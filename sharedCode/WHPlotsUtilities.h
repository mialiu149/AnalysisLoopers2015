#include <iostream>
#include <utility>
#include <string>

#include "TFile.h"

std::string toString(int in);
void ReplaceString(std::string& subject, const std::string& search, const std::string& replace);

int getColor(const std::string& sample);
std::string getLegendName(const std::string& sample);
std::string getTableName(const std::string& sample);
std::string getVariableName(const std::string& var);
std::string getMETBinLabel(const std::string& selection);

std::string getJetBJetPlotLabel(TFile* f, std::string dir_str);
std::string getHTPlotLabel(TFile* f, std::string dir_str);
std::string getHTTableLabel(TFile* f, std::string dir_str);
std::string getMETTableLabel(TFile* f, std::string dir_str);
std::string getMT2PlotLabel(TFile* f, std::string dir_str);
std::string getJetBJetTableLabel(TFile* f, std::string dir_str);
