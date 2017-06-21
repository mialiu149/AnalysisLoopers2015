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

#include "../sharedCode/histTools.cc"
#include "../sharedCode/METTemplateSelections.cc"

using namespace std;

void drawReweightingHists( string region = "2jets_inclusive" )
{

  string variable_tag = "p";	  
  bool variableBinning = true;
  
  METTemplates mettemplates( region );
  mettemplates.setBins     ( region );

  std::vector <int> nj_bins = mettemplates.get_nj_bins();

  TFile * outfile = TFile::Open(Form("reweightfiles/ratios_%s.root", region.c_str() ),"RECREATE");

  TFile * f_2j = TFile::Open( Form("ntuples/reweighting_hists_%s.root", region.c_str()) );

  float ymin = 2e-7; float ymax = 1;
  float xmin = 0; float xmax = 1200;  

  map <string, TH1F *> m_zpt;
  map <string, TH1F *> m_gpt;

  for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){

	string histname = Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	m_zpt.insert( make_pair(histname, dynamic_cast<TH1F*>(f_2j->Get(Form("zjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Clone(histname.c_str()))));
	m_zpt.at( histname )->SetLineColor(kBlue);
	m_zpt.at( histname )->SetLineWidth(2);
	m_zpt.at( histname )->SetMarkerSize(0);
	updateoverflow( m_zpt.at( histname ), xmax );

	histname = Form("h_zpt_em_%s_%i", region.c_str(), nj_bins.at(njetsind));
	m_zpt.insert( make_pair(histname, dynamic_cast<TH1F*>(f_2j->Get(Form("zjets_pt_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Clone(histname.c_str()))));
	m_zpt.at( histname )->SetLineColor(kGreen);
	m_zpt.at( histname )->SetLineWidth(2);
	m_zpt.at( histname )->SetMarkerSize(0);
	updateoverflow( m_zpt.at( histname ), xmax );

	histname = Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	m_gpt.insert( make_pair(histname, dynamic_cast<TH1F*>(f_2j->Get(Form("gjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Clone(histname.c_str()))));
	m_gpt.at( histname )->SetLineColor(kRed);
	m_gpt.at( histname )->SetLineWidth(2);
	m_gpt.at( histname )->SetMarkerSize(0);
	updateoverflow( m_gpt.at( histname ), xmax );

  }

  vector <float> photon_htcuts;
  if( region == "2jets_inclusive" ){
	photon_htcuts.clear();
	photon_htcuts.push_back(0  );
	// // photon_htcuts.push_back(10  );
	// photon_htcuts.push_back(22 );
	// photon_htcuts.push_back(30 );
	// photon_htcuts.push_back(36 );
	// photon_htcuts.push_back(50 );
	// photon_htcuts.push_back(75 );
	photon_htcuts.push_back(80 );
	photon_htcuts.push_back(90 );
	photon_htcuts.push_back(100);
	photon_htcuts.push_back(110);
	photon_htcuts.push_back(120);
	photon_htcuts.push_back(130);
	photon_htcuts.push_back(140);
	photon_htcuts.push_back(150);
	photon_htcuts.push_back(160);
	photon_htcuts.push_back(170);
	photon_htcuts.push_back(180);
	photon_htcuts.push_back(190);
	photon_htcuts.push_back(200);
	// // photon_htcuts.push_back(210);
	// // photon_htcuts.push_back(220);
	photon_htcuts.push_back(225);
	// // photon_htcuts.push_back(230);
	// // photon_htcuts.push_back(240);
	photon_htcuts.push_back(250);
	// // photon_htcuts.push_back(260);
	// // photon_htcuts.push_back(270);
	photon_htcuts.push_back(275);
	// // photon_htcuts.push_back(280);
	// // photon_htcuts.push_back(290);
	photon_htcuts.push_back(300);
	// photon_htcuts.push_back(350);
	photon_htcuts.push_back(400);
	photon_htcuts.push_back(500);
	photon_htcuts.push_back(600);
	// photon_htcuts.push_back(800);
	// photon_htcuts.push_back(1000);
	photon_htcuts.push_back(xmax);
  }

  else if( region == "3jets_inclusive" ){
	photon_htcuts.clear();
	photon_htcuts.push_back(0  );
	photon_htcuts.push_back(50 );
	photon_htcuts.push_back(100);
	photon_htcuts.push_back(150);
	photon_htcuts.push_back(200);
	photon_htcuts.push_back(300);
	photon_htcuts.push_back(400);
	photon_htcuts.push_back(500);
	photon_htcuts.push_back(600);
	photon_htcuts.push_back(xmax);
  }

  else if( region == "SRA_bveto" || region == "SRA_withb" ){
	photon_htcuts.clear();
	photon_htcuts.push_back(0  );
	photon_htcuts.push_back(50 );
	photon_htcuts.push_back(100);
	photon_htcuts.push_back(150);
	photon_htcuts.push_back(200);
	photon_htcuts.push_back(250);
	photon_htcuts.push_back(300);
	photon_htcuts.push_back(350);
	photon_htcuts.push_back(400);
	photon_htcuts.push_back(450);
	photon_htcuts.push_back(500);
	photon_htcuts.push_back(550);
	photon_htcuts.push_back(600);
	photon_htcuts.push_back(700);
	photon_htcuts.push_back(xmax);
  }

  else if( region == "SRB_bveto" || region == "SRB_withb" ){
	photon_htcuts.clear();
	photon_htcuts.push_back(0  );
	photon_htcuts.push_back(50 );
	photon_htcuts.push_back(100);
	photon_htcuts.push_back(150);
	photon_htcuts.push_back(200);
	photon_htcuts.push_back(250);
	photon_htcuts.push_back(300);
	photon_htcuts.push_back(350);
	photon_htcuts.push_back(400);
	photon_htcuts.push_back(450);
	photon_htcuts.push_back(500);
	photon_htcuts.push_back(550);
	photon_htcuts.push_back(600);
	photon_htcuts.push_back(xmax);
  }
  else{
	variableBinning = false;
  }
  
  // TLine * bin = NULL;
  //   for( size_t vecind = 0; vecind < photon_htcuts.size(); vecind++ ){
  // 	bin = new TLine(photon_htcuts.at(vecind), ymin, photon_htcuts.at(vecind), ymax);
  // 	bin->SetLineStyle(2);
  // 	bin->Draw("same");
  // }
  
  int nbinsx = photon_htcuts.size() - 1;
  double xbins[nbinsx];

  for( size_t binind = 0; binind < photon_htcuts.size(); binind++ ){
	xbins[binind] = photon_htcuts.at(binind);	
  }
  
  TCanvas * c1 = new TCanvas("c1","",800,800);
  c1->cd();
  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogy();

  TH1F * h_zpt = NULL;
  TH1F * h_gpt = NULL;

  TH1F * h_ratio = NULL;
  TH1F * h_denom = NULL;

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    

  // rebin
  for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){

	pad->SetLogy();
	
	if( variableBinning ){
	  string histname = Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_zpt.at( histname ) = (TH1F*)m_zpt.at( histname )->Rebin(nbinsx, (histname + "_rebinned").c_str(), xbins);
	  histname = Form("h_zpt_em_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_zpt.at( histname ) = (TH1F*)m_zpt.at( histname )->Rebin(nbinsx, (histname + "_rebinned").c_str(), xbins);
	  histname = Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_gpt.at( histname ) = (TH1F*)m_gpt.at( histname )->Rebin(nbinsx, (histname + "_rebinned").c_str(), xbins);	
	}
	else{
	  m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) ) -> Rebin(10);
	  m_zpt.at( Form("h_zpt_em_%s_%i", region.c_str(), nj_bins.at(njetsind)) ) -> Rebin(10);
	  m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) ) -> Rebin(10);	
	}

	// rescale bins
	for( size_t binind = 0; binind < (size_t)m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetNbinsX() + 1; binind++ ){
	  string histname = Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_zpt.at( histname )->SetBinContent(binind, m_zpt.at(histname)->GetBinContent(binind)*1/(m_zpt.at(histname)->GetBinWidth(binind)/10.));
	  m_zpt.at( histname )->SetBinError(  binind, m_zpt.at(histname)->GetBinError(  binind)*1/(m_zpt.at(histname)->GetBinWidth(binind)/10.));

	  histname = Form("h_zpt_em_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_zpt.at( histname )->SetBinContent(binind, m_zpt.at(histname)->GetBinContent(binind)*1/(m_zpt.at(histname)->GetBinWidth(binind)/10.));
	  m_zpt.at( histname )->SetBinError(  binind, m_zpt.at(histname)->GetBinError(  binind)*1/(m_zpt.at(histname)->GetBinWidth(binind)/10.));

	  histname = Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind));
	  m_gpt.at( histname )->SetBinContent(binind, m_gpt.at(histname)->GetBinContent(binind)*1/(m_gpt.at(histname)->GetBinWidth(binind)/10.));
	  m_gpt.at( histname )->SetBinError(  binind, m_gpt.at(histname)->GetBinError(  binind)*1/(m_gpt.at(histname)->GetBinWidth(binind)/10.));
	}
  
	// subtract OF events
	m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->Add(m_zpt.at( Form("h_zpt_em_%s_%i", region.c_str(), nj_bins.at(njetsind))), -1);

	// set low pT bins = 1
	// m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->SetBinContent(1, 1);
	// m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->SetBinContent(1, 1);

	// normalize
	m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->Scale(1/(m_zpt.at(Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)))->GetSumOfWeights()));
	m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->Scale(1/(m_gpt.at(Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)))->GetSumOfWeights()));

	if( TString(region).Contains("SRA") ) ymin = 1e-5;

	m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetYaxis()->SetRangeUser(ymin, ymax);
	m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetYaxis()->SetRangeUser(ymin, ymax);
	m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetXaxis()->SetRangeUser(xmin, xmax);
	m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetXaxis()->SetRangeUser(xmin, xmax);

	m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));
	m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) )->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));

	h_zpt = m_zpt.at( Form("h_zpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) );
	h_gpt = m_gpt.at( Form("h_gpt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind)) );

	h_zpt->Draw("histe1");
	h_gpt->Draw("histe1same");

	if( njetsind == 0 ){
	  l1->AddEntry( h_zpt, "Z + jets"     , "le");
	  l1->AddEntry( h_gpt, "#gamma + jets", "le");
	}
	
	l1->Draw("same");
 
	c1->SaveAs(Form("../output/ZMET2015/V00-00-21/plots/Reweighting/h_%st_%s_%ijets.png", variable_tag.c_str(), region.c_str(), nj_bins.at(njetsind) ));
	c1->SaveAs(Form("../output/ZMET2015/V00-00-21/plots/Reweighting/h_%st_%s_%ijets.pdf", variable_tag.c_str(), region.c_str(), nj_bins.at(njetsind) ));
	
	h_ratio = dynamic_cast<TH1F*>(h_zpt->Clone(Form("h_ratio_%i", nj_bins.at(njetsind) )));
	h_denom = dynamic_cast<TH1F*>(h_gpt->Clone(Form("h_denom_%i", nj_bins.at(njetsind) )));

	h_ratio->SetMarkerSize(0);
	h_denom->SetMarkerSize(0);

	h_ratio->SetBinContent(1, 0);
	// h_denom->SetBinContent(1, 1);

	h_ratio->Divide(h_denom);

	h_ratio->GetYaxis()->SetRangeUser(0,15);
	// h_ratio->GetYaxis()->SetNdivisions(5);
  
	pad->SetLogy(0);
  
	h_ratio->SetLineColor(kBlack);
	h_ratio->SetLineWidth(kBlack);
	h_ratio->GetYaxis()->SetTitle("Z+jets/#gamma+jets");
	h_ratio->Draw("histe1");

	c1->SaveAs(Form("../output/ZMET2015/V00-00-21/plots/Reweighting/h_%st_ratio_%s_%i.png", variable_tag.c_str(), region.c_str(), nj_bins.at(njetsind) ));
	c1->SaveAs(Form("../output/ZMET2015/V00-00-21/plots/Reweighting/h_%st_ratio_%s_%i.pdf", variable_tag.c_str(), region.c_str(), nj_bins.at(njetsind) ));

	outfile->cd();
	h_ratio->Write();

  }
  
  // h_ratio->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));
  // h_denom->GetXaxis()->SetTitle(Form("%s_{T} [GeV]", variable_tag.c_str() ));


  outfile->Close();

  
  return;
}
