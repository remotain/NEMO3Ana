#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Print cut flow on terminal')
parser.add_argument('file_path', metavar='file_path', type=str, help='file containing cut flow histogram')
args = parser.parse_args()

from ROOT import *

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

#Load one sample only for test
ProcessChannel.AddDataSet ( DataSet ( "Data" , 0, 0, 0 ) );

hcol = HistoCollection("Data", "Data");

#f = TFile.Open("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141115/OneElectronHistos.root")
f = TFile.Open(args.file_path)
f0 = f.Get("Data"); f0.cd()
hcol.Load(f0);

f1 = f.Get("Air_Tl208"); f1.cd()
hcol.Load(f1);

hcol.GetCollection().Print()

c0 = TCanvas()
hcol.Find("Data_h_RecoCutFlow").Draw()
c1 = TCanvas()
hcol.Find("Air_Tl208_h_RecoCutFlow").Draw()

raw_input("wait...")