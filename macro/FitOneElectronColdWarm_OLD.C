{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/OneElectronHistos.root");
	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/OneElectronHistos_Eth300keV_BentonHotSpotDef.root");
	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/OneElectronHistos_Eth300keV_OriginalHotSpotDef.root");
	
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150603/OneElectronHistos.root");
	
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
	DataManagement::AddParameter( new Parameter( "Cd116_K40_cold"    , "Cd116_K40_cold"    ,  0 , 6.04935e-03 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_K40_cold"    ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_cold" , "Cd116_Pa234m_cold" ,  1 , 1.04987e-03 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Pa234m_cold" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_K40_warm"    , "Cd116_K40_warm"    ,  2 , 1.06321e-02 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_K40_warm"    ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_warm" , "Cd116_Pa234m_warm" ,  3 , 2.10860e-03 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Pa234m_warm" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_cold"  , "SFoil_Bi210_cold"  ,  4 , 1.17451e+00 , 0.1 ) ); //DataManagement::FindParameter( "SFoil_Bi210_cold" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_warm"  , "SFoil_Bi210_warm"  ,  5 , 2.76078e+00 , 0.1 ) ); //DataManagement::FindParameter( "SFoil_Bi210_warm" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "cSwire"            , "cSwire"       	   ,  6 , 1.37181e+00 , 0.1 ) ); //DataManagement::FindParameter( "cSwire" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoil"            , "cSfoil"       	   ,  7 , 1.02459e+00 , 0.1 ) ); //DataManagement::FindParameter( "cSfoil" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cTl208"            , "cTl208"       	   ,  8 , 1.04284e+00 , 0.1 ) ); //DataManagement::FindParameter( "cTl208" ) -> SetFix();    
	DataManagement::AddParameter( new Parameter( "cBi214"            , "cBi214"       	   ,  9 , 1.05054e+00 , 0.1 ) ); //DataManagement::FindParameter( "cBi214" ) -> SetFix();    
	DataManagement::AddParameter( new Parameter( "cBi210"            , "cBi210"       	   , 10 , 9.98557e-01 , 0.1 ) ); //DataManagement::FindParameter( "cBi210" ) -> SetFix();    
	DataManagement::AddParameter( new Parameter( "cExt"              , "cExt"         	   , 11 , 1.01893e+00 , 0.1 ) ); //DataManagement::FindParameter( "cExt"   ) -> SetFix();
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
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ), DataManagement::GetNormBB()/2.9e19, 0.07*DataManagement::GetNormBB()/2.9e19)); DataManagement::FindComponent("Cd116_2b2n_m14")  ->SetFillColor( kViolet + 10 );	
	DataManagement::FindGroup("BB")->AddComponent(DataManagement::FindComponent("Cd116_2b2n_m14"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Single Beta emitter
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_cold"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "Cd116_K40_warm"    ) , 1. )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::FindGroup("K40")->AddComponent(DataManagement::FindComponent("Cd116_K40_cold"));
	DataManagement::FindGroup("K40")->AddComponent(DataManagement::FindComponent("Cd116_K40_warm"));
	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_cold" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "Cd116_Pa234m_warm" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );	
	DataManagement::FindGroup("Pa234m")->AddComponent(DataManagement::FindComponent("Cd116_Pa234m_cold"));
	DataManagement::FindGroup("Pa234m")->AddComponent(DataManagement::FindComponent("Cd116_Pa234m_warm"));

	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "SFoil_Bi210_cold"  ) , 1. )); DataManagement::FindComponent("SFoil_Bi210_cold"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "SFoil_Bi210_warm"  ) , 1. )); DataManagement::FindComponent("SFoil_Bi210_warm"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Bi210_P1"    , "^{210}Bi SWire P1"    , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "cBi210" ) , 2.48 , 0.12 , true, 1 )); DataManagement::FindComponent( "SWire_Bi210_P1"  )->SetFillColor( kGreen + 1 );
	DataManagement::AddComponent( new Component( "SWire_Bi210_P2"    , "^{210}Bi SWire P2"    , DataManagement::FindDataSet( "SWire_Bi210" ) , DataManagement::FindParameter( "cBi210" ) , 2.40 , 0.12 , true, 1 )); DataManagement::FindComponent( "SWire_Bi210_P2"  )->SetFillColor( kGreen + 1 );
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_cold"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_warm"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SWire_Bi210_P1"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SWire_Bi210_P2"));
	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cTl208" ) , 1.67716e-04*0.440        , 3.09928e-05*0.440        , true , 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cTl208" ) , 1.67716e-04*0.440/0.3594 , 3.09928e-05*0.440/0.3594 , true , 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"  ,"^{212}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "cTl208" ) , 1.67716e-04*0.440/0.3594 , 3.09928e-05*0.440/0.3594 , true , 1 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 2 );	
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Tl208"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Ac228"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Bi212"));

	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214" )    , DataManagement::FindParameter( "cBi214" ) , 0.440*2.8e-4      , 0.440*1.0e-4      , true , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cBi214" ) , 0.440*2.8e-4      , 0.440*1.0e-4      , true , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214" )    , DataManagement::FindParameter( "cBi214" ) , 0.888*3.01074e-03 , 0.888*2.29057e-04 , true , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214" )    , DataManagement::FindParameter( "cBi214" ) , 0.888*3.01074e-03 , 0.888*2.29057e-04 , true , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kOrange +  0 );
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Pb214"));

	//////////////////////////////////////////////////////////////////////////////	
	//	
	// Rn in tracker chamber : Values from 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Tl208_P1"  , "^{208}Tl SWire P1" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire" ) , 3.5E-03 , 0.4E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Tl208_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Tl208_P2"  , "^{208}Tl SWire P2" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire" ) , 2.9E-03 , 0.4E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Tl208_P2"  )->SetFillColor( kAzure + 2 );

	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 6.6E-01 , 4E-02 , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 6.6E-01 , 4E-02 , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 9.3E-02 , 6E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 9.3E-02 , 6E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-02 , 2E-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-02 , 2E-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.1E-03 , 3E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.1E-03 , 3E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );

	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2" ) );
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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) , 1.08923e+04        , 2.48367e+03        , true , 100 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) , 0.0                , 0.0                , true , 100 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	//DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) , 0.0/0.3594         , 0.0/0.3594         , true , 100 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) , 8.30325e+01        , 1.49165e+01        , true , 100 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 5.83127e+02        , 2.62340e+01        , true , 100 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) , 5.83127e+02        , 2.62340e+01        , true , 100 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 1.35486e+01        , 3.45649e+00        , true , 100 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) , 2.56405e+02        , 5.87015e+01        , true , 100 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) , 4.66797e+01        , 6.64189e-01        , true , 100 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) , 4.66797e+01/0.3594 , 6.64189e-01/0.3594 , true , 100 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) , 1.32636e+03        , 6.00053e+01        , true , 100 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) , 5.07412e+00        , 7.35094e-01        , true , 100 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) , 5.07412e+00        , 7.35094e-01        , true , 100 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) , 5.07412e+00        , 7.35094e-01        , true , 100 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) , 4.08894e+01        , 4.81803e+00        , true , 100 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange + 0 );
	DataManagement::AddComponent( new Component( "SScin_Bi214"    , "^{214}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi214"    ) , DataManagement::FindParameter( "cExt" ) , 2.54905e-01        , 3.96300e-02        , true , 100 )); DataManagement::FindComponent( "SScin_Bi214"    )->SetFillColor( kOrange + 0 );
	DataManagement::AddComponent( new Component( "SScin_Pb214"    , "^{214}Pb SScin     " , DataManagement::FindDataSet( "SScin_Pb214"    ) , DataManagement::FindParameter( "cExt" ) , 2.54905e-01        , 3.96300e-02        , true , 100 )); DataManagement::FindComponent( "SScin_Pb214"    )->SetFillColor( kOrange + 0 );
	//DataManagement::AddComponent( new Component( "SScin_Pa234m"   , "^{234m}Pa SScin    " , DataManagement::FindDataSet( "SScin_Pa234m"   ) , DataManagement::FindParameter( "cExt" ) ,1.92105e-01 , 3.16135e-01 , true , 1 )); DataManagement::FindComponent( "SScin_Pa234m"   )->SetFillColor( kOrange + 0 );	

	DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Bi214" ) );
	//DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Tl208" ) );
	//DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "FeShield_Ac228" ) );
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
	//DataManagement::FindGroup("Externals")->AddComponent( DataManagement::FindComponent( "SScin_Pm234m"   ) );
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
    //e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_cold"  ));
    //e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_cold"  ));
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
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"       ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"    ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_cold"     ));
    //e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"       ) , hcoll->Find( "SScin_Pa234m_h_e_energy_P1_cold"     ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"     ));

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
    //e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_cold"  ));
    //e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_cold"  ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	      ) , hcoll->Find( "PMT_K40_h_e_energy_P2_cold"   	  ));
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
    //e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"       ) , hcoll->Find( "SScin_Pa234m_h_e_energy_P2_cold"     ));
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
    //e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexZ_cold" ));
    //e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexZ_cold" ));
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
    //e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_vertexZ_cold"    ));	
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
    //e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexSector_cold" ));
    //e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexSector_cold" ));
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
    //e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_vertexSector_cold" ));	
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
    //e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_warm"  ));
    //e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_warm"  ));
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
    //e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_e_energy_P1_warm"     ));	
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
    //e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_warm"  ));
    //e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_warm"  ));
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
    //e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_e_energy_P2_warm"     ));	
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
    //e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexZ_warm" ));
    //e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexZ_warm" ));
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
    //e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_vertexZ_warm"    ));	
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
    //e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_vertexSector_warm" ));
    //e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_vertexSector_warm" ));
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
    //e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_vertexSector_warm"    ));	
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

	e_energy_P1_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps(");
	e_energy_P1_cold -> SetLogScale(kTRUE); e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy_P1_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy_P1_warm -> SetLogScale(kTRUE); e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");

	e_energy_P2_cold -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy_P2_cold -> SetLogScale(kTRUE); e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy_P2_warm -> Draw();                                         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy_P2_warm -> SetLogScale(kTRUE); e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");

	e_vertexZ_cold -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_vertexS_cold -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_vertexZ_warm -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_vertexS_warm -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");


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
    //e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_electronEnergy"  ));
    //e_energy -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_electronEnergy"  ));
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
	//e_energy -> AddComponent( DataManagement::FindComponent( "SScin_Pa234m"        ) , hcoll->Find( "SScin_Pa234m_h_electronEnergy"     ));	
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1"     ));
	e_energy -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"     ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2"     ));

	e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps");
	e_energy -> SetLogScale(kTRUE); e_energy -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps)");
	
	e_energy->PrintDetails();
	
}