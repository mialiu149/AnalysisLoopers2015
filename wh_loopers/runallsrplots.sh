#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=35.9
sigscaleup=50
setlog=false
usedata=false
usesig=true


selection="SR_mix_met125_mt50_mbb_twobtag" # pre selection + mbb cut
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" ,$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb2\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 

sigscaleup=1
selection="SR_mix_met125_mt150_mbb_mct170_twobtag" # SR
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" ,$sigscaleup,50,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\" ,$sigscaleup,50,20,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\" ,$sigscaleup,50,25,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\" ,$sigscaleup,25,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1\",\"$selection\" ,$sigscaleup,30,0,480,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb2\",\"$selection\" ,$sigscaleup,30,0,480,$setlog,$usedata,$usesig)" 

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
