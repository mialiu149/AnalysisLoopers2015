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


void draw_METvsHT( string inclusivestring = "inclusive", string bregion = "bveto", string metregion = "metall" )
{

  bool inclusive_njets = true;
  bool inclusive_ht    = true;
  if( inclusivestring == "inclusiveht" ) inclusive_njets = false;
  if( inclusivestring == "signalbinning" ){
	inclusive_njets = false;
	inclusive_ht    = false;
  }
  if( inclusivestring == "exclusive"   ){
	inclusive_njets = false;
	inclusive_ht    = false;
  }
  
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
  
  int njetbins = 8;
  float jetbinlo = 2;
  float jetbinhi = 10;
  int   nhtbins = 2500;
  float htbinlo = 0;
  float htbinhi = 2500;
  if( inclusivestring == "signalbinning" ){
	njetbins = 3;
	jetbinhi = 5;
	nhtbins = 1000;
	htbinhi = 1000;
  }
  
  TH2F * zjets_met      = new TH2F("zjets_met"     , "", njetbins, jetbinlo, jetbinhi, nhtbins, htbinlo, htbinhi);
  TH2F * zjets_incl_met = new TH2F("zjets_incl_met", "", njetbins, jetbinlo, jetbinhi, nhtbins, htbinlo, htbinhi);
  TH2F * fsbkg_met      = new TH2F("fsbkg_met"     , "", njetbins, jetbinlo, jetbinhi, nhtbins, htbinlo, htbinhi);
  TH2F * other_met      = new TH2F("other_met"     , "", njetbins, jetbinlo, jetbinhi, nhtbins, htbinlo, htbinhi);

  zjets_met     ->Sumw2();
  zjets_incl_met->Sumw2();
  fsbkg_met     ->Sumw2();
  other_met     ->Sumw2();
  
  TCut dilep      = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101 && evt_type == 0";
  TCut ht100      = "ht > 100";
  TCut genht100   = "gen_ht < 100";
  TCut njets2     = "njets > 1";
  TCut njets3     = "njets > 2";
  TCut metlow50   = "met_rawPt > 0 && met_rawPt <= 50";
  TCut metlow60   = "met_rawPt > 0 && met_rawPt <= 60";
  TCut met100     = "met_rawPt > 150 && met_rawPt <= 225";
  TCut met200     = "met_rawPt > 225 && met_rawPt <= 300";
  TCut met300     = "met_rawPt > 300";
  TCut bveto      = "nBJet40 == 0";
  TCut withb      = "nBJet40 > 0";
  TCut btag3      = "nBJet40 > 2";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight     = "evt_scale1fb*10";

  TCut selection = "";
  selection += dilep;
  selection += njets2;
  selection += xitionveto;
  if( bregion == "bveto" ) selection += bveto;
  if( bregion == "withb" ) selection += withb;
  if( bregion == "btag3" ){	selection += njets3;	selection += btag3;  }
  if( bregion == "bveto" ){
	if( metregion == "metlow" ) selection += metlow60;
	if( metregion == "metlow" ) selection += metlow60;
	if( metregion == "metlow" ) selection += metlow60;
  }
  if( bregion == "withb" ){
	if( metregion == "metlow" ) selection += metlow50;
	if( metregion == "metlow" ) selection += metlow50;
	if( metregion == "metlow" ) selection += metlow50;
  }
  if( metregion == "met150" ) selection += met100;
  if( metregion == "met225" ) selection += met200;
  if( metregion == "met300" ) selection += met300;
  
  ch_zjets->Draw(    Form("min(%f,ht):min(%f,njets)>>zjets_met"     , htbinhi-.5, jetbinhi-.5 ) , (selection            ) * weight);
  ch_zjets_inc->Draw(Form("min(%f,ht):min(%f,njets)>>zjets_incl_met", htbinhi-.5, jetbinhi-.5 ) , (selection + genht100 ) * weight);
  ch_fsbkg->Draw(    Form("min(%f,ht):min(%f,njets)>>fsbkg_met"     , htbinhi-.5, jetbinhi-.5 ) , (selection            ) * weight);
  ch_other->Draw(    Form("min(%f,ht):min(%f,njets)>>other_met"     , htbinhi-.5, jetbinhi-.5 ) , (selection            ) * weight);
  zjets_met->Add(zjets_incl_met);

  //formatting
  gStyle->SetPaintTextFormat(".1f");

  zjets_met->RebinY(100);
  other_met->RebinY(100);
  fsbkg_met->RebinY(100);

  zjets_met->GetYaxis()->SetTitle("H_{T}");
  zjets_met->GetXaxis()->SetTitle("N_{jets}");

  if( inclusivestring == "signalbinning" ){
	zjets_met->GetXaxis()->SetNdivisions(5);
  }
  
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
  if( inclusivestring == "signalbinning" )	p_inclusive->SetLogz(1);
  
  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack"));	
  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);

  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive"));

  makeHistInclusive( stack, h_inclusive, inclusive_njets, inclusive_ht );
  if( inclusivestring == "signalbinning" ) h_inclusive->GetZaxis()->SetRangeUser(0.1,5e1);
  h_inclusive->Draw("colztext");	
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( zjets_met, h_inclusive, inclusive_njets, inclusive_ht );
  if( inclusivestring == "signalbinning" ) h_inclusive->GetZaxis()->SetRangeUser(0.1,5e1);
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_zjets_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_zjets_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( fsbkg_met, h_inclusive, inclusive_njets, inclusive_ht );
  if( inclusivestring == "signalbinning" ) h_inclusive->GetZaxis()->SetRangeUser(0.1,5e1);
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_ttbar_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_ttbar_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  
  makeHistInclusive( other_met, h_inclusive, inclusive_njets, inclusive_ht );
  if( inclusivestring == "signalbinning" ) h_inclusive->GetZaxis()->SetRangeUser(0.1,5e1);
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_other_%s_%s_%s.pdf", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));
  c_inclusive->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_other_%s_%s_%s.png", inclusivestring.c_str(), metregion.c_str(), bregion.c_str() ));

  return;
}
