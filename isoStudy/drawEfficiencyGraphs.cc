#include <iostream>

#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TGraph.h"
#include "TMultiGraph.h"

void drawEfficiencyGraphs()
{

  TFile * file = TFile::Open("hists.root","READ");
  
  TGraph * h_EA_els = dynamic_cast<TGraph*>(file->Get("EA_el")->Clone("h_EA_els"));
  TGraph * h_MR_els = dynamic_cast<TGraph*>(file->Get("MR_el")->Clone("h_MR_els"));

  h_EA_els->SetMarkerStyle(7);
  h_MR_els->SetMarkerStyle(7);

  h_EA_els->SetMarkerColor(kRed);
  h_MR_els->SetMarkerColor(kBlue);
  h_EA_els->GetYaxis()->SetRangeUser(.2,1);
  h_MR_els->GetYaxis()->SetRangeUser(.2,1);
  
  TCanvas * c_iso = new TCanvas("c_iso","",800,800);

  c_iso->cd();

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(h_MR_els,"Ap");
  mg->Add(h_EA_els,"Ap");

  mg->Draw();

  TLegend *l1 = new TLegend(0.6, 0.2, 0.9, 0.5);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_EA_els , "EA Iso"   , "p");
  l1->AddEntry( h_MR_els , "MR Iso"   , "p");
  l1->Draw("same");
  
  c_iso->SaveAs("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/eff_els.pdf");
  c_iso->SaveAs("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/eff_els.png");

  
  TGraph * h_EA_mus = dynamic_cast<TGraph*>(file->Get("EA_mu")->Clone("h_EA_mus"));
  TGraph * h_MR_mus = dynamic_cast<TGraph*>(file->Get("MR_mu")->Clone("h_MR_mus"));

  h_EA_mus->SetMarkerStyle(7);
  h_MR_mus->SetMarkerStyle(7);

  h_EA_mus->SetMarkerColor(kRed);
  h_MR_mus->SetMarkerColor(kBlue);
  h_EA_mus->GetYaxis()->SetRangeUser(.2,1);
  h_MR_mus->GetYaxis()->SetRangeUser(.2,1);
  
  TCanvas * c_iso2 = new TCanvas("c_iso2","",800,800);

  c_iso2->cd();

  TMultiGraph *mg2 = new TMultiGraph();
  mg2->Add(h_MR_mus,"Ap");
  mg2->Add(h_EA_mus,"Ap");

  mg2->Draw();

  TLegend *l2 = new TLegend(0.6, 0.2, 0.9, 0.5);    
  l2->SetLineColor(kWhite);    
  l2->SetShadowColor(kWhite);    
  l2->SetFillColor(kWhite);    
  l2->AddEntry( h_EA_mus , "EA Iso"   , "p");
  l2->AddEntry( h_MR_mus , "MR Iso"   , "p");
  l2->Draw("same");
  
  c_iso2->SaveAs("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/eff_mus.pdf");
  c_iso2->SaveAs("/home/users/cwelke/public_html/ZMET2015/plots/IsolationStudies/fkwMethod/eff_mus.png");

  return;
}
