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

void RemoveDiagonal(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont);
TH2F* RemoveHistoDiagonal(TH2F *hold);
TGraph2D* GetInterpolatingGraph(TH2F *hold);
TH2F* PassThisHistogram(TH2F *hold);
TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec);
TGraph* GetContour(TGraph2D *g, TString name);

void RemoveDiagonal(TString signaltype, bool prefit, bool fakedata, bool nosigunc, bool nobkgunc, int xsecupdown, int compressed, bool dropsigcont){

  TString myoutputdir = outputdir;
  if(compressed==1) myoutputdir = myoutputdir + "compressed/";
  if(nosigunc&&nobkgunc) myoutputdir = myoutputdir + "nounc/";
  else if(nosigunc) myoutputdir = myoutputdir + "nosigunc/";
  else if(nobkgunc) myoutputdir = myoutputdir + "nobkgunc/";
  if(dropsigcont) myoutputdir = myoutputdir + "dropsigcont/";
  if(fakedata)   myoutputdir = myoutputdir + "fakedata/";
  TString infilename = myoutputdir + "Limits2DHistograms.root";
  TString outfilename = myoutputdir + "Limits2DHistogramsRemovedDiagonal.root";
  
  ifstream infile(infilename.Data());
  if(!(infile.good() ) ) {
    cout << "file " << outfilename << " does not exist - exit" << endl;
    return;
  }
  TFile *fin = new TFile(infilename, "read");
  fin->cd();
  TH2F* hExpOrg   = (TH2F*)fin->Get("hExpOrg");
  TH2F* hObsOrg   = (TH2F*)fin->Get("hObsOrg");
  TH2F* hObs1mOrg = (TH2F*)fin->Get("hObs1mOrg");
  TH2F* hObs1pOrg = (TH2F*)fin->Get("hObs1pOrg");
  TH2F* hExp1mOrg = (TH2F*)fin->Get("hExp1mOrg");
  TH2F* hExp2mOrg = (TH2F*)fin->Get("hExp2mOrg");
  TH2F* hExp1pOrg = (TH2F*)fin->Get("hExp1pOrg");
  TH2F* hExp2pOrg = (TH2F*)fin->Get("hExp2pOrg");
  TH2F* hExpOrgXsec   = (TH2F*)fin->Get("hExpOrgXsec");
  TH2F* hObsOrgXsec   = (TH2F*)fin->Get("hObsOrgXsec");
  TH2F* hObs1mOrgXsec = (TH2F*)fin->Get("hObs1mOrgXsec");
  TH2F* hObs1pOrgXsec = (TH2F*)fin->Get("hObs1pOrgXsec");
  TH2F* hExp1mOrgXsec = (TH2F*)fin->Get("hExp1mOrgXsec");
  TH2F* hExp2mOrgXsec = (TH2F*)fin->Get("hExp2mOrgXsec");
  TH2F* hExp1pOrgXsec = (TH2F*)fin->Get("hExp1pOrgXsec");
  TH2F* hExp2pOrgXsec = (TH2F*)fin->Get("hExp2pOrgXsec");
  TH2F* hExpOrgPass   = (TH2F*)fin->Get("hExpOrgPass");
  TH2F* hObsOrgPass   = (TH2F*)fin->Get("hObsOrgPass");
  TH2F* hObs1mOrgPass = (TH2F*)fin->Get("hObs1mOrgPass");
  TH2F* hObs1pOrgPass = (TH2F*)fin->Get("hObs1pOrgPass");
  TH2F* hExp1mOrgPass = (TH2F*)fin->Get("hExp1mOrgPass");
  TH2F* hExp2mOrgPass = (TH2F*)fin->Get("hExp2mOrgPass");
  TH2F* hExp1pOrgPass = (TH2F*)fin->Get("hExp1pOrgPass");
  TH2F* hExp2pOrgPass = (TH2F*)fin->Get("hExp2pOrgPass");
  TH2F* hExp   = (TH2F*)fin->Get("hExp");
  TH2F* hObs   = (TH2F*)fin->Get("hObs");
  TH2F* hObs1m = (TH2F*)fin->Get("hObs1m");
  TH2F* hObs1p = (TH2F*)fin->Get("hObs1p");
  TH2F* hExp1m = (TH2F*)fin->Get("hExp1m");
  TH2F* hExp2m = (TH2F*)fin->Get("hExp2m");
  TH2F* hExp1p = (TH2F*)fin->Get("hExp1p");
  TH2F* hExp2p = (TH2F*)fin->Get("hExp2p");
  TH2F* hExpXsec   = (TH2F*)fin->Get("hExpXsec");
  TH2F* hObsXsec   = (TH2F*)fin->Get("hObsXsec");
  TH2F* hObs1mXsec = (TH2F*)fin->Get("hObs1mXsec");
  TH2F* hObs1pXsec = (TH2F*)fin->Get("hObs1pXsec");
  TH2F* hExp1mXsec = (TH2F*)fin->Get("hExp1mXsec");
  TH2F* hExp2mXsec = (TH2F*)fin->Get("hExp2mXsec");
  TH2F* hExp1pXsec = (TH2F*)fin->Get("hExp1pXsec");
  TH2F* hExp2pXsec = (TH2F*)fin->Get("hExp2pXsec");
  TH2F* hExpPass   = (TH2F*)fin->Get("hExpPass");
  TH2F* hObsPass   = (TH2F*)fin->Get("hObsPass");
  TH2F* hObs1mPass = (TH2F*)fin->Get("hObs1mPass");
  TH2F* hObs1pPass = (TH2F*)fin->Get("hObs1pPass");
  TH2F* hExp1mPass = (TH2F*)fin->Get("hExp1mPass");
  TH2F* hExp2mPass = (TH2F*)fin->Get("hExp2mPass");
  TH2F* hExp1pPass = (TH2F*)fin->Get("hExp1pPass");
  TH2F* hExp2pPass = (TH2F*)fin->Get("hExp2pPass");

  TGraph2D *g2Exp   = (TGraph2D*)fin->Get("Graph2D_from_hExpOrg");
  TGraph2D *g2Obs   = (TGraph2D*)fin->Get("Graph2D_from_hObsOrg");
  TGraph2D *g2Obs1m = (TGraph2D*)fin->Get("Graph2D_from_hObs1mOrg");
  TGraph2D *g2Obs1p = (TGraph2D*)fin->Get("Graph2D_from_hObs1pOrg");
  TGraph2D *g2Exp1m = (TGraph2D*)fin->Get("Graph2D_from_hExp1mOrg");
  TGraph2D *g2Exp2m = (TGraph2D*)fin->Get("Graph2D_from_hExp2mOrg");
  TGraph2D *g2Exp1p = (TGraph2D*)fin->Get("Graph2D_from_hExp1pOrg");
  TGraph2D *g2Exp2p = (TGraph2D*)fin->Get("Graph2D_from_hExp2mOrg");//XXX - fix this later
  TGraph *gExp   = (TGraph*)fin->Get("gExp");
  TGraph *gObs   = (TGraph*)fin->Get("gObs");
  TGraph *gObs1m = (TGraph*)fin->Get("gObs1m");
  TGraph *gObs1p = (TGraph*)fin->Get("gObs1p");
  TGraph *gExp1m = (TGraph*)fin->Get("gExp1m");
  TGraph *gExp2m = (TGraph*)fin->Get("gExp2m");
  TGraph *gExp1p = (TGraph*)fin->Get("gExp1p");
  TGraph *gExp2p = (TGraph*)fin->Get("gExp2p");
  TGraph *gEmpty= (TGraph*)fin->Get("gEmpty");

  hExpOrg   ->SetName("hExpOrg_x");
  hObsOrg   ->SetName("hObsOrg_x");
  hObs1mOrg ->SetName("hObs1mOrg_x");
  hObs1pOrg ->SetName("hObs1pOrg_x");
  hExp1mOrg ->SetName("hExp1mOrg_x");
  hExp2mOrg ->SetName("hExp2mOrg_x");
  hExp1pOrg ->SetName("hExp1pOrg_x");
  hExp2pOrg ->SetName("hExp2pOrg_x");
  hExpOrgXsec   ->SetName("hExpOrgXsec_x");
  hObsOrgXsec   ->SetName("hObsOrgXsec_x");
  hObs1mOrgXsec ->SetName("hObs1mOrgXsec_x");
  hObs1pOrgXsec ->SetName("hObs1pOrgXsec_x");
  hExp1mOrgXsec ->SetName("hExp1mOrgXsec_x");
  hExp2mOrgXsec ->SetName("hExp2mOrgXsec_x");
  hExp1pOrgXsec ->SetName("hExp1pOrgXsec_x");
  hExp2pOrgXsec ->SetName("hExp2pOrgXsec_x");
  hExpOrgPass   ->SetName("hExpOrgPass_x");
  hObsOrgPass   ->SetName("hObsOrgPass_x");
  hObs1mOrgPass ->SetName("hObs1mOrgPass_x");
  hObs1pOrgPass ->SetName("hObs1pOrgPass_x");
  hExp1mOrgPass ->SetName("hExp1mOrgPass_x");
  hExp2mOrgPass ->SetName("hExp2mOrgPass_x");
  hExp1pOrgPass ->SetName("hExp1pOrgPass_x");
  hExp2pOrgPass ->SetName("hExp2pOrgPass_x");
  hExp   ->SetName("hExp_x");
  hObs   ->SetName("hObs_x");
  hObs1m ->SetName("hObs1m_x");
  hObs1p ->SetName("hObs1p_x");
  hExp1m ->SetName("hExp1m_x");
  hExp2m ->SetName("hExp2m_x");
  hExp1p ->SetName("hExp1p_x");
  hExp2p ->SetName("hExp2p_x");
  hExpXsec   ->SetName("hExpXsec_x");
  hObsXsec   ->SetName("hObsXsec_x");
  hObs1mXsec ->SetName("hObs1mXsec_x");
  hObs1pXsec ->SetName("hObs1pXsec_x");
  hExp1mXsec ->SetName("hExp1mXsec_x");
  hExp2mXsec ->SetName("hExp2mXsec_x");
  hExp1pXsec ->SetName("hExp1pXsec_x");
  hExp2pXsec ->SetName("hExp2pXsec_x");
  hExpPass   ->SetName("hExpPass_x");
  hObsPass   ->SetName("hObsPass_x");
  hObs1mPass ->SetName("hObs1mPass_x");
  hObs1pPass ->SetName("hObs1pPass_x");
  hExp1mPass ->SetName("hExp1mPass_x");
  hExp2mPass ->SetName("hExp2mPass_x");
  hExp1pPass ->SetName("hExp1pPass_x");
  hExp2pPass ->SetName("hExp2pPass_x");

  
  g2Exp   ->SetName("Graph2D_from_hExpOrg_x");
  g2Obs   ->SetName("Graph2D_from_hObsOrg_x");
  g2Obs1m ->SetName("Graph2D_from_hObs1mOrg_x");
  g2Obs1p ->SetName("Graph2D_from_hObs1pOrg_x");
  g2Exp1m ->SetName("Graph2D_from_hExp1mOrg_x");
  g2Exp2m ->SetName("Graph2D_from_hExp2mOrg_x");
  g2Exp1p ->SetName("Graph2D_from_hExp1pOrg_x");
  g2Exp2p ->SetName("Graph2D_from_hExp2pOrg_x");
  gExp   ->SetName("gExp_x");
  gObs   ->SetName("gObs_x");
  gObs1m ->SetName("gObs1m_x");
  gObs1p ->SetName("gObs1p_x");
  gExp1m ->SetName("gExp1m_x");
  gExp2m ->SetName("gExp2m_x");
  gExp1p ->SetName("gExp1p_x");
  gExp2p ->SetName("gExp2p_x");
  gEmpty->SetName("gEmpty_x");

  TFile *fout = new TFile(outfilename, "recreate");
  fout->cd();
  TH2F* nhExpOrg   = (TH2F*)RemoveHistoDiagonal(hExpOrg);
  TH2F* nhObsOrg   = (TH2F*)RemoveHistoDiagonal(hObsOrg);
  TH2F* nhObs1mOrg = (TH2F*)RemoveHistoDiagonal(hObs1mOrg);
  TH2F* nhObs1pOrg = (TH2F*)RemoveHistoDiagonal(hObs1pOrg);
  TH2F* nhExp1mOrg = (TH2F*)RemoveHistoDiagonal(hExp1mOrg);
  TH2F* nhExp2mOrg = (TH2F*)RemoveHistoDiagonal(hExp2mOrg);
  TH2F* nhExp1pOrg = (TH2F*)RemoveHistoDiagonal(hExp1pOrg);
  TH2F* nhExp2pOrg = (TH2F*)RemoveHistoDiagonal(hExp2pOrg);
  TH2F* nhExpOrgXsec   = (TH2F*)RemoveHistoDiagonal(hExpOrgXsec);
  TH2F* nhObsOrgXsec   = (TH2F*)RemoveHistoDiagonal(hObsOrgXsec);
  TH2F* nhObs1mOrgXsec = (TH2F*)RemoveHistoDiagonal(hObs1mOrgXsec);
  TH2F* nhObs1pOrgXsec = (TH2F*)RemoveHistoDiagonal(hObs1pOrgXsec);
  TH2F* nhExp1mOrgXsec = (TH2F*)RemoveHistoDiagonal(hExp1mOrgXsec);
  TH2F* nhExp2mOrgXsec = (TH2F*)RemoveHistoDiagonal(hExp2mOrgXsec);
  TH2F* nhExp1pOrgXsec = (TH2F*)RemoveHistoDiagonal(hExp1pOrgXsec);
  TH2F* nhExp2pOrgXsec = (TH2F*)RemoveHistoDiagonal(hExp2pOrgXsec);
  TH2F* nhExpOrgPass   = (TH2F*)RemoveHistoDiagonal(hExpOrgPass);
  TH2F* nhObsOrgPass   = (TH2F*)RemoveHistoDiagonal(hObsOrgPass);
  TH2F* nhObs1mOrgPass = (TH2F*)RemoveHistoDiagonal(hObs1mOrgPass);
  TH2F* nhObs1pOrgPass = (TH2F*)RemoveHistoDiagonal(hObs1pOrgPass);
  TH2F* nhExp1mOrgPass = (TH2F*)RemoveHistoDiagonal(hExp1mOrgPass);
  TH2F* nhExp2mOrgPass = (TH2F*)RemoveHistoDiagonal(hExp2mOrgPass);
  TH2F* nhExp1pOrgPass = (TH2F*)RemoveHistoDiagonal(hExp1pOrgPass);
  TH2F* nhExp2pOrgPass = (TH2F*)RemoveHistoDiagonal(hExp2pOrgPass);
  TH2F* nhExp   = (TH2F*)RemoveHistoDiagonal(hExp);
  TH2F* nhObs   = (TH2F*)RemoveHistoDiagonal(hObs);
  TH2F* nhObs1m = (TH2F*)RemoveHistoDiagonal(hObs1m);
  TH2F* nhObs1p = (TH2F*)RemoveHistoDiagonal(hObs1p);
  TH2F* nhExp1m = (TH2F*)RemoveHistoDiagonal(hExp1m);
  TH2F* nhExp2m = (TH2F*)RemoveHistoDiagonal(hExp2m);
  TH2F* nhExp1p = (TH2F*)RemoveHistoDiagonal(hExp1p);
  TH2F* nhExp2p = (TH2F*)RemoveHistoDiagonal(hExp2p);
  TH2F* nhExpXsec   = (TH2F*)RemoveHistoDiagonal(hExpXsec);
  TH2F* nhObsXsec   = (TH2F*)RemoveHistoDiagonal(hObsXsec);
  TH2F* nhObs1mXsec = (TH2F*)RemoveHistoDiagonal(hObs1mXsec);
  TH2F* nhObs1pXsec = (TH2F*)RemoveHistoDiagonal(hObs1pXsec);
  TH2F* nhExp1mXsec = (TH2F*)RemoveHistoDiagonal(hExp1mXsec);
  TH2F* nhExp2mXsec = (TH2F*)RemoveHistoDiagonal(hExp2mXsec);
  TH2F* nhExp1pXsec = (TH2F*)RemoveHistoDiagonal(hExp1pXsec);
  TH2F* nhExp2pXsec = (TH2F*)RemoveHistoDiagonal(hExp2pXsec);
  TH2F* nhExpPass   = (TH2F*)RemoveHistoDiagonal(hExpPass);
  TH2F* nhObsPass   = (TH2F*)RemoveHistoDiagonal(hObsPass);
  TH2F* nhObs1mPass = (TH2F*)RemoveHistoDiagonal(hObs1mPass);
  TH2F* nhObs1pPass = (TH2F*)RemoveHistoDiagonal(hObs1pPass);
  TH2F* nhExp1mPass = (TH2F*)RemoveHistoDiagonal(hExp1mPass);
  TH2F* nhExp2mPass = (TH2F*)RemoveHistoDiagonal(hExp2mPass);
  TH2F* nhExp1pPass = (TH2F*)RemoveHistoDiagonal(hExp1pPass);
  TH2F* nhExp2pPass = (TH2F*)RemoveHistoDiagonal(hExp2pPass);

  TGraph2D *ng2Exp   = (TGraph2D*)g2Exp->Clone("Graph2D_from_hExpOrg");
  TGraph2D *ng2Obs   = (TGraph2D*)g2Obs->Clone("Graph2D_from_hObsOrg");
  TGraph2D *ng2Obs1m = (TGraph2D*)g2Obs1m->Clone("Graph2D_from_hObs1mOrg");
  TGraph2D *ng2Obs1p = (TGraph2D*)g2Obs1p->Clone("Graph2D_from_hObs1pOrg");
  TGraph2D *ng2Exp1m = (TGraph2D*)g2Exp1m->Clone("Graph2D_from_hExp1mOrg");
  TGraph2D *ng2Exp2m = (TGraph2D*)g2Exp2m->Clone("Graph2D_from_hExp2mOrg");
  TGraph2D *ng2Exp1p = (TGraph2D*)g2Exp1p->Clone("Graph2D_from_hExp1pOrg");
  TGraph2D *ng2Exp2p = (TGraph2D*)g2Exp2p->Clone("Graph2D_from_hExp2pOrg");
  TGraph *ngExp   = (TGraph*)gExp->Clone("gExp");
  TGraph *ngObs   = (TGraph*)gObs->Clone("gObs");
  TGraph *ngObs1m = (TGraph*)gObs1m->Clone("gObs1m");
  TGraph *ngObs1p = (TGraph*)gObs1p->Clone("gObs1p");
  TGraph *ngExp1m = (TGraph*)gExp1m->Clone("gExp1m");
  TGraph *ngExp2m = (TGraph*)gExp2m->Clone("gExp2m");
  TGraph *ngExp1p = (TGraph*)gExp1p->Clone("gExp1p");
  TGraph *ngExp2p = (TGraph*)gExp2p->Clone("gExp2p");
  TGraph *ngEmpty= (TGraph*)gExp2p->Clone("gEmpty");

  fout->cd();
  nhExpOrg   ->Write();
  nhObsOrg   ->Write();
  nhObs1mOrg ->Write();
  nhObs1pOrg ->Write();
  nhExp1mOrg ->Write();
  nhExp2mOrg ->Write();
  nhExp1pOrg ->Write();
  nhExp2pOrg ->Write();
  nhExpOrgXsec   ->Write();
  nhObsOrgXsec   ->Write();
  nhObs1mOrgXsec ->Write();
  nhObs1pOrgXsec ->Write();
  nhExp1mOrgXsec ->Write();
  nhExp2mOrgXsec ->Write();
  nhExp1pOrgXsec ->Write();
  nhExp2pOrgXsec ->Write();
  nhExpOrgPass   ->Write();
  nhObsOrgPass   ->Write();
  nhObs1mOrgPass ->Write();
  nhObs1pOrgPass ->Write();
  nhExp1mOrgPass ->Write();
  nhExp2mOrgPass ->Write();
  nhExp1pOrgPass ->Write();
  nhExp2pOrgPass ->Write();
  nhExp   ->Write();
  nhObs   ->Write();
  nhObs1m ->Write();
  nhObs1p ->Write();
  nhExp1m ->Write();
  nhExp2m ->Write();
  nhExp1p ->Write();
  nhExp2p ->Write();
  nhExpXsec   ->Write();
  nhObsXsec   ->Write();
  nhObs1mXsec ->Write();
  nhObs1pXsec ->Write();
  nhExp1mXsec ->Write();
  nhExp2mXsec ->Write();
  nhExp1pXsec ->Write();
  nhExp2pXsec ->Write();
  nhExpPass   ->Write();
  nhObsPass   ->Write();
  nhObs1mPass ->Write();
  nhObs1pPass ->Write();
  nhExp1mPass ->Write();
  nhExp2mPass ->Write();
  nhExp1pPass ->Write();
  nhExp2pPass ->Write();

  ng2Exp   ->Write();
  ng2Obs   ->Write();
  ng2Obs1m ->Write();
  ng2Obs1p ->Write();
  ng2Exp1m ->Write();
  ng2Exp2m ->Write();
  ng2Exp1p ->Write();
  ng2Exp2p ->Write();
  ngExp   ->Write();
  ngObs   ->Write();
  ngObs1m ->Write();
  ngObs1p ->Write();
  ngExp1m ->Write();
  ngExp2m ->Write();
  ngExp1p ->Write();
  ngExp2p ->Write();
  ngEmpty->Write();
  fout->Close();
  cout << "Saved all histos in  " << fout->GetName() << endl;
  
}


