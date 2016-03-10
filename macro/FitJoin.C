{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");



	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll2e= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

	TFile * f2e = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TwoElectronIntHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f2e->Get(ds->GetName()); fdir->cd();
		hcoll2e->Load(fdir);
	}

	HistoCollection * hcoll1e= new HistoCollection("OneElectronIntHistos", "OneElectronIntHistos");

	TFile * f1e = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root");
	
	fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f1e->Get(ds->GetName()); fdir->cd();
		hcoll1e->Load(fdir);
	}

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll1e2g= new HistoCollection("OneElectronTwoGammaHistos", "OneElectronTwoGammaHistos");

	TFile * f1e2g = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronTwoGammaInt.root");
	fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f1e2g->Get(ds->GetName()); fdir->cd();
		hcoll1e2g->Load(fdir);
	}

	// Load OneElectronThreeGammaHistos in HistoCollection
	HistoCollection * hcoll1e3g= new HistoCollection("OneElectronThreeGammaHistos", "OneElectronThreeGammaHistos");

	TFile * f1e3g = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronThreeGammaInt.root");
	fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f1e3g->Get(ds->GetName()); fdir->cd();
		hcoll1e3g->Load(fdir);
	}


	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll2eExt = new HistoCollection("TwoElectronExtHistos", "TwoElectronExtHistos");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/TwoElectronExtHistos.root");
	TFile * f2eExt = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronExtHistos.root");

	fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f2eExt->Get(ds->GetName()); fdir->cd();
		hcoll2eExt->Load(fdir);
	}

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll1e1gExt = new HistoCollection("OneElectronOneGammaExt", "OneElectronOneGammaExt");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/OneElectronOneGammaExt.root");
	TFile * f1e1gExt = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronOneGammaExt.root");
	
	fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f1e1gExt->Get(ds->GetName()); fdir->cd();
		hcoll1e1gExt->Load(fdir);
	}


	bool constrain_all = true;


	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "cBB"               , "cBB"               ,  0 , 3.57e-01    , 0.0001 ) ); 
	DataManagement::AddParameter( new Parameter( "Cd116_K40_cold"    , "Cd116_K40_cold"    ,  1 , 5.29348e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_cold" , "Cd116_Pa234m_cold" ,  2 , 1.09687e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_K40_warm"    , "Cd116_K40_warm"    ,  3 , 9.73645e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_warm" , "Cd116_Pa234m_warm" ,  4 , 2.13357e-03 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_cold"  , "SFoil_Bi210_cold"  ,  5 , 1.14829e+00 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_warm"  , "SFoil_Bi210_warm"  ,  6 , 2.75597e+00 , 0.1 ) );  
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P1"   , "cSWire_Bi210_P1"   ,  7 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSWire_Bi210_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210_P2"   , "cSWire_Bi210_P2"   ,  8 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSWire_Bi210_P2"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "Cd116_Tl208"       , "Cd116_Tl208"       ,  9  , 1.36224e-04 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cCd116_Bi214"      , "cCd116_Bi214"      , 10 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMylar_Bi214"      , "cMylar_Bi214"      , 11 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cMylar_Bi214"       ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P1"   , "cSwire_Tl208_P1"   , 12 , 0. , 0.1 ) ); DataManagement::FindParameter( "cSwire_Tl208_P1"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P2"   , "cSwire_Tl208_P2"   , 13 , 0. , 0.1 ) ); DataManagement::FindParameter( "cSwire_Tl208_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P1"   , "cSwire_Bi214_P1"   , 14 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P2"   , "cSwire_Bi214_P2"   , 15 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P2"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P1"   , "cSfoil_Bi214_P1"   , 16 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P1"    ) -> SetFix();	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P2"   , "cSfoil_Bi214_P2"   , 17 , 1. , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P2"    ) -> SetFix();	

	DataManagement::AddParameter( new Parameter( "PMT_K40"         , "PMT_K40"             , 18 , 1.30000e+03 , 0.1 ) ); //DataManagement::FindParameter( "PMT_K40"       ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Scint_K40"       , "Scint_K40"           , 19 , 6.19355e+00 , 0.1 ) ); //DataManagement::FindParameter( "Scint_K40"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"       , "PMT_Bi214"           , 20 , 2.68820e+02 , 0.1 ) ); //DataManagement::FindParameter( "PMT_Bi214"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1"    , "Air_Bi214_P1"        , 21 , 5.99548e+02 , 0.1 ) ); //DataManagement::FindParameter( "Air_Bi214_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"       , "PMT_Tl208"           , 22 , 4.53709e+01 , 0.1 ) ); //DataManagement::FindParameter( "PMT_Tl208"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1"    , "Air_Tl208_P1"        , 23 , 1.39872e+01 , 0.1 ) ); //DataManagement::FindParameter( "Air_Tl208_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"     , "SScin_Bi210"         , 24 , 3.49389e+01 , 0.1 ) ); //DataManagement::FindParameter( "SScin_Bi210"   ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi214"     , "SScin_Bi214"         , 25 , 2.51318e-01 , 0.1 ) ); //DataManagement::FindParameter( "SScin_Bi214"   ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "CuTower_Co60"    , "CuTower_Co60"        , 26 , 6.18692e+01 , 0.1 ) ); //DataManagement::FindParameter( "Co60"          ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "FeShield_Bi214"  , "FeShield_Bi214"      , 27 , 1.03004e+04 , 0.1 ) ); //DataManagement::FindParameter( "FeShield_Bi214") -> SetFix();
	DataManagement::AddParameter( new Parameter( "MuMetal_Pa234m"    , "MuMetal_Pa234m"    , 28 , 2.65319e+03 , 0.1 ) ); //DataManagement::FindParameter( "MuMetal_Pa234m") -> SetFix();
	DataManagement::AddParameter( new Parameter( "FeShield_Tl208"  , "FeShield_Tl208"      , 29 , 484 , 0.1 )); //DataManagement::FindParameter( "FeShield_Tl208") -> SetFix();



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
	DataManagement::AddComponent( new Component( "Cd116_Tl208"     , "^{208}Tl Cd116"    , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "Cd116_Tl208"     ) , 1. )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228"     , "^{228}Ac Cd116"    , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "Cd116_Tl208"     ) , 0.440/0.3594 , 0.440/0.3594 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"     , "^{212}Bi Cd116"    , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "Cd116_Tl208"     ) , 0.440/0.3594 , 0.440/0.3594 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Tl208_P1"  , "^{208}Tl SWire P1" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P1" ) , 3.5E-03      , 0.4E-03      )); DataManagement::FindComponent( "SWire_Tl208_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Tl208_P2"  , "^{208}Tl SWire P2" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P2" ) , 2.9E-03      , 0.4E-03      )); DataManagement::FindComponent( "SWire_Tl208_P2"  )->SetFillColor( kAzure + 2 );

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
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_cold"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_warm"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_cold" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_warm" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	// Zac activities
	//DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0034 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , 0.0084 , 0.0001 )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0004 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	//DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , 0.0010 , 0.0001 )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		

	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) );
	DataManagement::FindGroup("K40")->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) );
	DataManagement::FindGroup("Pa234m")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) );

	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "SFoil_Bi210_cold" ) ,  1. )); DataManagement::FindComponent( "SFoil_Bi210_cold" ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210" ) , DataManagement::FindParameter( "SFoil_Bi210_warm" ) ,  1. )); DataManagement::FindComponent( "SFoil_Bi210_warm" ) -> SetFillColor( kGreen + 2 );	
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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "FeShield_Bi214" ) , 1.                    )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 11 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield  ^{208}Tl " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1.                    )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield  ^{228}Ac " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "FeShield_Tl208" ) , 1./0.3594   , 1/0.3594)); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "CuTower_Co60"   ) , 1.                    )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange +  9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.                    )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) , 1.                    )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) , 1.                    )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) , 1.                    )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1.                    )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) , 1./0.3594 , 1/0.3594  )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) , 1.                    )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) , 1.                    )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) , 1.                    )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) , 1.                    )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) , 1.                    )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"    , "^{214}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "SScin_Bi214"    ) , 1.                    )); DataManagement::FindComponent( "SScin_Bi214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"    , "^{214}Pb SScin     " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "SScin_Bi214"    ) , 1.                    )); DataManagement::FindComponent( "SScin_Pb214"    )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "MuMetal_Pa234m" , "Mu Metal ^{234m}Pa " , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , DataManagement::FindParameter( "MuMetal_Pa234m" ) , 1.                    )); DataManagement::FindComponent( "MuMetal_Pa234m" )->SetFillColor( kOrange +  5 );

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
	Observable * tot_e_energy_P1_cold  = new Observable("tot_e_energy_P1_cold" , "2e - E_{e1} + E_{e2} - Phase 1 cold" , kPhaseOne , hcoll2e->Find( "Data_h_tot_e_energy_P1_cold" ) ); tot_e_energy_P1_cold -> SetLogScale(kFALSE); tot_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_cold -> SetDrawGroup(kTRUE); //tot_e_energy_P1_cold -> SetFitRangeLowEdge(0.5);
	Observable * min_e_energy_P1_cold  = new Observable("min_e_energy_P1_cold" , "2e - E_{e,min} - Phase 1 cold"       , kPhaseOne , hcoll2e->Find( "Data_h_min_e_energy_P1_cold" ) ); min_e_energy_P1_cold -> SetLogScale(kFALSE); min_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_cold -> SetDrawGroup(kTRUE); 
	Observable * max_e_energy_P1_cold  = new Observable("max_e_energy_P1_cold" , "2e - E_{e,max} - Phase 1 cold"       , kPhaseOne , hcoll2e->Find( "Data_h_max_e_energy_P1_cold" ) ); max_e_energy_P1_cold -> SetLogScale(kFALSE); max_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_cold -> SetDrawGroup(kTRUE); 
	Observable * cosTheta_P1_cold      = new Observable("cosTheta_P1_cold"     , "2e - Cos(#Theta) - Phase 1 cold"     , kPhaseOne , hcoll2e->Find( "Data_h_cosTheta_P1_cold"     ) ); cosTheta_P1_cold     -> SetLogScale(kFALSE); cosTheta_P1_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_cold     -> SetDrawGroup(kTRUE); 
	hcoll2e->Find( "Data_h_cosTheta_P1_cold" ) ->GetYaxis()->SetRangeUser(0.5,500);

	Observable * tot_e_energy_P1_warm  = new Observable("tot_e_energy_P1_warm" , "2e - E_{e1} + E_{e2} - Phase 1 warm" , kPhaseOne , hcoll2e->Find( "Data_h_tot_e_energy_P1_warm" ) ); tot_e_energy_P1_warm -> SetLogScale(kFALSE); tot_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_warm -> SetDrawGroup(kTRUE); //tot_e_energy_P1_warm -> SetFitRangeLowEdge(0.5);
	Observable * min_e_energy_P1_warm  = new Observable("min_e_energy_P1_warm" , "2e - E_{e,min} - Phase 1 warm"       , kPhaseOne , hcoll2e->Find( "Data_h_min_e_energy_P1_warm" ) ); min_e_energy_P1_warm -> SetLogScale(kFALSE); min_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_warm -> SetDrawGroup(kTRUE); 
	Observable * max_e_energy_P1_warm  = new Observable("max_e_energy_P1_warm" , "2e - E_{e,max} - Phase 1 warm"       , kPhaseOne , hcoll2e->Find( "Data_h_max_e_energy_P1_warm" ) ); max_e_energy_P1_warm -> SetLogScale(kFALSE); max_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_warm -> SetDrawGroup(kTRUE); 
	Observable * cosTheta_P1_warm      = new Observable("cosTheta_P1_warm"     , "2e - Cos(#Theta) - Phase 1 warm"     , kPhaseOne , hcoll2e->Find( "Data_h_cosTheta_P1_warm"     ) ); cosTheta_P1_warm     -> SetLogScale(kFALSE); cosTheta_P1_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_warm     -> SetDrawGroup(kTRUE); 
	hcoll2e->Find( "Data_h_cosTheta_P1_warm" ) ->GetYaxis()->SetRangeUser(0.5,500);
	
	Observable * tot_e_energy_P2_cold  = new Observable("tot_e_energy_P2_cold" , "2e - E_{e1} + E_{e2} - Phase 2 cold" , kPhaseTwo , hcoll2e->Find( "Data_h_tot_e_energy_P2_cold" ) ); tot_e_energy_P2_cold -> SetLogScale(kFALSE); tot_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_cold -> SetDrawGroup(kTRUE); //tot_e_energy_P2_cold -> SetFitRangeLowEdge(0.5);
	Observable * min_e_energy_P2_cold  = new Observable("min_e_energy_P2_cold" , "2e - E_{e,min} - Phase 2 cold"       , kPhaseTwo , hcoll2e->Find( "Data_h_min_e_energy_P2_cold" ) ); min_e_energy_P2_cold -> SetLogScale(kFALSE); min_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_cold -> SetDrawGroup(kTRUE); 
	Observable * max_e_energy_P2_cold  = new Observable("max_e_energy_P2_cold" , "2e - E_{e,max} - Phase 2 cold"       , kPhaseTwo , hcoll2e->Find( "Data_h_max_e_energy_P2_cold" ) ); max_e_energy_P2_cold -> SetLogScale(kFALSE); max_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_cold -> SetDrawGroup(kTRUE); 
	Observable * cosTheta_P2_cold      = new Observable("cosTheta_P2_cold"     , "2e - Cos(#Theta) - Phase 2 cold"     , kPhaseTwo , hcoll2e->Find( "Data_h_cosTheta_P2_cold"     ) ); cosTheta_P2_cold     -> SetLogScale(kFALSE); cosTheta_P2_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_cold     -> SetDrawGroup(kTRUE); 
	hcoll2e->Find( "Data_h_cosTheta_P2_cold" ) ->GetYaxis()->SetRangeUser(0.5,500);

	Observable * tot_e_energy_P2_warm  = new Observable("tot_e_energy_P2_warm" , "2e - E_{e1} + E_{e2} - Phase 2 warm" , kPhaseTwo , hcoll2e->Find( "Data_h_tot_e_energy_P2_warm" ) ); tot_e_energy_P2_warm -> SetLogScale(kFALSE); tot_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_warm -> SetDrawGroup(kTRUE); //tot_e_energy_P2_warm -> SetFitRangeLowEdge(0.5);
	Observable * min_e_energy_P2_warm  = new Observable("min_e_energy_P2_warm" , "2e - E_{e,min} - Phase 2 warm"       , kPhaseTwo , hcoll2e->Find( "Data_h_min_e_energy_P2_warm" ) ); min_e_energy_P2_warm -> SetLogScale(kFALSE); min_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_warm -> SetDrawGroup(kTRUE); 
	Observable * max_e_energy_P2_warm  = new Observable("max_e_energy_P2_warm" , "2e - E_{e,max} - Phase 2 warm"       , kPhaseTwo , hcoll2e->Find( "Data_h_max_e_energy_P2_warm" ) ); max_e_energy_P2_warm -> SetLogScale(kFALSE); max_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_warm -> SetDrawGroup(kTRUE); 
	Observable * cosTheta_P2_warm      = new Observable("cosTheta_P2_warm"     , "2e - Cos(#Theta) - Phase 2 warm"     , kPhaseTwo , hcoll2e->Find( "Data_h_cosTheta_P2_warm"     ) ); cosTheta_P2_warm     -> SetLogScale(kFALSE); cosTheta_P2_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_warm     -> SetDrawGroup(kTRUE); 
	hcoll2e->Find( "Data_h_cosTheta_P2_warm" ) ->GetYaxis()->SetRangeUser(0.5,500);

	// 1e
	Observable * e_energy_P1_cold = new Observable("e_energy_P1_cold" , "E_{e} - Phase 1 Cold" , kPhaseOne , hcoll1e->Find( "Data_h_e_energy_P1_cold" ) ); e_energy_P1_cold -> SetLogScale(kFALSE); e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_cold -> SetDrawGroup(kTRUE); //e_energy_P1_cold -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P2_cold = new Observable("e_energy_P2_cold" , "E_{e} - Phase 2 Cold" , kPhaseTwo , hcoll1e->Find( "Data_h_e_energy_P2_cold" ) ); e_energy_P2_cold -> SetLogScale(kFALSE); e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_cold -> SetDrawGroup(kTRUE); //e_energy_P2_cold -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P1_warm = new Observable("e_energy_P1_warm" , "E_{e} - Phase 1 Warm" , kPhaseOne , hcoll1e->Find( "Data_h_e_energy_P1_warm" ) ); e_energy_P1_warm -> SetLogScale(kFALSE); e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_warm -> SetDrawGroup(kTRUE); //e_energy_P1_warm -> SetFitRangeLowEdge(1.5);
	Observable * e_energy_P2_warm = new Observable("e_energy_P2_warm" , "E_{e} - Phase 2 Warm" , kPhaseTwo , hcoll1e->Find( "Data_h_e_energy_P2_warm" ) ); e_energy_P2_warm -> SetLogScale(kFALSE); e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_warm -> SetDrawGroup(kTRUE); //e_energy_P2_warm -> SetFitRangeLowEdge(1.5);

	// 1e2g
	Observable * energy_score_fun_P1 = new Observable("energy_score_fun_P1 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 1 " , kPhaseOne , hcoll1e2g->Find( "Data_h_energy_score_fun_P1" ) ); energy_score_fun_P1 -> SetLogScale(kFALSE); energy_score_fun_P1 -> AddGroupAll(DataManagement::GetGroupCollection()); energy_score_fun_P1 -> SetDrawGroup(kTRUE); //energy_score_fun_P1 -> SetFitRangeLowEdge(-1);

	Observable * energy_score_fun_P2 = new Observable("energy_score_fun_P2 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 2 " , kPhaseTwo , hcoll1e2g->Find( "Data_h_energy_score_fun_P2" ) ); energy_score_fun_P2 -> SetLogScale(kFALSE); energy_score_fun_P2 -> AddGroupAll(DataManagement::GetGroupCollection()); energy_score_fun_P2 -> SetDrawGroup(kTRUE); //energy_score_fun_P2 -> SetFitRangeLowEdge(-1);
	
	// 1e3g
	Observable * tot_energy_3g       = new Observable("tot_energy_g3"        , "1e3g - E_{e} + E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} - Phase 1 & 2" , kAll      , hcoll1e3g->Find( "Data_h_tot_energy"       ) ); tot_energy_3g       -> SetLogScale(kFALSE); tot_energy_3g       -> AddGroupAll(DataManagement::GetGroupCollection()); tot_energy_3g       -> SetDrawGroup(kTRUE); 

	// Externals
	Observable * tot_ext_e_energy_P1   = new Observable("tot_ext_e_energy_P1"   , "2e ext - total electron energy - Phase 1 "           , kPhaseOne , hcoll2eExt   -> Find( "Data_h_tot_e_energy_P1" ) ); tot_ext_e_energy_P1   -> SetLogScale(kFALSE);
	Observable * tot_ext_e_energy_P2   = new Observable("tot_ext_e_energy_P2"   , "2e ext - total electron energy - Phase 2 "           , kPhaseTwo , hcoll2eExt   -> Find( "Data_h_tot_e_energy_P2" ) ); tot_ext_e_energy_P2   -> SetLogScale(kFALSE);	
	Observable * tot_ext_e_g_energy_P1 = new Observable("tot_ext_e_g_energy_P1" , "1e1g ext - total electron + gamma energy - Phase 1 " , kPhaseOne , hcoll1e1gExt -> Find( "Data_h_tot_energy_P1"   ) ); tot_ext_e_g_energy_P1 -> SetLogScale(kFALSE);
	Observable * tot_ext_e_g_energy_P2 = new Observable("tot_ext_e_g_energy_P2" , "1e1g ext - total electron + gamma energy - Phase 2 " , kPhaseTwo , hcoll1e1gExt -> Find( "Data_h_tot_energy_P2"   ) ); tot_ext_e_g_energy_P2 -> SetLogScale(kFALSE);	


	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	// P1 Cold
	{
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_cold" ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_tot_e_energy_P1_cold"    ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_tot_e_energy_P1_cold"    ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_tot_e_energy_P1_cold"    ) );   		
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P1_cold"    ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_tot_e_energy_P1_cold" ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_tot_e_energy_P1_cold" ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_tot_e_energy_P1_cold" ) );      		
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_tot_e_energy_P1_cold"      ) );   
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_tot_e_energy_P1_cold"      ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_tot_e_energy_P1_cold"        ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_tot_e_energy_P1_cold"   ) );      
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_tot_e_energy_P1_cold"   ) );
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_tot_e_energy_P1_cold" ) );            
		tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_cold" ) );      
    	
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_cold" ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_min_e_energy_P1_cold"    ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_min_e_energy_P1_cold"    ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_min_e_energy_P1_cold"    ) );   		
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P1_cold"    ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_min_e_energy_P1_cold" ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_min_e_energy_P1_cold" ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_min_e_energy_P1_cold" ) );      		
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_min_e_energy_P1_cold"      ) );   
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_min_e_energy_P1_cold"      ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_min_e_energy_P1_cold"        ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_min_e_energy_P1_cold"   ) );      
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_min_e_energy_P1_cold"   ) );
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_min_e_energy_P1_cold" ) );            
		min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_cold" ) );      
    	
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_cold" ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_max_e_energy_P1_cold"    ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_max_e_energy_P1_cold"    ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_max_e_energy_P1_cold"    ) );   		
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P1_cold"    ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_max_e_energy_P1_cold" ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_max_e_energy_P1_cold" ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_max_e_energy_P1_cold" ) );      		
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_max_e_energy_P1_cold"      ) );   
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_max_e_energy_P1_cold"      ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_max_e_energy_P1_cold"        ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_max_e_energy_P1_cold"   ) );      
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_max_e_energy_P1_cold"   ) );
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_max_e_energy_P1_cold" ) );            
		max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_cold" ) );      
	
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_cosTheta_P1_cold" ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_cosTheta_P1_cold"    ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_cosTheta_P1_cold"    ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_cosTheta_P1_cold"    ) );   		
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P1_cold"    ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_cosTheta_P1_cold" ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_cosTheta_P1_cold" ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_cosTheta_P1_cold" ) );      		
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_cosTheta_P1_cold"      ) );   
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_cosTheta_P1_cold"      ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_cosTheta_P1_cold"        ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_cosTheta_P1_cold"   ) );      
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_cosTheta_P1_cold"   ) );
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_cosTheta_P1_cold" ) );            
		cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_cosTheta_P1_cold" ) );
		
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e->Find( "Cd116_Tl208_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e->Find( "Cd116_Ac228_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e->Find( "Cd116_Bi212_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll1e->Find( "Cd116_Bi214_h_e_energy_P1_cold"	    ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll1e->Find( "Cd116_Pb214_VT_h_e_energy_P1_cold"  ));	
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e->Find( "Mylar_Bi214_h_e_energy_P1_cold"     ));	
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e->Find( "Mylar_Pb214_h_e_energy_P1_cold"     ));	
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll1e->Find( "SWire_Tl208_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll1e->Find( "SWire_Bi214_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll1e->Find( "SFoil_Bi214_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll1e->Find( "SWire_Pb214_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll1e->Find( "SFoil_Pb214_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e->Find( "FeShield_Bi214_h_e_energy_P1_cold"  ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e->Find( "FeShield_Tl208_h_e_energy_P1_cold"  ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e->Find( "FeShield_Ac228_h_e_energy_P1_cold"  ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll1e->Find( "PMT_K40_h_e_energy_P1_cold"         ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e->Find( "ScintOut_K40_h_e_energy_P1_cold"    ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e->Find( "ScintPet_K40_h_e_energy_P1_cold"    ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e->Find( "ScintInn_K40_h_e_energy_P1_cold"    ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll1e->Find( "PMT_Bi214_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll1e->Find( "Air_Bi214_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll1e->Find( "Air_Pb214_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e->Find( "PMT_Tl208_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e->Find( "PMT_Ac228_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll1e->Find( "Air_Tl208_h_e_energy_P1_cold"       ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e->Find( "CuTower_Co60_h_e_energy_P1_cold"    ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll1e->Find( "Cd116_2b2n_m4_h_e_energy_P1_cold"   ));	
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e->Find( "SScin_Bi210_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e->Find( "SScin_Bi214_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e->Find( "SScin_Pb214_h_e_energy_P1_cold"     ));
	    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e->Find( "MuMetal_Pa234m_h_e_energy_P1_cold"  ));	
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll1e->Find( "SWire_Bi210_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll1e->Find( "SFoil_Bi210_h_e_energy_P1_cold"     ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll1e->Find( "Cd116_K40_h_e_energy_P1_cold"       ));
		e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll1e->Find( "Cd116_Pa234m_h_e_energy_P1_cold"    ));
		      
	}
	// P1 Warm
	{
		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_warm" ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_tot_e_energy_P1_warm"    ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_tot_e_energy_P1_warm"    ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) );
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_tot_e_energy_P1_warm"    ) );   		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P1_warm"    ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_tot_e_energy_P1_warm" ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_tot_e_energy_P1_warm" ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_tot_e_energy_P1_warm" ) );      				
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_tot_e_energy_P1_warm"      ) );   
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_tot_e_energy_P1_warm"      ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_tot_e_energy_P1_warm"        ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_tot_e_energy_P1_warm"   ) );      
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_tot_e_energy_P1_warm"   ) );      		
		tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_warm" ) );      

		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_warm" ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_min_e_energy_P1_warm"    ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_min_e_energy_P1_warm"    ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) );
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_min_e_energy_P1_warm"    ) );   		
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P1_warm"    ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_min_e_energy_P1_warm" ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_min_e_energy_P1_warm" ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_min_e_energy_P1_warm" ) );      				
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_min_e_energy_P1_warm"      ) );   
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_min_e_energy_P1_warm"      ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_min_e_energy_P1_warm"        ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_min_e_energy_P1_warm"   ) );      
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_min_e_energy_P1_warm"   ) );      		
		min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_warm" ) );      

		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_warm" ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_max_e_energy_P1_warm"    ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_max_e_energy_P1_warm"    ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) );
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_max_e_energy_P1_warm"    ) );   		
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P1_warm"    ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_max_e_energy_P1_warm" ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_max_e_energy_P1_warm" ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_max_e_energy_P1_warm" ) );      				
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_max_e_energy_P1_warm"      ) );   
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_max_e_energy_P1_warm"      ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_max_e_energy_P1_warm"        ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_max_e_energy_P1_warm"   ) );      
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_max_e_energy_P1_warm"   ) );      		
		max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_warm" ) );      
	
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_cosTheta_P1_warm" ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_cosTheta_P1_warm"    ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_cosTheta_P1_warm"    ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) );
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_cosTheta_P1_warm"    ) );   		
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P1_warm"    ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_cosTheta_P1_warm" ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_cosTheta_P1_warm" ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_cosTheta_P1_warm" ) );      				
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_cosTheta_P1_warm"      ) );   
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_cosTheta_P1_warm"      ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_cosTheta_P1_warm"        ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_cosTheta_P1_warm"   ) );      
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_cosTheta_P1_warm"   ) );      		
		cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_cosTheta_P1_warm" ) );      
	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e->Find( "Cd116_Tl208_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e->Find( "Cd116_Ac228_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e->Find( "Cd116_Bi212_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll1e->Find( "Cd116_Bi214_h_e_energy_P1_warm"	  ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll1e->Find( "Cd116_Pb214_VT_h_e_energy_P1_warm"  ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e->Find( "Mylar_Bi214_h_e_energy_P1_warm"     ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e->Find( "Mylar_Pb214_h_e_energy_P1_warm"     ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll1e->Find( "SWire_Tl208_h_e_energy_P1_warm"     ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll1e->Find( "SWire_Bi214_h_e_energy_P1_warm"     ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll1e->Find( "SFoil_Bi214_h_e_energy_P1_warm"     ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll1e->Find( "SWire_Pb214_h_e_energy_P1_warm"     ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll1e->Find( "SFoil_Pb214_h_e_energy_P1_warm"     ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e->Find( "FeShield_Bi214_h_e_energy_P1_warm"  ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e->Find( "FeShield_Tl208_h_e_energy_P1_warm"  ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e->Find( "FeShield_Ac228_h_e_energy_P1_warm"  ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll1e->Find( "PMT_K40_h_e_energy_P1_warm"         ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e->Find( "ScintOut_K40_h_e_energy_P1_warm"    ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e->Find( "ScintPet_K40_h_e_energy_P1_warm"    ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e->Find( "ScintInn_K40_h_e_energy_P1_warm"    ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll1e->Find( "PMT_Bi214_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll1e->Find( "Air_Bi214_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll1e->Find( "Air_Pb214_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e->Find( "PMT_Tl208_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e->Find( "PMT_Ac228_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll1e->Find( "Air_Tl208_h_e_energy_P1_warm"       ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e->Find( "CuTower_Co60_h_e_energy_P1_warm"    ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll1e->Find( "Cd116_2b2n_m4_h_e_energy_P1_warm"   ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll1e->Find( "Cd116_K40_h_e_energy_P1_warm"       ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll1e->Find( "Cd116_Pa234m_h_e_energy_P1_warm"    ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e->Find( "SScin_Bi210_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e->Find( "SScin_Bi214_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e->Find( "SScin_Pb214_h_e_energy_P1_warm"     ));
	    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e->Find( "MuMetal_Pa234m_h_e_energy_P1_warm"     ));	
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll1e->Find( "SWire_Bi210_h_e_energy_P1_warm"     ));
		e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll1e->Find( "SFoil_Bi210_h_e_energy_P1_warm"     ));
		
	}
	// P2 Cold
	{
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_cold" ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_tot_e_energy_P2_cold"    ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_tot_e_energy_P2_cold"    ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P2_cold"      ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P2_cold"   ) );
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_tot_e_energy_P2_cold"    ) );   		
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P2_cold"    ) );   
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_tot_e_energy_P2_cold" ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_tot_e_energy_P2_cold" ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_tot_e_energy_P2_cold" ) );      				
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_tot_e_energy_P2_cold"      ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_tot_e_energy_P2_cold"        ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_tot_e_energy_P2_cold"   ) );      
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_tot_e_energy_P2_cold"   ) );      		
		tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_cold" ) );      

		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_cold" ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_min_e_energy_P2_cold"    ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_min_e_energy_P2_cold"    ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P2_cold"      ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P2_cold"   ) );
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_min_e_energy_P2_cold"    ) );   		
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P2_cold"    ) );   
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_min_e_energy_P2_cold" ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_min_e_energy_P2_cold" ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_min_e_energy_P2_cold" ) );      				
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_min_e_energy_P2_cold"      ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_min_e_energy_P2_cold"        ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_min_e_energy_P2_cold"   ) );      
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_min_e_energy_P2_cold"   ) );      		
		min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_cold" ) );      

		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_cold" ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_max_e_energy_P2_cold"    ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_max_e_energy_P2_cold"    ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P2_cold"      ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P2_cold"   ) );
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_max_e_energy_P2_cold"    ) );   		
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P2_cold"    ) );   
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_max_e_energy_P2_cold" ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_max_e_energy_P2_cold" ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_max_e_energy_P2_cold" ) );      				
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_max_e_energy_P2_cold"      ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_max_e_energy_P2_cold"        ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_max_e_energy_P2_cold"   ) );      
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_max_e_energy_P2_cold"   ) );      		
		max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_cold" ) );      
		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_cosTheta_P2_cold" ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_cosTheta_P2_cold"    ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_cosTheta_P2_cold"    ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P2_cold"      ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P2_cold"   ) );
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_cosTheta_P2_cold"    ) );   		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P2_cold"    ) );   
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_cosTheta_P2_cold" ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_cosTheta_P2_cold" ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_cosTheta_P2_cold" ) );      				
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_cosTheta_P2_cold"      ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_cosTheta_P2_cold"        ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_cosTheta_P2_cold"   ) );      
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_cosTheta_P2_cold"   ) );      		
		cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_cosTheta_P2_cold" ) );      
		
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e->Find( "Cd116_Tl208_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e->Find( "Cd116_Ac228_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e->Find( "Cd116_Bi212_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll1e->Find( "Cd116_Bi214_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll1e->Find( "Cd116_Pb214_VT_h_e_energy_P2_cold"  ));	
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e->Find( "Mylar_Bi214_h_e_energy_P2_cold"     ));	
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e->Find( "Mylar_Pb214_h_e_energy_P2_cold"     ));	
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll1e->Find( "SWire_Tl208_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll1e->Find( "SWire_Bi214_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll1e->Find( "SFoil_Bi214_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll1e->Find( "SWire_Pb214_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll1e->Find( "SFoil_Pb214_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e->Find( "FeShield_Bi214_h_e_energy_P2_cold"  ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e->Find( "FeShield_Tl208_h_e_energy_P2_cold"  ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e->Find( "FeShield_Ac228_h_e_energy_P2_cold"  ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll1e->Find( "PMT_K40_h_e_energy_P2_cold"   	  ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e->Find( "ScintOut_K40_h_e_energy_P2_cold"    ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e->Find( "ScintPet_K40_h_e_energy_P2_cold"    ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e->Find( "ScintInn_K40_h_e_energy_P2_cold"    ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll1e->Find( "PMT_Bi214_h_e_energy_P2_cold"       ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e->Find( "PMT_Tl208_h_e_energy_P2_cold"       ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e->Find( "PMT_Ac228_h_e_energy_P2_cold"       ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e->Find( "CuTower_Co60_h_e_energy_P2_cold"    ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll1e->Find( "Cd116_2b2n_m4_h_e_energy_P2_cold"   ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll1e->Find( "Cd116_K40_h_e_energy_P2_cold"       ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll1e->Find( "Cd116_Pa234m_h_e_energy_P2_cold"    ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e->Find( "SScin_Bi210_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e->Find( "SScin_Bi214_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e->Find( "SScin_Pb214_h_e_energy_P2_cold"     ));
	    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e->Find( "MuMetal_Pa234m_h_e_energy_P2_cold"  ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll1e->Find( "SWire_Bi210_h_e_energy_P2_cold"     ));
		e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll1e->Find( "SFoil_Bi210_h_e_energy_P2_cold"     ));
		
	}
	// P2 Warm
	{
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_warm" ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_tot_e_energy_P2_warm"    ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_tot_e_energy_P2_warm"    ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P2_warm"      ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P2_warm"   ) );
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_tot_e_energy_P2_warm"    ) );   		
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P2_warm"    ) );   
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_tot_e_energy_P2_warm" ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_tot_e_energy_P2_warm" ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_tot_e_energy_P2_warm" ) );      				
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_tot_e_energy_P2_warm"      ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_tot_e_energy_P2_warm"        ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_tot_e_energy_P2_warm"   ) );      
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_tot_e_energy_P2_warm"   ) );      		
		tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_warm" ) );      

		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_warm" ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_max_e_energy_P2_warm"    ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_max_e_energy_P2_warm"    ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P2_warm"      ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P2_warm"   ) );
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_max_e_energy_P2_warm"    ) );   		
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P2_warm"    ) );   
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_max_e_energy_P2_warm" ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_max_e_energy_P2_warm" ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_max_e_energy_P2_warm" ) );      				
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_max_e_energy_P2_warm"      ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_max_e_energy_P2_warm"        ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_max_e_energy_P2_warm"   ) );      
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_max_e_energy_P2_warm"   ) );      		
		max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_warm" ) );      

		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_warm" ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_min_e_energy_P2_warm"    ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_min_e_energy_P2_warm"    ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P2_warm"      ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P2_warm"   ) );
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_min_e_energy_P2_warm"    ) );   		
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P2_warm"    ) );   
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_min_e_energy_P2_warm" ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_min_e_energy_P2_warm" ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_min_e_energy_P2_warm" ) );      				
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_min_e_energy_P2_warm"      ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_min_e_energy_P2_warm"        ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_min_e_energy_P2_warm"   ) );      
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_min_e_energy_P2_warm"   ) );      		
		min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_warm" ) );      

		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_cosTheta_P2_warm" ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_cosTheta_P2_warm"    ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_cosTheta_P2_warm"    ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P2_warm"      ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P2_warm"   ) );
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_cosTheta_P2_warm"    ) );   		
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P2_warm"    ) );   
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_cosTheta_P2_warm" ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_cosTheta_P2_warm" ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_cosTheta_P2_warm" ) );      				
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_cosTheta_P2_warm"      ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_cosTheta_P2_warm"        ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_cosTheta_P2_warm"   ) );      
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_cosTheta_P2_warm"   ) );      		
		cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_cosTheta_P2_warm" ) ); 
		
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e->Find( "Cd116_Tl208_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e->Find( "Cd116_Ac228_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e->Find( "Cd116_Bi212_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll1e->Find( "Cd116_Bi214_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll1e->Find( "Cd116_Pb214_VT_h_e_energy_P2_warm"  ));	
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e->Find( "Mylar_Bi214_h_e_energy_P2_warm"     ));	
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e->Find( "Mylar_Pb214_h_e_energy_P2_warm"     ));	
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll1e->Find( "SWire_Tl208_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll1e->Find( "SWire_Bi214_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll1e->Find( "SFoil_Bi214_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll1e->Find( "SWire_Pb214_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll1e->Find( "SFoil_Pb214_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e->Find( "FeShield_Bi214_h_e_energy_P2_warm"  ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e->Find( "FeShield_Tl208_h_e_energy_P2_warm"  ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e->Find( "FeShield_Ac228_h_e_energy_P2_warm"  ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll1e->Find( "PMT_K40_h_e_energy_P2_warm"   	  ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e->Find( "ScintOut_K40_h_e_energy_P2_warm"    ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e->Find( "ScintPet_K40_h_e_energy_P2_warm"    ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e->Find( "ScintInn_K40_h_e_energy_P2_warm"    ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	      ) , hcoll1e->Find( "PMT_Bi214_h_e_energy_P2_warm"       ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e->Find( "PMT_Tl208_h_e_energy_P2_warm"       ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e->Find( "PMT_Ac228_h_e_energy_P2_warm"       ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e->Find( "CuTower_Co60_h_e_energy_P2_warm"    ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll1e->Find( "Cd116_2b2n_m4_h_e_energy_P2_warm"   ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"     ) , hcoll1e->Find( "Cd116_K40_h_e_energy_P2_warm"       ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm"  ) , hcoll1e->Find( "Cd116_Pa234m_h_e_energy_P2_warm"    ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e->Find( "SScin_Bi210_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e->Find( "SScin_Bi214_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e->Find( "SScin_Pb214_h_e_energy_P2_warm"     ));
	    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e->Find( "MuMetal_Pa234m_h_e_energy_P2_warm"     ));	
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll1e->Find( "SWire_Bi210_h_e_energy_P2_warm"     ));
		e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll1e->Find( "SFoil_Bi210_h_e_energy_P2_warm"     ));	
		     
	}
	// 1e2g & 1e3g
	{
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e2g->Find( "Cd116_Tl208_h_energy_score_fun_P1"     ));
	    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e2g->Find( "Cd116_Ac228_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e2g->Find( "Cd116_Bi212_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll1e2g->Find( "Cd116_Bi214_h_energy_score_fun_P1"	  ));
	    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll1e2g->Find( "Cd116_Pb214_VT_h_energy_score_fun_P1"  ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e2g->Find( "Mylar_Bi214_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e2g->Find( "Mylar_Pb214_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll1e2g->Find( "SWire_Tl208_h_energy_score_fun_P1"     ));	
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll1e2g->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));	
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll1e2g->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll1e2g->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));	
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll1e2g->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e2g->Find( "FeShield_Bi214_h_energy_score_fun_P1" ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e2g->Find( "FeShield_Tl208_h_energy_score_fun_P1" ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e2g->Find( "FeShield_Ac228_h_energy_score_fun_P1" ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e2g->Find( "CuTower_Co60_h_energy_score_fun_P1"   ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll1e2g->Find( "Air_Bi214_h_energy_score_fun_P1"      ));      
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll1e2g->Find( "Air_Pb214_h_energy_score_fun_P1"      ));      
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll1e2g->Find( "Air_Tl208_h_energy_score_fun_P1"      ));      
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll1e2g->Find( "PMT_Bi214_h_energy_score_fun_P1"      ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e2g->Find( "PMT_Tl208_h_energy_score_fun_P1"      ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e2g->Find( "PMT_Ac228_h_energy_score_fun_P1"      ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll1e2g->Find( "PMT_K40_h_energy_score_fun_P1"        ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e2g->Find( "ScintInn_K40_h_energy_score_fun_P1"   ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e2g->Find( "ScintOut_K40_h_energy_score_fun_P1"   ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e2g->Find( "ScintPet_K40_h_energy_score_fun_P1"   ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e2g->Find( "SScin_Bi210_h_energy_score_fun_P1"    ));         
	 	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e2g->Find( "SScin_Bi214_h_energy_score_fun_P1"    ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e2g->Find( "SScin_Pb214_h_energy_score_fun_P1"    ));         
		energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e2g->Find( "MuMetal_Pa234m_h_energy_score_fun_P1"    ));         

		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e2g->Find( "Cd116_Tl208_h_energy_score_fun_P2"     ));
	    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e2g->Find( "Cd116_Ac228_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e2g->Find( "Cd116_Bi212_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll1e2g->Find( "Cd116_Bi214_h_energy_score_fun_P2"	  ));
	    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll1e2g->Find( "Cd116_Pb214_VT_h_energy_score_fun_P2"  ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e2g->Find( "Mylar_Bi214_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e2g->Find( "Mylar_Pb214_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll1e2g->Find( "SWire_Tl208_h_energy_score_fun_P2"     ));	
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll1e2g->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));	
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll1e2g->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll1e2g->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));	
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll1e2g->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e2g->Find( "FeShield_Bi214_h_energy_score_fun_P2" ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e2g->Find( "FeShield_Tl208_h_energy_score_fun_P2" ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e2g->Find( "FeShield_Ac228_h_energy_score_fun_P2" ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e2g->Find( "CuTower_Co60_h_energy_score_fun_P2"   ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll1e2g->Find( "PMT_Bi214_h_energy_score_fun_P2"      ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e2g->Find( "PMT_Tl208_h_energy_score_fun_P2"      ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e2g->Find( "PMT_Ac228_h_energy_score_fun_P2"      ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll1e2g->Find( "PMT_K40_h_energy_score_fun_P2"        ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e2g->Find( "ScintInn_K40_h_energy_score_fun_P2"   ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e2g->Find( "ScintOut_K40_h_energy_score_fun_P2"   ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e2g->Find( "ScintPet_K40_h_energy_score_fun_P2"   ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e2g->Find( "SScin_Bi210_h_energy_score_fun_P2"    ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e2g->Find( "SScin_Bi214_h_energy_score_fun_P2"    ));         
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e2g->Find( "SScin_Pb214_h_energy_score_fun_P2"    ));         		
		energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e2g->Find( "MuMetal_Pa234m_h_energy_score_fun_P2"    ));         		
			
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll1e3g->Find( "Cd116_Tl208_h_tot_energy"    ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll1e3g->Find( "Cd116_Ac228_h_tot_energy"    ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll1e3g->Find( "Cd116_Bi212_h_tot_energy"    ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll1e3g->Find( "Cd116_Bi214_h_tot_energy"    ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll1e3g->Find( "Cd116_Pb214_VT_h_tot_energy"  ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll1e3g->Find( "Mylar_Bi214_h_tot_energy"    ));
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll1e3g->Find( "Mylar_Pb214_h_tot_energy"    ));
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll1e3g->Find( "SWire_Tl208_h_tot_energy_P1" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll1e3g->Find( "SWire_Tl208_h_tot_energy_P2" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll1e3g->Find( "SWire_Bi214_h_tot_energy_P1" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll1e3g->Find( "SFoil_Bi214_h_tot_energy_P1" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll1e3g->Find( "SWire_Bi214_h_tot_energy_P2" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll1e3g->Find( "SFoil_Bi214_h_tot_energy_P2" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll1e3g->Find( "SWire_Pb214_h_tot_energy_P1" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll1e3g->Find( "SFoil_Pb214_h_tot_energy_P1" ));    	  
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll1e3g->Find( "SWire_Pb214_h_tot_energy_P2" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll1e3g->Find( "SFoil_Pb214_h_tot_energy_P2" ));      
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll1e3g->Find( "FeShield_Bi214_h_tot_energy" ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll1e3g->Find( "FeShield_Tl208_h_tot_energy" ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll1e3g->Find( "FeShield_Ac228_h_tot_energy" ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll1e3g->Find( "CuTower_Co60_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll1e3g->Find( "PMT_Bi214_h_tot_energy"      ));         
	    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll1e3g->Find( "Air_Bi214_h_tot_energy_P1"   ));
	    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll1e3g->Find( "Air_Pb214_h_tot_energy_P1"   ));	
	    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll1e3g->Find( "Air_Tl208_h_tot_energy_P1"   ));
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll1e3g->Find( "PMT_Tl208_h_tot_energy"      ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll1e3g->Find( "PMT_Ac228_h_tot_energy"      ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll1e3g->Find( "PMT_K40_h_tot_energy"        ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll1e3g->Find( "ScintInn_K40_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll1e3g->Find( "ScintOut_K40_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll1e3g->Find( "ScintPet_K40_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll1e3g->Find( "SScin_Bi210_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll1e3g->Find( "SScin_Bi214_h_tot_energy"   ));         
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll1e3g->Find( "SScin_Pb214_h_tot_energy"   ));         			
		tot_energy_3g -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll1e3g->Find( "MuMetal_Pa234m_h_tot_energy"   ));         				
		
		
	}
	// External
	{
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll2eExt->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll2eExt->Find( "Mylar_Pb214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll2eExt->Find( "SWire_Pb214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll2eExt->Find( "SFoil_Pb214_h_tot_e_energy_P1"   ) );
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll2eExt->Find( "SScin_Bi214_h_tot_e_energy_P1"   ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll2eExt->Find( "SScin_Pb214_h_tot_e_energy_P1"   ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll2eExt->Find( "PMT_Tl208_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll2eExt->Find( "PMT_Ac228_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P1") ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P1") ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll2eExt->Find( "Air_Tl208_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll2eExt->Find( "CuTower_Co60_h_tot_e_energy_P1"  ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll2eExt->Find( "SScin_Bi210_h_tot_e_energy_P1"   ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll2eExt->Find( "MuMetal_Pa234m_h_tot_e_energy_P1") ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll2eExt->Find( "Air_Bi214_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll2eExt->Find( "Air_Pb214_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll2eExt->Find( "PMT_Bi214_h_tot_e_energy_P1"     ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P1") ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll2eExt->Find( "ScintPet_K40_h_tot_e_energy_P1"  ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll2eExt->Find( "ScintOut_K40_h_tot_e_energy_P1"  ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll2eExt->Find( "ScintInn_K40_h_tot_e_energy_P1"  ) ); 
		tot_ext_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll2eExt->Find( "PMT_K40_h_tot_e_energy_P1"       ) ); 

		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll2eExt->Find( "Cd116_Bi214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll2eExt->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll2eExt->Find( "Mylar_Bi214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll2eExt->Find( "Mylar_Pb214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll2eExt->Find( "SWire_Pb214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll2eExt->Find( "SFoil_Bi214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll2eExt->Find( "SFoil_Pb214_h_tot_e_energy_P2"     ) );
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll2eExt->Find( "SScin_Bi214_h_tot_e_energy_P2"     ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll2eExt->Find( "SScin_Pb214_h_tot_e_energy_P2"     ) ); 	
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll2eExt->Find( "PMT_Tl208_h_tot_e_energy_P2"       ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll2eExt->Find( "PMT_Ac228_h_tot_e_energy_P2"       ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P2"  ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P2"  ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll2eExt->Find( "CuTower_Co60_h_tot_e_energy_P2"  ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll2eExt->Find( "SScin_Bi210_h_tot_e_energy_P2"     ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll2eExt->Find( "MuMetal_Pa234m_h_tot_e_energy_P2"    ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll2eExt->Find( "PMT_Bi214_h_tot_e_energy_P2"       ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P2"  ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll2eExt->Find( "ScintPet_K40_h_tot_e_energy_P2"    ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll2eExt->Find( "ScintOut_K40_h_tot_e_energy_P2"    ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll2eExt->Find( "ScintInn_K40_h_tot_e_energy_P2"    ) ); 
		tot_ext_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll2eExt->Find( "PMT_K40_h_tot_e_energy_P2"         ) ); 

		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"     ) , hcoll1e1gExt->Find( "Cd116_Bi214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"     ) , hcoll1e1gExt->Find( "Cd116_Pb214_VT_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"     ) , hcoll1e1gExt->Find( "Mylar_Bi214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"     ) , hcoll1e1gExt->Find( "Mylar_Pb214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"  ) , hcoll1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"  ) , hcoll1e1gExt->Find( "SWire_Pb214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"  ) , hcoll1e1gExt->Find( "SFoil_Bi214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"  ) , hcoll1e1gExt->Find( "SFoil_Pb214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"     ) , hcoll1e1gExt->Find( "SScin_Bi214_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"     ) , hcoll1e1gExt->Find( "SScin_Pb214_h_tot_energy_P1"   ) );		
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"       ) , hcoll1e1gExt->Find( "PMT_Tl208_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"       ) , hcoll1e1gExt->Find( "PMT_Ac228_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"  ) , hcoll1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P1") ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"  ) , hcoll1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P1") ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"    ) , hcoll1e1gExt->Find( "Air_Tl208_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"    ) , hcoll1e1gExt->Find( "CuTower_Co60_h_tot_energy_P1"  ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"     ) , hcoll1e1gExt->Find( "SScin_Bi210_h_tot_energy_P1"   ) );
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"  ) , hcoll1e1gExt->Find( "MuMetal_Pa234m_h_tot_energy_P1") ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"    ) , hcoll1e1gExt->Find( "Air_Bi214_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"    ) , hcoll1e1gExt->Find( "Air_Pb214_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"       ) , hcoll1e1gExt->Find( "PMT_Bi214_h_tot_energy_P1"     ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"  ) , hcoll1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P1") ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"    ) , hcoll1e1gExt->Find( "ScintPet_K40_h_tot_energy_P1"  ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"    ) , hcoll1e1gExt->Find( "ScintOut_K40_h_tot_energy_P1"  ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"    ) , hcoll1e1gExt->Find( "ScintInn_K40_h_tot_energy_P1"  ) ); 
		tot_ext_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"         ) , hcoll1e1gExt->Find( "PMT_K40_h_tot_energy_P1"       ) ); 

		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"     ) , hcoll1e1gExt->Find( "Cd116_Bi214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"     ) , hcoll1e1gExt->Find( "Cd116_Pb214_VT_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"     ) , hcoll1e1gExt->Find( "Mylar_Bi214_h_tot_energy_P2"   ) );	
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"     ) , hcoll1e1gExt->Find( "Mylar_Pb214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"  ) , hcoll1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"  ) , hcoll1e1gExt->Find( "SWire_Pb214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"  ) , hcoll1e1gExt->Find( "SFoil_Bi214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"  ) , hcoll1e1gExt->Find( "SFoil_Pb214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"     ) , hcoll1e1gExt->Find( "SScin_Bi214_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"     ) , hcoll1e1gExt->Find( "SScin_Pb214_h_tot_energy_P2"   ) );		
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"       ) , hcoll1e1gExt->Find( "PMT_Tl208_h_tot_energy_P2"     ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"       ) , hcoll1e1gExt->Find( "PMT_Ac228_h_tot_energy_P2"     ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"  ) , hcoll1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P2") ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"  ) , hcoll1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P2") ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"    ) , hcoll1e1gExt->Find( "CuTower_Co60_h_tot_energy_P2"  ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"     ) , hcoll1e1gExt->Find( "SScin_Bi210_h_tot_energy_P2"   ) );
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"       ) , hcoll1e1gExt->Find( "PMT_Bi214_h_tot_energy_P2"             ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"  ) , hcoll1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P2"        ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"  ) , hcoll1e1gExt->Find( "MuMetal_Pa234m_h_tot_energy_P2"    ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"    ) , hcoll1e1gExt->Find( "ScintPet_K40_h_tot_energy_P2"  ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"    ) , hcoll1e1gExt->Find( "ScintOut_K40_h_tot_energy_P2"  ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"    ) , hcoll1e1gExt->Find( "ScintInn_K40_h_tot_energy_P2"  ) ); 
		tot_ext_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"         ) , hcoll1e1gExt->Find( "PMT_K40_h_tot_energy_P2"       ) ); 
		
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

	DataManagement::AddObservable( e_energy_P1_cold );
	DataManagement::AddObservable( e_energy_P2_cold );
	DataManagement::AddObservable( e_energy_P1_warm );	
	DataManagement::AddObservable( e_energy_P2_warm );

	DataManagement::AddObservable( energy_score_fun_P1 );	
	DataManagement::AddObservable( energy_score_fun_P2 );

	DataManagement::AddObservable( tot_ext_e_energy_P1 );	
	DataManagement::AddObservable( tot_ext_e_energy_P2 );	
	DataManagement::AddObservable( tot_ext_e_g_energy_P1 );	
	DataManagement::AddObservable( tot_ext_e_g_energy_P2 );	


	//Fit::DoDrawCorrelationMatrix();
	//Fit::DoDrawScan();
	//Fit::DoDrawContour();
	Fit::Run("Minuit", "Minimize");
    
	cout << "T_{1/2}^{2\\nu} = " << 1/DataManagement::FindParameter("cBB")->GetValInit() << "+/-" << 1/DataManagement::FindParameter("cBB")->GetValInit()**2*DataManagement::FindParameter("cBB")->GetValError() << " 1e+19 y" << endl;

	return 1;

	
	tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf(" ); tot_e_energy_P1_cold -> SetLogScale(kTRUE);
    tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); min_e_energy_P1_cold -> SetLogScale(kTRUE);
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); max_e_energy_P1_cold -> SetLogScale(kTRUE);
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); cosTheta_P1_cold -> SetLogScale(kTRUE);
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );

	tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); tot_e_energy_P2_cold -> SetLogScale(kTRUE);
    tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); min_e_energy_P2_cold -> SetLogScale(kTRUE);
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); max_e_energy_P2_cold -> SetLogScale(kTRUE);
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); cosTheta_P2_cold -> SetLogScale(kTRUE);
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );

	tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); tot_e_energy_P1_warm -> SetLogScale(kTRUE);
    tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); min_e_energy_P1_warm -> SetLogScale(kTRUE);
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); max_e_energy_P1_warm -> SetLogScale(kTRUE);
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); cosTheta_P1_warm -> SetLogScale(kTRUE);
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );

	tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); tot_e_energy_P2_warm -> SetLogScale(kTRUE);
    tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); min_e_energy_P2_warm -> SetLogScale(kTRUE);
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); max_e_energy_P2_warm -> SetLogScale(kTRUE);
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); cosTheta_P2_warm -> SetLogScale(kTRUE);
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );	

	energy_score_fun_P1 -> Draw(); 											   (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	energy_score_fun_P1 -> SetLogScale(kTRUE);	energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	energy_score_fun_P2 -> Draw(); 											   (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	energy_score_fun_P2 -> SetLogScale(kTRUE);	energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_energy_3g       -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");

	e_energy_P1_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P1_cold -> SetLogScale(kTRUE); e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P1_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P1_warm -> SetLogScale(kTRUE); e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");

	e_energy_P2_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P2_cold -> SetLogScale(kTRUE); e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P2_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	e_energy_P2_warm -> SetLogScale(kTRUE); e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");

	tot_ext_e_energy_P1   -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_energy_P1   -> SetLogScale(kTRUE); tot_ext_e_energy_P1   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_energy_P2   -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");	
	tot_ext_e_energy_P2   -> SetLogScale(kTRUE); tot_ext_e_energy_P2   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_g_energy_P1 -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_g_energy_P1 -> SetLogScale(kTRUE); tot_ext_e_g_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_g_energy_P2 -> Draw();                                          (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf");
	tot_ext_e_g_energy_P2 -> SetLogScale(kTRUE); tot_ext_e_g_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf")
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Summed plot
	//
	//////////////////////////////////////////////////////////////////////////////	
	
	Observable * tot_e_energy  = new Observable("tot_e_energy" , "2e - E_{e1} + E_{e2}" , kAll , hcoll2e->Find( "Data_h_tot_e_energy" ) ); tot_e_energy -> SetLogScale(kFALSE); tot_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy -> SetDrawGroup(kTRUE);
	Observable * min_e_energy  = new Observable("min_e_energy" , "2e - E_{e,min}"       , kAll , hcoll2e->Find( "Data_h_min_e_energy" ) ); min_e_energy -> SetLogScale(kFALSE); min_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy -> SetDrawGroup(kTRUE);
	Observable * max_e_energy  = new Observable("max_e_energy" , "2e - E_{e,max}"       , kAll , hcoll2e->Find( "Data_h_max_e_energy" ) ); max_e_energy -> SetLogScale(kFALSE); max_e_energy -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy -> SetDrawGroup(kTRUE);
	Observable * cosTheta      = new Observable("cosTheta"     , "2e - Cos(#Theta)"     , kAll , hcoll2e->Find( "Data_h_cosTheta"     ) ); cosTheta     -> SetLogScale(kFALSE); cosTheta     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta     -> SetDrawGroup(kTRUE);
	hcoll2e->Find( "Data_h_cosTheta" ) ->GetYaxis()->SetRangeUser(0.5,1000);

	hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P2_cold"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P2_cold"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P2_cold"    ) );
	hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P2_warm"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P2_warm"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P2_warm"    ) );

	hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_min_e_energy_P2_cold"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P2_cold"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P2_cold"    ) );
	hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_min_e_energy_P2_warm"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P2_warm"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P2_warm"    ) );

	hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_max_e_energy_P2_cold"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P2_cold"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P2_cold"    ) );
	hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_max_e_energy_P2_warm"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P2_warm"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P2_warm"    ) );

	hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_cosTheta_P2_cold"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P2_cold"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P2_cold"    ) );
	hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) -> Add( hcoll2e->Find( "Cd116_K40_h_cosTheta_P2_warm"      ) );
	hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) -> Add( hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P2_warm"   ) );
	hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) -> Add( hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P2_warm"    ) );


	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_tot_e_energy" ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_tot_e_energy"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_tot_e_energy"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) );
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_tot_e_energy_P2"    ) );   	
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_tot_e_energy"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_tot_e_energy_P2"    ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_tot_e_energy" ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_tot_e_energy" ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_tot_e_energy" ) );      		
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_tot_e_energy_P1"      ) );   
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_tot_e_energy"      ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_tot_e_energy"        ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_tot_e_energy"   ) );      
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_tot_e_energy"   ) );      	
	tot_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_tot_e_energy" ) );      

	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_min_e_energy" ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_min_e_energy"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_min_e_energy"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ) );
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_min_e_energy"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P1"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_min_e_energy_P2"    ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_min_e_energy" ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_min_e_energy" ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_min_e_energy" ) );      		
	min_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_min_e_energy_P1"      ) );   
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_min_e_energy"      ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_min_e_energy"        ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_min_e_energy"   ) );      
	min_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_min_e_energy"   ) );      	
	min_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_min_e_energy" ) );      

	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_max_e_energy" ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_max_e_energy"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_max_e_energy"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ) );
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_max_e_energy_P2"    ) );   	
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_max_e_energy"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P1"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_max_e_energy_P2"    ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_max_e_energy" ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_max_e_energy" ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_max_e_energy" ) );      		
	max_e_energy -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_max_e_energy_P1"      ) );   
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_max_e_energy"      ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_max_e_energy"        ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_max_e_energy"   ) );      
	max_e_energy -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_max_e_energy"   ) );      	
	max_e_energy -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_max_e_energy" ) );      

	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll2e->Find( "Cd116_Tl208_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll2e->Find( "Cd116_Ac228_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll2e->Find( "Cd116_Bi212_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll2e->Find( "Cd116_Bi214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll2e->Find( "Cd116_Pb214_VT_h_cosTheta" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll2e->Find( "Mylar_Bi214_h_cosTheta"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll2e->Find( "Mylar_Pb214_h_cosTheta"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_cold"      ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll2e->Find( "Cd116_K40_h_cosTheta_P1_warm"      ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll2e->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll2e->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ) );
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P1" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , hcoll2e->Find( "SWire_Bi210_h_cosTheta_P2" ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll2e->Find( "SScin_Bi210_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll2e->Find( "SScin_Bi214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll2e->Find( "SScin_Pb214_h_cosTheta"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P1"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll2e->Find( "SWire_Tl208_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll2e->Find( "SWire_Bi214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll2e->Find( "SFoil_Bi214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll2e->Find( "SWire_Pb214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll2e->Find( "SFoil_Pb214_h_cosTheta_P2"    ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll2e->Find( "FeShield_Bi214_h_cosTheta" ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll2e->Find( "FeShield_Tl208_h_cosTheta" ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll2e->Find( "FeShield_Ac228_h_cosTheta" ) );      		
	cosTheta -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll2e->Find( "CuTower_Co60_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll2e->Find( "Air_Bi214_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll2e->Find( "Air_Pb214_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll2e->Find( "Air_Tl208_h_cosTheta_P1"      ) );   
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll2e->Find( "PMT_Bi214_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll2e->Find( "PMT_Tl208_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll2e->Find( "PMT_Ac228_h_cosTheta"      ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll2e->Find( "PMT_K40_h_cosTheta"        ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll2e->Find( "ScintInn_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll2e->Find( "ScintOut_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll2e->Find( "ScintPet_K40_h_cosTheta"   ) );      
	cosTheta -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll2e->Find( "MuMetal_Pa234m_h_cosTheta"   ) );      	
	cosTheta -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll2e->Find( "Cd116_2b2n_m14_h_cosTheta" ) );      
	
	tot_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); tot_e_energy -> SetLogScale(kTRUE);
    tot_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	min_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); min_e_energy -> SetLogScale(kTRUE);
	min_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	max_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); max_e_energy -> SetLogScale(kTRUE);
	max_e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  );
	cosTheta     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf"  ); cosTheta -> SetLogScale(kTRUE);
	cosTheta     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitJoin.pdf)" );	
	
	tot_e_energy->DrawDetails();
	(TPad*)gROOT->GetSelectedPad()->Print("FitJoin_Details.pdf");
	
	tot_e_energy->PrintDetails();


}