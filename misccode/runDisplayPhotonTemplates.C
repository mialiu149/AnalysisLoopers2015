{
// #include "displayPhotonTempaltes.C"
  gROOT->ProcessLine(".L displayPhotonTemplates.C+");
  gSystem->Load("../CORE/libCMS2NtupleMacrosCORE.so");  

  // displayPhotonTemplates("Pt15to30");
  // displayPhotonTemplates("Pt30to50");
  // displayPhotonTemplates("Pt50to80");
  // displayPhotonTemplates("Pt80to120");
  // displayPhotonTemplates("Pt120to170");
  // displayPhotonTemplates("Pt170to300");
  // displayPhotonTemplates("Pt300to470");
  // displayPhotonTemplates("Pt470to800");
  // displayPhotonTemplates("Pt800to1400");
  // displayPhotonTemplates("with_calo");

  // displayPhotonTemplates("All_2jetbins");
  displayPhotonTemplates("All_Data_2jetbins");

}
