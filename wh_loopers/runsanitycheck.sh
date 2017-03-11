#! /bin/bash

source settings.sh

compile_looper
selection="cutflow"  # to draw money plot mbb.
./runTemplateLooper $selection $analysis_version ttbar_check  &
