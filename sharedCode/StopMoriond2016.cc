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
#include "EventTypeSel.h"
#include "histTools.h"
#include "V00_00_05.h"

using namespace std;
using namespace V00_00_05_np; 

float event_weight(std::string selection)
{
 if(TString(selection).Contains("btagsf") && !(TString(selection).Contains("DN")||TString(selection).Contains("UP"))) return scale1fb()*weight_btagsf();
 else if(TString(selection).Contains("btagsf_heavy_UP")) return scale1fb()*weight_btagsf_heavy_UP();
 else if(TString(selection).Contains("btagsf_heavy_DN")) return scale1fb()*weight_btagsf_heavy_DN();
 else if(TString(selection).Contains("btagsf_light_UP")) return scale1fb()*weight_btagsf_light_UP();
 else if(TString(selection).Contains("btagsf_light_DN")) return scale1fb()*weight_btagsf_light_DN();
 else if(TString(selection).Contains("scale0"))          return scale1fb()*abs(genweights().at(0));
 else if(TString(selection).Contains("scale1"))          return scale1fb()*abs(genweights().at(1));
 else if(TString(selection).Contains("scale2"))          return scale1fb()*abs(genweights().at(2));
 else if(TString(selection).Contains("scale3"))          return scale1fb()*abs(genweights().at(3));
 else if(TString(selection).Contains("scale4"))          return scale1fb()*abs(genweights().at(4));
 else if(TString(selection).Contains("scale5"))          return scale1fb()*abs(genweights().at(5));
 else if(TString(selection).Contains("scale6"))          return scale1fb()*abs(genweights().at(6));
 else if(TString(selection).Contains("scale7"))          return scale1fb()*abs(genweights().at(7));
 else if(TString(selection).Contains("scale8"))          return scale1fb()*abs(genweights().at(8));
 else if(TString(selection).Contains("pdf_up"))          return abs(scale1fb())*pdf_up_weight()*1.001122e+05/1.073756e+05;
 else if(TString(selection).Contains("pdf_dn"))          return abs(scale1fb())*pdf_down_weight()*1.001122e+05/8.931240e+04;
 else if(TString(selection).Contains("pdf_alpha1"))      return scale1fb()*abs(genweights()[109]);
 else if(TString(selection).Contains("pdf_alpha2"))      return scale1fb()*abs(genweights()[110]);
 else return scale1fb();
}

bool passPreselection(string selection)
{
 //--------------------------//
 //--- trigger requirement---//
 //--------------------------//
   if( !(HLT_SingleMu20()||HLT_SingleMuNoEta()||HLT_SingleMuNoIso()||HLT_SingleMuNoIsoNoEta() || HLT_SingleEl27() || HLT_MET170() )) return false;
   if( TString(selection).Contains("2l") && !(eventtype() == 0  ||eventtype() == 4 || eventtype() == 6))     return false; 
   if( TString(selection).Contains("SR") && !(eventtype() == 5))     return false; 
   if( pfmet() < 50)                                                 return false; // min met cut.
   if( TString(selection).Contains("met_trigger")&&pfmet() < 250)    return false; // met cut
   if( ngoodjets() < 2)                                              return false; // >=3 jets  
  return true;
}

bool pass2lPreselection()
{
 int NSLeps = 0;         
 if(!(HLT_Mu8El17()||HLT_Mu17El12())) return false;
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
  if( NSLeps < 2)      return false; // require at least 2 good lepton
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4();
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4();
  float mll = (l1lv+l2lv).mass();
  if( mll< 20 )        return false; // mll cut
  if( pfmet() < 50)    return false; // met cut
  if( ngoodjets() < 3) return false; // >=3 jets  

  return true;
}

bool passBaseline(string selection){
 if(!passPreselection(selection))     return false;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4();
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4();
 //if(nvetoleps()!=1 && !(nvetoleps()==2&&dRbetweenVectors(l1lv,l2lv)<0.01) ) return false;
 if( ngoodjets() < 3)        return false; // >=3 jets  
 if(!PassTrackVeto_v3())     return false;
 if(!PassTauVeto())          return false;
 if(ngoodbtags()<1)          return false;
 if(pfmet()<250 )            return false;
 if(mt_met_lep()<150)        return false;
 if(mindphi_met_j1_j2()<0.8) return false;
 return true;
}

