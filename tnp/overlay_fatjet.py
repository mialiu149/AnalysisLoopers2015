from ROOT import *
gROOT.ProcessLine(".x rootlogon.C")
gROOT.SetBatch(True)
gROOT.SetStyle("ATLAS")


fZee = TFile("rootfiles/CutHistos/FatJetPlots/Stop_850_100_fatjet.root")
fWgamma = TFile("rootfiles/CutHistos/FatJetPlots/TTbar_fatjet.root")

c = TCanvas("c", "c")
c.SetWindowSize(800, 600)

l = TLegend(.85, .7, .95, .9)
for k in fZee.GetListOfKeys():
    hZee = fZee.Get(k.GetName())
    hWgamma = fWgamma.Get(k.GetName().replace("Stop_850_100_fatjet", "TTbar2l"))

    if not hZee.InheritsFrom("TH1") or not hWgamma.InheritsFrom("TH1"):
        continue

    if hZee.Integral(): hZee.Scale(1/hZee.Integral())
    if hWgamma.Integral() :hWgamma.Scale(1/hWgamma.Integral())

    hZee.SetLineColor(kBlue)
    hZee.SetLineWidth(2)
    hWgamma.SetLineColor(kRed)
    hWgamma.SetLineWidth(2)

    hZee.SetTitle("Stop_850_100")
    hWgamma.SetTitle("TTbar")

    s = THStack(hZee.GetName(), hZee.GetTitle())
    s.Add(hWgamma)
    s.Add(hZee)
    s.Draw("nostack")
    s.GetXaxis().SetTitle(k.GetName())

    l.Clear()
    l.AddEntry(hZee)
    l.AddEntry(hWgamma)
    l.Draw()

    c.Update()
    c.SaveAs("/home/users/mliu/public_html/"+k.GetName().replace("Zee_", "") + ".png")
