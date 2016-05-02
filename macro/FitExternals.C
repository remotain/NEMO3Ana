{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSampleBkg.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_2eExt = new HistoCollection("TwoElectronExtHistos", "TwoElectronExtHistos");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/TwoElectronExtHistos.root");
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronExtHistos.root");

	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_2eExt->Load(fdir);
	}

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_1e1gExt = new HistoCollection("OneElectronOneGammaExt", "OneElectronOneGammaExt");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/OneElectronOneGammaExt.root");
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronOneGammaExt.root");
	
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
	DataManagement::AddParameter( new Parameter( "PMT_K40"         , "PMT_K40"             ,  0 , 1.30000e+03 , 0.001 ) ); //DataManagement::FindParameter( "PMT_K40"       ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Scint_K40"       , "Scint_K40"           ,  1 , 6.19355e+00 , 0.001 ) ); //DataManagement::FindParameter( "Scint_K40"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"       , "PMT_Bi214"           ,  2 , 2.68820e+02 , 0.001 ) ); //DataManagement::FindParameter( "PMT_Bi214"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1"    , "Air_Bi214_P1"        ,  3 , 5.99548e+02 , 0.001 ) ); //DataManagement::FindParameter( "Air_Bi214_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"       , "PMT_Tl208"           ,  4 , 4.53709e+01 , 0.001 ) ); //DataManagement::FindParameter( "PMT_Tl208"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1"    , "Air_Tl208_P1"        ,  5 , 1.39872e+01 , 0.001 ) ); //DataManagement::FindParameter( "Air_Tl208_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"     , "SScin_Bi210"         ,  6 , 3.49389e+01 , 0.001 ) ); //DataManagement::FindParameter( "SScin_Bi210"   ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi214"     , "SScin_Bi214"         ,  7 , 2.51318e-01 , 0.001 ) ); //DataManagement::FindParameter( "SScin_Bi214"   ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Co60"            , "Co60"                ,  8 , 6.18692e+01 , 0.001 ) ); //DataManagement::FindParameter( "Co60"          ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "FeShield_Bi214"  , "FeShield_Bi214"      ,  9 , 1.03004e+04 , 0.001 ) ); //DataManagement::FindParameter( "FeShield_Bi214") -> SetFix();
	DataManagement::AddParameter( new Parameter( "MuMetal_Pa234m"    , "MuMetal_Pa234m"    , 10 , 2.65319e+03 , 0.001 ) ); //DataManagement::FindParameter( "MuMetal_Pa234m") -> SetFix();
	DataManagement::AddParameter( new Parameter( "FeShield_Tl208"  , "FeShield_Tl208"      , 11 , 484 , 0.001 )); //DataManagement::FindParameter( "FeShield_Tl208") -> SetFix();

	// Push to negative values
	//DataManagement::AddParameter( new Parameter( "SScin_Pa234m"    , "SScin_Pa234m"        , 11 , 0.0 , 0.001 ));
	//DataManagement::AddParameter( new Parameter( "SteelFrame_Pa234m" , "SteelFrame_Pa234m" , 13 , 0.0 , 0.001 ));
	
	///////////////////////Q///////////////////////////////////////////////////////
	//	
	// Bi-214
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Cd116_Bi214"     , "^{214}Bi Cd116"      , DataManagement::FindDataSet( "Cd116_Bi214"    ) , 0.440*0.0004 , 0.440*0.0001 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kAzure + 11 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214"     , "^{214}Pb Cd116"      , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , 0.440*0.0004 , 0.440*0.0001 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kAzure + 12 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214"     , "^{214}Bi Mylar"      , DataManagement::FindDataSet( "Mylar_Bi214"    ) , 0.888*0.0028 , 0.888*0.0002 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kAzure + 13 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214"     , "^{214}Pb Mylar"      , DataManagement::FindDataSet( "Mylar_Pb214"    ) , 0.888*0.0028 , 0.888*0.0002 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kAzure + 14 );

	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1  " , DataManagement::FindDataSet( "SFoil_Bi214"    ) , 0.015  , 0.001                                           )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1  " , DataManagement::FindDataSet( "SFoil_Pb214"    ) , 0.015  , 0.001                                           )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2  " , DataManagement::FindDataSet( "SFoil_Bi214"    ) , 0.0013 , 0.0003                                          )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2  " , DataManagement::FindDataSet( "SFoil_Pb214"    ) , 0.0013 , 0.0003                                          )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1  " , DataManagement::FindDataSet( "SWire_Bi214"    ) , 0.67   , 0.03                                            )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1  " , DataManagement::FindDataSet( "SWire_Pb214"    ) , 0.67   , 0.03                                            )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2  " , DataManagement::FindDataSet( "SWire_Bi214"    ) , 0.091  , 0.005                                           )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2  " , DataManagement::FindDataSet( "SWire_Pb214"    ) , 0.091  , 0.005                                           )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "FeShield_Bi214"  , "FeShield ^{214}Bi  " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "FeShield_Bi214" ) , 1.00 )); DataManagement::FindComponent( "FeShield_Bi214"  )->SetFillColor( kAzure +  5 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"       , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) , 1.00 )); DataManagement::FindComponent( "PMT_Bi214"       )->SetFillColor( kAzure +  6 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"     , "SScint ^{214}Bi    " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "SScin_Bi214"    ) , 1.00 )); DataManagement::FindComponent( "SScin_Bi214"     )->SetFillColor( kAzure +  7 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"     , "SScint ^{214}Pb    " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "SScin_Bi214"    ) , 1.00 )); DataManagement::FindComponent( "SScin_Pb214"     )->SetFillColor( kAzure +  8 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"    , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.00 )); DataManagement::FindComponent( "Air_Bi214_P1"    )->SetFillColor( kAzure +  9 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"    , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.00 )); DataManagement::FindComponent( "Air_Pb214_P1"    )->SetFillColor( kAzure + 10 );


	//////////////////////////////////////////////////////////////////////////////
	//	
	// Tl-208
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.00        )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.00/0.3594 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.00        )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.00/0.3594 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kGreen +  3 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) , 1.00        )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kGreen +  4 );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// K-40
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) ,  1.00        )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange  +  10 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00        )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange  +  8 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00        )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange  -  3 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00        )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange  +  0 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Others
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi   " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) ,  1.00        )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "Co60"           , "^{60}Co           " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "Co60"           ) ,  1.00        )); DataManagement::FindComponent( "Co60"           )->SetFillColor( kViolet +  1 );	
	DataManagement::AddComponent( new Component( "MuMetal_Pa234m" , "Mu Metal ^{234m}Pa" , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , DataManagement::FindParameter( "MuMetal_Pa234m" ) ,  1.00        )); DataManagement::FindComponent( "MuMetal_Pa234m" )->SetFillColor( kViolet +  2 );	

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
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll_2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll_2eExt->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_2eExt->Find( "Mylar_Pb214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll_2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll_2eExt->Find( "SFoil_Pb214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll_2eExt->Find( "SScin_Bi214_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll_2eExt->Find( "SScin_Pb214_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_2eExt->Find( "Air_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Co60"               ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll_2eExt->Find( "MuMetal_Pa234m_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_2eExt->Find( "Air_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_2eExt->Find( "Air_Pb214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P1"       ) ); 

	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll_2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll_2eExt->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_2eExt->Find( "Mylar_Pb214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll_2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll_2eExt->Find( "SFoil_Pb214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll_2eExt->Find( "SScin_Bi214_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll_2eExt->Find( "SScin_Pb214_h_tot_e_energy_P2"     ) ); 	
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Co60"               ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll_2eExt->Find( "MuMetal_Pa234m_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P2"         ) ); 

	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"     ) , hcoll_1e1gExt->Find( "Cd116_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"     ) , hcoll_1e1gExt->Find( "Cd116_Pb214_VT_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"     ) , hcoll_1e1gExt->Find( "Mylar_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"     ) , hcoll_1e1gExt->Find( "Mylar_Pb214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll_1e1gExt->Find( "SFoil_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll_1e1gExt->Find( "SFoil_Pb214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll_1e1gExt->Find( "SScin_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll_1e1gExt->Find( "SScin_Pb214_h_tot_energy_P1"   ) );		
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_1e1gExt->Find( "Air_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Co60"               ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll_1e1gExt->Find( "MuMetal_Pa234m_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_1e1gExt->Find( "Air_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_1e1gExt->Find( "Air_Pb214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P1"       ) ); 

	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"     ) , hcoll_1e1gExt->Find( "Cd116_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"     ) , hcoll_1e1gExt->Find( "Cd116_Pb214_VT_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"     ) , hcoll_1e1gExt->Find( "Mylar_Bi214_h_tot_energy_P2"   ) );	
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"     ) , hcoll_1e1gExt->Find( "Mylar_Pb214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll_1e1gExt->Find( "SFoil_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll_1e1gExt->Find( "SFoil_Pb214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll_1e1gExt->Find( "SScin_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll_1e1gExt->Find( "SScin_Pb214_h_tot_energy_P2"   ) );		
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Co60"               ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P2"             ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P2"        ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll_1e1gExt->Find( "MuMetal_Pa234m_h_tot_energy_P2"    ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P2"       ) ); 

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1 );	
	DataManagement::AddObservable( tot_e_energy_P2 );	
	DataManagement::AddObservable( tot_e_g_energy_P1 );	
	DataManagement::AddObservable( tot_e_g_energy_P2 );	

	Fit::DoDrawScan();
	Fit::Run("Minuit", "Minimize");
	
	tot_e_energy_P1   -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf(");
	tot_e_energy_P1   -> SetLogScale(kTRUE); tot_e_energy_P1   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");
	tot_e_energy_P2   -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");	
	tot_e_energy_P2   -> SetLogScale(kTRUE); tot_e_energy_P2   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");
	tot_e_g_energy_P1 -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");
	tot_e_g_energy_P1 -> SetLogScale(kTRUE); tot_e_g_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");
	tot_e_g_energy_P2 -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf");
	tot_e_g_energy_P2 -> SetLogScale(kTRUE); tot_e_g_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals.pdf)");
	
	//tot_e_energy_P2   -> DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals_Details.pdf(");
	//tot_e_g_energy_P2 -> DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitExternals_Details.pdf)");
	                            
}                               
                                