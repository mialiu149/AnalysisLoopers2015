#include "TList.h"
#include "TMath.h"
#include "TString.h"
#include "TObject.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TH3F.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TH3D.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMap.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TStopwatch.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <cmath>

using namespace std;

TString inputdir = "/hadoop/cms/store/user/haweber/condor/limits/";
TString outputdir = "rootfiles/";

inline TString MakeOutputDir(TString dir){
  if(!dir.EndsWith("/")) dir += "/";
  // Create directory if needed
  //  >> NOTE: This function needs to be called before the booking functions!
  char cmd[100];
  sprintf(cmd,"mkdir -p %s", dir.Data());
  system(cmd);
  return dir;
}

void Make2DLimitHistos(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont);


void Make2DLimitHistos(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont){

  TH1D *hxsec;
  TFile *fxsec = new TFile("xsec_stop_13TeV.root","READ");
  if(fxsec->IsZombie()) {
    std::cout << "Somehow xsec_stop_13TeV.root is corrupted. Exit..." << std::endl;
    exit(0);
  }
  hxsec = (TH1D*)fxsec->Get("stop");
  
  int mStopLow  = 100;
  int mStopHigh = 1000;
  int mStopStep = 25;
  int mLSPLow   = 0;
  int mLSPHigh  = 500;
  int mLSPStep  = 25;
  int nbinsx = (mStopHigh - mStopLow)/mStopStep;
  int nbinsy = (mLSPHigh - mLSPLow)/mLSPStep;
  
  TString myoutputdir = outputdir;
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  MakeOutputDir(myoutputdir);
  TString myinputdir = inputdir;
  if(fakedata)   myinputdir = myinputdir + "fakedata/";
  if(compressed==1) myinputdir = myinputdir + "compressed/";
  if(nosigunc&&nobkgunc) myinputdir = myinputdir + "nounc/";
  else if(nosigunc) myinputdir = myinputdir + "nosigunc/";
  else if(nobkgunc) myinputdir = myinputdir + "nobkgunc/";
  
  TString outfilename = myoutputdir + "Limits2DHistograms.root";
  TFile *file = new TFile(outfilename, "recreate");
  file->cd();
  TH2F *hExp   = new TH2F("hExp",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs   = new TH2F("hObs",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1p = new TH2F("hObs1p", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1m = new TH2F("hObs1m", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1m = new TH2F("hExp1m", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2m = new TH2F("hExp2m", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1p = new TH2F("hExp1p", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2p = new TH2F("hExp2p", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpXsec   = new TH2F("hExpXsec",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsXsec   = new TH2F("hObsXsec",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pXsec = new TH2F("hObs1pXsec", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mXsec = new TH2F("hObs1mXsec", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mXsec = new TH2F("hExp1mXsec", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mXsec = new TH2F("hExp2mXsec", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pXsec = new TH2F("hExp1pXsec", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pXsec = new TH2F("hExp2pXsec", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExpPass   = new TH2F("hExpPass",   "hExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObsPass   = new TH2F("hObsPass",   "hObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1pPass = new TH2F("hObs1pPass", "hObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hObs1mPass = new TH2F("hObs1mPass", "hObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1mPass = new TH2F("hExp1mPass", "hExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2mPass = new TH2F("hExp2mPass", "hExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp1pPass = new TH2F("hExp1pPass", "hExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hExp2pPass = new TH2F("hExp2pPass", "hExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  
  TH2F *hSmoothedExp   = new TH2F("hSmoothedExp",   "hSmoothedExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs   = new TH2F("hSmoothedObs",   "hSmoothedObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1p = new TH2F("hSmoothedObs1p", "hSmoothedObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1m = new TH2F("hSmoothedObs1m", "hSmoothedObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1m = new TH2F("hSmoothedExp1m", "hSmoothedExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2m = new TH2F("hSmoothedExp2m", "hSmoothedExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1p = new TH2F("hSmoothedExp1p", "hSmoothedExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2p = new TH2F("hSmoothedExp2p", "hSmoothedExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExpXsec   = new TH2F("hSmoothedExpXsec",   "hSmoothedExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObsXsec   = new TH2F("hSmoothedObsXsec",   "hSmoothedObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1pXsec = new TH2F("hSmoothedObs1pXsec", "hSmoothedObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1mXsec = new TH2F("hSmoothedObs1mXsec", "hSmoothedObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1mXsec = new TH2F("hSmoothedExp1mXsec", "hSmoothedExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2mXsec = new TH2F("hSmoothedExp2mXsec", "hSmoothedExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1pXsec = new TH2F("hSmoothedExp1pXsec", "hSmoothedExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2pXsec = new TH2F("hSmoothedExp2pXsec", "hSmoothedExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExpPass   = new TH2F("hSmoothedExpPass",   "hSmoothedExp"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObsPass   = new TH2F("hSmoothedObsPass",   "hSmoothedObs"  , nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1pPass = new TH2F("hSmoothedObs1pPass", "hSmoothedObs1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedObs1mPass = new TH2F("hSmoothedObs1mPass", "hSmoothedObs1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1mPass = new TH2F("hSmoothedExp1mPass", "hSmoothedExp1m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2mPass = new TH2F("hSmoothedExp2mPass", "hSmoothedExp2m", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp1pPass = new TH2F("hSmoothedExp1pPass", "hSmoothedExp1p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);
  TH2F *hSmoothedExp2pPass = new TH2F("hSmoothedExp2pPass", "hSmoothedExp2p", nbinsx, mStopLow, mStopHigh, nbinsy, mLSPLow, mLSPHigh);

  for(int stop = mStopLow; stop<=mStopHigh; stop += mStopStep){
    for(int lsp = mLSPLow; lsp<=mLSPHigh; lsp += mLSPStep){
      TString limitfilebase = "Limits_Asymptotic_";
      if(prefit) limitfilebase = limitfilebase + "PreFit_";
      TString signalname = signaltype + "_" + std::to_string(stop) + "_" + std::to_string(lsp);
      TString limitfile = myinputdir + limitfilebase + signalname + ".root";
      cout << limitfile << endl;
      ifstream infile(limitfile.Data());
      bool exists = infile.good();
      if(!exists) {
	//cout << "No limit name for " << signalname << " - exit" << endl;
	continue;
      }
      cout << "Limit file exists for " << signalname << endl;
      double obs    = -1.0; //observed limit
      double obsm1s  = -1.0; //observed limit - 1 sigma theory
      double obsp1s = -1.0; //observed limit + 1 sigma theory
      double expm2s = -1.0; //expected - 2 sigma
      double expm1s = -1.0; //expected - 1 sigma
      double exp    = -1.0; //expected limit
      double expp1s = -1.0; //expected + 1 sigma
      double expp2s = -1.0; //expected + 2 sigma
      
      double xsec = hxsec->GetBinContent(hxsec->FindBin(stop));
      double xsecunc = hxsec->GetBinError(hxsec->FindBin(stop));
      TFile *flimit;
      flimit = new TFile(limitfile,"READ");
      if(flimit->IsZombie()) {
	flimit->Close();
	delete flimit;
	cout << "No limit file for " << signalname << " - exit" << endl;
	continue;
      }
      cout << "First create 2d limit histograms" << endl;
      //so flimit exists
      flimit->cd();
      TTree *tlimit = (TTree*)flimit->Get("limit");
      double value = -1.0;
      tlimit->SetBranchAddress("limit", &value);
            
      for(int i=0; i< 6; i++){
	tlimit->GetEntry(i);
	if(i==0)      expm2s = value;
	else if(i==1) expm1s = value;
	else if(i==2) exp    = value;
	else if(i==3) expp1s = value;
	else if(i==4) expp2s = value;
	else if(i==5) obs    = value;
      }
      delete tlimit;
      flimit->Close();
      delete flimit;

      file->cd();
      hExp  ->Fill(stop,lsp,exp   );
      hExp2m->Fill(stop,lsp,expm2s);
      hExp1m->Fill(stop,lsp,expm1s);
      hExp1p->Fill(stop,lsp,expp1s);
      hExp2p->Fill(stop,lsp,expp2s);
      hObs  ->Fill(stop,lsp,obs   );
      //xsecupdown
      hObs1p->Fill(stop,lsp,obs*xsec/(xsec+xsecunc)   );
      hObs1m->Fill(stop,lsp,obs*xsec/(xsec-xsecunc)   );
      
      hExpXsec  ->Fill(stop,lsp,xsec*exp   );
      hExp2mXsec->Fill(stop,lsp,xsec*expm2s);
      hExp1mXsec->Fill(stop,lsp,xsec*expm1s);
      hExp1pXsec->Fill(stop,lsp,xsec*expp1s);
      hExp2pXsec->Fill(stop,lsp,xsec*expp2s);
      hObsXsec  ->Fill(stop,lsp,xsec*obs   );
      //xsecupdown
      hObs1pXsec->Fill(stop,lsp,xsec*obs*xsec/(xsec+xsecunc)   );
      hObs1mXsec->Fill(stop,lsp,xsec*obs*xsec/(xsec-xsecunc)   );
      float nope = 0.0001; float yeah = 1.;
      if(exp   <1.) hExpPass  ->Fill(stop,lsp,yeah);
      else          hExpPass  ->Fill(stop,lsp,nope);
      if(expm2s<1.) hExp2mPass->Fill(stop,lsp,yeah);
      else          hExp2mPass->Fill(stop,lsp,nope);
      if(expm1s<1.) hExp1mPass->Fill(stop,lsp,yeah);
      else          hExp1mPass->Fill(stop,lsp,nope);
      if(expp1s<1.) hExp1pPass->Fill(stop,lsp,yeah);
      else          hExp1pPass->Fill(stop,lsp,nope);
      if(expp2s<1.) hExp2pPass->Fill(stop,lsp,yeah);
      else          hExp2pPass->Fill(stop,lsp,nope);
      if(obs   <1.) hObsPass  ->Fill(stop,lsp,yeah);
      else          hObsPass  ->Fill(stop,lsp,nope);
      //xsecupdown
      if(obs*xsec/(xsec+xsecunc)<1.) hObs1pPass->Fill(stop,lsp,yeah);
      else                           hObs1pPass->Fill(stop,lsp,nope);
      if(obs*xsec/(xsec-xsecunc)<1.) hObs1pPass->Fill(stop,lsp,yeah);
      else                           hObs1pPass->Fill(stop,lsp,nope);
      /*
      //XSec up limits
      limitfile = myinputdir + limitfilebase + "_XsecUp" + signalname + ".root";
      ifstream infilep(limitfile.Data());
      exists = infilep.good();
      if(exists){
	flimit = new TFile(limitfile,"READ");
	if(flimit->IsZombie()) {
	  flimit->Close();
	  delete flimit;
	  //cout << "No limit file for " << signalname << " - exit" << endl;
	  continue;
	}
	tlimit = (TTree*)flimit->Get("limit");
	tlimit->SetBranchAddress("limit", &value);
	tlimit->GetEntry(5);
	obsp1s = value;
	delete tlimit;
	flimit->Close();
	delete flimit;
	file->cd();
	hObs1p      ->Fill(stop,lsp,obsp1s);
	hObs1pXsec  ->Fill(stop,lsp,(xsec+xsecunc)*obsp1s);
	if(obsp1s<1.) hObs1pPass  ->Fill(stop,lsp,yeah);
	else          hObs1pPass  ->Fill(stop,lsp,nope);
      }
      //Xsecdown limits
      limitfile = myinputdir + limitfilebase + "_XsecDown" + signalname + ".root";
      ifstream infilem(limitfile.Data());
      exists = infilem.good();
      if(exists){
	flimit = new TFile(limitfile,"READ");
	if(flimit->IsZombie()) {
	  flimit->Close();
	  delete flimit;
	  //cout << "No limit file for " << signalname << " - exit" << endl;
	  continue;
	}
	tlimit = (TTree*)flimit->Get("limit");
	tlimit->SetBranchAddress("limit", &value);
	tlimit->GetEntry(5);
	obsm1s = value;
	delete tlimit;
	flimit->Close();
	delete flimit;
	file->cd();
	hObs1m      ->Fill(stop,lsp,obsm1s);
	hObs1mXsec  ->Fill(stop,lsp,(xsec+xsecunc)*obsm1s);
	if(obsm1s<1.) hObs1mPass  ->Fill(stop,lsp,yeah);
	else          hObs1mPass  ->Fill(stop,lsp,nope);
      }
      */
      
    }//lsp
  }//stop
      cout << "Next do interpolating using TGraph2D" << endl;
      TGraph2D *gExp = new TGraph2D(hExp);
      float interbinsize = mStopStep/2.;
      gExp->SetNpx(int(gExp->GetXmax()-gExp->GetXmin())/interbinsize);
      gExp->SetNpy(int(gExp->GetYmax()-gExp->GetYmin())/interbinsize);
      hExp = (TH2F*)gExp->GetHistogram();

  //make smoothed histograms
  
  //based on h*Pass histograms get TGraphs

  file->cd();
  gExp->Write();
  hExp   ->Write();
  hObs   ->Write();
  hObs1m ->Write();
  hObs1p ->Write();
  hExp1m ->Write();
  hExp2m ->Write();
  hExp1p ->Write();
  hExp2p ->Write();
  hExpXsec   ->Write();
  hObsXsec   ->Write();
  hObs1mXsec ->Write();
  hObs1pXsec ->Write();
  hExp1mXsec ->Write();
  hExp2mXsec ->Write();
  hExp1pXsec ->Write();
  hExp2pXsec ->Write();
  hExpPass   ->Write();
  hObsPass   ->Write();
  hObs1mPass ->Write();
  hObs1pPass ->Write();
  hExp1mPass ->Write();
  hExp2mPass ->Write();
  hExp1pPass ->Write();
  hExp2pPass ->Write();
  file->Close();

  fxsec->Close();
  delete fxsec;
  
}
