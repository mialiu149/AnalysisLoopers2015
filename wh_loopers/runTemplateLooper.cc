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
  string sigbabylocation = "/nfs-6/userdata/mliu/onelepbabies/V80_4fb/";
  string datalocation="/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/"; 
  string babylocation = "/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/";
  string stopbabylocation = "/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/";

  string helper;

  if ( sample == "jes_nominal_ttz"){
       helper = "/nfs-7/userdata/mliu/jes_nominal/TTZ*"; ch->Add(helper.c_str());
  }
  else if (sample == "wh_350_1"){
       helper = sigbabylocation+"SMS_tchwh_350_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_testscan"){
       //helper = "/nfs-6/userdata/mliu/onelepbabies/V80_signalscan_test/SMS_t2bw_scan_merged.root"; ch->Add(helper.c_str());
       helper = "/home/users/mliu/Stopmialiu149/StopBabyMaker/SMS_tchwh_lnbb.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_150_30"){
       helper = sigbabylocation+"tchwh_150_30.root"; ch->Add(helper.c_str());
 }
 
  else if (sample == "wh_250_1"){
       helper = sigbabylocation+"SMS_tchwh_250_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_225_80"){
       helper = sigbabylocation+"SMS_tchwh_225_80.root"; ch->Add(helper.c_str());
 }
  else if (sample == "wh_300_80"){
       helper = sigbabylocation+"SMS_tchwh_300_80.root"; ch->Add(helper.c_str());
 }

  else if (sample == "SMS_tchwh_lnbb"){
       helper = "/nfs-6/userdata/mliu/onelepbabies/V80_signalscanv3/SMS_tchwh_lnbb.root"; ch->Add(helper.c_str());
       //helper = "/home/users/mliu/Stopmialiu149/StopBabyMaker/SMS_tchwh_lnbb.root"; ch->Add(helper.c_str());
 }
 else if (sample =="diboson"){
    helper  =stopbabylocation+"WWTo*";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo3LNu_powheg_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo2L2Q_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"ZZTo*";ch->Add(helper.c_str());
 }
  else if ( sample == "data" ){
        //helper = stopbabylocation+"data_single_electron_*.root"; ch->Add(helper.c_str());
       // helper = stopbabylocation+"data_single_muon_*.root"; ch->Add(helper.c_str());
        helper = datalocation+"data_single_electron_*.root"; ch->Add(helper.c_str());
        helper = datalocation+"data_single_muon_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "zjets" ){
        helper = babylocation+"DYJetsToLL_m10To50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str()); //inclusive sample
        helper = babylocation+"DYJetsToLL_m50_amcnlo_pythia8_25ns*.root"; ch->Add(helper.c_str());
  }
   else if( sample == "zjets_htbin" ){
          helper = babylocation+"DYJetsToLL_M-5to50_HT*.root"; ch->Add(helper.c_str());//ht binned
          helper = babylocation+"DYJetsToLL_M-50*.root"; ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "ws_incl" ){
        helper = stopbabylocation+"WJetsToLNu_madgraph_pythia8_25ns.root";ch->Add(helper.c_str());
  }
   else if( sample == "ws_htbin" ){
           helper = stopbabylocation+"WJetsToLNu_HT100To200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT200To400*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT400To600*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT600To800*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT1200To2500*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT2500ToInf*.root";ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "ws_ht100"){
        helper = stopbabylocation+"WJetsToLNu_madgraph_pythia8_25ns.root";ch->Add(helper.c_str());
  }
  else if( sample == "wbb"){
        helper = babylocation+"WBJets.root";ch->Add(helper.c_str());
        helper = stopbabylocation+"WZTo1LNu2Q_amcnlo*.root";ch->Add(helper.c_str());
  }
  else if( sample == "tops" ){
        helper = stopbabylocation+"ttbar_powheg_pythia8*ext4*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"t_*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "singletop" ){
        helper = stopbabylocation+"t_*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "ttbar" ){
        helper = stopbabylocation+"ttbar_powheg_pythia8*ext4*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "wsHF"){
        helper = babylocation+"WBJets.root";ch->Add(helper.c_str());
  }

  else if( sample == "w1jets"){        helper = stopbabylocation+"W1JetsToLNu*.root";ch->Add(helper.c_str());}//njets binned
  else if( sample == "w2jets"){        helper = stopbabylocation+"W2JetsToLNu*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w3jets"){        helper = stopbabylocation+"W3JetsToLNu*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w4jets"){        helper = stopbabylocation+"W4JetsToLNu*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "ws_njets"){
        helper = stopbabylocation+"W1JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W2JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W3JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W4JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
  }
  else if( sample == "ws_njets_tostitch"){
        helper = stopbabylocation+"W1JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W2JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W3JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W4JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
  }
  else if(sample=="ws_htbin_tostitch"){
           helper = stopbabylocation+"WJetsToLNu_HT100To200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT200To400*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT400To600*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT600To800*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT1200To2500*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT2500ToInf*.root";ch->Add(helper.c_str());//ht binned

   }
  else if( sample == "wzbb"){
        helper = stopbabylocation+"WZTo1LNu2Q_amcnlo*.root";ch->Add(helper.c_str());
  }
  else if( sample == "rare"){
        helper = stopbabylocation+"TTZ*.root";ch->Add(helper.c_str());//ttv
        helper = stopbabylocation+"TTW*.root";ch->Add(helper.c_str());//ttv
        helper  =stopbabylocation+"WWTo*";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo3LNu_powheg_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo2L2Q_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  =stopbabylocation+"ZZTo*";ch->Add(helper.c_str());
        helper  = datalocation+"WminusH*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WplusH*";ch->Add(helper.c_str());
        helper  = datalocation+"WWW*";ch->Add(helper.c_str());
        helper  = datalocation+"WWG*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WWZ*";ch->Add(helper.c_str());
        helper  = datalocation+"WZZ*";ch->Add(helper.c_str());
        helper  = datalocation+"ZZZ*";ch->Add(helper.c_str());
  }
  else if( sample =="smWH"){
        helper  = datalocation+"WminusH*";ch->Add(helper.c_str());
        helper  = datalocation+"WplusH*";ch->Add(helper.c_str());
  }
  else if( sample == "triboson"){
        helper  = datalocation+"WWW*";ch->Add(helper.c_str());
        helper  = datalocation+"WWG*";ch->Add(helper.c_str());
        helper  = datalocation+"WWZ*";ch->Add(helper.c_str());
        helper  = datalocation+"WZZ*";ch->Add(helper.c_str());
        helper  = datalocation+"ZZZ*";ch->Add(helper.c_str());
  }
  else if( sample == "ttbar2l" ){
        helper = stopbabylocation+"ttbar_diLept_madgraph*ext1*.root"; ch->Add(helper.c_str());
  }
  else if (sample =="ws_nupt200"){
        helper = datalocation+"W1JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = datalocation+"W2JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = datalocation+"W3JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = datalocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w1jets_nupt200"){
        helper = datalocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }

  else if (sample == "w2jets_nupt200"){
        helper = datalocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }

  else if (sample == "w3jets_nupt200"){
        helper = datalocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w4jets_nupt200"){
        helper = datalocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "tops_mad" ){
      
        helper = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/ttbar_diLept_madgraph*ext1*.root"; ch->Add(helper.c_str());
        helper = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/ttbar_singleLeptFrom*ext1*.root"; ch->Add(helper.c_str());
        helper = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/t_*.root"; ch->Add(helper.c_str());
        helper = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/tbar_*.root"; ch->Add(helper.c_str());
        /*helper = stopbabylocation+"ttbar_diLept_madgraph*ext1*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"ttbar_singleLeptFrom*ext1*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"t_*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_*.root"; ch->Add(helper.c_str());
        */  
   }
  else if( sample == "ttbar1l" ){
  }
  else if ( sample == "QCD"){
        helper = babylocation+"QCD*.root"; ch->Add(helper.c_str());
  }
    else if( sample == "ttv" ){
        helper = stopbabylocation+"TTZ*.root";ch->Add(helper.c_str());//ttv
        helper = stopbabylocation+"TTW*.root";ch->Add(helper.c_str());//ttv
  }
  else if( sample=="top"){
//        helper = stopbabylocation+"ST_tW_*.root";ch->Add(helper.c_str());//single top
        helper = stopbabylocation+"t_*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "ttw"){
      helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/TTWJetsToQQ_amcnlo_pythia8_25ns.root"; ch->Add(helper.c_str());
 }
else if (sample == "tZq"){
     helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/tZq_*.root"; ch->Add(helper.c_str());
 }
else if (sample == "ww"){
    //helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/WW*";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WWTo*";ch->Add(helper.c_str());
 }
else if (sample == "wz"){
    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/WZ*";ch->Add(helper.c_str());
 }
else if (sample == "zz"){
    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/ZZ*";ch->Add(helper.c_str());
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
