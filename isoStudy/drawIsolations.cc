#include <iostream>

#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TGraph.h"

void drawIsolations( std::string isotype = "EA", std::string leptype = "el" )
{

  TFile * file = TFile::Open("lepton_isolations.root","READ");
  
  TH1F * h_prompt = dynamic_cast<TH1F*>(file->Get(Form("h_%s_prompt_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_prompt"));
  TH1F * h_npromp = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_npromp"));

  // TH1F * h_prompt = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_prompt"));
  // isotype = "MR";
  // TH1F * h_npromp = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_npromp"));
  TH1F * h_alllep = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_alllep"));

  TH1F * h_inclusive_prompt = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_inclusive_prompt"));
  TH1F * h_inclusive_npromp = dynamic_cast<TH1F*>(file->Get(Form("h_%s_npromp_%siso", leptype.c_str(), isotype.c_str() ))->Clone("h_inclusive_npromp"));

  TCanvas * c_iso = new TCanvas("c_iso","",800,800);

  c_iso->cd();
  c_iso->SetLogy();

  h_alllep->Add(h_prompt);
  h_prompt->SetMarkerSize(0);
  h_npromp->SetMarkerSize(0);

  double total_prompt = h_prompt->GetSumOfWeights();
  double total_npromp = h_npromp->GetSumOfWeights();
  
  double scale_prompt = h_prompt->GetSumOfWeights()/(total_prompt+total_npromp);
  double scale_npromp = h_npromp->GetSumOfWeights()/(total_prompt+total_npromp);
  
  h_prompt->Scale(1.0/h_prompt->GetSumOfWeights());
  h_npromp->Scale(1.0/h_npromp->GetSumOfWeights());
  h_alllep->Scale(1.0/h_alllep->GetSumOfWeights());
  
  h_prompt->SetLineColor(kRed);
  h_npromp->SetLineColor(kBlue);
  
  if( h_prompt ){
	h_prompt->GetYaxis()->SetRangeUser(1e-4,1);
	h_prompt->GetYaxis()->SetTitle("Fraction");
	h_prompt->GetXaxis()->SetTitle(Form("%s Isolation", isotype.c_str()));
  }else{
	h_prompt->GetYaxis()->SetRangeUser(1e-4,1);
	h_prompt->GetYaxis()->SetTitle("Fraction");
	h_prompt->GetXaxis()->SetTitle(Form("%s Isolation", isotype.c_str()));
  }
  
  // if( h_prompt ) h_prompt->Draw("histe1");
  // else
	h_npromp->Draw("histe1");
  // h_npromp->Draw("histe1same");

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_prompt , "Prompt leps"       , "l");
  l1->AddEntry( h_npromp , "Non-prompt leps"   , "l");
  l1->Draw("same");

  c_iso->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/%s_iso_%s.pdf", isotype.c_str(), leptype.c_str() ));
  c_iso->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/%s_iso_%s.png", isotype.c_str(), leptype.c_str() ));

  double val_prompt = 0;
  double err_prompt = 0;

  double val_npromp = 0;
  double err_npromp = 0;

  double val_alllep = 0;
  double err_alllep = 0;

  float cutval = 0.1;
  if( isotype == "EA" ) cutval = 0.15;
  
  int lowbin = h_prompt->FindBin(cutval);
  
  val_prompt = h_prompt -> IntegralAndError( 0, lowbin-1, err_prompt );
  val_npromp = h_npromp -> IntegralAndError( 0, lowbin-1, err_npromp );
  val_alllep = h_alllep -> IntegralAndError( 0, lowbin-1, err_alllep );
  
  std::cout<<Form("Efficiency of     prompt %ss for iso cut of %.2f : %.3f", leptype.c_str(), cutval, (float)val_prompt )<<std::endl;
  std::cout<<Form("Efficiency of non-prompt %ss for iso cut of %.2f : %.3f", leptype.c_str(), cutval, (float)val_npromp )<<std::endl;

  std::cout<<Form("Percentage of     prompt %ss for iso cut of %.2f : %.3f", leptype.c_str(), cutval, (float)val_alllep*scale_prompt )<<std::endl;
  std::cout<<Form("Percentage of non-prompt %ss for iso cut of %.2f : %.3f", leptype.c_str(), cutval, (float)val_alllep*scale_npromp )<<std::endl;

  // val_prompt /= (h_prompt->GetSumOfWeights);  
  // val_prompt /= (h_prompt->GetSumOfWeights);  

  h_inclusive_prompt->Scale(0.0);
  h_inclusive_npromp->Scale(0.0);

  for( int bini = 0; bini < h_inclusive_npromp->GetNbinsX()+1; bini++ ){
	val_prompt = h_prompt -> IntegralAndError( 0, bini-1, err_prompt );
	h_inclusive_prompt->SetBinContent(bini, val_prompt);
	h_inclusive_prompt->SetBinError(bini, err_prompt);

  	val_npromp = h_npromp -> IntegralAndError( 0, bini-1, err_npromp );
	h_inclusive_npromp->SetBinContent(bini, val_npromp);
	h_inclusive_npromp->SetBinError(bini, err_npromp);
}

  TCanvas * c_inclusive = new TCanvas("c_inclusive","",800,800);

  c_inclusive->cd();
  // c_inclusive->SetLogy();

  // h_prompt->Scale(1.0/h_prompt->GetSumOfWeights());
  // h_npromp->Scale(1.0/h_npromp->GetSumOfWeights());
  
  h_inclusive_prompt->SetLineColor(kRed);
  h_inclusive_npromp->SetLineColor(kBlue);
  
  h_inclusive_prompt->SetMarkerSize(0);
  h_inclusive_npromp->SetMarkerSize(0);
  
  h_inclusive_prompt->GetYaxis()->SetRangeUser(1e-4,1);
  // h_prompt->GetYaxis()->SetTitle("Fraction");
  h_inclusive_prompt->GetYaxis()->SetTitle(Form("%s Isolation efficiency", isotype.c_str()));
  h_inclusive_prompt->GetXaxis()->SetTitle(Form("%s Isolation", isotype.c_str()));

  h_inclusive_prompt->Draw("histe1");
  h_inclusive_npromp->Draw("histe1same");

  TLegend *l2 = NULL;
  if( leptype == "mu" ) l2 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  if( leptype == "el" ) l2 = new TLegend(0.6, 0.2, 0.9, 0.50);    
  l2->SetLineColor(kWhite);    
  l2->SetShadowColor(kWhite);    
  l2->SetFillColor(kWhite);    
  l2->AddEntry( h_prompt , "Prompt leps"       , "l");
  l2->AddEntry( h_npromp , "Non-prompt leps"   , "l");
  l2->Draw("same");

  c_inclusive->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/%s_iso_%s_inclusive.pdf", isotype.c_str(), leptype.c_str() ));
  c_inclusive->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/%s_iso_%s_inclusive.png", isotype.c_str(), leptype.c_str() ));

  // TH1F * h_efp_efn = dynamic_cast<TH1F*>(h_inclusive_prompt->Clone("h_efp_efn"));
  
  // h_efp_efn->Scale(0.0);

  // for( int bini = 0; bini < h_efp_efn->GetNbinsX()+1; bini++ ){
  // 	int binind = h_inclusive_prompt->FindBin(h_inclusive_npromp->GetBinContent(bini));
  // 	h_efp_efn->SetBinContent(binind, h_inclusive_prompt->GetBinContent(bini));
  // }

  TCanvas * c_efpn = new TCanvas("c_efpn","",800,800);

  c_efpn->cd();

  Double_t x[100], y[100];
  Int_t n = 100;
  for (Int_t bini = 0; bini < n; bini++ ) {
	y[bini] = h_inclusive_prompt->GetBinContent(bini);
	x[bini] = h_inclusive_npromp->GetBinContent(bini);
  }
  TGraph * gr = new TGraph(n,x,y);
  gr->GetXaxis()->SetRangeUser(0,1);
  gr->GetYaxis()->SetRangeUser(0,1);
  gr->GetXaxis()->SetTitle("non-prompt efficiency");
  gr->GetYaxis()->SetTitle("prompt efficiency");
  gr->Draw("A*");

  //  h_efp_efn->GetXaxis()->SetTitle("efficiency prompt");
  // h_efp_efn->GetYaxis()->SetTitle("efficiency non-prompt");

  // h_efp_efn->GetXaxis()->SetRangeUser(0,1);
  // h_efp_efn->GetYaxis()->SetRangeUser(0,1);

  // h_efp_efn->Draw();

  // c_efpn->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/%s_iso_%s_efpn.png", isotype.c_str(), leptype.c_str() ));

  TFile * outfile = NULL;
  if( isotype == "EA" && leptype == "el" )
	outfile = TFile::Open("hists.root","RECREATE");
  else
	outfile = TFile::Open("hists.root","UPDATE");
  outfile->cd();
  gr->Write(Form("%s_%s", isotype.c_str(), leptype.c_str() ));
  outfile->Close();

  return;
}
