#include <stdexcept>
#include <iostream>
#include <map>
#include "TH1.h"
#include "TMath.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"
#include "TribosonSelection.h"
#include "histTools.h"
#include "../classFiles/triboson_v0.1.9/triboson.h"
#include "../../commonUtils/commonUtils.h"
#include "Math/VectorUtil.h"
#include "StopSelections.h"
using namespace std;
using namespace triboson_np; 

namespace tribosonsel{
static const float BTAGWP = 0.5426;
static const float mBTAGWP = 0.8484;
//const double ZMASS = 91.1876;
const double ZMASS = 90.0;
//--------------//
// preselection //
//--------------//
int preselRegion( std::string looselep ){
    if(passPreselection(looselep)) {
      vector<int> goodleps = selectedLeps(looselep);                          //find loose leptons
      int type_looper = hyp_type_looper(goodleps);                                 //find event type
      if(type_looper==0) return 1;
      if(type_looper==2) return 2;
      if(type_looper==1) return 3;
    }
    else if(passPreselection("trilep_loose_VVV_cutbased_fo")){
      vector<int> leps_index = selectedLeps("trilep"); 
      int trileptype = trileptype_dilepmass(leps_index).first;
      if(trileptype==1) return 4;
      if(trileptype==2) return 5;
      if(trileptype==3) return 6;
   }
   return -999; 
}

int signalRegion2016(){
    if(passSR("ss_loose_VVV_cutbased_fo_v5")) {
      vector<int> goodleps = selectedLeps("ss_VVV_cutbased_fo_v5");                                  //find loose leptons
      int type_looper = hyp_type_looper(goodleps);                              //find event type
      if(type_looper==0) return 1;
      if(type_looper==2) return 2;
      if(type_looper==1) return 3;
    }
    else if(passSR("trilep_loose")){
      vector<int> leps_index = selectedLeps("trilep"); 
      int trileptype = trileptype_dilepmass(leps_index).first;
      if(trileptype==1) return 4;
      if(trileptype==2) return 5;
      if(trileptype==3) return 6;
   }
   return -999; 
}

bool passPreselection(string selection) {
 //bool passTrigger =  HLT_singleEl()||HLT_singleMu()||HLT_singleMu_noiso()||HLT_DoubleEl_noiso()|| HLT_DoubleEl_DZ_2()
  //                   || HLT_MuEG() || HLT_MuEG_noiso() || HLT_DoubleMu() || HLT_DoubleMu_noiso();
 //bool passTrigger =  HLT_DoubleEl_noiso()|| HLT_DoubleEl_DZ_2() || HLT_MuEG() || HLT_MuEG_noiso() || HLT_DoubleMu() || HLT_DoubleMu_noiso();
 bool passTrigger =   HLT_DoubleEl_DZ_2() || HLT_MuEG() || HLT_DoubleMu();
 if( !TString(selection).Contains("btag") && nBJetLoose()>0) return false; //default is loose btag now.
 if( TString(selection).Contains("btag") && nBJetLoose()<1) return false;
 vector<int> goodjets =  selectedjets();
 vector<int> veto_jets =  vetojets();
 vector<int> forward_jets =  forwardjets();
 int njets_sel = goodjets.size();
 int njets_veto = veto_jets.size();
 int njets_forward = forward_jets.size();
 
 if( TString(selection).Contains("jecup"))    njets_sel = njets_up();
 if( TString(selection).Contains("jecdown"))  njets_sel = njets_dn();

if(TString(selection).Contains("ss")){
 vector<int> goodleps = selectedLeps(selection);          //find good leptons
 int nvetoleps = countvetoleps(5);
 int type_looper = hyp_type_looper(goodleps);            //find event type
 if( !passTrigger)                                        return false; 
 //if( !TString(selection).Contains("crwz")&&(goodleps.size()!=2||nlep_VVV_cutbased_veto()>2))   return false; 
 if( !TString(selection).Contains("crwz")&&(goodleps.size()!=2||nvetoleps>2))   return false; 
 if( TString(selection).Contains("crwz")&&goodleps.size()!=3)                                  return false;
  if (TString(selection).Contains("onetight") && (isGoodLepton(goodleps.at(0),selection)    &&isGoodLepton(goodleps.at(1),selection))) return false;
 if (TString(selection).Contains("onetight") && (!isGoodLepton(goodleps.at(0),selection)    &&!isGoodLepton(goodleps.at(1),selection))) return false;
 if (TString(selection).Contains("doublefakable")&&(!isLooseNotTight(goodleps.at(0),selection)||!isLooseNotTight(goodleps.at(1),selection))) return false;
 if( type_looper<0)                                       return false; //event not SS type
 if( !TString(selection).Contains("noisotrackveto") && !TString(selection).Contains("crwz")&& nisoTrack_mt2_cleaned_VVV_cutbased_veto()>0) return false; //isotrackveto, on bydefault now
 if( !TString(selection).Contains("nojetcut")&&njets_sel<2)                                         return false; // at least two jets
 if( TString(selection).Contains("jetveto") && njets()>4) return false; //isotrackveto
 if( TString(selection).Contains("ee") && type_looper!=0) return false;    //ee
 if( TString(selection).Contains("mm") && type_looper!=1) return false;    //mm
 if( TString(selection).Contains("em") && type_looper!=2) return false;    //em
 float dilepmass = (lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).mass();// calculate dilepton mass
 if(TString(selection).Contains("lowmet") && met_pt()>40) return false;
 if( type_looper==0 && dilepmass>80 && dilepmass<100)     return false;    //for ee events, veto zmass
 if( type_looper==0 && dilepmass<40)                      return false;
 if( type_looper==1 && dilepmass<40)                      return false;
 if( type_looper==2 && dilepmass<30)                      return false;    // dilepmass>40
 return true;
 }

if(TString(selection).Contains("trilep")){
 vector<int> leps_index = selectedLeps(selection); 
 //if( evt()== 578874) cout<<__LINE__<<endl;
 if( leps_index.size()!=3 || nlep()!=3) return false;
 float dphi = dphi3lmet(leps_index,met_phi());
 if( dphi<2.5)                 return false;
 if( njets_veto >1 )           return false;
 int   trileptype = trileptype_dilepmass(leps_index).first;
 float dilepmass = trileptype_dilepmass(leps_index).second;
 if(lep_p4().at(leps_index.at(0)).pt()<25) return false;
 bool pass_SFOS0 = (trileptype==0 && dilepmass>20  && dphi>2.7);
 bool pass_SFOS1 = (trileptype==1 && dilepmass>20 && met_pt()>45 );
 bool pass_SFOS2 = (trileptype==2 && dilepmass>20 && met_pt()>55 );

 if(!pass_SFOS0&&!pass_SFOS1&&!pass_SFOS2) return false;
 if( TString(selection).Contains("SFOS0") && !pass_SFOS0) return false; 
 if( TString(selection).Contains("SFOS1") && !pass_SFOS1) return false; 
 if( TString(selection).Contains("SFOS2") && !pass_SFOS2) return false;
 //if( TString(selection).Contains("SFOS1")) cout<<evt()<<":"<< trileptype <<":"<<lep_pdgId().at(leps_index.at(0))<<":"<<lep_pdgId().at(leps_index.at(1))<<":"<<lep_pdgId().at(leps_index.at(2))<<endl;
 return true;
 }

cout<<"selection not defined"<<endl;
return false;
}

bool passPreselection(string selection, TH1D* &counterhist) {
 bool passTrigger =  HLT_singleEl()||HLT_singleMu()||HLT_singleMu_noiso()||HLT_DoubleEl_noiso()|| HLT_DoubleEl_DZ_2();
 passTrigger = true;
 if( !TString(selection).Contains("btag") && nBJetLoose()>0) return false; //default is loose btag now.
 counterhist->Fill(1);
 if( TString(selection).Contains("btag") && nBJetLoose()>1) return false;
 counterhist->Fill(2);
 vector<int> goodjets =  selectedjets();
 vector<int> veto_jets =  vetojets();

 int njets_veto = veto_jets.size();
 int njets_sel = goodjets.size();
 
 if( TString(selection).Contains("jecup"))    njets_sel = njets_up();
 if( TString(selection).Contains("jecdown"))  njets_sel = njets_dn();

if(TString(selection).Contains("ss")){
 vector<int> goodleps = selectedLeps(selection);                           //find good leptons
 int nvetoleps = countvetoleps(5);
 int type_looper = hyp_type_looper(goodleps);                              //find event type
 if( !passTrigger)                                        return false; counterhist->Fill(3);
 if( goodleps.size()!=2||nlep()!=2||nveto_leptons()>0)    return false; counterhist->Fill(4);
// if( goodleps.size()!=2 || nvetoleps>2) return false;    //exactly two good leptons
 if( type_looper<0)                                       return false; counterhist->Fill(5);   //event not SS type
 if( njets_sel<2)                                         return false; counterhist->Fill(6);   // at least two jets
 if( !TString(selection).Contains("noisotrackveto") && nisoTrack_mt2()>0) return false; counterhist->Fill(7);// isotrackveto
 if( TString(selection).Contains("ee") && type_looper!=0) return false;    //ee
 if( TString(selection).Contains("mm") && type_looper!=1) return false;    //mm
 if( TString(selection).Contains("em") && type_looper!=2) return false;    //em
 if( TString(selection).Contains("ee")) counterhist->Fill(8);
 if( TString(selection).Contains("em")) counterhist->Fill(21);
 if( TString(selection).Contains("mm")) counterhist->Fill(31);
 float dilepmass = (lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).mass();// calculate dilepton mass
 if( type_looper==0 && dilepmass>80 && dilepmass<100)     return false;    //for ee events, veto zmass
 if( TString(selection).Contains("ee")) counterhist->Fill(9);
 if( TString(selection).Contains("em")) counterhist->Fill(22);
 if( TString(selection).Contains("mm")) counterhist->Fill(32);
 double mjj =  mjj_dRmin( goodjets );
//(jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).mass();                    // dijet mass
 double deta_jj = abs(jets_p4().at(goodjets.at(0)).eta() - jets_p4().at(goodjets.at(1)).eta());      // dijet eta
 if( dilepmass<40)                    return false;                                  // dilepmass>40
 if( TString(selection).Contains("ee")) counterhist->Fill(10);
 if( TString(selection).Contains("em")) counterhist->Fill(23);
 if( TString(selection).Contains("mm")) counterhist->Fill(33);
 if( type_looper!=1&&met_pt()<40)     return false;                                  // met cut for ee/emu
 if( TString(selection).Contains("ee")) counterhist->Fill(11);
 if( TString(selection).Contains("em")) counterhist->Fill(24);
 if( TString(selection).Contains("mm")) counterhist->Fill(34);
 if( mjj>100 || mjj<60)                 return false;                                  // w mass window cut
 if( TString(selection).Contains("ee")) counterhist->Fill(12);
 if( TString(selection).Contains("em")) counterhist->Fill(25);
 if( TString(selection).Contains("mm")) counterhist->Fill(35);
 if( deta_jj>1.5)                     return false;                                  // delta eta cut
 if( TString(selection).Contains("ee")) counterhist->Fill(13);
 if( TString(selection).Contains("em")) counterhist->Fill(26);
 if( TString(selection).Contains("mm")) counterhist->Fill(36);
 if( jets_p4().at(goodjets.at(0)).pt()<30||fabs(jets_p4().at(goodjets.at(0)).eta())>2.5)         return false;                                  // leading jet pt
 if( jets_p4().at(goodjets.at(1)).pt()<20||fabs(jets_p4().at(goodjets.at(1)).eta())>2.5)         return false;                                  // leading jet pt
 if( TString(selection).Contains("ee")) counterhist->Fill(14);
 if( TString(selection).Contains("em")) counterhist->Fill(27);
 if( TString(selection).Contains("mm")) counterhist->Fill(37);
 if( fabs(jets_p4().at(goodjets.at(1)).eta())>2.5) return false;
 return true;
 }

if(TString(selection).Contains("trilep")){
 vector<int> leps_index = selectedLeps(selection); 
 if( leps_index.size()!=3 || nlep()!=3) return false;
 counterhist->Fill(41);
 float dphi = dphi3lmet(leps_index,met_phi());
 //if( njets_sel>1 || njets()>1) return false;
 //if(  njets()>1) return false;
 if( njets_veto >1 )           return false;
 counterhist->Fill(42);
 if( dphi<2.5)                 return false;
 int   trileptype = trileptype_dilepmass(leps_index).first;
 float dilepmass = trileptype_dilepmass(leps_index).second;
 bool pass_SFOS0 = (trileptype==0 && dilepmass>20 && ((abs(dilepmass-ZMASS)>15)||hyp_type()!=0));
 bool pass_SFOS1 = (trileptype==1 && dilepmass>20 && met_pt()>45 && (dilepmass-ZMASS>20 || ZMASS-dilepmass>35));
 bool pass_SFOS2 = (trileptype==2 && met_pt()>55 && abs(dilepmass-ZMASS)>20);
 if( TString(selection).Contains("nomet")) {
     pass_SFOS1 = (trileptype==1 && dilepmass>20 && (dilepmass-ZMASS>20 || ZMASS-dilepmass>35)); 
     pass_SFOS2 = (trileptype==2 && abs(dilepmass-ZMASS)>20);
 }
float   ptlll=(lep_p4().at(leps_index.at(0))+lep_p4().at(leps_index.at(1))+lep_p4().at(leps_index.at(2))).pt();  
 if( TString(selection).Contains("ptlll75")&&ptlll<75) return false;  
 if(!pass_SFOS0&&!pass_SFOS1&&!pass_SFOS2) return false;
 counterhist->Fill(43);
 if( TString(selection).Contains("SFOS0") && !pass_SFOS0) return false; 
 if( TString(selection).Contains("SFOS0")) counterhist->Fill(51);
 if( TString(selection).Contains("SFOS1") && !pass_SFOS1) return false; 
 if( TString(selection).Contains("SFOS1")) counterhist->Fill(52);
 if( TString(selection).Contains("SFOS2") && !pass_SFOS2) return false;
 if( TString(selection).Contains("SFOS2")) counterhist->Fill(53);
 //if( TString(selection).Contains("SFOS1")) cout<<evt()<<":"<< trileptype <<":"<<lep_pdgId().at(leps_index.at(0))<<":"<<lep_pdgId().at(leps_index.at(1))<<":"<<lep_pdgId().at(leps_index.at(2))<<endl;
 return true;
 }

cout<<"selection not defined"<<endl;
return false;
}

bool passSR( std::string selection ){
 bool passTrigger =  HLT_singleEl()||HLT_singleMu()||HLT_singleMu_noiso()||HLT_DoubleEl_noiso()|| HLT_DoubleEl_DZ_2();
 passTrigger = true;
 if( !TString(selection).Contains("btag") && nBJetLoose()>0) return false; //default is loose btag now.
 if( TString(selection).Contains("btag") && nBJetLoose()<1) return false;
 vector<int> goodjets =  selectedjets();
 vector<int> veto_jets =  vetojets();
 vector<int> forward_jets =  forwardjets();
 int njets_sel = goodjets.size();
 int njets_veto = veto_jets.size();
 int njets_forward = forward_jets.size();
 
 if( TString(selection).Contains("jecup"))    njets_sel = njets_up();
 if( TString(selection).Contains("jecdown"))  njets_sel = njets_dn();

 if(!passPreselection(selection)) return false;

 vector<int> goodleps = selectedLeps(selection);                           //find good leptons
 int type_looper = hyp_type_looper(goodleps);            //find event type
 
if(TString(selection).Contains("ss")){
  unsigned int lep1_index = goodleps.at(0);
  unsigned int lep2_index = goodleps.at(1);
  LorentzVector lep1_p4 = triboson_np::lep_p4().at(lep1_index);
  LorentzVector lep2_p4 = triboson_np::lep_p4().at(lep2_index);
  float lep1_pT_org = triboson_np::lep_p4().at(lep1_index).pt();
  float lep2_pT_org = triboson_np::lep_p4().at(lep2_index).pt();
  float lep1_pT = lep_coneCorrPt().at(lep1_index);
  float lep2_pT = lep_coneCorrPt().at(lep2_index);
  float dilepmass(-999);
  LorentzVector lep1_p4_coneCorr(lep1_pT,lep1_p4.eta(),lep1_p4.phi(),lep1_p4.energy()*lep1_pT/lep1_pT_org);    
  LorentzVector lep2_p4_coneCorr(lep2_pT,lep2_p4.eta(),lep2_p4.phi(),lep2_p4.energy()*lep2_pT/lep2_pT_org);    
 // dilepmass = (lep1_p4_coneCorr+lep2_p4_coneCorr).mass();
 dilepmass = (lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).mass();// calculate dilepton mass
 if( type_looper==0 && dilepmass>80 && dilepmass<100)     return false;    //for ee events, veto zmass
 if( type_looper==0 && dilepmass<40)                      return false;
 if( type_looper==1 && dilepmass<40)                      return false;
 if( type_looper==2 && dilepmass<30)                      return false;    // dilepmass>40
 if( type_looper==2 && maxMt(goodleps)<90)                return false;
 if( type_looper!=1 && met_pt()<40)     return false;                                  // met cut for ee/emu
 if( njets_sel < 2) return false;
 float mjj = mjj_dRmin(goodjets);
 float mjj_lead = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).mass();                // dijet mass
 double deta_jj = abs(jets_p4().at(goodjets.at(0)).eta() - jets_p4().at(goodjets.at(1)).eta());      // dijet eta

 if( TString(selection).Contains("atlas")) {
 if( fabs(mjj_lead-85)>20)                 return false;                                  // w mass window cut
 if( deta_jj>1.5)                          return false;                                  // delta eta cut
 if( jets_p4().at(goodjets.at(0)).pt()<30||fabs(jets_p4().at(goodjets.at(0)).eta())>2.5)         return false;                                  // leading jet pt
 if( jets_p4().at(goodjets.at(1)).pt()<20||fabs(jets_p4().at(goodjets.at(1)).eta())>2.5)         return false;                                  // leading jet pt
 return true;
 }
 if( !TString(selection).Contains("mjjsideband") && (mjj>100 || mjj<60))                         return false;                                  // w mass window cut
 if( TString(selection).Contains("mjjsideband") && (mjj<100 && mjj>60))                         return false;                                  // w mass window cut
 if( mjj_lead >400)                   return false;
 if( deta_jj>1.5)                     return false;                                  // delta eta cut
 if( jets_p4().at(goodjets.at(0)).pt()<30||fabs(jets_p4().at(goodjets.at(0)).eta())>2.5)         return false;                                  // leading jet pt
 if( jets_p4().at(goodjets.at(1)).pt()<30||fabs(jets_p4().at(goodjets.at(1)).eta())>2.5)         return false;                                  // leading jet pt
 return true;
}

if(TString(selection).Contains("trilep")){
 vector<int> leps_index = selectedLeps(selection); 
 if( leps_index.size()!=3) return false;
 int   trileptype = trileptype_dilepmass(leps_index).first;
 float dilepmass = trileptype_dilepmass(leps_index).second;
 bool pass_SFOS0 = (trileptype==0 && dilepmass>20 && ((abs(dilepmass-ZMASS)>15)||hyp_type()!=0));
 bool pass_SFOS1 = (trileptype==1 && dilepmass>20 && met_pt()>45 && (dilepmass-ZMASS>20 || ZMASS-dilepmass>35));
 bool pass_SFOS2 = (trileptype==2 && dilepmass>20 && met_pt()>55 && abs(dilepmass-ZMASS)>20);

 if( TString(selection).Contains("nomet")) {
     pass_SFOS1 = (trileptype==1 && (dilepmass-ZMASS>20 || ZMASS-dilepmass>35)); 
     pass_SFOS2 = (trileptype==2 && abs(dilepmass-ZMASS)>20);
 }

float   ptlll=(lep_p4().at(leps_index.at(0))+lep_p4().at(leps_index.at(1))+lep_p4().at(leps_index.at(2))).pt();  
float   mlll=(lep_p4().at(leps_index.at(0))+lep_p4().at(leps_index.at(1))+lep_p4().at(leps_index.at(2))).mass();  
 if(!TString(selection).Contains("noptlll60") && ptlll<60)  return false;  
 if(!TString(selection).Contains("mlll") && fabs(mlll-ZMASS)<10)       return false;  
 if(!pass_SFOS0&&!pass_SFOS1&&!pass_SFOS2) return false;
 if( TString(selection).Contains("SFOS0") && !pass_SFOS0) return false; 
 if( TString(selection).Contains("SFOS1") && !pass_SFOS1) return false; 
 if( TString(selection).Contains("SFOS2") && !pass_SFOS2) return false;
 return true;
 }
cout<<"selection not defined"<<endl;
return false;
}

