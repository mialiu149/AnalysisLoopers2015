#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Math/VectorUtil.h"

#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TH1D.h"
#include "TMath.h"

#include "templateLooper.h"
#include "../sharedCode/V80_00.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/WHSelection.h"
#include "../sharedCode/GenSelection.h"
#include "../sharedCode/AnalysisUtils.h"
#include "../sharedCode/EventTypeSel.h"
#include "../stop_variables/MT2_implementations.h"
#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"

using namespace std;
using namespace duplicate_removal;
using namespace V80_00_np;
using namespace whsel;
using namespace gensel; 

const bool debug = false;
const bool usejson = true;
const bool dovtxreweighting = false;
const bool applybtagsf = true;
const bool applytriggerweight = true;
const bool applylepsf = true;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::bookHistos(std::string region){
  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
//  leptype.push_back("el"); //currently not setup to run on this.
///  leptype.push_back("mu");
  leptype.push_back("lep");
  leptype.push_back("lep_onelep");
  leptype.push_back("lep_dilep");
  leptype.push_back("lep_HF");
  leptype.push_back("lep_LF");
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;             vector <float> variable_bins;
  variable.push_back("ptl1");           variable_bins.push_back(1000);  
  variable.push_back("pt_ISR");         variable_bins.push_back(1000);  
  variable.push_back("ptl1_pass");      variable_bins.push_back(1000);  
  variable.push_back("ptb1");           variable_bins.push_back(1000);  
  variable.push_back("ptb2");           variable_bins.push_back(1000);  
  variable.push_back("ptbb");           variable_bins.push_back(1000);  
  variable.push_back("ptlbb");          variable_bins.push_back(1000);  
  variable.push_back("met");            variable_bins.push_back(1000);  
  variable.push_back("met_pass");       variable_bins.push_back(1000);  
  variable.push_back("ht");	        variable_bins.push_back(1000);  
  variable.push_back("mt");	        variable_bins.push_back(1000);  
  variable.push_back("mt_0btag");	variable_bins.push_back(1000);  
  variable.push_back("mt_2btag");	variable_bins.push_back(1000);  
  variable.push_back("mbb");	        variable_bins.push_back(1500);  
  variable.push_back("MCT");	        variable_bins.push_back(1000);  
  variable.push_back("MCT_0btag");	variable_bins.push_back(1000);  
  variable.push_back("MCT_2btag");      variable_bins.push_back(1000);  
  variable.push_back("relIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("nhiso");	        variable_bins.push_back(1000);  
  variable.push_back("emiso");	        variable_bins.push_back(1000);  
  variable.push_back("MT2W");	        variable_bins.push_back(1000);  
  variable.push_back("dphi_Wlep");	variable_bins.push_back(1000);  
  variable.push_back("MT2lb");          variable_bins.push_back(1000);  
  variable.push_back("njets");               variable_bins.push_back(20  );  
  variable.push_back("nbjets_gen");          variable_bins.push_back(20  );  
  variable.push_back("ngenbjets_0btag");     variable_bins.push_back(20  );  
  variable.push_back("ngenbjets_1btag");     variable_bins.push_back(20  );  
  variable.push_back("ngenbjets_2btag");     variable_bins.push_back(20  );  
  variable.push_back("nbjets");              variable_bins.push_back(20  );  
  variable.push_back("nVert");               variable_bins.push_back(50  );  
  variable.push_back("ptb1overptb2");        variable_bins.push_back(10  );

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < variable.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype.at(lepind).c_str(),
						object.at(objind).c_str(),
					        variable.at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					        variable .at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   static_cast<int>(variable_bins.at(varind)),
				   0.0,
				   variable_bins.at(varind));
		}
	  }
     }
  }

 //phi and eta plots, they have the same x and y limits.
  vector <string> phivars;
  phivars.push_back("metphi");
  phivars.push_back("dphibb");
  phivars.push_back("dphibMET");
  phivars.push_back("dRbb");
  phivars.push_back("deltaphi_lep_met");
  phivars.push_back("deltaphi_lep_leadb");
  phivars.push_back("deltaphi_leadb_met");
  phivars.push_back("mindphi_met_j1_j2");
  phivars.push_back("nbjets_diff");
  phivars.push_back("dR_lep_leadb");
 
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < phivars.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					        phivars  .at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					        phivars  .at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   200   ,
				   -3.2  ,
				   3.2   );
		}
	  }
	}
  }

  //----------------------// 
  // book counting hists  //
  //----------------------//

  vector <string> genvars;
  genvars.push_back("gen_H");
  genvars.push_back("gen_W");
  genvars.push_back("gen_lep");
  genvars.push_back("gen_b");
  genvars.push_back("gen_ch");
  genvars.push_back("gen_n2");
  genvars.push_back("gen_lsp");
 
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < genvars.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					        genvars  .at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					        genvars  .at(varind).c_str(),
					        selection.at(selind).c_str()
						),
				   10    ,
				   -0.5  ,
				   9.5   );
		} // end of selection loop
	   } // end of variable
	} //end of object loop
  }//end of loop over leptons

  // some gen level variables
  bookHist("h_gen_sys_pt", "h_gen_sys_pt", 1000,0,1000);
  bookHist("h_gen_b_pt", "h_gen_b_pt", 1000,0,1000);
  bookHist("h_gen_nu_pt", "h_gen_nu_pt", 1000,0,1000);
  bookHist("h_gen_met", "h_gen_met", 1000,0,1000);
  bookHist("h_gen_mt", "h_gen_mt", 1000,0,1000);
  bookHist("h_gen_mt_up", "h_gen_mt_up", 1000,0,1000);
  bookHist("h_gen_mt_dn", "h_gen_mt_dn", 1000,0,1000);
  bookHist("h_reco_mt", "h_reco_mt", 1000,0,1000);
  bookHist("h_reco_mt_up", "h_reco_mt_up", 1000,0,1000);
  bookHist("h_reco_mt_dn", "h_reco_mt_dn", 1000,0,1000);
  bookHist("h_gen_w_mass", "h_gen_w_mass", 1000,0,1000);
  bookHist("h_gen_h_mass", "h_gen_h_mass", 1000,0,1000);
  bookHist("h_gen_w_mass_up", "h_gen_w_mass_up", 1000,0,1000);
  bookHist("h_gen_w_mass_dn", "h_gen_w_mass_dn", 1000,0,1000);
  bookHist("h_gen_lsp_mass", "h_gen_lsp_mass", 1000,0,1000);
  bookHist("h_gen_n2_mass", "h_gen_n2_mass", 1000,0,1000);
  bookHist("h_gen_ch_mass", "h_gen_ch_mass", 1000,0,1000);


  //--------------------// 
  // book Cutflow hists //
  //--------------------//
  vector<string> histonames_cutflow; histonames_cutflow.clear();
  histonames_cutflow.push_back("NEventsSR");
  histonames_cutflow.push_back("NEventsSROneBin");
  histonames_cutflow.push_back("NEventsSRMultiBin");
  histonames_cutflow.push_back("NEvents1lCR");
  histonames_cutflow.push_back("NEvents2lCR");
  histonames_cutflow.push_back("NEventsmbbCR");
  histonames_cutflow.push_back("NEventsSRCutflow");
  histonames_cutflow.push_back("NEvents2lCRCutflow");
  histonames_cutflow.push_back("NEvents1lCRCutflow");
  histonames_cutflow.push_back("NEventsMtBulkCutflow");

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
		for( unsigned int selind = 0; selind < histonames_cutflow.size(); selind++ ){
                string histoname = "h_"+leptype.at(lepind)+"_event_"+histonames_cutflow.at(selind);
                histos_cutflow[histoname] = new TH1D(histoname.c_str(),histoname.c_str(),25,0.5,25.5);
                histos_cutflow[histoname]->Sumw2();
		}
  }

 //---------------------------------------------------------//
 //                 2-D plots booked here                   //
 //---------------------------------------------------------//
 
  histMCTvsMT  = new TH2F( "h_histMCTvsMT", "h_histMCTvsMT", 1000,0,1000,1000,0,1000); histMCTvsMT->Sumw2();
  histMCTvsMET = new TH2F( "h_histMCTvsMET", "h_histMCTvsMET", 1000,0,1000,1000,0,1000); histMCTvsMET->Sumw2();
  histMCTvsMbb = new TH2F( "h_histMCTvsMbb", "h_histMCTvsMbb", 1000,0,1000,1000,0,1000); histMCTvsMbb->Sumw2();
  histscan = new TH3D( "h_histscan", "h_histscan", 24,124,724,15,-1,374,25,0.5,25.5); histscan->Sumw2();
  histscan_genmet = new TH3D( "h_histscan_genmet", "h_histscan_genmet", 24,124,724,15,-1,374,25,0.5,25.5); histscan_genmet->Sumw2();
  histscan_pdfup = new TH3D( "h_histscan_pdfup", "h_histscan_pdfup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_pdfup->Sumw2();
  histscan_pdfdn = new TH3D( "h_histscan_pdfdn", "h_histscan_pdfdn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_pdfdn->Sumw2();
  histscan_scaleup = new TH3D( "h_histscan_scaleup", "h_histscan_scaleup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_scaleup->Sumw2();
  histscan_scaledn = new TH3D( "h_histscan_scaledn", "h_histscan_scaledn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_scaledn->Sumw2();
  histscan_btagsfup = new TH3D( "h_histscan_btagsfup", "h_histscan_btagsfup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_btagsfup->Sumw2();
  histscan_btagsfdn = new TH3D( "h_histscan_btagsfdn", "h_histscan_btagsfdn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_btagsfdn->Sumw2();
  histscan_lepsfup = new TH3D( "h_histscan_lepsfup", "h_histscan_lepsfup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_lepsfup->Sumw2();
  histscan_lepsfdn = new TH3D( "h_histscan_lepsfdn", "h_histscan_lepsfdn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_lepsfdn->Sumw2();
  histscan_isrnom = new TH3D( "h_histscan_isrnom", "h_histscan_isrnom", 24,124,724,15,-1,374,25,0.5,25.5); histscan_isrnom->Sumw2();
  histscan_isrup = new TH3D( "h_histscan_isrup", "h_histscan_isrup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_isrup->Sumw2();
  histscan_isrdn = new TH3D( "h_histscan_isrdn", "h_histscan_isrdn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_isrdn->Sumw2();
  histscan_trigup = new TH3D( "h_histscan_trigup", "h_histscan_trigup", 24,124,724,15,-1,374,25,0.5,25.5); histscan_trigup->Sumw2();
  histscan_trigdn = new TH3D( "h_histscan_trigdn", "h_histscan_trigdn", 24,124,724,15,-1,374,25,0.5,25.5); histscan_trigdn->Sumw2();
  
}

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

 // if( is_data() )             cout << "Running on Data."        << endl;
 // else                        cout << "Running on MC.  "        << endl;

  double nel = 0;
  double nmu = 0;
  double nemu = 0;

  double nem_2jets = 0;
  double nem_2jets_mll = 0;
  double npass = 0;

  cout<<selection<<endl;
  if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : begin scan chain  " <<endl;
  bookHistos(selection.c_str());  
  if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : booked histograms " <<endl;
  
  // do this once per job
  const char* json_file ="Cert_271036-274443_13TeV_PromptReco_Collisions16_JSON.txt";
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
//  set_goodrun_file(json_file);
/*   eventFilter metFilterTxt;
   if ( TString(sample).Contains("data") ) {
    cout<<"Loading bad event files ..."<<endl;
    // old lists for partial dataset
    // add from hj email
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/csc2015_Dec01.txt");
    cout<<" ... finished!"<<endl;
  } 
*/
  //---------------------------------------------------//
  //         read reweighting/counter hists            //
  //---------------------------------------------------//
  TH1F * h_vtxweight = NULL;
  TFile * f_vtx = NULL;
  TH1F * h_xsecweight = NULL;
  TFile * f_xsec = NULL;
  TH3D * h_scanSys = NULL;
  TH2D * h_scanN = NULL;
  
  TFile * f_scanSys = NULL;
  TH1F * h_trig_el = NULL;
  TH1F * h_trig_el_ee = NULL;
  TFile * f_trig_el = NULL;
  TH1F * h_trig_mu_eb = NULL;
  TH1F * h_trig_mu_ee = NULL;
  TFile * f_trig_mu = NULL;
  TH1F * h_trig_el_eb_veto = NULL;
  TH1F * h_trig_el_ee_veto = NULL;
  TFile * f_trig_el_veto = NULL;
  TH1F * h_trig_mu_eb_veto = NULL;
  TH1F * h_trig_mu_ee_veto = NULL;
  TFile * f_trig_mu_veto = NULL;

  if( dovtxreweighting ){
	f_vtx = TFile::Open("inputhists/nvtx_ratio.root","READ");
	h_vtxweight = (TH1F*)f_vtx->Get("h_vtx_ratio")->Clone("h_vtxweight");
	h_vtxweight->SetDirectory(rootdir);
	f_vtx->Close();
  }

//  if( runsigscan ){
       if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : get signal scan counting histogram " <<endl;
        f_xsec = TFile::Open("inputhists/xsec_susy_13tev.root","READ");
        h_xsecweight = (TH1F*)f_xsec->Get("h_xsec_c1n2")->Clone("h_xsecweight");
        h_xsecweight->SetDirectory(rootdir);
        f_xsec->Close(); 
	f_scanSys = TFile::Open("/nfs-6/userdata/mliu/onelepbabies/V80_signalscanv3/SMS_tchwh_lnbb.root","READ");
	h_scanSys = (TH3D*)f_scanSys->Get("h_counterSMS")->Clone("h_scanSys");
	h_scanN = (TH2D*)f_scanSys->Get("histNEvts")->Clone("h_scanN");
	h_scanSys->SetDirectory(rootdir);
	h_scanN->SetDirectory(rootdir);
	f_scanSys->Close();
       if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" :....finished..... " <<endl;
//  }
  if( applytriggerweight){
       f_trig_el = TFile::Open("inputhists/trigeff_El.root","READ");
       h_trig_el = (TH1F*)f_trig_el->Get("h_pt_effi_eb_ele27WPLoose")->Clone("h_trig_el");
       h_trig_el->SetDirectory(rootdir);
       h_trig_el_ee = (TH1F*)f_trig_el->Get("h_pt_effi_ee_ele27WPLoose")->Clone("h_trig_el_ee");
       h_trig_el_ee->SetDirectory(rootdir);
       f_trig_el->Close();
       f_trig_mu = TFile::Open("inputhists/trigeff_Mu.root","READ");
       h_trig_mu_eb = (TH1F*)f_trig_mu->Get("h_pt_effi_eb_ele27WPLoose")->Clone("h_trig_mu_eb");
       h_trig_mu_ee = (TH1F*)f_trig_mu->Get("h_pt_effi_ee_ele27WPLoose")->Clone("h_trig_mu_ee");
       h_trig_mu_eb->SetDirectory(rootdir);
       h_trig_mu_ee->SetDirectory(rootdir);
       f_trig_mu->Close();
       f_trig_el_veto = TFile::Open("inputhists/trigeff_El_Veto.root","READ");
       h_trig_el_eb_veto = (TH1F*)f_trig_el_veto->Get("h_pt_effi_eb_ele27WPLoose")->Clone("h_trig_el_eb_veto");
       h_trig_el_ee_veto = (TH1F*)f_trig_el_veto->Get("h_pt_effi_ee_ele27WPLoose")->Clone("h_trig_el_ee_veto");
       h_trig_el_eb_veto->SetDirectory(rootdir);
       h_trig_el_ee_veto->SetDirectory(rootdir);
       f_trig_el_veto->Close();
       f_trig_mu_veto = TFile::Open("inputhists/trigeff_Mu_Veto.root","READ");
       h_trig_mu_eb_veto = (TH1F*)f_trig_mu_veto->Get("h_pt_effi_eb_ele27WPLoose")->Clone("h_trig_mu_eb_veto");
       h_trig_mu_ee_veto = (TH1F*)f_trig_mu_veto->Get("h_pt_effi_ee_ele27WPLoose")->Clone("h_trig_mu_ee_veto");
       h_trig_mu_eb_veto->SetDirectory(rootdir);
       h_trig_mu_ee_veto->SetDirectory(rootdir);
       f_trig_mu_veto->Close();
 }
  TObjArray *listOfFiles = chain->GetListOfFiles();
  unsigned int nEventsChain = 0;
  unsigned int nEvents = chain->GetEntries();
  nEventsChain = nEvents;
  unsigned int nEventsTotal = 0;
  unsigned int nDuplicates = 0;

  if(debug) cout << "Begin file loop" << endl;

  // file loop
  TIter fileIter(listOfFiles);
  TFile* currentFile = 0;
  while ( (currentFile = (TFile*) fileIter.Next()) ){

	TFile f(currentFile->GetTitle());
    TTree *tree = dynamic_cast<TTree*>(f.Get("t"));
    v80_00.Init(tree);
    // event loop
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  v80_00.GetEntry(event);
          ++nEventsTotal;
          //   continue;
	  if (nEventsTotal % 100000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
                printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
                fflush(stdout);
           } 
          }
        
         float genmetpt;
	 float weight = 1.0;
          // fix k-factors for MC samples 
         if( !is_data()) {
          genmetpt = gensel::gennuptw();
          if(TString(sample).Contains("ws_ht100")&&(genht()>100)) continue; //stitch samples
          if(TString(sample).Contains("ws_ht100_tostitch")&&(genht()>100||genmetpt>200)) continue; //stitch samples
          if(TString(sample).Contains("ws_njets_tostitch")&&genmetpt>200) continue; //stitch samples
          if( sample == "ws_njets") weight *= 1.23/kfactor();
          if( sample == "w1jets") {weight *= 1.238/kfactor(); if(genmetpt>200) continue;}
          if( sample == "w2jets") {weight *= 1.231/kfactor(); if(genmetpt>200) continue;}
          if( sample == "w3jets") {weight *= 1.231/kfactor(); if(genmetpt>200) continue;}
          if( sample == "w4jets") {weight *= 1.144/kfactor(); if(genmetpt>200) continue;}
          if( sample == "w1jets_nupt200") {weight *= 9.328793e+00/kfactor(); if(genmetpt<200) continue;}
          if( sample == "w2jets_nupt200") {weight *= 5.173081e+00/kfactor(); if(genmetpt<200) continue;}
          if( sample == "w3jets_nupt200") {weight *= 8.315804e+00/kfactor();  if(genmetpt<200) continue;}
          if( sample == "w4jets_nupt200") {weight *= 26.524/1.485/kfactor(); if(genmetpt<200) continue;}
	 if(TString(sample).Contains("ws_htbin_tostitch")&&genmetpt>200) continue; //stitch samples
         }
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
	  //         MET filter, trigger and json      //
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
//	  if ( is_data() && usejson && !goodrun(run(), ls()) ) continue;
          if (is_data() &&!filt_met())   continue;
          if (is_data() &&!(HLT_SingleMu()|| HLT_SingleEl() || HLT_SingleMuNoIso()))   continue;
          if (is_data() &&!filt_cscbeamhalo2015())   continue;
          if (is_data() &&!filt_badMuonFilter())   continue;
          if (is_data() &&!filt_badChargedCandidateFilter())   continue;
 
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//

	  if( is_data() ) {
		DorkyEventIdentifier id(run(), evt(), ls());
        	if (is_duplicate(id) ){
		  ++nDuplicates;
		  continue;
		}
          }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : removed duplicates   " <<endl;

	  //~-~-~-~-~-~-~-~~-~-~-//
	  //    primary vertex   //
	  //~-~-~-~-~-~-~-~-~-~-//

	   if(nvtxs()<0)               continue;

	  //~-~-~-~-~-~-~-~~-~-~-~--~//
	  //    split emu plot       //
	  //~-~-~-~-~-~-~-~-~-~-~-~-~//
	   bool ismu = false; bool isel = false;
 	   if( abs(lep1_pdgid()) == 13) {nmu++;ismu=true;}
	   if( abs(lep1_pdgid()) == 11) {nel++;isel=true;}
           if( TString(selection).Contains("muonly") && abs(lep1_pdgid()) != 13)  continue;
           if( TString(selection).Contains("ebonly") && abs(lep1_p4().eta())>1.2 )  continue;
           if( TString(selection).Contains("eeonly") && abs(lep1_p4().eta())<1.2 )  continue;
           if( TString(selection).Contains("elonly") && abs(lep1_pdgid()) != 11)  continue;
           
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//

          float lumi = 27.2;
          float trigeff = 1;
          float triglep1 = 1;
          float triglep2 = 1;

	  if( is_data() || TString(sample).Contains("SMS")){
		weight = 1.0;
	   } else if( !is_data() && !TString(selection).Contains("SMS")){
                  weight = scale1fb();//event_weight(selection.c_str());
                  if( TString(selection).Contains("yield"))  weight *= lumi;//scale by lumi
                  //scale1fb for signals
                  if( TString(sample).Contains("wh_350")) weight *= 0.00128300190114;
                  if( TString(sample).Contains("wh_300")) weight *= 0.00206056387342;
                  if( TString(sample).Contains("wh_250")) weight *= 0.00497616088593;
                  if( TString(sample).Contains("wh_225")) weight *= 0.00579149982859;
	  }
	  if( !is_data() && dovtxreweighting ){	
    	         weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(nvtxs()));		
	  }
          if( !is_data() && applybtagsf){
                 if(TString(selection).Contains("btagsfup")) weight *= weight_btagsf_heavy_UP();
                 else if(TString(selection).Contains("btagsfdn")) weight *= weight_btagsf_heavy_DN();
                 else weight *= weight_btagsf();
          }
          if( !is_data() && applylepsf) {
                  weight *= weight_lepSF()*weight_vetoLepSF();
           }
          if( !is_data() && applytriggerweight) {
    	         if(abs(lep1_pdgid()) == 11){ 
                   if(lep1_p4().pt()<500) triglep1*= h_trig_el->GetBinContent(h_trig_el->FindBin(lep1_p4().pt()));		
                   else  triglep1*= h_trig_el->GetBinContent(h_trig_el->FindBin(400));
                 }
    	         if(abs(lep1_pdgid()) == 13){
                   if(abs(lep1_p4().eta()) < 1.2) {
                   if(lep1_p4().pt()<500) triglep1*= h_trig_mu_eb->GetBinContent(h_trig_mu_eb->FindBin(lep1_p4().pt()));		
                   else  triglep1*= h_trig_mu_eb->GetBinContent(h_trig_mu_eb->FindBin(400));
                   }
                   else {
                   if(lep1_p4().pt()<500) triglep1*= h_trig_mu_ee->GetBinContent(h_trig_mu_ee->FindBin(lep1_p4().pt()));		
                   else  triglep1*= h_trig_mu_ee->GetBinContent(h_trig_mu_ee->FindBin(400));
                   }
                 }
            // lep2 is good electron
    	         if(abs(lep2_pdgid()) == 11 && lep2type()==1) {
                 if(abs(lep2_p4().eta()) < 1.442) {
                    if(lep2_p4().pt()<500) triglep2*= h_trig_el->GetBinContent(h_trig_el->FindBin(lep2_p4().pt()));		
                    else triglep2 *= h_trig_el->GetBinContent(h_trig_el->FindBin(400));
                 }
                 else {
                    if(lep2_p4().pt()<500) triglep2*= h_trig_el_ee->GetBinContent(h_trig_el_ee->FindBin(lep2_p4().pt()));		
                    else triglep2 *= h_trig_el_ee->GetBinContent(h_trig_el_ee->FindBin(400));
                   }
                }
            // lep2 is a veto electron`
    	         if(abs(lep2_pdgid()) == 11 && lep2type()==2) {
                 if(abs(lep2_p4().eta()) < 1.442) {
                    if(lep2_p4().pt()<500) triglep2*= h_trig_el_eb_veto->GetBinContent(h_trig_el_eb_veto->FindBin(lep2_p4().pt()));		
                    else triglep2 *= h_trig_el_eb_veto->GetBinContent(h_trig_el_eb_veto->FindBin(400));
                 }
                 else {
                    if(lep2_p4().pt()<500) triglep2*= h_trig_el_ee_veto->GetBinContent(h_trig_el_ee_veto->FindBin(lep2_p4().pt()));		
                    else triglep2 *= h_trig_el_ee_veto->GetBinContent(h_trig_el_ee_veto->FindBin(400));
                   }
                }
            // lep2 is good muon
    	         if(abs(lep2_pdgid()) == 13 && lep2type()==1){
                   if(abs(lep2_p4().eta()) < 1.2) {
                   if(lep2_p4().pt()<500) triglep2*= h_trig_mu_eb->GetBinContent(h_trig_mu_eb->FindBin(lep2_p4().pt()));		
                   else  triglep2*= h_trig_mu_eb->GetBinContent(h_trig_mu_eb->FindBin(400));
                   }
                   else {
                   if(lep2_p4().pt()<500) triglep2*= h_trig_mu_ee->GetBinContent(h_trig_mu_ee->FindBin(lep2_p4().pt()));		
                   else  triglep2*= h_trig_mu_ee->GetBinContent(h_trig_mu_ee->FindBin(400));
                   }
                 }
            // lep2 is veto muon
    	         if(abs(lep2_pdgid()) == 13 && lep2type()==2){
                   if(abs(lep2_p4().eta()) < 1.2) {
                   if(lep2_p4().pt()<500) triglep2*= h_trig_mu_eb_veto->GetBinContent(h_trig_mu_eb_veto->FindBin(lep2_p4().pt()));		
                   else  triglep2*= h_trig_mu_eb_veto->GetBinContent(h_trig_mu_eb_veto->FindBin(400));
                   }
                   else {
                   if(lep2_p4().pt()<500) triglep2*= h_trig_mu_ee_veto->GetBinContent(h_trig_mu_ee_veto->FindBin(lep2_p4().pt()));		
                   else  triglep2*= h_trig_mu_ee_veto->GetBinContent(h_trig_mu_ee_veto->FindBin(400));
                   }
                 }

               if(TString(selection).Contains("2lCR")) trigeff = 1-(1-triglep1)*(1-triglep2) ; else trigeff = triglep1;
                weight*= trigeff;
          }
          
          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //    calculate the right weights for scan    // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
	  float c1mass = -999;
          float n1mass = -999;
          float sigweight = 1;
          float xsec =1;
          float btagsfup = 1;
          float btagsfdn = 1;
          float lepsfup = 1;
          float lepsfdn = 1;
          float pdfup = 1;
          float pdfdn = 1;
          float scaleup = 1;
          float scaledn = 1;
          float isrnom =1;
          float isrup =1;
          float isrdn =1;
          int   c1massbin = 0;
          int   n1massbin = 0;
          float trigup =1;
          float trigdn =1;

          if(TString(sample).Contains("SMS") && !TString(selection).Contains("SMS")){
             c1mass = mass_chargino(); 
             n1mass = mass_lsp();
             xsec  = h_xsecweight->GetBinContent(h_xsecweight->FindBin(c1mass));
             c1massbin = h_scanN->GetXaxis()->FindBin(c1mass);
             n1massbin = h_scanN->GetYaxis()->FindBin(n1mass);
           // xsec weight
             sigweight = 1/(h_scanN->GetBinContent(c1massbin,n1massbin))*lumi*xsec*0.58*0.3*1000; // lumi*xsec*branchratio(0.58*0.3*pb/fb)
             weight*=sigweight;
           //btag variations
             btagsfup = 1/weight_btagsf()*weight_btagsf_fastsim_UP()/h_scanSys->GetBinContent(c1massbin,n1massbin,22)*h_scanSys->GetBinContent(c1massbin,n1massbin,14);//need to add normalization
             btagsfdn = 1/weight_btagsf()*weight_btagsf_fastsim_DN()/h_scanSys->GetBinContent(c1massbin,n1massbin,23)*h_scanSys->GetBinContent(c1massbin,n1massbin,14);//need to add normalization
           //lepton SF
             lepsfup = weight_lepSF_fastSim_up();
             lepsfdn = weight_lepSF_fastSim_down();
             if(abs(lep1_pdgid()) == 13) {lepsfup = 1.03;lepsfdn = 0.97;}  /// for ichep, fix 3% for muons
           //pdfs
             pdfup = pdf_up_weight();  
             pdfdn = pdf_down_weight();  
           //scale
             scaleup = genweights()[109]+1;  
             scaledn = genweights()[110]+1;  
           //isr uncern
             isrup = weight_ISRup(); 
             isrdn = weight_ISRdown(); 
            //trigger eff
             if(ismu){
              if(lep1_p4().pt()<100&&abs(lep1_p4().eta())<1.2) {trigup = 1.01;trigdn=0.99;}
              if(lep1_p4().pt()>100&&abs(lep1_p4().eta())<1.2) {trigup = 1.03;trigdn=0.97;}
              if(abs(lep1_p4().eta())>1.2){
                 if(lep1_p4().pt()<100) {trigup = 1.03;trigdn=0.97;}
                 if(lep1_p4().pt()<200&&lep1_p4().pt()>100) {trigup = 1.1;trigdn=0.9;}
                 if(lep1_p4().pt()<300&&lep1_p4().pt()>200) {trigup = 1.15;trigdn=0.85;}
              }
             if(isel){
               if(lep1_p4().pt()<35&&lep1_p4().pt()>30||lep1_p4().pt()>100) {trigup = 1.03;trigdn=0.97;}
                if(lep1_p4().pt()<100&&lep1_p4().pt()>35) {trigup = 1.01;trigdn=0.99;}
              }
             }
           }

          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //    fill cutflows and counters  // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
	  string histname = "dummy";
	  string version = "dummy";
           if( TString(selection).Contains("V0")) version = "v0";
           if( TString(selection).Contains("V1")) version = "v1";
           if( TString(selection).Contains("V2")) version = "v2";
           if( TString(selection).Contains("V3")) version = "v3";
           if( TString(selection).Contains("V4")) version = "v4";
           if( TString(selection).Contains("V5")) version = "v5";
           if( TString(selection).Contains("V6")) version = "v6";
           if( TString(selection).Contains("V7")) version = "v7";
           if( TString(selection).Contains("V8")) version = "v8";

          if(TString(selection).Contains("cutflow")){
          //if(TString(sample).Contains("SMS")&&(c1mass !=250||n1mass !=1)) continue;
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : cutflow" <<endl;
           histname = Form("h_%s_event_NEventsSRCutflow","lep");
          histos_cutflow[histname]->Fill(1,weight);                               //Nevents in the skim
          histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passcutflow("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(passcutflow("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(passcutflow("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(passcutflow("step4"))  histos_cutflow[histname]->Fill(6,weight); //two jets
          if(passcutflow("step5"))  histos_cutflow[histname]->Fill(7,weight); //two b tagged
          if(passcutflow("step6"))  histos_cutflow[histname]->Fill(8,weight); //met
          if(passcutflow("step7"))  histos_cutflow[histname]->Fill(9,weight); //
          if(passcutflow("step8"))  histos_cutflow[histname]->Fill(10,weight); //mt
          if(passcutflow("step9_genmet"))  histos_cutflow[histname]->Fill(11,weight); //mbb
          if(passcutflow("step10_genmet"))  histos_cutflow[histname]->Fill(12,weight); //mct
          histname = Form("h_%s_event_NEvents2lCRCutflow","lep");
          histos_cutflow[histname]->Fill(1,weight);                          //Nevents in the skim
          if(passcutflow("step0")) histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passcutflow("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(!passcutflow("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(!passcutflow("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(!passcutflow("step4"))  histos_cutflow[histname]->Fill(6,weight); //tau veto
          histname = Form("h_%s_event_NEvents1lCRCutflow","lep");
          histos_cutflow[histname]->Fill(1,weight);                               //Nevents in the skim
          if(passcutflow("step0")) histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passcutflow("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(passcutflow("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(passcutflow("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(passcutflow("step4"))  histos_cutflow[histname]->Fill(6,weight); //tau veto
          histname = Form("h_%s_event_NEventsMtBulkCutflow","lep");
          histos_cutflow[histname]->Fill(1,weight);                               //Nevents in the skim
          if(passPreselection("step0")) histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passPreselection("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(passPreselection("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(passPreselection("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(passPreselection("step4"))  histos_cutflow[histname]->Fill(6,weight); //tau veto
          continue;
          }

           if(TString(selection).Contains("SROneBin_yield")){ // this is for ichep,can be replaced by multibin hists 
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           //signal
           histname = Form("h_%s_event_NEventsSROneBin","lep");
           if(passSR(selection.c_str())) histos_cutflow[histname]->Fill(1,weight);
           if( is2lep()) {
           histname = Form("h_%s_event_NEventsSROneBin","lep_dilep");
           if(passSR(selection.c_str())) histos_cutflow[histname]->Fill(1,weight);
          }
           if( is1lep()) {
           histname = Form("h_%s_event_NEventsSROneBin","lep_onelep");
           if(passSR(selection.c_str())) histos_cutflow[histname]->Fill(1,weight);
          }
           if( gensel::isHF()){
           histname = Form("h_%s_event_NEventsSROneBin","lep_HF");
           if(passSR(selection.c_str())) histos_cutflow[histname]->Fill(1,weight);
          }
           if( !gensel::isHF()){
           histname = Form("h_%s_event_NEventsSROneBin","lep_LF");
           if(passSR(selection.c_str())) histos_cutflow[histname]->Fill(1,weight);
          }
           continue;
          }

           if(TString(selection).Contains("SRMultiBin")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           if(!passSR(selection.c_str()))   continue;

          for (int binn = 1; binn < 5; binn ++){
           histname = Form("h_%s_event_NEventsSRMultiBin","lep");
           string binstring = to_string(binn);
           if(passSR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           if( is2lep()) {
           histname = Form("h_%s_event_NEventsSRMultiBin","lep_dilep");
           if(passSR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( is1lep()) {
           histname = Form("h_%s_event_NEventsSRMultiBin","lep_onelep");
           if(passSR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( gensel::isHF() ){
           histname = Form("h_%s_event_NEventsSRMultiBin","lep_HF");
           if(passSR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( !gensel::isHF() ){
           histname = Form("h_%s_event_NEventsSRMultiBin","lep_LF");
           if(passSR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
                continue;
           } // loop over bins
          } //yield for multiple bins
           // 3D hists for signal scan //
          string region = selection;
          if(TString(selection).Contains("SRMultiBin") ){ 
          for (int binn = 1; binn < 5; binn ++){
             string binstring = to_string(binn);
             if(passSR(Form("SMS_SR_met100_mt150_mbb_mct150_twobtag_metbin%s%s",binstring.c_str(),version.c_str()))) {
             histscan->Fill(c1mass,n1mass,binn,weight);   // nominal yield;
             histscan_pdfup->Fill(c1mass,n1mass,binn,weight*pdfup);
             histscan_pdfdn->Fill(c1mass,n1mass,binn,weight*pdfdn);
             histscan_scaleup->Fill(c1mass,n1mass,binn,weight*scaleup);
             histscan_scaledn->Fill(c1mass,n1mass,binn,weight*scaledn);
             histscan_btagsfup->Fill(c1mass,n1mass,binn,weight*btagsfup);
             histscan_btagsfdn->Fill(c1mass,n1mass,binn,weight*btagsfdn);
             histscan_lepsfup->Fill(c1mass,n1mass,binn,weight*lepsfup);
             histscan_lepsfdn->Fill(c1mass,n1mass,binn,weight*lepsfdn);
             histscan_trigup->Fill(c1mass,n1mass,binn,weight*trigup);
             histscan_trigdn->Fill(c1mass,n1mass,binn,weight*trigdn);
             histscan_isrnom->Fill(c1mass,n1mass,binn,weight*isrnom);
             histscan_isrup->Fill(c1mass,n1mass,binn,weight*isrup);
             histscan_isrdn->Fill(c1mass,n1mass,binn,weight*isrdn);
             }
             if(passSR(Form("SMS_SR_met100_mt150_mbb_mct150_twobtag_genMET_metbin%s%s",binstring.c_str(),version.c_str()))) 
             histscan_genmet->Fill(c1mass,n1mass,binn,weight);   // genmet resolution            
           }// loop over bins
         } 
          if(TString(selection).Contains("yield_2lCR")){
           if(!pass2lCR(selection.c_str())) continue;
           for (int binn = 1; binn < 5; binn ++){
           histname = Form("h_%s_event_NEvents2lCR","lep");
           string binstring = to_string(binn);
           if(pass2lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           if( is2lep()) {
           histname = Form("h_%s_event_NEvents2lCR","lep_dilep");
           if(pass2lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
           if( is1lep()) {
           histname = Form("h_%s_event_NEvents2lCR","lep_onelep");
           if(pass2lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
           continue;   
          }
         }

          if(TString(selection).Contains("yield_1lCR")){
           if(!pass1lCR(selection.c_str())) continue;
           for (int binn = 1; binn < 5; binn ++){
           string binstring = to_string(binn);
           histname = Form("h_%s_event_NEvents1lCR","lep");
           if(pass1lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           if( is2lep()) {
           histname = Form("h_%s_event_NEvents1lCR","lep_dilep");
           if(pass1lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( is1lep()) {
           histname = Form("h_%s_event_NEvents1lCR","lep_onelep");
           if(pass1lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( gensel::isHF()){
           histname = Form("h_%s_event_NEvents1lCR","lep_HF");
           if(pass1lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( !gensel::isHF()){
           histname = Form("h_%s_event_NEvents1lCR","lep_LF");
           if(pass1lCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
         continue;   
         }
         }
          if(TString(selection).Contains("yield_mbbCR")){
           if(!passmbbCR(selection.c_str())) continue;
           
          for (int binn = 1; binn < 5; binn ++){
           histname = Form("h_%s_event_NEventsmbbCR","lep");
           string binstring = to_string(binn);
           if(passmbbCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           if( is2lep()) {
           histname = Form("h_%s_event_NEventsmbbCR","lep_dilep");
           if(passmbbCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
           }
           if( is1lep()) {
           histname = Form("h_%s_event_NEventsmbbCR","lep_onelep");
           if(passmbbCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
           if(gensel::isHF()){
           histname = Form("h_%s_event_NEventsmbbCR","lep_HF");
           if(passmbbCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
           if(!gensel::isHF()){
           histname = Form("h_%s_event_NEventsmbbCR","lep_LF");
           if(passmbbCR(Form("metbin%s%s",binstring.c_str(),version.c_str()))) histos_cutflow[histname]->Fill(binn,weight);
          }
          continue;   
          }
         }
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
         // gen selection  ---NEED CLEANUP//
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

        if(TString(selection).Contains("gensel")){
          // if(!(passpreselection("sr"))) continue;
          int genlepi = -999;
          int gennui = -999;
          int nhiggs = 0;
          int nw = 0;
          int nlsp = 0;
          int nn2 = 0;
          int nch = 0;
          weight =1;
          vector<int> hbs = gensel::bs_fromH();
          vector<vector<int>> selected_leps;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlep;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > gennu;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genb1;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genb2;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > gench;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genn2;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > sys;
          vector<int> lsps;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlsp1;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlsp2;

          selected_leps = gensel::lep_nu_fromW();
//          if(selected_leps.at(0).size()+selected_leps.at(2).size() ==2) {genlepi = selected_leps.at(2)[0] ; gennui = selected_leps.at(3)[0] ;}         
          if(selected_leps.at(0).size()+selected_leps.at(2).size() !=1) continue; //require only lepton events
          if(selected_leps.at(0).size()+selected_leps.at(1).size() ==2) {genlepi = selected_leps.at(0)[0] ; gennui = selected_leps.at(1)[0] ;}         
          if(selected_leps.at(2).size()+selected_leps.at(3).size() ==2) {genlepi = selected_leps.at(2)[0] ; gennui = selected_leps.at(3)[0] ;}         
          for(unsigned int i=0;i<genbosons_p4().size();i++) { if(genbosons_id()[i]==25) nhiggs++;if(abs(genbosons_id()[i])==24 && abs(genbosons_motherid()[i])==25) nw++;} // counting w and H
          for(unsigned int i=0;i<gensusy_p4().size();i++)   { 
             if(gensusy_id()[i]==1000022) { nlsp++; lsps.push_back(i);}
             if(abs(gensusy_id()[i])==1000023 && gensusy_status()[i]==62) {nn2++;genn2 = gensusy_p4()[i];} 
             if(abs(gensusy_id()[i])==1000024 && gensusy_status()[i]==62) {nch++;gench = gensusy_p4()[i];}
          } //count susy particles
          if(nn2!=1||nch!=1) continue;
          if(TString(selection).Contains("SR")     && !passSR(selection.c_str()))     continue;
          sys = (gench+genn2);

          event_hists.at("h_gen_sys_pt")->Fill(sys.pt());
          fillHist( "event", "gen_lep"  , selection.c_str(), selected_leps.at(0).size()+selected_leps.at(2).size() , weight );//couting leptons
          fillHist( "event", "gen_H"  ,   selection.c_str(), nhiggs , weight ); 
          fillHist( "event", "gen_W"  ,   selection.c_str(), nw , weight );     
          fillHist( "event", "gen_b"  ,   selection.c_str(), hbs.size() , weight );     
          fillHist( "event", "gen_lsp"  ,  selection.c_str(), nlsp , weight );     
          fillHist( "event", "gen_n2"  ,   selection.c_str(), nn2 , weight );     
          fillHist( "event", "gen_ch"  ,   selection.c_str(), nch , weight );     

          if(nw > 1||gensel::bs_fromH().size() < 2) continue;
          if(genlepi<0||gennui<0)           continue;//skip event if pair not found 
          if(!is1lep())  continue;
          genlep = genleps_p4().at(genlepi); 
          gennu  = gennus_p4().at(gennui);
          if(gensel::bs_fromH().size()>=2) genb1  = genqs_p4().at(gensel::bs_fromH().at(0));
          if(gensel::bs_fromH().size()>=2) genb2  = genqs_p4().at(gensel::bs_fromH().at(1));
          if(lsps.size() >= 2) genlsp1 = gensusy_p4().at(lsps.at(0));
          if(lsps.size() >= 2) genlsp2 = gensusy_p4().at(lsps.at(1));

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : begin the boost part  " <<endl;

          float genMET = genmet();
          float genMETPhi = genmet_phi();
          float genMETx = genMET*TMath::Cos(genMETPhi);
          float genMETy = genMET*TMath::Sin(genMETPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genmetlv;
          genmetlv.SetPxPyPzE(genMETx,genMETy,0.,genMET);
          event_hists.at("h_gen_mt")->Fill(getMT(genlep,genmetlv)); 
          //boost both to w rest frame
           TLorentzVector genlep_t;
           TLorentzVector gennu_t;
           genlep_t.SetPtEtaPhiE(genlep.Pt(),genlep.Eta(),genlep.Phi(),genlep.E());
           gennu_t.SetPtEtaPhiE(gennu.Pt(),gennu.Eta(),gennu.Phi(),gennu.E());

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : boosting  " <<endl;
           TLorentzVector cm = genlep_t + gennu_t;
           TLorentzVector genlep_boosted = genlep_t;
           TLorentzVector gennu_boosted = gennu_t;
           TVector3 boost = -cm.BoostVector();

           genlep_boosted.Boost(boost);
           gennu_boosted.Boost(boost);
          
           float massratio = ((genlep_boosted+gennu_boosted).M()-80.385)/80.385;
           TLorentzVector genlep_boosted_up = genlep_boosted*(1+massratio*.02); 
           TLorentzVector genlep_boosted_dn = genlep_boosted*(1-massratio*.02); 
           TLorentzVector gennu_boosted_up = gennu_boosted*(1+massratio*.02); 
           TLorentzVector gennu_boosted_dn = gennu_boosted*(1-massratio*.02); 

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : boosting  " <<endl;
           //boost back to the cm system.
           genlep_boosted_up.Boost(-boost);
           genlep_boosted_dn.Boost(-boost);
           gennu_boosted_up.Boost(-boost);
           gennu_boosted_dn.Boost(-boost);
           TLorentzVector lep_boosted_up = genlep_boosted_up - genlep_t;
           TLorentzVector lep_boosted_dn = genlep_boosted_dn - genlep_t;
           TLorentzVector nu_boosted_up = gennu_boosted_up - gennu_t;
           TLorentzVector nu_boosted_dn = gennu_boosted_dn - gennu_t;
           TLorentzVector reco_lep;
           TLorentzVector met_lv;
           reco_lep.SetPtEtaPhiE(lep1_p4().pt(),lep1_p4().eta(),lep1_p4().phi(),lep1_p4().E());
           met_lv.SetPxPyPzE(pfmet()*TMath::Cos(pfmet_phi()),pfmet()*TMath::Sin(pfmet_phi()),0,pfmet());
           
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : boosting  " <<endl;
           //plot mt
           float mt = getMT(genlep_t,gennu_t);
           float mt_up = getMT(genlep_boosted_up,gennu_boosted_up);
           float mt_dn = getMT(genlep_boosted_dn,gennu_boosted_dn);
           float reco_mt = getMT(reco_lep,met_lv);
           float reco_mt_up = getMT(reco_lep + lep_boosted_up,met_lv + nu_boosted_up);
           float reco_mt_dn = getMT(reco_lep + lep_boosted_dn,met_lv+nu_boosted_dn);
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : boosting  " <<endl;
          // event_hists.at("h_gen_lep_pt")->Fill(genlep.pt());
           //event_hists.at("h_gen_nu_pt")->Fill(gennu.pt());
           //event_hists.at("h_gen_b_pt")->Fill(genb1.pt());
           //event_hists.at("h_gen_b_pt")->Fill(genb2.pt());
           //event_hists.at("h_gen_h_mass")->Fill((genb1+genb2).mass());
           //event_hists.at("h_gen_ch_mass")->Fill(gench.mass());
           //event_hists.at("h_gen_n2_mass")->Fill(genn2.mass());
           //event_hists.at("h_gen_lsp_mass")->Fill(genlsp1.mass());
           //event_hists.at("h_gen_lsp_mass")->Fill(genlsp2.mass());
           event_hists.at("h_gen_mt")->Fill(mt); 
           event_hists.at("h_gen_mt_up")->Fill(mt_up); 
           event_hists.at("h_gen_mt_dn")->Fill(mt_dn);
           //reco mt
           event_hists.at("h_reco_mt")->Fill(reco_mt); 
           event_hists.at("h_reco_mt_up")->Fill(reco_mt_up); 
           event_hists.at("h_reco_mt_dn")->Fill(reco_mt_dn);
           //some validation plots
/*           event_hists.at("h_gen_lep_pt")->Fill(genlep_t.Pt()); 
           event_hists.at("h_gen_nu_pt")->Fill(gennu_t.Pt()); 
           event_hists.at("h_gen_w_mass")->Fill((genlep_t+gennu_t).M()); 
           event_hists.at("h_gen_w_mass_up")->Fill((genlep_boosted_up+gennu_boosted_up).M()); 
           event_hists.at("h_gen_w_mass_dn")->Fill((genlep_boosted_dn+gennu_boosted_dn).M());
*/  
        if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : boosting  " <<endl;
           continue; 
        }
 
	  //-~-~-~-~-~-~-~-~-//
	  //calculate variables//
	  //-~-~-~-~-~-~-~-~-//

	  float event_met_pt = pfmet();
	  float event_met_ph = pfmet_phi();
          float MET = pfmet();
          float METPhi = pfmet_phi();
          float METx = MET*TMath::Cos(METPhi);
          float METy = MET*TMath::Sin(METPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
          metlv.SetPxPyPzE(METx,METy,0.,MET);
          float m_bb = getmbb();
          float pt_bb = -999; pt_bb= getptbb();
          float mctbb = getmct();
          float ptlbb = 0;         
          float MT2lb =  -999; float dRbb = -999;
          float ptb1 =leadjetpt();
          float ptb2 =subleadjetpt();
          dRbb = getdRbb();
          vector<int> seljets = selectedjets();

	  //-~-~-~-~-~-~-~-~-//
	  //  selections     //
	  //-~-~-~-~-~-~-~-~-//
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : selection functions " <<endl;
          npass += weight;
          //if( mindphi_met_j1_j2()<0.4) continue;
          if(TString(selection).Contains("presel") && !passPreselection(selection))   continue;
          if(TString(selection).Contains("SR")     && !passSR(selection.c_str()))     continue;
          if(TString(selection).Contains("2lCR")   && !pass2lCR(selection.c_str()))   continue;
          if(TString(selection).Contains("1lCR")   && !pass1lCR(selection.c_str()))   continue;
          if(TString(selection).Contains("wjetsval")   && !passWJetsValidation())   continue;
          if(TString(selection).Contains("mbbCR")  && !passmbbCR(selection.c_str()))  continue;

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//

          event_hists.at("h_gen_nu_pt")->Fill(gensel::gennuptw(),weight);     
          event_hists.at("h_gen_met")->Fill(genmet(),weight);     
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "nbjets_gen"  , region.c_str(), gensel::isHF()   , weight );
          //if(ngoodbtags()==0) fillHist( "event", "ngenbjets_0btag"  , region.c_str(), gensel::isHF()   , weight );
          //if(ngoodbtags()==1) fillHist( "event", "ngenbjets_1btag"  , region.c_str(), gensel::isHF()   , weight );
          //if(ngoodbtags()!=0){ 
          fillHist( "event", "ngenbjets_2btag"  , region.c_str(), gensel::isHF()   , weight );
          //}
          fillHist( "event", "nbjets"  , region.c_str(), ngoodbtags(), weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
          fillHist( "event", "met_pass" , region.c_str(), event_met_pt        , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_p4().pt()      , weight );
          fillHist( "event", "pt_ISR"   , region.c_str(),isrjetpt()     , weight );

          if((lep1_relIso()*lep1_p4().pt() < 5)) fillHist( "event", "ptl1_pass"   , region.c_str(), lep1_p4().pt()      , weight );
	  if(ngoodbtags()==0) fillHist( "event", "mt_0btag"    , region.c_str(),  mt_met_lep()   , weight );
	  if(ngoodbtags()==2) fillHist( "event", "mt_2btag"    , region.c_str(),  mt_met_lep()   , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
	  fillHist( "event", "mindphi_met_j1_j2"    , region.c_str(),  mindphi_met_j1_j2(), weight );
	  fillHist( "event", "MT2lb"    , region.c_str(), MT2lb  , weight );
          // this is for unblinding purpose. doesn't show data inside mbb window
	  //if((TString(selection).Contains("SR")||TString(selection).Contains("mbbCR") )&& is_data() && !(m_bb<150&&m_bb>90)) 
          fillHist( "event", "mbb"    , region.c_str(),  m_bb   , weight );
	  fillHist( "event", "dRbb"    , region.c_str(), dRbb   , weight );
	  fillHist( "event", "MCT"    , region.c_str(),  mctbb   , weight );
          if(ngoodbtags()==0)  fillHist( "event", "MCT_0btag"    , region.c_str(),  mctbb   , weight );
       	  if(ngoodbtags()==2)  fillHist( "event", "MCT_2btag"    , region.c_str(),  mctbb   , weight );
	  fillHist( "event", "ptbb"    , region.c_str(),  pt_bb   , weight );
	  fillHist( "event", "ptlbb"    , region.c_str(),  ptlbb   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptb1"   , region.c_str(), ptb1   , weight );
          fillHist( "event", "ptb2"   , region.c_str(), ptb2    , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  //fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	 // fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "MT2W" , region.c_str(), MT2W()       , weight );	 
	  fillHist( "event", "dphibb" , region.c_str(), getdphibb()       , weight );	 
	  fillHist( "event", "ptb1overptb2" , region.c_str(), ptb1/ptb2      , weight );	 
	  fillHist( "event", "deltaphi_lep_met" , region.c_str(), abs(ROOT::Math::VectorUtil::DeltaPhi(lep1_p4(),metlv)), weight );	 
//	  fillHist( "event", "deltaphi_lep_leadb" , region.c_str(), abs(ROOT::Math::VectorUtil::DeltaPhi(lep1_p4(), ak4pfjets_p4().at(seljets.at(0)))), weight );	 
//	  fillHist( "event", "dR_lep_leadb"    , region.c_str(), abs(ROOT::Math::VectorUtil::DeltaR(lep1_p4(), ak4pfjets_p4().at(seljets.at(0))))   , weight );
//	  fillHist( "event", "deltaphi_leadb_met" , region.c_str(), abs(ROOT::Math::VectorUtil::DeltaPhi(ak4pfjets_p4().at(seljets.at(0)),metlv)), weight );	 
          
// 
           histMCTvsMT->Fill(mctbb,mt_met_lep(),weight);
           histMCTvsMET->Fill(mctbb,event_met_pt,weight);
           histMCTvsMbb->Fill(mctbb,m_bb,weight);
          //-~-~-~-~-~-~-~-~-~-~-//
	  //Print out some events//
	  //-~-~-~-~-~-~-~-~-~-~-//
//	  if(mctbb>150) { 
//          cout<<"Run_Number:"<<run()<<"Lum:"<< evt() <<":EventNumber:"<< evt() << "lep_pdgid"<<lep1_pdgid() <<":lep_pt: "<<lep1_p4().pt()<<  ":lep_eta: "<<lep1_p4().eta()<<":met:"<<event_met_pt<<":met_phi:"<<event_met_ph <<":mct:"<< mctbb<< ":mt:"<< mt_met_lep()<<endl;
//     }
          //cout<<run()<<":"<<ls()<<":"<<evt()<<"\n"<<endl; 
           
//           } // end of printout
   } // end loop over events
  } // end loop over files

  cout << nel         << " el events passing selection" << endl;
  cout << nmu         << " mu events passing selection" << endl;
 
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  
  // make histos rootfile
  string outputfilename = Form("${analysis_output}/%s_%s_hists.root",
								 sample.c_str(),
								 selection.c_str()
								 );
  cout << "Writing output to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
 
} // end ScanChain

void templateLooper::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}  
void templateLooper::bookHistTH1D( string name, string title, int nbins, float xmin, float xmax ){
  TH1D * hist = new TH1D( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  hist->SetTitle("Events");
  return;
}  

void templateLooper::fillHist( string obj, string var, string sel, float value, float weight ){
  string hist = "h_";
  try
	{
          if( is2lep() ){
		hist = Form("h_lep_dilep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( is1lep() ){
		hist = Form("h_lep_onelep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( gensel::isHF() ){
         	hist = Form("h_lep_HF_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( !gensel::isHF() ){
                hist = Form("h_lep_LF_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          hist = Form("h_lep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
          fillUnderOverFlow(event_hists.at( hist ), value, weight);
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
	return;
}  

