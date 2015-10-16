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

#include "makePhotonTemplates.h"

#include "../sharedCode/histTools.h"
#include "../sharedCode/ZMET.h"
#include "../sharedCode/METTemplateSelections.h"

using namespace std;

const bool debug = false;
const bool doReweighting = false;

makePhotonTemplates::makePhotonTemplates()
{
};

makePhotonTemplates::~makePhotonTemplates()
{
};

void makePhotonTemplates::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  int npass = 0;
  METTemplates mettemplates( selection );
  mettemplates.setBins( selection );
  mettemplates.bookMETHists(mettemplate_hists);
  // bookHistos();

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
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

	  
	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//

	  float event_met_pt = zmet.met_pt();
	  float event_met_ph = zmet.met_phi();

	  // event_met_pt = zmet.met_rawPt();
	  // event_met_ph = zmet.met_rawPhi();	  

	  if( zmet.ngamma()                      < 1     ) continue; // require at least 1 good photon
	  if( zmet.njets()                       < 2     ) continue; // >=2 jets
	  if( zmet.gamma_pt().at(0)              < 25    ) continue; // photon pt > 22 GeV
	  if( abs(zmet.gamma_p4().at(0).eta())   > 1.4 &&
		  abs(zmet.gamma_p4().at(0).eta())   < 1.6   ) continue; // photon in barrel only
	  if( abs(zmet.gamma_p4().at(0).eta())   > 2.4   ) continue; // photon in barrel only
	  // if( zmet.gamma_pt().at(0)              < 50    ) continue; // for now, require photon pt > 50 GeV
	  if( zmet.gamma_hOverE().at(0)          > 0.1   ) continue; // H/E < 0.1	  
	  if( zmet.matched_neutralemf()          < 0.7   ) continue; // jet neutral EM fraction cut
      if( acos( cos( zmet.gamma_phi().at(0)			 
					 - event_met_ph ) ) < 0.14       ) continue; // kill photons aligned with MET
	  if( zmet.elveto()                              ) continue; // veto pixel match
	  // if( zmet.ht()                          < 240.0 ) continue; // remove events with low HT for now
	  
	  if( TString(selection).Contains("bveto"          ) && zmet.nBJetMedium() > 0 ) continue; //bveto
	  if( TString(selection).Contains("withb"          ) && zmet.nBJetMedium() < 1 ) continue; //at least 1 b-tag
	  if( TString(selection).Contains("SRA"            ) && !((zmet.njets() == 2 ||
											           	   zmet.njets() == 3) &&
											           	  zmet.ht() > 600)         ) continue; //high HT region
	  if( TString(selection).Contains("SRB"            ) && zmet.njets() < 4       ) continue; //large njets
	  if( TString(selection).Contains("3jets"          ) && zmet.njets() < 3       ) continue; //large njets

	  // if( TString(selection).Contains("twojets"        ) && zmet.njets() > 2       ) continue; //large njets


	  // if( templates.jetpt() - templates.etg() < -5 )                        continue; // pfjet cleaning
      // if( templates.maxleppt() > 20.0 )                                     continue; // veto leptons pt > 20 GeV
      // // if( bveto && templates.nbm() > 0 )                                    continue; // apply medium csv b-veto 
      // // if( bveto && templates.nbl() < 2 )                                    continue; // apply medium csv b-veto 
      // // if( bveto && templates.nbl() > 0 )                                    continue; // apply loose csv b-veto 

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
	  if( doReweighting ) vtxweight = h_vtxweight->GetBinContent(h_vtxweight->FindBin(zmet.nVert()));

	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
	  mettemplates.FillTemplate(mettemplate_hists, zmet.njets(), zmet.ht(), zmet.gamma_pt().at(0), event_met_pt, weight*vtxweight );

	  // if( zmet.gamma_pt().at(0) < 50 )	  
		// cout<<"photon pT in event loop: "<<zmet.gamma_pt().at(0)<<endl;

	  // fillUnderOverFlow(mettemplate_hists.at("photon_pt"), zmet.gamma_pt().at(0), weight );
	  // fillUnderOverFlow(mettemplate_hists.at("ht"       ), zmet.ht()            , weight );
	  // fillUnderOverFlow(mettemplate_hists.at("met"      ), zmet.met_rawPt()     , weight );

	  // if( TString(currentFile->GetTitle()).Contains("ht100") ){
	  // 	fillUnderOverFlow(mettemplate_hists.at("photon_pt_ht100"), zmet.gamma_pt().at(0), weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("ht_ht100"       ), zmet.ht()            , weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("met_ht100"      ), zmet.met_rawPt()     , weight );
	  // }else if( TString(currentFile->GetTitle()).Contains("ht200") ){
	  // 	fillUnderOverFlow(mettemplate_hists.at("photon_pt_ht200"), zmet.gamma_pt().at(0), weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("ht_ht200"       ), zmet.ht()            , weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("met_ht200"      ), zmet.met_rawPt()     , weight );
	  // }else if( TString(currentFile->GetTitle()).Contains("ht400") ){
	  // 	fillUnderOverFlow(mettemplate_hists.at("photon_pt_ht400"), zmet.gamma_pt().at(0), weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("ht_ht400"       ), zmet.ht()            , weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("met_ht400"      ), zmet.met_rawPt()     , weight );
	  // }else if( TString(currentFile->GetTitle()).Contains("ht600") ){
	  // 	fillUnderOverFlow(mettemplate_hists.at("photon_pt_ht600"), zmet.gamma_pt().at(0), weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("ht_ht600"       ), zmet.ht()            , weight );
	  // 	fillUnderOverFlow(mettemplate_hists.at("met_ht600"      ), zmet.met_rawPt()     , weight );
	  // }			
	  
		
	  // }else{
	  // 	  cout << "NO TRIGGERS PASS!!!" << endl;
	  // 	  exit(0);
	  // 	}

    } // end loop over events
  } // end loop over files



  cout << npass << " events passing selection" << endl;

  mettemplates.NormalizeTemplates(mettemplate_hists);

  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  
  //-------------------------------------------
  // normalize templates
  //-------------------------------------------
  // if( normalized ){   
  // }

  // make histos rootfile
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();


  string outputfilename = 	Form("../output/photon/%s/%s%s_photon_templates.root",
								 iter.c_str(),
								 sample.c_str(),
								 selection.c_str()
								 );

  cout << "Writing templates to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void makePhotonTemplates::bookHistos(){

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();

  vector <int> photon_ptcuts;
  photon_ptcuts.push_back(22);
  photon_ptcuts.push_back(30);
  photon_ptcuts.push_back(36);
  photon_ptcuts.push_back(50);
  photon_ptcuts.push_back(75);
  photon_ptcuts.push_back(90);
  photon_ptcuts.push_back(120);
  photon_ptcuts.push_back(165);

  vector <int> photon_njetcuts;
  photon_ptcuts.push_back(2);
  photon_ptcuts.push_back(3);

  vector <int> photon_htcuts;
  photon_ptcuts.push_back(30);
  photon_ptcuts.push_back(60);
  photon_ptcuts.push_back(90);
  photon_ptcuts.push_back(120);
  photon_ptcuts.push_back(180);
  photon_ptcuts.push_back(240);
  photon_ptcuts.push_back(300);

}

  

