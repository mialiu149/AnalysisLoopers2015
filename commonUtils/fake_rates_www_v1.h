/*float electronqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.217206;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.193411;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.345574;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.101778;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.190289;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.167549;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.112191;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.189283;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.188359;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.054282;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0149329;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.209257;
   return 0.;
}
float muonqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0933023;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.17767;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.273373;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0458426;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0522414;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.028657;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0341787;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.136061;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0161925;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0520545;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.00419796;
   return 0.;
} */
/*float electronqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219323;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.184194;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.34185;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.103975;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.187725;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.183251;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.113568;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.198051;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.188444;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0549355;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0151401;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.214096;
   return 0.;
}
float muonqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0957453;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.183525;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.278973;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0469195;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0522495;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0292294;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0348813;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.147102;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0172289;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0535411;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.00464331;
   return 0.;
}
*/
//v1
/*float electronqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.216693;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.161483;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.263455;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.10308;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.152964;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.136479;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.110937;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.166022;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.1315;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.107835;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0319542;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0942394;
   return 0.;
}

float muonqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.115294;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226115;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319202;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0479081;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0609928;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0207256;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0342282;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0701455;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.105519;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0494491;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0742306;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0413671;
   return 0.;
}
*/
//v2
/*float electronqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.107199;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.163377;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.16809;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120903;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.182406;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.169261;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonqcdmcfakeratewww(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.115294;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226115;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319202;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0479081;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0609928;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0207256;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0342282;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0701455;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.105519;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0494491;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0742306;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0413671;
   return 0.;
} */

//v3
/*
 float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.227077;
   if (pt>=10 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.174303;
   if (pt>=10 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.331301;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.109844;
   if (pt>=30 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.172145;
   if (pt>=30 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.198319;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.124432;
   if (pt>=40 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.188955;
   if (pt>=40 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.205542;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.121996;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0398586;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.149896;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.118517;
   if (pt>=10 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.231281;
   if (pt>=10 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.325995;
   if (pt>=30 && pt<40 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0489688;
   if (pt>=30 && pt<40 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0611782;
   if (pt>=30 && pt<40 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0215312;
   if (pt>=40 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0349086;
   if (pt>=40 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0715834;
   if (pt>=40 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.112041;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0515744;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.076068;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0446494;
   return 0.;
} 
*/

//v4
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.234027;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.175835;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.348557;
   if (pt>=30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.119132;
   if (pt>=30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.175419;
   if (pt>=30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.207151;
   return 0.;
}
*/
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.218942;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.163935;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.342658;
   if (pt>=30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.102646;
   if (pt>=30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.155105;
   if (pt>=30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.197585;
   return 0.;
}
*/
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.241871;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.18303;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.373141;
   if (pt>=30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120873;
   if (pt>=30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.181962;
   if (pt>=30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.233958;
   return 0.;
}
*/
// good closure
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.216693;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.161483;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.263455;
   if (pt>=30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.104912;
   if (pt>=30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.155568;
   if (pt>=30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.135367;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0938087;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.169496;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.263914;
   if (pt>=30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.033076;
   if (pt>=30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0424406;
   if (pt>=30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0290088;
   return 0.;
}
*/
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.216693;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.161483;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.263455;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.104912;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.155568;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.135367;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.107835;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0319542;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0942394;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0938087;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.169496;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.263914;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.033076;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0424406;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0290088;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0366784;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0547788;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0342481;
   return 0.;
}
*/
//from philip
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.362264;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.388726;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.35197;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.225732;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.279512;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.309488;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.391862;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.209323;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.286257;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.299681;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.09479;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.361186;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.169276;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0148702;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.395652;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0940482;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.195929;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.190965;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.261048;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.101737;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.117012;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.191488;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.24993;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.322426;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0793026;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.12205;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.139782;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0535586;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0801295;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0869191;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0384728;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0876996;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.110241;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.056529;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0502592;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0338163;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0349646;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0535613;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0226673;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0239315;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0426106;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0452296;
   return 0.;
} */



//v1
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.216693;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.161483;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.263455;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.104912;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.155568;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.135367;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.107835;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0319542;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0942394;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.115294;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226115;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319202;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0443245;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0635889;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0394132;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0494491;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0742306;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0413671;
   return 0.;
} 
*/
// v2
/*float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.115294;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.226115;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319202;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0443245;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0635889;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0394132;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0494491;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0742306;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0413671;
   return 0.;
} 
*/
//v3
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0938087;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.169496;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.263914;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.033076;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0424406;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0290088;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0366784;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0547788;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0342481;
   return 0.;
}
*/
//v4
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0938087;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.169496;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.263914;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.033076;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0424406;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0290088;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0366784;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0547788;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0342481;
   return 0.;
}
*/
//v4 and <0.2
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.208277;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.274902;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.371703;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.122937;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.120677;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0813611;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.133251;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.184653;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.108995;
   return 0.;
}
*/
///v5
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.112286;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.218484;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.319799;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0424834;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0621551;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0407488;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.049517;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0711963;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0443772;
   return 0.;
}*/
/*
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.258034;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.362726;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.460509;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.172512;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.186391;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.105723;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.176379;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.243371;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.138903;
   return 0.;
}
*/
float electronQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.219081;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.165657;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.297851;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.11028;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.167086;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.168343;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.120869;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.03952;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.131341;
   return 0.;
}
float muonQCDMCFakeRateWWW(float pt, float eta) {
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.248538;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.356143;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.452374;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.169506;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.183393;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0980501;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.173042;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.238505;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.128074;
   return 0.;
}

float electronQCDMCFakeRate_v1_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.242555;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.336866;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.192523;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0283987;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.213894;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.282605;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.47633;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.179272;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.164202;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.366328;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0413917;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.292951;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.166088;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000785375;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.291011;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0886157;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.164163;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.12589;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.267221;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0983943;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0766051;
   return 0.;
}
float muonQCDMCFakeRate_v1_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.225108;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.295867;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.341478;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0925563;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.149588;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.151889;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0628802;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.101283;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0995832;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0463942;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.117547;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.131193;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0668561;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0652584;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0394252;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0433598;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0659743;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0281283;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.031655;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.056932;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0508411;
   return 0.;
}
float electronQCDMCFakeRate_v2_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.242674;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.336626;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.193809;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0272939;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.451726;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.286423;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.47633;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.179455;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.184202;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36706;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0395203;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.325702;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.166908;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00078625;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.38734;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0892066;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.15568;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158843;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.207506;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0918021;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0837233;
   return 0.;
}
float muonQCDMCFakeRate_v2_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.225088;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.295904;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.341478;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0925559;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.149588;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.151889;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0628802;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.101283;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0995832;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0463942;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.117547;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.131193;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0668561;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0652584;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0394252;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0433598;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0659743;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0281283;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.031655;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.056932;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0508411;
   return 0.;
}

