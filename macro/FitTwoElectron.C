{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos.root");
	//TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos_TrackLengh60cm.root");
	 TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150504/TwoElectronIntHistos_PInt_0_01.root");

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
	DataManagement::AddParameter( new Parameter( "cBB"       , "cBB"       ,  0 , 3.46e-01    , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cTl208"    , "Tl208"     ,  1 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cTl208" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cBi214"    , "Bi214"     ,  2 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cBi214" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cInt"      , "cInt"      ,  3 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cInt"   ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire"    , "cSwire"    ,  4 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cSwire" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSfoil"    , "cSfoil"    ,  5 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cSfoil" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cExt"      , "cExt"      ,  6 , 1.0 , 0.001 ) ); DataManagement::FindParameter( "cExt"   ) -> SetFix();
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
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208"  , "^{208}Tl Cd116"  , DataManagement::FindDataSet( "Cd116_Tl208"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*2.07070e-04 , 0.440*2.92895e-05 , false , 1 )); DataManagement::FindComponent("Cd116_Tl208"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Tl208"  )->SetLineColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Ac228"  , "^{228}Ac Cd116"  , DataManagement::FindDataSet( "Cd116_Ac228"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*2.07070e-04 , 0.440*2.92895e-05 , false , 1 )); DataManagement::FindComponent("Cd116_Ac228"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Ac228"  )->SetLineColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "Cd116_Pb211"  , "^{211}Pb Cd116"  , DataManagement::FindDataSet( "Cd116_Pb211"    ) , DataManagement::FindParameter( "cTl208" ) , 0.440*2.07070e-04 , 0.440*2.92895e-05 , false , 1 )); DataManagement::FindComponent("Cd116_Pb211"  )->SetFillColor( kOrange + 10 ); DataManagement::FindComponent("Cd116_Pb211"  )->SetLineColor( kOrange + 10 );
	
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Tl208"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Ac228"));
	DataManagement::FindGroup("Tl208")->AddComponent(DataManagement::FindComponent("Cd116_Pb211"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi-214
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Bi214"  , "^{214}Bi Cd116"  , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cBi214" ) , 0.440*2.82797e-04 , 0.440*8.57081e-05 , false , 1 )); DataManagement::FindComponent("Cd116_Bi214"  )->SetFillColor( kGreen +  0 ); DataManagement::FindComponent("Cd116_Bi214"  )->SetLineColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214"  , "^{214}Pb Cd116"  , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cBi214" ) , 0.440*2.82797e-04 , 0.440*8.57081e-05 , false , 1 )); DataManagement::FindComponent("Cd116_Pb214"  )->SetFillColor( kGreen +  0 ); DataManagement::FindComponent("Cd116_Pb214"  )->SetLineColor( kGreen +  0 );

	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Other Internals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Mylar_Bi214"  , "^{214}Bi Mylar"  , DataManagement::FindDataSet( "Mylar_Bi214"  ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.01074e-03 , 0.888*2.29057e-04 , false , 1 )); DataManagement::FindComponent("Mylar_Bi214"  )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Mylar_Bi214"  )->SetLineColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214"  , "^{214}Pb Mylar"  , DataManagement::FindDataSet( "Mylar_Pb214"  ) , DataManagement::FindParameter( "cInt" ) , 0.888*3.01074e-03 , 0.888*2.29057e-04 , false , 1 )); DataManagement::FindComponent("Mylar_Pb214"  )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Mylar_Pb214"  )->SetLineColor( kViolet + 0 );
	DataManagement::AddComponent( new Component( "Cd116_K40"    , "^{40}K Cd116"    , DataManagement::FindDataSet( "Cd116_K40"    ) , DataManagement::FindParameter( "cInt" ) ,       4.38531e-03 , 9.99822e-05       , false , 1 )); DataManagement::FindComponent("Cd116_K40"    )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Cd116_K40"    )->SetLineColor( kViolet + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m" , "^{234m}Pa Cd116" , DataManagement::FindDataSet( "Cd116_Pa234m" ) , DataManagement::FindParameter( "cInt" ) ,       2.59454e-03 , 4.38382e-05       , false , 1 )); DataManagement::FindComponent("Cd116_Pa234m" )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Cd116_Pa234m" )->SetLineColor( kViolet + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Cd113"  , "^{113}Cd Cd116"  , DataManagement::FindDataSet( "Cd116_Cd113m" ) , DataManagement::FindParameter( "cInt" ) ,       6.72143e-02 , 9.38386E-04       , false , 1 )); DataManagement::FindComponent("Cd116_Cd113"  )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent("Cd116_Cd113"  )->SetLineColor( kViolet + 0 );	
	DataManagement::AddComponent( new Component( "SWire_Bi210"  , "^{210}Bi SWire"  , DataManagement::FindDataSet( "SWire_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.40              , 0.12              , false , 1 )); DataManagement::FindComponent( "SWire_Bi210" )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent( "SWire_Bi210" )->SetLineColor( kViolet + 0 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210"  , "^{210}Bi SFoil"  , DataManagement::FindDataSet( "SFoil_Bi210"  ) , DataManagement::FindParameter( "cInt" ) , 2.57553e+00       , 6.65487e-03       , false , 1 )); DataManagement::FindComponent( "SFoil_Bi210" )->SetFillColor( kViolet + 0 ); DataManagement::FindComponent( "SFoil_Bi210" )->SetLineColor( kViolet + 0 );		
	
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("Mylar_Bi214"  ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("Mylar_Pb214"  ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("Cd116_K40"    ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("Cd116_Pa234m" ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("Cd116_Cd113"  ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("SWire_Bi210"  ) );
	DataManagement::FindGroup("Internals")->AddComponent( DataManagement::FindComponent("SFoil_Bi210"  ) );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn 
	//
	//////////////////////////////////////////////////////////////////////////////		
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1"  , "^{214}Bi SWire P1" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 6.57910e-01 , 3.71031e-02 , false , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Bi214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1"  , "^{214}Pb SWire P1" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 6.57910e-01 , 3.71031e-02 , false , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Pb214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2"  , "^{214}Bi SWire P2" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cSwire" ) , 9.29175e-02 , 4.40588e-03 , false , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Bi214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2"  , "^{214}Pb SWire P2" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cSwire" ) , 9.29175e-02 , 4.40588e-03 , false , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SWire_Pb214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"  , "^{214}Bi SFoil P1" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.49602e-02 , 1.97032e-03 , false , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Bi214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"  , "^{214}Pb SFoil P1" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.49602e-02 , 1.97032e-03 , false , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Pb214_P1" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"  , "^{214}Bi SFoil P2" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.10553e-03 , 2.40915e-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Bi214_P2" )->SetLineColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"  , "^{214}Pb SFoil P2" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cSfoil" ) , 1.10553e-03 , 2.40915e-04 , false , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2" )->SetFillColor( kAzure + 1 ); DataManagement::FindComponent( "SFoil_Pb214_P2" )->SetLineColor( kAzure + 1 );
	
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
	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield  ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , DataManagement::FindParameter( "cExt" ) ,7360.00     , 200.00      , false , 1 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl  " , DataManagement::FindDataSet( "FeShield_Tl208" ) , DataManagement::FindParameter( "cExt" ) , 484.00     ,  24.00      , false , 1 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kOrange + 10 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac  " , DataManagement::FindDataSet( "FeShield_Ac228" ) , DataManagement::FindParameter( "cExt" ) , 484.00     ,  24.00      , false , 1 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kOrange + 10 );	
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "cExt" ) ,9.12090e+01 , 1.07228e+01 , false , 1 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kOrange + 9 );	
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,5.92364e+02 , 2.10605e+01 , false , 1 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "cExt" ) ,5.92364e+02 , 2.10605e+01 , false , 1 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,1.35743e+01 , 2.91453e+00 , false , 1 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kOrange + 8 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "cExt" ) ,3.65058e+02 , 5.28742e+00 , false , 1 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "cExt" ) ,3.69815e+01 , 5.64289e-01 , false , 1 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "cExt" ) ,3.69815e+01 , 5.64289e-01 , false , 1 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "cExt" ) ,1.02617e+03 , 3.74992e+01 , false , 1 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange + 7 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "cExt" ) ,8.15671e+00 , 3.76417e-01 , false , 1 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "cExt" ) ,8.15671e+00 , 3.76417e-01 , false , 1 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "cExt" ) ,8.15671e+00 , 3.76417e-01 , false , 1 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange + 6 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cExt" ) ,2.05311e+01 , 6.90944e-01 , false , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange + 0 );
	
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
	Observable * tot_e_energy_P1  = new Observable("tot_e_energy_P1" , "2e - E_{e1} + E_{e2} - Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_tot_e_energy_P1" ) ); tot_e_energy_P1 -> SetLogScale(kFALSE); tot_e_energy_P1 -> AddGroupAll(DataManagement::GetGroupCollection()); tot_e_energy_P1 -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P1  = new Observable("min_e_energy_P1" , "2e - E_{e,min} - Phase 1 "       , kPhaseOne , hcoll->Find( "Data_h_min_e_energy_P1" ) ); min_e_energy_P1 -> SetLogScale(kFALSE); min_e_energy_P1 -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P1 -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P1  = new Observable("max_e_energy_P1" , "2e - E_{e,max} - Phase 1 "       , kPhaseOne , hcoll->Find( "Data_h_max_e_energy_P1" ) ); max_e_energy_P1 -> SetLogScale(kFALSE); max_e_energy_P1 -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P1 -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P1      = new Observable("cosTheta_P1"     , "2e - Cos(#Theta) - Phase 1 "     , kPhaseOne , hcoll->Find( "Data_h_cosTheta_P1"     ) ); cosTheta_P1     -> SetLogScale(kFALSE); cosTheta_P1     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P1     -> SetDrawGroup(kTRUE);

	Observable * tot_e_energy_P2  = new Observable("tot_e_energy_P2" , "2e - E_{e1} + E_{e2} - Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_tot_e_energy_P2" ) ); tot_e_energy_P2 -> SetLogScale(kFALSE); tot_e_energy_P2 -> AddGroupAll(DataManagement::GetGroupCollection());	tot_e_energy_P2 -> SetDrawGroup(kTRUE);
	Observable * min_e_energy_P2  = new Observable("min_e_energy_P2" , "2e - E_{e,min} - Phase 2 "       , kPhaseTwo , hcoll->Find( "Data_h_min_e_energy_P2" ) ); min_e_energy_P2 -> SetLogScale(kFALSE); min_e_energy_P2 -> AddGroupAll(DataManagement::GetGroupCollection()); min_e_energy_P2 -> SetDrawGroup(kTRUE);
	Observable * max_e_energy_P2  = new Observable("max_e_energy_P2" , "2e - E_{e,max} - Phase 2 "       , kPhaseTwo , hcoll->Find( "Data_h_max_e_energy_P2" ) ); max_e_energy_P2 -> SetLogScale(kFALSE); max_e_energy_P2 -> AddGroupAll(DataManagement::GetGroupCollection()); max_e_energy_P2 -> SetDrawGroup(kTRUE);
	Observable * cosTheta_P2      = new Observable("cosTheta_P2"     , "2e - Cos(#Theta) - Phase 2 "     , kPhaseTwo , hcoll->Find( "Data_h_cosTheta_P2"     ) ); cosTheta_P2     -> SetLogScale(kFALSE); cosTheta_P2     -> AddGroupAll(DataManagement::GetGroupCollection()); cosTheta_P2     -> SetDrawGroup(kTRUE);
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1" ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1"    ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1"    ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P1"      ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P1"    ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P1"    ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P1" ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P1" ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P1" ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P1"   ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_tot_e_energy_P1"      ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_tot_e_energy_P1"      ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_tot_e_energy_P1"      ) );   
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P1"      ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P1"      ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P1"      ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P1"        ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P1"   ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P1"   ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P1"   ) );      
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P1" ) );      

	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P1" ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P1"    )); 
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P1"    )); 
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P1"      ));
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P1"   ));
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P1"    ));
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P1"    ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P1" ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P1" ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P1" ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P1"   ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_min_e_energy_P1"      ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_min_e_energy_P1"      ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_min_e_energy_P1"      ));      
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P1"      ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P1"      ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P1"      ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P1"        ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P1"   ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P1"   ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P1"   ));         
	min_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P1" ));         

	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P1" ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P1"    )); 
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P1"    )); 
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P1"      ));
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P1"   ));
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P1"    ));
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P1"    ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P1" ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P1" ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P1" ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P1"   ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_max_e_energy_P1"      ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_max_e_energy_P1"      ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_max_e_energy_P1"      ));      
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P1"      ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P1"      ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P1"      ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P1"        ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P1"   ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P1"   ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P1"   ));         
	max_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P1" ));         

	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P1" ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P1"    )); 
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P1"    )); 
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_cosTheta_P1"      ));
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P1"   ));
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P1"    ));
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P1"    ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P1" ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P1" ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P1" ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P1"   ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_cosTheta_P1"      ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_cosTheta_P1"      ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_cosTheta_P1"      ));      
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P1"      ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P1"      ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P1"      ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P1"        ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P1"   ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P1"   ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P1"   ));         
	cosTheta_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P1" ));     

	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2" ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2"    ));
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2"    ));
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_tot_e_energy_P2"      ));
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_tot_e_energy_P2"   ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P2"    ));      
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P2" ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P2" ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P2" ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_tot_e_energy_P2"   ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_tot_e_energy_P2"      ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_tot_e_energy_P2"      ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_tot_e_energy_P2"      ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_tot_e_energy_P2"        ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_tot_e_energy_P2"   ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_tot_e_energy_P2"   ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_tot_e_energy_P2"   ));         
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy_P2" ));         

	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_min_e_energy_P2" ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_min_e_energy_P2"    )); 
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_min_e_energy_P2"    )); 
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_min_e_energy_P2"      ));
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_min_e_energy_P2"   ));
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_min_e_energy_P2"    ));
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_min_e_energy_P2"    ));      
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_min_e_energy_P2" ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_min_e_energy_P2" ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_min_e_energy_P2" ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_min_e_energy_P2"   ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_min_e_energy_P2"      ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_min_e_energy_P2"      ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_min_e_energy_P2"      ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_min_e_energy_P2"        ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_min_e_energy_P2"   ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_min_e_energy_P2"   ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_min_e_energy_P2"   ));         
	min_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_min_e_energy_P2" ));         

	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_max_e_energy_P2" ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_max_e_energy_P2"    )); 
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_max_e_energy_P2"    )); 
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_max_e_energy_P2"      ));
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_max_e_energy_P2"   ));
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_max_e_energy_P2"    ));
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_max_e_energy_P2"    ));      
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_max_e_energy_P2" ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_max_e_energy_P2" ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_max_e_energy_P2" ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_max_e_energy_P2"   ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_max_e_energy_P2"      ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_max_e_energy_P2"      ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_max_e_energy_P2"      ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_max_e_energy_P2"        ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_max_e_energy_P2"   ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_max_e_energy_P2"   ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_max_e_energy_P2"   ));         
	max_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_max_e_energy_P2" ));         

	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"      ) , hcoll->Find( "Cd116_Pb211_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , hcoll->Find( "Cd116_Bi214_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , hcoll->Find( "Cd116_Pb214_VT_h_cosTheta_P2" ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_cosTheta_P2"    )); 
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_cosTheta_P2"    )); 
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"        ) , hcoll->Find( "Cd116_K40_h_cosTheta_P2"      ));
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"     ) , hcoll->Find( "Cd116_Pa234m_h_cosTheta_P2"   ));
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Cd113"      ) , hcoll->Find( "Cd116_Cd113_h_cosTheta_P2"    ));
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"      ) , hcoll->Find( "SFoil_Bi210_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"      ) , hcoll->Find( "SWire_Bi210_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_cosTheta_P2"    ));      
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_cosTheta_P2" ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_cosTheta_P2" ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_cosTheta_P2" ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_cosTheta_P2"   ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_cosTheta_P2"      ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_cosTheta_P2"      ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_cosTheta_P2"      ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_cosTheta_P2"        ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_cosTheta_P2"   ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_cosTheta_P2"   ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_cosTheta_P2"   ));         
	cosTheta_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , hcoll->Find( "Cd116_2b2n_m14_h_cosTheta_P2" ));     


	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( tot_e_energy_P1 );	
	DataManagement::AddObservable( tot_e_energy_P2 );	
    //
	Fit::DoDrawScan();
	//Fit::DoDrawContour();
	Fit::Run("Minuit", "Minimize");
    
	cout << "T_{1/2}^{2\\nu} = " << 1/DataManagement::FindParameter("cBB")->GetValInit() << "+/-" << 1/DataManagement::FindParameter("cBB")->GetValInit()**2*DataManagement::FindParameter("cBB")->GetValError() << " 1e+19 y" << endl;
	
	tot_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps(" ); tot_e_energy_P1 -> SetLogScale(kTRUE);
    tot_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	min_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); min_e_energy_P1 -> SetLogScale(kTRUE);
	min_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	max_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); max_e_energy_P1 -> SetLogScale(kTRUE);
	max_e_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	cosTheta_P1     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); cosTheta_P1 -> SetLogScale(kTRUE);
	cosTheta_P1     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );

	tot_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps(" ); tot_e_energy_P2 -> SetLogScale(kTRUE);
    tot_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	min_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); min_e_energy_P2 -> SetLogScale(kTRUE);
	min_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	max_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); max_e_energy_P2 -> SetLogScale(kTRUE);
	max_e_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );
	cosTheta_P2     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  ); cosTheta_P2 -> SetLogScale(kTRUE);
	cosTheta_P2     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps"  );

	tot_e_energy_P2 -> DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectron.ps)");

	
	
}

