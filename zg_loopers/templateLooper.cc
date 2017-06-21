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
#include "TMath.h"

#include "Math/VectorUtil.h"

#include "templateLooper.h"
#include "../sharedCode/V00_00_01.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"

using namespace std;
using namespace duplicate_removal;

//using V00_00_01; 
const bool debug = false;
const bool usejson = true;
const bool dovtxreweighting = true;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::bookHistos(){

  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("el");
  leptype.push_back("mu");
  vector <string> object;
  object.push_back("event");
  vector <string> selection;
  selection.push_back("inclusive");
  selection.push_back("passtrig");
  selection.push_back("njet2_incl");
  selection.push_back("njet3_incl");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("ptl1");    variable_bins.push_back(1000);  
  variable.push_back("met");     variable_bins.push_back(500 );  
  // variable.push_back("met_phi"); variable_bins.push_back(500 );  
  // variable.push_back("met_phir");variable_bins.push_back(500 );  
  variable.push_back("ht");	     variable_bins.push_back(1000);  
  variable.push_back("mt");	     variable_bins.push_back(1000);  
  variable.push_back("njets");   variable_bins.push_back(20  );  
  variable.push_back("nVert");   variable_bins.push_back(50 );  

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < variable.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					    variable .at(varind).c_str(),
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
/*
  bookHist("h_ll_event_drll_2jets", "h_ll_event_drll_2jets", 500,0,5);
  bookHist("h_ee_event_drll_2jets", "h_ee_event_drll_2jets", 500,0,5);
  bookHist("h_mm_event_drll_2jets", "h_mm_event_drll_2jets", 500,0,5);
  bookHist("h_em_event_drll_2jets", "h_em_event_drll_2jets", 500,0,5);
*/
}

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  // if( cms3.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  double nel = 0;
  double nmu = 0;
  double nemu = 0;

  double ne = 0;

  double nem_2jets = 0;
  double nem_2jets_mll = 0;

  cout<<selection<<endl;
  
  bookHistos();

  double npass = 0;
  
  // do this once per job
  const char* json_file ="../json/json_270715_golden.txt";
  set_goodrun_file(json_file);

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

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
    cms3.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  cms3.GetEntry(event);
      ++nEventsTotal;

	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
          fflush(stdout);
        }
      }

	 // if ( cms3.is_data() && usejson && !goodrun(cms3.run(), cms3.ls()) ) continue;
//         cout<<"passed"<<endl;

	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  if( cms3.is_data() ) {
		DorkyEventIdentifier id(cms3.run(), cms3.evt(), cms3.ls());
		if (is_duplicate(id) ){
		  ++nDuplicates;
		  continue;
		}
          }
	  //~-~-~-~-~-~-~-~~-//
	  // primary vertex  //
	  //~-~-~-~-~-~-~-~-~//
	   if(cms3.nvtxs()<0)               continue;
	  
	  //~-~-~-~-~-~-~-~~-//
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

       	//  if( !(cms3.HLT_SingleMuNoEta()||cms3.HLT_SingleMuNoIso()||cms3.HLT_SingleMuNoIsoNoEta() || cms3.HLT_SingleEl27())) continue;//trigger
           if(!(cms3.HLT_DiEl()||cms3.HLT_DiMu())) continue;

	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( cms3.is_data() ){
		weight = 1.0;
	  }else if( !cms3.is_data() ){
		weight *= cms3.scale1fb();
	  }

	  if( !cms3.is_data() && dovtxreweighting ){	
    	  weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(cms3.nvtxs()));		
	  }
	  
	  float event_met_pt = cms3.pfmet();
	  float event_met_ph = cms3.pfmet_phi();

	  //~-~-~-~-~-~-~-~-~//
	  // region selection//
	  //~-~-~-~-~-~-~-~-~//
          bool passtrig(false); bool njet2_incl(false); bool njet3_incl(false);
	  //~-~-~-~-~-~-~-~-//
          // event selection// 
	  //~-~-~-~-~-~-~-~-//
          //if( !usejson && cms3.is_data() && !cms3.evt_passgoodrunlist()   ) continue; // good runs lists
          if( !usejson && cms3.is_data() ) continue; // good runs lists

	  //~-~-~-~-~-~-~-~-//
          // lepton selection// 
	  //~-~-~-~-~-~-~-~-//

          int NSLeps = 0;          
          int NMu = 0;
          int NEl = 0;
          if(cms3.lep1_is_mu()&&cms3.lep2_is_mu()){
              if(cms3.lep1_pt()>30&&fabs(cms3.lep1_eta())<2.1&&cms3.lep1_passMediumID()&&fabs(cms3.lep1_d0())<0.02&&fabs(cms3.lep1_dz())<0.1&&cms3.lep1_MiniIso()<0.1) ++NMu;
              if(cms3.lep2_pt()>30&&fabs(cms3.lep2_eta())<2.1&&cms3.lep2_passMediumID()&&fabs(cms3.lep2_d0())<0.02&&fabs(cms3.lep2_dz())<0.1&&cms3.lep2_MiniIso()<0.1) ++NMu;
          } 
          else if (cms3.lep1_is_el()){
                if(cms3.lep1_pt()>30&&fabs(cms3.lep1_eta())<1.4&&cms3.lep1_passMediumID()&&cms3.lep1_MiniIso()<0.1) ++NEl; 
                if(cms3.lep2_pt()>30&&fabs(cms3.lep2_eta())<1.4&&cms3.lep2_passMediumID()&&cms3.lep2_MiniIso()<0.1) ++NEl; 
          }
	  if( NMu < 2  && NEl < 2 ) continue; // require at least 1 good lepton
	  if( cms3.lep1_is_mu()) nmu++;
	  if( cms3.lep1_is_el()) nel++;
