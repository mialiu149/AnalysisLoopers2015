#ifndef EVETNTYPESELS_H
#define EVETNTYPESELS_H

#include "StopSelections.h"

int  lep1type();// checking the type of the second lepton.  type1: good. type2: 2l_veto. 
int  lep2type();// checking the type of the second lepton.  type1: good. type2: 2l_veto. 
int  eventtype(); //1: lep1_sel,lep2_sel, 2: lep1_sel,lep2_sel, 3: lep1_veto, lep2_sel, 4: lep1_veto, lep2_veto., 5: lep1 overlaps with lep2, sel, 6: lep1 overlaps with lep2, veto 
float worseMETrel(float percent);
// following functions are used for gen level studies.
#endif
