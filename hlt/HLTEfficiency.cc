#include <algorithm>
#include <iostream>
#include <string>
#include <map>

#include <TFile.h>
#include <TH2F.h>



class HLTEfficiency{
  
public:

  HLTEfficiency(std::string filename="HLT_Efficiencies_7p65fb_2016.root") {
    _initHistos=false;
    _fileName=filename;
    loadFile();
  };
  
  ~HLTEfficiency() {
      _file->Close();
    // delete _hist_HLT_DiEle_Leg1;
    // delete _hist_HLT_DiEle_Leg2;
    // delete _hist_HLT_EleMu_Leg1;
    // delete _hist_HLT_MuEle_Leg2;
    // delete _hist_HLT_DiEleHT_Leg;
    // delete _hist_HLT_EleMuHT_Leg1;
    // delete _hist_HLT_DiMu_Leg1;
    // delete _hist_HLT_DiMu_Leg2;
    // delete _hist_HLT_MuEle_Leg1;
    // delete _hist_HLT_EleMu_Leg2;
    // delete _hist_HLT_DiMuHT_Leg;
    // delete _hist_HLT_EleMuHT_Leg2;
    // delete _file;

  };


  float getEfficiency(float pt1, float eta1, int pdgId1,
		      float pt2, float eta2, int pdgId2, 
		      float ht, int var=0) {
    
    int flav=std::abs(pdgId1)+std::abs(pdgId2);
    bool isHTHLT=(ht>300);
    bool l1Lead=(pt1>pt2);

    int hltleg1=-1; 
    int hltleg2=-1;

    float totEff=1;

    switch(flav) {
    case 22: {
      hltleg1 = (isHTHLT)?( kElHTLeg ):( l1Lead?kElLeg1:kElLeg2 );
      hltleg2 = (isHTHLT)?( kElHTLeg ):( l1Lead?kElLeg2:kElLeg1 );
      //DZ efficiency correction
      totEff *= 0.995 + var*0.005;
      break;
    }
    case 24: {
      if(std::abs(pdgId1)==11) {
	hltleg1 = (isHTHLT)?( kElHTXTLeg ):( l1Lead?kElXTLeg1:kElXTLeg2 );
	hltleg2 = (isHTHLT)?( kMuHTXTLeg ):( l1Lead?kMuXTLeg2:kMuXTLeg1 );
      } else {
	hltleg1 = (isHTHLT)?( kMuHTXTLeg ):( l1Lead?kMuXTLeg1:kMuXTLeg2 );
	hltleg2 = (isHTHLT)?( kElHTXTLeg ):( l1Lead?kElXTLeg2:kElXTLeg1 );
      }
      break;
    }
    case 26: { 
      hltleg1 = (isHTHLT)?( kMuHTLeg ):( l1Lead?kMuLeg1:kMuLeg2 );
      hltleg2 = (isHTHLT)?( kMuHTLeg ):( l1Lead?kMuLeg2:kMuLeg1 );
      // if(!isHTHLT) totEff *= 0.86;
      break;
    }
    }
    
    totEff *= getSingleEfficiency(pt1, eta1, hltleg1, var) * getSingleEfficiency(pt2, eta2, hltleg2, var );

    //L1 HT plateau efficiency
    //https://lathomas.web.cern.ch/lathomas/SUSYMultiLepton/TriggerEff/Results_7p65fb/l1htturnon.pdf
    // if(isHTHLT) totEff *= 0.962 + var*0.01; // email 155eeeeaaa87dece
    
    //HLT HT efficiency correction for low pt leptons
    if(ht>300 && ht<325 && pt1<30 && pt2<30) {
      totEff *= 0.85 + var*0.05;
    }

    return std::min( (float)1.0,totEff);
  };


private:

