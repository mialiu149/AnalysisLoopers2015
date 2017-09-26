#!/bin/env python

import os
import sys
import glob

def splitList(lst, n):
    return [lst[i:i+n] for i in range(0,len(lst),n)]

def make_joblist(pattern, version):
    lepbabyrootfiles = glob.glob("/hadoop/cms/store/user/phchang/condor/forCommissioningv"+str(version)+"/*"+pattern+"*.root")
    combinedlist = splitList(lepbabyrootfiles, 30)
    for index, dataset in enumerate(combinedlist):
        print ",".join(dataset), "fakerate_"+pattern+"_"+str(index)+".root"

#def make_joblist(pattern):
#    lepbabyrootfiles = glob.glob("/hadoop/cms/store/user/phchang/condor/forCommissioningv9/*"+pattern+"*.root")
#    combinedlist = splitList(lepbabyrootfiles, 30)
#    for index, dataset in enumerate(combinedlist):
#        print ",".join(dataset), "fakerate_"+pattern+"_"+str(index)+".root"

def make_joblist_v7(pattern):
    lepbabyrootfiles = glob.glob("/hadoop/cms/store/user/phchang/condor/forCommissioningv7/*"+pattern+"*.root")
    combinedlist = splitList(lepbabyrootfiles, 30)
    for index, dataset in enumerate(combinedlist):
        print ",".join(dataset), "fakerate_"+pattern+"_"+str(index)+".root"

make_joblist("DoubleMuon", 12)
make_joblist("DoubleEG", 12)
make_joblist("DY_madgraph", 11)
make_joblist("TTbar", 11)
make_joblist("WJets_madgraph", 11)
make_joblist("WW", 9)
make_joblist("WZ", 9)
make_joblist("ZZ", 9)
make_joblist("QCD_EM", 7)
make_joblist("QCD_bcToE", 7)
make_joblist("QCD_Mu", 7)
