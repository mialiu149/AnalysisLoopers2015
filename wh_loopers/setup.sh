#! /bin/bash
setup_CMSSW_74X 

source settings.sh
#./../settings.sh incl_z datavsmc V00-00-01
#link_output
create_analysis_output
create_plot_output
export COREPATH=/home/users/mliu/CORE/
