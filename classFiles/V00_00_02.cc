#include "V00_00_02.h"
V00_00_02 v00_00_02;

void V00_00_02::Init(TTree *tree) {
	firstVtx_posp4_branch = 0;
	if (tree->GetBranch("firstVtx_posp4") != 0) {
		firstVtx_posp4_branch = tree->GetBranch("firstVtx_posp4");
		if (firstVtx_posp4_branch) {firstVtx_posp4_branch->SetAddress(&firstVtx_posp4_);}
	}
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
	ak4pfjet_overlep1_p4_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_p4") != 0) {
		ak4pfjet_overlep1_p4_branch = tree->GetBranch("ak4pfjet_overlep1_p4");
		if (ak4pfjet_overlep1_p4_branch) {ak4pfjet_overlep1_p4_branch->SetAddress(&ak4pfjet_overlep1_p4_);}
	}
	ak4pfjet_overlep2_p4_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_p4") != 0) {
		ak4pfjet_overlep2_p4_branch = tree->GetBranch("ak4pfjet_overlep2_p4");
		if (ak4pfjet_overlep2_p4_branch) {ak4pfjet_overlep2_p4_branch->SetAddress(&ak4pfjet_overlep2_p4_);}
	}
	ak8pfjets_p4_branch = 0;
	if (tree->GetBranch("ak8pfjets_p4") != 0) {
		ak8pfjets_p4_branch = tree->GetBranch("ak8pfjets_p4");
		if (ak8pfjets_p4_branch) {ak8pfjets_p4_branch->SetAddress(&ak8pfjets_p4_);}
	}
	ak4genjets_p4_branch = 0;
	if (tree->GetBranch("ak4genjets_p4") != 0) {
		ak4genjets_p4_branch = tree->GetBranch("ak4genjets_p4");
		if (ak4genjets_p4_branch) {ak4genjets_p4_branch->SetAddress(&ak4genjets_p4_);}
	}
	tau_leadtrack_p4_branch = 0;
	if (tree->GetBranch("tau_leadtrack_p4") != 0) {
		tau_leadtrack_p4_branch = tree->GetBranch("tau_leadtrack_p4");
		if (tau_leadtrack_p4_branch) {tau_leadtrack_p4_branch->SetAddress(&tau_leadtrack_p4_);}
	}
	tau_leadneutral_p4_branch = 0;
	if (tree->GetBranch("tau_leadneutral_p4") != 0) {
		tau_leadneutral_p4_branch = tree->GetBranch("tau_leadneutral_p4");
		if (tau_leadneutral_p4_branch) {tau_leadneutral_p4_branch->SetAddress(&tau_leadneutral_p4_);}
	}
	tau_p4_branch = 0;
	if (tree->GetBranch("tau_p4") != 0) {
		tau_p4_branch = tree->GetBranch("tau_p4");
		if (tau_p4_branch) {tau_p4_branch->SetAddress(&tau_p4_);}
	}
	isoTracks_p4_branch = 0;
	if (tree->GetBranch("isoTracks_p4") != 0) {
		isoTracks_p4_branch = tree->GetBranch("isoTracks_p4");
		if (isoTracks_p4_branch) {isoTracks_p4_branch->SetAddress(&isoTracks_p4_);}
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
	firstGoodVtxIdx_branch = 0;
	if (tree->GetBranch("firstGoodVtxIdx") != 0) {
		firstGoodVtxIdx_branch = tree->GetBranch("firstGoodVtxIdx");
		if (firstGoodVtxIdx_branch) {firstGoodVtxIdx_branch->SetAddress(&firstGoodVtxIdx_);}
	}
	firstVtx_isfake_branch = 0;
	if (tree->GetBranch("firstVtx_isfake") != 0) {
		firstVtx_isfake_branch = tree->GetBranch("firstVtx_isfake");
		if (firstVtx_isfake_branch) {firstVtx_isfake_branch->SetAddress(&firstVtx_isfake_);}
	}
	firstVtx_ndof_branch = 0;
	if (tree->GetBranch("firstVtx_ndof") != 0) {
		firstVtx_ndof_branch = tree->GetBranch("firstVtx_ndof");
		if (firstVtx_ndof_branch) {firstVtx_ndof_branch->SetAddress(&firstVtx_ndof_);}
	}
	firstVtx_posRho_branch = 0;
	if (tree->GetBranch("firstVtx_posRho") != 0) {
		firstVtx_posRho_branch = tree->GetBranch("firstVtx_posRho");
		if (firstVtx_posRho_branch) {firstVtx_posRho_branch->SetAddress(&firstVtx_posRho_);}
	}
	firstVtx_posZ_branch = 0;
	if (tree->GetBranch("firstVtx_posZ") != 0) {
		firstVtx_posZ_branch = tree->GetBranch("firstVtx_posZ");
		if (firstVtx_posZ_branch) {firstVtx_posZ_branch->SetAddress(&firstVtx_posZ_);}
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
	calomet_branch = 0;
	if (tree->GetBranch("calomet") != 0) {
		calomet_branch = tree->GetBranch("calomet");
		if (calomet_branch) {calomet_branch->SetAddress(&calomet_);}
	}
	calomet_phi_branch = 0;
	if (tree->GetBranch("calomet_phi") != 0) {
		calomet_phi_branch = tree->GetBranch("calomet_phi");
		if (calomet_phi_branch) {calomet_phi_branch->SetAddress(&calomet_phi_);}
	}
	filt_cscbeamhalo_branch = 0;
	if (tree->GetBranch("filt_cscbeamhalo") != 0) {
		filt_cscbeamhalo_branch = tree->GetBranch("filt_cscbeamhalo");
		if (filt_cscbeamhalo_branch) {filt_cscbeamhalo_branch->SetAddress(&filt_cscbeamhalo_);}
	}
	filt_ecallaser_branch = 0;
	if (tree->GetBranch("filt_ecallaser") != 0) {
		filt_ecallaser_branch = tree->GetBranch("filt_ecallaser");
		if (filt_ecallaser_branch) {filt_ecallaser_branch->SetAddress(&filt_ecallaser_);}
	}
	filt_ecaltp_branch = 0;
	if (tree->GetBranch("filt_ecaltp") != 0) {
		filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
		if (filt_ecaltp_branch) {filt_ecaltp_branch->SetAddress(&filt_ecaltp_);}
	}
	filt_eebadsc_branch = 0;
	if (tree->GetBranch("filt_eebadsc") != 0) {
		filt_eebadsc_branch = tree->GetBranch("filt_eebadsc");
		if (filt_eebadsc_branch) {filt_eebadsc_branch->SetAddress(&filt_eebadsc_);}
	}
	filt_goodvtx_branch = 0;
	if (tree->GetBranch("filt_goodvtx") != 0) {
		filt_goodvtx_branch = tree->GetBranch("filt_goodvtx");
		if (filt_goodvtx_branch) {filt_goodvtx_branch->SetAddress(&filt_goodvtx_);}
	}
	filt_badevents_branch = 0;
	if (tree->GetBranch("filt_badevents") != 0) {
		filt_badevents_branch = tree->GetBranch("filt_badevents");
		if (filt_badevents_branch) {filt_badevents_branch->SetAddress(&filt_badevents_);}
	}
	filt_hbhenoise_branch = 0;
	if (tree->GetBranch("filt_hbhenoise") != 0) {
		filt_hbhenoise_branch = tree->GetBranch("filt_hbhenoise");
		if (filt_hbhenoise_branch) {filt_hbhenoise_branch->SetAddress(&filt_hbhenoise_);}
	}
	filt_hcallaser_branch = 0;
	if (tree->GetBranch("filt_hcallaser") != 0) {
		filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
		if (filt_hcallaser_branch) {filt_hcallaser_branch->SetAddress(&filt_hcallaser_);}
	}
	filt_met_branch = 0;
	if (tree->GetBranch("filt_met") != 0) {
		filt_met_branch = tree->GetBranch("filt_met");
		if (filt_met_branch) {filt_met_branch->SetAddress(&filt_met_);}
	}
	filt_trkfail_branch = 0;
	if (tree->GetBranch("filt_trkfail") != 0) {
		filt_trkfail_branch = tree->GetBranch("filt_trkfail");
		if (filt_trkfail_branch) {filt_trkfail_branch->SetAddress(&filt_trkfail_);}
	}
	filt_trkPOG_branch = 0;
	if (tree->GetBranch("filt_trkPOG") != 0) {
		filt_trkPOG_branch = tree->GetBranch("filt_trkPOG");
		if (filt_trkPOG_branch) {filt_trkPOG_branch->SetAddress(&filt_trkPOG_);}
	}
	filt_trkPOG_tmc_branch = 0;
	if (tree->GetBranch("filt_trkPOG_tmc") != 0) {
		filt_trkPOG_tmc_branch = tree->GetBranch("filt_trkPOG_tmc");
		if (filt_trkPOG_tmc_branch) {filt_trkPOG_tmc_branch->SetAddress(&filt_trkPOG_tmc_);}
	}
	filt_trkPOG_tms_branch = 0;
	if (tree->GetBranch("filt_trkPOG_tms") != 0) {
		filt_trkPOG_tms_branch = tree->GetBranch("filt_trkPOG_tms");
		if (filt_trkPOG_tms_branch) {filt_trkPOG_tms_branch->SetAddress(&filt_trkPOG_tms_);}
	}
	filt_eff_branch = 0;
	if (tree->GetBranch("filt_eff") != 0) {
		filt_eff_branch = tree->GetBranch("filt_eff");
		if (filt_eff_branch) {filt_eff_branch->SetAddress(&filt_eff_);}
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
	nlooseleps_branch = 0;
	if (tree->GetBranch("nlooseleps") != 0) {
		nlooseleps_branch = tree->GetBranch("nlooseleps");
		if (nlooseleps_branch) {nlooseleps_branch->SetAddress(&nlooseleps_);}
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
	genlepsfromtop_branch = 0;
	if (tree->GetBranch("genlepsfromtop") != 0) {
		genlepsfromtop_branch = tree->GetBranch("genlepsfromtop");
		if (genlepsfromtop_branch) {genlepsfromtop_branch->SetAddress(&genlepsfromtop_);}
	}
	MT2W_branch = 0;
	if (tree->GetBranch("MT2W") != 0) {
		MT2W_branch = tree->GetBranch("MT2W");
		if (MT2W_branch) {MT2W_branch->SetAddress(&MT2W_);}
	}
	MT2W_lep2_branch = 0;
	if (tree->GetBranch("MT2W_lep2") != 0) {
		MT2W_lep2_branch = tree->GetBranch("MT2W_lep2");
		if (MT2W_lep2_branch) {MT2W_lep2_branch->SetAddress(&MT2W_lep2_);}
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
	mt_met_lep2_branch = 0;
	if (tree->GetBranch("mt_met_lep2") != 0) {
		mt_met_lep2_branch = tree->GetBranch("mt_met_lep2");
		if (mt_met_lep2_branch) {mt_met_lep2_branch->SetAddress(&mt_met_lep2_);}
	}
	dR_lep_leadb_branch = 0;
	if (tree->GetBranch("dR_lep_leadb") != 0) {
		dR_lep_leadb_branch = tree->GetBranch("dR_lep_leadb");
		if (dR_lep_leadb_branch) {dR_lep_leadb_branch->SetAddress(&dR_lep_leadb_);}
	}
	dR_lep2_leadb_branch = 0;
	if (tree->GetBranch("dR_lep2_leadb") != 0) {
		dR_lep2_leadb_branch = tree->GetBranch("dR_lep2_leadb");
		if (dR_lep2_leadb_branch) {dR_lep2_leadb_branch->SetAddress(&dR_lep2_leadb_);}
	}
	hadronic_top_chi2_branch = 0;
	if (tree->GetBranch("hadronic_top_chi2") != 0) {
		hadronic_top_chi2_branch = tree->GetBranch("hadronic_top_chi2");
		if (hadronic_top_chi2_branch) {hadronic_top_chi2_branch->SetAddress(&hadronic_top_chi2_);}
	}
	dphi_Wlep_branch = 0;
	if (tree->GetBranch("dphi_Wlep") != 0) {
		dphi_Wlep_branch = tree->GetBranch("dphi_Wlep");
		if (dphi_Wlep_branch) {dphi_Wlep_branch->SetAddress(&dphi_Wlep_);}
	}
	MET_over_sqrtHT_branch = 0;
	if (tree->GetBranch("MET_over_sqrtHT") != 0) {
		MET_over_sqrtHT_branch = tree->GetBranch("MET_over_sqrtHT");
		if (MET_over_sqrtHT_branch) {MET_over_sqrtHT_branch->SetAddress(&MET_over_sqrtHT_);}
	}
	ak4pfjets_rho_branch = 0;
	if (tree->GetBranch("ak4pfjets_rho") != 0) {
		ak4pfjets_rho_branch = tree->GetBranch("ak4pfjets_rho");
		if (ak4pfjets_rho_branch) {ak4pfjets_rho_branch->SetAddress(&ak4pfjets_rho_);}
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
	sparms_names_branch = 0;
	if (tree->GetBranch("sparms_names") != 0) {
		sparms_names_branch = tree->GetBranch("sparms_names");
		if (sparms_names_branch) {sparms_names_branch->SetAddress(&sparms_names_);}
	}
	sparms_filterEfficiency_branch = 0;
	if (tree->GetBranch("sparms_filterEfficiency") != 0) {
		sparms_filterEfficiency_branch = tree->GetBranch("sparms_filterEfficiency");
		if (sparms_filterEfficiency_branch) {sparms_filterEfficiency_branch->SetAddress(&sparms_filterEfficiency_);}
	}
	sparms_pdfScale_branch = 0;
	if (tree->GetBranch("sparms_pdfScale") != 0) {
		sparms_pdfScale_branch = tree->GetBranch("sparms_pdfScale");
		if (sparms_pdfScale_branch) {sparms_pdfScale_branch->SetAddress(&sparms_pdfScale_);}
	}
	sparms_pdfWeight1_branch = 0;
	if (tree->GetBranch("sparms_pdfWeight1") != 0) {
		sparms_pdfWeight1_branch = tree->GetBranch("sparms_pdfWeight1");
		if (sparms_pdfWeight1_branch) {sparms_pdfWeight1_branch->SetAddress(&sparms_pdfWeight1_);}
	}
	sparms_pdfWeight2_branch = 0;
	if (tree->GetBranch("sparms_pdfWeight2") != 0) {
		sparms_pdfWeight2_branch = tree->GetBranch("sparms_pdfWeight2");
		if (sparms_pdfWeight2_branch) {sparms_pdfWeight2_branch->SetAddress(&sparms_pdfWeight2_);}
	}
	sparms_weight_branch = 0;
	if (tree->GetBranch("sparms_weight") != 0) {
		sparms_weight_branch = tree->GetBranch("sparms_weight");
		if (sparms_weight_branch) {sparms_weight_branch->SetAddress(&sparms_weight_);}
	}
	sparms_xsec_branch = 0;
	if (tree->GetBranch("sparms_xsec") != 0) {
		sparms_xsec_branch = tree->GetBranch("sparms_xsec");
		if (sparms_xsec_branch) {sparms_xsec_branch->SetAddress(&sparms_xsec_);}
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
	PassTrackVeto_branch = 0;
	if (tree->GetBranch("PassTrackVeto") != 0) {
		PassTrackVeto_branch = tree->GetBranch("PassTrackVeto");
		if (PassTrackVeto_branch) {PassTrackVeto_branch->SetAddress(&PassTrackVeto_);}
	}
	PassTrackVeto_v2_branch = 0;
	if (tree->GetBranch("PassTrackVeto_v2") != 0) {
		PassTrackVeto_v2_branch = tree->GetBranch("PassTrackVeto_v2");
		if (PassTrackVeto_v2_branch) {PassTrackVeto_v2_branch->SetAddress(&PassTrackVeto_v2_);}
	}
	PassTrackVeto_v3_branch = 0;
	if (tree->GetBranch("PassTrackVeto_v3") != 0) {
		PassTrackVeto_v3_branch = tree->GetBranch("PassTrackVeto_v3");
		if (PassTrackVeto_v3_branch) {PassTrackVeto_v3_branch->SetAddress(&PassTrackVeto_v3_);}
	}
	PassTauVeto_branch = 0;
	if (tree->GetBranch("PassTauVeto") != 0) {
		PassTauVeto_branch = tree->GetBranch("PassTauVeto");
		if (PassTauVeto_branch) {PassTauVeto_branch->SetAddress(&PassTauVeto_);}
	}
	EA_all_rho_branch = 0;
	if (tree->GetBranch("EA_all_rho") != 0) {
		EA_all_rho_branch = tree->GetBranch("EA_all_rho");
		if (EA_all_rho_branch) {EA_all_rho_branch->SetAddress(&EA_all_rho_);}
	}
	EA_allcalo_rho_branch = 0;
	if (tree->GetBranch("EA_allcalo_rho") != 0) {
		EA_allcalo_rho_branch = tree->GetBranch("EA_allcalo_rho");
		if (EA_allcalo_rho_branch) {EA_allcalo_rho_branch->SetAddress(&EA_allcalo_rho_);}
	}
	EA_centralcalo_rho_branch = 0;
	if (tree->GetBranch("EA_centralcalo_rho") != 0) {
		EA_centralcalo_rho_branch = tree->GetBranch("EA_centralcalo_rho");
		if (EA_centralcalo_rho_branch) {EA_centralcalo_rho_branch->SetAddress(&EA_centralcalo_rho_);}
	}
	EA_centralchargedpileup_rho_branch = 0;
	if (tree->GetBranch("EA_centralchargedpileup_rho") != 0) {
		EA_centralchargedpileup_rho_branch = tree->GetBranch("EA_centralchargedpileup_rho");
		if (EA_centralchargedpileup_rho_branch) {EA_centralchargedpileup_rho_branch->SetAddress(&EA_centralchargedpileup_rho_);}
	}
	EA_centralneutral_rho_branch = 0;
	if (tree->GetBranch("EA_centralneutral_rho") != 0) {
		EA_centralneutral_rho_branch = tree->GetBranch("EA_centralneutral_rho");
		if (EA_centralneutral_rho_branch) {EA_centralneutral_rho_branch->SetAddress(&EA_centralneutral_rho_);}
	}
	topness_branch = 0;
	if (tree->GetBranch("topness") != 0) {
		topness_branch = tree->GetBranch("topness");
		if (topness_branch) {topness_branch->SetAddress(&topness_);}
	}
	topness_lep2_branch = 0;
	if (tree->GetBranch("topness_lep2") != 0) {
		topness_lep2_branch = tree->GetBranch("topness_lep2");
		if (topness_lep2_branch) {topness_lep2_branch->SetAddress(&topness_lep2_);}
	}
	topnessMod_branch = 0;
	if (tree->GetBranch("topnessMod") != 0) {
		topnessMod_branch = tree->GetBranch("topnessMod");
		if (topnessMod_branch) {topnessMod_branch->SetAddress(&topnessMod_);}
	}
	topnessMod_lep2_branch = 0;
	if (tree->GetBranch("topnessMod_lep2") != 0) {
		topnessMod_lep2_branch = tree->GetBranch("topnessMod_lep2");
		if (topnessMod_lep2_branch) {topnessMod_lep2_branch->SetAddress(&topnessMod_lep2_);}
	}
	MT2_lb_b_branch = 0;
	if (tree->GetBranch("MT2_lb_b") != 0) {
		MT2_lb_b_branch = tree->GetBranch("MT2_lb_b");
		if (MT2_lb_b_branch) {MT2_lb_b_branch->SetAddress(&MT2_lb_b_);}
	}
	MT2_lb_b_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_lep2") != 0) {
		MT2_lb_b_lep2_branch = tree->GetBranch("MT2_lb_b_lep2");
		if (MT2_lb_b_lep2_branch) {MT2_lb_b_lep2_branch->SetAddress(&MT2_lb_b_lep2_);}
	}
	MT2_lb_b_mass_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass") != 0) {
		MT2_lb_b_mass_branch = tree->GetBranch("MT2_lb_b_mass");
		if (MT2_lb_b_mass_branch) {MT2_lb_b_mass_branch->SetAddress(&MT2_lb_b_mass_);}
	}
	MT2_lb_b_mass_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_b_mass_lep2") != 0) {
		MT2_lb_b_mass_lep2_branch = tree->GetBranch("MT2_lb_b_mass_lep2");
		if (MT2_lb_b_mass_lep2_branch) {MT2_lb_b_mass_lep2_branch->SetAddress(&MT2_lb_b_mass_lep2_);}
	}
	MT2_lb_bqq_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq") != 0) {
		MT2_lb_bqq_branch = tree->GetBranch("MT2_lb_bqq");
		if (MT2_lb_bqq_branch) {MT2_lb_bqq_branch->SetAddress(&MT2_lb_bqq_);}
	}
	MT2_lb_bqq_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_lep2") != 0) {
		MT2_lb_bqq_lep2_branch = tree->GetBranch("MT2_lb_bqq_lep2");
		if (MT2_lb_bqq_lep2_branch) {MT2_lb_bqq_lep2_branch->SetAddress(&MT2_lb_bqq_lep2_);}
	}
	MT2_lb_bqq_mass_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_mass") != 0) {
		MT2_lb_bqq_mass_branch = tree->GetBranch("MT2_lb_bqq_mass");
		if (MT2_lb_bqq_mass_branch) {MT2_lb_bqq_mass_branch->SetAddress(&MT2_lb_bqq_mass_);}
	}
	MT2_lb_bqq_mass_lep2_branch = 0;
	if (tree->GetBranch("MT2_lb_bqq_mass_lep2") != 0) {
		MT2_lb_bqq_mass_lep2_branch = tree->GetBranch("MT2_lb_bqq_mass_lep2");
		if (MT2_lb_bqq_mass_lep2_branch) {MT2_lb_bqq_mass_lep2_branch->SetAddress(&MT2_lb_bqq_mass_lep2_);}
	}
	Mlb_closestb_branch = 0;
	if (tree->GetBranch("Mlb_closestb") != 0) {
		Mlb_closestb_branch = tree->GetBranch("Mlb_closestb");
		if (Mlb_closestb_branch) {Mlb_closestb_branch->SetAddress(&Mlb_closestb_);}
	}
	Mlb_lead_bdiscr_branch = 0;
	if (tree->GetBranch("Mlb_lead_bdiscr") != 0) {
		Mlb_lead_bdiscr_branch = tree->GetBranch("Mlb_lead_bdiscr");
		if (Mlb_lead_bdiscr_branch) {Mlb_lead_bdiscr_branch->SetAddress(&Mlb_lead_bdiscr_);}
	}
	Mlb_closestb_lep2_branch = 0;
	if (tree->GetBranch("Mlb_closestb_lep2") != 0) {
		Mlb_closestb_lep2_branch = tree->GetBranch("Mlb_closestb_lep2");
		if (Mlb_closestb_lep2_branch) {Mlb_closestb_lep2_branch->SetAddress(&Mlb_closestb_lep2_);}
	}
	Mlb_lead_bdiscr_lep2_branch = 0;
	if (tree->GetBranch("Mlb_lead_bdiscr_lep2") != 0) {
		Mlb_lead_bdiscr_lep2_branch = tree->GetBranch("Mlb_lead_bdiscr_lep2");
		if (Mlb_lead_bdiscr_lep2_branch) {Mlb_lead_bdiscr_lep2_branch->SetAddress(&Mlb_lead_bdiscr_lep2_);}
	}
	Mjjj_branch = 0;
	if (tree->GetBranch("Mjjj") != 0) {
		Mjjj_branch = tree->GetBranch("Mjjj");
		if (Mjjj_branch) {Mjjj_branch->SetAddress(&Mjjj_);}
	}
	Mjjj_lep2_branch = 0;
	if (tree->GetBranch("Mjjj_lep2") != 0) {
		Mjjj_lep2_branch = tree->GetBranch("Mjjj_lep2");
		if (Mjjj_lep2_branch) {Mjjj_lep2_branch->SetAddress(&Mjjj_lep2_);}
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
	HLT_MET170_branch = 0;
	if (tree->GetBranch("HLT_MET170") != 0) {
		HLT_MET170_branch = tree->GetBranch("HLT_MET170");
		if (HLT_MET170_branch) {HLT_MET170_branch->SetAddress(&HLT_MET170_);}
	}
	HLT_MET120Btag_branch = 0;
	if (tree->GetBranch("HLT_MET120Btag") != 0) {
		HLT_MET120Btag_branch = tree->GetBranch("HLT_MET120Btag");
		if (HLT_MET120Btag_branch) {HLT_MET120Btag_branch->SetAddress(&HLT_MET120Btag_);}
	}
	HLT_MET120Mu5_branch = 0;
	if (tree->GetBranch("HLT_MET120Mu5") != 0) {
		HLT_MET120Mu5_branch = tree->GetBranch("HLT_MET120Mu5");
		if (HLT_MET120Mu5_branch) {HLT_MET120Mu5_branch->SetAddress(&HLT_MET120Mu5_);}
	}
	HLT_HT350MET120_branch = 0;
	if (tree->GetBranch("HLT_HT350MET120") != 0) {
		HLT_HT350MET120_branch = tree->GetBranch("HLT_HT350MET120");
		if (HLT_HT350MET120_branch) {HLT_HT350MET120_branch->SetAddress(&HLT_HT350MET120_);}
	}
	HLT_DiEl_branch = 0;
	if (tree->GetBranch("HLT_DiEl") != 0) {
		HLT_DiEl_branch = tree->GetBranch("HLT_DiEl");
		if (HLT_DiEl_branch) {HLT_DiEl_branch->SetAddress(&HLT_DiEl_);}
	}
	HLT_DiEl_17_12_branch = 0;
	if (tree->GetBranch("HLT_DiEl_17_12") != 0) {
		HLT_DiEl_17_12_branch = tree->GetBranch("HLT_DiEl_17_12");
		if (HLT_DiEl_17_12_branch) {HLT_DiEl_17_12_branch->SetAddress(&HLT_DiEl_17_12_);}
	}
	HLT_DiMu_branch = 0;
	if (tree->GetBranch("HLT_DiMu") != 0) {
		HLT_DiMu_branch = tree->GetBranch("HLT_DiMu");
		if (HLT_DiMu_branch) {HLT_DiMu_branch->SetAddress(&HLT_DiMu_);}
	}
	HLT_Mu8El17_branch = 0;
	if (tree->GetBranch("HLT_Mu8El17") != 0) {
		HLT_Mu8El17_branch = tree->GetBranch("HLT_Mu8El17");
		if (HLT_Mu8El17_branch) {HLT_Mu8El17_branch->SetAddress(&HLT_Mu8El17_);}
	}
	HLT_Mu8El23_branch = 0;
	if (tree->GetBranch("HLT_Mu8El23") != 0) {
		HLT_Mu8El23_branch = tree->GetBranch("HLT_Mu8El23");
		if (HLT_Mu8El23_branch) {HLT_Mu8El23_branch->SetAddress(&HLT_Mu8El23_);}
	}
	HLT_Mu17El12_branch = 0;
	if (tree->GetBranch("HLT_Mu17El12") != 0) {
		HLT_Mu17El12_branch = tree->GetBranch("HLT_Mu17El12");
		if (HLT_Mu17El12_branch) {HLT_Mu17El12_branch->SetAddress(&HLT_Mu17El12_);}
	}
	HLT_Mu23El12_branch = 0;
	if (tree->GetBranch("HLT_Mu23El12") != 0) {
		HLT_Mu23El12_branch = tree->GetBranch("HLT_Mu23El12");
		if (HLT_Mu23El12_branch) {HLT_Mu23El12_branch->SetAddress(&HLT_Mu23El12_);}
	}
	HLT_SingleEl23_branch = 0;
	if (tree->GetBranch("HLT_SingleEl23") != 0) {
		HLT_SingleEl23_branch = tree->GetBranch("HLT_SingleEl23");
		if (HLT_SingleEl23_branch) {HLT_SingleEl23_branch->SetAddress(&HLT_SingleEl23_);}
	}
	HLT_SingleEl27_branch = 0;
	if (tree->GetBranch("HLT_SingleEl27") != 0) {
		HLT_SingleEl27_branch = tree->GetBranch("HLT_SingleEl27");
		if (HLT_SingleEl27_branch) {HLT_SingleEl27_branch->SetAddress(&HLT_SingleEl27_);}
	}
	HLT_SingleEl27Tight_branch = 0;
	if (tree->GetBranch("HLT_SingleEl27Tight") != 0) {
		HLT_SingleEl27Tight_branch = tree->GetBranch("HLT_SingleEl27Tight");
		if (HLT_SingleEl27Tight_branch) {HLT_SingleEl27Tight_branch->SetAddress(&HLT_SingleEl27Tight_);}
	}
	HLT_SingleElTight_branch = 0;
	if (tree->GetBranch("HLT_SingleElTight") != 0) {
		HLT_SingleElTight_branch = tree->GetBranch("HLT_SingleElTight");
		if (HLT_SingleElTight_branch) {HLT_SingleElTight_branch->SetAddress(&HLT_SingleElTight_);}
	}
	HLT_SingleElHT200_branch = 0;
	if (tree->GetBranch("HLT_SingleElHT200") != 0) {
		HLT_SingleElHT200_branch = tree->GetBranch("HLT_SingleElHT200");
		if (HLT_SingleElHT200_branch) {HLT_SingleElHT200_branch->SetAddress(&HLT_SingleElHT200_);}
	}
	HLT_SingleMuNoEta_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoEta") != 0) {
		HLT_SingleMuNoEta_branch = tree->GetBranch("HLT_SingleMuNoEta");
		if (HLT_SingleMuNoEta_branch) {HLT_SingleMuNoEta_branch->SetAddress(&HLT_SingleMuNoEta_);}
	}
	HLT_SingleMuNoIso_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoIso") != 0) {
		HLT_SingleMuNoIso_branch = tree->GetBranch("HLT_SingleMuNoIso");
		if (HLT_SingleMuNoIso_branch) {HLT_SingleMuNoIso_branch->SetAddress(&HLT_SingleMuNoIso_);}
	}
	HLT_SingleMuNoIsoNoEta_branch = 0;
	if (tree->GetBranch("HLT_SingleMuNoIsoNoEta") != 0) {
		HLT_SingleMuNoIsoNoEta_branch = tree->GetBranch("HLT_SingleMuNoIsoNoEta");
		if (HLT_SingleMuNoIsoNoEta_branch) {HLT_SingleMuNoIsoNoEta_branch->SetAddress(&HLT_SingleMuNoIsoNoEta_);}
	}
	HLT_Mu6HT200MET100_branch = 0;
	if (tree->GetBranch("HLT_Mu6HT200MET100") != 0) {
		HLT_Mu6HT200MET100_branch = tree->GetBranch("HLT_Mu6HT200MET100");
		if (HLT_Mu6HT200MET100_branch) {HLT_Mu6HT200MET100_branch->SetAddress(&HLT_Mu6HT200MET100_);}
	}
	HLT_HT350MET100_branch = 0;
	if (tree->GetBranch("HLT_HT350MET100") != 0) {
		HLT_HT350MET100_branch = tree->GetBranch("HLT_HT350MET100");
		if (HLT_HT350MET100_branch) {HLT_HT350MET100_branch->SetAddress(&HLT_HT350MET100_);}
	}
	HLT_SingleMu17_branch = 0;
	if (tree->GetBranch("HLT_SingleMu17") != 0) {
		HLT_SingleMu17_branch = tree->GetBranch("HLT_SingleMu17");
		if (HLT_SingleMu17_branch) {HLT_SingleMu17_branch->SetAddress(&HLT_SingleMu17_);}
	}
	HLT_SingleMu20_branch = 0;
	if (tree->GetBranch("HLT_SingleMu20") != 0) {
		HLT_SingleMu20_branch = tree->GetBranch("HLT_SingleMu20");
		if (HLT_SingleMu20_branch) {HLT_SingleMu20_branch->SetAddress(&HLT_SingleMu20_);}
	}
	HLT_SingleMu24_branch = 0;
	if (tree->GetBranch("HLT_SingleMu24") != 0) {
		HLT_SingleMu24_branch = tree->GetBranch("HLT_SingleMu24");
		if (HLT_SingleMu24_branch) {HLT_SingleMu24_branch->SetAddress(&HLT_SingleMu24_);}
	}
	HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight") != 0) {
		HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch = tree->GetBranch("HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight");
		if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch) {HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch->SetAddress(&HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_);}
	}
	HLT_MET90_MHT90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_MET90_MHT90_IDTight") != 0) {
		HLT_MET90_MHT90_IDTight_branch = tree->GetBranch("HLT_MET90_MHT90_IDTight");
		if (HLT_MET90_MHT90_IDTight_branch) {HLT_MET90_MHT90_IDTight_branch->SetAddress(&HLT_MET90_MHT90_IDTight_);}
	}
	HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch = 0;
	if (tree->GetBranch("HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight") != 0) {
		HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch = tree->GetBranch("HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight");
		if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch) {HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch->SetAddress(&HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_);}
	}
	HLT_Photon90_CaloIdL_PFHT500_branch = 0;
	if (tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500") != 0) {
		HLT_Photon90_CaloIdL_PFHT500_branch = tree->GetBranch("HLT_Photon90_CaloIdL_PFHT500");
		if (HLT_Photon90_CaloIdL_PFHT500_branch) {HLT_Photon90_CaloIdL_PFHT500_branch->SetAddress(&HLT_Photon90_CaloIdL_PFHT500_);}
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
	pu_weight_branch = 0;
	if (tree->GetBranch("pu_weight") != 0) {
		pu_weight_branch = tree->GetBranch("pu_weight");
		if (pu_weight_branch) {pu_weight_branch->SetAddress(&pu_weight_);}
	}
	lep_sf_branch = 0;
	if (tree->GetBranch("lep_sf") != 0) {
		lep_sf_branch = tree->GetBranch("lep_sf");
		if (lep_sf_branch) {lep_sf_branch->SetAddress(&lep_sf_);}
	}
	btag_sf_branch = 0;
	if (tree->GetBranch("btag_sf") != 0) {
		btag_sf_branch = tree->GetBranch("btag_sf");
		if (btag_sf_branch) {btag_sf_branch->SetAddress(&btag_sf_);}
	}
	HLT_SingleEl_eff_branch = 0;
	if (tree->GetBranch("HLT_SingleEl_eff") != 0) {
		HLT_SingleEl_eff_branch = tree->GetBranch("HLT_SingleEl_eff");
		if (HLT_SingleEl_eff_branch) {HLT_SingleEl_eff_branch->SetAddress(&HLT_SingleEl_eff_);}
	}
	HLT_SingleMu_eff_branch = 0;
	if (tree->GetBranch("HLT_SingleMu_eff") != 0) {
		HLT_SingleMu_eff_branch = tree->GetBranch("HLT_SingleMu_eff");
		if (HLT_SingleMu_eff_branch) {HLT_SingleMu_eff_branch->SetAddress(&HLT_SingleMu_eff_);}
	}
	lep1_is_mu_branch = 0;
	if (tree->GetBranch("lep1_is_mu") != 0) {
		lep1_is_mu_branch = tree->GetBranch("lep1_is_mu");
		if (lep1_is_mu_branch) {lep1_is_mu_branch->SetAddress(&lep1_is_mu_);}
	}
	lep1_is_el_branch = 0;
	if (tree->GetBranch("lep1_is_el") != 0) {
		lep1_is_el_branch = tree->GetBranch("lep1_is_el");
		if (lep1_is_el_branch) {lep1_is_el_branch->SetAddress(&lep1_is_el_);}
	}
	lep1_charge_branch = 0;
	if (tree->GetBranch("lep1_charge") != 0) {
		lep1_charge_branch = tree->GetBranch("lep1_charge");
		if (lep1_charge_branch) {lep1_charge_branch->SetAddress(&lep1_charge_);}
	}
	lep1_pdgid_branch = 0;
	if (tree->GetBranch("lep1_pdgid") != 0) {
		lep1_pdgid_branch = tree->GetBranch("lep1_pdgid");
		if (lep1_pdgid_branch) {lep1_pdgid_branch->SetAddress(&lep1_pdgid_);}
	}
	lep1_type_branch = 0;
	if (tree->GetBranch("lep1_type") != 0) {
		lep1_type_branch = tree->GetBranch("lep1_type");
		if (lep1_type_branch) {lep1_type_branch->SetAddress(&lep1_type_);}
	}
	lep1_production_type_branch = 0;
	if (tree->GetBranch("lep1_production_type") != 0) {
		lep1_production_type_branch = tree->GetBranch("lep1_production_type");
		if (lep1_production_type_branch) {lep1_production_type_branch->SetAddress(&lep1_production_type_);}
	}
	lep1_d0_branch = 0;
	if (tree->GetBranch("lep1_d0") != 0) {
		lep1_d0_branch = tree->GetBranch("lep1_d0");
		if (lep1_d0_branch) {lep1_d0_branch->SetAddress(&lep1_d0_);}
	}
	lep1_d0err_branch = 0;
	if (tree->GetBranch("lep1_d0err") != 0) {
		lep1_d0err_branch = tree->GetBranch("lep1_d0err");
		if (lep1_d0err_branch) {lep1_d0err_branch->SetAddress(&lep1_d0err_);}
	}
	lep1_dz_branch = 0;
	if (tree->GetBranch("lep1_dz") != 0) {
		lep1_dz_branch = tree->GetBranch("lep1_dz");
		if (lep1_dz_branch) {lep1_dz_branch->SetAddress(&lep1_dz_);}
	}
	lep1_dzerr_branch = 0;
	if (tree->GetBranch("lep1_dzerr") != 0) {
		lep1_dzerr_branch = tree->GetBranch("lep1_dzerr");
		if (lep1_dzerr_branch) {lep1_dzerr_branch->SetAddress(&lep1_dzerr_);}
	}
	lep1_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("lep1_sigmaIEtaEta_fill5x5") != 0) {
		lep1_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("lep1_sigmaIEtaEta_fill5x5");
		if (lep1_sigmaIEtaEta_fill5x5_branch) {lep1_sigmaIEtaEta_fill5x5_branch->SetAddress(&lep1_sigmaIEtaEta_fill5x5_);}
	}
	lep1_dEtaIn_branch = 0;
	if (tree->GetBranch("lep1_dEtaIn") != 0) {
		lep1_dEtaIn_branch = tree->GetBranch("lep1_dEtaIn");
		if (lep1_dEtaIn_branch) {lep1_dEtaIn_branch->SetAddress(&lep1_dEtaIn_);}
	}
	lep1_dPhiIn_branch = 0;
	if (tree->GetBranch("lep1_dPhiIn") != 0) {
		lep1_dPhiIn_branch = tree->GetBranch("lep1_dPhiIn");
		if (lep1_dPhiIn_branch) {lep1_dPhiIn_branch->SetAddress(&lep1_dPhiIn_);}
	}
	lep1_hOverE_branch = 0;
	if (tree->GetBranch("lep1_hOverE") != 0) {
		lep1_hOverE_branch = tree->GetBranch("lep1_hOverE");
		if (lep1_hOverE_branch) {lep1_hOverE_branch->SetAddress(&lep1_hOverE_);}
	}
	lep1_ooEmooP_branch = 0;
	if (tree->GetBranch("lep1_ooEmooP") != 0) {
		lep1_ooEmooP_branch = tree->GetBranch("lep1_ooEmooP");
		if (lep1_ooEmooP_branch) {lep1_ooEmooP_branch->SetAddress(&lep1_ooEmooP_);}
	}
	lep1_expectedMissingInnerHits_branch = 0;
	if (tree->GetBranch("lep1_expectedMissingInnerHits") != 0) {
		lep1_expectedMissingInnerHits_branch = tree->GetBranch("lep1_expectedMissingInnerHits");
		if (lep1_expectedMissingInnerHits_branch) {lep1_expectedMissingInnerHits_branch->SetAddress(&lep1_expectedMissingInnerHits_);}
	}
	lep1_conversionVeto_branch = 0;
	if (tree->GetBranch("lep1_conversionVeto") != 0) {
		lep1_conversionVeto_branch = tree->GetBranch("lep1_conversionVeto");
		if (lep1_conversionVeto_branch) {lep1_conversionVeto_branch->SetAddress(&lep1_conversionVeto_);}
	}
	lep1_etaSC_branch = 0;
	if (tree->GetBranch("lep1_etaSC") != 0) {
		lep1_etaSC_branch = tree->GetBranch("lep1_etaSC");
		if (lep1_etaSC_branch) {lep1_etaSC_branch->SetAddress(&lep1_etaSC_);}
	}
	lep1_ChiSqr_branch = 0;
	if (tree->GetBranch("lep1_ChiSqr") != 0) {
		lep1_ChiSqr_branch = tree->GetBranch("lep1_ChiSqr");
		if (lep1_ChiSqr_branch) {lep1_ChiSqr_branch->SetAddress(&lep1_ChiSqr_);}
	}
	lep1_chiso_branch = 0;
	if (tree->GetBranch("lep1_chiso") != 0) {
		lep1_chiso_branch = tree->GetBranch("lep1_chiso");
		if (lep1_chiso_branch) {lep1_chiso_branch->SetAddress(&lep1_chiso_);}
	}
	lep1_nhiso_branch = 0;
	if (tree->GetBranch("lep1_nhiso") != 0) {
		lep1_nhiso_branch = tree->GetBranch("lep1_nhiso");
		if (lep1_nhiso_branch) {lep1_nhiso_branch->SetAddress(&lep1_nhiso_);}
	}
	lep1_emiso_branch = 0;
	if (tree->GetBranch("lep1_emiso") != 0) {
		lep1_emiso_branch = tree->GetBranch("lep1_emiso");
		if (lep1_emiso_branch) {lep1_emiso_branch->SetAddress(&lep1_emiso_);}
	}
	lep1_deltaBeta_branch = 0;
	if (tree->GetBranch("lep1_deltaBeta") != 0) {
		lep1_deltaBeta_branch = tree->GetBranch("lep1_deltaBeta");
		if (lep1_deltaBeta_branch) {lep1_deltaBeta_branch->SetAddress(&lep1_deltaBeta_);}
	}
	lep1_relIso03DB_branch = 0;
	if (tree->GetBranch("lep1_relIso03DB") != 0) {
		lep1_relIso03DB_branch = tree->GetBranch("lep1_relIso03DB");
		if (lep1_relIso03DB_branch) {lep1_relIso03DB_branch->SetAddress(&lep1_relIso03DB_);}
	}
	lep1_relIso03EA_branch = 0;
	if (tree->GetBranch("lep1_relIso03EA") != 0) {
		lep1_relIso03EA_branch = tree->GetBranch("lep1_relIso03EA");
		if (lep1_relIso03EA_branch) {lep1_relIso03EA_branch->SetAddress(&lep1_relIso03EA_);}
	}
	lep1_relIso04DB_branch = 0;
	if (tree->GetBranch("lep1_relIso04DB") != 0) {
		lep1_relIso04DB_branch = tree->GetBranch("lep1_relIso04DB");
		if (lep1_relIso04DB_branch) {lep1_relIso04DB_branch->SetAddress(&lep1_relIso04DB_);}
	}
	lep1_miniRelIsoDB_branch = 0;
	if (tree->GetBranch("lep1_miniRelIsoDB") != 0) {
		lep1_miniRelIsoDB_branch = tree->GetBranch("lep1_miniRelIsoDB");
		if (lep1_miniRelIsoDB_branch) {lep1_miniRelIsoDB_branch->SetAddress(&lep1_miniRelIsoDB_);}
	}
	lep1_miniRelIsoEA_branch = 0;
	if (tree->GetBranch("lep1_miniRelIsoEA") != 0) {
		lep1_miniRelIsoEA_branch = tree->GetBranch("lep1_miniRelIsoEA");
		if (lep1_miniRelIsoEA_branch) {lep1_miniRelIsoEA_branch->SetAddress(&lep1_miniRelIsoEA_);}
	}
	lep1_MiniIso_branch = 0;
	if (tree->GetBranch("lep1_MiniIso") != 0) {
		lep1_MiniIso_branch = tree->GetBranch("lep1_MiniIso");
		if (lep1_MiniIso_branch) {lep1_MiniIso_branch->SetAddress(&lep1_MiniIso_);}
	}
	lep1_mcid_branch = 0;
	if (tree->GetBranch("lep1_mcid") != 0) {
		lep1_mcid_branch = tree->GetBranch("lep1_mcid");
		if (lep1_mcid_branch) {lep1_mcid_branch->SetAddress(&lep1_mcid_);}
	}
	lep1_mcstatus_branch = 0;
	if (tree->GetBranch("lep1_mcstatus") != 0) {
		lep1_mcstatus_branch = tree->GetBranch("lep1_mcstatus");
		if (lep1_mcstatus_branch) {lep1_mcstatus_branch->SetAddress(&lep1_mcstatus_);}
	}
	lep1_mc3dr_branch = 0;
	if (tree->GetBranch("lep1_mc3dr") != 0) {
		lep1_mc3dr_branch = tree->GetBranch("lep1_mc3dr");
		if (lep1_mc3dr_branch) {lep1_mc3dr_branch->SetAddress(&lep1_mc3dr_);}
	}
	lep1_mc3id_branch = 0;
	if (tree->GetBranch("lep1_mc3id") != 0) {
		lep1_mc3id_branch = tree->GetBranch("lep1_mc3id");
		if (lep1_mc3id_branch) {lep1_mc3id_branch->SetAddress(&lep1_mc3id_);}
	}
	lep1_mc3idx_branch = 0;
	if (tree->GetBranch("lep1_mc3idx") != 0) {
		lep1_mc3idx_branch = tree->GetBranch("lep1_mc3idx");
		if (lep1_mc3idx_branch) {lep1_mc3idx_branch->SetAddress(&lep1_mc3idx_);}
	}
	lep1_mc3motherid_branch = 0;
	if (tree->GetBranch("lep1_mc3motherid") != 0) {
		lep1_mc3motherid_branch = tree->GetBranch("lep1_mc3motherid");
		if (lep1_mc3motherid_branch) {lep1_mc3motherid_branch->SetAddress(&lep1_mc3motherid_);}
	}
	lep1_mc3motheridx_branch = 0;
	if (tree->GetBranch("lep1_mc3motheridx") != 0) {
		lep1_mc3motheridx_branch = tree->GetBranch("lep1_mc3motheridx");
		if (lep1_mc3motheridx_branch) {lep1_mc3motheridx_branch->SetAddress(&lep1_mc3motheridx_);}
	}
	lep1_is_eleid_loose_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_loose") != 0) {
		lep1_is_eleid_loose_branch = tree->GetBranch("lep1_is_eleid_loose");
		if (lep1_is_eleid_loose_branch) {lep1_is_eleid_loose_branch->SetAddress(&lep1_is_eleid_loose_);}
	}
	lep1_is_eleid_medium_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_medium") != 0) {
		lep1_is_eleid_medium_branch = tree->GetBranch("lep1_is_eleid_medium");
		if (lep1_is_eleid_medium_branch) {lep1_is_eleid_medium_branch->SetAddress(&lep1_is_eleid_medium_);}
	}
	lep1_is_eleid_tight_branch = 0;
	if (tree->GetBranch("lep1_is_eleid_tight") != 0) {
		lep1_is_eleid_tight_branch = tree->GetBranch("lep1_is_eleid_tight");
		if (lep1_is_eleid_tight_branch) {lep1_is_eleid_tight_branch->SetAddress(&lep1_is_eleid_tight_);}
	}
	lep1_is_phys14_loose_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_loose_noIso") != 0) {
		lep1_is_phys14_loose_noIso_branch = tree->GetBranch("lep1_is_phys14_loose_noIso");
		if (lep1_is_phys14_loose_noIso_branch) {lep1_is_phys14_loose_noIso_branch->SetAddress(&lep1_is_phys14_loose_noIso_);}
	}
	lep1_is_phys14_medium_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_medium_noIso") != 0) {
		lep1_is_phys14_medium_noIso_branch = tree->GetBranch("lep1_is_phys14_medium_noIso");
		if (lep1_is_phys14_medium_noIso_branch) {lep1_is_phys14_medium_noIso_branch->SetAddress(&lep1_is_phys14_medium_noIso_);}
	}
	lep1_is_phys14_tight_noIso_branch = 0;
	if (tree->GetBranch("lep1_is_phys14_tight_noIso") != 0) {
		lep1_is_phys14_tight_noIso_branch = tree->GetBranch("lep1_is_phys14_tight_noIso");
		if (lep1_is_phys14_tight_noIso_branch) {lep1_is_phys14_tight_noIso_branch->SetAddress(&lep1_is_phys14_tight_noIso_);}
	}
	lep1_eoverpin_branch = 0;
	if (tree->GetBranch("lep1_eoverpin") != 0) {
		lep1_eoverpin_branch = tree->GetBranch("lep1_eoverpin");
		if (lep1_eoverpin_branch) {lep1_eoverpin_branch->SetAddress(&lep1_eoverpin_);}
	}
	lep1_is_muoid_loose_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_loose") != 0) {
		lep1_is_muoid_loose_branch = tree->GetBranch("lep1_is_muoid_loose");
		if (lep1_is_muoid_loose_branch) {lep1_is_muoid_loose_branch->SetAddress(&lep1_is_muoid_loose_);}
	}
	lep1_is_muoid_medium_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_medium") != 0) {
		lep1_is_muoid_medium_branch = tree->GetBranch("lep1_is_muoid_medium");
		if (lep1_is_muoid_medium_branch) {lep1_is_muoid_medium_branch->SetAddress(&lep1_is_muoid_medium_);}
	}
	lep1_is_muoid_tight_branch = 0;
	if (tree->GetBranch("lep1_is_muoid_tight") != 0) {
		lep1_is_muoid_tight_branch = tree->GetBranch("lep1_is_muoid_tight");
		if (lep1_is_muoid_tight_branch) {lep1_is_muoid_tight_branch->SetAddress(&lep1_is_muoid_tight_);}
	}
	lep1_ip3d_branch = 0;
	if (tree->GetBranch("lep1_ip3d") != 0) {
		lep1_ip3d_branch = tree->GetBranch("lep1_ip3d");
		if (lep1_ip3d_branch) {lep1_ip3d_branch->SetAddress(&lep1_ip3d_);}
	}
	lep1_ip3derr_branch = 0;
	if (tree->GetBranch("lep1_ip3derr") != 0) {
		lep1_ip3derr_branch = tree->GetBranch("lep1_ip3derr");
		if (lep1_ip3derr_branch) {lep1_ip3derr_branch->SetAddress(&lep1_ip3derr_);}
	}
	lep1_is_pfmu_branch = 0;
	if (tree->GetBranch("lep1_is_pfmu") != 0) {
		lep1_is_pfmu_branch = tree->GetBranch("lep1_is_pfmu");
		if (lep1_is_pfmu_branch) {lep1_is_pfmu_branch->SetAddress(&lep1_is_pfmu_);}
	}
	lep1_passMediumID_branch = 0;
	if (tree->GetBranch("lep1_passMediumID") != 0) {
		lep1_passMediumID_branch = tree->GetBranch("lep1_passMediumID");
		if (lep1_passMediumID_branch) {lep1_passMediumID_branch->SetAddress(&lep1_passMediumID_);}
	}
	lep1_passVeto_branch = 0;
	if (tree->GetBranch("lep1_passVeto") != 0) {
		lep1_passVeto_branch = tree->GetBranch("lep1_passVeto");
		if (lep1_passVeto_branch) {lep1_passVeto_branch->SetAddress(&lep1_passVeto_);}
	}
	lep1_pt_branch = 0;
	if (tree->GetBranch("lep1_pt") != 0) {
		lep1_pt_branch = tree->GetBranch("lep1_pt");
		if (lep1_pt_branch) {lep1_pt_branch->SetAddress(&lep1_pt_);}
	}
	lep1_eta_branch = 0;
	if (tree->GetBranch("lep1_eta") != 0) {
		lep1_eta_branch = tree->GetBranch("lep1_eta");
		if (lep1_eta_branch) {lep1_eta_branch->SetAddress(&lep1_eta_);}
	}
	lep1_phi_branch = 0;
	if (tree->GetBranch("lep1_phi") != 0) {
		lep1_phi_branch = tree->GetBranch("lep1_phi");
		if (lep1_phi_branch) {lep1_phi_branch->SetAddress(&lep1_phi_);}
	}
	lep1_mass_branch = 0;
	if (tree->GetBranch("lep1_mass") != 0) {
		lep1_mass_branch = tree->GetBranch("lep1_mass");
		if (lep1_mass_branch) {lep1_mass_branch->SetAddress(&lep1_mass_);}
	}
	lep2_is_mu_branch = 0;
	if (tree->GetBranch("lep2_is_mu") != 0) {
		lep2_is_mu_branch = tree->GetBranch("lep2_is_mu");
		if (lep2_is_mu_branch) {lep2_is_mu_branch->SetAddress(&lep2_is_mu_);}
	}
	lep2_is_el_branch = 0;
	if (tree->GetBranch("lep2_is_el") != 0) {
		lep2_is_el_branch = tree->GetBranch("lep2_is_el");
		if (lep2_is_el_branch) {lep2_is_el_branch->SetAddress(&lep2_is_el_);}
	}
	lep2_charge_branch = 0;
	if (tree->GetBranch("lep2_charge") != 0) {
		lep2_charge_branch = tree->GetBranch("lep2_charge");
		if (lep2_charge_branch) {lep2_charge_branch->SetAddress(&lep2_charge_);}
	}
	lep2_pdgid_branch = 0;
	if (tree->GetBranch("lep2_pdgid") != 0) {
		lep2_pdgid_branch = tree->GetBranch("lep2_pdgid");
		if (lep2_pdgid_branch) {lep2_pdgid_branch->SetAddress(&lep2_pdgid_);}
	}
	lep2_type_branch = 0;
	if (tree->GetBranch("lep2_type") != 0) {
		lep2_type_branch = tree->GetBranch("lep2_type");
		if (lep2_type_branch) {lep2_type_branch->SetAddress(&lep2_type_);}
	}
	lep2_production_type_branch = 0;
	if (tree->GetBranch("lep2_production_type") != 0) {
		lep2_production_type_branch = tree->GetBranch("lep2_production_type");
		if (lep2_production_type_branch) {lep2_production_type_branch->SetAddress(&lep2_production_type_);}
	}
	lep2_d0_branch = 0;
	if (tree->GetBranch("lep2_d0") != 0) {
		lep2_d0_branch = tree->GetBranch("lep2_d0");
		if (lep2_d0_branch) {lep2_d0_branch->SetAddress(&lep2_d0_);}
	}
	lep2_d0err_branch = 0;
	if (tree->GetBranch("lep2_d0err") != 0) {
		lep2_d0err_branch = tree->GetBranch("lep2_d0err");
		if (lep2_d0err_branch) {lep2_d0err_branch->SetAddress(&lep2_d0err_);}
	}
	lep2_dz_branch = 0;
	if (tree->GetBranch("lep2_dz") != 0) {
		lep2_dz_branch = tree->GetBranch("lep2_dz");
		if (lep2_dz_branch) {lep2_dz_branch->SetAddress(&lep2_dz_);}
	}
	lep2_dzerr_branch = 0;
	if (tree->GetBranch("lep2_dzerr") != 0) {
		lep2_dzerr_branch = tree->GetBranch("lep2_dzerr");
		if (lep2_dzerr_branch) {lep2_dzerr_branch->SetAddress(&lep2_dzerr_);}
	}
	lep2_sigmaIEtaEta_fill5x5_branch = 0;
	if (tree->GetBranch("lep2_sigmaIEtaEta_fill5x5") != 0) {
		lep2_sigmaIEtaEta_fill5x5_branch = tree->GetBranch("lep2_sigmaIEtaEta_fill5x5");
		if (lep2_sigmaIEtaEta_fill5x5_branch) {lep2_sigmaIEtaEta_fill5x5_branch->SetAddress(&lep2_sigmaIEtaEta_fill5x5_);}
	}
	lep2_dEtaIn_branch = 0;
	if (tree->GetBranch("lep2_dEtaIn") != 0) {
		lep2_dEtaIn_branch = tree->GetBranch("lep2_dEtaIn");
		if (lep2_dEtaIn_branch) {lep2_dEtaIn_branch->SetAddress(&lep2_dEtaIn_);}
	}
	lep2_dPhiIn_branch = 0;
	if (tree->GetBranch("lep2_dPhiIn") != 0) {
		lep2_dPhiIn_branch = tree->GetBranch("lep2_dPhiIn");
		if (lep2_dPhiIn_branch) {lep2_dPhiIn_branch->SetAddress(&lep2_dPhiIn_);}
	}
	lep2_hOverE_branch = 0;
	if (tree->GetBranch("lep2_hOverE") != 0) {
		lep2_hOverE_branch = tree->GetBranch("lep2_hOverE");
		if (lep2_hOverE_branch) {lep2_hOverE_branch->SetAddress(&lep2_hOverE_);}
	}
	lep2_ooEmooP_branch = 0;
	if (tree->GetBranch("lep2_ooEmooP") != 0) {
		lep2_ooEmooP_branch = tree->GetBranch("lep2_ooEmooP");
		if (lep2_ooEmooP_branch) {lep2_ooEmooP_branch->SetAddress(&lep2_ooEmooP_);}
	}
	lep2_expectedMissingInnerHits_branch = 0;
	if (tree->GetBranch("lep2_expectedMissingInnerHits") != 0) {
		lep2_expectedMissingInnerHits_branch = tree->GetBranch("lep2_expectedMissingInnerHits");
		if (lep2_expectedMissingInnerHits_branch) {lep2_expectedMissingInnerHits_branch->SetAddress(&lep2_expectedMissingInnerHits_);}
	}
	lep2_conversionVeto_branch = 0;
	if (tree->GetBranch("lep2_conversionVeto") != 0) {
		lep2_conversionVeto_branch = tree->GetBranch("lep2_conversionVeto");
		if (lep2_conversionVeto_branch) {lep2_conversionVeto_branch->SetAddress(&lep2_conversionVeto_);}
	}
	lep2_etaSC_branch = 0;
	if (tree->GetBranch("lep2_etaSC") != 0) {
		lep2_etaSC_branch = tree->GetBranch("lep2_etaSC");
		if (lep2_etaSC_branch) {lep2_etaSC_branch->SetAddress(&lep2_etaSC_);}
	}
	lep2_ChiSqr_branch = 0;
	if (tree->GetBranch("lep2_ChiSqr") != 0) {
		lep2_ChiSqr_branch = tree->GetBranch("lep2_ChiSqr");
		if (lep2_ChiSqr_branch) {lep2_ChiSqr_branch->SetAddress(&lep2_ChiSqr_);}
	}
	lep2_chiso_branch = 0;
	if (tree->GetBranch("lep2_chiso") != 0) {
		lep2_chiso_branch = tree->GetBranch("lep2_chiso");
		if (lep2_chiso_branch) {lep2_chiso_branch->SetAddress(&lep2_chiso_);}
	}
	lep2_nhiso_branch = 0;
	if (tree->GetBranch("lep2_nhiso") != 0) {
		lep2_nhiso_branch = tree->GetBranch("lep2_nhiso");
		if (lep2_nhiso_branch) {lep2_nhiso_branch->SetAddress(&lep2_nhiso_);}
	}
	lep2_emiso_branch = 0;
	if (tree->GetBranch("lep2_emiso") != 0) {
		lep2_emiso_branch = tree->GetBranch("lep2_emiso");
		if (lep2_emiso_branch) {lep2_emiso_branch->SetAddress(&lep2_emiso_);}
	}
	lep2_deltaBeta_branch = 0;
	if (tree->GetBranch("lep2_deltaBeta") != 0) {
		lep2_deltaBeta_branch = tree->GetBranch("lep2_deltaBeta");
		if (lep2_deltaBeta_branch) {lep2_deltaBeta_branch->SetAddress(&lep2_deltaBeta_);}
	}
	lep2_relIso03DB_branch = 0;
	if (tree->GetBranch("lep2_relIso03DB") != 0) {
		lep2_relIso03DB_branch = tree->GetBranch("lep2_relIso03DB");
		if (lep2_relIso03DB_branch) {lep2_relIso03DB_branch->SetAddress(&lep2_relIso03DB_);}
	}
	lep2_relIso03EA_branch = 0;
	if (tree->GetBranch("lep2_relIso03EA") != 0) {
		lep2_relIso03EA_branch = tree->GetBranch("lep2_relIso03EA");
		if (lep2_relIso03EA_branch) {lep2_relIso03EA_branch->SetAddress(&lep2_relIso03EA_);}
	}
	lep2_relIso04DB_branch = 0;
	if (tree->GetBranch("lep2_relIso04DB") != 0) {
		lep2_relIso04DB_branch = tree->GetBranch("lep2_relIso04DB");
		if (lep2_relIso04DB_branch) {lep2_relIso04DB_branch->SetAddress(&lep2_relIso04DB_);}
	}
	lep2_miniRelIsoDB_branch = 0;
	if (tree->GetBranch("lep2_miniRelIsoDB") != 0) {
		lep2_miniRelIsoDB_branch = tree->GetBranch("lep2_miniRelIsoDB");
		if (lep2_miniRelIsoDB_branch) {lep2_miniRelIsoDB_branch->SetAddress(&lep2_miniRelIsoDB_);}
	}
	lep2_miniRelIsoEA_branch = 0;
	if (tree->GetBranch("lep2_miniRelIsoEA") != 0) {
		lep2_miniRelIsoEA_branch = tree->GetBranch("lep2_miniRelIsoEA");
		if (lep2_miniRelIsoEA_branch) {lep2_miniRelIsoEA_branch->SetAddress(&lep2_miniRelIsoEA_);}
	}
	lep2_MiniIso_branch = 0;
	if (tree->GetBranch("lep2_MiniIso") != 0) {
		lep2_MiniIso_branch = tree->GetBranch("lep2_MiniIso");
		if (lep2_MiniIso_branch) {lep2_MiniIso_branch->SetAddress(&lep2_MiniIso_);}
	}
	lep2_mcid_branch = 0;
	if (tree->GetBranch("lep2_mcid") != 0) {
		lep2_mcid_branch = tree->GetBranch("lep2_mcid");
		if (lep2_mcid_branch) {lep2_mcid_branch->SetAddress(&lep2_mcid_);}
	}
	lep2_mcstatus_branch = 0;
	if (tree->GetBranch("lep2_mcstatus") != 0) {
		lep2_mcstatus_branch = tree->GetBranch("lep2_mcstatus");
		if (lep2_mcstatus_branch) {lep2_mcstatus_branch->SetAddress(&lep2_mcstatus_);}
	}
	lep2_mc3dr_branch = 0;
	if (tree->GetBranch("lep2_mc3dr") != 0) {
		lep2_mc3dr_branch = tree->GetBranch("lep2_mc3dr");
		if (lep2_mc3dr_branch) {lep2_mc3dr_branch->SetAddress(&lep2_mc3dr_);}
	}
	lep2_mc3id_branch = 0;
	if (tree->GetBranch("lep2_mc3id") != 0) {
		lep2_mc3id_branch = tree->GetBranch("lep2_mc3id");
		if (lep2_mc3id_branch) {lep2_mc3id_branch->SetAddress(&lep2_mc3id_);}
	}
	lep2_mc3idx_branch = 0;
	if (tree->GetBranch("lep2_mc3idx") != 0) {
		lep2_mc3idx_branch = tree->GetBranch("lep2_mc3idx");
		if (lep2_mc3idx_branch) {lep2_mc3idx_branch->SetAddress(&lep2_mc3idx_);}
	}
	lep2_mc3motherid_branch = 0;
	if (tree->GetBranch("lep2_mc3motherid") != 0) {
		lep2_mc3motherid_branch = tree->GetBranch("lep2_mc3motherid");
		if (lep2_mc3motherid_branch) {lep2_mc3motherid_branch->SetAddress(&lep2_mc3motherid_);}
	}
	lep2_mc3motheridx_branch = 0;
	if (tree->GetBranch("lep2_mc3motheridx") != 0) {
		lep2_mc3motheridx_branch = tree->GetBranch("lep2_mc3motheridx");
		if (lep2_mc3motheridx_branch) {lep2_mc3motheridx_branch->SetAddress(&lep2_mc3motheridx_);}
	}
	lep2_is_eleid_loose_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_loose") != 0) {
		lep2_is_eleid_loose_branch = tree->GetBranch("lep2_is_eleid_loose");
		if (lep2_is_eleid_loose_branch) {lep2_is_eleid_loose_branch->SetAddress(&lep2_is_eleid_loose_);}
	}
	lep2_is_eleid_medium_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_medium") != 0) {
		lep2_is_eleid_medium_branch = tree->GetBranch("lep2_is_eleid_medium");
		if (lep2_is_eleid_medium_branch) {lep2_is_eleid_medium_branch->SetAddress(&lep2_is_eleid_medium_);}
	}
	lep2_is_eleid_tight_branch = 0;
	if (tree->GetBranch("lep2_is_eleid_tight") != 0) {
		lep2_is_eleid_tight_branch = tree->GetBranch("lep2_is_eleid_tight");
		if (lep2_is_eleid_tight_branch) {lep2_is_eleid_tight_branch->SetAddress(&lep2_is_eleid_tight_);}
	}
	lep2_is_phys14_loose_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_loose_noIso") != 0) {
		lep2_is_phys14_loose_noIso_branch = tree->GetBranch("lep2_is_phys14_loose_noIso");
		if (lep2_is_phys14_loose_noIso_branch) {lep2_is_phys14_loose_noIso_branch->SetAddress(&lep2_is_phys14_loose_noIso_);}
	}
	lep2_is_phys14_medium_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_medium_noIso") != 0) {
		lep2_is_phys14_medium_noIso_branch = tree->GetBranch("lep2_is_phys14_medium_noIso");
		if (lep2_is_phys14_medium_noIso_branch) {lep2_is_phys14_medium_noIso_branch->SetAddress(&lep2_is_phys14_medium_noIso_);}
	}
	lep2_is_phys14_tight_noIso_branch = 0;
	if (tree->GetBranch("lep2_is_phys14_tight_noIso") != 0) {
		lep2_is_phys14_tight_noIso_branch = tree->GetBranch("lep2_is_phys14_tight_noIso");
		if (lep2_is_phys14_tight_noIso_branch) {lep2_is_phys14_tight_noIso_branch->SetAddress(&lep2_is_phys14_tight_noIso_);}
	}
	lep2_eoverpin_branch = 0;
	if (tree->GetBranch("lep2_eoverpin") != 0) {
		lep2_eoverpin_branch = tree->GetBranch("lep2_eoverpin");
		if (lep2_eoverpin_branch) {lep2_eoverpin_branch->SetAddress(&lep2_eoverpin_);}
	}
	lep2_is_muoid_loose_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_loose") != 0) {
		lep2_is_muoid_loose_branch = tree->GetBranch("lep2_is_muoid_loose");
		if (lep2_is_muoid_loose_branch) {lep2_is_muoid_loose_branch->SetAddress(&lep2_is_muoid_loose_);}
	}
	lep2_is_muoid_medium_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_medium") != 0) {
		lep2_is_muoid_medium_branch = tree->GetBranch("lep2_is_muoid_medium");
		if (lep2_is_muoid_medium_branch) {lep2_is_muoid_medium_branch->SetAddress(&lep2_is_muoid_medium_);}
	}
	lep2_is_muoid_tight_branch = 0;
	if (tree->GetBranch("lep2_is_muoid_tight") != 0) {
		lep2_is_muoid_tight_branch = tree->GetBranch("lep2_is_muoid_tight");
		if (lep2_is_muoid_tight_branch) {lep2_is_muoid_tight_branch->SetAddress(&lep2_is_muoid_tight_);}
	}
	lep2_ip3d_branch = 0;
	if (tree->GetBranch("lep2_ip3d") != 0) {
		lep2_ip3d_branch = tree->GetBranch("lep2_ip3d");
		if (lep2_ip3d_branch) {lep2_ip3d_branch->SetAddress(&lep2_ip3d_);}
	}
	lep2_ip3derr_branch = 0;
	if (tree->GetBranch("lep2_ip3derr") != 0) {
		lep2_ip3derr_branch = tree->GetBranch("lep2_ip3derr");
		if (lep2_ip3derr_branch) {lep2_ip3derr_branch->SetAddress(&lep2_ip3derr_);}
	}
	lep2_is_pfmu_branch = 0;
	if (tree->GetBranch("lep2_is_pfmu") != 0) {
		lep2_is_pfmu_branch = tree->GetBranch("lep2_is_pfmu");
		if (lep2_is_pfmu_branch) {lep2_is_pfmu_branch->SetAddress(&lep2_is_pfmu_);}
	}
	lep2_passMediumID_branch = 0;
	if (tree->GetBranch("lep2_passMediumID") != 0) {
		lep2_passMediumID_branch = tree->GetBranch("lep2_passMediumID");
		if (lep2_passMediumID_branch) {lep2_passMediumID_branch->SetAddress(&lep2_passMediumID_);}
	}
	lep2_passVeto_branch = 0;
	if (tree->GetBranch("lep2_passVeto") != 0) {
		lep2_passVeto_branch = tree->GetBranch("lep2_passVeto");
		if (lep2_passVeto_branch) {lep2_passVeto_branch->SetAddress(&lep2_passVeto_);}
	}
	lep2_pt_branch = 0;
	if (tree->GetBranch("lep2_pt") != 0) {
		lep2_pt_branch = tree->GetBranch("lep2_pt");
		if (lep2_pt_branch) {lep2_pt_branch->SetAddress(&lep2_pt_);}
	}
	lep2_eta_branch = 0;
	if (tree->GetBranch("lep2_eta") != 0) {
		lep2_eta_branch = tree->GetBranch("lep2_eta");
		if (lep2_eta_branch) {lep2_eta_branch->SetAddress(&lep2_eta_);}
	}
	lep2_phi_branch = 0;
	if (tree->GetBranch("lep2_phi") != 0) {
		lep2_phi_branch = tree->GetBranch("lep2_phi");
		if (lep2_phi_branch) {lep2_phi_branch->SetAddress(&lep2_phi_);}
	}
	lep2_mass_branch = 0;
	if (tree->GetBranch("lep2_mass") != 0) {
		lep2_mass_branch = tree->GetBranch("lep2_mass");
		if (lep2_mass_branch) {lep2_mass_branch->SetAddress(&lep2_mass_);}
	}
	nGoodGenJets_branch = 0;
	if (tree->GetBranch("nGoodGenJets") != 0) {
		nGoodGenJets_branch = tree->GetBranch("nGoodGenJets");
		if (nGoodGenJets_branch) {nGoodGenJets_branch->SetAddress(&nGoodGenJets_);}
	}
	ngoodjets_branch = 0;
	if (tree->GetBranch("ngoodjets") != 0) {
		ngoodjets_branch = tree->GetBranch("ngoodjets");
		if (ngoodjets_branch) {ngoodjets_branch->SetAddress(&ngoodjets_);}
	}
	nfailjets_branch = 0;
	if (tree->GetBranch("nfailjets") != 0) {
		nfailjets_branch = tree->GetBranch("nfailjets");
		if (nfailjets_branch) {nfailjets_branch->SetAddress(&nfailjets_);}
	}
	ak8GoodPFJets_branch = 0;
	if (tree->GetBranch("ak8GoodPFJets") != 0) {
		ak8GoodPFJets_branch = tree->GetBranch("ak8GoodPFJets");
		if (ak8GoodPFJets_branch) {ak8GoodPFJets_branch->SetAddress(&ak8GoodPFJets_);}
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
	ak4_htssm_branch = 0;
	if (tree->GetBranch("ak4_htssm") != 0) {
		ak4_htssm_branch = tree->GetBranch("ak4_htssm");
		if (ak4_htssm_branch) {ak4_htssm_branch->SetAddress(&ak4_htssm_);}
	}
	ak4_htosm_branch = 0;
	if (tree->GetBranch("ak4_htosm") != 0) {
		ak4_htosm_branch = tree->GetBranch("ak4_htosm");
		if (ak4_htosm_branch) {ak4_htosm_branch->SetAddress(&ak4_htosm_);}
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
	ak4pfjets_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_pt") != 0) {
		ak4pfjets_pt_branch = tree->GetBranch("ak4pfjets_pt");
		if (ak4pfjets_pt_branch) {ak4pfjets_pt_branch->SetAddress(&ak4pfjets_pt_);}
	}
	ak4pfjets_eta_branch = 0;
	if (tree->GetBranch("ak4pfjets_eta") != 0) {
		ak4pfjets_eta_branch = tree->GetBranch("ak4pfjets_eta");
		if (ak4pfjets_eta_branch) {ak4pfjets_eta_branch->SetAddress(&ak4pfjets_eta_);}
	}
	ak4pfjets_phi_branch = 0;
	if (tree->GetBranch("ak4pfjets_phi") != 0) {
		ak4pfjets_phi_branch = tree->GetBranch("ak4pfjets_phi");
		if (ak4pfjets_phi_branch) {ak4pfjets_phi_branch->SetAddress(&ak4pfjets_phi_);}
	}
	ak4pfjets_mass_branch = 0;
	if (tree->GetBranch("ak4pfjets_mass") != 0) {
		ak4pfjets_mass_branch = tree->GetBranch("ak4pfjets_mass");
		if (ak4pfjets_mass_branch) {ak4pfjets_mass_branch->SetAddress(&ak4pfjets_mass_);}
	}
	ak4pfjets_passMEDbtag_branch = 0;
	if (tree->GetBranch("ak4pfjets_passMEDbtag") != 0) {
		ak4pfjets_passMEDbtag_branch = tree->GetBranch("ak4pfjets_passMEDbtag");
		if (ak4pfjets_passMEDbtag_branch) {ak4pfjets_passMEDbtag_branch->SetAddress(&ak4pfjets_passMEDbtag_);}
	}
	ak4pfjets_qg_disc_branch = 0;
	if (tree->GetBranch("ak4pfjets_qg_disc") != 0) {
		ak4pfjets_qg_disc_branch = tree->GetBranch("ak4pfjets_qg_disc");
		if (ak4pfjets_qg_disc_branch) {ak4pfjets_qg_disc_branch->SetAddress(&ak4pfjets_qg_disc_);}
	}
	ak4pfjets_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjets_CSV") != 0) {
		ak4pfjets_CSV_branch = tree->GetBranch("ak4pfjets_CSV");
		if (ak4pfjets_CSV_branch) {ak4pfjets_CSV_branch->SetAddress(&ak4pfjets_CSV_);}
	}
	ak4pfjets_puid_branch = 0;
	if (tree->GetBranch("ak4pfjets_puid") != 0) {
		ak4pfjets_puid_branch = tree->GetBranch("ak4pfjets_puid");
		if (ak4pfjets_puid_branch) {ak4pfjets_puid_branch->SetAddress(&ak4pfjets_puid_);}
	}
	ak4pfjets_parton_flavor_branch = 0;
	if (tree->GetBranch("ak4pfjets_parton_flavor") != 0) {
		ak4pfjets_parton_flavor_branch = tree->GetBranch("ak4pfjets_parton_flavor");
		if (ak4pfjets_parton_flavor_branch) {ak4pfjets_parton_flavor_branch->SetAddress(&ak4pfjets_parton_flavor_);}
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
	ak4pfjets_medium_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_medium_pfid") != 0) {
		ak4pfjets_medium_pfid_branch = tree->GetBranch("ak4pfjets_medium_pfid");
		if (ak4pfjets_medium_pfid_branch) {ak4pfjets_medium_pfid_branch->SetAddress(&ak4pfjets_medium_pfid_);}
	}
	ak4pfjets_tight_pfid_branch = 0;
	if (tree->GetBranch("ak4pfjets_tight_pfid") != 0) {
		ak4pfjets_tight_pfid_branch = tree->GetBranch("ak4pfjets_tight_pfid");
		if (ak4pfjets_tight_pfid_branch) {ak4pfjets_tight_pfid_branch->SetAddress(&ak4pfjets_tight_pfid_);}
	}
	ak4pfjets_MEDbjet_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_MEDbjet_pt") != 0) {
		ak4pfjets_MEDbjet_pt_branch = tree->GetBranch("ak4pfjets_MEDbjet_pt");
		if (ak4pfjets_MEDbjet_pt_branch) {ak4pfjets_MEDbjet_pt_branch->SetAddress(&ak4pfjets_MEDbjet_pt_);}
	}
	ak4pfjets_leadMEDbjet_pt_branch = 0;
	if (tree->GetBranch("ak4pfjets_leadMEDbjet_pt") != 0) {
		ak4pfjets_leadMEDbjet_pt_branch = tree->GetBranch("ak4pfjets_leadMEDbjet_pt");
		if (ak4pfjets_leadMEDbjet_pt_branch) {ak4pfjets_leadMEDbjet_pt_branch->SetAddress(&ak4pfjets_leadMEDbjet_pt_);}
	}
	ak4pfjets_chf_branch = 0;
	if (tree->GetBranch("ak4pfjets_chf") != 0) {
		ak4pfjets_chf_branch = tree->GetBranch("ak4pfjets_chf");
		if (ak4pfjets_chf_branch) {ak4pfjets_chf_branch->SetAddress(&ak4pfjets_chf_);}
	}
	ak4pfjets_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjets_nhf") != 0) {
		ak4pfjets_nhf_branch = tree->GetBranch("ak4pfjets_nhf");
		if (ak4pfjets_nhf_branch) {ak4pfjets_nhf_branch->SetAddress(&ak4pfjets_nhf_);}
	}
	ak4pfjets_cef_branch = 0;
	if (tree->GetBranch("ak4pfjets_cef") != 0) {
		ak4pfjets_cef_branch = tree->GetBranch("ak4pfjets_cef");
		if (ak4pfjets_cef_branch) {ak4pfjets_cef_branch->SetAddress(&ak4pfjets_cef_);}
	}
	ak4pfjets_nef_branch = 0;
	if (tree->GetBranch("ak4pfjets_nef") != 0) {
		ak4pfjets_nef_branch = tree->GetBranch("ak4pfjets_nef");
		if (ak4pfjets_nef_branch) {ak4pfjets_nef_branch->SetAddress(&ak4pfjets_nef_);}
	}
	ak4pfjets_muf_branch = 0;
	if (tree->GetBranch("ak4pfjets_muf") != 0) {
		ak4pfjets_muf_branch = tree->GetBranch("ak4pfjets_muf");
		if (ak4pfjets_muf_branch) {ak4pfjets_muf_branch->SetAddress(&ak4pfjets_muf_);}
	}
	ak4pfjets_cm_branch = 0;
	if (tree->GetBranch("ak4pfjets_cm") != 0) {
		ak4pfjets_cm_branch = tree->GetBranch("ak4pfjets_cm");
		if (ak4pfjets_cm_branch) {ak4pfjets_cm_branch->SetAddress(&ak4pfjets_cm_);}
	}
	ak4pfjets_nm_branch = 0;
	if (tree->GetBranch("ak4pfjets_nm") != 0) {
		ak4pfjets_nm_branch = tree->GetBranch("ak4pfjets_nm");
		if (ak4pfjets_nm_branch) {ak4pfjets_nm_branch->SetAddress(&ak4pfjets_nm_);}
	}
	ak4pfjets_mc3dr_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3dr") != 0) {
		ak4pfjets_mc3dr_branch = tree->GetBranch("ak4pfjets_mc3dr");
		if (ak4pfjets_mc3dr_branch) {ak4pfjets_mc3dr_branch->SetAddress(&ak4pfjets_mc3dr_);}
	}
	ak4pfjets_mc3id_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3id") != 0) {
		ak4pfjets_mc3id_branch = tree->GetBranch("ak4pfjets_mc3id");
		if (ak4pfjets_mc3id_branch) {ak4pfjets_mc3id_branch->SetAddress(&ak4pfjets_mc3id_);}
	}
	ak4pfjets_mc3idx_branch = 0;
	if (tree->GetBranch("ak4pfjets_mc3idx") != 0) {
		ak4pfjets_mc3idx_branch = tree->GetBranch("ak4pfjets_mc3idx");
		if (ak4pfjets_mc3idx_branch) {ak4pfjets_mc3idx_branch->SetAddress(&ak4pfjets_mc3idx_);}
	}
	ak4pfjets_mcmotherid_branch = 0;
	if (tree->GetBranch("ak4pfjets_mcmotherid") != 0) {
		ak4pfjets_mcmotherid_branch = tree->GetBranch("ak4pfjets_mcmotherid");
		if (ak4pfjets_mcmotherid_branch) {ak4pfjets_mcmotherid_branch->SetAddress(&ak4pfjets_mcmotherid_);}
	}
	ak4pfjet_overlep1_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_CSV") != 0) {
		ak4pfjet_overlep1_CSV_branch = tree->GetBranch("ak4pfjet_overlep1_CSV");
		if (ak4pfjet_overlep1_CSV_branch) {ak4pfjet_overlep1_CSV_branch->SetAddress(&ak4pfjet_overlep1_CSV_);}
	}
	ak4pfjet_overlep1_pu_id_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_pu_id") != 0) {
		ak4pfjet_overlep1_pu_id_branch = tree->GetBranch("ak4pfjet_overlep1_pu_id");
		if (ak4pfjet_overlep1_pu_id_branch) {ak4pfjet_overlep1_pu_id_branch->SetAddress(&ak4pfjet_overlep1_pu_id_);}
	}
	ak4pfjet_overlep1_chf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_chf") != 0) {
		ak4pfjet_overlep1_chf_branch = tree->GetBranch("ak4pfjet_overlep1_chf");
		if (ak4pfjet_overlep1_chf_branch) {ak4pfjet_overlep1_chf_branch->SetAddress(&ak4pfjet_overlep1_chf_);}
	}
	ak4pfjet_overlep1_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nhf") != 0) {
		ak4pfjet_overlep1_nhf_branch = tree->GetBranch("ak4pfjet_overlep1_nhf");
		if (ak4pfjet_overlep1_nhf_branch) {ak4pfjet_overlep1_nhf_branch->SetAddress(&ak4pfjet_overlep1_nhf_);}
	}
	ak4pfjet_overlep1_cef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_cef") != 0) {
		ak4pfjet_overlep1_cef_branch = tree->GetBranch("ak4pfjet_overlep1_cef");
		if (ak4pfjet_overlep1_cef_branch) {ak4pfjet_overlep1_cef_branch->SetAddress(&ak4pfjet_overlep1_cef_);}
	}
	ak4pfjet_overlep1_nef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nef") != 0) {
		ak4pfjet_overlep1_nef_branch = tree->GetBranch("ak4pfjet_overlep1_nef");
		if (ak4pfjet_overlep1_nef_branch) {ak4pfjet_overlep1_nef_branch->SetAddress(&ak4pfjet_overlep1_nef_);}
	}
	ak4pfjet_overlep1_muf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_muf") != 0) {
		ak4pfjet_overlep1_muf_branch = tree->GetBranch("ak4pfjet_overlep1_muf");
		if (ak4pfjet_overlep1_muf_branch) {ak4pfjet_overlep1_muf_branch->SetAddress(&ak4pfjet_overlep1_muf_);}
	}
	ak4pfjet_overlep1_cm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_cm") != 0) {
		ak4pfjet_overlep1_cm_branch = tree->GetBranch("ak4pfjet_overlep1_cm");
		if (ak4pfjet_overlep1_cm_branch) {ak4pfjet_overlep1_cm_branch->SetAddress(&ak4pfjet_overlep1_cm_);}
	}
	ak4pfjet_overlep1_nm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep1_nm") != 0) {
		ak4pfjet_overlep1_nm_branch = tree->GetBranch("ak4pfjet_overlep1_nm");
		if (ak4pfjet_overlep1_nm_branch) {ak4pfjet_overlep1_nm_branch->SetAddress(&ak4pfjet_overlep1_nm_);}
	}
	ak4pfjet_overlep2_CSV_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_CSV") != 0) {
		ak4pfjet_overlep2_CSV_branch = tree->GetBranch("ak4pfjet_overlep2_CSV");
		if (ak4pfjet_overlep2_CSV_branch) {ak4pfjet_overlep2_CSV_branch->SetAddress(&ak4pfjet_overlep2_CSV_);}
	}
	ak4pfjet_overlep2_pu_id_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_pu_id") != 0) {
		ak4pfjet_overlep2_pu_id_branch = tree->GetBranch("ak4pfjet_overlep2_pu_id");
		if (ak4pfjet_overlep2_pu_id_branch) {ak4pfjet_overlep2_pu_id_branch->SetAddress(&ak4pfjet_overlep2_pu_id_);}
	}
	ak4pfjet_overlep2_chf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_chf") != 0) {
		ak4pfjet_overlep2_chf_branch = tree->GetBranch("ak4pfjet_overlep2_chf");
		if (ak4pfjet_overlep2_chf_branch) {ak4pfjet_overlep2_chf_branch->SetAddress(&ak4pfjet_overlep2_chf_);}
	}
	ak4pfjet_overlep2_nhf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nhf") != 0) {
		ak4pfjet_overlep2_nhf_branch = tree->GetBranch("ak4pfjet_overlep2_nhf");
		if (ak4pfjet_overlep2_nhf_branch) {ak4pfjet_overlep2_nhf_branch->SetAddress(&ak4pfjet_overlep2_nhf_);}
	}
	ak4pfjet_overlep2_cef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_cef") != 0) {
		ak4pfjet_overlep2_cef_branch = tree->GetBranch("ak4pfjet_overlep2_cef");
		if (ak4pfjet_overlep2_cef_branch) {ak4pfjet_overlep2_cef_branch->SetAddress(&ak4pfjet_overlep2_cef_);}
	}
	ak4pfjet_overlep2_nef_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nef") != 0) {
		ak4pfjet_overlep2_nef_branch = tree->GetBranch("ak4pfjet_overlep2_nef");
		if (ak4pfjet_overlep2_nef_branch) {ak4pfjet_overlep2_nef_branch->SetAddress(&ak4pfjet_overlep2_nef_);}
	}
	ak4pfjet_overlep2_muf_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_muf") != 0) {
		ak4pfjet_overlep2_muf_branch = tree->GetBranch("ak4pfjet_overlep2_muf");
		if (ak4pfjet_overlep2_muf_branch) {ak4pfjet_overlep2_muf_branch->SetAddress(&ak4pfjet_overlep2_muf_);}
	}
	ak4pfjet_overlep2_cm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_cm") != 0) {
		ak4pfjet_overlep2_cm_branch = tree->GetBranch("ak4pfjet_overlep2_cm");
		if (ak4pfjet_overlep2_cm_branch) {ak4pfjet_overlep2_cm_branch->SetAddress(&ak4pfjet_overlep2_cm_);}
	}
	ak4pfjet_overlep2_nm_branch = 0;
	if (tree->GetBranch("ak4pfjet_overlep2_nm") != 0) {
		ak4pfjet_overlep2_nm_branch = tree->GetBranch("ak4pfjet_overlep2_nm");
		if (ak4pfjet_overlep2_nm_branch) {ak4pfjet_overlep2_nm_branch->SetAddress(&ak4pfjet_overlep2_nm_);}
	}
	ak8pfjets_tau1_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau1") != 0) {
		ak8pfjets_tau1_branch = tree->GetBranch("ak8pfjets_tau1");
		if (ak8pfjets_tau1_branch) {ak8pfjets_tau1_branch->SetAddress(&ak8pfjets_tau1_);}
	}
	ak8pfjets_tau2_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau2") != 0) {
		ak8pfjets_tau2_branch = tree->GetBranch("ak8pfjets_tau2");
		if (ak8pfjets_tau2_branch) {ak8pfjets_tau2_branch->SetAddress(&ak8pfjets_tau2_);}
	}
	ak8pfjets_tau3_branch = 0;
	if (tree->GetBranch("ak8pfjets_tau3") != 0) {
		ak8pfjets_tau3_branch = tree->GetBranch("ak8pfjets_tau3");
		if (ak8pfjets_tau3_branch) {ak8pfjets_tau3_branch->SetAddress(&ak8pfjets_tau3_);}
	}
	ak8pfjets_top_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_top_mass") != 0) {
		ak8pfjets_top_mass_branch = tree->GetBranch("ak8pfjets_top_mass");
		if (ak8pfjets_top_mass_branch) {ak8pfjets_top_mass_branch->SetAddress(&ak8pfjets_top_mass_);}
	}
	ak8pfjets_pruned_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_pruned_mass") != 0) {
		ak8pfjets_pruned_mass_branch = tree->GetBranch("ak8pfjets_pruned_mass");
		if (ak8pfjets_pruned_mass_branch) {ak8pfjets_pruned_mass_branch->SetAddress(&ak8pfjets_pruned_mass_);}
	}
	ak8pfjets_trimmed_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_trimmed_mass") != 0) {
		ak8pfjets_trimmed_mass_branch = tree->GetBranch("ak8pfjets_trimmed_mass");
		if (ak8pfjets_trimmed_mass_branch) {ak8pfjets_trimmed_mass_branch->SetAddress(&ak8pfjets_trimmed_mass_);}
	}
	ak8pfjets_filtered_mass_branch = 0;
	if (tree->GetBranch("ak8pfjets_filtered_mass") != 0) {
		ak8pfjets_filtered_mass_branch = tree->GetBranch("ak8pfjets_filtered_mass");
		if (ak8pfjets_filtered_mass_branch) {ak8pfjets_filtered_mass_branch->SetAddress(&ak8pfjets_filtered_mass_);}
	}
	ak8pfjets_pu_id_branch = 0;
	if (tree->GetBranch("ak8pfjets_pu_id") != 0) {
		ak8pfjets_pu_id_branch = tree->GetBranch("ak8pfjets_pu_id");
		if (ak8pfjets_pu_id_branch) {ak8pfjets_pu_id_branch->SetAddress(&ak8pfjets_pu_id_);}
	}
	ak8pfjets_parton_flavor_branch = 0;
	if (tree->GetBranch("ak8pfjets_parton_flavor") != 0) {
		ak8pfjets_parton_flavor_branch = tree->GetBranch("ak8pfjets_parton_flavor");
		if (ak8pfjets_parton_flavor_branch) {ak8pfjets_parton_flavor_branch->SetAddress(&ak8pfjets_parton_flavor_);}
	}
	tau_IDnames_branch = 0;
	if (tree->GetBranch("tau_IDnames") != 0) {
		tau_IDnames_branch = tree->GetBranch("tau_IDnames");
		if (tau_IDnames_branch) {tau_IDnames_branch->SetAddress(&tau_IDnames_);}
	}
	tau_isocand_p4_branch = 0;
	if (tree->GetBranch("tau_isocand_p4") != 0) {
		tau_isocand_p4_branch = tree->GetBranch("tau_isocand_p4");
		if (tau_isocand_p4_branch) {tau_isocand_p4_branch->SetAddress(&tau_isocand_p4_);}
	}
	tau_sigcand_p4_branch = 0;
	if (tree->GetBranch("tau_sigcand_p4") != 0) {
		tau_sigcand_p4_branch = tree->GetBranch("tau_sigcand_p4");
		if (tau_sigcand_p4_branch) {tau_sigcand_p4_branch->SetAddress(&tau_sigcand_p4_);}
	}
	tau_mass_branch = 0;
	if (tree->GetBranch("tau_mass") != 0) {
		tau_mass_branch = tree->GetBranch("tau_mass");
		if (tau_mass_branch) {tau_mass_branch->SetAddress(&tau_mass_);}
	}
	tau_ID_branch = 0;
	if (tree->GetBranch("tau_ID") != 0) {
		tau_ID_branch = tree->GetBranch("tau_ID");
		if (tau_ID_branch) {tau_ID_branch->SetAddress(&tau_ID_);}
	}
	tau_passID_branch = 0;
	if (tree->GetBranch("tau_passID") != 0) {
		tau_passID_branch = tree->GetBranch("tau_passID");
		if (tau_passID_branch) {tau_passID_branch->SetAddress(&tau_passID_);}
	}
	tau_charge_branch = 0;
	if (tree->GetBranch("tau_charge") != 0) {
		tau_charge_branch = tree->GetBranch("tau_charge");
		if (tau_charge_branch) {tau_charge_branch->SetAddress(&tau_charge_);}
	}
	ngoodtaus_branch = 0;
	if (tree->GetBranch("ngoodtaus") != 0) {
		ngoodtaus_branch = tree->GetBranch("ngoodtaus");
		if (ngoodtaus_branch) {ngoodtaus_branch->SetAddress(&ngoodtaus_);}
	}
	tau_againstMuonTight_branch = 0;
	if (tree->GetBranch("tau_againstMuonTight") != 0) {
		tau_againstMuonTight_branch = tree->GetBranch("tau_againstMuonTight");
		if (tau_againstMuonTight_branch) {tau_againstMuonTight_branch->SetAddress(&tau_againstMuonTight_);}
	}
	tau_againstElectronLoose_branch = 0;
	if (tree->GetBranch("tau_againstElectronLoose") != 0) {
		tau_againstElectronLoose_branch = tree->GetBranch("tau_againstElectronLoose");
		if (tau_againstElectronLoose_branch) {tau_againstElectronLoose_branch->SetAddress(&tau_againstElectronLoose_);}
	}
	tau_isVetoTau_branch = 0;
	if (tree->GetBranch("tau_isVetoTau") != 0) {
		tau_isVetoTau_branch = tree->GetBranch("tau_isVetoTau");
		if (tau_isVetoTau_branch) {tau_isVetoTau_branch->SetAddress(&tau_isVetoTau_);}
	}
	isoTracks_charge_branch = 0;
	if (tree->GetBranch("isoTracks_charge") != 0) {
		isoTracks_charge_branch = tree->GetBranch("isoTracks_charge");
		if (isoTracks_charge_branch) {isoTracks_charge_branch->SetAddress(&isoTracks_charge_);}
	}
	isoTracks_absIso_branch = 0;
	if (tree->GetBranch("isoTracks_absIso") != 0) {
		isoTracks_absIso_branch = tree->GetBranch("isoTracks_absIso");
		if (isoTracks_absIso_branch) {isoTracks_absIso_branch->SetAddress(&isoTracks_absIso_);}
	}
	isoTracks_dz_branch = 0;
	if (tree->GetBranch("isoTracks_dz") != 0) {
		isoTracks_dz_branch = tree->GetBranch("isoTracks_dz");
		if (isoTracks_dz_branch) {isoTracks_dz_branch->SetAddress(&isoTracks_dz_);}
	}
	isoTracks_pdgId_branch = 0;
	if (tree->GetBranch("isoTracks_pdgId") != 0) {
		isoTracks_pdgId_branch = tree->GetBranch("isoTracks_pdgId");
		if (isoTracks_pdgId_branch) {isoTracks_pdgId_branch->SetAddress(&isoTracks_pdgId_);}
	}
	isoTracks_selectedidx_branch = 0;
	if (tree->GetBranch("isoTracks_selectedidx") != 0) {
		isoTracks_selectedidx_branch = tree->GetBranch("isoTracks_selectedidx");
		if (isoTracks_selectedidx_branch) {isoTracks_selectedidx_branch->SetAddress(&isoTracks_selectedidx_);}
	}
	isoTracks_nselected_branch = 0;
	if (tree->GetBranch("isoTracks_nselected") != 0) {
		isoTracks_nselected_branch = tree->GetBranch("isoTracks_nselected");
		if (isoTracks_nselected_branch) {isoTracks_nselected_branch->SetAddress(&isoTracks_nselected_);}
	}
	isoTracks_isVetoTrack_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack") != 0) {
		isoTracks_isVetoTrack_branch = tree->GetBranch("isoTracks_isVetoTrack");
		if (isoTracks_isVetoTrack_branch) {isoTracks_isVetoTrack_branch->SetAddress(&isoTracks_isVetoTrack_);}
	}
	isoTracks_isVetoTrack_v2_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack_v2") != 0) {
		isoTracks_isVetoTrack_v2_branch = tree->GetBranch("isoTracks_isVetoTrack_v2");
		if (isoTracks_isVetoTrack_v2_branch) {isoTracks_isVetoTrack_v2_branch->SetAddress(&isoTracks_isVetoTrack_v2_);}
	}
	isoTracks_isVetoTrack_v3_branch = 0;
	if (tree->GetBranch("isoTracks_isVetoTrack_v3") != 0) {
		isoTracks_isVetoTrack_v3_branch = tree->GetBranch("isoTracks_isVetoTrack_v3");
		if (isoTracks_isVetoTrack_v3_branch) {isoTracks_isVetoTrack_v3_branch->SetAddress(&isoTracks_isVetoTrack_v3_);}
	}
  tree->SetMakeClass(0);
}
void V00_00_02::GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		run_isLoaded = false;
		ls_isLoaded = false;
		evt_isLoaded = false;
		nvtxs_isLoaded = false;
		firstGoodVtxIdx_isLoaded = false;
		firstVtx_isfake_isLoaded = false;
		firstVtx_ndof_isLoaded = false;
		firstVtx_posRho_isLoaded = false;
		firstVtx_posZ_isLoaded = false;
		firstVtx_posp4_isLoaded = false;
		pu_nvtxs_isLoaded = false;
		pfmet_isLoaded = false;
		pfmet_phi_isLoaded = false;
		calomet_isLoaded = false;
		calomet_phi_isLoaded = false;
		filt_cscbeamhalo_isLoaded = false;
		filt_ecallaser_isLoaded = false;
		filt_ecaltp_isLoaded = false;
		filt_eebadsc_isLoaded = false;
		filt_goodvtx_isLoaded = false;
		filt_badevents_isLoaded = false;
		filt_hbhenoise_isLoaded = false;
		filt_hcallaser_isLoaded = false;
		filt_met_isLoaded = false;
		filt_trkfail_isLoaded = false;
		filt_trkPOG_isLoaded = false;
		filt_trkPOG_tmc_isLoaded = false;
		filt_trkPOG_tms_isLoaded = false;
		filt_eff_isLoaded = false;
		scale1fb_isLoaded = false;
		xsec_isLoaded = false;
		kfactor_isLoaded = false;
		pu_ntrue_isLoaded = false;
		ngoodleps_isLoaded = false;
		nlooseleps_isLoaded = false;
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
		genlepsfromtop_isLoaded = false;
		MT2W_isLoaded = false;
		MT2W_lep2_isLoaded = false;
		mindphi_met_j1_j2_isLoaded = false;
		mt_met_lep_isLoaded = false;
		mt_met_lep2_isLoaded = false;
		dR_lep_leadb_isLoaded = false;
		dR_lep2_leadb_isLoaded = false;
		hadronic_top_chi2_isLoaded = false;
		dphi_Wlep_isLoaded = false;
		MET_over_sqrtHT_isLoaded = false;
		ak4pfjets_rho_isLoaded = false;
		genweightsID_isLoaded = false;
		genweights_isLoaded = false;
		sparms_names_isLoaded = false;
		sparms_filterEfficiency_isLoaded = false;
		sparms_pdfScale_isLoaded = false;
		sparms_pdfWeight1_isLoaded = false;
		sparms_pdfWeight2_isLoaded = false;
		sparms_weight_isLoaded = false;
		sparms_xsec_isLoaded = false;
		sparms_values_isLoaded = false;
		sparms_subProcessId_isLoaded = false;
		mass_lsp_isLoaded = false;
		mass_chargino_isLoaded = false;
		mass_stop_isLoaded = false;
		genmet_isLoaded = false;
		genmet_phi_isLoaded = false;
		PassTrackVeto_isLoaded = false;
		PassTrackVeto_v2_isLoaded = false;
		PassTrackVeto_v3_isLoaded = false;
		PassTauVeto_isLoaded = false;
		EA_all_rho_isLoaded = false;
		EA_allcalo_rho_isLoaded = false;
		EA_centralcalo_rho_isLoaded = false;
		EA_centralchargedpileup_rho_isLoaded = false;
		EA_centralneutral_rho_isLoaded = false;
		topness_isLoaded = false;
		topness_lep2_isLoaded = false;
		topnessMod_isLoaded = false;
		topnessMod_lep2_isLoaded = false;
		MT2_lb_b_isLoaded = false;
		MT2_lb_b_lep2_isLoaded = false;
		MT2_lb_b_mass_isLoaded = false;
		MT2_lb_b_mass_lep2_isLoaded = false;
		MT2_lb_bqq_isLoaded = false;
		MT2_lb_bqq_lep2_isLoaded = false;
		MT2_lb_bqq_mass_isLoaded = false;
		MT2_lb_bqq_mass_lep2_isLoaded = false;
		Mlb_closestb_isLoaded = false;
		Mlb_lead_bdiscr_isLoaded = false;
		Mlb_closestb_lep2_isLoaded = false;
		Mlb_lead_bdiscr_lep2_isLoaded = false;
		Mjjj_isLoaded = false;
		Mjjj_lep2_isLoaded = false;
		HLT_SingleEl_isLoaded = false;
		HLT_SingleMu_isLoaded = false;
		HLT_MET170_isLoaded = false;
		HLT_MET120Btag_isLoaded = false;
		HLT_MET120Mu5_isLoaded = false;
		HLT_HT350MET120_isLoaded = false;
		HLT_DiEl_isLoaded = false;
		HLT_DiEl_17_12_isLoaded = false;
		HLT_DiMu_isLoaded = false;
		HLT_Mu8El17_isLoaded = false;
		HLT_Mu8El23_isLoaded = false;
		HLT_Mu17El12_isLoaded = false;
		HLT_Mu23El12_isLoaded = false;
		HLT_SingleEl23_isLoaded = false;
		HLT_SingleEl27_isLoaded = false;
		HLT_SingleEl27Tight_isLoaded = false;
		HLT_SingleElTight_isLoaded = false;
		HLT_SingleElHT200_isLoaded = false;
		HLT_SingleMuNoEta_isLoaded = false;
		HLT_SingleMuNoIso_isLoaded = false;
		HLT_SingleMuNoIsoNoEta_isLoaded = false;
		HLT_Mu6HT200MET100_isLoaded = false;
		HLT_HT350MET100_isLoaded = false;
		HLT_SingleMu17_isLoaded = false;
		HLT_SingleMu20_isLoaded = false;
		HLT_SingleMu24_isLoaded = false;
		HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded = false;
		HLT_MET90_MHT90_IDTight_isLoaded = false;
		HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded = false;
		HLT_Photon90_CaloIdL_PFHT500_isLoaded = false;
		HLT_Photon165_R9Id90_HE10_IsoM_isLoaded = false;
		HLT_Photon175_isLoaded = false;
		HLT_Photon165_HE10_isLoaded = false;
		pu_weight_isLoaded = false;
		lep_sf_isLoaded = false;
		btag_sf_isLoaded = false;
		HLT_SingleEl_eff_isLoaded = false;
		HLT_SingleMu_eff_isLoaded = false;
		lep1_is_mu_isLoaded = false;
		lep1_is_el_isLoaded = false;
		lep1_charge_isLoaded = false;
		lep1_pdgid_isLoaded = false;
		lep1_type_isLoaded = false;
		lep1_production_type_isLoaded = false;
		lep1_d0_isLoaded = false;
		lep1_d0err_isLoaded = false;
		lep1_dz_isLoaded = false;
		lep1_dzerr_isLoaded = false;
		lep1_sigmaIEtaEta_fill5x5_isLoaded = false;
		lep1_dEtaIn_isLoaded = false;
		lep1_dPhiIn_isLoaded = false;
		lep1_hOverE_isLoaded = false;
		lep1_ooEmooP_isLoaded = false;
		lep1_expectedMissingInnerHits_isLoaded = false;
		lep1_conversionVeto_isLoaded = false;
		lep1_etaSC_isLoaded = false;
		lep1_ChiSqr_isLoaded = false;
		lep1_chiso_isLoaded = false;
		lep1_nhiso_isLoaded = false;
		lep1_emiso_isLoaded = false;
		lep1_deltaBeta_isLoaded = false;
		lep1_relIso03DB_isLoaded = false;
		lep1_relIso03EA_isLoaded = false;
		lep1_relIso04DB_isLoaded = false;
		lep1_miniRelIsoDB_isLoaded = false;
		lep1_miniRelIsoEA_isLoaded = false;
		lep1_MiniIso_isLoaded = false;
		lep1_mcid_isLoaded = false;
		lep1_mcstatus_isLoaded = false;
		lep1_mc3dr_isLoaded = false;
		lep1_mc3id_isLoaded = false;
		lep1_mc3idx_isLoaded = false;
		lep1_mc3motherid_isLoaded = false;
		lep1_mc3motheridx_isLoaded = false;
		lep1_is_eleid_loose_isLoaded = false;
		lep1_is_eleid_medium_isLoaded = false;
		lep1_is_eleid_tight_isLoaded = false;
		lep1_is_phys14_loose_noIso_isLoaded = false;
		lep1_is_phys14_medium_noIso_isLoaded = false;
		lep1_is_phys14_tight_noIso_isLoaded = false;
		lep1_eoverpin_isLoaded = false;
		lep1_is_muoid_loose_isLoaded = false;
		lep1_is_muoid_medium_isLoaded = false;
		lep1_is_muoid_tight_isLoaded = false;
		lep1_ip3d_isLoaded = false;
		lep1_ip3derr_isLoaded = false;
		lep1_is_pfmu_isLoaded = false;
		lep1_passMediumID_isLoaded = false;
		lep1_passVeto_isLoaded = false;
		lep1_p4_isLoaded = false;
		lep1_mcp4_isLoaded = false;
		lep1_pt_isLoaded = false;
		lep1_eta_isLoaded = false;
		lep1_phi_isLoaded = false;
		lep1_mass_isLoaded = false;
		lep2_is_mu_isLoaded = false;
		lep2_is_el_isLoaded = false;
		lep2_charge_isLoaded = false;
		lep2_pdgid_isLoaded = false;
		lep2_type_isLoaded = false;
		lep2_production_type_isLoaded = false;
		lep2_d0_isLoaded = false;
		lep2_d0err_isLoaded = false;
		lep2_dz_isLoaded = false;
		lep2_dzerr_isLoaded = false;
		lep2_sigmaIEtaEta_fill5x5_isLoaded = false;
		lep2_dEtaIn_isLoaded = false;
		lep2_dPhiIn_isLoaded = false;
		lep2_hOverE_isLoaded = false;
		lep2_ooEmooP_isLoaded = false;
		lep2_expectedMissingInnerHits_isLoaded = false;
		lep2_conversionVeto_isLoaded = false;
		lep2_etaSC_isLoaded = false;
		lep2_ChiSqr_isLoaded = false;
		lep2_chiso_isLoaded = false;
		lep2_nhiso_isLoaded = false;
		lep2_emiso_isLoaded = false;
		lep2_deltaBeta_isLoaded = false;
		lep2_relIso03DB_isLoaded = false;
		lep2_relIso03EA_isLoaded = false;
		lep2_relIso04DB_isLoaded = false;
		lep2_miniRelIsoDB_isLoaded = false;
		lep2_miniRelIsoEA_isLoaded = false;
		lep2_MiniIso_isLoaded = false;
		lep2_mcid_isLoaded = false;
		lep2_mcstatus_isLoaded = false;
		lep2_mc3dr_isLoaded = false;
		lep2_mc3id_isLoaded = false;
		lep2_mc3idx_isLoaded = false;
		lep2_mc3motherid_isLoaded = false;
		lep2_mc3motheridx_isLoaded = false;
		lep2_is_eleid_loose_isLoaded = false;
		lep2_is_eleid_medium_isLoaded = false;
		lep2_is_eleid_tight_isLoaded = false;
		lep2_is_phys14_loose_noIso_isLoaded = false;
		lep2_is_phys14_medium_noIso_isLoaded = false;
		lep2_is_phys14_tight_noIso_isLoaded = false;
		lep2_eoverpin_isLoaded = false;
		lep2_is_muoid_loose_isLoaded = false;
		lep2_is_muoid_medium_isLoaded = false;
		lep2_is_muoid_tight_isLoaded = false;
		lep2_ip3d_isLoaded = false;
		lep2_ip3derr_isLoaded = false;
		lep2_is_pfmu_isLoaded = false;
		lep2_passMediumID_isLoaded = false;
		lep2_passVeto_isLoaded = false;
		lep2_p4_isLoaded = false;
		lep2_mcp4_isLoaded = false;
		lep2_pt_isLoaded = false;
		lep2_eta_isLoaded = false;
		lep2_phi_isLoaded = false;
		lep2_mass_isLoaded = false;
		nGoodGenJets_isLoaded = false;
		ngoodjets_isLoaded = false;
		nfailjets_isLoaded = false;
		ak8GoodPFJets_isLoaded = false;
		ngoodbtags_isLoaded = false;
		ak4_HT_isLoaded = false;
		ak4_htssm_isLoaded = false;
		ak4_htosm_isLoaded = false;
		ak4_htratiom_isLoaded = false;
		dphi_ak4pfjet_met_isLoaded = false;
		ak4pfjets_p4_isLoaded = false;
		ak4pfjets_pt_isLoaded = false;
		ak4pfjets_eta_isLoaded = false;
		ak4pfjets_phi_isLoaded = false;
		ak4pfjets_mass_isLoaded = false;
		ak4pfjets_passMEDbtag_isLoaded = false;
		ak4pfjets_qg_disc_isLoaded = false;
		ak4pfjets_CSV_isLoaded = false;
		ak4pfjets_puid_isLoaded = false;
		ak4pfjets_parton_flavor_isLoaded = false;
		ak4pfjets_loose_puid_isLoaded = false;
		ak4pfjets_loose_pfid_isLoaded = false;
		ak4pfjets_medium_pfid_isLoaded = false;
		ak4pfjets_tight_pfid_isLoaded = false;
		ak4pfjets_MEDbjet_pt_isLoaded = false;
		ak4pfjets_leadMEDbjet_pt_isLoaded = false;
		ak4pfjets_leadMEDbjet_p4_isLoaded = false;
		ak4pfjets_leadbtag_p4_isLoaded = false;
		ak4pfjets_chf_isLoaded = false;
		ak4pfjets_nhf_isLoaded = false;
		ak4pfjets_cef_isLoaded = false;
		ak4pfjets_nef_isLoaded = false;
		ak4pfjets_muf_isLoaded = false;
		ak4pfjets_cm_isLoaded = false;
		ak4pfjets_nm_isLoaded = false;
		ak4pfjets_mc3dr_isLoaded = false;
		ak4pfjets_mc3id_isLoaded = false;
		ak4pfjets_mc3idx_isLoaded = false;
		ak4pfjets_mcmotherid_isLoaded = false;
		ak4pfjet_overlep1_p4_isLoaded = false;
		ak4pfjet_overlep1_CSV_isLoaded = false;
		ak4pfjet_overlep1_pu_id_isLoaded = false;
		ak4pfjet_overlep1_chf_isLoaded = false;
		ak4pfjet_overlep1_nhf_isLoaded = false;
		ak4pfjet_overlep1_cef_isLoaded = false;
		ak4pfjet_overlep1_nef_isLoaded = false;
		ak4pfjet_overlep1_muf_isLoaded = false;
		ak4pfjet_overlep1_cm_isLoaded = false;
		ak4pfjet_overlep1_nm_isLoaded = false;
		ak4pfjet_overlep2_p4_isLoaded = false;
		ak4pfjet_overlep2_CSV_isLoaded = false;
		ak4pfjet_overlep2_pu_id_isLoaded = false;
		ak4pfjet_overlep2_chf_isLoaded = false;
		ak4pfjet_overlep2_nhf_isLoaded = false;
		ak4pfjet_overlep2_cef_isLoaded = false;
		ak4pfjet_overlep2_nef_isLoaded = false;
		ak4pfjet_overlep2_muf_isLoaded = false;
		ak4pfjet_overlep2_cm_isLoaded = false;
		ak4pfjet_overlep2_nm_isLoaded = false;
		ak8pfjets_p4_isLoaded = false;
		ak8pfjets_tau1_isLoaded = false;
		ak8pfjets_tau2_isLoaded = false;
		ak8pfjets_tau3_isLoaded = false;
		ak8pfjets_top_mass_isLoaded = false;
		ak8pfjets_pruned_mass_isLoaded = false;
		ak8pfjets_trimmed_mass_isLoaded = false;
		ak8pfjets_filtered_mass_isLoaded = false;
		ak8pfjets_pu_id_isLoaded = false;
		ak8pfjets_parton_flavor_isLoaded = false;
		ak4genjets_p4_isLoaded = false;
		tau_IDnames_isLoaded = false;
		tau_leadtrack_p4_isLoaded = false;
		tau_leadneutral_p4_isLoaded = false;
		tau_p4_isLoaded = false;
		tau_isocand_p4_isLoaded = false;
		tau_sigcand_p4_isLoaded = false;
		tau_mass_isLoaded = false;
		tau_ID_isLoaded = false;
		tau_passID_isLoaded = false;
		tau_charge_isLoaded = false;
		ngoodtaus_isLoaded = false;
		tau_againstMuonTight_isLoaded = false;
		tau_againstElectronLoose_isLoaded = false;
		tau_isVetoTau_isLoaded = false;
		isoTracks_p4_isLoaded = false;
		isoTracks_charge_isLoaded = false;
		isoTracks_absIso_isLoaded = false;
		isoTracks_dz_isLoaded = false;
		isoTracks_pdgId_isLoaded = false;
		isoTracks_selectedidx_isLoaded = false;
		isoTracks_nselected_isLoaded = false;
		isoTracks_isVetoTrack_isLoaded = false;
		isoTracks_isVetoTrack_v2_isLoaded = false;
		isoTracks_isVetoTrack_v3_isLoaded = false;
	}

