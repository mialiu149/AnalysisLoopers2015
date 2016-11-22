'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os

lumi = 2.26
selection="yield_mbbCR_mct150_mt150_twobtag_V4"
table_header = '\\begin{tabular}{lcc}\n'
title = '1l CR   & &\\\\\n'
wfile="ws_stitch"
hist_prefix = 'h_lep_event_NEventsmbbCR'
input_dir = os.environ['analysis_output']

##cols to print out
label_col = ['sample',"100 GeV $<$ \met\ $<$ 200 GeV","\met\ $>$ 200 GeV"]
#label_col = ['sample','\crmbb','\mt\ $>$ 150 GeV','\mct\ $>$ 150 GeV','\mt\ $>$ 150 GeV, \mct\ $>$ 150 GeV']
#bins = ["100 GeV $<$ \met\ $<$ 200 GeV","\met\ $>$ 200 GeV"]
ncol = len(label_col) 
nbins=1
col_string = ''

# print out label column for different bins
for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'

row_inputs = [
              {'file':'data_'+selection+'_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':wfile+'_'+selection+'_hists.root','row_label':'\wl','hist_name':hist_prefix.replace('lep','lep_LF')},
              {'file':wfile+'_'+selection+'_hists.root','row_label':'\whf','hist_name':hist_prefix.replace('lep','lep_HF')},
              {'file':'wzbb_'+selection+'_hists.root','row_label':'\wzbb','hist_name':hist_prefix},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Single lepton top quark','hist_name':hist_prefix.replace('lep','lep_onelep')},
              {'file':'rare_'+selection+'_hists.root','row_label':'Rare','hist_name':hist_prefix},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Dilepton top quark','hist_name':hist_prefix.replace('lep','lep_dilep')}
              ]

datarows=[]
# print out data:
for j in range(nbins): 
    for row in row_inputs[0:1]:
        row_to_print = row['row_label']
        file = TFile(input_dir+'/'+row['file']) 
        print 'will use data input : ', input_dir+'/'+row['file']
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'$'
        datarows.append((row_to_print+'\\\\\n'))
print datarows
########################
# first one is data
data = TFile(input_dir+'/'+row_inputs[0]['file'])
hdata = data.Get(row_inputs[0]['hist_name'])
sum_bkg = hdata.Clone('sum_bkg')  # sum_bkg is used to calculate data-sumofMC

bkg1 = TFile(input_dir+'/'+row_inputs[1]['file'])
hbkg1 = bkg1.Get(row_inputs[1]['hist_name'])
mcsum_bkg = hbkg1.Clone('mcsum_bkg') # mcsum_bkg is used to calculate sum of mc.
########################

########################
bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den') # this is used to calculate (data-sumofotherMC)/ttbar2l
########################


####### calculate sums ###########
for i,row in enumerate(row_inputs[1:len(row_inputs)-1]):
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    sum_bkg.Add(hist,-1)
    
for i,row in enumerate(row_inputs[2:len(row_inputs)]):
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    mcsum_bkg.Add(hist)

################# find ratio  ################
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

##### now put content from hists to lists##########
sum_rows = []
mcsum_rows = []
ratio_rows=[]

for j in range(nbins):
    sum_row=''
    mcsum_row=''
    ratio_row=''
    for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        mcsum_row+="&${:.2f}".format(mcsum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(mcsum_bkg.GetBinError(i+1))+'$'
        ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
    sum_rows.append(sum_row)
    mcsum_rows.append(mcsum_row)
    ratio_rows.append(ratio_row)
#### so glad to be done with root ################

########print table##########
output = os.environ['analysis_output']+'/../tables/'
table = open(output+'table'+selection+'.tex','w')
table.write('%BEGINLATEX%\n')
table.write(table_header)
table.write('\\hline\n')
table.write('\\hline\n')

for j in range(nbins):
    table.write(datarows[j])
    table.write('\\hline\n')
    for row in row_inputs[1:]:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']

        ### print out the table 
        for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        table.write(row_to_print+'\\\\\n')
    table.write("\\hline\n")
    table.write("All MC"+mcsum_rows[j]+'\\\\\n') 
    table.write("data-others"+sum_rows[j]+'\\\\\n') 
    table.write("data-others/MC(2l top)"+ratio_rows[j]+'\\\\\n') 
    table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
print 'table saved in : ',output+'table'+selection+'.tex'
