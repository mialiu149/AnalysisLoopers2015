#include <iostream>
#include <utility>
#include <string>
#include <sstream>

#include "TROOT.h"
#include "TString.h"
#include "TFile.h"
#include "TH1.h"

#include "WHPlotUtilities.h"

using namespace std;

string getVariableName(const std::string& var)
{
  if (var.find("nVert")  != string::npos)   return "N_{vtx}";
  if (var.find("met") != string::npos)      return "E_{T}^{miss} [GeV]";
  if (var.find("absIso") != string::npos)   return "absIso03 [GeV]";
  if (var.find("mt") != string::npos)       return "m_{T}(l;#nu) [GeV]";
  if (var.find("MHT") != string::npos)      return "H_{T}^{miss} [GeV]";
  if (var.find("ht") != string::npos)       return "H_{T} Phi";
  if (var.find("ptl1") != string::npos)     return "lep p_{T} [GeV]";
  if (var.find("ptb1") != string::npos)     return "leading b jet p_{T} [GeV]";
  if (var.find("ptb1overptb2") != string::npos) return "ptb1/ptb2";
  if (var.find("MCT") != string::npos)      return "M_{CT} [GeV]";
  if (var.find("njets") != string::npos)    return "N_{jets}";
  if (var.find("mll") != string::npos)      return "M_{\\ell\\ell} [GeV]";
  if (var.find("mbb") != string::npos)      return "M_{b#bar{b}} [GeV]";
 // if (sample.find("") != string::npos) return "";
  cout << "getVariableName: WARNING: didn't recognize : " << var << endl;

  return var; 
}

string getMETBinLabel(const std::string& selection)
{
// if (sample.find("") != string::npos) return "";

  cout << "getMETBinLabel: WARNING: didn't recognize : " << selection << endl;

  return selection; 
}
