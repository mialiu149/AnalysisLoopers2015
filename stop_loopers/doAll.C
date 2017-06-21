{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/mliu/onelepbabies/V00-00-02/ttbar_powheg_pythia8_ext3_25ns.root");
  ScanChain(ch); 
}