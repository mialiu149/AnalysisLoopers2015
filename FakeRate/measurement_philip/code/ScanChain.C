//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "ScanChain.h"

int nptbins = 7;
double ptbins[8] = {10., 15., 20., 25., 30., 35., 50., 120.};

int nptbins_coarse = 6;
double ptbins_coarse[7] = {10., 15., 20., 25., 30., 35., 70.};

int netabins = 3;
double etabins_mu[4] = {0., 1.2, 2.1, 2.4};
double etabins_el[4] = {0., 0.8, 1.479, 2.5};

bool isData = false;

int evt_event_to_print = 310504089;

// Rebuilding event level variables

int prev_evt_event = 0;
std::vector<Lepton> leptons;

//========================================================================================
//
//
// Main Looper
//
//
//========================================================================================
//________________________________________________________________________________________
void ScanChain( TChain* chain, TString outputname, int nEvents = -1 )
{

    //------------------------------------------------------------------------------------
    // Identifying which sample I am running on based on the output name.
    // Generally not a good idea to have the output name dictate the behavior of the code.
    // But for simplicity I am treating the "outputname" as "options".
    //------------------------------------------------------------------------------------
    isData = outputname.Contains( "2016" )
        || outputname.Contains( "Double" ); // made it global so i can use in other functions. (Not pretty though.)
    bool isDoubleMuon = outputname.Contains( "DoubleMuon" ) || outputname.Contains( "doublemuon" );
    bool isEWK = ( outputname.Contains( "WJets" ) || outputname.Contains( "DY" ) || outputname.Contains( "TTbar_" )
                || outputname.Contains( "WW_" ) || outputname.Contains( "WZ_" ) || outputname.Contains( "ZZ_" ) );
    bool isQCD = outputname.Contains( "QCD" ) || outputname.Contains( "TTbarFake" );
    bool noMCMatch = ( isData || isEWK );
    bool isVV = outputname.Contains( "WW_" ) || outputname.Contains( "WZ_" ) || outputname.Contains( "ZZ_" );
    bool doSyst = false;
    if ( isQCD )
        doSyst = false;

    //------------------------------------------------------------------------------------
    // Constants in the analysis
    //------------------------------------------------------------------------------------
    float lumi = 35.87;
    // Hardcoded prescale values for the trigger.
    // Something went wrong with prescales for data.
    float e8i = 4682;
    float e17i = 604;
    float m8i = 3464;
    float m17i = 170;

//    58580.9700839
//    7911.88489799
//    46040.4965593
//    3139.29431998

    //------------------------------------------------------------------------------------
    // Histograms in the analysis
    //------------------------------------------------------------------------------------
    TasUtil::AutoHist hists;

    //------------------------------------------------------------------------------------
    //
    // Main iLoop
    //
    //------------------------------------------------------------------------------------
    TasUtil::Looper<LeptonTree> looper( chain, &lepton_tree, nEvents );

    while ( looper.nextEvent() )
    {

        //--------------------------------
        // Prescale calculation via Z-peak
        //--------------------------------

        if ( passes_VVV_cutbased_tight() && p4().pt() > 25. && tag_p4().pt() > 30. )
        {
            float wgt = isData ? 1 : scale1fb() * lumi;

            if ( abs( id() ) == 11 )
            {
                if ( HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30() > 0 )
                {
                    hists.fill( dilep_mass(), "mll_e8i", wgt, 80, 0, 200 );
                }

                if ( HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30() > 0 )
                {
                    hists.fill( dilep_mass(), "mll_e17i", wgt, 80, 0, 200 );
                }
            }
            else if ( abs( id() ) == 13 )
            {
                if ( HLT_Mu8_TrkIsoVVL() > 0 )
                    hists.fill( dilep_mass(), "mll_m8i", wgt, 80, 0, 200 );

                if ( HLT_Mu17_TrkIsoVVL() > 0 )
                {
                    hists.fill( dilep_mass(), "mll_m17i", wgt, 80, 0, 200 );
                }
            }
        }

        //----------------------
        // Compute jet variables
        //----------------------
        int njets40 = 0;
        int njets40_up = 0;
        int njets40_dn = 0;

        for ( unsigned int i = 0; i < jets().size(); i++ )
        {
            if ( ROOT::Math::VectorUtil::DeltaR( jets()[i], p4() ) >= 1. )
            {
                if ( jets()[i].pt() > 40. && fabs( jets()[i].eta() ) < 2.4 )
                    njets40++;
                if ( ( isEWK || isData ) && !isVV && doSyst )
                {
                    if ( ( jets()[i].pt() * ( 1 + jets_unc()[i] ) ) > 40. && fabs( jets()[i].eta() ) < 2.4 )
                        njets40_up++;
                    if ( ( jets()[i].pt() * ( 1 - jets_unc()[i] ) ) > 40. && fabs( jets()[i].eta() ) < 2.4 )
                        njets40_dn++;
                }
            }
        }

        //--------------------------
        // Compute trigger variables
        //--------------------------

        // Compute prescales for QCD and Data.
        // QCD will take prescale from the LeptonTree directly.
        // For data, the prescale values were messed up.
        // Therefore it will use hardcoded values.
        int prescale = 0;
        bool pass_trig = 0; // logical AND with whether it matched

        if ( abs( id() ) == 11 )
        {
            // Check the trigger for our isolated single lepton trigger fired.
            // The trigger has positive value for lepton leg matched.
            // The HLT_* branch value will be negative for leg not matched.
            // (See setHLTBranch() function in CORE for more info.)
            if ( p4().pt() >= 10 && p4().pt() < 25 )
            {
                prescale = e8i;
                pass_trig = true;

                if ( HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30() <= 0 )
                {
                    hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                    pass_trig = false;
                }
            }
            else if ( p4().pt() >= 25 )
            {
                prescale = e17i;
                pass_trig = true;

                if ( HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30() <= 0 )
                {
                    hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                    pass_trig = false;
                }
            }
        }
        else if ( abs( id() ) == 13 )
        {
            // Check the trigger for our isolated single lepton trigger fired.
            // The trigger has positive value for lepton leg matched.
            // The HLT_* branch value will be negative for leg not matched.
            // (See setHLTBranch() function in CORE for more info.)
            if ( p4().pt() >= 10 && p4().pt() < 25 )
            {
                prescale = m8i;
                pass_trig = true;

                if ( HLT_Mu8_TrkIsoVVL() <= 0 )
                {
                    hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                    pass_trig = false;
                }
            }
            else if ( p4().pt() >= 25 )
            {
                prescale = m17i;
                pass_trig = true;

                if ( HLT_Mu17_TrkIsoVVL() <= 0 )
                {
                    hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                    pass_trig = false;
                }
            }
        }

        //---------------------
        // Compute event weight
        //---------------------
        float weight = isData ? prescale : scale1fb() * lumi * getTruePUw_Moriond( nvtx() );

        //-------------------
        // compute MT and MET
        //-------------------
        float evt_met = evt_corrMET();
        float evt_metPhi = evt_corrMETPhi();
        float evt_mt = calculateMt( p4(), evt_met, evt_metPhi );
        float evt_met_up = -999;
        float evt_metPhi_up = -999;
        float evt_mt_up = -999;
        float evt_met_dn = -999;
        float evt_metPhi_dn = -999;
        float evt_mt_dn = -999;
        if ( doSyst && !isVV )
        //if ( false )
        {
  //          evt_met_up = evt_corrMET_up();
//            evt_metPhi_up = evt_corrMETPhi_up();
            evt_mt_up = calculateMt( p4(), evt_met_up, evt_metPhi_up );
            evt_met_dn = evt_corrMET_dn();
            evt_metPhi_dn = evt_corrMETPhi_dn();
            evt_mt_dn = calculateMt( p4(), evt_met_dn, evt_metPhi_dn );
        }

        //------------------------------------------------------------
        // Lepton ID selection (most important selection in fake rate)
        //------------------------------------------------------------
        bool passId = abs( id()) == 13 ? passes_VVV_cutbased_tight() :passes_VVV_cutbased_tight() && threeChargeAgree();
        float relIso = RelIso03EA();
        bool passFO = abs( id() ) == 13 ? passes_VVV_cutbased_veto() : passes_VVV_cutbased_fo_noiso();
        //v1
        // passFO = abs( id() ) == 13 ? passes_VVV_cutbased_fo_noiso() : passes_VVV_cutbased_fo_noiso();
        //v2 
        // passFO = abs( id() ) == 13 ? passes_VVV_cutbased_fo_noiso() : passes_VVV_cutbased_fo_noiso() && threeChargeAgree();
        //v3
          //passFO = abs( id() ) == 13 ?  passes_VVV_cutbased_veto_noiso_noip() && fabs(ip3d())<0.015 : passes_VVV_cutbased_fo_noiso() && threeChargeAgree();
        //v4
          //passFO = abs( id() ) == 13 ?  passes_VVV_cutbased_veto_noiso() && fabs(ip3d())<0.015 : passes_VVV_cutbased_fo_noiso() && threeChargeAgree();
         //v5
         // passFO = abs( id() ) == 13 ?  passes_VVV_cutbased_fo_noiso() && fabs(ip3d())<0.015 : passes_VVV_cutbased_fo_noiso() && threeChargeAgree() && fabs(ip3d())<0.015;
          //iso<0.2
         //v6
         passFO = abs( id() ) == 13 ? passes_VVV_cutbased_fo_noiso() : passes_VVV_cutbased_fo_noiso() && threeChargeAgree() && fabs(ip3d())<0.015;
  //passFO = ((abs(id()) == 13 && passes_POG_looseID()&& RelIso03EA() < 0.2  && fabs(ip3d())<0.015 && dZ()<0.1 && dxyPV()<0.05) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2 )) && (threeChargeAgree()||abs(id())==13); 
  //passFO = ((abs(id()) == 13 && passes_VVV_cutbased_fo_noiso() && RelIso03EA() < 0.2  && fabs(ip3d())<0.015 && dZ()<0.1 && dxyPV()<0.05) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2 )) && (threeChargeAgree()||abs(id())==13); 
  //passFO = ((abs(id()) == 13 && passes_VVV_cutbased_fo_noiso() && RelIso03EA() < 0.2 && dZ()<0.1 && dxyPV()<0.05) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2 )) && (threeChargeAgree()||abs(id())==13); 
  //v5
  //passFO = ((abs(id()) == 13 && passes_POG_looseID()&& RelIso03EA() < 0.4  && fabs(ip3d())<0.015 && dZ()<0.1 && dxyPV()<0.05) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2 && threeChargeAgree() ) ); 
  //passFO = ((abs(id()) == 13 && passes_POG_looseID()&& RelIso03EA() < 0.4  && fabs(ip3d())<0.015 && dZ()<0.1 && dxyPV()<0.05) || (passes_VVV_cutbased_fo_noiso()&&abs(id()) == 11 && RelIso03EA() < 0.2 )); 



        if ( abs( id() ) == 11 )
            //passFO = passFO && ( relIso < 0.2 ) && ( exp_innerlayers() == 0 );
            passFO = passFO && ( relIso < 0.2 );
        else if ( abs( id() ) == 13 )
            passFO = passFO && ( relIso < 0.4 ) && ( fabs( ip3d() ) < 0.015 );
            //passFO = passFO && ( relIso < 0.2 );

        // If electron, there are some trigger cuts necessary
        // to stay within the trigger online lepton ID
        if ( abs( id() ) == 11 )
        {
            bool isEB = fabs( etaSC() ) > 1.479 ? false : true;
            float sIeIe = sigmaIEtaIEta_full5x5();
            float hoe = hOverE();
            float deta = fabs( dEtaIn() );
            float dphi = fabs( dPhiIn() );
            float invep = fabs( 1. / ecalEnergy() - 1. / p4().P() );
            float cut_sIeIe = isEB ? 0.011 : 0.031;
            float cut_hoe   = 0.08;
            float cut_deta  = 0.01;
            float cut_dphi  = isEB ? 0.04 : 0.08;
            float cut_invep = 0.01;
            bool passHltCuts = ( sIeIe < cut_sIeIe && hoe < cut_hoe && deta < cut_deta
                    && dphi < cut_dphi && invep < cut_invep );

            if ( !passIsolatedFO( id(), etaSC(), mva_25ns(), p4().pt() ) )
            {
                hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                continue;
            }

            float ePFIso = ecalPFClusterIso() / p4().pt();
            float hPFIso = hcalPFClusterIso() / p4().pt();
            float trkIso = tkIso() / p4().pt();
            float cut_ePFIso = 0.45;
            float cut_hPFIso = 0.25;
            float cut_trkIso  = 0.2;
            passHltCuts = passHltCuts && ePFIso < cut_ePFIso && hPFIso < cut_hPFIso
                && trkIso < cut_trkIso;
            passFO = passHltCuts && passFO;
        }

        //---------------------------------------------------------
        // Compute cone correction variable for VVV tight isolation
        //---------------------------------------------------------
        float coneptcorr = 0;

        if ( abs( id() ) == 11 )
        {
            if ( abs( etaSC() ) <= 1.479 )
                coneptcorr = std::max( 0., relIso - 0.0588 );
            else
                coneptcorr = std::max( 0., relIso - 0.0571 );
        }

        if ( abs( id() ) == 13 )
            coneptcorr = std::max( 0., relIso - 0.06 );

        // If the lepton passed the tight ID no correction is needed.
        if ( passId )
            coneptcorr = 0;

        //==========================================================================================
        //
        //
        // Done computing variables
        //
        //
        //==========================================================================================

        //--------------------------
        // Instantiate Lepton object
        //--------------------------
        Lepton lepton;
        lepton.evt_event = lepton_tree.evt_event();
        lepton.evt_lumiBlock = lepton_tree.evt_lumiBlock();
        lepton.evt_run = lepton_tree.evt_run();
//        lepton.instantLumi = isQCD ? -999 : lepton_tree.instantLumi();
        lepton.nvtx = lepton_tree.nvtx();
        lepton.p4 = p4();
        lepton.id = id();
        lepton.iso = RelIso03EA();
        lepton.nFOs_VVV = isQCD ? nFOs_SS() : nFOs_VVV();
        lepton.njets40 = njets40;
        lepton.njets40_up = njets40_up;
        lepton.njets40_dn = njets40_dn;
        lepton.prescale = prescale;
        lepton.pass_trig = pass_trig;
        lepton.weight = weight;
        lepton.evt_met = evt_met;
        lepton.evt_metPhi = evt_metPhi;
        lepton.evt_mt = evt_mt;
        lepton.evt_met_up = evt_met_up;
        lepton.evt_metPhi_up = evt_metPhi_up;
        lepton.evt_mt_up = evt_mt_up;
        lepton.evt_met_dn = evt_met_dn;
        lepton.evt_metPhi_dn = evt_metPhi_dn;
        lepton.evt_mt_dn = evt_mt_dn;
        lepton.passId = passId;
        lepton.passFO = passFO;
        lepton.coneptcorr = coneptcorr;
        lepton.pass_e8i = HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30();
        lepton.pass_e17i = HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30();
        lepton.pass_m8i = HLT_Mu8_TrkIsoVVL();
        lepton.pass_m17i = HLT_Mu17_TrkIsoVVL();
        lepton.motherID = motherID();
        lepton.isEWK = isEWK;
        lepton.isData = isData;
        lepton.isDoubleMuon = isDoubleMuon;
        std::vector<float> wgt_syst;
        if ( !isQCD && doSyst )
            for ( unsigned int i = 1; i < lepton_tree.evt_wgt_vars().size(); ++i )
                wgt_syst.push_back( lepton_tree.evt_wgt_vars()[i] );
        lepton.wgt_syst = wgt_syst;

        //-------------------------------
        // Debug print relevant variables
        //-------------------------------

        if ( lepton_tree.evt_event() == evt_event_to_print )
        {
            std::cout << "Lepton in this event" << std::endl;
            std::cout << "File name : " << looper.tfile->GetName() << std::endl;
            std::cout << "idx in tree : " << looper.indexOfEventInTTree << std::endl;
            lepton.print();
        }

        //--------------------------------------------------------------------
        // Rebuiliding data at the per event level instead of per lepton level
        //--------------------------------------------------------------------
        if ( prev_evt_event != lepton_tree.evt_event() )
        {

            if ( leptons.size() > 0 )
            {

                // If it is a new event, it means it's time to take care of previous event data
                // Do something with it.
//                fillEventLevelHistograms( leptons, hists );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 0 , "" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 1 , "syst1_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 2 , "syst2_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 3 , "syst3_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 4 , "syst4_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 5 , "syst5_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 6 , "syst6_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 7 , "syst7_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 8 , "syst8_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 9 , "syst9_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 10, "syst10_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 11, "syst11_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40, leptons[0].evt_met, leptons[0].evt_metPhi, leptons[0].evt_mt, 12, "syst12_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40_up, leptons[0].evt_met_up, leptons[0].evt_metPhi_up, leptons[0].evt_mt_up, 13, "syst13_" );
                fillEventLevelHistogramsSyst( leptons, hists, leptons[0].njets40_dn, leptons[0].evt_met_dn, leptons[0].evt_metPhi_dn, leptons[0].evt_mt_dn, 14, "syst14_" );

                // After doing something with it, clear it out.
                leptons.clear();
            }

            prev_evt_event = lepton_tree.evt_event();
        }

        // add the lepton to the leptons vector
        if ( passFO )
            leptons.push_back( lepton );

        //------------------
        // Print lepton info
        //------------------
        if ( lepton_tree.evt_event() == evt_event_to_print )
        {
            std::cout << "=====meas====" << std::endl;
            std::cout << "printing event info for evt_event = " << lepton_tree.evt_event() << std::endl;
            std::cout << " passId " <<  passId << std::endl;
            std::cout << " passFO " <<  passFO << std::endl;
            std::cout << " pt " <<  p4().pt() << std::endl;
            std::cout << " nFOs_VVV " <<  nFOs_VVV() << std::endl;
            std::cout << " nFOs_SS " <<  nFOs_SS() << std::endl;
            std::cout << " evt_met " <<  evt_met << std::endl;
            std::cout << " evt_mt " <<  evt_mt << std::endl;
            std::cout << " prescale " << prescale << std::endl;
            std::cout << " pass_trig " << pass_trig << std::endl;
            std::cout << " njets40 " << njets40 << std::endl;
            std::cout << "=====" << std::endl;

        }

        continue;

        //==========================================================================================
        //
        //
        // Event selections
        //
        //
        //==========================================================================================

        //----------------------
        // Event level selection
        //----------------------
        // if prompt lepton with QCD sample reject.
        if ( isQCD && motherID() > 0 )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        //-----------------------------------
        // Skip events with trigger not fired
        //-----------------------------------
        if ( !pass_trig ) continue;

        //-----------------------------------------------------------------------------------------------
        // Skip events in data when the candidate we're looking at is not from the dataset that we expect
        //-----------------------------------------------------------------------------------------------
        if ( isData )
        {
            if ( isDoubleMuon && abs( id() ) != 13 )
            {
                hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                continue;
            }

            if ( !isDoubleMuon && abs( id() ) != 11 )
            {
                hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
                continue;
            }
        }

        //-----------------------------------------------
        // Skip events without at least one jet of 40 GeV
        //-----------------------------------------------
        if ( !( njets40 > 0 ) )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        //----------------------------------
        // Skip events with more than one FO
        //----------------------------------
        if ( nFOs_VVV() > 1 )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        //----------------------------------
        // Kinematic selection on the lepton
        //----------------------------------
        if ( p4().pt() < 10. )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        if ( abs( id() ) == 11 && fabs( p4().eta() ) > 2.5 )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        if ( abs( id() ) == 13 && fabs( p4().eta() ) > 2.4 )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        hists.fill( njets40, "njets40", weight, 5, 0, 5 );

        //==========================================================================================
        //
        //
        // fill histograms
        //
        //
        //==========================================================================================
        
        //-----------------------------------------
        // Fill the main fake rate study histograms
        //-----------------------------------------
        if ( passId )
            fillFakeRateHistograms( hists, "", evt_met, evt_mt, weight );

        if ( passFO )
            fillFakeRateHistograms( hists, "loose_", evt_met, evt_mt, weight );

        //        if ( passFO && !passId )
        //            fillFakeRateHistograms( hists, "lbnt_", evt_met, evt_mt, weight );

        if ( !( evt_met < 20. && evt_mt < 20 ) )
        {
            hists.fill( __COUNTER__, "counter",  1.,  20, 0, 20 );
            continue;
        }

        //-------------------
        // Verifying prescale
        //-------------------
        if ( abs( id() ) == 11 )
        {
            hists.fill( p4().pt(), "histo_pt_el", weight, 20000, 0, 200 );
            hists.fill( p4().pt(), "histo_nowgt_pt_el",
                    isData ? 1 : scale1fb() * lumi * getTruePUw_Moriond( nvtx() )
                    , 20000, 0, 200 );
        }
        else if ( abs( id() ) == 13 )
        {
            hists.fill( p4().pt(), "histo_pt_mu", weight, 20000, 0, 200 );
            hists.fill( p4().pt(), "histo_nowgt_pt_mu",
                    isData ? 1 : scale1fb() * lumi * getTruePUw_Moriond( nvtx() )
                    , 20000, 0, 200 );
        }

        // For MC, motherID's can have various values.
        // For data, it's always -1.
        // For MC, we only do matching for QCD sample.
        // For W/Z samples, noMCMatch is true. (See above)
        // For data, we accept all events.
        if ( noMCMatch || motherID() <= 0 )
        {

            if ( passId )
            {
                hists.fill( 0, "Nt", weight, 1, 0, 1 );

                if ( abs( id() ) == 11 )
                {
                    hists.fill( 0, "Nt_e", weight, 1, 0, 1 );
                    hists.fill( p4().pt(), abs( p4().eta() ), "Nt_histo_e",
                            weight, nptbins, ptbins, netabins, etabins_el );
                }

                if ( abs( id() ) == 13 )
                {
                    hists.fill( 0, "Nt_mu", weight, 1, 0, 1 );
                    hists.fill( p4().pt(), abs( p4().eta() ), "Nt_histo_mu",
                            weight, nptbins, ptbins, netabins, etabins_mu );
                }
            }

            if ( passFO )
            {
                hists.fill( 0, "Nl", weight, 1, 0, 1 );

                if ( abs( id() ) == 11 )
                {
                    hists.fill( 0, "Nl_e", weight, 1, 0, 1 );
                    hists.fill( p4().pt(), abs( p4().eta() ), "Nl_histo_e",
                            weight, nptbins, ptbins, netabins, etabins_el );
                    hists.fill( p4().pt() * ( 1 + coneptcorr ), abs( p4().eta() ),
                            "Nl_cone_histo_e", weight, nptbins, ptbins, netabins, etabins_el );
                }

                if ( abs( id() ) == 13 )
                {
                    hists.fill( 0, "Nl_mu", weight, 1, 0, 1 );
                    hists.fill( p4().pt(), abs( p4().eta() ), "Nl_histo_mu",
                            weight, nptbins, ptbins, netabins, etabins_mu );
                    hists.fill( p4().pt() * ( 1 + coneptcorr ), abs( p4().eta() ),
                            "Nl_cone_histo_mu", weight, nptbins, ptbins, netabins, etabins_mu );
        }
    }
}
}
    TH1F* h_Nt_e  = ( TH1F* ) hists.get( "evt_lvl_histo_ptvarbin_meas_el" );
    TH1F* h_Nl_e  = ( TH1F* ) hists.get( "evt_lvl_histo_ptvarbin_loose_meas_el" );
    TH1F* h_Nt_mu = ( TH1F* ) hists.get( "evt_lvl_histo_ptvarbin_meas_mu" );
    TH1F* h_Nl_mu = ( TH1F* ) hists.get( "evt_lvl_histo_ptvarbin_loose_meas_mu" );

    if ( h_Nt_e  ) h_Nt_e  -> Rebin( h_Nt_e ->GetNbinsX() );
    if ( h_Nl_e  ) h_Nl_e  -> Rebin( h_Nl_e ->GetNbinsX() );
    if ( h_Nt_mu ) h_Nt_mu -> Rebin( h_Nt_mu->GetNbinsX() );
    if ( h_Nl_mu ) h_Nl_mu -> Rebin( h_Nl_mu->GetNbinsX() );

    float Nt_e  = h_Nt_e  ? h_Nt_e  -> GetBinContent( 1 ) : 0.;
    float Nl_e  = h_Nl_e  ? h_Nl_e  -> GetBinContent( 1 ) : 0.;
    float Nt_mu = h_Nt_mu ? h_Nt_mu -> GetBinContent( 1 ) : 0.;
    float Nl_mu = h_Nl_mu ? h_Nl_mu -> GetBinContent( 1 ) : 0.;

    float e_e = Nt_e / ( Nl_e );
    float e_mu = Nt_mu / ( Nl_mu );

    cout << "\nReco (el): " << "Nt = " << Nt_e << ", Nl = " << Nl_e << ", e = " << e_e << endl;
    cout << "\nReco (mu): " << "Nt = " << Nt_mu << ", Nl = " << Nl_mu << ", e = " << e_mu <<
        endl;

    hists.save( outputname );
}

