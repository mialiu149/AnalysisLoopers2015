{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.9/skim/zz_2l2n_powheg_skim_1.root");
  ScanChain(ch); 
}