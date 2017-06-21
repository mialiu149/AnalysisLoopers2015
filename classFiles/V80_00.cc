#include "V80_00.h"
V80_00 v80_00;

void V80_00::Init(TTree *tree) {
	lep1_p4_branch = 0;
	if (tree->GetBranch("lep1_p4") != 0) {
		lep1_p4_branch = tree->GetBranch("lep1_p4");
		if (lep1_p4_branch) {lep1_p4_branch->SetAddress(&lep1_p4_);}
	}
	lep1_mcp4_branch = 0;
	if (tree->GetBranch("lep1_mcp4") != 0) {
		lep1_mcp4_branch = tree->GetBranch("lep1_mcp4");
		if (lep1_mcp4_branch) {lep1_mcp4_branch->SetAddress(&lep1_mcp4_);}
	}
	lep2_p4_branch = 0;
	if (tree->GetBranch("lep2_p4") != 0) {
		lep2_p4_branch = tree->GetBranch("lep2_p4");
		if (lep2_p4_branch) {lep2_p4_branch->SetAddress(&lep2_p4_);}
	}
	lep2_mcp4_branch = 0;
	if (tree->GetBranch("lep2_mcp4") != 0) {
		lep2_mcp4_branch = tree->GetBranch("lep2_mcp4");
		if (lep2_mcp4_branch) {lep2_mcp4_branch->SetAddress(&lep2_mcp4_);}
	}
	ph_p4_branch = 0;
	if (tree->GetBranch("ph_p4") != 0) {
		ph_p4_branch = tree->GetBranch("ph_p4");
		if (ph_p4_branch) {ph_p4_branch->SetAddress(&ph_p4_);}
	}
	ph_mcp4_branch = 0;
	if (tree->GetBranch("ph_mcp4") != 0) {
		ph_mcp4_branch = tree->GetBranch("ph_mcp4");
		if (ph_mcp4_branch) {ph_mcp4_branch->SetAddress(&ph_mcp4_);}
	}
	ak4pfjets_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_p4") != 0) {
		ak4pfjets_p4_branch = tree->GetBranch("ak4pfjets_p4");
		if (ak4pfjets_p4_branch) {ak4pfjets_p4_branch->SetAddress(&ak4pfjets_p4_);}
	}
	ak4pfjets_leadMEDbjet_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadMEDbjet_p4") != 0) {
		ak4pfjets_leadMEDbjet_p4_branch = tree->GetBranch("ak4pfjets_leadMEDbjet_p4");
		if (ak4pfjets_leadMEDbjet_p4_branch) {ak4pfjets_leadMEDbjet_p4_branch->SetAddress(&ak4pfjets_leadMEDbjet_p4_);}
	}
	ak4pfjets_leadbtag_p4_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadbtag_p4") != 0) {
		ak4pfjets_leadbtag_p4_branch = tree->GetBranch("ak4pfjets_leadbtag_p4");
		if (ak4pfjets_leadbtag_p4_branch) {ak4pfjets_leadbtag_p4_branch->SetAddress(&ak4pfjets_leadbtag_p4_);}
	}
	ak4genjets_p4_branch = 0;
	if (tree->GetBranch("ak4genjets_p4") != 0) {
		ak4genjets_p4_branch = tree->GetBranch("ak4genjets_p4");
		if (ak4genjets_p4_branch) {ak4genjets_p4_branch->SetAddress(&ak4genjets_p4_);}
	}
	genleps_p4_branch = 0;
	if (tree->GetBranch("genleps_p4") != 0) {
		genleps_p4_branch = tree->GetBranch("genleps_p4");
		if (genleps_p4_branch) {genleps_p4_branch->SetAddress(&genleps_p4_);}
	}
	genleps_motherp4_branch = 0;
	if (tree->GetBranch("genleps_motherp4") != 0) {
		genleps_motherp4_branch = tree->GetBranch("genleps_motherp4");
		if (genleps_motherp4_branch) {genleps_motherp4_branch->SetAddress(&genleps_motherp4_);}
	}
	genleps_gmotherp4_branch = 0;
	if (tree->GetBranch("genleps_gmotherp4") != 0) {
		genleps_gmotherp4_branch = tree->GetBranch("genleps_gmotherp4");
		if (genleps_gmotherp4_branch) {genleps_gmotherp4_branch->SetAddress(&genleps_gmotherp4_);}
	}
	gennus_p4_branch = 0;
	if (tree->GetBranch("gennus_p4") != 0) {
		gennus_p4_branch = tree->GetBranch("gennus_p4");
		if (gennus_p4_branch) {gennus_p4_branch->SetAddress(&gennus_p4_);}
	}
	gennus_motherp4_branch = 0;
	if (tree->GetBranch("gennus_motherp4") != 0) {
		gennus_motherp4_branch = tree->GetBranch("gennus_motherp4");
		if (gennus_motherp4_branch) {gennus_motherp4_branch->SetAddress(&gennus_motherp4_);}
	}
	gennus_gmotherp4_branch = 0;
	if (tree->GetBranch("gennus_gmotherp4") != 0) {
		gennus_gmotherp4_branch = tree->GetBranch("gennus_gmotherp4");
		if (gennus_gmotherp4_branch) {gennus_gmotherp4_branch->SetAddress(&gennus_gmotherp4_);}
	}
	genqs_p4_branch = 0;
	if (tree->GetBranch("genqs_p4") != 0) {
		genqs_p4_branch = tree->GetBranch("genqs_p4");
		if (genqs_p4_branch) {genqs_p4_branch->SetAddress(&genqs_p4_);}
	}
	genqs_motherp4_branch = 0;
	if (tree->GetBranch("genqs_motherp4") != 0) {
		genqs_motherp4_branch = tree->GetBranch("genqs_motherp4");
		if (genqs_motherp4_branch) {genqs_motherp4_branch->SetAddress(&genqs_motherp4_);}
	}
	genqs_gmotherp4_branch = 0;
	if (tree->GetBranch("genqs_gmotherp4") != 0) {
		genqs_gmotherp4_branch = tree->GetBranch("genqs_gmotherp4");
		if (genqs_gmotherp4_branch) {genqs_gmotherp4_branch->SetAddress(&genqs_gmotherp4_);}
	}
	genbosons_p4_branch = 0;
	if (tree->GetBranch("genbosons_p4") != 0) {
		genbosons_p4_branch = tree->GetBranch("genbosons_p4");
		if (genbosons_p4_branch) {genbosons_p4_branch->SetAddress(&genbosons_p4_);}
	}
	genbosons_motherp4_branch = 0;
	if (tree->GetBranch("genbosons_motherp4") != 0) {
		genbosons_motherp4_branch = tree->GetBranch("genbosons_motherp4");
		if (genbosons_motherp4_branch) {genbosons_motherp4_branch->SetAddress(&genbosons_motherp4_);}
	}
	genbosons_gmotherp4_branch = 0;
	if (tree->GetBranch("genbosons_gmotherp4") != 0) {
		genbosons_gmotherp4_branch = tree->GetBranch("genbosons_gmotherp4");
		if (genbosons_gmotherp4_branch) {genbosons_gmotherp4_branch->SetAddress(&genbosons_gmotherp4_);}
	}
	gensusy_p4_branch = 0;
	if (tree->GetBranch("gensusy_p4") != 0) {
		gensusy_p4_branch = tree->GetBranch("gensusy_p4");
		if (gensusy_p4_branch) {gensusy_p4_branch->SetAddress(&gensusy_p4_);}
	}
	gensusy_motherp4_branch = 0;
	if (tree->GetBranch("gensusy_motherp4") != 0) {
		gensusy_motherp4_branch = tree->GetBranch("gensusy_motherp4");
		if (gensusy_motherp4_branch) {gensusy_motherp4_branch->SetAddress(&gensusy_motherp4_);}
	}
	gensusy_gmotherp4_branch = 0;
	if (tree->GetBranch("gensusy_gmotherp4") != 0) {
		gensusy_gmotherp4_branch = tree->GetBranch("gensusy_gmotherp4");
		if (gensusy_gmotherp4_branch) {gensusy_gmotherp4_branch->SetAddress(&gensusy_gmotherp4_);}
	}
  tree->SetMakeClass(1);
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	ls_branch = 0;
	if (tree->GetBranch("ls") != 0) {
		ls_branch = tree->GetBranch("ls");
		if (ls_branch) {ls_branch->SetAddress(&ls_);}
	}
	evt_branch = 0;
	if (tree->GetBranch("evt") != 0) {
		evt_branch = tree->GetBranch("evt");
		if (evt_branch) {evt_branch->SetAddress(&evt_);}
	}
	nvtxs_branch = 0;
	if (tree->GetBranch("nvtxs") != 0) {
		nvtxs_branch = tree->GetBranch("nvtxs");
		if (nvtxs_branch) {nvtxs_branch->SetAddress(&nvtxs_);}
	}
	pu_nvtxs_branch = 0;
	if (tree->GetBranch("pu_nvtxs") != 0) {
		pu_nvtxs_branch = tree->GetBranch("pu_nvtxs");
		if (pu_nvtxs_branch) {pu_nvtxs_branch->SetAddress(&pu_nvtxs_);}
	}
	pfmet_branch = 0;
	if (tree->GetBranch("pfmet") != 0) {
		pfmet_branch = tree->GetBranch("pfmet");
		if (pfmet_branch) {pfmet_branch->SetAddress(&pfmet_);}
	}
	pfmet_phi_branch = 0;
	if (tree->GetBranch("pfmet_phi") != 0) {
		pfmet_phi_branch = tree->GetBranch("pfmet_phi");
		if (pfmet_phi_branch) {pfmet_phi_branch->SetAddress(&pfmet_phi_);}
	}
	scale1fb_branch = 0;
	if (tree->GetBranch("scale1fb") != 0) {
		scale1fb_branch = tree->GetBranch("scale1fb");
		if (scale1fb_branch) {scale1fb_branch->SetAddress(&scale1fb_);}
	}
	xsec_branch = 0;
	if (tree->GetBranch("xsec") != 0) {
		xsec_branch = tree->GetBranch("xsec");
		if (xsec_branch) {xsec_branch->SetAddress(&xsec_);}
	}
	xsec_uncert_branch = 0;
	if (tree->GetBranch("xsec_uncert") != 0) {
		xsec_uncert_branch = tree->GetBranch("xsec_uncert");
		if (xsec_uncert_branch) {xsec_uncert_branch->SetAddress(&xsec_uncert_);}
	}
	kfactor_branch = 0;
	if (tree->GetBranch("kfactor") != 0) {
		kfactor_branch = tree->GetBranch("kfactor");
		if (kfactor_branch) {kfactor_branch->SetAddress(&kfactor_);}
	}
	pu_ntrue_branch = 0;
	if (tree->GetBranch("pu_ntrue") != 0) {
		pu_ntrue_branch = tree->GetBranch("pu_ntrue");
		if (pu_ntrue_branch) {pu_ntrue_branch->SetAddress(&pu_ntrue_);}
	}
	ngoodleps_branch = 0;
	if (tree->GetBranch("ngoodleps") != 0) {
		ngoodleps_branch = tree->GetBranch("ngoodleps");
		if (ngoodleps_branch) {ngoodleps_branch->SetAddress(&ngoodleps_);}
	}
	nvetoleps_branch = 0;
	if (tree->GetBranch("nvetoleps") != 0) {
		nvetoleps_branch = tree->GetBranch("nvetoleps");
		if (nvetoleps_branch) {nvetoleps_branch->SetAddress(&nvetoleps_);}
	}
	is_data_branch = 0;
	if (tree->GetBranch("is_data") != 0) {
		is_data_branch = tree->GetBranch("is_data");
		if (is_data_branch) {is_data_branch->SetAddress(&is_data_);}
	}
	dataset_branch = 0;
	if (tree->GetBranch("dataset") != 0) {
		dataset_branch = tree->GetBranch("dataset");
		if (dataset_branch) {dataset_branch->SetAddress(&dataset_);}
	}
	filename_branch = 0;
	if (tree->GetBranch("filename") != 0) {
		filename_branch = tree->GetBranch("filename");
		if (filename_branch) {filename_branch->SetAddress(&filename_);}
	}
	cms3tag_branch = 0;
	if (tree->GetBranch("cms3tag") != 0) {
		cms3tag_branch = tree->GetBranch("cms3tag");
		if (cms3tag_branch) {cms3tag_branch->SetAddress(&cms3tag_);}
	}
	nEvents_branch = 0;
	if (tree->GetBranch("nEvents") != 0) {
		nEvents_branch = tree->GetBranch("nEvents");
		if (nEvents_branch) {nEvents_branch->SetAddress(&nEvents_);}
	}
	nEvents_goodvtx_branch = 0;
	if (tree->GetBranch("nEvents_goodvtx") != 0) {
		nEvents_goodvtx_branch = tree->GetBranch("nEvents_goodvtx");
		if (nEvents_goodvtx_branch) {nEvents_goodvtx_branch->SetAddress(&nEvents_goodvtx_);}
	}
	nEvents_MET30_branch = 0;
	if (tree->GetBranch("nEvents_MET30") != 0) {
		nEvents_MET30_branch = tree->GetBranch("nEvents_MET30");
		if (nEvents_MET30_branch) {nEvents_MET30_branch->SetAddress(&nEvents_MET30_);}
	}
	nEvents_1goodlep_branch = 0;
	if (tree->GetBranch("nEvents_1goodlep") != 0) {
		nEvents_1goodlep_branch = tree->GetBranch("nEvents_1goodlep");
		if (nEvents_1goodlep_branch) {nEvents_1goodlep_branch->SetAddress(&nEvents_1goodlep_);}
	}
	nEvents_2goodjets_branch = 0;
	if (tree->GetBranch("nEvents_2goodjets") != 0) {
		nEvents_2goodjets_branch = tree->GetBranch("nEvents_2goodjets");
		if (nEvents_2goodjets_branch) {nEvents_2goodjets_branch->SetAddress(&nEvents_2goodjets_);}
	}
	is0lep_branch = 0;
	if (tree->GetBranch("is0lep") != 0) {
		is0lep_branch = tree->GetBranch("is0lep");
		if (is0lep_branch) {is0lep_branch->SetAddress(&is0lep_);}
	}
	is1lep_branch = 0;
	if (tree->GetBranch("is1lep") != 0) {
		is1lep_branch = tree->GetBranch("is1lep");
		if (is1lep_branch) {is1lep_branch->SetAddress(&is1lep_);}
	}
	is2lep_branch = 0;
	if (tree->GetBranch("is2lep") != 0) {
		is2lep_branch = tree->GetBranch("is2lep");
		if (is2lep_branch) {is2lep_branch->SetAddress(&is2lep_);}
	}
	isZtoNuNu_branch = 0;
	if (tree->GetBranch("isZtoNuNu") != 0) {
		isZtoNuNu_branch = tree->GetBranch("isZtoNuNu");
		if (isZtoNuNu_branch) {isZtoNuNu_branch->SetAddress(&isZtoNuNu_);}
	}
	is1lepFromW_branch = 0;
	if (tree->GetBranch("is1lepFromW") != 0) {
		is1lepFromW_branch = tree->GetBranch("is1lepFromW");
		if (is1lepFromW_branch) {is1lepFromW_branch->SetAddress(&is1lepFromW_);}
	}
	is1lepFromTop_branch = 0;
	if (tree->GetBranch("is1lepFromTop") != 0) {
		is1lepFromTop_branch = tree->GetBranch("is1lepFromTop");
		if (is1lepFromTop_branch) {is1lepFromTop_branch->SetAddress(&is1lepFromTop_);}
	}
	MT2W_branch = 0;
	if (tree->GetBranch("MT2W") != 0) {
		MT2W_branch = tree->GetBranch("MT2W");
		if (MT2W_branch) {MT2W_branch->SetAddress(&MT2W_);}
	}
	mindphi_met_j1_j2_branch = 0;
	if (tree->GetBranch("mindphi_met_j1_j2") != 0) {
		mindphi_met_j1_j2_branch = tree->GetBranch("mindphi_met_j1_j2");
		if (mindphi_met_j1_j2_branch) {mindphi_met_j1_j2_branch->SetAddress(&mindphi_met_j1_j2_);}
	}
	mt_met_lep_branch = 0;
	if (tree->GetBranch("mt_met_lep") != 0) {
		mt_met_lep_branch = tree->GetBranch("mt_met_lep");
		if (mt_met_lep_branch) {mt_met_lep_branch->SetAddress(&mt_met_lep_);}
	}
	hadronic_top_chi2_branch = 0;
	if (tree->GetBranch("hadronic_top_chi2") != 0) {
		hadronic_top_chi2_branch = tree->GetBranch("hadronic_top_chi2");
		if (hadronic_top_chi2_branch) {hadronic_top_chi2_branch->SetAddress(&hadronic_top_chi2_);}
	}
	ak4pfjets_rho_branch = 0;
	if (tree->GetBranch("ak4pfjets_rho") != 0) {
		ak4pfjets_rho_branch = tree->GetBranch("ak4pfjets_rho");
		if (ak4pfjets_rho_branch) {ak4pfjets_rho_branch->SetAddress(&ak4pfjets_rho_);}
	}
	pdf_up_weight_branch = 0;
	if (tree->GetBranch("pdf_up_weight") != 0) {
		pdf_up_weight_branch = tree->GetBranch("pdf_up_weight");
		if (pdf_up_weight_branch) {pdf_up_weight_branch->SetAddress(&pdf_up_weight_);}
	}
	pdf_down_weight_branch = 0;
	if (tree->GetBranch("pdf_down_weight") != 0) {
		pdf_down_weight_branch = tree->GetBranch("pdf_down_weight");
		if (pdf_down_weight_branch) {pdf_down_weight_branch->SetAddress(&pdf_down_weight_);}
	}
	genweightsID_branch = 0;
	if (tree->GetBranch("genweightsID") != 0) {
		genweightsID_branch = tree->GetBranch("genweightsID");
		if (genweightsID_branch) {genweightsID_branch->SetAddress(&genweightsID_);}
	}
	genweights_branch = 0;
	if (tree->GetBranch("genweights") != 0) {
		genweights_branch = tree->GetBranch("genweights");
		if (genweights_branch) {genweights_branch->SetAddress(&genweights_);}
	}
	weight_btagsf_branch = 0;
	if (tree->GetBranch("weight_btagsf") != 0) {
		weight_btagsf_branch = tree->GetBranch("weight_btagsf");
		if (weight_btagsf_branch) {weight_btagsf_branch->SetAddress(&weight_btagsf_);}
	}
	weight_btagsf_heavy_UP_branch = 0;
	if (tree->GetBranch("weight_btagsf_heavy_UP") != 0) {
		weight_btagsf_heavy_UP_branch = tree->GetBranch("weight_btagsf_heavy_UP");
		if (weight_btagsf_heavy_UP_branch) {weight_btagsf_heavy_UP_branch->SetAddress(&weight_btagsf_heavy_UP_);}
	}
	weight_btagsf_light_UP_branch = 0;
	if (tree->GetBranch("weight_btagsf_light_UP") != 0) {
		weight_btagsf_light_UP_branch = tree->GetBranch("weight_btagsf_light_UP");
		if (weight_btagsf_light_UP_branch) {weight_btagsf_light_UP_branch->SetAddress(&weight_btagsf_light_UP_);}
	}
	weight_btagsf_heavy_DN_branch = 0;
	if (tree->GetBranch("weight_btagsf_heavy_DN") != 0) {
		weight_btagsf_heavy_DN_branch = tree->GetBranch("weight_btagsf_heavy_DN");
		if (weight_btagsf_heavy_DN_branch) {weight_btagsf_heavy_DN_branch->SetAddress(&weight_btagsf_heavy_DN_);}
	}
	weight_btagsf_light_DN_branch = 0;
	if (tree->GetBranch("weight_btagsf_light_DN") != 0) {
		weight_btagsf_light_DN_branch = tree->GetBranch("weight_btagsf_light_DN");
		if (weight_btagsf_light_DN_branch) {weight_btagsf_light_DN_branch->SetAddress(&weight_btagsf_light_DN_);}
	}
	weight_btagsf_fastsim_UP_branch = 0;
	if (tree->GetBranch("weight_btagsf_fastsim_UP") != 0) {
		weight_btagsf_fastsim_UP_branch = tree->GetBranch("weight_btagsf_fastsim_UP");
		if (weight_btagsf_fastsim_UP_branch) {weight_btagsf_fastsim_UP_branch->SetAddress(&weight_btagsf_fastsim_UP_);}
	}
	weight_btagsf_fastsim_DN_branch = 0;
	if (tree->GetBranch("weight_btagsf_fastsim_DN") != 0) {
		weight_btagsf_fastsim_DN_branch = tree->GetBranch("weight_btagsf_fastsim_DN");
		if (weight_btagsf_fastsim_DN_branch) {weight_btagsf_fastsim_DN_branch->SetAddress(&weight_btagsf_fastsim_DN_);}
	}
	weight_lepSF_branch = 0;
	if (tree->GetBranch("weight_lepSF") != 0) {
		weight_lepSF_branch = tree->GetBranch("weight_lepSF");
		if (weight_lepSF_branch) {weight_lepSF_branch->SetAddress(&weight_lepSF_);}
	}
	weight_lepSF_up_branch = 0;
	if (tree->GetBranch("weight_lepSF_up") != 0) {
		weight_lepSF_up_branch = tree->GetBranch("weight_lepSF_up");
		if (weight_lepSF_up_branch) {weight_lepSF_up_branch->SetAddress(&weight_lepSF_up_);}
	}
	weight_lepSF_down_branch = 0;
	if (tree->GetBranch("weight_lepSF_down") != 0) {
		weight_lepSF_down_branch = tree->GetBranch("weight_lepSF_down");
		if (weight_lepSF_down_branch) {weight_lepSF_down_branch->SetAddress(&weight_lepSF_down_);}
	}
	weight_vetoLepSF_branch = 0;
	if (tree->GetBranch("weight_vetoLepSF") != 0) {
		weight_vetoLepSF_branch = tree->GetBranch("weight_vetoLepSF");
		if (weight_vetoLepSF_branch) {weight_vetoLepSF_branch->SetAddress(&weight_vetoLepSF_);}
	}
	weight_vetoLepSF_up_branch = 0;
	if (tree->GetBranch("weight_vetoLepSF_up") != 0) {
		weight_vetoLepSF_up_branch = tree->GetBranch("weight_vetoLepSF_up");
		if (weight_vetoLepSF_up_branch) {weight_vetoLepSF_up_branch->SetAddress(&weight_vetoLepSF_up_);}
	}
	weight_vetoLepSF_down_branch = 0;
	if (tree->GetBranch("weight_vetoLepSF_down") != 0) {
		weight_vetoLepSF_down_branch = tree->GetBranch("weight_vetoLepSF_down");
		if (weight_vetoLepSF_down_branch) {weight_vetoLepSF_down_branch->SetAddress(&weight_vetoLepSF_down_);}
	}
	weight_lepSF_fastSim_branch = 0;
	if (tree->GetBranch("weight_lepSF_fastSim") != 0) {
		weight_lepSF_fastSim_branch = tree->GetBranch("weight_lepSF_fastSim");
		if (weight_lepSF_fastSim_branch) {weight_lepSF_fastSim_branch->SetAddress(&weight_lepSF_fastSim_);}
	}
	weight_lepSF_fastSim_up_branch = 0;
	if (tree->GetBranch("weight_lepSF_fastSim_up") != 0) {
		weight_lepSF_fastSim_up_branch = tree->GetBranch("weight_lepSF_fastSim_up");
		if (weight_lepSF_fastSim_up_branch) {weight_lepSF_fastSim_up_branch->SetAddress(&weight_lepSF_fastSim_up_);}
	}
	weight_lepSF_fastSim_down_branch = 0;
	if (tree->GetBranch("weight_lepSF_fastSim_down") != 0) {
		weight_lepSF_fastSim_down_branch = tree->GetBranch("weight_lepSF_fastSim_down");
		if (weight_lepSF_fastSim_down_branch) {weight_lepSF_fastSim_down_branch->SetAddress(&weight_lepSF_fastSim_down_);}
	}
	weight_ISR_branch = 0;
	if (tree->GetBranch("weight_ISR") != 0) {
		weight_ISR_branch = tree->GetBranch("weight_ISR");
		if (weight_ISR_branch) {weight_ISR_branch->SetAddress(&weight_ISR_);}
	}
	weight_ISRup_branch = 0;
	if (tree->GetBranch("weight_ISRup") != 0) {
		weight_ISRup_branch = tree->GetBranch("weight_ISRup");
		if (weight_ISRup_branch) {weight_ISRup_branch->SetAddress(&weight_ISRup_);}
	}
	weight_ISRdown_branch = 0;
	if (tree->GetBranch("weight_ISRdown") != 0) {
		weight_ISRdown_branch = tree->GetBranch("weight_ISRdown");
		if (weight_ISRdown_branch) {weight_ISRdown_branch->SetAddress(&weight_ISRdown_);}
	}
	weight_PU_branch = 0;
	if (tree->GetBranch("weight_PU") != 0) {
		weight_PU_branch = tree->GetBranch("weight_PU");
		if (weight_PU_branch) {weight_PU_branch->SetAddress(&weight_PU_);}
	}
	weight_PUup_branch = 0;
	if (tree->GetBranch("weight_PUup") != 0) {
		weight_PUup_branch = tree->GetBranch("weight_PUup");
		if (weight_PUup_branch) {weight_PUup_branch->SetAddress(&weight_PUup_);}
	}
	weight_PUdown_branch = 0;
	if (tree->GetBranch("weight_PUdown") != 0) {
		weight_PUdown_branch = tree->GetBranch("weight_PUdown");
		if (weight_PUdown_branch) {weight_PUdown_branch->SetAddress(&weight_PUdown_);}
	}
	sparms_names_branch = 0;
	if (tree->GetBranch("sparms_names") != 0) {
		sparms_names_branch = tree->GetBranch("sparms_names");
		if (sparms_names_branch) {sparms_names_branch->SetAddress(&sparms_names_);}
	}
	sparms_values_branch = 0;
	if (tree->GetBranch("sparms_values") != 0) {
		sparms_values_branch = tree->GetBranch("sparms_values");
		if (sparms_values_branch) {sparms_values_branch->SetAddress(&sparms_values_);}
	}
	sparms_subProcessId_branch = 0;
	if (tree->GetBranch("sparms_subProcessId") != 0) {
		sparms_subProcessId_branch = tree->GetBranch("sparms_subProcessId");
		if (sparms_subProcessId_branch) {sparms_subProcessId_branch->SetAddress(&sparms_subProcessId_);}
	}
	mass_lsp_branch = 0;
	if (tree->GetBranch("mass_lsp") != 0) {
		mass_lsp_branch = tree->GetBranch("mass_lsp");
		if (mass_lsp_branch) {mass_lsp_branch->SetAddress(&mass_lsp_);}
	}
	mass_chargino_branch = 0;
	if (tree->GetBranch("mass_chargino") != 0) {
		mass_chargino_branch = tree->GetBranch("mass_chargino");
		if (mass_chargino_branch) {mass_chargino_branch->SetAddress(&mass_chargino_);}
	}
	mass_stop_branch = 0;
	if (tree->GetBranch("mass_stop") != 0) {
		mass_stop_branch = tree->GetBranch("mass_stop");
		if (mass_stop_branch) {mass_stop_branch->SetAddress(&mass_stop_);}
	}
	mass_gluino_branch = 0;
	if (tree->GetBranch("mass_gluino") != 0) {
		mass_gluino_branch = tree->GetBranch("mass_gluino");
		if (mass_gluino_branch) {mass_gluino_branch->SetAddress(&mass_gluino_);}
	}
	genmet_branch = 0;
	if (tree->GetBranch("genmet") != 0) {
		genmet_branch = tree->GetBranch("genmet");
		if (genmet_branch) {genmet_branch->SetAddress(&genmet_);}
	}
	genmet_phi_branch = 0;
	if (tree->GetBranch("genmet_phi") != 0) {
		genmet_phi_branch = tree->GetBranch("genmet_phi");
		if (genmet_phi_branch) {genmet_phi_branch->SetAddress(&genmet_phi_);}
	}
	genht_branch = 0;
	if (tree->GetBranch("genht") != 0) {
		genht_branch = tree->GetBranch("genht");
		if (genht_branch) {genht_branch->SetAddress(&genht_);}
	}
	PassTrackVeto_branch = 0;
	if (tree->GetBranch("PassTrackVeto") != 0) {
		PassTrackVeto_branch = tree->GetBranch("PassTrackVeto");
		if (PassTrackVeto_branch) {PassTrackVeto_branch->SetAddress(&PassTrackVeto_);}
	}
	PassTauVeto_branch = 0;
	if (tree->GetBranch("PassTauVeto") != 0) {
		PassTauVeto_branch = tree->GetBranch("PassTauVeto");
		if (PassTauVeto_branch) {PassTauVeto_branch->SetAddress(&PassTauVeto_);}
	}
	topness_branch = 0;
	if (tree->GetBranch("topness") != 0) {
		topness_branch = tree->GetBranch("topness");
		if (topness_branch) {topness_branch->SetAddress(&topness_);}
	}
	topnessMod_branch = 0;
	if (tree->GetBranch("topnessMod") != 0) {
		topnessMod_branch = tree->GetBranch("topnessMod");
		if (topnessMod_branch) {topnessMod_branch->SetAddress(&topnessMod_);}
	}
	Mlb_closestb_branch = 0;
	if (tree->GetBranch("Mlb_closestb") != 0) {
		Mlb_closestb_branch = tree->GetBranch("Mlb_closestb");
		if (Mlb_closestb_branch) {Mlb_closestb_branch->SetAddress(&Mlb_closestb_);}
	}
	HLT_SingleEl_branch = 0;
	if (tree->GetBranch("HLT_SingleEl") != 0) {
		HLT_SingleEl_branch = tree->GetBranch("HLT_SingleEl");
		if (HLT_SingleEl_branch) {HLT_SingleEl_branch->SetAddress(&HLT_SingleEl_);}
	}
	HLT_SingleMu_branch = 0;
	if (tree->GetBranch("HLT_SingleMu") != 0) {
		HLT_SingleMu_branch = tree->GetBranch("HLT_SingleMu");
		if (HLT_SingleMu_branch) {HLT_SingleMu_branch->SetAddress(&HLT_SingleMu_);}
	}
	HLT_SingleMuNoIso_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoIso") != 0) {
		HLT_SingleMuNoIso_branch = tree->GetBranch("HLT_SingleMuNoIso");
		if (HLT_SingleMuNoIso_branch) {HLT_SingleMuNoIso_branch->SetAddress(&HLT_SingleMuNoIso_);}
	}
	HLT_SingleElNoIso_branch = 0;
	if (tree->GetBranch("HLT_SingleElNoIso") != 0) {
		HLT_SingleElNoIso_branch = tree->GetBranch("HLT_SingleElNoIso");
		if (HLT_SingleElNoIso_branch) {HLT_SingleElNoIso_branch->SetAddress(&HLT_SingleElNoIso_);}
	}
	HLT_MET_branch = 0;
	if (tree->GetBranch("HLT_MET") != 0) {
		HLT_MET_branch = tree->GetBranch("HLT_MET");
		if (HLT_MET_branch) {HLT_MET_branch->SetAddress(&HLT_MET_);}
	}
	HLT_DiEl_branch = 0;
	if (tree->GetBranch("HLT_DiEl") != 0) {
		HLT_DiEl_branch = tree->GetBranch("HLT_DiEl");
		if (HLT_DiEl_branch) {HLT_DiEl_branch->SetAddress(&HLT_DiEl_);}
	}
	HLT_DiMu_branch = 0;
	if (tree->GetBranch("HLT_DiMu") != 0) {
		HLT_DiMu_branch = tree->GetBranch("HLT_DiMu");
		if (HLT_DiMu_branch) {HLT_DiMu_branch->SetAddress(&HLT_DiMu_);}
	}
	HLT_MuE_branch = 0;
	if (tree->GetBranch("HLT_MuE") != 0) {
		HLT_MuE_branch = tree->GetBranch("HLT_MuE");
		if (HLT_MuE_branch) {HLT_MuE_branch->SetAddress(&HLT_MuE_);}
	}
	HLT_Photon90_CaloIdL_PFHT500_branch = 0;
	if (tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500") != 0) {
		HLT_Photon90_CaloIdL_PFHT500_branch = tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500");
		if (HLT_Photon90_CaloIdL_PFHT500_branch) {HLT_Photon90_CaloIdL_PFHT500_branch->SetAddress(&HLT_Photon90_CaloIdL_PFHT500_);}
	}
	HLT_Photon22_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon22_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon22_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon22_R9Id90_HE10_IsoM");
		if (HLT_Photon22_R9Id90_HE10_IsoM_branch) {HLT_Photon22_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon22_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon30_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon30_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon30_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon30_R9Id90_HE10_IsoM");
		if (HLT_Photon30_R9Id90_HE10_IsoM_branch) {HLT_Photon30_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon30_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon36_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon36_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon36_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon36_R9Id90_HE10_IsoM");
		if (HLT_Photon36_R9Id90_HE10_IsoM_branch) {HLT_Photon36_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon36_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon50_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon50_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon50_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon50_R9Id90_HE10_IsoM");
		if (HLT_Photon50_R9Id90_HE10_IsoM_branch) {HLT_Photon50_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon50_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon75_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon75_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon75_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon75_R9Id90_HE10_IsoM");
		if (HLT_Photon75_R9Id90_HE10_IsoM_branch) {HLT_Photon75_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon75_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon90_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon90_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon90_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon90_R9Id90_HE10_IsoM");
		if (HLT_Photon90_R9Id90_HE10_IsoM_branch) {HLT_Photon90_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon90_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon120_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon120_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon120_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon120_R9Id90_HE10_IsoM");
		if (HLT_Photon120_R9Id90_HE10_IsoM_branch) {HLT_Photon120_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon120_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon165_R9Id90_HE10_IsoM_branch = 0;
	if (tree->GetBranch("HLT_Photon165_R9Id90_HE10_IsoM") != 0) {
		HLT_Photon165_R9Id90_HE10_IsoM_branch = tree->GetBranch("HLT_Photon165_R9Id90_HE10_IsoM");
		if (HLT_Photon165_R9Id90_HE10_IsoM_branch) {HLT_Photon165_R9Id90_HE10_IsoM_branch->SetAddress(&HLT_Photon165_R9Id90_HE10_IsoM_);}
	}
	HLT_Photon175_branch = 0;
	if (tree->GetBranch("HLT_Photon175") != 0) {
		HLT_Photon175_branch = tree->GetBranch("HLT_Photon175");
		if (HLT_Photon175_branch) {HLT_Photon175_branch->SetAddress(&HLT_Photon175_);}
	}
	HLT_Photon165_HE10_branch = 0;
	if (tree->GetBranch("HLT_Photon165_HE10") != 0) {
		HLT_Photon165_HE10_branch = tree->GetBranch("HLT_Photon165_HE10");
		if (HLT_Photon165_HE10_branch) {HLT_Photon165_HE10_branch->SetAddress(&HLT_Photon165_HE10_);}
	}
	nPhotons_branch = 0;
	if (tree->GetBranch("nPhotons") != 0) {
		nPhotons_branch = tree->GetBranch("nPhotons");
		if (nPhotons_branch) {nPhotons_branch->SetAddress(&nPhotons_);}
	}
	ph_ngoodjets_branch = 0;
	if (tree->GetBranch("ph_ngoodjets") != 0) {
		ph_ngoodjets_branch = tree->GetBranch("ph_ngoodjets");
		if (ph_ngoodjets_branch) {ph_ngoodjets_branch->SetAddress(&ph_ngoodjets_);}
	}
	ph_ngoodbtags_branch = 0;
	if (tree->GetBranch("ph_ngoodbtags") != 0) {
		ph_ngoodbtags_branch = tree->GetBranch("ph_ngoodbtags");
		if (ph_ngoodbtags_branch) {ph_ngoodbtags_branch->SetAddress(&ph_ngoodbtags_);}
	}
	filt_met_branch = 0;
	if (tree->GetBranch("filt_met") != 0) {
		filt_met_branch = tree->GetBranch("filt_met");
		if (filt_met_branch) {filt_met_branch->SetAddress(&filt_met_);}
	}
	filt_badMuonFilter_branch = 0;
	if (tree->GetBranch("filt_badMuonFilter") != 0) {
		filt_badMuonFilter_branch = tree->GetBranch("filt_badMuonFilter");
		if (filt_badMuonFilter_branch) {filt_badMuonFilter_branch->SetAddress(&filt_badMuonFilter_);}
	}
	filt_badChargedCandidateFilter_branch = 0;
	if (tree->GetBranch("filt_badChargedCandidateFilter") != 0) {
		filt_badChargedCandidateFilter_branch = tree->GetBranch("filt_badChargedCandidateFilter");
		if (filt_badChargedCandidateFilter_branch) {filt_badChargedCandidateFilter_branch->SetAddress(&filt_badChargedCandidateFilter_);}
	}
	filt_cscbeamhalo2015_branch = 0;
	if (tree->GetBranch("filt_cscbeamhalo2015") != 0) {
		filt_cscbeamhalo2015_branch = tree->GetBranch("filt_cscbeamhalo2015");
		if (filt_cscbeamhalo2015_branch) {filt_cscbeamhalo2015_branch->SetAddress(&filt_cscbeamhalo2015_);}
	}
	filt_cscbeamhalo_branch = 0;
	if (tree->GetBranch("filt_cscbeamhalo") != 0) {
		filt_cscbeamhalo_branch = tree->GetBranch("filt_cscbeamhalo");
		if (filt_cscbeamhalo_branch) {filt_cscbeamhalo_branch->SetAddress(&filt_cscbeamhalo_);}
	}
	hardgenpt_branch = 0;
	if (tree->GetBranch("hardgenpt") != 0) {
		hardgenpt_branch = tree->GetBranch("hardgenpt");
		if (hardgenpt_branch) {hardgenpt_branch->SetAddress(&hardgenpt_);}
	}
	lep1_pdgid_branch = 0;
	if (tree->GetBranch("lep1_pdgid") != 0) {
		lep1_pdgid_branch = tree->GetBranch("lep1_pdgid");
		if (lep1_pdgid_branch) {lep1_pdgid_branch->SetAddress(&lep1_pdgid_);}
	}
	lep1_production_type_branch = 0;
	if (tree->GetBranch("lep1_production_type") != 0) {
		lep1_production_type_branch = tree->GetBranch("lep1_production_type");
		if (lep1_production_type_branch) {lep1_production_type_branch->SetAddress(&lep1_production_type_);}
	}
	lep1_MiniIso_branch = 0;
	if (tree->GetBranch("lep1_MiniIso") != 0) {
		lep1_MiniIso_branch = tree->GetBranch("lep1_MiniIso");
		if (lep1_MiniIso_branch) {lep1_MiniIso_branch->SetAddress(&lep1_MiniIso_);}
	}
	lep1_relIso_branch = 0;
	if (tree->GetBranch("lep1_relIso") != 0) {
		lep1_relIso_branch = tree->GetBranch("lep1_relIso");
		if (lep1_relIso_branch) {lep1_relIso_branch->SetAddress(&lep1_relIso_);}
	}
	lep1_passLooseID_branch = 0;
	if (tree->GetBranch("lep1_passLooseID") != 0) {
		lep1_passLooseID_branch = tree->GetBranch("lep1_passLooseID");
		if (lep1_passLooseID_branch) {lep1_passLooseID_branch->SetAddress(&lep1_passLooseID_);}
	}
	lep1_passMediumID_branch = 0;
	if (tree->GetBranch("lep1_passMediumID") != 0) {
		lep1_passMediumID_branch = tree->GetBranch("lep1_passMediumID");
		if (lep1_passMediumID_branch) {lep1_passMediumID_branch->SetAddress(&lep1_passMediumID_);}
	}
	lep1_passTightID_branch = 0;
	if (tree->GetBranch("lep1_passTightID") != 0) {
		lep1_passTightID_branch = tree->GetBranch("lep1_passTightID");
		if (lep1_passTightID_branch) {lep1_passTightID_branch->SetAddress(&lep1_passTightID_);}
	}
	lep1_passVeto_branch = 0;
	if (tree->GetBranch("lep1_passVeto") != 0) {
		lep1_passVeto_branch = tree->GetBranch("lep1_passVeto");
		if (lep1_passVeto_branch) {lep1_passVeto_branch->SetAddress(&lep1_passVeto_);}
	}
	lep1_mc_motherid_branch = 0;
	if (tree->GetBranch("lep1_mc_motherid") != 0) {
		lep1_mc_motherid_branch = tree->GetBranch("lep1_mc_motherid");
		if (lep1_mc_motherid_branch) {lep1_mc_motherid_branch->SetAddress(&lep1_mc_motherid_);}
	}
	lep2_pdgid_branch = 0;
	if (tree->GetBranch("lep2_pdgid") != 0) {
		lep2_pdgid_branch = tree->GetBranch("lep2_pdgid");
		if (lep2_pdgid_branch) {lep2_pdgid_branch->SetAddress(&lep2_pdgid_);}
	}
	lep2_production_type_branch = 0;
	if (tree->GetBranch("lep2_production_type") != 0) {
		lep2_production_type_branch = tree->GetBranch("lep2_production_type");
		if (lep2_production_type_branch) {lep2_production_type_branch->SetAddress(&lep2_production_type_);}
	}
	lep2_MiniIso_branch = 0;
	if (tree->GetBranch("lep2_MiniIso") != 0) {
		lep2_MiniIso_branch = tree->GetBranch("lep2_MiniIso");
		if (lep2_MiniIso_branch) {lep2_MiniIso_branch->SetAddress(&lep2_MiniIso_);}
	}
	lep2_relIso_branch = 0;
	if (tree->GetBranch("lep2_relIso") != 0) {
		lep2_relIso_branch = tree->GetBranch("lep2_relIso");
		if (lep2_relIso_branch) {lep2_relIso_branch->SetAddress(&lep2_relIso_);}
	}
	lep2_passLooseID_branch = 0;
	if (tree->GetBranch("lep2_passLooseID") != 0) {
		lep2_passLooseID_branch = tree->GetBranch("lep2_passLooseID");
		if (lep2_passLooseID_branch) {lep2_passLooseID_branch->SetAddress(&lep2_passLooseID_);}
	}
	lep2_passMediumID_branch = 0;
	if (tree->GetBranch("lep2_passMediumID") != 0) {
		lep2_passMediumID_branch = tree->GetBranch("lep2_passMediumID");
		if (lep2_passMediumID_branch) {lep2_passMediumID_branch->SetAddress(&lep2_passMediumID_);}
	}
	lep2_passTightID_branch = 0;
	if (tree->GetBranch("lep2_passTightID") != 0) {
		lep2_passTightID_branch = tree->GetBranch("lep2_passTightID");
		if (lep2_passTightID_branch) {lep2_passTightID_branch->SetAddress(&lep2_passTightID_);}
	}
	lep2_passVeto_branch = 0;
	if (tree->GetBranch("lep2_passVeto") != 0) {
		lep2_passVeto_branch = tree->GetBranch("lep2_passVeto");
		if (lep2_passVeto_branch) {lep2_passVeto_branch->SetAddress(&lep2_passVeto_);}
	}
	lep2_mc_motherid_branch = 0;
	if (tree->GetBranch("lep2_mc_motherid") != 0) {
		lep2_mc_motherid_branch = tree->GetBranch("lep2_mc_motherid");
		if (lep2_mc_motherid_branch) {lep2_mc_motherid_branch->SetAddress(&lep2_mc_motherid_);}
	}
	ph_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("ph_sigmaIEtaEta_fill5x5") != 0) {
		ph_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("ph_sigmaIEtaEta_fill5x5");
		if (ph_sigmaIEtaEta_fill5x5_branch) {ph_sigmaIEtaEta_fill5x5_branch->SetAddress(&ph_sigmaIEtaEta_fill5x5_);}
	}
	ph_hOverE_branch = 0;
	if (tree->GetBranch("ph_hOverE") != 0) {
		ph_hOverE_branch = tree->GetBranch("ph_hOverE");
		if (ph_hOverE_branch) {ph_hOverE_branch->SetAddress(&ph_hOverE_);}
	}
	ph_r9_branch = 0;
	if (tree->GetBranch("ph_r9") != 0) {
		ph_r9_branch = tree->GetBranch("ph_r9");
		if (ph_r9_branch) {ph_r9_branch->SetAddress(&ph_r9_);}
	}
	ph_chiso_branch = 0;
	if (tree->GetBranch("ph_chiso") != 0) {
		ph_chiso_branch = tree->GetBranch("ph_chiso");
		if (ph_chiso_branch) {ph_chiso_branch->SetAddress(&ph_chiso_);}
	}
	ph_nhiso_branch = 0;
	if (tree->GetBranch("ph_nhiso") != 0) {
		ph_nhiso_branch = tree->GetBranch("ph_nhiso");
		if (ph_nhiso_branch) {ph_nhiso_branch->SetAddress(&ph_nhiso_);}
	}
	ph_phiso_branch = 0;
	if (tree->GetBranch("ph_phiso") != 0) {
		ph_phiso_branch = tree->GetBranch("ph_phiso");
		if (ph_phiso_branch) {ph_phiso_branch->SetAddress(&ph_phiso_);}
	}
	ph_idCutBased_branch = 0;
	if (tree->GetBranch("ph_idCutBased") != 0) {
		ph_idCutBased_branch = tree->GetBranch("ph_idCutBased");
		if (ph_idCutBased_branch) {ph_idCutBased_branch->SetAddress(&ph_idCutBased_);}
	}
	ph_overlapJetId_branch = 0;
	if (tree->GetBranch("ph_overlapJetId") != 0) {
		ph_overlapJetId_branch = tree->GetBranch("ph_overlapJetId");
		if (ph_overlapJetId_branch) {ph_overlapJetId_branch->SetAddress(&ph_overlapJetId_);}
	}
	ph_pt_branch = 0;
	if (tree->GetBranch("ph_pt") != 0) {
		ph_pt_branch = tree->GetBranch("ph_pt");
		if (ph_pt_branch) {ph_pt_branch->SetAddress(&ph_pt_);}
	}
	ph_eta_branch = 0;
	if (tree->GetBranch("ph_eta") != 0) {
		ph_eta_branch = tree->GetBranch("ph_eta");
		if (ph_eta_branch) {ph_eta_branch->SetAddress(&ph_eta_);}
	}
	ph_phi_branch = 0;
	if (tree->GetBranch("ph_phi") != 0) {
		ph_phi_branch = tree->GetBranch("ph_phi");
		if (ph_phi_branch) {ph_phi_branch->SetAddress(&ph_phi_);}
	}
	ph_mass_branch = 0;
	if (tree->GetBranch("ph_mass") != 0) {
		ph_mass_branch = tree->GetBranch("ph_mass");
		if (ph_mass_branch) {ph_mass_branch->SetAddress(&ph_mass_);}
	}
	ph_mcMatchId_branch = 0;
	if (tree->GetBranch("ph_mcMatchId") != 0) {
		ph_mcMatchId_branch = tree->GetBranch("ph_mcMatchId");
		if (ph_mcMatchId_branch) {ph_mcMatchId_branch->SetAddress(&ph_mcMatchId_);}
	}
	ph_genIso04_branch = 0;
	if (tree->GetBranch("ph_genIso04") != 0) {
		ph_genIso04_branch = tree->GetBranch("ph_genIso04");
		if (ph_genIso04_branch) {ph_genIso04_branch->SetAddress(&ph_genIso04_);}
	}
	ph_drMinParton_branch = 0;
	if (tree->GetBranch("ph_drMinParton") != 0) {
		ph_drMinParton_branch = tree->GetBranch("ph_drMinParton");
		if (ph_drMinParton_branch) {ph_drMinParton_branch->SetAddress(&ph_drMinParton_);}
	}
	ngoodjets_branch = 0;
	if (tree->GetBranch("ngoodjets") != 0) {
		ngoodjets_branch = tree->GetBranch("ngoodjets");
		if (ngoodjets_branch) {ngoodjets_branch->SetAddress(&ngoodjets_);}
	}
	ngoodbtags_branch = 0;
	if (tree->GetBranch("ngoodbtags") != 0) {
		ngoodbtags_branch = tree->GetBranch("ngoodbtags");
		if (ngoodbtags_branch) {ngoodbtags_branch->SetAddress(&ngoodbtags_);}
	}
	ak4_HT_branch = 0;
	if (tree->GetBranch("ak4_HT") != 0) {
		ak4_HT_branch = tree->GetBranch("ak4_HT");
		if (ak4_HT_branch) {ak4_HT_branch->SetAddress(&ak4_HT_);}
	}
	ak4_htratiom_branch = 0;
	if (tree->GetBranch("ak4_htratiom") != 0) {
		ak4_htratiom_branch = tree->GetBranch("ak4_htratiom");
		if (ak4_htratiom_branch) {ak4_htratiom_branch->SetAddress(&ak4_htratiom_);}
	}
	dphi_ak4pfjet_met_branch = 0;
	if (tree->GetBranch("dphi_ak4pfjet_met") != 0) {
		dphi_ak4pfjet_met_branch = tree->GetBranch("dphi_ak4pfjet_met");
		if (dphi_ak4pfjet_met_branch) {dphi_ak4pfjet_met_branch->SetAddress(&dphi_ak4pfjet_met_);}
	}
	ak4pfjets_passMEDbtag_branch = 0;
	if (tree->GetBranch("ak4pfjets_passMEDbtag") != 0) {
		ak4pfjets_passMEDbtag_branch = tree->GetBranch("ak4pfjets_passMEDbtag");
		if (ak4pfjets_passMEDbtag_branch) {ak4pfjets_passMEDbtag_branch->SetAddress(&ak4pfjets_passMEDbtag_);}
	}
	ak4pfjets_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjets_CSV") != 0) {
		ak4pfjets_CSV_branch = tree->GetBranch("ak4pfjets_CSV");
		if (ak4pfjets_CSV_branch) {ak4pfjets_CSV_branch->SetAddress(&ak4pfjets_CSV_);}
	}
	ak4pfjets_mva_branch = 0;
	if (tree->GetBranch("ak4pfjets_mva") != 0) {
		ak4pfjets_mva_branch = tree->GetBranch("ak4pfjets_mva");
		if (ak4pfjets_mva_branch) {ak4pfjets_mva_branch->SetAddress(&ak4pfjets_mva_);}
	}
	ak4pfjets_parton_flavor_branch = 0;
	if (tree->GetBranch("ak4pfjets_parton_flavor") != 0) {
		ak4pfjets_parton_flavor_branch = tree->GetBranch("ak4pfjets_parton_flavor");
		if (ak4pfjets_parton_flavor_branch) {ak4pfjets_parton_flavor_branch->SetAddress(&ak4pfjets_parton_flavor_);}
	}
	ak4pfjets_hadron_flavor_branch = 0;
	if (tree->GetBranch("ak4pfjets_hadron_flavor") != 0) {
		ak4pfjets_hadron_flavor_branch = tree->GetBranch("ak4pfjets_hadron_flavor");
		if (ak4pfjets_hadron_flavor_branch) {ak4pfjets_hadron_flavor_branch->SetAddress(&ak4pfjets_hadron_flavor_);}
	}
	ak4pfjets_loose_puid_branch = 0;
	if (tree->GetBranch("ak4pfjets_loose_puid") != 0) {
		ak4pfjets_loose_puid_branch = tree->GetBranch("ak4pfjets_loose_puid");
		if (ak4pfjets_loose_puid_branch) {ak4pfjets_loose_puid_branch->SetAddress(&ak4pfjets_loose_puid_);}
	}
	ak4pfjets_loose_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_loose_pfid") != 0) {
		ak4pfjets_loose_pfid_branch = tree->GetBranch("ak4pfjets_loose_pfid");
		if (ak4pfjets_loose_pfid_branch) {ak4pfjets_loose_pfid_branch->SetAddress(&ak4pfjets_loose_pfid_);}
	}
	genleps_isfromt_branch = 0;
	if (tree->GetBranch("genleps_isfromt") != 0) {
		genleps_isfromt_branch = tree->GetBranch("genleps_isfromt");
		if (genleps_isfromt_branch) {genleps_isfromt_branch->SetAddress(&genleps_isfromt_);}
	}
	genleps_id_branch = 0;
	if (tree->GetBranch("genleps_id") != 0) {
		genleps_id_branch = tree->GetBranch("genleps_id");
		if (genleps_id_branch) {genleps_id_branch->SetAddress(&genleps_id_);}
	}
	genleps__genpsidx_branch = 0;
	if (tree->GetBranch("genleps__genpsidx") != 0) {
		genleps__genpsidx_branch = tree->GetBranch("genleps__genpsidx");
		if (genleps__genpsidx_branch) {genleps__genpsidx_branch->SetAddress(&genleps__genpsidx_);}
	}
	genleps_status_branch = 0;
	if (tree->GetBranch("genleps_status") != 0) {
		genleps_status_branch = tree->GetBranch("genleps_status");
		if (genleps_status_branch) {genleps_status_branch->SetAddress(&genleps_status_);}
	}
	genleps_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genleps_fromHardProcessDecayed") != 0) {
		genleps_fromHardProcessDecayed_branch = tree->GetBranch("genleps_fromHardProcessDecayed");
		if (genleps_fromHardProcessDecayed_branch) {genleps_fromHardProcessDecayed_branch->SetAddress(&genleps_fromHardProcessDecayed_);}
	}
	genleps_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genleps_fromHardProcessFinalState") != 0) {
		genleps_fromHardProcessFinalState_branch = tree->GetBranch("genleps_fromHardProcessFinalState");
		if (genleps_fromHardProcessFinalState_branch) {genleps_fromHardProcessFinalState_branch->SetAddress(&genleps_fromHardProcessFinalState_);}
	}
	genleps_isHardProcess_branch = 0;
	if (tree->GetBranch("genleps_isHardProcess") != 0) {
		genleps_isHardProcess_branch = tree->GetBranch("genleps_isHardProcess");
		if (genleps_isHardProcess_branch) {genleps_isHardProcess_branch->SetAddress(&genleps_isHardProcess_);}
	}
	genleps_isLastCopy_branch = 0;
	if (tree->GetBranch("genleps_isLastCopy") != 0) {
		genleps_isLastCopy_branch = tree->GetBranch("genleps_isLastCopy");
		if (genleps_isLastCopy_branch) {genleps_isLastCopy_branch->SetAddress(&genleps_isLastCopy_);}
	}
	genleps_gentaudecay_branch = 0;
	if (tree->GetBranch("genleps_gentaudecay") != 0) {
		genleps_gentaudecay_branch = tree->GetBranch("genleps_gentaudecay");
		if (genleps_gentaudecay_branch) {genleps_gentaudecay_branch->SetAddress(&genleps_gentaudecay_);}
	}
	gen_nfromtleps__branch = 0;
	if (tree->GetBranch("gen_nfromtleps_") != 0) {
		gen_nfromtleps__branch = tree->GetBranch("gen_nfromtleps_");
		if (gen_nfromtleps__branch) {gen_nfromtleps__branch->SetAddress(&gen_nfromtleps__);}
	}
	genleps_motherid_branch = 0;
	if (tree->GetBranch("genleps_motherid") != 0) {
		genleps_motherid_branch = tree->GetBranch("genleps_motherid");
		if (genleps_motherid_branch) {genleps_motherid_branch->SetAddress(&genleps_motherid_);}
	}
	genleps_motheridx_branch = 0;
	if (tree->GetBranch("genleps_motheridx") != 0) {
		genleps_motheridx_branch = tree->GetBranch("genleps_motheridx");
		if (genleps_motheridx_branch) {genleps_motheridx_branch->SetAddress(&genleps_motheridx_);}
	}
	genleps_motherstatus_branch = 0;
	if (tree->GetBranch("genleps_motherstatus") != 0) {
		genleps_motherstatus_branch = tree->GetBranch("genleps_motherstatus");
		if (genleps_motherstatus_branch) {genleps_motherstatus_branch->SetAddress(&genleps_motherstatus_);}
	}
	genleps_gmotherid_branch = 0;
	if (tree->GetBranch("genleps_gmotherid") != 0) {
		genleps_gmotherid_branch = tree->GetBranch("genleps_gmotherid");
		if (genleps_gmotherid_branch) {genleps_gmotherid_branch->SetAddress(&genleps_gmotherid_);}
	}
	genleps_gmotheridx_branch = 0;
	if (tree->GetBranch("genleps_gmotheridx") != 0) {
		genleps_gmotheridx_branch = tree->GetBranch("genleps_gmotheridx");
		if (genleps_gmotheridx_branch) {genleps_gmotheridx_branch->SetAddress(&genleps_gmotheridx_);}
	}
	genleps_gmotherstatus_branch = 0;
	if (tree->GetBranch("genleps_gmotherstatus") != 0) {
		genleps_gmotherstatus_branch = tree->GetBranch("genleps_gmotherstatus");
		if (genleps_gmotherstatus_branch) {genleps_gmotherstatus_branch->SetAddress(&genleps_gmotherstatus_);}
	}
	gennus_isfromt_branch = 0;
	if (tree->GetBranch("gennus_isfromt") != 0) {
		gennus_isfromt_branch = tree->GetBranch("gennus_isfromt");
		if (gennus_isfromt_branch) {gennus_isfromt_branch->SetAddress(&gennus_isfromt_);}
	}
	gennus_id_branch = 0;
	if (tree->GetBranch("gennus_id") != 0) {
		gennus_id_branch = tree->GetBranch("gennus_id");
		if (gennus_id_branch) {gennus_id_branch->SetAddress(&gennus_id_);}
	}
	gennus__genpsidx_branch = 0;
	if (tree->GetBranch("gennus__genpsidx") != 0) {
		gennus__genpsidx_branch = tree->GetBranch("gennus__genpsidx");
		if (gennus__genpsidx_branch) {gennus__genpsidx_branch->SetAddress(&gennus__genpsidx_);}
	}
	gennus_status_branch = 0;
	if (tree->GetBranch("gennus_status") != 0) {
		gennus_status_branch = tree->GetBranch("gennus_status");
		if (gennus_status_branch) {gennus_status_branch->SetAddress(&gennus_status_);}
	}
	gennus_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gennus_fromHardProcessDecayed") != 0) {
		gennus_fromHardProcessDecayed_branch = tree->GetBranch("gennus_fromHardProcessDecayed");
		if (gennus_fromHardProcessDecayed_branch) {gennus_fromHardProcessDecayed_branch->SetAddress(&gennus_fromHardProcessDecayed_);}
	}
	gennus_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gennus_fromHardProcessFinalState") != 0) {
		gennus_fromHardProcessFinalState_branch = tree->GetBranch("gennus_fromHardProcessFinalState");
		if (gennus_fromHardProcessFinalState_branch) {gennus_fromHardProcessFinalState_branch->SetAddress(&gennus_fromHardProcessFinalState_);}
	}
	gennus_isHardProcess_branch = 0;
	if (tree->GetBranch("gennus_isHardProcess") != 0) {
		gennus_isHardProcess_branch = tree->GetBranch("gennus_isHardProcess");
		if (gennus_isHardProcess_branch) {gennus_isHardProcess_branch->SetAddress(&gennus_isHardProcess_);}
	}
	gennus_isLastCopy_branch = 0;
	if (tree->GetBranch("gennus_isLastCopy") != 0) {
		gennus_isLastCopy_branch = tree->GetBranch("gennus_isLastCopy");
		if (gennus_isLastCopy_branch) {gennus_isLastCopy_branch->SetAddress(&gennus_isLastCopy_);}
	}
	gennus_gentaudecay_branch = 0;
	if (tree->GetBranch("gennus_gentaudecay") != 0) {
		gennus_gentaudecay_branch = tree->GetBranch("gennus_gentaudecay");
		if (gennus_gentaudecay_branch) {gennus_gentaudecay_branch->SetAddress(&gennus_gentaudecay_);}
	}
	gen_nfromtnus__branch = 0;
	if (tree->GetBranch("gen_nfromtnus_") != 0) {
		gen_nfromtnus__branch = tree->GetBranch("gen_nfromtnus_");
		if (gen_nfromtnus__branch) {gen_nfromtnus__branch->SetAddress(&gen_nfromtnus__);}
	}
	gennus_motherid_branch = 0;
	if (tree->GetBranch("gennus_motherid") != 0) {
		gennus_motherid_branch = tree->GetBranch("gennus_motherid");
		if (gennus_motherid_branch) {gennus_motherid_branch->SetAddress(&gennus_motherid_);}
	}
	gennus_motheridx_branch = 0;
	if (tree->GetBranch("gennus_motheridx") != 0) {
		gennus_motheridx_branch = tree->GetBranch("gennus_motheridx");
		if (gennus_motheridx_branch) {gennus_motheridx_branch->SetAddress(&gennus_motheridx_);}
	}
	gennus_motherstatus_branch = 0;
	if (tree->GetBranch("gennus_motherstatus") != 0) {
		gennus_motherstatus_branch = tree->GetBranch("gennus_motherstatus");
		if (gennus_motherstatus_branch) {gennus_motherstatus_branch->SetAddress(&gennus_motherstatus_);}
	}
	gennus_gmotherid_branch = 0;
	if (tree->GetBranch("gennus_gmotherid") != 0) {
		gennus_gmotherid_branch = tree->GetBranch("gennus_gmotherid");
		if (gennus_gmotherid_branch) {gennus_gmotherid_branch->SetAddress(&gennus_gmotherid_);}
	}
	gennus_gmotheridx_branch = 0;
	if (tree->GetBranch("gennus_gmotheridx") != 0) {
		gennus_gmotheridx_branch = tree->GetBranch("gennus_gmotheridx");
		if (gennus_gmotheridx_branch) {gennus_gmotheridx_branch->SetAddress(&gennus_gmotheridx_);}
	}
	gennus_gmotherstatus_branch = 0;
	if (tree->GetBranch("gennus_gmotherstatus") != 0) {
		gennus_gmotherstatus_branch = tree->GetBranch("gennus_gmotherstatus");
		if (gennus_gmotherstatus_branch) {gennus_gmotherstatus_branch->SetAddress(&gennus_gmotherstatus_);}
	}
	genqs_isfromt_branch = 0;
	if (tree->GetBranch("genqs_isfromt") != 0) {
		genqs_isfromt_branch = tree->GetBranch("genqs_isfromt");
		if (genqs_isfromt_branch) {genqs_isfromt_branch->SetAddress(&genqs_isfromt_);}
	}
	genqs_id_branch = 0;
	if (tree->GetBranch("genqs_id") != 0) {
		genqs_id_branch = tree->GetBranch("genqs_id");
		if (genqs_id_branch) {genqs_id_branch->SetAddress(&genqs_id_);}
	}
	genqs__genpsidx_branch = 0;
	if (tree->GetBranch("genqs__genpsidx") != 0) {
		genqs__genpsidx_branch = tree->GetBranch("genqs__genpsidx");
		if (genqs__genpsidx_branch) {genqs__genpsidx_branch->SetAddress(&genqs__genpsidx_);}
	}
	genqs_status_branch = 0;
	if (tree->GetBranch("genqs_status") != 0) {
		genqs_status_branch = tree->GetBranch("genqs_status");
		if (genqs_status_branch) {genqs_status_branch->SetAddress(&genqs_status_);}
	}
	genqs_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genqs_fromHardProcessDecayed") != 0) {
		genqs_fromHardProcessDecayed_branch = tree->GetBranch("genqs_fromHardProcessDecayed");
		if (genqs_fromHardProcessDecayed_branch) {genqs_fromHardProcessDecayed_branch->SetAddress(&genqs_fromHardProcessDecayed_);}
	}
	genqs_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genqs_fromHardProcessFinalState") != 0) {
		genqs_fromHardProcessFinalState_branch = tree->GetBranch("genqs_fromHardProcessFinalState");
		if (genqs_fromHardProcessFinalState_branch) {genqs_fromHardProcessFinalState_branch->SetAddress(&genqs_fromHardProcessFinalState_);}
	}
	genqs_isHardProcess_branch = 0;
	if (tree->GetBranch("genqs_isHardProcess") != 0) {
		genqs_isHardProcess_branch = tree->GetBranch("genqs_isHardProcess");
		if (genqs_isHardProcess_branch) {genqs_isHardProcess_branch->SetAddress(&genqs_isHardProcess_);}
	}
	genqs_isLastCopy_branch = 0;
	if (tree->GetBranch("genqs_isLastCopy") != 0) {
		genqs_isLastCopy_branch = tree->GetBranch("genqs_isLastCopy");
		if (genqs_isLastCopy_branch) {genqs_isLastCopy_branch->SetAddress(&genqs_isLastCopy_);}
	}
	genqs_gentaudecay_branch = 0;
	if (tree->GetBranch("genqs_gentaudecay") != 0) {
		genqs_gentaudecay_branch = tree->GetBranch("genqs_gentaudecay");
		if (genqs_gentaudecay_branch) {genqs_gentaudecay_branch->SetAddress(&genqs_gentaudecay_);}
	}
	gen_nfromtqs__branch = 0;
	if (tree->GetBranch("gen_nfromtqs_") != 0) {
		gen_nfromtqs__branch = tree->GetBranch("gen_nfromtqs_");
		if (gen_nfromtqs__branch) {gen_nfromtqs__branch->SetAddress(&gen_nfromtqs__);}
	}
	genqs_motherid_branch = 0;
	if (tree->GetBranch("genqs_motherid") != 0) {
		genqs_motherid_branch = tree->GetBranch("genqs_motherid");
		if (genqs_motherid_branch) {genqs_motherid_branch->SetAddress(&genqs_motherid_);}
	}
	genqs_motheridx_branch = 0;
	if (tree->GetBranch("genqs_motheridx") != 0) {
		genqs_motheridx_branch = tree->GetBranch("genqs_motheridx");
		if (genqs_motheridx_branch) {genqs_motheridx_branch->SetAddress(&genqs_motheridx_);}
	}
	genqs_motherstatus_branch = 0;
	if (tree->GetBranch("genqs_motherstatus") != 0) {
		genqs_motherstatus_branch = tree->GetBranch("genqs_motherstatus");
		if (genqs_motherstatus_branch) {genqs_motherstatus_branch->SetAddress(&genqs_motherstatus_);}
	}
	genqs_gmotherid_branch = 0;
	if (tree->GetBranch("genqs_gmotherid") != 0) {
		genqs_gmotherid_branch = tree->GetBranch("genqs_gmotherid");
		if (genqs_gmotherid_branch) {genqs_gmotherid_branch->SetAddress(&genqs_gmotherid_);}
	}
	genqs_gmotheridx_branch = 0;
	if (tree->GetBranch("genqs_gmotheridx") != 0) {
		genqs_gmotheridx_branch = tree->GetBranch("genqs_gmotheridx");
		if (genqs_gmotheridx_branch) {genqs_gmotheridx_branch->SetAddress(&genqs_gmotheridx_);}
	}
	genqs_gmotherstatus_branch = 0;
	if (tree->GetBranch("genqs_gmotherstatus") != 0) {
		genqs_gmotherstatus_branch = tree->GetBranch("genqs_gmotherstatus");
		if (genqs_gmotherstatus_branch) {genqs_gmotherstatus_branch->SetAddress(&genqs_gmotherstatus_);}
	}
	genbosons_isfromt_branch = 0;
	if (tree->GetBranch("genbosons_isfromt") != 0) {
		genbosons_isfromt_branch = tree->GetBranch("genbosons_isfromt");
		if (genbosons_isfromt_branch) {genbosons_isfromt_branch->SetAddress(&genbosons_isfromt_);}
	}
	genbosons_id_branch = 0;
	if (tree->GetBranch("genbosons_id") != 0) {
		genbosons_id_branch = tree->GetBranch("genbosons_id");
		if (genbosons_id_branch) {genbosons_id_branch->SetAddress(&genbosons_id_);}
	}
	genbosons__genpsidx_branch = 0;
	if (tree->GetBranch("genbosons__genpsidx") != 0) {
		genbosons__genpsidx_branch = tree->GetBranch("genbosons__genpsidx");
		if (genbosons__genpsidx_branch) {genbosons__genpsidx_branch->SetAddress(&genbosons__genpsidx_);}
	}
	genbosons_status_branch = 0;
	if (tree->GetBranch("genbosons_status") != 0) {
		genbosons_status_branch = tree->GetBranch("genbosons_status");
		if (genbosons_status_branch) {genbosons_status_branch->SetAddress(&genbosons_status_);}
	}
	genbosons_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("genbosons_fromHardProcessDecayed") != 0) {
		genbosons_fromHardProcessDecayed_branch = tree->GetBranch("genbosons_fromHardProcessDecayed");
		if (genbosons_fromHardProcessDecayed_branch) {genbosons_fromHardProcessDecayed_branch->SetAddress(&genbosons_fromHardProcessDecayed_);}
	}
	genbosons_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("genbosons_fromHardProcessFinalState") != 0) {
		genbosons_fromHardProcessFinalState_branch = tree->GetBranch("genbosons_fromHardProcessFinalState");
		if (genbosons_fromHardProcessFinalState_branch) {genbosons_fromHardProcessFinalState_branch->SetAddress(&genbosons_fromHardProcessFinalState_);}
	}
	genbosons_isHardProcess_branch = 0;
	if (tree->GetBranch("genbosons_isHardProcess") != 0) {
		genbosons_isHardProcess_branch = tree->GetBranch("genbosons_isHardProcess");
		if (genbosons_isHardProcess_branch) {genbosons_isHardProcess_branch->SetAddress(&genbosons_isHardProcess_);}
	}
	genbosons_isLastCopy_branch = 0;
	if (tree->GetBranch("genbosons_isLastCopy") != 0) {
		genbosons_isLastCopy_branch = tree->GetBranch("genbosons_isLastCopy");
		if (genbosons_isLastCopy_branch) {genbosons_isLastCopy_branch->SetAddress(&genbosons_isLastCopy_);}
	}
	genbosons_gentaudecay_branch = 0;
	if (tree->GetBranch("genbosons_gentaudecay") != 0) {
		genbosons_gentaudecay_branch = tree->GetBranch("genbosons_gentaudecay");
		if (genbosons_gentaudecay_branch) {genbosons_gentaudecay_branch->SetAddress(&genbosons_gentaudecay_);}
	}
	gen_nfromtbosons__branch = 0;
	if (tree->GetBranch("gen_nfromtbosons_") != 0) {
		gen_nfromtbosons__branch = tree->GetBranch("gen_nfromtbosons_");
		if (gen_nfromtbosons__branch) {gen_nfromtbosons__branch->SetAddress(&gen_nfromtbosons__);}
	}
	genbosons_motherid_branch = 0;
	if (tree->GetBranch("genbosons_motherid") != 0) {
		genbosons_motherid_branch = tree->GetBranch("genbosons_motherid");
		if (genbosons_motherid_branch) {genbosons_motherid_branch->SetAddress(&genbosons_motherid_);}
	}
	genbosons_motheridx_branch = 0;
	if (tree->GetBranch("genbosons_motheridx") != 0) {
		genbosons_motheridx_branch = tree->GetBranch("genbosons_motheridx");
		if (genbosons_motheridx_branch) {genbosons_motheridx_branch->SetAddress(&genbosons_motheridx_);}
	}
	genbosons_motherstatus_branch = 0;
	if (tree->GetBranch("genbosons_motherstatus") != 0) {
		genbosons_motherstatus_branch = tree->GetBranch("genbosons_motherstatus");
		if (genbosons_motherstatus_branch) {genbosons_motherstatus_branch->SetAddress(&genbosons_motherstatus_);}
	}
	genbosons_gmotherid_branch = 0;
	if (tree->GetBranch("genbosons_gmotherid") != 0) {
		genbosons_gmotherid_branch = tree->GetBranch("genbosons_gmotherid");
		if (genbosons_gmotherid_branch) {genbosons_gmotherid_branch->SetAddress(&genbosons_gmotherid_);}
	}
	genbosons_gmotheridx_branch = 0;
	if (tree->GetBranch("genbosons_gmotheridx") != 0) {
		genbosons_gmotheridx_branch = tree->GetBranch("genbosons_gmotheridx");
		if (genbosons_gmotheridx_branch) {genbosons_gmotheridx_branch->SetAddress(&genbosons_gmotheridx_);}
	}
	genbosons_gmotherstatus_branch = 0;
	if (tree->GetBranch("genbosons_gmotherstatus") != 0) {
		genbosons_gmotherstatus_branch = tree->GetBranch("genbosons_gmotherstatus");
		if (genbosons_gmotherstatus_branch) {genbosons_gmotherstatus_branch->SetAddress(&genbosons_gmotherstatus_);}
	}
	gensusy_isfromt_branch = 0;
	if (tree->GetBranch("gensusy_isfromt") != 0) {
		gensusy_isfromt_branch = tree->GetBranch("gensusy_isfromt");
		if (gensusy_isfromt_branch) {gensusy_isfromt_branch->SetAddress(&gensusy_isfromt_);}
	}
	gensusy_id_branch = 0;
	if (tree->GetBranch("gensusy_id") != 0) {
		gensusy_id_branch = tree->GetBranch("gensusy_id");
		if (gensusy_id_branch) {gensusy_id_branch->SetAddress(&gensusy_id_);}
	}
	gensusy__genpsidx_branch = 0;
	if (tree->GetBranch("gensusy__genpsidx") != 0) {
		gensusy__genpsidx_branch = tree->GetBranch("gensusy__genpsidx");
		if (gensusy__genpsidx_branch) {gensusy__genpsidx_branch->SetAddress(&gensusy__genpsidx_);}
	}
	gensusy_status_branch = 0;
	if (tree->GetBranch("gensusy_status") != 0) {
		gensusy_status_branch = tree->GetBranch("gensusy_status");
		if (gensusy_status_branch) {gensusy_status_branch->SetAddress(&gensusy_status_);}
	}
	gensusy_fromHardProcessDecayed_branch = 0;
	if (tree->GetBranch("gensusy_fromHardProcessDecayed") != 0) {
		gensusy_fromHardProcessDecayed_branch = tree->GetBranch("gensusy_fromHardProcessDecayed");
		if (gensusy_fromHardProcessDecayed_branch) {gensusy_fromHardProcessDecayed_branch->SetAddress(&gensusy_fromHardProcessDecayed_);}
	}
	gensusy_fromHardProcessFinalState_branch = 0;
	if (tree->GetBranch("gensusy_fromHardProcessFinalState") != 0) {
		gensusy_fromHardProcessFinalState_branch = tree->GetBranch("gensusy_fromHardProcessFinalState");
		if (gensusy_fromHardProcessFinalState_branch) {gensusy_fromHardProcessFinalState_branch->SetAddress(&gensusy_fromHardProcessFinalState_);}
	}
	gensusy_isHardProcess_branch = 0;
	if (tree->GetBranch("gensusy_isHardProcess") != 0) {
		gensusy_isHardProcess_branch = tree->GetBranch("gensusy_isHardProcess");
		if (gensusy_isHardProcess_branch) {gensusy_isHardProcess_branch->SetAddress(&gensusy_isHardProcess_);}
	}
	gensusy_isLastCopy_branch = 0;
	if (tree->GetBranch("gensusy_isLastCopy") != 0) {
		gensusy_isLastCopy_branch = tree->GetBranch("gensusy_isLastCopy");
		if (gensusy_isLastCopy_branch) {gensusy_isLastCopy_branch->SetAddress(&gensusy_isLastCopy_);}
	}
	gensusy_gentaudecay_branch = 0;
	if (tree->GetBranch("gensusy_gentaudecay") != 0) {
		gensusy_gentaudecay_branch = tree->GetBranch("gensusy_gentaudecay");
		if (gensusy_gentaudecay_branch) {gensusy_gentaudecay_branch->SetAddress(&gensusy_gentaudecay_);}
	}
	gen_nfromtsusy__branch = 0;
	if (tree->GetBranch("gen_nfromtsusy_") != 0) {
		gen_nfromtsusy__branch = tree->GetBranch("gen_nfromtsusy_");
		if (gen_nfromtsusy__branch) {gen_nfromtsusy__branch->SetAddress(&gen_nfromtsusy__);}
	}
	gensusy_motherid_branch = 0;
	if (tree->GetBranch("gensusy_motherid") != 0) {
		gensusy_motherid_branch = tree->GetBranch("gensusy_motherid");
		if (gensusy_motherid_branch) {gensusy_motherid_branch->SetAddress(&gensusy_motherid_);}
	}
	gensusy_motheridx_branch = 0;
	if (tree->GetBranch("gensusy_motheridx") != 0) {
		gensusy_motheridx_branch = tree->GetBranch("gensusy_motheridx");
		if (gensusy_motheridx_branch) {gensusy_motheridx_branch->SetAddress(&gensusy_motheridx_);}
	}
	gensusy_motherstatus_branch = 0;
	if (tree->GetBranch("gensusy_motherstatus") != 0) {
		gensusy_motherstatus_branch = tree->GetBranch("gensusy_motherstatus");
		if (gensusy_motherstatus_branch) {gensusy_motherstatus_branch->SetAddress(&gensusy_motherstatus_);}
	}
	gensusy_gmotherid_branch = 0;
	if (tree->GetBranch("gensusy_gmotherid") != 0) {
		gensusy_gmotherid_branch = tree->GetBranch("gensusy_gmotherid");
		if (gensusy_gmotherid_branch) {gensusy_gmotherid_branch->SetAddress(&gensusy_gmotherid_);}
	}
	gensusy_gmotheridx_branch = 0;
	if (tree->GetBranch("gensusy_gmotheridx") != 0) {
		gensusy_gmotheridx_branch = tree->GetBranch("gensusy_gmotheridx");
		if (gensusy_gmotheridx_branch) {gensusy_gmotheridx_branch->SetAddress(&gensusy_gmotheridx_);}
	}
	gensusy_gmotherstatus_branch = 0;
	if (tree->GetBranch("gensusy_gmotherstatus") != 0) {
		gensusy_gmotherstatus_branch = tree->GetBranch("gensusy_gmotherstatus");
		if (gensusy_gmotherstatus_branch) {gensusy_gmotherstatus_branch->SetAddress(&gensusy_gmotherstatus_);}
	}
  tree->SetMakeClass(0);
}
void V80_00::GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		run_isLoaded = false;
		ls_isLoaded = false;
		evt_isLoaded = false;
		nvtxs_isLoaded = false;
		pu_nvtxs_isLoaded = false;
		pfmet_isLoaded = false;
		pfmet_phi_isLoaded = false;
		scale1fb_isLoaded = false;
		xsec_isLoaded = false;
		xsec_uncert_isLoaded = false;
		kfactor_isLoaded = false;
		pu_ntrue_isLoaded = false;
		ngoodleps_isLoaded = false;
		nvetoleps_isLoaded = false;
		is_data_isLoaded = false;
		dataset_isLoaded = false;
		filename_isLoaded = false;
		cms3tag_isLoaded = false;
		nEvents_isLoaded = false;
		nEvents_goodvtx_isLoaded = false;
		nEvents_MET30_isLoaded = false;
		nEvents_1goodlep_isLoaded = false;
		nEvents_2goodjets_isLoaded = false;
		is0lep_isLoaded = false;
		is1lep_isLoaded = false;
		is2lep_isLoaded = false;
		isZtoNuNu_isLoaded = false;
		is1lepFromW_isLoaded = false;
		is1lepFromTop_isLoaded = false;
		MT2W_isLoaded = false;
		mindphi_met_j1_j2_isLoaded = false;
		mt_met_lep_isLoaded = false;
		hadronic_top_chi2_isLoaded = false;
		ak4pfjets_rho_isLoaded = false;
		pdf_up_weight_isLoaded = false;
		pdf_down_weight_isLoaded = false;
		genweightsID_isLoaded = false;
		genweights_isLoaded = false;
		weight_btagsf_isLoaded = false;
		weight_btagsf_heavy_UP_isLoaded = false;
		weight_btagsf_light_UP_isLoaded = false;
		weight_btagsf_heavy_DN_isLoaded = false;
		weight_btagsf_light_DN_isLoaded = false;
		weight_btagsf_fastsim_UP_isLoaded = false;
		weight_btagsf_fastsim_DN_isLoaded = false;
		weight_lepSF_isLoaded = false;
		weight_lepSF_up_isLoaded = false;
		weight_lepSF_down_isLoaded = false;
		weight_vetoLepSF_isLoaded = false;
		weight_vetoLepSF_up_isLoaded = false;
		weight_vetoLepSF_down_isLoaded = false;
		weight_lepSF_fastSim_isLoaded = false;
		weight_lepSF_fastSim_up_isLoaded = false;
		weight_lepSF_fastSim_down_isLoaded = false;
		weight_ISR_isLoaded = false;
		weight_ISRup_isLoaded = false;
		weight_ISRdown_isLoaded = false;
		weight_PU_isLoaded = false;
		weight_PUup_isLoaded = false;
		weight_PUdown_isLoaded = false;
		sparms_names_isLoaded = false;
		sparms_values_isLoaded = false;
		sparms_subProcessId_isLoaded = false;
		mass_lsp_isLoaded = false;
		mass_chargino_isLoaded = false;
		mass_stop_isLoaded = false;
		mass_gluino_isLoaded = false;
		genmet_isLoaded = false;
		genmet_phi_isLoaded = false;
		genht_isLoaded = false;
		PassTrackVeto_isLoaded = false;
		PassTauVeto_isLoaded = false;
		topness_isLoaded = false;
		topnessMod_isLoaded = false;
		Mlb_closestb_isLoaded = false;
		HLT_SingleEl_isLoaded = false;
		HLT_SingleMu_isLoaded = false;
		HLT_SingleMuNoIso_isLoaded = false;
		HLT_SingleElNoIso_isLoaded = false;
		HLT_MET_isLoaded = false;
		HLT_DiEl_isLoaded = false;
		HLT_DiMu_isLoaded = false;
		HLT_MuE_isLoaded = false;
		HLT_Photon90_CaloIdL_PFHT500_isLoaded = false;
		HLT_Photon22_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon30_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon36_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon50_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon75_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon90_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon120_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon165_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon175_isLoaded = false;
		HLT_Photon165_HE10_isLoaded = false;
		nPhotons_isLoaded = false;
		ph_ngoodjets_isLoaded = false;
		ph_ngoodbtags_isLoaded = false;
		filt_met_isLoaded = false;
		filt_badMuonFilter_isLoaded = false;
		filt_badChargedCandidateFilter_isLoaded = false;
		filt_cscbeamhalo2015_isLoaded = false;
		filt_cscbeamhalo_isLoaded = false;
		hardgenpt_isLoaded = false;
		lep1_pdgid_isLoaded = false;
		lep1_production_type_isLoaded = false;
		lep1_MiniIso_isLoaded = false;
		lep1_relIso_isLoaded = false;
		lep1_passLooseID_isLoaded = false;
		lep1_passMediumID_isLoaded = false;
		lep1_passTightID_isLoaded = false;
		lep1_passVeto_isLoaded = false;
		lep1_p4_isLoaded = false;
		lep1_mcp4_isLoaded = false;
		lep1_mc_motherid_isLoaded = false;
		lep2_pdgid_isLoaded = false;
		lep2_production_type_isLoaded = false;
		lep2_MiniIso_isLoaded = false;
		lep2_relIso_isLoaded = false;
		lep2_passLooseID_isLoaded = false;
		lep2_passMediumID_isLoaded = false;
		lep2_passTightID_isLoaded = false;
		lep2_passVeto_isLoaded = false;
		lep2_p4_isLoaded = false;
		lep2_mcp4_isLoaded = false;
		lep2_mc_motherid_isLoaded = false;
		ph_sigmaIEtaEta_fill5x5_isLoaded = false;
		ph_hOverE_isLoaded = false;
		ph_r9_isLoaded = false;
		ph_chiso_isLoaded = false;
		ph_nhiso_isLoaded = false;
		ph_phiso_isLoaded = false;
		ph_idCutBased_isLoaded = false;
		ph_overlapJetId_isLoaded = false;
		ph_p4_isLoaded = false;
		ph_mcp4_isLoaded = false;
		ph_pt_isLoaded = false;
		ph_eta_isLoaded = false;
		ph_phi_isLoaded = false;
		ph_mass_isLoaded = false;
		ph_mcMatchId_isLoaded = false;
		ph_genIso04_isLoaded = false;
		ph_drMinParton_isLoaded = false;
		ngoodjets_isLoaded = false;
		ngoodbtags_isLoaded = false;
		ak4_HT_isLoaded = false;
		ak4_htratiom_isLoaded = false;
		dphi_ak4pfjet_met_isLoaded = false;
		ak4pfjets_p4_isLoaded = false;
		ak4pfjets_passMEDbtag_isLoaded = false;
		ak4pfjets_CSV_isLoaded = false;
		ak4pfjets_mva_isLoaded = false;
		ak4pfjets_parton_flavor_isLoaded = false;
		ak4pfjets_hadron_flavor_isLoaded = false;
		ak4pfjets_loose_puid_isLoaded = false;
		ak4pfjets_loose_pfid_isLoaded = false;
		ak4pfjets_leadMEDbjet_p4_isLoaded = false;
		ak4pfjets_leadbtag_p4_isLoaded = false;
		ak4genjets_p4_isLoaded = false;
		genleps_isfromt_isLoaded = false;
		genleps_p4_isLoaded = false;
		genleps_id_isLoaded = false;
		genleps__genpsidx_isLoaded = false;
		genleps_status_isLoaded = false;
		genleps_fromHardProcessDecayed_isLoaded = false;
		genleps_fromHardProcessFinalState_isLoaded = false;
		genleps_isHardProcess_isLoaded = false;
		genleps_isLastCopy_isLoaded = false;
		genleps_gentaudecay_isLoaded = false;
		gen_nfromtleps__isLoaded = false;
		genleps_motherp4_isLoaded = false;
		genleps_motherid_isLoaded = false;
		genleps_motheridx_isLoaded = false;
		genleps_motherstatus_isLoaded = false;
		genleps_gmotherp4_isLoaded = false;
		genleps_gmotherid_isLoaded = false;
		genleps_gmotheridx_isLoaded = false;
		genleps_gmotherstatus_isLoaded = false;
		gennus_isfromt_isLoaded = false;
		gennus_p4_isLoaded = false;
		gennus_id_isLoaded = false;
		gennus__genpsidx_isLoaded = false;
		gennus_status_isLoaded = false;
		gennus_fromHardProcessDecayed_isLoaded = false;
		gennus_fromHardProcessFinalState_isLoaded = false;
		gennus_isHardProcess_isLoaded = false;
		gennus_isLastCopy_isLoaded = false;
		gennus_gentaudecay_isLoaded = false;
		gen_nfromtnus__isLoaded = false;
		gennus_motherp4_isLoaded = false;
		gennus_motherid_isLoaded = false;
		gennus_motheridx_isLoaded = false;
		gennus_motherstatus_isLoaded = false;
		gennus_gmotherp4_isLoaded = false;
		gennus_gmotherid_isLoaded = false;
		gennus_gmotheridx_isLoaded = false;
		gennus_gmotherstatus_isLoaded = false;
		genqs_isfromt_isLoaded = false;
		genqs_p4_isLoaded = false;
		genqs_id_isLoaded = false;
		genqs__genpsidx_isLoaded = false;
		genqs_status_isLoaded = false;
		genqs_fromHardProcessDecayed_isLoaded = false;
		genqs_fromHardProcessFinalState_isLoaded = false;
		genqs_isHardProcess_isLoaded = false;
		genqs_isLastCopy_isLoaded = false;
		genqs_gentaudecay_isLoaded = false;
		gen_nfromtqs__isLoaded = false;
		genqs_motherp4_isLoaded = false;
		genqs_motherid_isLoaded = false;
		genqs_motheridx_isLoaded = false;
		genqs_motherstatus_isLoaded = false;
		genqs_gmotherp4_isLoaded = false;
		genqs_gmotherid_isLoaded = false;
		genqs_gmotheridx_isLoaded = false;
		genqs_gmotherstatus_isLoaded = false;
		genbosons_isfromt_isLoaded = false;
		genbosons_p4_isLoaded = false;
		genbosons_id_isLoaded = false;
		genbosons__genpsidx_isLoaded = false;
		genbosons_status_isLoaded = false;
		genbosons_fromHardProcessDecayed_isLoaded = false;
		genbosons_fromHardProcessFinalState_isLoaded = false;
		genbosons_isHardProcess_isLoaded = false;
		genbosons_isLastCopy_isLoaded = false;
		genbosons_gentaudecay_isLoaded = false;
		gen_nfromtbosons__isLoaded = false;
		genbosons_motherp4_isLoaded = false;
		genbosons_motherid_isLoaded = false;
		genbosons_motheridx_isLoaded = false;
		genbosons_motherstatus_isLoaded = false;
		genbosons_gmotherp4_isLoaded = false;
		genbosons_gmotherid_isLoaded = false;
		genbosons_gmotheridx_isLoaded = false;
		genbosons_gmotherstatus_isLoaded = false;
		gensusy_isfromt_isLoaded = false;
		gensusy_p4_isLoaded = false;
		gensusy_id_isLoaded = false;
		gensusy__genpsidx_isLoaded = false;
		gensusy_status_isLoaded = false;
		gensusy_fromHardProcessDecayed_isLoaded = false;
		gensusy_fromHardProcessFinalState_isLoaded = false;
		gensusy_isHardProcess_isLoaded = false;
		gensusy_isLastCopy_isLoaded = false;
		gensusy_gentaudecay_isLoaded = false;
		gen_nfromtsusy__isLoaded = false;
		gensusy_motherp4_isLoaded = false;
		gensusy_motherid_isLoaded = false;
		gensusy_motheridx_isLoaded = false;
		gensusy_motherstatus_isLoaded = false;
		gensusy_gmotherp4_isLoaded = false;
		gensusy_gmotherid_isLoaded = false;
		gensusy_gmotheridx_isLoaded = false;
		gensusy_gmotherstatus_isLoaded = false;
	}

