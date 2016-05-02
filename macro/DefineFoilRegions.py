#!/usr/bin/python
import argparse

from ROOT import *

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

f = TFile.Open("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root")

d = f.Get("Data");
		
h_map = d.Get("Data_h_vtx_z_vs_sect_all")

h_map.SetTitle(";Sector; Z")


h = TH1D("h", ";Number of entries per bin;",100, 0, 10000)

for i in range( 0 , h_map.GetNbinsX() ):
       
    for j in range( 0 , h_map.GetNbinsY() ):

        if h_map.GetBinContent(i,j) != 0:
            h.Fill( h_map.GetBinContent(i,j) )

c = TCanvas()
c.Divide(1,2)
c.cd(1)
h_map.Draw("colz")
c.cd(2)
h.Draw()
c.Update()

raw_input("wait...")