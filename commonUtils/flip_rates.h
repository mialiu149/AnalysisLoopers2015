// obs/pred = 1.12586411131 +- 0.0250941720761
float flipRate(float pt, float eta) {
    float scale = 1.1259;
   if (pt>=15 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 3.1904e-05*scale;
   if (pt>=15 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000186291*scale;
   if (pt>=15 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00139741*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1.72654e-05*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000254101*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00193465*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 3.33916e-05*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000444596*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00276152*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 2.22283e-05*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000595391*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00423891*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 6.9003e-05*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000821344*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00440044*scale;
   if (pt>=200 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 7.02712e-06*scale;
   if (pt>=200 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000753121*scale;
   if (pt>=200 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00480737*scale;
   return 0.;
}
float flipRateError(float pt, float eta) {
    float scale = 1.1259;
   if (pt>=15 && pt<40 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 5.53873e-06*scale;
   if (pt>=15 && pt<40 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 1.72131e-05*scale;
   if (pt>=15 && pt<40 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 5.21526e-05*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 4.02809e-06*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 2.02022e-05*scale;
   if (pt>=40 && pt<60 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 6.82161e-05*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 1.50431e-05*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 7.74574e-05*scale;
   if (pt>=60 && pt<80 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.000238435*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 8.50748e-06*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000172241*scale;
   if (pt>=80 && pt<100 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.000709116*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 3.96222e-05*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000224086*scale;
   if (pt>=100 && pt<200 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.000667276*scale;
   if (pt>=200 && fabs(eta)>=0 && fabs(eta)<0.8 ) return 7.02842e-06*scale;
   if (pt>=200 && fabs(eta)>=0.8 && fabs(eta)<1.479 ) return 0.000519054*scale;
   if (pt>=200 && fabs(eta)>=1.479 && fabs(eta)<2.5 ) return 0.00265396*scale;
   return 0.;
}
