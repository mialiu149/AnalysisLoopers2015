#! /bin/bash

source settings.sh

compile_looper

selection="SR_mix_met125_mt50_twobtag" # this is the SR
#selection="SR_mix_met125_mt50_mbb_twobtag" # this is the SR
#selection="SR_mix_met125_mt150_mbb_mct170_twobtag" # this is the SR
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_ht100_tostitch_200 &
./runTemplateLooper $selection $analysis_version ws_htbin_tostitch_200 &

selection="SR_mix_met125_mt150_mbb_mct170_twobtag" # this is the SR
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_ht100_tostitch_200 &
./runTemplateLooper $selection $analysis_version ws_htbin_tostitch_200 &

selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="SR_mix_met125_mt150_mct170_twobtag_metbin1v4"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="SR_mix_met125_mt150_mct170_twobtag_metbin2v4"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
#./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
#./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
#./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
#./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w1jets_tostitch &
#./runTemplateLooper $selection $analysis_version w2jets_tostitch &
#./runTemplateLooper $selection $analysis_version w3jets_tostitch &
#./runTemplateLooper $selection $analysis_version ws_ht100_tostitch_200 &
#./runTemplateLooper $selection $analysis_version ws_htbin_tostitch_200 &
#./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
./runTemplateLooper $selection $analysis_version SMS_wh_225_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_250_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_300_75_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_350_1_noskim&
./runTemplateLooper $selection $analysis_version SMS_wh_400_1_noskim&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
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
#./runTemplateLooper $selection $analysis_version ws_ht100 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version rare &
#./runTemplateLooper $selection $analysis_version wzbb&
