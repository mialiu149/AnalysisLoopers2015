#include "leptree_v0.h"
leptree_v0 leptr_v0;

void leptree_v0::Init(TTree *tree) {
	jets_branch = 0;
	if (tree->GetBranch("jets") != 0) {
		jets_branch = tree->GetBranch("jets");
		if (jets_branch) {jets_branch->SetAddress(&jets_);}
	}
	p4_branch = 0;
	if (tree->GetBranch("p4") != 0) {
		p4_branch = tree->GetBranch("p4");
		if (p4_branch) {p4_branch->SetAddress(&p4_);}
	}
	tag_p4_branch = 0;
	if (tree->GetBranch("tag_p4") != 0) {
		tag_p4_branch = tree->GetBranch("tag_p4");
		if (tag_p4_branch) {tag_p4_branch->SetAddress(&tag_p4_);}
	}
	dilep_p4_branch = 0;
	if (tree->GetBranch("dilep_p4") != 0) {
		dilep_p4_branch = tree->GetBranch("dilep_p4");
		if (dilep_p4_branch) {dilep_p4_branch->SetAddress(&dilep_p4_);}
	}
	mc_p4_branch = 0;
	if (tree->GetBranch("mc_p4") != 0) {
		mc_p4_branch = tree->GetBranch("mc_p4");
		if (mc_p4_branch) {mc_p4_branch->SetAddress(&mc_p4_);}
	}
	mc_motherp4_branch = 0;
	if (tree->GetBranch("mc_motherp4") != 0) {
		mc_motherp4_branch = tree->GetBranch("mc_motherp4");
		if (mc_motherp4_branch) {mc_motherp4_branch->SetAddress(&mc_motherp4_);}
	}
	jet_close_lep_branch = 0;
	if (tree->GetBranch("jet_close_lep") != 0) {
		jet_close_lep_branch = tree->GetBranch("jet_close_lep");
		if (jet_close_lep_branch) {jet_close_lep_branch->SetAddress(&jet_close_lep_);}
	}
  tree->SetMakeClass(1);
	evt_pfmet_branch = 0;
	if (tree->GetBranch("evt_pfmet") != 0) {
		evt_pfmet_branch = tree->GetBranch("evt_pfmet");
		if (evt_pfmet_branch) {evt_pfmet_branch->SetAddress(&evt_pfmet_);}
	}
	evt_pfmetPhi_branch = 0;
	if (tree->GetBranch("evt_pfmetPhi") != 0) {
		evt_pfmetPhi_branch = tree->GetBranch("evt_pfmetPhi");
		if (evt_pfmetPhi_branch) {evt_pfmetPhi_branch->SetAddress(&evt_pfmetPhi_);}
	}
	evt_trackmet_branch = 0;
	if (tree->GetBranch("evt_trackmet") != 0) {
		evt_trackmet_branch = tree->GetBranch("evt_trackmet");
		if (evt_trackmet_branch) {evt_trackmet_branch->SetAddress(&evt_trackmet_);}
	}
	evt_trackmetPhi_branch = 0;
	if (tree->GetBranch("evt_trackmetPhi") != 0) {
		evt_trackmetPhi_branch = tree->GetBranch("evt_trackmetPhi");
		if (evt_trackmetPhi_branch) {evt_trackmetPhi_branch->SetAddress(&evt_trackmetPhi_);}
	}
	evt_corrMET_branch = 0;
	if (tree->GetBranch("evt_corrMET") != 0) {
		evt_corrMET_branch = tree->GetBranch("evt_corrMET");
		if (evt_corrMET_branch) {evt_corrMET_branch->SetAddress(&evt_corrMET_);}
	}
	evt_corrMETPhi_branch = 0;
	if (tree->GetBranch("evt_corrMETPhi") != 0) {
		evt_corrMETPhi_branch = tree->GetBranch("evt_corrMETPhi");
		if (evt_corrMETPhi_branch) {evt_corrMETPhi_branch->SetAddress(&evt_corrMETPhi_);}
	}
	evt_pfsumet_branch = 0;
	if (tree->GetBranch("evt_pfsumet") != 0) {
		evt_pfsumet_branch = tree->GetBranch("evt_pfsumet");
		if (evt_pfsumet_branch) {evt_pfsumet_branch->SetAddress(&evt_pfsumet_);}
	}
	evt_pfmetSig_branch = 0;
	if (tree->GetBranch("evt_pfmetSig") != 0) {
		evt_pfmetSig_branch = tree->GetBranch("evt_pfmetSig");
		if (evt_pfmetSig_branch) {evt_pfmetSig_branch->SetAddress(&evt_pfmetSig_);}
	}
	evt_event_branch = 0;
	if (tree->GetBranch("evt_event") != 0) {
		evt_event_branch = tree->GetBranch("evt_event");
		if (evt_event_branch) {evt_event_branch->SetAddress(&evt_event_);}
	}
	evt_lumiBlock_branch = 0;
	if (tree->GetBranch("evt_lumiBlock") != 0) {
		evt_lumiBlock_branch = tree->GetBranch("evt_lumiBlock");
		if (evt_lumiBlock_branch) {evt_lumiBlock_branch->SetAddress(&evt_lumiBlock_);}
	}
	evt_run_branch = 0;
	if (tree->GetBranch("evt_run") != 0) {
		evt_run_branch = tree->GetBranch("evt_run");
		if (evt_run_branch) {evt_run_branch->SetAddress(&evt_run_);}
	}
	filt_csc_branch = 0;
	if (tree->GetBranch("filt_csc") != 0) {
		filt_csc_branch = tree->GetBranch("filt_csc");
		if (filt_csc_branch) {filt_csc_branch->SetAddress(&filt_csc_);}
	}
	filt_hbhe_branch = 0;
	if (tree->GetBranch("filt_hbhe") != 0) {
		filt_hbhe_branch = tree->GetBranch("filt_hbhe");
		if (filt_hbhe_branch) {filt_hbhe_branch->SetAddress(&filt_hbhe_);}
	}
	passes_met_filters_branch = 0;
	if (tree->GetBranch("passes_met_filters") != 0) {
		passes_met_filters_branch = tree->GetBranch("passes_met_filters");
		if (passes_met_filters_branch) {passes_met_filters_branch->SetAddress(&passes_met_filters_);}
	}
	filt_hcallaser_branch = 0;
	if (tree->GetBranch("filt_hcallaser") != 0) {
		filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
		if (filt_hcallaser_branch) {filt_hcallaser_branch->SetAddress(&filt_hcallaser_);}
	}
	filt_ecaltp_branch = 0;
	if (tree->GetBranch("filt_ecaltp") != 0) {
		filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
		if (filt_ecaltp_branch) {filt_ecaltp_branch->SetAddress(&filt_ecaltp_);}
	}
	filt_trkfail_branch = 0;
	if (tree->GetBranch("filt_trkfail") != 0) {
		filt_trkfail_branch = tree->GetBranch("filt_trkfail");
		if (filt_trkfail_branch) {filt_trkfail_branch->SetAddress(&filt_trkfail_);}
	}
	filt_eebadsc_branch = 0;
	if (tree->GetBranch("filt_eebadsc") != 0) {
		filt_eebadsc_branch = tree->GetBranch("filt_eebadsc");
		if (filt_eebadsc_branch) {filt_eebadsc_branch->SetAddress(&filt_eebadsc_);}
	}
	evt_isRealData_branch = 0;
	if (tree->GetBranch("evt_isRealData") != 0) {
		evt_isRealData_branch = tree->GetBranch("evt_isRealData");
		if (evt_isRealData_branch) {evt_isRealData_branch->SetAddress(&evt_isRealData_);}
	}
	scale1fb_branch = 0;
	if (tree->GetBranch("scale1fb") != 0) {
		scale1fb_branch = tree->GetBranch("scale1fb");
		if (scale1fb_branch) {scale1fb_branch->SetAddress(&scale1fb_);}
	}
	evt_xsec_incl_branch = 0;
	if (tree->GetBranch("evt_xsec_incl") != 0) {
		evt_xsec_incl_branch = tree->GetBranch("evt_xsec_incl");
		if (evt_xsec_incl_branch) {evt_xsec_incl_branch->SetAddress(&evt_xsec_incl_);}
	}
	evt_kfactor_branch = 0;
	if (tree->GetBranch("evt_kfactor") != 0) {
		evt_kfactor_branch = tree->GetBranch("evt_kfactor");
		if (evt_kfactor_branch) {evt_kfactor_branch->SetAddress(&evt_kfactor_);}
	}
	gen_met_branch = 0;
	if (tree->GetBranch("gen_met") != 0) {
		gen_met_branch = tree->GetBranch("gen_met");
		if (gen_met_branch) {gen_met_branch->SetAddress(&gen_met_);}
	}
	gen_metPhi_branch = 0;
	if (tree->GetBranch("gen_metPhi") != 0) {
		gen_metPhi_branch = tree->GetBranch("gen_metPhi");
		if (gen_metPhi_branch) {gen_metPhi_branch->SetAddress(&gen_metPhi_);}
	}
	njets_branch = 0;
	if (tree->GetBranch("njets") != 0) {
		njets_branch = tree->GetBranch("njets");
		if (njets_branch) {njets_branch->SetAddress(&njets_);}
	}
	ht_branch = 0;
	if (tree->GetBranch("ht") != 0) {
		ht_branch = tree->GetBranch("ht");
		if (ht_branch) {ht_branch->SetAddress(&ht_);}
	}
	ht_SS_branch = 0;
	if (tree->GetBranch("ht_SS") != 0) {
		ht_SS_branch = tree->GetBranch("ht_SS");
		if (ht_SS_branch) {ht_SS_branch->SetAddress(&ht_SS_);}
	}
	jets_disc_branch = 0;
	if (tree->GetBranch("jets_disc") != 0) {
		jets_disc_branch = tree->GetBranch("jets_disc");
		if (jets_disc_branch) {jets_disc_branch->SetAddress(&jets_disc_);}
	}
	jets_area_branch = 0;
	if (tree->GetBranch("jets_area") != 0) {
		jets_area_branch = tree->GetBranch("jets_area");
		if (jets_area_branch) {jets_area_branch->SetAddress(&jets_area_);}
	}
	jets_undoJEC_branch = 0;
	if (tree->GetBranch("jets_undoJEC") != 0) {
		jets_undoJEC_branch = tree->GetBranch("jets_undoJEC");
		if (jets_undoJEC_branch) {jets_undoJEC_branch->SetAddress(&jets_undoJEC_);}
	}
	sample_branch = 0;
	if (tree->GetBranch("sample") != 0) {
		sample_branch = tree->GetBranch("sample");
		if (sample_branch) {sample_branch->SetAddress(&sample_);}
	}
	nFOs_SS_branch = 0;
	if (tree->GetBranch("nFOs_SS") != 0) {
		nFOs_SS_branch = tree->GetBranch("nFOs_SS");
		if (nFOs_SS_branch) {nFOs_SS_branch->SetAddress(&nFOs_SS_);}
	}
	nvtx_branch = 0;
	if (tree->GetBranch("nvtx") != 0) {
		nvtx_branch = tree->GetBranch("nvtx");
		if (nvtx_branch) {nvtx_branch->SetAddress(&nvtx_);}
	}
	rho_branch = 0;
	if (tree->GetBranch("rho") != 0) {
		rho_branch = tree->GetBranch("rho");
		if (rho_branch) {rho_branch->SetAddress(&rho_);}
	}
	rho_neut_centr_branch = 0;
	if (tree->GetBranch("rho_neut_centr") != 0) {
		rho_neut_centr_branch = tree->GetBranch("rho_neut_centr");
		if (rho_neut_centr_branch) {rho_neut_centr_branch->SetAddress(&rho_neut_centr_);}
	}
	rho_calo_branch = 0;
	if (tree->GetBranch("rho_calo") != 0) {
		rho_calo_branch = tree->GetBranch("rho_calo");
		if (rho_calo_branch) {rho_calo_branch->SetAddress(&rho_calo_);}
	}
	rho_calo_centr_branch = 0;
	if (tree->GetBranch("rho_calo_centr") != 0) {
		rho_calo_centr_branch = tree->GetBranch("rho_calo_centr");
		if (rho_calo_centr_branch) {rho_calo_centr_branch->SetAddress(&rho_calo_centr_);}
	}
	mc_motherid_branch = 0;
	if (tree->GetBranch("mc_motherid") != 0) {
		mc_motherid_branch = tree->GetBranch("mc_motherid");
		if (mc_motherid_branch) {mc_motherid_branch->SetAddress(&mc_motherid_);}
	}
	id_branch = 0;
	if (tree->GetBranch("id") != 0) {
		id_branch = tree->GetBranch("id");
		if (id_branch) {id_branch->SetAddress(&id_);}
	}
	isPF_branch = 0;
	if (tree->GetBranch("isPF") != 0) {
		isPF_branch = tree->GetBranch("isPF");
		if (isPF_branch) {isPF_branch->SetAddress(&isPF_);}
	}
	idx_branch = 0;
	if (tree->GetBranch("idx") != 0) {
		idx_branch = tree->GetBranch("idx");
		if (idx_branch) {idx_branch->SetAddress(&idx_);}
	}
	dxyPV_branch = 0;
	if (tree->GetBranch("dxyPV") != 0) {
		dxyPV_branch = tree->GetBranch("dxyPV");
		if (dxyPV_branch) {dxyPV_branch->SetAddress(&dxyPV_);}
	}
	dZ_branch = 0;
	if (tree->GetBranch("dZ") != 0) {
		dZ_branch = tree->GetBranch("dZ");
		if (dZ_branch) {dZ_branch->SetAddress(&dZ_);}
	}
	dxyPV_err_branch = 0;
	if (tree->GetBranch("dxyPV_err") != 0) {
		dxyPV_err_branch = tree->GetBranch("dxyPV_err");
		if (dxyPV_err_branch) {dxyPV_err_branch->SetAddress(&dxyPV_err_);}
	}
	motherID_branch = 0;
	if (tree->GetBranch("motherID") != 0) {
		motherID_branch = tree->GetBranch("motherID");
		if (motherID_branch) {motherID_branch->SetAddress(&motherID_);}
	}
	mc_id_branch = 0;
	if (tree->GetBranch("mc_id") != 0) {
		mc_id_branch = tree->GetBranch("mc_id");
		if (mc_id_branch) {mc_id_branch->SetAddress(&mc_id_);}
	}
	RelIso03_branch = 0;
	if (tree->GetBranch("RelIso03") != 0) {
		RelIso03_branch = tree->GetBranch("RelIso03");
		if (RelIso03_branch) {RelIso03_branch->SetAddress(&RelIso03_);}
	}
	RelIso03EA_branch = 0;
	if (tree->GetBranch("RelIso03EA") != 0) {
		RelIso03EA_branch = tree->GetBranch("RelIso03EA");
		if (RelIso03EA_branch) {RelIso03EA_branch->SetAddress(&RelIso03EA_);}
	}
	tag_RelIso03EA_branch = 0;
	if (tree->GetBranch("tag_RelIso03EA") != 0) {
		tag_RelIso03EA_branch = tree->GetBranch("tag_RelIso03EA");
		if (tag_RelIso03EA_branch) {tag_RelIso03EA_branch->SetAddress(&tag_RelIso03EA_);}
	}
	RelIso03DB_branch = 0;
	if (tree->GetBranch("RelIso03DB") != 0) {
		RelIso03DB_branch = tree->GetBranch("RelIso03DB");
		if (RelIso03DB_branch) {RelIso03DB_branch->SetAddress(&RelIso03DB_);}
	}
	pfChargedHadronIso_branch = 0;
	if (tree->GetBranch("pfChargedHadronIso") != 0) {
		pfChargedHadronIso_branch = tree->GetBranch("pfChargedHadronIso");
		if (pfChargedHadronIso_branch) {pfChargedHadronIso_branch->SetAddress(&pfChargedHadronIso_);}
	}
	pfPhotonIso_branch = 0;
	if (tree->GetBranch("pfPhotonIso") != 0) {
		pfPhotonIso_branch = tree->GetBranch("pfPhotonIso");
		if (pfPhotonIso_branch) {pfPhotonIso_branch->SetAddress(&pfPhotonIso_);}
	}
	pfNeutralHadronIso_branch = 0;
	if (tree->GetBranch("pfNeutralHadronIso") != 0) {
		pfNeutralHadronIso_branch = tree->GetBranch("pfNeutralHadronIso");
		if (pfNeutralHadronIso_branch) {pfNeutralHadronIso_branch->SetAddress(&pfNeutralHadronIso_);}
	}
	tkIso_branch = 0;
	if (tree->GetBranch("tkIso") != 0) {
		tkIso_branch = tree->GetBranch("tkIso");
		if (tkIso_branch) {tkIso_branch->SetAddress(&tkIso_);}
	}
	sumPUPt_branch = 0;
	if (tree->GetBranch("sumPUPt") != 0) {
		sumPUPt_branch = tree->GetBranch("sumPUPt");
		if (sumPUPt_branch) {sumPUPt_branch->SetAddress(&sumPUPt_);}
	}
	passes_SS_tight_v3_branch = 0;
	if (tree->GetBranch("passes_SS_tight_v3") != 0) {
		passes_SS_tight_v3_branch = tree->GetBranch("passes_SS_tight_v3");
		if (passes_SS_tight_v3_branch) {passes_SS_tight_v3_branch->SetAddress(&passes_SS_tight_v3_);}
	}
	passes_SS_tight_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_SS_tight_noiso_v3") != 0) {
		passes_SS_tight_noiso_v3_branch = tree->GetBranch("passes_SS_tight_noiso_v3");
		if (passes_SS_tight_noiso_v3_branch) {passes_SS_tight_noiso_v3_branch->SetAddress(&passes_SS_tight_noiso_v3_);}
	}
	passes_SS_fo_v3_branch = 0;
	if (tree->GetBranch("passes_SS_fo_v3") != 0) {
		passes_SS_fo_v3_branch = tree->GetBranch("passes_SS_fo_v3");
		if (passes_SS_fo_v3_branch) {passes_SS_fo_v3_branch->SetAddress(&passes_SS_fo_v3_);}
	}
	passes_SS_fo_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_SS_fo_noiso_v3") != 0) {
		passes_SS_fo_noiso_v3_branch = tree->GetBranch("passes_SS_fo_noiso_v3");
		if (passes_SS_fo_noiso_v3_branch) {passes_SS_fo_noiso_v3_branch->SetAddress(&passes_SS_fo_noiso_v3_);}
	}
	passes_SS_fo_looseMVA_v3_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_v3") != 0) {
		passes_SS_fo_looseMVA_v3_branch = tree->GetBranch("passes_SS_fo_looseMVA_v3");
		if (passes_SS_fo_looseMVA_v3_branch) {passes_SS_fo_looseMVA_v3_branch->SetAddress(&passes_SS_fo_looseMVA_v3_);}
	}
	passes_SS_fo_looseMVA_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_noiso_v3") != 0) {
		passes_SS_fo_looseMVA_noiso_v3_branch = tree->GetBranch("passes_SS_fo_looseMVA_noiso_v3");
		if (passes_SS_fo_looseMVA_noiso_v3_branch) {passes_SS_fo_looseMVA_noiso_v3_branch->SetAddress(&passes_SS_fo_looseMVA_noiso_v3_);}
	}
	passes_SS_veto_v3_branch = 0;
	if (tree->GetBranch("passes_SS_veto_v3") != 0) {
		passes_SS_veto_v3_branch = tree->GetBranch("passes_SS_veto_v3");
		if (passes_SS_veto_v3_branch) {passes_SS_veto_v3_branch->SetAddress(&passes_SS_veto_v3_);}
	}
	passes_SS_veto_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_SS_veto_noiso_v3") != 0) {
		passes_SS_veto_noiso_v3_branch = tree->GetBranch("passes_SS_veto_noiso_v3");
		if (passes_SS_veto_noiso_v3_branch) {passes_SS_veto_noiso_v3_branch->SetAddress(&passes_SS_veto_noiso_v3_);}
	}
	passes_SS_tight_v4_branch = 0;
	if (tree->GetBranch("passes_SS_tight_v4") != 0) {
		passes_SS_tight_v4_branch = tree->GetBranch("passes_SS_tight_v4");
		if (passes_SS_tight_v4_branch) {passes_SS_tight_v4_branch->SetAddress(&passes_SS_tight_v4_);}
	}
	passes_SS_tight_noiso_v4_branch = 0;
	if (tree->GetBranch("passes_SS_tight_noiso_v4") != 0) {
		passes_SS_tight_noiso_v4_branch = tree->GetBranch("passes_SS_tight_noiso_v4");
		if (passes_SS_tight_noiso_v4_branch) {passes_SS_tight_noiso_v4_branch->SetAddress(&passes_SS_tight_noiso_v4_);}
	}
	passes_SS_fo_v4_branch = 0;
	if (tree->GetBranch("passes_SS_fo_v4") != 0) {
		passes_SS_fo_v4_branch = tree->GetBranch("passes_SS_fo_v4");
		if (passes_SS_fo_v4_branch) {passes_SS_fo_v4_branch->SetAddress(&passes_SS_fo_v4_);}
	}
	passes_SS_fo_noiso_v4_branch = 0;
	if (tree->GetBranch("passes_SS_fo_noiso_v4") != 0) {
		passes_SS_fo_noiso_v4_branch = tree->GetBranch("passes_SS_fo_noiso_v4");
		if (passes_SS_fo_noiso_v4_branch) {passes_SS_fo_noiso_v4_branch->SetAddress(&passes_SS_fo_noiso_v4_);}
	}
	passes_SS_fo_looseMVA_v4_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_v4") != 0) {
		passes_SS_fo_looseMVA_v4_branch = tree->GetBranch("passes_SS_fo_looseMVA_v4");
		if (passes_SS_fo_looseMVA_v4_branch) {passes_SS_fo_looseMVA_v4_branch->SetAddress(&passes_SS_fo_looseMVA_v4_);}
	}
	passes_SS_fo_looseMVA_noiso_v4_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_noiso_v4") != 0) {
		passes_SS_fo_looseMVA_noiso_v4_branch = tree->GetBranch("passes_SS_fo_looseMVA_noiso_v4");
		if (passes_SS_fo_looseMVA_noiso_v4_branch) {passes_SS_fo_looseMVA_noiso_v4_branch->SetAddress(&passes_SS_fo_looseMVA_noiso_v4_);}
	}
	passes_SS_veto_v4_branch = 0;
	if (tree->GetBranch("passes_SS_veto_v4") != 0) {
		passes_SS_veto_v4_branch = tree->GetBranch("passes_SS_veto_v4");
		if (passes_SS_veto_v4_branch) {passes_SS_veto_v4_branch->SetAddress(&passes_SS_veto_v4_);}
	}
	passes_SS_veto_noiso_v4_branch = 0;
	if (tree->GetBranch("passes_SS_veto_noiso_v4") != 0) {
		passes_SS_veto_noiso_v4_branch = tree->GetBranch("passes_SS_veto_noiso_v4");
		if (passes_SS_veto_noiso_v4_branch) {passes_SS_veto_noiso_v4_branch->SetAddress(&passes_SS_veto_noiso_v4_);}
	}
	passes_SS_tight_v5_branch = 0;
	if (tree->GetBranch("passes_SS_tight_v5") != 0) {
		passes_SS_tight_v5_branch = tree->GetBranch("passes_SS_tight_v5");
		if (passes_SS_tight_v5_branch) {passes_SS_tight_v5_branch->SetAddress(&passes_SS_tight_v5_);}
	}
	passes_SS_tight_noiso_v5_branch = 0;
	if (tree->GetBranch("passes_SS_tight_noiso_v5") != 0) {
		passes_SS_tight_noiso_v5_branch = tree->GetBranch("passes_SS_tight_noiso_v5");
		if (passes_SS_tight_noiso_v5_branch) {passes_SS_tight_noiso_v5_branch->SetAddress(&passes_SS_tight_noiso_v5_);}
	}
	passes_SS_fo_v5_branch = 0;
	if (tree->GetBranch("passes_SS_fo_v5") != 0) {
		passes_SS_fo_v5_branch = tree->GetBranch("passes_SS_fo_v5");
		if (passes_SS_fo_v5_branch) {passes_SS_fo_v5_branch->SetAddress(&passes_SS_fo_v5_);}
	}
	passes_SS_fo_noiso_v5_branch = 0;
	if (tree->GetBranch("passes_SS_fo_noiso_v5") != 0) {
		passes_SS_fo_noiso_v5_branch = tree->GetBranch("passes_SS_fo_noiso_v5");
		if (passes_SS_fo_noiso_v5_branch) {passes_SS_fo_noiso_v5_branch->SetAddress(&passes_SS_fo_noiso_v5_);}
	}
	passes_SS_fo_looseMVA_v5_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_v5") != 0) {
		passes_SS_fo_looseMVA_v5_branch = tree->GetBranch("passes_SS_fo_looseMVA_v5");
		if (passes_SS_fo_looseMVA_v5_branch) {passes_SS_fo_looseMVA_v5_branch->SetAddress(&passes_SS_fo_looseMVA_v5_);}
	}
	passes_SS_fo_looseMVA_noiso_v5_branch = 0;
	if (tree->GetBranch("passes_SS_fo_looseMVA_noiso_v5") != 0) {
		passes_SS_fo_looseMVA_noiso_v5_branch = tree->GetBranch("passes_SS_fo_looseMVA_noiso_v5");
		if (passes_SS_fo_looseMVA_noiso_v5_branch) {passes_SS_fo_looseMVA_noiso_v5_branch->SetAddress(&passes_SS_fo_looseMVA_noiso_v5_);}
	}
	passes_SS_veto_v5_branch = 0;
	if (tree->GetBranch("passes_SS_veto_v5") != 0) {
		passes_SS_veto_v5_branch = tree->GetBranch("passes_SS_veto_v5");
		if (passes_SS_veto_v5_branch) {passes_SS_veto_v5_branch->SetAddress(&passes_SS_veto_v5_);}
	}
	passes_SS_veto_noiso_v5_branch = 0;
	if (tree->GetBranch("passes_SS_veto_noiso_v5") != 0) {
		passes_SS_veto_noiso_v5_branch = tree->GetBranch("passes_SS_veto_noiso_v5");
		if (passes_SS_veto_noiso_v5_branch) {passes_SS_veto_noiso_v5_branch->SetAddress(&passes_SS_veto_noiso_v5_);}
	}
	passes_WW_medium_v2_branch = 0;
	if (tree->GetBranch("passes_WW_medium_v2") != 0) {
		passes_WW_medium_v2_branch = tree->GetBranch("passes_WW_medium_v2");
		if (passes_WW_medium_v2_branch) {passes_WW_medium_v2_branch->SetAddress(&passes_WW_medium_v2_);}
	}
	passes_WW_medium_noiso_v2_branch = 0;
	if (tree->GetBranch("passes_WW_medium_noiso_v2") != 0) {
		passes_WW_medium_noiso_v2_branch = tree->GetBranch("passes_WW_medium_noiso_v2");
		if (passes_WW_medium_noiso_v2_branch) {passes_WW_medium_noiso_v2_branch->SetAddress(&passes_WW_medium_noiso_v2_);}
	}
	passes_WW_fo_v2_branch = 0;
	if (tree->GetBranch("passes_WW_fo_v2") != 0) {
		passes_WW_fo_v2_branch = tree->GetBranch("passes_WW_fo_v2");
		if (passes_WW_fo_v2_branch) {passes_WW_fo_v2_branch->SetAddress(&passes_WW_fo_v2_);}
	}
	passes_WW_fo_noiso_v2_branch = 0;
	if (tree->GetBranch("passes_WW_fo_noiso_v2") != 0) {
		passes_WW_fo_noiso_v2_branch = tree->GetBranch("passes_WW_fo_noiso_v2");
		if (passes_WW_fo_noiso_v2_branch) {passes_WW_fo_noiso_v2_branch->SetAddress(&passes_WW_fo_noiso_v2_);}
	}
	passes_WW_veto_v2_branch = 0;
	if (tree->GetBranch("passes_WW_veto_v2") != 0) {
		passes_WW_veto_v2_branch = tree->GetBranch("passes_WW_veto_v2");
		if (passes_WW_veto_v2_branch) {passes_WW_veto_v2_branch->SetAddress(&passes_WW_veto_v2_);}
	}
	passes_WW_veto_noiso_v2_branch = 0;
	if (tree->GetBranch("passes_WW_veto_noiso_v2") != 0) {
		passes_WW_veto_noiso_v2_branch = tree->GetBranch("passes_WW_veto_noiso_v2");
		if (passes_WW_veto_noiso_v2_branch) {passes_WW_veto_noiso_v2_branch->SetAddress(&passes_WW_veto_noiso_v2_);}
	}
	passes_HAD_veto_v3_branch = 0;
	if (tree->GetBranch("passes_HAD_veto_v3") != 0) {
		passes_HAD_veto_v3_branch = tree->GetBranch("passes_HAD_veto_v3");
		if (passes_HAD_veto_v3_branch) {passes_HAD_veto_v3_branch->SetAddress(&passes_HAD_veto_v3_);}
	}
	passes_HAD_veto_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_HAD_veto_noiso_v3") != 0) {
		passes_HAD_veto_noiso_v3_branch = tree->GetBranch("passes_HAD_veto_noiso_v3");
		if (passes_HAD_veto_noiso_v3_branch) {passes_HAD_veto_noiso_v3_branch->SetAddress(&passes_HAD_veto_noiso_v3_);}
	}
	passes_HAD_loose_v3_branch = 0;
	if (tree->GetBranch("passes_HAD_loose_v3") != 0) {
		passes_HAD_loose_v3_branch = tree->GetBranch("passes_HAD_loose_v3");
		if (passes_HAD_loose_v3_branch) {passes_HAD_loose_v3_branch->SetAddress(&passes_HAD_loose_v3_);}
	}
	passes_HAD_loose_noiso_v3_branch = 0;
	if (tree->GetBranch("passes_HAD_loose_noiso_v3") != 0) {
		passes_HAD_loose_noiso_v3_branch = tree->GetBranch("passes_HAD_loose_noiso_v3");
		if (passes_HAD_loose_noiso_v3_branch) {passes_HAD_loose_noiso_v3_branch->SetAddress(&passes_HAD_loose_noiso_v3_);}
	}
	passes_POG_vetoID_branch = 0;
	if (tree->GetBranch("passes_POG_vetoID") != 0) {
		passes_POG_vetoID_branch = tree->GetBranch("passes_POG_vetoID");
		if (passes_POG_vetoID_branch) {passes_POG_vetoID_branch->SetAddress(&passes_POG_vetoID_);}
	}
	passes_POG_looseID_branch = 0;
	if (tree->GetBranch("passes_POG_looseID") != 0) {
		passes_POG_looseID_branch = tree->GetBranch("passes_POG_looseID");
		if (passes_POG_looseID_branch) {passes_POG_looseID_branch->SetAddress(&passes_POG_looseID_);}
	}
	passes_POG_mediumID_branch = 0;
	if (tree->GetBranch("passes_POG_mediumID") != 0) {
		passes_POG_mediumID_branch = tree->GetBranch("passes_POG_mediumID");
		if (passes_POG_mediumID_branch) {passes_POG_mediumID_branch->SetAddress(&passes_POG_mediumID_);}
	}
	passes_POG_tightID_branch = 0;
	if (tree->GetBranch("passes_POG_tightID") != 0) {
		passes_POG_tightID_branch = tree->GetBranch("passes_POG_tightID");
		if (passes_POG_tightID_branch) {passes_POG_tightID_branch->SetAddress(&passes_POG_tightID_);}
	}
	ip3d_branch = 0;
	if (tree->GetBranch("ip3d") != 0) {
		ip3d_branch = tree->GetBranch("ip3d");
		if (ip3d_branch) {ip3d_branch->SetAddress(&ip3d_);}
	}
	ip3derr_branch = 0;
	if (tree->GetBranch("ip3derr") != 0) {
		ip3derr_branch = tree->GetBranch("ip3derr");
		if (ip3derr_branch) {ip3derr_branch->SetAddress(&ip3derr_);}
	}
	type_branch = 0;
	if (tree->GetBranch("type") != 0) {
		type_branch = tree->GetBranch("type");
		if (type_branch) {type_branch->SetAddress(&type_);}
	}
	mt_branch = 0;
	if (tree->GetBranch("mt") != 0) {
		mt_branch = tree->GetBranch("mt");
		if (mt_branch) {mt_branch->SetAddress(&mt_);}
	}
	ptrelv0_branch = 0;
	if (tree->GetBranch("ptrelv0") != 0) {
		ptrelv0_branch = tree->GetBranch("ptrelv0");
		if (ptrelv0_branch) {ptrelv0_branch->SetAddress(&ptrelv0_);}
	}
	ptrelv1_branch = 0;
	if (tree->GetBranch("ptrelv1") != 0) {
		ptrelv1_branch = tree->GetBranch("ptrelv1");
		if (ptrelv1_branch) {ptrelv1_branch->SetAddress(&ptrelv1_);}
	}
	miniiso_branch = 0;
	if (tree->GetBranch("miniiso") != 0) {
		miniiso_branch = tree->GetBranch("miniiso");
		if (miniiso_branch) {miniiso_branch->SetAddress(&miniiso_);}
	}
	miniisoDB_branch = 0;
	if (tree->GetBranch("miniisoDB") != 0) {
		miniisoDB_branch = tree->GetBranch("miniisoDB");
		if (miniisoDB_branch) {miniisoDB_branch->SetAddress(&miniisoDB_);}
	}
	reliso04_branch = 0;
	if (tree->GetBranch("reliso04") != 0) {
		reliso04_branch = tree->GetBranch("reliso04");
		if (reliso04_branch) {reliso04_branch->SetAddress(&reliso04_);}
	}
	annulus04_branch = 0;
	if (tree->GetBranch("annulus04") != 0) {
		annulus04_branch = tree->GetBranch("annulus04");
		if (annulus04_branch) {annulus04_branch->SetAddress(&annulus04_);}
	}
	AbsTrkIso_branch = 0;
	if (tree->GetBranch("AbsTrkIso") != 0) {
		AbsTrkIso_branch = tree->GetBranch("AbsTrkIso");
		if (AbsTrkIso_branch) {AbsTrkIso_branch->SetAddress(&AbsTrkIso_);}
	}
	TrkAn04_branch = 0;
	if (tree->GetBranch("TrkAn04") != 0) {
		TrkAn04_branch = tree->GetBranch("TrkAn04");
		if (TrkAn04_branch) {TrkAn04_branch->SetAddress(&TrkAn04_);}
	}
	iso03sumPt_branch = 0;
	if (tree->GetBranch("iso03sumPt") != 0) {
		iso03sumPt_branch = tree->GetBranch("iso03sumPt");
		if (iso03sumPt_branch) {iso03sumPt_branch->SetAddress(&iso03sumPt_);}
	}
	iso03emEt_branch = 0;
	if (tree->GetBranch("iso03emEt") != 0) {
		iso03emEt_branch = tree->GetBranch("iso03emEt");
		if (iso03emEt_branch) {iso03emEt_branch->SetAddress(&iso03emEt_);}
	}
	iso03hadEt_branch = 0;
	if (tree->GetBranch("iso03hadEt") != 0) {
		iso03hadEt_branch = tree->GetBranch("iso03hadEt");
		if (iso03hadEt_branch) {iso03hadEt_branch->SetAddress(&iso03hadEt_);}
	}
	jet_close_lep_idx_branch = 0;
	if (tree->GetBranch("jet_close_lep_idx") != 0) {
		jet_close_lep_idx_branch = tree->GetBranch("jet_close_lep_idx");
		if (jet_close_lep_idx_branch) {jet_close_lep_idx_branch->SetAddress(&jet_close_lep_idx_);}
	}
	jet_close_lep_undoJEC_branch = 0;
	if (tree->GetBranch("jet_close_lep_undoJEC") != 0) {
		jet_close_lep_undoJEC_branch = tree->GetBranch("jet_close_lep_undoJEC");
		if (jet_close_lep_undoJEC_branch) {jet_close_lep_undoJEC_branch->SetAddress(&jet_close_lep_undoJEC_);}
	}
	jet_close_lep_area_branch = 0;
	if (tree->GetBranch("jet_close_lep_area") != 0) {
		jet_close_lep_area_branch = tree->GetBranch("jet_close_lep_area");
		if (jet_close_lep_area_branch) {jet_close_lep_area_branch->SetAddress(&jet_close_lep_area_);}
	}
	jet_close_L1_branch = 0;
	if (tree->GetBranch("jet_close_L1") != 0) {
		jet_close_L1_branch = tree->GetBranch("jet_close_L1");
		if (jet_close_L1_branch) {jet_close_L1_branch->SetAddress(&jet_close_L1_);}
	}
	jet_close_L1nc_branch = 0;
	if (tree->GetBranch("jet_close_L1nc") != 0) {
		jet_close_L1nc_branch = tree->GetBranch("jet_close_L1nc");
		if (jet_close_L1nc_branch) {jet_close_L1nc_branch->SetAddress(&jet_close_L1nc_);}
	}
	jet_close_L1ncmc_branch = 0;
	if (tree->GetBranch("jet_close_L1ncmc") != 0) {
		jet_close_L1ncmc_branch = tree->GetBranch("jet_close_L1ncmc");
		if (jet_close_L1ncmc_branch) {jet_close_L1ncmc_branch->SetAddress(&jet_close_L1ncmc_);}
	}
	jet_close_L1L2L3_branch = 0;
	if (tree->GetBranch("jet_close_L1L2L3") != 0) {
		jet_close_L1L2L3_branch = tree->GetBranch("jet_close_L1L2L3");
		if (jet_close_L1L2L3_branch) {jet_close_L1L2L3_branch->SetAddress(&jet_close_L1L2L3_);}
	}
	jet_close_L2L3_branch = 0;
	if (tree->GetBranch("jet_close_L2L3") != 0) {
		jet_close_L2L3_branch = tree->GetBranch("jet_close_L2L3");
		if (jet_close_L2L3_branch) {jet_close_L2L3_branch->SetAddress(&jet_close_L2L3_);}
	}
	ptratio_branch = 0;
	if (tree->GetBranch("ptratio") != 0) {
		ptratio_branch = tree->GetBranch("ptratio");
		if (ptratio_branch) {ptratio_branch->SetAddress(&ptratio_);}
	}
	tag_charge_branch = 0;
	if (tree->GetBranch("tag_charge") != 0) {
		tag_charge_branch = tree->GetBranch("tag_charge");
		if (tag_charge_branch) {tag_charge_branch->SetAddress(&tag_charge_);}
	}
	tag_mc_motherid_branch = 0;
	if (tree->GetBranch("tag_mc_motherid") != 0) {
		tag_mc_motherid_branch = tree->GetBranch("tag_mc_motherid");
		if (tag_mc_motherid_branch) {tag_mc_motherid_branch->SetAddress(&tag_mc_motherid_);}
	}
	tag_eSeed_branch = 0;
	if (tree->GetBranch("tag_eSeed") != 0) {
		tag_eSeed_branch = tree->GetBranch("tag_eSeed");
		if (tag_eSeed_branch) {tag_eSeed_branch->SetAddress(&tag_eSeed_);}
	}
	tag_eSCRaw_branch = 0;
	if (tree->GetBranch("tag_eSCRaw") != 0) {
		tag_eSCRaw_branch = tree->GetBranch("tag_eSCRaw");
		if (tag_eSCRaw_branch) {tag_eSCRaw_branch->SetAddress(&tag_eSCRaw_);}
	}
	tag_eSC_branch = 0;
	if (tree->GetBranch("tag_eSC") != 0) {
		tag_eSC_branch = tree->GetBranch("tag_eSC");
		if (tag_eSC_branch) {tag_eSC_branch->SetAddress(&tag_eSC_);}
	}
	tag_ecalEnergy_branch = 0;
	if (tree->GetBranch("tag_ecalEnergy") != 0) {
		tag_ecalEnergy_branch = tree->GetBranch("tag_ecalEnergy");
		if (tag_ecalEnergy_branch) {tag_ecalEnergy_branch->SetAddress(&tag_ecalEnergy_);}
	}
	exp_innerlayers_branch = 0;
	if (tree->GetBranch("exp_innerlayers") != 0) {
		exp_innerlayers_branch = tree->GetBranch("exp_innerlayers");
		if (exp_innerlayers_branch) {exp_innerlayers_branch->SetAddress(&exp_innerlayers_);}
	}
	exp_outerlayers_branch = 0;
	if (tree->GetBranch("exp_outerlayers") != 0) {
		exp_outerlayers_branch = tree->GetBranch("exp_outerlayers");
		if (exp_outerlayers_branch) {exp_outerlayers_branch->SetAddress(&exp_outerlayers_);}
	}
	tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch = 0;
	if (tree->GetBranch("tag_HLT_Ele27_eta2p1_WPTight_Gsf") != 0) {
		tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch = tree->GetBranch("tag_HLT_Ele27_eta2p1_WPTight_Gsf");
		if (tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch) {tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch->SetAddress(&tag_HLT_Ele27_eta2p1_WPTight_Gsf_);}
	}
	tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch = 0;
	if (tree->GetBranch("tag_HLT_Ele32_eta2p1_WPTight_Gsf") != 0) {
		tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch = tree->GetBranch("tag_HLT_Ele32_eta2p1_WPTight_Gsf");
		if (tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch) {tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch->SetAddress(&tag_HLT_Ele32_eta2p1_WPTight_Gsf_);}
	}
	tag_HLT_IsoMu24_branch = 0;
	if (tree->GetBranch("tag_HLT_IsoMu24") != 0) {
		tag_HLT_IsoMu24_branch = tree->GetBranch("tag_HLT_IsoMu24");
		if (tag_HLT_IsoMu24_branch) {tag_HLT_IsoMu24_branch->SetAddress(&tag_HLT_IsoMu24_);}
	}
	tag_HLT_IsoTkMu24_branch = 0;
	if (tree->GetBranch("tag_HLT_IsoTkMu24") != 0) {
		tag_HLT_IsoTkMu24_branch = tree->GetBranch("tag_HLT_IsoTkMu24");
		if (tag_HLT_IsoTkMu24_branch) {tag_HLT_IsoTkMu24_branch->SetAddress(&tag_HLT_IsoTkMu24_);}
	}
	dilep_mass_branch = 0;
	if (tree->GetBranch("dilep_mass") != 0) {
		dilep_mass_branch = tree->GetBranch("dilep_mass");
		if (dilep_mass_branch) {dilep_mass_branch->SetAddress(&dilep_mass_);}
	}
	isRandom_branch = 0;
	if (tree->GetBranch("isRandom") != 0) {
		isRandom_branch = tree->GetBranch("isRandom");
		if (isRandom_branch) {isRandom_branch->SetAddress(&isRandom_);}
	}
	sigmaIEtaIEta_full5x5_branch = 0;
	if (tree->GetBranch("sigmaIEtaIEta_full5x5") != 0) {
		sigmaIEtaIEta_full5x5_branch = tree->GetBranch("sigmaIEtaIEta_full5x5");
		if (sigmaIEtaIEta_full5x5_branch) {sigmaIEtaIEta_full5x5_branch->SetAddress(&sigmaIEtaIEta_full5x5_);}
	}
	sigmaIEtaIEta_branch = 0;
	if (tree->GetBranch("sigmaIEtaIEta") != 0) {
		sigmaIEtaIEta_branch = tree->GetBranch("sigmaIEtaIEta");
		if (sigmaIEtaIEta_branch) {sigmaIEtaIEta_branch->SetAddress(&sigmaIEtaIEta_);}
	}
	etaSC_branch = 0;
	if (tree->GetBranch("etaSC") != 0) {
		etaSC_branch = tree->GetBranch("etaSC");
		if (etaSC_branch) {etaSC_branch->SetAddress(&etaSC_);}
	}
	dEtaIn_branch = 0;
	if (tree->GetBranch("dEtaIn") != 0) {
		dEtaIn_branch = tree->GetBranch("dEtaIn");
		if (dEtaIn_branch) {dEtaIn_branch->SetAddress(&dEtaIn_);}
	}
	dPhiIn_branch = 0;
	if (tree->GetBranch("dPhiIn") != 0) {
		dPhiIn_branch = tree->GetBranch("dPhiIn");
		if (dPhiIn_branch) {dPhiIn_branch->SetAddress(&dPhiIn_);}
	}
	hOverE_branch = 0;
	if (tree->GetBranch("hOverE") != 0) {
		hOverE_branch = tree->GetBranch("hOverE");
		if (hOverE_branch) {hOverE_branch->SetAddress(&hOverE_);}
	}
	eSeed_branch = 0;
	if (tree->GetBranch("eSeed") != 0) {
		eSeed_branch = tree->GetBranch("eSeed");
		if (eSeed_branch) {eSeed_branch->SetAddress(&eSeed_);}
	}
	scSeedEta_branch = 0;
	if (tree->GetBranch("scSeedEta") != 0) {
		scSeedEta_branch = tree->GetBranch("scSeedEta");
		if (scSeedEta_branch) {scSeedEta_branch->SetAddress(&scSeedEta_);}
	}
	ecalEnergy_branch = 0;
	if (tree->GetBranch("ecalEnergy") != 0) {
		ecalEnergy_branch = tree->GetBranch("ecalEnergy");
		if (ecalEnergy_branch) {ecalEnergy_branch->SetAddress(&ecalEnergy_);}
	}
	eOverPIn_branch = 0;
	if (tree->GetBranch("eOverPIn") != 0) {
		eOverPIn_branch = tree->GetBranch("eOverPIn");
		if (eOverPIn_branch) {eOverPIn_branch->SetAddress(&eOverPIn_);}
	}
	conv_vtx_flag_branch = 0;
	if (tree->GetBranch("conv_vtx_flag") != 0) {
		conv_vtx_flag_branch = tree->GetBranch("conv_vtx_flag");
		if (conv_vtx_flag_branch) {conv_vtx_flag_branch->SetAddress(&conv_vtx_flag_);}
	}
	charge_branch = 0;
	if (tree->GetBranch("charge") != 0) {
		charge_branch = tree->GetBranch("charge");
		if (charge_branch) {charge_branch->SetAddress(&charge_);}
	}
	sccharge_branch = 0;
	if (tree->GetBranch("sccharge") != 0) {
		sccharge_branch = tree->GetBranch("sccharge");
		if (sccharge_branch) {sccharge_branch->SetAddress(&sccharge_);}
	}
	ckf_charge_branch = 0;
	if (tree->GetBranch("ckf_charge") != 0) {
		ckf_charge_branch = tree->GetBranch("ckf_charge");
		if (ckf_charge_branch) {ckf_charge_branch->SetAddress(&ckf_charge_);}
	}
	threeChargeAgree_branch = 0;
	if (tree->GetBranch("threeChargeAgree") != 0) {
		threeChargeAgree_branch = tree->GetBranch("threeChargeAgree");
		if (threeChargeAgree_branch) {threeChargeAgree_branch->SetAddress(&threeChargeAgree_);}
	}
	mva_branch = 0;
	if (tree->GetBranch("mva") != 0) {
		mva_branch = tree->GetBranch("mva");
		if (mva_branch) {mva_branch->SetAddress(&mva_);}
	}
	mva_25ns_branch = 0;
	if (tree->GetBranch("mva_25ns") != 0) {
		mva_25ns_branch = tree->GetBranch("mva_25ns");
		if (mva_25ns_branch) {mva_25ns_branch->SetAddress(&mva_25ns_);}
	}
	tag_mva_25ns_branch = 0;
	if (tree->GetBranch("tag_mva_25ns") != 0) {
		tag_mva_25ns_branch = tree->GetBranch("tag_mva_25ns");
		if (tag_mva_25ns_branch) {tag_mva_25ns_branch->SetAddress(&tag_mva_25ns_);}
	}
	ecalIso_branch = 0;
	if (tree->GetBranch("ecalIso") != 0) {
		ecalIso_branch = tree->GetBranch("ecalIso");
		if (ecalIso_branch) {ecalIso_branch->SetAddress(&ecalIso_);}
	}
	hcalIso_branch = 0;
	if (tree->GetBranch("hcalIso") != 0) {
		hcalIso_branch = tree->GetBranch("hcalIso");
		if (hcalIso_branch) {hcalIso_branch->SetAddress(&hcalIso_);}
	}
	ecalPFClusterIso_branch = 0;
	if (tree->GetBranch("ecalPFClusterIso") != 0) {
		ecalPFClusterIso_branch = tree->GetBranch("ecalPFClusterIso");
		if (ecalPFClusterIso_branch) {ecalPFClusterIso_branch->SetAddress(&ecalPFClusterIso_);}
	}
	hcalPFClusterIso_branch = 0;
	if (tree->GetBranch("hcalPFClusterIso") != 0) {
		hcalPFClusterIso_branch = tree->GetBranch("hcalPFClusterIso");
		if (hcalPFClusterIso_branch) {hcalPFClusterIso_branch->SetAddress(&hcalPFClusterIso_);}
	}
	ckf_laywithmeas_branch = 0;
	if (tree->GetBranch("ckf_laywithmeas") != 0) {
		ckf_laywithmeas_branch = tree->GetBranch("ckf_laywithmeas");
		if (ckf_laywithmeas_branch) {ckf_laywithmeas_branch->SetAddress(&ckf_laywithmeas_);}
	}
	sigmaIPhiIPhi_full5x5_branch = 0;
	if (tree->GetBranch("sigmaIPhiIPhi_full5x5") != 0) {
		sigmaIPhiIPhi_full5x5_branch = tree->GetBranch("sigmaIPhiIPhi_full5x5");
		if (sigmaIPhiIPhi_full5x5_branch) {sigmaIPhiIPhi_full5x5_branch->SetAddress(&sigmaIPhiIPhi_full5x5_);}
	}
	e1x5_full5x5_branch = 0;
	if (tree->GetBranch("e1x5_full5x5") != 0) {
		e1x5_full5x5_branch = tree->GetBranch("e1x5_full5x5");
		if (e1x5_full5x5_branch) {e1x5_full5x5_branch->SetAddress(&e1x5_full5x5_);}
	}
	e5x5_full5x5_branch = 0;
	if (tree->GetBranch("e5x5_full5x5") != 0) {
		e5x5_full5x5_branch = tree->GetBranch("e5x5_full5x5");
		if (e5x5_full5x5_branch) {e5x5_full5x5_branch->SetAddress(&e5x5_full5x5_);}
	}
	r9_full5x5_branch = 0;
	if (tree->GetBranch("r9_full5x5") != 0) {
		r9_full5x5_branch = tree->GetBranch("r9_full5x5");
		if (r9_full5x5_branch) {r9_full5x5_branch->SetAddress(&r9_full5x5_);}
	}
	tag_r9_full5x5_branch = 0;
	if (tree->GetBranch("tag_r9_full5x5") != 0) {
		tag_r9_full5x5_branch = tree->GetBranch("tag_r9_full5x5");
		if (tag_r9_full5x5_branch) {tag_r9_full5x5_branch->SetAddress(&tag_r9_full5x5_);}
	}
	etaSCwidth_branch = 0;
	if (tree->GetBranch("etaSCwidth") != 0) {
		etaSCwidth_branch = tree->GetBranch("etaSCwidth");
		if (etaSCwidth_branch) {etaSCwidth_branch->SetAddress(&etaSCwidth_);}
	}
	phiSCwidth_branch = 0;
	if (tree->GetBranch("phiSCwidth") != 0) {
		phiSCwidth_branch = tree->GetBranch("phiSCwidth");
		if (phiSCwidth_branch) {phiSCwidth_branch->SetAddress(&phiSCwidth_);}
	}
	eSCRaw_branch = 0;
	if (tree->GetBranch("eSCRaw") != 0) {
		eSCRaw_branch = tree->GetBranch("eSCRaw");
		if (eSCRaw_branch) {eSCRaw_branch->SetAddress(&eSCRaw_);}
	}
	eSC_branch = 0;
	if (tree->GetBranch("eSC") != 0) {
		eSC_branch = tree->GetBranch("eSC");
		if (eSC_branch) {eSC_branch->SetAddress(&eSC_);}
	}
	eSCPresh_branch = 0;
	if (tree->GetBranch("eSCPresh") != 0) {
		eSCPresh_branch = tree->GetBranch("eSCPresh");
		if (eSCPresh_branch) {eSCPresh_branch->SetAddress(&eSCPresh_);}
	}
	ckf_chi2_branch = 0;
	if (tree->GetBranch("ckf_chi2") != 0) {
		ckf_chi2_branch = tree->GetBranch("ckf_chi2");
		if (ckf_chi2_branch) {ckf_chi2_branch->SetAddress(&ckf_chi2_);}
	}
	ckf_ndof_branch = 0;
	if (tree->GetBranch("ckf_ndof") != 0) {
		ckf_ndof_branch = tree->GetBranch("ckf_ndof");
		if (ckf_ndof_branch) {ckf_ndof_branch->SetAddress(&ckf_ndof_);}
	}
	chi2_branch = 0;
	if (tree->GetBranch("chi2") != 0) {
		chi2_branch = tree->GetBranch("chi2");
		if (chi2_branch) {chi2_branch->SetAddress(&chi2_);}
	}
	ndof_branch = 0;
	if (tree->GetBranch("ndof") != 0) {
		ndof_branch = tree->GetBranch("ndof");
		if (ndof_branch) {ndof_branch->SetAddress(&ndof_);}
	}
	fbrem_branch = 0;
	if (tree->GetBranch("fbrem") != 0) {
		fbrem_branch = tree->GetBranch("fbrem");
		if (fbrem_branch) {fbrem_branch->SetAddress(&fbrem_);}
	}
	eOverPOut_branch = 0;
	if (tree->GetBranch("eOverPOut") != 0) {
		eOverPOut_branch = tree->GetBranch("eOverPOut");
		if (eOverPOut_branch) {eOverPOut_branch->SetAddress(&eOverPOut_);}
	}
	dEtaOut_branch = 0;
	if (tree->GetBranch("dEtaOut") != 0) {
		dEtaOut_branch = tree->GetBranch("dEtaOut");
		if (dEtaOut_branch) {dEtaOut_branch->SetAddress(&dEtaOut_);}
	}
	dPhiOut_branch = 0;
	if (tree->GetBranch("dPhiOut") != 0) {
		dPhiOut_branch = tree->GetBranch("dPhiOut");
		if (dPhiOut_branch) {dPhiOut_branch->SetAddress(&dPhiOut_);}
	}
	gsf_validHits_branch = 0;
	if (tree->GetBranch("gsf_validHits") != 0) {
		gsf_validHits_branch = tree->GetBranch("gsf_validHits");
		if (gsf_validHits_branch) {gsf_validHits_branch->SetAddress(&gsf_validHits_);}
	}
	conv_vtx_prob_branch = 0;
	if (tree->GetBranch("conv_vtx_prob") != 0) {
		conv_vtx_prob_branch = tree->GetBranch("conv_vtx_prob");
		if (conv_vtx_prob_branch) {conv_vtx_prob_branch->SetAddress(&conv_vtx_prob_);}
	}
	pid_PFMuon_branch = 0;
	if (tree->GetBranch("pid_PFMuon") != 0) {
		pid_PFMuon_branch = tree->GetBranch("pid_PFMuon");
		if (pid_PFMuon_branch) {pid_PFMuon_branch->SetAddress(&pid_PFMuon_);}
	}
	gfit_chi2_branch = 0;
	if (tree->GetBranch("gfit_chi2") != 0) {
		gfit_chi2_branch = tree->GetBranch("gfit_chi2");
		if (gfit_chi2_branch) {gfit_chi2_branch->SetAddress(&gfit_chi2_);}
	}
	gfit_validSTAHits_branch = 0;
	if (tree->GetBranch("gfit_validSTAHits") != 0) {
		gfit_validSTAHits_branch = tree->GetBranch("gfit_validSTAHits");
		if (gfit_validSTAHits_branch) {gfit_validSTAHits_branch->SetAddress(&gfit_validSTAHits_);}
	}
	numberOfMatchedStations_branch = 0;
	if (tree->GetBranch("numberOfMatchedStations") != 0) {
		numberOfMatchedStations_branch = tree->GetBranch("numberOfMatchedStations");
		if (numberOfMatchedStations_branch) {numberOfMatchedStations_branch->SetAddress(&numberOfMatchedStations_);}
	}
	validPixelHits_branch = 0;
	if (tree->GetBranch("validPixelHits") != 0) {
		validPixelHits_branch = tree->GetBranch("validPixelHits");
		if (validPixelHits_branch) {validPixelHits_branch->SetAddress(&validPixelHits_);}
	}
	nlayers_branch = 0;
	if (tree->GetBranch("nlayers") != 0) {
		nlayers_branch = tree->GetBranch("nlayers");
		if (nlayers_branch) {nlayers_branch->SetAddress(&nlayers_);}
	}
	chi2LocalPosition_branch = 0;
	if (tree->GetBranch("chi2LocalPosition") != 0) {
		chi2LocalPosition_branch = tree->GetBranch("chi2LocalPosition");
		if (chi2LocalPosition_branch) {chi2LocalPosition_branch->SetAddress(&chi2LocalPosition_);}
	}
	trkKink_branch = 0;
	if (tree->GetBranch("trkKink") != 0) {
		trkKink_branch = tree->GetBranch("trkKink");
		if (trkKink_branch) {trkKink_branch->SetAddress(&trkKink_);}
	}
	validHits_branch = 0;
	if (tree->GetBranch("validHits") != 0) {
		validHits_branch = tree->GetBranch("validHits");
		if (validHits_branch) {validHits_branch->SetAddress(&validHits_);}
	}
	lostHits_branch = 0;
	if (tree->GetBranch("lostHits") != 0) {
		lostHits_branch = tree->GetBranch("lostHits");
		if (lostHits_branch) {lostHits_branch->SetAddress(&lostHits_);}
	}
	segmCompatibility_branch = 0;
	if (tree->GetBranch("segmCompatibility") != 0) {
		segmCompatibility_branch = tree->GetBranch("segmCompatibility");
		if (segmCompatibility_branch) {segmCompatibility_branch->SetAddress(&segmCompatibility_);}
	}
	HLT_Mu8_branch = 0;
	if (tree->GetBranch("HLT_Mu8") != 0) {
		HLT_Mu8_branch = tree->GetBranch("HLT_Mu8");
		if (HLT_Mu8_branch) {HLT_Mu8_branch->SetAddress(&HLT_Mu8_);}
	}
	HLT_Mu17_branch = 0;
	if (tree->GetBranch("HLT_Mu17") != 0) {
		HLT_Mu17_branch = tree->GetBranch("HLT_Mu17");
		if (HLT_Mu17_branch) {HLT_Mu17_branch->SetAddress(&HLT_Mu17_);}
	}
	HLT_Mu8_TrkIsoVVL_branch = 0;
	if (tree->GetBranch("HLT_Mu8_TrkIsoVVL") != 0) {
		HLT_Mu8_TrkIsoVVL_branch = tree->GetBranch("HLT_Mu8_TrkIsoVVL");
		if (HLT_Mu8_TrkIsoVVL_branch) {HLT_Mu8_TrkIsoVVL_branch->SetAddress(&HLT_Mu8_TrkIsoVVL_);}
	}
	HLT_Mu17_TrkIsoVVL_branch = 0;
	if (tree->GetBranch("HLT_Mu17_TrkIsoVVL") != 0) {
		HLT_Mu17_TrkIsoVVL_branch = tree->GetBranch("HLT_Mu17_TrkIsoVVL");
		if (HLT_Mu17_TrkIsoVVL_branch) {HLT_Mu17_TrkIsoVVL_branch->SetAddress(&HLT_Mu17_TrkIsoVVL_);}
	}
	HLT_IsoMu24_branch = 0;
	if (tree->GetBranch("HLT_IsoMu24") != 0) {
		HLT_IsoMu24_branch = tree->GetBranch("HLT_IsoMu24");
		if (HLT_IsoMu24_branch) {HLT_IsoMu24_branch->SetAddress(&HLT_IsoMu24_);}
	}
	HLT_IsoTkMu24_branch = 0;
	if (tree->GetBranch("HLT_IsoTkMu24") != 0) {
		HLT_IsoTkMu24_branch = tree->GetBranch("HLT_IsoTkMu24");
		if (HLT_IsoTkMu24_branch) {HLT_IsoTkMu24_branch->SetAddress(&HLT_IsoTkMu24_);}
	}
	HLT_Mu50_branch = 0;
	if (tree->GetBranch("HLT_Mu50") != 0) {
		HLT_Mu50_branch = tree->GetBranch("HLT_Mu50");
		if (HLT_Mu50_branch) {HLT_Mu50_branch->SetAddress(&HLT_Mu50_);}
	}
	HLT_Mu55_branch = 0;
	if (tree->GetBranch("HLT_Mu55") != 0) {
		HLT_Mu55_branch = tree->GetBranch("HLT_Mu55");
		if (HLT_Mu55_branch) {HLT_Mu55_branch->SetAddress(&HLT_Mu55_);}
	}
	HLT_TkMu50_branch = 0;
	if (tree->GetBranch("HLT_TkMu50") != 0) {
		HLT_TkMu50_branch = tree->GetBranch("HLT_TkMu50");
		if (HLT_TkMu50_branch) {HLT_TkMu50_branch->SetAddress(&HLT_TkMu50_);}
	}
	HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch = 0;
	if (tree->GetBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg") != 0) {
		HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch = tree->GetBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg");
		if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch) {HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch->SetAddress(&HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_);}
	}
	HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch = 0;
	if (tree->GetBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg") != 0) {
		HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch = tree->GetBranch("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg");
		if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch) {HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch->SetAddress(&HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_);}
	}
	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch = 0;
	if (tree->GetBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg") != 0) {
		HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch = tree->GetBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg");
		if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch) {HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch->SetAddress(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_);}
	}
	HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch = 0;
	if (tree->GetBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg") != 0) {
		HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch = tree->GetBranch("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg");
		if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch) {HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch->SetAddress(&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_);}
	}
	HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30") != 0) {
		HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch = tree->GetBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30");
		if (HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch) {HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch->SetAddress(&HLT_Ele8_CaloIdM_TrackIdM_PFJet30_);}
	}
	HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele12_CaloIdM_TrackIdM_PFJet30") != 0) {
		HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch = tree->GetBranch("HLT_Ele12_CaloIdM_TrackIdM_PFJet30");
		if (HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch) {HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch->SetAddress(&HLT_Ele12_CaloIdM_TrackIdM_PFJet30_);}
	}
	HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30") != 0) {
		HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch = tree->GetBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30");
		if (HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch) {HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch->SetAddress(&HLT_Ele17_CaloIdM_TrackIdM_PFJet30_);}
	}
	HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele23_CaloIdM_TrackIdM_PFJet30") != 0) {
		HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch = tree->GetBranch("HLT_Ele23_CaloIdM_TrackIdM_PFJet30");
		if (HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch) {HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch->SetAddress(&HLT_Ele23_CaloIdM_TrackIdM_PFJet30_);}
	}
	HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30") != 0) {
		HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = tree->GetBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30");
		if (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch) {HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->SetAddress(&HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_);}
	}
	HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30") != 0) {
		HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = tree->GetBranch("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30");
		if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch) {HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->SetAddress(&HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_);}
	}
	HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30") != 0) {
		HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = tree->GetBranch("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30");
		if (HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch) {HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->SetAddress(&HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_);}
	}
	HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = 0;
	if (tree->GetBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30") != 0) {
		HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch = tree->GetBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30");
		if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch) {HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->SetAddress(&HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_);}
	}
	HLT_Ele27_eta2p1_WPTight_Gsf_branch = 0;
	if (tree->GetBranch("HLT_Ele27_eta2p1_WPTight_Gsf") != 0) {
		HLT_Ele27_eta2p1_WPTight_Gsf_branch = tree->GetBranch("HLT_Ele27_eta2p1_WPTight_Gsf");
		if (HLT_Ele27_eta2p1_WPTight_Gsf_branch) {HLT_Ele27_eta2p1_WPTight_Gsf_branch->SetAddress(&HLT_Ele27_eta2p1_WPTight_Gsf_);}
	}
	HLT_Ele32_eta2p1_WPTight_Gsf_branch = 0;
	if (tree->GetBranch("HLT_Ele32_eta2p1_WPTight_Gsf") != 0) {
		HLT_Ele32_eta2p1_WPTight_Gsf_branch = tree->GetBranch("HLT_Ele32_eta2p1_WPTight_Gsf");
		if (HLT_Ele32_eta2p1_WPTight_Gsf_branch) {HLT_Ele32_eta2p1_WPTight_Gsf_branch->SetAddress(&HLT_Ele32_eta2p1_WPTight_Gsf_);}
	}
	HLT_Ele105_CaloIdVT_GsfTrkIdT_branch = 0;
	if (tree->GetBranch("HLT_Ele105_CaloIdVT_GsfTrkIdT") != 0) {
		HLT_Ele105_CaloIdVT_GsfTrkIdT_branch = tree->GetBranch("HLT_Ele105_CaloIdVT_GsfTrkIdT");
		if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch) {HLT_Ele105_CaloIdVT_GsfTrkIdT_branch->SetAddress(&HLT_Ele105_CaloIdVT_GsfTrkIdT_);}
	}
	HLT_Ele115_CaloIdVT_GsfTrkIdT_branch = 0;
	if (tree->GetBranch("HLT_Ele115_CaloIdVT_GsfTrkIdT") != 0) {
		HLT_Ele115_CaloIdVT_GsfTrkIdT_branch = tree->GetBranch("HLT_Ele115_CaloIdVT_GsfTrkIdT");
		if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch) {HLT_Ele115_CaloIdVT_GsfTrkIdT_branch->SetAddress(&HLT_Ele115_CaloIdVT_GsfTrkIdT_);}
	}
	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch = 0;
	if (tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg") != 0) {
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch = tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg");
		if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch) {HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch->SetAddress(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_);}
	}
	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch = 0;
	if (tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg") != 0) {
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch = tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg");
		if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch) {HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch->SetAddress(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_);}
	}
	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch = 0;
	if (tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1") != 0) {
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch = tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1");
		if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch) {HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch->SetAddress(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_);}
	}
	HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch = 0;
	if (tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL") != 0) {
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
		if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch) {HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_);}
	}
	HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch = 0;
	if (tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg") != 0) {
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch = tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg");
		if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch) {HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch->SetAddress(&HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_);}
	}
	HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch = 0;
	if (tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg") != 0) {
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch = tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg");
		if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch) {HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch->SetAddress(&HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_);}
	}
	HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch = 0;
	if (tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1") != 0) {
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch = tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1");
		if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch) {HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch->SetAddress(&HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_);}
	}
	HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch = 0;
	if (tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL") != 0) {
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL");
		if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch) {HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_);}
	}
  tree->SetMakeClass(0);
}
void leptree_v0::GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		evt_pfmet_isLoaded = false;
		evt_pfmetPhi_isLoaded = false;
		evt_trackmet_isLoaded = false;
		evt_trackmetPhi_isLoaded = false;
		evt_corrMET_isLoaded = false;
		evt_corrMETPhi_isLoaded = false;
		evt_pfsumet_isLoaded = false;
		evt_pfmetSig_isLoaded = false;
		evt_event_isLoaded = false;
		evt_lumiBlock_isLoaded = false;
		evt_run_isLoaded = false;
		filt_csc_isLoaded = false;
		filt_hbhe_isLoaded = false;
		passes_met_filters_isLoaded = false;
		filt_hcallaser_isLoaded = false;
		filt_ecaltp_isLoaded = false;
		filt_trkfail_isLoaded = false;
		filt_eebadsc_isLoaded = false;
		evt_isRealData_isLoaded = false;
		scale1fb_isLoaded = false;
		evt_xsec_incl_isLoaded = false;
		evt_kfactor_isLoaded = false;
		gen_met_isLoaded = false;
		gen_metPhi_isLoaded = false;
		njets_isLoaded = false;
		ht_isLoaded = false;
		ht_SS_isLoaded = false;
		jets_isLoaded = false;
		jets_disc_isLoaded = false;
		jets_area_isLoaded = false;
		jets_undoJEC_isLoaded = false;
		sample_isLoaded = false;
		nFOs_SS_isLoaded = false;
		nvtx_isLoaded = false;
		rho_isLoaded = false;
		rho_neut_centr_isLoaded = false;
		rho_calo_isLoaded = false;
		rho_calo_centr_isLoaded = false;
		p4_isLoaded = false;
		tag_p4_isLoaded = false;
		dilep_p4_isLoaded = false;
		mc_p4_isLoaded = false;
		mc_motherp4_isLoaded = false;
		mc_motherid_isLoaded = false;
		id_isLoaded = false;
		isPF_isLoaded = false;
		idx_isLoaded = false;
		dxyPV_isLoaded = false;
		dZ_isLoaded = false;
		dxyPV_err_isLoaded = false;
		motherID_isLoaded = false;
		mc_id_isLoaded = false;
		RelIso03_isLoaded = false;
		RelIso03EA_isLoaded = false;
		tag_RelIso03EA_isLoaded = false;
		RelIso03DB_isLoaded = false;
		pfChargedHadronIso_isLoaded = false;
		pfPhotonIso_isLoaded = false;
		pfNeutralHadronIso_isLoaded = false;
		tkIso_isLoaded = false;
		sumPUPt_isLoaded = false;
		passes_SS_tight_v3_isLoaded = false;
		passes_SS_tight_noiso_v3_isLoaded = false;
		passes_SS_fo_v3_isLoaded = false;
		passes_SS_fo_noiso_v3_isLoaded = false;
		passes_SS_fo_looseMVA_v3_isLoaded = false;
		passes_SS_fo_looseMVA_noiso_v3_isLoaded = false;
		passes_SS_veto_v3_isLoaded = false;
		passes_SS_veto_noiso_v3_isLoaded = false;
		passes_SS_tight_v4_isLoaded = false;
		passes_SS_tight_noiso_v4_isLoaded = false;
		passes_SS_fo_v4_isLoaded = false;
		passes_SS_fo_noiso_v4_isLoaded = false;
		passes_SS_fo_looseMVA_v4_isLoaded = false;
		passes_SS_fo_looseMVA_noiso_v4_isLoaded = false;
		passes_SS_veto_v4_isLoaded = false;
		passes_SS_veto_noiso_v4_isLoaded = false;
		passes_SS_tight_v5_isLoaded = false;
		passes_SS_tight_noiso_v5_isLoaded = false;
		passes_SS_fo_v5_isLoaded = false;
		passes_SS_fo_noiso_v5_isLoaded = false;
		passes_SS_fo_looseMVA_v5_isLoaded = false;
		passes_SS_fo_looseMVA_noiso_v5_isLoaded = false;
		passes_SS_veto_v5_isLoaded = false;
		passes_SS_veto_noiso_v5_isLoaded = false;
		passes_WW_medium_v2_isLoaded = false;
		passes_WW_medium_noiso_v2_isLoaded = false;
		passes_WW_fo_v2_isLoaded = false;
		passes_WW_fo_noiso_v2_isLoaded = false;
		passes_WW_veto_v2_isLoaded = false;
		passes_WW_veto_noiso_v2_isLoaded = false;
		passes_HAD_veto_v3_isLoaded = false;
		passes_HAD_veto_noiso_v3_isLoaded = false;
		passes_HAD_loose_v3_isLoaded = false;
		passes_HAD_loose_noiso_v3_isLoaded = false;
		passes_POG_vetoID_isLoaded = false;
		passes_POG_looseID_isLoaded = false;
		passes_POG_mediumID_isLoaded = false;
		passes_POG_tightID_isLoaded = false;
		ip3d_isLoaded = false;
		ip3derr_isLoaded = false;
		type_isLoaded = false;
		mt_isLoaded = false;
		ptrelv0_isLoaded = false;
		ptrelv1_isLoaded = false;
		miniiso_isLoaded = false;
		miniisoDB_isLoaded = false;
		reliso04_isLoaded = false;
		annulus04_isLoaded = false;
		AbsTrkIso_isLoaded = false;
		TrkAn04_isLoaded = false;
		iso03sumPt_isLoaded = false;
		iso03emEt_isLoaded = false;
		iso03hadEt_isLoaded = false;
		jet_close_lep_idx_isLoaded = false;
		jet_close_lep_isLoaded = false;
		jet_close_lep_undoJEC_isLoaded = false;
		jet_close_lep_area_isLoaded = false;
		jet_close_L1_isLoaded = false;
		jet_close_L1nc_isLoaded = false;
		jet_close_L1ncmc_isLoaded = false;
		jet_close_L1L2L3_isLoaded = false;
		jet_close_L2L3_isLoaded = false;
		ptratio_isLoaded = false;
		tag_charge_isLoaded = false;
		tag_mc_motherid_isLoaded = false;
		tag_eSeed_isLoaded = false;
		tag_eSCRaw_isLoaded = false;
		tag_eSC_isLoaded = false;
		tag_ecalEnergy_isLoaded = false;
		exp_innerlayers_isLoaded = false;
		exp_outerlayers_isLoaded = false;
		tag_HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded = false;
		tag_HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded = false;
		tag_HLT_IsoMu24_isLoaded = false;
		tag_HLT_IsoTkMu24_isLoaded = false;
		dilep_mass_isLoaded = false;
		isRandom_isLoaded = false;
		sigmaIEtaIEta_full5x5_isLoaded = false;
		sigmaIEtaIEta_isLoaded = false;
		etaSC_isLoaded = false;
		dEtaIn_isLoaded = false;
		dPhiIn_isLoaded = false;
		hOverE_isLoaded = false;
		eSeed_isLoaded = false;
		scSeedEta_isLoaded = false;
		ecalEnergy_isLoaded = false;
		eOverPIn_isLoaded = false;
		conv_vtx_flag_isLoaded = false;
		charge_isLoaded = false;
		sccharge_isLoaded = false;
		ckf_charge_isLoaded = false;
		threeChargeAgree_isLoaded = false;
		mva_isLoaded = false;
		mva_25ns_isLoaded = false;
		tag_mva_25ns_isLoaded = false;
		ecalIso_isLoaded = false;
		hcalIso_isLoaded = false;
		ecalPFClusterIso_isLoaded = false;
		hcalPFClusterIso_isLoaded = false;
		ckf_laywithmeas_isLoaded = false;
		sigmaIPhiIPhi_full5x5_isLoaded = false;
		e1x5_full5x5_isLoaded = false;
		e5x5_full5x5_isLoaded = false;
		r9_full5x5_isLoaded = false;
		tag_r9_full5x5_isLoaded = false;
		etaSCwidth_isLoaded = false;
		phiSCwidth_isLoaded = false;
		eSCRaw_isLoaded = false;
		eSC_isLoaded = false;
		eSCPresh_isLoaded = false;
		ckf_chi2_isLoaded = false;
		ckf_ndof_isLoaded = false;
		chi2_isLoaded = false;
		ndof_isLoaded = false;
		fbrem_isLoaded = false;
		eOverPOut_isLoaded = false;
		dEtaOut_isLoaded = false;
		dPhiOut_isLoaded = false;
		gsf_validHits_isLoaded = false;
		conv_vtx_prob_isLoaded = false;
		pid_PFMuon_isLoaded = false;
		gfit_chi2_isLoaded = false;
		gfit_validSTAHits_isLoaded = false;
		numberOfMatchedStations_isLoaded = false;
		validPixelHits_isLoaded = false;
		nlayers_isLoaded = false;
		chi2LocalPosition_isLoaded = false;
		trkKink_isLoaded = false;
		validHits_isLoaded = false;
		lostHits_isLoaded = false;
		segmCompatibility_isLoaded = false;
		HLT_Mu8_isLoaded = false;
		HLT_Mu17_isLoaded = false;
		HLT_Mu8_TrkIsoVVL_isLoaded = false;
		HLT_Mu17_TrkIsoVVL_isLoaded = false;
		HLT_IsoMu24_isLoaded = false;
		HLT_IsoTkMu24_isLoaded = false;
		HLT_Mu50_isLoaded = false;
		HLT_Mu55_isLoaded = false;
		HLT_TkMu50_isLoaded = false;
		HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded = false;
		HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded = false;
		HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded = false;
		HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded = false;
		HLT_Ele8_CaloIdM_TrackIdM_PFJet30_isLoaded = false;
		HLT_Ele12_CaloIdM_TrackIdM_PFJet30_isLoaded = false;
		HLT_Ele17_CaloIdM_TrackIdM_PFJet30_isLoaded = false;
		HLT_Ele23_CaloIdM_TrackIdM_PFJet30_isLoaded = false;
		HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = false;
		HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = false;
		HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = false;
		HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = false;
		HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded = false;
		HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded = false;
		HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded = false;
		HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded = false;
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded = false;
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded = false;
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded = false;
		HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded = false;
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded = false;
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded = false;
		HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
	}