bool passSR( string selection )
{
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

bool pass1lCR( string selection )
{
 if( !passPreselection(selection)) return false; 
 if( nvetoleps() > 1 )    return false; // second lepton veto
 if( ngoodbtags() > 0)    return false; // bveto 
 if( TString(selection).Contains("met150") && pfmet()<150)                     return false;
 if( TString(selection).Contains("mt120")  && mt_met_lep()<120)                return false;
 if( TString(selection).Contains("lep200") && lep1_pt()<200)                   return false;
 if( TString(selection).Contains("absiso") && lep1_pt()*lep1_relIso03EA()>10)  return false;
 if( TString(selection).Contains("dphi")   && mindphi_met_j1_j2()< 0.8 )       return false;
 if( TString(selection).Contains("all"))  return true;
 if( TString(selection).Contains("bin1") && (ngoodjets()>3&&pfmet()>250&&pfmet()<325&&MT2W()<200)) return true;
 if( TString(selection).Contains("bin2") && (ngoodjets()>3&&pfmet()>325&&MT2W()<200))              return true;
 if( TString(selection).Contains("bin3") && (ngoodjets()>3&&pfmet()>250&&pfmet()<350&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin4") && (ngoodjets()>3&&pfmet()>350&&pfmet()<450&&MT2W()>200)) return true;
 if( TString(selection).Contains("bin5") && (ngoodjets()>3&&pfmet()>450&&MT2W()>200))              return true;
 if( TString(selection).Contains("bin6") && (ngoodjets()==3&&pfmet()>250&&MT2W()>200))             return true;
 if( TString(selection).Contains("bin7") && (ngoodjets()>4&&pfmet()>250&&MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
 if( TString(selection).Contains("bin8") && (ngoodjets()>4&&pfmet()>250&&MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;

 return false;
}

bool pass2lCR( string selection )
{
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l1lv = lep1_p4();
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > l2lv = lep2_p4();
 if( TString(selection).Contains("CR4")) { if(!pass2lPreselection()) return false;}          // this is to validate total normalization and ISR modeling.
 if( !passPreselection(selection))                 return false;                             // preselection with at least 1 lep+ met50 +2jets||met trigger cuts 
 if( ngoodbtags()<1)                               return false;
 bool met_mt_cut = ( pfmet()>250 && mt_met_lep() > 150 );                                    // some additional requirement for CRs
 bool passCR5 = ( met_mt_cut &&  (eventtype()==1||eventtype()==2||eventtype()==3));                                            // fail lepton veto.
 bool passCR6 = ( met_mt_cut && (!PassTrackVeto_v3()||!PassTauVeto()) &&!(eventtype()==1||eventtype()==2||eventtype()==3));                      // fail track veto: CR6

 // the following corresponds to SR bins.
 //if( (TString(selection).Contains("CR5") && passCR5 || TString(selection).Contains("CR6") && passCR6 ) && TString(selection).Contains("yield") ){
 if( (passCR5 ||passCR6 ) && TString(selection).Contains("yield") ){
     if( TString(selection).Contains("all")  && (ngoodjets()>3  && pfmet()>250)) return true;
//     if( TString(selection).Contains("all")) return true; // very loose met and mt cut
/*     if( TString(selection).Contains("bin1") && (ngoodjets()>2  && pfmet()>250 && pfmet()<325&&MT2W()<200)) return true;
     if( TString(selection).Contains("bin2") && (ngoodjets()>3  && pfmet()>325 && MT2W()<200))              return true;
     if( TString(selection).Contains("bin3") && (ngoodjets()>3  && pfmet()>250 && pfmet()<350&&MT2W()>200)) return true;
     if( TString(selection).Contains("bin3") && (ngoodjets()>3  && pfmet()>250 && pfmet()<350&&MT2W()>200)) return true;
     if( TString(selection).Contains("bin4") && (ngoodjets()>3  && pfmet()>350 && pfmet()<450&&MT2W()>200)) return true;
     if( TString(selection).Contains("bin5") && (ngoodjets()>3  && pfmet()>450 && MT2W()>200))              return true;
     if( TString(selection).Contains("bin6") && (ngoodjets()==3 && pfmet()>250 ))                           return true;
     if( TString(selection).Contains("bin7") && (ngoodjets()>4  && pfmet()>250 && MT2W()<200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
     if( TString(selection).Contains("bin8") && (ngoodjets()>4  && pfmet()>250 && MT2W()>200&&ak4pfjets_pt().at(0)>200&& !ak4pfjets_passMEDbtag().at(0))) return true;
     if( TString(selection).Contains("bin10") && (ngoodjets()>3 && pfmet()>250 && MT2W()<200)) return true;
     if( TString(selection).Contains("bin11") && (ngoodjets()>3 && pfmet()>250 && MT2W()>200)) return true;
*/
     if( TString(selection).Contains("bin1") && (ngoodjets()>2  && pfmet()>250 && MT2W()<200)) return true; // low mt2w region
     if( TString(selection).Contains("bin2") && (ngoodjets()>2  && pfmet()>250 && MT2W()>200)) return true;// hight mt2w region
     if( TString(selection).Contains("bin3") && (ngoodjets()==2  && pfmet()>250 && topnessMod()>6.4)) return true; // add 2 jet region
 }

 if( TString(selection).Contains("CR5") && passCR5 && !TString(selection).Contains("yield")) return true; // for plots in CR5 
 if( TString(selection).Contains("CR6") && passCR6 && !TString(selection).Contains("yield")) return true; // for plots in CR6

 return false;
}

bool passRegion(string selection)
{
  if( TString(selection).Contains("2jets") && !(ngoodjets() >=2)) return false;
  if( TString(selection).Contains("2jets_met150") && !(ngoodjets() >=2 && pfmet()>150)) return false;
  if( TString(selection).Contains("2jets_met150_mt150") && !(ngoodjets() >=2 && pfmet()>150 && mt_met_lep() > 150)) return false;
  if( TString(selection).Contains("2jets_met150_mt150_dphi") && !(ngoodjets() >=2 && pfmet()>150 && mt_met_lep() > 150 && mindphi_met_j1_j2()>0.8)) return false;
  if( TString(selection).Contains("2jets_met150_mt150_dphi_absiso") && !(ngoodjets() >=2 && pfmet()>150 && mt_met_lep() > 150 && mindphi_met_j1_j2()>0.8 && lep1_relIso03EA()*lep1_pt() < 5)) return false;
  return true;
}

bool passStudyRegion( string selection)
{
  if( TString(selection).Contains("lep_pt_200") && !(ngoodjets() >=3 && lep1_pt()>200)) return false;
  return true;
}

vector<vector<int>> lep_nu_fromW()
{ 
 vector<int> leps_plus;
 vector<int> nus_plus;
 vector<int> leps_minus;
 vector<int> nus_minus;
 vector <vector<int>> lep_nu;
 
 if(!(passPreselection("SR"))) { cout<<"failpre"<<lep_nu.size()<<endl; return lep_nu;}

// do we need to match to the reco lepton????

 for (int i=0;i<genleps_p4().size();i++) 
 {
    //if(genleps_motherid()[i] == 24  && genleps_p4()[i].pt() > 20 && genleps_fromHardProcessDecayed()[i])  leps_plus.push_back(i);
   // if(genleps_motherid()[i] == -24 && genleps_p4()[i].pt() > 20 && genleps_fromHardProcessDecayed()[i])  leps_minus.push_back(i);
//    if(genleps_motherid()[i] == 24  && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1 || genleps_status()[i] == 23))  leps_plus.push_back(i);
//    if(genleps_motherid()[i] == -24 && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1 || genleps_status()[i] == 23))  leps_minus.push_back(i);
     if(genleps_motherid()[i] == 24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13) && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1)) leps_plus.push_back(i);
     if(genleps_motherid()[i] == -24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13) && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1)) leps_minus.push_back(i);
//     if(genleps_motherid()[i] == -24 && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1)) leps_minus.push_back(i); 
//   if(genleps_motherid()[i] == 24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13) && genleps_p4()[i].pt() > 1 )  {leps_plus.push_back(i);cout<< "status of plus genlep : "<<genleps_id()[i]<<endl;}
//   if(genleps_motherid()[i] == -24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13)  && genleps_p4()[i].pt() > 1 )  {leps_minus.push_back(i);cout<< "status of minus genlep : "<<genleps_id()[i]<<endl;}
 }

 for (int i=0;i<gennus_p4().size();i++){
     if(gennus_motherid()[i] == 24 && (abs(gennus_id()[i]) == 12||abs(gennus_id()[i]) == 14) && gennus_p4()[i].pt() > 1 && (gennus_status()[i] == 1)) nus_plus.push_back(i);
     if(gennus_motherid()[i] == -24 && (abs(gennus_id()[i]) == 12||abs(gennus_id()[i]) == 14) && gennus_p4()[i].pt() > 1 && (gennus_status()[i] == 1)) nus_minus.push_back(i);
//    if(gennus_motherid()[i] == 24  && gennus_p4()[i].pt() > 20 && gennus_status()[i] == 1)  nus_plus.push_back(i);
 //   if(gennus_motherid()[i] == -24 && gennus_p4()[i].pt() > 20 && gennus_status()[i] == 1)  nus_minus.push_back(i);
 }

lep_nu.push_back(leps_plus);
lep_nu.push_back(nus_plus);
lep_nu.push_back(leps_minus);
lep_nu.push_back(nus_minus);
//cout<<"plus:"<<leps_plus.size()<<":"<<nus_plus.size()<<endl;
//cout<<"minus:"<<leps_minus.size()+leps_plus.size()<<endl;
return lep_nu;

}
