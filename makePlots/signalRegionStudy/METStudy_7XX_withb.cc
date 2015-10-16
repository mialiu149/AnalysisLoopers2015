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

using namespace std;

void METStudy_7XX_withb()
{


  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht100to200.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht200to400.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht400to600.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_ht600toinf_1.root");

  TChain * ch_zjets_inc = new TChain("t");
  ch_zjets_inc->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/dyjetsll_m50inc.root");

  TChain * ch_fsbkg = new TChain("t");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_bars.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_bart.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_bartw.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_tops.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_topt.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/t_toptw.root");

  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_1.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_2.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttall_msdecays_3.root");

  TChain * ch_other = new TChain("t");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttw.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/ttz.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/wz_3lnu.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-15/zz_4l.root");
  
  TH2F * zjets_met = new TH2F("zjets_met", "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * zjets_incl_met = new TH2F("zjets_incl_met", "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * fsbkg_met = new TH2F("fsbkg_met", "", 8, 2, 10, 2500, 0 ,2500);
  TH2F * other_met = new TH2F("other_met", "", 8, 2, 10, 2500, 0 ,2500);

  zjets_met->Sumw2();
  zjets_incl_met->Sumw2();
  fsbkg_met->Sumw2();
  other_met->Sumw2();
  
  TCut dilep = "nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101 && evt_type == 0";
  TCut ht100 = "ht_eta30 > 100";
  TCut genht100 = "gen_ht < 100";
  TCut njets2 = "njets > 1";
  TCut metlow = "met_rawPt > 0 && met_rawPt <= 50";
  TCut met100 = "met_rawPt > 150 && met_rawPt <= 225";
  TCut met200 = "met_rawPt > 225 && met_rawPt <= 300";
  TCut met300 = "met_rawPt > 300";
  TCut bveto = "nBJet40 == 0";
  TCut withb = "nBJet40 > 0";
  TCut xitionveto = "(abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb*10";

  TCut selection = "";
  selection += dilep;
  // selection += ht100;
  selection += njets2;
  selection += xitionveto;
  selection += withb;
  // selection += met100;
  // selection += met200;
  // selection += met300;
  
  ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"    ,  selection          *weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met"    ,  (selection + genht100 )           *weight);
  ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"    ,  selection          *weight);
  ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"    ,  selection          *weight);
  zjets_met->Add(zjets_incl_met);

  vector <float> htcut;

  htcut.push_back(400.0);
  htcut.push_back(600.0);
  htcut.push_back(1000.0);
  htcut.push_back(1500.0);
  htcut.push_back(1800.0);
  htcut.push_back(-1);
  
  vector <double> val_zjets;
  vector <double> err_zjets;

  vector <double> val_fsbkg;
  vector <double> err_fsbkg;

  vector <double> val_other;
  vector <double> err_other;
  
  for( size_t i = 0; i < htcut.size(); i++ ){
	val_zjets.push_back(0);
	err_zjets.push_back(0);
	val_fsbkg.push_back(0);
	err_fsbkg.push_back(0);
	val_other.push_back(0);
	err_other.push_back(0);
  }

  for( size_t bini = 0; bini < htcut.size()-1; bini++ ){
	// cout<<"Integral over: "<<htcut.at(bini)<<" | "<<htcut.at(bini+1)<<endl;
	if( bini < htcut.size()-1 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( 1, 2, htcut.at(bini), htcut.at(bini+1)-1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( 1, 2, htcut.at(bini), htcut.at(bini+1)-1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( 1, 2, htcut.at(bini), htcut.at(bini+1)-1, err_other.at(bini));
	}
	if( bini == htcut.size()-1 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( 1, 2, htcut.at(bini), -1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( 1, 2, htcut.at(bini), -1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( 1, 2, htcut.at(bini), -1, err_other.at(bini));
	}

	// if( bini < htcut.size()-2 ){
	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(htcut.at(bini)), zjets_met->FindBin(htcut.at(bini+1))-1, err_zjets.at(bini));
	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(htcut.at(bini)), fsbkg_met->FindBin(htcut.at(bini+1))-1, err_fsbkg.at(bini));
	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(htcut.at(bini)), other_met->FindBin(htcut.at(bini+1))-1, err_other.at(bini));
	// }
	// if( bini == htcut.size()-2 ){
	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(htcut.at(bini)), -1, err_zjets.at(bini));
	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(htcut.at(bini)), -1, err_fsbkg.at(bini));
	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(htcut.at(bini)), -1, err_other.at(bini));
	// }
  }
  
  cout<<" $H_{T} [GeV]$ &";
  for( size_t bini = 0; bini < htcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", htcut.at(bini), htcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", htcut.at(htcut.size()-2) );
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
  for( size_t bini = 0; bini < htcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", htcut.at(bini), htcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", htcut.at(htcut.size()-2) );
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
  for( size_t bini = 0; bini < htcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", htcut.at(bini), htcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", htcut.at(htcut.size()-2) );
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
  pad->SetRightMargin(0.18);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogz();
  
  zjets_met->RebinY(100);
  other_met->RebinY(100);
  fsbkg_met->RebinY(100);

  gStyle->SetPaintTextFormat(".1f");

  // THStack * stack = new THStack("stack","");
  TH2F * stack       = NULL;
  TH2F * h_inclusive = NULL;

  zjets_met->GetYaxis()->SetTitle("H_{T}");
  zjets_met->GetXaxis()->SetTitle("N_{jets}");

  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack"));	
  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive"));
  h_inclusive->Scale(0);

  // zjets_met->Scale(1.0/allevents);
  // other_met->Scale(1.0/allevents);
  // fsbkg_met->Scale(1.0/allevents);
 
  stack->Add(other_met);
  stack->Add(fsbkg_met);
  // stack->Add(zjets_met);

  // zjets_met->SetFillColor(kRed);
  // fsbkg_met->SetFillColor(kYellow);
  // other_met->SetFillColor(kMagenta);

  // zjets_met->SetFillStyle(1001);
  // fsbkg_met->SetFillStyle(1001);
  // other_met->SetFillStyle(1001);

  // zjets_met->Rebin(10);

  stack->GetYaxis()->SetTitle("H_{T}");
  stack->GetXaxis()->SetTitle("N_{jets}");
	
  // zjets_met->GetYaxis()->SetRangeUser(2e-6,1);
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);

  stack->Draw("colztext");
  c_met->RedrawAxis();

  // TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  // l1->SetLineColor(kWhite);    
  // l1->SetShadowColor(kWhite);    
  // l1->SetFillColor(kWhite);    
  // l1->AddEntry( zjets_met , "Z+jets"       , "f");
  // l1->AddEntry( fsbkg_met , "t#bar{t}+single-t"       , "f");
  // l1->AddEntry( other_met , "Other"       , "f");
  // l1->Draw("same");

  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_withb.pdf");
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15/HT_vs_njets_run2_withb.png");
  

  TCanvas * c_inclusive = new TCanvas("c_inclusive","",800,800);

  c_inclusive->cd();

  TPad *p_inclusive = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  p_inclusive->SetBottomMargin(0.18); p_inclusive->SetRightMargin(0.18);
  p_inclusive->SetTopMargin(0.07)   ; p_inclusive->SetLeftMargin(0.18) ;
  p_inclusive->Draw(); p_inclusive->cd(); p_inclusive->SetLogz();
  
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, stack->Integral( xbin, -1, ybin, -1 ));
	}
  }

  h_inclusive->GetYaxis()->SetTitle("H_{T}");
  h_inclusive->GetXaxis()->SetTitle("N_{jets}");
  h_inclusive->Draw("colztext");
	
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, zjets_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, fsbkg_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, other_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_withb.png");


  //~-~-~-~-~-~-~-~-~-~//
  //MET > 100 GeV plots//
  //~-~-~-~-~-~-~-~-~-~//
  ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + met100 ) *weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met100 ) *weight);
  ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + met100 ) *weight);
  ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + met100 ) *weight);
  zjets_met->Add(zjets_incl_met);

  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met100"));	
  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met100"));
  h_inclusive->Scale(0);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetYaxis()->SetTitle("H_{T}");
  stack->GetXaxis()->SetTitle("N_{jets}");
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  stack->Draw("colztext");
  
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, stack->Integral( xbin, -1, ybin, -1 ));
	}
  }
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met100_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met100_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, zjets_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met100_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met100_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, fsbkg_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met100_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met100_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, other_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met100_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met100_withb.png");


  //~-~-~-~-~-~-~-~-~-~//
  //MET > 200 GeV plots//
  //~-~-~-~-~-~-~-~-~-~//
  ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + met200 ) *weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met200 ) *weight);
  ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + met200 ) *weight);
  ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + met200 ) *weight);
  zjets_met->Add(zjets_incl_met);

  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met200"));	
  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met200"));
  h_inclusive->Scale(0);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetYaxis()->SetTitle("H_{T}");
  stack->GetXaxis()->SetTitle("N_{jets}");
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  stack->Draw("colztext");
  
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, stack->Integral( xbin, -1, ybin, -1 ));
	}
  }
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met200_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met200_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, zjets_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met200_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met200_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, fsbkg_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met200_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met200_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, other_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met200_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met200_withb.png");


  //~-~-~-~-~-~-~-~-~-~//
  //MET > 300 GeV plots//
  //~-~-~-~-~-~-~-~-~-~//
  ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + met300 ) *weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + met300 ) *weight);
  ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + met300 ) *weight);
  ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + met300 ) *weight);
  zjets_met->Add(zjets_incl_met);

  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_met300"));	
  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_met300"));
  h_inclusive->Scale(0);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetYaxis()->SetTitle("H_{T}");
  stack->GetXaxis()->SetTitle("N_{jets}");
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  stack->Draw("colztext");
  
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, stack->Integral( xbin, -1, ybin, -1 ));
	}
  }
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met300_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_met300_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, zjets_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met300_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_met300_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, fsbkg_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met300_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_met300_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, other_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met300_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_met300_withb.png");


  //~-~-~-~-~-~-~-~-~-~//
  //MET > low GeV plots//
  //~-~-~-~-~-~-~-~-~-~//
  ch_zjets->Draw(     "min(2999,ht):min(11.5,njets)>>zjets_met"     ,  (selection            + metlow ) *weight);
  ch_zjets_inc->Draw("min(2999,ht):min(11.5,njets)>>zjets_incl_met" ,  (selection + genht100 + metlow ) *weight);
  ch_fsbkg->Draw(     "min(2999,ht):min(11.5,njets)>>fsbkg_met"     ,  (selection            + metlow ) *weight);
  ch_other->Draw(     "min(2999,ht):min(11.5,njets)>>other_met"     ,  (selection            + metlow ) *weight);
  zjets_met->Add(zjets_incl_met);

  stack       = dynamic_cast<TH2F*>(zjets_met->Clone("stack_metlow"));	
  h_inclusive = dynamic_cast<TH2F*>(zjets_met->Clone("h_inclusive_metlow"));
  h_inclusive->Scale(0);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->GetYaxis()->SetTitle("H_{T}");
  stack->GetXaxis()->SetTitle("N_{jets}");
  stack->GetZaxis()->SetRangeUser(2e-5,5e5);
  stack->Draw("colztext");
  
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, stack->Integral( xbin, -1, ybin, -1 ));
	}
  }
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_metlow_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_inclusive_metlow_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, zjets_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_metlow_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_zjets_metlow_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, fsbkg_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_metlow_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_ttbar_metlow_withb.png");
  
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < stack->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < stack->GetNbinsY()+1; ybin++ ){
	  h_inclusive->SetBinContent( xbin, ybin, other_met->Integral( xbin, -1, ybin, -1 ));
	}
  }  
  h_inclusive->Draw("colztext");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_metlow_withb.pdf");
  c_inclusive->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/V00-00-15//HT_vs_njets_run2_other_metlow_withb.png");

  return;
}
