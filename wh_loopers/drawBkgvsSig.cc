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
void drawBkgvsSig( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string type = "ll", string variable = "mll", string region = "passtrig" )
{
  bool usetemplates   = false;
  bool usefsbkg       = false;
  bool use_data(true); 
  bool use_wjets(true),use_ttbar(false),use_ttbar1l(true),use_ttbar2l(true),use_zjets(false),use_wbb(true);
  bool use_top(true),use_ttv(true),use_diboson(true);
  bool use_sig(false);
  bool use_norm_factor(false); float norm_factor = 1;
  int scaleup = 100;

  TH1F * h_data  = NULL;
  TH1F * h_ttbar = NULL;
  TH1F * h_ttbar1l = NULL;
  TH1F * h_ttbar2l = NULL;
  TH1F * h_wjets = NULL;
  TH1F * h_zjets = NULL;
  TH1F * h_top = NULL;
  TH1F * h_ttv = NULL;
  TH1F * h_wbb = NULL;  
  TH1F * h_diboson = NULL;  

  TH1F * h_sig_350_1 = NULL;
  TH1F * h_sig_300_80 = NULL;
  TH1F * h_sig_250_1 = NULL;
  TH1F * h_sig_225_80 = NULL;

  cout<<"entries"<<endl;
 
  if(use_data)  getBackground(  h_data, iter, Form("data_%s" , selection.c_str() ), variable, type, region );
  if(use_ttbar) getBackground(  h_ttbar, iter, Form("ttbar_%s", selection.c_str() ),variable, type, region );
  if(use_ttbar1l) getBackground(  h_ttbar1l, iter, Form("ttbar_%s", selection.c_str() ), variable,"lep_onelep" , region );
  if(use_ttbar2l) getBackground(  h_ttbar2l, iter, Form("ttbar_%s", selection.c_str() ), variable,"lep_dilep", region );
  //if(use_wjets) getBackground(  h_wjets, iter, Form("wjets_htbin_%s", selection.c_str() ), variable, type, region );
  if(use_wjets) getBackground(  h_wjets, iter, Form("wjets_%s", selection.c_str() ), variable, type, region );
  if(use_zjets) getBackground(  h_zjets, iter, Form("zjets_htbin_%s", selection.c_str() ), variable, type, region );
  if(use_top)   getBackground(  h_top, iter, Form("top_%s", selection.c_str() ), variable, type, region );
  if(use_ttv)   getBackground(  h_ttv, iter, Form("ttv_%s", selection.c_str() ), variable, type, region );
  if(use_wbb)   getBackground(  h_wbb, iter, Form("wbb_%s", selection.c_str() ), variable, type, region );
  if(use_diboson)   getBackground(  h_diboson, iter, Form("diboson_%s", selection.c_str() ), variable, type, region );
  if(use_sig)   getBackground(  h_sig_350_1, iter, Form("wh_350_1_%s", selection.c_str() ), variable, type, region );
  if(use_sig)   getBackground(  h_sig_300_80, iter, Form("wh_300_80_%s", selection.c_str() ), variable, type, region );
  if(use_sig)   getBackground(  h_sig_250_1, iter, Form("wh_250_1_%s", selection.c_str() ), variable, type, region );
  if(use_sig)   getBackground(  h_sig_225_80, iter, Form("wh_225_80_%s", selection.c_str() ), variable, type, region );

  //------------------------------------------------------------------------------------------------------//
  //-----------------------------              normalization               -------------------------------//
  //------------------------------------------------------------------------------------------------------//

  if(use_norm_factor) 
//        norm_factor =   h_data->Integral(h_data->FindBin(81),h_data->FindBin(100)-1)/
//	(h_wjets->Integral(h_wjets->FindBin(81),h_wjets->FindBin(101)-1) +
//	 h_ttbar->Integral(h_ttbar->FindBin(81),h_ttbar->FindBin(101)-1));
 //        cout<<"Norm factor for Z+jets: "<<norm_factor<<endl;
  if(use_wjets) h_wjets->Scale(norm_factor*luminosity);
  if(use_ttbar1l) h_ttbar1l->Scale(norm_factor*luminosity);
  if(use_ttbar2l) h_ttbar2l->Scale(norm_factor*luminosity);
  if(use_top)   h_top->Scale(luminosity);
  if(use_ttv)   h_ttv->Scale(luminosity);
  if(use_zjets) h_zjets->Scale(luminosity);
  if(use_wbb)   h_wbb->Scale(luminosity);
  if(use_diboson)   h_diboson->Scale(luminosity);
 // normalization for signals.
  if(use_sig){
   h_sig_350_1->Scale(luminosity*scaleup);
   h_sig_300_80->Scale(luminosity*scaleup);
   h_sig_250_1->Scale(luminosity*scaleup);
   h_sig_225_80->Scale(luminosity*scaleup);
   /*h_sig_350_1->Scale(luminosity*scaleup*0.00128300190114);
   h_sig_300_80->Scale(luminosity*scaleup*0.00206056387342);
   h_sig_250_1->Scale(luminosity*scaleup*0.00497616088593);
   h_sig_225_80->Scale(luminosity*scaleup*0.00579149982859);
  */
  }
 
  //------------------------------------------------------------------------------------------------------//
  //------------------------------MAKE PLOTS --> binning etc ---------------------------------------------//
  //------------------------------------------------------------------------------------------------------//

  float xmin = 50; float xmax = 500;
  //float ymin = 1e-1; float ymax = 1.5;
  float ymin = 0; float ymax = 1.5;
  int rebin = 20;
  if( TString(variable).Contains("MHT") ){	xmin = 0;	xmax = 250;	rebin = 5;  }
  if( TString(variable).Contains("NEvents") ){	xmin = 0.5;	xmax = 8.5;	rebin = 1;  }
  if( TString(variable).Contains("mhtphi") ){	xmin = 0;	xmax = 250;        ymin = 0;	rebin = 5;  }
  if( variable == "nVert" ){ xmin = 0;    xmax = 50;    ymax = 100;    ymin = 0;    rebin = 1;}
  if( TString(variable).Contains("met") || TString(variable).Contains("mt") || TString(variable).Contains("MT2") || TString(variable).Contains("mbb") ||TString(variable).Contains("ptbb")|| TString(variable).Contains("MCT"))
   //{  rebin = 25; xmin = 0;	  xmax = 1000;           ymax = 5e1; }
   {  rebin = 25; xmin = 0;	  xmax = 500;          }
  if( variable == "ht" ){xmin = 0;	xmax = 500;	rebin = 25; ymax = 5e1;}
  if( TString(variable).Contains("iso")){ xmin = 0;     xmax = 100;     rebin = 10;  }
  if( TString(variable).Contains("relIso")){     xmin = 0;     xmax = 10;     rebin = 20;  } 
  if( TString(variable).Contains("absIso")){     xmin = 0;     xmax = 100;     rebin = 5;  }
  if( TString(variable).Contains("pt") ){	xmin = 0;	xmax = 500;	rebin = 50;  }
  if( variable == "njets" || variable == "nbjets"){ xmin = 0;	xmax = 10;      	rebin = 1;  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
       xmin = -3.2;
	xmax = 3.2;
	ymax = 1000;
	rebin = 10;
  }

 if(use_data)  h_data->Rebin(rebin);
 if(use_wjets) h_wjets->Rebin(rebin);
 if(use_ttbar1l) h_ttbar1l->Rebin(rebin);
 if(use_ttbar2l) h_ttbar2l->Rebin(rebin);
 if(use_top)   h_top->Rebin(rebin);
 if(use_ttv)   h_ttv->Rebin(rebin);
 if(use_zjets) h_zjets->Rebin(rebin);
 if(use_wbb)   h_wbb->Rebin(rebin);
 if(use_diboson)   h_diboson->Rebin(rebin);
 if(use_sig)  { h_sig_350_1->Rebin(rebin);   h_sig_300_80->Rebin(rebin);   h_sig_250_1->Rebin(rebin);   h_sig_225_80->Rebin(rebin); }
//drawing on canvas and all that.
  if(use_data) { updateoverflow( h_data , xmax );  h_data->SetMarkerStyle(8); h_data->SetMarkerSize(0.75); }
  if(use_ttbar2l) { h_ttbar2l->SetFillStyle(1001);h_ttbar2l->SetFillColor(kAzure+4);h_ttbar2l->SetLineColor(kAzure+4) ;updateoverflow( h_ttbar2l, xmax );}
  if(use_ttbar1l) { h_ttbar1l->SetFillStyle(1001);h_ttbar1l->SetFillColorAlpha(kAzure+4,0.8);h_ttbar1l->SetLineColor(kAzure-5) ;updateoverflow( h_ttbar1l, xmax );}
  if(use_wjets) { h_wjets->SetFillColor(kRed-7); updateoverflow( h_wjets, xmax );h_wjets->SetLineColor(kRed-7);}
  if(use_wbb) { h_wbb->SetLineColorAlpha(kRed-7,0.8);updateoverflow( h_wbb, xmax );h_wbb->SetFillColorAlpha(kRed-7,0.8);}
  if(use_top) { h_top->SetFillColorAlpha(kOrange-3,0.9); updateoverflow( h_top, xmax );h_top->SetLineColor(kOrange-3);}
  if(use_ttv) { h_ttv->SetFillColor(kMagenta-5);updateoverflow( h_ttv, xmax );h_ttv->SetLineColor(kMagenta-5);}
  if(use_diboson) { h_diboson->SetLineColor(kMagenta-5);updateoverflow( h_diboson, xmax );h_diboson->SetFillColorAlpha(kMagenta-5,0.7);}
  if(use_zjets) { h_zjets->SetLineColor(kGreen+2);updateoverflow( h_zjets, xmax );h_zjets->SetFillColor(kGreen+2);}
   
  //some special settings

  if( TString(variable).Contains("phi") || variable == "mhtphi" || type    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_ttbar2l->GetYaxis()->SetRangeUser(0, h_ttbar2l->GetMaximum()*1.4 );  
  }
  else{
	h_ttbar2l->GetYaxis()->SetRangeUser(ymin*luminosity, h_ttbar2l->GetMaximum() * ymax );
  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_ttbar2l->GetYaxis()->SetRangeUser(0, h_ttbar2l->GetMaximum()*1.4 );  
  }
 //stacked histograms 
  THStack * stack = new THStack("stack","stacked");
  if(use_zjets) stack->Add(h_zjets,"hist");
  if(use_diboson) stack->Add(h_diboson,"hist");
  if(use_ttv)   stack->Add(h_ttv,"hist");
  if(use_wbb) stack->Add(h_wbb,"hist");
  if(use_wjets) stack->Add(h_wjets,"hist");
  if(use_top)   stack->Add(h_top,"hist");
  if(use_ttbar1l) stack->Add(h_ttbar1l,"hist");
  if(use_ttbar2l) stack->Add(h_ttbar2l,"hist");
 //legend to draw 
  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.9);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->SetNColumns(2);
  if(use_data)  l1->AddEntry( h_data  , "data"              , "lpe");
  if(use_ttbar2l)	l1->AddEntry( h_ttbar2l , "t#bar{t} 2l"       , "f");    if(use_sig)      l1->AddEntry(h_sig_350_1, Form("(350,1) x %i",scaleup), "l");
  if(use_ttbar1l)	l1->AddEntry( h_ttbar1l , "t#bar{t} 1l"       , "f");    if(use_sig)      l1->AddEntry(h_sig_250_1, Form("(250,1) x %i",scaleup), "l");
  if(use_top)   l1->AddEntry( h_top , "single top"            , "f");            if(use_sig)      l1->AddEntry(h_sig_300_80,Form("(300,80) x %i",scaleup), "l");
  if(use_wjets) l1->AddEntry( h_wjets , "W+jets "         , "f");                if(use_sig)      l1->AddEntry(h_sig_225_80,Form("(225,80) x %i",scaleup), "l");
  //l1->SetNColumns(1);
  if(use_wbb) l1->AddEntry( h_wbb , "W+b#bar{b}/WZ(b#bar{b})"          , "f");
  if(use_ttv)   l1->AddEntry( h_ttv ,  "ttv"            , "f");
  if(use_diboson) l1->AddEntry( h_diboson , "diboson"          , "f");
  if(use_zjets) l1->AddEntry( h_zjets , "DY"            , "f");
  TCanvas * c1 = new TCanvas("c1","");
