{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/mliu/jes_nominal_wbtag/TTZToLLNuNu.root");
  ScanChain(ch); 
}