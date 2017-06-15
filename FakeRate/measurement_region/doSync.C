{

  gSystem->Load("../../CORE/CMS3_CORE.so");

  gROOT->ProcessLine(".L ScanChain.C+");

  TChain *syncCh = new TChain("t"); 
  syncCh->Add( "./SyncDoubleMu.root" );
  // syncCh->Add( "./SyncDoubleEG.root" );
  ScanChain(syncCh,"./rate_histos_sync_LooseEMVA.root","useLooseEMVA"); 
  // ScanChain(syncCh,"./rate_histos_sync_LooseEMVA_IsoTrigs.root","useLooseEMVA,IsoTrigs"); 
  
}