//________________________________________________________________________________________
void fillEventLevelHistogramsSyst(
        std::vector<Lepton> leptons,
        TasUtil::AutoHist& hists,
        int njets,
        float evt_met,
        float evt_metPhi,
        float evt_mt,
        int iwgt,
        TString prefix
        )
{
    //----------------------------------------
    // Count number of loose and tight leptons
    //----------------------------------------
    int nFOs = 0;
    int nIds = 0;
    for ( auto& lepton : leptons )
    {
        if ( lepton.passFO ) nFOs++; // redundant as leptons vector already has passFO criteria
        if ( lepton.passId ) nIds++;
    }

    //--------------------------------------------------------------------
    // First reproduce the nominal results using this event level approach
    //--------------------------------------------------------------------
    if ( nFOs == 1 )
    {

        float weight = leptons[0].weight;

        if ( leptons[0].wgt_syst.size() )
        {
//            std::cout << "before " << weight << std::endl;
            weight /= leptons[0].wgt_syst[0];
            weight *= leptons[0].wgt_syst[iwgt];
//            std::cout << "after  " << weight << std::endl;
        }

        // Preselection
        if ( leptons[0].isData &&  leptons[0].isDoubleMuon && abs( leptons[0].id ) != 13 ) return;
        if ( leptons[0].isData && !leptons[0].isDoubleMuon && abs( leptons[0].id ) != 11 ) return;
        if ( njets              < 1 ) return;
        if ( leptons[0].pass_trig == false ) return;

        // EWK CR no MT cut
        if ( evt_met            > 30.          &&
             leptons[0].passId                 &&
             leptons[0].p4.pt() > 10.
           )
        {
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
                hists.fill( evt_mt           , prefix + "evt_lvl_histo_mt_cr_mu", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
                hists.fill( evt_mt           , prefix + "evt_lvl_histo_mt_cr_el", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
                hists.fill( evt_mt           , prefix + "evt_lvl_nvtxrewgt_histo_mt_cr_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
                hists.fill( evt_mt           , prefix + "evt_lvl_nvtxrewgt_histo_mt_cr_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 20, 0, 200 );
        }
        // MR
        if ( evt_met            < 20.          &&
             evt_mt             < 20.          &&
             leptons[0].p4.pt() > 10.
           )
        {
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_histo_ptvarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_histo_ptvarbin_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_histo_conecorrptvarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_histo_conecorrptvarbin_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_histo_etavarbin_loose_meas_mu", leptons[0].weight, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_histo_etavarbin_meas_mu", leptons[0].weight, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_ptvarbin_etavarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_ptvarbin_etavarbin_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_conecorrptvarbin_etavarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_conecorrptvarbin_etavarbin_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
            }
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_histo_ptvarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_histo_ptvarbin_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_histo_conecorrptvarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_histo_conecorrptvarbin_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_histo_etavarbin_loose_meas_el", leptons[0].weight, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_histo_etavarbin_meas_el", leptons[0].weight, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_ptvarbin_etavarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_ptvarbin_etavarbin_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_conecorrptvarbin_etavarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_histo_conecorrptvarbin_etavarbin_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
            }

            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
            {
                if ( leptons[0].passFO ) {
                 hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                hists.fill( leptons[0].iso, prefix + "evt_lvl_nvtxrewgt_histo_reliso", leptons[0].weight * nvtxRewgtMu( leptons[0] ),100,0,0.4);
                 }
                if ( leptons[0].passId ) 
                { 
                hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                }
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
            }
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
            }
        }
        // High pt lepton region
        if ( leptons[0].p4.pt() > 50. &&
             leptons[0].passId
           )
        {
            if ( abs( leptons[0].id ) == 13 ) hists.fill( evt_met           , prefix + "evt_lvl_histo_met_highpt50_mu", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( evt_met           , prefix + "evt_lvl_histo_met_highpt50_el", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].nvtx, prefix + "evt_lvl_histo_nvtx_highpt50_mu", leptons[0].weight, 50, 0, 50 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].nvtx, prefix + "evt_lvl_histo_nvtx_highpt50_el", leptons[0].weight, 50, 0, 50 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( evt_met           , prefix + "evt_lvl_nvtxrewgt_histo_met_highpt50_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( evt_met           , prefix + "evt_lvl_nvtxrewgt_histo_met_highpt50_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].nvtx, prefix + "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 50, 0, 50 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].nvtx, prefix + "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 50, 0, 50 );
        }
    }

//    else if ( nFOs == 2 )
//    {
//
//        // Compute some variables
//        float mll = ( leptons[0].p4 + leptons[1].p4 ).mass();
//        float mt0 = leptons[0].p4.pt() > 10. ? calculateMt( leptons[0].p4, leptons[0].evt_met, leptons[0].evt_metPhi ) : -999;
//        float mt1 = leptons[1].p4.pt() > 10. ? calculateMt( leptons[1].p4, leptons[1].evt_met, leptons[1].evt_metPhi ) : -999;
//        int idx_wtag = abs( mt0 - 80. ) < abs( mt1 - 80. ) ? 0 : 1;
//        int idx_cand = abs( mt0 - 80. ) < abs( mt1 - 80. ) ? 1 : 0;
//        int idx_lead = leptons[0].p4.pt() > leptons[1].p4.pt() ? 0 : 1;
//        int idx_subl = leptons[0].p4.pt() > leptons[1].p4.pt() ? 1 : 0;
//        int isSF = abs( leptons[0].id ) == abs( leptons[1].id );
//
//        hists.fill( mt0, "mt0" , leptons[0].weight, 50, 0, 150 );
//        hists.fill( mt1, "mt1" , leptons[1].weight, 50, 0, 150 );
//        hists.fill( idx_wtag ? mt1 : mt0, "mtW" , leptons[idx_wtag].weight, 50, 0, 150 );
//        hists.fill( idx_cand ? mt1 : mt0, "mtL" , leptons[idx_cand].weight, 50, 0, 150 );
//
//        // Preselection
//        bool presel = true;
//        if (!( leptons[idx_wtag].p4.pt()          >= 25.                            )) presel = false;
//        if (!( fabs( leptons[idx_wtag].p4.eta() ) <=  2.4                           )) presel = false;
//        if (!( ( abs( leptons[idx_wtag].id ) == 11 && leptons[idx_wtag].pass_e17i )
//            || ( abs( leptons[idx_wtag].id ) == 13 && leptons[idx_wtag].pass_m17i ) )) presel = false;
//
//        // Fill some histograms
//        if ( presel && isSF && abs( leptons[idx_wtag].id ) == 11 ) hists.fill( mll, "nFO2_mll_e17i" , leptons[idx_wtag].weight, 50, 0, 150 );
//        if ( presel && isSF && abs( leptons[idx_wtag].id ) == 13 ) hists.fill( mll, "nFO2_mll_m17i" , leptons[idx_wtag].weight, 50, 0, 150 );
//        if ( presel )
//        {
//            hists.fill( leptons[idx_wtag].evt_met, "met_presel" , leptons[idx_wtag].weight, 40, 0, 200 );
//            hists.fill( leptons[idx_wtag].evt_mt , "mt_presel"  , leptons[idx_wtag].weight, 40, 0, 200 );
//        }
//
//        // Tagging W events
//        bool wsel = presel;
//        if (!( leptons[idx_wtag].evt_mt > 80.                   )) wsel = false;
//        if (!( leptons[idx_wtag].evt_mt < 120.                  )) wsel = false;
//        if (!( ( isSF && fabs( mll - 91.1876 ) > 15. ) || !isSF )) wsel = false;
//        if (!( ( isSF && mll                   > 20. ) || !isSF )) wsel = false;
//
//        // Fill some histograms
//        if ( wsel )
//        {
//            // Fill without motherID tagging
//            hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_histo_ptvarbin_loose_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//            if ( leptons[idx_cand].passId )
//                hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_histo_ptvarbin_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//
//            // Fill with motherID tagging
//            if ( ( leptons[idx_cand].isEWK && leptons[idx_cand].motherID > 0 ) || !leptons[idx_cand].isEWK )
//            {
//                hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_wMCmatch_histo_ptvarbin_loose_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//                if ( leptons[idx_cand].passId )
//                    hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_wMCmatch_histo_ptvarbin_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//            }
//        }
//
//    }

}

