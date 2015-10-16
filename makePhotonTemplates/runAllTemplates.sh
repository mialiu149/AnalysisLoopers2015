#! /bin/bash

source ../settings.sh

if [ ! -d "../output/photon/$analysis_version/" ]; then
	mkdir -p ../output/photon/$analysis_version/
fi

compile_looper
# create_photon_output

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# # SR + CRS
# selection="_inclusive"
# make_gtemplates $selection "All_MC" 

# selection="_SRA_bveto"			    
# make_gtemplates $selection "All_MC" &
# selection="_SRA_withb"			    
# make_gtemplates $selection "All_MC" &

# selection="_SRB_bveto"			    
# make_gtemplates $selection "All_MC" &
# selection="_SRB_withb"			    
# make_gtemplates $selection "All_MC" &

selection="_2jets_inclusive"
make_gtemplates $selection "All_MC" &

# selection="_twojets"
# make_gtemplates $selection "All_MC" &

# selection="_3jets_inclusive"
# make_gtemplates $selection "All_MC" &

# # done
# selection="_2jets_edgec"
# make_gtemplates $selection "All_MC" &

# selection="_2jets_edgef"
# make_gtemplates $selection "All_MC" &

# selection="_3jets_edgef"
# make_gtemplates $selection "All_MC" &

# selection="_3jets_edgec"
# make_gtemplates $selection "All_MC" &

# # done
# selection="_2jets_edgec_bad"
# make_gtemplates $selection "All_MC" &

# selection="_2jets_edgef_bad"
# make_gtemplates $selection "All_MC" &

# selection="_3jets_edgef_bad"
# make_gtemplates $selection "All_MC" &

# selection="_3jets_edgec_bad"
# make_gtemplates $selection "All_MC" &


