#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>

#include "TCanvas.h"
#include "TLegend.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TPad.h"
#include "TCut.h"
#include "TProfile.h"
#include "THStack.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TLine.h"
#include "TMath.h"

using namespace std;

bool drawstacked = true;
bool weighted = false;

void draw_stackedPrescales()
{

  char* photonbaby;
  char* rootfilename;

  photonbaby   = (char*) "/home/users/benhoob/ZMet2012/photon_output/V00-02-03/data_53X_2012*_baby.root";
  rootfilename = (char*) "vtxreweight_DoubleElectron_19fb_hoesupertight_stacked_prescales.root";

  char* Zfile        = (char*) "/home/users/benhoob/ZMet2012/output/V00-02-13/data_53X_2012*_baby.root";

  TChain *chZ = new TChain("T1");
  chZ->Add(Zfile);

  TCut Zselection("dilmass>81 && dilmass<101 && njets>=2");
  //TCut Zselection("dilmass>81 && dilmass<101 && njets>=2 && (run<197556 || run>198913)");
  cout << "Using Z selection " << Zselection.GetTitle() << endl;

  TH1F* hZ   = new TH1F("hZ","",50,0,50);
  hZ->Sumw2();
  chZ->Draw("nvtx>>hZ",Zselection);

  
  TChain* chPhoton = new TChain("T1");
  chPhoton->Add(photonbaby);

  TCut njets("njets>=2");
  TCut etg("etg>=20");
  TCut etag("abs(etag)<2");
  TCut hoe("hoe<0.01");
  TCut pix("photon_pixelseed==0");
  TCut emfrac("jetneutralemfrac>0.7");
  TCut pfjet("jetpt - etg >= -5");
  TCut cjet ("calojetpt - etg >= -5");
  TCut elveto("elveto==0");
  TCut lepveto("maxleppt<20");
  TCut dphi("acos(cos( phig-pfmetphi ) ) > 0.14");
  TCut alltrig;
  TCut runrange("(run<197556 || run>198913)");
  
  alltrig = TCut("hgg22>0 || hgg36>0 || hgg50>0 || hgg75>0 || hgg90>0");

  TCut photonSelection;
  photonSelection += njets;
  photonSelection += etg;
  photonSelection += etag;
  photonSelection += hoe;
  photonSelection += pix;
  photonSelection += emfrac;
  photonSelection += pfjet;
  //photonSelection += cjet;
  photonSelection += elveto;
  photonSelection += lepveto;
  photonSelection += dphi;
  photonSelection += alltrig;
  //photonSelection += runrange;

  TCut hlt20("hgg22>0 && hgg36<1 && hgg50<1 && hgg75<1 && hgg90<1");
  TCut weight20;

  if(weighted) {
	weight20 = TCut("hgg22");
  }else{
	weight20 = TCut("1");
  }
  
  TCut ps_14  ("hgg22==14"  );
  TCut ps_21  ("hgg22==21"  );
  TCut ps_180 ("hgg22==180" );
  TCut ps_210 ("hgg22==210" );
  TCut ps_240 ("hgg22>210 &&hgg22 < 270" );
  TCut ps_270 ("hgg22>240 &&hgg22 < 2400" );
  TCut ps_2400("hgg22==2400");
  TCut ps_3600("hgg22==3600");

  photonSelection += hlt20;

  TH1F* h14   = new TH1F("h14"  ,"",50,0,50);
  TH1F* h21   = new TH1F("h21"  ,"",50,0,50);
  TH1F* h180  = new TH1F("h180" ,"",50,0,50);
  TH1F* h210  = new TH1F("h210" ,"",50,0,50);
  TH1F* h240  = new TH1F("h240" ,"",50,0,50);
  TH1F* h270  = new TH1F("h270" ,"",50,0,50);
  TH1F* h2400 = new TH1F("h2400","",50,0,50);
  TH1F* h3600 = new TH1F("h3600","",50,0,50);
  TH1F* hAll  = new TH1F("hAll" ,"",50,0,50);

  h14   -> Sumw2();
  h21   -> Sumw2();
  h180  -> Sumw2();
  h210  -> Sumw2();
  h240  -> Sumw2();
  h270  -> Sumw2();
  h2400 -> Sumw2();
  h3600 -> Sumw2();
  hAll  -> Sumw2();
  
  chPhoton->Draw("nvtx>>h14"  , (photonSelection + ps_14  ) * weight20);
  chPhoton->Draw("nvtx>>h21"  , (photonSelection + ps_21  ) * weight20);
  chPhoton->Draw("nvtx>>h180" , (photonSelection + ps_180 ) * weight20);
  chPhoton->Draw("nvtx>>h210" , (photonSelection + ps_210 ) * weight20);
  chPhoton->Draw("nvtx>>h240" , (photonSelection + ps_240 ) * weight20);
  chPhoton->Draw("nvtx>>h270" , (photonSelection + ps_270 ) * weight20);
  chPhoton->Draw("nvtx>>h2400", (photonSelection + ps_2400) * weight20);
  chPhoton->Draw("nvtx>>h3600", (photonSelection + ps_3600) * weight20);
  
  THStack * stack = new THStack("stack","");

  // stack->Add( h14  );
  // stack->Add( h21  );
  stack->Add( h180 );
  stack->Add( h210 );
  // stack->Add( h240 );
  stack->Add( h270 );
  // stack->Add( h2400);
  // stack->Add( h3600);

  if(!weighted) {
	h14   -> Scale(1/h14  ->GetSumOfWeights());
	h21   -> Scale(1/h21  ->GetSumOfWeights());
	h180  -> Scale(1/h180 ->GetSumOfWeights());
	h210  -> Scale(1/h210 ->GetSumOfWeights());
	h240  -> Scale(1/h240 ->GetSumOfWeights());
	h270  -> Scale(1/h270 ->GetSumOfWeights());
	h2400 -> Scale(1/h2400->GetSumOfWeights());
	h3600 -> Scale(1/h3600->GetSumOfWeights());

  }

  // hAll->Add( h14  );
  // hAll->Add( h21  );
  hAll->Add( h180 );
  hAll->Add( h210 );
  // hAll->Add( h240 );
  hAll->Add( h270 );
  // hAll->Add( h2400);
  // hAll->Add( h3600);

  if( drawstacked ){
	// if(weighted) {
	  h14   -> Scale(1/hAll->GetSumOfWeights());
	  h21   -> Scale(1/hAll->GetSumOfWeights());
	  h180  -> Scale(1/hAll->GetSumOfWeights());
	  h210  -> Scale(1/hAll->GetSumOfWeights());
	  h240  -> Scale(1/hAll->GetSumOfWeights());
	  h270  -> Scale(1/hAll->GetSumOfWeights());
	  h2400 -> Scale(1/hAll->GetSumOfWeights());
	  h3600 -> Scale(1/hAll->GetSumOfWeights());

	// }else{
	//   h14   -> Scale(1/h14  ->GetSumOfWeights());
	//   h21   -> Scale(1/h21  ->GetSumOfWeights());
	//   h180  -> Scale(1/h180 ->GetSumOfWeights());
	//   h210  -> Scale(1/h210 ->GetSumOfWeights());
	//   h240  -> Scale(1/h240 ->GetSumOfWeights());
	//   h270  -> Scale(1/h270 ->GetSumOfWeights());
	//   h2400 -> Scale(1/h2400->GetSumOfWeights());
	//   h3600 -> Scale(1/h3600->GetSumOfWeights());

	// }
  
	h14   -> SetFillStyle(1001);
	h21   -> SetFillStyle(1001);
	h180  -> SetFillStyle(1001);
	h210  -> SetFillStyle(1001);
	h240  -> SetFillStyle(1001);
	h270  -> SetFillStyle(1001);
	h2400 -> SetFillStyle(1001);
	h3600 -> SetFillStyle(1001);
  
	h14   -> SetFillColor(2);
	h21   -> SetFillColor(3);
	h180  -> SetFillColor(4);
	h210  -> SetFillColor(5);
	h240  -> SetFillColor(6);
	h270  -> SetFillColor(7);
	h2400 -> SetFillColor(8);
	h3600 -> SetFillColor(9);

	h14   -> SetFillColor(2);
	h21   -> SetFillColor(3);
	h180  -> SetFillColor(kBlue);
	h210  -> SetFillColor(kRed);
	h240  -> SetFillColor(6);
	h270  -> SetFillColor(kGreen);
	h2400 -> SetFillColor(8);
	h3600 -> SetFillColor(9);

	h14   -> SetLineColor(kBlack);
	h21   -> SetLineColor(kBlack);
	h180  -> SetLineColor(kBlack);
	h210  -> SetLineColor(kBlack);
	h240  -> SetLineColor(kBlack);
	h270  -> SetLineColor(kBlack);
	h2400 -> SetLineColor(kBlack);
	h3600 -> SetLineColor(kBlack);

  }else{
	h14   -> Scale(1/h14  ->GetSumOfWeights());
	h21   -> Scale(1/h21  ->GetSumOfWeights());
	h180  -> Scale(1/h180 ->GetSumOfWeights());
	h210  -> Scale(1/h210 ->GetSumOfWeights());
	h240  -> Scale(1/h240 ->GetSumOfWeights());
	h270  -> Scale(1/h270 ->GetSumOfWeights());
	h2400 -> Scale(1/h2400->GetSumOfWeights());
	h3600 -> Scale(1/h3600->GetSumOfWeights());

	h14   -> SetLineColor(2);
	h21   -> SetLineColor(3);
	h180  -> SetLineColor(kBlue);
	h210  -> SetLineColor(kRed);
	h240  -> SetLineColor(6);
	h270  -> SetLineColor(kGreen);
	h2400 -> SetLineColor(8);
	h3600 -> SetLineColor(9);


	h14   -> SetLineWidth(2);
	h21   -> SetLineWidth(2);
	h180  -> SetLineWidth(2);
	h210  -> SetLineWidth(2);
	h240  -> SetLineWidth(2);
	h270  -> SetLineWidth(2);
	h2400 -> SetLineWidth(2);
	h3600 -> SetLineWidth(2);

  }

  hZ   -> SetMarkerSize(.1);

  h14   -> SetMarkerSize(0);
  h21   -> SetMarkerSize(0);
  h180  -> SetMarkerSize(0);
  h210  -> SetMarkerSize(0);
  h240  -> SetMarkerSize(0);
  h270  -> SetMarkerSize(0);
  h2400 -> SetMarkerSize(0);
  h3600 -> SetMarkerSize(0);

  TCanvas * c_trig = new TCanvas("c_trig","",800,800);

  c_trig->cd();
  
  hZ->Scale(1/hZ->GetSumOfWeights());

  if( drawstacked ){
	hZ->GetYaxis()->SetRangeUser(0,.1);
  }else{
	hZ->GetYaxis()->SetRangeUser(0,.2);
  }
  hZ->Draw("histe1");

  if( drawstacked ){
	stack->Draw("histsame");
  }else{
	stack->Draw("histsamee1nostack");
  }

  hZ->Draw("samehiste1");

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( hZ     , "Z+jets"                     , "l");
  if( drawstacked ){
	// l1->AddEntry( h3600  , "prescale = 3600", "f");
	// l1->AddEntry( h2400  , "prescale = 2400", "f");
	l1->AddEntry( h270   , "prescale = 270" , "f");
	// l1->AddEntry( h240   , "prescale = 240" , "f");
	l1->AddEntry( h210   , "prescale = 210" , "f");
	l1->AddEntry( h180   , "prescale = 180" , "f");
	// l1->AddEntry( h21    , "prescale = 21"  , "f");
	// l1->AddEntry( h14    , "prescale = 14"  , "f");
  }else{
	// l1->AddEntry( h3600  , "prescale = 3600", "l");
	// l1->AddEntry( h2400  , "prescale = 2400", "l");
	l1->AddEntry( h270   , "prescale = 270" , "l");
	// l1->AddEntry( h240   , "prescale = 240" , "l");
	l1->AddEntry( h210   , "prescale = 210" , "l");
	l1->AddEntry( h180   , "prescale = 180" , "l");
	// l1->AddEntry( h21    , "prescale = 21"  , "l");
	// l1->AddEntry( h14    , "prescale = 14"  , "l");
  }
  l1->Draw("same");

  if( drawstacked ){
	if( weighted ){
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_weighted.png");
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_weighted.pdf");
	}else{
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22.png");
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22.pdf");
	}
	
  }else{
	if( weighted ){
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_weighted_nostack.png");
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_weighted_nostack.pdf");
	}else{
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_nostack.png");
	  c_trig->SaveAs("~/public_html/ZMET2015/plots/MET_study_8to13TeV/nvtx_8TeV_hgg22_nostack.pdf");
	}
  }
  
  return;
}