//________________________________________________________________________________________
void fillEventLevelHistograms( std::vector<Lepton>& leptons, TasUtil::AutoHist& hists )
{
    //----------------------------------------
    // Count number of loose and tight leptons
    //----------------------------------------
    int nFOs = 0;
    int nIds = 0;
    for ( auto& lepton : leptons )
    {
        if ( lepton.passFO ) nFOs++; // redundant as leptons vector already has passFO criteria
        if ( lepton.passId ) nIds++;
    }

    //--------------------------------------------------------------------
    // First reproduce the nominal results using this event level approach
    //--------------------------------------------------------------------
    if ( nFOs == 1 )
    {
        // Preselection
        if ( leptons[0].isData &&  leptons[0].isDoubleMuon && abs( leptons[0].id ) != 13 ) return;
        if ( leptons[0].isData && !leptons[0].isDoubleMuon && abs( leptons[0].id ) != 11 ) return;
        if ( leptons[0].njets40 < 1 ) return;
        if ( leptons[0].pass_trig == false ) return;

        // EWK CR no MT cut
        if ( leptons[0].evt_met > 30.          &&
             leptons[0].passId                 &&
             leptons[0].p4.pt() > 10.
           )
        {
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
                hists.fill( leptons[0].evt_mt, "evt_lvl_histo_mt_cr_mu", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
                hists.fill( leptons[0].evt_mt, "evt_lvl_histo_mt_cr_el", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
                hists.fill( leptons[0].evt_mt, "evt_lvl_nvtxrewgt_histo_mt_cr_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
                hists.fill( leptons[0].evt_mt, "evt_lvl_nvtxrewgt_histo_mt_cr_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 20, 0, 200 );
        }
        // MR
        if ( leptons[0].evt_met < 20.          &&
             leptons[0].evt_mt  < 20.          &&
             leptons[0].p4.pt() > 10.
           )
        {
            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), "evt_lvl_histo_ptvarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), "evt_lvl_histo_ptvarbin_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_histo_conecorrptvarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_histo_conecorrptvarbin_meas_mu", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), "evt_lvl_histo_etavarbin_loose_meas_mu", leptons[0].weight, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), "evt_lvl_histo_etavarbin_meas_mu", leptons[0].weight, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_ptvarbin_etavarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_ptvarbin_etavarbin_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_conecorrptvarbin_etavarbin_loose_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_conecorrptvarbin_etavarbin_meas_mu", leptons[0].weight, nptbins, ptbins, netabins, etabins_mu );
            }
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), "evt_lvl_histo_ptvarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), "evt_lvl_histo_ptvarbin_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_histo_conecorrptvarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_histo_conecorrptvarbin_meas_el", leptons[0].weight, nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), "evt_lvl_histo_etavarbin_loose_meas_el", leptons[0].weight, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), "evt_lvl_histo_etavarbin_meas_el", leptons[0].weight, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_ptvarbin_etavarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_ptvarbin_etavarbin_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_conecorrptvarbin_etavarbin_loose_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_histo_conecorrptvarbin_etavarbin_meas_el", leptons[0].weight, nptbins, ptbins, netabins, etabins_el );
            }

            if ( abs( leptons[0].id ) == 13 && fabs( leptons[0].p4.eta() ) < 2.4 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), nptbins, ptbins, netabins, etabins_mu );
            }
            if ( abs( leptons[0].id ) == 11 && fabs( leptons[0].p4.eta() ) < 2.5 )
            {
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_ptvarbin_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passFO ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
                if ( leptons[0].passId ) hists.fill( ( 1 + leptons[0].coneptcorr ) * leptons[0].p4.pt(), leptons[0].p4.eta(), "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), nptbins, ptbins, netabins, etabins_el );
            }
        }
        // High pt lepton region
        if ( leptons[0].p4.pt() > 50. &&
             leptons[0].passId
           )
        {
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].evt_met, "evt_lvl_histo_met_highpt50_mu", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].evt_met, "evt_lvl_histo_met_highpt50_el", leptons[0].weight, 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].nvtx, "evt_lvl_histo_nvtx_highpt50_mu", leptons[0].weight, 50, 0, 50 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].nvtx, "evt_lvl_histo_nvtx_highpt50_el", leptons[0].weight, 50, 0, 50 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].evt_met, "evt_lvl_nvtxrewgt_histo_met_highpt50_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].evt_met, "evt_lvl_nvtxrewgt_histo_met_highpt50_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 20, 0, 200 );
            if ( abs( leptons[0].id ) == 13 ) hists.fill( leptons[0].nvtx, "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_mu", leptons[0].weight * nvtxRewgtMu( leptons[0] ), 50, 0, 50 );
            if ( abs( leptons[0].id ) == 11 ) hists.fill( leptons[0].nvtx, "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_el", leptons[0].weight * nvtxRewgtEl( leptons[0] ), 50, 0, 50 );
        }
    }

