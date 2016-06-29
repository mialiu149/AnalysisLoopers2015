#! /bin/bash

source settings.sh

compile_looper

selection="SR_met100_mt150_mbb_mct150_twobtag"
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

#selection="SR_met100_mt150_mbb_mct150_twobtag"
selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag"
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="1lCR_mbb_bveto_met100_mct150"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &
#
selection="2lCR_met100_mt50"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="2lCR_mbb_met100_mt50"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="mbbCR_met100_mt50"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="yield_2lCR"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="yield_1lCR"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &

selection="yield_mbbCR"
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
#./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version ws_njets &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &
