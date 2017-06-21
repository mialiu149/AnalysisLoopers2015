from ROOT import *
gROOT.SetBatch(True)
import ROOT
gROOT.SetStyle("plain")
def makeDivCan():
    gStyle.SetOptStat(111110)
    """returns a divided canvas for ratios"""
    Rcanv = ROOT.TCanvas("Rcanv","Rcanv",1500,1200)
    Rcanv.cd()
    pad1 = ROOT.TPad("pad1","pad1",0,0.3,1,1)
    pad1.SetNumber(1)
    pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.3)
    pad2.SetNumber(2)
    pad1.Draw()
    pad2.Draw()
    Rcanv.cd()
    #ROOT.SetOwnership(Rcanv,0)
    ROOT.SetOwnership(pad1,0)
    ROOT.SetOwnership(pad2,0)
    return Rcanv
def save_and_show(c):
    c.SaveAs(h.save_name)
    r = ipy_show_canv(c)
    c.Close() #Need to close to prevent ROOT crash
    return r
#def plot_ratio():
def makeRatio(hist1,hist2,ymax=False,ymin=False,norm=False,xtitle=''):
    """returns the ratio plot hist2/hist1
    if one of the histograms is a stack put it in as argument 2!"""
    if norm:
        print 'scaling!'
        try:
            print 'scale 1: ',1/hist1.Integral()
            print 'scale 2: ',1/hist2.Integral()
            hist1.Scale(1/hist1.Integral())
            hist2.Scale(1/hist2.Integral())
        except(ZeroDivisionError):
            pass
    retH = hist1.Clone()
    try:
        retH.Divide(hist2)
    except(TypeError):
        #this is the error you get if hist2 is a stack
        hList = hist2.GetHists()
        sumHist = hist1.Clone("sumHist")
        sumHist.Reset()
        for h in hList:
            sumHist.Add(h)
        retH.Divide(sumHist)
    except(AttributeError):
        #this is the error you get if hist1 is a stack
        print "Did you use a stack as argument 1? please use stack as argument 2!"
        raise AttributeError
    if ymax or ymin:
        retH.GetYaxis().SetRangeUser(ymin,ymax)
        retH.SetLineColor(hist2.GetLineColor())
    retH.GetYaxis().SetTitle("W#gamma QCD unfiltered/filtered")
    retH.GetXaxis().SetTitle(xtitle)
    ROOT.SetOwnership(retH,0)
    return retH
def main():
	fZee = TFile("/home/users/mliu/LeptonTreeLooper/trigeff_El.root")
	fWgamma = TFile("/home/users/mliu/LeptonTreeLooper/trigeff_El_mc.root")
        fout = TFile("trigger_el_sf.root","RECREATE")
	c = TCanvas("c", "c")
	c.SetWindowSize(800, 600)
#        c=makeDivCan()
        c.SetLogx()
        c.SetGrid(1,1)
	l = TLegend(.5, .3, .9, .5)
        l.SetBorderSize(0)
        l.SetFillStyle(0)
	for k in fZee.GetListOfKeys():
	#    if k.GetName is not "noMET_genz_pt_ttzjets":continue
	    if 'pt_effi' not in k.GetName():
               continue
            hZee = fZee.Get(k.GetName())
	    hWgamma = fWgamma.Get(k.GetName().replace("_ttzjets", "_ttg_25ns"))
	    
	    if not hZee.InheritsFrom("TH1") or not hWgamma.InheritsFrom("TH1"):
		continue

	    #if(hZee.Integral()): hZee.Scale(1/hZee.Integral())
	    #if(hWgamma.Integral()): hWgamma.Scale(1/hWgamma.Integral())

	    hZee.SetLineColor(kRed)
	    hZee.SetMarkerColor(kRed)
	    hZee.SetLineWidth(2)
	    hWgamma.SetLineColor(kBlue)
	    hWgamma.SetMarkerColor(kBlue)
	    hWgamma.SetLineWidth(2)

	    hZee.SetTitle("SingleMuon_2016")
	    hWgamma.SetTitle("DY Madgraph")

            h_ratio = makeRatio(hZee,hWgamma,ymin=0,ymax=2.)
            h_ratio.SetTitle("SingleMuon_2016/DY Madgraph")
            h_ratio.SetMarkerColor(kGreen)
            h_ratio.SetLineColor(kGreen)
            h_ratio.SetStats(kFALSE)
	    s = THStack(hZee.GetName(), hZee.GetTitle())
	    s.Add(hZee)
	    s.Add(hWgamma)
           # pad1=c.GetPad(1)
           # pad2=c.GetPad(2)
            #pad1.cd()
	    s.Draw("nostack")
	    s.GetXaxis().SetTitle("lepton Pt [GeV]")
	    s.GetXaxis().SetMoreLogLabels()
	    s.GetYaxis().SetTitle("Efficiency")
	    s.SetMaximum(1.2)

	    l.Clear()
	    l.AddEntry(hZee)
	    l.AddEntry(hWgamma)
	    l.AddEntry(h_ratio)
	    l.Draw()

            #pad2.cd()
            h_ratio.Draw("same")
            h_ratio.Write()
	    c.Update()
	   # pad1.SetLogy()
	    c.SaveAs("~/public_html/"+k.GetName().replace("ele27WPLoose", "singlemu") + ".pdf")

if __name__ == "__main__":
    main()
