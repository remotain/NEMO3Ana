{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_2eExt = new HistoCollection("TwoElectronExtHistos", "TwoElectronExtHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141213/TwoElectronExtHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_2eExt->Load(fdir);
	}

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_1e1gExt = new HistoCollection("OneElectronOneGammaExt", "OneElectronOneGammaExt");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141218/OneElectronOneGammaExt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_1e1gExt->Load(fdir);
	}


	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "PMT_K40"        , "PMT_K40"        ,  0 , 1125.42 , 0.001 ) ); DataManagement::FindParameter( "PMT_K40"       );
	DataManagement::AddParameter( new Parameter( "Scint_K40"      , "Scint_K40"      ,  1 ,   14.55 , 0.001 ) ); DataManagement::FindParameter( "Scint_K40"     );
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"      , "PMT_Bi214"      ,  2 ,  376.38 , 0.001 ) ); DataManagement::FindParameter( "PMT_Bi214"     );
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1"   , "Air_Bi214_P1"   ,  3 ,  624.95 , 0.001 ) ); DataManagement::FindParameter( "Air_Bi214_P1"  );
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"      , "PMT_Tl208"      ,  4 ,   37.46 , 0.001 ) ); DataManagement::FindParameter( "PMT_Tl208"     );
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1"   , "Air_Tl208_P1"   ,  5 ,   12.37 , 0.001 ) ); DataManagement::FindParameter( "Air_Tl208_P1"  ); 
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"    , "SScin_Bi210"    ,  6 ,   21.29 , 0.001 ) ); DataManagement::FindParameter( "SScin_Bi210"   ); 
	DataManagement::AddParameter( new Parameter( "CuTower_Co60"   , "CuTower_Co60"   ,  7 ,   63.97 , 0.001 ) ); DataManagement::FindParameter( "CuTower_Co60"  ); 
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components fixed by the 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 6.60911e-01 , 4.98429e-02 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"          )->SetFillColor( kCyan +  0 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 6.70849e-01 , 4.94088e-02 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT"         )->SetFillColor( kCyan +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 8.67658e-02 , 5.90468e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"          )->SetFillColor( kCyan +  0 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.05511e-01 , 6.02982e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT"         )->SetFillColor( kCyan +  1 );

	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , 7360.00 , 200.00 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kGreen  +  2 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kAzure +  5 );
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components to fit
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) ,  1.00 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange  +  10 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange  +  8 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange  -  3 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange  +  0 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kGreen  +  0 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kGreen  +  0 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "CuTower_Co60"   ) ,  1.00 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kViolet +  1 );
	//DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "FeShield_Bi214" ) ,  1.00 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kAzure  +  6 );
	//DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "FeShield_Tl208" ) ,  1.00 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet +  2 );
	//DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "FeShield_Tl208" ) ,  1.00 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet +  3 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * tot_e_energy_P1   = new Observable("tot_e_energy_P1"   , "2e ext - total electron energy - Phase 1 "           , kPhaseOne , hcoll_2eExt   -> Find( "Data_h_tot_e_energy_P1" ) ); tot_e_energy_P1   -> SetLogScale(kFALSE);
	Observable * tot_e_energy_P2   = new Observable("tot_e_energy_P2"   , "2e ext - total electron energy - Phase 2 "           , kPhaseTwo , hcoll_2eExt   -> Find( "Data_h_tot_e_energy_P2" ) ); tot_e_energy_P2   -> SetLogScale(kFALSE);	
	Observable * tot_e_g_energy_P1 = new Observable("tot_e_g_energy_P1" , "1e1g ext - total electron + gamma energy - Phase 1 " , kPhaseOne , hcoll_1e1gExt -> Find( "Data_h_tot_energy_P1"   ) ); tot_e_g_energy_P1 -> SetLogScale(kFALSE);
	Observable * tot_e_g_energy_P2 = new Observable("tot_e_g_energy_P2" , "1e1g ext - total electron + gamma energy - Phase 2 " , kPhaseTwo , hcoll_1e1gExt -> Find( "Data_h_tot_energy_P2"   ) ); tot_e_g_energy_P2 -> SetLogScale(kFALSE);	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////	
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );	
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_2eExt->Find( "Air_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P1"       ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_2eExt->Find( "Air_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_2eExt->Find( "Air_Pb214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P1") ); 

	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );	
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P2"         ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P2"  ) ); 

	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );	
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_1e1gExt->Find( "Air_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P1"       ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P1"   ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_1e1gExt->Find( "Air_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_1e1gExt->Find( "Air_Pb214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P1") ); 

	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );	
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P2"       ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P2"   ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P2") ); 

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1 );	
	DataManagement::AddObservable( tot_e_energy_P2 );	
	DataManagement::AddObservable( tot_e_g_energy_P1 );	
	DataManagement::AddObservable( tot_e_g_energy_P2 );	

	Fit::Run("Minuit", "Minimize");
	
	tot_e_energy_P1   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_g_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_energy_P2   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_g_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
                                
                                
}                               
                                