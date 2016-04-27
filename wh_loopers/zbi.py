from ROOT import TMath
import math
def zbi(sig,bg,bgrelunc):
    bgunc = bgrelunc*bg
    tau = bg/pow(bgunc,2);#bgunc is absolute
    n_on = sig+bg
    n_off = tau*bg
    P_Bi = TMath.BetaIncomplete(1./(1.+tau),n_on,n_off+1)
    Z_Bi = math.sqrt(2.)*TMath.ErfInverse(1.-2.*P_Bi)
    return Z_Bi

