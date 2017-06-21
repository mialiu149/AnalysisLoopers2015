
#thedir='/home/users/haweber/StopAnalysis/CombineCode/datacards/fakedata/dataisbgsig/'
thedir='datacards/newsignal/'
fakedata=true
dataisbg=true

#version=$1
signal=$1

maxversions=17

for v in `seq 1 ${maxversions}`;
do
    version=`echo v${v}`
    maxbins=0
    if [ "$v" -eq 1 ]; then
	maxbins=8
    elif [ "$v" -eq 2 ]; then
	maxbins=8
    elif [ "$v" -eq 3 ]; then
	maxbins=8
    elif [ "$v" -eq 4 ]; then
	maxbins=8
    elif [ "$v" -eq 5 ]; then
	maxbins=6
    elif [ "$v" -eq 6 ]; then
	maxbins=8
    elif [ "$v" -eq 7 ]; then
	maxbins=8
    elif [ "$v" -eq 8 ]; then
	maxbins=7
    elif [ "$v" -eq 9 ]; then
	maxbins=7
    elif [ "$v" -eq 10 ]; then
	maxbins=8
    elif [ "$v" -eq 11 ]; then
	maxbins=6
    elif [ "$v" -eq 12 ]; then
	maxbins=8
    elif [ "$v" -eq 13 ]; then
	maxbins=6
    elif [ "$v" -eq 14 ]; then
	maxbins=8
    elif [ "$v" -eq 15 ]; then
	maxbins=5
    elif [ "$v" -eq 16 ]; then
	maxbins=9
    elif [ "$v" -eq 17 ]; then
	maxbins=11
    fi
    echo Number of bins is ${maxbins}.
    combinedir=`echo ${thedir}`
    verdir=`echo ${thedir}${version}/`

    Name=$signal
    #echo ${Name}

    combinestring=combineCards.py
    #for i in {1..9}
    for i in `seq 1 ${maxbins}`;
    do
	#echo $i
	combinestring=`echo ${combinestring} ch${i}=${verdir}Signal_${Name}_b${i}.txt`
	#echo ${combinestring}
    done

    eval ${combinestring} > ${combinedir}/${version}_combined_${Name}.txt
    #echo ${combinestring}
    echo Combined cards for ${Name} into ${combinedir}/${version}_combined_${Name}.txt
done
