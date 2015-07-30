{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_2eExt = new HistoCollection("TwoElectronExtHistos", "TwoElectronExtHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/TwoElectronExtHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_2eExt->Load(fdir);
	}

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll_1e1gExt = new HistoCollection("OneElectronOneGammaExt", "OneElectronOneGammaExt");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150107/OneElectronOneGammaExt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_1e1gExt->Load(fdir);
	}
	
	// Load OneElectron in HistoCollection
	HistoCollection * hcoll_1e = new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150217/OneElectronHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_1e->Load(fdir);
	}

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll_1e2gInt= new HistoCollection("OneElectronTwoGammaHistos", "OneElectronTwoGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronTwoGammaInt_Eg150keV.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll_1e2gInt->Load(fdir);
	}


	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit parameters
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddParameter( new Parameter( "PMT_K40"      , "PMT_K40"        ,  0 , 1.25226e+03 , 0.01 ) ); //DataManagement::FindParameter( "PMT_K40"       ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Scint_K40"    , "Scint_K40"      ,  1 , 6.17355e+00 , 0.01 ) ); //DataManagement::FindParameter( "Scint_K40"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Bi214"    , "PMT_Bi214"      ,  2 , 3.55170e+02 , 0.01 ) ); //DataManagement::FindParameter( "PMT_Bi214"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Bi214_P1" , "Air_Bi214_P1"   ,  3 , 5.32364e+02 , 0.01 ) ); //DataManagement::FindParameter( "Air_Bi214_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "PMT_Tl208"    , "PMT_Tl208"      ,  4 , 3.63310e+01 , 0.01 ) ); //DataManagement::FindParameter( "PMT_Tl208"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Air_Tl208_P1" , "Air_Tl208_P1"   ,  5 , 1.10966e+01 , 0.01 ) ); //DataManagement::FindParameter( "Air_Tl208_P1"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "CuTower_Co60" , "CuTower_Co60"   ,  6 , 1.13869e+02 , 0.01 ) ); //DataManagement::FindParameter( "CuTower_Co60"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SScin_Bi210"  , "SScin_Bi210"    ,  7 , 2.42138e+01 , 0.01 ) ); //DataManagement::FindParameter( "SScin_Bi210"   ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Tl208"  , "Cd116_Tl208"    ,  8 , 1.35815e-04 , 0.01 ) ); DataManagement::FindParameter( "Cd116_Tl208"  ) -> SetLimit(0,10.); 
	DataManagement::AddParameter( new Parameter( "Cd116_K40"    , "Cd116_K40"      ,  9 , 4.42795e-03 , 0.01 ) ); //DataManagement::FindParameter( "Cd116_K40"     ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "Cd116_Pa234m" , "Cd116_Pa234m"   , 10 , 2.38999e-03 , 0.01 ) ); //DataManagement::FindParameter( "Cd116_Pa234m"  ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "SFoil_Bi210"  , "SFoil_Bi210"    , 11 , 2.56986e+00 , 0.01 ) ); //DataManagement::FindParameter( "SFoil_Bi210" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "cSWire_Bi210" , "cSWire_Bi210"   , 12 , 1.10455e+00 , 0.01 ) ); //DataManagement::FindParameter( "cSWire_Bi210" ) -> SetFix();
	DataManagement::AddParameter( new Parameter( "cRn"          , "cRn"            , 13 , 9.95346e-01 , 0.01 ) ); //DataManagement::FindParameter( "cRn"  ) -> SetFix(); 
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internals
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_2b2n_m14" , "2#nu#beta#beta Cd116" , DataManagement::FindDataSet( "Cd116_2b2n_m14" ) , DataManagement::GetNormBB()/2.89e19, 0.1*DataManagement::GetNormBB()/2.89e19 ));              DataManagement::FindComponent("Cd116_2b2n_m14" )  ->SetFillColor( kViolet + 10 );	
	DataManagement::AddComponent( new Component( "Cd116_K40"      , "^{40}K Cd116"         , DataManagement::FindDataSet( "Cd116_K40"      ) , DataManagement::FindParameter( "Cd116_K40"    ) , 1. )); DataManagement::FindComponent("Cd116_K40"      ) -> SetFillColor( kViolet + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pa234m"   , "^{234m}Pa Cd116"      , DataManagement::FindDataSet( "Cd116_Pa234m"   ) , DataManagement::FindParameter( "Cd116_Pa234m" ) , 1. )); DataManagement::FindComponent("Cd116_Pa234m"   ) -> SetFillColor( kViolet + 2 );	
	DataManagement::AddComponent( new Component( "SFoil_Bi210"    , "^{210}Bi SFoil"       , DataManagement::FindDataSet( "SFoil_Bi210"    ) , DataManagement::FindParameter( "SFoil_Bi210"  ) , 1. )); DataManagement::FindComponent("SFoil_Bi210"    ) -> SetFillColor( kGreen + 2 );	
	DataManagement::AddComponent( new Component( "SWire_Bi210"    , "^{210}Bi SWire"       , DataManagement::FindDataSet( "SWire_Bi210"    ) , DataManagement::FindParameter( "cSWire_Bi210"  ) , 2.4, 0.12, true )); DataManagement::FindComponent("SWire_Bi210"    ) -> SetFillColor( kGreen + 1 );	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Internal
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "Cd116_Tl208" , "^{208}Tl Cd116" , DataManagement::FindDataSet( "Cd116_Tl208" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Tl208")->SetFillColor( kOrange + 0 );	
	DataManagement::AddComponent( new Component( "Cd116_Ac228" , "^{228}Ac Cd116" , DataManagement::FindDataSet( "Cd116_Ac228" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Ac228")->SetFillColor( kOrange + 1 );	
	DataManagement::AddComponent( new Component( "Cd116_Pb211"  , "^{211}Pb Cd116", DataManagement::FindDataSet( "Cd116_Pb211" ) , DataManagement::FindParameter( "Cd116_Tl208" ) , 0.440 )); DataManagement::FindComponent("Cd116_Pb211")->SetFillColor( kOrange + 3 );	
	
	DataManagement::AddComponent( new Component( "Cd116_Bi214" , "^{214}Bi Cd116" , DataManagement::FindDataSet( "Cd116_Bi214" )    , 0.440*2.82801e-04 , 0.440*8.53952e-05            )); DataManagement::FindComponent("Cd116_Bi214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Cd116_Pb214" , "^{214}Pb Cd116" , DataManagement::FindDataSet( "Cd116_pb214_VT" ) , 0.440*2.82801e-04 , 0.440*8.53952e-05            )); DataManagement::FindComponent("Cd116_Pb214")->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "Mylar_Bi214" , "^{214}Bi Mylar" , DataManagement::FindDataSet( "Mylar_Bi214" )    , 0.887680542*3.01073e-03, 0.887680542*2.28492e-04 )); DataManagement::FindComponent("Mylar_Bi214")->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "Mylar_Pb214" , "^{214}Pb Mylar" , DataManagement::FindDataSet( "Mylar_Pb214" )    , 0.887680542*3.01073e-03, 0.887680542*2.28492e-04 )); DataManagement::FindComponent("Mylar_Pb214")->SetFillColor( kOrange +  0 );
	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the components fixed by the 1e1a channel
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_IN"  , "^{214}Bi SWire P1 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 6.62169e-01 , 9.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P1_OUT" , "^{214}Bi SWire P1 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 6.53893e-01 , 8.6e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_IN"  , "^{214}Bi SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.22140e-02 , 3.01516e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P1_OUT" , "^{214}Bi SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.69628e-02 , 2.58033e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_IN"  , "^{214}Bi SWire P2 In " , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 8.53192e-02 , 2.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Bi214_P2_OUT" , "^{214}Bi SWire P2 Out" , DataManagement::FindDataSet( "SWire_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.00534e-01 , 2.2e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Bi214_P2_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_IN"  , "^{214}Bi SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.14207e-03 , 3.52491e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Bi214_P2_OUT" , "^{214}Bi SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Bi214" ) , DataManagement::FindParameter( "cRn" ) , 1.07416e-03 , 3.27150e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" )->SetFillColor( kAzure +  4 );	

	DataManagement::AddComponent( new Component( "SWire_Pb214_P1_IN"  , "^{214}Pb SWire P1 In " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 6.62169e-01 , 9.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P1_OUT" , "^{214}Pb SWire P1 Out" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 6.53893e-01 , 8.6e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P1_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1_IN"  , "^{214}Pb SFoil P1 In " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 1.22140e-02 , 3.01516e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P1_OUT" , "^{214}Pb SFoil P1 Out" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 1.69628e-02 , 2.58033e-03 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2_IN"  , "^{214}Pb SWire P2 In " , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 8.53192e-02 , 2.7e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2_IN"  )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "SWire_Pb214_P2_OUT" , "^{214}Pb SWire P2 Out" , DataManagement::FindDataSet( "SWire_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 1.00534e-01 , 2.2e-03     , true , 1 )); DataManagement::FindComponent( "SWire_Pb214_P2_OUT" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2_IN"  , "^{214}Pb SFoil P2 In " , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 1.14207e-03 , 3.52491e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "SFoil_Pb214_P2_OUT" , "^{214}Pb SFoil P2 Out" , DataManagement::FindDataSet( "SFoil_Pb214" ) , DataManagement::FindParameter( "cRn" ) , 1.07416e-03 , 3.27150e-04 , true , 1 )); DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" )->SetFillColor( kAzure +  4 );	

	DataManagement::AddComponent( new Component( "FeShield_Bi214" , "FeShield ^{214}Bi " , DataManagement::FindDataSet( "FeShield_Bi214" ) , 7360.00 , 200.00 )); DataManagement::FindComponent( "FeShield_Bi214" )->SetFillColor( kGreen  +  2 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208" , "FeShield ^{208}Tl " , DataManagement::FindDataSet( "FeShield_Tl208" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Tl208" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228" , "FeShield ^{228}Ac " , DataManagement::FindDataSet( "FeShield_Ac228" ) ,  484.00 ,  24.00 )); DataManagement::FindComponent( "FeShield_Ac228" )->SetFillColor( kAzure +  5 );

	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Externals
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddComponent( new Component( "PMT_K40"        , "PMT ^{40}K         " , DataManagement::FindDataSet( "PMT_K40"        ) , DataManagement::FindParameter( "PMT_K40"        ) ,  1.00 )); DataManagement::FindComponent( "PMT_K40"        )->SetFillColor( kOrange  +  10 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"   , "Scint Inn ^{40}K   " , DataManagement::FindDataSet( "ScintInn_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintInn_K40"   )->SetFillColor( kOrange  +  8 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"   , "Scint Out ^{40}K   " , DataManagement::FindDataSet( "ScintOut_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintOut_K40"   )->SetFillColor( kOrange  -  3 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"   , "Scint Pet ^{40}K   " , DataManagement::FindDataSet( "ScintPet_K40"   ) , DataManagement::FindParameter( "Scint_K40"      ) ,  1.00 )); DataManagement::FindComponent( "ScintPet_K40"   )->SetFillColor( kOrange  +  0 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"      , "PMT ^{214}Bi       " , DataManagement::FindDataSet( "PMT_Bi214"      ) , DataManagement::FindParameter( "PMT_Bi214"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Bi214"      )->SetFillColor( kGreen  +  1 );
	DataManagement::AddComponent( new Component( "Air_Bi214_P1"   , "LSM Air ^{214}Bi P1" , DataManagement::FindDataSet( "Air_Bi214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Bi214_P1"   )->SetFillColor( kGreen  +  0 );
	DataManagement::AddComponent( new Component( "Air_Pb214_P1"   , "LSM Air ^{214}Pb P1" , DataManagement::FindDataSet( "Air_Pb214"      ) , DataManagement::FindParameter( "Air_Bi214_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Pb214_P1"   )->SetFillColor( kGreen  +  0 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"      , "PMT ^{208}Tl       " , DataManagement::FindDataSet( "PMT_Tl208"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Tl208"      )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"      , "PMT ^{228}Ac       " , DataManagement::FindDataSet( "PMT_Ac228"      ) , DataManagement::FindParameter( "PMT_Tl208"      ) ,  1.00 )); DataManagement::FindComponent( "PMT_Ac228"      )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component( "Air_Tl208_P1"   , "LSM Air ^{208}Tl P1" , DataManagement::FindDataSet( "Air_Tl208"      ) , DataManagement::FindParameter( "Air_Tl208_P1"   ) ,  1.00 )); DataManagement::FindComponent( "Air_Tl208_P1"   )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"   , "CuTower ^{60}Co    " , DataManagement::FindDataSet( "CuTower_Co60"   ) , DataManagement::FindParameter( "CuTower_Co60"   ) ,  1.00 )); DataManagement::FindComponent( "CuTower_Co60"   )->SetFillColor( kViolet +  0 );
	DataManagement::AddComponent( new Component( "SScin_Bi210"    , "SScint ^{210}Bi    " , DataManagement::FindDataSet( "SScin_Bi210"    ) , DataManagement::FindParameter( "SScin_Bi210"    ) , 1.00 )); DataManagement::FindComponent( "SScin_Bi210"    )->SetFillColor( kViolet +  1 );
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1         = new Observable("e_energy_P1"       , "E_{e} - Phase 1"                                     , kPhaseOne , hcoll_1e      -> Find( "Data_h_e_energy_P1"     ) ); e_energy_P1       -> SetLogScale(kFALSE);
	Observable * e_energy_P2         = new Observable("e_energy_P2"       , "E_{e} - Phase 2"                                     , kPhaseTwo , hcoll_1e      -> Find( "Data_h_e_energy_P2"     ) ); e_energy_P2       -> SetLogScale(kFALSE);	
	Observable * tot_e_energy_P1     = new Observable("tot_e_energy_P1"   , "2e ext - total electron energy - Phase 1 "           , kPhaseOne , hcoll_2eExt   -> Find( "Data_h_tot_e_energy_P1" ) ); tot_e_energy_P1   -> SetLogScale(kFALSE);
	Observable * tot_e_energy_P2     = new Observable("tot_e_energy_P2"   , "2e ext - total electron energy - Phase 2 "           , kPhaseTwo , hcoll_2eExt   -> Find( "Data_h_tot_e_energy_P2" ) ); tot_e_energy_P2   -> SetLogScale(kFALSE);	
	Observable * tot_e_g_energy_P1   = new Observable("tot_e_g_energy_P1" , "1e1g ext - total electron + gamma energy - Phase 1 " , kPhaseOne , hcoll_1e1gExt -> Find( "Data_h_tot_energy_P1"   ) ); tot_e_g_energy_P1 -> SetLogScale(kFALSE);
	Observable * tot_e_g_energy_P2   = new Observable("tot_e_g_energy_P2" , "1e1g ext - total electron + gamma energy - Phase 2 " , kPhaseTwo , hcoll_1e1gExt -> Find( "Data_h_tot_energy_P2"   ) ); tot_e_g_energy_P2 -> SetLogScale(kFALSE);	
	Observable * energy_score_fun_P1 = new Observable("energy_score_fun_P1 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 1 " , kPhaseOne , hcoll_1e2gInt->Find( "Data_h_energy_score_fun_P1" ) ); energy_score_fun_P1 -> SetLogScale(kFALSE);
	Observable * energy_score_fun_P2 = new Observable("energy_score_fun_P2 " , "1e2g - [E_{e} + 1.5 * (E_{#gamma,Low} + E_{#gamma,High}) - 4]- Phase 2 " , kPhaseTwo , hcoll_1e2gInt->Find( "Data_h_energy_score_fun_P2" ) ); energy_score_fun_P2 -> SetLogScale(kFALSE);
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_1e->Find( "Cd116_Tl208_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_1e->Find( "Cd116_Ac228_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll_1e->Find( "Cd116_Pb211_h_e_energy_P1"     ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll_1e->Find( "Cd116_Bi214_h_e_energy_P1"	  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll_1e->Find( "Cd116_pb214_VT_h_e_energy_P1"  ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_1e->Find( "Mylar_Bi214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_1e->Find( "Mylar_Pb214_h_e_energy_P1"     ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_1e->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_1e->Find( "SWire_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll_1e->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll_1e->Find( "SFoil_Bi214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll_1e->Find( "SWire_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll_1e->Find( "SWire_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll_1e->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll_1e->Find( "SFoil_Pb214_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e->Find( "FeShield_Bi214_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e->Find( "FeShield_Tl208_h_e_energy_P1"  ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e->Find( "FeShield_Ac228_h_e_energy_P1"  ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll_1e->Find( "PMT_K40_h_e_energy_P1"         ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e->Find( "ScintOut_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e->Find( "ScintPet_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e->Find( "ScintInn_K40_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll_1e->Find( "PMT_Bi214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_1e->Find( "Air_Bi214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_1e->Find( "Air_Pb214_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e->Find( "PMT_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e->Find( "PMT_Ac228_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_1e->Find( "Air_Tl208_h_e_energy_P1"       ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e->Find( "CuTower_Co60_h_e_energy_P1"    ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll_1e->Find( "Cd116_2b2n_m4_h_e_energy_P1"   ));	
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"          ) , hcoll_1e->Find( "Cd116_K40_h_e_energy_P1"       ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"       ) , hcoll_1e->Find( "Cd116_Pa234m_h_e_energy_P1"    ));
    e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e->Find( "SScin_Bi210_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll_1e->Find( "SWire_Bi210_h_e_energy_P1"     ));
	e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"        ) , hcoll_1e->Find( "SFoil_Bi210_h_e_energy_P1"     ));

	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_1e->Find( "Cd116_Tl208_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_1e->Find( "Cd116_Ac228_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll_1e->Find( "Cd116_Pb211_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll_1e->Find( "Cd116_Bi214_h_e_energy_P2"     ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll_1e->Find( "Cd116_pb214_VT_h_e_energy_P2"  ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_1e->Find( "Mylar_Bi214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_1e->Find( "Mylar_Pb214_h_e_energy_P2"     ));	
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_1e->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_1e->Find( "SWire_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll_1e->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll_1e->Find( "SFoil_Bi214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll_1e->Find( "SWire_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll_1e->Find( "SWire_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll_1e->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll_1e->Find( "SFoil_Pb214_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e->Find( "FeShield_Bi214_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e->Find( "FeShield_Tl208_h_e_energy_P2"  ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e->Find( "FeShield_Ac228_h_e_energy_P2"  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"   	     ) , hcoll_1e->Find( "PMT_K40_h_e_energy_P2"   	  ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e->Find( "ScintOut_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e->Find( "ScintPet_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e->Find( "ScintInn_K40_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"   	     ) , hcoll_1e->Find( "PMT_Bi214_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e->Find( "PMT_Tl208_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e->Find( "PMT_Ac228_h_e_energy_P2"       ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e->Find( "CuTower_Co60_h_e_energy_P2"    ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"     ) , hcoll_1e->Find( "Cd116_2b2n_m4_h_e_energy_P2"   ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_K40"          ) , hcoll_1e->Find( "Cd116_K40_h_e_energy_P2"       ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m"       ) , hcoll_1e->Find( "Cd116_Pa234m_h_e_energy_P2"    ));
    e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e->Find( "SScin_Bi210_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi210"        ) , hcoll_1e->Find( "SWire_Bi210_h_e_energy_P2"     ));
	e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210"        ) , hcoll_1e->Find( "SFoil_Bi210_h_e_energy_P2"     ));


	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P1"   ) );	
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P1"   ) );
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P1"   ) );	
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P1") ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_2eExt->Find( "Air_Tl208_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P1"       ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P1"  ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P1"   ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_2eExt->Find( "Air_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_2eExt->Find( "Air_Pb214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P1"     ) ); 
	tot_e_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P1") ); 

	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_2eExt->Find( "SWire_Bi214_h_tot_e_energy_P2"     ) );	
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P2"     ) );
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll_2eExt->Find( "SWire_Pb214_h_tot_e_energy_P2"     ) );	
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_2eExt->Find( "PMT_Tl208_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_2eExt->Find( "FeShield_Tl208_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_2eExt->Find( "PMT_Ac228_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_2eExt->Find( "FeShield_Ac228_h_tot_e_energy_P2"  ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_2eExt->Find( "ScintPet_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_2eExt->Find( "ScintOut_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_2eExt->Find( "ScintInn_K40_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_2eExt->Find( "PMT_K40_h_tot_e_energy_P2"         ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_2eExt->Find( "CuTower_Co60_h_tot_e_energy_P2"    ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_2eExt->Find( "SScin_Bi210_h_tot_e_energy_P2"     ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_2eExt->Find( "PMT_Bi214_h_tot_e_energy_P2"       ) ); 
	tot_e_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_2eExt->Find( "FeShield_Bi214_h_tot_e_energy_P2"  ) ); 

	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P1"   ) );	
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P1"   ) );
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P1"   ) );	
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P1") ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_1e1gExt->Find( "Air_Tl208_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P1"       ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P1"  ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P1"   ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_1e1gExt->Find( "Air_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_1e1gExt->Find( "Air_Pb214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P1"     ) ); 
	tot_e_g_energy_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P1") ); 

	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_1e1gExt->Find( "SWire_Bi214_h_tot_energy_P2"   ) );	
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P2"   ) );
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll_1e1gExt->Find( "SWire_Pb214_h_tot_energy_P2"   ) );	
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e1gExt->Find( "PMT_Tl208_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e1gExt->Find( "FeShield_Tl208_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e1gExt->Find( "PMT_Ac228_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e1gExt->Find( "FeShield_Ac228_h_tot_energy_P2") ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e1gExt->Find( "ScintPet_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e1gExt->Find( "ScintOut_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e1gExt->Find( "ScintInn_K40_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e1gExt->Find( "PMT_K40_h_tot_energy_P2"       ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e1gExt->Find( "CuTower_Co60_h_tot_energy_P2"  ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"        ) , hcoll_1e1gExt->Find( "SScin_Bi210_h_tot_energy_P2"   ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e1gExt->Find( "PMT_Bi214_h_tot_energy_P2"     ) ); 
	tot_e_g_energy_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e1gExt->Find( "FeShield_Bi214_h_tot_energy_P2") ); 

	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_1e2gInt->Find( "Cd116_Tl208_h_energy_score_fun_P1"     ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_1e2gInt->Find( "Cd116_Ac228_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll_1e2gInt->Find( "Cd116_Pb211_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll_1e2gInt->Find( "Cd116_Bi214_h_energy_score_fun_P1"	  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll_1e2gInt->Find( "Cd116_pb214_VT_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_1e2gInt->Find( "Mylar_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_1e2gInt->Find( "Mylar_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e2gInt->Find( "FeShield_Bi214_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e2gInt->Find( "FeShield_Tl208_h_energy_score_fun_P1"  ));
    energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e2gInt->Find( "FeShield_Ac228_h_energy_score_fun_P1"  ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_IN"  ) , hcoll_1e2gInt->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1_OUT" ) , hcoll_1e2gInt->Find( "SWire_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_IN"  ) , hcoll_1e2gInt->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1_OUT" ) , hcoll_1e2gInt->Find( "SFoil_Bi214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_IN"  ) , hcoll_1e2gInt->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));	
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1_OUT" ) , hcoll_1e2gInt->Find( "SWire_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_IN"  ) , hcoll_1e2gInt->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1_OUT" ) , hcoll_1e2gInt->Find( "SFoil_Pb214_h_energy_score_fun_P1"     ));
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e2gInt->Find( "FeShield_Bi214_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e2gInt->Find( "FeShield_Tl208_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e2gInt->Find( "FeShield_Ac228_h_energy_score_fun_P1" ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e2gInt->Find( "CuTower_Co60_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"       ) , hcoll_1e2gInt->Find( "Air_Bi214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"       ) , hcoll_1e2gInt->Find( "Air_Pb214_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"       ) , hcoll_1e2gInt->Find( "Air_Tl208_h_energy_score_fun_P1"      ));      
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e2gInt->Find( "PMT_Bi214_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e2gInt->Find( "PMT_Tl208_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e2gInt->Find( "PMT_Ac228_h_energy_score_fun_P1"      ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e2gInt->Find( "PMT_K40_h_energy_score_fun_P1"        ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e2gInt->Find( "ScintInn_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e2gInt->Find( "ScintOut_K40_h_energy_score_fun_P1"   ));         
	energy_score_fun_P1 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e2gInt->Find( "ScintPet_K40_h_energy_score_fun_P1"   ));         

	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"        ) , hcoll_1e2gInt->Find( "Cd116_Tl208_h_energy_score_fun_P2"     ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"        ) , hcoll_1e2gInt->Find( "Cd116_Ac228_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb211"        ) , hcoll_1e2gInt->Find( "Cd116_Pb211_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"	     ) , hcoll_1e2gInt->Find( "Cd116_Bi214_h_energy_score_fun_P2"	  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"	     ) , hcoll_1e2gInt->Find( "Cd116_pb214_VT_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"        ) , hcoll_1e2gInt->Find( "Mylar_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"        ) , hcoll_1e2gInt->Find( "Mylar_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e2gInt->Find( "FeShield_Bi214_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e2gInt->Find( "FeShield_Tl208_h_energy_score_fun_P2"  ));
    energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e2gInt->Find( "FeShield_Ac228_h_energy_score_fun_P2"  ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_IN"  ) , hcoll_1e2gInt->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2_OUT" ) , hcoll_1e2gInt->Find( "SWire_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_IN"  ) , hcoll_1e2gInt->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2_OUT" ) , hcoll_1e2gInt->Find( "SFoil_Bi214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_IN"  ) , hcoll_1e2gInt->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));	
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2_OUT" ) , hcoll_1e2gInt->Find( "SWire_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_IN"  ) , hcoll_1e2gInt->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2_OUT" ) , hcoll_1e2gInt->Find( "SFoil_Pb214_h_energy_score_fun_P2"     ));
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"     ) , hcoll_1e2gInt->Find( "FeShield_Bi214_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"     ) , hcoll_1e2gInt->Find( "FeShield_Tl208_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"     ) , hcoll_1e2gInt->Find( "FeShield_Ac228_h_energy_score_fun_P2" ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"       ) , hcoll_1e2gInt->Find( "CuTower_Co60_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"          ) , hcoll_1e2gInt->Find( "PMT_Bi214_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"          ) , hcoll_1e2gInt->Find( "PMT_Tl208_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"          ) , hcoll_1e2gInt->Find( "PMT_Ac228_h_energy_score_fun_P2"      ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "PMT_K40"            ) , hcoll_1e2gInt->Find( "PMT_K40_h_energy_score_fun_P2"        ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"       ) , hcoll_1e2gInt->Find( "ScintInn_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"       ) , hcoll_1e2gInt->Find( "ScintOut_K40_h_energy_score_fun_P2"   ));         
	energy_score_fun_P2 -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"       ) , hcoll_1e2gInt->Find( "ScintPet_K40_h_energy_score_fun_P2"   ));         

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add for fitting
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::AddObservable( e_energy_P1 );	
	DataManagement::AddObservable( e_energy_P2 );	
	DataManagement::AddObservable( tot_e_energy_P1 );	
	DataManagement::AddObservable( tot_e_energy_P2 );	
	DataManagement::AddObservable( tot_e_g_energy_P1 );	
	DataManagement::AddObservable( tot_e_g_energy_P2 );	
	DataManagement::AddObservable( energy_score_fun_P1 );	
	DataManagement::AddObservable( energy_score_fun_P2 );	
	
	Fit::DoDrawScan();
	Fit::Run("Minuit", "Minimize");
	
	e_energy_P1         -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_energy_P1     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_g_energy_P1   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	e_energy_P2         -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_energy_P2     -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	tot_e_g_energy_P2   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,".eps");
	                        
   	e_energy_P1         -> SetLogScale(kTRUE); e_energy_P1       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
   	e_energy_P2         -> SetLogScale(kTRUE); e_energy_P2       -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_e_energy_P1     -> SetLogScale(kTRUE); tot_e_energy_P1   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_e_energy_P2     -> SetLogScale(kTRUE); tot_e_energy_P2   -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_e_g_energy_P1   -> SetLogScale(kTRUE); tot_e_g_energy_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	tot_e_g_energy_P2   -> SetLogScale(kTRUE); tot_e_g_energy_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	energy_score_fun_P1 -> SetLogScale(kTRUE); energy_score_fun_P1 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	energy_score_fun_P2 -> SetLogScale(kTRUE); energy_score_fun_P2 -> Draw(); (TPad*)gROOT->GetSelectedPad()->Print(0,"_log.eps");
	                            
}                               
                                