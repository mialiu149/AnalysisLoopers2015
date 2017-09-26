if [ -z $1 ]; then
    echo "hadd.sh : Missing argument to the path where fakerate_*.root resides."
    echo "exiting..."
    exit
fi

if $(type root &> /dev/null); then
    :
else
    echo "Setting up ROOT"
    export SCRAM_ARCH=slc6_amd64_gcc491   # or whatever scram_arch you need for your desired CMSSW release
    export CMSSW_VERSION=CMSSW_7_4_2
    source /cvmfs/cms.cern.ch/cmsset_default.sh
    cd /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/cmssw/$CMSSW_VERSION/src
    eval `scramv1 runtime -sh`
    cd -
fi

echo 'which root'
which root

hadd -f fakerate_data.root $1/fakerate_Double*.root
#hadd -f fakerate_data.root $1/fakerate_2016*.root
hadd -f fakerate_wj.root $1/fakerate_WJ*.root
hadd -f fakerate_dy.root $1/fakerate_DY*.root
hadd -f fakerate_qcd_el.root $1/fakerate_QCD_EM*.root $1/fakerate_QCD_bcToE*.root
hadd -f fakerate_qcd_mu.root $1/fakerate_QCD_Mu*.root
#hadd -f fakerate_qcd_mu_incl.root $1/fakerate_QCD_Mu_Enriched_incl*
hadd -f fakerate_ttbar.root $1/fakerate_TTbar_*.root
hadd -f fakerate_vv.root $1/fakerate_WW*.root $1/fakerate_WZ*.root $1/fakerate_ZZ*.root
#hadd -f fakerate_ttbarfake.root $1/fakerate_TTbarFake*.root
#if [[ "$1" == *v15* ]]; then
#    :
#else
#    hadd -f fakerate_data.root $1/fakerate_2016*.root
#    hadd -f fakerate_data_mu.root $1/fakerate_2016doublemuon*.root
#    hadd -f fakerate_data_el.root $1/fakerate_2016doublee*.root
#    #hadd -f fakerate_data_mu.root $1/fakerate_2016*Mu*.root
#    hadd -f fakerate_wj.root $1/fakerate_WJ*.root
#    hadd -f fakerate_dy.root $1/fakerate_DY*.root
#    hadd -f fakerate_qcd_el.root $1/fakerate_QCD_EM*.root
#    hadd -f fakerate_qcd_mu.root $1/fakerate_QCD_Mu*.root
#    hadd -f fakerate_ttbar.root $1/fakerate_TTbar*.root
#fi

mkdir -p outputs/
mv *.root outputs/
