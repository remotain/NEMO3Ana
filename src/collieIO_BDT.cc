#include "CollieIOFile.hh"

#include <iostream>
#include <map>
#include <string>

#include "TRandom.h"
#include "TString.h"

int main(int argc, char* argv[]) {
  
  	TString myModel;
   	TString myEcut;

  	if ( argc <= 2 ) {
		myModel = argv[1];
	}
  
	else if ( argc <= 3 ){
		myModel = argv[1];
		myEcut    = argv[2];
	}  
  
    // Default model to be trained + tested
    std::map<std::string,int> Model;

    // --- Cut optimisation
    Model[ "MM"    ]  = 0; // Mass mechanism
    Model[ "RHC_L" ]  = 0; // Right Handed Current
    Model[ "RHC_E" ]  = 0; // Right Handed Current	
    Model[ "M1"    ]  = 0; // Majoron
    Model[ "M2"    ]  = 0; // Majoron
    Model[ "M3"    ]  = 0; // Majoron
    Model[ "M7"    ]  = 0; // Majoron

    // Default model to be trained + tested
    std::map<std::string,double> CutOff;

    // --- Cut optimisation
    CutOff[ "-020" ] = -0.20; 
    CutOff[ "-010" ] = -0.10; 
    CutOff[ "-005" ] = -0.05; 
    CutOff[ "000" ] = 0.00; 
    CutOff[ "005" ] = 0.05; 
    CutOff[ "010" ] = 0.10; 
    CutOff[ "015" ] = 0.15; 
    CutOff[ "020" ] = 0.20; 

	double minEcut = -0.80;
	double maxEcut = 0.80;

	
    if(myModel != "") {
  	
 		std::string regModel(myModel);
		
 		if( Model.find(regModel) == Model.end() ){
 			std::cout << "Model \"" << myModel << "\" not known in under this name. Choose among the following:" << std::endl;
 			for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
 			std::cout << std::endl;
 			return 1;
 		}
	   
 		Model[regModel] = 1;
	
    } else {
   	
 	   std::cout << "No signal model as been specified. You must choose one among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
        std::cout << std::endl;
        return 1;
    }
  
  	std::cout << "Process model \"" << myModel << "\""<< std::endl;
  
    if(myEcut != "") {
  	
 		std::string regEcut(myEcut);
		
 		if( CutOff.find(regEcut) == CutOff.end() ){
 			std::cout << "Cut value \"" << myEcut << "\" not known in under this name. Choose among the following:" << std::endl;
 			for (std::map<std::string,double>::iterator it = CutOff.begin(); it != CutOff.end(); it++) std::cout << it->first << " ";
 			std::cout << std::endl;
 			return 1;
 		}
	   
 		minEcut = CutOff[regEcut];
	
    } else {
		
		std::cout << "No cut off as been specified. Use default value" << std::endl;
		myEcut = "DEF";
		minEcut = -0.40;
		
	}

  
  
	TString infileDir( "/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/TMVApp/" );
    TString infileName;
	infileName.Form( "TMVApp_%s.root", myModel.Data() );	

    TFile * infile = new TFile( infileDir + infileName , "READ");
  
    if (!infile) {
  	  cout << "Error opening file" << endl;
  	  return 1;
    }
	
	TH1D * sig = 0;
	
    if ( Model[ "MM"    ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m1_MVA_BDT"  ) ; 
    if ( Model[ "RHC_L" ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m2_MVA_BDT"  ) ; 
    if ( Model[ "RHC_E" ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m18_MVA_BDT" ) ; 	
    if ( Model[ "M1"    ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m5_MVA_BDT"  ) ; 
    if ( Model[ "M2"    ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m15_MVA_BDT" ) ; 
    if ( Model[ "M3"    ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m6_MVA_BDT"  ) ; 
    if ( Model[ "M7"    ] ) sig = (TH1D*) infile->Get( "Cd116_2b0n_m7_MVA_BDT"  ) ; 
	
 	sig -> Sumw2() ; 
	
	if ( Model[ "MM"    ] ) sig -> Scale( 1 / 5000000. );
	if ( Model[ "RHC_L" ] ) sig -> Scale( 1 / 4999900. );
	if ( Model[ "RHC_E" ] ) sig -> Scale( 1 / 3999900. );	
	if ( Model[ "M1"    ] ) sig -> Scale( 1 / 5000100. );
	if ( Model[ "M2"    ] ) sig -> Scale( 1 / 5000000. );
	if ( Model[ "M3"    ] ) sig -> Scale( 1 / 4999900. );
	if ( Model[ "M7"    ] ) sig -> Scale( 1 / 5000000. );
	
	//Define backgrounds     
	vector<string> bkgdNames;
	
	//Backgrounds are passed in via vector
	vector<TH1D*> vbkgd;
	
	TH1D * data = (TH1D*) infile->Get( "Data_MVA_BDT" ); 
	data->Sumw2();	

	int index = 0;

    //Otherwise, get your input histograms from an external file
    /*  0 */ double Cd116_Tl208_weight    = 6.52838           ; TH1D *  Cd116_Tl208       = 0 ; int Cd116_Tl208_i    ; if(  Cd116_Tl208_weight    != 0  ) { Cd116_Tl208      = (TH1D *) infile->Get("Cd116_Tl208_MVA_BDT"    ) -> Clone( "Cd116_Tl208"    ) ; Cd116_Tl208    -> Sumw2() ; Cd116_Tl208    -> Scale( Cd116_Tl208_weight     / Cd116_Tl208     ->Integral() ) ; bkgdNames.push_back("Cd116_Tl208"   ); vbkgd.push_back( Cd116_Tl208    ); Cd116_Tl208_i    = index; index++; };
    /*  1 */ double Cd116_Ac228_weight    = 7.62351           ; TH1D *  Cd116_Ac228       = 0 ; int Cd116_Ac228_i    ; if(  Cd116_Ac228_weight    != 0  ) { Cd116_Ac228      = (TH1D *) infile->Get("Cd116_Ac228_MVA_BDT"    ) -> Clone( "Cd116_Ac228"    ) ; Cd116_Ac228    -> Sumw2() ; Cd116_Ac228    -> Scale( Cd116_Ac228_weight     / Cd116_Ac228     ->Integral() ) ; bkgdNames.push_back("Cd116_Ac228"   ); vbkgd.push_back( Cd116_Ac228    ); Cd116_Ac228_i    = index; index++; };
    /*  2 */ double Cd116_Bi212_weight    = 3.00708           ; TH1D *  Cd116_Bi212       = 0 ; int Cd116_Bi212_i    ; if(  Cd116_Bi212_weight    != 0  ) { Cd116_Bi212      = (TH1D *) infile->Get("Cd116_Bi212_MVA_BDT"    ) -> Clone( "Cd116_Bi212"    ) ; Cd116_Bi212    -> Sumw2() ; Cd116_Bi212    -> Scale( Cd116_Bi212_weight     / Cd116_Bi212     ->Integral() ) ; bkgdNames.push_back("Cd116_Bi212"   ); vbkgd.push_back( Cd116_Bi212    ); Cd116_Bi212_i    = index; index++; };
    /*  3 */ double Cd116_Bi214_weight    = 18.1504           ; TH1D *  Cd116_Bi214       = 0 ; int Cd116_Bi214_i    ; if(  Cd116_Bi214_weight    != 0  ) { Cd116_Bi214      = (TH1D *) infile->Get("Cd116_Bi214_MVA_BDT"    ) -> Clone( "Cd116_Bi214"    ) ; Cd116_Bi214    -> Sumw2() ; Cd116_Bi214    -> Scale( Cd116_Bi214_weight     / Cd116_Bi214     ->Integral() ) ; bkgdNames.push_back("Cd116_Bi214"   ); vbkgd.push_back( Cd116_Bi214    ); Cd116_Bi214_i    = index; index++; };
    /*  4 */ double Cd116_Pb214_weight    = 0.186417          ; TH1D *  Cd116_Pb214       = 0 ; int Cd116_Pb214_i    ; if(  Cd116_Pb214_weight    != 0  ) { Cd116_Pb214      = (TH1D *) infile->Get("Cd116_Pb214_VT_MVA_BDT" ) -> Clone( "Cd116_Pb214"    ) ; Cd116_Pb214    -> Sumw2() ; Cd116_Pb214    -> Scale( Cd116_Pb214_weight     / Cd116_Pb214     ->Integral() ) ; bkgdNames.push_back("Cd116_Pb214"   ); vbkgd.push_back( Cd116_Pb214    ); Cd116_Pb214_i    = index; index++; };
    /*  5 */ double Mylar_Bi214_weight    = 11.1346           ; TH1D *  Mylar_Bi214       = 0 ; int Mylar_Bi214_i    ; if(  Mylar_Bi214_weight    != 0  ) { Mylar_Bi214      = (TH1D *) infile->Get("Mylar_Bi214_MVA_BDT"    ) -> Clone( "Mylar_Bi214"    ) ; Mylar_Bi214    -> Sumw2() ; Mylar_Bi214    -> Scale( Mylar_Bi214_weight     / Mylar_Bi214     ->Integral() ) ; bkgdNames.push_back("Mylar_Bi214"   ); vbkgd.push_back( Mylar_Bi214    ); Mylar_Bi214_i    = index; index++; };
    /*  6 */ double Mylar_Pb214_weight    = 0.496238          ; TH1D *  Mylar_Pb214       = 0 ; int Mylar_Pb214_i    ; if(  Mylar_Pb214_weight    != 0  ) { Mylar_Pb214      = (TH1D *) infile->Get("Mylar_Pb214_MVA_BDT"    ) -> Clone( "Mylar_Pb214"    ) ; Mylar_Pb214    -> Sumw2() ; Mylar_Pb214    -> Scale( Mylar_Pb214_weight     / Mylar_Pb214     ->Integral() ) ; bkgdNames.push_back("Mylar_Pb214"   ); vbkgd.push_back( Mylar_Pb214    ); Mylar_Pb214_i    = index; index++; };
    /*  7 */ double Cd116_K40_weight      = 8.9841+25.8272    ; TH1D *  Cd116_K40         = 0 ; int Cd116_K40_i      ; if(  Cd116_K40_weight      != 0  ) { Cd116_K40        = (TH1D *) infile->Get("Cd116_K40_MVA_BDT"      ) -> Clone( "Cd116_K40"      ) ; Cd116_K40      -> Sumw2() ; Cd116_K40      -> Scale( Cd116_K40_weight       / Cd116_K40       ->Integral() ) ; bkgdNames.push_back("Cd116_K40"     ); vbkgd.push_back( Cd116_K40      ); Cd116_K40_i      = index; index++; };
    /*  8 */ double Cd116_Pa234m_weight   = 27.9307+72.4667   ; TH1D *  Cd116_Pa234m      = 0 ; int Cd116_Pa234m_i   ; if(  Cd116_Pa234m_weight   != 0  ) { Cd116_Pa234m     = (TH1D *) infile->Get("Cd116_Pa234m_MVA_BDT"   ) -> Clone( "Cd116_Pa234m"   ) ; Cd116_Pa234m   -> Sumw2() ; Cd116_Pa234m   -> Scale( Cd116_Pa234m_weight    / Cd116_Pa234m    ->Integral() ) ; bkgdNames.push_back("Cd116_Pa234m"  ); vbkgd.push_back( Cd116_Pa234m   ); Cd116_Pa234m_i   = index; index++; };
    /*  9 */ double SFoil_Bi210_weight    = 0+23.2438         ; TH1D *  SFoil_Bi210       = 0 ; int SFoil_Bi210_i    ; if(  SFoil_Bi210_weight    != 0  ) { SFoil_Bi210      = (TH1D *) infile->Get("SFoil_Bi210_MVA_BDT"    ) -> Clone( "SFoil_Bi210"    ) ; SFoil_Bi210    -> Sumw2() ; SFoil_Bi210    -> Scale( SFoil_Bi210_weight     / SFoil_Bi210     ->Integral() ) ; bkgdNames.push_back("SFoil_Bi210"   ); vbkgd.push_back( SFoil_Bi210    ); SFoil_Bi210_i    = index; index++; };
    /* 10 */ double SWire_Bi210_weight    = 0.136147+0.624187 ; TH1D *  SWire_Bi210       = 0 ; int SWire_Bi210_i    ; if(  SWire_Bi210_weight    != 0  ) { SWire_Bi210      = (TH1D *) infile->Get("SWire_Bi210_MVA_BDT"    ) -> Clone( "SWire_Bi210"    ) ; SWire_Bi210    -> Sumw2() ; SWire_Bi210    -> Scale( SWire_Bi210_weight     / SWire_Bi210     ->Integral() ) ; bkgdNames.push_back("SWire_Bi210"   ); vbkgd.push_back( SWire_Bi210    ); SWire_Bi210_i    = index; index++; };
    /* 11 */ double SScin_Bi210_weight    = 1.75641           ; TH1D *  SScin_Bi210       = 0 ; int SScin_Bi210_i    ; if(  SScin_Bi210_weight    != 0  ) { SScin_Bi210      = (TH1D *) infile->Get("SScin_Bi210_MVA_BDT"    ) -> Clone( "SScin_Bi210"    ) ; SScin_Bi210    -> Sumw2() ; SScin_Bi210    -> Scale( SScin_Bi210_weight     / SScin_Bi210     ->Integral() ) ; bkgdNames.push_back("SScin_Bi210"   ); vbkgd.push_back( SScin_Bi210    ); SScin_Bi210_i    = index; index++; };
    /* 12 */ double SScin_Bi214_weight    = 0.0510754         ; TH1D *  SScin_Bi214       = 0 ; int SScin_Bi214_i    ; if(  SScin_Bi214_weight    != 0  ) { SScin_Bi214      = (TH1D *) infile->Get("SScin_Bi214_MVA_BDT"    ) -> Clone( "SScin_Bi214"    ) ; SScin_Bi214    -> Sumw2() ; SScin_Bi214    -> Scale( SScin_Bi214_weight     / SScin_Bi214     ->Integral() ) ; bkgdNames.push_back("SScin_Bi214"   ); vbkgd.push_back( SScin_Bi214    ); SScin_Bi214_i    = index; index++; };
    /* 13 */ double SScin_Pb214_weight    = 0                 ; TH1D *  SScin_Pb214       = 0 ; int SScin_Pb214_i    ; if(  SScin_Pb214_weight    != 0  ) { SScin_Pb214      = (TH1D *) infile->Get("SScin_Pb214_MVA_BDT"    ) -> Clone( "SScin_Pb214"    ) ; SScin_Pb214    -> Sumw2() ; SScin_Pb214    -> Scale( SScin_Pb214_weight     / SScin_Pb214     ->Integral() ) ; bkgdNames.push_back("SScin_Pb214"   ); vbkgd.push_back( SScin_Pb214    ); SScin_Pb214_i    = index; index++; };
    /* 14 */ double SWire_Tl208_weight    = 0.217623+1.07641  ; TH1D *  SWire_Tl208       = 0 ; int SWire_Tl208_i    ; if(  SWire_Tl208_weight    != 0  ) { SWire_Tl208      = (TH1D *) infile->Get("SWire_Tl208_MVA_BDT"    ) -> Clone( "SWire_Tl208"    ) ; SWire_Tl208    -> Sumw2() ; SWire_Tl208    -> Scale( SWire_Tl208_weight     / SWire_Tl208     ->Integral() ) ; bkgdNames.push_back("SWire_Tl208"   ); vbkgd.push_back( SWire_Tl208    ); SWire_Tl208_i    = index; index++; };
    /* 15 */ double SWire_Bi214_P1_weight = 21.4188+17.8236   ; TH1D *  SWire_Bi214_P1    = 0 ; int SWire_Bi214_P1_i ; if(  SWire_Bi214_P1_weight != 0  ) { SWire_Bi214_P1   = (TH1D *) infile->Get("SWire_Bi214_MVA_BDT"    ) -> Clone( "SWire_Bi214_P1" ) ; SWire_Bi214_P1 -> Sumw2() ; SWire_Bi214_P1 -> Scale( SWire_Bi214_P1_weight  / SWire_Bi214_P1  ->Integral() ) ; bkgdNames.push_back("SWire_Bi214_P1"); vbkgd.push_back( SWire_Bi214_P1 ); SWire_Bi214_P1_i = index; index++; };
    /* 16 */ double SFoil_Bi214_weight    = 5.83533+2.80427   ; TH1D *  SFoil_Bi214       = 0 ; int SFoil_Bi214_i    ; if(  SFoil_Bi214_weight    != 0  ) { SFoil_Bi214      = (TH1D *) infile->Get("SFoil_Bi214_MVA_BDT"    ) -> Clone( "SFoil_Bi214"    ) ; SFoil_Bi214    -> Sumw2() ; SFoil_Bi214    -> Scale( SFoil_Bi214_weight     / SFoil_Bi214     ->Integral() ) ; bkgdNames.push_back("SFoil_Bi214"   ); vbkgd.push_back( SFoil_Bi214    ); SFoil_Bi214_i    = index; index++; };
    /* 17 */ double SWire_Pb214_weight    = 0.458486+0.649167 ; TH1D *  SWire_Pb214       = 0 ; int SWire_Pb214_i    ; if(  SWire_Pb214_weight    != 0  ) { SWire_Pb214      = (TH1D *) infile->Get("SWire_Pb214_MVA_BDT"    ) -> Clone( "SWire_Pb214"    ) ; SWire_Pb214    -> Sumw2() ; SWire_Pb214    -> Scale( SWire_Pb214_weight     / SWire_Pb214     ->Integral() ) ; bkgdNames.push_back("SWire_Pb214"   ); vbkgd.push_back( SWire_Pb214    ); SWire_Pb214_i    = index; index++; };
    /* 18 */ double SFoil_Pb214_weight    = 0.218761+0.195287 ; TH1D *  SFoil_Pb214       = 0 ; int SFoil_Pb214_i    ; if(  SFoil_Pb214_weight    != 0  ) { SFoil_Pb214      = (TH1D *) infile->Get("SFoil_Pb214_MVA_BDT"    ) -> Clone( "SFoil_Pb214"    ) ; SFoil_Pb214    -> Sumw2() ; SFoil_Pb214    -> Scale( SFoil_Pb214_weight     / SFoil_Pb214     ->Integral() ) ; bkgdNames.push_back("SFoil_Pb214"   ); vbkgd.push_back( SFoil_Pb214    ); SFoil_Pb214_i    = index; index++; };
    /* 19 */ double FeShield_Bi214_weight = 50.7021           ; TH1D *  FeShield_Bi214    = 0 ; int FeShield_Bi214_i ; if(  FeShield_Bi214_weight != 0  ) { FeShield_Bi214   = (TH1D *) infile->Get("FeShield_Bi214_MVA_BDT" ) -> Clone( "FeShield_Bi214" ) ; FeShield_Bi214 -> Sumw2() ; FeShield_Bi214 -> Scale( FeShield_Bi214_weight  / FeShield_Bi214  ->Integral() ) ; bkgdNames.push_back("FeShield_Bi214"); vbkgd.push_back( FeShield_Bi214 ); FeShield_Bi214_i = index; index++; };
    /* 20 */ double FeShield_Tl208_weight = 0.859465          ; TH1D *  FeShield_Tl208    = 0 ; int FeShield_Tl208_i ; if(  FeShield_Tl208_weight != 0  ) { FeShield_Tl208   = (TH1D *) infile->Get("FeShield_Tl208_MVA_BDT" ) -> Clone( "FeShield_Tl208" ) ; FeShield_Tl208 -> Sumw2() ; FeShield_Tl208 -> Scale( FeShield_Tl208_weight  / FeShield_Tl208  ->Integral() ) ; bkgdNames.push_back("FeShield_Tl208"); vbkgd.push_back( FeShield_Tl208 ); FeShield_Tl208_i = index; index++; };
    /* 21 */ double FeShield_Ac228_weight = 0.126868          ; TH1D *  FeShield_Ac228    = 0 ; int FeShield_Ac228_i ; if(  FeShield_Ac228_weight != 0  ) { FeShield_Ac228   = (TH1D *) infile->Get("FeShield_Ac228_MVA_BDT" ) -> Clone( "FeShield_Ac228" ) ; FeShield_Ac228 -> Sumw2() ; FeShield_Ac228 -> Scale( FeShield_Ac228_weight  / FeShield_Ac228  ->Integral() ) ; bkgdNames.push_back("FeShield_Ac228"); vbkgd.push_back( FeShield_Ac228 ); FeShield_Ac228_i = index; index++; };
    /* 22 */ double CuTower_Co60_weight   = 3.9407            ; TH1D *  CuTower_Co60      = 0 ; int CuTower_Co60_i   ; if(  CuTower_Co60_weight   != 0  ) { CuTower_Co60     = (TH1D *) infile->Get("CuTower_Co60_MVA_BDT"   ) -> Clone( "CuTower_Co60"   ) ; CuTower_Co60   -> Sumw2() ; CuTower_Co60   -> Scale( CuTower_Co60_weight    / CuTower_Co60    ->Integral() ) ; bkgdNames.push_back("CuTower_Co60"  ); vbkgd.push_back( CuTower_Co60   ); CuTower_Co60_i   = index; index++; };
    /* 23 */ double Air_Bi214_P1_weight   = 4.19744           ; TH1D *  Air_Bi214_P1      = 0 ; int Air_Bi214_P1_i   ; if(  Air_Bi214_P1_weight   != 0  ) { Air_Bi214_P1     = (TH1D *) infile->Get("Air_Bi214_MVA_BDT"      ) -> Clone( "Air_Bi214_P1"   ) ; Air_Bi214_P1   -> Sumw2() ; Air_Bi214_P1   -> Scale( Air_Bi214_P1_weight    / Air_Bi214_P1    ->Integral() ) ; bkgdNames.push_back("Air_Bi214_P1"  ); vbkgd.push_back( Air_Bi214_P1   ); Air_Bi214_P1_i   = index; index++; };
    /* 24 */ double Air_Tl208_P1_weight   = 0                 ; TH1D *  Air_Tl208_P1      = 0 ; int Air_Tl208_P1_i   ; if(  Air_Tl208_P1_weight   != 0  ) { Air_Tl208_P1     = (TH1D *) infile->Get("Air_Tl208_MVA_BDT"      ) -> Clone( "Air_Tl208_P1"   ) ; Air_Tl208_P1   -> Sumw2() ; Air_Tl208_P1   -> Scale( Air_Tl208_P1_weight    / Air_Tl208_P1    ->Integral() ) ; bkgdNames.push_back("Air_Tl208_P1"  ); vbkgd.push_back( Air_Tl208_P1   ); Air_Tl208_P1_i   = index; index++; };
    /* 25 */ double PMT_Bi214_weight      = 27.9661           ; TH1D *  PMT_Bi214         = 0 ; int PMT_Bi214_i      ; if(  PMT_Bi214_weight      != 0  ) { PMT_Bi214        = (TH1D *) infile->Get("PMT_Bi214_MVA_BDT"      ) -> Clone( "PMT_Bi214"      ) ; PMT_Bi214      -> Sumw2() ; PMT_Bi214      -> Scale( PMT_Bi214_weight       / PMT_Bi214       ->Integral() ) ; bkgdNames.push_back("PMT_Bi214"     ); vbkgd.push_back( PMT_Bi214      ); PMT_Bi214_i      = index; index++; };
    /* 26 */ double PMT_Tl208_weight      = 22.923            ; TH1D *  PMT_Tl208         = 0 ; int PMT_Tl208_i      ; if(  PMT_Tl208_weight      != 0  ) { PMT_Tl208        = (TH1D *) infile->Get("PMT_Tl208_MVA_BDT"      ) -> Clone( "PMT_Tl208"      ) ; PMT_Tl208      -> Sumw2() ; PMT_Tl208      -> Scale( PMT_Tl208_weight       / PMT_Tl208       ->Integral() ) ; bkgdNames.push_back("PMT_Tl208"     ); vbkgd.push_back( PMT_Tl208      ); PMT_Tl208_i      = index; index++; };
    /* 27 */ double PMT_Ac228_weight      = 3.60712           ; TH1D *  PMT_Ac228         = 0 ; int PMT_Ac228_i      ; if(  PMT_Ac228_weight      != 0  ) { PMT_Ac228        = (TH1D *) infile->Get("PMT_Ac228_MVA_BDT"      ) -> Clone( "PMT_Ac228"      ) ; PMT_Ac228      -> Sumw2() ; PMT_Ac228      -> Scale( PMT_Ac228_weight       / PMT_Ac228       ->Integral() ) ; bkgdNames.push_back("PMT_Ac228"     ); vbkgd.push_back( PMT_Ac228      ); PMT_Ac228_i      = index; index++; };
    /* 28 */ double PMT_K40_weight        = 16.813            ; TH1D *  PMT_K40           = 0 ; int PMT_K40_i        ; if(  PMT_K40_weight        != 0  ) { PMT_K40          = (TH1D *) infile->Get("PMT_K40_MVA_BDT"        ) -> Clone( "PMT_K40"        ) ; PMT_K40        -> Sumw2() ; PMT_K40        -> Scale( PMT_K40_weight         / PMT_K40         ->Integral() ) ; bkgdNames.push_back("PMT_K40"       ); vbkgd.push_back( PMT_K40        ); PMT_K40_i        = index; index++; };
    /* 29 */ double ScintInn_K40_weight   = 0.333988          ; TH1D *  ScintInn_K40      = 0 ; int ScintInn_K40_i   ; if(  ScintInn_K40_weight   != 0  ) { ScintInn_K40     = (TH1D *) infile->Get("ScintInn_K40_MVA_BDT"   ) -> Clone( "ScintInn_K40"   ) ; ScintInn_K40   -> Sumw2() ; ScintInn_K40   -> Scale( ScintInn_K40_weight    / ScintInn_K40    ->Integral() ) ; bkgdNames.push_back("ScintInn_K40"  ); vbkgd.push_back( ScintInn_K40   ); ScintInn_K40_i   = index; index++; };
    /* 30 */ double ScintOut_K40_weight   = 0.601178          ; TH1D *  ScintOut_K40      = 0 ; int ScintOut_K40_i   ; if(  ScintOut_K40_weight   != 0  ) { ScintOut_K40     = (TH1D *) infile->Get("ScintOut_K40_MVA_BDT"   ) -> Clone( "ScintOut_K40"   ) ; ScintOut_K40   -> Sumw2() ; ScintOut_K40   -> Scale( ScintOut_K40_weight    / ScintOut_K40    ->Integral() ) ; bkgdNames.push_back("ScintOut_K40"  ); vbkgd.push_back( ScintOut_K40   ); ScintOut_K40_i   = index; index++; };
    /* 31 */ double ScintPet_K40_weight   = 1.00195           ; TH1D *  ScintPet_K40      = 0 ; int ScintPet_K40_i   ; if(  ScintPet_K40_weight   != 0  ) { ScintPet_K40     = (TH1D *) infile->Get("ScintPet_K40_MVA_BDT"   ) -> Clone( "ScintPet_K40"   ) ; ScintPet_K40   -> Sumw2() ; ScintPet_K40   -> Scale( ScintPet_K40_weight    / ScintPet_K40    ->Integral() ) ; bkgdNames.push_back("ScintPet_K40"  ); vbkgd.push_back( ScintPet_K40   ); ScintPet_K40_i   = index; index++; };
    /* 32 */ double MuMetal_Pa234m_weight = 0.739038          ; TH1D *  MuMetal_Pa234m    = 0 ; int MuMetal_Pa234m_i ; if(  MuMetal_Pa234m_weight != 0  ) { MuMetal_Pa234m   = (TH1D *) infile->Get("MuMetal_Pa234m_MVA_BDT" ) -> Clone( "MuMetal_Pa234m" ) ; MuMetal_Pa234m -> Sumw2() ; MuMetal_Pa234m -> Scale( MuMetal_Pa234m_weight  / MuMetal_Pa234m  ->Integral() ) ; bkgdNames.push_back("MuMetal_Pa234m"); vbkgd.push_back( MuMetal_Pa234m ); MuMetal_Pa234m_i = index; index++; };
    /* 33 */ double Cd116_2b2n_m14_weight = 4977.55           ; TH1D *  Cd116_2b2n_m14    = 0 ; int Cd116_2b2n_m14_i ; if(  Cd116_2b2n_m14_weight != 0  ) { Cd116_2b2n_m14   = (TH1D *) infile->Get("Cd116_2b2n_m14_MVA_BDT" ) -> Clone( "Cd116_2b2n_m14" ) ; Cd116_2b2n_m14 -> Sumw2() ; Cd116_2b2n_m14 -> Scale( Cd116_2b2n_m14_weight  / Cd116_2b2n_m14  ->Integral() ) ; bkgdNames.push_back("Cd116_2b2n_m14"); vbkgd.push_back( Cd116_2b2n_m14 ); Cd116_2b2n_m14_i = index; index++; };

    //Alpha parameters only matter when smoothing is utilized
    //  Input values don't matter if you're not smoothing.
    //  Don't smooth unless you know what you're doing.
    vector<double> valpha;
    valpha.push_back(-1);
    valpha.push_back(-1);

    /////////////////////////////////////////
    ///Create IO file with input parameters
    /////////////////////////////////////////
    CollieIOFile* cfile = new CollieIOFile();
    // Specify outputfile and channel name  
  
	TString outfileDir( "/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/Collie/" );
    TString outfileName;
	outfileName.Form( "CollieIO_BDT_%s_%s.root", myModel.Data(), myEcut.Data() );	
  	outfileName = outfileDir + outfileName;
  
    cfile->initFile( outfileName.Data() , "BDT_Score");  

    cfile->setInputHist(data->GetXaxis()->GetBinLowEdge(1),data->GetXaxis()->GetBinUpEdge(data->GetNbinsX()),data->GetNbinsX());
  
    // Option to define physical cutoffs where events should not exist (in terms of your historam range)
    //
    cfile->setCutoffs(minEcut, maxEcut);   
  
    // Option to rebin histograms to a coarser binning
    // Eg, rebinning by 2 reduces to 10 bins
    //
    cfile->setRebin(1);
  
	cfile->createChannel(bkgdNames);  
  
    // Option to smooth histograms
    // Don't smooth unless you know what you're doing
    //
    //  cfile->setSmooth(false);
  
    // Average number of `histogram entries for smoothing purposes (default=50k)
    // The value doesn't matter if you're not smoothing.
    //
    //  cfile->setHistNorm(50000);
    
    //Each parameter point has a signal histo, data histo, and an array of backgrounds...
    //  Smoothing parameters are also passed in.
    cfile->createMassPoint(100, data, sig, -1, vbkgd,valpha);

    // If you have more than one mass point, you may choose to interpolate on some parameter grid
    //cfile->interpolateMassGrid(5,100,110);
    
	// Add systematics...either flat or by shape (ie, function of final variable)
	//   if by shape, must supply a histogram of the values in percent(%) fluctuations...
	//   Signal requires no index, but backgrounds must be specifically indexed (0->N bkgds)    
	//   Read the instructions in collie/io/include/CollieIOFile.hh if you're in doubt
	cfile->createFlatSigSystematic("Efficiency"      , 0.0550 , 0.0550 ,100);
	cfile->createFlatSigSystematic("Foil"            , 0.0220 , 0.0324 ,100);
	cfile->createFlatSigSystematic("EnCalib"         , 0.0120 , 0.0125 ,100);
	cfile->createFlatSigSystematic("IsotopeMass"     , 0.0025 , 0.0025 ,100);
	
	// Background uncertainty
	/*  0 */ if( Cd116_Tl208     ) {cfile->createFlatBkgdSystematic( Cd116_Tl208_i    , "Tl208"      , 0.1400 , 0.1400 ,100);};
	/*  1 */ if( Cd116_Ac228     ) {cfile->createFlatBkgdSystematic( Cd116_Ac228_i    , "Tl208"      , 0.1400 , 0.1400 ,100);};
	/*  2 */ if( Cd116_Bi212     ) {cfile->createFlatBkgdSystematic( Cd116_Bi212_i    , "Tl208"      , 0.0005 , 0.0005 ,100);};
	/*  3 */ if( Cd116_Bi214     ) {cfile->createFlatBkgdSystematic( Cd116_Bi214_i    , "Bi214"      , 0.0200 , 0.0200 ,100);};
	/*  4 */ if( Cd116_Pb214     ) {cfile->createFlatBkgdSystematic( Cd116_Pb214_i    , "Bi214"      , 0.0200 , 0.0200 ,100);};
	/*  5 */ if( Mylar_Bi214     ) {cfile->createFlatBkgdSystematic( Mylar_Bi214_i    , "Bi214"      , 0.0200 , 0.0200 ,100);};
	/*  6 */ if( Mylar_Pb214     ) {cfile->createFlatBkgdSystematic( Mylar_Pb214_i    , "Bi214"      , 0.0200 , 0.0200 ,100);};
	/*  7 */ if( Cd116_K40       ) {cfile->createFlatBkgdSystematic( Cd116_K40_i      , "Internal"   , 0.3500 , 0.3500 ,100);};
	/*  8 */ if( Cd116_Pa234m    ) {cfile->createFlatBkgdSystematic( Cd116_Pa234m_i   , "Internal"   , 0.3500 , 0.3500 ,100);};
	/*  9 */ if( SFoil_Bi210     ) {cfile->createFlatBkgdSystematic( SFoil_Bi210_i    , "Internal"   , 0.3500 , 0.3500 ,100);};
	/* 10 */ if( SWire_Bi210     ) {cfile->createFlatBkgdSystematic( SWire_Bi210_i    , "Internal"   , 0.3500 , 0.3500 ,100);};
	/* 11 */ if( SScin_Bi210     ) {cfile->createFlatBkgdSystematic( SScin_Bi210_i    , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 12 */ if( SScin_Bi214     ) {cfile->createFlatBkgdSystematic( SScin_Bi214_i    , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 13 */ if( SScin_Pb214     ) {cfile->createFlatBkgdSystematic( SScin_Pb214_i    , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 14 */ if( SWire_Tl208     ) {cfile->createFlatBkgdSystematic( SWire_Tl208_i    , "Radon"      , 0.0260 , 0.0260 ,100);};
	/* 15 */ if( SWire_Bi214_P1  ) {cfile->createFlatBkgdSystematic( SWire_Bi214_P1_i , "Radon"      , 0.0260 , 0.0260 ,100);};
	/* 16 */ if( SFoil_Bi214     ) {cfile->createFlatBkgdSystematic( SFoil_Bi214_i    , "Radon"      , 0.0260 , 0.0260 ,100);};
	/* 17 */ if( SWire_Pb214     ) {cfile->createFlatBkgdSystematic( SWire_Pb214_i    , "Radon"      , 0.0260 , 0.0260 ,100);};
	/* 18 */ if( SFoil_Pb214     ) {cfile->createFlatBkgdSystematic( SFoil_Pb214_i    , "Radon"      , 0.0260 , 0.0260 ,100);};
	/* 19 */ if( FeShield_Bi214  ) {cfile->createFlatBkgdSystematic( FeShield_Bi214_i , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 20 */ if( FeShield_Tl208  ) {cfile->createFlatBkgdSystematic( FeShield_Tl208_i , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 21 */ if( FeShield_Ac228  ) {cfile->createFlatBkgdSystematic( FeShield_Ac228_i , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 22 */ if( CuTower_Co60    ) {cfile->createFlatBkgdSystematic( CuTower_Co60_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 23 */ if( Air_Bi214_P1    ) {cfile->createFlatBkgdSystematic( Air_Bi214_P1_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 24 */ if( Air_Tl208_P1    ) {cfile->createFlatBkgdSystematic( Air_Tl208_P1_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 25 */ if( PMT_Bi214       ) {cfile->createFlatBkgdSystematic( PMT_Bi214_i      , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 26 */ if( PMT_Tl208       ) {cfile->createFlatBkgdSystematic( PMT_Tl208_i      , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 27 */ if( PMT_Ac228       ) {cfile->createFlatBkgdSystematic( PMT_Ac228_i      , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 28 */ if( PMT_K40         ) {cfile->createFlatBkgdSystematic( PMT_K40_i        , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 29 */ if( ScintInn_K40    ) {cfile->createFlatBkgdSystematic( ScintInn_K40_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 30 */ if( ScintOut_K40    ) {cfile->createFlatBkgdSystematic( ScintOut_K40_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 31 */ if( ScintPet_K40    ) {cfile->createFlatBkgdSystematic( ScintPet_K40_i   , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 32 */ if( MuMetal_Pa234m  ) {cfile->createFlatBkgdSystematic( MuMetal_Pa234m_i , "Externals"  , 0.2100 , 0.2100 ,100);};
	/* 33 */ if( Cd116_2b2n_m14  ) {cfile->createFlatBkgdSystematic( Cd116_2b2n_m14_i , "bb2nu"      , 0.0670 , 0.0670 ,100);};
	
	//if ( Model[ "M1"    ] ) cfile->setBkgdFloatFlag(Cd116_2b2n_m14_i, "bb2nu", true, 100);
	//if ( Model[ "M2"    ] ) cfile->setBkgdFloatFlag(Cd116_2b2n_m14_i, "bb2nu", true, 100);
	//if ( Model[ "M3"    ] ) cfile->setBkgdFloatFlag(Cd116_2b2n_m14_i, "bb2nu", true, 100);
	//if ( Model[ "M7"    ] ) cfile->setBkgdFloatFlag(Cd116_2b2n_m14_i, "bb2nu", true, 100);
	
	///store and output channel information
	cfile->storeFile();
  
}
