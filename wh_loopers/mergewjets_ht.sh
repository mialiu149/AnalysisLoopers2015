echo "merging stitched w+jets samples"
selection=$1
hadd -f ${analysis_output}/ws_stitch_htwithpt200_${selection}_hists.root ${analysis_output}/w1jets_nupt200_${selection}_hists.root ${analysis_output}/w2jets_nupt200_${selection}_hists.root ${analysis_output}/w3jets_nupt200_${selection}_hists.root ${analysis_output}/w4jets_nupt200_${selection}_hists.root  ${analysis_output}/ws_htbin_tostitch_200_${selection}_hists.root ${analysis_output}/ws_ht100_tostitch_200_${selection}_hists.root 
