{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/leptonTree/ReRecoDataMoriondMC_2020_4Feb17/DY_madgraph.root");
  ScanChain(ch); 
}