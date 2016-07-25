echo "merging stitched w+jets samples"
#selection="SR_met100_mt150_mbb_mct150_twobtag"
selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag" # get yields in SR
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="SR_met100_mt150_mct150_twobtag"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="1lCR_mbb_bveto_met100_mct150"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="1lCR_mbb_bveto_met100_mct150_muonly_ebonly"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="1lCR_mbb_bveto_met100_mct150_muonly_eeonly"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_mt150_twobtag_noabsiso"
selection="2lCR_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="2lCR_mbb_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="mbbCR_met100_mt50"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="2lCR_met100_mt150"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="mbbCR_met100_mt150"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_2lCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_1lCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
selection="yield_mbbCR"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
