{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos.root");
//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos_FirstGgHitOnly.root");
//	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronIntHistos_NoGgLayerCut_NoVertexCut_Eth300keV.root");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TwoElectronIntHistos.root");
			
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	bool constrain_all = true;

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "cBB"       , "cBB"       ,  0 , 3.40846e-01    , 0.0001 ) ); 
	
	DataManagement::AddParameter( new Parameter( "cCd116_K40_cold"    , "cCd116_K40_cold"     ,  1 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_K40_cold"    ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_Pa234m_cold" , "cCd116_Pa234m_cold"  ,  2 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Pa234m_cold" ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_K40_warm"    , "cCd116_K40_warm"     ,  3 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_K40_warm"    ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cCd116_Pa234m_warm" , "cCd116_Pa234m_warm"  ,  4 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Pa234m_warm" ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSFoil_Bi210_cold"  , "cSFoil_Bi210_cold"   ,  5 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSFoil_Bi210_cold"  ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSFoil_Bi210_warm"  , "cSFoil_Bi210_warm"   ,  6 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSFoil_Bi210_warm"  ) -> SetFix();  
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P1"    , "cSWire_Bi210_P1"     ,  7 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSWire_Bi210_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P2"    , "cSWire_Bi210_P2"     ,  8 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSWire_Bi210_P2"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCd116_Tl208"       , "cCd116_Tl208"        ,  9 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Tl208"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCd116_Bi214"       , "cCd116_Bi214"        , 10 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMylar_Bi214"       , "cMylar_Bi214"        , 11 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cMylar_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P1"    , "cSwire_Tl208_P1"     , 12 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Tl208_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P2"    , "cSwire_Tl208_P2"     , 13 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Tl208_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P1"    , "cSwire_Bi214_P1"     , 14 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P2"    , "cSwire_Bi214_P2"     , 15 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P1"    , "cSfoil_Bi214_P1"     , 16 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P2"    , "cSfoil_Bi214_P2"     , 17 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cFeShield_Bi214"    , "cFeShield_Bi214"     , 18 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cFeShield_Bi214"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cFeShield_Tl208"    , "cFeShield_Tl208"     , 19 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cFeShield_Tl208"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cCuTower_Co60"      , "cCuTower_Co60"       , 20 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCuTower_Co60"      ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cAir_Bi214_P1"      , "cAir_Bi214_P1"       , 21 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cAir_Bi214_P1"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cAir_Tl208_P1"      , "cAir_Tl208_P1"       , 22 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cAir_Tl208_P1"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Bi214"         , "cPMT_Bi214"          , 23 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cPMT_Bi214"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Tl208"         , "cPMT_Tl208"          , 24 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cPMT_Tl208"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_K40"           , "cPMT_K40"            , 25 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cPMT_K40"           ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cScint_K40"         , "cScint_K40"          , 26 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cScint_K40"         ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi210"       , "cSScin_Bi210"        , 27 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSScin_Bi210"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi214"       , "cSScin_Bi214"        , 28 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSScin_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMuMetal_Pa234m"    , "cMuMetal_Pa234m"     , 29 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cMuMetal_Pa234m"    ) -> SetFix();	
	
	
	
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
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m4" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m4" ) , DataManagement::FindParameter( "cBB" ) , DataManagement::GetNormBB()*1e-19)); DataManagement::FindComponent("Cd116_2b2n_m4")  ->SetFillColor( kViolet + 10 );	
	DataManagement::FindGroup("BB")->AddComponent(DataManagement::FindComponent("Cd116_2b2n_m4"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Tl-208
	//
	//////////////////////////////////////////////////////////////////////////////false
	DataManagement::AddComponent( new Component( "Cd116_Tl208"     , "^{208}Tl Cd116"    , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00013*0.440        , 0.00003*0.440        , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228"     , "^{228}Ac Cd116"    , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00013*0.440/0.3594 , 0.00003*0.440/0.3594 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"     , "^{212}Bi Cd116"    , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "cCd116_Tl208"    ) , 0.00013*0.440/0.3594 , 0.00003*0.440/0.3594 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 2 );	
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
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0003 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0003 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kGreen +  3 );
	
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Mylar_Bi214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Mylar_Pb214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Cd116_Bi214" ));
	DataManagement::FindGroup("Bi214")->AddComponent( DataManagement::FindComponent( "Cd116_Pb214" ));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Other Internals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cCd116_K40_cold"    ) , 0.0054 , 0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cCd116_K40_warm"    ) , 0.0099 , 0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cCd116_Pa234m_cold" ) , 0.0013 , 0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cCd116_Pa234m_warm" ) , 0.0023 , 0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	// Zac activities
	//DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0034 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0084 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0004 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0010 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) );
	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) );

	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "cSFoil_Bi210_cold" ) ,  1.15 , 0.02 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi210_cold" ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "cSFoil_Bi210_warm" ) ,  2.75 , 0.02 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi210_warm" ) -> SetFillColor( kGreen + 2 );	
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
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.04   , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P1" ) , 0.67   , 0.04   , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.006  , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire_Bi214_P2" ) , 0.091  , 0.006  , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.002  , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P1" ) , 0.015  , 0.002  , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0004 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil_Bi214_P2" ) , 0.0013 , 0.0004 , constrain_all , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );

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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cFeShield_Bi214" ) , 10303       , 2835       , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 11 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield  ^{208}Tl " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55          , 19         , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield  ^{228}Ac " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cFeShield_Tl208" ) , 55/0.3594   , 19/0.3594  , constrain_all , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cCuTower_Co60"   ) , 62          , 19         , constrain_all , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange +  9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 28         , constrain_all , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cAir_Bi214_P1"   ) , 600         , 28         , constrain_all , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cAir_Tl208_P1"   ) , 14          , 4          , constrain_all , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cPMT_Bi214"      ) , 302         , 75         , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4        , 0.7        , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cPMT_Tl208"      ) , 45.4/0.3594 , 0.7/0.3594 , constrain_all , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cPMT_K40"        ) , 1300        , 64         , constrain_all , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 0.9        , constrain_all , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 0.9        , constrain_all , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cScint_K40"      ) , 6.2         , 0.9        , constrain_all , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cSScin_Bi210"    ) , 35          , 5          , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"    , "^{214}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.04       , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Bi214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"    , "^{214}Pb SScin     " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "cSScin_Bi214"    ) , 0.25        , 0.04       , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Pb214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "MuMetal_Pa234m" , "Mu Metal ^{234m}Pa " , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , DataManagement::FindParameter( "cMuMetal_Pa234m" ) , 2655        , 1659       , constrain_all , 1 )); DataManagement::FindComponent( "MuMetal_Pa234m" )->SetFillColor( kOrange +  5 );

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
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_tot_e_energy_P1_cold" ) );      
    	
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
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_min_e_energy_P1_cold" ) );      
    	
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
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_max_e_energy_P1_cold" ) );      
	
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
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_cosTheta_P1_cold" ) );      
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
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_tot_e_energy_P1_warm" ) );      

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
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_min_e_energy_P1_warm" ) );      

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
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_max_e_energy_P1_warm" ) );      
	
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
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_cosTheta_P1_warm" ) );      
	
		
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
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_tot_e_energy_P2_cold" ) );      

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
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_min_e_energy_P2_cold" ) );      

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
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_max_e_energy_P2_cold" ) );      
		
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
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_cosTheta_P2_cold" ) );      
		
		
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
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_tot_e_energy_P2_warm" ) );      

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
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_max_e_energy_P2_warm" ) );      

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
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_min_e_energy_P2_warm" ) );      

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
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_cosTheta_P2_warm" ) );      
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

	//DataManagement::AddObservable( min_e_energy_P1_cold );	
	//DataManagement::AddObservable( min_e_energy_P2_cold );	
	//DataManagement::AddObservable( min_e_energy_P1_warm );	
	//DataManagement::AddObservable( min_e_energy_P2_warm );	
    //
	//DataManagement::AddObservable( max_e_energy_P1_cold );	
	//DataManagement::AddObservable( max_e_energy_P2_cold );	
	//DataManagement::AddObservable( max_e_energy_P1_warm );	
	//DataManagement::AddObservable( max_e_energy_P2_warm );	
    //
	//DataManagement::AddObservable( cosTheta_P1_cold );	
	//DataManagement::AddObservable( cosTheta_P2_cold );	
	//DataManagement::AddObservable( cosTheta_P1_warm );	
	//DataManagement::AddObservable( cosTheta_P2_warm );	


	//Fit::DoDrawCorrelationMatrix();
	//Fit::DoDrawScan();
	//Fit::DoDrawContour();
	Fit::Run("Minuit", "Minimize");
    
	cout << "T_{1/2}^{2\\nu} = " << 1/DataManagement::FindParameter("cBB")->GetValInit() << "+/-" << 1/DataManagement::FindParameter("cBB")->GetValInit()**2*DataManagement::FindParameter("cBB")->GetValError() << " 1e+19 y" << endl;
	
	tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf(" ); tot_e_energy_P1_cold -> SetLogScale(kTRUE);
    tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); min_e_energy_P1_cold -> SetLogScale(kTRUE);
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); max_e_energy_P1_cold -> SetLogScale(kTRUE);
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); cosTheta_P1_cold -> SetLogScale(kTRUE);
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );

	tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); tot_e_energy_P2_cold -> SetLogScale(kTRUE);
    tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); min_e_energy_P2_cold -> SetLogScale(kTRUE);
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); max_e_energy_P2_cold -> SetLogScale(kTRUE);
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); cosTheta_P2_cold -> SetLogScale(kTRUE);
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );

	tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); tot_e_energy_P1_warm -> SetLogScale(kTRUE);
    tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); min_e_energy_P1_warm -> SetLogScale(kTRUE);
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); max_e_energy_P1_warm -> SetLogScale(kTRUE);
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); cosTheta_P1_warm -> SetLogScale(kTRUE);
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );

	tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); tot_e_energy_P2_warm -> SetLogScale(kTRUE);
    tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); min_e_energy_P2_warm -> SetLogScale(kTRUE);
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); max_e_energy_P2_warm -> SetLogScale(kTRUE);
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); cosTheta_P2_warm -> SetLogScale(kTRUE);
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  );	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Summed plot
	//
	//////////////////////////////////////////////////////////////////////////////	
	
	Observable * tot_e_energy  = new Observable("tot_e_energy" , "2e - E_{e1} + E_{e2}" , kAll , hcoll->Find( "Data_h_tot_e_energy" ) ); tot_e_energy -> SetLogScale(kFALSE); tot_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy -> SetDrawGroup(kTRUE);
	Observable * min_e_energy  = new Observable("min_e_energy" , "2e - E_{e,min}"       , kAll , hcoll->Find( "Data_h_min_e_energy" ) ); min_e_energy -> SetLogScale(kFALSE); min_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy -> SetDrawGroup(kTRUE);
	Observable * max_e_energy  = new Observable("max_e_energy" , "2e - E_{e,max}"       , kAll , hcoll->Find( "Data_h_max_e_energy" ) ); max_e_energy -> SetLogScale(kFALSE); max_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy -> SetDrawGroup(kTRUE);

	Observable * cosTheta      = new Observable("cosTheta"     , "2e - Cos(#Theta)"     , kAll , hcoll->Find( "Data_h_cosTheta"     ) ); cosTheta     -> SetLogScale(kFALSE); cosTheta     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta     -> SetDrawGroup(kTRUE);
	hcoll->Find( "Data_h_cosTheta" ) ->GetYaxis()->SetRangeUser(0.5,1000);

	Observable * e_vtx_dx  = new Observable("e_vtx_dx" , "2e - #DeltaX"       , kAll , hcoll->Find( "Data_h_vtx_dx" ) ); e_vtx_dx -> SetLogScale(kFALSE); e_vtx_dx -> AddGroupAll(DataManagement::GetGroupCollection()); e_vtx_dx -> SetDrawGroup(kTRUE);
	hcoll->Find( "Data_h_vtx_dx" ) ->GetYaxis()->SetRangeUser(0.01,10000);
	hcoll->Find( "Data_h_vtx_dx" ) ->Rebin(2);
	
	Observable * e_vtx_dy  = new Observable("e_vtx_dy" , "2e - #DeltaY"       , kAll , hcoll->Find( "Data_h_vtx_dy" ) ); e_vtx_dy -> SetLogScale(kFALSE); e_vtx_dy -> AddGroupAll(DataManagement::GetGroupCollection()); e_vtx_dy -> SetDrawGroup(kTRUE);
	hcoll->Find( "Data_h_vtx_dy" ) ->GetYaxis()->SetRangeUser(0.01,10000);
	hcoll->Find( "Data_h_vtx_dy" ) ->Rebin(2);

	Observable * e_vtx_dz  = new Observable("e_vtx_dz" , "2e - #DeltaZ"       , kAll , hcoll->Find( "Data_h_vtx_dz" ) ); e_vtx_dz -> SetLogScale(kFALSE); e_vtx_dz -> AddGroupAll(DataManagement::GetGroupCollection()); e_vtx_dz -> SetDrawGroup(kTRUE);
	hcoll->Find( "Data_h_vtx_dz" ) ->GetYaxis()->SetRangeUser(0.01,10000);
	hcoll->Find( "Data_h_vtx_dz" ) ->Rebin(2);
	
	Observable * e_vtx_dr  = new Observable("e_vtx_dr" , "2e - #DeltaR"       , kAll , hcoll->Find( "Data_h_vtx_dr" ) ); e_vtx_dr -> SetLogScale(kFALSE); e_vtx_dr -> AddGroupAll(DataManagement::GetGroupCollection()); e_vtx_dr -> SetDrawGroup(kTRUE);
	hcoll->Find( "Data_h_vtx_dr" ) ->GetYaxis()->SetRangeUser(0.01,10000);
	hcoll->Find( "Data_h_vtx_dr" ) ->Rebin(2);

	hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_min_e_energy_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_min_e_energy_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_max_e_energy_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_max_e_energy_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_cosTheta_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_cosTheta_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_vtx_dx_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dx_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dx_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_vtx_dx_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dx_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dx_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_vtx_dy_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dy_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dy_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_vtx_dy_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dy_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dy_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_vtx_dz_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dz_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dz_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_vtx_dz_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dz_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dz_P2_warm"    ) );

	hcoll->Find( "Cd116_K40_h_vtx_dr_P1_cold"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dr_P2_cold"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_cold"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P2_cold"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_cold"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dr_P2_cold"    ) );
	hcoll->Find( "Cd116_K40_h_vtx_dr_P1_warm"      ) -> Add( hcoll->Find( "Cd116_K40_h_vtx_dr_P2_warm"      ) );
	hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_warm"   ) -> Add( hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P2_warm"   ) );
	hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_warm"    ) -> Add( hcoll->Find( "SFoil_Bi210_h_vtx_dr_P2_warm"    ) );



	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy" ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2"    ) );   	
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy" ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy" ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy" ) );      		
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy"        ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy"   ) );      	
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_tot_e_energy" ) );      

	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy" ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy" ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy" ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy" ) );      		
	min_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy"        ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_min_e_energy"   ) );      	
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_min_e_energy" ) );      

	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy" ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2"    ) );   	
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy" ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy" ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy" ) );      		
	max_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy"        ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_max_e_energy"   ) );      	
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_max_e_energy" ) );      

	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta" ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta" ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta" ) );      		
	cosTheta -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta"        ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_cosTheta"   ) );      	
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_cosTheta" ) );      
	
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_vtx_dx"            ) ); hcoll->Find( "Cd116_Tl208_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_vtx_dx"            ) ); hcoll->Find( "Cd116_Ac228_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_vtx_dx"            ) ); hcoll->Find( "Cd116_Bi212_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_vtx_dx"            ) ); hcoll->Find( "Cd116_Bi214_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_vtx_dx"         ) ); hcoll->Find( "Cd116_Pb214_VT_h_vtx_dx"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_vtx_dx"            ) ); hcoll->Find( "Mylar_Bi214_h_vtx_dx"            ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_vtx_dx"            ) ); hcoll->Find( "Mylar_Pb214_h_vtx_dx"            ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_vtx_dx_P1_cold"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dx_P1_cold"      ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_cold"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_cold"   ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_cold"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_cold"    ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_vtx_dx_P1_warm"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dx_P1_warm"      ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_warm"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dx_P1_warm"   ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_warm"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dx_P1_warm"    ) -> Rebin(2);
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dx_P1"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dx_P2"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_vtx_dx"            ) ); hcoll->Find( "SScin_Bi210_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_vtx_dx"            ) ); hcoll->Find( "SScin_Bi214_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_vtx_dx"            ) ); hcoll->Find( "SScin_Pb214_h_vtx_dx"            ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dx_P1"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dx_P1"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dx_P1"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dx_P1"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dx_P1"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dx_P1"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dx_P2"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dx_P2"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dx_P2"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dx_P2"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dx_P2"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dx_P2"         ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_vtx_dx"         ) ); hcoll->Find( "FeShield_Bi214_h_vtx_dx"         ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_vtx_dx"         ) ); hcoll->Find( "FeShield_Tl208_h_vtx_dx"         ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_vtx_dx"         ) ); hcoll->Find( "FeShield_Ac228_h_vtx_dx"         ) -> Rebin(2);      		
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_vtx_dx"           ) ); hcoll->Find( "CuTower_Co60_h_vtx_dx"           ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_vtx_dx_P1"           ) ); hcoll->Find( "Air_Bi214_h_vtx_dx_P1"           ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_vtx_dx_P1"           ) ); hcoll->Find( "Air_Pb214_h_vtx_dx_P1"           ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_vtx_dx_P1"           ) ); hcoll->Find( "Air_Tl208_h_vtx_dx_P1"           ) -> Rebin(2);   
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_vtx_dx"              ) ); hcoll->Find( "PMT_Bi214_h_vtx_dx"              ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_vtx_dx"              ) ); hcoll->Find( "PMT_Tl208_h_vtx_dx"              ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_vtx_dx"              ) ); hcoll->Find( "PMT_Ac228_h_vtx_dx"              ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_vtx_dx"                ) ); hcoll->Find( "PMT_K40_h_vtx_dx"                ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_vtx_dx"           ) ); hcoll->Find( "ScintInn_K40_h_vtx_dx"           ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_vtx_dx"           ) ); hcoll->Find( "ScintOut_K40_h_vtx_dx"           ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_vtx_dx"           ) ); hcoll->Find( "ScintPet_K40_h_vtx_dx"           ) -> Rebin(2);      
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_vtx_dx"         ) ); hcoll->Find( "MuMetal_Pa234m_h_vtx_dx"         ) -> Rebin(2);      	
	e_vtx_dx -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_vtx_dx"         ) ); hcoll->Find( "Cd116_2b2n_m4_h_vtx_dx"         ) -> Rebin(2);      

	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_vtx_dy"            ) ); hcoll->Find( "Cd116_Tl208_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_vtx_dy"            ) ); hcoll->Find( "Cd116_Ac228_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_vtx_dy"            ) ); hcoll->Find( "Cd116_Bi212_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_vtx_dy"            ) ); hcoll->Find( "Cd116_Bi214_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_vtx_dy"         ) ); hcoll->Find( "Cd116_Pb214_VT_h_vtx_dy"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_vtx_dy"            ) ); hcoll->Find( "Mylar_Bi214_h_vtx_dy"            ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_vtx_dy"            ) ); hcoll->Find( "Mylar_Pb214_h_vtx_dy"            ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_vtx_dy_P1_cold"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dy_P1_cold"      ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_cold"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_cold"   ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_cold"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_cold"    ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_vtx_dy_P1_warm"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dy_P1_warm"      ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_warm"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dy_P1_warm"   ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_warm"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dy_P1_warm"    ) -> Rebin(2);
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dy_P1"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dy_P2"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_vtx_dy"            ) ); hcoll->Find( "SScin_Bi210_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_vtx_dy"            ) ); hcoll->Find( "SScin_Bi214_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_vtx_dy"            ) ); hcoll->Find( "SScin_Pb214_h_vtx_dy"            ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dy_P1"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dy_P1"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dy_P1"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dy_P1"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dy_P1"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dy_P1"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dy_P2"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dy_P2"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dy_P2"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dy_P2"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dy_P2"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dy_P2"         ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_vtx_dy"         ) ); hcoll->Find( "FeShield_Bi214_h_vtx_dy"         ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_vtx_dy"         ) ); hcoll->Find( "FeShield_Tl208_h_vtx_dy"         ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_vtx_dy"         ) ); hcoll->Find( "FeShield_Ac228_h_vtx_dy"         ) -> Rebin(2);     		
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_vtx_dy"           ) ); hcoll->Find( "CuTower_Co60_h_vtx_dy"           ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_vtx_dy_P1"           ) ); hcoll->Find( "Air_Bi214_h_vtx_dy_P1"           ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_vtx_dy_P1"           ) ); hcoll->Find( "Air_Pb214_h_vtx_dy_P1"           ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_vtx_dy_P1"           ) ); hcoll->Find( "Air_Tl208_h_vtx_dy_P1"           ) -> Rebin(2);  
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_vtx_dy"              ) ); hcoll->Find( "PMT_Bi214_h_vtx_dy"              ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_vtx_dy"              ) ); hcoll->Find( "PMT_Tl208_h_vtx_dy"              ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_vtx_dy"              ) ); hcoll->Find( "PMT_Ac228_h_vtx_dy"              ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_vtx_dy"                ) ); hcoll->Find( "PMT_K40_h_vtx_dy"                ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_vtx_dy"           ) ); hcoll->Find( "ScintInn_K40_h_vtx_dy"           ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_vtx_dy"           ) ); hcoll->Find( "ScintOut_K40_h_vtx_dy"           ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_vtx_dy"           ) ); hcoll->Find( "ScintPet_K40_h_vtx_dy"           ) -> Rebin(2);     
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_vtx_dy"         ) ); hcoll->Find( "MuMetal_Pa234m_h_vtx_dy"         ) -> Rebin(2);     	
	e_vtx_dy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_vtx_dy"         ) ); hcoll->Find( "Cd116_2b2n_m4_h_vtx_dy"         ) -> Rebin(2);	

	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_vtx_dz"            ) ); hcoll->Find( "Cd116_Tl208_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_vtx_dz"            ) ); hcoll->Find( "Cd116_Ac228_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_vtx_dz"            ) ); hcoll->Find( "Cd116_Bi212_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_vtx_dz"            ) ); hcoll->Find( "Cd116_Bi214_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_vtx_dz"         ) ); hcoll->Find( "Cd116_Pb214_VT_h_vtx_dz"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_vtx_dz"            ) ); hcoll->Find( "Mylar_Bi214_h_vtx_dz"            ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_vtx_dz"            ) ); hcoll->Find( "Mylar_Pb214_h_vtx_dz"            ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_vtx_dz_P1_cold"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dz_P1_cold"      ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_cold"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_cold"   ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_cold"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_cold"    ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_vtx_dz_P1_warm"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dz_P1_warm"      ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_warm"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dz_P1_warm"   ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_warm"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dz_P1_warm"    ) -> Rebin(2);
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dz_P1"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dz_P2"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_vtx_dz"            ) ); hcoll->Find( "SScin_Bi210_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_vtx_dz"            ) ); hcoll->Find( "SScin_Bi214_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_vtx_dz"            ) ); hcoll->Find( "SScin_Pb214_h_vtx_dz"            ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dz_P1"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dz_P1"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dz_P1"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dz_P1"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dz_P1"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dz_P1"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dz_P2"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dz_P2"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dz_P2"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dz_P2"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dz_P2"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dz_P2"         ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_vtx_dz"         ) ); hcoll->Find( "FeShield_Bi214_h_vtx_dz"         ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_vtx_dz"         ) ); hcoll->Find( "FeShield_Tl208_h_vtx_dz"         ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_vtx_dz"         ) ); hcoll->Find( "FeShield_Ac228_h_vtx_dz"         ) -> Rebin(2);      		
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_vtx_dz"           ) ); hcoll->Find( "CuTower_Co60_h_vtx_dz"           ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_vtx_dz_P1"           ) ); hcoll->Find( "Air_Bi214_h_vtx_dz_P1"           ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_vtx_dz_P1"           ) ); hcoll->Find( "Air_Pb214_h_vtx_dz_P1"           ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_vtx_dz_P1"           ) ); hcoll->Find( "Air_Tl208_h_vtx_dz_P1"           ) -> Rebin(2);   
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_vtx_dz"              ) ); hcoll->Find( "PMT_Bi214_h_vtx_dz"              ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_vtx_dz"              ) ); hcoll->Find( "PMT_Tl208_h_vtx_dz"              ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_vtx_dz"              ) ); hcoll->Find( "PMT_Ac228_h_vtx_dz"              ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_vtx_dz"                ) ); hcoll->Find( "PMT_K40_h_vtx_dz"                ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_vtx_dz"           ) ); hcoll->Find( "ScintInn_K40_h_vtx_dz"           ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_vtx_dz"           ) ); hcoll->Find( "ScintOut_K40_h_vtx_dz"           ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_vtx_dz"           ) ); hcoll->Find( "ScintPet_K40_h_vtx_dz"           ) -> Rebin(2);      
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_vtx_dz"         ) ); hcoll->Find( "MuMetal_Pa234m_h_vtx_dz"         ) -> Rebin(2);      	
	e_vtx_dz -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_vtx_dz"         ) ); hcoll->Find( "Cd116_2b2n_m4_h_vtx_dz"         ) -> Rebin(2); 

	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_vtx_dr"            ) ); hcoll->Find( "Cd116_Tl208_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_vtx_dr"            ) ); hcoll->Find( "Cd116_Ac228_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_vtx_dr"            ) ); hcoll->Find( "Cd116_Bi212_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_vtx_dr"            ) ); hcoll->Find( "Cd116_Bi214_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_vtx_dr"         ) ); hcoll->Find( "Cd116_Pb214_VT_h_vtx_dr"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_vtx_dr"            ) ); hcoll->Find( "Mylar_Bi214_h_vtx_dr"            ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_vtx_dr"            ) ); hcoll->Find( "Mylar_Pb214_h_vtx_dr"            ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_vtx_dr_P1_cold"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dr_P1_cold"      ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_cold"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_cold"   ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_cold"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_cold"    ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_vtx_dr_P1_warm"      ) ); hcoll->Find( "Cd116_K40_h_vtx_dr_P1_warm"      ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_warm"   ) ); hcoll->Find( "Cd116_Pa234m_h_vtx_dr_P1_warm"   ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_warm"    ) ); hcoll->Find( "SFoil_Bi210_h_vtx_dr_P1_warm"    ) -> Rebin(2);
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dr_P1"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll->Find( "SWire_Bi210_h_vtx_dr_P2"         ) ); hcoll->Find( "SWire_Bi210_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_vtx_dr"            ) ); hcoll->Find( "SScin_Bi210_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_vtx_dr"            ) ); hcoll->Find( "SScin_Bi214_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_vtx_dr"            ) ); hcoll->Find( "SScin_Pb214_h_vtx_dr"            ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dr_P1"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dr_P1"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dr_P1"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dr_P1"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dr_P1"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dr_P1"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_vtx_dr_P2"         ) ); hcoll->Find( "SWire_Tl208_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_vtx_dr_P2"         ) ); hcoll->Find( "SWire_Bi214_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_vtx_dr_P2"         ) ); hcoll->Find( "SFoil_Bi214_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_vtx_dr_P2"         ) ); hcoll->Find( "SWire_Pb214_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_vtx_dr_P2"         ) ); hcoll->Find( "SFoil_Pb214_h_vtx_dr_P2"         ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_vtx_dr"         ) ); hcoll->Find( "FeShield_Bi214_h_vtx_dr"         ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_vtx_dr"         ) ); hcoll->Find( "FeShield_Tl208_h_vtx_dr"         ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_vtx_dr"         ) ); hcoll->Find( "FeShield_Ac228_h_vtx_dr"         ) -> Rebin(2);     		
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_vtx_dr"           ) ); hcoll->Find( "CuTower_Co60_h_vtx_dr"           ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_vtx_dr_P1"           ) ); hcoll->Find( "Air_Bi214_h_vtx_dr_P1"           ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_vtx_dr_P1"           ) ); hcoll->Find( "Air_Pb214_h_vtx_dr_P1"           ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_vtx_dr_P1"           ) ); hcoll->Find( "Air_Tl208_h_vtx_dr_P1"           ) -> Rebin(2);  
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_vtx_dr"              ) ); hcoll->Find( "PMT_Bi214_h_vtx_dr"              ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_vtx_dr"              ) ); hcoll->Find( "PMT_Tl208_h_vtx_dr"              ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_vtx_dr"              ) ); hcoll->Find( "PMT_Ac228_h_vtx_dr"              ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_vtx_dr"                ) ); hcoll->Find( "PMT_K40_h_vtx_dr"                ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_vtx_dr"           ) ); hcoll->Find( "ScintInn_K40_h_vtx_dr"           ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_vtx_dr"           ) ); hcoll->Find( "ScintOut_K40_h_vtx_dr"           ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_vtx_dr"           ) ); hcoll->Find( "ScintPet_K40_h_vtx_dr"           ) -> Rebin(2);     
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_vtx_dr"         ) ); hcoll->Find( "MuMetal_Pa234m_h_vtx_dr"         ) -> Rebin(2);     	
	e_vtx_dr -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m4"   ) , hcoll->Find( "Cd116_2b2n_m4_h_vtx_dr"         ) ); hcoll->Find( "Cd116_2b2n_m4_h_vtx_dr"         ) -> Rebin(2);

	
	tot_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  ); tot_e_energy -> SetLogScale(kTRUE);
    tot_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  );
	min_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  ); min_e_energy -> SetLogScale(kTRUE);
	min_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  );
	max_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  ); max_e_energy -> SetLogScale(kTRUE);
	max_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  );
	cosTheta     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf"  ); cosTheta -> SetLogScale(kTRUE);
	cosTheta     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_HSD.pdf" );
		
	e_vtx_dx -> SetLogScale(kTRUE); e_vtx_dx     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf" );	
	e_vtx_dy -> SetLogScale(kTRUE); e_vtx_dy     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf" );	
	e_vtx_dz -> SetLogScale(kTRUE); e_vtx_dz     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf" );	
	e_vtx_dr -> SetLogScale(kTRUE); e_vtx_dr     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf)" );	

	
	tot_e_energy->DrawDetails();
	(TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm_Details.pdf");
	
	tot_e_energy->PrintDetails();
	
	// SSD/HSD Details
	std::cout << " Obs   " << " KS Test "           << "\t" << " Chi2 Test "                                  << "\t" << " P-value "               << std::endl;
	std::cout << " Tot : " << tot_e_energy->GetKS() << "\t" << tot_e_energy->GetChi2()/tot_e_energy->GetNDF() << "\t" << tot_e_energy->GetPValue() << std::endl;
	std::cout << " Min : " << min_e_energy->GetKS() << "\t" << min_e_energy->GetChi2()/min_e_energy->GetNDF() << "\t" << min_e_energy->GetPValue() << std::endl;
	std::cout << " Max : " << max_e_energy->GetKS() << "\t" << max_e_energy->GetChi2()/max_e_energy->GetNDF() << "\t" << max_e_energy->GetPValue() << std::endl;	
	
}

