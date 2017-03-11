#! /bin/bash

source settings.sh

compile_looper

#selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
#./runTemplateLooper $selection $analysis_version data  &
selection="2lCR_mix_twobtag_met125_mt50"
selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
#selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
#./runTemplateLooper $selection $analysis_version data&
#./runTemplateLooper $selection $analysis_version triboson&
#./runTemplateLooper $selection $analysis_version ttv&
#./runTemplateLooper $selection $analysis_version rare&
#./runTemplateLooper $selection $analysis_version ww&
#./runTemplateLooper $selection $analysis_version wz&
#./runTemplateLooper $selection $analysis_version zz&
#./runTemplateLooper $selection $analysis_version smWH&
#selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
#./runTemplateLooper $selection $analysis_version tops_mad  &
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
selection="SR_mix_met125_mt50_twobtag" # this is the SR
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
selection="1lCR_mbb_bveto_met125_mct170"
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
selection="yield_1lCR_mct170_mt150_bveto_V4"
selection="1lCR_mbb_bveto_met125_mct170"
selection="yield_2lCR_mix_mct170_mt150_twobtag_V4"
selection="yield_1lCR_mct170_mt150_bveto_V4_btagsfup"
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag_jecup" # get yields in SR
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4_btagsfup"
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4_btagsfdn"
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag_jecup" # get yields in SR
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
#selection="cutflow"
selection="yield_mbbCR_mix_mct170_mt150_twobtag_V4"
selection="SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag" # get yields in SR
selection="SR_mix_met125_mt150_mct170_twobtag"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version data&
selection="SR_mix_met125_mt150_mct170_twobtag_metbin1v4"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version data&
selection="SR_mix_met125_mt150_mct170_twobtag_metbin2v4"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version data&
