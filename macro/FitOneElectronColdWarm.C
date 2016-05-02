{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSampleBkg.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root");
	
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
	DataManagement::AddParameter( new Parameter( "Cd116_K40_cold"    , "Cd116_K40_cold"    ,  0 , 5.29348e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_cold" , "Cd116_Pa234m_cold" ,  1 , 1.09687e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_K40_warm"    , "Cd116_K40_warm"    ,  2 , 9.73645e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_warm" , "Cd116_Pa234m_warm" ,  3 , 2.13357e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_cold"  , "SFoil_Bi210_cold"  ,  4 , 1.14829e+00 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_warm"  , "SFoil_Bi210_warm"  ,  5 , 2.75597e+00 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P1"  , "cSWire_Bi210_P1"    ,  6 , 1.04586e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P2"  , "cSWire_Bi210_P2"    ,  7 , 9.59644e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cCd116_Tl208"    , "cCd116_Tl208"        ,  8 , 9.51694e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cCd116_Bi214"    , "cCd116_Bi214"        ,  9 , 1.19547e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cMylar_Bi214"    , "cMylar_Bi214"        , 10 , 1.01007e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P1" , "cSwire_Tl208_P1"     , 11 , 9.88111e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P2" , "cSwire_Tl208_P2"     , 12 , 9.81685e-01 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P1" , "cSwire_Bi214_P1"     , 13 , 1.05324e+00 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P2" , "cSwire_Bi214_P2"     , 14 , 1.01661e+00 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P1" , "cSfoil_Bi214_P1"     , 15 , 1.01907e+00 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P2" , "cSfoil_Bi214_P2"     , 16 , 9.50728e-01 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cFeShield_Bi214" , "cFeShield_Bi214"     , 17 , 1.14369e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cFeShield_Tl208" , "cFeShield_Tl208"     , 18 , 1.03335e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cCuTower_Co60"   , "cCuTower_Co60"       , 19 , 9.66856e-01 , 0.1 ) );	
	DataManagement::AddParameter( new Parameter( "cAir_Bi214_P1"   , "cAir_Bi214_P1"       , 20 , 1.01641e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cAir_Tl208_P1"   , "cAir_Tl208_P1"       , 21 , 1.88903e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cPMT_Bi214"      , "cPMT_Bi214"          , 22 , 9.94233e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cPMT_Tl208"      , "cPMT_Tl208"          , 23 , 1.00506e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cPMT_K40"        , "cPMT_K40"            , 24 , 1.00023e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cScint_K40"      , "cScint_K40"          , 25 , 9.79671e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi210"    , "cSScin_Bi210"        , 26 , 1.00068e+00 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi214"    , "cSScin_Bi214"        , 27 , 9.80337e-01 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cMuMetal_Pa234m" , "cMuMetal_Pa234m"     , 28 , 7.47917e-01 , 0.1 ) );	


	//////////////////////////////////////////////////////////////////////////////
	//
	// Groups
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddGroup( new Group( "Tl208"     , "^{208}Tl"   )); DataManagement::FindGroup("Tl208"     ) -> SetFillColor( kOrange + 10 );
	DataManagement::AddGroup( new Group( "Bi214"     , "^{214}Bi"   )); DataManagement::FindGroup("Bi214"     ) -> SetFillColor( kGreen  +  0 );
	DataManagement::AddGroup( new Group( "Radon"     , "Radon"      )); DataManagement::FindGroup("Radon"     ) -> SetFillColor( kAzure  +  1 );
	DataManagement::AddGroup( new Group( "Externals" , "Externals"  )); DataManagement::FindGroup("Externals" ) -> SetFillColor( kOrange +  0 );
	DataManagement::AddGroup( new Group( "BB"        , "2#nu2#beta" )); DataManagement::FindGroup("BB"        ) -> SetFillColor( kViolet + 10 );	
	DataManagement::AddGroup( new Group( "Pa234m"    , "^{234m}Pa"  )); DataManagement::FindGroup("Pa234m"    ) -> SetFillColor( kViolet +  1 );
	DataManagement::AddGroup( new Group( "K40"       , "^{40}K"     )); DataManagement::FindGroup("K40"       ) -> SetFillColor( kViolet +  2 );
	DataManagement::AddGroup( new Group( "Bi210"     , "^{210}Bi"   )); DataManagement::FindGroup("Bi210"     ) -> SetFillColor( kGreen  +  2 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// bb2nu
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ), DataManagement::GetNormBB()/2.75e19, 0.05*DataManagement::GetNormBB()/2.75e19)); DataManagement::FindComponent("Cd116_2b2n_m14")  ->SetFillColor( kViolet + 10 );	

	DataManagement::FindGroup("BB")->AddComponent(DataManagement::FindComponent("Cd116_2b2n_m14"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// K-40
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_cold"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_warm"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	

	DataManagement::FindGroup("K40")->AddComponent(DataManagement::FindComponent("Cd116_K40_cold"));
	DataManagement::FindGroup("K40")->AddComponent(DataManagement::FindComponent("Cd116_K40_warm"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Pa-234m
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_cold" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_warm" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );	

	DataManagement::FindGroup("Pa234m")->AddComponent(DataManagement::FindComponent("Cd116_Pa234m_cold"));
	DataManagement::FindGroup("Pa234m")->AddComponent(DataManagement::FindComponent("Cd116_Pa234m_warm"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-210
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "SFoil_Bi210_cold"  ) , 1. )); DataManagement::FindComponent("SFoil_Bi210_cold"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "SFoil_Bi210_warm"  ) , 1. )); DataManagement::FindComponent("SFoil_Bi210_warm"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Bi210_P1"    , "^{210}Bi SWire P1"    , DataManagement::FindDataSet( "SWire_Bi210" )  , DataManagement::FindParameter( "cSWire_Bi210_P1" ) , 2.48 , 0.12 , true, 1 )); DataManagement::FindComponent( "SWire_Bi210_P1"  )->SetFillColor( kGreen + 1 );
	DataManagement::AddComponent( new Component( "SWire_Bi210_P2"    , "^{210}Bi SWire P2"    , DataManagement::FindDataSet( "SWire_Bi210" )  , DataManagement::FindParameter( "cSWire_Bi210_P2" ) , 2.40 , 0.12 , true, 1 )); DataManagement::FindComponent( "SWire_Bi210_P2"  )->SetFillColor( kGreen + 1 );

	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_cold"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_warm"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SWire_Bi210_P1"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SWire_Bi210_P2"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Tl-208
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cCd116_Tl208" ) , 0.00014*0.440        , 0.00002*0.440        , true , 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cCd116_Tl208" ) , 0.00014*0.440/0.3594 , 0.00002*0.440/0.3594 , true , 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"  ,"^{212}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "cCd116_Tl208" ) , 0.00014*0.440/0.3594 , 0.00002*0.440/0.3594 , true , 1 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Tl208_P1"  , "^{208}Tl SWire P1" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P1" ) , 3.5E-03 , 0.4E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Tl208_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Tl208_P2"  , "^{208}Tl SWire P2" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P2" ) , 2.9E-03 , 0.4E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Tl208_P2"  )->SetFillColor( kAzure + 2 );

	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1" ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2" ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "Cd116_Tl208"    ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "Cd116_Ac228"    ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "Cd116_Bi212"    ));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-214
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , true , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , true , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0002 , true , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0002 , true , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kGreen +  3 );

	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Pb214"));
	//////////////////////////////////////////////////////////////////////////////	
	//	
	// Rn
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.03   , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.03   , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.005  , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.005  , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.001  , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.001  , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0003 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0003 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );

	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2" ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cFeShield_Bi214" ) , 10303       , 2023       , true , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 11 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield  ^{208}Tl " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55          , 50         , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield  ^{228}Ac " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55/0.3594   , 50/0.3594  , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cCuTower_Co60"   ) , 62          , 13         , true , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange +  9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 20         , true , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 20         , true , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cAir_Tl208_P1"   ) , 14          , 3          , true , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cPMT_Bi214"      ) , 269         , 47         , true , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4        , 1.4        , true , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4/0.3594 , 1.4/0.3594 , true , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cPMT_K40"        ) , 1300        , 45         , true , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1        , true , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1        , true , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1        , true , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cSScin_Bi210"    ) , 35          , 4          , true , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"    , "^{214}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.03       , true , 1 )); DataManagement::FindComponent( "SScin_Bi214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"    , "^{214}Pb SScin     " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.03       , true , 1 )); DataManagement::FindComponent( "SScin_Pb214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "MuMetal_Pa234m" , "Mu Metal ^{234m}Pa " , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , DataManagement::FindParameter( "cMuMetal_Pa234m" ) , 2655        , 1180       , true , 1 )); DataManagement::FindComponent( "MuMetal_Pa234m" )->SetFillColor( kOrange +  5 );

	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Bi214" ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Tl208" ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Ac228" ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "CuTower_Co60"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "PMT_Bi214"      ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "PMT_Tl208"      ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "PMT_Ac228"      ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "PMT_K40"        ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "ScintInn_K40"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "ScintOut_K40"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "ScintPet_K40"   ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "SScin_Bi210"    ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "SScin_Bi214"    ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "SScin_Pb214"    ) );
	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m" ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_cold = new Observable("e_energy_P1_cold" , "E_{e} - Phase 1 Cold" , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1_cold" ) ); e_energy_P1_cold -> SetLogScale(kFALSE); e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_cold -> SetDrawGroup(kTRUE); //e_energy_P1_cold -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P2_cold = new Observable("e_energy_P2_cold" , "E_{e} - Phase 2 Cold" , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2_cold" ) ); e_energy_P2_cold -> SetLogScale(kFALSE); e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_cold -> SetDrawGroup(kTRUE); //e_energy_P2_cold -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P1_warm = new Observable("e_energy_P1_warm" , "E_{e} - Phase 1 Warm" , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1_warm" ) ); e_energy_P1_warm -> SetLogScale(kFALSE); e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_warm -> SetDrawGroup(kTRUE); //e_energy_P1_warm -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P2_warm = new Observable("e_energy_P2_warm" , "E_{e} - Phase 2 Warm" , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2_warm" ) ); e_energy_P2_warm -> SetLogScale(kFALSE); e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_warm -> SetDrawGroup(kTRUE); //e_energy_P2_warm -> SetFitRangeLowEdge(1.5);

	Observable * e_vertexZ_cold = new Observable("e_vertexZ_cold" , "Vertez Z - Phase 1+2 Cold", kAll, hcoll->Find("Data_h_vertexZ_cold"      ) ); e_vertexZ_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_vertexZ_cold -> SetDrawGroup(kTRUE);
	Observable * e_vertexZ_warm = new Observable("e_vertexZ_warm" , "Vertez Z - Phase 1+2 Warm", kAll, hcoll->Find("Data_h_vertexZ_warm"      ) ); e_vertexZ_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_vertexZ_warm -> SetDrawGroup(kTRUE);
	Observable * e_vertexS_cold = new Observable("e_vertexS_cold" , "Vertez S - Phase 1+2 Cold", kAll, hcoll->Find("Data_h_vertexSector_cold" ) ); e_vertexS_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_vertexS_cold -> SetDrawGroup(kTRUE);
	Observable * e_vertexS_warm = new Observable("e_vertexS_warm" , "Vertez S - Phase 1+2 Warm", kAll, hcoll->Find("Data_h_vertexSector_warm" ) ); e_vertexS_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_vertexS_warm -> SetDrawGroup(kTRUE);	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_cold"	    ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P1_cold"  ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_cold"     ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_cold"     ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_cold"  ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_cold"  ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_cold"  ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_e_energy_P1_cold"         ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_cold"    ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_cold"    ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_cold"    ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1_cold"       ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_cold"    ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P1_cold"   ));	
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P1_cold"  ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"       ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"    ));

	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P2_cold"  ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_cold"     ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_cold"     ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_cold"  ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_cold"  ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_cold"  ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_e_energy_P2_cold"   	    ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_cold"    ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_cold"    ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_cold"    ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_cold"       ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_cold"       ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_cold"       ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_cold"    ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P2_cold"   ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_cold"       ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_cold"    ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"       ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P2_cold"));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_cold"     ));

	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexZ_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexZ_cold" ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexZ_cold"    ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexZ_cold"    ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_vertexZ_P2_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_vertexZ_P1_cold"    ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_vertexZ_P2_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_vertexZ_P2_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_vertexZ_P2_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_vertexZ_P2_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_vertexZ_P1_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_vertexZ_P1_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_vertexZ_P1_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_vertexZ_P1_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_vertexZ_cold" ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexZ_cold" ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexZ_cold" ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_vertexZ_cold"  	     ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_vertexZ_cold"   ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_vertexZ_cold"   ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_vertexZ_cold"   ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_vertexZ_cold"      ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_vertexZ_P1_cold"      ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_vertexZ_P1_cold"      ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_vertexZ_P1_cold"      ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_vertexZ_cold"      ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_vertexZ_cold"      ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_vertexZ_cold"   ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_vertexZ_cold"  ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_vertexZ_cold"      ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_vertexZ_cold"   ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_vertexZ_cold"    ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_vertexZ_P1_cold" ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_vertexZ_P2_cold" ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_vertexZ_cold"    ));

	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexSector_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexSector_cold" ));	
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexSector_cold"    ));	
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexSector_cold"    ));	
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_vertexSector_P2_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_vertexSector_P1_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_vertexSector_P2_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_vertexSector_P2_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_vertexSector_P2_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_vertexSector_P2_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_vertexSector_P1_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_vertexSector_P1_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_vertexSector_P1_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_vertexSector_P1_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_vertexSector_cold" ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexSector_cold" ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexSector_cold" ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_vertexSector_cold"  	     ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_vertexSector_cold"   ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_vertexSector_cold"   ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_vertexSector_cold"   ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_vertexSector_cold"      ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_vertexSector_P1_cold"      ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_vertexSector_P1_cold"      ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_vertexSector_P1_cold"      ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_vertexSector_cold"      ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_vertexSector_cold"      ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_vertexSector_cold"   ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_vertexSector_cold"  ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_vertexSector_cold"      ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_vertexSector_cold"   ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_vertexSector_cold" ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_vertexSector_cold" ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_vertexSector_cold" ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_vertexSector_cold" ));	
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_vertexSector_P1_cold" ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_vertexSector_P2_cold" ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_vertexSector_cold"    ));

	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_warm"	  ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P1_warm"  ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_warm"     ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_warm"     ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_warm"     ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_warm"  ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_warm"  ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_warm"  ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_e_energy_P1_warm"         ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_warm"    ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_warm"    ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_warm"    ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1_warm"       ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_warm"    ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P1_warm"   ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"       ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm"    ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P1_warm"     ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"     ));

	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P2_warm"  ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_warm"     ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_warm"     ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_warm"  ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_warm"  ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_warm"  ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_e_energy_P2_warm"   	  ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_warm"    ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_warm"    ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_warm"    ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_warm"       ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_warm"       ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_warm"       ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_warm"    ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_e_energy_P2_warm"   ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_warm"       ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_warm"    ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P2_warm"     ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_warm"     ));
  
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexZ_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexZ_warm" ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexZ_warm"    ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexZ_warm"    ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_vertexZ_P1_warm"    ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_vertexZ_P1_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_vertexZ_P1_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_vertexZ_P1_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_vertexZ_P1_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_vertexZ_warm" ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexZ_warm" ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexZ_warm" ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_vertexZ_warm"  	     ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_vertexZ_warm"   ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_vertexZ_warm"   ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_vertexZ_warm"   ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_vertexZ_warm"      ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_vertexZ_P1_warm"      ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_vertexZ_P1_warm"      ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_vertexZ_P1_warm"      ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_vertexZ_warm"      ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_vertexZ_warm"      ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_vertexZ_warm"   ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_vertexZ_warm"  ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll->Find( "Cd116_K40_h_vertexZ_warm"      ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll->Find( "Cd116_Pa234m_h_vertexZ_warm"   ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_vertexZ_warm"    ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_vertexZ_P1_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_vertexZ_P2_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_vertexZ_warm"    ));

	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexSector_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexSector_warm" ));	
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexSector_warm"    ));	
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexSector_warm"    ));	
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_vertexSector_warm" ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexSector_warm" ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexSector_warm" ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	        ) , hcoll->Find( "PMT_K40_h_vertexSector_warm"  	     ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_vertexSector_warm"   ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_vertexSector_warm"   ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_vertexSector_warm"   ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	    ) , hcoll->Find( "PMT_Bi214_h_vertexSector_warm"      ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_vertexSector_P1_warm"      ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_vertexSector_P1_warm"      ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_vertexSector_P1_warm"      ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_vertexSector_warm"      ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_vertexSector_warm"      ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_vertexSector_warm"   ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_vertexSector_warm"  ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll->Find( "Cd116_K40_h_vertexSector_warm"      ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll->Find( "Cd116_Pa234m_h_vertexSector_warm"   ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_vertexSector_warm"    ));	
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_vertexSector_P1_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_vertexSector_P2_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_vertexSector_warm"    ));
  	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( e_energy_P1_cold );
	DataManagement::AddObservable( e_energy_P2_cold );
	DataManagement::AddObservable( e_energy_P1_warm );	
	DataManagement::AddObservable( e_energy_P2_warm );

	Fit::DoDrawScan();
	Fit::Run("Minuit", "Minimize");

	e_energy_P1_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf(");
	e_energy_P1_cold -> SetLogScale(kTRUE); e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy_P1_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy_P1_warm -> SetLogScale(kTRUE); e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");

	e_energy_P2_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy_P2_cold -> SetLogScale(kTRUE); e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy_P2_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy_P2_warm -> SetLogScale(kTRUE); e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");

	e_vertexZ_cold -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_vertexS_cold -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_vertexZ_warm -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_vertexS_warm -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");


	//////////////////////////////////////////////////////////////////////////////
	//	
  	// Total summed histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy = new Observable("e_energy" , "E_{e} - Phase 1 + Phase 2 Warm/Cold" , kAll , hcoll->Find( "Data_h_electronEnergy" ) ); e_energy -> SetLogScale(kFALSE); e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy -> SetDrawGroup(kTRUE); 
	
	hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_e_energy_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_e_energy_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_e_energy_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_e_energy_P2_warm"    ) );
	
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_electronEnergy"     ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_electronEnergy"     ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_electronEnergy"     ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_electronEnergy"	    ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_electronEnergy"  ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_electronEnergy"     ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_electronEnergy"     ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2"     ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_electronEnergy"  ));
    e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_electronEnergy"  ));
    e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_electronEnergy"  ));
	e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_electronEnergy"         ));
	e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintOut_K40_h_electronEnergy"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintPet_K40_h_electronEnergy"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintInn_K40_h_electronEnergy"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll->Find( "PMT_Bi214_h_electronEnergy"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_electronEnergy"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_electronEnergy"       ));
    e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_electronEnergy"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll->Find( "Cd116_2b2n_m4_h_electronEnergy"   ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"       ));
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"       ));
	e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm"    ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"     ));
    e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_electronEnergy"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_electronEnergy"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_electronEnergy"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_electronEnergy"     ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2"     ));

	e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf");
	e_energy -> SetLogScale(kTRUE); e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.pdf)");

	e_energy->DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm_Details.pdf");
	e_energy->PrintDetails();
	
}