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
#include "../sharedCode/V00_00_02.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/StopMoriond2016.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"

using namespace std;
using namespace duplicate_removal;
using namespace V00_00_02_np;
const bool debug = false;
const bool usejson = true;
const bool dovtxreweighting = true;

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
  leptype.push_back("el_br");
  leptype.push_back("el_ec");
  leptype.push_back("mu");
  leptype.push_back("lep");
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;      vector <float> variable_bins;
  variable.push_back("ptl1");           variable_bins.push_back(1000);  
  variable.push_back("met");            variable_bins.push_back(500 );  
  variable.push_back("ht");	        variable_bins.push_back(1000);  
  variable.push_back("lep1_ooEmooP");	variable_bins.push_back(1000);  
  variable.push_back("mt");	        variable_bins.push_back(1000);  
  variable.push_back("njets");          variable_bins.push_back(20  );  
  variable.push_back("nVert");          variable_bins.push_back(50 );  
  variable.push_back("relIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("absIso03EA");	variable_bins.push_back(1000);  
  variable.push_back("nhiso");	        variable_bins.push_back(1000);  
  variable.push_back("emiso");	        variable_bins.push_back(1000);  
  variable.push_back("chiso");	        variable_bins.push_back(1000);  

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

  // random extra hists here
  bookHist("h_templ_met", "h_templ_met", 500,0,500);

  vector <string> phivars;
  phivars.push_back("metphi");
  phivars.push_back("deltaphi_lep_met");
  phivars.push_back("metphir");
  phivars.push_back("metphi20");
  phivars.push_back("metphi40");
  phivars.push_back("metphi60");
  phivars.push_back("mhtphi");
 
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

  //--------------------// 
  // book Cutflow hists //
  //--------------------//
  vector<string> histonames_cutflow; histonames_cutflow.clear();
  histonames_cutflow.push_back("NEventsSR");
  histonames_cutflow.push_back("NEvents1lCR");
  histonames_cutflow.push_back("NEvents2lCR");
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
		for( unsigned int selind = 0; selind < histonames_cutflow.size(); selind++ ){
  //bookHistTH1D(Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
  //             Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
  //             8,0.5,8.5
  //            );//book histos for all SRs and CRs
                string histoname = "h_"+leptype.at(lepind)+"_event_"+histonames_cutflow.at(selind)+"_"+region.c_str();
                histos_cutflow[histoname] = new TH1D(histoname.c_str(),histoname.c_str(),8,0.5,8.5);
                histos_cutflow[histoname]->Sumw2();
		}
  }

 //---------------------------------------------------------//
 // initialize histograms here for all regions of interests //
 //---------------------------------------------------------//
 
  /*
  bookHist("h_mm_event_drll_2jets", "h_mm_event_drll_2jets", 500,0,5);
  bookHist("h_em_event_drll_2jets", "h_em_event_drll_2jets", 500,0,5);
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

  cout<<selection<<endl;
  
  bookHistos(selection.c_str());

  double npass = 0;
  
  // do this once per job
  const char* json_file ="../json/json_270715_golden.txt";
  set_goodrun_file(json_file);
   eventFilter metFilterTxt;
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
   if ( TString(sample).Contains("data") ) {
   cout<<"Loading bad event files ..."<<endl;
    // old lists for partial dataset
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
    v00_00_02.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  v00_00_02.GetEntry(event);
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

	 // if ( is_data() && usejson && !goodrun(run(), ls()) ) continue;
           if (!filt_eebadsc()) continue;
           if (!filt_hbhenoise()) continue;
           if (is_data() && metFilterTxt.eventFails(run(), ls(), evt())) {
		//cout<<"Found bad event in data: "<<run()<<", "<<ls()<<", "<<evt()<<endl;
			continue;
           }
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
	  //~-~-~-~-~-~-~-~~-//
	  // primary vertex  //
	  //~-~-~-~-~-~-~-~-~//
	   if(nvtxs()<0)               continue;

	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( is_data() ){
		weight = 1.0;
	  }else if( !is_data() ){
                if( TString(selection).Contains("yield"))  weight *= 2.1*scale1fb();
		else weight *= scale1fb();
	  }

	  if( !is_data() && dovtxreweighting ){	
    	  weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(nvtxs()));		
	  }
	  
	  float event_met_pt = pfmet();
	  float event_met_ph = pfmet_phi();

          //~-~-~-~-~-~-~-~-//
          // event selection// 
	  //~-~-~-~-~-~-~-~-//
          if( !passPreselection() )       continue;
          if( ak4_HT() < 150  )           continue;

          //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
          //    fill cutflow histograms     // 
	  //~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

          if(TString(selection).Contains("yield")){
           //signal
           string histname ="h_lep_event_NEventsSR_yield";
           if(passSR("bin1")) histos_cutflow[histname]->Fill(1,weight); 
           if(passSR("bin2")) histos_cutflow[histname]->Fill(2,weight); 
           if(passSR("bin3")) histos_cutflow[histname]->Fill(3,weight); 
           if(passSR("bin4")) histos_cutflow[histname]->Fill(4,weight); 
           if(passSR("bin5")) histos_cutflow[histname]->Fill(5,weight); 
           if(passSR("bin6")) histos_cutflow[histname]->Fill(6,weight); 
           if(passSR("bin7")) histos_cutflow[histname]->Fill(7,weight); 
           if(passSR("bin8")) histos_cutflow[histname]->Fill(8,weight); 
           //CR1l
           histname = "h_lep_event_NEvents1lCR_yield";
           if(pass1lCR("bin1")) histos_cutflow[histname]->Fill(1,weight); 
           if(pass1lCR("bin2")) histos_cutflow[histname]->Fill(2,weight); 
           if(pass1lCR("bin3")) histos_cutflow[histname]->Fill(3,weight); 
           if(pass1lCR("bin4")) histos_cutflow[histname]->Fill(4,weight); 
           if(pass1lCR("bin5")) histos_cutflow[histname]->Fill(5,weight); 
           if(pass1lCR("bin6")) histos_cutflow[histname]->Fill(6,weight); 
           if(pass1lCR("bin7")) histos_cutflow[histname]->Fill(7,weight); 
           if(pass1lCR("bin8")) histos_cutflow[histname]->Fill(8,weight); 
           //CR2l
           histname = "h_lep_event_NEvents2lCR_yield";
           if(pass2lCR("bin1")) histos_cutflow[histname]->Fill(1,weight); 
           if(pass2lCR("bin2")) histos_cutflow[histname]->Fill(2,weight); 
           if(pass2lCR("bin3")) histos_cutflow[histname]->Fill(3,weight); 
           if(pass2lCR("bin4")) histos_cutflow[histname]->Fill(4,weight); 
           if(pass2lCR("bin5")) histos_cutflow[histname]->Fill(5,weight); 
           if(pass2lCR("bin6")) histos_cutflow[histname]->Fill(6,weight); 
           if(pass2lCR("bin7")) histos_cutflow[histname]->Fill(7,weight); 
           if(pass2lCR("bin8")) histos_cutflow[histname]->Fill(8,weight); 
           continue;
          }

          if(TString(selection).Contains("1l")) {
          if( !pass1lCR(selection.c_str())) continue;
          }
     
          if(TString(selection).Contains("2l")) {
          if( !pass2lCR(selection.c_str())) continue;
          }

          if(TString(selection).Contains("SR")) {
          if( !passSR(selection.c_str()))   continue;
          }

          //if( !passRegion(selection.c_str())) continue; 
 	  if( lep1_is_mu()) nmu++;
	  if( lep1_is_el()) nel++;
          //regions of interest
          //if( ngoodjets() >=3 && event_met_pt > 150 && ngoodbtags()<1 &&  mt_met_lep() > 120 && lep1_relIso03EA()*lep1_pt() < 5) njet2_met100 = true; 
          float MET = pfmet();
          float METPhi = pfmet_phi();
          float METx = MET*TMath::Cos(METPhi);
          float METy = MET*TMath::Sin(METPhi);
          ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > metlv;
          metlv.SetPxPyPzE(METx,METy,0.,MET);
//          if(mindphi_met_j1_j2() < 0.8) continue;
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
	 
          string region = selection;
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "lep1_ooEmooP"     , region.c_str(), lep1_ooEmooP()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
	  fillHist( "event", "deltaphi_lep_met" , region.c_str(), ROOT::Math::VectorUtil::DeltaPhi(lep1_p4(),metlv) , weight );	 
          if(mt_met_lep()>175 && fabs(lep1_eta()) > 1.6 &&lep1_is_el())
          { 
           cout<<"Run_Number:"<<run()<< ":EventNumber:"<< evt() <<":lep_pt: "<<lep1_pt()<<":met:"<<event_met_pt<<":met_phi:"<<event_met_ph <<":diff:"<<event_met_pt-lep1_pt()<<":diff_ratio:"<<(event_met_pt-lep1_pt())/lep1_pt() << ":mt:"<<mt_met_lep()<<endl;
           //cout<<run()<<":"<<ls()<<":"<<evt()<<"\n"<<endl; 
           }
	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
         npass += weight;
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
          if( lep1_is_el() && fabs(lep1_eta())>1.6&&fabs(lep1_eta())<2.1 ){
		hist = Form("h_el_ec_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( lep1_is_el() &&fabs(lep1_eta())<1.4 ){
		hist = Form("h_el_br_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
	  if( lep1_is_mu() ){
         	hist = Form("h_mu_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
	return;
}  

