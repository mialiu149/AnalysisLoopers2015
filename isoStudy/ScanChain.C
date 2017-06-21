// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"

// ZMET
#include "ZMET.h"

#include "../sharedCode/histTools.cc"

using namespace std;
using namespace ZMet;

// void FillOverFlow( TH1F * &h, float weight )
// {

//   if( 
  
//   return;
// }

int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  TH1F * h_min_dR = new TH1F("h_min_dR", "dR for leps", 1000,0,100);
  h_min_dR->SetDirectory(rootdir);
  h_min_dR->Sumw2();
  
  TH1F * h_el_prompt_EAiso = new TH1F("h_el_prompt_EAiso", "EA iso for prompt electrons"    , 100,0,1);
  TH1F * h_el_npromp_EAiso = new TH1F("h_el_npromp_EAiso", "EA iso for non-prompt electrons", 100,0,1);
  TH1F * h_mu_prompt_EAiso = new TH1F("h_mu_prompt_EAiso", "EA iso for prompt electrons"    , 100,0,1);
  TH1F * h_mu_npromp_EAiso = new TH1F("h_mu_npromp_EAiso", "EA iso for non-prompt electrons", 100,0,1);

  TH1F * h_el_prompt_noiso = new TH1F("h_el_prompt_noiso", "no iso for prompt electrons"    , 100,0,1);
  TH1F * h_el_npromp_noiso = new TH1F("h_el_npromp_noiso", "no iso for non-prompt electrons", 100,0,1);
  TH1F * h_mu_prompt_noiso = new TH1F("h_mu_prompt_noiso", "no iso for prompt electrons"    , 100,0,1);
  TH1F * h_mu_npromp_noiso = new TH1F("h_mu_npromp_noiso", "no iso for non-prompt electrons", 100,0,1);

  TH1F * h_el_prompt_DBiso = new TH1F("h_el_prompt_DBiso", "DB iso for prompt electrons"    , 100,0,1);
  TH1F * h_el_npromp_DBiso = new TH1F("h_el_npromp_DBiso", "DB iso for non-prompt electrons", 100,0,1);
  TH1F * h_mu_prompt_DBiso = new TH1F("h_mu_prompt_DBiso", "DB iso for prompt electrons"    , 100,0,1);
  TH1F * h_mu_npromp_DBiso = new TH1F("h_mu_npromp_DBiso", "DB iso for non-prompt electrons", 100,0,1);

  TH1F * h_el_prompt_MRiso = new TH1F("h_el_prompt_MRiso", "MR iso for prompt electrons"    , 100,0,1);
  TH1F * h_el_npromp_MRiso = new TH1F("h_el_npromp_MRiso", "MR iso for non-prompt electrons", 100,0,1);
  TH1F * h_mu_prompt_MRiso = new TH1F("h_mu_prompt_MRiso", "MR iso for prompt electrons"    , 100,0,1);
  TH1F * h_mu_npromp_MRiso = new TH1F("h_mu_npromp_MRiso", "MR iso for non-prompt electrons", 100,0,1);

  h_el_prompt_EAiso->SetDirectory(rootdir);
  h_el_npromp_EAiso->SetDirectory(rootdir);
  h_mu_prompt_EAiso->SetDirectory(rootdir);
  h_mu_npromp_EAiso->SetDirectory(rootdir);

  h_el_prompt_noiso->SetDirectory(rootdir);
  h_el_npromp_noiso->SetDirectory(rootdir);
  h_mu_prompt_noiso->SetDirectory(rootdir);
  h_mu_npromp_noiso->SetDirectory(rootdir);

  h_el_prompt_MRiso->SetDirectory(rootdir);
  h_el_npromp_MRiso->SetDirectory(rootdir);
  h_mu_prompt_MRiso->SetDirectory(rootdir);
  h_mu_npromp_MRiso->SetDirectory(rootdir);

  h_el_prompt_DBiso->SetDirectory(rootdir);
  h_el_npromp_DBiso->SetDirectory(rootdir);
  h_mu_prompt_DBiso->SetDirectory(rootdir);
  h_mu_npromp_DBiso->SetDirectory(rootdir);

  h_el_prompt_EAiso->Sumw2();
  h_el_npromp_EAiso->Sumw2();
  h_mu_prompt_EAiso->Sumw2();
  h_mu_npromp_EAiso->Sumw2();

  h_el_prompt_noiso->Sumw2();
  h_el_npromp_noiso->Sumw2();
  h_mu_prompt_noiso->Sumw2();
  h_mu_npromp_noiso->Sumw2();

  h_el_prompt_DBiso->Sumw2();
  h_el_npromp_DBiso->Sumw2();
  h_mu_prompt_DBiso->Sumw2();
  h_mu_npromp_DBiso->Sumw2();

  h_el_prompt_MRiso->Sumw2();
  h_el_npromp_MRiso->Sumw2();
  h_mu_prompt_MRiso->Sumw2();
  h_mu_npromp_MRiso->Sumw2();

  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    // Get File Content
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("t");
    if(fast) TTreeCache::SetLearnEntries(10);
    if(fast) tree->SetCacheSize(128*1024*1024);
    zmet.Init(tree);
    
    // Loop over Events in current file
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
    
      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      zmet.GetEntry(event);
      ++nEventsTotal;
    
      // Progress
      ZMET::progress( nEventsTotal, nEventsChain );

  //     // Analysis Code
  // TCut osdilep = "nlep>1 && lep_pt[0] > 25 && lep_pt[1] > 20 && evt_type==0";
  // TCut drll = "dRll > .3";  
  // TCut eta24 = "abs(lep_p4[0].eta()) < 2.4 && abs(lep_p4[1].eta()) < 2.4";
  // TCut vetoxition = "(abs(lep_p4[0].eta()) < 1.4 || abs(lep_p4[0].eta()) > 1.6) && (abs(lep_p4[1].eta()) < 1.4 || abs(lep_p4[1].eta()) > 1.6)";
  // TCut njets0 = "njets == 0";
  // TCut njets4 = "njets >= 4";
  // TCut ee = "hyp_type == 0" ;
  // TCut mm = "hyp_type == 1" ;
  // TCut em = "hyp_type == 2" ;

	  if( zmet.nlep()       < 1    ) continue; 
	  if( zmet.njets()      < 4    ) continue; 
	  // if( zmet.lep_charge().at(0)*zmet.lep_charge().at(1)     > 0   ) continue;// OS only

	  // if( zmet.lep_pt().at(0) < 25.0 ) continue;
	  // if( zmet.lep_pt().at(1) < 20.0 ) continue;

	  // if( !(abs(zmet.lep_pdgId().at(0)) == 11 && abs(zmet.lep_pdgId().at(1)) == 11) ) continue;

	  int event_type = -1;

	  // // int lepcount = 0;
	  // bool hasgenlep = false;
	  // for( size_t lepind = 0; lepind < zmet.genLep_pdgId().size(); lepind++ ){
	  // 	if( abs(zmet.genLep_pdgId().at(lepind)) == 11 ||
	  // 		abs(zmet.genLep_pdgId().at(lepind)) == 13 ||
	  // 		abs(zmet.genLep_pdgId().at(lepind)) == 15   ) hasgenlep = true; 
	  // }
	  // for( size_t lepind = 0; lepind < zmet.genLepFromTau_pdgId().size(); lepind++ ){
	  // 	if( abs(zmet.genLepFromTau_pdgId().at(lepind)) == 11 ||
	  // 		abs(zmet.genLepFromTau_pdgId().at(lepind)) == 13 ||
	  // 		abs(zmet.genLepFromTau_pdgId().at(lepind)) == 15   ) hasgenlep = true; 
	  // }
	  // if( !hasgenlep ) continue;
	  // if( zmet.ngenLep() > 0 ) continue;	  
	  // if( zmet.ngenTau() > 0 ) continue;	  
	  // if( zmet.ngenLepFromTau() > 0 ) continue;	  

	  for( size_t lepind = 0; lepind < zmet.lep_pdgId().size(); lepind++ ){

		bool hasMatch = false;
		int match_index = -999;
		float dRmin = 10;

		bool hasGenLep = false;
		for( size_t genind = 0; genind < zmet.genPart_pdgId().size(); genind++ ){
		  if( !(abs(zmet.genPart_status()  .at(genind)) == 1  ||
				abs(zmet.genPart_status()  .at(genind)) == 22 ||
				abs(zmet.genPart_status()  .at(genind)) == 23) ) continue;//only keep "status 3"
		  if( (abs(zmet.genPart_motherId().at(genind)) == 24 ||
			   abs(zmet.genPart_motherId().at(genind)) == 15) &&
			  ( abs(zmet.genPart_pdgId()   .at(genind)) == 11 ||
				abs(zmet.genPart_pdgId()   .at(genind)) == 13 ||
				abs(zmet.genPart_pdgId()   .at(genind)) == 15 ) ) hasGenLep = true;//only keep els, mus
		}
		if( hasGenLep ) continue;
		
		for( size_t genind = 0; genind < zmet.genPart_pdgId().size(); genind++ ){
		  // if( abs(zmet.genPart_status()  .at(genind)) == 1 ) continue;
		  if( !(abs(zmet.genPart_status()  .at(genind)) == 1  ||
				abs(zmet.genPart_status()  .at(genind)) == 22 ||
				abs(zmet.genPart_status()  .at(genind)) == 23) ) continue;//only keep "status 3"
		  if( !(abs(zmet.genPart_pdgId()   .at(genind)) == 11 ||  abs(zmet.genPart_pdgId()   .at(genind)) == 13) ) continue;//only keep els, mus
		  // if( !(abs(zmet.genPart_pdgId()   .at(genind)) == 15                                                  ) ) continue;//only keep els, mus
		  if( !(abs(zmet.genPart_motherId().at(genind)) == 24 ||  abs(zmet.genPart_motherId().at(genind)) == 15) ) continue;//only keep leps from taus and Ws
		  if( !(    zmet.genPart_pdgId().at(genind)     == zmet.lep_pdgId().at(lepind))                          ) continue;//only match leps to same flavor, and charge

		  float dRtemp = sqrt(pow(          zmet.genPart_eta().at(genind) - zmet.lep_eta().at(lepind)  , 2) +
							  pow( acos(cos(zmet.genPart_phi().at(genind) - zmet.lep_phi().at(lepind))), 2) );
		  if( dRtemp < dRmin ){
			dRmin = dRtemp;
			match_index = genind;
		  }
		}
	
		h_min_dR->Fill(dRmin);

		if( dRmin < 0.5 ) hasMatch = true;

		bool isPrompt = false;
		if( hasMatch ) isPrompt = true;
	  
		if(      abs(zmet.lep_pdgId().at(lepind)    ) == 11 ) event_type = 0;
		else if( abs(zmet.lep_pdgId().at(lepind)    ) == 13 ) event_type = 1;
		else continue;

		if( abs(zmet.lep_mcMatchId().at(lepind)) == 0  ) continue;

		// if( abs(zmet.lep_mcMatchId().at(lepind)) == 24 ||
		// 	abs(zmet.lep_mcMatchId().at(lepind)) == 15 ){
		//   isPrompt = true;
		// }
	    // else{
		//   isPrompt = false;
		//   cout<<"matchid: "<<abs(zmet.lep_mcMatchId().at(lepind))<<endl;
		// }

		// if( zmet.ngenLep() < 1 ) isPrompt = false;
		if( abs(zmet.lep_pt().at(lepind))  < 20  ) continue;  
		if( abs(zmet.lep_eta().at(lepind)) > 2.4 ) continue;  
		if( abs(zmet.lep_eta().at(lepind)) > 1.4 && abs(zmet.lep_eta().at(lepind)) < 1.6 ) continue;  

		if( isPrompt ){
		  if( event_type == 0 ) fillUnderOverFlow(h_el_prompt_EAiso, zmet.lep_relIso03EA().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 0 ) fillUnderOverFlow(h_el_prompt_DBiso, zmet.lep_relIso03DB().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 0 ) fillUnderOverFlow(h_el_prompt_MRiso, zmet.lep_relIso03MR().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_prompt_EAiso, zmet.lep_relIso03EA().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_prompt_DBiso, zmet.lep_relIso03DB().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_prompt_MRiso, zmet.lep_relIso03MR().at(lepind), zmet.evt_scale1fb());
		}else{
		  if( event_type == 0 ) fillUnderOverFlow(h_el_npromp_EAiso, zmet.lep_relIso03EA().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 0 ) fillUnderOverFlow(h_el_npromp_DBiso, zmet.lep_relIso03DB().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 0 ) fillUnderOverFlow(h_el_npromp_MRiso, zmet.lep_relIso03MR().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_npromp_EAiso, zmet.lep_relIso03EA().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_npromp_DBiso, zmet.lep_relIso03DB().at(lepind), zmet.evt_scale1fb());
		  if( event_type == 1 ) fillUnderOverFlow(h_mu_npromp_MRiso, zmet.lep_relIso03MR().at(lepind), zmet.evt_scale1fb());
		}
	  }

	  // lep_mcMatchId
	  // lep_relIso03EA
	  // lep_relIso03DB
	  // lep_relIso03MR
  
    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }
  
  TFile * outfile = TFile::Open("lepton_isolations.root","RECREATE");
  // Example Histograms
  outfile->cd();
  h_el_prompt_EAiso->Write();
  h_el_npromp_EAiso->Write();
  h_mu_prompt_EAiso->Write();
  h_mu_npromp_EAiso->Write();
  h_el_prompt_noiso->Write();
  h_el_npromp_noiso->Write();
  h_mu_prompt_noiso->Write();
  h_mu_npromp_noiso->Write();
  h_el_prompt_DBiso->Write();
  h_el_npromp_DBiso->Write();
  h_mu_prompt_DBiso->Write();
  h_mu_npromp_DBiso->Write();
  h_el_prompt_MRiso->Write();
  h_el_npromp_MRiso->Write();
  h_mu_prompt_MRiso->Write();
  h_mu_npromp_MRiso->Write();
  h_min_dR->Write();
  outfile->Close();
  
  // return
  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;
  return 0;
}
