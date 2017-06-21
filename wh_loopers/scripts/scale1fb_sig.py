
#dictionary for signals
signals = [{'mass':225,'xsec': 1165.09,'branch':0.58*0.3,'NEvents':35004},
           {'mass':250,'xsec': 782.487,'branch':0.58*0.3,'NEvents':27361},
           {'mass':300,'xsec': 386.936,'branch':0.58*0.3,'NEvents':32674},
           {'mass':350,'xsec': 209.439,'branch':0.58*0.3,'NEvents':28404}]

for signal in signals:
    scale1fb = signal['xsec']*signal['branch']/signal['NEvents']
    print str(signal['mass']) + ' : ' +str(scale1fb)
