#! /bin/bash

source settings.sh

compile_looper

selection="presel_ss_ee_isotrackveto_loosebtag"
#selection="trilep_sr_yield"
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
./runTemplateLooper $selection $analysis_version singletop &
selection="presel_ss_em_isotrackveto_loosebtag"
#selection="trilep_sr_yield"
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
./runTemplateLooper $selection $analysis_version singletop &
#selection="presel_trilep_SFOS2"
selection="presel_ss_mm_isotrackveto_loosebtag"
#selection="trilep_sr_yield"
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
./runTemplateLooper $selection $analysis_version singletop &
