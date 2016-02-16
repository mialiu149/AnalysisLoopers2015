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

#include "ZJetsSelection.h"
#include "histTools.h"
#include "V00_00_02.h"

using namespace std;
using namespace V00_00_02_np; 

namespace zjetssel{
//baseline for stop. don't need it???
bool passBaseline(string selection){
 if(!passPreselection(selection))     return false;
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

//binning for stop moriond 2016, don't need it here?
bool passSR( string selection ) {
 if( !passBaseline(selection)) return false; 
 if( TString(selection).Contains("all"))  return true;
 if( TString(selection).Contains("bin1") && !(ngoodjets()>3&&pfmet()>250&&pfmet()<325&&MT2W()<200)) return false;
 if( TString(selection).Contains("bin2") && !(ngoodjets()>3&&pfmet()>325&&MT2W()<200))              return false;
 if( TString(selection).Contains("bin3") && !(ngoodjets()>3&&pfmet()>250&&pfmet()<350&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin4") && !(ngoodjets()>3&&pfmet()>350&&pfmet()<450&&MT2W()>200)) return false;
 if( TString(selection).Contains("bin5") && !(ngoodjets()>3&&pfmet()>450&&MT2W()>200))              return false;
 if( TString(selection).Contains("bin6") && !(ngoodjets()==3&&pfmet()>250&&MT2W()>200))             return false;
 if( TString(selection).Contains("bin7") && !(ngoodjets()>4&&pfmet()>250&&MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return false;
 if( TString(selection).Contains("bin8") && !(ngoodjets()>4&&pfmet()>250&&MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return false;

 return true;
}

bool passPreselection(string selection) {// trigger + lepton selections
 //--------------------------//
 //--- trigger requirement---//
 //--------------------------//
  // for w+jets, only OR the met trigger when it's on the plateau of mt170
   //if( TString(selection).Contains("met_trigger")){ 
   //if( !(HLT_SingleMu20()||HLT_SingleMuNoEta()||HLT_SingleMuNoIso()||HLT_SingleMuNoIsoNoEta() || HLT_SingleEl27() || HLT_MET170() )) return false;
 //  }
//   else if (!(HLT_SingleMu20()||HLT_SingleMuNoEta()||HLT_SingleMuNoIso()||HLT_SingleMuNoIsoNoEta() || HLT_SingleEl27())) return false;
   //event type
   if( !(eventtype()==1))                                            return false;
   if( !(lep1_is_mu()&&lep2_is_mu()||lep1_is_el()&&lep2_is_el()))    return false;
//   if( pfmet() < 50)                                                 return false; // min met cut.
//   if( TString(selection).Contains("met_trigger")&&pfmet() < 250)    return false; // met cut
   //if( ngoodjets() < 2 )                                             return false; // >=3 jets  
//   if( ngoodbtags() > 0)                                             return false; //for bveto
   return true;
 }//end of funtion passPreselection


bool passRegion(string selection) {  // jet binning/kinematic regions etc.
  if(!passPreselection(selection)) 			                              return false;
  if( TString(selection).Contains("1jet_excl") && !(ngoodjets() ==1))                 return false;
  if( TString(selection).Contains("2jet_excl") && !(ngoodjets() ==2))                 return false;
  if( TString(selection).Contains("3jet_excl") && !(ngoodjets() ==3))                 return false;
  if( TString(selection).Contains("4jet_excl") && !(ngoodjets() ==4))                 return false;
  if( TString(selection).Contains("1jet_incl") && !(ngoodjets() >=1))                 return false;
  if( TString(selection).Contains("2jet_incl") && !(ngoodjets() >=2))                 return false;
  if( TString(selection).Contains("3jet_incl") && !(ngoodjets() >=3))                 return false;
  if( TString(selection).Contains("4jet_incl") && !(ngoodjets() >=4))                 return false;
  if( TString(selection).Contains("mtbulk")  && !(mt_met_lep()>70&&mt_met_lep()<120)) return false;
  if( TString(selection).Contains("mt150")   && !mt_met_lep() > 150)                  return false;
  if( TString(selection).Contains("met150")  && !pfmet() >      150)                  return false;
  if( TString(selection).Contains("absiso") && !(lep1_relIso03EA()*lep1_pt() < 5))    return false;
  return true;
}

bool passStudyRegion( string selection) {// can implement some study regions quickly if needed.{
  if( TString(selection).Contains("lep_pt_200") && !(ngoodjets() >=3 && lep1_pt()>200)) return false;
  return true;
}

// split events according to lepton types.
int  eventtype(){
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4(); 
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4(); 
 if (lep1type() == 1 && lep2type() == 0) return 5; // only one sel lepton.lep1 is the sel lepton.
 if (dRbetweenVectors(l1lv,l2lv)>0.01) {    // cases lep1 and lep2 don't overlap.
 if (lep1type() == 1 && lep2type() == 1) return 1; // both are sel
 if (lep1type() == 1 && lep2type() == 2) return 2; //lep1 is sel, lep2 is veto.
 if (lep1type() == 2 && lep2type() == 1) return 3; //lep2 is sel, lep1 is veto.
 if (lep1type() == 2 && lep2type() == 2) return 4; //both are veto.
 }
 else {
 if(lep1type() == 1) return 5;  // two lep overlap and are sel.
 if(lep1type() == 2) return 6;  // two lep overlap and are veto.
 }
 return 0; // no good lepton. :(
}


int lep1type() {  // first lepton definitions
     float sel_pt_mu = 35;
     float sel_eta_mu = 2.1 ;
     float veto_pt_mu = 10;
     float veto_eta_mu = 2.4;
     float sel_pt_el = 40;
     float sel_eta_el = 1.442;
     float veto_pt_el = 10;
     float veto_eta_el = 2.4;
     float sel_miniRelIso_el  = 0.1;
     float sel_miniRelIso_mu  = 0.1 ;
     float veto_miniRelIso_mu = 0.2 ;
     float veto_miniRelIso_el = 0.2 ;
     bool  firstLep_isSel  = false;
     bool  firstLep_isVeto = false;

     if( lep1_is_mu() ){
            if( lep1_pt()>sel_pt_mu &&
                fabs(lep1_eta())<sel_eta_mu &&
                lep1_is_muoid_tight() &&
                lep1_miniRelIsoEA()<sel_miniRelIso_mu ){
                firstLep_isSel = true;
            } // end if good muon                                                                                                                                                    
            else if ( lep1_pt()>veto_pt_mu &&
                     fabs(lep1_eta())<veto_eta_mu &&
                     lep1_passVeto() &&
                     lep1_miniRelIsoEA()<veto_miniRelIso_mu ){
                     firstLep_isVeto = true;
            } // end if veto muon                                                                                                                                                    
           }
        if( lep1_is_el() ){
            if( lep1_pt()>sel_pt_el &&
                (fabs(lep1_eta())<sel_eta_el || (fabs(lep1_eta())>1.5&&fabs(lep1_eta())<2.1)) &&//barrel + endcap
                lep1_passMediumID() &&
                lep1_miniRelIsoEA()<sel_miniRelIso_el ){
                firstLep_isSel = true;
            } // end if good electron                                                                                                                                                
            else if( lep1_pt()>veto_pt_el &&
                     fabs(lep1_eta())<veto_eta_el &&
                     lep1_passVeto() &&
                     lep1_miniRelIsoEA()<veto_miniRelIso_el ){
                     firstLep_isVeto = true;
            } // end if veto electron                                                                                                                                                
          }
  if(firstLep_isSel)  return 1;
  if(firstLep_isVeto) return 2; 
  return 0;
}

int lep2type() { // second lepton type
     float sel_pt_mu = 35;
     float sel_eta_mu = 2.1 ;
     float veto_pt_mu = 10;
     float veto_eta_mu = 2.1;
     float sel_miniRelIso_mu = 0.1 ;
     float sel_pt_el = 40;
     float sel_eta_el = 1.442;
     float veto_pt_el = 10;
     float veto_eta_el = 2.1;
     float sel_miniRelIso_el = 0.1;
     float veto_miniRelIso_mu = 0.2 ;
     float veto_miniRelIso_el = 0.2 ;
     bool  secondLep_isSel  = false;
     bool  secondLep_isVeto = false;
      if( lep2_is_mu() ){
            if( lep2_pt()>sel_pt_mu &&
                fabs(lep2_eta())<sel_eta_mu &&
                lep2_is_muoid_tight() &&
                lep2_miniRelIsoEA()<sel_miniRelIso_mu ){
                secondLep_isSel = true;
            } // end if good muon                                                                                                                                                    
            else if( lep2_pt()>veto_pt_mu &&
                     fabs(lep2_eta())<veto_eta_mu &&
                     lep2_passVeto() &&
                     lep2_miniRelIsoEA()<veto_miniRelIso_mu ){
                     secondLep_isVeto = true;
            } // end if veto muon                                                                                                                                                    
           }

        if( lep2_is_el() ){
            if( lep2_pt()>sel_pt_el &&
                //fabs(lep2_eta())<sel_eta_el &&
                (fabs(lep2_eta())<sel_eta_el || (fabs(lep2_eta())>1.5&&fabs(lep2_eta())<2.1)) &&//barrel+endcap
                lep2_passMediumID() &&
                lep2_miniRelIsoEA()<sel_miniRelIso_el ){
                secondLep_isSel = true;
            } // end if good electron                                                                                                                                                
            else if( lep2_pt()>veto_pt_el &&
                     fabs(lep2_eta())<veto_eta_el &&
                     lep2_passVeto() &&
                     lep2_miniRelIsoEA()<veto_miniRelIso_el ){
                     secondLep_isVeto = true;
            } // end if veto electron                                                                         }
  if(secondLep_isSel)  return 1;
  if(secondLep_isVeto) return 2; 
  return 0;
 }
 }
}//end namespace
