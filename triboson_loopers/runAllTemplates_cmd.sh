#! /bin/bash

source settings.sh

compile_looper

selection=$1
#selection="ss_sr_yield"
./runTemplateLooper $selection $analysis_version data &
./runTemplateLooper $selection $analysis_version wg &
./runTemplateLooper $selection $analysis_version zg &
./runTemplateLooper $selection $analysis_version ttbar_dilep &
./runTemplateLooper $selection $analysis_version ttbar_onelep &
./runTemplateLooper $selection $analysis_version ww &
./runTemplateLooper $selection $analysis_version wz &
./runTemplateLooper $selection $analysis_version zz &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version zjets_ht100 &
./runTemplateLooper $selection $analysis_version wjets_ht100 &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version ttv &
./runTemplateLooper $selection $analysis_version www &
./runTemplateLooper $selection $analysis_version www_2l_ext0 &
./runTemplateLooper $selection $analysis_version www_2l_ext1 &
./runTemplateLooper $selection $analysis_version singletop &
