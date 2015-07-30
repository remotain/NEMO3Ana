#!/usr/bin/python
import argparse
from array import *
from ROOT import *

n = 3

names = ("This work", "Zac/Benton", "Solotvina")

t    = array('d', [2.75, 2.88, 2.9]  )
y    = array('d', [1, 2, 3]  )
ey   = array('d', [0.05, 0.05, 0.05]  )
zero = array('d', [0.0, 0.0, 0.0]  )
stat = array('d', [0.05, 0.04, 0.06] )
syst_low = array('d', [-0.17, -0.17, -0.38] )
syst_up  = array('d', [+0.17, +0.16, +0.40] )

stat_syst_low_l = list()
stat_syst_up_l  = list()

for i in range(3):
    
    stat_syst_low_l.append( sqrt(stat[i]*stat[i] + syst_low[i]*syst_low[i]) )
    stat_syst_up_l.append( sqrt(stat[i]*stat[i] + syst_up[i]*syst_up[i]) )

stat_syst_low = array( 'd', stat_syst_low_l)
stat_syst_up = array( 'd', stat_syst_up_l)

print stat_syst_low 
print stat_syst_up 

c = TCanvas()
c.SetGridx(False)
c.SetGridy(False)

gr_stat_syst = TGraphAsymmErrors(3,t,y,stat_syst_low,stat_syst_up,ey,ey);
gr_stat_syst.SetTitle("; T_{1/2}^{2#nu} #times 10^{19} [y] ;");
gr_stat_syst.SetMarkerColor(4);
gr_stat_syst.SetMarkerStyle(21);

gr_stat_syst.SetFillColor(kOrange+10);
gr_stat_syst.Draw("A2");

ay = gr_stat_syst.GetHistogram().GetYaxis();
y1 = ay.GetBinLowEdge(1);
y2 = ay.GetBinUpEdge(ay.GetNbins());
gr_stat_syst.GetHistogram().GetYaxis().Set(3,y1,y2);
gr_stat_syst.GetHistogram().GetYaxis().SetBinLabel(1,names[0]);
gr_stat_syst.GetHistogram().GetYaxis().SetBinLabel(2,names[1]);
gr_stat_syst.GetHistogram().GetYaxis().SetBinLabel(3,names[2]);

gr_stat_only = TGraphAsymmErrors(3,t,y,stat,stat,zero,zero);
gr_stat_only.SetTitle("; T_{1/2}^{2#nu} #times 10^{19} [y] ;");
gr_stat_only.SetMarkerColor(1);
gr_stat_only.SetMarkerStyle(20);
gr_stat_syst.SetLineWidth(2);
gr_stat_syst.SetFillColor(kOrange);
gr_stat_only.Draw("Psame");

c.Update()

#"comparison", "; T_{1/2}^{2#nu} #times 10^{19} [y] ;");



raw_input("wait...")