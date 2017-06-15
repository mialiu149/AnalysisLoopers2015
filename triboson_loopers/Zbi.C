#include "TFile.h"
#include "TH1F.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TString.h"
#include "TMath.h"

using namespace std;

float Zbi(float sig, float bg, float bgrelunc=0.3){
     double bgunc = bgrelunc*bg;
     double tau = bg/pow(bgunc,2);//bgunc is absolute
     double n_on = sig+bg;//total yield in SR = sig + bg
     double n_off = tau*bg;
     double P_Bi = TMath::BetaIncomplete(1./(1.+tau),n_on,n_off+1);
     double Z_Bi = sqrt(2.)*TMath::ErfInverse(1.-2.*P_Bi);
     return Z_Bi;
}

 
