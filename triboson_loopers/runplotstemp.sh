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

selection="1lCR_mbb_bveto_met125_mct170_elonly_eeonly"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" ,$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb2\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
