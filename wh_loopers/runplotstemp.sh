#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=40
#selection="1lCR_mbb_bveto_met100_mct150"
#selection="SR_met150_mt150_mct150_twobtag"
#selection="SR_met150_mt150_mbb_mct150_twobtag"
#selection="SR_met100_mt150_mbb_mct150_twobtag"
#selection="SR_met150_mt150_mbb_mct150_twobtag_incl3jets" # this is the SR
#selection="SR_met150_mt150_mbb_mct150_twobtag" # this is the SR
#selection="SR_met150_mt150_mbb_mct150_twobtag" # this is the SR
selection="SR_mt150_mbb_mct150_lowMET_twobtag_mix" # this is the SR
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix_ptl100" # this is the SR
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix" # this is the SR
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix_mad"
#selection="SR_met100_mt150_mbb_mct150_twobtag_incl3jets" # this is the SR
#selection="SR_met100_twobtag"
#selection="SR_mbb_met100_twobtag"
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"MCT\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"met\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ht\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptl1\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb2\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"pt_ISR\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptbb\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"ptb1overptb2\",\"$selection\" )" 
root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"njets\",       \"$selection\" )" 
#selection="SR_met100_twobtag"
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mbb\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"mt\",\"$selection\" )" 
#root -b -q "drawBkgvsSig.cc+( \"$analysis_version\", $lumi, \"$selection\", \"lep\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"njets\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"relIso03EA\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"absIso03EA\",       \"$selection\" )" 
#
#
#selection="2lCR5"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"njets\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"njets\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"MT2W\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"relIso03EA\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"absIso03EA\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"MT2W\",       \"$selection\" )" 
#
#
#selection="2lCR6"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"njets\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"njets\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"mu\", \"MT2W\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ptl1\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"met\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"mt\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"ht\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"nVert\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"relIso03EA\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"absIso03EA\",       \"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"MT2W\",       \"$selection\" )" 
#
##oot -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"met\",\"$selection\" )" 
##selection="1lCRallbin_met150"
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
##selection="1lCRallbin"
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_lep200"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_absiso"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 

