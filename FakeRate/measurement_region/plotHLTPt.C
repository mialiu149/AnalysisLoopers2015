{

  TFile *_file0 = TFile::Open("rate_histos_data_LooseEMVA.root");

  TH1F* histo_pt_mu = (TH1F*) _file0->Get("histo_pt_mu");
  histo_pt_mu->SetLineColor(kBlack);
  TH1F* histo_pt_mu8 = (TH1F*) _file0->Get("histo_pt_mu8");
  histo_pt_mu8->SetFillColor(kRed);
  TH1F* histo_pt_mu17 = (TH1F*) _file0->Get("histo_pt_mu17");
  histo_pt_mu17->SetFillColor(kBlue);
  TH1F* histo_pt_mu24 = (TH1F*) _file0->Get("histo_pt_mu24");
  histo_pt_mu24->SetFillColor(kMagenta);
  TH1F* histo_pt_mu34 = (TH1F*) _file0->Get("histo_pt_mu34");
  histo_pt_mu34->SetFillColor(kGreen);
  TCanvas c1;
  c1.SetLogy();
  c1.SetGridx();
  histo_pt_mu->Draw("histE");
  histo_pt_mu8->Draw("hist,same");
  histo_pt_mu17->Draw("hist,same");
  histo_pt_mu24->Draw("hist,same");
  histo_pt_mu34->Draw("hist,same");
  histo_pt_mu->Draw("histE,same");
  c1.SaveAs("pt_mu.png");

  TH1F* histo_pt_el = (TH1F*) _file0->Get("histo_pt_el");
  histo_pt_el->SetLineColor(kBlack);
  TH1F* histo_pt_el8 = (TH1F*) _file0->Get("histo_pt_el8");
  histo_pt_el8->SetFillColor(kRed);
  TH1F* histo_pt_el12 = (TH1F*) _file0->Get("histo_pt_el12");
  histo_pt_el12->SetFillColor(kGray);
  TH1F* histo_pt_el17 = (TH1F*) _file0->Get("histo_pt_el17");
  histo_pt_el17->SetFillColor(kBlue);
  TH1F* histo_pt_el24 = (TH1F*) _file0->Get("histo_pt_el24");
  histo_pt_el24->SetFillColor(kMagenta);
  TH1F* histo_pt_el34 = (TH1F*) _file0->Get("histo_pt_el34");
  histo_pt_el34->SetFillColor(kGreen);
  TCanvas c2;
  c2.SetLogy();
  c2.SetGridx();
  histo_pt_el->Draw("histE");
  histo_pt_el8->Draw("hist,same");
  histo_pt_el12->Draw("hist,same");
  histo_pt_el17->Draw("hist,same");
  histo_pt_el24->Draw("hist,same");
  histo_pt_el34->Draw("hist,same");
  histo_pt_el->Draw("histE,same");
  c2.SaveAs("pt_el.png");

}