void V80_00::LoadAllBranches() 
	// load all branches
{
	if (run_branch != 0) run();
	if (ls_branch != 0) ls();
	if (evt_branch != 0) evt();
	if (nvtxs_branch != 0) nvtxs();
	if (pu_nvtxs_branch != 0) pu_nvtxs();
	if (pfmet_branch != 0) pfmet();
	if (pfmet_phi_branch != 0) pfmet_phi();
	if (scale1fb_branch != 0) scale1fb();
	if (xsec_branch != 0) xsec();
	if (xsec_uncert_branch != 0) xsec_uncert();
	if (kfactor_branch != 0) kfactor();
	if (pu_ntrue_branch != 0) pu_ntrue();
	if (ngoodleps_branch != 0) ngoodleps();
	if (nvetoleps_branch != 0) nvetoleps();
	if (is_data_branch != 0) is_data();
	if (dataset_branch != 0) dataset();
	if (filename_branch != 0) filename();
	if (cms3tag_branch != 0) cms3tag();
	if (nEvents_branch != 0) nEvents();
	if (nEvents_goodvtx_branch != 0) nEvents_goodvtx();
	if (nEvents_MET30_branch != 0) nEvents_MET30();
	if (nEvents_1goodlep_branch != 0) nEvents_1goodlep();
	if (nEvents_2goodjets_branch != 0) nEvents_2goodjets();
	if (is0lep_branch != 0) is0lep();
	if (is1lep_branch != 0) is1lep();
	if (is2lep_branch != 0) is2lep();
	if (isZtoNuNu_branch != 0) isZtoNuNu();
	if (is1lepFromW_branch != 0) is1lepFromW();
	if (is1lepFromTop_branch != 0) is1lepFromTop();
	if (MT2W_branch != 0) MT2W();
	if (mindphi_met_j1_j2_branch != 0) mindphi_met_j1_j2();
	if (mt_met_lep_branch != 0) mt_met_lep();
	if (hadronic_top_chi2_branch != 0) hadronic_top_chi2();
	if (ak4pfjets_rho_branch != 0) ak4pfjets_rho();
	if (pdf_up_weight_branch != 0) pdf_up_weight();
	if (pdf_down_weight_branch != 0) pdf_down_weight();
	if (genweightsID_branch != 0) genweightsID();
	if (genweights_branch != 0) genweights();
	if (weight_btagsf_branch != 0) weight_btagsf();
	if (weight_btagsf_heavy_UP_branch != 0) weight_btagsf_heavy_UP();
	if (weight_btagsf_light_UP_branch != 0) weight_btagsf_light_UP();
	if (weight_btagsf_heavy_DN_branch != 0) weight_btagsf_heavy_DN();
	if (weight_btagsf_light_DN_branch != 0) weight_btagsf_light_DN();
	if (weight_btagsf_fastsim_UP_branch != 0) weight_btagsf_fastsim_UP();
	if (weight_btagsf_fastsim_DN_branch != 0) weight_btagsf_fastsim_DN();
	if (weight_lepSF_branch != 0) weight_lepSF();
	if (weight_lepSF_up_branch != 0) weight_lepSF_up();
	if (weight_lepSF_down_branch != 0) weight_lepSF_down();
	if (weight_vetoLepSF_branch != 0) weight_vetoLepSF();
	if (weight_vetoLepSF_up_branch != 0) weight_vetoLepSF_up();
	if (weight_vetoLepSF_down_branch != 0) weight_vetoLepSF_down();
	if (weight_lepSF_fastSim_branch != 0) weight_lepSF_fastSim();
	if (weight_lepSF_fastSim_up_branch != 0) weight_lepSF_fastSim_up();
	if (weight_lepSF_fastSim_down_branch != 0) weight_lepSF_fastSim_down();
	if (weight_ISR_branch != 0) weight_ISR();
	if (weight_ISRup_branch != 0) weight_ISRup();
	if (weight_ISRdown_branch != 0) weight_ISRdown();
	if (weight_PU_branch != 0) weight_PU();
	if (weight_PUup_branch != 0) weight_PUup();
	if (weight_PUdown_branch != 0) weight_PUdown();
	if (sparms_names_branch != 0) sparms_names();
	if (sparms_values_branch != 0) sparms_values();
	if (sparms_subProcessId_branch != 0) sparms_subProcessId();
	if (mass_lsp_branch != 0) mass_lsp();
	if (mass_chargino_branch != 0) mass_chargino();
	if (mass_stop_branch != 0) mass_stop();
	if (mass_gluino_branch != 0) mass_gluino();
	if (genmet_branch != 0) genmet();
	if (genmet_phi_branch != 0) genmet_phi();
	if (genht_branch != 0) genht();
	if (PassTrackVeto_branch != 0) PassTrackVeto();
	if (PassTauVeto_branch != 0) PassTauVeto();
	if (topness_branch != 0) topness();
	if (topnessMod_branch != 0) topnessMod();
	if (Mlb_closestb_branch != 0) Mlb_closestb();
	if (HLT_SingleEl_branch != 0) HLT_SingleEl();
	if (HLT_SingleMu_branch != 0) HLT_SingleMu();
	if (HLT_SingleMuNoIso_branch != 0) HLT_SingleMuNoIso();
	if (HLT_SingleElNoIso_branch != 0) HLT_SingleElNoIso();
	if (HLT_MET_branch != 0) HLT_MET();
	if (HLT_DiEl_branch != 0) HLT_DiEl();
	if (HLT_DiMu_branch != 0) HLT_DiMu();
	if (HLT_MuE_branch != 0) HLT_MuE();
	if (HLT_Photon90_CaloIdL_PFHT500_branch != 0) HLT_Photon90_CaloIdL_PFHT500();
	if (HLT_Photon22_R9Id90_HE10_IsoM_branch != 0) HLT_Photon22_R9Id90_HE10_IsoM();
	if (HLT_Photon30_R9Id90_HE10_IsoM_branch != 0) HLT_Photon30_R9Id90_HE10_IsoM();
	if (HLT_Photon36_R9Id90_HE10_IsoM_branch != 0) HLT_Photon36_R9Id90_HE10_IsoM();
	if (HLT_Photon50_R9Id90_HE10_IsoM_branch != 0) HLT_Photon50_R9Id90_HE10_IsoM();
	if (HLT_Photon75_R9Id90_HE10_IsoM_branch != 0) HLT_Photon75_R9Id90_HE10_IsoM();
	if (HLT_Photon90_R9Id90_HE10_IsoM_branch != 0) HLT_Photon90_R9Id90_HE10_IsoM();
	if (HLT_Photon120_R9Id90_HE10_IsoM_branch != 0) HLT_Photon120_R9Id90_HE10_IsoM();
	if (HLT_Photon165_R9Id90_HE10_IsoM_branch != 0) HLT_Photon165_R9Id90_HE10_IsoM();
	if (HLT_Photon175_branch != 0) HLT_Photon175();
	if (HLT_Photon165_HE10_branch != 0) HLT_Photon165_HE10();
	if (nPhotons_branch != 0) nPhotons();
	if (ph_ngoodjets_branch != 0) ph_ngoodjets();
	if (ph_ngoodbtags_branch != 0) ph_ngoodbtags();
	if (filt_met_branch != 0) filt_met();
	if (filt_badMuonFilter_branch != 0) filt_badMuonFilter();
	if (filt_badChargedCandidateFilter_branch != 0) filt_badChargedCandidateFilter();
	if (filt_cscbeamhalo2015_branch != 0) filt_cscbeamhalo2015();
	if (filt_cscbeamhalo_branch != 0) filt_cscbeamhalo();
	if (hardgenpt_branch != 0) hardgenpt();
	if (lep1_pdgid_branch != 0) lep1_pdgid();
	if (lep1_production_type_branch != 0) lep1_production_type();
	if (lep1_MiniIso_branch != 0) lep1_MiniIso();
	if (lep1_relIso_branch != 0) lep1_relIso();
	if (lep1_passLooseID_branch != 0) lep1_passLooseID();
	if (lep1_passMediumID_branch != 0) lep1_passMediumID();
	if (lep1_passTightID_branch != 0) lep1_passTightID();
	if (lep1_passVeto_branch != 0) lep1_passVeto();
	if (lep1_p4_branch != 0) lep1_p4();
	if (lep1_mcp4_branch != 0) lep1_mcp4();
	if (lep1_mc_motherid_branch != 0) lep1_mc_motherid();
	if (lep2_pdgid_branch != 0) lep2_pdgid();
	if (lep2_production_type_branch != 0) lep2_production_type();
	if (lep2_MiniIso_branch != 0) lep2_MiniIso();
	if (lep2_relIso_branch != 0) lep2_relIso();
	if (lep2_passLooseID_branch != 0) lep2_passLooseID();
	if (lep2_passMediumID_branch != 0) lep2_passMediumID();
	if (lep2_passTightID_branch != 0) lep2_passTightID();
	if (lep2_passVeto_branch != 0) lep2_passVeto();
	if (lep2_p4_branch != 0) lep2_p4();
	if (lep2_mcp4_branch != 0) lep2_mcp4();
	if (lep2_mc_motherid_branch != 0) lep2_mc_motherid();
	if (ph_sigmaIEtaEta_fill5x5_branch != 0) ph_sigmaIEtaEta_fill5x5();
	if (ph_hOverE_branch != 0) ph_hOverE();
	if (ph_r9_branch != 0) ph_r9();
	if (ph_chiso_branch != 0) ph_chiso();
	if (ph_nhiso_branch != 0) ph_nhiso();
	if (ph_phiso_branch != 0) ph_phiso();
	if (ph_idCutBased_branch != 0) ph_idCutBased();
	if (ph_overlapJetId_branch != 0) ph_overlapJetId();
	if (ph_p4_branch != 0) ph_p4();
	if (ph_mcp4_branch != 0) ph_mcp4();
	if (ph_pt_branch != 0) ph_pt();
	if (ph_eta_branch != 0) ph_eta();
	if (ph_phi_branch != 0) ph_phi();
	if (ph_mass_branch != 0) ph_mass();
	if (ph_mcMatchId_branch != 0) ph_mcMatchId();
	if (ph_genIso04_branch != 0) ph_genIso04();
	if (ph_drMinParton_branch != 0) ph_drMinParton();
	if (ngoodjets_branch != 0) ngoodjets();
	if (ngoodbtags_branch != 0) ngoodbtags();
	if (ak4_HT_branch != 0) ak4_HT();
	if (ak4_htratiom_branch != 0) ak4_htratiom();
	if (dphi_ak4pfjet_met_branch != 0) dphi_ak4pfjet_met();
	if (ak4pfjets_p4_branch != 0) ak4pfjets_p4();
	if (ak4pfjets_passMEDbtag_branch != 0) ak4pfjets_passMEDbtag();
	if (ak4pfjets_CSV_branch != 0) ak4pfjets_CSV();
	if (ak4pfjets_mva_branch != 0) ak4pfjets_mva();
	if (ak4pfjets_parton_flavor_branch != 0) ak4pfjets_parton_flavor();
	if (ak4pfjets_hadron_flavor_branch != 0) ak4pfjets_hadron_flavor();
	if (ak4pfjets_loose_puid_branch != 0) ak4pfjets_loose_puid();
	if (ak4pfjets_loose_pfid_branch != 0) ak4pfjets_loose_pfid();
	if (ak4pfjets_leadMEDbjet_p4_branch != 0) ak4pfjets_leadMEDbjet_p4();
	if (ak4pfjets_leadbtag_p4_branch != 0) ak4pfjets_leadbtag_p4();
	if (ak4genjets_p4_branch != 0) ak4genjets_p4();
	if (genleps_isfromt_branch != 0) genleps_isfromt();
	if (genleps_p4_branch != 0) genleps_p4();
	if (genleps_id_branch != 0) genleps_id();
	if (genleps__genpsidx_branch != 0) genleps__genpsidx();
	if (genleps_status_branch != 0) genleps_status();
	if (genleps_fromHardProcessDecayed_branch != 0) genleps_fromHardProcessDecayed();
	if (genleps_fromHardProcessFinalState_branch != 0) genleps_fromHardProcessFinalState();
	if (genleps_isHardProcess_branch != 0) genleps_isHardProcess();
	if (genleps_isLastCopy_branch != 0) genleps_isLastCopy();
	if (genleps_gentaudecay_branch != 0) genleps_gentaudecay();
	if (gen_nfromtleps__branch != 0) gen_nfromtleps_();
	if (genleps_motherp4_branch != 0) genleps_motherp4();
	if (genleps_motherid_branch != 0) genleps_motherid();
	if (genleps_motheridx_branch != 0) genleps_motheridx();
	if (genleps_motherstatus_branch != 0) genleps_motherstatus();
	if (genleps_gmotherp4_branch != 0) genleps_gmotherp4();
	if (genleps_gmotherid_branch != 0) genleps_gmotherid();
	if (genleps_gmotheridx_branch != 0) genleps_gmotheridx();
	if (genleps_gmotherstatus_branch != 0) genleps_gmotherstatus();
	if (gennus_isfromt_branch != 0) gennus_isfromt();
	if (gennus_p4_branch != 0) gennus_p4();
	if (gennus_id_branch != 0) gennus_id();
	if (gennus__genpsidx_branch != 0) gennus__genpsidx();
	if (gennus_status_branch != 0) gennus_status();
	if (gennus_fromHardProcessDecayed_branch != 0) gennus_fromHardProcessDecayed();
	if (gennus_fromHardProcessFinalState_branch != 0) gennus_fromHardProcessFinalState();
	if (gennus_isHardProcess_branch != 0) gennus_isHardProcess();
	if (gennus_isLastCopy_branch != 0) gennus_isLastCopy();
	if (gennus_gentaudecay_branch != 0) gennus_gentaudecay();
	if (gen_nfromtnus__branch != 0) gen_nfromtnus_();
	if (gennus_motherp4_branch != 0) gennus_motherp4();
	if (gennus_motherid_branch != 0) gennus_motherid();
	if (gennus_motheridx_branch != 0) gennus_motheridx();
	if (gennus_motherstatus_branch != 0) gennus_motherstatus();
	if (gennus_gmotherp4_branch != 0) gennus_gmotherp4();
	if (gennus_gmotherid_branch != 0) gennus_gmotherid();
	if (gennus_gmotheridx_branch != 0) gennus_gmotheridx();
	if (gennus_gmotherstatus_branch != 0) gennus_gmotherstatus();
	if (genqs_isfromt_branch != 0) genqs_isfromt();
	if (genqs_p4_branch != 0) genqs_p4();
	if (genqs_id_branch != 0) genqs_id();
	if (genqs__genpsidx_branch != 0) genqs__genpsidx();
	if (genqs_status_branch != 0) genqs_status();
	if (genqs_fromHardProcessDecayed_branch != 0) genqs_fromHardProcessDecayed();
	if (genqs_fromHardProcessFinalState_branch != 0) genqs_fromHardProcessFinalState();
	if (genqs_isHardProcess_branch != 0) genqs_isHardProcess();
	if (genqs_isLastCopy_branch != 0) genqs_isLastCopy();
	if (genqs_gentaudecay_branch != 0) genqs_gentaudecay();
	if (gen_nfromtqs__branch != 0) gen_nfromtqs_();
	if (genqs_motherp4_branch != 0) genqs_motherp4();
	if (genqs_motherid_branch != 0) genqs_motherid();
	if (genqs_motheridx_branch != 0) genqs_motheridx();
	if (genqs_motherstatus_branch != 0) genqs_motherstatus();
	if (genqs_gmotherp4_branch != 0) genqs_gmotherp4();
	if (genqs_gmotherid_branch != 0) genqs_gmotherid();
	if (genqs_gmotheridx_branch != 0) genqs_gmotheridx();
	if (genqs_gmotherstatus_branch != 0) genqs_gmotherstatus();
	if (genbosons_isfromt_branch != 0) genbosons_isfromt();
	if (genbosons_p4_branch != 0) genbosons_p4();
	if (genbosons_id_branch != 0) genbosons_id();
	if (genbosons__genpsidx_branch != 0) genbosons__genpsidx();
	if (genbosons_status_branch != 0) genbosons_status();
	if (genbosons_fromHardProcessDecayed_branch != 0) genbosons_fromHardProcessDecayed();
	if (genbosons_fromHardProcessFinalState_branch != 0) genbosons_fromHardProcessFinalState();
	if (genbosons_isHardProcess_branch != 0) genbosons_isHardProcess();
	if (genbosons_isLastCopy_branch != 0) genbosons_isLastCopy();
	if (genbosons_gentaudecay_branch != 0) genbosons_gentaudecay();
	if (gen_nfromtbosons__branch != 0) gen_nfromtbosons_();
	if (genbosons_motherp4_branch != 0) genbosons_motherp4();
	if (genbosons_motherid_branch != 0) genbosons_motherid();
	if (genbosons_motheridx_branch != 0) genbosons_motheridx();
	if (genbosons_motherstatus_branch != 0) genbosons_motherstatus();
	if (genbosons_gmotherp4_branch != 0) genbosons_gmotherp4();
	if (genbosons_gmotherid_branch != 0) genbosons_gmotherid();
	if (genbosons_gmotheridx_branch != 0) genbosons_gmotheridx();
	if (genbosons_gmotherstatus_branch != 0) genbosons_gmotherstatus();
	if (gensusy_isfromt_branch != 0) gensusy_isfromt();
	if (gensusy_p4_branch != 0) gensusy_p4();
	if (gensusy_id_branch != 0) gensusy_id();
	if (gensusy__genpsidx_branch != 0) gensusy__genpsidx();
	if (gensusy_status_branch != 0) gensusy_status();
	if (gensusy_fromHardProcessDecayed_branch != 0) gensusy_fromHardProcessDecayed();
	if (gensusy_fromHardProcessFinalState_branch != 0) gensusy_fromHardProcessFinalState();
	if (gensusy_isHardProcess_branch != 0) gensusy_isHardProcess();
	if (gensusy_isLastCopy_branch != 0) gensusy_isLastCopy();
	if (gensusy_gentaudecay_branch != 0) gensusy_gentaudecay();
	if (gen_nfromtsusy__branch != 0) gen_nfromtsusy_();
	if (gensusy_motherp4_branch != 0) gensusy_motherp4();
	if (gensusy_motherid_branch != 0) gensusy_motherid();
	if (gensusy_motheridx_branch != 0) gensusy_motheridx();
	if (gensusy_motherstatus_branch != 0) gensusy_motherstatus();
	if (gensusy_gmotherp4_branch != 0) gensusy_gmotherp4();
	if (gensusy_gmotherid_branch != 0) gensusy_gmotherid();
	if (gensusy_gmotheridx_branch != 0) gensusy_gmotheridx();
	if (gensusy_gmotherstatus_branch != 0) gensusy_gmotherstatus();
}

	const unsigned int &V80_00::run()
	{
		if (not run_isLoaded) {
			if (run_branch != 0) {
				run_branch->GetEntry(index);
			} else { 
				printf("branch run_branch does not exist!\n");
				exit(1);
			}
			run_isLoaded = true;
		}
		return run_;
	}
	const unsigned int &V80_00::ls()
	{
		if (not ls_isLoaded) {
			if (ls_branch != 0) {
				ls_branch->GetEntry(index);
			} else { 
				printf("branch ls_branch does not exist!\n");
				exit(1);
			}
			ls_isLoaded = true;
		}
		return ls_;
	}
	const unsigned int &V80_00::evt()
	{
		if (not evt_isLoaded) {
			if (evt_branch != 0) {
				evt_branch->GetEntry(index);
			} else { 
				printf("branch evt_branch does not exist!\n");
				exit(1);
			}
			evt_isLoaded = true;
		}
		return evt_;
	}
	const int &V80_00::nvtxs()
	{
		if (not nvtxs_isLoaded) {
			if (nvtxs_branch != 0) {
				nvtxs_branch->GetEntry(index);
			} else { 
				printf("branch nvtxs_branch does not exist!\n");
				exit(1);
			}
			nvtxs_isLoaded = true;
		}
		return nvtxs_;
	}
	const int &V80_00::pu_nvtxs()
	{
		if (not pu_nvtxs_isLoaded) {
			if (pu_nvtxs_branch != 0) {
				pu_nvtxs_branch->GetEntry(index);
			} else { 
				printf("branch pu_nvtxs_branch does not exist!\n");
				exit(1);
			}
			pu_nvtxs_isLoaded = true;
		}
		return pu_nvtxs_;
	}
	const float &V80_00::pfmet()
	{
		if (not pfmet_isLoaded) {
			if (pfmet_branch != 0) {
				pfmet_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_branch does not exist!\n");
				exit(1);
			}
			pfmet_isLoaded = true;
		}
		return pfmet_;
	}
	const float &V80_00::pfmet_phi()
	{
		if (not pfmet_phi_isLoaded) {
			if (pfmet_phi_branch != 0) {
				pfmet_phi_branch->GetEntry(index);
			} else { 
				printf("branch pfmet_phi_branch does not exist!\n");
				exit(1);
			}
			pfmet_phi_isLoaded = true;
		}
		return pfmet_phi_;
	}
	const float &V80_00::scale1fb()
	{
		if (not scale1fb_isLoaded) {
			if (scale1fb_branch != 0) {
				scale1fb_branch->GetEntry(index);
			} else { 
				printf("branch scale1fb_branch does not exist!\n");
				exit(1);
			}
			scale1fb_isLoaded = true;
		}
		return scale1fb_;
	}
	const float &V80_00::xsec()
	{
		if (not xsec_isLoaded) {
			if (xsec_branch != 0) {
				xsec_branch->GetEntry(index);
			} else { 
				printf("branch xsec_branch does not exist!\n");
				exit(1);
			}
			xsec_isLoaded = true;
		}
		return xsec_;
	}
	const float &V80_00::xsec_uncert()
	{
		if (not xsec_uncert_isLoaded) {
			if (xsec_uncert_branch != 0) {
				xsec_uncert_branch->GetEntry(index);
			} else { 
				printf("branch xsec_uncert_branch does not exist!\n");
				exit(1);
			}
			xsec_uncert_isLoaded = true;
		}
		return xsec_uncert_;
	}
	const float &V80_00::kfactor()
	{
		if (not kfactor_isLoaded) {
			if (kfactor_branch != 0) {
				kfactor_branch->GetEntry(index);
			} else { 
				printf("branch kfactor_branch does not exist!\n");
				exit(1);
			}
			kfactor_isLoaded = true;
		}
		return kfactor_;
	}
	const float &V80_00::pu_ntrue()
	{
		if (not pu_ntrue_isLoaded) {
			if (pu_ntrue_branch != 0) {
				pu_ntrue_branch->GetEntry(index);
			} else { 
				printf("branch pu_ntrue_branch does not exist!\n");
				exit(1);
			}
			pu_ntrue_isLoaded = true;
		}
		return pu_ntrue_;
	}
	const int &V80_00::ngoodleps()
	{
		if (not ngoodleps_isLoaded) {
			if (ngoodleps_branch != 0) {
				ngoodleps_branch->GetEntry(index);
			} else { 
				printf("branch ngoodleps_branch does not exist!\n");
				exit(1);
			}
			ngoodleps_isLoaded = true;
		}
		return ngoodleps_;
	}
	const int &V80_00::nvetoleps()
	{
		if (not nvetoleps_isLoaded) {
			if (nvetoleps_branch != 0) {
				nvetoleps_branch->GetEntry(index);
			} else { 
				printf("branch nvetoleps_branch does not exist!\n");
				exit(1);
			}
			nvetoleps_isLoaded = true;
		}
		return nvetoleps_;
	}
	const bool &	V80_00::is_data()
	{
		if (not is_data_isLoaded) {
			if (is_data_branch != 0) {
				is_data_branch->GetEntry(index);
			} else { 
				printf("branch is_data_branch does not exist!\n");
				exit(1);
			}
			is_data_isLoaded = true;
		}
		return is_data_;
	}
	const string &V80_00::dataset()
	{
		if (not dataset_isLoaded) {
			if (dataset_branch != 0) {
				dataset_branch->GetEntry(index);
			} else { 
				printf("branch dataset_branch does not exist!\n");
				exit(1);
			}
			dataset_isLoaded = true;
		}
		return *dataset_;
	}
	const string &V80_00::filename()
	{
		if (not filename_isLoaded) {
			if (filename_branch != 0) {
				filename_branch->GetEntry(index);
			} else { 
				printf("branch filename_branch does not exist!\n");
				exit(1);
			}
			filename_isLoaded = true;
		}
		return *filename_;
	}
	const string &V80_00::cms3tag()
	{
		if (not cms3tag_isLoaded) {
			if (cms3tag_branch != 0) {
				cms3tag_branch->GetEntry(index);
			} else { 
				printf("branch cms3tag_branch does not exist!\n");
				exit(1);
			}
			cms3tag_isLoaded = true;
		}
		return *cms3tag_;
	}
	const unsigned int &V80_00::nEvents()
	{
		if (not nEvents_isLoaded) {
			if (nEvents_branch != 0) {
				nEvents_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_branch does not exist!\n");
				exit(1);
			}
			nEvents_isLoaded = true;
		}
		return nEvents_;
	}
	const unsigned int &V80_00::nEvents_goodvtx()
	{
		if (not nEvents_goodvtx_isLoaded) {
			if (nEvents_goodvtx_branch != 0) {
				nEvents_goodvtx_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_goodvtx_branch does not exist!\n");
				exit(1);
			}
			nEvents_goodvtx_isLoaded = true;
		}
		return nEvents_goodvtx_;
	}
	const unsigned int &V80_00::nEvents_MET30()
	{
		if (not nEvents_MET30_isLoaded) {
			if (nEvents_MET30_branch != 0) {
				nEvents_MET30_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_MET30_branch does not exist!\n");
				exit(1);
			}
			nEvents_MET30_isLoaded = true;
		}
		return nEvents_MET30_;
	}
	const unsigned int &V80_00::nEvents_1goodlep()
	{
		if (not nEvents_1goodlep_isLoaded) {
			if (nEvents_1goodlep_branch != 0) {
				nEvents_1goodlep_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_1goodlep_branch does not exist!\n");
				exit(1);
			}
			nEvents_1goodlep_isLoaded = true;
		}
		return nEvents_1goodlep_;
	}
	const unsigned int &V80_00::nEvents_2goodjets()
	{
		if (not nEvents_2goodjets_isLoaded) {
			if (nEvents_2goodjets_branch != 0) {
				nEvents_2goodjets_branch->GetEntry(index);
			} else { 
				printf("branch nEvents_2goodjets_branch does not exist!\n");
				exit(1);
			}
			nEvents_2goodjets_isLoaded = true;
		}
		return nEvents_2goodjets_;
	}
	const int &V80_00::is0lep()
	{
		if (not is0lep_isLoaded) {
			if (is0lep_branch != 0) {
				is0lep_branch->GetEntry(index);
			} else { 
				printf("branch is0lep_branch does not exist!\n");
				exit(1);
			}
			is0lep_isLoaded = true;
		}
		return is0lep_;
	}
	const int &V80_00::is1lep()
	{
		if (not is1lep_isLoaded) {
			if (is1lep_branch != 0) {
				is1lep_branch->GetEntry(index);
			} else { 
				printf("branch is1lep_branch does not exist!\n");
				exit(1);
			}
			is1lep_isLoaded = true;
		}
		return is1lep_;
	}
	const int &V80_00::is2lep()
	{
		if (not is2lep_isLoaded) {
			if (is2lep_branch != 0) {
				is2lep_branch->GetEntry(index);
			} else { 
				printf("branch is2lep_branch does not exist!\n");
				exit(1);
			}
			is2lep_isLoaded = true;
		}
		return is2lep_;
	}
	const int &V80_00::isZtoNuNu()
	{
		if (not isZtoNuNu_isLoaded) {
			if (isZtoNuNu_branch != 0) {
				isZtoNuNu_branch->GetEntry(index);
			} else { 
				printf("branch isZtoNuNu_branch does not exist!\n");
				exit(1);
			}
			isZtoNuNu_isLoaded = true;
		}
		return isZtoNuNu_;
	}
	const int &V80_00::is1lepFromW()
	{
		if (not is1lepFromW_isLoaded) {
			if (is1lepFromW_branch != 0) {
				is1lepFromW_branch->GetEntry(index);
			} else { 
				printf("branch is1lepFromW_branch does not exist!\n");
				exit(1);
			}
			is1lepFromW_isLoaded = true;
		}
		return is1lepFromW_;
	}
	const int &V80_00::is1lepFromTop()
	{
		if (not is1lepFromTop_isLoaded) {
			if (is1lepFromTop_branch != 0) {
				is1lepFromTop_branch->GetEntry(index);
			} else { 
				printf("branch is1lepFromTop_branch does not exist!\n");
				exit(1);
			}
			is1lepFromTop_isLoaded = true;
		}
		return is1lepFromTop_;
	}
	const float &V80_00::MT2W()
	{
		if (not MT2W_isLoaded) {
			if (MT2W_branch != 0) {
				MT2W_branch->GetEntry(index);
			} else { 
				printf("branch MT2W_branch does not exist!\n");
				exit(1);
			}
			MT2W_isLoaded = true;
		}
		return MT2W_;
	}
	const float &V80_00::mindphi_met_j1_j2()
	{
		if (not mindphi_met_j1_j2_isLoaded) {
			if (mindphi_met_j1_j2_branch != 0) {
				mindphi_met_j1_j2_branch->GetEntry(index);
			} else { 
				printf("branch mindphi_met_j1_j2_branch does not exist!\n");
				exit(1);
			}
			mindphi_met_j1_j2_isLoaded = true;
		}
		return mindphi_met_j1_j2_;
	}
	const float &V80_00::mt_met_lep()
	{
		if (not mt_met_lep_isLoaded) {
			if (mt_met_lep_branch != 0) {
				mt_met_lep_branch->GetEntry(index);
			} else { 
				printf("branch mt_met_lep_branch does not exist!\n");
				exit(1);
			}
			mt_met_lep_isLoaded = true;
		}
		return mt_met_lep_;
	}
	const float &V80_00::hadronic_top_chi2()
	{
		if (not hadronic_top_chi2_isLoaded) {
			if (hadronic_top_chi2_branch != 0) {
				hadronic_top_chi2_branch->GetEntry(index);
			} else { 
				printf("branch hadronic_top_chi2_branch does not exist!\n");
				exit(1);
			}
			hadronic_top_chi2_isLoaded = true;
		}
		return hadronic_top_chi2_;
	}
	const float &V80_00::ak4pfjets_rho()
	{
		if (not ak4pfjets_rho_isLoaded) {
			if (ak4pfjets_rho_branch != 0) {
				ak4pfjets_rho_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_rho_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_rho_isLoaded = true;
		}
		return ak4pfjets_rho_;
	}
	const float &V80_00::pdf_up_weight()
	{
		if (not pdf_up_weight_isLoaded) {
			if (pdf_up_weight_branch != 0) {
				pdf_up_weight_branch->GetEntry(index);
			} else { 
				printf("branch pdf_up_weight_branch does not exist!\n");
				exit(1);
			}
			pdf_up_weight_isLoaded = true;
		}
		return pdf_up_weight_;
	}
	const float &V80_00::pdf_down_weight()
	{
		if (not pdf_down_weight_isLoaded) {
			if (pdf_down_weight_branch != 0) {
				pdf_down_weight_branch->GetEntry(index);
			} else { 
				printf("branch pdf_down_weight_branch does not exist!\n");
				exit(1);
			}
			pdf_down_weight_isLoaded = true;
		}
		return pdf_down_weight_;
	}
	const vector<string> &V80_00::genweightsID()
	{
		if (not genweightsID_isLoaded) {
			if (genweightsID_branch != 0) {
				genweightsID_branch->GetEntry(index);
			} else { 
				printf("branch genweightsID_branch does not exist!\n");
				exit(1);
			}
			genweightsID_isLoaded = true;
		}
		return *genweightsID_;
	}
	const vector<float> &V80_00::genweights()
	{
		if (not genweights_isLoaded) {
			if (genweights_branch != 0) {
				genweights_branch->GetEntry(index);
			} else { 
				printf("branch genweights_branch does not exist!\n");
				exit(1);
			}
			genweights_isLoaded = true;
		}
		return *genweights_;
	}
	const float &V80_00::weight_btagsf()
	{
		if (not weight_btagsf_isLoaded) {
			if (weight_btagsf_branch != 0) {
				weight_btagsf_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_isLoaded = true;
		}
		return weight_btagsf_;
	}
	const float &V80_00::weight_btagsf_heavy_UP()
	{
		if (not weight_btagsf_heavy_UP_isLoaded) {
			if (weight_btagsf_heavy_UP_branch != 0) {
				weight_btagsf_heavy_UP_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_heavy_UP_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_heavy_UP_isLoaded = true;
		}
		return weight_btagsf_heavy_UP_;
	}
	const float &V80_00::weight_btagsf_light_UP()
	{
		if (not weight_btagsf_light_UP_isLoaded) {
			if (weight_btagsf_light_UP_branch != 0) {
				weight_btagsf_light_UP_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_light_UP_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_light_UP_isLoaded = true;
		}
		return weight_btagsf_light_UP_;
	}
	const float &V80_00::weight_btagsf_heavy_DN()
	{
		if (not weight_btagsf_heavy_DN_isLoaded) {
			if (weight_btagsf_heavy_DN_branch != 0) {
				weight_btagsf_heavy_DN_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_heavy_DN_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_heavy_DN_isLoaded = true;
		}
		return weight_btagsf_heavy_DN_;
	}
	const float &V80_00::weight_btagsf_light_DN()
	{
		if (not weight_btagsf_light_DN_isLoaded) {
			if (weight_btagsf_light_DN_branch != 0) {
				weight_btagsf_light_DN_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_light_DN_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_light_DN_isLoaded = true;
		}
		return weight_btagsf_light_DN_;
	}
	const float &V80_00::weight_btagsf_fastsim_UP()
	{
		if (not weight_btagsf_fastsim_UP_isLoaded) {
			if (weight_btagsf_fastsim_UP_branch != 0) {
				weight_btagsf_fastsim_UP_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_fastsim_UP_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_fastsim_UP_isLoaded = true;
		}
		return weight_btagsf_fastsim_UP_;
	}
	const float &V80_00::weight_btagsf_fastsim_DN()
	{
		if (not weight_btagsf_fastsim_DN_isLoaded) {
			if (weight_btagsf_fastsim_DN_branch != 0) {
				weight_btagsf_fastsim_DN_branch->GetEntry(index);
			} else { 
				printf("branch weight_btagsf_fastsim_DN_branch does not exist!\n");
				exit(1);
			}
			weight_btagsf_fastsim_DN_isLoaded = true;
		}
		return weight_btagsf_fastsim_DN_;
	}
	const float &V80_00::weight_lepSF()
	{
		if (not weight_lepSF_isLoaded) {
			if (weight_lepSF_branch != 0) {
				weight_lepSF_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_isLoaded = true;
		}
		return weight_lepSF_;
	}
	const float &V80_00::weight_lepSF_up()
	{
		if (not weight_lepSF_up_isLoaded) {
			if (weight_lepSF_up_branch != 0) {
				weight_lepSF_up_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_up_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_up_isLoaded = true;
		}
		return weight_lepSF_up_;
	}
	const float &V80_00::weight_lepSF_down()
	{
		if (not weight_lepSF_down_isLoaded) {
			if (weight_lepSF_down_branch != 0) {
				weight_lepSF_down_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_down_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_down_isLoaded = true;
		}
		return weight_lepSF_down_;
	}
	const float &V80_00::weight_vetoLepSF()
	{
		if (not weight_vetoLepSF_isLoaded) {
			if (weight_vetoLepSF_branch != 0) {
				weight_vetoLepSF_branch->GetEntry(index);
			} else { 
				printf("branch weight_vetoLepSF_branch does not exist!\n");
				exit(1);
			}
			weight_vetoLepSF_isLoaded = true;
		}
		return weight_vetoLepSF_;
	}
	const float &V80_00::weight_vetoLepSF_up()
	{
		if (not weight_vetoLepSF_up_isLoaded) {
			if (weight_vetoLepSF_up_branch != 0) {
				weight_vetoLepSF_up_branch->GetEntry(index);
			} else { 
				printf("branch weight_vetoLepSF_up_branch does not exist!\n");
				exit(1);
			}
			weight_vetoLepSF_up_isLoaded = true;
		}
		return weight_vetoLepSF_up_;
	}
	const float &V80_00::weight_vetoLepSF_down()
	{
		if (not weight_vetoLepSF_down_isLoaded) {
			if (weight_vetoLepSF_down_branch != 0) {
				weight_vetoLepSF_down_branch->GetEntry(index);
			} else { 
				printf("branch weight_vetoLepSF_down_branch does not exist!\n");
				exit(1);
			}
			weight_vetoLepSF_down_isLoaded = true;
		}
		return weight_vetoLepSF_down_;
	}
	const float &V80_00::weight_lepSF_fastSim()
	{
		if (not weight_lepSF_fastSim_isLoaded) {
			if (weight_lepSF_fastSim_branch != 0) {
				weight_lepSF_fastSim_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_fastSim_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_fastSim_isLoaded = true;
		}
		return weight_lepSF_fastSim_;
	}
	const float &V80_00::weight_lepSF_fastSim_up()
	{
		if (not weight_lepSF_fastSim_up_isLoaded) {
			if (weight_lepSF_fastSim_up_branch != 0) {
				weight_lepSF_fastSim_up_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_fastSim_up_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_fastSim_up_isLoaded = true;
		}
		return weight_lepSF_fastSim_up_;
	}
	const float &V80_00::weight_lepSF_fastSim_down()
	{
		if (not weight_lepSF_fastSim_down_isLoaded) {
			if (weight_lepSF_fastSim_down_branch != 0) {
				weight_lepSF_fastSim_down_branch->GetEntry(index);
			} else { 
				printf("branch weight_lepSF_fastSim_down_branch does not exist!\n");
				exit(1);
			}
			weight_lepSF_fastSim_down_isLoaded = true;
		}
		return weight_lepSF_fastSim_down_;
	}
	const float &V80_00::weight_ISR()
	{
		if (not weight_ISR_isLoaded) {
			if (weight_ISR_branch != 0) {
				weight_ISR_branch->GetEntry(index);
			} else { 
				printf("branch weight_ISR_branch does not exist!\n");
				exit(1);
			}
			weight_ISR_isLoaded = true;
		}
		return weight_ISR_;
	}
	const float &V80_00::weight_ISRup()
	{
		if (not weight_ISRup_isLoaded) {
			if (weight_ISRup_branch != 0) {
				weight_ISRup_branch->GetEntry(index);
			} else { 
				printf("branch weight_ISRup_branch does not exist!\n");
				exit(1);
			}
			weight_ISRup_isLoaded = true;
		}
		return weight_ISRup_;
	}
	const float &V80_00::weight_ISRdown()
	{
		if (not weight_ISRdown_isLoaded) {
			if (weight_ISRdown_branch != 0) {
				weight_ISRdown_branch->GetEntry(index);
			} else { 
				printf("branch weight_ISRdown_branch does not exist!\n");
				exit(1);
			}
			weight_ISRdown_isLoaded = true;
		}
		return weight_ISRdown_;
	}
	const float &V80_00::weight_PU()
	{
		if (not weight_PU_isLoaded) {
			if (weight_PU_branch != 0) {
				weight_PU_branch->GetEntry(index);
			} else { 
				printf("branch weight_PU_branch does not exist!\n");
				exit(1);
			}
			weight_PU_isLoaded = true;
		}
		return weight_PU_;
	}
	const float &V80_00::weight_PUup()
	{
		if (not weight_PUup_isLoaded) {
			if (weight_PUup_branch != 0) {
				weight_PUup_branch->GetEntry(index);
			} else { 
				printf("branch weight_PUup_branch does not exist!\n");
				exit(1);
			}
			weight_PUup_isLoaded = true;
		}
		return weight_PUup_;
	}
	const float &V80_00::weight_PUdown()
	{
		if (not weight_PUdown_isLoaded) {
			if (weight_PUdown_branch != 0) {
				weight_PUdown_branch->GetEntry(index);
			} else { 
				printf("branch weight_PUdown_branch does not exist!\n");
				exit(1);
			}
			weight_PUdown_isLoaded = true;
		}
		return weight_PUdown_;
	}
	const vector<string> &V80_00::sparms_names()
	{
		if (not sparms_names_isLoaded) {
			if (sparms_names_branch != 0) {
				sparms_names_branch->GetEntry(index);
			} else { 
				printf("branch sparms_names_branch does not exist!\n");
				exit(1);
			}
			sparms_names_isLoaded = true;
		}
		return *sparms_names_;
	}
	const vector<float> &V80_00::sparms_values()
	{
		if (not sparms_values_isLoaded) {
			if (sparms_values_branch != 0) {
				sparms_values_branch->GetEntry(index);
			} else { 
				printf("branch sparms_values_branch does not exist!\n");
				exit(1);
			}
			sparms_values_isLoaded = true;
		}
		return *sparms_values_;
	}
	const int &V80_00::sparms_subProcessId()
	{
		if (not sparms_subProcessId_isLoaded) {
			if (sparms_subProcessId_branch != 0) {
				sparms_subProcessId_branch->GetEntry(index);
			} else { 
				printf("branch sparms_subProcessId_branch does not exist!\n");
				exit(1);
			}
			sparms_subProcessId_isLoaded = true;
		}
		return sparms_subProcessId_;
	}
	const float &V80_00::mass_lsp()
	{
		if (not mass_lsp_isLoaded) {
			if (mass_lsp_branch != 0) {
				mass_lsp_branch->GetEntry(index);
			} else { 
				printf("branch mass_lsp_branch does not exist!\n");
				exit(1);
			}
			mass_lsp_isLoaded = true;
		}
		return mass_lsp_;
	}
	const float &V80_00::mass_chargino()
	{
		if (not mass_chargino_isLoaded) {
			if (mass_chargino_branch != 0) {
				mass_chargino_branch->GetEntry(index);
			} else { 
				printf("branch mass_chargino_branch does not exist!\n");
				exit(1);
			}
			mass_chargino_isLoaded = true;
		}
		return mass_chargino_;
	}
	const float &V80_00::mass_stop()
	{
		if (not mass_stop_isLoaded) {
			if (mass_stop_branch != 0) {
				mass_stop_branch->GetEntry(index);
			} else { 
				printf("branch mass_stop_branch does not exist!\n");
				exit(1);
			}
			mass_stop_isLoaded = true;
		}
		return mass_stop_;
	}
	const float &V80_00::mass_gluino()
	{
		if (not mass_gluino_isLoaded) {
			if (mass_gluino_branch != 0) {
				mass_gluino_branch->GetEntry(index);
			} else { 
				printf("branch mass_gluino_branch does not exist!\n");
				exit(1);
			}
			mass_gluino_isLoaded = true;
		}
		return mass_gluino_;
	}
	const float &V80_00::genmet()
	{
		if (not genmet_isLoaded) {
			if (genmet_branch != 0) {
				genmet_branch->GetEntry(index);
			} else { 
				printf("branch genmet_branch does not exist!\n");
				exit(1);
			}
			genmet_isLoaded = true;
		}
		return genmet_;
	}
	const float &V80_00::genmet_phi()
	{
		if (not genmet_phi_isLoaded) {
			if (genmet_phi_branch != 0) {
				genmet_phi_branch->GetEntry(index);
			} else { 
				printf("branch genmet_phi_branch does not exist!\n");
				exit(1);
			}
			genmet_phi_isLoaded = true;
		}
		return genmet_phi_;
	}
	const float &V80_00::genht()
	{
		if (not genht_isLoaded) {
			if (genht_branch != 0) {
				genht_branch->GetEntry(index);
			} else { 
				printf("branch genht_branch does not exist!\n");
				exit(1);
			}
			genht_isLoaded = true;
		}
		return genht_;
	}
	const bool &	V80_00::PassTrackVeto()
	{
		if (not PassTrackVeto_isLoaded) {
			if (PassTrackVeto_branch != 0) {
				PassTrackVeto_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_isLoaded = true;
		}
		return PassTrackVeto_;
	}
	const bool &	V80_00::PassTauVeto()
	{
		if (not PassTauVeto_isLoaded) {
			if (PassTauVeto_branch != 0) {
				PassTauVeto_branch->GetEntry(index);
			} else { 
				printf("branch PassTauVeto_branch does not exist!\n");
				exit(1);
			}
			PassTauVeto_isLoaded = true;
		}
		return PassTauVeto_;
	}
	const float &V80_00::topness()
	{
		if (not topness_isLoaded) {
			if (topness_branch != 0) {
				topness_branch->GetEntry(index);
			} else { 
				printf("branch topness_branch does not exist!\n");
				exit(1);
			}
			topness_isLoaded = true;
		}
		return topness_;
	}
	const float &V80_00::topnessMod()
	{
		if (not topnessMod_isLoaded) {
			if (topnessMod_branch != 0) {
				topnessMod_branch->GetEntry(index);
			} else { 
				printf("branch topnessMod_branch does not exist!\n");
				exit(1);
			}
			topnessMod_isLoaded = true;
		}
		return topnessMod_;
	}
	const float &V80_00::Mlb_closestb()
	{
		if (not Mlb_closestb_isLoaded) {
			if (Mlb_closestb_branch != 0) {
				Mlb_closestb_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_closestb_branch does not exist!\n");
				exit(1);
			}
			Mlb_closestb_isLoaded = true;
		}
		return Mlb_closestb_;
	}
	const int &V80_00::HLT_SingleEl()
	{
		if (not HLT_SingleEl_isLoaded) {
			if (HLT_SingleEl_branch != 0) {
				HLT_SingleEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl_isLoaded = true;
		}
		return HLT_SingleEl_;
	}
	const int &V80_00::HLT_SingleMu()
	{
		if (not HLT_SingleMu_isLoaded) {
			if (HLT_SingleMu_branch != 0) {
				HLT_SingleMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu_isLoaded = true;
		}
		return HLT_SingleMu_;
	}
	const int &V80_00::HLT_SingleMuNoIso()
	{
		if (not HLT_SingleMuNoIso_isLoaded) {
			if (HLT_SingleMuNoIso_branch != 0) {
				HLT_SingleMuNoIso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoIso_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoIso_isLoaded = true;
		}
		return HLT_SingleMuNoIso_;
	}
	const int &V80_00::HLT_SingleElNoIso()
	{
		if (not HLT_SingleElNoIso_isLoaded) {
			if (HLT_SingleElNoIso_branch != 0) {
				HLT_SingleElNoIso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleElNoIso_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleElNoIso_isLoaded = true;
		}
		return HLT_SingleElNoIso_;
	}
	const int &V80_00::HLT_MET()
	{
		if (not HLT_MET_isLoaded) {
			if (HLT_MET_branch != 0) {
				HLT_MET_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET_branch does not exist!\n");
				exit(1);
			}
			HLT_MET_isLoaded = true;
		}
		return HLT_MET_;
	}
	const int &V80_00::HLT_DiEl()
	{
		if (not HLT_DiEl_isLoaded) {
			if (HLT_DiEl_branch != 0) {
				HLT_DiEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiEl_branch does not exist!\n");
				exit(1);
			}
			HLT_DiEl_isLoaded = true;
		}
		return HLT_DiEl_;
	}
	const int &V80_00::HLT_DiMu()
	{
		if (not HLT_DiMu_isLoaded) {
			if (HLT_DiMu_branch != 0) {
				HLT_DiMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiMu_branch does not exist!\n");
				exit(1);
			}
			HLT_DiMu_isLoaded = true;
		}
		return HLT_DiMu_;
	}
	const int &V80_00::HLT_MuE()
	{
		if (not HLT_MuE_isLoaded) {
			if (HLT_MuE_branch != 0) {
				HLT_MuE_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MuE_branch does not exist!\n");
				exit(1);
			}
			HLT_MuE_isLoaded = true;
		}
		return HLT_MuE_;
	}
	const int &V80_00::HLT_Photon90_CaloIdL_PFHT500()
	{
		if (not HLT_Photon90_CaloIdL_PFHT500_isLoaded) {
			if (HLT_Photon90_CaloIdL_PFHT500_branch != 0) {
				HLT_Photon90_CaloIdL_PFHT500_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon90_CaloIdL_PFHT500_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon90_CaloIdL_PFHT500_isLoaded = true;
		}
		return HLT_Photon90_CaloIdL_PFHT500_;
	}
	const int &V80_00::HLT_Photon22_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon22_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon22_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon22_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon22_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon22_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon22_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon30_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon30_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon30_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon30_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon30_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon30_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon30_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon36_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon36_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon36_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon36_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon36_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon36_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon36_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon50_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon50_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon50_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon50_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon50_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon50_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon50_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon75_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon75_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon75_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon75_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon75_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon75_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon75_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon90_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon90_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon90_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon90_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon90_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon90_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon90_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon120_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon120_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon120_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon120_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon120_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon120_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon120_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon165_R9Id90_HE10_IsoM()
	{
		if (not HLT_Photon165_R9Id90_HE10_IsoM_isLoaded) {
			if (HLT_Photon165_R9Id90_HE10_IsoM_branch != 0) {
				HLT_Photon165_R9Id90_HE10_IsoM_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon165_R9Id90_HE10_IsoM_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon165_R9Id90_HE10_IsoM_isLoaded = true;
		}
		return HLT_Photon165_R9Id90_HE10_IsoM_;
	}
	const int &V80_00::HLT_Photon175()
	{
		if (not HLT_Photon175_isLoaded) {
			if (HLT_Photon175_branch != 0) {
				HLT_Photon175_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon175_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon175_isLoaded = true;
		}
		return HLT_Photon175_;
	}
	const int &V80_00::HLT_Photon165_HE10()
	{
		if (not HLT_Photon165_HE10_isLoaded) {
			if (HLT_Photon165_HE10_branch != 0) {
				HLT_Photon165_HE10_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Photon165_HE10_branch does not exist!\n");
				exit(1);
			}
			HLT_Photon165_HE10_isLoaded = true;
		}
		return HLT_Photon165_HE10_;
	}
	const int &V80_00::nPhotons()
	{
		if (not nPhotons_isLoaded) {
			if (nPhotons_branch != 0) {
				nPhotons_branch->GetEntry(index);
			} else { 
				printf("branch nPhotons_branch does not exist!\n");
				exit(1);
			}
			nPhotons_isLoaded = true;
		}
		return nPhotons_;
	}
	const int &V80_00::ph_ngoodjets()
	{
		if (not ph_ngoodjets_isLoaded) {
			if (ph_ngoodjets_branch != 0) {
				ph_ngoodjets_branch->GetEntry(index);
			} else { 
				printf("branch ph_ngoodjets_branch does not exist!\n");
				exit(1);
			}
			ph_ngoodjets_isLoaded = true;
		}
		return ph_ngoodjets_;
	}
	const int &V80_00::ph_ngoodbtags()
	{
		if (not ph_ngoodbtags_isLoaded) {
			if (ph_ngoodbtags_branch != 0) {
				ph_ngoodbtags_branch->GetEntry(index);
			} else { 
				printf("branch ph_ngoodbtags_branch does not exist!\n");
				exit(1);
			}
			ph_ngoodbtags_isLoaded = true;
		}
		return ph_ngoodbtags_;
	}
	const float &V80_00::filt_met()
	{
		if (not filt_met_isLoaded) {
			if (filt_met_branch != 0) {
				filt_met_branch->GetEntry(index);
			} else { 
				printf("branch filt_met_branch does not exist!\n");
				exit(1);
			}
			filt_met_isLoaded = true;
		}
		return filt_met_;
	}
	const float &V80_00::filt_badMuonFilter()
	{
		if (not filt_badMuonFilter_isLoaded) {
			if (filt_badMuonFilter_branch != 0) {
				filt_badMuonFilter_branch->GetEntry(index);
			} else { 
				printf("branch filt_badMuonFilter_branch does not exist!\n");
				exit(1);
			}
			filt_badMuonFilter_isLoaded = true;
		}
		return filt_badMuonFilter_;
	}
	const float &V80_00::filt_badChargedCandidateFilter()
	{
		if (not filt_badChargedCandidateFilter_isLoaded) {
			if (filt_badChargedCandidateFilter_branch != 0) {
				filt_badChargedCandidateFilter_branch->GetEntry(index);
			} else { 
				printf("branch filt_badChargedCandidateFilter_branch does not exist!\n");
				exit(1);
			}
			filt_badChargedCandidateFilter_isLoaded = true;
		}
		return filt_badChargedCandidateFilter_;
	}
	const float &V80_00::filt_cscbeamhalo2015()
	{
		if (not filt_cscbeamhalo2015_isLoaded) {
			if (filt_cscbeamhalo2015_branch != 0) {
				filt_cscbeamhalo2015_branch->GetEntry(index);
			} else { 
				printf("branch filt_cscbeamhalo2015_branch does not exist!\n");
				exit(1);
			}
			filt_cscbeamhalo2015_isLoaded = true;
		}
		return filt_cscbeamhalo2015_;
	}
	const float &V80_00::filt_cscbeamhalo()
	{
		if (not filt_cscbeamhalo_isLoaded) {
			if (filt_cscbeamhalo_branch != 0) {
				filt_cscbeamhalo_branch->GetEntry(index);
			} else { 
				printf("branch filt_cscbeamhalo_branch does not exist!\n");
				exit(1);
			}
			filt_cscbeamhalo_isLoaded = true;
		}
		return filt_cscbeamhalo_;
	}
	const float &V80_00::hardgenpt()
	{
		if (not hardgenpt_isLoaded) {
			if (hardgenpt_branch != 0) {
				hardgenpt_branch->GetEntry(index);
			} else { 
				printf("branch hardgenpt_branch does not exist!\n");
				exit(1);
			}
			hardgenpt_isLoaded = true;
		}
		return hardgenpt_;
	}
	const int &V80_00::lep1_pdgid()
	{
		if (not lep1_pdgid_isLoaded) {
			if (lep1_pdgid_branch != 0) {
				lep1_pdgid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_pdgid_branch does not exist!\n");
				exit(1);
			}
			lep1_pdgid_isLoaded = true;
		}
		return lep1_pdgid_;
	}
	const int &V80_00::lep1_production_type()
	{
		if (not lep1_production_type_isLoaded) {
			if (lep1_production_type_branch != 0) {
				lep1_production_type_branch->GetEntry(index);
			} else { 
				printf("branch lep1_production_type_branch does not exist!\n");
				exit(1);
			}
			lep1_production_type_isLoaded = true;
		}
		return lep1_production_type_;
	}
	const float &V80_00::lep1_MiniIso()
	{
		if (not lep1_MiniIso_isLoaded) {
			if (lep1_MiniIso_branch != 0) {
				lep1_MiniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_MiniIso_branch does not exist!\n");
				exit(1);
			}
			lep1_MiniIso_isLoaded = true;
		}
		return lep1_MiniIso_;
	}
	const float &V80_00::lep1_relIso()
	{
		if (not lep1_relIso_isLoaded) {
			if (lep1_relIso_branch != 0) {
				lep1_relIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso_isLoaded = true;
		}
		return lep1_relIso_;
	}
	const bool &	V80_00::lep1_passLooseID()
	{
		if (not lep1_passLooseID_isLoaded) {
			if (lep1_passLooseID_branch != 0) {
				lep1_passLooseID_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passLooseID_branch does not exist!\n");
				exit(1);
			}
			lep1_passLooseID_isLoaded = true;
		}
		return lep1_passLooseID_;
	}
	const bool &	V80_00::lep1_passMediumID()
	{
		if (not lep1_passMediumID_isLoaded) {
			if (lep1_passMediumID_branch != 0) {
				lep1_passMediumID_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passMediumID_branch does not exist!\n");
				exit(1);
			}
			lep1_passMediumID_isLoaded = true;
		}
		return lep1_passMediumID_;
	}
	const bool &	V80_00::lep1_passTightID()
	{
		if (not lep1_passTightID_isLoaded) {
			if (lep1_passTightID_branch != 0) {
				lep1_passTightID_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passTightID_branch does not exist!\n");
				exit(1);
			}
			lep1_passTightID_isLoaded = true;
		}
		return lep1_passTightID_;
	}
	const bool &	V80_00::lep1_passVeto()
	{
		if (not lep1_passVeto_isLoaded) {
			if (lep1_passVeto_branch != 0) {
				lep1_passVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passVeto_branch does not exist!\n");
				exit(1);
			}
			lep1_passVeto_isLoaded = true;
		}
		return lep1_passVeto_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::lep1_p4()
	{
		if (not lep1_p4_isLoaded) {
			if (lep1_p4_branch != 0) {
				lep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_p4_branch does not exist!\n");
				exit(1);
			}
			lep1_p4_isLoaded = true;
		}
		return *lep1_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::lep1_mcp4()
	{
		if (not lep1_mcp4_isLoaded) {
			if (lep1_mcp4_branch != 0) {
				lep1_mcp4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcp4_branch does not exist!\n");
				exit(1);
			}
			lep1_mcp4_isLoaded = true;
		}
		return *lep1_mcp4_;
	}
	const int &V80_00::lep1_mc_motherid()
	{
		if (not lep1_mc_motherid_isLoaded) {
			if (lep1_mc_motherid_branch != 0) {
				lep1_mc_motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc_motherid_branch does not exist!\n");
				exit(1);
			}
			lep1_mc_motherid_isLoaded = true;
		}
		return lep1_mc_motherid_;
	}
	const int &V80_00::lep2_pdgid()
	{
		if (not lep2_pdgid_isLoaded) {
			if (lep2_pdgid_branch != 0) {
				lep2_pdgid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_pdgid_branch does not exist!\n");
				exit(1);
			}
			lep2_pdgid_isLoaded = true;
		}
		return lep2_pdgid_;
	}
	const int &V80_00::lep2_production_type()
	{
		if (not lep2_production_type_isLoaded) {
			if (lep2_production_type_branch != 0) {
				lep2_production_type_branch->GetEntry(index);
			} else { 
				printf("branch lep2_production_type_branch does not exist!\n");
				exit(1);
			}
			lep2_production_type_isLoaded = true;
		}
		return lep2_production_type_;
	}
	const float &V80_00::lep2_MiniIso()
	{
		if (not lep2_MiniIso_isLoaded) {
			if (lep2_MiniIso_branch != 0) {
				lep2_MiniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_MiniIso_branch does not exist!\n");
				exit(1);
			}
			lep2_MiniIso_isLoaded = true;
		}
		return lep2_MiniIso_;
	}
	const float &V80_00::lep2_relIso()
	{
		if (not lep2_relIso_isLoaded) {
			if (lep2_relIso_branch != 0) {
				lep2_relIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso_isLoaded = true;
		}
		return lep2_relIso_;
	}
	const bool &	V80_00::lep2_passLooseID()
	{
		if (not lep2_passLooseID_isLoaded) {
			if (lep2_passLooseID_branch != 0) {
				lep2_passLooseID_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passLooseID_branch does not exist!\n");
				exit(1);
			}
			lep2_passLooseID_isLoaded = true;
		}
		return lep2_passLooseID_;
	}
	const bool &	V80_00::lep2_passMediumID()
	{
		if (not lep2_passMediumID_isLoaded) {
			if (lep2_passMediumID_branch != 0) {
				lep2_passMediumID_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passMediumID_branch does not exist!\n");
				exit(1);
			}
			lep2_passMediumID_isLoaded = true;
		}
		return lep2_passMediumID_;
	}
	const bool &	V80_00::lep2_passTightID()
	{
		if (not lep2_passTightID_isLoaded) {
			if (lep2_passTightID_branch != 0) {
				lep2_passTightID_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passTightID_branch does not exist!\n");
				exit(1);
			}
			lep2_passTightID_isLoaded = true;
		}
		return lep2_passTightID_;
	}
	const bool &	V80_00::lep2_passVeto()
	{
		if (not lep2_passVeto_isLoaded) {
			if (lep2_passVeto_branch != 0) {
				lep2_passVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passVeto_branch does not exist!\n");
				exit(1);
			}
			lep2_passVeto_isLoaded = true;
		}
		return lep2_passVeto_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::lep2_p4()
	{
		if (not lep2_p4_isLoaded) {
			if (lep2_p4_branch != 0) {
				lep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_p4_branch does not exist!\n");
				exit(1);
			}
			lep2_p4_isLoaded = true;
		}
		return *lep2_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::lep2_mcp4()
	{
		if (not lep2_mcp4_isLoaded) {
			if (lep2_mcp4_branch != 0) {
				lep2_mcp4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcp4_branch does not exist!\n");
				exit(1);
			}
			lep2_mcp4_isLoaded = true;
		}
		return *lep2_mcp4_;
	}
	const int &V80_00::lep2_mc_motherid()
	{
		if (not lep2_mc_motherid_isLoaded) {
			if (lep2_mc_motherid_branch != 0) {
				lep2_mc_motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc_motherid_branch does not exist!\n");
				exit(1);
			}
			lep2_mc_motherid_isLoaded = true;
		}
		return lep2_mc_motherid_;
	}
	const vector<float> &V80_00::ph_sigmaIEtaEta_fill5x5()
	{
		if (not ph_sigmaIEtaEta_fill5x5_isLoaded) {
			if (ph_sigmaIEtaEta_fill5x5_branch != 0) {
				ph_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
			} else { 
				printf("branch ph_sigmaIEtaEta_fill5x5_branch does not exist!\n");
				exit(1);
			}
			ph_sigmaIEtaEta_fill5x5_isLoaded = true;
		}
		return *ph_sigmaIEtaEta_fill5x5_;
	}
	const vector<float> &V80_00::ph_hOverE()
	{
		if (not ph_hOverE_isLoaded) {
			if (ph_hOverE_branch != 0) {
				ph_hOverE_branch->GetEntry(index);
			} else { 
				printf("branch ph_hOverE_branch does not exist!\n");
				exit(1);
			}
			ph_hOverE_isLoaded = true;
		}
		return *ph_hOverE_;
	}
	const vector<float> &V80_00::ph_r9()
	{
		if (not ph_r9_isLoaded) {
			if (ph_r9_branch != 0) {
				ph_r9_branch->GetEntry(index);
			} else { 
				printf("branch ph_r9_branch does not exist!\n");
				exit(1);
			}
			ph_r9_isLoaded = true;
		}
		return *ph_r9_;
	}
	const vector<float> &V80_00::ph_chiso()
	{
		if (not ph_chiso_isLoaded) {
			if (ph_chiso_branch != 0) {
				ph_chiso_branch->GetEntry(index);
			} else { 
				printf("branch ph_chiso_branch does not exist!\n");
				exit(1);
			}
			ph_chiso_isLoaded = true;
		}
		return *ph_chiso_;
	}
	const vector<float> &V80_00::ph_nhiso()
	{
		if (not ph_nhiso_isLoaded) {
			if (ph_nhiso_branch != 0) {
				ph_nhiso_branch->GetEntry(index);
			} else { 
				printf("branch ph_nhiso_branch does not exist!\n");
				exit(1);
			}
			ph_nhiso_isLoaded = true;
		}
		return *ph_nhiso_;
	}
	const vector<float> &V80_00::ph_phiso()
	{
		if (not ph_phiso_isLoaded) {
			if (ph_phiso_branch != 0) {
				ph_phiso_branch->GetEntry(index);
			} else { 
				printf("branch ph_phiso_branch does not exist!\n");
				exit(1);
			}
			ph_phiso_isLoaded = true;
		}
		return *ph_phiso_;
	}
	const vector<bool> &V80_00::ph_idCutBased()
	{
		if (not ph_idCutBased_isLoaded) {
			if (ph_idCutBased_branch != 0) {
				ph_idCutBased_branch->GetEntry(index);
			} else { 
				printf("branch ph_idCutBased_branch does not exist!\n");
				exit(1);
			}
			ph_idCutBased_isLoaded = true;
		}
		return *ph_idCutBased_;
	}
	const vector<int> &V80_00::ph_overlapJetId()
	{
		if (not ph_overlapJetId_isLoaded) {
			if (ph_overlapJetId_branch != 0) {
				ph_overlapJetId_branch->GetEntry(index);
			} else { 
				printf("branch ph_overlapJetId_branch does not exist!\n");
				exit(1);
			}
			ph_overlapJetId_isLoaded = true;
		}
		return *ph_overlapJetId_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::ph_p4()
	{
		if (not ph_p4_isLoaded) {
			if (ph_p4_branch != 0) {
				ph_p4_branch->GetEntry(index);
			} else { 
				printf("branch ph_p4_branch does not exist!\n");
				exit(1);
			}
			ph_p4_isLoaded = true;
		}
		return *ph_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::ph_mcp4()
	{
		if (not ph_mcp4_isLoaded) {
			if (ph_mcp4_branch != 0) {
				ph_mcp4_branch->GetEntry(index);
			} else { 
				printf("branch ph_mcp4_branch does not exist!\n");
				exit(1);
			}
			ph_mcp4_isLoaded = true;
		}
		return *ph_mcp4_;
	}
	const vector<float> &V80_00::ph_pt()
	{
		if (not ph_pt_isLoaded) {
			if (ph_pt_branch != 0) {
				ph_pt_branch->GetEntry(index);
			} else { 
				printf("branch ph_pt_branch does not exist!\n");
				exit(1);
			}
			ph_pt_isLoaded = true;
		}
		return *ph_pt_;
	}
	const vector<float> &V80_00::ph_eta()
	{
		if (not ph_eta_isLoaded) {
			if (ph_eta_branch != 0) {
				ph_eta_branch->GetEntry(index);
			} else { 
				printf("branch ph_eta_branch does not exist!\n");
				exit(1);
			}
			ph_eta_isLoaded = true;
		}
		return *ph_eta_;
	}
	const vector<float> &V80_00::ph_phi()
	{
		if (not ph_phi_isLoaded) {
			if (ph_phi_branch != 0) {
				ph_phi_branch->GetEntry(index);
			} else { 
				printf("branch ph_phi_branch does not exist!\n");
				exit(1);
			}
			ph_phi_isLoaded = true;
		}
		return *ph_phi_;
	}
	const vector<float> &V80_00::ph_mass()
	{
		if (not ph_mass_isLoaded) {
			if (ph_mass_branch != 0) {
				ph_mass_branch->GetEntry(index);
			} else { 
				printf("branch ph_mass_branch does not exist!\n");
				exit(1);
			}
			ph_mass_isLoaded = true;
		}
		return *ph_mass_;
	}
	const vector<int> &V80_00::ph_mcMatchId()
	{
		if (not ph_mcMatchId_isLoaded) {
			if (ph_mcMatchId_branch != 0) {
				ph_mcMatchId_branch->GetEntry(index);
			} else { 
				printf("branch ph_mcMatchId_branch does not exist!\n");
				exit(1);
			}
			ph_mcMatchId_isLoaded = true;
		}
		return *ph_mcMatchId_;
	}
	const vector<float> &V80_00::ph_genIso04()
	{
		if (not ph_genIso04_isLoaded) {
			if (ph_genIso04_branch != 0) {
				ph_genIso04_branch->GetEntry(index);
			} else { 
				printf("branch ph_genIso04_branch does not exist!\n");
				exit(1);
			}
			ph_genIso04_isLoaded = true;
		}
		return *ph_genIso04_;
	}
	const vector<float> &V80_00::ph_drMinParton()
	{
		if (not ph_drMinParton_isLoaded) {
			if (ph_drMinParton_branch != 0) {
				ph_drMinParton_branch->GetEntry(index);
			} else { 
				printf("branch ph_drMinParton_branch does not exist!\n");
				exit(1);
			}
			ph_drMinParton_isLoaded = true;
		}
		return *ph_drMinParton_;
	}
	const int &V80_00::ngoodjets()
	{
		if (not ngoodjets_isLoaded) {
			if (ngoodjets_branch != 0) {
				ngoodjets_branch->GetEntry(index);
			} else { 
				printf("branch ngoodjets_branch does not exist!\n");
				exit(1);
			}
			ngoodjets_isLoaded = true;
		}
		return ngoodjets_;
	}
	const int &V80_00::ngoodbtags()
	{
		if (not ngoodbtags_isLoaded) {
			if (ngoodbtags_branch != 0) {
				ngoodbtags_branch->GetEntry(index);
			} else { 
				printf("branch ngoodbtags_branch does not exist!\n");
				exit(1);
			}
			ngoodbtags_isLoaded = true;
		}
		return ngoodbtags_;
	}
	const float &V80_00::ak4_HT()
	{
		if (not ak4_HT_isLoaded) {
			if (ak4_HT_branch != 0) {
				ak4_HT_branch->GetEntry(index);
			} else { 
				printf("branch ak4_HT_branch does not exist!\n");
				exit(1);
			}
			ak4_HT_isLoaded = true;
		}
		return ak4_HT_;
	}
	const float &V80_00::ak4_htratiom()
	{
		if (not ak4_htratiom_isLoaded) {
			if (ak4_htratiom_branch != 0) {
				ak4_htratiom_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htratiom_branch does not exist!\n");
				exit(1);
			}
			ak4_htratiom_isLoaded = true;
		}
		return ak4_htratiom_;
	}
	const vector<float> &V80_00::dphi_ak4pfjet_met()
	{
		if (not dphi_ak4pfjet_met_isLoaded) {
			if (dphi_ak4pfjet_met_branch != 0) {
				dphi_ak4pfjet_met_branch->GetEntry(index);
			} else { 
				printf("branch dphi_ak4pfjet_met_branch does not exist!\n");
				exit(1);
			}
			dphi_ak4pfjet_met_isLoaded = true;
		}
		return *dphi_ak4pfjet_met_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::ak4pfjets_p4()
	{
		if (not ak4pfjets_p4_isLoaded) {
			if (ak4pfjets_p4_branch != 0) {
				ak4pfjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_p4_isLoaded = true;
		}
		return *ak4pfjets_p4_;
	}
	const vector<bool> &V80_00::ak4pfjets_passMEDbtag()
	{
		if (not ak4pfjets_passMEDbtag_isLoaded) {
			if (ak4pfjets_passMEDbtag_branch != 0) {
				ak4pfjets_passMEDbtag_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_passMEDbtag_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_passMEDbtag_isLoaded = true;
		}
		return *ak4pfjets_passMEDbtag_;
	}
	const vector<float> &V80_00::ak4pfjets_CSV()
	{
		if (not ak4pfjets_CSV_isLoaded) {
			if (ak4pfjets_CSV_branch != 0) {
				ak4pfjets_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_CSV_isLoaded = true;
		}
		return *ak4pfjets_CSV_;
	}
	const vector<float> &V80_00::ak4pfjets_mva()
	{
		if (not ak4pfjets_mva_isLoaded) {
			if (ak4pfjets_mva_branch != 0) {
				ak4pfjets_mva_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mva_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mva_isLoaded = true;
		}
		return *ak4pfjets_mva_;
	}
	const vector<int> &V80_00::ak4pfjets_parton_flavor()
	{
		if (not ak4pfjets_parton_flavor_isLoaded) {
			if (ak4pfjets_parton_flavor_branch != 0) {
				ak4pfjets_parton_flavor_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_parton_flavor_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_parton_flavor_isLoaded = true;
		}
		return *ak4pfjets_parton_flavor_;
	}
	const vector<int> &V80_00::ak4pfjets_hadron_flavor()
	{
		if (not ak4pfjets_hadron_flavor_isLoaded) {
			if (ak4pfjets_hadron_flavor_branch != 0) {
				ak4pfjets_hadron_flavor_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_hadron_flavor_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_hadron_flavor_isLoaded = true;
		}
		return *ak4pfjets_hadron_flavor_;
	}
	const vector<bool> &V80_00::ak4pfjets_loose_puid()
	{
		if (not ak4pfjets_loose_puid_isLoaded) {
			if (ak4pfjets_loose_puid_branch != 0) {
				ak4pfjets_loose_puid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_loose_puid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_loose_puid_isLoaded = true;
		}
		return *ak4pfjets_loose_puid_;
	}
	const vector<bool> &V80_00::ak4pfjets_loose_pfid()
	{
		if (not ak4pfjets_loose_pfid_isLoaded) {
			if (ak4pfjets_loose_pfid_branch != 0) {
				ak4pfjets_loose_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_loose_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_loose_pfid_isLoaded = true;
		}
		return *ak4pfjets_loose_pfid_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::ak4pfjets_leadMEDbjet_p4()
	{
		if (not ak4pfjets_leadMEDbjet_p4_isLoaded) {
			if (ak4pfjets_leadMEDbjet_p4_branch != 0) {
				ak4pfjets_leadMEDbjet_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadMEDbjet_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadMEDbjet_p4_isLoaded = true;
		}
		return *ak4pfjets_leadMEDbjet_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V80_00::ak4pfjets_leadbtag_p4()
	{
		if (not ak4pfjets_leadbtag_p4_isLoaded) {
			if (ak4pfjets_leadbtag_p4_branch != 0) {
				ak4pfjets_leadbtag_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadbtag_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadbtag_p4_isLoaded = true;
		}
		return *ak4pfjets_leadbtag_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::ak4genjets_p4()
	{
		if (not ak4genjets_p4_isLoaded) {
			if (ak4genjets_p4_branch != 0) {
				ak4genjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4genjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak4genjets_p4_isLoaded = true;
		}
		return *ak4genjets_p4_;
	}
	const vector<bool> &V80_00::genleps_isfromt()
	{
		if (not genleps_isfromt_isLoaded) {
			if (genleps_isfromt_branch != 0) {
				genleps_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genleps_isfromt_branch does not exist!\n");
				exit(1);
			}
			genleps_isfromt_isLoaded = true;
		}
		return *genleps_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genleps_p4()
	{
		if (not genleps_p4_isLoaded) {
			if (genleps_p4_branch != 0) {
				genleps_p4_branch->GetEntry(index);
			} else { 
				printf("branch genleps_p4_branch does not exist!\n");
				exit(1);
			}
			genleps_p4_isLoaded = true;
		}
		return *genleps_p4_;
	}
	const vector<int> &V80_00::genleps_id()
	{
		if (not genleps_id_isLoaded) {
			if (genleps_id_branch != 0) {
				genleps_id_branch->GetEntry(index);
			} else { 
				printf("branch genleps_id_branch does not exist!\n");
				exit(1);
			}
			genleps_id_isLoaded = true;
		}
		return *genleps_id_;
	}
	const vector<int> &V80_00::genleps__genpsidx()
	{
		if (not genleps__genpsidx_isLoaded) {
			if (genleps__genpsidx_branch != 0) {
				genleps__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genleps__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genleps__genpsidx_isLoaded = true;
		}
		return *genleps__genpsidx_;
	}
	const vector<int> &V80_00::genleps_status()
	{
		if (not genleps_status_isLoaded) {
			if (genleps_status_branch != 0) {
				genleps_status_branch->GetEntry(index);
			} else { 
				printf("branch genleps_status_branch does not exist!\n");
				exit(1);
			}
			genleps_status_isLoaded = true;
		}
		return *genleps_status_;
	}
	const vector<bool> &V80_00::genleps_fromHardProcessDecayed()
	{
		if (not genleps_fromHardProcessDecayed_isLoaded) {
			if (genleps_fromHardProcessDecayed_branch != 0) {
				genleps_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genleps_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genleps_fromHardProcessDecayed_isLoaded = true;
		}
		return *genleps_fromHardProcessDecayed_;
	}
	const vector<bool> &V80_00::genleps_fromHardProcessFinalState()
	{
		if (not genleps_fromHardProcessFinalState_isLoaded) {
			if (genleps_fromHardProcessFinalState_branch != 0) {
				genleps_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genleps_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genleps_fromHardProcessFinalState_isLoaded = true;
		}
		return *genleps_fromHardProcessFinalState_;
	}
	const vector<bool> &V80_00::genleps_isHardProcess()
	{
		if (not genleps_isHardProcess_isLoaded) {
			if (genleps_isHardProcess_branch != 0) {
				genleps_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genleps_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genleps_isHardProcess_isLoaded = true;
		}
		return *genleps_isHardProcess_;
	}
	const vector<bool> &V80_00::genleps_isLastCopy()
	{
		if (not genleps_isLastCopy_isLoaded) {
			if (genleps_isLastCopy_branch != 0) {
				genleps_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genleps_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genleps_isLastCopy_isLoaded = true;
		}
		return *genleps_isLastCopy_;
	}
	const vector<int> &V80_00::genleps_gentaudecay()
	{
		if (not genleps_gentaudecay_isLoaded) {
			if (genleps_gentaudecay_branch != 0) {
				genleps_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genleps_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genleps_gentaudecay_isLoaded = true;
		}
		return *genleps_gentaudecay_;
	}
	const int &V80_00::gen_nfromtleps_()
	{
		if (not gen_nfromtleps__isLoaded) {
			if (gen_nfromtleps__branch != 0) {
				gen_nfromtleps__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtleps__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtleps__isLoaded = true;
		}
		return gen_nfromtleps__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genleps_motherp4()
	{
		if (not genleps_motherp4_isLoaded) {
			if (genleps_motherp4_branch != 0) {
				genleps_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genleps_motherp4_branch does not exist!\n");
				exit(1);
			}
			genleps_motherp4_isLoaded = true;
		}
		return *genleps_motherp4_;
	}
	const vector<int> &V80_00::genleps_motherid()
	{
		if (not genleps_motherid_isLoaded) {
			if (genleps_motherid_branch != 0) {
				genleps_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genleps_motherid_branch does not exist!\n");
				exit(1);
			}
			genleps_motherid_isLoaded = true;
		}
		return *genleps_motherid_;
	}
	const vector<int> &V80_00::genleps_motheridx()
	{
		if (not genleps_motheridx_isLoaded) {
			if (genleps_motheridx_branch != 0) {
				genleps_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genleps_motheridx_branch does not exist!\n");
				exit(1);
			}
			genleps_motheridx_isLoaded = true;
		}
		return *genleps_motheridx_;
	}
	const vector<int> &V80_00::genleps_motherstatus()
	{
		if (not genleps_motherstatus_isLoaded) {
			if (genleps_motherstatus_branch != 0) {
				genleps_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genleps_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genleps_motherstatus_isLoaded = true;
		}
		return *genleps_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genleps_gmotherp4()
	{
		if (not genleps_gmotherp4_isLoaded) {
			if (genleps_gmotherp4_branch != 0) {
				genleps_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genleps_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genleps_gmotherp4_isLoaded = true;
		}
		return *genleps_gmotherp4_;
	}
	const vector<int> &V80_00::genleps_gmotherid()
	{
		if (not genleps_gmotherid_isLoaded) {
			if (genleps_gmotherid_branch != 0) {
				genleps_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genleps_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genleps_gmotherid_isLoaded = true;
		}
		return *genleps_gmotherid_;
	}
	const vector<int> &V80_00::genleps_gmotheridx()
	{
		if (not genleps_gmotheridx_isLoaded) {
			if (genleps_gmotheridx_branch != 0) {
				genleps_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genleps_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genleps_gmotheridx_isLoaded = true;
		}
		return *genleps_gmotheridx_;
	}
	const vector<int> &V80_00::genleps_gmotherstatus()
	{
		if (not genleps_gmotherstatus_isLoaded) {
			if (genleps_gmotherstatus_branch != 0) {
				genleps_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genleps_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genleps_gmotherstatus_isLoaded = true;
		}
		return *genleps_gmotherstatus_;
	}
	const vector<bool> &V80_00::gennus_isfromt()
	{
		if (not gennus_isfromt_isLoaded) {
			if (gennus_isfromt_branch != 0) {
				gennus_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gennus_isfromt_branch does not exist!\n");
				exit(1);
			}
			gennus_isfromt_isLoaded = true;
		}
		return *gennus_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gennus_p4()
	{
		if (not gennus_p4_isLoaded) {
			if (gennus_p4_branch != 0) {
				gennus_p4_branch->GetEntry(index);
			} else { 
				printf("branch gennus_p4_branch does not exist!\n");
				exit(1);
			}
			gennus_p4_isLoaded = true;
		}
		return *gennus_p4_;
	}
	const vector<int> &V80_00::gennus_id()
	{
		if (not gennus_id_isLoaded) {
			if (gennus_id_branch != 0) {
				gennus_id_branch->GetEntry(index);
			} else { 
				printf("branch gennus_id_branch does not exist!\n");
				exit(1);
			}
			gennus_id_isLoaded = true;
		}
		return *gennus_id_;
	}
	const vector<int> &V80_00::gennus__genpsidx()
	{
		if (not gennus__genpsidx_isLoaded) {
			if (gennus__genpsidx_branch != 0) {
				gennus__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gennus__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gennus__genpsidx_isLoaded = true;
		}
		return *gennus__genpsidx_;
	}
	const vector<int> &V80_00::gennus_status()
	{
		if (not gennus_status_isLoaded) {
			if (gennus_status_branch != 0) {
				gennus_status_branch->GetEntry(index);
			} else { 
				printf("branch gennus_status_branch does not exist!\n");
				exit(1);
			}
			gennus_status_isLoaded = true;
		}
		return *gennus_status_;
	}
	const vector<bool> &V80_00::gennus_fromHardProcessDecayed()
	{
		if (not gennus_fromHardProcessDecayed_isLoaded) {
			if (gennus_fromHardProcessDecayed_branch != 0) {
				gennus_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gennus_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gennus_fromHardProcessDecayed_isLoaded = true;
		}
		return *gennus_fromHardProcessDecayed_;
	}
	const vector<bool> &V80_00::gennus_fromHardProcessFinalState()
	{
		if (not gennus_fromHardProcessFinalState_isLoaded) {
			if (gennus_fromHardProcessFinalState_branch != 0) {
				gennus_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gennus_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gennus_fromHardProcessFinalState_isLoaded = true;
		}
		return *gennus_fromHardProcessFinalState_;
	}
	const vector<bool> &V80_00::gennus_isHardProcess()
	{
		if (not gennus_isHardProcess_isLoaded) {
			if (gennus_isHardProcess_branch != 0) {
				gennus_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gennus_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gennus_isHardProcess_isLoaded = true;
		}
		return *gennus_isHardProcess_;
	}
	const vector<bool> &V80_00::gennus_isLastCopy()
	{
		if (not gennus_isLastCopy_isLoaded) {
			if (gennus_isLastCopy_branch != 0) {
				gennus_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gennus_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gennus_isLastCopy_isLoaded = true;
		}
		return *gennus_isLastCopy_;
	}
	const vector<int> &V80_00::gennus_gentaudecay()
	{
		if (not gennus_gentaudecay_isLoaded) {
			if (gennus_gentaudecay_branch != 0) {
				gennus_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gennus_gentaudecay_isLoaded = true;
		}
		return *gennus_gentaudecay_;
	}
	const int &V80_00::gen_nfromtnus_()
	{
		if (not gen_nfromtnus__isLoaded) {
			if (gen_nfromtnus__branch != 0) {
				gen_nfromtnus__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtnus__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtnus__isLoaded = true;
		}
		return gen_nfromtnus__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gennus_motherp4()
	{
		if (not gennus_motherp4_isLoaded) {
			if (gennus_motherp4_branch != 0) {
				gennus_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherp4_branch does not exist!\n");
				exit(1);
			}
			gennus_motherp4_isLoaded = true;
		}
		return *gennus_motherp4_;
	}
	const vector<int> &V80_00::gennus_motherid()
	{
		if (not gennus_motherid_isLoaded) {
			if (gennus_motherid_branch != 0) {
				gennus_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherid_branch does not exist!\n");
				exit(1);
			}
			gennus_motherid_isLoaded = true;
		}
		return *gennus_motherid_;
	}
	const vector<int> &V80_00::gennus_motheridx()
	{
		if (not gennus_motheridx_isLoaded) {
			if (gennus_motheridx_branch != 0) {
				gennus_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motheridx_branch does not exist!\n");
				exit(1);
			}
			gennus_motheridx_isLoaded = true;
		}
		return *gennus_motheridx_;
	}
	const vector<int> &V80_00::gennus_motherstatus()
	{
		if (not gennus_motherstatus_isLoaded) {
			if (gennus_motherstatus_branch != 0) {
				gennus_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennus_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gennus_motherstatus_isLoaded = true;
		}
		return *gennus_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gennus_gmotherp4()
	{
		if (not gennus_gmotherp4_isLoaded) {
			if (gennus_gmotherp4_branch != 0) {
				gennus_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gennus_gmotherp4_isLoaded = true;
		}
		return *gennus_gmotherp4_;
	}
	const vector<int> &V80_00::gennus_gmotherid()
	{
		if (not gennus_gmotherid_isLoaded) {
			if (gennus_gmotherid_branch != 0) {
				gennus_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gennus_gmotherid_isLoaded = true;
		}
		return *gennus_gmotherid_;
	}
	const vector<int> &V80_00::gennus_gmotheridx()
	{
		if (not gennus_gmotheridx_isLoaded) {
			if (gennus_gmotheridx_branch != 0) {
				gennus_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gennus_gmotheridx_isLoaded = true;
		}
		return *gennus_gmotheridx_;
	}
	const vector<int> &V80_00::gennus_gmotherstatus()
	{
		if (not gennus_gmotherstatus_isLoaded) {
			if (gennus_gmotherstatus_branch != 0) {
				gennus_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gennus_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gennus_gmotherstatus_isLoaded = true;
		}
		return *gennus_gmotherstatus_;
	}
	const vector<bool> &V80_00::genqs_isfromt()
	{
		if (not genqs_isfromt_isLoaded) {
			if (genqs_isfromt_branch != 0) {
				genqs_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isfromt_branch does not exist!\n");
				exit(1);
			}
			genqs_isfromt_isLoaded = true;
		}
		return *genqs_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genqs_p4()
	{
		if (not genqs_p4_isLoaded) {
			if (genqs_p4_branch != 0) {
				genqs_p4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_p4_branch does not exist!\n");
				exit(1);
			}
			genqs_p4_isLoaded = true;
		}
		return *genqs_p4_;
	}
	const vector<int> &V80_00::genqs_id()
	{
		if (not genqs_id_isLoaded) {
			if (genqs_id_branch != 0) {
				genqs_id_branch->GetEntry(index);
			} else { 
				printf("branch genqs_id_branch does not exist!\n");
				exit(1);
			}
			genqs_id_isLoaded = true;
		}
		return *genqs_id_;
	}
	const vector<int> &V80_00::genqs__genpsidx()
	{
		if (not genqs__genpsidx_isLoaded) {
			if (genqs__genpsidx_branch != 0) {
				genqs__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genqs__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genqs__genpsidx_isLoaded = true;
		}
		return *genqs__genpsidx_;
	}
	const vector<int> &V80_00::genqs_status()
	{
		if (not genqs_status_isLoaded) {
			if (genqs_status_branch != 0) {
				genqs_status_branch->GetEntry(index);
			} else { 
				printf("branch genqs_status_branch does not exist!\n");
				exit(1);
			}
			genqs_status_isLoaded = true;
		}
		return *genqs_status_;
	}
	const vector<bool> &V80_00::genqs_fromHardProcessDecayed()
	{
		if (not genqs_fromHardProcessDecayed_isLoaded) {
			if (genqs_fromHardProcessDecayed_branch != 0) {
				genqs_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genqs_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genqs_fromHardProcessDecayed_isLoaded = true;
		}
		return *genqs_fromHardProcessDecayed_;
	}
	const vector<bool> &V80_00::genqs_fromHardProcessFinalState()
	{
		if (not genqs_fromHardProcessFinalState_isLoaded) {
			if (genqs_fromHardProcessFinalState_branch != 0) {
				genqs_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genqs_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genqs_fromHardProcessFinalState_isLoaded = true;
		}
		return *genqs_fromHardProcessFinalState_;
	}
	const vector<bool> &V80_00::genqs_isHardProcess()
	{
		if (not genqs_isHardProcess_isLoaded) {
			if (genqs_isHardProcess_branch != 0) {
				genqs_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genqs_isHardProcess_isLoaded = true;
		}
		return *genqs_isHardProcess_;
	}
	const vector<bool> &V80_00::genqs_isLastCopy()
	{
		if (not genqs_isLastCopy_isLoaded) {
			if (genqs_isLastCopy_branch != 0) {
				genqs_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genqs_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genqs_isLastCopy_isLoaded = true;
		}
		return *genqs_isLastCopy_;
	}
	const vector<int> &V80_00::genqs_gentaudecay()
	{
		if (not genqs_gentaudecay_isLoaded) {
			if (genqs_gentaudecay_branch != 0) {
				genqs_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genqs_gentaudecay_isLoaded = true;
		}
		return *genqs_gentaudecay_;
	}
	const int &V80_00::gen_nfromtqs_()
	{
		if (not gen_nfromtqs__isLoaded) {
			if (gen_nfromtqs__branch != 0) {
				gen_nfromtqs__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtqs__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtqs__isLoaded = true;
		}
		return gen_nfromtqs__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genqs_motherp4()
	{
		if (not genqs_motherp4_isLoaded) {
			if (genqs_motherp4_branch != 0) {
				genqs_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_motherp4_isLoaded = true;
		}
		return *genqs_motherp4_;
	}
	const vector<int> &V80_00::genqs_motherid()
	{
		if (not genqs_motherid_isLoaded) {
			if (genqs_motherid_branch != 0) {
				genqs_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherid_branch does not exist!\n");
				exit(1);
			}
			genqs_motherid_isLoaded = true;
		}
		return *genqs_motherid_;
	}
	const vector<int> &V80_00::genqs_motheridx()
	{
		if (not genqs_motheridx_isLoaded) {
			if (genqs_motheridx_branch != 0) {
				genqs_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_motheridx_isLoaded = true;
		}
		return *genqs_motheridx_;
	}
	const vector<int> &V80_00::genqs_motherstatus()
	{
		if (not genqs_motherstatus_isLoaded) {
			if (genqs_motherstatus_branch != 0) {
				genqs_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_motherstatus_isLoaded = true;
		}
		return *genqs_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genqs_gmotherp4()
	{
		if (not genqs_gmotherp4_isLoaded) {
			if (genqs_gmotherp4_branch != 0) {
				genqs_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherp4_isLoaded = true;
		}
		return *genqs_gmotherp4_;
	}
	const vector<int> &V80_00::genqs_gmotherid()
	{
		if (not genqs_gmotherid_isLoaded) {
			if (genqs_gmotherid_branch != 0) {
				genqs_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherid_isLoaded = true;
		}
		return *genqs_gmotherid_;
	}
	const vector<int> &V80_00::genqs_gmotheridx()
	{
		if (not genqs_gmotheridx_isLoaded) {
			if (genqs_gmotheridx_branch != 0) {
				genqs_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotheridx_isLoaded = true;
		}
		return *genqs_gmotheridx_;
	}
	const vector<int> &V80_00::genqs_gmotherstatus()
	{
		if (not genqs_gmotherstatus_isLoaded) {
			if (genqs_gmotherstatus_branch != 0) {
				genqs_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genqs_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genqs_gmotherstatus_isLoaded = true;
		}
		return *genqs_gmotherstatus_;
	}
	const vector<bool> &V80_00::genbosons_isfromt()
	{
		if (not genbosons_isfromt_isLoaded) {
			if (genbosons_isfromt_branch != 0) {
				genbosons_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_isfromt_branch does not exist!\n");
				exit(1);
			}
			genbosons_isfromt_isLoaded = true;
		}
		return *genbosons_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genbosons_p4()
	{
		if (not genbosons_p4_isLoaded) {
			if (genbosons_p4_branch != 0) {
				genbosons_p4_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_p4_branch does not exist!\n");
				exit(1);
			}
			genbosons_p4_isLoaded = true;
		}
		return *genbosons_p4_;
	}
	const vector<int> &V80_00::genbosons_id()
	{
		if (not genbosons_id_isLoaded) {
			if (genbosons_id_branch != 0) {
				genbosons_id_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_id_branch does not exist!\n");
				exit(1);
			}
			genbosons_id_isLoaded = true;
		}
		return *genbosons_id_;
	}
	const vector<int> &V80_00::genbosons__genpsidx()
	{
		if (not genbosons__genpsidx_isLoaded) {
			if (genbosons__genpsidx_branch != 0) {
				genbosons__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch genbosons__genpsidx_branch does not exist!\n");
				exit(1);
			}
			genbosons__genpsidx_isLoaded = true;
		}
		return *genbosons__genpsidx_;
	}
	const vector<int> &V80_00::genbosons_status()
	{
		if (not genbosons_status_isLoaded) {
			if (genbosons_status_branch != 0) {
				genbosons_status_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_status_branch does not exist!\n");
				exit(1);
			}
			genbosons_status_isLoaded = true;
		}
		return *genbosons_status_;
	}
	const vector<bool> &V80_00::genbosons_fromHardProcessDecayed()
	{
		if (not genbosons_fromHardProcessDecayed_isLoaded) {
			if (genbosons_fromHardProcessDecayed_branch != 0) {
				genbosons_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			genbosons_fromHardProcessDecayed_isLoaded = true;
		}
		return *genbosons_fromHardProcessDecayed_;
	}
	const vector<bool> &V80_00::genbosons_fromHardProcessFinalState()
	{
		if (not genbosons_fromHardProcessFinalState_isLoaded) {
			if (genbosons_fromHardProcessFinalState_branch != 0) {
				genbosons_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			genbosons_fromHardProcessFinalState_isLoaded = true;
		}
		return *genbosons_fromHardProcessFinalState_;
	}
	const vector<bool> &V80_00::genbosons_isHardProcess()
	{
		if (not genbosons_isHardProcess_isLoaded) {
			if (genbosons_isHardProcess_branch != 0) {
				genbosons_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			genbosons_isHardProcess_isLoaded = true;
		}
		return *genbosons_isHardProcess_;
	}
	const vector<bool> &V80_00::genbosons_isLastCopy()
	{
		if (not genbosons_isLastCopy_isLoaded) {
			if (genbosons_isLastCopy_branch != 0) {
				genbosons_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			genbosons_isLastCopy_isLoaded = true;
		}
		return *genbosons_isLastCopy_;
	}
	const vector<int> &V80_00::genbosons_gentaudecay()
	{
		if (not genbosons_gentaudecay_isLoaded) {
			if (genbosons_gentaudecay_branch != 0) {
				genbosons_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			genbosons_gentaudecay_isLoaded = true;
		}
		return *genbosons_gentaudecay_;
	}
	const int &V80_00::gen_nfromtbosons_()
	{
		if (not gen_nfromtbosons__isLoaded) {
			if (gen_nfromtbosons__branch != 0) {
				gen_nfromtbosons__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtbosons__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtbosons__isLoaded = true;
		}
		return gen_nfromtbosons__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genbosons_motherp4()
	{
		if (not genbosons_motherp4_isLoaded) {
			if (genbosons_motherp4_branch != 0) {
				genbosons_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_motherp4_branch does not exist!\n");
				exit(1);
			}
			genbosons_motherp4_isLoaded = true;
		}
		return *genbosons_motherp4_;
	}
	const vector<int> &V80_00::genbosons_motherid()
	{
		if (not genbosons_motherid_isLoaded) {
			if (genbosons_motherid_branch != 0) {
				genbosons_motherid_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_motherid_branch does not exist!\n");
				exit(1);
			}
			genbosons_motherid_isLoaded = true;
		}
		return *genbosons_motherid_;
	}
	const vector<int> &V80_00::genbosons_motheridx()
	{
		if (not genbosons_motheridx_isLoaded) {
			if (genbosons_motheridx_branch != 0) {
				genbosons_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_motheridx_branch does not exist!\n");
				exit(1);
			}
			genbosons_motheridx_isLoaded = true;
		}
		return *genbosons_motheridx_;
	}
	const vector<int> &V80_00::genbosons_motherstatus()
	{
		if (not genbosons_motherstatus_isLoaded) {
			if (genbosons_motherstatus_branch != 0) {
				genbosons_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_motherstatus_branch does not exist!\n");
				exit(1);
			}
			genbosons_motherstatus_isLoaded = true;
		}
		return *genbosons_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::genbosons_gmotherp4()
	{
		if (not genbosons_gmotherp4_isLoaded) {
			if (genbosons_gmotherp4_branch != 0) {
				genbosons_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			genbosons_gmotherp4_isLoaded = true;
		}
		return *genbosons_gmotherp4_;
	}
	const vector<int> &V80_00::genbosons_gmotherid()
	{
		if (not genbosons_gmotherid_isLoaded) {
			if (genbosons_gmotherid_branch != 0) {
				genbosons_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_gmotherid_branch does not exist!\n");
				exit(1);
			}
			genbosons_gmotherid_isLoaded = true;
		}
		return *genbosons_gmotherid_;
	}
	const vector<int> &V80_00::genbosons_gmotheridx()
	{
		if (not genbosons_gmotheridx_isLoaded) {
			if (genbosons_gmotheridx_branch != 0) {
				genbosons_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			genbosons_gmotheridx_isLoaded = true;
		}
		return *genbosons_gmotheridx_;
	}
	const vector<int> &V80_00::genbosons_gmotherstatus()
	{
		if (not genbosons_gmotherstatus_isLoaded) {
			if (genbosons_gmotherstatus_branch != 0) {
				genbosons_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch genbosons_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			genbosons_gmotherstatus_isLoaded = true;
		}
		return *genbosons_gmotherstatus_;
	}
	const vector<bool> &V80_00::gensusy_isfromt()
	{
		if (not gensusy_isfromt_isLoaded) {
			if (gensusy_isfromt_branch != 0) {
				gensusy_isfromt_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_isfromt_branch does not exist!\n");
				exit(1);
			}
			gensusy_isfromt_isLoaded = true;
		}
		return *gensusy_isfromt_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gensusy_p4()
	{
		if (not gensusy_p4_isLoaded) {
			if (gensusy_p4_branch != 0) {
				gensusy_p4_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_p4_branch does not exist!\n");
				exit(1);
			}
			gensusy_p4_isLoaded = true;
		}
		return *gensusy_p4_;
	}
	const vector<int> &V80_00::gensusy_id()
	{
		if (not gensusy_id_isLoaded) {
			if (gensusy_id_branch != 0) {
				gensusy_id_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_id_branch does not exist!\n");
				exit(1);
			}
			gensusy_id_isLoaded = true;
		}
		return *gensusy_id_;
	}
	const vector<int> &V80_00::gensusy__genpsidx()
	{
		if (not gensusy__genpsidx_isLoaded) {
			if (gensusy__genpsidx_branch != 0) {
				gensusy__genpsidx_branch->GetEntry(index);
			} else { 
				printf("branch gensusy__genpsidx_branch does not exist!\n");
				exit(1);
			}
			gensusy__genpsidx_isLoaded = true;
		}
		return *gensusy__genpsidx_;
	}
	const vector<int> &V80_00::gensusy_status()
	{
		if (not gensusy_status_isLoaded) {
			if (gensusy_status_branch != 0) {
				gensusy_status_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_status_branch does not exist!\n");
				exit(1);
			}
			gensusy_status_isLoaded = true;
		}
		return *gensusy_status_;
	}
	const vector<bool> &V80_00::gensusy_fromHardProcessDecayed()
	{
		if (not gensusy_fromHardProcessDecayed_isLoaded) {
			if (gensusy_fromHardProcessDecayed_branch != 0) {
				gensusy_fromHardProcessDecayed_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_fromHardProcessDecayed_branch does not exist!\n");
				exit(1);
			}
			gensusy_fromHardProcessDecayed_isLoaded = true;
		}
		return *gensusy_fromHardProcessDecayed_;
	}
	const vector<bool> &V80_00::gensusy_fromHardProcessFinalState()
	{
		if (not gensusy_fromHardProcessFinalState_isLoaded) {
			if (gensusy_fromHardProcessFinalState_branch != 0) {
				gensusy_fromHardProcessFinalState_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_fromHardProcessFinalState_branch does not exist!\n");
				exit(1);
			}
			gensusy_fromHardProcessFinalState_isLoaded = true;
		}
		return *gensusy_fromHardProcessFinalState_;
	}
	const vector<bool> &V80_00::gensusy_isHardProcess()
	{
		if (not gensusy_isHardProcess_isLoaded) {
			if (gensusy_isHardProcess_branch != 0) {
				gensusy_isHardProcess_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_isHardProcess_branch does not exist!\n");
				exit(1);
			}
			gensusy_isHardProcess_isLoaded = true;
		}
		return *gensusy_isHardProcess_;
	}
	const vector<bool> &V80_00::gensusy_isLastCopy()
	{
		if (not gensusy_isLastCopy_isLoaded) {
			if (gensusy_isLastCopy_branch != 0) {
				gensusy_isLastCopy_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_isLastCopy_branch does not exist!\n");
				exit(1);
			}
			gensusy_isLastCopy_isLoaded = true;
		}
		return *gensusy_isLastCopy_;
	}
	const vector<int> &V80_00::gensusy_gentaudecay()
	{
		if (not gensusy_gentaudecay_isLoaded) {
			if (gensusy_gentaudecay_branch != 0) {
				gensusy_gentaudecay_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_gentaudecay_branch does not exist!\n");
				exit(1);
			}
			gensusy_gentaudecay_isLoaded = true;
		}
		return *gensusy_gentaudecay_;
	}
	const int &V80_00::gen_nfromtsusy_()
	{
		if (not gen_nfromtsusy__isLoaded) {
			if (gen_nfromtsusy__branch != 0) {
				gen_nfromtsusy__branch->GetEntry(index);
			} else { 
				printf("branch gen_nfromtsusy__branch does not exist!\n");
				exit(1);
			}
			gen_nfromtsusy__isLoaded = true;
		}
		return gen_nfromtsusy__;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gensusy_motherp4()
	{
		if (not gensusy_motherp4_isLoaded) {
			if (gensusy_motherp4_branch != 0) {
				gensusy_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_motherp4_branch does not exist!\n");
				exit(1);
			}
			gensusy_motherp4_isLoaded = true;
		}
		return *gensusy_motherp4_;
	}
	const vector<int> &V80_00::gensusy_motherid()
	{
		if (not gensusy_motherid_isLoaded) {
			if (gensusy_motherid_branch != 0) {
				gensusy_motherid_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_motherid_branch does not exist!\n");
				exit(1);
			}
			gensusy_motherid_isLoaded = true;
		}
		return *gensusy_motherid_;
	}
	const vector<int> &V80_00::gensusy_motheridx()
	{
		if (not gensusy_motheridx_isLoaded) {
			if (gensusy_motheridx_branch != 0) {
				gensusy_motheridx_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_motheridx_branch does not exist!\n");
				exit(1);
			}
			gensusy_motheridx_isLoaded = true;
		}
		return *gensusy_motheridx_;
	}
	const vector<int> &V80_00::gensusy_motherstatus()
	{
		if (not gensusy_motherstatus_isLoaded) {
			if (gensusy_motherstatus_branch != 0) {
				gensusy_motherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_motherstatus_branch does not exist!\n");
				exit(1);
			}
			gensusy_motherstatus_isLoaded = true;
		}
		return *gensusy_motherstatus_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V80_00::gensusy_gmotherp4()
	{
		if (not gensusy_gmotherp4_isLoaded) {
			if (gensusy_gmotherp4_branch != 0) {
				gensusy_gmotherp4_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_gmotherp4_branch does not exist!\n");
				exit(1);
			}
			gensusy_gmotherp4_isLoaded = true;
		}
		return *gensusy_gmotherp4_;
	}
	const vector<int> &V80_00::gensusy_gmotherid()
	{
		if (not gensusy_gmotherid_isLoaded) {
			if (gensusy_gmotherid_branch != 0) {
				gensusy_gmotherid_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_gmotherid_branch does not exist!\n");
				exit(1);
			}
			gensusy_gmotherid_isLoaded = true;
		}
		return *gensusy_gmotherid_;
	}
	const vector<int> &V80_00::gensusy_gmotheridx()
	{
		if (not gensusy_gmotheridx_isLoaded) {
			if (gensusy_gmotheridx_branch != 0) {
				gensusy_gmotheridx_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_gmotheridx_branch does not exist!\n");
				exit(1);
			}
			gensusy_gmotheridx_isLoaded = true;
		}
		return *gensusy_gmotheridx_;
	}
	const vector<int> &V80_00::gensusy_gmotherstatus()
	{
		if (not gensusy_gmotherstatus_isLoaded) {
			if (gensusy_gmotherstatus_branch != 0) {
				gensusy_gmotherstatus_branch->GetEntry(index);
			} else { 
				printf("branch gensusy_gmotherstatus_branch does not exist!\n");
				exit(1);
			}
			gensusy_gmotherstatus_isLoaded = true;
		}
		return *gensusy_gmotherstatus_;
	}

  void V80_00::progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
namespace V80_00_np {
	const unsigned int &run() { return v80_00.run(); }
	const unsigned int &ls() { return v80_00.ls(); }
	const unsigned int &evt() { return v80_00.evt(); }
	const int &nvtxs() { return v80_00.nvtxs(); }
	const int &pu_nvtxs() { return v80_00.pu_nvtxs(); }
	const float &pfmet() { return v80_00.pfmet(); }
	const float &pfmet_phi() { return v80_00.pfmet_phi(); }
	const float &scale1fb() { return v80_00.scale1fb(); }
	const float &xsec() { return v80_00.xsec(); }
	const float &xsec_uncert() { return v80_00.xsec_uncert(); }
	const float &kfactor() { return v80_00.kfactor(); }
	const float &pu_ntrue() { return v80_00.pu_ntrue(); }
	const int &ngoodleps() { return v80_00.ngoodleps(); }
	const int &nvetoleps() { return v80_00.nvetoleps(); }
	const bool &is_data() { return v80_00.is_data(); }
	const string &dataset() { return v80_00.dataset(); }
	const string &filename() { return v80_00.filename(); }
	const string &cms3tag() { return v80_00.cms3tag(); }
	const unsigned int &nEvents() { return v80_00.nEvents(); }
	const unsigned int &nEvents_goodvtx() { return v80_00.nEvents_goodvtx(); }
	const unsigned int &nEvents_MET30() { return v80_00.nEvents_MET30(); }
	const unsigned int &nEvents_1goodlep() { return v80_00.nEvents_1goodlep(); }
	const unsigned int &nEvents_2goodjets() { return v80_00.nEvents_2goodjets(); }
	const int &is0lep() { return v80_00.is0lep(); }
	const int &is1lep() { return v80_00.is1lep(); }
	const int &is2lep() { return v80_00.is2lep(); }
	const int &isZtoNuNu() { return v80_00.isZtoNuNu(); }
	const int &is1lepFromW() { return v80_00.is1lepFromW(); }
	const int &is1lepFromTop() { return v80_00.is1lepFromTop(); }
	const float &MT2W() { return v80_00.MT2W(); }
	const float &mindphi_met_j1_j2() { return v80_00.mindphi_met_j1_j2(); }
	const float &mt_met_lep() { return v80_00.mt_met_lep(); }
	const float &hadronic_top_chi2() { return v80_00.hadronic_top_chi2(); }
	const float &ak4pfjets_rho() { return v80_00.ak4pfjets_rho(); }
	const float &pdf_up_weight() { return v80_00.pdf_up_weight(); }
	const float &pdf_down_weight() { return v80_00.pdf_down_weight(); }
	const vector<string> &genweightsID() { return v80_00.genweightsID(); }
	const vector<float> &genweights() { return v80_00.genweights(); }
	const float &weight_btagsf() { return v80_00.weight_btagsf(); }
	const float &weight_btagsf_heavy_UP() { return v80_00.weight_btagsf_heavy_UP(); }
	const float &weight_btagsf_light_UP() { return v80_00.weight_btagsf_light_UP(); }
	const float &weight_btagsf_heavy_DN() { return v80_00.weight_btagsf_heavy_DN(); }
	const float &weight_btagsf_light_DN() { return v80_00.weight_btagsf_light_DN(); }
	const float &weight_btagsf_fastsim_UP() { return v80_00.weight_btagsf_fastsim_UP(); }
	const float &weight_btagsf_fastsim_DN() { return v80_00.weight_btagsf_fastsim_DN(); }
	const float &weight_lepSF() { return v80_00.weight_lepSF(); }
	const float &weight_lepSF_up() { return v80_00.weight_lepSF_up(); }
	const float &weight_lepSF_down() { return v80_00.weight_lepSF_down(); }
	const float &weight_vetoLepSF() { return v80_00.weight_vetoLepSF(); }
	const float &weight_vetoLepSF_up() { return v80_00.weight_vetoLepSF_up(); }
	const float &weight_vetoLepSF_down() { return v80_00.weight_vetoLepSF_down(); }
	const float &weight_lepSF_fastSim() { return v80_00.weight_lepSF_fastSim(); }
	const float &weight_lepSF_fastSim_up() { return v80_00.weight_lepSF_fastSim_up(); }
	const float &weight_lepSF_fastSim_down() { return v80_00.weight_lepSF_fastSim_down(); }
	const float &weight_ISR() { return v80_00.weight_ISR(); }
	const float &weight_ISRup() { return v80_00.weight_ISRup(); }
	const float &weight_ISRdown() { return v80_00.weight_ISRdown(); }
	const float &weight_PU() { return v80_00.weight_PU(); }
	const float &weight_PUup() { return v80_00.weight_PUup(); }
	const float &weight_PUdown() { return v80_00.weight_PUdown(); }
	const vector<string> &sparms_names() { return v80_00.sparms_names(); }
	const vector<float> &sparms_values() { return v80_00.sparms_values(); }
	const int &sparms_subProcessId() { return v80_00.sparms_subProcessId(); }
	const float &mass_lsp() { return v80_00.mass_lsp(); }
	const float &mass_chargino() { return v80_00.mass_chargino(); }
	const float &mass_stop() { return v80_00.mass_stop(); }
	const float &mass_gluino() { return v80_00.mass_gluino(); }
	const float &genmet() { return v80_00.genmet(); }
	const float &genmet_phi() { return v80_00.genmet_phi(); }
	const float &genht() { return v80_00.genht(); }
	const bool &PassTrackVeto() { return v80_00.PassTrackVeto(); }
	const bool &PassTauVeto() { return v80_00.PassTauVeto(); }
	const float &topness() { return v80_00.topness(); }
	const float &topnessMod() { return v80_00.topnessMod(); }
	const float &Mlb_closestb() { return v80_00.Mlb_closestb(); }
	const int &HLT_SingleEl() { return v80_00.HLT_SingleEl(); }
	const int &HLT_SingleMu() { return v80_00.HLT_SingleMu(); }
	const int &HLT_SingleMuNoIso() { return v80_00.HLT_SingleMuNoIso(); }
	const int &HLT_SingleElNoIso() { return v80_00.HLT_SingleElNoIso(); }
	const int &HLT_MET() { return v80_00.HLT_MET(); }
	const int &HLT_DiEl() { return v80_00.HLT_DiEl(); }
	const int &HLT_DiMu() { return v80_00.HLT_DiMu(); }
	const int &HLT_MuE() { return v80_00.HLT_MuE(); }
	const int &HLT_Photon90_CaloIdL_PFHT500() { return v80_00.HLT_Photon90_CaloIdL_PFHT500(); }
	const int &HLT_Photon22_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon22_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon30_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon30_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon36_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon36_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon50_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon50_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon75_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon75_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon90_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon90_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon120_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon120_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon165_R9Id90_HE10_IsoM() { return v80_00.HLT_Photon165_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon175() { return v80_00.HLT_Photon175(); }
	const int &HLT_Photon165_HE10() { return v80_00.HLT_Photon165_HE10(); }
	const int &nPhotons() { return v80_00.nPhotons(); }
	const int &ph_ngoodjets() { return v80_00.ph_ngoodjets(); }
	const int &ph_ngoodbtags() { return v80_00.ph_ngoodbtags(); }
	const float &filt_met() { return v80_00.filt_met(); }
	const float &filt_badMuonFilter() { return v80_00.filt_badMuonFilter(); }
	const float &filt_badChargedCandidateFilter() { return v80_00.filt_badChargedCandidateFilter(); }
	const float &filt_cscbeamhalo2015() { return v80_00.filt_cscbeamhalo2015(); }
	const float &filt_cscbeamhalo() { return v80_00.filt_cscbeamhalo(); }
	const float &hardgenpt() { return v80_00.hardgenpt(); }
	const int &lep1_pdgid() { return v80_00.lep1_pdgid(); }
	const int &lep1_production_type() { return v80_00.lep1_production_type(); }
	const float &lep1_MiniIso() { return v80_00.lep1_MiniIso(); }
	const float &lep1_relIso() { return v80_00.lep1_relIso(); }
	const bool &lep1_passLooseID() { return v80_00.lep1_passLooseID(); }
	const bool &lep1_passMediumID() { return v80_00.lep1_passMediumID(); }
	const bool &lep1_passTightID() { return v80_00.lep1_passTightID(); }
	const bool &lep1_passVeto() { return v80_00.lep1_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return v80_00.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4() { return v80_00.lep1_mcp4(); }
	const int &lep1_mc_motherid() { return v80_00.lep1_mc_motherid(); }
	const int &lep2_pdgid() { return v80_00.lep2_pdgid(); }
	const int &lep2_production_type() { return v80_00.lep2_production_type(); }
	const float &lep2_MiniIso() { return v80_00.lep2_MiniIso(); }
	const float &lep2_relIso() { return v80_00.lep2_relIso(); }
	const bool &lep2_passLooseID() { return v80_00.lep2_passLooseID(); }
	const bool &lep2_passMediumID() { return v80_00.lep2_passMediumID(); }
	const bool &lep2_passTightID() { return v80_00.lep2_passTightID(); }
	const bool &lep2_passVeto() { return v80_00.lep2_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return v80_00.lep2_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4() { return v80_00.lep2_mcp4(); }
	const int &lep2_mc_motherid() { return v80_00.lep2_mc_motherid(); }
	const vector<float> &ph_sigmaIEtaEta_fill5x5() { return v80_00.ph_sigmaIEtaEta_fill5x5(); }
	const vector<float> &ph_hOverE() { return v80_00.ph_hOverE(); }
	const vector<float> &ph_r9() { return v80_00.ph_r9(); }
	const vector<float> &ph_chiso() { return v80_00.ph_chiso(); }
	const vector<float> &ph_nhiso() { return v80_00.ph_nhiso(); }
	const vector<float> &ph_phiso() { return v80_00.ph_phiso(); }
	const vector<bool> &ph_idCutBased() { return v80_00.ph_idCutBased(); }
	const vector<int> &ph_overlapJetId() { return v80_00.ph_overlapJetId(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_p4() { return v80_00.ph_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ph_mcp4() { return v80_00.ph_mcp4(); }
	const vector<float> &ph_pt() { return v80_00.ph_pt(); }
	const vector<float> &ph_eta() { return v80_00.ph_eta(); }
	const vector<float> &ph_phi() { return v80_00.ph_phi(); }
	const vector<float> &ph_mass() { return v80_00.ph_mass(); }
	const vector<int> &ph_mcMatchId() { return v80_00.ph_mcMatchId(); }
	const vector<float> &ph_genIso04() { return v80_00.ph_genIso04(); }
	const vector<float> &ph_drMinParton() { return v80_00.ph_drMinParton(); }
	const int &ngoodjets() { return v80_00.ngoodjets(); }
	const int &ngoodbtags() { return v80_00.ngoodbtags(); }
	const float &ak4_HT() { return v80_00.ak4_HT(); }
	const float &ak4_htratiom() { return v80_00.ak4_htratiom(); }
	const vector<float> &dphi_ak4pfjet_met() { return v80_00.dphi_ak4pfjet_met(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4() { return v80_00.ak4pfjets_p4(); }
	const vector<bool> &ak4pfjets_passMEDbtag() { return v80_00.ak4pfjets_passMEDbtag(); }
	const vector<float> &ak4pfjets_CSV() { return v80_00.ak4pfjets_CSV(); }
	const vector<float> &ak4pfjets_mva() { return v80_00.ak4pfjets_mva(); }
	const vector<int> &ak4pfjets_parton_flavor() { return v80_00.ak4pfjets_parton_flavor(); }
	const vector<int> &ak4pfjets_hadron_flavor() { return v80_00.ak4pfjets_hadron_flavor(); }
	const vector<bool> &ak4pfjets_loose_puid() { return v80_00.ak4pfjets_loose_puid(); }
	const vector<bool> &ak4pfjets_loose_pfid() { return v80_00.ak4pfjets_loose_pfid(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4() { return v80_00.ak4pfjets_leadMEDbjet_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4() { return v80_00.ak4pfjets_leadbtag_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4() { return v80_00.ak4genjets_p4(); }
	const vector<bool> &genleps_isfromt() { return v80_00.genleps_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_p4() { return v80_00.genleps_p4(); }
	const vector<int> &genleps_id() { return v80_00.genleps_id(); }
	const vector<int> &genleps__genpsidx() { return v80_00.genleps__genpsidx(); }
	const vector<int> &genleps_status() { return v80_00.genleps_status(); }
	const vector<bool> &genleps_fromHardProcessDecayed() { return v80_00.genleps_fromHardProcessDecayed(); }
	const vector<bool> &genleps_fromHardProcessFinalState() { return v80_00.genleps_fromHardProcessFinalState(); }
	const vector<bool> &genleps_isHardProcess() { return v80_00.genleps_isHardProcess(); }
	const vector<bool> &genleps_isLastCopy() { return v80_00.genleps_isLastCopy(); }
	const vector<int> &genleps_gentaudecay() { return v80_00.genleps_gentaudecay(); }
	const int &gen_nfromtleps_() { return v80_00.gen_nfromtleps_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_motherp4() { return v80_00.genleps_motherp4(); }
	const vector<int> &genleps_motherid() { return v80_00.genleps_motherid(); }
	const vector<int> &genleps_motheridx() { return v80_00.genleps_motheridx(); }
	const vector<int> &genleps_motherstatus() { return v80_00.genleps_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genleps_gmotherp4() { return v80_00.genleps_gmotherp4(); }
	const vector<int> &genleps_gmotherid() { return v80_00.genleps_gmotherid(); }
	const vector<int> &genleps_gmotheridx() { return v80_00.genleps_gmotheridx(); }
	const vector<int> &genleps_gmotherstatus() { return v80_00.genleps_gmotherstatus(); }
	const vector<bool> &gennus_isfromt() { return v80_00.gennus_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_p4() { return v80_00.gennus_p4(); }
	const vector<int> &gennus_id() { return v80_00.gennus_id(); }
	const vector<int> &gennus__genpsidx() { return v80_00.gennus__genpsidx(); }
	const vector<int> &gennus_status() { return v80_00.gennus_status(); }
	const vector<bool> &gennus_fromHardProcessDecayed() { return v80_00.gennus_fromHardProcessDecayed(); }
	const vector<bool> &gennus_fromHardProcessFinalState() { return v80_00.gennus_fromHardProcessFinalState(); }
	const vector<bool> &gennus_isHardProcess() { return v80_00.gennus_isHardProcess(); }
	const vector<bool> &gennus_isLastCopy() { return v80_00.gennus_isLastCopy(); }
	const vector<int> &gennus_gentaudecay() { return v80_00.gennus_gentaudecay(); }
	const int &gen_nfromtnus_() { return v80_00.gen_nfromtnus_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_motherp4() { return v80_00.gennus_motherp4(); }
	const vector<int> &gennus_motherid() { return v80_00.gennus_motherid(); }
	const vector<int> &gennus_motheridx() { return v80_00.gennus_motheridx(); }
	const vector<int> &gennus_motherstatus() { return v80_00.gennus_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gennus_gmotherp4() { return v80_00.gennus_gmotherp4(); }
	const vector<int> &gennus_gmotherid() { return v80_00.gennus_gmotherid(); }
	const vector<int> &gennus_gmotheridx() { return v80_00.gennus_gmotheridx(); }
	const vector<int> &gennus_gmotherstatus() { return v80_00.gennus_gmotherstatus(); }
	const vector<bool> &genqs_isfromt() { return v80_00.genqs_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_p4() { return v80_00.genqs_p4(); }
	const vector<int> &genqs_id() { return v80_00.genqs_id(); }
	const vector<int> &genqs__genpsidx() { return v80_00.genqs__genpsidx(); }
	const vector<int> &genqs_status() { return v80_00.genqs_status(); }
	const vector<bool> &genqs_fromHardProcessDecayed() { return v80_00.genqs_fromHardProcessDecayed(); }
	const vector<bool> &genqs_fromHardProcessFinalState() { return v80_00.genqs_fromHardProcessFinalState(); }
	const vector<bool> &genqs_isHardProcess() { return v80_00.genqs_isHardProcess(); }
	const vector<bool> &genqs_isLastCopy() { return v80_00.genqs_isLastCopy(); }
	const vector<int> &genqs_gentaudecay() { return v80_00.genqs_gentaudecay(); }
	const int &gen_nfromtqs_() { return v80_00.gen_nfromtqs_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_motherp4() { return v80_00.genqs_motherp4(); }
	const vector<int> &genqs_motherid() { return v80_00.genqs_motherid(); }
	const vector<int> &genqs_motheridx() { return v80_00.genqs_motheridx(); }
	const vector<int> &genqs_motherstatus() { return v80_00.genqs_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genqs_gmotherp4() { return v80_00.genqs_gmotherp4(); }
	const vector<int> &genqs_gmotherid() { return v80_00.genqs_gmotherid(); }
	const vector<int> &genqs_gmotheridx() { return v80_00.genqs_gmotheridx(); }
	const vector<int> &genqs_gmotherstatus() { return v80_00.genqs_gmotherstatus(); }
	const vector<bool> &genbosons_isfromt() { return v80_00.genbosons_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_p4() { return v80_00.genbosons_p4(); }
	const vector<int> &genbosons_id() { return v80_00.genbosons_id(); }
	const vector<int> &genbosons__genpsidx() { return v80_00.genbosons__genpsidx(); }
	const vector<int> &genbosons_status() { return v80_00.genbosons_status(); }
	const vector<bool> &genbosons_fromHardProcessDecayed() { return v80_00.genbosons_fromHardProcessDecayed(); }
	const vector<bool> &genbosons_fromHardProcessFinalState() { return v80_00.genbosons_fromHardProcessFinalState(); }
	const vector<bool> &genbosons_isHardProcess() { return v80_00.genbosons_isHardProcess(); }
	const vector<bool> &genbosons_isLastCopy() { return v80_00.genbosons_isLastCopy(); }
	const vector<int> &genbosons_gentaudecay() { return v80_00.genbosons_gentaudecay(); }
	const int &gen_nfromtbosons_() { return v80_00.gen_nfromtbosons_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_motherp4() { return v80_00.genbosons_motherp4(); }
	const vector<int> &genbosons_motherid() { return v80_00.genbosons_motherid(); }
	const vector<int> &genbosons_motheridx() { return v80_00.genbosons_motheridx(); }
	const vector<int> &genbosons_motherstatus() { return v80_00.genbosons_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genbosons_gmotherp4() { return v80_00.genbosons_gmotherp4(); }
	const vector<int> &genbosons_gmotherid() { return v80_00.genbosons_gmotherid(); }
	const vector<int> &genbosons_gmotheridx() { return v80_00.genbosons_gmotheridx(); }
	const vector<int> &genbosons_gmotherstatus() { return v80_00.genbosons_gmotherstatus(); }
	const vector<bool> &gensusy_isfromt() { return v80_00.gensusy_isfromt(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_p4() { return v80_00.gensusy_p4(); }
	const vector<int> &gensusy_id() { return v80_00.gensusy_id(); }
	const vector<int> &gensusy__genpsidx() { return v80_00.gensusy__genpsidx(); }
	const vector<int> &gensusy_status() { return v80_00.gensusy_status(); }
	const vector<bool> &gensusy_fromHardProcessDecayed() { return v80_00.gensusy_fromHardProcessDecayed(); }
	const vector<bool> &gensusy_fromHardProcessFinalState() { return v80_00.gensusy_fromHardProcessFinalState(); }
	const vector<bool> &gensusy_isHardProcess() { return v80_00.gensusy_isHardProcess(); }
	const vector<bool> &gensusy_isLastCopy() { return v80_00.gensusy_isLastCopy(); }
	const vector<int> &gensusy_gentaudecay() { return v80_00.gensusy_gentaudecay(); }
	const int &gen_nfromtsusy_() { return v80_00.gen_nfromtsusy_(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_motherp4() { return v80_00.gensusy_motherp4(); }
	const vector<int> &gensusy_motherid() { return v80_00.gensusy_motherid(); }
	const vector<int> &gensusy_motheridx() { return v80_00.gensusy_motheridx(); }
	const vector<int> &gensusy_motherstatus() { return v80_00.gensusy_motherstatus(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gensusy_gmotherp4() { return v80_00.gensusy_gmotherp4(); }
	const vector<int> &gensusy_gmotherid() { return v80_00.gensusy_gmotherid(); }
	const vector<int> &gensusy_gmotheridx() { return v80_00.gensusy_gmotheridx(); }
	const vector<int> &gensusy_gmotherstatus() { return v80_00.gensusy_gmotherstatus(); }
}
