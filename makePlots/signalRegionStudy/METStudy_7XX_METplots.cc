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

#include "../../sharedCode/histTools.cc"

using namespace std;

const float luminosity = 10.0;

void METStudy_7XX_METplots( string signalregion = "SR2", string bregion = "bveto" )
{

  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht100to200.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht200to400.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht400to600.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf.root");
  ch_zjets->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf_1.root");

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_m50inc.root");

  TChain * ch_fsbkg = new TChain("t");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_bars.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_bart.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_bartw.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_tops.root");
  // ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_topt.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/t_toptw.root");

  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_1.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_2.root");
  ch_fsbkg->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_3.root");

  TChain * ch_other = new TChain("t");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttw.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/ttz.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/wz_3lnu.root");
  ch_other->Add("/nfs-6/userdata/cwelke/ZMETbabies/V00-00-15/zz_4l.root");
  
  TH1F * zjets_met      = new TH1F("zjets_met"     , "", 350, 0 ,350 );
  TH1F * zjets_incl_met = new TH1F("zjets_incl_met", "", 350, 0 ,350 );
  TH1F * fsbkg_met      = new TH1F("fsbkg_met"     , "", 350, 0 ,350 );
  TH1F * other_met      = new TH1F("other_met"     , "", 350, 0 ,350 );

  zjets_met     ->Sumw2();
  zjets_incl_met->Sumw2();
  fsbkg_met     ->Sumw2();
  other_met     ->Sumw2();

  string mettype = "met_pt";
  
  TCut dilep = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101 && evt_type == 0";
  TCut ht100 = "ht_eta30 > 100";
  TCut genht100 = "gen_ht < 100";
  TCut njets2 = "njets > 1";
  TCut metlow = Form("%s > 0   && %s <= 60" , mettype.c_str(), mettype.c_str() );
  TCut met100 = Form("%s > 100 && %s <= 200", mettype.c_str(), mettype.c_str() );
  TCut met200 = Form("%s > 200 && %s <= 300", mettype.c_str(), mettype.c_str() );
  TCut met300 = Form("%s > 300"                              , mettype.c_str() );
  TCut bveto = "nBJet40 == 0";
  TCut withb = "nBJet40 > 0";
  TCut btag3 = "nBJet40 > 2";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb*10";
  TCut SR1    = "ht > 600 && njets >= 2 && njets <= 3";
  TCut SR2    = "njets >= 4";
  TCut SR3    = "njets >= 3 && nBJet40 > 2";

  TCut selection = "";
  selection += dilep;
  selection += njets2;
  selection += xitionveto;
  if( bregion == "bveto" ) selection += bveto;
  if( bregion == "withb" ) selection += withb;
  if( bregion == "btag3" ) selection += btag3;
  if( signalregion == "SR1" ) selection += SR1;
  if( signalregion == "SR2" ) selection += SR2;
  if( signalregion == "SR3" ) selection += SR3;
  
  ch_zjets->Draw(     Form("min(349.5,%s)>>zjets_met"      , mettype.c_str() ), selection               *weight);
  ch_zjets_inc->Draw( Form("min(349.5,%s)>>zjets_incl_met" , mettype.c_str() ), (selection + genht100 ) *weight);
  ch_fsbkg->Draw(     Form("min(349.5,%s)>>fsbkg_met"      , mettype.c_str() ), selection               *weight);
  ch_other->Draw(     Form("min(349.5,%s)>>other_met"      , mettype.c_str() ), selection               *weight);
  zjets_met->Add(zjets_incl_met);

  vector <float> metcut;

  metcut.push_back(0.0);
  if( bregion == "bveto" ) metcut.push_back(60.0);
  if( bregion == "withb" ) metcut.push_back(50.0);
  if( bregion == "btag3" ) metcut.push_back(50.0);
  metcut.push_back(150.0);
  metcut.push_back(225.0);
  metcut.push_back(300.0);
  metcut.push_back(-1);
  
  vector <double> val_zjets;
  vector <double> err_zjets;

  vector <double> val_fsbkg;
  vector <double> err_fsbkg;

  vector <double> val_other;
  vector <double> err_other;
  
  for( size_t i = 0; i < metcut.size(); i++ ){
	val_zjets.push_back(0);
	err_zjets.push_back(0);
	val_fsbkg.push_back(0);
	err_fsbkg.push_back(0);
	val_other.push_back(0);
	err_other.push_back(0);
  }

  for( size_t bini = 0; bini < metcut.size()-1; bini++ ){

	if( bini < metcut.size()-2 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), zjets_met->FindBin(metcut.at(bini+1))-1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), fsbkg_met->FindBin(metcut.at(bini+1))-1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), other_met->FindBin(metcut.at(bini+1))-1, err_other.at(bini));
	}
	if( bini == metcut.size()-2 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), -1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), -1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), -1, err_other.at(bini));
	}
  }
  
  cout<<" $E_{T}^{miss} [GeV]$ &";
  for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  cout<<endl;

  cout<<"\\hline "<<endl;
  cout<<"zjets& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini), err_zjets.at(bini));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini), err_zjets.at(bini));
  }
  cout<<endl;

  cout<<"fsbkg& ";
  for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  }
  cout<<endl;

  cout<<"other& ";
  for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini), err_other.at(bini));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini), err_other.at(bini));
  }
  cout<<endl;
  cout<<"\\hline "<<endl;

  cout<<"total& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_zjets.at(bini)
										  +val_fsbkg.at(bini)
										  +val_other.at(bini)), sqrt(pow(err_zjets.at(bini),2)
																	 +pow(err_fsbkg.at(bini),2)
																	 +pow(err_other.at(bini),2)));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_zjets.at(bini)
											 +val_fsbkg.at(bini)
											 +val_other.at(bini)), sqrt(pow(err_zjets.at(bini),2)
																		+pow(err_fsbkg.at(bini),2)
																		+pow(err_other.at(bini),2)));
  }
  cout<<endl;

  cout<<endl;
  cout<<"Normalized to total BG:"<<endl;

  double totalBG = 0.0;
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	totalBG += val_zjets.at(bini)/100.0;
	totalBG += val_fsbkg.at(bini)/100.0;
	totalBG += val_other.at(bini)/100.0;
  }

  cout<<" $H_{T} [GeV]$ &";
  for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  cout<<endl;

  cout<<"\\hline "<<endl;
  cout<<"zjets& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_zjets.at(bini)/totalBG, err_zjets.at(bini)/totalBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_zjets.at(bini)/totalBG, err_zjets.at(bini)/totalBG);
  }
  cout<<endl;

  cout<<"fsbkg& ";
  for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
  }
  cout<<endl;

  cout<<"other& ";
  for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
  }
  cout<<endl;
  cout<<"\\hline "<<endl;
  
  cout<<"total& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f & ", (val_zjets.at(bini) 
										  +val_fsbkg.at(bini)
										  +val_other.at(bini))/totalBG, sqrt(pow(err_zjets.at(bini) ,2)
																			 +pow(err_fsbkg.at(bini),2)
																			 +pow(err_other.at(bini),2))/totalBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", (val_zjets.at(bini)
											 +val_fsbkg.at(bini)
											 +val_other.at(bini))/totalBG, sqrt(pow(err_zjets.at(bini),2)
																				+pow(err_fsbkg.at(bini),2)
																				+pow(err_other.at(bini),2))/totalBG);
  }
  cout<<endl;

  cout<<endl;
  cout<<"Normalized to each region BG:"<<endl;

  double regionBG = 0.0;

  cout<<" $H_{T} [GeV]$ &";
  for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  cout<<endl;

  cout<<"\\hline "<<endl;
  cout<<"zjets& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini)/regionBG, err_zjets.at(bini)/regionBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini)/regionBG, err_zjets.at(bini)/regionBG);
  }
  cout<<endl;

  cout<<"fsbkg& ";
  for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
  }
  cout<<endl;

  cout<<"other& ";
  for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
  }
  cout<<endl;
  cout<<"\\hline "<<endl;

  cout<<"total& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	regionBG = val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini);
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_zjets.at(bini)
										  +val_fsbkg.at(bini)
										  +val_other.at(bini))/regionBG, sqrt(pow(err_zjets.at(bini),2)
																			  +pow(err_fsbkg.at(bini),2)
																			  +pow(err_other.at(bini),2))/regionBG);
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_zjets.at(bini)
											 +val_fsbkg.at(bini)
											 +val_other.at(bini))/regionBG, sqrt(pow(err_zjets.at(bini),2)
																				 +pow(err_fsbkg.at(bini),2)
																				 +pow(err_other.at(bini),2))/regionBG);
  }
  cout<<endl;

  TCanvas * c_met = new TCanvas("c_met","",800,800);

  c_met->cd();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  pad->SetBottomMargin(0.18);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.06);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogy();
  
  zjets_met->Rebin(25);
  other_met->Rebin(25);
  fsbkg_met->Rebin(25);

  // THStack * stack = new THStack("stack","");
  THStack * stack       = new THStack("stack","");

  // zjets_met->Scale(1.0/allevents);
  // other_met->Scale(1.0/allevents);
  // fsbkg_met->Scale(1.0/allevents); 

  zjets_met->SetFillColor(kRed);
  fsbkg_met->SetFillColor(kYellow);
  other_met->SetFillColor(kMagenta);

  zjets_met->SetFillStyle(1001);
  fsbkg_met->SetFillStyle(1001);
  other_met->SetFillStyle(1001);

  zjets_met->SetMarkerSize(0);
  fsbkg_met->SetMarkerSize(0);
  other_met->SetMarkerSize(0);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->Add(zjets_met);

  zjets_met->GetYaxis()->SetRangeUser(2e-1,1e4);
  zjets_met->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  zjets_met->GetYaxis()->SetTitle("Events/25 GeV");

  zjets_met->Draw("hist");
  stack->Draw("histsame");
  pad->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.8, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( zjets_met , "Z+jets"       , "f");
  l1->AddEntry( fsbkg_met , "t#bar{t}+single-t"       , "f");
  l1->AddEntry( other_met , "Other"       , "f");
  l1->Draw("same");

  // drawCMSLatex( c_met, luminosity, .18, .5 );
  drawCMSLatex( c_met, luminosity );
  
  c_met->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/MET_%s_%s.pdf", signalregion.c_str(), bregion.c_str()));
  c_met->SaveAs(Form("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/MET_%s_%s.png", signalregion.c_str(), bregion.c_str()));
  
  return;
}
