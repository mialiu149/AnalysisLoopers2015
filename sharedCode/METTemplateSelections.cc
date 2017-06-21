#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1.h"
#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"

#include "METTemplateSelections.h"
#include "histTools.h"

using namespace std;

METTemplates::METTemplates( const string selection )
{
  photon_ptcuts.clear();
  photon_njetcuts.clear();
  photon_htcuts.clear();
  met_counts.clear();


  setBins( selection );
  size_t njetcuts = photon_njetcuts.size();  
  size_t nhtcuts  = photon_htcuts  .size();  
  size_t nptcuts  = photon_ptcuts  .size();  
  for(  size_t njets_ind = 0; njets_ind < njetcuts; njets_ind++ ){
	for(   size_t ht_ind = 0;    ht_ind <  nhtcuts;    ht_ind++ ){
	  for( size_t pt_ind = 0;    pt_ind <  nptcuts;    pt_ind++ ){
		string counts = Form("ncount_%i_%i_%i"
							 , static_cast<int>(njets_ind)
							 , static_cast<int>(ht_ind)
							 , static_cast<int>(pt_ind)
							 );
		// cout<<"methistname: "<<counts<<endl;
		met_counts.insert( pair<std::string,double>( counts.c_str(), 0.0) );
	  }
	}
  }
  photon_ptcuts.clear();
  photon_njetcuts.clear();
  photon_htcuts.clear();
  // exit(3);

}

METTemplates::~METTemplates()
{
  photon_ptcuts.clear();
  photon_njetcuts.clear();
  photon_htcuts.clear();
  met_counts.clear();
}

void METTemplates::bookMETHists( std::map<std::string, TH1F*> &methists )
{
  size_t njetcuts = photon_njetcuts.size();  
  size_t nhtcuts  = photon_htcuts  .size();  
  size_t nptcuts  = photon_ptcuts  .size();  
  std::string histname = "";
  std::string histtitle = "";
  for(  size_t njets_ind = 0; njets_ind < njetcuts; njets_ind++ ){
	for(   size_t ht_ind = 0;    ht_ind <  nhtcuts;    ht_ind++ ){
	  for( size_t pt_ind = 0;    pt_ind <  nptcuts;    pt_ind++ ){
		histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
						, static_cast<int>(njets_ind)
						, static_cast<int>(ht_ind)
						, static_cast<int>(pt_ind) );
		histtitle = Form("h_template_njets%i_pt%i_ht%i"
						 , static_cast<int>(photon_njetcuts.at(njets_ind))
						 , static_cast<int>(photon_ptcuts.at(pt_ind))
						 , static_cast<int>(photon_htcuts.at(ht_ind)) );
		// std::cout<<Form("Booking hist: %s", histname.c_str())<<std::endl;
		methists.insert ( pair<std::string,TH1F*>(histname, new TH1F(histname.c_str(), histtitle.c_str(), 500.0, 0, 500.0)));
		methists.at(histname)->Sumw2();	  
	  }
	}
  }
  return;
}

