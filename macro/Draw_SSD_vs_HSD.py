#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Print cut flow on terminal')
parser.add_argument('file_path', metavar='file_path', type=str, help='file containing cut flow histogram')
args = parser.parse_args()

from ROOT import *

# Load libraries
gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

gROOT.ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

f = TFile.Open(args.file_path)

hc_SSD = HistoCollection("SSD","SSD")
hc_SSD.Load( f.Get("Cd116_2b2n_m14") )
#norm_SSD = float(DataManagement.FindDataSet( "Cd116_2b2n_m14" ).GetGeneratedEvents())
norm_SSD = float(hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").Integral())

hc_HSD = HistoCollection("HSD","HSD")
hc_HSD.Load( f.Get("Cd116_2b2n_m4") )
#norm_HSD = float(DataManagement.FindDataSet( "Cd116_2b2n_m4" ).GetGeneratedEvents())
norm_HSD = float(hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").Integral()) 
  
###############################################################################
  
c_tot = TCanvas("c_tot", "SSD vs HSD", 500, 500)

pad_tot_1 = TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
pad_tot_1.SetTickx(True)
pad_tot_1.SetTicky(True)
pad_tot_1.SetTopMargin(0.1)
pad_tot_1.SetBottomMargin(0.01)
pad_tot_1.SetRightMargin(0.05)
pad_tot_1.SetLeftMargin(0.25)

pad_tot_2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
pad_tot_2.SetTopMargin(0.1)
pad_tot_2.SetBottomMargin(0.35)
pad_tot_2.SetRightMargin(0.05)
pad_tot_2.SetLeftMargin(0.25)
pad_tot_2.SetTickx()
pad_tot_2.SetTicky()

gStyle.SetTitleBorderSize(0);

pad_tot_1.Draw()
pad_tot_1.cd()

hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").SetMarkerStyle(20)
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").SetMarkerSize(0.5)
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").SetMarkerColor(kBlue)
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").Scale( 1/norm_HSD )
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").SetStats(False)
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").GetYaxis().SetTitle("No.Events / 0.1 MeV / Tot No.Events")
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").GetYaxis().SetTitleOffset(2.30)
hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").Draw()

hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").SetMarkerStyle(20)
hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").SetMarkerSize(0.5)
hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").SetMarkerColor(kRed)
hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").Scale( 1/norm_SSD )
hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").GetYaxis().SetTitle("")
hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy").Draw("same")

c_tot.cd()

pad_tot_2.Draw()
pad_tot_2.cd()

hratio_tot = hc_HSD.Find("Cd116_2b2n_m4_h_tot_e_energy").Clone( "ratio" )
hratio_tot.SetTitle("")
hratio_tot.Add(hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy"), -1)
hratio_tot.Divide(hc_SSD.Find("Cd116_2b2n_m14_h_tot_e_energy"))
hratio_tot.SetMarkerStyle(20)
hratio_tot.SetMarkerSize(0.5)
hratio_tot.SetMarkerColor(kBlack)	
	
hratio_tot.GetYaxis().SetTitle("#frac{(HSD-SSD)}{SSD}")
hratio_tot.GetYaxis().CenterTitle(True)
hratio_tot.GetYaxis().SetTitleOffset(0.75)

hratio_tot.GetYaxis().SetRangeUser(-0.2,0.2)

hratio_tot.GetYaxis().SetNdivisions(505)
hratio_tot.GetYaxis().SetTitleSize(0.15)
hratio_tot.GetXaxis().SetTitleSize(0.15)
hratio_tot.GetYaxis().SetLabelSize(0.15)
hratio_tot.GetXaxis().SetLabelSize(0.15)

hratio_tot.Draw()
 
c_tot.Update() 

###############################################################################
  
c_min = TCanvas("c_min", "SSD vs HSD", 500, 500)

pad_min_1 = TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
pad_min_1.SetTickx(True)
pad_min_1.SetTicky(True)
pad_min_1.SetTopMargin(0.1)
pad_min_1.SetBottomMargin(0.01)
pad_min_1.SetRightMargin(0.05)
pad_min_1.SetLeftMargin(0.25)

pad_min_2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
pad_min_2.SetTopMargin(0.1)
pad_min_2.SetBottomMargin(0.35)
pad_min_2.SetRightMargin(0.05)
pad_min_2.SetLeftMargin(0.25)
pad_min_2.SetTickx()
pad_min_2.SetTicky()

gStyle.SetTitleBorderSize(0);

pad_min_1.Draw()
pad_min_1.cd()

hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").SetMarkerStyle(20)
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").SetMarkerSize(0.5)
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").SetMarkerColor(kBlue)
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").Scale( 1/norm_HSD )
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").SetStats(False)
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").GetYaxis().SetTitle("No.Events / 0.1 MeV / Tot No.Events")
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").GetYaxis().SetTitleOffset(2.30)
hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").Draw()

hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").SetMarkerStyle(20)
hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").SetMarkerSize(0.5)
hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").SetMarkerColor(kRed)
hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").Scale( 1/norm_SSD )
hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").GetYaxis().SetTitle("")
hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy").Draw("same")

c_min.cd()

pad_min_2.Draw()
pad_min_2.cd()

hratio_min = hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy").Clone( "ratio" )
hratio_min.SetTitle("")
hratio_min.Add(hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy"),-1)
hratio_min.Divide(hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy"))
hratio_min.SetMarkerStyle(20)
hratio_min.SetMarkerSize(0.5)
hratio_min.SetMarkerColor(kBlack)	
    
hratio_min.GetYaxis().SetTitle("#frac{(HSD-SSD)}{SSD}")
hratio_min.GetYaxis().CenterTitle(True)
hratio_min.GetYaxis().SetTitleOffset(0.75)

hratio_min.GetYaxis().SetRangeUser(-0.2,0.2)

hratio_min.GetYaxis().SetNdivisions(505)
hratio_min.GetYaxis().SetTitleSize(0.15)
hratio_min.GetXaxis().SetTitleSize(0.15)
hratio_min.GetYaxis().SetLabelSize(0.15)
hratio_min.GetXaxis().SetLabelSize(0.15)

hratio_min.Draw()
 
c_min.Update() 

###############################################################################
  
c_max = TCanvas("c_max", "SSD vs HSD", 500, 500)

pad_max_1 = TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
pad_max_1.SetTickx(True)
pad_max_1.SetTicky(True)
pad_max_1.SetTopMargin(0.1)
pad_max_1.SetBottomMargin(0.01)
pad_max_1.SetRightMargin(0.05)
pad_max_1.SetLeftMargin(0.25)

pad_max_2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
pad_max_2.SetTopMargin(0.1)
pad_max_2.SetBottomMargin(0.35)
pad_max_2.SetRightMargin(0.05)
pad_max_2.SetLeftMargin(0.25)
pad_max_2.SetTickx()
pad_max_2.SetTicky()

gStyle.SetTitleBorderSize(0);

pad_max_1.Draw()
pad_max_1.cd()

hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").SetMarkerStyle(20)
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").SetMarkerSize(0.5)
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").SetMarkerColor(kBlue)
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").Scale( 1/norm_HSD )
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").SetStats(False)
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").GetYaxis().SetTitle("No.Events / 0.1 MeV / Tot No.Events")
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").GetYaxis().SetTitleOffset(2.30)
hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").Draw()

hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").SetMarkerStyle(20)
hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").SetMarkerSize(0.5)
hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").SetMarkerColor(kRed)
hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").Scale( 1/norm_SSD )
hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").GetYaxis().SetTitle("")
hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").Draw("same")

c_max.cd()

pad_max_2.Draw()
pad_max_2.cd()

hratio_max = hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").Clone( "ratio" )
hratio_max.SetTitle("")
hratio_max.Add(hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy"),-1)
hratio_max.Divide(hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy"))
hratio_max.SetMarkerStyle(20)
hratio_max.SetMarkerSize(0.5)	
hratio_max.SetMarkerColor(kBlack)
    
hratio_max.GetYaxis().SetTitle("#frac{(HSD-SSD)}{SSD}")
hratio_max.GetYaxis().CenterTitle(True)
hratio_max.GetYaxis().SetTitleOffset(0.75)

hratio_max.GetYaxis().SetRangeUser(-0.2,0.2)

hratio_max.GetYaxis().SetNdivisions(505)
hratio_max.GetYaxis().SetTitleSize(0.15)
hratio_max.GetXaxis().SetTitleSize(0.15)
hratio_max.GetYaxis().SetLabelSize(0.15)
hratio_max.GetXaxis().SetLabelSize(0.15)

hratio_max.Draw()
 
c_max.Update() 
 
###############################################################################
  
c_single = TCanvas("c_single", "SSD vs HSD", 500, 500)

pad_single_1 = TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
pad_single_1.SetTickx(True)
pad_single_1.SetTicky(True)
pad_single_1.SetTopMargin(0.1)
pad_single_1.SetBottomMargin(0.01)
pad_single_1.SetRightMargin(0.05)
pad_single_1.SetLeftMargin(0.25)

pad_single_2 = TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
pad_single_2.SetTopMargin(0.1)
pad_single_2.SetBottomMargin(0.35)
pad_single_2.SetRightMargin(0.05)
pad_single_2.SetLeftMargin(0.25)
pad_single_2.SetTickx()
pad_single_2.SetTicky()

gStyle.SetTitleBorderSize(0);

pad_single_1.Draw()
pad_single_1.cd()

HSD_single = hc_HSD.Find("Cd116_2b2n_m4_h_max_e_energy").Clone("HSD_single")
HSD_single.Add(hc_HSD.Find("Cd116_2b2n_m4_h_min_e_energy"),+1)
HSD_single.Draw()

SSD_single = hc_SSD.Find("Cd116_2b2n_m14_h_max_e_energy").Clone("SSD_single")
SSD_single.Add(hc_SSD.Find("Cd116_2b2n_m14_h_min_e_energy"),+1)
SSD_single.Draw("same")

c_single.cd()

pad_single_2.Draw()
pad_single_2.cd()

hratio_single = HSD_single.Clone( "ratio" )
hratio_single.SetTitle("")
hratio_single.Add(SSD_single,-1)
hratio_single.Divide(SSD_single)
hratio_single.SetMarkerStyle(20)
hratio_single.SetMarkerSize(0.5)	
hratio_single.SetMarkerColor(kBlack)
    
hratio_single.GetYaxis().SetTitle("#frac{(HSD-SSD)}{SSD}")
hratio_single.GetYaxis().CenterTitle(True)
hratio_single.GetYaxis().SetTitleOffset(0.75)

hratio_single.GetYaxis().SetRangeUser(-0.2,0.2)

hratio_single.GetYaxis().SetNdivisions(505)
hratio_single.GetYaxis().SetTitleSize(0.15)
hratio_single.GetXaxis().SetTitleSize(0.15)
hratio_single.GetYaxis().SetLabelSize(0.15)
hratio_single.GetXaxis().SetLabelSize(0.15)

hratio_single.GetXaxis().SetTitle("E / MeV")

hratio_single.Draw()
 
c_single.Update()  

print "SSD : %.1f / %.1f (%.2f %%)" % (norm_SSD, DataManagement.FindDataSet( "Cd116_2b2n_m14" ).GetGeneratedEvents(), 100*norm_SSD/DataManagement.FindDataSet( "Cd116_2b2n_m14" ).GetGeneratedEvents()) 
print "HSD : %.1f / %.1f (%.2f %%)" % (norm_HSD, DataManagement.FindDataSet( "Cd116_2b2n_m4" ).GetGeneratedEvents(), 100*norm_HSD/DataManagement.FindDataSet( "Cd116_2b2n_m4" ).GetGeneratedEvents()) 
 
raw_input("wait...")

c_tot.Print("SSD_vs_HSD.pdf(")
c_min.Print("SSD_vs_HSD.pdf")
c_max.Print("SSD_vs_HSD.pdf")
c_single.Print("SSD_vs_HSD.pdf)")

# Delete objects
hc_SSD.Delete() 
hc_HSD.Delete() 
f.Close()
