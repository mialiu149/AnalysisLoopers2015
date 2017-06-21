#ifndef looper_h
#define looper_h

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>

#include "Math/VectorUtil.h"
#include "Math/LorentzVector.h"

#include "CORE/SSSelections.h"

class TChain;
struct Lep;
struct DilepHyp;

int runMain(bool useSkim, bool skimAll, bool runAll, bool runLepEff, bool runSync, string runBaby, bool expt, std::vector<int> evtToDebug = std::vector<int>());

class looper
{
 public:
  typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector; 
  looper() {
    p4_ = new LorentzVector();
  };
  ~looper() {
    //delete babyFile_;
    //delete babyTree_;
  };
  
  int ScanChain ( TChain* chain, TString prefix, TString postfix, bool isData, TString whatTest = "", int nEvents = -1, std::vector<int> evtToDebug = std::vector<int>());



  
  //void MakeBabyNtuple (const char *);
  //void InitBabyNtuple ();
  //void FillBabyNtuple (){babyTree_->Fill();}
  //void CloseBabyNtuple () { babyFile_->cd();babyTree_->Write();babyFile_->Close();}
  
  void CreateOutputFile(const char * name){
    outf = TFile::Open(name,"RECREATE");
  }
  void SaveHistos(){outf->cd();outf->Write();outf->Close();}
  void fillUnderOverFlow(TH1F *h1, float value, float weight = 1);
  
  void printEvent(  ostream& ostr = std::cout );
  
  template<class T, class U> void makeFillHisto1D(const char* name,const char* title,
						  int nbins,U minx,U maxx,U value, 
						  float weight = 1.) {
    if (makehist==0) return;
    T* h = (T*) outf->Get(name);
    if (!h) {
      outf->cd();
      h = new T(name, title, nbins, minx, maxx);
      h->Sumw2();
    }
    h->Fill(std::max(minx,std::min(value,U(h->GetBinCenter(nbins)))),weight);
  }
  template<class T, class U> void makeFillHisto2D(const char* name,const char* title,
						  int nbinsx,U minx,U maxx,U valuex,
						  int nbinsy,U miny,U maxy,U valuey, 
						  float weight = 1.) {
    if (makehist==0) return;
    T* h = (T*) outf->Get(name);
    if (!h) {
      outf->cd();
      h = new T(name, title, nbinsx, minx, maxx, nbinsy, miny, maxy);
      h->Sumw2();
    }
    h->Fill(std::max(minx,std::min(valuex,U(h->GetXaxis()->GetBinCenter(nbinsx)))),std::max(miny,std::min(valuey,U(h->GetYaxis()->GetBinCenter(nbinsy)))),weight);
    float newvaluex = std::max(minx,std::min(valuex,U(h->GetXaxis()->GetBinCenter(nbinsx))));
    float newvaluey = std::max(miny,std::min(valuey,U(h->GetYaxis()->GetBinCenter(nbinsy))));
    if (TString(name)=="evt_mt_vs_pt" && valuey>80. && newvaluey<80.) std::cout << valuex << " " << newvaluex << " " << valuey << " " << newvaluey << std::endl;
  }
  
 private:
  
  bool makebaby;
  bool makehist;
  bool maketext;
  
  //ntuple, file
  //TFile *babyFile_;
  //TTree *babyTree_;
  TFile *outf;
  
  //baby vars
  int run_,ls_,evt_;
  float weight_;

  LorentzVector* p4_;

  //histos
  TH1F* h_dummy;
  
  ofstream ofile;
};

#endif
