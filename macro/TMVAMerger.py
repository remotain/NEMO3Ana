#!/usr/bin/python

from ROOT import *

file_path = "/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/"

file_name_template = "TMVApp_"

file_name_merged = "TMVApp.root"

labels_list = (
"Data",
"Cd116_2b0n_m1",
"Cd116_Tl208",
"Cd116_Ac228",
"Cd116_Bi212",
"Cd116_Bi214",
"Cd116_Pb214_VT",
"Mylar_Bi214",
"Mylar_Pb214",
"Cd116_K40",
"Cd116_Pa234m",
"SFoil_Bi210",
"SWire_Bi210",
"SScin_Bi210",
"SScin_Bi214",
"SWire_Tl208",
"SWire_Bi214",
"SFoil_Bi214",
"SWire_Pb214",
"SFoil_Pb214",
"FeShield_Bi214",
"FeShield_Tl208",
"FeShield_Ac228",
"CuTower_Co60",
"Air_Bi214",
"PMT_Bi214",
"PMT_Tl208",
"PMT_Ac228",
"PMT_K40",
"ScintInn_K40",
"ScintOut_K40",
"ScintPet_K40",
"MuMetal_Pa234m",
"Cd116_2b2n_m14"
)

f = TFile.Open(file_path + file_name_merged, "RECREATE")

for label in labels_list:
    
    print "\n Open " + file_name_template + label + ".root...", 

    f_tmp = TFile.Open(file_path + "TMVApp_tmp/" +  file_name_template + label + ".root", "READ")

    if not f_tmp or f_tmp.IsZombie():
        print "Failed!"
        continue
    
    print "Done!"

    h = f_tmp.Get( label + "_MVA_BDT")
    
    f.cd()
    h.Write()
    
f.Print()
f.ls()
f.Close()    