int trilepEventtype(){
if( nlep()!=3) return -999;
if( abs(lep_pdgId().at(0))==abs(lep_pdgId().at(1))&&abs(lep_pdgId().at(1))==abs(lep_pdgId().at(2)))
return 2;
std::vector<std::pair<int, int>> leps;
for (unsigned int lep_index = 0;lep_index<3;++lep_index){
 std::pair<int, int> lep;
 lep = std::make_pair(lep_index,abs(lep_pdgId().at(lep_index)));
 leps.push_back(lep);
 }
 std::sort(leps.begin(), leps.end(), sortByValue);  
 if( leps.at(1).second == 13 && lep_charge().at(leps.at(1).first)* lep_charge().at(leps.at(0).first)>0) return 0;
 if( leps.at(1).second == 11 && lep_charge().at(leps.at(1).first)* lep_charge().at(leps.at(2).first)>0) return 0;
 return 1;
}

pair<int,float> trileptype_dilepmass(vector<int> sellep_index ){

if( sellep_index.size() < 3) {  
 cout<<"event has less than three leptons, exiting"<<endl;
 return std::make_pair(-999,-999); 
}

int trileptype = -999;
float dilepmass_min = -999;
// all three are e/m
int eventcharge = lep_charge().at(sellep_index.at(0))
                  *lep_charge().at(sellep_index.at(1))
                  *lep_charge().at(sellep_index.at(2));
unsigned int lep_os(0);
if( abs(lep_charge().at(sellep_index.at(0))+lep_charge().at(sellep_index.at(1))+lep_charge().at(sellep_index.at(2))) ==3) return std::make_pair(-999,-999);
if( fabs(lep_pdgId().at(sellep_index.at(0)))==fabs(lep_pdgId().at(sellep_index.at(1)))
  &&fabs(lep_pdgId().at(sellep_index.at(1)))==fabs(lep_pdgId().at(sellep_index.at(2))))
  trileptype = 2;
// loop over three leptons to save the lepton indices and pdgid in a pair
std::vector<std::pair<int, int>> leps;
for (unsigned int lep_index = 0;lep_index<3;++lep_index){
    std::pair<int, int> lep;
    lep = std::make_pair(lep_index,abs(lep_pdgId().at(sellep_index.at(lep_index))));
    if (lep_charge().at(sellep_index.at(lep_index))*eventcharge > 0) lep_os = lep_index;
    leps.push_back(lep);
 }
bool eventfail(false);
for (unsigned int lep_index = 0;lep_index<3;++lep_index){
    if (lep_index==lep_os) continue;
    float dilepmass = (lep_p4().at(sellep_index.at(lep_index))+lep_p4().at(sellep_index.at(lep_os))).mass();
    if (dilepmass<20) eventfail = true; 
    if (abs(dilepmass-ZMASS) < abs(dilepmass_min-ZMASS) && 
       abs(lep_pdgId().at(sellep_index.at(lep_index))) == abs(lep_pdgId().at(sellep_index.at(lep_os)))) 
    dilepmass_min = dilepmass;
}

if(trileptype ==2) { if(dilepmass_min>20 && !eventfail) return make_pair(trileptype,dilepmass_min); else return make_pair(-999,-999);}
// sort the leps so that muons are listed first
 std::sort(leps.begin(), leps.end(), sortByValue);
// if the sorted second lepton is muon, event is mme type, check mm sign, if it's same-sign, yes--> 0SFOS  
 if( leps.at(1).second == 13){ 
     dilepmass_min = (lep_p4().at(sellep_index.at(leps.at(1).first))+lep_p4().at(sellep_index.at(leps.at(0).first))).mass();
     if (lep_pdgId().at(sellep_index.at(leps.at(1).first))* lep_pdgId().at(sellep_index.at(leps.at(0).first))>0) trileptype=0;
     else trileptype=1; 
   }
// if the sorted second lepton is electron, event is mee type, check ee sign, it's same-sign, yes--> 0SFOS  
 if( leps.at(1).second == 11) {
     dilepmass_min = (lep_p4().at(sellep_index.at(leps.at(1).first))+lep_p4().at(sellep_index.at(leps.at(2).first))).mass();
     if (lep_pdgId().at(sellep_index.at(leps.at(1).first))* lep_pdgId().at(sellep_index.at(leps.at(2).first))>0) trileptype=0;
     else trileptype =1;  
   }
 return make_pair(trileptype,dilepmass_min);
}