//    else if ( nFOs == 2 )
//    {
//
//        // Compute some variables
//        float mll = ( leptons[0].p4 + leptons[1].p4 ).mass();
//        float mt0 = leptons[0].p4.pt() > 10. ? calculateMt( leptons[0].p4, leptons[0].evt_met, leptons[0].evt_metPhi ) : -999;
//        float mt1 = leptons[1].p4.pt() > 10. ? calculateMt( leptons[1].p4, leptons[1].evt_met, leptons[1].evt_metPhi ) : -999;
//        int idx_wtag = abs( mt0 - 80. ) < abs( mt1 - 80. ) ? 0 : 1;
//        int idx_cand = abs( mt0 - 80. ) < abs( mt1 - 80. ) ? 1 : 0;
//        int idx_lead = leptons[0].p4.pt() > leptons[1].p4.pt() ? 0 : 1;
//        int idx_subl = leptons[0].p4.pt() > leptons[1].p4.pt() ? 1 : 0;
//        int isSF = abs( leptons[0].id ) == abs( leptons[1].id );
//
//        hists.fill( mt0, "mt0" , leptons[0].weight, 50, 0, 150 );
//        hists.fill( mt1, "mt1" , leptons[1].weight, 50, 0, 150 );
//        hists.fill( idx_wtag ? mt1 : mt0, "mtW" , leptons[idx_wtag].weight, 50, 0, 150 );
//        hists.fill( idx_cand ? mt1 : mt0, "mtL" , leptons[idx_cand].weight, 50, 0, 150 );
//
//        // Preselection
//        bool presel = true;
//        if (!( leptons[idx_wtag].p4.pt()          >= 25.                            )) presel = false;
//        if (!( fabs( leptons[idx_wtag].p4.eta() ) <=  2.4                           )) presel = false;
//        if (!( ( abs( leptons[idx_wtag].id ) == 11 && leptons[idx_wtag].pass_e17i )
//            || ( abs( leptons[idx_wtag].id ) == 13 && leptons[idx_wtag].pass_m17i ) )) presel = false;
//
//        // Fill some histograms
//        if ( presel && isSF && abs( leptons[idx_wtag].id ) == 11 ) hists.fill( mll, "nFO2_mll_e17i" , leptons[idx_wtag].weight, 50, 0, 150 );
//        if ( presel && isSF && abs( leptons[idx_wtag].id ) == 13 ) hists.fill( mll, "nFO2_mll_m17i" , leptons[idx_wtag].weight, 50, 0, 150 );
//        if ( presel )
//        {
//            hists.fill( leptons[idx_wtag].evt_met, "met_presel" , leptons[idx_wtag].weight, 40, 0, 200 );
//            hists.fill( leptons[idx_wtag].evt_mt , "mt_presel"  , leptons[idx_wtag].weight, 40, 0, 200 );
//        }
//
//        // Tagging W events
//        bool wsel = presel;
//        if (!( leptons[idx_wtag].evt_mt > 80.                   )) wsel = false;
//        if (!( leptons[idx_wtag].evt_mt < 120.                  )) wsel = false;
//        if (!( ( isSF && fabs( mll - 91.1876 ) > 15. ) || !isSF )) wsel = false;
//        if (!( ( isSF && mll                   > 20. ) || !isSF )) wsel = false;
//
//        // Fill some histograms
//        if ( wsel )
//        {
//            // Fill without motherID tagging
//            hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_histo_ptvarbin_loose_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//            if ( leptons[idx_cand].passId )
//                hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_histo_ptvarbin_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//
//            // Fill with motherID tagging
//            if ( ( leptons[idx_cand].isEWK && leptons[idx_cand].motherID > 0 ) || !leptons[idx_cand].isEWK )
//            {
//                hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_wMCmatch_histo_ptvarbin_loose_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//                if ( leptons[idx_cand].passId )
//                    hists.fill( leptons[idx_cand].p4.pt(), "evt_lvl_nFO2_wMCmatch_histo_ptvarbin_meas_mu", leptons[idx_cand].weight, nptbins, ptbins );
//            }
//        }
//
//    }

}

//________________________________________________________________________________________
float computePtRel( LorentzVector lepp4, LorentzVector jetp4, bool subtractLep )
{
    if ( jetp4.pt() == 0 )
        return 0.;

    if ( subtractLep )
        jetp4 -= lepp4;

    float dot = lepp4.Vect().Dot( jetp4.Vect() );
    float ptrel = lepp4.P2() - dot * dot / jetp4.P2();
    ptrel = ptrel > 0 ? sqrt( ptrel ) : 0.0;
    return ptrel;
}

//________________________________________________________________________________________
double calculateMt( const LorentzVector p4, double met, double met_phi )
{
    float phi1 = p4.Phi();
    float phi2 = met_phi;
    float Et1  = p4.Et();
    float Et2  = met;
    return sqrt( 2 * Et1 * Et2 * ( 1.0 - cos( phi1 - phi2 ) ) );
}

//________________________________________________________________________________________
float getPt( float pt, bool extrPtRel )
{
    if ( !extrPtRel && pt >= 70. )
        return 69.;

    if ( extrPtRel && pt >= 150. )
        return 149.;

    if ( pt < 10. )
    {
        return 11.;    //use this if lower FR histo bound is 10.
    }

    return pt;
}

//________________________________________________________________________________________
float getEta( float eta, float ht, bool extrPtRel )
{
    if ( extrPtRel )
    {
        if ( ht >= 800 )
            return 799;

        return ht;
    }

    if ( fabs( eta ) >= 2.4 )
        return 2.3;

    return fabs( eta );
}

//________________________________________________________________________________________
bool passIsolatedFO( int id, float eta, float disc, float pt )
{
    if ( abs( id ) == 13 )
        return true;

    float aeta = fabs( eta );

    // if (aeta < 0.8) return mva > -0.155;
    // if ((aeta >= 0.8 && aeta <= 1.479)) return mva > -0.56;
    // if (aeta > 1.479) return mva > -0.76;
    if ( aeta < 0.8 )
        return disc > mvacut( -0.86, -0.96, -0.3, pt );

    if ( ( aeta >= 0.8 && aeta <= 1.479 ) )
        return disc > mvacut( -0.85, -0.96, -0.36, pt );

    if ( aeta > 1.479 )
        return disc > mvacut( -0.81, -0.95, -0.63, pt );

    return false;
}

