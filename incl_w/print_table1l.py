'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
lumi = 2.1
table_header = '\\begin{tabular}{lcccccccc}\n'
title = '1l CR & & & & & & & &\\\\\n'
hist_prefix = 'h_lep_event_NEvents1lCR_yield'
#input_dir = '/home/users/mliu/public_html/rootfiles/CutHistos/Sync/'
input_dir = '/home/users/mliu/public_html/analysis2015/incl_w/V00-00-04/datavsmc/rootfiles/'
##cols to print out
#label_col = ['Sample','[250,300] GeV','[300,350]','[350,400] GeV','[400,500] GeV','[500,inf] GeV','njets==3']
label_col = ['Sample','[250,325],low dM','[325,Inf],low dM','[250,325],high dM','[325,450],high dM','[450,Inf],high dM','njets==3,high mass','compressed1','compressed2']
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
              {'file':'data_yield_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':'ttbar_yield_hists.root','row_label':'ttbar','hist_name':hist_prefix},
              {'file':'zjets_htbin_yield_hists.root','row_label':'z+jets','hist_name':hist_prefix},
              {'file':'wjets_htbin_yield_hists.root','row_label':'w+jets','hist_name':hist_prefix}
             ]
##table to print out####
table = open('table_test.tex','w')
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

for row in row_inputs[0:1]:
    row_to_print = row['row_label']
    file = TFile(input_dir+row['file']) 
    print input_dir+row['file']
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')

bkg1 = TFile(input_dir+row_inputs[0]['file'])
hbkg1 = bkg1.Get(row_inputs[0]['hist_name'])
sum_bkg = hbkg1.Clone('sum_bkg')

bkg2 = TFile(input_dir+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')

for row in row_inputs[1:]:
    row_to_print = row['row_label']
    sum_row = ''
    ratio_row = ''
    file = TFile(input_dir+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    if row_inputs.index(row) is not len(row_inputs)-1:
       sum_bkg.Add(hist,-1)
    ratio = sum_bkg.Clone('ratio')
    ratio.Divide(den)

    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
    table.write(row_to_print+'\\\\\n')
table.write("databkgsub"+sum_row+'\\\\\n') 
table.write("databkgsub"+ratio_row+'\\\\\n') 
table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')
