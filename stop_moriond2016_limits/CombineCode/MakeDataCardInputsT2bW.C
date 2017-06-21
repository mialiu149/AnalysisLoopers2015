// Usage:
// > root -b doAll.C

// C++
#include <iostream>
#include <vector>
#include <map>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "TLorentzVector.h"

// CMS3
//#include "CMS3_old20150505.cc"
#include "CMS3_fuckingsync.cc"

using namespace std;
using namespace tas;



int ScanChain( TChain* chain, bool fast = true, int nEvents = -1, string skimFilePrefix = "test") {
  int version = 4;
  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  // Example Histograms
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");


  map<string, TH1F*> histos;
  vector<string> histonames; histonames.clear();

  int nbins = 9; float blow = 0.5; float bup = 9.5; bool storeh = true;
  if(version== 1){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 2){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 3){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 4){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 5){ nbins =  6; blow = 0.5; bup =  6.5; storeh = true; }
  if(version== 6){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 7){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version== 8){ nbins =  7; blow = 0.5; bup =  7.5; storeh = true; }
  if(version== 9){ nbins =  7; blow = 0.5; bup =  7.5; storeh = true; }
  if(version==10){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version==11){ nbins =  6; blow = 0.5; bup =  6.5; storeh = true; }
  if(version==12){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version==13){ nbins =  6; blow = 0.5; bup =  6.5; storeh = true; }
  if(version==14){ nbins =  8; blow = 0.5; bup =  8.5; storeh = true; }
  if(version==15){ nbins =  5; blow = 0.5; bup =  5.5; storeh = true; }
  if(version==16){ nbins =  9; blow = 0.5; bup =  9.5; storeh = true; }
  if(version==17){ nbins = 11; blow = 0.5; bup = 11.5; storeh = true; }

  //AllBGCorr
  //CorrName1Name2Name3 with NameX being sampleX
  //CorrAllBG CorrAll means correlated among all backgrounds, or everything (bg+sig)
  histonames.push_back("SRyield");
  histonames.push_back("CRyield");
  histonames.push_back("StatUnc");
  histonames.push_back("SystUnc");
 
  for(unsigned int b = 0; b<2; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    //cout << helper << endl;
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    string mapname;
    for(unsigned int i = 0; i<histonames.size();++i){
      mapname = histonames[i] + "_" + samplename;
      //cout << mapname << " " << nbins << " " << blow << " " << bup << endl;
      if(histos.count(mapname) == 0 ) histos[mapname] = new TH1F(mapname.c_str(), "", nbins, blow, bup);
      histos[mapname]->Sumw2(); histos[mapname]->SetDirectory(rootdir);
      //cout << mapname << endl;
      //cout << mapname << endl;
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
    cms3.Init(tree);
    
    // Loop over Events in current file
    if( nEventsTotal >= nEventsChain ) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
    
      // Get Event Content
      if( nEventsTotal >= nEventsChain ) continue;
      if(fast) tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
      
      // Progress
      CMS3::progress( nEventsTotal, nEventsChain );
      
      string samplename = skimFilePrefix;
      if(skimFilePrefix=="TTbar"){
	if(genlepsfromtop() ==2) samplename = "TTbar2l";
	else if(genlepsfromtop() ==1) samplename = "TTbar1l";
	else { samplename = "TTbarH"; continue; }// cout << "no gen lep" << " " << genlepsfromtop() << endl; }
      }
      TString helper = TString(samplename);
      /*if(helper.Contains("Signal")){
	if(helper.Contains("T2tt")){
	  TString signalname = Form("%s_%d_%d",samplename.c_str(),(int)mass_stop(),(int)mass_lsp());
	  samplename = signalname.Data();
	}
      }*/
      
      // Analysis Code
      float weight = cms3.scale1fb()*3.;
      if(samplename == "Data") weight = 1.;
      if(is_data()) weight = 1.;
      if(event==0) cout << "weight " << weight << " nEvents " << cms3.nEvents() << " filename " << currentFile->GetTitle() << endl;
      //bool trackveto = cms3.PassTrackVeto();
      //bool tauveto = cms3.PassTauVeto();

      int NGLeps = 0;
      int NSLeps = 0;
      int NGJets = 0;
      int NGBJets = 0;

      if(lep1_is_mu()){
	if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NSLeps; }
	//if(lep1_pt()>30&&fabs(lep1_eta())<2.4&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {++NGLeps; }
      } else if (lep1_is_el()){
	if(lep1_pt()>40&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&lep1_MiniIso()<0.1) {++NSLeps; }
	//if(lep1_pt()>40&&fabs(lep1_eta())<2.5&&lep1_is_phys14_medium_noIso()&&lep1_MiniIso()<0.1) {++NGLeps; }
      }
      if(lep2_is_mu()){
       	if(lep2_pt()>30&&fabs(lep2_eta())<2.1&&lep2_passMediumID()&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NSLeps; }
      	//if(lep2_pt()>30&&fabs(lep2_eta())<2.4&&fabs(lep2_d0())<0.02&&fabs(lep2_dz())<0.1&&lep2_MiniIso()<0.1) {++NGLeps; }
      } else if (lep2_is_el()){
	if(lep2_pt()>40&&fabs(lep2_eta())<2.1&&lep2_passMediumID()&&lep2_MiniIso()<0.1) {++NSLeps; }
	//if(lep2_pt()>40&&fabs(lep2_eta())<2.5&&lep2_is_phys14_medium_noIso()&&lep2_MiniIso()<0.1) {++NGLeps; }
      }
      NGLeps = nvetoleps();
      
      for(unsigned int nj = 0; nj<ak4pfjets_CSV().size(); ++nj){
	if(ak4pfjets_p4()[nj].Pt()<30) continue;
	if(fabs(ak4pfjets_p4()[nj].Eta())>2.4) continue;
	if(ak4pfjets_loose_pfid()[nj]==false) continue;
	++NGJets;

	if(ak4pfjets_CSV()[nj]>0.890) {++NGBJets; }
      }

      if(nvtxs()<0)        continue;
      if(nvetoleps()!=1)   continue;
      //if(NSLeps!=1)        continue;
      if(ngoodleps()!=1)   continue;
      if(!PassTrackVeto_v3()) continue;
      if(!PassTauVeto())   continue;
      if(NGJets<3)         continue;
      if(NGBJets<1)        continue;
      if(mindphi_met_j1_j2()<0.8) continue;
      //if(hadronic_top_chi2()>10) continue;
      if(pfmet()<250)       continue;
      if(mt_met_lep()<150)  continue;

      //cout << __LINE__ << " version " << version << endl;
      bool ge4j = NGJets>=4;
      float met = pfmet();
      bool m2w = MT2W()>200.;
      bool mlb = Mlb_lead_bdiscr()>175.;
      float bpt = ak4pfjets_leadMEDbjet_p4().Pt();

      //NOTE that we already have MET>=250!
      float mybin = -1;
      
      if(version==16){
	if(bpt<=100){
	  if(!m2w) mybin = 1; else if(!mlb) mybin = 2; else mybin = 3;
	}
	else if(!m2w) mybin = 4;
	else if(!mlb){
	  if(met>375) mybin = 6; else mybin = 5;
	}
	else if(met>400) mybin = 9; else if(met>325) mybin = 8; else mybin = 7;
      }
      if(version==17){
	if(!mlb){
	  if(!m2w){
	    if(bpt<=150){
	      if(met>325) mybin = 2; else mybin = 1;
	    } else mybin = 8;
	  } else if(bpt<=150){
	    if(met>375) mybin = 4; else mybin = 3;
	  } else mybin = 9;
	}
	else if(!m2w) mybin = 5;
	else if(bpt<=150){
	  if(met>350) mybin = 7; else mybin = 6;
	}
	else if(met>350) mybin = 11; else mybin = 10;
      }
      
      if(!ge4j) continue;
      
      if(version==1){
	if(bpt<=100){
	  if(mlb) mybin = 3; else if(m2w) mybin = 2; else mybin = 1;
	} else {
	  if(!m2w) mybin = 4; else if(!mlb) mybin = 5;
	  else if(met>400) mybin = 8; else if(met>325) mybin = 7; else mybin = 6;
	}
      }
      if(version==2){
	if(bpt<=100){
	  if(!m2w) mybin = 1; else if(met>350) mybin = 3; else mybin = 2;
	} else {
	  if(!m2w) mybin = 4;
	  else if(met>450) mybin = 8; else if(met>350) mybin = 7; else if(met>300) mybin = 6; else mybin = 5;
	}
      }
      if(version==3){
	if(bpt<=100){
	  if(mlb) mybin = 3; else if(met>350) mybin = 2; else mybin = 1;
	} else if(bpt>100){
	  if(mlb){
	    if(met>400) mybin = 8; else if(met>300) mybin = 7; else mybin = 6;
	  } else if(met>350) mybin = 5; else mybin = 4;
	}
      }
      if(version==4){
	if(bpt<=100){
	  if(met>400) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
	} else {
	  if(met>450) mybin = 8; else if(met>375) mybin = 7; else if(met>325) mybin = 6; else if(met>275) mybin = 5; else mybin = 4;
	}
      }
      if(version==5){
	if(!mlb){
	  if(bpt>150) mybin = 4; else if(m2w) mybin = 2; else mybin = 1;
	} else {
	  if(m2w){
	    if(met>350&&bpt>150) mybin = 6; else if(bpt>150) mybin = 5;
	  } else mybin = 3;
	}
      }
      if(version==6){
	if(bpt<=150){
	  if(!m2w) mybin = 1; else if(met>400) mybin = 4; else if(met>300) mybin = 3; else mybin = 2;
	} else {
	  if(!m2w) mybin = 5; else if(met>400) mybin = 8; else if(met>300) mybin = 7; else mybin = 6;
	}
      }
      if(version==7){
	if(bpt<=150){
	  if(mlb){ if(met>300) mybin = 5; else mybin = 4; }
	  else if(met>400) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
	} else {
	  if(!mlb) mybin = 6; else if(met>350) mybin = 8; else mybin = 7;
	}
      }
      if(version==8){
	if(bpt<=150){
	  if(met>425) mybin = 4; else if(met>350) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
	} else if(met>400) mybin = 7; else if(met>325) mybin = 6; else mybin = 5;
      }
      if(version==9){
	if(bpt>200){
	  if(met>350) mybin = 7; else mybin = 6;
	} else if(m2w) {
	  if(met>400) mybin = 5; else if(met>325) mybin = 4; else mybin = 3;
	} else {
	  if(met>325) mybin = 2; else mybin = 1;
	}
      }
      if(version==10){
	if(bpt>200){
	  if(met>350) mybin = 8; else mybin = 7;
	} else if(mlb){
	  if(met>375) mybin = 6; else if(met>300) mybin = 5; else mybin = 4;
	} else {
	  if(met>400) mybin = 3; else if(met>325) mybin = 2; else mybin = 1;
	}
      }
      if(version==11){
	if(bpt>200){
	  if(met>350) mybin = 6; else mybin = 5;
	}
	else if(met>450) mybin = 4; else if(met>350) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
      }
      if(version==12){
	if(!mlb){
	  if(!m2w){
	    if(met>325) mybin = 2; else mybin = 1;
	  }
	  else if(met>375) mybin = 4; else mybin = 3;
	} else if(!m2w) mybin = 5; else if(met>400) mybin = 8; else if(met>300) mybin = 7; else mybin = 6;
      }
      if(version==13){
	if(mlb){
	  if(met>350) mybin = 6; else if(met>300) mybin = 5; else mybin = 4;
	}
	else if(met>425) mybin = 3; else if(met>325) mybin = 2; else mybin = 1;
      }
      if(version==14){
	if(m2w){
	  if(met>500) mybin = 8; else if(met>400) mybin = 7; else if(met>350) mybin = 6; else if(met>300) mybin = 5; else mybin = 4;
	}
	else if(met>350) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
      }
      if(version==15){
	if(met>500) mybin = 5; else if(met>400) mybin = 4; else if(met>350) mybin = 3; else if(met>300) mybin = 2; else mybin = 1;
      }
      //cout << __LINE__ << " mybin " << mybin << " " << samplename << endl;
      //cout << "SRyield_" + samplename << endl;
      histos["SRyield_" + samplename]->Fill(mybin,weight);

    }
  
    // Clean Up
    delete tree;
    file->Close();
    delete file;
  }
  if ( nEventsChain != nEventsTotal ) {
    cout << Form( "ERROR: number of events from files (%d) is not equal to total number of events (%d)", nEventsChain, nEventsTotal ) << endl;
  }

  //do all postrunning modifications here - maybe need some additional code if running over additional types of babies
  //i.e.if we have additional babies, run extra, hadd files and do further modifications (note you might need to store additional histos)
  for(unsigned int b = 0; b<2; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) samplename = "TTbarH";
    string mapname;
    for(int i = 1; i<=histos["SRyield_"+samplename]->GetNbinsX();++i){
      if(histos["SRyield_"+samplename]->Integral()>0) {
	if(histos["SRyield_"+samplename]->GetBinContent(i)>0){
	  histos["StatUnc_"+samplename]->SetBinContent(i, histos["SRyield_"+samplename]->GetBinError(i)/histos["SRyield_"+samplename]->GetBinContent(i));
	}
	else histos["StatUnc_"+samplename]->SetBinContent(i, -999);
	histos["SystUnc_"+samplename]->SetBinContent(i, 0.3);
      }
    }
  }  

  //save all relevant histograms into some rootfiles
  for(unsigned int b = 0; b<2; ++b){
    string samplename = skimFilePrefix;
    TString helper = TString(samplename);
    if(skimFilePrefix!="TTbar"&&b>0) continue;
    if(skimFilePrefix=="TTbar"&&b==0) samplename = "TTbar1l";
    if(skimFilePrefix=="TTbar"&&b==1) samplename = "TTbar2l";
    if(skimFilePrefix=="TTbar"&&b==2) continue;
    string filename = "inputfiles/"+samplename+".root";
    if(version== 1) filename = "inputfiles/v1/"+samplename+".root";
    if(version== 2) filename = "inputfiles/v2/"+samplename+".root";
    if(version== 3) filename = "inputfiles/v3/"+samplename+".root";
    if(version== 4) filename = "inputfiles/v4/"+samplename+".root";
    if(version== 5) filename = "inputfiles/v5/"+samplename+".root";
    if(version== 6) filename = "inputfiles/v6/"+samplename+".root";
    if(version== 7) filename = "inputfiles/v7/"+samplename+".root";
    if(version== 8) filename = "inputfiles/v8/"+samplename+".root";
    if(version== 9) filename = "inputfiles/v9/"+samplename+".root";
    if(version==10) filename = "inputfiles/v10/"+samplename+".root";
    if(version==11) filename = "inputfiles/v11/"+samplename+".root";
    if(version==12) filename = "inputfiles/v12/"+samplename+".root";
    if(version==13) filename = "inputfiles/v13/"+samplename+".root";
    if(version==14) filename = "inputfiles/v14/"+samplename+".root";
    if(version==15) filename = "inputfiles/v15/"+samplename+".root";
    if(version==16) filename = "inputfiles/v16/"+samplename+".root";
    if(version==17) filename = "inputfiles/v17/"+samplename+".root";
    TFile *f = new TFile(filename.c_str(),"RECREATE");
    f->cd();
    string mapname;
    for(unsigned int i = 0; i<histonames.size();++i){
      mapname = histonames[i] + "_" + samplename;
      if(storeh) histos[mapname]->Write();
    }
    f->Close();
    cout << "Saved histos in " << f->GetName() << endl;
  }

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
