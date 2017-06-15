#! /bin/bash

source settings.sh

compile_looper

selection="1lCR_mbb_bveto_met125_mct170"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version ws_ht100_tostitch &
#./runTemplateLooper $selection $analysis_version ws_htbin_tostitch &
#./runTemplateLooper $selection $analysis_version ws_htbin_tostitch_200 &
#./runTemplateLooper $selection $analysis_version ws_ht100_tostitch_200 &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
#selection="2lCR_mix_twobtag_met125_mt50"
#selection="2lCR_mix_twobtag_mbb_met125_mt50"
#selection="mbbCR_mix_met125_mt50"
selection="yield_2lCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ws_ht100 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="yield_1lCR_mct170_mt150_bveto_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="2lCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="mbbCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
