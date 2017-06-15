pair<float,float> normalizeZpeak(float intlumi, TString tag, bool useIsoTrig, bool do8=false /*default is false*/) {

  // we want to output the MTCR SFs so we can lazily chain the macros together
  float sfel, sfmu;

  gStyle->SetOptStat(0);

  for(int doMu = 0; doMu < 2; doMu++) {
  gROOT->Reset();

  TString hlt = (doMu ? "HLT_Mu17" : "HLT_Ele17_CaloIdM_TrackIdM_PFJet30");
  if (useIsoTrig) hlt = (doMu ? "HLT_Mu17_TrkIsoVVL" : "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30");

  if(do8) {
      hlt = (doMu ? "HLT_Mu8" : "HLT_Ele8_CaloIdM_TrackIdM_PFJet30");
      if (useIsoTrig) hlt = (doMu ? "HLT_Mu8_TrkIsoVVL" : "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30");
  }

  TString tag_data = tag;
  // TString tag_data = "v1.12FR";
  // TString tag_data = "v1.13FR";


  float mult = 1.0;

  float e8i = 1.0;
  float e17i = 1.0;
  float e8 = 1.0;
  float e17 = 1.0;

  float m8i = 1.0;
  float m17i = 1.0;
  float m8 = 1.0;
  float m17 = 1.0;


  // // to go from 800/pb SFs to 4/fb SFs
  // e8i *= 0.7625*3.99/0.8042;
  // e17i *= 0.9663*3.99/0.8042;
  // e8 *= 0.7625*3.99/0.8042;
  // e17 *= 0.929*3.99/0.8042;
  // m8i *= 0.758*3.99/0.8042;
  // m17i *= 0.369*3.99/0.8042;
  // m8 *= 0.7528*3.99/0.8042;
  // m17 *= 0.4533*3.99/0.8042;

  // // for 6.26/fb
  // e8i = 17644.6*1.05035;
  // e17i = 1161.41*1.05035;
  // e8 = 17840.6*1.05035;
  // e17 = 1166.48*1.05035;
  // m8i = 3443.22*1.05;
  // m17i = 102.902*1.05;
  // m8 = 6829.05*1.05;
  // m17 = 85.8415*1.05;

  // // dummy to be used to calculate new SF
  // e8i = 1;
  // e17i = 1;
  // e8 = 1;
  // e17 = 1;
  // m8i = 1;
  // m17i = 1;
  // m8 = 1;
  // m17 = 1;

  // // 12.9 fb^-1
  // e8i = 4437.33;
  // e17i = 354.598;
  // e8 = 4434.51;
  // e17 = 355.14;
  // m8i = 1952.23;
  // m17i = 92.9757;
  // m8 = 3956.74;
  // m17 = 65.5245;

  // // go from 12.9 fb^-1 to (12.9-6.26) fb^-1 for Lesya's suggestion to check second HALF
  // e8i *= 1.1784;
  // e17i *= 1.46174;
  // e8 *= 1.17915;
  // e17 *= 1.45954;
  // m8i *= 2.16748;
  // m17i *= 2.96596;
  // m8 *= 2.03015;
  // m17 *= 4.20456;

  // // MATTHIEU's numbers 
  // // for 6.26/fb
  // e8i = 3912.5;
  // e17i = 241.16;
  // e8 = 3912.5;
  // e17 = 241.62;
  // m8i = 1339.7;
  // m17i = 48.035;
  // m8 = 2628.3;
  // m17 = 31.912;

  // // For 22.0/fb JSON
  // e8i = 5251.71;
  // e17i = 483.027;
  // e8 = 5249.37;
  // e17 = 476.482;
  // m8i = 2820.13;
  // m17i = 133.217;
  // m8 = 5707.51;
  // m17 = 98.7317;

  // For 36.8/fb json with reRECO
  e8i = 4208.14;
  e17i = 617.166;
  e8 = 4209.02;
  e17 = 568.98;
  m8i = 3716.07;
  m17i = 181.349;
  m8 = 7361.42;
  m17 = 139.899;

  if(do8) {
      if(useIsoTrig) mult = (doMu ? m8i : e8i);
      else mult = (doMu ? m8 : e8);
  } else {
      if(useIsoTrig) mult = (doMu ? m17i : e17i);
      else mult = (doMu ? m17 : e17);
  }


  TString suffix = (useIsoTrig ? "_IsoTrigs" : "");

  int idlep = (doMu ? 13 : 11); 

  TString dataf = (doMu ? "/nfs-7/userdata/leptonTree/"+tag_data+"/2016DoubleMu*.root" : "/nfs-7/userdata/leptonTree/"+tag_data+"/2016DoubleEG*.root");
  TString dyf = "/nfs-7/userdata/leptonTree/"+tag+"/DY_madgraph*.root";

  TString leptype = (doMu ? "Mu17" : "Ele17");

  TChain* t_data = new TChain("t");
  TChain* t_dy = new TChain("t");
  t_data->Add(dataf);
  t_dy->Add(dyf);

  TH1F* mll_data = new TH1F("mll_data","mll_data",80,0,200);
  TH1F* mll_dy = new TH1F("mll_dy","mll_dy",80,0,200);
  mll_data->Sumw2();  
  mll_dy->Sumw2();

  std::cout << "scanning data" << std::endl;
  // t_data->Draw("dilep_mass>>mll_data",Form("%f*%s*(abs(id)==%i && passes_SS_tight_v5 && %s>0 && tag_p4.pt()>30. && p4.pt()>25.)",mult,hlt.Data(),idlep,hlt.Data()),"goff");
  t_data->Draw("dilep_mass>>mll_data",Form("%f*%s*(abs(id)==%i && passes_SS_tight_v5 && %s>0 && tag_p4.pt()>30. && p4.pt()>25.)",mult,"1",idlep,hlt.Data()),"goff");
  // HALF
  // t_data->Draw("dilep_mass>>mll_data",Form("%f*%s*((evt_run>275782) && abs(id)==%i && passes_SS_tight_v5 && %s>0 && tag_p4.pt()>30. && p4.pt()>25.)",mult,hlt.Data(),idlep,hlt.Data()),"goff");

  hlt = "1";
  std::cout << "scanning mc" << std::endl;
  t_dy->Draw("dilep_mass>>mll_dy",Form("%f*scale1fb*%s*(abs(id)==%i && passes_SS_tight_v5 && %s>0 && tag_p4.pt()>30. && p4.pt()>25.)",intlumi,hlt.Data(),idlep,hlt.Data()),"goff");

  float mc_zpeak   = mll_dy->Integral(mll_dy->FindBin(75),mll_dy->FindBin(105));
  float data_zpeak = mll_data->Integral(mll_data->FindBin(75),mll_data->FindBin(105));

  cout << "doMu=" << doMu << " mc_zpeak=" << mc_zpeak << " data_zpeak=" << data_zpeak << " sf=" << data_zpeak/mc_zpeak << endl;  
  if(doMu) sfmu = data_zpeak/mc_zpeak;
  else sfel = data_zpeak/mc_zpeak;

  TCanvas c1;

  mll_data->SetMarkerStyle(kFullCircle);
  mll_dy->SetFillColor(kGreen+2);
  mll_dy->SetTitle("m_{ll} "+leptype);
  
  //mll_data->Draw("PE");
  mll_dy->Draw("hist");
  mll_data->Draw("PEsame");

  TLegend* leg = new TLegend(0.7,0.7,0.89,0.89);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetHeader(Form("L=%.1f/fb",intlumi));
  leg->AddEntry(mll_data,"data","pe");
  leg->AddEntry(mll_dy  ,"DY","f");
  leg->AddEntry((TObject*)0  ,Form( "SF: %.2f", data_zpeak/mc_zpeak ),"");
  leg->Draw();

  c1.SaveAs( (doMu ? "pdfs/zpeak_mu"+suffix+".pdf" : "pdfs/zpeak_el"+suffix+".pdf") );


  }

  return make_pair(sfel,sfmu);
}
