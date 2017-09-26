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
#include "THStack.h"

#ifndef HISTTOOLS_H
#define HISTTOOLS_H

enum mc_sample_tribosonana{WWW,WWZ_WZZ,tt1l,tt2l,singleTop,Wjets,Zjets,ww,WZ,ZZ,ttV,other,WG,ZG};
enum bkg_type_ss{loselepton,jetfake,chargeflip,truess,gammafake,threelep,loselepton3l};

void fillUnderOverFlow(TH1F * &h1, float value, float weight);
void fillUnderOverFlow(TH1D * &h1, double value, float weight);
void setxaxistitle( TH2F * &hist, std::string var);
void setxaxistitle( THStack * &stack, std::string var);
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
void getenvelope(TH1F * &h1, TH1F* h1_up,TH1F* h1_down);
void setsys(TH1F * &h1, float sys);
#endif
