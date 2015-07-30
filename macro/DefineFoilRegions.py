#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Define foil regions')
parser.add_argument('file_path', metavar='file_path', type=str, help='file containing 1e foil map')
args = parser.parse_args()

from ROOT import *

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");
f = TFile.Open(args.file_path)

h_map = f.Get("foil_map_1e")
h_map.SetTitle(";Sector; Z")
#h_map.Rebin2D(1,1)
#h_map.GetXaxis().SetRangeUser(18.8,19.0)
#h_map.GetYaxis().SetRangeUser(-120,120)

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