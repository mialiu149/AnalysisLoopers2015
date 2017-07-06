/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.59233;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.379131;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.309078;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.076029;
   if (pt>=25 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.21303;
   if (pt>=25 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.210138;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.193258;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.062475;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158648;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.175735;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0951388;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.301407;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0789763;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.144318;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.209963;
   if (pt>=25 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.082156;
   if (pt>=25 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.159377;
   if (pt>=25 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.173652;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0622908;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0819141;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.124316;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0740672;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.152258;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0807695;
   return 0.;
}
//fo, iso<0.15
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.489992;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.134238;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.107627;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.189631;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0389218;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.176297;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.112086;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0272572;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0946562;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.15406;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0792135;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.20755;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.294693;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.391971;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.4779;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.346155;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.324877;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0874795;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.286549;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.37246;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.554929;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.378043;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.484683;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.339871;
   return 0.;
}
*/// tight_id, iso<0.4
/*   float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.991906;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.468175;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.516856;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.663377;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.894567;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.968867;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.759116;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.982067;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.900895;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0845591;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.159104;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.227015;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0713218;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0915571;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0378341;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0536187;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.113672;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.19114;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0789206;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.154227;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0943053;
   return 0.;
}
*/
// tight_id, iso<0.15
/*  float electronqcdmcfakeratewww(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.991906;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.468175;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.516856;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.663377;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.894567;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.968867;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.759116;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.982067;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.900895;
   return 0.;
}
float muonqcdmcfakeratewww(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.304269;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.397472;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.492373;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.346155;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.333522;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0981741;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.286549;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.390487;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.554929;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.394841;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.50521;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.428518;
   return 0.;
}
*/
// 65   passId = passes_VVV_cutbased_tight() && RelIso03EA() < 0.06;
//   66   passFO = passes_VVV_cutbased_fo_noiso() && RelIso03EA() < 0.15 || passes_VVV_cutbased_fo()&&abs(id()) == 11;
// fo_id, iso<0.15, tighter iso for electrons (~0.1)
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.523178;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165099;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.130078;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.227831;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0428034;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.205137;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.153698;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0385795;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.111747;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.175735;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0934327;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.271536;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.294693;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.391971;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.4779;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.346155;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.324877;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0874795;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.286549;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.37246;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.554929;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.378043;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.484683;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.339871;
   return 0.;
}
*/
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.171544;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0672457;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.259276;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0432936;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.123286;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0962575;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.323318;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.294693;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.391971;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.4779;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.346155;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.324877;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0874795;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.286549;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.37246;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.554929;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.378043;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.484683;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.339871;
   return 0.;
}
*/
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.171544;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0672457;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.259276;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0432936;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.123286;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0962575;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.323318;
   return 0.;
}

float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.203725;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.293184;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.380014;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.234421;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226048;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0610961;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.162091;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.267413;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.498316;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.209845;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.361253;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.187911;
   return 0.;
}
*/
//muiso 0.25
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.171544;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0672457;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.259276;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0432936;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.123286;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0962575;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.323318;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.157217;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.241995;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319833;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.146549;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.15714;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0513255;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.106311;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.203073;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.290523;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.134269;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.266166;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.160509;
   return 0.;
}*/
//mu 0.12
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.171544;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0672457;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.259276;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0432936;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.123286;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0962575;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.323318;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.408992;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.489889;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.560936;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.465096;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.42753;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.176494;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.320058;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.507216;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.715992;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.439042;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.52627;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.361036;
   return 0.;
}
*/
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.592248;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.422492;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.262558;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.101369;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.289834;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0446848;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.162407;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0980152;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.358885;
   return 0.;
}
*/
/*float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.152904;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.274802;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.328621;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.133225;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.161948;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.114959;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.158;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.193215;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.19114;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.13;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.241007;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.174553;
   return 0.;
}
*/
//doBonly
/*float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.130479;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.237508;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.2871;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.119819;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.128304;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0923918;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.13351;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.156353;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.192938;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0592843;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.212201;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.134468;
   return 0.;
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0692093;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.123234;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.188033;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0661948;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0789151;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0404145;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0594887;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.192938;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0228372;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.107518;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.00875163;
   return 0.;
}
}
//iso<0.4, doBonly
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0692093;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.123234;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.188033;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0661948;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0789151;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0404145;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0594887;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.192938;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0228372;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.107518;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.00875163;
   return 0.;
}
//iso<0.4 doall jets
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0822055;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.156463;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.22163;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0703129;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0902125;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0357508;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0529169;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.110199;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.19114;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0740672;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.152258;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0807695;
   return 0.;
}
//iso<0.2 doall jets
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.203725;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.293184;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.380014;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.234421;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226048;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0610961;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.162091;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.267413;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.498316;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.209845;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.361253;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.187911;
   return 0.;
}
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.171544;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313539;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0672457;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.259276;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203471;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0432936;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.123286;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178534;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0962575;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.323318;
   return 0.;
}
//doBonly, iso0.4

float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0692093;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.123234;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.188033;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0661948;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0789151;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0404145;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0594887;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.192938;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0228372;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.107518;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.00875163;
   return 0.;
}

float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.588959;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.197895;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.175161;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.313643;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0700661;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.247865;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.203834;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03958;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.143428;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.178235;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0949442;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.264702;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.12649;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.21324;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.295639;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0443511;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0670447;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0224964;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0320166;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0753019;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.111441;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0364605;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0742249;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0560326;
   return 0.;
}*/
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.444606;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.118224;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.108384;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0492844;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0191397;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.13265;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0913697;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0119287;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0611515;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.145386;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0448965;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.18343;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.115046;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.223674;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.317125;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0476632;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0614801;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0208778;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.034691;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0722105;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.107852;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0505523;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0747081;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0413671;
   return 0.;
}

