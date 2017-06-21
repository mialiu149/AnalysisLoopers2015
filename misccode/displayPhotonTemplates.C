#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include "TChain.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TLine.h"
#include "TProfile.h"
#include "TLatex.h"
#include "TStyle.h"
#include <sstream>
#include "benstyle.C"

#include "../CORE/metTemplatesSelections.h"

using namespace std;

enum metType   { e_tcmet = 0, e_tcmetNew = 1, e_pfmet = 2};

//----------------------------------------------------------------------------------------
//user params
//----------------------------------------------------------------------------------------
const int      nTrigBins        = 1;
// const int      nJetBins         = ;
// const int      nSumJetPtBins    = 2;
const metType  myMetType        = e_pfmet;
const float    maxmet           = 200;
const int      rebin            = 10;
const bool     twoTemplates     = true;
const bool     vertical         = true;

//----------------------------------------------------------------------------------------

void displayPhotonTemplates( string sample = "All_Data", bool printgif = true ){

  int nSumJetPtBin    = 3;
  
  //start from here
  //no reweighting comparison
  string filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_mjjveto_bveto.root";
  string filename2 = "../photon_output/V00-02-05/ttbar_2jetbins_templates_mjjveto_bveto.root";

  //reweighting comparison

  filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_mjjveto_bveto.root";
  filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_mjjveto_bveto.root";

  // filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi.root";
  // filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi.root";
  // filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi.root";
  // filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jlo.root";

  filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_2btag_mjjhi_mt2jhi.root";
  filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi.root";

  filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_2btag_mjjhi_mt2jhi.root";
  filename2 = "../photon_output/V00-02-05/ttbar_2jetbins_templates_2btag_mjjhi_mt2jhi.root";

  // filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi.root";
  filename2 = "../photon_output/V00-02-05/ttbar_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi.root";

  // filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi_withttbar.root";
  filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjhi_mt2jhi_withoutttbar.root";

  // filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi_tighthoe.root";
  filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi_inclusive.root";
  filename1 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi_inclusive_medium.root";

  filename1 = "../photon_output/V00-02-05/wjets_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi_inclusive_medium.root";
  filename2 = "../photon_output/V00-02-05/All_Data_2jetbins_templates_vtxreweight_2btag_mjjlo_mt2jhi_inclusive_medium.root";

  setBenStyle();

  gStyle->SetOptStat(0);

  TFile *file1 = TFile::Open(filename1.c_str());
  TFile *file2;
  if( twoTemplates ) file2 = TFile::Open(filename2.c_str());

  TH1F* hmet1[nTrigBins][nJetBins][nSumJetPtBin];
  TH1F* hmet2[nTrigBins][nJetBins][nSumJetPtBin];

  TCanvas *can[nTrigBins];

  Double_t nentries1 = 0;
  Double_t nentries2 = 0;
  TLatex *t = new TLatex();
  t->SetNDC();
  
  for( int iT = 0 ; iT < nTrigBins ; ++iT ){

    if( vertical ){
      can[iT] = new TCanvas(Form("can_%i",iT),Form("can_%i",iT),600,300);
      can[iT]->Divide(nJetBins-1, nSumJetPtBin-2);
    }
    else{
      can[iT] = new TCanvas(Form("can_%i",iT),Form("can_%i",iT),1500,600);
      can[iT]->Divide(nSumJetPtBin-2, nJetBins-1 );
      // can[iT]->Divide(5,2);
    }
  
    for( int iJ = 1 ; iJ < nJetBins ; iJ++ ){
      
      for( int iS = 2 ; iS < nSumJetPtBin ; iS++ ){
        
        //can[iJ]->cd(iS-1);
        // if( vertical ) can[iT]->cd( (nJetBins - 1) * (iS-2) + (iJ - 1) + 1 ) ;
        if( vertical ) can[iT]->cd( ( iJ ) + ( iS - 2 ) * (nJetBins - 1) );
        else           can[iT]->cd( (iJ-1) * (nSumJetPtBin - 2) + iS-1 );
        
        string mettype = "";
        if( myMetType == e_pfmet ) mettype = "pfmet";
        if( myMetType == e_tcmet ) mettype = "tcmet";
        
        hmet1[iT][iJ][iS] = (TH1F*) file1->Get(Form("%sTemplate_photon_%i_%i_%i",mettype.c_str(),iT,iJ,iS));
        
		bool displayOverlaid = true;
		// displayOverlaid = false;

        if( twoTemplates ){
          hmet2[iT][iJ][iS] = (TH1F*) file2->Get(Form("%sTemplate_photon_%i_%i_%i",mettype.c_str(),iT,iJ,iS));
		  if(displayOverlaid) hmet2[iT][iJ][iS] = (TH1F*) file2->Get(Form("super%sTemplate_photon_%i_%i_%i",mettype.c_str(),iT,iJ,iS));
        }

        if( hmet1[iT][iJ][iS]->Integral() > 0 )
		  if(displayOverlaid) gPad->SetLogy(1);
        
        hmet1[iT][iJ][iS]->Rebin(rebin);
		// hmet1[iT][iJ][iS]->Scale(1./rebin);
        if( maxmet > 0 ) hmet1[iT][iJ][iS]->GetXaxis()->SetRangeUser(0,maxmet);
        hmet1[iT][iJ][iS]->SetLineColor(2);
        hmet1[iT][iJ][iS]->SetMarkerColor(2);
        hmet1[iT][iJ][iS]->SetMarkerSize(0.5);
        hmet1[iT][iJ][iS]->Draw("E1");
        
        hmet1[iT][iJ][iS]->SetMinimum(0);
        if(displayOverlaid) hmet1[iT][iJ][iS]->SetMinimum(1e-3);
        // if(displayOverlaid) hmet1[iT][iJ][iS]->SetMinimum(1);
		hmet1[iT][iJ][iS]->SetTitle("");
		if(hmet1[iT][iJ][iS]->GetEntries() != 0 ){
		  hmet1[iT][iJ][iS]->SetMaximum( 5 );
		  if(displayOverlaid) hmet1[iT][iJ][iS]->SetMaximum( hmet1[iT][iJ][iS]->GetMaximum()*1e5 );
		//   hmet1[iT][iJ][iS]->SetMaximum( 1 );
		//   // hmet1[iT][iJ][iS]->SetMaximum( 0.002 );
        // }else{
		  // hmet1[iT][iJ][iS]->SetMaximum( 1 );
		}        

        stringstream s1;
        s1 << hmet1[iT][iJ][iS]->GetEntries();
        nentries1 += hmet1[iT][iJ][iS]->GetEntries();
        //s1 << hmet1[iT][iJ][iS]->Integral(  hmet1[iT][iJ][iS]->FindBin(180) , 100000) ;
        // s1 << hmet1[iT][iJ][iS]->Integral();
        // nentries1 += hmet1[iT][iJ][iS]->Integral();
        t->SetTextColor(2);
        t->SetTextSize(0.075);
        t->DrawLatex(0.6,0.8,s1.str().c_str());
        
        if( twoTemplates ){
          stringstream s2;
          s2 << hmet2[iT][iJ][iS]->GetEntries();
          nentries2 += hmet2[iT][iJ][iS]->GetEntries();
          // s2 << hmet2[iT][iJ][iS]->Integral();
          // nentries2 += hmet2[iT][iJ][iS]->Integral();
          t->SetTextColor(4);
          t->DrawLatex(0.6,0.7,s2.str().c_str());
		  // if( iT == 0 ){
          hmet2[iT][iJ][iS]->Rebin(rebin);
		  // hmet2[iT][iJ][iS]->Scale(1./rebin);
		  // }
          hmet2[iT][iJ][iS]->SetLineColor(1);
          hmet2[iT][iJ][iS]->SetMarkerColor(38);
          hmet2[iT][iJ][iS]->SetFillColor(38);
          hmet2[iT][iJ][iS]->Draw("samehist");
          hmet1[iT][iJ][iS]->Draw("sameE1");
          hmet1[iT][iJ][iS]->Draw("axissame");
        }
      }
    }
    if( printgif) can[iT]->Print(Form("~/public_html/MetTemplatePlots/template_targeted_%i_%s.pdf",iT,sample.c_str()));
  }

  cout << "nentries1 " << nentries1 << endl;
  cout << "nentries2 " << nentries2 << endl;
}
