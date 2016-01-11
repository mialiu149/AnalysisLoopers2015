#ifndef ANALYSISSELECTIONS_H
#define ANALYSISSELECTIONS_H

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
int  lep1type();// checking the type of the second lepton.  type1: good. type2: 2l_veto. 
int  lep2type();// checking the type of the second lepton.  type1: good. type2: 2l_veto. 
int  eventtype(); //1: lep1_sel,lep2_sel, 2: lep1_sel,lep2_sel, 3: lep1_veto, lep2_sel, 4: lep1_veto, lep2_veto., 5: lep1 overlaps with lep2, sel, 6: lep1 overlaps with lep2, veto 
#endif
