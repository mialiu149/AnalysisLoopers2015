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
#include "TH2D.h"
#include "TH2F.h"
#include "TMath.h"

#include "Math/VectorUtil.h"

#include "templateLooper.h"
#include "../sharedCode/leptree_v0.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/ZJetsSelection.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"
#include "../../CORE/Tools/badEventFilter.h"

using namespace std;
using namespace duplicate_removal;
using namespace zjetssel;
using namespace leptree_v0_np;
const bool debug = false;
const bool usejson = true;
const bool dovtxreweighting = false;
const bool applyLepSFs = true;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::bookHistos(std::string region){

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
  variable.push_back("ptl2");           variable_bins.push_back(1000);  
  variable.push_back("ptl1_ptl2_diff"); variable_bins.push_back(1000);  
  variable.push_back("met");            variable_bins.push_back(500 );  
  variable.push_back("ht");	        variable_bins.push_back(1000);  
  variable.push_back("mll");	        variable_bins.push_back(1000);  
  variable.push_back("ptll");	        variable_bins.push_back(1000);  
  variable.push_back("lep1_ooEmooP");	variable_bins.push_back(1000);  
  variable.push_back("mt");	        variable_bins.push_back(1000);  
  variable.push_back("njets");          variable_bins.push_back(20  );  
  variable.push_back("ngoodbtags");     variable_bins.push_back(20  );  
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
		//		   -variable_bins.at(varind),
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
  histonames_cutflow.push_back("NEventsCutflow");
  histonames_cutflow.push_back("NEvents1lCR");
  histonames_cutflow.push_back("NEvents2lCR");
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
		for( unsigned int selind = 0; selind < histonames_cutflow.size(); selind++ ){
  //bookHistTH1D(Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
  //             Form("h_%s_%s",leptype.at(lepind).c_str(),histonames_cutflow.at(selind).c_str()),
  //             8,0.5,8.5
  //            );//book histos for all SRs and CRs
                string histoname = "h_"+leptype.at(lepind)+"_event_"+histonames_cutflow.at(selind);
                histos_cutflow[histoname] = new TH1D(histoname.c_str(),histoname.c_str(),10,0.5,10.5);
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

  histPtvsEta_den = new TH2F( "h_histPtvsEta_den", "h_histPtvsEta_den", 1000,0,1000,1000,0,1000); histPtvsEta_den->Sumw2();
  histPtvsEta_num = new TH2F( "h_histPtvsEta_num", "h_histPtvsEta_num", 1000,0,1000,1000,0,1000); histPtvsEta_num->Sumw2();
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
  //
  // Open lepton SF histos
  //
  TFile *f_el_SF;
  TFile *f_mu_SF_id;
  TFile *f_mu_SF_iso;
  
  TH2D *h_el_SF = NULL;
  TH2D *h_mu_SF = NULL;
  
  if(applyLepSFs && !(TString(sample).Contains("data"))){
    
    f_el_SF     = new TFile("lepsf/kinematicBinSFele.root", "read");
    f_mu_SF_id  = new TFile("lepsf/TnP_MuonID_NUM_MediumID_DENOM_generalTracks_VAR_map_pt_eta.root", "read");
    f_mu_SF_iso = new TFile("lepsf/TnP_MuonID_NUM_MiniIsoTight_DENOM_LooseID_VAR_map_pt_eta.root");
    
    TH2D *h_el_SF_id_temp  = (TH2D*)f_el_SF->Get("CutBasedMedium");
    TH2D *h_el_SF_iso_temp = (TH2D*)f_el_SF->Get("MiniIso0p1_vs_AbsEta");
    TH2D *h_mu_SF_id_temp  = (TH2D*)f_mu_SF_id->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_tag_IsoMu20_pass");
    TH2D *h_mu_SF_iso_temp = (TH2D*)f_mu_SF_iso->Get("pt_abseta_PLOT_pair_probeMultiplicity_bin0_&_tag_combRelIsoPF04dBeta_bin0_&_tag_pt_bin0_&_PF_pass_&_tag_IsoMu20_pass");

    //out_file->cd();

    TH2D *h_el_SF_id  = (TH2D*)h_el_SF_id_temp->Clone("h_el_SF_id");
    TH2D *h_el_SF_iso = (TH2D*)h_el_SF_iso_temp->Clone("h_el_SF_iso");
    TH2D *h_mu_SF_id  = (TH2D*)h_mu_SF_id_temp->Clone("h_mu_SF_id");
    TH2D *h_mu_SF_iso = (TH2D*)h_mu_SF_iso_temp->Clone("h_mu_SF_iso");
    h_el_SF_id->SetDirectory(rootdir);
    h_el_SF_iso->SetDirectory(rootdir);
    h_mu_SF_id->SetDirectory(rootdir);
    h_mu_SF_iso->SetDirectory(rootdir);
    
    h_el_SF = (TH2D*)h_el_SF_id->Clone("h_el_SF");
    h_el_SF->Multiply(h_el_SF_iso);
    h_el_SF->SetDirectory(rootdir);
    h_mu_SF = (TH2D*)h_mu_SF_id->Clone("h_mu_SF");
    h_mu_SF->Multiply(h_mu_SF_iso);
    h_mu_SF->SetDirectory(rootdir);
    f_el_SF->Close();
    f_mu_SF_id->Close();
    f_mu_SF_iso->Close();
    cout << "loaded lepton SFs" << endl;
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
    leptr_v0.Init(tree);

    // event loop
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	 leptr_v0.GetEntry(event);
         ++nEventsTotal;
      // ~~~~~~~~~~~
      //   continue;
      // ~~~~~~~~~~~
          string histname = "h_lep_event_NEventsCutflow";
          histos_cutflow[histname]->Fill(1,1);
	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
          fflush(stdout);
        }
      }

	 // if ( is_data() && usejson && !goodrun(run(), ls()) ) continue;
//           if (is_data() && metFilterTxt.eventFails(run(), ls(), evt())) {
           //if (!filt_hbhenoise()) {cout<<"failed"<<endl;continue;}
			continue;
           }
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
           string region = selection;
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
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
		hist = Form("h_el_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
	return;
}  

