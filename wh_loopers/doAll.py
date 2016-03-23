from ROOT import *
import os,sys

gROOT.SetBatch(True)
gROOT.LoadMacro("vecUtils.h+")
gSystem.Load("/home/users/haweber/oxbridgelibrary/lib/liboxbridgekinetics-1.0.so")
gInterpreter.AddIncludePath("/home/users/haweber/oxbridgelibrary/include/oxbridgekinetics-1.0");
gInterpreter.AddIncludePath("/home/users/haweber/oxbridgelibrary/include")
gROOT.ProcessLine(".L /home/users/haweber/oxbridgelibrary/include/Davismt2.cc+")
gROOT.ProcessLine(".L topness.cc+")
gROOT.ProcessLine(".L ScanChainTemp.C+")

ch = []
dataset = []
#input_dir = '/nfs-7/userdata/stop2015/babies_4May2015/'
input_dir = '/nfs-7/userdata/stopRun2/StopBabies_V07_02_08_met30_ge1lep_2jskim/'
output_dir = './results/'+sys.argv[1]

if not os.path.isdir('./results'):
   os.mkdir('./results')
if os.path.isdir(output_dir): 
   print 'output directory '+output_dir +' already exists'
   print 'enter a new name for outputs'
   sys.exit()
os.mkdir(output_dir)
os.mkdir(output_dir+'/hists')
os.mkdir(output_dir+'/plots')

ch_ttbar = TChain("t")
ch_ttbar.Add(input_dir+'ttbar.root')
ch.append(ch_ttbar)
dataset.append('TTbar')

ch_singleT = TChain('t')
ch_singleT.Add(input_dir+'t_sch.root')
ch_singleT.Add(input_dir+'tbar_sch.root')
ch_singleT.Add(input_dir+'t_tch.root')
ch_singleT.Add(input_dir+'tbar_tch.root')
ch_singleT.Add(input_dir+'t_tW.root')
ch_singleT.Add(input_dir+'tbar_tW.root')
ch.append(ch_singleT)
dataset.append('SingleT')

ch_TTV = TChain('t')
ch_TTV.Add(input_dir+'ttwjets.root')
ch_TTV.Add(input_dir+'ttzjets.root')
ch.append(ch_TTV)
dataset.append('TTV')

ch_WJets = TChain('t')
ch_WJets.Add(input_dir+'wjets.root')
ch.append(ch_WJets)
dataset.append('WJets')

ch_VV = TChain('t')
ch_VV.Add(input_dir+'wzjets.root')
ch_VV.Add(input_dir+'zz.root')
ch.append(ch_VV)
dataset.append('VV')

#ch_DYJets = TChain('t')
#ch_DYJets.Add(input_dir+'dyjets.root')
#ch.append(ch_DYJets)
#dataset.append('DYJets')

ch_Stop_425_325 = TChain('t')
ch_Stop_425_325.Add(input_dir+'stop_425_325.root')
ch.append(ch_Stop_425_325)
dataset.append('Stop_425_325')

ch_Stop_500_325 = TChain('t')
ch_Stop_500_325.Add(input_dir+'stop_500_325.root')
ch.append(ch_Stop_500_325)
dataset.append('Stop_500_325')

ch_Stop_650_325 = TChain('t')
ch_Stop_650_325.Add(input_dir+'stop_650_325.root')
ch.append(ch_Stop_650_325)
dataset.append('Stop_650_325')

ch_Stop_850_100 = TChain('t')
ch_Stop_850_100.Add(input_dir+'stop_850_100.root')
ch.append(ch_Stop_850_100)
dataset.append('Stop_850_100')

test = False
if test: dataset_toloop = dataset[:1]
else: dataset_toloop = dataset

for i,sample in enumerate(dataset_toloop):
    ScanChain(ch[i],True,-1,sample,output_dir)

print '################ finished loops, gonna make plots now####################'
gROOT.ProcessLine('.L dataMCplotMaker.cc+')
file = TFile(output_dir+'/hists/TTbar.root')
SetTDRStyle()
bgnames = ["TTbar","SingleT","TTV","WJets","VV"]
signames = ["Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"]
#bgnames = ["TTbar","SingleT","TTV","VV"]
sigfiles = map(lambda x:TFile(output_dir+'/hists/'+x+'.root'),signames)
bgfiles = map(lambda x:TFile(output_dir+'/hists/'+x+'.root'),bgnames)
hists = []
#for k in file.GetListOfKeys():hists.append(k.GetName())
hists = ["PostAll_Topness_TTbar","PreMT_Topness_TTbar","Topness_TTbar"]
##loop over histograms to plot
for hist in hists:
    bghist = []
    sighist = []    
    options = "--outputName " + output_dir+'/plots/' + hist  + " --xAxisLabel " + hist + " --noXaxisUnit --energy 13 --lumi 10 --legendTextSize 0.02  --preserveBackgroundOrder --legendUp 0.05 --legendRight -0.2"
    for ibg,bg in enumerate(bgnames):
        h1 = TH1F()
        h1 = bgfiles[ibg].Get(hist.replace('TTbar',bg))
#        if  not hZee.InheritsFrom("TH1"):
        bghist.append(h1)
    for isig,sig in enumerate(signames):
        h1 = TH1F()
        h1 = sigfiles[isig].Get(hist.replace('TTbar',sig))
        sighist.append(h1)

    bghist_vector = std.vector('TH1F*')()
    bghist_vector.clear()
    sighist_vector = std.vector('TH1F*')()
    sighist_vector.clear()
    bgnames_vector = std.vector(string)()
    bgnames_vector.clear()
    signames_vector = std.vector(string)()
    signames_vector.clear()
    for item in bghist:bghist_vector.push_back(item)
    for item in sighist:sighist_vector.push_back(item)
    for item in bgnames:bgnames_vector.push_back(item)
    for item in signames:signames_vector.push_back(item)
    null = TH1F()
    #dataMCplotMaker(null,bghist_vector,bgnames,"sig x10","",options,sighist_vector,signames)
    dataMCplotMaker(null,bghist_vector,bgnames_vector,"sig x10","",options,sighist_vector,signames_vector)
#    dataMCplotMaker(null,bghist,bgnames,"sig x10","",options,sighist,signames)
