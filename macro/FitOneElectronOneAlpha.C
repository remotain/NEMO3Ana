{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronOneAlphaHistos", "OneElectronOneAlphaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronOneAlphaHistos.root");
	
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
	DataManagement::AddParameter( new Parameter( "Mylar_Bi214"        , "Mylar_Bi214"        , 0 , 0.0033 , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "Cd116_Bi214"        , "Cd116_Bi214"        , 1 , 0.0002 , 0.1 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P1
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P1_IN"  , "SFoil_Bi214_P1_IN"  , 2 , 25e-3  , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P1_OUT" , "SFoil_Bi214_P1_OUT" , 3 , 25e-3  , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P1_IN"  , "SWire_Bi214_P1_IN"  , 4 , 614e-3 , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P1_OUT" , "SWire_Bi214_P1_OUT" , 5 , 575e-3 , 0.1 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P2
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P2_IN"  , "SFoil_Bi214_P2_IN"  , 6 , 1.14205e-03 , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P2_OUT" , "SFoil_Bi214_P2_OUT" , 7 , 1.07414e-03 , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P2_IN"  , "SWire_Bi214_P2_IN"  , 8 , 81e-3       , 0.1 ) );
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P2_OUT" , "SWire_Bi214_P2_OUT" , 9 , 70e-3       , 0.1 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Groups
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddGroup( new Group( "Cd116_Bi214", "^{214}Bi Cd116"   )); DataManagement::FindGroup("Cd116_Bi214" ) -> SetFillColor( kOrange + 10 );	
	DataManagement::AddGroup( new Group( "Mylar_Bi214", "^{214}Bi Mylar"   )); DataManagement::FindGroup("Mylar_Bi214" ) -> SetFillColor( kGreen  +  1 );
	DataManagement::AddGroup( new Group( "SFoil_Bi214", "^{214}Bi SFoil"   )); DataManagement::FindGroup("SFoil_Bi214" ) -> SetFillColor( kViolet +  0 );
	DataManagement::AddGroup( new Group( "SWire_Bi214", "^{214}Bi SWire"   )); DataManagement::FindGroup("SWire_Bi214" ) -> SetFillColor( kAzure  +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P1
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_IN_IN"   , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_OUT_OUT" , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_IN_OUT"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1_OUT_IN"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  )->SetFillColor( kGreen  +  1 );
                           
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P1_IN_IN"  ));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P1_OUT_OUT"));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P1_IN_OUT" ));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P1_OUT_IN" ));
						                                                                                                                                                                                  
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_IN_IN"   , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_OUT_OUT" , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_IN_OUT"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1_OUT_IN"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  )->SetFillColor( kOrange + 10 );

	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P1_IN_IN"  ));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P1_OUT_OUT"));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P1_IN_OUT" ));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P1_OUT_IN" ));
                                                                                                                                                                                         
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN_IN"   , "^{214}Bi SFoil P1 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT_OUT" , "^{214}Bi SFoil P1 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN_OUT"  , "^{214}Bi SFoil P1 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT_IN"  , "^{214}Bi SFoil P1 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  )->SetFillColor( kViolet +  0 );

	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P1_IN_IN"  ));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P1_OUT_OUT"));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P1_IN_OUT" ));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P1_OUT_IN" ));
				
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN_IN"   , "^{214}Bi SWire P1 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT_OUT" , "^{214}Bi SWire P1 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN_OUT"  , "^{214}Bi SWire P1 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT_IN"  , "^{214}Bi SWire P1 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  )->SetFillColor( kAzure  +  1 );

	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P1_IN_IN"  ));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P1_OUT_OUT"));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P1_IN_OUT" ));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P1_OUT_IN" ));
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P2
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_IN_IN"   , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_OUT_OUT" , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_IN_OUT"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2_OUT_IN"  , "^{214}Bi Mylar        " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"        ) , 1.0*0.887680542 )); DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  )->SetFillColor( kGreen  +  1 );
       
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P2_IN_IN"  ));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P2_OUT_OUT"));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P2_IN_OUT" ));
	DataManagement::FindGroup("Mylar_Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214_P2_OUT_IN" ));
	   	                                                                                                                                                                                                      
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_IN_IN"   , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_OUT_OUT" , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_IN_OUT"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2_OUT_IN"  , "^{214}Bi Cd116        " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"        ) , 1.0*0.440 )); DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  )->SetFillColor( kOrange + 10 );
       
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P2_IN_IN"  ));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P2_OUT_OUT"));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P2_IN_OUT" ));
	DataManagement::FindGroup("Cd116_Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214_P2_OUT_IN" ));  
	                                                                                                                                                                                                      
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN_IN"   , "^{214}Bi SFoil P2 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT_OUT" , "^{214}Bi SFoil P2 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN_OUT"  , "^{214}Bi SFoil P2 OUT " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT_IN"  , "^{214}Bi SFoil P2 IN  " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  )->SetFillColor( kViolet +  0 );

	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P2_IN_IN"  ));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P2_OUT_OUT"));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P2_IN_OUT" ));
	DataManagement::FindGroup("SFoil_Bi214")->AddComponent(DataManagement::FindComponent("SFoil_Bi214_P2_OUT_IN" ));

	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN_IN"   , "^{214}Bi SWire P2 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT_OUT" , "^{214}Bi SWire P2 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN_OUT"  , "^{214}Bi SWire P2 OUT " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_OUT" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT_IN"  , "^{214}Bi SWire P2 IN  " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2_IN"  ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  )->SetFillColor( kAzure  +  1 );

	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P2_IN_IN"  ));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P2_OUT_OUT"));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P2_IN_OUT" ));
	DataManagement::FindGroup("SWire_Bi214")->AddComponent(DataManagement::FindComponent("SWire_Bi214_P2_OUT_IN" ));

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * alphaLength    = new Observable("alphaLength"      , "1e1a - alpha track length"  , kAll , hcoll->Find( "Data_h_alphaLength"    ) ); alphaLength     -> SetLogScale(kFALSE); alphaLength    -> AddGroupAll(DataManagement::GetGroupCollection()); alphaLength    -> SetDrawGroup(kTRUE);
	Observable * electronEnergy = new Observable("electronEnergy"   , "1e1a - electron energy"     , kAll , hcoll->Find( "Data_h_electronEnergy" ) ); electronEnergy  -> SetLogScale(kFALSE); electronEnergy -> AddGroupAll(DataManagement::GetGroupCollection()); electronEnergy -> SetDrawGroup(kTRUE);
	Observable * alphaTime      = new Observable("alphaTime"        , "1e1a -  alpha delayed time" , kAll , hcoll->Find( "Data_h_alphaTime"      ) ); alphaTime       -> SetLogScale(kTRUE);  alphaTime      -> AddGroupAll(DataManagement::GetGroupCollection()); alphaTime      -> SetDrawGroup(kTRUE);


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
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aIn"   ) );		
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aIn"   ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aOut" ) );		
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aOut" ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aOut"  ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aIn"  ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aIn"  ) );		
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aIn"   ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aOut"  ) );			
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aOut"  ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aIn"  ) );	
	alphaLength -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aIn"  ) );		
	alphaLength -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aIn"  ) );

	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aIn" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aOut" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aOut" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aIn" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aIn" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aOut" ) );	
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aIn" ) );

	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P1_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P1_eIn_aIn" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P1_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P1_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P1_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P1_eOut_aOut" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P1_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P1_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P1_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P1_eIn_aOut" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P1_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P1_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P1_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P1_eOut_aIn" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P1_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P1_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P2_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P2_eIn_aIn" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P2_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P2_eIn_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P2_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P2_eOut_aOut" ) );	
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P2_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P2_eOut_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P2_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P2_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P2_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P2_eIn_aOut" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P2_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P2_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P2_eOut_aIn" ) );
	alphaTime -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P2_eOut_aIn" ) );


	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aIn"   ) );		
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aIn"   ) );	
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aIn"   ) );
	alphaLength_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aIn"   ) );

	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aOut" ) );		
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aOut" ) );	
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aOut" ) );
	alphaLength_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aOut" ) );

	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aOut"  ) );	
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aOut"  ) );
	alphaLength_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aOut"  ) );

	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aIn"  ) );	
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aIn"  ) );		
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aIn"  ) );
	alphaLength_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aIn"  ) );

	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aIn"   ) );	
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aIn"   ) );
	alphaLength_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aIn"   ) );

	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aOut" ) );	
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aOut" ) );
	alphaLength_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aOut" ) );

	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aOut"  ) );			
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aOut"  ) );	
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aOut"  ) );
	alphaLength_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aOut"  ) );

	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aIn"  ) );	
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aIn"  ) );		
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aIn"  ) );
	alphaLength_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aIn"  ) );

	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aIn" ) );	
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aIn" ) );
	electronEnergy_P1_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aIn" ) );

	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_OUT" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aOut" ) );	
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aOut" ) );
	electronEnergy_P1_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_OUT" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aOut" ) );

	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_IN_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eIn_aOut" ) );	
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eIn_aOut" ) );
	electronEnergy_P1_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eIn_aOut" ) );

	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1_OUT_IN"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1_eOut_aIn" ) );	
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1_eOut_aIn" ) );
	electronEnergy_P1_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT_IN"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1_eOut_aIn" ) );

	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_IN"    ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_IN"    ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aIn" ) );	
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_IN"    ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aIn" ) );
	electronEnergy_P2_IN_IN   -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_IN"    ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aIn" ) );

	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aOut" ) );	
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aOut" ) );
	electronEnergy_P2_OUT_OUT -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_OUT"  ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aOut" ) );

	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_IN_OUT"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eIn_aOut" ) );
	electronEnergy_P2_IN_OUT  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN_OUT"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eIn_aOut" ) );

	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2_OUT_IN"   ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2_eOut_aIn" ) );
	electronEnergy_P2_OUT_IN  -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT_IN"   ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2_eOut_aIn" ) );


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

	Fit::DoDrawScan();
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
    
	Fit::DoDrawScan();
	Fit::Run("Minuit", "Minimize");
	
	alphaLength_P1_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf(");
	alphaLength_P1_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P1_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P1_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P2_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P2_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P2_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaLength_P2_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	
	electronEnergy_P1_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P1_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P1_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P1_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P2_IN_IN   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P2_OUT_OUT -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P2_IN_OUT  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy_P2_OUT_IN  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");

	alphaLength     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	alphaTime       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf");
	electronEnergy  -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha.pdf)");
	
	alphaLength -> DrawDetails();
	(TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronOneAlpha_Details.pdf");
	
	alphaLength->PrintDetails();

}
