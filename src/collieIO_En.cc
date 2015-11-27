#include "CollieIOFile.hh"

#include <iostream>
#include <map>
#include <string>

#include "TRandom.h"
#include "TString.h"

int main(int argc, char* argv[]) {
  
  	TString myModel;
  
  	if ( argc <= 2 ) {
		myModel = argv[1];
	}
  
    // Default model to be trained + tested
    std::map<std::string,int> Model;

    // --- Cut optimisation
    Model[ "MM"  ]  = 0; // Mass mechanism
    Model[ "RHC" ]  = 0; // Right Handed Current
    Model[ "M1"  ]  = 0; // Majoron
    Model[ "M2"  ]  = 0; // Majoron
    Model[ "M3"  ]  = 0; // Majoron
    Model[ "M7"  ]  = 0; // Majoron
	
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

	TString infileDir( "/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/" );
    TString infileName("TwoElectronIntTree_NO_CHARGE_NO_VERTEX_CUT.root");

    TFile * infile = new TFile( infileDir + infileName , "READ");
  
    if (!infile) {
  	  cout << "Error opening file" << endl;
  	  return 1;
    }
	
	TDirectory * fdir = 0;
	
	TH1D * sig = 0;
	
    if ( Model[ "MM"  ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m1" ); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m1_h_tot_e_energy"  ); };
    if ( Model[ "RHC" ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m2" ); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m2_h_tot_e_energy"  ); };
    if ( Model[ "M1"  ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m5" ); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m5_h_tot_e_energy"  ); };
    if ( Model[ "M2"  ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m15"); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m15_h_tot_e_energy" ); };
    if ( Model[ "M3"  ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m6" ); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m6_h_tot_e_energy"  ); };
    if ( Model[ "M7"  ] ) {fdir = (TDirectory *) infile->Get("Cd116_2b0n_m7" ); fdir->cd(); sig = (TH1D*) infile->Get( "Cd116_2b0n_m7_h_tot_e_energy"  ); };
	
 	sig -> Sumw2() ; 
	
	if ( Model[ "MM"  ] ) sig -> Scale( 1 / 5000000. );
	if ( Model[ "RHC" ] ) sig -> Scale( 1 / 4999900. );
	if ( Model[ "M1"  ] ) sig -> Scale( 1 / 5000100. );
	if ( Model[ "M2"  ] ) sig -> Scale( 1 / 5000000. );
	if ( Model[ "M3"  ] ) sig -> Scale( 1 / 4999900. );
	if ( Model[ "M7"  ] ) sig -> Scale( 1 / 5000000. );
	
	//Define backgrounds     
	vector<string> bkgdNames;
	
	//Backgrounds are passed in via vector
	vector<TH1D*> vbkgd;
	
	fdir = (TDirectory *) infile->Get("Data"); fdir->cd(); 
	
	TH1D * data = (TH1D*) infile->Get( "Data_h_tot_e_energy" ); 
	data->Sumw2();	

    //Otherwise, get your input histograms from an external file
    /*  0 */ fdir = (TDirectory *) infile->Get("Cd116_Tl208"    ); fdir->cd(); TH1D *  Cd116_Tl208      = (TH1D *) infile->Get("Cd116_Tl208_h_tot_e_energy"    ) -> Clone( "Cd116_Tl208"    ) ; Cd116_Tl208    -> Sumw2() ; Cd116_Tl208    -> Scale( (  7.06556         ) / Cd116_Tl208     ->Integral() ) ; bkgdNames.push_back("Cd116_Tl208"   ); vbkgd.push_back( Cd116_Tl208    );
    /*  1 */ fdir = (TDirectory *) infile->Get("Cd116_Ac228"    ); fdir->cd(); TH1D *  Cd116_Ac228      = (TH1D *) infile->Get("Cd116_Ac228_h_tot_e_energy"    ) -> Clone( "Cd116_Ac228"    ) ; Cd116_Ac228    -> Sumw2() ; Cd116_Ac228    -> Scale( (  8.28423         ) / Cd116_Ac228     ->Integral() ) ; bkgdNames.push_back("Cd116_Ac228"   ); vbkgd.push_back( Cd116_Ac228    );
    /*  2 */ fdir = (TDirectory *) infile->Get("Cd116_Bi212"    ); fdir->cd(); TH1D *  Cd116_Bi212      = (TH1D *) infile->Get("Cd116_Bi212_h_tot_e_energy"    ) -> Clone( "Cd116_Bi212"    ) ; Cd116_Bi212    -> Sumw2() ; Cd116_Bi212    -> Scale( (  3.35833         ) / Cd116_Bi212     ->Integral() ) ; bkgdNames.push_back("Cd116_Bi212"   ); vbkgd.push_back( Cd116_Bi212    );
    /*  3 */ fdir = (TDirectory *) infile->Get("Cd116_Bi214"    ); fdir->cd(); TH1D *  Cd116_Bi214      = (TH1D *) infile->Get("Cd116_Bi214_h_tot_e_energy"    ) -> Clone( "Cd116_Bi214"    ) ; Cd116_Bi214    -> Sumw2() ; Cd116_Bi214    -> Scale( (  21.6569         ) / Cd116_Bi214     ->Integral() ) ; bkgdNames.push_back("Cd116_Bi214"   ); vbkgd.push_back( Cd116_Bi214    );
    /*  4 */ fdir = (TDirectory *) infile->Get("Cd116_Pb214_VT" ); fdir->cd(); TH1D *  Cd116_Pb214      = (TH1D *) infile->Get("Cd116_Pb214_VT_h_tot_e_energy" ) -> Clone( "Cd116_Pb214"    ) ; Cd116_Pb214    -> Sumw2() ; Cd116_Pb214    -> Scale( (  0.22638         ) / Cd116_Pb214     ->Integral() ) ; bkgdNames.push_back("Cd116_Pb214"   ); vbkgd.push_back( Cd116_Pb214    );
    /*  5 */ fdir = (TDirectory *) infile->Get("Mylar_Bi214"    ); fdir->cd(); TH1D *  Mylar_Bi214      = (TH1D *) infile->Get("Mylar_Bi214_h_tot_e_energy"    ) -> Clone( "Mylar_Bi214"    ) ; Mylar_Bi214    -> Sumw2() ; Mylar_Bi214    -> Scale( (   13.741         ) / Mylar_Bi214     ->Integral() ) ; bkgdNames.push_back("Mylar_Bi214"   ); vbkgd.push_back( Mylar_Bi214    );
    /*  6 */ fdir = (TDirectory *) infile->Get("Mylar_Pb214"    ); fdir->cd(); TH1D *  Mylar_Pb214      = (TH1D *) infile->Get("Mylar_Pb214_h_tot_e_energy"    ) -> Clone( "Mylar_Pb214"    ) ; Mylar_Pb214    -> Sumw2() ; Mylar_Pb214    -> Scale( ( 0.603642         ) / Mylar_Pb214     ->Integral() ) ; bkgdNames.push_back("Mylar_Pb214"   ); vbkgd.push_back( Mylar_Pb214    );
    /*  7 */ fdir = (TDirectory *) infile->Get("Cd116_K40"      ); fdir->cd(); TH1D *  Cd116_K40        = (TH1D *) infile->Get("Cd116_K40_h_tot_e_energy"      ) -> Clone( "Cd116_K40"      ) ; Cd116_K40      -> Sumw2() ; Cd116_K40      -> Scale( (  10.9783+31.7262 ) / Cd116_K40       ->Integral() ) ; bkgdNames.push_back("Cd116_K40"     ); vbkgd.push_back( Cd116_K40      );
    /*  8 */ fdir = (TDirectory *) infile->Get("Cd116_Pa234m"   ); fdir->cd(); TH1D *  Cd116_Pa234m     = (TH1D *) infile->Get("Cd116_Pa234m_h_tot_e_energy"   ) -> Clone( "Cd116_Pa234m"   ) ; Cd116_Pa234m   -> Sumw2() ; Cd116_Pa234m   -> Scale( ( 32.2618+86.295   ) / Cd116_Pa234m    ->Integral() ) ; bkgdNames.push_back("Cd116_Pa234m"  ); vbkgd.push_back( Cd116_Pa234m   );
    /*  9 */ fdir = (TDirectory *) infile->Get("SFoil_Bi210"    ); fdir->cd(); TH1D *  SFoil_Bi210      = (TH1D *) infile->Get("SFoil_Bi210_h_tot_e_energy"    ) -> Clone( "SFoil_Bi210"    ) ; SFoil_Bi210    -> Sumw2() ; SFoil_Bi210    -> Scale( ( 1.64958+23.2437  ) / SFoil_Bi210     ->Integral() ) ; bkgdNames.push_back("SFoil_Bi210"   ); vbkgd.push_back( SFoil_Bi210    );
    /* 10 */ fdir = (TDirectory *) infile->Get("SWire_Bi210"    ); fdir->cd(); TH1D *  SWire_Bi210      = (TH1D *) infile->Get("SWire_Bi210_h_tot_e_energy"    ) -> Clone( "SWire_Bi210"    ) ; SWire_Bi210    -> Sumw2() ; SWire_Bi210    -> Scale( ( 0.217523+1.28146 ) / SWire_Bi210     ->Integral() ) ; bkgdNames.push_back("SWire_Bi210"   ); vbkgd.push_back( SWire_Bi210    );
    /* 11 */ fdir = (TDirectory *) infile->Get("SScin_Bi210"    ); fdir->cd(); TH1D *  SScin_Bi210      = (TH1D *) infile->Get("SScin_Bi210_h_tot_e_energy"    ) -> Clone( "SScin_Bi210"    ) ; SScin_Bi210    -> Sumw2() ; SScin_Bi210    -> Scale( (  3.5633          ) / SScin_Bi210     ->Integral() ) ; bkgdNames.push_back("SScin_Bi210"   ); vbkgd.push_back( SScin_Bi210    );
    /* 12 */ fdir = (TDirectory *) infile->Get("SScin_Bi214"    ); fdir->cd(); TH1D *  SScin_Bi214      = (TH1D *) infile->Get("SScin_Bi214_h_tot_e_energy"    ) -> Clone( "SScin_Bi214"    ) ; SScin_Bi214    -> Sumw2() ; SScin_Bi214    -> Scale( ( 3.03289          ) / SScin_Bi214     ->Integral() ) ; bkgdNames.push_back("SScin_Bi214"   ); vbkgd.push_back( SScin_Bi214    );
    /* 13 */ fdir = (TDirectory *) infile->Get("SScin_Pb214"    ); fdir->cd(); TH1D *  SScin_Pb214      = (TH1D *) infile->Get("SScin_Pb214_h_tot_e_energy"    ) -> Clone( "SScin_Pb214"    ) ; SScin_Pb214    -> Sumw2() ; SScin_Pb214    -> Scale( ( 0.0404384        ) / SScin_Pb214     ->Integral() ) ; bkgdNames.push_back("SScin_Pb214"   ); vbkgd.push_back( SScin_Pb214    );
    /* 14 */ fdir = (TDirectory *) infile->Get("SWire_Tl208"    ); fdir->cd(); TH1D *  SWire_Tl208      = (TH1D *) infile->Get("SWire_Tl208_h_tot_e_energy"    ) -> Clone( "SWire_Tl208"    ) ; SWire_Tl208    -> Sumw2() ; SWire_Tl208    -> Scale( ( 0.42948+2.3516   ) / SWire_Tl208     ->Integral() ) ; bkgdNames.push_back("SWire_Tl208"   ); vbkgd.push_back( SWire_Tl208    );
    /* 15 */ fdir = (TDirectory *) infile->Get("SWire_Bi214"    ); fdir->cd(); TH1D *  SWire_Bi214_P1   = (TH1D *) infile->Get("SWire_Bi214_h_tot_e_energy"    ) -> Clone( "SWire_Bi214_P1" ) ; SWire_Bi214_P1 -> Sumw2() ; SWire_Bi214_P1 -> Scale( ( 38.1982+34.6645  ) / SWire_Bi214_P1  ->Integral() ) ; bkgdNames.push_back("SWire_Bi214_P1"); vbkgd.push_back( SWire_Bi214_P1 );
    /* 16 */ fdir = (TDirectory *) infile->Get("SFoil_Bi214"    ); fdir->cd(); TH1D *  SFoil_Bi214      = (TH1D *) infile->Get("SFoil_Bi214_h_tot_e_energy"    ) -> Clone( "SFoil_Bi214"    ) ; SFoil_Bi214    -> Sumw2() ; SFoil_Bi214    -> Scale( ( 7.38274+3.47797  ) / SFoil_Bi214     ->Integral() ) ; bkgdNames.push_back("SFoil_Bi214"   ); vbkgd.push_back( SFoil_Bi214    );
    /* 17 */ fdir = (TDirectory *) infile->Get("SWire_Pb214"    ); fdir->cd(); TH1D *  SWire_Pb214      = (TH1D *) infile->Get("SWire_Pb214_h_tot_e_energy"    ) -> Clone( "SWire_Pb214"    ) ; SWire_Pb214    -> Sumw2() ; SWire_Pb214    -> Scale( ( 1.03586+1.34745  ) / SWire_Pb214     ->Integral() ) ; bkgdNames.push_back("SWire_Pb214"   ); vbkgd.push_back( SWire_Pb214    );
    /* 18 */ fdir = (TDirectory *) infile->Get("SFoil_Pb214"    ); fdir->cd(); TH1D *  SFoil_Pb214      = (TH1D *) infile->Get("SFoil_Pb214_h_tot_e_energy"    ) -> Clone( "SFoil_Pb214"    ) ; SFoil_Pb214    -> Sumw2() ; SFoil_Pb214    -> Scale( ( 0.341813+0.242809) / SFoil_Pb214     ->Integral() ) ; bkgdNames.push_back("SFoil_Pb214"   ); vbkgd.push_back( SFoil_Pb214    );
    /* 19 */ fdir = (TDirectory *) infile->Get("FeShield_Bi214" ); fdir->cd(); TH1D *  FeShield_Bi214   = (TH1D *) infile->Get("FeShield_Bi214_h_tot_e_energy" ) -> Clone( "FeShield_Bi214" ) ; FeShield_Bi214 -> Sumw2() ; FeShield_Bi214 -> Scale( (  122.319         ) / FeShield_Bi214  ->Integral() ) ; bkgdNames.push_back("FeShield_Bi214"); vbkgd.push_back( FeShield_Bi214 );
    /* 20 */ fdir = (TDirectory *) infile->Get("FeShield_Tl208" ); fdir->cd(); TH1D *  FeShield_Tl208   = (TH1D *) infile->Get("FeShield_Tl208_h_tot_e_energy" ) -> Clone( "FeShield_Tl208" ) ; FeShield_Tl208 -> Sumw2() ; FeShield_Tl208 -> Scale( (  6.62106         ) / FeShield_Tl208  ->Integral() ) ; bkgdNames.push_back("FeShield_Tl208"); vbkgd.push_back( FeShield_Tl208 );
    /* 21 */ fdir = (TDirectory *) infile->Get("FeShield_Ac228" ); fdir->cd(); TH1D *  FeShield_Ac228   = (TH1D *) infile->Get("FeShield_Ac228_h_tot_e_energy" ) -> Clone( "FeShield_Ac228" ) ; FeShield_Ac228 -> Sumw2() ; FeShield_Ac228 -> Scale( ( 0.264067         ) / FeShield_Ac228  ->Integral() ) ; bkgdNames.push_back("FeShield_Ac228"); vbkgd.push_back( FeShield_Ac228 );
    /* 22 */ fdir = (TDirectory *) infile->Get("CuTower_Co60"   ); fdir->cd(); TH1D *  CuTower_Co60     = (TH1D *) infile->Get("CuTower_Co60_h_tot_e_energy"   ) -> Clone( "CuTower_Co60"   ) ; CuTower_Co60   -> Sumw2() ; CuTower_Co60   -> Scale( (  9.43038         ) / CuTower_Co60    ->Integral() ) ; bkgdNames.push_back("CuTower_Co60"  ); vbkgd.push_back( CuTower_Co60   );
    /* 23 */ fdir = (TDirectory *) infile->Get("Air_Bi214"      ); fdir->cd(); TH1D *  Air_Bi214_P1     = (TH1D *) infile->Get("Air_Bi214_h_tot_e_energy"      ) -> Clone( "Air_Bi214_P1"   ) ; Air_Bi214_P1   -> Sumw2() ; Air_Bi214_P1   -> Scale( ( 23.7466          ) / Air_Bi214_P1    ->Integral() ) ; bkgdNames.push_back("Air_Bi214_P1"  ); vbkgd.push_back( Air_Bi214_P1   );
    /* 24 */ fdir = (TDirectory *) infile->Get("Air_Tl208"      ); fdir->cd(); TH1D *  Air_Tl208_P1     = (TH1D *) infile->Get("Air_Tl208_h_tot_e_energy"      ) -> Clone( "Air_Tl208_P1"   ) ; Air_Tl208_P1   -> Sumw2() ; Air_Tl208_P1   -> Scale( ( 2.13679          ) / Air_Tl208_P1    ->Integral() ) ; bkgdNames.push_back("Air_Tl208_P1"  ); vbkgd.push_back( Air_Tl208_P1   );
    /* 25 */ fdir = (TDirectory *) infile->Get("PMT_Bi214"      ); fdir->cd(); TH1D *  PMT_Bi214        = (TH1D *) infile->Get("PMT_Bi214_h_tot_e_energy"      ) -> Clone( "PMT_Bi214"      ) ; PMT_Bi214      -> Sumw2() ; PMT_Bi214      -> Scale( ( 104.462          ) / PMT_Bi214       ->Integral() ) ; bkgdNames.push_back("PMT_Bi214"     ); vbkgd.push_back( PMT_Bi214      );
    /* 26 */ fdir = (TDirectory *) infile->Get("PMT_Tl208"      ); fdir->cd(); TH1D *  PMT_Tl208        = (TH1D *) infile->Get("PMT_Tl208_h_tot_e_energy"      ) -> Clone( "PMT_Tl208"      ) ; PMT_Tl208      -> Sumw2() ; PMT_Tl208      -> Scale( (  154.14          ) / PMT_Tl208       ->Integral() ) ; bkgdNames.push_back("PMT_Tl208"     ); vbkgd.push_back( PMT_Tl208      );
    /* 27 */ fdir = (TDirectory *) infile->Get("PMT_Ac228"      ); fdir->cd(); TH1D *  PMT_Ac228        = (TH1D *) infile->Get("PMT_Ac228_h_tot_e_energy"      ) -> Clone( "PMT_Ac228"      ) ; PMT_Ac228      -> Sumw2() ; PMT_Ac228      -> Scale( ( 8.66286          ) / PMT_Ac228       ->Integral() ) ; bkgdNames.push_back("PMT_Ac228"     ); vbkgd.push_back( PMT_Ac228      );
    /* 28 */ fdir = (TDirectory *) infile->Get("PMT_K40"        ); fdir->cd(); TH1D *  PMT_K40          = (TH1D *) infile->Get("PMT_K40_h_tot_e_energy"        ) -> Clone( "PMT_K40"        ) ; PMT_K40        -> Sumw2() ; PMT_K40        -> Scale( ( 45.6541          ) / PMT_K40         ->Integral() ) ; bkgdNames.push_back("PMT_K40"       ); vbkgd.push_back( PMT_K40        );
    /* 29 */ fdir = (TDirectory *) infile->Get("ScintInn_K40"   ); fdir->cd(); TH1D *  ScintInn_K40     = (TH1D *) infile->Get("ScintInn_K40_h_tot_e_energy"   ) -> Clone( "ScintInn_K40"   ) ; ScintInn_K40   -> Sumw2() ; ScintInn_K40   -> Scale( ( 1.34227          ) / ScintInn_K40    ->Integral() ) ; bkgdNames.push_back("ScintInn_K40"  ); vbkgd.push_back( ScintInn_K40   );
    /* 30 */ fdir = (TDirectory *) infile->Get("ScintOut_K40"   ); fdir->cd(); TH1D *  ScintOut_K40     = (TH1D *) infile->Get("ScintOut_K40_h_tot_e_energy"   ) -> Clone( "ScintOut_K40"   ) ; ScintOut_K40   -> Sumw2() ; ScintOut_K40   -> Scale( ( 1.81207          ) / ScintOut_K40    ->Integral() ) ; bkgdNames.push_back("ScintOut_K40"  ); vbkgd.push_back( ScintOut_K40   );
    /* 31 */ fdir = (TDirectory *) infile->Get("ScintPet_K40"   ); fdir->cd(); TH1D *  ScintPet_K40     = (TH1D *) infile->Get("ScintPet_K40_h_tot_e_energy"   ) -> Clone( "ScintPet_K40"   ) ; ScintPet_K40   -> Sumw2() ; ScintPet_K40   -> Scale( ( 1.00669          ) / ScintPet_K40    ->Integral() ) ; bkgdNames.push_back("ScintPet_K40"  ); vbkgd.push_back( ScintPet_K40   );
    /* 32 */ fdir = (TDirectory *) infile->Get("MuMetal_Pa234m" ); fdir->cd(); TH1D *  MuMetal_Pa234m   = (TH1D *) infile->Get("MuMetal_Pa234m_h_tot_e_energy" ) -> Clone( "MuMetal_Pa234m" ) ; MuMetal_Pa234m -> Sumw2() ; MuMetal_Pa234m -> Scale( ( 1.67054          ) / MuMetal_Pa234m  ->Integral() ) ; bkgdNames.push_back("MuMetal_Pa234m"); vbkgd.push_back( MuMetal_Pa234m );
    /* 33 */ fdir = (TDirectory *) infile->Get("Cd116_2b2n_m14" ); fdir->cd(); TH1D *  Cd116_2b2n_m14   = (TH1D *) infile->Get("Cd116_2b2n_m14_h_tot_e_energy" ) -> Clone( "Cd116_2b2n_m14" ) ; Cd116_2b2n_m14 -> Sumw2() ; Cd116_2b2n_m14 -> Scale( ( 5935.43          ) / Cd116_2b2n_m14  ->Integral() ) ; bkgdNames.push_back("Cd116_2b2n_m14"); vbkgd.push_back( Cd116_2b2n_m14 );
    
	//fdir->Close();
	//infile->Close();
  
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
  
	TString outfileDir( "/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie/" );
    TString outfileName;
	outfileName.Form( "CollieIO_En_%s.root", myModel.Data() );	
  	outfileName = outfileDir + outfileName;
  
    cfile->initFile( outfileName.Data() , "Energy");  
  
    cfile->setInputHist(data->GetXaxis()->GetBinLowEdge(1),data->GetXaxis()->GetBinUpEdge(data->GetNbinsX()),data->GetNbinsX());
  
    // Option to define physical cutoffs where events should not exist (in terms of your historam range)
    //
    //cfile->setCutoffs(-0.8,0.8);   
  
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
	cfile->createFlatSigSystematic("IsotopeMass"     , 0.0025 , 0.0025 ,100);
	cfile->createFlatSigSystematic("Efficiency"      , 0.0550 , 0.0550 ,100);
	cfile->createFlatSigSystematic("Bremsstrahlung"  , 0.0050 , 0.0012 ,100);
	cfile->createFlatSigSystematic("ThinFoil"        , 0.0073 , 0.0073 ,100);
	cfile->createFlatSigSystematic("EnCalib"         , 0.0025 , 0.0025 ,100);
	
	// Tl-208 Systematics
	cfile->createFlatBkgdSystematic(  0 , "Tl208"    , 0.0004 , 0.0004 ,100);
	cfile->createFlatBkgdSystematic(  1 , "Tl208"    , 0.0004 , 0.0004 ,100);
	cfile->createFlatBkgdSystematic(  2 , "Tl208"    , 0.0004 , 0.0004 ,100);
	cfile->createFlatBkgdSystematic( 14 , "Tl208"    , 0.0004 , 0.0004 ,100);
	
	// Bi-214 Systematic
	cfile->createFlatBkgdSystematic(  3 , "Bi214"    , 0.0007 , 0.0007 ,100);
	cfile->createFlatBkgdSystematic(  4 , "Bi214"    , 0.0007 , 0.0007 ,100);
	cfile->createFlatBkgdSystematic(  5 , "Bi214"    , 0.0007 , 0.0007 ,100);
	cfile->createFlatBkgdSystematic(  6 , "Bi214"    , 0.0007 , 0.0007 ,100);
	
	// Internal Systematic
	cfile->createFlatBkgdSystematic(  7 , "Internal" , 0.0140 , 0.0176 ,100);
	cfile->createFlatBkgdSystematic(  8 , "Internal" , 0.0140 , 0.0176 ,100);
	cfile->createFlatBkgdSystematic(  9 , "Internal" , 0.0140 , 0.0176 ,100);
	cfile->createFlatBkgdSystematic( 10 , "Internal" , 0.0140 , 0.0176 ,100);
	
	// Radon Systematic
	cfile->createFlatBkgdSystematic( 15 , "Radon"    , 0.0004 , 0.0004 ,100);	
	cfile->createFlatBkgdSystematic( 16 , "Radon"    , 0.0004 , 0.0004 ,100);	
	cfile->createFlatBkgdSystematic( 17 , "Radon"    , 0.0004 , 0.0004 ,100);	
	cfile->createFlatBkgdSystematic( 18 , "Radon"    , 0.0004 , 0.0004 ,100);	
	
	// Externals Systematic
	cfile->createFlatBkgdSystematic( 11 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 12 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 13 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 19 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 20 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 21 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 22 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 23 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 24 , "Externals"  , 0.0061 , 0.0129 ,100);	 
	cfile->createFlatBkgdSystematic( 25 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 26 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 27 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 28 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 29 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 30 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 31 , "Externals"  , 0.0061 , 0.0129 ,100);	
	cfile->createFlatBkgdSystematic( 32 , "Externals"  , 0.0061 , 0.0129 ,100);	

	// bb2nu
	cfile->createFlatBkgdSystematic( 33 , "bb2nu"      , 0.0220 , 0.0220 ,100);	
	
	///store and output channel information
	cfile->storeFile();
  
}
