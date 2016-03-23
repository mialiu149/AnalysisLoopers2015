#! /bin/bash

source settings.sh

compile_looper

selection="sync"

./runTemplateLooper $selection $analysis_version sync  &
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version top &
#./runTemplateLooper $selection $analysis_version ttv &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
###
###
