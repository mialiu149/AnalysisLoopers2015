#! /bin/bash
export analysis="incl_w" 
export analysis_version="V07-04-05"
export study="datavsmc"
echo "Analysis version = $analysis_version"
localdirectory=`pwd`


function create_analysis_output
{
	if [ ! -d $HOME/public_html/rootfiles/$analysis/$analysis_version/$study ]; then
		echo "Creating directory: $HOME/public_html/$analysis/$analysis_version/$study/rootfiles/"
		mkdir -p $HOME/public_html/rootfiles/$analysis/$analysis_version/$study/rootfiles
		sleep 1
	else
		echo "Saving output to: $HOME/public_html/$analysis/$analysis_version/$study/rootfiles"
		sleep 1
	fi
}

function create_plot_output
{
	if [ ! -d $HOME/public_html/$analysis/$analysis_version/$study/plots/ ]; then
		echo "Will save plots to a new directory:$HOME/public_html/$analysis/$analysis_version/$study/plots"
		mkdir -p $HOME/public_html/$analysis/$analysis_version/$study/plots
		sleep 1
	else
		echo "Willl save plots to : $HOME/public_html/$analysis/$analysis_version/$study/plots/"
		sleep 1
	fi

	if [ ! -e $HOME/public_html/$analysis/$analysis_version/$study/plots/index.php ]; then
		cp index.php $HOME/public_html/$analysis/$analysis_version/$study/plots
	fi
}

function compile_looper
{
	echo "Compiling code."
	make -j5
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


