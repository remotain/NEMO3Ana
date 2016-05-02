#!/usr/bin/python
import re
import argparse
import numpy as np
from ROOT import *

parser = argparse.ArgumentParser(description='')
parser.add_argument('model', choices=["MM" , "RHC_L" , "RHC_E" , "M1" , "M2" , "M3" , "M7" ])
parser.add_argument('observable', choices=["BDT", "E", "ALL" ])
args = parser.parse_args()
		
gROOT.ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+")

###########################################################################
###########################################################################                
Norm90CLEn = {
    'MM'    : 78.5  * 0.09208,
    'RHC_E' : 87.0  * 0.07510,
    'RHC_L' : 156.0 * 0.04758,       
    'M1'    : 900.7 * 0.06308,
    'M2'    : None,
    'M3'    : None,
    'M7'    : None                                
}

Norm90CLBDT = {
    'MM'    : 71.2  * 0.09208,
    'RHC_E' : 56.8  * 0.07510,
    'RHC_L' : 130.7 * 0.04758,          
    'M1'    : 878.2 * 0.06308,
    'M2'    : None,
    'M3'    : None,
    'M7'    : None                                
}

Norm90CL = {
    "E"   : Norm90CLEn,
    "BDT" : Norm90CLBDT
}

Label = {
    'MM'    : "#LT m_{#nu} #GT",
    'RHC_L' : "RHC #lambda ",
    'RHC_E' : "RHC #eta ",        
    'M1'    : "M1 ",
    'M2'    : "M2 ",
    'M3'    : "M3 ",
    'M7'    : "M7 "                                        
}


HistoTitle = "NEMO-3 ^{116}Cd - 0.410 g, 5.26 y"

