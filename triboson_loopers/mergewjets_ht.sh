echo "merging stitched w+jets samples"
selection="presel_ss_ee_isotrackveto_loosebtag"
. mergewjets_cmd.sh $selection
selection="presel_ss_mm_isotrackveto_loosebtag"
. mergewjets_cmd.sh $selection
selection="presel_ss_em_isotrackveto_loosebtag"
. mergewjets_cmd.sh $selection
