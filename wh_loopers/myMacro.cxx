void myMacro(){
  cout << "Trivial ROOT macro: Hello, World!" << endl;
  TChain* t1 = new TChain("t");
  TChain* t2 = new TChain("t");
  t1->Add("/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim/TChiWH_350_1.root");
  t2->Add("/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/whsignoskim_moriond/TChiWH_350_1.root");
  TCanvas* c = new TCanvas("c","c");
  c->SetGrid(1,1);
  c->cd();
  TH1D* h1= new TH1D("h1","MET [GeV]",40,0,1000);
  TH1D* h2= new TH1D("h2","MET [GeV]",40,0,1000);
  // it sounds like "Cogito, ergo sum" said by HAL9000 ...
  //t1->Draw("pfmet>>h1","ngoodleps==1&&nvetoleps==1&&((lep1_p4.pt()>30&&abs(lep1_pdgid)==11)||(lep1_p4.pt()>25&&abs(lep1_pdgid)==13)&&abs(lep1_p4.eta())<2.1)&&lep1_relIso*lep1_p4.pt() < 5&&ngoodjets==2 && ngoodbtags==2&& pfmet>125 && mt_met_lep>150&&mct>170");
  //t2->Draw("pfmet>>h2","ngoodleps==1&&nvetoleps==1&&((lep1_p4.pt()>30&&abs(lep1_pdgid)==11)||(lep1_p4.pt()>25&&abs(lep1_pdgid)==13)&&abs(lep1_p4.eta())<2.1)&&lep1_relIso*lep1_p4.pt() < 5 &&ngoodjets==2 && ngoodbtags==2&&pfmet>125&& mt_met_lep>150&&mct>170");
  t1->Draw("pfmet>>h1","ngoodleps==1&&nvetoleps==1&&((lep1_p4.pt()>30&&abs(lep1_pdgid)==11)||(lep1_p4.pt()>25&&abs(lep1_pdgid)==13)&&abs(lep1_p4.eta())<2.1)&&lep1_relIso*lep1_p4.pt() < 5&&ngoodjets==2 && ngoodbtags==2&& mt_met_lep>150&&mct>170");
  t2->Draw("pfmet>>h2","ngoodleps==1&&nvetoleps==1&&((lep1_p4.pt()>30&&abs(lep1_pdgid)==11)||(lep1_p4.pt()>25&&abs(lep1_pdgid)==13)&&abs(lep1_p4.eta())<2.1)&&lep1_relIso*lep1_p4.pt() < 5 &&ngoodjets==2&& ngoodbtags==2&& mt_met_lep>150&&mct>170");
  std::cout<<h2->GetEntries()<<std::endl;
  h2->SetLineColor(2);
  h1->DrawNormalized();
  h2->DrawNormalized("same");
  c->SaveAs("~/public_html/sr_nometcut_350_1.pdf");
}
