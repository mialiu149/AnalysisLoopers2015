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

#include "WHSelection.h"
#include "EventTypeSel.h"
#include "../stop_variables/MT2_implementations.h"
#include "histTools.h"
//#include "V00_00_05.h"
#include "V80_00.h"
#include "Math/VectorUtil.h"
using namespace std;
//using namespace V00_00_05_np; 
using namespace V80_00_np; 

namespace whsel{
//static const float BTAGWP = 0.460;
static const float BTAGWP = 0.800;
//--------------//
// preselection //
//--------------//

bool passPreselection(string selection) {
 bool passTrigger =  HLT_SingleMu()|| HLT_SingleEl();
// if (TString(selection).Contains("notrigger") ) 
 passTrigger = true; // fast sim doesn't have the right trigger information.
 bool passOneLep = (lep1type()==1);
 if( !passTrigger) return false;
 if( lep1type()!=1) return false; // lep1 is good lepton
 //if( !TString(selection).Contains("noabsiso") && !(lep1_relIso()*lep1_p4().pt() < 5)) return false;
 //if( TString(selection).Contains("reliso") && !(lep1_relIso() < 0.1)) return false;
 //if( !(lep1_relIso() < 0.1)) return false;
 if( !(lep1_relIso()*lep1_p4().pt() < 5)) return false;
 if( TString(selection).Contains("SR") || TString(selection).Contains("1lCR")) {     //if SR, second lepton veto
 if( lep2type()==1||lep2type()==2) return false;
 //if( eventtype()!=5)               return false;
 if( !PassTrackVeto())          return false;  // ttrack veto
 if( !PassTauVeto())               return false; // tau veto
 }
 if( pfmet() < 50)                                                 return false; // min met cut.
 return true;
}
bool passWJetsValidation(){
 bool passTrigger =  HLT_SingleMu()|| HLT_SingleEl();
// if (TString(selection).Contains("notrigger") ) 
 passTrigger = true; // fast sim doesn't have the right trigger information.
 if( lep1type()!=1)                       return false; 
 if( !(lep1_relIso()*lep1_p4().pt() < 5)) return false;
 //if( lep2type()==1||lep2type()==2)        return false;
 if( ngoodjets()<2)                       return false;
 if( pfmet() < 200)                        return false; // min met cut.
 //if( ak4_HT()<150)                        return false;
 
 return true;
}

bool passcutflow( std::string selection){
  
 bool passTrigger =  HLT_SingleMu()|| HLT_SingleEl();
 passTrigger = true; // fast sim doesn't have the right trigger information.
 bool passOneLep = (lep1type()==1);
 bool passLepSel = !(lep2type()==1||lep2type()==2);
 std::pair<vector<int>,vector<int>> jets = btaggedjets(); vector<int> seljets = jets.first;// btagged jets.
 float m_bb = getmbb();  float mctbb = getmct();
 float mt = mt_met_lep();
 float event_met_pt = pfmet();
 if(TString(selection).Contains("genmet")   ) {event_met_pt = genmet();mt = calculateMt(lep1_p4(),event_met_pt,genmet_phi());}

  bool step0 = passTrigger; 
  bool step1 = step0 && passOneLep; 
  bool step2=  step1 && passLepSel; 
  bool step3 = step2 && PassTrackVeto();
  bool step4 = step3 && PassTauVeto();
  bool step5 = step4 && (ngoodbtags()==2);
  bool step6 = step5 && (ngoodjets()==2);
  bool step7 = step6 && (m_bb>90&&m_bb<150);
  bool step8 = step7 && (mctbb>150); 
  bool step9 = step8 && (event_met_pt > 100);
  bool step10 = step9&& (mt>150);

 if( TString(selection).Contains("step0") && !step0)   return false;
 if( TString(selection).Contains("step1") && !step1)   return false; //if cutflow returns true
 if( TString(selection).Contains("step2") && !step2)   return false;
 if( TString(selection).Contains("step3") && !step3)   return false; 
 if( TString(selection).Contains("step4") && !step4)   return false;
 if( TString(selection).Contains("step5") && !step5)   return false;
 if( TString(selection).Contains("step6") && !step6)   return false;
 if( TString(selection).Contains("step7") && !step7)   return false;
 if( TString(selection).Contains("step8") && !step8)   return false;
 if( TString(selection).Contains("step9") && !step9)   return false;
 if( TString(selection).Contains("step10") && !step10)   return false;
 return true;
}

bool passISR(){
 //std::pair<vector<int>,vector<int>> jets = btaggedjets(); vector<int> seljets = jets.second;
 //if( seljets.size()==0) return false;
 //int leadjet = seljets.at(0); if( ak4pfjets_p4().at(leadjet).pt() > 50)  return true;
  if(ngoodjets()>2&&ak4pfjets_p4().at(0).pt()>150) return true;
 else return false;
}

bool passSR( std::string selection){
  float m_bb = getmbb();
  float mctbb = getmct();
  float event_met_pt = pfmet();
  float mt = mt_met_lep();
  if(TString(selection).Contains("worseMET") ) {event_met_pt = worseMETrel(0.2);mt = calculateMt(lep1_p4(),event_met_pt,pfmet_phi());}
  if(TString(selection).Contains("genMET")   ) {event_met_pt = genmet();mt = calculateMt(lep1_p4(),event_met_pt,genmet_phi());}
  bool met_mt_cut = ( event_met_pt > 50 &&  mt> 50 ); 
  if(TString(selection).Contains("mt120"))  met_mt_cut = ( event_met_pt > 50 && mt > 120 );                                       
  if(TString(selection).Contains("mt150"))  met_mt_cut = ( event_met_pt > 50 && mt > 150 );
  if(!passPreselection(selection.c_str()))                                                  return false;
  if(TString(selection).Contains("onebtag")) {if( ngoodbtags() != 1)                        return false;}// btagged}
  if(TString(selection).Contains("twobtag")) {if( ngoodbtags() != 2)                        return false;}// btagged}
 std::pair<vector<int>,vector<int>> jets = btaggedjets(); vector<int> bjets = jets.first;// btagged jets.
 vector<int> seljets = selbjets();

 if( ngoodjets()  != 2 )                                  return false;// exactly 2 jets
 //if( ngoodbtags() !=2)                                  return false;
// if( bjets.size() !=2)                                  return false;
 if( !met_mt_cut)                                         return false;
 if( TString(selection).Contains("mbb"))     {if(m_bb>150||m_bb<90)       return false;}
 if( TString(selection).Contains("mct50"))   {if(mctbb<50)                 return false;} // mct cuts
 if( TString(selection).Contains("mct100"))  {if(mctbb<100)                return false;} 
 if( TString(selection).Contains("mct125"))  {if(mctbb<125)                return false;}
 if( TString(selection).Contains("mct160"))  {if(mctbb<160)                return false;}
 if( TString(selection).Contains("mct150"))  {if(mctbb<150)                return false;}
 if( TString(selection).Contains("mct170"))  {if(mctbb<170)                return false;}
 if( TString(selection).Contains("met100"))  {if(event_met_pt<100)              return false;} 
 if( TString(selection).Contains("met150"))  {if(event_met_pt<150)              return false;} 
 if( TString(selection).Contains("met175"))  {if(event_met_pt<175)              return false;} 
 if( TString(selection).Contains("met200"))  {if(event_met_pt<200)              return false;}
 if( TString(selection).Contains("met250"))  {if(event_met_pt<250)              return false;}

 if( TString(selection).Contains("metbin1v1")) {if(pfmet()<100||pfmet()>125) return false;} //met cuts
 if( TString(selection).Contains("metbin2v1")) {if(pfmet()<125||pfmet()>150) return false;}
 if( TString(selection).Contains("metbin3v1")) {if(pfmet()<150||pfmet()>200) return false;}
 if( TString(selection).Contains("metbin4v1")) {if(pfmet()<200)              return false;}

 if( TString(selection).Contains("metbin1v2")) {if(pfmet()<100||pfmet()>150) return false;} 
 if( TString(selection).Contains("metbin2v2")) {if(pfmet()<150||pfmet()>200) return false;}
 if( TString(selection).Contains("metbin3v2")) {if(pfmet()<200)              return false;}

 if( TString(selection).Contains("metbin1v3")) {if(pfmet()<100||pfmet()>200) return false;} 
 if( TString(selection).Contains("metbin2v3")) {if(pfmet()<200)              return false;} 

 if( TString(selection).Contains("metbin1v4")) {if(pfmet()<100||pfmet()>175) return false;} 
 if( TString(selection).Contains("metbin2v4")) {if(pfmet()<175)              return false;} 

 if( TString(selection).Contains("metbin1v5")) {if(!(pfmet()>100&&ngoodbtags() == 2 && mctbb>150 && ngoodjets()  == 2))  return false;} //add ISR region
 if( TString(selection).Contains("metbin2v5")) {if(!(pfmet()>100&&ngoodbtags() == 2 && mctbb>150 && passISR())) return false;}

 if( TString(selection).Contains("metbin1v6")) {if(!(pfmet()>250&&ngoodbtags() == 1&&mctbb>180)) return false;}
 if( TString(selection).Contains("metbin2v6")) {if(!(pfmet()>100&& pfmet()<175 &&ngoodbtags() == 2 &&mctbb>150)) return false;}
 if( TString(selection).Contains("metbin3v6")) {if(!(pfmet()>175&&ngoodbtags() == 2 &&mctbb>150)) return false;}
  
 if( TString(selection).Contains("metbin1v7")) {if(!(pfmet()>100 && mctbb>150)) return false;}
 if( TString(selection).Contains("metbin2v7")) {if(!(pfmet()>200 && mctbb<150 && mctbb>100)) return false;}
 
 return true;
}

//--------------//
//   2l CR      //
//--------------//
bool pass2lCR( string selection ) {
  //bool pass2lCR =  ( lep2type() ==1 || lep2type() ==2 || !PassTrackVeto()||!PassTauVeto());                      // fail track veto: 2l CR.
  bool pass2lCR =  ( lep2type() ==1 ||  lep2type() ==2);                      // fail track veto: 2l CR.
  if( !passPreselection(selection))                   return false;                                    // preselection with at least 1 lep+ met50 + >=2jets 
  if( !pass2lCR)                                      return false; //pre selection + reverted veto
  if( ngoodbtags() != 2)                              return false;// btagged
  if( ngoodjets() !=2)                                return false;
  if( !passmetmt(selection))                            return false;
  if( !passbin(selection))                            return false;
 return true;
}

bool pass1lCR( string selection ) {
  if(!passPreselection("1lCR"))                      return false;// preselection with at least 1 lep+ met50 + >=2jets 
/*  if(TString(selection).Contains("bveto"))    {if(ngoodbtags()>0)   return false;}
  if(TString(selection).Contains("twobtag"))  {if(ngoodbtags()!= 2) return false;}// btagged}
  if(TString(selection).Contains("btag"))     {if(ngoodbtags()< 1)  return false;}// btagged}
  if(TString(selection).Contains("twojets"))  {if(ngoodjets()!= 2)  return false;}// exactly 2 jets
  if(TString(selection).Contains("onejets"))  {if(ngoodjets()> 2)   return false;}//  less than 2 jets
*/
//  vector<int> jets = selbjets();
 // if( jets.size()<2)                                  return false;
  if(ngoodbtags()>0)   return false;
  if(ngoodjets()!= 2)  return false;
  if( !passmetmt(selection))                            return false;
  if( !passbin(selection))                              return false;
  return true;
}

bool passmetmt(std::string selection ) {
 if( TString(selection).Contains("metbin1")) {if(pfmet()<50) return false;} //met cuts
// if( TString(selection).Contains("metbin1")) {if(pfmet()<50||pfmet()>100) return false;} //met cuts
 if( TString(selection).Contains("metbin2")) {if(pfmet()<100||pfmet()>125) return false;} //met cuts
 if( TString(selection).Contains("metbin3")) {if(pfmet()<125||pfmet()>150) return false;} //met cuts
 if( TString(selection).Contains("metbin4")) {if(pfmet()<150||pfmet()>200) return false;} //met cuts
 if( TString(selection).Contains("metbin5")) {if(pfmet()<200) return false;}
 if( TString(selection).Contains("met100"))  {if(pfmet()<100) return false;} 
 if( TString(selection).Contains("met150"))  {if(pfmet()<150) return false;} 
 if( TString(selection).Contains("met175"))  {if(pfmet()<175) return false;} 
 if( TString(selection).Contains("met200"))  {if(pfmet()<200) return false;}
 if( TString(selection).Contains("met250"))  {if(pfmet()<250) return false;}
 if( TString(selection).Contains("mtbulk"))  {if(mt_met_lep()<50 || mt_met_lep()>100) return false;}
 if( TString(selection).Contains("mt50"))    {if(mt_met_lep()<50) return false;}
 if( TString(selection).Contains("mt75"))    {if(mt_met_lep()<75) return false;}
 if( TString(selection).Contains("mt100"))    {if(mt_met_lep()<100) return false;}
 if( TString(selection).Contains("mt120"))   {if(mt_met_lep()<120) return false;}
 if( TString(selection).Contains("mt150"))   {if(mt_met_lep()<150) return false;}
 if( TString(selection).Contains("mt250"))   {if(mt_met_lep()<250) return false;}
 if( TString(selection).Contains("mt450"))   {if(mt_met_lep()<450) return false;}
 return true;
}
bool passbin(std::string selection ) {
  float m_bb = getmbb();
  float mctbb = getmct();
 if(m_bb<0) return false;
 if(mctbb<0) return false;
 if( TString(selection).Contains("mbb_"))     {if(m_bb>150||m_bb<90) return false;} //mbb cut  
 if( TString(selection).Contains("mct50"))   {if(mctbb<50)    return false;} // mct cuts
 if( TString(selection).Contains("mct100"))  {if(mctbb<100)    return false;} // mct cuts
 if( TString(selection).Contains("mct125"))  {if(mctbb<125)    return false;}
 if( TString(selection).Contains("mct150"))  {if(mctbb<150)    return false;}
 if( TString(selection).Contains("RegionA")) {if(mctbb<170||mt_met_lep()<150) return false; }// abcd regions
 if( TString(selection).Contains("RegionB")) {if(mctbb>170||mt_met_lep()<150) return false; }
 if( TString(selection).Contains("RegionC")) {if(mctbb<170||mt_met_lep()>150) return false; }
 if( TString(selection).Contains("RegionD")) {if(mctbb>170||mt_met_lep()>150) return false; }
 return true;
}

bool passmbbCR(  string selection ) {
 bool  met_mt_cut = ( pfmet() > 50 && mt_met_lep() > 0 );                                               // some additional requirement for CRs
 bool  pass1l =  met_mt_cut &&  lep2type() !=1&& lep2type() !=2 && PassTrackVeto() && PassTauVeto(); // pass 2nd lep veto etc.
 float m_bb = getmbb();
 float mctbb = getmct();
 bool  outside_mbb = (m_bb>150||m_bb<90);
 if( !passPreselection(selection))                   return false;// preselection with at least 1 lep+ met50 + >=2jets 
 if( ngoodbtags() != 2)                              return false;// btagged
 if( ngoodjets()  != 2)                              return false;// exactly 2 jets 
 if( !pass1l || !outside_mbb)                        return false;
 if( m_bb>90 && m_bb < 150)    { cout<<"outside mass window"<<endl; return false;}
 //if( TString(selection).Contains("mct150") && mctbb < 150) return false; 
 if( !passmetmt(selection))                          return false;
 if( !passbin(selection))                            return false;
 return true;
}

//-------------------------------------------------//
//// regions for optimization studies ---old---    //
//-------------------------------------------------//
bool passStudyRegion( string selection) {
  float MET = pfmet();
  float METPhi = pfmet_phi();
  float METx = MET*TMath::Cos(METPhi);
  float METy = MET*TMath::Sin(METPhi);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
  metlv.SetPxPyPzE(METx,METy,0.,MET);
  //select b jets
  std::pair<vector<int>,vector<int>> alljets;
  alljets = btaggedjets();
  vector<int> bjets = alljets.first;
  vector<int> addjets = alljets.second;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> bjetslv;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> addjetslv;
  if(!passPreselection("SR"))     return false;
  if(bjets.size()!=2 &&(TString(selection).Contains("2btags")||TString(selection).Contains("step5")))  return false; // require only two btagged.
  float m_bb = mbb(bjets);
  float pt_bb = ptbb(bjets);
  float mctbb = mct(bjets);
  float ptlbb = 0;
  int ngoodjets_low = bjets.size()+addjets.size();
  for (int i=0;i<bjets.size();i++) { ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jetlv = ak4pfjets_p4().at(bjets.at(i));bjetslv.push_back(jetlv); }
  for (int i=0;i<addjets.size();i++) { ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jetlv = ak4pfjets_p4().at(addjets.at(i));addjetslv.push_back(jetlv);}
  //recal MT2
  ptlbb = (bjetslv.at(0)+bjetslv.at(1)+lep1_p4()).pt();
  float MT2lb = CalcMT2_lb_b_(MET, METPhi, lep1_p4(), bjetslv, addjetslv, 0, false);	 
  if((m_bb>150||m_bb<100)&&TString(selection).Contains("mbb100"))                  return false; 
  if((m_bb>150||m_bb<90)&&TString(selection).Contains("mbb90"))                  return false; 
  if((m_bb>150||m_bb<100)&&TString(selection).Contains("step6"))                 return false;// mass window
  //after requiring two b tags 
  if(TString(selection).Contains("l5jets")&&ngoodjets_low>5)                     return false;
  if(TString(selection).Contains("l4jets")&&ngoodjets_low>3)                     return false;
  if(TString(selection).Contains("3jets")&&ngoodjets_low!=3)                     return false;
  if(TString(selection).Contains("2jets")&&ngoodjets_low!=2)                     return false; 
  // mt
  if(mt_met_lep()<150 && TString(selection).Contains("mt150"))                         return false;
  if(mt_met_lep()<125 && TString(selection).Contains("mt125"))                         return false;
  if(mt_met_lep()<120 && TString(selection).Contains("mt120"))                         return false;
  if(mt_met_lep()<100 && TString(selection).Contains("mt100"))                         return false;
  //met
  if((pfmet()<50  || pfmet()>100) && TString(selection).Contains("met100"))        return false; // change to exclusive binning
  if((pfmet()<100 || pfmet()>200) && TString(selection).Contains("met150"))        return false;
  if(pfmet()<200 && TString(selection).Contains("met175"))                         return false;
  if(TString(selection).Contains("met200") && pfmet()   < 200)                   return false;
  //mct
  if(mctbb<100 && TString(selection).Contains("mct100"))                         return false;
  if(mctbb<125 && TString(selection).Contains("mct125"))                         return false;
  if(mctbb<130 && TString(selection).Contains("mct130"))                         return false;
  if(mctbb<140 && TString(selection).Contains("mct140"))                         return false;
  if(mctbb<150 && TString(selection).Contains("mct150"))                         return false;
  if(mctbb<160 && TString(selection).Contains("mct160"))                         return false;
  if(mctbb<170 && TString(selection).Contains("mct170"))                         return false;
  if(mctbb<175 && TString(selection).Contains("mct175"))                         return false;
  if(mctbb<180 && TString(selection).Contains("mct180"))                         return false;
  if(mctbb<185 && TString(selection).Contains("mct185"))                         return false;
  if(mctbb<190 && TString(selection).Contains("mct190"))                         return false;
  if(mctbb<195 && TString(selection).Contains("mct195"))                         return false;
  if(mctbb<200 && TString(selection).Contains("mct200"))                         return false;
  if(mctbb<205 && TString(selection).Contains("mct205"))                         return false;
  if(mctbb<210 && TString(selection).Contains("mct210"))                         return false;
  if(mctbb<215 && TString(selection).Contains("mct215"))                         return false;
  if(mctbb<220 && TString(selection).Contains("mct220"))                         return false;
  if(mctbb<225 && TString(selection).Contains("mct225"))                         return false;
  //ptlbb && ptbb cuts
  if(TString(selection).Contains("ptlbb150")&& ptlbb<150)                      return false;
  if(TString(selection).Contains("ptlbb250")&& ptlbb>250)                      return false;
  if(TString(selection).Contains("ptbb200")&& pt_bb<200)                       return false;       
  if(TString(selection).Contains("mt2lb150") &&  MT2lb<150)                    return false;
  return true;
}

//-----------------------------------------//
// the following has some utility functions//
//-----------------------------------------//


inline bool sortIndexbyCSV( pair<int, float> &vec1, pair<int, float> &vec2 ) {
  return vec1.second > vec2.second;
}

vector <pair<int, float>> sortedjetsbyCSV(){
   vector <pair<int, float>> jet_csv_pairs;
   for( size_t jetind = 0; jetind < ak4pfjets_p4().size(); jetind++ ){
	  if( ak4pfjets_CSV().at(jetind) < BTAGWP && ak4pfjets_p4().at(jetind).Pt() > 30 &&// loose btagging.
	  //if( ak4pfjets_CSV().at(jetind) < 0.800 && ak4pfjets_p4().at(jetind).Pt() > 30 &&
                fabs(ak4pfjets_p4().at(jetind).Eta()) < 2.4
                && ak4pfjets_loose_pfid().at(jetind)){
	    jet_csv_pairs.push_back(make_pair(jetind,ak4pfjets_CSV().at(jetind)));
       }
   }
   sort( jet_csv_pairs.begin(), jet_csv_pairs.end(), sortIndexbyCSV);
  return jet_csv_pairs;
}

std::pair<vector<int>,vector<int>> btaggedjets()  {
 vector<int> bJets_idx;
 vector<int> nonbJets_idx;
 std::pair<vector<int>,vector<int>> jets;
 for(int iJet=0; iJet<(int)ak4pfjets_p4().size(); iJet++){
            if( ak4pfjets_p4().at(iJet).Pt() > 30 &&
                fabs(ak4pfjets_p4().at(iJet).Eta()) < 2.4 
                && ak4pfjets_loose_pfid().at(iJet)
                )
                {
               if (ak4pfjets_CSV().at(iJet) > BTAGWP) 
//                if (ak4pfjets_CSV().at(iJet) >0.800) 
                   bJets_idx.push_back(iJet);
                else nonbJets_idx.push_back(iJet);}
 }
 jets = std::make_pair (bJets_idx,nonbJets_idx);
 return jets;
}

vector<int> selbjets(){
 vector<int> seljets;
 std::pair<vector<int>,vector<int>> jets = btaggedjets();
 vector <pair<int, float>> jetscsv = sortedjetsbyCSV();
 
 if(jets.first.size()>1) seljets = jets.first;//two btags
 if(jets.first.size()==1 && jetscsv.size() > 0) { seljets.push_back(jets.first.at(0) ); seljets.push_back(jetscsv.at(0).first);} // one b tag
 if(jets.first.size()==0) { seljets = jets.second ; } // 0 btag, use two highest pt/why not csv?
 return seljets;
}

float leadjetpt() {
vector<int> selbjets_idx = selbjets();
float ptb1 = -999; if(selbjets_idx.size() > 0) ptb1 = ak4pfjets_p4().at(selbjets_idx.at(0)).pt();
return ptb1;
}

float subleadjetpt() {
vector<int> selbjets_idx = selbjets();
float ptb2 = -999; if(selbjets_idx.size() > 1) ptb2 = ak4pfjets_p4().at(selbjets_idx.at(1)).pt();
return ptb2;
}
float mbb(vector<int> selbjets_idx)
{
  if (selbjets_idx.size()<2)   return -999;
  float mbb = (ak4pfjets_p4().at(selbjets_idx.at(0))+ak4pfjets_p4().at(selbjets_idx.at(1))).mass(); 
  return mbb;
}

float ptbb(vector<int> selbjets_idx)
{
  if (selbjets_idx.size()<2)  return -999;
  float ptbb = (ak4pfjets_p4().at(selbjets_idx.at(0))+ak4pfjets_p4().at(selbjets_idx.at(1))).pt(); 
  return ptbb;
}

float mct(vector<int> selbjets_idx){
   if (selbjets_idx.size()<2)  return -999;
   float ptb1 = ak4pfjets_p4().at(selbjets_idx.at(0)).pt();
   float ptb2 = ak4pfjets_p4().at(selbjets_idx.at(1)).pt();
   float phib1 = ak4pfjets_p4().at(selbjets_idx.at(0)).phi();
   float phib2 = ak4pfjets_p4().at(selbjets_idx.at(1)).phi();
   float dPhibb = getdphi(phib1,phib2);
   float mct = sqrt(2*ptb1*ptb2*(1+cos(dPhibb)));
  return mct;
}

float dphibb(vector<int> selbjets_idx){
   if (selbjets_idx.size()<2)  return -999;
   float phib1 = ak4pfjets_p4().at(selbjets_idx.at(0)).phi();
   float phib2 = ak4pfjets_p4().at(selbjets_idx.at(1)).phi();
   float dPhibb = getdphi(phib1,phib2);
  return dPhibb;
}

float dRbb(vector<int> selbjets_idx){
   if (selbjets_idx.size()<2)  return -999;
   LorentzVector phib1 = ak4pfjets_p4().at(selbjets_idx.at(0));
   LorentzVector phib2 = ak4pfjets_p4().at(selbjets_idx.at(1));
   float dPhibb =  ROOT::Math::VectorUtil::DeltaR(phib1,phib2);
  return dPhibb;
}

float getdRbb()
{
 vector<int> bjets = selbjets(); if(bjets.size()<2) return -999; float mctbb = dRbb(bjets); return mctbb;
}
float getmct()
{
 vector<int> bjets = selbjets(); if(bjets.size()<2) return -999; float mctbb = mct(bjets); return mctbb;
}

float getmbb()
{
  vector<int> bjets = selbjets(); if(bjets.size()<2) return -999; float m_bb = mbb(bjets); return m_bb;
}

float getptbb()
{
  vector<int> bjets = selbjets(); if(bjets.size()<2) return -999; float m_bb = ptbb(bjets); return m_bb;
}
float getdphibb()
{
  vector<int> bjets = selbjets(); if(bjets.size()<2) return -999; float  dphi = dphibb(bjets); return dphi;
}

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

}//end of namespace
