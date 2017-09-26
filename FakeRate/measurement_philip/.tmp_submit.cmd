
universe=Vanilla
+DESIRED_Sites="UAF,T2_US_UCSD"
executable=do_run_fakerate.sh
arguments=/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_82.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_83.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_84.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_86.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_87.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_88.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_89.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_9.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_90.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_91.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_92.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_93.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_94.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_95.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_96.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_97.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_98.root,/hadoop/cms/store/user/phchang/condor/forCommissioningv7/QCD_Mu_Enriched_99.root fakerate_QCD_Mu_5.root
transfer_executable=True
transfer_input_files=condor_package.tgz
transfer_output_files = ""
+Owner = undefined
+project_Name = "cmssurfandturf"
log=./condor_logs/1503981286.log
output=./condor_logs/std_logs/1e.$(Cluster).$(Process).out
error=./condor_logs/std_logs/1e.$(Cluster).$(Process).err
notification=Never
should_transfer_files = YES
when_to_transfer_output = ON_EXIT
x509userproxy=/tmp/x509up_u31617
+taskname="joblist_final"
+jobnum="110"

queue
    