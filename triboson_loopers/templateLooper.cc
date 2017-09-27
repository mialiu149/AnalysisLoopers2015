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
#include "../sharedCode/TribosonSelection.h"
#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"
#include "../../commonUtils/commonUtils.h"

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
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;             vector <float> variable_bins;
  variable.push_back("ptl1");           variable_bins.push_back(1000);  
  variable.push_back("ptl2");           variable_bins.push_back(1000);  
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
  variable.push_back("absIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA_subleading");	variable_bins.push_back(1000);  
  variable.push_back("MT2W");	        variable_bins.push_back(1000);  
  variable.push_back("MT2lb");          variable_bins.push_back(1000);  
  variable.push_back("njets");          variable_bins.push_back(20  );  
  variable.push_back("flavorbin");          variable_bins.push_back(7  );  
  variable.push_back("nleps");          variable_bins.push_back(20  );  
  variable.push_back("bkgtype");          variable_bins.push_back(20  );  
  variable.push_back("nveto_leptons");          variable_bins.push_back(20  );  
  variable.push_back("nisoTrack_mt2");          variable_bins.push_back(20  );  
  variable.push_back("nbjets");              variable_bins.push_back(20  );  
  variable.push_back("nVert");               variable_bins.push_back(50  );  
  variable.push_back("ptb1overptb2");        variable_bins.push_back(10  );
  variable.push_back("lep_gfit_pt");         variable_bins.push_back(1000);
  variable.push_back("lep_gfit_ptErr");      variable_bins.push_back(10  );
  bookHists(leptype,object,variable,selection,variable_bins);
 //phi and eta plots, they have the same x and y limits.
  vector <string> phivars;
  phivars.push_back("relIso03EA");
  phivars.push_back("ip3d");
  phivars.push_back("ip3derr");
  phivars.push_back("fakerate_weight");
  phivars.push_back("metphi");
  phivars.push_back("dphibb");
  phivars.push_back("dphijj");
  phivars.push_back("dphibMET");
  phivars.push_back("dRjj");
  phivars.push_back("dRl1j1");
  phivars.push_back("dRl1j2");
  phivars.push_back("dRl2j1");
  phivars.push_back("dRl2j2");
  phivars.push_back("dRll");
  phivars.push_back("deta_jj");
  phivars.push_back("deltaphi_lep_met");
  phivars.push_back("deltaphi_lep_leadb");
  phivars.push_back("deltaphi_leadb_met");
  phivars.push_back("mindphi_met_j1_j2");
  phivars.push_back("nbjets_diff");
  phivars.push_back("dR_lep_leadb");
  phivars.push_back("lep_gfit_ratio");   
  phivars.push_back("etal1");   
  phivars.push_back("etal2");   
  phivars.push_back("etaj1");   
  phivars.push_back("etaj2");   
  bookHists(leptype,object,phivars,selection,2000,-3.2,3.2); 
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
  bookHists(leptype,object,genvars,selection, 10,-0.5,9.5); 
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
//    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

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
 	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
          float luminosity = 35.9;
	  float weight = 1.0;
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
         float genmetpt;
         bool gammafake = isgammafake();
         if( !isData()) {
          if( TString(sample).Contains("ht100")&&(gen_ht()>100)) continue; //stitch samples
          if( (TString(sample).Contains("wjets")|| TString(sample).Contains("zjets") || TString(sample).Contains("ttbar_onelep")) && gammafake) continue;
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
          if(!evt_passgoodrunlist()) continue;
          }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : removed duplicates   " <<endl;

	  //~-~-~-~-~-~-~-~~-~-~-//
	  //    primary vertex   //
	  //~-~-~-~-~-~-~-~-~-~-//

	   if(nVert()<0)                                           continue;

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
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
         //         gen selection         //
         //-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

        if(TString(selection).Contains("gensel")){ cout<<" genselection needs to be written, exit"<<endl; return;}
         
          //-~-~-~-~-~-~-~-~-//
	  //  selections     //
	  //-~-~-~-~-~-~-~-~-//
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : selection functions " <<endl;
          npass += weight;
          histname = Form("h_%s_event_NEventsSRCutflow","lep");
          if( !TString(selection).Contains("yield")){
          if(TString(selection).Contains("presel") && !passPreselection(selection))   continue;
          if(TString(selection).Contains("sr") &&  !passSR(selection)) continue;
           }
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
          double mjj(-999),deta_jj(-999),pt_sys(-999),mctjj(-999),ptjj(-999),ptj1(-999),ptj2(-999), ptll(-999), mjj_lead(-999), ptlll(-999), mlll(-999),dRjj(-999),mindphi_met_j1_j2(-999), dphijj(-999),dRll(-999), dRl1j1(-999), dRl1j2(-999), dRl2j1(-999),dRl2j2(-999);
          vector<int> goodleps = selectedLeps(selection);                                  //find good leptons
          if (goodleps.size()<2) continue;
          vector<int> goodjets =  selectedjets();
          vector<int> veto_jets =  vetojets();
          vector<int> forward_jets =  forwardjets();
          pt_sys = ptlljj(goodleps,goodjets);
          mctjj = mct(goodjets); 
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
          if(goodjets.size()>1){
             mjj = mjj_dRmin(goodjets);
             mjj_lead = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).mass();
             ptjj = (jets_p4().at(goodjets.at(0))+jets_p4().at(goodjets.at(1))).pt();
             deta_jj = fabs(jets_p4().at(goodjets.at(0)).eta() - jets_p4().at(goodjets.at(1)).eta());
             ptj1 = jets_p4().at(goodjets.at(0)).pt();
             ptj2 = jets_p4().at(goodjets.at(1)).pt();
             dRjj =  deltaR(jets_p4().at(goodjets.at(0)),jets_p4().at(goodjets.at(1)));
             mindphi_met_j1_j2 = getMinDphi(met_phi(),jets_p4().at(goodjets.at(0)),jets_p4().at(goodjets.at(1)));
             float phib1 = jets_p4().at(goodjets.at(0)).phi();
             float phib2 = jets_p4().at(goodjets.at(1)).phi();
             dphijj = getdphi(phib1,phib2);
          }

           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
           float dilepmass(-999);
           unsigned int lep1_index(0),lep2_index(0);
           int lep3_index(-1);
           unsigned int ilep1(0),ilep2(0),ilep3(0);
           int lep1_id(0),lep2_id(0),lep3_id(0);
           float lep1_pT_org(-999),lep2_pT_org(-999),lep3_pT_org(-999);
           float lep1_pT(-999),lep2_pT(-999),lep3_pT(-999);
           int type_looper = hyp_type_looper(goodleps);                              //find event type
           int trileptype(-9999); if(TString(selection).Contains("trilep") ) trileptype = trileptype_dilepmass(goodleps).first;
           lep1_index = goodleps.at(0);
           lep2_index = goodleps.at(1);
           ilep1 = lep_genPart_index().at(lep1_index);
           ilep2 = lep_genPart_index().at(lep2_index);
           lep1_id = triboson_np::lep_pdgId().at(lep1_index);
           lep2_id = triboson_np::lep_pdgId().at(lep2_index);
           lep1_pT_org = triboson_np::lep_p4().at(lep1_index).pt();
           lep2_pT_org = triboson_np::lep_p4().at(lep2_index).pt();
           lep1_pT = (coneCorrPt(lep1_index)+1)*lep1_pT_org;
           lep2_pT = (coneCorrPt(lep2_index)+1)*lep2_pT_org;
           LorentzVector lep1_p4 = triboson_np::lep_p4().at(lep1_index);
           LorentzVector lep2_p4 = triboson_np::lep_p4().at(lep2_index);
           LorentzVector lep1_p4_coneCorr(lep1_pT,lep1_p4.eta(),lep1_p4.phi(),lep1_p4.energy()*lep1_pT/lep1_pT_org);    
           LorentzVector lep2_p4_coneCorr(lep2_pT,lep2_p4.eta(),lep2_p4.phi(),lep2_p4.energy()*lep2_pT/lep2_pT_org);    
           ptll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).pt();  
           dilepmass = (lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))).mass();
           dRll = deltaR(lep1_p4,lep2_p4);

           if(goodleps.size()>2) {
               lep3_index = goodleps.at(2);
               ilep3 = lep_genPart_index().at(goodleps.at(2));
               lep3_id = triboson_np::lep_pdgId().at(lep3_index);
               lep3_pT_org = triboson_np::lep_p4().at(lep3_index).pt();
               lep3_pT = (coneCorrPt(lep3_index)+1)*lep3_pT_org;
               ptlll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))+lep_p4().at(goodleps.at(2))).pt();  
               mlll=(lep_p4().at(goodleps.at(0))+lep_p4().at(goodleps.at(1))+lep_p4().at(goodleps.at(2))).mass();  
           }

          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
           if(goodjets.size()>1){ 
           dRl1j1 = deltaR(lep1_p4,jets_p4().at(goodjets.at(0)));
           dRl1j2 = deltaR(lep1_p4,jets_p4().at(goodjets.at(1)));
           dRl2j1 = deltaR(lep2_p4,jets_p4().at(goodjets.at(0)));
           dRl2j1 = deltaR(lep2_p4,jets_p4().at(goodjets.at(1)));
           }
           string region = selection;
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
         //int  type = gentype(lep1_index,lep2_index);
         int type = gentype(lep1_index,lep2_index,lep3_index); 
          // fix k-factors for MC samples 
         if( !isData() && TString(selection).Contains("ss")) {
          if( TString(sample).Contains("truess") && type!=0) continue; 
          if( TString(sample).Contains("threelep") && type!=1) continue; 
          if( TString(sample).Contains("chargeflip") && type!=2) continue;
          if( TString(sample).Contains("lostlep") && type!=3) continue;
          if( TString(sample).Contains("jetfake") && type!=4) continue;
          if( TString(sample).Contains("gammafake") && type!=5) continue;
         }
         else if( !isData() && TString(selection).Contains("trilep")) {
          if( TString(sample).Contains("threelep") && type!=1 && type!=0) continue; 
          if( TString(sample).Contains("lostlep") && type!=3) continue;
          if( TString(sample).Contains("jetfake") && type!=4) continue;
          if( TString(sample).Contains("gammafake") && type!=5) continue;
         }
	
          if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : will fill histograms " <<endl;
             if(TString(selection).Contains("fakerate")){                 
             if(!isData() && !TString(selection).Contains("yield")) weight *=luminosity;
             bool subtract = !isData()&& (type==0||type==1||type==2||type==3);
             weight *= fakerateweight(subtract,selection,lep1_index,lep2_index,lep3_index);
            }
           if(TString(selection).Contains("sr_yield")){
           if(debug) cout<< "DEBUG::LINE:"<< __LINE__ <<" : fill cutflow histograms " <<endl;
           if(TString(selection).Contains("raw")) weight = 1;
           histname = Form("h_%s_event_NEventsSR_ss","lep");
           if(passSR(Form("ss_%s",selection.c_str()))) histos_cutflow[histname]->Fill(hyp_type_looper(selectedLeps(Form("ss_%s",selection.c_str()))),weight);
           if(passSR(Form("trilep_SFOS0_%s",selection.c_str()))) histos_cutflow[histname]->Fill(2.9,weight);
           if(passSR(Form("trilep_SFOS1_%s",selection.c_str()))) histos_cutflow[histname]->Fill(3.9,weight);
           if(passSR(Form("trilep_SFOS2_%s",selection.c_str()))) histos_cutflow[histname]->Fill(4.9,weight);
           continue;
          } 
         fillHist( "event", "njets"  , region.c_str(), goodjets.size()    , weight );
          fillHist( "event", "fakerate_weight"  , region.c_str(), weight   ,1 );
          fillHist( "event", "bkgtype"  , region.c_str(), type  , weight );
        if(TString(selection).Contains("ss")) {
          if(type_looper==0) fillHist( "event", "flavorbin"  , region.c_str(), 1, weight );
          if(type_looper==2) fillHist( "event", "flavorbin"  , region.c_str(), 2, weight );
          if(type_looper==1) fillHist( "event", "flavorbin"  , region.c_str(), 3, weight );
         }
        if(TString(selection).Contains("trilep")) {
         fillHist( "event", "flavorbin"  , region.c_str(), trileptype+1, weight );
         }
          fillHist( "event", "nleps"  , region.c_str(), nlep()  , weight );
          fillHist( "event", "nveto_leptons"  , region.c_str(), nveto_leptons()    , weight );
          fillHist( "event", "nisoTrack_mt2"  , region.c_str(), nisoTrack_mt2()    , weight );
          fillHist( "event", "nbjets"  , region.c_str(), nBJetLoose(), weight );
          fillHist( "event", "met"    , region.c_str(), met_pt(), weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep_p4().at(lep1_index).pt()      , weight );
          fillHist( "event", "ptl2"   , region.c_str(), lep_p4().at(lep2_index).pt()      , weight );
          fillHist( "event", "etal1"   , region.c_str(), lep_p4().at(lep1_index).eta()      , weight );
          fillHist( "event", "etal2"   , region.c_str(), lep_p4().at(lep2_index).eta()      , weight );
        if(goodjets.size()>0)  fillHist( "event", "etaj1"   , region.c_str(), jets_p4().at(goodjets.at(0)).eta()      , weight );
        if(goodjets.size()>1)  fillHist( "event", "etaj2"   , region.c_str(), jets_p4().at(goodjets.at(1)).eta()      , weight );
          fillHist( "event", "deta_jj"   , region.c_str(), deta_jj     , weight );
          fillHist( "event", "dRjj"   , region.c_str(), dRjj     , weight );
          fillHist( "event", "dRll"   , region.c_str(), dRll     , weight );
          fillHist( "event", "dRl1j1"   , region.c_str(), dRl1j1     , weight );
          fillHist( "event", "dRl1j2"   , region.c_str(), dRl1j2     , weight );
          fillHist( "event", "dRl2j1"   , region.c_str(), dRl2j1     , weight );
          fillHist( "event", "dRl2j2"   , region.c_str(), dRl2j2     , weight );
          fillHist( "event", "dphijj"   , region.c_str(), dphijj     , weight );
          fillHist( "event", "mindphi_met_j1_j2"   , region.c_str(), mindphi_met_j1_j2     , weight );
          fillHist( "event", "mll"    , region.c_str(),  dilepmass, weight);
          fillHist( "event", "mjj"    , region.c_str(),  mjj   , weight );
          fillHist( "event", "mjj_lead"    , region.c_str(),  mjj_lead , weight );
          // check where the mismodeling come from.
          fillHist( "event", "relIso03EA" , region.c_str(), lep_relIso03EAv2().at(lep2_index)    , weight );	 
          fillHist( "event", "relIso03EA" , region.c_str(), lep_relIso03EAv2().at(lep1_index)    , weight );	 
          fillHist( "event", "ip3d" , region.c_str(), lep_ip3d().at(lep1_index)    , weight );	 
          fillHist( "event", "ip3d" , region.c_str(), lep_ip3d().at(lep2_index)    , weight );	 
          fillHist( "event", "ip3derr" , region.c_str(), lep_ip3derr().at(lep1_index)    , weight );	 
          fillHist( "event", "ip3derr" , region.c_str(), lep_ip3derr().at(lep2_index)    , weight );	 
	  //fillHist( "event", "absIso03EA" , region.c_str(), lep_relIso03().at(goodleps.at(0))*lep_pt().at(goodleps.at(0))        , weight );	 
	  //fillHist( "event", "absIso03EA_subleading" , region.c_str(), lep_relIso03().at(goodleps.at(1))*lep_pt().at(goodleps.at(1))        , weight );	 
          fillHist( "event", "ptlljj"   , region.c_str(),pt_sys     , weight );
	  fillHist( "event", "mtMax"    , region.c_str(), maxMt(goodleps)   , weight );
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
void templateLooper::bookHists(vector <string> leptype, vector <string> object, vector <string> variable, vector <string> selection, int nbins, float xmin, float xmax){
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
                                   nbins,                  
				   xmin,
				   xmax);
		}
	  }
     }
  }
}

void templateLooper::bookHists(vector <string> leptype, vector <string> object, vector <string> variable, vector <string> selection, vector <float> variable_bins){
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
}

void templateLooper::fillHist( string obj, string var, string sel, float value, float weight ) {
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
