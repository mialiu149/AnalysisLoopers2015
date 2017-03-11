#! /bin/bash
export analysis="wh_loopers" 
#export analysis_version="crmtbulk-15-v00"
#export analysis_version="cr0b-15-v01"
#export analysis_version="sr-16-v00"
#export analysis_version="elwp_studies_v0"
#export analysis_version="btagwp_studies_v0"
# v7 is with 7,56 
# v8 is with 7,65, fixed trigger eff for di-lepton CR  
#export analysis_version="allregions-7p65v2_twogood"
#export analysis_version="allregions-7p65v3"
#export analysis_version="allregions-13fbv3"
#export analysis_version="allregions-18fbv0_2p1"
#export analysis_version="allregions-18fbv0_2p1"
# allregions-36fbv10_2p1 is the version used in frozen document for pre-approval.
# allregions-36fbv11_2p1 is the version used to check the effect of bad muon filter.
#export analysis_version="allregions-36fbv21_2p1"
export analysis_version="allregions-36fbv22_2p1"  # version for reminiaod
#export analysis_version="allregions-16-v02"

export study="datavsmc"
localdirectory=`pwd`
export analysis_output=$HOME/public_html/analysis/$analysis/$analysis_version/$study/rootfiles
export plot_output=$HOME/public_html/analysis/$analysis/$analysis_version/$study/plots
function create_analysis_output
{
	if [ ! -d $HOME/public_html/analysis/$analysis/$analysis_version/$study ]; then
		echo "Creating directory: $HOME/public_html/analysis/$analysis/$analysis_version/$study/rootfiles/"
		mkdir -p $HOME/public_html/analysis/$analysis/$analysis_version/$study/rootfiles
		sleep 1
	else
		echo "Saving output to: $HOME/public_html/analysis/$analysis/$analysis_version/$study/rootfiles"
		sleep 1
	fi
}

function create_plot_output
{
	if [ ! -d $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots/ ]; then
		echo "Will save plots to a new directory:$HOME/public_html/analysis/$analysis/$analysis_version/$study/plots"
		mkdir -p $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots
		sleep 1
	else
		echo "Will save plots to : $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots/"
		sleep 1
	fi

	if [ ! -e $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots/index.php ]; then
		cp $HOME/index.php $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots
	fi
}

function create_table_output
{
	if [ ! -d $HOME/public_html/analysis/$analysis/$analysis_version/$study/tables/ ]; then
		echo "Will save tables to a new directory:$HOME/public_html/analysis/$analysis/$analysis_version/$study/tables"
		mkdir -p $HOME/public_html/analysis/$analysis/$analysis_version/$study/tables
		sleep 1
	else
		echo "Will save tables to : $HOME/public_html/analysis/$analysis/$analysis_version/$study/tables/"
		sleep 1
	fi

}
function compile_looper
{
	echo "Compiling code."
	make -j20
	if [ ! "$?" -eq "0" ]; then
		echo "Code did not compile, exiting."
		exit
	fi
}

function make_gtemplates
{
	selection_region=$1
	iteration=$analysis_version
	sample=$2
	echo "running templateLooper."
	root -b -q "runPhotonTemplates.cc( \"$selection_region\", \"$iteration\", \"$sample\")"
}

function run_template_looper
{
	selection_region=$1
    iteration=$analysis_version
    sample_region=$2
	echo "running templateLooper."
	root -b -q "runTemplateLooper.cc( \"$selection_region\", \"$iteration\", \"$sample_region\")"
}
