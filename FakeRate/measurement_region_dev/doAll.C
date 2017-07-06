{

  // Load libraries and macros
  gROOT->ProcessLine(".L ../../commonUtils/commonUtils.h");
  gROOT->ProcessLine(".L vtx_reweight.h");
  gSystem->Load("../../CORE/CMS3_CORE.so");
//  gSystem->Load("../../triboson_loopers/libSharedCode.so");
  gROOT->ProcessLine(".L ./../../sharedCode/histTools.cc+");
  gROOT->ProcessLine(".L ScanChain.C+");
  // Get tag name
  TString tag                   = "v4.0";
  TString input_dir_parent_path = "/nfs-7/userdata/phchang/lepton_babies";
  TString lepton_baby_path      = input_dir_parent_path + "/" + tag;

  // DO NOT CHANGE. Some legacy involved. But this is the "magic" option we shoud keep.
  //TString option = "useLooseEMVA,IsoTrigs,doLightonly";
  //TString fileoption = "_doLightonly";
  TString option = "useLooseEMVA,IsoTrigs";
  TString fileoption = "";
  // Run ScanChain for each
//	  TChain *data   = new TChain("t"); data   -> Add(lepton_baby_path + "/2016Single*.root"     ); ScanChain(data   , "./rate_histos_data.root"   , myAnalysisID , option);
  //TChain *data   = new TChain("t"); data   -> Add(lepton_baby_path + "/2016SingleMu*.root"     ); ScanChain(data   , "./rate_histos_data.root"   , myAnalysisID , option);
//	  TChain *dy     = new TChain("t"); dy     -> Add(lepton_baby_path + "/DY_madgraph*.root"    ); ScanChain(dy     , "./rate_histos_dy.root"     , myAnalysisID , option);
//	  TChain *wj     = new TChain("t"); wj     -> Add(lepton_baby_path + "/WJets_madgraph*.root" ); ScanChain(wj     , "./rate_histos_wj.root"     , myAnalysisID , option);
	  TChain *qcd_el = new TChain("t"); qcd_el -> Add(lepton_baby_path + "/QCD_EM_Enriched*.root"); ScanChain(qcd_el , "./rate_histos_qcd_el"+fileoption+".root" , myAnalysisID , option);
	  TChain *qcd_mu = new TChain("t"); qcd_mu -> Add(lepton_baby_path + "/QCD_Mu_Enriched*.root"); ScanChain(qcd_mu , "./rate_histos_qcd_mu"+fileoption+".root" , myAnalysisID , option);

}
