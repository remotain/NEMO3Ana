{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSampleBkg.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronTwoGammaHistos", "OneElectronTwoGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronTwoGammaInt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	// Load OneElectronThreeGammaHistos in HistoCollection
	HistoCollection * hcoll_3g= new HistoCollection("OneElectronThreeGammaHistos", "OneElectronThreeGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronThreeGammaInt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_3g->Load(fdir);
	}

	bool constrain_all = true;

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "Cd116_Tl208"     , "Cd116_Tl208"     ,  0  , 1.36224e-04 , 0.1 ) ); 
	DataManagement::AddParameter( new Parameter( "cCd116_Bi214"    , "cCd116_Bi214"    ,  1  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cCd116_Bi214"    ) -> SetFix();     
	DataManagement::AddParameter( new Parameter( "cMylar_Bi214"    , "cMylar_Bi214"    ,  2  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cMylar_Bi214"    ) -> SetFix();     
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P1" , "cSwire_Tl208_P1" ,  3  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Tl208_P1" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSwire_Tl208_P2" , "cSwire_Tl208_P2" ,  4  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Tl208_P2" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P1" , "cSwire_Bi214_P1" ,  5  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P1" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cSwire_Bi214_P2" , "cSwire_Bi214_P2" ,  6  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSwire_Bi214_P2" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P1" , "cSfoil_Bi214_P1" ,  7  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P1" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cSfoil_Bi214_P2" , "cSfoil_Bi214_P2" ,  8  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSfoil_Bi214_P2" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cFeShield_Bi214" , "cFeShield_Bi214" ,  9  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cFeShield_Bi214" ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cFeShield_Tl208" , "cFeShield_Tl208" , 10  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cFeShield_Tl208" ) -> SetFix(); 	
	DataManagement::AddParameter( new Parameter( "cCuTower_Co60"   , "cCuTower_Co60"   , 11  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cCuTower_Co60"   ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cAir_Bi214_P1"    , "cAir_Bi214_P1"  , 12  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cAir_Bi214_P1"   ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cAir_Tl208_P1"    , "cAir_Tl208_P1"  , 13  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cAir_Tl208_P1"   ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Bi214"      , "cPMT_Bi214"      , 14  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cPMT_Bi214"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_Tl208"      , "cPMT_Tl208"      , 15  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cPMT_Tl208"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cPMT_K40"        , "cPMT_K40"        , 16  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cPMT_K40"        ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cScint_K40"      , "cScint_K40"      , 17  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cScint_K40"      ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi210"    , "cSScin_Bi210"    , 18  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSScin_Bi210"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cSScin_Bi214"    , "cSScin_Bi214"    , 19  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cSScin_Bi214"    ) -> SetFix(); 
	DataManagement::AddParameter( new Parameter( "cMuMetal_Pa234m" , "cMuMetal_Pa234m" , 20  , 1.0 , 0.1 ) ); //DataManagement::FindParameter( "cMuMetal_Pa234m" ) -> SetFix(); 	
	
	
	DataManagement::AddGroup( new Group( "Tl208"     , "^{208}Tl"   )); DataManagement::FindGroup("Tl208"     ) -> SetFillColor( kOrange + 10 );
	DataManagement::AddGroup( new Group( "Bi214"     , "^{214}Bi"   )); DataManagement::FindGroup("Bi214"     ) -> SetFillColor( kGreen  +  0 );
	DataManagement::AddGroup( new Group( "Radon"     , "Radon"      )); DataManagement::FindGroup("Radon"     ) -> SetFillColor( kAzure  +  1 );
	DataManagement::AddGroup( new Group( "Externals" , "Externals"  )); DataManagement::FindGroup("Externals" ) -> SetFillColor( kOrange +  0 );
	
	
	//////////////////////////////////////////////////////////////////////////////               
	//	
	// Tl 
	//
	////////////////////////////////////////////////////Cd116_Bi212//////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208"     , "^{208}Tl Cd116"    , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "Cd116_Tl208" )     , 0.440                        )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228"     , "^{228}Ac Cd116"    , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "Cd116_Tl208" )     , 0.440/0.3594                 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Bi212"     , "^{212}Bi Cd116"    , DataManagement::FindDataSet( "Cd116_Bi212" ) , DataManagement::FindParameter( "Cd116_Tl208" )     , 0.440/0.3594                 )); DataManagement::FindComponent("Cd116_Bi212")->SetFillColor( kOrange + 3 );	
	DataManagement::AddComponent( new Component( "SWire_Tl208_P1"  , "^{208}Tl SWire P1" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P1" ) , 3.5E-03 , 0.4E-03 , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Tl208_P1"  )->SetFillColor( kAzure + 1 );
	DataManagement::AddComponent( new Component( "SWire_Tl208_P2"  , "^{208}Tl SWire P2" , DataManagement::FindDataSet( "SWire_Tl208" ) , DataManagement::FindParameter( "cSwire_Tl208_P2" ) , 2.9E-03 , 0.4E-03 , constrain_all , 1 )); DataManagement::FindComponent( "SWire_Tl208_P2"  )->SetFillColor( kAzure + 2 );

	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1" ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2" ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent("Cd116_Tl208"     ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent("Cd116_Ac228"     ));
	DataManagement::FindGroup("Tl208")->AddComponent( DataManagement::FindComponent("Cd116_Bi212"     ));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Bi 
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214"    ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kGreen +  0 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , DataManagement::FindParameter( "cCd116_Bi214" ) , 0.440*0.0004 , 0.440*0.0001 , constrain_all , 1 )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kGreen +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kGreen +  2 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214"    ) , DataManagement::FindParameter( "cMylar_Bi214" ) , 0.888*0.0028 , 0.888*0.0002 , constrain_all , 1 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kGreen +  3 );

	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Cd116_Pb214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Bi214"));
	DataManagement::FindGroup("Bi214")->AddComponent(DataManagement::FindComponent("Mylar_Pb214"));
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Rn in tracker chamber
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
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1" ) );
	DataManagement::FindGroup("Radon")->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1" ) );
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
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "^{210}Bi SScin     " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "cSScin_Bi210"    ) , 35          , 4          , constrain_all , 1 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kOrange +  0 );
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
	Observable * energy_score_fun_P1 = new Observable("energy_score_fun_P1 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 1 " , kPhaseOne , hcoll->Find( "Data_h_energy_score_fun_P1" ) ); energy_score_fun_P1 -> SetLogScale(kFALSE); energy_score_fun_P1 -> AddGroupAll(DataManagement::GetGroupCollection()); energy_score_fun_P1 -> SetDrawGroup(kTRUE); //energy_score_fun_P1 -> SetFitRangeLowEdge(-1);
	Observable * tot_energy_P1       = new Observable("tot_energy_P1"        , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 1 "              , kPhaseOne , hcoll->Find( "Data_h_tot_energy_P1"       ) ); tot_energy_P1       -> SetLogScale(kFALSE); tot_energy_P1       -> AddGroupAll(DataManagement::GetGroupCollection()); tot_energy_P1       -> SetDrawGroup(kTRUE);
	Observable * e_energy_P1         = new Observable("e_energy_P1"          , "1e2g - E_{e} - Phase 1 "                                                 , kPhaseOne , hcoll->Find( "Data_h_e_energy_P1"         ) ); e_energy_P1         -> SetLogScale(kFALSE); e_energy_P1         -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P1         -> SetDrawGroup(kTRUE);
	Observable * glow_energy_P1      = new Observable("glow_energy_P1"       , "1e2g - E_{#gamma,Low}  - Phase 1 "                                       , kPhaseOne , hcoll->Find( "Data_h_glow_energy_P1"      ) ); glow_energy_P1      -> SetLogScale(kFALSE); glow_energy_P1      -> AddGroupAll(DataManagement::GetGroupCollection()); glow_energy_P1      -> SetDrawGroup(kTRUE);	
	Observable * ghigh_energy_P1     = new Observable("ghigh_energy_P1"      , "1e2g - E_{#gamma,High}  - Phase 1 "                                      , kPhaseOne , hcoll->Find( "Data_h_ghigh_energy_P1"     ) ); ghigh_energy_P1     -> SetLogScale(kFALSE); ghigh_energy_P1     -> AddGroupAll(DataManagement::GetGroupCollection()); ghigh_energy_P1     -> SetDrawGroup(kTRUE);

	Observable * energy_score_fun_P2 = new Observable("energy_score_fun_P2 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 2 " , kPhaseTwo , hcoll->Find( "Data_h_energy_score_fun_P2" ) ); energy_score_fun_P2 -> SetLogScale(kFALSE); energy_score_fun_P2 -> AddGroupAll(DataManagement::GetGroupCollection()); energy_score_fun_P2 -> SetDrawGroup(kTRUE); //energy_score_fun_P2 -> SetFitRangeLowEdge(-1);
	Observable * tot_energy_P2       = new Observable("tot_energy_P2"        , "1e2g - E_{e} + E_{#gamma,Low} + E_{#gamma,High} - Phase 2 "              , kPhaseTwo , hcoll->Find( "Data_h_tot_energy_P2"       ) ); tot_energy_P2       -> SetLogScale(kFALSE); tot_energy_P2       -> AddGroupAll(DataManagement::GetGroupCollection()); tot_energy_P2       -> SetDrawGroup(kTRUE); 	
	Observable * e_energy_P2         = new Observable("e_energy_P2"          , "1e2g - E_{e} - Phase 2 "                                                 , kPhaseTwo , hcoll->Find( "Data_h_e_energy_P2"         ) ); e_energy_P2         -> SetLogScale(kFALSE); e_energy_P2         -> AddGroupAll(DataManagement::GetGroupCollection()); e_energy_P2         -> SetDrawGroup(kTRUE); 
	Observable * glow_energy_P2      = new Observable("glow_energy_P2"       , "1e2g - E_{#gamma,Low}  - Phase 2 "                                       , kPhaseTwo , hcoll->Find( "Data_h_glow_energy_P2"      ) ); glow_energy_P2      -> SetLogScale(kFALSE); glow_energy_P2      -> AddGroupAll(DataManagement::GetGroupCollection()); glow_energy_P2      -> SetDrawGroup(kTRUE);	 	
	Observable * ghigh_energy_P2     = new Observable("ghigh_energy_P2"      , "1e2g - E_{#gamma,High}  - Phase 2 "                                      , kPhaseTwo , hcoll->Find( "Data_h_ghigh_energy_P2"     ) ); ghigh_energy_P2     -> SetLogScale(kFALSE); ghigh_energy_P2     -> AddGroupAll(DataManagement::GetGroupCollection()); ghigh_energy_P2     -> SetDrawGroup(kTRUE); 
	
	Observable * tot_energy_3g       = new Observable("tot_energy_g3"        , "1e3g - E_{e} + E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} - Phase 1 & 2" , kAll      , hcoll_3g->Find( "Data_h_tot_energy"       ) ); tot_energy_3g       -> SetLogScale(kFALSE); tot_energy_3g       -> AddGroupAll(DataManagement::GetGroupCollection()); tot_energy_3g       -> SetDrawGroup(kTRUE); 
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////		
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P1"     ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P1"	  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_Pb214_VT_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P1"        ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_energy_score_fun_P1"    ));         
 	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_energy_score_fun_P1"    ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_energy_score_fun_P1"    ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_energy_score_fun_P1"    ));         

	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_energy_score_fun_P2"     ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll->Find( "Cd116_Bi214_h_energy_score_fun_P2"	  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll->Find( "Cd116_Pb214_VT_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_energy_score_fun_P2"        ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_energy_score_fun_P2"    ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_energy_score_fun_P2"    ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_energy_score_fun_P2"    ));         		
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_energy_score_fun_P2"    ));         		
			
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P1"     ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P1"	  ));
    tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_energy_P1"  ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll->Find( "SWire_Tl208_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P1"     ));	
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P1"     ));
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P1" ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll->Find( "Air_Bi214_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll->Find( "Air_Pb214_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll->Find( "Air_Tl208_h_tot_energy_P1"      ));      
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P1"      ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_tot_energy_P1"        ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_tot_energy_P1"   ));         
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_tot_energy_P1"   ));         		
	tot_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_tot_energy_P1"   ));         			

	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll->Find( "Cd116_Tl208_h_tot_energy_P2"     ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll->Find( "Cd116_Ac228_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll->Find( "Cd116_Bi212_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_tot_energy_P2"	  ));
    tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_Pb214_VT_h_tot_energy_P2"  ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll->Find( "Mylar_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll->Find( "Mylar_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll->Find( "SWire_Tl208_h_tot_energy_P2"     ));	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     ));		
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll->Find( "SWire_Pb214_h_tot_energy_P2"     ));	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll->Find( "SFoil_Pb214_h_tot_energy_P2"     ));
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll->Find( "FeShield_Bi214_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll->Find( "FeShield_Tl208_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll->Find( "FeShield_Ac228_h_tot_energy_P2" ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll->Find( "CuTower_Co60_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll->Find( "PMT_Bi214_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll->Find( "PMT_Tl208_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll->Find( "PMT_Ac228_h_tot_energy_P2"      ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll->Find( "PMT_K40_h_tot_energy_P2"        ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll->Find( "ScintInn_K40_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll->Find( "ScintOut_K40_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll->Find( "ScintPet_K40_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll->Find( "SScin_Bi210_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll->Find( "SScin_Bi214_h_tot_energy_P2"   ));         	
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll->Find( "SScin_Pb214_h_tot_energy_P2"   ));         
	tot_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll->Find( "MuMetal_Pa234m_h_tot_energy_P2"   ));         	

	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"          ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"          ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"          ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1"	  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"          ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"          ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"       ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"       ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"       ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"       ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"       ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"       ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"       ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"       ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1" ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"         ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"         ) , hcoll->Find( "Air_Bi214_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"         ) , hcoll->Find( "Air_Pb214_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"         ) , hcoll->Find( "Air_Tl208_h_e_energy_P1"      ));      
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"            ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"            ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"            ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1"      ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"              ) , hcoll->Find( "PMT_K40_h_e_energy_P1"        ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"         ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"         ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"         ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"          ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"          ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"          ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1"   ));         
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"       ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P1"   ));         	
                                                                                       
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"          ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"          ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"          ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	       ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2"	  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	       ) , hcoll->Find( "Cd116_Pb214_VT_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"          ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"          ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"       ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"       ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"       ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"       ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"       ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"       ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"       ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"       ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2" ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"         ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"            ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"            ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"            ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2"      ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"              ) , hcoll->Find( "PMT_K40_h_e_energy_P2"        ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"         ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"         ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"         ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"          ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"          ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2"   ));         
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"          ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2"   ));         		
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"       ) , hcoll->Find( "MuMetal_Pa234m_h_e_energy_P2"   ));         			

	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"       ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P1"     ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"       ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"       ) , hcoll->Find( "Cd116_Bi212_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	   ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P1"	 ));
    glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	   ) , hcoll->Find( "Cd116_Pb214_VT_h_glow_energy_P1"  ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P1"     ));	
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P1"     ));
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P1" ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"      ) , hcoll->Find( "Air_Tl208_h_glow_energy_P1"      ));      
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P1"      ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_glow_energy_P1"        ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"       ) , hcoll->Find( "SScin_Bi210_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"       ) , hcoll->Find( "SScin_Bi214_h_glow_energy_P1"   ));         
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"       ) , hcoll->Find( "SScin_Pb214_h_glow_energy_P1"   ));         		
	glow_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"    ) , hcoll->Find( "MuMetal_Pa234m_h_glow_energy_P1"   ));         			

	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"       ) , hcoll->Find( "Cd116_Tl208_h_glow_energy_P2"    ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"       ) , hcoll->Find( "Cd116_Ac228_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"       ) , hcoll->Find( "Cd116_Bi212_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	   ) , hcoll->Find( "Cd116_Bi214_h_glow_energy_P2"	   ));
    glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	   ) , hcoll->Find( "Cd116_Pb214_VT_h_glow_energy_P2" ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) , hcoll->Find( "SWire_Tl208_h_glow_energy_P2"    ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) , hcoll->Find( "SWire_Bi214_h_glow_energy_P2"    ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) , hcoll->Find( "SFoil_Bi214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) , hcoll->Find( "SWire_Pb214_h_glow_energy_P2"    ));	
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) , hcoll->Find( "SFoil_Pb214_h_glow_energy_P2"    ));
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_glow_energy_P2" ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_glow_energy_P2"      ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_glow_energy_P2"        ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"       ) , hcoll->Find( "SScin_Bi210_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"       ) , hcoll->Find( "SScin_Bi214_h_glow_energy_P2"   ));         
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"       ) , hcoll->Find( "SScin_Pb214_h_glow_energy_P2"   ));         		
	glow_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"    ) , hcoll->Find( "MuMetal_Pa234m_h_glow_energy_P2"   ));         			

	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P1"     ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	   ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P1"	 ));
    ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	   ) , hcoll->Find( "Cd116_Pb214_VT_h_ghigh_energy_P1"  ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , hcoll->Find( "SWire_Tl208_h_ghigh_energy_P1"     ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P1"     ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P1"     ));	
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P1"     ));
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P1" ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , hcoll->Find( "Air_Bi214_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"     ) , hcoll->Find( "Air_Pb214_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"     ) , hcoll->Find( "Air_Tl208_h_ghigh_energy_P1"      ));      
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P1"      ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P1"        ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_ghigh_energy_P1"   ));         
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_ghigh_energy_P1"   ));         		
	ghigh_energy_P1 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_ghigh_energy_P1"   ));         			

	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , hcoll->Find( "Cd116_Tl208_h_ghigh_energy_P2"     ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , hcoll->Find( "Cd116_Ac228_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , hcoll->Find( "Cd116_Bi212_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	   ) , hcoll->Find( "Cd116_Bi214_h_ghigh_energy_P2"	 ));
    ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	   ) , hcoll->Find( "Cd116_Pb214_VT_h_ghigh_energy_P2"  ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , hcoll->Find( "Mylar_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , hcoll->Find( "Mylar_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , hcoll->Find( "SWire_Tl208_h_ghigh_energy_P2"     ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , hcoll->Find( "SWire_Bi214_h_ghigh_energy_P2"     ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , hcoll->Find( "SFoil_Bi214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , hcoll->Find( "SWire_Pb214_h_ghigh_energy_P2"     ));	
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , hcoll->Find( "SFoil_Pb214_h_ghigh_energy_P2"     ));
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , hcoll->Find( "FeShield_Bi214_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , hcoll->Find( "FeShield_Tl208_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , hcoll->Find( "FeShield_Ac228_h_ghigh_energy_P2" ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , hcoll->Find( "CuTower_Co60_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , hcoll->Find( "PMT_Bi214_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , hcoll->Find( "PMT_Tl208_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , hcoll->Find( "PMT_Ac228_h_ghigh_energy_P2"      ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , hcoll->Find( "PMT_K40_h_ghigh_energy_P2"        ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , hcoll->Find( "ScintInn_K40_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , hcoll->Find( "ScintOut_K40_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , hcoll->Find( "ScintPet_K40_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , hcoll->Find( "SScin_Bi210_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , hcoll->Find( "SScin_Bi214_h_ghigh_energy_P2"   ));         
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"      ) , hcoll->Find( "SScin_Pb214_h_ghigh_energy_P2"   ));         		
	ghigh_energy_P2 -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , hcoll->Find( "MuMetal_Pa234m_h_ghigh_energy_P2"   ));         			

	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_3g->Find( "Cd116_Tl208_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_3g->Find( "Cd116_Ac228_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"        ) , hcoll_3g->Find( "Cd116_Bi212_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"        ) , hcoll_3g->Find( "Cd116_Bi214_h_tot_energy"    ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"        ) , hcoll_3g->Find( "Cd116_Pb214_VT_h_tot_energy"  ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_3g->Find( "Mylar_Bi214_h_tot_energy"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_3g->Find( "Mylar_Pb214_h_tot_energy"    ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"     ) , hcoll_3g->Find( "SWire_Tl208_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"     ) , hcoll_3g->Find( "SWire_Tl208_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"     ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"     ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"     ) , hcoll_3g->Find( "SWire_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"     ) , hcoll_3g->Find( "SFoil_Bi214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"     ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P1" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"     ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P1" ));    	  
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"     ) , hcoll_3g->Find( "SWire_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"     ) , hcoll_3g->Find( "SFoil_Pb214_h_tot_energy_P2" ));      
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_3g->Find( "FeShield_Bi214_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_3g->Find( "FeShield_Tl208_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_3g->Find( "FeShield_Ac228_h_tot_energy" ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_3g->Find( "CuTower_Co60_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_3g->Find( "PMT_Bi214_h_tot_energy"      ));         
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_3g->Find( "Air_Bi214_h_tot_energy_P1"   ));
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_3g->Find( "Air_Pb214_h_tot_energy_P1"   ));	
    tot_energy_3g -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_3g->Find( "Air_Tl208_h_tot_energy_P1"   ));
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_3g->Find( "PMT_Tl208_h_tot_energy"      ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_3g->Find( "PMT_Ac228_h_tot_energy"      ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_3g->Find( "PMT_K40_h_tot_energy"        ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_3g->Find( "ScintInn_K40_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_3g->Find( "ScintOut_K40_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_3g->Find( "ScintPet_K40_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_3g->Find( "SScin_Bi210_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"        ) , hcoll_3g->Find( "SScin_Bi214_h_tot_energy"   ));         
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"        ) , hcoll_3g->Find( "SScin_Pb214_h_tot_energy"   ));         			
	tot_energy_3g -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"     ) , hcoll_3g->Find( "MuMetal_Pa234m_h_tot_energy"   ));         				
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( energy_score_fun_P1 );	
	DataManagement::AddObservable( energy_score_fun_P2 );
	//DataManagement::AddObservable( tot_energy_3g );	
	//DataManagement::AddObservable( tot_energy_P1 );
	//DataManagement::AddObservable( tot_energy_P2 );

	//Fit::DoDrawScan();
	Fit::Run("Minuit", "Minimize");
    
	energy_score_fun_P1 -> Draw(); 											   (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf(");
	energy_score_fun_P1 -> SetLogScale(kTRUE);	energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	energy_score_fun_P2 -> Draw(); 											   (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	energy_score_fun_P2 -> SetLogScale(kTRUE);	energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	e_energy_P1         -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	e_energy_P1         -> SetLogScale(kTRUE);  e_energy_P1 -> Draw();         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	e_energy_P2         -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	e_energy_P2         -> SetLogScale(kTRUE);  e_energy_P2 -> Draw();         (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	tot_energy_P1       -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	tot_energy_P1       -> SetLogScale(kTRUE);  tot_energy_P1 -> Draw();       (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	tot_energy_P2       -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	tot_energy_P2       -> SetLogScale(kTRUE);  tot_energy_P2 -> Draw();       (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	glow_energy_P1      -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	glow_energy_P1      -> SetLogScale(kTRUE);  glow_energy_P1 -> Draw();      (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	glow_energy_P2      -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	glow_energy_P2      -> SetLogScale(kTRUE);  glow_energy_P2 -> Draw();      (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	ghigh_energy_P1     -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	ghigh_energy_P1     -> SetLogScale(kTRUE);  ghigh_energy_P1 -> Draw();     (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	ghigh_energy_P2     -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	ghigh_energy_P2     -> SetLogScale(kTRUE);  ghigh_energy_P2 -> Draw();     (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf");
	tot_energy_3g       -> Draw();                                             (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma.pdf)");

	energy_score_fun_P1 -> DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma_Details.pdf(");
	energy_score_fun_P2 -> DrawDetails(); (TPad*)gROOT->GetSelectedPad()->Print("FitOneElectronTwoGamma_Details.pdf)");	
	
	energy_score_fun_P1 -> PrintDetails();    
	energy_score_fun_P2 -> PrintDetails();

}