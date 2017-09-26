#! /bin/bash

source settings.sh

compile_looper

selection=$1
#selection="ss_sr_yield"
./runTemplateLooper $selection $analysis_version Vjj &
./runTemplateLooper $selection $analysis_version data &
./runTemplateLooper $selection $analysis_version lostlep &
./runTemplateLooper $selection $analysis_version jetfake &
./runTemplateLooper $selection $analysis_version gammafake &
./runTemplateLooper $selection $analysis_version jetfake_ht100 &
./runTemplateLooper $selection $analysis_version chargeflip_ht100 &
./runTemplateLooper $selection $analysis_version truess &
./runTemplateLooper $selection $analysis_version threelep &
./runTemplateLooper $selection $analysis_version zz &
./runTemplateLooper $selection $analysis_version chargeflip &
./runTemplateLooper $selection $analysis_version www_2l_ext0 &
./runTemplateLooper $selection $analysis_version www_2l_ext1 &
