'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os

lumi = 2.26
#selection="yield_1lCR_mbb_wbbCR"
#selection="SROneBin_yield_mbb_mct170_mt150_met200_incloneb"

#selection="yield_SR_met100_mt150_mct150_mbb_loosebtag"
#selection="SROneBin_yield_met100_mt150_mct150_mbb_loosebtag_3jets"

#selection="SRMultiBinV5_yield_mbb_mct150_mt150_twobtag"
selection="SR_SROneBin_yield_mbb_mct150_mt150_met100_twobtag" # get yields in SR
table_header = '\\begin{tabular}{lc}\n'
title = '1l CR & \\\\\n'
hist_prefix = 'h_lep_event_NEventsSROneBin_'+selection
input_dir = os.environ['analysis_output']
print input_dir
##cols to print out
#label_col = ['sample','mct$>$50','mct$>$100','mct$>$125','mct$>$150']
label_col = ['sample','mt$>$150']
nbins=1
bins = ["MET [50,100] GeV &  \\\\\n","MET [100,125] GeV  & &\\\\\n","MET [125,150] GeV  & &\\\\\n","MET [150,200] GeV   & &\\\\\n","MET [200,Inf] GeV & &\\\\\n"]
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
#              ]
row_inputs = [
              {'file':'diboson_'+selection+'_hists.root','row_label':'diboson','hist_name':hist_prefix},
              {'file':'triboson_'+selection+'_hists.root','row_label':'triboson','hist_name':hist_prefix},
              {'file':'smWH_'+selection+'_hists.root','row_label':'WlvHbb','hist_name':hist_prefix},
              {'file':'ttv_'+selection+'_hists.root','row_label':'ttv','hist_name':hist_prefix},
              {'file':'zjets_'+selection+'_hists.root','row_label':'zjets','hist_name':hist_prefix},
              {'file':'rare_'+selection+'_hists.root','row_label':'rare','hist_name':hist_prefix}
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
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        datarows.append((row_to_print+'\\\\\n'))

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


########################
########################
for i,row in enumerate(row_inputs[1:]):
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    #subtract it if it is not the last row, which is 2l ttbar
    #if row['row_label'] is not 'w+jets(light)':
    if i < 6:
       sum_bkg.Add(hist,-1)
    print row['row_label'],':',hist.GetBinContent(5)

########find ratio############
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

sum_rows = []
ratio_rows=[]

for j in range(nbins):
    sum_row=''
    ratio_row=''
    for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
        sum_row+="&${:.2f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(sum_bkg.GetBinError(i+1))+'$'
        ratio_row+="&${:.2f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(ratio.GetBinError(i+1))+'$'        
    sum_rows.append(sum_row)
    ratio_rows.append(ratio_row)

########print table##########
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

for j in range(nbins):
    table.write(bins[j])
    table.write('\\hline\n')
    table.write(datarows[j])
    table.write('\\hline\n')
    for row in row_inputs[1:]:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']
        ### print out the table
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            row_to_print+='&$'+"{:.2f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.2f}".format(hist.GetBinError(i+1))+'$'
        table.write(row_to_print+'\\\\\n')
    table.write("\\hline\n")
#    table.write("databkgsub"+sum_rows[j]+'\\\\\n') 
#    table.write("kfactor"+ratio_rows[j]+'\\\\\n') 
    table.write('\\hline\hline\n')
    table.write("\\hline\n")
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')
print 'table saved in : ','table'+selection+'.tex'
