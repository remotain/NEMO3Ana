{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("TwoElectronExtHistos", "TwoElectronExtHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141213/TwoElectronExtHistos.root");
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
	DataManagement::AddParameter( new Parameter( "PMT_K40"        , "PMT_K40"        ,  0 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SScin_K40"      , "SScin_K40"      ,  1 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"      , "PMT_Bi214"      ,  2 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "FeShield_Bi214" , "FeShield_Bi214" ,  3 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1"   , "Air_Bi214_P1"   ,  4 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"      , "PMT_Tl208"      ,  5 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "FeShield_Tl208" , "FeShield_Tl208" ,  6 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1"   , "Air_Tl208_P1"   ,  7 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "CuTower_Co60"   , "CuTower_Co60"   ,  8 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SScin_Pa234m"   , "SScin_Pa234m"   ,  9 , 0.0033 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"    , "SScin_Bi210"    , 10 , 0.0033 , 0.001 ) );
	//DataManagement::AddParameter( new Parameter( "Neutron"        , "Neutron"        , 11 , 0.0033 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components to fit
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT {40}^K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) , 1.0 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_K40"      , "SScint ^{40}K      " , DataManagement::FindDataSet( "SScin_K40"      ) , DataManagement::FindParameter( "SScin_K40"      ) , 1.0 )); DataManagement::FindComponent( "SScin_K40"      )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "FeShield_Bi214" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214_P1"   ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214_P1"   ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208_P1"   ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "CuTower_Co60"   ) , 1.0 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pa234m"   , "SScint ^{234m}Pa   " , DataManagement::FindDataSet( "SScin_Pa234m"   ) , DataManagement::FindParameter( "SScin_Pa234m"   ) , 1.0 )); DataManagement::FindComponent( "SScin_Pa234m"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kViolet +  0 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components fixed to 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Mylar_Bi214"    , "^{214}Bi Mylar    " , DataManagement::FindDataSet( "Mylar_Bi214" ) , 1.0 ));       DataManagement::FindComponent( "Mylar_Bi214"    )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214"    , "^{214}Bi Cd116    " , DataManagement::FindDataSet( "Cd116_Bi214" ) , 1.0/0.440 )); DataManagement::FindComponent( "Cd116_Bi214"    )->SetFillColor( kOrange + 10 );                                                                                                                                           
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1" , "^{214}Bi SFoil P1 " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.0 ));       DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1" , "^{214}Bi SWire P1 " , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.0 ));       DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2" , "^{214}Bi SFoil P2 " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.0 ));       DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2" , "^{214}Bi SWire P2 " , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.0 ));       DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kAzure  +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * alphaLength_P1_IN_IN   = new Observable("alphaLength_P1_IN_IN"   , "1e1a - alpha track length - Phase 1 e IN #alpha IN   " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eIn_aIn"   ) ); alphaLength_P1_IN_IN   -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_OUT_OUT = new Observable("alphaLength_P1_OUT_OUT" , "1e1a - alpha track length - Phase 1 e OUT #alpha OUT " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eOut_aOut" ) ); alphaLength_P1_OUT_OUT -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_IN_OUT  = new Observable("alphaLength_P1_IN_OUT"  , "1e1a - alpha track length - Phase 1 e IN #alpha OUT  " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eIn_aOut"  ) ); alphaLength_P1_IN_OUT  -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_OUT_IN  = new Observable("alphaLength_P1_OUT_IN"  , "1e1a - alpha track length - Phase 1 e OUT #alpha IN  " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eOut_aIn"  ) ); alphaLength_P1_OUT_IN  -> SetLogScale(kFALSE);

	Observable * electronEnergy_P1_IN_IN   = new Observable("electronEnergy_P1_IN_IN"   , "1e1a - electron energy - Phase 1 e IN #alpha IN   " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P1_eIn_aIn"   ) ); electronEnergy_P1_IN_IN   -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_OUT_OUT = new Observable("electronEnergy_P1_OUT_OUT" , "1e1a - electron energy - Phase 1 e OUT #alpha OUT " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P1_eOut_aOut" ) ); electronEnergy_P1_OUT_OUT -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_IN_OUT  = new Observable("electronEnergy_P1_IN_OUT"  , "1e1a - electron energy - Phase 1 e IN #alpha OUT  " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P1_eIn_aOut"  ) ); electronEnergy_P1_IN_OUT  -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_OUT_IN  = new Observable("electronEnergy_P1_OUT_IN"  , "1e1a - electron energy - Phase 1 e OUT #alpha IN  " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P1_eOut_aIn"  ) ); electronEnergy_P1_OUT_IN  -> SetLogScale(kFALSE);


	Observable * alphaLength_P2_IN_IN   = new Observable("alphaLength_P2_IN_IN"   , "1e1a - alpha track length - Phase 2 e IN #alpha IN   " , kPhaseTwo , hcoll->Find( "Data_h_alphaLength_P2_eIn_aIn"   ) ); alphaLength_P2_IN_IN   -> SetLogScale(kFALSE);
	Observable * alphaLength_P2_OUT_OUT = new Observable("alphaLength_P2_OUT_OUT" , "1e1a - alpha track length - Phase 2 e OUT #alpha OUT " , kPhaseTwo , hcoll->Find( "Data_h_alphaLength_P2_eOut_aOut" ) ); alphaLength_P2_OUT_OUT -> SetLogScale(kFALSE);
	Observable * alphaLength_P2_IN_OUT  = new Observable("alphaLength_P2_IN_OUT"  , "1e1a - alpha track length - Phase 2 e IN #alpha OUT  " , kPhaseTwo , hcoll->Find( "Data_h_alphaLength_P2_eIn_aOut"  ) ); alphaLength_P2_IN_OUT  -> SetLogScale(kFALSE);
	Observable * alphaLength_P2_OUT_IN  = new Observable("alphaLength_P2_OUT_IN"  , "1e1a - alpha track length - Phase 2 e OUT #alpha IN  " , kPhaseTwo , hcoll->Find( "Data_h_alphaLength_P2_eOut_aIn"  ) ); alphaLength_P2_OUT_IN  -> SetLogScale(kFALSE);

	Observable * electronEnergy_P2_IN_IN   = new Observable("electronEnergy_P2_IN_IN"   , "1e1a - electron energy - Phase 2 e IN #alpha IN   " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P2_eIn_aIn"   ) ); electronEnergy_P2_IN_IN   -> SetLogScale(kFALSE);
	Observable * electronEnergy_P2_OUT_OUT = new Observable("electronEnergy_P2_OUT_OUT" , "1e1a - electron energy - Phase 2 e OUT #alpha OUT " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P2_eOut_aOut" ) ); electronEnergy_P2_OUT_OUT -> SetLogScale(kFALSE);
	Observable * electronEnergy_P2_IN_OUT  = new Observable("electronEnergy_P2_IN_OUT"  , "1e1a - electron energy - Phase 2 e IN #alpha OUT  " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P2_eIn_aOut"  ) ); electronEnergy_P2_IN_OUT  -> SetLogScale(kFALSE);
	Observable * electronEnergy_P2_OUT_IN  = new Observable("electronEnergy_P2_OUT_IN"  , "1e1a - electron energy - Phase 2 e OUT #alpha IN  " , kPhaseTwo , hcoll->Find( "Data_h_electronEnergy_P2_eOut_aIn"  ) ); electronEnergy_P2_OUT_IN  -> SetLogScale(kFALSE);
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////	
	//alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1_IN_IN"   ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aIn"   ) );		
	//alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aOut" ) );		
	//alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	//alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aIn"  ) );	
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aIn"  ) );	
	//alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2_IN_IN"   ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	//alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	//alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aOut"  ) );			
	//alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aIn"  ) );	
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aIn"  ) );	

	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aIn" ) );

	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aIn" ) );



	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	//DataManagement::AddObservable( alphaLength_P1_IN_IN   );	
	//DataManagement::AddObservable( alphaLength_P1_OUT_OUT );	
	//DataManagement::AddObservable( alphaLength_P1_IN_OUT  );	
	//DataManagement::AddObservable( alphaLength_P1_OUT_IN  );	
	DataManagement::AddObservable( alphaLength_P2_IN_IN   );	
	DataManagement::AddObservable( alphaLength_P2_OUT_OUT );	
	DataManagement::AddObservable( alphaLength_P2_IN_OUT  );	
	DataManagement::AddObservable( alphaLength_P2_OUT_IN  );	

	DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  )->SetFix(); 
	DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" )->SetFix(); 
	DataManagement::FindParameter( "SWire_Bi214_P1_IN"  )->SetFix(); 
	DataManagement::FindParameter( "SWire_Bi214_P1_OUT" )->SetFix(); 

	Fit::Run("Minuit", "Minimize");
	
	DataManagement::FindParameter( "Mylar_Bi214" )->SetFix();
    DataManagement::FindParameter( "Cd116_Bi214" )->SetFix();
		
	DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  )->Release(); 
	DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" )->Release(); 
	DataManagement::FindParameter( "SWire_Bi214_P1_IN"  )->Release(); 
	DataManagement::FindParameter( "SWire_Bi214_P1_OUT" )->Release(); 	
		
	DataManagement::AddObservable( alphaLength_P1_IN_IN   );	
	DataManagement::AddObservable( alphaLength_P1_OUT_OUT );	
	DataManagement::AddObservable( alphaLength_P1_IN_OUT  );	
	DataManagement::AddObservable( alphaLength_P1_OUT_IN  );	
    
	Fit::Run("Minuit", "Minimize");

	alphaLength_P1_IN_IN   -> Draw();
	alphaLength_P1_OUT_OUT -> Draw();
	alphaLength_P1_IN_OUT  -> Draw();
	alphaLength_P1_OUT_IN  -> Draw();
	alphaLength_P2_IN_IN   -> Draw();
	alphaLength_P2_OUT_OUT -> Draw();
	alphaLength_P2_IN_OUT  -> Draw();
	alphaLength_P2_OUT_IN  -> Draw();

	electronEnergy_P1_IN_IN   -> Draw();
	electronEnergy_P1_OUT_OUT -> Draw();
	electronEnergy_P1_IN_OUT  -> Draw();
	electronEnergy_P1_OUT_IN  -> Draw();
	electronEnergy_P2_IN_IN   -> Draw();
	electronEnergy_P2_OUT_OUT -> Draw();
	electronEnergy_P2_IN_OUT  -> Draw();
	electronEnergy_P2_OUT_IN  -> Draw();

}
