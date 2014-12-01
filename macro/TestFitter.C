{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141120/OneElectronHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddParameter( new Parameter("Externals" , "External Backgrounds" , 0 , 1.0 , 1.1 , 0.9 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Radon"     , "Radon Backgrounds"    , 1 , 1.0 , 1.1 , 0.9 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Internals" , "Internal Backgrounds" , 2 , 1.0 , 1.1 , 0.9 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("2b2nu"     , "2e2#nu"               , 3 , 1.0 , 1.1 , 0.9 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "CuPetals_Co60"    , "^{60}Co CuPetals     " , "CuPetals_Co60"    , "Externals" , 47.6 ) ); 
	DataManagement::AddComponent( new Component( "CuTower_Co60"     , "^{60}Co CuTower      " , "CuTower_Co60"     , "Externals" , 18.4 ) ); 
	DataManagement::AddComponent( new Component( "MuMetal_Co60"     , "^{60}Co MuMetal      " , "MuMetal_Co60"     , "Externals" , 14.6 ) ); 
	DataManagement::AddComponent( new Component( "SteelFrame_Co60"  , "^{60}Co SteelFrame   " , "SteelFrame_Co60"  , "Externals" , 6.09 ) ); 
	DataManagement::AddComponent( new Component( "FeShield_Ac228"   , "^{228}Ac FeShield    " , "FeShield_Ac228"   , "Externals" , 1350 ) ); 
	DataManagement::AddComponent( new Component( "PMT_Ac228"        , "^{228}Ac PMT         " , "PMT_Ac228"        , "Externals" , 72.7 ) ); 
	DataManagement::AddComponent( new Component( "SteelFrame_Ac228" , "^{228}Ac SteelFrame  " , "SteelFrame_Ac228" , "Externals" , 8.54 ) ); 
	DataManagement::AddComponent( new Component( "FeShield_Bi214"   , "^{214}Bi FeShield    " , "FeShield_Bi214"   , "Externals" , 7360 ) ); 
	DataManagement::AddComponent( new Component( "PMT_Bi214"        , "^{214}Bi PMT         " , "PMT_Bi214"        , "Externals" ,  324 ) ); 
	DataManagement::AddComponent( new Component( "SteelFrame_Bi214" , "^{214}Bi SteelFrame  " , "SteelFrame_Bi214" , "Externals" ,  9.1 ) ); 
	DataManagement::AddComponent( new Component( "FeShield_Tl208"   , "^{208}Tl FeShield    " , "FeShield_Tl208"   , "Externals" ,  484 ) ); 
	DataManagement::AddComponent( new Component( "PMT_Tl208"        , "^{208}Tl PMT         " , "PMT_Tl208"        , "Externals" , 27.0 ) ); 
	DataManagement::AddComponent( new Component( "SteelFrame_Tl208" , "^{208}Tl SteelFrame  " , "SteelFrame_Tl208" , "Externals" ,  3.1 ) ); 
	DataManagement::AddComponent( new Component( "PMT_K40"          , "^{40}K PMT           " , "PMT_K40"          , "Externals" , 1078 ) ); 
	DataManagement::AddComponent( new Component( "ScintInn_K40"     , "^{40}K Inner Scint.  " , "ScintInn_K40"     , "Externals" , 7.59 ) ); 
	DataManagement::AddComponent( new Component( "ScintOut_K40"     , "^{40}K Outer Scint.  " , "ScintOut_K40"     , "Externals" ,12.53 ) ); 
	DataManagement::AddComponent( new Component( "ScintPet_K40"     , "^{40}K Petal Scint.  " , "ScintPet_K40"     , "Externals" , 1.39 ) ); 
	DataManagement::AddComponent( new Component( "SteelFrame_K40"   , "^{40}K SteelFrame    " , "SteelFrame_K40"   , "Externals" ,  100 ) ); 
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	double sscin_activity_bi214=(0.291*15.19 + 0.431*34.94 + 0.418*9.68)/59.81;
	double sscin_activity_bi210=(28.6*15.19 + 34.6*34.94 + 27.9*9.68)/59.81;
	DataManagement::AddComponent( new Component("Air_Bi214_P1"         , "^{214}Bi LSM Air P1     "   , "Air_Bi214"   , "Radon" ,                566.5 ));
	DataManagement::AddComponent( new Component("Air_Pb214_P1"         , "^{214}Pb LSM Air P1     "   , "Air_Pb214"   , "Radon" ,                566.5 ));
	DataManagement::AddComponent( new Component("Air_Bi214_P2"         , "^{214}Bi LSM Air P2     "   , "Air_Bi214"   , "Radon" ,                  0.0 ));
	DataManagement::AddComponent( new Component("Air_Pb214_P2"         , "^{214}Pb LSM Air P2     "   , "Air_Pb214"   , "Radon" ,                  0.0 ));
	DataManagement::AddComponent( new Component("SFoil_Bi214_P1"       , "^{214}Bi SFoil P1       "   , "SFoil_Bi214" , "Radon" ,             0.009955 ));
	DataManagement::AddComponent( new Component("SFoil_Bi214_P2"       , "^{214}Bi SFoil P2       "   , "SFoil_Bi214" , "Radon" ,             0.001881 ));
	DataManagement::AddComponent( new Component("SFoil_Pb214_P1"       , "^{214}Pb SFoil P1       "   , "SFoil_Pb214" , "Radon" ,             0.009955 ));
	DataManagement::AddComponent( new Component("SFoil_Pb214_P2"       , "^{214}Pb SFoil P2       "   , "SFoil_Pb214" , "Radon" ,             0.001881 ));
	DataManagement::AddComponent( new Component("SWire_Bi214_P1"       , "^{214}Bi SWire P1       "   , "SWire_Bi214" , "Radon" ,             0.851706 ));             
	DataManagement::AddComponent( new Component("SWire_Bi214_P2"       , "^{214}Bi SWire P2       "   , "SWire_Bi214" , "Radon" ,             0.110407 ));             
	DataManagement::AddComponent( new Component("SWire_Pb214_P1"       , "^{214}Pb SWire P1       "   , "SWire_Pb214" , "Radon" ,             0.851706 ));             
	DataManagement::AddComponent( new Component("SWire_Pb214_P2"       , "^{214}Pb SWire P2       "   , "SWire_Pb214" , "Radon" ,             0.110407 ));             
	DataManagement::AddComponent( new Component("SScin_Bi214_P1"       , "^{214}Bi SScin P1       "   , "SScin_Bi214" , "Radon" , sscin_activity_bi214 )); 
	DataManagement::AddComponent( new Component("SScin_Bi214_P2"       , "^{214}Bi SScin P2       "   , "SScin_Bi214" , "Radon" , sscin_activity_bi214 )); 
	DataManagement::AddComponent( new Component("SScin_Pb214_P1"       , "^{214}Pb SScin P1       "   , "SScin_Pb214" , "Radon" , sscin_activity_bi214 )); 
	DataManagement::AddComponent( new Component("SScin_Pb214_P2"       , "^{214}Pb SScin P2       "   , "SScin_Pb214" , "Radon" , sscin_activity_bi214 )); 
	DataManagement::AddComponent( new Component("SFoil_Bi210_MoMet_P1" , "^{210}Bi SFoil MoMet P1 "   , "SFoil_Bi210" , "Radon" ,                  0.0 ));        
	DataManagement::AddComponent( new Component("SFoil_Bi210_MoCom_P1" , "^{210}Bi SFoil MoCom P1 "   , "SFoil_Bi210" , "Radon" ,             0.225811 ));        
	DataManagement::AddComponent( new Component("SFoil_Bi210_MoMet_P2" , "^{210}Bi SFoil MoMet P2 "   , "SFoil_Bi210" , "Radon" ,                  0.0 ));        
	DataManagement::AddComponent( new Component("SFoil_Bi210_MoCom_P2" , "^{210}Bi SFoil MoCom P2 "   , "SFoil_Bi210" , "Radon" ,             0.225811 ));        
	DataManagement::AddComponent( new Component("SScin_Bi210_P1"       , "^{210}Bi SScin P1       "   , "SScin_Bi210" , "Radon" , sscin_activity_bi210 )); 
	DataManagement::AddComponent( new Component("SScin_Bi210_P2"       , "^{210}Bi SScin P2       "   , "SScin_Bi210" , "Radon" , sscin_activity_bi210 )); 
	DataManagement::AddComponent( new Component("SWire_Bi210_P1"       , "^{210}Bi SWire P1       "   , "SWire_Bi210" , "Radon" ,            17.353306 ));            
	DataManagement::AddComponent( new Component("SWire_Bi210_P2"       , "^{210}Bi SWire P2       "   , "SWire_Bi210" , "Radon" ,            14.961481 ));            
	DataManagement::AddComponent( new Component("SWire_Tl208_P1"       , "^{208}Tl SWire P1       "   , "SWire_Tl208" , "Radon" ,               3.5e-3 ));            
	DataManagement::AddComponent( new Component("SWire_Tl208_P2"       , "^{208}Tl SWire P2       "   , "SWire_Tl208" , "Radon" ,               2.9e-3 ));            
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component("Cd116_Tl208_cold"  , "^{208}Tl Cold region  " , "Cd116_Tl208"    , "Internals" , 1.7e-2       ));
	DataManagement::AddComponent( new Component("Cd116_Ac228_cold"  , "^{228}Ac Cold region  " , "Cd116_Ac228"    , "Internals" , 2.782*1.7e-2 ));
	DataManagement::AddComponent( new Component("Cd116_Bi212_cold"  , "^{212}Bi Cold region  " , "Cd116_Bi212"    , "Internals" , 2.782*1.7e-2 ));
	DataManagement::AddComponent( new Component("Cd116_Bi214_cold"  , "^{214}Bi Cold region  " , "Cd116_Bi214"    , "Internals" , 0.162        ));
	DataManagement::AddComponent( new Component("Cd116_Pb214_cold"  , "^{214}Pb Cold region  " , "Cd116_pb214_VT" , "Internals" , 0.162        ));
	DataManagement::AddComponent( new Component("Cd116_Cs137_cold"  , "^{137}Cs Cold region  " , "Cd116_Cs137"    , "Internals" , 1.210        ));
	DataManagement::AddComponent( new Component("Cd116_K40_cold"    , "^{40}K Mo Cold region " , "Cd116_K40"      , "Internals" , 3.393        ));
	DataManagement::AddComponent( new Component("Cd116_Pa234m_cold" , "^{234m}Pa Cold region " , "Cd116_Pa234m"   , "Internals" , 0.260        ));
                                                                                                                  
	DataManagement::AddComponent( new Component("Cd116_Tl208_warm"  , "^{208}Tl Warm region  " , "Cd116_Tl208"    , "Internals" , 4.1e-2       ));
	DataManagement::AddComponent( new Component("Cd116_Ac228_warm"  , "^{228}Ac Warm region  " , "Cd116_Ac228"    , "Internals" , 2.782*4.1e-2 ));
	DataManagement::AddComponent( new Component("Cd116_Bi212_warm"  , "^{212}Bi Warm region  " , "Cd116_Bi212"    , "Internals" , 2.782*4.1e-2 ));
	DataManagement::AddComponent( new Component("Cd116_Bi214_warm"  , "^{214}Bi Warm region  " , "Cd116_Bi214"    , "Internals" , 0.389        ));
	DataManagement::AddComponent( new Component("Cd116_Pb214_warm"  , "^{214}Pb Warm region  " , "Cd116_pb214_VT" , "Internals" , 0.389        ));
	DataManagement::AddComponent( new Component("Cd116_Cs137_warm"  , "^{137}Cs Warm region  " , "Cd116_Cs137"    , "Internals" , 1.210        ));
	DataManagement::AddComponent( new Component("Cd116_K40_warm"    , "^{40}K Mo Warm region " , "Cd116_K40"      , "Internals" , 8.390        ));
	DataManagement::AddComponent( new Component("Cd116_Pa234m_warm" , "^{234m}Pa Warm region " , "Cd116_Pa234m"   , "Internals" , 1.010        ));
                                                                                                                  
	DataManagement::AddComponent( new Component("Mylar_Bi214"       , "^{214}Bi Mylar        " , "Mylar_Bi214"    , "Internals",  0.000653      ));
	DataManagement::AddComponent( new Component("Mylar_Pb214"       , "^{214}Pb Mylar        " , "Mylar_Pb214"    , "Internals",  0.000653      ));

	//DataManagement::AddComponents( new Component("Cd116_cold_Co60"   , "^{60}Co Cold region   " , "Cd116_Co60"   , "Internals" , 1.98e-3               ));
	//DataManagement::AddComponents( new Component("Cd116_cold_Tl207"  , "^{207}Tl Cold region  " , "MoCom_Tl207"  , "Internals_MoCom",  Act_MoCom_Tl207      ));
	//DataManagement::AddComponents( new Component("Cd116_cold_Pb211"  , "^{211}Pb Cold region  " , "MoCom_Pb211"  , "Internals_MoCom",  Act_MoCom_Tl207      ));
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define 2b2nu components
	//
	//////////////////////////////////////////////////////////////////////////////
	double mass = 1. ; // g
	DataManagement::AddComponent( new Component("2b2nu" , "2e2#nu" , "Cd116_2b2n_m14" , "2b2nu",  1 ));

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1 = new Observable("e_energy_P1_cold" , "One electron energy - Phase 1 - Cold" , kPhaseOne , hcoll->Find("Data_h_e_energy_P1_cold") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P1_cold"    ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P1_cold"  ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_cold"   ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_cold"        ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P1_cold" ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_cold"   ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_cold"        ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P1_cold" ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_cold"   ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_cold"        ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P1_cold" ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P1_cold"          ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P1_cold"   ) ); 
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_cold"        ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_cold"        ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P1"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P1"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_cold"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_cold"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_cold"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_cold"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_cold"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1_cold"   ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_cold"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"        ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"     ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P1_cold"   ) );
	
	DataManagement::AddObservable( e_energy_P1 );	

	Fit::Run("Minuit", "Migrad");

	// TODO
	// 1 - Implement a xcheck of the DataSet being used. The DataSet name is not enough!
	// 2 - Compute initial normalisation for 2b2nu
	// 3 - Handle posterio parameter (Get a new ParameterCollection from the fitter ?)
	// 4 - Plotting macro => W/o see what's going on I'm kind of blinded.

}
