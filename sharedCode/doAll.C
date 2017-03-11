{

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  ch->Add("/nfs-7/userdata/mliu/tupler_babies/merged/onelepbabymaker/moriond2017.v14/output/data_single_electron_Run2016B_MINIAOD_23Sep2016-v3.root");
  ScanChain(ch); 
}