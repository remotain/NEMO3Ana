{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "Cd116_K40"    , "Cd116_K40"    , 0 , 9.85562e-03 , 0.001 ) ); //DataManagement::FindParameter( "Cd116_K40"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m" , "Cd116_Pa234m" , 1 , 2.33036e-03 , 0.001 ) ); //DataManagement::FindParameter( "Cd116_Pa234m"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210"  , "SFoil_Bi210"  , 2 , 2.12 , 0.001 ) ); // DataManagement::FindParameter( "SFoil_Bi210" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"  , "SScin_Bi210"  , 3 , 20.4 , 0.001 ) ); //DataManagement::FindParameter( "Scin_Bi210"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SWire_Bi210"  , "SWire_Bi210"  , 4 , 2.40 , 0.001 ) ); //DataManagement::FindParameter( "Scin_Bi210"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "cRn"          , "cRn"          , 5 , 1   , 0.001 ) ); DataManagement::FindParameter( "cRn"  ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cInt"         , "cInt"         , 6 , 1   , 0.001 ) ); DataManagement::FindParameter( "cInt" ) -> SetFix();    
	DataManagement::AddParameter( new Parameter( "cExt"         , "cExt"         , 7 , 1.  , 0.001 ) ); DataManagement::FindParameter( "cExt" ) -> SetFix();

	//DataManagement::AddParameter( new Parameter( "cShield"      , "cShield"     , 5 , 1.      , 0.001 ) ); DataManagement::FindParameter( "cShield" ) -> SetFix();
	//DataManagement::AddParameter( new Parameter( "cCo"          , "cCo"         , 6 , 1.      , 0.001 ) ); DataManagement::FindParameter( "cCo"     ) -> SetFix();
	//DataManagement::AddParameter( new Parameter( "cPMT"         , "cPMT"        , 7 , 1.      , 0.001 ) ); DataManagement::FindParameter( "cPMT"    ) -> SetFix();
	//DataManagement::AddParameter( new Parameter( "cAir"         , "cAir"        , 8 , 1.      , 0.001 ) ); DataManagement::FindParameter( "cAir"    ) -> SetFix();
	//DataManagement::AddParameter( new Parameter( "cK40"         , "cK40"        , 10, 1.      , 0.001 ) ); DataManagement::FindParameter( "cK40"  ) -> SetFix();
	//////////////////////////////////////////////////////////////////////////////
	//	
	// bb2nu
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ) , DataManagement::GetNormBB()/2.89e19, 1. )); DataManagement::FindComponent("Cd116_2b2n_m14")  ->SetFillColor( kViolet + 10 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Single Beta emitter
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40"    , "^{40}K Cd116"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40"    ) , 1. )); DataManagement::FindComponent("Cd116_K40"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m" , "^{234m}Pa Cd116" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m" ) -> SetFillColor( kViolet + 2 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-210 on the Surface of the foil
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "SFoil_Bi210"  , "^{210}Bi SFoil"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "SFoil_Bi210"       ) , 1. ));   DataManagement::FindComponent("SFoil_Bi210") -> SetFillColor( kGreen + 2 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-210 on the wires (Activity from background paper)
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "SWire_Bi210"  , "^{210}Bi SWire"  , DataManagement::FindDataSet( "SWire_Bi210" )  , DataManagement::FindParameter( "SWire_Bi210"       ) , 1.  ));                                                 DataManagement::FindComponent("SWire_Bi210") -> SetFillColor( kGreen + 1 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-210 on the Scintillator surface
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScin ^{210}Bi    "  , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210" ) , 1. )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kGreen + 0 );		
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cInt" ), 0.440*1.82391e-04 , 0.440*2.45621e-05           , true, 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cInt" ), 0.440*1.82391e-04 , 0.440*2.45621e-05           , true, 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "cInt" ), 0.440*2.82801e-04 , 0.440*8.53952e-05           , true, 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "cInt" ), 0.887680542*3.01073e-03, 0.887680542*2.28492e-04, true, 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kOrange +  0 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber : Values from 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 6.62169e-01 , 9.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 6.53893e-01 , 8.6e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.22140e-02 , 3.01516e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.69628e-02 , 2.58033e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 8.53192e-02 , 2.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.00534e-01 , 2.2e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.14207e-03 , 3.52491e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.07416e-03 , 3.27150e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  4 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) , 7360.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) , 9.51298e+01 , 1.00484e+01 , true , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 1.35840e+01 , 2.88846e+00 , true , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 3.65096e+02 , 5.23372e+00 , true , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) , 1.02045e+03 , 3.69086e+01 , true , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) ,    7.90     , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) ,    7.90     , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) ,    7.90     , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1 = new Observable("e_energy_P1" , "E_{e} - Phase 1" , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1" ) ); e_energy_P1 -> SetLogScale(kFALSE);
	Observable * e_energy_P2 = new Observable("e_energy_P2" , "E_{e} - Phase 2" , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2" ) ); e_energy_P2 -> SetLogScale(kFALSE);	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1"	    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P1"         ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"      ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P1"   ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"          ) , hcoll->Find( "Cd116_K40_h_e_energy_P1"       ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"       ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1"    ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"        ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1"     ));

	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2"	    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P2"   	  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"      ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P2"   ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"          ) , hcoll->Find( "Cd116_K40_h_e_energy_P2"       ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"       ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2"    ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"        ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2"     ));
  
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( e_energy_P1 );
	DataManagement::AddObservable( e_energy_P2 );

	Fit::Run("Minuit", "Minimize");

	e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	
	e_energy_P1 -> SetLogScale(kTRUE); e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	e_energy_P2 -> SetLogScale(kTRUE); e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	
}