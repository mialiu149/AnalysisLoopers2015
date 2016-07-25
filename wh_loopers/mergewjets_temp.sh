echo "merging stitched w+jets samples"
#selection="1lCR_mbb_bveto_met100_mct150_mt150"
#selection="1lCR_mbb_bveto_met100_mct150"
#selection="yield_1lCR"
#selection="1lCR_mbb_bveto_met100_mct150_muonly_noabsiso_reliso"
#selection="wjetsval_genmet200"
selection="wjetsval_nupt"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="wjetsval_nupt_met200"
#hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="mbbCR_met100_mct150_mt50"	
#selection="yield_mbbCR_met100_mt50"	
#selection="2lCR_mbb_met100_mt50"
#hadd -f ${analysis_output}/wjets_stitch.root ${analysis_output}/w1jets_nupt200_${selection}_hists.root ${analysis_output}/w2jets_nupt200_${selection}_hists.root ${analysis_output}/w3jets_nupt200_${selection}_hists.root ${analysis_output}/w4jets_nupt200_${selection}_hists.root ${analysis_output}/w1jets_${selection}_hists.root ${analysis_output}/w2jets_${selection}_hists.root ${analysis_output}/w3jets_${selection}_hists.root ${analysis_output}/w4jets_${selection}_hists.root
