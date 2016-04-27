#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1.h"
#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"

#include "WJetsSelection.h"
#include "EventTypeSel.h"
#include "histTools.h"
#include "V00_00_05.h"

using namespace std;
using namespace V00_00_05_np; 

namespace wjetssel {

bool passPreselection(string selection)
{
  // for w+jets, only OR the met trigger when it's on the plateau of mt170
   if (!(HLT_SingleMu20() || HLT_SingleEl27())) return false;
   //event type
   //if( !(eventtype()==3))                                            return false;
   if( lep1type() != 1)                                              return false;
   if( (lep2type() ==1 || lep2type() ==2))                             return false;//second lepton veto
   if( pfmet() < 50)                                                 return false; // min met cut.
   if( TString(selection).Contains("met_trigger")&&pfmet() < 250)    return false; // met cut
   return true;
 }//end of funtion passPreselection

bool passRegion(string selection) {
  if(!passPreselection(selection)) 			                              return false;
  if( TString(selection).Contains("1jet_excl") && !(ngoodjets() ==1))                 return false;
  if( TString(selection).Contains("2jet_excl") && !(ngoodjets() ==2))                 return false;
  if( TString(selection).Contains("3jet_excl") && !(ngoodjets() ==3))                 return false;
  if( TString(selection).Contains("4jet_excl") && !(ngoodjets() ==4))                 return false;
  if( TString(selection).Contains("1jet_incl") && !(ngoodjets() >=1))                 return false;
  if( TString(selection).Contains("2jet_incl") && !(ngoodjets() >=2))                 return false;
  if( TString(selection).Contains("3jet_incl") && !(ngoodjets() >=3))                 return false;
  if( TString(selection).Contains("4jet_incl") && !(ngoodjets() >=4))                 return false;
  if( TString(selection).Contains("btag") && ngoodbtags()<1)                          return false;
  if( TString(selection).Contains("bveto") && ngoodbtags()>0)                          return false;
  if( TString(selection).Contains("mtbulk")  && !(mt_met_lep()>70 && mt_met_lep()<120)) return false;
  if( TString(selection).Contains("mt50")    && !(mt_met_lep() > 50))                   return false;
  if( TString(selection).Contains("mt150")   && !(mt_met_lep() > 150))                  return false;
  if( TString(selection).Contains("met150")  && !(pfmet() >      150))                  return false;
  if( TString(selection).Contains("absiso")  && !(lep1_relIso03EA()*lep1_pt() < 5))    return false;
  if( TString(selection).Contains("lep_pt_200") && !(ngoodjets() >=3 && lep1_pt()>200)) return false;

  return true;
}

}//end namespace
