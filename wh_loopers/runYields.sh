#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=1

selection="met_trigger_SR_yield"
root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEventsSR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents1lCR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents2lCR\",             \"$selection\")" 
#
#selection="yield_CR6"
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEventsSR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents1lCR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents2lCR\",             \"$selection\")" 
#selection="yield_CR5_CR6"
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEventsSR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents1lCR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEvents2lCR\",             \"$selection\")" 
