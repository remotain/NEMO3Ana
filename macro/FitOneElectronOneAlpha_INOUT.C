{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronOneAlphaHistos", "OneElectronOneAlphaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141218/OneElectronOneAlphaHistos_2hits.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters in common
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "Mylar_Bi214"        , "Mylar_Bi214"        , 0 , 0.0017 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "Cd116_Bi214"        , "Cd116_Bi214"        , 1 , 0.0015 , 0.001 ) );
	//DataManagement::AddParameter( new Parameter( "SScin_Bi214"        , "SScin_Bi214"        , 2 , 0.2910 , 0.001 ) ); DataManagement::FindParameter( "SScin_Bi214"       ) -> SetFix(); // SetLimit(0., 1..);
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P1
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P1_IN"  , "SFoil_Bi214_P1_IN"  , 2 , 0.024 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P1_OUT" , "SFoil_Bi214_P1_OUT" , 3 , 0.024 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P1_IN"  , "SWire_Bi214_P1_IN"  , 4 , 0.614 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P1_OUT" , "SWire_Bi214_P1_OUT" , 5 , 0.575 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P2
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P2_IN"  , "SFoil_Bi214_P2_IN"  ,  6 , 0.0009 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P2_OUT" , "SFoil_Bi214_P2_OUT" ,  7 , 0.0020 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P2_IN"  , "SWire_Bi214_P2_IN"  ,  8 , 0.0800 , 0.001 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P2_OUT" , "SWire_Bi214_P2_OUT" ,  9 , 0.0700 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P1
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_IN_IN"   , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_OUT_OUT" , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_IN_OUT"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_OUT_IN"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  )->SetFillColor( kGreen  +  1 );
                                                                                                                                                                                                          
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_IN_IN"   , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_OUT_OUT" , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_IN_OUT"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_OUT_IN"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  )->SetFillColor( kOrange + 10 );
                                                                                                                                                                                                          
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P1_IN_IN"   , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P1_IN_IN"   )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P1_OUT_OUT" , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P1_OUT_OUT" )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P1_IN_OUT"  , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P1_IN_OUT"  )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P1_OUT_IN"  , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P1_OUT_IN"  )->SetFillColor( kOrange +  1 );

	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN_IN"   , "^{214}Bi SFoil P1 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT_OUT" , "^{214}Bi SFoil P1 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN_OUT"  , "^{214}Bi SFoil P1 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT_IN"  , "^{214}Bi SFoil P1 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  )->SetFillColor( kViolet +  0 );
				
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN_IN"   , "^{214}Bi SWire P1 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT_OUT" , "^{214}Bi SWire P1 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN_OUT"  , "^{214}Bi SWire P1 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT_IN"  , "^{214}Bi SWire P1 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  )->SetFillColor( kAzure  +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P2
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_IN_IN"   , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_OUT_OUT" , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_IN_OUT"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_OUT_IN"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  )->SetFillColor( kGreen  +  1 );
                                                                                                                                                                                                          
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_IN_IN"   , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_OUT_OUT" , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_IN_OUT"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_OUT_IN"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  )->SetFillColor( kOrange + 10 );
                                                                                                                                                                                                          
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P2_IN_IN"   , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P2_IN_IN"   )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P2_OUT_OUT" , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P2_OUT_OUT" )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P2_IN_OUT"  , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P2_IN_OUT"  )->SetFillColor( kOrange +  1 );
	//DataManagement::AddComponent( new Component( "SScin_Bi214_P2_OUT_IN"  , "^{214}Bi SScin        " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214"        ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P2_OUT_IN"  )->SetFillColor( kOrange +  1 );

	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN_IN"   , "^{214}Bi SFoil P2 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT_OUT" , "^{214}Bi SFoil P2 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN_OUT"  , "^{214}Bi SFoil P2 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT_IN"  , "^{214}Bi SFoil P2 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  )->SetFillColor( kViolet +  0 );

	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN_IN"   , "^{214}Bi SWire P2 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT_OUT" , "^{214}Bi SWire P2 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN_OUT"  , "^{214}Bi SWire P2 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT_IN"  , "^{214}Bi SWire P2 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  )->SetFillColor( kAzure  +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * alphaLength_P1_IN_IN   = new Observable("alphaLength_P1_IN_IN"   , "1e1a - alpha track length - Phase 1 e IN #alpha IN   " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eIn_aIn"   ) ); alphaLength_P1_IN_IN   -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_OUT_OUT = new Observable("alphaLength_P1_OUT_OUT" , "1e1a - alpha track length - Phase 1 e OUT #alpha OUT " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eOut_aOut" ) ); alphaLength_P1_OUT_OUT -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_IN_OUT  = new Observable("alphaLength_P1_IN_OUT"  , "1e1a - alpha track length - Phase 1 e IN #alpha OUT  " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eIn_aOut"  ) ); alphaLength_P1_IN_OUT  -> SetLogScale(kFALSE);
	Observable * alphaLength_P1_OUT_IN  = new Observable("alphaLength_P1_OUT_IN"  , "1e1a - alpha track length - Phase 1 e OUT #alpha IN  " , kPhaseOne , hcoll->Find( "Data_h_alphaLength_P1_eOut_aIn"  ) ); alphaLength_P1_OUT_IN  -> SetLogScale(kFALSE);

	Observable * electronEnergy_P1_IN_IN   = new Observable("electronEnergy_P1_IN_IN"   , "1e1a - electron energy - Phase 1 e IN #alpha IN   " , kPhaseOne , hcoll->Find( "Data_h_electronEnergy_P1_eIn_aIn"   ) ); electronEnergy_P1_IN_IN   -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_OUT_OUT = new Observable("electronEnergy_P1_OUT_OUT" , "1e1a - electron energy - Phase 1 e OUT #alpha OUT " , kPhaseOne , hcoll->Find( "Data_h_electronEnergy_P1_eOut_aOut" ) ); electronEnergy_P1_OUT_OUT -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_IN_OUT  = new Observable("electronEnergy_P1_IN_OUT"  , "1e1a - electron energy - Phase 1 e IN #alpha OUT  " , kPhaseOne , hcoll->Find( "Data_h_electronEnergy_P1_eIn_aOut"  ) ); electronEnergy_P1_IN_OUT  -> SetLogScale(kFALSE);
	Observable * electronEnergy_P1_OUT_IN  = new Observable("electronEnergy_P1_OUT_IN"  , "1e1a - electron energy - Phase 1 e OUT #alpha IN  " , kPhaseOne , hcoll->Find( "Data_h_electronEnergy_P1_eOut_aIn"  ) ); electronEnergy_P1_OUT_IN  -> SetLogScale(kFALSE);

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
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aIn"   ) );		
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aIn"   ) );	
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aIn"   ) );

	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aOut" ) );		
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aOut" ) );	
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aOut" ) );

	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aOut"  ) );	
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aOut"  ) );

	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aIn"  ) );	
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aIn"  ) );		
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aIn"  ) );

	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aIn"   ) );	
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aIn"   ) );

	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aOut" ) );

	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aOut"  ) );			
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aOut"  ) );	
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aOut"  ) );

	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aIn"  ) );	
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aIn"  ) );		
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aIn"  ) );

	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aIn" ) );	
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aIn" ) );

	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aOut" ) );	
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aOut" ) );

	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aOut" ) );	
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aOut" ) );

	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aIn" ) );	
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aIn" ) );

	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aIn" ) );	
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aIn" ) );

	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aOut" ) );	
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aOut" ) );

	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aOut" ) );

	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aIn" ) );


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

	// Draw all!
	TIter next(DataManagement::GetObservableCollection());
	Observable * o;
	while( (o = (Observable *) next()) ) {		
		o->Draw();
		(TPad*)gROOT->GetSelectedPad()->Print(0,".eps");		
	}

	electronEnergy_P1_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P1_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P1_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P1_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P2_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P2_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P2_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	electronEnergy_P2_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");

}
