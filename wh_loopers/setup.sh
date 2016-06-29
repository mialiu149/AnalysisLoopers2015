#! /bin/bash
setup_CMSSW_74X 

#source $PWD/settings.sh
source /home/users/mliu/AnalysisLoopers_80x/wh_loopers/settings.sh 
#./../settings.sh incl_z datavsmc V00-00-01
#link_output
create_analysis_output
create_plot_output
create_table_output
export COREPATH=/home/users/mliu/CORE/
