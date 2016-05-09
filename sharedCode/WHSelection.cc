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
#include "V00_00_05.h"

using namespace std;
using namespace V00_00_05_np; 

namespace whsel{

//--------------//
// preselection //
//--------------//

bool passPreselection(string selection) {
 //--------------------------//
 //--- trigger requirement---//
 //--------------------------//
 bool passTrigger =  HLT_SingleMu20()|| HLT_SingleEl27();
 if (TString(selection).Contains("FastSim") ) passTrigger = true; // fast sim doesn't have the right trigger information.
// int passOneLep = !(eventtype()!=1&&eventtype()!=2&&eventtype()!=3&&eventtype()!=5);
 bool passOneLep = (lep1type()==1);
 int passLepSel = !(eventtype()-5);

 if( !passTrigger) return false;
// if( !passOneLep)  return false; 
 if( !(lep1_relIso03EA()*lep1_pt() < 5)) return false;
 if( lep1type()!=1) return false; // lep1 is good lepton
 if( TString(selection).Contains("SR")){     //if SR, second lepton veto
 if( !passLepSel)             return false; //second lepton veto
 if( !PassTrackVeto_v3())     return false;  // ttrack veto
 if( !PassTauVeto())          return false; // tau veto
}
 // ttbar 1l selections
 if( TString(selection).Contains("ttbar1l")){
 if( !passOneLep)             return false; 
 if( !passLepSel)             return false; //second lepton veto
 if( ngoodbtags()<2)          return false;
 if( ngoodjets() < 4)                                              return false; // >=3 jets  
 if( pfmet() < 200)                                                return false; // min met cut.
 }
 if( pfmet() < 50)                                                 return false; // min met cut.
 if( ngoodjets() < 2)                                              return false; // >=2 jets  
// cutflow step cuts
 if( TString(selection).Contains("step0") && !passTrigger) return false;
 if( TString(selection).Contains("step1") && !passOneLep) return false; //if cutflow returns true
 if( TString(selection).Contains("step2") && !(passLepSel && passOneLep)) return false;
 if( TString(selection).Contains("step3") && !(PassTrackVeto_v3() && passLepSel && passOneLep))   return false; 
 if( TString(selection).Contains("step4") && !(PassTauVeto() && PassTrackVeto_v3() && passLepSel && passOneLep))   return false;
//event passed!
  return true;
}

//--------------//
//   2l CR      //
//--------------//
bool pass2lCR( string selection ) {
 if( !passPreselection(selection))                   return false;                                    // preselection with at least 1 lep+ met50 + >=2jets 
 if( ngoodbtags() != 2)                              return false;// btagged
 if( ngoodjets()  != 2)                              return false;// exactly 2 jets
  bool met_mt_cut = ( pfmet() > 50 && mt_met_lep() > 0 ); 
  if(TString(selection).Contains("mt120"))  met_mt_cut = ( pfmet() > 50 && mt_met_lep() > 120 );                                       // some additional requirement for CRs
  if(TString(selection).Contains("mt150"))  met_mt_cut = ( pfmet() > 50 && mt_met_lep() > 150 );                                       // some additional requirement for CRs
  bool pass2lCR =  met_mt_cut && ( lep2type() ==1 || lep2type() ==2 || !PassTrackVeto_v3()||!PassTauVeto());                      // fail track veto: 2l CR.
  //bool pass2lCR =  met_mt_cut && ((!PassTrackVeto_v3()||!PassTauVeto()) || eventtype()==1||eventtype() == 2 ||eventtype() == 3);                      // fail track veto: 2l CR.
  float m_bb = passmbb();
  float mctbb = passmct();
 // the following corresponds to SR bins.
 
 if( !pass2lCR)                                               return false; //pre selection + reverted veto

 if( TString(selection).Contains("mbb")) {if(m_bb>150||m_bb<90) return false;} //mbb cut  
 if( TString(selection).Contains("mct50"))  {if(mctbb<50)    return false;} // mct cuts
 if( TString(selection).Contains("mct100"))  {if(mctbb<100)    return false;} // mct cuts
 if( TString(selection).Contains("mct125"))  {if(mctbb<125)    return false;}
 if( TString(selection).Contains("mct150"))  {if(mctbb<150)    return false;}
 if( TString(selection).Contains("metbin1")) {if(pfmet()<100||pfmet()>200) return false;} //met cuts
 if( TString(selection).Contains("metbin2")) {if(pfmet()<200) return false;}
 if( TString(selection).Contains("met100")) {if(pfmet()<100) return false;} 
 if( TString(selection).Contains("met200")) {if(pfmet()<200) return false;}
 if( TString(selection).Contains("RegionA")) {if(mctbb<170||mt_met_lep()<150) return false; }// abcd regions
 if( TString(selection).Contains("RegionB")) {if(mctbb>170||mt_met_lep()<150) return false; }
 if( TString(selection).Contains("RegionC")) {if(mctbb<170||mt_met_lep()>150) return false; }
 if( TString(selection).Contains("RegionD")) {if(mctbb>170||mt_met_lep()>150) return false; }
 // event yields
 if( TString(selection).Contains("yield") ){
     if( TString(selection).Contains("metbin1")) { if(!(pfmet()>100 && pfmet()<200)) return false; }// 
     if( TString(selection).Contains("metbin2")) { if(!(pfmet()>200) ) return false; }// 
     if( TString(selection).Contains("mct50"))  { if(mctbb<50)  return false;}
     if( TString(selection).Contains("mct100")) { if(mctbb<100) return false;}
     if( TString(selection).Contains("mct125")) { if(mctbb<125) return false;}
     if( TString(selection).Contains("mct150")) { if(mctbb<150) return false;}
     if( TString(selection).Contains("mct170")) { if(mctbb<170) return false;}
 }
 return true;
}

bool passmbbCR(  string selection ) {

 if( !passPreselection(selection))                   return false;                                    // preselection with at least 1 lep+ met50 + >=2jets 
 if( ngoodbtags() != 2)                              return false;// btagged
 if( ngoodjets()  != 2)                              return false;// exactly 2 jets
 
  bool met_mt_cut = ( pfmet() > 50 && mt_met_lep() > 0 );                                               // some additional requirement for CRs
  bool pass1l =  met_mt_cut &&  lep2type() !=1&& lep2type() !=2 && PassTrackVeto_v3() && PassTauVeto();                      // pass 2nd lep veto etc.

  float m_bb = passmbb();
  float mctbb = passmct();
  bool outside_mbb = (m_bb>150||m_bb<90);
 // the following corresponds to SR bins.
 if( !pass1l || !outside_mbb)    return false;
 if( m_bb>90 && m_bb < 150)    { cout<<"outside mass window"<<endl; return false;}
 if( TString(selection).Contains("mct170") && mctbb < 170) return false; 
 if( TString(selection).Contains("yield") ){
     //if(  TString(selection).Contains("all")  && !(pfmet()>100)) return false;
     if( TString(selection).Contains("bin1")) { if(pfmet()>50 && pfmet()<100) return true; else return false; }// 
     if( TString(selection).Contains("bin2")) { if(pfmet()>100 && pfmet()<200) return true; else return false; }// 
     if( TString(selection).Contains("bin3"))  { if( pfmet()>200)  return true; else return false;} // 
 }
 return true;
}

//----------------------------------------//
//// regions for optimization studies     //
//----------------------------------------//
bool passStudyRegion( string selection) {
  float MET = pfmet();
  float METPhi = pfmet_phi();
  float METx = MET*TMath::Cos(METPhi);
  float METy = MET*TMath::Sin(METPhi);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
  metlv.SetPxPyPzE(METx,METy,0.,MET);
  //select b jets
  std::pair<vector<int>,vector<int>> alljets;
  alljets = btaggedjets(selection);
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
  if(TString(selection).Contains("met50")  && pfmet()   < 50)                      return false;
  if((pfmet()<50 || pfmet()>100) && TString(selection).Contains("met100"))                         return false; // change to exclusive binning
  //if(pfmet()<100 && TString(selection).Contains("met125"))                         return false;
  if((pfmet()<100 || pfmet()>200) && TString(selection).Contains("met150"))                         return false;
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

std::pair<vector<int>,vector<int>> btaggedjets(std::string selection)
{
 vector<int> bJets_idx;
 vector<int> nonbJets_idx;
 std::pair<vector<int>,vector<int>> jets;
 // add overlap removal
 for(int iJet=0; iJet<(int)ak4pfjets_p4().size(); iJet++){
            if( ak4pfjets_p4().at(iJet).Pt() > 30 &&
                fabs(ak4pfjets_p4().at(iJet).Eta()) < 2.4 
                && ak4pfjets_loose_pfid().at(iJet)
                )
                {if (ak4pfjets_CSV().at(iJet) >0.890) 
                   bJets_idx.push_back(iJet);
                else nonbJets_idx.push_back(iJet);}
 }
 jets = std::make_pair (bJets_idx,nonbJets_idx);
 return jets;
}

float mbb(vector<int> selbjets_idx)
{
  if (selbjets_idx.size()<2) {//cout<<"less than two b jets!"<<endl;
   return -999;}
  float mbb = (ak4pfjets_p4().at(selbjets_idx.at(0))+ak4pfjets_p4().at(selbjets_idx.at(1))).mass(); 
  return mbb;
}

float ptbb(vector<int> selbjets_idx)
{
  if (selbjets_idx.size()<2) {//cout<<"less than two b jets!"<<endl;
 return -999;}
  float ptbb = (ak4pfjets_p4().at(selbjets_idx.at(0))+ak4pfjets_p4().at(selbjets_idx.at(1))).pt(); 
  return ptbb;
}

float mct(vector<int> selbjets_idx){
   if (selbjets_idx.size()<2) {//cout<<"less than two b jets!"<<endl;
   return -999;}
   float ptb1 = ak4pfjets_p4().at(selbjets_idx.at(0)).pt();
   float ptb2 = ak4pfjets_p4().at(selbjets_idx.at(1)).pt();
   float phib1 = ak4pfjets_p4().at(selbjets_idx.at(0)).phi();
   float phib2 = ak4pfjets_p4().at(selbjets_idx.at(1)).phi();
   float dPhibb = getdphi(phib1,phib2);
   float mct = sqrt(2*ptb1*ptb2*(1+cos(dPhibb)));
   
   return mct;

}

float passmct()
{
  float MET = pfmet();
  float METPhi = pfmet_phi();
  float METx = MET*TMath::Cos(METPhi);
  float METy = MET*TMath::Sin(METPhi);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
  metlv.SetPxPyPzE(METx,METy,0.,MET);
  //select b jets
  std::pair<vector<int>,vector<int>> alljets;
  alljets = btaggedjets("default");
  vector<int> bjets = alljets.first;
  vector<int> addjets = alljets.second;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> bjetslv;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> addjetslv;
// return false;
  float m_bb = -999, mctbb = -999;
  if(bjets.size()==2){
  mctbb = mct(bjets);
  //ptlbb = 0;
  }
  if(bjets.size() < 2 && addjets.size() >=2 ) {
   mctbb = mct(addjets);
  }
  return mctbb;
}

float passmbb()
{
  float MET = pfmet();
  float METPhi = pfmet_phi();
  float METx = MET*TMath::Cos(METPhi);
  float METy = MET*TMath::Sin(METPhi);
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
  metlv.SetPxPyPzE(METx,METy,0.,MET);
  //select b jets
  std::pair<vector<int>,vector<int>> alljets;
  alljets = btaggedjets("default");
  vector<int> bjets = alljets.first;
  vector<int> addjets = alljets.second;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> bjetslv;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> addjetslv;
// return false;
  float m_bb = -999, mctbb = -999;
  if(bjets.size()==2){
   m_bb = mbb(bjets);
  }
  if(bjets.size() < 2 && addjets.size() >=2 ) {
   m_bb = mbb(addjets);
  }
return m_bb;
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
