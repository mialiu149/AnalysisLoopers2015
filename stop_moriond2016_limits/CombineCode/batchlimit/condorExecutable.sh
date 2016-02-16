#!/bin/bash

# Track time job begins
RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  Beginning Condor Job "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""

# This stuff to drive the the limit macro
#only input I need to define is
postfit=$1

#This stuff to get output back
export COPYDIR=$2
export CONDOR_DIR_NAME=$3
export DATACARDS_TAR=$4
export MAKER_NAME=$5


# Setup Environment
RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  Setting up environment... "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""

# Show where you are
hostname

# Show g++ version
echo " " 
echo "G++ INFORMATION" 
g++ --version
which g++

CMSSW_VERSION=CMSSW_7_1_5



# Untar the zip dir
RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  Unpack the tarball... "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""

echo "This this the current dir: "
THISDIR=`pwd`
echo $THISDIR
echo "LS to check that all files were transferred: "
ls
tar xzf $CONDOR_DIR_NAME.tar.gz
echo "LS to check that tarball was unpacked: "
ls

OLDDIR=`pwd`
#This should be CMSSW_7_1_5/src/HiggsAnalysis/CombinedLimit/
cd $MAKER_NAME/

export CMS_PATH=/cvmfs/cms.cern.ch
echo "CMSENV"
export SCRAM_ARCH=slc6_amd64_gcc481
source /cvmfs/cms.cern.ch/cmsset_default.sh
#cd 
eval `scramv1 runtime -sh`
cd $OLDDIR
echo "copy datacards into HiggsCombine directory"
cp $DATACARDS_TAR $MAKER_NAME/.
cd $MAKER_NAME/
echo "rescram to update links"
scramv1 b ProjectRename
source /cvmfs/cms.cern.ch/cmsset_default.sh
eval `scramv1 runtime -sh`
echo "untar datacards"
tar xzfv $DATACARDS_TAR
echo "LS to check contents of unpacked combine: "
ls
echo "remove the tar files "
rm $CONDOR_DIR_NAME.tar.gz
rm $DATACARDS_TAR

RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  Running combine limits... "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""

methodcmd="--noFitAsimov"
methodname="PreFit"
if [ "${postfit}" = true ]
then
    methodcmd=" "
    methodname="PostFit"
fi

#get all datacards
NameArray=( )
for f in *; do
    if [ ${f: -7} == ".tar.gz" ]
    then
	continue
    fi
    #echo $f
    mytest=`echo $f | grep -q datacard ; echo $?`
    #echo "mytest $mytest"
    if [ $mytest == "0" ]
    then
        echo "passed $f"
        NameArray=("${NameArray[@]}" "${f}")
    fi
done

#run over all datacards
for Name in "${NameArray[@]}"
do
    filenamenoext="${Name%.*}"
    stripone=`echo "datacard_"`
    #echo $stripone
    Signal=`echo ${filenamenoext#${stripone}}`
    echo "get limit for $Signal"
    #computes automatically observed and expected limit together
    combine  -M Asymptotic ${Name} ${methodcmd} -n ${methodname}${Signal}
    #> /dev/null 2>&1
    ls
    mv higgsCombine${methodname}${Signal}.Asymptotic.mH120.root Limits_Asymptotic_${methodname}_${Signal}.root
    ls
done


# Copy the output to the output directory via lcg-cp
RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  Copy output file with lcg-cp... "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""

#  This preserves grid functionality
echo "copying.  LS is: "
#ls -l *.root
ls
rootfilearray=( )
for f in *; do
    #echo $f
    mytest=`echo $f | grep -q root ; echo $?`
    #echo "mytest $mytest"
    if [ $mytest == "0" ]
    then
        echo "passed $f"
        rootfilearray=("${rootfilearray[@]}" "${f}")
    fi
done
#echo "${rootfilearray[@]}"

for Name in "${rootfilearray[@]}"
do
    echo "Transfer ${Name}"
    lcg-cp -b -D srmv2 --vo cms --connect-timeout 2400 --verbose file://`pwd`/${Name} srm://bsrm-3.t2.ucsd.edu:8443/srm/v2/server?SFN=${COPYDIR}/${Name}
done
#lcg-cp -b -D srmv2 --vo cms --connect-timeout 2400 --verbose file://`pwd`/${NAME}_${NUMBER}.root srm://bsrm-3.t2.ucsd.edu:8443/srm/v2/server?SFN=${COPYDIR}/${NAME}_${NUMBER}.root

# Job Complete
RIGHT_NOW=`date +"%Y%m%d %H%M%S"`
echo ""
echo "*************************************"
echo "  JOB COMPLETE! "
echo "    TIME = $RIGHT_NOW "
echo "*************************************"
echo ""