bool isGoodLepton(int lepindex, string selection){
  float pt_cut = 20.0;
  float iso_cut_el = 0.06;
  float iso_cut_mu = 0.06;
  bool pass_cut = false;
  bool eta_cut = false;
  if (abs(lep_pdgId().at(lepindex))==13) eta_cut = fabs(lep_eta().at(lepindex))<2.4;
  if (abs(lep_pdgId().at(lepindex))==11) eta_cut = fabs(lep_eta().at(lepindex))<2.5 && (fabs(lep_eta().at(lepindex))<1.4 || fabs(lep_eta().at(lepindex))>1.6) ;
  if(TString(selection).Contains("looseiso")) {iso_cut_el=0.1;iso_cut_mu=0.1;}
  if(TString(selection).Contains("ss"))  { pt_cut=30.0;}
  if(TString(selection).Contains("VVV_baseline") ) pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EAv2().at(lepindex)<iso_cut_el &&abs(lep_ip3d().at(lepindex))<0.015 && (abs(lep_pdgId().at(lepindex))==13 || lep_tightCharge().at(lepindex) == 2) && lep_pass_VVV_baseline().at(lepindex);
  else pass_cut = lep_p4().at(lepindex).pt() > pt_cut && eta_cut && lep_pass_VVV_cutbased_tight_noiso().at(lepindex)&&lep_relIso03EAv2().at(lepindex)<iso_cut_el && abs(lep_ip3d().at(lepindex))<0.015 && (abs(lep_pdgId().at(lepindex))==13 || lep_tightCharge().at(lepindex) == 2);
  return pass_cut;
}

