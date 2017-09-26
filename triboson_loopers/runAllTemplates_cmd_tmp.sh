#! /bin/bash

source settings.sh

compile_looper

selection=$1
#selection="ss_sr_yield"
./runTemplateLooper $selection $analysis_version wz  &
