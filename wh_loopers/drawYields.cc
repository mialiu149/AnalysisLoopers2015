#include "TH1F.h"
#include "TH1D.h"
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
void drawYields( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string type = "ll", string variable = "mll", string region = "passtrig" )
{
  bool useedgebinning = false;
  bool usetemplates   = false;
  bool usefsbkg       = false;
  
  TH1D * h_data  = NULL;
  TH1D * h_wjets = NULL;
  TH1D * h_ttbar = NULL;
  TH1D * h_zjets = NULL;
//  TH1D * h_QCD = NULL;
///  TH1D * h_top = NULL;
//  TH1D * h_ttv = NULL;
  getYield(   h_data, iter, Form("data_%s" , selection.c_str() ), variable, type, region );
  if( usefsbkg ) getYield(  h_ttbar, "V07-04-03_updatedHLT", Form("data%s", selection.c_str() ), "metgt1jet", "em", "inclusive" );
  else {
  getYield(  h_ttbar, iter, Form("ttbar_%s", selection.c_str() ), variable, type, region );
  getYield(  h_zjets, iter, Form("zjets_htbin_%s", selection.c_str() ), variable, type, region );
 //getYield(  h_QCD, iter, Form("QCD_%s", selection.c_str() ), variable, type, region );
 //getYield(  h_top, iter, Form("top_%s", selection.c_str() ), variable, type, region );
 //getYield(  h_ttv, iter, Form("ttv_%s", selection.c_str() ), variable, type, region );
  }
  getYield(  h_wjets, iter, Form("wjets_htbin_%s", selection.c_str() ), variable, type, region );
  if( usetemplates ){
	h_ttbar->Scale(0.15);
//	h_wjets->Scale(1./h_wjets->GetSumOfWeights());
	float val_data  = h_data  -> Integral(1,49);
	float val_ttbar = h_ttbar -> Integral(1,49);
	float val_wjets = h_wjets -> Integral(1,49);

	cout<<"data:  "<<val_data<<endl;
	cout<<"wjets: "<<val_wjets<<endl;
	cout<<"ttbar: "<<val_ttbar<<endl;
  
	float scaleval = ((val_data-val_ttbar)/(val_wjets));
//	h_wjets->Scale(scaleval);
	val_data  = h_data  -> Integral(1,49);
	val_ttbar = h_ttbar -> Integral(1,49);
	val_wjets = h_wjets -> Integral(1,49);

	cout<<"data:  "<<val_data<<endl;
	cout<<"wjets: "<<val_wjets<<endl;
	cout<<"ttbar: "<<val_ttbar<<endl;

  }
  else{
	h_wjets->Scale(luminosity);
	h_ttbar->Scale(luminosity);
  }

  //MAKE PLOTS
  float xmin = 50; float xmax = 200;
  float ymin = 1e-1; float ymax = 0.5;

  int rebin = 5;
  
  if( type == "em" ){
    rebin = 10;
	ymin = 1e0;
	if( TString(variable).Contains("met") ){
	  rebin = 20;
	}
  }
  if( variable == "nVert" ){
    xmin = 0;
    xmax = 50;
    ymax = 100;
    ymin = 0;
    rebin = 1;
  }
  if( TString(variable).Contains("met") || TString(variable).Contains("mt") ){
	if( type == "em" ) rebin = 20;
	else rebin = 20;
	  xmin = 0;
	  if( usefsbkg ) xmax = 300;
	  else           xmax = 500;
    ymax = 5e1;
  }
 
//  h_data->Rebin(rebin);
//  h_wjets->Rebin(rebin);
//  h_ttbar->Rebin(rebin);
//  h_zjets->Rebin(rebin);
//  h_QCD->Rebin(rebin);
//  h_top->Rebin(rebin);
//  h_ttv->Rebin(rebin);

  float norm_factor = 1;

  TCanvas * c1 = new TCanvas("c1","");
  c1->cd();
//  // c1->SetLogy();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.35, 1.0, 1.0);
  pad->SetBottomMargin(0.3);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.08);
  pad->SetLeftMargin(0.18);
  pad->Draw("B");
  pad->cd();
