'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os
from math import sqrt
lumi = '36.5'
selection = "SR_mix_SRMultiBin_V4_yield_mbb_mct170_mt150_met125_twobtag"
table_header = '\\begin{tabular}{lcc}\n'
title = 'Expected yields at %s $fb^{-1}$ & \\\\\n'%lumi
hist_prefix = 'h_lep_event_NEventsSRMultiBin'
input_dir = os.environ['analysis_output']
print input_dir
label_col = ['sample','mt$>$150','mct$>$100']
nbins=1
bins = ["MET [50,100] GeV &  \\\\\n","MET [100,125] GeV  & &\\\\\n","MET [125,150] GeV  & &\\\\\n","MET [150,200] GeV   & &\\\\\n","MET [200,Inf] GeV & &\\\\\n"]
col_string = ''

for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'

row_inputs = [
              {'file':'data_'+selection+'_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Dilepton top quark','hist_name':hist_prefix.replace('lep','lep_dilep'),'sys':0.3},
              {'file':'ws_stitch_'+selection+'_hists.root','row_label':'\wl','hist_name':hist_prefix.replace('lep','lep_LF'),'sys':0.1},
              {'file':'ws_stitch_'+selection+'_hists.root','row_label':'\whf','hist_name':hist_prefix.replace('lep','lep_HF'),'sys':0.52},
              {'file':'wzbb_'+selection+'_hists.root','row_label':"\wzbb",'hist_name':hist_prefix,'sys':0.5},
              {'file':'tops_mad_'+selection+'_hists.root','row_label':'Single lepton top quark','hist_name':hist_prefix.replace('lep','lep_onelep'),'sys':1},
              {'file':'rare_'+selection+'_hists.root','row_label':'Rare','hist_name':hist_prefix,'sys':0.5},
              {'file':'SMS_wh_225_75_noskim_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (225,75)','hist_name':hist_prefix}, 
              {'file':'SMS_wh_250_1_noskim_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (250,1)','hist_name':hist_prefix}, 
              {'file':'SMS_wh_500_1_noskim_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (500,1)','hist_name':hist_prefix}, 
              {'file':'SMS_wh_500_125_noskim_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (500,125)','hist_name':hist_prefix}, 
              {'file':'SMS_wh_350_100_noskim_'+selection+'_hists.root','row_label':'$\\tilde{\\chi}_{1}^{\pm}\\tilde{\\chi}_{1}^{0}$ (350,100)','hist_name':hist_prefix}
             ]

##print out data####
datarows=[]
for j in range(nbins): 
    for row in row_inputs[0:1]:
        row_to_print = row['row_label']
        file = TFile(input_dir+'/'+row['file']) 
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            row_to_print+='&'+"%d" % hist.GetBinContent(i+1)
        datarows.append((row_to_print+'\\\\\n'))

##############################
# first background, 2l ttbar #
##############################
bkg1 = TFile(input_dir+'/'+row_inputs[1]['file'])
hbkg1 = bkg1.Get(row_inputs[1]['hist_name'])
sum_bkg = hbkg1.Clone('sum_bkg')
########################

########################
bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')
########################

################################
# these are other bkgs     ####
################################
for i,row in enumerate(row_inputs[2:7]):
    file = TFile(input_dir+'/'+row['file'])
    hist = file.Get(row['hist_name']) 
    row['hist'] = hist
    sum_bkg.Add(hist)
    print row['row_label'],':',hist.GetBinContent(1)

########find ratio############
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

sum_rows = []
ratio_rows=[]
for j in range(nbins):
    sum_row=''
    ratio_row=''
    for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
        sum_row+="&${:.1f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.1f}".format(sum_bkg.GetBinError(i+1))
        ratio_row+="&${:.1f}".format(ratio.GetBinContent(i+1))+'\\pm'+"{:.1f}".format(ratio.GetBinError(i+1))        
    sum_rows.append(sum_row)
    ratio_rows.append(ratio_row)

########print table##########
output = os.environ['analysis_output']+'/../tables/'
table = open(output+'table'+selection+'.tex','w')
table.write('%BEGINLATEX%\n')
table.write('\\begin{table}\n')
table.write('\\begin{center}\n')
#table.write('\\small\n')
table.write('\\caption{ Yields in signal regions using \\fullLumi data. Errors are stat +/- sys. \\label{tab:yields36fb}}\n')
table.write(table_header)
table.write('\\hline\n')
table.write('& 125 GeV $<$ \\met$<$200 GeV &\\met $>$ 200 GeV\\\ \n')
#table.write('\\hline\n')
#table.write(title)
#table.write('\\hline\n')
#table.write(col_string+'\\\\\n')
table.write('\\hline\n')

for j in range(nbins):
    table.write(datarows[j])
    table.write('\\hline\n')
    sys =[0,0]
    for row in row_inputs[1:7]:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']
        ### print out the table
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            yieldbin = hist.GetBinContent(i+1)
            if hist.GetBinContent(i+1)<0:yieldbin=0.00 
            row_to_print+='&$'+"{:.1f}".format(yieldbin)+'\\pm'+"{:.1f}".format(hist.GetBinError(i+1))+'\\pm'+"{:.1f}".format(row['sys']*yieldbin)+'$'
            sys[i]+=(row['sys']*yieldbin)**2
        table.write(row_to_print+'\\\\\n')
    sumrow =""
    for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
        sumrow+='&$'+"{:.1f}".format(sum_bkg.GetBinContent(i+1))+'\\pm'+"{:.1f}".format(sum_bkg.GetBinError(i+1))+'\\pm'+"{:.1f}".format(sqrt(sys[i]))+'$'
#    table.write("kfactor"+ratio_rows[j]+'\\\\\n') 
    table.write('\\hline\n')
    table.write("Total bkg"+sumrow+'\\\\\n')
    table.write('\\hline\n')

    for row in row_inputs[7:]:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']
        ### print out the table
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            row_to_print+='&$'+"{:.1f}".format(hist.GetBinContent(i+1))+'\\pm'+"{:.1f}".format(hist.GetBinError(i+1))+'$'
        table.write(row_to_print+'\\\\\n')
table.write('\\hline\n')
table.write('\\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')

print 'table saved in : ',output+'table'+selection+'.tex'
