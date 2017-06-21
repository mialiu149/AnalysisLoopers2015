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

  string babylocation = Form("/nfs-7/userdata/mliu/onelepbabies/%s/",iter.c_str());
  string helper;
  
  if ( sample == "data" ){
        helper = babylocation+"data_double_eg_2015D*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_double_mu_2015D*.root"; ch->Add(helper.c_str());
  }
  
  else if ( sample == "All_MC" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_50ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_50ns_m50nlo*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/tt2lnu_50ns_php8*.root"         , iter.c_str() ));	
  }

  else if( sample == "zjets" ){
        helper = babylocation+"DYJetsToLL_m10To50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str());
        helper = babylocation+"DYJetsToLL_m50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "wjets" ){
        helper = babylocation+"WJetsToLNu_amcnlo_pythia8_25ns*.root";ch->Add(helper.c_str());
  }
  else if( sample == "zjinc" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
  }

  else if( sample == "ttbar" ){
        helper = babylocation+"ttbar_madgraph_pythia8_25ns*.root"; ch->Add(helper.c_str());
  }

  else if( sample == "top" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/t_*.root", iter.c_str() ));	
  }
  else if ( sample == "QCD"){
        helper = babylocation+"QCD_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "vv" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/zz_4l*.root", iter.c_str() ));	
  }

  else if( sample == "ttv" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/tth*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/ttw*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/ttv*.root", iter.c_str() ));	
  }
  
  else if( sample == "FS_BG" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/ttall_msdecays*.root", iter.c_str() ));	

	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/t_bartw.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/t_toptw.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/zz_4l*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/tth*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/ttw*.root", iter.c_str() ));	
	// // ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/ttv*.root", iter.c_str() ));	
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
