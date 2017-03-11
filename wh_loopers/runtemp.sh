#! /bin/bash

source settings.sh

compile_looper

selection="presel"
./runTemplateLooper $selection $analysis_version w2jets_nupt200 &
./runTemplateLooper $selection $analysis_version w2jets_nupt100 &
./runTemplateLooper $selection $analysis_version w2jets&
