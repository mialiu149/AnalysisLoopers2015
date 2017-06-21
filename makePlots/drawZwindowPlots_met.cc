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

void drawZwindowPlots_met()
{

  string mllwindow = "loose";
  // mllwindow = "medium";
  // mllwindow = "tight";
  // gStyle->SetOptStat(1101);
  
  TFile * file = TFile::Open("mll_hists.root");

  TH1F * h_met_ee = dynamic_cast<TH1F*>(file->Get(Form("zjets_met_%s_ee_incl", mllwindow.c_str() ))->Clone("h_met_ee_incl"));
  h_met_ee->Add(dynamic_cast<TH1F*>(    file->Get(Form("zjets_met_%s_ee_njet", mllwindow.c_str() ))->Clone("h_met_ee_njet")));

  TH1F * h_met_mm = dynamic_cast<TH1F*>(file->Get(Form("zjets_met_%s_mm_incl", mllwindow.c_str() ))->Clone("h_met_mm_incl"));
  h_met_mm->Add(dynamic_cast<TH1F*>(    file->Get(Form("zjets_met_%s_mm_njet", mllwindow.c_str() ))->Clone("h_met_mm_njet")));

  h_met_ee->SetMarkerSize(0);
  h_met_ee->SetLineColor(kBlue);

  h_met_mm->SetMarkerSize(0);
  h_met_mm->SetLineColor(kRed);

  h_met_ee->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  h_met_mm->GetXaxis()->SetTitle("");
  h_met_mm->GetXaxis()->SetLabelSize(0);

  h_met_ee->GetYaxis()->SetTitle("Fraction");
  h_met_mm->GetYaxis()->SetTitle("Fraction");

  // h_met_ee->GetYaxis()->SetTitle("Events/1 [GeV]");
  // h_met_mm->GetYaxis()->SetTitle("Events/1 [GeV]");

  h_met_ee->Scale(1.0/h_met_ee->GetSumOfWeights());
  h_met_mm->Scale(1.0/h_met_mm->GetSumOfWeights());

  h_met_ee->Rebin(10);
  h_met_mm->Rebin(10);

  h_met_mm->SetLineWidth(2);

  // h_met_ee->GetYaxis()->SetRangeUser(2e1,2e6);
  // h_met_mm->GetYaxis()->SetRangeUser(2e1,2e6);

  // h_met_ee->GetXaxis()->SetRangeUser(76,106);
  // h_met_mm->GetXaxis()->SetRangeUser(76,106);

  TCanvas * c_met = new TCanvas("c_met","",800,800);
  c_met->cd();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogy();

  float lobin = 81;
  float hibin = 101;
  
  TLine * cut_lo = new TLine( lobin-5, 2e1, lobin-5, 2e6);
  TLine * cut_hi = new TLine( hibin+5, 2e1, hibin+5, 2e6);
  
  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_met_ee , "ee events"       , "lpe");
  l1->AddEntry( h_met_mm , "#mu#mu events"   , "lpe");

  h_met_mm->Draw("histe1");
  h_met_ee->Draw("histe1same");
  // h_met_ee->Draw("histe1");
  // cut_hi->Draw("same");
  // cut_lo->Draw("same");
  l1->Draw("same");

  c_met->cd();

  TPad *p_rat = new TPad( "p_rat", "p_rat", 0.0, 0.0, 1.0, 0.3);
  p_rat->SetBottomMargin(0.36);
  p_rat->SetRightMargin(0.07);
  p_rat->SetTopMargin(0.07);
  p_rat->SetLeftMargin(0.18);
  // p_rat->SetBottomMargin(0.12);
  // p_rat->SetRightMargin(0.07);
  // p_rat->SetTopMargin(0.07);
  // p_rat->SetLeftMargin(0.18);
  p_rat->Draw();
  p_rat->cd();
  p_rat->SetGridy();

  TH1F * h_ratio = dynamic_cast<TH1F*>(h_met_ee->Clone("h_ratio"));
  h_ratio->Divide(h_met_mm);

  h_ratio->GetYaxis()->SetRangeUser(0,2);
  h_ratio->GetYaxis()->SetLabelSize(0.12);
  h_ratio->GetXaxis()->SetLabelSize(0.12);
  h_ratio->GetYaxis()->SetNdivisions(5);

  h_ratio->GetYaxis()->SetTitle("Z\\rightarrow ee/Z\\rightarrow \\mu\\mu");
  h_ratio->GetYaxis()->SetTitleSize(0.12);
  h_ratio->GetYaxis()->SetTitleOffset(0.55);
  // cout<<h_ratio->GetYaxis()->GetTitleSize()<<endl;

  h_ratio->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  h_ratio->GetXaxis()->SetTitleOffset(0.9);
  h_ratio->GetXaxis()->SetTitleSize(0.15);
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetLineWidth(1);
  h_ratio->Draw("histe1");

  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_%s.pdf", mllwindow.c_str() ));
  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_%s.png", mllwindow.c_str() ));
  
  c_met->cd();
  c_met->SetLogy();
  h_met_mm->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  h_met_mm->Draw("histe1");

  cut_hi->Draw("same");
  cut_lo->Draw("same");

  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_mm_%s.pdf", mllwindow.c_str() ));
  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_mm_%s.png", mllwindow.c_str() ));
  
  h_met_ee->Draw("histe1");

  cut_hi->Draw("same");
  cut_lo->Draw("same");

  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_ee_%s.pdf", mllwindow.c_str() ));
  c_met->SaveAs(Form("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/met_ee_%s.png", mllwindow.c_str() ));

  // float total_ee = h_mll_ee->Integral(h_mll_ee->FindBin(lobin-5), h_mll_ee->FindBin(hibin+5)-1);
  // float total_mm = h_mll_mm->Integral(h_mll_mm->FindBin(lobin-5), h_mll_mm->FindBin(hibin+5)-1);

  // float eff_ee = h_mll_ee->Integral(h_mll_ee->FindBin(lobin), h_mll_ee->FindBin(hibin)-1);
  // float eff_mm = h_mll_mm->Integral(h_mll_mm->FindBin(lobin), h_mll_mm->FindBin(hibin)-1);

  // float eff_ee_tight = h_mll_ee->Integral(h_mll_ee->FindBin(lobin+5), h_mll_ee->FindBin(hibin-5)-1);
  // float eff_mm_tight = h_mll_mm->Integral(h_mll_mm->FindBin(lobin+5), h_mll_mm->FindBin(hibin-5)-1);

  // cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f", lobin-5, hibin+5, total_ee)<<endl;
  // cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f", lobin-5, hibin+5, total_mm)<<endl;

  // cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_ee)<<endl;
  // cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_mm)<<endl;
  // cout<<Form("Total ee+mm Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_mm+eff_ee)<<endl;
  // cout<<Form("Efficiency for ee in %.0f-%.0f GeV window: %.3f" , lobin, hibin, eff_ee/total_ee)<<endl;
  // cout<<Form("Efficiency for mm in %.0f-%.0f GeV window: %.3f" , lobin, hibin, eff_mm/total_mm)<<endl;
  // cout<<Form("Efficiency for ee+mm in %.0f-%.0f GeV window: %.3f", lobin, hibin, (eff_mm+eff_ee)/(total_mm+total_ee))<<endl;
  // cout<<endl;  
  // cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f"     , lobin+5, hibin-5, eff_ee_tight)<<endl;
  // cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f"     , lobin+5, hibin-5, eff_mm_tight)<<endl;
  // cout<<Form("Total ee+mm Events in %.0f-%.0f GeV window: %.0f"  , lobin+5, hibin-5, eff_mm_tight+eff_ee_tight)<<endl;
  // cout<<Form("Efficiency for ee in %.0f-%.0f GeV window: %.3f"   , lobin+5, hibin-5, eff_ee_tight/total_ee)<<endl;
  // cout<<Form("Efficiency for mm in %.0f-%.0f GeV window: %.3f"   , lobin+5, hibin-5, eff_mm_tight/total_mm)<<endl;
  // cout<<Form("Efficiency for ee+mm in %.0f-%.0f GeV window: %.3f", lobin+5, hibin-5, (eff_mm_tight+eff_ee_tight)/(total_mm+total_ee))<<endl;

  // //find peaks
  // float peak_num = 0.0;
  // float peak_den = 0.0;
  // float peak_num_err = 0.0;
  // for( int bini = h_mll_ee->FindBin(lobin-5); bini < h_mll_ee->FindBin(hibin+5); bini++ ){
  // 	peak_num += (float)h_mll_ee->GetBinContent(bini)*h_mll_ee->GetBinLowEdge(bini);
  // 	peak_den += (float)h_mll_ee->GetBinContent(bini);
  // 	peak_num_err += pow(h_mll_ee->GetBinContent(bini),2)*pow((float)h_mll_ee->GetBinError(bini),2);
  // }
  // float peak_ee = peak_num/peak_den;
  // float erro_ee = sqrt(peak_num_err)/peak_den;

  // peak_num = 0.0;
  // peak_den = 0.0;
  // peak_num_err = 0.0;
  // for( int bini = h_mll_mm->FindBin(lobin-5); bini < h_mll_mm->FindBin(hibin+5); bini++ ){
  // 	peak_num += (float)h_mll_mm->GetBinContent(bini)*h_mll_mm->GetBinLowEdge(bini);
  // 	peak_den += (float)h_mll_mm->GetBinContent(bini);
  // 	peak_num_err += pow(h_mll_mm->GetBinContent(bini),2)*pow((float)h_mll_mm->GetBinError(bini),2);
  // }
  // float peak_mm = peak_num/peak_den;
  // float erro_mm = sqrt(peak_num_err)/peak_den;

  // // cout<<"Peak for ee: "<<peak_ee<<" +/- "<<erro_ee<<endl;  
  // // cout<<"Peak for mm: "<<peak_mm<<" +/- "<<erro_mm<<endl;  
  // cout<<"Peak for ee: "<<peak_ee<<endl;  
  // cout<<"Peak for mm: "<<peak_mm<<endl;  
  return;
}
