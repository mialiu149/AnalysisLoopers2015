#include <iostream>

#include "TFile.h"
#include "TCut.h"
#include "TH1F.h"
#include "TChain.h"
#include "TColor.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLine.h"
#include "TLegend.h"
#include "TStyle.h"

using namespace std;

void plothtandpt_ratio()
{

  string variable = "pt";
  
  TFile * f_2j = TFile::Open("htptplots.root");
  TFile * f_3j = TFile::Open("htptplots_3jets.root");

  TH1F * h_zpt_2j = dynamic_cast<TH1F*>(f_2j->Get(Form("zjets_%s_ll_SRA_bveto", variable.c_str() ))->Clone("h_zpt_2j"));
  TH1F * h_gpt_2j = dynamic_cast<TH1F*>(f_2j->Get(Form("gjets_%s_ll_SRA_bveto", variable.c_str() ))->Clone("h_gpt_2j"));
  TH1F * h_zpt_3j = dynamic_cast<TH1F*>(f_3j->Get(Form("zjets_%s_ll_SRA_bveto", variable.c_str() ))->Clone("h_zpt_3j"));
  TH1F * h_gpt_3j = dynamic_cast<TH1F*>(f_3j->Get(Form("gjets_%s_ll_SRA_bveto", variable.c_str() ))->Clone("h_gpt_3j"));

  h_zpt_2j->SetLineColor(kRed);
  h_zpt_3j->SetLineColor(kMagenta);
  h_gpt_2j->SetLineColor(kBlue);
  h_gpt_3j->SetLineColor(kGreen);

  vector <float> photon_htcuts;
  photon_htcuts.clear();
  photon_htcuts.push_back(50);
  photon_htcuts.push_back(100);
  photon_htcuts.push_back(150);
  photon_htcuts.push_back(200);
  photon_htcuts.push_back(400);
  photon_htcuts.push_back(600);
  if( variable == "ht" ) {
	photon_htcuts.clear();
	photon_htcuts.push_back(35);
	photon_htcuts.push_back(70);
	photon_htcuts.push_back(105);
	photon_htcuts.push_back(140);
	photon_htcuts.push_back(200);
	photon_htcuts.push_back(350);
	photon_htcuts.push_back(500);
	photon_htcuts.push_back(1000);
	photon_htcuts.push_back(1500);
	photon_htcuts.push_back(2000);
  }

  int nbinsx = photon_htcuts.size();
  double binsx[nbinsx+1];
  binsx[0] = 0;
  for( size_t binind = 0; binind < nbinsx; binind++ ){
	binsx[binind+1] = photon_htcuts.at(binind);	
  }
  
  h_zpt_2j = h_zpt_2j->Rebin(nbinsx, binsx, "h_zpt_2j_rebinned");
  h_zpt_3j = h_zpt_3j->Rebin(nbinsx, binsx, "h_zpt_3j_rebinned");
  h_gpt_2j = h_gpt_2j->Rebin(nbinsx, binsx, "h_gpt_2j_rebinned");
  h_gpt_3j = h_gpt_3j->Rebin(nbinsx, binsx, "h_gpt_3j_rebinned");
  
  h_gpt_2j->Scale(1./h_gpt_2j->GetSumOfWeights());
  h_gpt_3j->Scale(1./h_gpt_3j->GetSumOfWeights());
  h_zpt_2j->Scale(1./h_zpt_2j->GetSumOfWeights());
  h_zpt_3j->Scale(1./h_zpt_3j->GetSumOfWeights());

  // h_gpt_2j->Divide(h_zpt_2j);
  // h_gpt_3j->Divide(h_zpt_3j);
  h_zpt_2j->Divide(h_gpt_2j);
  h_zpt_3j->Divide(h_gpt_3j);
  
  h_zpt_2j->SetMarkerSize(0);
  h_zpt_3j->SetMarkerSize(0);
  h_gpt_2j->SetMarkerSize(0);
  h_gpt_3j->SetMarkerSize(0);

  float ymin = 2e-7; float ymax = 10;
  float xmin = 0; float xmax = 1000;
  if( variable == "ht" ){ xmin = 0; xmax = 2000;}
  
  h_gpt_2j->GetYaxis()->SetRangeUser(0,ymax);
  h_gpt_3j->GetYaxis()->SetRangeUser(0,ymax);
  h_zpt_2j->GetYaxis()->SetRangeUser(0,ymax);
  h_zpt_3j->GetYaxis()->SetRangeUser(0,ymax);

  TCanvas * c1 = new TCanvas("c1","",800,800);
  c1->cd();
  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  // pad->SetLogy();

  string variable_tag = "p";
  if( variable == "ht" ) variable_tag = "H";	
  
  h_zpt_2j->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));
  h_zpt_3j->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));
  h_gpt_2j->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));
  h_gpt_3j->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));

  h_zpt_2j->Draw("histe1");
  h_zpt_3j->Draw("histe1same");
  // h_gpt_2j->Draw("histe1");
  // h_gpt_3j->Draw("histe1same");

  TLine * bin = NULL;
  
  for( size_t vecind = 0; vecind < photon_htcuts.size(); vecind++ ){
	bin = new TLine(photon_htcuts.at(vecind), ymin, photon_htcuts.at(vecind), ymax);
	bin->SetLineStyle(2);
	bin->Draw("same");
  }
  
  TLegend *l1 = new TLegend(0.4, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_gpt_2j , Form("%s_{T}(#gamma)/%s_{T}(Z): 2 Jets" , variable_tag.c_str() , variable_tag.c_str() ), "le");
  l1->AddEntry( h_gpt_3j , Form("%s_{T}(#gamma)/%s_{T}(Z): 3 Jets" , variable_tag.c_str() , variable_tag.c_str() ), "le");

  c1->SaveAs(Form("../output/ZMET2015/V00-00-20/plots/Closure/h_%st_2vs3jets_ratioZtogamma.png", variable_tag.c_str() ));
  c1->SaveAs(Form("../output/ZMET2015/V00-00-20/plots/Closure/h_%st_2vs3jets_ratioZtogamma.pdf", variable_tag.c_str() ));
		
  return;
}
