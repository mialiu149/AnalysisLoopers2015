'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os

lumi = 2.1
selection = 'SR_yield_met_trigger'
table_header = '\\begin{tabular}{lcccccccc}\n'
title = 'SR & & & & & & & &\\\\\n'
hist_prefix = 'h_lep_event_NEventsSR_'+selection
input_dir = os.environ['analysis_output']
#print input_dir
##cols to print out
#/jes_nominal_ttz_btag_SR_yield_met_trigger_btagsf_heavy_UP_hists.root
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
              #{'file':'jes_nominal_ttz_btag_'+selection+'_hists.root','row_label':'nominal','hist_name':hist_prefix},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale0_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale0'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale1_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale1'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale2_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale2'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale3_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale3'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale4_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale4'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale5_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale5'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale6_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale6'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale7_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale7'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_scale8_hists.root','row_label':'nominal','hist_name':hist_prefix+'_scale8'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_pdf_alpha1_hists.root','row_label':'nominal','hist_name':hist_prefix+'_pdf_alpha1'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_pdf_alpha2_hists.root','row_label':'nominal','hist_name':hist_prefix+'_pdf_alpha2'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_pdf_up_hists.root','row_label':'nominal','hist_name':hist_prefix+'_pdf_up'},
              {'file':'jes_nominal_ttz_btag_'+selection+'_pdf_dn_hists.root','row_label':'nominal','hist_name':hist_prefix+'_pdf_dn'}
             ]
##table to print out####
table = open('tableSR_scale_pdf.tex','w')
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
    file = TFile(input_dir+'/'+row['file']) 
    print input_dir+'/'+row['file']
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')

bkg1 = TFile(input_dir+'/'+row_inputs[0]['file'])
hbkg1 = bkg1.Get(row_inputs[0]['hist_name'])
sum_bkg = hbkg1.Clone('sum_bkg')

bkg2 = TFile(input_dir+'/'+row_inputs[0]['file'])
hbkg2 = bkg2.Get(row_inputs[0]['hist_name'])
den = hbkg2.Clone('den')

ratio_rows = []
    
for row in row_inputs[1:]:
    row_to_print = row['row_label']
    sum_row = ''
    ratio_row = ''
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    for i in range(len(label_col)-1):
        row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
    #if row_inputs.index(row) is not len(row_inputs)-1:
    hist.Add(sum_bkg,-1)
    ratio = hist.Clone('ratio')
    ratio.Divide(den)

    for i in range(len(label_col)-1):
     #   row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
     #   sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'       
    ratio_rows.append(ratio_row) 
    table.write(row_to_print+'\\\\\n')
for item in ratio_rows:
    table.write("var"+str(ratio_rows.index(item))+item+'\\\\\n')
table.write('\\hline\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')