bool isLooseLepton(int lepindex, string selection){
  float pt_cut = 20.0;
  float iso_cut_el = 0.2;
  float iso_cut_mu = 0.4;
  bool  pass_cut = false;
  bool  eta_cut = false;
  if (abs(lep_pdgId().at(lepindex))==13) eta_cut = fabs(lep_eta().at(lepindex))<2.4;
  if (abs(lep_pdgId().at(lepindex))==11) eta_cut = fabs(lep_eta().at(lepindex))<2.5 && (fabs(lep_eta().at(lepindex))<1.4 || fabs(lep_eta().at(lepindex))>1.6) ;
  //default fakeable ID definition
  bool cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && lep_lostHits().at(lepindex)==0 && eta_cut && (abs(lep_pdgId().at(lepindex))==13 || lep_tightCharge().at(lepindex)== 2)) ;
  bool cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut);
//nominal one
     //cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut);
     //cut_mu = (lep_pass_VVV_cutbased_veto_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut && abs(lep_ip3d().at(lepindex))<0.015);
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut &&lep_tightCharge().at(lepindex)== 2 && abs(lep_ip3d().at(lepindex))<0.015 && lep_lostHits().at(lepindex)==0);
     //cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut );
     cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut && abs(lep_ip3d().at(lepindex))<0.015);

  if(TString(selection).Contains("v1")) {
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut);
     cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut);
   }  
  else if(TString(selection).Contains("v2")) {
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut &&lep_tightCharge().at(lepindex)== 2);
     cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut && abs(lep_ip3d().at(lepindex))<0.015);
   }  
  else if(TString(selection).Contains("v3")) {
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut && lep_tightCharge().at(lepindex)== 2);
     cut_mu = (lep_pass_VVV_cutbased_veto_noiso_noip().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut && abs(lep_ip3d().at(lepindex))<0.015);
   }  
  else if(TString(selection).Contains("v4")) {
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut && lep_tightCharge().at(lepindex)== 2);
     cut_mu = (lep_pass_VVV_cutbased_veto_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut  && abs(lep_ip3d().at(lepindex))<0.015);
   }  
  else if(TString(selection).Contains("v5")) {
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut &&lep_tightCharge().at(lepindex)== 2 && abs(lep_ip3d().at(lepindex))<0.015 && lep_lostHits().at(lepindex)==0);
     cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut && abs(lep_ip3d().at(lepindex))<0.015);
   }  
  else if(TString(selection).Contains("v6")) {
     iso_cut_mu = 0.2;
     cut_el = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_el && eta_cut &&lep_tightCharge().at(lepindex)== 2 && abs(lep_ip3d().at(lepindex))<0.015);
     cut_mu = (lep_pass_VVV_cutbased_fo_noiso().at(lepindex) &&  lep_relIso03EAv2().at(lepindex)<iso_cut_mu && eta_cut );
   }  
 
  if(TString(selection).Contains("ss")) { pt_cut=30.0;}
  if(TString(selection).Contains("_fo_")){ pt_cut=30.0;}
  if(TString(selection).Contains("SS_veto_noiso_v5")) {
   pt_cut=30.0;
   pass_cut =  lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EAv2().at(lepindex)<iso_cut_el && lep_pass_VVV_cutbased_fo_noiso().at(lepindex);    
  }
 else{ 
   if (abs(lep_pdgId().at(lepindex)) ==11) pass_cut =  lep_p4().at(lepindex).pt() > pt_cut && cut_el ; 
   if (abs(lep_pdgId().at(lepindex)) ==13) pass_cut =  lep_p4().at(lepindex).pt() > pt_cut && cut_mu ; 
  }
  return pass_cut;
}

