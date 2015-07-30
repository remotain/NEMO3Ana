{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/OneElectronHistos_Eth300keV_OriginalHotSpotDef.root");
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
	DataManagement::AddParameter( new Parameter( "Cd116_K40_cold"    , "Cd116_K40_cold"    ,  0 , 3.45663e-03  , 0.1 ) ); //DataManagement::FindParameter( "Cd116_K40_cold"    ) -> SetLimit(0,1);
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_cold" , "Cd116_Pa234m_cold" ,  1 , 1.67017e-03  , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Pa234m_cold" ) -> SetLimit(0,1);
	DataManagement::AddParameter( new Parameter( "Cd116_K40_warm"    , "Cd116_K40_warm"    ,  2 , 9.04479e-03  , 0.1 ) ); //DataManagement::FindParameter( "Cd116_K40_warm"    ) -> SetLimit(0,1);
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m_warm" , "Cd116_Pa234m_warm" ,  3 , 3.08042e-03  , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Pa234m_warm" ) -> SetLimit(0,1);
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_cold"  , "SFoil_Bi210_cold"  ,  4 , 1.26245e+00  , 0.1 ) ); //DataManagement::FindParameter( "SFoil_Bi210" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210_warm"  , "SFoil_Bi210_warm"  ,  5 , 2.81877e+00  , 0.1 ) ); //DataManagement::FindParameter( "SFoil_Bi210" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Cd113"       , "Cd116_Cd113"       ,  6 , 4.92387e-02 , 0.1 ) ); //DataManagement::FindParameter( "Cd116_Cd113" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "cSwire"            , "cSwire"       	   ,  7 , 1.00660e+00 , 0.1 ) ); //DataManagement::FindParameter( "cSwire"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoil"            , "cSfoil"       	   ,  8 , 1.01162e+00 , 0.1 ) ); //DataManagement::FindParameter( "cSfoil"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cInt"              , "cInt"         	   ,  9 , 1.00707e+00 , 0.1 ) ); //DataManagement::FindParameter( "cInt"        ) -> SetFix();    
	DataManagement::AddParameter( new Parameter( "cExt"              , "cExt"         	   , 10 , 1.00215e+00 , 0.1 ) ); //DataManagement::FindParameter( "cExt"        ) -> SetFix();
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
	DataManagement::AddGroup( new Group( "Cd113"     , "^{113}Cd"   )); DataManagement::FindGroup("Cd113"     ) -> SetFillColor( kViolet +  3 );
	DataManagement::AddGroup( new Group( "Bi210"     , "^{210}Bi"   )); DataManagement::FindGroup("Bi210"     ) -> SetFillColor( kGreen  +  2 );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// bb2nu
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ), DataManagement::GetNormBB()/2.9e19, 0.07*DataManagement::GetNormBB()/2.89e19)); DataManagement::FindComponent("Cd116_2b2n_m14")  ->SetFillColor( kViolet + 10 );	
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
	DataManagement::AddComponent( new Component( "SWire_Bi210"       , "^{210}Bi SWire"       , DataManagement::FindDataSet( "SWire_Bi210" ) , 2.40 , 0.12 )); DataManagement::FindComponent( "SWire_Bi210"  )->SetFillColor( kGreen + 1 );
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_cold"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SFoil_Bi210_warm"));
	DataManagement::FindGroup("Bi210")->AddComponent(DataManagement::FindComponent("SWire_Bi210"));
	
	DataManagement::AddComponent( new Component( "Cd116_Cd113"       , "^{113}Cd Cd116"       , DataManagement::FindDataSet( "Cd116_Cd113m" ) , DataManagement::FindParameter( "Cd116_Cd113"       ) , 1. )); DataManagement::FindComponent("Cd116_Cd113"       ) -> SetFillColor( kViolet + 3 );	
	DataManagement::FindGroup("Cd113")->AddComponent(DataManagement::FindComponent("Cd116_Cd113"));
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "cInt" )    , 0.440*1.7E-04 , 0.440*5E-05 , true , 1 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "cInt" )    , 0.440*1.7E-04 , 0.440*5E-05 , true , 1 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Pb211"  ,"^{211}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb211" ) , DataManagement::FindParameter( "cInt" )    , 0.440*1.7E-04 , 0.440*5E-05 , true , 1 )); DataManagement::FindComponent("Cd116_Pb211")->SetFillColor( kOrange + 2 );	
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Tl208"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Ac228"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Pb211"));

	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cInt" ) , 0.440*2E-04   , 0.440*0E+00 , true , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cInt" ) , 0.440*2E-04   , 0.440*0E+00 , true , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.3E-03 , 0.888*1E-04 , true , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.3E-03 , 0.888*1E-04 , true , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kOrange +  0 );
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Pb214"));

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber : Values from 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 5.9E-01 , 6E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 5.9E-01 , 6E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 7.5E-02 , 2E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 7.5E-02 , 2E-03 , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2"  )->SetFillColor( kAzure + 2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 2.5E-02 , 7E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 2.5E-02 , 7E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1"  )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-03 , 1E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-03 , 1E-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2"  )->SetFillColor( kAzure +  4 );

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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) ,7360.00   , 200.00  , true , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) , 484.00   ,  24.00  , true , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) , 484.00   ,  24.00  , true , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) ,8.7E+01   , 8E+00   , true , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,5.7E+02   , 0E+00   , true , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) ,5.7E+02   , 0E+00   , true , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,1.2E+01   , 1.2E+01 , true , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,3.2E+02   , 1E+00   , true , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,2.7E+01   , 6E-01   , true , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) ,2.7E+01   , 6E-01   , true , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) ,1.078E+03 , 3E+01   , true , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , true , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , true , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , true , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) ,3.2E+01   , 0E+00   , true , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange + 0 );

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
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_cold = new Observable("e_energy_P1_cold" , "E_{e} - Phase 1 Cold" , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1_cold" ) ); e_energy_P1_cold -> SetLogScale(kFALSE); e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_cold -> SetDrawGroup(kTRUE); //e_energy_P1_cold -> SetFitRangeLowEdge(0.5);
	Observable * e_energy_P2_cold = new Observable("e_energy_P2_cold" , "E_{e} - Phase 2 Cold" , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2_cold" ) ); e_energy_P2_cold -> SetLogScale(kFALSE); e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_cold -> SetDrawGroup(kTRUE); //e_energy_P2_cold -> SetFitRangeLowEdge(0.5);
	Observable * e_energy_P1_warm = new Observable("e_energy_P1_warm" , "E_{e} - Phase 1 Warm" , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1_warm" ) ); e_energy_P1_warm -> SetLogScale(kFALSE); e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1_warm -> SetDrawGroup(kTRUE); //e_energy_P1_warm -> SetFitRangeLowEdge(0.5);
	Observable * e_energy_P2_warm = new Observable("e_energy_P2_warm" , "E_{e} - Phase 2 Warm" , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2_warm" ) ); e_energy_P2_warm -> SetLogScale(kFALSE); e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2_warm -> SetDrawGroup(kTRUE); //e_energy_P2_warm -> SetFitRangeLowEdge(0.5);
	
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
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_cold"     ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_cold"	    ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P1_cold"  ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_cold"     ));	
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_cold"     ));	
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
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"     ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"       ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold"  ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"    ));
    e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"     ));
	e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_e_energy_P1_cold"    ));

	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_cold"     ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P2_cold"  ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_cold"     ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_cold"     ));	
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_cold"  ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_cold"  ));
    e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_cold"  ));
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
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_cold"     ));
	e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_e_energy_P2_cold"    ));

	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexZ_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexZ_cold"    ));
    e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexZ_cold" ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexZ_cold"    ));	
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexZ_cold"    ));	
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
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_vertexZ_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_vertexZ_cold"    ));
	e_vertexZ_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_vertexZ_cold"   ));  

	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexSector_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexSector_cold"    ));
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexSector_cold" ));	
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexSector_cold"    ));	
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexSector_cold"    ));	
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
    e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_vertexSector_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_vertexSector_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold"   ) , hcoll->Find( "SFoil_Bi210_h_vertexSector_cold"    ));
	e_vertexS_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_vertexSector_cold"   ));  

	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_warm"     ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_warm"	  ));
    e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P1_warm"  ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_warm"     ));	
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_warm"     ));	
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
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"     ));
	e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_e_energy_P1_warm"    ));

	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	      ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_warm"     ));
    e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	      ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P2_warm"  ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_warm"     ));	
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_warm"     ));	
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
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_warm"     ));
	e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_e_energy_P2_warm"    ));  
  
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexZ_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexZ_warm"    ));
    e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexZ_warm" ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexZ_warm"    ));	
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexZ_warm"    ));	
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
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_vertexZ_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_vertexZ_warm"    ));
	e_vertexZ_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_vertexZ_warm"   ));  

	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_vertexSector_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll->Find( "Cd116_Pb211_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	    ) , hcoll->Find( "Cd116_Bi214_h_vertexSector_warm"    ));
    e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	    ) , hcoll->Find( "Cd116_Pb214_VT_h_vertexSector_warm" ));	
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_vertexSector_warm"    ));	
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_vertexSector_warm"    ));	
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
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll->Find( "SWire_Bi210_h_vertexSector_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"   ) , hcoll->Find( "SFoil_Bi210_h_vertexSector_warm"    ));
	e_vertexS_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"        ) , hcoll->Find( "Cd116_Cd113m_h_vertexSector_warm"   ));   
  
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
	e_vertexS_warm -> Draw();                                           (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronColdWarm.ps)");

	
}