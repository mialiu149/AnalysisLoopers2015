#include "dataMCplotMaker.h"
#include "TFile.h"
#include "TH1F.h"
#include <iostream>
#include <vector>
#include <string>
#include "TString.h"

using namespace std;

void makePlotQuickDilepCheck(){

  //  vector<char*> bgnames, signames;
  vector<string> bgstrings, sigstrings, sigstringn;
  vector<Color_t> colors;
  const unsigned int datasetsize =5;//12
  const unsigned int bgsetsize = 5;//8
  const unsigned int sigsetsize = datasetsize-bgsetsize;
  string datasets[datasetsize]={"TTbar1l","TTbar2l","SingleT","WJets","Rare"};

  string bgname[bgsetsize]={"$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 2\\ell$","$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 1\\ell$", "single $t$","W$(\\ell\\nu)$+jets", "Rare"};
  //string signame[sigsetsize]={"$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (650,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (850,100)"};
  string signame[sigsetsize];
  
  string datasetn[datasetsize]={"$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 1\\ell$","\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 2\\ell$","single $t$","W$(\\ell\\nu)$+jets","Rare"};
  const Color_t mccolor[datasetsize]={kRed-7,kCyan-3,kGreen-7,kOrange-2,kMagenta-5,/*kGreen+2,kYellow+1,kBlue,kMagenta*/};//kGreen-7 added

  
  string outputdir = "plots/";

  for(unsigned int n=0; n<bgsetsize; ++n) {
    bgstrings.push_back(datasets[n]);
    colors.push_back(mccolor[n]);
  }
  for(unsigned int n=bgsetsize; n<datasetsize; ++n) {
    sigstrings.push_back(datasets[n]);
    sigstringn.push_back(datasetn[n]);
    colors.push_back(mccolor[n]);
  }
  TFile *fbg[bgsetsize];
  for(unsigned int n=0; n<bgsetsize; ++n) {
    string datasetstring = datasets[n];
    if(n==0) datasetstring = "TTbar";
    else if(n==1) continue;
    TString x = ("rootfiles/TestLepDist_"+datasetstring+".root");
    //cout << x << endl;
      fbg[n] = TFile::Open(x);
      //  cout << fbg[n].IsZombie();
  }
  TFile *fsig[sigsetsize];
  for(unsigned int n=0; n<sigsetsize; ++n) {
    string datasetstring = datasets[bgsetsize+n];
    TString x = ("rootfiles/TestLepDist_"+datasetstring+".root");
    //cout << x << endl;
    fsig[n] = TFile::Open(x);
  }
  TFile *fdata = TFile::Open("rootfiles/TestLepDist_Data.root");

  vector<string> histonames;
   histonames.push_back("NLeps_lowMT2W");
   histonames.push_back("NLeps_highMT2W");
   histonames.push_back("NLeps_3j");
   TH1F* null = new TH1F("","",1,0,1);

   for(unsigned int i = 0; i<histonames.size();++i){
     vector<TH1F*> bghist; bghist.clear();
     vector<TH1F*> sighist; sighist.clear();
     string options = "--outputName " + outputdir + histonames[i] + " --xAxisLabel Leptons --energy 13 --lumi 2.11 --noXaxisUnit --legendTextSize 0.02 --type 1l --preserveBackgroundOrder --legendUp 0.05 --noOverflow --xAxisBinLabels SR,CR6,CR5,1l&>2l,CR4,>2l --isLinear";

     for(unsigned int n=0; n<bgsetsize; ++n){
       int fileidentifier = n;
       if(n==1) fileidentifier = 0;//TTbar2l
       //if(n==2) fileidentifier = 0;//TTbarH
       fbg[fileidentifier]->cd();
       string name = histonames[i]+"_"+bgstrings[n];
       //cout << fbg[fileidentifier]->GetName() << " " << name << endl;
       TH1F *h = (TH1F*)fbg[fileidentifier]->Get(name.c_str());
       //cout << h->GetName() << endl;
       //h->Scale(0.3);
       bghist.push_back(h);
     }
     for(unsigned int n=0; n<sigsetsize; ++n){
       fsig[n]->cd();
       string name = histonames[i]+"_"+sigstrings[n];
       TH1F *h = (TH1F*)fsig[n]->Get(name.c_str());
       //cout << fsig[n]->GetName() << " " << name << endl;
       //h->Scale(0.3);
       sighist.push_back(h);
       cout << sigstringn[n] << endl;
     }
     string dataname = histonames[i]+"_Data";
     TH1F *hdata =  (TH1F*)fdata->Get(dataname.c_str());
     hdata->SetBinContent(1,-1);
     dataMCplotMaker(hdata,bghist,bgstrings,"","",options,sighist,sigstrings,colors);
   }

} 
