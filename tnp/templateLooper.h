#ifndef TEMPLATELOOPER_h
#define TEMPLATELOOPER_h

#include "TChain.h"
#include "TH1F.h"
#include "TH1D.h"

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
  TH2F* histPtvsEta_den;  
  TH2F* histPtvsEta_num;  
};
#endif
