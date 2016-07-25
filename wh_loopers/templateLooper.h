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
   TH2D* histscan;
   TH2D* histscan_genmet;
   TH2D* histscan_pdfup ;
   TH2D* histscan_pdfdn ;
   TH2D* histscan_scaleup ;
   TH2D* histscan_scaledn ;
   TH2D* histscan_btagsfup ;
   TH2D* histscan_btagsfdn ;
   TH2D* histscan_lepsfup ;
   TH2D* histscan_lepsfdn ;
   TH2D* histscan_isrnom;
   TH2D* histscan_isrup;
   TH2D* histscan_isrdn ;
};
#endif
