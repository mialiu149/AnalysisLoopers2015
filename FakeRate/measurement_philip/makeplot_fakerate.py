#!/bin/env python

import sys
sys.path.append("/home/users/phchang/public_html/tasutil")
import plotmaker
import ROOT as r

tfile_data   = r.TFile("outputs/fakerate_data.root")
tfile_dy     = r.TFile("outputs/fakerate_dy.root")
tfile_wj     = r.TFile("outputs/fakerate_wj.root")
tfile_ttbar  = r.TFile("outputs/fakerate_ttbar.root")
tfile_qcd_mu = r.TFile("outputs/fakerate_qcd_mu.root")
tfile_qcd_el = r.TFile("outputs/fakerate_qcd_el.root")

from array import *

norebin = True

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
def draw(histname, additional_optstring="", include_ttbar=False, include_QCD=False, rewgthist=None, suffix=""):

    print histname

    # Get histograms
    histo__data = rebin( tfile_data .Get(histname).Clone("Data"), histname )
    histo__dy   = rebin( tfile_dy   .Get(histname).Clone("DY"), histname )
    histo__wj   = rebin( tfile_wj   .Get(histname).Clone("W"), histname )
    histo__data .SetDirectory( 0 )
    histo__dy   .SetDirectory( 0 )
    histo__wj   .SetDirectory( 0 )
    histo__data.SetLineColor( 1 )
    histo__dy.SetFillColor( 7002 )
    histo__wj.SetFillColor( 7006 )
    histo__dy.SetLineColor( 7002 )
    histo__wj.SetLineColor( 7006 )

    # reweight histograms (NOTE: only used for ptvarbin. This was used to study why high pt muon fake rate was rising)
    if rewgthist:
        try:
            for ibin in xrange( 0, histo__dy.GetNbinsX() + 1 ):
                if ibin == 0 or ibin == 1:
                    continue
                histo__dy.SetBinContent( ibin + 1, histo__dy.GetBinContent( ibin + 1 ) * rewgthist.GetBinContent( ibin + 1 ) )
                histo__wj.SetBinContent( ibin + 1, histo__wj.GetBinContent( ibin + 1 ) * rewgthist.GetBinContent( ibin + 1 ) )
        except:
            histo__dy.Scale( rewgthist )
            histo__wj.Scale( rewgthist )

    # The v_bkg_hists will be inputted to the plotmaker script
    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back( histo__dy )
    v_bkg_hists.push_back( histo__wj )

    # To include ttbar MC if the option is turned on
    if include_ttbar:
        histo__ttbar = rebin( tfile_ttbar.Get(histname).Clone("t#bar{t}"), histname)
        histo__ttbar.SetDirectory( 0 )
        histo__ttbar.SetFillColor( 7004 )
        histo__ttbar.SetLineColor( 7004 )
        if rewgthist:
            for ibin in xrange( 0, histo__dy.GetNbinsX() + 1 ):
                histo__ttbar.SetBinContent( ibin + 1, histo__ttbar.GetBinContent( ibin + 1 ) * rewgthist.GetBinContent( ibin + 1 ) )
        v_bkg_hists.push_back( histo__ttbar )

    # To include QCD MC if the option is turned on
    if include_QCD:
        histo__qcd_mu= rebin( tfile_qcd_mu.Get(histname).Clone("QCD"), histname )
        histo__qcd_mu.SetDirectory( 0 )
        histo__qcd_mu.SetFillColor( 7003 )
        histo__qcd_mu.SetLineColor( 7003 )
        if rewgthist:
            for ibin in xrange( 0, histo__dy.GetNbinsX() + 1 ):
                histo__qcd_mu.SetBinContent( ibin + 1, histo__qcd_mu.GetBinContent( ibin + 1 ) * rewgthist.GetBinContent( ibin + 1 ) )
        v_bkg_hists.push_back( histo__qcd_mu )

    # To divide by bin width if the variable binning is used
    if histname.find( "varbin" ):
        additional_optstring += "--divideByBinWidth"

    # To print histogram infos
    for bkg_hist in v_bkg_hists:
        bkg_hist.Print("all")

    # To print histogram infos
    histo__data.Print("all")

    # Run the plot and return ratio plot
    # The plotmaker function returns the data/MC ratio TH1 created during the plotting process.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle m_{T,#mu} [GeV]
                  --plotOutputName %s
                  --ratio_DrawOpt ep
                  --ratio_Maximum 1.3
                  --ratio_Minimum 0.
                  --showOverflow
                  --ratioPaneAtBottom
                  --autoStack
                  %s
                  """%("plots/" + histname + suffix, additional_optstring),
                  histo__data, v_bkg_hists )

###################################################################################################
# Plot 1D distribution of Tight and Loose MRs with electroweak part subtracted for both tight and loose region.
#
def draw_ewk_subtr(num_histname, den_histname, plotname, additional_optstring="", include_ttbar=False, rewgthist=None, suffix=""):

    # Get the histograms
    histo_num__data = rebin( tfile_data .Get(num_histname).Clone("Tight Data") , num_histname)
    histo_num__dy   = rebin( tfile_dy   .Get(num_histname).Clone("DYskip") , num_histname)
    histo_num__wj   = rebin( tfile_wj   .Get(num_histname).Clone("Wskip") , num_histname)
    histo_den__data = rebin( tfile_data .Get(den_histname).Clone("Loose Data") , den_histname)
    histo_den__dy   = rebin( tfile_dy   .Get(den_histname).Clone("DYskip") , den_histname)
    histo_den__wj   = rebin( tfile_wj   .Get(den_histname).Clone("Wskip") , den_histname)

    # Do some cosmetics
    histo_num__data .SetDirectory( 0 )
    histo_num__dy   .SetDirectory( 0 )
    histo_num__wj   .SetDirectory( 0 )
    histo_den__data .SetDirectory( 0 )
    histo_den__dy   .SetDirectory( 0 )
    histo_den__wj   .SetDirectory( 0 )
    histo_num__data .SetLineColor( 1 )
    histo_num__data .SetFillColor( r.kGray + 1 )
    histo_den__data .SetLineColor( 1 )
    histo_num__dy.SetFillColor( 7002 )
    histo_num__wj.SetFillColor( 7006 )
    histo_num__dy.SetLineColor( 7002 )
    histo_num__wj.SetLineColor( 7006 )
    histo_den__dy.SetFillColor( 7002 )
    histo_den__wj.SetFillColor( 7006 )
    histo_den__dy.SetLineColor( 7002 )
    histo_den__wj.SetLineColor( 7006 )

    # Rewight histograms (NOTE this was used to study why muon fake rate was rising in pT)
    if rewgthist:
        if rewgthist[0]:
            num_rewgthist = rewgthist[0]
            for ibin in xrange( 0, histo_num__dy.GetNbinsX() + 1 ):
                print ibin + 1, num_rewgthist.GetBinContent( ibin + 1 )
                histo_num__dy.SetBinContent( ibin + 1, histo_num__dy.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )
                histo_num__wj.SetBinContent( ibin + 1, histo_num__wj.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )

        if rewgthist[1]:
            den_rewgthist = rewgthist[1]
            for ibin in xrange( 0, histo_den__dy.GetNbinsX() + 1 ):
                print ibin + 1, den_rewgthist.GetBinContent( ibin + 1 )
                histo_den__dy.SetBinContent( ibin + 1, histo_den__dy.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )
                histo_den__wj.SetBinContent( ibin + 1, histo_den__wj.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )

        if rewgthist[2]:
            flatrewgt = rewgthist[2]
            histo_num__dy.Scale( flatrewgt )
            histo_num__wj.Scale( flatrewgt )

        if rewgthist[3]:
            flatrewgt = rewgthist[3]
            histo_den__dy.Scale( flatrewgt )
            histo_den__wj.Scale( flatrewgt )

    # As the dy/wj will be subtracted, flip the scale
    # the "plotmaker" will then "subtract" by adding a negative histogram
    histo_num__dy.Scale( -1 )
    histo_num__wj.Scale( -1 )
    histo_den__dy.Scale( -1 )
    histo_den__wj.Scale( -1 )

    # The actual variable that will be passed ton plotmaker
    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back( histo_num__data )
    v_bkg_hists.push_back( histo_num__dy )
    v_bkg_hists.push_back( histo_num__wj )
    v_data_hists = r.vector("TH1*")()
    v_data_hists.push_back( histo_den__data )
    v_data_hists.push_back( histo_den__dy )
    v_data_hists.push_back( histo_den__wj )

    # if include ttbar MC option is turned on, add the ttbar MC
    if include_ttbar:
        histo_num__ttbar= rebin( tfile_ttbar.Get(num_histname).Clone("t#bar{t}skip") , num_histname)
        histo_den__ttbar= rebin( tfile_ttbar.Get(den_histname).Clone("t#bar{t}skip") , den_histname)
        histo_num__ttbar.SetDirectory( 0 )
        histo_num__ttbar.SetFillColor( 7004 )
        histo_num__ttbar.SetLineColor( 7004 )
        histo_den__ttbar.SetDirectory( 0 )
        histo_den__ttbar.SetFillColor( 7004 )
        histo_den__ttbar.SetLineColor( 7004 )
        if rewgthist:
            if rewgthist[0]:
                num_rewgthist = rewgthist[0]
                for ibin in xrange( 0, histo_num__dy.GetNbinsX() + 1 ):
                    print ibin + 1, num_rewgthist.GetBinContent( ibin + 1 )
                    histo_num__ttbar.SetBinContent( ibin + 1, histo_num__ttbar.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )

            if rewgthist[1]:
                den_rewgthist = rewgthist[1]
                for ibin in xrange( 0, histo_den__dy.GetNbinsX() + 1 ):
                    print ibin + 1, den_rewgthist.GetBinContent( ibin + 1 )
                    histo_den__ttbar.SetBinContent( ibin + 1, histo_den__ttbar.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )

            if rewgthist[2]:
                flatrewgt = rewgthist[2]
                histo_num__ttbar.Scale( flatrewgt )

            if rewgthist[3]:
                flatrewgt = rewgthist[3]
                histo_den__ttbar.Scale( flatrewgt )

        histo_num__ttbar.Scale( -1 )
        histo_den__ttbar.Scale( -1 )
        v_bkg_hists.push_back( histo_num__ttbar )
        v_data_hists.push_back( histo_den__ttbar )

    # If the binning is variable add the divideByBinWidth option
    if num_histname.find( "varbin" ):
        additional_optstring += "--divideByBinWidth"

    # make a plot of tight region vs. loose region and the returning ratio TH1 object will be the fake rate itself.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle m_{T,#mu} [GeV]
                  --plotOutputName %s
                  --ratio_DrawOpt ep
                  --sumDataHists
                  --autoStack
                  --showOverflow
                  --ratioPaneAtBottom
                  --ratio_Maximum 1.7
                  %s
                  """%("plots/" + plotname + suffix, additional_optstring),
                  v_data_hists, v_bkg_hists )

