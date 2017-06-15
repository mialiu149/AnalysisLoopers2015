#! /bin/bash

source settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

selection="presel_ss_ee_isotrackveto_loosebtag"
./runallcrplots_cmd.sh $selection 
#selection="presel_trilep_SFOS1"
selection="presel_ss_mm_isotrackveto_loosebtag"
./runallcrplots_cmd.sh $selection 
selection="presel_ss_em_isotrackveto_loosebtag"
./runallcrplots_cmd.sh $selection 