TH2F* RemoveHistoDiagonal(TH2F *hold){
  int nbinsX = hold->GetNbinsX();
  int nbinsY = hold->GetNbinsY();
  TString name = hold->GetName();
  name.ReplaceAll("_x","");
  TH2F *h = (TH2F*)hold->Clone(name);

  for(int x = 1; x<=h->GetNbinsX(); ++x){
    for(int y = 1; y<=h->GetNbinsY(); ++y){
      float xlow = h->GetXaxis()->GetBinLowEdge(x);
      float xup  = xlow + h->GetXaxis()->GetBinWidth(x);
      float ylow = h->GetYaxis()->GetBinLowEdge(y);
      float yup  = ylow + h->GetYaxis()->GetBinWidth(y);
      //if(name=="hExp") cout << "xlow " << xlow << " xup " << xup << " ylow " << ylow << " yup " << yup << endl;
      if(((xlow-ylow)>=172.5&&((xlow-ylow)<=175))||((xup-yup)>=172.5&&(xup-yup)<=175.) ) //continue;
      h->SetBinContent(x,y,0);
    }
  }
  return h;
}

TGraph2D* GetInterpolatingGraph(TH2F *hold){
  float binsize = hold->GetXaxis()->GetBinWidth(1)/2.;
  TString name = hold->GetName();
  name.ReplaceAll("Org","");
  TGraph2D *g = new TGraph2D(hold);
  g->SetNpx(int(g->GetXmax()-g->GetXmin())/binsize);
  g->SetNpy(int(g->GetYmax()-g->GetYmin())/binsize);
  //cout << "name " << g->GetN() << " " << hold->Integral() << endl;
  return g;
}

