#include <iostream>
#include <utility>
#include <string>
#include <sstream>

#include "TH1.h"
#include "TFile.h"
#include "TList.h"
#include "TIterator.h"
#include "TRegexp.h"
#include "TObject.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TMath.h"
#include "histTools.h"

using namespace std;


float err_mult(float A, float B, float errA, float errB, float C) {
  return sqrt(C*C*(pow(errA/A,2) + pow(errB/B,2)));
}

double getBinomialError( const double num, const double deno ){
  double   p       =   num / deno;
  double   error   =   sqrt(p*(1-p)/deno);
  return error;  
}

void fillUnderOverFlow(TH1F * &h1, float value, float weight){
  float min = h1->GetXaxis()->GetXmin();
  float max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void fillUnderOverFlow(TH1D * &h1, double value, float weight){
  double min = h1->GetXaxis()->GetXmin();
  double max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void getenvelope(TH1F * &h1, TH1F* h1_up,TH1F* h1_down){
  if (h1->GetNbinsX()!=h1_up->GetNbinsX() || h1->GetNbinsX()!=h1_down->GetNbinsX())
  { cout<<"number of bins are not the same"<<endl; return;}
  for (int bini = 0; bini < h1->GetNbinsX(); bini++){
      double newerror = fabs( h1_up->GetBinContent(bini+1)-h1->GetBinContent(bini + 1)) > fabs( h1_down->GetBinContent(bini+1)-h1->GetBinContent(bini+1)) ? fabs( h1_up->GetBinContent(bini+1)-h1->GetBinContent(bini+1)):fabs( h1_down->GetBinContent(bini+1)-h1->GetBinContent(bini+1));
       h1->SetBinError  ( bini + 1, newerror );
  }
}

void setsys(TH1F * &h1, float sys){
  for (int bini = 0; bini < h1->GetNbinsX(); bini++){
       double newerror = sqrt(pow(h1->GetBinContent(bini+1)*sys,2)+ pow(h1->GetBinError(bini+1),2));
       h1->SetBinError  ( bini + 1, newerror );
   }
}

void saveHist(const string filename, const string pat)
{
  TList* list = gDirectory->GetList() ;
  TIterator* iter = list->MakeIterator();
  TRegexp re(pat.c_str(),kTRUE) ;
  TObject *obj;
  TFile outf(filename.c_str(),"RECREATE") ;
  while((obj=iter->Next())) {
	if (TString(obj->GetName()).Index(re)>=0  && !TString(obj->GetName()).Contains("err2")) {
	  obj->Write() ;
	  cout << "." ;
	  cout.flush() ;
	}
  }
  cout << endl ;
  outf.Close() ;
  delete iter ;
}

void drawCMSLatex( TCanvas * &canvas, float luminosity , bool is_simulation)
{

  canvas->cd();
  TLatex *lumitex = NULL;
  lumitex = new TLatex(0.66,0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex->SetNDC();    
  lumitex->SetTextSize(0.04);    
  lumitex->SetLineWidth(2);
  lumitex->SetTextFont(42);    
  lumitex->Draw();

  TLatex *cmstex = NULL;
 if( !is_simulation) cmstex = new TLatex(0.18,0.95, "CMS" );    
 else if (is_simulation) cmstex = new TLatex(0.18,0.95, "CMS Simulation" );
  cmstex->SetNDC();    
  cmstex->SetTextSize(0.04);    
  cmstex->SetLineWidth(2);
  cmstex->SetTextFont(62);    
  cmstex->Draw();

  return;
}

void drawCMSLatex( TCanvas * &canvas, float luminosity, float cmsleftmargin, float lumileftmargin )
{

  canvas->cd();
  TLatex *lumitex = NULL;
  // lumitex = new TLatex(lumileftmargin, 0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex = new TLatex(lumileftmargin, 0.955, Form("%.1f fb^{-1} (13 TeV)", luminosity) );    
  lumitex->SetNDC();    
  lumitex->SetTextSize(0.04);    
  lumitex->SetLineWidth(2);
  lumitex->SetTextFont(42);    
  lumitex->Draw();

  TLatex *cmstex = NULL;
  cmstex = new TLatex(cmsleftmargin, 0.95, "CMS Simulation" );    
  cmstex->SetNDC();    
  cmstex->SetTextSize(0.04);    
  cmstex->SetLineWidth(2);
  cmstex->SetTextFont(62);    
  cmstex->Draw();

  return;
}

void getBackground( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );  
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  if(infile->IsZombie())  cout<<"can not red from file :"<<filename<<endl;
  backgroundhist = dynamic_cast<TH1F*>(infile->Get(Form("h_%s_event_%s_%s", leptype.c_str(), variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getYield( TH1D* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  backgroundhist = dynamic_cast<TH1D*>(infile->Get(Form("h_%s_event_%s_%s", leptype.c_str(), variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getBackgroundGenSplit( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype,std::string gentype ,std::string selection )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  backgroundhist = dynamic_cast<TH1F*>(infile->Get(Form("h_%s_%s_event_%s_%s", leptype.c_str(),gentype.c_str() ,variable.c_str(), selection.c_str() ))->Clone("backgroundhist"));
  return;
}

void getTemplateMET( TH1F* &methist, std::string iter, std::string bgfileprefix )
{
  std::string filename = Form("$analysis_output/%s_hists.root", bgfileprefix.c_str() );
  TFile *infile = TFile::Open(filename.c_str(),"READ");
  methist = dynamic_cast<TH1F*>(infile->Get("h_templ_met")->Clone(Form("methist_%s", bgfileprefix.c_str())));  
  return;
}

void updateoverflow( TH1F * &hist, float xmax )
{

  int overflowbin = hist->FindBin(xmax)-1;
  for( int bini = overflowbin; bini < hist->GetNbinsX(); bini++ ){
	hist->SetBinContent( overflowbin, hist->GetBinContent( overflowbin ) + hist->GetBinContent( bini + 1 ) );	
	hist->SetBinError  ( overflowbin, sqrt( pow(hist->GetBinError  ( overflowbin ), 2 ) + pow( hist->GetBinError( bini + 1 ), 2 ) ) );	
	hist->SetBinContent( bini + 1, 0 );
	hist->SetBinError  ( bini + 1, 0 );
  }
  return;
}


void renormalizebins( TH1F * &hist )
{
  for( int bini = 0; bini < hist->GetNbinsX()+1; bini++ ){
	if( hist->GetBinWidth(bini) > hist->GetBinWidth(1) ){
	  hist->SetBinContent( bini, hist->GetBinContent( bini )*(hist->GetBinWidth(1)/hist->GetBinWidth(bini)) );	
	  hist->SetBinError( bini, hist->GetBinError( bini )    *(hist->GetBinWidth(1)/hist->GetBinWidth(bini)) );	
	  // hist->SetBinContent( bini, hist->GetBinContent( bini ) * (10./hist->GetBinWidth(bini)) );	
	  // hist->SetBinError(   bini, hist->GetBinError( bini )   * (10./hist->GetBinWidth(bini)) );	
	}
  }  
  return;
}

void setxaxistitle( TH2F * &hist, string var){
  string xlabel = getVariableName(var);
  hist->GetXaxis()->SetTitle(TString(xlabel));
}

void setxaxistitle( THStack * &stack, string var){
  string xlabel = getVariableName(var);
  stack->GetXaxis()->SetTitle(TString(xlabel));
}

string getVariableName(const std::string& var)
{
  if (var.find("nVert")  != string::npos)   return "N_{vtx}";
  if (var.find("bkgtype")  != string::npos)   return "";
  if (var.find("flavorbin")  != string::npos)   return "";
  if (var.find("nbjets")  != string::npos)  return "N_{bjets}";
  if (var.find("njet")  != string::npos)    return "N_{jet}";
  if (var.find("met") != string::npos)      return "E_{T}^{miss} [GeV]";
  if (var.find("absIso") != string::npos)   return "absIso03 [GeV]";
  if (var.find("mtMax") != string::npos)       return "m_{T}_max [GeV]";
  if (var.find("mt") != string::npos)       return "m_{T}(l;#nu) [GeV]";
  if (var.find("MHT") != string::npos)      return "H_{T}^{miss} [GeV]";
  if (var.find("ht") != string::npos)       return "H_{T} Phi";
  if (var.find("ptl1") != string::npos)     return "leading lep p_{T} [GeV]";
  if (var.find("ptl2") != string::npos)     return "subleading lep p_{T} [GeV]";
  if (var.find("ptb1") != string::npos)     return "leading b jet p_{T} [GeV]";
  if (var.find("ptj1") != string::npos)     return "leading jet p_{T} [GeV]";
  if (var.find("ptj2") != string::npos)     return "subleading jet p_{T} [GeV]";
  if (var.find("etaj1") != string::npos)     return "leading jet #eta";
  if (var.find("etaj2") != string::npos)     return "subleading jet #eta";
  if (var.find("ptb1overptb2") != string::npos) return "ptb1/ptb2";
  if (var.find("MCT") != string::npos)      return "M_{CT} [GeV]";
  if (var.find("njets") != string::npos)    return "N_{jets}";
  if (var.find("mll") != string::npos)      return "M_{\\ell\\ell} [GeV]";
  if (var.find("mbb") != string::npos)      return "M_{b#bar{b}} [GeV]";
  if (var.find("MCT") != string::npos)      return "M_{CT} [GeV]";
  if (var.find("ptlll") != string::npos)    return "pT_{\\ell\\ell\\ell} [GeV]";
 // if (sample.find("") != string::npos) return "";
  cout << "getVariableName: WARNING: didn't recognize : " << var << endl;

  return var; 
}

TGraphAsymmErrors* getPoissonGraph( TH1F* histo, bool drawZeros, const std::string& xerrType, float nSigma ) {

  //  histo->SetBinErrorOption(TH1::kPoisson);
  const double alpha = 1 - 0.6827;

  unsigned int nBins = histo->GetNbinsX();
  int emptyBins=0;
  for( unsigned i=1; i < nBins; ++i ) {
    if( histo->GetBinContent(i)==0 ) emptyBins += 1;
  }
  if( (float)emptyBins/(float)nBins > 0.4 ) drawZeros=false;

  TGraphAsymmErrors* graph = new TGraphAsymmErrors(0);

  for( int iBin=1; iBin<(histo->GetXaxis()->GetNbins()+1); ++iBin ) {

    int y; // these are data histograms, so y has to be integer
    double x, xerr, yerrplus, yerrminus;
    x = histo->GetBinCenter(iBin);
    if( xerrType=="0" )
      xerr = 0.;
    else if( xerrType=="binWidth" )
      xerr = histo->GetBinWidth(iBin)/2.;
    else if( xerrType=="sqrt12" )
      xerr = histo->GetBinWidth(iBin)/sqrt(12.);
    else {
      std::cout << "[MT2DrawTools::getPoissonGraph] Unkown xerrType '" << xerrType << "'. Setting to bin width." << std::endl;
      xerr = histo->GetBinWidth(iBin);
    }

    y = (int)histo->GetBinContent(iBin);

    if( y==0 && !drawZeros ) continue;     
    
    double ym =  (y==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,y,1.));
    double yp =  ROOT::Math::gamma_quantile_c(alpha/2,y+1,1) ;
    
    //    yerrminus = histo->GetBinErrorLow(iBin);
    //    yerrplus = histo->GetBinErrorUp(iBin);
    
    //double ym, yp;
    //RooHistError::instance().getPoissonInterval(y,ym,yp,nSigma);
    
    yerrplus = yp - y;
    yerrminus = y - ym;

    if(y==0)
      std::cout << yerrplus << "\t" << yerrminus << std::endl;

    int thisPoint = graph->GetN();
    graph->SetPoint( thisPoint, x, y );
    graph->SetPointError( thisPoint, xerr, xerr, yerrminus, yerrplus );

  }

  return graph;
}

TGraphAsymmErrors* getRatioGraph( TH1F* histo_data, TH1F* histo_mc, const std::string& xerrType){

  if( !histo_data || !histo_mc ) return 0;

  TGraphAsymmErrors* graph  = new TGraphAsymmErrors();
  
  //  TGraphAsymmErrors* graph_data = getPoissonGraph(histo_data, false);
  TGraphAsymmErrors* graph_data = getPoissonGraph(histo_data, true);
  
  for( int i=0; i < graph_data->GetN(); ++i){
    
    Double_t x_tmp, data;
    graph_data->GetPoint( i, x_tmp, data );

    Double_t data_errUp = graph_data->GetErrorYhigh(i);
    Double_t data_errDn = graph_data->GetErrorYlow(i);
    
    int iBin = histo_mc->FindBin(x_tmp);
    float mc = histo_mc->GetBinContent(iBin);
    float mc_err = histo_mc->GetBinError(iBin);


    float ratio = data/mc;
    float ratio_errUp = sqrt( data_errUp*data_errUp/(mc*mc) + mc_err*mc_err*data*data/(mc*mc*mc*mc) );
    float ratio_errDn = sqrt( data_errDn*data_errDn/(mc*mc) + mc_err*mc_err*data*data/(mc*mc*mc*mc) );

    double xerr;
    
    if( xerrType=="0" )
      xerr = 0.;
    else if( xerrType=="binWidth" )
      xerr = histo_mc->GetBinWidth(iBin)/2.;
    else if( xerrType=="sqrt12" )
      xerr = histo_mc->GetBinWidth(iBin)/sqrt(12.);
    else {
      std::cout << "[MT2DrawTools::getPoissonGraph] Unkown xerrType '" << xerrType << "'. Setting to bin width." << std::endl;
      xerr = histo_mc->GetBinWidth(iBin);
    }
    graph->SetPoint(i, x_tmp, ratio );
    graph->SetPointEYhigh(i, ratio_errUp );
    graph->SetPointEYlow(i, ratio_errDn );
    graph->SetPointEXhigh(i, xerr );
    graph->SetPointEXlow(i, xerr );
  }
  graph->SetLineColor(1);
  graph->SetMarkerColor(1);
  graph->SetMarkerStyle(20);
  return graph;
}


void defineColors(){
  TColor *clightblue = new TColor(2001,91/255.,187/255.,241/255.);//light-blue
  TColor *cblue = new TColor(2002,60/255.,144/255.,196/255.);//blue
  TColor *corange= new TColor(2003,230/255.,159/255.,0/255.);// orange
  TColor *cbrown = new TColor(2004,180/255.,117/255.,0/255.);//
  TColor *cyellow = new TColor(2005,245/255.,236/255.,69/255.); 
  TColor *cdarkyellow = new TColor(2006,215/255.,200/255.,0/255.);
  TColor *cblueviolet = new TColor(2007,70/255.,109/255.,171/255.);
  TColor *cviolet = new TColor(2008,70/255.,90/255.,134/255.); 
  TColor *cdarkviolet = new TColor(2009,55/255.,65/255.,100/255.);
  TColor *clightgreen = new TColor(2010,120/255.,160/255.,0/255.);
  TColor *cgreen = new TColor(2011,0/255.,158/255.,115/255.); 
  TColor *cpink = new TColor(2012,204/255.,121/255.,167/255.);
}

int getColorSplitByMC_tribosonana( mc_sample_tribosonana mc_sample) {
    switch(mc_sample){
    case(WWW):        return 632; //kRed
    case(WWZ_WZZ):    return 616; //kMagenta
    case(tt1l):       return 2005; 
    case(tt2l):       return 2008; 
    case(singleTop):  return 2009;
    case(Wjets):      return 2006;
    case(Zjets):      return 2010;
    case(ww):         return 2007;
    case(WZ):         return 2003;
    case(ZZ):         return 2011;
    case(ttV):        return 2004;
    case(WG):         return  920;
    case(ZG):         return  921;
    case(other):      return 2012; 
    default: return 0; // blank
  } 
}

int getColorSplitByBg_ss(bkg_type_ss bkg_type){
    switch(bkg_type){
    case(loselepton):   return 2003;
    case(loselepton3l): return 2011;
    case(threelep):   return 2003;
    case(jetfake):    return 2005;
    case(chargeflip): return 2007;
    case(truess):     return 2001;
    case(gammafake):  return  920;
    default: return 0; // blank
   }   
}
