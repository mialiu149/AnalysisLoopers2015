#! /bin/bash

source settings.sh

compile_looper

selection="1lCR_mbb_bveto_125_mct150"
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
selection="2lCR_125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
selection="2lCR_mbb_125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="mbbCR_125_mt50"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_2lCR"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_1lCR"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="yield_mbbCR"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="2lCR_125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&

selection="mbbCR_125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
