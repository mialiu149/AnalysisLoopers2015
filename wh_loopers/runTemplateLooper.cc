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
  /*
  string datalocation="/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/"; 
  string babylocation = "/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/";
  string stopbabylocation = "/nfs-6/userdata/mliu/onelepbabies/V80_13fb_v0/";
  */
  string datalocation="/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v14/output/"; 
  string babylocation = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/";
  string stopbabylocation = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/";
//  string datalocation="/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v21/output/";  
//  string babylocation="/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v21/output/";  
//  string stopbabylocation="/nfs-7/userdata/haweber/tupler_babies/merged/Stop_1l/v21/output/";  
//string stopbabylocation="/nfs-7/userdata/stopRun2/analysis2016__SUS-16-028__12p9fb/stopBabies__v8.0.x_v8__20160729/Nominal/";
  string helper;

  if ( sample == "jes_nominal_ttz"){
       helper = "/nfs-7/userdata/mliu/jes_nominal/TTZ*"; ch->Add(helper.c_str());
  }
  else if (sample == "ttbar_check"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/ttbar_diLept_madgraph_pythia8_ext1_25ns_2.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_225_75_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_225_75.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_250_1_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_250_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_250_1_noskim_old"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim/TChiWH_250_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_350_1_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond/TChiWH_350_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_300_75_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_300_75.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_400_1_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond/TChiWH_400_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_500_1_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_500_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_350_100_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_350_100.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_wh_500_125_noskim"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond_v1/TChiWH_500_125.root"; ch->Add(helper.c_str());
 }

  else if (sample == "wh_350_1"){
       helper = sigbabylocation+"SMS_tchwh_350_1.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_testscan"){
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
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v13/output/SMS_tchiwh*.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_tchwh_lnbb_jecup"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v13/output/SMS_tchiwh*.root"; ch->Add(helper.c_str());
 }
  else if (sample == "SMS_tchwh_lnbb_jecdown"){
       helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v13/output/SMS_tchiwh*.root"; ch->Add(helper.c_str());
 }
 else if (sample =="diboson"){
    helper  =stopbabylocation+"WWTo*";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo3LNu_powheg_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"WZTo2L2Q_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
    helper  =stopbabylocation+"ZZTo*";ch->Add(helper.c_str());
 }
  else if ( sample == "data" ){
        helper = datalocation+"data_single_electron_Run2016*.root"; ch->Add(helper.c_str());
        helper = datalocation+"data_single_muon_Run2016*.root"; ch->Add(helper.c_str());
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
//           helper = stopbabylocation+"WJetsToLNu_HT100To200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
//           helper = stopbabylocation+"WJetsToLNu_HT200To400*_ext1_*.root";ch->Add(helper.c_str());//ht binned
//           helper = stopbabylocation+"WJetsToLNu_HT400To600*ext*.root";ch->Add(helper.c_str());//ht binned
//           helper = stopbabylocation+"WJetsToLNu_HT600To800*.root";ch->Add(helper.c_str());//ht binned
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
          helper ="/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge/WJetsToLNu*.root";ch->Add(helper.c_str()); 
//           helper = stopbabylocation+"WJetsToLNu_HT1200To2500*.root";ch->Add(helper.c_str());//ht binned
//           helper = stopbabylocation+"WJetsToLNu_HT2500ToInf*ext1*.root";ch->Add(helper.c_str());//ht binned
  }
  else if( sample == "ws_ht100"){
        helper = stopbabylocation+"WJetsToLNu_madgraph_pythia8_25ns.root";ch->Add(helper.c_str());
  }
  else if( sample == "ws_ht100_tostitch"){
        helper = stopbabylocation+"WJetsToLNu_madgraph_pythia8_25ns.root";ch->Add(helper.c_str());
  }
  else if( sample == "ws_ht100_tostitch_200"){
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

  else if( sample == "w1jets"){        helper = stopbabylocation+"W1JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned
  else if( sample == "w2jets"){        helper = stopbabylocation+"W2JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w3jets"){        helper = stopbabylocation+"W3JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w4jets"){        helper = stopbabylocation+"W4JetsToLNu_madgraph*ext2*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w1jets_tostitch"){        helper = stopbabylocation+"W1JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned
  else if( sample == "w2jets_tostitch"){        helper = stopbabylocation+"W2JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w3jets_tostitch"){        helper = stopbabylocation+"W3JetsToLNu_madgraph*.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "w4jets_tostitch"){        helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge/W4JetsToLNu_madgraph_pythia8.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "ws_njets"){
        helper = stopbabylocation+"W1JetsToLNu_madgraph*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W2JetsToLNu_madgraph*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W3JetsToLNu_madgraph*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W4JetsToLNu_madgraph*.root";ch->Add(helper.c_str());//njets binned
        helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge/W4JetsToLNu_madgraph_pythia8.root";ch->Add(helper.c_str());}//njets binned}
  else if( sample == "ws_njets_tostitch"){
        helper = stopbabylocation+"W1JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W2JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W3JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
        helper = stopbabylocation+"W4JetsToLNu*.root";ch->Add(helper.c_str());//njets binned
  }
  else if(sample=="ws_htbin_tostitch"){
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper ="/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge/WJetsToLNu*.root";ch->Add(helper.c_str()); 
   }
  else if(sample=="ws_htbin_tostitch_200"){
           helper = stopbabylocation+"WJetsToLNu_HT800To1200*_ext1_*.root";ch->Add(helper.c_str());//ht binned
           helper ="/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge/WJetsToLNu*.root";ch->Add(helper.c_str()); 
   }
  else if( sample == "wzbb"){
        helper = stopbabylocation+"WZTo1LNu2Q_amcnlo*.root";ch->Add(helper.c_str());   
        ch->Add(helper.c_str());
  }
  else if( sample == "wzbb_jecup"){
        helper = "/hadoop/cms/store/user/mliu/onelepbabies//V80_13fb_v0_jecdn_WZTo1LNu2Q_amcnlo_pythia8_25ns/*root";ch->Add(helper.c_str());
  }
  else if( sample == "wzbb_jecdn"){
        helper = "/hadoop/cms/store/user/mliu/onelepbabies//V80_13fb_v0_jecup_WZTo1LNu2Q_amcnlo_pythia8_25ns/*root";ch->Add(helper.c_str());
  }
  else if( sample == "rare"){
        helper = stopbabylocation+"ttZ*.root";ch->Add(helper.c_str());//ttv
        helper = stopbabylocation+"tZq*.root";ch->Add(helper.c_str());//ttv
        helper = stopbabylocation+"ttW*.root";ch->Add(helper.c_str());//ttv
        helper  =stopbabylocation+"WWTo*powheg*";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns*.root";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo3LNu_powheg_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  ="/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WZTo2L2Q_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  = stopbabylocation+"ZZTo*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"WminusH*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"WplusH*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*WWW*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*WWZ*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*WZG*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*WZZ*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*ZZZ*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"*WWG*";ch->Add(helper.c_str());
 }
  else if( sample =="smWH"){
        helper  = stopbabylocation+"WminusH*";ch->Add(helper.c_str());
        helper  = stopbabylocation+"WplusH*";ch->Add(helper.c_str());
  }
  else if( sample == "triboson"){
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WWW*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WWG*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WWZ*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/WZZ*";ch->Add(helper.c_str());
        helper  = "/nfs-6/userdata/mliu/onelepbabies/V80_7p65_v2/ZZZ*";ch->Add(helper.c_str());
  }
  else if( sample == "ttbar2l" ){
        helper = stopbabylocation+"ttbar_diLept_madgraph*ext1*.root"; ch->Add(helper.c_str());
  }
  else if (sample =="ws_nupt200"){
        helper = babylocation+"W1JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = babylocation+"W2JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = babylocation+"W3JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
        helper = babylocation+"W4JetsToLNu_NuPt-200*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w1jets_nupt200"){
        helper = babylocation+"W1JetsToLNu_nupT200_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w1jets_nupt100"){
        helper = babylocation+"W1JetsToLNu_nupT100_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w2jets_nupt200"){
        helper = babylocation+"W2JetsToLNu_nupT200_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w2jets_nupt100"){
        helper = babylocation+"W2JetsToLNu_nupT100_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w3jets_nupt200"){
        helper = babylocation+"W3JetsToLNu_nupT200_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w3jets_nupt100"){
        helper = babylocation+"W3JetsToLNu_nupT100_*.root"; ch->Add(helper.c_str());
  }
  else if (sample == "w4jets_nupt200"){
        helper = babylocation+"W4JetsToLNu_nupT200_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "tops_mad" ){
        helper = stopbabylocation+"ttbar_diLept_madgraph*ext1*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"ttbar_singleLeptFrom*ext1*.root"; ch->Add(helper.c_str());
//        helper = stopbabylocation+"t_tW*pythia8_noHadDecays_25ns*ext1*.root"; ch->Add(helper.c_str());
//       helper = stopbabylocation+"t_tbarW*pythia8_noHadDecays_25ns*ext1*.root"; ch->Add(helper.c_str());
        helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge//t_tbarW_5f_powheg_pythia8_noHadDecays.root";ch->Add(helper.c_str());
        helper = "/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v10/output/extmerge//t_tW_5f_powheg_pythia8_noHadDecays.root";ch->Add(helper.c_str());
        helper = stopbabylocation+"t_tch_4f_powheg_pythia8_inclDecays_25ns*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"tbar_tch_4f_powheg_pythia8_inclDecays_25ns*.root"; ch->Add(helper.c_str());
        helper = stopbabylocation+"t_sch*.root"; ch->Add(helper.c_str());
   }
  else if( sample == "ttbar1l" ){
  }
  else if ( sample == "QCD"){
        helper = babylocation+"QCD*.root"; ch->Add(helper.c_str());
  }
    else if( sample == "ttv" ){
        helper = stopbabylocation+"ttZ*.root";ch->Add(helper.c_str());//ttv
        helper = stopbabylocation+"ttW*.root";ch->Add(helper.c_str());//ttv
  }
  else if( sample=="top"){
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
    helper  =stopbabylocation+"WWTo2l2Nu*";ch->Add(helper.c_str());
 }
else if (sample == "wz"){
        helper  =stopbabylocation+"WZTo1L3Nu_amcnlo_pythia8_25ns.root";ch->Add(helper.c_str());
        helper  =stopbabylocation+"WZTo3LNu_powheg_pythia8_25ns.root";ch->Add(helper.c_str());
    //helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/WZ*";ch->Add(helper.c_str());
 }
else if (sample == "zz"){
//    helper = "/hadoop/cms/store/user/jgwood/condor/stop_1l_babies/stop_babies__CMS3_V070411__BabyMaker_V0704X_v7__20151208/merged_files/ZZ*";ch->Add(helper.c_str());
        helper  =stopbabylocation+"ZZTo*";ch->Add(helper.c_str());
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
