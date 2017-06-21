from ROOT import *
import sys, os
sys.path.insert(1,'/home/users/namin/2016/ss/master/SSAnalysis/bck_software/pyRootPlotMaker/')
import pyRootPlotMaker as ppm

# r.gInterpreter.ProcessLine('#include "CMS3.cc"')
# r.gInterpreter.ProcessLine('#include "/home/users/namin/CORE/VertexSelections.h"')
# r.gSystem.Load('/home/users/namin/CORE/CMS3_CORE.so')
# f = r.TFile("ntuple_May18.root")

def main(kine="HH"):

    ismc = False

    # kine = "HH"

    if ismc:
        indir = "comparison_rootfiles/"
        # indir = "comparison_rootfiles_mc_Sept15/"
        f_is = TFile(indir+"histos__LooseEMVA_mva_ept_hth_inSitu_coneCorr_%s.root" % kine)
        f_qcd = TFile(indir+"histos__LooseEMVA_coneCorr_%s.root" % kine)

    else:
        # indir = "comparison_rootfiles_data/"
        # f_is = TFile(indir+"histos__LooseEMVA_mva_ept_hth_inSitu_coneCorr_HH.root")
        # f_qcd = TFile(indir+"histos__LooseEMVA_coneCorr_HH.root")

        # indir = "comparison_rootfiles_data_Sept14/"
        indir = "moriond/"
        # f_is = TFile(indir+"/histos__LooseEMVA_mva_ept_hth_inSitu_coneCorr_%s.root" % kine)
        f_is = TFile(indir+"/histos__LooseEMVA_soup_mva_ept_hth_inSitu_coneCorr_%s.root" % kine)
        f_qcd = TFile(indir+"/histos__LooseEMVA_coneCorr_%s.root" % kine)

    # plotdir = "comparison_plots_Oct25/"
    # lumi = 22.0
    plotdir = "moriond/comparisons/"
    lumi = 36.8

    types = ["br","sr","HT","MET","MTMIN","L1PT","L2PT","LTrue","LFake"]
    type_map = {
            "br": "Nbtags",
            "sr": "SR",
            "HT": "HT",
            "MET": "MET",
            "MTMIN": "MTMIN",
            "L1PT": "L1PT",
            "L2PT": "L2PT",
            "LTrue": "LTrue",
            "LFake": "LFake",
            }
    lep_map = {"tot": "Total", "el": "Electrons", "mu": "Muons"}

    # f1.ls()

    d_obs = {}
    d_pred = {}
    for t in types:
        d_obs[t] = {
                "tot": [f_is.Get("Npn_histo_%s_obsTTBAR" % t), f_qcd.Get("Npn_histo_%s_obsTTBAR" % t)],
                "el": [f_is.Get("Npn_histo_%s_obs_elTTBAR" % t), f_qcd.Get("Npn_histo_%s_obs_elTTBAR" % t)],
                "mu": [f_is.Get("Npn_histo_%s_obs_muTTBAR" % t), f_qcd.Get("Npn_histo_%s_obs_muTTBAR" % t)],
                }
        d_pred[t] = {
                "tot": [f_is.Get("Npn_histo_%s_pred;1" % t), f_qcd.Get("Npn_histo_%s_pred;1" % t)],
                "el": [f_is.Get("Npn_histo_%s_pred_el;1" % t), f_qcd.Get("Npn_histo_%s_pred_el;1" % t)],
                "mu": [f_is.Get("Npn_histo_%s_pred_mu;1" % t), f_qcd.Get("Npn_histo_%s_pred_mu;1" % t)],
                }


    for t in d_pred.keys():
        for lep in ["tot","el","mu"]:

            pred_is = d_pred[t][lep][0]
            pred_qcd = d_pred[t][lep][1]

            obs = d_obs[t][lep][0]

            lep_str = lep_map[lep]
            type_str = type_map[t]
            if ismc:
                ppm.plotComparison(pred_is,pred_qcd,bkgs=[obs],bkgs_titles=["Observed"],ratioTitle="Pred/Obs", h1Title="Pred: InSitu", h2Title="Pred: Reg", saveAs=plotdir+"h1_%s_%s_%s.pdf" % (kine, t,lep), isLog=False, title="t#bar{t} with %.1f fb^{-1} data FR: #font[62]{%s [%s, %s]}" % (lumi, type_str, lep_str, kine),flatSystBand=0.3)
            else:
                ppm.plotComparison(pred_is,pred_qcd,bkgs=[],bkgs_titles=[],ratioTitle="InSitu/Reg", h1Title="Pred: InSitu", h2Title="Pred: Reg", saveAs=plotdir+"h1_%s_%s_%s.pdf" % (kine,t,lep), isLog=False, title="%.1f fb^{-1} Data FR+App: #font[62]{%s [%s, %s]}" % (lumi, type_str, lep_str, kine),scaleYmax=0.5,flatSystBand=0.3)
                if t.lower() == "sr":
                    ppm.plotComparison(pred_is,pred_qcd,bkgs=[],bkgs_titles=[],ratioTitle="InSitu/Reg", h1Title="Pred: InSitu", h2Title="Pred: Reg", saveAs=plotdir+"h1_%s_%s_%s_log.pdf" % (kine,t,lep), isLog=True, title="%.1f fb^{-1} Data FR+App: #font[62]{%s [%s, %s]}" % (lumi, type_str, lep_str, kine),scaleYmax=0.5,flatSystBand=0.3)




if __name__ == '__main__':
    main("HH")
    # main("HL")
    # main("LL")

    # os.system("niceplots comparison_plots")
