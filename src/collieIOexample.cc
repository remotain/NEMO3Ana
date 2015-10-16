#include "CollieIOFile.hh"
#include "TRandom.h"

int main(int argc, char* argv[]) {
  
  /////////////////////////////////////////
  ///Create IO file with input parameters
  /////////////////////////////////////////
  CollieIOFile* cfile = new CollieIOFile();
  // Specify outputfile and channel name  
  
  cfile->initFile("/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/CollieIO.root", "BDT_Score");  

  // Define your input histograms
  double Xmin = -0.8; 
  double Xmax = 0.8;
  int Nbins = 100;
  //

  cfile->setInputHist(Xmin,Xmax,Nbins);
  
  // Option to define physical cutoffs where events should not exist (in terms of your historam range)
  //
  //  cfile->setCutoffs(0.0,1.0);   
  
  // Option to rebin histograms to a coarser binning
  // Eg, rebinning by 2 reduces to 10 bins
  //
  cfile->setRebin(1);
  
  // Option to smooth histograms
  // Don't smooth unless you know what you're doing
  //
  //  cfile->setSmooth(false);
  
  // Average number of `histogram entries for smoothing purposes (default=50k)
  // The value doesn't matter if you're not smoothing.
  //
  //  cfile->setHistNorm(50000);

  //Define backgrounds
  vector<string> bkgdNames;

  //bkgdNames.push_back("Cd116_Tl208");      
  //bkgdNames.push_back("Cd116_Ac228");      
  //bkgdNames.push_back("Cd116_Bi212");      
  //bkgdNames.push_back("Cd116_Bi214");      
  //bkgdNames.push_back("Cd116_Pb214");      
  //bkgdNames.push_back("Mylar_Bi214");      
  //bkgdNames.push_back("Mylar_Pb214");      
  //bkgdNames.push_back("Cd116_K40_cold"); 
  //bkgdNames.push_back("Cd116_K40_warm"); 
  //bkgdNames.push_back("Cd116_Pa234m_cold");
  //bkgdNames.push_back("Cd116_Pa234m_warm");
  //bkgdNames.push_back("SFoil_Bi210_cold");      
  //bkgdNames.push_back("SFoil_Bi210_warm");      
  //bkgdNames.push_back("SWire_Bi210_P1"); 
  //bkgdNames.push_back("SWire_Bi210_P2"); 
  //bkgdNames.push_back("SScin_Bi210");      
  //bkgdNames.push_back("SScin_Bi214");      
  //bkgdNames.push_back("SWire_Tl208_P1"); 
  //bkgdNames.push_back("SWire_Tl208_P2"); 
  //bkgdNames.push_back("SWire_Bi214_P1"); 
  //bkgdNames.push_back("SWire_Bi214_P2"); 
  //bkgdNames.push_back("SFoil_Bi214_P1"); 
  //bkgdNames.push_back("SFoil_Bi214_P2"); 
  //bkgdNames.push_back("SWire_Pb214_P1"); 
  //bkgdNames.push_back("SWire_Pb214_P2"); 
  //bkgdNames.push_back("SFoil_Pb214_P1"); 
  //bkgdNames.push_back("SFoil_Pb214_P2"); 
  //bkgdNames.push_back("FeShield_Bi214");   
  //bkgdNames.push_back("FeShield_Tl208");   
  //bkgdNames.push_back("FeShield_Ac228");   
  //bkgdNames.push_back("CuTower_Co60");     
  //bkgdNames.push_back("Air_Bi214_P1");     
  //bkgdNames.push_back("PMT_Bi214");        
  //bkgdNames.push_back("PMT_Tl208");        
  //bkgdNames.push_back("PMT_Ac228");        
  //bkgdNames.push_back("PMT_K40");          
  //bkgdNames.push_back("ScintInn_K40");     
  //bkgdNames.push_back("ScintOut_K40");     
  //bkgdNames.push_back("ScintPet_K40");     
  //bkgdNames.push_back("MuMetal_Pa234m");   
  bkgdNames.push_back("Cd116_2b2n_m14");   
  
  cfile->createChannel(bkgdNames);
  
  
  //// For this example, generate backgrounds, signal, data, and systematics
  //TH1D* bkgd1 = new TH1D("bkgd1","bkgd1",Nbins,Xmin,Xmax);
  //TH1D* bkgd2 = new TH1D("bkgd2","bkgd2",Nbins,Xmin,Xmax);
  //
  //TH1D* bkgd2SystP = new TH1D("bkgd2systP","bkgd2systP",Nbins,Xmin,Xmax);
  //TH1D* bkgd2SystN = new TH1D("bkgd2systN","bkgd2systN",Nbins,Xmin,Xmax);
  //
  //TH1D* sig = new TH1D("sig","sig",Nbins,Xmin,Xmax);
  //TH1D* sigSystP = new TH1D("sig_systP","sig_systP",Nbins,Xmin,Xmax);
  //TH1D* sigSystN = new TH1D("sig_systN","sig_systN",Nbins,Xmin,Xmax);
  //TH1D* data = new TH1D("data","data",Nbins,Xmin,Xmax);
  //
  //// Make sure you keep track of statistical uncertainties in histograms correctly
  //bkgd1->Sumw2();
  //bkgd2->Sumw2();
  //bkgd2SystP->Sumw2();
  //bkgd2SystN->Sumw2();
  //sig->Sumw2();
  //sigSystP->Sumw2();
  //sigSystN->Sumw2();
  //data->Sumw2();
  
  
  //Otherwise, get your input histograms from an external file
  
  TFile infile("/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TMVApp.root");
  
  TH1D* data = (TH1D*)infile.Get("Data_MVA_BDT");

  TH1D* sig = (TH1D*)infile.Get("Cd116_2b0n_m1_MVA_BDT");
  
  //TH1D * Cd116_Tl208       = (TH1D*) infile.Get("Cd116_Tl208_MVA_BDT")    ; Cd116_Tl208       -> Sumw2() ; Cd116_Tl208       -> Scale( 5.93799  ); 
  //TH1D * Cd116_Ac228       = (TH1D*) infile.Get("Cd116_Ac228_MVA_BDT")    ; Cd116_Ac228       -> Sumw2() ; Cd116_Ac228       -> Scale( 6.92654  ); 
  //TH1D * Cd116_Bi212       = (TH1D*) infile.Get("Cd116_Bi212_MVA_BDT")    ; Cd116_Bi212       -> Sumw2() ; Cd116_Bi212       -> Scale( 2.74751  ); 
  //TH1D * Cd116_Bi214       = (TH1D*) infile.Get("Cd116_Bi214_MVA_BDT")    ; Cd116_Bi214       -> Sumw2() ; Cd116_Bi214       -> Scale( 18.3589  ); 
  //TH1D * Cd116_Pb214       = (TH1D*) infile.Get("Cd116_Pb214_VT_MVA_BDT") ; Cd116_Pb214       -> Sumw2() ; Cd116_Pb214       -> Scale( 0.187229 ); 
  //TH1D * Mylar_Bi214       = (TH1D*) infile.Get("Mylar_Bi214_MVA_BDT")    ; Mylar_Bi214       -> Sumw2() ; Mylar_Bi214       -> Scale( 11.1957  ); 
  //TH1D * Mylar_Pb214       = (TH1D*) infile.Get("Mylar_Pb214_MVA_BDT")    ; Mylar_Pb214       -> Sumw2() ; Mylar_Pb214       -> Scale( 0.49351  ); 
  //TH1D * Cd116_K40_cold    = (TH1D*) infile.Get("Cd116_K40_MVA_BDT")      ; Cd116_K40_cold    -> Sumw2() ; Cd116_K40_cold    -> Scale( 9.02821  ); 
  //TH1D * Cd116_K40_warm    = (TH1D*) infile.Get("Cd116_K40_MVA_BDT")      ; Cd116_K40_warm    -> Sumw2() ; Cd116_K40_warm    -> Scale( 25.9862  ); 
  //TH1D * Cd116_Pa234m_cold = (TH1D*) infile.Get("Cd116_Pa234m_MVA_BDT")   ; Cd116_Pa234m_cold -> Sumw2() ; Cd116_Pa234m_cold -> Scale( 27.6202  ); 
  //TH1D * Cd116_Pa234m_warm = (TH1D*) infile.Get("Cd116_Pa234m_MVA_BDT")   ; Cd116_Pa234m_warm -> Sumw2() ; Cd116_Pa234m_warm -> Scale( 72.5556  ); 
  //TH1D * SFoil_Bi210_cold  = (TH1D*) infile.Get("SFoil_Bi210_MVA_BDT")    ; SFoil_Bi210_cold  -> Sumw2() ; SFoil_Bi210_cold  -> Scale( 0.  ); 
  //TH1D * SFoil_Bi210_warm  = (TH1D*) infile.Get("SFoil_Bi210_MVA_BDT")    ; SFoil_Bi210_warm  -> Sumw2() ; SFoil_Bi210_warm  -> Scale( 23.2433  );   
  //TH1D * SWire_Bi210_P1    = (TH1D*) infile.Get("SWire_Bi210_MVA_BDT")    ; SWire_Bi210_P1    -> Sumw2() ; SWire_Bi210_P1    -> Scale( 0.136145 ); 
  //TH1D * SWire_Bi210_P2    = (TH1D*) infile.Get("SWire_Bi210_MVA_BDT")    ; SWire_Bi210_P2    -> Sumw2() ; SWire_Bi210_P2    -> Scale( 0.624186 ); 
  //TH1D * SScin_Bi210       = (TH1D*) infile.Get("SScin_Bi210_MVA_BDT")    ; SScin_Bi210       -> Sumw2() ; SScin_Bi210       -> Scale( 1.75763  ); 
  //TH1D * SScin_Bi214       = (TH1D*) infile.Get("SScin_Bi214_MVA_BDT")    ; SScin_Bi214       -> Sumw2() ; SScin_Bi214       -> Scale( 0.0505381); 
  //TH1D * SWire_Tl208_P1    = (TH1D*) infile.Get("SWire_Tl208_MVA_BDT")    ; SWire_Tl208_P1    -> Sumw2() ; SWire_Tl208_P1    -> Scale( 0.217615 ); 
  //TH1D * SWire_Tl208_P2    = (TH1D*) infile.Get("SWire_Tl208_MVA_BDT")    ; SWire_Tl208_P2    -> Sumw2() ; SWire_Tl208_P2    -> Scale( 1.07721  ); 
  //TH1D * SWire_Bi214_P1    = (TH1D*) infile.Get("SWire_Bi214_MVA_BDT")    ; SWire_Bi214_P1    -> Sumw2() ; SWire_Bi214_P1    -> Scale( 21.4388  ); 
  //TH1D * SWire_Bi214_P2    = (TH1D*) infile.Get("SWire_Bi214_MVA_BDT")    ; SWire_Bi214_P2    -> Sumw2() ; SWire_Bi214_P2    -> Scale( 17.9663  ); 
  //TH1D * SFoil_Bi214_P1    = (TH1D*) infile.Get("SFoil_Bi214_MVA_BDT")    ; SFoil_Bi214_P1    -> Sumw2() ; SFoil_Bi214_P1    -> Scale( 5.7695   ); 
  //TH1D * SFoil_Bi214_P2    = (TH1D*) infile.Get("SFoil_Bi214_MVA_BDT")    ; SFoil_Bi214_P2    -> Sumw2() ; SFoil_Bi214_P2    -> Scale( 2.73967  ); 
  //TH1D * SWire_Pb214_P1    = (TH1D*) infile.Get("SWire_Pb214_MVA_BDT")    ; SWire_Pb214_P1    -> Sumw2() ; SWire_Pb214_P1    -> Scale( 0.457038 ); 
  //TH1D * SWire_Pb214_P2    = (TH1D*) infile.Get("SWire_Pb214_MVA_BDT")    ; SWire_Pb214_P2    -> Sumw2() ; SWire_Pb214_P2    -> Scale( 0.648715 ); 
  //TH1D * SFoil_Pb214_P1    = (TH1D*) infile.Get("SFoil_Pb214_MVA_BDT")    ; SFoil_Pb214_P1    -> Sumw2() ; SFoil_Pb214_P1    -> Scale( 0.215401 ); 
  //TH1D * SFoil_Pb214_P2    = (TH1D*) infile.Get("SFoil_Pb214_MVA_BDT")    ; SFoil_Pb214_P2    -> Sumw2() ; SFoil_Pb214_P2    -> Scale( 0.189179 ); 
  //TH1D * FeShield_Bi214    = (TH1D*) infile.Get("FeShield_Bi214_MVA_BDT") ; FeShield_Bi214    -> Sumw2() ; FeShield_Bi214    -> Scale( 50.1037  ); 
  //TH1D * FeShield_Tl208    = (TH1D*) infile.Get("FeShield_Tl208_MVA_BDT") ; FeShield_Tl208    -> Sumw2() ; FeShield_Tl208    -> Scale( 1.1935   ); 
  //TH1D * FeShield_Ac228    = (TH1D*) infile.Get("FeShield_Ac228_MVA_BDT") ; FeShield_Ac228    -> Sumw2() ; FeShield_Ac228    -> Scale( 0.176176 ); 
  //TH1D * CuTower_Co60      = (TH1D*) infile.Get("CuTower_Co60_MVA_BDT")   ; CuTower_Co60      -> Sumw2() ; CuTower_Co60      -> Scale( 3.79642  ); 
  //TH1D * Air_Bi214_P1      = (TH1D*) infile.Get("Air_Bi214_MVA_BDT")      ; Air_Bi214_P1      -> Sumw2() ; Air_Bi214_P1      -> Scale( 4.19156  ); 
  //TH1D * PMT_Bi214         = (TH1D*) infile.Get("PMT_Bi214_MVA_BDT")      ; PMT_Bi214         -> Sumw2() ; PMT_Bi214         -> Scale( 30.6795  ); 
  //TH1D * PMT_Tl208         = (TH1D*) infile.Get("PMT_Tl208_MVA_BDT")      ; PMT_Tl208         -> Sumw2() ; PMT_Tl208         -> Scale( 23.2697  ); 
  //TH1D * PMT_Ac228         = (TH1D*) infile.Get("PMT_Ac228_MVA_BDT")      ; PMT_Ac228         -> Sumw2() ; PMT_Ac228         -> Scale( 3.60937  ); 
  //TH1D * PMT_K40           = (TH1D*) infile.Get("PMT_K40_MVA_BDT")        ; PMT_K40           -> Sumw2() ; PMT_K40           -> Scale( 16.792   ); 
  //TH1D * ScintInn_K40      = (TH1D*) infile.Get("ScintInn_K40_MVA_BDT")   ; ScintInn_K40      -> Sumw2() ; ScintInn_K40      -> Scale( 0.33559  ); 
  //TH1D * ScintOut_K40      = (TH1D*) infile.Get("ScintOut_K40_MVA_BDT")   ; ScintOut_K40      -> Sumw2() ; ScintOut_K40      -> Scale( 0.604063 ); 
  //TH1D * ScintPet_K40      = (TH1D*) infile.Get("ScintPet_K40_MVA_BDT")   ; ScintPet_K40      -> Sumw2() ; ScintPet_K40      -> Scale( 1.00676  ); 
  //TH1D * MuMetal_Pa234m    = (TH1D*) infile.Get("MuMetal_Pa234m_MVA_BDT") ; MuMetal_Pa234m    -> Sumw2() ; MuMetal_Pa234m    -> Scale( 0.664017 ); 
  TH1D * Cd116_2b2n_m14    = (TH1D*) infile.Get("Cd116_2b2n_m14_MVA_BDT") ; Cd116_2b2n_m14    -> Sumw2() ; Cd116_2b2n_m14    -> Scale( 4913.49  ); 


	//TFile * infile = new TFile("/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TwoElectronIntHistos.root");
    //
	//TDirectory * fdir = 0;
	//fdir = (TDirectory *) infile->Get("Data"); fdir->cd();
	//TH1D* data = (TH1D*)fdir->Get("Data_h_tot_e_energy"); 
    //
	//fdir = (TDirectory *) infile->Get("Cd116_2b0n_m1"); fdir->cd();
	//TH1D* sig = (TH1D*)fdir->Get("Cd116_2b0n_m1_h_tot_e_energy"); 
    //
    //
	//fdir = (TDirectory *) infile->Get("Cd116_Tl208"   ); fdir->cd(); TH1D * Cd116_Tl208       = (TH1D*) fdir->Get("Cd116_Tl208_h_tot_e_energy"    ); /*Cd116_Tl208       -> Sumw2()*/ ; Cd116_Tl208       -> Scale( 5.93799  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Ac228"   ); fdir->cd(); TH1D * Cd116_Ac228       = (TH1D*) fdir->Get("Cd116_Ac228_h_tot_e_energy"    ); /*Cd116_Ac228       -> Sumw2()*/ ; Cd116_Ac228       -> Scale( 6.92654  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Bi212"   ); fdir->cd(); TH1D * Cd116_Bi212       = (TH1D*) fdir->Get("Cd116_Bi212_h_tot_e_energy"    ); /*Cd116_Bi212       -> Sumw2()*/ ; Cd116_Bi212       -> Scale( 2.74751  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Bi214"   ); fdir->cd(); TH1D * Cd116_Bi214       = (TH1D*) fdir->Get("Cd116_Bi214_h_tot_e_energy"    ); /*Cd116_Bi214       -> Sumw2()*/ ; Cd116_Bi214       -> Scale( 18.3589  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Pb214_VT"); fdir->cd(); TH1D * Cd116_Pb214       = (TH1D*) fdir->Get("Cd116_Pb214_VT_h_tot_e_energy" ); /*Cd116_Pb214       -> Sumw2()*/ ; Cd116_Pb214       -> Scale( 0.187229 ); 
	//fdir = (TDirectory *) infile->Get("Mylar_Bi214"   ); fdir->cd(); TH1D * Mylar_Bi214       = (TH1D*) fdir->Get("Mylar_Bi214_h_tot_e_energy"    ); /*Mylar_Bi214       -> Sumw2()*/ ; Mylar_Bi214       -> Scale( 11.1957  ); 
	//fdir = (TDirectory *) infile->Get("Mylar_Pb214"   ); fdir->cd(); TH1D * Mylar_Pb214       = (TH1D*) fdir->Get("Mylar_Pb214_h_tot_e_energy"    ); /*Mylar_Pb214       -> Sumw2()*/ ; Mylar_Pb214       -> Scale( 0.49351  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_K40"     ); fdir->cd(); TH1D * Cd116_K40_cold    = (TH1D*) fdir->Get("Cd116_K40_h_tot_e_energy"      ); /*Cd116_K40_cold    -> Sumw2()*/ ; Cd116_K40_cold    -> Scale( 9.02821  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_K40"     ); fdir->cd(); TH1D * Cd116_K40_warm    = (TH1D*) fdir->Get("Cd116_K40_h_tot_e_energy"      ); /*Cd116_K40_warm    -> Sumw2()*/ ; Cd116_K40_warm    -> Scale( 25.9862  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Pa234m"  ); fdir->cd(); TH1D * Cd116_Pa234m_cold = (TH1D*) fdir->Get("Cd116_Pa234m_h_tot_e_energy"   ); /*Cd116_Pa234m_cold -> Sumw2()*/ ; Cd116_Pa234m_cold -> Scale( 27.6202  ); 
	//fdir = (TDirectory *) infile->Get("Cd116_Pa234m"  ); fdir->cd(); TH1D * Cd116_Pa234m_warm = (TH1D*) fdir->Get("Cd116_Pa234m_h_tot_e_energy"   ); /*Cd116_Pa234m_warm -> Sumw2()*/ ; Cd116_Pa234m_warm -> Scale( 72.5556  ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Bi210"   ); fdir->cd(); TH1D * SFoil_Bi210_cold  = (TH1D*) fdir->Get("SFoil_Bi210_h_tot_e_energy"    ); /*SFoil_Bi210_cold  -> Sumw2()*/ ; SFoil_Bi210_cold  -> Scale( 0.       ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Bi210"   ); fdir->cd(); TH1D * SFoil_Bi210_warm  = (TH1D*) fdir->Get("SFoil_Bi210_h_tot_e_energy"    ); /*SFoil_Bi210_warm  -> Sumw2()*/ ; SFoil_Bi210_warm  -> Scale( 23.2433  ); 
	//fdir = (TDirectory *) infile->Get("SWire_Bi210"   ); fdir->cd(); TH1D * SWire_Bi210_P1    = (TH1D*) fdir->Get("SWire_Bi210_h_tot_e_energy"    ); /*SWire_Bi210_P1    -> Sumw2()*/ ; SWire_Bi210_P1    -> Scale( 0.136145 ); 
	//fdir = (TDirectory *) infile->Get("SWire_Bi210"   ); fdir->cd(); TH1D * SWire_Bi210_P2    = (TH1D*) fdir->Get("SWire_Bi210_h_tot_e_energy"    ); /*SWire_Bi210_P2    -> Sumw2()*/ ; SWire_Bi210_P2    -> Scale( 0.624186 ); 
	//fdir = (TDirectory *) infile->Get("SScin_Bi210"   ); fdir->cd(); TH1D * SScin_Bi210       = (TH1D*) fdir->Get("SScin_Bi210_h_tot_e_energy"    ); /*SScin_Bi210       -> Sumw2()*/ ; SScin_Bi210       -> Scale( 1.75763  ); 
	//fdir = (TDirectory *) infile->Get("SScin_Bi214"   ); fdir->cd(); TH1D * SScin_Bi214       = (TH1D*) fdir->Get("SScin_Bi214_h_tot_e_energy"    ); /*SScin_Bi214       -> Sumw2()*/ ; SScin_Bi214       -> Scale( 0.0505381); 
	//fdir = (TDirectory *) infile->Get("SWire_Tl208"   ); fdir->cd(); TH1D * SWire_Tl208_P1    = (TH1D*) fdir->Get("SWire_Tl208_h_tot_e_energy"    ); /*SWire_Tl208_P1    -> Sumw2()*/ ; SWire_Tl208_P1    -> Scale( 0.217615 ); 
	//fdir = (TDirectory *) infile->Get("SWire_Tl208"   ); fdir->cd(); TH1D * SWire_Tl208_P2    = (TH1D*) fdir->Get("SWire_Tl208_h_tot_e_energy"    ); /*SWire_Tl208_P2    -> Sumw2()*/ ; SWire_Tl208_P2    -> Scale( 1.07721  ); 
	//fdir = (TDirectory *) infile->Get("SWire_Bi214"   ); fdir->cd(); TH1D * SWire_Bi214_P1    = (TH1D*) fdir->Get("SWire_Bi214_h_tot_e_energy"    ); /*SWire_Bi214_P1    -> Sumw2()*/ ; SWire_Bi214_P1    -> Scale( 21.4388  ); 
	//fdir = (TDirectory *) infile->Get("SWire_Bi214"   ); fdir->cd(); TH1D * SWire_Bi214_P2    = (TH1D*) fdir->Get("SWire_Bi214_h_tot_e_energy"    ); /*SWire_Bi214_P2    -> Sumw2()*/ ; SWire_Bi214_P2    -> Scale( 17.9663  ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Bi214"   ); fdir->cd(); TH1D * SFoil_Bi214_P1    = (TH1D*) fdir->Get("SFoil_Bi214_h_tot_e_energy"    ); /*SFoil_Bi214_P1    -> Sumw2()*/ ; SFoil_Bi214_P1    -> Scale( 5.7695   ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Bi214"   ); fdir->cd(); TH1D * SFoil_Bi214_P2    = (TH1D*) fdir->Get("SFoil_Bi214_h_tot_e_energy"    ); /*SFoil_Bi214_P2    -> Sumw2()*/ ; SFoil_Bi214_P2    -> Scale( 2.73967  ); 
	//fdir = (TDirectory *) infile->Get("SWire_Pb214"   ); fdir->cd(); TH1D * SWire_Pb214_P1    = (TH1D*) fdir->Get("SWire_Pb214_h_tot_e_energy"    ); /*SWire_Pb214_P1    -> Sumw2()*/ ; SWire_Pb214_P1    -> Scale( 0.457038 ); 
	//fdir = (TDirectory *) infile->Get("SWire_Pb214"   ); fdir->cd(); TH1D * SWire_Pb214_P2    = (TH1D*) fdir->Get("SWire_Pb214_h_tot_e_energy"    ); /*SWire_Pb214_P2    -> Sumw2()*/ ; SWire_Pb214_P2    -> Scale( 0.648715 ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Pb214"   ); fdir->cd(); TH1D * SFoil_Pb214_P1    = (TH1D*) fdir->Get("SFoil_Pb214_h_tot_e_energy"    ); /*SFoil_Pb214_P1    -> Sumw2()*/ ; SFoil_Pb214_P1    -> Scale( 0.215401 ); 
	//fdir = (TDirectory *) infile->Get("SFoil_Pb214"   ); fdir->cd(); TH1D * SFoil_Pb214_P2    = (TH1D*) fdir->Get("SFoil_Pb214_h_tot_e_energy"    ); /*SFoil_Pb214_P2    -> Sumw2()*/ ; SFoil_Pb214_P2    -> Scale( 0.189179 ); 
	//fdir = (TDirectory *) infile->Get("FeShield_Bi214"); fdir->cd(); TH1D * FeShield_Bi214    = (TH1D*) fdir->Get("FeShield_Bi214_h_tot_e_energy" ); /*FeShield_Bi214    -> Sumw2()*/ ; FeShield_Bi214    -> Scale( 50.1037  ); 
	//fdir = (TDirectory *) infile->Get("FeShield_Tl208"); fdir->cd(); TH1D * FeShield_Tl208    = (TH1D*) fdir->Get("FeShield_Tl208_h_tot_e_energy" ); /*FeShield_Tl208    -> Sumw2()*/ ; FeShield_Tl208    -> Scale( 1.1935   ); 
	//fdir = (TDirectory *) infile->Get("FeShield_Ac228"); fdir->cd(); TH1D * FeShield_Ac228    = (TH1D*) fdir->Get("FeShield_Ac228_h_tot_e_energy" ); /*FeShield_Ac228    -> Sumw2()*/ ; FeShield_Ac228    -> Scale( 0.176176 ); 
	//fdir = (TDirectory *) infile->Get("CuTower_Co60"  ); fdir->cd(); TH1D * CuTower_Co60      = (TH1D*) fdir->Get("CuTower_Co60_h_tot_e_energy"   ); /*CuTower_Co60      -> Sumw2()*/ ; CuTower_Co60      -> Scale( 3.79642  ); 
	//fdir = (TDirectory *) infile->Get("Air_Bi214"     ); fdir->cd(); TH1D * Air_Bi214_P1      = (TH1D*) fdir->Get("Air_Bi214_h_tot_e_energy"      ); /*Air_Bi214_P1      -> Sumw2()*/ ; Air_Bi214_P1      -> Scale( 4.19156  ); 
	//fdir = (TDirectory *) infile->Get("PMT_Bi214"     ); fdir->cd(); TH1D * PMT_Bi214         = (TH1D*) fdir->Get("PMT_Bi214_h_tot_e_energy"      ); /*PMT_Bi214         -> Sumw2()*/ ; PMT_Bi214         -> Scale( 30.6795  ); 
	//fdir = (TDirectory *) infile->Get("PMT_Tl208"     ); fdir->cd(); TH1D * PMT_Tl208         = (TH1D*) fdir->Get("PMT_Tl208_h_tot_e_energy"      ); /*PMT_Tl208         -> Sumw2()*/ ; PMT_Tl208         -> Scale( 23.2697  ); 
	//fdir = (TDirectory *) infile->Get("PMT_Ac228"     ); fdir->cd(); TH1D * PMT_Ac228         = (TH1D*) fdir->Get("PMT_Ac228_h_tot_e_energy"      ); /*PMT_Ac228         -> Sumw2()*/ ; PMT_Ac228         -> Scale( 3.60937  ); 
	//fdir = (TDirectory *) infile->Get("PMT_K40"       ); fdir->cd(); TH1D * PMT_K40           = (TH1D*) fdir->Get("PMT_K40_h_tot_e_energy"        ); /*PMT_K40           -> Sumw2()*/ ; PMT_K40           -> Scale( 16.792   ); 
	//fdir = (TDirectory *) infile->Get("ScintInn_K40"  ); fdir->cd(); TH1D * ScintInn_K40      = (TH1D*) fdir->Get("ScintInn_K40_h_tot_e_energy"   ); /*ScintInn_K40      -> Sumw2()*/ ; ScintInn_K40      -> Scale( 0.33559  ); 
	//fdir = (TDirectory *) infile->Get("ScintOut_K40"  ); fdir->cd(); TH1D * ScintOut_K40      = (TH1D*) fdir->Get("ScintOut_K40_h_tot_e_energy"   ); /*ScintOut_K40      -> Sumw2()*/ ; ScintOut_K40      -> Scale( 0.604063 ); 
	//fdir = (TDirectory *) infile->Get("ScintPet_K40"  ); fdir->cd(); TH1D * ScintPet_K40      = (TH1D*) fdir->Get("ScintPet_K40_h_tot_e_energy"   ); /*ScintPet_K40      -> Sumw2()*/ ; ScintPet_K40      -> Scale( 1.00676  ); 
	//fdir = (TDirectory *) infile->Get("MuMetal_Pa234m"); fdir->cd(); TH1D * MuMetal_Pa234m    = (TH1D*) fdir->Get("MuMetal_Pa234m_h_tot_e_energy" ); /*MuMetal_Pa234m    -> Sumw2()*/ ; MuMetal_Pa234m    -> Scale( 0.664017 ); 
	//fdir = (TDirectory *) infile->Get("Cd116_2b2n_m14"); fdir->cd(); TH1D * Cd116_2b2n_m14    = (TH1D*) fdir->Get("Cd116_2b2n_m14_h_tot_e_energy" ); /*Cd116_2b2n_m14    -> Sumw2()*/ ; Cd116_2b2n_m14    -> Scale( 4913.49  ); 
    //
	//fdir->Close();
	//infile->Close();

  TRandom r(1234);
  double niter = 5e5;
  
  //We'll make three mass points...
  //for(int m=100; m<=150; m+=25){
    
    //bkgd1->Scale(0);
    //bkgd2->Scale(0);
    //sig->Scale(0);
    //data->Scale(0);
    //bkgd2SystP->Scale(0);
    //bkgd2SystN->Scale(0);
    //sigSystP->Scale(0);
    //sigSystN->Scale(0);

    // For this example, randomly fill histograms
    //for(int i=0; i<niter; i++){
    //  //Flat background
    //  bkgd1->Fill(r.Rndm(),150.0/niter);
    //  
    //  //Fill data with 5% higher bkgd1 rate
    //  data->Fill(r.Rndm(), 157.5/niter);
    //  
    //  //Falling background
    //  bkgd2->Fill(r.Gaus(0,0.30),600.0/niter);
    //  
    //  //Shape-dependent bkgd systematic
    //  bkgd2SystP->Fill(r.Gaus(0,0.305),605.0/niter);
    //  bkgd2SystN->Fill(r.Gaus(0,0.295),595.0/niter);
    //  
    //  //Fill data with 2% lower rate and 1/2 sigma morphed shape
    //  data->Fill(r.Gaus(0,0.2975), 588.0/niter);
    //  
    //  //Peaked signal
    //  sig->Fill(r.Gaus(1,0.15),15/niter);
    //  
    //  //Shape-dependent signal systematic
    //  sigSystP->Fill(r.Gaus(1,0.145),15/niter);
    //  sigSystN->Fill(r.Gaus(1,0.155),15/niter);
    //}
    

    //Backgrounds are passed in via vector
    vector<TH1D*> vbkgd;
    //vbkgd.push_back(Cd116_Tl208);      
    //vbkgd.push_back(Cd116_Ac228);      
    //vbkgd.push_back(Cd116_Bi212);      
    //vbkgd.push_back(Cd116_Bi214);      
    //vbkgd.push_back(Cd116_Pb214);      
    //vbkgd.push_back(Mylar_Bi214);      
    //vbkgd.push_back(Mylar_Pb214);      
    //vbkgd.push_back(Cd116_K40_cold); 
    //vbkgd.push_back(Cd116_K40_warm); 
    //vbkgd.push_back(Cd116_Pa234m_cold);
    //vbkgd.push_back(Cd116_Pa234m_warm);
    //vbkgd.push_back(SFoil_Bi210_cold);      
    //vbkgd.push_back(SFoil_Bi210_warm);      
    //vbkgd.push_back(SWire_Bi210_P1); 
    //vbkgd.push_back(SWire_Bi210_P2); 
    //vbkgd.push_back(SScin_Bi210);      
    //vbkgd.push_back(SScin_Bi214);      
    //vbkgd.push_back(SWire_Tl208_P1); 
    //vbkgd.push_back(SWire_Tl208_P2); 
    //vbkgd.push_back(SWire_Bi214_P1); 
    //vbkgd.push_back(SWire_Bi214_P2); 
    //vbkgd.push_back(SFoil_Bi214_P1); 
    //vbkgd.push_back(SFoil_Bi214_P2); 
    //vbkgd.push_back(SWire_Pb214_P1); 
    //vbkgd.push_back(SWire_Pb214_P2); 
    //vbkgd.push_back(SFoil_Pb214_P1); 
    //vbkgd.push_back(SFoil_Pb214_P2); 
    //vbkgd.push_back(FeShield_Bi214);   
    //vbkgd.push_back(FeShield_Tl208);   
    //vbkgd.push_back(FeShield_Ac228);   
    //vbkgd.push_back(CuTower_Co60);     
    //vbkgd.push_back(Air_Bi214_P1);     
    //vbkgd.push_back(PMT_Bi214);        
    //vbkgd.push_back(PMT_Tl208);        
    //vbkgd.push_back(PMT_Ac228);        
    //vbkgd.push_back(PMT_K40);          
    //vbkgd.push_back(ScintInn_K40);     
    //vbkgd.push_back(ScintOut_K40);     
    //vbkgd.push_back(ScintPet_K40);     
    //vbkgd.push_back(MuMetal_Pa234m);   
    vbkgd.push_back(Cd116_2b2n_m14);   
	
    //Alpha parameters only matter when smoothing is utilized
    //  Input values don't matter if you're not smoothing.
    //  Don't smooth unless you know what you're doing.
    vector<double> valpha;
    valpha.push_back(-1);
    valpha.push_back(-1);
    
    ///Use this tool to allow collie to generate a low-stats safe
    // binning for your histograms.  Histogram binning should be
    // larger than your desired final number of bins.  For more
    // details see CollieIOfile.h
    // Should be done for each mass point in the file, but with
    // the same number of output bins (specified above).  IE, if
    // you have a mass point loop, put this inside the loop.
    //
    //         TH1D* btotal = (TH1D*)bkgd1->Clone("btotal");
    //         btotal->Add(bkgd2);
    //         cfile->generateBinMap(btotal,sig,"MVA");
    //         delete btotal; btotal = NULL;
    
    
    //Each parameter point has a signal histo, data histo, and an array of backgrounds...
    //  Smoothing parameters are also passed in.
    cfile->createMassPoint(100, data, sig, -1, vbkgd,valpha);


    // If you have more than one mass point, you may choose to interpolate on some parameter grid
    //cfile->interpolateMassGrid(5,100,110);
    

  // Add systematics...either flat or by shape (ie, function of final variable)
  //   if by shape, must supply a histogram of the values in percent(%) fluctuations...
  //   Signal requires no index, but backgrounds must be specifically indexed (0->N bkgds)    
  //   Read the instructions in collie/io/include/CollieIOFile.hh if you're in doubt
  cfile->createFlatSigSystematic("IsotopeMass"    , 0.0025 , 0.0025 ,100);
  cfile->createFlatSigSystematic("Efficiency"     , 0.0550 , 0.0550 ,100);
  cfile->createFlatSigSystematic("Bremsstrahlung" , 0.0050 , 0.0012 ,100);
  cfile->createFlatSigSystematic("ThinFoil"       , 0.0073 , 0.0073 ,100);
  cfile->createFlatSigSystematic("EnCalib"        , 0.0025 , 0.0025 ,100);
  
  //// Tl-208 Systematics
  //cfile->createFlatBkgdSystematic(  0 , "Tl-208"      , 0.0004 , 0.0004 ,100);
  //cfile->createFlatBkgdSystematic(  1 , "Tl-208"      , 0.0004 , 0.0004 ,100);
  //cfile->createFlatBkgdSystematic(  2 , "Tl-208"      , 0.0004 , 0.0004 ,100);
  //cfile->createFlatBkgdSystematic( 17 , "Tl-208"      , 0.0004 , 0.0004 ,100);
  //cfile->createFlatBkgdSystematic( 18 , "Tl-208"      , 0.0004 , 0.0004 ,100);
  //
  //// Bi-214 Systematic
  //cfile->createFlatBkgdSystematic(  3 , "Bi-214"     , 0.0007 , 0.0007 ,100);
  //cfile->createFlatBkgdSystematic(  4 , "Bi-214"     , 0.0007 , 0.0007 ,100);
  //cfile->createFlatBkgdSystematic(  5 , "Bi-214"     , 0.0007 , 0.0007 ,100);
  //cfile->createFlatBkgdSystematic(  6 , "Bi-214"     , 0.0007 , 0.0007 ,100);
  //
  //// Internal Systematic
  //cfile->createFlatBkgdSystematic(  7 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic(  8 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic(  9 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic( 10 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic( 11 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic( 12 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic( 13 , "Internal"   , 0.0140 , 0.0176 ,100);
  //cfile->createFlatBkgdSystematic( 14 , "Internal"   , 0.0140 , 0.0176 ,100);	
  //
  //// Radon Systematic
  //cfile->createFlatBkgdSystematic( 19 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 20 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 21 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 22 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 23 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 24 , "Radon"      , 0.0004 , 0.0004 ,100);	
  //cfile->createFlatBkgdSystematic( 25 , "Radon"      , 0.0004 , 0.0004 ,100);           
  //cfile->createFlatBkgdSystematic( 26 , "Radon"      , 0.0004 , 0.0004 ,100);           
  //
  //// Externals Systematic
  //cfile->createFlatBkgdSystematic( 15 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 16 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 27 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 28 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 29 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 30 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 31 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 32 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 33 , "Externals"  , 0.0061 , 0.0129 ,100);	 
  //cfile->createFlatBkgdSystematic( 34 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 35 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 36 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 37 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 38 , "Externals"  , 0.0061 , 0.0129 ,100);	
  //cfile->createFlatBkgdSystematic( 39 , "Externals"  , 0.0061 , 0.0129 ,100);	

  //}
  ///store and output channel information
	cfile->storeFile();
  
}