bool isLooseNotTight(int lepindex, string selection){
  if(!isGoodLepton(lepindex,selection) && isLooseLepton(lepindex,selection)) return true;
  return false; 
}

vector<int> selectedLeps(string selection){
  vector<int> selectedleps;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      bool pass_cut(false);
      if(TString(selection).Contains("fakerate") || TString(selection).Contains("loose") || TString(selection).Contains("_fo_")) pass_cut = isLooseLepton(lepindex,selection);
      else pass_cut = isGoodLepton(lepindex,selection);
      if(pass_cut)  selectedleps.push_back(lepindex);
  }
return selectedleps;
}

int countvetoleps(float pt_cut){
  int nvetolep = 0;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_pass_VVV_cutbased_veto_noiso()[lepindex]&&fabs(lep_p4()[lepindex].Eta())<2.4&&lep_p4()[lepindex].Pt()>10&&lep_relIso03EAv2()[lepindex]<=0.4)
      nvetolep++; 
}
return nvetolep;
}

int hyp_type_looper(vector<int> lepindex){
  if (lepindex.size()<2 )  return -999;
  if (lep_pdgId().at(lepindex.at(0))*lep_pdgId().at(lepindex.at(1)) < 0) return -999;
  if ((lep_pdgId().at(lepindex.at(0)))==(lep_pdgId().at(lepindex.at(1))) && abs(lep_pdgId().at(lepindex.at(0))) ==11) return 0;
  if ((lep_pdgId().at(lepindex.at(0)))==(lep_pdgId().at(lepindex.at(1))) && abs(lep_pdgId().at(lepindex.at(0))) ==13) return 1;
  if (abs(lep_pdgId().at(lepindex.at(0)))!=abs(lep_pdgId().at(lepindex.at(1))) && lep_pdgId().at(lepindex.at(0))*lep_pdgId().at(lepindex.at(1)) >0 ) return 2;
  return -999;
}