//  c1->SetWindowSize(800, 600);
  c1->SetTopMargin(0.06);
  c1->SetRightMargin(0.07);
  if(use_data) {
  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  pad->SetBottomMargin(0.05);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.08);
  pad->SetLeftMargin(0.18);
  pad->Draw(); pad->cd();
  if( !(TString(variable).Contains("phi") || variable == "nVert" || variable == "mhtphi" || type == "em" || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir") ){
	pad->SetLogy();
  } 
   
  h_data->GetXaxis()->SetRangeUser(xmin, xmax);
  h_data->SetMarkerStyle(8);
  h_data->SetMarkerSize(0.75);
  h_data->Draw("e1");
  stack->Draw("samehist");
  h_data->Draw("samex0e1");

  pad->RedrawAxis();
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

  TH1F* h_rat = (TH1F*)h_data  -> Clone("h_rat");
  TH1F* h_den = (TH1F*)h_wjets -> Clone("h_den");
  h_den->Add(h_ttbar2l);
  h_den->Add(h_ttbar1l);
  h_den->Add(h_zjets);
  h_den->Add(h_top);
  h_den->Add(h_ttv);
  
  h_rat->Divide(h_den);

  h_rat->GetYaxis()->SetRangeUser(0.0,2.0);
  if( TString(variable).Contains("met") ){
  h_rat->GetYaxis()->SetRangeUser(0.0,2.0);
  }
//  h_rat->GetXaxis()->SetLimits(xmin,xmax);
  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);
  h_rat->GetYaxis()->SetTitle("#frac{Data}{MC}");
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.5);
  h_rat->GetYaxis()->CenterTitle();

  if( variable == "nVert"               )    h_rat->GetXaxis()->SetTitle("N_{vtx}");
  if( TString(variable).Contains("met") )    h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( TString(variable).Contains("absIso") )    h_rat->GetXaxis()->SetTitle("absIso03 GeV");
  if( TString(variable).Contains("mt") )     h_rat->GetXaxis()->SetTitle("m_{T}(l;#nu) GeV");
  if( TString(variable).Contains("MHT") )    h_rat->GetXaxis()->SetTitle("H_{T}^{miss} GeV");
  if( TString(variable).Contains("mhtphi") ) h_rat->GetXaxis()->SetTitle("H_{T} Phi");
  if( variable == "ht"                  ) h_rat->GetXaxis()->SetTitle("H_{T} GeV");
  if( TString(variable).Contains("pt")  ) h_rat->GetXaxis()->SetTitle("p_{T} GeV");
  if( variable == "njets"               ) h_rat->GetXaxis()->SetTitle("N_{jets}");  
  if( variable == "mll"                 ) h_rat->GetXaxis()->SetTitle("M_{\\ell\\ell} GeV");
  if( TString(variable).Contains("phi") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} #phi");
  if( TString(variable).Contains("_pt") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);
  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);
  h_rat->Draw("e0x0");
  h_rat->Draw("e1x0same");

  TLine * xaxis = new TLine(xmin,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
  drawCMSLatex( c1, luminosity);
  }

  if(!use_data){
  stack->Draw();
  if( variable == "nVert"               )    stack->GetXaxis()->SetTitle("N_{vtx}");
  if( variable == "mbb"               )    stack->GetXaxis()->SetTitle("M_{bb} GeV");
  if( variable == "MCT"               )    stack->GetXaxis()->SetTitle("MCT");
  if( TString(variable).Contains("met") )    stack->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( TString(variable).Contains("MT2W") )    stack->GetXaxis()->SetTitle("MT2W GeV");
  if( TString(variable).Contains("absIso") )    stack->GetXaxis()->SetTitle("absIso03 GeV");
  if( TString(variable).Contains("mt") )     stack->GetXaxis()->SetTitle("m_{T}(l;#nu) GeV");
  if( TString(variable).Contains("MHT") )    stack->GetXaxis()->SetTitle("H_{T}^{miss} GeV");
  if( TString(variable).Contains("mhtphi") ) stack->GetXaxis()->SetTitle("H_{T} Phi");
  if( variable == "ht"                  ) stack->GetXaxis()->SetTitle("H_{T} GeV");
  if( TString(variable).Contains("pt")  ) stack->GetXaxis()->SetTitle("p_{T} GeV");
  if( variable == "njets"               ) stack->GetXaxis()->SetTitle("N_{jets}");  
  if( variable == "nbjets"               ) stack->GetXaxis()->SetTitle("N_{bjets}");  
  if( variable == "mll"                 ) stack->GetXaxis()->SetTitle("M_{\\ell\\ell} GeV");
  if( TString(variable).Contains("phi") ) stack->GetXaxis()->SetTitle("E_{T}^{miss} #phi");
  if( TString(variable).Contains("_pt") ) stack->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  stack->GetXaxis()->SetLimits(xmin,xmax);
  stack->GetXaxis()->SetTitleOffset(0.9);
  stack->GetXaxis()->SetTitleSize(0.15);
  stack->GetXaxis()->SetLabelSize(0.04);
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
     h_sig_300_80->SetLineColor(kRed+1); h_sig_300_80->SetLineStyle(5);h_sig_300_80->SetLineWidth(4); updateoverflow(h_sig_300_80,xmax);
     h_sig_225_80->SetLineColor(kGreen+3); h_sig_225_80->SetLineStyle(5);h_sig_225_80->SetLineWidth(4); updateoverflow(h_sig_225_80,xmax);  
     h_sig_350_1->SetLineColor(kBlack+3);  h_sig_350_1->SetLineStyle(5);h_sig_350_1->SetLineWidth(4);   updateoverflow(h_sig_350_1,xmax);
     h_sig_250_1->SetLineColor(kMagenta+3);  h_sig_250_1->SetLineStyle(5); h_sig_250_1->SetLineWidth(4);  updateoverflow(h_sig_250_1,xmax);

     h_sig_350_1->Draw("SAMEHIST");
     h_sig_300_80->Draw("SAMEHIST");
     h_sig_225_80->Draw("SAMEHIST");
     h_sig_250_1->Draw("SAMEHIST");
  }
  if(!use_data) {
  //c1->SetLogy();
  c1->RedrawAxis();
  c1->Modified();
  l1->Draw();
  drawCMSLatex( c1, luminosity*norm_factor );
  }
  c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_%s.png", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
  c1->SaveAs(Form("${plot_output}/h_%s_%s_signalregion%s_%s.pdf", variable.c_str(), type.c_str(), selection.c_str(), region.c_str() ));
  return;
}
