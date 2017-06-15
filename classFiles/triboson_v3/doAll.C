{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.6/skim/ttbar_dilep_powheg_skim_6.root");
  ScanChain(ch); 
}