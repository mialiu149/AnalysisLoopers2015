#include <iostream>
#include <stdexcept>
#include <vector>

#include "TChain.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TColor.h"
#include "THStack.h"
#include "TCut.h"
#include "TH1F.h"
#include "TLine.h"

using namespace std;

void zjets_gjets_ht_comparison()
{


  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht100to200.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht200to400.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht400to600.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf_1.root");

  TChain * ch_gjets = new TChain("t");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht100to200.root"  );
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400.root"  );
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400_1.root");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600.root"  );
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600_1.root");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf.root"  );
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf_1.root");
  
  float lastxbin = 3500.0;
  int rebin = 25;

  TH1F * zjets_ht = new TH1F("zjets_ht", "", (int)lastxbin, 0 ,lastxbin);
  TH1F * gjets_ht = new TH1F("gjets_ht", "", (int)lastxbin, 0 ,lastxbin);

  zjets_ht->Sumw2();
  gjets_ht->Sumw2();
  
  //shared cuts
  TCut metcut = "met_rawPt > 150";
  TCut htcut = "ht_eta30 > 240";
  TCut njets2 = "njets_eta30 > 1";

  //zjets cuts
  TCut dilep = "nlep > 1 && lep_pt[0] > 20 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101";
  TCut xitionveto = "hyp_type == 0 && (abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb";

  TCut z_selection = "";
  z_selection += dilep;
  z_selection += htcut;
  z_selection += metcut;
  z_selection += njets2;
  z_selection += xitionveto;

  string plotvar = "ht_eta30";
  
  ch_zjets->Draw(Form("min(%f,%s)>>zjets_ht", lastxbin-0.5, plotvar.c_str())   ,  z_selection          *weight);

  //gjets cuts
  TCut photon     = "ngamma                      > 0";
  TCut pt22       = "gamma_pt[0]                 > 22";
  TCut hoe        = "gamma_hOverE[0]             < 0.1";
  TCut nemf       = "matched_neutralemf          > 0.7";
  // TCut notaligned = "acos( cos( gamma_phi[0] - met_rawPhi ) ) > 0.14 ";
  TCut elveto     = "!elveto";


  TCut g_selection = "";
  g_selection += photon;
  g_selection += pt22;
  g_selection += hoe;
  g_selection += nemf;
  // g_selection += notaligned;
  g_selection += elveto;

  g_selection += htcut;
  g_selection += metcut;
  g_selection += njets2;

  ch_gjets->Draw(Form("min(%f,%s)>>gjets_ht", lastxbin-0.5, plotvar.c_str())    ,  g_selection          *weight);

  // vector <float> metcut;
  // // metcut.push_back(0.0);
  // // // metcut.push_back(60);
  // // metcut.push_back(70);
  // // metcut.push_back(80);
  // // metcut.push_back(90);
  // // metcut.push_back(100);
  // // // metcut.push_back(150);
  // // metcut.push_back(200);
  // // // metcut.push_back(300);
  // // metcut.push_back(-1);

  // metcut.push_back(0.0);
  // metcut.push_back(60);
  // metcut.push_back(130);
  // metcut.push_back(200);
  // metcut.push_back(300);
  // metcut.push_back(-1);

  // // vector <int> metbin;
  // // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // // 	metbin.push_back(zjets_ht->FindBin(metcut.at(bini)));
  // // }
  
  // vector <double> val_zjets;
  // vector <double> err_zjets;

  // vector <double> val_gjets;
  // vector <double> err_gjets;

  // for( size_t i = 0; i < metcut.size(); i++ ){
  // 	val_zjets.push_back(0);
  // 	err_zjets.push_back(0);
  // 	val_gjets.push_back(0);
  // 	err_gjets.push_back(0);
  // }

  // for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
  // 	// cout<<"Integral over: "<<metcut.at(bini)<<" | "<<metcut.at(bini+1)<<endl;
  // 	if( bini < metcut.size()-1 ){
  // 	  val_zjets.at(bini) = zjets_ht->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_zjets.at(bini));
  // 	  val_gjets.at(bini) = gjets_ht->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_gjets.at(bini));
  // 	}
  // 	if( bini == metcut.size()-1 ){
  // 	  val_zjets.at(bini) = zjets_ht->IntegralAndError( metcut.at(bini), -1, err_zjets.at(bini));
  // 	  val_gjets.at(bini) = gjets_ht->IntegralAndError( metcut.at(bini), -1, err_gjets.at(bini));
  // 	}
  // }
  
  // cout<<" $E_{T}^{miss} [GeV]$ &";
  // for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
  // 	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  // }
  // cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  // cout<<endl;

  // cout<<"\\hline "<<endl;
  // cout<<"zjets& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini), err_zjets.at(bini));
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini), err_zjets.at(bini));
  // }
  // cout<<endl;

  // cout<<"gjets& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_gjets.at(bini), err_gjets.at(bini));
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_gjets.at(bini), err_gjets.at(bini));
  // }
  // cout<<endl;

  // cout<<"\\hline "<<endl;

  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_zjets.at(bini)
  // 										  +val_gjets.at(bini)), sqrt(pow(err_zjets.at(bini),2)
  // 																	 +pow(err_gjets.at(bini),2)));
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_zjets.at(bini)
  // 											 +val_gjets.at(bini)), sqrt(pow(err_zjets.at(bini),2)
  // 																		+pow(err_gjets.at(bini),2)));
  // }
  // cout<<endl;
  // cout<<endl;

  TCanvas * c_met = new TCanvas("c_met","",800,800);

  c_met->cd();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  pad->SetBottomMargin(0.08);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogy();

  // zjets_ht = (TH1F*)zjets_ht->Rebin(rebin);
  // gjets_ht = (TH1F*)gjets_ht->Rebin(rebin);

  const int nbins = 12;
  double xbinning[nbins+1] = {0,240,280,320,360,400,500,1000,1500,2000,2500,3000,3500};
  
  zjets_ht = (TH1F*)zjets_ht->Rebin(nbins,"zjets_ht_rebinned",xbinning);
  gjets_ht = (TH1F*)gjets_ht->Rebin(nbins,"gjets_ht_rebinned",xbinning);

  // float allevents = zjets_ht->GetSumOfWeights() + gjets_ht->GetSumOfWeights();
  
  zjets_ht->Scale(1.0/zjets_ht->GetSumOfWeights());
  gjets_ht->Scale(1.0/gjets_ht->GetSumOfWeights());

  // zjets_ht->SetFillColor(kRed);
  // gjets_ht->SetFillColor(kYellow);

  zjets_ht->SetLineColor(kRed);
  gjets_ht->SetLineColor(kBlue);

  zjets_ht->SetMarkerSize(0);
  gjets_ht->SetMarkerSize(0);

  // zjets_ht->SetFillStyle(1001);
  // gjets_ht->SetFillStyle(1001);

  // zjets_ht->GetXaxis()->SetTitle("E^{miss}_{T}");
  zjets_ht->GetXaxis()->SetTitle("");
  zjets_ht->GetXaxis()->SetLabelSize(0);
  zjets_ht->GetYaxis()->SetTitle("Fraction");
	
  zjets_ht->GetYaxis()->SetRangeUser(2e-3,1);

  zjets_ht->Draw("histe1");
  gjets_ht->Draw("samehiste1");
  c_met->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( zjets_ht , "Z+jets"       , "f");
  l1->AddEntry( gjets_ht , "#gamma+jets"       , "f");
  l1->Draw("same");

  c_met->cd();
	
  TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  rat_pad->SetBottomMargin(0.36);
  rat_pad->SetRightMargin(0.07);
  rat_pad->SetTopMargin(0.07);
  rat_pad->SetLeftMargin(0.18);
  rat_pad->Draw();
  rat_pad->cd();
  rat_pad->SetGridy();

  TH1F* h_rat = (TH1F*)zjets_ht->Clone("h_rat");

  h_rat->Divide(gjets_ht);

  h_rat->GetYaxis()->SetRangeUser(0,2);
  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);

  h_rat->GetYaxis()->SetTitle("#frac{Z+jets}{#gamma+jets}");
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.65);
  // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  h_rat->GetXaxis()->SetTitle("H_{T} GeV");
  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);

  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);
  h_rat->SetLineColor(kBlack);

  h_rat->Draw("e1x0");

  TLine * xaxis = new TLine(0,1,lastxbin,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  

  
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/HT_gjetsVSZjets_comparison_13TeV.pdf");
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/HT_gjetsVSZjets_comparison_13TeV.png");
  
  return;
}
