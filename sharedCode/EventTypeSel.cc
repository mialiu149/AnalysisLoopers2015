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
#include "../classFiles/V80_03.h"

using namespace std;
using namespace V80_03_np; 

float worseMETrel(float percent){
float metx = pfmet()*TMath::Cos(pfmet_phi());
float mety = pfmet()*TMath::Sin(pfmet_phi());
float genmetx = genmet()*TMath::Cos(genmet_phi());
float genmety  = genmet()*TMath::Sin(genmet_phi());

float worsemetx = genmetx+(1+percent)*(metx-genmetx) ;
float worsemety = genmety+(1+percent)*(mety-genmety) ;
float worsemet = TMath::Sqrt(worsemetx*worsemetx+worsemety*worsemety); 

return worsemet;
}

int  eventtype(){
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4(); 
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4(); 

 if (dRbetweenVectors(l1lv,l2lv)>0.01) {    // cases lep1 and lep2 don't overlap.
 if ((lep1type() == 1 && lep2type() == 0)||(lep1type() == 0 && lep2type() == 1)) return 5; // only one sel lepton.lep1 is the sel lepton, or only lep2 is the sel
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
     float sel_eta_mu = 2.1 ;
     float veto_pt_mu = 5;
     float veto_eta_mu = 2.4;
     float sel_pt_el = 30;
     float sel_eta_el = 1.442;
     //float sel_eta_el = 2.4;
     float veto_pt_el = 5;
     float veto_eta_el = 2.4;
     float sel_miniRelIso_el  = 0.1;
     float sel_miniRelIso_mu  = 0.1 ;
     float veto_miniRelIso_mu = 0.2 ;
     float veto_miniRelIso_el = 0.2 ;
     bool  firstLep_isSel  = false;
     bool  firstLep_isVeto = false;

     if( abs(lep1_pdgid()) == 13){
            if( lep1_p4().pt()>sel_pt_mu &&
                fabs(lep1_p4().eta())<sel_eta_mu &&
                lep1_passTightID() &&
                lep1_MiniIso() < sel_miniRelIso_mu 
              && lep1_relIso()*lep1_p4().pt() < 5)
                {
                firstLep_isSel = true;
            } // end if good muon                                                                                                                                                    
            else if ( lep1_p4().pt()>veto_pt_mu &&
                     fabs(lep1_p4().eta())<veto_eta_mu &&
                     lep1_passVeto() &&
                     lep1_MiniIso()<veto_miniRelIso_mu ){
                     firstLep_isVeto = true;
            } // end if veto muon                                                                                                                                                    
           }
	  if( abs(lep1_pdgid()) == 11 ){
            if( lep1_p4().pt()>sel_pt_el &&
                //(fabs(lep1_eta())<sel_eta_el || (fabs(lep1_eta())>1.5&&fabs(lep1_eta())<2.1)) &&//barrel + endcap
                (fabs(lep1_p4().eta())<sel_eta_el) &&//barrel + endcap
                lep1_passMediumID() &&
                lep1_MiniIso()<sel_miniRelIso_el
 &&                lep1_relIso()*lep1_p4().pt() < 5 )
{
                firstLep_isSel = true;
            } // end if good electron                                                                                                                                                
            else if( lep1_p4().pt()>veto_pt_el &&
                     fabs(lep1_p4().eta())<veto_eta_el &&
                     lep1_passVeto() &&
                     lep1_MiniIso()<veto_miniRelIso_el ){
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
     float veto_pt_mu = 5;
     float veto_eta_mu = 2.4; // need to be 2.4
     float sel_miniRelIso_mu = 0.1 ;
     float sel_pt_el = 30;
     float sel_eta_el = 1.442;
     float veto_pt_el = 5;
     float veto_eta_el = 2.4; //need to be 2.4
     float sel_miniRelIso_el = 0.1;
     float veto_miniRelIso_mu = 0.2 ;
     float veto_miniRelIso_el = 0.2 ;
     bool  secondLep_isSel  = false;
     bool  secondLep_isVeto = false;
     //muons
     if( abs(lep2_pdgid()) == 13){
            if( lep2_p4().pt()>sel_pt_mu &&
                fabs(lep2_p4().eta())<sel_eta_mu &&
                lep2_passTightID() &&
                lep2_MiniIso()<sel_miniRelIso_mu )   
            secondLep_isSel = true;
            else if( lep2_p4().pt()>veto_pt_mu &&
                     fabs(lep2_p4().eta())<veto_eta_mu &&
                     lep2_passVeto() &&
                     lep2_MiniIso()<veto_miniRelIso_mu )
                     secondLep_isVeto = true;
           }
       //electrons
	  if( abs(lep2_pdgid()) == 11 ){
            if( lep2_p4().pt()>sel_pt_el &&
                (fabs(lep2_p4().eta())<sel_eta_el) &&//barrel+endcap
                lep2_passMediumID() &&
                lep2_MiniIso()<sel_miniRelIso_el )
                secondLep_isSel = true;
            else if( lep2_p4().pt()>veto_pt_el &&
                     fabs(lep2_p4().eta())<veto_eta_el &&
                     lep2_passVeto() &&
                     lep2_MiniIso()<veto_miniRelIso_el )
                     secondLep_isVeto = true;
          }
  if(secondLep_isSel)  return 1;
  else if(secondLep_isVeto) return 2; 
  else return 0;
}
