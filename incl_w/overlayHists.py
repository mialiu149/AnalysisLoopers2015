from ROOT import *
import sys,os
gROOT.SetBatch(True)
###python overlayhist.py hist1,hist2,hist MT 
keys = sys.argv[1].split(',')
title = sys.argv[2]
legends = sys.argv[3].split(',')
min_argv = 3

print len(sys.argv)
print "Overlaying these hists: ",keys,sys.argv[1]
print "Title for the plot is: ",title,sys.argv[2]
print "Using legends : ", legends,sys.argv[3]

if len(sys.argv)>min_argv+1: 
   fZee = TFile(sys.argv[min_argv+1])
   print "using file: ", sys.argv[min_argv+1]
if len(sys.argv)>min_argv+2:
   fWgamma = TFile(sys.argv[min_argv+2])
   print "using file: ", sys.argv[min_argv+2]
if len(sys.argv)>min_argv+3: 
   f3 = TFile(sys.argv[min_argv+3])
   print "using file: ", sys.argv[min_argv+3]
if len(sys.argv)>min_argv+4: 
   f4 = TFile(sys.argv[min_argv+4])
   print "using file: ", sys.argv[min_argv+4]
if len(sys.argv)>min_argv+5: 
   f5 = TFile(sys.argv[min_argv+5])
   print "using file: ", sys.argv[min_argv+5]

c = TCanvas("c", "c")
c.SetWindowSize(600, 600)
c.SetLogy()
l = TLegend(.3, .7, .9, .9)
s = THStack(title, title)
colors = [kBlue,kRed,kCyan-3,kOrange-2,kMagenta-5]

for i,k in enumerate(keys):
    hZee = fZee.Get(k)
    hWgamma = fWgamma.Get(k)
    if len(sys.argv)>min_argv+3: h3 = f3.Get(k)
    if len(sys.argv)>min_argv+4: h4 = f4.Get(k)
    if len(sys.argv)>min_argv+5: h5 = f5.Get(k)
    print k
    if not hZee.InheritsFrom("TH1") or not hWgamma.InheritsFrom("TH1"):
        continue

    if hZee.Integral(): hZee.Scale(1/hZee.Integral())
    if hWgamma.Integral() :hWgamma.Scale(1/hWgamma.Integral())
    
    if len(sys.argv)>min_argv+3:
       if h3.Integral():
          h3.Scale(1/h3.Integral())
    if len(sys.argv)>min_argv+4:
       if h4.Integral():
          h4.Scale(1/h4.Integral())
    if len(sys.argv)>min_argv+5:
       if h5.Integral():
          h5.Scale(1/h4.Integral())

    hZee.SetLineColor(colors[i*len(keys)])
    hZee.SetMarkerColor(colors[i*len(keys)])
    hZee.SetLineWidth(2)
    hWgamma.SetLineColor(colors[i*len(keys)+1])
    hWgamma.SetMarkerColor(colors[i*len(keys)+1])
    hWgamma.SetLineWidth(2)

    if len(sys.argv)>min_argv+3:
       h3.SetLineWidth(2)
       h3.SetLineColor(colors[i+2])
    if len(sys.argv)>min_argv+4:
       h4.SetLineWidth(2)
       h4.SetLineColor(kOrange-2)
    if len(sys.argv)>min_argv+5:
       h5.SetLineWidth(2)
       h5.SetLineColor(kMagenta-5)

#    hZee.SetTitle(sys.argv[min_argv+3].replace('.root','')+k.replace('Wmunu_selection',''))
#    hWgamma.SetTitle(sys.argv[min_argv+4].replace('.root','')+k.replace('Wmunu_selection',''))
#    if len(sys.argv)>min_argv+3: h3.SetTitle(sys.argv[min_argv+3].replace('.root','')+k.replace('Wmunu_selection',''))
#    if len(sys.argv)>min_argv+4: h4.SetTitle(sys.argv[min_argv+4].replace('.root','')+k.replace('Wmunu_selection',''))
#    if len(sys.argv)>min_argv+5: h5.SetTitle(sys.argv[min_argv+5].replace('.root','')+k.replace('Wmunu_selection',''))
    hZee.SetTitle(legends[i*len(keys)])
    hWgamma.SetTitle(legends[i*len(keys)+1])
    if len(sys.argv)>min_argv+3: h3.SetTitle(legends[2])
    if len(sys.argv)>min_argv+4: h4.SetTitle(legends[3])
    if len(sys.argv)>min_argv+5: h5.SetTitle(legends[4])
    s.Add(hWgamma)
    s.Add(hZee)
    if len(sys.argv)>min_argv+3:s.Add(h3)
    if len(sys.argv)>min_argv+4:s.Add(h4)
    if len(sys.argv)>min_argv+5:s.Add(h5)

#    l.Clear()
    l.AddEntry(hZee)
    l.AddEntry(hWgamma)
    if len(sys.argv)>min_argv+3:l.AddEntry(h3)
    if len(sys.argv)>min_argv+4:l.AddEntry(h4)
    if len(sys.argv)>min_argv+5:l.AddEntry(h5)

s.Draw("nostack")
s.GetXaxis().SetTitle(title+' [GeV]')
l.SetTextSize(0.03)
l.Draw()

c.Update()
c.SaveAs("~/public_html/ttz_z_comp/plots/"+title+".pdf")
