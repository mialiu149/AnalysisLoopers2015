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

void drawZwindowPlots()
{

  // gStyle->SetOptStat(1101);
  
  TFile * file = TFile::Open("mll_hists.root");

  TH1F * h_mll_ee = dynamic_cast<TH1F*>(file->Get("zjets_mll_ee_incl")->Clone("h_mll_ee_incl"));
  h_mll_ee->Add(dynamic_cast<TH1F*>(file->Get("zjets_mll_ee_njet")->Clone("h_mll_ee_njet")));

  TH1F * h_mll_mm = dynamic_cast<TH1F*>(file->Get("zjets_mll_mm_incl")->Clone("h_mll_mm_incl"));
  h_mll_mm->Add(dynamic_cast<TH1F*>(file->Get("zjets_mll_mm_njet")->Clone("h_mll_mm_njet")));

  h_mll_ee->SetMarkerSize(0);
  h_mll_ee->SetLineColor(kBlue);

  h_mll_mm->SetMarkerSize(0);
  h_mll_mm->SetLineColor(kRed);

  h_mll_ee->GetXaxis()->SetTitle("m_{\\ell\\ell} [GeV]");
  h_mll_mm->GetXaxis()->SetTitle("m_{\\ell\\ell} [GeV]");

  h_mll_ee->GetYaxis()->SetTitle("Events/1 [GeV]");
  h_mll_mm->GetYaxis()->SetTitle("Events/1 [GeV]");

  h_mll_ee->Scale(10);
  h_mll_mm->Scale(10);

  h_mll_ee->GetYaxis()->SetRangeUser(2e1,2e6);
  h_mll_mm->GetYaxis()->SetRangeUser(2e1,2e6);

  // h_mll_ee->GetXaxis()->SetRangeUser(76,106);
  // h_mll_mm->GetXaxis()->SetRangeUser(76,106);

  TCanvas * c_met = new TCanvas("c_met","",800,800);
  c_met->cd();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
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
  l1->AddEntry( h_mll_ee , "ee events"       , "lpe");
  l1->AddEntry( h_mll_mm , "#mu#mu events"   , "lpe");

  h_mll_mm->Draw("histe1");
  h_mll_ee->Draw("histe1same");
  // h_mll_ee->Draw("histe1");
  cut_hi->Draw("same");
  cut_lo->Draw("same");
  l1->Draw("same");

  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll.pdf");
  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll.png");
  
  h_mll_mm->Draw("histe1");

  cut_hi->Draw("same");
  cut_lo->Draw("same");

  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll_mm.pdf");
  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll_mm.png");
  
  h_mll_ee->Draw("histe1");

  cut_hi->Draw("same");
  cut_lo->Draw("same");

  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll_ee.pdf");
  c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll_ee.png");

  float total_ee = h_mll_ee->Integral(h_mll_ee->FindBin(lobin-5), h_mll_ee->FindBin(hibin+5)-1);
  float total_mm = h_mll_mm->Integral(h_mll_mm->FindBin(lobin-5), h_mll_mm->FindBin(hibin+5)-1);

  float eff_ee = h_mll_ee->Integral(h_mll_ee->FindBin(lobin), h_mll_ee->FindBin(hibin)-1);
  float eff_mm = h_mll_mm->Integral(h_mll_mm->FindBin(lobin), h_mll_mm->FindBin(hibin)-1);

  float eff_ee_tight = h_mll_ee->Integral(h_mll_ee->FindBin(lobin+5), h_mll_ee->FindBin(hibin-5)-1);
  float eff_mm_tight = h_mll_mm->Integral(h_mll_mm->FindBin(lobin+5), h_mll_mm->FindBin(hibin-5)-1);

  cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f", lobin-5, hibin+5, total_ee)<<endl;
  cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f", lobin-5, hibin+5, total_mm)<<endl;

  cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_ee)<<endl;
  cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_mm)<<endl;
  cout<<Form("Total ee+mm Events in %.0f-%.0f GeV window: %.0f", lobin, hibin, eff_mm+eff_ee)<<endl;
  cout<<Form("Efficiency for ee in %.0f-%.0f GeV window: %.3f" , lobin, hibin, eff_ee/total_ee)<<endl;
  cout<<Form("Efficiency for mm in %.0f-%.0f GeV window: %.3f" , lobin, hibin, eff_mm/total_mm)<<endl;
  cout<<Form("Efficiency for ee+mm in %.0f-%.0f GeV window: %.3f", lobin, hibin, (eff_mm+eff_ee)/(total_mm+total_ee))<<endl;
  cout<<endl;  
  cout<<Form("Total ee Events in %.0f-%.0f GeV window: %.0f"     , lobin+5, hibin-5, eff_ee_tight)<<endl;
  cout<<Form("Total mm Events in %.0f-%.0f GeV window: %.0f"     , lobin+5, hibin-5, eff_mm_tight)<<endl;
  cout<<Form("Total ee+mm Events in %.0f-%.0f GeV window: %.0f"  , lobin+5, hibin-5, eff_mm_tight+eff_ee_tight)<<endl;
  cout<<Form("Efficiency for ee in %.0f-%.0f GeV window: %.3f"   , lobin+5, hibin-5, eff_ee_tight/total_ee)<<endl;
  cout<<Form("Efficiency for mm in %.0f-%.0f GeV window: %.3f"   , lobin+5, hibin-5, eff_mm_tight/total_mm)<<endl;
  cout<<Form("Efficiency for ee+mm in %.0f-%.0f GeV window: %.3f", lobin+5, hibin-5, (eff_mm_tight+eff_ee_tight)/(total_mm+total_ee))<<endl;

  //find peaks
  float peak_num = 0.0;
  float peak_den = 0.0;
  float peak_num_err = 0.0;
  for( int bini = h_mll_ee->FindBin(lobin-5); bini < h_mll_ee->FindBin(hibin+5); bini++ ){
	peak_num += (float)h_mll_ee->GetBinContent(bini)*h_mll_ee->GetBinLowEdge(bini);
	peak_den += (float)h_mll_ee->GetBinContent(bini);
	peak_num_err += pow(h_mll_ee->GetBinContent(bini),2)*pow((float)h_mll_ee->GetBinError(bini),2);
  }
  float peak_ee = peak_num/peak_den;
  float erro_ee = sqrt(peak_num_err)/peak_den;

  peak_num = 0.0;
  peak_den = 0.0;
  peak_num_err = 0.0;
  for( int bini = h_mll_mm->FindBin(lobin-5); bini < h_mll_mm->FindBin(hibin+5); bini++ ){
	peak_num += (float)h_mll_mm->GetBinContent(bini)*h_mll_mm->GetBinLowEdge(bini);
	peak_den += (float)h_mll_mm->GetBinContent(bini);
	peak_num_err += pow(h_mll_mm->GetBinContent(bini),2)*pow((float)h_mll_mm->GetBinError(bini),2);
  }
  float peak_mm = peak_num/peak_den;
  float erro_mm = sqrt(peak_num_err)/peak_den;

  // cout<<"Peak for ee: "<<peak_ee<<" +/- "<<erro_ee<<endl;  
  // cout<<"Peak for mm: "<<peak_mm<<" +/- "<<erro_mm<<endl;  
  cout<<"Peak for ee: "<<peak_ee<<endl;  
  cout<<"Peak for mm: "<<peak_mm<<endl;  
  return;
}
