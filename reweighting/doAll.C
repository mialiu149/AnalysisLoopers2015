void doAll( string region = "SRA_bveto", string variable = "pt" )
{

  string iter     = "V00-00-20";

  gROOT->ProcessLine(".L ../sharedCode/ZMET.cc+");
  gROOT->ProcessLine(".L ../sharedCode/AnalysisSelections.cc+");
  gROOT->ProcessLine(".L ../sharedCode/histTools.cc+");
  gROOT->ProcessLine(".L ../sharedCode/METTemplateSelections.cc+");
  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *ch = new TChain("t"); 
  TChain * ch_zjets = new TChain("t");

  TChain * ch_zjets_inc = new TChain("t");
  
  TChain * ch_gjets = new TChain("t");

  ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root", iter.c_str() ));
  ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht*.root"    , iter.c_str() ));
  ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjet_ht*.root"        , iter.c_str() ));

  ScanChain(ch, region, variable ); 
  return;
}
