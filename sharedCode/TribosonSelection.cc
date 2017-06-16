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
#include "../classFiles/triboson_v3/triboson.h"
#include "Math/VectorUtil.h"
#include "StopSelections.h"
using namespace std;
using namespace triboson_np; 

namespace tribosonsel{
static const float BTAGWP = 0.5426;
static const float mBTAGWP = 0.8484;
const double ZMASS = 91.1876;
//--------------//
// preselection //
//--------------//
int preselRegion(){
    if(passPreselection("ss_loose")) {
      vector<int> goodleps = selectedLooseLeps("SS_veto_noiso_v5");                           //find good leptons
      int type_looper = hyp_type_looper(goodleps);                                           //find event type
      if(type_looper==0) return 1;
      if(type_looper==2) return 2;
      if(type_looper==1) return 3;
    }
    else if(passPreselection("trilep_loose")){
      vector<int> leps_index = selectedLooseLeps("trilep"); 
      int trileptype = trileptype_dilepmass(leps_index).first;
      if(trileptype==1) return 4;
      if(trileptype==2) return 5;
      if(trileptype==3) return 6;
   }
   return -999; 
}

int signalRegion2016(){
    if(passSR("ss_loose")) {
      vector<int> goodleps = selectedLooseLeps("SS_veto_noiso_v5");                                  //find good leptons
      int type_looper = hyp_type_looper(goodleps);                              //find event type
      if(type_looper==0) return 1;
      if(type_looper==2) return 2;
      if(type_looper==1) return 3;
    }
    else if(passSR("trilep_loose")){
      vector<int> leps_index = selectedLooseLeps("trilep"); 
      int trileptype = trileptype_dilepmass(leps_index).first;
      if(trileptype==1) return 4;
      if(trileptype==2) return 5;
      if(trileptype==3) return 6;
   }
   return -999; 
}

bool passPreselection(string selection) {
 bool passTrigger =  HLT_singleEl()||HLT_singleMu()||HLT_singleMu_noiso()||HLT_DoubleEl_noiso()|| HLT_DoubleEl_DZ_2();
 passTrigger = true;
 if( !TString(selection).Contains("medbtag") && nBJetLoose()>0) return false; //default is loose btag now.
 if( TString(selection).Contains("medbtag") && nBJetMedium()>0) return false;
 vector<int> goodjets =  selectedjets();
 vector<int> veto_jets =  vetojets();
 vector<int> forward_jets =  forwardjets();
 int njets_sel = goodjets.size();
 int njets_veto = veto_jets.size();
 int njets_forward = forward_jets.size();
 
 if( TString(selection).Contains("jecup"))    njets_sel = njets_up();
 if( TString(selection).Contains("jecdown"))  njets_sel = njets_dn();

if(TString(selection).Contains("ss")){
 vector<int> goodleps = selectedLeps(selection);                           //find good leptons
 if (TString(selection).Contains("loose")) goodleps = selectedLooseLeps(selection);
 int nvetoleps = countvetoleps(5);
 int type_looper = hyp_type_looper(goodleps);                              //find event type
 if( !passTrigger)                                        return false; 
 if( !TString(selection).Contains("crwz")&&(goodleps.size()!=2||nlep()!=2||nveto_leptons()>0))    return false; 
 if( TString(selection).Contains("crwz")&&goodleps.size()!=3)                                  return false;
 if( type_looper<0)                                       return false; //event not SS type
 if( njets_sel<2)                                         return false; // at least two jets
 if( !TString(selection).Contains("noisotrackveto") && !TString(selection).Contains("crwz")&& nisoTrack_mt2()>0) return false; //isotrackveto, on bydefault now
 if( TString(selection).Contains("jetveto") && njets()>4) return false; //isotrackveto
 if( TString(selection).Contains("ee") && type_looper!=0) return false;    //ee
 if( TString(selection).Contains("mm") && type_looper!=1) return false;    //mm
 if( TString(selection).Contains("em") && type_looper!=2) return false;    //em
 float dilepmass = (lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).mass();// calculate dilepton mass
 if( type_looper==0 && dilepmass>80 && dilepmass<100)     return false;    //for ee events, veto zmass
 if( dilepmass<40)                    return false;                                  // dilepmass>40
 if( type_looper!=1&&met_pt()<40)     return false;                                  // met cut for ee/emu
 return true;
 }

if(TString(selection).Contains("trilep")){
 vector<int> leps_index = selectedLeps(selection); 
 if (TString(selection).Contains("loose")) leps_index = selectedLooseLeps(selection);
 //if( leps_index.size()!=3) return false;
 if( leps_index.size()!=3 || nlep()!=3) return false;
 float dphi = dphi3lmet(leps_index,met_phi());
 if( dphi<2.5)                 return false;
 if( njets_veto >1 )           return false;
 int   trileptype = trileptype_dilepmass(leps_index).first;
 float dilepmass = trileptype_dilepmass(leps_index).second;
 bool pass_SFOS0 = (trileptype==0 && dilepmass>20 );
 bool pass_SFOS1 = (trileptype==1 && dilepmass>20 && met_pt()>45 );
 bool pass_SFOS2 = (trileptype==2 && dilepmass>20 && met_pt()>55 );

 if( TString(selection).Contains("nomet")) {
     pass_SFOS1 = (trileptype==1); 
     pass_SFOS2 = (trileptype==2);
 }
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
 if( !TString(selection).Contains("medbtag") && nBJetLoose()>0) return false; //default is loose btag now.
 counterhist->Fill(1);
 if( TString(selection).Contains("medbtag") && nBJetMedium()>0) return false;
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
 if( !TString(selection).Contains("medbtag") && nBJetLoose()>0) return false; //default is loose btag now.
 if( TString(selection).Contains("medbtag") && nBJetMedium()>0) return false;
 vector<int> goodjets =  selectedjets();
 vector<int> veto_jets =  vetojets();
 vector<int> forward_jets =  forwardjets();
 int njets_sel = goodjets.size();
 int njets_veto = veto_jets.size();
 int njets_forward = forward_jets.size();
 
 if( TString(selection).Contains("jecup"))    njets_sel = njets_up();
 if( TString(selection).Contains("jecdown"))  njets_sel = njets_dn();

if(!passPreselection(selection)) return false;

if(TString(selection).Contains("ss")){
 float mjj = mjj_dRmin(goodjets);
 float mjj_lead = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).mass();                    // dijet mass
 double deta_jj = abs(jets_p4().at(goodjets.at(0)).eta() - jets_p4().at(goodjets.at(1)).eta());      // dijet eta
 if( TString(selection).Contains("crwz"))  return true;

 if( TString(selection).Contains("atlas")) {
 if( fabs(mjj_lead-85)>20)                 return false;                                  // w mass window cut
 if( deta_jj>1.5)                          return false;                                  // delta eta cut
 if( jets_p4().at(goodjets.at(0)).pt()<30||fabs(jets_p4().at(goodjets.at(0)).eta())>2.5)         return false;                                  // leading jet pt
 if( jets_p4().at(goodjets.at(1)).pt()<20||fabs(jets_p4().at(goodjets.at(1)).eta())>2.5)         return false;                                  // leading jet pt
 return true;
 }
 
 if( mjj>100 || mjj<60)               return false;                                  // w mass window cut
 if( mjj_lead >400)                   return false;
 if( deta_jj>1.5)                     return false;                                  // delta eta cut
 if( jets_p4().at(goodjets.at(0)).pt()<30||fabs(jets_p4().at(goodjets.at(0)).eta())>2.5)         return false;                                  // leading jet pt
 if( jets_p4().at(goodjets.at(1)).pt()<30||fabs(jets_p4().at(goodjets.at(1)).eta())>2.5)         return false;                                  // leading jet pt
 return true;
}

if(TString(selection).Contains("trilep")){
 vector<int> leps_index = selectedLeps(selection); 
 if(TString(selection).Contains("loose")) leps_index = selectedLooseLeps(selection);
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
 if( TString(selection).Contains("ptlll60")&&ptlll<60) return false;  
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
// all three are e/m
int eventcharge = lep_charge().at(sellep_index.at(0))
                  *lep_charge().at(sellep_index.at(1))
                  *lep_charge().at(sellep_index.at(2));
unsigned int lep_os(0);
float dilepmass_min = -999;

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

for (unsigned int lep_index = 0;lep_index<3;++lep_index){
    if (lep_index==lep_os) continue;
    float dilepmass = (lep_p4().at(sellep_index.at(lep_index))+lep_p4().at(sellep_index.at(lep_os))).mass();
    if (abs(dilepmass-ZMASS) < abs(dilepmass_min-ZMASS) && 
       abs(lep_pdgId().at(sellep_index.at(lep_index))) == abs(lep_pdgId().at(sellep_index.at(lep_os)))) 
    dilepmass_min = dilepmass;
}

if(trileptype ==2 ) return make_pair(trileptype,dilepmass_min);

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
  if(TString(selection).Contains("ss"))  pt_cut=30.0;
  if(TString(selection).Contains("ss")) pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el &&abs(lep_ip3d().at(lepindex))<0.015 && (abs(lep_pdgId().at(lepindex))==13 || lep_tightCharge().at(lepindex) == 2) && lep_pass_VVV_cutbased_tight_noiso().at(lepindex);
  else pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el &&abs(lep_ip3d().at(lepindex))<0.015;
  return pass_cut;
}

bool isLooseLepton(int lepindex, string selection){
  float pt_cut = 20.0;
  float iso_cut_el = 0.4;
  float iso_cut_mu = 0.4;
  bool pass_cut = false;
  // case(SS_veto_noiso_v5):
  // trigger match cuts
  // if (!isTriggerSafenoIso_v1(elIdx)) return false;
  //            if (fabs(els_etaSC().at(elIdx)) > 2.5) return false;
  //                  if (els_conv_vtx_flag().at(elIdx)) return false;
  //                        if (els_exp_innerlayers().at(elIdx) > 1) return false;
  //                              if (fabs(els_dxyPV().at(elIdx)) >= 0.05) return false;
  //                                    if (fabs(els_dzPV().at(elIdx)) >= 0.1) return false; 
  //                                          if (globalEleMVAreader==0){
  //                                                  cout << "readMVA=0, please create and init it (e.g with createAndInitMVA function)" << endl;
  //                                                          return false;
  //                                                                }
  //                                                                      return globalEleMVAreader->passesElectronMVAid(elIdx, id_level);
  //                                                                            break;
  //
  if(TString(selection).Contains("SS_veto_noiso_v5")) {
   pt_cut=30.0;
   pass_cut =  lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el && lep_pass_VVV_cutbased_fo_noiso().at(lepindex);    
}
   
  if(TString(selection).Contains("ss")) { pt_cut=30.0; pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el;}
  else pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el;
  return pass_cut;
}

vector<int> selectedLooseLeps(string selection){
  vector<int> selectedlooseleps;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(isLooseLepton(lepindex,selection)) selectedlooseleps.push_back(lepindex);
  }
return selectedlooseleps;
}

vector<int> selectedLeps(string selection){
  vector<int> selectedleps;
  float pt_cut = 20.0;
  float iso_cut_el = 0.06;
  float iso_cut_mu = 0.06;
  if(TString(selection).Contains("ss"))  pt_cut=30.0;
  if(TString(selection).Contains("looseiso")) {iso_cut_el=0.1;iso_cut_mu=0.1;}
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      bool pass_cut = false;
      if(TString(selection).Contains("ss")) pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el &&abs(lep_ip3d().at(lepindex))<0.015 && (abs(lep_pdgId().at(lepindex))==13 || lep_tightCharge().at(lepindex) == 2);
      else pass_cut = lep_p4().at(lepindex).pt() > pt_cut && lep_relIso03EA().at(lepindex)<iso_cut_el &&abs(lep_ip3d().at(lepindex))<0.015;
      if(pass_cut)
       selectedleps.push_back(lepindex);
  }
return selectedleps;
}


