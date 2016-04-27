'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os
from zbi import zbi

print zbi(46,152,0.30)
print zbi(26,43,0.20)

lumi = 10
#selection="SR_yield_2btags_2jets_mbb100_mct160"
selection='yield_2lCR'
table_header = '\\begin{tabular}{lccc}\n'
title = 'CR &  Mt $>$ 120 & &\\\\\n'
hist_prefix = 'h_lep_event_NEvents2lCR_'+selection
input_dir = os.environ['analysis_output']
print input_dir
#input_dir = '/home/users/mliu/public_html/analysis2015/wh_loopers/V00-00-03/datavsmc/rootfiles/'
##cols to print out
label_col = ['Sample','MET[100,125]','MET[125,175]', 'MET[175,inf]']
              
col_string = ''
for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'
## inputs to print out rows
row_inputs = [
              {'file':'wh_225_80_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (225,80)','hist_name':hist_prefix}, 
              {'file':'wh_250_1_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (250,1)','hist_name':hist_prefix}, 
              {'file':'wh_300_80_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (300,80)','hist_name':hist_prefix}, 
              {'file':'wh_350_1_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (350,1)','hist_name':hist_prefix}, 
              {'file':'ttbar_'+selection+'_hists.root','row_label':'$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow \\ell\\ell$','hist_name':hist_prefix.replace('lep','lep_dilep')}, 
              {'file':'ttbar_'+selection+'_hists.root','row_label':'semileptonic $\\mathrm{t}\\bar{\\mathrm{t}}$','hist_name':hist_prefix.replace('lep','lep_onelep')},
              {'file':'wbb_'+selection+'_hists.root','row_label':'W+bb','hist_name':hist_prefix},
              {'file':'top_'+selection+'_hists.root','row_label':'Single top','hist_name':hist_prefix},
              {'file':'ttv_'+selection+'_hists.root','row_label':'TTV','hist_name':hist_prefix},
              {'file':'diboson_'+selection+'_hists.root','row_label':'Diboson','hist_name':hist_prefix}
              ]
#table to print out####
table = open('table_madgrah'+selection+'.tex','w')
table.write('%BEGINLATEX%\n')
table.write('\\begin{table}\n')
table.write('\\begin{center}\n')
table.write('\\small\n')
table.write(table_header)
table.write('\\hline\n')
table.write(title)
table.write('\\hline\n')
table.write(col_string+'\\\\\n')
table.write('\\hline\n')

#signals
bkg1 = TFile(input_dir+'/'+row_inputs[4]['file'])
hbkg1 = bkg1.Get(row_inputs[4]['hist_name'])
sum_bkg = hbkg1.Clone('sum_bkg')

bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')

for row in row_inputs[4:]:
    row_to_print = row['row_label']
    sum_row = ''
    ratio_row = ''
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    if row_inputs.index(row) is not len(row_inputs)-1 and row_inputs.index(row) is not 4:
       sum_bkg.Add(hist)
#    ratio = sum_bkg.Clone('ratio')
#    ratio.Divide(den)

    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
     #   ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n') # sum of backgrounds
table.write("Total bkg"+sum_row+'\\\\\n') 
#table.write("kfactor"+ratio_row+'\\\\\n') 
for row in row_inputs[0:4]:
    row_to_print = row['row_label']
    file = TFile(input_dir+'/'+row['file']) 
    print input_dir+'/'+row['file']
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(len(label_col)-1):
        sig = hist.GetBinContent(i+1)
        bg = sum_bkg.GetBinContent(i+1)
        bgrelunc = 0.3
#        Zbi = zbi(sig,bg,bgrelunc) 
#        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$' + '('+"{:.2f}".format(Zbi)+')'
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')
print "wtf"


table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')
