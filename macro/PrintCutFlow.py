#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Print cut flow on terminal')
parser.add_argument('file_path', metavar='file_path', type=str, help='file containing cut flow histogram')
parser.add_argument('sample', choices=["SSD" , "HSD" , "MM" , "RHC_L", "RHC_E" , "M1" , "M2" , "M3" , "M7" ])

args = parser.parse_args()

from ROOT import *

#
# Binomial error on the efficiency
# sqrt(eff*(1-eff)/self.norm)

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

gROOT.ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

#Load one sample_dict[args.sample] only for test
DataManagement.AddDataSet ( DataSet ( "Data" , 0, 0, 0 ) );

hdata = HistoCollection("Data", "Data");
hbb = HistoCollection("Bb", "Bb");

#f = TFile.Open("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141115/OneElectronHistos.root")
f = TFile.Open(args.file_path)
fdata = f.Get("Data"); fdata.cd()

sample_dict  = {
    
    "SSD" : "Cd116_2b2n_m14",
    "HSD" : "Cd116_2b2n_m4",
    "MM"  : "Cd116_2b0n_m1", 
    "RHC_L" : "Cd116_2b0n_m2", 
    "RHC_E" : "Cd116_2b0n_m18",     
    "M1"  : "Cd116_2b0n_m5", 
    "M2"  : "Cd116_2b0n_m15",
    "M3"  : "Cd116_2b0n_m6", 
    "M7"  : "Cd116_2b0n_m7"
    
}

fbb   = f.Get(sample_dict[args.sample]); fbb.cd() 
 
hdata.Load(fdata);
hdata.GetCollection().Print()

h_RecoCutFlow = hdata.Find("Data_h_RecoCutFlow")
h_AnaCutFlow = hdata.Find("Data_h_AnaCutFlow")

hbb.Load(fbb);
hbb.GetCollection().Print()


b_RecoCutFlow = hbb.Find(sample_dict[args.sample] + "_h_RecoCutFlow")
b_AnaCutFlow  = hbb.Find(sample_dict[args.sample] + "_h_AnaCutFlow")

tot_gen_evt = DataManagement.FindDataSet( sample_dict[args.sample] ).GetGeneratedEvents();


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


print ""
print "Selection requirement".rjust(70), "|", "Data".rjust(10) , "|", "MC".rjust(10), "|", "Eff".rjust(21), "|"
print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*21, "|"
for i in range(1,h_RecoCutFlow.GetNbinsX()+1):
    
    eff = b_RecoCutFlow.GetBinContent(i)/tot_gen_evt
    eff_e = sqrt(eff*(1-eff)/tot_gen_evt)
    
    print h_RecoCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_RecoCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_RecoCutFlow.GetBinContent(i)), "|", "{0:10.3f}".format(100*eff),"+/-", "{0:<6.3f}".format(100*eff_e ), "|"
    #print h_RecoCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_RecoCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_RecoCutFlow.GetBinContent(i)), "|", "{0:10.5f}".format(b_RecoCutFlow.GetBinContent(i)/b_RecoCutFlow.GetBinContent(1)), "|"    


print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*21, "|"
for i in range(1,b_AnaCutFlow.GetNbinsX()):
    
    eff = b_AnaCutFlow.GetBinContent(i)/tot_gen_evt
    eff_e = sqrt(eff*(1-eff)/tot_gen_evt)
    
    print h_AnaCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_AnaCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_AnaCutFlow.GetBinContent(i)), "|", "{0:10.3f}".format(100*eff),"+/-", "{0:<6.3f}".format(100*eff_e), "|"
    #print h_AnaCutFlow.GetXaxis().GetBinLabel(i).rjust(70), "|", "{0:10.0f}".format(h_AnaCutFlow.GetBinContent(i)), "|", "{0:10.0f}".format(b_AnaCutFlow.GetBinContent(i)), "|", "{0:10.5f}".format(b_AnaCutFlow.GetBinContent(i)/b_RecoCutFlow.GetBinContent(1)), "|"    
print "-"*70 , "|", "-"*10, "|", "-"*10, "|", "-"*21, "|"
print ""    

#Delte objects
fdata.Delete()
fbb.Delete()
f.Close()
