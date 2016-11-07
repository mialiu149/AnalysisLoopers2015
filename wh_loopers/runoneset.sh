#! /bin/bash

source settings.sh

compile_looper

selection="SR_SRMultiBin_V4_yield_mbb_mct150_mt150_met125_twobtag" # get yields in SR
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb  &
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb_jecup  &
./runTemplateLooper $selection $analysis_version SMS_tchwh_lnbb_jecdn  &
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
