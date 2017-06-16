#include "TH1.h"
#include "TCanvas.h"
#include <iostream>
#include <utility>
#include <string>

#include "TFile.h"
#include "Math/QuantFuncMathCore.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TLine.h"
#include "TColor.h"
#include "TMatrixD.h"

#ifndef HISTTOOLS_H
#define HISTTOOLS_H

enum mc_sample_tribosonana{WWW,WWZ_WZZ,tt1l,tt2l,singleTop,Wjets,Zjets,WW,WZ,ZZ,ttV,Other};
enum bkg_type_ss{ WWW,WWZ_WZZ,loselepton,fake,chargeflip,truess};

void fillUnderOverFlow(TH1F * &h1, float value, float weight);
void fillUnderOverFlow(TH1D * &h1, double value, float weight);
void saveHist(const std::string filename, const std::string pat="*");
void drawCMSLatex( TCanvas * &canvas, float luminosity ,bool is_simulation);
void drawCMSLatex( TCanvas * &canvas, float luminosity, float cmsleftmargin, float lumileftmargin );
void updateoverflow( TH1F * &hist, float xmax );
void getBackground( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection );
void getYield( TH1D* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection );
void renormalizebins( TH1F * &hist );
std::string getVariableName(const std::string& var);
static TGraphAsymmErrors* getPoissonGraph( TH1F* h1, bool drawZeros=true, const std::string& xerrType="0", float nSigma=1. );
static TGraphAsymmErrors* getRatioGraph( TH1F* h1, TH1F* h2, const std::string& xerrType="0" );
void defineColors();
int  getColorSplitByMC_tribosonana(mc_sample_tribosonana mc_sample);
int  getColorSplitByBg_ss(bkg_type_ss bkg_type);
#endif
