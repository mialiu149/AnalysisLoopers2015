#! /bin/bash

source settings.sh

compile_looper

selection="SMS_SR_met125_mt150_mbb_mct150_twobtag" # this is the SR
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb_jecup  &
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb_jecdn  &

selection="SR_met125_mt150_mbb_mct150_twobtag" # this is the SR
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht125 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="SR_met125_mt150_mct150_twobtag"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht125 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

#selection="SR_SROneBin_yield_mbb_mct150_mt150_met125_twobtag" # get yields in SR
selection="SR_SRMultiBin_V0_yield_mbb_mct150_mt150_met125_twobtag" # get yields in SR
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht125 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

#selection="SR_mbb_met125_mt150_twobtag"  # draw plots presel+mbb window for other variables
#./runTemplateLooper $selection $analysis_version wh_300_80&
#./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version wh_250_1&
#./runTemplateLooper $selection $analysis_version wh_225_80&
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ws_ht125 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version rare &
#./runTemplateLooper $selection $analysis_version wzbb&
