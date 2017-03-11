#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=36.5
setlog=true
sigscaleup=1
usedata=true
usesig=false

selection="1lCR_mbb_bveto_met125_mct170"
root -b -q "drawBkgvsSig_dev.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" ,$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
