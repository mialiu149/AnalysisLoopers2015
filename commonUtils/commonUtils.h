#ifndef _commonUtils_h_
#define _commonUtils_h_

// // 0.8
// float getLumi() { return 0.8042; }
// float getLumiUnblind() { return 0.8042; }
// bool isUnblindRun(int run) { return run <= 274240; }
// float getWZSF() { return 0.85; }
// TString getTag() { return "v8.02"; } // up to the 3.99/fb json
// #include "flip_rates.h"


// // 2.6
// float getLumi() { return 2.6; }
// float getLumiUnblind() { return 2.6; }
// bool isUnblindRun(int run) { return run <= 274442; }
// float getWZSF() { return 0.85; } 
// TString getTag() { return "v8.02"; } // up to the 3.99/fb json
// #include "flip_rates.h"

// // 3.99
// float getLumi() { return 3.99; }
// float getLumiUnblind() { return 3.99; }
// bool isUnblindRun(int run) { return run <= 275125; }
// float getWZSF() { return 1.021; } // 4/fb
// TString getTag() { return "v8.02"; } // up to the 3.99/fb json
// #include "flip_rates.h"

// // 6.26
// float getLumi() { return 6.26; }
// float getLumiUnblind() { return 6.26; }
// bool isUnblindRun(int run) { return run <= 275782; }
// float getWZSF() { return 0.948; }
// TString getTag() { return "v8.03"; } // up to the 6.26/fb json
// #include "flip_rates_6p26ifb.h"
// #include "fake_rates.h"

// // 12.9 - ICHEP
// float getLumi() { return 12.9; }
// float getLumiUnblind() { return 12.9; }
// bool isUnblindRun(int run) { return true; }
// float getWZSF() { return 0.948; } // 0.948 pm 0.210
// float getttZSF() { return 1.0; }
// TString getTag() { return "v8.04"; }
// TString getTagData() { return "v8.04"; }
// #include "flip_rates.h"
// #include "fake_rates.h"
// #include "fake_rates_insitu.h"

// // 2nd HALF of ICHEP dataset
// float getLumi() { return 12.9-6.26; }
// float getLumiUnblind() { return 12.9-6.26; }
// bool isUnblindRun(int run) { return run > 275782; }
// float getWZSF() { return 0.948; } // 0.948 pm 0.210
// TString getTag() { return "v8.04"; }
// #include "flip_rates_12p9ifb.h"
// #include "fake_rates_2ndhalf.h"

// // 22.0
// float getLumi() { return 22.0; }
// float getLumiUnblind() { return 22.0; }
// bool isUnblindRun(int run) { return true; }
// float getWZSF() { return 0.948; } // 0.948 pm 0.210
// TString getTag() { return "v8.04"; }
// TString getTagData() { return "v8.05"; }
// #include "flip_rates.h"
// #include "fake_rates.h"
// #include "fake_rates_insitu_mva.h"

// // 27.2
// float getLumi() { return 27.2; }
// float getLumiUnblind() { return 12.9+4.4; }
// bool isUnblindRun(int run) { return ((run<=276811) || ((run<=279931) && (run>=278820))) && ( (run!=279658) && (run!=279658) && (run!=279667) && (run!=279681) && (run!=279682) && (run!=279682) && (run!=279682) && (run!=279683) && (run!=279684) && (run!=279685) && (run!=279685) && (run!=279691) && (run!=279694) ); } // 276811 for end of ICHEP (12.9/fb), or 278820-279931 for beyond ICHEP studies (+4.4/fb)
// float getWZSF() { return 0.948; } // 0.948 pm 0.210
// float getttZSF() { return 1.0; }
// TString getTag() { return "v8.04"; }
// TString getTagData() { return "v8.05"; }
// #include "flip_rates.h"
// // #include "fake_rates_22p0ifb.h"
// #include "fake_rates.h"
// #include "fake_rates_insitu_22p0ifb.h"
// // #include "fake_rates_insitu.h"
// // #include "fake_rates_insitu_mva_soup.h"

