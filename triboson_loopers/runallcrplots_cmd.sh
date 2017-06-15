#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=35.9
setlog=false
sigscaleup=10
usedata=false
usesig=true

selection=$1
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptj1\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptj2\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptjj\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptll\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptlll\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mlll\",\"$selection\",$sigscaleup,10,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" ,$sigscaleup,1,0,10,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nveto_leptons\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nisoTrack_mt2\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nleps\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mll\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj_lead\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptlljj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"absIso03EA\",\"$selection\" ,$sigscaleup,1,0,20,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"absIso03EA_subleading\",\"$selection\" ,$sigscaleup,1,0,20,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mtMin\",\"$selection\" ,$sigscaleup,10,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"deta_jj\",\"$selection\" ,$sigscaleup,10,0,5,$setlog,$usedata,$usesig)" 
