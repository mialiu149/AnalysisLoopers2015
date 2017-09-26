#ifndef TRIBOSONSELECTION_H
#define TRIBOSONSELECTION_H

#include "StopSelections.h"
namespace tribosonsel{
//enum eventtype{ss_ee,ss_em,ss_mm}
bool passPreselection(std::string selection, TH1D* &hist);
bool passPreselection(std::string selection);
int  trilepEventtype();
bool passBaseline( std::string selection);
bool passSR( std::string selection );
bool passcutflow( std::string selection );
bool passRegion(std::string selection);
bool passStudyRegion(std::string selection);
bool pass1lCR( std::string selection );
bool pass2lCR( std::string selection );
bool passmbbCR( std::string selection );
bool passbin( std::string selection);
float event_weight(std::string selection);
bool passISR();
bool passWJetsValidation();
std::pair<vector<int>,vector<int> >btaggedjets(bool isloose);
vector<int> selectedjets();
vector<int> vetojets();
vector<int> forwardjets();
vector<int> selectedLooseLeps(string selection);
float mbb(vector<int>);
float ptbb(vector<int>);
float dphibb(vector<int>);
float dRbb(vector<int>);
float mct(vector<int>);
float getmct();
float getmjj();
float getmll();
float getdphibb();
float getdRbb();
float getptbb();
float leadjetpt();
float subleadjetpt();
float isrjetpt();
int countvetoleps(float pt_cut);
inline bool sortIndexbyCSV( pair<int, float> &vec1, pair<int, float> &vec2 ) ;
inline bool sortByValue(const std::pair<int, int>& vec1, const std::pair<int, int>& vec2 ) ;
vector <pair<int, float>> sortedjetsbyCSV();
pair<int,float> trileptype_dilepmass(vector<int> sellep_index);
vector<int> selectedLeps(string selection);
int hyp_type_looper(vector<int> lepindex);
float ptlljj(vector<int>leps,vector<int>jets); 
float maxMt(vector<int>leps);
float dphi3lmet(vector<int>leps, float met_phi);
float mjj_dRmin(vector<int> jets);
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
