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
#endif
