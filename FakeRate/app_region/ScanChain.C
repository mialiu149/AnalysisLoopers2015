#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <fstream>
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH2D.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TString.h"
#include "TPaveText.h"
#include "../../CORE/SSSelections.h"
#include "../../CORE/IsolationTools.h"
#include "../../CORE/Tools/utils.h"
#include "../../CORE/Tools/dorky/dorky.cc"
#include "../../classFiles/triboson_v0.1.16/triboson.h"
#include "../../software/dataMCplotMaker/PlotMaker2D.h"
#include "../../software/dataMCplotMaker/dataMCplotMaker.h"
#include "../../commonUtils/commonUtils.h"
#include "../../sharedCode/TribosonSelection.h"
#include "../../sharedCode/histTools.h"

using namespace std;
using namespace duplicate_removal;


bool doLatex = true;
bool doRatio = false;
bool inclHT = true;
bool debug = false; 

std::string looselep = "ss_VVV_cutbased_fo_default";
std::string plotdir="~mliu/public_html/www_closure/plots/triggersafev1/";
//std::string looselep = "ss_VVV_cutbased_fo_v5";
//std::string plotdir="~mliu/public_html/www_closure/plots/v5_2jets/";
TString version = TString(looselep);

const double coneCorrCut = 0.06;
std::map<std::string, TH1F*> event_hists;
TH1D * evtCounter = new TH1D("","",1000,0,1000); 
map<TString, int> evtBinMap;
int evtBin = 0;
void initCounter() {
    evtCounter = new TH1D("","",1000,0,1000); 
    evtCounter->Sumw2();
    evtBinMap.clear();
}

void addToCounter(TString name, double weight=1.0) {
    if(evtBinMap.find(name) == evtBinMap.end() ) {
        evtBinMap[name] = evtBin;
        evtBin++;
    }
    evtCounter->Fill(evtBinMap[name], weight);
}

void printCounter(bool file = false) {
    ofstream outfile;
    if(file) outfile.open("counter.txt");
    cout << string(30, '-') << endl << "Counter totals: " << endl;
    for(map<TString,int>::iterator it = evtBinMap.begin(); it != evtBinMap.end(); it++) {
        int iBin = (it->second)+1;
        printf("%-15s %6.2f %6.2f\n",
                (it->first).Data(),
                evtCounter->GetBinContent(iBin),
                evtCounter->GetBinError(iBin) );
        if(file) outfile << (it->first).Data() << "  " << evtCounter->GetBinContent(iBin) << "  " << evtCounter->GetBinError(iBin) << endl;
    }
    cout << string(30, '-') << endl;
    if(file) outfile.close();
    if(file) cout << "Wrote counter to counter.txt" << endl;
}

bool isFakeLeg(int lep, bool doData=false){
     if (doData) return true;
      //doublecheck
      vector<unsigned int> ilep = tribosonsel::selectedLeps(looselep);
      if(ilep.size()<2)  return 1; 
      unsigned int lep1_index = ilep.at(0);
      unsigned int lep2_index = ilep.at(1);
      int lep1_motherID = triboson_np::lep_motherIdSS().at(lep1_index);
      int lep2_motherID = triboson_np::lep_motherIdSS().at(lep2_index);
      if (lep == 1) return (lep1_motherID <= 0);
      if (lep == 2) return (lep2_motherID <= 0);
  return 0;
}

bool isGoodLeg(int lep, bool doData=false){
  if (doData) return true;
  //doublecheck
      vector<unsigned int> ilep = tribosonsel::selectedLeps(looselep);
      if(ilep.size()<2)  return 1; 
      unsigned int lep1_index = ilep.at(0);
      unsigned int lep2_index = ilep.at(1);
 //     int   lep1_motherID = tribosonsel::lepMotherID_v2(lep1_index).first;//write this function
  //    int   lep2_motherID = tribosonsel::lepMotherID_v2(lep2_index).first;
      int lep1_motherID = triboson_np::lep_motherIdSS().at(lep1_index);
      int lep2_motherID = triboson_np::lep_motherIdSS().at(lep2_index);
      if (lep == 1) return (lep1_motherID == 1 || lep1_motherID == 2);
      if (lep == 2) return (lep2_motherID == 1 || lep2_motherID == 2);
  return 0;
}

bool AN_MVA(int level, int lep_id, float lep_etaSC, float lep_MVA){
    // level == 1 for Iso and 2 for noniso
    lep_etaSC = fabs(lep_etaSC);
    if (abs(lep_id) != 11) return true;

    // http://uaf-8.t2.ucsd.edu/~namin/dump/ssan.pdf#page=55
    //    - Isolated trigger denominator: (0.05, -0.26, -0.40)
    //    - Non-isolated trigger denominator: (-0.36,-0.58,-0.62)
    //       - will need to bypass the passIsolatedFO stuff in order to use this since this is looser than that
    if (level == 1) {
        if (lep_etaSC < 0.8) return lep_MVA > 0.05;
        if ((lep_etaSC >= 0.8 && lep_etaSC <= 1.479)) return lep_MVA > -0.26;
        if (lep_etaSC > 1.479) return lep_MVA > -0.40;
    } else if (level == 2) {
        if (lep_etaSC < 0.8) return lep_MVA > -0.36;
        if ((lep_etaSC >= 0.8 && lep_etaSC <= 1.479)) return lep_MVA > -0.58;
        if (lep_etaSC > 1.479) return lep_MVA > -0.62;
    }
    return false;
}

float computePtRel(LorentzVector lepp4, LorentzVector jetp4, bool subtractLep){
  if (jetp4.pt()==0) return 0.;
  if (subtractLep) jetp4-=lepp4;
  float dot = lepp4.Vect().Dot( jetp4.Vect() );
  float ptrel = lepp4.P2() - dot*dot/jetp4.P2();
  ptrel = ptrel>0 ? sqrt(ptrel) : 0.0;
  return ptrel;
}

int number = 0;
/*
float getFakeRate(int id, float pt, float eta, float ht, bool extrPtRel = false, bool doData = false, bool doInSitu = false){
    if (inclHT) ht = -1; // negative ht means use inclusive ht in commonUtils // FIXME

    if (doInSitu) return fakeRateInSitu(id, pt, eta, ht);
    else if (doData ) return fakeRate(id, pt, eta, ht);
    else return qcdMCFakeRateWWW(id, pt, eta, ht);
}

float getFakeRateError(int id, float pt, float eta, float ht, bool doInSitu = false) { 
    if (doInSitu) return fakeRateErrorInSitu(id, pt, eta, ht);
    else return fakeRateError(id, pt, eta, ht);
}

float getFakeRate2(int id, float pt, float eta, float ht, bool extrPtRel = false, bool doData = false){
  if (doData) return fakeRateNoCC(id, pt, eta, ht);
  else return qcdMCFakeRateWWW(id, pt, eta, ht);
}
*/
void GetErrorPlot(TH1F *pred, vector< vector<TH2D*> > pred_err2_mu, vector< vector<TH2D*> > pred_err2_el, bool inSitu){

  for (int bin=1;bin<=pred->GetNbinsX();++bin) {
    int sr = bin-1;
    float p = pred->GetBinContent(bin);
    //stat error on nFOs
    float pe = pred->GetBinError(bin);
    float pefr2 = 0;
    //stat error on FR 
    for (unsigned int i = 0; i < 2; i++){
      if (pred_err2_mu[i][sr]!=0) { 
        for (int frbinx=1;frbinx<=pred_err2_mu[i][sr]->GetNbinsX();++frbinx) {
          for (int frbiny=1;frbiny<=pred_err2_mu[i][sr]->GetNbinsY();++frbiny) {
            float fr = getFakeRate(13, pred_err2_mu[i][sr]->GetXaxis()->GetBinLowEdge(frbinx), pred_err2_mu[i][sr]->GetYaxis()->GetBinLowEdge(frbiny), i == 0 ? 500 : 150, false, inSitu,version); 
            float fre = getFakeRateError(13, pred_err2_mu[i][sr]->GetXaxis()->GetBinLowEdge(frbinx), pred_err2_mu[i][sr]->GetYaxis()->GetBinLowEdge(frbiny), i == 0 ? 500 : 150,  inSitu); 
            float tot = pred_err2_mu[i][sr]->GetBinContent(frbinx,frbiny);
            pefr2 += fre*fre*pow(1-fr,-4)*tot*tot;
          }
        }
      }
      if (pred_err2_el[i][sr]!=0) { 
        for (int frbinx=1;frbinx<=pred_err2_el[i][sr]->GetNbinsX();++frbinx) {
          for (int frbiny=1;frbiny<=pred_err2_el[i][sr]->GetNbinsY();++frbiny) {
            float fr = getFakeRate(11, pred_err2_el[i][sr]->GetXaxis()->GetBinLowEdge(frbinx), pred_err2_el[i][sr]->GetYaxis()->GetBinLowEdge(frbiny), i == 0 ? 500 : 150, false, inSitu,version);
            float fre = getFakeRateError(11, pred_err2_el[i][sr]->GetXaxis()->GetBinLowEdge(frbinx), pred_err2_el[i][sr]->GetYaxis()->GetBinLowEdge(frbiny), i == 0 ? 500 : 150,  inSitu);
            float tot = pred_err2_el[i][sr]->GetBinContent(frbinx,frbiny);
            pefr2 += fre*fre*pow(1-fr,-4)*tot*tot;
          }
        }
      }
    }
    //now combine the two
    pe = sqrt(pe*pe + pefr2);
    pred->SetBinError(bin, pe); 
  }
}


//getPt and getEta need to stay on sync with meas region
float getPt(float pt, bool extrPtRel = false){
  if(pt < 10.)  return 11.;  
  if(!extrPtRel && pt >= 70.) return 69.;
  if(extrPtRel && pt >= 150.) return 149.;
  return pt;
}

float getEta(float eta, float ht, bool extrPtRel = false){
  if (extrPtRel) {
    if(ht >= 800) return 799;
    return ht;
  }
  if(fabs(eta) >= 2.4) return 2.3;
  return fabs(eta);
}
//what a pointless function!
TH1F* histCreator(string str1, string str2, int n1, float n2, float n3){
  TH1F *temp = new TH1F(str1.c_str(), str2.c_str(), n1, n2, n3);   
  return temp;
}
TH1F* histCreator(string str1, string str2, int nbins, float xbins[]){
  // int nbins = 5;
  // float xbins[6] = {10, 15, 25, 35, 50, 1000};
  TH1F *temp = new TH1F(str1.c_str(), str2.c_str(), nbins, xbins);
  return temp;
}

vector <TH1F*> hists; 
int getHist(TString name){
  for (unsigned int i = 0; i < hists.size(); i++){
    if (hists[i]->GetName() == name) return i; 
  }
  cout << "getHist failed on: " << name << ".  Be careful of spurious spaces!" << endl;
  return -1;
}


std::vector<std::pair<TH1F*, TH1F*> > getBackgrounds(std::string type, int isMu, std::vector<TString> filenames) {
  std::vector<std::pair<TH1F*, TH1F*> > pairs;
  for(unsigned int i = 0; i < filenames.size(); i++) {
      std::string histname = type;
      if(isMu == 0) histname += "_el";
      else if(isMu == 1) histname += "_mu";
      histname += filenames[i].Data();
      // if(TString(histname).Contains("_obs")) continue; // FIXME - remove when not doing data
      pairs.push_back( make_pair(hists[getHist(histname)],hists[getHist(histname)]) );
  }
  return pairs;
}

void printClosureNumbers(std::vector<TString> filenames) {
    for(int imu = -1; imu < 2; imu++) {
        TString musuffix = "";
        if (imu == 1) musuffix = "_mu";
        else if (imu == 0) musuffix = "_el";

        std::cout << "-- Closure for " << (imu >= 0 ? (imu == 1 ? "MU" : "EL" ) : "TOTAL") << " -- " << std::endl;
        float val_pred = hists[getHist("Npn_histo_br_pred"+musuffix)]->GetBinContent(2);
        float val_pred_error = hists[getHist("Npn_histo_br_pred"+musuffix)]->GetBinError(2);
        std::cout << "  pred: " << val_pred << std::endl;
        std::vector<std::pair<TH1F*,TH1F*> > vobs = getBackgrounds("Npn_histo_br_obs",imu,filenames);
        float tot_obs = 0.;
        float tot_obs_error = 0.;
        for(unsigned int ifile = 0; ifile < filenames.size(); ifile++) {
           float val_obs = vobs.at(ifile).first->GetBinContent(2);
           float val_obs_error = vobs.at(ifile).first->GetBinError(2);
            tot_obs += val_obs;
            tot_obs_error +=pow(val_obs_error,2);
           std::cout << "   " << filenames[ifile] << " obs: " << val_obs << std::endl;
       }
         
        std::cout << "  --> pred/obs: " << val_pred/tot_obs << std::endl;
        std::cout << "  --> error: " << (val_pred/tot_obs)*sqrt(pow(val_pred_error/val_pred,2)+ tot_obs_error*pow(1/tot_obs,2)) << std::endl;
         
       std::cout << std::endl;
    }
}

