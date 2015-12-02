#! /bin/bash

source settings.sh

compile_looper

#selection="3jets_met150_mt120"
selection="yield"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &

#selection="1lCRallbin_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1lCRallbin_met150_mt120"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1lCRallbin"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1lCRallbin_met150_lep200"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1lCRallbin_lep200"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1lCRallbin_absiso"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1lCRallbin_absiso_dphi"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &

#selection="1lCRallbin_absiso_dphi_mt120_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version zjets_htbin &

#selection="1lCRallbin_absiso_dphi_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1lCRallbin_absiso_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
