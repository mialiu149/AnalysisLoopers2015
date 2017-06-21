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

void drawBkgvsSig( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string type = "ll", string variable = "mll", string region = "passtrig" , int sigscaleup = 1.0,  int rebin=10,float xmin = 50, float xmax = 500, bool setlog =false, bool use_data=false,bool use_sig=false, bool drawmoneyplot=false)
{
  const bool debug(false);
  const bool save_mcsum(false);
  const double alpha = 1 - 0.6827;
  bool drawsys= false;
  if (TString(variable).Contains("deltaphi")) setlog = false;
  bool use_wjets(true),use_ttbar(false),use_ttbar1l(true),use_ttbar2l(true),use_zjets(true);
  bool use_singletop(true),use_ttv(true),use_wz(true),use_ww(true),use_zz(true);
  bool use_www = use_sig||drawmoneyplot;
  bool use_norm_factor(false); float norm_factor = 1.;

  defineColors();  //colors are defined here: ../sharedCode/histTools.cc
  //get histograms from root files
  vector<pair<bool,TH1F *>> bkghists;
  TH1F * h_data  = NULL;
  TH1F * h_ttbar = NULL;
  TH1F * h_ttbar1l = NULL;
  TH1F * h_ttbar2l = NULL;
  TH1F * h_wjets = NULL;
  TH1F * h_singletop = NULL;
  TH1F * h_ttv = NULL;
  TH1F * h_zjets = NULL;  
  TH1F * h_wz= NULL;  
  TH1F * h_ww= NULL;  
  TH1F * h_zz = NULL;  
  TH1F * h_sig_www = NULL;
 
  if(use_data)  {
    getBackground(  h_data, iter, Form("data_%s" , selection.c_str() ), variable, type, region );h_data->SetBinErrorOption(TH1::kPoisson); 
  }
  if(use_ttbar){ 
    getBackground(  h_ttbar, iter, Form("ttbar_%s", selection.c_str() ),variable, type, region );
    bkghists.push_back(make_pair(use_ttbar,h_ttbar)); 
  }
  if(use_ttbar1l) {
    getBackground(  h_ttbar1l, iter, Form("ttbar_onelep_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_ttbar1l,h_ttbar1l)); 
  }
  if(use_ttbar2l) {
    getBackground(  h_ttbar2l, iter, Form("ttbar_dilep_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_ttbar2l,h_ttbar2l)); 
  }
  if(use_wjets) {
    getBackground(  h_wjets, iter, Form("wjets_stitch_%s", selection.c_str() ), variable,type, region );
    bkghists.push_back(make_pair(use_wjets,h_wjets)); 
  }
  if(use_zjets){
    getBackground(  h_zjets, iter, Form("zjets_stitch_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_zjets,h_zjets)); 
  } 
  if(use_singletop)  { 
    getBackground(  h_singletop, iter, Form("singletop_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_singletop,h_singletop)); 
  }
  if(use_ttv) {
    getBackground(  h_ttv, iter, Form("ttv_%s", selection.c_str() ), variable, type, region ); 
    bkghists.push_back(make_pair(use_ttv,h_ttv)); 
  }
  if(use_ww) {
    getBackground(  h_ww, iter, Form("ww_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_ww,h_ww)); 
  }
  if(use_wz)  {
    getBackground(  h_wz, iter, Form("wz_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_wz,h_wz)); 
  }
  if(use_zz)   {
    getBackground(  h_zz, iter, Form("zz_%s", selection.c_str() ), variable, type, region );
    bkghists.push_back(make_pair(use_zz,h_zz)); 
  }
  if(use_www)   {
    getBackground(  h_sig_www, iter, Form("www_stitch_%s", selection.c_str() ), variable, type, region );
  }

  if(debug)  cout<<"LINE::"<<__LINE__<<" got histograms from files"<<endl;
  //------------------------------------------------------------------------------------------------------//
  //-----------------------------              normalization               -------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(debug)  cout<<"LINE::"<<__LINE__<<" : normalized to luminosity of "<<luminosity<<endl;
  for(unsigned int ihist=0;ihist<bkghists.size();++ihist){
     if(bkghists.at(ihist).first)  bkghists.at(ihist).second->Scale(luminosity);
  }
 // normalization for signals.
  if(use_www)  h_sig_www->Scale(sigscaleup*luminosity);
  //------------------------------------------------------------------------------------------------------//
  //---------------------------------------------binning---- ---------------------------------------------//
  //------------------------------------------------------------------------------------------------------//

  float ymin = 1e-2; float ymax = 20;
  if(!setlog) {ymin = 1e-5;ymax =2;}
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
    if(use_wjets) {
       updateoverflow( h_wjets, xmax );
       h_wjets = (TH1F*) h_wjets->Rebin(nbins, "h_wjets_rebinned", bins); 
       renormalizebins(h_wjets);
       updateoverflow( h_wjets, xmax );
    }
    if(use_ttbar1l) {
       updateoverflow( h_ttbar1l, xmax );
       h_ttbar1l = (TH1F*) h_ttbar1l->Rebin(nbins, "h_ttbar1l_rebinned", bins);
       renormalizebins(h_ttbar1l);updateoverflow( h_ttbar1l, xmax );
    }
    if(use_ttbar2l) { 
       updateoverflow( h_ttbar2l, xmax );
       h_ttbar2l = (TH1F*) h_ttbar2l ->Rebin(nbins, "h_ttbar2l_rebinned", bins); 
       renormalizebins(h_ttbar2l); updateoverflow( h_ttbar2l, xmax );}
    if(use_singletop) {
       updateoverflow( h_singletop, xmax );
       h_singletop = (TH1F*) h_singletop    ->Rebin(nbins, "h_singletop_rebinned", bins);  
       renormalizebins(h_singletop); updateoverflow( h_singletop, xmax );
    }
    if(use_ttv) {
       updateoverflow( h_ttv, xmax );
       h_ttv = (TH1F*) h_ttv ->Rebin(nbins, "h_ttv_rebinned", bins);  
       renormalizebins(h_ttv);updateoverflow( h_ttv, xmax );
    }
    if(use_zjets) { 
       updateoverflow( h_zjets, xmax );
       h_zjets = (TH1F*) h_zjets    ->Rebin(nbins, "h_zjets_rebinned", bins);  
       renormalizebins(h_zjets);updateoverflow( h_zjets, xmax );
   }
    if(use_ww) {updateoverflow( h_ww, xmax );
       h_ww = (TH1F*) h_ww    ->Rebin(nbins, "h_ww_rebinned", bins);  
       renormalizebins(h_ww);
       updateoverflow( h_ww, xmax );
   }
    if(use_wz) {
       updateoverflow( h_wz, xmax );
       h_wz = (TH1F*) h_wz    ->Rebin(nbins, "h_wz_rebinned", bins); 
       renormalizebins(h_wz);
       updateoverflow( h_wz, xmax );
   }
    if(use_zz) {
       updateoverflow( h_zz, xmax );
       h_zz = (TH1F*) h_zz    ->Rebin(nbins, "h_zz_rebinned", bins);  
       renormalizebins(h_zz);updateoverflow( h_zz, xmax );
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
  if(use_ttbar2l) { 
     h_ttbar2l->SetFillColor(getColorSplitByMC_tribosonana(tt2l));
     h_ttbar2l->SetLineColor(getColorSplitByMC_tribosonana(tt2l));
     updateoverflow( h_ttbar2l, xmax );
  }
  if(use_ttbar1l) {
     h_ttbar1l->SetFillColor(getColorSplitByMC_tribosonana(tt1l));
     h_ttbar1l->SetLineColor(getColorSplitByMC_tribosonana(tt1l)) ;
     updateoverflow( h_ttbar1l, xmax );
 }
  if(use_wjets) { 
     h_wjets->SetFillColor(getColorSplitByMC_tribosonana(Wjets));
     h_wjets->SetLineColor(getColorSplitByMC_tribosonana(Wjets));
     updateoverflow( h_wjets, xmax );
  }
  if(use_zjets) { 
     h_zjets->SetFillColor(getColorSplitByMC_tribosonana(Zjets));
     h_zjets->SetLineColor(getColorSplitByMC_tribosonana(Zjets));
     updateoverflow( h_zjets, xmax );
  }
  if(use_singletop) { 
     h_singletop->SetFillColor(getColorSplitByMC_tribosonana(singleTop));
     h_singletop->SetLineColor(getColorSplitByMC_tribosonana(singleTop));
     updateoverflow(  h_singletop, xmax );
  }
  if(use_ttv) {
     h_ttv->SetFillColor(getColorSplitByMC_tribosonana(ttV));
     h_ttv->SetLineColor(getColorSplitByMC_tribosonana(ttV));
     updateoverflow(  h_ttv, xmax ); 
  }
  if(use_ww) { 
     h_ww->SetLineColor(getColorSplitByMC_tribosonana(WW));
     h_ww->SetFillColor(getColorSplitByMC_tribosonana(WW));
     updateoverflow( h_ww, xmax );
  }
  if(use_wz) { 
     h_wz->SetLineColor(getColorSplitByMC_tribosonana(WZ));
     h_wz->SetFillColor(getColorSplitByMC_tribosonana(WZ));
     updateoverflow( h_wz, xmax );
  }
  if(use_zz) { 
     h_zz->SetLineColor(getColorSplitByMC_tribosonana(ZZ));
     h_zz->SetFillColor(getColorSplitByMC_tribosonana(ZZ));
     updateoverflow( h_zz, xmax );
  }
  //------------------------------------------------------------------------------------------------------//
  //----------------------------- ----------set ymax------------------------------------------------------//
  //------------------------------------------------------------------------------------------------------//
  if(   TString(variable).Contains("dphi") ||  variable == "mhtphi" || type    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
    h_ttbar2l->GetYaxis()->SetRangeUser(0, h_ttbar2l->GetMaximum()*5 );  
  }
  else{
     h_ttbar2l->GetYaxis()->SetRangeUser(ymin*luminosity, h_ttbar2l->GetMaximum() * ymax );
     if(drawmoneyplot) h_ttbar2l->GetYaxis()->SetRangeUser(ymin,ymax );
   }
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
  float l1_xmin(0.4),l1_xmax(0.9),l1_ymin(0.68),l1_ymax(0.9);
  float l2_xmin(0.3),l2_xmax(0.65),l2_ymin(0.4),l2_ymax(0.68);
  if(use_sig && !use_data){ 
    l1_xmin = 0.55, l1_xmax=0.9, l1_ymin=0.58,l1_ymax=0.9; 
    l2_xmin = 0.2, l2_xmax=0.5, l2_ymin=0.8,l2_ymax=0.9;
  }
  TLegend *l1 = new TLegend(l1_xmin, l1_ymin,l1_xmax,l1_ymax);    
  TLegend *l2 = new TLegend(l2_xmin, l2_ymin, l2_xmax, l2_ymax);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l2->SetLineColor(kWhite);    
  l2->SetShadowColor(kWhite);    
  l2->SetFillColor(kWhite);    
  if(use_www)      l2->AddEntry(h_sig_www,Form("WWW x %i",sigscaleup), "l");
  if(!use_sig)  l1->SetNColumns(2);
  if(use_data)  l1->AddEntry( h_data  , "data"              , "lpe");
  if(use_ttbar2l)	l1->AddEntry( h_ttbar2l , "2l top quark"       , "f");    
  if(use_ttbar1l)	l1->AddEntry( h_ttbar1l , "1l top quark"       , "f");    
  if(use_zjets) l1->AddEntry( h_zjets , "DY"          , "f");               
  if(use_wjets) l1->AddEntry( h_wjets , "W+Jets "         , "f");            
  if(use_singletop)   l1->AddEntry( h_singletop , "single top"            , "f"); 
  if(use_ttv)   l1->AddEntry( h_ttv ,  "ttv"            , "f");
  if(use_zz) l1->AddEntry( h_zz , "ZZ"          , "f");
  if(use_wz) l1->AddEntry( h_wz , "WZ"          , "f");
  if(use_ww) l1->AddEntry( h_ww , "WW"          , "f");
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
  stack->SetMaximum(ymax);
  stack->GetXaxis()->SetLabelSize(0);
  stack->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  h_data_gr->Draw("pe,same");
  if(!drawmoneyplot)  {
    h_data_gr->GetXaxis()->SetRangeUser(xmin, xmax);
    h_data_gr->GetYaxis()->SetRangeUser(ymin*luminosity, h_data_gr->GetMaximum() * ymax );
  }
  else {
    h_data_gr->GetYaxis()->SetRangeUser(ymin, ymax);
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
  if(use_sig) l2->Draw();
  l1->Draw("same");
  c1->cd();

  TH1F* h_rat = (TH1F*)h_data  -> Clone("h_rat");
  TH1F* h_den = (TH1F*)h_wjets -> Clone("h_den");

  if(use_ttbar2l) h_den->Add(h_ttbar2l);
  if(use_ttbar1l) h_den->Add(h_ttbar1l);
  if(use_zjets) h_den->Add(h_zjets);
  if(use_singletop)   h_den->Add(h_singletop);
  if(use_ttv)   h_den->Add(h_ttv);
  if(use_ww)  h_den->Add(h_ww);
  if(use_wz)   h_den->Add(h_wz);
  if(use_zz)   h_den->Add(h_zz);

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
   for(int i = 1; i<=h_den->GetNbinsX(); ++i){
    h_den->SetBinError(i,h_den->GetBinContent(i)*0.3);
  }
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
  TH2F * h_axis = new TH2F("h_axis","h_axis",nbins,bins,2,ybins);// 2-d hists to set x/y axis
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
  h_axis->GetYaxis()->SetLabelSize(0.12);
  h_axis->GetXaxis()->SetLabelSize(0.12);
  h_axis->GetYaxis()->SetNdivisions(5);
  h_axis->GetYaxis()->SetTitle("#frac{Data}{MC}");
  h_axis->GetYaxis()->SetTitleSize(0.12);
  h_axis->GetYaxis()->SetTitleOffset(0.5);
  h_axis->GetYaxis()->CenterTitle();

  // set Xaxis titles.
  setxaxistitle(h_axis,variable);
  TH1F* h_rat_sys = (TH1F*)h_rat -> Clone("h_rat_sys");
  if(drawsys){
   for(int i = 1; i<=h_rat->GetNbinsX(); ++i){
    h_rat_sys->SetBinError(i,0.3);
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
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_ht.png", variable.c_str(), type.c_str(), selection.c_str() ));
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_ht.pdf", variable.c_str(), type.c_str(), selection.c_str() ));
  }
  else{ 
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_log_ht.png", variable.c_str(), type.c_str(), selection.c_str() ));
  c1->SaveAs(Form("${plot_output}/h_%s_%s_%s_log_ht.pdf", variable.c_str(), type.c_str(), selection.c_str() ));
  } 
 return;
}