  void loadFile() { 
    _file = TFile::Open(_fileName.c_str(), "read");
    
    _hist_HLT_DiEle_Leg1   =(TH2F*)_file->Get("hist2dnum_Ele23_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
    _hist_HLT_DiEle_Leg2   =(TH2F*)_file->Get("hist2dnum_Ele12_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
    _hist_HLT_EleMu_Leg1   =(TH2F*)_file->Get("hist2dnum_Ele23_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
    _hist_HLT_MuEle_Leg2   =(TH2F*)_file->Get("hist2dnum_Ele12_CaloIdL_TrackIdL_IsoVL__HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
    _hist_HLT_DiEleHT_Leg  =(TH2F*)_file->Get("hist2dnum_Ele8_CaloIdM_TrackIdM__DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250or300");
    _hist_HLT_EleMuHT_Leg1 =(TH2F*)_file->Get("hist2dnum_Ele8_CaloIdM_TrackIdM__DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250or300");
    _hist_HLT_DiMu_Leg1    =(TH2F*)_file->Get("hist2dnum_Mu17__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"); // modify this
    _hist_HLT_DiMu_Leg2    =(TH2F*)_file->Get("hist2dnum_Mu8__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"); // modify this
    _hist_HLT_MuEle_Leg1   =(TH2F*)_file->Get("hist2dnum_Mu17__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
    _hist_HLT_EleMu_Leg2   =(TH2F*)_file->Get("hist2dnum_Mu8__HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
    _hist_HLT_DiMuHT_Leg   =(TH2F*)_file->Get("hist2dnum_Mu8__HLT_DoubleMu8_Mass8_PFHT250or300");
    _hist_HLT_EleMuHT_Leg2 =(TH2F*)_file->Get("hist2dnum_Mu8__HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT250or300");
    
  };

  float getSingleEfficiency(float pt, float eta, int hlttag, int var) {

    switch(hlttag) {
    case kElLeg1:    { return getBinContent(pt, std::abs(eta), _hist_HLT_DiEle_Leg1)   + var*0.01;}
    case kElLeg2:    { return getBinContent(pt, std::abs(eta), _hist_HLT_DiEle_Leg2)   + var*0.01;}
    case kElXTLeg1:  { return getBinContent(pt, std::abs(eta), _hist_HLT_EleMu_Leg1)   + var*0.01;}
    case kElXTLeg2:  { return getBinContent(pt, std::abs(eta), _hist_HLT_MuEle_Leg2)   + var*0.01;}
    case kElHTLeg:   { return getBinContent(pt, std::abs(eta), _hist_HLT_DiEleHT_Leg)  + var*0.01;}
    case kElHTXTLeg: { return getBinContent(pt, std::abs(eta), _hist_HLT_EleMuHT_Leg1) + var*0.01;}
    case kMuLeg1:    { return getBinContent(pt, std::abs(eta), _hist_HLT_DiMu_Leg1)    + var*0.01;}
    case kMuLeg2:    { return getBinContent(pt, std::abs(eta), _hist_HLT_DiMu_Leg2)    + var*0.01;}
    case kMuXTLeg1:  { return getBinContent(pt, std::abs(eta), _hist_HLT_MuEle_Leg1)   + var*0.01;}
    case kMuXTLeg2:  { return getBinContent(pt, std::abs(eta), _hist_HLT_EleMu_Leg2)   + var*0.01;}
    case kMuHTLeg:   { return getBinContent(pt, std::abs(eta), _hist_HLT_DiMuHT_Leg)   + var*0.01;}
    case kMuHTXTLeg: { return getBinContent(pt, std::abs(eta), _hist_HLT_EleMuHT_Leg2) + var*0.01;}
    }
    return 1;
  };

  float getBinContent(float x, float y, TH2F* h) {
    int xb=h->GetXaxis()->FindBin( x );
    int yb=h->GetYaxis()->FindBin( y );
    return h->GetBinContent(xb,yb);
  };


private:

  enum {kElLeg1, kElLeg2, kElXTLeg1, kElXTLeg2, kElHTLeg, kElHTXTLeg,
	kMuLeg1, kMuLeg2, kMuXTLeg1, kMuXTLeg2, kMuHTLeg, kMuHTXTLeg };
  
  bool _initHistos;


  //TH2F* _hist_HLT_DiEle_DZ;
  TH2F* _hist_HLT_DiEle_Leg1;
  TH2F* _hist_HLT_DiEle_Leg2;
  TH2F* _hist_HLT_EleMu_Leg1;
  TH2F* _hist_HLT_MuEle_Leg2;
  TH2F* _hist_HLT_DiEleHT_Leg;
  TH2F* _hist_HLT_EleMuHT_Leg1;
  TH2F* _hist_HLT_DiMu_Leg1;
  TH2F* _hist_HLT_DiMu_Leg2;
  TH2F* _hist_HLT_MuEle_Leg1;
  TH2F* _hist_HLT_EleMu_Leg2;
  TH2F* _hist_HLT_DiMuHT_Leg;
  TH2F* _hist_HLT_EleMuHT_Leg2;

  TFile* _file;
  std::string _fileName;

};
