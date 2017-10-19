#! /bin/bash

source settings.sh

compile_looper

selection=$1
#selection="ss_sr_yield"
#./runTemplateLooper $selection $analysis_version wz  &
#./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version wjets_ht100 &
./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version ttbar_onelep &
