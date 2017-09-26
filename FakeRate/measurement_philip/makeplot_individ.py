#!/bin/env python

import sys
sys.path.append("/home/users/phchang/public_html/tasutil")
import plotmaker
import ROOT as r

tfile_data   = r.TFile("outputs/fakerate_data.root")
tfile_wj     = r.TFile("outputs/fakerate_wj.root")
tfile_dy     = r.TFile("outputs/fakerate_dy.root")
tfile_ttbar  = r.TFile("outputs/fakerate_ttbar.root")
tfile_vv     = r.TFile("outputs/fakerate_vv.root")
tfile_qcd_mu = r.TFile("outputs/fakerate_qcd_mu.root")
tfile_qcd_el = r.TFile("outputs/fakerate_qcd_el.root")
#try:
#    tfile_test   = r.TFile("fakerate_DY_madgraph_0.root")
#except:
#    pass

from array import *

norebin = False
addvv = False

###################################################################################################
# Rebinning histograms when needed.
# Currently only the "ptvarbin" variable and "met" is being rebinned to do some "studies".
#
def rebin(hist, name):
    if norebin:
        return hist
    if name.find("ptvarbin") != -1:
#        bins = array('d', [10., 15., 20., 25., 30., 35., 50., 170.])
#        tmphist = hist.Rebin(7, hist.GetName(), bins)
#        bins = array('d', [10., 15., 20., 25., 30., 35., 170.])
#        tmphist = hist.Rebin(6, hist.GetName(), bins)
        bins = array('d', [10., 15., 20., 25., 30., 35., 50., 170.])
        tmphist = hist.Rebin(7, hist.GetName(), bins)
        tmphist.SetDirectory( 0 )
        return tmphist
    if name.find("histo_nvtxrewgt_met_") != -1:
        bins = array('d', [0., 20., 30., 200.])
        tmphist = hist.Rebin(3, hist.GetName(), bins)
        tmphist.SetDirectory( 0 )
        return tmphist
    return hist


