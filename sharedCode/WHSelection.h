#ifndef WHSELECTION_H
#define WHSELECTION_H

#include "StopSelections.h"
namespace whsel{
bool passPreselection(std::string selection);
bool pass2lPreselection();
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
float mbb(vector<int>);
float ptbb(vector<int>);
float dphibb(vector<int>);
float dRbb(vector<int>);
float mct(vector<int>);
float getmct();
float getmbb();
float getdphibb();
float getdRbb();
float getptbb();
float leadjetpt();
float subleadjetpt();
float isrjetpt();
inline bool sortIndexbyCSV( pair<int, float> &vec1, pair<int, float> &vec2 ) ;
vector <pair<int, float>> sortedjetsbyCSV();
}
#endif
