#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Print cut flow on terminal')
parser.add_argument('file_path', metavar='file_path', type=str, help='file containing cut flow histogram')
args = parser.parse_args()

from ROOT import *

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

#Load one sample only for test
DataManagement.AddDataSet ( DataSet ( "Data" , 0, 0, 0 ) );

hcol = HistoCollection("Data", "Data");

#f = TFile.Open("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141115/OneElectronHistos.root")
f = TFile.Open(args.file_path)
f0 = f.Get("Data"); f0.cd()
 
hcol.Load(f0);
hcol.GetCollection().Print()

h_RecoCutFlow = hcol.Find("Data_h_RecoCutFlow")
h_AnaCutFlow = hcol.Find("Data_h_AnaCutFlow")

print ""
print "-"*70 , "|", "-"*10, "|", "-"*7, "|"
for i in range(1,h_RecoCutFlow.GetNbinsX()+1):
    print h_RecoCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_RecoCutFlow.GetBinContent(i)), "|", "{0:4.5f}".format(h_RecoCutFlow.GetBinContent(i)/h_RecoCutFlow.GetBinContent(1)), "|"

print "-"*70 , "|", "-"*10, "|", "-"*7, "|"
for i in range(1,h_AnaCutFlow.GetNbinsX()):
    print h_AnaCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_AnaCutFlow.GetBinContent(i)), "|", "{0:4.5f}".format(h_AnaCutFlow.GetBinContent(i)/h_RecoCutFlow.GetBinContent(1)), "|"
print "-"*70 , "|", "-"*10, "|", "-"*7, "|"
print ""    


#raw_input("wait...")