#! /bin/bash

source settings.sh

compile_looper

#selection="SR_yield_newbin_2btags_2jets_mbb90_mct170"
selection="2lCR"
./runTemplateLooper $selection $analysis_version ttbar &

