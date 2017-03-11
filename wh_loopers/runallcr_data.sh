#! /bin/bash

source settings.sh

compile_looper

selection="1lCR_mbb_bveto_met125_mct170"
./runTemplateLooper $selection $analysis_version data  &
selection="yield_2lCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
selection="yield_1lCR_mct170_mt150_bveto_V4_elonly"
./runTemplateLooper $selection $analysis_version data  &
selection="yield_1lCR_mct170_mt150_bveto_V4"
./runTemplateLooper $selection $analysis_version data  &
selection="yield_1lCR_mct170_mt150_bveto_V4_muonly"
./runTemplateLooper $selection $analysis_version data  &
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
./runTemplateLooper $selection $analysis_version data  &
selection="2lCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
selection="mbbCR_mix_twobtag_met125_mt150"
./runTemplateLooper $selection $analysis_version data  &
