echo "merging fake background estimations"
selection=$1
hadd -f $analysis_output/fakerate_${selection}_hists.root /home/users/mliu/public_html/analysis/triboson_loopers/sr_studies_v7/sr_studies/rootfiles/chargeflip_stitch_${selection}_hists.root /home/users/mliu/public_html/analysis/triboson_loopers/sr_studies_v7/sr_studies/rootfiles/data_${selection}_hists.root /home/users/mliu/public_html/analysis/triboson_loopers/sr_studies_v7/sr_studies/rootfiles/gammafake_${selection}_hists.root /home/users/mliu/public_html/analysis/triboson_loopers/sr_studies_v7/sr_studies/rootfiles/truess_${selection}_hists.root /home/users/mliu/public_html/analysis/triboson_loopers/sr_studies_v7/sr_studies/rootfiles/lostlep_${selection}_hists.root
