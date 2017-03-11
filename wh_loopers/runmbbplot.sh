#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=36.8
sigscaleup=1
setlog=false
usedata=false
usesig=true

usedata=true
usesig=false
selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig,true)" 
selection="SR_mix_met125_mt150_mct170_twobtag_metbin1v4"  # to draw money plot mbb.
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig,true)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig,true)" 
selection="SR_mix_met125_mt150_mct170_twobtag_metbin2v4"  # to draw money plot mbb.
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig,true)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig,true)" 
selection="SR_mix_met125_mt50_twobtag" # pre selection without mbb cut
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\",$sigscaleup,30,10,490,$setlog,$usedata,$usesig)" 
