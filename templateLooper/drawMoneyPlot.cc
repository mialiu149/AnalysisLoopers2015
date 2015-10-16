#include "TH1F.h"
#include "TFile.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLatex.h"
#include "THStack.h"

#include <iostream>

#include "../sharedCode/histTools.cc"

using namespace std;
void drawMoneyPlot( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive" )
{

  bool useedgebinning = true;
  
  TH1F * h_data  = NULL;
  TH1F * h_zjets = NULL;
  TH1F * h_fsbkg = NULL;
  TH1F * h_other = NULL;
  TH1F * h_vvbkg = NULL;

  getBackground(   h_data, iter, Form("All_MC%s", selection.c_str() ), "met", "ll" );
  getBackground(  h_fsbkg, iter, Form("All_MC%s", selection.c_str() ), "met", "em" );
  getBackground(  h_other, iter, Form("ttv%s"   , selection.c_str() ), "met", "ll" );
  getBackground(  h_vvbkg, iter, Form("vv%s"    , selection.c_str() ), "met", "ll" );
  // getBackground(  h_zjets, iter, "All_MC", "jzb", "ll" );
  getTemplateMET( h_zjets, iter, Form("All_MC%s", selection.c_str() ) );

  h_data->Scale(luminosity);
  h_zjets->Scale(luminosity);
  h_fsbkg->Scale(luminosity);
  h_other->Scale(luminosity);
  h_vvbkg->Scale(luminosity);
  // h_vvbkg->Scale(0);

  //taken care of in template prediction except for small %age of FS events from WZ->3lnu
  // h_other->Add(h_vvbkg);
  // h_vvbkg->Scale(luminosity);

  //MAKE TABLES
  vector <float> metcut;
  metcut.push_back(0.0);
  metcut.push_back(50);
  metcut.push_back(100);
  metcut.push_back(150);
  metcut.push_back(200);
  metcut.push_back(300);
  metcut.push_back(-1);
  if( useedgebinning ){
	metcut.clear();
	metcut.push_back(0.0);
	metcut.push_back(50);
	if( TString(selection).Contains("2jets"  ) ){ metcut.push_back(150); }
	if( TString(selection).Contains("3jets"  ) ){ metcut.push_back(100); }
	metcut.push_back(-1);

  }

  
  vector <double> val_data;
  vector <double> err_data;

  vector <double> val_zjets;
  vector <double> err_zjets;

  vector <double> val_fsbkg;
  vector <double> err_fsbkg;

  vector <double> val_other;
  vector <double> err_other;

  vector <double> val_vvbkg;
  vector <double> err_vvbkg;

  vector <double> val_allbg;
  vector <double> err_allbg;

  vector <double> val_ratio;
  vector <double> err_ratio;
  
  for( size_t i = 0; i < metcut.size(); i++ ){
	val_data.push_back(0);
	err_data.push_back(0);
	val_zjets.push_back(0);
	err_zjets.push_back(0);
	val_fsbkg.push_back(0);
	err_fsbkg.push_back(0);
	val_other.push_back(0);
	err_other.push_back(0);
	val_vvbkg.push_back(0);
	err_vvbkg.push_back(0);
	val_allbg.push_back(0);
	err_allbg.push_back(0);
	val_ratio.push_back(0);
	err_ratio.push_back(0);
  }

  for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
	if( bini < metcut.size()-1 ){
	  val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_data .at(bini));
	  val_zjets.at(bini) = h_zjets->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = h_fsbkg->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_fsbkg.at(bini));
	  val_other.at(bini) = h_other->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_other.at(bini));
	  val_vvbkg.at(bini) = h_vvbkg->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_vvbkg.at(bini));
	}
	if( bini == metcut.size()-1 ){
	  val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini), -1, err_data .at(bini));
	  val_zjets.at(bini) = h_zjets->IntegralAndError( metcut.at(bini), -1, err_zjets.at(bini));
	  val_fsbkg.at(bini) = h_fsbkg->IntegralAndError( metcut.at(bini), -1, err_fsbkg.at(bini));
	  val_other.at(bini) = h_other->IntegralAndError( metcut.at(bini), -1, err_other.at(bini));
	  val_vvbkg.at(bini) = h_vvbkg->IntegralAndError( metcut.at(bini), -1, err_vvbkg.at(bini));
	}
  }

  float norm_factor = (val_data.at(0) -
					   val_fsbkg.at(0) -
					   val_vvbkg.at(0) -
					   val_other.at(0))/(val_zjets.at(0));
  for( size_t bini = 0; bini < metcut.size(); bini++ ){
	val_zjets.at(bini) *= norm_factor;
    err_zjets.at(bini) *= norm_factor;
  }

  for( size_t bini = 0; bini < metcut.size(); bini++ ){
	val_allbg.at(bini) = val_zjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini) + val_vvbkg.at(bini);
	err_allbg.at(bini) = sqrt( pow(err_zjets.at(bini), 2) + pow(err_fsbkg.at(bini), 2) + pow(err_other.at(bini), 2) + pow(err_vvbkg.at(bini), 2));
	val_ratio.at(bini) = val_data .at(bini)/val_allbg.at(bini);
	err_ratio.at(bini) = err_mult( val_data .at(bini), val_allbg.at(bini),
								   err_data .at(bini), err_allbg.at(bini), val_data .at(bini)/val_allbg.at(bini));
  }
  
  cout<<"$\\mathrm{E_{T}^{miss} [GeV]}$ &";
  for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  cout<<endl;

  if( useedgebinning ){
	cout<<"\\hline "<<endl;
	cout<<"Z+jets& ";
	for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	  if( bini < val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini)+val_vvbkg.at(bini)+val_other.at(bini), sqrt(pow(err_zjets.at(bini),2) + pow(err_vvbkg.at(bini), 2) + pow(err_other.at(bini), 2) ));
	  if( bini == val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini)+val_vvbkg.at(bini)+val_other.at(bini), sqrt(pow(err_zjets.at(bini),2) + pow(err_vvbkg.at(bini), 2) + pow(err_other.at(bini), 2) ));
	}
	cout<<endl;

	cout<<"FS bkg& ";
	for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	  if( bini < val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	  if( bini == val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	}
	cout<<endl;

  }else{
	cout<<"\\hline "<<endl;
	cout<<"Z+jets& ";
	for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	  if( bini < val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini), err_zjets.at(bini));
	  if( bini == val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini), err_zjets.at(bini));
	}
	cout<<endl;

	cout<<"FS bkg& ";
	for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	  if( bini < val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	  if( bini == val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	}
	cout<<endl;

	cout<<"WZ + ZZ bkg& ";
	for( size_t bini = 0; bini < val_vvbkg.size()-1; bini++ ){
	  if( bini < val_vvbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_vvbkg.at(bini), err_vvbkg.at(bini));
	  if( bini == val_vvbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_vvbkg.at(bini), err_vvbkg.at(bini));
	}
	cout<<endl;

	cout<<"rare SM BG& ";
	for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
	  if( bini < val_other.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini), err_other.at(bini));
	  if( bini == val_other.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini), err_other.at(bini));
	}
	cout<<endl;
  }
  
  cout<<"\\hline "<<endl;
  cout<<"total BG& ";
  for( size_t bini = 0; bini < val_allbg.size()-1; bini++ ){
	if( bini < val_allbg.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_allbg.at(bini), err_allbg.at(bini));
	if( bini == val_allbg.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_allbg.at(bini), err_allbg.at(bini));
  }
  cout<<endl;

  cout<<"\\hline "<<endl;
  cout<<"all MC& ";
  for( size_t bini = 0; bini < val_data.size()-1; bini++ ){
	if( bini < val_data.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_data.at(bini), err_data.at(bini));
	if( bini == val_data.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_data.at(bini), err_data.at(bini));
  }
  cout<<endl;

  cout<<"\\hline "<<endl;
  
  cout<<"All MC/BG& ";
  for( size_t bini = 0; bini < val_ratio.size()-1; bini++ ){
	if( bini < val_ratio.size()-2 )
	  cout<<Form(" %.2f $\\pm$ %.2f & ", val_ratio.at(bini), err_ratio.at(bini));
	if( bini == val_ratio.size()-2 )
	  cout<<Form(" %.2f $\\pm$ %.2f \\\\ ", val_ratio.at(bini), err_ratio.at(bini));
  }
  cout<<endl;


  //MAKE PLOTS

  int rebin = 10;
  
  h_data->Rebin(rebin);
  h_zjets->Rebin(rebin);
  h_fsbkg->Rebin(rebin);
  h_vvbkg->Rebin(rebin);
  h_other->Rebin(rebin);

  TCanvas * c1 = new TCanvas("c1","");
  c1->cd();
  // c1->SetLogy();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  pad->SetBottomMargin(0.05);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.08);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  pad->SetLogy();

  h_data->SetLineWidth(2);

  h_zjets->SetFillColor(kBlue);
  h_fsbkg->SetFillColor(kYellow+1);
  h_vvbkg->SetFillColor(kRed);
  h_other->SetFillColor(kMagenta);

  h_zjets->SetFillStyle(1001);
  h_fsbkg->SetFillStyle(1001);
  h_vvbkg->SetFillStyle(1001);
  h_other->SetFillStyle(1001);

  cout<<"Norm factor for Z+jets: "<<norm_factor<<endl;
  h_zjets->Scale(norm_factor);
  
  float xmax = 350;
  updateoverflow( h_data , xmax );
  updateoverflow( h_zjets, xmax );
  updateoverflow( h_fsbkg, xmax );
  updateoverflow( h_vvbkg, xmax );
  updateoverflow( h_other, xmax );

  THStack * stack = new THStack("stack","");

  stack->Add(h_other);
  stack->Add(h_vvbkg);
  stack->Add(h_fsbkg);
  stack->Add(h_zjets);
  
  h_data->GetXaxis()->SetLabelSize(0);
  h_data->GetYaxis()->SetLabelSize(0.05);
  h_data->GetYaxis()->SetTitleOffset(1.5);
  h_data->GetYaxis()->SetTitleSize(0.05);
  h_data->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  h_data->GetYaxis()->SetRangeUser(2e-3*luminosity, h_data->GetMaximum() * 1e1 );
  h_data->GetXaxis()->SetRangeUser(0, xmax);
  h_data->SetMarkerStyle(8);
  h_data->SetMarkerSize(0.75);

  h_data->Draw("e1");
  stack->Draw("samehist");
  h_data->Draw("samex0e1");
  
  pad->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.85);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_data  , "All MC"              , "lpe");
  l1->AddEntry( h_zjets , "Template prediction" , "f");
  l1->AddEntry( h_fsbkg , "FS prediction"       , "f");
  l1->AddEntry( h_vvbkg , "WZ+ZZ MC"            , "f");
  l1->AddEntry( h_other , "Rare SM MC"          , "f");
  l1->Draw("same");
  
  c1->cd();
	
  TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  rat_pad->SetBottomMargin(0.36);
  rat_pad->SetRightMargin(0.07);
  rat_pad->SetTopMargin(0.07);
  rat_pad->SetLeftMargin(0.18);
  rat_pad->Draw();
  rat_pad->cd();
  rat_pad->SetGridy();

  TH1F* h_rat = (TH1F*)h_data->Clone("h_rat");
  TH1F* h_den = (TH1F*)h_zjets->Clone("h_den");
  h_den->Add(h_fsbkg);
  h_den->Add(h_other);
  h_den->Add(h_vvbkg);

  h_rat->Divide(h_den);

  h_rat->GetYaxis()->SetRangeUser(0.0,2.0);
  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);

  h_rat->GetYaxis()->SetTitle("#frac{All MC}{Prediction}");
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.5);
  h_rat->GetYaxis()->CenterTitle();
  // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);

  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);

  h_rat->Draw("e0x0");
  h_rat->Draw("e1x0same");

  TLine * xaxis = new TLine(0,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
 
  drawCMSLatex( c1, luminosity );

  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_met_signalregion%s.png", iter.c_str(), selection.c_str() ));
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_met_signalregion%s.pdf", iter.c_str(), selection.c_str() ));
  
  return;
}
