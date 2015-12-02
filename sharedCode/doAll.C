{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-6/userdata/mliu/onelepbabies/V00-00-01/DYJetsToLL_m10To50_amcnlo_pythia8_25ns.root");
  ScanChain(ch); 
}