void leptree_v0::LoadAllBranches() 
	// load all branches
{
	if (evt_pfmet_branch != 0) evt_pfmet();
	if (evt_pfmetPhi_branch != 0) evt_pfmetPhi();
	if (evt_trackmet_branch != 0) evt_trackmet();
	if (evt_trackmetPhi_branch != 0) evt_trackmetPhi();
	if (evt_corrMET_branch != 0) evt_corrMET();
	if (evt_corrMETPhi_branch != 0) evt_corrMETPhi();
	if (evt_pfsumet_branch != 0) evt_pfsumet();
	if (evt_pfmetSig_branch != 0) evt_pfmetSig();
	if (evt_event_branch != 0) evt_event();
	if (evt_lumiBlock_branch != 0) evt_lumiBlock();
	if (evt_run_branch != 0) evt_run();
	if (filt_csc_branch != 0) filt_csc();
	if (filt_hbhe_branch != 0) filt_hbhe();
	if (passes_met_filters_branch != 0) passes_met_filters();
	if (filt_hcallaser_branch != 0) filt_hcallaser();
	if (filt_ecaltp_branch != 0) filt_ecaltp();
	if (filt_trkfail_branch != 0) filt_trkfail();
	if (filt_eebadsc_branch != 0) filt_eebadsc();
	if (evt_isRealData_branch != 0) evt_isRealData();
	if (scale1fb_branch != 0) scale1fb();
	if (evt_xsec_incl_branch != 0) evt_xsec_incl();
	if (evt_kfactor_branch != 0) evt_kfactor();
	if (gen_met_branch != 0) gen_met();
	if (gen_metPhi_branch != 0) gen_metPhi();
	if (njets_branch != 0) njets();
	if (ht_branch != 0) ht();
	if (ht_SS_branch != 0) ht_SS();
	if (jets_branch != 0) jets();
	if (jets_disc_branch != 0) jets_disc();
	if (jets_area_branch != 0) jets_area();
	if (jets_undoJEC_branch != 0) jets_undoJEC();
	if (sample_branch != 0) sample();
	if (nFOs_SS_branch != 0) nFOs_SS();
	if (nvtx_branch != 0) nvtx();
	if (rho_branch != 0) rho();
	if (rho_neut_centr_branch != 0) rho_neut_centr();
	if (rho_calo_branch != 0) rho_calo();
	if (rho_calo_centr_branch != 0) rho_calo_centr();
	if (p4_branch != 0) p4();
	if (tag_p4_branch != 0) tag_p4();
	if (dilep_p4_branch != 0) dilep_p4();
	if (mc_p4_branch != 0) mc_p4();
	if (mc_motherp4_branch != 0) mc_motherp4();
	if (mc_motherid_branch != 0) mc_motherid();
	if (id_branch != 0) id();
	if (isPF_branch != 0) isPF();
	if (idx_branch != 0) idx();
	if (dxyPV_branch != 0) dxyPV();
	if (dZ_branch != 0) dZ();
	if (dxyPV_err_branch != 0) dxyPV_err();
	if (motherID_branch != 0) motherID();
	if (mc_id_branch != 0) mc_id();
	if (RelIso03_branch != 0) RelIso03();
	if (RelIso03EA_branch != 0) RelIso03EA();
	if (tag_RelIso03EA_branch != 0) tag_RelIso03EA();
	if (RelIso03DB_branch != 0) RelIso03DB();
	if (pfChargedHadronIso_branch != 0) pfChargedHadronIso();
	if (pfPhotonIso_branch != 0) pfPhotonIso();
	if (pfNeutralHadronIso_branch != 0) pfNeutralHadronIso();
	if (tkIso_branch != 0) tkIso();
	if (sumPUPt_branch != 0) sumPUPt();
	if (passes_SS_tight_v3_branch != 0) passes_SS_tight_v3();
	if (passes_SS_tight_noiso_v3_branch != 0) passes_SS_tight_noiso_v3();
	if (passes_SS_fo_v3_branch != 0) passes_SS_fo_v3();
	if (passes_SS_fo_noiso_v3_branch != 0) passes_SS_fo_noiso_v3();
	if (passes_SS_fo_looseMVA_v3_branch != 0) passes_SS_fo_looseMVA_v3();
	if (passes_SS_fo_looseMVA_noiso_v3_branch != 0) passes_SS_fo_looseMVA_noiso_v3();
	if (passes_SS_veto_v3_branch != 0) passes_SS_veto_v3();
	if (passes_SS_veto_noiso_v3_branch != 0) passes_SS_veto_noiso_v3();
	if (passes_SS_tight_v4_branch != 0) passes_SS_tight_v4();
	if (passes_SS_tight_noiso_v4_branch != 0) passes_SS_tight_noiso_v4();
	if (passes_SS_fo_v4_branch != 0) passes_SS_fo_v4();
	if (passes_SS_fo_noiso_v4_branch != 0) passes_SS_fo_noiso_v4();
	if (passes_SS_fo_looseMVA_v4_branch != 0) passes_SS_fo_looseMVA_v4();
	if (passes_SS_fo_looseMVA_noiso_v4_branch != 0) passes_SS_fo_looseMVA_noiso_v4();
	if (passes_SS_veto_v4_branch != 0) passes_SS_veto_v4();
	if (passes_SS_veto_noiso_v4_branch != 0) passes_SS_veto_noiso_v4();
	if (passes_SS_tight_v5_branch != 0) passes_SS_tight_v5();
	if (passes_SS_tight_noiso_v5_branch != 0) passes_SS_tight_noiso_v5();
	if (passes_SS_fo_v5_branch != 0) passes_SS_fo_v5();
	if (passes_SS_fo_noiso_v5_branch != 0) passes_SS_fo_noiso_v5();
	if (passes_SS_fo_looseMVA_v5_branch != 0) passes_SS_fo_looseMVA_v5();
	if (passes_SS_fo_looseMVA_noiso_v5_branch != 0) passes_SS_fo_looseMVA_noiso_v5();
	if (passes_SS_veto_v5_branch != 0) passes_SS_veto_v5();
	if (passes_SS_veto_noiso_v5_branch != 0) passes_SS_veto_noiso_v5();
	if (passes_WW_medium_v2_branch != 0) passes_WW_medium_v2();
	if (passes_WW_medium_noiso_v2_branch != 0) passes_WW_medium_noiso_v2();
	if (passes_WW_fo_v2_branch != 0) passes_WW_fo_v2();
	if (passes_WW_fo_noiso_v2_branch != 0) passes_WW_fo_noiso_v2();
	if (passes_WW_veto_v2_branch != 0) passes_WW_veto_v2();
	if (passes_WW_veto_noiso_v2_branch != 0) passes_WW_veto_noiso_v2();
	if (passes_HAD_veto_v3_branch != 0) passes_HAD_veto_v3();
	if (passes_HAD_veto_noiso_v3_branch != 0) passes_HAD_veto_noiso_v3();
	if (passes_HAD_loose_v3_branch != 0) passes_HAD_loose_v3();
	if (passes_HAD_loose_noiso_v3_branch != 0) passes_HAD_loose_noiso_v3();
	if (passes_POG_vetoID_branch != 0) passes_POG_vetoID();
	if (passes_POG_looseID_branch != 0) passes_POG_looseID();
	if (passes_POG_mediumID_branch != 0) passes_POG_mediumID();
	if (passes_POG_tightID_branch != 0) passes_POG_tightID();
	if (ip3d_branch != 0) ip3d();
	if (ip3derr_branch != 0) ip3derr();
	if (type_branch != 0) type();
	if (mt_branch != 0) mt();
	if (ptrelv0_branch != 0) ptrelv0();
	if (ptrelv1_branch != 0) ptrelv1();
	if (miniiso_branch != 0) miniiso();
	if (miniisoDB_branch != 0) miniisoDB();
	if (reliso04_branch != 0) reliso04();
	if (annulus04_branch != 0) annulus04();
	if (AbsTrkIso_branch != 0) AbsTrkIso();
	if (TrkAn04_branch != 0) TrkAn04();
	if (iso03sumPt_branch != 0) iso03sumPt();
	if (iso03emEt_branch != 0) iso03emEt();
	if (iso03hadEt_branch != 0) iso03hadEt();
	if (jet_close_lep_idx_branch != 0) jet_close_lep_idx();
	if (jet_close_lep_branch != 0) jet_close_lep();
	if (jet_close_lep_undoJEC_branch != 0) jet_close_lep_undoJEC();
	if (jet_close_lep_area_branch != 0) jet_close_lep_area();
	if (jet_close_L1_branch != 0) jet_close_L1();
	if (jet_close_L1nc_branch != 0) jet_close_L1nc();
	if (jet_close_L1ncmc_branch != 0) jet_close_L1ncmc();
	if (jet_close_L1L2L3_branch != 0) jet_close_L1L2L3();
	if (jet_close_L2L3_branch != 0) jet_close_L2L3();
	if (ptratio_branch != 0) ptratio();
	if (tag_charge_branch != 0) tag_charge();
	if (tag_mc_motherid_branch != 0) tag_mc_motherid();
	if (tag_eSeed_branch != 0) tag_eSeed();
	if (tag_eSCRaw_branch != 0) tag_eSCRaw();
	if (tag_eSC_branch != 0) tag_eSC();
	if (tag_ecalEnergy_branch != 0) tag_ecalEnergy();
	if (exp_innerlayers_branch != 0) exp_innerlayers();
	if (exp_outerlayers_branch != 0) exp_outerlayers();
	if (tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch != 0) tag_HLT_Ele27_eta2p1_WPTight_Gsf();
	if (tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch != 0) tag_HLT_Ele32_eta2p1_WPTight_Gsf();
	if (tag_HLT_IsoMu24_branch != 0) tag_HLT_IsoMu24();
	if (tag_HLT_IsoTkMu24_branch != 0) tag_HLT_IsoTkMu24();
	if (dilep_mass_branch != 0) dilep_mass();
	if (isRandom_branch != 0) isRandom();
	if (sigmaIEtaIEta_full5x5_branch != 0) sigmaIEtaIEta_full5x5();
	if (sigmaIEtaIEta_branch != 0) sigmaIEtaIEta();
	if (etaSC_branch != 0) etaSC();
	if (dEtaIn_branch != 0) dEtaIn();
	if (dPhiIn_branch != 0) dPhiIn();
	if (hOverE_branch != 0) hOverE();
	if (eSeed_branch != 0) eSeed();
	if (scSeedEta_branch != 0) scSeedEta();
	if (ecalEnergy_branch != 0) ecalEnergy();
	if (eOverPIn_branch != 0) eOverPIn();
	if (conv_vtx_flag_branch != 0) conv_vtx_flag();
	if (charge_branch != 0) charge();
	if (sccharge_branch != 0) sccharge();
	if (ckf_charge_branch != 0) ckf_charge();
	if (threeChargeAgree_branch != 0) threeChargeAgree();
	if (mva_branch != 0) mva();
	if (mva_25ns_branch != 0) mva_25ns();
	if (tag_mva_25ns_branch != 0) tag_mva_25ns();
	if (ecalIso_branch != 0) ecalIso();
	if (hcalIso_branch != 0) hcalIso();
	if (ecalPFClusterIso_branch != 0) ecalPFClusterIso();
	if (hcalPFClusterIso_branch != 0) hcalPFClusterIso();
	if (ckf_laywithmeas_branch != 0) ckf_laywithmeas();
	if (sigmaIPhiIPhi_full5x5_branch != 0) sigmaIPhiIPhi_full5x5();
	if (e1x5_full5x5_branch != 0) e1x5_full5x5();
	if (e5x5_full5x5_branch != 0) e5x5_full5x5();
	if (r9_full5x5_branch != 0) r9_full5x5();
	if (tag_r9_full5x5_branch != 0) tag_r9_full5x5();
	if (etaSCwidth_branch != 0) etaSCwidth();
	if (phiSCwidth_branch != 0) phiSCwidth();
	if (eSCRaw_branch != 0) eSCRaw();
	if (eSC_branch != 0) eSC();
	if (eSCPresh_branch != 0) eSCPresh();
	if (ckf_chi2_branch != 0) ckf_chi2();
	if (ckf_ndof_branch != 0) ckf_ndof();
	if (chi2_branch != 0) chi2();
	if (ndof_branch != 0) ndof();
	if (fbrem_branch != 0) fbrem();
	if (eOverPOut_branch != 0) eOverPOut();
	if (dEtaOut_branch != 0) dEtaOut();
	if (dPhiOut_branch != 0) dPhiOut();
	if (gsf_validHits_branch != 0) gsf_validHits();
	if (conv_vtx_prob_branch != 0) conv_vtx_prob();
	if (pid_PFMuon_branch != 0) pid_PFMuon();
	if (gfit_chi2_branch != 0) gfit_chi2();
	if (gfit_validSTAHits_branch != 0) gfit_validSTAHits();
	if (numberOfMatchedStations_branch != 0) numberOfMatchedStations();
	if (validPixelHits_branch != 0) validPixelHits();
	if (nlayers_branch != 0) nlayers();
	if (chi2LocalPosition_branch != 0) chi2LocalPosition();
	if (trkKink_branch != 0) trkKink();
	if (validHits_branch != 0) validHits();
	if (lostHits_branch != 0) lostHits();
	if (segmCompatibility_branch != 0) segmCompatibility();
	if (HLT_Mu8_branch != 0) HLT_Mu8();
	if (HLT_Mu17_branch != 0) HLT_Mu17();
	if (HLT_Mu8_TrkIsoVVL_branch != 0) HLT_Mu8_TrkIsoVVL();
	if (HLT_Mu17_TrkIsoVVL_branch != 0) HLT_Mu17_TrkIsoVVL();
	if (HLT_IsoMu24_branch != 0) HLT_IsoMu24();
	if (HLT_IsoTkMu24_branch != 0) HLT_IsoTkMu24();
	if (HLT_Mu50_branch != 0) HLT_Mu50();
	if (HLT_Mu55_branch != 0) HLT_Mu55();
	if (HLT_TkMu50_branch != 0) HLT_TkMu50();
	if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch != 0) HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg();
	if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch != 0) HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg();
	if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch != 0) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg();
	if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch != 0) HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg();
	if (HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch != 0) HLT_Ele8_CaloIdM_TrackIdM_PFJet30();
	if (HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch != 0) HLT_Ele12_CaloIdM_TrackIdM_PFJet30();
	if (HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch != 0) HLT_Ele17_CaloIdM_TrackIdM_PFJet30();
	if (HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch != 0) HLT_Ele23_CaloIdM_TrackIdM_PFJet30();
	if (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30();
	if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30();
	if (HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30();
	if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30();
	if (HLT_Ele27_eta2p1_WPTight_Gsf_branch != 0) HLT_Ele27_eta2p1_WPTight_Gsf();
	if (HLT_Ele32_eta2p1_WPTight_Gsf_branch != 0) HLT_Ele32_eta2p1_WPTight_Gsf();
	if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch != 0) HLT_Ele105_CaloIdVT_GsfTrkIdT();
	if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch != 0) HLT_Ele115_CaloIdVT_GsfTrkIdT();
	if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch != 0) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg();
	if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch != 0) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg();
	if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch != 0) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1();
	if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
	if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch != 0) HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg();
	if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch != 0) HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg();
	if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch != 0) HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1();
	if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL();
}

	const float &leptree_v0::evt_pfmet()
	{
		if (not evt_pfmet_isLoaded) {
			if (evt_pfmet_branch != 0) {
				evt_pfmet_branch->GetEntry(index);
			} else { 
				printf("branch evt_pfmet_branch does not exist!\n");
				exit(1);
			}
			evt_pfmet_isLoaded = true;
		}
		return evt_pfmet_;
	}
	const float &leptree_v0::evt_pfmetPhi()
	{
		if (not evt_pfmetPhi_isLoaded) {
			if (evt_pfmetPhi_branch != 0) {
				evt_pfmetPhi_branch->GetEntry(index);
			} else { 
				printf("branch evt_pfmetPhi_branch does not exist!\n");
				exit(1);
			}
			evt_pfmetPhi_isLoaded = true;
		}
		return evt_pfmetPhi_;
	}
	const float &leptree_v0::evt_trackmet()
	{
		if (not evt_trackmet_isLoaded) {
			if (evt_trackmet_branch != 0) {
				evt_trackmet_branch->GetEntry(index);
			} else { 
				printf("branch evt_trackmet_branch does not exist!\n");
				exit(1);
			}
			evt_trackmet_isLoaded = true;
		}
		return evt_trackmet_;
	}
	const float &leptree_v0::evt_trackmetPhi()
	{
		if (not evt_trackmetPhi_isLoaded) {
			if (evt_trackmetPhi_branch != 0) {
				evt_trackmetPhi_branch->GetEntry(index);
			} else { 
				printf("branch evt_trackmetPhi_branch does not exist!\n");
				exit(1);
			}
			evt_trackmetPhi_isLoaded = true;
		}
		return evt_trackmetPhi_;
	}
	const float &leptree_v0::evt_corrMET()
	{
		if (not evt_corrMET_isLoaded) {
			if (evt_corrMET_branch != 0) {
				evt_corrMET_branch->GetEntry(index);
			} else { 
				printf("branch evt_corrMET_branch does not exist!\n");
				exit(1);
			}
			evt_corrMET_isLoaded = true;
		}
		return evt_corrMET_;
	}
	const float &leptree_v0::evt_corrMETPhi()
	{
		if (not evt_corrMETPhi_isLoaded) {
			if (evt_corrMETPhi_branch != 0) {
				evt_corrMETPhi_branch->GetEntry(index);
			} else { 
				printf("branch evt_corrMETPhi_branch does not exist!\n");
				exit(1);
			}
			evt_corrMETPhi_isLoaded = true;
		}
		return evt_corrMETPhi_;
	}
	const float &leptree_v0::evt_pfsumet()
	{
		if (not evt_pfsumet_isLoaded) {
			if (evt_pfsumet_branch != 0) {
				evt_pfsumet_branch->GetEntry(index);
			} else { 
				printf("branch evt_pfsumet_branch does not exist!\n");
				exit(1);
			}
			evt_pfsumet_isLoaded = true;
		}
		return evt_pfsumet_;
	}
	const float &leptree_v0::evt_pfmetSig()
	{
		if (not evt_pfmetSig_isLoaded) {
			if (evt_pfmetSig_branch != 0) {
				evt_pfmetSig_branch->GetEntry(index);
			} else { 
				printf("branch evt_pfmetSig_branch does not exist!\n");
				exit(1);
			}
			evt_pfmetSig_isLoaded = true;
		}
		return evt_pfmetSig_;
	}
	const int &leptree_v0::evt_event()
	{
		if (not evt_event_isLoaded) {
			if (evt_event_branch != 0) {
				evt_event_branch->GetEntry(index);
			} else { 
				printf("branch evt_event_branch does not exist!\n");
				exit(1);
			}
			evt_event_isLoaded = true;
		}
		return evt_event_;
	}
	const int &leptree_v0::evt_lumiBlock()
	{
		if (not evt_lumiBlock_isLoaded) {
			if (evt_lumiBlock_branch != 0) {
				evt_lumiBlock_branch->GetEntry(index);
			} else { 
				printf("branch evt_lumiBlock_branch does not exist!\n");
				exit(1);
			}
			evt_lumiBlock_isLoaded = true;
		}
		return evt_lumiBlock_;
	}
	const int &leptree_v0::evt_run()
	{
		if (not evt_run_isLoaded) {
			if (evt_run_branch != 0) {
				evt_run_branch->GetEntry(index);
			} else { 
				printf("branch evt_run_branch does not exist!\n");
				exit(1);
			}
			evt_run_isLoaded = true;
		}
		return evt_run_;
	}
	const bool &	leptree_v0::filt_csc()
	{
		if (not filt_csc_isLoaded) {
			if (filt_csc_branch != 0) {
				filt_csc_branch->GetEntry(index);
			} else { 
				printf("branch filt_csc_branch does not exist!\n");
				exit(1);
			}
			filt_csc_isLoaded = true;
		}
		return filt_csc_;
	}
	const bool &	leptree_v0::filt_hbhe()
	{
		if (not filt_hbhe_isLoaded) {
			if (filt_hbhe_branch != 0) {
				filt_hbhe_branch->GetEntry(index);
			} else { 
				printf("branch filt_hbhe_branch does not exist!\n");
				exit(1);
			}
			filt_hbhe_isLoaded = true;
		}
		return filt_hbhe_;
	}
	const bool &	leptree_v0::passes_met_filters()
	{
		if (not passes_met_filters_isLoaded) {
			if (passes_met_filters_branch != 0) {
				passes_met_filters_branch->GetEntry(index);
			} else { 
				printf("branch passes_met_filters_branch does not exist!\n");
				exit(1);
			}
			passes_met_filters_isLoaded = true;
		}
		return passes_met_filters_;
	}
	const bool &	leptree_v0::filt_hcallaser()
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
	const bool &	leptree_v0::filt_ecaltp()
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
	const bool &	leptree_v0::filt_trkfail()
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
	const bool &	leptree_v0::filt_eebadsc()
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
	const bool &	leptree_v0::evt_isRealData()
	{
		if (not evt_isRealData_isLoaded) {
			if (evt_isRealData_branch != 0) {
				evt_isRealData_branch->GetEntry(index);
			} else { 
				printf("branch evt_isRealData_branch does not exist!\n");
				exit(1);
			}
			evt_isRealData_isLoaded = true;
		}
		return evt_isRealData_;
	}
	const float &leptree_v0::scale1fb()
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
	const float &leptree_v0::evt_xsec_incl()
	{
		if (not evt_xsec_incl_isLoaded) {
			if (evt_xsec_incl_branch != 0) {
				evt_xsec_incl_branch->GetEntry(index);
			} else { 
				printf("branch evt_xsec_incl_branch does not exist!\n");
				exit(1);
			}
			evt_xsec_incl_isLoaded = true;
		}
		return evt_xsec_incl_;
	}
	const float &leptree_v0::evt_kfactor()
	{
		if (not evt_kfactor_isLoaded) {
			if (evt_kfactor_branch != 0) {
				evt_kfactor_branch->GetEntry(index);
			} else { 
				printf("branch evt_kfactor_branch does not exist!\n");
				exit(1);
			}
			evt_kfactor_isLoaded = true;
		}
		return evt_kfactor_;
	}
	const float &leptree_v0::gen_met()
	{
		if (not gen_met_isLoaded) {
			if (gen_met_branch != 0) {
				gen_met_branch->GetEntry(index);
			} else { 
				printf("branch gen_met_branch does not exist!\n");
				exit(1);
			}
			gen_met_isLoaded = true;
		}
		return gen_met_;
	}
	const float &leptree_v0::gen_metPhi()
	{
		if (not gen_metPhi_isLoaded) {
			if (gen_metPhi_branch != 0) {
				gen_metPhi_branch->GetEntry(index);
			} else { 
				printf("branch gen_metPhi_branch does not exist!\n");
				exit(1);
			}
			gen_metPhi_isLoaded = true;
		}
		return gen_metPhi_;
	}
	const float &leptree_v0::njets()
	{
		if (not njets_isLoaded) {
			if (njets_branch != 0) {
				njets_branch->GetEntry(index);
			} else { 
				printf("branch njets_branch does not exist!\n");
				exit(1);
			}
			njets_isLoaded = true;
		}
		return njets_;
	}
	const float &leptree_v0::ht()
	{
		if (not ht_isLoaded) {
			if (ht_branch != 0) {
				ht_branch->GetEntry(index);
			} else { 
				printf("branch ht_branch does not exist!\n");
				exit(1);
			}
			ht_isLoaded = true;
		}
		return ht_;
	}
	const float &leptree_v0::ht_SS()
	{
		if (not ht_SS_isLoaded) {
			if (ht_SS_branch != 0) {
				ht_SS_branch->GetEntry(index);
			} else { 
				printf("branch ht_SS_branch does not exist!\n");
				exit(1);
			}
			ht_SS_isLoaded = true;
		}
		return ht_SS_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &leptree_v0::jets()
	{
		if (not jets_isLoaded) {
			if (jets_branch != 0) {
				jets_branch->GetEntry(index);
			} else { 
				printf("branch jets_branch does not exist!\n");
				exit(1);
			}
			jets_isLoaded = true;
		}
		return *jets_;
	}
	const vector<float> &leptree_v0::jets_disc()
	{
		if (not jets_disc_isLoaded) {
			if (jets_disc_branch != 0) {
				jets_disc_branch->GetEntry(index);
			} else { 
				printf("branch jets_disc_branch does not exist!\n");
				exit(1);
			}
			jets_disc_isLoaded = true;
		}
		return *jets_disc_;
	}
	const vector<float> &leptree_v0::jets_area()
	{
		if (not jets_area_isLoaded) {
			if (jets_area_branch != 0) {
				jets_area_branch->GetEntry(index);
			} else { 
				printf("branch jets_area_branch does not exist!\n");
				exit(1);
			}
			jets_area_isLoaded = true;
		}
		return *jets_area_;
	}
	const vector<float> &leptree_v0::jets_undoJEC()
	{
		if (not jets_undoJEC_isLoaded) {
			if (jets_undoJEC_branch != 0) {
				jets_undoJEC_branch->GetEntry(index);
			} else { 
				printf("branch jets_undoJEC_branch does not exist!\n");
				exit(1);
			}
			jets_undoJEC_isLoaded = true;
		}
		return *jets_undoJEC_;
	}
	const TString &leptree_v0::sample()
	{
		if (not sample_isLoaded) {
			if (sample_branch != 0) {
				sample_branch->GetEntry(index);
			} else { 
				printf("branch sample_branch does not exist!\n");
				exit(1);
			}
			sample_isLoaded = true;
		}
		return *sample_;
	}
	const int &leptree_v0::nFOs_SS()
	{
		if (not nFOs_SS_isLoaded) {
			if (nFOs_SS_branch != 0) {
				nFOs_SS_branch->GetEntry(index);
			} else { 
				printf("branch nFOs_SS_branch does not exist!\n");
				exit(1);
			}
			nFOs_SS_isLoaded = true;
		}
		return nFOs_SS_;
	}
	const int &leptree_v0::nvtx()
	{
		if (not nvtx_isLoaded) {
			if (nvtx_branch != 0) {
				nvtx_branch->GetEntry(index);
			} else { 
				printf("branch nvtx_branch does not exist!\n");
				exit(1);
			}
			nvtx_isLoaded = true;
		}
		return nvtx_;
	}
	const float &leptree_v0::rho()
	{
		if (not rho_isLoaded) {
			if (rho_branch != 0) {
				rho_branch->GetEntry(index);
			} else { 
				printf("branch rho_branch does not exist!\n");
				exit(1);
			}
			rho_isLoaded = true;
		}
		return rho_;
	}
	const float &leptree_v0::rho_neut_centr()
	{
		if (not rho_neut_centr_isLoaded) {
			if (rho_neut_centr_branch != 0) {
				rho_neut_centr_branch->GetEntry(index);
			} else { 
				printf("branch rho_neut_centr_branch does not exist!\n");
				exit(1);
			}
			rho_neut_centr_isLoaded = true;
		}
		return rho_neut_centr_;
	}
	const float &leptree_v0::rho_calo()
	{
		if (not rho_calo_isLoaded) {
			if (rho_calo_branch != 0) {
				rho_calo_branch->GetEntry(index);
			} else { 
				printf("branch rho_calo_branch does not exist!\n");
				exit(1);
			}
			rho_calo_isLoaded = true;
		}
		return rho_calo_;
	}
	const float &leptree_v0::rho_calo_centr()
	{
		if (not rho_calo_centr_isLoaded) {
			if (rho_calo_centr_branch != 0) {
				rho_calo_centr_branch->GetEntry(index);
			} else { 
				printf("branch rho_calo_centr_branch does not exist!\n");
				exit(1);
			}
			rho_calo_centr_isLoaded = true;
		}
		return rho_calo_centr_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::p4()
	{
		if (not p4_isLoaded) {
			if (p4_branch != 0) {
				p4_branch->GetEntry(index);
			} else { 
				printf("branch p4_branch does not exist!\n");
				exit(1);
			}
			p4_isLoaded = true;
		}
		return *p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::tag_p4()
	{
		if (not tag_p4_isLoaded) {
			if (tag_p4_branch != 0) {
				tag_p4_branch->GetEntry(index);
			} else { 
				printf("branch tag_p4_branch does not exist!\n");
				exit(1);
			}
			tag_p4_isLoaded = true;
		}
		return *tag_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::dilep_p4()
	{
		if (not dilep_p4_isLoaded) {
			if (dilep_p4_branch != 0) {
				dilep_p4_branch->GetEntry(index);
			} else { 
				printf("branch dilep_p4_branch does not exist!\n");
				exit(1);
			}
			dilep_p4_isLoaded = true;
		}
		return *dilep_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::mc_p4()
	{
		if (not mc_p4_isLoaded) {
			if (mc_p4_branch != 0) {
				mc_p4_branch->GetEntry(index);
			} else { 
				printf("branch mc_p4_branch does not exist!\n");
				exit(1);
			}
			mc_p4_isLoaded = true;
		}
		return *mc_p4_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::mc_motherp4()
	{
		if (not mc_motherp4_isLoaded) {
			if (mc_motherp4_branch != 0) {
				mc_motherp4_branch->GetEntry(index);
			} else { 
				printf("branch mc_motherp4_branch does not exist!\n");
				exit(1);
			}
			mc_motherp4_isLoaded = true;
		}
		return *mc_motherp4_;
	}
	const int &leptree_v0::mc_motherid()
	{
		if (not mc_motherid_isLoaded) {
			if (mc_motherid_branch != 0) {
				mc_motherid_branch->GetEntry(index);
			} else { 
				printf("branch mc_motherid_branch does not exist!\n");
				exit(1);
			}
			mc_motherid_isLoaded = true;
		}
		return mc_motherid_;
	}
	const int &leptree_v0::id()
	{
		if (not id_isLoaded) {
			if (id_branch != 0) {
				id_branch->GetEntry(index);
			} else { 
				printf("branch id_branch does not exist!\n");
				exit(1);
			}
			id_isLoaded = true;
		}
		return id_;
	}
	const bool &	leptree_v0::isPF()
	{
		if (not isPF_isLoaded) {
			if (isPF_branch != 0) {
				isPF_branch->GetEntry(index);
			} else { 
				printf("branch isPF_branch does not exist!\n");
				exit(1);
			}
			isPF_isLoaded = true;
		}
		return isPF_;
	}
	const int &leptree_v0::idx()
	{
		if (not idx_isLoaded) {
			if (idx_branch != 0) {
				idx_branch->GetEntry(index);
			} else { 
				printf("branch idx_branch does not exist!\n");
				exit(1);
			}
			idx_isLoaded = true;
		}
		return idx_;
	}
	const float &leptree_v0::dxyPV()
	{
		if (not dxyPV_isLoaded) {
			if (dxyPV_branch != 0) {
				dxyPV_branch->GetEntry(index);
			} else { 
				printf("branch dxyPV_branch does not exist!\n");
				exit(1);
			}
			dxyPV_isLoaded = true;
		}
		return dxyPV_;
	}
	const float &leptree_v0::dZ()
	{
		if (not dZ_isLoaded) {
			if (dZ_branch != 0) {
				dZ_branch->GetEntry(index);
			} else { 
				printf("branch dZ_branch does not exist!\n");
				exit(1);
			}
			dZ_isLoaded = true;
		}
		return dZ_;
	}
	const float &leptree_v0::dxyPV_err()
	{
		if (not dxyPV_err_isLoaded) {
			if (dxyPV_err_branch != 0) {
				dxyPV_err_branch->GetEntry(index);
			} else { 
				printf("branch dxyPV_err_branch does not exist!\n");
				exit(1);
			}
			dxyPV_err_isLoaded = true;
		}
		return dxyPV_err_;
	}
	const int &leptree_v0::motherID()
	{
		if (not motherID_isLoaded) {
			if (motherID_branch != 0) {
				motherID_branch->GetEntry(index);
			} else { 
				printf("branch motherID_branch does not exist!\n");
				exit(1);
			}
			motherID_isLoaded = true;
		}
		return motherID_;
	}
	const int &leptree_v0::mc_id()
	{
		if (not mc_id_isLoaded) {
			if (mc_id_branch != 0) {
				mc_id_branch->GetEntry(index);
			} else { 
				printf("branch mc_id_branch does not exist!\n");
				exit(1);
			}
			mc_id_isLoaded = true;
		}
		return mc_id_;
	}
	const float &leptree_v0::RelIso03()
	{
		if (not RelIso03_isLoaded) {
			if (RelIso03_branch != 0) {
				RelIso03_branch->GetEntry(index);
			} else { 
				printf("branch RelIso03_branch does not exist!\n");
				exit(1);
			}
			RelIso03_isLoaded = true;
		}
		return RelIso03_;
	}
	const float &leptree_v0::RelIso03EA()
	{
		if (not RelIso03EA_isLoaded) {
			if (RelIso03EA_branch != 0) {
				RelIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch RelIso03EA_branch does not exist!\n");
				exit(1);
			}
			RelIso03EA_isLoaded = true;
		}
		return RelIso03EA_;
	}
	const float &leptree_v0::tag_RelIso03EA()
	{
		if (not tag_RelIso03EA_isLoaded) {
			if (tag_RelIso03EA_branch != 0) {
				tag_RelIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch tag_RelIso03EA_branch does not exist!\n");
				exit(1);
			}
			tag_RelIso03EA_isLoaded = true;
		}
		return tag_RelIso03EA_;
	}
	const float &leptree_v0::RelIso03DB()
	{
		if (not RelIso03DB_isLoaded) {
			if (RelIso03DB_branch != 0) {
				RelIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch RelIso03DB_branch does not exist!\n");
				exit(1);
			}
			RelIso03DB_isLoaded = true;
		}
		return RelIso03DB_;
	}
	const float &leptree_v0::pfChargedHadronIso()
	{
		if (not pfChargedHadronIso_isLoaded) {
			if (pfChargedHadronIso_branch != 0) {
				pfChargedHadronIso_branch->GetEntry(index);
			} else { 
				printf("branch pfChargedHadronIso_branch does not exist!\n");
				exit(1);
			}
			pfChargedHadronIso_isLoaded = true;
		}
		return pfChargedHadronIso_;
	}
	const float &leptree_v0::pfPhotonIso()
	{
		if (not pfPhotonIso_isLoaded) {
			if (pfPhotonIso_branch != 0) {
				pfPhotonIso_branch->GetEntry(index);
			} else { 
				printf("branch pfPhotonIso_branch does not exist!\n");
				exit(1);
			}
			pfPhotonIso_isLoaded = true;
		}
		return pfPhotonIso_;
	}
	const float &leptree_v0::pfNeutralHadronIso()
	{
		if (not pfNeutralHadronIso_isLoaded) {
			if (pfNeutralHadronIso_branch != 0) {
				pfNeutralHadronIso_branch->GetEntry(index);
			} else { 
				printf("branch pfNeutralHadronIso_branch does not exist!\n");
				exit(1);
			}
			pfNeutralHadronIso_isLoaded = true;
		}
		return pfNeutralHadronIso_;
	}
	const float &leptree_v0::tkIso()
	{
		if (not tkIso_isLoaded) {
			if (tkIso_branch != 0) {
				tkIso_branch->GetEntry(index);
			} else { 
				printf("branch tkIso_branch does not exist!\n");
				exit(1);
			}
			tkIso_isLoaded = true;
		}
		return tkIso_;
	}
	const float &leptree_v0::sumPUPt()
	{
		if (not sumPUPt_isLoaded) {
			if (sumPUPt_branch != 0) {
				sumPUPt_branch->GetEntry(index);
			} else { 
				printf("branch sumPUPt_branch does not exist!\n");
				exit(1);
			}
			sumPUPt_isLoaded = true;
		}
		return sumPUPt_;
	}
	const bool &	leptree_v0::passes_SS_tight_v3()
	{
		if (not passes_SS_tight_v3_isLoaded) {
			if (passes_SS_tight_v3_branch != 0) {
				passes_SS_tight_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_v3_isLoaded = true;
		}
		return passes_SS_tight_v3_;
	}
	const bool &	leptree_v0::passes_SS_tight_noiso_v3()
	{
		if (not passes_SS_tight_noiso_v3_isLoaded) {
			if (passes_SS_tight_noiso_v3_branch != 0) {
				passes_SS_tight_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_noiso_v3_isLoaded = true;
		}
		return passes_SS_tight_noiso_v3_;
	}
	const bool &	leptree_v0::passes_SS_fo_v3()
	{
		if (not passes_SS_fo_v3_isLoaded) {
			if (passes_SS_fo_v3_branch != 0) {
				passes_SS_fo_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_v3_isLoaded = true;
		}
		return passes_SS_fo_v3_;
	}
	const bool &	leptree_v0::passes_SS_fo_noiso_v3()
	{
		if (not passes_SS_fo_noiso_v3_isLoaded) {
			if (passes_SS_fo_noiso_v3_branch != 0) {
				passes_SS_fo_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_noiso_v3_isLoaded = true;
		}
		return passes_SS_fo_noiso_v3_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_v3()
	{
		if (not passes_SS_fo_looseMVA_v3_isLoaded) {
			if (passes_SS_fo_looseMVA_v3_branch != 0) {
				passes_SS_fo_looseMVA_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_v3_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_v3_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_noiso_v3()
	{
		if (not passes_SS_fo_looseMVA_noiso_v3_isLoaded) {
			if (passes_SS_fo_looseMVA_noiso_v3_branch != 0) {
				passes_SS_fo_looseMVA_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_noiso_v3_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_noiso_v3_;
	}
	const bool &	leptree_v0::passes_SS_veto_v3()
	{
		if (not passes_SS_veto_v3_isLoaded) {
			if (passes_SS_veto_v3_branch != 0) {
				passes_SS_veto_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_v3_isLoaded = true;
		}
		return passes_SS_veto_v3_;
	}
	const bool &	leptree_v0::passes_SS_veto_noiso_v3()
	{
		if (not passes_SS_veto_noiso_v3_isLoaded) {
			if (passes_SS_veto_noiso_v3_branch != 0) {
				passes_SS_veto_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_noiso_v3_isLoaded = true;
		}
		return passes_SS_veto_noiso_v3_;
	}
	const bool &	leptree_v0::passes_SS_tight_v4()
	{
		if (not passes_SS_tight_v4_isLoaded) {
			if (passes_SS_tight_v4_branch != 0) {
				passes_SS_tight_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_v4_isLoaded = true;
		}
		return passes_SS_tight_v4_;
	}
	const bool &	leptree_v0::passes_SS_tight_noiso_v4()
	{
		if (not passes_SS_tight_noiso_v4_isLoaded) {
			if (passes_SS_tight_noiso_v4_branch != 0) {
				passes_SS_tight_noiso_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_noiso_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_noiso_v4_isLoaded = true;
		}
		return passes_SS_tight_noiso_v4_;
	}
	const bool &	leptree_v0::passes_SS_fo_v4()
	{
		if (not passes_SS_fo_v4_isLoaded) {
			if (passes_SS_fo_v4_branch != 0) {
				passes_SS_fo_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_v4_isLoaded = true;
		}
		return passes_SS_fo_v4_;
	}
	const bool &	leptree_v0::passes_SS_fo_noiso_v4()
	{
		if (not passes_SS_fo_noiso_v4_isLoaded) {
			if (passes_SS_fo_noiso_v4_branch != 0) {
				passes_SS_fo_noiso_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_noiso_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_noiso_v4_isLoaded = true;
		}
		return passes_SS_fo_noiso_v4_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_v4()
	{
		if (not passes_SS_fo_looseMVA_v4_isLoaded) {
			if (passes_SS_fo_looseMVA_v4_branch != 0) {
				passes_SS_fo_looseMVA_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_v4_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_v4_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_noiso_v4()
	{
		if (not passes_SS_fo_looseMVA_noiso_v4_isLoaded) {
			if (passes_SS_fo_looseMVA_noiso_v4_branch != 0) {
				passes_SS_fo_looseMVA_noiso_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_noiso_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_noiso_v4_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_noiso_v4_;
	}
	const bool &	leptree_v0::passes_SS_veto_v4()
	{
		if (not passes_SS_veto_v4_isLoaded) {
			if (passes_SS_veto_v4_branch != 0) {
				passes_SS_veto_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_v4_isLoaded = true;
		}
		return passes_SS_veto_v4_;
	}
	const bool &	leptree_v0::passes_SS_veto_noiso_v4()
	{
		if (not passes_SS_veto_noiso_v4_isLoaded) {
			if (passes_SS_veto_noiso_v4_branch != 0) {
				passes_SS_veto_noiso_v4_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_noiso_v4_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_noiso_v4_isLoaded = true;
		}
		return passes_SS_veto_noiso_v4_;
	}
	const bool &	leptree_v0::passes_SS_tight_v5()
	{
		if (not passes_SS_tight_v5_isLoaded) {
			if (passes_SS_tight_v5_branch != 0) {
				passes_SS_tight_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_v5_isLoaded = true;
		}
		return passes_SS_tight_v5_;
	}
	const bool &	leptree_v0::passes_SS_tight_noiso_v5()
	{
		if (not passes_SS_tight_noiso_v5_isLoaded) {
			if (passes_SS_tight_noiso_v5_branch != 0) {
				passes_SS_tight_noiso_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_tight_noiso_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_tight_noiso_v5_isLoaded = true;
		}
		return passes_SS_tight_noiso_v5_;
	}
	const bool &	leptree_v0::passes_SS_fo_v5()
	{
		if (not passes_SS_fo_v5_isLoaded) {
			if (passes_SS_fo_v5_branch != 0) {
				passes_SS_fo_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_v5_isLoaded = true;
		}
		return passes_SS_fo_v5_;
	}
	const bool &	leptree_v0::passes_SS_fo_noiso_v5()
	{
		if (not passes_SS_fo_noiso_v5_isLoaded) {
			if (passes_SS_fo_noiso_v5_branch != 0) {
				passes_SS_fo_noiso_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_noiso_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_noiso_v5_isLoaded = true;
		}
		return passes_SS_fo_noiso_v5_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_v5()
	{
		if (not passes_SS_fo_looseMVA_v5_isLoaded) {
			if (passes_SS_fo_looseMVA_v5_branch != 0) {
				passes_SS_fo_looseMVA_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_v5_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_v5_;
	}
	const bool &	leptree_v0::passes_SS_fo_looseMVA_noiso_v5()
	{
		if (not passes_SS_fo_looseMVA_noiso_v5_isLoaded) {
			if (passes_SS_fo_looseMVA_noiso_v5_branch != 0) {
				passes_SS_fo_looseMVA_noiso_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_fo_looseMVA_noiso_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_fo_looseMVA_noiso_v5_isLoaded = true;
		}
		return passes_SS_fo_looseMVA_noiso_v5_;
	}
	const bool &	leptree_v0::passes_SS_veto_v5()
	{
		if (not passes_SS_veto_v5_isLoaded) {
			if (passes_SS_veto_v5_branch != 0) {
				passes_SS_veto_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_v5_isLoaded = true;
		}
		return passes_SS_veto_v5_;
	}
	const bool &	leptree_v0::passes_SS_veto_noiso_v5()
	{
		if (not passes_SS_veto_noiso_v5_isLoaded) {
			if (passes_SS_veto_noiso_v5_branch != 0) {
				passes_SS_veto_noiso_v5_branch->GetEntry(index);
			} else { 
				printf("branch passes_SS_veto_noiso_v5_branch does not exist!\n");
				exit(1);
			}
			passes_SS_veto_noiso_v5_isLoaded = true;
		}
		return passes_SS_veto_noiso_v5_;
	}
	const bool &	leptree_v0::passes_WW_medium_v2()
	{
		if (not passes_WW_medium_v2_isLoaded) {
			if (passes_WW_medium_v2_branch != 0) {
				passes_WW_medium_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_medium_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_medium_v2_isLoaded = true;
		}
		return passes_WW_medium_v2_;
	}
	const bool &	leptree_v0::passes_WW_medium_noiso_v2()
	{
		if (not passes_WW_medium_noiso_v2_isLoaded) {
			if (passes_WW_medium_noiso_v2_branch != 0) {
				passes_WW_medium_noiso_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_medium_noiso_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_medium_noiso_v2_isLoaded = true;
		}
		return passes_WW_medium_noiso_v2_;
	}
	const bool &	leptree_v0::passes_WW_fo_v2()
	{
		if (not passes_WW_fo_v2_isLoaded) {
			if (passes_WW_fo_v2_branch != 0) {
				passes_WW_fo_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_fo_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_fo_v2_isLoaded = true;
		}
		return passes_WW_fo_v2_;
	}
	const bool &	leptree_v0::passes_WW_fo_noiso_v2()
	{
		if (not passes_WW_fo_noiso_v2_isLoaded) {
			if (passes_WW_fo_noiso_v2_branch != 0) {
				passes_WW_fo_noiso_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_fo_noiso_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_fo_noiso_v2_isLoaded = true;
		}
		return passes_WW_fo_noiso_v2_;
	}
	const bool &	leptree_v0::passes_WW_veto_v2()
	{
		if (not passes_WW_veto_v2_isLoaded) {
			if (passes_WW_veto_v2_branch != 0) {
				passes_WW_veto_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_veto_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_veto_v2_isLoaded = true;
		}
		return passes_WW_veto_v2_;
	}
	const bool &	leptree_v0::passes_WW_veto_noiso_v2()
	{
		if (not passes_WW_veto_noiso_v2_isLoaded) {
			if (passes_WW_veto_noiso_v2_branch != 0) {
				passes_WW_veto_noiso_v2_branch->GetEntry(index);
			} else { 
				printf("branch passes_WW_veto_noiso_v2_branch does not exist!\n");
				exit(1);
			}
			passes_WW_veto_noiso_v2_isLoaded = true;
		}
		return passes_WW_veto_noiso_v2_;
	}
	const bool &	leptree_v0::passes_HAD_veto_v3()
	{
		if (not passes_HAD_veto_v3_isLoaded) {
			if (passes_HAD_veto_v3_branch != 0) {
				passes_HAD_veto_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_HAD_veto_v3_branch does not exist!\n");
				exit(1);
			}
			passes_HAD_veto_v3_isLoaded = true;
		}
		return passes_HAD_veto_v3_;
	}
	const bool &	leptree_v0::passes_HAD_veto_noiso_v3()
	{
		if (not passes_HAD_veto_noiso_v3_isLoaded) {
			if (passes_HAD_veto_noiso_v3_branch != 0) {
				passes_HAD_veto_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_HAD_veto_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_HAD_veto_noiso_v3_isLoaded = true;
		}
		return passes_HAD_veto_noiso_v3_;
	}
	const bool &	leptree_v0::passes_HAD_loose_v3()
	{
		if (not passes_HAD_loose_v3_isLoaded) {
			if (passes_HAD_loose_v3_branch != 0) {
				passes_HAD_loose_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_HAD_loose_v3_branch does not exist!\n");
				exit(1);
			}
			passes_HAD_loose_v3_isLoaded = true;
		}
		return passes_HAD_loose_v3_;
	}
	const bool &	leptree_v0::passes_HAD_loose_noiso_v3()
	{
		if (not passes_HAD_loose_noiso_v3_isLoaded) {
			if (passes_HAD_loose_noiso_v3_branch != 0) {
				passes_HAD_loose_noiso_v3_branch->GetEntry(index);
			} else { 
				printf("branch passes_HAD_loose_noiso_v3_branch does not exist!\n");
				exit(1);
			}
			passes_HAD_loose_noiso_v3_isLoaded = true;
		}
		return passes_HAD_loose_noiso_v3_;
	}
	const bool &	leptree_v0::passes_POG_vetoID()
	{
		if (not passes_POG_vetoID_isLoaded) {
			if (passes_POG_vetoID_branch != 0) {
				passes_POG_vetoID_branch->GetEntry(index);
			} else { 
				printf("branch passes_POG_vetoID_branch does not exist!\n");
				exit(1);
			}
			passes_POG_vetoID_isLoaded = true;
		}
		return passes_POG_vetoID_;
	}
	const bool &	leptree_v0::passes_POG_looseID()
	{
		if (not passes_POG_looseID_isLoaded) {
			if (passes_POG_looseID_branch != 0) {
				passes_POG_looseID_branch->GetEntry(index);
			} else { 
				printf("branch passes_POG_looseID_branch does not exist!\n");
				exit(1);
			}
			passes_POG_looseID_isLoaded = true;
		}
		return passes_POG_looseID_;
	}
	const bool &	leptree_v0::passes_POG_mediumID()
	{
		if (not passes_POG_mediumID_isLoaded) {
			if (passes_POG_mediumID_branch != 0) {
				passes_POG_mediumID_branch->GetEntry(index);
			} else { 
				printf("branch passes_POG_mediumID_branch does not exist!\n");
				exit(1);
			}
			passes_POG_mediumID_isLoaded = true;
		}
		return passes_POG_mediumID_;
	}
	const bool &	leptree_v0::passes_POG_tightID()
	{
		if (not passes_POG_tightID_isLoaded) {
			if (passes_POG_tightID_branch != 0) {
				passes_POG_tightID_branch->GetEntry(index);
			} else { 
				printf("branch passes_POG_tightID_branch does not exist!\n");
				exit(1);
			}
			passes_POG_tightID_isLoaded = true;
		}
		return passes_POG_tightID_;
	}
	const float &leptree_v0::ip3d()
	{
		if (not ip3d_isLoaded) {
			if (ip3d_branch != 0) {
				ip3d_branch->GetEntry(index);
			} else { 
				printf("branch ip3d_branch does not exist!\n");
				exit(1);
			}
			ip3d_isLoaded = true;
		}
		return ip3d_;
	}
	const float &leptree_v0::ip3derr()
	{
		if (not ip3derr_isLoaded) {
			if (ip3derr_branch != 0) {
				ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch ip3derr_branch does not exist!\n");
				exit(1);
			}
			ip3derr_isLoaded = true;
		}
		return ip3derr_;
	}
	const int &leptree_v0::type()
	{
		if (not type_isLoaded) {
			if (type_branch != 0) {
				type_branch->GetEntry(index);
			} else { 
				printf("branch type_branch does not exist!\n");
				exit(1);
			}
			type_isLoaded = true;
		}
		return type_;
	}
	const float &leptree_v0::mt()
	{
		if (not mt_isLoaded) {
			if (mt_branch != 0) {
				mt_branch->GetEntry(index);
			} else { 
				printf("branch mt_branch does not exist!\n");
				exit(1);
			}
			mt_isLoaded = true;
		}
		return mt_;
	}
	const float &leptree_v0::ptrelv0()
	{
		if (not ptrelv0_isLoaded) {
			if (ptrelv0_branch != 0) {
				ptrelv0_branch->GetEntry(index);
			} else { 
				printf("branch ptrelv0_branch does not exist!\n");
				exit(1);
			}
			ptrelv0_isLoaded = true;
		}
		return ptrelv0_;
	}
	const float &leptree_v0::ptrelv1()
	{
		if (not ptrelv1_isLoaded) {
			if (ptrelv1_branch != 0) {
				ptrelv1_branch->GetEntry(index);
			} else { 
				printf("branch ptrelv1_branch does not exist!\n");
				exit(1);
			}
			ptrelv1_isLoaded = true;
		}
		return ptrelv1_;
	}
	const float &leptree_v0::miniiso()
	{
		if (not miniiso_isLoaded) {
			if (miniiso_branch != 0) {
				miniiso_branch->GetEntry(index);
			} else { 
				printf("branch miniiso_branch does not exist!\n");
				exit(1);
			}
			miniiso_isLoaded = true;
		}
		return miniiso_;
	}
	const float &leptree_v0::miniisoDB()
	{
		if (not miniisoDB_isLoaded) {
			if (miniisoDB_branch != 0) {
				miniisoDB_branch->GetEntry(index);
			} else { 
				printf("branch miniisoDB_branch does not exist!\n");
				exit(1);
			}
			miniisoDB_isLoaded = true;
		}
		return miniisoDB_;
	}
	const float &leptree_v0::reliso04()
	{
		if (not reliso04_isLoaded) {
			if (reliso04_branch != 0) {
				reliso04_branch->GetEntry(index);
			} else { 
				printf("branch reliso04_branch does not exist!\n");
				exit(1);
			}
			reliso04_isLoaded = true;
		}
		return reliso04_;
	}
	const float &leptree_v0::annulus04()
	{
		if (not annulus04_isLoaded) {
			if (annulus04_branch != 0) {
				annulus04_branch->GetEntry(index);
			} else { 
				printf("branch annulus04_branch does not exist!\n");
				exit(1);
			}
			annulus04_isLoaded = true;
		}
		return annulus04_;
	}
	const float &leptree_v0::AbsTrkIso()
	{
		if (not AbsTrkIso_isLoaded) {
			if (AbsTrkIso_branch != 0) {
				AbsTrkIso_branch->GetEntry(index);
			} else { 
				printf("branch AbsTrkIso_branch does not exist!\n");
				exit(1);
			}
			AbsTrkIso_isLoaded = true;
		}
		return AbsTrkIso_;
	}
	const float &leptree_v0::TrkAn04()
	{
		if (not TrkAn04_isLoaded) {
			if (TrkAn04_branch != 0) {
				TrkAn04_branch->GetEntry(index);
			} else { 
				printf("branch TrkAn04_branch does not exist!\n");
				exit(1);
			}
			TrkAn04_isLoaded = true;
		}
		return TrkAn04_;
	}
	const float &leptree_v0::iso03sumPt()
	{
		if (not iso03sumPt_isLoaded) {
			if (iso03sumPt_branch != 0) {
				iso03sumPt_branch->GetEntry(index);
			} else { 
				printf("branch iso03sumPt_branch does not exist!\n");
				exit(1);
			}
			iso03sumPt_isLoaded = true;
		}
		return iso03sumPt_;
	}
	const float &leptree_v0::iso03emEt()
	{
		if (not iso03emEt_isLoaded) {
			if (iso03emEt_branch != 0) {
				iso03emEt_branch->GetEntry(index);
			} else { 
				printf("branch iso03emEt_branch does not exist!\n");
				exit(1);
			}
			iso03emEt_isLoaded = true;
		}
		return iso03emEt_;
	}
	const float &leptree_v0::iso03hadEt()
	{
		if (not iso03hadEt_isLoaded) {
			if (iso03hadEt_branch != 0) {
				iso03hadEt_branch->GetEntry(index);
			} else { 
				printf("branch iso03hadEt_branch does not exist!\n");
				exit(1);
			}
			iso03hadEt_isLoaded = true;
		}
		return iso03hadEt_;
	}
	const int &leptree_v0::jet_close_lep_idx()
	{
		if (not jet_close_lep_idx_isLoaded) {
			if (jet_close_lep_idx_branch != 0) {
				jet_close_lep_idx_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep_idx_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep_idx_isLoaded = true;
		}
		return jet_close_lep_idx_;
	}
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &leptree_v0::jet_close_lep()
	{
		if (not jet_close_lep_isLoaded) {
			if (jet_close_lep_branch != 0) {
				jet_close_lep_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep_isLoaded = true;
		}
		return *jet_close_lep_;
	}
	const float &leptree_v0::jet_close_lep_undoJEC()
	{
		if (not jet_close_lep_undoJEC_isLoaded) {
			if (jet_close_lep_undoJEC_branch != 0) {
				jet_close_lep_undoJEC_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep_undoJEC_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep_undoJEC_isLoaded = true;
		}
		return jet_close_lep_undoJEC_;
	}
	const float &leptree_v0::jet_close_lep_area()
	{
		if (not jet_close_lep_area_isLoaded) {
			if (jet_close_lep_area_branch != 0) {
				jet_close_lep_area_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep_area_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep_area_isLoaded = true;
		}
		return jet_close_lep_area_;
	}
	const float &leptree_v0::jet_close_L1()
	{
		if (not jet_close_L1_isLoaded) {
			if (jet_close_L1_branch != 0) {
				jet_close_L1_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_L1_branch does not exist!\n");
				exit(1);
			}
			jet_close_L1_isLoaded = true;
		}
		return jet_close_L1_;
	}
	const float &leptree_v0::jet_close_L1nc()
	{
		if (not jet_close_L1nc_isLoaded) {
			if (jet_close_L1nc_branch != 0) {
				jet_close_L1nc_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_L1nc_branch does not exist!\n");
				exit(1);
			}
			jet_close_L1nc_isLoaded = true;
		}
		return jet_close_L1nc_;
	}
	const float &leptree_v0::jet_close_L1ncmc()
	{
		if (not jet_close_L1ncmc_isLoaded) {
			if (jet_close_L1ncmc_branch != 0) {
				jet_close_L1ncmc_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_L1ncmc_branch does not exist!\n");
				exit(1);
			}
			jet_close_L1ncmc_isLoaded = true;
		}
		return jet_close_L1ncmc_;
	}
	const float &leptree_v0::jet_close_L1L2L3()
	{
		if (not jet_close_L1L2L3_isLoaded) {
			if (jet_close_L1L2L3_branch != 0) {
				jet_close_L1L2L3_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_L1L2L3_branch does not exist!\n");
				exit(1);
			}
			jet_close_L1L2L3_isLoaded = true;
		}
		return jet_close_L1L2L3_;
	}
	const float &leptree_v0::jet_close_L2L3()
	{
		if (not jet_close_L2L3_isLoaded) {
			if (jet_close_L2L3_branch != 0) {
				jet_close_L2L3_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_L2L3_branch does not exist!\n");
				exit(1);
			}
			jet_close_L2L3_isLoaded = true;
		}
		return jet_close_L2L3_;
	}
	const float &leptree_v0::ptratio()
	{
		if (not ptratio_isLoaded) {
			if (ptratio_branch != 0) {
				ptratio_branch->GetEntry(index);
			} else { 
				printf("branch ptratio_branch does not exist!\n");
				exit(1);
			}
			ptratio_isLoaded = true;
		}
		return ptratio_;
	}
	const int &leptree_v0::tag_charge()
	{
		if (not tag_charge_isLoaded) {
			if (tag_charge_branch != 0) {
				tag_charge_branch->GetEntry(index);
			} else { 
				printf("branch tag_charge_branch does not exist!\n");
				exit(1);
			}
			tag_charge_isLoaded = true;
		}
		return tag_charge_;
	}
	const int &leptree_v0::tag_mc_motherid()
	{
		if (not tag_mc_motherid_isLoaded) {
			if (tag_mc_motherid_branch != 0) {
				tag_mc_motherid_branch->GetEntry(index);
			} else { 
				printf("branch tag_mc_motherid_branch does not exist!\n");
				exit(1);
			}
			tag_mc_motherid_isLoaded = true;
		}
		return tag_mc_motherid_;
	}
	const float &leptree_v0::tag_eSeed()
	{
		if (not tag_eSeed_isLoaded) {
			if (tag_eSeed_branch != 0) {
				tag_eSeed_branch->GetEntry(index);
			} else { 
				printf("branch tag_eSeed_branch does not exist!\n");
				exit(1);
			}
			tag_eSeed_isLoaded = true;
		}
		return tag_eSeed_;
	}
	const float &leptree_v0::tag_eSCRaw()
	{
		if (not tag_eSCRaw_isLoaded) {
			if (tag_eSCRaw_branch != 0) {
				tag_eSCRaw_branch->GetEntry(index);
			} else { 
				printf("branch tag_eSCRaw_branch does not exist!\n");
				exit(1);
			}
			tag_eSCRaw_isLoaded = true;
		}
		return tag_eSCRaw_;
	}
	const float &leptree_v0::tag_eSC()
	{
		if (not tag_eSC_isLoaded) {
			if (tag_eSC_branch != 0) {
				tag_eSC_branch->GetEntry(index);
			} else { 
				printf("branch tag_eSC_branch does not exist!\n");
				exit(1);
			}
			tag_eSC_isLoaded = true;
		}
		return tag_eSC_;
	}
	const float &leptree_v0::tag_ecalEnergy()
	{
		if (not tag_ecalEnergy_isLoaded) {
			if (tag_ecalEnergy_branch != 0) {
				tag_ecalEnergy_branch->GetEntry(index);
			} else { 
				printf("branch tag_ecalEnergy_branch does not exist!\n");
				exit(1);
			}
			tag_ecalEnergy_isLoaded = true;
		}
		return tag_ecalEnergy_;
	}
	const int &leptree_v0::exp_innerlayers()
	{
		if (not exp_innerlayers_isLoaded) {
			if (exp_innerlayers_branch != 0) {
				exp_innerlayers_branch->GetEntry(index);
			} else { 
				printf("branch exp_innerlayers_branch does not exist!\n");
				exit(1);
			}
			exp_innerlayers_isLoaded = true;
		}
		return exp_innerlayers_;
	}
	const int &leptree_v0::exp_outerlayers()
	{
		if (not exp_outerlayers_isLoaded) {
			if (exp_outerlayers_branch != 0) {
				exp_outerlayers_branch->GetEntry(index);
			} else { 
				printf("branch exp_outerlayers_branch does not exist!\n");
				exit(1);
			}
			exp_outerlayers_isLoaded = true;
		}
		return exp_outerlayers_;
	}
	const int &leptree_v0::tag_HLT_Ele27_eta2p1_WPTight_Gsf()
	{
		if (not tag_HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded) {
			if (tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch != 0) {
				tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch->GetEntry(index);
			} else { 
				printf("branch tag_HLT_Ele27_eta2p1_WPTight_Gsf_branch does not exist!\n");
				exit(1);
			}
			tag_HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded = true;
		}
		return tag_HLT_Ele27_eta2p1_WPTight_Gsf_;
	}
	const int &leptree_v0::tag_HLT_Ele32_eta2p1_WPTight_Gsf()
	{
		if (not tag_HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded) {
			if (tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch != 0) {
				tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch->GetEntry(index);
			} else { 
				printf("branch tag_HLT_Ele32_eta2p1_WPTight_Gsf_branch does not exist!\n");
				exit(1);
			}
			tag_HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded = true;
		}
		return tag_HLT_Ele32_eta2p1_WPTight_Gsf_;
	}
	const int &leptree_v0::tag_HLT_IsoMu24()
	{
		if (not tag_HLT_IsoMu24_isLoaded) {
			if (tag_HLT_IsoMu24_branch != 0) {
				tag_HLT_IsoMu24_branch->GetEntry(index);
			} else { 
				printf("branch tag_HLT_IsoMu24_branch does not exist!\n");
				exit(1);
			}
			tag_HLT_IsoMu24_isLoaded = true;
		}
		return tag_HLT_IsoMu24_;
	}
	const int &leptree_v0::tag_HLT_IsoTkMu24()
	{
		if (not tag_HLT_IsoTkMu24_isLoaded) {
			if (tag_HLT_IsoTkMu24_branch != 0) {
				tag_HLT_IsoTkMu24_branch->GetEntry(index);
			} else { 
				printf("branch tag_HLT_IsoTkMu24_branch does not exist!\n");
				exit(1);
			}
			tag_HLT_IsoTkMu24_isLoaded = true;
		}
		return tag_HLT_IsoTkMu24_;
	}
	const float &leptree_v0::dilep_mass()
	{
		if (not dilep_mass_isLoaded) {
			if (dilep_mass_branch != 0) {
				dilep_mass_branch->GetEntry(index);
			} else { 
				printf("branch dilep_mass_branch does not exist!\n");
				exit(1);
			}
			dilep_mass_isLoaded = true;
		}
		return dilep_mass_;
	}
	const bool &	leptree_v0::isRandom()
	{
		if (not isRandom_isLoaded) {
			if (isRandom_branch != 0) {
				isRandom_branch->GetEntry(index);
			} else { 
				printf("branch isRandom_branch does not exist!\n");
				exit(1);
			}
			isRandom_isLoaded = true;
		}
		return isRandom_;
	}
	const float &leptree_v0::sigmaIEtaIEta_full5x5()
	{
		if (not sigmaIEtaIEta_full5x5_isLoaded) {
			if (sigmaIEtaIEta_full5x5_branch != 0) {
				sigmaIEtaIEta_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch sigmaIEtaIEta_full5x5_branch does not exist!\n");
				exit(1);
			}
			sigmaIEtaIEta_full5x5_isLoaded = true;
		}
		return sigmaIEtaIEta_full5x5_;
	}
	const float &leptree_v0::sigmaIEtaIEta()
	{
		if (not sigmaIEtaIEta_isLoaded) {
			if (sigmaIEtaIEta_branch != 0) {
				sigmaIEtaIEta_branch->GetEntry(index);
			} else { 
				printf("branch sigmaIEtaIEta_branch does not exist!\n");
				exit(1);
			}
			sigmaIEtaIEta_isLoaded = true;
		}
		return sigmaIEtaIEta_;
	}
	const float &leptree_v0::etaSC()
	{
		if (not etaSC_isLoaded) {
			if (etaSC_branch != 0) {
				etaSC_branch->GetEntry(index);
			} else { 
				printf("branch etaSC_branch does not exist!\n");
				exit(1);
			}
			etaSC_isLoaded = true;
		}
		return etaSC_;
	}
	const float &leptree_v0::dEtaIn()
	{
		if (not dEtaIn_isLoaded) {
			if (dEtaIn_branch != 0) {
				dEtaIn_branch->GetEntry(index);
			} else { 
				printf("branch dEtaIn_branch does not exist!\n");
				exit(1);
			}
			dEtaIn_isLoaded = true;
		}
		return dEtaIn_;
	}
	const float &leptree_v0::dPhiIn()
	{
		if (not dPhiIn_isLoaded) {
			if (dPhiIn_branch != 0) {
				dPhiIn_branch->GetEntry(index);
			} else { 
				printf("branch dPhiIn_branch does not exist!\n");
				exit(1);
			}
			dPhiIn_isLoaded = true;
		}
		return dPhiIn_;
	}
	const float &leptree_v0::hOverE()
	{
		if (not hOverE_isLoaded) {
			if (hOverE_branch != 0) {
				hOverE_branch->GetEntry(index);
			} else { 
				printf("branch hOverE_branch does not exist!\n");
				exit(1);
			}
			hOverE_isLoaded = true;
		}
		return hOverE_;
	}
	const float &leptree_v0::eSeed()
	{
		if (not eSeed_isLoaded) {
			if (eSeed_branch != 0) {
				eSeed_branch->GetEntry(index);
			} else { 
				printf("branch eSeed_branch does not exist!\n");
				exit(1);
			}
			eSeed_isLoaded = true;
		}
		return eSeed_;
	}
	const float &leptree_v0::scSeedEta()
	{
		if (not scSeedEta_isLoaded) {
			if (scSeedEta_branch != 0) {
				scSeedEta_branch->GetEntry(index);
			} else { 
				printf("branch scSeedEta_branch does not exist!\n");
				exit(1);
			}
			scSeedEta_isLoaded = true;
		}
		return scSeedEta_;
	}
	const float &leptree_v0::ecalEnergy()
	{
		if (not ecalEnergy_isLoaded) {
			if (ecalEnergy_branch != 0) {
				ecalEnergy_branch->GetEntry(index);
			} else { 
				printf("branch ecalEnergy_branch does not exist!\n");
				exit(1);
			}
			ecalEnergy_isLoaded = true;
		}
		return ecalEnergy_;
	}
	const float &leptree_v0::eOverPIn()
	{
		if (not eOverPIn_isLoaded) {
			if (eOverPIn_branch != 0) {
				eOverPIn_branch->GetEntry(index);
			} else { 
				printf("branch eOverPIn_branch does not exist!\n");
				exit(1);
			}
			eOverPIn_isLoaded = true;
		}
		return eOverPIn_;
	}
	const bool &	leptree_v0::conv_vtx_flag()
	{
		if (not conv_vtx_flag_isLoaded) {
			if (conv_vtx_flag_branch != 0) {
				conv_vtx_flag_branch->GetEntry(index);
			} else { 
				printf("branch conv_vtx_flag_branch does not exist!\n");
				exit(1);
			}
			conv_vtx_flag_isLoaded = true;
		}
		return conv_vtx_flag_;
	}
	const int &leptree_v0::charge()
	{
		if (not charge_isLoaded) {
			if (charge_branch != 0) {
				charge_branch->GetEntry(index);
			} else { 
				printf("branch charge_branch does not exist!\n");
				exit(1);
			}
			charge_isLoaded = true;
		}
		return charge_;
	}
	const int &leptree_v0::sccharge()
	{
		if (not sccharge_isLoaded) {
			if (sccharge_branch != 0) {
				sccharge_branch->GetEntry(index);
			} else { 
				printf("branch sccharge_branch does not exist!\n");
				exit(1);
			}
			sccharge_isLoaded = true;
		}
		return sccharge_;
	}
	const int &leptree_v0::ckf_charge()
	{
		if (not ckf_charge_isLoaded) {
			if (ckf_charge_branch != 0) {
				ckf_charge_branch->GetEntry(index);
			} else { 
				printf("branch ckf_charge_branch does not exist!\n");
				exit(1);
			}
			ckf_charge_isLoaded = true;
		}
		return ckf_charge_;
	}
	const bool &	leptree_v0::threeChargeAgree()
	{
		if (not threeChargeAgree_isLoaded) {
			if (threeChargeAgree_branch != 0) {
				threeChargeAgree_branch->GetEntry(index);
			} else { 
				printf("branch threeChargeAgree_branch does not exist!\n");
				exit(1);
			}
			threeChargeAgree_isLoaded = true;
		}
		return threeChargeAgree_;
	}
	const float &leptree_v0::mva()
	{
		if (not mva_isLoaded) {
			if (mva_branch != 0) {
				mva_branch->GetEntry(index);
			} else { 
				printf("branch mva_branch does not exist!\n");
				exit(1);
			}
			mva_isLoaded = true;
		}
		return mva_;
	}
	const float &leptree_v0::mva_25ns()
	{
		if (not mva_25ns_isLoaded) {
			if (mva_25ns_branch != 0) {
				mva_25ns_branch->GetEntry(index);
			} else { 
				printf("branch mva_25ns_branch does not exist!\n");
				exit(1);
			}
			mva_25ns_isLoaded = true;
		}
		return mva_25ns_;
	}
	const float &leptree_v0::tag_mva_25ns()
	{
		if (not tag_mva_25ns_isLoaded) {
			if (tag_mva_25ns_branch != 0) {
				tag_mva_25ns_branch->GetEntry(index);
			} else { 
				printf("branch tag_mva_25ns_branch does not exist!\n");
				exit(1);
			}
			tag_mva_25ns_isLoaded = true;
		}
		return tag_mva_25ns_;
	}
	const float &leptree_v0::ecalIso()
	{
		if (not ecalIso_isLoaded) {
			if (ecalIso_branch != 0) {
				ecalIso_branch->GetEntry(index);
			} else { 
				printf("branch ecalIso_branch does not exist!\n");
				exit(1);
			}
			ecalIso_isLoaded = true;
		}
		return ecalIso_;
	}
	const float &leptree_v0::hcalIso()
	{
		if (not hcalIso_isLoaded) {
			if (hcalIso_branch != 0) {
				hcalIso_branch->GetEntry(index);
			} else { 
				printf("branch hcalIso_branch does not exist!\n");
				exit(1);
			}
			hcalIso_isLoaded = true;
		}
		return hcalIso_;
	}
	const float &leptree_v0::ecalPFClusterIso()
	{
		if (not ecalPFClusterIso_isLoaded) {
			if (ecalPFClusterIso_branch != 0) {
				ecalPFClusterIso_branch->GetEntry(index);
			} else { 
				printf("branch ecalPFClusterIso_branch does not exist!\n");
				exit(1);
			}
			ecalPFClusterIso_isLoaded = true;
		}
		return ecalPFClusterIso_;
	}
	const float &leptree_v0::hcalPFClusterIso()
	{
		if (not hcalPFClusterIso_isLoaded) {
			if (hcalPFClusterIso_branch != 0) {
				hcalPFClusterIso_branch->GetEntry(index);
			} else { 
				printf("branch hcalPFClusterIso_branch does not exist!\n");
				exit(1);
			}
			hcalPFClusterIso_isLoaded = true;
		}
		return hcalPFClusterIso_;
	}
	const int &leptree_v0::ckf_laywithmeas()
	{
		if (not ckf_laywithmeas_isLoaded) {
			if (ckf_laywithmeas_branch != 0) {
				ckf_laywithmeas_branch->GetEntry(index);
			} else { 
				printf("branch ckf_laywithmeas_branch does not exist!\n");
				exit(1);
			}
			ckf_laywithmeas_isLoaded = true;
		}
		return ckf_laywithmeas_;
	}
	const float &leptree_v0::sigmaIPhiIPhi_full5x5()
	{
		if (not sigmaIPhiIPhi_full5x5_isLoaded) {
			if (sigmaIPhiIPhi_full5x5_branch != 0) {
				sigmaIPhiIPhi_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch sigmaIPhiIPhi_full5x5_branch does not exist!\n");
				exit(1);
			}
			sigmaIPhiIPhi_full5x5_isLoaded = true;
		}
		return sigmaIPhiIPhi_full5x5_;
	}
	const float &leptree_v0::e1x5_full5x5()
	{
		if (not e1x5_full5x5_isLoaded) {
			if (e1x5_full5x5_branch != 0) {
				e1x5_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch e1x5_full5x5_branch does not exist!\n");
				exit(1);
			}
			e1x5_full5x5_isLoaded = true;
		}
		return e1x5_full5x5_;
	}
	const float &leptree_v0::e5x5_full5x5()
	{
		if (not e5x5_full5x5_isLoaded) {
			if (e5x5_full5x5_branch != 0) {
				e5x5_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch e5x5_full5x5_branch does not exist!\n");
				exit(1);
			}
			e5x5_full5x5_isLoaded = true;
		}
		return e5x5_full5x5_;
	}
	const float &leptree_v0::r9_full5x5()
	{
		if (not r9_full5x5_isLoaded) {
			if (r9_full5x5_branch != 0) {
				r9_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch r9_full5x5_branch does not exist!\n");
				exit(1);
			}
			r9_full5x5_isLoaded = true;
		}
		return r9_full5x5_;
	}
	const float &leptree_v0::tag_r9_full5x5()
	{
		if (not tag_r9_full5x5_isLoaded) {
			if (tag_r9_full5x5_branch != 0) {
				tag_r9_full5x5_branch->GetEntry(index);
			} else { 
				printf("branch tag_r9_full5x5_branch does not exist!\n");
				exit(1);
			}
			tag_r9_full5x5_isLoaded = true;
		}
		return tag_r9_full5x5_;
	}
	const float &leptree_v0::etaSCwidth()
	{
		if (not etaSCwidth_isLoaded) {
			if (etaSCwidth_branch != 0) {
				etaSCwidth_branch->GetEntry(index);
			} else { 
				printf("branch etaSCwidth_branch does not exist!\n");
				exit(1);
			}
			etaSCwidth_isLoaded = true;
		}
		return etaSCwidth_;
	}
	const float &leptree_v0::phiSCwidth()
	{
		if (not phiSCwidth_isLoaded) {
			if (phiSCwidth_branch != 0) {
				phiSCwidth_branch->GetEntry(index);
			} else { 
				printf("branch phiSCwidth_branch does not exist!\n");
				exit(1);
			}
			phiSCwidth_isLoaded = true;
		}
		return phiSCwidth_;
	}
	const float &leptree_v0::eSCRaw()
	{
		if (not eSCRaw_isLoaded) {
			if (eSCRaw_branch != 0) {
				eSCRaw_branch->GetEntry(index);
			} else { 
				printf("branch eSCRaw_branch does not exist!\n");
				exit(1);
			}
			eSCRaw_isLoaded = true;
		}
		return eSCRaw_;
	}
	const float &leptree_v0::eSC()
	{
		if (not eSC_isLoaded) {
			if (eSC_branch != 0) {
				eSC_branch->GetEntry(index);
			} else { 
				printf("branch eSC_branch does not exist!\n");
				exit(1);
			}
			eSC_isLoaded = true;
		}
		return eSC_;
	}
	const float &leptree_v0::eSCPresh()
	{
		if (not eSCPresh_isLoaded) {
			if (eSCPresh_branch != 0) {
				eSCPresh_branch->GetEntry(index);
			} else { 
				printf("branch eSCPresh_branch does not exist!\n");
				exit(1);
			}
			eSCPresh_isLoaded = true;
		}
		return eSCPresh_;
	}
	const float &leptree_v0::ckf_chi2()
	{
		if (not ckf_chi2_isLoaded) {
			if (ckf_chi2_branch != 0) {
				ckf_chi2_branch->GetEntry(index);
			} else { 
				printf("branch ckf_chi2_branch does not exist!\n");
				exit(1);
			}
			ckf_chi2_isLoaded = true;
		}
		return ckf_chi2_;
	}
	const int &leptree_v0::ckf_ndof()
	{
		if (not ckf_ndof_isLoaded) {
			if (ckf_ndof_branch != 0) {
				ckf_ndof_branch->GetEntry(index);
			} else { 
				printf("branch ckf_ndof_branch does not exist!\n");
				exit(1);
			}
			ckf_ndof_isLoaded = true;
		}
		return ckf_ndof_;
	}
	const float &leptree_v0::chi2()
	{
		if (not chi2_isLoaded) {
			if (chi2_branch != 0) {
				chi2_branch->GetEntry(index);
			} else { 
				printf("branch chi2_branch does not exist!\n");
				exit(1);
			}
			chi2_isLoaded = true;
		}
		return chi2_;
	}
	const int &leptree_v0::ndof()
	{
		if (not ndof_isLoaded) {
			if (ndof_branch != 0) {
				ndof_branch->GetEntry(index);
			} else { 
				printf("branch ndof_branch does not exist!\n");
				exit(1);
			}
			ndof_isLoaded = true;
		}
		return ndof_;
	}
	const float &leptree_v0::fbrem()
	{
		if (not fbrem_isLoaded) {
			if (fbrem_branch != 0) {
				fbrem_branch->GetEntry(index);
			} else { 
				printf("branch fbrem_branch does not exist!\n");
				exit(1);
			}
			fbrem_isLoaded = true;
		}
		return fbrem_;
	}
	const float &leptree_v0::eOverPOut()
	{
		if (not eOverPOut_isLoaded) {
			if (eOverPOut_branch != 0) {
				eOverPOut_branch->GetEntry(index);
			} else { 
				printf("branch eOverPOut_branch does not exist!\n");
				exit(1);
			}
			eOverPOut_isLoaded = true;
		}
		return eOverPOut_;
	}
	const float &leptree_v0::dEtaOut()
	{
		if (not dEtaOut_isLoaded) {
			if (dEtaOut_branch != 0) {
				dEtaOut_branch->GetEntry(index);
			} else { 
				printf("branch dEtaOut_branch does not exist!\n");
				exit(1);
			}
			dEtaOut_isLoaded = true;
		}
		return dEtaOut_;
	}
	const float &leptree_v0::dPhiOut()
	{
		if (not dPhiOut_isLoaded) {
			if (dPhiOut_branch != 0) {
				dPhiOut_branch->GetEntry(index);
			} else { 
				printf("branch dPhiOut_branch does not exist!\n");
				exit(1);
			}
			dPhiOut_isLoaded = true;
		}
		return dPhiOut_;
	}
	const int &leptree_v0::gsf_validHits()
	{
		if (not gsf_validHits_isLoaded) {
			if (gsf_validHits_branch != 0) {
				gsf_validHits_branch->GetEntry(index);
			} else { 
				printf("branch gsf_validHits_branch does not exist!\n");
				exit(1);
			}
			gsf_validHits_isLoaded = true;
		}
		return gsf_validHits_;
	}
	const float &leptree_v0::conv_vtx_prob()
	{
		if (not conv_vtx_prob_isLoaded) {
			if (conv_vtx_prob_branch != 0) {
				conv_vtx_prob_branch->GetEntry(index);
			} else { 
				printf("branch conv_vtx_prob_branch does not exist!\n");
				exit(1);
			}
			conv_vtx_prob_isLoaded = true;
		}
		return conv_vtx_prob_;
	}
	const int &leptree_v0::pid_PFMuon()
	{
		if (not pid_PFMuon_isLoaded) {
			if (pid_PFMuon_branch != 0) {
				pid_PFMuon_branch->GetEntry(index);
			} else { 
				printf("branch pid_PFMuon_branch does not exist!\n");
				exit(1);
			}
			pid_PFMuon_isLoaded = true;
		}
		return pid_PFMuon_;
	}
	const float &leptree_v0::gfit_chi2()
	{
		if (not gfit_chi2_isLoaded) {
			if (gfit_chi2_branch != 0) {
				gfit_chi2_branch->GetEntry(index);
			} else { 
				printf("branch gfit_chi2_branch does not exist!\n");
				exit(1);
			}
			gfit_chi2_isLoaded = true;
		}
		return gfit_chi2_;
	}
	const int &leptree_v0::gfit_validSTAHits()
	{
		if (not gfit_validSTAHits_isLoaded) {
			if (gfit_validSTAHits_branch != 0) {
				gfit_validSTAHits_branch->GetEntry(index);
			} else { 
				printf("branch gfit_validSTAHits_branch does not exist!\n");
				exit(1);
			}
			gfit_validSTAHits_isLoaded = true;
		}
		return gfit_validSTAHits_;
	}
	const int &leptree_v0::numberOfMatchedStations()
	{
		if (not numberOfMatchedStations_isLoaded) {
			if (numberOfMatchedStations_branch != 0) {
				numberOfMatchedStations_branch->GetEntry(index);
			} else { 
				printf("branch numberOfMatchedStations_branch does not exist!\n");
				exit(1);
			}
			numberOfMatchedStations_isLoaded = true;
		}
		return numberOfMatchedStations_;
	}
	const int &leptree_v0::validPixelHits()
	{
		if (not validPixelHits_isLoaded) {
			if (validPixelHits_branch != 0) {
				validPixelHits_branch->GetEntry(index);
			} else { 
				printf("branch validPixelHits_branch does not exist!\n");
				exit(1);
			}
			validPixelHits_isLoaded = true;
		}
		return validPixelHits_;
	}
	const int &leptree_v0::nlayers()
	{
		if (not nlayers_isLoaded) {
			if (nlayers_branch != 0) {
				nlayers_branch->GetEntry(index);
			} else { 
				printf("branch nlayers_branch does not exist!\n");
				exit(1);
			}
			nlayers_isLoaded = true;
		}
		return nlayers_;
	}
	const float &leptree_v0::chi2LocalPosition()
	{
		if (not chi2LocalPosition_isLoaded) {
			if (chi2LocalPosition_branch != 0) {
				chi2LocalPosition_branch->GetEntry(index);
			} else { 
				printf("branch chi2LocalPosition_branch does not exist!\n");
				exit(1);
			}
			chi2LocalPosition_isLoaded = true;
		}
		return chi2LocalPosition_;
	}
	const float &leptree_v0::trkKink()
	{
		if (not trkKink_isLoaded) {
			if (trkKink_branch != 0) {
				trkKink_branch->GetEntry(index);
			} else { 
				printf("branch trkKink_branch does not exist!\n");
				exit(1);
			}
			trkKink_isLoaded = true;
		}
		return trkKink_;
	}
	const int &leptree_v0::validHits()
	{
		if (not validHits_isLoaded) {
			if (validHits_branch != 0) {
				validHits_branch->GetEntry(index);
			} else { 
				printf("branch validHits_branch does not exist!\n");
				exit(1);
			}
			validHits_isLoaded = true;
		}
		return validHits_;
	}
	const int &leptree_v0::lostHits()
	{
		if (not lostHits_isLoaded) {
			if (lostHits_branch != 0) {
				lostHits_branch->GetEntry(index);
			} else { 
				printf("branch lostHits_branch does not exist!\n");
				exit(1);
			}
			lostHits_isLoaded = true;
		}
		return lostHits_;
	}
	const float &leptree_v0::segmCompatibility()
	{
		if (not segmCompatibility_isLoaded) {
			if (segmCompatibility_branch != 0) {
				segmCompatibility_branch->GetEntry(index);
			} else { 
				printf("branch segmCompatibility_branch does not exist!\n");
				exit(1);
			}
			segmCompatibility_isLoaded = true;
		}
		return segmCompatibility_;
	}
	const int &leptree_v0::HLT_Mu8()
	{
		if (not HLT_Mu8_isLoaded) {
			if (HLT_Mu8_branch != 0) {
				HLT_Mu8_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8_isLoaded = true;
		}
		return HLT_Mu8_;
	}
	const int &leptree_v0::HLT_Mu17()
	{
		if (not HLT_Mu17_isLoaded) {
			if (HLT_Mu17_branch != 0) {
				HLT_Mu17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_isLoaded = true;
		}
		return HLT_Mu17_;
	}
	const int &leptree_v0::HLT_Mu8_TrkIsoVVL()
	{
		if (not HLT_Mu8_TrkIsoVVL_isLoaded) {
			if (HLT_Mu8_TrkIsoVVL_branch != 0) {
				HLT_Mu8_TrkIsoVVL_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8_TrkIsoVVL_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8_TrkIsoVVL_isLoaded = true;
		}
		return HLT_Mu8_TrkIsoVVL_;
	}
	const int &leptree_v0::HLT_Mu17_TrkIsoVVL()
	{
		if (not HLT_Mu17_TrkIsoVVL_isLoaded) {
			if (HLT_Mu17_TrkIsoVVL_branch != 0) {
				HLT_Mu17_TrkIsoVVL_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_TrkIsoVVL_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_TrkIsoVVL_isLoaded = true;
		}
		return HLT_Mu17_TrkIsoVVL_;
	}
	const int &leptree_v0::HLT_IsoMu24()
	{
		if (not HLT_IsoMu24_isLoaded) {
			if (HLT_IsoMu24_branch != 0) {
				HLT_IsoMu24_branch->GetEntry(index);
			} else { 
				printf("branch HLT_IsoMu24_branch does not exist!\n");
				exit(1);
			}
			HLT_IsoMu24_isLoaded = true;
		}
		return HLT_IsoMu24_;
	}
	const int &leptree_v0::HLT_IsoTkMu24()
	{
		if (not HLT_IsoTkMu24_isLoaded) {
			if (HLT_IsoTkMu24_branch != 0) {
				HLT_IsoTkMu24_branch->GetEntry(index);
			} else { 
				printf("branch HLT_IsoTkMu24_branch does not exist!\n");
				exit(1);
			}
			HLT_IsoTkMu24_isLoaded = true;
		}
		return HLT_IsoTkMu24_;
	}
	const int &leptree_v0::HLT_Mu50()
	{
		if (not HLT_Mu50_isLoaded) {
			if (HLT_Mu50_branch != 0) {
				HLT_Mu50_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu50_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu50_isLoaded = true;
		}
		return HLT_Mu50_;
	}
	const int &leptree_v0::HLT_Mu55()
	{
		if (not HLT_Mu55_isLoaded) {
			if (HLT_Mu55_branch != 0) {
				HLT_Mu55_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu55_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu55_isLoaded = true;
		}
		return HLT_Mu55_;
	}
	const int &leptree_v0::HLT_TkMu50()
	{
		if (not HLT_TkMu50_isLoaded) {
			if (HLT_TkMu50_branch != 0) {
				HLT_TkMu50_branch->GetEntry(index);
			} else { 
				printf("branch HLT_TkMu50_branch does not exist!\n");
				exit(1);
			}
			HLT_TkMu50_isLoaded = true;
		}
		return HLT_TkMu50_;
	}
	const int &leptree_v0::HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg()
	{
		if (not HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded) {
			if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch != 0) {
				HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded = true;
		}
		return HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg_;
	}
	const int &leptree_v0::HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg()
	{
		if (not HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded) {
			if (HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch != 0) {
				HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded = true;
		}
		return HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg_;
	}
	const int &leptree_v0::HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg()
	{
		if (not HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded) {
			if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch != 0) {
				HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_isLoaded = true;
		}
		return HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg_;
	}
	const int &leptree_v0::HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg()
	{
		if (not HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded) {
			if (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch != 0) {
				HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_isLoaded = true;
		}
		return HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg_;
	}
	const int &leptree_v0::HLT_Ele8_CaloIdM_TrackIdM_PFJet30()
	{
		if (not HLT_Ele8_CaloIdM_TrackIdM_PFJet30_isLoaded) {
			if (HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch != 0) {
				HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele8_CaloIdM_TrackIdM_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele8_CaloIdM_TrackIdM_PFJet30_isLoaded = true;
		}
		return HLT_Ele8_CaloIdM_TrackIdM_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele12_CaloIdM_TrackIdM_PFJet30()
	{
		if (not HLT_Ele12_CaloIdM_TrackIdM_PFJet30_isLoaded) {
			if (HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch != 0) {
				HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele12_CaloIdM_TrackIdM_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele12_CaloIdM_TrackIdM_PFJet30_isLoaded = true;
		}
		return HLT_Ele12_CaloIdM_TrackIdM_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele17_CaloIdM_TrackIdM_PFJet30()
	{
		if (not HLT_Ele17_CaloIdM_TrackIdM_PFJet30_isLoaded) {
			if (HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch != 0) {
				HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_CaloIdM_TrackIdM_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_CaloIdM_TrackIdM_PFJet30_isLoaded = true;
		}
		return HLT_Ele17_CaloIdM_TrackIdM_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele23_CaloIdM_TrackIdM_PFJet30()
	{
		if (not HLT_Ele23_CaloIdM_TrackIdM_PFJet30_isLoaded) {
			if (HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch != 0) {
				HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_CaloIdM_TrackIdM_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_CaloIdM_TrackIdM_PFJet30_isLoaded = true;
		}
		return HLT_Ele23_CaloIdM_TrackIdM_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30()
	{
		if (not HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded) {
			if (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) {
				HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = true;
		}
		return HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30()
	{
		if (not HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded) {
			if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) {
				HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = true;
		}
		return HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30()
	{
		if (not HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded) {
			if (HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) {
				HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = true;
		}
		return HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30()
	{
		if (not HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded) {
			if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch != 0) {
				HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_isLoaded = true;
		}
		return HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_;
	}
	const int &leptree_v0::HLT_Ele27_eta2p1_WPTight_Gsf()
	{
		if (not HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded) {
			if (HLT_Ele27_eta2p1_WPTight_Gsf_branch != 0) {
				HLT_Ele27_eta2p1_WPTight_Gsf_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele27_eta2p1_WPTight_Gsf_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele27_eta2p1_WPTight_Gsf_isLoaded = true;
		}
		return HLT_Ele27_eta2p1_WPTight_Gsf_;
	}
	const int &leptree_v0::HLT_Ele32_eta2p1_WPTight_Gsf()
	{
		if (not HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded) {
			if (HLT_Ele32_eta2p1_WPTight_Gsf_branch != 0) {
				HLT_Ele32_eta2p1_WPTight_Gsf_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele32_eta2p1_WPTight_Gsf_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele32_eta2p1_WPTight_Gsf_isLoaded = true;
		}
		return HLT_Ele32_eta2p1_WPTight_Gsf_;
	}
	const int &leptree_v0::HLT_Ele105_CaloIdVT_GsfTrkIdT()
	{
		if (not HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded) {
			if (HLT_Ele105_CaloIdVT_GsfTrkIdT_branch != 0) {
				HLT_Ele105_CaloIdVT_GsfTrkIdT_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele105_CaloIdVT_GsfTrkIdT_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele105_CaloIdVT_GsfTrkIdT_isLoaded = true;
		}
		return HLT_Ele105_CaloIdVT_GsfTrkIdT_;
	}
	const int &leptree_v0::HLT_Ele115_CaloIdVT_GsfTrkIdT()
	{
		if (not HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded) {
			if (HLT_Ele115_CaloIdVT_GsfTrkIdT_branch != 0) {
				HLT_Ele115_CaloIdVT_GsfTrkIdT_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele115_CaloIdVT_GsfTrkIdT_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele115_CaloIdVT_GsfTrkIdT_isLoaded = true;
		}
		return HLT_Ele115_CaloIdVT_GsfTrkIdT_;
	}
	const int &leptree_v0::HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg()
	{
		if (not HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded) {
			if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch != 0) {
				HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded = true;
		}
		return HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_;
	}
	const int &leptree_v0::HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg()
	{
		if (not HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded) {
			if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch != 0) {
				HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded = true;
		}
		return HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_;
	}
	const int &leptree_v0::HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1()
	{
		if (not HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded) {
			if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch != 0) {
				HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded = true;
		}
		return HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1_;
	}
	const int &leptree_v0::HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL()
	{
		if (not HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
			if (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
				HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
		}
		return HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_;
	}
	const int &leptree_v0::HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg()
	{
		if (not HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded) {
			if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch != 0) {
				HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_isLoaded = true;
		}
		return HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg_;
	}
	const int &leptree_v0::HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg()
	{
		if (not HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded) {
			if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch != 0) {
				HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_isLoaded = true;
		}
		return HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg_;
	}
	const int &leptree_v0::HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1()
	{
		if (not HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded) {
			if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch != 0) {
				HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_isLoaded = true;
		}
		return HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1_;
	}
	const int &leptree_v0::HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL()
	{
		if (not HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
			if (HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
				HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
				exit(1);
			}
			HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
		}
		return HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_;
	}

  void leptree_v0::progress( int nEventsTotal, int nEventsChain ){
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
  
namespace leptree_v0_np {
	const float &evt_pfmet() { return leptr_v0.evt_pfmet(); }
	const float &evt_pfmetPhi() { return leptr_v0.evt_pfmetPhi(); }
	const float &evt_trackmet() { return leptr_v0.evt_trackmet(); }
	const float &evt_trackmetPhi() { return leptr_v0.evt_trackmetPhi(); }
	const float &evt_corrMET() { return leptr_v0.evt_corrMET(); }
	const float &evt_corrMETPhi() { return leptr_v0.evt_corrMETPhi(); }
	const float &evt_pfsumet() { return leptr_v0.evt_pfsumet(); }
	const float &evt_pfmetSig() { return leptr_v0.evt_pfmetSig(); }
	const int &evt_event() { return leptr_v0.evt_event(); }
	const int &evt_lumiBlock() { return leptr_v0.evt_lumiBlock(); }
	const int &evt_run() { return leptr_v0.evt_run(); }
	const bool &filt_csc() { return leptr_v0.filt_csc(); }
	const bool &filt_hbhe() { return leptr_v0.filt_hbhe(); }
	const bool &passes_met_filters() { return leptr_v0.passes_met_filters(); }
	const bool &filt_hcallaser() { return leptr_v0.filt_hcallaser(); }
	const bool &filt_ecaltp() { return leptr_v0.filt_ecaltp(); }
	const bool &filt_trkfail() { return leptr_v0.filt_trkfail(); }
	const bool &filt_eebadsc() { return leptr_v0.filt_eebadsc(); }
	const bool &evt_isRealData() { return leptr_v0.evt_isRealData(); }
	const float &scale1fb() { return leptr_v0.scale1fb(); }
	const float &evt_xsec_incl() { return leptr_v0.evt_xsec_incl(); }
	const float &evt_kfactor() { return leptr_v0.evt_kfactor(); }
	const float &gen_met() { return leptr_v0.gen_met(); }
	const float &gen_metPhi() { return leptr_v0.gen_metPhi(); }
	const float &njets() { return leptr_v0.njets(); }
	const float &ht() { return leptr_v0.ht(); }
	const float &ht_SS() { return leptr_v0.ht_SS(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets() { return leptr_v0.jets(); }
	const vector<float> &jets_disc() { return leptr_v0.jets_disc(); }
	const vector<float> &jets_area() { return leptr_v0.jets_area(); }
	const vector<float> &jets_undoJEC() { return leptr_v0.jets_undoJEC(); }
	const TString &sample() { return leptr_v0.sample(); }
	const int &nFOs_SS() { return leptr_v0.nFOs_SS(); }
	const int &nvtx() { return leptr_v0.nvtx(); }
	const float &rho() { return leptr_v0.rho(); }
	const float &rho_neut_centr() { return leptr_v0.rho_neut_centr(); }
	const float &rho_calo() { return leptr_v0.rho_calo(); }
	const float &rho_calo_centr() { return leptr_v0.rho_calo_centr(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &p4() { return leptr_v0.p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &tag_p4() { return leptr_v0.tag_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4() { return leptr_v0.dilep_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &mc_p4() { return leptr_v0.mc_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &mc_motherp4() { return leptr_v0.mc_motherp4(); }
	const int &mc_motherid() { return leptr_v0.mc_motherid(); }
	const int &id() { return leptr_v0.id(); }
	const bool &isPF() { return leptr_v0.isPF(); }
	const int &idx() { return leptr_v0.idx(); }
	const float &dxyPV() { return leptr_v0.dxyPV(); }
	const float &dZ() { return leptr_v0.dZ(); }
	const float &dxyPV_err() { return leptr_v0.dxyPV_err(); }
	const int &motherID() { return leptr_v0.motherID(); }
	const int &mc_id() { return leptr_v0.mc_id(); }
	const float &RelIso03() { return leptr_v0.RelIso03(); }
	const float &RelIso03EA() { return leptr_v0.RelIso03EA(); }
	const float &tag_RelIso03EA() { return leptr_v0.tag_RelIso03EA(); }
	const float &RelIso03DB() { return leptr_v0.RelIso03DB(); }
	const float &pfChargedHadronIso() { return leptr_v0.pfChargedHadronIso(); }
	const float &pfPhotonIso() { return leptr_v0.pfPhotonIso(); }
	const float &pfNeutralHadronIso() { return leptr_v0.pfNeutralHadronIso(); }
	const float &tkIso() { return leptr_v0.tkIso(); }
	const float &sumPUPt() { return leptr_v0.sumPUPt(); }
	const bool &passes_SS_tight_v3() { return leptr_v0.passes_SS_tight_v3(); }
	const bool &passes_SS_tight_noiso_v3() { return leptr_v0.passes_SS_tight_noiso_v3(); }
	const bool &passes_SS_fo_v3() { return leptr_v0.passes_SS_fo_v3(); }
	const bool &passes_SS_fo_noiso_v3() { return leptr_v0.passes_SS_fo_noiso_v3(); }
	const bool &passes_SS_fo_looseMVA_v3() { return leptr_v0.passes_SS_fo_looseMVA_v3(); }
	const bool &passes_SS_fo_looseMVA_noiso_v3() { return leptr_v0.passes_SS_fo_looseMVA_noiso_v3(); }
	const bool &passes_SS_veto_v3() { return leptr_v0.passes_SS_veto_v3(); }
	const bool &passes_SS_veto_noiso_v3() { return leptr_v0.passes_SS_veto_noiso_v3(); }
	const bool &passes_SS_tight_v4() { return leptr_v0.passes_SS_tight_v4(); }
	const bool &passes_SS_tight_noiso_v4() { return leptr_v0.passes_SS_tight_noiso_v4(); }
	const bool &passes_SS_fo_v4() { return leptr_v0.passes_SS_fo_v4(); }
	const bool &passes_SS_fo_noiso_v4() { return leptr_v0.passes_SS_fo_noiso_v4(); }
	const bool &passes_SS_fo_looseMVA_v4() { return leptr_v0.passes_SS_fo_looseMVA_v4(); }
	const bool &passes_SS_fo_looseMVA_noiso_v4() { return leptr_v0.passes_SS_fo_looseMVA_noiso_v4(); }
	const bool &passes_SS_veto_v4() { return leptr_v0.passes_SS_veto_v4(); }
	const bool &passes_SS_veto_noiso_v4() { return leptr_v0.passes_SS_veto_noiso_v4(); }
	const bool &passes_SS_tight_v5() { return leptr_v0.passes_SS_tight_v5(); }
	const bool &passes_SS_tight_noiso_v5() { return leptr_v0.passes_SS_tight_noiso_v5(); }
	const bool &passes_SS_fo_v5() { return leptr_v0.passes_SS_fo_v5(); }
	const bool &passes_SS_fo_noiso_v5() { return leptr_v0.passes_SS_fo_noiso_v5(); }
	const bool &passes_SS_fo_looseMVA_v5() { return leptr_v0.passes_SS_fo_looseMVA_v5(); }
	const bool &passes_SS_fo_looseMVA_noiso_v5() { return leptr_v0.passes_SS_fo_looseMVA_noiso_v5(); }
	const bool &passes_SS_veto_v5() { return leptr_v0.passes_SS_veto_v5(); }
	const bool &passes_SS_veto_noiso_v5() { return leptr_v0.passes_SS_veto_noiso_v5(); }
	const bool &passes_WW_medium_v2() { return leptr_v0.passes_WW_medium_v2(); }
	const bool &passes_WW_medium_noiso_v2() { return leptr_v0.passes_WW_medium_noiso_v2(); }
	const bool &passes_WW_fo_v2() { return leptr_v0.passes_WW_fo_v2(); }
	const bool &passes_WW_fo_noiso_v2() { return leptr_v0.passes_WW_fo_noiso_v2(); }
	const bool &passes_WW_veto_v2() { return leptr_v0.passes_WW_veto_v2(); }
	const bool &passes_WW_veto_noiso_v2() { return leptr_v0.passes_WW_veto_noiso_v2(); }
	const bool &passes_HAD_veto_v3() { return leptr_v0.passes_HAD_veto_v3(); }
	const bool &passes_HAD_veto_noiso_v3() { return leptr_v0.passes_HAD_veto_noiso_v3(); }
	const bool &passes_HAD_loose_v3() { return leptr_v0.passes_HAD_loose_v3(); }
	const bool &passes_HAD_loose_noiso_v3() { return leptr_v0.passes_HAD_loose_noiso_v3(); }
	const bool &passes_POG_vetoID() { return leptr_v0.passes_POG_vetoID(); }
	const bool &passes_POG_looseID() { return leptr_v0.passes_POG_looseID(); }
	const bool &passes_POG_mediumID() { return leptr_v0.passes_POG_mediumID(); }
	const bool &passes_POG_tightID() { return leptr_v0.passes_POG_tightID(); }
	const float &ip3d() { return leptr_v0.ip3d(); }
	const float &ip3derr() { return leptr_v0.ip3derr(); }
	const int &type() { return leptr_v0.type(); }
	const float &mt() { return leptr_v0.mt(); }
	const float &ptrelv0() { return leptr_v0.ptrelv0(); }
	const float &ptrelv1() { return leptr_v0.ptrelv1(); }
	const float &miniiso() { return leptr_v0.miniiso(); }
	const float &miniisoDB() { return leptr_v0.miniisoDB(); }
	const float &reliso04() { return leptr_v0.reliso04(); }
	const float &annulus04() { return leptr_v0.annulus04(); }
	const float &AbsTrkIso() { return leptr_v0.AbsTrkIso(); }
	const float &TrkAn04() { return leptr_v0.TrkAn04(); }
	const float &iso03sumPt() { return leptr_v0.iso03sumPt(); }
	const float &iso03emEt() { return leptr_v0.iso03emEt(); }
	const float &iso03hadEt() { return leptr_v0.iso03hadEt(); }
	const int &jet_close_lep_idx() { return leptr_v0.jet_close_lep_idx(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep() { return leptr_v0.jet_close_lep(); }
	const float &jet_close_lep_undoJEC() { return leptr_v0.jet_close_lep_undoJEC(); }
	const float &jet_close_lep_area() { return leptr_v0.jet_close_lep_area(); }
	const float &jet_close_L1() { return leptr_v0.jet_close_L1(); }
	const float &jet_close_L1nc() { return leptr_v0.jet_close_L1nc(); }
	const float &jet_close_L1ncmc() { return leptr_v0.jet_close_L1ncmc(); }
	const float &jet_close_L1L2L3() { return leptr_v0.jet_close_L1L2L3(); }
	const float &jet_close_L2L3() { return leptr_v0.jet_close_L2L3(); }
	const float &ptratio() { return leptr_v0.ptratio(); }
	const int &tag_charge() { return leptr_v0.tag_charge(); }
	const int &tag_mc_motherid() { return leptr_v0.tag_mc_motherid(); }
	const float &tag_eSeed() { return leptr_v0.tag_eSeed(); }
	const float &tag_eSCRaw() { return leptr_v0.tag_eSCRaw(); }
	const float &tag_eSC() { return leptr_v0.tag_eSC(); }
	const float &tag_ecalEnergy() { return leptr_v0.tag_ecalEnergy(); }
	const int &exp_innerlayers() { return leptr_v0.exp_innerlayers(); }
	const int &exp_outerlayers() { return leptr_v0.exp_outerlayers(); }
	const int &tag_HLT_Ele27_eta2p1_WPTight_Gsf() { return leptr_v0.tag_HLT_Ele27_eta2p1_WPTight_Gsf(); }
	const int &tag_HLT_Ele32_eta2p1_WPTight_Gsf() { return leptr_v0.tag_HLT_Ele32_eta2p1_WPTight_Gsf(); }
	const int &tag_HLT_IsoMu24() { return leptr_v0.tag_HLT_IsoMu24(); }
	const int &tag_HLT_IsoTkMu24() { return leptr_v0.tag_HLT_IsoTkMu24(); }
	const float &dilep_mass() { return leptr_v0.dilep_mass(); }
	const bool &isRandom() { return leptr_v0.isRandom(); }
	const float &sigmaIEtaIEta_full5x5() { return leptr_v0.sigmaIEtaIEta_full5x5(); }
	const float &sigmaIEtaIEta() { return leptr_v0.sigmaIEtaIEta(); }
	const float &etaSC() { return leptr_v0.etaSC(); }
	const float &dEtaIn() { return leptr_v0.dEtaIn(); }
	const float &dPhiIn() { return leptr_v0.dPhiIn(); }
	const float &hOverE() { return leptr_v0.hOverE(); }
	const float &eSeed() { return leptr_v0.eSeed(); }
	const float &scSeedEta() { return leptr_v0.scSeedEta(); }
	const float &ecalEnergy() { return leptr_v0.ecalEnergy(); }
	const float &eOverPIn() { return leptr_v0.eOverPIn(); }
	const bool &conv_vtx_flag() { return leptr_v0.conv_vtx_flag(); }
	const int &charge() { return leptr_v0.charge(); }
	const int &sccharge() { return leptr_v0.sccharge(); }
	const int &ckf_charge() { return leptr_v0.ckf_charge(); }
	const bool &threeChargeAgree() { return leptr_v0.threeChargeAgree(); }
	const float &mva() { return leptr_v0.mva(); }
	const float &mva_25ns() { return leptr_v0.mva_25ns(); }
	const float &tag_mva_25ns() { return leptr_v0.tag_mva_25ns(); }
	const float &ecalIso() { return leptr_v0.ecalIso(); }
	const float &hcalIso() { return leptr_v0.hcalIso(); }
	const float &ecalPFClusterIso() { return leptr_v0.ecalPFClusterIso(); }
	const float &hcalPFClusterIso() { return leptr_v0.hcalPFClusterIso(); }
	const int &ckf_laywithmeas() { return leptr_v0.ckf_laywithmeas(); }
	const float &sigmaIPhiIPhi_full5x5() { return leptr_v0.sigmaIPhiIPhi_full5x5(); }
	const float &e1x5_full5x5() { return leptr_v0.e1x5_full5x5(); }
	const float &e5x5_full5x5() { return leptr_v0.e5x5_full5x5(); }
	const float &r9_full5x5() { return leptr_v0.r9_full5x5(); }
	const float &tag_r9_full5x5() { return leptr_v0.tag_r9_full5x5(); }
	const float &etaSCwidth() { return leptr_v0.etaSCwidth(); }
	const float &phiSCwidth() { return leptr_v0.phiSCwidth(); }
	const float &eSCRaw() { return leptr_v0.eSCRaw(); }
	const float &eSC() { return leptr_v0.eSC(); }
	const float &eSCPresh() { return leptr_v0.eSCPresh(); }
	const float &ckf_chi2() { return leptr_v0.ckf_chi2(); }
	const int &ckf_ndof() { return leptr_v0.ckf_ndof(); }
	const float &chi2() { return leptr_v0.chi2(); }
	const int &ndof() { return leptr_v0.ndof(); }
	const float &fbrem() { return leptr_v0.fbrem(); }
	const float &eOverPOut() { return leptr_v0.eOverPOut(); }
	const float &dEtaOut() { return leptr_v0.dEtaOut(); }
	const float &dPhiOut() { return leptr_v0.dPhiOut(); }
	const int &gsf_validHits() { return leptr_v0.gsf_validHits(); }
	const float &conv_vtx_prob() { return leptr_v0.conv_vtx_prob(); }
	const int &pid_PFMuon() { return leptr_v0.pid_PFMuon(); }
	const float &gfit_chi2() { return leptr_v0.gfit_chi2(); }
	const int &gfit_validSTAHits() { return leptr_v0.gfit_validSTAHits(); }
	const int &numberOfMatchedStations() { return leptr_v0.numberOfMatchedStations(); }
	const int &validPixelHits() { return leptr_v0.validPixelHits(); }
	const int &nlayers() { return leptr_v0.nlayers(); }
	const float &chi2LocalPosition() { return leptr_v0.chi2LocalPosition(); }
	const float &trkKink() { return leptr_v0.trkKink(); }
	const int &validHits() { return leptr_v0.validHits(); }
	const int &lostHits() { return leptr_v0.lostHits(); }
	const float &segmCompatibility() { return leptr_v0.segmCompatibility(); }
	const int &HLT_Mu8() { return leptr_v0.HLT_Mu8(); }
	const int &HLT_Mu17() { return leptr_v0.HLT_Mu17(); }
	const int &HLT_Mu8_TrkIsoVVL() { return leptr_v0.HLT_Mu8_TrkIsoVVL(); }
	const int &HLT_Mu17_TrkIsoVVL() { return leptr_v0.HLT_Mu17_TrkIsoVVL(); }
	const int &HLT_IsoMu24() { return leptr_v0.HLT_IsoMu24(); }
	const int &HLT_IsoTkMu24() { return leptr_v0.HLT_IsoTkMu24(); }
	const int &HLT_Mu50() { return leptr_v0.HLT_Mu50(); }
	const int &HLT_Mu55() { return leptr_v0.HLT_Mu55(); }
	const int &HLT_TkMu50() { return leptr_v0.HLT_TkMu50(); }
	const int &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg() { return leptr_v0.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_TrailingLeg(); }
	const int &HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg() { return leptr_v0.HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_LeadingLeg(); }
	const int &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg() { return leptr_v0.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_TrailingLeg(); }
	const int &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg() { return leptr_v0.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_LeadingLeg(); }
	const int &HLT_Ele8_CaloIdM_TrackIdM_PFJet30() { return leptr_v0.HLT_Ele8_CaloIdM_TrackIdM_PFJet30(); }
	const int &HLT_Ele12_CaloIdM_TrackIdM_PFJet30() { return leptr_v0.HLT_Ele12_CaloIdM_TrackIdM_PFJet30(); }
	const int &HLT_Ele17_CaloIdM_TrackIdM_PFJet30() { return leptr_v0.HLT_Ele17_CaloIdM_TrackIdM_PFJet30(); }
	const int &HLT_Ele23_CaloIdM_TrackIdM_PFJet30() { return leptr_v0.HLT_Ele23_CaloIdM_TrackIdM_PFJet30(); }
	const int &HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30() { return leptr_v0.HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30(); }
	const int &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30() { return leptr_v0.HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30(); }
	const int &HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30() { return leptr_v0.HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30(); }
	const int &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30() { return leptr_v0.HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30(); }
	const int &HLT_Ele27_eta2p1_WPTight_Gsf() { return leptr_v0.HLT_Ele27_eta2p1_WPTight_Gsf(); }
	const int &HLT_Ele32_eta2p1_WPTight_Gsf() { return leptr_v0.HLT_Ele32_eta2p1_WPTight_Gsf(); }
	const int &HLT_Ele105_CaloIdVT_GsfTrkIdT() { return leptr_v0.HLT_Ele105_CaloIdVT_GsfTrkIdT(); }
	const int &HLT_Ele115_CaloIdVT_GsfTrkIdT() { return leptr_v0.HLT_Ele115_CaloIdVT_GsfTrkIdT(); }
	const int &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg() { return leptr_v0.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg(); }
	const int &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg() { return leptr_v0.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg(); }
	const int &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1() { return leptr_v0.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_L1(); }
	const int &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() { return leptr_v0.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL(); }
	const int &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg() { return leptr_v0.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_LeadingLeg(); }
	const int &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg() { return leptr_v0.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_TrailingLeg(); }
	const int &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1() { return leptr_v0.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_L1(); }
	const int &HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL() { return leptr_v0.HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL(); }
}
