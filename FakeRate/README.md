Run setup.sh first!!!
This will create a directory on nfs for the fake rate babies with the form:
      /nfs-7/userdata/[USER]/fake_rate_output/[tag]
      
babymaker subdirectory contains all code for making fake rate babies.
measurement_region subdirectory contains all code for obtaining the rake rate histos from the babies.
app_region subdirectory contains all code for comparing fake rate method to gen level in ttbar sample.

So run babymaker/do.C, then measurement_region/doAll.C, and finally app_region/doAll.C

Adjust which CMS3 ntuples to run on in babymaker/do.C
Adjust which babies to run on in measurement_region/doAll.C
Adjust which files to compare fake rate method to truth on in app_region/doAll.C
app_region/ScanChain.C picks up whatever histograms are saved after running measurement_region/doAll.C (measurement_region/rate_histos.root)

Before each new tag, change tag in setup.sh, babymaker/fakeratelooper.C, and measurement_region/doAll.C

