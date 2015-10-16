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
  string variable = "pt";
  string region = "SRA_bveto";
  
  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root", iter.c_str() ));
  
  TChain * ch_gjets = new TChain("t");
  ch_gjets->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht*.root", iter.c_str() ));

  TH1F * zjets_ht_ll = new TH1F(Form("zjets_ht_ll_%s", region.c_str() ), "", 2000, 0 ,2000);
  TH1F * zincl_ht_ll = new TH1F(Form("zincl_ht_ll_%s", region.c_str() ), "", 2000, 0 ,2000);
  TH1F * gjets_ht_ll = new TH1F(Form("gjets_ht_ll_%s", region.c_str() ), "", 2000, 0 ,2000);

  zincl_ht_ll->Sumw2();
  zjets_ht_ll->Sumw2();
  gjets_ht_ll->Sumw2();  

  // TH1F * zjets_pt_ll = new TH1F(Form("zjets_pt_ll_%s", region.c_str() ), "", 1000, 0 ,1000);
  // TH1F * zincl_pt_ll = new TH1F(Form("zincl_pt_ll_%s", region.c_str() ), "", 1000, 0 ,1000);
  // TH1F * gjets_pt_ll = new TH1F(Form("gjets_pt_ll_%s", region.c_str() ), "", 1000, 0 ,1000);
  // zincl_pt_ll->Sumw2();
  // zjets_pt_ll->Sumw2();
  // gjets_pt_ll->Sumw2();

  // zjets_mll_mm_njet->Sumw2();
  // zjets_mll_ee_incl->Sumw2();
  // zjets_mll_mm_incl->Sumw2();

  TCut dilep = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && evt_type == 0";
  TCut photon = "ngamma > 0 && gamma_pt[0] > 22 && evt_type == 2 && gamma_hOverE[0] < 0.1 && matched_neutralemf > 0.7 && acos( cos( gamma_phi[0] - met_pt ) ) > 0.14 && !elveto";
  TCut ll = "hyp_type == 0 || hyp_type == 1";
  TCut ee = "hyp_type == 0";
  TCut mm = "hyp_type == 1";
  TCut em = "hyp_type == 2";
  TCut genhtlt = "gen_ht < 100";
  TCut genhtgt = "gen_ht > 100";
  TCut njets2 = "njets > 1";
  TCut njets3 = "njets > 3";
  TCut njets23 = "njets == 2 || njets == 3";
  TCut bveto = "nBJetMedium == 0";
  TCut SRA = "(njets == 2 || njets == 3) && ht > 600";
  TCut SRB = "njets >= 4";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb*10";
  TCut loosemll  = "dilmass > 76 && dilmass < 106";
  TCut mediummll = "dilmass > 81 && dilmass < 101";
  TCut tightmll  = "dilmass > 86 && dilmass < 96";
  TCut drll  = "dRll > 0.1";
  TCut btag = "nBJetMedium >= 1";
		 
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

  return;
}
  
