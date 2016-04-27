#! /bin/bash

source settings.sh

compile_looper

#selection="yield_newbin_2lCR"
#selection="gensel"

selection="2lCR"
./runTemplateLooper $selection $analysis_version wh_150_30&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
###
./runTemplateLooper $selection $analysis_version wbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version ttbar2l &
./runTemplateLooper $selection $analysis_version ttbar1l &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version diboson&

selection="2lCR_mbb"
./runTemplateLooper $selection $analysis_version wh_150_30&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
###
./runTemplateLooper $selection $analysis_version wbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version ttbar2l &
./runTemplateLooper $selection $analysis_version ttbar1l &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version diboson&

