#include <iostream>

#include "TChain.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCut.h"

using namespace std;

int getVtxWeights()
{

  TChain * ch_zjets = new TChain("t");

  string iter = "V00-00-20";
  
  // ch_zjets->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_m50inc*.root");
  ch_zjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
  ch_zjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));
  
  TChain * ch_gjets = new TChain("t");

  ch_gjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/gjet_ht100to200*.root", iter.c_str() ));
  ch_gjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/gjet_ht200to400*.root", iter.c_str() ));
  ch_gjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/gjet_ht400to600*.root", iter.c_str() ));
  ch_gjets->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/gjet_ht600toinf*.root", iter.c_str() ));

  TH1F * h_nvtx = new TH1F("h_nvtx", "", 50,0,50);
  // TH1F * h_num = new TH1F("h_num", "", 50,0,50);
  TH1F * h_den = new TH1F("h_den", "", 50,0,50);

  h_nvtx->Sumw2();
  // h_num->Sumw2();
  h_den->Sumw2();
  
  TCut dilep    ("nlep > 1 && lep_pt[0] > 25 && lep_pt[1] > 20 && dilmass > 81 && dilmass < 101 && dRll > 0.1 && evt_type == 0");
  TCut dilpt50  ("dilpt > 50");
  TCut gteq2jets("njets > 1 ");
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
	
  selection = dilep+gteq2jets;
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
