#!/bin/bash

if $(type root &> /dev/null); then
    :
else
    echo "Setting up ROOT"
    export SCRAM_ARCH=slc6_amd64_gcc491   # or whatever scram_arch you need for your desired CMSSW release
    export CMSSW_VERSION=CMSSW_7_4_2
    source /cvmfs/cms.cern.ch/cmsset_default.sh
    cd /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/cmssw/$CMSSW_VERSION/src
    eval `scramv1 runtime -sh`
    cd -
fi

echo 'which root'
which root

compute_prescale()
{
    python ~/ditto/python/makeplot.py \
        --datahist 'outputs/fakerate_data.root:::mll_'$1':::SetMarkerStyle=>19,SetLineColor=>1   ,SetName=>data%ep,Scale=>1' \
        --bkghist  'outputs/fakerate_dy.root  :::mll_'$1':::SetFillColor=>7002,SetLineColor=>7002,SetName=>DY%f,Scale=>1' \
        --nbinx 1 \
        --plottype plot1d \
        --plotname plots/plot_zpeak_before_prescaled_$1 \
        --ratio_maximum 1.7 \
        --ratio_minimum 0.3

    YIELDS=$(python ~/ditto/python/makeplot.py \
        --datahist 'outputs/fakerate_data.root:::mll_'$1':::SetMarkerStyle=>19,SetLineColor=>1   ,SetName=>data%ep,Scale=>1' \
        --bkghist  'outputs/fakerate_dy.root  :::mll_'$1':::SetFillColor=>7002,SetLineColor=>7002,SetName=>DY%f,Scale=>1' \
        --nbinx 1 \
        --plottype plot1d \
        --plotname plots/plot_zpeak_before_prescaled_$1 \
        --ratio_maximum 1.7 \
        --ratio_minimum 0.3 | grep 'yield')
    python ~/ditto/python/makeplot.py \
        --datahist 'outputs/fakerate_data.root:::mll_'$1':::SetMarkerStyle=>19,SetLineColor=>1   ,SetName=>data%ep,Scale=>1' \
        --bkghist  'outputs/fakerate_dy.root  :::mll_'$1':::SetFillColor=>7002,SetLineColor=>7002,SetName=>DY%f,Scale=>1' \
        --plottype plot1d \
        --plotname plots/plot_zpeak_before_prescaled_$1 \
        --ratio_maximum 1.7 \
        --ratio_minimum 0.3 | grep 'yield'
    TOKENS=($YIELDS)
    BKGYIELD=${TOKENS[2]}
    DATAYIELD=${TOKENS[5]}
    echo "For trigger: $1 bkg  yields" $BKGYIELD
    echo "For trigger: $1 data yields" $DATAYIELD
    PRESCALE=$(echo "$BKGYIELD / $DATAYIELD" | bc)
    python ~/ditto/python/makeplot.py \
        --datahist 'outputs/fakerate_data.root:::mll_'$1':::SetMarkerStyle=>19,SetLineColor=>1   ,SetName=>data%ep,Scale=>'${PRESCALE} \
        --bkghist  'outputs/fakerate_dy.root  :::mll_'$1':::SetFillColor=>7002,SetLineColor=>7002,SetName=>DY%f,Scale=>1' \
        --plottype plot1d \
        --plotname plots/plot_zpeak_prescaled_$1 \
        --ratio_maximum 1.7 \
        --ratio_minimum 0.3 | grep 'yield'
}

compute_prescale m8i
compute_prescale m17i
compute_prescale e8i
compute_prescale e17i
