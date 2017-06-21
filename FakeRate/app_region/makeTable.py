import math
import sys
# import tableMaker as tm

# ONE LINER to generate tables
# python makeTable.py | python ~/Software/slideMaker/tableMaker.py | pdflatex ; pdfcrop texput.pdf brcounts.pdf ; web brcounts.pdf

def getTotal(countErr):
    ctot, etot = 0.0, 0.0
    for c, e in countErr:
        ctot += c
        etot += e**2.0
    etot = etot**0.5
    return ctot, etot

fh = open("content.txt","r")
content = fh.read()
fh.close()

types = ["el", "mu", "tot"]
if(len(sys.argv) > 1):
    types = [sys.argv[-1]]
for t in types:
    dObs = {}
    dPred = {}

    for line in content.split("\n"):
        if(len(line)) < 5: continue

        tag, count, err = line.split()
        count, err = float(count), float(err)
        sample, obspred, elmu, br = tag.split("_")

        if(t == "el"):
            if("el" not in elmu): continue
        elif(t == "mu"):
            if("mu" not in elmu): continue
        elif(t == "tot"):
            pass

        if(obspred == "pred"):
            if(br in dPred):
                dPred[br][0] += count
                oldErr = dPred[br][1]
                dPred[br][1] = (err**2.0+oldErr**2.0)**0.5
            else:
                dPred[br] = [count, err]

        elif(obspred == "obs"):
            if br not in dObs: dObs[br] = {}

            if(sample in dObs[br]):
                dObs[br][sample][0] += count
                oldErr = dObs[br][sample][1]
                dObs[br][sample][1] = (err**2.0+oldErr**2.0)**0.5
            else:
                dObs[br][sample] = [count, err]

    allSamples = list(set(sum([dObs[k].keys() for k in dObs.keys()],[])))

    if("el" in t):
        print "mrc 1 5 \\textbf{el} | | | |"
    elif("mu" in t):
        if len(types) > 1: print ""
        print "mrc 1 5 \\textbf{mu} | | | |"
    elif("tot" in t):
        if len(types) > 1: print ""
        print "mrc 1 5 \\textbf{el+mu} | | | |"

    print " | BR0 | BR1 | BR2 | BR3"
    for s in allSamples:
        br0 = dObs["BR0"].get(s, [0.0,0.0])
        br1 = dObs["BR1"].get(s, [0.0,0.0])
        br2 = dObs["BR2"].get(s, [0.0,0.0])
        br3 = dObs["BR3"].get(s, [0.0,0.0])
        tup = (s, br0[0], br0[1],
                  br1[0], br1[1],
                  br2[0], br2[1],
                  br3[0], br3[1] )
        print "%s | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f" % tup

    tup = ( getTotal(dObs["BR0"].values())[0],
            getTotal(dObs["BR0"].values())[1],
            getTotal(dObs["BR1"].values())[0],
            getTotal(dObs["BR1"].values())[1],
            getTotal(dObs["BR2"].values())[0],
            getTotal(dObs["BR2"].values())[1],
            getTotal(dObs["BR3"].values())[0],
            getTotal(dObs["BR3"].values())[1] )
    print "\\textbf{Total obs} | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f" % tup

    tup = ( dPred["BR0"][0],
            dPred["BR0"][1],
            dPred["BR1"][0],
            dPred["BR1"][1],
            dPred["BR2"][0],
            dPred["BR2"][1],
            dPred["BR3"][0],
            dPred["BR3"][1] )
    print "\\textbf{Total pred (data)} | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f | %.2f $\\pm$ %.2f" % tup