###########################################################################
###########################################################################                
def DrawObservable( model, obs, norm = None, min = None, max = None, zoom = False ): 
    
    Model = {
        'MM'    : False,
        'RHC_L' : False,
        'RHC_E' : False,        
        'M1'    : False,
        'M2'    : False,
        'M3'    : False,
        'M7'    : False                                
    }
        
    Model[model] = True
        
    # weigths
    Cd116_Tl208_weight     = 5.93241
    Cd116_Ac228_weight     = 6.92004
    Cd116_Bi212_weight     = 2.74493
    Cd116_Bi214_weight     = 18.2853
    Cd116_Pb214_weight     = 0.186478
    Mylar_Bi214_weight     = 11.1896
    Mylar_Pb214_weight     = 0.493241
    Cd116_K40_weight       = 25.9835+9.02952
    Cd116_Pa234m_weight    = 27.7433+72.4378
    SFoil_Bi210_weight     = 23.243
    SWire_Bi210_weight     = 0.136147+0.624186
    SScin_Bi210_weight     = 1.756
    SScin_Bi214_weight     = 0.050538
    SScin_Pb214_weight     = 0.
    SWire_Tl208_weight     = 0.217623+1.07644
    SWire_Bi214_P1_weight  = 21.4626+17.9578
    SFoil_Bi214_weight     = 5.77558+2.73528
    SWire_Pb214_weight     = 0.457546+0.648406
    SFoil_Pb214_weight     = 0.215627+0.188876
    FeShield_Bi214_weight  = 49.1846
    FeShield_Tl208_weight  = 1.19312
    FeShield_Ac228_weight  = 0.17612
    CuTower_Co60_weight    = 3.77603
    Air_Bi214_P1_weight    = 4.19271
    Air_Tl208_P1_weight    = 0.
    PMT_Bi214_weight       = 30.7385
    PMT_Tl208_weight       = 23.2701
    PMT_Ac228_weight       = 3.60944
    PMT_K40_weight         = 16.7905
    ScintInn_K40_weight    = 0.335557
    ScintOut_K40_weight    = 0.604003
    ScintPet_K40_weight    = 1.00666
    MuMetal_Pa234m_weight  = 0.66462
    Cd116_2b2n_m14_weight  = 5022.22
       
    # Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    fd = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/" 

    if obs == "BDT" :
        fn = "TMVApp/TMVApp_%s.root" %  model 
    elif obs == "E" :
        fn = "TwoElectronIntHistos.root"

    f = TFile.Open( fd + fn , "READ" ) 
    f.Print() 
    
    if obs == "BDT" :
        
        Data = f.Get("Data_MVA_BDT") 
        	
        if Model[ "MM"    ] : 
            Signal = f.Get( "Cd116_2b0n_m1_MVA_BDT"   )   
        if Model[ "RHC_L" ] : 
            Signal = f.Get( "Cd116_2b0n_m2_MVA_BDT"   )   
        if Model[ "RHC_E" ] : 
            Signal = f.Get( "Cd116_2b0n_m18_MVA_BDT"  )   	
        if Model[ "M1"    ] : 
            Signal = f.Get( "Cd116_2b0n_m5_MVA_BDT"   )   
        if Model[ "M2"    ] : 
            Signal = f.Get( "Cd116_2b0n_m15_MVA_BDT"  )   
        if Model[ "M3"    ] : 
            Signal = f.Get( "Cd116_2b0n_m6_MVA_BDT"   )   
        if Model[ "M7"    ] : 
            Signal = f.Get( "Cd116_2b0n_m7_MVA_BDT"   )   

        Cd116_Tl208      = f.Get("Cd116_Tl208_MVA_BDT"    ) 
        if Cd116_Tl208    : 
            Cd116_Tl208    . Scale( Cd116_Tl208_weight    / Cd116_Tl208     .Integral() )
             
        Cd116_Ac228      = f.Get("Cd116_Ac228_MVA_BDT"    ) 
        if Cd116_Ac228    : 
            Cd116_Ac228    . Scale( Cd116_Ac228_weight    / Cd116_Ac228     .Integral() )
             
        Cd116_Bi212      = f.Get("Cd116_Bi212_MVA_BDT"    ) 
        if Cd116_Bi212    : 
            Cd116_Bi212    . Scale( Cd116_Bi212_weight    / Cd116_Bi212     .Integral() )
             
        Cd116_Bi214      = f.Get("Cd116_Bi214_MVA_BDT"    ) 
        if Cd116_Bi214    : 
            Cd116_Bi214    . Scale( Cd116_Bi214_weight    / Cd116_Bi214     .Integral() )
             
        Cd116_Pb214      = f.Get("Cd116_Pb214_VT_MVA_BDT" ) 
        if Cd116_Pb214    : 
            Cd116_Pb214    . Scale( Cd116_Pb214_weight    / Cd116_Pb214     .Integral() )
             
        Mylar_Bi214      = f.Get("Mylar_Bi214_MVA_BDT"    ) 
        if Mylar_Bi214    : 
            Mylar_Bi214    . Scale( Mylar_Bi214_weight    / Mylar_Bi214     .Integral() )
             
        Mylar_Pb214      = f.Get("Mylar_Pb214_MVA_BDT"    ) 
        if Mylar_Pb214    : 
            Mylar_Pb214    . Scale( Mylar_Pb214_weight    / Mylar_Pb214     .Integral() )
             
        Cd116_K40        = f.Get("Cd116_K40_MVA_BDT"      ) 
        if Cd116_K40      : 
            Cd116_K40      . Scale( Cd116_K40_weight      / Cd116_K40       .Integral() )
             
        Cd116_Pa234m     = f.Get("Cd116_Pa234m_MVA_BDT"   ) 
        if Cd116_Pa234m   : 
            Cd116_Pa234m   . Scale( Cd116_Pa234m_weight   / Cd116_Pa234m    .Integral() )
             
        SFoil_Bi210      = f.Get("SFoil_Bi210_MVA_BDT"    ) 
        if SFoil_Bi210    : 
            SFoil_Bi210    . Scale( SFoil_Bi210_weight    / SFoil_Bi210     .Integral() )
             
        SWire_Bi210      = f.Get("SWire_Bi210_MVA_BDT"    ) 
        if SWire_Bi210    : 
            SWire_Bi210    . Scale( SWire_Bi210_weight    / SWire_Bi210     .Integral() )
             
        SScin_Bi210      = f.Get("SScin_Bi210_MVA_BDT"    ) 
        if SScin_Bi210    : 
            SScin_Bi210    . Scale( SScin_Bi210_weight    / SScin_Bi210     .Integral() )
             
        SScin_Bi214      = f.Get("SScin_Bi214_MVA_BDT"    ) 
        if SScin_Bi214    : 
            SScin_Bi214    . Scale( SScin_Bi214_weight    / SScin_Bi214     .Integral() )
             
        SScin_Pb214      = f.Get("SScin_Pb214_MVA_BDT"    ) 
        if SScin_Pb214    : 
            SScin_Pb214    . Scale( SScin_Pb214_weight    / SScin_Pb214     .Integral() )
             
        SWire_Tl208      = f.Get("SWire_Tl208_MVA_BDT"    ) 
        if SWire_Tl208    : 
            SWire_Tl208    . Scale( SWire_Tl208_weight    / SWire_Tl208     .Integral() )
             
        SWire_Bi214_P1   = f.Get("SWire_Bi214_MVA_BDT"    ) 
        if SWire_Bi214_P1 : 
            SWire_Bi214_P1 . Scale( SWire_Bi214_P1_weight / SWire_Bi214_P1  .Integral() )
             
        SFoil_Bi214      = f.Get("SFoil_Bi214_MVA_BDT"    ) 
        if SFoil_Bi214    : 
            SFoil_Bi214    . Scale( SFoil_Bi214_weight    / SFoil_Bi214     .Integral() )
             
        SWire_Pb214      = f.Get("SWire_Pb214_MVA_BDT"    ) 
        if SWire_Pb214    : 
            SWire_Pb214    . Scale( SWire_Pb214_weight    / SWire_Pb214     .Integral() )
             
        SFoil_Pb214      = f.Get("SFoil_Pb214_MVA_BDT"    ) 
        if SFoil_Pb214    : 
            SFoil_Pb214    . Scale( SFoil_Pb214_weight    / SFoil_Pb214     .Integral() )
             
        FeShield_Bi214   = f.Get("FeShield_Bi214_MVA_BDT" ) 
        if FeShield_Bi214 : 
            FeShield_Bi214 . Scale( FeShield_Bi214_weight / FeShield_Bi214  .Integral() )
             
        FeShield_Tl208   = f.Get("FeShield_Tl208_MVA_BDT" ) 
        if FeShield_Tl208 : 
            FeShield_Tl208 . Scale( FeShield_Tl208_weight / FeShield_Tl208  .Integral() )
             
        FeShield_Ac228   = f.Get("FeShield_Ac228_MVA_BDT" ) 
        if FeShield_Ac228 : 
            FeShield_Ac228 . Scale( FeShield_Ac228_weight / FeShield_Ac228  .Integral() )
             
        CuTower_Co60     = f.Get("CuTower_Co60_MVA_BDT"   ) 
        if CuTower_Co60   : 
            CuTower_Co60   . Scale( CuTower_Co60_weight   / CuTower_Co60    .Integral() )
             
        Air_Bi214_P1     = f.Get("Air_Bi214_MVA_BDT"      ) 
        if Air_Bi214_P1   : 
            Air_Bi214_P1   . Scale( Air_Bi214_P1_weight   / Air_Bi214_P1    .Integral() )
             
        Air_Tl208_P1     = f.Get("Air_Tl208_MVA_BDT"      ) 
        if Air_Tl208_P1   : 
            Air_Tl208_P1   . Scale( Air_Tl208_P1_weight   / Air_Tl208_P1    .Integral() )
             
        PMT_Bi214        = f.Get("PMT_Bi214_MVA_BDT"      ) 
        if PMT_Bi214      : 
            PMT_Bi214      . Scale( PMT_Bi214_weight      / PMT_Bi214       .Integral() )
             
        PMT_Tl208        = f.Get("PMT_Tl208_MVA_BDT"      ) 
        if PMT_Tl208      : 
            PMT_Tl208      . Scale( PMT_Tl208_weight      / PMT_Tl208       .Integral() )
             
        PMT_Ac228        = f.Get("PMT_Ac228_MVA_BDT"      ) 
        if PMT_Ac228      : 
            PMT_Ac228      . Scale( PMT_Ac228_weight      / PMT_Ac228       .Integral() )
             
        PMT_K40          = f.Get("PMT_K40_MVA_BDT"        ) 
        if PMT_K40        : 
            PMT_K40        . Scale( PMT_K40_weight        / PMT_K40         .Integral() )
             
        ScintInn_K40     = f.Get("ScintInn_K40_MVA_BDT"   ) 
        if ScintInn_K40   : 
            ScintInn_K40   . Scale( ScintInn_K40_weight   / ScintInn_K40    .Integral() )
             
        ScintOut_K40     = f.Get("ScintOut_K40_MVA_BDT"   ) 
        if ScintOut_K40   : 
            ScintOut_K40   . Scale( ScintOut_K40_weight   / ScintOut_K40    .Integral() )
             
        ScintPet_K40     = f.Get("ScintPet_K40_MVA_BDT"   ) 
        if ScintPet_K40   : 
            ScintPet_K40   . Scale( ScintPet_K40_weight   / ScintPet_K40    .Integral() )
             
        MuMetal_Pa234m   = f.Get("MuMetal_Pa234m_MVA_BDT" ) 
        if MuMetal_Pa234m : 
            MuMetal_Pa234m . Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m  .Integral() )
             
        Cd116_2b2n_m14   = f.Get("Cd116_2b2n_m14_MVA_BDT" ) 
        if Cd116_2b2n_m14 : 
            Cd116_2b2n_m14 . Scale( Cd116_2b2n_m14_weight / Cd116_2b2n_m14  .Integral() )
         


    if obs == "E" :
        
        d = f.Get("Data")
        Data = d.Get("Data_h_tot_e_energy") 
        	
        if Model[ "MM"    ] : 
            d=f.Get("Cd116_2b0n_m1"  )
            Signal = d.Get( "Cd116_2b0n_m1_h_tot_e_energy"   )   
        if Model[ "RHC_L" ] : 
            d=f.Get("Cd116_2b0n_m2"  )
            Signal = d.Get( "Cd116_2b0n_m2_h_tot_e_energy"   )   
        if Model[ "RHC_E" ] : 
            d=f.Get("Cd116_2b0n_m18" )
            Signal = d.Get( "Cd116_2b0n_m18_h_tot_e_energy"  )   	
        if Model[ "M1"    ] : 
            d=f.Get("Cd116_2b0n_m5"  )
            Signal = d.Get( "Cd116_2b0n_m5_h_tot_e_energy"   )   
        if Model[ "M2"    ] : 
            d=f.Get("Cd116_2b0n_m15" )
            Signal = d.Get( "Cd116_2b0n_m15_h_tot_e_energy"  )   
        if Model[ "M3"    ] : 
            d=f.Get("Cd116_2b0n_m6"  )
            Signal = d.Get( "Cd116_2b0n_m6_h_tot_e_energy"   )   
        if Model[ "M7"    ] : 
            d=f.Get("Cd116_2b0n_m7"  )
            Signal = d.Get( "Cd116_2b0n_m7_h_tot_e_energy"   )   

        d = f.Get("Cd116_Tl208")
        Cd116_Tl208      = d.Get("Cd116_Tl208_h_tot_e_energy"    ) 
        if Cd116_Tl208   .GetEntries() != 0 : 
            Cd116_Tl208    . Scale( Cd116_Tl208_weight    / Cd116_Tl208     .Integral() )
             
        d = f.Get("Cd116_Ac228")
        Cd116_Ac228      = d.Get("Cd116_Ac228_h_tot_e_energy"    ) 
        if Cd116_Ac228   .GetEntries() != 0 : 
            Cd116_Ac228    . Scale( Cd116_Ac228_weight    / Cd116_Ac228     .Integral() )
             
        d = f.Get("Cd116_Bi212")
        Cd116_Bi212      = d.Get("Cd116_Bi212_h_tot_e_energy"    ) 
        if Cd116_Bi212   .GetEntries() != 0 : 
            Cd116_Bi212    . Scale( Cd116_Bi212_weight    / Cd116_Bi212     .Integral() )
             
        d = f.Get("Cd116_Bi214")
        Cd116_Bi214      = d.Get("Cd116_Bi214_h_tot_e_energy"    ) 
        if Cd116_Bi214   .GetEntries() != 0 : 
            Cd116_Bi214    . Scale( Cd116_Bi214_weight    / Cd116_Bi214     .Integral() )
             
        d = f.Get("Cd116_Pb214_VT")
        Cd116_Pb214      = d.Get("Cd116_Pb214_VT_h_tot_e_energy" ) 
        if Cd116_Pb214   .GetEntries() != 0 : 
            Cd116_Pb214    . Scale( Cd116_Pb214_weight    / Cd116_Pb214     .Integral() )
             
        d = f.Get("Mylar_Bi214")
        Mylar_Bi214      = d.Get("Mylar_Bi214_h_tot_e_energy"    ) 
        if Mylar_Bi214   .GetEntries() != 0 : 
            Mylar_Bi214    . Scale( Mylar_Bi214_weight    / Mylar_Bi214     .Integral() )
             
        d = f.Get("Mylar_Pb214")
        Mylar_Pb214      = d.Get("Mylar_Pb214_h_tot_e_energy"    ) 
        if Mylar_Pb214   .GetEntries() != 0 : 
            Mylar_Pb214    . Scale( Mylar_Pb214_weight    / Mylar_Pb214     .Integral() )
             
        d = f.Get("Cd116_K40")
        Cd116_K40        = d.Get("Cd116_K40_h_tot_e_energy"      ) 
        if Cd116_K40     .GetEntries() != 0 : 
            Cd116_K40      . Scale( Cd116_K40_weight      / Cd116_K40       .Integral() )
             
        d = f.Get("Cd116_Pa234m")
        Cd116_Pa234m     = d.Get("Cd116_Pa234m_h_tot_e_energy"   ) 
        if Cd116_Pa234m  .GetEntries() != 0 : 
            Cd116_Pa234m   . Scale( Cd116_Pa234m_weight   / Cd116_Pa234m    .Integral() )
             
        d = f.Get("SFoil_Bi210")
        SFoil_Bi210      = d.Get("SFoil_Bi210_h_tot_e_energy"    ) 
        if SFoil_Bi210   .GetEntries() != 0 : 
            SFoil_Bi210    . Scale( SFoil_Bi210_weight    / SFoil_Bi210     .Integral() )
             
        d = f.Get("SWire_Bi210")
        SWire_Bi210      = d.Get("SWire_Bi210_h_tot_e_energy"    ) 
        if SWire_Bi210   .GetEntries() != 0 : 
            SWire_Bi210    . Scale( SWire_Bi210_weight    / SWire_Bi210     .Integral() )
             
        d = f.Get("SScin_Bi210")
        SScin_Bi210      = d.Get("SScin_Bi210_h_tot_e_energy"    ) 
        if SScin_Bi210   .GetEntries() != 0 : 
            SScin_Bi210    . Scale( SScin_Bi210_weight    / SScin_Bi210     .Integral() )
             
        d = f.Get("SScin_Bi214")
        SScin_Bi214      = d.Get("SScin_Bi214_h_tot_e_energy"    ) 
        if SScin_Bi214   .GetEntries() != 0 : 
            SScin_Bi214    . Scale( SScin_Bi214_weight    / SScin_Bi214     .Integral() )
             
        d = f.Get("SScin_Pb214")
        SScin_Pb214      = d.Get("SScin_Pb214_h_tot_e_energy"    ) 
        if SScin_Pb214   .GetEntries() != 0 : 
            SScin_Pb214    . Scale( SScin_Pb214_weight    / SScin_Pb214     .Integral() )
             
        d = f.Get("SWire_Tl208")
        SWire_Tl208      = d.Get("SWire_Tl208_h_tot_e_energy"    ) 
        if SWire_Tl208   .GetEntries() != 0 : 
            SWire_Tl208    . Scale( SWire_Tl208_weight    / SWire_Tl208     .Integral() )
             
        d = f.Get("SWire_Bi214")
        SWire_Bi214_P1   = d.Get("SWire_Bi214_h_tot_e_energy"    ) 
        if SWire_Bi214_P1.GetEntries() != 0 : 
            SWire_Bi214_P1 . Scale( SWire_Bi214_P1_weight / SWire_Bi214_P1  .Integral() )
             
        d = f.Get("SFoil_Bi214")
        SFoil_Bi214      = d.Get("SFoil_Bi214_h_tot_e_energy"    ) 
        if SFoil_Bi214   .GetEntries() != 0 : 
            SFoil_Bi214    . Scale( SFoil_Bi214_weight    / SFoil_Bi214     .Integral() )
             
        d = f.Get("SWire_Pb214")
        SWire_Pb214      = d.Get("SWire_Pb214_h_tot_e_energy"    ) 
        if SWire_Pb214   .GetEntries() != 0 : 
            SWire_Pb214    . Scale( SWire_Pb214_weight    / SWire_Pb214     .Integral() )
             
        d = f.Get("SFoil_Pb214")
        SFoil_Pb214      = d.Get("SFoil_Pb214_h_tot_e_energy"    ) 
        if SFoil_Pb214   .GetEntries() != 0 : 
            SFoil_Pb214    . Scale( SFoil_Pb214_weight    / SFoil_Pb214     .Integral() )
             
        d = f.Get("FeShield_Bi214")
        FeShield_Bi214   = d.Get("FeShield_Bi214_h_tot_e_energy" ) 
        if FeShield_Bi214.GetEntries() != 0 : 
            FeShield_Bi214 . Scale( FeShield_Bi214_weight / FeShield_Bi214  .Integral() )
             
        d = f.Get("FeShield_Tl208")
        FeShield_Tl208   = d.Get("FeShield_Tl208_h_tot_e_energy" ) 
        if FeShield_Tl208.GetEntries() != 0 : 
            FeShield_Tl208 . Scale( FeShield_Tl208_weight / FeShield_Tl208  .Integral() )
             
        d = f.Get("FeShield_Ac228")
        FeShield_Ac228   = d.Get("FeShield_Ac228_h_tot_e_energy" ) 
        if FeShield_Ac228.GetEntries() != 0 : 
            FeShield_Ac228 . Scale( FeShield_Ac228_weight / FeShield_Ac228  .Integral() )
             
        d = f.Get("CuTower_Co60")
        CuTower_Co60     = d.Get("CuTower_Co60_h_tot_e_energy"   ) 
        if CuTower_Co60  .GetEntries() != 0 : 
            CuTower_Co60   . Scale( CuTower_Co60_weight   / CuTower_Co60    .Integral() )
             
        d = f.Get("Air_Bi214")
        Air_Bi214_P1     = d.Get("Air_Bi214_h_tot_e_energy"      ) 
        if Air_Bi214_P1  .GetEntries() != 0 : 
            Air_Bi214_P1   . Scale( Air_Bi214_P1_weight   / Air_Bi214_P1    .Integral() )
             
        d = f.Get("Air_Tl208")
        Air_Tl208_P1     = d.Get("Air_Tl208_h_tot_e_energy"      ) 
        if Air_Tl208_P1  .GetEntries() != 0 : 
            Air_Tl208_P1   . Scale( Air_Tl208_P1_weight   / Air_Tl208_P1    .Integral() )
             
        d = f.Get("PMT_Bi214")
        PMT_Bi214        = d.Get("PMT_Bi214_h_tot_e_energy"      ) 
        if PMT_Bi214     .GetEntries() != 0 : 
            PMT_Bi214      . Scale( PMT_Bi214_weight      / PMT_Bi214       .Integral() )
             
        d = f.Get("PMT_Tl208")
        PMT_Tl208        = d.Get("PMT_Tl208_h_tot_e_energy"      ) 
        if PMT_Tl208     .GetEntries() != 0 : 
            PMT_Tl208      . Scale( PMT_Tl208_weight      / PMT_Tl208       .Integral() )
             
        d = f.Get("PMT_Ac228")
        PMT_Ac228        = d.Get("PMT_Ac228_h_tot_e_energy"      ) 
        if PMT_Ac228     .GetEntries() != 0 : 
            PMT_Ac228      . Scale( PMT_Ac228_weight      / PMT_Ac228       .Integral() )
             
        d = f.Get("PMT_K40")
        PMT_K40          = d.Get("PMT_K40_h_tot_e_energy"        ) 
        if PMT_K40       .GetEntries() != 0 : 
            PMT_K40        . Scale( PMT_K40_weight        / PMT_K40         .Integral() )
             
        d = f.Get("ScintInn_K40")
        ScintInn_K40     = d.Get("ScintInn_K40_h_tot_e_energy"   ) 
        if ScintInn_K40  .GetEntries() != 0 : 
            ScintInn_K40   . Scale( ScintInn_K40_weight   / ScintInn_K40    .Integral() )
             
        d = f.Get("ScintOut_K40")
        ScintOut_K40     = d.Get("ScintOut_K40_h_tot_e_energy"   ) 
        if ScintOut_K40  .GetEntries() != 0 : 
            ScintOut_K40   . Scale( ScintOut_K40_weight   / ScintOut_K40    .Integral() )
             
        d = f.Get("ScintPet_K40")
        ScintPet_K40     = d.Get("ScintPet_K40_h_tot_e_energy"   ) 
        if ScintPet_K40  .GetEntries() != 0 : 
            ScintPet_K40   . Scale( ScintPet_K40_weight   / ScintPet_K40    .Integral() )
             
        d = f.Get("MuMetal_Pa234m")
        MuMetal_Pa234m   = d.Get("MuMetal_Pa234m_h_tot_e_energy" ) 
        if MuMetal_Pa234m.GetEntries() != 0 : 
            MuMetal_Pa234m . Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m  .Integral() )
             
        d = f.Get("Cd116_2b2n_m14")
        Cd116_2b2n_m14   = d.Get("Cd116_2b2n_m14_h_tot_e_energy" ) 
        if Cd116_2b2n_m14.GetEntries() != 0 : 
            Cd116_2b2n_m14 . Scale( Cd116_2b2n_m14_weight / Cd116_2b2n_m14  .Integral() )
        



    
  
    Data.Sumw2()
    
    # Signal normalisation
    if norm == None :
        Signal.Scale( ( 100 ) / Signal.Integral() ) 
    else:
        Signal.Scale( ( norm ) / Signal.Integral() ) 

    # Set the groups
    Tl208 = SWire_Tl208.Clone("Tl208") 
    if Cd116_Tl208:
        Tl208.Add( Cd116_Tl208 )
    if Cd116_Ac228:
        Tl208.Add( Cd116_Ac228 )
    if Cd116_Bi212:
        Tl208.Add( Cd116_Bi212 )
    
    Bi214 = Mylar_Bi214.Clone("Bi214") 
    if Mylar_Pb214:
        Bi214.Add( Mylar_Pb214 )
    if Cd116_Bi214:
        Bi214.Add( Cd116_Bi214 )
    if Cd116_Pb214:
        Bi214.Add( Cd116_Pb214 )
    
    K40 = Cd116_K40.Clone("K40") 
    
    Pa234m = Cd116_Pa234m.Clone("Pa234m") 
    
    Bi210 = SFoil_Bi210.Clone("Bi210") 
    if SWire_Bi210:
        Bi210.Add( SWire_Bi210   )
    
    Radon = SWire_Bi214_P1.Clone("Radon") 
    if SWire_Pb214:
        Radon.Add( SWire_Pb214 )
    if SFoil_Bi214:
        Radon.Add( SFoil_Bi214 )
    if SFoil_Pb214:
        Radon.Add( SFoil_Pb214 )
    	
    Externals = FeShield_Bi214.Clone("Externals") 
    if FeShield_Bi214:
        Externals.Add( FeShield_Bi214 )
    if FeShield_Tl208:
        Externals.Add( FeShield_Tl208 )
    if FeShield_Ac228:
        Externals.Add( FeShield_Ac228 )
    if CuTower_Co60:
        Externals.Add( CuTower_Co60   )
    if Air_Bi214_P1:
        Externals.Add( Air_Bi214_P1   )
    if Air_Tl208_P1:
        Externals.Add( Air_Tl208_P1   )	
    if PMT_Bi214:
        Externals.Add( PMT_Bi214      )
    if PMT_Tl208:
        Externals.Add( PMT_Tl208      )
    if PMT_Ac228:
        Externals.Add( PMT_Ac228      )
    if PMT_K40:
        Externals.Add( PMT_K40        )
    if ScintInn_K40:
        Externals.Add( ScintInn_K40   )
    if ScintOut_K40:
        Externals.Add( ScintOut_K40   )
    if ScintPet_K40:
        Externals.Add( ScintPet_K40   )
    if SScin_Bi210:
        Externals.Add( SScin_Bi210    )
    if SScin_Bi214:
        Externals.Add( SScin_Bi214    )
    if SScin_Pb214:
        Externals.Add( SScin_Pb214    )
    if MuMetal_Pa234m:
        Externals.Add( MuMetal_Pa234m )
    
    
    Tl208         .SetFillColor( kOrange + 10 ) 
    Bi214         .SetFillColor( kGreen  +  0 ) 
    Radon         .SetFillColor( kAzure  +  1 ) 
    Externals     .SetFillColor( kOrange +  0 ) 
    K40           .SetFillColor( kViolet +  1 ) 
    Pa234m        .SetFillColor( kViolet +  0 ) 	
    Bi210         .SetFillColor( kGreen  +  2 ) 
    Cd116_2b2n_m14.SetFillColor( kViolet + 10 ) 
    
    # Rebin
    if obs == "BDT" :
        Tl208         .Rebin()
        Bi214         .Rebin()
        Radon         .Rebin()
        Externals     .Rebin()
        K40           .Rebin()
        Pa234m        .Rebin()
        Bi210         .Rebin()
        Cd116_2b2n_m14.Rebin()    
        Data          .Rebin()
        Signal        .Rebin()

    #Signal.SetLineColor(kGray+3) 
    Signal.SetLineColor(kRed) 
    Signal.SetLineWidth(2) 
    Signal.SetLineStyle(7) 
    
    # Set the Stack
    Stack = THStack("stack","stack") 
    Stack.Add( Tl208          ) 
    Stack.Add( Bi214          ) 
    Stack.Add( K40            ) 
    Stack.Add( Pa234m         ) 
    Stack.Add( Bi210          ) 
    Stack.Add( Radon          ) 
    Stack.Add( Externals      ) 
    Stack.Add( Cd116_2b2n_m14 ) 
    Stack.Add( Signal         ) 
    
    hsum = Cd116_2b2n_m14.Clone("hsum") 
    hsum.Add (Tl208    ) 
    hsum.Add (Bi214    ) 
    hsum.Add (Radon    ) 
    hsum.Add (Externals) 
    hsum.Add (K40      ) 
    hsum.Add (Pa234m   ) 
    hsum.Add (Bi210    ) 
    	
    canvas = TCanvas("BDT", "BDT", 500, 500) 

    
    h_title = HistoTitle
    
    if obs == "BDT" :
        #h_title = "BDT Score (%s)" % Label[model]
        h_x_title = "BDT Score"
    elif obs == "E" :
        #h_title = "Total energy" + " (%s)" % Label[model]
        h_x_title = "E_{Tot} (MeV)"
            
    _LogScale = kTRUE 
    _Grid = kFALSE
    _MarkerStyle = 20 
    _MarkerSize  = 0.8 
    _MarkerColor = kBlack 
    
    gStyle.SetTitleBorderSize(0) 
    gStyle.SetLegendBorderSize(0)
    
    # Upper plot will be in pad1                                               
    pad1 = TPad("pad1", "pad1", 0, 0.40, 1, 1.0) 
    pad1.SetGrid(_Grid, _Grid)
    pad1.SetLogy( _LogScale ) 
    pad1.SetTickx() 
    pad1.SetTicky() 
    pad1.SetTopMargin(0.15)  
    pad1.SetBottomMargin(0.01)  
    pad1.SetRightMargin(0.05)  
    pad1.Draw() 
    pad1.cd() 
        
    #gStyle.SetTitleFont(43,"") 
    Data.SetTitle(h_title)
    Data.SetLineWidth(2) 
    Data.SetMarkerColor( _MarkerColor ) 
    Data.SetMarkerStyle( _MarkerStyle ) 	
    Data.SetMarkerSize( _MarkerSize ) 
    Data.SetStats(kFALSE) 
    Data.GetXaxis().SetTitle(h_x_title) 
    Data.GetYaxis().SetTitle("No.Events") 
    Data.GetYaxis().CenterTitle(kTRUE) 
    Data.GetXaxis().CenterTitle(kTRUE) 
    Data.GetYaxis().SetRangeUser(1e-1,5e+3) 
        
    canvas.cd() 	
    pad2 = TPad("pad2", "pad2", 0, 0.25, 1, 0.40) 
    pad2.SetGrid(_Grid, _Grid)
    pad2.SetTopMargin(0.1) 
    pad2.SetBottomMargin(0.01) 
    pad2.SetRightMargin(0.05)  
    pad2.SetTickx() 
    pad2.SetTicky() 
    pad2.Draw() 
    pad2.cd() 
    
    hratio = Data.Clone( "ratio_%s" % Data.GetName() ) 
    hratio.SetTitle("") 
    hratio.Divide(hsum) 
    	
    hratio.GetYaxis().SetNdivisions(505)   	
    hratio.GetYaxis().SetTitle("Data/MC")   
    hratio.GetYaxis().CenterTitle(kTRUE) 
    hratio.GetYaxis().SetRangeUser(0.,5.) 
    
    canvas.cd() 	
    pad3 = TPad("pad3", "pad3", 0, 0.01, 1, 0.25) 
    pad3.SetGrid(_Grid, _Grid)
    pad3.SetTopMargin(0.1) 
    pad3.SetBottomMargin(0.4) 
    pad3.SetRightMargin(0.05)  
    pad3.SetTickx() 
    pad3.SetTicky() 
    pad3.Draw() 
    
    hres = Data.Clone( "residuals_%s" % Data.GetName() ) 
    hres.SetTitle("") 
    hres.Add(hsum, -1) 
    
    for i in range(1, hratio.GetNbinsX()+1):
    
    	if hratio.GetBinError(i) == 0:
             continue 
    	
    	hres.SetBinContent(i, hres.GetBinContent(i) / TMath.Sqrt( Data.GetBinContent(i) ) ) 
    	hres.SetBinError(i, TMath.Sqrt( TMath.Abs(hres.GetBinContent(i)) ) ) 
    
    hres.GetYaxis().SetNdivisions(505)   
    hres.GetYaxis().SetTitle("Residuals")   
    hres.GetYaxis().CenterTitle(kTRUE) 
    hres.GetYaxis().SetRangeUser(-5.0,5.0) 
        
    _chi2  = 0  
    _ndf   = 0  
    _igood = 0 
    
    Data.Chi2Test(hsum, "PUW")  
    #_pval = Data.Chi2TestX(hsum, _chi2, _ndf, _igood, "PUW")  
    #_ks = Data.KolmogorovTest(hsum,"D")  
    
    leg = 0

    if obs == "BDT" and min == None and max == None  :
        leg = TLegend(0.20,0.8,0.40,0.35) 
    elif obs == "BDT" and min != None and max != None :
        leg = TLegend(0.66,0.8,0.92,0.42)         
    elif obs == "E" :
        leg = TLegend(0.66,0.8,0.92,0.42) 

    leg.SetNColumns(2)
    leg.SetLineWidth(0)

    leg.AddEntry( Cd116_2b2n_m14 , "2#nu#beta#beta"                 , "F"  ) 
    leg.AddEntry( Externals      , "Externals"                      , "F"  ) 
    leg.AddEntry( Radon          , "Radon"                          , "F"  ) 
    leg.AddEntry( Bi210          , "Bi210"                          , "F"  ) 
    leg.AddEntry( Pa234m         , "Pa234m"                         , "F"  ) 
    leg.AddEntry( K40            , "K40"                            , "F"  ) 
    leg.AddEntry( Bi214          , "Bi214"                          , "F"  ) 			
    leg.AddEntry( Tl208          , "Tl208"                          , "F"  ) 
    leg.AddEntry( Data           , "Data"                           , "PL" ) 
    leg.AddEntry( Signal         , "0#nu#beta#beta " + Label[model] , "F"  ) 
   
    pad1.cd()     
    Data.Draw("") 
    Stack.Draw("A,SAME,HIST")
    Data.Draw("SAME") 
    #Signal.Draw("SAME,HIST") 
    pad2.cd() 
    hratio.Draw("P0") 
    pad3.cd() 
    hres.Draw("P0") 
    pad1.cd() 
    leg.Draw() 
    
    # Zoom over X axis
    if min != None and max != None:
        Data.GetXaxis().SetRangeUser(min, max)
        hratio.GetXaxis().SetRangeUser(min, max)
        hres.GetXaxis().SetRangeUser(min, max)
    
    if zoom:
        Data.GetYaxis().SetRangeUser(1e-1,5e2)
        gROOT.GetSelectedPad().Print("plots/%s_%s_zoom.pdf" % (obs, model) )
    else:
        gROOT.GetSelectedPad().Print("plots/%s_%s.pdf" % (obs, model) )
    
    pad1.Delete()
    pad2.Delete()
    pad3.Delete()

    bkg_dict = {
    "2#nu#beta#beta" :  Cd116_2b2n_m14 ,
    "Externals"      :  Externals      ,
    "Radon"          :  Radon          ,
    "Bi210"          :  Bi210          ,
    "Pa234m"         :  Pa234m         ,
    "K40"            :  K40            ,
    "Bi214"          :  Bi214          ,
    "Tl208"          :  Tl208          } 
     
    print [Signal, hsum, bkg_dict] 
     
    return [Signal, hsum, bkg_dict]        

