#! /bin/bash

source settings.sh

compile_looper

selection="mbbCR_met100_mt50"	
#./runTemplateLooper $selection $analysis_version wh_300_80&
#./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version wh_250_1&
#./runTemplateLooper $selection $analysis_version wh_225_80&
#./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops_mad &
#./runTemplateLooper $selection $analysis_version tops &
##./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version ttbar2l &
##./runTemplateLooper $selection $analysis_version singletop &
#./runTemplateLooper $selection $analysis_version wsLF &
#./runTemplateLooper $selection $analysis_version ws_ht100 &
#./runTemplateLooper $selection $analysis_version ws_htbin &
#./runTemplateLooper $selection $analysis_version wsHF &
#./runTemplateLooper $selection $analysis_version rare &
#./runTemplateLooper $selection $analysis_version diboson &
#./runTemplateLooper $selection $analysis_version ttv &
#./runTemplateLooper $selection $analysis_version zjets &
#
selection="yield_mbbCR_met100_mct150_mt50_notrigger"
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version tops_mad &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version ttbar2l &
./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version wsLF &
./runTemplateLooper $selection $analysis_version ws_ht100 &
./runTemplateLooper $selection $analysis_version ws_htbin &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &
./runTemplateLooper $selection $analysis_version diboson &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version zjets &
#
