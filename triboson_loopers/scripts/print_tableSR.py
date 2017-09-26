'''this script takes in root files containing hists and prints out a latex table'''
from ROOT import TH1F,TFile
import os
from math import sqrt
lumi = '36.5'
selection="sr_yield"
#selection="sr_yield_v1_CRWZ_noisotrackveto_jetveto_removejetcuts"
#selection="sr_yield_v1_CRWZ_noisotrackveto_jetveto"
#selection = "sr_yield_isotrackveto_loosebtag_tightiso_v1"
#selection = "ss_sr_yield_isotrackveto"
#selection="ss_sr_yield_isotrackveto_loosebtag_tighteriso"
#selection="sr_yield_isotrackveto_loosebtag_raw"
printsys = False
table_header = '\\begin{tabular}{lcccccc}\n'
title = 'Expected yields at %s $fb^{-1}$ & \\\\\n'%lumi
hist_prefix = 'h_lep_event_NEventsSR_ss'
input_dir = os.environ['analysis_output']
print input_dir
label_col = ['sample','ee','mm','em','0SFOS', '1SFOS','2SFOS']
nbins=1
bins = ["MET [50,100] GeV &  \\\\\n","MET [100,125] GeV  & &\\\\\n","MET [125,150] GeV  & &\\\\\n","MET [150,200] GeV   & &\\\\\n","MET [200,Inf] GeV & &\\\\\n"]
col_string = ''

for col in label_col:
    if label_col.index(col) is len(label_col)-1:
       col_string+= col
    else:col_string+= col+'&'

row_inputs = [
#              {'file':'data_'+selection+'_hists.root','row_label':'data','hist_name':hist_prefix},
              {'file':'wz_'+selection+'_hists.root','row_label':"wz",'hist_name':hist_prefix,'sys':0.5},
              {'file':'ww_'+selection+'_hists.root','row_label':'ww','hist_name':hist_prefix,'sys':0.5},
              {'file':'zz_'+selection+'_hists.root','row_label':'zz','hist_name':hist_prefix,'sys':0.5},
              {'file':'wjets_stitch_'+selection+'_hists.root','row_label':'wjets','hist_name':hist_prefix.replace('lep','lep'),'sys':0.1},
              {'file':'zjets_stitch_'+selection+'_hists.root','row_label':'zjets','hist_name':hist_prefix.replace('lep','lep'),'sys':0.52},
              {'file':'ttv_'+selection+'_hists.root','row_label':'ttv','hist_name':hist_prefix,'sys':0.5},
              {'file':'ttbar_dilep_'+selection+'_hists.root','row_label':'Dilepton top quark','hist_name':hist_prefix.replace('lep','lep'),'sys':0.3},
              {'file':'ttbar_onelep_'+selection+'_hists.root','row_label':'Single lepton top quark','hist_name':hist_prefix.replace('lep','lep'),'sys':1},
              {'file':'singletop_'+selection+'_hists.root','row_label':'singletop','hist_name':hist_prefix,'sys':0.5},
              {'file':'www_stitch_'+selection+'_hists.root','row_label':'www','hist_name':hist_prefix,'sys':0.5},
             ]
######################################################################################
#loop over input files, fill printdata line if there is data, clone ttbar as sum_bkg #
######################################################################################

datarows=[]
for j in range(nbins): 
    for row in row_inputs:
        if 'data' in row['file']:
           print 'found data file, will print data in the table'
           row_to_print = row['row_label']
           file = TFile(input_dir+'/'+row['file']) 
           hist = file.Get(row['hist_name']) 
           row['hist'] = hist
           for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
               row_to_print+='&'+"%d" % hist.GetBinContent(i)
           datarows.append((row_to_print+'\\\\\n'))
        if 'ttbar_dilep' in row['file']:
            bkg1 = TFile(input_dir+'/'+row['file'])
            hbkg1 = bkg1.Get(row['hist_name'])
            sum_bkg = hbkg1.Clone('sum_bkg')

