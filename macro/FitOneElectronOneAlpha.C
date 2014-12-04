{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronOneAlphaHistos", "OneElectronOneAlphaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141120/OneElectronOneAlphaHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	double sscin_activity_bi214=(0.291*15.19 + 0.431*34.94 + 0.418*9.68)/59.81;
	double sscin_activity_bi210=(28.6*15.19 + 34.6*34.94 + 27.9*9.68)/59.81;

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddParameter( new Parameter("Air_Bi214_P1"   ,  1 ,            566.50    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Air_Pb214_P1"   ,  2 ,            566.50    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SFoil_Bi210_P1" ,  5 ,              1.60    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SFoil_Bi214_P1" ,  7 ,              0.00854 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SScin_Bi214_P1" ,  8 ,              0.00854 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SScin_Bi210_P1" ,  9 , sscin_activity_bi214 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SWire_Bi214_P1" , 10 , sscin_activity_bi214 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SWire_Bi210_P1" , 11 , sscin_activity_bi210 , 0.001 ) );        
	DataManagement::AddParameter( new Parameter("SWire_Tl208_P1" , 12 ,             1.12     , 0.001 ) );
					
	DataManagement::AddParameter( new Parameter("Air_Bi214_P2"   ,  1 ,            566.50    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Air_Pb214_P2"   ,  2 ,            566.50    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SFoil_Bi210_P2" ,  5 ,              1.60    , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SFoil_Bi214_P2" ,  7 ,              0.00854 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SScin_Bi214_P2" ,  8 ,              0.00854 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SScin_Bi210_P2" ,  9 , sscin_activity_bi214 , 0.001 ) );
	DataManagement::AddParameter( new Parameter("SWire_Bi214_P2" , 10 , sscin_activity_bi214 , 0.001 ) );            
	DataManagement::AddParameter( new Parameter("SWire_Bi210_P2" , 11 , sscin_activity_bi210 , 0.001 ) );                   
	DataManagement::AddParameter( new Parameter("SWire_Tl208_P2" , 12 ,             1.12     , 0.001 ) );           

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component("Air_Bi214_P1"   , "^{214}Bi LSM Air P1 " , DataManagement::FindDataSet( "Air_Bi214"   ) , DataManagement::FindParameter( "Air_Bi214"      ) , 1.0 )); DataManagement::FindComponent("Air_Bi214_P1"   )->SetFillColor( kCyan  +  4 );
	DataManagement::AddComponent( new Component("Air_Pb214_P1"   , "^{214}Pb LSM Air P1 " , DataManagement::FindDataSet( "Air_Pb214"   ) , DataManagement::FindParameter( "Air_Pb214"      ) , 1.0 )); DataManagement::FindComponent("Air_Pb214_P1"   )->SetFillColor( kCyan  +  3 );
	DataManagement::AddComponent( new Component("SFoil_Bi210_P1" , "^{210}Bi SFoil P1   " , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "SFoil_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Bi210_P1" )->SetFillColor( kAzure -  9 );
	DataManagement::AddComponent( new Component("SFoil_Bi214_P1" , "^{214}Bi SFoil P1   " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Bi214_P1" )->SetFillColor( kAzure -  7 );
	DataManagement::AddComponent( new Component("SFoil_Pb214_P1" , "^{214}Pb SFoil P1   " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Pb214_P1" )->SetFillColor( kAzure -  5 );
	DataManagement::AddComponent( new Component("SScin_Bi214_P1" , "^{214}Bi SScin P1   " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Bi214_P1" )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component("SScin_Pb214_P1" , "^{214}Pb SScin P1   " , DataManagement::FindDataSet( "SScin_Pb214" ) , DataManagement::FindParameter( "SScin_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Pb214_P1" )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component("SScin_Bi210_P1" , "^{210}Bi SScin P1   " , DataManagement::FindDataSet( "SScin_Bi210" ) , DataManagement::FindParameter( "SScin_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Bi210_P1" )->SetFillColor( kAzure +  5 );
	DataManagement::AddComponent( new Component("SWire_Bi214_P1" , "^{214}Bi SWire P1   " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Bi214_P1" )->SetFillColor( kAzure -  3 );            
	DataManagement::AddComponent( new Component("SWire_Pb214_P1" , "^{214}Pb SWire P1   " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "SWire_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Pb214_P1" )->SetFillColor( kAzure -  1 );            
	DataManagement::AddComponent( new Component("SWire_Bi210_P1" , "^{210}Bi SWire P1   " , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "SWire_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Bi210_P1" )->SetFillColor( kAzure +  7 );           
	DataManagement::AddComponent( new Component("SWire_Tl208_P1" , "^{208}Tl SWire P1   " , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "SWire_Tl208P1"  ) , 1.0 )); DataManagement::FindComponent("SWire_Tl208_P1" )->SetFillColor( kAzure +  9 );           	

	DataManagement::AddComponent( new Component("Air_Bi214_P2"   , "^{214}Bi LSM Air P2 " , DataManagement::FindDataSet( "Air_Bi214"   ) , DataManagement::FindParameter( "Air_Bi214"      ) , 1.0 )); DataManagement::FindComponent("Air_Bi214_P2"   )->SetFillColor( kCyan  +  2 );
	DataManagement::AddComponent( new Component("Air_Pb214_P2"   , "^{214}Pb LSM Air P2 " , DataManagement::FindDataSet( "Air_Pb214"   ) , DataManagement::FindParameter( "Air_Pb214"      ) , 1.0 )); DataManagement::FindComponent("Air_Pb214_P2"   )->SetFillColor( kCyan  +  1 );
	DataManagement::AddComponent( new Component("SFoil_Bi210_P2" , "^{210}Bi SFoil P2   " , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "SFoil_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Bi210_P2" )->SetFillColor( kAzure -  8 );
	DataManagement::AddComponent( new Component("SFoil_Bi214_P2" , "^{214}Bi SFoil P2   " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Bi214_P2" )->SetFillColor( kAzure -  6 );
	DataManagement::AddComponent( new Component("SFoil_Pb214_P2" , "^{214}Pb SFoil P2   " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SFoil_Pb214_P2" )->SetFillColor( kAzure -  4 );
	DataManagement::AddComponent( new Component("SScin_Bi214_P2" , "^{214}Bi SScin P2   " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Bi214_P2" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component("SScin_Pb214_P2" , "^{214}Pb SScin P2   " , DataManagement::FindDataSet( "SScin_Pb214" ) , DataManagement::FindParameter( "SScin_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Pb214_P2" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component("SScin_Bi210_P2" , "^{210}Bi SScin P2   " , DataManagement::FindDataSet( "SScin_Bi210" ) , DataManagement::FindParameter( "SScin_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SScin_Bi210_P2" )->SetFillColor( kAzure +  6 );
	DataManagement::AddComponent( new Component("SWire_Bi214_P2" , "^{214}Bi SWire P2   " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Bi214_P2" )->SetFillColor( kAzure -  2 );            
	DataManagement::AddComponent( new Component("SWire_Pb214_P2" , "^{214}Pb SWire P2   " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "SWire_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Pb214_P2" )->SetFillColor( kAzure +  0 );            
	DataManagement::AddComponent( new Component("SWire_Bi210_P2" , "^{210}Bi SWire P2   " , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "SWire_Bi210_P1" ) , 1.0 )); DataManagement::FindComponent("SWire_Bi210_P2" )->SetFillColor( kAzure +  8 );           
	DataManagement::AddComponent( new Component("SWire_Tl208_P2" , "^{208}Tl SWire P2   " , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "SWire_Tl208P1"  ) , 1.0 )); DataManagement::FindComponent("SWire_Tl208_P2" )->SetFillColor( kAzure + 10 );           
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_cold = new Observable("e_energy_P1_cold" , "One electron energy - Phase 1 - Cold" , kPhaseOne , hcoll->Find("Data_h_e_energy_P1_cold") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P1_cold"    ) ); // Externals {
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P1_cold"  ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P1_cold" ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P1_cold" ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P1_cold" ) ); // } Externals 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P1_cold"          ) ); // { Radon
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P1"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P1"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P1"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_cold"      ) ); // } Radon
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_cold"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_cold"      ) ); // Internals {
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_cold"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_cold"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_cold"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_cold"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1_cold"   ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_cold"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"     ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_cold"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_cold"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_cold"      ) ); // } Internals
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P1_cold"   ) );
	
	DataManagement::AddObservable( e_energy_P1_cold );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P2_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P2_cold = new Observable("e_energy_P2_cold" , "One electron energy - Phase 2 - Cold" , kPhaseTwo , hcoll->Find("Data_h_e_energy_P2_cold") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P2_cold"    ) ); // Externals {
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P2_cold"  ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P2_cold" ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P2_cold" ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P2_cold" ) ); // } Externals 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P2_cold"          ) ); // { Radon
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Air_Bi214_P2"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Air_Pb214_P2"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P2"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P2"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P2"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_cold"      ) ); // } Radon
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_cold"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_cold"      ) ); // Internals {
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_cold"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_cold"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_cold"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_cold"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P2_cold"   ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_cold"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_cold"     ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_cold"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_cold"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_cold"      ) ); // } Internals
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P2_cold"   ) );
	
	DataManagement::AddObservable( e_energy_P2_cold );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_warm
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_warm = new Observable("e_energy_P1_warm" , "One electron energy - Phase 1 - Warm" , kPhaseOne , hcoll->Find("Data_h_e_energy_P1_warm") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P1_warm"    ) ); // Externals {
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P1_warm"  ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P1_warm" ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P1_warm" ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P1_warm" ) ); // } Externals 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P1_warm"          ) ); // { Radon
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P1"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P1"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P1"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_warm"      ) ); // } Radon
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_warm"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_warm"      ) ); // Internals {
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_warm"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_warm"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_warm"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_warm"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1_warm"   ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_warm"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm"     ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_warm"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_warm"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_warm"      ) ); // } Internals
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P1_warm"   ) );
	
	DataManagement::AddObservable( e_energy_P1_warm );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P2_warm
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P2_warm = new Observable("e_energy_P2_warm" , "One electron energy - Phase 2 - Warm" , kPhaseTwo , hcoll->Find("Data_h_e_energy_P2_warm") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P2_warm"    ) ); // Externals {
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P2_warm"  ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P2_warm" ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P2_warm" ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P2_warm" ) ); // } Externals 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P2_warm"          ) ); // { Radon
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Air_Bi214_P2"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Air_Pb214_P2"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P2"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P2"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P2"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_warm"      ) ); // } Radon
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_warm"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_warm"      ) ); // Internals {
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_warm"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_warm"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_warm"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_warm"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P2_warm"   ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_warm"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_warm"     ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_warm"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_warm"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_warm"      ) ); // } Internals
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P2_warm"   ) );
	
	DataManagement::AddObservable( e_energy_P2_warm );	

	e_energy_P1_cold->Draw();
	e_energy_P1_warm->Draw();
	e_energy_P2_cold->Draw();
	e_energy_P2_warm->Draw();

	Fit::Run("Minuit", "Migrad");

	e_energy_P1_cold->Draw();
	e_energy_P1_warm->Draw();
	e_energy_P2_cold->Draw();
	e_energy_P2_warm->Draw();


}
