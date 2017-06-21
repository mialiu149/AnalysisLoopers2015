#include "fastSimTriggerEff.h"

float electronScaleFactorFastSimHighHT(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9639;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.9437;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8006;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9425;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8360;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8031;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9327;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8292;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8172;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9297;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8216;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8285;
  if (pt >= 50  && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9288;
  if (pt >= 50  && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8474;
  if (pt >= 50  && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8438;
  return 0.;
}
float electronScaleFactorFastSimLowHT(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9640;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.9419;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.7957;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9451;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8386;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8038;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9336;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8330;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8209;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9304;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8203;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8269;
  if (pt >= 50  && fabs(eta) >= 0.000 && fabs(eta) < 1.442) return 0.9251;
  if (pt >= 50  && fabs(eta) >= 1.442 && fabs(eta) < 1.556) return 0.8407;
  if (pt >= 50  && fabs(eta) >= 1.556 && fabs(eta) < 2.500) return 0.8420;
  return 0.;
}
float muonScaleFactorFastSim(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9948;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9603;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9702;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 1.0693;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9888;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9736;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9739;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 1.0287;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9871;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9830;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9735;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 1.0983;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9901;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9957;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9765;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 1.1042;
  if (pt >= 50  && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9868;
  if (pt >= 50  && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9885;
  if (pt >= 50  && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9805;
  if (pt >= 50  && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 1.1391;
  return 0.;
}

float leptonScaleFactorFastSim(int pdgId, float pt, float eta, int nvtx, int ht) {
  if (abs(pdgId)==13) return muonScaleFactorFastSim(pt, eta);
  else if (abs(pdgId)==11){
    if (ht>300) return electronScaleFactorFastSimHighHT(pt, eta);
      else return electronScaleFactorFastSimLowHT(pt, eta);
  }
  return 0.;
}

float eventScaleFactorFastSim(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht, int nvtx) {
  return FastSimTriggerEfficiency(ht, pt1, pdgId1, pt2, pdgId2) * leptonScaleFactorFastSim(pdgId1, pt1, eta1, nvtx, ht) * leptonScaleFactorFastSim(pdgId2, pt2, eta2, nvtx, ht);
}
