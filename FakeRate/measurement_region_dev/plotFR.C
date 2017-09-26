{
  for(int i = 1; i < 3; i++) {
      for(int doIso = 0; doIso < 1; doIso++) {

  gROOT->Reset();
  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat("4.2f");

  bool saveDen = true;

  TString sample;
  if(i == 0) sample = "data";
  if(i == 1) sample = "qcd_mu";
  if(i == 2) sample = "qcd_el";
  // sample = "qcd_mu";
  // sample = "qcd_el";
  // sample = "wj";

  TString postfix = "";
//  postfix+="_LooseEMVA";
  if(doIso) postfix+="_IsoTrigs";
  // postfix+="_PtRatioCor";
//   postfix+="_doBonly";
//     postfix+="_doLightonly";
  TString var = "";
  var="_cone";
  // var="_jet";
  // var="_jet_highpt";
  // var="_jet_lowpt";

  TFile* f = TFile::Open("rate_histos_"+sample+postfix+".root");

  if (sample.Contains("_el")==0) {
    TH2F* muf = (TH2F*) f->Get("rate"+var+"_histo_mu");
    muf->SetTitle("muon fake rate ("+sample+")");
    muf->GetXaxis()->SetTitle("muon p_{T} [GeV]");
    if (var=="_cone") muf->GetXaxis()->SetTitle("muon p_{T}^{corr.} [GeV]");
    if (var=="_jet") muf->GetXaxis()->SetTitle("jet p_{T} [GeV]");
    muf->GetYaxis()->SetTitle("muon |#eta|");
    muf->GetYaxis()->SetTitleOffset(1.2);
    if (postfix=="_extrPtRel") muf->GetYaxis()->SetTitle("H_{T} [GeV]");
    TCanvas c1("c1","c1",600,600);
    muf->GetZaxis()->SetRangeUser(0,0.5);
    muf->GetZaxis()->SetLabelSize(0.025);
    muf->SetMarkerSize(1.5);
    if (postfix!="_extrPtRel") muf->GetXaxis()->SetNdivisions(6,0);
    muf->Draw("texte,colz");
    c1.RedrawAxis();
    c1.SaveAs("~/public_html/fakerate/measurement/pdfs/mu_fr"+var+"_"+sample+postfix+".pdf");
  }

  if (sample.Contains("_mu")==0) {
    TH2F* elf = (TH2F*) f->Get("rate"+var+"_histo_e");
    elf->SetTitle("electron fake rate ("+sample+")");
    elf->GetXaxis()->SetTitle("electron p_{T} [GeV]");
    if (var=="_cone") elf->GetXaxis()->SetTitle("electron p_{T}^{corr.} [GeV]");
    if (var=="_jet") elf->GetXaxis()->SetTitle("jet p_{T} [GeV]");
    elf->GetYaxis()->SetTitle("electron |#eta|");
    elf->GetYaxis()->SetTitleOffset(1.2);
    if (postfix=="_extrPtRel") elf->GetYaxis()->SetTitle("H_{T} [GeV]");
    TCanvas c2("c2","c2",600,600);
    elf->GetZaxis()->SetRangeUser(0,0.5);
    elf->GetZaxis()->SetLabelSize(0.025);
    elf->SetMarkerSize(1.5);
    if (postfix!="_extrPtRel") elf->GetXaxis()->SetNdivisions(6,0);
    elf->Draw("texte,colz");
    c2.RedrawAxis();
    c2.SaveAs("/home/users/mliu/public_html/fakerate/measurement/pdfs/el_fr"+var+"_"+sample+postfix+".pdf");
  }

  if (saveDen) {

    if (sample.Contains("_el")==0) {
      TH2F* mud = (TH2F*) f->Get("Nl"+var+"_histo_mu");
      mud->SetTitle("muon fake rate denominator ("+sample+")");
      mud->GetXaxis()->SetTitle("muon p_{T} [GeV]");
      if (var=="_cone") mud->GetXaxis()->SetTitle("muon p_{T}^{corr.} [GeV]");
      if (var=="_jet") mud->GetXaxis()->SetTitle("jet p_{T} [GeV]");
      mud->GetYaxis()->SetTitle("moun |#eta|");
      mud->GetYaxis()->SetTitleOffset(1.2);
      if (postfix=="_extrPtRel") mud->GetYaxis()->SetTitle("H_{T} [GeV]");
      TCanvas c3("c3","c3",600,600);
      mud->SetMarkerSize(1.);
      if (postfix!="_extrPtRel") mud->GetXaxis()->SetNdivisions(6,0);
      mud->Draw("texte");
      c3.RedrawAxis();
      c3.SaveAs("/home/users/mliu/public_html/fakerate/measurement/pdfs/mu_den_fr"+var+"_"+sample+postfix+".pdf");
      TH1D* mud1d_data = mud->ProjectionX();
      mud1d_data->DrawNormalized();
      c3.SaveAs("/home/users/mliu/public_html/fakerate/measurement/pdfs/mu_den_fr"+var+"_"+sample+postfix+"_1d.pdf");
    }      

    if (sample.Contains("_mu")==0) {
      TH2F* eld = (TH2F*) f->Get("Nl"+var+"_histo_e");
      eld->SetTitle("electron fake rate denominator ("+sample+")");
      eld->GetXaxis()->SetTitle("electron p_{T} [GeV]");
      if (var=="_cone") eld->GetXaxis()->SetTitle("electron p_{T}^{corr.} [GeV]");
      if (var=="_jet") eld->GetXaxis()->SetTitle("jet p_{T} [GeV]");
      eld->GetYaxis()->SetTitle("electron |#eta|");
      eld->GetYaxis()->SetTitleOffset(1.2);
      if (postfix=="_extrPtRel") eld->GetYaxis()->SetTitle("H_{T} [GeV]");
      TCanvas c4("c4","c4",600,600);
      eld->SetMarkerSize(1.);
      if (postfix!="_extrPtRel") eld->GetXaxis()->SetNdivisions(6,0);
      eld->Draw("texte");
      c4.RedrawAxis();    
      c4.SaveAs("/home/users/mliu/public_html/fakerate/measurement/pdfs/el_den_fr"+var+"_"+sample+postfix+".pdf");
      TH1D* eld1d_data = eld->ProjectionX();
      eld1d_data->DrawNormalized();
      c4.SaveAs("/home/users/mliu/public_html/fakerate/measurement/pdfs/el_den_fr"+var+"_"+sample+postfix+"_1d.pdf");
    }

  }

      }
  }
}
