#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TMath.h"

#include "Math/VectorUtil.h"

#include "templateLooper.h"
#include "../sharedCode/V00_00_05.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/WHSelection.h"
#include "../sharedCode/GenSelection.h"
#include "../sharedCode/AnalysisUtils.h"
#include "../stop_variables/MT2_implementations.h"
#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"

using namespace std;
using namespace duplicate_removal;
using namespace V00_00_05_np;
using namespace whsel;
using namespace gensel; 

const bool debug = false;
const bool usejson = true;
const bool dovtxreweighting = true;
const bool dobtagweighting = true;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::bookHistos(std::string region){
  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("el");
  leptype.push_back("mu");
  leptype.push_back("lep");
  leptype.push_back("lep_onelep");
  leptype.push_back("lep_dilep");
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;             vector <float> variable_bins;
  variable.push_back("ptl1");           variable_bins.push_back(1000);  
  variable.push_back("ptb1");           variable_bins.push_back(1000);  
  variable.push_back("ptb2");           variable_bins.push_back(1000);  
  variable.push_back("ptbb");           variable_bins.push_back(1000);  
  variable.push_back("ptlbb");           variable_bins.push_back(1000);  
  variable.push_back("met");            variable_bins.push_back(1000);  
  variable.push_back("ht");	        variable_bins.push_back(1000);  
  variable.push_back("mt");	        variable_bins.push_back(1000);  
  variable.push_back("mbb");	        variable_bins.push_back(1000);  
  variable.push_back("MCT");	        variable_bins.push_back(1000);  
  variable.push_back("njets");          variable_bins.push_back(20  );  
  variable.push_back("nbjets");         variable_bins.push_back(20  );  
  variable.push_back("nVert");          variable_bins.push_back(50  );  
  variable.push_back("relIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("nhiso");	        variable_bins.push_back(1000);  
  variable.push_back("emiso");	        variable_bins.push_back(1000);  
  variable.push_back("MT2W");	        variable_bins.push_back(1000);  
  variable.push_back("dphi_Wlep");	variable_bins.push_back(1000);  
  variable.push_back("dR_lep_leadb");	variable_bins.push_back(1000);  
  variable.push_back("MT2_lb_b_mass");  variable_bins.push_back(1000);  
  variable.push_back("MT2lb");  variable_bins.push_back(1000);  
  variable.push_back("MT2_lb_b");	variable_bins.push_back(1000);  
  variable.push_back("MT2_lb_b_mass_lep2"); variable_bins.push_back(1000);  
  variable.push_back("MT2_lb_b_lep2");      variable_bins.push_back(1000);  

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

  // some gen level variables
  bookHist("h_gen_lep_pt", "h_gen_lep_pt", 1000,0,1000);
  bookHist("h_gen_b_pt", "h_gen_b_pt", 1000,0,1000);
  bookHist("h_gen_nu_pt", "h_gen_nu_pt", 1000,0,1000);
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

 //phi and eta plots, they have the same x and y limits.
  vector <string> phivars;
  phivars.push_back("metphi");
  phivars.push_back("deltaphi_lep_met");
  phivars.push_back("metphir");
  phivars.push_back("metphi20");
  phivars.push_back("metphi40");
  phivars.push_back("metphi60");
  phivars.push_back("mhtphi");
  phivars.push_back("nbjets_diff");
 
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


  //--------------------// 
  // book Cutflow hists //
  //--------------------//
  vector<string> histonames_cutflow; histonames_cutflow.clear();
  histonames_cutflow.push_back("NEventsSR");
  histonames_cutflow.push_back("NEvents1lCR");
  histonames_cutflow.push_back("NEvents2lCR");
  histonames_cutflow.push_back("NEventsPerCut");

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
		for( unsigned int selind = 0; selind < histonames_cutflow.size(); selind++ ){
               //bookHistTH1D(Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
               //             Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
               //             8,0.5,8.5
  //            );//book histos for all SRs and CRs
                string histoname = "h_"+leptype.at(lepind)+"_event_"+histonames_cutflow.at(selind)+"_"+region.c_str();
                histos_cutflow[histoname] = new TH1D(histoname.c_str(),histoname.c_str(),11,0.5,11.5);
                histos_cutflow[histoname]->Sumw2();
		}
  }

 //---------------------------------------------------------//
 // initialize histograms here for all regions of interests //
 //---------------------------------------------------------//
 
  /*
  bookHist("h_mm_event_drll_2jets", "h_mm_event_drll_2jets", 500,0,5);
  */
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
  const char* json_file ="../json/json_270715_golden.txt";
  set_goodrun_file(json_file);
   eventFilter metFilterTxt;
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
   if ( TString(sample).Contains("data") ) {
    cout<<"Loading bad event files ..."<<endl;
    // old lists for partial dataset
    // add from hj email
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/csc2015_Dec01.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/ecalscn1043093_Dec01.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/badResolutionTrack_Jan13.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/muonBadTrack_Jan13.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_DoubleEG_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_DoubleMuon_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_HTMHT_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_JetHT_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_MET_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_MuonEG_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_SingleElectron_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_SingleMuon_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/eventlist_SinglePhoton_csc2015.txt");
    // new lists: supposed to include above but do not always
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/DoubleEG_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/DoubleMuon_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/HTMHT_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/JetHT_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/MET_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/MuonEG_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleElectron_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SingleMuon_csc2015.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SinglePhoton_csc2015.txt");
    // not all samples have events which failed the ecal SC filter
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/DoubleEG_ecalscn1043093.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/HTMHT_ecalscn1043093.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/JetHT_ecalscn1043093.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/MET_ecalscn1043093.txt");
    metFilterTxt.loadBadEventList("/nfs-6/userdata/mt2utils/SinglePhoton_ecalscn1043093.txt");
    cout<<" ... finished!"<<endl;
  } 

  TH1F * h_vtxweight = NULL;
  TFile * f_vtx = NULL;
  if( dovtxreweighting ){
	f_vtx = TFile::Open("nvtx_ratio.root","READ");
	h_vtxweight = (TH1F*)f_vtx->Get("h_vtx_ratio")->Clone("h_vtxweight");
	h_vtxweight->SetDirectory(rootdir);
	f_vtx->Close();
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
    v00_00_05.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  v00_00_05.GetEntry(event);
          ++nEventsTotal;
          // ~~~~~~~~~~~
          //   continue;
          // ~~~~~~~~~~~
	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
                printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
                fflush(stdout);
           } 
          }

	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
	  //         MET filter  and json      //
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

	 // if ( is_data() && usejson && !goodrun(run(), ls()) ) continue;
           if (is_data() &&!filt_eebadsc())   continue;
           if (is_data() &&!filt_hbhenoise()) continue;
           if (is_data() && metFilterTxt.eventFails(run(), ls(), evt())) {
		//cout<<"Found bad event in data: "<<run()<<", "<<ls()<<", "<<evt()<<endl;
			continue;
           }
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : pass MET filter  and json " <<endl;
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

	  //~-~-~-~-~-~-~-~~-~-~-//
	  //    counters         //
	  //~-~-~-~-~-~-~-~-~-~-//
 	   if( lep1_is_mu()) nmu++;
	   if( lep1_is_el()) nel++;

	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//

	  float weight = 1.0;
          float lumi = 10.0;
	  if( is_data() ){
		weight = 1.0;
	   } else if( !is_data() ){
                  weight = event_weight(selection.c_str());
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
	  
	  if( !is_data() && dobtagweighting){
          weight *= weight_btagsf();
          } 
	  float event_met_pt = pfmet();
	  float event_met_ph = pfmet_phi();

          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //       additional event selection (to protect again some gen level cuts for example)      // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //    fill cutflow histograms     // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

	  string histname = "dummy";
          if(TString(selection).Contains("percut")){
	  if(pfmet()<50) continue;
          if(ngoodjets()<2) continue;

          histname = Form("h_%s_event_NEventsPerCut_%s","lep",selection.c_str());
          histos_cutflow[histname]->Fill(1,weight);                               //Nevents in the skim
          if(passPreselection("step0")) histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passPreselection("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(passPreselection("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(passPreselection("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(passPreselection("step4"))  histos_cutflow[histname]->Fill(6,weight); //tau veto
          if(passStudyRegion("step5"))  histos_cutflow[histname]->Fill(7,weight); // two btagged
//          if(passStudyRegion("step6"))  histos_cutflow[histname]->Fill(8,weight); //exactly two jets
          continue;
           }

          if(TString(selection).Contains("SR_yield")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           //signal
           if(!passStudyRegion("presel_2btags")) continue;
           if(!passStudyRegion(selection.c_str())) continue;
           //if(mindphi_met_j1_j2() < 0.8) continue;
           histname = Form("h_%s_event_NEventsSR_%s","lep",selection.c_str());
           if(passStudyRegion("met100_mt100_2jets")) histos_cutflow[histname]->Fill(1,weight);
           if(passStudyRegion("met150_mt100_2jets")) histos_cutflow[histname]->Fill(2,weight);
           if(passStudyRegion("met175_mt100_2jets")) histos_cutflow[histname]->Fill(3,weight);
           if(passStudyRegion("met100_mt120_2jets")) histos_cutflow[histname]->Fill(4,weight);
           if(passStudyRegion("met150_mt120_2jets")) histos_cutflow[histname]->Fill(5,weight);
           if(passStudyRegion("met175_mt120_2jets")) histos_cutflow[histname]->Fill(6,weight);
           if(passStudyRegion("met100_mt150_2jets")) histos_cutflow[histname]->Fill(7,weight);
           if(passStudyRegion("met150_mt150_2jets")) histos_cutflow[histname]->Fill(8,weight);
           if(passStudyRegion("met175_mt150_2jets"))  histos_cutflow[histname]->Fill(9,weight);

           if( is2lep()) {
           histname = Form("h_%s_event_NEventsSR_%s","lep_dilep",selection.c_str());
           if(passStudyRegion("met100_mt100_2jets")) histos_cutflow[histname]->Fill(1,weight);
           if(passStudyRegion("met150_mt100_2jets")) histos_cutflow[histname]->Fill(2,weight);
           if(passStudyRegion("met175_mt100_2jets")) histos_cutflow[histname]->Fill(3,weight);
           if(passStudyRegion("met100_mt120_2jets")) histos_cutflow[histname]->Fill(4,weight);
           if(passStudyRegion("met150_mt120_2jets")) histos_cutflow[histname]->Fill(5,weight);
           if(passStudyRegion("met175_mt120_2jets")) histos_cutflow[histname]->Fill(6,weight);
           if(passStudyRegion("met100_mt150_2jets")) histos_cutflow[histname]->Fill(7,weight);
           if(passStudyRegion("met150_mt150_2jets")) histos_cutflow[histname]->Fill(8,weight);
           if(passStudyRegion("met175_mt150_2jets"))  histos_cutflow[histname]->Fill(9,weight);
           }

           if( is1lep()) {
           histname = Form("h_%s_event_NEventsSR_%s","lep_onelep",selection.c_str());
           if(passStudyRegion("met100_mt100_2jets")) histos_cutflow[histname]->Fill(1,weight);
           if(passStudyRegion("met150_mt100_2jets")) histos_cutflow[histname]->Fill(2,weight);
           if(passStudyRegion("met175_mt100_2jets")) histos_cutflow[histname]->Fill(3,weight);
           if(passStudyRegion("met100_mt120_2jets")) histos_cutflow[histname]->Fill(4,weight);
           if(passStudyRegion("met150_mt120_2jets")) histos_cutflow[histname]->Fill(5,weight);
           if(passStudyRegion("met175_mt120_2jets")) histos_cutflow[histname]->Fill(6,weight);
           if(passStudyRegion("met100_mt150_2jets")) histos_cutflow[histname]->Fill(7,weight);
           if(passStudyRegion("met150_mt150_2jets")) histos_cutflow[histname]->Fill(8,weight);
           if(passStudyRegion("met175_mt150_2jets"))  histos_cutflow[histname]->Fill(9,weight);
           }
           continue;
 
          //CR1l
       } //end of if yield
              
          if(TString(selection).Contains("yield_2lCR")){
           histname = Form("h_%s_event_NEvents2lCR_%s","lep",selection.c_str());
           if(pass2lCR("yield_bin1")) histos_cutflow[histname]->Fill(1,weight);
           if(pass2lCR("yield_bin2")) histos_cutflow[histname]->Fill(2,weight);
           if(pass2lCR("yield_bin3")) histos_cutflow[histname]->Fill(3,weight);

           if( is2lep()) {
           histname = Form("h_%s_event_NEvents2lCR_%s","lep_dilep",selection.c_str());
           if(pass2lCR("yield_bin1")) histos_cutflow[histname]->Fill(1,weight);
           if(pass2lCR("yield_bin2")) histos_cutflow[histname]->Fill(2,weight);
           if(pass2lCR("yield_bin3")) histos_cutflow[histname]->Fill(3,weight);
           }
           if( is1lep()) {
           histname = Form("h_%s_event_NEvents2lCR_%s","lep_onelep",selection.c_str());
           if(pass2lCR("yield_bin1")) histos_cutflow[histname]->Fill(1,weight);
           if(pass2lCR("yield_bin2")) histos_cutflow[histname]->Fill(2,weight);
           if(pass2lCR("yield_bin3")) histos_cutflow[histname]->Fill(3,weight);
           }
         continue;   
         }
    
          //1l CR
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : check selection region " <<endl;
          //2l CR
//          if(TString(selection).Contains("2l")) {
 //            if( !pass2lCR(selection.c_str())) continue;
 //         }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : finished check selection region " <<endl;

         //-~-~-~-~-~-~-~-~-~-//
         // gen selection     //
         //-~-~-~-~-~-~-~-~-~-//

        if(TString(selection).Contains("gensel")){
          // if(!(passpreselection("sr"))) continue;
          // select gen lepton and gen neutrino, need to write a function.
          int genlepi = -999;
          int gennui = -999;
          int nhiggs = 0;
          int nw = 0;
          int nlsp = 0;
          int nn2 = 0;
          int nch = 0;
          vector<int> hbs = bs_fromH();
          vector<vector<int>> selected_leps;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlep;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > gennu;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genb1;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genb2;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >gench;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >genn2;
          vector<int> lsps;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlsp1;
             ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genlsp2;

          selected_leps = lep_nu_fromW();
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

          fillHist( "event", "gen_lep"  , selection.c_str(), selected_leps.at(0).size()+selected_leps.at(2).size() , weight );//couting leptons
          fillHist( "event", "gen_H"  ,   selection.c_str(), nhiggs , weight ); 
          fillHist( "event", "gen_W"  ,   selection.c_str(), nw , weight );     
          fillHist( "event", "gen_b"  ,   selection.c_str(), hbs.size() , weight );     
          fillHist( "event", "gen_lsp"  ,  selection.c_str(), nlsp , weight );     
          fillHist( "event", "gen_n2"  ,   selection.c_str(), nn2 , weight );     
          fillHist( "event", "gen_ch"  ,   selection.c_str(), nch , weight );     

          //if(nw > 1||bs_fromH().size() < 2) continue;
          if(genlepi<0||gennui<0)           continue;//skip event if pair not found 
          if(!is1lep())  continue;
          genlep = genleps_p4().at(genlepi); 
          gennu  = gennus_p4().at(gennui);
          if(bs_fromH().size()>=2) genb1  = genqs_p4().at(bs_fromH().at(0));
          if(bs_fromH().size()>=2) genb2  = genqs_p4().at(bs_fromH().at(1));
          if(lsps.size() >= 2) genlsp1 = gensusy_p4().at(lsps.at(0));
          if(lsps.size() >= 2) genlsp2 = gensusy_p4().at(lsps.at(1));
          float genMET = genmet();
          float genMETPhi = genmet_phi();
          float genMETx = genMET*TMath::Cos(genMETPhi);
          float genMETy = genMET*TMath::Sin(genMETPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > genmetlv;
          genmetlv.SetPxPyPzE(genMETx,genMETy,0.,genMET);
          //event_hists.at("h_gen_mt")->Fill(getMT(genlep,gennu)); 
          event_hists.at("h_gen_mt")->Fill(getMT(genlep,genmetlv)); 
          //boost both to w rest frame
           TLorentzVector genlep_t;
           TLorentzVector gennu_t;
           genlep_t.SetPtEtaPhiE(genlep.Pt(),genlep.Eta(),genlep.Phi(),genlep.E());
           gennu_t.SetPtEtaPhiE(gennu.Pt(),gennu.Eta(),gennu.Phi(),gennu.E());

           TLorentzVector cm = genlep_t + gennu_t;
           TLorentzVector genlep_boosted = genlep_t;
           TLorentzVector gennu_boosted = gennu_t;
           TVector3 boost = -cm.BoostVector();

           genlep_boosted.Boost(boost);
           gennu_boosted.Boost(boost);
           ///---- boost validation-----//
           //cm.Boost( -cm.BoostVector() );
           //cout << cm.Px() << " " << cm.Py() << " " << cm.Pz() << " " << cm.E() << endl;
           //cout << genlep_boosted.Px() << " " << genlep_boosted.Py() << " " << genlep_boosted.Pz() << " " << genlep_boosted.E() << endl;
           //cout << genlep_t.Px() << " " << genlep_t.Py() << " " << genlep_t.Pz() << " " << genlep_t.E() << endl;
           //cout << gennu_boosted.Px() << " " << gennu_boosted.Py() << " " << gennu_boosted.Pz() << " " << gennu_boosted.E() << endl;
           //scale them to make the width to be 1.02, 2.195 ± 0.083--> width
           
           //plots to validate the width change.
           
           float massratio = ((genlep_boosted+gennu_boosted).M()-80.385)/80.385;
           TLorentzVector genlep_boosted_up = genlep_boosted*(1+massratio*.02); 
           TLorentzVector genlep_boosted_dn = genlep_boosted*(1-massratio*.02); 
           TLorentzVector gennu_boosted_up = gennu_boosted*(1+massratio*.02); 
           TLorentzVector gennu_boosted_dn = gennu_boosted*(1-massratio*.02); 

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
           met_lv.SetPxPyPzE(pfmet()*TMath::Cos(event_met_ph),pfmet()*TMath::Sin(event_met_ph),0,pfmet());
           
           //plot mt
           float mt = getMT(genlep_t,gennu_t);
           float mt_up = getMT(genlep_boosted_up,gennu_boosted_up);
           float mt_dn = getMT(genlep_boosted_dn,gennu_boosted_dn);
           float reco_mt = getMT(reco_lep,met_lv);
           float reco_mt_up = getMT(reco_lep + lep_boosted_up,met_lv + nu_boosted_up);
           float reco_mt_dn = getMT(reco_lep + lep_boosted_dn,met_lv+nu_boosted_dn);
           //only consider events with mt > 120 and met > 200
           //if(gennu_t.Pt() < 200) continue;
           //if(pfmet()<200) continue;
           //event_hists.at("")->Fill();
           event_hists.at("h_gen_lep_pt")->Fill(genlep.pt());
           event_hists.at("h_gen_nu_pt")->Fill(gennu.pt());
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
           event_hists.at("h_gen_lep_pt")->Fill(genlep_t.Pt()); 
           event_hists.at("h_gen_nu_pt")->Fill(gennu_t.Pt()); 
           event_hists.at("h_gen_w_mass")->Fill((genlep_t+gennu_t).M()); 
           event_hists.at("h_gen_w_mass_up")->Fill((genlep_boosted_up+gennu_boosted_up).M()); 
           event_hists.at("h_gen_w_mass_dn")->Fill((genlep_boosted_dn+gennu_boosted_dn).M());
           continue; 
        }
 
          float MET = pfmet();
          float METPhi = pfmet_phi();
          float METx = MET*TMath::Cos(METPhi);
          float METy = MET*TMath::Sin(METPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
          metlv.SetPxPyPzE(METx,METy,0.,MET);
          //select b jets
          std::pair<vector<int>,vector<int>> alljets;
          alljets = btaggedjets(selection);
          vector<int> bjets = alljets.first;
          vector<int> addjets = alljets.second;
          vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> bjetslv;
          vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >> addjetslv;
          float m_bb = mbb(bjets);
          float pt_bb = ptbb(bjets);
          float mctbb = mct(bjets);
          int ngoodjets_low = bjets.size()+addjets.size();
          for (int i=0;i<bjets.size();i++) { ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jetlv = ak4pfjets_p4().at(bjets.at(i));bjetslv.push_back(jetlv); }
          for (int i=0;i<addjets.size();i++) { ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > jetlv = ak4pfjets_p4().at(addjets.at(i));addjetslv.push_back(jetlv);}
          //recal MT2
          float MT2lb = CalcMT2_lb_b_(MET, METPhi, lep1_p4(), bjetslv, addjetslv, 0, false);	 
//          if(bjets.size()!=2 && TString(selection).Contains("2btags"))  continue;
//          if((m_bb>150||m_bb<100)&&TString(selection).Contains("mbb"))                 continue;       
          float ptlbb = 0;         
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
          npass += weight;
          if(TString(selection).Contains("presel")&& !passPreselection(selection))  continue;
          if(TString(selection).Contains("SR")&& !passStudyRegion(selection.c_str()))     continue;
          if(TString(selection).Contains("2lCR") && ! pass2lCR(selection.c_str())) continue;
          if(bjets.size()==2) ptlbb = (bjetslv.at(0)+bjetslv.at(1)+lep1_p4()).pt();
          //if(event_met_pt<100) continue;
          string region = selection;
          fillHist( "event", "njets"  , region.c_str(), ngoodjets_low    , weight );
          fillHist( "event", "nbjets"  , region.c_str(), bjets.size(), weight );
          fillHist( "event", "nbjets_diff"  , region.c_str(), bjets.size()-ngoodbtags(), weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
	  fillHist( "event", "dphi_Wlep"    , region.c_str(),  dphi_Wlep()   , weight );
	  fillHist( "event", "dR_lep_leadb"    , region.c_str(),  dR_lep_leadb()   , weight );
	  fillHist( "event", "MT2_lb_b_mass"    , region.c_str(),  MT2_lb_b_mass()   , weight );
	  fillHist( "event", "MT2lb"    , region.c_str(), MT2lb  , weight );
	  fillHist( "event", "MT2_lb_b"    , region.c_str(),  MT2_lb_b()   , weight );
	  fillHist( "event", "MT2_lb_b_mass_lep2"    , region.c_str(),  MT2_lb_b_mass_lep2()   , weight );
	  fillHist( "event", "MT2_lb_b_lep2"    , region.c_str(),  MT2_lb_b_lep2()   , weight );
	  fillHist( "event", "mbb"    , region.c_str(),  m_bb   , weight );
	  fillHist( "event", "MCT"    , region.c_str(),  mctbb   , weight );
	  fillHist( "event", "ptbb"    , region.c_str(),  pt_bb   , weight );
	  fillHist( "event", "ptlbb"    , region.c_str(),  ptlbb   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "MT2W" , region.c_str(), MT2W()       , weight );	 
	  fillHist( "event", "deltaphi_lep_met" , region.c_str(), ROOT::Math::VectorUtil::DeltaPhi(lep1_p4(),metlv) , weight );	 
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : finished filling histograms " <<endl;

          //-~-~-~-~-~-~-~-~-~-~-//
	  //Print out some events//
	  //-~-~-~-~-~-~-~-~-~-~-//
	  
//          if(mt_met_lep()>175 && fabs(lep1_eta()) > 1.6 &&lep1_is_el()) { 
           //cout<<"Run_Number:"<<run()<< ":EventNumber:"<< evt() <<":lep_pt: "<<lep1_pt()<<":met:"<<event_met_pt<<":met_phi:"<<event_met_ph <<":diff:"<<event_met_pt-lep1_pt()<<":diff_ratio:"<<(event_met_pt-lep1_pt())/lep1_pt() << ":mt:"<<mt_met_lep()<<endl;
           //cout<<run()<<":"<<ls()<<":"<<evt()<<"\n"<<endl; 
//           } // end of printout
   } // end loop over events
  } // end loop over files

  cout << nel         << " el events passing selection" << endl;
  cout << nmu         << " mu events passing selection" << endl;
  cout << nemu         << " el+mu events passing selection" << endl;

  cout<<"nemu 2 jets    : "<<nem_2jets<<endl;
  cout<<"nemu 2 jets mll: "<<nem_2jets_mll<<endl;
  cout<<"emu scale factor: "<<nem_2jets_mll/nem_2jets<<endl;
 
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
	  if( lep1_is_el() ){
		hist = Form("h_el_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
          if( is2lep() ){
		hist = Form("h_lep_dilep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( is1lep() ){
		hist = Form("h_lep_onelep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
	  if( lep1_is_mu() ){
         	hist = Form("h_mu_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
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

