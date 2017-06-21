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

  //string babylocation = Form("/nfs-7/userdata/mliu/onelepbabies/%s/",iter.c_str());
  //string babylocation = Form("/nfs-7/userdata/mliu/onelepbabies/%s/","V00-00-04");
//  string babylocation = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/";
  string babylocation = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v9__20160127/merged_files/";
  //string babylocation = "/nfs-7/userdata/mliu/jes_nominal/"; //jes nominal
  //babylocation = "/nfs-7/userdata/mliu/jes_up/";
  //babylocation = "/nfs-7/userdata/mliu/jes_dn/";
  string helper;

  if ( sample == "jes_nominal_ttz"){
       helper = "/nfs-7/userdata/mliu/jes_nominal/TTZ*"; ch->Add(helper.c_str());
  }
  else if (sample == "jes_nominal_ttz_btag")
 {
     helper = "/nfs-7/userdata/mliu/jes_nominal_wbtag/TTZToLLNuNu.root"; ch->Add(helper.c_str());
 }
  else if (sample == "jes_up_ttz")
  {
       helper = "/nfs-7/userdata/mliu/jes_up/TTZ*"; ch->Add(helper.c_str());
  } 
 else if (sample == "jes_dn_ttz")
  {
       helper = "/nfs-7/userdata/mliu/jes_dn/TTZ*"; ch->Add(helper.c_str());
  }
 else if (sample == "ttw"){
      helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/TTWJetsToQQ_amcnlo_pythia8_25ns.root"; ch->Add(helper.c_str());
 }
else if (sample == "tZq"){
     helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/tZq_*.root"; ch->Add(helper.c_str());
 }
else if (sample == "ww"){
    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/WW*";ch->Add(helper.c_str());
 }
else if (sample == "wz"){
    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/WZ*";ch->Add(helper.c_str());
 }
else if (sample == "zz"){
    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/ZZ*";ch->Add(helper.c_str());
 }
  else if ( sample == "data" ){
        helper = babylocation+"data_single_electron_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_single_muon_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_single_muon_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_single_electron_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_met_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = babylocation+"data_met_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
  }
  else if ( sample == "All_MC" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_50ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_50ns_m50nlo*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/tt2lnu_50ns_php8*.root"         , iter.c_str() ));	
  }
  else if( sample == "zjets" ){
        helper = babylocation+"DYJetsToLL_m10To50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str()); //inclusive sample
        helper = babylocation+"DYJetsToLL_m50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str());
  }
   else if( sample == "zjets_htbin" ){
          helper = babylocation+"DYJetsToLL_M-5to50_HT*.root"; ch->Add(helper.c_str());//ht binned
          helper = babylocation+"DYJetsToLL_M-50*.root"; ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "wjets" ){
        helper = babylocation+"WJetsToLNu_madgraph_pythia8_25*.root";ch->Add(helper.c_str());//amcnlo
  }
   else if( sample == "wjets_htbin" ){
           helper = babylocation+"WJetsToLNu_HT100To200*.root";ch->Add(helper.c_str());//ht binned
           helper = babylocation+"WJetsToLNu_HT200To400*.root";ch->Add(helper.c_str());//ht binned
           helper = babylocation+"WJetsToLNu_HT400To600*.root";ch->Add(helper.c_str());//ht binned
           //helper = babylocation+"WJetsToLNu_HT600To800*.root";ch->Add(helper.c_str());//ht binned
           helper = "/nfs-6/userdata/mliu/onelepbabies/V00-00-09/WJetsToLNu_HT600To800_madgraph_pythia8_25ns*.root"; ch->Add(helper.c_str());// add 600 to 800 from my own babies
           helper = babylocation+"WJetsToLNu_HT800To1200*.root";ch->Add(helper.c_str());//ht binned
           helper = babylocation+"WJetsToLNu_HT1200To2500*.root";ch->Add(helper.c_str());//ht binned
           helper = babylocation+"WJetsToLNu_HT2500ToInf*.root";ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "zjinc" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
  }

  else if( sample == "ttbar" ){
        helper = babylocation+"ttbar_powheg_pythia8*ext3*.root"; ch->Add(helper.c_str());
  }
  else if ( sample == "QCD"){
        helper = babylocation+"QCD*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "vv" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/zz_4l*.root", iter.c_str() ));	
  }

  else if( sample == "ttv" ){
        helper = babylocation+"ttz_*.root";ch->Add(helper.c_str());//single top
  }
  else if( sample=="top"){
        helper = babylocation+"ST_tW_*_5f_inclusiveDecays.root";ch->Add(helper.c_str());//single top
        helper = babylocation+"ST_*channel.root"; ch->Add(helper.c_str());
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
