echo "merging stitched w+jets samples"
selection=$1
hadd -f ${analysis_output}/chargeflip_stitch_${selection}_hists.root ${analysis_output}/chargeflip_ht100_${selection}_hists.root ${analysis_output}/chargeflip_${selection}_hists.root
hadd -f ${analysis_output}/jetfake_stitch_${selection}_hists.root ${analysis_output}/jetfake_ht100_${selection}_hists.root ${analysis_output}/jetfake_${selection}_hists.root
hadd -f ${analysis_output}/www_stitch_${selection}_hists.root ${analysis_output}/www_2l_ext1_${selection}_hists.root ${analysis_output}/www_2l_ext0_${selection}_hists.root
