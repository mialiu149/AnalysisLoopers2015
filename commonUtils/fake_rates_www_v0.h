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
