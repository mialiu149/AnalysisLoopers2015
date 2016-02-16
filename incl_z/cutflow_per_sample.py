from ROOT import *
import os,sys

gROOT.SetBatch(True)
gROOT.LoadMacro("vecUtils.h+")
gSystem.Load("libMinuit2.so");
gROOT.ProcessLine(".L stop_variables/JetUtil.cc+");
gROOT.ProcessLine(".L stop_variables/topness.cc+");
gROOT.ProcessLine(".L stop_variables/Davismt2.cc+");
gROOT.ProcessLine(".L stop_variables/MT2_implementations.cc+");
gROOT.ProcessLine(".L stop_variables/mt2w_bisect.cpp+");
gROOT.ProcessLine(".L stop_variables/mt2w.cc+");
gROOT.ProcessLine(".L GetCutFlow.C+");
ch = {'name':'phys14'}
dataset = []
input_dir = '/nfs-7/userdata/stopRun2/StopBabies_V728_met30_ge1l_ge2j_Phys14/'
output_dir = './results/'+sys.argv[2]

if not os.path.isdir('./results'):
   os.mkdir('./results')
if os.path.isdir(output_dir): 
   print 'output directory '+output_dir +' already exists'
   print 'enter a new name for outputs'
   sys.exit()
os.mkdir(output_dir)
os.mkdir(output_dir+'/hists')
os.mkdir(output_dir+'/plots')

chain  = TChain("t")
chain.Add(input_dir+'WJets.root')
ScanChain(chain,True,-1,'test')
filelist = open(sys.argv[1])
for line in filelist:
    filename  = line.strip()
    ch[filename.replace('.root','')] = TChain("t")
    ch[filename.replace('.root','')].Add(input_dir+filename)
    print filename.replace('.root','')
    #myfile = TFile(input_dir+filename)
    #chain = gDirectory.Get("t")
    #ScanChain(ch[filename.replace('.root','')],True,-1,filename.replace('.root',''))
    #myfile.Close()    
#for i,sample in enumerate(dataset_toloop):
#    ScanChain(ch[i],True,-1,sample,output_dir)

print '################ finished loops, gonna make plots now####################'
