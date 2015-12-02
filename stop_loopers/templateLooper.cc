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
#include "../sharedCode/V00_00_02.h"
#include "../sharedCode/histTools.h"
#include "../sharedCode/METTemplateSelections.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"

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

void templateLooper::bookHistos(){

  // hist naming convention: "h_<leptype>_<gentype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  vector <string> gentype;
  leptype.push_back("el");
  leptype.push_back("lep");
  leptype.push_back("el_br");
  leptype.push_back("el_ec");
  leptype.push_back("mu");
  gentype.push_back("2l");
  vector <string> object;
  object.push_back("event");
  vector <string> selection;
  selection.push_back("inclusive");
  selection.push_back("passtrig");
  selection.push_back("njet2_incl");
  selection.push_back("njet2_met50");
  selection.push_back("njet2_met100");
  selection.push_back("njet3_incl");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("ptl1");    variable_bins.push_back(1000);  
  variable.push_back("met");     variable_bins.push_back(500 );  
  variable.push_back("ht");	     variable_bins.push_back(1000);  
  variable.push_back("mt");	     variable_bins.push_back(1000);  
  variable.push_back("njets");               variable_bins.push_back(20  );  
  variable.push_back("nVert");               variable_bins.push_back(50 );  
  variable.push_back("relIso03EA");	     variable_bins.push_back(1000);  
  variable.push_back("absIso03EA");	     variable_bins.push_back(1000);  
  variable.push_back("nhiso");	     variable_bins.push_back(1000);  
  variable.push_back("emiso");	     variable_bins.push_back(1000);  
  variable.push_back("chiso");	     variable_bins.push_back(1000);  

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
      for( unsigned int genind = 0; genind < gentype.size(); genind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < variable.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						gentype  .at(genind).c_str(),
						object   .at(objind).c_str(),
    					        variable .at(varind).c_str(),
  					        selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						gentype  .at(genind).c_str(),
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
   //--------------------// 
  // book Cutflow hists //
  //--------------------//
  map<string, TH1D*> histos_cutflow;
  vector<string> histonames_cutflow; histonames_cutflow.clear();
  histonames_cutflow.push_back("NEventsPerSignalRegion");
  
 //--------------------------------------------------------- //
 //   initialize cutflow histograms                          //
 //---------------------------------------------------------//

    for(unsigned int i = 0;i<histonames_cutflow.size();i++){
//    string histoname = histonames_cutflow.at(i);
    bookHist(histonames_cutflow.at(i),histonames_cutflow.at(i),8,0,8);
 //   histos_cutflow[histoname] = new TH1D(histoname.c_str(),"",8,0,8);
//    histos_cutflow[histoname]->Sumw2(); histos_cutflow[histoname]->SetDirectory(rootdir);
/*    histos_cutflow[histoname]->GetYaxis()->SetTitle("Events");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(1,"met[250,325],lDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(2,"met[325,Inf],lDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(3,"met[250,350],hDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(4,"met[350,450],hDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(5,"met[450,Inf],hDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(6,"3jet,hDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(7,"compressed1,hDM");
    histos_cutflow[histoname]->GetXaxis()->SetBinLabel(8,"compressed2,hDM");
  */  }
}

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  double nel = 0;
  double nmu = 0;
  double nemu = 0;

  double ne = 0;


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
    v00_00_02.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
    cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
	  v00_00_02.GetEntry(event);
      ++nEventsTotal;

	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
          fflush(stdout);
        }
      }

	 // if ( is_data() && usejson && !goodrun(run(), ls()) ) continue;
//         cout<<"passed"<<endl;

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
	   //if(nvtxs()<0)               continue;
	   if(nvtxs()<0)               continue;
	  //~-~-~-~-~-~-~-~~-//
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

	  if( !(HLT_SingleMuNoEta()||HLT_SingleMuNoIso()||HLT_SingleMuNoIsoNoEta() || HLT_SingleEl27())) continue;//trigger
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //   event weights       //
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( is_data() ){
		weight = 1.0;
	  }else if( !is_data() ){
		//weight *= fabs(scale1fb());
		weight *= scale1fb();
//                if() 
		//weight *= fabs(scale1fb())*genweights().at(0);
	  }

	  if( !is_data() && dovtxreweighting ){	
    	  weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(nvtxs()));		
	  }
	  
	  float event_met_pt = pfmet();
	  float event_met_ph = pfmet_phi();

	  //~-~-~-~-~-~-~-~-~//
	  // region selection//
	  //~-~-~-~-~-~-~-~-~//
          bool passtrig(false); bool njet2_incl(false); bool njet3_incl(false); bool njet2_met50(false); bool njet2_met100(false);

	  //~-~-~-~-~-~-~-~-//
          // event selection// 
	  //~-~-~-~-~-~-~-~-//
          //if( !usejson && is_data() && !evt_passgoodrunlist()   ) continue; // good runs lists
          if( !usejson && is_data() ) continue; // good runs lists

	  //~-~-~-~-~-~-~-~-//
          // lepton selection// 
	  //~-~-~-~-~-~-~-~-//

          int NSLeps = 0;          
          if(lep1_is_mu()){
              if(lep1_pt()>30&&fabs(lep1_eta())<2.1&&lep1_passMediumID()&&fabs(lep1_d0())<0.02&&fabs(lep1_dz())<0.1&&lep1_MiniIso()<0.1) {
              ++NSLeps;
              }
          } 
          else if (lep1_is_el()){
                if(lep1_pt()>35 && (fabs(lep1_eta())<1.4||(fabs(lep1_eta())>1.5 && fabs(lep1_eta())<2.1) ) && lep1_passMediumID()&&lep1_MiniIso()<0.1) {
                 ++NSLeps; 
             }
          }
          
	  if( NSLeps                       != 1         )  continue; // require at least 1 good lepton
	  if( nvetoleps()               > 1         ) continue; // second lepton veto
          if( ak4_HT() < 150)                         continue;
          if( event_met_pt < 50)                         continue;
          //if( lep1_chiso() >10 )  continue;
 	  if( lep1_is_mu()) nmu++;
	  if( lep1_is_el()) nel++;
