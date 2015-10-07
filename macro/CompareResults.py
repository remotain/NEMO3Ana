#!/usr/bin/python
import argparse
from array import *
from ROOT import *

n = 4

names = ("This work", "Zac/Benton", "Solotvina", "NEMO-2")

t    = array('d', [2.75, 2.88, 2.9, 3.75]  )
y    = array('d', [0, 1, 2, 3]  )
ey   = array('d', [0.05, 0.05, 0.05, 0.05]  )
zero = array('d', [0.0, 0.0, 0.0, 0]  )
stat = array('d', [0.06, 0.04, 0.06, 0.35] )
syst_low = array('d', [-0.17, -0.16, -0.38, -0.21] )
syst_up  = array('d', [+0.16, +0.16, +0.40, +0.21] )

stat_syst_low = list()
stat_syst_up = list()
stat_syst = list()

for i in range(n):
    
    stat_syst_low.append( sqrt(stat[i]*stat[i] + syst_low[i]*syst_low[i]) )
    stat_syst_up.append( sqrt(stat[i]*stat[i] + syst_up[i]*syst_up[i]) )

stat_syst.append(stat_syst_low)
stat_syst.append(stat_syst_up)

#print stat_syst

import matplotlib.pyplot as plt
import numpy as np

plt.errorbar(t,y,None,stat_syst, xlolims=True, marker='s', linewidth=0, elinewidth=10 ,ecolor='green')

plt.errorbar(t,y,None,stat,marker='s', linewidth=0, elinewidth=2, ecolor='black',mfc='black')

plt.yticks( np.arange(4), names )

plt.axis([2.42,4.2,-1,4])

plt.xlabel(r'$^{116}$Cd 2$\nu\beta\beta$ half-life [$\times 10^{19}$ y]')

plt.grid(axis='x')

plt.show()