// tight loose catorgorizations for FR
int hyp_class(){
    vector<int> goodleps,looseleps,selleps;
    for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
        if(isGoodLepton(lepindex,"ss_VVV_cutbased_tight")) goodleps.push_back(lepindex);
        if(isLooseLepton(lepindex,"ss_VVV_cutbased_fo_v5")) looseleps.push_back(lepindex);
    }
    if(looseleps.size()!=2)  return -999; // three lepton event
    if(goodleps.size()==2) {if(hyp_type_looper(goodleps)>-1) return 3;} //ss tight-tight 
    if(goodleps.size()==1&&looseleps.size()==2) { 
       if((isGoodLepton(looseleps.at(0),"ss_VVV_cutbased_tight") 
          && !isGoodLepton(looseleps.at(1),"ss_VVV_cutbased_tight")
          || isGoodLepton(looseleps.at(1),"ss_VVV_cutbased_tight")
          && !isGoodLepton(looseleps.at(0),"ss_VVV_cutbased_tight")) 
          && hyp_type_looper(looseleps) >-1 ) return 2;
    }  // ss tight-loose; loose-tight
    if(goodleps.size()==0&&looseleps.size()==2) { if(hyp_type_looper(looseleps) >-1 ) return 1;}  //ss loose-loose
    if(looseleps.size()==2&&hyp_type_looper(looseleps)<0)  return -1;
  return 0; //should not end up here
}

vector<int> vetojets(){
 vector<int> vetojets;
 for(unsigned int jetindex=0;jetindex<jets_p4().size();++jetindex){
 if( jets_p4().at(jetindex).pt()>20 &&fabs(jets_p4().at(jetindex).eta())<5) vetojets.push_back(jetindex); 
 }
return vetojets;
}

vector<int> forwardjets(){
 vector<int> forwardjets;
 for(unsigned int jetindex=0;jetindex<jets_p4().size();++jetindex){
 if( jets_p4().at(jetindex).pt()>30&&fabs(jets_p4().at(jetindex).eta())>2.5) forwardjets.push_back(jetindex); 
 }
return forwardjets;
}

vector<int> selectedjets(){
 vector<int> goodjets;
 for(unsigned int jetindex=0;jetindex<jets_p4().size();++jetindex){
 if( fabs(jets_p4().at(jetindex).eta())<2.5 && jets_p4().at(jetindex).pt()>30) goodjets.push_back(jetindex); 
 }
return goodjets;
}

inline bool sortByValue(const std::pair<int,int>& pair1, const std::pair<int,int>& pair2 ) {
  return pair1.second > pair2.second;
}

float ptlljj(vector<int>leps,vector<int>jets) {
 if(leps.size()<2||jets.size()<2)   return -999;
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > p4_system; 
  for (unsigned int i =0;i<leps.size();++i) {p4_system +=lep_p4().at(leps.at(i));}
  for (unsigned int i =0;i<jets.size();++i) {p4_system +=jets_p4().at(jets.at(i));}
  return p4_system.pt();
}

float mct(vector<int> selbjets_idx) {
   if (selbjets_idx.size()<2)  return -999;
   float ptb1 = jets_p4().at(selbjets_idx.at(0)).pt();
   float ptb2 = jets_p4().at(selbjets_idx.at(1)).pt();
   float phib1 = jets_p4().at(selbjets_idx.at(0)).phi();
   float phib2 = jets_p4().at(selbjets_idx.at(1)).phi();
   float dPhibb = getdphi(phib1,phib2);
   float mct = sqrt(2*ptb1*ptb2*(1+cos(dPhibb)));
  return mct;
}

float maxMt(vector<int>leps){
   float mt_max = 0;
   for(unsigned int i=0;i<leps.size();++i){
      float mt = calculateMt(lep_p4().at(leps.at(i)),met_pt(),met_phi());
      if(mt>mt_max) mt_max = mt; 
  } 
 return mt_max;
}

float dphi3lmet(vector<int>leps, float met_phi){
 float dphi = 0;
 if(leps.size()!=3) {cout<< "not exactly three leptons, wtf"<<endl;return dphi;}
 ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > p4_3l = 
 lep_p4().at(leps.at(0)) +lep_p4().at(leps.at(1))+lep_p4().at(leps.at(2));
 dphi = getdphi(met_phi,p4_3l.phi());
 return dphi;
}

float mjj_dRmin(vector<int> jets){
 float mjj(-999), dRjj_min(999),dRjj(999);
 std::pair <int,int> jetpair;
 if(jets.size()<2) return mjj;

 for (unsigned int i=0;i<jets.size();++i){
    for(unsigned int j = i;j<jets.size();++j){
      if( j==i) continue;
      dRjj =  deltaR(jets_p4().at(jets.at(i)),jets_p4().at(jets.at(j)));
     if(dRjj<dRjj_min) { dRjj_min = dRjj; jetpair = std::make_pair(i,j);}
    }
  }
 mjj = (jets_p4().at(jets.at(jetpair.first))+jets_p4().at(jets.at(jetpair.second))).mass();
return mjj; 
}

bool isgammafake(){ 
  bool gammafake = false;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_motherIdSS().at(lepindex) == -3) gammafake = true;
  }
 return gammafake;
 }
 
int gentype(){ 
  bool gammafake = false;
  unsigned int ngenlep = ngenLepFromTau()+ ngenLep();
  unsigned int nW(0), nZ(0);
  vector<int> reallepindex;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_motherIdSS().at(lepindex) > 0) reallepindex.push_back(lepindex);
      if(lep_motherIdSS().at(lepindex) == -3) gammafake = true;
      if(lep_isFromW().at(lepindex)) nW++;
      if(lep_isFromZ().at(lepindex)) nZ++;
  }
  if(ngenlep>2 || reallepindex.size()>2 || (nW>0 && nZ>0)) return 3; // lostlep
  if(ngenlep<2 && !gammafake) return 4; // jetfake

