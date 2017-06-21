
ls v*.txt > myfilelist
nLines=`wc -l < myfilelist`

echo Number of limits $nLines

declare -i ntoys=-1
methodcmd="--toysFreq"
methodname="Posteriori"
if [ "${priori}" = true ]
then
    methodcmd=" "
    methodname="Priori"
fi

#run all samples
for (( i = 1; i <= $nLines; i++ ))
do
    temp=`awk "NR==$i" myfilelist` #this is the datacard I have
    echo Get significance for ${temp}
    combine -M ProfileLikelihood --significance ${temp} -t ${ntoys} --expectSignal=1
    
done

rm myfilelist