TH2F* PassThisHistogram(TH2F *hold){
  TString name = hold->GetName() + (TString)"Pass";
  TH2F *hnew = (TH2F*)hold->Clone(name);
  for(int x = 1; x<=hnew->GetNbinsX(); ++x){
    for(int y = 1; y<=hnew->GetNbinsY(); ++y){
      float val = hnew->GetBinContent(x,y);
      float pass = 0;
      if(val>1) pass = 0.001;
      else if(val>0) pass = 1;
      hnew->SetBinContent(x,y,pass);
    }
  }
  return hnew;
}

TH2F* XsecThisHistogram(TH2F *hold, TH1D *hxsec){
  TString name = hold->GetName() + (TString)"Xsec";
  TH2F *hnew = (TH2F*)hold->Clone(name);
  for(int x = 1; x<=hnew->GetNbinsX(); ++x){
    for(int y = 1; y<=hnew->GetNbinsY(); ++y){
      float val = hnew->GetBinContent(x,y);
      float mstop = hnew->GetXaxis()->GetBinLowEdge(x);
      //cout << "check " << "bin " << x << " gets me mstop " << mstop << endl;
      float xsec = hxsec->GetBinContent(hxsec->FindBin(mstop));
      hnew->SetBinContent(x,y,val*xsec);
    }
  }
  return hnew;
}

TGraph* GetContour(TGraph2D *g, TString name){
  TGraph *gnew;
  //cout << g->GetName() << " " << g->GetN() << endl;
  TH2D *temp = (TH2D*)g->GetHistogram();//need this for list to work?
  //g->Draw("alp");//need this for list to work?
  TList *glist = (TList*)g->GetContourList(1.0);
  if(glist == nullptr) return gnew;
  int max_points = -1;
  int nn = glist->GetSize();
  //cout << "number of entries in list " << nn << endl;
  for(int i = 0; i<glist->GetSize(); ++i){
    TGraph *gtemp = (TGraph*)glist->At(i);
    int Npoints = gtemp->GetN();
    if(Npoints>max_points){
      gnew = (TGraph*)gtemp->Clone(name);
      max_points = Npoints;
    }
  }
  return gnew;
}