//          if( lep1_is_el()) weight = weight;
          if( ngoodjets() >=2) njet2_incl = true; 
          if( ngoodjets() >=2 && event_met_pt > 50 && ngoodbtags()<1 ) njet2_met50 = true; 
          if( ngoodjets() >=3 && event_met_pt > 150 && ngoodbtags()<1 ) njet2_met100 = true; 
          if( ngoodjets() >=3) njet3_incl = true;
	  passtrig = true;	
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//
	  if(passtrig){
	  string region = "passtrig"; 
	  fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
	  fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"     , region.c_str(),  mt_met_lep()   , weight );
	  fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
	  fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );	  
	  fillHist( "event", "nVert"  , region.c_str(), nvtxs()        , weight );	  
//	  fillHist( "event", "metphi" , region.c_str(), event_met_ph        , weight );	 
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
         } 
        
          if(njet2_incl){
          string region = "njet2_incl";
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
  //        fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
          }
          if(njet3_incl){
          string region = "njet3_incl";
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
//          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
          }

          if(njet2_met50){
          string region = "njet2_met50";
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
//          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
          }

	  if(njet2_met100){
          string region = "njet2_met100";
          fillHist( "event", "njets"  , region.c_str(), ngoodjets()    , weight );
          fillHist( "event", "met"    , region.c_str(), event_met_pt        , weight );
	  fillHist( "event", "mt"    , region.c_str(),  mt_met_lep()   , weight );
          fillHist( "event", "ht"     , region.c_str(), ak4_HT()       , weight );
          fillHist( "event", "ptl1"   , region.c_str(), lep1_pt()      , weight );
          fillHist( "event", "nVert"  , region.c_str(),nvtxs()        , weight );
//          fillHist( "event", "metphi" , region.c_str(),event_met_ph        , weight );
	  fillHist( "event", "relIso03EA" , region.c_str(), lep1_relIso03EA()        , weight );	 
	  fillHist( "event", "absIso03EA" , region.c_str(), lep1_relIso03EA()*lep1_pt()        , weight );	 
	  fillHist( "event", "nhiso" , region.c_str(), lep1_nhiso()        , weight );	 
	  fillHist( "event", "emiso" , region.c_str(), lep1_emiso()        , weight );	 
	  fillHist( "event", "chiso" , region.c_str(), lep1_chiso()       , weight );	 
          }
	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
	  if( ngoodjets() < 2 ) continue; // require at least 2 good jets
          npass += weight;

    } // end loop over events
  } // end loop over files


//  cout << npass       << " events passing selection" << endl;
//  cout << nDuplicates << " duplicate events in data" << endl;
  cout << nel         << " el events passing selection" << endl;
  cout << nmu         << " mu events passing selection" << endl;
  cout << nemu         << " el+mu events passing selection" << endl;
 
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


void templateLooper::fillHist( string obj,string var, string sel, float value, float weight ){
  string hist = "h_";
  try
	{
	  if( lep1_is_el() ){
		hist = Form("h_el_2l_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
          if( lep1_is_el() && fabs(lep1_eta())>1.5&&fabs(lep1_eta())<2.1 ){
  		hist = Form("h_el_ec_2l_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
          if( lep1_is_el() &&fabs(lep1_eta())<1.4 ){
		hist = Form("h_el_br_2l_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
          }
	  if( lep1_is_mu() ){
		hist = Form("h_mu_2l_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
//	  if(gen_nfromtmus_() + gen_nfromtels_() + gen_nfromttaus_() ==2) {
          if( lep1_is_el() || lep1_is_mu()) {
		hist = Form("h_lep_2l_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
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

