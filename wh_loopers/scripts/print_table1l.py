'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os

lumi = 2.26
selection="yield_1lCR_mct170_mt150_bveto_V4"
table_header = '\\begin{tabular}{lcc}\n'
title = '1l CR   & &\\\\\n'
hist_prefix = 'h_lep_event_NEvents1lCR'
input_dir = os.environ['analysis_output']
wfile="ws_stitch"
#wfile="ws_stitch_njets"
label_col = ['sample','\mt\ $>$ 50 GeV','\mt\ $>$ 120 GeV','\mt\ $>$ 150 GeV']
nbins=1
#bins = ["MET [50,100] GeV","MET [100,125] GeV  & &\\\\\n","MET [125,150] GeV  & &\\\\\n","MET [150,200] GeV   & &\\\\\n","MET [200,Inf] GeV & &\\\\\n"]
bins = ["\met\ $>$ 100 GeV"]
ncol = len(label_col)-1
nbins=len(bins)
col_string = ''

for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'

## inputs to print out rows
row_inputs = [
              {'file':'data_'+selection+'_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Dilepton top quark','hist_name':hist_prefix.replace('lep','lep_dilep')},
              {'file':wfile+'_'+selection+'_hists.root','row_label':'\whf','hist_name':hist_prefix.replace('lep','lep_HF')},
              {'file':'wzbb_'+selection+'_hists.root','row_label':'\wzbb','hist_name':hist_prefix},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Single lepton top quark','hist_name':hist_prefix.replace('lep','lep_onelep')},
              {'file':'rare_'+selection+'_hists.root','row_label':'Rare','hist_name':hist_prefix},
              {'file':wfile+'_'+selection+'_hists.root','row_label':'\wl','hist_name':hist_prefix.replace('lep','lep_LF')}
             ]
##table to print out####
datarows=[]
# print out data:
for j in range(nbins): 
    for row in row_inputs[0:1]:
        row_to_print = row['row_label']
        file = TFile(input_dir+'/'+row['file']) 
        print input_dir+'/'+row['file']
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
            #row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'$'
        datarows.append((row_to_print+'\\\\\n'))
#######################

data = TFile(input_dir+'/'+row_inputs[0]['file'])
hdata = data.Get(row_inputs[0]['hist_name'])
sum_bkg = hdata.Clone('sum_bkg')

bkg1 = TFile(input_dir+'/'+row_inputs[1]['file'])
hbkg1 = bkg1.Get(row_inputs[1]['hist_name'])
mcsum_bkg = hbkg1.Clone('mcsum_bkg')
########################

########################
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

bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

sum_rows = []
ratio_rows=[]
mcsum_rows = []

for j in range(nbins):
    sum_row=''
    ratio_row=''
    mcsum_row=''
    for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        mcsum_row+="&${:.2f}".format(mcsum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(mcsum_bkg.GetBinError(i+1))+'$'
        ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
    sum_rows.append(sum_row)
    mcsum_rows.append(mcsum_row)
    ratio_rows.append(ratio_row)

########print table##########
output = os.environ['analysis_output']+'/../tables/'
table = open(output+'table'+selection+wfile+'.tex','w')
table.write('%BEGINLATEX%\n')
#table.write('\\begin{table}\n')
table.write('\\begin{center}\n')
table.write(table_header)
table.write('\\hline\n')
table.write('& 125 GeV $<$ \\met$<$200 GeV &\\met $>$ 200 GeV\\ \\n')
table.write('\\hline\n')

for j in range(nbins):
    table.write('\\hline\n')
    table.write(datarows[j])
    table.write('\\hline\n')
    for row in row_inputs[1:]:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']
        for i in range((ncol-1)*j,(ncol-1)*j+(ncol-1)):
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        table.write(row_to_print+'\\\\\n')
    table.write("\\hline\n")
    table.write("All MC"+mcsum_rows[j]+'\\\\\n') 
    table.write("data-others"+sum_rows[j]+'\\\\\n') 
    table.write("data-others/MC(W+LF)"+ratio_rows[j]+'\\\\\n') 
    table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
#table.write('\\end{table}\n')
table.write('%ENDLATEX%')
print 'table saved in : ',output+'table'+selection+wfile+'.tex'
