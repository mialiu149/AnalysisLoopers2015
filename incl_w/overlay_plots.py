from ROOT import *
gROOT.SetBatch(True)
#gROOT.ProcessLine('tdrstyle_SUSY.C')
#setTDRStyle()
gStyle.SetOptStat(0)
c = TCanvas("c", "c")
c.SetWindowSize(800, 800)
c.SetGrid()

#files = ['histos.625_325_bin1GeV.root','histos_500_325_bin1GeV.root','histos_650_325_bin1GeV.root','histos_850_100_bin1GeV.root']
#files = ['Histos_Stop.625_325.root','Histos_Stop_500_325.root','Histos_Stop_650_325.root','Histos_Stop_850_100.root']
dir = '~/public_html/rootfiles/TriggerEffs/'
files = [dir+'Histos_SingleEl.root']
#,'Histos_Stop_500_325.root','Histos_Stop_650_325.root','Histos_Stop_850_100.root']
l = TLegend(.65, .5, .9, .7)
#l = TLegend(0.25,0.7,0.68,0.9)
#s = THStack('Efficiency w.r.t gen level','Gen Efficiency')
s = THStack('Efficiency','MET170 efficiency')
colors = [632#kRed
         ,800#kOrange
         ,616#kGreen,
         ,600#kBlue
         ] 
legends = ['OneLep Skim','el triggered','muon triggered','Stop850_LSP100']
hists = []

