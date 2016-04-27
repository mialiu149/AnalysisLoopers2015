#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=10
selection="presel_yield"
root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"$selection\", \"lep\", \"NEventsSR\",\"$selection\")" 

