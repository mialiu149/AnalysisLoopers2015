// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <stdexcept>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"

// ZMET
#include "../sharedCode/ZMET.h"

#include "../sharedCode/AnalysisSelections.h"
#include "../sharedCode/METTemplateSelections.h"

using namespace std;
using namespace ZMet;

int ScanChain( TChain* chain, string region = "2jets", string reweightvariable = "pt", bool fast = true, int nEvents = -1) {

  bool dopTreweighting = false;
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  METTemplates mettemplates( region );
  mettemplates.setBins     ( region );

  std::vector <int> pt_bins = mettemplates.get_pt_bins();
  std::vector <int> ht_bins = mettemplates.get_ht_bins();
  std::vector <int> nj_bins = mettemplates.get_nj_bins();

  // start here need multiple hists for different njets
  // Example Histograms
  TH1F * zjets_ht_ll = new TH1F(Form("zjets_ht_ll_%s", region.c_str() ), "", 2500, 0, 2500);
  TH1F * zjets_ht_ee = new TH1F(Form("zjets_ht_ee_%s", region.c_str() ), "", 2500, 0, 2500);
  TH1F * zjets_ht_mm = new TH1F(Form("zjets_ht_mm_%s", region.c_str() ), "", 2500, 0, 2500);
  TH1F * zjets_ht_em = new TH1F(Form("zjets_ht_em_%s", region.c_str() ), "", 2500, 0, 2500);
  TH1F * gjets_ht_ll = new TH1F(Form("gjets_ht_ll_%s", region.c_str() ), "", 2500, 0, 2500);
  zjets_ht_ll->Sumw2();
  zjets_ht_ee->Sumw2();
  zjets_ht_mm->Sumw2();
  zjets_ht_em->Sumw2();
  gjets_ht_ll->Sumw2();

  TFile * ptratiofile = NULL;
  if( reweightvariable == "ht" ) dopTreweighting = true;
  
  TH1F * h_ptratio[nj_bins.size()];
  if( dopTreweighting ){
	ptratiofile = TFile::Open(Form("reweightfiles/ratios_%s.root", region.c_str() ),"READ");
	for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){
	  h_ptratio[njetsind] = dynamic_cast<TH1F*>( ptratiofile->Get(Form("h_ratio_%i", nj_bins.at(njetsind))) ->Clone(Form("h_ptratio_%i", nj_bins.at(njetsind))));
	}
  }
  
  map <string, TH1F *> zjets_pt_ll;
  map <string, TH1F *> zjets_pt_ee;
  map <string, TH1F *> zjets_pt_mm;
  map <string, TH1F *> zjets_pt_em;
  map <string, TH1F *> gjets_pt_ll;

  map <string, TH1F *> m_ht_hists;

  if( dopTreweighting ){
	for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){
	  m_ht_hists.insert( make_pair(Form("zjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 2500, 0, 2500) ) );
	  m_ht_hists.insert( make_pair(Form("zjets_ht_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_ht_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 2500, 0, 2500) ) );
	  m_ht_hists.insert( make_pair(Form("zjets_ht_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_ht_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 2500, 0, 2500) ) );
	  m_ht_hists.insert( make_pair(Form("zjets_ht_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_ht_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 2500, 0, 2500) ) );
	  m_ht_hists.insert( make_pair(Form("gjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("gjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 2500, 0, 2500) ) );

	  m_ht_hists.at(Form("zjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  m_ht_hists.at(Form("zjets_ht_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  m_ht_hists.at(Form("zjets_ht_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  m_ht_hists.at(Form("zjets_ht_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  m_ht_hists.at(Form("gjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();  
	}
  }else{
  
	for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){
	  zjets_pt_ll.insert( make_pair(Form("zjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 1500, 0, 1500) ) );
	  zjets_pt_ee.insert( make_pair(Form("zjets_pt_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_pt_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 1500, 0, 1500) ) );
	  zjets_pt_mm.insert( make_pair(Form("zjets_pt_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_pt_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 1500, 0, 1500) ) );
	  zjets_pt_em.insert( make_pair(Form("zjets_pt_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("zjets_pt_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 1500, 0, 1500) ) );
	  gjets_pt_ll.insert( make_pair(Form("gjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), new TH1F(Form("gjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ), "", 1500, 0, 1500) ) );

	  zjets_pt_ll.at(Form("zjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  zjets_pt_ee.at(Form("zjets_pt_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  zjets_pt_mm.at(Form("zjets_pt_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  zjets_pt_em.at(Form("zjets_pt_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();
	  gjets_pt_ll.at(Form("gjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Sumw2();  
	}
  }
  
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

	cout<<"Processing file: "<<currentFile->GetTitle()<<endl;
	
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

	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //Deal with event weights//
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( zmet.isData() ){
		weight = 1.0;
	  }else if( !zmet.isData() ){
		weight *= zmet.evt_scale1fb();
	  }

      // Analysis Code
	  if( !passBaselineSelections()            ) continue;
	  if( !passSignalRegionSelection( region ) ) continue;

	  int njbin = mettemplates.getNjetsBin(zmet.njets());
	  njbin += 2;	

	  if( TString(currentFile->GetTitle()).Contains("dyjetsll") ){
		if( TString(currentFile->GetTitle()).Contains("m50inc") ){
		  if( highHT_zjinc( (string)currentFile->GetTitle() ) ) continue;
		}
		if( eventHas2GoodLeps() ){

		  if( dopTreweighting ){
			try{
			  if( zmet.hyp_type() == 0 ) m_ht_hists.at(Form("zjets_ht_ee_%s_%i", region.c_str(), njbin ))->Fill( zmet.ht(), weight );
			  if( zmet.hyp_type() == 1 ) m_ht_hists.at(Form("zjets_ht_mm_%s_%i", region.c_str(), njbin ))->Fill( zmet.ht(), weight );
			  if( zmet.hyp_type() == 2 ) m_ht_hists.at(Form("zjets_ht_em_%s_%i", region.c_str(), njbin ))->Fill( zmet.ht(), weight );
			  if( zmet.hyp_type() == 0 ||				    		       
				  zmet.hyp_type() == 1 ) m_ht_hists.at(Form("zjets_ht_ll_%s_%i", region.c_str(), njbin ))->Fill( zmet.ht(), weight );
			}catch( exception &e ){

			  cout<<"failed"<<endl;
			  exit(9);			
			}
		  }else{
			if( zmet.hyp_type() == 0 ) zjets_pt_ee.at(Form("zjets_pt_ee_%s_%i", region.c_str(), njbin ))->Fill( zmet.dilpt(), weight );
			if( zmet.hyp_type() == 1 ) zjets_pt_mm.at(Form("zjets_pt_mm_%s_%i", region.c_str(), njbin ))->Fill( zmet.dilpt(), weight );
			if( zmet.hyp_type() == 2 ) zjets_pt_em.at(Form("zjets_pt_em_%s_%i", region.c_str(), njbin ))->Fill( zmet.dilpt(), weight );
			if( zmet.hyp_type() == 0 ||				    			   		    					  
				zmet.hyp_type() == 1 ) zjets_pt_ll.at(Form("zjets_pt_ll_%s_%i", region.c_str(), njbin ))->Fill( zmet.dilpt(), weight );
		  }
		
		}
	  }
	  else if( eventHasGoodPhoton() ){
		if( dopTreweighting ){
		  float pTweight = 1.0;
		  pTweight = h_ptratio[mettemplates.getNjetsBin(zmet.njets())]->GetBinContent(h_ptratio[mettemplates.getNjetsBin(zmet.njets())]->FindBin(zmet.gamma_pt().at(0)));
		  m_ht_hists.at(Form("gjets_ht_ll_%s_%i", region.c_str(), njbin ))->Fill( zmet.ht(), pTweight*weight );
		}else{
		  gjets_pt_ll.at(Form("gjets_pt_ll_%s_%i", region.c_str(), njbin ))->Fill( zmet.gamma_p4().at(0).pt(), weight );		
		}
	  }

	}
 
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  // TH1F * ratio_pt = (TH1F*) zjets_pt_ll->Clone("ratio_pt");
  // TH1F * denom_pt = (TH1F*) gjets_pt_ll->Clone("denom_pt");
  // ratio_pt->Add(zjets_pt_em, -1);
  // ratio_pt->Scale(ratio_pt->Integral(0,-1));
  // denom_pt->Scale(denom_pt->Integral(0,-1));
  // ratio_pt->Divide(denom_pt);

  // TH1F * ratio_ht = (TH1F*) zjets_ht_ll->Clone("ratio_ht");
  // TH1F * denom_ht = (TH1F*) gjets_ht_ll->Clone("denom_ht");
  // ratio_ht->Add(zjets_ht_em, -1);
  // ratio_ht->Scale(ratio_ht->Integral(0,-1));
  // denom_ht->Scale(denom_ht->Integral(0,-1));
  // ratio_ht->Divide(denom_ht);
	
  // Example Histograms
  TFile * outfile = NULL;
  if( dopTreweighting ) outfile = TFile::Open(Form("ntuples/reweighting_hists_%s.root", region.c_str()), "UPDATE" );  
  else                  outfile = TFile::Open(Form("ntuples/reweighting_hists_%s.root", region.c_str()), "RECREATE" );  
  outfile->cd();
  if( dopTreweighting ) {
	// ratio_ht->Write();  
	// denom_ht->Write();  
	  for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){
		m_ht_hists.at(Form("zjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		m_ht_hists.at(Form("zjets_ht_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		m_ht_hists.at(Form("zjets_ht_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		m_ht_hists.at(Form("zjets_ht_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		m_ht_hists.at(Form("gjets_ht_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();  
	  }
  }

  else
	{
	  for( size_t njetsind = 0; njetsind < nj_bins.size(); njetsind++ ){
		zjets_pt_ll.at(Form("zjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		zjets_pt_ee.at(Form("zjets_pt_ee_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		zjets_pt_mm.at(Form("zjets_pt_mm_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		zjets_pt_em.at(Form("zjets_pt_em_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();
		gjets_pt_ll.at(Form("gjets_pt_ll_%s_%i", region.c_str(), nj_bins.at(njetsind) ))->Write();  
	  }
	}
  
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
