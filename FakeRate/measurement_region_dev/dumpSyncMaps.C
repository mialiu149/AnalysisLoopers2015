{

  TCanvas c1;

  TFile* f1 = TFile::Open("rate_histos_sync_LooseEMVA.root");

  Nl_cone_histo_e->Draw("text");
  c1.SaveAs("noniso_den_ele.png");
  Nt_histo_e->Draw("text");
  c1.SaveAs("noniso_num_ele.png");

  Nl_cone_histo_mu->Draw("text");
  c1.SaveAs("noniso_den_mu.png");
  Nt_histo_mu->Draw("text");
  c1.SaveAs("noniso_num_mu.png");

  TFile* f2 = TFile::Open("rate_histos_sync_LooseEMVA_IsoTrigs.root");

  Nl_cone_histo_e->Draw("text");
  c1.SaveAs("iso_den_ele.png");
  Nt_histo_e->Draw("text");
  c1.SaveAs("iso_num_ele.png");

  Nl_cone_histo_mu->Draw("text");
  c1.SaveAs("iso_den_mu.png");
  Nt_histo_mu->Draw("text");
  c1.SaveAs("iso_num_mu.png");

}
