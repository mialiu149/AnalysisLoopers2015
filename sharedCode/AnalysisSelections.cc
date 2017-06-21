#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1.h"
#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"

#include "AnalysisSelections.h"
#include "histTools.h"
#include "ZMET.h"

using namespace std;

bool passBaselineSelections()
{
  if( zmet.njets()                       < 2         ) return false; // >=2 jets  
  // if( zmet.ht()                          < 240       ) return false; // >=240 GeV HT  
  return true;
}

bool passSignalRegionSelection( string selection )
{
  if( TString(selection).Contains("bveto"          ) && zmet.nBJetMedium() > 0   ) return false; //bveto
  if( TString(selection).Contains("withb"          ) && zmet.nBJetMedium() < 1   ) return false; //at least 1 b-tag
  if( TString(selection).Contains("SRA"            ) && !((zmet.njets() == 2 ||
														   zmet.njets() == 3  ) &&
														  (zmet.ht()    > 600 )) ) return false; //high HT region
  if( TString(selection).Contains("SRB"            ) && zmet.njets() < 4         ) return false; //large njets
  if( TString(selection).Contains("twojets"        ) && zmet.njets() > 2         ) return false; //exactly 2 jets
  if( TString(selection).Contains("2jets_inclusive") && zmet.njets() < 2         ) return false; //at least 2 jets
  if( TString(selection).Contains("3jets_inclusive") && zmet.njets() < 3         ) return false; //at least 3 jets

  return true;
}

bool eventHas2GoodLeps()
{
  if( zmet.nlep()                        < 2         ) return false; // require at least 2 good leptons
  if( zmet.lep_pt().at(0)                < 25        ) return false; // leading lep pT > 25 GeV
  if( zmet.lep_pt().at(1)                < 20        ) return false; // tailing lep pT > 20 GeV
  if( abs(zmet.lep_p4().at(0).eta())     > 2.4       ) return false; // eta < 2.4
  if( abs(zmet.lep_p4().at(1).eta())     > 2.4       ) return false; // eta < 2.4
  if( abs(zmet.lep_p4().at(0).eta())     > 1.4 &&
	  abs(zmet.lep_p4().at(0).eta())     < 1.6       ) return false;
  if( abs(zmet.lep_p4().at(1).eta())     > 1.4 &&
	  abs(zmet.lep_p4().at(1).eta())     < 1.6       ) return false; // veto xition region
  if( zmet.dRll()                        < 0.1       ) return false;
  if( !(zmet.hyp_type() == 0 ||					     
		zmet.hyp_type() == 1 ||					     
		zmet.hyp_type() == 2 )                       ) return false; // require explicit dilepton event
  if( !(zmet.evt_type() == 0 )                       ) return false; // require opposite sign
  if( !(zmet.dilmass() > 81 && zmet.dilmass() < 101) ) return false; // on-Z
  if( !(zmet.dilpt() > 50)                           ) return false; // Z pT > 50 GeV
  return true;
}

bool eventHas3Jets()
{
  if( zmet.njets()                       < 3         ) return false; // require at least 3 jets
  return true;
}

bool eventHasGoodPhoton()
{
  if( zmet.ngamma()                      <  1    ) return false; // require at least 1 good photon
  if( zmet.evt_type()                    != 2    ) return false; // photon + jets events
  if( zmet.gamma_pt().at(0)              < 22    ) return false; // photon pt > 22 GeV
  if( abs(zmet.gamma_p4().at(0).eta())   > 1.4 &&
	  abs(zmet.gamma_p4().at(0).eta())   < 1.6   ) return false; // veto xition region
  if( abs(zmet.gamma_p4().at(0).eta())   > 2.4   ) return false; // photon in EC or EB
  if( zmet.gamma_hOverE().at(0)          > 0.1   ) return false; // H/E < 0.1	  
  if( zmet.matched_neutralemf()          < 0.7   ) return false; // jet neutral EM fraction cut
  if( acos( cos( zmet.gamma_phi().at(0)			 
				 - zmet.met_phi() ) )    < 0.14  ) return false; // kill photons aligned with MET
  if( zmet.elveto()                              ) return false; // veto pixel match
  return true;  
}

bool passPhotonTrigger()
{
  if(      passPhotonTrigger22()  ) return true;
  else if( passPhotonTrigger30()  ) return true;
  else if( passPhotonTrigger36()  ) return true;
  else if( passPhotonTrigger50()  ) return true;
  else if( passPhotonTrigger75()  ) return true;
  else if( passPhotonTrigger90()  ) return true;
  else if( passPhotonTrigger120() ) return true;
  else if( passPhotonTrigger165() ) return true;
  return false;
}

bool passPhotonTrigger22()
{
  if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 0   && zmet.gamma_pt().at(0) < 35  ) return true;
  return false;
}

bool passPhotonTrigger30()
{
  if( zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 35  && zmet.gamma_pt().at(0) < 40  ) return true;
  return false;
}

bool passPhotonTrigger36()
{
  if( zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 40  && zmet.gamma_pt().at(0) < 60  ) return true;
  return false;
}

bool passPhotonTrigger50()
{
  if( zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 60  && zmet.gamma_pt().at(0) < 80  ) return true;
  return false;
}

bool passPhotonTrigger75()
{
  if( zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 80  && zmet.gamma_pt().at(0) < 100 ) return true;
  return false;
}

bool passPhotonTrigger90()
{
  if( zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 100 && zmet.gamma_pt().at(0) < 125 ) return true;
  return false;
}

bool passPhotonTrigger120()
{
  if( zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 && zmet.gamma_pt().at(0) > 125 && zmet.gamma_pt().at(0) < 170 ) return true;
  return false;
}

bool passPhotonTrigger165()
{
  if( zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 && zmet.gamma_pt().at(0) > 170                                ) return true;
  return false;
}

int getPrescale()
{
  if( !( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ||
		 zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 
		 ) ) return 0;
  if(      passPhotonTrigger22()  ) return zmet.HLT_Photon22_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger30()  ) return zmet.HLT_Photon30_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger36()  ) return zmet.HLT_Photon36_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger50()  ) return zmet.HLT_Photon50_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger75()  ) return zmet.HLT_Photon75_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger90()  ) return zmet.HLT_Photon90_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger120() ) return zmet.HLT_Photon120_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger165() ) return zmet.HLT_Photon165_R9Id90_HE10_IsoM();
  return -1; // should not get here
}

bool highHT_zjinc( string samplename )
{
  if( TString(samplename).Contains("m50inc") ){
	if( zmet.gen_ht() > 100 ) return true;
  }
  return false;
}
