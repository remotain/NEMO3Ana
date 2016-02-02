#!/usr/bin/python

from array import *
import matplotlib.pyplot as plt
import numpy as np


from ROOT import *

path = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie/"

files_En = {
    "MM"    : "CollieLC_En_MM_DEF",
    "RHC_L" : "CollieLC_En_RHC_L_DEF",
    "RHC_E" : "CollieLC_En_RHC_E_DEF",
    "M1"    : "CollieLC_En_M1_DEF"
}

files_BDT = {
    "MM"    : "CollieLC_BDT_MM_DEF",
    "RHC_L" : "CollieLC_BDT_RHC_L_DEF",
    "RHC_E" : "CollieLC_BDT_RHC_E_DEF",
    "M1"    : "CollieLC_BDT_M1_DEF"    
}

path_scan = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie/"

files_En_scan = {
    "030" : "CollieLC_En_MM_DEF",    
    "100" : "CollieLC_En_MM_100",
    "150" : "CollieLC_En_MM_150",
    "200" : "CollieLC_En_MM_200",
    "250" : "CollieLC_En_MM_250"   
}

files_BDT_scan = {
    -0.40 : "CollieLC_BDT_MM",
    -0.20 : "CollieLC_BDT_MM_-020",
    -0.10 : "CollieLC_BDT_MM_-010",    
    0.    : "CollieLC_BDT_MM_000",
    0.10  : "CollieLC_BDT_MM_010",
    0.20  : "CollieLC_BDT_MM_020"
}


###############################################################################
#
# Normalisation @ 90 % C.L.
#
###############################################################################

print "{0:6s}".format("Model"), "|" , "{0:10s}".format("N Obs."), "|", "{0:10s}".format("-1 sigma"), "|",  "{0:10s}".format("N Exp."), "|",  "{0:10s}".format("+1 sigma")

print "\n E sum \n"

for key in files_En:
    
    f  = TFile.Open( path + files_En[key]          + ".root", "READ")
    fp = TFile.Open( path + files_En[key] + "_p1s" + ".root", "READ")
    fm = TFile.Open( path + files_En[key] + "_m1s" + ".root", "READ")        
    
    t  = f.Get("SCAN")
    tp = fp.Get("SCAN")
    tm = fm.Get("SCAN")        
    
    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)
    
    print "{0:6}".format(key), "|" , "{0:10.1f}".format(t.xsec_obsfactor), "|" , "{0:10.1f}".format(tm.xsec_medfactor), "|",  "{0:10.1f}".format(t.xsec_medfactor), "|",  "{0:10.1f}".format(tp.xsec_medfactor)
    
    f.Close()
    
print "\n BDT \n"    
    
for key in files_En:
    
    f  = TFile.Open( path + files_BDT[key]          + ".root", "READ")
    fp = TFile.Open( path + files_BDT[key] + "_p1s" + ".root", "READ")
    fm = TFile.Open( path + files_BDT[key] + "_m1s" + ".root", "READ")        
    
    t  = f.Get("SCAN")
    tp = fp.Get("SCAN")
    tm = fm.Get("SCAN")        
    
    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)
    
    print "{0:6}".format(key), "|" , "{0:10.1f}".format(t.xsec_obsfactor), "|" , "{0:10.1f}".format(tm.xsec_medfactor), "|",  "{0:10.1f}".format(t.xsec_medfactor), "|",  "{0:10.1f}".format(tp.xsec_medfactor)
    
    f.Close()

###############################################################################
#
# Sensitivity Scan ENERGY
#
###############################################################################
print "\n"
print "{0:6s}".format("Cut value"), "|", "{0:10s}".format("-1 sigma"), "|",  "{0:10s}".format("N Exp."), "|",  "{0:10s}".format("+1 sigma")

print "\n E sum \n"

x    = array('d')
y    = array('d')
emin = array('d')
emax = array('d')

for key in files_En_scan:
    
    f  = TFile.Open( path_scan + files_En_scan[key] + ".root", "READ")
    fp = TFile.Open( path_scan + files_En_scan[key] + "_p1s" + ".root", "READ")
    fm = TFile.Open( path_scan + files_En_scan[key] + "_m1s" + ".root", "READ")        
  
    if not f:
        continue
    if not fp:
        continue
    if not fm:
        continue
  
  
    t  = f.Get("SCAN")
    tp = fp.Get("SCAN")
    tm = fm.Get("SCAN")        
    
    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)

    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)
    
    print "{0:6}".format(key), "|" , "{0:10.1f}".format(tm.xsec_medfactor), "|",  "{0:10.1f}".format(t.xsec_medfactor), "|",  "{0:10.1f}".format(tp.xsec_medfactor)

    x.append(float(key)/100.)
    y.append(t.xsec_medfactor)
    emin.append(abs(t.xsec_medfactor-tm.xsec_medfactor))
    emax.append(abs(t.xsec_medfactor-tp.xsec_medfactor))
        
    f.Close()

err = np.array([emin, emax])
plt.errorbar(x,y,err, None, xlolims=True, marker='s', linewidth=0, elinewidth=1)
plt.axis([0,3.0,min(y)*0.5,max(y)*1.5])
plt.xlabel("Low Energy cut [MeV]")
plt.ylabel("No.Events (Sensitivity @ 90% C.L.)")
plt.grid(axis='x')
plt.grid(axis='y')
plt.show()

###############################################################################
#
# Sensitivity Scan BDT
#
###############################################################################
print "\n"
print "{0:6s}".format("Cut value"), "|", "{0:10s}".format("-1 sigma"), "|",  "{0:10s}".format("N Exp."), "|",  "{0:10s}".format("+1 sigma")

print "\n E sum \n"

x    = array('d')
y    = array('d')
emin = array('d')
emax = array('d')

for key in files_BDT_scan:
    
    f  = TFile.Open( path_scan + files_BDT_scan[key] + ".root", "READ")
    fp = TFile.Open( path_scan + files_BDT_scan[key] + "_p1s" + ".root", "READ")
    fm = TFile.Open( path_scan + files_BDT_scan[key] + "_m1s" + ".root", "READ")        
  
    if not f:
        continue
    if not fp:
        continue
    if not fm:
        continue
  
  
    t  = f.Get("SCAN")
    tp = fp.Get("SCAN")
    tm = fm.Get("SCAN")        
    
    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)

    t.GetEntry(0)
    tp.GetEntry(0)
    tm.GetEntry(0)
    
    print "{0:6.2f}".format(key), "|" , "{0:10.1f}".format(tm.xsec_medfactor), "|",  "{0:10.1f}".format(t.xsec_medfactor), "|",  "{0:10.1f}".format(tp.xsec_medfactor)

    x.append(key)
    y.append(t.xsec_medfactor)
    emin.append(abs(t.xsec_medfactor-tm.xsec_medfactor))
    emax.append(abs(t.xsec_medfactor-tp.xsec_medfactor))
        
    f.Close()

err = np.array([emin, emax])
plt.errorbar(x,y,err, None, xlolims=True, marker='s', linewidth=0, elinewidth=1)
plt.axis([-0.5,0.3,min(y)*0.5,max(y)*1.5])
plt.xlabel("BDT Score")
plt.ylabel("No.Events (Sensitivity @ 90% C.L.)")
plt.grid(axis='x')
plt.grid(axis='y')
plt.show()

