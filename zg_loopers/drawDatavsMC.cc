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
void drawDatavsMC( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string type = "ll", string variable = "mll", string region = "passtrig" )
{

  bool useedgebinning = false;
  bool usetemplates   = false;
  bool usefsbkg       = false;
  
  TH1F * h_data  = NULL;
  TH1F * h_wjets = NULL;
  TH1F * h_ttbar = NULL;
  TH1F * h_zjets = NULL;
  TH1F * h_QCD = NULL;
  // TH1F * h_other = NULL;
  // TH1F * h_vvbkg = NULL;

  // string variable = "mll";
  // string type = "ll";
  
  getBackground(   h_data, iter, Form("data%s" , selection.c_str() ), variable, type, region );
  if( usefsbkg ) getBackground(  h_ttbar, "V07-04-03_updatedHLT", Form("data%s", selection.c_str() ), "metgt1jet", "em", "inclusive" );
  else {
  getBackground(  h_ttbar, iter, Form("ttbar%s", selection.c_str() ), variable, type, region );
  getBackground(  h_zjets, iter, Form("zjets%s", selection.c_str() ), variable, type, region );
  getBackground(  h_QCD, iter, Form("QCD%s", selection.c_str() ), variable, type, region );
  }
  // getBackground(  h_wjets, iter, Form("wjets%s", selection.c_str() ), variable, type, region );
  // getBackground(  h_other, iter, Form("ttv%s"   , selection.c_str() ), "met", "ll" );
  // getBackground(  h_vvbkg, iter, Form("vv%s"    , selection.c_str() ), "met", "ll" );
  // getBackground(  h_wjets, iter, "All_MC", "jzb", "ll" );
  if( usetemplates ) getTemplateMET( h_wjets, "V07-04-03_updatedHLT", Form("data%s", selection.c_str() ) );
  else getBackground(  h_wjets, iter, Form("wjets%s", selection.c_str() ), variable, type, region );
  // getTemplateMET( h_wjets, iter, Form("data%s", selection.c_str() ) );
  // h_wjets->Scale(0.057);
  // h_ttbar->Scale(0.057);

  // h_data->Scale(luminosity);
  // h_other->Scale(luminosity);
  // h_vvbkg->Scale(luminosity);
  // h_vvbkg->Scale(0);

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

  // //MAKE TABLES
  // vector <float> metcut;
  // metcut.push_back(0.0);
  // metcut.push_back(50);
  // metcut.push_back(100);
  // metcut.push_back(150);
  // metcut.push_back(200);
  // metcut.push_back(300);
  // metcut.push_back(-1);
  // if( useedgebinning ){
  // 	metcut.clear();
  // 	metcut.push_back(0.0);
  // 	metcut.push_back(50);
  // 	if( TString(selection).Contains("2jets"  ) ){ metcut.push_back(150); }
  // 	if( TString(selection).Contains("3jets"  ) ){ metcut.push_back(100); }
  // 	metcut.push_back(-1);

  // }

  
  // vector <double> val_data;
  // vector <double> err_data;

  // vector <double> val_wjets;
  // vector <double> err_wjets;

  // vector <double> val_fsbkg;
  // vector <double> err_fsbkg;

  // vector <double> val_other;
  // vector <double> err_other;

  // vector <double> val_vvbkg;
  // vector <double> err_vvbkg;

  // vector <double> val_allbg;
  // vector <double> err_allbg;

  // vector <double> val_ratio;
  // vector <double> err_ratio;
  
  // for( size_t i = 0; i < metcut.size(); i++ ){
  // 	val_data.push_back(0);
  // 	err_data.push_back(0);
  // 	val_wjets.push_back(0);
  // 	err_wjets.push_back(0);
  // 	val_fsbkg.push_back(0);
  // 	err_fsbkg.push_back(0);
  // 	val_other.push_back(0);
  // 	err_other.push_back(0);
  // 	val_vvbkg.push_back(0);
  // 	err_vvbkg.push_back(0);
  // 	val_allbg.push_back(0);
  // 	err_allbg.push_back(0);
  // 	val_ratio.push_back(0);
  // 	err_ratio.push_back(0);
  // }

  // for( size_t bini = 0; bini < metcut.size()-1; bini++ ){
  // 	if( bini < metcut.size()-1 ){
  // 	  val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_data .at(bini));
  // 	  val_wjets.at(bini) = h_wjets->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_wjets.at(bini));
  // 	  val_fsbkg.at(bini) = h_fsbkg->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = h_other->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_other.at(bini));
  // 	  val_vvbkg.at(bini) = h_vvbkg->IntegralAndError( metcut.at(bini), metcut.at(bini+1)-1, err_vvbkg.at(bini));
  // 	}
  // 	if( bini == metcut.size()-1 ){
  // 	  val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini), -1, err_data .at(bini));
  // 	  val_wjets.at(bini) = h_wjets->IntegralAndError( metcut.at(bini), -1, err_wjets.at(bini));
  // 	  val_fsbkg.at(bini) = h_fsbkg->IntegralAndError( metcut.at(bini), -1, err_fsbkg.at(bini));
  // 	  val_other.at(bini) = h_other->IntegralAndError( metcut.at(bini), -1, err_other.at(bini));
  // 	  val_vvbkg.at(bini) = h_vvbkg->IntegralAndError( metcut.at(bini), -1, err_vvbkg.at(bini));
  // 	}
  // }

  // float norm_factor = (val_data.at(0) -
  // 					   val_fsbkg.at(0) -
  // 					   val_vvbkg.at(0) -
  // 					   val_other.at(0))/(val_wjets.at(0));
  // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // 	val_wjets.at(bini) *= norm_factor;
  //   err_wjets.at(bini) *= norm_factor;
  // }

  // for( size_t bini = 0; bini < metcut.size(); bini++ ){
  // 	val_allbg.at(bini) = val_wjets.at(bini) + val_fsbkg.at(bini) + val_other.at(bini) + val_vvbkg.at(bini);
  // 	err_allbg.at(bini) = sqrt( pow(err_wjets.at(bini), 2) + pow(err_fsbkg.at(bini), 2) + pow(err_other.at(bini), 2) + pow(err_vvbkg.at(bini), 2));
  // 	val_ratio.at(bini) = val_data .at(bini)/val_allbg.at(bini);
  // 	err_ratio.at(bini) = err_mult( val_data .at(bini), val_allbg.at(bini),
  // 								   err_data .at(bini), err_allbg.at(bini), val_data .at(bini)/val_allbg.at(bini));
  // }
  
  // cout<<"$\\mathrm{E_{T}^{miss} [GeV]}$ &";
  // for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
  // 	cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
  // }
  // cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
  // cout<<endl;

  // if( useedgebinning ){
  // 	cout<<"\\hline "<<endl;
  // 	cout<<"Z+jets& ";
  // 	for( size_t bini = 0; bini < val_wjets.size()-1; bini++ ){
  // 	  if( bini < val_wjets.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_wjets.at(bini)+val_vvbkg.at(bini)+val_other.at(bini), sqrt(pow(err_wjets.at(bini),2) + pow(err_vvbkg.at(bini), 2) + pow(err_other.at(bini), 2) ));
  // 	  if( bini == val_wjets.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_wjets.at(bini)+val_vvbkg.at(bini)+val_other.at(bini), sqrt(pow(err_wjets.at(bini),2) + pow(err_vvbkg.at(bini), 2) + pow(err_other.at(bini), 2) ));
  // 	}
  // 	cout<<endl;

  // 	cout<<"FS bkg& ";
  // 	for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	  if( bini < val_fsbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	  if( bini == val_fsbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	}
  // 	cout<<endl;

  // }else{
  // 	cout<<"\\hline "<<endl;
  // 	cout<<"Z+jets& ";
  // 	for( size_t bini = 0; bini < val_wjets.size()-1; bini++ ){
  // 	  if( bini < val_wjets.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_wjets.at(bini), err_wjets.at(bini));
  // 	  if( bini == val_wjets.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_wjets.at(bini), err_wjets.at(bini));
  // 	}
  // 	cout<<endl;

  // 	cout<<"FS bkg& ";
  // 	for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
  // 	  if( bini < val_fsbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	  if( bini == val_fsbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
  // 	}
  // 	cout<<endl;

  // 	cout<<"WZ + ZZ bkg& ";
  // 	for( size_t bini = 0; bini < val_vvbkg.size()-1; bini++ ){
  // 	  if( bini < val_vvbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_vvbkg.at(bini), err_vvbkg.at(bini));
  // 	  if( bini == val_vvbkg.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_vvbkg.at(bini), err_vvbkg.at(bini));
  // 	}
  // 	cout<<endl;

  // 	cout<<"rare SM BG& ";
  // 	for( size_t bini = 0; bini < val_other.size()-1; bini++ ){
  // 	  if( bini < val_other.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f & ", val_other.at(bini), err_other.at(bini));
  // 	  if( bini == val_other.size()-2 )
  // 		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_other.at(bini), err_other.at(bini));
  // 	}
  // 	cout<<endl;
  // }
  
  // cout<<"\\hline "<<endl;
  // cout<<"total BG& ";
  // for( size_t bini = 0; bini < val_allbg.size()-1; bini++ ){
  // 	if( bini < val_allbg.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_allbg.at(bini), err_allbg.at(bini));
  // 	if( bini == val_allbg.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_allbg.at(bini), err_allbg.at(bini));
  // }
  // cout<<endl;

  // cout<<"\\hline "<<endl;
  // cout<<"all MC& ";
  // for( size_t bini = 0; bini < val_data.size()-1; bini++ ){
  // 	if( bini < val_data.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f & ", val_data.at(bini), err_data.at(bini));
  // 	if( bini == val_data.size()-2 )
  // 	  cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_data.at(bini), err_data.at(bini));
  // }
  // cout<<endl;

  // cout<<"\\hline "<<endl;
  
  // cout<<"All MC/BG& ";
  // for( size_t bini = 0; bini < val_ratio.size()-1; bini++ ){
  // 	if( bini < val_ratio.size()-2 )
  // 	  cout<<Form(" %.2f $\\pm$ %.2f & ", val_ratio.at(bini), err_ratio.at(bini));
  // 	if( bini == val_ratio.size()-2 )
  // 	  cout<<Form(" %.2f $\\pm$ %.2f \\\\ ", val_ratio.at(bini), err_ratio.at(bini));
  // }
  // cout<<endl;


  //MAKE PLOTS
  float xmin = 50; float xmax = 200;
  float ymin = 1e-1; float ymax = 1e2;

  int rebin = 5;
  
  if( variable == "mt3" ){
	xmin = 0;
	xmax = 150;
    // ymin = 0;
	rebin = 25;
  }
  if( TString(variable).Contains("MHT") ){
	xmin = 0;
	xmax = 250;
    // ymin = 0;
	rebin = 5;
  }
  if( TString(variable).Contains("mhtphi") ){
	// xmin = 0;
	// xmax = 250;
    // // ymin = 0;
	rebin = 5;
  }
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
  if( TString(variable).Contains("met") ){
	if( type == "em" ) rebin = 10;
	else rebin = 10;
	  xmin = 0;
	  if( usefsbkg ) xmax = 150;
	  else           xmax = 150;
    ymax = 5e1;
  }
  if( variable == "ht" ){
	xmin = 0;
	xmax = 500;
    // ymax = 5e1;
	rebin = 10;
  }
  if( TString(variable).Contains("pt") ){
	xmin = 0;
	xmax = 200;
    // ymax = 5e1;
	rebin = 5;
  }
  if( variable == "njets" ){
	xmin = 0;
	xmax = 10;
    ymax = 5e1;
	rebin = 1;
  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	xmin = -3.2;
	xmax = 3.2;
	ymax = 1000;
	rebin = 5;
  }
  
  h_data->Rebin(rebin);
  h_wjets->Rebin(rebin);
  h_ttbar->Rebin(rebin);
  h_zjets->Rebin(rebin);
  h_QCD->Rebin(rebin);

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
  if( !(TString(variable).Contains("phi") || variable == "nVert" || variable == "mhtphi" || type == "em" || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir") ){
	pad->SetLogy();
  }
  
  h_data->SetLineWidth(2);

  h_wjets->SetFillColor(kBlue);
  h_ttbar->SetFillColor(kCyan-3);
  h_zjets->SetFillColor(kGreen+2);
  h_QCD->SetFillColor(kOrange-2);

  h_wjets->SetFillStyle(1001);
  h_ttbar->SetFillStyle(1001);
  h_zjets->SetFillStyle(1001);
  h_QCD->SetFillStyle(1001);

  float norm_factor =   h_data->Integral(h_data->FindBin(81),h_data->FindBin(100)-1)/
	(h_wjets->Integral(h_wjets->FindBin(81),h_wjets->FindBin(101)-1) +
	 h_ttbar->Integral(h_ttbar->FindBin(81),h_ttbar->FindBin(101)-1));
  cout<<"Norm factor for Z+jets: "<<norm_factor<<endl;

  if( variable != "mll" ){
	if( region == "passtrig" ){
	  if( type == "ll" ) norm_factor = 2.71145;
	  if( type == "ee" ) norm_factor = 4.19728;
	  if( type == "mm" ) norm_factor = 1.52758;
	}
	if( region == "inclusive" ){
	  if( type == "ll" ) norm_factor = 6.49903;
	  if( type == "ee" ) norm_factor = 6.11659;
	  if( type == "mm" ) norm_factor = 6.81433;
	}
  }

  norm_factor = 1;
  
  //h_wjets->Scale(norm_factor);
  //h_ttbar->Scale(norm_factor);
//  h_wjets->Scale(luminosity);
//  h_ttbar->Scale(luminosity);
  
  updateoverflow( h_data , xmax );
  updateoverflow( h_wjets, xmax );
  updateoverflow( h_ttbar, xmax );
  updateoverflow( h_zjets, xmax );
  updateoverflow( h_QCD, xmax );

  THStack * stack = new THStack("stack","");

  stack->Add(h_QCD);
  stack->Add(h_zjets);
  stack->Add(h_ttbar);
  stack->Add(h_wjets);
  
  h_data->GetXaxis()->SetLabelSize(0);
  h_data->GetYaxis()->SetLabelSize(0.05);
  h_data->GetYaxis()->SetTitleOffset(1.5);
  h_data->GetYaxis()->SetTitleSize(0.05);
  h_data->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  if( TString(variable).Contains("phi") || variable == "mhtphi" || type    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_data->GetYaxis()->SetRangeUser(0, h_data->GetMaximum()*1.4 );  
  }
  else{
	h_data->GetYaxis()->SetRangeUser(ymin*luminosity, h_data->GetMaximum() * ymax );
  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_data->GetYaxis()->SetRangeUser(0, h_data->GetMaximum()*1.4 );  
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
  l1->AddEntry( h_QCD , "QCD"          , "f");
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
  h_den->Add(h_ttbar);
  h_den->Add(h_zjets);
  h_den->Add(h_QCD);

  h_rat->Divide(h_den);

  h_rat->GetYaxis()->SetRangeUser(0.6,1.4);
  if( TString(variable).Contains("met") ){
  h_rat->GetYaxis()->SetRangeUser(0.0,2.0);
  }
  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);

  h_rat->GetYaxis()->SetTitle("#frac{Data}{Prediction}");
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.5);
  h_rat->GetYaxis()->CenterTitle();
  // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  if( variable == "nVert"               ) h_rat->GetXaxis()->SetTitle("N_{vtx}");
  if( TString(variable).Contains("met") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( TString(variable).Contains("MHT") ) h_rat->GetXaxis()->SetTitle("H_{T}^{miss} GeV");
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
