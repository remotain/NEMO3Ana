#!/usr/bin/python
import argparse
from array import *
import matplotlib.pyplot as plt
import numpy as np

names    =      (      r'This work', r'Zac/Benton', r'CdWO$_{4}$' , r'Solotvina', r'NEMO-2' , r'ELEGANT-V'   )

y        = array('d', [0          , 1           , 2          , 3          , 4        , 5           ] )
t        = array('d', [2.74       , 2.88        , 2.8        , 2.9        , 2.9      , 2.6         ] )
t0nu     = array('d', [1.1        , 1.3         , 1.0        , 1.7        , 0.005    , 0.003       ] )
stat     = array('d', [0.04       , 0.04        , 0.05       , 0.06       , 0.3      , 0.0         ] )
syst_low = array('d', [-0.18      , -0.16       , -0.4       , -0.38      , -0.2     , -0.5        ] )
syst_up  = array('d', [+0.18      , +0.16       , +-0.4      , +0.40      , +0.2     , +0.9        ] )
color    =      [      'orange'   , 'green'     , 'green'    , 'green'    , 'green'  , 'green'       ]

stat_syst_low = list()
stat_syst_up = list()

n = len(names)

for i in range(n):
    
    stat_syst_low.append( np.sqrt(stat[i]*stat[i] + syst_low[i]*syst_low[i]) )
    stat_syst_up.append( np.sqrt(stat[i]*stat[i] + syst_up[i]*syst_up[i]) )

    if i == 0:
        stat_syst_0 = np.array([stat_syst_low, stat_syst_up])

stat_syst = np.array([stat_syst_low, stat_syst_up])

print stat_syst

plt.figure(1)

plt.errorbar(t,y,None,stat_syst, xlolims=True, marker='s', linewidth=0, elinewidth=10 ,ecolor='green')

plt.errorbar(t[0],y[0],None,stat_syst_0, xlolims=True, marker='s', linewidth=0, elinewidth=10 ,ecolor='orange')

plt.errorbar(t,y,None,stat,marker='s', linewidth=0, elinewidth=2, ecolor='black',mfc='black')

plt.yticks( np.arange(n), names )

plt.axis([2.0,3.6,-1,n])

plt.xlabel(r'$^{116}$Cd 2$\nu\beta\beta$ half-life [$\times 10^{19}$ y]')

plt.grid(axis='x')

plt.figure(2)

plt.errorbar(t0nu,y,None,None,marker='s', linewidth=0, elinewidth=2, ecolor='black',mfc='black')

plt.yticks( np.arange(n), names )

plt.axis([0.001,2.0,-1,n])

plt.xlabel(r'$^{116}$Cd 0$\nu\beta\beta$ half-life limits @ 90% C.L. [$\times 10^{19}$ y]')

plt.grid(axis='x')


plt.show()