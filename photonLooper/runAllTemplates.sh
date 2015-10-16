#! /bin/bash

function make_gtemplates
{
	selection_region=$1
	echo "running photonLooper."
	root -b -q "runPhotonLooper.cc( \"$selection_region\")"
}


# compile photonLooper
echo "Compiling photonLooper."
make -j5
if [ ! "$?" -eq "0" ]; then
	echo "photonLooper did not compile, exiting."
	exit
fi

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# SR + CRS
selection="_inclusive"
make_gtemplates $selection

# selection="_2btag_mjjlo_mt2jhi_inclusive_medium"
# make_gtemplates $selection &
# selection="_2btag_mjjhi_mt2jhi_inclusive_medium"
# make_gtemplates $selection &
# selection="_2btag_mjjlo_mt2jlo_inclusive_medium"
# make_gtemplates $selection &
# selection="_2btag_mjjhi_mt2jlo_inclusive_medium"
# make_gtemplates $selection &

# selection="_bveto_mjjhi_mt2jhi_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_mjjlo_mt2jhi_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_mjjhi_mt2jlo_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_mjjlo_mt2jlo_inclusive_medium"
# make_gtemplates $selection &

# # for OF Efficiency
# selection="_2btag_mt2jlo_inclusive"
# make_gtemplates $selection &
# selection="_2btag_mt2jhi_inclusive"
# make_gtemplates $selection &

# selection="_bveto_mt2jlo_inclusive"
# make_gtemplates $selection &
# selection="_bveto_mt2jhi_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mt2jlo_inclusive_medium"
# make_gtemplates $selection &
# selection="_2btag_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_bveto_mt2jlo_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_2btag_mjjlo_mt2jlo_inclusive_medium"
# make_gtemplates $selection &

# selection="_2btag_mjjlo_mt2jhi_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mjjlo_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jhi_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_bveto_mjjhi_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_bveto_mjjlo_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jlo_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jlo_inclusive_medium"
# make_gtemplates $selection &


# selection="_2btag_mt2jhi_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mt2jhi_inclusive_medium"
# make_gtemplates $selection &

# selection="_2btag_mt2jlo_inclusive"
# make_gtemplates $selection &

# selection="_2btag_mt2jlo_inclusive_medium"
# make_gtemplates $selection &


# selection="_bveto_mjjhi_mt2jhi"
# make_gtemplates $selection &

# selection="_bveto_mjjhi_mt2jlo"
# make_gtemplates $selection &

# selection="_bveto_mjjlo_mt2jlo"
# make_gtemplates $selection &

# selection="_bveto_mjjlo_mt2jhi"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jhi"
# make_gtemplates $selection &

# selection="_2btag_mjjhi_mt2jlo"
# make_gtemplates $selection &

# # Signal Region
# selection="_2btag_mjjlo_mt2jhi"
# make_gtemplates $selection &

# selection="_2btag_mjjlo_mt2jlo"
# make_gtemplates $selection &

# selection="_2btag_mt2jhi"
# make_gtemplates $selection &

# selection="_2btag_mt2jlo"
# make_gtemplates $selection &

# selection="_bveto_mt2jhi"
# make_gtemplates $selection &

# selection="_bveto_mt2jlo"
# make_gtemplates $selection &

# selection="_bveto"
# make_gtemplates $selection &

# selection="_2btag"
# make_gtemplates $selection &

# selection="_2btag_0genbs"
# make_gtemplates $selection &

# selection="_2btag_1genbs"
# make_gtemplates $selection &

# selection="_2btag_2genbs"
# make_gtemplates $selection &

