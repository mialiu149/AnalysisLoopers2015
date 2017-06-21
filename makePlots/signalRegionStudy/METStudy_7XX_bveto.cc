#include <iostream>
#include <stdexcept>
#include <vector>

#include "TChain.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TColor.h"
#include "THStack.h"
#include "TCut.h"
#include "TH1F.h"
#include "TH2F.h"

#include "plottingTools.cc"

using namespace std;

const bool inclusive_njets = false;

void METStudy_7XX_bveto()
{
  string inclusivestring = "inclusive";
  string bregion   = "bveto";
  string metregion = "metlow";
 metregion = "met150";
 metregion = "met225";
 metregion = "met300";
 if( !inclusive_njets ) inclusivestring = "inclusiveht";

  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht100to200*.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht200to400*.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht400to600*.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf*.root");
  // ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf_1.root");

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_m50inc*.root");

  TChain * ch_fsbkg = new TChain("t");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_bartw.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_toptw.root");

  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays*.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_1.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_2.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_3.root");

  TChain * ch_other = new TChain("t");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttw.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttz.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/wz_3lnu.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/zz_4l.root");
  
  TH2F * zjets_met      = new TH2F("zjets_met"     , "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * zjets_incl_met = new TH2F("zjets_incl_met", "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * fsbkg_met      = new TH2F("fsbkg_met"     , "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * other_met      = new TH2F("other_met"     , "", 8, 2, 10, 2500, 0 ,2500);

  zjets_met     ->Sumw2();
  zjets_incl_met->Sumw2();
  fsbkg_met     ->Sumw2();
  other_met     ->Sumw2();
  
  TCut dilep      = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101 && evt_type == 0";
  TCut ht100      = "ht > 100";
  TCut genht100   = "gen_ht < 100";
  TCut njets2     = "njets > 1";
  TCut metlow     = "met_rawPt > 0 && met_rawPt <= 60";
  TCut met100     = "met_rawPt > 150 && met_rawPt <= 225";
  TCut met200     = "met_rawPt > 225 && met_rawPt <= 300";
  TCut met300     = "met_rawPt > 300";
  TCut bveto      = "nBJet40 == 0";
  TCut withb      = "nBJet40 > 0";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight     = "evt_scale1fb*10";

  TCut selection = "";
  selection += dilep;
  selection += njets2;
  selection += bveto;
  selection += xitionveto;
  // selection += met100;
  // selection += met200;
  // selection += met300;
  
  ch_zjets->Draw(    "min(2999,ht):min(11.5,njets)>>zjets_met"      , (selection            ) * weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" , (selection + genht100 ) * weight);
  ch_fsbkg->Draw(    "min(2999,ht):min(11.5,njets)>>fsbkg_met"      , (selection            ) * weight);
  ch_other->Draw(    "min(2999,ht):min(11.5,njets)>>other_met"      , (selection            ) * weight);
  zjets_met->Add(zjets_incl_met);

  //formatting
  gStyle->SetPaintTextFormat(".1f");

  zjets_met->RebinY(100);
  other_met->RebinY(100);
  fsbkg_met->RebinY(100);

  zjets_met->GetYaxis()->SetTitle("H_{T}");
  zjets_met->GetXaxis()->SetTitle("N_{jets}");

  TH2F * stack       = NULL;
  TH2F * h_inclusive = NULL;

  // //draw exclusive plot
  // TCanvas * c_met = new TCanvas("c_met","",800,800);

  // c_met->cd();

  // TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  // pad->SetBottomMargin(0.18);
  // pad->SetRightMargin(0.18);
  // pad->SetTopMargin(0.07);
  // pad->SetLeftMargin(0.18);
  // pad->Draw();
  // pad->cd();
  // pad->SetLogz();

  //draw non-inclusive plot
  // stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack"));	
  // h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive"));
  // h_inclusive->Scale(0);
  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->GetYaxis()->SetTitle("H_{T}");
  // stack->GetXaxis()->SetTitle("N_{jets}");
  // stack->GetZaxis()->SetRangeUser(2e-5,5e5);

  // stack->Draw("colztext");
  // c_met->RedrawAxis();

  // c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_bveto.pdf");
  // c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_bveto.png");
  

  TCanvas * c_inclusive = new TCanvas("c_inclusive","",800,800);

  c_inclusive->cd();

  TPad *p_inclusive = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  p_inclusive->SetBottomMargin(0.18);
  p_inclusive->SetRightMargin (0.18);
  p_inclusive->SetTopMargin   (0.07);
  p_inclusive->SetLeftMargin  (0.18);
  p_inclusive->Draw();
  p_inclusive->cd();
  p_inclusive->SetLogz();
  
  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack"));	
  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);

  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive"));

  makeHistInclusive( stack, h_inclusive, inclusive_njets );
  h_inclusive->Draw("colztext");	
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( zjets_met, h_inclusive, inclusive_njets );
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_zjets_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_zjets_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets );
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_ttbar_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_ttbar_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( other_met, h_inclusive, inclusive_njets );
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_other_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_other_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));


  // //~-~-~-~-~-~-~-~-~-~//
  // //MET > 100 GeV plots//
  // //~-~-~-~-~-~-~-~-~-~//
  // ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"      ,  (selection            + met100 ) *weight);
  // ch_zjets_inc->Draw( "min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met100 ) *weight);
  // ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"      ,  (selection            + met100 ) *weight);
  // ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"      ,  (selection            + met100 ) *weight);
  // zjets_met->Add(zjets_incl_met);

  // stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met100"));	
  // h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met100"));

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->GetYaxis()->SetTitle("H_{T}");
  // stack->GetXaxis()->SetTitle("N_{jets}");
  // stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  // stack->Draw("colztext");
  
  // makeHistInclusive( stack, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met150_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met150_bveto.png");
  
  // makeHistInclusive( zjets_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met150_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met150_bveto.png");
  
  // makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met150_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met150_bveto.png");
  
  // makeHistInclusive( other_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met150_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met150_bveto.png");


  // //~-~-~-~-~-~-~-~-~-~//
  // //MET > 200 GeV plots//
  // //~-~-~-~-~-~-~-~-~-~//
  // ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + met200 ) *weight);
  // ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met200 ) *weight);
  // ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + met200 ) *weight);
  // ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + met200 ) *weight);
  // zjets_met->Add(zjets_incl_met);

  // stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met200"));	
  // h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met200"));

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->GetYaxis()->SetTitle("H_{T}");
  // stack->GetXaxis()->SetTitle("N_{jets}");
  // stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  // stack->Draw("colztext");
  
  // makeHistInclusive( stack, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met225_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met225_bveto.png");
  
  // makeHistInclusive( zjets_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met225_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met225_bveto.png");
  
  // makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met225_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met225_bveto.png");
  
  // makeHistInclusive( other_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met225_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met225_bveto.png");


  // //~-~-~-~-~-~-~-~-~-~//
  // //MET > 300 GeV plots//
  // //~-~-~-~-~-~-~-~-~-~//
  // ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + met300 ) *weight);
  // ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met300 ) *weight);
  // ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + met300 ) *weight);
  // ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + met300 ) *weight);
  // zjets_met->Add(zjets_incl_met);

  // stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met300"));	
  // h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met300"));

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->GetYaxis()->SetTitle("H_{T}");
  // stack->GetXaxis()->SetTitle("N_{jets}");
  // stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  // stack->Draw("colztext");
  
  // makeHistInclusive( stack, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met300_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met300_bveto.png");
  
  // makeHistInclusive( zjets_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met300_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met300_bveto.png");
  
  // makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met300_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met300_bveto.png");
  
  // makeHistInclusive( other_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met300_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met300_bveto.png");


  // //~-~-~-~-~-~-~-~-~-~//
  // //MET > low GeV plots//
  // //~-~-~-~-~-~-~-~-~-~//
  // ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + metlow ) *weight);
  // ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + metlow ) *weight);
  // ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + metlow ) *weight);
  // ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + metlow ) *weight);
  // zjets_met->Add(zjets_incl_met);

  // stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_metlow"));	
  // h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_metlow"));
  // h_inclusive->Scale(0);

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->GetYaxis()->SetTitle("H_{T}");
  // stack->GetXaxis()->SetTitle("N_{jets}");
  // stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  // stack->Draw("colztext");
  
  // makeHistInclusive( stack, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_metlow_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_metlow_bveto.png");
  
  // makeHistInclusive( zjets_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_metlow_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_metlow_bveto.png");
  
  // makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_metlow_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_metlow_bveto.png");
  
  // makeHistInclusive( other_met, h_inclusive, inclusive_njets );
  // h_inclusive->Draw("colztext");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_metlow_bveto.pdf");
  // c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_metlow_bveto.png");

  return;
}
