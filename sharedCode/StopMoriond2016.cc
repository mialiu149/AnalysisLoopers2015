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

#include "StopMoriond2016.h"
#include "histTools.h"
#include "V00_00_02.h"

using namespace std;
using namespace V00_00_02_np; 

bool passPreselection()
{
 int NSLeps = 0;         
 if( !(HLT_SingleMuNoEta()||HLT_SingleMuNoIso()||HLT_SingleMuNoIsoNoEta() || HLT_SingleEl27())) return false;//trigger
 if(lep1_is_mu()){
 if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) ++NSLeps;
 } 
 else if (lep1_is_el()){
  if(lep1_pt()>35&&(fabs(lep1_eta())<1.4||fabs(lep1_eta())>1.6&&fabs(lep1_eta())<2.1)&&lep1_passMediumID()&&lep1_MiniIso()<0.1) ++NSLeps; 
 }
  //to add: track veto.
  if( NSLeps!= 1)      return false; // require at least 1 good lepton
  if( pfmet() < 50)    return false; // met cut
  if( ngoodjets() < 3) return false; // >=3 jets  
  return true;
}

bool pass2lPreselection()
{
 int NSLeps = 0;         
 if( !(HLT_Mu8El17()||HLT_Mu17El12())) return false;
 if(lep1_is_mu()){
 if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) ++NSLeps;
 } 
 else if (lep1_is_el()){
  if(lep1_pt()>30&&(fabs(lep1_eta())<1.4||fabs(lep1_eta())>1.6 && fabs(lep1_eta())<2.1)&&lep1_passMediumID()&&lep1_MiniIso()<0.1) ++NSLeps; 
 }
 if(lep2_is_mu()){
 if(lep2_pt()>15&&fabs(lep2_eta())<2.1&&lep2_passMediumID()&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) ++NSLeps;
 } 
 else if (lep2_is_el()){
  if(lep2_pt()>15&&(fabs(lep2_eta())<1.4||fabs(lep2_eta())>1.6 && fabs(lep2_eta())<2.1)&&lep2_passMediumID()&&lep2_MiniIso()<0.1) ++NSLeps; 
 }
 //to add: track veto.
  if( NSLeps < 2)     return false; // require at least 2 good lepton
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4();
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4();
  float mll = (l1lv+l2lv).mass();
  if( mll< 20 )        return false; // mll cut
  if( pfmet() < 50)    return false; // met cut
  if( ngoodjets() < 3) return false; // >=3 jets  
  return true;
}

bool passBaseline(){
 if(!passPreselection())     return false;
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4();
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4();
 if(nvetoleps()!=1 && !(nvetoleps()==2&&dRbetweenVectors(l1lv,l2lv)<0.01) ) return false;
 if(!PassTrackVeto_v3())     return false;
 if(!PassTauVeto())          return false;
 if(ngoodbtags()<1)          return false;
 if(pfmet()<250)             return false;
 if(mt_met_lep()<150)        return false;
 if(mindphi_met_j1_j2()<0.8) return false;
 return true;
}

