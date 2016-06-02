#! /bin/bash

source settings.sh

compile_looper

#selection="SRMultiBinV2_yield_lumi20_mbb_mct150_mt150"      -->limit calculation for 20fb
#selection="yield_2lCR_mbb"                                  #-->2l CR yields with relaxed cuts 
#selection="SRMultiBinV1_yield_lumi20_mbb_mct150_mt150"
#selection="1lCR"
#selection="1lCR_mbb"
#selection="SR_met100_mt150"
#selection="2lCR_mbb_met100_mct150"
#./runTemplateLooper $selection $analysis_version wh_350_1&
#./runTemplateLooper $selection $analysis_version wh_300_80&
#./runTemplateLooper $selection $analysis_version wh_250_1&
#./runTemplateLooper $selection $analysis_version wh_225_80&
###
#./runTemplateLooper $selection $analysis_version wzbb&
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version tops &
#./runTemplateLooper $selection $analysis_version wsLF &
#./runTemplateLooper $selection $analysis_version wsHF &
#./runTemplateLooper $selection $analysis_version rare &

#selection="SROneBin_yield_mbb_mct150_mt150_met150_incloneb"
#selection="2lCR_mt50_met100"
#selection="SR_met100_mt150_mct150"
#selection="yield_2lCR_mbb"                                  #-->2l CR yields with relaxed cuts 
#selection="1lCR_met100_mct150"
#selection="1lCR_met100_mtbulk_removeveto"    # for wbb look at mt bulk b tagged region
#selection="SRMultiBinV6_yield_met250"
#selection="SR_met100_mt150"
#selection="yield_2lCR_mbb_firstbinnomct_mt150"
#selection="SRMultiBinV5_yield_mbb_mct150_mt150_twobtag_jetpt150"
#selection="SR_met100_mt150_mct150_isr_twobtag"
#selection="gensel_SR_met100_mt150_mct150_twobtag_isr"
#selection="yield_2lCR_mbb"
#selection="yield_1lCR_met100_mbb_nobveto"
#selection="cutflow_loosebtag"
selection="SRMultiBinV1_yield_mbb_mct150_mt150"
#selection="SROneBin_yield_met100_mt150_mct150_mbb_loosebtag_3jets"
./runTemplateLooper $selection $analysis_version wh_350_1&
./runTemplateLooper $selection $analysis_version wh_300_80&
./runTemplateLooper $selection $analysis_version wh_250_1&
./runTemplateLooper $selection $analysis_version wh_225_80&
./runTemplateLooper $selection $analysis_version wzbb&
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version tops &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version ttbar2l &
./runTemplateLooper $selection $analysis_version singletop &
./runTemplateLooper $selection $analysis_version wsLF &
./runTemplateLooper $selection $analysis_version wsHF &
./runTemplateLooper $selection $analysis_version rare &

