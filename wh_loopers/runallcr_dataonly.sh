#! /bin/bash

source settings.sh

compile_looper

selection="1lCR_mbb_bveto_met125_mct170"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &
#
#selection="2lCR_mix_twobtag_met125_mt50"
#selection="2lCR_mix_twobtag_mbb_met125_mt50"
#selection="mbbCR_mix_met125_mt50"
selection="yield_2lCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &
#

selection="yield_1lCR_mct170_mt150_bveto_V4_elonly"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="yield_1lCR_mct170_mt150_bveto_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="yield_1lCR_mct170_mt150_bveto_V4_muonly"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="2lCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &

selection="mbbCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version ws_incl &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version w1jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w3jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w3jets_nupt100 &
./runTemplateLooper $selection $analysis_version w4jets_nupt200 &
./runTemplateLooper $selection $analysis_version w1jets_tostitch &
./runTemplateLooper $selection $analysis_version w2jets_tostitch &
./runTemplateLooper $selection $analysis_version w3jets_tostitch &
./runTemplateLooper $selection $analysis_version w4jets_tostitch &
