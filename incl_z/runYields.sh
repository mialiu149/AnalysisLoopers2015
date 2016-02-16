#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=1
selection="yield"
root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEventsSR\",             \"$selection\")" 
root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEvents1lCR\",             \"$selection\")" 
root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEvents2lCR\",             \"$selection\")" 
