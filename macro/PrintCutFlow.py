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

hdata = HistoCollection("Data", "Data");
#hbb = HistoCollection("Bb", "Bb");

#f = TFile.Open("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141115/OneElectronHistos.root")
f = TFile.Open(args.file_path)
fdata = f.Get("Data"); fdata.cd()
#fbb   = f.Get("Cd116_2b2n_m14"); fbb.cd() 
 
hdata.Load(fdata);
hdata.GetCollection().Print()

h_RecoCutFlow = hdata.Find("Data_h_RecoCutFlow")
h_AnaCutFlow = hdata.Find("Data_h_AnaCutFlow")

#hbb.Load(fbb);
#hbb.GetCollection().Print()


#b_RecoCutFlow = hbb.Find("Cd116_2b2n_m14_h_RecoCutFlow")
#b_AnaCutFlow  = hbb.Find("Cd116_2b2n_m14_h_AnaCutFlow")

print ""
print "Selection requirement".rjust(70), "|", "Data".rjust(10) ,"|"
print "-"*70 , "|", "-"*10, "|"
for i in range(1,h_RecoCutFlow.GetNbinsX()+1):
    print h_RecoCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_RecoCutFlow.GetBinContent(i)), "|"


print "-"*70 , "|", "-"*10, "|"
for i in range(1,h_AnaCutFlow.GetNbinsX()):
    print h_AnaCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_AnaCutFlow.GetBinContent(i)), "|"
print "-"*70 , "|", "-"*10, "|"
print ""    


#print ""
#print "Selection requirement".rjust(70), "|", "Data".rjust(10) , "|", "MC bb2nu".rjust(10), "|", "Eff bb2nu".rjust(10), "|"
#print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*10, "|"
#for i in range(1,h_RecoCutFlow.GetNbinsX()+1):
#    print h_RecoCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_RecoCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_RecoCutFlow.GetBinContent(i)), "|", "{0:10.5f}".format(b_RecoCutFlow.GetBinContent(i)/b_RecoCutFlow.GetBinContent(1)), "|"
#
#
#print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*10, "|"
#for i in range(1,b_AnaCutFlow.GetNbinsX()):
#    print h_AnaCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_AnaCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_AnaCutFlow.GetBinContent(i)), "|", "{0:10.5f}".format(b_AnaCutFlow.GetBinContent(i)/b_RecoCutFlow.GetBinContent(1)), "|"
#print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*10, "|"
#print ""    


#raw_input("wait...")