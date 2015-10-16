#! /bin/bash

source ../settings.sh

compile_looper
# create_analysis_output

if [ ! -d "../output/$analysis_version/" ]; then
	mkdir -p ../output/$analysis_version/
fi

selection="_inclusive"
# ./runTemplateLooper $selection V07-04-03_updatedHLT data  &

./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection V07-04-03_extraMETVariables zjets &
#./runTemplateLooper $selection V07-04-03_extraMETVariables ttbar &
# ./runTemplateLooper $selection V07-04-03_goodtrigs All_MC  &

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# sample="All_MC"
# run_template_looper $selection $sample &


# # # For the edge Z+JETS BG prediction
# selection="_2jets_inclusive"
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"  &
# run_template_looper $selection "ttv" &

# selection="_twojets"
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"  &
# run_template_looper $selection "ttv" &

# selection="_3jets_inclusive"
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"  &
# run_template_looper $selection "ttv" &


# # # For the edge Z+JETS BG prediction
# selection="_2jets_edgec"
# run_template_looper $selection "zjets"  &
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &

# selection="_2jets_edgef"
# run_template_looper $selection "zjets"  &
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &

# selection="_3jets_edgef"
# run_template_looper $selection "zjets"  &
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	  &
# run_template_looper $selection "ttv"    &

# # # done
# selection="_3jets_edgec"
# run_template_looper $selection "zjets"  &
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"     &
# run_template_looper $selection "ttv"    &


# # # For the edge Z+JETS BG prediction
# selection="_2jets_edgec"
# run_template_looper $selection "zjinc" &

# selection="_2jets_edgef"
# run_template_looper $selection "zjinc" &

# selection="_3jets_edgec"
# run_template_looper $selection "zjinc" &

# selection="_3jets_edgef"
# run_template_looper $selection "zjinc" &

# selection="_2jets_inclusive"
# run_template_looper $selection "data"   
# # run_template_looper $selection "All_MC" &

# selection="_2jets_inclusive"
# # run_template_looper $selection "zjets"  &
# # run_template_looper $selection "All_MC" &
# # run_template_looper $selection "vv"     &
# # run_template_looper $selection "ttv"    &

# selection="_twojets"
# run_template_looper $selection "zjets" &
# selection="_3jets_inclusive"
# run_template_looper $selection "zjets" &



# # SR + CRS
# selection="_inclusive"
# run_template_looper $selection "zjets"
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &
# run_template_looper $selection "FS_BG"  &

# # run_template_looper $selection "zjets"
# # # run_template_looper $selection "ttbar"
# # # # run_template_looper $selection "top"

# selection="_SRA_withb"
# run_template_looper $selection "zjets"  &

# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &
# run_template_looper $selection "FS_BG"  &
									    
# selection="_SRA_withb"				    
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &
# run_template_looper $selection "FS_BG"  &
									    
# selection="_SRB_bveto"				    
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &
# run_template_looper $selection "FS_BG"  &
									    
# selection="_SRB_withb"				    
# run_template_looper $selection "All_MC" &
# run_template_looper $selection "vv"	    &
# run_template_looper $selection "ttv"    &
# run_template_looper $selection "FS_BG"  &
