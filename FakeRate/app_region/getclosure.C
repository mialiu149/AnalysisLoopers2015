{ 
TFile *_file0 = TFile::Open("histos_LooseEMVA_coneCorr_HH_hists.root");
TH1F *h1 = (TH1F*)gDirectory->Get("Npn_histo_br_obs_elWJets");
h1->Print("all");
TH1F *h2 = (TH1F*)gDirectory->Get("Npn_histo_br_obs_elTTBAR");
h2->Print("all");
h1->Add(h2);
h1->Print("all");
TH1F *h3 = (TH1F*)gDirectory->Get("Npn_histo_br_pred_el");
h3->Print("all");
h3->Divide(h1);
h3->Print("all");
}