void METTemplates::setBins( const string selection )
{

  //set photon njets cuts
  photon_njetcuts.clear();
  photon_njetcuts.push_back(2);
  photon_njetcuts.push_back(3);

  //set event pT cuts
  photon_ptcuts.clear();
  photon_ptcuts.push_back(22);
  photon_ptcuts.push_back(40);
  photon_ptcuts.push_back(60);
  photon_ptcuts.push_back(80);
  photon_ptcuts.push_back(100);
  photon_ptcuts.push_back(125);
  photon_ptcuts.push_back(170);

  //set event HT cuts
  photon_htcuts.clear();
  photon_htcuts.push_back(35);
  photon_htcuts.push_back(70);
  photon_htcuts.push_back(105);
  photon_htcuts.push_back(140);
  // photon_htcuts.push_back(200);
  // photon_htcuts.push_back(350);
  // photon_htcuts.push_back(500);
  // photon_htcuts.push_back(1000);
  // photon_htcuts.push_back(1500);
  // photon_htcuts.push_back(2000);

  if( !TString(selection).Contains("bad") ) {
	if( TString(selection).Contains("3jets") ) {
	  if( TString(selection).Contains("edgec") ) {
		photon_ptcuts.clear();
		photon_ptcuts.push_back(45);
		photon_ptcuts.push_back(50);
		photon_ptcuts.push_back(75);
		photon_ptcuts.push_back(90);
		photon_ptcuts.push_back(135);
		photon_ptcuts.push_back(175);
		photon_htcuts.clear();
		photon_htcuts.push_back(105);
		photon_htcuts.push_back(140);
		photon_htcuts.push_back(250);
		photon_htcuts.push_back(400);
	  }
	  if( TString(selection).Contains("edgef") ) {
		photon_ptcuts.clear();
		photon_ptcuts.push_back(50);
		photon_ptcuts.push_back(60);
		photon_ptcuts.push_back(75);
		photon_ptcuts.push_back(90);
		photon_ptcuts.push_back(135);
		photon_ptcuts.push_back(200);
		photon_ptcuts.push_back(350);
		photon_htcuts.clear();
		photon_htcuts.push_back(105);
		photon_htcuts.push_back(140);
		photon_htcuts.push_back(250);
		photon_htcuts.push_back(400);
		photon_htcuts.push_back(600);
		photon_htcuts.push_back(1000);
	  }
	}

	if( TString(selection).Contains("2jets") ) {
	  if( TString(selection).Contains("edgec") ) {
		photon_ptcuts.clear();
		photon_ptcuts.push_back(50);
		photon_ptcuts.push_back(75);
		photon_ptcuts.push_back(90);
		photon_ptcuts.push_back(135);
		photon_ptcuts.push_back(175);
		photon_ptcuts.push_back(250);
		photon_htcuts.clear();
		photon_htcuts.push_back(70);
		photon_htcuts.push_back(105);
		photon_htcuts.push_back(140);
		photon_htcuts.push_back(250);
		photon_htcuts.push_back(400);
		photon_htcuts.push_back(600);
	  }
	  if( TString(selection).Contains("edgef") ) {
		photon_ptcuts.clear();
		photon_ptcuts.push_back(50);
		photon_ptcuts.push_back(75);
		photon_ptcuts.push_back(90);
		photon_ptcuts.push_back(135);
		photon_ptcuts.push_back(175);
		photon_ptcuts.push_back(250);
		photon_htcuts.clear();
		photon_htcuts.push_back(70);
		photon_htcuts.push_back(105);
		photon_htcuts.push_back(140);
		photon_htcuts.push_back(250);
		photon_htcuts.push_back(400);
		photon_htcuts.push_back(600);
		photon_htcuts.push_back(1000);
	  }
	}
  }
  
  //set event HT cuts
  if( TString(selection).Contains("bveto") ) {
	if( TString(selection).Contains("SRA") ){
	  photon_htcuts.push_back(600);
	  // photon_htcuts.push_back(640);
	  // photon_htcuts.push_back(680);
	  // photon_htcuts.push_back(720);
	  // photon_htcuts.push_back(760);
	  // photon_htcuts.push_back(860);
	  // photon_htcuts.push_back(900);
	  // photon_htcuts.push_back(1100);
	  // photon_htcuts.push_back(1500);
	  // photon_htcuts.push_back(2000);

	  // photon_htcuts.push_back(600);
	  // photon_htcuts.push_back(635);
	  // photon_htcuts.push_back(670);
	  // photon_htcuts.push_back(705);
	  // photon_htcuts.push_back(750);
	  // photon_htcuts.push_back(800);
	  // photon_htcuts.push_back(1000);
	  // photon_htcuts.push_back(1200);
	}
  
	if( TString(selection).Contains("SRB") ){
	  photon_htcuts.push_back(140);
	  photon_htcuts.push_back(175);
	  photon_htcuts.push_back(210);
	  photon_htcuts.push_back(245);
	  photon_htcuts.push_back(300);
	  photon_htcuts.push_back(500);
	  photon_htcuts.push_back(750);
	  photon_htcuts.push_back(1000);
	  photon_htcuts.push_back(1200);
	  photon_htcuts.push_back(1500);
	}
  }

  //set event HT cuts
  if( TString(selection).Contains("withb") ) {
	if( TString(selection).Contains("SRA") ){
	  photon_htcuts.push_back(600);
	  photon_htcuts.push_back(635);
	  photon_htcuts.push_back(670);
	  photon_htcuts.push_back(705);
	  photon_htcuts.push_back(750);
	  photon_htcuts.push_back(800);
	  photon_htcuts.push_back(1000);
	  photon_htcuts.push_back(1200);
	}

	if( TString(selection).Contains("SRB") ){
	  photon_htcuts.push_back(140);
	  photon_htcuts.push_back(175);
	  photon_htcuts.push_back(210);
	  photon_htcuts.push_back(245);
	  photon_htcuts.push_back(300);
	  photon_htcuts.push_back(500);
	  photon_htcuts.push_back(750);
	  photon_htcuts.push_back(1000);
	  photon_htcuts.push_back(1200);
	  photon_htcuts.push_back(1500);
	}
  }
  
}

