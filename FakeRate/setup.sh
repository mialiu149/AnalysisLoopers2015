#! /bin/bash

tag="V00-00-07"
direxample="fake_rate_output"
pdfsdir="measurement_region/pdfs/"

if [ ! -d $direxample ]; then
	echo "directory $direxample does not exist, creating link to /nfs-7/userdata/$USER/$direxample/$tag."
	mkdir -p /nfs-7/userdata/$USER/$direxample/$tag
	ln -s /nfs-7/userdata/$USER/$direxample/
else
	echo "directory $direxample already exists."		
fi

if [ ! -d $pdfsdir ]; then
	echo "directory $pdfsdir does not exist, creating it"
	mkdir -p $pdfsdir
fi

