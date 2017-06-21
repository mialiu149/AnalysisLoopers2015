{

  gROOT->ProcessLine(".L ZMET.cc+");
  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-12_zmet_noiso/ttall_msdecays*.root");
  ScanChain(ch); 
}
