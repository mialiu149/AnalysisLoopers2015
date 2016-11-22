#! /bin/bash

source settings.sh

compile_looper

selection="1lCR_mbb_bveto_met125_mct150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
#./runTemplateLooper $selection $analysis_version ws_htbin_tostitch &
#./runTemplateLooper $selection $analysis_version ws_ht100_tostitch &
#./runTemplateLooper $selection $analysis_version ws_njets_tostitch &
#./runTemplateLooper $selection $analysis_version ws_njets &
#./runTemplateLooper $selection $analysis_version tops &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
#./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
#./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
#
selection="2lCR_met125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="2lCR_mbb_met125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="mbbCR_met125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_2lCR_mct150_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_1lCR_mct150_mt150_bveto_V4_elonly"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_1lCR_mct150_mt150_bveto_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_1lCR_mct150_mt150_bveto_V4_muonly"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_mbbCR_mct150_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="2lCR_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="mbbCR_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