###################################################################################################
# Plot 1D distribution of Tight and Loose MRs with electroweak part subtracted for both tight and loose region.
#
def draw_ewk_subtr_2d(num_histname, den_histname, plotname, additional_optstring="", include_ttbar=False, rewgthist=None, suffix=""):

    # Get the histograms
    histo_num__data = rebin( tfile_data .Get(num_histname).Clone("Tight Data") , num_histname)
    histo_num__dy   = rebin( tfile_dy   .Get(num_histname).Clone("DYskip") , num_histname)
    histo_num__wj   = rebin( tfile_wj   .Get(num_histname).Clone("Wskip") , num_histname)
    histo_den__data = rebin( tfile_data .Get(den_histname).Clone("Loose Data") , den_histname)
    histo_den__dy   = rebin( tfile_dy   .Get(den_histname).Clone("DYskip") , den_histname)
    histo_den__wj   = rebin( tfile_wj   .Get(den_histname).Clone("Wskip") , den_histname)

    # Do some cosmetics
    histo_num__data .SetDirectory( 0 )
    histo_num__dy   .SetDirectory( 0 )
    histo_num__wj   .SetDirectory( 0 )
    histo_den__data .SetDirectory( 0 )
    histo_den__dy   .SetDirectory( 0 )
    histo_den__wj   .SetDirectory( 0 )
    histo_num__data .SetLineColor( 1 )
    histo_num__data .SetFillColor( r.kGray + 1 )
    histo_den__data .SetLineColor( 1 )
    histo_num__dy.SetFillColor( 7002 )
    histo_num__wj.SetFillColor( 7006 )
    histo_num__dy.SetLineColor( 7002 )
    histo_num__wj.SetLineColor( 7006 )
    histo_den__dy.SetFillColor( 7002 )
    histo_den__wj.SetFillColor( 7006 )
    histo_den__dy.SetLineColor( 7002 )
    histo_den__wj.SetLineColor( 7006 )

    # Rewight histograms (NOTE this was used to study why muon fake rate was rising in pT)
    if rewgthist:
        if rewgthist[0]:
            num_rewgthist = rewgthist[0]
            for ibin in xrange( 0, histo_num__dy.GetNbinsX() + 1 ):
                print ibin + 1, num_rewgthist.GetBinContent( ibin + 1 )
                histo_num__dy.SetBinContent( ibin + 1, histo_num__dy.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )
                histo_num__wj.SetBinContent( ibin + 1, histo_num__wj.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )

        if rewgthist[1]:
            den_rewgthist = rewgthist[1]
            for ibin in xrange( 0, histo_den__dy.GetNbinsX() + 1 ):
                print ibin + 1, den_rewgthist.GetBinContent( ibin + 1 )
                histo_den__dy.SetBinContent( ibin + 1, histo_den__dy.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )
                histo_den__wj.SetBinContent( ibin + 1, histo_den__wj.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )

        if rewgthist[2]:
            flatrewgt = rewgthist[2]
            histo_num__dy.Scale( flatrewgt )
            histo_num__wj.Scale( flatrewgt )

        if rewgthist[3]:
            flatrewgt = rewgthist[3]
            histo_den__dy.Scale( flatrewgt )
            histo_den__wj.Scale( flatrewgt )

    # As the dy/wj will be subtracted, flip the scale
    # the "plotmaker" will then "subtract" by adding a negative histogram
    histo_num__dy.Scale( -1 )
    histo_num__wj.Scale( -1 )
    histo_den__dy.Scale( -1 )
    histo_den__wj.Scale( -1 )

    # The actual variable that will be passed ton plotmaker
    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back( histo_num__data )
    v_bkg_hists.push_back( histo_num__dy )
    v_bkg_hists.push_back( histo_num__wj )
    v_data_hists = r.vector("TH1*")()
    v_data_hists.push_back( histo_den__data )
    v_data_hists.push_back( histo_den__dy )
    v_data_hists.push_back( histo_den__wj )

    # if include ttbar MC option is turned on, add the ttbar MC
    if include_ttbar:
        histo_num__ttbar= rebin( tfile_ttbar.Get(num_histname).Clone("t#bar{t}skip") , num_histname)
        histo_den__ttbar= rebin( tfile_ttbar.Get(den_histname).Clone("t#bar{t}skip") , den_histname)
        histo_num__ttbar.SetDirectory( 0 )
        histo_num__ttbar.SetFillColor( 7004 )
        histo_num__ttbar.SetLineColor( 7004 )
        histo_den__ttbar.SetDirectory( 0 )
        histo_den__ttbar.SetFillColor( 7004 )
        histo_den__ttbar.SetLineColor( 7004 )
        if rewgthist:
            if rewgthist[0]:
                num_rewgthist = rewgthist[0]
                for ibin in xrange( 0, histo_num__dy.GetNbinsX() + 1 ):
                    print ibin + 1, num_rewgthist.GetBinContent( ibin + 1 )
                    histo_num__ttbar.SetBinContent( ibin + 1, histo_num__ttbar.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )

            if rewgthist[1]:
                den_rewgthist = rewgthist[1]
                for ibin in xrange( 0, histo_den__dy.GetNbinsX() + 1 ):
                    print ibin + 1, den_rewgthist.GetBinContent( ibin + 1 )
                    histo_den__ttbar.SetBinContent( ibin + 1, histo_den__ttbar.GetBinContent( ibin + 1 ) * den_rewgthist.GetBinContent( ibin + 1 ) )

            if rewgthist[2]:
                flatrewgt = rewgthist[2]
                histo_num__ttbar.Scale( flatrewgt )

            if rewgthist[3]:
                flatrewgt = rewgthist[3]
                histo_den__ttbar.Scale( flatrewgt )

        histo_num__ttbar.Scale( -1 )
        histo_den__ttbar.Scale( -1 )
        v_bkg_hists.push_back( histo_num__ttbar )
        v_data_hists.push_back( histo_den__ttbar )

    # If the binning is variable add the divideByBinWidth option
    if num_histname.find( "varbin" ):
        additional_optstring += "--divideByBinWidth"

    # make a plot of tight region vs. loose region and the returning ratio TH1 object will be the fake rate itself.
    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle m_{T,#mu} [GeV]
                  --plotOutputName %s
                  --ratio_DrawOpt ep
                  --sumDataHists
                  --autoStack
                  --showOverflow
                  --ratioPaneAtBottom
                  --ratio_Maximum 1.7
                  %s
                  """%("plots/" + plotname + suffix, additional_optstring),
                  v_data_hists, v_bkg_hists )

###################################################################################################
# Plot 1D distribution with QCD MC in Tight and Loose MR.
#
def draw_qcd(num_histname, den_histname, plotname, additional_optstring="", include_ttbar=False, rewgthist=None, suffix=""):

    # If muon stay in this block.
    # FIXME This kinda of if and else statement is a bit clunky.
    if num_histname.find( "_mu" ) != -1:

        histo_num__qcd_mu = rebin( tfile_qcd_mu.Get(num_histname).Clone("Tight QCD") , num_histname)
        histo_den__qcd_mu = rebin( tfile_qcd_mu.Get(den_histname).Clone("Loose QCD") , den_histname)

        histo_den__qcd_mu.SetLineColor( 2 )
        histo_den__qcd_mu.SetMarkerColor( 2 )
        histo_num__qcd_mu.SetLineColor( 1 )
        histo_num__qcd_mu.SetFillColor( 7003 )

        v_bkg_hists = r.vector("TH1*")()
        v_bkg_hists.push_back( histo_num__qcd_mu )
        v_data_hists = r.vector("TH1*")()
        v_data_hists.push_back( histo_den__qcd_mu )

        if num_histname.find( "varbin" ):
            additional_optstring += "--divideByBinWidth"

        return r.plotmaker( """
                      --yTitle N leptons
                      --xTitle m_{T,#mu} [GeV]
                      --plotOutputName %s
                      --ratio_DrawOpt ep
                      --autoStack
                      --ratioPaneAtBottom
                      --showOverflow
                      --ratio_Maximum 1.7
                      %s
                      """%("plots/" + plotname + suffix, additional_optstring),
                      v_data_hists, v_bkg_hists )

    else:
        histo_num__qcd_el = rebin( tfile_qcd_el.Get(num_histname).Clone("Tight QCD") , num_histname)
        histo_den__qcd_el = rebin( tfile_qcd_el.Get(den_histname).Clone("Loose QCD") , den_histname)

        histo_den__qcd_el.SetLineColor( 2 )
        histo_den__qcd_el.SetMarkerColor( 2 )
        histo_num__qcd_el.SetLineColor( 1 )
        histo_num__qcd_el.SetFillColor( 7003 )

        v_bkg_hists = r.vector("TH1*")()
        v_bkg_hists.push_back( histo_num__qcd_el )
        v_data_hists = r.vector("TH1*")()
        v_data_hists.push_back( histo_den__qcd_el )

        if num_histname.find( "varbin" ):
            additional_optstring += "--divideByBinWidth"

        return r.plotmaker( """
                      --yTitle N leptons
                      --xTitle m_{T,#mu} [GeV]
                      --plotOutputName %s
                      --ratio_DrawOpt ep
                      --autoStack
                      --ratioPaneAtBottom
                      --showOverflow
                      --ratio_Maximum 1.7
                      %s
                      """%("plots/" + plotname + suffix, additional_optstring),
                      v_data_hists, v_bkg_hists )


###################################################################################################
# Plot 1D distribution comparing QCD MC and ewk subtracted in Tight and Loose MR.
#
def draw_ewk_v_qcd(histname, plotname, additional_optstring="", include_ttbar=False, rewgthist=None, flatrewgt=1.0, suffix=""):

    histo_num__data = rebin( tfile_data .Get(histname).Clone("Data") , histname)
    histo_num__dy   = rebin( tfile_dy   .Get(histname).Clone("DYskip") , histname)
    histo_num__wj   = rebin( tfile_wj   .Get(histname).Clone("Wskip") , histname)

    histo_num__data .SetDirectory( 0 )
    histo_num__dy   .SetDirectory( 0 )
    histo_num__wj   .SetDirectory( 0 )

    histo_num__data .SetLineColor( 1 )
    histo_num__data .SetFillColor( r.kGray + 1 )

    histo_num__dy.SetFillColor( 7002 )
    histo_num__wj.SetFillColor( 7006 )
    histo_num__dy.SetLineColor( 7002 )
    histo_num__wj.SetLineColor( 7006 )

    if rewgthist:
        num_rewgthist = rewgthist[0]
        for ibin in xrange( 0, histo_num__dy.GetNbinsX() + 1 ):
            histo_num__dy.SetBinContent( ibin + 1, histo_num__dy.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )
            histo_num__wj.SetBinContent( ibin + 1, histo_num__wj.GetBinContent( ibin + 1 ) * num_rewgthist.GetBinContent( ibin + 1 ) )

    histo_num__dy.Scale( -1 * flatrewgt )
    histo_num__wj.Scale( -1 * flatrewgt )

    v_data_hists = r.vector("TH1*")()
    v_data_hists.push_back( histo_num__data )
    v_data_hists.push_back( histo_num__dy )
    v_data_hists.push_back( histo_num__wj )

    histo_den__qcd_mu = tfile_qcd_mu.Get(histname).Clone("QCD")

    histo_den__qcd_mu .SetLineColor( 1 )
    histo_den__qcd_mu .SetFillColor( r.kGray + 1 )

    v_bkg_hists = r.vector("TH1*")()
    v_bkg_hists.push_back( histo_den__qcd_mu )

    if histname.find( "varbin" ):
        additional_optstring += "--divideByBinWidth"

    return r.plotmaker( """
                  --yTitle N leptons
                  --xTitle m_{T,#mu} [GeV]
                  --plotOutputName %s
                  --ratio_DrawOpt ep
                  --sumDataHists
                  --showOverflow
                  --autoStack
                  --ratioPaneAtBottom
                  --ratio_Maximum 1.7
                  %s
                  """%("plots/" + plotname + suffix, additional_optstring),
                  v_data_hists, v_bkg_hists )

import sys




def run_fakerate(var, lepflav, dottbar, magicsf, runlabel):

    #
    # Muon
    #

    if lepflav == "mu":
        nicename = "#mu"
    elif lepflav =="el":
        nicename = "e"


    # Drawing 1D distributions
    print "here"
#    print draw     ( "histo_mt_ewk_cr_"+lepflav            , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] --xNbin 1 """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    print draw     ( "histo_nvtxrewgt_mt_ewk_cr_"+lepflav            , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] --xNbin 1 """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    draw           ( "histo_mt_cr_"+lepflav                , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV]           """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    draw           ( "histo_nvtxrewgt_mt_cr_"+lepflav      , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV]           """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    draw           ( "histo_nvtxrewgt_mt_cr_"+lepflav      , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV]           """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    flat_sf  = draw( "histo_"+var+"_ewk_cr_"+lepflav       , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] --xNbin 1 """%nicename  , dottbar ,   False , None  , "")[0].GetBinContent(1)
#    tight_sf = draw( "histo_nvtxrewgt_"+var+"_ewk_cr_"+lepflav       , """ --ratio_Maximum 1.5 --ratio_Minimum 0.7 --xTitle p_{T,%s} [GeV] """%nicename            , dottbar ,   False , None  , "")
#    loose_sf = draw( "histo_"+var+"_loose_ewk_cr_"+lepflav , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] """%nicename            , dottbar ,   False , None  , "")
    draw           ( "histo_"+var+"_meas_"+lepflav         , """ --Maximum 30000 --reverseRatio --xTitle p_{T,%s} [GeV] """%nicename , dottbar ,   False , None  , "")
    draw           ( "histo_"+var+"_loose_meas_"+lepflav   , """ --Maximum 30000 --reverseRatio --xTitle p_{T,%s} [GeV] """%nicename , dottbar ,   False , None  , "")
#    draw           ( "histo_"+var+"_meas_"+lepflav         , """ --Maximum 30000 --reverseRatio --xTitle p_{T,%s} [GeV] """%nicename , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_"+var+"_loose_meas_"+lepflav   , """ --Maximum 30000 --reverseRatio --xTitle p_{T,%s} [GeV] --printData --printTotalBkg """%nicename , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_"+var+"_ewk_cr_"+lepflav       , """ --ratio_Maximum 1.5 --ratio_Minimum 0.7 --xTitle p_{T,%s} [GeV] """%nicename            , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_mt_highpt_"+lepflav            , """ --ratio_Maximum 1.9 --xTitle m_{T,%s} [GeV] """%nicename            , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt_"+lepflav              , """ --ratio_Maximum 1.9 --xTitle MET [GeV] """                          , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_"+var+"_hmt_"+lepflav          , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] """%nicename            , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_pt_hmt_"+lepflav               , """ --ratio_Maximum 1.9 --xTitle p_{T,%s} [GeV] """%nicename            , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_highpt_"+lepflav           , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_medpt_"+lepflav            , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_highpt50_"+lepflav         , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    print "NVTX BEGIN"
#    draw           ( "histo_nvtx_highpt50_"+lepflav        , """ --ratio_Maximum 1.9 --xTitle N_{Vtx}           """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    print "NVTX END"
#    draw           ( "histo_nvtxrewgt_nvtx_highpt_"+lepflav        , """ --ratio_Maximum 1.9 --xTitle N_{Vtx}           """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_nvtx_highpt50_"+lepflav        , """ --ratio_Maximum 1.9 --xTitle N_{Vtx}           """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_met_highpt50_"+lepflav        , """ --ratio_Maximum 1.2 --ratio_Minimum 0.8 --xTitle MET [GeV]         """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_mt_highpt50_"+lepflav        , """ --ratio_Maximum 1.2 --ratio_Minimum 0.8 --xTitle MET [GeV]         """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_nvtx_loose_highpt50_"+lepflav        , """ --ratio_Maximum 1.9 --xTitle N_{Vtx}           """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_met_loose_highpt50_"+lepflav        , """ --ratio_Maximum 1.2 --ratio_Minimum 0.8 --xTitle MET [GeV]         """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_mt_loose_highpt50_"+lepflav        , """ --ratio_Maximum 1.2 --ratio_Minimum 0.8 --xTitle MET [GeV]         """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_nvtxrewgt_mt_cr_"+lepflav        , """ --ratio_Maximum 1.2 --ratio_Minimum 0.8 --xTitle MET [GeV]         """                  , dottbar , dottbar , None  , "_wqcd")[0].Print("all")
#    draw           ( "histo_met_hmt80pt50_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt70pt50_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt50pt50_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt80pt30_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt70pt30_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")
#    draw           ( "histo_met_hmt50pt30_"+lepflav        , """ --ratio_Minimum 0.7 --ratio_Maximum 1.3 --xTitle MET [GeV] """      , dottbar , dottbar , None  , "_wqcd")

    # Compute fake rate in pt
    fakerate_pt_data = draw_ewk_subtr( "histo_"+var+"_meas_"+lepflav+"" , "histo_"+var+"_loose_meas_"+lepflav+"" , "histo_"+var+"_fakerate_data_"+lepflav+"" ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --MaximumMultiplier 3.0 --xTitle p_{T,%s} [GeV] """%nicename ,
            dottbar , [None, None, magicsf, magicsf] )
    fakerate_pt_data_qcd = draw_qcd( "histo_"+var+"_meas_"+lepflav+""   , "histo_"+var+"_loose_meas_"+lepflav+"" , "histo_"+var+"_fakerate_qcd_"+lepflav+""  ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --xTitle p_{T,%s} [GeV] --MaximumMultiplier 3.0 """%nicename ,
            dottbar )

    fakerate_pt_data[0].SetName( "EWK Subtr. Data" )
    fakerate_pt_data[0].SetLineColor( 1 )
    fakerate_pt_data[0].SetMarkerColor( 1 )
    fakerate_pt_data_qcd[0].SetName( "QCD MC" )
    fakerate_pt_data_qcd[0].SetLineColor( 2 )
    fakerate_pt_data_qcd[0].SetMarkerColor( 2 )

    # Compute fake rate in pt
    fakerate_pt_data = draw_ewk_subtr( "histo_ptvarbin_meas_"+lepflav+"" , "histo_ptvarbin_loose_meas_"+lepflav+"" , "histo_ptvarbin_fakerate_data_"+lepflav+"" ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --MaximumMultiplier 3.0 --xTitle p_{T,%s} [GeV] """%nicename ,
            dottbar , [None, None, magicsf, magicsf] )
    fakerate_pt_data_qcd = draw_qcd( "histo_ptvarbin_meas_"+lepflav+""   , "histo_ptvarbin_loose_meas_"+lepflav+"" , "histo_ptvarbin_fakerate_qcd_"+lepflav+""  ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --xTitle p_{T,%s} [GeV] --MaximumMultiplier 3.0 """%nicename ,
            dottbar )

    # Compute fake rate in pt
#    fakerate_pt_data = draw_ewk_subtr( "histo_nvtxrewgt_ptvarbin_meas_"+lepflav+"" , "histo_nvtxrewgt_ptvarbin_loose_meas_"+lepflav+"" , "histo_ptvarbin_fakerate_data_"+lepflav+"" ,
#            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --MaximumMultiplier 3.0 --xTitle p_{T,%s} [GeV] """%nicename ,
#            dottbar , [None, None, magicsf, magicsf] )
#            #dottbar , [None, None, magicsf, magicsf] )
#    fakerate_pt_data_qcd = draw_qcd( "histo_nvtxrewgt_ptvarbin_meas_"+lepflav+""   , "histo_nvtxrewgt_ptvarbin_loose_meas_"+lepflav+"" , "histo_ptvarbin_fakerate_qcd_"+lepflav+""  ,
#            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --xTitle p_{T,%s} [GeV] --MaximumMultiplier 3.0 """%nicename ,
#            dottbar )

    fakerate_pt_data[0].SetName( "EWK Subtr. Data" )
    fakerate_pt_data[0].SetLineColor( 1 )
    fakerate_pt_data[0].SetMarkerColor( 1 )
    fakerate_pt_data_qcd[0].SetName( "QCD MC" )
    fakerate_pt_data_qcd[0].SetLineColor( 2 )
    fakerate_pt_data_qcd[0].SetMarkerColor( 2 )

    # Compute fake rate in eta
    fakerate_eta_data = draw_ewk_subtr( "histo_etavarbin_meas_"+lepflav+"" , "histo_etavarbin_loose_meas_"+lepflav+"" , "histo_etavarbin_fakerate_data_"+lepflav+"" ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --MaximumMultiplier 3.0 --xTitle p_{T,%s} [GeV] """%nicename ,
            dottbar , [tight_sf[0], tight_sf[0], magicsf, magicsf] )
            #dottbar , [None, None, magicsf, magicsf] )
    fakerate_eta_data_qcd = draw_qcd( "histo_etavarbin_meas_"+lepflav+""   , "histo_etavarbin_loose_meas_"+lepflav+"" , "histo_etavarbin_fakerate_qcd_"+lepflav+""  ,
            """ --Minimum 1 --Maximum 20000000 --ratio_yTitle Fake Rate --reverseRatio --ratio_Minimum 0.0 --ratio_Maximum 0.7 --xTitle p_{T,%s} [GeV] --MaximumMultiplier 3.0 """%nicename ,
            dottbar )

    fakerate_eta_data[0].SetName( "EWK Subtr. Data" )
    fakerate_eta_data[0].SetLineColor( 1 )
    fakerate_eta_data[0].SetMarkerColor( 1 )
    fakerate_eta_data_qcd[0].SetName( "QCD MC" )
    fakerate_eta_data_qcd[0].SetLineColor( 2 )
    fakerate_eta_data_qcd[0].SetMarkerColor( 2 )

    # Compute the ratio
    finalratio = []
    finalratio.append( r.plotmaker(
            """ --ratioPaneAtBottom --legend_bkgDrawOpt e2p --ratio_DrawOpt ep --data_DrawOpt ep --ratio_Maximum 2.1 --Maximum 0.7
                --stack_DrawOpt ep --yTitle Fake rate --xTitle p_{T,%s} [GeV] --plotOutputName plots/fakerate_pt_%s_%s """%(nicename, lepflav, runlabel),
            fakerate_pt_data[0], fakerate_pt_data_qcd[0])[0].Print("all") )

    finalratio.append( r.plotmaker(
            """ --ratioPaneAtBottom --legend_bkgDrawOpt e2p --ratio_DrawOpt ep --data_DrawOpt ep --ratio_Maximum 1.1 --Maximum 0.7
                --stack_DrawOpt ep --yTitle Fake rate --xTitle p_{T,%s} [GeV] --plotOutputName plots/fakerate_eta_%s_%s """%(nicename, lepflav, runlabel),
            fakerate_eta_data[0], fakerate_eta_data_qcd[0])[0].Print("all") )

    return finalratio

#run_fakerate( "ptvarbin", "mu", True )
nominal_result = run_fakerate( "ptvarbin", "mu", True, 1.00, "nominal" )
#nominal_result = run_fakerate( "ptvarbin", "mu", True, 1.10, "syst" )
#nominal_result = run_fakerate( "ptvarbin", "el", True, 1.06, "nominal" )
#syst_result    = run_fakerate( "ptvarbin", "mu", False, True, 1.00, "syst" )

sys.exit()
