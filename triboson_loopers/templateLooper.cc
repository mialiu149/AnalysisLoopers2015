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
#include "TGraphAsymmErrors.h"

#include "templateLooper.h"
#include "../classFiles/triboson_v0.1.9/triboson.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/TribosonSelection.h"
#include "../sharedCode/AnalysisUtils.h"
#include "../stop_variables/MT2_implementations.h"
#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"

using namespace std;
using namespace duplicate_removal;
using namespace triboson_np;
using namespace tribosonsel;
//using namespace gensel; 

const bool debug = false;
const bool usejson = false;
const bool dovtxreweighting = true;
const bool applybtagsf = true;
const bool applytriggerweight = false ;
const bool applytriggersf = true ;
const bool applylepsf = true;
const bool halfsigxsec = true;
templateLooper::templateLooper() {
}

templateLooper::~templateLooper() {
}

void templateLooper::bookHistos(std::string region){
  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("lep");
  leptype.push_back("lep_trilep");
  leptype.push_back("lep_dilep");
//  leptype.push_back("lep_HF");
//  leptype.push_back("lep_LF");
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;             vector <float> variable_bins;
  variable.push_back("ptl1");           variable_bins.push_back(1000);  
  variable.push_back("pt_ISR");         variable_bins.push_back(1000);  
  variable.push_back("ptl1_pass");      variable_bins.push_back(1000);  
  variable.push_back("ptj1");           variable_bins.push_back(1000);  
  variable.push_back("ptj2");           variable_bins.push_back(1000);  
  variable.push_back("ptjj");           variable_bins.push_back(1000);  
  variable.push_back("ptlll");           variable_bins.push_back(1000);  
  variable.push_back("mlll");           variable_bins.push_back(1000);  
  variable.push_back("ptll");           variable_bins.push_back(1000);  
  variable.push_back("ptlljj");          variable_bins.push_back(1000);  
  variable.push_back("met");            variable_bins.push_back(1000);  
  variable.push_back("mll");            variable_bins.push_back(1000);  
  variable.push_back("ht");	        variable_bins.push_back(1000);  
  variable.push_back("mtMax");	        variable_bins.push_back(1000);  
  variable.push_back("mjj");	        variable_bins.push_back(1500);  
  variable.push_back("mjj_lead");	variable_bins.push_back(1500);  
  variable.push_back("MCT");	        variable_bins.push_back(1000);  
  variable.push_back("relIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA_subleading");	variable_bins.push_back(1000);  
  variable.push_back("MT2W");	        variable_bins.push_back(1000);  
  variable.push_back("dphi_Wlep");	variable_bins.push_back(1000);  
  variable.push_back("MT2lb");          variable_bins.push_back(1000);  
  variable.push_back("njets");          variable_bins.push_back(20  );  
  variable.push_back("nleps");          variable_bins.push_back(20  );  
  variable.push_back("nveto_leptons");          variable_bins.push_back(20  );  
  variable.push_back("nisoTrack_mt2");          variable_bins.push_back(20  );  
  variable.push_back("nbjets");              variable_bins.push_back(20  );  
  variable.push_back("nVert");               variable_bins.push_back(50  );  
  variable.push_back("ptb1overptb2");        variable_bins.push_back(10  );
  variable.push_back("lep_gfit_pt");         variable_bins.push_back(1000);
  variable.push_back("lep_gfit_ptErr");      variable_bins.push_back(10  );

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
  phivars.push_back("deta_jj");
  phivars.push_back("deltaphi_lep_met");
  phivars.push_back("deltaphi_lep_leadb");
  phivars.push_back("deltaphi_leadb_met");
  phivars.push_back("mindphi_met_j1_j2");
  phivars.push_back("nbjets_diff");
  phivars.push_back("dR_lep_leadb");
  phivars.push_back("lep_gfit_ratio");   
 
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
  histonames_cutflow.push_back("NEventsSR_ss");
  histonames_cutflow.push_back("NEventsSR_trilep");
  histonames_cutflow.push_back("NEventsSRCutflow");
/*  histonames_cutflow.push_back("NEventsSR_ss_em");
  histonames_cutflow.push_back("NEventsSR_ss_mm");
*/
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
		for( unsigned int selind = 0; selind < histonames_cutflow.size(); selind++ ){
                string histoname = "h_"+leptype.at(lepind)+"_event_"+histonames_cutflow.at(selind);
                histos_cutflow[histoname] = new TH1D(histoname.c_str(),histoname.c_str(),100,0.5,100.5);
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
}

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

 // if( isData() )             cout << "Running on Data."        << endl;
 // else                        cout << "Running on MC.  "        << endl;

  double nel = 0;
  double nmu = 0;
  double npass = 0;

  cout<<selection<<endl;
  if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : begin scan chain  " <<endl;
  bookHistos(selection.c_str());  
  if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : booked histograms " <<endl;
  
  // do this once per job
 const char* json_file ="/home/users/olivito/mt2_80x/MT2Analysis/babymaker/jsons/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON_unblind18_sorted_snt.txt";
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  set_goodrun_file(json_file);
	  string histname = "dummy";
	  string version = "dummy";
  //---------------------------------------------------//
  //         read reweighting/counter hists            //
  //---------------------------------------------------//
  TH1F * h_vtxweight = NULL;
  TFile * f_vtx = NULL;
  TH1F * h_xsecweight = NULL;
  TFile * f_xsec = NULL;
  // Final scale factor histograms for selected leptons
//	f_vtx = TFile::Open("inputhists/nvtx_ratio.root","READ");
//	h_vtxweight = (TH1F*)f_vtx->Get("h_vtx_ratio")->Clone("h_vtxweight");
//	h_vtxweight->SetDirectory(rootdir);
//	f_vtx->Close();
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
       if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" :....finished..... " <<endl;

	TFile f(currentFile->GetTitle());
    TTree *tree = dynamic_cast<TTree*>(f.Get("t"));
    cms3_triboson.Init(tree);
    // event loop
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  cms3_triboson.GetEntry(event);
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
         if( !isData()) {
          if( TString(sample).Contains("wjets_ht100")&&(gen_ht()>100)) continue; //stitch samples
          if( TString(sample).Contains("zjets_ht100")&&(gen_ht()>100)) continue; //stitch samples
         }
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
	  //         MET filter, trigger and json      //
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
  /*        bool skim_isFastsim = (TString(sample).Contains("SMS"));           
	  if (isData() && usejson && !goodrun(run(), ls()) ) continue;
          if (isData() &&!filt_met())   continue;
          if (isData() &&!filt_badMuonFilter())   continue;
          if (isData() &&!filt_badChargedCandidateFilter())   continue;
          if (isData() &&!filt_jetWithBadMuon())   continue;
          if (isData() &&!filt_pfovercalomet())   continue;
*/	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//

	  if( isData() ) {
		DorkyEventIdentifier id(run(), evt(), lumi());
        	if (is_duplicate(id) ){
		  ++nDuplicates;
		  continue;
		}
          }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : removed duplicates   " <<endl;

	  //~-~-~-~-~-~-~-~~-~-~-//
	  //    primary vertex   //
	  //~-~-~-~-~-~-~-~-~-~-//

	   if(nVert()<0)                                           continue;

	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
          float luminosity = 35.9;
	  if( isData() || (TString(sample).Contains("SMS"))){
		  weight *= 1.0;
	   } else if( !isData()){
                  weight *= evt_scale1fb();//event_weight(selection.c_str());
            if( TString(sample).Contains("www_2l_ext0")) weight *= 0.066805*91900./(91900.+164800.);//(208fb/1pb)*BR(WWW—> >=2l)*combineweight
            if( TString(sample).Contains("www_2l_ext1")) weight *= 0.066805*164800./(91900.+164800.);//(208fb/1pb)*BR(WWW—> >=2l)*combineweight
             if( TString(selection).Contains("yield")||TString(selection).Contains("cutflow"))  weight *= luminosity;//scale by lumi
                  //scale1fb for private signal points
	  }
	  if( !isData() && dovtxreweighting ){	
    	         //weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(nvtxs()));		
    	         weight *= puWeight();		
	  }
          if( !isData() && applybtagsf){
                 if(TString(selection).Contains("btagsfup")) weight *= weight_btagsf_heavy_UP();
                 else if(TString(selection).Contains("btagsfdn")) weight *= weight_btagsf_heavy_DN();
                 else weight *= weight_btagsf();
          }
/*          if( !isData() && applylepsf) {
                  //weight *= weight_lepSF()*weight_vetoLepSF();
                  if(TString(sample).Contains("SMS") ) {weight *=weight_lepSF();}
                  else { weight *= lepSF;}
           }
  */       
          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //    fill cutflows and counters  // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
           if(TString(selection).Contains("cutflow")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : cutflow" <<endl;
           histname = Form("h_%s_event_NEventsSRCutflow","lep");
          /*histos_cutflow[histname]->Fill(2,weight); //trigger
          if(passcutflow("step1")) histos_cutflow[histname]->Fill(3,weight); //one lept
          if(passcutflow("step2")) histos_cutflow[histname]->Fill(4,weight); //lep_veto
          if(passcutflow("step3"))  histos_cutflow[histname]->Fill(5,weight); //track veto
          if(passcutflow("step4"))  histos_cutflow[histname]->Fill(6,weight); //tau veto
          if(passcutflow("step5"))  histos_cutflow[histname]->Fill(7,weight); //two jets
          if(passcutflow("step6"))  histos_cutflow[histname]->Fill(8,weight); //two good btags
          if(passcutflow("step7"))  histos_cutflow[histname]->Fill(9,weight); //
          if(passcutflow("step8"))  histos_cutflow[histname]->Fill(10,weight); //mt
          if(passcutflow("step9"))  histos_cutflow[histname]->Fill(11,weight); //mbb
          if(passcutflow("step10"))  histos_cutflow[histname]->Fill(12,weight); //mct
        */ 
           }
           if(TString(selection).Contains("sr_yield")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           if(TString(selection).Contains("raw")) weight = 1;
           histname = Form("h_%s_event_NEventsSR_ss","lep");
           if(passSR(Form("ss_%s",selection.c_str()))) histos_cutflow[histname]->Fill(hyp_type_looper(selectedLeps("ss")),weight);
           if(passSR(Form("trilep_SFOS0_%s",selection.c_str()))) histos_cutflow[histname]->Fill(2.9,weight);
           if(passSR(Form("trilep_SFOS1_%s",selection.c_str()))) histos_cutflow[histname]->Fill(3.9,weight);
           if(passSR(Form("trilep_SFOS2_%s",selection.c_str()))) histos_cutflow[histname]->Fill(4.9,weight);
           continue;
          } 

          if(TString(selection).Contains("trilep_yield")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           if(!passSR(selection.c_str()))   continue;
           histname = Form("h_%s_event_NEventsSR_trilep","lep");
           if(passSR("trilep_SFOS0")) histos_cutflow[histname]->Fill(-0.1,weight);
           if(passSR("trilep_SFOS1")) histos_cutflow[histname]->Fill(0.9,weight);
           if(passSR("trilep_SFOS2")) histos_cutflow[histname]->Fill(1.9,weight);
           continue;
         } 
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
         // gen selection  ---NEED CLEANUP//
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

        if(TString(selection).Contains("gensel")){ cout<<" genselection needs to be written, exit"<<endl; return;}
         
	  //-~-~-~-~-~-~-~-~-//
	  //calculate variables//
	  //-~-~-~-~-~-~-~-~-//

	  float event_met_pt = met_pt();
	  float event_met_ph = met_phi();
          float MET = met_pt();
          float METPhi = met_phi();
          float METx = MET*TMath::Cos(METPhi);
          float METy = MET*TMath::Sin(METPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
          metlv.SetPxPyPzE(METx,METy,0.,MET);
	  //-~-~-~-~-~-~-~-~-//
	  //  selections     //
	  //-~-~-~-~-~-~-~-~-//
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : selection functions " <<endl;
          npass += weight;
          histname = Form("h_%s_event_NEventsSRCutflow","lep");
          //if(TString(selection).Contains("presel") && !passPreselection(selection, histos_cutflow[histname]))   continue;
          if(TString(selection).Contains("presel") && !passPreselection(selection))   continue;
          if(TString(selection).Contains("sr") &&  !passSR(selection)) continue;
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
          cout<<"Run_Number:"<<run()<<":Lum:"<< lumi() <<":EventNumber:"<< evt()<<endl;
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
          double mjj(-999),deta_jj(-999),pt_sys(-999),mctjj(-999),ptjj(-999),ptj1(-999),ptj2(-999), ptll(-999), mjj_lead(-999), ptlll(-999), mlll(-999);
          vector<int> goodleps = selectedLeps(selection);                                  //find good leptons
          vector<int> goodjets =  selectedjets();
          vector<int> veto_jets =  vetojets();
          vector<int> forward_jets =  forwardjets();
          pt_sys = ptlljj(goodleps,goodjets);
          mctjj = mct(goodjets); 
          if(goodjets.size()>1){
             mjj = mjj_dRmin(goodjets);
             mjj_lead = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).mass();
             ptjj = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).pt();
             deta_jj = fabs(jets_p4().at(goodjets.at(0)).eta() - jets_p4().at(goodjets.at(1)).eta());
             ptj1 = jets_p4().at(goodjets.at(0)).pt();
             ptj2 = jets_p4().at(goodjets.at(1)).pt();
          }
          if(goodleps.size()>1){
           int ilep1 = lep_genPart_index().at(goodleps.at(0));
           int ilep2 = lep_genPart_index().at(goodleps.at(1));
          ptll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).pt();  
          cout<<hyp_class()<<":"<<lep_motherIdSS().at(goodleps.at(0))<<":"<<lep_motherIdSS().at(goodleps.at(1))<<":"<<lep_3ch_agree().at(0)<<":"<<lep_3ch_agree().at(1) <<endl;

 if(lep_charge().at(goodleps.at(0))!=genPart_charge().at(ilep1) || lep_charge().at(goodleps.at(1))!=genPart_charge().at(ilep2))          cout<<__LINE__<< lep_charge().at(goodleps.at(0))<<":"<<lep_charge().at(goodleps.at(1)) <<":"<<genPart_charge().at(ilep1)<<":"<<genPart_charge().at(ilep2)<<endl;

          }
          if(goodleps.size()>2){
          ptlll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))+lep_p4().at(goodleps.at(2))).pt();  
          mlll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))+lep_p4().at(goodleps.at(2))).mass();  
          }

          string region = selection;
          fillHist( "event", "njets"  , region.c_str(), njets()    , weight );
          fillHist( "event", "nleps"  , region.c_str(), nlep()  , weight );
          fillHist( "event", "nveto_leptons"  , region.c_str(), nveto_leptons()    , weight );
          fillHist( "event", "nisoTrack_mt2"  , region.c_str(), nisoTrack_mt2()    , weight );
          fillHist( "event", "nbjets"  , region.c_str(), nBJetLoose(), weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep_p4().at(0).pt()      , weight );
          fillHist( "event", "deta_jj"   , region.c_str(), deta_jj     , weight );
