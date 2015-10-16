#include "TH1.h"
#include "TCanvas.h"

#ifndef HISTTOOLS_H
#define HISTTOOLS_H

void fillUnderOverFlow(TH1F * &h1, float value, float weight);
void fillUnderOverFlow(TH1D * &h1, double value, float weight);
void saveHist(const std::string filename, const std::string pat="*");
void drawCMSLatex( TCanvas * &canvas, float luminosity );
void drawCMSLatex( TCanvas * &canvas, float luminosity, float cmsleftmargin, float lumileftmargin );
void updateoverflow( TH1F * &hist, float xmax );
void getBackground( TH1F* &backgroundhist, std::string iter, std::string bgfileprefix, std::string variable, std::string leptype, std::string selection );

#endif
