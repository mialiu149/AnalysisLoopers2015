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

#include "../sharedCode/histTools.h"
#include "../sharedCode/V00_00_01.h"
#include "../sharedCode/METTemplateSelections.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"

using namespace std;
using namespace duplicate_removal;

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
  leptype.push_back("ee");
  leptype.push_back("mm");
  leptype.push_back("em");
  leptype.push_back("ll");
  vector <string> object;
  object.push_back("event");
  vector <string> selection;
  selection.push_back("inclusive");
  selection.push_back("passtrig");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("ptl1");    variable_bins.push_back(1000);  
  variable.push_back("ptdil");   variable_bins.push_back(1000);  
  variable.push_back("met");     variable_bins.push_back(500 );  
  // variable.push_back("met_phi"); variable_bins.push_back(500 );  
  // variable.push_back("met_phir");variable_bins.push_back(500 );  
  variable.push_back("met_raw"); variable_bins.push_back(500 );  
  variable.push_back("met_rawgt1jet"); variable_bins.push_back(500 );  
  variable.push_back("met_raw_vince"); variable_bins.push_back(500 );  
  variable.push_back("ht");	     variable_bins.push_back(1000);  
  variable.push_back("mt3");     variable_bins.push_back(500);  
  variable.push_back("njets");   variable_bins.push_back(20  );  
  variable.push_back("mll");     variable_bins.push_back(300 );  
  variable.push_back("nVert");   variable_bins.push_back(50 );  
  variable.push_back("MHTFW");   variable_bins.push_back(1000 );  
  variable.push_back("MHTBA");   variable_bins.push_back(1000 );  
  variable.push_back("MHTFB");   variable_bins.push_back(1000 );  
  variable.push_back("MHTFBgt1jet");   variable_bins.push_back(1000 );
  
  variable.push_back("met0jet");  variable_bins.push_back(500 );  
  variable.push_back("met1jet");  variable_bins.push_back(500 );  
  variable.push_back("metgt1jet");variable_bins.push_back(500 );  

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

  double nee = 0;
  double nmm = 0;
  double nll = 0;
  double nem = 0;

  double ne = 0;
  double nmu = 0;

  double nem_2jets = 0;
  double nem_2jets_mll = 0;

  cout<<selection<<endl;
  
  bookHistos();

  double npass = 0;
  
  // do this once per job
  const char* json_file ="../../dilepbabymaker/json_270715_golden.txt";
  set_goodrun_file(json_file);

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  TH1F * h_vtxweight = NULL;
//  TFile * f_vtx = NULL;
/*  if( dovtxreweighting ){
	f_vtx = TFile::Open("nvtx_ratio.root","READ");
	h_vtxweight = (TH1F*)f_vtx->Get("h_vtx_ratio")->Clone("h_vtxweight");
	h_vtxweight->SetDirectory(rootdir);
	f_vtx->Close();
  }
*/
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

	  if ( cms3.isData() && usejson && !goodrun(cms3.run(), cms3.lumi()) ) continue;

	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  if( cms3.isData() ) {
		DorkyEventIdentifier id(cms3.run(), cms3.evt(), cms3.lumi());
		if (is_duplicate(id) ){
		  ++nDuplicates;
		  continue;
		}
          }
	  
	  //~-~-~-~-~-~-~-~~-//
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

	  
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( cms3.isData() ){
		weight = 1.0;
	  }else if( !cms3.isData() ){
		weight *= cms3.evt_scale1fb();
	  }

	  if( !cms3.isData() && dovtxreweighting ){
		// cout<<h_vtxweight->GetBinContent(h_vtxweight->FindBin(cms3.nVert()));
		weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(cms3.nVert()));		
		// weight *= h_vtxweight->GetBinContent(cms3.nVert());		
	  }
	  
	  float event_met_pt = cms3.met_pt();
	  float event_met_ph = cms3.met_phi();


	  //~-~-~-~-~-~-~-~-//
          // event selection// 
	  //~-~-~-~-~-~-~-~-//
          if( !usejson && cms3.isData() && !cms3.evt_passgoodrunlist()   ) continue; // good runs lists
	  if( !(cms3.HLT_SingleMu() || cms3.HLT_SingleEl() )) continue;

	  if( cms3.nlep()                        < 1         ) continue; // require at least 1 good lepton
	  if( cms3.lep_pt().at(0)                < 40        ) continue; // leading lep pT > 40 GeV
	  if( cms3.lep_pt().size()               > 1         ) continue; // second lepton veto

	  if( abs(cms3.lep_p4().at(0).eta())     > 2.4       ) continue; // eta < 2.4
	  if( abs(cms3.lep_p4().at(0).eta())     > 1.4 &&
	  	  abs(cms3.lep_p4().at(0).eta())     < 1.6       ) continue; //excluding tracker crack region 
	  
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//	  
	  fillHist( "event", "njets"  , "passtrig", cms3.njets()        , weight );
	  fillHist( "event", "met"    , "passtrig", event_met_pt        , weight );
	  fillHist( "event", "met_raw", "passtrig", cms3.met_rawPt()    , weight );
	  fillHist( "event", "ht"     , "passtrig", cms3.ht()           , weight );
	  fillHist( "event", "ptl1"   , "passtrig", cms3.lep_pt().at(0) , weight );	  
	  fillHist( "event", "nVert"  , "passtrig", cms3.nVert()        , weight );	  
	  fillHist( "event", "metphi" , "passtrig", event_met_ph        , weight );	  
	  fillHist( "event", "metphir", "passtrig", cms3.met_rawPhi()   , weight );	  

	  if( cms3.njets() == 0 ) fillHist( "event", "met0jet"   , "passtrig", event_met_pt        , weight );
	  if( cms3.njets() == 1 ) fillHist( "event", "met1jet"   , "passtrig", event_met_pt        , weight );
	  if( cms3.njets() >= 2 ) fillHist( "event", "metgt1jet" , "passtrig", event_met_pt        , weight );

	  // MHTFW
	  LorentzVector MHTFB_p4(0,0,0,0);// =  - cms3.lep1.p4()  - cms3.lep2.p4()  - cms3.jet1.p4();
	  LorentzVector MHTFW_p4(0,0,0,0);// =  - cms3.lep1.p4()  - cms3.lep2.p4()  - cms3.jet1.p4();
	  LorentzVector MHTBA_p4(0,0,0,0);// =  - cms3.lep1.p4()  - cms3.lep2.p4()  - cms3.jet1.p4();
	  for( size_t lepind = 0; lepind < cms3.lep_p4().size(); lepind++ ){
		MHTFB_p4 += - cms3.lep_p4().at(lepind);
		if( abs(cms3.lep_p4().at(lepind).eta()) > 1.6 ) MHTFW_p4 += - cms3.lep_p4().at(lepind);
		if( abs(cms3.lep_p4().at(lepind).eta()) < 1.4 ) MHTBA_p4 += - cms3.lep_p4().at(lepind);
	  }
	  for( size_t jetind = 0; jetind < cms3.jets_p4().size(); jetind++ ){
		MHTFB_p4 += - cms3.jets_p4().at(jetind);
		if( abs(cms3.jets_p4().at(jetind).eta()) > 1.6 ) MHTFW_p4 += - cms3.jets_p4().at(jetind);
		if( abs(cms3.jets_p4().at(jetind).eta()) < 1.4 ) MHTBA_p4 += - cms3.jets_p4().at(jetind);
	  }	 
	  float MHTFB = MHTFB_p4.pt();
	  float MHTFW = MHTFW_p4.pt();
	  float MHTBA = MHTBA_p4.pt();
	  fillHist( "event", "MHTFB", "passtrig", MHTFB   , weight );	  
	  fillHist( "event", "MHTFW", "passtrig", MHTFW   , weight );	  
	  fillHist( "event", "MHTBA", "passtrig", MHTBA   , weight );	  
	  fillHist( "event", "mhtphi" , "passtrig", MHTFB_p4.phi() , weight );	  
	  
	  if( event_met_pt > 20 ) fillHist( "event", "metphi20" , "passtrig", event_met_ph        , weight );	  
	  if( event_met_pt > 40 ) fillHist( "event", "metphi40" , "passtrig", event_met_ph        , weight );	  
	  if( event_met_pt > 60 ) fillHist( "event", "metphi60" , "passtrig", event_met_ph        , weight );	  

	  if( cms3.njets() >= 2 ) fillHist( "event", "MHTFBgt1jet", "passtrig", MHTFB   , weight );	  
	  if( cms3.njets() >= 2 ) fillHist( "event", "met_rawgt1jet", "passtrig", cms3.met_rawPt()   , weight );	  
	  
	  if( cms3.nlep() > 2 ){
		float dphi = acos(cos(cms3.lep_p4()[2].phi()-event_met_ph));
		float mt = sqrt(2*event_met_pt*cms3.lep_pt()[2]*cos(dphi));
		fillHist( "event", "mt3", "passtrig", mt, weight );	  
	  }
	  
	  if( event_met_pt < 50 && cms3.hyp_type() == 2 ) nem_2jets += weight;
		  
	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
	  if( cms3.njets() < 2 ) continue; // require at least 2 good jets
          npass += weight;

    } // end loop over events
  } // end loop over files


  cout << npass       << " events passing selection" << endl;
  cout << nDuplicates << " duplicate events in data" << endl;
  cout << nee         << " ee events passing selection" << endl;
  cout << nmm         << " mm events passing selection" << endl;
  cout << nll         << " ll events passing selection" << endl;
  cout << nem         << " em events passing selection" << endl;

  cout<<"nemu 2 jets    : "<<nem_2jets<<endl;
  cout<<"nemu 2 jets mll: "<<nem_2jets_mll<<endl;
  cout<<"emu scale factor: "<<nem_2jets_mll/nem_2jets<<endl;
 
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  
  // make histos rootfile
  string outputfilename = 	Form("../output/%s/%s%s_hists.root",
								 iter.c_str(),
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
	  if( cms3.hyp_type() == 0 ){
		hist = Form("h_ee_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( cms3.hyp_type() == 1 ){
		hist = Form("h_mm_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( cms3.hyp_type() == 2 ){
		hist = Form("h_em_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( cms3.hyp_type() == 0 || cms3.hyp_type() == 1 ){
		hist = Form("h_ll_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
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

