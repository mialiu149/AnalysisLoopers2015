#! /bin/bash

source settings.sh

compile_looper

#selection="1lCR_mbb_bveto_met100_mct150_absmini"

#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version wzbb&
#./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ws_njets &
#./runTemplateLooper $selection $analysis_version ws_ht100 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version rare &
#./runTemplateLooper $selection $analysis_version diboson &
#./runTemplateLooper $selection $analysis_version ttv &
#./runTemplateLooper $selection $analysis_version zjets &

#selection="SR" # this is the SR
#./runTemplateLooper $selection $analysis_version ww  &
##./runTemplateLooper $selection $analysis_version wh_300_80&
#./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version wh_250_1&
#./runTemplateLooper $selection $analysis_version wh_225_80&
selection="cutflow"
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_100_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_500_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_500_125_noskim&
