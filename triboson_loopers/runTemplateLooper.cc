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

  //string baby_base = "/hadoop/cms/store/user/haweber/AutoTwopler_babies/WWW/merged/ZMET/WWW_vX/output/";
  //string skim_base = "/hadoop/cms/store/user/haweber/AutoTwopler_babies/WWW/merged/ZMET/WWW_vX/skim/";
  string baby_base = "/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.5/output/";
  string skim_base = "/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.5/skim/";
  string helper;

  if ( sample == "ttbar"){
       helper = skim_base+"ttbar_*mgmlm*_ext1_*"; ch->Add(helper.c_str());
  }
  else if (sample == "ttbar_dilep"){
       helper = skim_base+"ttbar_*dilep*mgmlm*_ext1_*"; ch->Add(helper.c_str());
 }
  else if (sample == "ttbar_onelep"){
       helper = skim_base+"ttbar_*1l*mgmlm*_ext1_*"; ch->Add(helper.c_str());
 }
  else if (sample =="ww"){
       helper = skim_base+"ww_*"; ch->Add(helper.c_str());
       helper = skim_base+"wpwpjj_ewk-qcd_madgraph_*"; ch->Add(helper.c_str());
 }
  else if (sample =="www"){
       helper = skim_base+"www_*incl*_1.root"; ch->Add(helper.c_str());
 }
  else if (sample =="www_2l_ext1"){
       helper = skim_base+"www_2l_ext1_mia_skim_1.root"; ch->Add(helper.c_str());
 }
  else if (sample =="www_2l_ext0"){
       helper = skim_base+"www_2l_mia_skim_1.root"; ch->Add(helper.c_str());
 }
  else if (sample =="wz"){
       helper = skim_base+"wz_*"; ch->Add(helper.c_str());
     //  helper = "/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.5/skim/wz_3lnu_powheg_skim_1.root"; ch->Add(helper.c_str());
 }
  else if (sample =="zz"){
       helper = skim_base+"zz_*"; ch->Add(helper.c_str());
 }
/*  else if ( sample == "data" ){
        helper = datalocation+"data_single_electron_Run2016*.root"; ch->Add(helper.c_str());
        helper = datalocation+"data_single_muon_Run2016*.root"; ch->Add(helper.c_str());
  }
 */ else if( sample == "zjets_htbin" ){
       helper = skim_base+"dy_m1050_mgmlm_*.root"; ch->Add(helper.c_str());
       helper = skim_base+"dy_m50_mgmlm_ht*"; ch->Add(helper.c_str());
  }
  else if(sample == "zjets_ht100"){
       helper = skim_base+"dy_m50_mgmlm_ext1_*.root"; ch->Add(helper.c_str());
  }
  else if(sample == "wjets_ht100"){
       helper = skim_base+"wjets_incl_mgmlm_*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "wjets_htbin" ){
       helper = skim_base+"wjets_ht*.root"; ch->Add(helper.c_str());
  }
  else if( sample == "ttv" ){
       helper = skim_base+"ttw_incl_*"; ch->Add(helper.c_str());
       helper = skim_base+"ttz_incl_*"; ch->Add(helper.c_str());
       helper = skim_base+"tth_bb_powheg*"; ch->Add(helper.c_str());
       helper = skim_base+"tth_nobb_powheg*"; ch->Add(helper.c_str());
       helper = skim_base+"ttg_incl_amcnlo_*.root"; ch->Add(helper.c_str());
  }
   else if( sample == "vgamma" ){
       helper = skim_base+"wgjets_ptg*"; ch->Add(helper.c_str());
  }
   else if( sample == "singletop" ){
       helper = skim_base+"stt_*powheg*"; ch->Add(helper.c_str());
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
