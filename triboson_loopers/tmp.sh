#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=35.9
setlog=false
sigscaleup=1
usedata=true
usesig=false

selection=presel_ss
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"flavorbin\",\"$selection\" ,$sigscaleup,1,0,3,$setlog,$usedata,$usesig)" 