//          if( cms3.lep1_is_el()) weight = weight;
          if( cms3.ngoodjets() >=2) njet2_incl = true; 
          if( cms3.ngoodjets() >=3) njet3_incl = true;
	  passtrig = true;	
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
	  if(passtrig){
	  string region = "passtrig"; 
	  fillHist( "event", "njets"  , region.c_str(), cms3.ngoodjets()    , weight );
	  fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  cms3.mt_met_lep()   , weight );
	  fillHist( "event", "ht"     , region.c_str(), cms3.ak4_HT()       , weight );
	  fillHist( "event", "ptl1"   , region.c_str(), cms3.lep1_pt()      , weight );	  
	  fillHist( "event", "nVert"  , region.c_str(), cms3.nvtxs()        , weight );	  
	  fillHist( "event", "metphi" , region.c_str(), event_met_ph        , weight );	 
         } 
        
          if(njet2_incl){
          string region = "njet2_incl";
          fillHist( "event", "njets"  , region.c_str(), cms3.ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  cms3.mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), cms3.ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), cms3.lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),cms3.nvtxs()        , weight );
          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
          }
          if(njet3_incl){
          string region = "njet3_incl";
          fillHist( "event", "njets"  , region.c_str(), cms3.ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  cms3.mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), cms3.ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), cms3.lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),cms3.nvtxs()        , weight );
          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
          }

	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
	  if( cms3.ngoodjets() < 2 ) continue; // require at least 2 good jets
          npass += weight;

    } // end loop over events
  } // end loop over files


//  cout << npass       << " events passing selection" << endl;
//  cout << nDuplicates << " duplicate events in data" << endl;
  cout << nel         << " el events passing selection" << endl;
  cout << nmu         << " mu events passing selection" << endl;
  cout << nemu         << " el+mu events passing selection" << endl;

  cout<<"nemu 2 jets    : "<<nem_2jets<<endl;
  cout<<"nemu 2 jets mll: "<<nem_2jets_mll<<endl;
  cout<<"emu scale factor: "<<nem_2jets_mll/nem_2jets<<endl;
 
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  
  // make histos rootfile
  string outputfilename = 	Form("${analysis_output}/%s%s_hists.root",
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


void templateLooper::fillHist( string obj, string var, string sel, float value, float weight ){
  string hist = "h_";
  try
	{
	  if( cms3.lep1_is_el() ){
		hist = Form("h_el_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( cms3.lep1_is_mu() ){
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

