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
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters in common
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "Mylar_Bi214" , "Mylar_Bi214" , 0 , 0.0020 , 0.001 ) ); DataManagement::FindParameter( "Mylar_Bi214" ) -> SetLimit(0., 1.);
	DataManagement::AddParameter( new Parameter( "Cd116_Bi214" , "Cd116_Bi214" , 1 , 0.0004 , 0.001 ) ); DataManagement::FindParameter( "Cd116_Bi214" ) -> SetLimit(0., 1.);
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P1
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P1" , "SFoil_Bi214_P1" , 2 , 0.080 , 0.001 ) ); DataManagement::FindParameter( "SFoil_Bi214_P1" ) -> SetLimit(0., 5.);
	DataManagement::AddParameter( new Parameter( "SScin_Bi214_P1" , "SScin_Bi214_P1" , 3 , 0.291 , 0.001 ) ); DataManagement::FindParameter( "SScin_Bi214_P1" )  -> SetFix(); //SetLimit(0.1, 10.);
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P1" , "SWire_Bi214_P1" , 4 , 0.198 , 0.001 ) ); DataManagement::FindParameter( "SWire_Bi214_P1" ) -> SetLimit(0., 1.);
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters P2
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddParameter( new Parameter( "SFoil_Bi214_P2" , "SFoil_Bi214_P2" , 5 , 0.020 , 0.001 ) ); DataManagement::FindParameter( "SFoil_Bi214_P2" ) -> SetLimit(0., 5.);
	DataManagement::AddParameter( new Parameter( "SScin_Bi214_P2" , "SScin_Bi214_P2" , 6 , 0.291 , 0.001 ) ); DataManagement::FindParameter( "SScin_Bi214_P2" ) -> SetFix(); //SetLimit(0.1, 10.);
	DataManagement::AddParameter( new Parameter( "SWire_Bi214_P2" , "SWire_Bi214_P2" , 7 , 0.198 , 0.001 ) ); DataManagement::FindParameter( "SWire_Bi214_P2" ) -> SetLimit(0., 5.);
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P1
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P1" , "^{214}B1 Mylar P1   " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"    ) , 1.0 )); DataManagement::FindComponent( "Mylar_Bi214_P1" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1" , "^{214}B1 SFoil P1   " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214_P1" , "^{214}B1 SScin P1   " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P1" )->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1" , "^{214}B1 SWire P1   " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P1" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P1" , "^{214}B1 Int P1     " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"    ) , 1.0 )); DataManagement::FindComponent( "Cd116_Bi214_P1" )->SetFillColor( kOrange + 10 );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define components P2
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214_P2" , "^{214}B1 Mylar P2   " , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "Mylar_Bi214"    ) , 1.0 )); DataManagement::FindComponent( "Mylar_Bi214_P2" )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2" , "^{214}B1 SFoil P2   " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "SFoil_Bi214_P2" ) , 1.0 )); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214_P2" , "^{214}B1 SScin P2   " , DataManagement::FindDataSet( "SScin_Bi214" ) , DataManagement::FindParameter( "SScin_Bi214_P2" ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi214_P2" )->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2" , "^{214}B1 SWire P2   " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "SWire_Bi214_P2" ) , 1.0 )); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214_P2" , "^{214}B1 Int P2     " , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "Cd116_Bi214"    ) , 1.0 )); DataManagement::FindComponent( "Cd116_Bi214_P2" )->SetFillColor( kOrange + 10 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * alphaLength_P1    = new Observable("alphaLength_P1"    , "1e1a - alpha track length - Phase 1" , kPhaseOne , hcoll->Find("Data_h_alphaLength_P1"    ) );
	Observable * alphaLength_P2    = new Observable("alphaLength_P2"    , "1e1a - alpha track length - Phase 2" , kPhaseTwo , hcoll->Find("Data_h_alphaLength_P2"    ) );

	Observable * electronEnergy_P1 = new Observable("electronEnergy_P1" , "1e1a - electron energy - Phase 1"    , kPhaseOne , hcoll->Find("Data_h_electronEnergy_P1" ) );
	Observable * electronEnergy_P2 = new Observable("electronEnergy_P2" , "1e1a - electron energy - Phase 2"    , kPhaseTwo , hcoll->Find("Data_h_electronEnergy_P2" ) );

	Observable * alphaTime_P1    = new Observable("alphaTime_P1"    , "1e1a - alpha delayed time - Phase 1" , kPhaseOne , hcoll->Find("Data_h_alphaTime_P1"    ) );
	Observable * alphaTime_P2    = new Observable("alphaTime_P2"    , "1e1a - alpha delayed time - Phase 2" , kPhaseTwo , hcoll->Find("Data_h_alphaTime_P2"    ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////	
	alphaLength_P1->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1" ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P1" ) );
	alphaLength_P1->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P1" ) );
	alphaLength_P1->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P1" ) );
	alphaLength_P1->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P1" ) );
	alphaLength_P1->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P1" ) );

	alphaLength_P2->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2" ) , hcoll->Find( "SScin_Bi214_h_alphaLength_P2" ) );	
	alphaLength_P2->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2" ) , hcoll->Find( "Cd116_Bi214_h_alphaLength_P2" ) );
	alphaLength_P2->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2" ) , hcoll->Find( "Mylar_Bi214_h_alphaLength_P2" ) );
	alphaLength_P2->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2" ) , hcoll->Find( "SFoil_Bi214_h_alphaLength_P2" ) );
	alphaLength_P2->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) , hcoll->Find( "SWire_Bi214_h_alphaLength_P2" ) );

	electronEnergy_P1->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1" ) , hcoll->Find( "SScin_Bi214_h_electronEnergy_P1" ) );
    electronEnergy_P1->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P1" ) );	
	electronEnergy_P1->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P1" ) );
	electronEnergy_P1->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P1" ) );
	electronEnergy_P1->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P1" ) );
		
	electronEnergy_P2->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2" ) , hcoll->Find( "SScin_Bi214_h_electronEnergy_P2" ) );
	electronEnergy_P2->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2" ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy_P2" ) );
	electronEnergy_P2->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2" ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy_P2" ) );
	electronEnergy_P2->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2" ) , hcoll->Find( "SFoil_Bi214_h_electronEnergy_P2" ) );
	electronEnergy_P2->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) , hcoll->Find( "SWire_Bi214_h_electronEnergy_P2" ) );

	alphaTime_P1->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1" ) , hcoll->Find( "SScin_Bi214_h_alphaTime_P1" ) );
    alphaTime_P1->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P1" ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P1" ) );
	alphaTime_P1->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P1" ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P1" ) );
	alphaTime_P1->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P1" ) );
	alphaTime_P1->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1" ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P1" ) );
		
	alphaTime_P2->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2" ) , hcoll->Find( "SScin_Bi214_h_alphaTime_P2" ) );
	alphaTime_P2->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_P2" ) , hcoll->Find( "Cd116_Bi214_h_alphaTime_P2" ) );
	alphaTime_P2->AddComponent( DataManagement::FindComponent( "Mylar_Bi214_P2" ) , hcoll->Find( "Mylar_Bi214_h_alphaTime_P2" ) );
	alphaTime_P2->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2" ) , hcoll->Find( "SFoil_Bi214_h_alphaTime_P2" ) );
	alphaTime_P2->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) , hcoll->Find( "SWire_Bi214_h_alphaTime_P2" ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	//DataManagement::AddObservable( alphaLength_P1 );	
	DataManagement::AddObservable( alphaLength_P2 );
	
	DataManagement::FindParameter( "SFoil_Bi214_P1" ) -> SetFix();
	DataManagement::FindParameter( "SWire_Bi214_P1" ) -> SetFix();

	Fit::Run("Minuit", "Minimize");
	
	DataManagement::AddObservable( alphaLength_P1 );	

	DataManagement::FindParameter( "Mylar_Bi214" ) -> SetFix();
	DataManagement::FindParameter( "Cd116_Bi214" ) -> SetFix();
	
	DataManagement::FindParameter( "SFoil_Bi214_P1" ) -> SetLimit(0., 5.); 
	DataManagement::FindParameter( "SWire_Bi214_P1" ) -> SetLimit(0., 1.);
	
	
	Fit::Run("Minuit", "Minimize");

	alphaLength_P1    -> Draw();
	alphaLength_P2    -> Draw();
	electronEnergy_P1 -> Draw();
	electronEnergy_P2 -> Draw();
	alphaTime_P1      -> Draw();
	alphaTime_P2      -> Draw();


}