bool passSR( string selection )
{
 if(!passBaseline()) return false; 
 if( TString(selection).Contains("all"))  return true;
 if( TString(selection).Contains("bin1") && !(ngoodjets()>3&&pfmet()>250&&pfmet()<325&&MT2W()<200)) return false;
 if( TString(selection).Contains("bin2") && !(ngoodjets()>3&&pfmet()>325&&MT2W()<200)) return false;
 if( TString(selection).Contains("bin3") && !(ngoodjets()>3&&pfmet()>250&&pfmet()<350&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin4") && !(ngoodjets()>3&&pfmet()>350&&pfmet()<450&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin5") && !(ngoodjets()>3&&pfmet()>450&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin6") && !(ngoodjets()==3&&pfmet()>250&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin7") && !(ngoodjets()>4&&pfmet()>250&&MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return false;
 if( TString(selection).Contains("bin8") && !(ngoodjets()>4&&pfmet()>250&&MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return false;

 return true;
}

bool pass1lCR( string selection )
{
 if(!passPreselection())  return false; 
 if( nvetoleps() > 1 )    return false; // second lepton veto
 if( ngoodbtags() > 0)    return false; // bveto 
 if( TString(selection).Contains("met150") && pfmet()<150)   return false;
 if( TString(selection).Contains("mt120")  && mt_met_lep()<120)   return false;
 if( TString(selection).Contains("lep200") && lep1_pt()<200) return false;
 if( TString(selection).Contains("absiso") && lep1_pt()*lep1_relIso03EA()>10) return false;
 if( TString(selection).Contains("dphi")   && mindphi_met_j1_j2()< 0.8 ) return false;
 //if( mt_met_lep() < 40 ) return false;
 if( TString(selection).Contains("all"))  return true;
 if( TString(selection).Contains("bin1") && (ngoodjets()>3&&pfmet()>250&&pfmet()<325&&MT2W()<200)) return true;
 if( TString(selection).Contains("bin2") && (ngoodjets()>3&&pfmet()>325&&MT2W()<200)) return true;
 if( TString(selection).Contains("bin3") && (ngoodjets()>3&&pfmet()>250&&pfmet()<350&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin4") && (ngoodjets()>3&&pfmet()>350&&pfmet()<450&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin5") && (ngoodjets()>3&&pfmet()>450&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin6") && (ngoodjets()==3&&pfmet()>250&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin7") && (ngoodjets()>4&&pfmet()>250&&MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
 if( TString(selection).Contains("bin8") && (ngoodjets()>4&&pfmet()>250&&MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
 return false;
}

bool pass2lCR( string selection )
{
 if(!pass2lPreselection())         return false; 
// if( PassTrackVeto_v3())           return false;
// if( PassTauVeto())                return false;
// if( pfmet()<150)                  return false;
 if( TString(selection).Contains("all"))  return true;
 if( TString(selection).Contains("bin1") && (ngoodjets()>3&&pfmet()>250&&pfmet()<325&&MT2W()<200)) return true;
 if( TString(selection).Contains("bin2") && (ngoodjets()>3&&pfmet()>325&&MT2W()<200)) return true;
 if( TString(selection).Contains("bin3") && (ngoodjets()>3&&pfmet()>250&&pfmet()<350&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin4") && (ngoodjets()>3&&pfmet()>350&&pfmet()<450&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin5") && (ngoodjets()>3&&pfmet()>450&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin6") && (ngoodjets()==3&&pfmet()>250&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin7") && (ngoodjets()>4&&pfmet()>250&&MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
 if( TString(selection).Contains("bin8") && (ngoodjets()>4&&pfmet()>250&&MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
 
 return false;
}

bool passRegion(string selection)
{
  if( TString(selection).Contains("3jets") && !(ngoodjets() >=3)) return false;
  if( TString(selection).Contains("3jets_met150") && !(ngoodjets() >=3 && pfmet()>150)) return false;
  if( TString(selection).Contains("3jets_met150_mt120") && !(ngoodjets() >=3 && pfmet()>150 && mt_met_lep() > 120)) return false;
  if( TString(selection).Contains("3jets_met150_mt120_dphi") && !(ngoodjets() >=3 && pfmet()>150 && mt_met_lep() > 120 && mindphi_met_j1_j2()>0.8)) return false;
  if( TString(selection).Contains("3jets_met150_mt120_dphi_absiso") && !(ngoodjets() >=3 && pfmet()>150 && mt_met_lep() > 120 && mindphi_met_j1_j2()>0.8 && lep1_relIso03EA()*lep1_pt() < 5)) return false;
  return true;
}

bool passStudyRegion( string selection)
{
  if( TString(selection).Contains("lep_pt_200") && !(ngoodjets() >=3 && lep1_pt()>200)) return false;
  return true;
}
