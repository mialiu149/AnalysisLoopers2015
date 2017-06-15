#include "../../commonUtils.h"
void trigStudyMu(bool doIso=false) {

  gROOT->Reset();
  gStyle->SetOptStat(0);

  TString tag = getTag();
  tag = "v1.09FR_80X"; // FIXME
  TString dataf = "/nfs-7/userdata/leptonTree/"+tag+"/2016DoubleMuon.root";
  //dataf = "SyncDoubleMu.root";

  TString mod = "";

  if(doIso) {
      mod = "_TrkIsoVVL";
  } else {
      mod = "";
  }

  TFile *_file = TFile::Open(dataf);

  TTree* t = (TTree*) _file->Get("t");

  TH1F* total_pt_Mu8 = new TH1F("total_pt_Mu8","total_pt_Mu8",20,0,100);
  total_pt_Mu8->Sumw2();  
  TH1F* total_pt_Mu17 = (TH1F*) total_pt_Mu8->Clone("total_pt_Mu17");
  TH1F* total_pt_Mu24 = (TH1F*) total_pt_Mu8->Clone("total_pt_Mu24");
  TH1F* total_pt_Mu34 = (TH1F*) total_pt_Mu8->Clone("total_pt_Mu34");

  TH1F* fo_pt_Mu8 = new TH1F("fo_pt_Mu8","fo_pt_Mu8",20,0,100);
  fo_pt_Mu8->Sumw2();  
  TH1F* fo_pt_Mu17 = (TH1F*) fo_pt_Mu8->Clone("fo_pt_Mu17");
  TH1F* fo_pt_Mu24 = (TH1F*) fo_pt_Mu8->Clone("fo_pt_Mu24");
  TH1F* fo_pt_Mu34 = (TH1F*) fo_pt_Mu8->Clone("fo_pt_Mu34");

  TH1F* tight_pt_Mu8 = new TH1F("tight_pt_Mu8","tight_pt_Mu8",20,0,100);
  tight_pt_Mu8->Sumw2();  
  TH1F* tight_pt_Mu17 = (TH1F*) tight_pt_Mu8->Clone("tight_pt_Mu17");
  TH1F* tight_pt_Mu24 = (TH1F*) tight_pt_Mu8->Clone("tight_pt_Mu24");
  TH1F* tight_pt_Mu34 = (TH1F*) tight_pt_Mu8->Clone("tight_pt_Mu34");

  TH1F* cuts_pt_Mu8 = new TH1F("cuts_pt_Mu8","cuts_pt_Mu8",20,0,100);
  cuts_pt_Mu8->Sumw2();  
  TH1F* cuts_pt_Mu17 = (TH1F*) cuts_pt_Mu8->Clone("cuts_pt_Mu17");
  TH1F* cuts_pt_Mu24 = (TH1F*) cuts_pt_Mu8->Clone("cuts_pt_Mu24");
  TH1F* cuts_pt_Mu34 = (TH1F*) cuts_pt_Mu8->Clone("cuts_pt_Mu34");

  TH1F* unw_fo_pt_Mu8 = new TH1F("unw_fo_pt_Mu8","unw_fo_pt_Mu8",20,0,100);
  unw_fo_pt_Mu8->Sumw2();  
  TH1F* unw_fo_pt_Mu17 = (TH1F*) unw_fo_pt_Mu8->Clone("unw_fo_pt_Mu17");
  TH1F* unw_fo_pt_Mu24 = (TH1F*) unw_fo_pt_Mu8->Clone("unw_fo_pt_Mu24");
  TH1F* unw_fo_pt_Mu34 = (TH1F*) unw_fo_pt_Mu8->Clone("unw_fo_pt_Mu34");

  t->Draw("p4.pt()>>total_pt_Mu8" ,"HLT_Mu8"+mod+"*(HLT_Mu8"+mod+">0  && abs(id)==13)","goff");// && passes_SS_tight_v5 && HLT_Mu24>0 && tag_p4.pt()>30. && p4.pt()>25.
  t->Draw("p4.pt()>>total_pt_Mu17","HLT_Mu17"+mod+"*(HLT_Mu17"+mod+">0 && abs(id)==13)","goff");
  t->Draw("p4.pt()>>total_pt_Mu24","HLT_Mu24"+mod+"*(HLT_Mu24"+mod+">0 && abs(id)==13)","goff");
  t->Draw("p4.pt()>>total_pt_Mu34","HLT_Mu34"+mod+"*(HLT_Mu34"+mod+">0 && abs(id)==13)","goff");
  
  t->Draw("p4.pt()>>fo_pt_Mu8" ,"HLT_Mu8"+mod+" *(HLT_Mu8"+mod+">0  && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Mu17","HLT_Mu17"+mod+"*(HLT_Mu17"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Mu24","HLT_Mu24"+mod+"*(HLT_Mu24"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Mu34","HLT_Mu34"+mod+"*(HLT_Mu34"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");
    
  t->Draw("p4.pt()>>cuts_pt_Mu8" ,"HLT_Mu8"+mod+" *(HLT_Mu8"+mod+">0  && abs(id)==13 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Mu17","HLT_Mu17"+mod+"*(HLT_Mu17"+mod+">0 && abs(id)==13 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Mu24","HLT_Mu24"+mod+"*(HLT_Mu24"+mod+">0 && abs(id)==13 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Mu34","HLT_Mu34"+mod+"*(HLT_Mu34"+mod+">0 && abs(id)==13 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");

  t->Draw("p4.pt()>>tight_pt_Mu8" ,"HLT_Mu8"+mod+" *(HLT_Mu8"+mod+">0  && abs(id)==13 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Mu17","HLT_Mu17"+mod+"*(HLT_Mu17"+mod+">0 && abs(id)==13 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Mu24","HLT_Mu24"+mod+"*(HLT_Mu24"+mod+">0 && abs(id)==13 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Mu34","HLT_Mu34"+mod+"*(HLT_Mu34"+mod+">0 && abs(id)==13 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  
  t->Draw("p4.pt()>>unw_fo_pt_Mu8" ,"(HLT_Mu8"+mod+">0  && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Mu17","(HLT_Mu17"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Mu24","(HLT_Mu24"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Mu34","(HLT_Mu34"+mod+">0 && abs(id)==13 && passes_SS_fo_v5)","goff");

  TCanvas c1;
  c1.SetLogy();

  TH1F* paths_total = new TH1F("paths_total","paths_total",4,0,4);
  paths_total->Fill(0.0,total_pt_Mu8->GetEntries());
  paths_total->Fill(1.0,total_pt_Mu17->GetEntries());
  paths_total->Fill(2.0,total_pt_Mu24->GetEntries());
  paths_total->Fill(3.0,total_pt_Mu34->GetEntries());
  paths_total->SetLineColor(kBlue);

  TH1F* paths_fo = new TH1F("paths_fo","paths_fo",40,0,40);
  paths_fo->Fill(0.0,fo_pt_Mu8->GetEntries());
  paths_fo->Fill(1.0,fo_pt_Mu17->GetEntries());
  paths_fo->Fill(2.0,fo_pt_Mu24->GetEntries());
  paths_fo->Fill(3.0,fo_pt_Mu34->GetEntries());
  paths_fo->SetLineColor(kMagenta);

  TH1F* paths_tight = new TH1F("paths_tight","paths_tight",40,0,40);
  paths_tight->Fill(0.0,tight_pt_Mu8->GetEntries());
  paths_tight->Fill(1.0,tight_pt_Mu17->GetEntries());
  paths_tight->Fill(2.0,tight_pt_Mu24->GetEntries());
  paths_tight->Fill(3.0,tight_pt_Mu34->GetEntries());
  paths_tight->SetLineColor(kRed);

  TH1F* paths_cuts = new TH1F("paths_cuts","paths_cuts",40,0,40);
  paths_cuts->Fill(0.0,cuts_pt_Mu8->GetEntries());
  paths_cuts->Fill(1.0,cuts_pt_Mu17->GetEntries());
  paths_cuts->Fill(2.0,cuts_pt_Mu24->GetEntries());
  paths_cuts->Fill(3.0,cuts_pt_Mu34->GetEntries());
  paths_cuts->SetLineColor(kGreen);

  TLatex *label = new TLatex();

  paths_total->GetXaxis()->SetBinLabel(1,"Mu8");
  paths_total->GetXaxis()->SetBinLabel(2,"Mu17");
  paths_total->GetXaxis()->SetBinLabel(3,"Mu24");
  paths_total->GetXaxis()->SetBinLabel(4,"Mu34");
  paths_total->GetYaxis()->SetRangeUser(10,10*total_pt_Mu17->GetEntries());
  paths_total->Draw("hist,text0");
  paths_fo->Draw("hist,text0,same");
  paths_tight->Draw("hist,text0,same");
  paths_cuts->Draw("hist,text0,same");


  label->SetTextColor(kBlue);    label->DrawLatexNDC(0.65,0.85, "all");
  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.65,0.80, "pass FO");
  label->SetTextColor(kGreen);   label->DrawLatexNDC(0.65,0.75, "pass FO+cuts");
  label->SetTextColor(kRed);     label->DrawLatexNDC(0.65,0.70, "pass Tight+cuts");

  c1.SaveAs( doIso ? "pdfs/iso_paths_mu.pdf" : "pdfs/paths_mu.pdf" );

  TCanvas c2;
  c2.SetLogy();
  unw_fo_pt_Mu8->SetLineColor(kBlack);
  unw_fo_pt_Mu17->SetLineColor(kBlue);
  unw_fo_pt_Mu24->SetLineColor(kRed);
  unw_fo_pt_Mu34->SetLineColor(kMagenta);
  unw_fo_pt_Mu8->GetYaxis()->SetRangeUser(1,total_pt_Mu17->GetEntries());
  unw_fo_pt_Mu8->Draw("hist");
  unw_fo_pt_Mu17->Draw("hist,same");
  unw_fo_pt_Mu24->Draw("hist,same");
  unw_fo_pt_Mu34->Draw("hist,same");

  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.8,0.85, "Mu34");
  label->SetTextColor(kRed); label->DrawLatexNDC(0.8,0.80, "Mu24");
  label->SetTextColor(kBlue); label->DrawLatexNDC(0.8,0.75, "Mu17");
  label->SetTextColor(kBlack); label->DrawLatexNDC(0.8,0.70, "Mu8");

  c2.SaveAs( doIso ? "pdfs/iso_unw_pt_mu.pdf" : "pdfs/unw_pt_mu.pdf" );


  TCanvas c3;
  c3.SetLogy();
  fo_pt_Mu8->SetLineColor(kBlack);
  fo_pt_Mu17->SetLineColor(kBlue);
  fo_pt_Mu24->SetLineColor(kRed);
  fo_pt_Mu34->SetLineColor(kMagenta);
  fo_pt_Mu8->GetYaxis()->SetRangeUser(1,total_pt_Mu17->GetEntries());
  fo_pt_Mu8->Draw("hist");
  fo_pt_Mu17->Draw("hist,same");
  fo_pt_Mu24->Draw("hist,same");
  fo_pt_Mu34->Draw("hist,same");

  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.8,0.85, "Mu34");
  label->SetTextColor(kRed); label->DrawLatexNDC(0.8,0.80, "Mu24");
  label->SetTextColor(kBlue); label->DrawLatexNDC(0.8,0.75, "Mu17");
  label->SetTextColor(kBlack); label->DrawLatexNDC(0.8,0.70, "Mu8");

  c3.SaveAs( doIso ? "pdfs/iso_pt_mu.pdf" : "pdfs/pt_mu.pdf" );

}
