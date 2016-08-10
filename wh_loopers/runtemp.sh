#! /bin/bash

source settings.sh

compile_looper

#selection="1lCR_mbb_bveto_met100_mct150_muonly_mt450"
#./runTemplateLooper $selection $analysis_version data  &
#selection="SMS_SR_met175_mt150_mbb_mct150_twobtag" # this is the SR
#./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
#selection="SMS_SR_met100_mt150_mbb_mct160_twobtag" # this is the SR
#./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
#selection="SMS_SR_met100_mt120_mbb_mct150_twobtag" # this is the SR
#./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
#selection="SMS_SR_met100_mt100_mbb_mct150_twobtag" # this is the SR
#./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
#selection="SR_SROneBin_yield_mbb_mct150_mt150_met175_twobtag" # get yields in SR
#selection="SR_SROneBin_yield_mbb_mct160_mt150_met100_twobtag" # get yields in SR
#selection="SR_SROneBin_yield_mbb_mct160_mt120_met100_twobtag" # get yields in SR

#selection="1lCR_mbb_bveto_met100_mct150_mt250"
#selection="SR_met100_mt150_mbb_mct150_twobtag" # this is the SR
selection="cutflow_genmet"
#./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
#./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
#./runTemplateLooper $selection $analysis_version wh_225_80&
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ws_ht100 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version rare &
#./runTemplateLooper $selection $analysis_version wzbb&
#./runTemplateLooper $selection $analysis_version wzbb_jecup&
#./runTemplateLooper $selection $analysis_version wzbb_jecdn&

