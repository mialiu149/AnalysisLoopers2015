 #include <iostream>

#include "TChain.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"

#include "templateLooper.h"

using namespace std;

void runTemplateLooper( std::string selection = "", std::string iter = "", std::string sample = "All_MC" ){

  gSystem->Load("libTemplateLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");
  if ( sample == "data" ){
	// ch->Add(Form("/home/users/cwelke/analysis2015/CMSSW_7_4_1_patch1/analysis2015_dev/analysis2015/dilepbabymaker/unknown_test_data.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_ee*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_em*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_mm*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_ph*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_se*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_sm*.root" , iter.c_str() ));

	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_ee.root", iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_em.root", iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_mm.root", iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_ph.root", iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_se.root", iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_50ns_sm.root", iter.c_str() ));
  }
  
  else if ( sample == "All_MC" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m50nlo*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tt2lnu_50ns_php8*.root"         , iter.c_str() ));	
  }

  else if( sample == "zjets" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m50nlo*.root"    , iter.c_str() ));
  }

  else if( sample == "zjinc" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
  }

  else if( sample == "ttbar" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tt2lnu_50ns_php8*.root"         , iter.c_str() ));
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

int main(int argc, char **argv)
{

  if (argc < 4) {
    std::cout << "USAGE: runTemplateLooper <selection> <iter> <sample>" << std::endl;
    return 1;
  }
  
  string selection(argv[1]); 
  string iter(argv[2]); 
  string sample(argv[3]); 
  
  runTemplateLooper( selection, iter, sample );
  return 0;
}