//________________________________________________________________________________________
// returns A if pt<ptmin, B if pt>ptmax, and linear interpolation between. if pt<10, use C
float mvacut( float A, float B, float C, float pt_ )
{
    float ptmin = 15;
    float ptmax = 25;
    return pt_ > 10 ? std::min( A, std::max( B,
                A + ( B - A ) / ( ptmax - ptmin ) * ( pt_ - ptmin ) ) ) : C;
}

//________________________________________________________________________________________
void fill( TasUtil::AutoHist& hists, TString suffix, float& evt_mt, float& evt_met, float& weight )
{
    float coneptcorr = 0;
    float relIso = RelIso03EA();

    if ( abs( id() ) == 11 )
    {
        if ( abs( etaSC() ) <= 1.479 )
            coneptcorr = std::max( 0., relIso - 0.0588 );
        else
            coneptcorr = std::max( 0., relIso - 0.0571 );
    }

    if ( abs( id() ) == 13 )
        coneptcorr = std::max( 0., relIso - 0.06 );

    hists.fill( evt_mt, "histo_mt_" + suffix, weight, 20, 0, 200 );
    hists.fill( evt_met, "histo_met_" + suffix, weight, 20, 0, 200 );

    if ( abs( id() ) == 11 )
    {
        hists.fill( nvtx(), "histo_nvtx_" + suffix + "_el", weight, 50, 0, 50 );
        hists.fill( evt_mt, "histo_mt_" + suffix + "_el", weight, 20, 0, 200 );
        hists.fill( evt_met, "histo_met_" + suffix + "_el", weight, 20, 0, 200 );
        hists.fill( p4().pt(), "histo_ptvarbin_" + suffix + "_el", weight, nptbins, ptbins );
        hists.fill( p4().pt(), "histo_ptvarbin_coarse_" + suffix + "_el", weight, nptbins_coarse, ptbins_coarse );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), "histo_conecorrptvarbin_" + suffix + "_el", weight, nptbins, ptbins );
        hists.fill( p4().eta(), "histo_etavarbin_" + suffix + "_el", weight, netabins, etabins_el );
        hists.fill( p4().pt(), p4().eta(), "histo_ptvarbin_etavarbin_" + suffix + "_el", weight, nptbins, ptbins, netabins,
                etabins_el );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), p4().eta(), "histo_conecorrptvarbin_etavarbin_" + suffix + "_el", weight,
                nptbins, ptbins, netabins, etabins_el );
        hists.fill( p4().pt(), "histo_pt_" + suffix + "_el", weight, 40, 0, 200 );
        hists.fill( p4().eta(), "histo_eta_" + suffix + "_el", weight, 20, -3, 3 );
        hists.fill( p4().phi(), "histo_phi_" + suffix + "_el", weight, 20, -3.15, 3.15 );
    }
    else if ( abs( id() ) == 13 )
    {
        hists.fill( nvtx(), "histo_nvtx_" + suffix + "_mu", weight, 50, 0, 50 );
        hists.fill( evt_mt, "histo_mt_" + suffix + "_mu", weight, 20, 0, 200 );
        hists.fill( evt_met, "histo_met_" + suffix + "_mu", weight, 20, 0, 200 );
        hists.fill( p4().pt(), "histo_ptvarbin_" + suffix + "_mu", weight, nptbins, ptbins );
        hists.fill( p4().pt(), "histo_ptvarbin_coarse_" + suffix + "_mu", weight, nptbins_coarse, ptbins_coarse );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), "histo_conecorrptvarbin_" + suffix + "_mu", weight, nptbins, ptbins );
        hists.fill( p4().eta(), "histo_etavarbin_" + suffix + "_mu", weight, netabins, etabins_mu );
        hists.fill( p4().pt(), p4().eta(), "histo_ptvarbin_etavarbin_" + suffix + "_mu", weight, nptbins, ptbins, netabins,
                etabins_mu );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), p4().eta(), "histo_conecorrptvarbin_etavarbin_" + suffix + "_mu", weight,
                nptbins, ptbins, netabins, etabins_mu );
        hists.fill( p4().pt(), "histo_pt_" + suffix + "_mu", weight, 40, 0, 200 );
        hists.fill( p4().eta(), "histo_eta_" + suffix + "_mu", weight, 20, -3, 3 );
        hists.fill( p4().phi(), "histo_phi_" + suffix + "_mu", weight, 20, -3.15, 3.15 );

        float nvtxrewgt = isData ? 1. : nvtxRewgt( nvtx() );
        
        hists.fill( nvtx(), "histo_nvtxrewgt_nvtx_" + suffix + "_mu", weight * nvtxrewgt, 50, 0, 50 );
        hists.fill( evt_mt, "histo_nvtxrewgt_mt_" + suffix + "_mu", weight * nvtxrewgt, 20, 0, 200 );
        hists.fill( evt_met, "histo_nvtxrewgt_met_" + suffix + "_mu", weight * nvtxrewgt, 20, 0, 200 );
        hists.fill( p4().pt(), "histo_nvtxrewgt_ptvarbin_" + suffix + "_mu", weight * nvtxrewgt, nptbins, ptbins );
        hists.fill( p4().pt(), "histo_nvtxrewgt_ptvarbin_coarse_" + suffix + "_mu", weight * nvtxrewgt, nptbins_coarse,
                    ptbins_coarse );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), "histo_nvtxrewgt_conecorrptvarbin_" + suffix + "_mu", weight * nvtxrewgt,
                    nptbins, ptbins );
        hists.fill( p4().eta(), "histo_nvtxrewgt_etavarbin_" + suffix + "_mu", weight * nvtxrewgt, netabins, etabins_mu );
        hists.fill( p4().pt(), p4().eta(), "histo_nvtxrewgt_ptvarbin_etavarbin_" + suffix + "_mu", weight * nvtxrewgt, nptbins,
                    ptbins, netabins,
                    etabins_mu );
        hists.fill( p4().pt() * ( 1 + coneptcorr ), p4().eta(), "histo_nvtxrewgt_conecorrptvarbin_etavarbin_" + suffix + "_mu",
                    weight * nvtxrewgt,
                    nptbins, ptbins, netabins, etabins_mu );
        hists.fill( p4().pt(), "histo_nvtxrewgt_pt_" + suffix + "_mu", weight * nvtxrewgt, 40, 0, 200 );
        hists.fill( p4().eta(), "histo_nvtxrewgt_eta_" + suffix + "_mu", weight * nvtxrewgt, 20, -3, 3 );
        hists.fill( p4().phi(), "histo_nvtxrewgt_phi_" + suffix + "_mu", weight * nvtxrewgt, 20, -3.15, 3.15 );
    }

    //    if ( abs( id() ) == 11 )
    //    {
    //        if ( p4().pt() < 10. )
    //            return;
    //        else if ( p4().pt() < 15. )
    //        {
    //            hists.fill( evt_mt, "histo_pt15_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt15_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 20. )
    //        {
    //            hists.fill( evt_mt, "histo_pt20_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt20_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 25. )
    //        {
    //            hists.fill( evt_mt, "histo_pt25_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt25_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 30. )
    //        {
    //            hists.fill( evt_mt, "histo_pt30_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt30_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 35. )
    //        {
    //            hists.fill( evt_mt, "histo_pt35_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt35_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 50. )
    //        {
    //            hists.fill( evt_mt, "histo_pt50_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt50_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 70. )
    //        {
    //            hists.fill( evt_mt, "histo_pt70_mt_" + suffix + "_el", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt70_met_" + suffix + "_el", weight, 20, 0, 200 );
    //        }
    //    }
    //    else if ( abs( id() ) == 13 )
    //    {
    //        if ( p4().pt() < 10. )
    //            return;
    //        else if ( p4().pt() < 15. )
    //        {
    //            hists.fill( evt_mt, "histo_pt15_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt15_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 20. )
    //        {
    //            hists.fill( evt_mt, "histo_pt20_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt20_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 25. )
    //        {
    //            hists.fill( evt_mt, "histo_pt25_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt25_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 30. )
    //        {
    //            hists.fill( evt_mt, "histo_pt30_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt30_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 35. )
    //        {
    //            hists.fill( evt_mt, "histo_pt35_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt35_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 50. )
    //        {
    //            hists.fill( evt_mt, "histo_pt50_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt50_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //        else if ( p4().pt() < 70. )
    //        {
    //            hists.fill( evt_mt, "histo_pt70_mt_" + suffix + "_mu", weight, 20, 0, 200 );
    //            hists.fill( evt_met, "histo_pt70_met_" + suffix + "_mu", weight, 20, 0, 200 );
    //        }
    //    }



}

//________________________________________________________________________________________
void fillFakeRateHistograms( TasUtil::AutoHist& hists, TString label, float& evt_met, float& evt_mt, float& weight )
{
    //mt control region
    if ( evt_met > 30. && evt_mt > 80. && evt_mt < 120. )
        fill( hists, label + "ewk_cr", evt_mt, evt_met, weight );

    if ( evt_met < 30. && evt_mt > 80. && evt_mt < 120. )
        fill( hists, label + "lowmet_ewk_cr", evt_mt, evt_met, weight );

    if ( evt_met > 30. && p4().pt() > 50 )
        fill( hists, label + "highpt_cr", evt_mt, evt_met, weight );

    if ( evt_met > 30. && p4().pt() <= 50 && p4().pt() > 30 )
        fill( hists, label + "medpt_cr", evt_mt, evt_met, weight );

    if ( evt_met > 30. && p4().pt() <= 30 )
        fill( hists, label + "lowpt_cr", evt_mt, evt_met, weight );

    if ( evt_met > 30. )
        fill( hists, label + "cr", evt_mt, evt_met, weight );

    if ( evt_met > 50. && p4().pt() > 30 )
        fill( hists, label + "highpt_tightcr", evt_mt, evt_met, weight );

    if ( evt_met > 50. && p4().pt() <= 30 )
        fill( hists, label + "lowpt_tightcr", evt_mt, evt_met, weight );

    if ( evt_met > 50. )
        fill( hists, label + "tightcr", evt_mt, evt_met, weight );

    if ( evt_met < 20. )
        fill( hists, label + "lm", evt_mt, evt_met, weight );

    if ( p4().pt() > 30 )
        fill( hists, label + "highpt", evt_mt, evt_met, weight );

    if ( p4().pt() > 50 )
        fill( hists, label + "highpt50", evt_mt, evt_met, weight );

    if ( p4().pt() > 30. &&  p4().pt() <= 50 )
        fill( hists, label + "medpt", evt_mt, evt_met, weight );

    if ( evt_mt < 20. )
        fill( hists, label + "lmt", evt_mt, evt_met, weight );

    if ( evt_mt > 30. )
        fill( hists, label + "hmt", evt_mt, evt_met, weight );

    if ( evt_mt > 50. )
        fill( hists, label + "hmt50", evt_mt, evt_met, weight );

    if ( evt_mt > 70. )
        fill( hists, label + "hmt70", evt_mt, evt_met, weight );

    if ( evt_mt > 80. )
        fill( hists, label + "hmt80", evt_mt, evt_met, weight );

    if ( evt_mt > 120. )
        fill( hists, label + "hmt120", evt_mt, evt_met, weight );

    if ( evt_mt > 50. && p4().pt() > 30. )
        fill( hists, label + "hmt50pt30", evt_mt, evt_met, weight );

    if ( evt_mt > 70. && p4().pt() > 30. )
        fill( hists, label + "hmt70pt30", evt_mt, evt_met, weight );

    if ( evt_mt > 80. && p4().pt() > 30. )
        fill( hists, label + "hmt80pt30", evt_mt, evt_met, weight );

    if ( evt_mt > 120. && p4().pt() > 30. )
        fill( hists, label + "hmt120pt30", evt_mt, evt_met, weight );

    if ( evt_mt > 50. && p4().pt() > 50. )
        fill( hists, label + "hmt50pt50", evt_mt, evt_met, weight );

    if ( evt_mt > 70. && p4().pt() > 50. )
        fill( hists, label + "hmt70pt50", evt_mt, evt_met, weight );

    if ( evt_mt > 80. && p4().pt() > 50. )
        fill( hists, label + "hmt80pt50", evt_mt, evt_met, weight );

    if ( evt_mt > 120. && p4().pt() > 50. )
        fill( hists, label + "hmt120pt50", evt_mt, evt_met, weight );

    if ( evt_mt < 20. && evt_met < 20 )
    {
//        if ( abs( id() ) == 13 && label.IsNull() )
//        {
//            std::cout << "=====meas====" << std::endl;
//            std::cout << "printing event info for evt_event = " << lepton_tree.evt_event() << std::endl;
//            std::cout << " passId " <<  passId << std::endl;
//            std::cout << " passFO " <<  passFO << std::endl;
//            std::cout << " pt " <<  p4().pt() << std::endl;
//            std::cout << " nFOs_VVV " <<  nFOs_VVV() << std::endl;
//            std::cout << " nFOs_SS " <<  nFOs_SS() << std::endl;
//            std::cout << " evt_met " <<  evt_met << std::endl;
//            std::cout << " evt_mt " <<  evt_mt << std::endl;
//            std::cout << " prescale " << prescale << std::endl;
//            std::cout << " pass_trig " << pass_trig << std::endl;
//            std::cout << " njets40 " << njets40 << std::endl;
//            std::cout << "=====" << std::endl;
//        }
        fill( hists, label + "meas", evt_mt, evt_met, weight );

    }
}

