if [ -z $1 ]; then
    echo "provide a tag"
    exit
fi

mv condor_logs condor_logs_archive/condor_logs_$1
mv condor*tgz condor_logs_archive/condor_logs_$1
