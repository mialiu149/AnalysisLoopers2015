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

selection=$1
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nBadMuons20\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRl1j1\",\"$selection\" ,$sigscaleup,200,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRl1j2\",\"$selection\" ,$sigscaleup,200,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRl2j2\",\"$selection\" ,$sigscaleup,200,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRl2j1\",\"$selection\" ,$sigscaleup,200,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\",$sigscaleup,10,10,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl2\",\"$selection\",$sigscaleup,10,10,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptj1\",\"$selection\",$sigscaleup,10,10,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptj2\",\"$selection\",$sigscaleup,10,10,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptjj\",\"$selection\",$sigscaleup,10,10,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\",$sigscaleup,20,0,140,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptll\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptlll\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mlll\",\"$selection\",$sigscaleup,20,10,490,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" ,$sigscaleup,1,0,10,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"flavorbin\",\"$selection\" ,$sigscaleup,1,1,4,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nveto_leptons\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nisoTrack_mt2\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nleps\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" ,$sigscaleup,1,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mll\",\"$selection\" ,$sigscaleup,20,0,180,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj\",\"$selection\" ,$sigscaleup,20,0,240,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mjj_lead\",\"$selection\" ,$sigscaleup,20,0,240,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptlljj\",\"$selection\" ,$sigscaleup,20,0,500,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"relIso03EA\",\"$selection\" ,$sigscaleup,2,0,1,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ip3derr\",\"$selection\" ,$sigscaleup,2,0,1,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ip3d\",\"$selection\" ,$sigscaleup,2,0,1,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"absIso03EA_subleading\",\"$selection\" ,$sigscaleup,1,0,20,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mtMax\",\"$selection\" ,$sigscaleup,10,0,250,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"deta_jj\",\"$selection\" ,$sigscaleup,200,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRjj\",\"$selection\" ,$sigscaleup,100,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dRll\",\"$selection\" ,$sigscaleup,100,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dphijj\",\"$selection\" ,$sigscaleup,100,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mindphi_met_j1_j2\",\"$selection\" ,$sigscaleup,100,0,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"etal1\",\"$selection\" ,$sigscaleup,100,-5,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"etal2\",\"$selection\" ,$sigscaleup,100,-5,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"etaj1\",\"$selection\" ,$sigscaleup,100,-5,5,$setlog,$usedata,$usesig)" 
root -b -q "drawBkgvsSigSplitbyGen.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"etaj2\",\"$selection\" ,$sigscaleup,100,-5,5,$setlog,$usedata,$usesig)" 
