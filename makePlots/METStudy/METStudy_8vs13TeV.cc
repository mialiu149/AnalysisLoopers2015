#include <iostream>
#include <stdexcept>

#include "TChain.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TColor.h"
#include "THStack.h"
#include "TCut.h"
#include "TH1F.h"

using namespace std;

void METStudy_8vs13TeV()
{

  TChain * ch_zjets_08tev = new TChain("T1");
  ch_zjets_08tev->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/z1jet_53X_slim__baby.root");
  ch_zjets_08tev->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/z2jet_53X_slim__baby.root");
  ch_zjets_08tev->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/z3jet_53X_slim__baby.root");
  ch_zjets_08tev->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/z4jet_53X_slim__baby.root");

  TChain * ch_zjets_08inc = new TChain("T1");
  ch_zjets_08inc->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/zjets_53X_slim_baby.root");

  TChain * ch_zjets_13tev = new TChain("t");
  ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht100to200.root");
  ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht200to400.root");
  ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht400to600.root");
  ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf.root");
  ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf_1.root");
  // ch_zjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_m50inc.root");

  
  TH1F * zjets_met_08tev = new TH1F("zjets_met_08tev", "", 350, 0 ,350);
  TH1F * zjets_met_08inc = new TH1F("zjets_met_08inc", "", 350, 0 ,350);
  TH1F * zjets_met_13tev = new TH1F("zjets_met_13tev", "", 350, 0 ,350);

  zjets_met_08tev->Sumw2();
  zjets_met_08inc->Sumw2();
  zjets_met_13tev->Sumw2();
  
  TCut c_08tev_dilep      = "lep1.pt() > 20 && lep1.pt() > 20 && leptype != 2 && dilmass > 81 && dilmass < 101";
  TCut c_08tev_ht100      = "ht40 > 100";
  TCut c_08tev_stitch     = "nwzpartons < 1";
  TCut c_08tev_njets2     = "njets40 > 1";
  TCut c_08tev_met100     = "pfmet > 100";
  TCut c_08tev_met200     = "pfmet > 200";
  TCut c_08tev_met300     = "pfmet > 300";
  TCut c_08tev_xitionveto = "leptype == 0 && (abs(abs(lep1.eta())-1.5)>0.1&&abs(abs(lep2.eta())-1.5)>0.1)";
  TCut c_08tev_weight     = "weight";

  TCut s_08tev_selection = "";
  s_08tev_selection += c_08tev_dilep;
  s_08tev_selection += c_08tev_ht100;
  s_08tev_selection += c_08tev_njets2;
  s_08tev_selection += c_08tev_xitionveto;

  cout<<"implementing cuts for 8 TeV"<<endl;  
  ch_zjets_08tev->Draw("min(pfmet, 349.5)>>zjets_met_08tev"    ,  s_08tev_selection        *c_08tev_weight);
  ch_zjets_08inc->Draw("min(pfmet, 349.5)>>zjets_met_08inc"    ,  (s_08tev_selection+c_08tev_stitch)        *c_08tev_weight);

  zjets_met_08tev->Add(zjets_met_08inc);
  
  TCut c_13tev_dilep      = "nlep > 1 && lep_pt[0] > 20 && lep_pt[1] > 20 && (hyp_type == 0 || hyp_type == 1) && dilmass > 81 && dilmass < 101";
  TCut c_13tev_ht100      = "ht_eta30 > 100";
  TCut c_13tev_njets2     = "njets_eta30 > 1";
  TCut c_13tev_met100     = "pfmet > 100";
  TCut c_13tev_met200     = "pfmet > 200";
  TCut c_13tev_met300     = "pfmet > 300";
  TCut c_13tev_xitionveto = "hyp_type == 0 && (abs(abs(lep_p4[0].eta())-1.5)>0.1&&abs(abs(lep_p4[1].eta())-1.5)>0.1)";
  TCut c_13tev_weight     = "evt_scale1fb";

  TCut s_13tev_selection = "";
  s_13tev_selection += c_13tev_dilep;
  s_13tev_selection += c_13tev_ht100;
  s_13tev_selection += c_13tev_njets2;
  s_13tev_selection += c_13tev_xitionveto;
  
  cout<<"implementing cuts for 13 TeV"<<endl;  
  ch_zjets_13tev->Draw("min(met_rawPt,349.5)>>zjets_met_13tev"    ,  s_13tev_selection        *c_13tev_weight);

  // vector <float> metcut;
  // metcut.push_back(0.0);
  // metcut.push_back(60);
  // metcut.push_back(90);
  // metcut.push_back(130);
  // metcut.push_back(200);
  // metcut.push_back(-1);

  // // vector <int> metbin;
  // // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // // 	metbin.push_back(zjets_met->FindBin(metcut.at(bini)));
  // // }
  
  // vector <double> val_zjets;
  // vector <double> err_zjets;

  // vector <double> val_fsbkg;
  // vector <double> err_fsbkg;

  // vector <double> val_other;
  // vector <double> err_other;
  
  // for( size_t i = 0; i < metcut.size(); i++ ){
  // 	val_zjets.push_back(0);
  // 	err_zjets.push_back(0);
  // 	val_fsbkg.push_back(0);
  // 	err_fsbkg.push_back(0);
  // 	val_other.push_back(0);
  // 	err_other.push_back(0);
  // }

  // for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
  // 	// cout<<"Integral over: "<<metcut.at(bini)<<" | "<<metcut.at(bini+1)<<endl;
  // 	if( bini < metcut.size()-1 ){
  // 	  val_zjets.at(bini) = zjets_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_zjets.at(bini));
  // 	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_other.at(bini));
  // 	}
  // 	if( bini == metcut.size()-1 ){
  // 	  val_zjets.at(bini) = zjets_met->IntegralAndError( metcut.at(bini), -1, err_zjets.at(bini));
  // 	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), -1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), -1, err_other.at(bini));
  // 	}

  // 	// if( bini < metcut.size()-2 ){
  // 	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), zjets_met->FindBin(metcut.at(bini+1))-1, err_zjets.at(bini));
  // 	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), fsbkg_met->FindBin(metcut.at(bini+1))-1, err_fsbkg.at(bini));
  // 	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), other_met->FindBin(metcut.at(bini+1))-1, err_other.at(bini));
  // 	// }
  // 	// if( bini == metcut.size()-2 ){
  // 	//   val_zjets.at(bini) = zjets_met->IntegralAndError( zjets_met->FindBin(metcut.at(bini)), -1, err_zjets.at(bini));
  // 	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), -1, err_fsbkg.at(bini));
  // 	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), -1, err_other.at(bini));
  // 	// }
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

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	if( bini == val_zjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini), err_other.at(bini));
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini), err_other.at(bini));
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;

  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_zjets.at(bini)
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini)), sqrt(pow(err_zjets.at(bini),2)
  // 																	 +pow(err_fsbkg.at(bini),2)
  // 																	 +pow(err_other.at(bini),2)));
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_zjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini)), sqrt(pow(err_zjets.at(bini),2)
  // 																		+pow(err_fsbkg.at(bini),2)
  // 																		+pow(err_other.at(bini),2)));
  // }
  // cout<<endl;

  // cout<<endl;
  // cout<<"Normalized to total BG:"<<endl;

  // double totalBG = 0.0;
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	totalBG += val_zjets.at(bini)/100.0;
  // 	totalBG += val_fsbkg.at(bini)/100.0;
  // 	totalBG += val_other.at(bini)/100.0;
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
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_zjets.at(bini)/totalBG, err_zjets.at(bini)/totalBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_zjets.at(bini)/totalBG, err_zjets.at(bini)/totalBG);
  // }
  // cout<<endl;

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	cout<<Form(" %.3f $\\pm$ %.3f & ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;
  
  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", (val_zjets.at(bini) 
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini))/totalBG, sqrt(pow(err_zjets.at(bini) ,2)
  // 																			 +pow(err_fsbkg.at(bini),2)
  // 																			 +pow(err_other.at(bini),2))/totalBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", (val_zjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini))/totalBG, sqrt(pow(err_zjets.at(bini),2)
  // 																		+pow(err_fsbkg.at(bini),2)
  // 																		+pow(err_other.at(bini),2))/totalBG);
  // }
  // cout<<endl;

  // cout<<endl;
  // cout<<"Normalized to each region BG:"<<endl;

  // double regionBG = 0.0;

  // cout<<" $E_{T}^{miss} [GeV]$ &";
  // for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
  // 	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  // }
  // cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  // cout<<endl;

  // cout<<"\\hline "<<endl;
  // cout<<"zjets& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini)/regionBG, err_zjets.at(bini)/regionBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini)/regionBG, err_zjets.at(bini)/regionBG);
  // }
  // cout<<endl;

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_zjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	regionBG = (val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;

  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
  // 	regionBG = val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini);
  // 	if( bini < val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_zjets.at(bini)
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini))/regionBG, sqrt(pow(err_zjets.at(bini),2)
  // 																			  +pow(err_fsbkg.at(bini),2)
  // 																			  +pow(err_other.at(bini),2))/regionBG);
  // 	if( bini == val_zjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_zjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini))/regionBG, sqrt(pow(err_zjets.at(bini),2)
  // 																				 +pow(err_fsbkg.at(bini),2)
  // 																				 +pow(err_other.at(bini),2))/regionBG);
  // }
  // cout<<endl;

  TCanvas * c_met = new TCanvas("c_met","",800,800);

  c_met->cd();
  c_met->SetLogy();
  
  // THStack * stack = new THStack("stack","");

  zjets_met_08tev->Rebin(10);
  zjets_met_13tev->Rebin(10);
  // other_met->Rebin(10);
  // fsbkg_met->Rebin(10);

  // float allevents = zjets_met->GetSumOfWeights() + other_met->GetSumOfWeights() + fsbkg_met->GetSumOfWeights();
  
  zjets_met_08tev->Scale(1.0/zjets_met_08tev->GetSumOfWeights());
  zjets_met_13tev->Scale(1.0/zjets_met_13tev->GetSumOfWeights());

  // zjets_met->Scale(1.0/allevents);
  // other_met->Scale(1.0/allevents);
  // fsbkg_met->Scale(1.0/allevents);

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->Add(zjets_met);

  // zjets_met->SetFillColor(kRed);
  // fsbkg_met->SetFillColor(kYellow);
  // other_met->SetFillColor(kMagenta);

  // zjets_met->SetFillStyle(1001);
  // fsbkg_met->SetFillStyle(1001);
  // other_met->SetFillStyle(1001);

  zjets_met_08tev->GetXaxis()->SetTitle("E^{miss}_{T}");
  zjets_met_08tev->GetYaxis()->SetTitle("Fraction");
	
  zjets_met_08tev->GetYaxis()->SetRangeUser(2e-8,1);

  zjets_met_08tev->SetMarkerSize(0);
  zjets_met_13tev->SetMarkerSize(0);

  zjets_met_08tev->SetLineWidth(2);
  zjets_met_08tev->SetLineColor(2);

  zjets_met_13tev->SetLineWidth(2);
  zjets_met_13tev->SetLineColor(3);

  zjets_met_08tev->Draw("histe1x0");
  zjets_met_13tev->Draw("samehiste1x0");
  // stack->Draw("samehist");

  c_met->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( zjets_met_08tev , "Z+jets; 8 TeV"       , "l");
  l1->AddEntry( zjets_met_13tev , "Z+jets; 13 TeV"       , "l");
  // l1->AddEntry( fsbkg_met , "t#bar{t}+single-t"       , "f");
  // l1->AddEntry( other_met , "Other"       , "f");
  l1->Draw("same");

  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_8vs13TeV.pdf");
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_8vs13TeV.png");
  
  return;
}
