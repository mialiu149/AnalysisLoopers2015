#! /bin/bash

source settings.sh

compile_looper
#selection="3jets_met150_mt120"
selection="2lCR5"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &

selection="2lCR6"
./runTemplateLooper $selection $analysis_version data  &
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &

selection="yield_CR5"
./runTemplateLooper $selection $analysis_version data & 
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &

selection="yield_CR6"
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &

selection="yield_CR5_CR6"
./runTemplateLooper $selection $analysis_version data & 
./runTemplateLooper $selection $analysis_version ttbar &
./runTemplateLooper $selection $analysis_version zjets &
./runTemplateLooper $selection $analysis_version wjets &
./runTemplateLooper $selection $analysis_version QCD &
./runTemplateLooper $selection $analysis_version zjets_htbin &
./runTemplateLooper $selection $analysis_version wjets_htbin &
./runTemplateLooper $selection $analysis_version top &
./runTemplateLooper $selection $analysis_version ttv &


#selection="SR"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version top &
#./runTemplateLooper $selection $analysis_version ttv &


#selection="1l2lCRallbin_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1l2lCRallbin_met150_mt120"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1l2lCRallbin"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1l2lCRallbin_met150_lep200"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#
#selection="1l2lCRallbin_lep200"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1l2lCRallbin_absiso"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1l2lCRallbin_absiso_dphi"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &

#selection="1l2lCRallbin_absiso_dphi_mt120_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#./runTemplateLooper $selection $analysis_version zjets_htbin &

#selection="1l2lCRallbin_absiso_dphi_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
#selection="1l2lCRallbin_absiso_met150"
#./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
#
