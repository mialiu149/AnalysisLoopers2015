#ifndef ANALYSISSELECTIONS_H
#define ANALYSISSELECTIONS_H

#include "AnalysisSelections.h"

bool passBaselineSelections();
bool passSignalRegionSelection( std::string selection );
bool eventHas2GoodLeps();
bool eventHas3Jets();
bool eventHasGoodPhoton();
bool passPhotonTrigger();
bool passPhotonTrigger22();
bool passPhotonTrigger30();
bool passPhotonTrigger36();
bool passPhotonTrigger50();
bool passPhotonTrigger75();
bool passPhotonTrigger90();
bool passPhotonTrigger120();
bool passPhotonTrigger165();
int  getPrescale();
bool highHT_zjinc( std::string samplename );

#endif
