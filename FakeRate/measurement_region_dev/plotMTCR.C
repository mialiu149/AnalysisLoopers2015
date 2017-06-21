#include "../../commonUtils.h"
pair<float,float> plotMTCR(float inputSF_el, float inputSF_mu, bool useIsoTrig) {

  float sfel, sfmu;

//	  TString suffix = (useIsoTrig ? "_IsoTrigs" : "");
  TString suffix = "";
  
  for(int doMu = 0; doMu < 2; doMu++) {

  gROOT->Reset();

  gStyle->SetOptStat(0);
  TGaxis::SetMaxDigits(3);

  TCanvas c1("c1","c1",600,600);

  TString plot = "mt_cr";
  bool applyInputSF  = 0;
  bool applyOutputSF = 1;

  float lowerMt = 70.; // qcd contaminates cr, so bumped this up
  float upperMt = 120.;

  if (doMu) plot = "histo_"+plot+"_mu";
  else plot = "histo_"+plot+"_el";

//	  TFile *_file_wj = TFile::Open("rate_histos_wj_LooseEMVA"+suffix+".root");
//	  TFile *_file_dy = TFile::Open("rate_histos_dy_LooseEMVA"+suffix+".root");

//	  TFile *_file_data = TFile::Open("rate_histos_data_LooseEMVA"+suffix+".root");

  TFile *_file_wj = TFile::Open("rate_histos_wj"+suffix+".root");
  TFile *_file_dy = TFile::Open("rate_histos_dy"+suffix+".root");

  TFile *_file_data = TFile::Open("rate_histos_data"+suffix+".root");

  TH1F* h_data = (TH1F*) _file_data->Get(plot);
  TH1F* h_wj = (TH1F*) _file_wj->Get(plot);
  TH1F* h_dy = (TH1F*) _file_dy->Get(plot);


  if (applyInputSF) {
    if (doMu) {
      h_wj->Scale(inputSF_mu);
      h_dy->Scale(inputSF_mu);
    } else {
      h_wj->Scale(inputSF_el);
      h_dy->Scale(inputSF_el);
    }
  }

  float sf = -1;
  if (applyOutputSF) {
    float ewkMtwindow = h_wj->Integral(h_wj->FindBin(lowerMt),h_wj->FindBin(upperMt)) + h_dy->Integral(h_dy->FindBin(lowerMt),h_dy->FindBin(upperMt));
    float dataMtwindow = h_data->Integral(h_data->FindBin(lowerMt),h_data->FindBin(upperMt));
    sf = dataMtwindow/ewkMtwindow;
    cout << "doMu=" << doMu << " ewk=" << ewkMtwindow << " data=" << dataMtwindow << " sf=" << sf << endl;

    if(doMu) sfmu = sf;
    else sfel = sf;

    h_wj->Scale(dataMtwindow/ewkMtwindow);
    h_dy->Scale(dataMtwindow/ewkMtwindow);
  }

  h_wj->SetFillColor(kRed+2);
  h_dy->SetFillColor(kYellow+2);

  THStack* h_ewk = new THStack("hs","hs");
  h_ewk->Add(h_wj);
  h_ewk->Add(h_dy);

  h_data->SetMarkerStyle(kFullCircle);

  if(doMu) h_data->SetTitle("M_{T} (#mu)");
  else h_data->SetTitle("M_{T} (e)");

  h_data->GetXaxis()->SetTitle("MT [GeV]");
  if (plot.Contains("met")) h_data->GetXaxis()->SetTitle("MET [GeV]");
  h_data->GetYaxis()->SetTitle("events/bin");
  h_data->GetYaxis()->SetTitleOffset(1.2);

  h_data->Draw("PE");
  h_ewk->Draw("same,hist");
  h_data->Draw("same");  

  TLegend* leg = new TLegend(0.7,0.7,0.89,0.89);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetHeader(Form("L=%.1f/fb",getLumi()));
  // leg->SetHeader(Form("L=%.1f/fb",12.9-6.26)); // HALF
  leg->AddEntry(h_data,"data","pe");
  leg->AddEntry(h_wj  ,"W+jets","f");
  leg->AddEntry(h_dy  ,"DY","f");
  leg->AddEntry((TObject*)0  ,Form( "SF: %.2f", sf ),"");
  leg->Draw();

  c1.SaveAs("pdfs/"+plot+(doMu ? "_mu" : "_el")+suffix+".pdf");
  }

  return make_pair(sfel,sfmu);
}
