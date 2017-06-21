#include "triboson_v1.h"
triboson_v1 cms3;

void triboson_v1::Init(TTree *tree) {
	lep_p4_branch = 0;
	if (tree->GetBranch("lep_p4") != 0) {
		lep_p4_branch = tree->GetBranch("lep_p4");
		if (lep_p4_branch) {lep_p4_branch->SetAddress(&lep_p4_);}
	}
	isotr_p4_branch = 0;
	if (tree->GetBranch("isotr_p4") != 0) {
		isotr_p4_branch = tree->GetBranch("isotr_p4");
		if (isotr_p4_branch) {isotr_p4_branch->SetAddress(&isotr_p4_);}
	}
	gamma_p4_branch = 0;
	if (tree->GetBranch("gamma_p4") != 0) {
		gamma_p4_branch = tree->GetBranch("gamma_p4");
		if (gamma_p4_branch) {gamma_p4_branch->SetAddress(&gamma_p4_);}
	}
	genPart_p4_branch = 0;
	if (tree->GetBranch("genPart_p4") != 0) {
		genPart_p4_branch = tree->GetBranch("genPart_p4");
		if (genPart_p4_branch) {genPart_p4_branch->SetAddress(&genPart_p4_);}
	}
	jets_p4_branch = 0;
	if (tree->GetBranch("jets_p4") != 0) {
		jets_p4_branch = tree->GetBranch("jets_p4");
		if (jets_p4_branch) {jets_p4_branch->SetAddress(&jets_p4_);}
	}
	removed_jets_p4_branch = 0;
	if (tree->GetBranch("removed_jets_p4") != 0) {
		removed_jets_p4_branch = tree->GetBranch("removed_jets_p4");
		if (removed_jets_p4_branch) {removed_jets_p4_branch->SetAddress(&removed_jets_p4_);}
	}
	jets_medb_p4_branch = 0;
	if (tree->GetBranch("jets_medb_p4") != 0) {
		jets_medb_p4_branch = tree->GetBranch("jets_medb_p4");
		if (jets_medb_p4_branch) {jets_medb_p4_branch->SetAddress(&jets_medb_p4_);}
	}
	jets_up_p4_branch = 0;
	if (tree->GetBranch("jets_up_p4") != 0) {
		jets_up_p4_branch = tree->GetBranch("jets_up_p4");
		if (jets_up_p4_branch) {jets_up_p4_branch->SetAddress(&jets_up_p4_);}
	}
	jets_medb_up_p4_branch = 0;
	if (tree->GetBranch("jets_medb_up_p4") != 0) {
		jets_medb_up_p4_branch = tree->GetBranch("jets_medb_up_p4");
		if (jets_medb_up_p4_branch) {jets_medb_up_p4_branch->SetAddress(&jets_medb_up_p4_);}
	}
	jets_dn_p4_branch = 0;
	if (tree->GetBranch("jets_dn_p4") != 0) {
		jets_dn_p4_branch = tree->GetBranch("jets_dn_p4");
		if (jets_dn_p4_branch) {jets_dn_p4_branch->SetAddress(&jets_dn_p4_);}
	}
	jets_medb_dn_p4_branch = 0;
	if (tree->GetBranch("jets_medb_dn_p4") != 0) {
		jets_medb_dn_p4_branch = tree->GetBranch("jets_medb_dn_p4");
		if (jets_medb_dn_p4_branch) {jets_medb_dn_p4_branch->SetAddress(&jets_medb_dn_p4_);}
	}
  tree->SetMakeClass(1);
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	lumi_branch = 0;
	if (tree->GetBranch("lumi") != 0) {
		lumi_branch = tree->GetBranch("lumi");
		if (lumi_branch) {lumi_branch->SetAddress(&lumi_);}
	}
	evt_branch = 0;
	if (tree->GetBranch("evt") != 0) {
		evt_branch = tree->GetBranch("evt");
		if (evt_branch) {evt_branch->SetAddress(&evt_);}
	}
	isData_branch = 0;
	if (tree->GetBranch("isData") != 0) {
		isData_branch = tree->GetBranch("isData");
		if (isData_branch) {isData_branch->SetAddress(&isData_);}
	}
	evt_passgoodrunlist_branch = 0;
	if (tree->GetBranch("evt_passgoodrunlist") != 0) {
		evt_passgoodrunlist_branch = tree->GetBranch("evt_passgoodrunlist");
		if (evt_passgoodrunlist_branch) {evt_passgoodrunlist_branch->SetAddress(&evt_passgoodrunlist_);}
	}
	evt_scale1fb_branch = 0;
	if (tree->GetBranch("evt_scale1fb") != 0) {
		evt_scale1fb_branch = tree->GetBranch("evt_scale1fb");
		if (evt_scale1fb_branch) {evt_scale1fb_branch->SetAddress(&evt_scale1fb_);}
	}
	evt_xsec_branch = 0;
	if (tree->GetBranch("evt_xsec") != 0) {
		evt_xsec_branch = tree->GetBranch("evt_xsec");
		if (evt_xsec_branch) {evt_xsec_branch->SetAddress(&evt_xsec_);}
	}
	evt_kfactor_branch = 0;
	if (tree->GetBranch("evt_kfactor") != 0) {
		evt_kfactor_branch = tree->GetBranch("evt_kfactor");
		if (evt_kfactor_branch) {evt_kfactor_branch->SetAddress(&evt_kfactor_);}
	}
	evt_filter_branch = 0;
	if (tree->GetBranch("evt_filter") != 0) {
		evt_filter_branch = tree->GetBranch("evt_filter");
		if (evt_filter_branch) {evt_filter_branch->SetAddress(&evt_filter_);}
	}
	evt_nEvts_branch = 0;
	if (tree->GetBranch("evt_nEvts") != 0) {
		evt_nEvts_branch = tree->GetBranch("evt_nEvts");
		if (evt_nEvts_branch) {evt_nEvts_branch->SetAddress(&evt_nEvts_);}
	}
	evt_dataset_branch = 0;
	if (tree->GetBranch("evt_dataset") != 0) {
		evt_dataset_branch = tree->GetBranch("evt_dataset");
		if (evt_dataset_branch) {evt_dataset_branch->SetAddress(&evt_dataset_);}
	}
	puWeight_branch = 0;
	if (tree->GetBranch("puWeight") != 0) {
		puWeight_branch = tree->GetBranch("puWeight");
		if (puWeight_branch) {puWeight_branch->SetAddress(&puWeight_);}
	}
	nVert_branch = 0;
	if (tree->GetBranch("nVert") != 0) {
		nVert_branch = tree->GetBranch("nVert");
		if (nVert_branch) {nVert_branch->SetAddress(&nVert_);}
	}
	nTrueInt_branch = 0;
	if (tree->GetBranch("nTrueInt") != 0) {
		nTrueInt_branch = tree->GetBranch("nTrueInt");
		if (nTrueInt_branch) {nTrueInt_branch->SetAddress(&nTrueInt_);}
	}
	rho_branch = 0;
	if (tree->GetBranch("rho") != 0) {
		rho_branch = tree->GetBranch("rho");
		if (rho_branch) {rho_branch->SetAddress(&rho_);}
	}
	gen_ht_branch = 0;
	if (tree->GetBranch("gen_ht") != 0) {
		gen_ht_branch = tree->GetBranch("gen_ht");
		if (gen_ht_branch) {gen_ht_branch->SetAddress(&gen_ht_);}
	}
	nBJetTight_branch = 0;
	if (tree->GetBranch("nBJetTight") != 0) {
		nBJetTight_branch = tree->GetBranch("nBJetTight");
		if (nBJetTight_branch) {nBJetTight_branch->SetAddress(&nBJetTight_);}
	}
	nBJetMedium_branch = 0;
	if (tree->GetBranch("nBJetMedium") != 0) {
		nBJetMedium_branch = tree->GetBranch("nBJetMedium");
		if (nBJetMedium_branch) {nBJetMedium_branch->SetAddress(&nBJetMedium_);}
	}
	nBJetLoose_branch = 0;
	if (tree->GetBranch("nBJetLoose") != 0) {
		nBJetLoose_branch = tree->GetBranch("nBJetLoose");
		if (nBJetLoose_branch) {nBJetLoose_branch->SetAddress(&nBJetLoose_);}
	}
	nBJetTight_up_branch = 0;
	if (tree->GetBranch("nBJetTight_up") != 0) {
		nBJetTight_up_branch = tree->GetBranch("nBJetTight_up");
		if (nBJetTight_up_branch) {nBJetTight_up_branch->SetAddress(&nBJetTight_up_);}
	}
	nBJetMedium_up_branch = 0;
	if (tree->GetBranch("nBJetMedium_up") != 0) {
		nBJetMedium_up_branch = tree->GetBranch("nBJetMedium_up");
		if (nBJetMedium_up_branch) {nBJetMedium_up_branch->SetAddress(&nBJetMedium_up_);}
	}
	nBJetLoose_up_branch = 0;
	if (tree->GetBranch("nBJetLoose_up") != 0) {
		nBJetLoose_up_branch = tree->GetBranch("nBJetLoose_up");
		if (nBJetLoose_up_branch) {nBJetLoose_up_branch->SetAddress(&nBJetLoose_up_);}
	}
	nBJetTight_dn_branch = 0;
	if (tree->GetBranch("nBJetTight_dn") != 0) {
		nBJetTight_dn_branch = tree->GetBranch("nBJetTight_dn");
		if (nBJetTight_dn_branch) {nBJetTight_dn_branch->SetAddress(&nBJetTight_dn_);}
	}
	nBJetMedium_dn_branch = 0;
	if (tree->GetBranch("nBJetMedium_dn") != 0) {
		nBJetMedium_dn_branch = tree->GetBranch("nBJetMedium_dn");
		if (nBJetMedium_dn_branch) {nBJetMedium_dn_branch->SetAddress(&nBJetMedium_dn_);}
	}
	nBJetLoose_dn_branch = 0;
	if (tree->GetBranch("nBJetLoose_dn") != 0) {
		nBJetLoose_dn_branch = tree->GetBranch("nBJetLoose_dn");
		if (nBJetLoose_dn_branch) {nBJetLoose_dn_branch->SetAddress(&nBJetLoose_dn_);}
	}
	nJet200MuFrac50DphiMet_branch = 0;
	if (tree->GetBranch("nJet200MuFrac50DphiMet") != 0) {
		nJet200MuFrac50DphiMet_branch = tree->GetBranch("nJet200MuFrac50DphiMet");
		if (nJet200MuFrac50DphiMet_branch) {nJet200MuFrac50DphiMet_branch->SetAddress(&nJet200MuFrac50DphiMet_);}
	}
	nMuons10_branch = 0;
	if (tree->GetBranch("nMuons10") != 0) {
		nMuons10_branch = tree->GetBranch("nMuons10");
		if (nMuons10_branch) {nMuons10_branch->SetAddress(&nMuons10_);}
	}
	nBadMuons20_branch = 0;
	if (tree->GetBranch("nBadMuons20") != 0) {
		nBadMuons20_branch = tree->GetBranch("nBadMuons20");
		if (nBadMuons20_branch) {nBadMuons20_branch->SetAddress(&nBadMuons20_);}
	}
	nElectrons10_branch = 0;
	if (tree->GetBranch("nElectrons10") != 0) {
		nElectrons10_branch = tree->GetBranch("nElectrons10");
		if (nElectrons10_branch) {nElectrons10_branch->SetAddress(&nElectrons10_);}
	}
	nGammas20_branch = 0;
	if (tree->GetBranch("nGammas20") != 0) {
		nGammas20_branch = tree->GetBranch("nGammas20");
		if (nGammas20_branch) {nGammas20_branch->SetAddress(&nGammas20_);}
	}
	nTaus20_branch = 0;
	if (tree->GetBranch("nTaus20") != 0) {
		nTaus20_branch = tree->GetBranch("nTaus20");
		if (nTaus20_branch) {nTaus20_branch->SetAddress(&nTaus20_);}
	}
	met_pt_branch = 0;
	if (tree->GetBranch("met_pt") != 0) {
		met_pt_branch = tree->GetBranch("met_pt");
		if (met_pt_branch) {met_pt_branch->SetAddress(&met_pt_);}
	}
	met_phi_branch = 0;
	if (tree->GetBranch("met_phi") != 0) {
		met_phi_branch = tree->GetBranch("met_phi");
		if (met_phi_branch) {met_phi_branch->SetAddress(&met_phi_);}
	}
	met_calo_pt_branch = 0;
	if (tree->GetBranch("met_calo_pt") != 0) {
		met_calo_pt_branch = tree->GetBranch("met_calo_pt");
		if (met_calo_pt_branch) {met_calo_pt_branch->SetAddress(&met_calo_pt_);}
	}
	met_calo_phi_branch = 0;
	if (tree->GetBranch("met_calo_phi") != 0) {
		met_calo_phi_branch = tree->GetBranch("met_calo_phi");
		if (met_calo_phi_branch) {met_calo_phi_branch->SetAddress(&met_calo_phi_);}
	}
	met_miniaod_pt_branch = 0;
	if (tree->GetBranch("met_miniaod_pt") != 0) {
		met_miniaod_pt_branch = tree->GetBranch("met_miniaod_pt");
		if (met_miniaod_pt_branch) {met_miniaod_pt_branch->SetAddress(&met_miniaod_pt_);}
	}
	met_miniaod_phi_branch = 0;
	if (tree->GetBranch("met_miniaod_phi") != 0) {
		met_miniaod_phi_branch = tree->GetBranch("met_miniaod_phi");
		if (met_miniaod_phi_branch) {met_miniaod_phi_branch->SetAddress(&met_miniaod_phi_);}
	}
	met_muegclean_pt_branch = 0;
	if (tree->GetBranch("met_muegclean_pt") != 0) {
		met_muegclean_pt_branch = tree->GetBranch("met_muegclean_pt");
		if (met_muegclean_pt_branch) {met_muegclean_pt_branch->SetAddress(&met_muegclean_pt_);}
	}
	met_muegclean_phi_branch = 0;
	if (tree->GetBranch("met_muegclean_phi") != 0) {
		met_muegclean_phi_branch = tree->GetBranch("met_muegclean_phi");
		if (met_muegclean_phi_branch) {met_muegclean_phi_branch->SetAddress(&met_muegclean_phi_);}
	}
	met_rawPt_branch = 0;
	if (tree->GetBranch("met_rawPt") != 0) {
		met_rawPt_branch = tree->GetBranch("met_rawPt");
		if (met_rawPt_branch) {met_rawPt_branch->SetAddress(&met_rawPt_);}
	}
	met_rawPhi_branch = 0;
	if (tree->GetBranch("met_rawPhi") != 0) {
		met_rawPhi_branch = tree->GetBranch("met_rawPhi");
		if (met_rawPhi_branch) {met_rawPhi_branch->SetAddress(&met_rawPhi_);}
	}
	met_genPt_branch = 0;
	if (tree->GetBranch("met_genPt") != 0) {
		met_genPt_branch = tree->GetBranch("met_genPt");
		if (met_genPt_branch) {met_genPt_branch->SetAddress(&met_genPt_);}
	}
	met_genPhi_branch = 0;
	if (tree->GetBranch("met_genPhi") != 0) {
		met_genPhi_branch = tree->GetBranch("met_genPhi");
		if (met_genPhi_branch) {met_genPhi_branch->SetAddress(&met_genPhi_);}
	}
	sumet_raw_branch = 0;
	if (tree->GetBranch("sumet_raw") != 0) {
		sumet_raw_branch = tree->GetBranch("sumet_raw");
		if (sumet_raw_branch) {sumet_raw_branch->SetAddress(&sumet_raw_);}
	}
	Flag_ecalLaserCorrFilter_branch = 0;
	if (tree->GetBranch("Flag_ecalLaserCorrFilter") != 0) {
		Flag_ecalLaserCorrFilter_branch = tree->GetBranch("Flag_ecalLaserCorrFilter");
		if (Flag_ecalLaserCorrFilter_branch) {Flag_ecalLaserCorrFilter_branch->SetAddress(&Flag_ecalLaserCorrFilter_);}
	}
	Flag_hcalLaserEventFilter_branch = 0;
	if (tree->GetBranch("Flag_hcalLaserEventFilter") != 0) {
		Flag_hcalLaserEventFilter_branch = tree->GetBranch("Flag_hcalLaserEventFilter");
		if (Flag_hcalLaserEventFilter_branch) {Flag_hcalLaserEventFilter_branch->SetAddress(&Flag_hcalLaserEventFilter_);}
	}
	Flag_trackingFailureFilter_branch = 0;
	if (tree->GetBranch("Flag_trackingFailureFilter") != 0) {
		Flag_trackingFailureFilter_branch = tree->GetBranch("Flag_trackingFailureFilter");
		if (Flag_trackingFailureFilter_branch) {Flag_trackingFailureFilter_branch->SetAddress(&Flag_trackingFailureFilter_);}
	}
	Flag_CSCTightHaloFilter_branch = 0;
	if (tree->GetBranch("Flag_CSCTightHaloFilter") != 0) {
		Flag_CSCTightHaloFilter_branch = tree->GetBranch("Flag_CSCTightHaloFilter");
		if (Flag_CSCTightHaloFilter_branch) {Flag_CSCTightHaloFilter_branch->SetAddress(&Flag_CSCTightHaloFilter_);}
	}
	Flag_HBHENoiseFilter_branch = 0;
	if (tree->GetBranch("Flag_HBHENoiseFilter") != 0) {
		Flag_HBHENoiseFilter_branch = tree->GetBranch("Flag_HBHENoiseFilter");
		if (Flag_HBHENoiseFilter_branch) {Flag_HBHENoiseFilter_branch->SetAddress(&Flag_HBHENoiseFilter_);}
	}
	Flag_HBHEIsoNoiseFilter_branch = 0;
	if (tree->GetBranch("Flag_HBHEIsoNoiseFilter") != 0) {
		Flag_HBHEIsoNoiseFilter_branch = tree->GetBranch("Flag_HBHEIsoNoiseFilter");
		if (Flag_HBHEIsoNoiseFilter_branch) {Flag_HBHEIsoNoiseFilter_branch->SetAddress(&Flag_HBHEIsoNoiseFilter_);}
	}
	Flag_CSCTightHalo2015Filter_branch = 0;
	if (tree->GetBranch("Flag_CSCTightHalo2015Filter") != 0) {
		Flag_CSCTightHalo2015Filter_branch = tree->GetBranch("Flag_CSCTightHalo2015Filter");
		if (Flag_CSCTightHalo2015Filter_branch) {Flag_CSCTightHalo2015Filter_branch->SetAddress(&Flag_CSCTightHalo2015Filter_);}
	}
	Flag_EcalDeadCellTriggerPrimitiveFilter_branch = 0;
	if (tree->GetBranch("Flag_EcalDeadCellTriggerPrimitiveFilter") != 0) {
		Flag_EcalDeadCellTriggerPrimitiveFilter_branch = tree->GetBranch("Flag_EcalDeadCellTriggerPrimitiveFilter");
		if (Flag_EcalDeadCellTriggerPrimitiveFilter_branch) {Flag_EcalDeadCellTriggerPrimitiveFilter_branch->SetAddress(&Flag_EcalDeadCellTriggerPrimitiveFilter_);}
	}
	Flag_goodVertices_branch = 0;
	if (tree->GetBranch("Flag_goodVertices") != 0) {
		Flag_goodVertices_branch = tree->GetBranch("Flag_goodVertices");
		if (Flag_goodVertices_branch) {Flag_goodVertices_branch->SetAddress(&Flag_goodVertices_);}
	}
	Flag_eeBadScFilter_branch = 0;
	if (tree->GetBranch("Flag_eeBadScFilter") != 0) {
		Flag_eeBadScFilter_branch = tree->GetBranch("Flag_eeBadScFilter");
		if (Flag_eeBadScFilter_branch) {Flag_eeBadScFilter_branch->SetAddress(&Flag_eeBadScFilter_);}
	}
	Flag_globalTightHalo2016_branch = 0;
	if (tree->GetBranch("Flag_globalTightHalo2016") != 0) {
		Flag_globalTightHalo2016_branch = tree->GetBranch("Flag_globalTightHalo2016");
		if (Flag_globalTightHalo2016_branch) {Flag_globalTightHalo2016_branch->SetAddress(&Flag_globalTightHalo2016_);}
	}
	Flag_badMuonFilter_branch = 0;
	if (tree->GetBranch("Flag_badMuonFilter") != 0) {
		Flag_badMuonFilter_branch = tree->GetBranch("Flag_badMuonFilter");
		if (Flag_badMuonFilter_branch) {Flag_badMuonFilter_branch->SetAddress(&Flag_badMuonFilter_);}
	}
	Flag_badChargedCandidateFilter_branch = 0;
	if (tree->GetBranch("Flag_badChargedCandidateFilter") != 0) {
		Flag_badChargedCandidateFilter_branch = tree->GetBranch("Flag_badChargedCandidateFilter");
		if (Flag_badChargedCandidateFilter_branch) {Flag_badChargedCandidateFilter_branch->SetAddress(&Flag_badChargedCandidateFilter_);}
	}
	Flag_badMuonFilterv2_branch = 0;
	if (tree->GetBranch("Flag_badMuonFilterv2") != 0) {
		Flag_badMuonFilterv2_branch = tree->GetBranch("Flag_badMuonFilterv2");
		if (Flag_badMuonFilterv2_branch) {Flag_badMuonFilterv2_branch->SetAddress(&Flag_badMuonFilterv2_);}
	}
	Flag_badChargedCandidateFilterv2_branch = 0;
	if (tree->GetBranch("Flag_badChargedCandidateFilterv2") != 0) {
		Flag_badChargedCandidateFilterv2_branch = tree->GetBranch("Flag_badChargedCandidateFilterv2");
		if (Flag_badChargedCandidateFilterv2_branch) {Flag_badChargedCandidateFilterv2_branch->SetAddress(&Flag_badChargedCandidateFilterv2_);}
	}
	Flag_badMuons_branch = 0;
	if (tree->GetBranch("Flag_badMuons") != 0) {
		Flag_badMuons_branch = tree->GetBranch("Flag_badMuons");
		if (Flag_badMuons_branch) {Flag_badMuons_branch->SetAddress(&Flag_badMuons_);}
	}
	Flag_duplicateMuons_branch = 0;
	if (tree->GetBranch("Flag_duplicateMuons") != 0) {
		Flag_duplicateMuons_branch = tree->GetBranch("Flag_duplicateMuons");
		if (Flag_duplicateMuons_branch) {Flag_duplicateMuons_branch->SetAddress(&Flag_duplicateMuons_);}
	}
	Flag_noBadMuons_branch = 0;
	if (tree->GetBranch("Flag_noBadMuons") != 0) {
		Flag_noBadMuons_branch = tree->GetBranch("Flag_noBadMuons");
		if (Flag_noBadMuons_branch) {Flag_noBadMuons_branch->SetAddress(&Flag_noBadMuons_);}
	}
	HLT_singleEl_branch = 0;
	if (tree->GetBranch("HLT_singleEl") != 0) {
		HLT_singleEl_branch = tree->GetBranch("HLT_singleEl");
		if (HLT_singleEl_branch) {HLT_singleEl_branch->SetAddress(&HLT_singleEl_);}
	}
	HLT_singleMu_branch = 0;
	if (tree->GetBranch("HLT_singleMu") != 0) {
		HLT_singleMu_branch = tree->GetBranch("HLT_singleMu");
		if (HLT_singleMu_branch) {HLT_singleMu_branch->SetAddress(&HLT_singleMu_);}
	}
	HLT_singleMu_noiso_branch = 0;
	if (tree->GetBranch("HLT_singleMu_noiso") != 0) {
		HLT_singleMu_noiso_branch = tree->GetBranch("HLT_singleMu_noiso");
		if (HLT_singleMu_noiso_branch) {HLT_singleMu_noiso_branch->SetAddress(&HLT_singleMu_noiso_);}
	}
	HLT_DoubleEl_noiso_branch = 0;
	if (tree->GetBranch("HLT_DoubleEl_noiso") != 0) {
		HLT_DoubleEl_noiso_branch = tree->GetBranch("HLT_DoubleEl_noiso");
		if (HLT_DoubleEl_noiso_branch) {HLT_DoubleEl_noiso_branch->SetAddress(&HLT_DoubleEl_noiso_);}
	}
	HLT_DoubleEl_branch = 0;
	if (tree->GetBranch("HLT_DoubleEl") != 0) {
		HLT_DoubleEl_branch = tree->GetBranch("HLT_DoubleEl");
		if (HLT_DoubleEl_branch) {HLT_DoubleEl_branch->SetAddress(&HLT_DoubleEl_);}
	}
	HLT_DoubleEl_DZ_branch = 0;
	if (tree->GetBranch("HLT_DoubleEl_DZ") != 0) {
		HLT_DoubleEl_DZ_branch = tree->GetBranch("HLT_DoubleEl_DZ");
		if (HLT_DoubleEl_DZ_branch) {HLT_DoubleEl_DZ_branch->SetAddress(&HLT_DoubleEl_DZ_);}
	}
	HLT_DoubleEl_DZ_2_branch = 0;
	if (tree->GetBranch("HLT_DoubleEl_DZ_2") != 0) {
		HLT_DoubleEl_DZ_2_branch = tree->GetBranch("HLT_DoubleEl_DZ_2");
		if (HLT_DoubleEl_DZ_2_branch) {HLT_DoubleEl_DZ_2_branch->SetAddress(&HLT_DoubleEl_DZ_2_);}
	}
	HLT_MuEG_branch = 0;
	if (tree->GetBranch("HLT_MuEG") != 0) {
		HLT_MuEG_branch = tree->GetBranch("HLT_MuEG");
		if (HLT_MuEG_branch) {HLT_MuEG_branch->SetAddress(&HLT_MuEG_);}
	}
	HLT_MuEG_2_branch = 0;
	if (tree->GetBranch("HLT_MuEG_2") != 0) {
		HLT_MuEG_2_branch = tree->GetBranch("HLT_MuEG_2");
		if (HLT_MuEG_2_branch) {HLT_MuEG_2_branch->SetAddress(&HLT_MuEG_2_);}
	}
	HLT_MuEG_noiso_branch = 0;
	if (tree->GetBranch("HLT_MuEG_noiso") != 0) {
		HLT_MuEG_noiso_branch = tree->GetBranch("HLT_MuEG_noiso");
		if (HLT_MuEG_noiso_branch) {HLT_MuEG_noiso_branch->SetAddress(&HLT_MuEG_noiso_);}
	}
	HLT_MuEG_noiso_2_branch = 0;
	if (tree->GetBranch("HLT_MuEG_noiso_2") != 0) {
		HLT_MuEG_noiso_2_branch = tree->GetBranch("HLT_MuEG_noiso_2");
		if (HLT_MuEG_noiso_2_branch) {HLT_MuEG_noiso_2_branch->SetAddress(&HLT_MuEG_noiso_2_);}
	}
	HLT_Mu8_EG17_branch = 0;
	if (tree->GetBranch("HLT_Mu8_EG17") != 0) {
		HLT_Mu8_EG17_branch = tree->GetBranch("HLT_Mu8_EG17");
		if (HLT_Mu8_EG17_branch) {HLT_Mu8_EG17_branch->SetAddress(&HLT_Mu8_EG17_);}
	}
	HLT_Mu8_EG23_branch = 0;
	if (tree->GetBranch("HLT_Mu8_EG23") != 0) {
		HLT_Mu8_EG23_branch = tree->GetBranch("HLT_Mu8_EG23");
		if (HLT_Mu8_EG23_branch) {HLT_Mu8_EG23_branch->SetAddress(&HLT_Mu8_EG23_);}
	}
	HLT_Mu8_EG23_DZ_branch = 0;
	if (tree->GetBranch("HLT_Mu8_EG23_DZ") != 0) {
		HLT_Mu8_EG23_DZ_branch = tree->GetBranch("HLT_Mu8_EG23_DZ");
		if (HLT_Mu8_EG23_DZ_branch) {HLT_Mu8_EG23_DZ_branch->SetAddress(&HLT_Mu8_EG23_DZ_);}
	}
	HLT_Mu12_EG23_DZ_branch = 0;
	if (tree->GetBranch("HLT_Mu12_EG23_DZ") != 0) {
		HLT_Mu12_EG23_DZ_branch = tree->GetBranch("HLT_Mu12_EG23_DZ");
		if (HLT_Mu12_EG23_DZ_branch) {HLT_Mu12_EG23_DZ_branch->SetAddress(&HLT_Mu12_EG23_DZ_);}
	}
	HLT_Mu17_EG12_branch = 0;
	if (tree->GetBranch("HLT_Mu17_EG12") != 0) {
		HLT_Mu17_EG12_branch = tree->GetBranch("HLT_Mu17_EG12");
		if (HLT_Mu17_EG12_branch) {HLT_Mu17_EG12_branch->SetAddress(&HLT_Mu17_EG12_);}
	}
	HLT_Mu23_EG8_branch = 0;
	if (tree->GetBranch("HLT_Mu23_EG8") != 0) {
		HLT_Mu23_EG8_branch = tree->GetBranch("HLT_Mu23_EG8");
		if (HLT_Mu23_EG8_branch) {HLT_Mu23_EG8_branch->SetAddress(&HLT_Mu23_EG8_);}
	}
	HLT_Mu23_EG8_DZ_branch = 0;
	if (tree->GetBranch("HLT_Mu23_EG8_DZ") != 0) {
		HLT_Mu23_EG8_DZ_branch = tree->GetBranch("HLT_Mu23_EG8_DZ");
		if (HLT_Mu23_EG8_DZ_branch) {HLT_Mu23_EG8_DZ_branch->SetAddress(&HLT_Mu23_EG8_DZ_);}
	}
	HLT_Mu23_EG12_branch = 0;
	if (tree->GetBranch("HLT_Mu23_EG12") != 0) {
		HLT_Mu23_EG12_branch = tree->GetBranch("HLT_Mu23_EG12");
		if (HLT_Mu23_EG12_branch) {HLT_Mu23_EG12_branch->SetAddress(&HLT_Mu23_EG12_);}
	}
	HLT_Mu23_EG12_DZ_branch = 0;
	if (tree->GetBranch("HLT_Mu23_EG12_DZ") != 0) {
		HLT_Mu23_EG12_DZ_branch = tree->GetBranch("HLT_Mu23_EG12_DZ");
		if (HLT_Mu23_EG12_DZ_branch) {HLT_Mu23_EG12_DZ_branch->SetAddress(&HLT_Mu23_EG12_DZ_);}
	}
	HLT_DoubleMu_noiso_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_noiso") != 0) {
		HLT_DoubleMu_noiso_branch = tree->GetBranch("HLT_DoubleMu_noiso");
		if (HLT_DoubleMu_noiso_branch) {HLT_DoubleMu_noiso_branch->SetAddress(&HLT_DoubleMu_noiso_);}
	}
	HLT_DoubleMu_noiso_27_8_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_noiso_27_8") != 0) {
		HLT_DoubleMu_noiso_27_8_branch = tree->GetBranch("HLT_DoubleMu_noiso_27_8");
		if (HLT_DoubleMu_noiso_27_8_branch) {HLT_DoubleMu_noiso_27_8_branch->SetAddress(&HLT_DoubleMu_noiso_27_8_);}
	}
	HLT_DoubleMu_noiso_30_11_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_noiso_30_11") != 0) {
		HLT_DoubleMu_noiso_30_11_branch = tree->GetBranch("HLT_DoubleMu_noiso_30_11");
		if (HLT_DoubleMu_noiso_30_11_branch) {HLT_DoubleMu_noiso_30_11_branch->SetAddress(&HLT_DoubleMu_noiso_30_11_);}
	}
	HLT_DoubleMu_noiso_40_11_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_noiso_40_11") != 0) {
		HLT_DoubleMu_noiso_40_11_branch = tree->GetBranch("HLT_DoubleMu_noiso_40_11");
		if (HLT_DoubleMu_noiso_40_11_branch) {HLT_DoubleMu_noiso_40_11_branch->SetAddress(&HLT_DoubleMu_noiso_40_11_);}
	}
	HLT_DoubleMu_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu") != 0) {
		HLT_DoubleMu_branch = tree->GetBranch("HLT_DoubleMu");
		if (HLT_DoubleMu_branch) {HLT_DoubleMu_branch->SetAddress(&HLT_DoubleMu_);}
	}
	HLT_DoubleMu_tk_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_tk") != 0) {
		HLT_DoubleMu_tk_branch = tree->GetBranch("HLT_DoubleMu_tk");
		if (HLT_DoubleMu_tk_branch) {HLT_DoubleMu_tk_branch->SetAddress(&HLT_DoubleMu_tk_);}
	}
	HLT_DoubleMu_dbltk_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_dbltk") != 0) {
		HLT_DoubleMu_dbltk_branch = tree->GetBranch("HLT_DoubleMu_dbltk");
		if (HLT_DoubleMu_dbltk_branch) {HLT_DoubleMu_dbltk_branch->SetAddress(&HLT_DoubleMu_dbltk_);}
	}
	HLT_DoubleMu_nonDZ_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_nonDZ") != 0) {
		HLT_DoubleMu_nonDZ_branch = tree->GetBranch("HLT_DoubleMu_nonDZ");
		if (HLT_DoubleMu_nonDZ_branch) {HLT_DoubleMu_nonDZ_branch->SetAddress(&HLT_DoubleMu_nonDZ_);}
	}
	HLT_DoubleMu_tk_nonDZ_branch = 0;
	if (tree->GetBranch("HLT_DoubleMu_tk_nonDZ") != 0) {
		HLT_DoubleMu_tk_nonDZ_branch = tree->GetBranch("HLT_DoubleMu_tk_nonDZ");
		if (HLT_DoubleMu_tk_nonDZ_branch) {HLT_DoubleMu_tk_nonDZ_branch->SetAddress(&HLT_DoubleMu_tk_nonDZ_);}
	}
	dilmass_branch = 0;
	if (tree->GetBranch("dilmass") != 0) {
		dilmass_branch = tree->GetBranch("dilmass");
		if (dilmass_branch) {dilmass_branch->SetAddress(&dilmass_);}
	}
	dilpt_branch = 0;
	if (tree->GetBranch("dilpt") != 0) {
		dilpt_branch = tree->GetBranch("dilpt");
		if (dilpt_branch) {dilpt_branch->SetAddress(&dilpt_);}
	}
	trilmass_branch = 0;
	if (tree->GetBranch("trilmass") != 0) {
		trilmass_branch = tree->GetBranch("trilmass");
		if (trilmass_branch) {trilmass_branch->SetAddress(&trilmass_);}
	}
	reilpt_branch = 0;
	if (tree->GetBranch("reilpt") != 0) {
		reilpt_branch = tree->GetBranch("reilpt");
		if (reilpt_branch) {reilpt_branch->SetAddress(&reilpt_);}
	}
	dRll_branch = 0;
	if (tree->GetBranch("dRll") != 0) {
		dRll_branch = tree->GetBranch("dRll");
		if (dRll_branch) {dRll_branch->SetAddress(&dRll_);}
	}
	matched_neutralemf_branch = 0;
	if (tree->GetBranch("matched_neutralemf") != 0) {
		matched_neutralemf_branch = tree->GetBranch("matched_neutralemf");
		if (matched_neutralemf_branch) {matched_neutralemf_branch->SetAddress(&matched_neutralemf_);}
	}
	matched_emf_branch = 0;
	if (tree->GetBranch("matched_emf") != 0) {
		matched_emf_branch = tree->GetBranch("matched_emf");
		if (matched_emf_branch) {matched_emf_branch->SetAddress(&matched_emf_);}
	}
	elveto_branch = 0;
	if (tree->GetBranch("elveto") != 0) {
		elveto_branch = tree->GetBranch("elveto");
		if (elveto_branch) {elveto_branch->SetAddress(&elveto_);}
	}
	nlep_branch = 0;
	if (tree->GetBranch("nlep") != 0) {
		nlep_branch = tree->GetBranch("nlep");
		if (nlep_branch) {nlep_branch->SetAddress(&nlep_);}
	}
	nveto_leptons_branch = 0;
	if (tree->GetBranch("nveto_leptons") != 0) {
		nveto_leptons_branch = tree->GetBranch("nveto_leptons");
		if (nveto_leptons_branch) {nveto_leptons_branch->SetAddress(&nveto_leptons_);}
	}
	lep_pt_branch = 0;
	if (tree->GetBranch("lep_pt") != 0) {
		lep_pt_branch = tree->GetBranch("lep_pt");
		if (lep_pt_branch) {lep_pt_branch->SetAddress(&lep_pt_);}
	}
	lep_eta_branch = 0;
	if (tree->GetBranch("lep_eta") != 0) {
		lep_eta_branch = tree->GetBranch("lep_eta");
		if (lep_eta_branch) {lep_eta_branch->SetAddress(&lep_eta_);}
	}
	lep_phi_branch = 0;
	if (tree->GetBranch("lep_phi") != 0) {
		lep_phi_branch = tree->GetBranch("lep_phi");
		if (lep_phi_branch) {lep_phi_branch->SetAddress(&lep_phi_);}
	}
	lep_mass_branch = 0;
	if (tree->GetBranch("lep_mass") != 0) {
		lep_mass_branch = tree->GetBranch("lep_mass");
		if (lep_mass_branch) {lep_mass_branch->SetAddress(&lep_mass_);}
	}
	lep_charge_branch = 0;
	if (tree->GetBranch("lep_charge") != 0) {
		lep_charge_branch = tree->GetBranch("lep_charge");
		if (lep_charge_branch) {lep_charge_branch->SetAddress(&lep_charge_);}
	}
	lep_threecharge_branch = 0;
	if (tree->GetBranch("lep_threecharge") != 0) {
		lep_threecharge_branch = tree->GetBranch("lep_threecharge");
		if (lep_threecharge_branch) {lep_threecharge_branch->SetAddress(&lep_threecharge_);}
	}
	lep_tightcharge_branch = 0;
	if (tree->GetBranch("lep_tightcharge") != 0) {
		lep_tightcharge_branch = tree->GetBranch("lep_tightcharge");
		if (lep_tightcharge_branch) {lep_tightcharge_branch->SetAddress(&lep_tightcharge_);}
	}
	lep_pdgId_branch = 0;
	if (tree->GetBranch("lep_pdgId") != 0) {
		lep_pdgId_branch = tree->GetBranch("lep_pdgId");
		if (lep_pdgId_branch) {lep_pdgId_branch->SetAddress(&lep_pdgId_);}
	}
	lep_dxy_branch = 0;
	if (tree->GetBranch("lep_dxy") != 0) {
		lep_dxy_branch = tree->GetBranch("lep_dxy");
		if (lep_dxy_branch) {lep_dxy_branch->SetAddress(&lep_dxy_);}
	}
	lep_ip3d_branch = 0;
	if (tree->GetBranch("lep_ip3d") != 0) {
		lep_ip3d_branch = tree->GetBranch("lep_ip3d");
		if (lep_ip3d_branch) {lep_ip3d_branch->SetAddress(&lep_ip3d_);}
	}
	lep_ip3derr_branch = 0;
	if (tree->GetBranch("lep_ip3derr") != 0) {
		lep_ip3derr_branch = tree->GetBranch("lep_ip3derr");
		if (lep_ip3derr_branch) {lep_ip3derr_branch->SetAddress(&lep_ip3derr_);}
	}
	lep_etaSC_branch = 0;
	if (tree->GetBranch("lep_etaSC") != 0) {
		lep_etaSC_branch = tree->GetBranch("lep_etaSC");
		if (lep_etaSC_branch) {lep_etaSC_branch->SetAddress(&lep_etaSC_);}
	}
	lep_dz_branch = 0;
	if (tree->GetBranch("lep_dz") != 0) {
		lep_dz_branch = tree->GetBranch("lep_dz");
		if (lep_dz_branch) {lep_dz_branch->SetAddress(&lep_dz_);}
	}
	lep_dzerr_branch = 0;
	if (tree->GetBranch("lep_dzerr") != 0) {
		lep_dzerr_branch = tree->GetBranch("lep_dzerr");
		if (lep_dzerr_branch) {lep_dzerr_branch->SetAddress(&lep_dzerr_);}
	}
	lep_vetoId_branch = 0;
	if (tree->GetBranch("lep_vetoId") != 0) {
		lep_vetoId_branch = tree->GetBranch("lep_vetoId");
		if (lep_vetoId_branch) {lep_vetoId_branch->SetAddress(&lep_vetoId_);}
	}
	lep_looseId_branch = 0;
	if (tree->GetBranch("lep_looseId") != 0) {
		lep_looseId_branch = tree->GetBranch("lep_looseId");
		if (lep_looseId_branch) {lep_looseId_branch->SetAddress(&lep_looseId_);}
	}
	lep_mediumId_branch = 0;
	if (tree->GetBranch("lep_mediumId") != 0) {
		lep_mediumId_branch = tree->GetBranch("lep_mediumId");
		if (lep_mediumId_branch) {lep_mediumId_branch->SetAddress(&lep_mediumId_);}
	}
	lep_tightId_branch = 0;
	if (tree->GetBranch("lep_tightId") != 0) {
		lep_tightId_branch = tree->GetBranch("lep_tightId");
		if (lep_tightId_branch) {lep_tightId_branch->SetAddress(&lep_tightId_);}
	}
	lep_relIso03_branch = 0;
	if (tree->GetBranch("lep_relIso03") != 0) {
		lep_relIso03_branch = tree->GetBranch("lep_relIso03");
		if (lep_relIso03_branch) {lep_relIso03_branch->SetAddress(&lep_relIso03_);}
	}
	lep_relIso03EA_branch = 0;
	if (tree->GetBranch("lep_relIso03EA") != 0) {
		lep_relIso03EA_branch = tree->GetBranch("lep_relIso03EA");
		if (lep_relIso03EA_branch) {lep_relIso03EA_branch->SetAddress(&lep_relIso03EA_);}
	}
	lep_relIso03DB_branch = 0;
	if (tree->GetBranch("lep_relIso03DB") != 0) {
		lep_relIso03DB_branch = tree->GetBranch("lep_relIso03DB");
		if (lep_relIso03DB_branch) {lep_relIso03DB_branch->SetAddress(&lep_relIso03DB_);}
	}
	lep_relIso04_branch = 0;
	if (tree->GetBranch("lep_relIso04") != 0) {
		lep_relIso04_branch = tree->GetBranch("lep_relIso04");
		if (lep_relIso04_branch) {lep_relIso04_branch->SetAddress(&lep_relIso04_);}
	}
	lep_relIso04EA_branch = 0;
	if (tree->GetBranch("lep_relIso04EA") != 0) {
		lep_relIso04EA_branch = tree->GetBranch("lep_relIso04EA");
		if (lep_relIso04EA_branch) {lep_relIso04EA_branch->SetAddress(&lep_relIso04EA_);}
	}
	lep_relIso04DB_branch = 0;
	if (tree->GetBranch("lep_relIso04DB") != 0) {
		lep_relIso04DB_branch = tree->GetBranch("lep_relIso04DB");
		if (lep_relIso04DB_branch) {lep_relIso04DB_branch->SetAddress(&lep_relIso04DB_);}
	}
	lep_ptrel_branch = 0;
	if (tree->GetBranch("lep_ptrel") != 0) {
		lep_ptrel_branch = tree->GetBranch("lep_ptrel");
		if (lep_ptrel_branch) {lep_ptrel_branch->SetAddress(&lep_ptrel_);}
	}
	lep_ptratio_branch = 0;
	if (tree->GetBranch("lep_ptratio") != 0) {
		lep_ptratio_branch = tree->GetBranch("lep_ptratio");
		if (lep_ptratio_branch) {lep_ptratio_branch->SetAddress(&lep_ptratio_);}
	}
	lep_mcMatchId_branch = 0;
	if (tree->GetBranch("lep_mcMatchId") != 0) {
		lep_mcMatchId_branch = tree->GetBranch("lep_mcMatchId");
		if (lep_mcMatchId_branch) {lep_mcMatchId_branch->SetAddress(&lep_mcMatchId_);}
	}
	lep_lostHits_branch = 0;
	if (tree->GetBranch("lep_lostHits") != 0) {
		lep_lostHits_branch = tree->GetBranch("lep_lostHits");
		if (lep_lostHits_branch) {lep_lostHits_branch->SetAddress(&lep_lostHits_);}
	}
	lep_isfromW_branch = 0;
	if (tree->GetBranch("lep_isfromW") != 0) {
		lep_isfromW_branch = tree->GetBranch("lep_isfromW");
		if (lep_isfromW_branch) {lep_isfromW_branch->SetAddress(&lep_isfromW_);}
	}
	lep_isfromZ_branch = 0;
	if (tree->GetBranch("lep_isfromZ") != 0) {
		lep_isfromZ_branch = tree->GetBranch("lep_isfromZ");
		if (lep_isfromZ_branch) {lep_isfromZ_branch->SetAddress(&lep_isfromZ_);}
	}
	lep_isfromH_branch = 0;
	if (tree->GetBranch("lep_isfromH") != 0) {
		lep_isfromH_branch = tree->GetBranch("lep_isfromH");
		if (lep_isfromH_branch) {lep_isfromH_branch->SetAddress(&lep_isfromH_);}
	}
	lep_isfromB_branch = 0;
	if (tree->GetBranch("lep_isfromB") != 0) {
		lep_isfromB_branch = tree->GetBranch("lep_isfromB");
		if (lep_isfromB_branch) {lep_isfromB_branch->SetAddress(&lep_isfromB_);}
	}
	lep_isfromC_branch = 0;
	if (tree->GetBranch("lep_isfromC") != 0) {
		lep_isfromC_branch = tree->GetBranch("lep_isfromC");
		if (lep_isfromC_branch) {lep_isfromC_branch->SetAddress(&lep_isfromC_);}
	}
	lep_isfromL_branch = 0;
	if (tree->GetBranch("lep_isfromL") != 0) {
		lep_isfromL_branch = tree->GetBranch("lep_isfromL");
		if (lep_isfromL_branch) {lep_isfromL_branch->SetAddress(&lep_isfromL_);}
	}
	lep_convVeto_branch = 0;
	if (tree->GetBranch("lep_convVeto") != 0) {
		lep_convVeto_branch = tree->GetBranch("lep_convVeto");
		if (lep_convVeto_branch) {lep_convVeto_branch->SetAddress(&lep_convVeto_);}
	}
	lep_MVA_branch = 0;
	if (tree->GetBranch("lep_MVA") != 0) {
		lep_MVA_branch = tree->GetBranch("lep_MVA");
		if (lep_MVA_branch) {lep_MVA_branch->SetAddress(&lep_MVA_);}
	}
	lep_validfraction_branch = 0;
	if (tree->GetBranch("lep_validfraction") != 0) {
		lep_validfraction_branch = tree->GetBranch("lep_validfraction");
		if (lep_validfraction_branch) {lep_validfraction_branch->SetAddress(&lep_validfraction_);}
	}
	lep_pterr_branch = 0;
	if (tree->GetBranch("lep_pterr") != 0) {
		lep_pterr_branch = tree->GetBranch("lep_pterr");
		if (lep_pterr_branch) {lep_pterr_branch->SetAddress(&lep_pterr_);}
	}
	lep_sta_pterrOpt_branch = 0;
	if (tree->GetBranch("lep_sta_pterrOpt") != 0) {
		lep_sta_pterrOpt_branch = tree->GetBranch("lep_sta_pterrOpt");
		if (lep_sta_pterrOpt_branch) {lep_sta_pterrOpt_branch->SetAddress(&lep_sta_pterrOpt_);}
	}
	lep_glb_pterrOpt_branch = 0;
	if (tree->GetBranch("lep_glb_pterrOpt") != 0) {
		lep_glb_pterrOpt_branch = tree->GetBranch("lep_glb_pterrOpt");
		if (lep_glb_pterrOpt_branch) {lep_glb_pterrOpt_branch->SetAddress(&lep_glb_pterrOpt_);}
	}
	lep_x2ondof_branch = 0;
	if (tree->GetBranch("lep_x2ondof") != 0) {
		lep_x2ondof_branch = tree->GetBranch("lep_x2ondof");
		if (lep_x2ondof_branch) {lep_x2ondof_branch->SetAddress(&lep_x2ondof_);}
	}
	lep_sta_x2ondof_branch = 0;
	if (tree->GetBranch("lep_sta_x2ondof") != 0) {
		lep_sta_x2ondof_branch = tree->GetBranch("lep_sta_x2ondof");
		if (lep_sta_x2ondof_branch) {lep_sta_x2ondof_branch->SetAddress(&lep_sta_x2ondof_);}
	}
	lep_glb_x2ondof_branch = 0;
	if (tree->GetBranch("lep_glb_x2ondof") != 0) {
		lep_glb_x2ondof_branch = tree->GetBranch("lep_glb_x2ondof");
		if (lep_glb_x2ondof_branch) {lep_glb_x2ondof_branch->SetAddress(&lep_glb_x2ondof_);}
	}
	nisoTracks_branch = 0;
	if (tree->GetBranch("nisoTracks") != 0) {
		nisoTracks_branch = tree->GetBranch("nisoTracks");
		if (nisoTracks_branch) {nisoTracks_branch->SetAddress(&nisoTracks_);}
	}
	isotr_relIso03_branch = 0;
	if (tree->GetBranch("isotr_relIso03") != 0) {
		isotr_relIso03_branch = tree->GetBranch("isotr_relIso03");
		if (isotr_relIso03_branch) {isotr_relIso03_branch->SetAddress(&isotr_relIso03_);}
	}
	isotr_relIso04_branch = 0;
	if (tree->GetBranch("isotr_relIso04") != 0) {
		isotr_relIso04_branch = tree->GetBranch("isotr_relIso04");
		if (isotr_relIso04_branch) {isotr_relIso04_branch->SetAddress(&isotr_relIso04_);}
	}
	isotr_ptrel_branch = 0;
	if (tree->GetBranch("isotr_ptrel") != 0) {
		isotr_ptrel_branch = tree->GetBranch("isotr_ptrel");
		if (isotr_ptrel_branch) {isotr_ptrel_branch->SetAddress(&isotr_ptrel_);}
	}
	isotr_ptratio_branch = 0;
	if (tree->GetBranch("isotr_ptratio") != 0) {
		isotr_ptratio_branch = tree->GetBranch("isotr_ptratio");
		if (isotr_ptratio_branch) {isotr_ptratio_branch->SetAddress(&isotr_ptratio_);}
	}
	isotr_charge_branch = 0;
	if (tree->GetBranch("isotr_charge") != 0) {
		isotr_charge_branch = tree->GetBranch("isotr_charge");
		if (isotr_charge_branch) {isotr_charge_branch->SetAddress(&isotr_charge_);}
	}
	isotr_pdgId_branch = 0;
	if (tree->GetBranch("isotr_pdgId") != 0) {
		isotr_pdgId_branch = tree->GetBranch("isotr_pdgId");
		if (isotr_pdgId_branch) {isotr_pdgId_branch->SetAddress(&isotr_pdgId_);}
	}
	isotr_dz_branch = 0;
	if (tree->GetBranch("isotr_dz") != 0) {
		isotr_dz_branch = tree->GetBranch("isotr_dz");
		if (isotr_dz_branch) {isotr_dz_branch->SetAddress(&isotr_dz_);}
	}
	nisoTrack_5gev_branch = 0;
	if (tree->GetBranch("nisoTrack_5gev") != 0) {
		nisoTrack_5gev_branch = tree->GetBranch("nisoTrack_5gev");
		if (nisoTrack_5gev_branch) {nisoTrack_5gev_branch->SetAddress(&nisoTrack_5gev_);}
	}
	nisoTrack_mt2_branch = 0;
	if (tree->GetBranch("nisoTrack_mt2") != 0) {
		nisoTrack_mt2_branch = tree->GetBranch("nisoTrack_mt2");
		if (nisoTrack_mt2_branch) {nisoTrack_mt2_branch->SetAddress(&nisoTrack_mt2_);}
	}
	nisoTrack_PFLep5_woverlaps_branch = 0;
	if (tree->GetBranch("nisoTrack_PFLep5_woverlaps") != 0) {
		nisoTrack_PFLep5_woverlaps_branch = tree->GetBranch("nisoTrack_PFLep5_woverlaps");
		if (nisoTrack_PFLep5_woverlaps_branch) {nisoTrack_PFLep5_woverlaps_branch->SetAddress(&nisoTrack_PFLep5_woverlaps_);}
	}
	nisoTrack_PFHad10_woverlaps_branch = 0;
	if (tree->GetBranch("nisoTrack_PFHad10_woverlaps") != 0) {
		nisoTrack_PFHad10_woverlaps_branch = tree->GetBranch("nisoTrack_PFHad10_woverlaps");
		if (nisoTrack_PFHad10_woverlaps_branch) {nisoTrack_PFHad10_woverlaps_branch->SetAddress(&nisoTrack_PFHad10_woverlaps_);}
	}
	ngamma_branch = 0;
	if (tree->GetBranch("ngamma") != 0) {
		ngamma_branch = tree->GetBranch("ngamma");
		if (ngamma_branch) {ngamma_branch->SetAddress(&ngamma_);}
	}
	gamma_mcMatchId_branch = 0;
	if (tree->GetBranch("gamma_mcMatchId") != 0) {
		gamma_mcMatchId_branch = tree->GetBranch("gamma_mcMatchId");
		if (gamma_mcMatchId_branch) {gamma_mcMatchId_branch->SetAddress(&gamma_mcMatchId_);}
	}
	gamma_genPt_branch = 0;
	if (tree->GetBranch("gamma_genPt") != 0) {
		gamma_genPt_branch = tree->GetBranch("gamma_genPt");
		if (gamma_genPt_branch) {gamma_genPt_branch->SetAddress(&gamma_genPt_);}
	}
	gamma_genIso_branch = 0;
	if (tree->GetBranch("gamma_genIso") != 0) {
		gamma_genIso_branch = tree->GetBranch("gamma_genIso");
		if (gamma_genIso_branch) {gamma_genIso_branch->SetAddress(&gamma_genIso_);}
	}
	gamma_chHadIso_branch = 0;
	if (tree->GetBranch("gamma_chHadIso") != 0) {
		gamma_chHadIso_branch = tree->GetBranch("gamma_chHadIso");
		if (gamma_chHadIso_branch) {gamma_chHadIso_branch->SetAddress(&gamma_chHadIso_);}
	}
	gamma_neuHadIso_branch = 0;
	if (tree->GetBranch("gamma_neuHadIso") != 0) {
		gamma_neuHadIso_branch = tree->GetBranch("gamma_neuHadIso");
		if (gamma_neuHadIso_branch) {gamma_neuHadIso_branch->SetAddress(&gamma_neuHadIso_);}
	}
	gamma_phIso_branch = 0;
	if (tree->GetBranch("gamma_phIso") != 0) {
		gamma_phIso_branch = tree->GetBranch("gamma_phIso");
		if (gamma_phIso_branch) {gamma_phIso_branch->SetAddress(&gamma_phIso_);}
	}
	gamma_idCutBased_branch = 0;
	if (tree->GetBranch("gamma_idCutBased") != 0) {
		gamma_idCutBased_branch = tree->GetBranch("gamma_idCutBased");
		if (gamma_idCutBased_branch) {gamma_idCutBased_branch->SetAddress(&gamma_idCutBased_);}
	}
	gamma_drMinParton_branch = 0;
	if (tree->GetBranch("gamma_drMinParton") != 0) {
		gamma_drMinParton_branch = tree->GetBranch("gamma_drMinParton");
		if (gamma_drMinParton_branch) {gamma_drMinParton_branch->SetAddress(&gamma_drMinParton_);}
	}
	ngenPart_branch = 0;
	if (tree->GetBranch("ngenPart") != 0) {
		ngenPart_branch = tree->GetBranch("ngenPart");
		if (ngenPart_branch) {ngenPart_branch->SetAddress(&ngenPart_);}
	}
	genPart_pt_branch = 0;
	if (tree->GetBranch("genPart_pt") != 0) {
		genPart_pt_branch = tree->GetBranch("genPart_pt");
		if (genPart_pt_branch) {genPart_pt_branch->SetAddress(&genPart_pt_);}
	}
	genPart_eta_branch = 0;
	if (tree->GetBranch("genPart_eta") != 0) {
		genPart_eta_branch = tree->GetBranch("genPart_eta");
		if (genPart_eta_branch) {genPart_eta_branch->SetAddress(&genPart_eta_);}
	}
	genPart_phi_branch = 0;
	if (tree->GetBranch("genPart_phi") != 0) {
		genPart_phi_branch = tree->GetBranch("genPart_phi");
		if (genPart_phi_branch) {genPart_phi_branch->SetAddress(&genPart_phi_);}
	}
	genPart_mass_branch = 0;
	if (tree->GetBranch("genPart_mass") != 0) {
		genPart_mass_branch = tree->GetBranch("genPart_mass");
		if (genPart_mass_branch) {genPart_mass_branch->SetAddress(&genPart_mass_);}
	}
	genPart_pdgId_branch = 0;
	if (tree->GetBranch("genPart_pdgId") != 0) {
		genPart_pdgId_branch = tree->GetBranch("genPart_pdgId");
		if (genPart_pdgId_branch) {genPart_pdgId_branch->SetAddress(&genPart_pdgId_);}
	}
	genPart_status_branch = 0;
	if (tree->GetBranch("genPart_status") != 0) {
		genPart_status_branch = tree->GetBranch("genPart_status");
		if (genPart_status_branch) {genPart_status_branch->SetAddress(&genPart_status_);}
	}
	genPart_charge_branch = 0;
	if (tree->GetBranch("genPart_charge") != 0) {
		genPart_charge_branch = tree->GetBranch("genPart_charge");
		if (genPart_charge_branch) {genPart_charge_branch->SetAddress(&genPart_charge_);}
	}
	genPart_motherId_branch = 0;
	if (tree->GetBranch("genPart_motherId") != 0) {
		genPart_motherId_branch = tree->GetBranch("genPart_motherId");
		if (genPart_motherId_branch) {genPart_motherId_branch->SetAddress(&genPart_motherId_);}
	}
	genPart_grandmaId_branch = 0;
	if (tree->GetBranch("genPart_grandmaId") != 0) {
		genPart_grandmaId_branch = tree->GetBranch("genPart_grandmaId");
		if (genPart_grandmaId_branch) {genPart_grandmaId_branch->SetAddress(&genPart_grandmaId_);}
	}
	genPart_isp6status3_branch = 0;
	if (tree->GetBranch("genPart_isp6status3") != 0) {
		genPart_isp6status3_branch = tree->GetBranch("genPart_isp6status3");
		if (genPart_isp6status3_branch) {genPart_isp6status3_branch->SetAddress(&genPart_isp6status3_);}
	}
	njets_branch = 0;
	if (tree->GetBranch("njets") != 0) {
		njets_branch = tree->GetBranch("njets");
		if (njets_branch) {njets_branch->SetAddress(&njets_);}
	}
	removed_jets_csv_branch = 0;
	if (tree->GetBranch("removed_jets_csv") != 0) {
		removed_jets_csv_branch = tree->GetBranch("removed_jets_csv");
		if (removed_jets_csv_branch) {removed_jets_csv_branch->SetAddress(&removed_jets_csv_);}
	}
	removed_jets_deepB_branch = 0;
	if (tree->GetBranch("removed_jets_deepB") != 0) {
		removed_jets_deepB_branch = tree->GetBranch("removed_jets_deepB");
		if (removed_jets_deepB_branch) {removed_jets_deepB_branch->SetAddress(&removed_jets_deepB_);}
	}
	removed_jets_deepC_branch = 0;
	if (tree->GetBranch("removed_jets_deepC") != 0) {
		removed_jets_deepC_branch = tree->GetBranch("removed_jets_deepC");
		if (removed_jets_deepC_branch) {removed_jets_deepC_branch->SetAddress(&removed_jets_deepC_);}
	}
	njets_up_branch = 0;
	if (tree->GetBranch("njets_up") != 0) {
		njets_up_branch = tree->GetBranch("njets_up");
		if (njets_up_branch) {njets_up_branch->SetAddress(&njets_up_);}
	}
	jets_csv_branch = 0;
	if (tree->GetBranch("jets_csv") != 0) {
		jets_csv_branch = tree->GetBranch("jets_csv");
		if (jets_csv_branch) {jets_csv_branch->SetAddress(&jets_csv_);}
	}
	jets_up_csv_branch = 0;
	if (tree->GetBranch("jets_up_csv") != 0) {
		jets_up_csv_branch = tree->GetBranch("jets_up_csv");
		if (jets_up_csv_branch) {jets_up_csv_branch->SetAddress(&jets_up_csv_);}
	}
	jets_deepB_branch = 0;
	if (tree->GetBranch("jets_deepB") != 0) {
		jets_deepB_branch = tree->GetBranch("jets_deepB");
		if (jets_deepB_branch) {jets_deepB_branch->SetAddress(&jets_deepB_);}
	}
	jets_up_deepB_branch = 0;
	if (tree->GetBranch("jets_up_deepB") != 0) {
		jets_up_deepB_branch = tree->GetBranch("jets_up_deepB");
		if (jets_up_deepB_branch) {jets_up_deepB_branch->SetAddress(&jets_up_deepB_);}
	}
	jets_deepC_branch = 0;
	if (tree->GetBranch("jets_deepC") != 0) {
		jets_deepC_branch = tree->GetBranch("jets_deepC");
		if (jets_deepC_branch) {jets_deepC_branch->SetAddress(&jets_deepC_);}
	}
	jets_up_deepC_branch = 0;
	if (tree->GetBranch("jets_up_deepC") != 0) {
		jets_up_deepC_branch = tree->GetBranch("jets_up_deepC");
		if (jets_up_deepC_branch) {jets_up_deepC_branch->SetAddress(&jets_up_deepC_);}
	}
	njets_dn_branch = 0;
	if (tree->GetBranch("njets_dn") != 0) {
		njets_dn_branch = tree->GetBranch("njets_dn");
		if (njets_dn_branch) {njets_dn_branch->SetAddress(&njets_dn_);}
	}
	jets_dn_csv_branch = 0;
	if (tree->GetBranch("jets_dn_csv") != 0) {
		jets_dn_csv_branch = tree->GetBranch("jets_dn_csv");
		if (jets_dn_csv_branch) {jets_dn_csv_branch->SetAddress(&jets_dn_csv_);}
	}
	jets_dn_deepB_branch = 0;
	if (tree->GetBranch("jets_dn_deepB") != 0) {
		jets_dn_deepB_branch = tree->GetBranch("jets_dn_deepB");
		if (jets_dn_deepB_branch) {jets_dn_deepB_branch->SetAddress(&jets_dn_deepB_);}
	}
	jets_dn_deepC_branch = 0;
	if (tree->GetBranch("jets_dn_deepC") != 0) {
		jets_dn_deepC_branch = tree->GetBranch("jets_dn_deepC");
		if (jets_dn_deepC_branch) {jets_dn_deepC_branch->SetAddress(&jets_dn_deepC_);}
	}
	jets_muf_branch = 0;
	if (tree->GetBranch("jets_muf") != 0) {
		jets_muf_branch = tree->GetBranch("jets_muf");
		if (jets_muf_branch) {jets_muf_branch->SetAddress(&jets_muf_);}
	}
	jets_mcFlavour_branch = 0;
	if (tree->GetBranch("jets_mcFlavour") != 0) {
		jets_mcFlavour_branch = tree->GetBranch("jets_mcFlavour");
		if (jets_mcFlavour_branch) {jets_mcFlavour_branch->SetAddress(&jets_mcFlavour_);}
	}
	jets_mcHadronFlav_branch = 0;
	if (tree->GetBranch("jets_mcHadronFlav") != 0) {
		jets_mcHadronFlav_branch = tree->GetBranch("jets_mcHadronFlav");
		if (jets_mcHadronFlav_branch) {jets_mcHadronFlav_branch->SetAddress(&jets_mcHadronFlav_);}
	}
	ht_branch = 0;
	if (tree->GetBranch("ht") != 0) {
		ht_branch = tree->GetBranch("ht");
		if (ht_branch) {ht_branch->SetAddress(&ht_);}
	}
	ht_up_branch = 0;
	if (tree->GetBranch("ht_up") != 0) {
		ht_up_branch = tree->GetBranch("ht_up");
		if (ht_up_branch) {ht_up_branch->SetAddress(&ht_up_);}
	}
	ht_dn_branch = 0;
	if (tree->GetBranch("ht_dn") != 0) {
		ht_dn_branch = tree->GetBranch("ht_dn");
		if (ht_dn_branch) {ht_dn_branch->SetAddress(&ht_dn_);}
	}
	mt_lep1_branch = 0;
	if (tree->GetBranch("mt_lep1") != 0) {
		mt_lep1_branch = tree->GetBranch("mt_lep1");
		if (mt_lep1_branch) {mt_lep1_branch->SetAddress(&mt_lep1_);}
	}
	mt_min_branch = 0;
	if (tree->GetBranch("mt_min") != 0) {
		mt_min_branch = tree->GetBranch("mt_min");
		if (mt_min_branch) {mt_min_branch->SetAddress(&mt_min_);}
	}
	mt_max_branch = 0;
	if (tree->GetBranch("mt_max") != 0) {
		mt_max_branch = tree->GetBranch("mt_max");
		if (mt_max_branch) {mt_max_branch->SetAddress(&mt_max_);}
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
	met_T1CHS_pt_branch = 0;
	if (tree->GetBranch("met_T1CHS_pt") != 0) {
		met_T1CHS_pt_branch = tree->GetBranch("met_T1CHS_pt");
		if (met_T1CHS_pt_branch) {met_T1CHS_pt_branch->SetAddress(&met_T1CHS_pt_);}
	}
	met_T1CHS_phi_branch = 0;
	if (tree->GetBranch("met_T1CHS_phi") != 0) {
		met_T1CHS_phi_branch = tree->GetBranch("met_T1CHS_phi");
		if (met_T1CHS_phi_branch) {met_T1CHS_phi_branch->SetAddress(&met_T1CHS_phi_);}
	}
	met_T1CHS_fromCORE_pt_branch = 0;
	if (tree->GetBranch("met_T1CHS_fromCORE_pt") != 0) {
		met_T1CHS_fromCORE_pt_branch = tree->GetBranch("met_T1CHS_fromCORE_pt");
		if (met_T1CHS_fromCORE_pt_branch) {met_T1CHS_fromCORE_pt_branch->SetAddress(&met_T1CHS_fromCORE_pt_);}
	}
	met_T1CHS_fromCORE_phi_branch = 0;
	if (tree->GetBranch("met_T1CHS_fromCORE_phi") != 0) {
		met_T1CHS_fromCORE_phi_branch = tree->GetBranch("met_T1CHS_fromCORE_phi");
		if (met_T1CHS_fromCORE_phi_branch) {met_T1CHS_fromCORE_phi_branch->SetAddress(&met_T1CHS_fromCORE_phi_);}
	}
	met_T1CHS_miniAOD_CORE_pt_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_pt") != 0) {
		met_T1CHS_miniAOD_CORE_pt_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_pt");
		if (met_T1CHS_miniAOD_CORE_pt_branch) {met_T1CHS_miniAOD_CORE_pt_branch->SetAddress(&met_T1CHS_miniAOD_CORE_pt_);}
	}
	met_T1CHS_miniAOD_CORE_phi_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_phi") != 0) {
		met_T1CHS_miniAOD_CORE_phi_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_phi");
		if (met_T1CHS_miniAOD_CORE_phi_branch) {met_T1CHS_miniAOD_CORE_phi_branch->SetAddress(&met_T1CHS_miniAOD_CORE_phi_);}
	}
	met_T1CHS_miniAOD_CORE_up_pt_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_up_pt") != 0) {
		met_T1CHS_miniAOD_CORE_up_pt_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_up_pt");
		if (met_T1CHS_miniAOD_CORE_up_pt_branch) {met_T1CHS_miniAOD_CORE_up_pt_branch->SetAddress(&met_T1CHS_miniAOD_CORE_up_pt_);}
	}
	met_T1CHS_miniAOD_CORE_up_phi_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_up_phi") != 0) {
		met_T1CHS_miniAOD_CORE_up_phi_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_up_phi");
		if (met_T1CHS_miniAOD_CORE_up_phi_branch) {met_T1CHS_miniAOD_CORE_up_phi_branch->SetAddress(&met_T1CHS_miniAOD_CORE_up_phi_);}
	}
	met_T1CHS_miniAOD_CORE_dn_pt_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_dn_pt") != 0) {
		met_T1CHS_miniAOD_CORE_dn_pt_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_dn_pt");
		if (met_T1CHS_miniAOD_CORE_dn_pt_branch) {met_T1CHS_miniAOD_CORE_dn_pt_branch->SetAddress(&met_T1CHS_miniAOD_CORE_dn_pt_);}
	}
	met_T1CHS_miniAOD_CORE_dn_phi_branch = 0;
	if (tree->GetBranch("met_T1CHS_miniAOD_CORE_dn_phi") != 0) {
		met_T1CHS_miniAOD_CORE_dn_phi_branch = tree->GetBranch("met_T1CHS_miniAOD_CORE_dn_phi");
		if (met_T1CHS_miniAOD_CORE_dn_phi_branch) {met_T1CHS_miniAOD_CORE_dn_phi_branch->SetAddress(&met_T1CHS_miniAOD_CORE_dn_phi_);}
	}
	hyp_type_branch = 0;
	if (tree->GetBranch("hyp_type") != 0) {
		hyp_type_branch = tree->GetBranch("hyp_type");
		if (hyp_type_branch) {hyp_type_branch->SetAddress(&hyp_type_);}
	}
	evt_type_branch = 0;
	if (tree->GetBranch("evt_type") != 0) {
		evt_type_branch = tree->GetBranch("evt_type");
		if (evt_type_branch) {evt_type_branch->SetAddress(&evt_type_);}
	}
	isrboost_branch = 0;
	if (tree->GetBranch("isrboost") != 0) {
		isrboost_branch = tree->GetBranch("isrboost");
		if (isrboost_branch) {isrboost_branch->SetAddress(&isrboost_);}
	}
	isr_njets_branch = 0;
	if (tree->GetBranch("isr_njets") != 0) {
		isr_njets_branch = tree->GetBranch("isr_njets");
		if (isr_njets_branch) {isr_njets_branch->SetAddress(&isr_njets_);}
	}
	isr_weight_branch = 0;
	if (tree->GetBranch("isr_weight") != 0) {
		isr_weight_branch = tree->GetBranch("isr_weight");
		if (isr_weight_branch) {isr_weight_branch->SetAddress(&isr_weight_);}
	}
	isr_unc_branch = 0;
	if (tree->GetBranch("isr_unc") != 0) {
		isr_unc_branch = tree->GetBranch("isr_unc");
		if (isr_unc_branch) {isr_unc_branch->SetAddress(&isr_unc_);}
	}
	weightsf_lepid_branch = 0;
	if (tree->GetBranch("weightsf_lepid") != 0) {
		weightsf_lepid_branch = tree->GetBranch("weightsf_lepid");
		if (weightsf_lepid_branch) {weightsf_lepid_branch->SetAddress(&weightsf_lepid_);}
	}
	weightsf_lepiso_branch = 0;
	if (tree->GetBranch("weightsf_lepiso") != 0) {
		weightsf_lepiso_branch = tree->GetBranch("weightsf_lepiso");
		if (weightsf_lepiso_branch) {weightsf_lepiso_branch->SetAddress(&weightsf_lepiso_);}
	}
	weightsf_lepip_branch = 0;
	if (tree->GetBranch("weightsf_lepip") != 0) {
		weightsf_lepip_branch = tree->GetBranch("weightsf_lepip");
		if (weightsf_lepip_branch) {weightsf_lepip_branch->SetAddress(&weightsf_lepip_);}
	}
	weightsf_lepreco_branch = 0;
	if (tree->GetBranch("weightsf_lepreco") != 0) {
		weightsf_lepreco_branch = tree->GetBranch("weightsf_lepreco");
		if (weightsf_lepreco_branch) {weightsf_lepreco_branch->SetAddress(&weightsf_lepreco_);}
	}
	weightsf_lepconv_branch = 0;
	if (tree->GetBranch("weightsf_lepconv") != 0) {
		weightsf_lepconv_branch = tree->GetBranch("weightsf_lepconv");
		if (weightsf_lepconv_branch) {weightsf_lepconv_branch->SetAddress(&weightsf_lepconv_);}
	}
	weightsf_lepid_FS_branch = 0;
	if (tree->GetBranch("weightsf_lepid_FS") != 0) {
		weightsf_lepid_FS_branch = tree->GetBranch("weightsf_lepid_FS");
		if (weightsf_lepid_FS_branch) {weightsf_lepid_FS_branch->SetAddress(&weightsf_lepid_FS_);}
	}
	weightsf_lepiso_FS_branch = 0;
	if (tree->GetBranch("weightsf_lepiso_FS") != 0) {
		weightsf_lepiso_FS_branch = tree->GetBranch("weightsf_lepiso_FS");
		if (weightsf_lepiso_FS_branch) {weightsf_lepiso_FS_branch->SetAddress(&weightsf_lepiso_FS_);}
	}
	weightsf_lepip_FS_branch = 0;
	if (tree->GetBranch("weightsf_lepip_FS") != 0) {
		weightsf_lepip_FS_branch = tree->GetBranch("weightsf_lepip_FS");
		if (weightsf_lepip_FS_branch) {weightsf_lepip_FS_branch->SetAddress(&weightsf_lepip_FS_);}
	}
  tree->SetMakeClass(0);
}
void triboson_v1::GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		run_isLoaded = false;
		lumi_isLoaded = false;
		evt_isLoaded = false;
		isData_isLoaded = false;
		evt_passgoodrunlist_isLoaded = false;
		evt_scale1fb_isLoaded = false;
		evt_xsec_isLoaded = false;
		evt_kfactor_isLoaded = false;
		evt_filter_isLoaded = false;
		evt_nEvts_isLoaded = false;
		evt_dataset_isLoaded = false;
		puWeight_isLoaded = false;
		nVert_isLoaded = false;
		nTrueInt_isLoaded = false;
		rho_isLoaded = false;
		gen_ht_isLoaded = false;
		nBJetTight_isLoaded = false;
		nBJetMedium_isLoaded = false;
		nBJetLoose_isLoaded = false;
		nBJetTight_up_isLoaded = false;
		nBJetMedium_up_isLoaded = false;
		nBJetLoose_up_isLoaded = false;
		nBJetTight_dn_isLoaded = false;
		nBJetMedium_dn_isLoaded = false;
		nBJetLoose_dn_isLoaded = false;
		nJet200MuFrac50DphiMet_isLoaded = false;
		nMuons10_isLoaded = false;
		nBadMuons20_isLoaded = false;
		nElectrons10_isLoaded = false;
		nGammas20_isLoaded = false;
		nTaus20_isLoaded = false;
		met_pt_isLoaded = false;
		met_phi_isLoaded = false;
		met_calo_pt_isLoaded = false;
		met_calo_phi_isLoaded = false;
		met_miniaod_pt_isLoaded = false;
		met_miniaod_phi_isLoaded = false;
		met_muegclean_pt_isLoaded = false;
		met_muegclean_phi_isLoaded = false;
		met_rawPt_isLoaded = false;
		met_rawPhi_isLoaded = false;
		met_genPt_isLoaded = false;
		met_genPhi_isLoaded = false;
		sumet_raw_isLoaded = false;
		Flag_ecalLaserCorrFilter_isLoaded = false;
		Flag_hcalLaserEventFilter_isLoaded = false;
		Flag_trackingFailureFilter_isLoaded = false;
		Flag_CSCTightHaloFilter_isLoaded = false;
		Flag_HBHENoiseFilter_isLoaded = false;
		Flag_HBHEIsoNoiseFilter_isLoaded = false;
		Flag_CSCTightHalo2015Filter_isLoaded = false;
		Flag_EcalDeadCellTriggerPrimitiveFilter_isLoaded = false;
		Flag_goodVertices_isLoaded = false;
		Flag_eeBadScFilter_isLoaded = false;
		Flag_globalTightHalo2016_isLoaded = false;
		Flag_badMuonFilter_isLoaded = false;
		Flag_badChargedCandidateFilter_isLoaded = false;
		Flag_badMuonFilterv2_isLoaded = false;
		Flag_badChargedCandidateFilterv2_isLoaded = false;
		Flag_badMuons_isLoaded = false;
		Flag_duplicateMuons_isLoaded = false;
		Flag_noBadMuons_isLoaded = false;
		HLT_singleEl_isLoaded = false;
		HLT_singleMu_isLoaded = false;
		HLT_singleMu_noiso_isLoaded = false;
		HLT_DoubleEl_noiso_isLoaded = false;
		HLT_DoubleEl_isLoaded = false;
		HLT_DoubleEl_DZ_isLoaded = false;
		HLT_DoubleEl_DZ_2_isLoaded = false;
		HLT_MuEG_isLoaded = false;
		HLT_MuEG_2_isLoaded = false;
		HLT_MuEG_noiso_isLoaded = false;
		HLT_MuEG_noiso_2_isLoaded = false;
		HLT_Mu8_EG17_isLoaded = false;
		HLT_Mu8_EG23_isLoaded = false;
		HLT_Mu8_EG23_DZ_isLoaded = false;
		HLT_Mu12_EG23_DZ_isLoaded = false;
		HLT_Mu17_EG12_isLoaded = false;
		HLT_Mu23_EG8_isLoaded = false;
		HLT_Mu23_EG8_DZ_isLoaded = false;
		HLT_Mu23_EG12_isLoaded = false;
		HLT_Mu23_EG12_DZ_isLoaded = false;
		HLT_DoubleMu_noiso_isLoaded = false;
		HLT_DoubleMu_noiso_27_8_isLoaded = false;
		HLT_DoubleMu_noiso_30_11_isLoaded = false;
		HLT_DoubleMu_noiso_40_11_isLoaded = false;
		HLT_DoubleMu_isLoaded = false;
		HLT_DoubleMu_tk_isLoaded = false;
		HLT_DoubleMu_dbltk_isLoaded = false;
		HLT_DoubleMu_nonDZ_isLoaded = false;
		HLT_DoubleMu_tk_nonDZ_isLoaded = false;
		dilmass_isLoaded = false;
		dilpt_isLoaded = false;
		trilmass_isLoaded = false;
		reilpt_isLoaded = false;
		dRll_isLoaded = false;
		matched_neutralemf_isLoaded = false;
		matched_emf_isLoaded = false;
		elveto_isLoaded = false;
		nlep_isLoaded = false;
		nveto_leptons_isLoaded = false;
		lep_p4_isLoaded = false;
		lep_pt_isLoaded = false;
		lep_eta_isLoaded = false;
		lep_phi_isLoaded = false;
		lep_mass_isLoaded = false;
		lep_charge_isLoaded = false;
		lep_threecharge_isLoaded = false;
		lep_tightcharge_isLoaded = false;
		lep_pdgId_isLoaded = false;
		lep_dxy_isLoaded = false;
		lep_ip3d_isLoaded = false;
		lep_ip3derr_isLoaded = false;
		lep_etaSC_isLoaded = false;
		lep_dz_isLoaded = false;
		lep_dzerr_isLoaded = false;
		lep_vetoId_isLoaded = false;
		lep_looseId_isLoaded = false;
		lep_mediumId_isLoaded = false;
		lep_tightId_isLoaded = false;
		lep_relIso03_isLoaded = false;
		lep_relIso03EA_isLoaded = false;
		lep_relIso03DB_isLoaded = false;
		lep_relIso04_isLoaded = false;
		lep_relIso04EA_isLoaded = false;
		lep_relIso04DB_isLoaded = false;
		lep_ptrel_isLoaded = false;
		lep_ptratio_isLoaded = false;
		lep_mcMatchId_isLoaded = false;
		lep_lostHits_isLoaded = false;
		lep_isfromW_isLoaded = false;
		lep_isfromZ_isLoaded = false;
		lep_isfromH_isLoaded = false;
		lep_isfromB_isLoaded = false;
		lep_isfromC_isLoaded = false;
		lep_isfromL_isLoaded = false;
		lep_convVeto_isLoaded = false;
		lep_MVA_isLoaded = false;
		lep_validfraction_isLoaded = false;
		lep_pterr_isLoaded = false;
		lep_sta_pterrOpt_isLoaded = false;
		lep_glb_pterrOpt_isLoaded = false;
		lep_x2ondof_isLoaded = false;
		lep_sta_x2ondof_isLoaded = false;
		lep_glb_x2ondof_isLoaded = false;
		nisoTracks_isLoaded = false;
		isotr_p4_isLoaded = false;
		isotr_relIso03_isLoaded = false;
		isotr_relIso04_isLoaded = false;
		isotr_ptrel_isLoaded = false;
		isotr_ptratio_isLoaded = false;
		isotr_charge_isLoaded = false;
		isotr_pdgId_isLoaded = false;
		isotr_dz_isLoaded = false;
		nisoTrack_5gev_isLoaded = false;
		nisoTrack_mt2_isLoaded = false;
		nisoTrack_PFLep5_woverlaps_isLoaded = false;
		nisoTrack_PFHad10_woverlaps_isLoaded = false;
		ngamma_isLoaded = false;
		gamma_p4_isLoaded = false;
		gamma_mcMatchId_isLoaded = false;
		gamma_genPt_isLoaded = false;
		gamma_genIso_isLoaded = false;
		gamma_chHadIso_isLoaded = false;
		gamma_neuHadIso_isLoaded = false;
		gamma_phIso_isLoaded = false;
		gamma_idCutBased_isLoaded = false;
		gamma_drMinParton_isLoaded = false;
		ngenPart_isLoaded = false;
		genPart_p4_isLoaded = false;
		genPart_pt_isLoaded = false;
		genPart_eta_isLoaded = false;
		genPart_phi_isLoaded = false;
		genPart_mass_isLoaded = false;
		genPart_pdgId_isLoaded = false;
		genPart_status_isLoaded = false;
		genPart_charge_isLoaded = false;
		genPart_motherId_isLoaded = false;
		genPart_grandmaId_isLoaded = false;
		genPart_isp6status3_isLoaded = false;
		njets_isLoaded = false;
		jets_p4_isLoaded = false;
		removed_jets_p4_isLoaded = false;
		removed_jets_csv_isLoaded = false;
		removed_jets_deepB_isLoaded = false;
		removed_jets_deepC_isLoaded = false;
		jets_medb_p4_isLoaded = false;
		njets_up_isLoaded = false;
		jets_up_p4_isLoaded = false;
		jets_medb_up_p4_isLoaded = false;
		jets_csv_isLoaded = false;
		jets_up_csv_isLoaded = false;
		jets_deepB_isLoaded = false;
		jets_up_deepB_isLoaded = false;
		jets_deepC_isLoaded = false;
		jets_up_deepC_isLoaded = false;
		njets_dn_isLoaded = false;
		jets_dn_p4_isLoaded = false;
		jets_medb_dn_p4_isLoaded = false;
		jets_dn_csv_isLoaded = false;
		jets_dn_deepB_isLoaded = false;
		jets_dn_deepC_isLoaded = false;
		jets_muf_isLoaded = false;
		jets_mcFlavour_isLoaded = false;
		jets_mcHadronFlav_isLoaded = false;
		ht_isLoaded = false;
		ht_up_isLoaded = false;
		ht_dn_isLoaded = false;
		mt_lep1_isLoaded = false;
		mt_min_isLoaded = false;
		mt_max_isLoaded = false;
		weight_btagsf_isLoaded = false;
		weight_btagsf_heavy_UP_isLoaded = false;
		weight_btagsf_light_UP_isLoaded = false;
		weight_btagsf_heavy_DN_isLoaded = false;
		weight_btagsf_light_DN_isLoaded = false;
		met_T1CHS_pt_isLoaded = false;
		met_T1CHS_phi_isLoaded = false;
		met_T1CHS_fromCORE_pt_isLoaded = false;
		met_T1CHS_fromCORE_phi_isLoaded = false;
		met_T1CHS_miniAOD_CORE_pt_isLoaded = false;
		met_T1CHS_miniAOD_CORE_phi_isLoaded = false;
		met_T1CHS_miniAOD_CORE_up_pt_isLoaded = false;
		met_T1CHS_miniAOD_CORE_up_phi_isLoaded = false;
		met_T1CHS_miniAOD_CORE_dn_pt_isLoaded = false;
		met_T1CHS_miniAOD_CORE_dn_phi_isLoaded = false;
		hyp_type_isLoaded = false;
		evt_type_isLoaded = false;
		isrboost_isLoaded = false;
		isr_njets_isLoaded = false;
		isr_weight_isLoaded = false;
		isr_unc_isLoaded = false;
		weightsf_lepid_isLoaded = false;
		weightsf_lepiso_isLoaded = false;
		weightsf_lepip_isLoaded = false;
		weightsf_lepreco_isLoaded = false;
		weightsf_lepconv_isLoaded = false;
		weightsf_lepid_FS_isLoaded = false;
		weightsf_lepiso_FS_isLoaded = false;
		weightsf_lepip_FS_isLoaded = false;
	}

