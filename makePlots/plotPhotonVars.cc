#include <iostream>
#include <map>

#include "TFile.h"
#include "TH1.h"
#include "TPad.h"
#include "TLegend.h"
#include "THStack.h"
#include "TKey.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TColor.h"

#include "plotPhotonVars.h"

using namespace std;

string filename = "";

void plotPhotonVars()
{

  filename = "../output/photon/V00-00-00/All_MC_photon_hists.root";
  std::cout<<"Reading hists from file: "<<filename<<endl;

  makeAndSavePlot( "pt"   , "2jets", 5, true );
  makeAndSavePlot( "ht"   , "2jets", 10, true );
  makeAndSavePlot( "met"  , "2jets", 5, true );
  makeAndSavePlot( "t1met", "2jets", 5, true );
  makeAndSavePlot( "njets", "2jets", 1, true );

  return;
}

void addHistToMap( string hname, std::map<std::string, TH1F*> &histmap, TFile * &infile ){
  TH1F* hist = dynamic_cast<TH1F*>(infile->Get(hname.c_str())->Clone((hname+"plot").c_str()));
  histmap.insert ( pair<std::string,TH1F*>( hname, hist ) );		
  return;
}

void rebinMap( std::map<std::string, TH1F*> &histmap, int rebin ){
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
	itr->second->Rebin(rebin);
  }
  return;
}

void setColorMap( std::map<std::string, TH1F*> &histmap ){
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
	if( TString(itr->first).Contains("_incl_") ) continue;
	if( TString(itr->first).Contains("_ht100_") ) itr->second->SetFillColor(kGreen   );
	if( TString(itr->first).Contains("_ht200_") ) itr->second->SetFillColor(kBlue    );
	if( TString(itr->first).Contains("_ht400_") ) itr->second->SetFillColor(kRed     );
	if( TString(itr->first).Contains("_ht600_") ) itr->second->SetFillColor(kMagenta );
	itr->second->SetFillStyle(1001);
	itr->second->SetLineWidth(2);
  }
  return;
}

TLegend* getLegend( std::map<std::string, TH1F*> &histmap ){
  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
	if( TString(itr->first).Contains("_incl_")  ) l1->AddEntry( itr->second , "#gamma+jets"       , "");
  }
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
	if( TString(itr->first).Contains("_ht100_") ) l1->AddEntry( itr->second , "H_{T}: 100-200 GeV"    , "f");
	if( TString(itr->first).Contains("_ht200_") ) l1->AddEntry( itr->second , "H_{T}: 200-400 GeV"    , "f");
	if( TString(itr->first).Contains("_ht400_") ) l1->AddEntry( itr->second , "H_{T}: 400-600 GeV"    , "f");
	if( TString(itr->first).Contains("_ht600_") ) l1->AddEntry( itr->second , "H_{T} #geq 600 GeV"    , "f");
  }
	// l1->Draw();
  // return;
  return l1;
}

void fixNormalization( std::map<std::string, TH1F*> &histmap )
{
  TH1F * h_incl = NULL;
  float bincontent = 0;
  float binerror = 0;
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
	if( TString(itr->first).Contains("_incl_")  ) h_incl = itr->second;
  }
  h_incl->Scale(0);  
  for (std::map<std::string, TH1F*>::iterator itr = histmap.begin(); itr != histmap.end(); itr++){
  	if( ! TString(itr->first).Contains("_incl_")  ){
  	  for( int bini = 0; bini < itr->second->GetNbinsX()+1; bini++ ){
  		bincontent = itr->second->GetBinContent(bini) + h_incl->GetBinContent(bini);
  		h_incl->SetBinContent(bini, bincontent);
  		binerror = sqrt(pow(itr->second->GetBinError(bini),2) + pow(h_incl->GetBinError(bini),2));
  		h_incl->SetBinError(bini, binerror);
  	  }
  	}
  }
  return;
}

