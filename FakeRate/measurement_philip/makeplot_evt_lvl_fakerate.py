#!/bin/env python

import sys
sys.path.append("/home/users/phchang/public_html/tasutil")
import plotmaker
import ROOT as r

r.gStyle.SetPalette( r.kInvertedDarkBodyRadiator )

version = "v6"

tfile_data   = r.TFile("outputs/fakerate_data.root")
tfile_wj     = r.TFile("outputs/fakerate_wj.root")
tfile_dy     = r.TFile("outputs/fakerate_dy.root")
tfile_ttbar  = r.TFile("outputs/fakerate_ttbar.root")
tfile_vv     = r.TFile("outputs/fakerate_vv.root")
tfile_qcd_mu = r.TFile("fakerate_mu_QCD_v1.root".replace('v1',version))
tfile_qcd_el = r.TFile("fakerate_el_QCD_v1.root".replace('v1',version))
#try:
#    tfile_test   = r.TFile("fakerate_DY_madgraph_0.root")
#except:
#    pass

from array import *

global prefix
prefix = ""
norebin = False
addvv = False

def quadsum( numlist ):
    sys.path.append("/home/users/phchang/syncfiles/pyfiles/")
    from errors import E
    errors = [ E(0.0, x) for x in numlist ]
    return sum( errors ).err

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
# Rebinning histograms when needed.
# Currently only the "ptvarbin" variable and "met" is being rebinned to do some "studies".
#
def rebin2d(hist, name):
    ptbins  = array('d', [10., 15., 20., 25., 30., 35., 50., 170.])
    etabins_mu = array('d', [0., 1.2, 2.1, 2.4])
    etabins_el = array('d', [0., 0.8, 1.479, 2.5])
    if norebin:
        return hist
    tmphist = None
    if name.find("ptvarbin") != -1 and name.find("mu") != -1:
        tmphist = r.TH2F( name, name, 7, ptbins, 3, etabins_mu)
        tmphist.SetDirectory( 0 )
    elif name.find("ptvarbin") != -1 and name.find("el") != -1:
        tmphist = r.TH2F( name, name, 7, ptbins, 3, etabins_el)
        tmphist.SetDirectory( 0 )
    for ix in xrange( 1, 7 ):
        for iy in xrange( 1, 4 ):
            tmphist.SetBinContent( ix, iy, hist.GetBinContent( ix, iy ) )
            tmphist.SetBinError( ix, iy, hist.GetBinError( ix, iy ) )
    tmphist.SetBinContent( 7, 1, hist.GetBinContent( 7, 1 ) + hist.GetBinContent( 8, 1 ) + hist.GetBinContent( 9, 1 ) + hist.GetBinContent( 10, 1 ) )
    tmphist.SetBinContent( 7, 2, hist.GetBinContent( 7, 2 ) + hist.GetBinContent( 8, 2 ) + hist.GetBinContent( 9, 2 ) + hist.GetBinContent( 10, 2 ) )
    tmphist.SetBinContent( 7, 3, hist.GetBinContent( 7, 3 ) + hist.GetBinContent( 8, 3 ) + hist.GetBinContent( 9, 3 ) + hist.GetBinContent( 10, 3 ) )
    tmphist.SetBinError( 7, 1, quadsum( [ hist.GetBinError( 7, 1 ) , hist.GetBinError( 8, 1 ) , hist.GetBinError( 9, 1 ) , hist.GetBinError( 10, 1 ) ] ) )
    tmphist.SetBinError( 7, 2, quadsum( [ hist.GetBinError( 7, 2 ) , hist.GetBinError( 8, 2 ) , hist.GetBinError( 9, 2 ) , hist.GetBinError( 10, 2 ) ] ) )
    tmphist.SetBinError( 7, 3, quadsum( [ hist.GetBinError( 7, 3 ) , hist.GetBinError( 8, 3 ) , hist.GetBinError( 9, 3 ) , hist.GetBinError( 10, 3 ) ] ) )
    return tmphist

