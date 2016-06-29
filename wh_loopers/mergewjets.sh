echo "merging stitched w+jets samples"
#selection="1lCR_mbb_bveto_met100_mct150_mt150"
#selection="1lCR_mbb_bveto_met100_mct150"
#selection="yield_1lCR"
#selection="1lCR_mbb_bveto_met100_mct150_muonly_noabsiso_reliso"
selection="SR_met100_mt150_mbb_mct150_twobtag"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="SR_met100_mt150_mct150_twobtag"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="1lCR_mbb_bveto_met100_mct150_elonly_noabsiso_reliso"
selection="1lCR_mbb_bveto_met100_mct150"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag_noabsiso"
selection="2lCR_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="2lCR_mbb_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="mbbCR_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_2lCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_1lCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_mbbCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag_lumi10"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="yield_2lCR_jecup"
#selection="mbbCR_met100_mct150_mt50"	
#selection="2lCR_met100_mt50_notrigger"	
#selection="1lCR_mbb_bveto_met100_mct150_notrigger"
#selection="mbbCR_met100_mct150_mt50_notrigger"	
#selection="mbbCR_met100_mct150_mt50"	
#selection="yield_mbbCR_met100_mt50"	
#selection="2lCR_mbb_met100_mt50"
