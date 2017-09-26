sh do_create_condor_tarball.sh -o condor_package.tgz code/ CORE/
# forCommissioningv5 and v4 in some combination
#~/public_html/tasutil/condor_concierge submit -e do_run_fakerate.sh -p condor_package.tgz -j joblists/joblist_ttbar.txt,joblists/joblist_2016doublemuon.txt,joblists/joblist_2016doubleeg.txt,joblists/joblist_dy.txt,joblists/joblist_wj.txt,joblists/joblist_qcd_mu.txt,joblists/joblist_qcd_el.txt
# forCommissioningv6 with nFOs_SS counter fixed to VVV loose counter
#python ~/public_html/tasutil/condor_concierge.py submit -e do_run_fakerate.sh -p condor_package.tgz -j joblists/joblist_forCommissioningv7.txt
#python ~/public_html/tasutil/condor_concierge.py submit -e do_run_fakerate.sh -p condor_package.tgz -j joblists/joblist_forCommissioningv9_xrootd.txt
python ~/public_html/tasutil/condor_concierge.py submit -e do_run_fakerate.sh -p condor_package.tgz -j joblists/joblist_final.txt
