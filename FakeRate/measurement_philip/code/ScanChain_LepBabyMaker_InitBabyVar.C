// Event-wide variable
event = -999;
lumiBlock = -999;
run = -999;
evt_corrMET = -999;
evt_corrMETPhi = -999;
scale1fb = -999;     
ht = -999;  
nlep_VVV_cutbased_fo = -999;
nvtx = -999;
// Jets
jets.clear();
jets_disc.clear(); 
jets_area.clear(); 
jets_undoJEC.clear(); 
// Lepton
p4.SetXYZT(0, 0, 0, 0);
dilep_p4.SetXYZT(0, 0, 0, 0);
idx = -999;
// pdgIds
id = -999;
motherID = -999;
mc_id = -999;
// IPs
dxyPV = -999;
dZ = -999;
dxyPV_err = -999;
ip3d = -999;
ip3derr = -999;
// Isos
RelIso03 = -999; //RelIso03 (not corrected)
RelIso03EA = -999; //RelIso03 (EffectiveArea corrected)
RelIso03DB = -999; //RelIso03 (DeltaBeta corrected)
tkIso = -999;
miniiso = -999;
miniisoDB = -999;
// IDs
passes_VVV_cutbased_veto = -999;
passes_VVV_cutbased_veto_noiso = -999;
passes_VVV_cutbased_veto_noiso_noip = -999;
passes_VVV_cutbased_fo = -999;
passes_VVV_cutbased_fo_noiso = -999;
passes_VVV_cutbased_tight = -999;
passes_VVV_cutbased_tight_noiso = -999;
passes_VVV_MVAbased_tight = -999;
passes_VVV_MVAbased_tight_noiso = -999;
passes_VVV_baseline = -999;
// Auxiliary variables
dilep_mass = -999;
// Electron related
sigmaIEtaIEta_full5x5 = -999;
etaSC = -999;
dEtaIn = -999;
dPhiIn = -999;
hOverE = -999;
ecalEnergy = -999;
eOverPIn = -999;
conv_vtx_flag = -999;
charge = -999;
mva_25ns = -999;
tag_mva_25ns = -999;
ecalPFClusterIso = -999;
hcalPFClusterIso = -999;
// Triggers
HLT_Mu8 = -999;
HLT_Mu17 = -999;
HLT_Mu8_TrkIsoVVL = -999;
HLT_Mu17_TrkIsoVVL = -999;
HLT_IsoMu24 = -999;
HLT_IsoTkMu24 = -999;
HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -999;
HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -999;
HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
