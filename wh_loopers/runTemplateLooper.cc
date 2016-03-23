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
  string babylocation = "/nfs-6/userdata/mliu/whbabies/";
  string stopbabylocation = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v9__20160127/merged_files/";
  string helper;

  if ( sample == "jes_nominal_ttz"){
       helper = "/nfs-7/userdata/mliu/jes_nominal/TTZ*"; ch->Add(helper.c_str());
  }
  else if (sample == "wh_350_1"){
//       helper = "/home/users/mliu/AnalysisLoopers2015/wh_loopers/../../stop2015/StopBabyMaker/SMS_tchwh_test.root"; ch->Add(helper.c_str());
       helper = babylocation+"SMS_tchwh_350_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_250_1"){
       helper = babylocation+"SMS_tchwh_250_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_225_80"){
       helper = babylocation+"SMS_tchwh_225_80.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_300_80"){
       helper = babylocation+"SMS_tchwh_300_80.root"; ch->Add(helper.c_str());
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
else if (sample =="diboson"){
    helper  =stopbabylocation+"WW*";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZ*";ch->Add(helper.c_str());
    helper  =stopbabylocation+"ZZ*";ch->Add(helper.c_str());
}
  else if ( sample == "data" ){
        helper = stopbabylocation+"data_single_electron_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"data_single_muon_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"data_single_muon_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"data_single_electron_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"data_met_2015D_promptRecoV4*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"data_met_2015D_05Oct2015_v1*.root"; ch->Add(helper.c_str());
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
           helper = stopbabylocation+"WJetsToLNu_HT100To200*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT200To400*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT400To600*.root";ch->Add(helper.c_str());//ht binned
           //helper = stopbabylocation+"WJetsToLNu_HT600To800*.root";ch->Add(helper.c_str());//ht binned
           helper = "/nfs-6/userdata/mliu/onelepbabies/V00-00-09/WJetsToLNu_HT600To800_madgraph_pythia8_25ns*.root"; ch->Add(helper.c_str());// add 600 to 800 from my own babies
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT1200To2500*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT2500ToInf*.root";ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "wbb"){
        helper = babylocation+"WBJets.root";ch->Add(helper.c_str());
  }
  else if( sample == "ttbar" ){
        helper = stopbabylocation+"ttbar_powheg_pythia8*ext3*.root"; ch->Add(helper.c_str());
  }
  else if ( sample == "QCD"){
        helper = babylocation+"QCD*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "vv" ){
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/wz_3lnu*.root", iter.c_str() ));	
	ch->Add(Form("/nfs-6/userdata/mliu/onelepbabies/%s/zz_4l*.root", iter.c_str() ));	
  }

  else if( sample == "ttv" ){
        helper = stopbabylocation+"TTZ*.root";ch->Add(helper.c_str());//ttv
        cout<<"input for ttv:"<<helper<<endl;
        helper = stopbabylocation+"TTW*.root";ch->Add(helper.c_str());//ttv
  }
  else if( sample=="top"){
//        helper = stopbabylocation+"ST_tW_*.root";ch->Add(helper.c_str());//single top
        helper = stopbabylocation+"t_*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_*.root"; ch->Add(helper.c_str());
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
