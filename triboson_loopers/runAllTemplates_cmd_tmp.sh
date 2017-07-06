#! /bin/bash

source settings.sh

compile_looper

selection=$1
#selection="ss_sr_yield"
./runTemplateLooper $selection $analysis_version ttbar_onelep  &
#./runTemplateLooper $selection $analysis_version www_2l_ext0  &
