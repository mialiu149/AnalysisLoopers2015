#! /bin/bash

source settings.sh

# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_inclusive\", 0.057 )"

#lumi=0.0358 # vince json
#lumi=0.0284 # fgolf json
#lumi=0.0419 # mark json
#lumi=0.0403 # golden jason: ../../dilepbabymaker/json_270715_golden.txt 
lumi=1.62*1.5
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ptl1\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"met\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"mt\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ht\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"njets\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nVert\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ptl1\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"met\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"mt\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ht\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"njets\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"nVert\",       \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ptl1\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"met\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"mt\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"ht\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"njets\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"el\", \"nVert\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ptl1\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"met\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"mt\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"ht\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"njets\",       \"njet2_incl\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mu\", \"nVert\",       \"njet2_incl\" )" 


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
