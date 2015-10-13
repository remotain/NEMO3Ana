{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("TwoElectronIntHistos", "TwoElectronIntHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TMVApp.root");
	
	//TDirectory * fdir = 0;
	//TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	//while( ds = (DataSet*) next() ){
	//	fdir = (TDirectory *) f->cd(); fdir->cd();
	//	hcoll->Load(fdir);
	//}
	
	bool constrain_all = true;

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
	// Renormalise histogram wrt best fit
	//
	//////////////////////////////////////////////////////////////////////////////	
	TH1F *       Data        = f.Get( "Data_MVA_BDT"           );              Data->Sumw2();	
	TH1F *       Cd116_Tl208 = f.Get( "Cd116_Tl208_MVA_BDT"    );       Cd116_Tl208->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Tl208"      , "Cd116_Tl208"      , DataManagement::FindDataSet( "Cd116_Tl208"    ) , 5.93241  , 0. ) );
	TH1F *       Cd116_Ac228 = f.Get( "Cd116_Ac228_MVA_BDT"    );       Cd116_Ac228->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Ac228"      , "Cd116_Ac228"      , DataManagement::FindDataSet( "Cd116_Ac228"    ) , 6.92004  , 0. ) );
	TH1F *       Cd116_Bi212 = f.Get( "Cd116_Bi212_MVA_BDT"    );       Cd116_Bi212->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Bi212"      , "Cd116_Bi212"      , DataManagement::FindDataSet( "Cd116_Bi212"    ) , 2.74493  , 0. ) );
	TH1F *       Cd116_Bi214 = f.Get( "Cd116_Bi214_MVA_BDT"    );       Cd116_Bi214->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Bi214"      , "Cd116_Bi214"      , DataManagement::FindDataSet( "Cd116_Bi214"    ) , 18.2853  , 0. ) );
	TH1F *       Cd116_Pb214 = f.Get( "Cd116_Pb214_VT_MVA_BDT" );       Cd116_Pb214->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Pb214"      , "Cd116_Pb214"      , DataManagement::FindDataSet( "Cd116_Pb214_VT" ) , 0.186478 , 0. ) );
	TH1F *       Mylar_Bi214 = f.Get( "Mylar_Bi214_MVA_BDT"    );       Mylar_Bi214->Sumw2();  DataManagement::AddComponent( new Component( "Mylar_Bi214"      , "Mylar_Bi214"      , DataManagement::FindDataSet( "Mylar_Bi214"    ) , 11.1896  , 0. ) );
	TH1F *       Mylar_Pb214 = f.Get( "Mylar_Pb214_MVA_BDT"    );       Mylar_Pb214->Sumw2();  DataManagement::AddComponent( new Component( "Mylar_Pb214"      , "Mylar_Pb214"      , DataManagement::FindDataSet( "Mylar_Pb214"    ) , 0.493241 , 0. ) );
	TH1F *    Cd116_K40_cold = f.Get( "Cd116_K40_MVA_BDT"      );    Cd116_K40_cold->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_K40_cold"   , "Cd116_K40_cold"   , DataManagement::FindDataSet( "Cd116_K40"      ) , 9.02952  , 0. ) );
	TH1F * Cd116_Pa234m_cold = f.Get( "Cd116_Pa234m_MVA_BDT"   ); Cd116_Pa234m_cold->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Pa234m_cold", "Cd116_Pa234m_cold", DataManagement::FindDataSet( "Cd116_Pa234m"   ) , 27.7433  , 0. ) );
	TH1F *    Cd116_K40_warm = f.Get( "Cd116_K40_MVA_BDT"      );    Cd116_K40_warm->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_K40_warm"   , "Cd116_K40_warm"   , DataManagement::FindDataSet( "Cd116_K40"      ) , 25.9835  , 0. ) );
	TH1F * Cd116_Pa234m_warm = f.Get( "Cd116_Pa234m_MVA_BDT"   ); Cd116_Pa234m_warm->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_Pa234m_warm", "Cd116_Pa234m_warm", DataManagement::FindDataSet( "Cd116_Pa234m"   ) , 72.4378  , 0. ) );
	TH1F *  SFoil_Bi210_warm = f.Get( "SFoil_Bi210_MVA_BDT"    );  SFoil_Bi210_warm->Sumw2();  DataManagement::AddComponent( new Component( "SFoil_Bi210_warm" , "SFoil_Bi210_warm" , DataManagement::FindDataSet( "SFoil_Bi210"    ) , 23.243   , 0. ) );
	TH1F *    SWire_Bi210_P1 = f.Get( "SWire_Bi210_MVA_BDT"    );    SWire_Bi210_P1->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Bi210_P1"   , "SWire_Bi210_P1"   , DataManagement::FindDataSet( "SWire_Bi210"    ) , 0.136147 , 0. ) );
	TH1F *    SWire_Bi210_P2 = f.Get( "SWire_Bi210_MVA_BDT"    );    SWire_Bi210_P2->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Bi210_P2"   , "SWire_Bi210_P2"   , DataManagement::FindDataSet( "SWire_Bi210"    ) , 0.624186 , 0. ) );
	TH1F *       SScin_Bi210 = f.Get( "SScin_Bi210_MVA_BDT"    );       SScin_Bi210->Sumw2();  DataManagement::AddComponent( new Component( "SScin_Bi210"      , "SScin_Bi210"      , DataManagement::FindDataSet( "SScin_Bi210"    ) , 1.756    , 0. ) );
	TH1F *       SScin_Bi214 = f.Get( "SScin_Bi214_MVA_BDT"    );       SScin_Bi214->Sumw2();  DataManagement::AddComponent( new Component( "SScin_Bi214"      , "SScin_Bi214"      , DataManagement::FindDataSet( "SScin_Bi214"    ) , 0.050538 , 0. ) );
	TH1F *    SWire_Tl208_P1 = f.Get( "SWire_Tl208_MVA_BDT"    );    SWire_Tl208_P1->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Tl208_P1"   , "SWire_Tl208_P1"   , DataManagement::FindDataSet( "SWire_Tl208"    ) , 0.217623 , 0. ) );
	TH1F *    SWire_Bi214_P1 = f.Get( "SWire_Bi214_MVA_BDT"    );    SWire_Bi214_P1->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Bi214_P1"   , "SWire_Bi214_P1"   , DataManagement::FindDataSet( "SWire_Bi214"    ) , 21.4626  , 0. ) );
	TH1F *    SFoil_Bi214_P1 = f.Get( "SFoil_Bi214_MVA_BDT"    );    SFoil_Bi214_P1->Sumw2();  DataManagement::AddComponent( new Component( "SFoil_Bi214_P1"   , "SFoil_Bi214_P1"   , DataManagement::FindDataSet( "SFoil_Bi214"    ) , 5.77558  , 0. ) );
	TH1F *    SWire_Pb214_P1 = f.Get( "SWire_Pb214_MVA_BDT"    );    SWire_Pb214_P1->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Pb214_P1"   , "SWire_Pb214_P1"   , DataManagement::FindDataSet( "SWire_Pb214"    ) , 0.457546 , 0. ) );
	TH1F *    SFoil_Pb214_P1 = f.Get( "SFoil_Pb214_MVA_BDT"    );    SFoil_Pb214_P1->Sumw2();  DataManagement::AddComponent( new Component( "SFoil_Pb214_P1"   , "SFoil_Pb214_P1"   , DataManagement::FindDataSet( "SFoil_Pb214"    ) , 0.215627 , 0. ) );
	TH1F *    SWire_Tl208_P2 = f.Get( "SWire_Tl208_MVA_BDT"    );    SWire_Tl208_P2->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Tl208_P2"   , "SWire_Tl208_P2"   , DataManagement::FindDataSet( "SWire_Tl208"    ) , 1.07644  , 0. ) );
	TH1F *    SWire_Bi214_P2 = f.Get( "SWire_Bi214_MVA_BDT"    );    SWire_Bi214_P2->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Bi214_P2"   , "SWire_Bi214_P2"   , DataManagement::FindDataSet( "SWire_Bi214"    ) , 17.9578  , 0. ) );
	TH1F *    SFoil_Bi214_P2 = f.Get( "SFoil_Bi214_MVA_BDT"    );    SFoil_Bi214_P2->Sumw2();  DataManagement::AddComponent( new Component( "SFoil_Bi214_P2"   , "SFoil_Bi214_P2"   , DataManagement::FindDataSet( "SFoil_Bi214"    ) , 2.73528  , 0. ) );
	TH1F *    SWire_Pb214_P2 = f.Get( "SWire_Pb214_MVA_BDT"    );    SWire_Pb214_P2->Sumw2();  DataManagement::AddComponent( new Component( "SWire_Pb214_P2"   , "SWire_Pb214_P2"   , DataManagement::FindDataSet( "SWire_Pb214"    ) , 0.648406 , 0. ) );
	TH1F *    SFoil_Pb214_P2 = f.Get( "SFoil_Pb214_MVA_BDT"    );    SFoil_Pb214_P2->Sumw2();  DataManagement::AddComponent( new Component( "SFoil_Pb214_P2"   , "SFoil_Pb214_P2"   , DataManagement::FindDataSet( "SFoil_Pb214"    ) , 0.188876 , 0. ) );
	TH1F *    FeShield_Bi214 = f.Get( "FeShield_Bi214_MVA_BDT" );    FeShield_Bi214->Sumw2();  DataManagement::AddComponent( new Component( "FeShield_Bi214"   , "FeShield_Bi214"   , DataManagement::FindDataSet( "FeShield_Bi214" ) , 49.1846  , 0. ) );
	TH1F *    FeShield_Tl208 = f.Get( "FeShield_Tl208_MVA_BDT" );    FeShield_Tl208->Sumw2();  DataManagement::AddComponent( new Component( "FeShield_Tl208"   , "FeShield_Tl208"   , DataManagement::FindDataSet( "FeShield_Tl208" ) , 1.19312  , 0. ) );
	TH1F *    FeShield_Ac228 = f.Get( "FeShield_Ac228_MVA_BDT" );    FeShield_Ac228->Sumw2();  DataManagement::AddComponent( new Component( "FeShield_Ac228"   , "FeShield_Ac228"   , DataManagement::FindDataSet( "FeShield_Ac228" ) , 0.17612  , 0. ) );
	TH1F *      CuTower_Co60 = f.Get( "CuTower_Co60_MVA_BDT"   );      CuTower_Co60->Sumw2();  DataManagement::AddComponent( new Component( "CuTower_Co60"     , "CuTower_Co60"     , DataManagement::FindDataSet( "CuTower_Co60"   ) , 3.77603  , 0. ) );
	TH1F *      Air_Bi214_P1 = f.Get( "Air_Bi214_MVA_BDT"      );      Air_Bi214_P1->Sumw2();  DataManagement::AddComponent( new Component( "Air_Bi214_P1"     , "Air_Bi214_P1"     , DataManagement::FindDataSet( "Air_Bi214"      ) , 4.19271  , 0. ) );
	TH1F *         PMT_Bi214 = f.Get( "PMT_Bi214_MVA_BDT"      );         PMT_Bi214->Sumw2();  DataManagement::AddComponent( new Component( "PMT_Bi214"        , "PMT_Bi214"        , DataManagement::FindDataSet( "PMT_Bi214"      ) , 30.7385  , 0. ) );
	TH1F *         PMT_Tl208 = f.Get( "PMT_Tl208_MVA_BDT"      );         PMT_Tl208->Sumw2();  DataManagement::AddComponent( new Component( "PMT_Tl208"        , "PMT_Tl208"        , DataManagement::FindDataSet( "PMT_Tl208"      ) , 23.2701  , 0. ) );
	TH1F *         PMT_Ac228 = f.Get( "PMT_Ac228_MVA_BDT"      );         PMT_Ac228->Sumw2();  DataManagement::AddComponent( new Component( "PMT_Ac228"        , "PMT_Ac228"        , DataManagement::FindDataSet( "PMT_Ac228"      ) , 3.60944  , 0. ) );
	TH1F *           PMT_K40 = f.Get( "PMT_K40_MVA_BDT"        );           PMT_K40->Sumw2();  DataManagement::AddComponent( new Component( "PMT_K40"          , "PMT_K40"          , DataManagement::FindDataSet( "PMT_K40"        ) , 16.7905  , 0. ) );
	TH1F *      ScintInn_K40 = f.Get( "ScintInn_K40_MVA_BDT"   );      ScintInn_K40->Sumw2();  DataManagement::AddComponent( new Component( "ScintInn_K40"     , "ScintInn_K40"     , DataManagement::FindDataSet( "ScintInn_K40"   ) , 0.335557 , 0. ) );
	TH1F *      ScintOut_K40 = f.Get( "ScintOut_K40_MVA_BDT"   );      ScintOut_K40->Sumw2();  DataManagement::AddComponent( new Component( "ScintOut_K40"     , "ScintOut_K40"     , DataManagement::FindDataSet( "ScintOut_K40"   ) , 0.604003 , 0. ) );
	TH1F *      ScintPet_K40 = f.Get( "ScintPet_K40_MVA_BDT"   );      ScintPet_K40->Sumw2();  DataManagement::AddComponent( new Component( "ScintPet_K40"     , "ScintPet_K40"     , DataManagement::FindDataSet( "ScintPet_K40"   ) , 1.00666  , 0. ) );
	TH1F *    MuMetal_Pa234m = f.Get( "MuMetal_Pa234m_MVA_BDT" );    MuMetal_Pa234m->Sumw2();  DataManagement::AddComponent( new Component( "MuMetal_Pa234m"   , "MuMetal_Pa234m"   , DataManagement::FindDataSet( "MuMetal_Pa234m" ) , 0.66462  , 0. ) );
	TH1F *    Cd116_2b2n_m14 = f.Get( "Cd116_2b2n_m14_MVA_BDT" );    Cd116_2b2n_m14->Sumw2();  DataManagement::AddComponent( new Component( "Cd116_2b2n_m14"   , "Cd116_2b2n_m14"   , DataManagement::FindDataSet( "Cd116_2b2n_m14" ) , 5022.22  , 0. ) );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define gorups
	//
	//////////////////////////////////////////////////////////////////////////////	
	DataManagement::FindGroup( "BB"        ) -> AddComponent( DataManagement::FindComponent("Cd116_2b2n_m14"     ) );	
	DataManagement::FindGroup( "Tl208"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) );
	DataManagement::FindGroup( "Tl208"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) );
	DataManagement::FindGroup( "Tl208"     ) -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"       ) );
	DataManagement::FindGroup( "Tl208"     ) -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"       ) );
	DataManagement::FindGroup( "Tl208"     ) -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"       ) );	
	DataManagement::FindGroup( "Bi214"     ) -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) );
	DataManagement::FindGroup( "Bi214"     ) -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) );
	DataManagement::FindGroup( "Bi214"     ) -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"       ) );
	DataManagement::FindGroup( "Bi214"     ) -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"       ) );	
	DataManagement::FindGroup( "K40"       ) -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) );
	DataManagement::FindGroup( "K40"       ) -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) );
	DataManagement::FindGroup( "Pa234m"    ) -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) );
	DataManagement::FindGroup( "Pa234m"    ) -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) );	
	DataManagement::FindGroup( "Bi210"     ) -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm"  ) );
	DataManagement::FindGroup( "Bi210"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) );
	DataManagement::FindGroup( "Bi210"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"    ) );	
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) );
	DataManagement::FindGroup( "Radon"     ) -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) );	
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "Air_Tl208_P1"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "PMT_K40"           ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"       ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"       ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "SScin_Pb214"       ) );
	DataManagement::FindGroup( "Externals" ) -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"    ) );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * BDT_score  = new Observable("BDT_score" , "BDT Score; BDT Score" , kAll , Data ); BDT_score -> SetLogScale(kFALSE); BDT_score -> AddGroupAll(DataManagement::GetGroupCollection()); BDT_score -> SetDrawGroup(kTRUE); 
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Summed plot
	//
	//////////////////////////////////////////////////////////////////////////////	
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Tl208"      ) , Cd116_Tl208       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Ac228"      ) , Cd116_Ac228       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Bi212"      ) , Cd116_Bi212       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Bi214"      ) , Cd116_Bi214       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Pb214"      ) , Cd116_Pb214       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Mylar_Bi214"      ) , Mylar_Bi214       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Mylar_Pb214"      ) , Mylar_Pb214       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"   ) , Cd116_K40_cold    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold") , Cd116_Pa234m_cold );   
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"   ) , Cd116_K40_warm    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm") , Cd116_Pa234m_warm );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SFoil_Bi210_warm" ) , SFoil_Bi210_warm  );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"   ) , SWire_Bi210_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"   ) , SWire_Bi210_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SScin_Bi210"      ) , SScin_Bi210       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SScin_Bi214"      ) , SScin_Bi214       );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"   ) , SWire_Tl208_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"   ) , SWire_Bi214_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"   ) , SFoil_Bi214_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"   ) , SWire_Pb214_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"   ) , SFoil_Pb214_P1    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"   ) , SWire_Tl208_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"   ) , SWire_Bi214_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"   ) , SFoil_Bi214_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"   ) , SWire_Pb214_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"   ) , SFoil_Pb214_P2    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "FeShield_Bi214"   ) , FeShield_Bi214    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "FeShield_Tl208"   ) , FeShield_Tl208    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "FeShield_Ac228"   ) , FeShield_Ac228    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "CuTower_Co60"     ) , CuTower_Co60      );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"     ) , Air_Bi214_P1      );
	BDT_score -> AddComponent( DataManagement::FindComponent( "PMT_Bi214"        ) , PMT_Bi214         );
	BDT_score -> AddComponent( DataManagement::FindComponent( "PMT_Tl208"        ) , PMT_Tl208         );
	BDT_score -> AddComponent( DataManagement::FindComponent( "PMT_Ac228"        ) , PMT_Ac228         );
	BDT_score -> AddComponent( DataManagement::FindComponent( "PMT_K40"          ) , PMT_K40           );
	BDT_score -> AddComponent( DataManagement::FindComponent( "ScintInn_K40"     ) , ScintInn_K40      );
	BDT_score -> AddComponent( DataManagement::FindComponent( "ScintOut_K40"     ) , ScintOut_K40      );
	BDT_score -> AddComponent( DataManagement::FindComponent( "ScintPet_K40"     ) , ScintPet_K40      );
	BDT_score -> AddComponent( DataManagement::FindComponent( "MuMetal_Pa234m"   ) , MuMetal_Pa234m    );
	BDT_score -> AddComponent( DataManagement::FindComponent( "Cd116_2b2n_m14"   ) , Cd116_2b2n_m14    );

	BDT_score -> Draw(); //(TPad*)gROOT->GetSelectedPad()->Print("FitTwoElectronColdWarm.pdf"  ); tot_e_energy -> SetLogScale(kTRUE);

}