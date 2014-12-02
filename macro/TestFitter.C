{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141120/OneElectronHistos.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define the parameters
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddParameter( new Parameter("Externals" , "External Backgrounds" , 0 , 1.0     , 2.0         , 0.         , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Radon"     , "Radon Backgrounds"    , 1 , 1.0     , 2.0         , 0.         , 0.001 ) );
	DataManagement::AddParameter( new Parameter("Internals" , "Internal Backgrounds" , 2 , 1.0     , 2.0         , 0.         , 0.001 ) );
	DataManagement::AddParameter( new Parameter("2b2nu"     , "2e2#nu"               , 3 , 1/2.88e19 , (1/2.88e19)*1.1 , (1/2.88e19)*0.9 , 0.001 ) );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component( "CuPetals_Co60"    , "^{60}Co CuPetals     " , DataManagement::FindDataSet("CuPetals_Co60"   ) , DataManagement::FindParameter("Externals") , 47.6 ) ); DataManagement::FindComponent("CuPetals_Co60"   )->SetFillColor( kOrange -  7 );
	DataManagement::AddComponent( new Component( "CuTower_Co60"     , "^{60}Co CuTower      " , DataManagement::FindDataSet("CuTower_Co60"    ) , DataManagement::FindParameter("Externals") , 18.4 ) ); DataManagement::FindComponent("CuTower_Co60"    )->SetFillColor( kOrange -  6 );
	DataManagement::AddComponent( new Component( "MuMetal_Co60"     , "^{60}Co MuMetal      " , DataManagement::FindDataSet("MuMetal_Co60"    ) , DataManagement::FindParameter("Externals") , 14.6 ) ); DataManagement::FindComponent("MuMetal_Co60"    )->SetFillColor( kOrange -  5 );
	DataManagement::AddComponent( new Component( "SteelFrame_Co60"  , "^{60}Co SteelFrame   " , DataManagement::FindDataSet("SteelFrame_Co60" ) , DataManagement::FindParameter("Externals") , 6.09 ) ); DataManagement::FindComponent("SteelFrame_Co60" )->SetFillColor( kOrange -  4 );
	DataManagement::AddComponent( new Component( "FeShield_Ac228"   , "^{228}Ac FeShield    " , DataManagement::FindDataSet("FeShield_Ac228"  ) , DataManagement::FindParameter("Externals") , 1350 ) ); DataManagement::FindComponent("FeShield_Ac228"  )->SetFillColor( kOrange -  3 );
	DataManagement::AddComponent( new Component( "PMT_Ac228"        , "^{228}Ac PMT         " , DataManagement::FindDataSet("PMT_Ac228"       ) , DataManagement::FindParameter("Externals") , 72.7 ) ); DataManagement::FindComponent("PMT_Ac228"       )->SetFillColor( kOrange -  2 );
	DataManagement::AddComponent( new Component( "SteelFrame_Ac228" , "^{228}Ac SteelFrame  " , DataManagement::FindDataSet("SteelFrame_Ac228") , DataManagement::FindParameter("Externals") , 8.54 ) ); DataManagement::FindComponent("SteelFrame_Ac228")->SetFillColor( kOrange -  1 );
	DataManagement::AddComponent( new Component( "FeShield_Bi214"   , "^{214}Bi FeShield    " , DataManagement::FindDataSet("FeShield_Bi214"  ) , DataManagement::FindParameter("Externals") , 7360 ) ); DataManagement::FindComponent("FeShield_Bi214"  )->SetFillColor( kOrange +  0 );
	DataManagement::AddComponent( new Component( "PMT_Bi214"        , "^{214}Bi PMT         " , DataManagement::FindDataSet("PMT_Bi214"       ) , DataManagement::FindParameter("Externals") ,  324 ) ); DataManagement::FindComponent("PMT_Bi214"       )->SetFillColor( kOrange +  1 );
	DataManagement::AddComponent( new Component( "SteelFrame_Bi214" , "^{214}Bi SteelFrame  " , DataManagement::FindDataSet("SteelFrame_Bi214") , DataManagement::FindParameter("Externals") ,  9.1 ) ); DataManagement::FindComponent("SteelFrame_Bi214")->SetFillColor( kOrange +  2 );
	DataManagement::AddComponent( new Component( "FeShield_Tl208"   , "^{208}Tl FeShield    " , DataManagement::FindDataSet("FeShield_Tl208"  ) , DataManagement::FindParameter("Externals") ,  484 ) ); DataManagement::FindComponent("FeShield_Tl208"  )->SetFillColor( kOrange +  3 );
	DataManagement::AddComponent( new Component( "PMT_Tl208"        , "^{208}Tl PMT         " , DataManagement::FindDataSet("PMT_Tl208"       ) , DataManagement::FindParameter("Externals") , 27.0 ) ); DataManagement::FindComponent("PMT_Tl208"       )->SetFillColor( kOrange +  4 );
	DataManagement::AddComponent( new Component( "SteelFrame_Tl208" , "^{208}Tl SteelFrame  " , DataManagement::FindDataSet("SteelFrame_Tl208") , DataManagement::FindParameter("Externals") ,  3.1 ) ); DataManagement::FindComponent("SteelFrame_Tl208")->SetFillColor( kOrange +  5 );
	DataManagement::AddComponent( new Component( "PMT_K40"          , "^{40}K PMT           " , DataManagement::FindDataSet("PMT_K40"         ) , DataManagement::FindParameter("Externals") , 1078 ) ); DataManagement::FindComponent("PMT_K40"         )->SetFillColor( kOrange +  6 );
	DataManagement::AddComponent( new Component( "ScintInn_K40"     , "^{40}K Inner Scint.  " , DataManagement::FindDataSet("ScintInn_K40"    ) , DataManagement::FindParameter("Externals") , 7.59 ) ); DataManagement::FindComponent("ScintInn_K40"    )->SetFillColor( kOrange +  7 );
	DataManagement::AddComponent( new Component( "ScintOut_K40"     , "^{40}K Outer Scint.  " , DataManagement::FindDataSet("ScintOut_K40"    ) , DataManagement::FindParameter("Externals") ,12.53 ) ); DataManagement::FindComponent("ScintOut_K40"    )->SetFillColor( kOrange +  8 );
	DataManagement::AddComponent( new Component( "ScintPet_K40"     , "^{40}K Petal Scint.  " , DataManagement::FindDataSet("ScintPet_K40"    ) , DataManagement::FindParameter("Externals") , 1.39 ) ); DataManagement::FindComponent("ScintPet_K40"    )->SetFillColor( kOrange +  9 );
	DataManagement::AddComponent( new Component( "SteelFrame_K40"   , "^{40}K SteelFrame    " , DataManagement::FindDataSet("SteelFrame_K40"  ) , DataManagement::FindParameter("Externals") ,  100 ) ); DataManagement::FindComponent("SteelFrame_K40"  )->SetFillColor( kOrange + 10 );
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Externals components
	//
	//////////////////////////////////////////////////////////////////////////////
	double sscin_activity_bi214=(0.291*15.19 + 0.431*34.94 + 0.418*9.68)/59.81;
	double sscin_activity_bi210=(28.6*15.19 + 34.6*34.94 + 27.9*9.68)/59.81;
	DataManagement::AddComponent( new Component("Air_Bi214_P1"         , "^{214}Bi LSM Air P1     "   , DataManagement::FindDataSet("Air_Bi214"  ) , DataManagement::FindParameter("Radon") ,           566.5      )); DataManagement::FindComponent("Air_Bi214_P1"   )->SetFillColor( kCyan  +  4 );
	DataManagement::AddComponent( new Component("Air_Pb214_P1"         , "^{214}Pb LSM Air P1     "   , DataManagement::FindDataSet("Air_Pb214"  ) , DataManagement::FindParameter("Radon") ,           566.5      )); DataManagement::FindComponent("Air_Pb214_P1"   )->SetFillColor( kCyan  +  3 );
	DataManagement::AddComponent( new Component("Air_Bi214_P2"         , "^{214}Bi LSM Air P2     "   , DataManagement::FindDataSet("Air_Bi214"  ) , DataManagement::FindParameter("Radon") ,             0.0      )); DataManagement::FindComponent("Air_Bi214_P2"   )->SetFillColor( kCyan  +  2 );
	DataManagement::AddComponent( new Component("Air_Pb214_P2"         , "^{214}Pb LSM Air P2     "   , DataManagement::FindDataSet("Air_Pb214"  ) , DataManagement::FindParameter("Radon") ,             0.0      )); DataManagement::FindComponent("Air_Pb214_P2"   )->SetFillColor( kCyan  +  1 );
	DataManagement::AddComponent( new Component("SFoil_Bi210_P1"       , "^{210}Bi SFoil P1       "   , DataManagement::FindDataSet("SFoil_Bi210") , DataManagement::FindParameter("Radon") ,             1.60     )); DataManagement::FindComponent("SFoil_Bi210_P1" )->SetFillColor( kAzure -  9 );
	DataManagement::AddComponent( new Component("SFoil_Bi210_P2"       , "^{210}Bi SFoil P2       "   , DataManagement::FindDataSet("SFoil_Bi210") , DataManagement::FindParameter("Radon") ,             1.60     )); DataManagement::FindComponent("SFoil_Bi210_P2" )->SetFillColor( kAzure -  8 );
	DataManagement::AddComponent( new Component("SFoil_Bi214_P1"       , "^{214}Bi SFoil P1       "   , DataManagement::FindDataSet("SFoil_Bi214") , DataManagement::FindParameter("Radon") ,             0.00854  )); DataManagement::FindComponent("SFoil_Bi214_P1" )->SetFillColor( kAzure -  7 );
	DataManagement::AddComponent( new Component("SFoil_Bi214_P2"       , "^{214}Bi SFoil P2       "   , DataManagement::FindDataSet("SFoil_Bi214") , DataManagement::FindParameter("Radon") ,             0.00238  )); DataManagement::FindComponent("SFoil_Bi214_P2" )->SetFillColor( kAzure -  6 );
	DataManagement::AddComponent( new Component("SFoil_Pb214_P1"       , "^{214}Pb SFoil P1       "   , DataManagement::FindDataSet("SFoil_Pb214") , DataManagement::FindParameter("Radon") ,             0.00854  )); DataManagement::FindComponent("SFoil_Pb214_P1" )->SetFillColor( kAzure -  5 );
	DataManagement::AddComponent( new Component("SFoil_Pb214_P2"       , "^{214}Pb SFoil P2       "   , DataManagement::FindDataSet("SFoil_Pb214") , DataManagement::FindParameter("Radon") ,             0.00238  )); DataManagement::FindComponent("SFoil_Pb214_P2" )->SetFillColor( kAzure -  4 );
	DataManagement::AddComponent( new Component("SScin_Bi214_P1"       , "^{214}Bi SScin P1       "   , DataManagement::FindDataSet("SScin_Bi214") , DataManagement::FindParameter("Radon") , sscin_activity_bi214 )); DataManagement::FindComponent("SScin_Bi214_P1" )->SetFillColor( kAzure +  1 );
	DataManagement::AddComponent( new Component("SScin_Bi214_P2"       , "^{214}Bi SScin P2       "   , DataManagement::FindDataSet("SScin_Bi214") , DataManagement::FindParameter("Radon") , sscin_activity_bi214 )); DataManagement::FindComponent("SScin_Bi214_P2" )->SetFillColor( kAzure +  2 );
	DataManagement::AddComponent( new Component("SScin_Pb214_P1"       , "^{214}Pb SScin P1       "   , DataManagement::FindDataSet("SScin_Pb214") , DataManagement::FindParameter("Radon") , sscin_activity_bi214 )); DataManagement::FindComponent("SScin_Pb214_P1" )->SetFillColor( kAzure +  3 );
	DataManagement::AddComponent( new Component("SScin_Pb214_P2"       , "^{214}Pb SScin P2       "   , DataManagement::FindDataSet("SScin_Pb214") , DataManagement::FindParameter("Radon") , sscin_activity_bi214 )); DataManagement::FindComponent("SScin_Pb214_P2" )->SetFillColor( kAzure +  4 );
	DataManagement::AddComponent( new Component("SScin_Bi210_P1"       , "^{210}Bi SScin P1       "   , DataManagement::FindDataSet("SScin_Bi210") , DataManagement::FindParameter("Radon") , sscin_activity_bi210 )); DataManagement::FindComponent("SScin_Bi210_P1" )->SetFillColor( kAzure +  5 );
	DataManagement::AddComponent( new Component("SScin_Bi210_P2"       , "^{210}Bi SScin P2       "   , DataManagement::FindDataSet("SScin_Bi210") , DataManagement::FindParameter("Radon") , sscin_activity_bi210 )); DataManagement::FindComponent("SScin_Bi210_P2" )->SetFillColor( kAzure +  6 );
	DataManagement::AddComponent( new Component("SWire_Bi214_P1"       , "^{214}Bi SWire P1       "   , DataManagement::FindDataSet("SWire_Bi214") , DataManagement::FindParameter("Radon") ,             1.12     )); DataManagement::FindComponent("SWire_Bi214_P1" )->SetFillColor( kAzure -  3 );            
	DataManagement::AddComponent( new Component("SWire_Bi214_P2"       , "^{214}Bi SWire P2       "   , DataManagement::FindDataSet("SWire_Bi214") , DataManagement::FindParameter("Radon") ,             0.20     )); DataManagement::FindComponent("SWire_Bi214_P2" )->SetFillColor( kAzure -  2 );            
	DataManagement::AddComponent( new Component("SWire_Pb214_P1"       , "^{214}Pb SWire P1       "   , DataManagement::FindDataSet("SWire_Pb214") , DataManagement::FindParameter("Radon") ,             1.12     )); DataManagement::FindComponent("SWire_Pb214_P1" )->SetFillColor( kAzure -  1 );            
	DataManagement::AddComponent( new Component("SWire_Pb214_P2"       , "^{214}Pb SWire P2       "   , DataManagement::FindDataSet("SWire_Pb214") , DataManagement::FindParameter("Radon") ,             0.20     )); DataManagement::FindComponent("SWire_Pb214_P2" )->SetFillColor( kAzure +  0 );            
	DataManagement::AddComponent( new Component("SWire_Bi210_P1"       , "^{210}Bi SWire P1       "   , DataManagement::FindDataSet("SWire_Bi210") , DataManagement::FindParameter("Radon") ,             8.536 )); DataManagement::FindComponent("SWire_Bi210_P1" )->SetFillColor( kAzure +  7 );           
	DataManagement::AddComponent( new Component("SWire_Bi210_P2"       , "^{210}Bi SWire P2       "   , DataManagement::FindDataSet("SWire_Bi210") , DataManagement::FindParameter("Radon") ,             8.536 )); DataManagement::FindComponent("SWire_Bi210_P2" )->SetFillColor( kAzure +  8 );           
	DataManagement::AddComponent( new Component("SWire_Tl208_P1"       , "^{208}Tl SWire P1       "   , DataManagement::FindDataSet("SWire_Tl208") , DataManagement::FindParameter("Radon") ,             3.5e-3   )); DataManagement::FindComponent("SWire_Tl208_P1" )->SetFillColor( kAzure +  9 );           
	DataManagement::AddComponent( new Component("SWire_Tl208_P2"       , "^{208}Tl SWire P2       "   , DataManagement::FindDataSet("SWire_Tl208") , DataManagement::FindParameter("Radon") ,             2.9e-3   )); DataManagement::FindComponent("SWire_Tl208_P2" )->SetFillColor( kAzure + 10 );           
	//////////////////////////////////////////////////////////////////////////////
	//
	// Define Internals components
	//
	//////////////////////////////////////////////////////////////////////////////
	DataManagement::AddComponent( new Component("Cd116_Tl208_cold"  , "^{208}Tl Cold region  " , DataManagement::FindDataSet("Cd116_Tl208"   ) , DataManagement::FindParameter("Internals") , 1.70         * 1e-5 )); DataManagement::FindComponent("Cd116_Tl208_cold"  )->SetFillColor( kViolet + 0 );           
	DataManagement::AddComponent( new Component("Cd116_Ac228_cold"  , "^{228}Ac Cold region  " , DataManagement::FindDataSet("Cd116_Ac228"   ) , DataManagement::FindParameter("Internals") , 2.782*1.7e-2 * 1e-3 )); DataManagement::FindComponent("Cd116_Ac228_cold"  )->SetFillColor( kViolet + 1 );           
	DataManagement::AddComponent( new Component("Cd116_Bi212_cold"  , "^{212}Bi Cold region  " , DataManagement::FindDataSet("Cd116_Bi212"   ) , DataManagement::FindParameter("Internals") , 2.782*1.7e-2 * 1e-3 )); DataManagement::FindComponent("Cd116_Bi212_cold"  )->SetFillColor( kViolet + 2 );           
	DataManagement::AddComponent( new Component("Cd116_Bi214_cold"  , "^{214}Bi Cold region  " , DataManagement::FindDataSet("Cd116_Bi214"   ) , DataManagement::FindParameter("Internals") , 0.162        * 1e-3 )); DataManagement::FindComponent("Cd116_Bi214_cold"  )->SetFillColor( kViolet + 3 );           
	DataManagement::AddComponent( new Component("Cd116_Pb214_cold"  , "^{214}Pb Cold region  " , DataManagement::FindDataSet("Cd116_pb214_VT") , DataManagement::FindParameter("Internals") , 0.162        * 1e-3 )); DataManagement::FindComponent("Cd116_Pb214_cold"  )->SetFillColor( kViolet + 4 );           
	DataManagement::AddComponent( new Component("Cd116_Cs137_cold"  , "^{137}Cs Cold region  " , DataManagement::FindDataSet("Cd116_Cs137"   ) , DataManagement::FindParameter("Internals") , 1.210        * 1e-3 )); DataManagement::FindComponent("Cd116_Cs137_cold"  )->SetFillColor( kViolet + 5 );           
	DataManagement::AddComponent( new Component("Cd116_K40_cold"    , "^{40}K Cold region "    , DataManagement::FindDataSet("Cd116_K40"     ) , DataManagement::FindParameter("Internals") , 3.370        * 1e-3 )); DataManagement::FindComponent("Cd116_K40_cold"    )->SetFillColor( kViolet + 6 );           
	DataManagement::AddComponent( new Component("Cd116_Pa234m_cold" , "^{234m}Pa Cold region " , DataManagement::FindDataSet("Cd116_Pa234m"  ) , DataManagement::FindParameter("Internals") , 0.360        * 1e-3 )); DataManagement::FindComponent("Cd116_Pa234m_cold" )->SetFillColor( kViolet + 7 );
	DataManagement::AddComponent( new Component("Cd116_Tl207_cold"  , "^{207}Tl Cold region  " , DataManagement::FindDataSet("Cd116_Tl207"   ) , DataManagement::FindParameter("Internals") , 0.0e-3              )); DataManagement::FindComponent("Cd116_Tl207_cold"  )->SetFillColor( kViolet + 9 );
	DataManagement::AddComponent( new Component("Cd116_Pb211_cold"  , "^{211}Pb Cold region  " , DataManagement::FindDataSet("Cd116_Pb211"   ) , DataManagement::FindParameter("Internals") , 0.0e-3              )); DataManagement::FindComponent("Cd116_Pb211_cold"  )->SetFillColor( kViolet + 10 );
	                                                                                                                                                                   
	DataManagement::AddComponent( new Component("Cd116_Tl208_warm"  , "^{208}Tl Warm region  " , DataManagement::FindDataSet("Cd116_Tl208"   ) , DataManagement::FindParameter("Internals") , 4.10         * 1e-5 )); DataManagement::FindComponent("Cd116_Tl208_warm"  )->SetFillColor( kViolet + 0 );
	DataManagement::AddComponent( new Component("Cd116_Ac228_warm"  , "^{228}Ac Warm region  " , DataManagement::FindDataSet("Cd116_Ac228"   ) , DataManagement::FindParameter("Internals") , 2.782*4.1e-2 * 1e-3 )); DataManagement::FindComponent("Cd116_Ac228_warm"  )->SetFillColor( kViolet + 1 );
	DataManagement::AddComponent( new Component("Cd116_Bi212_warm"  , "^{212}Bi Warm region  " , DataManagement::FindDataSet("Cd116_Bi212"   ) , DataManagement::FindParameter("Internals") , 2.782*4.1e-2 * 1e-3 )); DataManagement::FindComponent("Cd116_Bi212_warm"  )->SetFillColor( kViolet + 2 );
	DataManagement::AddComponent( new Component("Cd116_Bi214_warm"  , "^{214}Bi Warm region  " , DataManagement::FindDataSet("Cd116_Bi214"   ) , DataManagement::FindParameter("Internals") , 0.389        * 1e-3 )); DataManagement::FindComponent("Cd116_Bi214_warm"  )->SetFillColor( kViolet + 3 );
	DataManagement::AddComponent( new Component("Cd116_Pb214_warm"  , "^{214}Pb Warm region  " , DataManagement::FindDataSet("Cd116_pb214_VT") , DataManagement::FindParameter("Internals") , 0.389        * 1e-3 )); DataManagement::FindComponent("Cd116_Pb214_warm"  )->SetFillColor( kViolet + 4 );
	DataManagement::AddComponent( new Component("Cd116_Cs137_warm"  , "^{137}Cs Warm region  " , DataManagement::FindDataSet("Cd116_Cs137"   ) , DataManagement::FindParameter("Internals") , 1.210        * 1e-3 )); DataManagement::FindComponent("Cd116_Cs137_warm"  )->SetFillColor( kViolet + 5 );
	DataManagement::AddComponent( new Component("Cd116_K40_warm"    , "^{40}K Warm region "    , DataManagement::FindDataSet("Cd116_K40"     ) , DataManagement::FindParameter("Internals") , 8.340        * 1e-3 )); DataManagement::FindComponent("Cd116_K40_warm"    )->SetFillColor( kViolet + 6 );
	DataManagement::AddComponent( new Component("Cd116_Pa234m_warm" , "^{234m}Pa Warm region " , DataManagement::FindDataSet("Cd116_Pa234m"  ) , DataManagement::FindParameter("Internals") , 1.010        * 1e-3 )); DataManagement::FindComponent("Cd116_Pa234m_warm" )->SetFillColor( kViolet + 7 );
	DataManagement::AddComponent( new Component("Cd116_Tl207_warm"  , "^{207}Tl Warm region  " , DataManagement::FindDataSet("Cd116_Tl207"   ) , DataManagement::FindParameter("Internals") , 0.0e-3              )); DataManagement::FindComponent("Cd116_Tl207_warm"  )->SetFillColor( kViolet + 9 );
	DataManagement::AddComponent( new Component("Cd116_Pb211_warm"  , "^{211}Pb Warm region  " , DataManagement::FindDataSet("Cd116_Pb211"   ) , DataManagement::FindParameter("Internals") , 0.0e-3              )); DataManagement::FindComponent("Cd116_Pb211_warm"  )->SetFillColor( kViolet + 10 );
	                                                                                                                  
	DataManagement::AddComponent( new Component("Mylar_Bi214"       , "^{214}Bi Mylar        " , DataManagement::FindDataSet("Mylar_Bi214"   ) , DataManagement::FindParameter("Internals") ,  0.000653           )); DataManagement::FindComponent("Mylar_Bi214"       )->SetFillColor( kViolet - 1 );
	DataManagement::AddComponent( new Component("Mylar_Pb214"       , "^{214}Pb Mylar        " , DataManagement::FindDataSet("Mylar_Pb214"   ) , DataManagement::FindParameter("Internals") ,  0.000653           )); DataManagement::FindComponent("Mylar_Pb214"       )->SetFillColor( kViolet - 2 );

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define 2b2nu components
	//
	//////////////////////////////////////////////////////////////////////////////
	double n = (TMath::Na() * TMath::Log(2) * DataManagement::GetIsotopeMass()) / (DataManagement::GetIsotopeAtomicWeight() * 3.15569e7 /* s/y */) ;
	DataManagement::AddComponent( new Component("2b2nu" , "2e2#nu" , DataManagement::FindDataSet("Cd116_2b2n_m14" ) , DataManagement::FindParameter("2b2nu"), n)); DataManagement::FindComponent("2b2nu" )->SetFillColor( kRed );

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_cold = new Observable("e_energy_P1_cold" , "One electron energy - Phase 1 - Cold" , kPhaseOne , hcoll->Find("Data_h_e_energy_P1_cold") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P1_cold"    ) ); // Externals {
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P1_cold"  ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P1_cold" ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P1_cold" ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_cold"        ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P1_cold" ) ); // } Externals 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P1_cold"          ) ); // { Radon
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_cold"     ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P1_cold"   ) ); 
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P1"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P1"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P1"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_cold"      ) ); // } Radon
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_cold"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_cold"      ) ); // Internals {
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_cold"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_cold"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_cold"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_cold"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1_cold"   ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_cold"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"        ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold"     ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_cold"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_cold"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_cold"      ) );
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_cold"      ) ); // } Internals
	e_energy_P1_cold->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P1_cold"   ) );
	
	DataManagement::AddObservable( e_energy_P1_cold );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P2_cold
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P2_cold = new Observable("e_energy_P2_cold" , "One electron energy - Phase 2 - Cold" , kPhaseTwo , hcoll->Find("Data_h_e_energy_P2_cold") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P2_cold"    ) ); // Externals {
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P2_cold"  ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P2_cold" ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P2_cold" ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_cold"        ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P2_cold" ) ); // } Externals 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P2_cold"          ) ); // { Radon
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_cold"     ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P2_cold"   ) ); 
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Air_Bi214_P2"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Air_Pb214_P2"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P2"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P2"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P2"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_cold"      ) ); // } Radon
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_cold"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_cold"      ) ); // Internals {
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_cold"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_cold"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_cold"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_cold"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P2_cold"   ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_cold"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_K40_cold"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_cold"        ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_cold" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_cold"     ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_cold"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_cold"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_cold"      ) );
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_cold"      ) ); // } Internals
	e_energy_P2_cold->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P2_cold"   ) );
	
	DataManagement::AddObservable( e_energy_P2_cold );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P1_warm
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P1_warm = new Observable("e_energy_P1_warm" , "One electron energy - Phase 1 - Warm" , kPhaseOne , hcoll->Find("Data_h_e_energy_P1_warm") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P1_warm"    ) ); // Externals {
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P1_warm"  ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P1_warm" ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P1_warm" ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P1_warm"        ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P1_warm" ) ); // } Externals 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P1_warm"          ) ); // { Radon
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P1_warm"     ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P1_warm"   ) ); 
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Air_Bi214_P1"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Air_Pb214_P1"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P1"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P1"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P1"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P1"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P1"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P1"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P1"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P1"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P1"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P1"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P1_warm"      ) ); // } Radon
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_warm"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P1_warm"      ) ); // Internals {
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_warm"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_warm"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_warm"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_warm"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P1_warm"   ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_warm"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"        ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm"     ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_warm"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_warm"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P1_warm"      ) );
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P1_warm"      ) ); // } Internals
	e_energy_P1_warm->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P1_warm"   ) );
	
	DataManagement::AddObservable( e_energy_P1_warm );	

	//////////////////////////////////////////////////////////////////////////////
	//	
	// Define the observables e_energy_P2_warm
	//
	//////////////////////////////////////////////////////////////////////////////
	Observable * e_energy_P2_warm = new Observable("e_energy_P2_warm" , "One electron energy - Phase 2 - Warm" , kPhaseTwo , hcoll->Find("Data_h_e_energy_P2_warm") );
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Add components to fit and the respective histogram
	//
	//////////////////////////////////////////////////////////////////////////////
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "CuPetals_Co60"     ) , hcoll->Find( "CuPetals_Co60_h_e_energy_P2_warm"    ) ); // Externals {
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "CuTower_Co60"      ) , hcoll->Find( "CuTower_Co60_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "MuMetal_Co60"      ) , hcoll->Find( "MuMetal_Co60_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Co60"   ) , hcoll->Find( "SteelFrame_Co60_h_e_energy_P2_warm"  ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Ac228"    ) , hcoll->Find( "FeShield_Ac228_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Ac228"         ) , hcoll->Find( "PMT_Ac228_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Ac228"  ) , hcoll->Find( "SteelFrame_Ac228_h_e_energy_P2_warm" ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Bi214"    ) , hcoll->Find( "FeShield_Bi214_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Bi214"         ) , hcoll->Find( "PMT_Bi214_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Bi214"  ) , hcoll->Find( "SteelFrame_Bi214_h_e_energy_P2_warm" ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "FeShield_Tl208"    ) , hcoll->Find( "FeShield_Tl208_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_Tl208"         ) , hcoll->Find( "PMT_Tl208_h_e_energy_P2_warm"        ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_Tl208"  ) , hcoll->Find( "SteelFrame_Tl208_h_e_energy_P2_warm" ) ); // } Externals 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "PMT_K40"           ) , hcoll->Find( "PMT_K40_h_e_energy_P2_warm"          ) ); // { Radon
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintInn_K40"      ) , hcoll->Find( "ScintInn_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintOut_K40"      ) , hcoll->Find( "ScintOut_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "ScintPet_K40"      ) , hcoll->Find( "ScintPet_K40_h_e_energy_P2_warm"     ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SteelFrame_K40"    ) , hcoll->Find( "SteelFrame_K40_h_e_energy_P2_warm"   ) ); 
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Air_Bi214_P2"      ) , hcoll->Find( "Air_Bi214_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Air_Pb214_P2"      ) , hcoll->Find( "Air_Pb214_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi210_P2"    ) , hcoll->Find( "SFoil_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Bi214_P2"    ) , hcoll->Find( "SFoil_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SFoil_Pb214_P2"    ) , hcoll->Find( "SFoil_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi214_P2"    ) , hcoll->Find( "SWire_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Pb214_P2"    ) , hcoll->Find( "SWire_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi214_P2"    ) , hcoll->Find( "SScin_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Pb214_P2"    ) , hcoll->Find( "SScin_Pb214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SScin_Bi210_P2"    ) , hcoll->Find( "SScin_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Bi210_P2"    ) , hcoll->Find( "SWire_Bi210_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "SWire_Tl208_P2"    ) , hcoll->Find( "SWire_Tl208_h_e_energy_P2_warm"      ) ); // } Radon
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl208_warm"  ) , hcoll->Find( "Cd116_Tl208_h_e_energy_P2_warm"      ) ); // Internals {
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Ac228_warm"  ) , hcoll->Find( "Cd116_Ac228_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi212_warm"  ) , hcoll->Find( "Cd116_Bi212_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Bi214_warm"  ) , hcoll->Find( "Cd116_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb214_warm"  ) , hcoll->Find( "Cd116_pb214_VT_h_e_energy_P2_warm"   ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Cs137_warm"  ) , hcoll->Find( "Cd116_Cs137_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_K40_warm"    ) , hcoll->Find( "Cd116_K40_h_e_energy_P2_warm"        ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pa234m_warm" ) , hcoll->Find( "Cd116_Pa234m_h_e_energy_P2_warm"     ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Tl207_warm"  ) , hcoll->Find( "Cd116_Tl207_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Cd116_Pb211_warm"  ) , hcoll->Find( "Cd116_Pb211_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Mylar_Bi214"       ) , hcoll->Find( "Mylar_Bi214_h_e_energy_P2_warm"      ) );
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "Mylar_Pb214"       ) , hcoll->Find( "Mylar_Pb214_h_e_energy_P2_warm"      ) ); // } Internals
	e_energy_P2_warm->AddComponent( DataManagement::FindComponent( "2b2nu"             ) , hcoll->Find( "Cd116_2b2n_m14_h_e_energy_P2_warm"   ) );
	
	DataManagement::AddObservable( e_energy_P2_warm );	

	Fit::Run("Minuit", "Migrad");

	e_energy_P1_cold->Draw();
	e_energy_P1_warm->Draw();
	e_energy_P2_cold->Draw();
	e_energy_P2_warm->Draw();

}
