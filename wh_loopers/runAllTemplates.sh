#! /bin/bash

source settings.sh

compile_looper

selection="presel_met100_mt100"

./runTemplateLooper $selection $analysis_version diboson&
#./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version wh_300_80&
#./runTemplateLooper $selection $analysis_version wh_250_1&
#./runTemplateLooper $selection $analysis_version wh_225_80&
##
#./runTemplateLooper $selection $analysis_version Wbb&
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version top &
#./runTemplateLooper $selection $analysis_version ttv &
##./runTemplateLooper $selection $analysis_version QCD &
#
#
#
