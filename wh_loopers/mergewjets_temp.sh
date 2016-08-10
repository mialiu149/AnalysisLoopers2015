echo "merging stitched w+jets samples"
#selection="SR_met100_mt150_mbb_mct150_twobtag"
selection="1lCR_mbb_bveto_met100_mct150_mt250"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