// 36.46 / 36.814 (post-normtag update)
// float getLumi() { return 36.46; }
// float getLumiUnblind() { return 36.46; }
// float getLumi() { return 36.814; }
// float getLumiUnblind() { return 36.814; }
float getLumi() { return 35.87; } // FIXME FIXME FIXME
float getLumiUnblind() { return 35.87; } // FIXME FIXME FIXME
bool isUnblindRun(int run) { return true; }
// float getLumiUnblind() { return 12.9+4.4; }
// bool isUnblindRun(int run) { 
//     return ((run<=276811) || ((run<=279931) && (run>=278820)))
//         && ( (run!=279658) && (run!=279658) && (run!=279667) 
//                 && (run!=279681) && (run!=279682) 
//                 && (run!=279682) && (run!=279682) 
//                 && (run!=279683) && (run!=279684) 
//                 && (run!=279685) && (run!=279685) 
//                 && (run!=279691) && (run!=279694) ); } // 276811 for end of ICHEP (12.9/fb), or 278820-279931 for beyond ICHEP studies (+4.4/fb)
float getWZSF() { return 1.23; } // pm 0.12
float getttZSF() { return 1.14; } // pm 0.30
TString getTag() { return "v8.07"; }
TString getTagData() { return "v8.07"; }
#include "flip_rates_36p5ifb.h"
// #include "fake_rates_22p0ifb.h"
// #include "fake_rates.h"
#if USE_SPECIFIC_FR>0
#include "fake_rates_22p0ifb.h"
#else
#include "fake_rates_36p5ifb.h"
// #include "fake_rates_moriond.h"
// #include "fake_rates_nonenriched.h"
#endif
// #include "fake_rates_insitu_22p0ifb.h"
#include "fake_rates_insitu_mva_soup.h"
// #include "fake_rates_insitu_soup_moriond.h"
// #include "fake_rates_insitu_36p8ifb.h"
// #include "fake_rates_insitu_mva_soup_moriond.h"
// #include "inSituFR/prompt.h"
// #include "inSituFR/test_isfr_mcsoup_mva.h"
// #include "inSituFR/mc_test_4.h"
// #include "fake_rates_insitu.h"
// #include "fake_rates_insitu_mva_soup.h"
#include "fake_rates_www_v1.h"
bool applyThirdLeptonVeto() { return false; }


#include "../hlt/HLTEfficiency.cc"

#include "LaurentSFs_debug.h"
#include "LaurentSFs_fastsim.h"

#include "pu_weights.h"
// #include "flip_rates.h"
// #include "fake_rates.h"
#include "fake_rates_noCC.h"

// #if USE_OLD_LEPSF>0

// #include "lepton_sf.h"
// #include "lepton_sf_fastsim.h"

// #elif USE_TEST_LEPSF>0

// #include "lepton_sf_moriond_test.h"
// #include "lepton_sf_fastsim_moriond.h"

// #elif USE_RA7_MORIOND_LEPSF>0

// #include "lepton_sf_moriond_ra7.h"
// #include "lepton_sf_fastsim_moriond.h"

// #else


#include "lepton_sf_moriond.h"
#include "lepton_sf_fastsim_moriond.h"

// #endif

// #include "fake_rates_insitu_22p0ifb.h"
// #include "fake_rates_insitu.h"
// #include "fake_rates_insitu_siplt4.h"
// #include "fake_rates_insitu_miniisolt4.h"
// #include "fake_rates_insitu_soup.h"
// #include "fake_rates_insitu_wjets.h"
// #include "fake_rates_insitu_mva_soup.h"
// #include "fake_rates_insitu_mva.h"



float fakeRate(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronFakeRate(pt,eta);
    else if (abs(id)==13) return muonFakeRate(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonFakeRate_IsoTrigs(pt,eta);
    else return 0.;
  }
}

float fakeRateError(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronFakeRateError(pt,eta);
    else if (abs(id)==13) return muonFakeRateError(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronFakeRateError_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonFakeRateError_IsoTrigs(pt,eta);
    else return 0.;
  }
}

float alternativeFakeRate(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronAlternativeFakeRate(pt,eta);
    else if (abs(id)==13) return muonAlternativeFakeRate(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronAlternativeFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonAlternativeFakeRate_IsoTrigs(pt,eta);
    else return 0.;
  }
}

