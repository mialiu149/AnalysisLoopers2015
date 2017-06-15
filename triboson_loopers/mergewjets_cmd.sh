echo "merging stitched w+jets samples"
selection=$1
hadd -f ${analysis_output}/wjets_stitch_${selection}_hists.root ${analysis_output}/wjets_ht100_${selection}_hists.root ${analysis_output}/wjets_htbin_${selection}_hists.root
hadd -f ${analysis_output}/zjets_stitch_${selection}_hists.root ${analysis_output}/zjets_ht100_${selection}_hists.root ${analysis_output}/zjets_htbin_${selection}_hists.root
hadd -f ${analysis_output}/www_stitch_${selection}_hists.root ${analysis_output}/www_2l_ext1_${selection}_hists.root ${analysis_output}/www_2l_ext0_${selection}_hists.root
