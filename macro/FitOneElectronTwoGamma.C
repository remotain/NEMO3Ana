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
	DataManagement::AddParameter( new Parameter( "Cd116_Tl208" , "Cd116_Tl208" , 0 , 1.67295e-04 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Tl208"  ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwireP1"    , "cSwireP1"    , 1 , 0.5         , 0.1 ) ); //DataManagement::FindParameter( "cSwireP1"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoilP1"    , "cSfoilP1"    , 2 , 9.99252e-01 , 0.1 ) ); //DataManagement::FindParameter( "cSfoilP1"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwireP2"    , "cSwireP2"    , 3 , 0.5 , 0.1 ) ); //DataManagement::FindParameter( "cSwireP2"     ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoilP2"    , "cSfoilP2"    , 4 , 9.96903e-01 , 0.1 ) ); //DataManagement::FindParameter( "cSfoilP2"     ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cInt"        , "cInt"        , 5 , 9.99680e-01 , 0.1 ) ); //DataManagement::FindParameter( "cInt"         ) -> SetFix();             
	DataManagement::AddParameter( new Parameter( "cExt"        , "cExt"        , 6 , 9.82486e-01 , 0.1 ) ); //DataManagement::FindParameter( "cExt"         ) -> SetFix();                                                                                            
	//////////////////////////////////////////////////////////////////////////////               
	//	
	// Tl Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 1 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi Internal
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "cInt" ), 0.440*2.82801e-04 , 0.440*8.53952e-05 , true, 2)); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi from Mylar
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "cInt" ), 0.887680542*3.01073e-03, 0.887680542*2.28492e-04, true, 2 )); DataManagement::FindComponent( "Mylar_Bi214"   )->SetFillColor( kGreen +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber
	//
	//////////////////////////////////////////////////////////////////////////////	
	// Values from 1e1a channel
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 6.62169e-01 , 5.29137e-02 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 6.53893e-01 , 5.15176e-02 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 8.53192e-02 , 6.19447e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 1.00534e-01 , 6.20848e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  1 );

	// Values from Vera DocDB 2751
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 6.141e-01 , 9.7e-03 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 5.754e-01 , 8.6e-03 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , 81.3e-03 , 2.7e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , 70.2e-03 , 2.2e-03 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  1 );
	
	//DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.22140e-02 , 3.01516e-03 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.69628e-02 , 2.58033e-03 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.14207e-03 , 3.52491e-04 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	//DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , 1.07416e-03 , 3.27150e-04 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  1 );	
	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.62169e-01 , 9.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP1" ) , 6.53893e-01 , 8.6e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.22140e-02 , 3.01516e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP1" ) , 1.69628e-02 , 2.58033e-03 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP2" ) , 8.53192e-02 , 2.7e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwireP2" ) , 1.00534e-01 , 2.2e-03     , true , 2 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.14207e-03 , 3.52491e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoilP2" ) , 1.07416e-03 , 3.27150e-04 , true , 2 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  4 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////
	//DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , 7360.00 , 200.00 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kViolet + 0 );
	//DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet + 0 );
	//DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet + 0 );	
	//DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"      ) , 1.02045e+03, 3.69086e+01 )); DataManagement::FindComponent( "PMT_K40"      )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"    ) , 3.65096e+02, 5.02773e+00 )); DataManagement::FindComponent( "PMT_Bi214"    )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"    ) , 5.67075e+02, 1.97080e+01 )); DataManagement::FindComponent( "Air_Bi214_P1" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"    ) , 5.67075e+02, 1.97080e+01 )); DataManagement::FindComponent( "Air_Pb214_P1" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"    ) , 3.69908e+01, 5.36727e-01 )); DataManagement::FindComponent( "PMT_Tl208"    )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"    ) , 3.69908e+01, 5.36727e-01 )); DataManagement::FindComponent( "PMT_Ac228"    )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"    ) , 1.35840e+01, 2.78419e+00 )); DataManagement::FindComponent( "Air_Tl208_P1" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60" ) , 9.51298e+01, 9.78469e+00 )); DataManagement::FindComponent( "CuTower_Co60" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"  ) , 2.03793e+01, 6.37295e-01 )); DataManagement::FindComponent( "SScin_Bi210"  )->SetFillColor( kOrange + 10 );

	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) , 7360.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet + 1 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     , 1.          , true , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet + 2 );	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) , 1.02045e+03 , 3.69086e+01 , true , 1 )); DataManagement::FindComponent( "PMT_K40"      )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 3.65096e+02 , 5.23372e+00 , true , 1 )); DataManagement::FindComponent( "PMT_Bi214"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Bi214_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 , 2.06779e+01 , true , 1 )); DataManagement::FindComponent( "Air_Pb214_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Tl208"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 , 5.59895e-01 , true , 1 )); DataManagement::FindComponent( "PMT_Ac228"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 1.35840e+01 , 2.88846e+00 , true , 1 )); DataManagement::FindComponent( "Air_Tl208_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) , 9.51298e+01 , 1.00484e+01 , true , 1 )); DataManagement::FindComponent( "CuTower_Co60" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) , 2.03793e+01 , 6.77523e-01 , true , 1 )); DataManagement::FindComponent( "SScin_Bi210"  )->SetFillColor( kOrange + 10 );		

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * energy_score_fun_P1 = new Observable("energy_score_fun_P1 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_energy_score_fun_P1" ) ); energy_score_fun_P1 -> SetLogScale(kFALSE);
	Observable * tot_energy_P1       = new Observable("tot_energy_P1"   , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_tot_energy_P1" ) ); tot_energy_P1 -> SetLogScale(kFALSE);
	Observable * e_energy_P1         = new Observable("e_energy_P1"   , "1e2g - E_{e} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1" ) ); e_energy_P1 -> SetLogScale(kFALSE);
	Observable * glow_energy_P1      = new Observable("glow_energy_P1"  , "1e2g - E_{#gamma,Low}  - Phase 1 "  , kPhaseOne , hcoll->Find( "Data_h_glow_energy_P1"  ) ); glow_energy_P1  -> SetLogScale(kFALSE);	
	Observable * ghigh_energy_P1     = new Observable("ghigh_energy_P1" , "1e2g - E_{#gamma,High}  - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_ghigh_energy_P1" ) ); ghigh_energy_P1 -> SetLogScale(kFALSE);

	Observable * energy_score_fun_P2 = new Observable("energy_score_fun_P2 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_energy_score_fun_P2" ) ); energy_score_fun_P2 -> SetLogScale(kFALSE);
	Observable * tot_energy_P2       = new Observable("tot_energy_P2"   , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_tot_energy_P2" ) ); tot_energy_P2 -> SetLogScale(kFALSE);	
	Observable * e_energy_P2         = new Observable("e_energy_P2"   , "1e2g - E_{e} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2" ) ); e_energy_P2-> SetLogScale(kFALSE);
	Observable * glow_energy_P2      = new Observable("glow_energy_P2"  , "1e2g - E_{#gamma,Low}  - Phase 2 "  , kPhaseTwo , hcoll->Find( "Data_h_glow_energy_P2"  ) ); glow_energy_P2  -> SetLogScale(kFALSE);	
	Observable * ghigh_energy_P2     = new Observable("ghigh_energy_P2" , "1e2g - E_{#gamma,High}  - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_ghigh_energy_P2" ) ); ghigh_energy_P2 -> SetLogScale(kFALSE);
	
	Observable * tot_energy_3g       = new Observable("tot_energy_g3"   , "1e3g - E_{e} + E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} - Phase 1 & 2" , kAll , hcoll_3g->Find( "Data_h_tot_energy" ) ); tot_energy_3g -> SetLogScale(kFALSE);	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P1"     ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P1"     ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P1"	  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P1"   	  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P1"   	  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_energy_score_fun_P1"       ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_energy_score_fun_P1"       ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P1"       ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P1"       ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_energy_score_fun_P1"       ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P1"    ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_energy_score_fun_P1"     ));
		
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P2"     ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P2"     ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P2"	  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P2"   	  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P2"   	  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P2"       ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P2"       ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P2"    ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_energy_score_fun_P2"     ));

	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P1"     ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P1"     ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P1"	  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P1"  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P1"  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P1"  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"     	   ) , hcoll->Find( "PMT_K40_h_tot_energy_P1"   	  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	   ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P1"   	  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_tot_energy_P1"       ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_tot_energy_P1"       ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P1"       ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P1"       ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_tot_energy_P1"       ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P1"    ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_tot_energy_P1"     ));

	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P2"     ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P2"     ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P2"	  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P2"     ));	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P2"  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P2"  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P2"  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	       ) , hcoll->Find( "PMT_K40_h_tot_energy_P2"   	  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	   ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P2"   	  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P2"       ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P2"       ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P2"    ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_tot_energy_P2"     ));

	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1"	  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P1"   	  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1"   	  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1"    ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1"     ));

	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2"	  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P2"   	  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2"   	  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2"    ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2"     ));

	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P1"     ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P1"     ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P1"	    ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P1"  ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P1"  ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P1"  ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_glow_energy_P1"     	));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P1"   	));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_glow_energy_P1"       ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_glow_energy_P1"       ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P1"       ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P1"       ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_glow_energy_P1"       ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P1"    ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_glow_energy_P1"     ));
		
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P2"     ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P2"     ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P2"	    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P2"     ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P2"  ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P2"  ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P2"  ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P2"     ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P2"     ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P2"     ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P2"     ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_glow_energy_P2"      	));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P2"   	));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P2"       ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P2"       ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P2"    ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_glow_energy_P2"     ));	
	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P1"    ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P1"    ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P1"	 ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P1"    ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P1" ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P1" ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P1" ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P1"    ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P1"    ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P1"    ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P1"    ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P1"   	 ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P1"   	 ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_ghigh_energy_P1"       ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_ghigh_energy_P1"       ));	
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P1"      ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P1"      ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_ghigh_energy_P1"       ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P1"   ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_ghigh_energy_P1"    ));
		
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P2"    ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P2"    ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P2"	 ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P2"    ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P2" ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P2" ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P2" ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P2"    ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P2"    ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P2"    ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P2"    ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P2"   	 ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P2"   	 ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P2"      ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P2"      ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P2"   ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_ghigh_energy_P2"    ));

	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_3g->Find( "Cd116_Tl208_h_tot_energy"     ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_3g->Find( "Cd116_Ac228_h_tot_energy"     ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll_3g->Find( "Cd116_Bi214_h_tot_energy"	 ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_3g->Find( "Mylar_Bi214_h_tot_energy"     ));	
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_3g->Find( "FeShield_Bi214_h_tot_energy"  ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_3g->Find( "FeShield_Tl208_h_tot_energy"  ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_3g->Find( "FeShield_Ac228_h_tot_energy"  ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P1"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P1"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P1"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P1"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P2"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P2"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P2"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P2"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	       ) , hcoll_3g->Find( "PMT_K40_h_tot_energy"   	     ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	   ) , hcoll_3g->Find( "PMT_Bi214_h_tot_energy"   	 ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_3g->Find( "Air_Bi214_h_tot_energy_P1"       ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_3g->Find( "Air_Pb214_h_tot_energy_P1"       ));	
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_3g->Find( "PMT_Tl208_h_tot_energy"       ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_3g->Find( "PMT_Ac228_h_tot_energy"       ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_3g->Find( "Air_Tl208_h_tot_energy_P1"       ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_3g->Find( "CuTower_Co60_h_tot_energy"    ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_3g->Find( "SScin_Bi210_h_tot_energy"     ));

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