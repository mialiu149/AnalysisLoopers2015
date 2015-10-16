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

using namespace std;

void METStudy_7XX()
{


  TChain * ch_zjets = new TChain("t");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht100to200.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht200to400.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht400to600.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf_1.root");
  // TChain * ch_zjets_inc = new TChain("t");
  // ch_zjets_inc->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_m50inc.root");

  TChain * ch_fsbkg = new TChain("t");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_bars.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_bart.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_bartw.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_tops.root");
  // ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_topt.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/t_toptw.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttall_msdecays.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttall_msdecays_1.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttall_msdecays_2.root");
  ch_fsbkg->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttall_msdecays_3.root");

  TChain * ch_other = new TChain("t");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttw.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/ttz.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/wz_3lnu.root");
  ch_other->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/zz_4l.root");
  
  TH1F * zjets_met = new TH1F("zjets_met", "", 350, 0 ,350);
  TH1F * fsbkg_met = new TH1F("fsbkg_met", "", 350, 0 ,350);
  TH1F * other_met = new TH1F("other_met", "", 350, 0 ,350);

  zjets_met->Sumw2();
  fsbkg_met->Sumw2();
  other_met->Sumw2();
  
  TCut dilep = "nlep > 1 && lep_pt[0] > 20 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101";
  TCut ht100 = "ht_eta30 > 100";
  TCut njets2 = "njets_eta30 > 1";
  TCut met100 = "pfmet > 100";
  TCut met200 = "pfmet > 200";
  TCut met300 = "pfmet > 300";
  TCut xitionveto = "hyp_type == 0 && (abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut weight = "evt_scale1fb";

  TCut selection = "";
  selection += dilep;
  selection += ht100;
  selection += njets2;
  selection += xitionveto;
  
  ch_zjets->Draw("min(349.5,met_rawPt)>>zjets_met"    ,  selection          *weight);
  ch_fsbkg->Draw("min(349.5,met_rawPt)>>fsbkg_met"    ,  selection          *weight);
  ch_other->Draw("min(349.5,met_rawPt)>>other_met"    ,  selection          *weight);

  vector <float> metcut;
  // metcut.push_back(0.0);
  // // metcut.push_back(60);
  // metcut.push_back(70);
  // metcut.push_back(80);
  // metcut.push_back(90);
  // metcut.push_back(100);
  // // metcut.push_back(150);
  // metcut.push_back(200);
  // // metcut.push_back(300);
  // metcut.push_back(-1);

  metcut.push_back(0.0);
  metcut.push_back(60);
  metcut.push_back(130);
  metcut.push_back(200);
  metcut.push_back(300);
  metcut.push_back(-1);

  // vector <int> metbin;
  // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // 	metbin.push_back(zjets_met->FindBin(metcut.at(bini)));
  // }
  
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
	// cout<<"Integral over: "<<metcut.at(bini)<<" | "<<metcut.at(bini+1)<<endl;
	if( bini < metcut.size()-1 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_other.at(bini));
	}
	if( bini == metcut.size()-1 ){
	  val_zjets.at(bini) = zjets_met->IntegralAndError( metcut.at(bini), -1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), -1, err_fsbkg.at(bini));
	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), -1, err_other.at(bini));
	}

	// if( bini < metcut.size()-2 ){
	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), zjets_met->FindBin(metcut.at(bini+1))-1, err_zjets.at(bini));
	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), fsbkg_met->FindBin(metcut.at(bini+1))-1, err_fsbkg.at(bini));
	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), other_met->FindBin(metcut.at(bini+1))-1, err_other.at(bini));
	// }
	// if( bini == metcut.size()-2 ){
	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), -1, err_zjets.at(bini));
	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), -1, err_fsbkg.at(bini));
	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), -1, err_other.at(bini));
	// }
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

  cout<<" $E_{T}^{miss} [GeV]$ &";
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
  c_met->SetLogy();
  
  THStack * stack = new THStack("stack","");

  zjets_met->Rebin(10);
  other_met->Rebin(10);
  fsbkg_met->Rebin(10);

  float allevents = zjets_met->GetSumOfWeights() + other_met->GetSumOfWeights() + fsbkg_met->GetSumOfWeights();
  
  zjets_met->Scale(1.0/allevents);
  other_met->Scale(1.0/allevents);
  fsbkg_met->Scale(1.0/allevents);

  stack->Add(other_met);
  stack->Add(fsbkg_met);
  stack->Add(zjets_met);

  zjets_met->SetFillColor(kRed);
  fsbkg_met->SetFillColor(kYellow);
  other_met->SetFillColor(kMagenta);

  zjets_met->SetFillStyle(1001);
  fsbkg_met->SetFillStyle(1001);
  other_met->SetFillStyle(1001);

  // zjets_met->Rebin(10);

  zjets_met->GetXaxis()->SetTitle("E^{miss}_{T}");
  zjets_met->GetYaxis()->SetTitle("Fraction");
	
  zjets_met->GetYaxis()->SetRangeUser(2e-6,1);

  zjets_met->Draw("");
  stack->Draw("samehist");
  c_met->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( zjets_met , "Z+jets"       , "f");
  l1->AddEntry( fsbkg_met , "t#bar{t}+single-t"       , "f");
  l1->AddEntry( other_met , "Other"       , "f");
  l1->Draw("same");

  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_run2.pdf");
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_run2.png");
  
  return;
}
