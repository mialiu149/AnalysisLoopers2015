#include <iostream>
#include "TH1.h"
#include "TFile.h"
#include "TList.h"
#include "TIterator.h"
#include "TRegexp.h"
#include "TObject.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TMath.h"

using namespace std;


float err_mult(float A, float B, float errA, float errB, float C) {
  return sqrt(C*C*(pow(errA/A,2) + pow(errB/B,2)));
}

double getBinomialError( const double num, const double deno ){
  double   p       =   num / deno;
  double   error   =   sqrt(p*(1-p)/deno);
  return error;  
}

void fillUnderOverFlow(TH1F * &h1, float value, float weight){
  float min = h1->GetXaxis()->GetXmin();
  float max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void fillUnderOverFlow(TH1D * &h1, double value, float weight){
  double min = h1->GetXaxis()->GetXmin();
  double max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void saveHist(const string filename, const string pat)
{
  TList* list = gDirectory->GetList() ;
  TIterator* iter = list->MakeIterator();
  TRegexp re(pat.c_str(),kTRUE) ;
  TObject *obj;
  TFile outf(filename.c_str(),"RECREATE") ;
  while((obj=iter->Next())) {
	if (TString(obj->GetName()).Index(re)>=0) {
	  obj->Write() ;
	  cout << "." ;
	  cout.flush() ;
	}
  }
  cout << endl ;
  outf.Close() ;
  delete iter ;
}

void drawCMSLatex( TCanvas * &canvas, float luminosity )
{

  canvas->cd();
  TLatex *lumitex = NULL;
  lumitex = new TLatex(0.66,0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex->SetNDC();    
  lumitex->SetTextSize(0.04);    
  lumitex->SetLineWidth(2);
  lumitex->SetTextFont(42);    
  lumitex->Draw();

  TLatex *cmstex = NULL;
  cmstex = new TLatex(0.18,0.95, "CMS Preliminary" );    
  cmstex->SetNDC();    
  cmstex->SetTextSize(0.04);    
  cmstex->SetLineWidth(2);
  cmstex->SetTextFont(62);    
  cmstex->Draw();

  return;
}

void drawCMSLatex( TCanvas * &canvas, float luminosity, float cmsleftmargin, float lumileftmargin )
{

  canvas->cd();
  TLatex *lumitex = NULL;
  // lumitex = new TLatex(lumileftmargin, 0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex = new TLatex(lumileftmargin, 0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex->SetNDC();    
  lumitex->SetTextSize(0.04);    
  lumitex->SetLineWidth(2);
  lumitex->SetTextFont(42);    
  lumitex->Draw();

  TLatex *cmstex = NULL;
  cmstex = new TLatex(cmsleftmargin, 0.95, "CMS Simulation" );    
  cmstex->SetNDC();    
  cmstex->SetTextSize(0.04);    
  cmstex->SetLineWidth(2);
  cmstex->SetTextFont(62);    
  cmstex->Draw();

  return;
}

void getBackground( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  backgroundhist = dynamic_cast<TH1F*>(infile->Get(Form("h_%s_event_%s_%s", leptype.c_str(), variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getYield( TH1D* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  backgroundhist = dynamic_cast<TH1D*>(infile->Get(Form("h_%s_event_%s_%s", leptype.c_str(), variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getBackgroundGenSplit( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype,std::string gentype ,std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  backgroundhist = dynamic_cast<TH1F*>(infile->Get(Form("h_%s_%s_event_%s_%s", leptype.c_str(),gentype.c_str() ,variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getTemplateMET( TH1F* &methist, std::string iter, std::string bgfileprefix )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  methist = dynamic_cast<TH1F*>(infile->Get("h_templ_met")->Clone(Form("methist_%s", bgfileprefix.c_str())));  
  return;
}

void updateoverflow( TH1F * &hist, float xmax )
{

  int overflowbin = hist->FindBin(xmax)-1;
  for( int bini = overflowbin; bini < hist->GetNbinsX(); bini++ ){
	hist->SetBinContent( overflowbin, hist->GetBinContent( overflowbin ) + hist->GetBinContent( bini + 1 ) );	
	hist->SetBinError  ( overflowbin, sqrt( pow(hist->GetBinError  ( overflowbin ), 2 ) + pow( hist->GetBinError( bini + 1 ), 2 ) ) );	
	hist->SetBinContent( bini + 1, 0 );
	hist->SetBinError  ( bini + 1, 0 );
  }
  return;
}


