// #include <string>

// // #include "makePhotonTemplates.C"

// #include "makePhotonTemplates.h"

// #include "TChain.h"
// #include "TSystem.h"
// #include "TROOT.h"
// #include "TStyle.h"


// using namespace std;

void runPhotonTemplates( std::string selection = "", std::string iter = "", std::string sample = "" ){

  gSystem->Load("libmakePhotonTemplates.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "All_MC" ){
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_pt40_doubleEM.root");

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht100to200*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht200to400*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht400to600*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht600toinf*.root", iter.c_str() ));

	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht100to200.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf_1.root" );

  }

  makePhotonTemplates* myLooper = new makePhotonTemplates();
  myLooper->ScanChain( ch , iter , sample, selection );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

