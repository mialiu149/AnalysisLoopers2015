#! /bin/bash
export analysis="wh_loopers" 
#export analysis_version="crmtbulk-15-v00"
#export analysis_version="cr0b-15-v01"
#export analysis_version="sr-16-v00"
#export analysis_version="elwp_studies_v0"
#export analysis_version="btagwp_studies_v0"
export analysis_version="allregions-16-v03"
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
		echo "Willl save plots to : $HOME/public_html/analysis/$analysis/$analysis_version/$study/plots/"
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
		echo "Willl save tables to : $HOME/public_html/analysis/$analysis/$analysis_version/$study/tables/"
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


