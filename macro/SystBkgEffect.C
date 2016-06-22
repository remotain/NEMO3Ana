{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos.root");
//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos_FirstGgHitOnly.root");
//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos_NoGgLayerCut_NoVertexCut_Eth300keV.root");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/TwoElectronIntHistos.root");
			
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	bool constrain_all = false;

	int sign = +1;
	//int sign = - 1;

	double syst_tl_208 = 1; 
	//syst_tl_208 = (1 + sign * 0.140);

	double syst_bi_214 = 1; 
	//syst_bi_214 = (1 + sign * 0.020);

	double syst_radon  = 1; 
	//syst_radon  = (1 + sign * 0.026);
	
	double syst_int    = 1; 
	//syst_int    = (1 + 0.35);
	//syst_int    = (1 - 0.35);
	
	double syst_ext    = 1; 
	//syst_ext    = (1 + 0.21);	
	syst_ext    = (1 - 0.21);	

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "cBB"       , "cBB"       ,  0 , 3.65343e-01    , 10. ) ); 
	
	DataManagement::AddParameter( new Parameter( "cCd116_K40_cold"    , "cCd116_K40_cold"     ,  1 , syst_int    *     3.65343e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_K40_cold"    ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_Pa234m_cold" , "cCd116_Pa234m_cold"  ,  2 , syst_int    *     9.99692e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_Pa234m_cold" ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_K40_warm"    , "cCd116_K40_warm"     ,  3 , syst_int    *     9.95358e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_K40_warm"    ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_Pa234m_warm" , "cCd116_Pa234m_warm"  ,  4 , syst_int    *     9.99900e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_Pa234m_warm" ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSFoil_Bi210_cold"  , "cSFoil_Bi210_cold"   ,  5 , syst_int    *     9.97151e-01 , 1 ) ); DataManagement::FindParameter( "cSFoil_Bi210_cold"  ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSFoil_Bi210_warm"  , "cSFoil_Bi210_warm"   ,  6 , syst_int    *     9.99924e-01 , 1 ) ); DataManagement::FindParameter( "cSFoil_Bi210_warm"  ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P1"    , "cSWire_Bi210_P1"     ,  7 , syst_int    *     9.99988e-01 , 1 ) ); DataManagement::FindParameter( "cSWire_Bi210_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P2"    , "cSWire_Bi210_P2"     ,  8 , syst_int    *     9.97501e-01 , 1 ) ); DataManagement::FindParameter( "cSWire_Bi210_P2"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCd116_Tl208"       , "cCd116_Tl208"        ,  9 , syst_tl_208 *     9.97534e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_Tl208"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCd116_Bi214"       , "cCd116_Bi214"        , 10 , syst_bi_214 *     9.80027e-01 , 1 ) ); DataManagement::FindParameter( "cCd116_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMylar_Bi214"       , "cMylar_Bi214"        , 11 , syst_bi_214 *     9.46646e-01 , 1 ) ); DataManagement::FindParameter( "cMylar_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P1"    , "cSwire_Tl208_P1"     , 12 , syst_tl_208 *     9.95069e-01 , 1 ) ); DataManagement::FindParameter( "cSwire_Tl208_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P2"    , "cSwire_Tl208_P2"     , 13 , syst_tl_208 *     9.87122e-01 , 1 ) ); DataManagement::FindParameter( "cSwire_Tl208_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P1"    , "cSwire_Bi214_P1"     , 14 , syst_radon  *     9.82112e-01 , 1 ) ); DataManagement::FindParameter( "cSwire_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P2"    , "cSwire_Bi214_P2"     , 15 , syst_radon  *     9.97443e-01 , 1 ) ); DataManagement::FindParameter( "cSwire_Bi214_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P1"    , "cSfoil_Bi214_P1"     , 16 , syst_radon  *     9.97288e-01 , 1 ) ); DataManagement::FindParameter( "cSfoil_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P2"    , "cSfoil_Bi214_P2"     , 17 , syst_radon  *     9.95076e-01 , 1 ) ); DataManagement::FindParameter( "cSfoil_Bi214_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cFeShield_Bi214"    , "cFeShield_Bi214"     , 18 , syst_ext    *     9.52671e-01 , 1 ) ); DataManagement::FindParameter( "cFeShield_Bi214"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cFeShield_Tl208"    , "cFeShield_Tl208"     , 19 , syst_ext    *     9.65451e-01 , 1 ) ); DataManagement::FindParameter( "cFeShield_Tl208"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCuTower_Co60"      , "cCuTower_Co60"       , 20 , syst_ext    *     6.50152e-01 , 1 ) ); DataManagement::FindParameter( "cCuTower_Co60"      ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cAir_Bi214_P1"      , "cAir_Bi214_P1"       , 21 , syst_ext    *     9.58620e-01 , 1 ) ); DataManagement::FindParameter( "cAir_Bi214_P1"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cAir_Tl208_P1"      , "cAir_Tl208_P1"       , 22 , syst_ext    *     9.98824e-01 , 1 ) ); DataManagement::FindParameter( "cAir_Tl208_P1"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Bi214"         , "cPMT_Bi214"          , 23 , syst_ext    *     9.57871e-01 , 1 ) ); DataManagement::FindParameter( "cPMT_Bi214"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Tl208"         , "cPMT_Tl208"          , 24 , syst_ext    *     9.71131e-01 , 1 ) ); DataManagement::FindParameter( "cPMT_Tl208"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_K40"           , "cPMT_K40"            , 25 , syst_ext    *     9.99147e-01 , 1 ) ); DataManagement::FindParameter( "cPMT_K40"           ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cScint_K40"         , "cScint_K40"          , 26 , syst_ext    *     9.98685e-01 , 1 ) ); DataManagement::FindParameter( "cScint_K40"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi210"       , "cSScin_Bi210"        , 27 , syst_ext    *     9.74930e-01 , 1 ) ); DataManagement::FindParameter( "cSScin_Bi210"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi214"       , "cSScin_Bi214"        , 28 , syst_ext    *     9.80756e-01 , 1 ) ); DataManagement::FindParameter( "cSScin_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMuMetal_Pa234m"    , "cMuMetal_Pa234m"     , 29 , syst_ext    *     9.86006e-01 , 1 ) ); DataManagement::FindParameter( "cMuMetal_Pa234m"    ) -> SetFix();	
	
	
	
	//////////////////////////////////////////////////////////////////////////////
	//
	// Groups
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddGroup( new Group( "Tl208"     , "^{208}Tl"   )); DataManagement::FindGroup("Tl208"     ) -> SetFillColor( kOrange + 10 );
	DataManagement::AddGroup( new Group( "Bi214"     , "^{214}Bi"   )); DataManagement::FindGroup("Bi214"     ) -> SetFillColor( kGreen  +  0 );
	DataManagement::AddGroup( new Group( "Radon"     , "Radon"      )); DataManagement::FindGroup("Radon"     ) -> SetFillColor( kAzure  +  1 );
	DataManagement::AddGroup( new Group( "Externals" , "Externals"  )); DataManagement::FindGroup("Externals" ) -> SetFillColor( kOrange +  0 );
	DataManagement::AddGroup( new Group( "K40"       , "K40"        )); DataManagement::FindGroup("K40"       ) -> SetFillColor( kViolet +  1 );
	DataManagement::AddGroup( new Group( "Pa234m"    , "Pa234m"     )); DataManagement::FindGroup("Pa234m"    ) -> SetFillColor( kViolet +  0 );	
	DataManagement::AddGroup( new Group( "Bi210"     , "^{210}Bi"   )); DataManagement::FindGroup("Bi210"     ) -> SetFillColor( kGreen  +  2 );
	DataManagement::AddGroup( new Group( "BB"        , "2#nu2#beta" )); DataManagement::FindGroup("BB"        ) -> SetFillColor( kViolet + 10 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// bb2nu
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ) , DataManagement::FindParameter( "cBB" ) , DataManagement::GetNormBB()*1e-19)); DataManagement::FindComponent("Cd116_2b2n_m14")  ->SetFillColor( kViolet + 10 );	
	DataManagement::FindGroup("BB")->AddComponent(DataManagement::FindComponent("Cd116_2b2n_m14"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Tl-208
	//
	//////////////////////////////////////////////////////////////////////////////false
	DataManagement::AddComponent( new Component( "Cd116_Tl208"     , "^{208}Tl Cd116"    , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00014*0.440        , 0.00002*0.440        , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228"     , "^{228}Ac Cd116"    , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00014*0.440/0.3594 , 0.00002*0.440/0.3594 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"     , "^{212}Bi Cd116"    , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00014*0.440/0.3594 , 0.00002*0.440/0.3594 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Tl208_P1"  , "^{208}Tl SWire P1" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P1" ) , 3.5E-03              , 0.4E-03              , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Tl208_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Tl208_P2"  , "^{208}Tl SWire P2" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P2" ) , 2.9E-03              , 0.4E-03              , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Tl208_P2"  )->SetFillColor( kAzure + 2 );

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
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cCd116_Bi214" ) ,  0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cCd116_Bi214" ) ,  0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) ,  0.888*0.0028 , 0.888*0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) ,  0.888*0.0028 , 0.888*0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kGreen +  3 );
	
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Mylar_Bi214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Mylar_Pb214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Cd116_Bi214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Cd116_Pb214" ));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Other Internals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cCd116_K40_cold"    ) , 0.0054 , 0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cCd116_K40_warm"    ) , 0.0099 , 0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cCd116_Pa234m_cold" ) , 0.0013 , 0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cCd116_Pa234m_warm" ) , 0.0023 , 0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	// Zac activities
	//DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0034 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0084 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0004 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0010 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) );
	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) );

	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "cSFoil_Bi210_cold" ) ,  1.15 , 0.01 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi210_cold" ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "cSFoil_Bi210_warm" ) ,  2.75 , 0.01 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi210_warm" ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Bi210_P1"    , "^{210}Bi SWire P1"    , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "cSWire_Bi210_P1"   ) ,  2.40 , 0.12 , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi210_P1"   ) -> SetFillColor( kGreen + 1 );
	DataManagement::AddComponent( new Component( "SWire_Bi210_P2"    , "^{210}Bi SWire P2"    , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "cSWire_Bi210_P2"   ) ,  2.40 , 0.12 , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi210_P2"   ) -> SetFillColor( kGreen + 1 );

	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent( "SFoil_Bi210_cold" ) );
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent( "SFoil_Bi210_warm" ) );
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent( "SWire_Bi210_P1"   ) );
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent( "SWire_Bi210_P2"   ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn 
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.03   , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.03   , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.005  , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.005  , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.001  , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.001  , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0003 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0003 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );

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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cFeShield_Bi214" ) , 10303       , 2023       , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 11 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield  ^{208}Tl " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55          , 50         , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield  ^{228}Ac " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55/0.3594   , 50/0.3594  , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cCuTower_Co60"   ) , 62          , 13         , constrain_all , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange +  9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 20         , constrain_all , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 20         , constrain_all , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cAir_Tl208_P1"   ) , 14          , 3          , constrain_all , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cPMT_Bi214"      ) , 269         , 47         , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4        , 1.4        , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4/0.3594 , 1.4/0.3594 , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cPMT_K40"        ) , 1300        , 45         , constrain_all , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1          , constrain_all , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1          , constrain_all , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 1          , constrain_all , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cSScin_Bi210"    ) , 35          , 5          , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"    , "^{214}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.03       , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Bi214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"    , "^{214}Pb SScin     " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.03       , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Pb214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "MuMetal_Pa234m" , "Mu Metal ^{234m}Pa " , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , DataManagement::FindParameter( "cMuMetal_Pa234m" ) , 2655        , 1180       , constrain_all , 1 )); DataManagement::FindComponent( "MuMetal_Pa234m" )->SetFillColor( kOrange +  5 );

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
	{
	
		Observable * tot_e_energy_P1_cold  = new Observable("tot_e_energy_P1_cold" , "2e - E_{e1} + E_{e2} - Phase 1 cold" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P1_cold" ) ); tot_e_energy_P1_cold -> SetLogScale(kFALSE); tot_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_cold -> SetDrawGroup(kTRUE); //tot_e_energy_P1_cold -> SetFitRangeLowEdge(0.5);
		Observable * min_e_energy_P1_cold  = new Observable("min_e_energy_P1_cold" , "2e - E_{e,min} - Phase 1 cold"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P1_cold" ) ); min_e_energy_P1_cold -> SetLogScale(kFALSE); min_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_cold -> SetDrawGroup(kTRUE); 
		Observable * max_e_energy_P1_cold  = new Observable("max_e_energy_P1_cold" , "2e - E_{e,max} - Phase 1 cold"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P1_cold" ) ); max_e_energy_P1_cold -> SetLogScale(kFALSE); max_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_cold -> SetDrawGroup(kTRUE); 
		Observable * cosTheta_P1_cold      = new Observable("cosTheta_P1_cold"     , "2e - Cos(#Theta) - Phase 1 cold"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P1_cold"     ) ); cosTheta_P1_cold     -> SetLogScale(kFALSE); cosTheta_P1_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_cold     -> SetDrawGroup(kTRUE); 
		hcoll->Find( "Data_h_cosTheta_P1_cold" ) ->GetYaxis()->SetRangeUser(0.5,500);
	
		Observable * tot_e_energy_P1_warm  = new Observable("tot_e_energy_P1_warm" , "2e - E_{e1} + E_{e2} - Phase 1 warm" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P1_warm" ) ); tot_e_energy_P1_warm -> SetLogScale(kFALSE); tot_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_warm -> SetDrawGroup(kTRUE); //tot_e_energy_P1_warm -> SetFitRangeLowEdge(0.5);
		Observable * min_e_energy_P1_warm  = new Observable("min_e_energy_P1_warm" , "2e - E_{e,min} - Phase 1 warm"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P1_warm" ) ); min_e_energy_P1_warm -> SetLogScale(kFALSE); min_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_warm -> SetDrawGroup(kTRUE); 
		Observable * max_e_energy_P1_warm  = new Observable("max_e_energy_P1_warm" , "2e - E_{e,max} - Phase 1 warm"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P1_warm" ) ); max_e_energy_P1_warm -> SetLogScale(kFALSE); max_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_warm -> SetDrawGroup(kTRUE); 
		Observable * cosTheta_P1_warm      = new Observable("cosTheta_P1_warm"     , "2e - Cos(#Theta) - Phase 1 warm"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P1_warm"     ) ); cosTheta_P1_warm     -> SetLogScale(kFALSE); cosTheta_P1_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_warm     -> SetDrawGroup(kTRUE); 
		hcoll->Find( "Data_h_cosTheta_P1_warm" ) ->GetYaxis()->SetRangeUser(0.5,500);
		
		Observable * tot_e_energy_P2_cold  = new Observable("tot_e_energy_P2_cold" , "2e - E_{e1} + E_{e2} - Phase 2 cold" , kPhaseTwo , hcoll->Find( "Data_h_tot_e_energy_P2_cold" ) ); tot_e_energy_P2_cold -> SetLogScale(kFALSE); tot_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_cold -> SetDrawGroup(kTRUE); //tot_e_energy_P2_cold -> SetFitRangeLowEdge(0.5);
		Observable * min_e_energy_P2_cold  = new Observable("min_e_energy_P2_cold" , "2e - E_{e,min} - Phase 2 cold"       , kPhaseTwo , hcoll->Find( "Data_h_min_e_energy_P2_cold" ) ); min_e_energy_P2_cold -> SetLogScale(kFALSE); min_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_cold -> SetDrawGroup(kTRUE); 
		Observable * max_e_energy_P2_cold  = new Observable("max_e_energy_P2_cold" , "2e - E_{e,max} - Phase 2 cold"       , kPhaseTwo , hcoll->Find( "Data_h_max_e_energy_P2_cold" ) ); max_e_energy_P2_cold -> SetLogScale(kFALSE); max_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_cold -> SetDrawGroup(kTRUE); 
		Observable * cosTheta_P2_cold      = new Observable("cosTheta_P2_cold"     , "2e - Cos(#Theta) - Phase 2 cold"     , kPhaseTwo , hcoll->Find( "Data_h_cosTheta_P2_cold"     ) ); cosTheta_P2_cold     -> SetLogScale(kFALSE); cosTheta_P2_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_cold     -> SetDrawGroup(kTRUE); 
		hcoll->Find( "Data_h_cosTheta_P2_cold" ) ->GetYaxis()->SetRangeUser(0.5,500);
	
		Observable * tot_e_energy_P2_warm  = new Observable("tot_e_energy_P2_warm" , "2e - E_{e1} + E_{e2} - Phase 2 warm" , kPhaseTwo , hcoll->Find( "Data_h_tot_e_energy_P2_warm" ) ); tot_e_energy_P2_warm -> SetLogScale(kFALSE); tot_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_warm -> SetDrawGroup(kTRUE); //tot_e_energy_P2_warm -> SetFitRangeLowEdge(0.5);
		Observable * min_e_energy_P2_warm  = new Observable("min_e_energy_P2_warm" , "2e - E_{e,min} - Phase 2 warm"       , kPhaseTwo , hcoll->Find( "Data_h_min_e_energy_P2_warm" ) ); min_e_energy_P2_warm -> SetLogScale(kFALSE); min_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_warm -> SetDrawGroup(kTRUE); 
		Observable * max_e_energy_P2_warm  = new Observable("max_e_energy_P2_warm" , "2e - E_{e,max} - Phase 2 warm"       , kPhaseTwo , hcoll->Find( "Data_h_max_e_energy_P2_warm" ) ); max_e_energy_P2_warm -> SetLogScale(kFALSE); max_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_warm -> SetDrawGroup(kTRUE); 
		Observable * cosTheta_P2_warm      = new Observable("cosTheta_P2_warm"     , "2e - Cos(#Theta) - Phase 2 warm"     , kPhaseTwo , hcoll->Find( "Data_h_cosTheta_P2_warm"     ) ); cosTheta_P2_warm     -> SetLogScale(kFALSE); cosTheta_P2_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_warm     -> SetDrawGroup(kTRUE); 
		hcoll->Find( "Data_h_cosTheta_P2_warm" ) ->GetYaxis()->SetRangeUser(0.5,500);

	}
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	// P1 Cold
	{
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_cold" ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1_cold"    ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1_cold"    ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_tot_e_energy_P1_cold"    ) );   		
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P1_cold" ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P1_cold" ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P1_cold" ) );      		
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P1_cold"        ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P1_cold"   ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P1_cold" ) );            
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_cold" ) );      
    	
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_cold" ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P1_cold"    ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P1_cold"    ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_min_e_energy_P1_cold"    ) );   		
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P1_cold" ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P1_cold" ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P1_cold" ) );      		
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P1_cold"        ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P1_cold"   ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_min_e_energy_P1_cold" ) );            
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_cold" ) );      
    	
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_cold" ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P1_cold"    ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P1_cold"    ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_max_e_energy_P1_cold"    ) );   		
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P1_cold" ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P1_cold" ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P1_cold" ) );      		
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P1_cold"        ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P1_cold"   ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_max_e_energy_P1_cold" ) );            
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_cold" ) );      
	
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P1_cold" ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P1_cold"    ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P1_cold"    ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_cosTheta_P1_cold"    ) );   		
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P1_cold" ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P1_cold" ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P1_cold" ) );      		
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P1_cold"        ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P1_cold"   ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_cosTheta_P1_cold" ) );            
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P1_cold" ) );      
	}
	// P1 Warm
	{
		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_warm" ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1_warm"    ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1_warm"    ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_tot_e_energy_P1_warm"    ) );   		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P1_warm" ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P1_warm" ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P1_warm" ) );      				
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P1_warm"        ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P1_warm"   ) );      		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_warm" ) );      

		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_warm" ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P1_warm"    ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P1_warm"    ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_min_e_energy_P1_warm"    ) );   		
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P1_warm" ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P1_warm" ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P1_warm" ) );      				
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P1_warm"        ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_min_e_energy_P1_warm"   ) );      		
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_warm" ) );      

		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_warm" ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P1_warm"    ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P1_warm"    ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_max_e_energy_P1_warm"    ) );   		
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P1_warm" ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P1_warm" ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P1_warm" ) );      				
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P1_warm"        ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_max_e_energy_P1_warm"   ) );      		
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_warm" ) );      
	
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P1_warm" ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P1_warm"    ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P1_warm"    ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_cosTheta_P1_warm"    ) );   		
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P1_warm" ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P1_warm" ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P1_warm" ) );      				
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P1_warm"        ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_cosTheta_P1_warm"   ) );      		
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P1_warm" ) );      
	
		
	}
	// P2 Cold
	{
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_cold" ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2_cold"    ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2_cold"    ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_cold"      ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_cold"   ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_tot_e_energy_P2_cold"    ) );   		
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P2_cold" ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P2_cold" ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P2_cold" ) );      				
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P2_cold"        ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P2_cold"   ) );      		
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_cold" ) );      

		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_cold" ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P2_cold"    ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P2_cold"    ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P2_cold"      ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_cold"   ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_min_e_energy_P2_cold"    ) );   		
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P2_cold" ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P2_cold" ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P2_cold" ) );      				
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P2_cold"        ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_min_e_energy_P2_cold"   ) );      		
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_cold" ) );      

		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_cold" ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P2_cold"    ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P2_cold"    ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P2_cold"      ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_cold"   ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_max_e_energy_P2_cold"    ) );   		
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P2_cold" ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P2_cold" ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P2_cold" ) );      				
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P2_cold"        ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_max_e_energy_P2_cold"   ) );      		
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_cold" ) );      
		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P2_cold" ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P2_cold"    ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P2_cold"    ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P2_cold"      ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_cold"   ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_cosTheta_P2_cold"    ) );   		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P2_cold" ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P2_cold" ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P2_cold" ) );      				
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P2_cold"        ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_cosTheta_P2_cold"   ) );      		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P2_cold" ) );      
		
		
	}
	// P2 Warm
	{
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_warm" ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2_warm"    ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2_warm"    ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_warm"      ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_warm"   ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_tot_e_energy_P2_warm"    ) );   		
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P2_warm" ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P2_warm" ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P2_warm" ) );      				
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P2_warm"        ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P2_warm"   ) );      		
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_warm" ) );      

		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_warm" ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P2_warm"    ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P2_warm"    ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P2_warm"      ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_warm"   ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_max_e_energy_P2_warm"    ) );   		
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P2_warm" ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P2_warm" ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P2_warm" ) );      				
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P2_warm"        ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_max_e_energy_P2_warm"   ) );      		
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_warm" ) );      

		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_warm" ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P2_warm"    ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P2_warm"    ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P2_warm"      ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_warm"   ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_min_e_energy_P2_warm"    ) );   		
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P2_warm" ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P2_warm" ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P2_warm" ) );      				
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P2_warm"        ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_min_e_energy_P2_warm"   ) );      		
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_warm" ) );      

		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P2_warm" ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P2_warm"    ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P2_warm"    ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P2_warm"      ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_warm"   ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_cosTheta_P2_warm"    ) );   		
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P2_warm" ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P2_warm" ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P2_warm" ) );      				
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P2_warm"        ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_cosTheta_P2_warm"   ) );      		
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P2_warm" ) );      
	}
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1_cold );	
	DataManagement::AddObservable( tot_e_energy_P2_cold );	
	DataManagement::AddObservable( tot_e_energy_P1_warm );	
	DataManagement::AddObservable( tot_e_energy_P2_warm );	

	Fit::Run("Minuit", "Minimize");
    
	cout << "T_{1/2}^{2\\nu} = " << 1/DataManagement::FindParameter("cBB")->GetValInit() << "+/-" << 1/DataManagement::FindParameter("cBB")->GetValInit()**2*DataManagement::FindParameter("cBB")->GetValError() << " 1e+19 y" << endl;	
	
}

