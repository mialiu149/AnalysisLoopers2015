#! /bin/bash

source settings.sh

compile_looper
#selection="SR_yield_met_trigger"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
##./runTemplateLooper $selection $analysis_version WW&
##./runTemplateLooper $selection $analysis_version WZ&
##./runTemplateLooper $selection $analysis_version ZZ&
##./runTemplateLooper $selection $analysis_version ttw&
##./runTemplateLooper $selection $analysis_version tZq&
#selection="SR_yield_met_trigger_scale0"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale1"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale2"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale3"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale4"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale5"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale6"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale7"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_scale8"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_pdf_up"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_pdf_dn"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_pdf_alpha1"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#selection="SR_yield_met_trigger_pdf_alpha2"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag&
#
##selection="SR_yield_met_trigger_btagsf"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag& 
#selection="SR_yield_met_trigger_btagsf_heavy_UP"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag& 
#selection="SR_yield_met_trigger_btagsf_heavy_DN"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag& 
#selection="SR_yield_met_trigger_btagsf_light_UP"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag& 
#selection="SR_yield_met_trigger_btagsf_light_DN"
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz_btag& 
#./runTemplateLooper $selection $analysis_version jes_up_ttz& 
#./runTemplateLooper $selection $analysis_version jes_dn_ttz& 
#./runTemplateLooper $selection $analysis_version jes_nominal_ttz& 

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

selection="CR5_CR6_yield_met_trigger"
./runTemplateLooper $selection $analysis_version data  &
#./runTemplateLooper $selection $analysis_version ttbar &
#./runTemplateLooper $selection $analysis_version zjets &
#./runTemplateLooper $selection $analysis_version wjets &
#./runTemplateLooper $selection $analysis_version QCD &
#./runTemplateLooper $selection $analysis_version zjets_htbin &
#./runTemplateLooper $selection $analysis_version wjets_htbin &
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