void fillHist( string obj, string var, string sel,int lepid ,float value, float weight ){
  string hist = "h_";
  try
	{
          if( abs(lepid) ==11 ){
		hist = Form("h_el_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
         }
          if( abs(lepid) ==13 ){
		hist = Form("h_mu_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
         }
 
        hist = Form("h_lep_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
        fillUnderOverFlow(event_hists.at( hist ), value, weight);
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
	return;
}  


void bookHist( string name, string title, int nbins, float xmin, float xmax ){
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}

void bookHistos(std::string region){
  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("lep");
  leptype.push_back("el");
  leptype.push_back("mu");
  vector <string> object;
  object.push_back("event");
  vector <string> selection; 
  selection.push_back(region.c_str());
  vector <string> variable;             vector <float> variable_bins;
  variable.push_back("hyp_class");         variable_bins.push_back(20  );  
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < variable.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype.at(lepind).c_str(),
						object.at(objind).c_str(),
					        variable.at(varind).c_str(),
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
  }//hists with integer binning

  vector <string> phivars;
  phivars.push_back("metphi");
  phivars.push_back("fakerate_weight");
 
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

  //----------------------// 
  // book counting hists  //
}//end of booking hists
int ScanChain( TChain* chain, TString option = "", TString ptRegion = "HH", bool doData = false, int nEvents = -1){

  initCounter();
  string selection = "br";
  bookHistos(selection.c_str());  
  //Parse options
  bool coneCorr = option.Contains("coneCorr") ? true : false;
  bool jetCorr = option.Contains("jetCorr") ? true : false;
  bool usePtRatioCor = option.Contains("PtRatioCor") ? true :false;
  bool doBonly = option.Contains("doBonly") ? true : false;
  bool doTauonly = option.Contains("doTauonly") ? true : false;
  bool doConly = option.Contains("doConly") ? true : false;
  bool doLightonly = option.Contains("doLightonly") ? true : false;
  bool inSitu = option.Contains("inSitu") ? true : false;
  bool soup = option.Contains("soup") ? true : false;
  bool PCssZ = option.Contains("PCssZ") ? true : false;
  bool ssZ = (!PCssZ && option.Contains("ssZ")) ? true : false;
  bool PC = (!PCssZ && option.Contains("PC")) ? true : false;
  bool notCC = option.Contains("notCC") ? true : false;
  bool looseEMVA = option.Contains("LooseEMVA") ? true : false;
  bool highhigh = ptRegion.Contains("HH") ? true : false;
  bool highlow = ptRegion.Contains("HL") ? true : false;
  bool lowlow = ptRegion.Contains("LL") ? true : false;

  bool testMVA = option.Contains("_mva") ? true : false;
  bool extrPt = option.Contains("_ept") ? true : false;
  inclHT = option.Contains("_hth") ? true : false;

  bool doLowHT = option.Contains("IsoTrigs") ? true : false;
  bool doHighHT = option.Contains("HTTrigs") ? true : false;

  bool doSpecial = option.Contains("special") ? true : false;

  bool weightOne = false;
  bool bypass = false;
  bool doSubtractContamination = false;
  bool requireIsoTriggers = false;

  // float luminosity = doData ? getLumi() : 12.9;
  float luminosity = doData ? getLumi() : getLumi();

  //Dir
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  int nsr = 33;
  if (highlow) nsr = 27;
  if (lowlow)  nsr = 8;

  //Make rate histo (for shape only)
  float xbins[6] = {10, 15, 25, 35, 50, 1000};
  float xbins_extr[7] = {10, 15, 25, 35, 50, 70, 1000};
  float xbins_abbrev[5] = {15, 25, 35, 50, 150};
  float ybinse[4] = {0, 0.8, 1.479, 2.5}; 
  float ybinsm[4] = {0, 1.2, 2.1, 2.4}; 

  TH2D *rate_histo_e;
  TH2D *rate_histo_mu;
  if (extrPt) {
      rate_histo_e  = new TH2D("elec", "elec", 6, xbins_extr, 3, ybinse);
      rate_histo_mu = new TH2D("muon", "muon", 6, xbins_extr, 3, ybinsm);
  } else {
      rate_histo_e  = new TH2D("elec", "elec", 5, xbins     , 3, ybinse);
      rate_histo_mu = new TH2D("muon", "muon", 5, xbins     , 3, ybinsm);
  }

  //Histograms
  vector<TString> possibleFilenames = {"TTBAR", "WJets"};
  for (unsigned int i = 0; i < possibleFilenames.size(); i++) {
      std::string fname = possibleFilenames[i].Data();
      hists.push_back( histCreator("Npn_histo_br_obs"        + fname, "Observed Prompt-NonPrompt Background"              ,  4, 0,    4) ); 
      hists.push_back( histCreator("Npn_histo_br_pred"              , "Predicted Prompt-NonPrompt Background"             ,  4, 0,    4) );
      hists.push_back( histCreator("Npn_histo_br_obs_mu"     + fname, "Observed Prompt-NonPrompt Background (Single mu)"  ,  4, 0,    4) );
      hists.push_back( histCreator("Npn_histo_br_pred_mu"           , "Predicted Prompt-NonPrompt Background (Single mu)" ,  4, 0,    4) );
      hists.push_back( histCreator("Npn_histo_br_obs_el"     + fname, "Observed Prompt-NonPrompt Background (Single el)"  ,  4, 0,    4) );
      hists.push_back( histCreator("Npn_histo_br_pred_el"           , "Predicted Prompt-NonPrompt Background (Single el)" ,  4, 0,    4) );
      hists.push_back( histCreator("Npn_histo_sr_obs"        + fname, "Observed Prompt-NonPrompt Background"              , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_sr_pred"              , "Predicted Prompt-NonPrompt Background"             , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_sr_obs_mu"     + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_sr_pred_mu"           , "Predicted Prompt-NonPrompt Background (Single mu)" , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_sr_obs_el"     + fname, "Observed Prompt-NonPrompt Background (Single el)"  , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_sr_pred_el"           , "Predicted Prompt-NonPrompt Background (Single el)" , nsr, 0.5,   nsr+0.5) );
      hists.push_back( histCreator("Npn_histo_HT_obs"        + fname, "Observed Prompt-NonPrompt Background"              , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_HT_pred"              , "Predicted Prompt-NonPrompt Background"             , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_HT_obs_mu"     + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_HT_pred_mu"           , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_HT_obs_el"     + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_HT_pred_el"           , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0, 1000) );
      hists.push_back( histCreator("Npn_histo_MET_obs"       + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MET_pred"             , "Predicted Prompt-NonPrompt Background"             , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MET_obs_mu"    + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MET_pred_mu"          , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MET_obs_el"    + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MET_pred_el"          , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_njets_obs"       + fname, "Observed Prompt-NonPrompt Background"              , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_njets_pred"             , "Predicted Prompt-NonPrompt Background"             , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_njets_obs_mu"    + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_njets_pred_mu"          , "Predicted Prompt-NonPrompt Background (Single mu)" , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_njets_obs_el"    + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_njets_pred_el"          , "Predicted Prompt-NonPrompt Background (Single el)" , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_obs"       + fname, "Observed Prompt-NonPrompt Background"              , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_pred"             , "Predicted Prompt-NonPrompt Background"             , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_obs_mu"    + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_pred_mu"          , "Predicted Prompt-NonPrompt Background (Single mu)" , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_obs_el"    + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_nbtags_pred_el"          , "Predicted Prompt-NonPrompt Background (Single el)" , 10, 0,   10) );
      hists.push_back( histCreator("Npn_histo_MJJ_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_pred"           , "Predicted Prompt-NonPrompt Background"             , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_pred"           , "Predicted Prompt-NonPrompt Background"             , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MJJ_lead_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_pred"           , "Predicted Prompt-NonPrompt Background"             , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_DYJJ_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MLL_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MLL_pred"           , "Predicted Prompt-NonPrompt Background"             , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MLL_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MLL_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MLL_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MLL_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   500) );
      hists.push_back( histCreator("Npn_histo_MTMAX_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MTMAX_pred"           , "Predicted Prompt-NonPrompt Background"             , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MTMAX_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MTMAX_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MTMAX_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_MTMAX_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 20, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_obs"      + fname, "Observed Prompt-NonPrompt Background"              , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_pred"            , "Predicted Prompt-NonPrompt Background"             , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_obs_mu"   + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_pred_mu"         , "Predicted Prompt-NonPrompt Background (Single mu)" , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_obs_el"   + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L1PT_pred_el"         , "Predicted Prompt-NonPrompt Background (Single el)" , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_obs"      + fname, "Observed Prompt-NonPrompt Background"              , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_pred"            , "Predicted Prompt-NonPrompt Background"             , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_obs_mu"   + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_pred_mu"         , "Predicted Prompt-NonPrompt Background (Single mu)" , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_obs_el"   + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_L2PT_pred_el"         , "Predicted Prompt-NonPrompt Background (Single el)" , 30, 0,   250) );
      hists.push_back( histCreator("Npn_histo_LTrue_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LTrue_pred"           , "Predicted Prompt-NonPrompt Background"             , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LTrue_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LTrue_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LTrue_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LTrue_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_obs"     + fname, "Observed Prompt-NonPrompt Background"              , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_pred"           , "Predicted Prompt-NonPrompt Background"             , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_obs_el"  + fname, "Observed Prompt-NonPrompt Background (Single el)"  , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFake_pred_el"        , "Predicted Prompt-NonPrompt Background (Single el)" , 30, 0,  250) );
      hists.push_back( histCreator("Npn_histo_LFakeiso_obs_mu"  + fname, "Observed Prompt-NonPrompt Background (Single mu)"  , 100, 0,  0.4) );
      hists.push_back( histCreator("Npn_histo_LFakeiso_pred_mu"        , "Predicted Prompt-NonPrompt Background (Single mu)" , 100, 0,  0.4) );
      hists.push_back( histCreator("NBs_BR_histo_e"                 , "Number of FOs from B's vs Nbtags (els)"            ,  4, 0,    4) );
      hists.push_back( histCreator("NBs_BR_histo_mu"                , "Number of FOs from B's vs Nbtags (muons)"          ,  4, 0,    4) );
      hists.push_back( histCreator("NnotBs_BR_histo_e"              , "Number of FOs NOT from B's vs Nbtags (els)"        ,  4, 0,    4) );
      hists.push_back( histCreator("NnotBs_BR_histo_mu"             , "Number of FOs NOT from B's vs Nbtags (muons)"      ,  4, 0,    4) );
      hists.push_back( histCreator("pTrel_histo_el"                 , "pTrel (Electrons)"                                 , 15, 0,   30) );
      hists.push_back( histCreator("pTrel_histo_mu"                 , "pTrel (Muons)"                                     , 15, 0,   30) );
  }

  for (unsigned int i = 0; i < hists.size(); i++){
    hists[i]->SetDirectory(rootdir); 
    hists[i]->Sumw2(); 
  }

  //2D histos
  TH2D *pTrelvsIso_histo_mu = new TH2D("pTrelvsIso_histo_mu", "pTrel vs Iso (Muons)", 10, 0., 1., 15, 0., 30.);
  TH2D *pTrelvsIso_histo_el = new TH2D("pTrelvsIso_histo_el", "pTrel vs Iso (Electrons)", 10, 0., 1., 15, 0., 30.);
  TH2D *pTrelvsMiniIso_histo_mu = new TH2D("pTrelvsMiniIso_histo_mu", "pTrel vs MiniIso (Muons)", 10, 0., 1., 15, 0., 30.);
  TH2D *pTrelvsMiniIso_histo_el = new TH2D("pTrelvsMiniIso_histo_el", "pTrel vs MiniIso (Electrons)", 10, 0., 1., 15, 0., 30.);


  //Errors
  vector< vector<TH2D*> > Npn_histo_br_err2_pred_mu(2, vector<TH2D*>(4,0));  
  vector< vector<TH2D*> > Npn_histo_br_err2_pred_el(2, vector<TH2D*>(4,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<4;++h){
      Npn_histo_br_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_br_err2_pred_mu_br%i",h));
      Npn_histo_br_err2_pred_mu[i][h]->Reset();
      Npn_histo_br_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_br_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_br_err2_pred_el_br%i",h));
      Npn_histo_br_err2_pred_el[i][h]->Reset();
      Npn_histo_br_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_sr_err2_pred_mu(2, vector<TH2D*>(40,0));  
  vector< vector<TH2D*> > Npn_histo_sr_err2_pred_el(2, vector<TH2D*>(40,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<40;++h) {
      Npn_histo_sr_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_sr_err2_pred_mu_sr%i",h));
      Npn_histo_sr_err2_pred_mu[i][h]->Reset();
      Npn_histo_sr_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_sr_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_sr_err2_pred_el_sr%i",h));
      Npn_histo_sr_err2_pred_el[i][h]->Reset();
      Npn_histo_sr_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_HT_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_HT_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_HT_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_HT_err2_pred_mu_HT%i",h));
      Npn_histo_HT_err2_pred_mu[i][h]->Reset();
      Npn_histo_HT_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_HT_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_HT_err2_pred_el_HT%i",h));
      Npn_histo_HT_err2_pred_el[i][h]->Reset();
      Npn_histo_HT_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_MET_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_MET_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_MET_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_MET_err2_pred_mu_MET%i",h));
      Npn_histo_MET_err2_pred_mu[i][h]->Reset();
      Npn_histo_MET_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_MET_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_MET_err2_pred_el_MET%i",h));
      Npn_histo_MET_err2_pred_el[i][h]->Reset();
      Npn_histo_MET_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_MLL_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_MLL_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_MLL_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_MLL_err2_pred_mu_MLL%i",h));
      Npn_histo_MLL_err2_pred_mu[i][h]->Reset();
      Npn_histo_MLL_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_MLL_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_MLL_err2_pred_el_MLL%i",h));
      Npn_histo_MLL_err2_pred_el[i][h]->Reset();
      Npn_histo_MLL_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_MJJ_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_MJJ_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_MJJ_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_MJJ_err2_pred_mu_MJJ%i",h));
      Npn_histo_MJJ_err2_pred_mu[i][h]->Reset();
      Npn_histo_MJJ_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_MJJ_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_MJJ_err2_pred_el_MJJ%i",h));
      Npn_histo_MJJ_err2_pred_el[i][h]->Reset();
      Npn_histo_MJJ_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }
  
vector< vector<TH2D*> > Npn_histo_MTMAX_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_MTMAX_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_MTMAX_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_MTMAX_err2_pred_mu_MTMAX%i",h));
      Npn_histo_MTMAX_err2_pred_mu[i][h]->Reset();
      Npn_histo_MTMAX_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_MTMAX_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_MTMAX_err2_pred_el_MTMAX%i",h));
      Npn_histo_MTMAX_err2_pred_el[i][h]->Reset();
      Npn_histo_MTMAX_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_L1PT_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_L1PT_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_L1PT_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_L1PT_err2_pred_mu_L1PT%i",h));
      Npn_histo_L1PT_err2_pred_mu[i][h]->Reset();
      Npn_histo_L1PT_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_L1PT_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_L1PT_err2_pred_el_L1PT%i",h));
      Npn_histo_L1PT_err2_pred_el[i][h]->Reset();
      Npn_histo_L1PT_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_L2PT_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_L2PT_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_L2PT_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_L2PT_err2_pred_mu_L2PT%i",h));
      Npn_histo_L2PT_err2_pred_mu[i][h]->Reset();
      Npn_histo_L2PT_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_L2PT_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_L2PT_err2_pred_el_L2PT%i",h));
      Npn_histo_L2PT_err2_pred_el[i][h]->Reset();
      Npn_histo_L2PT_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_LTrue_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_LTrue_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_LTrue_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_LTrue_err2_pred_mu_LTrue%i",h));
      Npn_histo_LTrue_err2_pred_mu[i][h]->Reset();
      Npn_histo_LTrue_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_LTrue_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_LTrue_err2_pred_el_LTrue%i",h));
      Npn_histo_LTrue_err2_pred_el[i][h]->Reset();
      Npn_histo_LTrue_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }

  vector< vector<TH2D*> > Npn_histo_LFake_err2_pred_mu(2, vector<TH2D*>(50,0));  
  vector< vector<TH2D*> > Npn_histo_LFake_err2_pred_el(2, vector<TH2D*>(50,0));  
  for (int i=0;i<2;++i) {
    for (int h=0;h<50;++h) {
      Npn_histo_LFake_err2_pred_mu[i][h] = (TH2D*) rate_histo_mu->Clone(Form("Npn_histo_LFake_err2_pred_mu_LFake%i",h));
      Npn_histo_LFake_err2_pred_mu[i][h]->Reset();
      Npn_histo_LFake_err2_pred_mu[i][h]->SetDirectory(rootdir);
      Npn_histo_LFake_err2_pred_el[i][h] = (TH2D*) rate_histo_e->Clone(Form("Npn_histo_LFake_err2_pred_el_LFake%i",h));
      Npn_histo_LFake_err2_pred_el[i][h]->Reset();
      Npn_histo_LFake_err2_pred_el[i][h]->SetDirectory(rootdir);
    }
  }
  //----------------------
  float prompt2_gen = 0.;     //2 prompt leptons in ss pairs
  float prompt2_reco = 0.;    //2 prompt leptons in ss pairs
  float prompt1_gen = 0.;     //1 prompt leptons in ss pairs
  float prompt1_reco = 0.;    //1 prompt leptons in ss pairs
  float prompt0_gen = 0.;     //0 prompt leptons in ss pairs
  float prompt0_reco = 0.;    //0 prompt leptons in ss pairs
  float sign_misid_gen = 0.;  //number of reco ss that are gen os
  float sign_misid_reco = 0.; // =0
  float Nss_gen=0.;           //number ss events
  float Nss_reco=0.;          //number ss events
  float NpromptL1_reco=0.;    //events where lep1 is prompt
  float NpromptL1_gen=0.;     //events where lep1 is prompt
  float NpromptL2_reco=0.;    //events where lep2 is prompt
  float NpromptL2_gen=0.;     //events where lep2 is prompt
  //----------------------

  //e determination
  float Npn = 0.; //# of prompt-nonprompt tight-tight pairs
  float Npn_s = 0.; //signal contamination for # of prompt-nonprompt tight-tight pairs
  float Nnn = 0.; //# of nonprompt-nonprompt tight-tight pairs
  //float e = 0.;  //rate = Nt/Nl
  float e1 = 0.;  //rate = Nt/Nl
  float e1a = 0.;  //rate = Nt/Nl
  float e2 = 0.;  //rate = Nt/Nl
  float e2a = 0.;  //rate = Nt/Nl
  //----------------
  int counter = 0;  
  float Bs_e = 0;
  float notBs_e = 0;
  float Bs_mu = 0;
  float notBs_mu = 0;
  float Bs_mu_mia = 0;
  // Loop over events to Analyze
  unsigned int nEventsTotal = 0;
  unsigned int nEventsChain = chain->GetEntries();
  if( nEvents >= 0 ) nEventsChain = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

  // File Loop
  vector<TString> filenames;
  TString prevFilename = "";
  while ( (currentFile = (TFile*)fileIter.Next()) ) {

    
    TString fname(currentFile->GetTitle());

    // Get File Content
    TFile *file = new TFile( fname );
    TTree *tree = (TTree*)file->Get("t");
    cms3_triboson.Init(tree);

         if(fname.Contains("ttbar")) { fname = "TTBAR";  }
    else if(fname.Contains("zjets"))    { fname = "DY";     }
    else if(fname.Contains("ttw"))   { fname = "TTW";    }
    else if(fname.Contains("ttz"))   { fname = "TTZ";    }
    else if(fname.Contains("wjets")) { fname = "WJets";  }
    else if(fname.Contains("wz_3l"))  { fname = "WZ";     }
    else if(fname.Contains("data"))  { fname = "Data";   }

    if(fname != prevFilename) {
        filenames.push_back(fname);
        prevFilename = fname;
    }

    // Loop over Events in current file
    if (nEventsTotal >= nEventsChain) continue;
    unsigned int nEventsTree = tree->GetEntriesFast();
    for(unsigned int eventAG = 0; eventAG < nEventsTree; ++eventAG){

      // Get Event Content
      if(nEventsTotal >= nEventsChain) continue;
	  cms3_triboson.GetEntry(eventAG);
      ++nEventsTotal;

      //debug
      //if (triboson_np::event() != 48767071) continue;

      // Progress
      //SSAG::progress(nEventsTotal, nEventsChain);

	  if (nEventsTotal % 100000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
                printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
                fflush(stdout);
           } 
          }
      if (triboson_np::isData() ) {
          DorkyEventIdentifier id(triboson_np::run(), triboson_np::evt(), triboson_np::lumi());
          if(is_duplicate(id)) continue;
      }

      // Analysis Code
      float weight = triboson_np::isData() ? 1.0 : triboson_np::evt_scale1fb()*luminosity; // *getTruePUw_Moriond(triboson_np::trueNumInt()[0]);

      TString filename = fname;
      if( debug) cout<<__LINE__<<endl;

      // // ignore MC part of chain when looking at data, except for contamination subtraction
      // if(doData && !triboson_np::isData()) weight = 0; 

//      if( !(triboson_np::njets() >= 2 && (triboson_np::ht() > 500 ? 1 : triboson_np::met_pt() > 30) ) ) continue;
      //require triggers  doublecheck
/*      if (!doSpecial) {
          if (!triboson_np::fired_trigger()) continue;
      } else {
          if (!triboson_np::fired_trigger() && triboson_np::isData()) continue;
      }
  */  
 //   define and initialize variables here, so it's easier to switch to new ntuples 
      vector<unsigned int> ilep = tribosonsel::selectedLeps(looselep);
      if(ilep.size()!=2) continue; 
      if( debug) cout<<__LINE__<<endl;
      unsigned int lep1_index = ilep.at(0);
      unsigned int lep2_index = ilep.at(1);
      float lep1_ptrel_v1 = triboson_np::lep_ptRel().at(lep1_index);
      float lep2_ptrel_v1 = triboson_np::lep_ptRel().at(lep2_index);
      LorentzVector lep1_p4 = triboson_np::lep_p4().at(lep1_index);
      LorentzVector lep2_p4 = triboson_np::lep_p4().at(lep2_index);
      
      //Determine lep pT
      float lep1_pT_org = triboson_np::lep_p4().at(lep1_index).pt();
      float lep2_pT_org = triboson_np::lep_p4().at(lep2_index).pt();
      float lep1_pT = lep1_pT_org;
      float lep2_pT = lep2_pT_org;
      float lep1_miniIso = triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep1_index);
      float lep2_miniIso = triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep2_index);
      float lep1_iso = triboson_np::lep_relIso03EAv2().at(lep1_index);
      float lep2_iso = triboson_np::lep_relIso03EAv2().at(lep2_index);
      int   lep1_id = triboson_np::lep_pdgId().at(lep1_index);
      int   lep2_id = triboson_np::lep_pdgId().at(lep2_index);
      float lep1_ip3d = triboson_np::lep_ip3d().at(lep1_index);
      float lep2_ip3d = triboson_np::lep_ip3d().at(lep2_index);
      float lep1_ip3d_err = triboson_np::lep_ip3derr().at(lep1_index);
      float lep2_ip3d_err = triboson_np::lep_ip3derr().at(lep2_index);
      int lep1_motherID = triboson_np::lep_motherIdSS().at(lep1_index);
      int lep2_motherID = triboson_np::lep_motherIdSS().at(lep2_index);
      int ilep1 =   triboson_np::lep_genPart_index().at(lep1_index);
      int ilep2 =   triboson_np::lep_genPart_index().at(lep2_index);
      bool lep1_chargeflip(false), lep2_chargeflip(false);
      if(triboson_np::genPart_charge().size()>ilep1&&triboson_np::genPart_charge().size()>ilep2){
      bool lep1_chargeflip  =triboson_np::genPart_charge().at(ilep1)!= triboson_np::lep_charge().at(lep1_index);
      bool lep2_chargeflip  =triboson_np::genPart_charge().at(ilep2)!= triboson_np::lep_charge().at(lep2_index);
    } 
      //f((doBonly||doLightonly||doTauonly )&& (lep1_chargeflip||lep2_chargeflip))  continue;
      float jet_close_lep1 = lep1_pT_org/triboson_np::lep_ptRatio().at(lep1_index);
      float jet_close_lep2 = lep2_pT_org/triboson_np::lep_ptRatio().at(lep2_index);
      float lep1_closejetpt = jet_close_lep1;
      float lep2_closejetpt = jet_close_lep2;
      float lep1_MVA = triboson_np::lep_MVA().at(lep1_index);    
      float lep2_MVA = triboson_np::lep_MVA().at(lep2_index);    
      float lep1_etaSC = triboson_np::lep_etaSC().at(lep1_index);
      float lep2_etaSC = triboson_np::lep_etaSC().at(lep2_index);

      if( debug) cout<<__LINE__<<endl;
      if (doLowHT) {
	if (triboson_np::ht()>300.) continue;
      }
      if (doHighHT) {
	if (triboson_np::ht()<300.) continue;
      }
      bool isB(false),isC(false),isLight(false),isPhoton(false);
      //double check
      if (doBonly) {
      //consider only prompt or bs
        if (lep2_motherID!=1&&lep2_motherID!=2 && lep2_motherID!=-1) continue;
        if (lep1_motherID!=1&&lep1_motherID!=2 && lep1_motherID!=-1) continue;
      }
      else if (doConly) {
       //consider only prompt or cs
        if (lep2_motherID!=1&&lep2_motherID!=2 && lep2_motherID!=-2) continue;
        if (lep1_motherID!=1&&lep1_motherID!=2 && lep1_motherID!=-2) continue;
      }
      else if (doLightonly) {
        //consider only prompt or lights
//        if (lep2_motherID!=1 && lep2_motherID!=-4 && lep2_motherID!=0 &&  lep2_motherID!=-3) continue;
 //       if (lep1_motherID!=1 && lep1_motherID!=-4 && lep1_motherID!=0 &&  lep2_motherID!=-3) continue;
//        if (lep2_motherID!=1&&lep2_motherID!=2 && lep2_motherID!=-1 && lep2_motherID!=0 && lep2_motherID!=-2 && lep2_motherID!=-3) continue;
 //       if (lep1_motherID!=1&&lep1_motherID!=2 && lep1_motherID!=-1 && lep1_motherID!=0 && lep1_motherID!=-2 && lep1_motherID!=-3) continue;
        if (lep2_motherID!=1&&lep2_motherID!=2 && lep2_motherID!=0) continue;
        if (lep1_motherID!=1&&lep1_motherID!=2 && lep1_motherID!=0) continue;
          
    //EMEnriched starts at 20 GeV

        // if (!inSitu) {
        //     if ( (abs(lep1_id)==11 && lep1_motherID==0 && lep1_pT_org < 20) || 
        //          (abs(lep2_id)==11 && lep2_motherID==0 && lep2_pT_org < 20) ) continue;
        // }

      }
      else if(doTauonly){
   
        if (lep2_motherID!=1&&lep2_motherID!=2 && lep2_motherID!=-3) continue;
        if (lep1_motherID!=1&&lep1_motherID!=2 && lep1_motherID!=-3) continue;

      }
      //doublecheck
      //assert(fabs(lep1_ptrel_v1 - computePtRel(triboson_np::lep_p4().at(lep1_index),jet_close_lep1, true))<0.0001);
      //assert(fabs(lep2_ptrel_v1 - computePtRel(triboson_np::lep_p4().at(lep2_index),jet_close_lep2, true))<0.0001);

      if( debug) cout<<__LINE__<<endl;
//      if (fabs(triboson_np::lep_ip3d().at(lep1_index)/triboson_np::lep_ip3derr().at(lep1_index))>4.) continue;
//      if (fabs(triboson_np::lep_ip3d().at(lep2_index)/triboson_np::lep_ip3derr().at(lep2_index))>4.) continue;
      
/*      if (coneCorr){
        if (abs(lep1_id)==11){
          if (lep1_ptrel_v1>7.2) lep1_pT = lep1_pT_org*(1+std::max(0.,triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep1_index)-0.12));
          else lep1_pT = std::max(lep1_pT_org,jet_close_lep1*float(0.80));
        } 
        else {
          if (lep1_ptrel_v1>7.2) lep1_pT = lep1_pT_org*(1+std::max(0.,triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep1_index)-0.16));
          else lep1_pT = std::max(lep1_pT_org,jet_close_lep1*float(0.76));
        }

        if (abs(lep2_id)==11){
          if (lep2_ptrel_v1>7.2) lep2_pT = lep2_pT_org*(1+std::max(0.,triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep2_index)-0.12));
          else lep2_pT = std::max(lep2_pT_org,jet_close_lep2*float(0.80));
        } 
        else {
          if (lep2_ptrel_v1>7.2) lep2_pT = lep2_pT_org*(1+std::max(0.,triboson_np::lep_miniRelIsoCMS3_EAv2().at(lep2_index)-0.16));
          else lep2_pT = std::max(lep2_pT_org,jet_close_lep2*float(0.76));
        }
        //lep1_p4.pt() = lep1_pT;
  }
 */
      if (coneCorr){
        if (abs(lep1_id)==11){
          if (lep1_ptrel_v1>7.2) lep1_pT = lep1_pT_org*(1+std::max(0.,lep1_iso-coneCorrCut));
          else lep1_pT = std::max(lep1_pT_org,jet_close_lep1*float(0.80));
        } 
        else {
          if (lep1_ptrel_v1>7.2) lep1_pT = lep1_pT_org*(1+std::max(0.,lep1_iso-coneCorrCut));
          else lep1_pT = std::max(lep1_pT_org,jet_close_lep1*float(0.76));
        }

        if (abs(lep2_id)==11){
          if (lep2_ptrel_v1>7.2) lep2_pT = lep2_pT_org*(1+std::max(0.,lep2_iso-coneCorrCut));
          else lep2_pT = std::max(lep2_pT_org,jet_close_lep2*float(0.80));
        } 
        else {
          if (lep2_ptrel_v1>7.2) lep2_pT = lep2_pT_org*(1+std::max(0.,lep2_iso-coneCorrCut));
          else lep2_pT = std::max(lep2_pT_org,jet_close_lep2*float(0.76));
        }
        //lep1_p4.pt() = lep1_pT;
  }

      if (jetCorr){
        lep1_pT = jet_close_lep1;
        lep2_pT = jet_close_lep2;
      }
   
      if( debug) cout<<__LINE__<<endl;
      //doublecheck
//       assert(fabs(lep1_pT - triboson_np::lep_coneCorrPt().at(lep1_index))<0.0001);
 //      assert(fabs(lep2_pT - triboson_np::lep_coneCorrPt().at(lep2_index))<0.0001);
      bool verbose = false;
     //Determine passes ID
      bool lep1_passes_id = tribosonsel::isGoodLepton(lep1_index, "ss_VVV_cutbased_tight");
      bool lep2_passes_id = tribosonsel::isGoodLepton(lep2_index, "ss_VVV_cutbased_tight");
//      if(lep1_passes_id&&lep2_passes_id) cout<<tribosonsel::hyp_class()<<":lep1_passes_id:"<<lep1_passes_id<<":lep2_passes_id:"<<lep2_passes_id<<":lep1_motherID:" << triboson_np::lep_motherIdSS().at(lep1_index)<<":lep2_motherID:"<<triboson_np::lep_motherIdSS().at(lep2_index)<<endl;
      //doublecheck
      //if(lep1_motherID==-3||lep2_motherID==-3) continue;//skip photons
      if (verbose) {
          bool lep1prompt = lep1_motherID>0;
          bool lep2prompt = lep2_motherID>0;
          bool lep1nonprompt = lep1_motherID<=0;
          bool lep2nonprompt = lep2_motherID<=0;
          std::cout << " triboson_np::lep1_passes_id(): " << lep1_passes_id << " triboson_np::lep2_passes_id(): " << lep2_passes_id << std::endl;
          std::cout << " lep1_pT: " << lep1_pT << " lep2_pT: " << lep2_pT << std::endl;
          std::cout << " lep1prompt: " << lep1prompt << " lep2prompt: " << lep2prompt << " lep1nonprompt: " << lep1nonprompt << " lep2nonprompt: " << lep2nonprompt << std::endl;
      }

      // //do not do LL for LowHT -- I guess this was default for regular FR? so for now I will put the !inSitu part
      // if (!inSitu && lep1_pT < 25. && lep2_pT < 25.) continue;

      if(!testMVA) {
          if (triboson_np::ht()<300.) {
              //Skip if does not pass FO for isolated triggers
              if (!passIsolatedFO(lep1_id, lep1_p4.eta(), lep1_MVA, lep1_pT_org)) continue;
              if (!passIsolatedFO(lep2_id, lep2_p4.eta(), lep2_MVA, lep2_pT_org)) continue;
          } 
      } else {
          if (triboson_np::ht()<300.) { // isolated
              if(!AN_MVA(1, lep1_id, lep1_etaSC, lep1_MVA)) continue;
              if(!AN_MVA(1, lep2_id, lep2_etaSC, lep2_MVA)) continue;
          } else { // non isolated
              if(!AN_MVA(2, lep1_id, lep1_etaSC, lep1_MVA)) continue;
              if(!AN_MVA(2, lep2_id, lep2_etaSC, lep2_MVA)) continue;
          }
      }

      //Determine mtMin
      float mtmax(-999);
      if (coneCorr){
        float mtl1 = MT(lep1_pT, lep1_p4.phi(), triboson_np::met_pt(), triboson_np::met_phi());
        float mtl2 = MT(lep2_pT, lep2_p4.phi(), triboson_np::met_pt(), triboson_np::met_phi());
        mtmax = mtl1 < mtl2 ? mtl2 : mtl1;
      }

      if (lep1_pT<30.) continue;
      if (lep2_pT<30.) continue;
      float mll(-999);
      LorentzVector lep1_p4_coneCorr(lep1_pT,lep1_p4.eta(),lep1_p4.phi(),lep1_p4.energy()*lep1_pT/lep1_pT_org);    
      LorentzVector lep2_p4_coneCorr(lep2_pT,lep2_p4.eta(),lep2_p4.phi(),lep2_p4.energy()*lep2_pT/lep2_pT_org);    
      mll = (lep1_p4+lep2_p4).mass();
//      if(coneCorr)     mll = (lep1_p4_coneCorr+lep2_p4_coneCorr).mass();
      float mjj = tribosonsel::getmjj();
//      if(mll<50) cout<<mll<<":"<<(lep1_p4+lep2_p4).mass()<<endl;
      //Determine SR and BR
      if(debug)   cout<<"going to find out which region are we at"<< __LINE__<<endl;
      int br = tribosonsel::preselRegion(looselep); // 1:ss_ee, 2:ss_em,3:ss_mm,4:0SFOS, 5:1SFOS, 6:2SFOS
      if(debug)   cout<<"found which baseline selection"<< __LINE__<<endl;
      int sr = tribosonsel::signalRegion2016();
      if (br<0||br>4) continue;
      br = 1; 
      if (sr>0&&sr<4) sr =1;
      if(debug)   cout<<"event passed baseline selection"<< __LINE__<<endl;
      fillHist( "event", "hyp_class", selection.c_str(),-1 ,tribosonsel::hyp_class(), weight);
      //if (verbose) std::cout << " inSitu: " << inSitu << " br: " << br << " ac_base: " << ac_base << " tribosonsel::hyp_class(): " << tribosonsel::hyp_class() << std::endl;

      // SS Z veto -- this is to match the inSitu FR derivation macro

      //lepton pT selection
      /*doublecheck
      if(highhigh && ac_base!=HighHigh) continue;
      if(highlow  && ac_base!=HighLow ) continue;
      if(lowlow   && ac_base!=LowLow  ) continue;
      */
      //pTrel plots
      if(!triboson_np::isData()) {
        if ( (lep1_pT > 25. && lep2_pT > 25.) ){
          if( lep1_id*lep2_id > 0 ) {
            if (  (lep1_motherID<=0 && /*lep1_iso>0.1 &&*/ fabs(lep1_ip3d/lep1_ip3d_err)<4. && lep2_motherID==1)
               || (!lep1_passes_id && fabs(lep1_ip3d/lep1_ip3d_err)<4. && lep2_passes_id ) ) {
              if (abs(lep1_id)==11){
                pTrelvsIso_histo_el->Fill( std::min(lep1_iso,float(0.99)), std::min(lep1_ptrel_v1,float(29.9)) );
                pTrelvsMiniIso_histo_el->Fill( std::min(lep1_miniIso,float(0.99)), std::min(lep1_ptrel_v1,float(29.9)) );
                hists[getHist("pTrel_histo_el")]->Fill(std::min(lep1_ptrel_v1,float(29.9)) );
              } 
              else {
                pTrelvsIso_histo_mu->Fill( std::min(lep1_iso,float(0.99)), std::min(lep1_ptrel_v1,float(29.9)) );
                pTrelvsMiniIso_histo_mu->Fill( std::min(lep1_miniIso,float(0.99)), std::min(lep1_ptrel_v1,float(29.9)) );
                hists[getHist("pTrel_histo_mu")]->Fill(std::min(lep1_ptrel_v1,float(29.9)) );
              }
            }
            if (  (lep2_motherID<=0 && /*lep2_iso>0.1 &&*/ fabs(lep2_ip3d/lep2_ip3d_err)<4. && lep1_motherID==1) 
               || (lep1_passes_id && fabs(lep2_ip3d/lep2_ip3d_err)<4. && !lep2_passes_id ) ) {
              if (abs(lep2_id)==11) {
                pTrelvsIso_histo_el->Fill( std::min(lep2_iso,float(0.99)), std::min(lep2_ptrel_v1,float(29.9)) );
                pTrelvsMiniIso_histo_el->Fill( std::min(lep2_miniIso,float(0.99)), std::min(lep2_ptrel_v1,float(29.9)) );
                hists[getHist("pTrel_histo_el")]->Fill(std::min(lep2_ptrel_v1,float(29.9)) );
              } 
              else {
                pTrelvsIso_histo_mu->Fill( std::min(lep2_iso,float(0.99)), std::min(lep2_ptrel_v1,float(29.9)) );
                pTrelvsMiniIso_histo_mu->Fill( std::min(lep2_miniIso,float(0.99)), std::min(lep2_ptrel_v1,float(29.9)) );
                hists[getHist("pTrel_histo_mu")]->Fill(std::min(lep2_ptrel_v1,float(29.9)) );
              }
            }
          }
        }
      }

      //////////////////////////////////////////////////////////////////////////////////////////
      //                         RECO SAME SIGN PAIRS                                         // 
      //////////////////////////////////////////////////////////////////////////////////////////
      // if we're doing data, we want to only fill prompt-nonprompt prediction (class 2) with data
      // and leave all MC in class 3 observations (if they have truth fakes)

      // doublecheck
          //bool isLep1Prompt =  triboson_np::lep_isFromW().at(lep1_index);
          //bool isLep2Prompt =  triboson_np::lep_isFromW().at(lep2_index);
          bool isLep1Prompt = lep1_motherID > 0 && !lep1_chargeflip;// && (triboson_np::lep_isFromW().at(lep1_index) || triboson_np::lep_isFromZ().at(lep1_index));
          bool isLep2Prompt = lep2_motherID > 0 && !lep2_chargeflip;//  && (triboson_np::lep_isFromW().at(lep2_index) || triboson_np::lep_isFromZ().at(lep2_index));
          bool isLep1NonPrompt = lep1_motherID<=0;
          bool isLep2NonPrompt = lep2_motherID<=0;
        //Counters
       if (!triboson_np::isData() && tribosonsel::hyp_class() == 3) {
          counter++;
          Nss_reco = Nss_reco + weight;

        if( isLep1Prompt && isLep2Prompt ){
          prompt2_reco = prompt2_reco + weight;
          NpromptL1_reco = NpromptL1_reco + weight;
          NpromptL2_reco = NpromptL2_reco + weight;
        }
        else if ( lep1_chargeflip || lep2_chargeflip ) sign_misid_reco += weight; 

        //1) Lep 2 is non-prompt
        else if( isLep1Prompt && isLep2NonPrompt ){ 

          prompt1_reco += weight;  
          NpromptL1_reco += weight;  
          if(sr > 0) hists[getHist("Npn_histo_sr_obs"+fname)   ]->Fill(sr, weight);
          hists[getHist("Npn_histo_br_obs"+fname)   ]->Fill(br, weight);
          hists[getHist("Npn_histo_HT_obs"+fname)   ]->Fill(triboson_np::ht(), weight);
          hists[getHist("Npn_histo_MET_obs"+fname)  ]->Fill(triboson_np::met_pt(), weight);
          hists[getHist("Npn_histo_MLL_obs"+fname)  ]->Fill(mll, weight);
          hists[getHist("Npn_histo_MJJ_obs"+fname)  ]->Fill(mjj, weight);
          hists[getHist("Npn_histo_MTMAX_obs"+fname)]->Fill(mtmax, weight);
          hists[getHist("Npn_histo_L1PT_obs"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
          hists[getHist("Npn_histo_L2PT_obs"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);
          hists[getHist("Npn_histo_LTrue_obs"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
          hists[getHist("Npn_histo_LFake_obs"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);

          if(abs(lep2_id) == 11){
            if(sr > 0) hists[getHist("Npn_histo_sr_obs_el"+fname)   ]->Fill(sr, weight);
            hists[getHist("Npn_histo_br_obs_el"+fname)   ]->Fill(br, weight);
            hists[getHist("Npn_histo_HT_obs_el"+fname)   ]->Fill(triboson_np::ht(), weight);
            hists[getHist("Npn_histo_MET_obs_el"+fname)  ]->Fill(triboson_np::met_pt(), weight);
            hists[getHist("Npn_histo_MTMAX_obs_el"+fname)]->Fill(mtmax, weight);
            hists[getHist("Npn_histo_MLL_obs_el"+fname)]->Fill(mll, weight);
            hists[getHist("Npn_histo_MJJ_obs_el"+fname)]->Fill(mjj, weight);
            hists[getHist("Npn_histo_L1PT_obs_el"+fname) ]->Fill(coneCorr ? lep1_pT :lep1_pT_org ,weight);
            hists[getHist("Npn_histo_L2PT_obs_el"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org,weight);
            hists[getHist("Npn_histo_LTrue_obs_el"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org,weight);
            hists[getHist("Npn_histo_LFake_obs_el"+fname) ]->Fill(coneCorr ? lep2_pT :lep2_pT_org ,weight);
            // hists[getHist("Npn_histo_LFake_obs_el_rebin"+fname) ]->Fill(min(coneCorr ? lep2_pT : lep2_pT_org,69.F), weight);
            addToCounter(filename+Form("_obs_el_BR%i", br), weight);
            if (fabs(lep2_p4.eta()) < 0.8 && lep2_pT >= 70) addToCounter(filename+"_obs_el_pteta2", 1);
          } 
          else if(abs(lep2_id) == 13){
            if(sr > 0) hists[getHist("Npn_histo_sr_obs_mu"+fname)   ]->Fill(sr, weight);
            hists[getHist("Npn_histo_br_obs_mu"+fname)   ]->Fill(br, weight);
            hists[getHist("Npn_histo_HT_obs_mu"+fname)   ]->Fill(triboson_np::ht(), weight);
            hists[getHist("Npn_histo_MET_obs_mu"+fname)  ]->Fill(triboson_np::met_pt(), weight);
            hists[getHist("Npn_histo_MTMAX_obs_mu"+fname)]->Fill(mtmax, weight);
            hists[getHist("Npn_histo_MLL_obs_mu"+fname)]->Fill(mll, weight);
            hists[getHist("Npn_histo_MJJ_obs_mu"+fname)]->Fill(mjj, weight);
            hists[getHist("Npn_histo_L1PT_obs_mu"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org,weight);
            hists[getHist("Npn_histo_L2PT_obs_mu"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);
            hists[getHist("Npn_histo_LTrue_obs_mu"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
            hists[getHist("Npn_histo_LFake_obs_mu"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);

            addToCounter(filename+Form("_obs_mu_BR%i", br), weight);
            if (fabs(lep2_p4.eta()) < 1.2 && lep2_pT >= 50) {
                addToCounter(filename+"_obs_mu_pteta2", 1);
                // addToCounter(Form("%i:%llu",triboson_np::lumi(), triboson_np::event()));
            }
          }
        }
        //2) Lep 1 is non-prompt
        else if( isLep1NonPrompt && isLep2Prompt ){ 

          prompt1_reco += weight;
          NpromptL2_reco += weight;

          if(sr > 0) hists[getHist("Npn_histo_sr_obs"+fname)]   ->Fill(sr, weight);
          hists[getHist("Npn_histo_br_obs"+fname)]   ->Fill(br, weight);
          hists[getHist("Npn_histo_HT_obs"+fname)]   ->Fill(triboson_np::ht(), weight);
          hists[getHist("Npn_histo_MET_obs"+fname)]  ->Fill(triboson_np::met_pt(), weight);
          hists[getHist("Npn_histo_MTMAX_obs"+fname)]->Fill(mtmax, weight);
          hists[getHist("Npn_histo_MLL_obs"+fname)]->Fill(mll, weight);
          hists[getHist("Npn_histo_MJJ_obs"+fname)]->Fill(mjj, weight);
          hists[getHist("Npn_histo_L1PT_obs"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org,weight);
          hists[getHist("Npn_histo_L2PT_obs"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org,weight);
          hists[getHist("Npn_histo_LFake_obs"+fname) ]->Fill(coneCorr ? lep1_pT :lep1_pT_org, weight);
          hists[getHist("Npn_histo_LTrue_obs"+fname) ]->Fill(coneCorr ? lep2_pT :lep2_pT_org, weight);
          
          if(abs(lep1_id) == 11){

            if(sr > 0) hists[getHist("Npn_histo_sr_obs_el"+fname)]   ->Fill(sr, weight);
            hists[getHist("Npn_histo_br_obs_el"+fname)]   ->Fill(br, weight);
            hists[getHist("Npn_histo_HT_obs_el"+fname)]   ->Fill(triboson_np::ht(), weight);
            hists[getHist("Npn_histo_MET_obs_el"+fname)]  ->Fill(triboson_np::met_pt(), weight);
            hists[getHist("Npn_histo_MTMAX_obs_el"+fname)]->Fill(mtmax, weight);
            hists[getHist("Npn_histo_MLL_obs_el"+fname)]->Fill(mll, weight);
            hists[getHist("Npn_histo_MJJ_obs_el"+fname)]->Fill(mjj, weight);
            hists[getHist("Npn_histo_L1PT_obs_el"+fname)] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
            hists[getHist("Npn_histo_L2PT_obs_el"+fname)] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);
            hists[getHist("Npn_histo_LFake_obs_el"+fname) ]->Fill(coneCorr ? lep1_pT :lep1_pT_org , weight);
            hists[getHist("Npn_histo_LTrue_obs_el"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);
            
            addToCounter(filename+Form("_obs_el_BR%i", br), weight);
            if (fabs(lep1_p4.eta()) < 0.8 && lep1_pT >= 70) {
                addToCounter(filename+"_obs_el_pteta1", 1);
                // addToCounter(Form("%i:%llu",triboson_np::lumi(), triboson_np::event()));
            }

          } 
          else if(abs(lep1_id) == 13){
            if(sr > 0) hists[getHist("Npn_histo_sr_obs_mu"+fname)]   ->Fill(sr, weight);
            hists[getHist("Npn_histo_br_obs_mu"+fname)]   ->Fill(br, weight);
            hists[getHist("Npn_histo_HT_obs_mu"+fname)]   ->Fill(triboson_np::ht(), weight);
            hists[getHist("Npn_histo_MET_obs_mu"+fname)]  ->Fill(triboson_np::met_pt(), weight);
            hists[getHist("Npn_histo_MTMAX_obs_mu"+fname)]->Fill(mtmax, weight);
            hists[getHist("Npn_histo_MLL_obs_mu"+fname)]->Fill(mll, weight);
            hists[getHist("Npn_histo_MJJ_obs_mu"+fname)]->Fill(mjj, weight);
            hists[getHist("Npn_histo_L1PT_obs_mu"+fname)] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
            hists[getHist("Npn_histo_L2PT_obs_mu"+fname)] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);
            hists[getHist("Npn_histo_LFake_obs_mu"+fname) ]->Fill(coneCorr ? lep1_pT : lep1_pT_org, weight);
            hists[getHist("Npn_histo_LTrue_obs_mu"+fname) ]->Fill(coneCorr ? lep2_pT : lep2_pT_org, weight);

            addToCounter(filename+Form("_obs_mu_BR%i", br), weight);
            if (fabs(lep1_p4.eta()) < 1.2 && lep1_pT >= 50) addToCounter(filename+"_obs_mu_pteta1", 1);
          }
        }

        //Both are non-prompt
        else if( isLep1NonPrompt && isLep2NonPrompt ) prompt0_reco += weight;

        //check for charge misID on gen level.
//        if (lep1_motherID==2 || lep2_motherID==2) sign_misid_gen += weight;
        if (lep1_chargeflip || lep2_chargeflip) sign_misid_gen += weight;

        else {
          Nss_gen += weight;
          if( isLep1Prompt && isLep2Prompt ){
            prompt2_gen += weight;
            NpromptL1_gen += weight;
            NpromptL2_gen += weight;
          }
          else if( isLep1Prompt && lep2_motherID<=0 ){
            prompt1_gen += weight;
            NpromptL1_gen += weight;
          }
          else if( lep1_motherID<=0 && isLep2Prompt ){
            prompt1_gen += weight;
            NpromptL2_gen += weight;
          }
          else if( (lep1_motherID<=0&& lep2_motherID<=0) ) prompt0_gen += weight;
        }
      }
      
      // Contamination subtraction: Subtract prompt-prompt MC 
      // (which ends up as class 2 instead of 3) from data prediction by assigning negative weight
      bool subtractContamination = false;
      float mult = 1.0;
      if(doData && doSubtractContamination && !triboson_np::isData() && tribosonsel::hyp_class() == 2 && lep1_motherID>0 && lep2_motherID>0) {
        mult = -1.0; // invert weight to subtract from the prediction
        subtractContamination = true;
        filename = "Data"; // when filling counter below, want it to think we are filling in negative data
      }

      //////////////////////////////////////////////////////////////////////////////////////////
      //                         SINGLE FAKES                                                 // 
      //////////////////////////////////////////////////////////////////////////////////////////

      e1 = 0.; //rate for lep1
      e2 = 0.; //rate for lep2
      float w = 0.;
      
      //prompt-nonprompt background
      // if we're doing data, we want to only fill prompt-nonprompt prediction (class 2) with data
      // and leave all MC in class 3 observations (if they have truth fakes)
      if( ( doData && (triboson_np::isData() && (tribosonsel::hyp_class() == 2 || inSitu)) ) || // if doing data, only fill pred with data
          (!doData && (tribosonsel::hyp_class() == 2 || inSitu) ) || // if not doing data, fill pred with MC (old behaviour)
          (doData && subtractContamination && !triboson_np::isData()) ) { // do contamination subtraction if doData and MC
        int nbjets = triboson_np::nBJetLoose();
        if (nbjets > 3) nbjets = 3; 

        //0) InSituFR variables
        float ptrel_cut_1    = (abs(lep1_id) == 11 ? 7.20 : 7.20);
        float ptrel_cut_2    = (abs(lep2_id) == 11 ? 7.20 : 7.20);
        float ptratio_cut_1  = (abs(lep1_id) == 11 ? 0.80 : 0.76);
        float ptratio_cut_2  = (abs(lep2_id) == 11 ? 0.80 : 0.76);
        float mini_cut_1     = (abs(lep1_id) == 11 ? 0.12 : 0.16);
        float mini_cut_2     = (abs(lep2_id) == 11 ? 0.12 : 0.16);
        //doublecheck  denominator isolation definition
        bool lep1_denom_iso  = ((lep1_miniIso < 0.4));
        bool lep2_denom_iso  = ((lep2_miniIso < 0.4));
      //bool lep1_denom_iso  = ((lep1_miniIso < 0.4) && ((lep1_ptrel_v1 > ptrel_cut_1) || ((triboson_np::lep1_closeJet().pt()/lep1_pT_org) < (1.0/ptratio_cut_1 + lep1_miniIso))));
      //bool lep2_denom_iso  = ((lep2_miniIso < 0.4) && ((lep2_ptrel_v1 > ptrel_cut_2) || ((triboson_np::lep2_closeJet().pt()/lep2_pT_org) < (1.0/ptratio_cut_2 + lep2_miniIso))));

      // for new ntuples, we must re-compute the IDs (and apply MVA manually) because I have taken out the tight MVA at the babymaking level
      bool inSituFR_id_lep1 = true;
      bool inSituFR_id_lep2 = true;
      //doublecheck, not sure if we need all these
/*      if(abs(lep1_id) == 11) inSituFR_id_lep1 = fabs(lep1_etaSC)<2.5 &&  triboson_np::lep1_el_conv_vtx_flag() == 1 &&  triboson_np::lep1_el_threeChargeAgree() == 1 &&  triboson_np::lep1_el_exp_innerlayers() == 1 &&  triboson_np::lep1_dZ() < 0.1;
      else inSituFR_id_lep1 =  triboson_np::lep1_dZ() < 0.1 && triboson_np::lep1_mu_ptErr() && triboson_np::lep1_mediumMuonPOG() &&  fabs(lep1_p4.eta()) < 2.4;
      if(abs(lep2_id) == 11) inSituFR_id_lep2 = fabs(lep2_etaSC)<2.5 &&  triboson_np::lep2_el_conv_vtx_flag() == 1 &&  triboson_np::lep2_el_threeChargeAgree() == 1 &&  triboson_np::lep2_el_exp_innerlayers() == 1 &&  triboson_np::lep2_dZ() < 0.1;
      else inSituFR_id_lep2 =  triboson_np::lep2_dZ() < 0.1 && triboson_np::lep2_mu_ptErr() && triboson_np::lep2_mediumMuonPOG() &&  fabs(lep2_p4.eta()) < 2.4;

      if(!testMVA) {
          inSituFR_id_lep1 = inSituFR_id_lep1 && passesNumeratorMVA(lep1_id, lep1_etaSC, lep1_MVA, lep1_pT_org);
          inSituFR_id_lep2 = inSituFR_id_lep2 && passesNumeratorMVA(lep2_id, lep2_etaSC, lep2_MVA, lep2_pT_org);
      }
          // if (inSitu && (!triboson_np::passed_id_inSituFR_lep1() || !triboson_np::passed_id_inSituFR_lep2())) continue;
          if (inSitu && (!inSituFR_id_lep1 || !inSituFR_id_lep2)) continue; // recomputed versions of variables above
          // if (inSitu && (!triboson_np::lep1_isTrigSafeNoIsov1() || !triboson_np::lep2_isTrigSafeNoIsov1())) continue;
      */
        //1) Lep1 is tight, lep2 is loose!tight
        if (lep1_passes_id && !lep2_passes_id){
          //Baseline selections
          if (!inSitu && (tribosonsel::hyp_class() != 2)) continue;
           //doublecheck
           // if (inSitu && (triboson_np::lep2_multiIso() || !isFakeLeg(2, doData) || !isGoodLeg(1, doData) || !lep2_denom_iso)) continue;

          if (usePtRatioCor){
            //this is a tighter FO than default, so skip if it does not pass
            if ( abs(lep2_id)==11 ){
              float ptratiocor = lep2_closejetpt>0. ? lep2_pT_org*(1+std::max(0.,lep2_iso-coneCorrCut))/lep2_closejetpt : 1.;
              if (!(ptratiocor > 0.70 || lep2_ptrel_v1 > 7.0)) continue;
            } 
            else {
              float ptratiocor = lep2_closejetpt>0. ? lep2_pT_org*(1+std::max(0.,lep2_iso-coneCorrCut))/lep2_closejetpt : 1.;
              if (!(ptratiocor > 0.68 || lep2_ptrel_v1 > 6.7)) continue;
            }
          }

          if (abs(lep2_id) == 11){  
            e2 = getFakeRate(11, lep2_pT, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData, inSitu, TString(looselep));
            e2a = getFakeRate2(11, lep2_pT_org, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData); 
            w = coneCorr ? (e2/(1-e2))*weight : (e2a/(1-e2a))*weight;
           //cout<< e2/(1-e2)<<endl;
           //w = weight;
           
           if(weightOne) w = 1.0;
           if(subtractContamination) w = mult*weight;

            addToCounter(filename+Form("_pred_el_BR%i", br), w);
            if (fabs(lep2_p4.eta()) < 0.8 && lep2_pT >= 70) addToCounter(filename+"_pred_el_pteta2", w);
            if (fabs(lep2_p4.eta()) < 0.8 && lep2_pT >= 70) addToCounter(filename+"_prednotf_el_pteta2", 1);

            if(sr >= 0) hists[getHist("Npn_histo_sr_pred_el")]   ->Fill(sr, w);
            hists[getHist("Npn_histo_br_pred_el")]   ->Fill(br, w);
            hists[getHist("Npn_histo_HT_pred_el")]   ->Fill(triboson_np::ht(), w);
            hists[getHist("Npn_histo_MET_pred_el")]  ->Fill(triboson_np::met_pt(), w);
          //  hists[getHist("Npn_histo_MTMAX_pred_el")]->Fill(mtmax, w);
             hists[getHist("Npn_histo_MLL_pred_el")]->Fill(mll, w);
             hists[getHist("Npn_histo_MJJ_pred_el")]->Fill(mjj, w);
            hists[getHist("Npn_histo_L1PT_pred_el")] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            hists[getHist("Npn_histo_L2PT_pred_el")] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            hists[getHist("Npn_histo_LTrue_pred_el")] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            if(isFakeLeg(2)) hists[getHist("Npn_histo_LFake_pred_el")] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            // if(isFakeLeg(2)) hists[getHist("Npn_histo_LFake_pred_el_rebin")] ->Fill(min(coneCorr ? lep2_pT : lep2_pT_org,69.F), w);
            if (sr>=0) Npn_histo_sr_err2_pred_el[(triboson_np::ht() > 300)][sr-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_br_err2_pred_el[triboson_np::ht() > 300][br]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_HT_err2_pred_el[(triboson_np::ht() > 300)][hists[getHist("Npn_histo_HT_pred_el")]->FindBin(triboson_np::ht())-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_MET_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_MET_pred_el")]->FindBin(triboson_np::met_pt())-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_L1PT_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_L1PT_pred_el")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_L2PT_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_L2PT_pred_el")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_LTrue_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_LTrue_pred_el")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_LFake_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_LFake_pred_el")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            // fill el abundance histos here w/ nbtags
            if(lep2_motherID == -1) hists[getHist("NBs_BR_histo_e")]->Fill(nbjets, w);
            if(lep2_motherID == -2 || lep2_motherID == 0) hists[getHist("NnotBs_BR_histo_e")]->Fill(nbjets, w);
            if(lep2_motherID == -1) Bs_e = Bs_e + mult*weight;
            if(lep2_motherID == -2 || lep2_motherID == 0) notBs_e = notBs_e + mult*weight;
          }
          else if (abs(lep2_id) == 13){ 
            e2 = getFakeRate(13, lep2_pT, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData, inSitu, TString(looselep));
            e2a = getFakeRate2(13, lep2_pT_org, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData); 
            w = coneCorr ? (e2/(1-e2))*weight : (e2a/(1-e2a))*weight;
            if(weightOne) w = 1.0;
            if(subtractContamination) w = mult*weight;

            addToCounter(filename+Form("_pred_mu_BR%i", br), w);
            if (fabs(lep2_p4.eta()) < 1.2 && lep2_pT >= 50) addToCounter(filename+"_pred_mu_pteta2", w);
            if (fabs(lep2_p4.eta()) < 1.2 && lep2_pT >= 50) addToCounter(filename+"_prednotf_mu_pteta2", 1);

//            hists[getHist("Npn_histo_br_pred_mu")]->Fill(br, weight);
            fillHist( "event", "fakerate_weight", selection.c_str(),lep2_id,e2/(1-e2), 1);
//            fillHist("event","Npn_histo_LFakeiso_pred_mu",selection.c_str(),)
            if(sr > 0) hists[getHist("Npn_histo_sr_pred_mu")]->Fill(sr, w);
            hists[getHist("Npn_histo_br_pred_mu")]->Fill(br, w);
            hists[getHist("Npn_histo_HT_pred_mu")]->Fill(triboson_np::ht(), w);
            hists[getHist("Npn_histo_MET_pred_mu")]->Fill(triboson_np::met_pt(), w);
            hists[getHist("Npn_histo_MTMAX_pred_mu")]->Fill(mtmax, w);
            hists[getHist("Npn_histo_MLL_pred_mu")]->Fill(mll, w);
            hists[getHist("Npn_histo_MJJ_pred_mu")]->Fill(mjj, w);
            hists[getHist("Npn_histo_L1PT_pred_mu")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            hists[getHist("Npn_histo_L2PT_pred_mu")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            hists[getHist("Npn_histo_LTrue_pred_mu")] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            if(isFakeLeg(2)) hists[getHist("Npn_histo_LFake_pred_mu")] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            if (sr>0) Npn_histo_sr_err2_pred_mu[(triboson_np::ht() > 300)][sr-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
          //  Npn_histo_br_err2_pred_mu[triboson_np::ht() > 300][br]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_HT_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_HT_pred_mu")]->FindBin(triboson_np::ht())-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_MET_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_MET_pred_mu")]->FindBin(triboson_np::met_pt())-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_L1PT_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_L1PT_pred_mu")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_L2PT_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_L2PT_pred_mu")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_LTrue_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_LTrue_pred_mu")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            Npn_histo_LFake_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_LFake_pred_mu")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep2_pT, fabs(lep2_p4.eta()), w);
            if(lep2_motherID == -1) hists[getHist("NBs_BR_histo_mu")]->Fill(nbjets, mult*weight); //LOOSE!TIGHT, not LOOSE LIKE IN MEAS REGION
            if(lep2_motherID == -2 || lep2_motherID == 0) hists[getHist("NnotBs_BR_histo_mu")]->Fill(nbjets, w);
            if(lep2_motherID == -1) Bs_mu = Bs_mu + mult*weight;
            if(lep2_motherID == -2 || lep2_motherID == 0) notBs_mu = notBs_mu + mult*weight;
          }
          Npn = Npn + w;
          if (isLep2Prompt) Npn_s = Npn_s + w;
          if(sr > 0) hists[getHist("Npn_histo_sr_pred")]->Fill(sr, w);
          hists[getHist("Npn_histo_br_pred")]->Fill(br, w);
          hists[getHist("Npn_histo_HT_pred")]->Fill(triboson_np::ht(), w);
          hists[getHist("Npn_histo_MET_pred")]->Fill(triboson_np::met_pt(), w);
          hists[getHist("Npn_histo_MTMAX_pred")]->Fill(mtmax, w);
          hists[getHist("Npn_histo_MLL_pred")]->Fill(mll, w);
          hists[getHist("Npn_histo_MJJ_pred")]->Fill(mjj, w);
          hists[getHist("Npn_histo_L1PT_pred")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
          hists[getHist("Npn_histo_L2PT_pred")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
          hists[getHist("Npn_histo_LTrue_pred")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
          if(isFakeLeg(2)) hists[getHist("Npn_histo_LFake_pred")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
        }

        //2) Lep1 is loose!tight, lep2 is tight
        if (!lep1_passes_id && lep2_passes_id){
          //Baseline selections
          if (!inSitu && triboson_np::hyp_type() != 2) continue;
          //doublecheck
          //if (inSitu && (triboson_np::lep1_multiIso() || !isFakeLeg(1, doData) || !isGoodLeg(2, doData) || !lep1_denom_iso)) continue;
          //if(doData && !triboson_np::isData() && isGoodLeg(1)) weight = -triboson_np::scale1fb(); 
          //else weight = 0;

          if (usePtRatioCor){
            if ( abs(lep1_id)==11 ){
              float ptratiocor = lep1_closejetpt>0. ? lep1_pT_org*(1+std::max(0.,lep1_iso-0.06))/lep1_closejetpt : 1.;
              if (!(ptratiocor > 0.70 || lep1_ptrel_v1 > 7.0)) continue;
            } 
            else {
              float ptratiocor = lep1_closejetpt>0. ? lep1_pT_org*(1+std::max(0.,lep1_iso-0.06))/lep1_closejetpt : 1.;
              if (!(ptratiocor > 0.68 || lep1_ptrel_v1 > 6.7)) continue;
            }
          }
          if( abs(lep1_id) == 11 ){	//if el, use el rate.  FILL WITH NONPROMPT			  
            e1 = getFakeRate(11, lep1_pT, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData, inSitu );
            e1a = getFakeRate2(11, lep1_pT_org, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData); 
            w = coneCorr ? (e1/(1-e1))*weight : (e1a/(1-e1a))*weight;
            //w = weight;
            if(weightOne) w = 1.0;
            if(subtractContamination) w = mult*weight;
            addToCounter(filename+Form("_pred_el_BR%i", br), w);
            if (fabs(lep1_p4.eta()) < 0.8 && lep1_pT >= 70) addToCounter(filename+"_pred_el_pteta1", w);
            if (fabs(lep1_p4.eta()) < 0.8 && lep1_pT >= 70) addToCounter(filename+"_prednotf_el_pteta1", 1);

            if(sr > 0) hists[getHist("Npn_histo_sr_pred_el")]   ->Fill(sr, w);
            hists[getHist("Npn_histo_br_pred_el")]   ->Fill(br, w);
            hists[getHist("Npn_histo_HT_pred_el")]   ->Fill(triboson_np::ht(), w);
            hists[getHist("Npn_histo_MET_pred_el")]  ->Fill(triboson_np::met_pt(), w);
            hists[getHist("Npn_histo_MTMAX_pred_el")]->Fill(mtmax, w);
            hists[getHist("Npn_histo_MLL_pred_el")]->Fill(mll, w);
            hists[getHist("Npn_histo_MJJ_pred_el")]->Fill(mjj, w);
            hists[getHist("Npn_histo_L1PT_pred_el")] ->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            hists[getHist("Npn_histo_L2PT_pred_el")] ->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            if(isFakeLeg(1)) hists[getHist("Npn_histo_LFake_pred_el")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            // if(isFakeLeg(1)) hists[getHist("Npn_histo_LFake_pred_el_rebin")]->Fill(min(coneCorr ? lep1_pT : lep1_pT_org,69.F), w);
            hists[getHist("Npn_histo_LTrue_pred_el")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);

            if (sr>=0) Npn_histo_sr_err2_pred_el[(triboson_np::ht() > 300)][sr-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
          //  Npn_histo_br_err2_pred_el[triboson_np::ht() > 300][br]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_HT_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_HT_pred_el")]->FindBin(triboson_np::ht())-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_MET_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_MET_pred_el")]->FindBin(triboson_np::met_pt())-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_L1PT_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_L1PT_pred_el")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_L2PT_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_L2PT_pred_el")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);

            Npn_histo_LFake_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_LFake_pred_el")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_LTrue_err2_pred_el[triboson_np::ht() > 300][hists[getHist("Npn_histo_LTrue_pred_el")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            // fill el abundance histos here w/ nbtags
            if(lep1_motherID == -1) hists[getHist("NBs_BR_histo_e")]->Fill(nbjets, mult*weight); //LOOSE!TIGHT, not LOOSE LIKE IN MEAS REGION
            if(lep1_motherID == -2 || lep1_motherID == 0) hists[getHist("NnotBs_BR_histo_e")]->Fill(nbjets, w);
            if(lep1_motherID == -1) Bs_e = Bs_e + mult*weight;
            if(lep1_motherID == -2 || lep1_motherID == 0) notBs_e = notBs_e + mult*weight;
          }
          else if( abs(lep1_id) == 13 ){ //if mu, use mu rate.  FILL WITH NONPROMPT				  
            e1 = getFakeRate(13, lep1_pT, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData, inSitu );
            e1a = getFakeRate2(13, lep1_pT_org, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData); 
            w = coneCorr ? (e1/(1-e1))*weight : (e1a/(1-e1a))*weight;
            //w = weight;
            if(weightOne) w = 1.0;
            if(subtractContamination) w = mult*weight;

            addToCounter(filename+Form("_pred_mu_BR%i", br), w);
            if (fabs(lep1_p4.eta()) < 1.2 && lep1_pT >= 50) addToCounter(filename+"_pred_mu_pteta1", w);
            if (fabs(lep1_p4.eta()) < 1.2 && lep1_pT >= 50) addToCounter(filename+"_prednotf_mu_pteta1", 1);

            fillHist( "event", "fakerate_weight", selection.c_str(),lep1_id, e2/(1-e2), 1);
            if(sr > 0) hists[getHist("Npn_histo_sr_pred_mu")]->Fill(sr, w);
            hists[getHist("Npn_histo_br_pred_mu")]->Fill(br, w);
            hists[getHist("Npn_histo_HT_pred_mu")]->Fill(triboson_np::ht(), w);
            hists[getHist("Npn_histo_MET_pred_mu")]->Fill(triboson_np::met_pt(), w);
            hists[getHist("Npn_histo_MTMAX_pred_mu")]->Fill(mtmax, w);
            hists[getHist("Npn_histo_MLL_pred_mu")]->Fill(mll, w);
            hists[getHist("Npn_histo_MJJ_pred_mu")]->Fill(mjj, w);
            hists[getHist("Npn_histo_L1PT_pred_mu")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            hists[getHist("Npn_histo_L2PT_pred_mu")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
            if(isFakeLeg(1)) hists[getHist("Npn_histo_LFake_pred_mu")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
            hists[getHist("Npn_histo_LTrue_pred_mu")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);

            if (sr>=0) Npn_histo_sr_err2_pred_mu[(triboson_np::ht() > 300)][sr-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
          //  Npn_histo_br_err2_pred_mu[triboson_np::ht() > 300][br]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_HT_err2_pred_mu[(triboson_np::ht() > 300)][hists[getHist("Npn_histo_HT_pred_mu")]->FindBin(triboson_np::ht())-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_MET_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_MET_pred_mu")]->FindBin(triboson_np::met_pt())-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_L1PT_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_L1PT_pred_mu")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_L2PT_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_L2PT_pred_mu")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_LFake_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_LFake_pred_mu")]->FindBin(coneCorr ? lep1_pT : lep1_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            Npn_histo_LTrue_err2_pred_mu[triboson_np::ht() > 300][hists[getHist("Npn_histo_LTrue_pred_mu")]->FindBin(coneCorr ? lep2_pT : lep2_pT_org)-1]->Fill(lep1_pT, fabs(lep1_p4.eta()), w);
            // fill el abundance histos here w/ nbtags
            if(lep1_motherID == -1) hists[getHist("NBs_BR_histo_mu")]->Fill(nbjets, mult*weight); //LOOSE!TIGHT, not LOOSE LIKE IN MEAS REGION
            if(lep1_motherID == -2 || lep1_motherID == 0) hists[getHist("NnotBs_BR_histo_mu")]->Fill(nbjets, w);
            if(lep1_motherID == -1) Bs_mu = Bs_mu + mult*weight;
            if(lep1_motherID == -2 || lep1_motherID == 0) notBs_mu = notBs_mu + mult*weight;
          }
          Npn = Npn + w;
          if (lep1_motherID>0) Npn_s = Npn_s + w;
          if(sr > 0) hists[getHist("Npn_histo_sr_pred")]->Fill(sr, w);
          hists[getHist("Npn_histo_br_pred")]->Fill(br, w);
          hists[getHist("Npn_histo_HT_pred")]->Fill(triboson_np::ht(), w);
          hists[getHist("Npn_histo_MET_pred")]->Fill(triboson_np::met_pt(), w);
          hists[getHist("Npn_histo_MTMAX_pred")]->Fill(mtmax, w);
          hists[getHist("Npn_histo_MLL_pred")]->Fill(mll, w);
          hists[getHist("Npn_histo_MJJ_pred")]->Fill(mjj, w);
          hists[getHist("Npn_histo_L1PT_pred")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
          hists[getHist("Npn_histo_L2PT_pred")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
          if(isFakeLeg(1)) hists[getHist("Npn_histo_LFake_pred")]->Fill(coneCorr ? lep1_pT : lep1_pT_org, w);
          hists[getHist("Npn_histo_LTrue_pred")]->Fill(coneCorr ? lep2_pT : lep2_pT_org, w);
        }
      } //end hyp = 2 if statement
      
      // // resume ignoring MC part of chain when looking at data, except for contamination subtraction
      // if(doData && !triboson_np::isData()) weight = 0; 

      //nonprompt-nonprompt background
      else if(tribosonsel::hyp_class() == 1){
        if( lep1_id*lep2_id > 0 ){
          if( abs(lep2_id) == 11 ) e2 = getFakeRate(11, lep2_pT, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData, inSitu );
          else if( abs(lep2_id) == 13 ) e2 = getFakeRate(13, lep2_pT, fabs(lep2_p4.eta()), triboson_np::ht(), false, doData, inSitu );
          if( abs(lep1_id) == 11)      e1 = getFakeRate(11, lep1_pT, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData, inSitu );
          else if( abs(lep1_id) == 13) e1 = getFakeRate(13, lep1_pT, fabs(lep1_p4.eta()), triboson_np::ht(), false, doData, inSitu );
          Nnn = Nnn + w*weight;
        }
      } //end hyp = 1 if statement

    }//end event loop

    // Clean Up
    delete tree;
    file->Close();
    delete file;

  }//file loop

  cout<<"\n"<<"Hyp_type = 3 (Both leptons pass tight selection)"<<endl;
  cout<<"---------------------------------------------"<<endl;
  cout<<setw(15)<<""<<setw(15)<<"Reco Level"<<setw(15)<<"Gen Level"<<endl;
  cout<<setw(15)<<"ss prompt2"<<setw(15)<<prompt2_reco<<setw(15)<<prompt2_gen<<endl;
  cout<<setw(15)<<"ss prompt1"<<setw(15)<<prompt1_reco<<setw(15)<<prompt1_gen<<endl;
  cout<<setw(15)<<"ss prompt0"<<setw(15)<<prompt0_reco<<setw(15)<<prompt0_gen<<endl;
  cout<<setw(15)<<"charge misID"<<setw(15)<<sign_misid_reco<<setw(15)<<sign_misid_gen<<endl;
  cout<<setw(15)<<"Nss"<<setw(15)<<Nss_reco<<setw(15)<<Nss_gen<<endl;
  cout<<"---------------------------------------------"<<endl;
  cout<<setw(15)<<"Nprompt L1"<<setw(15)<<NpromptL1_reco<<setw(15)<<NpromptL1_gen<<endl;
  cout<<setw(15)<<"Nprompt L2"<<setw(15)<<NpromptL2_reco<<setw(15)<<NpromptL2_gen<<endl;
  cout<<"---------------------------------------------"<<endl;

  cout<<setw(25)<<" "<<setw(10)<<"EST"<<setw(10)<<"OBS"<<setw(10)<<"EST/OBS"<<endl;
  cout<<setw(25)<<"Npn:"<<setw(10)<<Npn<<setw(10)<<prompt1_reco<<setw(10)<<Npn/prompt1_reco<<endl;
  cout<<setw(25)<<"Npn-Npn_s:"<<setw(10)<<Npn-Npn_s<<setw(10)<<prompt1_reco<<setw(10)<<(Npn-Npn_s)/prompt1_reco<<endl;
  cout<<setw(25)<<"Nnn:"<<setw(10)<<Nnn<<setw(10)<<prompt0_reco<<setw(10)<<Nnn/prompt0_reco<<endl;

  cout<<"\nCounter = "<<counter<<endl;
  cout<<"\nAve B abundance (els)= "<<Bs_e/(Bs_e + notBs_e)<<endl;
  cout<<"\nAve B abundance (mus)= "<<Bs_mu/(Bs_mu + notBs_mu)<<", Bs_mu = "<<Bs_mu<<", notBs_mu = "<<notBs_mu <<endl;
  
  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat("1.3f");

  //redefine option to save also ptRegion in output files
  option=option+"_"+ptRegion;


  // TString commonOptions = Form(" --isLinear --outOfFrame --type Supplementary (Simulation) --dataName Data --noDivisionLabel --noRatioPlot --lumi %.2f --yTitleOffset -0.2", luminosity);// --systBlack --systFillStyle 3345
  TString commonOptions = Form(" --legendCounts --isLinear --outOfFrame --type Supplementary (Simulation) --dataName Prediction --noDivisionLabel --lumi %.2f --yTitleOffset -0.2 --legendTaller 0.07 --legendRight -0.06", luminosity);// --systBlack --systFillStyle 3345
  TString commonOptionsLog = Form(" --legendCounts  --outOfFrame --type Supplementary (Simulation) --dataName Prediction --noDivisionLabel --lumi %.2f --yTitleOffset -0.2 --legendTaller 0.07 --legendRight -0.06", luminosity);// --systBlack --systFillStyle 3345

  std::string mc_type = "MC";
  std::vector<Color_t> colors;

  std::vector<std::string> obs_types;
  for(unsigned int i = 0; i < filenames.size(); i++) {
      if (filenames[i] == "TTBAR") {
          obs_types.push_back("t#bar{t}");
          colors.push_back(kYellow);
      }
      else if (filenames[i] == "WJets") {
          obs_types.push_back("W+jets");
          colors.push_back(kOrange);
      }
      else {
          obs_types.push_back(filenames[i].Data());
          colors.push_back(kGreen+2);
      }
  }

  if (!doData) {
  //BR plots
  GetErrorPlot(hists[getHist("Npn_histo_br_pred")], Npn_histo_br_err2_pred_mu, Npn_histo_br_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_br_pred_mu")], Npn_histo_br_err2_pred_mu, Npn_histo_br_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_br_pred_el")], Npn_histo_br_err2_pred_mu, Npn_histo_br_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_br_pred")], getBackgrounds("Npn_histo_br_obs", -1, filenames), obs_types, "BRs", mc_type+"", Form("--outputName %s --xAxisLabel Baseline Region --noXaxisUnit"+commonOptions, (plotdir+"br_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_br_pred_mu")], getBackgrounds("Npn_histo_br_obs", 1, filenames), obs_types, "BRs", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel Baseline Region --noXaxisUnit"+commonOptions, (plotdir+"br_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_br_pred_el")], getBackgrounds("Npn_histo_br_obs", 0, filenames), obs_types, "BRs", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel Baseline Region --noXaxisUnit"+commonOptions, (plotdir+"br_el"+option).Data()), {}, {}, colors); 

  //SR plots
  string typeAG = "HH";
  if (highlow) typeAG = "HL";
  if (lowlow)  typeAG = "LL";
  GetErrorPlot(hists[getHist("Npn_histo_sr_pred")], Npn_histo_sr_err2_pred_mu, Npn_histo_sr_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_sr_pred_mu")], Npn_histo_sr_err2_pred_mu, Npn_histo_sr_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_sr_pred_el")], Npn_histo_sr_err2_pred_mu, Npn_histo_sr_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred")], getBackgrounds("Npn_histo_sr_obs",-1,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+"", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptions, (plotdir+"sr_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred_mu")], getBackgrounds("Npn_histo_sr_obs",1,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptions, (plotdir+"sr_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred_el")], getBackgrounds("Npn_histo_sr_obs",0,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptions, (plotdir+"sr_el"+option).Data()), {}, {}, colors); 

  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred")], getBackgrounds("Npn_histo_sr_obs",-1,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+"", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptionsLog, (plotdir+"sr_log_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred_mu")], getBackgrounds("Npn_histo_sr_obs",1,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptionsLog, (plotdir+"sr_log_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_sr_pred_el")], getBackgrounds("Npn_histo_sr_obs",0,filenames), obs_types, Form("%s SRs", typeAG.c_str()), mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel SR --noXaxisUnit"+commonOptionsLog, (plotdir+"sr_log_el"+option).Data()), {}, {}, colors); 

  //HT plots
  GetErrorPlot(hists[getHist("Npn_histo_HT_pred")], Npn_histo_HT_err2_pred_mu, Npn_histo_HT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_HT_pred_mu")], Npn_histo_HT_err2_pred_mu, Npn_histo_HT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_HT_pred_el")], Npn_histo_HT_err2_pred_mu, Npn_histo_HT_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_HT_pred")], getBackgrounds("Npn_histo_HT_obs",-1,filenames), obs_types, "H_{T}", mc_type+"", Form("--outputName %s --xAxisLabel H_{T}"+commonOptions, (plotdir+"HT_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_HT_pred_mu")], getBackgrounds("Npn_histo_HT_obs",1,filenames), obs_types, "H_{T}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel H_{T}"+commonOptions, (plotdir+"HT_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_HT_pred_el")], getBackgrounds("Npn_histo_HT_obs",0,filenames), obs_types, "H_{T}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel H_{T}"+commonOptions, (plotdir+"HT_el"+option).Data()), {}, {}, colors); 

  //MET plots
  GetErrorPlot(hists[getHist("Npn_histo_MET_pred")], Npn_histo_MET_err2_pred_mu, Npn_histo_MET_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MET_pred_mu")], Npn_histo_MET_err2_pred_mu, Npn_histo_MET_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MET_pred_el")], Npn_histo_MET_err2_pred_mu, Npn_histo_MET_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_MET_pred")], getBackgrounds("Npn_histo_MET_obs",-1,filenames), obs_types, "MET", mc_type+"", Form("--outputName %s --xAxisLabel MET"+commonOptions, (plotdir+"MET_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MET_pred_mu")], getBackgrounds("Npn_histo_MET_obs",1,filenames), obs_types, "MET", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel MET"+commonOptions, (plotdir+"MET_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MET_pred_el")], getBackgrounds("Npn_histo_MET_obs",0,filenames), obs_types, "MET", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel MET"+commonOptions, (plotdir+"MET_el"+option).Data()), {}, {}, colors); 
//MLL plots
  GetErrorPlot(hists[getHist("Npn_histo_MLL_pred")], Npn_histo_MLL_err2_pred_mu, Npn_histo_MLL_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MLL_pred_mu")], Npn_histo_MLL_err2_pred_mu, Npn_histo_MLL_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MLL_pred_el")], Npn_histo_MLL_err2_pred_mu, Npn_histo_MLL_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_MLL_pred")], getBackgrounds("Npn_histo_MLL_obs",-1,filenames), obs_types, "M_{ll}", mc_type+"", Form("--outputName %s --xAxisLabel MLL"+commonOptions, (plotdir+"MLL_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MLL_pred_mu")], getBackgrounds("Npn_histo_MLL_obs",1,filenames), obs_types, "M_{ll}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel MLL"+commonOptions, (plotdir+"MLL_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MLL_pred_el")], getBackgrounds("Npn_histo_MLL_obs",0,filenames), obs_types, "M_{ll}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel MLL"+commonOptions, (plotdir+"MLL_el"+option).Data()), {}, {}, colors); 
//MJJ
  GetErrorPlot(hists[getHist("Npn_histo_MJJ_pred")], Npn_histo_MJJ_err2_pred_mu, Npn_histo_MJJ_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MJJ_pred_mu")], Npn_histo_MJJ_err2_pred_mu, Npn_histo_MJJ_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MJJ_pred_el")], Npn_histo_MJJ_err2_pred_mu, Npn_histo_MJJ_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_MJJ_pred")], getBackgrounds("Npn_histo_MJJ_obs",-1,filenames), obs_types, "M_{jj}", mc_type+"", Form("--outputName %s --xAxisLabel MJJ"+commonOptions, (plotdir+"MJJ_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MJJ_pred_mu")], getBackgrounds("Npn_histo_MJJ_obs",1,filenames), obs_types, "M_{jj}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel MJJ"+commonOptions, (plotdir+"MJJ_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MJJ_pred_el")], getBackgrounds("Npn_histo_MJJ_obs",0,filenames), obs_types, "M_{jj}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel MJJ"+commonOptions, (plotdir+"MJJ_el"+option).Data()), {}, {}, colors); 

  //MTMAX plots
  GetErrorPlot(hists[getHist("Npn_histo_MTMAX_pred")], Npn_histo_MTMAX_err2_pred_mu, Npn_histo_MTMAX_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MTMAX_pred_mu")], Npn_histo_MTMAX_err2_pred_mu, Npn_histo_MTMAX_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_MTMAX_pred_el")], Npn_histo_MTMAX_err2_pred_mu, Npn_histo_MTMAX_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_MTMAX_pred")], getBackgrounds("Npn_histo_MTMAX_obs",-1,filenames), obs_types, "M_{T}^{min}", mc_type+"", Form("--outputName %s --xAxisLabel M_{T}^{min}"+commonOptions, (plotdir+"MTMAX_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MTMAX_pred_mu")], getBackgrounds("Npn_histo_MTMAX_obs",1,filenames), obs_types, "M_{T}^{min}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel M_{T}^{min}"+commonOptions, (plotdir+"MTMAX_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_MTMAX_pred_el")], getBackgrounds("Npn_histo_MTMAX_obs",0,filenames), obs_types, "M_{T}^{min}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel M_{T}^{min}"+commonOptions, (plotdir+"MTMAX_el"+option).Data()), {}, {}, colors); 

  //L1PT plots
  GetErrorPlot(hists[getHist("Npn_histo_L1PT_pred")], Npn_histo_L1PT_err2_pred_mu, Npn_histo_L1PT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_L1PT_pred_mu")], Npn_histo_L1PT_err2_pred_mu, Npn_histo_L1PT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_L1PT_pred_el")], Npn_histo_L1PT_err2_pred_mu, Npn_histo_L1PT_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_L1PT_pred")], getBackgrounds("Npn_histo_L1PT_obs",-1,filenames), obs_types, "L1 p_{T}", mc_type+"", Form("--outputName %s --xAxisLabel L1 p_{T}"+commonOptions, (plotdir+"L1PT_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_L1PT_pred_mu")], getBackgrounds("Npn_histo_L1PT_obs",1,filenames), obs_types, "L1 p_{T}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel L1 p_{T}"+commonOptions, (plotdir+"L1PT_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_L1PT_pred_el")], getBackgrounds("Npn_histo_L1PT_obs",0,filenames), obs_types, "L1 p_{T}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel L1 p_{T}"+commonOptions, (plotdir+"L1PT_el"+option).Data()), {}, {}, colors); 

  //L2PT plots
  GetErrorPlot(hists[getHist("Npn_histo_L2PT_pred")], Npn_histo_L2PT_err2_pred_mu, Npn_histo_L2PT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_L2PT_pred_mu")], Npn_histo_L2PT_err2_pred_mu, Npn_histo_L2PT_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_L2PT_pred_el")], Npn_histo_L2PT_err2_pred_mu, Npn_histo_L2PT_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_L2PT_pred")], getBackgrounds("Npn_histo_L2PT_obs",-1,filenames), obs_types, "L2 p_{T}", mc_type+"", Form("--outputName %s --xAxisLabel L2 p_{T}"+commonOptions, (plotdir+"L2PT_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_L2PT_pred_mu")], getBackgrounds("Npn_histo_L2PT_obs",1,filenames), obs_types, "L2 p_{T}", mc_type+", Nonprompt muons", Form("--outputName %s --xAxisLabel L2 p_{T}"+commonOptions, (plotdir+"L2PT_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_L2PT_pred_el")], getBackgrounds("Npn_histo_L2PT_obs",0,filenames), obs_types, "L2 p_{T}", mc_type+", Nonprompt electrons", Form("--outputName %s --xAxisLabel L2 p_{T}"+commonOptions, (plotdir+"L2PT_el"+option).Data()), {}, {}, colors); 
  
  //LTrue plots
  GetErrorPlot(hists[getHist("Npn_histo_LTrue_pred")], Npn_histo_LTrue_err2_pred_mu, Npn_histo_LTrue_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_LTrue_pred_mu")], Npn_histo_LTrue_err2_pred_mu, Npn_histo_LTrue_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_LTrue_pred_el")], Npn_histo_LTrue_err2_pred_mu, Npn_histo_LTrue_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_LTrue_pred")], getBackgrounds("Npn_histo_LTrue_obs",-1,filenames), obs_types, "LTight p_{T}", mc_type+", all", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LTight p_{T} "+commonOptions, (plotdir+"LTrue_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_LTrue_pred_mu")], getBackgrounds("Npn_histo_LTrue_obs",1,filenames), obs_types, "LTight p_{T}", mc_type+", Nonprompt muons", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LTight p_{T} "+commonOptions, (plotdir+"LTrue_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_LTrue_pred_el")], getBackgrounds("Npn_histo_LTrue_obs",0,filenames), obs_types, "LTight p_{T}", mc_type+", Nonprompt electrons", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LTight p_{T} "+commonOptions, (plotdir+"LTrue_el"+option).Data()), {}, {}, colors); 

  //LFake plots
  GetErrorPlot(hists[getHist("Npn_histo_LFake_pred")], Npn_histo_LFake_err2_pred_mu, Npn_histo_LFake_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_LFake_pred_mu")], Npn_histo_LFake_err2_pred_mu, Npn_histo_LFake_err2_pred_el, inSitu);
  GetErrorPlot(hists[getHist("Npn_histo_LFake_pred_el")], Npn_histo_LFake_err2_pred_mu, Npn_histo_LFake_err2_pred_el, inSitu);
  dataMCplotMaker(hists[getHist("Npn_histo_LFake_pred")], getBackgrounds("Npn_histo_LFake_obs",-1,filenames), obs_types, "LLoose p_{T}", mc_type+", all", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LLoose p_{T} "+commonOptions, (plotdir+"LFake_all"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_LFake_pred_mu")], getBackgrounds("Npn_histo_LFake_obs",1,filenames), obs_types, "LLoose p_{T}", mc_type+", Nonprompt muons", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LLoose p_{T} "+commonOptions, (plotdir+"LFake_mu"+option).Data()), {}, {}, colors); 
  dataMCplotMaker(hists[getHist("Npn_histo_LFake_pred_el")], getBackgrounds("Npn_histo_LFake_obs",0,filenames), obs_types, "LLoose p_{T}", mc_type+", Nonprompt electrons", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LLoose p_{T} "+commonOptions, (plotdir+"LFake_el"+option).Data()), {}, {}, colors); 
  // dataMCplotMaker(hists[getHist("Npn_histo_LFake_pred_el_rebin")], { make_pair(hists[getHist("Npn_histo_LFake_obs_el_rebin")], hists[getHist("Npn_histo_LFake_obs_el_rebin")]) }, obs_types, "LLoose p_{T}", mc_type+", el", Form("--outputName %s --outOfFrame --dataName Data --xAxisLabel LLoose p_{T} --noDivisionLabel --setMaxMultiplier 2.0 --isLinear --noOverflow --lumi 12.9 --noXaxisUnit --systBlack --systFillStyle 3345 --type Simulation --lumiPrec 1 --legendCounts", (plotdir+"LFake_el_rebin"+option).Data()), {}, {}, colors); 


  TH1F *total_BR_histo_e = (TH1F*)  hists[getHist("NBs_BR_histo_e")]->Clone("total_BR_histo_e");
  TH1F *total_BR_histo_mu = (TH1F*) hists[getHist("NBs_BR_histo_mu")]->Clone("total_BR_histo_mu");
  total_BR_histo_e->Add(hists[getHist("NnotBs_BR_histo_e")]);
  total_BR_histo_mu->Add(hists[getHist("NnotBs_BR_histo_mu")]);
  hists[getHist("NBs_BR_histo_e")]->Divide(hists[getHist("NBs_BR_histo_e")], total_BR_histo_e,1,1,"B");
  hists[getHist("NBs_BR_histo_mu")]->Divide(hists[getHist("NBs_BR_histo_mu")], total_BR_histo_mu,1,1,"B");
  hists[getHist("NBs_BR_histo_e")]->GetXaxis()->SetTitle("Nbtags"); 
  hists[getHist("NBs_BR_histo_e")]->GetYaxis()->SetTitle("Abundance");
  hists[getHist("NBs_BR_histo_e")]->GetYaxis()->SetRangeUser(0.,1.);
  hists[getHist("NBs_BR_histo_e")]->SetTitle("B Abundance vs Nbtags (Njets >= 2) (electrons)");
  hists[getHist("NBs_BR_histo_mu")]->GetXaxis()->SetTitle("Nbtags"); 
  hists[getHist("NBs_BR_histo_mu")]->GetYaxis()->SetTitle("Abundance");
  hists[getHist("NBs_BR_histo_mu")]->GetYaxis()->SetRangeUser(0.,1.);
  hists[getHist("NBs_BR_histo_mu")]->SetTitle("B Abundance vs Nbtags (Njets >= 2) (muons)");

  TCanvas *c6 = new TCanvas("c6","B Abundance vs Nbtags (Njets >= 2) (electrons)", 800,800);
  c6->cd();
  hists[getHist("NBs_BR_histo_e")]->Draw("histE");
  TCanvas *c7 = new TCanvas("c7","B Abundance vs Nbtags (Njets >= 2) (muons)", 800,800);
  c7->cd();
  hists[getHist("NBs_BR_histo_mu")]->Draw("histE");
  TCanvas c8;
  hists[getHist("pTrel_histo_mu")]->Draw();
  c8.SaveAs(plotdir+"pTrel_mu"+option+".png");
  hists[getHist("pTrel_histo_el")]->Draw();
  c8.SaveAs(plotdir+"pTrel_el"+option+".png");
  c8.SetLogz();
  pTrelvsIso_histo_mu->Draw("colz");
  c8.SaveAs(plotdir+"pTrelvsIso_mu"+option+".png");
  pTrelvsIso_histo_el->Draw("colz");
  c8.SaveAs(plotdir+"pTrelvsIso_el"+option+".png");
  pTrelvsMiniIso_histo_mu->Draw("colz");
  c8.SaveAs(plotdir+"pTrelvsMiniIso_mu"+option+".png");
  pTrelvsMiniIso_histo_el->Draw("colz");
  c8.SaveAs(plotdir+"pTrelvsMiniIso_el"+option+".png");
   }
/*
  TFile *file = new TFile("histos_"+option+".root", "RECREATE");
  file->Write();
 
  for (unsigned int i = 0; i < hists.size(); i++){
      if(doData && TString(hists[i]->GetName()).Contains("_obs")) continue;
      hists[i]->Write();
  }
*/
  string outputfilename = Form("histos%s_hists.root", option.Data());
  saveHist(outputfilename.c_str(),"*");

  printCounter(true);

  if (!doData) printClosureNumbers(filenames);

  return 0;
}