float electronQCDMCFakeRate_v3_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.242674;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.336626;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.193809;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0272939;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.451726;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.286543;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.47633;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.179455;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.184202;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36706;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0395203;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.325756;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.16668;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00078625;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.38734;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0892066;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.15568;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158843;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.207506;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0918266;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0837233;
   return 0.;
}
float muonQCDMCFakeRate_v3_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.189305;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.248226;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.316341;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0768258;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.120103;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.12949;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0518964;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0790828;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0809892;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0373997;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0864491;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.104695;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0544853;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0491095;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0307922;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.034245;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0526552;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0210227;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0232764;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0417332;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0409277;
   return 0.;
}

float electronQCDMCFakeRate_v4_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.242674;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.336626;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.193809;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0272939;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.451726;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.286543;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.47633;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.179455;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.184202;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36706;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0395203;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.325756;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.16668;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00078625;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.38734;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0892066;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.15568;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158843;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.207506;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0918266;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0837233;
   return 0.;
}
float muonQCDMCFakeRate_v4_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.189308;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.24829;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.316356;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0768276;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.120114;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.129602;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0519235;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0791734;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0822743;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0374023;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0864758;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.105095;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0544853;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0492785;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0308787;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.034245;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0526878;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0211372;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0232764;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0418115;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0418333;
   return 0.;
}

float electronQCDMCFakeRate_v5_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.242674;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.336626;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.193809;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0272939;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.451726;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.286423;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.47633;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.179455;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.184202;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36706;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0395203;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.325702;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.166908;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00078625;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.38734;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0892066;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.15568;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.158843;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.207506;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0918021;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0837233;
   return 0.;
}
float muonQCDMCFakeRate_v5_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.231049;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.300869;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.356083;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.094671;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.15128;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.157534;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0646616;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.101954;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.101973;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0473911;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.117781;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.133766;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0685411;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.065473;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0410585;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0441118;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0669387;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0284621;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0323729;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0575213;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0527099;
   return 0.;
}