int countvetoleps(float pt_cut){
  int nvetolep = 0;
  for (unsigned int lepindex = 0;lepindex<lep_p4().size();++lepindex){
      if(lep_p4().at(lepindex).pt() > pt_cut)
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
        if(isGoodLepton(lepindex,"ss")) goodleps.push_back(lepindex);
        if(isLooseLepton(lepindex,"SS_veto_noiso_v5")) looseleps.push_back(lepindex);
    }
    if(looseleps.size()!=2)  return -999; // three lepton event
    if(goodleps.size()==2) {if(hyp_type_looper(goodleps)>-1) return 3;} //ss tight-tight 
    if(goodleps.size()==1&&looseleps.size()==2) { if(hyp_type_looper(looseleps) >-1 ) return 2;}// ss tight-loose; loose-tight
    if(goodleps.size()==0&&looseleps.size()==2) { if(hyp_type_looper(looseleps) >-1 ) return 1;}  //ss loose-loose
    if(looseleps.size()==2&&hyp_type_looper(looseleps)<0)  return -1;
  return 0; //should not end up here
}

vector<int> vetojets(){
 vector<int> vetojets;
 for(unsigned int jetindex=0;jetindex<jets_p4().size();++jetindex){
 if( jets_p4().at(jetindex).pt()>25 &&fabs(jets_p4().at(jetindex).eta())<4.5) vetojets.push_back(jetindex); 
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
 if( fabs(jets_p4().at(jetindex).eta())<2.5) goodjets.push_back(jetindex); 
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

float minMt(vector<int>leps){
   float mt_min = 99999;
   for(unsigned int i=0;i<leps.size();++i){
      float mt = calculateMt(lep_p4().at(leps.at(i)),met_pt(),met_phi());
      if(mt<mt_min) mt_min = mt; 
  } 
 return mt_min;
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
 if(jets.size()<2) {cout<<"need at least two jets"<<endl;return mjj;}
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

pair <int, int> lepMotherID_v2(int lepindex){
  int id_reco = lep_pdgId().at(lepindex);  
  if (abs(id_reco) != 11 && abs(id_reco) != 13) return make_pair(0, 0); 
  int idx_reco = lepindex; 
  LorentzVector recop4 = lep_p4().at(lepindex); 

  //First, see if CMS3 matches the particle to the right type, or can't match it at all.  If it does, just use that
  //int gen_idx = (abs(id_reco) == 11) ? tas::els_mc3idx().at(idx_reco) : tas::mus_mc3idx().at(idx_reco); 
  int idx = -1;
  int id = -1; 
  bool goodOne = false;
  float dR_best = 1000;
    for (unsigned int iGen = 0; iGen < genPart_pt().size(); iGen++){
      float dR = DeltaR(genPart_eta().at(iGen) ,recop4.eta(),genPart_phi().at(iGen) ,recop4.phi());  
    //First see if this one is closer than alternatives
      if (dR < dR_best && goodOne == false){ 
        dR_best = dR; 
        idx = iGen;
        id =  genPart_pdgId().at(iGen); 
      }
      //Now regardless of that, see if we can get a "good" match
      if (dR > 0.2) continue;
      if (abs( genPart_pdgId().at(iGen)) != abs(id_reco)) continue;
      if (abs( genPart_status().at(iGen)) != 1) continue; 
      if (dR < dR_best || !goodOne){
        goodOne = true;
        dR_best = dR; 
        idx = iGen;
        id = genPart_pdgId().at(iGen); 
      }
    }
  //If you get here and idx < 0, failed to match
  if (idx < 0) return make_pair(0, idx); 

  //Mother & Grandma ID
  int mother_id = genPart_motherId().at(idx);
  int grandma_id = genPart_grandmaId().at(idx);  
  //Now we are matched, classify it
  if ((abs(id) != abs(id_reco)) && abs(id) != 22) return make_pair(0, idx); 
  if (isData()) return make_pair(1, idx);
  if (abs(id) == 22  || (abs(id) == abs(id_reco) && abs(mother_id) == 22)){
    // doublecheck if (gamma_genIsPromptFinalState().at(idx) || tas::genps_isDirectPromptTauDecayProductFinalState().at(idx) || tas::genps_isHardProcess().at(idx)) return make_pair(-3, idx);
   // if (gamma_genIsPromptFinalState().at(idx)) return make_pair(-3, idx);
 //   else return make_pair(0, idx); 
    return make_pair(-3, idx);  
 }
  //If you get here, we have a well-matched MC particle.  Now check its pedigree.
  //if (tas::genps_isPromptFinalState().at(idx) || tas::genps_isDirectPromptTauDecayProductFinalState().at(idx) || tas::genps_isHardProcess().at(idx) || (abs(id) == abs(id_reco) && (abs(mother_id) == 24 || abs(mother_id) == 23 || abs(mother_id) == 1000024 || (abs(mother_id) == 15 && (abs(grandma_id) == 24 || abs(grandma_id) == 23 || abs(grandma_id) == 1000024))))){
  if ((abs(id) == abs(id_reco) && (abs(mother_id) == 24 || abs(mother_id) == 23 || abs(mother_id) == 1000024 || (abs(mother_id) == 15 && (abs(grandma_id) == 24 || abs(grandma_id) == 23 || abs(grandma_id) == 1000024))))){    
    if (sgn(id_reco) == sgn(id)) return make_pair(1, idx);
    else return make_pair(2, idx);
  }
  else if (lep_isFromW().at(lepindex)) return make_pair(1, idx);
  else if (lep_isFromB().at(lepindex)) return make_pair(-1, idx);
  else if (lep_isFromC().at(lepindex)) return make_pair(-2, idx);
  else if (lep_isFromLF().at(lepindex)) return make_pair(-4, idx);
  return make_pair(0, idx);
 }
}//end of namespace