void V00_00_02::LoadAllBranches() 
	// load all branches
{
	if (run_branch != 0) run();
	if (ls_branch != 0) ls();
	if (evt_branch != 0) evt();
	if (nvtxs_branch != 0) nvtxs();
	if (firstGoodVtxIdx_branch != 0) firstGoodVtxIdx();
	if (firstVtx_isfake_branch != 0) firstVtx_isfake();
	if (firstVtx_ndof_branch != 0) firstVtx_ndof();
	if (firstVtx_posRho_branch != 0) firstVtx_posRho();
	if (firstVtx_posZ_branch != 0) firstVtx_posZ();
	if (firstVtx_posp4_branch != 0) firstVtx_posp4();
	if (pu_nvtxs_branch != 0) pu_nvtxs();
	if (pfmet_branch != 0) pfmet();
	if (pfmet_phi_branch != 0) pfmet_phi();
	if (calomet_branch != 0) calomet();
	if (calomet_phi_branch != 0) calomet_phi();
	if (filt_cscbeamhalo_branch != 0) filt_cscbeamhalo();
	if (filt_ecallaser_branch != 0) filt_ecallaser();
	if (filt_ecaltp_branch != 0) filt_ecaltp();
	if (filt_eebadsc_branch != 0) filt_eebadsc();
	if (filt_goodvtx_branch != 0) filt_goodvtx();
	if (filt_badevents_branch != 0) filt_badevents();
	if (filt_hbhenoise_branch != 0) filt_hbhenoise();
	if (filt_hcallaser_branch != 0) filt_hcallaser();
	if (filt_met_branch != 0) filt_met();
	if (filt_trkfail_branch != 0) filt_trkfail();
	if (filt_trkPOG_branch != 0) filt_trkPOG();
	if (filt_trkPOG_tmc_branch != 0) filt_trkPOG_tmc();
	if (filt_trkPOG_tms_branch != 0) filt_trkPOG_tms();
	if (filt_eff_branch != 0) filt_eff();
	if (scale1fb_branch != 0) scale1fb();
	if (xsec_branch != 0) xsec();
	if (kfactor_branch != 0) kfactor();
	if (pu_ntrue_branch != 0) pu_ntrue();
	if (ngoodleps_branch != 0) ngoodleps();
	if (nlooseleps_branch != 0) nlooseleps();
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
	if (genlepsfromtop_branch != 0) genlepsfromtop();
	if (MT2W_branch != 0) MT2W();
	if (MT2W_lep2_branch != 0) MT2W_lep2();
	if (mindphi_met_j1_j2_branch != 0) mindphi_met_j1_j2();
	if (mt_met_lep_branch != 0) mt_met_lep();
	if (mt_met_lep2_branch != 0) mt_met_lep2();
	if (dR_lep_leadb_branch != 0) dR_lep_leadb();
	if (dR_lep2_leadb_branch != 0) dR_lep2_leadb();
	if (hadronic_top_chi2_branch != 0) hadronic_top_chi2();
	if (dphi_Wlep_branch != 0) dphi_Wlep();
	if (MET_over_sqrtHT_branch != 0) MET_over_sqrtHT();
	if (ak4pfjets_rho_branch != 0) ak4pfjets_rho();
	if (genweightsID_branch != 0) genweightsID();
	if (genweights_branch != 0) genweights();
	if (sparms_names_branch != 0) sparms_names();
	if (sparms_filterEfficiency_branch != 0) sparms_filterEfficiency();
	if (sparms_pdfScale_branch != 0) sparms_pdfScale();
	if (sparms_pdfWeight1_branch != 0) sparms_pdfWeight1();
	if (sparms_pdfWeight2_branch != 0) sparms_pdfWeight2();
	if (sparms_weight_branch != 0) sparms_weight();
	if (sparms_xsec_branch != 0) sparms_xsec();
	if (sparms_values_branch != 0) sparms_values();
	if (sparms_subProcessId_branch != 0) sparms_subProcessId();
	if (mass_lsp_branch != 0) mass_lsp();
	if (mass_chargino_branch != 0) mass_chargino();
	if (mass_stop_branch != 0) mass_stop();
	if (genmet_branch != 0) genmet();
	if (genmet_phi_branch != 0) genmet_phi();
	if (PassTrackVeto_branch != 0) PassTrackVeto();
	if (PassTrackVeto_v2_branch != 0) PassTrackVeto_v2();
	if (PassTrackVeto_v3_branch != 0) PassTrackVeto_v3();
	if (PassTauVeto_branch != 0) PassTauVeto();
	if (EA_all_rho_branch != 0) EA_all_rho();
	if (EA_allcalo_rho_branch != 0) EA_allcalo_rho();
	if (EA_centralcalo_rho_branch != 0) EA_centralcalo_rho();
	if (EA_centralchargedpileup_rho_branch != 0) EA_centralchargedpileup_rho();
	if (EA_centralneutral_rho_branch != 0) EA_centralneutral_rho();
	if (topness_branch != 0) topness();
	if (topness_lep2_branch != 0) topness_lep2();
	if (topnessMod_branch != 0) topnessMod();
	if (topnessMod_lep2_branch != 0) topnessMod_lep2();
	if (MT2_lb_b_branch != 0) MT2_lb_b();
	if (MT2_lb_b_lep2_branch != 0) MT2_lb_b_lep2();
	if (MT2_lb_b_mass_branch != 0) MT2_lb_b_mass();
	if (MT2_lb_b_mass_lep2_branch != 0) MT2_lb_b_mass_lep2();
	if (MT2_lb_bqq_branch != 0) MT2_lb_bqq();
	if (MT2_lb_bqq_lep2_branch != 0) MT2_lb_bqq_lep2();
	if (MT2_lb_bqq_mass_branch != 0) MT2_lb_bqq_mass();
	if (MT2_lb_bqq_mass_lep2_branch != 0) MT2_lb_bqq_mass_lep2();
	if (Mlb_closestb_branch != 0) Mlb_closestb();
	if (Mlb_lead_bdiscr_branch != 0) Mlb_lead_bdiscr();
	if (Mlb_closestb_lep2_branch != 0) Mlb_closestb_lep2();
	if (Mlb_lead_bdiscr_lep2_branch != 0) Mlb_lead_bdiscr_lep2();
	if (Mjjj_branch != 0) Mjjj();
	if (Mjjj_lep2_branch != 0) Mjjj_lep2();
	if (HLT_SingleEl_branch != 0) HLT_SingleEl();
	if (HLT_SingleMu_branch != 0) HLT_SingleMu();
	if (HLT_MET170_branch != 0) HLT_MET170();
	if (HLT_MET120Btag_branch != 0) HLT_MET120Btag();
	if (HLT_MET120Mu5_branch != 0) HLT_MET120Mu5();
	if (HLT_HT350MET120_branch != 0) HLT_HT350MET120();
	if (HLT_DiEl_branch != 0) HLT_DiEl();
	if (HLT_DiEl_17_12_branch != 0) HLT_DiEl_17_12();
	if (HLT_DiMu_branch != 0) HLT_DiMu();
	if (HLT_Mu8El17_branch != 0) HLT_Mu8El17();
	if (HLT_Mu8El23_branch != 0) HLT_Mu8El23();
	if (HLT_Mu17El12_branch != 0) HLT_Mu17El12();
	if (HLT_Mu23El12_branch != 0) HLT_Mu23El12();
	if (HLT_SingleEl23_branch != 0) HLT_SingleEl23();
	if (HLT_SingleEl27_branch != 0) HLT_SingleEl27();
	if (HLT_SingleEl27Tight_branch != 0) HLT_SingleEl27Tight();
	if (HLT_SingleElTight_branch != 0) HLT_SingleElTight();
	if (HLT_SingleElHT200_branch != 0) HLT_SingleElHT200();
	if (HLT_SingleMuNoEta_branch != 0) HLT_SingleMuNoEta();
	if (HLT_SingleMuNoIso_branch != 0) HLT_SingleMuNoIso();
	if (HLT_SingleMuNoIsoNoEta_branch != 0) HLT_SingleMuNoIsoNoEta();
	if (HLT_Mu6HT200MET100_branch != 0) HLT_Mu6HT200MET100();
	if (HLT_HT350MET100_branch != 0) HLT_HT350MET100();
	if (HLT_SingleMu17_branch != 0) HLT_SingleMu17();
	if (HLT_SingleMu20_branch != 0) HLT_SingleMu20();
	if (HLT_SingleMu24_branch != 0) HLT_SingleMu24();
	if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch != 0) HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight();
	if (HLT_MET90_MHT90_IDTight_branch != 0) HLT_MET90_MHT90_IDTight();
	if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch != 0) HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight();
	if (HLT_Photon90_CaloIdL_PFHT500_branch != 0) HLT_Photon90_CaloIdL_PFHT500();
	if (HLT_Photon165_R9Id90_HE10_IsoM_branch != 0) HLT_Photon165_R9Id90_HE10_IsoM();
	if (HLT_Photon175_branch != 0) HLT_Photon175();
	if (HLT_Photon165_HE10_branch != 0) HLT_Photon165_HE10();
	if (pu_weight_branch != 0) pu_weight();
	if (lep_sf_branch != 0) lep_sf();
	if (btag_sf_branch != 0) btag_sf();
	if (HLT_SingleEl_eff_branch != 0) HLT_SingleEl_eff();
	if (HLT_SingleMu_eff_branch != 0) HLT_SingleMu_eff();
	if (lep1_is_mu_branch != 0) lep1_is_mu();
	if (lep1_is_el_branch != 0) lep1_is_el();
	if (lep1_charge_branch != 0) lep1_charge();
	if (lep1_pdgid_branch != 0) lep1_pdgid();
	if (lep1_type_branch != 0) lep1_type();
	if (lep1_production_type_branch != 0) lep1_production_type();
	if (lep1_d0_branch != 0) lep1_d0();
	if (lep1_d0err_branch != 0) lep1_d0err();
	if (lep1_dz_branch != 0) lep1_dz();
	if (lep1_dzerr_branch != 0) lep1_dzerr();
	if (lep1_sigmaIEtaEta_fill5x5_branch != 0) lep1_sigmaIEtaEta_fill5x5();
	if (lep1_dEtaIn_branch != 0) lep1_dEtaIn();
	if (lep1_dPhiIn_branch != 0) lep1_dPhiIn();
	if (lep1_hOverE_branch != 0) lep1_hOverE();
	if (lep1_ooEmooP_branch != 0) lep1_ooEmooP();
	if (lep1_expectedMissingInnerHits_branch != 0) lep1_expectedMissingInnerHits();
	if (lep1_conversionVeto_branch != 0) lep1_conversionVeto();
	if (lep1_etaSC_branch != 0) lep1_etaSC();
	if (lep1_ChiSqr_branch != 0) lep1_ChiSqr();
	if (lep1_chiso_branch != 0) lep1_chiso();
	if (lep1_nhiso_branch != 0) lep1_nhiso();
	if (lep1_emiso_branch != 0) lep1_emiso();
	if (lep1_deltaBeta_branch != 0) lep1_deltaBeta();
	if (lep1_relIso03DB_branch != 0) lep1_relIso03DB();
	if (lep1_relIso03EA_branch != 0) lep1_relIso03EA();
	if (lep1_relIso04DB_branch != 0) lep1_relIso04DB();
	if (lep1_miniRelIsoDB_branch != 0) lep1_miniRelIsoDB();
	if (lep1_miniRelIsoEA_branch != 0) lep1_miniRelIsoEA();
	if (lep1_MiniIso_branch != 0) lep1_MiniIso();
	if (lep1_mcid_branch != 0) lep1_mcid();
	if (lep1_mcstatus_branch != 0) lep1_mcstatus();
	if (lep1_mc3dr_branch != 0) lep1_mc3dr();
	if (lep1_mc3id_branch != 0) lep1_mc3id();
	if (lep1_mc3idx_branch != 0) lep1_mc3idx();
	if (lep1_mc3motherid_branch != 0) lep1_mc3motherid();
	if (lep1_mc3motheridx_branch != 0) lep1_mc3motheridx();
	if (lep1_is_eleid_loose_branch != 0) lep1_is_eleid_loose();
	if (lep1_is_eleid_medium_branch != 0) lep1_is_eleid_medium();
	if (lep1_is_eleid_tight_branch != 0) lep1_is_eleid_tight();
	if (lep1_is_phys14_loose_noIso_branch != 0) lep1_is_phys14_loose_noIso();
	if (lep1_is_phys14_medium_noIso_branch != 0) lep1_is_phys14_medium_noIso();
	if (lep1_is_phys14_tight_noIso_branch != 0) lep1_is_phys14_tight_noIso();
	if (lep1_eoverpin_branch != 0) lep1_eoverpin();
	if (lep1_is_muoid_loose_branch != 0) lep1_is_muoid_loose();
	if (lep1_is_muoid_medium_branch != 0) lep1_is_muoid_medium();
	if (lep1_is_muoid_tight_branch != 0) lep1_is_muoid_tight();
	if (lep1_ip3d_branch != 0) lep1_ip3d();
	if (lep1_ip3derr_branch != 0) lep1_ip3derr();
	if (lep1_is_pfmu_branch != 0) lep1_is_pfmu();
	if (lep1_passMediumID_branch != 0) lep1_passMediumID();
	if (lep1_passVeto_branch != 0) lep1_passVeto();
	if (lep1_p4_branch != 0) lep1_p4();
	if (lep1_mcp4_branch != 0) lep1_mcp4();
	if (lep1_pt_branch != 0) lep1_pt();
	if (lep1_eta_branch != 0) lep1_eta();
	if (lep1_phi_branch != 0) lep1_phi();
	if (lep1_mass_branch != 0) lep1_mass();
	if (lep2_is_mu_branch != 0) lep2_is_mu();
	if (lep2_is_el_branch != 0) lep2_is_el();
	if (lep2_charge_branch != 0) lep2_charge();
	if (lep2_pdgid_branch != 0) lep2_pdgid();
	if (lep2_type_branch != 0) lep2_type();
	if (lep2_production_type_branch != 0) lep2_production_type();
	if (lep2_d0_branch != 0) lep2_d0();
	if (lep2_d0err_branch != 0) lep2_d0err();
	if (lep2_dz_branch != 0) lep2_dz();
	if (lep2_dzerr_branch != 0) lep2_dzerr();
	if (lep2_sigmaIEtaEta_fill5x5_branch != 0) lep2_sigmaIEtaEta_fill5x5();
	if (lep2_dEtaIn_branch != 0) lep2_dEtaIn();
	if (lep2_dPhiIn_branch != 0) lep2_dPhiIn();
	if (lep2_hOverE_branch != 0) lep2_hOverE();
	if (lep2_ooEmooP_branch != 0) lep2_ooEmooP();
	if (lep2_expectedMissingInnerHits_branch != 0) lep2_expectedMissingInnerHits();
	if (lep2_conversionVeto_branch != 0) lep2_conversionVeto();
	if (lep2_etaSC_branch != 0) lep2_etaSC();
	if (lep2_ChiSqr_branch != 0) lep2_ChiSqr();
	if (lep2_chiso_branch != 0) lep2_chiso();
	if (lep2_nhiso_branch != 0) lep2_nhiso();
	if (lep2_emiso_branch != 0) lep2_emiso();
	if (lep2_deltaBeta_branch != 0) lep2_deltaBeta();
	if (lep2_relIso03DB_branch != 0) lep2_relIso03DB();
	if (lep2_relIso03EA_branch != 0) lep2_relIso03EA();
	if (lep2_relIso04DB_branch != 0) lep2_relIso04DB();
	if (lep2_miniRelIsoDB_branch != 0) lep2_miniRelIsoDB();
	if (lep2_miniRelIsoEA_branch != 0) lep2_miniRelIsoEA();
	if (lep2_MiniIso_branch != 0) lep2_MiniIso();
	if (lep2_mcid_branch != 0) lep2_mcid();
	if (lep2_mcstatus_branch != 0) lep2_mcstatus();
	if (lep2_mc3dr_branch != 0) lep2_mc3dr();
	if (lep2_mc3id_branch != 0) lep2_mc3id();
	if (lep2_mc3idx_branch != 0) lep2_mc3idx();
	if (lep2_mc3motherid_branch != 0) lep2_mc3motherid();
	if (lep2_mc3motheridx_branch != 0) lep2_mc3motheridx();
	if (lep2_is_eleid_loose_branch != 0) lep2_is_eleid_loose();
	if (lep2_is_eleid_medium_branch != 0) lep2_is_eleid_medium();
	if (lep2_is_eleid_tight_branch != 0) lep2_is_eleid_tight();
	if (lep2_is_phys14_loose_noIso_branch != 0) lep2_is_phys14_loose_noIso();
	if (lep2_is_phys14_medium_noIso_branch != 0) lep2_is_phys14_medium_noIso();
	if (lep2_is_phys14_tight_noIso_branch != 0) lep2_is_phys14_tight_noIso();
	if (lep2_eoverpin_branch != 0) lep2_eoverpin();
	if (lep2_is_muoid_loose_branch != 0) lep2_is_muoid_loose();
	if (lep2_is_muoid_medium_branch != 0) lep2_is_muoid_medium();
	if (lep2_is_muoid_tight_branch != 0) lep2_is_muoid_tight();
	if (lep2_ip3d_branch != 0) lep2_ip3d();
	if (lep2_ip3derr_branch != 0) lep2_ip3derr();
	if (lep2_is_pfmu_branch != 0) lep2_is_pfmu();
	if (lep2_passMediumID_branch != 0) lep2_passMediumID();
	if (lep2_passVeto_branch != 0) lep2_passVeto();
	if (lep2_p4_branch != 0) lep2_p4();
	if (lep2_mcp4_branch != 0) lep2_mcp4();
	if (lep2_pt_branch != 0) lep2_pt();
	if (lep2_eta_branch != 0) lep2_eta();
	if (lep2_phi_branch != 0) lep2_phi();
	if (lep2_mass_branch != 0) lep2_mass();
	if (nGoodGenJets_branch != 0) nGoodGenJets();
	if (ngoodjets_branch != 0) ngoodjets();
	if (nfailjets_branch != 0) nfailjets();
	if (ak8GoodPFJets_branch != 0) ak8GoodPFJets();
	if (ngoodbtags_branch != 0) ngoodbtags();
	if (ak4_HT_branch != 0) ak4_HT();
	if (ak4_htssm_branch != 0) ak4_htssm();
	if (ak4_htosm_branch != 0) ak4_htosm();
	if (ak4_htratiom_branch != 0) ak4_htratiom();
	if (dphi_ak4pfjet_met_branch != 0) dphi_ak4pfjet_met();
	if (ak4pfjets_p4_branch != 0) ak4pfjets_p4();
	if (ak4pfjets_pt_branch != 0) ak4pfjets_pt();
	if (ak4pfjets_eta_branch != 0) ak4pfjets_eta();
	if (ak4pfjets_phi_branch != 0) ak4pfjets_phi();
	if (ak4pfjets_mass_branch != 0) ak4pfjets_mass();
	if (ak4pfjets_passMEDbtag_branch != 0) ak4pfjets_passMEDbtag();
	if (ak4pfjets_qg_disc_branch != 0) ak4pfjets_qg_disc();
	if (ak4pfjets_CSV_branch != 0) ak4pfjets_CSV();
	if (ak4pfjets_puid_branch != 0) ak4pfjets_puid();
	if (ak4pfjets_parton_flavor_branch != 0) ak4pfjets_parton_flavor();
	if (ak4pfjets_loose_puid_branch != 0) ak4pfjets_loose_puid();
	if (ak4pfjets_loose_pfid_branch != 0) ak4pfjets_loose_pfid();
	if (ak4pfjets_medium_pfid_branch != 0) ak4pfjets_medium_pfid();
	if (ak4pfjets_tight_pfid_branch != 0) ak4pfjets_tight_pfid();
	if (ak4pfjets_MEDbjet_pt_branch != 0) ak4pfjets_MEDbjet_pt();
	if (ak4pfjets_leadMEDbjet_pt_branch != 0) ak4pfjets_leadMEDbjet_pt();
	if (ak4pfjets_leadMEDbjet_p4_branch != 0) ak4pfjets_leadMEDbjet_p4();
	if (ak4pfjets_leadbtag_p4_branch != 0) ak4pfjets_leadbtag_p4();
	if (ak4pfjets_chf_branch != 0) ak4pfjets_chf();
	if (ak4pfjets_nhf_branch != 0) ak4pfjets_nhf();
	if (ak4pfjets_cef_branch != 0) ak4pfjets_cef();
	if (ak4pfjets_nef_branch != 0) ak4pfjets_nef();
	if (ak4pfjets_muf_branch != 0) ak4pfjets_muf();
	if (ak4pfjets_cm_branch != 0) ak4pfjets_cm();
	if (ak4pfjets_nm_branch != 0) ak4pfjets_nm();
	if (ak4pfjets_mc3dr_branch != 0) ak4pfjets_mc3dr();
	if (ak4pfjets_mc3id_branch != 0) ak4pfjets_mc3id();
	if (ak4pfjets_mc3idx_branch != 0) ak4pfjets_mc3idx();
	if (ak4pfjets_mcmotherid_branch != 0) ak4pfjets_mcmotherid();
	if (ak4pfjet_overlep1_p4_branch != 0) ak4pfjet_overlep1_p4();
	if (ak4pfjet_overlep1_CSV_branch != 0) ak4pfjet_overlep1_CSV();
	if (ak4pfjet_overlep1_pu_id_branch != 0) ak4pfjet_overlep1_pu_id();
	if (ak4pfjet_overlep1_chf_branch != 0) ak4pfjet_overlep1_chf();
	if (ak4pfjet_overlep1_nhf_branch != 0) ak4pfjet_overlep1_nhf();
	if (ak4pfjet_overlep1_cef_branch != 0) ak4pfjet_overlep1_cef();
	if (ak4pfjet_overlep1_nef_branch != 0) ak4pfjet_overlep1_nef();
	if (ak4pfjet_overlep1_muf_branch != 0) ak4pfjet_overlep1_muf();
	if (ak4pfjet_overlep1_cm_branch != 0) ak4pfjet_overlep1_cm();
	if (ak4pfjet_overlep1_nm_branch != 0) ak4pfjet_overlep1_nm();
	if (ak4pfjet_overlep2_p4_branch != 0) ak4pfjet_overlep2_p4();
	if (ak4pfjet_overlep2_CSV_branch != 0) ak4pfjet_overlep2_CSV();
	if (ak4pfjet_overlep2_pu_id_branch != 0) ak4pfjet_overlep2_pu_id();
	if (ak4pfjet_overlep2_chf_branch != 0) ak4pfjet_overlep2_chf();
	if (ak4pfjet_overlep2_nhf_branch != 0) ak4pfjet_overlep2_nhf();
	if (ak4pfjet_overlep2_cef_branch != 0) ak4pfjet_overlep2_cef();
	if (ak4pfjet_overlep2_nef_branch != 0) ak4pfjet_overlep2_nef();
	if (ak4pfjet_overlep2_muf_branch != 0) ak4pfjet_overlep2_muf();
	if (ak4pfjet_overlep2_cm_branch != 0) ak4pfjet_overlep2_cm();
	if (ak4pfjet_overlep2_nm_branch != 0) ak4pfjet_overlep2_nm();
	if (ak8pfjets_p4_branch != 0) ak8pfjets_p4();
	if (ak8pfjets_tau1_branch != 0) ak8pfjets_tau1();
	if (ak8pfjets_tau2_branch != 0) ak8pfjets_tau2();
	if (ak8pfjets_tau3_branch != 0) ak8pfjets_tau3();
	if (ak8pfjets_top_mass_branch != 0) ak8pfjets_top_mass();
	if (ak8pfjets_pruned_mass_branch != 0) ak8pfjets_pruned_mass();
	if (ak8pfjets_trimmed_mass_branch != 0) ak8pfjets_trimmed_mass();
	if (ak8pfjets_filtered_mass_branch != 0) ak8pfjets_filtered_mass();
	if (ak8pfjets_pu_id_branch != 0) ak8pfjets_pu_id();
	if (ak8pfjets_parton_flavor_branch != 0) ak8pfjets_parton_flavor();
	if (ak4genjets_p4_branch != 0) ak4genjets_p4();
	if (tau_IDnames_branch != 0) tau_IDnames();
	if (tau_leadtrack_p4_branch != 0) tau_leadtrack_p4();
	if (tau_leadneutral_p4_branch != 0) tau_leadneutral_p4();
	if (tau_p4_branch != 0) tau_p4();
	if (tau_isocand_p4_branch != 0) tau_isocand_p4();
	if (tau_sigcand_p4_branch != 0) tau_sigcand_p4();
	if (tau_mass_branch != 0) tau_mass();
	if (tau_ID_branch != 0) tau_ID();
	if (tau_passID_branch != 0) tau_passID();
	if (tau_charge_branch != 0) tau_charge();
	if (ngoodtaus_branch != 0) ngoodtaus();
	if (tau_againstMuonTight_branch != 0) tau_againstMuonTight();
	if (tau_againstElectronLoose_branch != 0) tau_againstElectronLoose();
	if (tau_isVetoTau_branch != 0) tau_isVetoTau();
	if (isoTracks_p4_branch != 0) isoTracks_p4();
	if (isoTracks_charge_branch != 0) isoTracks_charge();
	if (isoTracks_absIso_branch != 0) isoTracks_absIso();
	if (isoTracks_dz_branch != 0) isoTracks_dz();
	if (isoTracks_pdgId_branch != 0) isoTracks_pdgId();
	if (isoTracks_selectedidx_branch != 0) isoTracks_selectedidx();
	if (isoTracks_nselected_branch != 0) isoTracks_nselected();
	if (isoTracks_isVetoTrack_branch != 0) isoTracks_isVetoTrack();
	if (isoTracks_isVetoTrack_v2_branch != 0) isoTracks_isVetoTrack_v2();
	if (isoTracks_isVetoTrack_v3_branch != 0) isoTracks_isVetoTrack_v3();
}

	const unsigned int &V00_00_02::run()
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
	const unsigned int &V00_00_02::ls()
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
	const unsigned int &V00_00_02::evt()
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
	const int &V00_00_02::nvtxs()
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
	const int &V00_00_02::firstGoodVtxIdx()
	{
		if (not firstGoodVtxIdx_isLoaded) {
			if (firstGoodVtxIdx_branch != 0) {
				firstGoodVtxIdx_branch->GetEntry(index);
			} else { 
				printf("branch firstGoodVtxIdx_branch does not exist!\n");
				exit(1);
			}
			firstGoodVtxIdx_isLoaded = true;
		}
		return firstGoodVtxIdx_;
	}
	const int &V00_00_02::firstVtx_isfake()
	{
		if (not firstVtx_isfake_isLoaded) {
			if (firstVtx_isfake_branch != 0) {
				firstVtx_isfake_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_isfake_branch does not exist!\n");
				exit(1);
			}
			firstVtx_isfake_isLoaded = true;
		}
		return firstVtx_isfake_;
	}
	const float &V00_00_02::firstVtx_ndof()
	{
		if (not firstVtx_ndof_isLoaded) {
			if (firstVtx_ndof_branch != 0) {
				firstVtx_ndof_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_ndof_branch does not exist!\n");
				exit(1);
			}
			firstVtx_ndof_isLoaded = true;
		}
		return firstVtx_ndof_;
	}
	const float &V00_00_02::firstVtx_posRho()
	{
		if (not firstVtx_posRho_isLoaded) {
			if (firstVtx_posRho_branch != 0) {
				firstVtx_posRho_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posRho_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posRho_isLoaded = true;
		}
		return firstVtx_posRho_;
	}
	const float &V00_00_02::firstVtx_posZ()
	{
		if (not firstVtx_posZ_isLoaded) {
			if (firstVtx_posZ_branch != 0) {
				firstVtx_posZ_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posZ_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posZ_isLoaded = true;
		}
		return firstVtx_posZ_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::firstVtx_posp4()
	{
		if (not firstVtx_posp4_isLoaded) {
			if (firstVtx_posp4_branch != 0) {
				firstVtx_posp4_branch->GetEntry(index);
			} else { 
				printf("branch firstVtx_posp4_branch does not exist!\n");
				exit(1);
			}
			firstVtx_posp4_isLoaded = true;
		}
		return *firstVtx_posp4_;
	}
	const int &V00_00_02::pu_nvtxs()
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
	const float &V00_00_02::pfmet()
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
	const float &V00_00_02::pfmet_phi()
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
	const float &V00_00_02::calomet()
	{
		if (not calomet_isLoaded) {
			if (calomet_branch != 0) {
				calomet_branch->GetEntry(index);
			} else { 
				printf("branch calomet_branch does not exist!\n");
				exit(1);
			}
			calomet_isLoaded = true;
		}
		return calomet_;
	}
	const float &V00_00_02::calomet_phi()
	{
		if (not calomet_phi_isLoaded) {
			if (calomet_phi_branch != 0) {
				calomet_phi_branch->GetEntry(index);
			} else { 
				printf("branch calomet_phi_branch does not exist!\n");
				exit(1);
			}
			calomet_phi_isLoaded = true;
		}
		return calomet_phi_;
	}
	const float &V00_00_02::filt_cscbeamhalo()
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
	const float &V00_00_02::filt_ecallaser()
	{
		if (not filt_ecallaser_isLoaded) {
			if (filt_ecallaser_branch != 0) {
				filt_ecallaser_branch->GetEntry(index);
			} else { 
				printf("branch filt_ecallaser_branch does not exist!\n");
				exit(1);
			}
			filt_ecallaser_isLoaded = true;
		}
		return filt_ecallaser_;
	}
	const float &V00_00_02::filt_ecaltp()
	{
		if (not filt_ecaltp_isLoaded) {
			if (filt_ecaltp_branch != 0) {
				filt_ecaltp_branch->GetEntry(index);
			} else { 
				printf("branch filt_ecaltp_branch does not exist!\n");
				exit(1);
			}
			filt_ecaltp_isLoaded = true;
		}
		return filt_ecaltp_;
	}
	const float &V00_00_02::filt_eebadsc()
	{
		if (not filt_eebadsc_isLoaded) {
			if (filt_eebadsc_branch != 0) {
				filt_eebadsc_branch->GetEntry(index);
			} else { 
				printf("branch filt_eebadsc_branch does not exist!\n");
				exit(1);
			}
			filt_eebadsc_isLoaded = true;
		}
		return filt_eebadsc_;
	}
	const float &V00_00_02::filt_goodvtx()
	{
		if (not filt_goodvtx_isLoaded) {
			if (filt_goodvtx_branch != 0) {
				filt_goodvtx_branch->GetEntry(index);
			} else { 
				printf("branch filt_goodvtx_branch does not exist!\n");
				exit(1);
			}
			filt_goodvtx_isLoaded = true;
		}
		return filt_goodvtx_;
	}
	const float &V00_00_02::filt_badevents()
	{
		if (not filt_badevents_isLoaded) {
			if (filt_badevents_branch != 0) {
				filt_badevents_branch->GetEntry(index);
			} else { 
				printf("branch filt_badevents_branch does not exist!\n");
				exit(1);
			}
			filt_badevents_isLoaded = true;
		}
		return filt_badevents_;
	}
	const float &V00_00_02::filt_hbhenoise()
	{
		if (not filt_hbhenoise_isLoaded) {
			if (filt_hbhenoise_branch != 0) {
				filt_hbhenoise_branch->GetEntry(index);
			} else { 
				printf("branch filt_hbhenoise_branch does not exist!\n");
				exit(1);
			}
			filt_hbhenoise_isLoaded = true;
		}
		return filt_hbhenoise_;
	}
	const float &V00_00_02::filt_hcallaser()
	{
		if (not filt_hcallaser_isLoaded) {
			if (filt_hcallaser_branch != 0) {
				filt_hcallaser_branch->GetEntry(index);
			} else { 
				printf("branch filt_hcallaser_branch does not exist!\n");
				exit(1);
			}
			filt_hcallaser_isLoaded = true;
		}
		return filt_hcallaser_;
	}
	const float &V00_00_02::filt_met()
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
	const float &V00_00_02::filt_trkfail()
	{
		if (not filt_trkfail_isLoaded) {
			if (filt_trkfail_branch != 0) {
				filt_trkfail_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkfail_branch does not exist!\n");
				exit(1);
			}
			filt_trkfail_isLoaded = true;
		}
		return filt_trkfail_;
	}
	const float &V00_00_02::filt_trkPOG()
	{
		if (not filt_trkPOG_isLoaded) {
			if (filt_trkPOG_branch != 0) {
				filt_trkPOG_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_isLoaded = true;
		}
		return filt_trkPOG_;
	}
	const float &V00_00_02::filt_trkPOG_tmc()
	{
		if (not filt_trkPOG_tmc_isLoaded) {
			if (filt_trkPOG_tmc_branch != 0) {
				filt_trkPOG_tmc_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_tmc_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_tmc_isLoaded = true;
		}
		return filt_trkPOG_tmc_;
	}
	const float &V00_00_02::filt_trkPOG_tms()
	{
		if (not filt_trkPOG_tms_isLoaded) {
			if (filt_trkPOG_tms_branch != 0) {
				filt_trkPOG_tms_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkPOG_tms_branch does not exist!\n");
				exit(1);
			}
			filt_trkPOG_tms_isLoaded = true;
		}
		return filt_trkPOG_tms_;
	}
	const float &V00_00_02::filt_eff()
	{
		if (not filt_eff_isLoaded) {
			if (filt_eff_branch != 0) {
				filt_eff_branch->GetEntry(index);
			} else { 
				printf("branch filt_eff_branch does not exist!\n");
				exit(1);
			}
			filt_eff_isLoaded = true;
		}
		return filt_eff_;
	}
	const float &V00_00_02::scale1fb()
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
	const float &V00_00_02::xsec()
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
	const float &V00_00_02::kfactor()
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
	const float &V00_00_02::pu_ntrue()
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
	const int &V00_00_02::ngoodleps()
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
	const int &V00_00_02::nlooseleps()
	{
		if (not nlooseleps_isLoaded) {
			if (nlooseleps_branch != 0) {
				nlooseleps_branch->GetEntry(index);
			} else { 
				printf("branch nlooseleps_branch does not exist!\n");
				exit(1);
			}
			nlooseleps_isLoaded = true;
		}
		return nlooseleps_;
	}
	const int &V00_00_02::nvetoleps()
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
	const bool &	V00_00_02::is_data()
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
	const string &V00_00_02::dataset()
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
	const string &V00_00_02::filename()
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
	const string &V00_00_02::cms3tag()
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
	const unsigned int &V00_00_02::nEvents()
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
	const unsigned int &V00_00_02::nEvents_goodvtx()
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
	const unsigned int &V00_00_02::nEvents_MET30()
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
	const unsigned int &V00_00_02::nEvents_1goodlep()
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
	const unsigned int &V00_00_02::nEvents_2goodjets()
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
	const int &V00_00_02::genlepsfromtop()
	{
		if (not genlepsfromtop_isLoaded) {
			if (genlepsfromtop_branch != 0) {
				genlepsfromtop_branch->GetEntry(index);
			} else { 
				printf("branch genlepsfromtop_branch does not exist!\n");
				exit(1);
			}
			genlepsfromtop_isLoaded = true;
		}
		return genlepsfromtop_;
	}
	const float &V00_00_02::MT2W()
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
	const float &V00_00_02::MT2W_lep2()
	{
		if (not MT2W_lep2_isLoaded) {
			if (MT2W_lep2_branch != 0) {
				MT2W_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2W_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2W_lep2_isLoaded = true;
		}
		return MT2W_lep2_;
	}
	const float &V00_00_02::mindphi_met_j1_j2()
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
	const float &V00_00_02::mt_met_lep()
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
	const float &V00_00_02::mt_met_lep2()
	{
		if (not mt_met_lep2_isLoaded) {
			if (mt_met_lep2_branch != 0) {
				mt_met_lep2_branch->GetEntry(index);
			} else { 
				printf("branch mt_met_lep2_branch does not exist!\n");
				exit(1);
			}
			mt_met_lep2_isLoaded = true;
		}
		return mt_met_lep2_;
	}
	const float &V00_00_02::dR_lep_leadb()
	{
		if (not dR_lep_leadb_isLoaded) {
			if (dR_lep_leadb_branch != 0) {
				dR_lep_leadb_branch->GetEntry(index);
			} else { 
				printf("branch dR_lep_leadb_branch does not exist!\n");
				exit(1);
			}
			dR_lep_leadb_isLoaded = true;
		}
		return dR_lep_leadb_;
	}
	const float &V00_00_02::dR_lep2_leadb()
	{
		if (not dR_lep2_leadb_isLoaded) {
			if (dR_lep2_leadb_branch != 0) {
				dR_lep2_leadb_branch->GetEntry(index);
			} else { 
				printf("branch dR_lep2_leadb_branch does not exist!\n");
				exit(1);
			}
			dR_lep2_leadb_isLoaded = true;
		}
		return dR_lep2_leadb_;
	}
	const float &V00_00_02::hadronic_top_chi2()
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
	const float &V00_00_02::dphi_Wlep()
	{
		if (not dphi_Wlep_isLoaded) {
			if (dphi_Wlep_branch != 0) {
				dphi_Wlep_branch->GetEntry(index);
			} else { 
				printf("branch dphi_Wlep_branch does not exist!\n");
				exit(1);
			}
			dphi_Wlep_isLoaded = true;
		}
		return dphi_Wlep_;
	}
	const float &V00_00_02::MET_over_sqrtHT()
	{
		if (not MET_over_sqrtHT_isLoaded) {
			if (MET_over_sqrtHT_branch != 0) {
				MET_over_sqrtHT_branch->GetEntry(index);
			} else { 
				printf("branch MET_over_sqrtHT_branch does not exist!\n");
				exit(1);
			}
			MET_over_sqrtHT_isLoaded = true;
		}
		return MET_over_sqrtHT_;
	}
	const float &V00_00_02::ak4pfjets_rho()
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
	const vector<string> &V00_00_02::genweightsID()
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
	const vector<float> &V00_00_02::genweights()
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
	const vector<string> &V00_00_02::sparms_names()
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
	const float &V00_00_02::sparms_filterEfficiency()
	{
		if (not sparms_filterEfficiency_isLoaded) {
			if (sparms_filterEfficiency_branch != 0) {
				sparms_filterEfficiency_branch->GetEntry(index);
			} else { 
				printf("branch sparms_filterEfficiency_branch does not exist!\n");
				exit(1);
			}
			sparms_filterEfficiency_isLoaded = true;
		}
		return sparms_filterEfficiency_;
	}
	const float &V00_00_02::sparms_pdfScale()
	{
		if (not sparms_pdfScale_isLoaded) {
			if (sparms_pdfScale_branch != 0) {
				sparms_pdfScale_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfScale_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfScale_isLoaded = true;
		}
		return sparms_pdfScale_;
	}
	const float &V00_00_02::sparms_pdfWeight1()
	{
		if (not sparms_pdfWeight1_isLoaded) {
			if (sparms_pdfWeight1_branch != 0) {
				sparms_pdfWeight1_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfWeight1_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfWeight1_isLoaded = true;
		}
		return sparms_pdfWeight1_;
	}
	const float &V00_00_02::sparms_pdfWeight2()
	{
		if (not sparms_pdfWeight2_isLoaded) {
			if (sparms_pdfWeight2_branch != 0) {
				sparms_pdfWeight2_branch->GetEntry(index);
			} else { 
				printf("branch sparms_pdfWeight2_branch does not exist!\n");
				exit(1);
			}
			sparms_pdfWeight2_isLoaded = true;
		}
		return sparms_pdfWeight2_;
	}
	const float &V00_00_02::sparms_weight()
	{
		if (not sparms_weight_isLoaded) {
			if (sparms_weight_branch != 0) {
				sparms_weight_branch->GetEntry(index);
			} else { 
				printf("branch sparms_weight_branch does not exist!\n");
				exit(1);
			}
			sparms_weight_isLoaded = true;
		}
		return sparms_weight_;
	}
	const float &V00_00_02::sparms_xsec()
	{
		if (not sparms_xsec_isLoaded) {
			if (sparms_xsec_branch != 0) {
				sparms_xsec_branch->GetEntry(index);
			} else { 
				printf("branch sparms_xsec_branch does not exist!\n");
				exit(1);
			}
			sparms_xsec_isLoaded = true;
		}
		return sparms_xsec_;
	}
	const vector<float> &V00_00_02::sparms_values()
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
	const int &V00_00_02::sparms_subProcessId()
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
	const float &V00_00_02::mass_lsp()
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
	const float &V00_00_02::mass_chargino()
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
	const float &V00_00_02::mass_stop()
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
	const float &V00_00_02::genmet()
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
	const float &V00_00_02::genmet_phi()
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
	const bool &	V00_00_02::PassTrackVeto()
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
	const bool &	V00_00_02::PassTrackVeto_v2()
	{
		if (not PassTrackVeto_v2_isLoaded) {
			if (PassTrackVeto_v2_branch != 0) {
				PassTrackVeto_v2_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_v2_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_v2_isLoaded = true;
		}
		return PassTrackVeto_v2_;
	}
	const bool &	V00_00_02::PassTrackVeto_v3()
	{
		if (not PassTrackVeto_v3_isLoaded) {
			if (PassTrackVeto_v3_branch != 0) {
				PassTrackVeto_v3_branch->GetEntry(index);
			} else { 
				printf("branch PassTrackVeto_v3_branch does not exist!\n");
				exit(1);
			}
			PassTrackVeto_v3_isLoaded = true;
		}
		return PassTrackVeto_v3_;
	}
	const bool &	V00_00_02::PassTauVeto()
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
	const float &V00_00_02::EA_all_rho()
	{
		if (not EA_all_rho_isLoaded) {
			if (EA_all_rho_branch != 0) {
				EA_all_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_all_rho_branch does not exist!\n");
				exit(1);
			}
			EA_all_rho_isLoaded = true;
		}
		return EA_all_rho_;
	}
	const float &V00_00_02::EA_allcalo_rho()
	{
		if (not EA_allcalo_rho_isLoaded) {
			if (EA_allcalo_rho_branch != 0) {
				EA_allcalo_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_allcalo_rho_branch does not exist!\n");
				exit(1);
			}
			EA_allcalo_rho_isLoaded = true;
		}
		return EA_allcalo_rho_;
	}
	const float &V00_00_02::EA_centralcalo_rho()
	{
		if (not EA_centralcalo_rho_isLoaded) {
			if (EA_centralcalo_rho_branch != 0) {
				EA_centralcalo_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralcalo_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralcalo_rho_isLoaded = true;
		}
		return EA_centralcalo_rho_;
	}
	const float &V00_00_02::EA_centralchargedpileup_rho()
	{
		if (not EA_centralchargedpileup_rho_isLoaded) {
			if (EA_centralchargedpileup_rho_branch != 0) {
				EA_centralchargedpileup_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralchargedpileup_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralchargedpileup_rho_isLoaded = true;
		}
		return EA_centralchargedpileup_rho_;
	}
	const float &V00_00_02::EA_centralneutral_rho()
	{
		if (not EA_centralneutral_rho_isLoaded) {
			if (EA_centralneutral_rho_branch != 0) {
				EA_centralneutral_rho_branch->GetEntry(index);
			} else { 
				printf("branch EA_centralneutral_rho_branch does not exist!\n");
				exit(1);
			}
			EA_centralneutral_rho_isLoaded = true;
		}
		return EA_centralneutral_rho_;
	}
	const float &V00_00_02::topness()
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
	const float &V00_00_02::topness_lep2()
	{
		if (not topness_lep2_isLoaded) {
			if (topness_lep2_branch != 0) {
				topness_lep2_branch->GetEntry(index);
			} else { 
				printf("branch topness_lep2_branch does not exist!\n");
				exit(1);
			}
			topness_lep2_isLoaded = true;
		}
		return topness_lep2_;
	}
	const float &V00_00_02::topnessMod()
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
	const float &V00_00_02::topnessMod_lep2()
	{
		if (not topnessMod_lep2_isLoaded) {
			if (topnessMod_lep2_branch != 0) {
				topnessMod_lep2_branch->GetEntry(index);
			} else { 
				printf("branch topnessMod_lep2_branch does not exist!\n");
				exit(1);
			}
			topnessMod_lep2_isLoaded = true;
		}
		return topnessMod_lep2_;
	}
	const float &V00_00_02::MT2_lb_b()
	{
		if (not MT2_lb_b_isLoaded) {
			if (MT2_lb_b_branch != 0) {
				MT2_lb_b_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_isLoaded = true;
		}
		return MT2_lb_b_;
	}
	const float &V00_00_02::MT2_lb_b_lep2()
	{
		if (not MT2_lb_b_lep2_isLoaded) {
			if (MT2_lb_b_lep2_branch != 0) {
				MT2_lb_b_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_lep2_isLoaded = true;
		}
		return MT2_lb_b_lep2_;
	}
	const float &V00_00_02::MT2_lb_b_mass()
	{
		if (not MT2_lb_b_mass_isLoaded) {
			if (MT2_lb_b_mass_branch != 0) {
				MT2_lb_b_mass_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_mass_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_mass_isLoaded = true;
		}
		return MT2_lb_b_mass_;
	}
	const float &V00_00_02::MT2_lb_b_mass_lep2()
	{
		if (not MT2_lb_b_mass_lep2_isLoaded) {
			if (MT2_lb_b_mass_lep2_branch != 0) {
				MT2_lb_b_mass_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_b_mass_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_b_mass_lep2_isLoaded = true;
		}
		return MT2_lb_b_mass_lep2_;
	}
	const float &V00_00_02::MT2_lb_bqq()
	{
		if (not MT2_lb_bqq_isLoaded) {
			if (MT2_lb_bqq_branch != 0) {
				MT2_lb_bqq_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_isLoaded = true;
		}
		return MT2_lb_bqq_;
	}
	const float &V00_00_02::MT2_lb_bqq_lep2()
	{
		if (not MT2_lb_bqq_lep2_isLoaded) {
			if (MT2_lb_bqq_lep2_branch != 0) {
				MT2_lb_bqq_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_lep2_isLoaded = true;
		}
		return MT2_lb_bqq_lep2_;
	}
	const float &V00_00_02::MT2_lb_bqq_mass()
	{
		if (not MT2_lb_bqq_mass_isLoaded) {
			if (MT2_lb_bqq_mass_branch != 0) {
				MT2_lb_bqq_mass_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_mass_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_mass_isLoaded = true;
		}
		return MT2_lb_bqq_mass_;
	}
	const float &V00_00_02::MT2_lb_bqq_mass_lep2()
	{
		if (not MT2_lb_bqq_mass_lep2_isLoaded) {
			if (MT2_lb_bqq_mass_lep2_branch != 0) {
				MT2_lb_bqq_mass_lep2_branch->GetEntry(index);
			} else { 
				printf("branch MT2_lb_bqq_mass_lep2_branch does not exist!\n");
				exit(1);
			}
			MT2_lb_bqq_mass_lep2_isLoaded = true;
		}
		return MT2_lb_bqq_mass_lep2_;
	}
	const float &V00_00_02::Mlb_closestb()
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
	const float &V00_00_02::Mlb_lead_bdiscr()
	{
		if (not Mlb_lead_bdiscr_isLoaded) {
			if (Mlb_lead_bdiscr_branch != 0) {
				Mlb_lead_bdiscr_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_lead_bdiscr_branch does not exist!\n");
				exit(1);
			}
			Mlb_lead_bdiscr_isLoaded = true;
		}
		return Mlb_lead_bdiscr_;
	}
	const float &V00_00_02::Mlb_closestb_lep2()
	{
		if (not Mlb_closestb_lep2_isLoaded) {
			if (Mlb_closestb_lep2_branch != 0) {
				Mlb_closestb_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_closestb_lep2_branch does not exist!\n");
				exit(1);
			}
			Mlb_closestb_lep2_isLoaded = true;
		}
		return Mlb_closestb_lep2_;
	}
	const float &V00_00_02::Mlb_lead_bdiscr_lep2()
	{
		if (not Mlb_lead_bdiscr_lep2_isLoaded) {
			if (Mlb_lead_bdiscr_lep2_branch != 0) {
				Mlb_lead_bdiscr_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mlb_lead_bdiscr_lep2_branch does not exist!\n");
				exit(1);
			}
			Mlb_lead_bdiscr_lep2_isLoaded = true;
		}
		return Mlb_lead_bdiscr_lep2_;
	}
	const float &V00_00_02::Mjjj()
	{
		if (not Mjjj_isLoaded) {
			if (Mjjj_branch != 0) {
				Mjjj_branch->GetEntry(index);
			} else { 
				printf("branch Mjjj_branch does not exist!\n");
				exit(1);
			}
			Mjjj_isLoaded = true;
		}
		return Mjjj_;
	}
	const float &V00_00_02::Mjjj_lep2()
	{
		if (not Mjjj_lep2_isLoaded) {
			if (Mjjj_lep2_branch != 0) {
				Mjjj_lep2_branch->GetEntry(index);
			} else { 
				printf("branch Mjjj_lep2_branch does not exist!\n");
				exit(1);
			}
			Mjjj_lep2_isLoaded = true;
		}
		return Mjjj_lep2_;
	}
	const int &V00_00_02::HLT_SingleEl()
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
	const int &V00_00_02::HLT_SingleMu()
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
	const int &V00_00_02::HLT_MET170()
	{
		if (not HLT_MET170_isLoaded) {
			if (HLT_MET170_branch != 0) {
				HLT_MET170_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET170_branch does not exist!\n");
				exit(1);
			}
			HLT_MET170_isLoaded = true;
		}
		return HLT_MET170_;
	}
	const int &V00_00_02::HLT_MET120Btag()
	{
		if (not HLT_MET120Btag_isLoaded) {
			if (HLT_MET120Btag_branch != 0) {
				HLT_MET120Btag_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET120Btag_branch does not exist!\n");
				exit(1);
			}
			HLT_MET120Btag_isLoaded = true;
		}
		return HLT_MET120Btag_;
	}
	const int &V00_00_02::HLT_MET120Mu5()
	{
		if (not HLT_MET120Mu5_isLoaded) {
			if (HLT_MET120Mu5_branch != 0) {
				HLT_MET120Mu5_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET120Mu5_branch does not exist!\n");
				exit(1);
			}
			HLT_MET120Mu5_isLoaded = true;
		}
		return HLT_MET120Mu5_;
	}
	const int &V00_00_02::HLT_HT350MET120()
	{
		if (not HLT_HT350MET120_isLoaded) {
			if (HLT_HT350MET120_branch != 0) {
				HLT_HT350MET120_branch->GetEntry(index);
			} else { 
				printf("branch HLT_HT350MET120_branch does not exist!\n");
				exit(1);
			}
			HLT_HT350MET120_isLoaded = true;
		}
		return HLT_HT350MET120_;
	}
	const int &V00_00_02::HLT_DiEl()
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
	const int &V00_00_02::HLT_DiEl_17_12()
	{
		if (not HLT_DiEl_17_12_isLoaded) {
			if (HLT_DiEl_17_12_branch != 0) {
				HLT_DiEl_17_12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DiEl_17_12_branch does not exist!\n");
				exit(1);
			}
			HLT_DiEl_17_12_isLoaded = true;
		}
		return HLT_DiEl_17_12_;
	}
	const int &V00_00_02::HLT_DiMu()
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
	const int &V00_00_02::HLT_Mu8El17()
	{
		if (not HLT_Mu8El17_isLoaded) {
			if (HLT_Mu8El17_branch != 0) {
				HLT_Mu8El17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8El17_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8El17_isLoaded = true;
		}
		return HLT_Mu8El17_;
	}
	const int &V00_00_02::HLT_Mu8El23()
	{
		if (not HLT_Mu8El23_isLoaded) {
			if (HLT_Mu8El23_branch != 0) {
				HLT_Mu8El23_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8El23_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8El23_isLoaded = true;
		}
		return HLT_Mu8El23_;
	}
	const int &V00_00_02::HLT_Mu17El12()
	{
		if (not HLT_Mu17El12_isLoaded) {
			if (HLT_Mu17El12_branch != 0) {
				HLT_Mu17El12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17El12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17El12_isLoaded = true;
		}
		return HLT_Mu17El12_;
	}
	const int &V00_00_02::HLT_Mu23El12()
	{
		if (not HLT_Mu23El12_isLoaded) {
			if (HLT_Mu23El12_branch != 0) {
				HLT_Mu23El12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23El12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23El12_isLoaded = true;
		}
		return HLT_Mu23El12_;
	}
	const int &V00_00_02::HLT_SingleEl23()
	{
		if (not HLT_SingleEl23_isLoaded) {
			if (HLT_SingleEl23_branch != 0) {
				HLT_SingleEl23_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl23_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl23_isLoaded = true;
		}
		return HLT_SingleEl23_;
	}
	const int &V00_00_02::HLT_SingleEl27()
	{
		if (not HLT_SingleEl27_isLoaded) {
			if (HLT_SingleEl27_branch != 0) {
				HLT_SingleEl27_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl27_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl27_isLoaded = true;
		}
		return HLT_SingleEl27_;
	}
	const int &V00_00_02::HLT_SingleEl27Tight()
	{
		if (not HLT_SingleEl27Tight_isLoaded) {
			if (HLT_SingleEl27Tight_branch != 0) {
				HLT_SingleEl27Tight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl27Tight_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl27Tight_isLoaded = true;
		}
		return HLT_SingleEl27Tight_;
	}
	const int &V00_00_02::HLT_SingleElTight()
	{
		if (not HLT_SingleElTight_isLoaded) {
			if (HLT_SingleElTight_branch != 0) {
				HLT_SingleElTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleElTight_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleElTight_isLoaded = true;
		}
		return HLT_SingleElTight_;
	}
	const int &V00_00_02::HLT_SingleElHT200()
	{
		if (not HLT_SingleElHT200_isLoaded) {
			if (HLT_SingleElHT200_branch != 0) {
				HLT_SingleElHT200_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleElHT200_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleElHT200_isLoaded = true;
		}
		return HLT_SingleElHT200_;
	}
	const int &V00_00_02::HLT_SingleMuNoEta()
	{
		if (not HLT_SingleMuNoEta_isLoaded) {
			if (HLT_SingleMuNoEta_branch != 0) {
				HLT_SingleMuNoEta_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoEta_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoEta_isLoaded = true;
		}
		return HLT_SingleMuNoEta_;
	}
	const int &V00_00_02::HLT_SingleMuNoIso()
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
	const int &V00_00_02::HLT_SingleMuNoIsoNoEta()
	{
		if (not HLT_SingleMuNoIsoNoEta_isLoaded) {
			if (HLT_SingleMuNoIsoNoEta_branch != 0) {
				HLT_SingleMuNoIsoNoEta_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMuNoIsoNoEta_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMuNoIsoNoEta_isLoaded = true;
		}
		return HLT_SingleMuNoIsoNoEta_;
	}
	const int &V00_00_02::HLT_Mu6HT200MET100()
	{
		if (not HLT_Mu6HT200MET100_isLoaded) {
			if (HLT_Mu6HT200MET100_branch != 0) {
				HLT_Mu6HT200MET100_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu6HT200MET100_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu6HT200MET100_isLoaded = true;
		}
		return HLT_Mu6HT200MET100_;
	}
	const int &V00_00_02::HLT_HT350MET100()
	{
		if (not HLT_HT350MET100_isLoaded) {
			if (HLT_HT350MET100_branch != 0) {
				HLT_HT350MET100_branch->GetEntry(index);
			} else { 
				printf("branch HLT_HT350MET100_branch does not exist!\n");
				exit(1);
			}
			HLT_HT350MET100_isLoaded = true;
		}
		return HLT_HT350MET100_;
	}
	const int &V00_00_02::HLT_SingleMu17()
	{
		if (not HLT_SingleMu17_isLoaded) {
			if (HLT_SingleMu17_branch != 0) {
				HLT_SingleMu17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu17_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu17_isLoaded = true;
		}
		return HLT_SingleMu17_;
	}
	const int &V00_00_02::HLT_SingleMu20()
	{
		if (not HLT_SingleMu20_isLoaded) {
			if (HLT_SingleMu20_branch != 0) {
				HLT_SingleMu20_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu20_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu20_isLoaded = true;
		}
		return HLT_SingleMu20_;
	}
	const int &V00_00_02::HLT_SingleMu24()
	{
		if (not HLT_SingleMu24_isLoaded) {
			if (HLT_SingleMu24_branch != 0) {
				HLT_SingleMu24_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu24_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu24_isLoaded = true;
		}
		return HLT_SingleMu24_;
	}
	const int &V00_00_02::HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight()
	{
		if (not HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded) {
			if (HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch != 0) {
				HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_isLoaded = true;
		}
		return HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight_;
	}
	const int &V00_00_02::HLT_MET90_MHT90_IDTight()
	{
		if (not HLT_MET90_MHT90_IDTight_isLoaded) {
			if (HLT_MET90_MHT90_IDTight_branch != 0) {
				HLT_MET90_MHT90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MET90_MHT90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_MET90_MHT90_IDTight_isLoaded = true;
		}
		return HLT_MET90_MHT90_IDTight_;
	}
	const int &V00_00_02::HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight()
	{
		if (not HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded) {
			if (HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch != 0) {
				HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch->GetEntry(index);
			} else { 
				printf("branch HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_branch does not exist!\n");
				exit(1);
			}
			HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_isLoaded = true;
		}
		return HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight_;
	}
	const int &V00_00_02::HLT_Photon90_CaloIdL_PFHT500()
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
	const int &V00_00_02::HLT_Photon165_R9Id90_HE10_IsoM()
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
	const int &V00_00_02::HLT_Photon175()
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
	const int &V00_00_02::HLT_Photon165_HE10()
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
	const float &V00_00_02::pu_weight()
	{
		if (not pu_weight_isLoaded) {
			if (pu_weight_branch != 0) {
				pu_weight_branch->GetEntry(index);
			} else { 
				printf("branch pu_weight_branch does not exist!\n");
				exit(1);
			}
			pu_weight_isLoaded = true;
		}
		return pu_weight_;
	}
	const float &V00_00_02::lep_sf()
	{
		if (not lep_sf_isLoaded) {
			if (lep_sf_branch != 0) {
				lep_sf_branch->GetEntry(index);
			} else { 
				printf("branch lep_sf_branch does not exist!\n");
				exit(1);
			}
			lep_sf_isLoaded = true;
		}
		return lep_sf_;
	}
	const float &V00_00_02::btag_sf()
	{
		if (not btag_sf_isLoaded) {
			if (btag_sf_branch != 0) {
				btag_sf_branch->GetEntry(index);
			} else { 
				printf("branch btag_sf_branch does not exist!\n");
				exit(1);
			}
			btag_sf_isLoaded = true;
		}
		return btag_sf_;
	}
	const float &V00_00_02::HLT_SingleEl_eff()
	{
		if (not HLT_SingleEl_eff_isLoaded) {
			if (HLT_SingleEl_eff_branch != 0) {
				HLT_SingleEl_eff_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleEl_eff_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleEl_eff_isLoaded = true;
		}
		return HLT_SingleEl_eff_;
	}
	const float &V00_00_02::HLT_SingleMu_eff()
	{
		if (not HLT_SingleMu_eff_isLoaded) {
			if (HLT_SingleMu_eff_branch != 0) {
				HLT_SingleMu_eff_branch->GetEntry(index);
			} else { 
				printf("branch HLT_SingleMu_eff_branch does not exist!\n");
				exit(1);
			}
			HLT_SingleMu_eff_isLoaded = true;
		}
		return HLT_SingleMu_eff_;
	}
	const bool &	V00_00_02::lep1_is_mu()
	{
		if (not lep1_is_mu_isLoaded) {
			if (lep1_is_mu_branch != 0) {
				lep1_is_mu_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_mu_branch does not exist!\n");
				exit(1);
			}
			lep1_is_mu_isLoaded = true;
		}
		return lep1_is_mu_;
	}
	const bool &	V00_00_02::lep1_is_el()
	{
		if (not lep1_is_el_isLoaded) {
			if (lep1_is_el_branch != 0) {
				lep1_is_el_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_el_branch does not exist!\n");
				exit(1);
			}
			lep1_is_el_isLoaded = true;
		}
		return lep1_is_el_;
	}
	const int &V00_00_02::lep1_charge()
	{
		if (not lep1_charge_isLoaded) {
			if (lep1_charge_branch != 0) {
				lep1_charge_branch->GetEntry(index);
			} else { 
				printf("branch lep1_charge_branch does not exist!\n");
				exit(1);
			}
			lep1_charge_isLoaded = true;
		}
		return lep1_charge_;
	}
	const int &V00_00_02::lep1_pdgid()
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
	const int &V00_00_02::lep1_type()
	{
		if (not lep1_type_isLoaded) {
			if (lep1_type_branch != 0) {
				lep1_type_branch->GetEntry(index);
			} else { 
				printf("branch lep1_type_branch does not exist!\n");
				exit(1);
			}
			lep1_type_isLoaded = true;
		}
		return lep1_type_;
	}
	const int &V00_00_02::lep1_production_type()
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
	const float &V00_00_02::lep1_d0()
	{
		if (not lep1_d0_isLoaded) {
			if (lep1_d0_branch != 0) {
				lep1_d0_branch->GetEntry(index);
			} else { 
				printf("branch lep1_d0_branch does not exist!\n");
				exit(1);
			}
			lep1_d0_isLoaded = true;
		}
		return lep1_d0_;
	}
	const float &V00_00_02::lep1_d0err()
	{
		if (not lep1_d0err_isLoaded) {
			if (lep1_d0err_branch != 0) {
				lep1_d0err_branch->GetEntry(index);
			} else { 
				printf("branch lep1_d0err_branch does not exist!\n");
				exit(1);
			}
			lep1_d0err_isLoaded = true;
		}
		return lep1_d0err_;
	}
	const float &V00_00_02::lep1_dz()
	{
		if (not lep1_dz_isLoaded) {
			if (lep1_dz_branch != 0) {
				lep1_dz_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dz_branch does not exist!\n");
				exit(1);
			}
			lep1_dz_isLoaded = true;
		}
		return lep1_dz_;
	}
	const float &V00_00_02::lep1_dzerr()
	{
		if (not lep1_dzerr_isLoaded) {
			if (lep1_dzerr_branch != 0) {
				lep1_dzerr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dzerr_branch does not exist!\n");
				exit(1);
			}
			lep1_dzerr_isLoaded = true;
		}
		return lep1_dzerr_;
	}
	const float &V00_00_02::lep1_sigmaIEtaEta_fill5x5()
	{
		if (not lep1_sigmaIEtaEta_fill5x5_isLoaded) {
			if (lep1_sigmaIEtaEta_fill5x5_branch != 0) {
				lep1_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
			} else { 
				printf("branch lep1_sigmaIEtaEta_fill5x5_branch does not exist!\n");
				exit(1);
			}
			lep1_sigmaIEtaEta_fill5x5_isLoaded = true;
		}
		return lep1_sigmaIEtaEta_fill5x5_;
	}
	const float &V00_00_02::lep1_dEtaIn()
	{
		if (not lep1_dEtaIn_isLoaded) {
			if (lep1_dEtaIn_branch != 0) {
				lep1_dEtaIn_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dEtaIn_branch does not exist!\n");
				exit(1);
			}
			lep1_dEtaIn_isLoaded = true;
		}
		return lep1_dEtaIn_;
	}
	const float &V00_00_02::lep1_dPhiIn()
	{
		if (not lep1_dPhiIn_isLoaded) {
			if (lep1_dPhiIn_branch != 0) {
				lep1_dPhiIn_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dPhiIn_branch does not exist!\n");
				exit(1);
			}
			lep1_dPhiIn_isLoaded = true;
		}
		return lep1_dPhiIn_;
	}
	const float &V00_00_02::lep1_hOverE()
	{
		if (not lep1_hOverE_isLoaded) {
			if (lep1_hOverE_branch != 0) {
				lep1_hOverE_branch->GetEntry(index);
			} else { 
				printf("branch lep1_hOverE_branch does not exist!\n");
				exit(1);
			}
			lep1_hOverE_isLoaded = true;
		}
		return lep1_hOverE_;
	}
	const float &V00_00_02::lep1_ooEmooP()
	{
		if (not lep1_ooEmooP_isLoaded) {
			if (lep1_ooEmooP_branch != 0) {
				lep1_ooEmooP_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ooEmooP_branch does not exist!\n");
				exit(1);
			}
			lep1_ooEmooP_isLoaded = true;
		}
		return lep1_ooEmooP_;
	}
	const int &V00_00_02::lep1_expectedMissingInnerHits()
	{
		if (not lep1_expectedMissingInnerHits_isLoaded) {
			if (lep1_expectedMissingInnerHits_branch != 0) {
				lep1_expectedMissingInnerHits_branch->GetEntry(index);
			} else { 
				printf("branch lep1_expectedMissingInnerHits_branch does not exist!\n");
				exit(1);
			}
			lep1_expectedMissingInnerHits_isLoaded = true;
		}
		return lep1_expectedMissingInnerHits_;
	}
	const bool &	V00_00_02::lep1_conversionVeto()
	{
		if (not lep1_conversionVeto_isLoaded) {
			if (lep1_conversionVeto_branch != 0) {
				lep1_conversionVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep1_conversionVeto_branch does not exist!\n");
				exit(1);
			}
			lep1_conversionVeto_isLoaded = true;
		}
		return lep1_conversionVeto_;
	}
	const float &V00_00_02::lep1_etaSC()
	{
		if (not lep1_etaSC_isLoaded) {
			if (lep1_etaSC_branch != 0) {
				lep1_etaSC_branch->GetEntry(index);
			} else { 
				printf("branch lep1_etaSC_branch does not exist!\n");
				exit(1);
			}
			lep1_etaSC_isLoaded = true;
		}
		return lep1_etaSC_;
	}
	const float &V00_00_02::lep1_ChiSqr()
	{
		if (not lep1_ChiSqr_isLoaded) {
			if (lep1_ChiSqr_branch != 0) {
				lep1_ChiSqr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ChiSqr_branch does not exist!\n");
				exit(1);
			}
			lep1_ChiSqr_isLoaded = true;
		}
		return lep1_ChiSqr_;
	}
	const float &V00_00_02::lep1_chiso()
	{
		if (not lep1_chiso_isLoaded) {
			if (lep1_chiso_branch != 0) {
				lep1_chiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_chiso_branch does not exist!\n");
				exit(1);
			}
			lep1_chiso_isLoaded = true;
		}
		return lep1_chiso_;
	}
	const float &V00_00_02::lep1_nhiso()
	{
		if (not lep1_nhiso_isLoaded) {
			if (lep1_nhiso_branch != 0) {
				lep1_nhiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_nhiso_branch does not exist!\n");
				exit(1);
			}
			lep1_nhiso_isLoaded = true;
		}
		return lep1_nhiso_;
	}
	const float &V00_00_02::lep1_emiso()
	{
		if (not lep1_emiso_isLoaded) {
			if (lep1_emiso_branch != 0) {
				lep1_emiso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_emiso_branch does not exist!\n");
				exit(1);
			}
			lep1_emiso_isLoaded = true;
		}
		return lep1_emiso_;
	}
	const float &V00_00_02::lep1_deltaBeta()
	{
		if (not lep1_deltaBeta_isLoaded) {
			if (lep1_deltaBeta_branch != 0) {
				lep1_deltaBeta_branch->GetEntry(index);
			} else { 
				printf("branch lep1_deltaBeta_branch does not exist!\n");
				exit(1);
			}
			lep1_deltaBeta_isLoaded = true;
		}
		return lep1_deltaBeta_;
	}
	const float &V00_00_02::lep1_relIso03DB()
	{
		if (not lep1_relIso03DB_isLoaded) {
			if (lep1_relIso03DB_branch != 0) {
				lep1_relIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso03DB_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso03DB_isLoaded = true;
		}
		return lep1_relIso03DB_;
	}
	const float &V00_00_02::lep1_relIso03EA()
	{
		if (not lep1_relIso03EA_isLoaded) {
			if (lep1_relIso03EA_branch != 0) {
				lep1_relIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso03EA_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso03EA_isLoaded = true;
		}
		return lep1_relIso03EA_;
	}
	const float &V00_00_02::lep1_relIso04DB()
	{
		if (not lep1_relIso04DB_isLoaded) {
			if (lep1_relIso04DB_branch != 0) {
				lep1_relIso04DB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_relIso04DB_branch does not exist!\n");
				exit(1);
			}
			lep1_relIso04DB_isLoaded = true;
		}
		return lep1_relIso04DB_;
	}
	const float &V00_00_02::lep1_miniRelIsoDB()
	{
		if (not lep1_miniRelIsoDB_isLoaded) {
			if (lep1_miniRelIsoDB_branch != 0) {
				lep1_miniRelIsoDB_branch->GetEntry(index);
			} else { 
				printf("branch lep1_miniRelIsoDB_branch does not exist!\n");
				exit(1);
			}
			lep1_miniRelIsoDB_isLoaded = true;
		}
		return lep1_miniRelIsoDB_;
	}
	const float &V00_00_02::lep1_miniRelIsoEA()
	{
		if (not lep1_miniRelIsoEA_isLoaded) {
			if (lep1_miniRelIsoEA_branch != 0) {
				lep1_miniRelIsoEA_branch->GetEntry(index);
			} else { 
				printf("branch lep1_miniRelIsoEA_branch does not exist!\n");
				exit(1);
			}
			lep1_miniRelIsoEA_isLoaded = true;
		}
		return lep1_miniRelIsoEA_;
	}
	const float &V00_00_02::lep1_MiniIso()
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
	const int &V00_00_02::lep1_mcid()
	{
		if (not lep1_mcid_isLoaded) {
			if (lep1_mcid_branch != 0) {
				lep1_mcid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcid_branch does not exist!\n");
				exit(1);
			}
			lep1_mcid_isLoaded = true;
		}
		return lep1_mcid_;
	}
	const int &V00_00_02::lep1_mcstatus()
	{
		if (not lep1_mcstatus_isLoaded) {
			if (lep1_mcstatus_branch != 0) {
				lep1_mcstatus_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mcstatus_branch does not exist!\n");
				exit(1);
			}
			lep1_mcstatus_isLoaded = true;
		}
		return lep1_mcstatus_;
	}
	const int &V00_00_02::lep1_mc3dr()
	{
		if (not lep1_mc3dr_isLoaded) {
			if (lep1_mc3dr_branch != 0) {
				lep1_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3dr_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3dr_isLoaded = true;
		}
		return lep1_mc3dr_;
	}
	const int &V00_00_02::lep1_mc3id()
	{
		if (not lep1_mc3id_isLoaded) {
			if (lep1_mc3id_branch != 0) {
				lep1_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3id_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3id_isLoaded = true;
		}
		return lep1_mc3id_;
	}
	const int &V00_00_02::lep1_mc3idx()
	{
		if (not lep1_mc3idx_isLoaded) {
			if (lep1_mc3idx_branch != 0) {
				lep1_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3idx_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3idx_isLoaded = true;
		}
		return lep1_mc3idx_;
	}
	const int &V00_00_02::lep1_mc3motherid()
	{
		if (not lep1_mc3motherid_isLoaded) {
			if (lep1_mc3motherid_branch != 0) {
				lep1_mc3motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3motherid_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3motherid_isLoaded = true;
		}
		return lep1_mc3motherid_;
	}
	const int &V00_00_02::lep1_mc3motheridx()
	{
		if (not lep1_mc3motheridx_isLoaded) {
			if (lep1_mc3motheridx_branch != 0) {
				lep1_mc3motheridx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc3motheridx_branch does not exist!\n");
				exit(1);
			}
			lep1_mc3motheridx_isLoaded = true;
		}
		return lep1_mc3motheridx_;
	}
	const bool &	V00_00_02::lep1_is_eleid_loose()
	{
		if (not lep1_is_eleid_loose_isLoaded) {
			if (lep1_is_eleid_loose_branch != 0) {
				lep1_is_eleid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_loose_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_loose_isLoaded = true;
		}
		return lep1_is_eleid_loose_;
	}
	const bool &	V00_00_02::lep1_is_eleid_medium()
	{
		if (not lep1_is_eleid_medium_isLoaded) {
			if (lep1_is_eleid_medium_branch != 0) {
				lep1_is_eleid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_medium_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_medium_isLoaded = true;
		}
		return lep1_is_eleid_medium_;
	}
	const bool &	V00_00_02::lep1_is_eleid_tight()
	{
		if (not lep1_is_eleid_tight_isLoaded) {
			if (lep1_is_eleid_tight_branch != 0) {
				lep1_is_eleid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_eleid_tight_branch does not exist!\n");
				exit(1);
			}
			lep1_is_eleid_tight_isLoaded = true;
		}
		return lep1_is_eleid_tight_;
	}
	const bool &	V00_00_02::lep1_is_phys14_loose_noIso()
	{
		if (not lep1_is_phys14_loose_noIso_isLoaded) {
			if (lep1_is_phys14_loose_noIso_branch != 0) {
				lep1_is_phys14_loose_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_loose_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_loose_noIso_isLoaded = true;
		}
		return lep1_is_phys14_loose_noIso_;
	}
	const bool &	V00_00_02::lep1_is_phys14_medium_noIso()
	{
		if (not lep1_is_phys14_medium_noIso_isLoaded) {
			if (lep1_is_phys14_medium_noIso_branch != 0) {
				lep1_is_phys14_medium_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_medium_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_medium_noIso_isLoaded = true;
		}
		return lep1_is_phys14_medium_noIso_;
	}
	const bool &	V00_00_02::lep1_is_phys14_tight_noIso()
	{
		if (not lep1_is_phys14_tight_noIso_isLoaded) {
			if (lep1_is_phys14_tight_noIso_branch != 0) {
				lep1_is_phys14_tight_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_phys14_tight_noIso_branch does not exist!\n");
				exit(1);
			}
			lep1_is_phys14_tight_noIso_isLoaded = true;
		}
		return lep1_is_phys14_tight_noIso_;
	}
	const float &V00_00_02::lep1_eoverpin()
	{
		if (not lep1_eoverpin_isLoaded) {
			if (lep1_eoverpin_branch != 0) {
				lep1_eoverpin_branch->GetEntry(index);
			} else { 
				printf("branch lep1_eoverpin_branch does not exist!\n");
				exit(1);
			}
			lep1_eoverpin_isLoaded = true;
		}
		return lep1_eoverpin_;
	}
	const bool &	V00_00_02::lep1_is_muoid_loose()
	{
		if (not lep1_is_muoid_loose_isLoaded) {
			if (lep1_is_muoid_loose_branch != 0) {
				lep1_is_muoid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_loose_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_loose_isLoaded = true;
		}
		return lep1_is_muoid_loose_;
	}
	const bool &	V00_00_02::lep1_is_muoid_medium()
	{
		if (not lep1_is_muoid_medium_isLoaded) {
			if (lep1_is_muoid_medium_branch != 0) {
				lep1_is_muoid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_medium_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_medium_isLoaded = true;
		}
		return lep1_is_muoid_medium_;
	}
	const bool &	V00_00_02::lep1_is_muoid_tight()
	{
		if (not lep1_is_muoid_tight_isLoaded) {
			if (lep1_is_muoid_tight_branch != 0) {
				lep1_is_muoid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_muoid_tight_branch does not exist!\n");
				exit(1);
			}
			lep1_is_muoid_tight_isLoaded = true;
		}
		return lep1_is_muoid_tight_;
	}
	const float &V00_00_02::lep1_ip3d()
	{
		if (not lep1_ip3d_isLoaded) {
			if (lep1_ip3d_branch != 0) {
				lep1_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3d_isLoaded = true;
		}
		return lep1_ip3d_;
	}
	const float &V00_00_02::lep1_ip3derr()
	{
		if (not lep1_ip3derr_isLoaded) {
			if (lep1_ip3derr_branch != 0) {
				lep1_ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3derr_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3derr_isLoaded = true;
		}
		return lep1_ip3derr_;
	}
	const bool &	V00_00_02::lep1_is_pfmu()
	{
		if (not lep1_is_pfmu_isLoaded) {
			if (lep1_is_pfmu_branch != 0) {
				lep1_is_pfmu_branch->GetEntry(index);
			} else { 
				printf("branch lep1_is_pfmu_branch does not exist!\n");
				exit(1);
			}
			lep1_is_pfmu_isLoaded = true;
		}
		return lep1_is_pfmu_;
	}
	const bool &	V00_00_02::lep1_passMediumID()
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
	const bool &	V00_00_02::lep1_passVeto()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::lep1_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::lep1_mcp4()
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
	const float &V00_00_02::lep1_pt()
	{
		if (not lep1_pt_isLoaded) {
			if (lep1_pt_branch != 0) {
				lep1_pt_branch->GetEntry(index);
			} else { 
				printf("branch lep1_pt_branch does not exist!\n");
				exit(1);
			}
			lep1_pt_isLoaded = true;
		}
		return lep1_pt_;
	}
	const float &V00_00_02::lep1_eta()
	{
		if (not lep1_eta_isLoaded) {
			if (lep1_eta_branch != 0) {
				lep1_eta_branch->GetEntry(index);
			} else { 
				printf("branch lep1_eta_branch does not exist!\n");
				exit(1);
			}
			lep1_eta_isLoaded = true;
		}
		return lep1_eta_;
	}
	const float &V00_00_02::lep1_phi()
	{
		if (not lep1_phi_isLoaded) {
			if (lep1_phi_branch != 0) {
				lep1_phi_branch->GetEntry(index);
			} else { 
				printf("branch lep1_phi_branch does not exist!\n");
				exit(1);
			}
			lep1_phi_isLoaded = true;
		}
		return lep1_phi_;
	}
	const float &V00_00_02::lep1_mass()
	{
		if (not lep1_mass_isLoaded) {
			if (lep1_mass_branch != 0) {
				lep1_mass_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mass_branch does not exist!\n");
				exit(1);
			}
			lep1_mass_isLoaded = true;
		}
		return lep1_mass_;
	}
	const bool &	V00_00_02::lep2_is_mu()
	{
		if (not lep2_is_mu_isLoaded) {
			if (lep2_is_mu_branch != 0) {
				lep2_is_mu_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_mu_branch does not exist!\n");
				exit(1);
			}
			lep2_is_mu_isLoaded = true;
		}
		return lep2_is_mu_;
	}
	const bool &	V00_00_02::lep2_is_el()
	{
		if (not lep2_is_el_isLoaded) {
			if (lep2_is_el_branch != 0) {
				lep2_is_el_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_el_branch does not exist!\n");
				exit(1);
			}
			lep2_is_el_isLoaded = true;
		}
		return lep2_is_el_;
	}
	const int &V00_00_02::lep2_charge()
	{
		if (not lep2_charge_isLoaded) {
			if (lep2_charge_branch != 0) {
				lep2_charge_branch->GetEntry(index);
			} else { 
				printf("branch lep2_charge_branch does not exist!\n");
				exit(1);
			}
			lep2_charge_isLoaded = true;
		}
		return lep2_charge_;
	}
	const int &V00_00_02::lep2_pdgid()
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
	const int &V00_00_02::lep2_type()
	{
		if (not lep2_type_isLoaded) {
			if (lep2_type_branch != 0) {
				lep2_type_branch->GetEntry(index);
			} else { 
				printf("branch lep2_type_branch does not exist!\n");
				exit(1);
			}
			lep2_type_isLoaded = true;
		}
		return lep2_type_;
	}
	const int &V00_00_02::lep2_production_type()
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
	const float &V00_00_02::lep2_d0()
	{
		if (not lep2_d0_isLoaded) {
			if (lep2_d0_branch != 0) {
				lep2_d0_branch->GetEntry(index);
			} else { 
				printf("branch lep2_d0_branch does not exist!\n");
				exit(1);
			}
			lep2_d0_isLoaded = true;
		}
		return lep2_d0_;
	}
	const float &V00_00_02::lep2_d0err()
	{
		if (not lep2_d0err_isLoaded) {
			if (lep2_d0err_branch != 0) {
				lep2_d0err_branch->GetEntry(index);
			} else { 
				printf("branch lep2_d0err_branch does not exist!\n");
				exit(1);
			}
			lep2_d0err_isLoaded = true;
		}
		return lep2_d0err_;
	}
	const float &V00_00_02::lep2_dz()
	{
		if (not lep2_dz_isLoaded) {
			if (lep2_dz_branch != 0) {
				lep2_dz_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dz_branch does not exist!\n");
				exit(1);
			}
			lep2_dz_isLoaded = true;
		}
		return lep2_dz_;
	}
	const float &V00_00_02::lep2_dzerr()
	{
		if (not lep2_dzerr_isLoaded) {
			if (lep2_dzerr_branch != 0) {
				lep2_dzerr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dzerr_branch does not exist!\n");
				exit(1);
			}
			lep2_dzerr_isLoaded = true;
		}
		return lep2_dzerr_;
	}
	const float &V00_00_02::lep2_sigmaIEtaEta_fill5x5()
	{
		if (not lep2_sigmaIEtaEta_fill5x5_isLoaded) {
			if (lep2_sigmaIEtaEta_fill5x5_branch != 0) {
				lep2_sigmaIEtaEta_fill5x5_branch->GetEntry(index);
			} else { 
				printf("branch lep2_sigmaIEtaEta_fill5x5_branch does not exist!\n");
				exit(1);
			}
			lep2_sigmaIEtaEta_fill5x5_isLoaded = true;
		}
		return lep2_sigmaIEtaEta_fill5x5_;
	}
	const float &V00_00_02::lep2_dEtaIn()
	{
		if (not lep2_dEtaIn_isLoaded) {
			if (lep2_dEtaIn_branch != 0) {
				lep2_dEtaIn_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dEtaIn_branch does not exist!\n");
				exit(1);
			}
			lep2_dEtaIn_isLoaded = true;
		}
		return lep2_dEtaIn_;
	}
	const float &V00_00_02::lep2_dPhiIn()
	{
		if (not lep2_dPhiIn_isLoaded) {
			if (lep2_dPhiIn_branch != 0) {
				lep2_dPhiIn_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dPhiIn_branch does not exist!\n");
				exit(1);
			}
			lep2_dPhiIn_isLoaded = true;
		}
		return lep2_dPhiIn_;
	}
	const float &V00_00_02::lep2_hOverE()
	{
		if (not lep2_hOverE_isLoaded) {
			if (lep2_hOverE_branch != 0) {
				lep2_hOverE_branch->GetEntry(index);
			} else { 
				printf("branch lep2_hOverE_branch does not exist!\n");
				exit(1);
			}
			lep2_hOverE_isLoaded = true;
		}
		return lep2_hOverE_;
	}
	const float &V00_00_02::lep2_ooEmooP()
	{
		if (not lep2_ooEmooP_isLoaded) {
			if (lep2_ooEmooP_branch != 0) {
				lep2_ooEmooP_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ooEmooP_branch does not exist!\n");
				exit(1);
			}
			lep2_ooEmooP_isLoaded = true;
		}
		return lep2_ooEmooP_;
	}
	const int &V00_00_02::lep2_expectedMissingInnerHits()
	{
		if (not lep2_expectedMissingInnerHits_isLoaded) {
			if (lep2_expectedMissingInnerHits_branch != 0) {
				lep2_expectedMissingInnerHits_branch->GetEntry(index);
			} else { 
				printf("branch lep2_expectedMissingInnerHits_branch does not exist!\n");
				exit(1);
			}
			lep2_expectedMissingInnerHits_isLoaded = true;
		}
		return lep2_expectedMissingInnerHits_;
	}
	const bool &	V00_00_02::lep2_conversionVeto()
	{
		if (not lep2_conversionVeto_isLoaded) {
			if (lep2_conversionVeto_branch != 0) {
				lep2_conversionVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep2_conversionVeto_branch does not exist!\n");
				exit(1);
			}
			lep2_conversionVeto_isLoaded = true;
		}
		return lep2_conversionVeto_;
	}
	const float &V00_00_02::lep2_etaSC()
	{
		if (not lep2_etaSC_isLoaded) {
			if (lep2_etaSC_branch != 0) {
				lep2_etaSC_branch->GetEntry(index);
			} else { 
				printf("branch lep2_etaSC_branch does not exist!\n");
				exit(1);
			}
			lep2_etaSC_isLoaded = true;
		}
		return lep2_etaSC_;
	}
	const float &V00_00_02::lep2_ChiSqr()
	{
		if (not lep2_ChiSqr_isLoaded) {
			if (lep2_ChiSqr_branch != 0) {
				lep2_ChiSqr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ChiSqr_branch does not exist!\n");
				exit(1);
			}
			lep2_ChiSqr_isLoaded = true;
		}
		return lep2_ChiSqr_;
	}
	const float &V00_00_02::lep2_chiso()
	{
		if (not lep2_chiso_isLoaded) {
			if (lep2_chiso_branch != 0) {
				lep2_chiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_chiso_branch does not exist!\n");
				exit(1);
			}
			lep2_chiso_isLoaded = true;
		}
		return lep2_chiso_;
	}
	const float &V00_00_02::lep2_nhiso()
	{
		if (not lep2_nhiso_isLoaded) {
			if (lep2_nhiso_branch != 0) {
				lep2_nhiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_nhiso_branch does not exist!\n");
				exit(1);
			}
			lep2_nhiso_isLoaded = true;
		}
		return lep2_nhiso_;
	}
	const float &V00_00_02::lep2_emiso()
	{
		if (not lep2_emiso_isLoaded) {
			if (lep2_emiso_branch != 0) {
				lep2_emiso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_emiso_branch does not exist!\n");
				exit(1);
			}
			lep2_emiso_isLoaded = true;
		}
		return lep2_emiso_;
	}
	const float &V00_00_02::lep2_deltaBeta()
	{
		if (not lep2_deltaBeta_isLoaded) {
			if (lep2_deltaBeta_branch != 0) {
				lep2_deltaBeta_branch->GetEntry(index);
			} else { 
				printf("branch lep2_deltaBeta_branch does not exist!\n");
				exit(1);
			}
			lep2_deltaBeta_isLoaded = true;
		}
		return lep2_deltaBeta_;
	}
	const float &V00_00_02::lep2_relIso03DB()
	{
		if (not lep2_relIso03DB_isLoaded) {
			if (lep2_relIso03DB_branch != 0) {
				lep2_relIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso03DB_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso03DB_isLoaded = true;
		}
		return lep2_relIso03DB_;
	}
	const float &V00_00_02::lep2_relIso03EA()
	{
		if (not lep2_relIso03EA_isLoaded) {
			if (lep2_relIso03EA_branch != 0) {
				lep2_relIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso03EA_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso03EA_isLoaded = true;
		}
		return lep2_relIso03EA_;
	}
	const float &V00_00_02::lep2_relIso04DB()
	{
		if (not lep2_relIso04DB_isLoaded) {
			if (lep2_relIso04DB_branch != 0) {
				lep2_relIso04DB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_relIso04DB_branch does not exist!\n");
				exit(1);
			}
			lep2_relIso04DB_isLoaded = true;
		}
		return lep2_relIso04DB_;
	}
	const float &V00_00_02::lep2_miniRelIsoDB()
	{
		if (not lep2_miniRelIsoDB_isLoaded) {
			if (lep2_miniRelIsoDB_branch != 0) {
				lep2_miniRelIsoDB_branch->GetEntry(index);
			} else { 
				printf("branch lep2_miniRelIsoDB_branch does not exist!\n");
				exit(1);
			}
			lep2_miniRelIsoDB_isLoaded = true;
		}
		return lep2_miniRelIsoDB_;
	}
	const float &V00_00_02::lep2_miniRelIsoEA()
	{
		if (not lep2_miniRelIsoEA_isLoaded) {
			if (lep2_miniRelIsoEA_branch != 0) {
				lep2_miniRelIsoEA_branch->GetEntry(index);
			} else { 
				printf("branch lep2_miniRelIsoEA_branch does not exist!\n");
				exit(1);
			}
			lep2_miniRelIsoEA_isLoaded = true;
		}
		return lep2_miniRelIsoEA_;
	}
	const float &V00_00_02::lep2_MiniIso()
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
	const int &V00_00_02::lep2_mcid()
	{
		if (not lep2_mcid_isLoaded) {
			if (lep2_mcid_branch != 0) {
				lep2_mcid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcid_branch does not exist!\n");
				exit(1);
			}
			lep2_mcid_isLoaded = true;
		}
		return lep2_mcid_;
	}
	const int &V00_00_02::lep2_mcstatus()
	{
		if (not lep2_mcstatus_isLoaded) {
			if (lep2_mcstatus_branch != 0) {
				lep2_mcstatus_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mcstatus_branch does not exist!\n");
				exit(1);
			}
			lep2_mcstatus_isLoaded = true;
		}
		return lep2_mcstatus_;
	}
	const int &V00_00_02::lep2_mc3dr()
	{
		if (not lep2_mc3dr_isLoaded) {
			if (lep2_mc3dr_branch != 0) {
				lep2_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3dr_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3dr_isLoaded = true;
		}
		return lep2_mc3dr_;
	}
	const int &V00_00_02::lep2_mc3id()
	{
		if (not lep2_mc3id_isLoaded) {
			if (lep2_mc3id_branch != 0) {
				lep2_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3id_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3id_isLoaded = true;
		}
		return lep2_mc3id_;
	}
	const int &V00_00_02::lep2_mc3idx()
	{
		if (not lep2_mc3idx_isLoaded) {
			if (lep2_mc3idx_branch != 0) {
				lep2_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3idx_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3idx_isLoaded = true;
		}
		return lep2_mc3idx_;
	}
	const int &V00_00_02::lep2_mc3motherid()
	{
		if (not lep2_mc3motherid_isLoaded) {
			if (lep2_mc3motherid_branch != 0) {
				lep2_mc3motherid_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3motherid_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3motherid_isLoaded = true;
		}
		return lep2_mc3motherid_;
	}
	const int &V00_00_02::lep2_mc3motheridx()
	{
		if (not lep2_mc3motheridx_isLoaded) {
			if (lep2_mc3motheridx_branch != 0) {
				lep2_mc3motheridx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc3motheridx_branch does not exist!\n");
				exit(1);
			}
			lep2_mc3motheridx_isLoaded = true;
		}
		return lep2_mc3motheridx_;
	}
	const bool &	V00_00_02::lep2_is_eleid_loose()
	{
		if (not lep2_is_eleid_loose_isLoaded) {
			if (lep2_is_eleid_loose_branch != 0) {
				lep2_is_eleid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_loose_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_loose_isLoaded = true;
		}
		return lep2_is_eleid_loose_;
	}
	const bool &	V00_00_02::lep2_is_eleid_medium()
	{
		if (not lep2_is_eleid_medium_isLoaded) {
			if (lep2_is_eleid_medium_branch != 0) {
				lep2_is_eleid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_medium_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_medium_isLoaded = true;
		}
		return lep2_is_eleid_medium_;
	}
	const bool &	V00_00_02::lep2_is_eleid_tight()
	{
		if (not lep2_is_eleid_tight_isLoaded) {
			if (lep2_is_eleid_tight_branch != 0) {
				lep2_is_eleid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_eleid_tight_branch does not exist!\n");
				exit(1);
			}
			lep2_is_eleid_tight_isLoaded = true;
		}
		return lep2_is_eleid_tight_;
	}
	const bool &	V00_00_02::lep2_is_phys14_loose_noIso()
	{
		if (not lep2_is_phys14_loose_noIso_isLoaded) {
			if (lep2_is_phys14_loose_noIso_branch != 0) {
				lep2_is_phys14_loose_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_loose_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_loose_noIso_isLoaded = true;
		}
		return lep2_is_phys14_loose_noIso_;
	}
	const bool &	V00_00_02::lep2_is_phys14_medium_noIso()
	{
		if (not lep2_is_phys14_medium_noIso_isLoaded) {
			if (lep2_is_phys14_medium_noIso_branch != 0) {
				lep2_is_phys14_medium_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_medium_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_medium_noIso_isLoaded = true;
		}
		return lep2_is_phys14_medium_noIso_;
	}
	const bool &	V00_00_02::lep2_is_phys14_tight_noIso()
	{
		if (not lep2_is_phys14_tight_noIso_isLoaded) {
			if (lep2_is_phys14_tight_noIso_branch != 0) {
				lep2_is_phys14_tight_noIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_phys14_tight_noIso_branch does not exist!\n");
				exit(1);
			}
			lep2_is_phys14_tight_noIso_isLoaded = true;
		}
		return lep2_is_phys14_tight_noIso_;
	}
	const float &V00_00_02::lep2_eoverpin()
	{
		if (not lep2_eoverpin_isLoaded) {
			if (lep2_eoverpin_branch != 0) {
				lep2_eoverpin_branch->GetEntry(index);
			} else { 
				printf("branch lep2_eoverpin_branch does not exist!\n");
				exit(1);
			}
			lep2_eoverpin_isLoaded = true;
		}
		return lep2_eoverpin_;
	}
	const bool &	V00_00_02::lep2_is_muoid_loose()
	{
		if (not lep2_is_muoid_loose_isLoaded) {
			if (lep2_is_muoid_loose_branch != 0) {
				lep2_is_muoid_loose_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_loose_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_loose_isLoaded = true;
		}
		return lep2_is_muoid_loose_;
	}
	const bool &	V00_00_02::lep2_is_muoid_medium()
	{
		if (not lep2_is_muoid_medium_isLoaded) {
			if (lep2_is_muoid_medium_branch != 0) {
				lep2_is_muoid_medium_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_medium_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_medium_isLoaded = true;
		}
		return lep2_is_muoid_medium_;
	}
	const bool &	V00_00_02::lep2_is_muoid_tight()
	{
		if (not lep2_is_muoid_tight_isLoaded) {
			if (lep2_is_muoid_tight_branch != 0) {
				lep2_is_muoid_tight_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_muoid_tight_branch does not exist!\n");
				exit(1);
			}
			lep2_is_muoid_tight_isLoaded = true;
		}
		return lep2_is_muoid_tight_;
	}
	const float &V00_00_02::lep2_ip3d()
	{
		if (not lep2_ip3d_isLoaded) {
			if (lep2_ip3d_branch != 0) {
				lep2_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3d_isLoaded = true;
		}
		return lep2_ip3d_;
	}
	const float &V00_00_02::lep2_ip3derr()
	{
		if (not lep2_ip3derr_isLoaded) {
			if (lep2_ip3derr_branch != 0) {
				lep2_ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3derr_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3derr_isLoaded = true;
		}
		return lep2_ip3derr_;
	}
	const bool &	V00_00_02::lep2_is_pfmu()
	{
		if (not lep2_is_pfmu_isLoaded) {
			if (lep2_is_pfmu_branch != 0) {
				lep2_is_pfmu_branch->GetEntry(index);
			} else { 
				printf("branch lep2_is_pfmu_branch does not exist!\n");
				exit(1);
			}
			lep2_is_pfmu_isLoaded = true;
		}
		return lep2_is_pfmu_;
	}
	const bool &	V00_00_02::lep2_passMediumID()
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
	const bool &	V00_00_02::lep2_passVeto()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::lep2_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::lep2_mcp4()
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
	const float &V00_00_02::lep2_pt()
	{
		if (not lep2_pt_isLoaded) {
			if (lep2_pt_branch != 0) {
				lep2_pt_branch->GetEntry(index);
			} else { 
				printf("branch lep2_pt_branch does not exist!\n");
				exit(1);
			}
			lep2_pt_isLoaded = true;
		}
		return lep2_pt_;
	}
	const float &V00_00_02::lep2_eta()
	{
		if (not lep2_eta_isLoaded) {
			if (lep2_eta_branch != 0) {
				lep2_eta_branch->GetEntry(index);
			} else { 
				printf("branch lep2_eta_branch does not exist!\n");
				exit(1);
			}
			lep2_eta_isLoaded = true;
		}
		return lep2_eta_;
	}
	const float &V00_00_02::lep2_phi()
	{
		if (not lep2_phi_isLoaded) {
			if (lep2_phi_branch != 0) {
				lep2_phi_branch->GetEntry(index);
			} else { 
				printf("branch lep2_phi_branch does not exist!\n");
				exit(1);
			}
			lep2_phi_isLoaded = true;
		}
		return lep2_phi_;
	}
	const float &V00_00_02::lep2_mass()
	{
		if (not lep2_mass_isLoaded) {
			if (lep2_mass_branch != 0) {
				lep2_mass_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mass_branch does not exist!\n");
				exit(1);
			}
			lep2_mass_isLoaded = true;
		}
		return lep2_mass_;
	}
	const int &V00_00_02::nGoodGenJets()
	{
		if (not nGoodGenJets_isLoaded) {
			if (nGoodGenJets_branch != 0) {
				nGoodGenJets_branch->GetEntry(index);
			} else { 
				printf("branch nGoodGenJets_branch does not exist!\n");
				exit(1);
			}
			nGoodGenJets_isLoaded = true;
		}
		return nGoodGenJets_;
	}
	const int &V00_00_02::ngoodjets()
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
	const int &V00_00_02::nfailjets()
	{
		if (not nfailjets_isLoaded) {
			if (nfailjets_branch != 0) {
				nfailjets_branch->GetEntry(index);
			} else { 
				printf("branch nfailjets_branch does not exist!\n");
				exit(1);
			}
			nfailjets_isLoaded = true;
		}
		return nfailjets_;
	}
	const int &V00_00_02::ak8GoodPFJets()
	{
		if (not ak8GoodPFJets_isLoaded) {
			if (ak8GoodPFJets_branch != 0) {
				ak8GoodPFJets_branch->GetEntry(index);
			} else { 
				printf("branch ak8GoodPFJets_branch does not exist!\n");
				exit(1);
			}
			ak8GoodPFJets_isLoaded = true;
		}
		return ak8GoodPFJets_;
	}
	const int &V00_00_02::ngoodbtags()
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
	const float &V00_00_02::ak4_HT()
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
	const float &V00_00_02::ak4_htssm()
	{
		if (not ak4_htssm_isLoaded) {
			if (ak4_htssm_branch != 0) {
				ak4_htssm_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htssm_branch does not exist!\n");
				exit(1);
			}
			ak4_htssm_isLoaded = true;
		}
		return ak4_htssm_;
	}
	const float &V00_00_02::ak4_htosm()
	{
		if (not ak4_htosm_isLoaded) {
			if (ak4_htosm_branch != 0) {
				ak4_htosm_branch->GetEntry(index);
			} else { 
				printf("branch ak4_htosm_branch does not exist!\n");
				exit(1);
			}
			ak4_htosm_isLoaded = true;
		}
		return ak4_htosm_;
	}
	const float &V00_00_02::ak4_htratiom()
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
	const vector<float> &V00_00_02::dphi_ak4pfjet_met()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::ak4pfjets_p4()
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
	const vector<float> &V00_00_02::ak4pfjets_pt()
	{
		if (not ak4pfjets_pt_isLoaded) {
			if (ak4pfjets_pt_branch != 0) {
				ak4pfjets_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_pt_isLoaded = true;
		}
		return *ak4pfjets_pt_;
	}
	const vector<float> &V00_00_02::ak4pfjets_eta()
	{
		if (not ak4pfjets_eta_isLoaded) {
			if (ak4pfjets_eta_branch != 0) {
				ak4pfjets_eta_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_eta_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_eta_isLoaded = true;
		}
		return *ak4pfjets_eta_;
	}
	const vector<float> &V00_00_02::ak4pfjets_phi()
	{
		if (not ak4pfjets_phi_isLoaded) {
			if (ak4pfjets_phi_branch != 0) {
				ak4pfjets_phi_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_phi_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_phi_isLoaded = true;
		}
		return *ak4pfjets_phi_;
	}
	const vector<float> &V00_00_02::ak4pfjets_mass()
	{
		if (not ak4pfjets_mass_isLoaded) {
			if (ak4pfjets_mass_branch != 0) {
				ak4pfjets_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mass_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mass_isLoaded = true;
		}
		return *ak4pfjets_mass_;
	}
	const vector<bool> &V00_00_02::ak4pfjets_passMEDbtag()
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
	const vector<float> &V00_00_02::ak4pfjets_qg_disc()
	{
		if (not ak4pfjets_qg_disc_isLoaded) {
			if (ak4pfjets_qg_disc_branch != 0) {
				ak4pfjets_qg_disc_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_qg_disc_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_qg_disc_isLoaded = true;
		}
		return *ak4pfjets_qg_disc_;
	}
	const vector<float> &V00_00_02::ak4pfjets_CSV()
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
	const vector<float> &V00_00_02::ak4pfjets_puid()
	{
		if (not ak4pfjets_puid_isLoaded) {
			if (ak4pfjets_puid_branch != 0) {
				ak4pfjets_puid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_puid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_puid_isLoaded = true;
		}
		return *ak4pfjets_puid_;
	}
	const vector<int> &V00_00_02::ak4pfjets_parton_flavor()
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
	const vector<bool> &V00_00_02::ak4pfjets_loose_puid()
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
	const vector<bool> &V00_00_02::ak4pfjets_loose_pfid()
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
	const vector<bool> &V00_00_02::ak4pfjets_medium_pfid()
	{
		if (not ak4pfjets_medium_pfid_isLoaded) {
			if (ak4pfjets_medium_pfid_branch != 0) {
				ak4pfjets_medium_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_medium_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_medium_pfid_isLoaded = true;
		}
		return *ak4pfjets_medium_pfid_;
	}
	const vector<bool> &V00_00_02::ak4pfjets_tight_pfid()
	{
		if (not ak4pfjets_tight_pfid_isLoaded) {
			if (ak4pfjets_tight_pfid_branch != 0) {
				ak4pfjets_tight_pfid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_tight_pfid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_tight_pfid_isLoaded = true;
		}
		return *ak4pfjets_tight_pfid_;
	}
	const vector<float> &V00_00_02::ak4pfjets_MEDbjet_pt()
	{
		if (not ak4pfjets_MEDbjet_pt_isLoaded) {
			if (ak4pfjets_MEDbjet_pt_branch != 0) {
				ak4pfjets_MEDbjet_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_MEDbjet_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_MEDbjet_pt_isLoaded = true;
		}
		return *ak4pfjets_MEDbjet_pt_;
	}
	const float &V00_00_02::ak4pfjets_leadMEDbjet_pt()
	{
		if (not ak4pfjets_leadMEDbjet_pt_isLoaded) {
			if (ak4pfjets_leadMEDbjet_pt_branch != 0) {
				ak4pfjets_leadMEDbjet_pt_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_leadMEDbjet_pt_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_leadMEDbjet_pt_isLoaded = true;
		}
		return ak4pfjets_leadMEDbjet_pt_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::ak4pfjets_leadMEDbjet_p4()
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
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::ak4pfjets_leadbtag_p4()
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
	const vector<float> &V00_00_02::ak4pfjets_chf()
	{
		if (not ak4pfjets_chf_isLoaded) {
			if (ak4pfjets_chf_branch != 0) {
				ak4pfjets_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_chf_isLoaded = true;
		}
		return *ak4pfjets_chf_;
	}
	const vector<float> &V00_00_02::ak4pfjets_nhf()
	{
		if (not ak4pfjets_nhf_isLoaded) {
			if (ak4pfjets_nhf_branch != 0) {
				ak4pfjets_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nhf_isLoaded = true;
		}
		return *ak4pfjets_nhf_;
	}
	const vector<float> &V00_00_02::ak4pfjets_cef()
	{
		if (not ak4pfjets_cef_isLoaded) {
			if (ak4pfjets_cef_branch != 0) {
				ak4pfjets_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_cef_isLoaded = true;
		}
		return *ak4pfjets_cef_;
	}
	const vector<float> &V00_00_02::ak4pfjets_nef()
	{
		if (not ak4pfjets_nef_isLoaded) {
			if (ak4pfjets_nef_branch != 0) {
				ak4pfjets_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nef_isLoaded = true;
		}
		return *ak4pfjets_nef_;
	}
	const vector<float> &V00_00_02::ak4pfjets_muf()
	{
		if (not ak4pfjets_muf_isLoaded) {
			if (ak4pfjets_muf_branch != 0) {
				ak4pfjets_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_muf_isLoaded = true;
		}
		return *ak4pfjets_muf_;
	}
	const vector<int> &V00_00_02::ak4pfjets_cm()
	{
		if (not ak4pfjets_cm_isLoaded) {
			if (ak4pfjets_cm_branch != 0) {
				ak4pfjets_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_cm_isLoaded = true;
		}
		return *ak4pfjets_cm_;
	}
	const vector<int> &V00_00_02::ak4pfjets_nm()
	{
		if (not ak4pfjets_nm_isLoaded) {
			if (ak4pfjets_nm_branch != 0) {
				ak4pfjets_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_nm_isLoaded = true;
		}
		return *ak4pfjets_nm_;
	}
	const vector<int> &V00_00_02::ak4pfjets_mc3dr()
	{
		if (not ak4pfjets_mc3dr_isLoaded) {
			if (ak4pfjets_mc3dr_branch != 0) {
				ak4pfjets_mc3dr_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3dr_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3dr_isLoaded = true;
		}
		return *ak4pfjets_mc3dr_;
	}
	const vector<int> &V00_00_02::ak4pfjets_mc3id()
	{
		if (not ak4pfjets_mc3id_isLoaded) {
			if (ak4pfjets_mc3id_branch != 0) {
				ak4pfjets_mc3id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3id_isLoaded = true;
		}
		return *ak4pfjets_mc3id_;
	}
	const vector<int> &V00_00_02::ak4pfjets_mc3idx()
	{
		if (not ak4pfjets_mc3idx_isLoaded) {
			if (ak4pfjets_mc3idx_branch != 0) {
				ak4pfjets_mc3idx_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mc3idx_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mc3idx_isLoaded = true;
		}
		return *ak4pfjets_mc3idx_;
	}
	const vector<int> &V00_00_02::ak4pfjets_mcmotherid()
	{
		if (not ak4pfjets_mcmotherid_isLoaded) {
			if (ak4pfjets_mcmotherid_branch != 0) {
				ak4pfjets_mcmotherid_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjets_mcmotherid_branch does not exist!\n");
				exit(1);
			}
			ak4pfjets_mcmotherid_isLoaded = true;
		}
		return *ak4pfjets_mcmotherid_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::ak4pfjet_overlep1_p4()
	{
		if (not ak4pfjet_overlep1_p4_isLoaded) {
			if (ak4pfjet_overlep1_p4_branch != 0) {
				ak4pfjet_overlep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_p4_isLoaded = true;
		}
		return *ak4pfjet_overlep1_p4_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_CSV()
	{
		if (not ak4pfjet_overlep1_CSV_isLoaded) {
			if (ak4pfjet_overlep1_CSV_branch != 0) {
				ak4pfjet_overlep1_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_CSV_isLoaded = true;
		}
		return ak4pfjet_overlep1_CSV_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_pu_id()
	{
		if (not ak4pfjet_overlep1_pu_id_isLoaded) {
			if (ak4pfjet_overlep1_pu_id_branch != 0) {
				ak4pfjet_overlep1_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_pu_id_isLoaded = true;
		}
		return ak4pfjet_overlep1_pu_id_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_chf()
	{
		if (not ak4pfjet_overlep1_chf_isLoaded) {
			if (ak4pfjet_overlep1_chf_branch != 0) {
				ak4pfjet_overlep1_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_chf_isLoaded = true;
		}
		return ak4pfjet_overlep1_chf_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_nhf()
	{
		if (not ak4pfjet_overlep1_nhf_isLoaded) {
			if (ak4pfjet_overlep1_nhf_branch != 0) {
				ak4pfjet_overlep1_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nhf_isLoaded = true;
		}
		return ak4pfjet_overlep1_nhf_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_cef()
	{
		if (not ak4pfjet_overlep1_cef_isLoaded) {
			if (ak4pfjet_overlep1_cef_branch != 0) {
				ak4pfjet_overlep1_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_cef_isLoaded = true;
		}
		return ak4pfjet_overlep1_cef_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_nef()
	{
		if (not ak4pfjet_overlep1_nef_isLoaded) {
			if (ak4pfjet_overlep1_nef_branch != 0) {
				ak4pfjet_overlep1_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nef_isLoaded = true;
		}
		return ak4pfjet_overlep1_nef_;
	}
	const float &V00_00_02::ak4pfjet_overlep1_muf()
	{
		if (not ak4pfjet_overlep1_muf_isLoaded) {
			if (ak4pfjet_overlep1_muf_branch != 0) {
				ak4pfjet_overlep1_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_muf_isLoaded = true;
		}
		return ak4pfjet_overlep1_muf_;
	}
	const int &V00_00_02::ak4pfjet_overlep1_cm()
	{
		if (not ak4pfjet_overlep1_cm_isLoaded) {
			if (ak4pfjet_overlep1_cm_branch != 0) {
				ak4pfjet_overlep1_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_cm_isLoaded = true;
		}
		return ak4pfjet_overlep1_cm_;
	}
	const int &V00_00_02::ak4pfjet_overlep1_nm()
	{
		if (not ak4pfjet_overlep1_nm_isLoaded) {
			if (ak4pfjet_overlep1_nm_branch != 0) {
				ak4pfjet_overlep1_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep1_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep1_nm_isLoaded = true;
		}
		return ak4pfjet_overlep1_nm_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &V00_00_02::ak4pfjet_overlep2_p4()
	{
		if (not ak4pfjet_overlep2_p4_isLoaded) {
			if (ak4pfjet_overlep2_p4_branch != 0) {
				ak4pfjet_overlep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_p4_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_p4_isLoaded = true;
		}
		return *ak4pfjet_overlep2_p4_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_CSV()
	{
		if (not ak4pfjet_overlep2_CSV_isLoaded) {
			if (ak4pfjet_overlep2_CSV_branch != 0) {
				ak4pfjet_overlep2_CSV_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_CSV_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_CSV_isLoaded = true;
		}
		return ak4pfjet_overlep2_CSV_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_pu_id()
	{
		if (not ak4pfjet_overlep2_pu_id_isLoaded) {
			if (ak4pfjet_overlep2_pu_id_branch != 0) {
				ak4pfjet_overlep2_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_pu_id_isLoaded = true;
		}
		return ak4pfjet_overlep2_pu_id_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_chf()
	{
		if (not ak4pfjet_overlep2_chf_isLoaded) {
			if (ak4pfjet_overlep2_chf_branch != 0) {
				ak4pfjet_overlep2_chf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_chf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_chf_isLoaded = true;
		}
		return ak4pfjet_overlep2_chf_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_nhf()
	{
		if (not ak4pfjet_overlep2_nhf_isLoaded) {
			if (ak4pfjet_overlep2_nhf_branch != 0) {
				ak4pfjet_overlep2_nhf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nhf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nhf_isLoaded = true;
		}
		return ak4pfjet_overlep2_nhf_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_cef()
	{
		if (not ak4pfjet_overlep2_cef_isLoaded) {
			if (ak4pfjet_overlep2_cef_branch != 0) {
				ak4pfjet_overlep2_cef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_cef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_cef_isLoaded = true;
		}
		return ak4pfjet_overlep2_cef_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_nef()
	{
		if (not ak4pfjet_overlep2_nef_isLoaded) {
			if (ak4pfjet_overlep2_nef_branch != 0) {
				ak4pfjet_overlep2_nef_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nef_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nef_isLoaded = true;
		}
		return ak4pfjet_overlep2_nef_;
	}
	const float &V00_00_02::ak4pfjet_overlep2_muf()
	{
		if (not ak4pfjet_overlep2_muf_isLoaded) {
			if (ak4pfjet_overlep2_muf_branch != 0) {
				ak4pfjet_overlep2_muf_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_muf_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_muf_isLoaded = true;
		}
		return ak4pfjet_overlep2_muf_;
	}
	const int &V00_00_02::ak4pfjet_overlep2_cm()
	{
		if (not ak4pfjet_overlep2_cm_isLoaded) {
			if (ak4pfjet_overlep2_cm_branch != 0) {
				ak4pfjet_overlep2_cm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_cm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_cm_isLoaded = true;
		}
		return ak4pfjet_overlep2_cm_;
	}
	const int &V00_00_02::ak4pfjet_overlep2_nm()
	{
		if (not ak4pfjet_overlep2_nm_isLoaded) {
			if (ak4pfjet_overlep2_nm_branch != 0) {
				ak4pfjet_overlep2_nm_branch->GetEntry(index);
			} else { 
				printf("branch ak4pfjet_overlep2_nm_branch does not exist!\n");
				exit(1);
			}
			ak4pfjet_overlep2_nm_isLoaded = true;
		}
		return ak4pfjet_overlep2_nm_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::ak8pfjets_p4()
	{
		if (not ak8pfjets_p4_isLoaded) {
			if (ak8pfjets_p4_branch != 0) {
				ak8pfjets_p4_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_p4_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_p4_isLoaded = true;
		}
		return *ak8pfjets_p4_;
	}
	const vector<float> &V00_00_02::ak8pfjets_tau1()
	{
		if (not ak8pfjets_tau1_isLoaded) {
			if (ak8pfjets_tau1_branch != 0) {
				ak8pfjets_tau1_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau1_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau1_isLoaded = true;
		}
		return *ak8pfjets_tau1_;
	}
	const vector<float> &V00_00_02::ak8pfjets_tau2()
	{
		if (not ak8pfjets_tau2_isLoaded) {
			if (ak8pfjets_tau2_branch != 0) {
				ak8pfjets_tau2_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau2_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau2_isLoaded = true;
		}
		return *ak8pfjets_tau2_;
	}
	const vector<float> &V00_00_02::ak8pfjets_tau3()
	{
		if (not ak8pfjets_tau3_isLoaded) {
			if (ak8pfjets_tau3_branch != 0) {
				ak8pfjets_tau3_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_tau3_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_tau3_isLoaded = true;
		}
		return *ak8pfjets_tau3_;
	}
	const vector<float> &V00_00_02::ak8pfjets_top_mass()
	{
		if (not ak8pfjets_top_mass_isLoaded) {
			if (ak8pfjets_top_mass_branch != 0) {
				ak8pfjets_top_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_top_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_top_mass_isLoaded = true;
		}
		return *ak8pfjets_top_mass_;
	}
	const vector<float> &V00_00_02::ak8pfjets_pruned_mass()
	{
		if (not ak8pfjets_pruned_mass_isLoaded) {
			if (ak8pfjets_pruned_mass_branch != 0) {
				ak8pfjets_pruned_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_pruned_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_pruned_mass_isLoaded = true;
		}
		return *ak8pfjets_pruned_mass_;
	}
	const vector<float> &V00_00_02::ak8pfjets_trimmed_mass()
	{
		if (not ak8pfjets_trimmed_mass_isLoaded) {
			if (ak8pfjets_trimmed_mass_branch != 0) {
				ak8pfjets_trimmed_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_trimmed_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_trimmed_mass_isLoaded = true;
		}
		return *ak8pfjets_trimmed_mass_;
	}
	const vector<float> &V00_00_02::ak8pfjets_filtered_mass()
	{
		if (not ak8pfjets_filtered_mass_isLoaded) {
			if (ak8pfjets_filtered_mass_branch != 0) {
				ak8pfjets_filtered_mass_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_filtered_mass_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_filtered_mass_isLoaded = true;
		}
		return *ak8pfjets_filtered_mass_;
	}
	const vector<float> &V00_00_02::ak8pfjets_pu_id()
	{
		if (not ak8pfjets_pu_id_isLoaded) {
			if (ak8pfjets_pu_id_branch != 0) {
				ak8pfjets_pu_id_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_pu_id_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_pu_id_isLoaded = true;
		}
		return *ak8pfjets_pu_id_;
	}
	const vector<int> &V00_00_02::ak8pfjets_parton_flavor()
	{
		if (not ak8pfjets_parton_flavor_isLoaded) {
			if (ak8pfjets_parton_flavor_branch != 0) {
				ak8pfjets_parton_flavor_branch->GetEntry(index);
			} else { 
				printf("branch ak8pfjets_parton_flavor_branch does not exist!\n");
				exit(1);
			}
			ak8pfjets_parton_flavor_isLoaded = true;
		}
		return *ak8pfjets_parton_flavor_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::ak4genjets_p4()
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
	const vector<TString> &V00_00_02::tau_IDnames()
	{
		if (not tau_IDnames_isLoaded) {
			if (tau_IDnames_branch != 0) {
				tau_IDnames_branch->GetEntry(index);
			} else { 
				printf("branch tau_IDnames_branch does not exist!\n");
				exit(1);
			}
			tau_IDnames_isLoaded = true;
		}
		return *tau_IDnames_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::tau_leadtrack_p4()
	{
		if (not tau_leadtrack_p4_isLoaded) {
			if (tau_leadtrack_p4_branch != 0) {
				tau_leadtrack_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_leadtrack_p4_branch does not exist!\n");
				exit(1);
			}
			tau_leadtrack_p4_isLoaded = true;
		}
		return *tau_leadtrack_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::tau_leadneutral_p4()
	{
		if (not tau_leadneutral_p4_isLoaded) {
			if (tau_leadneutral_p4_branch != 0) {
				tau_leadneutral_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_leadneutral_p4_branch does not exist!\n");
				exit(1);
			}
			tau_leadneutral_p4_isLoaded = true;
		}
		return *tau_leadneutral_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::tau_p4()
	{
		if (not tau_p4_isLoaded) {
			if (tau_p4_branch != 0) {
				tau_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_p4_branch does not exist!\n");
				exit(1);
			}
			tau_p4_isLoaded = true;
		}
		return *tau_p4_;
	}
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &V00_00_02::tau_isocand_p4()
	{
		if (not tau_isocand_p4_isLoaded) {
			if (tau_isocand_p4_branch != 0) {
				tau_isocand_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_isocand_p4_branch does not exist!\n");
				exit(1);
			}
			tau_isocand_p4_isLoaded = true;
		}
		return *tau_isocand_p4_;
	}
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &V00_00_02::tau_sigcand_p4()
	{
		if (not tau_sigcand_p4_isLoaded) {
			if (tau_sigcand_p4_branch != 0) {
				tau_sigcand_p4_branch->GetEntry(index);
			} else { 
				printf("branch tau_sigcand_p4_branch does not exist!\n");
				exit(1);
			}
			tau_sigcand_p4_isLoaded = true;
		}
		return *tau_sigcand_p4_;
	}
	const vector<float> &V00_00_02::tau_mass()
	{
		if (not tau_mass_isLoaded) {
			if (tau_mass_branch != 0) {
				tau_mass_branch->GetEntry(index);
			} else { 
				printf("branch tau_mass_branch does not exist!\n");
				exit(1);
			}
			tau_mass_isLoaded = true;
		}
		return *tau_mass_;
	}
	const vector<vector<float> > &V00_00_02::tau_ID()
	{
		if (not tau_ID_isLoaded) {
			if (tau_ID_branch != 0) {
				tau_ID_branch->GetEntry(index);
			} else { 
				printf("branch tau_ID_branch does not exist!\n");
				exit(1);
			}
			tau_ID_isLoaded = true;
		}
		return *tau_ID_;
	}
	const vector<float> &V00_00_02::tau_passID()
	{
		if (not tau_passID_isLoaded) {
			if (tau_passID_branch != 0) {
				tau_passID_branch->GetEntry(index);
			} else { 
				printf("branch tau_passID_branch does not exist!\n");
				exit(1);
			}
			tau_passID_isLoaded = true;
		}
		return *tau_passID_;
	}
	const vector<float> &V00_00_02::tau_charge()
	{
		if (not tau_charge_isLoaded) {
			if (tau_charge_branch != 0) {
				tau_charge_branch->GetEntry(index);
			} else { 
				printf("branch tau_charge_branch does not exist!\n");
				exit(1);
			}
			tau_charge_isLoaded = true;
		}
		return *tau_charge_;
	}
	const int &V00_00_02::ngoodtaus()
	{
		if (not ngoodtaus_isLoaded) {
			if (ngoodtaus_branch != 0) {
				ngoodtaus_branch->GetEntry(index);
			} else { 
				printf("branch ngoodtaus_branch does not exist!\n");
				exit(1);
			}
			ngoodtaus_isLoaded = true;
		}
		return ngoodtaus_;
	}
	const vector<float> &V00_00_02::tau_againstMuonTight()
	{
		if (not tau_againstMuonTight_isLoaded) {
			if (tau_againstMuonTight_branch != 0) {
				tau_againstMuonTight_branch->GetEntry(index);
			} else { 
				printf("branch tau_againstMuonTight_branch does not exist!\n");
				exit(1);
			}
			tau_againstMuonTight_isLoaded = true;
		}
		return *tau_againstMuonTight_;
	}
	const vector<float> &V00_00_02::tau_againstElectronLoose()
	{
		if (not tau_againstElectronLoose_isLoaded) {
			if (tau_againstElectronLoose_branch != 0) {
				tau_againstElectronLoose_branch->GetEntry(index);
			} else { 
				printf("branch tau_againstElectronLoose_branch does not exist!\n");
				exit(1);
			}
			tau_againstElectronLoose_isLoaded = true;
		}
		return *tau_againstElectronLoose_;
	}
	const vector<bool> &V00_00_02::tau_isVetoTau()
	{
		if (not tau_isVetoTau_isLoaded) {
			if (tau_isVetoTau_branch != 0) {
				tau_isVetoTau_branch->GetEntry(index);
			} else { 
				printf("branch tau_isVetoTau_branch does not exist!\n");
				exit(1);
			}
			tau_isVetoTau_isLoaded = true;
		}
		return *tau_isVetoTau_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &V00_00_02::isoTracks_p4()
	{
		if (not isoTracks_p4_isLoaded) {
			if (isoTracks_p4_branch != 0) {
				isoTracks_p4_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_p4_branch does not exist!\n");
				exit(1);
			}
			isoTracks_p4_isLoaded = true;
		}
		return *isoTracks_p4_;
	}
	const vector<int> &V00_00_02::isoTracks_charge()
	{
		if (not isoTracks_charge_isLoaded) {
			if (isoTracks_charge_branch != 0) {
				isoTracks_charge_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_charge_branch does not exist!\n");
				exit(1);
			}
			isoTracks_charge_isLoaded = true;
		}
		return *isoTracks_charge_;
	}
	const vector<float> &V00_00_02::isoTracks_absIso()
	{
		if (not isoTracks_absIso_isLoaded) {
			if (isoTracks_absIso_branch != 0) {
				isoTracks_absIso_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_absIso_branch does not exist!\n");
				exit(1);
			}
			isoTracks_absIso_isLoaded = true;
		}
		return *isoTracks_absIso_;
	}
	const vector<float> &V00_00_02::isoTracks_dz()
	{
		if (not isoTracks_dz_isLoaded) {
			if (isoTracks_dz_branch != 0) {
				isoTracks_dz_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_dz_branch does not exist!\n");
				exit(1);
			}
			isoTracks_dz_isLoaded = true;
		}
		return *isoTracks_dz_;
	}
	const vector<int> &V00_00_02::isoTracks_pdgId()
	{
		if (not isoTracks_pdgId_isLoaded) {
			if (isoTracks_pdgId_branch != 0) {
				isoTracks_pdgId_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_pdgId_branch does not exist!\n");
				exit(1);
			}
			isoTracks_pdgId_isLoaded = true;
		}
		return *isoTracks_pdgId_;
	}
	const vector<int> &V00_00_02::isoTracks_selectedidx()
	{
		if (not isoTracks_selectedidx_isLoaded) {
			if (isoTracks_selectedidx_branch != 0) {
				isoTracks_selectedidx_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_selectedidx_branch does not exist!\n");
				exit(1);
			}
			isoTracks_selectedidx_isLoaded = true;
		}
		return *isoTracks_selectedidx_;
	}
	const int &V00_00_02::isoTracks_nselected()
	{
		if (not isoTracks_nselected_isLoaded) {
			if (isoTracks_nselected_branch != 0) {
				isoTracks_nselected_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_nselected_branch does not exist!\n");
				exit(1);
			}
			isoTracks_nselected_isLoaded = true;
		}
		return isoTracks_nselected_;
	}
	const vector<bool> &V00_00_02::isoTracks_isVetoTrack()
	{
		if (not isoTracks_isVetoTrack_isLoaded) {
			if (isoTracks_isVetoTrack_branch != 0) {
				isoTracks_isVetoTrack_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_;
	}
	const vector<bool> &V00_00_02::isoTracks_isVetoTrack_v2()
	{
		if (not isoTracks_isVetoTrack_v2_isLoaded) {
			if (isoTracks_isVetoTrack_v2_branch != 0) {
				isoTracks_isVetoTrack_v2_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_v2_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_v2_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_v2_;
	}
	const vector<bool> &V00_00_02::isoTracks_isVetoTrack_v3()
	{
		if (not isoTracks_isVetoTrack_v3_isLoaded) {
			if (isoTracks_isVetoTrack_v3_branch != 0) {
				isoTracks_isVetoTrack_v3_branch->GetEntry(index);
			} else { 
				printf("branch isoTracks_isVetoTrack_v3_branch does not exist!\n");
				exit(1);
			}
			isoTracks_isVetoTrack_v3_isLoaded = true;
		}
		return *isoTracks_isVetoTrack_v3_;
	}

  void V00_00_02::progress( int nEventsTotal, int nEventsChain ){
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
  
namespace V00_00_02_np {
	const unsigned int &run() { return v00_00_02.run(); }
	const unsigned int &ls() { return v00_00_02.ls(); }
	const unsigned int &evt() { return v00_00_02.evt(); }
	const int &nvtxs() { return v00_00_02.nvtxs(); }
	const int &firstGoodVtxIdx() { return v00_00_02.firstGoodVtxIdx(); }
	const int &firstVtx_isfake() { return v00_00_02.firstVtx_isfake(); }
	const float &firstVtx_ndof() { return v00_00_02.firstVtx_ndof(); }
	const float &firstVtx_posRho() { return v00_00_02.firstVtx_posRho(); }
	const float &firstVtx_posZ() { return v00_00_02.firstVtx_posZ(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &firstVtx_posp4() { return v00_00_02.firstVtx_posp4(); }
	const int &pu_nvtxs() { return v00_00_02.pu_nvtxs(); }
	const float &pfmet() { return v00_00_02.pfmet(); }
	const float &pfmet_phi() { return v00_00_02.pfmet_phi(); }
	const float &calomet() { return v00_00_02.calomet(); }
	const float &calomet_phi() { return v00_00_02.calomet_phi(); }
	const float &filt_cscbeamhalo() { return v00_00_02.filt_cscbeamhalo(); }
	const float &filt_ecallaser() { return v00_00_02.filt_ecallaser(); }
	const float &filt_ecaltp() { return v00_00_02.filt_ecaltp(); }
	const float &filt_eebadsc() { return v00_00_02.filt_eebadsc(); }
	const float &filt_goodvtx() { return v00_00_02.filt_goodvtx(); }
	const float &filt_badevents() { return v00_00_02.filt_badevents(); }
	const float &filt_hbhenoise() { return v00_00_02.filt_hbhenoise(); }
	const float &filt_hcallaser() { return v00_00_02.filt_hcallaser(); }
	const float &filt_met() { return v00_00_02.filt_met(); }
	const float &filt_trkfail() { return v00_00_02.filt_trkfail(); }
	const float &filt_trkPOG() { return v00_00_02.filt_trkPOG(); }
	const float &filt_trkPOG_tmc() { return v00_00_02.filt_trkPOG_tmc(); }
	const float &filt_trkPOG_tms() { return v00_00_02.filt_trkPOG_tms(); }
	const float &filt_eff() { return v00_00_02.filt_eff(); }
	const float &scale1fb() { return v00_00_02.scale1fb(); }
	const float &xsec() { return v00_00_02.xsec(); }
	const float &kfactor() { return v00_00_02.kfactor(); }
	const float &pu_ntrue() { return v00_00_02.pu_ntrue(); }
	const int &ngoodleps() { return v00_00_02.ngoodleps(); }
	const int &nlooseleps() { return v00_00_02.nlooseleps(); }
	const int &nvetoleps() { return v00_00_02.nvetoleps(); }
	const bool &is_data() { return v00_00_02.is_data(); }
	const string &dataset() { return v00_00_02.dataset(); }
	const string &filename() { return v00_00_02.filename(); }
	const string &cms3tag() { return v00_00_02.cms3tag(); }
	const unsigned int &nEvents() { return v00_00_02.nEvents(); }
	const unsigned int &nEvents_goodvtx() { return v00_00_02.nEvents_goodvtx(); }
	const unsigned int &nEvents_MET30() { return v00_00_02.nEvents_MET30(); }
	const unsigned int &nEvents_1goodlep() { return v00_00_02.nEvents_1goodlep(); }
	const unsigned int &nEvents_2goodjets() { return v00_00_02.nEvents_2goodjets(); }
	const int &genlepsfromtop() { return v00_00_02.genlepsfromtop(); }
	const float &MT2W() { return v00_00_02.MT2W(); }
	const float &MT2W_lep2() { return v00_00_02.MT2W_lep2(); }
	const float &mindphi_met_j1_j2() { return v00_00_02.mindphi_met_j1_j2(); }
	const float &mt_met_lep() { return v00_00_02.mt_met_lep(); }
	const float &mt_met_lep2() { return v00_00_02.mt_met_lep2(); }
	const float &dR_lep_leadb() { return v00_00_02.dR_lep_leadb(); }
	const float &dR_lep2_leadb() { return v00_00_02.dR_lep2_leadb(); }
	const float &hadronic_top_chi2() { return v00_00_02.hadronic_top_chi2(); }
	const float &dphi_Wlep() { return v00_00_02.dphi_Wlep(); }
	const float &MET_over_sqrtHT() { return v00_00_02.MET_over_sqrtHT(); }
	const float &ak4pfjets_rho() { return v00_00_02.ak4pfjets_rho(); }
	const vector<string> &genweightsID() { return v00_00_02.genweightsID(); }
	const vector<float> &genweights() { return v00_00_02.genweights(); }
	const vector<string> &sparms_names() { return v00_00_02.sparms_names(); }
	const float &sparms_filterEfficiency() { return v00_00_02.sparms_filterEfficiency(); }
	const float &sparms_pdfScale() { return v00_00_02.sparms_pdfScale(); }
	const float &sparms_pdfWeight1() { return v00_00_02.sparms_pdfWeight1(); }
	const float &sparms_pdfWeight2() { return v00_00_02.sparms_pdfWeight2(); }
	const float &sparms_weight() { return v00_00_02.sparms_weight(); }
	const float &sparms_xsec() { return v00_00_02.sparms_xsec(); }
	const vector<float> &sparms_values() { return v00_00_02.sparms_values(); }
	const int &sparms_subProcessId() { return v00_00_02.sparms_subProcessId(); }
	const float &mass_lsp() { return v00_00_02.mass_lsp(); }
	const float &mass_chargino() { return v00_00_02.mass_chargino(); }
	const float &mass_stop() { return v00_00_02.mass_stop(); }
	const float &genmet() { return v00_00_02.genmet(); }
	const float &genmet_phi() { return v00_00_02.genmet_phi(); }
	const bool &PassTrackVeto() { return v00_00_02.PassTrackVeto(); }
	const bool &PassTrackVeto_v2() { return v00_00_02.PassTrackVeto_v2(); }
	const bool &PassTrackVeto_v3() { return v00_00_02.PassTrackVeto_v3(); }
	const bool &PassTauVeto() { return v00_00_02.PassTauVeto(); }
	const float &EA_all_rho() { return v00_00_02.EA_all_rho(); }
	const float &EA_allcalo_rho() { return v00_00_02.EA_allcalo_rho(); }
	const float &EA_centralcalo_rho() { return v00_00_02.EA_centralcalo_rho(); }
	const float &EA_centralchargedpileup_rho() { return v00_00_02.EA_centralchargedpileup_rho(); }
	const float &EA_centralneutral_rho() { return v00_00_02.EA_centralneutral_rho(); }
	const float &topness() { return v00_00_02.topness(); }
	const float &topness_lep2() { return v00_00_02.topness_lep2(); }
	const float &topnessMod() { return v00_00_02.topnessMod(); }
	const float &topnessMod_lep2() { return v00_00_02.topnessMod_lep2(); }
	const float &MT2_lb_b() { return v00_00_02.MT2_lb_b(); }
	const float &MT2_lb_b_lep2() { return v00_00_02.MT2_lb_b_lep2(); }
	const float &MT2_lb_b_mass() { return v00_00_02.MT2_lb_b_mass(); }
	const float &MT2_lb_b_mass_lep2() { return v00_00_02.MT2_lb_b_mass_lep2(); }
	const float &MT2_lb_bqq() { return v00_00_02.MT2_lb_bqq(); }
	const float &MT2_lb_bqq_lep2() { return v00_00_02.MT2_lb_bqq_lep2(); }
	const float &MT2_lb_bqq_mass() { return v00_00_02.MT2_lb_bqq_mass(); }
	const float &MT2_lb_bqq_mass_lep2() { return v00_00_02.MT2_lb_bqq_mass_lep2(); }
	const float &Mlb_closestb() { return v00_00_02.Mlb_closestb(); }
	const float &Mlb_lead_bdiscr() { return v00_00_02.Mlb_lead_bdiscr(); }
	const float &Mlb_closestb_lep2() { return v00_00_02.Mlb_closestb_lep2(); }
	const float &Mlb_lead_bdiscr_lep2() { return v00_00_02.Mlb_lead_bdiscr_lep2(); }
	const float &Mjjj() { return v00_00_02.Mjjj(); }
	const float &Mjjj_lep2() { return v00_00_02.Mjjj_lep2(); }
	const int &HLT_SingleEl() { return v00_00_02.HLT_SingleEl(); }
	const int &HLT_SingleMu() { return v00_00_02.HLT_SingleMu(); }
	const int &HLT_MET170() { return v00_00_02.HLT_MET170(); }
	const int &HLT_MET120Btag() { return v00_00_02.HLT_MET120Btag(); }
	const int &HLT_MET120Mu5() { return v00_00_02.HLT_MET120Mu5(); }
	const int &HLT_HT350MET120() { return v00_00_02.HLT_HT350MET120(); }
	const int &HLT_DiEl() { return v00_00_02.HLT_DiEl(); }
	const int &HLT_DiEl_17_12() { return v00_00_02.HLT_DiEl_17_12(); }
	const int &HLT_DiMu() { return v00_00_02.HLT_DiMu(); }
	const int &HLT_Mu8El17() { return v00_00_02.HLT_Mu8El17(); }
	const int &HLT_Mu8El23() { return v00_00_02.HLT_Mu8El23(); }
	const int &HLT_Mu17El12() { return v00_00_02.HLT_Mu17El12(); }
	const int &HLT_Mu23El12() { return v00_00_02.HLT_Mu23El12(); }
	const int &HLT_SingleEl23() { return v00_00_02.HLT_SingleEl23(); }
	const int &HLT_SingleEl27() { return v00_00_02.HLT_SingleEl27(); }
	const int &HLT_SingleEl27Tight() { return v00_00_02.HLT_SingleEl27Tight(); }
	const int &HLT_SingleElTight() { return v00_00_02.HLT_SingleElTight(); }
	const int &HLT_SingleElHT200() { return v00_00_02.HLT_SingleElHT200(); }
	const int &HLT_SingleMuNoEta() { return v00_00_02.HLT_SingleMuNoEta(); }
	const int &HLT_SingleMuNoIso() { return v00_00_02.HLT_SingleMuNoIso(); }
	const int &HLT_SingleMuNoIsoNoEta() { return v00_00_02.HLT_SingleMuNoIsoNoEta(); }
	const int &HLT_Mu6HT200MET100() { return v00_00_02.HLT_Mu6HT200MET100(); }
	const int &HLT_HT350MET100() { return v00_00_02.HLT_HT350MET100(); }
	const int &HLT_SingleMu17() { return v00_00_02.HLT_SingleMu17(); }
	const int &HLT_SingleMu20() { return v00_00_02.HLT_SingleMu20(); }
	const int &HLT_SingleMu24() { return v00_00_02.HLT_SingleMu24(); }
	const int &HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight() { return v00_00_02.HLT_MonoCentPFJet80_METNoMu90_MHTNoMu90_IDTight(); }
	const int &HLT_MET90_MHT90_IDTight() { return v00_00_02.HLT_MET90_MHT90_IDTight(); }
	const int &HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight() { return v00_00_02.HLT_METNoMu90_NoiseCleaned_MHTNoMu90_IDTight(); }
	const int &HLT_Photon90_CaloIdL_PFHT500() { return v00_00_02.HLT_Photon90_CaloIdL_PFHT500(); }
	const int &HLT_Photon165_R9Id90_HE10_IsoM() { return v00_00_02.HLT_Photon165_R9Id90_HE10_IsoM(); }
	const int &HLT_Photon175() { return v00_00_02.HLT_Photon175(); }
	const int &HLT_Photon165_HE10() { return v00_00_02.HLT_Photon165_HE10(); }
	const float &pu_weight() { return v00_00_02.pu_weight(); }
	const float &lep_sf() { return v00_00_02.lep_sf(); }
	const float &btag_sf() { return v00_00_02.btag_sf(); }
	const float &HLT_SingleEl_eff() { return v00_00_02.HLT_SingleEl_eff(); }
	const float &HLT_SingleMu_eff() { return v00_00_02.HLT_SingleMu_eff(); }
	const bool &lep1_is_mu() { return v00_00_02.lep1_is_mu(); }
	const bool &lep1_is_el() { return v00_00_02.lep1_is_el(); }
	const int &lep1_charge() { return v00_00_02.lep1_charge(); }
	const int &lep1_pdgid() { return v00_00_02.lep1_pdgid(); }
	const int &lep1_type() { return v00_00_02.lep1_type(); }
	const int &lep1_production_type() { return v00_00_02.lep1_production_type(); }
	const float &lep1_d0() { return v00_00_02.lep1_d0(); }
	const float &lep1_d0err() { return v00_00_02.lep1_d0err(); }
	const float &lep1_dz() { return v00_00_02.lep1_dz(); }
	const float &lep1_dzerr() { return v00_00_02.lep1_dzerr(); }
	const float &lep1_sigmaIEtaEta_fill5x5() { return v00_00_02.lep1_sigmaIEtaEta_fill5x5(); }
	const float &lep1_dEtaIn() { return v00_00_02.lep1_dEtaIn(); }
	const float &lep1_dPhiIn() { return v00_00_02.lep1_dPhiIn(); }
	const float &lep1_hOverE() { return v00_00_02.lep1_hOverE(); }
	const float &lep1_ooEmooP() { return v00_00_02.lep1_ooEmooP(); }
	const int &lep1_expectedMissingInnerHits() { return v00_00_02.lep1_expectedMissingInnerHits(); }
	const bool &lep1_conversionVeto() { return v00_00_02.lep1_conversionVeto(); }
	const float &lep1_etaSC() { return v00_00_02.lep1_etaSC(); }
	const float &lep1_ChiSqr() { return v00_00_02.lep1_ChiSqr(); }
	const float &lep1_chiso() { return v00_00_02.lep1_chiso(); }
	const float &lep1_nhiso() { return v00_00_02.lep1_nhiso(); }
	const float &lep1_emiso() { return v00_00_02.lep1_emiso(); }
	const float &lep1_deltaBeta() { return v00_00_02.lep1_deltaBeta(); }
	const float &lep1_relIso03DB() { return v00_00_02.lep1_relIso03DB(); }
	const float &lep1_relIso03EA() { return v00_00_02.lep1_relIso03EA(); }
	const float &lep1_relIso04DB() { return v00_00_02.lep1_relIso04DB(); }
	const float &lep1_miniRelIsoDB() { return v00_00_02.lep1_miniRelIsoDB(); }
	const float &lep1_miniRelIsoEA() { return v00_00_02.lep1_miniRelIsoEA(); }
	const float &lep1_MiniIso() { return v00_00_02.lep1_MiniIso(); }
	const int &lep1_mcid() { return v00_00_02.lep1_mcid(); }
	const int &lep1_mcstatus() { return v00_00_02.lep1_mcstatus(); }
	const int &lep1_mc3dr() { return v00_00_02.lep1_mc3dr(); }
	const int &lep1_mc3id() { return v00_00_02.lep1_mc3id(); }
	const int &lep1_mc3idx() { return v00_00_02.lep1_mc3idx(); }
	const int &lep1_mc3motherid() { return v00_00_02.lep1_mc3motherid(); }
	const int &lep1_mc3motheridx() { return v00_00_02.lep1_mc3motheridx(); }
	const bool &lep1_is_eleid_loose() { return v00_00_02.lep1_is_eleid_loose(); }
	const bool &lep1_is_eleid_medium() { return v00_00_02.lep1_is_eleid_medium(); }
	const bool &lep1_is_eleid_tight() { return v00_00_02.lep1_is_eleid_tight(); }
	const bool &lep1_is_phys14_loose_noIso() { return v00_00_02.lep1_is_phys14_loose_noIso(); }
	const bool &lep1_is_phys14_medium_noIso() { return v00_00_02.lep1_is_phys14_medium_noIso(); }
	const bool &lep1_is_phys14_tight_noIso() { return v00_00_02.lep1_is_phys14_tight_noIso(); }
	const float &lep1_eoverpin() { return v00_00_02.lep1_eoverpin(); }
	const bool &lep1_is_muoid_loose() { return v00_00_02.lep1_is_muoid_loose(); }
	const bool &lep1_is_muoid_medium() { return v00_00_02.lep1_is_muoid_medium(); }
	const bool &lep1_is_muoid_tight() { return v00_00_02.lep1_is_muoid_tight(); }
	const float &lep1_ip3d() { return v00_00_02.lep1_ip3d(); }
	const float &lep1_ip3derr() { return v00_00_02.lep1_ip3derr(); }
	const bool &lep1_is_pfmu() { return v00_00_02.lep1_is_pfmu(); }
	const bool &lep1_passMediumID() { return v00_00_02.lep1_passMediumID(); }
	const bool &lep1_passVeto() { return v00_00_02.lep1_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return v00_00_02.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_mcp4() { return v00_00_02.lep1_mcp4(); }
	const float &lep1_pt() { return v00_00_02.lep1_pt(); }
	const float &lep1_eta() { return v00_00_02.lep1_eta(); }
	const float &lep1_phi() { return v00_00_02.lep1_phi(); }
	const float &lep1_mass() { return v00_00_02.lep1_mass(); }
	const bool &lep2_is_mu() { return v00_00_02.lep2_is_mu(); }
	const bool &lep2_is_el() { return v00_00_02.lep2_is_el(); }
	const int &lep2_charge() { return v00_00_02.lep2_charge(); }
	const int &lep2_pdgid() { return v00_00_02.lep2_pdgid(); }
	const int &lep2_type() { return v00_00_02.lep2_type(); }
	const int &lep2_production_type() { return v00_00_02.lep2_production_type(); }
	const float &lep2_d0() { return v00_00_02.lep2_d0(); }
	const float &lep2_d0err() { return v00_00_02.lep2_d0err(); }
	const float &lep2_dz() { return v00_00_02.lep2_dz(); }
	const float &lep2_dzerr() { return v00_00_02.lep2_dzerr(); }
	const float &lep2_sigmaIEtaEta_fill5x5() { return v00_00_02.lep2_sigmaIEtaEta_fill5x5(); }
	const float &lep2_dEtaIn() { return v00_00_02.lep2_dEtaIn(); }
	const float &lep2_dPhiIn() { return v00_00_02.lep2_dPhiIn(); }
	const float &lep2_hOverE() { return v00_00_02.lep2_hOverE(); }
	const float &lep2_ooEmooP() { return v00_00_02.lep2_ooEmooP(); }
	const int &lep2_expectedMissingInnerHits() { return v00_00_02.lep2_expectedMissingInnerHits(); }
	const bool &lep2_conversionVeto() { return v00_00_02.lep2_conversionVeto(); }
	const float &lep2_etaSC() { return v00_00_02.lep2_etaSC(); }
	const float &lep2_ChiSqr() { return v00_00_02.lep2_ChiSqr(); }
	const float &lep2_chiso() { return v00_00_02.lep2_chiso(); }
	const float &lep2_nhiso() { return v00_00_02.lep2_nhiso(); }
	const float &lep2_emiso() { return v00_00_02.lep2_emiso(); }
	const float &lep2_deltaBeta() { return v00_00_02.lep2_deltaBeta(); }
	const float &lep2_relIso03DB() { return v00_00_02.lep2_relIso03DB(); }
	const float &lep2_relIso03EA() { return v00_00_02.lep2_relIso03EA(); }
	const float &lep2_relIso04DB() { return v00_00_02.lep2_relIso04DB(); }
	const float &lep2_miniRelIsoDB() { return v00_00_02.lep2_miniRelIsoDB(); }
	const float &lep2_miniRelIsoEA() { return v00_00_02.lep2_miniRelIsoEA(); }
	const float &lep2_MiniIso() { return v00_00_02.lep2_MiniIso(); }
	const int &lep2_mcid() { return v00_00_02.lep2_mcid(); }
	const int &lep2_mcstatus() { return v00_00_02.lep2_mcstatus(); }
	const int &lep2_mc3dr() { return v00_00_02.lep2_mc3dr(); }
	const int &lep2_mc3id() { return v00_00_02.lep2_mc3id(); }
	const int &lep2_mc3idx() { return v00_00_02.lep2_mc3idx(); }
	const int &lep2_mc3motherid() { return v00_00_02.lep2_mc3motherid(); }
	const int &lep2_mc3motheridx() { return v00_00_02.lep2_mc3motheridx(); }
	const bool &lep2_is_eleid_loose() { return v00_00_02.lep2_is_eleid_loose(); }
	const bool &lep2_is_eleid_medium() { return v00_00_02.lep2_is_eleid_medium(); }
	const bool &lep2_is_eleid_tight() { return v00_00_02.lep2_is_eleid_tight(); }
	const bool &lep2_is_phys14_loose_noIso() { return v00_00_02.lep2_is_phys14_loose_noIso(); }
	const bool &lep2_is_phys14_medium_noIso() { return v00_00_02.lep2_is_phys14_medium_noIso(); }
	const bool &lep2_is_phys14_tight_noIso() { return v00_00_02.lep2_is_phys14_tight_noIso(); }
	const float &lep2_eoverpin() { return v00_00_02.lep2_eoverpin(); }
	const bool &lep2_is_muoid_loose() { return v00_00_02.lep2_is_muoid_loose(); }
	const bool &lep2_is_muoid_medium() { return v00_00_02.lep2_is_muoid_medium(); }
	const bool &lep2_is_muoid_tight() { return v00_00_02.lep2_is_muoid_tight(); }
	const float &lep2_ip3d() { return v00_00_02.lep2_ip3d(); }
	const float &lep2_ip3derr() { return v00_00_02.lep2_ip3derr(); }
	const bool &lep2_is_pfmu() { return v00_00_02.lep2_is_pfmu(); }
	const bool &lep2_passMediumID() { return v00_00_02.lep2_passMediumID(); }
	const bool &lep2_passVeto() { return v00_00_02.lep2_passVeto(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return v00_00_02.lep2_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_mcp4() { return v00_00_02.lep2_mcp4(); }
	const float &lep2_pt() { return v00_00_02.lep2_pt(); }
	const float &lep2_eta() { return v00_00_02.lep2_eta(); }
	const float &lep2_phi() { return v00_00_02.lep2_phi(); }
	const float &lep2_mass() { return v00_00_02.lep2_mass(); }
	const int &nGoodGenJets() { return v00_00_02.nGoodGenJets(); }
	const int &ngoodjets() { return v00_00_02.ngoodjets(); }
	const int &nfailjets() { return v00_00_02.nfailjets(); }
	const int &ak8GoodPFJets() { return v00_00_02.ak8GoodPFJets(); }
	const int &ngoodbtags() { return v00_00_02.ngoodbtags(); }
	const float &ak4_HT() { return v00_00_02.ak4_HT(); }
	const float &ak4_htssm() { return v00_00_02.ak4_htssm(); }
	const float &ak4_htosm() { return v00_00_02.ak4_htosm(); }
	const float &ak4_htratiom() { return v00_00_02.ak4_htratiom(); }
	const vector<float> &dphi_ak4pfjet_met() { return v00_00_02.dphi_ak4pfjet_met(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4pfjets_p4() { return v00_00_02.ak4pfjets_p4(); }
	const vector<float> &ak4pfjets_pt() { return v00_00_02.ak4pfjets_pt(); }
	const vector<float> &ak4pfjets_eta() { return v00_00_02.ak4pfjets_eta(); }
	const vector<float> &ak4pfjets_phi() { return v00_00_02.ak4pfjets_phi(); }
	const vector<float> &ak4pfjets_mass() { return v00_00_02.ak4pfjets_mass(); }
	const vector<bool> &ak4pfjets_passMEDbtag() { return v00_00_02.ak4pfjets_passMEDbtag(); }
	const vector<float> &ak4pfjets_qg_disc() { return v00_00_02.ak4pfjets_qg_disc(); }
	const vector<float> &ak4pfjets_CSV() { return v00_00_02.ak4pfjets_CSV(); }
	const vector<float> &ak4pfjets_puid() { return v00_00_02.ak4pfjets_puid(); }
	const vector<int> &ak4pfjets_parton_flavor() { return v00_00_02.ak4pfjets_parton_flavor(); }
	const vector<bool> &ak4pfjets_loose_puid() { return v00_00_02.ak4pfjets_loose_puid(); }
	const vector<bool> &ak4pfjets_loose_pfid() { return v00_00_02.ak4pfjets_loose_pfid(); }
	const vector<bool> &ak4pfjets_medium_pfid() { return v00_00_02.ak4pfjets_medium_pfid(); }
	const vector<bool> &ak4pfjets_tight_pfid() { return v00_00_02.ak4pfjets_tight_pfid(); }
	const vector<float> &ak4pfjets_MEDbjet_pt() { return v00_00_02.ak4pfjets_MEDbjet_pt(); }
	const float &ak4pfjets_leadMEDbjet_pt() { return v00_00_02.ak4pfjets_leadMEDbjet_pt(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadMEDbjet_p4() { return v00_00_02.ak4pfjets_leadMEDbjet_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjets_leadbtag_p4() { return v00_00_02.ak4pfjets_leadbtag_p4(); }
	const vector<float> &ak4pfjets_chf() { return v00_00_02.ak4pfjets_chf(); }
	const vector<float> &ak4pfjets_nhf() { return v00_00_02.ak4pfjets_nhf(); }
	const vector<float> &ak4pfjets_cef() { return v00_00_02.ak4pfjets_cef(); }
	const vector<float> &ak4pfjets_nef() { return v00_00_02.ak4pfjets_nef(); }
	const vector<float> &ak4pfjets_muf() { return v00_00_02.ak4pfjets_muf(); }
	const vector<int> &ak4pfjets_cm() { return v00_00_02.ak4pfjets_cm(); }
	const vector<int> &ak4pfjets_nm() { return v00_00_02.ak4pfjets_nm(); }
	const vector<int> &ak4pfjets_mc3dr() { return v00_00_02.ak4pfjets_mc3dr(); }
	const vector<int> &ak4pfjets_mc3id() { return v00_00_02.ak4pfjets_mc3id(); }
	const vector<int> &ak4pfjets_mc3idx() { return v00_00_02.ak4pfjets_mc3idx(); }
	const vector<int> &ak4pfjets_mcmotherid() { return v00_00_02.ak4pfjets_mcmotherid(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep1_p4() { return v00_00_02.ak4pfjet_overlep1_p4(); }
	const float &ak4pfjet_overlep1_CSV() { return v00_00_02.ak4pfjet_overlep1_CSV(); }
	const float &ak4pfjet_overlep1_pu_id() { return v00_00_02.ak4pfjet_overlep1_pu_id(); }
	const float &ak4pfjet_overlep1_chf() { return v00_00_02.ak4pfjet_overlep1_chf(); }
	const float &ak4pfjet_overlep1_nhf() { return v00_00_02.ak4pfjet_overlep1_nhf(); }
	const float &ak4pfjet_overlep1_cef() { return v00_00_02.ak4pfjet_overlep1_cef(); }
	const float &ak4pfjet_overlep1_nef() { return v00_00_02.ak4pfjet_overlep1_nef(); }
	const float &ak4pfjet_overlep1_muf() { return v00_00_02.ak4pfjet_overlep1_muf(); }
	const int &ak4pfjet_overlep1_cm() { return v00_00_02.ak4pfjet_overlep1_cm(); }
	const int &ak4pfjet_overlep1_nm() { return v00_00_02.ak4pfjet_overlep1_nm(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &ak4pfjet_overlep2_p4() { return v00_00_02.ak4pfjet_overlep2_p4(); }
	const float &ak4pfjet_overlep2_CSV() { return v00_00_02.ak4pfjet_overlep2_CSV(); }
	const float &ak4pfjet_overlep2_pu_id() { return v00_00_02.ak4pfjet_overlep2_pu_id(); }
	const float &ak4pfjet_overlep2_chf() { return v00_00_02.ak4pfjet_overlep2_chf(); }
	const float &ak4pfjet_overlep2_nhf() { return v00_00_02.ak4pfjet_overlep2_nhf(); }
	const float &ak4pfjet_overlep2_cef() { return v00_00_02.ak4pfjet_overlep2_cef(); }
	const float &ak4pfjet_overlep2_nef() { return v00_00_02.ak4pfjet_overlep2_nef(); }
	const float &ak4pfjet_overlep2_muf() { return v00_00_02.ak4pfjet_overlep2_muf(); }
	const int &ak4pfjet_overlep2_cm() { return v00_00_02.ak4pfjet_overlep2_cm(); }
	const int &ak4pfjet_overlep2_nm() { return v00_00_02.ak4pfjet_overlep2_nm(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8pfjets_p4() { return v00_00_02.ak8pfjets_p4(); }
	const vector<float> &ak8pfjets_tau1() { return v00_00_02.ak8pfjets_tau1(); }
	const vector<float> &ak8pfjets_tau2() { return v00_00_02.ak8pfjets_tau2(); }
	const vector<float> &ak8pfjets_tau3() { return v00_00_02.ak8pfjets_tau3(); }
	const vector<float> &ak8pfjets_top_mass() { return v00_00_02.ak8pfjets_top_mass(); }
	const vector<float> &ak8pfjets_pruned_mass() { return v00_00_02.ak8pfjets_pruned_mass(); }
	const vector<float> &ak8pfjets_trimmed_mass() { return v00_00_02.ak8pfjets_trimmed_mass(); }
	const vector<float> &ak8pfjets_filtered_mass() { return v00_00_02.ak8pfjets_filtered_mass(); }
	const vector<float> &ak8pfjets_pu_id() { return v00_00_02.ak8pfjets_pu_id(); }
	const vector<int> &ak8pfjets_parton_flavor() { return v00_00_02.ak8pfjets_parton_flavor(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak4genjets_p4() { return v00_00_02.ak4genjets_p4(); }
	const vector<TString> &tau_IDnames() { return v00_00_02.tau_IDnames(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadtrack_p4() { return v00_00_02.tau_leadtrack_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_leadneutral_p4() { return v00_00_02.tau_leadneutral_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &tau_p4() { return v00_00_02.tau_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_isocand_p4() { return v00_00_02.tau_isocand_p4(); }
	const vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &tau_sigcand_p4() { return v00_00_02.tau_sigcand_p4(); }
	const vector<float> &tau_mass() { return v00_00_02.tau_mass(); }
	const vector<vector<float> > &tau_ID() { return v00_00_02.tau_ID(); }
	const vector<float> &tau_passID() { return v00_00_02.tau_passID(); }
	const vector<float> &tau_charge() { return v00_00_02.tau_charge(); }
	const int &ngoodtaus() { return v00_00_02.ngoodtaus(); }
	const vector<float> &tau_againstMuonTight() { return v00_00_02.tau_againstMuonTight(); }
	const vector<float> &tau_againstElectronLoose() { return v00_00_02.tau_againstElectronLoose(); }
	const vector<bool> &tau_isVetoTau() { return v00_00_02.tau_isVetoTau(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isoTracks_p4() { return v00_00_02.isoTracks_p4(); }
	const vector<int> &isoTracks_charge() { return v00_00_02.isoTracks_charge(); }
	const vector<float> &isoTracks_absIso() { return v00_00_02.isoTracks_absIso(); }
	const vector<float> &isoTracks_dz() { return v00_00_02.isoTracks_dz(); }
	const vector<int> &isoTracks_pdgId() { return v00_00_02.isoTracks_pdgId(); }
	const vector<int> &isoTracks_selectedidx() { return v00_00_02.isoTracks_selectedidx(); }
	const int &isoTracks_nselected() { return v00_00_02.isoTracks_nselected(); }
	const vector<bool> &isoTracks_isVetoTrack() { return v00_00_02.isoTracks_isVetoTrack(); }
	const vector<bool> &isoTracks_isVetoTrack_v2() { return v00_00_02.isoTracks_isVetoTrack_v2(); }
	const vector<bool> &isoTracks_isVetoTrack_v3() { return v00_00_02.isoTracks_isVetoTrack_v3(); }
}
