// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "Math/VectorUtil.h"
#include <unistd.h> //isatty

// lepfilter
#include "LeptonTree.cc"

#include "../../sharedCode/histTools.h"
#include "../../CORE/Tools/JetCorrector.cc"
#include "../../commonUtils/commonUtils.h"
#include "vtx_reweight.h"

using namespace std;
using namespace lepton_tree;

static const float BTAGWP = 0.5426;

#ifdef __MAKECINT__
#pragma link C++ class ROOT::Math::PxPyPzE4D<float>+;
#pragma link C++ class ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >+;
#endif






//=====================================================================================================
// The following function defines the ID being used to measure the fake rate.
// The function returns true, if the given lepton entry in the LeptonTree is good.
// The function returns false, if the given lepton entry in the LeptonTree is to be skipped.
// This function will be passed on to the ScanChain.C, which is our LeptonTree looper, as an argment.
// The doAll.C is where the ScanChain.C is called for each TTree and this function is passed.
// FIXME
// FIXME
// FIXME
// FIXME
bool myAnalysisID(bool& passId, bool& passFO)
{

  ///
  ///
  /// Define the ID you want to use here!
  ///
  ///

  passId = passes_VVV_cutbased_tight_noiso() && RelIso03EA() < 0.06;
  passFO = (abs(id()) == 13&& passes_VVV_cutbased_fo_noiso() && RelIso03EA() < 0.4) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2);
  //passFO = passes_SS_fo_v5();

  // We use isolated auxiliary single lepton trigger.
  // Modify the passFO for electrons for two things, (1) online HLT ID, and (2) online isolation.
  if (abs(id()) == 11)
  {
    // Apply the online HLT cuts for the electrons to be within the trigger ID.
    bool isEB = true;
    if ( fabs(etaSC())>1.479 ) isEB = false;
    float sIeIe = sigmaIEtaIEta_full5x5();
    float hoe = hOverE();
    float deta = fabs(dEtaIn());
    float dphi = fabs(dPhiIn());
    float invep = fabs(1./ecalEnergy() - 1./p4().P());
    float cut_sIeIe = isEB ? 0.011 : 0.031;
    float cut_hoe   = 0.08;
    float cut_deta  = 0.01;
    float cut_dphi  = isEB ? 0.04 : 0.08;
    float cut_invep = 0.01;
    bool passHltCuts = ( sIeIe<cut_sIeIe && hoe<cut_hoe && deta<cut_deta && dphi<cut_dphi && invep<cut_invep );
    // Since we use isolated auxiliary triggers to measure FR we apply the online isolation criteria as well.
    if (!passIsolatedFO(id(),etaSC(),mva_25ns(),p4().pt()))
      return false;
    float ePFIso = ecalPFClusterIso()/p4().pt();
    float hPFIso = hcalPFClusterIso()/p4().pt();
    float trkIso = tkIso()/p4().pt();
    float cut_ePFIso = 0.45;
    float cut_hPFIso = 0.25;
    float cut_trkIso = 0.2;
    passHltCuts = passHltCuts && ePFIso<cut_ePFIso && hPFIso<cut_hPFIso && trkIso<cut_trkIso;
    passFO = passHltCuts && passFO;
  }
  return true;

}
// FIXME
// FIXME
// FIXME
// FIXME
//==================================================================================================

float computePtRel(LorentzVector lepp4, LorentzVector jetp4, bool subtractLep) {
  if (jetp4.pt()==0) return 0.;
  if (subtractLep) jetp4-=lepp4;
  float dot = lepp4.Vect().Dot( jetp4.Vect() );
  float ptrel = lepp4.P2() - dot*dot/jetp4.P2();
  ptrel = ptrel>0 ? sqrt(ptrel) : 0.0;
  return ptrel;
}

float getPt(float pt, bool extrPtRel = false) {
  if(!extrPtRel && pt >= 70.) return 69.;
  if(extrPtRel && pt >= 150.) return 149.;
  if(pt < 10.)  return 11.;   //use this if lower FR histo bound is 10.
  return pt;
}

float getEta(float eta, float ht, bool extrPtRel = false) {
  if (extrPtRel) {
    if(ht >= 800) return 799;
    return ht;
  }
  if(fabs(eta) >= 2.4) return 2.3;
  return fabs(eta);
}

