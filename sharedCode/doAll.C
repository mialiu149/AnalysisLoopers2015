{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/mliu/onelepbabies/V00-00-04/ttbar_powheg_pythia8_25ns_1.root");
  ScanChain(ch); 
}