{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-6/userdata/mliu/ZMETbabies/V_test/data_50ns_sm.root");
  ScanChain(ch); 
}