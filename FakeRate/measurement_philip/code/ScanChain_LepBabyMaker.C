//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "ScanChain_LepBabyMaker.h"

//Switches
bool verbose = 0;
unsigned int evt_cut = 0;
bool addPFCandidates = false; // Default is false
bool checkIsPFTrueFalse = false; // Default is false (requires double loop on recocandidates and pfcandidates)
bool addAnnulus = false; // Default is false
bool recoLeptonsDownTo5GeV = false; // Default is false (meaning 10 GeV)
bool recoLeptonsDownTo20GeV = false; // Default is false (meaning 10 GeV)
bool onlySaveTagProbePairs = false; // Default is false
bool applyJson = true;
bool isDataFromFileName = false;
bool checkMuonTag( unsigned int i, unsigned int& itag );
bool checkElectronTag( unsigned int i, readMVA* v25nsMVAreader, unsigned int& itag );


//________________________________________________________________________________________
void ScanChain_LepBabyMaker( TChain* chain, TString outputname, int nEvents = -1 )
{

    //------------------------------------------------------------------------------------
    // Constant configurations
    //------------------------------------------------------------------------------------
    bool applyJson = true;

    //------------------------------------------------------------------------------------
    // Identifying which sample I am running on based on the output name.
    // Generally not a good idea to have the output name dictate the behavior of the code.
    // But for simplicity I am treating the "outputname" as "options".
    //------------------------------------------------------------------------------------
    isDataFromFileName = outputname.Contains( "Run2015" )
                              || outputname.Contains( "Run2016" );
    bool isPromptReco = outputname.Contains( "PromptReco" ) || isDataFromFileName;
    int bx = outputname.Contains( "Run2015B" ) || outputname.Contains( "50ns" ) ? 50 : 25;
    
    //------------------------------------------------------------------------------------
    // Set good runslist
    //------------------------------------------------------------------------------------
    set_goodrun_file( "goodrunslist/goldenJson_2016rereco_36p46ifb.txt" );
    
    //------------------------------------------------------------------------------------
    // Electrons (MVA)
    //------------------------------------------------------------------------------------
    createAndInitMVA( "./CORE", true, false, 80 ); // Moriond
    readMVA* v25nsMVAreader = new readMVA();
    v25nsMVAreader->InitMVA( "CORE", true );
    
    //------------------------------------------------------------------------------------
    // Jets (JEC)
    //------------------------------------------------------------------------------------
    //JEC files -- 50 ns MC
    std::vector<std::string> jetcorr_filenames_50ns_MC_pfL1;
    std::vector<std::string> jetcorr_filenames_50ns_MC_pfL1L2L3;
    std::vector<std::string> jetcorr_filenames_50ns_MC_pfL2L3;
    jetcorr_filenames_50ns_MC_pfL1.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_50ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_MC_L2L3Residual_AK4PFchs.txt" );
    //JEC files -- 50 ns DATA
    std::vector<std::string> jetcorr_filenames_50ns_DATA_pfL1;
    std::vector<std::string> jetcorr_filenames_50ns_DATA_pfL1L2L3;
    jetcorr_filenames_50ns_DATA_pfL1.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_DATA_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_50ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_DATA_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_50ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_DATA_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_50ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_DATA_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_50ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_50ns/Summer15_50nsV4_DATA_L2L3Residual_AK4PFchs.txt" );
    //JEC files -- 25 ns MC
    std::vector<std::string> jetcorr_filenames_25ns_MC_pfL1;
    std::vector<std::string> jetcorr_filenames_25ns_MC_pfL1L2L3;
    std::vector<std::string> jetcorr_filenames_25ns_MC_pfL2L3;
    jetcorr_filenames_25ns_MC_pfL1.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_25ns_MC_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_MC_L2L3Residual_AK4PFchs.txt" );
    //JEC files -- 25 ns DATA
    std::vector<std::string> jetcorr_filenames_25ns_DATA_pfL1;
    std::vector<std::string> jetcorr_filenames_25ns_DATA_pfL1L2L3;
    std::vector<std::string> jetcorr_filenames_25ns_DATA_pfL2L3;
    jetcorr_filenames_25ns_DATA_pfL1.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L1FastJet_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL1L2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L2L3Residual_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L2Relative_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L3Absolute_AK4PFchs.txt" );
    jetcorr_filenames_25ns_DATA_pfL2L3.push_back( "CORE/Tools/jetcorr/data/run2_25ns/Spring16_25nsV6_DATA_L2L3Residual_AK4PFchs.txt" );
    //Make JEC for each of these
    FactorizedJetCorrector *jet_corrector_50ns_MC_pfL1;
    FactorizedJetCorrector *jet_corrector_50ns_MC_pfL1L2L3;
    FactorizedJetCorrector *jet_corrector_50ns_MC_pfL2L3;
    FactorizedJetCorrector *jet_corrector_50ns_DATA_pfL1;
    FactorizedJetCorrector *jet_corrector_50ns_DATA_pfL1L2L3;
    FactorizedJetCorrector *jet_corrector_25ns_MC_pfL1;
    FactorizedJetCorrector *jet_corrector_25ns_MC_pfL1L2L3;
    FactorizedJetCorrector *jet_corrector_25ns_MC_pfL2L3;
    FactorizedJetCorrector *jet_corrector_25ns_DATA_pfL1;
    FactorizedJetCorrector *jet_corrector_25ns_DATA_pfL1L2L3;
    FactorizedJetCorrector *jet_corrector_25ns_DATA_pfL2L3;
    //Fill the JEC
    jet_corrector_50ns_MC_pfL1 = makeJetCorrector( jetcorr_filenames_50ns_MC_pfL1 );
    jet_corrector_50ns_MC_pfL1L2L3 = makeJetCorrector( jetcorr_filenames_50ns_MC_pfL1L2L3 );
    jet_corrector_50ns_MC_pfL2L3 = makeJetCorrector( jetcorr_filenames_50ns_MC_pfL2L3 );
    jet_corrector_50ns_DATA_pfL1 = makeJetCorrector( jetcorr_filenames_50ns_DATA_pfL1 );
    jet_corrector_50ns_DATA_pfL1L2L3 = makeJetCorrector( jetcorr_filenames_50ns_DATA_pfL1L2L3 );
    jet_corrector_25ns_MC_pfL1 = makeJetCorrector( jetcorr_filenames_25ns_MC_pfL1 );
    jet_corrector_25ns_MC_pfL1L2L3 = makeJetCorrector( jetcorr_filenames_25ns_MC_pfL1L2L3 );
    jet_corrector_25ns_MC_pfL2L3 = makeJetCorrector( jetcorr_filenames_25ns_MC_pfL2L3 );
    jet_corrector_25ns_DATA_pfL1 = makeJetCorrector( jetcorr_filenames_25ns_DATA_pfL1 );
    jet_corrector_25ns_DATA_pfL1L2L3 = makeJetCorrector( jetcorr_filenames_25ns_DATA_pfL1L2L3 );
    jet_corrector_25ns_DATA_pfL2L3 = makeJetCorrector( jetcorr_filenames_25ns_DATA_pfL2L3 );
    //JECs
    FactorizedJetCorrector *jet_corrector_pfL1 = 0;
    FactorizedJetCorrector *jet_corrector_pfL1MC = 0;
    FactorizedJetCorrector *jet_corrector_pfL1L2L3 = 0;
    FactorizedJetCorrector *jet_corrector_pfL2L3 = 0;
    //Record filenames
    std::vector <string> jetcorr_filenames_pfL1;
    std::vector <string> jetcorr_filenames_pfL1L2L3;
    std::vector <string> jetcorr_filenames_pfL2L3;
    
    // retrieve JEC from files, if using
    //// files for RunIISpring15 MC
    if ( bx == 50 && isDataFromFileName )
    {
        jet_corrector_pfL1 = jet_corrector_50ns_DATA_pfL1;
        jet_corrector_pfL1MC = jet_corrector_50ns_MC_pfL1;
        jet_corrector_pfL1L2L3 = jet_corrector_50ns_DATA_pfL1L2L3;
        jet_corrector_pfL2L3 =
            jet_corrector_25ns_MC_pfL2L3; //just a kludge, we will never use this
        jetcorr_filenames_pfL1 = jetcorr_filenames_50ns_DATA_pfL1;
        jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_50ns_DATA_pfL1L2L3;
    }
    else if ( bx == 50 && !isDataFromFileName )
    {
        jet_corrector_pfL1 = jet_corrector_50ns_MC_pfL1;
        jet_corrector_pfL1MC = jet_corrector_50ns_MC_pfL1;
        jet_corrector_pfL2L3 = jet_corrector_50ns_MC_pfL2L3;
        jet_corrector_pfL1L2L3 = jet_corrector_50ns_MC_pfL1L2L3;
        jetcorr_filenames_pfL1 = jetcorr_filenames_50ns_MC_pfL1;
        jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_50ns_MC_pfL1L2L3;
    }
    else if ( bx == 25 && isDataFromFileName )
    {
        jet_corrector_pfL1 = jet_corrector_25ns_DATA_pfL1;
        jet_corrector_pfL1MC = jet_corrector_25ns_MC_pfL1;
        jet_corrector_pfL1L2L3 = jet_corrector_25ns_DATA_pfL1L2L3;
        jet_corrector_pfL2L3 = jet_corrector_25ns_DATA_pfL2L3;
        jetcorr_filenames_pfL1 = jetcorr_filenames_25ns_DATA_pfL1;
        jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_25ns_DATA_pfL1L2L3;
    }
    else if ( bx == 25 && !isDataFromFileName )
    {
        jet_corrector_pfL1 = jet_corrector_25ns_MC_pfL1;
        jet_corrector_pfL1MC = jet_corrector_25ns_MC_pfL1;
        jet_corrector_pfL1L2L3 = jet_corrector_25ns_MC_pfL1L2L3;
        jet_corrector_pfL2L3 = jet_corrector_25ns_MC_pfL2L3;
        jetcorr_filenames_pfL1 = jetcorr_filenames_25ns_MC_pfL1;
        jetcorr_filenames_pfL1L2L3 = jetcorr_filenames_25ns_MC_pfL1L2L3;
    }

    //------------------------------------------------------------------------------------
    // Output TTree
    //------------------------------------------------------------------------------------
    TFile* ofile = new TFile(outputname.ReplaceAll(".root", "_tree.root"), "recreate");
    TTree* otree = new TTree("t", "Lepton Baby");

    //-----------------------------------------------------
    // List of variables to calculate and fill output TTree
    //-----------------------------------------------------

    // Event-wide variable
    int event = -999;
    int lumiBlock = -999;
    int run = -999;
    int isRealData = -999;
    float scale1fb = -999;     
    float evt_corrMET = -999;
    float evt_corrMETPhi = -999;
    float ht = -999;  
    int nlep_VVV_cutbased_fo = -999;
    int nvtx = -999;
    // Jets
    vector <LorentzVector> jets;
    vector <float> jets_disc; 
    vector <float> jets_area; 
    vector <float> jets_undoJEC; 
    // Lepton
    LorentzVector p4;
    LorentzVector dilep_p4;
    int idx = -999;
    // pdgIds
    int id = -999;
    int motherID = -999;
    int mc_id = -999;
    // IPs
    float dxyPV = -999;
    float dZ = -999;
    float dxyPV_err = -999;
    float ip3d = -999;
    float ip3derr = -999;
    // Isos
    float RelIso03 = -999; //RelIso03 (not corrected)
    float RelIso03EA = -999; //RelIso03 (EffectiveArea corrected)
    float RelIso03DB = -999; //RelIso03 (DeltaBeta corrected)
    float tkIso = -999;
    float miniiso = -999;
    float miniisoDB = -999;
    // IDs
    bool passes_VVV_cutbased_veto = -999;
    bool passes_VVV_cutbased_veto_noiso = -999;
    bool passes_VVV_cutbased_veto_noiso_noip = -999;
    bool passes_VVV_cutbased_fo = -999;
    bool passes_VVV_cutbased_fo_noiso = -999;
    bool passes_VVV_cutbased_tight = -999;
    bool passes_VVV_cutbased_tight_noiso = -999;
    bool passes_VVV_MVAbased_tight = -999;
    bool passes_VVV_MVAbased_tight_noiso = -999;
    bool passes_VVV_baseline = -999;
    // Nearby jets
    LorentzVector jet_close_lep;
    float jet_close_lep_undoJEC = -999;
    float jet_close_L1 = -999;
    float jet_close_L2L3 = -999;
    // Auxiliary variables
    float dilep_mass = -999;
    // Electron related
    float sigmaIEtaIEta_full5x5 = -999;
    float etaSC = -999;
    float dEtaIn = -999;
    float dPhiIn = -999;
    float hOverE = -999;
    float ecalEnergy = -999;
    float eOverPIn = -999;
    bool conv_vtx_flag = -999;
    int charge = -999;
    float mva_25ns = -999;
    float tag_mva_25ns = -999;
    float ecalPFClusterIso = -999;
    float hcalPFClusterIso = -999;
    // Triggers
    int HLT_Mu8 = -999;
    int HLT_Mu17 = -999;
    int HLT_Mu8_TrkIsoVVL = -999;
    int HLT_Mu17_TrkIsoVVL = -999;
    int HLT_IsoMu24 = -999;
    int HLT_IsoTkMu24 = -999;
    int HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -999;
    int HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -999;
    int HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
    int HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;

    otree->Branch("evt_event"                                , &event                                    );
    otree->Branch("evt_lumiBlock"                            , &lumiBlock                                );
    otree->Branch("evt_run"                                  , &run                                      );
    otree->Branch("evt_isRealData"                           , &isRealData                               );
    otree->Branch("scale1fb"                                 , &scale1fb                                 );
    otree->Branch("evt_corrMET"                              , &evt_corrMET                              );
    otree->Branch("evt_corrMETPhi"                           , &evt_corrMETPhi                           );
    otree->Branch("ht"                                       , &ht                                       );
    otree->Branch("jets"                                     , &jets                                     );
    otree->Branch("jets_disc"                                , &jets_disc                                );
    otree->Branch("jets_area"                                , &jets_area                                );
    otree->Branch("jets_undoJEC"                             , &jets_undoJEC                             );
    otree->Branch("nlep_VVV_cutbased_fo"                     , &nlep_VVV_cutbased_fo                     );
    otree->Branch("nvtx"                                     , &nvtx                                     );
    otree->Branch("p4"                                       , &p4                                       );
    otree->Branch("dilep_p4"                                 , &dilep_p4                                 );
    otree->Branch("id"                                       , &id                                       );
    otree->Branch("idx"                                      , &idx                                      );
    otree->Branch("dxyPV"                                    , &dxyPV                                    );
    otree->Branch("dZ"                                       , &dZ                                       );
    otree->Branch("dxyPV_err"                                , &dxyPV_err                                );
    otree->Branch("motherID"                                 , &motherID                                 );
    otree->Branch("mc_id"                                    , &mc_id                                    );
    otree->Branch("RelIso03"                                 , &RelIso03                                 );
    otree->Branch("RelIso03EA"                               , &RelIso03EA                               );
    otree->Branch("RelIso03DB"                               , &RelIso03DB                               );
    otree->Branch("tkIso"                                    , &tkIso                                    );
    otree->Branch("passes_VVV_cutbased_veto"                 , &passes_VVV_cutbased_veto                 );
    otree->Branch("passes_VVV_cutbased_veto_noiso"           , &passes_VVV_cutbased_veto_noiso           );
    otree->Branch("passes_VVV_cutbased_veto_noiso_noip"      , &passes_VVV_cutbased_veto_noiso_noip      );
    otree->Branch("passes_VVV_cutbased_fo"                   , &passes_VVV_cutbased_fo                   );
    otree->Branch("passes_VVV_cutbased_fo_noiso"             , &passes_VVV_cutbased_fo_noiso             );
    otree->Branch("passes_VVV_cutbased_tight_noiso"          , &passes_VVV_cutbased_tight_noiso          );
    otree->Branch("passes_VVV_cutbased_tight"                , &passes_VVV_cutbased_tight                );
    otree->Branch("passes_VVV_MVAbased_tight_noiso"          , &passes_VVV_MVAbased_tight_noiso          );
    otree->Branch("passes_VVV_MVAbased_tight"                , &passes_VVV_MVAbased_tight                );
    otree->Branch("passes_VVV_baseline"                      , &passes_VVV_baseline                      );
    otree->Branch("ip3d"                                     , &ip3d                                     );
    otree->Branch("ip3derr"                                  , &ip3derr                                  );
    otree->Branch("miniiso"                                  , &miniiso                                  );
    otree->Branch("miniisoDB"                                , &miniisoDB                                );
    otree->Branch("dilep_mass"                               , &dilep_mass                               );
    otree->Branch("sigmaIEtaIEta_full5x5"                    , &sigmaIEtaIEta_full5x5                    );
    otree->Branch("etaSC"                                    , &etaSC                                    );
    otree->Branch("dEtaIn"                                   , &dEtaIn                                   );
    otree->Branch("dPhiIn"                                   , &dPhiIn                                   );
    otree->Branch("hOverE"                                   , &hOverE                                   );
    otree->Branch("ecalEnergy"                               , &ecalEnergy                               );
    otree->Branch("conv_vtx_flag"                            , &conv_vtx_flag                            );
    otree->Branch("charge"                                   , &charge                                   );
    otree->Branch("mva_25ns"                                 , &mva_25ns                                 );
    otree->Branch("tag_mva_25ns"                             , &tag_mva_25ns                             );
    otree->Branch("ecalPFClusterIso"                         , &ecalPFClusterIso                         );
    otree->Branch("hcalPFClusterIso"                         , &hcalPFClusterIso                         );
    otree->Branch("HLT_Mu8"                                  , &HLT_Mu8                                  );
    otree->Branch("HLT_Mu17"                                 , &HLT_Mu17                                 );
    otree->Branch("HLT_Mu8_TrkIsoVVL"                        , &HLT_Mu8_TrkIsoVVL                        );
    otree->Branch("HLT_Mu17_TrkIsoVVL"                       , &HLT_Mu17_TrkIsoVVL                       );
    otree->Branch("HLT_IsoMu24"                              , &HLT_IsoMu24                              );
    otree->Branch("HLT_IsoTkMu24"                            , &HLT_IsoTkMu24                            );
    otree->Branch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30"        , &HLT_Ele8_CaloIdM_TrackIdM_PFJet30        );
    otree->Branch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30"       , &HLT_Ele17_CaloIdM_TrackIdM_PFJet30       );
    otree->Branch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30"  , &HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30  );
    otree->Branch("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30" , &HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 );

    
    //------------------------------------------------------------------------------------
    //
    // Main Loop
    //
    //------------------------------------------------------------------------------------
    TasUtil::Looper<CMS3> looper( chain, &cms3, nEvents );
    
    while ( looper.nextEvent() )
    {

        //-------------------
        // Reset TTree values
        //-------------------
        // Event-wide variable
        event = -999;
        lumiBlock = -999;
        run = -999;
        evt_corrMET = -999;
        evt_corrMETPhi = -999;
        scale1fb = -999;     
        ht = 0;  
        nlep_VVV_cutbased_fo = 0;
        nvtx = 0;
        // Jets
        jets.clear();
        jets_disc.clear(); 
        jets_area.clear(); 
        jets_undoJEC.clear(); 
        // Lepton
        p4.SetXYZT(0, 0, 0, 0);
        dilep_p4.SetXYZT(0, 0, 0, 0);
        idx = -999;
        // pdgIds
        id = -999;
        motherID = -999;
        mc_id = -999;
        // IPs
        dxyPV = -999;
        dZ = -999;
        dxyPV_err = -999;
        ip3d = -999;
        ip3derr = -999;
        // Isos
        RelIso03 = -999; //RelIso03 (not corrected)
        RelIso03EA = -999; //RelIso03 (EffectiveArea corrected)
        RelIso03DB = -999; //RelIso03 (DeltaBeta corrected)
        tkIso = -999;
        miniiso = -999;
        miniisoDB = -999;
        // IDs
        passes_VVV_cutbased_veto = -999;
        passes_VVV_cutbased_veto_noiso = -999;
        passes_VVV_cutbased_veto_noiso_noip = -999;
        passes_VVV_cutbased_fo = -999;
        passes_VVV_cutbased_fo_noiso = -999;
        passes_VVV_cutbased_tight = -999;
        passes_VVV_cutbased_tight_noiso = -999;
        passes_VVV_MVAbased_tight = -999;
        passes_VVV_MVAbased_tight_noiso = -999;
        passes_VVV_baseline = -999;
        // Auxiliary variables
        dilep_mass = -999;
        // Electron related
        sigmaIEtaIEta_full5x5 = -999;
        etaSC = -999;
        dEtaIn = -999;
        dPhiIn = -999;
        hOverE = -999;
        ecalEnergy = -999;
        eOverPIn = -999;
        conv_vtx_flag = -999;
        charge = -999;
        mva_25ns = -999;
        tag_mva_25ns = -999;
        ecalPFClusterIso = -999;
        hcalPFClusterIso = -999;
        // Triggers
        HLT_Mu8 = -999;
        HLT_Mu17 = -999;
        HLT_Mu8_TrkIsoVVL = -999;
        HLT_Mu17_TrkIsoVVL = -999;
        HLT_IsoMu24 = -999;
        HLT_IsoTkMu24 = -999;
        HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -999;
        HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -999;
        HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
        HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;

        //---------------------
        // Check good runs list
        //---------------------
        if ( applyJson && evt_isRealData()
                && !goodrun( evt_run(), evt_lumiBlock() ) )
            continue;
            
        // Why? idk.
        if ( evt_isRealData() && isPromptReco && evt_run() <= 251562 )
            continue;

        //--------------
        // Sanity checks
        //--------------
        if ( mus_dxyPV().size() != mus_dzPV().size() )
            continue;

        //----------------
        // Event variables
        //----------------
        event = evt_event();
        lumiBlock = evt_lumiBlock();
        run = evt_run();
        isRealData = evt_isRealData();
        scale1fb = evt_isRealData() ? 1 : evt_scale1fb();
        nvtx = 0;
        for ( unsigned int ivtx = 0; ivtx < evt_nvtxs(); ivtx++ )
            if ( isGoodVertex( ivtx ) )
                nvtx++;
        // Not in TTree but for calculation in between
        float rho = evt_fixgridfastjet_all_rho();
        float rho_neut_centr = evt_fixgridfastjet_centralneutral_rho();
        float rho_calo = evt_fixgridfastjet_allcalo_rho();
        float rho_calo_centr = evt_fixgridfastjet_centralcalo_rho();

        //--------------
        // MET variables
        //--------------
        metStruct trackMetStruct =  trackerMET(0.2);
        pair<float,float> corrMETPair = getT1CHSMET_fromMINIAOD(jet_corrector_pfL1L2L3);
        evt_corrMET    = corrMETPair.first;
        evt_corrMETPhi = corrMETPair.second;

        //---------
        // Jet Loop
        //---------
        for ( unsigned int i = 0; i < pfjets_p4().size(); i++ )
        {

            LorentzVector raw_jet = pfjets_p4()[i] * pfjets_undoJEC()[i];

            //Require loose jet ID
            if ( !isLoosePFJet_Summer16_v1( i ) )
                continue;

            float jet_L1L2L3 = 1.;

            if ( jetcorr_filenames_pfL1L2L3.size() > 0 )
            {
                //L1L2L3
                jet_corrector_pfL1L2L3->setJetEta( raw_jet.eta() );
                jet_corrector_pfL1L2L3->setJetPt( raw_jet.pt() );
                jet_corrector_pfL1L2L3->setJetA( pfjets_area()[i] );
                jet_corrector_pfL1L2L3->setRho( rho );
                jet_L1L2L3 = jet_corrector_pfL1L2L3->getCorrection();
            }

            LorentzVector jet = raw_jet * jet_L1L2L3;

            //Kinematic jet cuts
            if ( jet.pt() < 25 )
                continue;

            //Save jets that make it this far
            jets.push_back( jet );

            //HT is sum of jets with pT > 40
            if ( jet.pt() > 40 )
                ht += jet.pt();

            //Save b-tags
            float disc = pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag()[i];
            jets_disc.push_back( disc );
            jets_area.push_back( pfjets_area()[i] );
            jets_undoJEC.push_back( pfjets_undoJEC()[i] );

        }

        //-------------
        // Counting nFO
        //----------
        for ( unsigned int i = 0; i < mus_p4().size(); i++)
            if ( muonID( i, VVV_cutbased_fo ) && mus_p4()[i].pt() > 10 )
                nlep_VVV_cutbased_fo++;

        for ( unsigned int i = 0; i < els_p4().size(); i++)
            if ( electronID( i, VVV_cutbased_fo ) && els_p4()[i].pt() > 10 )
                nlep_VVV_cutbased_fo++;

        //----------
        // Muon Loop
        //----------
        for ( unsigned int i = 0; i < mus_p4().size(); i++)
        {

            // Lepton
            p4.SetXYZT(0, 0, 0, 0);
            dilep_p4.SetXYZT(0, 0, 0, 0);
            idx = -999;
            // pdgIds
            id = -999;
            motherID = -999;
            mc_id = -999;
            // IPs
            dxyPV = -999;
            dZ = -999;
            dxyPV_err = -999;
            ip3d = -999;
            ip3derr = -999;
            // Isos
            RelIso03 = -999; //RelIso03 (not corrected)
            RelIso03EA = -999; //RelIso03 (EffectiveArea corrected)
            RelIso03DB = -999; //RelIso03 (DeltaBeta corrected)
            tkIso = -999;
            miniiso = -999;
            miniisoDB = -999;
            // IDs
            passes_VVV_cutbased_veto = -999;
            passes_VVV_cutbased_veto_noiso = -999;
            passes_VVV_cutbased_veto_noiso_noip = -999;
            passes_VVV_cutbased_fo = -999;
            passes_VVV_cutbased_fo_noiso = -999;
            passes_VVV_cutbased_tight = -999;
            passes_VVV_cutbased_tight_noiso = -999;
            passes_VVV_MVAbased_tight = -999;
            passes_VVV_MVAbased_tight_noiso = -999;
            passes_VVV_baseline = -999;
            // Auxiliary variables
            dilep_mass = -999;
            // Electron related
            sigmaIEtaIEta_full5x5 = -999;
            etaSC = -999;
            dEtaIn = -999;
            dPhiIn = -999;
            hOverE = -999;
            ecalEnergy = -999;
            eOverPIn = -999;
            conv_vtx_flag = -999;
            charge = -999;
            mva_25ns = -999;
            tag_mva_25ns = -999;
            ecalPFClusterIso = -999;
            hcalPFClusterIso = -999;
            // Triggers
            HLT_Mu8 = -999;
            HLT_Mu17 = -999;
            HLT_Mu8_TrkIsoVVL = -999;
            HLT_Mu17_TrkIsoVVL = -999;
            HLT_IsoMu24 = -999;
            HLT_IsoTkMu24 = -999;
            HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -999;
            HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -999;
            HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
            HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;

            if (!( mus_p4()[i].pt() > 10 ))
                continue;

            // Check for a tag muon (loop inside a loop)
            unsigned int itag = 0;
            bool foundtag = checkMuonTag( i, itag );

            // Check Muon ID
            if ( muonID( i, VVV_cutbased_veto_noiso_noip ) == 0 && foundtag == false )
                continue;

            // Dilepton stuff
            if ( foundtag )
            {
                dilep_p4 = p4 + mus_p4()[itag];
                dilep_mass = dilep_p4.M();
            }

            // Set lepton entry variable to this muon
            id = -13.0 * mus_charge()[i];
            idx = i;
            p4 = mus_p4()[i];

            //MC stuff

            if ( !evt_isRealData() )
            {
                motherID = lepMotherID( Lep( id, idx ) );
                mc_id = mus_mc_id()[i];
            }

            //Impact parameter
            dxyPV = mus_dxyPV()[i];
            dxyPV_err = mus_d0Err()[i];
            dZ = mus_dzPV()[i];
            ip3d = mus_ip3d()[i];
            ip3derr = mus_ip3derr()[i];
            //Isolation et al
            RelIso03 = ( mus_isoR03_pf_ChargedHadronPt()[i] + mus_isoR03_pf_NeutralHadronEt()[i] + mus_isoR03_pf_PhotonEt()[i] ) /
                mus_p4()[i].pt();
            RelIso03EA = muRelIso03EA( i );
            RelIso03DB = muRelIso03DB( i );
            tkIso = mus_iso03_sumPt()[i];
            miniiso = muMiniRelIsoCMS3_EA( i, 1 );
            miniisoDB = muMiniRelIsoCMS3_DB( i );

            // Save VVV ID bools
            if ( muonID( i, VVV_cutbased_veto ) )
                passes_VVV_cutbased_veto = true;

            if ( muonID( i, VVV_cutbased_veto_noiso ) )
                passes_VVV_cutbased_veto_noiso = true;

            if ( muonID( i, VVV_cutbased_veto_noiso_noip ) )
                passes_VVV_cutbased_veto_noiso_noip = true;

            if ( muonID( i, VVV_cutbased_fo ) )
                passes_VVV_cutbased_fo = true;

            if ( muonID( i, VVV_cutbased_fo_noiso ) )
                passes_VVV_cutbased_fo_noiso = true;

            if ( muonID( i, VVV_cutbased_tight ) )
                passes_VVV_cutbased_tight = true;

            if ( muonID( i, VVV_cutbased_tight_noiso ) )
                passes_VVV_cutbased_tight_noiso = true;

            if ( muonID( i, VVV_baseline ) )
                passes_VVV_baseline = true;

            setHLTBranch( "HLT_Mu8_v"            , mus_HLT_Mu8()[i]            , HLT_Mu8            );
            setHLTBranch( "HLT_Mu17_v"           , mus_HLT_Mu17()[i]           , HLT_Mu17           );
            setHLTBranch( "HLT_Mu8_TrkIsoVVL_v"  , mus_HLT_Mu8_TrkIsoVVL()[i]  , HLT_Mu8_TrkIsoVVL  );
            setHLTBranch( "HLT_Mu17_TrkIsoVVL_v" , mus_HLT_Mu17_TrkIsoVVL()[i] , HLT_Mu17_TrkIsoVVL );
            setHLTBranch( "HLT_IsoMu24_v"        , mus_HLT_IsoMu24()[i]        , HLT_IsoMu24        );
            setHLTBranch( "HLT_IsoTkMu24_v"      , mus_HLT_IsoTkMu24()[i]      , HLT_IsoTkMu24      );

            otree->Fill();

        }

        //--------------
        // Electron Loop
        //--------------
        for ( unsigned int i = 0; i < els_p4().size(); i++)
        {

            // Lepton
            p4.SetXYZT(0, 0, 0, 0);
            dilep_p4.SetXYZT(0, 0, 0, 0);
            idx = -999;
            // pdgIds
            id = -999;
            motherID = -999;
            mc_id = -999;
            // IPs
            dxyPV = -999;
            dZ = -999;
            dxyPV_err = -999;
            ip3d = -999;
            ip3derr = -999;
            // Isos
            RelIso03 = -999; //RelIso03 (not corrected)
            RelIso03EA = -999; //RelIso03 (EffectiveArea corrected)
            RelIso03DB = -999; //RelIso03 (DeltaBeta corrected)
            tkIso = -999;
            miniiso = -999;
            miniisoDB = -999;
            // IDs
            passes_VVV_cutbased_veto = -999;
            passes_VVV_cutbased_veto_noiso = -999;
            passes_VVV_cutbased_veto_noiso_noip = -999;
            passes_VVV_cutbased_fo = -999;
            passes_VVV_cutbased_fo_noiso = -999;
            passes_VVV_cutbased_tight = -999;
            passes_VVV_cutbased_tight_noiso = -999;
            passes_VVV_MVAbased_tight = -999;
            passes_VVV_MVAbased_tight_noiso = -999;
            passes_VVV_baseline = -999;
            // Auxiliary variables
            dilep_mass = -999;
            // Electron related
            sigmaIEtaIEta_full5x5 = -999;
            etaSC = -999;
            dEtaIn = -999;
            dPhiIn = -999;
            hOverE = -999;
            ecalEnergy = -999;
            eOverPIn = -999;
            conv_vtx_flag = -999;
            charge = -999;
            mva_25ns = -999;
            tag_mva_25ns = -999;
            ecalPFClusterIso = -999;
            hcalPFClusterIso = -999;
            // Triggers
            HLT_Mu8 = -999;
            HLT_Mu17 = -999;
            HLT_Mu8_TrkIsoVVL = -999;
            HLT_Mu17_TrkIsoVVL = -999;
            HLT_IsoMu24 = -999;
            HLT_IsoTkMu24 = -999;
            HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = -999;
            HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = -999;
            HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;
            HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = -999;


            if (!( els_p4()[i].pt() > 10 ))
                continue;

            // Check for a tag muon (loop inside a loop)
            unsigned int itag = 0;
            bool foundtag = checkElectronTag( i, v25nsMVAreader, itag );

            // Check Muon ID
            if ( electronID( i, VVV_cutbased_veto_noiso_noip ) == 0 && foundtag == false )
                continue;

            // Dilepton stuff
            if ( foundtag )
            {
                dilep_p4 = p4 + els_p4()[itag];
                dilep_mass = dilep_p4.M();
            }

            // Set lepton entry variable to this muon
            id = -11.0 * els_charge()[i];
            idx = i;
            p4 = els_p4()[i];

            //MC stuff

            if ( !evt_isRealData() )
            {
                motherID = lepMotherID( Lep( id, idx ) );
                mc_id = els_mc_id()[i];
            }

            //Impact parameter
            dxyPV = els_dxyPV()[i];
            dxyPV_err = els_d0Err()[i];
            dZ = els_dzPV()[i];
            ip3d = els_ip3d()[i];
            ip3derr = els_ip3derr()[i];
            //Isolation et al
            RelIso03 = ( els_pfChargedHadronIso()[i] + els_pfNeutralHadronIso()[i] + els_pfPhotonIso()[i] ) / els_p4()[i].pt();
            RelIso03EA = eleRelIso03EA( i );
            RelIso03DB = eleRelIso03DB( i );
            tkIso = els_tkIso()[i];
            miniiso = elMiniRelIsoCMS3_EA( i, 1 );
            miniisoDB = elMiniRelIsoCMS3_DB( i );
            // Other electron stuff
            sigmaIEtaIEta_full5x5 = els_sigmaIEtaIEta_full5x5().at(i);
            etaSC = els_etaSC().at(i);
            dEtaIn = els_dEtaIn().at(i);
            dPhiIn = els_dPhiIn().at(i);
            hOverE = els_hOverE().at(i);
            ecalEnergy = els_ecalEnergy().at(i);
            eOverPIn = els_eOverPIn().at(i);
            conv_vtx_flag = els_conv_vtx_flag().at(i);

            // VVV
            if ( electronID( i, VVV_cutbased_veto ) )
                passes_VVV_cutbased_veto = true;

            if ( electronID( i, VVV_cutbased_veto_noiso ) )
                passes_VVV_cutbased_veto_noiso = true;

            if ( electronID( i, VVV_cutbased_veto_noiso_noip ) )
                passes_VVV_cutbased_veto_noiso_noip = true;

            if ( electronID( i, VVV_cutbased_fo ) )
                passes_VVV_cutbased_fo = true;

            if ( electronID( i, VVV_cutbased_fo_noiso ) )
                passes_VVV_cutbased_fo_noiso = true;

            if ( electronID( i, VVV_cutbased_tight ) )
                passes_VVV_cutbased_tight = true;

            if ( electronID( i, VVV_cutbased_tight_noiso ) )
                passes_VVV_cutbased_tight_noiso = true;

            if ( electronID( i, VVV_MVAbased_tight_noiso ) )
                passes_VVV_MVAbased_tight_noiso = true;

            if ( electronID( i, VVV_MVAbased_tight ) )
                passes_VVV_MVAbased_tight = true;

            if ( electronID( i, VVV_baseline ) )
                passes_VVV_baseline = true;

            setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,        els_HLT_Ele8_CaloIdM_TrackIdM_PFJet30_ElectronLeg()[i]  ,  HLT_Ele8_CaloIdM_TrackIdM_PFJet30 );
            setHLTBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v",        els_HLT_Ele17_CaloIdM_TrackIdM_PFJet30_ElectronLeg()[i] , HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
            setHLTBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v",   els_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg()[i]  ,  HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
            setHLTBranch("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  els_HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_ElectronLeg()[i] , HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30);

            otree->Fill();

        }

    } // end of main loop

    ofile->cd();
    otree->Write();
    
}

