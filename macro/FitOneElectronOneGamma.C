{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronOneGammaHistos", "OneElectronOneGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronOneGammaInt.root");
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
	DataManagement::AddParameter( new Parameter( "cInt"  , "cInt"  ,  0 , 1.  , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cRnP1" , "cRnP1" ,  1 , 0.9 , 0.1 ) ); DataManagement::FindParameter( "cRnP1" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cRnP2" , "cRnP2" ,  2 , 1.7 , 0.1 ) ); DataManagement::FindParameter( "cRnP2" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cExt"  , "cExt"  ,  3 , 1.  , 0.1 ) ); DataManagement::FindParameter( "cExt"  ) -> SetFix(); 
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cInt" ) , 0.440*1.82391e-04 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cInt" ) , 0.4401.82391e-04  )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214" ) , DataManagement::FindParameter( "cInt" ) , 0.440*2.82801e-04 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214" ) , DataManagement::FindParameter( "cInt" ) , 0.887680542*3.01073e-03 )); DataManagement::FindComponent( "Mylar_Bi214" )->SetFillColor( kGreen +  1 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRnP1" ) , 6.62169e-01 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRnP1" ) , 6.53893e-01 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRnP2" ) , 8.53192e-02 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRnP2" ) , 1.00534e-01 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  2 );
	//
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRnP1" ) , 1.22140e-02 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRnP1" ) , 1.69628e-02 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRnP2" ) , 1.14207e-03 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRnP2" ) , 1.07416e-03 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  4 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) , 7360.00     )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kViolet + 1 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) ,  484.00     )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kViolet + 2 );	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) , 1.02045e+03 )); DataManagement::FindComponent( "PMT_K40"      )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 3.65096e+02 )); DataManagement::FindComponent( "PMT_Bi214"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 )); DataManagement::FindComponent( "Air_Bi214_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) , 5.67075e+02 )); DataManagement::FindComponent( "Air_Pb214_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 )); DataManagement::FindComponent( "PMT_Tl208"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) , 3.69908e+01 )); DataManagement::FindComponent( "PMT_Ac228"    )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 1.35840e+01 )); DataManagement::FindComponent( "Air_Tl208_P1" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) , 9.51298e+01 )); DataManagement::FindComponent( "CuTower_Co60" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) , 2.03793e+01 )); DataManagement::FindComponent( "SScin_Bi210"  )->SetFillColor( kOrange + 10 );		
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * tot_energy_P1    = new Observable("tot_energy_P1" , "1e1g - E_{e} + E_{#gamma} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_tot_energy_P1" ) ); tot_energy_P1 -> SetLogScale(kFALSE);
	//Observable * e_energy_P1      = new Observable("e_energy_P1"   , "1e1g - E_{e} - Phase 1 "              , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1"   ) ); e_energy_P1   -> SetLogScale(kFALSE);
	//Observable * g_energy_P1      = new Observable("g_energy_P1"   , "1e1g - E_{#gamma}  - Phase 1 "        , kPhaseOne , hcoll->Find( "Data_h_g_energy_P1"   ) ); g_energy_P1   -> SetLogScale(kFALSE);	

	Observable * tot_energy_P2    = new Observable("tot_energy_P2" , "1e1g - E_{e} + E_{#gamma} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_tot_energy_P2" ) ); tot_energy_P2 -> SetLogScale(kFALSE);	
	//Observable * e_energy_P2      = new Observable("e_energy_P2"   , "1e1g - E_{e} - Phase 2 "              , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2"   ) ); e_energy_P2   -> SetLogScale(kFALSE);
	//Observable * g_energy_P2      = new Observable("g_energy_P2"   , "1e1g - E_{#gamma}  - Phase 2 "        , kPhaseTwo , hcoll->Find( "Data_h_g_energy_P2"   ) ); g_energy_P2   -> SetLogScale(kFALSE);	
	
	Observable * tot_energy_3g    = new Observable("tot_energy_g3" , "1e3g - E_{e} + E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} - Phase 1 & 2" , kAll , hcoll_3g->Find( "Data_h_tot_energy" ) ); tot_energy_3g -> SetLogScale(kFALSE);	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
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

	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1"     ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1"	  ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1"     ));	
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1"  ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1"  ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1"  ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P1"   	  ));
	//e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1"   	  ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"       ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"       ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1"       ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1"       ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"       ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1"    ));
    //e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1"     ));
    //
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2"     ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2"	  ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2"     ));	
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2"  ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2"  ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2"  ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_e_energy_P2"   	  ));
	//e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2"   	  ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2"       ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2"       ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2"    ));
    //e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2"     ));
    //
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_g_energy_P1"     ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_g_energy_P1"     ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_g_energy_P1"	    ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_g_energy_P1"     ));	
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_g_energy_P1"  ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_g_energy_P1"  ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_g_energy_P1"  ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll->Find( "SWire_Bi214_h_g_energy_P1"     ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll->Find( "SWire_Bi214_h_g_energy_P1"     ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll->Find( "SFoil_Bi214_h_g_energy_P1"     ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll->Find( "SFoil_Bi214_h_g_energy_P1"     ));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_g_energy_P1"     	));
	//g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_g_energy_P1"   	));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_g_energy_P1"       ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_g_energy_P1"       ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_g_energy_P1"       ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_g_energy_P1"       ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_g_energy_P1"       ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_g_energy_P1"    ));
    //g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_g_energy_P1"     ));
	//	
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_g_energy_P2"     ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_g_energy_P2"     ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_g_energy_P2"	    ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_g_energy_P2"     ));	
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_g_energy_P2"  ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_g_energy_P2"  ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_g_energy_P2"  ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll->Find( "SWire_Bi214_h_g_energy_P2"     ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll->Find( "SWire_Bi214_h_g_energy_P2"     ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll->Find( "SFoil_Bi214_h_g_energy_P2"     ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll->Find( "SFoil_Bi214_h_g_energy_P2"     ));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll->Find( "PMT_K40_h_g_energy_P2"      	));
	//g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll->Find( "PMT_Bi214_h_g_energy_P2"   	));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_g_energy_P2"       ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_g_energy_P2"       ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_g_energy_P2"    ));
    //g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_g_energy_P2"     ));	
	
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
	DataManagement::AddObservable( tot_energy_P1 );	
	DataManagement::AddObservable( tot_energy_P2 );	

	Fit::Run("Minuit", "Minimize");
    
	tot_energy_P1       -> Draw();
	tot_energy_P2       -> Draw();
	//e_energy_P1      -> Draw();
	//e_energy_P2      -> Draw();
	//g_energy_P1      -> Draw();
	//g_energy_P2      -> Draw();
	
	tot_energy_3g       -> Draw();
	
}