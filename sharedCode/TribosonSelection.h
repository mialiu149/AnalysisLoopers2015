#ifndef TRIBOSONSELECTION_H
#define TRIBOSONSELECTION_H

#include "StopSelections.h"
namespace tribosonsel{
//enum eventtype{ss_ee,ss_em,ss_mm}

struct eventinfo{
  int eventtype;
  float mll;
  float mtmax  ; 
  float detajj ;
  float mjj    ;
  float mjjlead ;
  float mlll   ;
  float ptlll   ;
  float dphi3lmet ;
  vector<unsigned int> leps;
  vector<unsigned int> jets;

  eventinfo(){
   eventtype = -999.0;
   mll    = -999.0;
   mtmax  = -999.0; 
   detajj = -999.0;
   mjj    = -999.0;
   mjjlead = -999.0;
   mlll   = -999.0;
   ptlll   = -999.0;
   dphi3lmet = -999.0;
  }
} ;

bool passPreselection(std::string selection, TH1D* &hist);
bool passPreselection(std::string selection);
int  trilepEventtype();
bool passBaseline( std::string selection);
bool passSelection( std::string selection,eventinfo& );
bool passcutflow( std::string selection );
bool passRegion(std::string selection);
bool passbin( std::string selection);
float event_weight(std::string selection);
std::pair<vector<unsigned int>,vector<int> >btaggedjets(bool isloose);
vector<unsigned int> selectedjets();
vector<unsigned int> vetojets();
vector<unsigned int> forwardjets();
float mbb(vector<unsigned int>);
float ptbb(vector<unsigned int>);
float dphibb(vector<unsigned int>);
float dRbb(vector<unsigned int>);
float mct(vector<unsigned int>);
int   countvetoleps(float pt_cut);
inline bool sortIndexbyCSV( pair<int, float> &vec1, pair<int, float> &vec2 ) ;
inline bool sortByValue(const std::pair<int, int>& vec1, const std::pair<int, int>& vec2 ) ;
vector <pair<int, float>> sortedjetsbyCSV();
pair<int,float> trileptype_dilepmass(vector<unsigned int> sellep_index);
vector<unsigned int> selectedLeps(string selection);
int hyp_type_looper(vector<unsigned int> lepindex);
float ptlljj(vector<unsigned int>leps,vector<unsigned int>jets); 
float maxMt(vector<unsigned int>leps);
float dphi3lmet(vector<unsigned int>leps, float met_phi);
float mjj_dRmin(vector<unsigned int> jets);
float getmjj();
int preselRegion(string selection);
int signalRegion2016();
bool isgammafake(); 
bool isGoodLepton(int lepindex, string selection);
bool isLooseLepton(int lepindex, string selection);
bool isLooseNotTight(int lepindex, string selection);
pair <int, int> lepMotherID_v2(int lepindex);
int hyp_class();
template <typename T> int sgn(T val){
	  return (T(0) < val) - (val < T(0));
}
float coneCorrPt(int lepi);
int gentype();
int gentype(unsigned lep1_index,unsigned ilep2_index);
int gentype(unsigned lep1_index,unsigned ilep2_index,int lep3_index);
float fakerateweight(bool substract, string selection,unsigned lep1_index,unsigned ilep2_index,int lep3_index);
}
#endif
