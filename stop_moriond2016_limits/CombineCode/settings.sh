export analysis="stop_limits" 
export analysis_version="V00-00-02"
localdirectory=`pwd`
export input_yields="../SignalAnalysisCode/rootfiles/signalyields/"
export datacards=$HOME/public_html/analysis2015/$analysis/$analysis_version/datacards
export limits=$HOME/public_html/analysis2015/$analysis/$analysis_version/rootfiles

function create_analysis_datacards
{
	if [ ! -d $HOME/public_html/analysis2015/$analysis/$analysis_version ]; then
		echo "Creating directory: $HOME/public_html/analysis2015/$analysis/$analysis_version/datacards/"
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/compressed
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/nounc
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/nosigunc
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/nobkgunc
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/dropsigcont
		sleep 1
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/datacards/fakedata
		sleep 1
	else
		echo "Saving limit hists output to: $HOME/public_html/analysis2015/$analysis/$analysis_version/datacards"
		sleep 1
	fi
}

function create_analysis_rootfiles
{
	if [ ! -d $HOME/public_html/analysis2015/$analysis/$analysis_version ]; then
		echo "Creating directory: $HOME/public_html/analysis2015/$analysis/$analysis_version/rootfiles/"
		mkdir -p $HOME/public_html/analysis2015/$analysis/$analysis_version/$study/rootfiles
		sleep 1
	else
		echo "Saving limit hists output to: $HOME/public_html/analysis2015/$analysis/$analysis_version/rootfiles"
		sleep 1
	fi
}
