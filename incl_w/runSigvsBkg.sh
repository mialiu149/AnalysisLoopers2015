#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=2.26

#selection="mt150_met150_2jet_incl_met_trigger"
#selection="presel_absiso_bveto_mt50"
#selection="presel_absiso_mtbulk"
#selection="presel_absiso_mtbulk_btag"
#selection="presel_absiso"
#selection="presel"
#selection="presel_absiso_bveto_2jets_incl"
#selection="presel_absiso_bveto_2jets_incl_met100_mt50"
#selection="presel_absiso_btag_3jets_incl_met100_mt120"
#selection="presel_absiso_btag_3jets_incl_met100_mt120"

#selection="presel_absiso_bveto_2jets_incl_met150_mt50"
#selection="presel_absiso_bveto_2jet_incl_met150_mt150"
#selection="presel_absiso_bveto_2jet_incl_met150_mt50_mct100"
selection="presel_absiso_btag_2jet_excl_withbtagweight"
#selection="presel_absiso_bveto_2jet_excl_met150_mt50"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"metphi\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mct\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ht\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"absIso03EA\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"deltaphi_lep_met\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mindphi_met_j1_j2\",\"$selection\" )" 