int METTemplates::getNjetsBin( const int &njets )
{

  size_t ncuts = photon_njetcuts.size();  
  int returnval = -1;
  for( size_t njets_ind = 0; njets_ind < ncuts; njets_ind++ ){
	if( njets < photon_njetcuts.at(0) )
	  {
		std::cout<<Form("Number of jets less than %i. ", photon_njetcuts.at(0)) <<std::endl;
	    returnval = 999;
	  }
	else if( njets_ind+1 < ncuts ){
	  if     ( njets >= photon_njetcuts.at(njets_ind) && njets < photon_njetcuts.at(njets_ind+1) ){
	    returnval = njets_ind;
	  }
	}
	else if( njets_ind+1 == ncuts ){
	  if     ( njets >= photon_njetcuts.at(njets_ind) ){
	    returnval = njets_ind;
	  }
	}
  }
  return returnval;
  std::cout<<"WARNING: Did not find good Njets Bin. " <<std::endl;
  std::cout<<"NJets: "<<njets<<std::endl;
  return -9999;
}

int METTemplates::getHTBin( const float &HT )
{
  size_t ncuts = photon_htcuts.size();  
  for( size_t ht_ind = 0; ht_ind < ncuts; ht_ind++ ){
	if( HT < photon_htcuts.at(0) )
	  {
		// std::cout<<Form("HT less than %f. ", static_cast<double>(photon_htcuts.at(0))) <<std::endl;
		// return -999;
		return 0;
	  }
	else if( ht_ind+1 < ncuts ){
	  if     ( HT >= photon_htcuts.at(ht_ind) && HT < photon_htcuts.at(ht_ind+1) ){ return ht_ind;}
	}else if( ht_ind+1 == ncuts ){
	  if     ( HT >= photon_htcuts.at(ht_ind) ){ return ht_ind;}
	}
  }
  std::cout<<"WARNING: Did not find good HT Bin. " <<std::endl;
  std::cout<<"HT: "<<HT<<std::endl;
  return -9999;
}

int METTemplates::getpTBin( const float &pT )
{
  size_t ncuts = photon_ptcuts.size();  
  for( size_t pt_ind = 0; pt_ind < ncuts; pt_ind++ ){
	if( pT < photon_ptcuts.at(0) )
	  {
		// std::cout<<Form("pT in templater: %f. ", pT) <<std::endl;
		// std::cout<<Form("pT less than %f. ", static_cast<double>(photon_ptcuts.at(0))) <<std::endl;
		// return -999;
		return 0;
	  }
	else if( pt_ind+1 < ncuts ){
	  if     ( pT >= photon_ptcuts.at(pt_ind) && pT < photon_ptcuts.at(pt_ind+1) ){ return pt_ind; }
	}else if( pt_ind+1 == ncuts ){
	  if     ( pT >= photon_ptcuts.at(pt_ind) ){ return pt_ind; }
	}
  }
  std::cout<<"WARNING: Did not find good pT Bin. " <<std::endl;
  std::cout<<"pT: "<<pT<<std::endl;
  return -9999;
}

void METTemplates::FillTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt, float met, float weight )
{
  std::string histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
							  , static_cast<int>(getNjetsBin(njets))
							  , static_cast<int>(getHTBin(ht))
							  , static_cast<int>(getpTBin(pt)) );
  try
	{
	  fillUnderOverFlow(methists.at(histname.c_str()), met, weight);
	}
  catch ( exception &e )
	{
	  std::cout<<Form("Cannot find hist: %s", histname.c_str() )<<std::endl<<"Exiting."<<std::endl;
	  exit(1);
	}  
}

void METTemplates::NormalizeTemplates( std::map<std::string, TH1F*> &methists )
{
  for (std::map<std::string, TH1F*>::iterator itr = methists.begin(); itr != methists.end(); itr++){
	if( itr->second->GetEntries() > 0 ){
	  // cout<<itr->first<<endl;
	  itr->second->Scale(1.0/itr->second->GetSumOfWeights());
	}
  }
}

