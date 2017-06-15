#ifndef TOOLS_H
#define TOOLS_H
#include "TMath.h"

inline float deltaPhi( float phi1 , float phi2 ) {
  float dphi = fabs( phi1 - phi2 );
  if( dphi > TMath::Pi() ) dphi = TMath::TwoPi() - dphi;
  return dphi;
}

inline float deltaR( LorentzVector lv1, LorentzVector lv2 ) {
  return sqrt( pow(deltaPhi(lv1.phi(),lv2.phi()),2) + pow(lv1.eta()-lv2.eta(),2) );
}

inline float mt(float pt1, float pt2, float dphi){
  return 2*sqrt(pt1*pt2)*fabs(sin(dphi/2));
}

inline float calculateMt(float pt1, float pt2, float dphi){
  return 2*sqrt(pt1*pt2)*fabs(sin(dphi/2));
}

#endif
