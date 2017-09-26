from ROOT import *
import sys,os
gROOT.SetBatch(True)
###python overlayhist.py hist1,hist2,hist MT 
selection = "sr_ss_fakerate"
var = "flavorbin"
histdict = {
  'up':["fakerate_sr_ss_fakerate_up_hists.root".replace("sr_ss_fakerate",selection),"h_lep_event_"+var+"_sr_ss_fakerate_up".replace("sr_ss_fakerate",selection),kBlue],
  'nominal':["fakerate_sr_ss_fakerate_hists.root".replace("sr_ss_fakerate",selection),"h_lep_event_"+var+"_sr_ss_fakerate".replace("sr_ss_fakerate",selection),kOrange-2],
  'down':["fakerate_sr_ss_fakerate_down_hists.root".replace("sr_ss_fakerate",selection),"h_lep_event_"+var+"_sr_ss_fakerate_down".replace("sr_ss_fakerate",selection),kMagenta-5]
 }
colors = [kBlue,kRed,kCyan-3,kOrange-2,kMagenta-5]
c = TCanvas("c", "c")
c.SetWindowSize(600, 600)
l = TLegend(.6, .7, .9, .9)
s = THStack("fake", "ss fake yields")

for key in histdict.keys():
    ftmp = TFile(os.environ["analysis_output"]+"/"+histdict[key][0])
    hist = ftmp.Get(histdict[key][1])
    hist.SetLineColor(histdict[key][2])
    hist.SetMarkerColor(histdict[key][2])
    hist.SetDirectory(0)
    hist.Rebin(1)
    hist.SetTitle(key)
    l.AddEntry(hist)
    s.Add(hist)

c.Update()
s.Draw("nostack")
l.Draw()
#s.GetXaxis().SetTitle('ss sr')
c.SaveAs("~/public_html/"+var+"_sr_ss_fakerate.pdf".replace("sr_ss_fakerate",selection))
