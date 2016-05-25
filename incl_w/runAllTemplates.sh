#! /bin/bash

source settings.sh

compile_looper

#selection="presel_absiso_btag_3jets_incl_met100_mt120"

#selection="bveto_2jet_excl_met100_absiso"
selection="bveto_2jet_excl_met100_absiso_mbb"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version ttbar2l &
./runTemplateLooper $selection $analysis_version ttbar1l &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets_incl &
./runTemplateLooper $selection $analysis_version wjets&
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version zjets_htbin &

#selection="presel_absiso_btag_2jet_excl_withbtagweight"

