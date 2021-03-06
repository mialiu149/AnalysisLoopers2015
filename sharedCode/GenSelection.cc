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

#include "GenSelection.h"
#include "histTools.h"
#include "../classFiles/V80_03.h"

using namespace std;
using namespace V80_03_np; 

namespace gensel{

float gennuptw(){
    vector<vector<int>> selected_leps = lep_nu_fromW(); int gennui =-999;
    if(selected_leps.at(1).size()+selected_leps.at(3).size() !=1)     return -999; //require only lepton events
    if(selected_leps.at(1).size()) gennui = selected_leps.at(1)[0] ;//events from w plus 
    if(selected_leps.at(3).size()) gennui = selected_leps.at(3)[0] ;//events from w minus
    if(gennui==-999) return -999;
    float gennupt  = gennus_p4().at(gennui).pt();
   return gennupt;
}

vector<vector<int>> lep_nu_fromW() { 
 vector<int> leps_plus;
 vector<int> nus_plus;
 vector<int> leps_minus;
 vector<int> nus_minus;
 vector <vector<int>> lep_nu;

 for (unsigned int i=0;i<genleps_p4().size();i++) {
     if(genleps_motherid()[i] == 24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13) && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1)) leps_plus.push_back(i);
     if(genleps_motherid()[i] == -24 && (abs(genleps_id()[i]) == 11||abs(genleps_id()[i]) == 13) && genleps_p4()[i].pt() > 1 && (genleps_status()[i] == 1)) leps_minus.push_back(i);
 }
 for (unsigned int i=0;i<gennus_p4().size();i++){
     if(gennus_motherid()[i] == 24 && (abs(gennus_id()[i]) == 12||abs(gennus_id()[i]) == 14) && gennus_p4()[i].pt() > 1 && (gennus_status()[i] == 1)) nus_plus.push_back(i);
     if(gennus_motherid()[i] == -24 && (abs(gennus_id()[i]) == 12||abs(gennus_id()[i]) == 14) && gennus_p4()[i].pt() > 1 && (gennus_status()[i] == 1)) nus_minus.push_back(i);
 }

 lep_nu.push_back(leps_plus);//e plus 0 
 lep_nu.push_back(nus_plus);//nu plus 1
 lep_nu.push_back(leps_minus); //e minus 2
 lep_nu.push_back(nus_minus);//nu minus 3
 return lep_nu;
 }// end of lep_nu_fromW

vector<int> bs_fromH() {
 vector<int> bs_fromHiggs;
 for (unsigned int i=0; i<genqs_p4().size();i++){
    //if(genqs_motherid()[i] == 25 && fabs(genqs_id()[i]) == 5) {bs_fromHiggs.push_back(i); cout<< "status:" <<genqs_status()[i]<<endl;} 
   if(genqs_motherid()[i] == 25 && abs(genqs_id()[i]) == 5 && (genqs_status()[i] == 23)) bs_fromHiggs.push_back(i); 
 }
 //cout<<"bs_fromHiggs :: "<<bs_fromHiggs.size()<<endl;
 //cout<<"gen_bosons :: "<<genbosons_p4().size()<<endl;
 return bs_fromHiggs; 
}
int isHF(){
  int isHF = 0;
  for (unsigned int i=0;i<ak4pfjets_p4().size();i++){
  if (ak4pfjets_hadron_flavor().at(i)==5) isHF++;
}
 return isHF; 
}

}//end of namespace
