#include "TH1F.h"
#include "TFile.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPad.h"

#include <iostream>

#include "../sharedCode/histTools.cc"

using namespace std;

void FS_closure( std::string iter = "", float luminosity = 1.0 )
{

  std::string sample_test = "FS_BG";
  std::string variable = "drll";
  string region = "inclusive";

  
  std::string filename = Form("../output/%s/%s_%s_hists.root", iter.c_str(), sample_test.c_str(), region.c_str() );
  // std::string filename = Form("../output/%s/ttbar_hists.root", iter.c_str() );
  TFile *infile = new TFile(filename.c_str());
  
  TH1F * h_ll = (TH1F*)infile->Get(Form("h_ee_event_%s_2jets", variable.c_str() ))->Clone("h_ll");
  TH1F * h_em = (TH1F*)infile->Get(Form("h_mm_event_%s_2jets", variable.c_str() ))->Clone("h_em");

  h_ll->Scale(luminosity);
  h_em->Scale(luminosity);

  //MAKE TABLES
  vector <float> metcut;
  if( variable == "mll" ){
	metcut.push_back(0.0);
	metcut.push_back(20);
	metcut.push_back(70);
	metcut.push_back(81);
	metcut.push_back(101);
	metcut.push_back(120);
	metcut.push_back(-1);
  }
  
  if( variable == "met" ){
	metcut.push_back(0.0);
	metcut.push_back(60);
	metcut.push_back(150);
	metcut.push_back(225);
	metcut.push_back(300);
	metcut.push_back(-1);
  }

  if( variable == "drll" ){
	metcut.push_back(0.0);
	metcut.push_back(0.1);
	metcut.push_back(0.3);
	metcut.push_back(1.0);
	metcut.push_back(-1);
  }
  
  vector <double> val_zjets;
  vector <double> err_zjets;
  vector <double> val_gjets;
  vector <double> err_gjets;
  vector <double> val_ratio;
  vector <double> err_ratio;
  
  for( size_t i = 0; i < metcut.size(); i++ ){
	val_zjets.push_back(0);
	err_zjets.push_back(0);
	val_gjets.push_back(0);
	err_gjets.push_back(0);
	val_ratio.push_back(0);
	err_ratio.push_back(0);
  }

  for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
	if( bini < metcut.size()-1 ){
	  val_zjets.at(bini) = h_ll->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_zjets.at(bini));
	  val_gjets.at(bini) = h_em->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_gjets.at(bini));
	}
	if( bini == metcut.size()-1 ){
	  val_zjets.at(bini) = h_ll->IntegralAndError( metcut.at(bini), -1, err_zjets.at(bini));
	  val_gjets.at(bini) = h_em->IntegralAndError( metcut.at(bini), -1, err_gjets.at(bini));
	}
  }
  
  if( variable == "met" ) cout<<"$\\mathrm{E_{T}^{miss} [GeV]}$ &";
  if( variable == "mll" ) cout<<"$\\mathrm{m_{\\ell\\ell} [GeV]}$ &";

  for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  }
  cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  cout<<endl;

  cout<<"\\hline "<<endl;
  cout<<"$\\mathrm{ee+\\mu\\mu}$& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini), err_zjets.at(bini));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini), err_zjets.at(bini));
  }
  cout<<endl;

  cout<<"$\\mathrm{e\\mu}$& ";
  for( size_t bini = 0; bini < val_gjets.size()-1; bini++ ){
	if( bini < val_gjets.size()-2 )
	cout<<Form(" %.1f $\\pm$ %.1f & ", val_gjets.at(bini), err_gjets.at(bini));
	if( bini == val_gjets.size()-2 )
	cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_gjets.at(bini), err_gjets.at(bini));
  }
  cout<<endl<<"\\hline"<<endl;

  for( size_t bini = 0; bini < val_ratio.size()-1; bini++ ){
	val_ratio.at(bini) = val_zjets.at(bini)/val_gjets.at(bini);
	err_ratio.at(bini) = err_mult( val_zjets.at(bini), val_gjets.at(bini), err_zjets.at(bini), err_gjets.at(bini), val_ratio.at(bini));
  }
  
  cout<<"ratio& ";
  for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	if( bini < val_zjets.size()-2 )
	  cout<<Form(" %.2f $\\pm$ %.2f & ", val_ratio.at(bini), err_ratio.at(bini));
	if( bini == val_zjets.size()-2 )
	  cout<<Form(" %.2f $\\pm$ %.2f \\\\ ", val_ratio.at(bini), err_ratio.at(bini));
  }
  cout<<endl;


  //MAKE PLOTS

  int rebin = 10;

  if( variable == "drll" ) rebin = 2;
  
  h_ll->Rebin(rebin);
  h_em->Rebin(rebin);

  h_ll->Scale(1./h_ll->GetSumOfWeights());
  h_em->Scale(1./h_em->GetSumOfWeights());

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
  if( variable == "met" ) pad->SetLogy();

  h_ll->SetLineWidth(2);
  h_em->SetFillColor(kCyan);
  h_em->SetFillStyle(1001);
  
  h_ll->GetXaxis()->SetLabelSize(0);
  if( sample_test == "FS_BG" ){
	// if( variable == "met" ) h_ll->GetYaxis()->SetRangeUser(1e-2,1e2);
	if( variable == "met"  ) h_ll->GetYaxis()->SetRangeUser(2e-0,2e3);
	if( variable == "drll" ) h_ll->GetYaxis()->SetRangeUser(2e-5,0.01);
	// if( variable == "mll" ) h_ll->GetYaxis()->SetRangeUser(0,5.5e2);
  }
  
  float xmax = 350;

  if( variable == "drll" ) xmax = 1;

  updateoverflow( h_ll, xmax );
  updateoverflow( h_em, xmax );
  
  h_ll->GetYaxis()->SetLabelSize(0.05);
  h_ll->GetYaxis()->SetTitleOffset(1.5);
  h_ll->GetYaxis()->SetTitleSize(0.05);
  h_ll->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  if( variable == "drll" )  h_ll->GetYaxis()->SetTitle(Form("Events"));
  h_ll->GetXaxis()->SetRangeUser(0,xmax);
  h_ll->SetMarkerStyle(8);
  h_ll->SetMarkerSize(0.75);

  h_ll->Draw("e1");
  h_em->Draw("samehist");
  h_ll->Draw("samex0e1");
  
  pad->RedrawAxis();

  TLegend *l1 = NULL;
  if( variable == "drll" ) l1 = new TLegend(0.25, 0.6, 0.55, 0.90);    
  else l1 = new TLegend(0.6, 0.6, .9, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_ll , "ee events"       , "lpe");
  l1->AddEntry( h_em , "#mu#mu events"       , "f");
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

  TH1F* h_rat = (TH1F*)h_ll->Clone("h_rat");

  h_rat->Divide(h_em);

  // if( variable == "met" ) h_rat->GetYaxis()->SetRangeUser(8,13);
  if( variable == "met"  ) h_rat->GetYaxis()->SetRangeUser(.6,1.4);
  if( variable == "mll"  ) h_rat->GetYaxis()->SetRangeUser(0.75,1.25);
  if( variable == "drll" ) h_rat->GetYaxis()->SetRangeUser(0.,2);
  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);

  h_rat->GetYaxis()->SetTitle("#frac{ee}{#mu#mu}");
  h_rat->GetYaxis()->CenterTitle();
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.5);
  // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  if( variable == "met" ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( variable == "mll" ) h_rat->GetXaxis()->SetTitle("m_{\\ell\\ell} GeV");
  if( variable == "drll" ) h_rat->GetXaxis()->SetTitle("dR(\\ell_{1},\\ell_{2})");

  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);

  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);

  h_rat->Draw("e1x0");

  TLine * xaxis = new TLine(0,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
 
  drawCMSLatex( c1, luminosity );

  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_closure.png", iter.c_str(), variable.c_str(), sample_test.c_str() ));
  c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_closure.pdf", iter.c_str(), variable.c_str(), sample_test.c_str() ));
  
  return;
}
