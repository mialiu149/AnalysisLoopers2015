#ifndef TEMPLATELOOPER_h
#define TEMPLATELOOPER_h

#include "TChain.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"

class TChain;

class templateLooper
{
public:

  templateLooper();
  ~templateLooper();
  void ScanChain (TChain * chain,const std::string iter,const std::string sample, const std::string selection);
  void bookHistos(const std::string region);
  void bookHist( std::string name, std::string title, int nbins, float xmin, float xmax );
  void bookHistTH1D( std::string name, std::string title, int nbins, float xmin, float xmax );
  void fillHist( std::string obj, std::string var, std::string sel, float value, float weight );
  
private:

  std::map<std::string, TH1F*> mettemplate_hists;
  std::map<std::string, TH1F*> event_hists;
  std::map<std::string, TH1D*> histos_cutflow;
   TH2F* histMCTvsMT; 
   TH2F* histMCTvsMET; 
   TH2F* histMCTvsMbb; 
   TH3D* histscan;
   TH3D* histscan_genmet;
   TH3D* histscan_pdfup ;
   TH3D* histscan_pdfdn ;
   TH3D* histscan_scaleup ;
   TH3D* histscan_scaledn ;
   TH3D* histscan_btagsfup ;
   TH3D* histscan_btagsfdn ;
   TH3D* histscan_lepsfup ;
   TH3D* histscan_lepsfdn ;
   TH3D* histscan_isrnom;
   TH3D* histscan_isrup;
   TH3D* histscan_isrdn;
   TH3D* histscan_trigup;
   TH3D* histscan_trigdn;
   TH3D* histscan_pileupup;
   TH3D* histscan_pileupdn;
  TFile *f_el_SF;
  // Fullsim Electron file
  TFile *f_el_SF_tracking;
  // Fullsim Muon files
  TFile *f_mu_SF_id;
  TFile *f_mu_SF_iso;
  TFile *f_mu_SF_ip;
  TFile *f_mu_SF_tracking;
  TFile *f_mu_SF_veto_id;
  TFile *f_mu_SF_veto_iso;
  TFile *f_mu_SF_veto_ip;
  // Fullsim/Fastsim Electron files
  TFile *f_el_FS_ID;
  TFile *f_el_FS_Iso;
  TFile *f_el_veto_FS_ID;
  TFile *f_el_veto_FS_Iso;

  // Fullsim/Fastsim Muon files
  TFile *f_mu_FS_ID;
  TFile *f_mu_FS_Iso;
  TFile *f_mu_FS_Ip;
  TFile *f_mu_veto_FS_ID;
  TFile *f_mu_veto_FS_Iso;
  TFile *f_mu_veto_FS_Ip;
  TFile *f_vetoLep_eff;

 // trigger sf files
  TFile *f_trig_el_sf;
  TFile *f_trig_mu_sf;
  TH1F* h_trig_el_sf;
  TH1F* h_trig_mu_sf_eb;
  TH1F* h_trig_mu_sf_ee;
};
#endif
