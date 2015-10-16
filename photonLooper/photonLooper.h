#ifndef PHOTONLOOPER_H
#define PHOTONLOOPER_H

// #include "Math/LorentzVector.h"
// #include "Math/VectorUtil.h"

#include "TChain.h"
#include "TH1F.h"

class TChain;

// typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

class photonLooper
{
public:

  photonLooper();
  ~photonLooper();
  void ScanChain (TChain * chain,const std::string iter,const std::string sample);
  void bookHistos();
  void bookHist( std::string name, std::string title, int nbins, float xmin, float xmax );
  void fillHist( std::string var, std::string sel, float value, float weight );
  void setSample( std::string samplename );
  std::string getSample( std::string samplename );

private:

  std::string sampleName;
  std::map<std::string, TH1F*> event_hists;
  
};
#endif