//  pad->SetLogy();
  
  h_data->SetLineWidth(2);

  h_wjets->SetFillColor(kBlue);
  h_ttbar->SetFillColor(kCyan-3);
//  h_top->SetFillColor(kCyan-3);
//  h_ttv->SetFillColor(kCyan-3);
  h_zjets->SetFillColor(kGreen+2);
//  h_QCD->SetFillColor(kOrange-2);

  h_wjets->SetFillStyle(1001);
  h_ttbar->SetFillStyle(1001);
//  h_top->SetFillStyle(1001);
//  h_ttv->SetFillStyle(1001);
  h_zjets->SetFillStyle(1001);
//  h_QCD->SetFillStyle(1001);

  THStack * stack = new THStack("stack","");

  stack->Add(h_ttbar);
  stack->Add(h_wjets);
  stack->Add(h_zjets);
//  stack->Add(h_QCD);
//  stack->Add(h_top);
//  stack->Add(h_ttv);
  
  h_data->GetXaxis()->SetLabelSize(0);
  h_data->GetYaxis()->SetLabelSize(0.05);
  h_data->GetYaxis()->SetTitleOffset(1.5);
  h_data->GetYaxis()->SetTitleSize(0.05);
  h_data->GetYaxis()->SetTitle("Events");
  
 if( TString(variable).Contains("phi") || variable == "mhtphi" || type    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_data->GetYaxis()->SetRangeUser(0, h_data->GetMaximum()*1.4 );  
  }
  else{
	h_data->GetYaxis()->SetRangeUser(ymin*luminosity, h_data->GetMaximum() * ymax );
  }
  
  h_data->GetXaxis()->SetRangeUser(xmin, xmax);
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
  l1->AddEntry( h_data  , "data"              , "lpe");
  if( usetemplates ){
	l1->AddEntry( h_wjets , "MET Templates"      , "f");
  }else{
	l1->AddEntry( h_wjets , "W+jets MC"         , "f");
  }
  if( usefsbkg ){
  	l1->AddEntry( h_ttbar , "FS Bkg"       , "f");
  }else{
	l1->AddEntry( h_ttbar , "t#bar{t} MC"       , "f");
  }
  l1->AddEntry( h_zjets , "DY"            , "f");
