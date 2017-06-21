float triggerScaleFactor(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht) {
    // return TotalTriggerSF(pdgId1, pt1, eta1, pdgId2, pt2, eta2, ht);
    // Using Matthieu's macro, so dummy 1 here
    return 1.0; // FIXME


  if (ht>300) {
    if ((abs(pdgId1)+abs(pdgId2))==22) return 1.;
    if ((abs(pdgId1)+abs(pdgId2))==26) return 0.985*0.985;
    if ((abs(pdgId1)+abs(pdgId2))==24) return 0.985;
  } else {
    if ((abs(pdgId1)+abs(pdgId2))==22) return 0.997*0.997*0.998;
    if ((abs(pdgId1)+abs(pdgId2))==26) return 0.982*0.985*0.973;
    if ((abs(pdgId1)+abs(pdgId2))==24) {
      if (abs(pdgId1)==11) {
	if (pt1>pt2) return 0.997*0.985;
	else return 0.997*0.982;
      } else {
	if (pt1>pt2) return 0.997*0.982;
	else return 0.997*0.985;
      }
    }
  }
  return 0.;
}

float electronScaleFactorHighHT(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9158;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9820;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 1.0756;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9203;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 1.1124;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9177;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9499;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9710;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9370;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9904;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9210;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9472;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9927;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9443;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9785;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9213;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9515;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9830;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9480;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9628;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9212;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9483;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9845;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9480;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9483;
  if (pt >= 100  && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9469;
  if (pt >= 100  && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9429;
  if (pt >= 100  && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9932;
  if (pt >= 100  && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9455;
  if (pt >= 100  && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9592;
  return 0.;
}
float electronScaleFactorLowHT(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9149;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9768;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 1.0781;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9169;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 1.1100;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9170;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9497;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9687;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9356;
  if (pt >= 20 && pt < 30 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9894;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9208;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9483;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9923;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9438;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9781;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9202;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9514;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9827;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9480;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9627;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9207;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9481;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9848;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9480;
  if (pt >= 50 && pt < 100 && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9477;
  if (pt >= 100  && fabs(eta) >= 0.000 && fabs(eta) < 0.800) return 0.9472;
  if (pt >= 100  && fabs(eta) >= 0.800 && fabs(eta) < 1.442) return 0.9333;
  if (pt >= 100  && fabs(eta) >= 1.442 && fabs(eta) < 1.566) return 0.9934;
  if (pt >= 100  && fabs(eta) >= 1.566 && fabs(eta) < 2.000) return 0.9383;
  if (pt >= 100  && fabs(eta) >= 2.000 && fabs(eta) < 2.500) return 0.9597;
  return 0.;
}
float muonScaleFactor(float pt, float eta) {
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9047;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.8860;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.8916;
  if (pt >= 10 && pt < 20 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.8394;
  if (pt >= 20 && pt < 25 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9430;
  if (pt >= 20 && pt < 25 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9685;
  if (pt >= 20 && pt < 25 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9741;
  if (pt >= 20 && pt < 25 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.8917;
  if (pt >= 25 && pt < 30 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9707;
  if (pt >= 25 && pt < 30 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9724;
  if (pt >= 25 && pt < 30 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9777;
  if (pt >= 25 && pt < 30 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.9180;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9821;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9850;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9934;
  if (pt >= 30 && pt < 40 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.9389;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9854;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9861;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9968;
  if (pt >= 40 && pt < 50 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.9453;
  if (pt >= 50 && pt < 60 && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9813;
  if (pt >= 50 && pt < 60 && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9819;
  if (pt >= 50 && pt < 60 && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9964;
  if (pt >= 50 && pt < 60 && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.9410;
  if (pt >= 60  && fabs(eta) >= 0.000 && fabs(eta) < 0.900) return 0.9830;
  if (pt >= 60  && fabs(eta) >= 0.900 && fabs(eta) < 1.200) return 0.9861;
  if (pt >= 60  && fabs(eta) >= 1.200 && fabs(eta) < 2.100) return 0.9994;
  if (pt >= 60  && fabs(eta) >= 2.100 && fabs(eta) < 2.400) return 0.9525;
  return 0.;
}

float electronGSF(float pt, float eta) {
  if (pt >= 20  && eta >= -2.500 && eta < -2.400) return 1.1703;
  if (pt >= 20  && eta >= -2.400 && eta < -2.300) return 1.0085;
  if (pt >= 20  && eta >= -2.300 && eta < -2.200) return 1.0105;
  if (pt >= 20  && eta >= -2.200 && eta < -2.000) return 1.0052;
  if (pt >= 20  && eta >= -2.000 && eta < -1.800) return 0.9979;
  if (pt >= 20  && eta >= -1.800 && eta < -1.630) return 0.9917;
  if (pt >= 20  && eta >= -1.630 && eta < -1.566) return 0.9865;
  if (pt >= 20  && eta >= -1.566 && eta < -1.444) return 0.9616;
  if (pt >= 20  && eta >= -1.444 && eta < -1.200) return 0.9867;
  if (pt >= 20  && eta >= -1.200 && eta < -1.000) return 0.9775;
  if (pt >= 20  && eta >= -1.000 && eta < -0.600) return 0.9694;
  if (pt >= 20  && eta >= -0.600 && eta < -0.400) return 0.9664;
  if (pt >= 20  && eta >= -0.400 && eta < -0.200) return 0.9633;
  if (pt >= 20  && eta >= -0.200 && eta < 0.000) return 0.9600;
  if (pt >= 20  && eta >= 0.000 && eta < 0.200) return 0.9662;
  if (pt >= 20  && eta >= 0.200 && eta < 0.400) return 0.9796;
  if (pt >= 20  && eta >= 0.400 && eta < 0.600) return 0.9766;
  if (pt >= 20  && eta >= 0.600 && eta < 1.000) return 0.9807;
  if (pt >= 20  && eta >= 1.000 && eta < 1.200) return 0.9867;
  if (pt >= 20  && eta >= 1.200 && eta < 1.444) return 0.9867;
  if (pt >= 20  && eta >= 1.444 && eta < 1.566) return 0.9707;
  if (pt >= 20  && eta >= 1.566 && eta < 1.630) return 0.9897;
  if (pt >= 20  && eta >= 1.630 && eta < 1.800) return 0.9959;
  if (pt >= 20  && eta >= 1.800 && eta < 2.000) return 0.9897;
  if (pt >= 20  && eta >= 2.000 && eta < 2.200) return 0.9949;
  if (pt >= 20  && eta >= 2.200 && eta < 2.300) return 0.9928;
  if (pt >= 20  && eta >= 2.300 && eta < 2.400) return 0.9666;
  if (pt >= 20  && eta >= 2.400 && eta < 2.500) return 0.8840;
  return 0.;
}

float trackingSF(float eta) {
  if (eta >= -2.400 && eta < -2.100) return 0.9879;
  if (eta >= -2.100 && eta < -1.600) return 0.9939;
  if (eta >= -1.600 && eta < -1.100) return 0.9970;
  if (eta >= -1.100 && eta < -0.600) return 0.9954;
  if (eta >= -0.600 && eta <  0.000) return 0.9937;
  if (eta >=  0.000 && eta <  0.600) return 0.9959;
  if (eta >=  0.600 && eta <  1.100) return 0.9976;
  if (eta >=  1.100 && eta <  1.600) return 0.9961;
  if (eta >=  1.600 && eta <  2.100) return 0.9930;
  if (eta >=  2.100 && eta <  2.400) return 0.9819;
  return 1.0;
}

float leptonScaleFactor(int pdgId, float pt, float eta, float ht) {
  if (abs(pdgId)==13) return muonScaleFactor(pt, eta)*trackingSF(eta);
  else if (abs(pdgId)==11){
    if (ht>300) return electronScaleFactorHighHT(pt, eta)*electronGSF(pt, eta);
      else return electronScaleFactorLowHT(pt, eta)*electronGSF(pt, eta);
  }
  return 0.;
}

float eventScaleFactor(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht) {
  return triggerScaleFactor(pdgId1, pdgId2, pt1, pt2, eta1, eta2, ht) * leptonScaleFactor(pdgId1, pt1, eta1, ht) * leptonScaleFactor(pdgId2, pt2, eta2, ht);
}
