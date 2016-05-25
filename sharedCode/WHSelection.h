#ifndef ANALYSISSELECTIONS_H
#define ANALYSISSELECTIONS_H

#include "StopSelections.h"
namespace whsel{
bool passPreselection(std::string selection);
bool pass2lPreselection();
bool passBaseline( std::string selection);
bool passSR( std::string selection );
bool passRegion(std::string selection);
bool passStudyRegion(std::string selection);
bool pass1lCR( std::string selection );
bool pass2lCR( std::string selection );
bool passmbbCR( std::string selection );
bool passbin( std::string selection);
float event_weight(std::string selection);
// the following functions are used to catergorize 2l CR estimation.
// following functions are used for gen level studies.
std::pair<vector<int>,vector<int> >btaggedjets();
vector<int> selbjets();
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
inline bool sortIndexbyCSV( pair<int, float> &vec1, pair<int, float> &vec2 ) ;
vector <pair<int, float>> sortedjetsbyCSV();
}
#endif
