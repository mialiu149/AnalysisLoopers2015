#!/bin/bash

usage()
{
    echo "Usage: sh [-g] [-c] run.sh lepbaby output.root"
    exit
}


# Command-line opts
while getopts ":gch" OPTION; do
  case $OPTION in
    g) DEBUG=true;;
    c) FORCERECOMPILE="+";;
    h) usage;;
    :) usage;;
  esac
done

# to shift away the parsed options
shift $(($OPTIND - 1))

if [ -z $1 ]; then usage; fi
if [ -z $2 ]; then usage; fi

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

export FAKERATEDIR=$DIR

if $(type root &> /dev/null); then
    :
else
    echo "Setting up ROOT"
    export SCRAM_ARCH=slc6_amd64_gcc530   # or whatever scram_arch you need for your desired CMSSW release
    export CMSSW_VERSION=CMSSW_9_2_4
    source /cvmfs/cms.cern.ch/cmsset_default.sh
    cd /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/cmssw/$CMSSW_VERSION/src
    eval `scramv1 runtime -sh`
    cd -
fi

echo 'which root'
which root

INPUTFILES=$1
OUTPUTFILE=$2

if [ "x${_CONDOR_SLOT}" == "x" ]; then
    :
else
    tar xvzf condor_package.tgz
#    if [[ "${HOSTNAME}" == *uaf* ]]; then
#        :
#    else
#        ALLFILES=$(echo $1 | tr ',' ' ')
#        ALLBASENAMEFILES=""
#        for FILE in ${ALLFILES}; do
#            gfal-copy -p -f -t 4200 gsiftp://gftp.t2.ucsd.edu/$FILE ./ --checksum ADLER32
#            if [ $? -eq 0 ]; then
#                :
#            else
#                echo "failed the first time, trying again."
#                sleep 10
#                gfal-copy -p -f -t 4200 gsiftp://gftp.t2.ucsd.edu/$FILE ./ --checksum ADLER32
#                if [ $? -eq 0 ]; then
#                    :
#                else
#                    echo "failed the second time, trying again. Third time's a charm?"
#                    sleep 30
#                    gfal-copy -p -f -t 4200 gsiftp://gftp.t2.ucsd.edu/$FILE ./ --checksum ADLER32
#                    if [ $? -eq 0 ]; then
#                        :
#                    else
#                        echo "failed the third time, trying one last time. Fourth time better fucking work."
#                        sleep 60
#                        gfal-copy -p -f -t 4200 gsiftp://gftp.t2.ucsd.edu/$FILE ./ #--checksum ADLER32
#                        if [ $? -eq 0 ]; then
#                            :
#                        else
#                            echo "failed the fourth time, fuck this shit. exiting!"
#                            hostname
#                            uname -a
#                            date
#                            whoami
#                            pwd
#                            echo "Job Failed on getting input files"
#                            exit
#                        fi
#                    fi
#                fi
#            fi
#            ALLBASENAMEFILES="${ALLBASENAMEFILES} $(basename $FILE)"
#            echo 'LS-ing after one gfal-copy'
#            ls -l
#        done
#        INPUTFILES=$(echo ${ALLBASENAMEFILES} | tr ' ' ',')
#    fi
fi

if [[ "$DEBUG" == true ]]; then
    gdb --args root.exe -l -b -q $FAKERATEDIR'/code/run.C("'${INPUTFILES}'","'${OUTPUTFILE}'")'
#    igprof -pp -d -z -o igprof.pp.gz root.exe -l -b -q $FAKERATEDIR'/code/run.C("'$1'","'$2'")'
#    igprof-analyse --sqlite -d -v -g igprof.pp.gz | sqlite3 igprof.pp.sql3 >& /dev/null
#    cp igprof.pp.sql3 ~/public_html/cgi-bin/data/
#    echo "http://${HOSTNAME}/~phchang/cgi-bin/igprof-navigator.py/igprof.pp/"
else
    root -l -b -q $FAKERATEDIR'/code/run.C("'${INPUTFILES}'","'${OUTPUTFILE}'")'
fi

if [ "x${_CONDOR_SLOT}" == "x" ]; then
    :
else
    echo 'ls -l'
    ls -l
    echo 'gfal-copy'
    INFILE=$2
    OUTDIR=condor/fakerate_forCommissioningv12
    OUTFILE=${OUTDIR}/${INFILE}
    HADOOPDIR=/hadoop/cms/store/user/phchang/
    echo gfal-copy -p -f -t 4200 --verbose file://\`pwd\`/${INFILE} gsiftp://gftp.t2.ucsd.edu/${HADOOPDIR}/${OUTFILE} --checksum ADLER32
    hostname
    uname -a
    date
    whoami
    pwd
    gfal-copy -p -f -t 4200 --verbose file://`pwd`/${INFILE} gsiftp://gftp.t2.ucsd.edu/${HADOOPDIR}/${OUTFILE} --checksum ADLER32
    if [ $? -eq 0 ]; then
        echo "Job Success"
    else
        echo "Job Failed"
    fi
fi

#eof
