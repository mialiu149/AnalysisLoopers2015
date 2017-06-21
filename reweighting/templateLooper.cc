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
#include "../sharedCode/ZMET.h"
#include "../sharedCode/METTemplateSelections.h"

using namespace std;

const bool debug = false;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  unsigned long nee = 0;
  unsigned long nmm = 0;
  unsigned long nem = 0;

  double nem_2jets = 0;

  cout<<selection<<endl;
  
  int npass = 0;
  METTemplates mettemplates( selection );
  mettemplates.loadTemplatesFromFile( Form("../output/photon/%s/All_MC%s_photon_templates.root", iter.c_str(), selection.c_str()), mettemplate_hists );
  mettemplates.setBins( selection );
  TH1F* currentMETTemplate = NULL;

  bookHistos();

  TObjArray *listOfFiles = chain->GetListOfFiles();
  unsigned int nEventsChain = 0;
  unsigned int nEvents = chain->GetEntries();
  nEventsChain = nEvents;
  unsigned int nEventsTotal = 0;

  if(debug) cout << "Begin file loop" << endl;

  // file loop
  TIter fileIter(listOfFiles);
  TFile* currentFile = 0;
  while ( (currentFile = (TFile*) fileIter.Next()) ){

	TFile f(currentFile->GetTitle());
    TTree *tree = dynamic_cast<TTree*>(f.Get("t"));
    zmet.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
	cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
   
	  zmet.GetEntry(event);
      ++nEventsTotal;

	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
          fflush(stdout);
        }
      }

	  //~-~-~-~-~-~-~-~~-//
	  //Stitch DY samples//
	  //~-~-~-~-~-~-~-~-~//

	  if( TString(currentFile->GetTitle()).Contains("m50inc") ){
	  	if( zmet.gen_ht() > 100 ) continue;
	  }else if( TString(currentFile->GetTitle()).Contains("dyjetsll") ){
	  	if( zmet.gen_ht() < 100 ) continue;
	  }
	
	  
	  //~-~-~-~-~-~-~-~~-//
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

	  
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //Deal with event weights//
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( zmet.isData() ){
		weight = 1.0;
	  }else if( !zmet.isData() ){
		weight *= zmet.evt_scale1fb();
	  }

	  float event_met_pt = zmet.met_pt();
	  float event_met_ph = zmet.met_phi();

	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//
	  if( !eventHas2GoodLeps()      ) continue;
	  if( !passBaselineSelections() ) continue;	  


	  if( zmet.hyp_type() == 0 ) nee++;
	  if( zmet.hyp_type() == 1 ) nmm++;
	  if( zmet.hyp_type() == 2 ) nem++;
	  
	  fillHist( "event", "mll"  , "2jets", zmet.dilmass()  , weight );

	  // if( zmet.dilpt()                       < 50   ) continue; // for now, require 50 GeV dil Z pT cut

      // if( isdata && !(templates.csc()==0 && 
	  // 				  templates.hbhe()==1 && 
	  // 				  templates.hcallaser()==1 && 
	  // 				  templates.ecallaser()==1 && 
	  // 				  templates.ecaltp()==1 && 
	  // 				  templates.trkfail()==1 && 
	  // 				  templates.eebadsc()==1 && 
	  // 				  templates.hbhenew()==1) )                             continue; // MET filters
	  // // if( isdata && (h20 < 1 && h30 < 1 && h50 < 1 && h75 < 1 && h90 < 1 )) continue; // require trig
	  // if( isdata && (h20 < 1 && h50 < 1 && h75 < 1 && h90 < 1 )) continue; // require trig

	  
	  // if( !(zmet.hyp_type() == 0 ||					     
	  // 		zmet.hyp_type() == 1 ) ) continue;					     

	  // if( zmet.dilpt() < 50 ) continue;
	  fillHist( "event", "pt"  , "2jets"   , zmet.dilpt()  , weight );
	  if( zmet.HLT_DoubleMu() ||
		  zmet.HLT_DoubleEl() ||
		  zmet.HLT_DoubleEl_noiso() ||
		  zmet.HLT_MuEG()     ){
		fillHist( "event", "pt"  , "passtrig", zmet.dilpt()  , weight );
	  }
	  
	  // if( TString(selection).Contains("bveto"          ) && zmet.nBJetMedium() > 0 ) continue; //bveto
	  // if( TString(selection).Contains("withb"          ) && zmet.nBJetMedium() < 1 ) continue; //at least 1 b-tag
	  // if( TString(selection).Contains("SRA"            ) && !((zmet.njets() == 2 ||
	  // 										           	   zmet.njets() == 3) &&
	  // 										           	  zmet.ht() > 600)         ) continue; //high HT region
	  // if( TString(selection).Contains("SRB"            ) && zmet.njets() < 4       ) continue; //large njets
	  if( TString(selection).Contains("twojets") && zmet.njets() > 2              ) continue; //large njets
	  else if( TString(selection).Contains("2jets_inclusive") && zmet.njets() < 2 ) continue; //large njets
	  if( TString(selection).Contains("3jets_inclusive") && zmet.njets() < 3      ) continue; //large njets

	  if( event_met_pt < 50 && zmet.hyp_type() == 2 ) nem_2jets += weight;
	  
	  // if( sample == "vv" ||
	  // 	  sample == "ttv" ) 
		  
      ++npass;

	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  

	  if( zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ){
		currentMETTemplate = mettemplates.pickTemplate( mettemplate_hists, zmet.njets(), zmet.ht(), zmet.dilpt() );
		mettemplates.countTemplate( zmet.njets(), zmet.ht(), zmet.dilpt(), weight );
		// currentMETTemplate->Scale(weight);
		try
		  {
			event_hists.at( "h_templ_met" ) -> Add( currentMETTemplate, weight );		
		  }
		catch(exception &e)
		  {
			cout<<"Hist: h_templ_met Does not exist!"<<endl;
			exit(1);
		  }
		// mettemplates.normalizeTemplate(currentMETTemplate);
	  }
	  
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//	  

	  fillHist( "event", "njets", "2jets", zmet.njets()    , weight );
	  fillHist( "event", "met"  , "2jets", event_met_pt    , weight );
	  fillHist( "event", "ht"   , "2jets", zmet.ht()       , weight );

	  if( zmet.jzb_T1() < 0 ){
	  	fillHist( "event", "jzb"  , "2jets", event_met_pt  , weight );
	  }
	  
	  // }else{
	  // 	  cout << "NO TRIGGERS PASS!!!" << endl;
	  // 	  exit(0);
	  // 	}

    } // end loop over events
  } // end loop over files

  cout << npass << " events passing selection" << endl;
  
  mettemplates.NormalizeTemplates(mettemplate_hists);
  mettemplates.correctBinUncertainty( mettemplate_hists, event_hists.at("h_templ_met") );

  
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  

  // make histos rootfile
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();



  string outputfilename = 	Form("../output/%s/reweighting/%s%s_hists.root",
								 iter.c_str(),
								 sample.c_str(),
								 selection.c_str()
								 );

  cout << "Writing output to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void templateLooper::bookHistos(){

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();

  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("ee");
  leptype.push_back("mm");
  leptype.push_back("em");
  leptype.push_back("ll");
  vector <string> object;
  object.push_back("event");
  // object.push_back("templ");
  object.push_back("lep1");
  object.push_back("lep2");
  object.push_back("dilep");
  vector <string> selection;
  selection.push_back("2jets");
  selection.push_back("passtrig");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("pt");      variable_bins.push_back(1000);  
  variable.push_back("met");     variable_bins.push_back(500 );  
  variable.push_back("ht");	     variable_bins.push_back(1000);  
  variable.push_back("mt2");     variable_bins.push_back(500 );  
  variable.push_back("mt2j");    variable_bins.push_back(500 );  
  variable.push_back("njets");   variable_bins.push_back(20  );  
  variable.push_back("mll");     variable_bins.push_back(300 );  
  variable.push_back("jzb");     variable_bins.push_back(500 );  

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
  bookHist("h_ll_event_drll_2jets", "h_ll_event_drll_2jets", 500,0,5);
  bookHist("h_ee_event_drll_2jets", "h_ee_event_drll_2jets", 500,0,5);
  bookHist("h_mm_event_drll_2jets", "h_mm_event_drll_2jets", 500,0,5);
  bookHist("h_em_event_drll_2jets", "h_em_event_drll_2jets", 500,0,5);

  // need to add hists for calculating FS BG


}

void templateLooper::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  // cout<<"Booking hist: "<<name<<endl;
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}  


void templateLooper::fillHist( string obj, string var, string sel, float value, float weight ){
  // cout<<"Booking hist: "<<name<<endl;
  // TH1F * hist = new TH1F( name, title, nbins, xmin, xmax );
  string hist = "h_";
  try
	{
	  if( zmet.hyp_type() == 0 ){
		hist = Form("h_ee_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 1 ){
		hist = Form("h_mm_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 2 ){
		hist = Form("h_em_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ){
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

