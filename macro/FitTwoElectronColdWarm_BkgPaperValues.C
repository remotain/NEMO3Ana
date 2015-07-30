{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos.root");
	
	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos_PInt_0_01.root");
	
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos_Eth_200.root");
	
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
	DataManagement::AddParameter( new Parameter( "cBB"       , "cBB"       ,  0 , 3.46e-01    , 0.0000001 ) ); 
	DataManagement::AddParameter( new Parameter( "cTl208"    , "Tl208"     ,  1 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cTl208" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cBi214"    , "Bi214"     ,  2 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cBi214" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cInt"      , "cInt"      ,  3 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cInt"   ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire"    , "cSwire"    ,  4 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cSwire" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoil"    , "cSfoil"    ,  5 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cSfoil" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cExt"      , "cExt"      ,  6 , 1.0 , 0.1 ) ); DataManagement::FindParameter( "cExt"   ) -> SetFix();
	//////////////////////////////////////////////////////////////////////////////
	//
	// Groups
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddGroup( new Group( "Tl208"     , "^{208}Tl"   )); DataManagement::FindGroup("Tl208"     ) -> SetFillColor( kOrange + 10 );
	DataManagement::AddGroup( new Group( "Bi214"     , "^{214}Bi"   )); DataManagement::FindGroup("Bi214"     ) -> SetFillColor( kGreen  +  0 );
	DataManagement::AddGroup( new Group( "Radon"     , "Radon"      )); DataManagement::FindGroup("Radon"     ) -> SetFillColor( kAzure  +  1 );
	DataManagement::AddGroup( new Group( "Internals" , "Internals"  )); DataManagement::FindGroup("Internals" ) -> SetFillColor( kViolet +  0 );
	DataManagement::AddGroup( new Group( "Externals" , "Externals"  )); DataManagement::FindGroup("Externals" ) -> SetFillColor( kOrange +  0 );
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
	DataManagement::AddComponent( new Component( "Cd116_Tl208"  , "^{208}Tl Cd116"  , DataManagement::FindDataSet( "Cd116_Tl208"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*1.7E-04 , 0.440*5E-05 , false , 1 )); DataManagement::FindComponent("Cd116_Tl208"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Tl208"  )->SetLineColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Ac228"  , "^{228}Ac Cd116"  , DataManagement::FindDataSet( "Cd116_Ac228"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*1.7E-04 , 0.440*5E-05 , false , 1 )); DataManagement::FindComponent("Cd116_Ac228"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Ac228"  )->SetLineColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Pb211"  , "^{211}Pb Cd116"  , DataManagement::FindDataSet( "Cd116_Pb211"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*1.7E-04 , 0.440*5E-05 , false , 1 )); DataManagement::FindComponent("Cd116_Pb211"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Pb211"  )->SetLineColor( kOrange + 10 );
	
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Tl208"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Ac228"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Pb211"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-214
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Bi214"  , "^{214}Bi Cd116"  , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cBi214" ) , 0.440*2E-04   , 0.440*0E+00 , false , 1 )); DataManagement::FindComponent("Cd116_Bi214"  )->SetFillColor( kGreen +  0 ); DataManagement::FindComponent("Cd116_Bi214"  )->SetLineColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214"  , "^{214}Pb Cd116"  , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cBi214" ) , 0.440*2E-04   , 0.440*0E+00 , false , 1 )); DataManagement::FindComponent("Cd116_Pb214"  )->SetFillColor( kGreen +  0 ); DataManagement::FindComponent("Cd116_Pb214"  )->SetLineColor( kGreen +  0 );

	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Other Internals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_K40_cold"    , "^{40}K Cd116 cold"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cInt" ) , 5.09736e-03 , 1.56578e-04 , false , 1. )); DataManagement::FindComponent("Cd116_K40_cold"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_K40_warm"    , "^{40}K Cd116 warm"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cInt" ) , 9.80635e-03 , 1.64672e-04 , false , 1. )); DataManagement::FindComponent("Cd116_K40_warm"    ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold" , "^{234m}Pa Cd116 cold" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cInt" ) , 1.38651e-03 , 5.66566e-05 , false , 1. )); DataManagement::FindComponent("Cd116_Pa234m_cold" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm" , "^{234m}Pa Cd116 warm" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cInt" ) , 2.87945e-03 , 5.43377e-05 , false , 1. )); DataManagement::FindComponent("Cd116_Pa234m_warm" ) -> SetFillColor( kViolet + 2 );		
	DataManagement::AddComponent( new Component( "SFoil_Bi210_cold"  , "^{210}Bi SFoil cold"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 1.12720e+00 , 1.21087e-02 , false , 1. )); DataManagement::FindComponent("SFoil_Bi210_cold"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210_warm"  , "^{210}Bi SFoil warm"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.77371e+00 , 1.13022e-02 , false , 1. )); DataManagement::FindComponent("SFoil_Bi210_warm"  ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "Cd116_Cd113"       , "^{113}Cd Cd116"       , DataManagement::FindDataSet( "Cd116_Cd113m" ) , DataManagement::FindParameter( "cInt" ) , 6.72143e-02 , 9.38386E-04 , false , 1. )); DataManagement::FindComponent("Cd116_Cd113"       ) -> SetFillColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "SWire_Bi210"       , "^{210}Bi SWire"       , DataManagement::FindDataSet( "SWire_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.40        , 0.12        , false , 1. )); DataManagement::FindComponent( "SWire_Bi210"      ) -> SetFillColor( kGreen + 1 );

	DataManagement::AddComponent( new Component( "Mylar_Bi214"  , "^{214}Bi Mylar"  , DataManagement::FindDataSet( "Mylar_Bi214"  ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.3E-03 , 0.888*1E-04 , false , 1 )); DataManagement::FindComponent("Mylar_Bi214"  )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Mylar_Bi214"  )->SetLineColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214"  , "^{214}Pb Mylar"  , DataManagement::FindDataSet( "Mylar_Pb214"  ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.3E-03 , 0.888*1E-04 , false , 1 )); DataManagement::FindComponent("Mylar_Pb214"  )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Mylar_Pb214"  )->SetLineColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "SWire_Bi210"  , "^{210}Bi SWire"  , DataManagement::FindDataSet( "SWire_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.40              , 0.12              , false , 1 )); DataManagement::FindComponent( "SWire_Bi210" )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent( "SWire_Bi210" )->SetLineColor( kViolet + 0 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210"  , "^{210}Bi SFoil"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.57553e+00       , 6.65487e-03       , false , 1 )); DataManagement::FindComponent( "SFoil_Bi210" )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent( "SFoil_Bi210" )->SetLineColor( kViolet + 0 );		
	
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "SWire_Bi210"       ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "SFoil_Bi210"       ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent( "Cd116_Cd113"       ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn 
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 5.9E-01 , 6E-03 , false , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 5.9E-01 , 6E-03 , false , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Pb214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 7.5E-02 , 2E-03 , false , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 7.5E-02 , 2E-03 , false , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Pb214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 2.5E-02 , 7E-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 2.5E-02 , 7E-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Pb214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-03 , 1E-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.5E-03 , 1E-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Pb214_P2" )->SetLineColor( kAzure + 1 );
	
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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) ,7360.00   , 200.00  , false , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) , 484.00   ,  24.00  , false , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) , 484.00   ,  24.00  , false , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) ,8.7E+01   , 8E+00   , false , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,5.7E+02   , 0E+00   , false , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) ,5.7E+02   , 0E+00   , false , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,1.2E+01   , 1.2E+01 , false , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,3.2E+02   , 1E+00   , false , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,2.7E+01   , 6E-01   , false , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) ,2.7E+01   , 6E-01   , false , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) ,1.078E+03 , 3E+01   , false , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , false , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , false , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) ,2.15E+01  , 9E-01   , false , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) ,3.2E+01   , 0E+00   , false , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange + 0 );
	
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
	Observable * tot_e_energy_P1_cold  = new Observable("tot_e_energy_P1_cold" , "2e - E_{e1} + E_{e2} - Phase 1 cold" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P1_cold" ) ); tot_e_energy_P1_cold -> SetLogScale(kFALSE); tot_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_cold -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P1_cold  = new Observable("min_e_energy_P1_cold" , "2e - E_{e,min} - Phase 1 cold"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P1_cold" ) ); min_e_energy_P1_cold -> SetLogScale(kFALSE); min_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_cold -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P1_cold  = new Observable("max_e_energy_P1_cold" , "2e - E_{e,max} - Phase 1 cold"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P1_cold" ) ); max_e_energy_P1_cold -> SetLogScale(kFALSE); max_e_energy_P1_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_cold -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P1_cold      = new Observable("cosTheta_P1_cold"     , "2e - Cos(#Theta) - Phase 1 cold"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P1_cold"     ) ); cosTheta_P1_cold     -> SetLogScale(kFALSE); cosTheta_P1_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_cold     -> SetDrawGroup(kTRUE);

	Observable * tot_e_energy_P1_warm  = new Observable("tot_e_energy_P1_warm" , "2e - E_{e1} + E_{e2} - Phase 1 warm" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P1_warm" ) ); tot_e_energy_P1_warm -> SetLogScale(kFALSE); tot_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1_warm -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P1_warm  = new Observable("min_e_energy_P1_warm" , "2e - E_{e,min} - Phase 1 warm"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P1_warm" ) ); min_e_energy_P1_warm -> SetLogScale(kFALSE); min_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1_warm -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P1_warm  = new Observable("max_e_energy_P1_warm" , "2e - E_{e,max} - Phase 1 warm"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P1_warm" ) ); max_e_energy_P1_warm -> SetLogScale(kFALSE); max_e_energy_P1_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1_warm -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P1_warm      = new Observable("cosTheta_P1_warm"     , "2e - Cos(#Theta) - Phase 1 warm"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P1_warm"     ) ); cosTheta_P1_warm     -> SetLogScale(kFALSE); cosTheta_P1_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1_warm     -> SetDrawGroup(kTRUE);

	Observable * tot_e_energy_P2_cold  = new Observable("tot_e_energy_P2_cold" , "2e - E_{e1} + E_{e2} - Phase 2 cold" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P2_cold" ) ); tot_e_energy_P2_cold -> SetLogScale(kFALSE); tot_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_cold -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P2_cold  = new Observable("min_e_energy_P2_cold" , "2e - E_{e,min} - Phase 2 cold"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P2_cold" ) ); min_e_energy_P2_cold -> SetLogScale(kFALSE); min_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_cold -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P2_cold  = new Observable("max_e_energy_P2_cold" , "2e - E_{e,max} - Phase 2 cold"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P2_cold" ) ); max_e_energy_P2_cold -> SetLogScale(kFALSE); max_e_energy_P2_cold -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_cold -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P2_cold      = new Observable("cosTheta_P2_cold"     , "2e - Cos(#Theta) - Phase 2 cold"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P2_cold"     ) ); cosTheta_P2_cold     -> SetLogScale(kFALSE); cosTheta_P2_cold     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_cold     -> SetDrawGroup(kTRUE);

	Observable * tot_e_energy_P2_warm  = new Observable("tot_e_energy_P2_warm" , "2e - E_{e1} + E_{e2} - Phase 2 warm" , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P2_warm" ) ); tot_e_energy_P2_warm -> SetLogScale(kFALSE); tot_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P2_warm -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P2_warm  = new Observable("min_e_energy_P2_warm" , "2e - E_{e,min} - Phase 2 warm"       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P2_warm" ) ); min_e_energy_P2_warm -> SetLogScale(kFALSE); min_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2_warm -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P2_warm  = new Observable("max_e_energy_P2_warm" , "2e - E_{e,max} - Phase 2 warm"       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P2_warm" ) ); max_e_energy_P2_warm -> SetLogScale(kFALSE); max_e_energy_P2_warm -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2_warm -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P2_warm      = new Observable("cosTheta_P2_warm"     , "2e - Cos(#Theta) - Phase 2 warm"     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P2_warm"     ) ); cosTheta_P2_warm     -> SetLogScale(kFALSE); cosTheta_P2_warm     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2_warm     -> SetDrawGroup(kTRUE);

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_cold" ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1_cold"    ) );
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1_cold"    ) );
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_cold"      ) );
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_cold"   ) );
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P1_cold"    ) );
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1_cold"    ) );   
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1_cold"    ) );   
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
	tot_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_cold" ) );      

	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_cold" ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2_cold"    ) );
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2_cold"    ) );
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_cold"      ) );
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_cold"   ) );
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2_cold"    ) );   
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2_cold"    ) );   
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
	tot_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_cold" ) );      

	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1_warm" ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1_warm"    ) );
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1_warm"    ) );
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1_warm"      ) );
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1_warm"   ) );
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1_warm"    ) );   
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1_warm"    ) );   
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
	tot_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1_warm" ) );      

	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2_warm" ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2_warm"    ) );
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2_warm"    ) );
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P2_warm"      ) );
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2_warm"   ) );
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2_warm"    ) );   
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2_warm"    ) );   
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
	tot_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2_warm" ) );      

	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_cold" ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P1_cold"    )); 
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P1_cold"    )); 
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_cold"      ));
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_cold"   ));
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1_cold"    ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P1_cold" ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P1_cold" ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P1_cold" ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P1_cold"   ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1_cold"      ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1_cold"      ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1_cold"      ));      
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P1_cold"      ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P1_cold"      ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P1_cold"      ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P1_cold"        ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P1_cold"   ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P1_cold"   ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P1_cold"   ));         
	min_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_cold" ));         

	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_cold" ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P2_cold"    )); 
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P2_cold"    )); 
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P2_cold"      ));
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_cold"   ));
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2_cold"    ));      
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P2_cold" ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P2_cold" ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P2_cold" ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P2_cold"   ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P2_cold"      ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P2_cold"      ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P2_cold"      ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P2_cold"        ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P2_cold"   ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P2_cold"   ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P2_cold"   ));         
	min_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_cold" ));         

	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P1_warm" ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P1_warm"    )); 
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P1_warm"    )); 
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1_warm"      ));
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1_warm"   ));
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1_warm"    ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P1_warm" ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P1_warm" ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P1_warm" ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P1_warm"   ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1_warm"      ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1_warm"      ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1_warm"      ));      
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P1_warm"      ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P1_warm"      ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P1_warm"      ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P1_warm"        ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P1_warm"   ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P1_warm"   ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P1_warm"   ));         
	min_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P1_warm" ));         

	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P2_warm" ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P2_warm"    )); 
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P2_warm"    )); 
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P2_warm"      ));
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2_warm"   ));
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2_warm"    ));      
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P2_warm" ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P2_warm" ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P2_warm" ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P2_warm"   ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P2_warm"      ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P2_warm"      ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P2_warm"      ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P2_warm"        ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P2_warm"   ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P2_warm"   ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P2_warm"   ));         
	min_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P2_warm" ));         

	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_cold" ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P1_cold"    )); 
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P1_cold"    )); 
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_cold"      ));
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_cold"   ));
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1_cold"    ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P1_cold" ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P1_cold" ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P1_cold" ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P1_cold"   ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1_cold"      ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1_cold"      ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1_cold"      ));      
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P1_cold"      ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P1_cold"      ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P1_cold"      ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P1_cold"        ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P1_cold"   ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P1_cold"   ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P1_cold"   ));         
	max_e_energy_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_cold" ));         

	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_cold" ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P2_cold"    )); 
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P2_cold"    )); 
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P2_cold"      ));
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_cold"   ));
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2_cold"    ));      
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P2_cold" ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P2_cold" ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P2_cold" ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P2_cold"   ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P2_cold"      ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P2_cold"      ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P2_cold"      ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P2_cold"        ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P2_cold"   ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P2_cold"   ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P2_cold"   ));         
	max_e_energy_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_cold" ));         

	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P1_warm" ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P1_warm"    )); 
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P1_warm"    )); 
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1_warm"      ));
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1_warm"   ));
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1_warm"    ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P1_warm" ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P1_warm" ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P1_warm" ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P1_warm"   ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1_warm"      ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1_warm"      ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1_warm"      ));      
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P1_warm"      ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P1_warm"      ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P1_warm"      ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P1_warm"        ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P1_warm"   ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P1_warm"   ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P1_warm"   ));         
	max_e_energy_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P1_warm" ));         

	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P2_warm" ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P2_warm"    )); 
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P2_warm"    )); 
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P2_warm"      ));
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2_warm"   ));
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2_warm"    ));      
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P2_warm" ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P2_warm" ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P2_warm" ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P2_warm"   ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P2_warm"      ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P2_warm"      ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P2_warm"      ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P2_warm"        ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P2_warm"   ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P2_warm"   ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P2_warm"   ));         
	max_e_energy_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P2_warm" ));         

	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P1_cold" ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P1_cold"    )); 
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P1_cold"    )); 
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_cold"      ));
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_cold"   ));
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1_cold"    ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P1_cold" ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P1_cold" ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P1_cold" ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P1_cold"   ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1_cold"      ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1_cold"      ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1_cold"      ));      
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P1_cold"      ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P1_cold"      ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P1_cold"      ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P1_cold"        ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P1_cold"   ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P1_cold"   ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P1_cold"   ));         
	cosTheta_P1_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P1_cold" ));     

	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P2_cold" ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P2_cold"    )); 
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P2_cold"    )); 
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P2_cold"      ));
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_cold"   ));
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_cold" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2_cold"    ));      
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P2_cold" ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P2_cold" ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P2_cold" ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P2_cold"   ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P2_cold"      ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P2_cold"      ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P2_cold"      ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P2_cold"        ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P2_cold"   ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P2_cold"   ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P2_cold"   ));         
	cosTheta_P2_cold -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P2_cold" ));     

	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P1_warm" ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P1_warm"    )); 
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P1_warm"    )); 
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1_warm"      ));
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1_warm"   ));
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1_warm"    ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P1_warm" ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P1_warm" ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P1_warm" ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P1_warm"   ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1_warm"      ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1_warm"      ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1_warm"      ));      
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P1_warm"      ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P1_warm"      ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P1_warm"      ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P1_warm"        ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P1_warm"   ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P1_warm"   ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P1_warm"   ));         
	cosTheta_P1_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P1_warm" ));     

	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P2_warm" ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P2_warm"    )); 
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P2_warm"    )); 
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , hcoll->Find( "Cd116_K40_h_cosTheta_P2_warm"      ));
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2_warm"   ));
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2_warm"    ));      
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P2_warm" ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P2_warm" ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P2_warm" ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P2_warm"   ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P2_warm"      ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P2_warm"      ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P2_warm"      ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P2_warm"        ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P2_warm"   ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P2_warm"   ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P2_warm"   ));         
	cosTheta_P2_warm -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P2_warm" ));     

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1_cold );	
	DataManagement::AddObservable( tot_e_energy_P2_cold );	
	DataManagement::AddObservable( tot_e_energy_P1_warm );	
	DataManagement::AddObservable( tot_e_energy_P2_warm );	

    //
	Fit::DoDrawScan();
	//Fit::DoDrawContour();
	Fit::Run("Minuit", "Minimize");
    
	cout << "T_{1/2}^{2\\nu} = " << 1/DataManagement::FindParameter("cBB")->GetValInit() << "+/-" << 1/DataManagement::FindParameter("cBB")->GetValInit()**2*DataManagement::FindParameter("cBB")->GetValError() << " 1e+19 y" << endl;
	
	tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps(" ); tot_e_energy_P1_cold -> SetLogScale(kTRUE);
    tot_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); min_e_energy_P1_cold -> SetLogScale(kTRUE);
	min_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); max_e_energy_P1_cold -> SetLogScale(kTRUE);
	max_e_energy_P1_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); cosTheta_P1_cold -> SetLogScale(kTRUE);
	cosTheta_P1_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );

	tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); tot_e_energy_P2_cold -> SetLogScale(kTRUE);
    tot_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); min_e_energy_P2_cold -> SetLogScale(kTRUE);
	min_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); max_e_energy_P2_cold -> SetLogScale(kTRUE);
	max_e_energy_P2_cold -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); cosTheta_P2_cold -> SetLogScale(kTRUE);
	cosTheta_P2_cold     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );

	tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); tot_e_energy_P1_warm -> SetLogScale(kTRUE);
    tot_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); min_e_energy_P1_warm -> SetLogScale(kTRUE);
	min_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); max_e_energy_P1_warm -> SetLogScale(kTRUE);
	max_e_energy_P1_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); cosTheta_P1_warm -> SetLogScale(kTRUE);
	cosTheta_P1_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );

	tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); tot_e_energy_P2_warm -> SetLogScale(kTRUE);
    tot_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); min_e_energy_P2_warm -> SetLogScale(kTRUE);
	min_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); max_e_energy_P2_warm -> SetLogScale(kTRUE);
	max_e_energy_P2_warm -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  );
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps"  ); cosTheta_P2_warm -> SetLogScale(kTRUE);
	cosTheta_P2_warm     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.ps)"  );	
	
}

