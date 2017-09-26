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
#include "TStyle.h"
#include "RooHistError.h"
#include "TGraphAsymmErrors.h"
#include "../sharedCode/histTools.cc"

using namespace std;

void drawBkgvsSigSplitbyGen( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string type = "ll", string variable = "mll", string region = "passtrig" , int sigscaleup = 1.0,  int rebin=10,float xmin = 50, float xmax = 500, bool setlog =false, bool use_data=false,bool use_sig=false, bool drawmoneyplot=false)
{
  const bool debug(false);
  const bool save_mcsum(false);
  const double alpha = 1 - 0.6827;
  bool drawsys= true;
  if (TString(variable).Contains("deltaphi")) setlog = false;
  bool use_jetfake(true),use_chargeflip(true),use_gammafake(true),use_lostlep(true),use_zz(true), use_truess(true), use_threelep(false);
  bool use_www = use_sig||drawmoneyplot;
  bool use_norm_factor(false); float norm_factor = 1.;
  bool use_fakerate(true),use_fakerate_up(false),use_fakerate_down(false);
  if(use_fakerate && drawsys) { use_fakerate_up = true;use_fakerate_down = true;}
  defineColors();  //colors are defined here: ../sharedCode/histTools.cc
  //get histograms from root files
  if(TString(region).Contains("trilep") ) {use_chargeflip = false; use_zz= false;use_truess = false;use_threelep = true;}
  vector<pair<bool,TH1F *>> bkghists;
  TH1F * h_data  = NULL;
  TH1F * h_chargeflip = NULL;
  TH1F * h_jetfake = NULL;
  TH1F * h_jetfake_up = NULL;
  TH1F * h_jetfake_down = NULL;
  TH1F * h_gammafake = NULL;
  TH1F * h_lostlep= NULL;  
  TH1F * h_zz = NULL;  
  TH1F * h_truess = NULL;  
  TH1F * h_threelep = NULL;  
  TH1F * h_sig_www = NULL;
  string selection_fakerate = selection+"_fakerate"; 
  string selection_fakerate_up = selection+"_fakerate_up"; 
  string selection_fakerate_down = selection+"_fakerate_down"; 
  cout<<Form("fakerate_%s", selection_fakerate.c_str())<<endl;
  if(use_data)  {
    getBackground(  h_data, iter, Form("data_%s" , selection.c_str() ), variable, type, region );h_data->SetBinErrorOption(TH1::kPoisson); 
  }
  if(use_chargeflip) {
    getBackground(  h_chargeflip, iter, Form("chargeflip_stitch_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_chargeflip,h_chargeflip)); 
  }
  if(use_gammafake) {
    getBackground(  h_gammafake, iter, Form("gammafake_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_gammafake,h_gammafake)); 
  }
  if(use_jetfake) {
   if(use_fakerate) getBackground(  h_jetfake, iter, Form("fakerate_%s", selection_fakerate.c_str()), variable,type, selection_fakerate );
   else     getBackground(  h_jetfake, iter, Form("jetfake_stitch_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_jetfake,h_jetfake)); 
  }
  if(use_jetfake && drawsys){
    getBackground(  h_jetfake_up, iter, Form("fakerate_%s", selection_fakerate_up.c_str()), variable,type, selection_fakerate_up );
    getBackground(  h_jetfake_down, iter, Form("fakerate_%s", selection_fakerate_down.c_str()), variable,type, selection_fakerate_down );
    getenvelope(h_jetfake,h_jetfake_up,h_jetfake_down);
  }
  if(use_lostlep)  {
    getBackground(  h_lostlep, iter, Form("lostlep_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_lostlep,h_lostlep)); 
  }
  if(use_zz)   {
    getBackground(  h_zz, iter, Form("zz_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_zz,h_zz)); 
  }
  if(use_truess)   {
    getBackground(  h_truess, iter, Form("truess_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_truess,h_truess)); 
  }
  if(use_www)   {
    getBackground(  h_sig_www, iter, Form("www_stitch_%s", selection.c_str() ), variable, type, region );
  }
  if(use_threelep)   {
    getBackground(  h_threelep, iter, Form("threelep_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_threelep,h_threelep)); 
  }

  if(drawsys)  {
   if(use_truess) setsys(h_truess,0.2);
   if(use_jetfake) setsys(h_jetfake,0.3);
  if(TString(variable).Contains("flavorbin")) h_jetfake->Print("all");
  }
  if(debug)  cout<<"LINE::"<<__LINE__<<" got histograms from files"<<endl;
  //------------------------------------------------------------------------------------------------------//
  //-----------------------------              normalization               -------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(debug)  cout<<"LINE::"<<__LINE__<<" : normalized to luminosity of "<<luminosity<<endl;
  if(use_fakerate) h_jetfake->Scale(1/luminosity);
  if(use_fakerate_up) h_jetfake_up->Scale(1/luminosity);
  if(use_fakerate_down) h_jetfake_down->Scale(1/luminosity);
  for(unsigned int ihist=0;ihist<bkghists.size();++ihist){
     if(bkghists.at(ihist).first)  bkghists.at(ihist).second->Scale(luminosity);
  }

  // normalization for signals.
  if(use_www)  h_sig_www->Scale(sigscaleup*luminosity);
  //------------------------------------------------------------------------------------------------------//
  //---------------------------------------------binning---- ---------------------------------------------//
  //------------------------------------------------------------------------------------------------------//

  float ymin = 1e-2; float ymax = 20;
  if(!setlog) {ymin = 1e-5;ymax =3;}
// these are special variable binning (legacy from WH) if needed.
  int nbins = 7, nybins=3;
  double bins[8] = {30,60,90,120,150,210,270,410};
  double ybins[4] = {0,1,2,3};
  if(drawmoneyplot) {
    xmin=30;xmax=410;
    if(TString(selection).Contains("metbin1")) {ymin=0; ymax=9;}
    else if(TString(selection).Contains("metbin2")) {ymin=0; ymax=14;}
  }
 //special binning for phi
 if( variable == "dphibb" || variable == "deltaphi_lep_met" )   {
     xmin = 0;	xmax = 6.4;  ymin = 0;	 ymax=1000; rebin=5;
 }
 if(!drawmoneyplot){ 
    if(debug)  cout<<"LINE::"<<__LINE__<<" going to rebin histograms, not money plot"<<endl;
    for(unsigned int ihist=0;ihist<bkghists.size();++ihist){
       if(bkghists.at(ihist).first)  bkghists.at(ihist).second->Rebin(rebin);
  }
    if(use_data) h_data->Rebin(rebin);
    if(use_www) h_sig_www->Rebin(rebin);
 }
 else {
    xmax=410; 
    if(use_data) {
      updateoverflow( h_data , xmax );
      h_data = (TH1F*) h_data->Rebin(nbins, "h_data_rebinned", bins);
      renormalizebins(h_data);
    //  updateoverflow( h_data , xmax );
    }
    if(use_www)  {
       h_sig_www = (TH1F*) h_sig_www->Rebin(nbins, "h_sig_www_rebinned", bins);
       renormalizebins(h_sig_www);
    }
    if(use_jetfake) {
       updateoverflow( h_jetfake, xmax );
       h_jetfake = (TH1F*) h_jetfake->Rebin(nbins, "h_jetfake_rebinned", bins); 
       renormalizebins(h_jetfake);
       updateoverflow( h_jetfake, xmax );
    }
    if(use_gammafake) {
       updateoverflow( h_gammafake, xmax );
       h_gammafake = (TH1F*) h_gammafake->Rebin(nbins, "h_gammafake_rebinned", bins); 
       renormalizebins(h_gammafake);
       updateoverflow( h_gammafake, xmax );
    }
    if(use_chargeflip) { 
       updateoverflow( h_chargeflip, xmax );
       h_chargeflip = (TH1F*) h_chargeflip ->Rebin(nbins, "h_chargeflip_rebinned", bins); 
       renormalizebins(h_chargeflip); updateoverflow( h_chargeflip, xmax );
   }
    if(use_lostlep) {
       updateoverflow( h_lostlep, xmax );
       h_lostlep = (TH1F*) h_lostlep    ->Rebin(nbins, "h_lostlep_rebinned", bins); 
       renormalizebins(h_lostlep);
       updateoverflow( h_lostlep, xmax );
   }
    if(use_zz) {
       updateoverflow( h_zz, xmax );
       h_zz = (TH1F*) h_zz    ->Rebin(nbins, "h_zz_rebinned", bins);  
       renormalizebins(h_zz);updateoverflow( h_zz, xmax );
   }
    if(use_truess) {
       updateoverflow( h_truess, xmax );
       h_truess = (TH1F*) h_truess    ->Rebin(nbins, "h_truess_rebinned", bins);  
       renormalizebins(h_truess);updateoverflow( h_truess, xmax );
   }
    if(use_threelep) {
       updateoverflow( h_threelep, xmax );
       h_threelep = (TH1F*) h_threelep    ->Rebin(nbins, "h_threelep_rebinned", bins);  
       renormalizebins(h_threelep);updateoverflow( h_threelep, xmax );
   }
 }
  //drawing on canvas and all that.
  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------set colors and xmin/xmax -------------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(debug)  cout<<"LINE::"<<__LINE__<<" set color for the histograms"<<endl;
  if(use_data) { 
     updateoverflow( h_data , xmax ); 
     h_data->SetMarkerStyle(8);
     h_data->SetMarkerSize(0.75); 
  }
  if(use_chargeflip) { 
     h_chargeflip->SetFillColor(getColorSplitByBg_ss(chargeflip));
     h_chargeflip->SetLineColor(getColorSplitByBg_ss(chargeflip));
     updateoverflow( h_chargeflip, xmax );
  }
  if(use_gammafake) { 
     h_gammafake->SetFillColor(getColorSplitByBg_ss(gammafake));
     h_gammafake->SetLineColor(getColorSplitByBg_ss(gammafake));
     updateoverflow( h_gammafake, xmax );
  }
  if(use_jetfake) { 
     h_jetfake->SetFillColor(getColorSplitByBg_ss(jetfake));
     h_jetfake->SetLineColor(getColorSplitByBg_ss(jetfake));
     updateoverflow( h_jetfake, xmax );

  }
  if(use_lostlep) { 
     h_lostlep->SetLineColor(getColorSplitByBg_ss(loselepton));
     h_lostlep->SetFillColor(getColorSplitByBg_ss(loselepton));
     if(TString(region).Contains("trilep")) {
        h_lostlep->SetLineColor(getColorSplitByBg_ss(loselepton3l));
        h_lostlep->SetFillColor(getColorSplitByBg_ss(loselepton3l));
     }
     updateoverflow( h_lostlep, xmax );
  }
  if(use_zz) { 
     h_zz->SetLineColor(getColorSplitByMC_tribosonana(ZZ));
     h_zz->SetFillColor(getColorSplitByMC_tribosonana(ZZ));
     updateoverflow( h_zz, xmax );
  }
  if(use_truess) { 
     h_truess->SetLineColor(getColorSplitByBg_ss(truess));
     h_truess->SetFillColor(getColorSplitByBg_ss(truess));
     updateoverflow( h_truess, xmax );
  }
  if(use_threelep) { 
     h_threelep->SetLineColor(getColorSplitByBg_ss(threelep));
     h_threelep->SetFillColor(getColorSplitByBg_ss(threelep));
     updateoverflow( h_threelep, xmax );
  }
  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------set ymax------------------------------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(   TString(variable).Contains("dphi") ||  variable == "mhtphi" || type    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
    h_chargeflip->GetYaxis()->SetRangeUser(0, h_chargeflip->GetMaximum()*5 );  
  }
/*  else{
     h_chargeflip->GetYaxis()->SetRangeUser(ymin*luminosity, h_chargeflip->GetMaximum() * ymax );
     if(drawmoneyplot) h_chargeflip->GetYaxis()->SetRangeUser(ymin,ymax );
   }
*/
  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------stacked histograms--------------------------------------------// 
  //------------------------------------------------------------------------------------------------------//
  if(debug)  cout<<"LINE::"<<__LINE__<<" stack them up"<<endl;
  THStack * stack = new THStack("stack","stacked");
  for(unsigned int ihist=0;ihist<bkghists.size();++ihist){
     if(bkghists.at(ihist).first)  stack->Add(bkghists.at(ihist).second,"hist");
  }
  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------legends----------------------------- -------------------------// 
  //------------------------------------------------------------------------------------------------------//
  if(debug)  cout<<"LINE::"<<__LINE__<<" create legends"<<endl;
  float l1_xmin(0.5),l1_xmax(0.9),l1_ymin(0.65),l1_ymax(0.9);
  float l2_xmin(0.6),l2_xmax(0.9),l2_ymin(0.5),l2_ymax(0.58);
  if(use_sig && !use_data){ 
    l1_xmin = 0.55, l1_xmax=0.9, l1_ymin=0.58,l1_ymax=0.9; 
    l2_xmin = 0.2, l2_xmax=0.5, l2_ymin=0.8,l2_ymax=0.9;
  }
  TLegend *l1 = new TLegend(l1_xmin, l1_ymin,l1_xmax,l1_ymax);    
  TLegend *l2 = new TLegend(l2_xmin, l2_ymin, l2_xmax, l2_ymax);    
  l1->SetNColumns(2);
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l2->SetLineColor(kWhite);    
  l2->SetShadowColor(kWhite);    
  l2->SetFillColor(kWhite);    
  if(use_www && !use_data)      l2->AddEntry(h_sig_www,Form("WWW x %i",sigscaleup), "l");
  if(!use_sig)  l1->SetNColumns(2);
  if(use_data)  l1->AddEntry( h_data  , "data"              , "lpe");
  if(use_chargeflip)	l1->AddEntry( h_chargeflip , "Charge flip"       , "f");    
  if(use_jetfake) l1->AddEntry( h_jetfake , "fakes "         , "f");            
  if(use_gammafake) l1->AddEntry( h_gammafake , "#gamma->lepton "         , "f");            
  if(use_zz) l1->AddEntry( h_zz , "ZZ"          , "f");
  if(use_truess) l1->AddEntry( h_truess , "true SS"          , "f");
  if(use_threelep) l1->AddEntry( h_threelep , "3l"          , "f");
  if(use_lostlep) l1->AddEntry( h_lostlep , "Lost lepton"          , "f");
  if(use_www && use_data)      l1->AddEntry(h_sig_www,Form("WWW x %i",sigscaleup), "l");
  if(use_www&&drawmoneyplot)      l1->AddEntry(h_sig_www, Form("#tilde{#chi}^{#pm}_{1} #tilde{#chi}^{0}_{1} (250,1)"), "l");

  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------draw on canvas---------------------- -------------------------// 
  //------------------------------------------------------------------------------------------------------//
  TCanvas * c1 = new TCanvas("c1","");
  c1->SetTopMargin(0.06);
  c1->SetRightMargin(0.07);
  if(use_data) {
  TGraphAsymmErrors* h_data_gr = getPoissonGraph( h_data);
  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0); //top pad to draw histograms
  pad->SetBottomMargin(0.05);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.08);
  pad->SetLeftMargin(0.18);
  pad->Draw(); pad->cd();
  if( !( TString(variable).Contains("dphi") || variable == "nVert" || variable == "mhtphi" || type == "em" || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir") ){
     if(setlog)   pad->SetLogy();
  } 
  h_data_gr->GetXaxis()->SetLabelSize(0);
  h_data_gr->GetYaxis()->SetLabelSize(0.05);
  h_data_gr->GetYaxis()->SetTitleOffset(1.5);
  h_data_gr->GetYaxis()->SetTitleSize(0.05);
  h_data_gr->SetMarkerStyle(20);
  h_data_gr->SetMarkerSize(0.75);
  stack->Draw("hist");
  stack->GetXaxis()->SetLimits(xmin,xmax);
  stack->SetMaximum(stack->GetMaximum() * ymax);
  stack->GetXaxis()->SetLabelSize(0);
  stack->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  if (variable.find("flavorbin")  != string::npos) { stack->GetYaxis()->SetTitle("Yields");}
  h_data_gr->Draw("pe,same");

  if(!drawmoneyplot)  {
    h_data_gr->GetXaxis()->SetRangeUser(xmin, xmax);
    //h_data_gr->GetYaxis()->SetRangeUser(ymin*luminosity, stack->GetMaximum() * ymax );
    h_data_gr->GetYaxis()->SetRangeUser(ymin*luminosity, 1000);
  }
  else {
    h_data_gr->GetYaxis()->SetRangeUser(ymin, ymax);
    h_data_gr->GetXaxis()->SetRangeUser(xmin, xmax);
  }
    h_data_gr->Draw("pe,same");
    pad->Update();

    if(use_www&&use_data) {
      h_sig_www->SetLineColor(getColorSplitByMC_tribosonana(WWW)); 
      h_sig_www->SetLineStyle(5); 
      h_sig_www->SetLineWidth(4);  
      updateoverflow(h_sig_www,xmax);
      h_sig_www->Draw("SAMEHIST");
   }
  pad->RedrawAxis();
  if(use_sig && !use_data) l2->Draw();
  l1->Draw("same");
  c1->cd();

  TH1F* h_rat = (TH1F*)h_data  -> Clone("h_rat");
  TH1F* h_den = (TH1F*)h_jetfake -> Clone("h_den");

  if(use_chargeflip) h_den->Add(h_chargeflip);
  if(use_lostlep)   h_den->Add(h_lostlep);
  if(use_zz)   h_den->Add(h_zz);
  if(use_truess)   h_den->Add(h_truess);
  if(use_threelep)   h_den->Add(h_threelep);
  if(use_gammafake)   h_den->Add(h_gammafake);

  TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  rat_pad->SetBottomMargin(0.36);
  rat_pad->SetRightMargin(0.07);
  rat_pad->SetTopMargin(0.07);
  rat_pad->SetLeftMargin(0.18);
  rat_pad->Draw();

  if(save_mcsum){
    TH1F* h_sum = (TH1F*)h_den -> Clone("h_sum");// save the h_sum histogram
    saveHist(Form("MCsum_%s.root",selection.c_str()),"h_sum");
  }
  if(drawsys){
//   for(int i = 1; i<=h_den->GetNbinsX(); ++i){
//    h_den->SetBinError(i,h_den->GetBinContent(i)*0.3);
//  }
   pad->cd();
   gStyle->SetErrorX(0.5);
   h_den->SetFillColor(1);
   h_den->SetFillStyle(3004);
   h_den->SetLineColor(1);
   h_den->SetLineStyle(0);
   h_den->SetMarkerStyle(0);
   h_den->Draw("e2same");
   } 

  TGraphAsymmErrors* h_rat_gr = getRatioGraph( h_data, h_den);//ratioi of data/mc 
  rat_pad->cd();
  rat_pad->SetGridy();
  TH2F * h_axis;
  if(drawmoneyplot) h_axis = new TH2F("h_axis","h_axis",nbins,bins,2,ybins);// 2-d hists to set x/y axis
  else h_axis = new TH2F("h_axis","h_axis",(xmax-xmin)/rebin+1,xmin,xmax,2,ybins);
  if(variable.find("flavorbin")!= string::npos) h_axis = new TH2F("h_axis","h_axis",3,1,4,2,ybins);
  h_axis->Draw();
  h_rat_gr->SetMarkerStyle(20);
  h_rat_gr->SetMarkerSize(0.75);
  h_rat_gr->Draw("ep,same");

  if( TString(variable).Contains("met") ){
     if(drawmoneyplot) h_rat_gr->GetYaxis()->SetRangeUser(0.0,3.0);
  }
  h_rat_gr->Draw("pe,same");

  h_axis->GetXaxis()->SetTitleOffset(0.9);
  h_axis->GetXaxis()->SetTitleSize(0.15);
  h_axis->GetXaxis()->SetLabelSize(0.12);
  h_axis->GetYaxis()->SetLabelSize(0.12);
  h_axis->GetYaxis()->SetNdivisions(5);
  h_axis->GetYaxis()->SetTitle("#frac{Data}{MC}");
  h_axis->GetYaxis()->SetTitleSize(0.12);
  h_axis->GetYaxis()->SetTitleOffset(0.5);
  h_axis->GetYaxis()->CenterTitle();
 
  if (variable.find("flavorbin")  != string::npos) {
  h_axis->GetXaxis()->SetLabelSize(0.2);
    h_axis->GetXaxis()->SetBinLabel(1.,"ee");
    h_axis->GetXaxis()->SetBinLabel(2.,"e#mu");
    h_axis->GetXaxis()->SetBinLabel(3.,"#mu#mu");
 } 
  // set Xaxis titles.
  setxaxistitle(h_axis,variable);
  TH1F* h_rat_sys = (TH1F*)h_rat -> Clone("h_rat_sys");
  if(drawsys){
   for(int i = 1; i<=h_rat->GetNbinsX(); ++i){
    h_rat_sys->SetBinError(i,h_den->GetBinError(i)/h_den->GetBinContent(i));
    h_rat_sys->SetBinContent(i,1);
  }
   gStyle->SetErrorX(0.5);
   h_rat_sys->SetFillColor(1);
   h_rat_sys->SetFillStyle(3004);
   h_rat_sys->SetLineColor(1);
   h_rat_sys->SetLineStyle(0);
   h_rat_sys->SetMarkerStyle(0);
   h_rat_sys->Draw("e2same");
  } 
  TLine * xaxis = new TLine(xmin,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
  //------------------------------------------------------------------------------------------------------//
  //------------------------------------------     labels          ---------------------------------------//
  //------------------------------------------------------------------------------------------------------//
  drawCMSLatex( c1, luminosity,use_sig);
  TLatex label;
  label.SetNDC();
  TString met_label= "E_{T}^{miss} > 125 GeV ";
  if (TString(selection).Contains("metbin1")) met_label = "125 #leq E_{T}^{miss} < 200 GeV";
  if (TString(selection).Contains("metbin2")) met_label = "E_{T}^{miss} #geq 200 GeV";
  if (drawmoneyplot) {label.SetTextSize(0.03);label.DrawLatex(0.58,0.68,met_label);}
  }

  //------------------------------------------------------------------------------------------------------//
  //----------------------------------- use stack to set axis when not using data ------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(!use_data){
  stack->Draw();
  setxaxistitle(stack,variable);
  stack->GetXaxis()->SetLimits(xmin,xmax);
  stack->GetXaxis()->SetTitleOffset(1.);
  stack->GetXaxis()->SetTitleSize(0.05);
  stack->GetYaxis()->SetLabelSize(0.05);
  stack->GetYaxis()->SetTitleOffset(1.5);
  stack->GetYaxis()->SetTitleSize(0.05);
  stack->SetMaximum(ymax*stack->GetMaximum());
  stack->SetMinimum(ymin*luminosity);
  stack->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  }
  if(use_sig) { 
     h_sig_www->SetLineColor(getColorSplitByMC_tribosonana(WWW)); h_sig_www->SetLineStyle(5);h_sig_www->SetLineWidth(4); updateoverflow(h_sig_www,xmax);  
     h_sig_www->Draw("SAMEHIST");
  }
  if(!use_data) {
    if(setlog) c1->SetLogy();
    c1->RedrawAxis();
    c1->Modified();
    l1->Draw();
    if(use_sig) l2->Draw();
    drawCMSLatex( c1, luminosity*norm_factor ,use_sig);
  } 
  //------------------------------------------------------------------------------------------------------//
  //----------------------------------- save histograms---------------------------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(!setlog){
     if(use_fakerate){
      c1->SaveAs(Form("${plot_output}/h_%s_%s_%s.png", variable.c_str(), type.c_str(), selection_fakerate.c_str() ));
      c1->SaveAs(Form("${plot_output}/h_%s_%s_%s.pdf", variable.c_str(), type.c_str(), selection_fakerate.c_str() ));
     }
      else{
      c1->SaveAs(Form("${plot_output}/h_%s_%s_%s.png", variable.c_str(), type.c_str(), selection.c_str() ));
      c1->SaveAs(Form("${plot_output}/h_%s_%s_%s.pdf", variable.c_str(), type.c_str(), selection.c_str() ));
     } 
 }
  else{ 
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_log.png", variable.c_str(), type.c_str(), selection.c_str() ));
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_log.pdf", variable.c_str(), type.c_str(), selection.c_str() ));
  } 
 return;
}