float electronQCDMCFakeRate_v6_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.28746;
   if (pt>=10 && pt<15 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.383604;
   if (pt>=10 && pt<15 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.198623;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0272993;
   if (pt>=15 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.451726;
   if (pt>=15 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.293595;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.489658;
   if (pt>=20 && pt<25 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.18611;
   if (pt>=20 && pt<25 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.187621;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.36706;
   if (pt>=25 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0395586;
   if (pt>=25 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.336628;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.166908;
   if (pt>=30 && pt<35 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00078644;
   if (pt>=30 && pt<35 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.39691;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0892066;
   if (pt>=35 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.158085;
   if (pt>=35 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.146202;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.209425;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0881274;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0921099;
   return 0.;
}
float muonQCDMCFakeRate_v6_WWW(float pt, float eta) {
   if (pt>=10 && pt<15 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.352148;
   if (pt>=10 && pt<15 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.432396;
   if (pt>=10 && pt<15 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.464472;
   if (pt>=15 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.257234;
   if (pt>=15 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.329833;
   if (pt>=15 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.337688;
   if (pt>=20 && pt<25 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.200216;
   if (pt>=20 && pt<25 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.241441;
   if (pt>=20 && pt<25 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.234156;
   if (pt>=25 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.18846;
   if (pt>=25 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.298851;
   if (pt>=25 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.359944;
   if (pt>=30 && pt<35 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.257848;
   if (pt>=30 && pt<35 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.209254;
   if (pt>=30 && pt<35 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.12702;
   if (pt>=35 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.20049;
   if (pt>=35 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.229479;
   if (pt>=35 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0944669;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.183022;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.218869;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.129928;
   return 0.;
}

float electronQCDMCFakeRate_20170911_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.251111;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.261666;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.302791;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.195776;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.191887;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.217486;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.169051;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.164039;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.1736;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.199399;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.101855;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.170493;
   return 0.;
}
float electronQCDMCFakeRateError_20170911_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.018014;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0196728;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0248089;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0282233;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0232803;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0248149;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0207381;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0213855;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.014733;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0770095;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0601733;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0370097;
   return 0.;
}
float muonQCDMCFakeRate_20170911_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.184524;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.221222;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.281988;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.054216;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0866916;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.12044;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0459721;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0727306;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.105424;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0760604;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0229585;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0229585;
   return 0.;
}
float muonQCDMCFakeRateError_20170911_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00604681;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00897252;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0222317;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00640781;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0093254;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0282658;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00482489;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00683751;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0156435;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0334087;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0417386;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0417386;
   return 0.;
}
float electronFakeRate_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.180863;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.151654;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.166857;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.13346;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.108987;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.127049;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.115078;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0997162;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.106396;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0793936;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.079424;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0995945;
   return 0.;
}
float electronFakeRateError_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0117806;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00866844;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00867508;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0146961;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0112594;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0116392;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0116122;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.00995091;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00678264;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0340196;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0289512;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0122391;
   return 0.;
}
float muonFakeRate_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.181629;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.228556;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.284502;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.059308;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0812574;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.120472;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0502797;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0755524;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.102111;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0504603;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.06998;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.06998;
   return 0.;
}
float muonFakeRateError_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00419139;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00643408;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0138531;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00429932;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00690134;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0154601;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00337692;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.004541;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0116372;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0223031;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0249675;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0249675;
   return 0.;
}
float electronFakeRate_qcd_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.230089;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.187919;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.181326;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.17306;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.127839;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.106022;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0515026;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.141964;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0987933;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0854687;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.10156;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0892399;
   return 0.;
}
float electronFakeRateError_qcd_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0136355;
   if (pt>=10 && pt<20 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0301967;
   if (pt>=10 && pt<20 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0229038;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0540544;
   if (pt>=20 && pt<30 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0578527;
   if (pt>=20 && pt<30 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0311611;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0163129;
   if (pt>=30 && pt<50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.070563;
   if (pt>=30 && pt<50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0221528;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 0.0367682;
   if (pt>=50 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.0386389;
   if (pt>=50 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.0199718;
   return 0.;
}
float muonFakeRate_qcd_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.192454;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.252128;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.299959;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0592033;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.109371;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.124618;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.045541;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0673591;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0674571;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.0317323;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0554221;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0583592;
   return 0.;
}
float muonFakeRateError_qcd_WWW(float pt, float eta) {
   if (pt>=10 && pt<20 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00435652;
   if (pt>=10 && pt<20 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00673523;
   if (pt>=10 && pt<20 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0139497;
   if (pt>=20 && pt<30 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00397246;
   if (pt>=20 && pt<30 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00733365;
   if (pt>=20 && pt<30 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0126553;
   if (pt>=30 && pt<50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00546544;
   if (pt>=30 && pt<50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.00792283;
   if (pt>=30 && pt<50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0151419;
   if (pt>=50 && fabs(eta)>=0 && fabs(eta)<1.2 ) return 0.00831419;
   if (pt>=50 && fabs(eta)>=1.2 && fabs(eta)<2.1 ) return 0.0171941;
   if (pt>=50 && fabs(eta)>=2.1 && fabs(eta)<2.4 ) return 0.0227116;
   return 0.;
}