void makeAndSavePlot( string var, string sel, int rebin, bool setlog )
{

  // string filename = "../output/photon/V00-00-00/All_MC_photon_hists.root";
  string outputdir = "../output/ZMET2015/V00-00-00/plots/photonVars/";

  TFile *infile = new TFile(filename.c_str());
  // std::cout<<"Reading hists from file: "<<filename<<endl;

  std::map<std::string, TH1F*> m_hists;
  addHistToMap( Form( "h_incl_%s_%s", var.c_str(), sel.c_str() ) ,m_hists, infile );
  addHistToMap( Form("h_ht100_%s_%s", var.c_str(), sel.c_str() ) ,m_hists, infile );
  addHistToMap( Form("h_ht200_%s_%s", var.c_str(), sel.c_str() ) ,m_hists, infile );
  addHistToMap( Form("h_ht400_%s_%s", var.c_str(), sel.c_str() ) ,m_hists, infile );
  addHistToMap( Form("h_ht600_%s_%s", var.c_str(), sel.c_str() ) ,m_hists, infile );

  rebinMap(    m_hists, rebin );
  setColorMap( m_hists );
	
  THStack * stack = new THStack("stack","");
  stack->Add(m_hists.at(Form("h_ht600_%s_%s", var.c_str(), sel.c_str() )));
  stack->Add(m_hists.at(Form("h_ht400_%s_%s", var.c_str(), sel.c_str() )));
  stack->Add(m_hists.at(Form("h_ht200_%s_%s", var.c_str(), sel.c_str() )));
  stack->Add(m_hists.at(Form("h_ht100_%s_%s", var.c_str(), sel.c_str() )));
  
  TCanvas * c1 = new TCanvas("c1","c1",800,800);
  c1->cd();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  if( setlog ) pad->SetLogy();

  TLegend * legend = getLegend( m_hists );
  
  fixNormalization( m_hists );
  
  TH1F * h_format = dynamic_cast<TH1F*>(m_hists.at(Form("h_incl_%s_%s", var.c_str(), sel.c_str() ))->Clone("h_format"));
  // TH1F * h_format = m_hists.at(Form("h_incl_%s_%s", var.c_str(), sel.c_str() ));

  double entries = h_format->GetEntries();
  if( entries < 1 ){
	cout<<"Empty hist."<<endl;
  }

  if( var == "pt" ){
	h_format->GetXaxis()->SetTitle("#gamma p_{T} GeV");
	h_format->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
	h_format->GetYaxis()->SetRangeUser(5e1,5e5);
  }

  if( var == "met" ){
	h_format->GetXaxis()->SetTitle("raw pf E_{T}^{miss} GeV");
	h_format->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
	// h_format->GetYaxis()->SetRangeUser(5e1,5e5);
  }

  if( var == "t1met" ){
	h_format->GetXaxis()->SetTitle("T1 corrected E_{T}^{miss} GeV");
	h_format->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
	// h_format->GetYaxis()->SetRangeUser(5e1,5e5);
  }

  if( var == "ht" ){
	h_format->GetXaxis()->SetTitle("H_{T} GeV");
	h_format->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
	// h_format->GetYaxis()->SetRangeUser(5e1,5e5);
  }

  if( var == "njets" ){
	h_format->GetXaxis()->SetTitle("N_{jets} GeV");
	h_format->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
	h_format->GetYaxis()->SetRangeUser(1e-1,5e6);
	// h_format->GetYaxis()->SetRangeUser(1e4,5e6);
  }

  h_format->SetLineWidth(2);
  h_format->GetYaxis()->SetTitleOffset(1.2);

  // h_format->Draw("axig");
  h_format->Draw("e1xo");

  stack->Draw("histsame");
  h_format->Draw("e1samexo");
  legend->Draw("same");
  
  // h_format->Scale(0);

  pad->RedrawAxis();
  
  string histtitle = Form("photon_%s_%s", var.c_str(), sel.c_str() );

  string outfile = outputdir+histtitle+".png";	
  c1->SaveAs(outfile.c_str());
  // outfile = outputdir+histtitle+".ps";
  // c1->SaveAs(outfile.c_str());
  return;
}
