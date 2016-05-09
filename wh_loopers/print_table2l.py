'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os

lumi = 2.26
selection="yield_2lCR_mbb"
table_header = '\\begin{tabular}{lcccccc}\n'
title = '2l CR& & & & &\\\\\n'
hist_prefix = 'h_lep_event_NEvents2lCR_'+selection
input_dir = os.environ['analysis_output']
print input_dir
##cols to print out
label_col = ['sample','mct$>$50','mct$>$100','mct$>$125','mct$>$150','mct$>$170']
col_string = ''
for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'
## inputs to print out rows
#row_inputs = [
#              {'file':'Stop_425_325.root','row_label':'$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (425,325)','hist_name':hist_prefix+'_Stop_425_325'}, 
#              {'file':'Stop_500_325.root','row_label':'$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (500,325)','hist_name':hist_prefix+'_Stop_500_325'}, 
#              {'file':'Stop_650_325.root','row_label':'$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (650,325)','hist_name':hist_prefix+'_Stop_650_325'}, 
#              {'file':'Stop_850_100.root','row_label':'$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (850,100)','hist_name':hist_prefix+'_Stop_850_100'}, 
#              {'file':'TTbar.root','row_label':'$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow \\ell\\ell$','hist_name':hist_prefix+'_TTbar2l'}, 
#              {'file':'TTbar.root','row_label':'semileptonic $\\mathrm{t}\\bar{\\mathrm{t}}$','hist_name':hist_prefix+'_TTbar1l'},
#              {'file':'WJets.root','row_label':'W+jets','hist_name':hist_prefix+'_WJets'},
#              {'file':'SingleTop.root','row_label':'Single top','hist_name':hist_prefix+'_SingleTop'},
#              {'file':'Rare.root','row_label':'Rare','hist_name':hist_prefix+'_Rare'}
#              ]
row_inputs = [
              {'file':'data_'+selection+'_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':'wjets_'+selection+'_hists.root','row_label':'w+jets','hist_name':hist_prefix},
              {'file':'top_'+selection+'_hists.root','row_label':'single top','hist_name':hist_prefix},
              {'file':'ttv_'+selection+'_hists.root','row_label':'ttv','hist_name':hist_prefix},
              {'file':'ttbar_'+selection+'_hists.root','row_label':'ttbar1l','hist_name':hist_prefix.replace('lep','lep_onelep')},
              {'file':'ttbar_'+selection+'_hists.root','row_label':'ttbar2l','hist_name':hist_prefix.replace('lep','lep_dilep')}
             ]
##table to print out####
table = open('table'+selection+'.tex','w')
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

table.write("MET [100,200] GeV & & & & &\\\\\n")
table.write("\\hline\n")

# print out data:
for row in row_inputs[0:1]:
    row_to_print = row['row_label']
    file = TFile(input_dir+'/'+row['file']) 
    print input_dir+'/'+row['file']
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')

########################
# first one is data
bkg1 = TFile(input_dir+'/'+row_inputs[0]['file'])
hbkg1 = bkg1.Get(row_inputs[0]['hist_name'])
sum_bkg = hbkg1.Clone('sum_bkg')
########################

########################
# the last background is 2l ttbar
bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')
########################

table.write("\\hline\n")

########################
########################
for i,row in enumerate(row_inputs[1:]):
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    #subtract it if it is not the last row, which is 2l ttbar
    if row['row_label'] is not 'ttbar2l':
       sum_bkg.Add(hist,-1)
    print row['row_label'],':',hist.GetBinContent(1)

########find ratio############
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

sum_row1 = ''
ratio_row1 = ''
sum_row2 = ''
ratio_row2 = ''
for i in range(0,5):
    sum_row1+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
    ratio_row1+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
for i in range(5,10):
    sum_row2+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
    ratio_row2+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
########print table##########
for row in row_inputs[1:]:
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    row_to_print = row['row_label']
    ### print out the table
    for i in range(0,5):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')

table.write("\\hline\n")
table.write("databkgsub"+sum_row1+'\\\\\n') 
table.write("kfactor"+ratio_row1+'\\\\\n') 
table.write('\\hline\hline\n')
table.write("MET [200,Inf] GeV & & & & &\\\\\n")
table.write("\\hline\n")

for row in row_inputs[0:1]:
    row_to_print = row['row_label']
    file = TFile(input_dir+'/'+row['file']) 
    print input_dir+'/'+row['file']
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(5,5+len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')

for row in row_inputs[1:]:
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    row_to_print = row['row_label']
    sum_row = ''
    ratio_row = ''
    for i in range(5,10):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
#        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        #ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')

table.write("\\hline\n")
table.write("databkgsub"+sum_row2+'\\\\\n') 
table.write("kfactor"+ratio_row2+'\\\\\n') 
table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')
print 'table saved in : ','table'+selection+'.tex'