###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw(histname, varname, extraopt=""):

    # Get histograms
    histo__data = tfile_data .Get(histname).Clone("Data")
    histo__wj   = tfile_wj   .Get(histname).Clone("WJets")
    histo__dy   = tfile_dy   .Get(histname).Clone("DY")
    histo__ttbar= tfile_ttbar.Get(histname).Clone("TTbar")
    histo__vv   = tfile_ttbar.Get(histname).Clone("VV")
    histo__data .SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__wj   .Scale( 1.01 )
    histo__dy   .Scale( 1.01 )
    histo__ttbar.Scale( 1.01 )
    histo__vv   .Scale( 1.01 )
    histo__data .SetLineColor( 1 )
    histo__wj   .SetLineColor( 7006 )
    histo__dy   .SetLineColor( 7002 )
    histo__ttbar.SetLineColor( 7004 )
    histo__vv   .SetLineColor( 7005 )
    histo__wj   .SetFillColor( 7006 )
    histo__dy   .SetFillColor( 7002 )
    histo__ttbar.SetFillColor( 7004 )
    histo__vv   .SetFillColor( 7005 )
    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__wj)
    v_bkg_hists.push_back(histo__dy)
    v_bkg_hists.push_back(histo__ttbar)
    if addvv: v_bkg_hists.push_back(histo__vv)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle %s
                  --plotOutputName plots/%s
                  --ratio_Maximum 1.4
                  --ratio_Minimum 0.6
                  --showOverflow
                  --MaximumMultiplier 1.5
                  --autoStack
                  %s
                  --ratio_DrawOpt ep
                  """%(varname, histname, extraopt) ,
                  histo__data, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_mu(extraopt=""):

    histname = "histo_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -1 )
    histo__tight.Add( histo__dy, -1 )
    histo__tight.Add( histo__ttbar, -1 )
    if addvv: histo__tight.Add( histo__vv, -1 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = "histo_conecorrptvarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -1 )
    histo__loose.Add( histo__dy, -1 )
    if addvv: histo__loose.Add( histo__vv, -1 )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/fakerate_mu_data
                  --ratio_DrawOpt ep
                  --ratio_Maximum 0.27
                  --ratio_Minimum 0.0
                  --reverseRatio
                  --showOverflow
                  --ratioPaneAtBottom
                  --divideByBinWidth
                  %s
                  --MaximumMultiplier 6
                  --autoStack
                  """%(extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_nvtxrewgt_fakerate_mu(extraopt=""):

    histname = "histo_nvtxrewgt_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -1.01 )
    histo__tight.Add( histo__dy, -1.01 )
    histo__tight.Add( histo__ttbar, -1.01 )
    if addvv: histo__tight.Add( histo__vv   , -1.01 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = "histo_nvtxrewgt_conecorrptvarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -1 )
    histo__loose.Add( histo__dy, -1 )
    histo__loose.Add( histo__ttbar, -1 )
    if addvv: histo__loose.Add( histo__vv   , -1 )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/fakerate_nvtxrewgt_mu_data
                  --ratio_DrawOpt ep
                  --ratio_Maximum 0.27
                  --ratio_Minimum 0.0
                  --reverseRatio
                  --showOverflow
                  --divideByBinWidth
                  --ratioPaneAtBottom
                  %s
                  --MaximumMultiplier 6
                  --autoStack
                  """%(extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_el(extraopt=""):

    histname = "histo_conecorrptvarbin_meas_el"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -0.94 )
    histo__tight.Add( histo__dy, -0.94 )
    histo__tight.Add( histo__ttbar, -0.94 )
    if addvv: histo__tight.Add( histo__vv   , -0.94 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = "histo_conecorrptvarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -0.94 )
    histo__loose.Add( histo__dy, -0.94 )
    histo__loose.Add( histo__ttbar, -0.94 )
    if addvv: histo__loose.Add( histo__vv   , -0.94 )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --plotOutputName plots/fakerate_el_data
                  --ratio_DrawOpt ep
                  --ratio_Maximum 0.57
                  --ratio_Minimum 0.0
                  --reverseRatio
                  --showOverflow
                  --ratioPaneAtBottom
                  --divideByBinWidth
                  %s
                  --MaximumMultiplier 6
                  --autoStack
                  """%(extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_qcd_mu(extraopt=""):

    histname = "histo_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_qcd_mu .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kYellow )

    histname = "histo_conecorrptvarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin( tfile_qcd_mu .Get(histname).Clone("Loose"), histname )
    histo__loose.SetDirectory( 0 )
    histo__loose.SetLineColor( 2 )
    histo__loose.SetMarkerColor( 2 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/fakerate_mu_qcd
                  --ratio_DrawOpt ep
                  --ratio_Maximum 0.27
                  --ratio_Minimum 0.0
                  --reverseRatio
                  --showOverflow
                  --ratioPaneAtBottom
                  %s
                  --MaximumMultiplier 6
                  --autoStack
                  """%(extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_qcd_el(extraopt=""):

    histname = "histo_conecorrptvarbin_meas_el"

    # Get histograms
    histo__tight = rebin( tfile_qcd_el .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kYellow )

    histname = "histo_conecorrptvarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin( tfile_qcd_el .Get(histname).Clone("Loose"), histname )
    histo__loose.SetDirectory( 0 )
    histo__loose.SetLineColor( 2 )
    histo__loose.SetMarkerColor( 2 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --ratio_DrawOpt ep
                  --ratio_Maximum 0.57
                  --ratio_Minimum 0.0
                  --reverseRatio
                  --showOverflow
                  --MaximumMultiplier 6
                  --autoStack
                  --ratioPaneAtBottom
                  %s
                  --plotOutputName plots/fakerate_el_qcd
                  """%(extraopt) ,
                  histo__loose, v_bkg_hists )

if __name__ == "__main__":

    draw("histo_nvtx_highpt50_mu", "N_{vtx}", "--xNbin 1")[0].Print("all")
    draw("histo_nvtx_highpt50_mu", "N_{vtx}", "--ratio_Minimum 0 --ratio_Maximum 15")[0].Print("all")
    draw("histo_met_highpt50_mu", "MET [GeV]", "--ratioPaneAtBottom" )
    draw("histo_nvtxrewgt_nvtx_highpt50_mu", "N_{vtx}", "--ratioPaneAtBottom" )
    draw("histo_nvtxrewgt_met_highpt50_mu", "MET [GeV]", "--ratioPaneAtBottom" )
    draw("histo_nvtx_hmt80pt50_el", "N_{vtx}")
    draw("histo_met_hmt80pt50_el", "MET [GeV]")
    draw("histo_conecorrptvarbin_hmt80pt50_el", "p_{T,e}")
    draw("histo_nvtx_highpt50_el", "N_{vtx}")
    draw("histo_met_highpt50_el", "MET [GeV]", "--ratioPaneAtBottom" )
#    draw("histo_pt_el", "p_{T,e} [GeV]")
#    draw("histo_pt_mu", "p_{T,#mu} [GeV]")
#
    draw("histo_mt_ewk_cr_el", "m_{T,e} [GeV]", "--xNbin 1")[0].Print("all")
    draw("histo_mt_ewk_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 1")[0].Print("all")
    draw("histo_nvtxrewgt_mt_ewk_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 1")[0].Print("all")
#
    draw("histo_mt_cr_el", "m_{T,e} [GeV]")
    draw("histo_mt_cr_mu", "m_{T,#mu} [GeV]")
    draw("histo_nvtxrewgt_mt_cr_mu", "m_{T,#mu} [GeV]", "--ratioPaneAtBottom" )

    draw("histo_ptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("evt_lvl_histo_ptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("histo_ptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("evt_lvl_histo_ptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )

    draw("histo_conecorrptvarbin_loose_meas_el", "p_{T,e} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 0.4 --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("histo_conecorrptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("histo_nvtxrewgt_conecorrptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 504 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
#
    draw("histo_conecorrptvarbin_meas_el", "p_{T,e} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 0.6 --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 505 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("histo_conecorrptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 505 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
    draw("histo_nvtxrewgt_conecorrptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--divideByBinWidth --ratio_Minimum 0 --ratio_Maximum 1  --Minimum 100 --MaximumMultiplier 10000 --ratio_yNdivisions 505 --ratioPaneAtBottom --ratio_yTitle EWK Contam. --reverseRatio" )
#
#    draw_fakerate_mu()
    fakerate_el_data = draw_fakerate_el()
    fakerate_el_qcd  = draw_fakerate_qcd_el()
    fakerate_nvtxrewgt_mu_data = draw_nvtxrewgt_fakerate_mu()
    fakerate_mu_data = draw_fakerate_mu()
    fakerate_mu_qcd  = draw_fakerate_qcd_mu()


    fakerate_el_data[0].SetName( "FR data" )
    fakerate_el_qcd[0].SetName( "FR QCD MC" )
    fakerate_mu_data[0].SetName( "FR data" )
    fakerate_mu_qcd[0].SetName( "FR QCD MC" )
    fakerate_nvtxrewgt_mu_data[0].SetName( "FR data" )

    r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --plotOutputName plots/fakerate_el_full
                  --ratio_DrawOpt ep
                  --ratio_Maximum 2.00
                  --ratio_Minimum 0.0
                  --MaximumMultiplier 2.0
                  --Maximum 0.57
                  --autoStack
                  --ratioPaneAtBottom
                  --stack_DrawOpt ep
                  --legend_bkgDrawOpt ep
                  """,
                  fakerate_el_data, fakerate_el_qcd )

    r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/fakerate_mu_full
                  --ratio_DrawOpt ep
                  --ratio_Maximum 2.00
                  --ratio_Minimum 0.0
                  --MaximumMultiplier 2.0
                  --Maximum 0.27
                  --autoStack
                  --ratioPaneAtBottom
                  --stack_DrawOpt ep
                  --legend_bkgDrawOpt ep
                  """,
                  fakerate_mu_data, fakerate_mu_qcd )

    r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/fakerate_nvtxrewgt_mu_full
                  --ratio_DrawOpt ep
                  --ratio_Maximum 2.00
                  --ratio_Minimum 0.0
                  --MaximumMultiplier 2.0
                  --Maximum 0.27
                  --autoStack
                  --ratioPaneAtBottom
                  --stack_DrawOpt ep
                  --legend_bkgDrawOpt ep
                  """,
                  fakerate_nvtxrewgt_mu_data, fakerate_mu_qcd )

#    draw("histo_nvtx_ewk_cr_mu", "Nvtx")
#    draw("histo_nvtxrewgt_nvtx_ewk_cr_mu", "Nvtx")
#    draw("histo_met_ewk_cr_mu", "MET [GeV]")
#    draw("histo_nvtxrewgt_met_ewk_cr_mu", "MET [GeV]")
#    draw("histo_met_ewk_cr_el", "MET [GeV]")

    #draw("instantLumi_m8i")
#    draw("met_presel", "met_presel")
#    draw("mt_presel", "mt_presel")
#    draw("evt_lvl_nFO2_histo_ptvarbin_meas_mu", "evt_lvl_nFO2_histo_ptvarbin_meas_mu")
#    draw("evt_lvl_nFO2_histo_ptvarbin_loose_meas_mu", "evt_lvl_nFO2_histo_ptvarbin_loose_meas_mu")
#    draw("nFO2_mll_m17i", "nFO2_mll_m17i")
#    draw("evt_lvl_nFO2_histo_ptvarbin_meas_mu", "evt_lvl_nFO2_histo_ptvarbin_meas_mu")
#    draw("nIds_VVV_pt50", "nIds_VVV_pt50")
#    draw("nIds_VVV_pt70", "nIds_VVV_pt70")
#    draw("nIds_VVV_pt120", "nIds_VVV_pt120")
#    draw("nIds_VVV_pt170", "nIds_VVV_pt170")
#    draw("mll_nIds_VVV_eq2", "mll_nIds_VVV_eq2")