########################
bkg2 = TFile(input_dir+'/'+row_inputs[-1]['file'])
hbkg2 = bkg2.Get(row_inputs[-1]['hist_name'])
den = hbkg2.Clone('den')
########################

################################
### add up  backgrounds     ####
################################
for i,row in enumerate(row_inputs):
    if not  'data' in row['file'] and not 'ttbar_dilep' in row['file'] and not 'www' in row['file']:
       file = TFile(input_dir+'/'+row['file'])
       hist = file.Get(row['hist_name']) 
       row['hist'] = hist
       sum_bkg.Add(hist)
       print row['row_label'],':',hist.GetBinContent(i)

########find ratio############
ratio = sum_bkg.Clone('ratio')
ratio.Divide(den)

sum_rows = []
ratio_rows=[]
for j in range(nbins):
    sum_row=''
    ratio_row=''
    for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
        sum_row+="&${:.1f}".format(sum_bkg.GetBinContent(i))+'\\pm'+"{:.1f}".format(sum_bkg.GetBinError(i))
        ratio_row+="&${:.1f}".format(ratio.GetBinContent(i))+'\\pm'+"{:.1f}".format(ratio.GetBinError(i))        
    sum_rows.append(sum_row)
    ratio_rows.append(ratio_row)

########print table##########
output = os.environ['analysis_output']+'/../tables/'
table = open(output+'table'+selection+'.tex','w')
table.write('%BEGINLATEX%\n')
table.write('\\begin{table}\n')
table.write('\\begin{center}\n')
#table.write('\\small\n')
table.write('\\caption{ Yields in signal regions. Errors are stat only}\n')
table.write(table_header)
table.write('\\hline\n')
table.write('& ee&mm&em&0SFOS&1SFOS&2SFOS \\\\\n')
#table.write('\\hline\n')
#table.write(title)
#table.write('\\hline\n')
#table.write(col_string+'\\\\\n')
table.write('\\hline\n')

for j in range(nbins):
    if len(datarows):
       table.write(datarows[j])
    table.write('\\hline\n')
    sys =[0,0]
    for row in row_inputs:
        file = TFile(input_dir+'/'+row['file'])
        hist = file.Get(row['hist_name']) 
        row['hist'] = hist
        row_to_print = row['row_label']
        for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
            yieldbin = hist.GetBinContent(i)
            if hist.GetBinContent(1)<0:yieldbin=0.00 
            if printsys:row_to_print+='&$'+"{:.1f}".format(yieldbin)+'\\pm'+"{:.1f}".format(hist.GetBinError(i))+'\\pm'+"{:.1f}".format(row['sys']*yieldbin)+'$'
            else:row_to_print+='&$'+"{:.1f}".format(yieldbin)+'\\pm'+"{:.1f}".format(hist.GetBinError(i))+'$'
            #sys[i]+=(row['sys']*yieldbin)**2
        table.write(row_to_print+'\\\\\n')
    sumrow =""
    for i in range((len(label_col)-1)*j,(len(label_col)-1)*j+(len(label_col)-1)):
        if printsys:sumrow+='&$'+"{:.1f}".format(sum_bkg.GetBinContent(i))+'\\pm'+"{:.1f}".format(sum_bkg.GetBinError(i))+'\\pm'+"{:.1f}".format(sqrt(sys[i]))+'$'
        else: sumrow+='&$'+"{:.1f}".format(sum_bkg.GetBinContent(i))+'\\pm'+"{:.1f}".format(sum_bkg.GetBinError(i))+'$'
#    table.write("kfactor"+ratio_rows[j]+'\\\\\n') 
    table.write('\\hline\n')
    table.write("Total bkg"+sumrow+'\\\\\n')
    table.write('\\hline\n')

table.write('\\hline\n')
table.write('\\hline\n')
table.write('\\end{tabular}\n')
table.write('\\end{center}\n')
table.write('\\end{table}\n')
table.write('%ENDLATEX%')

print 'table saved in : ',output+'table'+selection+'.tex'