//found two real leptons
  if(reallepindex.size()==2) {
      int lep1_index = reallepindex.at(0);
      int lep2_index = reallepindex.at(1);
      int ilep1 =   triboson_np::lep_genPart_index().at(lep1_index);
      int ilep2 =   triboson_np::lep_genPart_index().at(lep2_index);
      bool lep1_chargeflip  =triboson_np::genPart_charge().at(ilep1)!= triboson_np::lep_charge().at(lep1_index);
      bool lep2_chargeflip  =triboson_np::genPart_charge().at(ilep2)!= triboson_np::lep_charge().at(lep2_index);
      if (!lep1_chargeflip&&!lep2_chargeflip) return 1; // true SS
      if (lep1_chargeflip||lep2_chargeflip)   return 2; // charge flip
   } 

  if(ngenlep<2 && gammafake) return 5;//gamma fake
//  if(ngenlep==2 && reallepindex.size()==1) {if( ) }
  return 1;
}

int gentype(unsigned lep1_index,unsigned lep2_index){ 
  bool gammafake = false;
  unsigned int ngenlep = ngenLepFromTau()+ ngenLep();
  unsigned int nW(0), nZ(0);
  bool lep1_real = lep_motherIdSS().at(lep1_index) > 0;
  bool lep2_real = lep_motherIdSS().at(lep2_index) > 0;
  vector<int> reallepindex;

  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_motherIdSS().at(lepindex) > 0) reallepindex.push_back(lepindex);
      if(lep_motherIdSS().at(lepindex) == -3) gammafake = true;
      if(lep_isFromW().at(lepindex)) nW++;
      if(lep_isFromZ().at(lepindex)) nZ++;
  }

  if(ngenlep>2 || reallepindex.size()>2 || (nW>0 && nZ>0)) return 3; // lostlep
  if((ngenlep<2 ||!lep1_real||!lep2_real)&& !gammafake) return 4; // jetfake

//found two real leptons
  if(lep1_real&&lep2_real) {
      int ilep1 =   triboson_np::lep_genPart_index().at(lep1_index);
      int ilep2 =   triboson_np::lep_genPart_index().at(lep2_index);
      bool lep1_chargeflip  =triboson_np::genPart_charge().at(ilep1)!= triboson_np::lep_charge().at(lep1_index);
      bool lep2_chargeflip  =triboson_np::genPart_charge().at(ilep2)!= triboson_np::lep_charge().at(lep2_index);
      if (!lep1_chargeflip && !lep2_chargeflip) return 0; // true SS
      if (lep1_chargeflip  ||  lep2_chargeflip)   return 2; // charge flip
   } 
  //found more than two leptons
  if(ngenlep<2 && gammafake) return 5;//gamma fake
  return 1;
 }

int gentype(unsigned lep1_index=0,unsigned lep2_index=1, int lep3_index=-1){
  bool gammafake = false;
  bool jetfake   = false;
  bool debug = false;
  unsigned int ngenlep = ngenLepFromTau()+ ngenLep();
  unsigned int nW(0), nZ(0);
  bool lep1_real = lep_motherIdSS().at(lep1_index) > 0;
  bool lep2_real = lep_motherIdSS().at(lep2_index) > 0;
  bool lep3_real = false;
  if(lep3_index>0) lep3_real = lep_motherIdSS().at(lep2_index) > 0;
  vector<int> reallepindex;

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_motherIdSS().at(lepindex) > 0) reallepindex.push_back(lepindex);
      else if(lep_motherIdSS().at(lepindex) == -3) gammafake = true;
      else                                           jetfake = true;
      if(lep_isFromW().at(lepindex)) nW++;
      if(lep_isFromZ().at(lepindex)) nZ++;
  }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
  //found two real leptons
  if(lep3_index<0){
    bool ischargeflip = false;
    bool isSS = false;
    if(lep1_real&&lep2_real) {
      int ilep1 =   lep_genPart_index().at(lep1_index);
      int ilep2 =   lep_genPart_index().at(lep2_index);
      bool lep1_chargeflip  =genPart_charge().at(ilep1)!= lep_charge().at(lep1_index);
      bool lep2_chargeflip  =genPart_charge().at(ilep2)!= lep_charge().at(lep2_index);
      if (!lep1_chargeflip&&!lep2_chargeflip&&nW==2) return 0; // true SS
      else if (!lep1_chargeflip&&!lep2_chargeflip) isSS = true; // true SS - but could be still lost lepton WZ
      if (lep1_chargeflip||lep2_chargeflip)   ischargeflip = true; // charge flip
    }

    if(ngenlep>2 || reallepindex.size()>2 || (nW>0 && nZ>0)) return 3; // lostlep
    if((ngenlep<2 ||!lep1_real||!lep2_real)&&    jetfake) return 4; // jetfake - if double fake with one jet fake and one gamma fake call it jet fake
    if((ngenlep<2 ||!lep1_real||!lep2_real)&&  gammafake) return 5; // gammafake
    if((ngenlep<2 ||!lep1_real||!lep2_real)&& !gammafake) return 4; // call all without gamma fake jetfake - safety cut
    if(isSS) return 0;
    if(ischargeflip) return 2;

    cout << "This event was not classified - 2 lepton event - v2" << endl;
    return 1;
  } else {
    //found three real leptons
    bool ischargeflip = false;
    bool isthreelep = false;
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms :" << lep3_index<< lep_genPart_index().size()<<endl;
    if(lep1_real&&lep2_real&&lep3_real) {
      int ilep1 =   lep_genPart_index().at(lep1_index);
      int ilep2 =   lep_genPart_index().at(lep2_index);
      int ilep3 =   lep_genPart_index().at(lep3_index);
      bool lep1_chargeflip  =genPart_charge().at(ilep1)!= lep_charge().at(lep1_index);
      bool lep2_chargeflip  =genPart_charge().at(ilep2)!= lep_charge().at(lep2_index);
      bool lep3_chargeflip(false);
      if(ilep3>=0) lep3_chargeflip  =genPart_charge().at(ilep3)!= lep_charge().at(lep3_index);
      if (!lep1_chargeflip&&!lep2_chargeflip&&!lep3_chargeflip&&nW==3) return 0; // true WWW
      else if (!lep1_chargeflip&&!lep2_chargeflip&&!lep3_chargeflip) isthreelep = true; // true 3l, but could be lost lepton ZZ
      if (lep1_chargeflip||lep2_chargeflip||lep3_chargeflip)   ischargeflip = true; // charge flip
    }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
    if(ngenlep>3 || reallepindex.size()>3 || (nW>=2 && nZ>=1) || (nZ>=3)) return 3; // lostlep (2 lep from W and 2 from Z, or 4 from Z)
    //there is the case of having WZZ with two lost leptons --> ngenlep>3 - correctly put has lostlep
    if((ngenlep<3 ||!lep1_real||!lep2_real||!lep3_real)&&    jetfake) return 4; // jetfake
    if((ngenlep<3 ||!lep1_real||!lep2_real||!lep3_real)&&  gammafake) return 5; // gammafake
    if((ngenlep<3 ||!lep1_real||!lep2_real||!lep3_real)&& !gammafake) return 4; // jetfake
    if(isthreelep) return 1;
    if(ischargeflip) return 2;
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;

    cout << "This event was not classified - 3 lepton event - v2" << endl;
    return 0;
  }
}

