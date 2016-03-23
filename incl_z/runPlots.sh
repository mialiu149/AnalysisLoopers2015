#! /bin/bash

source settings.sh
# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

lumi=2.3
selection="baseline"
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mll\",\"$selection\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el\", \"mll\",\"$selection\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_absiso_dphi"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_met150_lep200"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_met150_mt120"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_br\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_absiso_dphi_mt120_met150"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_br\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_absiso_dphi_met150"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_br\", \"absIso03EA\",\"$selection\" )" 
#selection="1lCRallbin_absiso_met150"
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"mt\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_ec\", \"absIso03EA\",\"$selection\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"$selection\", \"el_br\", \"absIso03EA\",\"$selection\" )" 
##
#selection="yield"
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEventsSR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEvents1lCR\",             \"$selection\")" 
#root -b -q "drawYields.cc+( \"$analysis_version\",  $lumi, \"_yield\", \"lep\", \"NEvents2lCR\",             \"$selection\")" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"deltaphi_lep_met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"deltaphi_lep_met\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"deltaphi_lep_met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"deltaphi_lep_met\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"deltaphi_lep_met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ptl1\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"mt\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"njets\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nVert\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"relIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"absIso03EA\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"absIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"absIso03EA\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"absIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"absIso03EA\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"absIso03EA\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nhiso\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"emiso\",       \"njet2_met100\" )" 
##root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"chiso\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"ptl1\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"met\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"njets\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"mt\",       \"njet2_met50\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"mt\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"ht\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"njets\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"nVert\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"relIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"absIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"nhiso\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"emiso\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_ec\", \"chiso\",       \"njet2_met100\" )" 
#
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"ptl1\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"mt\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"ht\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"njets\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"nVert\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"relIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"absIso03EA\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"nhiso\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"emiso\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el_br\", \"chiso\",       \"njet2_met100\" )" 
#

#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ptl1\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"met\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"mt\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ht\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"njets\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ptl1\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"met\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"mt\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ht\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"njets\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"nVert\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"nVert\",       \"njet2_met100\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ptl1\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"met\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"mt\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ht\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"njets\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nVert\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"relIso03EA\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"absIso03EA\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nhiso\",       \"njet2_met30\" )" 
#root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"emiso\",       \"njet2_met30\" )" 
##########root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"chiso\",       \"njet2_met30\" )" 


# root -b -q "drawRatio.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "FS_closure.cc+( \"$analysis_version\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_edgef\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_edgec\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_edgef\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_edgec\", 4.0 )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_edgec\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_edgef\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_3jets_edgec\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_3jets_edgef\" )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_twojets\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_inclusive\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_inclusive\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_bveto\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_withb\", 10.0 )"


# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_2jets\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_twojets\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_3jets_inclusive\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_withb\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_withb\" )"
