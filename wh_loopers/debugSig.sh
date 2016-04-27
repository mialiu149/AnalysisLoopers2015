#! /bin/bash

source settings.sh

compile_looper


selection="SR_presel"
#selection="gensel"
#./runTemplateLooper $selection $analysis_version wh_150_30&
./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version top &
