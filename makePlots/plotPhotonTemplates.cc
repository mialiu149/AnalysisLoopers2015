#include <iostream>

#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "TAxis.h"
#include "TCanvas.h"

using namespace std;

void plotPhotonTemplates( string region = "2jets_edgec" )
{

  int rebin = 10;

  string iter   = "V00-00-20";
  // string region = "2jets_inclusive";
  
  string filename =  Form("../output/photon/%s/All_MC_%s_photon_templates.root", iter.c_str(), region.c_str());
  string outputdir = Form("../output/ZMET2015/%s/plots/Templates/%s/"          , iter.c_str(), region.c_str());

  TCanvas * c1 = new TCanvas("c1","c1",800,800);
  
  TFile *infile = new TFile(filename.c_str());
  std::cout<<"Reading hists from file: "<<filename<<endl;
  infile->cd();
  TIter iKey(infile->GetListOfKeys());
  TKey* key=0;
  while((key=(TKey*)iKey())) {
	TH1* hist=(TH1*)key->ReadObjectAny(TH1::Class());
	string histname = hist->GetName();
	// cout<<"Name:  "<<TString(hist->GetName())<<endl;
	string histtitle = hist->GetTitle();
	// cout<<"Title: "<<TString(hist->GetTitle())<<endl;

	c1->cd();
	c1->SetLogy(true);
	hist->Rebin(rebin);
    double entries = hist->GetEntries();
	hist->GetXaxis()->SetTitle(Form("E_{T}^{miss}; %i entries",(int)entries));
	hist->GetYaxis()->SetTitle(Form("Normalized Entries/%i GeV",rebin));
	hist->GetYaxis()->SetRangeUser(1e-6,1);
	hist->Draw("histe1");

	if( !(histtitle == "") ){	
	  string outfile = outputdir+histtitle+".png";	
	  c1->SaveAs(outfile.c_str());
	}

	else{ 
	  string outfile = outputdir+histname+".png";	
	  c1->SaveAs(outfile.c_str());
	}

	// outfile = outputdir+histtitle+".ps";
	// c1->SaveAs(outfile.c_str());
	
  }
  
  return;
}