//         fillHist( "event", "mll"    , region.c_str(), trileptype_dilepmass(goodleps).second, weight );
          fillHist( "event", "mjj"    , region.c_str(),  mjj   , weight );
          fillHist( "event", "mjj_lead"    , region.c_str(),  mjj_lead , weight );
	  //fillHist( "event", "relIso03EA" , region.c_str(), lep_relIso03().at(0)        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep_relIso03().at(goodleps.at(0))*lep_pt().at(goodleps.at(0))        , weight );	 
	  fillHist( "event", "absIso03EA_subleading" , region.c_str(), lep_relIso03().at(goodleps.at(1))*lep_pt().at(goodleps.at(1))        , weight );	 
          fillHist( "event", "ptlljj"   , region.c_str(),pt_sys     , weight );
	  fillHist( "event", "mtMax"    , region.c_str(), maxMt(goodleps)   , weight );
	  //fillHist( "event", "MT2lb"    , region.c_str(), MT2lb  , weight );
          //fillHist( "event", "mbb"    , region.c_str(),  m_bb   , weight );
	  //fillHist( "event", "dRbb"    , region.c_str(), dRbb   , weight );
	  fillHist( "event", "MCT"    , region.c_str(),  mctjj   , weight );
	  fillHist( "event", "ptjj"    , region.c_str(),  ptjj   , weight );
	  fillHist( "event", "ptll"    , region.c_str(),  ptll   , weight );
	  fillHist( "event", "ptlll"    , region.c_str(),  ptlll   , weight );
	  fillHist( "event", "mlll"    , region.c_str(),  mlll   , weight );
	  //fillHist( "event", "ptlbb"    , region.c_str(),  ptlbb   , weight );
          //fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptj1"   , region.c_str(), ptj1   , weight );
          fillHist( "event", "ptj2"   , region.c_str(), ptj2    , weight );
          //fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
          //fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  //fillHist( "event", "MT2W" , region.c_str(), MT2W()       , weight );	 
	  //fillHist( "event", "dphibb" , region.c_str(), getdphibb()       , weight );	 
	  //fillHist( "event", "ptb1overptb2" , region.c_str(), ptb1/ptb2      , weight );	 
	  //fillHist( "event", "deltaphi_lep_met" , region.c_str(), abs(ROOT::Math::VectorUtil::DeltaPhi(lep1_p4(),metlv)), weight );	 
          //histMCTvsMT->Fill(mctbb,mt_met_lep(),weight);
          //histMCTvsMET->Fill(mctbb,event_met_pt,weight);
          //histMCTvsMbb->Fill(mctbb,m_bb,weight);
//	  if(mctbb>150) { 
          //cout<<"Run_Number:"<<run()<<"Lum:"<< evt() <<":EventNumber:"<< evt() << "lep_pdgid"<<lep1_pdgid() <<":lep_pt: "<<lep1_p4().pt()<<  ":lep_eta: "<<lep1_p4().eta()<<":met:"<<event_met_pt<<":met_phi:"<<event_met_ph <<":mct:"<< mctbb<< ":mt:"<< mt_met_lep()<<endl;
//     }
           
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
          if( evt_type()==1 ){
		hist = Form("h_lep_dilep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( evt_type()==0 ){
		hist = Form("h_lep_trilep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
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
