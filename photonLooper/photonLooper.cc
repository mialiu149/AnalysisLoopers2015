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

#include "photonLooper.h"

#include "../sharedCode/histTools.h"
#include "../sharedCode/ZMET.h"
#include "../sharedCode/METTemplateSelections.h"

using namespace std;

const bool debug = false;
const bool usevtxweight = false;

photonLooper::photonLooper()
{
};

photonLooper::~photonLooper()
{
};

void photonLooper::ScanChain ( TChain * chain , const string iter , const string sample ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  int npass = 0;
  // METTemplates mettemplates;
  // mettemplates.setBins();
  // mettemplates.bookMETHists(mettemplate_hists);
  bookHistos();

  //~-~-~-~-~-~-~-~~-~//
  //Vertex Reweighting//
  //~-~-~-~-~-~-~-~-~-//  
  TFile * vtxfile = TFile::Open("../misccode/vtx_reweight_MC.root","READ");
  TH1F * h_vtxweight = dynamic_cast<TH1F*>( vtxfile->Get("h_nvtx") ->Clone("h_vtxweight"));

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
	string currentFileName = currentFile->GetTitle();
	setSample(currentFileName);
	
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
	  	 
	  float vtxweight = 1.0;
	  vtxweight = h_vtxweight->GetBinContent(h_vtxweight->FindBin(zmet.nVert()));
	  if( usevtxweight ) weight *= vtxweight;

	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//

	  if( zmet.ngamma()                      < 1     ) continue; // require at least 1 good photon
	  if( zmet.gamma_pt().at(0)              < 22    ) continue; // photon pt > 22 GeV
	  if( zmet.gamma_hOverE().at(0)          > 0.1   ) continue; // H/E < 0.1	  
	  if( zmet.matched_neutralemf()          < 0.7   ) continue; // jet neutral EM fraction cut
      if( acos( cos( zmet.gamma_phi().at(0)			 
					 - zmet.met_rawPhi() ) ) < 0.14  ) continue; // kill photons aligned with MET
	  if( zmet.elveto()                              ) continue; // veto pixel match
	  // if( zmet.ht()                          < 100.0 ) continue; // remove events with low HT for now
	  	  
	  fillHist( "njets", "2jets", zmet.njets()         , weight );
	  if( zmet.njets()                       < 2     ) continue; // >=2 jets


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
	  
      ++npass;

	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  

	  fillHist( "pt"   , "2jets", zmet.gamma_pt().at(0), weight );
	  fillHist( "met"  , "2jets", zmet.met_rawPt()     , weight );
	  fillHist( "t1met", "2jets", zmet.met_pt()        , weight );
	  if( zmet.gamma_pt().at(0)              < 100   ) continue; // for now, require photon pt > 50 GeV
	  fillHist( "ht"   , "2jets", zmet.ht()            , weight );

	  
	  // }else{
	  // 	  cout << "NO TRIGGERS PASS!!!" << endl;
	  // 	  exit(0);
	  // 	}

    } // end loop over events
  } // end loop over files



  cout << npass << " events passing selection" << endl;

  // mettemplates.NormalizeTemplates(mettemplate_hists);

  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  
  // make histos rootfile
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();


  string outputfilename = 	Form("../output/photon/%s/%s_photon_hists.root",
								 iter.c_str(),
								 sample.c_str()
								 );

  cout << "Writing templates to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void photonLooper::bookHistos(){

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();


  // hist naming convention: "h_<samtype>_<variable>_<selection>"
  vector <string> samtype;
  samtype.push_back("incl");
  samtype.push_back("ht100");
  samtype.push_back("ht200");
  samtype.push_back("ht400");
  samtype.push_back("ht600");
  vector <string> selection;
  selection.push_back("2jets");
  vector <string> variable;       vector <float> variable_bins;
  variable.push_back("pt"   );    variable_bins.push_back(500 );
  variable.push_back("met"  );    variable_bins.push_back(500 );
  variable.push_back("t1met");    variable_bins.push_back(500 );
  variable.push_back("ht"   );    variable_bins.push_back(1000);
  variable.push_back("njets");    variable_bins.push_back(20  );  

  
  for( unsigned int samind = 0; samind < samtype.size(); samind++ ){
	for( unsigned int varind = 0; varind < variable.size(); varind++ ){
	  for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		bookHist(Form("h_%s_%s_%s",
					  samtype  .at(samind).c_str(),
					  variable .at(varind).c_str(),
					  selection.at(selind).c_str()
					  ),
				 Form("h_%s_%s_%s",
					  samtype  .at(samind).c_str(),
					  variable .at(varind).c_str(),
					  selection.at(selind).c_str()
					  ),
				 static_cast<int>(variable_bins.at(varind)),
				 0.0,
				 variable_bins.at(varind));
	  }
	}
  }

  // example of booking a single hist  
  // bookHist("h_templ_met", "h_templ_met", 500,0,500);

  return;
}


void photonLooper::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  cout<<"Booking hist: "<<name<<endl;
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}  
  
void photonLooper::fillHist( string var, string sel, float value, float weight ){
  string hist = "h_";
  try
	{
	  if( sampleName == "gjets_ht100" ){
		hist = Form("h_ht100_%s_%s", var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( sampleName == "gjets_ht200" ){
		hist = Form("h_ht200_%s_%s", var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( sampleName == "gjets_ht400" ){
		hist = Form("h_ht400_%s_%s", var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( sampleName == "gjets_ht600" ){
		hist = Form("h_ht600_%s_%s", var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  hist = Form("h_incl_%s_%s", var.c_str(), sel.c_str());
	  fillUnderOverFlow(event_hists.at( hist ), value, weight);
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
  return;
}

void photonLooper::setSample( string samplename ){
  cout<<"Processing File: "<<samplename<<endl;
  sampleName = getSample( samplename );
  return;
}

string photonLooper::getSample( string samplename ){
  string sample = "";
  if( TString(samplename).Contains("ht100") ) sample = "gjets_ht100";
  if( TString(samplename).Contains("ht200") ) sample = "gjets_ht200";
  if( TString(samplename).Contains("ht400") ) sample = "gjets_ht400";
  if( TString(samplename).Contains("ht600") ) sample = "gjets_ht600";
  if( sample == "" ) cout<<"Sample: "<<samplename<<" not found!"<<endl;
  return sample;
}
