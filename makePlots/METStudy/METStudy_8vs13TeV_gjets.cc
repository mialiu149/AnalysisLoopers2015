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

void METStudy_8vs13TeV_gjets()
{

  TChain * ch_gjets_08tev = new TChain("T1");
  // ch_gjets_08tev->Add("/nfs-6/userdata/cwelke/ZHMet2012/photon_output/V00-02-21/photon_mght40*_baby.root");
  ch_gjets_08tev->Add("/nfs-6/userdata/cwelke/ZHMet2012/photon_output/V00-02-21/photon_mght100*_baby.root");
  ch_gjets_08tev->Add("/nfs-6/userdata/cwelke/ZHMet2012/photon_output/V00-02-21/merged/photon_mght200_baby.root");
  ch_gjets_08tev->Add("/nfs-6/userdata/cwelke/ZHMet2012/photon_output/V00-02-21/merged/photon_mght400_baby.root");

  // TChain * ch_gjets_08inc = new TChain("T1");
  // ch_gjets_08inc->Add("/home/users/cwelke/ZHmet_2013/output/V00-02-19/zjets_53X_slim_baby.root");

  TChain * ch_gjets_13tev = new TChain("t");
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht100to200.root"  );
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400.root"  );
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400_1.root");
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600.root"  );
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600_1.root");
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf.root"  );
  ch_gjets_13tev->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf_1.root");

  
  TH1F * gjets_met_08tev = new TH1F("gjets_met_08tev", "", 350, 0 ,350);
  // TH1F * gjets_met_08inc = new TH1F("gjets_met_08inc", "", 350, 0 ,350);
  TH1F * gjets_met_13tev = new TH1F("gjets_met_13tev", "", 350, 0 ,350);

  gjets_met_08tev->Sumw2();
  // gjets_met_08inc->Sumw2();
  gjets_met_13tev->Sumw2();

  //8 TeV cuts  
  TCut c_08tev_photon     = "etg     >  22";
  TCut c_08tev_ht100      = "ht      > 100";
  TCut c_08tev_njets2     = "njets40 > 1";
  TCut c_08tev_hoe        = "hoe     < 0.1";
  TCut c_08tev_nemf       = "jetneutralemfrac          > 0.7";
  // TCut notaligned = "acos( cos( gamma_phi[0] - met_rawPhi ) ) > 0.14 ";
  TCut c_08tev_elveto     = "!elveto";
  TCut c_08tev_weight     = "weight";

  TCut s_08tev_selection = "";
  s_08tev_selection += c_08tev_photon;
  s_08tev_selection += c_08tev_ht100;
  s_08tev_selection += c_08tev_njets2;
  s_08tev_selection += c_08tev_hoe;
  s_08tev_selection += c_08tev_nemf;
  s_08tev_selection += c_08tev_elveto;

  cout<<"implementing cuts for 8 TeV"<<endl;  
  ch_gjets_08tev->Draw("min(pfmet, 349.5)>>gjets_met_08tev"    ,  s_08tev_selection        *c_08tev_weight);
  // ch_gjets_08inc->Draw("min(pfmet, 349.5)>>gjets_met_08inc"    ,  (s_08tev_selection+c_08tev_stitch)        *c_08tev_weight);

  // gjets_met_08tev->Add(gjets_met_08inc);
  
  TCut c_13tev_metcut     = "met_rawPt > 0";
  TCut c_13tev_htcut      = "ht_eta30 > 100";
  TCut c_13tev_njets2     = "njets_eta30 > 1";
  TCut c_13tev_weight     = "evt_scale1fb";
  TCut c_13tev_photon     = "ngamma                      > 0";
  TCut c_13tev_pt22       = "gamma_pt[0]                 > 22";
  TCut c_13tev_hoe        = "gamma_hOverE[0]             < 0.1";
  TCut c_13tev_nemf       = "matched_neutralemf          > 0.7";
  // TCut c_13tev_notaligned = "acos( cos( gamma_phi[0] - met_rawPhi ) ) > 0.14 ";
  TCut c_13tev_elveto     = "!elveto";

  TCut s_13tev_selection = "";
  s_13tev_selection += c_13tev_metcut;
  s_13tev_selection += c_13tev_htcut ;
  s_13tev_selection += c_13tev_njets2;
  s_13tev_selection += c_13tev_photon;
  s_13tev_selection += c_13tev_pt22  ;
  s_13tev_selection += c_13tev_hoe   ;
  s_13tev_selection += c_13tev_nemf  ;
  s_13tev_selection += c_13tev_elveto;
  
  cout<<"implementing cuts for 13 TeV"<<endl;  
  ch_gjets_13tev->Draw("min(met_rawPt,349.5)>>gjets_met_13tev"    ,  s_13tev_selection        *c_13tev_weight);

  // vector <float> metcut;
  // metcut.push_back(0.0);
  // metcut.push_back(60);
  // metcut.push_back(90);
  // metcut.push_back(130);
  // metcut.push_back(200);
  // metcut.push_back(-1);

  // // vector <int> metbin;
  // // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // // 	metbin.push_back(gjets_met->FindBin(metcut.at(bini)));
  // // }
  
  // vector <double> val_gjets;
  // vector <double> err_gjets;

  // vector <double> val_fsbkg;
  // vector <double> err_fsbkg;

  // vector <double> val_other;
  // vector <double> err_other;
  
  // for( size_t i = 0; i < metcut.size(); i++ ){
  // 	val_gjets.push_back(0);
  // 	err_gjets.push_back(0);
  // 	val_fsbkg.push_back(0);
  // 	err_fsbkg.push_back(0);
  // 	val_other.push_back(0);
  // 	err_other.push_back(0);
  // }

  // for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
  // 	// cout<<"Integral over: "<<metcut.at(bini)<<" | "<<metcut.at(bini+1)<<endl;
  // 	if( bini < metcut.size()-1 ){
  // 	  val_gjets.at(bini) = gjets_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_gjets.at(bini));
  // 	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_other.at(bini));
  // 	}
  // 	if( bini == metcut.size()-1 ){
  // 	  val_gjets.at(bini) = gjets_met->IntegralAndError( metcut.at(bini), -1, err_gjets.at(bini));
  // 	  val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( metcut.at(bini), -1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = other_met->IntegralAndError( metcut.at(bini), -1, err_other.at(bini));
  // 	}

  // 	// if( bini < metcut.size()-2 ){
  // 	//   val_gjets.at(bini) = gjets_met->IntegralAndError( gjets_met->FindBin(metcut.at(bini)), gjets_met->FindBin(metcut.at(bini+1))-1, err_gjets.at(bini));
  // 	//   val_fsbkg.at(bini) = fsbkg_met->IntegralAndError( fsbkg_met->FindBin(metcut.at(bini)), fsbkg_met->FindBin(metcut.at(bini+1))-1, err_fsbkg.at(bini));
  // 	//   val_other.at(bini) = other_met->IntegralAndError( other_met->FindBin(metcut.at(bini)), other_met->FindBin(metcut.at(bini+1))-1, err_other.at(bini));
  // 	// }
  // 	// if( bini == metcut.size()-2 ){
  // 	//   val_gjets.at(bini) = gjets_met->IntegralAndError( gjets_met->FindBin(metcut.at(bini)), -1, err_gjets.at(bini));
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
  // cout<<"gjets& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_gjets.at(bini), err_gjets.at(bini));
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_gjets.at(bini), err_gjets.at(bini));
  // }
  // cout<<endl;

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	if( bini == val_gjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini), err_other.at(bini));
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini), err_other.at(bini));
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;

  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_gjets.at(bini)
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini)), sqrt(pow(err_gjets.at(bini),2)
  // 																	 +pow(err_fsbkg.at(bini),2)
  // 																	 +pow(err_other.at(bini),2)));
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_gjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini)), sqrt(pow(err_gjets.at(bini),2)
  // 																		+pow(err_fsbkg.at(bini),2)
  // 																		+pow(err_other.at(bini),2)));
  // }
  // cout<<endl;

  // cout<<endl;
  // cout<<"Normalized to total BG:"<<endl;

  // double totalBG = 0.0;
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	totalBG += val_gjets.at(bini)/100.0;
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
  // cout<<"gjets& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_gjets.at(bini)/totalBG, err_gjets.at(bini)/totalBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_gjets.at(bini)/totalBG, err_gjets.at(bini)/totalBG);
  // }
  // cout<<endl;

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	cout<<Form(" %.3f $\\pm$ %.3f & ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_fsbkg.at(bini)/totalBG, err_fsbkg.at(bini)/totalBG);
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", val_other.at(bini)/totalBG, err_other.at(bini)/totalBG);
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;
  
  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f & ", (val_gjets.at(bini) 
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini))/totalBG, sqrt(pow(err_gjets.at(bini) ,2)
  // 																			 +pow(err_fsbkg.at(bini),2)
  // 																			 +pow(err_other.at(bini),2))/totalBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.3f $\\pm$ %.3f \\\\ ", (val_gjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini))/totalBG, sqrt(pow(err_gjets.at(bini),2)
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
  // cout<<"gjets& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	regionBG = (val_gjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_gjets.at(bini)/regionBG, err_gjets.at(bini)/regionBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_gjets.at(bini)/regionBG, err_gjets.at(bini)/regionBG);
  // }
  // cout<<endl;

  // cout<<"fsbkg& ";
  // for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	regionBG = (val_gjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_gjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini)/regionBG, err_fsbkg.at(bini)/regionBG);
  // }
  // cout<<endl;

  // cout<<"other& ";
  // for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	regionBG = (val_gjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini))/100.0;
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini)/regionBG, err_other.at(bini)/regionBG);
  // }
  // cout<<endl;
  // cout<<"\\hline "<<endl;

  // cout<<"total& ";
  // for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
  // 	regionBG = val_gjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini);
  // 	if( bini < val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", (val_gjets.at(bini)
  // 										  +val_fsbkg.at(bini)
  // 										  +val_other.at(bini))/regionBG, sqrt(pow(err_gjets.at(bini),2)
  // 																			  +pow(err_fsbkg.at(bini),2)
  // 																			  +pow(err_other.at(bini),2))/regionBG);
  // 	if( bini == val_gjets.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", (val_gjets.at(bini)
  // 											 +val_fsbkg.at(bini)
  // 											 +val_other.at(bini))/regionBG, sqrt(pow(err_gjets.at(bini),2)
  // 																				 +pow(err_fsbkg.at(bini),2)
  // 																				 +pow(err_other.at(bini),2))/regionBG);
  // }
  // cout<<endl;

  TCanvas * c_met = new TCanvas("c_met","",800,800);

  c_met->cd();
  c_met->SetLogy();
  
  // THStack * stack = new THStack("stack","");

  gjets_met_08tev->Rebin(10);
  gjets_met_13tev->Rebin(10);
  // other_met->Rebin(10);
  // fsbkg_met->Rebin(10);

  // float allevents = gjets_met->GetSumOfWeights() + other_met->GetSumOfWeights() + fsbkg_met->GetSumOfWeights();
  
  gjets_met_08tev->Scale(1.0/gjets_met_08tev->GetSumOfWeights());
  gjets_met_13tev->Scale(1.0/gjets_met_13tev->GetSumOfWeights());

  // gjets_met->Scale(1.0/allevents);
  // other_met->Scale(1.0/allevents);
  // fsbkg_met->Scale(1.0/allevents);

  // stack->Add(other_met);
  // stack->Add(fsbkg_met);
  // stack->Add(gjets_met);

  // gjets_met->SetFillColor(kRed);
  // fsbkg_met->SetFillColor(kYellow);
  // other_met->SetFillColor(kMagenta);

  // gjets_met->SetFillStyle(1001);
  // fsbkg_met->SetFillStyle(1001);
  // other_met->SetFillStyle(1001);

  gjets_met_08tev->GetXaxis()->SetTitle("E^{miss}_{T}");
  gjets_met_08tev->GetYaxis()->SetTitle("Fraction");
	
  gjets_met_08tev->GetYaxis()->SetRangeUser(2e-8,1);

  gjets_met_08tev->SetMarkerSize(0);
  gjets_met_13tev->SetMarkerSize(0);

  gjets_met_08tev->SetLineWidth(2);
  gjets_met_08tev->SetLineColor(2);

  gjets_met_13tev->SetLineWidth(2);
  gjets_met_13tev->SetLineColor(3);

  gjets_met_08tev->Draw("histe1x0");
  gjets_met_13tev->Draw("samehiste1x0");
  // stack->Draw("samehist");

  c_met->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( gjets_met_08tev , "#gamma+jets; 8 TeV"       , "l");
  l1->AddEntry( gjets_met_13tev , "#gamma+jets; 13 TeV"       , "l");
  // l1->AddEntry( fsbkg_met , "t#bar{t}+single-t"       , "f");
  // l1->AddEntry( other_met , "Other"       , "f");
  l1->Draw("same");

  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_8vs13TeV_gjets.pdf");
  c_met->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/met_stack_8vs13TeV_gjets.png");
  
  return;
}