//How to use following functions:
  // cout << "Retrieving templates " << endl;
  // std::map<std::string, TH1F*> dummy;  
  // mettemplates.loadTemplatesFromFile( outputfilename, dummy);

  // double normalization = dummy.at("h_template_njetsind_1_htind_6_ptind_7")->GetEntries();
  // cout << "Nentries 1 " << normalization << endl;


  // cout << "Retrieving Hist for 3, 350, 175 " << endl;
  // TH1F * mettemplate = mettemplates.pickTemplate( dummy, 3, 350, 175 );
  // normalization = mettemplate->GetEntries();
  // cout << "Nentries 2 " << normalization << endl;

void METTemplates::loadTemplatesFromFile( const std::string filename, std::map<std::string, TH1F*> &methists )
{
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  // h_vtxweight->SetDirectory(rootdir);
  TFile *infile = new TFile(filename.c_str());
  std::cout<<"Reading hists from file: "<<filename<<std::endl;
  // infile->cd();
  TIter iKey(infile->GetListOfKeys());
  TKey* key=0;
  while((key=(TKey*)iKey())) {
	TH1* hist=(TH1*)key->ReadObjectAny(TH1::Class());
	std::string histname = hist->GetName();
	// std::cout<<"Name:  "<<TString(hist->GetName())<<std::endl;
	methists.insert ( pair<std::string,TH1F*>(histname, (TH1F*)hist));	
	// std::string histtitle = TString(hist->GetTitle())
	// std::cout<<"Title: "<<TString(hist->GetTitle())<<std::endl;
  }
  return;
}

TH1F* METTemplates::pickTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt )
{
  std::string histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
							  , static_cast<int>(getNjetsBin(njets))
							  , static_cast<int>(getHTBin(ht))
							  , static_cast<int>(getpTBin(pt)) );
  try
	{
	  return methists.at(histname.c_str());
	}
  catch ( exception &e )
	{
	  std::cout<<Form("Cannot find hist: %s", histname.c_str() )<<std::endl<<"Exiting."<<std::endl;
	  exit(1);
	}  
  return NULL;
}

void METTemplates::normalizeTemplate( TH1F * &current_template )
{
  current_template->Scale(1.0/current_template->GetSumOfWeights());
  return;
}


void METTemplates::countTemplate( int njets, float ht, float pt, double weight ){
  int njets_ind = static_cast<int>(getNjetsBin(njets));
  int ht_ind    = static_cast<int>(getHTBin(ht));
  int pt_ind    = static_cast<int>(getpTBin(pt));
  met_counts.at(Form("ncount_%i_%i_%i",njets_ind,ht_ind,pt_ind)) += weight;
  return;
}

void METTemplates::correctBinUncertainty( std::map<std::string, TH1F*> &methists, TH1F * &h_mettotal ){
  string histname = "";
  size_t njetcuts = photon_njetcuts.size();  
  size_t nhtcuts  = photon_htcuts  .size();  
  size_t nptcuts  = photon_ptcuts  .size();  
  for( int bin_ind = 0; bin_ind < h_mettotal->GetNbinsX() + 1; bin_ind++ ){
	//loop over all MET bins
    double corrected_unc = 0.0;
	//get corrected uncertainty with sqrt(N)*bin_unc
	for(  size_t njets_ind = 0; njets_ind < njetcuts; njets_ind++ ){
	  for(   size_t ht_ind = 0;    ht_ind <  nhtcuts;    ht_ind++ ){
		for( size_t pt_ind = 0;    pt_ind <  nptcuts;    pt_ind++ ){
		  histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
						  , static_cast<int>(njets_ind)
						  , static_cast<int>(ht_ind)
						  , static_cast<int>(pt_ind) );
		  try
			{
			  // cout<<met_counts.at(Form("ncount_%i_%i_%i"
			  // 						   , static_cast<int>(njets_ind)
			  // 						   , static_cast<int>(ht_ind)
			  // 						   , static_cast<int>(pt_ind)
			  // 						   ))<<endl;
			  corrected_unc += pow( methists.at(histname.c_str())->GetBinError(bin_ind)*met_counts.at(Form("ncount_%i_%i_%i"
																										   , static_cast<int>(njets_ind)
																										   , static_cast<int>(ht_ind)
																										   , static_cast<int>(pt_ind)
																										   )),2);
			}
		  catch ( exception &e )
			{
			  // cout<<"Histname: "<<histname<<endl;
			  // exit(2);
			}
		}
	  }
	}
	// cout<<"Uncertainty: "<<sqrt(corrected_unc)<<endl;
	h_mettotal->SetBinError(bin_ind,sqrt(corrected_unc));
  }
  return;
}
