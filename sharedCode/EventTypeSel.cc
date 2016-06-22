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

#include "EventTypeSel.h"
#include "histTools.h"
#include "V00_00_05.h"

using namespace std;
using namespace V00_00_05_np; 

// split events according to lepton types.
/*int  eventtype(){
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4(); 
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4(); 
 if ((lep1type() == 1 && lep2type() ==1)&&(dRbetweenVectors(l1lv,l2lv)>0.01)) return 1; // both are sel and they don't overlap.
 if ((lep1type() == 1 && lep2type() ==2)&&dRbetweenVectors(l1lv,l2lv)>0.01) return 2; // lep1 is sel,lep2 is veto, and they don't overlap
 if ((lep1type() == 1 && lep2type() ==0)) return 3; // lep1 is sel,lep2 is not a veto, and they don't overlap
// if (lep1type() == 2 && lep2type() == 2) return 4; //both are veto
// if (lep1type() == 2 && lep2type() == 1) return 4; //lep2 is sel, lep1 is veto
// if (lep1type() == 0 && lep2type() == 0) return 5;  
 else return 0; // who cares what it is
}
*/
int  eventtype(){
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4(); 
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4(); 

 if (dRbetweenVectors(l1lv,l2lv)>0.01) {    // cases lep1 and lep2 don't overlap.
 if ((lep1type() == 1 && lep2type() == 0)) return 5; // only one sel lepton.lep1 is the sel lepton, or only lep2 is the sel
 //if ((lep1type() == 1 && lep2type() == 0)||(lep1type() == 0 && lep2type() == 1)) return 5; // only one sel lepton.lep1 is the sel lepton, or only lep2 is the sel
 if (lep1type() == 1 && lep2type() == 1) return 1; // both are sel
 if (lep1type() == 1 && lep2type() == 2) return 2; //lep1 is sel, lep2 is veto.
 if (lep1type() == 2 && lep2type() == 1) return 3; //lep2 is sel, lep1 is veto.
 if (lep1type() == 2 && (lep2type() != 1) || lep1type() !=1 && (lep2type() == 2)) return 4; //both are veto. or worse than veto
 }
 else { //cases lep1 and lep2 overlap
// if((lep1type() == 1&&lep1_is_mu()&&lep2type() == 1&&lep2_is_el())||(lep1type() == 1&&lep1_is_el()&&lep2type() == 1&&lep2_is_mu())) return 1;
 if(lep1type() == 1) return 5;  // two lep overlap and are sel.
 else if (lep1type() == 2) return 4;
 }
 if(lep1type() == 0 && lep2type() == 0) return 4;  
 else return 0; // no good lepton. :(
}

int lep1type() {  // first lepton definitions
     float sel_pt_mu = 25;
     float sel_eta_mu = 2.4 ;
     float veto_pt_mu = 10;
     float veto_eta_mu = 2.4;
     float sel_pt_el = 30;
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
                lep1_miniRelIsoEA()<sel_miniRelIso_mu  &&
                lep1_relIso03EA()*lep1_pt() < 5){
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
                //(fabs(lep1_eta())<sel_eta_el || (fabs(lep1_eta())>1.5&&fabs(lep1_eta())<2.1)) &&//barrel + endcap
                (fabs(lep1_eta())<sel_eta_el) &&//barrel + endcap
                lep1_passMediumID() &&
                lep1_miniRelIsoEA()<sel_miniRelIso_el &&
                lep1_relIso03EA()*lep1_pt() < 5 ){
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
  else if(firstLep_isVeto) return 2; 
  else return 0;
}

int lep2type() { // second lepton type
     float sel_pt_mu = 25;
     float sel_eta_mu = 2.4 ;
     float veto_pt_mu = 10;
     float veto_eta_mu = 2.1;
     float sel_miniRelIso_mu = 0.1 ;
     float sel_pt_el = 30;
     float sel_eta_el = 1.442;
     float veto_pt_el = 10;
     float veto_eta_el = 2.1;
     float sel_miniRelIso_el = 0.1;
     float veto_miniRelIso_mu = 0.2 ;
     float veto_miniRelIso_el = 0.2 ;
     bool  secondLep_isSel  = false;
     bool  secondLep_isVeto = false;
     //muons
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
       //electrons
        if( lep2_is_el() ){
            if( lep2_pt()>sel_pt_el &&
                //fabs(lep2_eta())<sel_eta_el &&
                //(fabs(lep2_eta())<sel_eta_el || (fabs(lep2_eta())>1.5&&fabs(lep2_eta())<2.1)) &&//barrel+endcap
                (fabs(lep2_eta())<sel_eta_el) &&//barrel+endcap
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
  else if(secondLep_isVeto) return 2; 
  else return 0;
  }
 }
