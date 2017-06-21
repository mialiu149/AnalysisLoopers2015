from ROOT import *
gROOT.SetBatch(True)


fZee = TFile("rootfiles/CutHistos/FatJetPlots/ttzjets.root")
fWgamma = TFile("rootfiles/CutHistos/FatJetPlots/ttg_25ns.root")

c = TCanvas("c", "c")
c.SetWindowSize(800, 600)

l = TLegend(.85, .7, .95, .9)
for k in fZee.GetListOfKeys():
#    if k.GetName is not "noMET_genz_pt_ttzjets":continue
    hZee = fZee.Get(k.GetName())
    hWgamma = fWgamma.Get(k.GetName().replace("_ttzjets", "_ttg_25ns"))
    
    if not hZee.InheritsFrom("TH1") or not hWgamma.InheritsFrom("TH1"):
        continue

    if(hZee.Integral()): hZee.Scale(1/hZee.Integral())
    if(hWgamma.Integral()): hWgamma.Scale(1/hWgamma.Integral())

    hZee.SetLineColor(kBlue)
    hZee.SetMarkerColor(kBlue)
    hZee.SetLineWidth(2)
    hWgamma.SetLineColor(kRed)
    hWgamma.SetMarkerColor(kRed)
    hWgamma.SetLineWidth(2)

    hZee.SetTitle("ttz")
    hWgamma.SetTitle("ttg")

    s = THStack(hZee.GetName(), hZee.GetTitle())
    s.Add(hZee)
    s.Add(hWgamma)
    s.Draw("nostack")
    s.GetXaxis().SetTitle(k.GetName())

    l.Clear()
    l.AddEntry(hZee)
    l.AddEntry(hWgamma)
    l.Draw()

    c.Update()
    c.SetLogy()
    c.SaveAs("~/public_html/ttz_z_comp/"+k.GetName().replace("_ttzjets", "") + ".pdf")
