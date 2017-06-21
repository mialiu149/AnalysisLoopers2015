#include <iostream>

#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCut.h"

using namespace std;

int getVtxWeights()
{

  TChain * ch_zjets = new TChain("t");

  // ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_m50inc*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht100to200*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht200to400*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht400to600*.root");
  ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf*.root");
  
  TChain * ch_gjets = new TChain("t");

  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht100to200*.root");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht200to400*.root");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht400to600*.root");
  ch_gjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/gjet_ht600toinf*.root");

  TH1F * h_nvtx = new TH1F("h_nvtx", "", 50,0,50);
  // TH1F * h_num = new TH1F("h_num", "", 50,0,50);
  TH1F * h_den = new TH1F("h_den", "", 50,0,50);

  h_nvtx->Sumw2();
  // h_num->Sumw2();
  h_den->Sumw2();
  
  TCut dilep    ("nlep  > 1 && dilmass > 81 && dilmass < 101");
  TCut dilpt50  ("dilpt > 50");
  TCut gteq2jets("njets > 1 ");
  TCut pt2525   ("lep_pt[0] > 25 && lep_pt[1] > 25");  
  TCut ht100    ("ht > 100");  
  TCut ht240    ("ht > 240");  
  TCut llonly   ("hyp_type==0||hyp_type==1");  

  TCut photon   ("ngamma  > 0");
  TCut pt22     ("gamma_pt[0]        > 22 ");
  TCut hoe      ("gamma_hOverE[0]    < 0.1");
  TCut emf      ("matched_neutralemf > 0.7");
  TCut elveto   ("!elveto"                 );
  
  TCut selection;
  selection = photon+gteq2jets+pt22+ht240+hoe+emf;
  selection += elveto;
  
  cout<<"Getting photon+jets events."<<endl;
  ch_gjets->Draw("min(nVert, 49.5)>>h_den", selection);
	
  selection = dilep+gteq2jets+pt2525+ht240;
  selection += llonly;
  
  cout<<"Getting Z+jets events."<<endl;
  ch_zjets->Draw("min(nVert, 49.5)>>h_nvtx", selection);

  // for( int binind = 0; binind < h_den->GetNBins(); binind++ ){  
  // 	if( h_den->GetBinContent(binind) < 1 ){
  // 	  h_den->SetBinContent(binind, 1.0);
  // 	  h_den->SetBinError(binind, 1.0);
  // 	}
  // }
  

  h_nvtx->Scale(1.0/h_nvtx->GetSumOfWeights());
  h_den->Scale(1.0/h_den->GetSumOfWeights());
  h_nvtx->Divide(h_den);
  // h_nvtx = h_num;
  
  cout<<"Saving output to: vtx_reweight_MC.root"<<endl;
  TFile * outfile = TFile::Open("vtx_reweight_MC.root","RECREATE");

  outfile->cd();
  h_nvtx->Write();
  h_den->Write();
  outfile->Close();
  
  return 0;
}