###########################################################################
###########################################################################
def DrawSignalEffOverBkg(sig, bkg, bkg_dict, min = None, max = None):

    # signal / Sqrt(Integrated background) histogram
    g_sig_over_bkg = sig.Clone("sig_over_bkg")
    g_sig_over_bkg.Reset()        

    # Total integrated background histogram
    g_bkg = bkg.Clone("bkg")
    g_bkg.Reset()
    g_bkg.SetStats(False)
    
    bkg_int_dict = dict()
    
    for key in bkg_list:
        temp = bkg_list[key].Clone( )
        temp.Reset()
        bkg_int_dict[key] = temp

    # Integrated 
    for i in range(0, sig.GetNbinsX()):
        
        _sig_eff = sig.Integral(i, sig.GetNbinsX()) / sig.Integral(1, sig.GetNbinsX())
        _bkg = bkg.Integral(i, sig.GetNbinsX())

        # Signal efficiency / Sqrt(Bkg)
        if _bkg != 0:
            g_sig_over_bkg.SetBinContent(i, _sig_eff / sqrt(_bkg) )
        else:
            g_sig_over_bkg.SetBinContent(i, 0 )
        
        g_bkg.SetBinContent(i, _bkg)
        
        # Stack integrated background
        for key in bkg_int_dict:                    
            bkg_int_dict[key].SetBinContent( i , bkg_dict[key].Integral(i, sig.GetNbinsX()) )
        
    # Draw the thing
    canvas = TCanvas("BDT", "BDT", 500, 500) 
    
    g_bkg.Draw()
    g_bkg.GetXaxis().SetTitleOffset (2.0)
    
    
    # Integrated background stack
    g_stack = THStack("stack","stack") 
    g_stack.Add( bkg_int_dict[ "Tl208"          ] ) 
    g_stack.Add( bkg_int_dict[ "Bi214"          ] ) 
    g_stack.Add( bkg_int_dict[ "K40"            ] ) 
    g_stack.Add( bkg_int_dict[ "Pa234m"         ] ) 
    g_stack.Add( bkg_int_dict[ "Bi210"          ] ) 
    g_stack.Add( bkg_int_dict[ "Radon"          ] ) 
    g_stack.Add( bkg_int_dict[ "Externals"      ] ) 
    g_stack.Add( bkg_int_dict[ "2#nu#beta#beta" ] ) 
    g_stack.Draw("same")
        
    # Scale histogram & Draw
    rightmax = g_sig_over_bkg.GetMaximum()
    leftmax = g_bkg.GetBinContent( g_sig_over_bkg.FindBin(min) )
    scale = leftmax/rightmax

    g_sig_over_bkg.Scale(scale)
    g_sig_over_bkg.Draw("same")
    g_sig_over_bkg.SetLineWidth(2)
    g_sig_over_bkg.SetLineColor(kRed)       

    # Zoom over X axis
    if min != None and max != None:
        g_bkg.GetXaxis().SetRangeUser(min,max)
        g_stack.GetXaxis().SetRangeUser(min,max)
        g_sig_over_bkg.GetXaxis().SetRangeUser(min,max)

    # Set titles
    g_sig_over_bkg.SetTitle("; Lower cut value; Signal efficiency / Sqrt(Integrated background)")
    g_bkg.SetTitle("; Lower cut value; Integrated Background")
    g_stack.SetTitle("; Lower cut value; Integrated Background")

    # Draw new left axis
    axis = TGaxis(gPad.GetUxmax(),gPad.GetUymin(),gPad.GetUxmax(), gPad.GetUymax(),0,rightmax,510,"+L")
    axis.SetTitle("Signal efficiency / Sqrt(Integrated background)")
    axis.SetTitleColor  (g_sig_over_bkg.GetLineColor()   )
    axis.SetLabelColor  (g_sig_over_bkg.GetLineColor()   )
    axis.SetLineColor   (g_sig_over_bkg.GetLineColor()   )
    axis.SetLabelFont   (g_sig_over_bkg.GetLabelFont()   )
    axis.SetLabelSize   (g_sig_over_bkg.GetLabelSize()   )
    axis.SetLabelOffset (g_sig_over_bkg.GetLabelOffset() )
    axis.SetTitleFont   (g_sig_over_bkg.GetTitleFont()   )
    axis.SetTitleSize   (g_sig_over_bkg.GetTitleSize()   )
    axis.SetTitleOffset (2.0)

    axis.Draw("same")
    
    leg = TLegend(0.60,0.8,0.80,0.35) 
    
    leg.AddEntry( bkg_int_dict[ "Tl208"          ], "Tl208"               , "F" ) 
    leg.AddEntry( bkg_int_dict[ "Bi214"          ], "Bi214"               , "F" ) 
    leg.AddEntry( bkg_int_dict[ "K40"            ], "K40"                 , "F" ) 
    leg.AddEntry( bkg_int_dict[ "Pa234m"         ], "Pa234m"              , "F" ) 
    leg.AddEntry( bkg_int_dict[ "Bi210"          ], "Bi210"               , "F" ) 
    leg.AddEntry( bkg_int_dict[ "Radon"          ], "Radon"               , "F" ) 
    leg.AddEntry( bkg_int_dict[ "Externals"      ], "Externals"           , "F" ) 
    leg.AddEntry( bkg_int_dict[ "2#nu#beta#beta" ], "2#nu#beta#beta"      , "F" ) 
    leg.AddEntry( g_sig_over_bkg                  , "Sig. Eff / #sqrt(B)" , "L" ) 
        
    leg.Draw()     

    gPad.SetRightMargin(0.15)
    
    canvas.Update()
    
    gROOT.GetSelectedPad().Print("plots/sig_over_bkg_%s_%s.pdf" % (args.observable,args.model) )  
    
    # Print some informations
    max_bin = g_sig_over_bkg.GetMaximumBin()

    print "Max Eff / Sqrt(B) : %.2f" % g_sig_over_bkg.GetMaximum()    
    print "Max Eff / Sqrt(B) @ : %.2f" % g_sig_over_bkg.GetBinLowEdge(max_bin)
    print ""
    
    print "{0:15}".format("Tl208"          ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Tl208"         ].GetBinContent(max_bin))
    print "{0:15}".format("Bi214"          ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Bi214"         ].GetBinContent(max_bin))
    print "{0:15}".format("K40"            ) + ":" +  "{0:10.2f}".format(bkg_int_dict["K40"           ].GetBinContent(max_bin))
    print "{0:15}".format("Pa234m"         ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Pa234m"        ].GetBinContent(max_bin))
    print "{0:15}".format("Bi210"          ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Bi210"         ].GetBinContent(max_bin))
    print "{0:15}".format("Radon"          ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Radon"         ].GetBinContent(max_bin))
    print "{0:15}".format("Externals"      ) + ":" +  "{0:10.2f}".format(bkg_int_dict["Externals"     ].GetBinContent(max_bin))
    print "{0:15}".format("2#nu#beta#beta" ) + ":" +  "{0:10.2f}".format(bkg_int_dict["2#nu#beta#beta"].GetBinContent(max_bin))        
    print ""
    print "{0:15}".format("Tot bkg."       ) + ":" +  "{0:10.2f}".format(g_bkg.GetBinContent(max_bin))
    
    raw_input('wait...')
    
    return [g_bkg, g_stack, g_sig_over_bkg]
    
###########################################################################
###########################################################################


###########################################################################
###########################################################################
#def DrawEfficiency(sig, bkg, stack, obs): 
    
    #sig = Signal.Clone("sig") 
    #bkg = hsum.Clone("bkg") 
    
    #sig.Scale( 1000. / sig.Integral() )
    sig.GetXaxis().SetTitleOffset(2.);

    sig.SetStats(kFALSE) 

    if obs == "BDT":
        sig.Rebin(2)
        bkg.Rebin(2)

    _x = list()
    _sig_eff = list()
    _sig_bkg = list()    
    _bkg_eff = list()
    _bkg     = list()
    
    g_sig_eff = sig.Clone("sig_eff")
    g_sig_eff.Reset()
    g_sig_eff.SetTitle("; Lower cut value; Efficiency")
    g_sig_eff.SetLineColor(kBlue)
    g_sig_eff.SetLineWidth(3)
    
    g_bkg_eff = sig.Clone("bkg_eff")
    g_bkg_eff.Reset()
    g_bkg_eff.SetTitle("; Lower cut value; Efficiency")
    g_bkg_eff.SetLineWidth(3)
    g_bkg_eff.SetLineColor(kRed)    

    g_bkg = THStack("g_bkg","")
    #g_bkg.Reset()
    g_bkg.SetTitle("; Lower cut value; Background counts")
    #g_bkg.SetLineWidth(3)
    #g_bkg.SetLineColor(kBlack)       
    g_bkg_tot = bkg.Clone("bkg_tot")
    g_bkg_tot.Reset()

    g_sig_over_bkg = sig.Clone("sig_over_bkg")
    g_sig_over_bkg.Reset()
    g_sig_over_bkg.SetTitle("; Lower cut value; Signal efficiency / Sqrt(Background counts)")
    g_sig_over_bkg.SetLineWidth(3)
    g_sig_over_bkg.SetLineColor(kBlack)       

    for key in stack.GetStack():

        temp = key.Clone( )
        temp.Reset()
        g_bkg.Add(temp)
    
    for i in range(0, sig.GetNbinsX()):
        
        _x.append( sig.GetBinCenter(i+1) )
        _sig_eff.append( sig.Integral(i+1, sig.GetNbinsX()) / sig.Integral(1, sig.GetNbinsX()) )
        _bkg_eff.append( bkg.Integral(i+1, sig.GetNbinsX()) / bkg.Integral(1, sig.GetNbinsX()) )
        _bkg.append( bkg.Integral(i+1, sig.GetNbinsX()) )
        
        for key in stack.GetStack():
            
            g_bkg.GetStack().FindObject( key.GetName() ).SetBinContent( i+1 , key.Integral(i+1, sig.GetNbinsX()) )
            g_bkg.GetStack().FindObject( key.GetName() ).SetBinError( i+1, 0)
        
        if _bkg[-1] != 0:
            _sig_bkg.append( _sig_eff[-1] / sqrt(_bkg[-1]) )
        else:
            _sig_bkg.append( 0 )
    
    
        g_sig_eff.Fill( _x[-1], _sig_eff[-1])
        g_sig_eff.SetBinError( i, 0)

        g_bkg_eff.Fill( _x[-1], _bkg_eff[-1])
        g_bkg_eff.SetBinError( i, 0)

        g_bkg_tot.Fill( _x[-1], _bkg[-1])
        g_bkg_tot.SetBinError( i, 0)

        g_sig_over_bkg.Fill( _x[-1], _sig_bkg[-1] )
        g_sig_over_bkg.SetBinError( i, 0)

    
    x = np.array( _x )
    sig_eff = np.array( _sig_eff )
    bkg_eff = np.array( _bkg_eff )
    sig_bkg = np.array( _sig_bkg )  
    bkg = np.array( _bkg )      

    print "{0:15s}".format("S eff."),     "|", "{0:15s}".format("B eff."),                                          "|", "{0:15s}".format("S eff / B "),                                      "|", "{0:12s}".format("B"),                                      "|", "{0:10s}".format("Cut th.")    
    print "{0:15.3f}".format(100*1.00),   "|", "{0:15.3f}".format(100*bkg_eff[np.min(np.where( sig_eff <= 1.00 ))]), "|", "{0:15.3f}".format(1.00 / bkg[np.min(np.where( sig_eff <= 1.00 ))]), "|", "{0:12.2f}".format(bkg[np.min(np.where( sig_eff <= 1.00 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff <= 1.00 ))] )    
    print "{0:15.3f}".format(100*0.99),   "|", "{0:15.3f}".format(100*bkg_eff[np.min(np.where( sig_eff <= 0.99 ))]), "|", "{0:15.3f}".format(0.99 / bkg[np.min(np.where( sig_eff <= 0.99 ))]), "|", "{0:12.2f}".format(bkg[np.min(np.where( sig_eff <= 0.99 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff <= 0.99 ))] )
    print "{0:15.3f}".format(100*0.95),   "|", "{0:15.3f}".format(100*bkg_eff[np.min(np.where( sig_eff <= 0.95 ))]), "|", "{0:15.3f}".format(0.95 / bkg[np.min(np.where( sig_eff <= 0.95 ))]), "|", "{0:12.2f}".format(bkg[np.min(np.where( sig_eff <= 0.95 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff <= 0.95 ))] )
    print "{0:15.3f}".format(100*0.90),   "|", "{0:15.3f}".format(100*bkg_eff[np.min(np.where( sig_eff <= 0.90 ))]), "|", "{0:15.3f}".format(0.90 / bkg[np.min(np.where( sig_eff <= 0.90 ))]), "|", "{0:12.2f}".format(bkg[np.min(np.where( sig_eff <= 0.90 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff <= 0.90 ))] )
    #print "{0:10.3f}".format(0.80),   "|", "{0:10.3f}".format(bkg_eff[np.min(np.where( sig_eff < 0.80 ))]), "|", "{0:10.3f}".format(0.80 / bkg_eff[np.min(np.where( sig_eff < 0.80 ))]), "|", "{0:12.2f}".format(sig_sig[np.min(np.where( sig_eff < 0.80 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff < 0.80 ))] )
    #print "{0:10.3f}".format(0.50),   "|", "{0:10.3f}".format(bkg_eff[np.min(np.where( sig_eff < 0.50 ))]), "|", "{0:10.3f}".format(0.50 / bkg_eff[np.min(np.where( sig_eff < 0.50 ))]), "|", "{0:12.2f}".format(sig_sig[np.min(np.where( sig_eff < 0.50 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff < 0.50 ))] )
    #print "{0:10.3f}".format(0.20),   "|", "{0:10.3f}".format(bkg_eff[np.min(np.where( sig_eff < 0.20 ))]), "|", "{0:10.3f}".format(0.20 / bkg_eff[np.min(np.where( sig_eff < 0.20 ))]), "|", "{0:12.2f}".format(sig_sig[np.min(np.where( sig_eff < 0.20 ))]), "|", "{0:10.2f}".format(x[np.min(np.where( sig_eff < 0.20 ))] )        
    
    g_sig_bkg = TGraph(sig.GetNbinsX(), sig_eff, bkg)
    g_sig_bkg.SetLineWidth(3)
    g_sig_bkg.SetLineColor(kBlack)   
    
    print "\n"
    print "Signal efficiency / Bkg. (max) = %.2f @ %.2f (MeV or BDT score), Bkg. = %.2f" % (g_sig_over_bkg.GetMaximum(), g_sig_over_bkg.GetBinLowEdge(g_sig_over_bkg.GetMaximumBin()), g_bkg_tot.GetBinContent(g_sig_over_bkg.GetMaximumBin()))
        
    return [g_sig_eff, g_bkg_eff, g_bkg, g_sig_over_bkg, g_sig_bkg]

   #if args.observable == 'ALL':
   #
   #    [sig_bdt, bkg_bdt, stack] = DrawObservable(args.model, "BDT")    
   #    [g_sig_eff_bdt, g_bkg_eff_bdt, g_bkg_bdt, g_sig_over_bkg_bdt, g_sig_bkg_bdt] = DrawEfficiency(sig_bdt,bkg_bdt, stack, "BDT")
   #
   #    [sig_e, bkg_e, stack] = DrawObservable(args.model, "E")    
   #    [g_sig_eff_e, g_bkg_eff_e, g_bkg, g_sig_over_bkg_bdt, g_sig_bkg_e] = DrawEfficiency(sig_e,bkg_e, stack, "E")
   #
   #    c_bkg = TCanvas()
   #    c_bkg.SetLogy(True)
   #    g_sig_bkg_bdt.SetTitle("")
   #    g_sig_bkg_bdt.GetYaxis().SetRangeUser(1, 10000)
   #    g_sig_bkg_bdt.GetXaxis().SetRangeUser(0.2, 1.)                
   #
   #    g_sig_bkg_bdt.Draw("")
   #
   #    g_sig_bkg_bdt.SetLineColor(kBlue)
   #    g_sig_bkg_bdt.GetXaxis().SetTitle("Signal Efficiency")
   #    g_sig_bkg_bdt.GetYaxis().SetTitle("Num. of Background evt.")
   #
   #    g_sig_bkg_e.Draw("same")
   #    g_sig_bkg_e.SetLineColor(kRed)
   #    c_bkg.Update()
   #    
   #    gROOT.GetSelectedPad().Print("plots/bkg_eff_%s.pdf" % (args.model) )
   #    
   #else: 
   #
   #    [sig, bkg, stack] = DrawObservable(args.model, args.observable)    
   #    [g_sig_eff, g_bkg_eff, g_bkg, g_sig_over_bkg, g_sig_bkg] = DrawEfficiency(sig,bkg,stack,args.observable)
   #
   ## Calculate Signal Efficiency / Sqrt (Background count) vs Low edge cut
   #g_bkg = THStack("g_bkg","")
   #g_bkg.SetTitle("; Lower cut value; Background counts")
   #g_bkg_tot = hsum.Clone("bkg_tot")
   #g_bkg_tot.Reset()
   #
   #g_sig_over_bkg = Signal.Clone("sig_over_bkg")
   #g_sig_over_bkg.Reset()
   #g_sig_over_bkg.SetTitle("; Lower cut value; Signal efficiency / Sqrt(Background counts)")
   #g_sig_over_bkg.SetLineWidth(3)
   #g_sig_over_bkg.SetLineColor(kBlack)       
   #
   #for key in Stack.GetStack():
   #
   #    temp = key.Clone( )
   #    temp.Reset()
   #    g_bkg.Add(temp)
   #
   #for i in range(0, Signal.GetNbinsX()):
   #    
   #    _sig_eff = Signal.Integral(i+1, Signal.GetNbinsX()) / Signal.Integral(1, Signal.GetNbinsX())
   #    _bkg = hsum.Integral(i+1, Signal.GetNbinsX())
   #         
   #    for key in Stack.GetStack():
   #        
   #        g_bkg.GetStack().FindObject( key.GetName() ).SetBinContent( i+1 , key.Integral(i+1, Signal.GetNbinsX()) )
   #        g_bkg.GetStack().FindObject( key.GetName() ).SetBinError( i+1, 0)
   #
   #    if _bkg != 0:
   #        g_sig_over_bkg.SetBinContent(i+1, _sig_eff / sqrt(_bkg) )
   #
   #canvas1 = TCanvas("", "", 500, 500) 
   #
   #g_min = 2
   #g_max = 3.4
   #
   #if args.observable == "BDT":
   #    g_min = 0
   #    g_max = 0.4       
   #
   #g_sig_over_bkg.Draw()
   #g_sig_over_bkg.GetXaxis().SetRangeUser(g_min,g_max)
   #g_sig_over_bkg.SetLineColor(kRed)
   #
   #rightmax = 1.05*hsum.Integral(hsum.FindBin(g_min),hsum.FindBin(g_max) )
   #scale = gPad.GetUymax()/rightmax
   #
   #for key in g_bkg.GetStack():
   #    key.Scale(scale)
   #
   #g_bkg.Draw("same")
   #g_sig_over_bkg.Draw("same")
   #
   #axis = TGaxis(gPad.GetUxmax(),gPad.GetUymin(),gPad.GetUxmax(), gPad.GetUymax(),0,rightmax,510,"+L")
   #axis.SetTitle("Background counts")
   #axis.SetLabelFont   (g_sig_over_bkg.GetLabelFont()   )
   #axis.SetLabelSize   (g_sig_over_bkg.GetLabelSize()   )
   #axis.SetLabelOffset (g_sig_over_bkg.GetLabelOffset() )
   #axis.SetTitleFont   (g_sig_over_bkg.GetTitleFont()   )
   #axis.SetTitleSize   (g_sig_over_bkg.GetTitleSize()   )
   #axis.SetTitleOffset (1.5)
   #axis.Draw("same")
   #leg.Draw() 
   #canvas1.Update()
   #
   #raw_input("wait...")
   #
   #gROOT.GetSelectedPad().Print("plots/sig_over_bkg_%s_%s.pdf" % (args.observable,args.model) )
   #
   #
   #
   #
   #    #for h in stack.GetStack():
   #    #    
   #    #    print h.GetName() + " " + str(h.Integral(0, 46))
   #    #
   #    #raw_input("wait...")
   #
   #
   #    c_eff = TCanvas()
   #    g_sig_eff.Draw("")
   #    g_bkg_eff.Draw("same")
   #    c_eff.Update()
   #    gROOT.GetSelectedPad().Print("plots/eff_%s_%s.pdf" % (args.observable,args.model) )
   #
   #    c_bkg = TCanvas()
   #    g_sig_bkg.Draw("AL")
   #    c_bkg.Update()
   #
   #    c_bkg_1 = TCanvas()
   #    c_bkg_1.SetLogy(True)
   #    #g_bkg.GetYaxis().SetRangeUser(0.1, 1e4)
   #    g_bkg.Draw()
   #    c_bkg_1.Update()
   #    
   #raw_input("wait...")

###########################################################################
###########################################################################
if __name__ == "__main__":
      
    # Draw En/BDT full axis
    # Draw En/BDT zoom
    if args.observable == "E":
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=0.6, max=3.4)     
    elif args.observable == "BDT" and re.match("M([0-9])", args.model) == None:                                       
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=-0.35, max=0.35)     
    else:                                       
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=-0.35, max=0.6)     

    raw_input('wait...')
    
    # Draw En/BDT zoom
    if args.observable == "E":
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=2.0, max=3.2, zoom=True)
    elif args.observable == "BDT" and re.match("M([0-9])", args.model) == None:                                       
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=0.0, max=0.35, zoom=True)     
    else:
        [sig, bkg, bkg_list] = DrawObservable(args.model, args.observable,Norm90CL[args.observable][args.model], min=0.3, max=0.6, zoom=True)     
        
    raw_input('wait...')
    
    # Draw Signal Efficiency / Sqrt (Integrated background)
    if args.observable == "E":
        DrawSignalEffOverBkg(sig, bkg, bkg_list, min = 2.0, max = 3.2)
    elif args.observable == "BDT":
        DrawSignalEffOverBkg(sig, bkg, bkg_list, min = 0.0, max = 0.5)
            
    raw_input('wait...')        
        