//________________________________________________________________________________________
double nvtxRewgtMu( Lepton& lepton )
{
    if ( lepton.isData ) return 1;
    int nvtx = lepton.nvtx;
    double rewgt = 0;
    if ( nvtx == 1 ) rewgt = 12.0595;
    if ( nvtx == 2 ) rewgt = 8.92974;
    if ( nvtx == 3 ) rewgt = 9.18154;
    if ( nvtx == 4 ) rewgt = 5.44869;
    if ( nvtx == 5 ) rewgt = 3.89667;
    if ( nvtx == 6 ) rewgt = 7.17796;
    if ( nvtx == 7 ) rewgt = 8.54106;
    if ( nvtx == 8 ) rewgt = 5.06104;
    if ( nvtx == 9 ) rewgt = 3.65879;
    if ( nvtx == 10) rewgt = 3.00747;
    if ( nvtx == 11) rewgt = 2.24693;
    if ( nvtx == 12) rewgt = 1.87359;
    if ( nvtx == 13) rewgt = 1.55825;
    if ( nvtx == 14) rewgt = 1.29995;
    if ( nvtx == 15) rewgt = 1.09876;
    if ( nvtx == 16) rewgt = 0.97441;
    if ( nvtx == 17) rewgt = 0.829951;
    if ( nvtx == 18) rewgt = 0.774742;
    if ( nvtx == 19) rewgt = 0.690336;
    if ( nvtx == 20) rewgt = 0.602904;
    if ( nvtx == 21) rewgt = 0.559357;
    if ( nvtx == 22) rewgt = 0.460413;
    if ( nvtx == 23) rewgt = 0.413193;
    if ( nvtx == 24) rewgt = 0.347697;
    if ( nvtx == 25) rewgt = 0.318157;
    if ( nvtx == 26) rewgt = 0.284326;
    if ( nvtx == 27) rewgt = 0.24215;
    if ( nvtx == 28) rewgt = 0.197417;
    if ( nvtx == 29) rewgt = 0.179646;
    if ( nvtx == 30) rewgt = 0.140347;
    if ( nvtx == 31) rewgt = 0.146983;
    if ( nvtx == 32) rewgt = 0.106538;
    if ( nvtx == 33) rewgt = 0.0968753;
    if ( nvtx == 34) rewgt = 0.109652;
    if ( nvtx == 35) rewgt = 0.103228;
    if ( nvtx == 36) rewgt = 0.0758201;
    if ( nvtx == 37) rewgt = 0.100034;
    if ( nvtx == 38) rewgt = 0.118447;
    if ( nvtx >= 39) rewgt = 0.108058;
//    if ( nvtx == 39) return 0.224361;
//    if ( nvtx == 40) return 0.153384;
//    if ( nvtx == 41) return 0.08641;
//    if ( nvtx == 42) return 0.249793;
//    if ( nvtx == 43) return 0.419394;
//    if ( nvtx == 44) return 0.840061;
//    if ( nvtx == 45) return 1.05601;
//    if ( nvtx == 46) return 3.19624;
//    if ( nvtx == 47) return 1.76097;
//    if ( nvtx == 48) return 10.5195;
//    if ( nvtx == 49) return 0;
    return rewgt / 1.08601;
}

//________________________________________________________________________________________
double nvtxRewgtEl( Lepton& lepton )
{
    if ( lepton.isData ) return 1;
    int nvtx = lepton.nvtx;
    double rewgt = 0;
    if (nvtx == 1 ) rewgt = 6.88505;
    if (nvtx == 2 ) rewgt = 4.70385;
    if (nvtx == 3 ) rewgt = 7.32598;
    if (nvtx == 4 ) rewgt = 4.72944;
    if (nvtx == 5 ) rewgt = 3.85838;
    if (nvtx == 6 ) rewgt = 7.61054;
    if (nvtx == 7 ) rewgt = 8.87676;
    if (nvtx == 8 ) rewgt = 6.01298;
    if (nvtx == 9 ) rewgt = 4.49724;
    if (nvtx == 10) rewgt = 3.7141;
    if (nvtx == 11) rewgt = 2.94349;
    if (nvtx == 12) rewgt = 2.43554;
    if (nvtx == 13) rewgt = 2.08074;
    if (nvtx == 14) rewgt = 1.69239;
    if (nvtx == 15) rewgt = 1.50527;
    if (nvtx == 16) rewgt = 1.24766;
    if (nvtx == 17) rewgt = 1.09752;
    if (nvtx == 18) rewgt = 1.02464;
    if (nvtx == 19) rewgt = 0.847891;
    if (nvtx == 20) rewgt = 0.748406;
    if (nvtx == 21) rewgt = 0.644106;
    if (nvtx == 22) rewgt = 0.568709;
    if (nvtx == 23) rewgt = 0.510288;
    if (nvtx == 24) rewgt = 0.437237;
    if (nvtx == 25) rewgt = 0.354571;
    if (nvtx == 26) rewgt = 0.316947;
    if (nvtx == 27) rewgt = 0.224743;
    if (nvtx == 28) rewgt = 0.267746;
    if (nvtx == 29) rewgt = 0.205743;
    if (nvtx == 30) rewgt = 0.160799;
    if (nvtx == 31) rewgt = 0.161664;
    if (nvtx == 32) rewgt = 0.145897;
    if (nvtx == 33) rewgt = 0.147893;
    if (nvtx >= 34) rewgt = 0.099029;
//    if (nvtx == 35) return 0.137373;
//    if (nvtx == 36) return 0.109028;
//    if (nvtx == 37) return 0.091604;
//    if (nvtx == 38) return 0.20039;
//    if (nvtx == 39) return 0.170611;
//    if (nvtx == 40) return 0;
//    if (nvtx == 41) return 0.131135;
//    if (nvtx == 42) return 0;
//    if (nvtx == 43) return 0;
//    if (nvtx == 44) return 0;
//    if (nvtx == 45) return 0;
//    if (nvtx == 46) return 6.31619;
//    if (nvtx == 47) return 0;
//    if (nvtx == 48) return 0;
//    if (nvtx == 49) return 24.4347;
//    if (nvtx == 50) return 0;
    return rewgt / 1.38452;
}


