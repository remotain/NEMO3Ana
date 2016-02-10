from ROOT import *

gROOT.ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+")

gSystem.Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

gROOT.ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

###########################################################################
###########################################################################
def SystShape(tfile, data_set):

    t = f.Get(data_set + "_tree")
    
    h_d = TH1F("h_d", "", 46, 0, 4.6)
    h_p = TH1F("h_p", "", 46, 0, 4.6)
    h_m = TH1F("h_m", "", 46, 0, 4.6)
    
    t.Draw("1.00*(min_el_en+max_el_en)>>h_d","1.00*min_el_en>0.30&&1.00*max_el_en>0.30","goff")
    t.Draw("1.01*(min_el_en+max_el_en)>>h_p","1.01*min_el_en>0.30&&1.01*max_el_en>0.30","goff")
    t.Draw("0.99*(min_el_en+max_el_en)>>h_m","0.99*min_el_en>0.30&&0.99*max_el_en>0.30","goff")    
    
    h_d.Sumw2()
    h_p.Sumw2()
    h_m.Sumw2()
    
    eff_d = h_d.Integral(0,h_d.GetNbinsX()) / DataManagement.FindDataSet( data_set ).GetGeneratedEvents()
    eff_p = h_p.Integral(0,h_p.GetNbinsX()) / DataManagement.FindDataSet( data_set ).GetGeneratedEvents()
    eff_m = h_m.Integral(0,h_m.GetNbinsX()) / DataManagement.FindDataSet( data_set ).GetGeneratedEvents()
    
    if eff_d != 0:
        syst_p = (eff_p - eff_d) / eff_d
        syst_m = (eff_m - eff_d) / eff_d
    else:
        syst_p = 0.
        syst_m = 0.
    
    h_syst_p = h_p.Clone(data_set + "_h_syst_p")
    #h_syst_p.Add(h_d,-1)
    h_syst_p.Divide(h_d)        
    #h_syst_p.Scale(1/float(DataManagement.FindDataSet( data_set ).GetGeneratedEvents()))
    h_syst_p.SetLineColor(kBlue)
    
    h_syst_m = h_m.Clone(data_set + "_h_syst_m")
    #h_syst_m.Add(h_p,-1)
    h_syst_m.Divide(h_d)
    #h_syst_m.Scale(1/float(DataManagement.FindDataSet( data_set ).GetGeneratedEvents()))
    h_syst_m.SetLineColor(kRed)

    h_d.Delete()
    h_p.Delete()
    h_m.Delete()        
    t.Delete()
    
    return [syst_p, syst_m, h_syst_p, h_syst_m]

###########################################################################
###########################################################################

data_set_list = [
    "Cd116_Tl208"    ,
    "Cd116_Ac228"    ,
    "Cd116_Bi212"    ,
    "Cd116_Bi214"    ,
    "Cd116_Pb214_VT" ,
    "Mylar_Bi214"    ,
    "Mylar_Pb214"    ,
    "Cd116_K40"      ,
    "Cd116_Pa234m"   ,
    "SFoil_Bi210"    ,
    "SWire_Bi210"    ,
    "SScin_Bi210"    ,
    "SScin_Bi214"    ,
    "SScin_Pb214"    ,
    "SWire_Tl208"    ,
    "SWire_Bi214"    ,
    "SFoil_Bi214"    ,
    "SWire_Pb214"    ,
    "SFoil_Pb214"    ,
    "FeShield_Bi214" ,
    "FeShield_Tl208" ,
    "FeShield_Ac228" ,
    "CuTower_Co60"   ,
    "Air_Pb214"      ,
    "Air_Bi214"      ,
    "Air_Tl208"      ,
    "PMT_Bi214"      ,
    "PMT_Tl208"      ,
    "PMT_Ac228"      ,
    "PMT_K40"        ,
    "ScintInn_K40"   ,
    "ScintOut_K40"   ,
    "ScintPet_K40"   ,
    "MuMetal_Pa234m" ,
    "Cd116_2b2n_m14" 
]

# Create a ROOT output file where TMVA will store ntuples, histograms, etc.
fd = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/" 

fn = "TwoElectronIntTree_LOOSE_EMINCUT.root"


f = TFile.Open( fd + fn , "READ" ) 
f.Print() 

f_out = TFile.Open( fd + "SystShape.root" , "RECREATE" ) 
f_out.Print() 

f.cd()

c = TCanvas()

h = TH1F("h","; #Sigma E_{e} / MeV ; Syst. / 0.1 MeV",46,0,4.6)
h.GetYaxis().SetRangeUser(0, 2)
h.GetXaxis().SetTitleOffset(2)
h.SetStats(False)
h.Draw()

c.Update()

sup = 0
mup = 0

for data_set in data_set_list:
    
    syst = SystShape(f, data_set)

    if data_set == "Cd116_2b2n_m14":
        syst[2].DrawCopy("same")
        syst[3].DrawCopy("same")
    
    
    print "{0:20}".format(data_set) + " | " + "{0:10.5f}".format(100*syst[0]) + " | " + "{0:10.5f}".format(100*syst[1])

    sup += syst[0]
    mup += syst[1]

    f_out.cd()
    
    syst[2].Write()
    syst[3].Write()

c.Update()

#print "{0:20}".format("Total") + " | " + "{0:10.5f}".format(100*sup) + " | " + "{0:10.5f}".format(100*mup)

raw_input("wait...")

f.Close()
f_out.Close()