//  l1->AddEntry( h_QCD , "QCD"          , "f");
//  l1->AddEntry( h_ttv ,  "ttv"            , "f");
//  l1->AddEntry( h_top , "single top"            , "f");
  l1->Draw("same");
  
  c1->cd();
	
  TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.52);
  rat_pad->SetBottomMargin(0.75);
  rat_pad->SetRightMargin(0.07);
  rat_pad->SetTopMargin(0.07);
  rat_pad->SetLeftMargin(0.18);
  rat_pad->Draw();
  rat_pad->cd();
  rat_pad->SetGridy();

  TH1D* h_rat = (TH1D*)h_data  -> Clone("h_rat");
  TH1D* h_den = (TH1D*)h_wjets -> Clone("h_den");
  h_den->Add(h_ttbar);
  h_den->Add(h_zjets);
 // h_den->Add(h_QCD);

  h_rat->Divide(h_den);
  h_rat->GetYaxis()->SetRangeUser(0.,2);
  if( TString(variable).Contains("met") ){
      h_rat->GetYaxis()->SetRangeUser(0.0,2.0);
  }
  h_rat->GetYaxis()->SetLabelSize(0.05);
  h_rat->GetXaxis()->SetLabelSize(0.05);
  h_rat->GetYaxis()->SetNdivisions(5);
  h_rat->GetYaxis()->SetTitle("#frac{Data}{MC}");
  h_rat->GetYaxis()->SetTitleSize(0.05);
  h_rat->GetYaxis()->SetTitleOffset(0.8);
  h_rat->GetYaxis()->CenterTitle();
  
  if( variable == "nVert"               )        h_rat->GetXaxis()->SetTitle("N_{vtx}");
  if( TString(variable).Contains("met") )        h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( TString(variable).Contains("NEvents") )    
  {
   h_rat->GetXaxis()->SetLabelSize(0.06);
   if( TString(variable).Contains("2l") ){
   h_rat->GetXaxis()->SetBinLabel(1,"njets>=4\n,E_{T}^{miss}[250,325],MT2W<200");
   h_rat->GetXaxis()->SetBinLabel(2,"njets>=4\n,E_{T}^{miss}>325,MT2W<200");
   h_rat->GetXaxis()->SetBinLabel(3,"njets>=4\n,E_{T}^{miss}[250,325],MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(4,"njets>=4\n,E_{T}^{miss}[325,450],MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(5,"njets>=4\n,E_{T}^{miss}>450,MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(6,"njets==3\n,E_{T}^{miss}>350,MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(7,"njets>=5\n,E_{T}^{miss}>250,MT2W<200,compressed");
   h_rat->GetXaxis()->SetBinLabel(8,"njets>=5\n,E_{T}^{miss}>250,MT2W>200,compressed");
   h_rat->GetXaxis()->SetBinLabel(9,"njets>=4");
   h_rat->GetXaxis()->LabelsOption("v");
 
   }
   else{
   h_rat->GetXaxis()->SetBinLabel(1,"njets>=4\n,E_{T}^{miss}[250,325],MT2W<200");
   h_rat->GetXaxis()->SetBinLabel(2,"njets>=4\n,E_{T}^{miss}>325,MT2W<200");
   h_rat->GetXaxis()->SetBinLabel(3,"njets>=4\n,E_{T}^{miss}[250,325],MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(4,"njets>=4\n,E_{T}^{miss}[325,450],MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(5,"njets>=4\n,E_{T}^{miss}>450,MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(6,"njets==3\n,E_{T}^{miss}>350,MT2W>200");
   h_rat->GetXaxis()->SetBinLabel(7,"njets>=5\n,E_{T}^{miss}>250,MT2W<200,compressed");
   h_rat->GetXaxis()->SetBinLabel(8,"njets>=5\n,E_{T}^{miss}>250,MT2W>200,compressed");
   h_rat->GetXaxis()->SetBinLabel(9,"njets>=4");
   h_rat->GetXaxis()->LabelsOption("v");
   }
  }

  if( TString(variable).Contains("mt") )         h_rat->GetXaxis()->SetTitle("m_{T}(l;#nu) GeV");
  if( TString(variable).Contains("MHT") )        h_rat->GetXaxis()->SetTitle("H_{T}^{miss} GeV");
  if( TString(variable).Contains("mhtphi") )     h_rat->GetXaxis()->SetTitle("H_{T} Phi");
  if( variable == "ht"                  )        h_rat->GetXaxis()->SetTitle("H_{T} GeV");
  if( TString(variable).Contains("pt")  )        h_rat->GetXaxis()->SetTitle("p_{T} GeV");
  if( variable == "njets"               )        h_rat->GetXaxis()->SetTitle("N_{jets}");  
  if( variable == "mll"                 )        h_rat->GetXaxis()->SetTitle("M_{\\ell\\ell} GeV");
  if( TString(variable).Contains("phi") )        h_rat->GetXaxis()->SetTitle("E_{T}^{miss} #phi");
  if( TString(variable).Contains("_pt") )        h_rat->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");

  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);
  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);
  h_rat->Draw("e0x0");
  h_rat->Draw("e1x0same");

  TLine * xaxis = new TLine(xmin,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
 
  drawCMSLatex( c1, luminosity*norm_factor );

  if( usefsbkg ) {
	c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_fsbkg_%s.png", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
	c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_fsbkg_%s.pdf", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
  }else{
	c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_%s.png", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
	c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_%s.pdf", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
  }
  return;
}