//________________________________________________________________________________________
double nvtxRewgt( int nvtx )
{

// fSumw[0]=0, x=-0.5, error=0
// fSumw[1]=0, x=0.5, error=0
// fSumw[2]=11.9844, x=1.5, error=4.55465
// fSumw[3]=8.75933, x=2.5, error=1.65551
// fSumw[4]=9.1306, x=3.5, error=0.962118
// fSumw[5]=5.38545, x=4.5, error=0.357498
// fSumw[6]=3.84938, x=5.5, error=0.169243
// fSumw[7]=7.10142, x=6.5, error=0.233379
// fSumw[8]=8.45726, x=7.5, error=0.214584
// fSumw[9]=5.01207, x=8.5, error=0.106408
// fSumw[10]=3.61684, x=9.5, error=0.0657688
// fSumw[11]=2.97838, x=10.5, error=0.0482009
// fSumw[12]=2.2285, x=11.5, error=0.0333529
// fSumw[13]=1.8588, x=12.5, error=0.0264373
// fSumw[14]=1.54345, x=13.5, error=0.0214497
// fSumw[15]=1.28931, x=14.5, error=0.0178557
// fSumw[16]=1.09047, x=15.5, error=0.0154628
// fSumw[17]=0.964869, x=16.5, error=0.0141774
// fSumw[18]=0.824583, x=17.5, error=0.012804
// fSumw[19]=0.768344, x=18.5, error=0.0127023
// fSumw[20]=0.685475, x=19.5, error=0.0122317
// fSumw[21]=0.598741, x=20.5, error=0.0117341
// fSumw[22]=0.55269, x=21.5, error=0.0119456
// fSumw[23]=0.4556, x=22.5, error=0.0111601
// fSumw[24]=0.407472, x=23.5, error=0.0110971
// fSumw[25]=0.343969, x=24.5, error=0.0107676
// fSumw[26]=0.315303, x=25.5, error=0.0109747
// fSumw[27]=0.279933, x=26.5, error=0.0109031
// fSumw[28]=0.238095, x=27.5, error=0.0108403
// fSumw[29]=0.195887, x=28.5, error=0.0102764
// fSumw[30]=0.178236, x=29.5, error=0.0107143
// fSumw[31]=0.137694, x=30.5, error=0.0100946
// fSumw[32]=0.142796, x=31.5, error=0.0112742
// fSumw[33]=0.103904, x=32.5, error=0.0105019
// fSumw[34]=0.0944095, x=33.5, error=0.0112458
// fSumw[35]=0.105182, x=34.5, error=0.0136012
// fSumw[36]=0.100785, x=35.5, error=0.0150963
// fSumw[37]=0.0738785, x=36.5, error=0.0149246
// fSumw[38]=0.0974241, x=37.5, error=0.0205439
// fSumw[39]=0.115404, x=38.5, error=0.0282939
// fSumw[40]=0.104832, x=39.5, error=0.0318636
// fSumw[41]=0.217811, x=40.5, error=0.0611742
// fSumw[42]=0.149607, x=41.5, error=0.0614748
// fSumw[43]=0.125906, x=42.5, error=0.0729795
// fSumw[44]=0.243544, x=43.5, error=0.141345
// fSumw[45]=0.409703, x=44.5, error=0.238007
// fSumw[46]=0.819052, x=45.5, error=0.476631
// fSumw[47]=1.02546, x=46.5, error=0.729617
// fSumw[48]=3.08499, x=47.5, error=1.80208
// fSumw[49]=1.71352, x=48.5, error=1.72103
// fSumw[50]=10.2019, x=49.5, error=7.31305
// fSumw[51]=0, x=50.5, error=0

    if ( nvtx == 0 )
        return  0         ;

    if ( nvtx == 1 )
        return  12.0748   ;

    if ( nvtx == 2 )
        return  8.84592   ;

    if ( nvtx == 3 )
        return  8.70355   ;

    if ( nvtx == 4 )
        return  5.31321   ;

    if ( nvtx == 5 )
        return  3.78796   ;

    if ( nvtx == 6 )
        return  7.01165   ;

    if ( nvtx == 7 )
        return  8.41857   ;

    if ( nvtx == 8 )
        return  4.82683   ;

    if ( nvtx == 9 )
        return  3.58198   ;

    if ( nvtx == 10 )
        return  2.9254    ;

    if ( nvtx == 11 )
        return  2.19347   ;

    if ( nvtx == 12 )
        return  1.81965   ;

    if ( nvtx == 13 )
        return  1.51107   ;

    if ( nvtx == 14 )
        return  1.26134   ;

    if ( nvtx == 15 )
        return  1.07211   ;

    if ( nvtx == 16 )
        return  0.943931  ;

    if ( nvtx == 17 )
        return  0.804781  ;

    if ( nvtx == 18 )
        return  0.749968  ;

    if ( nvtx == 19 )
        return  0.671684  ;

    if ( nvtx == 20 )
        return  0.586063  ;

    if ( nvtx == 21 )
        return  0.543424  ;

    if ( nvtx == 22 )
        return  0.443598  ;

    if ( nvtx == 23 )
        return  0.397247  ;

    if ( nvtx == 24 )
        return  0.333098  ;

    if ( nvtx == 25 )
        return  0.306724  ;

    if ( nvtx == 26 )
        return  0.274128  ;

    if ( nvtx == 27 )
        return  0.230995  ;

    if ( nvtx == 28 )
        return  0.189151  ;

    if ( nvtx == 29 )
        return  0.173443  ;

    if ( nvtx == 30 )
        return  0.13398   ;

    if ( nvtx == 31 )
        return  0.140405  ;

    if ( nvtx == 32 )
        return  0.0990381 ;

    if ( nvtx == 33 )
        return  0.0925015 ;

    if ( nvtx == 34 )
        return  0.0998464 ;

    if ( nvtx == 35 )
        return  0.0981454 ;

    if ( nvtx == 36 )
        return  0.0707519 ;

    if ( nvtx == 37 )
        return  0.0952367 ;

    if ( nvtx >= 38 )
        return  0.112327  ;

    return 0;
}

//        //------------------------------
//        // Rebuild event level variables
//        //------------------------------
//
//        if ( lepton_tree.evt_event() == evt_event_to_print )
//        {
//            std::cout << "=====meas====" << std::endl;
//            std::cout << "printing event info for evt_event = " << lepton_tree.evt_event() << std::endl;
//            std::cout << " passId " <<  passId << std::endl;
//            std::cout << " passFO " <<  passFO << std::endl;
//            std::cout << " pt " <<  p4().pt() << std::endl;
//            std::cout << " nFOs_VVV " <<  nFOs_VVV() << std::endl;
//            std::cout << " nFOs_SS " <<  nFOs_SS() << std::endl;
//            std::cout << " evt_met " <<  evt_met << std::endl;
//            std::cout << " evt_mt " <<  evt_mt << std::endl;
//            std::cout << " prescale " << prescale << std::endl;
//            std::cout << " pass_trig " << pass_trig << std::endl;
//            std::cout << " njets40 " << njets40 << std::endl;
//            std::cout << "=====" << std::endl;
//
//        }
//        
//        // New event!
//        if ( prev_evt_event != lepton_tree.evt_event() )
//        {
//        
//        
////            std::cout << " prev_evt_event " << prev_evt_event << std::endl;
////            std::cout << " local_nFOs_VVV " <<  evt_lvl_var_passFO_p4.size() << std::endl;
////            std::cout << " local_nIds_VVV " <<  evt_lvl_var_passId_p4.size() << std::endl;
////            std::cout << " evt_met " <<  evt_met << std::endl;
////            std::cout << " lepton_tree.evt_event() " << lepton_tree.evt_event() << std::endl;
//
//            // We got a new event.
//            // Deal with what's already in the vectors and
//            // then later push this even'ts variable into the vector.
//            if ( prev_evt_event == evt_event_to_print ) printEvtLvlVar();
//        
//            int local_nFOs_VVV = evt_lvl_var_passFO_p4.size();
//            int local_nIds_VVV = evt_lvl_var_passId_p4.size();
//        
//            bool pass = false;
//            int idx_wtag = -1;
//            float pt = -999;
//            float met = -999;
//            float mt = -999;
//            float this_weight = 1;
//        
//            // Now if it's a one lepton bin do the usual
//            if ( local_nIds_VVV == 1 && local_nFOs_VVV == 1 )
//            {
//                if ( prev_evt_event == evt_event_to_print )
//                {
//                    printEvtLvlVar();
//                    std::cout << "diagnose" << std::endl;
//                    std::cout << evt_lvl_var_evt_met[0] << std::endl;
//                    std::cout << evt_lvl_var_evt_mt[0] << std::endl;
//                    std::cout << local_nIds_VVV << std::endl;
//                    std::cout << fabs( evt_lvl_var_passId_id[0] ) << std::endl;
//                    std::cout << fabs( evt_lvl_var_passId_p4[0].eta() ) << std::endl;
//                    std::cout << fabs( evt_lvl_var_passId_p4[0].pt() ) << std::endl;
//                    std::cout << evt_lvl_var_njets[0] << std::endl;
//                    std::cout << evt_lvl_var_pass_trig[0] << std::endl;
//                }
//                // Since I want to study the purity in the tight Id
//                if ( evt_lvl_var_evt_met[0] < 20. && evt_lvl_var_evt_mt[0] < 20. && local_nIds_VVV == 1 && fabs( evt_lvl_var_passId_id[0] ) == 13
//                        && fabs( evt_lvl_var_passId_p4[0].eta() ) < 2.4 && fabs( evt_lvl_var_passId_p4[0].pt() ) > 10. && evt_lvl_var_njets[0] > 0 
//                        && evt_lvl_var_pass_trig[0] == 1 )
//                {
//                    if ( prev_evt_event == evt_event_to_print )
//                        std::cout << "here" << std::endl;
//                    pass = true;
//                    pt = evt_lvl_var_passId_p4[0].pt();
//                    met = evt_lvl_var_evt_met[0];
//                    mt = evt_lvl_var_evt_mt[0];
//                }
//            }
//            // This is what I am trying to compare to
//            else if ( local_nFOs_VVV == 2 )
//            {
//                // First I need to construct dilepton mass
//                float mll = dilep_mass_from_FOs();
//        
//                float Mt0 = calculateMt( evt_lvl_var_passFO_p4[0], evt_lvl_var_evt_met[0], evt_lvl_var_evt_metPhi[0] );
//                float Mt1 = calculateMt( evt_lvl_var_passFO_p4[1], evt_lvl_var_evt_met[1], evt_lvl_var_evt_metPhi[1] );
//                hists.fill( Mt0, "Mt0" ,  this_weight,  50, 0, 150 );
//                hists.fill( Mt1, "Mt1" ,  this_weight,  50, 0, 150 );
//                // Tag W via one closer to MT = 80
//                idx_wtag = abs( Mt0 - 80. ) < abs( Mt1 - 80. ) ? 0 : 1;
//                pass = abs( evt_lvl_var_passId_id[idx_wtag] ) == 13;
//                pt = evt_lvl_var_passId_p4[idx_wtag].pt();
//                met = evt_lvl_var_evt_met[idx_wtag];
//                mt = evt_lvl_var_evt_mt[idx_wtag];
//
////                if ( abs( mll - 91.1876 ) > 15. )
////                {
////                    hists.fill( mll, "mll_nIds_VVV_eq2", this_weight, 80, 0, 200 );
////        
////                    // Now of the two leptons let's tag W
////                    if ( local_nIds_VVV == 2 )
////                    {
////                        float Mt0 = calculateMt( evt_lvl_var_passId_p4[0], evt_lvl_var_evt_met[0], evt_lvl_var_evt_metPhi[0] );
////                        float Mt1 = calculateMt( evt_lvl_var_passId_p4[1], evt_lvl_var_evt_met[1], evt_lvl_var_evt_metPhi[1] );
////                        hists.fill( Mt0, "Mt0" ,  this_weight,  50, 0, 150 );
////                        hists.fill( Mt1, "Mt1" ,  this_weight,  50, 0, 150 );
////                        // Tag W via one closer to MT = 80
////                        idx_wtag = abs( Mt0 - 80. ) < abs( Mt1 - 80. ) ? 0 : 1;
////                        pass = abs( evt_lvl_var_passId_id[idx_wtag] ) == 13;
////                        pt = evt_lvl_var_passId_p4[idx_wtag].pt();
////                        met = evt_lvl_var_evt_met[idx_wtag];
////                        mt = evt_lvl_var_evt_mt[idx_wtag];
////                    }
////                }
//            }
//        
//            if ( pass )
//            {
//                if ( pass && local_nIds_VVV == 1 )
//                {
//                    std::cout << std::endl;
//                    std::cout << " evt " << prev_evt_event << " pt = " << pt << " met = " << met << " mt = " << mt << " wgt = " << evt_lvl_var_weight[0] << std::endl;
//                }
//                hists.fill( local_nIds_VVV, "nIds_VVV",  evt_lvl_var_weight[0],  2, 1, 3 );
//                if ( pt > 170. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt170",  evt_lvl_var_weight[0],  2, 1, 3 );
//                else if ( pt > 120. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt120",  evt_lvl_var_weight[0],  2, 1, 3 );
//                else if ( pt >  70. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt70" ,  evt_lvl_var_weight[0],  2, 1, 3 );
//                else if ( pt >  50. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt50" ,  evt_lvl_var_weight[0],  2, 1, 3 );
//        
//                if ( local_nFOs_VVV == 1 || ( local_nFOs_VVV == 2 && abs( dilep_mass_from_FOs() - 91.1876 ) > 25. ) )
//                {
//                    hists.fill( local_nIds_VVV, "nIds_VVV_ZvetoTight",  this_weight,  2, 1, 3 );
//                    if ( pt > 170. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt170_ZvetoTight",  this_weight,  2, 1, 3 );
//                    else if ( pt > 120. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt120_ZvetoTight",  this_weight,  2, 1, 3 );
//                    else if ( pt >  70. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt70_ZvetoTight" ,  this_weight,  2, 1, 3 );
//                    else if ( pt >  50. ) hists.fill( local_nIds_VVV, "nIds_VVV_pt50_ZvetoTight" ,  this_weight,  2, 1, 3 );
//                }
//            }
//        
//            // Now the previous event is dealt with clear the vector
//            clearEvtLvlVar();
//        
//            // And save this round of event
//            saveEvtLvlVar( passFO, passId, evt_met, evt_metPhi, evt_mt, njets40, pass_trig, prescale, weight );
//        
//            prev_evt_event = lepton_tree.evt_event();
//        }
//        // Old event!
//        else
//        {
//            // If it's an old event just save
//            saveEvtLvlVar( passFO, passId, evt_met, evt_metPhi, evt_mt, njets40, pass_trig, prescale, weight );
//        }

