// #include <string>

// // #include "makePhotonTemplates.C"

// #include "makePhotonTemplates.h"

// #include "TChain.h"
// #include "TSystem.h"
// #include "TROOT.h"
// #include "TStyle.h"


// using namespace std;

void runTemplateLooper( std::string selection = "", std::string iter = "", std::string sample = "All_MC" ){

  gSystem->Load("libTemplateLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "All_MC" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));	

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttall_msdecays*.root", iter.c_str() ));	

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t_*.root", iter.c_str() ));	

  	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz_4l*.root", iter.c_str() ));	

  	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tth*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttw*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttv*.root", iter.c_str() ));	
  }

  else if( sample == "zjets" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));	
  }

  else if( sample == "zjinc" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
  }

  else if( sample == "ttbar" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttall_msdecays*.root", iter.c_str() ));	
  }

  else if( sample == "top" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t_*.root", iter.c_str() ));	
  }

  else if( sample == "vv" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz_4l*.root", iter.c_str() ));	
  }

  else if( sample == "ttv" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tth*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttw*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttv*.root", iter.c_str() ));	
  }
  
  else if( sample == "FS_BG" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttall_msdecays*.root", iter.c_str() ));	

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t_bartw.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t_toptw.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz_4l*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tth*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttw*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttv*.root", iter.c_str() ));	
  }

  templateLooper* myLooper = new templateLooper();
  myLooper->ScanChain( ch , iter , sample, selection );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