float qcdMCFakeRate(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronQCDMCFakeRate(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRate(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronQCDMCFakeRate_IsoTrigs(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRate_IsoTrigs(pt,eta);
    else return 0.;
    //else {cout<<"pt:"<<pt<<":eta:"<<eta<<endl;return 0.;}
  }
}

float fakeRateInSitu(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
      if (abs(id)==11) return elecFakeRateInSituHighHT(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSituHighHT(pt,eta);
      else return 0.;
  } else if(ht > 0) {
      if (abs(id)==11) return elecFakeRateInSitu(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSitu(pt,eta);
      else return 0.;
  } else { // negative ht means inclusive
      if (abs(id)==11) return elecFakeRateInSituAllHT(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSituAllHT(pt,eta);
      else return 0.;
  }
}

float fakeRateErrorInSitu(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
      if (abs(id)==11) return elecFakeRateInSituErrorHighHT(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSituErrorHighHT(pt,eta);
      else return 0.;
  } else if(ht > 0) {
      if (abs(id)==11) return elecFakeRateInSituError(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSituError(pt,eta);
      else return 0.;
  } else { // negative ht means inclusive
      if (abs(id)==11) return elecFakeRateInSituErrorAllHT(pt,eta);
      else if (abs(id)==13) return muonFakeRateInSituErrorAllHT(pt,eta);
      else return 0.;
  }
}

// returns A if pt<ptmin, B if pt>ptmax, and linear interpolation between. if pt<10, use C
float mvacut(float A, float B, float C, float pt_) {
    float ptmin = 15;
    float ptmax = 25;
    return pt_>10 ? std::min(A, std::max(B,A + (B-A)/(ptmax-ptmin)*(pt_-ptmin))) : C; 
}

bool passIsolatedFO(int id, float eta, float disc, float pt) {
  if (abs(id)==13) return true;
  float aeta = fabs(eta);
  // if (aeta < 0.8) return mva > -0.155;
  // if ((aeta >= 0.8 && aeta <= 1.479)) return mva > -0.56;
  // if (aeta > 1.479) return mva > -0.76;
    if (aeta < 0.8) return disc > mvacut(-0.86,-0.96,-0.3,pt);
    if ((aeta >= 0.8 && aeta <= 1.479)) return disc > mvacut(-0.85,-0.96,-0.36,pt);
    if (aeta > 1.479) return disc > mvacut(-0.81,-0.95,-0.63,pt);
  return false;
}

bool passesNumeratorMVA(int id, float eta, float disc, float pt){
  if (abs(id) != 11) return true;
  float aeta = fabs(eta);
  // if (aeta < 0.8) return disc > 0.87;
  // if ((aeta >= 0.8 && aeta <= 1.479)) return disc > 0.60;
  // if (aeta > 1.479) return disc > 0.17;
  if (aeta < 0.8) return disc > mvacut(0.77,0.52,0.77,pt);
  if ((aeta >= 0.8 && aeta <= 1.479)) return disc > mvacut(0.56,0.11,0.56,pt);
  if (aeta > 1.479) return disc > mvacut(0.48,-0.01,0.48,pt);
  return false;
}

float fakeRateNoCC(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronFakeRateNoCC(pt,eta);
    else if (abs(id)==13) return muonFakeRateNoCC(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronFakeRate_IsoTrigsNoCC(pt,eta);
    else if (abs(id)==13) return muonFakeRate_IsoTrigsNoCC(pt,eta);
    else return 0.;
  }
}

float fakeRateErrorNoCC(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronFakeRateErrorNoCC(pt,eta);
    else if (abs(id)==13) return muonFakeRateErrorNoCC(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronFakeRateError_IsoTrigsNoCC(pt,eta);
    else if (abs(id)==13) return muonFakeRateError_IsoTrigsNoCC(pt,eta);
    else return 0.;
  }
}

float qcdMCFakeRateWWW(int id, float pt, float eta, float ht, TString version = "default") { 
    if (abs(id)==11) {
        if(version.Contains("v1")) return electronQCDMCFakeRate_v1_WWW(pt,eta);
        else if(version.Contains("v2")) return electronQCDMCFakeRate_v2_WWW(pt,eta);
        else if(version.Contains("v3")) return electronQCDMCFakeRate_v3_WWW(pt,eta);
        else if(version.Contains("v4")) return electronQCDMCFakeRate_v4_WWW(pt,eta);
        else if(version.Contains("v5")) return electronQCDMCFakeRate_v5_WWW(pt,eta);
        else if(version.Contains("v6")) return electronQCDMCFakeRate_v6_WWW(pt,eta);
        //else if(version.Contains("default")) return electronQCDMCFakeRate_v5_WWW(pt,eta);
        else if(version.Contains("default")) return electronQCDMCFakeRate_20170911_WWW(pt,eta);
        else {cout<<"using default fake rate"<<endl;return electronQCDMCFakeRateWWW(pt,eta);}
 }   else if (abs(id)==13) {
        if(version.Contains("v1")) return muonQCDMCFakeRate_v1_WWW(pt,eta);
        else if(version.Contains("v2")) return muonQCDMCFakeRate_v2_WWW(pt,eta);
        else if(version.Contains("v3")) return muonQCDMCFakeRate_v3_WWW(pt,eta);
        else if(version.Contains("v4")) return muonQCDMCFakeRate_v4_WWW(pt,eta);
        else if(version.Contains("v5")) return muonQCDMCFakeRate_v5_WWW(pt,eta);
        else if(version.Contains("v6")) return muonQCDMCFakeRate_v6_WWW(pt,eta);
        //else if(version.Contains("default")) return muonQCDMCFakeRate_v5_WWW(pt,eta);
        else if(version.Contains("default")) return muonQCDMCFakeRate_20170911_WWW(pt,eta);
        else {cout<<version<<":using default fake rate"<<endl;return muonQCDMCFakeRateWWW(pt,eta);}
//        else return muonQCDMCFakeRateWWW(pt,eta);
}
    else return 0.;
}

float FakeRateErrorWWW(int id, float pt, float eta, float ht, TString version = "default") { 
    if (abs(id)==11) {
        //else if(version.Contains("default")) return electronQCDMCFakeRateError_v5_WWW(pt,eta);
        if(version.Contains("default")) return electronQCDMCFakeRateError_20170911_WWW(pt,eta);
         else return 0.;
 }   else if (abs(id)==13) {
        //else if(version.Contains("default")) return muonQCDMCFakeRateError_v5_WWW(pt,eta);
        if(version.Contains("default")) return muonQCDMCFakeRateError_20170911_WWW(pt,eta);
         else return 0.;
//        else return muonQCDMCFakeRateErrorWWW(pt,eta);
}
    else return 0.;
}

float qcdMCFakeRateNoCC(int id, float pt, float eta, float ht) { 
  if (ht>300.) {
    if (abs(id)==11) return electronQCDMCFakeRateNoCC(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRateNoCC(pt,eta);
    else return 0.;
  } else {
    if (abs(id)==11) return electronQCDMCFakeRate_IsoTrigsNoCC(pt,eta);
    else if (abs(id)==13) return muonQCDMCFakeRate_IsoTrigsNoCC(pt,eta);
    else return 0.;
  }
}

float getFakeRate(int id, float pt, float eta, float ht, bool extrPtRel = false, bool doData = false, bool doInSitu = false, TString version = "default"){
    //if (inclHT) ht = -1; // negative ht means use inclusive ht in commonUtils // FIXME

    if (doInSitu) return fakeRateInSitu(id, pt, eta, ht);
    else if (doData ) return fakeRate(id, pt, eta, ht);
    else return qcdMCFakeRateWWW(id, pt, eta, ht, version);
}

float getFakeRateError(int id, float pt, float eta, float ht, bool doInSitu = false) { 
    if (doInSitu) return fakeRateErrorInSitu(id, pt, eta, ht);
    else return FakeRateErrorWWW(id, pt, eta, ht);
}

float getFakeRate2(int id, float pt, float eta, float ht, bool extrPtRel = false, bool doData = false){
  if (doData) return fakeRateNoCC(id, pt, eta, ht);
  else return qcdMCFakeRateWWW(id, pt, eta, ht);
}

#endif
