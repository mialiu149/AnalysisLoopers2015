#include "../../commonUtils.h"
void trigStudyEl(bool doIso=false) {

  gROOT->Reset();
  gStyle->SetOptStat(0);

  TString tag = getTag();
  tag = "v1.09FR_80X"; // FIXME
  TString dataf = "/nfs-7/userdata/leptonTree/"+tag+"/2016DoubleEG.root";

  TString mod = "";

  if(doIso) {
      mod = "CaloIdL_TrackIdL_IsoVL_PFJet30";
  } else {
      mod = "CaloIdM_TrackIdM_PFJet30";
  }

  TFile *_file = TFile::Open(dataf);

  TTree* t = (TTree*) _file->Get("t");

  TH1F* total_pt_Ele8 = new TH1F("total_pt_Ele8","total_pt_Ele8",20,0,100);
  total_pt_Ele8->Sumw2();  
  TH1F* total_pt_Ele12 = (TH1F*) total_pt_Ele8->Clone("total_pt_Ele12");
  TH1F* total_pt_Ele17 = (TH1F*) total_pt_Ele8->Clone("total_pt_Ele17");
  TH1F* total_pt_Ele23 = (TH1F*) total_pt_Ele8->Clone("total_pt_Ele23");
  TH1F* total_pt_Ele33 = (TH1F*) total_pt_Ele8->Clone("total_pt_Ele33");

  TH1F* fo_pt_Ele8 = new TH1F("fo_pt_Ele8","fo_pt_Ele8",20,0,100);
  fo_pt_Ele8->Sumw2();  
  TH1F* fo_pt_Ele12 = (TH1F*) fo_pt_Ele8->Clone("fo_pt_Ele12");
  TH1F* fo_pt_Ele17 = (TH1F*) fo_pt_Ele8->Clone("fo_pt_Ele17");
  TH1F* fo_pt_Ele23 = (TH1F*) fo_pt_Ele8->Clone("fo_pt_Ele23");
  TH1F* fo_pt_Ele33 = (TH1F*) fo_pt_Ele8->Clone("fo_pt_Ele33");

  TH1F* tight_pt_Ele8 = new TH1F("tight_pt_Ele8","tight_pt_Ele8",20,0,100);
  tight_pt_Ele8->Sumw2();  
  TH1F* tight_pt_Ele12 = (TH1F*) tight_pt_Ele8->Clone("tight_pt_Ele12");
  TH1F* tight_pt_Ele17 = (TH1F*) tight_pt_Ele8->Clone("tight_pt_Ele17");
  TH1F* tight_pt_Ele23 = (TH1F*) tight_pt_Ele8->Clone("tight_pt_Ele23");
  TH1F* tight_pt_Ele33 = (TH1F*) tight_pt_Ele8->Clone("tight_pt_Ele33");

  TH1F* cuts_pt_Ele8 = new TH1F("cuts_pt_Ele8","cuts_pt_Ele8",20,0,100);
  cuts_pt_Ele8->Sumw2();  
  TH1F* cuts_pt_Ele12 = (TH1F*) cuts_pt_Ele8->Clone("cuts_pt_Ele12");
  TH1F* cuts_pt_Ele17 = (TH1F*) cuts_pt_Ele8->Clone("cuts_pt_Ele17");
  TH1F* cuts_pt_Ele23 = (TH1F*) cuts_pt_Ele8->Clone("cuts_pt_Ele23");
  TH1F* cuts_pt_Ele33 = (TH1F*) cuts_pt_Ele8->Clone("cuts_pt_Ele33");

  TH1F* unw_fo_pt_Ele8 = new TH1F("unw_fo_pt_Ele8","unw_fo_pt_Ele8",20,0,100);
  unw_fo_pt_Ele8->Sumw2();  
  TH1F* unw_fo_pt_Ele12 = (TH1F*) unw_fo_pt_Ele8->Clone("unw_fo_pt_Ele12");
  TH1F* unw_fo_pt_Ele17 = (TH1F*) unw_fo_pt_Ele8->Clone("unw_fo_pt_Ele17");
  TH1F* unw_fo_pt_Ele23 = (TH1F*) unw_fo_pt_Ele8->Clone("unw_fo_pt_Ele23");
  TH1F* unw_fo_pt_Ele33 = (TH1F*) unw_fo_pt_Ele8->Clone("unw_fo_pt_Ele33");

  //all fired (matched, weighted)
  t->Draw("p4.pt()>>total_pt_Ele8" ,"HLT_Ele8_"+mod+"*(HLT_Ele8_"+mod+">0   && abs(id)==11)","goff");
  t->Draw("p4.pt()>>total_pt_Ele12","HLT_Ele12_"+mod+"*(HLT_Ele12_"+mod+">0 && abs(id)==11)","goff");
  t->Draw("p4.pt()>>total_pt_Ele17","HLT_Ele17_"+mod+"*(HLT_Ele17_"+mod+">0 && abs(id)==11)","goff");
  t->Draw("p4.pt()>>total_pt_Ele23","HLT_Ele23_"+mod+"*(HLT_Ele23_"+mod+">0 && abs(id)==11)","goff");
  t->Draw("p4.pt()>>total_pt_Ele33","HLT_Ele33_"+mod+"*(HLT_Ele33_"+mod+">0 && abs(id)==11)","goff");
  
  //fo fired (matched, weighted)
  t->Draw("p4.pt()>>fo_pt_Ele8" ,"HLT_Ele8_"+mod+" *(HLT_Ele8_"+mod+">0  && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Ele12","HLT_Ele12_"+mod+"*(HLT_Ele12_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Ele17","HLT_Ele17_"+mod+"*(HLT_Ele17_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Ele23","HLT_Ele23_"+mod+"*(HLT_Ele23_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>fo_pt_Ele33","HLT_Ele33_"+mod+"*(HLT_Ele33_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  
  //cuts fired (matched, weighted)
  t->Draw("p4.pt()>>cuts_pt_Ele8" ,"HLT_Ele8_"+mod+" *(HLT_Ele8_"+mod+">0  && abs(id)==11 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Ele12","HLT_Ele12_"+mod+"*(HLT_Ele12_"+mod+">0 && abs(id)==11 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Ele17","HLT_Ele17_"+mod+"*(HLT_Ele17_"+mod+">0 && abs(id)==11 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Ele23","HLT_Ele23_"+mod+"*(HLT_Ele23_"+mod+">0 && abs(id)==11 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>cuts_pt_Ele33","HLT_Ele33_"+mod+"*(HLT_Ele33_"+mod+">0 && abs(id)==11 && passes_SS_fo_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  
  //tight fired (matched, weighted)
  t->Draw("p4.pt()>>tight_pt_Ele8" ,"HLT_Ele8_"+mod+" *(HLT_Ele8_"+mod+">0  && abs(id)==11 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Ele12","HLT_Ele12_"+mod+"*(HLT_Ele12_"+mod+">0 && abs(id)==11 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Ele17","HLT_Ele17_"+mod+"*(HLT_Ele17_"+mod+">0 && abs(id)==11 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Ele23","HLT_Ele23_"+mod+"*(HLT_Ele23_"+mod+">0 && abs(id)==11 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  t->Draw("p4.pt()>>tight_pt_Ele33","HLT_Ele33_"+mod+"*(HLT_Ele33_"+mod+">0 && abs(id)==11 && passes_SS_tight_v5 && evt_pfmet<20 && mt<20 && nFOs_SS==1 && ht_SS>40)","goff");
  
  //fo fired (matched, unweighted)
  t->Draw("p4.pt()>>unw_fo_pt_Ele8" ,"(HLT_Ele8_"+mod+">0  && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Ele12","(HLT_Ele12_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Ele17","(HLT_Ele17_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Ele23","(HLT_Ele23_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");
  t->Draw("p4.pt()>>unw_fo_pt_Ele33","(HLT_Ele33_"+mod+">0 && abs(id)==11 && passes_SS_fo_looseMVA_v5)","goff");

  TCanvas c1;
  c1.SetLogy();

  TH1F* paths_total = new TH1F("paths_total","paths_total",5,0,5);
  paths_total->Fill(0.0,total_pt_Ele8->GetEntries());
  paths_total->Fill(1.0,total_pt_Ele12->GetEntries());
  paths_total->Fill(2.0,total_pt_Ele17->GetEntries());
  paths_total->Fill(3.0,total_pt_Ele23->GetEntries());
  paths_total->Fill(4.0,total_pt_Ele33->GetEntries());

  TH1F* paths_fo = new TH1F("paths_fo","paths_fo",40,0,40);
  paths_fo->Fill(0.0,fo_pt_Ele8->GetEntries());
  paths_fo->Fill(1.0,fo_pt_Ele12->GetEntries());
  paths_fo->Fill(2.0,fo_pt_Ele17->GetEntries());
  paths_fo->Fill(3.0,fo_pt_Ele23->GetEntries());
  paths_fo->Fill(4.0,fo_pt_Ele33->GetEntries());
  paths_fo->SetLineColor(kMagenta);

  TH1F* paths_tight = new TH1F("paths_tight","paths_tight",40,0,40);
  paths_tight->Fill(0.0,tight_pt_Ele8->GetEntries());
  paths_tight->Fill(1.0,tight_pt_Ele12->GetEntries());
  paths_tight->Fill(2.0,tight_pt_Ele17->GetEntries());
  paths_tight->Fill(3.0,tight_pt_Ele23->GetEntries());
  paths_tight->Fill(4.0,tight_pt_Ele33->GetEntries());
  paths_tight->SetLineColor(kRed);

  TH1F* paths_cuts = new TH1F("paths_cuts","paths_cuts",40,0,40);
  paths_cuts->Fill(0.0,cuts_pt_Ele8->GetEntries());
  paths_cuts->Fill(1.0,cuts_pt_Ele12->GetEntries());
  paths_cuts->Fill(2.0,cuts_pt_Ele17->GetEntries());
  paths_cuts->Fill(3.0,cuts_pt_Ele23->GetEntries());
  paths_cuts->Fill(4.0,cuts_pt_Ele33->GetEntries());
  paths_cuts->SetLineColor(kGreen);

  TLatex *label = new TLatex();

  paths_total->GetXaxis()->SetBinLabel(1,"Ele8");
  paths_total->GetXaxis()->SetBinLabel(2,"Ele12");
  paths_total->GetXaxis()->SetBinLabel(3,"Ele17");
  paths_total->GetXaxis()->SetBinLabel(4,"Ele23");
  paths_total->GetXaxis()->SetBinLabel(5,"Ele33");
  paths_total->GetYaxis()->SetRangeUser(10,10*total_pt_Ele12->GetEntries());
  paths_total->Draw("hist,text0");
  paths_fo->Draw("hist,text0,same");
  paths_tight->Draw("hist,text0,same");
  paths_cuts->Draw("hist,text0,same");

  label->SetTextColor(kBlue);    label->DrawLatexNDC(0.65,0.85, "all");
  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.65,0.80, "pass FO");
  label->SetTextColor(kGreen);   label->DrawLatexNDC(0.65,0.75, "pass FO+cuts");
  label->SetTextColor(kRed);     label->DrawLatexNDC(0.65,0.70, "pass Tight+cuts");

  c1.SaveAs( doIso ? "pdfs/iso_paths_el.pdf" : "pdfs/paths_el.pdf" );

  TCanvas c2;
  c2.SetLogy();
  unw_fo_pt_Ele8->SetLineColor(kBlack);
  unw_fo_pt_Ele12->SetLineColor(kGreen);
  unw_fo_pt_Ele17->SetLineColor(kBlue);
  unw_fo_pt_Ele23->SetLineColor(kRed);
  unw_fo_pt_Ele33->SetLineColor(kMagenta);
  unw_fo_pt_Ele8->GetYaxis()->SetRangeUser(1,total_pt_Ele12->GetEntries());
  unw_fo_pt_Ele8->Draw("hist");
  unw_fo_pt_Ele12->Draw("hist,same");
  unw_fo_pt_Ele17->Draw("hist,same");
  unw_fo_pt_Ele23->Draw("hist,same");
  unw_fo_pt_Ele33->Draw("hist,same");

  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.8,0.85, "Ele33");
  label->SetTextColor(kRed); label->DrawLatexNDC(0.8,0.80, "Ele23");
  label->SetTextColor(kBlue); label->DrawLatexNDC(0.8,0.75, "Ele17");
  label->SetTextColor(kGreen); label->DrawLatexNDC(0.8,0.70, "Ele12");
  label->SetTextColor(kBlack); label->DrawLatexNDC(0.8,0.65, "Ele8");

  c2.SaveAs( doIso ? "pdfs/iso_unw_pt_el.pdf" : "pdfs/unw_pt_el.pdf" );

  TCanvas c3;
  c3.SetLogy();
  fo_pt_Ele8->SetLineColor(kBlack);
  fo_pt_Ele12->SetLineColor(kGreen);
  fo_pt_Ele17->SetLineColor(kBlue);
  fo_pt_Ele23->SetLineColor(kRed);
  fo_pt_Ele33->SetLineColor(kMagenta);
  fo_pt_Ele8->GetYaxis()->SetRangeUser(50,5000000);
  fo_pt_Ele8->Draw("hist");
  fo_pt_Ele12->Draw("hist,same");
  fo_pt_Ele17->Draw("hist,same");
  fo_pt_Ele23->Draw("hist,same");
  fo_pt_Ele33->Draw("hist,same");

  label->SetTextColor(kMagenta); label->DrawLatexNDC(0.8,0.85, "Ele33");
  label->SetTextColor(kRed); label->DrawLatexNDC(0.8,0.80, "Ele23");
  label->SetTextColor(kBlue); label->DrawLatexNDC(0.8,0.75, "Ele17");
  label->SetTextColor(kGreen); label->DrawLatexNDC(0.8,0.70, "Ele12");
  label->SetTextColor(kBlack); label->DrawLatexNDC(0.8,0.65, "Ele8");

  c3.SaveAs( doIso ? "pdfs/iso_pt_el.pdf" : "pdfs/pt_el.pdf" );

}
