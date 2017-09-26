void makeFRHist()
{

    TString flav = "mu";

    TFile* file_data = new TFile("fakerate_data.root");
    TFile* file_dy   = new TFile("fakerate_dy.root");
    TFile* file_wj   = new TFile("fakerate_wj.root");

    TCanvas* c1 = new TCanvas("", "", 0, 0, 800, 800);

    TH1F* hist_num_data = (TH1F*) file_data->Get("histo_ptvarbin_meas_"+flav);
    hist_num_data->Scale(43);
    TH1F* hist_num_dy   = (TH1F*) file_dy  ->Get("histo_ptvarbin_meas_"+flav);
    TH1F* hist_num_wj   = (TH1F*) file_wj  ->Get("histo_ptvarbin_meas_"+flav);

    hist_num_data->Draw("ep");
    c1->SaveAs("plot_num_before.png");

    hist_num_data->SetBinContent(1, hist_num_data->GetBinContent(0) + hist_num_data->GetBinContent(1));
    hist_num_wj  ->SetBinContent(1, hist_num_wj  ->GetBinContent(0) + hist_num_wj  ->GetBinContent(1));
    hist_num_dy  ->SetBinContent(1, hist_num_dy  ->GetBinContent(0) + hist_num_dy  ->GetBinContent(1));
    hist_num_data->SetBinContent(hist_num_data->GetNbinsX(), hist_num_data->GetBinContent(hist_num_data->GetNbinsX()) + hist_num_data->GetBinContent(hist_num_data->GetNbinsX()+1));
    hist_num_wj  ->SetBinContent(hist_num_wj  ->GetNbinsX(), hist_num_wj  ->GetBinContent(hist_num_wj  ->GetNbinsX()) + hist_num_wj  ->GetBinContent(hist_num_wj  ->GetNbinsX()+1));
    hist_num_dy  ->SetBinContent(hist_num_dy  ->GetNbinsX(), hist_num_dy  ->GetBinContent(hist_num_dy  ->GetNbinsX()) + hist_num_dy  ->GetBinContent(hist_num_dy  ->GetNbinsX()+1));
    hist_num_data->Add(hist_num_dy, -1.00668746540963);
    hist_num_data->Add(hist_num_wj, -1.00668746540963);

    hist_num_data->Draw("ep");
    c1->SaveAs("plot_num.png");

    TH1F* hist_den_data = (TH1F*) file_data->Get("histo_ptvarbin_loose_meas_"+flav);
    hist_den_data->Scale(43);
    TH1F* hist_den_dy   = (TH1F*) file_dy  ->Get("histo_ptvarbin_loose_meas_"+flav);
    TH1F* hist_den_wj   = (TH1F*) file_wj  ->Get("histo_ptvarbin_loose_meas_"+flav);

    hist_den_data->Draw("ep");
    c1->SaveAs("plot_den_before.png");

    hist_den_data->SetBinContent(1, hist_den_data->GetBinContent(0) + hist_den_data->GetBinContent(1));
    hist_den_wj  ->SetBinContent(1, hist_den_wj  ->GetBinContent(0) + hist_den_wj  ->GetBinContent(1));
    hist_den_dy  ->SetBinContent(1, hist_den_dy  ->GetBinContent(0) + hist_den_dy  ->GetBinContent(1));
    hist_den_data->SetBinContent(hist_den_data->GetNbinsX(), hist_den_data->GetBinContent(hist_den_data->GetNbinsX()) + hist_den_data->GetBinContent(hist_den_data->GetNbinsX()+1));
    hist_den_wj  ->SetBinContent(hist_den_wj  ->GetNbinsX(), hist_den_wj  ->GetBinContent(hist_den_wj  ->GetNbinsX()) + hist_den_wj  ->GetBinContent(hist_den_wj  ->GetNbinsX()+1));
    hist_den_dy  ->SetBinContent(hist_den_dy  ->GetNbinsX(), hist_den_dy  ->GetBinContent(hist_den_dy  ->GetNbinsX()) + hist_den_dy  ->GetBinContent(hist_den_dy  ->GetNbinsX()+1));
    hist_den_data->Add(hist_den_dy, -1.00668746540963);
    hist_den_data->Add(hist_den_wj, -1.00668746540963);

    hist_den_data->Draw("ep");
    c1->SaveAs("plot_den.png");

    TH1F* ratio = (TH1F*) hist_num_data->Clone("ratio");
    ratio->Divide(hist_num_data, hist_den_data, 1, 1, "B");

    ratio->Draw("ep");
    ratio->SetMinimum(0);
    ratio->SetMaximum(0.7);
    c1->SaveAs("plots/plot_fakerate_"+flav+".png");

    TFile* file_qcd_mu = new TFile("fakerate_qcd_"+flav+".root");
    TH1F* hist_num_qcd_mu = (TH1F*) file_qcd_mu->Get("histo_ptvarbin_meas_"+flav);
    TH1F* hist_den_qcd_mu = (TH1F*) file_qcd_mu->Get("histo_ptvarbin_loose_meas_"+flav);

    TH1F* ratio_qcd_mu = (TH1F*) hist_num_qcd_mu->Clone("ratio");
    ratio_qcd_mu->Divide(hist_num_qcd_mu, hist_den_qcd_mu, 1, 1, "B");

    ratio_qcd_mu->Draw("ep");
    ratio_qcd_mu->SetMinimum(0);
    ratio_qcd_mu->SetMaximum(0.7);
    c1->SaveAs("plots/plot_fakerate_pt_qcd_"+flav+".png");

}
