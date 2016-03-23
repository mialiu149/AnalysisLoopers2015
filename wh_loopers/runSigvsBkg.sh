#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=10
#selection="presel"
selection="presel_met100_mt100"

root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"relIso03EA\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptbb\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"nbjets\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dphi_Wlep\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"dR_lep_leadb\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MT2_lb_b_mass\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MT2_lb_b\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MT2_lb_b_mass_lep2\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MT2_lb_b_lep2\",\"$selection\" )" 

#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"\",\"$selection\" )" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\" )" 