float coneCorrPt(int lepi){
        float coneptcorr = 0;
        float relIso = lep_relIso03EAv2().at(lepi);
        bool passId = isGoodLepton(lepi, "trilep"); 
        if ( abs(lep_pdgId().at(lepi)) == 11 )
        {
            if ( fabs(lep_eta().at(lepi)) <= 1.479 )
                coneptcorr = std::max( 0., relIso - 0.0588 );
            else
                coneptcorr = std::max( 0., relIso - 0.0571 );
        }

        if ( abs(lep_pdgId().at(lepi)) == 13 )
            coneptcorr = std::max( 0., relIso - 0.06 );

        // If the lepton passed the tight ID no correction is needed.
        if ( passId )  coneptcorr = 0;
 return coneptcorr;
 }
//fakerate function has to take in the loose leptons
float fakerateweight(bool subtract,string selection,unsigned lep1_index,unsigned lep2_index,int lep3_index=-1){
            bool coneCorr(true),doData(false),inSitu(false), lep1_fakeable(false),lep2_fakeable(false),lep3_fakeable(false);
            float weight = 0;
            float lep1_pT_org(-999),lep2_pT_org(-999),lep3_pT_org(-999);
            float lep1_pT(-999),lep2_pT(-999),lep3_pT(-999);
            int lep1_id(0),lep2_id(0),lep3_id(0);
            float e1 = 0.;  //rate = Nt/Nl
            float e1a = 0.;  //rate = Nt/Nl
            float e2 = 0.;  //rate = Nt/Nl
            float e2a = 0.;  //rate = Nt/Nl
            lep1_pT_org = triboson_np::lep_p4().at(lep1_index).pt();
            lep2_pT_org = triboson_np::lep_p4().at(lep2_index).pt();
            lep1_pT = (coneCorrPt(lep1_index)+1)*lep1_pT_org;
            lep2_pT = (coneCorrPt(lep2_index)+1)*lep2_pT_org;
            lep1_id = triboson_np::lep_pdgId().at(lep1_index);
            lep2_id = triboson_np::lep_pdgId().at(lep2_index);
            lep1_fakeable = isLooseNotTight(lep1_index,selection); 
            lep2_fakeable = isLooseNotTight(lep2_index,selection);

            if(lep3_index>-1) {
              lep3_fakeable = isLooseNotTight(lep3_index,selection);
              lep3_pT_org = triboson_np::lep_p4().at(lep3_index).pt();
              lep3_pT = (coneCorrPt(lep3_index)+1)*lep3_pT_org;
              lep3_id = triboson_np::lep_pdgId().at(lep3_index);
            }
            if(subtract) weight *= -1;
            if(!lep1_fakeable && !lep2_fakeable && !lep3_fakeable) weight = 0; //no fakeable object
            if(lep1_fakeable && !lep2_fakeable &&!lep3_fakeable){
            //weight for lep1
               weight = 1;
               e1 = getFakeRate(abs(lep1_id), lep1_pT, fabs(lep_p4().at(lep1_index).eta()), triboson_np::ht(), false, doData, inSitu );
               if(TString(selection).Contains("up")) e1 +=getFakeRateError(abs(lep1_id), lep1_pT, fabs(lep_p4().at(lep1_index).eta()), triboson_np::ht(),inSitu);
               if(TString(selection).Contains("down")) e1 +=-getFakeRateError(abs(lep1_id), lep1_pT, fabs(lep_p4().at(lep1_index).eta()), triboson_np::ht(),inSitu);
               e1a = getFakeRate2(abs(lep1_id), lep1_pT_org, fabs(lep_p4().at(lep1_index).eta()), triboson_np::ht(), false, doData); 
               weight = coneCorr ? (e1/(1-e1))*weight : (e1a/(1-e1a))*weight;
            }
            if(lep2_fakeable && !lep1_fakeable && !lep3_fakeable){
            //weight for lep2
               weight = 1;
                e2 = getFakeRate(abs(lep2_id), lep2_pT, fabs(lep_p4().at(lep2_index).eta()), triboson_np::ht(), false, doData, inSitu );
                e2a = getFakeRate2(abs(lep2_id), lep2_pT_org, fabs(lep_p4().at(lep2_index).eta()), triboson_np::ht(), false, doData); 
               if(TString(selection).Contains("up")) e2 +=getFakeRateError(abs(lep2_id), lep2_pT, fabs(lep_p4().at(lep2_index).eta()), triboson_np::ht(),inSitu);
               if(TString(selection).Contains("down")) e2 +=-getFakeRateError(abs(lep2_id), lep2_pT, fabs(lep_p4().at(lep2_index).eta()), triboson_np::ht(),inSitu);
                weight = coneCorr ? (e2/(1-e2))*weight : (e2a/(1-e2a))*weight;
            }
            if(lep3_fakeable && !lep1_fakeable && !lep2_fakeable){
            //weight for lep3
               weight = 1;
                e2 = getFakeRate(abs(lep3_id), lep3_pT, fabs(lep_p4().at(lep3_index).eta()), triboson_np::ht(), false, doData, inSitu );
                e2a = getFakeRate2(abs(lep3_id), lep3_pT_org, fabs(lep_p4().at(lep3_index).eta()), triboson_np::ht(), false, doData); 
               if(TString(selection).Contains("up")) e2 +=getFakeRateError(abs(lep3_id), lep3_pT, fabs(lep_p4().at(lep3_index).eta()), triboson_np::ht(),inSitu);
               if(TString(selection).Contains("down")) e2 +=-getFakeRateError(abs(lep3_id), lep3_pT, fabs(lep_p4().at(lep3_index).eta()), triboson_np::ht(),inSitu);
                weight = coneCorr ? (e2/(1-e2))*weight : (e2a/(1-e2a))*weight;
            }
            if(lep1_fakeable && lep2_fakeable){// skip double fakes for now
             weight = 0; 
           }
     
     return weight;      
}

}//end of namespace
