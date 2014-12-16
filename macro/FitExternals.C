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

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141213/OneElectronOneGammaExt.root");
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
	DataManagement::AddParameter( new Parameter( "PMT_K40"        , "PMT_K40"        ,  0 , 1078.00 , 0.001 ) ); DataManagement::FindParameter( "PMT_K40"       )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "ScintInn_K40"   , "ScintInn_K40"   ,  1 ,    7.59 , 0.001 ) ); DataManagement::FindParameter( "ScintInn_K40"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "ScintOut_K40"   , "ScintOut_K40"   ,  2 ,   12.53 , 0.001 ) ); DataManagement::FindParameter( "ScintOut_K40"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "ScintPet_K40"   , "ScintPet_K40"   ,  3 ,    1.39 , 0.001 ) ); DataManagement::FindParameter( "ScintPet_K40"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"      , "PMT_Bi214"      ,  4 ,  324.00 , 0.001 ) ); DataManagement::FindParameter( "PMT_Bi214"     )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "FeShield_Bi214" , "FeShield_Bi214" ,  5 , 7360.00 , 0.001 ) ); DataManagement::FindParameter( "FeShield_Bi214")->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1"   , "Air_Bi214_P1"   ,  6 ,  500.00 , 0.001 ) ); DataManagement::FindParameter( "Air_Bi214_P1"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"      , "PMT_Tl208"      ,  7 ,   27.00 , 0.001 ) ); DataManagement::FindParameter( "PMT_Tl208"     )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "FeShield_Tl208" , "FeShield_Tl208" ,  8 ,  484.00 , 0.001 ) ); DataManagement::FindParameter( "FeShield_Tl208")->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1"   , "Air_Tl208_P1"   ,  9 ,    7.50 , 0.001 ) ); DataManagement::FindParameter( "Air_Tl208_P1"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "CuTower_Co60"   , "CuTower_Co60"   , 10 ,   18.40 , 0.001 ) ); DataManagement::FindParameter( "CuTower_Co60"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "SScin_Pa234m"   , "SScin_Pa234m"   , 11 ,    3.00 , 0.001 ) ); DataManagement::FindParameter( "SScin_Pa234m"  )->SetLimit(0,2000);
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"    , "SScin_Bi210"    , 12 ,   30.00 , 0.001 ) ); DataManagement::FindParameter( "SScin_Bi210"   )->SetLimit(0,2000);
	//DataManagement::AddParameter( new Parameter( "Neutron"        , "Neutron"        , 11 , 0.0033 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components to fit
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) , 1.0 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kGreen  +  0 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "ScintInn_K40"   ) , 1.0 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "ScintOut_K40"   ) , 1.0 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kGreen  +  2 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "ScintPet_K40"   ) , 1.0 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kGreen  +  3 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "FeShield_Bi214" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange +  2 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange +  3 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.0 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kViolet +  1 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet +  2 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.0 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet +  3 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) , 1.0 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kViolet +  4 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "CuTower_Co60"   ) , 1.0 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kAzure  +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pa234m"   , "SScint ^{234m}Pa   " , DataManagement::FindDataSet( "SScin_Pa234m"   ) , DataManagement::FindParameter( "SScin_Pa234m"   ) , 1.0 )); DataManagement::FindComponent( "SScin_Pa234m"   )->SetFillColor( kAzure  +  1 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) , 1.0 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kAzure  +  2 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components fixed by the 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Mylar_Bi214"    , "^{214}Bi Mylar    " , DataManagement::FindDataSet( "Mylar_Bi214" ) , 2.86 * 1e-3 , 0.25 * 1e-3 )); DataManagement::FindComponent( "Mylar_Bi214"    )->SetFillColor( kYellow  +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Bi214"    , "^{214}Bi Cd116    " , DataManagement::FindDataSet( "Cd116_Bi214" ) , 0.15 * 0.440 * 1e-3 , 0.03 * 0.440 * 1e-3 )); DataManagement::FindComponent( "Cd116_Bi214"    )->SetFillColor( kYellow + 1 );                                                                                                                                           
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1" , "^{214}Bi SFoil P1 " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.00 * 1e-3  , 1.00 * 1e-3 )); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kYellow +  2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1" , "^{214}Bi SWire P1 " , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.00 * 1e-3  , 1.00 * 1e-3 )); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kYellow +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2" , "^{214}Bi SFoil P2 " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.00 * 1e-3  , 1.00 * 1e-3 )); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetFillColor( kYellow +  2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2" , "^{214}Bi SWire P2 " , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.00 * 1e-3  , 1.00 * 1e-3 )); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetFillColor( kYellow +  3 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * tot_e_energy_P1   = new Observable("tot_e_energy_P1"   , "2e ext - total electron energy - Phase 1 " , kPhaseOne , hcoll_2eExt->Find( "Data_h_tot_e_energy_P1"   ) ); tot_e_energy_P1   -> SetLogScale(kFALSE);
	Observable * tot_e_energy_P2   = new Observable("tot_e_energy_P2"   , "2e ext - total electron energy - Phase 2 " , kPhaseTwo , hcoll_2eExt->Find( "Data_h_tot_e_energy_P2"   ) ); tot_e_energy_P2   -> SetLogScale(kFALSE);	

	Observable * tot_e_g_energy_P1   = new Observable("tot_e_g_energy_P1"   , "1e1g ext - total electron + gamma energy - Phase 1 " , kPhaseOne , hcoll_1e1gExt->Find( ""   ) ); tot_e_energy_P1   -> SetLogScale(kFALSE);
	Observable * tot_e_g_energy_P2   = new Observable("tot_e_g_energy_P2"   , "1e1g ext - total electron + gamma energy - Phase 2 " , kPhaseTwo , hcoll_1e1gExt->Find( ""   ) ); tot_e_energy_P2   -> SetLogScale(kFALSE);	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////	
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"        ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P1"       ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"   ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"   ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"   ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"      ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214" ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"   ) , hcoll_2eExt->Find( "Air_Bi214_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"   ) , hcoll_2eExt->Find( "Air_Pb214_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"      ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"      ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208" ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228" ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"   ) , hcoll_2eExt->Find( "Air_Tl208_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"   ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"   ) , hcoll_2eExt->Find( "SScin_Pa234m_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"    ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"    ) , hcoll_2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"    ) , hcoll_2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) , hcoll_2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P1") );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1") );

	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"        ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"   ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"   ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"   ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"      ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214" ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P2") ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"      ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"      ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208" ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P2") ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228" ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P2") ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"   ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"   ) , hcoll_2eExt->Find( "SScin_Pa234m_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"    ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P2"   ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"    ) , hcoll_2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P2"   ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"    ) , hcoll_2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P2"   ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2" ) , hcoll_2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P2") );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2") );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1 );	
	DataManagement::AddObservable( tot_e_energy_P2 );	

	Fit::Run("Minuit", "Minimize");
	
	tot_e_energy_P1 -> Draw();
	tot_e_energy_P2 -> Draw();

}