double calculateMt(const LorentzVector p4, double met, double met_phi){
  float phi1 = p4.Phi();
  float phi2 = met_phi;
  float Et1  = p4.Et();
  float Et2  = met;
  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

//	int ScanChain( TChain* chain, TString outfile, TString option="", bool fast = true, int nEvents = -1) {//, string skimFilePrefix = "test") {
int ScanChain( TChain* chain, TString outfile, std::function<bool(bool&, bool&)> passMyAnalysisID, TString option="", bool fast = true, int nEvents = -1) {//, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  //default is MultiIso no SIP

  bool useRelIso = false;
  if (option.Contains("useRelIso")) useRelIso = true;

  bool useLooseEMVA = false;
  if (option.Contains("useLooseEMVA")) useLooseEMVA = true;

  bool usePtRatioCor = false;
  if (option.Contains("usePtRatioCor")) usePtRatioCor = true;

  bool doBonly = false;
  if (option.Contains("doBonly")) doBonly = true;

  bool doConly = false;
  if (option.Contains("doConly")) doConly = true;

  bool doLightonly = false;
  if (option.Contains("doLightonly")) doLightonly = true;

  bool useIsoTrigs = false;
  if (option.Contains("IsoTrigs")) useIsoTrigs = true;

  float anyPt = false;

  bool doJEC = false;

  bool debug = false;

  bool applyDataVtxWeight = false;

  int nptbins = 4;
  int netabins = 3;
  float ptbins[5] = { 10., 30., 40., 50., 70.};
  float etabins_mu[4] = {0., 1.2, 2.1, 2.4};
  float etabins_el[4] = {0., 0.8, 1.479, 2.5};

  HLTEfficiency HLTEff("../../hlt/HLT_Efficiencies_7p65fb_2016.root");

  // int nptbins = 7;
  // int netabins = 3;
  // float ptbins[8] = {10., 12., 15., 20., 25., 35., 50., 70.};
  // float etabins_mu[4] = {0., 1.2, 2.1, 2.4};
  // float etabins_el[4] = {0., 0.8, 1.479, 2.5};

  // handmade "prescales" from normalizeToZPeak.C
  // 800/pb SFs from normalizeZpeak
  float e8i = 1767.61;
  float e17i = 84.5516;
  float e8 = 1767.61;
  float e17 = 85.1862;
  float m8i = 238.145;
  float m17i = 28.3003;
  float m8 = 496.07;
  float m17 = 13.1493;

  // For 36.8/fb json with reRECO
  e8i = 4208.14;
  e17i = 617.166;
  e8 = 4209.02;
  e17 = 568.98;
  m8i = 3716.07;
  m17i = 181.349;
  m8 = 7361.42;
  m17 = 139.899;

  if (false) {
    //this should be ok as long as there are less bins in the extrPtRel case
    ptbins[0] = 10.;
    ptbins[1] = 50.;
    ptbins[2] = 100.;
    ptbins[3] = 150.;
    nptbins = 3;
    etabins_mu[0] = 0.;
    etabins_mu[1] = 400.;
    etabins_mu[2] = 800.;
    etabins_el[0] = 0.;
    etabins_el[1] = 400.;
    etabins_el[2] = 800.;
    netabins = 2;
  }


  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  TH2D *Nt_histo_e = new TH2D("Nt_histo_e", "Nt vs Pt, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nt_histo_e->SetDirectory(rootdir);
  Nt_histo_e->Sumw2();

  TH2D *Nl_histo_e = new TH2D("Nl_histo_e", "Nl vs Pt, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nl_histo_e->SetDirectory(rootdir);
  Nl_histo_e->Sumw2();

  TH2D *Nt_histo_mu = new TH2D("Nt_histo_mu", "Nt vs Pt, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nt_histo_mu->SetDirectory(rootdir);
  Nt_histo_mu->Sumw2();

  TH2D *Nl_histo_mu = new TH2D("Nl_histo_mu", "Nl vs Pt, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nl_histo_mu->SetDirectory(rootdir);
  Nl_histo_mu->Sumw2();

  TH2D *Nl_cone_histo_e = new TH2D("Nl_cone_histo_e", "Nl vs Cone Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nl_cone_histo_e->SetDirectory(rootdir);
  Nl_cone_histo_e->Sumw2();

  TH2D *Nl_cone_histo_mu = new TH2D("Nl_cone_histo_mu", "Nl vs Cone Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nl_cone_histo_mu->SetDirectory(rootdir);
  Nl_cone_histo_mu->Sumw2();

  TH2D *Nt_jet_histo_e = new TH2D("Nt_jet_histo_e", "Nt vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nt_jet_histo_e->SetDirectory(rootdir);
  Nt_jet_histo_e->Sumw2();

  TH2D *Nt_jet_histo_mu = new TH2D("Nt_jet_histo_mu", "Nt vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nt_jet_histo_mu->SetDirectory(rootdir);
  Nt_jet_histo_mu->Sumw2();

  TH2D *Nl_jet_histo_e = new TH2D("Nl_jet_histo_e", "Nl vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nl_jet_histo_e->SetDirectory(rootdir);
  Nl_jet_histo_e->Sumw2();

  TH2D *Nl_jet_histo_mu = new TH2D("Nl_jet_histo_mu", "Nl vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nl_jet_histo_mu->SetDirectory(rootdir);
  Nl_jet_histo_mu->Sumw2();

  TH2D *Nt_jet_highpt_histo_e = new TH2D("Nt_jet_highpt_histo_e", "Nt vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nt_jet_highpt_histo_e->SetDirectory(rootdir);
  Nt_jet_highpt_histo_e->Sumw2();

  TH2D *Nt_jet_highpt_histo_mu = new TH2D("Nt_jet_highpt_histo_mu", "Nt vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nt_jet_highpt_histo_mu->SetDirectory(rootdir);
  Nt_jet_highpt_histo_mu->Sumw2();

  TH2D *Nl_jet_highpt_histo_e = new TH2D("Nl_jet_highpt_histo_e", "Nl vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nl_jet_highpt_histo_e->SetDirectory(rootdir);
  Nl_jet_highpt_histo_e->Sumw2();

  TH2D *Nl_jet_highpt_histo_mu = new TH2D("Nl_jet_highpt_histo_mu", "Nl vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nl_jet_highpt_histo_mu->SetDirectory(rootdir);
  Nl_jet_highpt_histo_mu->Sumw2();

  TH2D *Nt_jet_lowpt_histo_e = new TH2D("Nt_jet_lowpt_histo_e", "Nt vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nt_jet_lowpt_histo_e->SetDirectory(rootdir);
  Nt_jet_lowpt_histo_e->Sumw2();

  TH2D *Nt_jet_lowpt_histo_mu = new TH2D("Nt_jet_lowpt_histo_mu", "Nt vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nt_jet_lowpt_histo_mu->SetDirectory(rootdir);
  Nt_jet_lowpt_histo_mu->Sumw2();

  TH2D *Nl_jet_lowpt_histo_e = new TH2D("Nl_jet_lowpt_histo_e", "Nl vs Jet Energy, Eta (electrons)", nptbins,ptbins,netabins,etabins_el);
  Nl_jet_lowpt_histo_e->SetDirectory(rootdir);
  Nl_jet_lowpt_histo_e->Sumw2();

  TH2D *Nl_jet_lowpt_histo_mu = new TH2D("Nl_jet_lowpt_histo_mu", "Nl vs Jet Energy, Eta (muons)", nptbins,ptbins,netabins,etabins_mu);
  Nl_jet_lowpt_histo_mu->SetDirectory(rootdir);
  Nl_jet_lowpt_histo_mu->Sumw2();

  TH1F *NBs_BR_histo_e = new TH1F("NBs_BR_histo_e", "Number of FO's from B's vs Nbtags (els)", 5,0,5);
  NBs_BR_histo_e->SetDirectory(rootdir);
  NBs_BR_histo_e->Sumw2();

  TH1F *NBs_BR_histo_mu = new TH1F("NBs_BR_histo_mu", "Number of FO's from B's vs Nbtags (muons)", 5,0,5);
  NBs_BR_histo_mu->SetDirectory(rootdir);
  NBs_BR_histo_mu->Sumw2();

  TH1F *NnotBs_BR_histo_e = new TH1F("NnotBs_BR_histo_e", "Number of FO's NOT from B's vs Nbtags (els)", 5,0,5);
  NnotBs_BR_histo_e->SetDirectory(rootdir);
  NnotBs_BR_histo_e->Sumw2();

  TH1F *NnotBs_BR_histo_mu = new TH1F("NnotBs_BR_histo_mu", "Number of FO's NOT from B's vs Nbtags (muons)", 5,0,5);
  NnotBs_BR_histo_mu->SetDirectory(rootdir);
  NnotBs_BR_histo_mu->Sumw2();

  TH1F *RelIso_BR_histo_mu = new TH1F("RelIso_BR_histo_mu", "RelIso03 of muons ", 50,0,1);
  RelIso_BR_histo_mu->SetDirectory(rootdir);
  RelIso_BR_histo_mu->Sumw2();

  TH1F *RelIso_BR_histo_el = new TH1F("RelIso_BR_histo_el", "RelIso03 of electrons ", 50,0,1);
  RelIso_BR_histo_el->SetDirectory(rootdir);
  RelIso_BR_histo_el->Sumw2();

  TH2D *pTrelvsIso_histo_el = new TH2D("pTrelvsIso_histo_el", "pTrel vs Iso (Electrons)", 10, 0., 1., 15, 0., 30.);
  pTrelvsIso_histo_el->SetDirectory(rootdir);
  pTrelvsIso_histo_el->Sumw2();

  TH2D *pTrelvsIso_histo_mu = new TH2D("pTrelvsIso_histo_mu", "pTrel vs Iso (Muons)", 10, 0., 1., 15, 0., 30.);
  pTrelvsIso_histo_mu->SetDirectory(rootdir);
  pTrelvsIso_histo_mu->Sumw2();

  TH1D *pTrel_histo_el = new TH1D("pTrel_histo_el", "pTrel (Electrons)", 15, 0., 30.);
  pTrel_histo_el->SetDirectory(rootdir);
  pTrel_histo_el->Sumw2();

  TH1D *pTrel_histo_mu = new TH1D("pTrel_histo_mu", "pTrel (Muons)", 15, 0., 30.);
  pTrel_histo_mu->SetDirectory(rootdir);
  pTrel_histo_mu->Sumw2();

  TH1F *histo_ht = new TH1F("histo_ht", "HT", 20,0,1000);
  histo_ht->SetDirectory(rootdir);
  histo_ht->Sumw2();

  TH1F *histo_met = new TH1F("histo_met", "MET", 20,0,1000);
  histo_met->SetDirectory(rootdir);
  histo_met->Sumw2();

  TH1F *histo_met_all = new TH1F("histo_met_all", "MET", 20,0,200);
  histo_met_all->SetDirectory(rootdir);
  histo_met_all->Sumw2();

  TH1F *histo_met_all_el = new TH1F("histo_met_all_el", "MET", 20,0,200);
  histo_met_all_el->SetDirectory(rootdir);
  histo_met_all_el->Sumw2();

  TH1F *histo_met_all_mu = new TH1F("histo_met_all_mu", "MET", 20,0,200);
  histo_met_all_mu->SetDirectory(rootdir);
  histo_met_all_mu->Sumw2();

  TH1F *histo_met_lm = new TH1F("histo_met_lm", "MET", 20,0,200);
  histo_met_lm->SetDirectory(rootdir);
  histo_met_lm->Sumw2();

  TH1F *histo_met_lm_el = new TH1F("histo_met_lm_el", "MET", 20,0,200);
  histo_met_lm_el->SetDirectory(rootdir);
  histo_met_lm_el->Sumw2();

  TH1F *histo_met_lm_mu = new TH1F("histo_met_lm_mu", "MET", 20,0,200);
  histo_met_lm_mu->SetDirectory(rootdir);
  histo_met_lm_mu->Sumw2();

  TH1F *histo_met_cr = new TH1F("histo_met_cr", "MET", 20,0,200);
  histo_met_cr->SetDirectory(rootdir);
  histo_met_cr->Sumw2();

  TH1F *histo_met_cr_el = new TH1F("histo_met_cr_el", "MET", 20,0,200);
  histo_met_cr_el->SetDirectory(rootdir);
  histo_met_cr_el->Sumw2();

  TH1F *histo_met_cr_mu = new TH1F("histo_met_cr_mu", "MET", 20,0,200);
  histo_met_cr_mu->SetDirectory(rootdir);
  histo_met_cr_mu->Sumw2();

  TH1F *histo_mt = new TH1F("histo_mt", "MT", 20,0,1000);
  histo_mt->SetDirectory(rootdir);
  histo_mt->Sumw2();

  TH1F *histo_mt_all = new TH1F("histo_mt_all", "MT", 20,0,200);
  histo_mt_all->SetDirectory(rootdir);
  histo_mt_all->Sumw2();

  TH1F *histo_mt_all_el = new TH1F("histo_mt_all_el", "MT", 20,0,200);
  histo_mt_all_el->SetDirectory(rootdir);
  histo_mt_all_el->Sumw2();

  TH1F *histo_mt_all_mu = new TH1F("histo_mt_all_mu", "MT", 20,0,200);
  histo_mt_all_mu->SetDirectory(rootdir);
  histo_mt_all_mu->Sumw2();

  TH1F *histo_mt_lm = new TH1F("histo_mt_lm", "MT", 20,0,200);
  histo_mt_lm->SetDirectory(rootdir);
  histo_mt_lm->Sumw2();

  TH1F *histo_mt_lm_el = new TH1F("histo_mt_lm_el", "MT", 20,0,200);
  histo_mt_lm_el->SetDirectory(rootdir);
  histo_mt_lm_el->Sumw2();

  TH1F *histo_mt_lm_mu = new TH1F("histo_mt_lm_mu", "MT", 20,0,200);
  histo_mt_lm_mu->SetDirectory(rootdir);
  histo_mt_lm_mu->Sumw2();

  TH1F *histo_mt_cr = new TH1F("histo_mt_cr", "MT", 20,0,200);
  histo_mt_cr->SetDirectory(rootdir);
  histo_mt_cr->Sumw2();

  TH1F *histo_mt_cr_el = new TH1F("histo_mt_cr_el", "MT", 20,0,200);
  histo_mt_cr_el->SetDirectory(rootdir);
  histo_mt_cr_el->Sumw2();

  TH1F *histo_mt_cr_mu = new TH1F("histo_mt_cr_mu", "MT", 20,0,200);
  histo_mt_cr_mu->SetDirectory(rootdir);
  histo_mt_cr_mu->Sumw2();

  TH1F *histo_pt_mu = new TH1F("histo_pt_mu", "pt mu", 100,0,200);
  histo_pt_mu->SetDirectory(rootdir);
  histo_pt_mu->Sumw2();

  TH1F *histo_pt_mu8 = new TH1F("histo_pt_mu8", "pt mu8", 100,0,200);
  histo_pt_mu8->SetDirectory(rootdir);
  histo_pt_mu8->Sumw2();

  TH1F *histo_pt_mu17 = new TH1F("histo_pt_mu17", "pt mu17", 100,0,200);
  histo_pt_mu17->SetDirectory(rootdir);
  histo_pt_mu17->Sumw2();

  TH1F *histo_pt_mu24 = new TH1F("histo_pt_mu24", "pt mu24", 100,0,200);
  histo_pt_mu24->SetDirectory(rootdir);
  histo_pt_mu24->Sumw2();

  TH1F *histo_pt_mu34 = new TH1F("histo_pt_mu34", "pt mu34", 100,0,200);
  histo_pt_mu34->SetDirectory(rootdir);
  histo_pt_mu34->Sumw2();

  TH1F *histo_pt_el = new TH1F("histo_pt_el", "pt el", 100,0,200);
  histo_pt_el->SetDirectory(rootdir);
  histo_pt_el->Sumw2();

  TH1F *histo_pt_el8 = new TH1F("histo_pt_el8", "pt el8", 100,0,200);
  histo_pt_el8->SetDirectory(rootdir);
  histo_pt_el8->Sumw2();

  TH1F *histo_pt_el12 = new TH1F("histo_pt_el12", "pt el12", 100,0,200);
  histo_pt_el12->SetDirectory(rootdir);
  histo_pt_el12->Sumw2();

  TH1F *histo_pt_el17 = new TH1F("histo_pt_el17", "pt el17", 100,0,200);
  histo_pt_el17->SetDirectory(rootdir);
  histo_pt_el17->Sumw2();

  TH1F *histo_pt_el24 = new TH1F("histo_pt_el24", "pt el24", 100,0,200);
  histo_pt_el24->SetDirectory(rootdir);
  histo_pt_el24->Sumw2();

  TH1F *histo_pt_el34 = new TH1F("histo_pt_el34", "pt el34", 100,0,200);
  histo_pt_el34->SetDirectory(rootdir);
  histo_pt_el34->Sumw2();

  TH1F *njets30_histo = new TH1F("njets30_histo", "Njets with pT > 40 GeV", 5,0,5);
  njets30_histo->SetDirectory(rootdir);
  njets30_histo->Sumw2();

  // NJA
  TH1D *Nt_nvtx_histo_e = new TH1D("Nt_nvtx_histo_e", "", 20, 0, 40);
  Nt_nvtx_histo_e->SetDirectory(rootdir);
  Nt_nvtx_histo_e->Sumw2();

  TH1D *Nt_nvtx_histo_mu = new TH1D("Nt_nvtx_histo_mu", "", 20, 0, 40);
  Nt_nvtx_histo_mu->SetDirectory(rootdir);
  Nt_nvtx_histo_mu->Sumw2();

  TH1D *Nl_cone_nvtx_histo_e = new TH1D("Nl_cone_nvtx_histo_e", "", 20, 0, 40);
  Nl_cone_nvtx_histo_e->SetDirectory(rootdir);
  Nl_cone_nvtx_histo_e->Sumw2();

  TH1D *Nl_cone_nvtx_histo_mu = new TH1D("Nl_cone_nvtx_histo_mu", "", 20, 0, 40);
  Nl_cone_nvtx_histo_mu->SetDirectory(rootdir);
  Nl_cone_nvtx_histo_mu->Sumw2();
  //----------------------

  //e determination
  float Nt = 0.;  //# of tight leptons
  float Nl = 0.;  //# of loose leptons
  float e = 0.;   //rate = Nt/(Nl)
  float Nt_e = 0.;
  float Nl_e = 0.;
  float e_e = 0.;
  float Nt_mu = 0.;
  float Nl_mu = 0.;
  float e_mu = 0.;
  //----------------
  float Bs_e = 0.;
  float notBs_e = 0.;
  float Bs_mu = 0.;
  float notBs_mu = 0.;

  //-------- JEC application


  //JEC files -- 25 ns MC
  std::vector<std::string> jetcorr_filenames_25ns_MC_pfL1;
  std::vector<std::string> jetcorr_filenames_25ns_MC_pfL1L2L3;
  jetcorr_filenames_25ns_MC_pfL1.push_back      ("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV2_MC_L1FastJet_AK4PFchs.txt");
  jetcorr_filenames_25ns_MC_pfL1L2L3.push_back  ("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV2_MC_L1FastJet_AK4PFchs.txt");
  jetcorr_filenames_25ns_MC_pfL1L2L3.push_back  ("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV2_MC_L2Relative_AK4PFchs.txt");
  jetcorr_filenames_25ns_MC_pfL1L2L3.push_back  ("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV2_MC_L3Absolute_AK4PFchs.txt");

  //JEC files -- 25 ns DATA
  std::vector<std::string> jetcorr_filenames_25ns_DATA_pfL1;
  std::vector<std::string> jetcorr_filenames_25ns_DATA_pfL1L2L3;
  jetcorr_filenames_25ns_DATA_pfL1.push_back    ("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV5_DATA_L1FastJet_AK4PFchs.txt");
  jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV5_DATA_L1FastJet_AK4PFchs.txt");
  jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV5_DATA_L2Relative_AK4PFchs.txt");
  jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV5_DATA_L3Absolute_AK4PFchs.txt");
  jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back("../../CORE/Tools/jetcorr/data/run2_25ns/Summer15_25nsV5_DATA_L2L3Residual_AK4PFchs.txt");

  FactorizedJetCorrector *jet_corrector_25ns_MC_pfL1;
  FactorizedJetCorrector *jet_corrector_25ns_MC_pfL1L2L3;
  FactorizedJetCorrector *jet_corrector_25ns_DATA_pfL1;
  FactorizedJetCorrector *jet_corrector_25ns_DATA_pfL1L2L3;

  //Fill the JEC
  jet_corrector_25ns_MC_pfL1 = makeJetCorrector(jetcorr_filenames_25ns_MC_pfL1);
  jet_corrector_25ns_MC_pfL1L2L3 = makeJetCorrector(jetcorr_filenames_25ns_MC_pfL1L2L3);
  jet_corrector_25ns_DATA_pfL1 = makeJetCorrector(jetcorr_filenames_25ns_DATA_pfL1);
  jet_corrector_25ns_DATA_pfL1L2L3 = makeJetCorrector(jetcorr_filenames_25ns_DATA_pfL1L2L3);

  //JECs
  FactorizedJetCorrector *jet_corrector_pfL1 = 0;
  FactorizedJetCorrector *jet_corrector_pfL1MC = 0;
  FactorizedJetCorrector *jet_corrector_pfL1L2L3 = 0;

  //Record filenames
  std::vector <string> jetcorr_filenames_pfL1L2L3;


  //-------- JEC application

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    
    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("t");
    if(fast) TTreeCache::SetLearnEntries(10);
    if(fast) tree->SetCacheSize(128*1024*1024);
    lepton_tree_obj.Init(tree);

    bool isSyncFile = TString(currentFile->GetTitle()).Contains("Sync");
    // Apply JEC
    bool isDataFromFileName = TString(currentFile->GetTitle()).Contains("2015C") || TString(currentFile->GetTitle()).Contains("2015D") ||
      TString(currentFile->GetTitle()).Contains("DoubleMu") || TString(currentFile->GetTitle()).Contains("DoubleEG");
    bool isDoubleMuon = TString(currentFile->GetTitle()).Contains("DoubleMu");
    bool isQCD = TString(currentFile->GetTitle()).Contains("QCD");
    bool isQCDMu = TString(currentFile->GetTitle()).Contains("QCD_Mu");
    bool isQCDEl = TString(currentFile->GetTitle()).Contains("QCD_El");
    bool isTTbar = TString(currentFile->GetTitle()).Contains("TTbar");

    bool doTrig = isQCD;


    if (isDataFromFileName){
      jet_corrector_pfL1 = jet_corrector_25ns_DATA_pfL1;
      jet_corrector_pfL1MC = jet_corrector_25ns_MC_pfL1;
      jet_corrector_pfL1L2L3 = jet_corrector_25ns_DATA_pfL1L2L3;
      jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_25ns_DATA_pfL1L2L3;
    } else {
      jet_corrector_pfL1 = jet_corrector_25ns_MC_pfL1;
      jet_corrector_pfL1MC = jet_corrector_25ns_MC_pfL1;
      jet_corrector_pfL1L2L3 = jet_corrector_25ns_MC_pfL1L2L3;
      jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_25ns_MC_pfL1L2L3;
    }

    cout << " => File: " << TString(currentFile->GetTitle()) << endl;

    if(doJEC) {
      cout << "applying JEC from the following files:" << endl;
      for (unsigned int ifile = 0; ifile < jetcorr_filenames_pfL1L2L3.size(); ++ifile) {
        cout << (isDataFromFileName ? "DATA: " : "MC: ") << jetcorr_filenames_pfL1L2L3.at(ifile) << endl;
      }
    }

    // Loop over Events in current file   //ACTUALLY A LEPTON "EVENT" LOOP
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
//	    for( unsigned int event = 0; event < 1000; ++event) {

      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      lepton_tree_obj.GetEntry(event);
      ++nEventsTotal;

      // Progress
      LeptonTree::progress( nEventsTotal, nEventsChain );

//	      if (debug && evt_event()!=701238056) continue;
      if (debug) cout << "event=" << evt_event() << " run=" << evt_run() << endl;

      //cout << "pt=" << p4().pt() << " iso=" << RelIso03EA() << endl;
      if (debug) cout << "lepp4=" << p4() << " pt=" << p4().pt() << " eta=" << p4().eta() << " phi=" << p4().phi() << " jetp4=" << jet_close_lep() << endl;

      if (isTTbar) {
        if (motherID() > 0) continue;
      }

      vector<LorentzVector> jets_recorr;
      for(unsigned int i=0; i<jets().size(); i++)  {
        float jetcorrection = 1.0;
        float jetarea = jets_area().at(i);
        float undoJEC = jets_undoJEC().at(i);
        if (debug) {
          cout << "event has jet with pt,eta,phi: " << jets()[i].pt() << "," << jets()[i].eta() << "," << jets()[i].phi() << endl;
        }

        if(doJEC) {
          if (jetcorr_filenames_pfL1L2L3.size()>0) {
            jet_corrector_pfL1->setJetEta(jets()[i].eta());
            jet_corrector_pfL1->setJetPt(jets()[i].pt());
            jet_corrector_pfL1->setJetA(jetarea);
            jet_corrector_pfL1->setRho(rho());
            jetcorrection = jet_corrector_pfL1->getCorrection();
          }
          if(undoJEC > 0) jetcorrection /= undoJEC; // if we have undoJEC from miniAOD->CMS3, divide it out
        }

        jets_recorr.push_back(jets()[i]*jetcorrection); // add our own JEC
      }


      LorentzVector jet_close_lep_p4 = jet_close_lep();
      if(doJEC && jet_close_lep_idx() >= 0 && jetcorr_filenames_pfL1L2L3.size()>0) {
        jet_corrector_pfL1->setJetEta(jet_close_lep().eta());
        jet_corrector_pfL1->setJetPt(jet_close_lep().pt());
        jet_corrector_pfL1->setJetA(jet_close_lep_area());
        jet_corrector_pfL1->setRho(rho());

        jet_close_lep_p4 /= jet_close_lep_undoJEC(); // undoJEC from miniAOD->CMS3
        jet_close_lep_p4 *= jet_corrector_pfL1->getCorrection();
      }


      bool isEWK = false;
      if (TString(currentFile->GetTitle()).Contains("WJets") || TString(currentFile->GetTitle()).Contains("DY")) isEWK = true;

      bool isData = evt_isRealData();
      bool noMCMatch = false;
      if (isData || isEWK) noMCMatch = true;

      //reject electrons from DoubleMu and muons from DoubleEG
      if (debug) cout << "check dataset" << endl;
      if (isData) {
        if ( isDoubleMuon && abs(id())!=13) continue;
        if (!isDoubleMuon && abs(id())!=11) continue;
      }

      // Analysis Code
      float lumi = getLumi();//in /fb
      // float lumi = 12.9-6.26;//in /fb // HALF
      // if(isData && evt_run() <= 275782) continue;
      float puw = getTruePUw_Moriond(nvtx());
      // float puw = 1.0;
      float weight = scale1fb()*lumi*puw;

      if (!isData) {
        // weight *= HLTEff.getEfficiency(ss::lep1_p4().pt(),ss::lep1_p4().eta(), ss::lep1_id(), ss::lep2_p4().pt(), ss::lep2_p4().eta(), ss::lep2_id(), ss::ht(), 0);
      }

      if (isData) weight = 1.;

      if (isData==0 && isEWK==0) {
        if (abs(id())==13) {
          if (debug) cout << "check qcd" << endl;

          bool nonEnriched = false;

          if (nonEnriched) {
            // throw away el pt_uncorr<15 for nonenriched FIXME
            if (p4().pt()<15) continue;
          } else {
              if (isQCDMu) {
              // Moriond 80X
//              if (p4().pt()<15. &&  scale1fb() > 14.8 && scale1fb() < 14.9 ) continue;  //take only Mu15 above pT=15
//              if (p4().pt()>15. && (scale1fb() < 14.8 || scale1fb() > 14.9)) continue;  //take only Mu5 below pT=15
//              if (scale1fb() < 1.03 || scale1fb() > 600.) continue; //avoid extreme ranges and weights
            }
          }
        }

        if (abs(id())==11) {
          // // FIXME
          // //if(isData==0 && scale1fb() > 100000.) continue;  //excludes 5to10 and 10to20 EM Enriched, 15to30 non-Enriched
          // if (debug) cout << "check qcd" << endl;
          // if (scale1fb() < 5.0) continue; //avoid extreme ranges and weights
          // if (scale1fb() > 280 && scale1fb() < 281) continue;
          // if (scale1fb() > 1085 && scale1fb() < 1086) continue;
        }
        //fixme
        //make sure we use mu from MuEnrich and el from EG+BCtoE
        // if (isData==0 && abs(id())==13 && fabs(scale1fb()-20.94)>0.1 && fabs(scale1fb()-79.81)>0.1 && fabs(scale1fb()-85.19)>0.1 && fabs(scale1fb()-357.93)>0.1) continue;
        // if (isData==0 && abs(id())==11 && !(fabs(scale1fb()-20.94)>0.1 && fabs(scale1fb()-79.81)>0.1 && fabs(scale1fb()-85.19)>0.1 && fabs(scale1fb()-357.93)>0.1)) continue;
      }

      bool jetptcut = false;
      float ht = 0.;
      int njets30 = 0;
      int nbtags = 0;
      for(unsigned int i=0; i<jets_recorr.size(); i++)  {
        if(ROOT::Math::VectorUtil::DeltaR(jets_recorr[i], p4()) < 1.) continue; //0.4 in babymaker
        if(jets_disc()[i] > BTAGWP) nbtags++;
        if(jets_recorr[i].pt() > 30. && fabs(jets_recorr[i].eta()) < 2.4) {
          ht += jets_recorr[i].pt();
          njets30++;
          if(debug) {
            cout << "-->recoiljet:" << jets_recorr[i].pt() << "," << jets_recorr[i].eta() << "," << jets_recorr[i].phi() << endl;
            cout << "-->deltaR " << ROOT::Math::VectorUtil::DeltaR(jets_recorr[i],p4()) << endl;
          }
        }
      }
      if(njets30 > 0) jetptcut = true;

      LorentzVector closejet = (jet_close_lep_p4*jet_close_lep_undoJEC()*jet_close_L1() - p4())*jet_close_L2L3() + p4(); // V5
      float ptrel =  computePtRel(p4(),closejet,true);//ptrelv1();
      float closejetpt = closejet.pt(); // V5
      //float miniIso = miniiso();
      float relIso = RelIso03EA();
      if (debug) cout << "close jet raw p4=" << jet_close_lep_p4*jet_close_lep_undoJEC()
        << " pt=" << (jet_close_lep_p4*jet_close_lep_undoJEC()).pt()
          << " corrected p4=" << closejet
          << " pt=" << closejet.pt()
          << " L1=" << jet_close_L1()
          << " L2L3=" << jet_close_L2L3()
          << " rho=" << rho()
          << " ptrel=" << ptrel
          << " ptratio=" << p4().pt()/closejetpt
          << endl;

      if(debug) {
        cout << "lepton pt,eta,phi: " << p4().pt() << "," << p4().eta() << "," << p4().phi() << endl;
        cout << "closejet pt,eta,phi: " << closejet.pt() << "," << closejet.eta() << "," << closejet.phi() << endl;
        cout << "deltaR " << ROOT::Math::VectorUtil::DeltaR(closejet,p4()) << endl;
      }

      if (debug) cout << "check jet: njets30=" << njets30 << " ht_SS=" << ht_SS() << endl;
      if( !jetptcut || ht_SS()<40 )
      {continue;}
//         if(abs(id())==13) histo_pt_mu->Fill(p4().pt());

      //trigger selection
      if (debug) cout << "check hlt HLT_Mu8=" << HLT_Mu8() << " HLT_Mu17=" << HLT_Mu17() << " HLT_Ele12_CaloIdM_TrackIdM_PFJet30=" << HLT_Ele12_CaloIdM_TrackIdM_PFJet30() << endl;
      if (abs(id())==11 && (isData || doTrig)) {
        // ele12 for 2015D
        if (useIsoTrigs) {
          if (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30()<=0
              && HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30()<=0
             ) continue;
        } else {
          if (HLT_Ele8_CaloIdM_TrackIdM_PFJet30()<=0
              && HLT_Ele17_CaloIdM_TrackIdM_PFJet30()<=0
             ) continue;
        }
      }
      if (abs(id())==13 && (isData || doTrig)) {
        // mu8 or mu17 for 2015D
        if (useIsoTrigs) {
          if (HLT_Mu8_TrkIsoVVL()<=0 &&
              HLT_Mu17_TrkIsoVVL()<=0) continue;
        } else {
          if (HLT_Mu8()<=0 &&
              HLT_Mu17()<=0) continue;
        }

      }

      float vtxWeight = 1.0;
      if (debug) cout << "check pt range of triggers" << endl;
      //check prescales, apply cuts on the pT range depending on the trigger
      int prescale = -1;
      if(!isData) prescale = 1; // triggers messed up in 80X MC
      if (abs(id())==11 && (isData || doTrig)) {
        if (useIsoTrigs) {
          if (p4().pt() >= 10 && p4().pt() < 25 && HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30()>0) {
            prescale = HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30();
            if (!doTrig) prescale = e8i; // FIXME
            vtxWeight = getPUw_iso_8_el(nvtx());
          }
          if ((anyPt || p4().pt() >= 25) && HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30()>0) {
            prescale = HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30();
            if (!doTrig) prescale = e17i; // FIXME
            vtxWeight = getPUw_iso_17_el(nvtx());
          }
          if (prescale>0) weight *= prescale;
          else continue;
        } else {
          if (p4().pt() >= 10 && p4().pt() < 25 && HLT_Ele8_CaloIdM_TrackIdM_PFJet30()>0) {
            prescale = HLT_Ele8_CaloIdM_TrackIdM_PFJet30();
            if (!doTrig) prescale = e8; // FIXME
            vtxWeight = getPUw_8_el(nvtx());
          }
          if ((anyPt || p4().pt() >= 25) && HLT_Ele17_CaloIdM_TrackIdM_PFJet30()>0) {
            prescale = HLT_Ele17_CaloIdM_TrackIdM_PFJet30();
            if (!doTrig) prescale = e17; // FIXME
            vtxWeight = getPUw_17_el(nvtx());
          }
          if (prescale>0) weight *= prescale;
          else continue;
        }
      }
      if (abs(id())==13 && (isData || doTrig)) {
        // use mu8+mu17
        if (useIsoTrigs) {
          if (p4().pt()>=10 && p4().pt()<25 && HLT_Mu8_TrkIsoVVL()>0) {
            prescale = HLT_Mu8_TrkIsoVVL();
            if (!doTrig) prescale = m8i; // FIXME
            vtxWeight = getPUw_iso_8_mu(nvtx());
          }

          if ((anyPt || p4().pt()>=25) && HLT_Mu17_TrkIsoVVL()>0) {
            prescale = HLT_Mu17_TrkIsoVVL();
            if (!doTrig) prescale = m17i; // FIXME
            vtxWeight = getPUw_iso_17_mu(nvtx());
          }

          if (prescale>0) weight *= prescale;
          else continue;
        } else {
          if (p4().pt()>=10 && p4().pt()<25 && HLT_Mu8()>0)
          {
            prescale = HLT_Mu8();
            if (!doTrig) prescale = m8; // FIXME
            vtxWeight = getPUw_8_mu(nvtx());
          }

          if ((anyPt || p4().pt() >= 25) && HLT_Mu17()>0)
          {
            prescale = HLT_Mu17();
            if (!doTrig) prescale = m17; // FIXME
            vtxWeight = getPUw_17_mu(nvtx());
          }

          if (prescale>0) weight *= prescale;
          else continue;
        }
      }

      if(applyDataVtxWeight) weight *= vtxWeight;

      //if (isSyncFile) weight = 1;

      if (debug) cout << "check nFO_SS" << endl;
      if(nFOs_SS() > 1) //if more than 1 FO in event
      {continue;}

      //Ditch bounds here and just enforce correct reading of histo in getFakeRate() in app_region/ScanChain.C???
      //If we dont want leptons w/ |eta|>2.4 in ttbar application, filling rate histos with leptons w/
      // |eta|>2.4 will mess up the rate in the highest eta bins (2<|eta|<3)
      //Don't think eta cut is anywhere else
      if (debug) cout << "check pt/eta" << endl;
      if(p4().pt() < 20.) continue;
      if(abs(id()) == 11 && fabs(p4().eta()) > 2.5) continue;
      if(abs(id()) == 13 && fabs(p4().eta()) > 2.4) continue;

      if (doLightonly && abs(id())==11 && p4().pt() < 20.) continue;//because EMEnriched does not go below 20 GeV

      if (debug) cout << "check sip " << fabs(ip3d()/ip3derr()) << endl;
      if (fabs(ip3d()/ip3derr())>4. ) continue;

      
      //============================================================================================
      // FIXME Modify me to get the right ID FIXME
      // FIXME Modify me to get the right ID FIXME
      // FIXME Modify me to get the right ID FIXME
      bool passId = passes_VVV_cutbased_tight_noiso() && RelIso03EA() < 0.06;
      bool passFO = (abs(id()) == 13&& passes_VVV_cutbased_fo_noiso() && RelIso03EA() < 0.4) || (passes_VVV_cutbased_fo()&&abs(id()) == 11 && RelIso03EA() < 0.1);
      bool passId_noiso = passes_VVV_cutbased_tight_noiso();
      bool passFO_noiso = passes_VVV_cutbased_fo_noiso();
      if (!passMyAnalysisID(passId, passFO)) continue;
      // FIXME Modify me to get the right ID FIXME
      // FIXME Modify me to get the right ID FIXME
      // FIXME Modify me to get the right ID FIXME
      //============================================================================================
      float evt_met = evt_corrMET();
      float evt_metPhi = evt_corrMETPhi();
      float evt_mt = calculateMt(p4(),evt_met,evt_metPhi);

      if (passId) {
        //mt control region
        if (evt_met > 30. && p4().pt()>30) {
          histo_mt_all->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==11) histo_mt_all_el->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==13) histo_mt_all_mu->Fill( std::min(evt_mt,float(200.)), weight );
        }
        if (evt_met < 20.) {
          histo_mt_lm->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==11) histo_mt_lm_el->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==13) histo_mt_lm_mu->Fill( std::min(evt_mt,float(200.)), weight );
        }
        if (evt_met > 30.) {
          histo_mt_cr->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==11) histo_mt_cr_el->Fill( std::min(evt_mt,float(200.)), weight );
          if (abs(id())==13) histo_mt_cr_mu->Fill( std::min(evt_mt,float(200.)), weight );
        }
        //test if bad data/MC ratio in mt control region is due to met
        if (p4().pt()>30) {
          histo_met_all->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==11) histo_met_all_el->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==13) histo_met_all_mu->Fill( std::min(evt_met,float(200.)), weight );
        }
        if (evt_mt < 20.) {
          histo_met_lm->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==11) histo_met_lm_el->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==13) histo_met_lm_mu->Fill( std::min(evt_met,float(200.)), weight );
        }
        if (evt_mt > 30.) {
          histo_met_cr->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==11) histo_met_cr_el->Fill( std::min(evt_met,float(200.)), weight );
          if (abs(id())==13) histo_met_cr_mu->Fill( std::min(evt_met,float(200.)), weight );
        }
      }
      if (debug) cout << "check met/mt " << evt_met << " / " << evt_mt << " metPhi=" << evt_metPhi << endl;
      if( !(evt_met < 20. && evt_mt < 20) ) {
        continue;
      }

      if (usePtRatioCor) {
        if (abs(id())==11) {
          float ptratiocor = closejetpt>0. ? p4().pt()*(1+std::max(0.,miniiso()-0.12))/closejetpt : 1.;
          passFO = passes_SS_fo_v5() && (ptratiocor > 0.76 || ptrel > 7.2);
        } else {
          float ptratiocor = closejetpt>0. ? p4().pt()*(1+std::max(0.,miniiso()-0.16))/closejetpt : 1.;
          passFO = passes_SS_fo_v5() && (ptratiocor > 0.80 || ptrel > 7.2);
        }
      }

      float coneptcorr = 1.;
      if (abs(id())==11) {
        if (ptrel>7.2) {
          coneptcorr = std::max(0.,miniiso()-0.12);
        } else {
          coneptcorr = max(double(0.),(closejetpt*0.80/p4().pt()-1.));
        }
      } else {
        if (ptrel>7.2) {
          coneptcorr = std::max(0.,miniiso()-0.16);
        } else {
          coneptcorr = max(double(0.),(closejetpt*0.76/p4().pt()-1.));
        }
      }
 
      if (useRelIso) {
        passId = passId_noiso && relIso<0.1;
        passFO = passFO_noiso && relIso<0.5;
      coneptcorr = std::max(0.,relIso-0.06);
      }

      if (debug) cout << Form("check FO miniiso=%.2f ptratio=%.2f ptrel=%5.2f mva=%5.2f",miniiso(),p4().pt()/closejetpt,ptrel,mva_25ns()) << endl;
      if (!passFO) continue;
      if (debug) cout << "passed FO" << endl;

      //------------------------------------------------------------------------------------------
      //---------------------------------Find e = f(const)---------------------------------------
      //------------------------------------------------------------------------------------------

      //Find ratio of nonprompt leps passing tight to nonprompt leps passing at least loose.  This is the fake rate
      // Use lep_passes_id to see if num.  Use FO to see if Fakable Object (denom)
      //Calculate e=Nt/(Nl) where l->loose  (as opposed to loose-not-tight).

      //Using gen level info to see if prompt -> no prompt contamination in measurement region
      //everything else is RECO (p4, id, passes_id, FO, etc.)

      if( noMCMatch || (motherID() <= 0 && (doBonly==0 || motherID() == -1) && (doConly==0 || motherID() == -2) && (doLightonly==0 || motherID() == 0) ) )  //if lep is nonprompt
      {
        if(abs(id())==11 &&passes_VVV_cutbased_tight_noiso() ) RelIso_BR_histo_el->Fill(RelIso03EA());
        if(abs(id())==13 &&passes_VVV_cutbased_tight_noiso() ) RelIso_BR_histo_mu->Fill(RelIso03EA());
        if( abs( id() ) == 11 ) //it's an el
        {
          if( passId )  //if el is tight
          {
            Nt = Nt + weight;
            Nt_e = Nt_e + weight;
          }
          if( passFO )
          {
            Nl = Nl + weight;     //l now means loose, as opposed to loose-not-tight
            Nl_e = Nl_e + weight;
          }
        }

        if( abs( id() ) == 13 ) //it's a mu
        {
          if( passId )  //if mu is tight
          {
            Nt = Nt + weight;
            Nt_mu = Nt_mu + weight;
          }
          if( passFO )
          {
            Nl = Nl + weight;     //l now means loose, as opposed to loose-not-tight
            Nl_mu = Nl_mu + weight;
          }
        }
      }

      //------------------------------------------------------------------------------------------
      //---------------------------------Find e = f(Pt,eta)---------------------------------------
      //------------------------------------------------------------------------------------------

      //Find ratio of nonprompt leps passing tight to nonprompt leps passing at least loose.  This is the fake rate
      // Use lep_passes_id to see if num.  Use FO to see if Fakable Object (denom)
      //Calculate e=Nt/(Nl) where l->loose  (as opposed to loose-not-tight).

      //Using gen level info to see if prompt -> no prompt contamination in measurement region
      //everything else is RECO (p4, id, passes_id, FO, etc.)


      if( noMCMatch || (motherID() <= 0 && (doBonly==0 || motherID() == -1) && (doConly==0 || motherID() == -2) && (doLightonly==0 || motherID() == 0) ) )  //if el is nonprompt (GEN info)
      {

        if (passFO) {
          histo_ht->Fill( std::min(ht,float(1000.)) );
          histo_met->Fill( std::min(evt_met,float(1000.)) );
          histo_mt->Fill( std::min(evt_mt,float(1000.)) );

          if( abs( id() ) == 11 ) pTrelvsIso_histo_el->Fill( std::min(RelIso03EA(),float(0.99)), std::min(ptrel,float(29.9)) );
          if( abs( id() ) == 13 ) pTrelvsIso_histo_mu->Fill( std::min(RelIso03EA(),float(0.99)), std::min(ptrel,float(29.9)) );
          if( abs( id() ) == 11 ) pTrel_histo_el->Fill( std::min(ptrel,float(29.9)) );
          if( abs( id() ) == 13 ) pTrel_histo_mu->Fill( std::min(ptrel,float(29.9)) );
        }

        if( abs( id() ) == 11 ) // it's an el
        {
          if( passId )  //if el is tight
          {
            //uncorrected and cone corrected FR
            Nt_histo_e->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //

            // NJA
            Nt_nvtx_histo_e->Fill(nvtx(), weight);   //

            //jet corrected FR
            Nt_jet_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            if (p4().pt()>25.) Nt_jet_highpt_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            else Nt_jet_lowpt_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
          }

          if( passFO )  //if el is FO
          {
            //not corrected FR
            Nl_histo_e->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //  <-- loose (as opposed to l!t)
            //cone corrected FR
            if( passId ) Nl_cone_histo_e->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //  <-- loose (as opposed to l!t)
            else Nl_cone_histo_e->Fill(getPt(p4().pt()*(1+coneptcorr),false), getEta(fabs(p4().eta()),ht,false), weight);

            // NJA
            Nl_cone_nvtx_histo_e->Fill(nvtx(), weight);

            //jet corrected FR
            Nl_jet_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            if (p4().pt()>25.) Nl_jet_highpt_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            else Nl_jet_lowpt_histo_e->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);

            if (isSyncFile) {
              cout << Form("Electron FO raw pt=%6.2f corr pt=%6.2f eta=%5.2f miniiso=%.2f ptratio=%.2f ptrel=%5.2f mva=%5.2f isNum=%1i met=%5.2f mt=%5.2f event %i",
                  p4().pt(),p4().pt()*(1+coneptcorr),p4().eta(),miniiso(),p4().pt()/closejetpt,ptrel,mva_25ns(),passId,evt_met,evt_mt,(int)evt_event()) << endl;
            }

            njets30_histo->Fill(njets30, weight);

            if (noMCMatch==0 && doBonly==0 && doConly==0 && doLightonly==0) //abundance doesn't make sense otherwise
            {
              if(motherID()==-1){
                NBs_BR_histo_e ->Fill(nbtags, weight);
                Bs_e = Bs_e + weight;
              }
              else if(motherID()==-2 || motherID()==0){
                NnotBs_BR_histo_e ->Fill(nbtags, weight);
                notBs_e = notBs_e + weight;
              }
            }
          }
        }
        if( abs( id() ) == 13 ) // it's a mu
        {
          if( passId )  //if mu is tight
          {
           //if(getPt(p4().pt(), false)>40) cout<<"have muons with pt>40:"<< getPt(p4().pt(), false)<<":eta:"<<getEta(fabs(p4().eta()),ht,false)<<":line:"<<__LINE__<<":weight:"<<weight<<endl;
            //uncorrected and cone corrected FR
            Nt_histo_mu->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //

            // NJA
            Nt_nvtx_histo_mu->Fill(nvtx(), weight);   //

            //jet corrected FR
            Nt_jet_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            if (p4().pt()>25.) Nt_jet_highpt_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            else Nt_jet_lowpt_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
          }

          if( passFO )  //if mu is FO
          {
            //not corrected FR
            Nl_histo_mu->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //  <-- loose (as opposed to l!t)
            //cone corrected FR
            if( passId ) Nl_cone_histo_mu->Fill(getPt(p4().pt(),false), getEta(fabs(p4().eta()),ht,false), weight);   //  <-- loose (as opposed to l!t)
            else Nl_cone_histo_mu->Fill(getPt(p4().pt()*(1+coneptcorr),false), getEta(fabs(p4().eta()),ht,false), weight);

            // NJA
            Nl_cone_nvtx_histo_mu->Fill(nvtx(), weight);

            //jet corrected FR
            Nl_jet_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            if (p4().pt()>25.) Nl_jet_highpt_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);
            else Nl_jet_lowpt_histo_mu->Fill(getPt(closejetpt,false), getEta(fabs(p4().eta()),ht,false), weight);

            if (isSyncFile) {

              cout << Form("%1llu %7.3f %7.3f %6.3f %6.3f %6.3f %6.3f %1i %6.3f %6.3f %6.0f",(unsigned long long)evt_event() , p4().pt(),p4().pt()*(1+coneptcorr),p4().eta(),miniiso(),p4().pt()/closejetpt,ptrel,passId,evt_met,evt_mt,weight) << endl;
            }

            njets30_histo->Fill(njets30, weight);

            if (noMCMatch==0 && doBonly==0 && doConly==0 && doLightonly==0) //abundance doesn't make sense otherwise
            {
              if(motherID()==-1){
                NBs_BR_histo_mu ->Fill(nbtags, weight);
                Bs_mu = Bs_mu + weight;
              }
              else if(motherID()==-2 || motherID()==0){
                NnotBs_BR_histo_mu ->Fill(nbtags, weight);
                notBs_mu = notBs_mu + weight;
              }
            }
          }
        }
      }

      //---------------------------------------------------------------------------------------------------------------------------

    }//end event loop

    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  e = Nt/(Nl);
  e_e = Nt_e/(Nl_e);
  e_mu = Nt_mu/(Nl_mu);

  cout<<"\nReco: "<<"Nt = "<<Nt<<", Nl = "<<Nl<<", e ="<<e<<endl;
  cout<<"\nReco (el): "<<"Nt = "<<Nt_e<<", Nl = "<<Nl_e<<", e ="<<e_e<<endl;
  cout<<"\nReco (mu): "<<"Nt = "<<Nt_mu<<", Nl = "<<Nl_mu<<", e ="<<e_mu<<endl<<endl;
  cout<<"\nAve B abundance (els)= "<<Bs_e/(Bs_e + notBs_e)<<endl;
  cout<<"Ave B abundance (mus)= "<<Bs_mu/(Bs_mu + notBs_mu)<<endl;

  //Histograms
  // TH2D *rate_histo = (TH2D*) Nt_histo->Clone("rate_histo");
  TH2D *rate_histo_e = (TH2D*) Nt_histo_e->Clone("rate_histo_e");
  TH2D *rate_histo_mu = (TH2D*) Nt_histo_mu->Clone("rate_histo_mu");
  TH2D *rate_cone_histo_e = (TH2D*) Nt_histo_e->Clone("rate_cone_histo_e");
  TH2D *rate_cone_histo_mu = (TH2D*) Nt_histo_mu->Clone("rate_cone_histo_mu");
  TH2D *rate_jet_histo_e = (TH2D*) Nt_jet_histo_e->Clone("rate_jet_histo_e");
  TH2D *rate_jet_histo_mu = (TH2D*) Nt_jet_histo_mu->Clone("rate_jet_histo_mu");
  TH2D *rate_jet_highpt_histo_e = (TH2D*) Nt_jet_highpt_histo_e->Clone("rate_jet_highpt_histo_e");
  TH2D *rate_jet_highpt_histo_mu = (TH2D*) Nt_jet_highpt_histo_mu->Clone("rate_jet_highpt_histo_mu");
  TH2D *rate_jet_lowpt_histo_e = (TH2D*) Nt_jet_lowpt_histo_e->Clone("rate_jet_lowpt_histo_e");
  TH2D *rate_jet_lowpt_histo_mu = (TH2D*) Nt_jet_lowpt_histo_mu->Clone("rate_jet_lowpt_histo_mu");
  TH1F *total_BR_histo_e = (TH1F*) NBs_BR_histo_e->Clone("total_BR_histo_e");
  TH1F *total_BR_histo_mu = (TH1F*) NBs_BR_histo_mu->Clone("total_BR_histo_mu");

  // NJA
  TH1D *rate_cone_nvtx_histo_e = (TH1D*) Nt_nvtx_histo_e->Clone("rate_cone_nvtx_histo_e");
  TH1D *rate_cone_nvtx_histo_mu = (TH1D*) Nt_nvtx_histo_mu->Clone("rate_cone_nvtx_histo_mu");
  rate_cone_nvtx_histo_e->Divide(rate_cone_nvtx_histo_e,Nl_cone_nvtx_histo_e);
  rate_cone_nvtx_histo_mu->Divide(rate_cone_nvtx_histo_mu,Nl_cone_nvtx_histo_mu);

  rate_histo_e->Divide(rate_histo_e,Nl_histo_e,1,1,"B");
  rate_histo_mu->Divide(rate_histo_mu,Nl_histo_mu,1,1,"B");
  rate_cone_histo_e->Divide(rate_cone_histo_e,Nl_cone_histo_e,1,1,"B");
  rate_cone_histo_mu->Divide(rate_cone_histo_mu,Nl_cone_histo_mu,1,1,"B");
  rate_jet_histo_e->Divide(rate_jet_histo_e,Nl_jet_histo_e,1,1,"B");
  rate_jet_histo_mu->Divide(rate_jet_histo_mu,Nl_jet_histo_mu,1,1,"B");
  rate_jet_highpt_histo_e->Divide(rate_jet_highpt_histo_e,Nl_jet_highpt_histo_e,1,1,"B");
  rate_jet_highpt_histo_mu->Divide(rate_jet_highpt_histo_mu,Nl_jet_highpt_histo_mu,1,1,"B");
  rate_jet_lowpt_histo_e->Divide(rate_jet_lowpt_histo_e,Nl_jet_lowpt_histo_e,1,1,"B");
  rate_jet_lowpt_histo_mu->Divide(rate_jet_lowpt_histo_mu,Nl_jet_lowpt_histo_mu,1,1,"B");
  total_BR_histo_e->Add(NnotBs_BR_histo_e);
  total_BR_histo_mu->Add(NnotBs_BR_histo_mu);
  NBs_BR_histo_e->Divide(NBs_BR_histo_e, total_BR_histo_e,1,1,"B");
  NBs_BR_histo_mu->Divide(NBs_BR_histo_mu, total_BR_histo_mu,1,1,"B");

  rate_histo_e->GetXaxis()->SetTitle("pT (GeV)");
  rate_histo_e->GetYaxis()->SetTitle("eta");
  rate_histo_e->GetZaxis()->SetRangeUser(0,.5);
  rate_histo_e->SetTitle("Fake Rate vs Pt, Eta (electrons)");
  rate_histo_mu->GetXaxis()->SetTitle("pT (GeV)");
  rate_histo_mu->GetYaxis()->SetTitle("eta");
  rate_histo_mu->GetZaxis()->SetRangeUser(0,.5);
  rate_histo_mu->SetTitle("Fake Rate vs Pt, Eta (muons)");
  rate_cone_histo_e->GetXaxis()->SetTitle("corrected pT (GeV)");
  rate_cone_histo_e->GetYaxis()->SetTitle("eta");
  rate_cone_histo_e->GetZaxis()->SetRangeUser(0,.5);
  rate_cone_histo_e->SetTitle("Fake Rate vs Pt + Cone Energy, Eta (electrons)");
  rate_cone_histo_mu->GetXaxis()->SetTitle("corrected pT (GeV)");
  rate_cone_histo_mu->GetYaxis()->SetTitle("eta");
  rate_cone_histo_mu->GetZaxis()->SetRangeUser(0,.5);
  rate_cone_histo_mu->SetTitle("Fake Rate vs Pt + Cone Energy, Eta (muons)");
  rate_jet_histo_e->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_histo_e->GetYaxis()->SetTitle("eta");
  rate_jet_histo_e->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_histo_e->SetTitle("Fake Rate vs Jet Pt, Eta (electrons)");
  rate_jet_histo_mu->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_histo_mu->GetYaxis()->SetTitle("eta");
  rate_jet_histo_mu->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_histo_mu->SetTitle("Fake Rate vs Jet Pt, Eta (muons)");
  rate_jet_highpt_histo_e->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_highpt_histo_e->GetYaxis()->SetTitle("eta");
  rate_jet_highpt_histo_e->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_highpt_histo_e->SetTitle("Fake Rate vs Jet Pt, Eta (electrons)");
  rate_jet_highpt_histo_mu->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_highpt_histo_mu->GetYaxis()->SetTitle("eta");
  rate_jet_highpt_histo_mu->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_highpt_histo_mu->SetTitle("Fake Rate vs Jet Pt, Eta (muons)");
  rate_jet_lowpt_histo_e->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_lowpt_histo_e->GetYaxis()->SetTitle("eta");
  rate_jet_lowpt_histo_e->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_lowpt_histo_e->SetTitle("Fake Rate vs Jet Pt, Eta (electrons)");
  rate_jet_lowpt_histo_mu->GetXaxis()->SetTitle("Jet pT (GeV)");
  rate_jet_lowpt_histo_mu->GetYaxis()->SetTitle("eta");
  rate_jet_lowpt_histo_mu->GetZaxis()->SetRangeUser(0,.5);
  rate_jet_lowpt_histo_mu->SetTitle("Fake Rate vs Jet Pt, Eta (muons)");
  NBs_BR_histo_e->GetXaxis()->SetTitle("Nbjets");
  NBs_BR_histo_e->GetYaxis()->SetTitle("Abundance");
  NBs_BR_histo_e->GetYaxis()->SetRangeUser(0., 1.);
  NBs_BR_histo_e->SetTitle("B Abundance vs Nbtags (electrons)");
  NBs_BR_histo_mu->GetXaxis()->SetTitle("Nbjets");
  NBs_BR_histo_mu->GetYaxis()->SetTitle("Abundance");
  NBs_BR_histo_mu->GetYaxis()->SetRangeUser(0., 1.);
  NBs_BR_histo_mu->SetTitle("B Abundance vs Nbtags (muons)");
  pTrelvsIso_histo_el->GetXaxis()->SetTitle("Iso");
  pTrelvsIso_histo_el->GetYaxis()->SetTitle("pTrel");
  pTrelvsIso_histo_mu->GetXaxis()->SetTitle("Iso");
  pTrelvsIso_histo_mu->GetYaxis()->SetTitle("pTrel");
  njets30_histo->GetXaxis()->SetTitle("Njets");
  njets30_histo->GetYaxis()->SetTitle("Events");
  njets30_histo->SetTitle("Njets with pT > 30 GeV");

  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat("1.3f");

  TCanvas *c11=new TCanvas("c11","B Abundance vs Nbjets (electrons)",800,800);
  c11->cd();
  NBs_BR_histo_e->Draw("histE");
  TCanvas *c12=new TCanvas("c12","B Abundance vs Nbjets (muons)",800,800);
  c12->cd();
  NBs_BR_histo_mu->Draw("histE");
  TCanvas *c13=new TCanvas("c13","Njets with pT > 40 GeV",800,800);
  c13->cd();
  njets30_histo->Draw("histE");

  //---save histos-------//
  saveHist(outfile.Data(),"*");
  delete jet_corrector_25ns_MC_pfL1;
  delete jet_corrector_25ns_MC_pfL1L2L3;
  delete jet_corrector_25ns_DATA_pfL1;
  delete jet_corrector_25ns_DATA_pfL1L2L3;

  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}