//________________________________________________________________________________________
bool checkMuonTag( unsigned int i, unsigned int& itag )
{
    for ( unsigned int j = 0; j < mus_p4().size(); j++ )
    {
        if ( i == j )
            continue;

        if ( mus_p4()[j].pt() < 20.0 )
            continue;

        if ( fabs( mus_p4()[j].eta() ) > 2.4 )
            continue;

        if ( fabs( mus_dxyPV()[j] ) > 0.02 )
            continue;

        if ( fabs( mus_dzPV()[j] ) > 0.05 )
            continue;

        if ( fabs( mus_ip3d()[j] / mus_ip3derr()[j] ) > 4 )
            continue;

        if ( !isTightMuonPOG( j ) )
            continue;

        if ( muRelIso03EA( j ) > 0.2 )
            continue;

        itag = j;

        return true;

    }

    return false;
}

//________________________________________________________________________________________
bool checkElectronTag( unsigned int i, readMVA* v25nsMVAreader, unsigned int& itag )
{
    for ( unsigned int j = 0; j < tas::els_p4().size(); j++ )
    {
        if ( i == j )
            continue;

        if ( tas::els_p4().at( j ).pt() < 20.0 )
            continue;

        if ( fabs( tas::els_etaSC().at( j ) ) > 2.5 )
            continue;

        if ( !tas::els_passMediumId().at( j ) )
            continue;

        if ( fabs( tas::els_ip3d().at( j ) / tas::els_ip3derr().at( j ) ) > 4 )
            continue;

        itag = j;

        return true;
    }

    return false;
}
