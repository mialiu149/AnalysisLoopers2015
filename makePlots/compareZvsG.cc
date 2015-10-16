#include "TH1F.h"
#include "TFile.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPad.h"
#include "TCut.h"
#include "TChain.h"
#include "TColor.h"

#include <iostream>

#include "../sharedCode/histTools.cc"

using namespace std;

void compareZvsG()
{
  
  string iter     = "V00-00-20";
  string variable = "ht";
  
  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root", iter.c_str() ));
  
  TChain * ch_gjets = new TChain("t");
  ch_gjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht*.root", iter.c_str() ));

  TH1F * zjets_ht_ll_SRA_bveto = new TH1F("zjets_ht_ll_SRA_bveto", "", 2000, 0 ,2000);
  TH1F * zincl_ht_ll_SRA_bveto = new TH1F("zincl_ht_ll_SRA_bveto", "", 2000, 0 ,2000);
  zincl_ht_ll_SRA_bveto->Sumw2();
  TH1F * gjets_ht_ll_SRA_bveto = new TH1F("gjets_ht_ll_SRA_bveto", "", 2000, 0 ,2000);
  zjets_ht_ll_SRA_bveto->Sumw2();
  gjets_ht_ll_SRA_bveto->Sumw2();
  
  TH1F * zjets_pt_ll_SRA_bveto = new TH1F("zjets_pt_ll_SRA_bveto", "", 1000, 0 ,1000);
  TH1F * zincl_pt_ll_SRA_bveto = new TH1F("zincl_pt_ll_SRA_bveto", "", 1000, 0 ,1000);
  zincl_pt_ll_SRA_bveto->Sumw2();
  TH1F * gjets_pt_ll_SRA_bveto = new TH1F("gjets_pt_ll_SRA_bveto", "", 1000, 0 ,1000);
  zjets_pt_ll_SRA_bveto->Sumw2();
  gjets_pt_ll_SRA_bveto->Sumw2();

  // TH1F * zjets_ht_mm_njet = new TH1F("zjets_mll_mm_njet", "", 150, 50 ,200);
  // TH1F * zjets_ht_ee_incl = new TH1F("zjets_mll_ee_incl", "", 150, 50 ,200);
  // TH1F * zjets_ht_mm_incl = new TH1F("zjets_mll_mm_incl", "", 150, 50 ,200);

  // zjets_mll_mm_njet->Sumw2();
  // zjets_mll_ee_incl->Sumw2();
  // zjets_mll_mm_incl->Sumw2();

  TCut dilep = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && evt_type == 0";
  TCut photon = "ngamma > 0 && gamma_pt[0] > 22 && evt_type == 2 && gamma_hOverE[0] < 0.1 && matched_neutralemf > 0.7 && acos( cos( gamma_phi[0] - met_pt ) ) > 0.14 && !elveto";
 // && dilmass > 81 && dilmass < 101
  TCut ee = "hyp_type == 0";
  TCut mm = "hyp_type == 1";
  TCut genhtlt = "gen_ht < 100";
  TCut genhtgt = "gen_ht > 100";
  TCut njets2 = "njets > 1";
  TCut njets3 = "njets > 3";
  TCut njets23 = "njets == 2 || njets == 3";
  TCut bveto = "nBJetMedium == 0";
  TCut SRA = "(njets == 2 || njets == 3) && ht > 600";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb*10";
  TCut loosemll  = "dilmass > 76 && dilmass < 106";
  TCut mediummll = "dilmass > 81 && dilmass < 101";
  TCut tightmll  = "dilmass > 86 && dilmass < 96";
  TCut drll = "dRll > 0.1";
		 
  TCut selection = dilep;
  // selection += SRA;
  selection += njets3;
  selection += mediummll;
  selection += drll;
  selection += xitionveto;
  // selection += genhtlt;
  
  ch_zjets_inc -> Draw("min(ht, 1999.5)>>zincl_ht_ll_SRA_bveto", (selection + genhtlt)*weight );
  ch_zjets     -> Draw("min(ht, 1999.5)>>zjets_ht_ll_SRA_bveto", (selection          )*weight );
  zjets_ht_ll_SRA_bveto->Add(zincl_ht_ll_SRA_bveto);
  
  selection = photon;
  selection += njets3;
  // selection += SRA;
  // selection += bveto;
  // selection += genhtlt;
  
  ch_gjets     -> Draw("min(ht, 1999.5)>>gjets_ht_ll_SRA_bveto", (selection          )*weight );

  selection = dilep;
  // selection += SRA;
  selection += njets3;
  // selection += bveto;
  selection += mediummll;
  selection += drll;
  selection += xitionveto;
  // selection += genhtlt;
  
  ch_zjets_inc -> Draw("min(dilpt, 999.5)>>zincl_pt_ll_SRA_bveto", (selection + genhtlt)*weight );
  ch_zjets     -> Draw("min(dilpt, 999.5)>>zjets_pt_ll_SRA_bveto", (selection          )*weight );
  zjets_pt_ll_SRA_bveto->Add(zincl_pt_ll_SRA_bveto);

  selection = photon;
  selection += njets3;
  // selection += SRA;
  // selection += bveto;
  // selection += genhtlt;
  
  ch_gjets     -> Draw("min(gamma_pt[0], 999.5)>>gjets_pt_ll_SRA_bveto", (selection          )*weight );

  TFile * file = TFile::Open("htptplots_3jets.root","RECREATE");
  file->cd();
  zjets_ht_ll_SRA_bveto->Write();
  gjets_ht_ll_SRA_bveto->Write();
  zjets_pt_ll_SRA_bveto->Write();
  gjets_pt_ll_SRA_bveto->Write();
  file->Close();

  TCanvas * c1 = new TCanvas("c1","c1",800,800);
  c1->cd();
  c1->SetLogy();

  zjets_ht_ll_SRA_bveto->Rebin(10);
  gjets_ht_ll_SRA_bveto->Rebin(10);

  zjets_ht_ll_SRA_bveto->Scale(1./zjets_ht_ll_SRA_bveto->GetSumOfWeights());
  gjets_ht_ll_SRA_bveto->Scale(1./gjets_ht_ll_SRA_bveto->GetSumOfWeights());

  zjets_ht_ll_SRA_bveto->SetMarkerSize(0);
  gjets_ht_ll_SRA_bveto->SetMarkerSize(0);

  zjets_ht_ll_SRA_bveto->SetLineColor(kRed);
  gjets_ht_ll_SRA_bveto->SetLineColor(kBlue);

  // gjets_ht_ll_SRA_bveto->GetYaxis()->SetRangeUser(1e-6, 1e0);

  gjets_ht_ll_SRA_bveto->Draw("histe1");
  zjets_ht_ll_SRA_bveto->Draw("histe1same");
  gjets_ht_ll_SRA_bveto->Draw("histe1same");
  
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_compare_3jets.png", iter.c_str(), variable.c_str() ));
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_compare_3jets.pdf", iter.c_str(), variable.c_str() ));

  variable = "pt";
  
  zjets_pt_ll_SRA_bveto->Rebin(10);
  gjets_pt_ll_SRA_bveto->Rebin(10);

  zjets_pt_ll_SRA_bveto->Scale(1./zjets_pt_ll_SRA_bveto->GetSumOfWeights());
  gjets_pt_ll_SRA_bveto->Scale(1./gjets_pt_ll_SRA_bveto->GetSumOfWeights());

  zjets_pt_ll_SRA_bveto->SetMarkerSize(0);
  gjets_pt_ll_SRA_bveto->SetMarkerSize(0);

  zjets_pt_ll_SRA_bveto->SetLineColor(kRed);
  gjets_pt_ll_SRA_bveto->SetLineColor(kBlue);

  // gjets_pt_ll_SRA_bveto->GetYaxis()->SetRangeUser(1e-2, 1e7);

  gjets_pt_ll_SRA_bveto->Draw("histe1");
  zjets_pt_ll_SRA_bveto->Draw("histe1same");
  gjets_pt_ll_SRA_bveto->Draw("histe1same");
  
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_compare_3jets.png", iter.c_str(), variable.c_str() ));
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_compare_3jets.pdf", iter.c_str(), variable.c_str() ));

  //MAKE PLOTS

  // int rebin = 10;
  
  // h_ll->Rebin(rebin);
  // h_em->Rebin(rebin);

  // TCanvas * c1 = new TCanvas("c1","");
  // c1->cd();
  // // c1->SetLogy();

  // TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  // pad->SetBottomMargin(0.05);
  // pad->SetRightMargin(0.07);
  // pad->SetTopMargin(0.08);
  // pad->SetLeftMargin(0.18);
  // pad->Draw();
  // pad->cd();
  // if( variable == "met" ) pad->SetLogy();

  // h_ll->SetLineWidth(2);
  // h_em->SetFillColor(kCyan);
  // h_em->SetFillStyle(1001);
  
  // h_ll->GetXaxis()->SetLabelSize(0);
  // if( sample_test == "FS_BG" ){
  // 	// if( variable == "met" ) h_ll->GetYaxis()->SetRangeUser(1e-2,1e2);
  // 	if( variable == "met" ) h_ll->GetYaxis()->SetRangeUser(2e-0,2e3);
  // 	// if( variable == "mll" ) h_ll->GetYaxis()->SetRangeUser(0,5.5e2);
  // }
  
  // float xmax = 350;
  // updateoverflow( h_ll, xmax );
  // updateoverflow( h_em, xmax );
  
  // h_ll->GetYaxis()->SetLabelSize(0.05);
  // h_ll->GetYaxis()->SetTitleOffset(1.5);
  // h_ll->GetYaxis()->SetTitleSize(0.05);
  // h_ll->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  // h_ll->GetXaxis()->SetRangeUser(0,xmax);
  // h_ll->SetMarkerStyle(8);
  // h_ll->SetMarkerSize(0.75);

  // h_ll->Draw("e1");
  // h_em->Draw("samehist");
  // h_ll->Draw("samex0e1");
  
  // pad->RedrawAxis();

  // TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  // l1->SetLineColor(kWhite);    
  // l1->SetShadowColor(kWhite);    
  // l1->SetFillColor(kWhite);    
  // l1->AddEntry( h_ll , "ee+#mu#mu events"       , "lpe");
  // l1->AddEntry( h_em , "e#mu events"       , "f");
  // l1->Draw("same");
  
  // c1->cd();
	
  // TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  // rat_pad->SetBottomMargin(0.36);
  // rat_pad->SetRightMargin(0.07);
  // rat_pad->SetTopMargin(0.07);
  // rat_pad->SetLeftMargin(0.18);
  // rat_pad->Draw();
  // rat_pad->cd();
  // rat_pad->SetGridy();

  // TH1F* h_rat = (TH1F*)h_ll->Clone("h_rat");

  // h_rat->Divide(h_em);

  // // if( variable == "met" ) h_rat->GetYaxis()->SetRangeUser(8,13);
  // if( variable == "met" ) h_rat->GetYaxis()->SetRangeUser(.6,1.4);
  // if( variable == "mll" ) h_rat->GetYaxis()->SetRangeUser(0.75,1.25);
  // h_rat->GetYaxis()->SetLabelSize(0.12);
  // h_rat->GetXaxis()->SetLabelSize(0.12);
  // h_rat->GetYaxis()->SetNdivisions(5);

  // h_rat->GetYaxis()->SetTitle("#frac{ee+#mu#mu}{e#mu}");
  // h_rat->GetYaxis()->CenterTitle();
  // h_rat->GetYaxis()->SetTitleSize(0.12);
  // h_rat->GetYaxis()->SetTitleOffset(0.5);
  // // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  // if( variable == "met" ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  // if( variable == "mll" ) h_rat->GetXaxis()->SetTitle("m_{\\ell\\ell} GeV");

  // h_rat->GetXaxis()->SetTitleOffset(0.9);
  // h_rat->GetXaxis()->SetTitleSize(0.15);

  // h_rat->SetMarkerStyle(8);
  // h_rat->SetMarkerSize(0.75);

  // h_rat->Draw("e1x0");

  // TLine * xaxis = new TLine(0,1,xmax,1);
  // xaxis->SetLineWidth(2);
  // xaxis->Draw("same");  
 
  // drawCMSLatex( c1, luminosity );
  
  return;
}
  
