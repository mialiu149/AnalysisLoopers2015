echo "merging stitched w+jets samples"
#selection="SR_SRMultiBin_V5_yield_mbb_mct150_mt150_met100_twobtag"
#selection="SR_SRMultiBin_V5_yield_mbb_mct170_mt150_met100_twobtag_mix" # get yields in SR
selection="SR_mt150_mbb_mct150_twobtag_mix" # this is the SR
selection="SR_mt150_mbb_mct150_highMET_twobtag_mix" # this is the SR
selection="SR_SRMultiBin_V4_yield_mbb_mct150_mt150_met100_twobtag_mix_ptb125"
selection="SR_mt150_mbb_mct150_lowMET_twobtag_mix"
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix_ptl100" # this is the SR
selection="SR_SRMultiBin_V8_yield_mbb_mct170_mt150_met100_twobtag_mix" # get yields in SR
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix" # this is the SR
selection="SR_mt150_mbb_mct170_lowMET_twobtag_mix_mad"
hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
#selection="SR_SRMultiBin_V4_yield_mbb_mct170_mt150_met100_twobtag_mix" # get yields in SR
#hadd -f ${analysis_output}/ws_stitch_${selection}_hists.root ${analysis_output}/ws_ht100_${selection}_hists.root ${analysis_output}/ws_htbin_${selection}_hists.root
