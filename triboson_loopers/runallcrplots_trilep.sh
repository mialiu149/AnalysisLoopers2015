#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=35.9
setlog=false
sigscaleup=5
usedata=false
usesig=true

selection="presel_trilep_SFOS0"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nveto_leptons\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nisoTrack_mt2\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nleps\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mll\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
selection="presel_trilep_SFOS1"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nisoTrack_mt2\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nleps\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mll\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nveto_leptons\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
selection="presel_trilep_SFOS2"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nisoTrack_mt2\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nleps\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mll\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nveto_leptons\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
#selection="1lCR_mbb_bveto_met125_mct170"
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" ,$sigscaleup,25,0,500,$setlog,$usedata,$usesig)" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb2\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
