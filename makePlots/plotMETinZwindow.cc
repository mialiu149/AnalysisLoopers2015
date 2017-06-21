#include <iostream>

#include "TFile.h"
#include "TCut.h"
#include "TH1F.h"
#include "TChain.h"

using namespace std;

void plotMETinZwindow()
{

  // TFile * file = TFile::Open("");

  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht100to200*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht200to400*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht400to600*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf*.root");

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_m50inc*.root");
  
  TH1F * zjets_mll_ee_njet = new TH1F("zjets_mll_ee_njet", "", 150, 50 ,200);
  TH1F * zjets_mll_mm_njet = new TH1F("zjets_mll_mm_njet", "", 150, 50 ,200);
  TH1F * zjets_mll_ee_incl = new TH1F("zjets_mll_ee_incl", "", 150, 50 ,200);
  TH1F * zjets_mll_mm_incl = new TH1F("zjets_mll_mm_incl", "", 150, 50 ,200);

  zjets_mll_ee_njet->Sumw2();
  zjets_mll_mm_njet->Sumw2();
  zjets_mll_ee_incl->Sumw2();
  zjets_mll_mm_incl->Sumw2();

  TH1F * zjets_met_loose_ee_njet = new TH1F("zjets_met_loose_ee_njet", "", 350, 0  ,350);
  TH1F * zjets_met_loose_mm_njet = new TH1F("zjets_met_loose_mm_njet", "", 350, 0  ,350);
  TH1F * zjets_met_loose_ee_incl = new TH1F("zjets_met_loose_ee_incl", "", 350, 0  ,350);
  TH1F * zjets_met_loose_mm_incl = new TH1F("zjets_met_loose_mm_incl", "", 350, 0  ,350);

  zjets_met_loose_ee_njet->Sumw2();
  zjets_met_loose_mm_njet->Sumw2();
  zjets_met_loose_ee_incl->Sumw2();
  zjets_met_loose_mm_incl->Sumw2();

  TH1F * zjets_met_medium_ee_njet = new TH1F("zjets_met_medium_ee_njet", "", 350, 0  ,350);
  TH1F * zjets_met_medium_mm_njet = new TH1F("zjets_met_medium_mm_njet", "", 350, 0  ,350);
  TH1F * zjets_met_medium_ee_incl = new TH1F("zjets_met_medium_ee_incl", "", 350, 0  ,350);
  TH1F * zjets_met_medium_mm_incl = new TH1F("zjets_met_medium_mm_incl", "", 350, 0  ,350);

  zjets_met_medium_ee_njet->Sumw2();
  zjets_met_medium_mm_njet->Sumw2();
  zjets_met_medium_ee_incl->Sumw2();
  zjets_met_medium_mm_incl->Sumw2();

  TH1F * zjets_met_tight_ee_njet = new TH1F("zjets_met_tight_ee_njet", "", 350, 0  ,350);
  TH1F * zjets_met_tight_mm_njet = new TH1F("zjets_met_tight_mm_njet", "", 350, 0  ,350);
  TH1F * zjets_met_tight_ee_incl = new TH1F("zjets_met_tight_ee_incl", "", 350, 0  ,350);
  TH1F * zjets_met_tight_mm_incl = new TH1F("zjets_met_tight_mm_incl", "", 350, 0  ,350);

  zjets_met_tight_ee_njet->Sumw2();
  zjets_met_tight_mm_njet->Sumw2();
  zjets_met_tight_ee_incl->Sumw2();
  zjets_met_tight_mm_incl->Sumw2();

  TCut dilep = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && evt_type == 0";
 // && dilmass > 81 && dilmass < 101
  TCut ee = "hyp_type == 0";
  TCut mm = "hyp_type == 1";
  TCut ht100 = "ht_eta30 > 100";
  TCut genhtlt = "gen_ht < 100";
  TCut genhtgt = "gen_ht > 100";
  TCut njets2 = "njets_eta30 > 1";
  TCut met100 = "pfmet > 100";
  TCut met200 = "pfmet > 200";
  TCut met300 = "pfmet > 300";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb";
  TCut loosemll  = "dilmass > 76 && dilmass < 106";
  TCut mediummll = "dilmass > 81 && dilmass < 101";
  TCut tightmll  = "dilmass > 86 && dilmass < 96";

  TCut selection = "";
  selection += dilep;
  // selection += ht100;
  // selection += njets2;
  // selection += xitionveto;

  ch_zjets->Draw("min(199.5,dilmass)>>zjets_mll_ee_njet"     ,  (selection + ee + xitionveto) * weight);
  ch_zjets->Draw("min(199.5,dilmass)>>zjets_mll_mm_njet"     ,  (selection + mm + xitionveto) * weight);
  ch_zjets_inc->Draw("min(199.5,dilmass)>>zjets_mll_ee_incl" ,  (selection + ee + xitionveto + genhtlt ) * weight);
  ch_zjets_inc->Draw("min(199.5,dilmass)>>zjets_mll_mm_incl" ,  (selection + mm + xitionveto + genhtlt ) * weight);

  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_loose_ee_njet" ,  (selection + ee + xitionveto + loosemll           ) * weight);
  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_loose_mm_njet" ,  (selection + mm + xitionveto + loosemll           ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_loose_ee_incl" ,  (selection + ee + xitionveto + loosemll + genhtlt ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_loose_mm_incl" ,  (selection + mm + xitionveto + loosemll + genhtlt ) * weight);

  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_medium_ee_njet" ,  (selection + ee + xitionveto + mediummll           ) * weight);
  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_medium_mm_njet" ,  (selection + mm + xitionveto + mediummll           ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_medium_ee_incl" ,  (selection + ee + xitionveto + mediummll + genhtlt ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_medium_mm_incl" ,  (selection + mm + xitionveto + mediummll + genhtlt ) * weight);

  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_tight_ee_njet" ,  (selection + ee + xitionveto + tightmll           ) * weight);
  ch_zjets->Draw(    "min(349.5,met_rawPt)>>zjets_met_tight_mm_njet" ,  (selection + mm + xitionveto + tightmll           ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_tight_ee_incl" ,  (selection + ee + xitionveto + tightmll + genhtlt ) * weight);
  ch_zjets_inc->Draw("min(349.5,met_rawPt)>>zjets_met_tight_mm_incl" ,  (selection + mm + xitionveto + tightmll + genhtlt ) * weight);

  TFile * file = TFile::Open("mll_hists.root","RECREATE");

  zjets_mll_ee_incl->Draw("histe1");
  zjets_mll_mm_incl->Draw("histsamee1");
  zjets_mll_ee_njet->Draw("histsamee1");
  zjets_mll_mm_njet->Draw("histsamee1");
  
  file->cd();
  zjets_mll_mm_incl->Write();
  zjets_mll_ee_incl->Write();
  zjets_mll_mm_njet->Write();
  zjets_mll_ee_njet->Write();
  zjets_met_loose_mm_incl->Write();
  zjets_met_loose_ee_incl->Write();
  zjets_met_loose_mm_njet->Write();
  zjets_met_loose_ee_njet->Write();
  zjets_met_medium_mm_incl->Write();
  zjets_met_medium_ee_incl->Write();
  zjets_met_medium_mm_njet->Write();
  zjets_met_medium_ee_njet->Write();
  zjets_met_tight_mm_incl->Write();
  zjets_met_tight_ee_incl->Write();
  zjets_met_tight_mm_njet->Write();
  zjets_met_tight_ee_njet->Write();
  file->Close();
  
  return;
}
