#! /bin/bash

source settings.sh

compile_looper

selection="cutflow"
./runTemplateLooper $selection $analysis_version tops_mad&
#selection="SR_SRMultiBin_V6_yield_mbb_mct150_mt150_met100_twobtag" # get yields in SR
#selection="SR_SRMultiBin_V5_yield_mbb_mct150_mt150_met100_twobtag" # get yields in SR