for idex,file in enumerate(files):
    hfile = TFile(file)
    h_pt_gen_match = TH1F()
    h_pt_gen = TH1F()
    h_pt_eff = TH1F()
    h_pt_gen_match.Sumw2()
    h_pt_gen.Sumw2()
    h_pt_eff.Sumw2()
    h_pt_gen_match = hfile.Get('MET_after_met170_SingleEl')
    h_pt_gen = hfile.Get('MET_pre_met170_SingleEl')
    h_pt_eff = h_pt_gen_match
    h_pt_eff.Divide(h_pt_gen_match,h_pt_gen,1.0,1.0,'B')
    h_pt_eff.SetMarkerStyle(8)
    h_pt_eff.SetMarkerSize(.6)
    h_pt_eff.SetMarkerColor(kBlue)
    h_pt_eff.SetTitle(legends[0])

    h1_pt_gen_match = TH1F()
    h1_pt_gen = TH1F()
    h1_pt_eff = TH1F()
    h1_pt_gen_match.Sumw2()
    h1_pt_gen.Sumw2()
    h1_pt_eff.Sumw2()
    h1_pt_gen_match = hfile.Get('MET_after_met170_el_SingleEl')
    h1_pt_gen = hfile.Get('MET_pre_met170_el_SingleEl')
    h1_pt_eff = h1_pt_gen_match
    h1_pt_eff.Divide(h1_pt_gen_match,h1_pt_gen,1.0,1.0,'B')
    h1_pt_eff.SetMarkerStyle(26)
    h1_pt_eff.SetMarkerSize(.6)
    h1_pt_eff.SetMarkerColor(kRed)
    h1_pt_eff.SetTitle(legends[1])

    h2_pt_gen_match = TH1F()
    h2_pt_gen = TH1F()
    h2_pt_eff = TH1F()
    h2_pt_gen_match.Sumw2()
    h2_pt_gen.Sumw2()
    h2_pt_eff.Sumw2()
    h2_pt_gen_match = hfile.Get('MET_after_met170_mu_SingleEl')
    h2_pt_gen = hfile.Get('MET_pre_met170_mu_SingleEl')
    h2_pt_eff = h2_pt_gen_match
    h2_pt_eff.Divide(h2_pt_gen_match,h2_pt_gen,1.0,1.0,'B')
    h2_pt_eff.SetMarkerStyle(25)
    h2_pt_eff.SetMarkerSize(.6)
    h2_pt_eff.SetMarkerColor(kCyan-3)
    h2_pt_eff.SetTitle(legends[2])
    
    h3_pt_gen_match = TH1F()
    h3_pt_gen = TH1F()
    h3_pt_eff = TH1F()
    h3_pt_gen_match.Sumw2()
    h3_pt_gen.Sumw2()
    h3_pt_eff.Sumw2()
    h3_pt_gen_match = hfile.Get('MET_after_met170_el_offline20_SingleEl')
    h3_pt_gen = hfile.Get('MET_pre_met170_el_offline20_SingleEl')
    h3_pt_eff = h3_pt_gen_match
    h3_pt_eff.Divide(h3_pt_gen_match,h3_pt_gen,1.0,1.0,'B')
    h3_pt_eff.SetMarkerStyle(26)
    h3_pt_eff.SetMarkerSize(.6)
    h3_pt_eff.SetMarkerColor(kBlue)
    h3_pt_eff.SetTitle('pt_el>20GeV')
    
    h4_pt_gen_match = TH1F()
    h4_pt_gen = TH1F()
    h4_pt_eff = TH1F()
    h4_pt_gen_match.Sumw2()
    h4_pt_gen.Sumw2()
    h4_pt_eff.Sumw2()
    h4_pt_gen_match = hfile.Get('MET_after_met170_el_offline40_SingleEl')
    h4_pt_gen = hfile.Get('MET_pre_met170_el_offline40_SingleEl')
    h4_pt_eff = h4_pt_gen_match
    h4_pt_eff.Divide(h4_pt_gen_match,h4_pt_gen,1.0,1.0,'B')
    h4_pt_eff.SetMarkerStyle(26)
    h4_pt_eff.SetMarkerSize(.6)
    h4_pt_eff.SetMarkerColor(kBlue)
    h4_pt_eff.SetTitle('pt_el>40GeV')

    h5_pt_gen_match = TH1F()
    h5_pt_gen = TH1F()
    h5_pt_eff = TH1F()
    h5_pt_gen_match.Sumw2()
    h5_pt_gen.Sumw2()
    h5_pt_eff.Sumw2()
    h5_pt_gen_match = hfile.Get('MET_after_met170_mu_offline20_SingleEl')
    h5_pt_gen = hfile.Get('MET_pre_met170_mu_offline20_SingleEl')
    h5_pt_eff = h5_pt_gen_match
    h5_pt_eff.Divide(h5_pt_gen_match,h5_pt_gen,1.0,1.0,'B')
    h5_pt_eff.SetMarkerStyle(25)
    h5_pt_eff.SetMarkerSize(.6)
    h5_pt_eff.SetMarkerColor(kOrange-2)
    h5_pt_eff.SetTitle('pt_mu>20GeV')

    h6_pt_gen_match = TH1F()
    h6_pt_gen = TH1F()
    h6_pt_eff = TH1F()
    h6_pt_gen_match.Sumw2()
    h6_pt_gen.Sumw2()
    h6_pt_eff.Sumw2()
    h6_pt_gen_match = hfile.Get('MET_after_met170_mu_offline30_SingleEl')
    h6_pt_gen = hfile.Get('MET_pre_met170_mu_offline30_SingleEl')
    h6_pt_eff = h6_pt_gen_match
    h6_pt_eff.Divide(h6_pt_gen_match,h6_pt_gen,1.0,1.0,'B')
    h6_pt_eff.SetMarkerStyle(25)
    h6_pt_eff.SetMarkerSize(.6)
    h6_pt_eff.SetMarkerColor(kRed)
    h6_pt_eff.SetTitle('pt_mu>30GeV')

#    s.Add(h_pt_eff) #both

#    s.Add(h1_pt_eff)#el
#    s.Add(h3_pt_eff)#el
    s.Add(h4_pt_eff)#el
#    s.Add(h2_pt_eff)#mu
#    s.Add(h5_pt_eff)#mu
#    s.Add(h6_pt_eff)#mu

#    l.AddEntry(h_pt_eff)#both
#    l.AddEntry(h1_pt_eff)#el
#    l.AddEntry(h3_pt_eff)#el
    l.AddEntry(h4_pt_eff)#el
#    l.AddEntry(h2_pt_eff)#mu
#    l.AddEntry(h5_pt_eff)#mu
#    l.AddEntry(h6_pt_eff)#mu

s.Draw("nostack")    
l.Draw()
#c.SaveAs('/home/users/cwelke/public_html/MIA/eff.625_325.pdf')
c.SaveAs('/home/users/mliu/public_html/met170_el_htplus10.pdf')

