// #include <string>

// // #include "makePhotonTemplates.C"

// #include "makePhotonTemplates.h"

// #include "TChain.h"
// #include "TSystem.h"
// #include "TROOT.h"
// #include "TStyle.h"


// using namespace std;

void runPhotonLooper( std::string selection = "" ){

  string iter = "V00-00-00";

  string sample = "All_MC"; 

  gSystem->Load("libPhotonLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "All_MC" ){
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_pt40_doubleEM.root");

	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht100to200*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf*.root");

	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht100to200.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf_1.root" );

  }

  photonLooper* myLooper = new photonLooper();
  myLooper->ScanChain( ch , iter , sample );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

