{
  gSystem->Exec("mkdir -p plots");
  gSystem->Load("../../CORE/CMS3_CORE.so");
  gSystem->Load("../../triboson_loopers/libSharedCode.so");
  gROOT->ProcessLine(".L ../../software/dataMCplotMaker/PlotMaker2D.cc+");
  gROOT->ProcessLine(".L ../../software/dataMCplotMaker/dataMCplotMaker.cc+");
  gSystem->Load("../../software/tableMaker/libSimpleTable.so");
  gROOT->ProcessLine(".L ../../classFiles/triboson_v0.1.16/triboson.cc+");
  gROOT->ProcessLine(".L ../../sharedCode/histTools.cc+");
  gROOT->ProcessLine(".L ../../commonUtils/commonUtils.h");
  gROOT->ProcessLine(".L ScanChain.C++");

  TString tag1 = getTag();

  bool highhigh   = 1;
  bool highlow    = 0;
  bool lowlow     = 0;

  bool doJetCorr    = 0;
  bool doPtRatioCor = 0;
  bool doConeCorr   = 1;
  bool doData          = 0;

  bool doInSitu        = 0;
  bool testMVA         = 0; // use modified MVA from Lesya in 2015 AN for ISFR
  bool extrPt          = 0; // extra Ptbin for electrons
  bool inclusiveHT     = 0; // use inclusive HT FR

  bool doBonly         = 0;
  bool doTauonly       = 0;
  bool doConly         = 0;
  bool doLightonly     = 0;

  //For both inSitu and not-in-Situ
  bool doLooseEMVA  = 1;

  //These are only for inSitu (choose only one of these)
  bool soup         = 1;
  bool PC           = 0;   
  bool ssZ          = 0;
  bool PCssZ        = 0;

  TString option = "";

  if (doLooseEMVA) option+="_LooseEMVA";

  if (!doInSitu){
    if (doPtRatioCor) option+="_PtRatioCor";
    if (doBonly) option+="_doBonly";
    if (doTauonly) option+="_doTauonly";
    if (doConly) option+="_doConly";
    if (doLightonly) option+="_doLightonly";
    if (doIsoTrigs) option+="_IsoTrigs";
    if (doHTTrigs) option+="_HTTrigs";
  }
  else {
    if (soup) option += "_soup";
    if (PC) option += "_PC";
    if (ssZ) option += "_ssZ";
    if (PCssZ) option += "_PCssZ";
    if (doBonly) option+="_doBonly";
    if (doTauonly) option+="_doTauonly";
    if (doLightonly) option+="_doLightonly";
    if (testMVA) option+="_mva";
    if (extrPt) option+="_ept";
    if (inclusiveHT) option+="_hth";

    option += "_inSitu"; 
  }

  TString ptRegion = "";
  if (highhigh) ptRegion = "HH";
  else if (highlow)  ptRegion = "HL";
  else if (lowlow)   ptRegion = "LL";

  if (doConeCorr) option+="_coneCorr";     //option only for ScanChain
  else if (doJetCorr) option+="_jetCorr";  //option only for ScanChain

  TChain *ch = new TChain("t"); 
  if(doData) {
        // option += "_data";
        std::cout<< "Doing data!" <<  std::endl;
        ch->Add("../../inSituFR/skims_Jan25/Data_skim.root");
  } else {
    if (doLooseEMVA){
        ch->Add("/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.16/skim/ttbar_*mgmlm*_ext1_*");
        ch->Add("/nfs-7/userdata/bhashemi/WWW_babies/WWW_v0.1.16/skim/wjets_*.root");  
   }
    else ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag1+"/TTBAR.root");
  }
  ScanChain(ch, option, ptRegion, doData);
}
