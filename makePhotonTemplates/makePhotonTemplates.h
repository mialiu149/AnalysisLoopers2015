#ifndef makePhotonTemplates_h
#define makePhotonTemplates_h

// #include "Math/LorentzVector.h"
// #include "Math/VectorUtil.h"

#include "TChain.h"
#include "TH1F.h"

class TChain;

// typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

class makePhotonTemplates
{
public:

  makePhotonTemplates();
  ~makePhotonTemplates();
  void ScanChain (TChain * chain,const std::string iter,const std::string sample, const std::string selection);
  void bookHistos();
  
private:

  std::map<std::string, TH1F*> mettemplate_hists;
  
};
#endif