void triboson_v1::LoadAllBranches() 
	// load all branches
{
	if (run_branch != 0) run();
	if (lumi_branch != 0) lumi();
	if (evt_branch != 0) evt();
	if (isData_branch != 0) isData();
	if (evt_passgoodrunlist_branch != 0) evt_passgoodrunlist();
	if (evt_scale1fb_branch != 0) evt_scale1fb();
	if (evt_xsec_branch != 0) evt_xsec();
	if (evt_kfactor_branch != 0) evt_kfactor();
	if (evt_filter_branch != 0) evt_filter();
	if (evt_nEvts_branch != 0) evt_nEvts();
	if (evt_dataset_branch != 0) evt_dataset();
	if (puWeight_branch != 0) puWeight();
	if (nVert_branch != 0) nVert();
	if (nTrueInt_branch != 0) nTrueInt();
	if (rho_branch != 0) rho();
	if (gen_ht_branch != 0) gen_ht();
	if (nBJetTight_branch != 0) nBJetTight();
	if (nBJetMedium_branch != 0) nBJetMedium();
	if (nBJetLoose_branch != 0) nBJetLoose();
	if (nBJetTight_up_branch != 0) nBJetTight_up();
	if (nBJetMedium_up_branch != 0) nBJetMedium_up();
	if (nBJetLoose_up_branch != 0) nBJetLoose_up();
	if (nBJetTight_dn_branch != 0) nBJetTight_dn();
	if (nBJetMedium_dn_branch != 0) nBJetMedium_dn();
	if (nBJetLoose_dn_branch != 0) nBJetLoose_dn();
	if (nJet200MuFrac50DphiMet_branch != 0) nJet200MuFrac50DphiMet();
	if (nMuons10_branch != 0) nMuons10();
	if (nBadMuons20_branch != 0) nBadMuons20();
	if (nElectrons10_branch != 0) nElectrons10();
	if (nGammas20_branch != 0) nGammas20();
	if (nTaus20_branch != 0) nTaus20();
	if (met_pt_branch != 0) met_pt();
	if (met_phi_branch != 0) met_phi();
	if (met_calo_pt_branch != 0) met_calo_pt();
	if (met_calo_phi_branch != 0) met_calo_phi();
	if (met_miniaod_pt_branch != 0) met_miniaod_pt();
	if (met_miniaod_phi_branch != 0) met_miniaod_phi();
	if (met_muegclean_pt_branch != 0) met_muegclean_pt();
	if (met_muegclean_phi_branch != 0) met_muegclean_phi();
	if (met_rawPt_branch != 0) met_rawPt();
	if (met_rawPhi_branch != 0) met_rawPhi();
	if (met_genPt_branch != 0) met_genPt();
	if (met_genPhi_branch != 0) met_genPhi();
	if (sumet_raw_branch != 0) sumet_raw();
	if (Flag_ecalLaserCorrFilter_branch != 0) Flag_ecalLaserCorrFilter();
	if (Flag_hcalLaserEventFilter_branch != 0) Flag_hcalLaserEventFilter();
	if (Flag_trackingFailureFilter_branch != 0) Flag_trackingFailureFilter();
	if (Flag_CSCTightHaloFilter_branch != 0) Flag_CSCTightHaloFilter();
	if (Flag_HBHENoiseFilter_branch != 0) Flag_HBHENoiseFilter();
	if (Flag_HBHEIsoNoiseFilter_branch != 0) Flag_HBHEIsoNoiseFilter();
	if (Flag_CSCTightHalo2015Filter_branch != 0) Flag_CSCTightHalo2015Filter();
	if (Flag_EcalDeadCellTriggerPrimitiveFilter_branch != 0) Flag_EcalDeadCellTriggerPrimitiveFilter();
	if (Flag_goodVertices_branch != 0) Flag_goodVertices();
	if (Flag_eeBadScFilter_branch != 0) Flag_eeBadScFilter();
	if (Flag_globalTightHalo2016_branch != 0) Flag_globalTightHalo2016();
	if (Flag_badMuonFilter_branch != 0) Flag_badMuonFilter();
	if (Flag_badChargedCandidateFilter_branch != 0) Flag_badChargedCandidateFilter();
	if (Flag_badMuonFilterv2_branch != 0) Flag_badMuonFilterv2();
	if (Flag_badChargedCandidateFilterv2_branch != 0) Flag_badChargedCandidateFilterv2();
	if (Flag_badMuons_branch != 0) Flag_badMuons();
	if (Flag_duplicateMuons_branch != 0) Flag_duplicateMuons();
	if (Flag_noBadMuons_branch != 0) Flag_noBadMuons();
	if (HLT_singleEl_branch != 0) HLT_singleEl();
	if (HLT_singleMu_branch != 0) HLT_singleMu();
	if (HLT_singleMu_noiso_branch != 0) HLT_singleMu_noiso();
	if (HLT_DoubleEl_noiso_branch != 0) HLT_DoubleEl_noiso();
	if (HLT_DoubleEl_branch != 0) HLT_DoubleEl();
	if (HLT_DoubleEl_DZ_branch != 0) HLT_DoubleEl_DZ();
	if (HLT_DoubleEl_DZ_2_branch != 0) HLT_DoubleEl_DZ_2();
	if (HLT_MuEG_branch != 0) HLT_MuEG();
	if (HLT_MuEG_2_branch != 0) HLT_MuEG_2();
	if (HLT_MuEG_noiso_branch != 0) HLT_MuEG_noiso();
	if (HLT_MuEG_noiso_2_branch != 0) HLT_MuEG_noiso_2();
	if (HLT_Mu8_EG17_branch != 0) HLT_Mu8_EG17();
	if (HLT_Mu8_EG23_branch != 0) HLT_Mu8_EG23();
	if (HLT_Mu8_EG23_DZ_branch != 0) HLT_Mu8_EG23_DZ();
	if (HLT_Mu12_EG23_DZ_branch != 0) HLT_Mu12_EG23_DZ();
	if (HLT_Mu17_EG12_branch != 0) HLT_Mu17_EG12();
	if (HLT_Mu23_EG8_branch != 0) HLT_Mu23_EG8();
	if (HLT_Mu23_EG8_DZ_branch != 0) HLT_Mu23_EG8_DZ();
	if (HLT_Mu23_EG12_branch != 0) HLT_Mu23_EG12();
	if (HLT_Mu23_EG12_DZ_branch != 0) HLT_Mu23_EG12_DZ();
	if (HLT_DoubleMu_noiso_branch != 0) HLT_DoubleMu_noiso();
	if (HLT_DoubleMu_noiso_27_8_branch != 0) HLT_DoubleMu_noiso_27_8();
	if (HLT_DoubleMu_noiso_30_11_branch != 0) HLT_DoubleMu_noiso_30_11();
	if (HLT_DoubleMu_noiso_40_11_branch != 0) HLT_DoubleMu_noiso_40_11();
	if (HLT_DoubleMu_branch != 0) HLT_DoubleMu();
	if (HLT_DoubleMu_tk_branch != 0) HLT_DoubleMu_tk();
	if (HLT_DoubleMu_dbltk_branch != 0) HLT_DoubleMu_dbltk();
	if (HLT_DoubleMu_nonDZ_branch != 0) HLT_DoubleMu_nonDZ();
	if (HLT_DoubleMu_tk_nonDZ_branch != 0) HLT_DoubleMu_tk_nonDZ();
	if (dilmass_branch != 0) dilmass();
	if (dilpt_branch != 0) dilpt();
	if (trilmass_branch != 0) trilmass();
	if (reilpt_branch != 0) reilpt();
	if (dRll_branch != 0) dRll();
	if (matched_neutralemf_branch != 0) matched_neutralemf();
	if (matched_emf_branch != 0) matched_emf();
	if (elveto_branch != 0) elveto();
	if (nlep_branch != 0) nlep();
	if (nveto_leptons_branch != 0) nveto_leptons();
	if (lep_p4_branch != 0) lep_p4();
	if (lep_pt_branch != 0) lep_pt();
	if (lep_eta_branch != 0) lep_eta();
	if (lep_phi_branch != 0) lep_phi();
	if (lep_mass_branch != 0) lep_mass();
	if (lep_charge_branch != 0) lep_charge();
	if (lep_threecharge_branch != 0) lep_threecharge();
	if (lep_tightcharge_branch != 0) lep_tightcharge();
	if (lep_pdgId_branch != 0) lep_pdgId();
	if (lep_dxy_branch != 0) lep_dxy();
	if (lep_ip3d_branch != 0) lep_ip3d();
	if (lep_ip3derr_branch != 0) lep_ip3derr();
	if (lep_etaSC_branch != 0) lep_etaSC();
	if (lep_dz_branch != 0) lep_dz();
	if (lep_dzerr_branch != 0) lep_dzerr();
	if (lep_vetoId_branch != 0) lep_vetoId();
	if (lep_looseId_branch != 0) lep_looseId();
	if (lep_mediumId_branch != 0) lep_mediumId();
	if (lep_tightId_branch != 0) lep_tightId();
	if (lep_relIso03_branch != 0) lep_relIso03();
	if (lep_relIso03EA_branch != 0) lep_relIso03EA();
	if (lep_relIso03DB_branch != 0) lep_relIso03DB();
	if (lep_relIso04_branch != 0) lep_relIso04();
	if (lep_relIso04EA_branch != 0) lep_relIso04EA();
	if (lep_relIso04DB_branch != 0) lep_relIso04DB();
	if (lep_ptrel_branch != 0) lep_ptrel();
	if (lep_ptratio_branch != 0) lep_ptratio();
	if (lep_mcMatchId_branch != 0) lep_mcMatchId();
	if (lep_lostHits_branch != 0) lep_lostHits();
	if (lep_isfromW_branch != 0) lep_isfromW();
	if (lep_isfromZ_branch != 0) lep_isfromZ();
	if (lep_isfromH_branch != 0) lep_isfromH();
	if (lep_isfromB_branch != 0) lep_isfromB();
	if (lep_isfromC_branch != 0) lep_isfromC();
	if (lep_isfromL_branch != 0) lep_isfromL();
	if (lep_convVeto_branch != 0) lep_convVeto();
	if (lep_MVA_branch != 0) lep_MVA();
	if (lep_validfraction_branch != 0) lep_validfraction();
	if (lep_pterr_branch != 0) lep_pterr();
	if (lep_sta_pterrOpt_branch != 0) lep_sta_pterrOpt();
	if (lep_glb_pterrOpt_branch != 0) lep_glb_pterrOpt();
	if (lep_x2ondof_branch != 0) lep_x2ondof();
	if (lep_sta_x2ondof_branch != 0) lep_sta_x2ondof();
	if (lep_glb_x2ondof_branch != 0) lep_glb_x2ondof();
	if (nisoTracks_branch != 0) nisoTracks();
	if (isotr_p4_branch != 0) isotr_p4();
	if (isotr_relIso03_branch != 0) isotr_relIso03();
	if (isotr_relIso04_branch != 0) isotr_relIso04();
	if (isotr_ptrel_branch != 0) isotr_ptrel();
	if (isotr_ptratio_branch != 0) isotr_ptratio();
	if (isotr_charge_branch != 0) isotr_charge();
	if (isotr_pdgId_branch != 0) isotr_pdgId();
	if (isotr_dz_branch != 0) isotr_dz();
	if (nisoTrack_5gev_branch != 0) nisoTrack_5gev();
	if (nisoTrack_mt2_branch != 0) nisoTrack_mt2();
	if (nisoTrack_PFLep5_woverlaps_branch != 0) nisoTrack_PFLep5_woverlaps();
	if (nisoTrack_PFHad10_woverlaps_branch != 0) nisoTrack_PFHad10_woverlaps();
	if (ngamma_branch != 0) ngamma();
	if (gamma_p4_branch != 0) gamma_p4();
	if (gamma_mcMatchId_branch != 0) gamma_mcMatchId();
	if (gamma_genPt_branch != 0) gamma_genPt();
	if (gamma_genIso_branch != 0) gamma_genIso();
	if (gamma_chHadIso_branch != 0) gamma_chHadIso();
	if (gamma_neuHadIso_branch != 0) gamma_neuHadIso();
	if (gamma_phIso_branch != 0) gamma_phIso();
	if (gamma_idCutBased_branch != 0) gamma_idCutBased();
	if (gamma_drMinParton_branch != 0) gamma_drMinParton();
	if (ngenPart_branch != 0) ngenPart();
	if (genPart_p4_branch != 0) genPart_p4();
	if (genPart_pt_branch != 0) genPart_pt();
	if (genPart_eta_branch != 0) genPart_eta();
	if (genPart_phi_branch != 0) genPart_phi();
	if (genPart_mass_branch != 0) genPart_mass();
	if (genPart_pdgId_branch != 0) genPart_pdgId();
	if (genPart_status_branch != 0) genPart_status();
	if (genPart_charge_branch != 0) genPart_charge();
	if (genPart_motherId_branch != 0) genPart_motherId();
	if (genPart_grandmaId_branch != 0) genPart_grandmaId();
	if (genPart_isp6status3_branch != 0) genPart_isp6status3();
	if (njets_branch != 0) njets();
	if (jets_p4_branch != 0) jets_p4();
	if (removed_jets_p4_branch != 0) removed_jets_p4();
	if (removed_jets_csv_branch != 0) removed_jets_csv();
	if (removed_jets_deepB_branch != 0) removed_jets_deepB();
	if (removed_jets_deepC_branch != 0) removed_jets_deepC();
	if (jets_medb_p4_branch != 0) jets_medb_p4();
	if (njets_up_branch != 0) njets_up();
	if (jets_up_p4_branch != 0) jets_up_p4();
	if (jets_medb_up_p4_branch != 0) jets_medb_up_p4();
	if (jets_csv_branch != 0) jets_csv();
	if (jets_up_csv_branch != 0) jets_up_csv();
	if (jets_deepB_branch != 0) jets_deepB();
	if (jets_up_deepB_branch != 0) jets_up_deepB();
	if (jets_deepC_branch != 0) jets_deepC();
	if (jets_up_deepC_branch != 0) jets_up_deepC();
	if (njets_dn_branch != 0) njets_dn();
	if (jets_dn_p4_branch != 0) jets_dn_p4();
	if (jets_medb_dn_p4_branch != 0) jets_medb_dn_p4();
	if (jets_dn_csv_branch != 0) jets_dn_csv();
	if (jets_dn_deepB_branch != 0) jets_dn_deepB();
	if (jets_dn_deepC_branch != 0) jets_dn_deepC();
	if (jets_muf_branch != 0) jets_muf();
	if (jets_mcFlavour_branch != 0) jets_mcFlavour();
	if (jets_mcHadronFlav_branch != 0) jets_mcHadronFlav();
	if (ht_branch != 0) ht();
	if (ht_up_branch != 0) ht_up();
	if (ht_dn_branch != 0) ht_dn();
	if (mt_lep1_branch != 0) mt_lep1();
	if (mt_min_branch != 0) mt_min();
	if (mt_max_branch != 0) mt_max();
	if (weight_btagsf_branch != 0) weight_btagsf();
	if (weight_btagsf_heavy_UP_branch != 0) weight_btagsf_heavy_UP();
	if (weight_btagsf_light_UP_branch != 0) weight_btagsf_light_UP();
	if (weight_btagsf_heavy_DN_branch != 0) weight_btagsf_heavy_DN();
	if (weight_btagsf_light_DN_branch != 0) weight_btagsf_light_DN();
	if (met_T1CHS_pt_branch != 0) met_T1CHS_pt();
	if (met_T1CHS_phi_branch != 0) met_T1CHS_phi();
	if (met_T1CHS_fromCORE_pt_branch != 0) met_T1CHS_fromCORE_pt();
	if (met_T1CHS_fromCORE_phi_branch != 0) met_T1CHS_fromCORE_phi();
	if (met_T1CHS_miniAOD_CORE_pt_branch != 0) met_T1CHS_miniAOD_CORE_pt();
	if (met_T1CHS_miniAOD_CORE_phi_branch != 0) met_T1CHS_miniAOD_CORE_phi();
	if (met_T1CHS_miniAOD_CORE_up_pt_branch != 0) met_T1CHS_miniAOD_CORE_up_pt();
	if (met_T1CHS_miniAOD_CORE_up_phi_branch != 0) met_T1CHS_miniAOD_CORE_up_phi();
	if (met_T1CHS_miniAOD_CORE_dn_pt_branch != 0) met_T1CHS_miniAOD_CORE_dn_pt();
	if (met_T1CHS_miniAOD_CORE_dn_phi_branch != 0) met_T1CHS_miniAOD_CORE_dn_phi();
	if (hyp_type_branch != 0) hyp_type();
	if (evt_type_branch != 0) evt_type();
	if (isrboost_branch != 0) isrboost();
	if (isr_njets_branch != 0) isr_njets();
	if (isr_weight_branch != 0) isr_weight();
	if (isr_unc_branch != 0) isr_unc();
	if (weightsf_lepid_branch != 0) weightsf_lepid();
	if (weightsf_lepiso_branch != 0) weightsf_lepiso();
	if (weightsf_lepip_branch != 0) weightsf_lepip();
	if (weightsf_lepreco_branch != 0) weightsf_lepreco();
	if (weightsf_lepconv_branch != 0) weightsf_lepconv();
	if (weightsf_lepid_FS_branch != 0) weightsf_lepid_FS();
	if (weightsf_lepiso_FS_branch != 0) weightsf_lepiso_FS();
	if (weightsf_lepip_FS_branch != 0) weightsf_lepip_FS();
}

	const int &triboson_v1::run()
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
	const int &triboson_v1::lumi()
	{
		if (not lumi_isLoaded) {
			if (lumi_branch != 0) {
				lumi_branch->GetEntry(index);
			} else { 
				printf("branch lumi_branch does not exist!\n");
				exit(1);
			}
			lumi_isLoaded = true;
		}
		return lumi_;
	}
	const unsigned long long &triboson_v1::evt()
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
	const int &triboson_v1::isData()
	{
		if (not isData_isLoaded) {
			if (isData_branch != 0) {
				isData_branch->GetEntry(index);
			} else { 
				printf("branch isData_branch does not exist!\n");
				exit(1);
			}
			isData_isLoaded = true;
		}
		return isData_;
	}
	const bool &	triboson_v1::evt_passgoodrunlist()
	{
		if (not evt_passgoodrunlist_isLoaded) {
			if (evt_passgoodrunlist_branch != 0) {
				evt_passgoodrunlist_branch->GetEntry(index);
			} else { 
				printf("branch evt_passgoodrunlist_branch does not exist!\n");
				exit(1);
			}
			evt_passgoodrunlist_isLoaded = true;
		}
		return evt_passgoodrunlist_;
	}
	const float &triboson_v1::evt_scale1fb()
	{
		if (not evt_scale1fb_isLoaded) {
			if (evt_scale1fb_branch != 0) {
				evt_scale1fb_branch->GetEntry(index);
			} else { 
				printf("branch evt_scale1fb_branch does not exist!\n");
				exit(1);
			}
			evt_scale1fb_isLoaded = true;
		}
		return evt_scale1fb_;
	}
	const float &triboson_v1::evt_xsec()
	{
		if (not evt_xsec_isLoaded) {
			if (evt_xsec_branch != 0) {
				evt_xsec_branch->GetEntry(index);
			} else { 
				printf("branch evt_xsec_branch does not exist!\n");
				exit(1);
			}
			evt_xsec_isLoaded = true;
		}
		return evt_xsec_;
	}
	const float &triboson_v1::evt_kfactor()
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
	const float &triboson_v1::evt_filter()
	{
		if (not evt_filter_isLoaded) {
			if (evt_filter_branch != 0) {
				evt_filter_branch->GetEntry(index);
			} else { 
				printf("branch evt_filter_branch does not exist!\n");
				exit(1);
			}
			evt_filter_isLoaded = true;
		}
		return evt_filter_;
	}
	const int &triboson_v1::evt_nEvts()
	{
		if (not evt_nEvts_isLoaded) {
			if (evt_nEvts_branch != 0) {
				evt_nEvts_branch->GetEntry(index);
			} else { 
				printf("branch evt_nEvts_branch does not exist!\n");
				exit(1);
			}
			evt_nEvts_isLoaded = true;
		}
		return evt_nEvts_;
	}
	const vector<TString> &triboson_v1::evt_dataset()
	{
		if (not evt_dataset_isLoaded) {
			if (evt_dataset_branch != 0) {
				evt_dataset_branch->GetEntry(index);
			} else { 
				printf("branch evt_dataset_branch does not exist!\n");
				exit(1);
			}
			evt_dataset_isLoaded = true;
		}
		return *evt_dataset_;
	}
	const float &triboson_v1::puWeight()
	{
		if (not puWeight_isLoaded) {
			if (puWeight_branch != 0) {
				puWeight_branch->GetEntry(index);
			} else { 
				printf("branch puWeight_branch does not exist!\n");
				exit(1);
			}
			puWeight_isLoaded = true;
		}
		return puWeight_;
	}
	const int &triboson_v1::nVert()
	{
		if (not nVert_isLoaded) {
			if (nVert_branch != 0) {
				nVert_branch->GetEntry(index);
			} else { 
				printf("branch nVert_branch does not exist!\n");
				exit(1);
			}
			nVert_isLoaded = true;
		}
		return nVert_;
	}
	const int &triboson_v1::nTrueInt()
	{
		if (not nTrueInt_isLoaded) {
			if (nTrueInt_branch != 0) {
				nTrueInt_branch->GetEntry(index);
			} else { 
				printf("branch nTrueInt_branch does not exist!\n");
				exit(1);
			}
			nTrueInt_isLoaded = true;
		}
		return nTrueInt_;
	}
	const float &triboson_v1::rho()
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
	const float &triboson_v1::gen_ht()
	{
		if (not gen_ht_isLoaded) {
			if (gen_ht_branch != 0) {
				gen_ht_branch->GetEntry(index);
			} else { 
				printf("branch gen_ht_branch does not exist!\n");
				exit(1);
			}
			gen_ht_isLoaded = true;
		}
		return gen_ht_;
	}
	const int &triboson_v1::nBJetTight()
	{
		if (not nBJetTight_isLoaded) {
			if (nBJetTight_branch != 0) {
				nBJetTight_branch->GetEntry(index);
			} else { 
				printf("branch nBJetTight_branch does not exist!\n");
				exit(1);
			}
			nBJetTight_isLoaded = true;
		}
		return nBJetTight_;
	}
	const int &triboson_v1::nBJetMedium()
	{
		if (not nBJetMedium_isLoaded) {
			if (nBJetMedium_branch != 0) {
				nBJetMedium_branch->GetEntry(index);
			} else { 
				printf("branch nBJetMedium_branch does not exist!\n");
				exit(1);
			}
			nBJetMedium_isLoaded = true;
		}
		return nBJetMedium_;
	}
	const int &triboson_v1::nBJetLoose()
	{
		if (not nBJetLoose_isLoaded) {
			if (nBJetLoose_branch != 0) {
				nBJetLoose_branch->GetEntry(index);
			} else { 
				printf("branch nBJetLoose_branch does not exist!\n");
				exit(1);
			}
			nBJetLoose_isLoaded = true;
		}
		return nBJetLoose_;
	}
	const int &triboson_v1::nBJetTight_up()
	{
		if (not nBJetTight_up_isLoaded) {
			if (nBJetTight_up_branch != 0) {
				nBJetTight_up_branch->GetEntry(index);
			} else { 
				printf("branch nBJetTight_up_branch does not exist!\n");
				exit(1);
			}
			nBJetTight_up_isLoaded = true;
		}
		return nBJetTight_up_;
	}
	const int &triboson_v1::nBJetMedium_up()
	{
		if (not nBJetMedium_up_isLoaded) {
			if (nBJetMedium_up_branch != 0) {
				nBJetMedium_up_branch->GetEntry(index);
			} else { 
				printf("branch nBJetMedium_up_branch does not exist!\n");
				exit(1);
			}
			nBJetMedium_up_isLoaded = true;
		}
		return nBJetMedium_up_;
	}
	const int &triboson_v1::nBJetLoose_up()
	{
		if (not nBJetLoose_up_isLoaded) {
			if (nBJetLoose_up_branch != 0) {
				nBJetLoose_up_branch->GetEntry(index);
			} else { 
				printf("branch nBJetLoose_up_branch does not exist!\n");
				exit(1);
			}
			nBJetLoose_up_isLoaded = true;
		}
		return nBJetLoose_up_;
	}
	const int &triboson_v1::nBJetTight_dn()
	{
		if (not nBJetTight_dn_isLoaded) {
			if (nBJetTight_dn_branch != 0) {
				nBJetTight_dn_branch->GetEntry(index);
			} else { 
				printf("branch nBJetTight_dn_branch does not exist!\n");
				exit(1);
			}
			nBJetTight_dn_isLoaded = true;
		}
		return nBJetTight_dn_;
	}
	const int &triboson_v1::nBJetMedium_dn()
	{
		if (not nBJetMedium_dn_isLoaded) {
			if (nBJetMedium_dn_branch != 0) {
				nBJetMedium_dn_branch->GetEntry(index);
			} else { 
				printf("branch nBJetMedium_dn_branch does not exist!\n");
				exit(1);
			}
			nBJetMedium_dn_isLoaded = true;
		}
		return nBJetMedium_dn_;
	}
	const int &triboson_v1::nBJetLoose_dn()
	{
		if (not nBJetLoose_dn_isLoaded) {
			if (nBJetLoose_dn_branch != 0) {
				nBJetLoose_dn_branch->GetEntry(index);
			} else { 
				printf("branch nBJetLoose_dn_branch does not exist!\n");
				exit(1);
			}
			nBJetLoose_dn_isLoaded = true;
		}
		return nBJetLoose_dn_;
	}
	const int &triboson_v1::nJet200MuFrac50DphiMet()
	{
		if (not nJet200MuFrac50DphiMet_isLoaded) {
			if (nJet200MuFrac50DphiMet_branch != 0) {
				nJet200MuFrac50DphiMet_branch->GetEntry(index);
			} else { 
				printf("branch nJet200MuFrac50DphiMet_branch does not exist!\n");
				exit(1);
			}
			nJet200MuFrac50DphiMet_isLoaded = true;
		}
		return nJet200MuFrac50DphiMet_;
	}
	const int &triboson_v1::nMuons10()
	{
		if (not nMuons10_isLoaded) {
			if (nMuons10_branch != 0) {
				nMuons10_branch->GetEntry(index);
			} else { 
				printf("branch nMuons10_branch does not exist!\n");
				exit(1);
			}
			nMuons10_isLoaded = true;
		}
		return nMuons10_;
	}
	const int &triboson_v1::nBadMuons20()
	{
		if (not nBadMuons20_isLoaded) {
			if (nBadMuons20_branch != 0) {
				nBadMuons20_branch->GetEntry(index);
			} else { 
				printf("branch nBadMuons20_branch does not exist!\n");
				exit(1);
			}
			nBadMuons20_isLoaded = true;
		}
		return nBadMuons20_;
	}
	const int &triboson_v1::nElectrons10()
	{
		if (not nElectrons10_isLoaded) {
			if (nElectrons10_branch != 0) {
				nElectrons10_branch->GetEntry(index);
			} else { 
				printf("branch nElectrons10_branch does not exist!\n");
				exit(1);
			}
			nElectrons10_isLoaded = true;
		}
		return nElectrons10_;
	}
	const int &triboson_v1::nGammas20()
	{
		if (not nGammas20_isLoaded) {
			if (nGammas20_branch != 0) {
				nGammas20_branch->GetEntry(index);
			} else { 
				printf("branch nGammas20_branch does not exist!\n");
				exit(1);
			}
			nGammas20_isLoaded = true;
		}
		return nGammas20_;
	}
	const int &triboson_v1::nTaus20()
	{
		if (not nTaus20_isLoaded) {
			if (nTaus20_branch != 0) {
				nTaus20_branch->GetEntry(index);
			} else { 
				printf("branch nTaus20_branch does not exist!\n");
				exit(1);
			}
			nTaus20_isLoaded = true;
		}
		return nTaus20_;
	}
	const float &triboson_v1::met_pt()
	{
		if (not met_pt_isLoaded) {
			if (met_pt_branch != 0) {
				met_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_pt_branch does not exist!\n");
				exit(1);
			}
			met_pt_isLoaded = true;
		}
		return met_pt_;
	}
	const float &triboson_v1::met_phi()
	{
		if (not met_phi_isLoaded) {
			if (met_phi_branch != 0) {
				met_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_phi_branch does not exist!\n");
				exit(1);
			}
			met_phi_isLoaded = true;
		}
		return met_phi_;
	}
	const float &triboson_v1::met_calo_pt()
	{
		if (not met_calo_pt_isLoaded) {
			if (met_calo_pt_branch != 0) {
				met_calo_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_calo_pt_branch does not exist!\n");
				exit(1);
			}
			met_calo_pt_isLoaded = true;
		}
		return met_calo_pt_;
	}
	const float &triboson_v1::met_calo_phi()
	{
		if (not met_calo_phi_isLoaded) {
			if (met_calo_phi_branch != 0) {
				met_calo_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_calo_phi_branch does not exist!\n");
				exit(1);
			}
			met_calo_phi_isLoaded = true;
		}
		return met_calo_phi_;
	}
	const float &triboson_v1::met_miniaod_pt()
	{
		if (not met_miniaod_pt_isLoaded) {
			if (met_miniaod_pt_branch != 0) {
				met_miniaod_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_miniaod_pt_branch does not exist!\n");
				exit(1);
			}
			met_miniaod_pt_isLoaded = true;
		}
		return met_miniaod_pt_;
	}
	const float &triboson_v1::met_miniaod_phi()
	{
		if (not met_miniaod_phi_isLoaded) {
			if (met_miniaod_phi_branch != 0) {
				met_miniaod_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_miniaod_phi_branch does not exist!\n");
				exit(1);
			}
			met_miniaod_phi_isLoaded = true;
		}
		return met_miniaod_phi_;
	}
	const float &triboson_v1::met_muegclean_pt()
	{
		if (not met_muegclean_pt_isLoaded) {
			if (met_muegclean_pt_branch != 0) {
				met_muegclean_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_muegclean_pt_branch does not exist!\n");
				exit(1);
			}
			met_muegclean_pt_isLoaded = true;
		}
		return met_muegclean_pt_;
	}
	const float &triboson_v1::met_muegclean_phi()
	{
		if (not met_muegclean_phi_isLoaded) {
			if (met_muegclean_phi_branch != 0) {
				met_muegclean_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_muegclean_phi_branch does not exist!\n");
				exit(1);
			}
			met_muegclean_phi_isLoaded = true;
		}
		return met_muegclean_phi_;
	}
	const float &triboson_v1::met_rawPt()
	{
		if (not met_rawPt_isLoaded) {
			if (met_rawPt_branch != 0) {
				met_rawPt_branch->GetEntry(index);
			} else { 
				printf("branch met_rawPt_branch does not exist!\n");
				exit(1);
			}
			met_rawPt_isLoaded = true;
		}
		return met_rawPt_;
	}
	const float &triboson_v1::met_rawPhi()
	{
		if (not met_rawPhi_isLoaded) {
			if (met_rawPhi_branch != 0) {
				met_rawPhi_branch->GetEntry(index);
			} else { 
				printf("branch met_rawPhi_branch does not exist!\n");
				exit(1);
			}
			met_rawPhi_isLoaded = true;
		}
		return met_rawPhi_;
	}
	const float &triboson_v1::met_genPt()
	{
		if (not met_genPt_isLoaded) {
			if (met_genPt_branch != 0) {
				met_genPt_branch->GetEntry(index);
			} else { 
				printf("branch met_genPt_branch does not exist!\n");
				exit(1);
			}
			met_genPt_isLoaded = true;
		}
		return met_genPt_;
	}
	const float &triboson_v1::met_genPhi()
	{
		if (not met_genPhi_isLoaded) {
			if (met_genPhi_branch != 0) {
				met_genPhi_branch->GetEntry(index);
			} else { 
				printf("branch met_genPhi_branch does not exist!\n");
				exit(1);
			}
			met_genPhi_isLoaded = true;
		}
		return met_genPhi_;
	}
	const float &triboson_v1::sumet_raw()
	{
		if (not sumet_raw_isLoaded) {
			if (sumet_raw_branch != 0) {
				sumet_raw_branch->GetEntry(index);
			} else { 
				printf("branch sumet_raw_branch does not exist!\n");
				exit(1);
			}
			sumet_raw_isLoaded = true;
		}
		return sumet_raw_;
	}
	const int &triboson_v1::Flag_ecalLaserCorrFilter()
	{
		if (not Flag_ecalLaserCorrFilter_isLoaded) {
			if (Flag_ecalLaserCorrFilter_branch != 0) {
				Flag_ecalLaserCorrFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_ecalLaserCorrFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_ecalLaserCorrFilter_isLoaded = true;
		}
		return Flag_ecalLaserCorrFilter_;
	}
	const int &triboson_v1::Flag_hcalLaserEventFilter()
	{
		if (not Flag_hcalLaserEventFilter_isLoaded) {
			if (Flag_hcalLaserEventFilter_branch != 0) {
				Flag_hcalLaserEventFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_hcalLaserEventFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_hcalLaserEventFilter_isLoaded = true;
		}
		return Flag_hcalLaserEventFilter_;
	}
	const int &triboson_v1::Flag_trackingFailureFilter()
	{
		if (not Flag_trackingFailureFilter_isLoaded) {
			if (Flag_trackingFailureFilter_branch != 0) {
				Flag_trackingFailureFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_trackingFailureFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_trackingFailureFilter_isLoaded = true;
		}
		return Flag_trackingFailureFilter_;
	}
	const int &triboson_v1::Flag_CSCTightHaloFilter()
	{
		if (not Flag_CSCTightHaloFilter_isLoaded) {
			if (Flag_CSCTightHaloFilter_branch != 0) {
				Flag_CSCTightHaloFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_CSCTightHaloFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_CSCTightHaloFilter_isLoaded = true;
		}
		return Flag_CSCTightHaloFilter_;
	}
	const int &triboson_v1::Flag_HBHENoiseFilter()
	{
		if (not Flag_HBHENoiseFilter_isLoaded) {
			if (Flag_HBHENoiseFilter_branch != 0) {
				Flag_HBHENoiseFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_HBHENoiseFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_HBHENoiseFilter_isLoaded = true;
		}
		return Flag_HBHENoiseFilter_;
	}
	const int &triboson_v1::Flag_HBHEIsoNoiseFilter()
	{
		if (not Flag_HBHEIsoNoiseFilter_isLoaded) {
			if (Flag_HBHEIsoNoiseFilter_branch != 0) {
				Flag_HBHEIsoNoiseFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_HBHEIsoNoiseFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_HBHEIsoNoiseFilter_isLoaded = true;
		}
		return Flag_HBHEIsoNoiseFilter_;
	}
	const int &triboson_v1::Flag_CSCTightHalo2015Filter()
	{
		if (not Flag_CSCTightHalo2015Filter_isLoaded) {
			if (Flag_CSCTightHalo2015Filter_branch != 0) {
				Flag_CSCTightHalo2015Filter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_CSCTightHalo2015Filter_branch does not exist!\n");
				exit(1);
			}
			Flag_CSCTightHalo2015Filter_isLoaded = true;
		}
		return Flag_CSCTightHalo2015Filter_;
	}
	const int &triboson_v1::Flag_EcalDeadCellTriggerPrimitiveFilter()
	{
		if (not Flag_EcalDeadCellTriggerPrimitiveFilter_isLoaded) {
			if (Flag_EcalDeadCellTriggerPrimitiveFilter_branch != 0) {
				Flag_EcalDeadCellTriggerPrimitiveFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_EcalDeadCellTriggerPrimitiveFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_EcalDeadCellTriggerPrimitiveFilter_isLoaded = true;
		}
		return Flag_EcalDeadCellTriggerPrimitiveFilter_;
	}
	const int &triboson_v1::Flag_goodVertices()
	{
		if (not Flag_goodVertices_isLoaded) {
			if (Flag_goodVertices_branch != 0) {
				Flag_goodVertices_branch->GetEntry(index);
			} else { 
				printf("branch Flag_goodVertices_branch does not exist!\n");
				exit(1);
			}
			Flag_goodVertices_isLoaded = true;
		}
		return Flag_goodVertices_;
	}
	const int &triboson_v1::Flag_eeBadScFilter()
	{
		if (not Flag_eeBadScFilter_isLoaded) {
			if (Flag_eeBadScFilter_branch != 0) {
				Flag_eeBadScFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_eeBadScFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_eeBadScFilter_isLoaded = true;
		}
		return Flag_eeBadScFilter_;
	}
	const int &triboson_v1::Flag_globalTightHalo2016()
	{
		if (not Flag_globalTightHalo2016_isLoaded) {
			if (Flag_globalTightHalo2016_branch != 0) {
				Flag_globalTightHalo2016_branch->GetEntry(index);
			} else { 
				printf("branch Flag_globalTightHalo2016_branch does not exist!\n");
				exit(1);
			}
			Flag_globalTightHalo2016_isLoaded = true;
		}
		return Flag_globalTightHalo2016_;
	}
	const int &triboson_v1::Flag_badMuonFilter()
	{
		if (not Flag_badMuonFilter_isLoaded) {
			if (Flag_badMuonFilter_branch != 0) {
				Flag_badMuonFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_badMuonFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_badMuonFilter_isLoaded = true;
		}
		return Flag_badMuonFilter_;
	}
	const int &triboson_v1::Flag_badChargedCandidateFilter()
	{
		if (not Flag_badChargedCandidateFilter_isLoaded) {
			if (Flag_badChargedCandidateFilter_branch != 0) {
				Flag_badChargedCandidateFilter_branch->GetEntry(index);
			} else { 
				printf("branch Flag_badChargedCandidateFilter_branch does not exist!\n");
				exit(1);
			}
			Flag_badChargedCandidateFilter_isLoaded = true;
		}
		return Flag_badChargedCandidateFilter_;
	}
	const int &triboson_v1::Flag_badMuonFilterv2()
	{
		if (not Flag_badMuonFilterv2_isLoaded) {
			if (Flag_badMuonFilterv2_branch != 0) {
				Flag_badMuonFilterv2_branch->GetEntry(index);
			} else { 
				printf("branch Flag_badMuonFilterv2_branch does not exist!\n");
				exit(1);
			}
			Flag_badMuonFilterv2_isLoaded = true;
		}
		return Flag_badMuonFilterv2_;
	}
	const int &triboson_v1::Flag_badChargedCandidateFilterv2()
	{
		if (not Flag_badChargedCandidateFilterv2_isLoaded) {
			if (Flag_badChargedCandidateFilterv2_branch != 0) {
				Flag_badChargedCandidateFilterv2_branch->GetEntry(index);
			} else { 
				printf("branch Flag_badChargedCandidateFilterv2_branch does not exist!\n");
				exit(1);
			}
			Flag_badChargedCandidateFilterv2_isLoaded = true;
		}
		return Flag_badChargedCandidateFilterv2_;
	}
	const int &triboson_v1::Flag_badMuons()
	{
		if (not Flag_badMuons_isLoaded) {
			if (Flag_badMuons_branch != 0) {
				Flag_badMuons_branch->GetEntry(index);
			} else { 
				printf("branch Flag_badMuons_branch does not exist!\n");
				exit(1);
			}
			Flag_badMuons_isLoaded = true;
		}
		return Flag_badMuons_;
	}
	const int &triboson_v1::Flag_duplicateMuons()
	{
		if (not Flag_duplicateMuons_isLoaded) {
			if (Flag_duplicateMuons_branch != 0) {
				Flag_duplicateMuons_branch->GetEntry(index);
			} else { 
				printf("branch Flag_duplicateMuons_branch does not exist!\n");
				exit(1);
			}
			Flag_duplicateMuons_isLoaded = true;
		}
		return Flag_duplicateMuons_;
	}
	const int &triboson_v1::Flag_noBadMuons()
	{
		if (not Flag_noBadMuons_isLoaded) {
			if (Flag_noBadMuons_branch != 0) {
				Flag_noBadMuons_branch->GetEntry(index);
			} else { 
				printf("branch Flag_noBadMuons_branch does not exist!\n");
				exit(1);
			}
			Flag_noBadMuons_isLoaded = true;
		}
		return Flag_noBadMuons_;
	}
	const int &triboson_v1::HLT_singleEl()
	{
		if (not HLT_singleEl_isLoaded) {
			if (HLT_singleEl_branch != 0) {
				HLT_singleEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_singleEl_branch does not exist!\n");
				exit(1);
			}
			HLT_singleEl_isLoaded = true;
		}
		return HLT_singleEl_;
	}
	const int &triboson_v1::HLT_singleMu()
	{
		if (not HLT_singleMu_isLoaded) {
			if (HLT_singleMu_branch != 0) {
				HLT_singleMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_singleMu_branch does not exist!\n");
				exit(1);
			}
			HLT_singleMu_isLoaded = true;
		}
		return HLT_singleMu_;
	}
	const int &triboson_v1::HLT_singleMu_noiso()
	{
		if (not HLT_singleMu_noiso_isLoaded) {
			if (HLT_singleMu_noiso_branch != 0) {
				HLT_singleMu_noiso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_singleMu_noiso_branch does not exist!\n");
				exit(1);
			}
			HLT_singleMu_noiso_isLoaded = true;
		}
		return HLT_singleMu_noiso_;
	}
	const int &triboson_v1::HLT_DoubleEl_noiso()
	{
		if (not HLT_DoubleEl_noiso_isLoaded) {
			if (HLT_DoubleEl_noiso_branch != 0) {
				HLT_DoubleEl_noiso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleEl_noiso_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleEl_noiso_isLoaded = true;
		}
		return HLT_DoubleEl_noiso_;
	}
	const int &triboson_v1::HLT_DoubleEl()
	{
		if (not HLT_DoubleEl_isLoaded) {
			if (HLT_DoubleEl_branch != 0) {
				HLT_DoubleEl_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleEl_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleEl_isLoaded = true;
		}
		return HLT_DoubleEl_;
	}
	const int &triboson_v1::HLT_DoubleEl_DZ()
	{
		if (not HLT_DoubleEl_DZ_isLoaded) {
			if (HLT_DoubleEl_DZ_branch != 0) {
				HLT_DoubleEl_DZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleEl_DZ_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleEl_DZ_isLoaded = true;
		}
		return HLT_DoubleEl_DZ_;
	}
	const int &triboson_v1::HLT_DoubleEl_DZ_2()
	{
		if (not HLT_DoubleEl_DZ_2_isLoaded) {
			if (HLT_DoubleEl_DZ_2_branch != 0) {
				HLT_DoubleEl_DZ_2_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleEl_DZ_2_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleEl_DZ_2_isLoaded = true;
		}
		return HLT_DoubleEl_DZ_2_;
	}
	const int &triboson_v1::HLT_MuEG()
	{
		if (not HLT_MuEG_isLoaded) {
			if (HLT_MuEG_branch != 0) {
				HLT_MuEG_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MuEG_branch does not exist!\n");
				exit(1);
			}
			HLT_MuEG_isLoaded = true;
		}
		return HLT_MuEG_;
	}
	const int &triboson_v1::HLT_MuEG_2()
	{
		if (not HLT_MuEG_2_isLoaded) {
			if (HLT_MuEG_2_branch != 0) {
				HLT_MuEG_2_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MuEG_2_branch does not exist!\n");
				exit(1);
			}
			HLT_MuEG_2_isLoaded = true;
		}
		return HLT_MuEG_2_;
	}
	const int &triboson_v1::HLT_MuEG_noiso()
	{
		if (not HLT_MuEG_noiso_isLoaded) {
			if (HLT_MuEG_noiso_branch != 0) {
				HLT_MuEG_noiso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MuEG_noiso_branch does not exist!\n");
				exit(1);
			}
			HLT_MuEG_noiso_isLoaded = true;
		}
		return HLT_MuEG_noiso_;
	}
	const int &triboson_v1::HLT_MuEG_noiso_2()
	{
		if (not HLT_MuEG_noiso_2_isLoaded) {
			if (HLT_MuEG_noiso_2_branch != 0) {
				HLT_MuEG_noiso_2_branch->GetEntry(index);
			} else { 
				printf("branch HLT_MuEG_noiso_2_branch does not exist!\n");
				exit(1);
			}
			HLT_MuEG_noiso_2_isLoaded = true;
		}
		return HLT_MuEG_noiso_2_;
	}
	const int &triboson_v1::HLT_Mu8_EG17()
	{
		if (not HLT_Mu8_EG17_isLoaded) {
			if (HLT_Mu8_EG17_branch != 0) {
				HLT_Mu8_EG17_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8_EG17_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8_EG17_isLoaded = true;
		}
		return HLT_Mu8_EG17_;
	}
	const int &triboson_v1::HLT_Mu8_EG23()
	{
		if (not HLT_Mu8_EG23_isLoaded) {
			if (HLT_Mu8_EG23_branch != 0) {
				HLT_Mu8_EG23_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8_EG23_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8_EG23_isLoaded = true;
		}
		return HLT_Mu8_EG23_;
	}
	const int &triboson_v1::HLT_Mu8_EG23_DZ()
	{
		if (not HLT_Mu8_EG23_DZ_isLoaded) {
			if (HLT_Mu8_EG23_DZ_branch != 0) {
				HLT_Mu8_EG23_DZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu8_EG23_DZ_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu8_EG23_DZ_isLoaded = true;
		}
		return HLT_Mu8_EG23_DZ_;
	}
	const int &triboson_v1::HLT_Mu12_EG23_DZ()
	{
		if (not HLT_Mu12_EG23_DZ_isLoaded) {
			if (HLT_Mu12_EG23_DZ_branch != 0) {
				HLT_Mu12_EG23_DZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu12_EG23_DZ_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu12_EG23_DZ_isLoaded = true;
		}
		return HLT_Mu12_EG23_DZ_;
	}
	const int &triboson_v1::HLT_Mu17_EG12()
	{
		if (not HLT_Mu17_EG12_isLoaded) {
			if (HLT_Mu17_EG12_branch != 0) {
				HLT_Mu17_EG12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu17_EG12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu17_EG12_isLoaded = true;
		}
		return HLT_Mu17_EG12_;
	}
	const int &triboson_v1::HLT_Mu23_EG8()
	{
		if (not HLT_Mu23_EG8_isLoaded) {
			if (HLT_Mu23_EG8_branch != 0) {
				HLT_Mu23_EG8_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23_EG8_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23_EG8_isLoaded = true;
		}
		return HLT_Mu23_EG8_;
	}
	const int &triboson_v1::HLT_Mu23_EG8_DZ()
	{
		if (not HLT_Mu23_EG8_DZ_isLoaded) {
			if (HLT_Mu23_EG8_DZ_branch != 0) {
				HLT_Mu23_EG8_DZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23_EG8_DZ_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23_EG8_DZ_isLoaded = true;
		}
		return HLT_Mu23_EG8_DZ_;
	}
	const int &triboson_v1::HLT_Mu23_EG12()
	{
		if (not HLT_Mu23_EG12_isLoaded) {
			if (HLT_Mu23_EG12_branch != 0) {
				HLT_Mu23_EG12_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23_EG12_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23_EG12_isLoaded = true;
		}
		return HLT_Mu23_EG12_;
	}
	const int &triboson_v1::HLT_Mu23_EG12_DZ()
	{
		if (not HLT_Mu23_EG12_DZ_isLoaded) {
			if (HLT_Mu23_EG12_DZ_branch != 0) {
				HLT_Mu23_EG12_DZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_Mu23_EG12_DZ_branch does not exist!\n");
				exit(1);
			}
			HLT_Mu23_EG12_DZ_isLoaded = true;
		}
		return HLT_Mu23_EG12_DZ_;
	}
	const int &triboson_v1::HLT_DoubleMu_noiso()
	{
		if (not HLT_DoubleMu_noiso_isLoaded) {
			if (HLT_DoubleMu_noiso_branch != 0) {
				HLT_DoubleMu_noiso_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_noiso_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_noiso_isLoaded = true;
		}
		return HLT_DoubleMu_noiso_;
	}
	const int &triboson_v1::HLT_DoubleMu_noiso_27_8()
	{
		if (not HLT_DoubleMu_noiso_27_8_isLoaded) {
			if (HLT_DoubleMu_noiso_27_8_branch != 0) {
				HLT_DoubleMu_noiso_27_8_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_noiso_27_8_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_noiso_27_8_isLoaded = true;
		}
		return HLT_DoubleMu_noiso_27_8_;
	}
	const int &triboson_v1::HLT_DoubleMu_noiso_30_11()
	{
		if (not HLT_DoubleMu_noiso_30_11_isLoaded) {
			if (HLT_DoubleMu_noiso_30_11_branch != 0) {
				HLT_DoubleMu_noiso_30_11_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_noiso_30_11_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_noiso_30_11_isLoaded = true;
		}
		return HLT_DoubleMu_noiso_30_11_;
	}
	const int &triboson_v1::HLT_DoubleMu_noiso_40_11()
	{
		if (not HLT_DoubleMu_noiso_40_11_isLoaded) {
			if (HLT_DoubleMu_noiso_40_11_branch != 0) {
				HLT_DoubleMu_noiso_40_11_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_noiso_40_11_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_noiso_40_11_isLoaded = true;
		}
		return HLT_DoubleMu_noiso_40_11_;
	}
	const int &triboson_v1::HLT_DoubleMu()
	{
		if (not HLT_DoubleMu_isLoaded) {
			if (HLT_DoubleMu_branch != 0) {
				HLT_DoubleMu_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_isLoaded = true;
		}
		return HLT_DoubleMu_;
	}
	const int &triboson_v1::HLT_DoubleMu_tk()
	{
		if (not HLT_DoubleMu_tk_isLoaded) {
			if (HLT_DoubleMu_tk_branch != 0) {
				HLT_DoubleMu_tk_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_tk_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_tk_isLoaded = true;
		}
		return HLT_DoubleMu_tk_;
	}
	const int &triboson_v1::HLT_DoubleMu_dbltk()
	{
		if (not HLT_DoubleMu_dbltk_isLoaded) {
			if (HLT_DoubleMu_dbltk_branch != 0) {
				HLT_DoubleMu_dbltk_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_dbltk_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_dbltk_isLoaded = true;
		}
		return HLT_DoubleMu_dbltk_;
	}
	const int &triboson_v1::HLT_DoubleMu_nonDZ()
	{
		if (not HLT_DoubleMu_nonDZ_isLoaded) {
			if (HLT_DoubleMu_nonDZ_branch != 0) {
				HLT_DoubleMu_nonDZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_nonDZ_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_nonDZ_isLoaded = true;
		}
		return HLT_DoubleMu_nonDZ_;
	}
	const int &triboson_v1::HLT_DoubleMu_tk_nonDZ()
	{
		if (not HLT_DoubleMu_tk_nonDZ_isLoaded) {
			if (HLT_DoubleMu_tk_nonDZ_branch != 0) {
				HLT_DoubleMu_tk_nonDZ_branch->GetEntry(index);
			} else { 
				printf("branch HLT_DoubleMu_tk_nonDZ_branch does not exist!\n");
				exit(1);
			}
			HLT_DoubleMu_tk_nonDZ_isLoaded = true;
		}
		return HLT_DoubleMu_tk_nonDZ_;
	}
	const float &triboson_v1::dilmass()
	{
		if (not dilmass_isLoaded) {
			if (dilmass_branch != 0) {
				dilmass_branch->GetEntry(index);
			} else { 
				printf("branch dilmass_branch does not exist!\n");
				exit(1);
			}
			dilmass_isLoaded = true;
		}
		return dilmass_;
	}
	const float &triboson_v1::dilpt()
	{
		if (not dilpt_isLoaded) {
			if (dilpt_branch != 0) {
				dilpt_branch->GetEntry(index);
			} else { 
				printf("branch dilpt_branch does not exist!\n");
				exit(1);
			}
			dilpt_isLoaded = true;
		}
		return dilpt_;
	}
	const float &triboson_v1::trilmass()
	{
		if (not trilmass_isLoaded) {
			if (trilmass_branch != 0) {
				trilmass_branch->GetEntry(index);
			} else { 
				printf("branch trilmass_branch does not exist!\n");
				exit(1);
			}
			trilmass_isLoaded = true;
		}
		return trilmass_;
	}
	const float &triboson_v1::reilpt()
	{
		if (not reilpt_isLoaded) {
			if (reilpt_branch != 0) {
				reilpt_branch->GetEntry(index);
			} else { 
				printf("branch reilpt_branch does not exist!\n");
				exit(1);
			}
			reilpt_isLoaded = true;
		}
		return reilpt_;
	}
	const float &triboson_v1::dRll()
	{
		if (not dRll_isLoaded) {
			if (dRll_branch != 0) {
				dRll_branch->GetEntry(index);
			} else { 
				printf("branch dRll_branch does not exist!\n");
				exit(1);
			}
			dRll_isLoaded = true;
		}
		return dRll_;
	}
	const float &triboson_v1::matched_neutralemf()
	{
		if (not matched_neutralemf_isLoaded) {
			if (matched_neutralemf_branch != 0) {
				matched_neutralemf_branch->GetEntry(index);
			} else { 
				printf("branch matched_neutralemf_branch does not exist!\n");
				exit(1);
			}
			matched_neutralemf_isLoaded = true;
		}
		return matched_neutralemf_;
	}
	const float &triboson_v1::matched_emf()
	{
		if (not matched_emf_isLoaded) {
			if (matched_emf_branch != 0) {
				matched_emf_branch->GetEntry(index);
			} else { 
				printf("branch matched_emf_branch does not exist!\n");
				exit(1);
			}
			matched_emf_isLoaded = true;
		}
		return matched_emf_;
	}
	const bool &	triboson_v1::elveto()
	{
		if (not elveto_isLoaded) {
			if (elveto_branch != 0) {
				elveto_branch->GetEntry(index);
			} else { 
				printf("branch elveto_branch does not exist!\n");
				exit(1);
			}
			elveto_isLoaded = true;
		}
		return elveto_;
	}
	const int &triboson_v1::nlep()
	{
		if (not nlep_isLoaded) {
			if (nlep_branch != 0) {
				nlep_branch->GetEntry(index);
			} else { 
				printf("branch nlep_branch does not exist!\n");
				exit(1);
			}
			nlep_isLoaded = true;
		}
		return nlep_;
	}
	const int &triboson_v1::nveto_leptons()
	{
		if (not nveto_leptons_isLoaded) {
			if (nveto_leptons_branch != 0) {
				nveto_leptons_branch->GetEntry(index);
			} else { 
				printf("branch nveto_leptons_branch does not exist!\n");
				exit(1);
			}
			nveto_leptons_isLoaded = true;
		}
		return nveto_leptons_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::lep_p4()
	{
		if (not lep_p4_isLoaded) {
			if (lep_p4_branch != 0) {
				lep_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep_p4_branch does not exist!\n");
				exit(1);
			}
			lep_p4_isLoaded = true;
		}
		return *lep_p4_;
	}
	const vector<float> &triboson_v1::lep_pt()
	{
		if (not lep_pt_isLoaded) {
			if (lep_pt_branch != 0) {
				lep_pt_branch->GetEntry(index);
			} else { 
				printf("branch lep_pt_branch does not exist!\n");
				exit(1);
			}
			lep_pt_isLoaded = true;
		}
		return *lep_pt_;
	}
	const vector<float> &triboson_v1::lep_eta()
	{
		if (not lep_eta_isLoaded) {
			if (lep_eta_branch != 0) {
				lep_eta_branch->GetEntry(index);
			} else { 
				printf("branch lep_eta_branch does not exist!\n");
				exit(1);
			}
			lep_eta_isLoaded = true;
		}
		return *lep_eta_;
	}
	const vector<float> &triboson_v1::lep_phi()
	{
		if (not lep_phi_isLoaded) {
			if (lep_phi_branch != 0) {
				lep_phi_branch->GetEntry(index);
			} else { 
				printf("branch lep_phi_branch does not exist!\n");
				exit(1);
			}
			lep_phi_isLoaded = true;
		}
		return *lep_phi_;
	}
	const vector<float> &triboson_v1::lep_mass()
	{
		if (not lep_mass_isLoaded) {
			if (lep_mass_branch != 0) {
				lep_mass_branch->GetEntry(index);
			} else { 
				printf("branch lep_mass_branch does not exist!\n");
				exit(1);
			}
			lep_mass_isLoaded = true;
		}
		return *lep_mass_;
	}
	const vector<int> &triboson_v1::lep_charge()
	{
		if (not lep_charge_isLoaded) {
			if (lep_charge_branch != 0) {
				lep_charge_branch->GetEntry(index);
			} else { 
				printf("branch lep_charge_branch does not exist!\n");
				exit(1);
			}
			lep_charge_isLoaded = true;
		}
		return *lep_charge_;
	}
	const vector<int> &triboson_v1::lep_threecharge()
	{
		if (not lep_threecharge_isLoaded) {
			if (lep_threecharge_branch != 0) {
				lep_threecharge_branch->GetEntry(index);
			} else { 
				printf("branch lep_threecharge_branch does not exist!\n");
				exit(1);
			}
			lep_threecharge_isLoaded = true;
		}
		return *lep_threecharge_;
	}
	const vector<int> &triboson_v1::lep_tightcharge()
	{
		if (not lep_tightcharge_isLoaded) {
			if (lep_tightcharge_branch != 0) {
				lep_tightcharge_branch->GetEntry(index);
			} else { 
				printf("branch lep_tightcharge_branch does not exist!\n");
				exit(1);
			}
			lep_tightcharge_isLoaded = true;
		}
		return *lep_tightcharge_;
	}
	const vector<int> &triboson_v1::lep_pdgId()
	{
		if (not lep_pdgId_isLoaded) {
			if (lep_pdgId_branch != 0) {
				lep_pdgId_branch->GetEntry(index);
			} else { 
				printf("branch lep_pdgId_branch does not exist!\n");
				exit(1);
			}
			lep_pdgId_isLoaded = true;
		}
		return *lep_pdgId_;
	}
	const vector<float> &triboson_v1::lep_dxy()
	{
		if (not lep_dxy_isLoaded) {
			if (lep_dxy_branch != 0) {
				lep_dxy_branch->GetEntry(index);
			} else { 
				printf("branch lep_dxy_branch does not exist!\n");
				exit(1);
			}
			lep_dxy_isLoaded = true;
		}
		return *lep_dxy_;
	}
	const vector<float> &triboson_v1::lep_ip3d()
	{
		if (not lep_ip3d_isLoaded) {
			if (lep_ip3d_branch != 0) {
				lep_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep_ip3d_isLoaded = true;
		}
		return *lep_ip3d_;
	}
	const vector<float> &triboson_v1::lep_ip3derr()
	{
		if (not lep_ip3derr_isLoaded) {
			if (lep_ip3derr_branch != 0) {
				lep_ip3derr_branch->GetEntry(index);
			} else { 
				printf("branch lep_ip3derr_branch does not exist!\n");
				exit(1);
			}
			lep_ip3derr_isLoaded = true;
		}
		return *lep_ip3derr_;
	}
	const vector<float> &triboson_v1::lep_etaSC()
	{
		if (not lep_etaSC_isLoaded) {
			if (lep_etaSC_branch != 0) {
				lep_etaSC_branch->GetEntry(index);
			} else { 
				printf("branch lep_etaSC_branch does not exist!\n");
				exit(1);
			}
			lep_etaSC_isLoaded = true;
		}
		return *lep_etaSC_;
	}
	const vector<float> &triboson_v1::lep_dz()
	{
		if (not lep_dz_isLoaded) {
			if (lep_dz_branch != 0) {
				lep_dz_branch->GetEntry(index);
			} else { 
				printf("branch lep_dz_branch does not exist!\n");
				exit(1);
			}
			lep_dz_isLoaded = true;
		}
		return *lep_dz_;
	}
	const vector<float> &triboson_v1::lep_dzerr()
	{
		if (not lep_dzerr_isLoaded) {
			if (lep_dzerr_branch != 0) {
				lep_dzerr_branch->GetEntry(index);
			} else { 
				printf("branch lep_dzerr_branch does not exist!\n");
				exit(1);
			}
			lep_dzerr_isLoaded = true;
		}
		return *lep_dzerr_;
	}
	const vector<int> &triboson_v1::lep_vetoId()
	{
		if (not lep_vetoId_isLoaded) {
			if (lep_vetoId_branch != 0) {
				lep_vetoId_branch->GetEntry(index);
			} else { 
				printf("branch lep_vetoId_branch does not exist!\n");
				exit(1);
			}
			lep_vetoId_isLoaded = true;
		}
		return *lep_vetoId_;
	}
	const vector<int> &triboson_v1::lep_looseId()
	{
		if (not lep_looseId_isLoaded) {
			if (lep_looseId_branch != 0) {
				lep_looseId_branch->GetEntry(index);
			} else { 
				printf("branch lep_looseId_branch does not exist!\n");
				exit(1);
			}
			lep_looseId_isLoaded = true;
		}
		return *lep_looseId_;
	}
	const vector<int> &triboson_v1::lep_mediumId()
	{
		if (not lep_mediumId_isLoaded) {
			if (lep_mediumId_branch != 0) {
				lep_mediumId_branch->GetEntry(index);
			} else { 
				printf("branch lep_mediumId_branch does not exist!\n");
				exit(1);
			}
			lep_mediumId_isLoaded = true;
		}
		return *lep_mediumId_;
	}
	const vector<int> &triboson_v1::lep_tightId()
	{
		if (not lep_tightId_isLoaded) {
			if (lep_tightId_branch != 0) {
				lep_tightId_branch->GetEntry(index);
			} else { 
				printf("branch lep_tightId_branch does not exist!\n");
				exit(1);
			}
			lep_tightId_isLoaded = true;
		}
		return *lep_tightId_;
	}
	const vector<float> &triboson_v1::lep_relIso03()
	{
		if (not lep_relIso03_isLoaded) {
			if (lep_relIso03_branch != 0) {
				lep_relIso03_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso03_branch does not exist!\n");
				exit(1);
			}
			lep_relIso03_isLoaded = true;
		}
		return *lep_relIso03_;
	}
	const vector<float> &triboson_v1::lep_relIso03EA()
	{
		if (not lep_relIso03EA_isLoaded) {
			if (lep_relIso03EA_branch != 0) {
				lep_relIso03EA_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso03EA_branch does not exist!\n");
				exit(1);
			}
			lep_relIso03EA_isLoaded = true;
		}
		return *lep_relIso03EA_;
	}
	const vector<float> &triboson_v1::lep_relIso03DB()
	{
		if (not lep_relIso03DB_isLoaded) {
			if (lep_relIso03DB_branch != 0) {
				lep_relIso03DB_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso03DB_branch does not exist!\n");
				exit(1);
			}
			lep_relIso03DB_isLoaded = true;
		}
		return *lep_relIso03DB_;
	}
	const vector<float> &triboson_v1::lep_relIso04()
	{
		if (not lep_relIso04_isLoaded) {
			if (lep_relIso04_branch != 0) {
				lep_relIso04_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso04_branch does not exist!\n");
				exit(1);
			}
			lep_relIso04_isLoaded = true;
		}
		return *lep_relIso04_;
	}
	const vector<float> &triboson_v1::lep_relIso04EA()
	{
		if (not lep_relIso04EA_isLoaded) {
			if (lep_relIso04EA_branch != 0) {
				lep_relIso04EA_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso04EA_branch does not exist!\n");
				exit(1);
			}
			lep_relIso04EA_isLoaded = true;
		}
		return *lep_relIso04EA_;
	}
	const vector<float> &triboson_v1::lep_relIso04DB()
	{
		if (not lep_relIso04DB_isLoaded) {
			if (lep_relIso04DB_branch != 0) {
				lep_relIso04DB_branch->GetEntry(index);
			} else { 
				printf("branch lep_relIso04DB_branch does not exist!\n");
				exit(1);
			}
			lep_relIso04DB_isLoaded = true;
		}
		return *lep_relIso04DB_;
	}
	const vector<float> &triboson_v1::lep_ptrel()
	{
		if (not lep_ptrel_isLoaded) {
			if (lep_ptrel_branch != 0) {
				lep_ptrel_branch->GetEntry(index);
			} else { 
				printf("branch lep_ptrel_branch does not exist!\n");
				exit(1);
			}
			lep_ptrel_isLoaded = true;
		}
		return *lep_ptrel_;
	}
	const vector<float> &triboson_v1::lep_ptratio()
	{
		if (not lep_ptratio_isLoaded) {
			if (lep_ptratio_branch != 0) {
				lep_ptratio_branch->GetEntry(index);
			} else { 
				printf("branch lep_ptratio_branch does not exist!\n");
				exit(1);
			}
			lep_ptratio_isLoaded = true;
		}
		return *lep_ptratio_;
	}
	const vector<int> &triboson_v1::lep_mcMatchId()
	{
		if (not lep_mcMatchId_isLoaded) {
			if (lep_mcMatchId_branch != 0) {
				lep_mcMatchId_branch->GetEntry(index);
			} else { 
				printf("branch lep_mcMatchId_branch does not exist!\n");
				exit(1);
			}
			lep_mcMatchId_isLoaded = true;
		}
		return *lep_mcMatchId_;
	}
	const vector<int> &triboson_v1::lep_lostHits()
	{
		if (not lep_lostHits_isLoaded) {
			if (lep_lostHits_branch != 0) {
				lep_lostHits_branch->GetEntry(index);
			} else { 
				printf("branch lep_lostHits_branch does not exist!\n");
				exit(1);
			}
			lep_lostHits_isLoaded = true;
		}
		return *lep_lostHits_;
	}
	const vector<int> &triboson_v1::lep_isfromW()
	{
		if (not lep_isfromW_isLoaded) {
			if (lep_isfromW_branch != 0) {
				lep_isfromW_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromW_branch does not exist!\n");
				exit(1);
			}
			lep_isfromW_isLoaded = true;
		}
		return *lep_isfromW_;
	}
	const vector<int> &triboson_v1::lep_isfromZ()
	{
		if (not lep_isfromZ_isLoaded) {
			if (lep_isfromZ_branch != 0) {
				lep_isfromZ_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromZ_branch does not exist!\n");
				exit(1);
			}
			lep_isfromZ_isLoaded = true;
		}
		return *lep_isfromZ_;
	}
	const vector<int> &triboson_v1::lep_isfromH()
	{
		if (not lep_isfromH_isLoaded) {
			if (lep_isfromH_branch != 0) {
				lep_isfromH_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromH_branch does not exist!\n");
				exit(1);
			}
			lep_isfromH_isLoaded = true;
		}
		return *lep_isfromH_;
	}
	const vector<int> &triboson_v1::lep_isfromB()
	{
		if (not lep_isfromB_isLoaded) {
			if (lep_isfromB_branch != 0) {
				lep_isfromB_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromB_branch does not exist!\n");
				exit(1);
			}
			lep_isfromB_isLoaded = true;
		}
		return *lep_isfromB_;
	}
	const vector<int> &triboson_v1::lep_isfromC()
	{
		if (not lep_isfromC_isLoaded) {
			if (lep_isfromC_branch != 0) {
				lep_isfromC_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromC_branch does not exist!\n");
				exit(1);
			}
			lep_isfromC_isLoaded = true;
		}
		return *lep_isfromC_;
	}
	const vector<int> &triboson_v1::lep_isfromL()
	{
		if (not lep_isfromL_isLoaded) {
			if (lep_isfromL_branch != 0) {
				lep_isfromL_branch->GetEntry(index);
			} else { 
				printf("branch lep_isfromL_branch does not exist!\n");
				exit(1);
			}
			lep_isfromL_isLoaded = true;
		}
		return *lep_isfromL_;
	}
	const vector<int> &triboson_v1::lep_convVeto()
	{
		if (not lep_convVeto_isLoaded) {
			if (lep_convVeto_branch != 0) {
				lep_convVeto_branch->GetEntry(index);
			} else { 
				printf("branch lep_convVeto_branch does not exist!\n");
				exit(1);
			}
			lep_convVeto_isLoaded = true;
		}
		return *lep_convVeto_;
	}
	const vector<float> &triboson_v1::lep_MVA()
	{
		if (not lep_MVA_isLoaded) {
			if (lep_MVA_branch != 0) {
				lep_MVA_branch->GetEntry(index);
			} else { 
				printf("branch lep_MVA_branch does not exist!\n");
				exit(1);
			}
			lep_MVA_isLoaded = true;
		}
		return *lep_MVA_;
	}
	const vector<float> &triboson_v1::lep_validfraction()
	{
		if (not lep_validfraction_isLoaded) {
			if (lep_validfraction_branch != 0) {
				lep_validfraction_branch->GetEntry(index);
			} else { 
				printf("branch lep_validfraction_branch does not exist!\n");
				exit(1);
			}
			lep_validfraction_isLoaded = true;
		}
		return *lep_validfraction_;
	}
	const vector<float> &triboson_v1::lep_pterr()
	{
		if (not lep_pterr_isLoaded) {
			if (lep_pterr_branch != 0) {
				lep_pterr_branch->GetEntry(index);
			} else { 
				printf("branch lep_pterr_branch does not exist!\n");
				exit(1);
			}
			lep_pterr_isLoaded = true;
		}
		return *lep_pterr_;
	}
	const vector<float> &triboson_v1::lep_sta_pterrOpt()
	{
		if (not lep_sta_pterrOpt_isLoaded) {
			if (lep_sta_pterrOpt_branch != 0) {
				lep_sta_pterrOpt_branch->GetEntry(index);
			} else { 
				printf("branch lep_sta_pterrOpt_branch does not exist!\n");
				exit(1);
			}
			lep_sta_pterrOpt_isLoaded = true;
		}
		return *lep_sta_pterrOpt_;
	}
	const vector<float> &triboson_v1::lep_glb_pterrOpt()
	{
		if (not lep_glb_pterrOpt_isLoaded) {
			if (lep_glb_pterrOpt_branch != 0) {
				lep_glb_pterrOpt_branch->GetEntry(index);
			} else { 
				printf("branch lep_glb_pterrOpt_branch does not exist!\n");
				exit(1);
			}
			lep_glb_pterrOpt_isLoaded = true;
		}
		return *lep_glb_pterrOpt_;
	}
	const vector<float> &triboson_v1::lep_x2ondof()
	{
		if (not lep_x2ondof_isLoaded) {
			if (lep_x2ondof_branch != 0) {
				lep_x2ondof_branch->GetEntry(index);
			} else { 
				printf("branch lep_x2ondof_branch does not exist!\n");
				exit(1);
			}
			lep_x2ondof_isLoaded = true;
		}
		return *lep_x2ondof_;
	}
	const vector<float> &triboson_v1::lep_sta_x2ondof()
	{
		if (not lep_sta_x2ondof_isLoaded) {
			if (lep_sta_x2ondof_branch != 0) {
				lep_sta_x2ondof_branch->GetEntry(index);
			} else { 
				printf("branch lep_sta_x2ondof_branch does not exist!\n");
				exit(1);
			}
			lep_sta_x2ondof_isLoaded = true;
		}
		return *lep_sta_x2ondof_;
	}
	const vector<float> &triboson_v1::lep_glb_x2ondof()
	{
		if (not lep_glb_x2ondof_isLoaded) {
			if (lep_glb_x2ondof_branch != 0) {
				lep_glb_x2ondof_branch->GetEntry(index);
			} else { 
				printf("branch lep_glb_x2ondof_branch does not exist!\n");
				exit(1);
			}
			lep_glb_x2ondof_isLoaded = true;
		}
		return *lep_glb_x2ondof_;
	}
	const int &triboson_v1::nisoTracks()
	{
		if (not nisoTracks_isLoaded) {
			if (nisoTracks_branch != 0) {
				nisoTracks_branch->GetEntry(index);
			} else { 
				printf("branch nisoTracks_branch does not exist!\n");
				exit(1);
			}
			nisoTracks_isLoaded = true;
		}
		return nisoTracks_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::isotr_p4()
	{
		if (not isotr_p4_isLoaded) {
			if (isotr_p4_branch != 0) {
				isotr_p4_branch->GetEntry(index);
			} else { 
				printf("branch isotr_p4_branch does not exist!\n");
				exit(1);
			}
			isotr_p4_isLoaded = true;
		}
		return *isotr_p4_;
	}
	const vector<float> &triboson_v1::isotr_relIso03()
	{
		if (not isotr_relIso03_isLoaded) {
			if (isotr_relIso03_branch != 0) {
				isotr_relIso03_branch->GetEntry(index);
			} else { 
				printf("branch isotr_relIso03_branch does not exist!\n");
				exit(1);
			}
			isotr_relIso03_isLoaded = true;
		}
		return *isotr_relIso03_;
	}
	const vector<float> &triboson_v1::isotr_relIso04()
	{
		if (not isotr_relIso04_isLoaded) {
			if (isotr_relIso04_branch != 0) {
				isotr_relIso04_branch->GetEntry(index);
			} else { 
				printf("branch isotr_relIso04_branch does not exist!\n");
				exit(1);
			}
			isotr_relIso04_isLoaded = true;
		}
		return *isotr_relIso04_;
	}
	const vector<float> &triboson_v1::isotr_ptrel()
	{
		if (not isotr_ptrel_isLoaded) {
			if (isotr_ptrel_branch != 0) {
				isotr_ptrel_branch->GetEntry(index);
			} else { 
				printf("branch isotr_ptrel_branch does not exist!\n");
				exit(1);
			}
			isotr_ptrel_isLoaded = true;
		}
		return *isotr_ptrel_;
	}
	const vector<float> &triboson_v1::isotr_ptratio()
	{
		if (not isotr_ptratio_isLoaded) {
			if (isotr_ptratio_branch != 0) {
				isotr_ptratio_branch->GetEntry(index);
			} else { 
				printf("branch isotr_ptratio_branch does not exist!\n");
				exit(1);
			}
			isotr_ptratio_isLoaded = true;
		}
		return *isotr_ptratio_;
	}
	const vector<int> &triboson_v1::isotr_charge()
	{
		if (not isotr_charge_isLoaded) {
			if (isotr_charge_branch != 0) {
				isotr_charge_branch->GetEntry(index);
			} else { 
				printf("branch isotr_charge_branch does not exist!\n");
				exit(1);
			}
			isotr_charge_isLoaded = true;
		}
		return *isotr_charge_;
	}
	const vector<int> &triboson_v1::isotr_pdgId()
	{
		if (not isotr_pdgId_isLoaded) {
			if (isotr_pdgId_branch != 0) {
				isotr_pdgId_branch->GetEntry(index);
			} else { 
				printf("branch isotr_pdgId_branch does not exist!\n");
				exit(1);
			}
			isotr_pdgId_isLoaded = true;
		}
		return *isotr_pdgId_;
	}
	const vector<float> &triboson_v1::isotr_dz()
	{
		if (not isotr_dz_isLoaded) {
			if (isotr_dz_branch != 0) {
				isotr_dz_branch->GetEntry(index);
			} else { 
				printf("branch isotr_dz_branch does not exist!\n");
				exit(1);
			}
			isotr_dz_isLoaded = true;
		}
		return *isotr_dz_;
	}
	const int &triboson_v1::nisoTrack_5gev()
	{
		if (not nisoTrack_5gev_isLoaded) {
			if (nisoTrack_5gev_branch != 0) {
				nisoTrack_5gev_branch->GetEntry(index);
			} else { 
				printf("branch nisoTrack_5gev_branch does not exist!\n");
				exit(1);
			}
			nisoTrack_5gev_isLoaded = true;
		}
		return nisoTrack_5gev_;
	}
	const int &triboson_v1::nisoTrack_mt2()
	{
		if (not nisoTrack_mt2_isLoaded) {
			if (nisoTrack_mt2_branch != 0) {
				nisoTrack_mt2_branch->GetEntry(index);
			} else { 
				printf("branch nisoTrack_mt2_branch does not exist!\n");
				exit(1);
			}
			nisoTrack_mt2_isLoaded = true;
		}
		return nisoTrack_mt2_;
	}
	const int &triboson_v1::nisoTrack_PFLep5_woverlaps()
	{
		if (not nisoTrack_PFLep5_woverlaps_isLoaded) {
			if (nisoTrack_PFLep5_woverlaps_branch != 0) {
				nisoTrack_PFLep5_woverlaps_branch->GetEntry(index);
			} else { 
				printf("branch nisoTrack_PFLep5_woverlaps_branch does not exist!\n");
				exit(1);
			}
			nisoTrack_PFLep5_woverlaps_isLoaded = true;
		}
		return nisoTrack_PFLep5_woverlaps_;
	}
	const int &triboson_v1::nisoTrack_PFHad10_woverlaps()
	{
		if (not nisoTrack_PFHad10_woverlaps_isLoaded) {
			if (nisoTrack_PFHad10_woverlaps_branch != 0) {
				nisoTrack_PFHad10_woverlaps_branch->GetEntry(index);
			} else { 
				printf("branch nisoTrack_PFHad10_woverlaps_branch does not exist!\n");
				exit(1);
			}
			nisoTrack_PFHad10_woverlaps_isLoaded = true;
		}
		return nisoTrack_PFHad10_woverlaps_;
	}
	const int &triboson_v1::ngamma()
	{
		if (not ngamma_isLoaded) {
			if (ngamma_branch != 0) {
				ngamma_branch->GetEntry(index);
			} else { 
				printf("branch ngamma_branch does not exist!\n");
				exit(1);
			}
			ngamma_isLoaded = true;
		}
		return ngamma_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::gamma_p4()
	{
		if (not gamma_p4_isLoaded) {
			if (gamma_p4_branch != 0) {
				gamma_p4_branch->GetEntry(index);
			} else { 
				printf("branch gamma_p4_branch does not exist!\n");
				exit(1);
			}
			gamma_p4_isLoaded = true;
		}
		return *gamma_p4_;
	}
	const vector<int> &triboson_v1::gamma_mcMatchId()
	{
		if (not gamma_mcMatchId_isLoaded) {
			if (gamma_mcMatchId_branch != 0) {
				gamma_mcMatchId_branch->GetEntry(index);
			} else { 
				printf("branch gamma_mcMatchId_branch does not exist!\n");
				exit(1);
			}
			gamma_mcMatchId_isLoaded = true;
		}
		return *gamma_mcMatchId_;
	}
	const vector<float> &triboson_v1::gamma_genPt()
	{
		if (not gamma_genPt_isLoaded) {
			if (gamma_genPt_branch != 0) {
				gamma_genPt_branch->GetEntry(index);
			} else { 
				printf("branch gamma_genPt_branch does not exist!\n");
				exit(1);
			}
			gamma_genPt_isLoaded = true;
		}
		return *gamma_genPt_;
	}
	const vector<float> &triboson_v1::gamma_genIso()
	{
		if (not gamma_genIso_isLoaded) {
			if (gamma_genIso_branch != 0) {
				gamma_genIso_branch->GetEntry(index);
			} else { 
				printf("branch gamma_genIso_branch does not exist!\n");
				exit(1);
			}
			gamma_genIso_isLoaded = true;
		}
		return *gamma_genIso_;
	}
	const vector<float> &triboson_v1::gamma_chHadIso()
	{
		if (not gamma_chHadIso_isLoaded) {
			if (gamma_chHadIso_branch != 0) {
				gamma_chHadIso_branch->GetEntry(index);
			} else { 
				printf("branch gamma_chHadIso_branch does not exist!\n");
				exit(1);
			}
			gamma_chHadIso_isLoaded = true;
		}
		return *gamma_chHadIso_;
	}
	const vector<float> &triboson_v1::gamma_neuHadIso()
	{
		if (not gamma_neuHadIso_isLoaded) {
			if (gamma_neuHadIso_branch != 0) {
				gamma_neuHadIso_branch->GetEntry(index);
			} else { 
				printf("branch gamma_neuHadIso_branch does not exist!\n");
				exit(1);
			}
			gamma_neuHadIso_isLoaded = true;
		}
		return *gamma_neuHadIso_;
	}
	const vector<float> &triboson_v1::gamma_phIso()
	{
		if (not gamma_phIso_isLoaded) {
			if (gamma_phIso_branch != 0) {
				gamma_phIso_branch->GetEntry(index);
			} else { 
				printf("branch gamma_phIso_branch does not exist!\n");
				exit(1);
			}
			gamma_phIso_isLoaded = true;
		}
		return *gamma_phIso_;
	}
	const vector<int> &triboson_v1::gamma_idCutBased()
	{
		if (not gamma_idCutBased_isLoaded) {
			if (gamma_idCutBased_branch != 0) {
				gamma_idCutBased_branch->GetEntry(index);
			} else { 
				printf("branch gamma_idCutBased_branch does not exist!\n");
				exit(1);
			}
			gamma_idCutBased_isLoaded = true;
		}
		return *gamma_idCutBased_;
	}
	const vector<float> &triboson_v1::gamma_drMinParton()
	{
		if (not gamma_drMinParton_isLoaded) {
			if (gamma_drMinParton_branch != 0) {
				gamma_drMinParton_branch->GetEntry(index);
			} else { 
				printf("branch gamma_drMinParton_branch does not exist!\n");
				exit(1);
			}
			gamma_drMinParton_isLoaded = true;
		}
		return *gamma_drMinParton_;
	}
	const int &triboson_v1::ngenPart()
	{
		if (not ngenPart_isLoaded) {
			if (ngenPart_branch != 0) {
				ngenPart_branch->GetEntry(index);
			} else { 
				printf("branch ngenPart_branch does not exist!\n");
				exit(1);
			}
			ngenPart_isLoaded = true;
		}
		return ngenPart_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::genPart_p4()
	{
		if (not genPart_p4_isLoaded) {
			if (genPart_p4_branch != 0) {
				genPart_p4_branch->GetEntry(index);
			} else { 
				printf("branch genPart_p4_branch does not exist!\n");
				exit(1);
			}
			genPart_p4_isLoaded = true;
		}
		return *genPart_p4_;
	}
	const vector<float> &triboson_v1::genPart_pt()
	{
		if (not genPart_pt_isLoaded) {
			if (genPart_pt_branch != 0) {
				genPart_pt_branch->GetEntry(index);
			} else { 
				printf("branch genPart_pt_branch does not exist!\n");
				exit(1);
			}
			genPart_pt_isLoaded = true;
		}
		return *genPart_pt_;
	}
	const vector<float> &triboson_v1::genPart_eta()
	{
		if (not genPart_eta_isLoaded) {
			if (genPart_eta_branch != 0) {
				genPart_eta_branch->GetEntry(index);
			} else { 
				printf("branch genPart_eta_branch does not exist!\n");
				exit(1);
			}
			genPart_eta_isLoaded = true;
		}
		return *genPart_eta_;
	}
	const vector<float> &triboson_v1::genPart_phi()
	{
		if (not genPart_phi_isLoaded) {
			if (genPart_phi_branch != 0) {
				genPart_phi_branch->GetEntry(index);
			} else { 
				printf("branch genPart_phi_branch does not exist!\n");
				exit(1);
			}
			genPart_phi_isLoaded = true;
		}
		return *genPart_phi_;
	}
	const vector<float> &triboson_v1::genPart_mass()
	{
		if (not genPart_mass_isLoaded) {
			if (genPart_mass_branch != 0) {
				genPart_mass_branch->GetEntry(index);
			} else { 
				printf("branch genPart_mass_branch does not exist!\n");
				exit(1);
			}
			genPart_mass_isLoaded = true;
		}
		return *genPart_mass_;
	}
	const vector<int> &triboson_v1::genPart_pdgId()
	{
		if (not genPart_pdgId_isLoaded) {
			if (genPart_pdgId_branch != 0) {
				genPart_pdgId_branch->GetEntry(index);
			} else { 
				printf("branch genPart_pdgId_branch does not exist!\n");
				exit(1);
			}
			genPart_pdgId_isLoaded = true;
		}
		return *genPart_pdgId_;
	}
	const vector<int> &triboson_v1::genPart_status()
	{
		if (not genPart_status_isLoaded) {
			if (genPart_status_branch != 0) {
				genPart_status_branch->GetEntry(index);
			} else { 
				printf("branch genPart_status_branch does not exist!\n");
				exit(1);
			}
			genPart_status_isLoaded = true;
		}
		return *genPart_status_;
	}
	const vector<float> &triboson_v1::genPart_charge()
	{
		if (not genPart_charge_isLoaded) {
			if (genPart_charge_branch != 0) {
				genPart_charge_branch->GetEntry(index);
			} else { 
				printf("branch genPart_charge_branch does not exist!\n");
				exit(1);
			}
			genPart_charge_isLoaded = true;
		}
		return *genPart_charge_;
	}
	const vector<int> &triboson_v1::genPart_motherId()
	{
		if (not genPart_motherId_isLoaded) {
			if (genPart_motherId_branch != 0) {
				genPart_motherId_branch->GetEntry(index);
			} else { 
				printf("branch genPart_motherId_branch does not exist!\n");
				exit(1);
			}
			genPart_motherId_isLoaded = true;
		}
		return *genPart_motherId_;
	}
	const vector<int> &triboson_v1::genPart_grandmaId()
	{
		if (not genPart_grandmaId_isLoaded) {
			if (genPart_grandmaId_branch != 0) {
				genPart_grandmaId_branch->GetEntry(index);
			} else { 
				printf("branch genPart_grandmaId_branch does not exist!\n");
				exit(1);
			}
			genPart_grandmaId_isLoaded = true;
		}
		return *genPart_grandmaId_;
	}
	const vector<bool> &triboson_v1::genPart_isp6status3()
	{
		if (not genPart_isp6status3_isLoaded) {
			if (genPart_isp6status3_branch != 0) {
				genPart_isp6status3_branch->GetEntry(index);
			} else { 
				printf("branch genPart_isp6status3_branch does not exist!\n");
				exit(1);
			}
			genPart_isp6status3_isLoaded = true;
		}
		return *genPart_isp6status3_;
	}
	const int &triboson_v1::njets()
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
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_p4()
	{
		if (not jets_p4_isLoaded) {
			if (jets_p4_branch != 0) {
				jets_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_p4_branch does not exist!\n");
				exit(1);
			}
			jets_p4_isLoaded = true;
		}
		return *jets_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::removed_jets_p4()
	{
		if (not removed_jets_p4_isLoaded) {
			if (removed_jets_p4_branch != 0) {
				removed_jets_p4_branch->GetEntry(index);
			} else { 
				printf("branch removed_jets_p4_branch does not exist!\n");
				exit(1);
			}
			removed_jets_p4_isLoaded = true;
		}
		return *removed_jets_p4_;
	}
	const vector<float> &triboson_v1::removed_jets_csv()
	{
		if (not removed_jets_csv_isLoaded) {
			if (removed_jets_csv_branch != 0) {
				removed_jets_csv_branch->GetEntry(index);
			} else { 
				printf("branch removed_jets_csv_branch does not exist!\n");
				exit(1);
			}
			removed_jets_csv_isLoaded = true;
		}
		return *removed_jets_csv_;
	}
	const vector<float> &triboson_v1::removed_jets_deepB()
	{
		if (not removed_jets_deepB_isLoaded) {
			if (removed_jets_deepB_branch != 0) {
				removed_jets_deepB_branch->GetEntry(index);
			} else { 
				printf("branch removed_jets_deepB_branch does not exist!\n");
				exit(1);
			}
			removed_jets_deepB_isLoaded = true;
		}
		return *removed_jets_deepB_;
	}
	const vector<float> &triboson_v1::removed_jets_deepC()
	{
		if (not removed_jets_deepC_isLoaded) {
			if (removed_jets_deepC_branch != 0) {
				removed_jets_deepC_branch->GetEntry(index);
			} else { 
				printf("branch removed_jets_deepC_branch does not exist!\n");
				exit(1);
			}
			removed_jets_deepC_isLoaded = true;
		}
		return *removed_jets_deepC_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_medb_p4()
	{
		if (not jets_medb_p4_isLoaded) {
			if (jets_medb_p4_branch != 0) {
				jets_medb_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_medb_p4_branch does not exist!\n");
				exit(1);
			}
			jets_medb_p4_isLoaded = true;
		}
		return *jets_medb_p4_;
	}
	const int &triboson_v1::njets_up()
	{
		if (not njets_up_isLoaded) {
			if (njets_up_branch != 0) {
				njets_up_branch->GetEntry(index);
			} else { 
				printf("branch njets_up_branch does not exist!\n");
				exit(1);
			}
			njets_up_isLoaded = true;
		}
		return njets_up_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_up_p4()
	{
		if (not jets_up_p4_isLoaded) {
			if (jets_up_p4_branch != 0) {
				jets_up_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_up_p4_branch does not exist!\n");
				exit(1);
			}
			jets_up_p4_isLoaded = true;
		}
		return *jets_up_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_medb_up_p4()
	{
		if (not jets_medb_up_p4_isLoaded) {
			if (jets_medb_up_p4_branch != 0) {
				jets_medb_up_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_medb_up_p4_branch does not exist!\n");
				exit(1);
			}
			jets_medb_up_p4_isLoaded = true;
		}
		return *jets_medb_up_p4_;
	}
	const vector<float> &triboson_v1::jets_csv()
	{
		if (not jets_csv_isLoaded) {
			if (jets_csv_branch != 0) {
				jets_csv_branch->GetEntry(index);
			} else { 
				printf("branch jets_csv_branch does not exist!\n");
				exit(1);
			}
			jets_csv_isLoaded = true;
		}
		return *jets_csv_;
	}
	const vector<float> &triboson_v1::jets_up_csv()
	{
		if (not jets_up_csv_isLoaded) {
			if (jets_up_csv_branch != 0) {
				jets_up_csv_branch->GetEntry(index);
			} else { 
				printf("branch jets_up_csv_branch does not exist!\n");
				exit(1);
			}
			jets_up_csv_isLoaded = true;
		}
		return *jets_up_csv_;
	}
	const vector<float> &triboson_v1::jets_deepB()
	{
		if (not jets_deepB_isLoaded) {
			if (jets_deepB_branch != 0) {
				jets_deepB_branch->GetEntry(index);
			} else { 
				printf("branch jets_deepB_branch does not exist!\n");
				exit(1);
			}
			jets_deepB_isLoaded = true;
		}
		return *jets_deepB_;
	}
	const vector<float> &triboson_v1::jets_up_deepB()
	{
		if (not jets_up_deepB_isLoaded) {
			if (jets_up_deepB_branch != 0) {
				jets_up_deepB_branch->GetEntry(index);
			} else { 
				printf("branch jets_up_deepB_branch does not exist!\n");
				exit(1);
			}
			jets_up_deepB_isLoaded = true;
		}
		return *jets_up_deepB_;
	}
	const vector<float> &triboson_v1::jets_deepC()
	{
		if (not jets_deepC_isLoaded) {
			if (jets_deepC_branch != 0) {
				jets_deepC_branch->GetEntry(index);
			} else { 
				printf("branch jets_deepC_branch does not exist!\n");
				exit(1);
			}
			jets_deepC_isLoaded = true;
		}
		return *jets_deepC_;
	}
	const vector<float> &triboson_v1::jets_up_deepC()
	{
		if (not jets_up_deepC_isLoaded) {
			if (jets_up_deepC_branch != 0) {
				jets_up_deepC_branch->GetEntry(index);
			} else { 
				printf("branch jets_up_deepC_branch does not exist!\n");
				exit(1);
			}
			jets_up_deepC_isLoaded = true;
		}
		return *jets_up_deepC_;
	}
	const int &triboson_v1::njets_dn()
	{
		if (not njets_dn_isLoaded) {
			if (njets_dn_branch != 0) {
				njets_dn_branch->GetEntry(index);
			} else { 
				printf("branch njets_dn_branch does not exist!\n");
				exit(1);
			}
			njets_dn_isLoaded = true;
		}
		return njets_dn_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_dn_p4()
	{
		if (not jets_dn_p4_isLoaded) {
			if (jets_dn_p4_branch != 0) {
				jets_dn_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_dn_p4_branch does not exist!\n");
				exit(1);
			}
			jets_dn_p4_isLoaded = true;
		}
		return *jets_dn_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &triboson_v1::jets_medb_dn_p4()
	{
		if (not jets_medb_dn_p4_isLoaded) {
			if (jets_medb_dn_p4_branch != 0) {
				jets_medb_dn_p4_branch->GetEntry(index);
			} else { 
				printf("branch jets_medb_dn_p4_branch does not exist!\n");
				exit(1);
			}
			jets_medb_dn_p4_isLoaded = true;
		}
		return *jets_medb_dn_p4_;
	}
	const vector<float> &triboson_v1::jets_dn_csv()
	{
		if (not jets_dn_csv_isLoaded) {
			if (jets_dn_csv_branch != 0) {
				jets_dn_csv_branch->GetEntry(index);
			} else { 
				printf("branch jets_dn_csv_branch does not exist!\n");
				exit(1);
			}
			jets_dn_csv_isLoaded = true;
		}
		return *jets_dn_csv_;
	}
	const vector<float> &triboson_v1::jets_dn_deepB()
	{
		if (not jets_dn_deepB_isLoaded) {
			if (jets_dn_deepB_branch != 0) {
				jets_dn_deepB_branch->GetEntry(index);
			} else { 
				printf("branch jets_dn_deepB_branch does not exist!\n");
				exit(1);
			}
			jets_dn_deepB_isLoaded = true;
		}
		return *jets_dn_deepB_;
	}
	const vector<float> &triboson_v1::jets_dn_deepC()
	{
		if (not jets_dn_deepC_isLoaded) {
			if (jets_dn_deepC_branch != 0) {
				jets_dn_deepC_branch->GetEntry(index);
			} else { 
				printf("branch jets_dn_deepC_branch does not exist!\n");
				exit(1);
			}
			jets_dn_deepC_isLoaded = true;
		}
		return *jets_dn_deepC_;
	}
	const vector<float> &triboson_v1::jets_muf()
	{
		if (not jets_muf_isLoaded) {
			if (jets_muf_branch != 0) {
				jets_muf_branch->GetEntry(index);
			} else { 
				printf("branch jets_muf_branch does not exist!\n");
				exit(1);
			}
			jets_muf_isLoaded = true;
		}
		return *jets_muf_;
	}
	const vector<int> &triboson_v1::jets_mcFlavour()
	{
		if (not jets_mcFlavour_isLoaded) {
			if (jets_mcFlavour_branch != 0) {
				jets_mcFlavour_branch->GetEntry(index);
			} else { 
				printf("branch jets_mcFlavour_branch does not exist!\n");
				exit(1);
			}
			jets_mcFlavour_isLoaded = true;
		}
		return *jets_mcFlavour_;
	}
	const vector<int> &triboson_v1::jets_mcHadronFlav()
	{
		if (not jets_mcHadronFlav_isLoaded) {
			if (jets_mcHadronFlav_branch != 0) {
				jets_mcHadronFlav_branch->GetEntry(index);
			} else { 
				printf("branch jets_mcHadronFlav_branch does not exist!\n");
				exit(1);
			}
			jets_mcHadronFlav_isLoaded = true;
		}
		return *jets_mcHadronFlav_;
	}
	const float &triboson_v1::ht()
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
	const float &triboson_v1::ht_up()
	{
		if (not ht_up_isLoaded) {
			if (ht_up_branch != 0) {
				ht_up_branch->GetEntry(index);
			} else { 
				printf("branch ht_up_branch does not exist!\n");
				exit(1);
			}
			ht_up_isLoaded = true;
		}
		return ht_up_;
	}
	const float &triboson_v1::ht_dn()
	{
		if (not ht_dn_isLoaded) {
			if (ht_dn_branch != 0) {
				ht_dn_branch->GetEntry(index);
			} else { 
				printf("branch ht_dn_branch does not exist!\n");
				exit(1);
			}
			ht_dn_isLoaded = true;
		}
		return ht_dn_;
	}
	const float &triboson_v1::mt_lep1()
	{
		if (not mt_lep1_isLoaded) {
			if (mt_lep1_branch != 0) {
				mt_lep1_branch->GetEntry(index);
			} else { 
				printf("branch mt_lep1_branch does not exist!\n");
				exit(1);
			}
			mt_lep1_isLoaded = true;
		}
		return mt_lep1_;
	}
	const float &triboson_v1::mt_min()
	{
		if (not mt_min_isLoaded) {
			if (mt_min_branch != 0) {
				mt_min_branch->GetEntry(index);
			} else { 
				printf("branch mt_min_branch does not exist!\n");
				exit(1);
			}
			mt_min_isLoaded = true;
		}
		return mt_min_;
	}
	const float &triboson_v1::mt_max()
	{
		if (not mt_max_isLoaded) {
			if (mt_max_branch != 0) {
				mt_max_branch->GetEntry(index);
			} else { 
				printf("branch mt_max_branch does not exist!\n");
				exit(1);
			}
			mt_max_isLoaded = true;
		}
		return mt_max_;
	}
	const float &triboson_v1::weight_btagsf()
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
	const float &triboson_v1::weight_btagsf_heavy_UP()
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
	const float &triboson_v1::weight_btagsf_light_UP()
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
	const float &triboson_v1::weight_btagsf_heavy_DN()
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
	const float &triboson_v1::weight_btagsf_light_DN()
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
	const float &triboson_v1::met_T1CHS_pt()
	{
		if (not met_T1CHS_pt_isLoaded) {
			if (met_T1CHS_pt_branch != 0) {
				met_T1CHS_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_pt_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_pt_isLoaded = true;
		}
		return met_T1CHS_pt_;
	}
	const float &triboson_v1::met_T1CHS_phi()
	{
		if (not met_T1CHS_phi_isLoaded) {
			if (met_T1CHS_phi_branch != 0) {
				met_T1CHS_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_phi_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_phi_isLoaded = true;
		}
		return met_T1CHS_phi_;
	}
	const float &triboson_v1::met_T1CHS_fromCORE_pt()
	{
		if (not met_T1CHS_fromCORE_pt_isLoaded) {
			if (met_T1CHS_fromCORE_pt_branch != 0) {
				met_T1CHS_fromCORE_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_fromCORE_pt_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_fromCORE_pt_isLoaded = true;
		}
		return met_T1CHS_fromCORE_pt_;
	}
	const float &triboson_v1::met_T1CHS_fromCORE_phi()
	{
		if (not met_T1CHS_fromCORE_phi_isLoaded) {
			if (met_T1CHS_fromCORE_phi_branch != 0) {
				met_T1CHS_fromCORE_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_fromCORE_phi_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_fromCORE_phi_isLoaded = true;
		}
		return met_T1CHS_fromCORE_phi_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_pt()
	{
		if (not met_T1CHS_miniAOD_CORE_pt_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_pt_branch != 0) {
				met_T1CHS_miniAOD_CORE_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_pt_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_pt_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_pt_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_phi()
	{
		if (not met_T1CHS_miniAOD_CORE_phi_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_phi_branch != 0) {
				met_T1CHS_miniAOD_CORE_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_phi_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_phi_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_phi_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_up_pt()
	{
		if (not met_T1CHS_miniAOD_CORE_up_pt_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_up_pt_branch != 0) {
				met_T1CHS_miniAOD_CORE_up_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_up_pt_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_up_pt_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_up_pt_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_up_phi()
	{
		if (not met_T1CHS_miniAOD_CORE_up_phi_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_up_phi_branch != 0) {
				met_T1CHS_miniAOD_CORE_up_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_up_phi_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_up_phi_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_up_phi_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_dn_pt()
	{
		if (not met_T1CHS_miniAOD_CORE_dn_pt_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_dn_pt_branch != 0) {
				met_T1CHS_miniAOD_CORE_dn_pt_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_dn_pt_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_dn_pt_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_dn_pt_;
	}
	const float &triboson_v1::met_T1CHS_miniAOD_CORE_dn_phi()
	{
		if (not met_T1CHS_miniAOD_CORE_dn_phi_isLoaded) {
			if (met_T1CHS_miniAOD_CORE_dn_phi_branch != 0) {
				met_T1CHS_miniAOD_CORE_dn_phi_branch->GetEntry(index);
			} else { 
				printf("branch met_T1CHS_miniAOD_CORE_dn_phi_branch does not exist!\n");
				exit(1);
			}
			met_T1CHS_miniAOD_CORE_dn_phi_isLoaded = true;
		}
		return met_T1CHS_miniAOD_CORE_dn_phi_;
	}
	const int &triboson_v1::hyp_type()
	{
		if (not hyp_type_isLoaded) {
			if (hyp_type_branch != 0) {
				hyp_type_branch->GetEntry(index);
			} else { 
				printf("branch hyp_type_branch does not exist!\n");
				exit(1);
			}
			hyp_type_isLoaded = true;
		}
		return hyp_type_;
	}
	const int &triboson_v1::evt_type()
	{
		if (not evt_type_isLoaded) {
			if (evt_type_branch != 0) {
				evt_type_branch->GetEntry(index);
			} else { 
				printf("branch evt_type_branch does not exist!\n");
				exit(1);
			}
			evt_type_isLoaded = true;
		}
		return evt_type_;
	}
	const float &triboson_v1::isrboost()
	{
		if (not isrboost_isLoaded) {
			if (isrboost_branch != 0) {
				isrboost_branch->GetEntry(index);
			} else { 
				printf("branch isrboost_branch does not exist!\n");
				exit(1);
			}
			isrboost_isLoaded = true;
		}
		return isrboost_;
	}
	const int &triboson_v1::isr_njets()
	{
		if (not isr_njets_isLoaded) {
			if (isr_njets_branch != 0) {
				isr_njets_branch->GetEntry(index);
			} else { 
				printf("branch isr_njets_branch does not exist!\n");
				exit(1);
			}
			isr_njets_isLoaded = true;
		}
		return isr_njets_;
	}
	const float &triboson_v1::isr_weight()
	{
		if (not isr_weight_isLoaded) {
			if (isr_weight_branch != 0) {
				isr_weight_branch->GetEntry(index);
			} else { 
				printf("branch isr_weight_branch does not exist!\n");
				exit(1);
			}
			isr_weight_isLoaded = true;
		}
		return isr_weight_;
	}
	const float &triboson_v1::isr_unc()
	{
		if (not isr_unc_isLoaded) {
			if (isr_unc_branch != 0) {
				isr_unc_branch->GetEntry(index);
			} else { 
				printf("branch isr_unc_branch does not exist!\n");
				exit(1);
			}
			isr_unc_isLoaded = true;
		}
		return isr_unc_;
	}
	const vector<float> &triboson_v1::weightsf_lepid()
	{
		if (not weightsf_lepid_isLoaded) {
			if (weightsf_lepid_branch != 0) {
				weightsf_lepid_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepid_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepid_isLoaded = true;
		}
		return *weightsf_lepid_;
	}
	const vector<float> &triboson_v1::weightsf_lepiso()
	{
		if (not weightsf_lepiso_isLoaded) {
			if (weightsf_lepiso_branch != 0) {
				weightsf_lepiso_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepiso_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepiso_isLoaded = true;
		}
		return *weightsf_lepiso_;
	}
	const vector<float> &triboson_v1::weightsf_lepip()
	{
		if (not weightsf_lepip_isLoaded) {
			if (weightsf_lepip_branch != 0) {
				weightsf_lepip_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepip_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepip_isLoaded = true;
		}
		return *weightsf_lepip_;
	}
	const vector<float> &triboson_v1::weightsf_lepreco()
	{
		if (not weightsf_lepreco_isLoaded) {
			if (weightsf_lepreco_branch != 0) {
				weightsf_lepreco_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepreco_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepreco_isLoaded = true;
		}
		return *weightsf_lepreco_;
	}
	const vector<float> &triboson_v1::weightsf_lepconv()
	{
		if (not weightsf_lepconv_isLoaded) {
			if (weightsf_lepconv_branch != 0) {
				weightsf_lepconv_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepconv_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepconv_isLoaded = true;
		}
		return *weightsf_lepconv_;
	}
	const vector<float> &triboson_v1::weightsf_lepid_FS()
	{
		if (not weightsf_lepid_FS_isLoaded) {
			if (weightsf_lepid_FS_branch != 0) {
				weightsf_lepid_FS_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepid_FS_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepid_FS_isLoaded = true;
		}
		return *weightsf_lepid_FS_;
	}
	const vector<float> &triboson_v1::weightsf_lepiso_FS()
	{
		if (not weightsf_lepiso_FS_isLoaded) {
			if (weightsf_lepiso_FS_branch != 0) {
				weightsf_lepiso_FS_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepiso_FS_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepiso_FS_isLoaded = true;
		}
		return *weightsf_lepiso_FS_;
	}
	const vector<float> &triboson_v1::weightsf_lepip_FS()
	{
		if (not weightsf_lepip_FS_isLoaded) {
			if (weightsf_lepip_FS_branch != 0) {
				weightsf_lepip_FS_branch->GetEntry(index);
			} else { 
				printf("branch weightsf_lepip_FS_branch does not exist!\n");
				exit(1);
			}
			weightsf_lepip_FS_isLoaded = true;
		}
		return *weightsf_lepip_FS_;
	}

  void triboson_v1::progress( int nEventsTotal, int nEventsChain ){
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
  
namespace triboson_v1_np {
	const int &run() { return cms3.run(); }
	const int &lumi() { return cms3.lumi(); }
	const unsigned long long &evt() { return cms3.evt(); }
	const int &isData() { return cms3.isData(); }
	const bool &evt_passgoodrunlist() { return cms3.evt_passgoodrunlist(); }
	const float &evt_scale1fb() { return cms3.evt_scale1fb(); }
	const float &evt_xsec() { return cms3.evt_xsec(); }
	const float &evt_kfactor() { return cms3.evt_kfactor(); }
	const float &evt_filter() { return cms3.evt_filter(); }
	const int &evt_nEvts() { return cms3.evt_nEvts(); }
	const vector<TString> &evt_dataset() { return cms3.evt_dataset(); }
	const float &puWeight() { return cms3.puWeight(); }
	const int &nVert() { return cms3.nVert(); }
	const int &nTrueInt() { return cms3.nTrueInt(); }
	const float &rho() { return cms3.rho(); }
	const float &gen_ht() { return cms3.gen_ht(); }
	const int &nBJetTight() { return cms3.nBJetTight(); }
	const int &nBJetMedium() { return cms3.nBJetMedium(); }
	const int &nBJetLoose() { return cms3.nBJetLoose(); }
	const int &nBJetTight_up() { return cms3.nBJetTight_up(); }
	const int &nBJetMedium_up() { return cms3.nBJetMedium_up(); }
	const int &nBJetLoose_up() { return cms3.nBJetLoose_up(); }
	const int &nBJetTight_dn() { return cms3.nBJetTight_dn(); }
	const int &nBJetMedium_dn() { return cms3.nBJetMedium_dn(); }
	const int &nBJetLoose_dn() { return cms3.nBJetLoose_dn(); }
	const int &nJet200MuFrac50DphiMet() { return cms3.nJet200MuFrac50DphiMet(); }
	const int &nMuons10() { return cms3.nMuons10(); }
	const int &nBadMuons20() { return cms3.nBadMuons20(); }
	const int &nElectrons10() { return cms3.nElectrons10(); }
	const int &nGammas20() { return cms3.nGammas20(); }
	const int &nTaus20() { return cms3.nTaus20(); }
	const float &met_pt() { return cms3.met_pt(); }
	const float &met_phi() { return cms3.met_phi(); }
	const float &met_calo_pt() { return cms3.met_calo_pt(); }
	const float &met_calo_phi() { return cms3.met_calo_phi(); }
	const float &met_miniaod_pt() { return cms3.met_miniaod_pt(); }
	const float &met_miniaod_phi() { return cms3.met_miniaod_phi(); }
	const float &met_muegclean_pt() { return cms3.met_muegclean_pt(); }
	const float &met_muegclean_phi() { return cms3.met_muegclean_phi(); }
	const float &met_rawPt() { return cms3.met_rawPt(); }
	const float &met_rawPhi() { return cms3.met_rawPhi(); }
	const float &met_genPt() { return cms3.met_genPt(); }
	const float &met_genPhi() { return cms3.met_genPhi(); }
	const float &sumet_raw() { return cms3.sumet_raw(); }
	const int &Flag_ecalLaserCorrFilter() { return cms3.Flag_ecalLaserCorrFilter(); }
	const int &Flag_hcalLaserEventFilter() { return cms3.Flag_hcalLaserEventFilter(); }
	const int &Flag_trackingFailureFilter() { return cms3.Flag_trackingFailureFilter(); }
	const int &Flag_CSCTightHaloFilter() { return cms3.Flag_CSCTightHaloFilter(); }
	const int &Flag_HBHENoiseFilter() { return cms3.Flag_HBHENoiseFilter(); }
	const int &Flag_HBHEIsoNoiseFilter() { return cms3.Flag_HBHEIsoNoiseFilter(); }
	const int &Flag_CSCTightHalo2015Filter() { return cms3.Flag_CSCTightHalo2015Filter(); }
	const int &Flag_EcalDeadCellTriggerPrimitiveFilter() { return cms3.Flag_EcalDeadCellTriggerPrimitiveFilter(); }
	const int &Flag_goodVertices() { return cms3.Flag_goodVertices(); }
	const int &Flag_eeBadScFilter() { return cms3.Flag_eeBadScFilter(); }
	const int &Flag_globalTightHalo2016() { return cms3.Flag_globalTightHalo2016(); }
	const int &Flag_badMuonFilter() { return cms3.Flag_badMuonFilter(); }
	const int &Flag_badChargedCandidateFilter() { return cms3.Flag_badChargedCandidateFilter(); }
	const int &Flag_badMuonFilterv2() { return cms3.Flag_badMuonFilterv2(); }
	const int &Flag_badChargedCandidateFilterv2() { return cms3.Flag_badChargedCandidateFilterv2(); }
	const int &Flag_badMuons() { return cms3.Flag_badMuons(); }
	const int &Flag_duplicateMuons() { return cms3.Flag_duplicateMuons(); }
	const int &Flag_noBadMuons() { return cms3.Flag_noBadMuons(); }
	const int &HLT_singleEl() { return cms3.HLT_singleEl(); }
	const int &HLT_singleMu() { return cms3.HLT_singleMu(); }
	const int &HLT_singleMu_noiso() { return cms3.HLT_singleMu_noiso(); }
	const int &HLT_DoubleEl_noiso() { return cms3.HLT_DoubleEl_noiso(); }
	const int &HLT_DoubleEl() { return cms3.HLT_DoubleEl(); }
	const int &HLT_DoubleEl_DZ() { return cms3.HLT_DoubleEl_DZ(); }
	const int &HLT_DoubleEl_DZ_2() { return cms3.HLT_DoubleEl_DZ_2(); }
	const int &HLT_MuEG() { return cms3.HLT_MuEG(); }
	const int &HLT_MuEG_2() { return cms3.HLT_MuEG_2(); }
	const int &HLT_MuEG_noiso() { return cms3.HLT_MuEG_noiso(); }
	const int &HLT_MuEG_noiso_2() { return cms3.HLT_MuEG_noiso_2(); }
	const int &HLT_Mu8_EG17() { return cms3.HLT_Mu8_EG17(); }
	const int &HLT_Mu8_EG23() { return cms3.HLT_Mu8_EG23(); }
	const int &HLT_Mu8_EG23_DZ() { return cms3.HLT_Mu8_EG23_DZ(); }
	const int &HLT_Mu12_EG23_DZ() { return cms3.HLT_Mu12_EG23_DZ(); }
	const int &HLT_Mu17_EG12() { return cms3.HLT_Mu17_EG12(); }
	const int &HLT_Mu23_EG8() { return cms3.HLT_Mu23_EG8(); }
	const int &HLT_Mu23_EG8_DZ() { return cms3.HLT_Mu23_EG8_DZ(); }
	const int &HLT_Mu23_EG12() { return cms3.HLT_Mu23_EG12(); }
	const int &HLT_Mu23_EG12_DZ() { return cms3.HLT_Mu23_EG12_DZ(); }
	const int &HLT_DoubleMu_noiso() { return cms3.HLT_DoubleMu_noiso(); }
	const int &HLT_DoubleMu_noiso_27_8() { return cms3.HLT_DoubleMu_noiso_27_8(); }
	const int &HLT_DoubleMu_noiso_30_11() { return cms3.HLT_DoubleMu_noiso_30_11(); }
	const int &HLT_DoubleMu_noiso_40_11() { return cms3.HLT_DoubleMu_noiso_40_11(); }
	const int &HLT_DoubleMu() { return cms3.HLT_DoubleMu(); }
	const int &HLT_DoubleMu_tk() { return cms3.HLT_DoubleMu_tk(); }
	const int &HLT_DoubleMu_dbltk() { return cms3.HLT_DoubleMu_dbltk(); }
	const int &HLT_DoubleMu_nonDZ() { return cms3.HLT_DoubleMu_nonDZ(); }
	const int &HLT_DoubleMu_tk_nonDZ() { return cms3.HLT_DoubleMu_tk_nonDZ(); }
	const float &dilmass() { return cms3.dilmass(); }
	const float &dilpt() { return cms3.dilpt(); }
	const float &trilmass() { return cms3.trilmass(); }
	const float &reilpt() { return cms3.reilpt(); }
	const float &dRll() { return cms3.dRll(); }
	const float &matched_neutralemf() { return cms3.matched_neutralemf(); }
	const float &matched_emf() { return cms3.matched_emf(); }
	const bool &elveto() { return cms3.elveto(); }
	const int &nlep() { return cms3.nlep(); }
	const int &nveto_leptons() { return cms3.nveto_leptons(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &lep_p4() { return cms3.lep_p4(); }
	const vector<float> &lep_pt() { return cms3.lep_pt(); }
	const vector<float> &lep_eta() { return cms3.lep_eta(); }
	const vector<float> &lep_phi() { return cms3.lep_phi(); }
	const vector<float> &lep_mass() { return cms3.lep_mass(); }
	const vector<int> &lep_charge() { return cms3.lep_charge(); }
	const vector<int> &lep_threecharge() { return cms3.lep_threecharge(); }
	const vector<int> &lep_tightcharge() { return cms3.lep_tightcharge(); }
	const vector<int> &lep_pdgId() { return cms3.lep_pdgId(); }
	const vector<float> &lep_dxy() { return cms3.lep_dxy(); }
	const vector<float> &lep_ip3d() { return cms3.lep_ip3d(); }
	const vector<float> &lep_ip3derr() { return cms3.lep_ip3derr(); }
	const vector<float> &lep_etaSC() { return cms3.lep_etaSC(); }
	const vector<float> &lep_dz() { return cms3.lep_dz(); }
	const vector<float> &lep_dzerr() { return cms3.lep_dzerr(); }
	const vector<int> &lep_vetoId() { return cms3.lep_vetoId(); }
	const vector<int> &lep_looseId() { return cms3.lep_looseId(); }
	const vector<int> &lep_mediumId() { return cms3.lep_mediumId(); }
	const vector<int> &lep_tightId() { return cms3.lep_tightId(); }
	const vector<float> &lep_relIso03() { return cms3.lep_relIso03(); }
	const vector<float> &lep_relIso03EA() { return cms3.lep_relIso03EA(); }
	const vector<float> &lep_relIso03DB() { return cms3.lep_relIso03DB(); }
	const vector<float> &lep_relIso04() { return cms3.lep_relIso04(); }
	const vector<float> &lep_relIso04EA() { return cms3.lep_relIso04EA(); }
	const vector<float> &lep_relIso04DB() { return cms3.lep_relIso04DB(); }
	const vector<float> &lep_ptrel() { return cms3.lep_ptrel(); }
	const vector<float> &lep_ptratio() { return cms3.lep_ptratio(); }
	const vector<int> &lep_mcMatchId() { return cms3.lep_mcMatchId(); }
	const vector<int> &lep_lostHits() { return cms3.lep_lostHits(); }
	const vector<int> &lep_isfromW() { return cms3.lep_isfromW(); }
	const vector<int> &lep_isfromZ() { return cms3.lep_isfromZ(); }
	const vector<int> &lep_isfromH() { return cms3.lep_isfromH(); }
	const vector<int> &lep_isfromB() { return cms3.lep_isfromB(); }
	const vector<int> &lep_isfromC() { return cms3.lep_isfromC(); }
	const vector<int> &lep_isfromL() { return cms3.lep_isfromL(); }
	const vector<int> &lep_convVeto() { return cms3.lep_convVeto(); }
	const vector<float> &lep_MVA() { return cms3.lep_MVA(); }
	const vector<float> &lep_validfraction() { return cms3.lep_validfraction(); }
	const vector<float> &lep_pterr() { return cms3.lep_pterr(); }
	const vector<float> &lep_sta_pterrOpt() { return cms3.lep_sta_pterrOpt(); }
	const vector<float> &lep_glb_pterrOpt() { return cms3.lep_glb_pterrOpt(); }
	const vector<float> &lep_x2ondof() { return cms3.lep_x2ondof(); }
	const vector<float> &lep_sta_x2ondof() { return cms3.lep_sta_x2ondof(); }
	const vector<float> &lep_glb_x2ondof() { return cms3.lep_glb_x2ondof(); }
	const int &nisoTracks() { return cms3.nisoTracks(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &isotr_p4() { return cms3.isotr_p4(); }
	const vector<float> &isotr_relIso03() { return cms3.isotr_relIso03(); }
	const vector<float> &isotr_relIso04() { return cms3.isotr_relIso04(); }
	const vector<float> &isotr_ptrel() { return cms3.isotr_ptrel(); }
	const vector<float> &isotr_ptratio() { return cms3.isotr_ptratio(); }
	const vector<int> &isotr_charge() { return cms3.isotr_charge(); }
	const vector<int> &isotr_pdgId() { return cms3.isotr_pdgId(); }
	const vector<float> &isotr_dz() { return cms3.isotr_dz(); }
	const int &nisoTrack_5gev() { return cms3.nisoTrack_5gev(); }
	const int &nisoTrack_mt2() { return cms3.nisoTrack_mt2(); }
	const int &nisoTrack_PFLep5_woverlaps() { return cms3.nisoTrack_PFLep5_woverlaps(); }
	const int &nisoTrack_PFHad10_woverlaps() { return cms3.nisoTrack_PFHad10_woverlaps(); }
	const int &ngamma() { return cms3.ngamma(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gamma_p4() { return cms3.gamma_p4(); }
	const vector<int> &gamma_mcMatchId() { return cms3.gamma_mcMatchId(); }
	const vector<float> &gamma_genPt() { return cms3.gamma_genPt(); }
	const vector<float> &gamma_genIso() { return cms3.gamma_genIso(); }
	const vector<float> &gamma_chHadIso() { return cms3.gamma_chHadIso(); }
	const vector<float> &gamma_neuHadIso() { return cms3.gamma_neuHadIso(); }
	const vector<float> &gamma_phIso() { return cms3.gamma_phIso(); }
	const vector<int> &gamma_idCutBased() { return cms3.gamma_idCutBased(); }
	const vector<float> &gamma_drMinParton() { return cms3.gamma_drMinParton(); }
	const int &ngenPart() { return cms3.ngenPart(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genPart_p4() { return cms3.genPart_p4(); }
	const vector<float> &genPart_pt() { return cms3.genPart_pt(); }
	const vector<float> &genPart_eta() { return cms3.genPart_eta(); }
	const vector<float> &genPart_phi() { return cms3.genPart_phi(); }
	const vector<float> &genPart_mass() { return cms3.genPart_mass(); }
	const vector<int> &genPart_pdgId() { return cms3.genPart_pdgId(); }
	const vector<int> &genPart_status() { return cms3.genPart_status(); }
	const vector<float> &genPart_charge() { return cms3.genPart_charge(); }
	const vector<int> &genPart_motherId() { return cms3.genPart_motherId(); }
	const vector<int> &genPart_grandmaId() { return cms3.genPart_grandmaId(); }
	const vector<bool> &genPart_isp6status3() { return cms3.genPart_isp6status3(); }
	const int &njets() { return cms3.njets(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4() { return cms3.jets_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &removed_jets_p4() { return cms3.removed_jets_p4(); }
	const vector<float> &removed_jets_csv() { return cms3.removed_jets_csv(); }
	const vector<float> &removed_jets_deepB() { return cms3.removed_jets_deepB(); }
	const vector<float> &removed_jets_deepC() { return cms3.removed_jets_deepC(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_medb_p4() { return cms3.jets_medb_p4(); }
	const int &njets_up() { return cms3.njets_up(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_up_p4() { return cms3.jets_up_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_medb_up_p4() { return cms3.jets_medb_up_p4(); }
	const vector<float> &jets_csv() { return cms3.jets_csv(); }
	const vector<float> &jets_up_csv() { return cms3.jets_up_csv(); }
	const vector<float> &jets_deepB() { return cms3.jets_deepB(); }
	const vector<float> &jets_up_deepB() { return cms3.jets_up_deepB(); }
	const vector<float> &jets_deepC() { return cms3.jets_deepC(); }
	const vector<float> &jets_up_deepC() { return cms3.jets_up_deepC(); }
	const int &njets_dn() { return cms3.njets_dn(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_dn_p4() { return cms3.jets_dn_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_medb_dn_p4() { return cms3.jets_medb_dn_p4(); }
	const vector<float> &jets_dn_csv() { return cms3.jets_dn_csv(); }
	const vector<float> &jets_dn_deepB() { return cms3.jets_dn_deepB(); }
	const vector<float> &jets_dn_deepC() { return cms3.jets_dn_deepC(); }
	const vector<float> &jets_muf() { return cms3.jets_muf(); }
	const vector<int> &jets_mcFlavour() { return cms3.jets_mcFlavour(); }
	const vector<int> &jets_mcHadronFlav() { return cms3.jets_mcHadronFlav(); }
	const float &ht() { return cms3.ht(); }
	const float &ht_up() { return cms3.ht_up(); }
	const float &ht_dn() { return cms3.ht_dn(); }
	const float &mt_lep1() { return cms3.mt_lep1(); }
	const float &mt_min() { return cms3.mt_min(); }
	const float &mt_max() { return cms3.mt_max(); }
	const float &weight_btagsf() { return cms3.weight_btagsf(); }
	const float &weight_btagsf_heavy_UP() { return cms3.weight_btagsf_heavy_UP(); }
	const float &weight_btagsf_light_UP() { return cms3.weight_btagsf_light_UP(); }
	const float &weight_btagsf_heavy_DN() { return cms3.weight_btagsf_heavy_DN(); }
	const float &weight_btagsf_light_DN() { return cms3.weight_btagsf_light_DN(); }
	const float &met_T1CHS_pt() { return cms3.met_T1CHS_pt(); }
	const float &met_T1CHS_phi() { return cms3.met_T1CHS_phi(); }
	const float &met_T1CHS_fromCORE_pt() { return cms3.met_T1CHS_fromCORE_pt(); }
	const float &met_T1CHS_fromCORE_phi() { return cms3.met_T1CHS_fromCORE_phi(); }
	const float &met_T1CHS_miniAOD_CORE_pt() { return cms3.met_T1CHS_miniAOD_CORE_pt(); }
	const float &met_T1CHS_miniAOD_CORE_phi() { return cms3.met_T1CHS_miniAOD_CORE_phi(); }
	const float &met_T1CHS_miniAOD_CORE_up_pt() { return cms3.met_T1CHS_miniAOD_CORE_up_pt(); }
	const float &met_T1CHS_miniAOD_CORE_up_phi() { return cms3.met_T1CHS_miniAOD_CORE_up_phi(); }
	const float &met_T1CHS_miniAOD_CORE_dn_pt() { return cms3.met_T1CHS_miniAOD_CORE_dn_pt(); }
	const float &met_T1CHS_miniAOD_CORE_dn_phi() { return cms3.met_T1CHS_miniAOD_CORE_dn_phi(); }
	const int &hyp_type() { return cms3.hyp_type(); }
	const int &evt_type() { return cms3.evt_type(); }
	const float &isrboost() { return cms3.isrboost(); }
	const int &isr_njets() { return cms3.isr_njets(); }
	const float &isr_weight() { return cms3.isr_weight(); }
	const float &isr_unc() { return cms3.isr_unc(); }
	const vector<float> &weightsf_lepid() { return cms3.weightsf_lepid(); }
	const vector<float> &weightsf_lepiso() { return cms3.weightsf_lepiso(); }
	const vector<float> &weightsf_lepip() { return cms3.weightsf_lepip(); }
	const vector<float> &weightsf_lepreco() { return cms3.weightsf_lepreco(); }
	const vector<float> &weightsf_lepconv() { return cms3.weightsf_lepconv(); }
	const vector<float> &weightsf_lepid_FS() { return cms3.weightsf_lepid_FS(); }
	const vector<float> &weightsf_lepiso_FS() { return cms3.weightsf_lepiso_FS(); }
	const vector<float> &weightsf_lepip_FS() { return cms3.weightsf_lepip_FS(); }
}
