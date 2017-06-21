#ifndef STOPMORIOND2016_H
#define STOPMORIOND2016_H

#include "StopSelections.h"
bool passPreselection(std::string selection);
bool pass2lPreselection();
bool passBaseline( std::string selection);
bool passSR( std::string selection );
bool passRegion(std::string selection);
bool passStudyRegion(std::string selection);
bool pass1lCR( std::string selection );
bool pass2lCR( std::string selection );
float event_weight(std::string selection);
// following functions are used for gen level studies.
vector<vector<int>>  lep_nu_fromW();
std::pair<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >,ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> qs_fromW();
#endif
