#ifndef GENSELECTION_H
#define GENSELECTION_H

#include "StopSelections.h"
// following functions are used for gen level studies.
namespace gensel{
vector<vector<int>>  lep_nu_fromW();
vector<int>  bs_fromH();
int isHF();// Heavy flavor
float gennuptw();
}//end of namespace
#endif
