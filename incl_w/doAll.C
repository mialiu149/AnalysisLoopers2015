{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-6/userdata/mliu/ZMETbabies/V00-00-01/data_50ns_ee.root");
  ScanChain(ch); 
}