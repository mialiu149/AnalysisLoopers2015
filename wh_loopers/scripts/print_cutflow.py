from ROOT import TH1F,TFile
import os
selection="cutflow"

def getcf(sample):    
#    input_dir = os.environ['analysis_output']
    input_dir = "/home/users/mliu/public_html/analysis2015/wh_loopers/V00-05-25/datavsmc/rootfiles/"
    f =  TFile(input_dir+"/"+sample+'_'+selection+'_hists.root')
    hist = f.Get("h_lep_event_NEventsSRCutflow_"+selection)
    cutflow = []
    for i in range(1,13):
        cutflow.append(hist.GetBinContent(i))
    return cutflow

def getcuteff(sample):
    cutflow=getcf(sample)
    cutflowshifted = cutflow[:]
    del(cutflowshifted[-1])
    cutflowshifted.insert(0,cutflow[0])
    cuteff = []
    for x,y in zip(cutflow,cutflowshifted):
        cuteff.append(float(x)/float(y))
    return cuteff

def printtableheader(samples,title):
    col_string = ''
    for i,col in enumerate(samples):
        if i is len(samples)-1:
           col_string+= col
        else:col_string+= col+'&'

    table_header = '\\begin{tabular}{l'+ 'c'*len(samples) +'}\n'
    print '%BEGINLATEX%\n'
    print '\\begin{table}\n'
    print '\\begin{center}\n'
    print '\\small\n'
    print table_header
    print '\\hline\n'
    print title
    print '\\hline\n'
    print col_string+'\\\\\n'
    print '\\hline\n' 
#def printrow():

def printtableend():
    print "\\hline\n"
    print '\\end{tabular}\n'
    print '\\end{center}\n'
    print '\\end{table}\n'

if __name__ == "__main__":
   #sample = "wh_350_1"
   #sample = "wh_250_80"
   #sample = "wh_300_80"
   #sample = "ttbar2l"
   samples = ["wh_250_1","wh_350_1","wh_225_80","wh_300_80","ttbar2l"]
   cuts = ['total','trigger','1 lep','2nd lep veto','track veto','tau veto','==2jets','==2 btags','met > 100','mt > 150','mbb window','mct > 150' ]
   cuteff = [getcuteff(sample) for sample in samples]
   #for sample,ce in zip(samples,cuteff):       
   #for cut,y in zip(cuts,ce):
   printtableheader(samples, "selection efficiency") 

   for i,cut in enumerate(cuts):
       stringtoprint = ''
       for sample in samples:
           stringtoprint+= "{:.3f}".format(cuteff[samples.index(sample)][i])+'&'
       print cut, '&',stringtoprint

   printtableend()