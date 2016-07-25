#! /bin/bash

source settings.sh

compile_looper
#selection="SR_met100_mt150_mbb_mct150_twobtag" # this is the SR
#selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag_worseMET" # get yields in SR
#selection="SR_met100_mt150_mbb_mct150_twobtag" # this is the SR
#selection="wjetsval_incl"

selection="1lCR_mbb_bveto_met100_mct150"
./runTemplateLooper $selection $analysis_version ws_ht100 &