####################################################################################################
## Rebinning histograms when needed.
## Currently only the "ptvarbin" variable and "met" is being rebinned to do some "studies".
##
#def printFakeRateFunction( ratio, name ):
#    print "double getFR_%s( float conecorrpt, 

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw(histname, varname, extraopt="", scale=1.00):

    # Get histograms
    histo__data = tfile_data .Get(histname).Clone("Data")
    histo__wj   = tfile_wj   .Get(histname).Clone("WJets")
    histo__dy   = tfile_dy   .Get(histname).Clone("DY")
    histo__ttbar= tfile_ttbar.Get(histname).Clone("TTbar")
    if addvv: histo__vv   = tfile_ttbar.Get(histname).Clone("VV")
    histo__data .SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__wj   .Scale( scale )
    histo__dy   .Scale( scale )
    histo__ttbar.Scale( scale )
    if addvv: histo__vv   .Scale( scale )
    histo__data .SetLineColor( 1 )
    histo__wj   .SetLineColor( 7006 )
    histo__dy   .SetLineColor( 7002 )
    histo__ttbar.SetLineColor( 7004 )
    if addvv: histo__vv   .SetLineColor( 7005 )
    histo__wj   .SetFillColor( 7006 )
    histo__dy   .SetFillColor( 7002 )
    histo__ttbar.SetFillColor( 7004 )
    if addvv: histo__vv   .SetFillColor( 7005 )
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
                  --ratioPaneAtBottom
                  %s
                  --ratio_DrawOpt ep
                  """%(varname, histname, extraopt) ,
                  histo__data, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_mu(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_histo_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv, -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_histo_conecorrptvarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv, -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/%sfakerate_mu_data
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
                  """%(prefix, extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_nvtxrewgt_fakerate_el(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_el"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv   , -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv   , -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --plotOutputName plots/%sfakerate_nvtxrewgt_el_data
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
                  """%(prefix, extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_nvtxrewgt_fakerate_mu(extraopt="", scale=1.0):
    global prefix
    print "hereHEREHREHREH", prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv   , -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv   , -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,#mu} [GeV]
                  --plotOutputName plots/%sfakerate_nvtxrewgt_mu_data
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
                  """%(prefix, extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_el(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_histo_conecorrptvarbin_meas_el"

    # Get histograms
    histo__tight = rebin( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv   , -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_histo_conecorrptvarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin( tfile_dy   .Get(histname).Clone("DY")   , histname )
    histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv   , -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --plotOutputName plots/%sfakerate_el_data
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
                  """%(prefix, extraopt) ,
                  histo__loose, v_bkg_hists )

###################################################################################################
# Plot 1D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_fakerate_qcd_mu(extraopt=""):
    global prefix

    histname = "evt_lvl_histo_conecorrptvarbin_meas_mu"

    # Get histograms
    histo__tight = rebin( tfile_qcd_mu .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kYellow )

    histname = "evt_lvl_histo_conecorrptvarbin_loose_meas_mu"

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
    global prefix

    histname = "evt_lvl_histo_conecorrptvarbin_meas_el"

    # Get histograms
    histo__tight = rebin( tfile_qcd_el .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kYellow )

    histname = "evt_lvl_histo_conecorrptvarbin_loose_meas_el"

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

###################################################################################################
# Plot 2D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_nvtxrewgt_fakerate_mu_2d(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_mu"

    # Get histograms
    histo__tight = rebin2d( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin2d( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin2d( tfile_dy   .Get(histname).Clone("DY"), histname )
    histo__ttbar = rebin2d( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv   , -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin2d( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin2d( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin2d( tfile_dy   .Get(histname).Clone("DY"), histname )
    histo__ttbar = rebin2d( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv   , -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    ratio = histo__tight.Clone( "muon_fakerate_conecorrpt_v_eta" )
    ratio.SetDirectory( 0 )
    ratio.Divide( histo__loose )

    c1 = r.TCanvas( "", "", 0, 0, 800, 800 )
    c1.SetLogx()
    r.gStyle.SetPaintTextFormat( ".3f" )
    ratio.SetMaximum(0.5)
    ratio.SetMinimum(-0.15)
    ratio.SetMarkerColor(1)
    ratio.SetMarkerSize(0.8)
    ratio.SetContour(100)
    ratio.GetXaxis().SetMoreLogLabels()
    ratio.Draw( "colztexte" )
    c1.SaveAs( "plots/2dmuonfakerate.pdf" )
    return ratio

###################################################################################################
# Plot 2D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_qcd_fakerate_mu_2d(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_mu"

    # Get histograms
    histo__tight = rebin2d( tfile_qcd_mu .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_mu"

    # Get histograms
    histo__loose = rebin2d( tfile_qcd_mu .Get(histname).Clone("Loose"), histname )
    histo__loose.SetDirectory( 0 )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    ratio = histo__tight.Clone( "muon_fakerate_conecorrpt_v_eta_qcd" )
    ratio.SetDirectory( 0 )
    ratio.Divide( histo__loose )

    c1 = r.TCanvas( "", "", 0, 0, 800, 800 )
    c1.SetLogx()
    r.gStyle.SetPaintTextFormat( ".3f" )
    ratio.SetMaximum(0.5)
    ratio.SetMinimum(-0.15)
    ratio.SetMarkerColor(1)
    ratio.SetMarkerSize(0.8)
    ratio.SetContour(100)
    ratio.GetXaxis().SetMoreLogLabels()
    ratio.Draw( "colztexte" )
    c1.SaveAs( "plots/2dmuonfakerate_qcd.pdf" )
    return ratio

###################################################################################################
# Plot 2D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_nvtxrewgt_fakerate_el_2d(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_el"

    # Get histograms
    histo__tight = rebin2d( tfile_data .Get(histname).Clone("Tight"), histname )
    histo__wj    = rebin2d( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin2d( tfile_dy   .Get(histname).Clone("DY"), histname )
    histo__ttbar = rebin2d( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__tight.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__tight.Add( histo__wj, -scale )
    histo__tight.Add( histo__dy, -scale )
    histo__tight.Add( histo__ttbar, -scale )
    if addvv: histo__tight.Add( histo__vv   , -scale )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin2d( tfile_data .Get(histname).Clone("Loose"), histname )
    histo__wj    = rebin2d( tfile_wj   .Get(histname).Clone("WJets"), histname )
    histo__dy    = rebin2d( tfile_dy   .Get(histname).Clone("DY"), histname )
    histo__ttbar = rebin2d( tfile_ttbar.Get(histname).Clone("TTbar"), histname )
    if addvv: histo__vv    = rebin( tfile_vv   .Get(histname).Clone("VV")   , histname )
    histo__loose.SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__ttbar.SetDirectory( 0 )
    if addvv: histo__vv   .SetDirectory( 0 )
    histo__loose.Add( histo__wj, -scale )
    histo__loose.Add( histo__dy, -scale )
    histo__loose.Add( histo__ttbar, -scale )
    if addvv: histo__loose.Add( histo__vv   , -scale )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    ratio = histo__tight.Clone( "elec_fakerate_conecorrpt_v_eta" )
    ratio.SetDirectory( 0 )
    ratio.Divide( histo__loose )

    c1 = r.TCanvas( "", "", 0, 0, 800, 800 )
    c1.SetLogx()
    r.gStyle.SetPaintTextFormat( ".3f" )
    ratio.SetMaximum(0.5)
    ratio.SetMarkerColor(1)
    ratio.SetMarkerSize(0.8)
    ratio.SetContour(100)
    ratio.GetXaxis().SetMoreLogLabels()
    ratio.Draw( "colztexte" )
    c1.SaveAs( "plots/2delectronfakerate.pdf" )
    return ratio

###################################################################################################
# Plot 2D distribution (default : data, W, DY. optional : add QCD, or ttbar)
#
def draw_qcd_fakerate_el_2d(extraopt="", scale=1.0):
    global prefix

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_meas_el"

    # Get histograms
    histo__tight = rebin2d( tfile_qcd_el .Get(histname).Clone("Tight"), histname )
    histo__tight.SetDirectory( 0 )
    histo__tight.SetLineColor( 1 )
    histo__tight.SetFillColor( r.kGray + 1 )

    histname = prefix + "evt_lvl_nvtxrewgt_histo_conecorrptvarbin_etavarbin_loose_meas_el"

    # Get histograms
    histo__loose = rebin2d( tfile_qcd_el .Get(histname).Clone("Loose"), histname )
    histo__loose.SetDirectory( 0 )
    histo__loose.SetLineColor( 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back(histo__tight)

    ratio = histo__tight.Clone( "elec_fakerate_conecorrpt_v_eta_qcd" )
    ratio.SetDirectory( 0 )
    ratio.Divide( histo__loose )

    c1 = r.TCanvas( "", "", 0, 0, 800, 800 )
    c1.SetLogx()
    r.gStyle.SetPaintTextFormat( ".3f" )
    ratio.SetMaximum(0.5)
    ratio.SetMarkerColor(1)
    ratio.SetMarkerSize(0.8)
    ratio.SetContour(100)
    ratio.GetXaxis().SetMoreLogLabels()
    ratio.Draw( "colztexte" )
    c1.SaveAs( "plots/2delectronfakerate_qcd.pdf" )
    return ratio

def main() :
    global prefix

    f = r.TFile( "fakerate_pt_v_eta_v1.root".replace('v1',version), "recreate" )
    sf_mu = draw("evt_lvl_nvtxrewgt_histo_mt_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
    sf_mu_syst1 = draw("syst13_evt_lvl_nvtxrewgt_histo_mt_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
    sf_mu_syst2 = draw("syst14_evt_lvl_nvtxrewgt_histo_mt_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )

    sf_el = draw("evt_lvl_nvtxrewgt_histo_mt_cr_el", "m_{T,e} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
    sf_el_syst1 = draw("syst13_evt_lvl_nvtxrewgt_histo_mt_cr_el", "m_{T,e} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
    sf_el_syst2 = draw("syst14_evt_lvl_nvtxrewgt_histo_mt_cr_el", "m_{T,e} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )

    fakerate_nvtxrewgt_mu_data = draw_nvtxrewgt_fakerate_mu("--onlyLog --onlyLog", sf_mu)
    prefix = "syst13_"
    fakerate_nvtxrewgt_mu_data_syst1 = draw_nvtxrewgt_fakerate_mu("--onlyLog --plotOutputName plots/fakerate_nvtxrewgt_mu_data_syst1", sf_mu_syst1)
    prefix = "syst14_"
    fakerate_nvtxrewgt_mu_data_syst2 = draw_nvtxrewgt_fakerate_mu("--onlyLog --plotOutputName plots/fakerate_nvtxrewgt_mu_data_syst2", sf_mu_syst2)
    prefix = ""
    fakerate_nvtxrewgt_el_data = draw_nvtxrewgt_fakerate_el("--onlyLog --onlyLog", sf_el)
    prefix = "syst13_"
    fakerate_nvtxrewgt_el_data_syst1 = draw_nvtxrewgt_fakerate_el("--onlyLog --plotOutputName plots/fakerate_nvtxrewgt_el_data_syst1", sf_el_syst1)
    prefix = "syst14_"
    fakerate_nvtxrewgt_el_data_syst2 = draw_nvtxrewgt_fakerate_el("--onlyLog --plotOutputName plots/fakerate_nvtxrewgt_el_data_syst2", sf_el_syst2)
    prefix = ""
    fakerate_mu_qcd  = draw_fakerate_qcd_mu()
    fakerate_el_qcd  = draw_fakerate_qcd_el()

    draw_qcd_fakerate_mu_2d("").Write()
    draw_qcd_fakerate_el_2d("").Write()

    fakerate_nvtxrewgt_mu_data[0].SetName( "FR data" )
    fakerate_nvtxrewgt_el_data[0].SetName( "FR data" )
    fakerate_mu_qcd[0].SetName( "FR QCD MC" )
    fakerate_el_qcd[0].SetName( "FR QCD MC" )

    syst_data_vectors = r.vector( "TH1*" )()
    syst_data_vectors.push_back( fakerate_nvtxrewgt_el_data_syst1[0] )
    syst_data_vectors.push_back( fakerate_nvtxrewgt_el_data_syst2[0] )
    fakerate_nvtxrewgt_el_data_systsum = r.getSystByMaxDiff( fakerate_nvtxrewgt_el_data[0], syst_data_vectors )
    syst_data_vectors = r.vector( "TH1*" )()
    syst_data_vectors.push_back( fakerate_nvtxrewgt_mu_data_syst1[0] )
    syst_data_vectors.push_back( fakerate_nvtxrewgt_mu_data_syst2[0] )
    fakerate_nvtxrewgt_mu_data_systsum = r.getSystByMaxDiff( fakerate_nvtxrewgt_mu_data[0], syst_data_vectors )

    data_vectors = r.vector( "TH1*" )()
    bkg_vectors  = r.vector( "TH1*" )()
    sig_vectors  = r.vector( "TH1*" )()
    syst_data_vectors = r.vector( "TH1*" )()
    syst_bkg_vectors  = r.vector( "TH1*" )()
    syst_sig_vectors  = r.vector( "TH1*" )()
    data_vectors.push_back( fakerate_nvtxrewgt_mu_data[0] )
    syst_data_vectors.push_back( fakerate_nvtxrewgt_mu_data_systsum )
    bkg_vectors.push_back( fakerate_mu_qcd[0] )
    syst_bkg_vectors.push_back( fakerate_mu_qcd[0] )
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
                  --systByDiff
                  --onlyLin
                  --ratioPaneAtBottom
                  --stack_DrawOpt ep
                  --legend_bkgDrawOpt ep
                  """,
                  data_vectors, bkg_vectors, sig_vectors, syst_data_vectors, syst_bkg_vectors, syst_sig_vectors )

    data_vectors = r.vector( "TH1*" )()
    bkg_vectors  = r.vector( "TH1*" )()
    sig_vectors  = r.vector( "TH1*" )()
    syst_data_vectors = r.vector( "TH1*" )()
    syst_bkg_vectors  = r.vector( "TH1*" )()
    syst_sig_vectors  = r.vector( "TH1*" )()
    data_vectors.push_back( fakerate_nvtxrewgt_el_data[0] )
    syst_data_vectors.push_back( fakerate_nvtxrewgt_el_data_systsum )
    bkg_vectors.push_back( fakerate_el_qcd[0] )
    syst_bkg_vectors.push_back( fakerate_el_qcd[0] )
    r.plotmaker( """
                  --yTitle N leptons
                  --xTitle p_{T,e} [GeV]
                  --plotOutputName plots/fakerate_nvtxrewgt_el_full
                  --ratio_DrawOpt ep
                  --ratio_Maximum 2.00
                  --ratio_Minimum 0.0
                  --MaximumMultiplier 2.0
                  --Maximum 0.57
                  --autoStack
                  --systByDiff
                  --onlyLin
                  --ratioPaneAtBottom
                  --stack_DrawOpt ep
                  --legend_bkgDrawOpt ep
                  """,
                  data_vectors, bkg_vectors, sig_vectors, syst_data_vectors, syst_bkg_vectors, syst_sig_vectors )

    return

if __name__ == "__main__":

    prefix = ""
    main()

#    for i in xrange(1,15):
#        if i != 13 and i != 14:
#            continue
#        prefix = "syst%d_" % i
#        print prefix
#        main()

##    print draw("mll_e8i", "mll_e8i", "--xNbin 1 --reverseRatio" )[0].GetBinContent( 1 )
##    print draw("mll_e17i", "mll_e17i", "--xNbin 1 --reverseRatio" )[0].GetBinContent( 1 )
##    print draw("mll_m8i", "mll_m8i", "--xNbin 1 --reverseRatio" )[0].GetBinContent( 1 )
##    print draw("mll_m17i", "mll_m17i", "--xNbin 1 --reverseRatio" )[0].GetBinContent( 1 )
#
#    # Draw MT plot in the control region
#    sf_el = draw(prefix + "evt_lvl_histo_mt_cr_el", "m_{T,e} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
#    sf_mu = draw(prefix + "evt_lvl_histo_mt_cr_mu", "m_{T,#mu} [GeV]", "--xNbin 5" )[0].GetBinContent( 3 )
#    print sf_el, sf_mu
#
#    prefix_global = prefix
#
#
#    draw_nvtxrewgt_fakerate_mu_2d("", sf_mu).Write()
#    draw_nvtxrewgt_fakerate_el_2d("", sf_el).Write()
#
#    draw_qcd_fakerate_mu_2d("").Write()
#    draw_qcd_fakerate_el_2d("").Write()
#
#
#    draw(prefix + "evt_lvl_histo_mt_cr_el", "m_{T,e} [GeV]" )
#    draw(prefix + "evt_lvl_histo_mt_cr_mu", "m_{T,#mu} [GeV]" )
#
#    draw(prefix + "evt_lvl_histo_ptvarbin_meas_el", "p_{T,e} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#    draw(prefix + "evt_lvl_histo_ptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#
#    draw(prefix + "evt_lvl_histo_ptvarbin_loose_meas_el", "p_{T,e} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#    draw(prefix + "evt_lvl_histo_ptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_el", "p_{T,e} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_loose_meas_mu", "p_{T,#mu} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_el", "p_{T,e} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_ptvarbin_meas_mu", "p_{T,#mu} [GeV]", "--reverseRatio --ratio_Minimum 0 --ratio_Maximum 1 --divideByBinWidth --Minimum 100 --MaximumMultiplier 1000" )
#
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_mt_cr_el", "m_{T,e} [GeV]" )
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_mt_cr_mu", "m_{T,#mu} [GeV]" )
#
#    draw(prefix + "evt_lvl_histo_nvtx_highpt50_el", "N_{vtx} (e events)", "--xNbin 1" )[0].Print("all")
#    draw(prefix + "evt_lvl_histo_nvtx_highpt50_mu", "N_{vtx} (#mu events)", "--xNbin 1" )[0].Print("all")
#
#    draw(prefix + "evt_lvl_histo_nvtx_highpt50_el", "N_{vtx} (e events)" )[0].Print("all")
#    draw(prefix + "evt_lvl_histo_nvtx_highpt50_mu", "N_{vtx} (#mu events)" )[0].Print("all")
#
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_el", "N_{vtx} (e events)" )[0].Print("all")
#    draw(prefix + "evt_lvl_nvtxrewgt_histo_nvtx_highpt50_mu", "N_{vtx} (#mu events)" )[0].Print("all")
#
#    draw(prefix + "evt_lvl_histo_met_highpt50_el", "MET [GeV] (e events)" )
#    draw(prefix + "evt_lvl_histo_met_highpt50_mu", "MET [GeV] (#mu events)" )
#
#    fakerate_el_data = draw_fakerate_el("", sf_el)
#    fakerate_el_data_syst = draw_fakerate_el("--plotOutputName plots/fakerate_el_data_syst", 1.00)
#    fakerate_el_qcd  = draw_fakerate_qcd_el()
#    fakerate_mu_data = draw_fakerate_mu("", sf_mu)
#    fakerate_nvtxrewgt_mu_data = draw_nvtxrewgt_fakerate_mu("", sf_mu)
#    prefix = "syst13_"
#    fakerate_nvtxrewgt_mu_data_syst1 = draw_nvtxrewgt_fakerate_mu("--plotOutputName plots/fakerate_nvtxrewgt_mu_data_syst1", sf_mu_syst1)
#    prefix = "syst14_"
#    fakerate_nvtxrewgt_mu_data_syst2 = draw_nvtxrewgt_fakerate_mu("--plotOutputName plots/fakerate_nvtxrewgt_mu_data_syst2", sf_mu_syst2)
#    prefix = ""
#    fakerate_nvtxrewgt_el_data = draw_nvtxrewgt_fakerate_el("", sf_el)
#    fakerate_nvtxrewgt_el_data_syst = draw_nvtxrewgt_fakerate_el("--plotOutputName plots/fakerate_nvtxrewgt_el_data_syst", sf_el)
#    fakerate_mu_qcd  = draw_fakerate_qcd_mu()
#
#    fakerate_el_data[0].SetName( "FR data" )
##    fakerate_el_qcd[0].SetName( "FR QCD MC" )
#    fakerate_mu_data[0].SetName( "FR data" )
#    fakerate_nvtxrewgt_mu_data[0].SetName( "FR data" )
#    fakerate_nvtxrewgt_el_data[0].SetName( "FR data" )
##    fakerate_mu_qcd[0].SetName( "FR QCD MC" )
#
#    data_vectors = r.vector( "TH1*" )()
#    bkg_vectors  = r.vector( "TH1*" )()
#    sig_vectors  = r.vector( "TH1*" )()
#    syst_data_vectors = r.vector( "TH1*" )()
#    syst_bkg_vectors  = r.vector( "TH1*" )()
#    syst_sig_vectors  = r.vector( "TH1*" )()
#    data_vectors.push_back( fakerate_el_data[0] )
#    syst_data_vectors.push_back( fakerate_el_data_syst[0] )
##    bkg_vectors.push_back( fakerate_el_qcd[0] )
##    syst_bkg_vectors.push_back( fakerate_el_qcd[0] )
#    r.plotmaker( """
#                  --yTitle N leptons
#                  --xTitle p_{T,e} [GeV]
#                  --plotOutputName plots/fakerate_el_full
#                  --ratio_DrawOpt ep
#                  --ratio_Maximum 2.00
#                  --ratio_Minimum 0.0
#                  --MaximumMultiplier 2.0
#                  --Maximum 0.57
#                  --systByDiff
#                  --autoStack
#                  --ratioPaneAtBottom
#                  --stack_DrawOpt ep
#                  --legend_bkgDrawOpt ep
#                  """,
#                  data_vectors, bkg_vectors, sig_vectors, syst_data_vectors, syst_bkg_vectors, syst_sig_vectors )
#
#    r.plotmaker( """
#                  --yTitle N leptons
#                  --xTitle p_{T,#mu} [GeV]
#                  --plotOutputName plots/fakerate_mu_full
#                  --ratio_DrawOpt ep
#                  --ratio_Maximum 2.00
#                  --ratio_Minimum 0.0
#                  --MaximumMultiplier 2.0
#                  --Maximum 0.27
#                  --autoStack
#                  --ratioPaneAtBottom
#                  --stack_DrawOpt ep
#                  --legend_bkgDrawOpt ep
#                  """,
#                  fakerate_mu_data, fakerate_mu_qcd )
#
#    data_vectors = r.vector( "TH1*" )()
#    bkg_vectors  = r.vector( "TH1*" )()
#    sig_vectors  = r.vector( "TH1*" )()
#    syst_data_vectors = r.vector( "TH1*" )()
#    syst_bkg_vectors  = r.vector( "TH1*" )()
#    syst_sig_vectors  = r.vector( "TH1*" )()
#    data_vectors.push_back( fakerate_nvtxrewgt_mu_data[0] )
#    syst_data_vectors.push_back( fakerate_nvtxrewgt_mu_data_syst1[0] )
#    syst_data_vectors.push_back( fakerate_nvtxrewgt_mu_data_syst2[0] )
#    bkg_vectors.push_back( fakerate_mu_qcd[0] )
#    syst_bkg_vectors.push_back( fakerate_mu_qcd[0] )
#    r.plotmaker( """
#                  --yTitle N leptons
#                  --xTitle p_{T,#mu} [GeV]
#                  --plotOutputName plots/fakerate_nvtxrewgt_mu_full
#                  --ratio_DrawOpt ep
#                  --ratio_Maximum 2.00
#                  --ratio_Minimum 0.0
#                  --MaximumMultiplier 2.0
#                  --Maximum 0.27
#                  --autoStack
#                  --systByDiff
#                  --ratioPaneAtBottom
#                  --stack_DrawOpt ep
#                  --legend_bkgDrawOpt ep
#                  """,
#                  data_vectors, bkg_vectors, sig_vectors, syst_data_vectors, syst_bkg_vectors, syst_sig_vectors )
#
#    data_vectors = r.vector( "TH1*" )()
#    bkg_vectors  = r.vector( "TH1*" )()
#    sig_vectors  = r.vector( "TH1*" )()
#    syst_data_vectors = r.vector( "TH1*" )()
#    syst_bkg_vectors  = r.vector( "TH1*" )()
#    syst_sig_vectors  = r.vector( "TH1*" )()
#    data_vectors.push_back( fakerate_nvtxrewgt_el_data[0] )
#    syst_data_vectors.push_back( fakerate_nvtxrewgt_el_data_syst[0] )
#    bkg_vectors.push_back( fakerate_el_qcd[0] )
#    syst_bkg_vectors.push_back( fakerate_el_qcd[0] )
#    r.plotmaker( """
#                  --yTitle N leptons
#                  --xTitle p_{T,e} [GeV]
#                  --plotOutputName plots/fakerate_nvtxrewgt_el_full
#                  --ratio_DrawOpt ep
#                  --ratio_Maximum 2.00
#                  --ratio_Minimum 0.0
#                  --MaximumMultiplier 2.0
#                  --Maximum 0.57
#                  --autoStack
#                  --systByDiff
#                  --ratioPaneAtBottom
#                  --stack_DrawOpt ep
#                  --legend_bkgDrawOpt ep
#                  """,
#                  data_vectors, bkg_vectors, sig_vectors, syst_data_vectors, syst_bkg_vectors, syst_sig_vectors )
#
