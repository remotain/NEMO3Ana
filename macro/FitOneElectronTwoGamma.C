{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronTwoGammaHistos", "OneElectronTwoGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronTwoGammaInt_Eg150keV.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	// Load OneElectronThreeGammaHistos in HistoCollection
	HistoCollection * hcoll_3g= new HistoCollection("OneElectronThreeGammaHistos", "OneElectronThreeGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronThreeGammaInt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_3g->Load(fdir);
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "Cd116_Tl208" , "Cd116_Tl208" , 0 , 1.86197e-04 , 0.001 ) ); //DataManagement::FindParameter( "Cd116_Tl208"  ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwireP1"    , "cSwireP1"    , 1 , 5.39626e-01 , 0.001 ) ); //DataManagement::FindParameter( "cSwireP1"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoilP1"    , "cSfoilP1"    , 2 , 9.99772e-01 , 0.001 ) ); //DataManagement::FindParameter( "cSfoilP1"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwireP2"    , "cSwireP2"    , 3 , 3.99872e-01 , 0.001 ) ); //DataManagement::FindParameter( "cSwireP2"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoilP2"    , "cSfoilP2"    , 4 , 9.99996e-01 , 0.001 ) ); //DataManagement::FindParameter( "cSfoilP2"     ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cInt"        , "cInt"        , 5 , 1.00000e+00 , 0.001 ) ); //DataManagement::FindParameter( "cInt"         ) -> SetFix();             
	DataManagement::AddParameter( new Parameter( "cExt"        , "cExt"        , 6 , 1.00000e+00 , 0.001 ) ); //DataManagement::FindParameter( "cExt"         ) -> SetFix();                           
	//////////////////////////////////////////////////////////////////////////////               
	//	
	// Tl 
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pb211"  , "^{211}Pb Cd116", DataManagement::FindDataSet( "Cd116_Pb211" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Pb211")->SetFillColor( kOrange + 3 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi 
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cInt" ) , 0.440*0.30*1e-3 , 0.440*0.08*1e-3 , true , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_pb214_VT" ) , DataManagement::FindParameter( "cInt" ) , 0.440*0.30*1e-3 , 0.440*0.08*1e-3 , true , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.01*1e-3 , 0.888*2.28*1e-4 , true , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.01*1e-3 , 0.888*2.28*1e-4 , true , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kGreen +  3 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.62169e-01 , 9.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.53893e-01 , 8.6e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1_IN"  , "^{214}Pb SWire P1 In " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.62169e-01 , 9.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Pb214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1_OUT" , "^{214}Pb SWire P1 Out" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.53893e-01 , 8.6e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Pb214_P1_OUT" )->SetFillColor( kAzure +  2 );

	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.22140e-02 , 3.01516e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.69628e-02 , 2.58033e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1_IN"  , "^{214}Pb SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.22140e-02 , 3.01516e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1_OUT" , "^{214}Pb SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.69628e-02 , 2.58033e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" )->SetFillColor( kAzure +  4 );

	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP2" ) , 8.53192e-02 , 2.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP2" ) , 1.00534e-01 , 2.2e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2_IN"  , "^{214}Pb SWire P2 In " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwireP2" ) , 8.53192e-02 , 2.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Pb214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2_OUT" , "^{214}Pb SWire P2 Out" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwireP2" ) , 1.00534e-01 , 2.2e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Pb214_P2_OUT" )->SetFillColor( kAzure +  2 );

	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.14207e-03 , 3.52491e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.07416e-03 , 3.27150e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  4 );	
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2_IN"  , "^{214}Pb SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.14207e-03 , 3.52491e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2_OUT" , "^{214}Pb SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.07416e-03 , 3.27150e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" )->SetFillColor( kAzure +  4 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) ,7360.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) , 484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) , 484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) ,9.51298e+01 , 1.00484e+01 , true , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) ,5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,1.35840e+01 , 2.88846e+00 , true , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,3.65096e+02 , 5.23372e+00 , true , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) ,3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) ,1.02045e+03 , 3.69086e+01 , true , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) ,7.90        , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) ,7.90        , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) ,7.90        , 3.3         , true , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * energy_score_fun_P1 = new Observable("energy_score_fun_P1 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_energy_score_fun_P1" ) ); energy_score_fun_P1 -> SetLogScale(kFALSE);
	Observable * tot_energy_P1       = new Observable("tot_energy_P1"        , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_tot_energy_P1" ) ); tot_energy_P1 -> SetLogScale(kFALSE);
	Observable * e_energy_P1         = new Observable("e_energy_P1"          , "1e2g - E_{e} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1" ) ); e_energy_P1 -> SetLogScale(kFALSE);
	Observable * glow_energy_P1      = new Observable("glow_energy_P1"       , "1e2g - E_{#gamma,Low}  - Phase 1 "  , kPhaseOne , hcoll->Find( "Data_h_glow_energy_P1"  ) ); glow_energy_P1  -> SetLogScale(kFALSE);	
	Observable * ghigh_energy_P1     = new Observable("ghigh_energy_P1"      , "1e2g - E_{#gamma,High}  - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_ghigh_energy_P1" ) ); ghigh_energy_P1 -> SetLogScale(kFALSE);

	Observable * energy_score_fun_P2 = new Observable("energy_score_fun_P2 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_energy_score_fun_P2" ) ); energy_score_fun_P2 -> SetLogScale(kFALSE);
	Observable * tot_energy_P2       = new Observable("tot_energy_P2"        , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_tot_energy_P2" ) ); tot_energy_P2 -> SetLogScale(kFALSE);	
	Observable * e_energy_P2         = new Observable("e_energy_P2"          , "1e2g - E_{e} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2" ) ); e_energy_P2-> SetLogScale(kFALSE);
	Observable * glow_energy_P2      = new Observable("glow_energy_P2"       , "1e2g - E_{#gamma,Low}  - Phase 2 "  , kPhaseTwo , hcoll->Find( "Data_h_glow_energy_P2"  ) ); glow_energy_P2  -> SetLogScale(kFALSE);	
	Observable * ghigh_energy_P2     = new Observable("ghigh_energy_P2"      , "1e2g - E_{#gamma,High}  - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_ghigh_energy_P2" ) ); ghigh_energy_P2 -> SetLogScale(kFALSE);
	
	Observable * tot_energy_3g       = new Observable("tot_energy_g3"        , "1e3g - E_{e} + E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} - Phase 1 & 2" , kAll , hcoll_3g->Find( "Data_h_tot_energy" ) ); tot_energy_3g -> SetLogScale(kFALSE);	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P1"     ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P1"	  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P1"        ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_energy_score_fun_P1"   ));         

	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P2"     ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P2"	  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P2"        ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_energy_score_fun_P2"   ));         
		
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P1"     ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P1"	  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_pb214_VT_h_tot_energy_P1"  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P1"  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P1"  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P1"  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_tot_energy_P1"        ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_tot_energy_P1"   ));         

	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P2"     ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P2"	  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_pb214_VT_h_tot_energy_P2"  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P2"  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P2"  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P2"  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     ));	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P2"     ));	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_tot_energy_P2"        ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_tot_energy_P2"   ));         

	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1"	  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_e_energy_P1"        ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1"   ));         

	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2"	  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_e_energy_P2"        ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2"   ));         

	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P1"     ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P1"	 ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_pb214_VT_h_glow_energy_P1"  ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P1"  ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P1"  ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P1"  ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_glow_energy_P1"        ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_glow_energy_P1"   ));         

	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P2"    ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P2"	   ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_pb214_VT_h_glow_energy_P2" ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P2" ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P2" ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P2" ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P2"    ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P2"    ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_glow_energy_P2"        ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_glow_energy_P2"   ));         

	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P1"     ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P1"	 ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_ghigh_energy_P1"  ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P1"  ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P1"  ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P1"  ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P1"     ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P1"     ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P1"        ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_ghigh_energy_P1"   ));         

	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P2"     ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P2"	 ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_pb214_VT_h_ghigh_energy_P2"  ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P2"  ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P2"  ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P2"  ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P2"     ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P2"     ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P2"        ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_ghigh_energy_P2"   ));         

	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_3g->Find( "Cd116_Tl208_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_3g->Find( "Cd116_Ac228_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll_3g->Find( "Cd116_Pb211_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll_3g->Find( "Cd116_Bi214_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll_3g->Find( "Cd116_pb214_VT_h_tot_energy"  ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_3g->Find( "Mylar_Bi214_h_tot_energy"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_3g->Find( "Mylar_Pb214_h_tot_energy"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_3g->Find( "FeShield_Bi214_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_3g->Find( "FeShield_Tl208_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_3g->Find( "FeShield_Ac228_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_3g->Find( "CuTower_Co60_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_3g->Find( "PMT_Bi214_h_tot_energy"      ));         
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_3g->Find( "Air_Bi214_h_tot_energy_P1"   ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_3g->Find( "Air_Pb214_h_tot_energy_P1"   ));	
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_3g->Find( "Air_Tl208_h_tot_energy_P1"   ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_3g->Find( "PMT_Tl208_h_tot_energy"      ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_3g->Find( "PMT_Ac228_h_tot_energy"      ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_3g->Find( "PMT_K40_h_tot_energy"        ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_3g->Find( "ScintInn_K40_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_3g->Find( "ScintOut_K40_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_3g->Find( "ScintPet_K40_h_tot_energy"   ));         

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( energy_score_fun_P1 );	
	DataManagement::AddObservable( energy_score_fun_P2 );	
	//DataManagement::AddObservable( tot_energy_P1 );
	//DataManagement::AddObservable( tot_energy_P2 );

	Fit::Run("Minuit", "Minimize");
    
	energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_energy_P1       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_energy_P2       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	glow_energy_P1      -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	glow_energy_P2      -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	ghigh_energy_P1     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");	
	ghigh_energy_P2     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_energy_3g       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");

	energy_score_fun_P1 -> SetLogScale(kTRUE); energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	energy_score_fun_P2 -> SetLogScale(kTRUE); energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_energy_P1       -> SetLogScale(kTRUE); tot_energy_P1       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_energy_P2       -> SetLogScale(kTRUE); tot_energy_P2       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	glow_energy_P1      -> SetLogScale(kTRUE); glow_energy_P1      -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	glow_energy_P2      -> SetLogScale(kTRUE); glow_energy_P2      -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	ghigh_energy_P1     -> SetLogScale(kTRUE); ghigh_energy_P1     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");	
	ghigh_energy_P2     -> SetLogScale(kTRUE); ghigh_energy_P2     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_energy_3g       -> SetLogScale(kTRUE); tot_energy_3g       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	
	
	
}