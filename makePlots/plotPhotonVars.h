#include <map>

#include "TH1F.h"
#include "TPad.h"
#include "TFile.h"
#include "TLegend.h"

#ifndef PLOTPHOTONVARS_H
#define PLOTPHOTONVARS_H

void addHistToMap( std::string hname, std::map<std::string, TH1F*> &histmap, TFile * &infile );
void rebinMap( std::map<std::string, TH1F*> &histmap, int rebin );
void setColorMap( std::map<std::string, TH1F*> &histmap );
TLegend* getLegend( std::map<std::string, TH1F*> &histmap );
void makeAndSavePlot( std::string var, std::string sel, int rebin, bool setlog = false );
void fixNormalization( std::map<std::string, TH1F*> &histmap );

#endif