//        if ( lepton_tree.evt_event() == evt_event_to_print )
//        {
//            std::cout << "=====meas2====" << std::endl;
//            std::cout << "printing event info for evt_event = " << lepton_tree.evt_event() << std::endl;
//            std::cout << " passId " <<  passId << std::endl;
//            std::cout << " passFO " <<  passFO << std::endl;
//            std::cout << " pt " <<  p4().pt() << std::endl;
//            std::cout << " nFOs_VVV " <<  nFOs_VVV() << std::endl;
//            std::cout << " nFOs_SS " <<  nFOs_SS() << std::endl;
//            std::cout << " evt_met " <<  evt_met << std::endl;
//            std::cout << " evt_mt " <<  evt_mt << std::endl;
//            std::cout << " prescale " << prescale << std::endl;
//            std::cout << " pass_trig " << pass_trig << std::endl;
//            std::cout << " njets40 " << njets40 << std::endl;
//            std::cout << "=====" << std::endl;
//        }

////========================================================================================
//// Lepton Baby Event Level Variable Rebuilding Tool
////========================================================================================
//
//std::vector<int> evt_lvl_var_passFOs;
//std::vector<int> evt_lvl_var_passIds;
//std::vector<int> evt_lvl_var_njets;
//std::vector<LV> evt_lvl_var_p4;
//std::vector<LV> evt_lvl_var_passFO_p4;
//std::vector<int> evt_lvl_var_passFO_id;
//std::vector<LV> evt_lvl_var_passId_p4;
//std::vector<int> evt_lvl_var_passId_id;
//std::vector<int> evt_lvl_var_pass_trig;
//std::vector<int> evt_lvl_var_prescale;
//std::vector<int> evt_lvl_var_dilep_mass;
//std::vector<float> evt_lvl_var_evt_met;
//std::vector<float> evt_lvl_var_evt_metPhi;
//std::vector<float> evt_lvl_var_evt_mt;
//std::vector<float> evt_lvl_var_weight;
//std::vector<int>   evt_lvl_var_FO_pass_trig;
//std::vector<int>   evt_lvl_var_FO_prescale;
//std::vector<int>   evt_lvl_var_FO_dilep_mass;
//std::vector<float> evt_lvl_var_FO_evt_met;
//std::vector<float> evt_lvl_var_FO_evt_metPhi;
//std::vector<float> evt_lvl_var_FO_evt_mt;
//std::vector<float> evt_lvl_var_FO_weight;
//
////________________________________________________________________________________________
//void printEvtLvlVar()
//{
//    std::cout << "evt_lvl_var_passFOs   : "; for ( auto& i : evt_lvl_var_passFOs )     std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_passIds   : "; for ( auto& i : evt_lvl_var_passIds )     std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_p4        : "; for ( auto& i : evt_lvl_var_p4 )          std::cout << i.pt() << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_p4 eta    : "; for ( auto& i : evt_lvl_var_p4 )          std::cout << i.eta()<< " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_passFO_p4 : "; for ( auto& i : evt_lvl_var_passFO_p4 )   std::cout << i.pt() << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_passFO_id : "; for ( auto& i : evt_lvl_var_passFO_id )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_passId_p4 : "; for ( auto& i : evt_lvl_var_passId_p4 )   std::cout << i.pt() << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_passId_id : "; for ( auto& i : evt_lvl_var_passId_id )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_pass_trig : "; for ( auto& i : evt_lvl_var_pass_trig )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_prescale  : "; for ( auto& i : evt_lvl_var_prescale  )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_njets     : "; for ( auto& i : evt_lvl_var_njets     )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_dilep_mass: "; for ( auto& i : evt_lvl_var_dilep_mass)   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_evt_met   : "; for ( auto& i : evt_lvl_var_evt_met  )    std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_evt_metPhi: "; for ( auto& i : evt_lvl_var_evt_metPhi  ) std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_evt_mt    : "; for ( auto& i : evt_lvl_var_evt_mt  )     std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_pass_trig : "; for ( auto& i : evt_lvl_var_FO_pass_trig )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_prescale  : "; for ( auto& i : evt_lvl_var_FO_prescale  )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_njets     : "; for ( auto& i : evt_lvl_var_FO_njets     )   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_dilep_mass: "; for ( auto& i : evt_lvl_var_FO_dilep_mass)   std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_evt_met   : "; for ( auto& i : evt_lvl_var_FO_evt_met  )    std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_evt_metPhi: "; for ( auto& i : evt_lvl_var_FO_evt_metPhi  ) std::cout << i      << " "; std::cout << std::endl;
//    std::cout << "evt_lvl_var_FO_evt_mt    : "; for ( auto& i : evt_lvl_var_FO_evt_mt  )     std::cout << i      << " "; std::cout << std::endl;
//}
//
////________________________________________________________________________________________
//void clearEvtLvlVar()
//{
//    // Now the previous event is dealt with clear the vector
//    evt_lvl_var_passFOs.clear();
//    evt_lvl_var_passIds.clear();
//    evt_lvl_var_njets.clear();
//    evt_lvl_var_p4.clear();
//    evt_lvl_var_passFO_p4.clear();
//    evt_lvl_var_passFO_id.clear();
//    evt_lvl_var_passId_p4.clear();
//    evt_lvl_var_passId_id.clear();
//    evt_lvl_var_pass_trig.clear();
//    evt_lvl_var_prescale.clear();
//    evt_lvl_var_dilep_mass.clear();
//    evt_lvl_var_evt_met.clear();
//    evt_lvl_var_evt_metPhi.clear();
//    evt_lvl_var_evt_mt.clear();
//    evt_lvl_var_weight.clear();
//    evt_lvl_var_FO_pass_trig.clear();
//    evt_lvl_var_FO_prescale.clear();
//    evt_lvl_var_FO_dilep_mass.clear();
//    evt_lvl_var_FO_evt_met.clear();
//    evt_lvl_var_FO_evt_metPhi.clear();
//    evt_lvl_var_FO_evt_mt.clear();
//    evt_lvl_var_FO_weight.clear();
//}
//
////________________________________________________________________________________________
//void saveEvtLvlVar( bool passFO, bool passId, float evt_met, float evt_metPhi, float evt_mt, int njets, bool pass_trig, int prescale, float weight )
//{
//    evt_lvl_var_passFOs.push_back( passFO );
//    evt_lvl_var_passIds.push_back( passId );
//    evt_lvl_var_p4.push_back( p4() );
//
//    passFO &= p4().pt() > 10.;
//    passId &= p4().pt() > 10.;
//
//    if ( passFO )
//        evt_lvl_var_passFO_p4.push_back( p4() );
//
//    if ( passFO )
//        evt_lvl_var_passFO_id.push_back( id() );
//
//    if ( passId )
//        evt_lvl_var_passId_p4.push_back( p4() );
//
//    if ( passId )
//        evt_lvl_var_passId_id.push_back( id() );
//
//    if ( passId )
//    {
//        evt_lvl_var_pass_trig.push_back( pass_trig );
//        evt_lvl_var_prescale.push_back( prescale );
//        evt_lvl_var_njets.push_back( njets );
//        evt_lvl_var_dilep_mass.push_back( dilep_mass() );
//        evt_lvl_var_evt_met.push_back( evt_met );
//        evt_lvl_var_evt_metPhi.push_back( evt_metPhi );
//        evt_lvl_var_evt_mt.push_back( evt_mt );
//        evt_lvl_var_weight.push_back( weight );
//    }
//    if ( passFO )
//    {
//        evt_lvl_var_FO_pass_trig.push_back( pass_trig );
//        evt_lvl_var_FO_prescale.push_back( prescale );
//        evt_lvl_var_FO_njets.push_back( njets );
//        evt_lvl_var_FO_dilep_mass.push_back( dilep_mass() );
//        evt_lvl_var_FO_evt_met.push_back( evt_met );
//        evt_lvl_var_FO_evt_metPhi.push_back( evt_metPhi );
//        evt_lvl_var_FO_evt_mt.push_back( evt_mt );
//        evt_lvl_var_FO_weight.push_back( weight );
//    }
//}
//
////________________________________________________________________________________________
//int nIds_VVV()
//{
//    int nIds_VVV_rtn = 0;
//
//    for ( auto& passId : evt_lvl_var_passIds )
//    {
//        if ( passId != 0 )
//            nIds_VVV_rtn++;
//    }
//
//    return nIds_VVV_rtn;
//}
//
////________________________________________________________________________________________
//float dilep_mass_from_FOs()
//{
//    // I will assume when I call this function I already have two FOs
//    if ( evt_lvl_var_passFO_p4.size() != 2 )
//        TasUtil::error( "I assumed I had two and only two fakeable object. This is not true!" );
//
//    return ( evt_lvl_var_passFO_p4[0] + evt_lvl_var_passFO_p4[1] ).mass();
//}

//    TH1F* histo_ptvarbin_meas_mu = ( TH1F*) hists.get( "histo_ptvarbin_meas_mu" );
//    TH1F* nIds_VVV_pt50 = ( TH1F*) hists.get( "nIds_VVV_pt50" );
//    TH1F* nIds_VVV_pt70 = ( TH1F*) hists.get( "nIds_VVV_pt70" );
//    TH1F* nIds_VVV_pt120 = ( TH1F*) hists.get( "nIds_VVV_pt120" );
//    TH1F* nIds_VVV_pt170 = ( TH1F*) hists.get( "nIds_VVV_pt170" );
//
//    if ( histo_ptvarbin_meas_mu && nIds_VVV_pt50 && nIds_VVV_pt70 && nIds_VVV_pt120 )
//    {
//        double ref50 = histo_ptvarbin_meas_mu->GetBinContent( 7 );
//        double ref70 = histo_ptvarbin_meas_mu->GetBinContent( 8 );
//        double ref120 = histo_ptvarbin_meas_mu->GetBinContent( 9 );
//        double val50 = nIds_VVV_pt50->GetBinContent( 1 );
//        double val70 = nIds_VVV_pt70->GetBinContent( 1 );
//        double val120 = nIds_VVV_pt120->GetBinContent( 1 );
//
//        std::cout << " pt 50 - 70 bin : " << ref50 << " " << val50 << std::endl;
//        std::cout << " pt 70 -120 bin : " << ref70 << " " << val70 << std::endl;
//        std::cout << " pt120 -170 bin : " << ref120 << " " << val120 << std::endl;
//    }
