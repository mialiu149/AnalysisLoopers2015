
ls new2fbinvv*.txt > myfilelist
nLines=`wc -l < myfilelist`

echo Number of limits $nLines

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
    combine -M ProfileLikelihood --significance ${temp} -t -1 --expectSignal=1
    echo This was the significance for ${temp}
    
done

rm myfilelist
