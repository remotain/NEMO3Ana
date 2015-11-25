// @(#)root/tmva $Id$
/**********************************************************************************
 * Project   : TMVA - a ROOT-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Root Macro: TMVAClassification                                                 *
 *                                                                                *
 * This macro provides examples for the training and testing of the               *
 * TMVA classifiers.                                                              *
 *                                                                                *
 * As input data is used a toy-MC sample consisting of four Gaussian-distributed  *
 * and linearly correlated input variables.                                       *
 *                                                                                *
 * The methods to be used can be switched on and off by means of booleans, or     *
 * via the prompt command, for example:                                           *
 *                                                                                *
 *    root -l ./TMVAClassification.C\(\"Fisher,Likelihood\"\)                     *
 *                                                                                *
 * (note that the backslashes are mandatory)                                      *
 * If no method given, a default set of classifiers is used.                      *
 *                                                                                *
 * The output file "TMVA.root" can be analysed with the use of dedicated          *
 * macros (simply say: root -l <macro.C>), which can be conveniently              *
 * invoked through a GUI that will appear at the end of the run of this macro.    *
 * Launch the GUI via the command:                                                *
 *                                                                                *
 *    root -l ./TMVAGui.C                                                         *
 *                                                                                *
 **********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"


#if not defined(__CINT__) || defined(__MAKECINT__)
// needs to be included when makecint runs (ACLIC)
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#endif

void TMVAClassification( TString myMethodList = "" , TString myModel = "")
{
   // The explicit loading of the shared libTMVA is done in TMVAlogon.C, defined in .rootrc
   // if you use your private .rootrc, or run from a different directory, please copy the
   // corresponding lines from .rootrc

   // methods to be processed can be given as an argument; use format:
   //
   // mylinux~> root -l TMVAClassification.C\(\"myMethod1,myMethod2,myMethod3\"\)
   //
   // if you like to use a method via the plugin mechanism, we recommend using
   //
   // mylinux~> root -l TMVAClassification.C\(\"P_myMethod\"\)
   // (an example is given for using the BDT as plugin (see below),
   // but of course the real application is when you write your own
   // method based)

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // to get access to the GUI and all tmva macros
    TString tmva_dir(TString(gRootDir) + "/tmva");
    if(gSystem->Getenv("TMVASYS"))
       tmva_dir = TString(gSystem->Getenv("TMVASYS"));
    gROOT->SetMacroPath(tmva_dir + "/test/:" + gROOT->GetMacroPath() );
    gROOT->ProcessLine(".L TMVAGui.C");



   // Default MVA methods to be trained + tested
   std::map<std::string,int> Use;

   // --- Cut optimisation
   Use["Cuts"]            = 0;
   Use["CutsD"]           = 0;
   Use["CutsPCA"]         = 0;
   Use["CutsGA"]          = 0;
   Use["CutsSA"]          = 0;
   // 
   // --- 1-dimensional likelihood ("naive Bayes estimator")
   Use["Likelihood"]      = 0;
   Use["LikelihoodD"]     = 0; // the "D" extension indicates decorrelated input variables (see option strings)
   Use["LikelihoodPCA"]   = 0; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
   Use["LikelihoodKDE"]   = 0;
   Use["LikelihoodMIX"]   = 0;
   //
   // --- Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"]           = 0;
   Use["PDERSD"]          = 0;
   Use["PDERSPCA"]        = 0;
   Use["PDEFoam"]         = 0;
   Use["PDEFoamBoost"]    = 0; // uses generalised MVA method boosting
   Use["KNN"]             = 0; // k-nearest neighbour method
   //
   // --- Linear Discriminant Analysis
   Use["LD"]              = 0; // Linear Discriminant identical to Fisher
   Use["Fisher"]          = 0;
   Use["FisherG"]         = 0;
   Use["BoostedFisher"]   = 0; // uses generalised MVA method boosting
   Use["HMatrix"]         = 0;
   //
   // --- Function Discriminant analysis
   Use["FDA_GA"]          = 0; // minimisation of user-defined function using Genetics Algorithm
   Use["FDA_SA"]          = 0;
   Use["FDA_MC"]          = 0;
   Use["FDA_MT"]          = 0;
   Use["FDA_GAMT"]        = 0;
   Use["FDA_MCMT"]        = 0;
   //
   // --- Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"]             = 0; // Recommended ANN
   Use["MLPBFGS"]         = 0; // Recommended ANN with optional training method
   Use["MLPBNN"]          = 0; // Recommended ANN with BFGS training method and bayesian regulator
   Use["CFMlpANN"]        = 0; // Depreciated ANN from ALEPH
   Use["TMlpANN"]         = 0; // ROOT's own ANN
   //
   // --- Support Vector Machine 
   Use["SVM"]             = 0;
   // 
   // --- Boosted Decision Trees
   Use["BDT"]             = 1; // uses Adaptive Boost
   Use["BDTG"]            = 0; // uses Gradient Boost
   Use["BDTB"]            = 0; // uses Bagging
   Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
   Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting 
   // 
   // --- Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"]         = 0;
   // ---------------------------------------------------------------

   // Default model to be trained + tested
   std::map<std::string,int> Model;

   // --- Cut optimisation
   Model[ "MM"  ]  = 0; // Mass mechanism
   Model[ "RHC" ]  = 0; // Right Handed Current
   Model[ "M1"  ]  = 0; // Majoron
   Model[ "M2"  ]  = 0; // Majoron
   Model[ "M3"  ]  = 0; // Majoron
   Model[ "M7"  ]  = 0; // Majoron

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;

   // Select methods (don't look at this code - not of interest)
   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
            std::cout << std::endl;
            return;
         }
         Use[regMethod] = 1;
      }
   }

   if(myModel != "") {
  	
		std::string regModel(myModel);
		
		if( Model.find(regModel) == Model.end() ){
			std::cout << "Model \"" << myModel << "\" not known in under this name. Choose among the following:" << std::endl;
			for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
			std::cout << std::endl;
			return;
		}
	   
		Model[regModel] = 1;
	
   } else {
   	
	   std::cout << "No signal model as been specified. You must choose one among the following:" << std::endl;
       for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
       std::cout << std::endl;
       return;
   }

    // --------------------------------------------------------------------------------------------------

    // --- Here the preparation phase begins

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString outfileName;
	outfileName.Form( "TMVA_%s.root", myModel.Data() );
	//TString outfileDir( "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_FINAL_TECHNOTE_20150921/TMVA/" );
	TString outfileDir( "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/TMVA/" );
	TFile* outputFile = TFile::Open( outfileDir + outfileName , "RECREATE" );
   
   // Create the factory object. Later you can choose the methods
   // whose performance you'd like to investigate. The factory is 
   // the only TMVA object you have to interact with
   //
   // The first argument is the base of the name of all the
   // weightfiles in the directory weight/
   //
   // The second argument is the output file for the training results
   // All TMVA output can be suppressed by removing the "!" (not) in
   // front of the "Silent" argument in the option string
	TString weightBaseName;
	weightBaseName.Form("TMVAClassification_%s", myModel.Data());	
   TMVA::Factory *factory = new TMVA::Factory( weightBaseName , outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification" );

   // If you wish to modify default settings
   // (please check "src/Config.h" to see all available global options)
   //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
   //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
   //factory->AddVariable( "myvar1 := var1+var2", 'F' );
   //factory->AddVariable( "myvar2 := var1-var2", "Expression 2", "", 'F' );
   //factory->AddVariable( "var3",                "Variable 3", "units", 'F' );
   //factory->AddVariable( "var4",                "Variable 4", "units", 'F' );

	factory->AddVariable( "min_el_en"                                                                   , 'F' );  
	factory->AddVariable( "max_el_en"                                                                   , 'F' );  
    factory->AddVariable( "el_en_asym := (max_el_en-min_el_en)/(min_el_en+max_el_en)"                   , 'F' );  
	factory->AddVariable( "el_en_sum := min_el_en+max_el_en"                                            , 'F' );  
	factory->AddVariable( "cos_theta"                                                                   , 'F' );
	factory->AddVariable( "prob_int"                                                                    , 'F' );
	factory->AddVariable( "min_el_track_len"                                                            , 'F' );       
	factory->AddVariable( "max_el_track_len"                                                            , 'F' );       
	factory->AddVariable( "min_el_curv := min_el_track_r*min_el_sign"                                   , 'F' );       
	factory->AddVariable( "max_el_curv := max_el_track_r*max_el_sign"                                   , 'F' );       
	factory->AddVariable( "max_vertex_s"                                                                , 'F' );       
	factory->AddVariable( "max_vertex_z"                                                                , 'F' );                 
	factory->AddVariable( "min_vertex_s"                                                                , 'F' );       
	factory->AddVariable( "min_vertex_z"                                                                , 'F' );                 
 
   // You can add so-called "Spectator variables", which are not used in the MVA training,
   // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
   // input variables, the response values of all trained MVAs, and the spectator variables
   //factory->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
   //factory->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );

   // Read training and test data
   // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
   //TString fdir = "/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/";
   TString fdir = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/";
   TString fname = "TwoElectronIntTree_NO_CHARGE_NO_VERTEX_CUT.root";
      
   TFile *input = TFile::Open( fdir + fname , "READ");
   
   std::cout << "--- TMVAClassification       : Using input file: " << input->GetName() << std::endl;
   
   TTree *  sig_tree    = 0;
   Double_t sig_weight  = 1.; 
   
   if ( Model[ "MM"  ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m1_tree"  ) ; 
   if ( Model[ "RHC" ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m2_tree"  ) ; 
   if ( Model[ "M1"  ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m5_tree"  ) ; 
   if ( Model[ "M2"  ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m15_tree" ) ; 
   if ( Model[ "M3"  ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m6_tree"  ) ; 
   if ( Model[ "M7"  ] ) sig_tree = (TTree*) input->Get( "Cd116_2b0n_m7_tree"  ) ; 

   factory->AddSignalTree( sig_tree , sig_weight );     

   //Double_t Cd116_2b0n_m1_weight  = 1.; 
   //TTree *  Cd116_2b0n_m1_tree    = (TTree*) input->Get("Cd116_2b0n_m1_tree"  ) ; 
   //factory->AddSignalTree( Cd116_2b0n_m1_tree , Cd116_2b0n_m1_weight     );     
   
   TTree *  Cd116_Tl208_tree       = (TTree*) input->Get("Cd116_Tl208_tree"    ) ; Double_t Cd116_Tl208_weight       =  7.06556           ; factory->AddBackgroundTree( Cd116_Tl208_tree       , Cd116_Tl208_weight       );
   TTree *  Cd116_Ac228_tree       = (TTree*) input->Get("Cd116_Ac228_tree"    ) ; Double_t Cd116_Ac228_weight       =  8.28423           ; factory->AddBackgroundTree( Cd116_Ac228_tree       , Cd116_Ac228_weight       );
   TTree *  Cd116_Bi212_tree       = (TTree*) input->Get("Cd116_Bi212_tree"    ) ; Double_t Cd116_Bi212_weight       =  3.35833           ; factory->AddBackgroundTree( Cd116_Bi212_tree       , Cd116_Bi212_weight       );
   TTree *  Cd116_Bi214_tree       = (TTree*) input->Get("Cd116_Bi214_tree"    ) ; Double_t Cd116_Bi214_weight       =  21.6569           ; factory->AddBackgroundTree( Cd116_Bi214_tree       , Cd116_Bi214_weight       );
   TTree *  Cd116_Pb214_tree       = (TTree*) input->Get("Cd116_Pb214_VT_tree" ) ; Double_t Cd116_Pb214_weight       =  0.22638           ; factory->AddBackgroundTree( Cd116_Pb214_tree       , Cd116_Pb214_weight       );
   TTree *  Mylar_Bi214_tree       = (TTree*) input->Get("Mylar_Bi214_tree"    ) ; Double_t Mylar_Bi214_weight       =   13.741           ; factory->AddBackgroundTree( Mylar_Bi214_tree       , Mylar_Bi214_weight       );
   TTree *  Mylar_Pb214_tree       = (TTree*) input->Get("Mylar_Pb214_tree"    ) ; Double_t Mylar_Pb214_weight       = 0.603642           ; factory->AddBackgroundTree( Mylar_Pb214_tree       , Mylar_Pb214_weight       );
   TTree *  Cd116_K40_tree         = (TTree*) input->Get("Cd116_K40_tree"      ) ; Double_t Cd116_K40_weight         =  10.9783+31.7262   ; factory->AddBackgroundTree( Cd116_K40_tree         , Cd116_K40_weight         );
   TTree *  Cd116_Pa234m_tree      = (TTree*) input->Get("Cd116_Pa234m_tree"   ) ; Double_t Cd116_Pa234m_weight      = 32.2618+86.295     ; factory->AddBackgroundTree( Cd116_Pa234m_tree      , Cd116_Pa234m_weight      );
   TTree *  SFoil_Bi210_tree       = (TTree*) input->Get("SFoil_Bi210_tree"    ) ; Double_t SFoil_Bi210_weight       = 1.64958+23.2437    ; factory->AddBackgroundTree( SFoil_Bi210_tree       , SFoil_Bi210_weight       );
   TTree *  SWire_Bi210_tree       = (TTree*) input->Get("SWire_Bi210_tree"    ) ; Double_t SWire_Bi210_weight       = 0.217523+1.28146   ; factory->AddBackgroundTree( SWire_Bi210_tree       , SWire_Bi210_weight       );
   TTree *  SScin_Bi210_tree       = (TTree*) input->Get("SScin_Bi210_tree"    ) ; Double_t SScin_Bi210_weight       =  3.5633            ; factory->AddBackgroundTree( SScin_Bi210_tree       , SScin_Bi210_weight       );
   TTree *  SScin_Bi214_tree       = (TTree*) input->Get("SScin_Bi214_tree"    ) ; Double_t SScin_Bi214_weight       = 3.03289            ; factory->AddBackgroundTree( SScin_Bi214_tree       , SScin_Bi214_weight       );
   TTree *  SScin_Pb214_tree       = (TTree*) input->Get("SScin_Pb214_tree"    ) ; Double_t SScin_Pb214_weight       =  0.0404384         ; factory->AddBackgroundTree( SScin_Pb214_tree       , SScin_Pb214_weight       );
   TTree *  SWire_Tl208_tree       = (TTree*) input->Get("SWire_Tl208_tree"    ) ; Double_t SWire_Tl208_weight       = 0.42948+2.3516     ; factory->AddBackgroundTree( SWire_Tl208_tree       , SWire_Tl208_weight       );
   TTree *  SWire_Bi214_P1_tree    = (TTree*) input->Get("SWire_Bi214_tree"    ) ; Double_t SWire_Bi214_weight       = 38.1982+34.6645    ; factory->AddBackgroundTree( SWire_Bi214_tree       , SWire_Bi214_weight       );
   TTree *  SFoil_Bi214_tree       = (TTree*) input->Get("SFoil_Bi214_tree"    ) ; Double_t SFoil_Bi214_weight       = 7.38274+3.47797    ; factory->AddBackgroundTree( SFoil_Bi214_tree       , SFoil_Bi214_weight       );   
   TTree *  SWire_Pb214_tree       = (TTree*) input->Get("SWire_Pb214_tree"    ) ; Double_t SWire_Pb214_weight       = 1.03586+1.34745    ; factory->AddBackgroundTree( SWire_Pb214_tree       , SWire_Pb214_weight       );   
   TTree *  SFoil_Pb214_tree       = (TTree*) input->Get("SFoil_Pb214_tree"    ) ; Double_t SFoil_Pb214_weight       = 0.341813+0.242809  ; factory->AddBackgroundTree( SFoil_Pb214_tree       , SFoil_Pb214_weight       );   
   TTree *  FeShield_Bi214_tree    = (TTree*) input->Get("FeShield_Bi214_tree" ) ; Double_t FeShield_Bi214_weight    =  122.319           ; factory->AddBackgroundTree( FeShield_Bi214_tree    , FeShield_Bi214_weight    );
   TTree *  FeShield_Tl208_tree    = (TTree*) input->Get("FeShield_Tl208_tree" ) ; Double_t FeShield_Tl208_weight    =  6.62106           ; factory->AddBackgroundTree( FeShield_Tl208_tree    , FeShield_Tl208_weight    );
   TTree *  FeShield_Ac228_tree    = (TTree*) input->Get("FeShield_Ac228_tree" ) ; Double_t FeShield_Ac228_weight    = 0.264067           ; factory->AddBackgroundTree( FeShield_Ac228_tree    , FeShield_Ac228_weight    );
   TTree *  CuTower_Co60_tree      = (TTree*) input->Get("CuTower_Co60_tree"   ) ; Double_t CuTower_Co60_weight      =  9.43038           ; factory->AddBackgroundTree( CuTower_Co60_tree      , CuTower_Co60_weight      );
   TTree *  Air_Bi214_P1_tree      = (TTree*) input->Get("Air_Bi214_tree"      ) ; Double_t Air_Bi214_P1_weight      = 23.7466            ; factory->AddBackgroundTree( Air_Bi214_P1_tree      , Air_Bi214_P1_weight      );
   TTree *  Air_Tl208_P1_tree      = (TTree*) input->Get("Air_Tl208_tree"      ) ; Double_t Air_Tl208_P1_weight      = 2.13679            ; factory->AddBackgroundTree( Air_Tl208_P1_tree      , Air_Tl208_P1_weight      );
   TTree *  PMT_Bi214_tree         = (TTree*) input->Get("PMT_Bi214_tree"      ) ; Double_t PMT_Bi214_weight         = 104.462            ; factory->AddBackgroundTree( PMT_Bi214_tree         , PMT_Bi214_weight         );
   TTree *  PMT_Tl208_tree         = (TTree*) input->Get("PMT_Tl208_tree"      ) ; Double_t PMT_Tl208_weight         =  154.14            ; factory->AddBackgroundTree( PMT_Tl208_tree         , PMT_Tl208_weight         );
   TTree *  PMT_Ac228_tree         = (TTree*) input->Get("PMT_Ac228_tree"      ) ; Double_t PMT_Ac228_weight         = 8.66286            ; factory->AddBackgroundTree( PMT_Ac228_tree         , PMT_Ac228_weight         );
   TTree *  PMT_K40_tree           = (TTree*) input->Get("PMT_K40_tree"        ) ; Double_t PMT_K40_weight           = 45.6541            ; factory->AddBackgroundTree( PMT_K40_tree           , PMT_K40_weight           );
   TTree *  ScintInn_K40_tree      = (TTree*) input->Get("ScintInn_K40_tree"   ) ; Double_t ScintInn_K40_weight      = 1.34227            ; factory->AddBackgroundTree( ScintInn_K40_tree      , ScintInn_K40_weight      );
   TTree *  ScintOut_K40_tree      = (TTree*) input->Get("ScintOut_K40_tree"   ) ; Double_t ScintOut_K40_weight      = 1.81207            ; factory->AddBackgroundTree( ScintOut_K40_tree      , ScintOut_K40_weight      );
   TTree *  ScintPet_K40_tree      = (TTree*) input->Get("ScintPet_K40_tree"   ) ; Double_t ScintPet_K40_weight      = 1.00669            ; factory->AddBackgroundTree( ScintPet_K40_tree      , ScintPet_K40_weight      );
   TTree *  MuMetal_Pa234m_tree    = (TTree*) input->Get("MuMetal_Pa234m_tree" ) ; Double_t MuMetal_Pa234m_weight    = 1.67054            ; factory->AddBackgroundTree( MuMetal_Pa234m_tree    , MuMetal_Pa234m_weight    );
   TTree *  Cd116_2b2n_m14_tree    = (TTree*) input->Get("Cd116_2b2n_m14_tree" ) ; Double_t Cd116_2b2n_m14_weight    = 5935.43            ; factory->AddBackgroundTree( Cd116_2b2n_m14_tree    , Cd116_2b2n_m14_weight    );
   

   // --- end of tree registration 

   // Set individual event weights (the variables must exist in the original TTree)
   //    for signal    : factory->SetSignalWeightExpression    ("weight1*weight2");
   //    for background: factory->SetBackgroundWeightExpression("weight1*weight2");
   factory->SetBackgroundWeightExpression( "weight" );

   // Apply additional cuts on the signal and background samples (can be different)
	
	// Apply cut on charge
	//TCut mycuts = "min_el_sign < 0 && max_el_sign < 0.";
	//TCut mycutb = "min_el_sign < 0 && max_el_sign < 0.";

	// Apply cut on vertex
	//TCut mycuts = "((max_vertex_x - min_vertex_x)**2 + (max_vertex_y - min_vertex_y)**2 <= 4**2)&&((max_vertex_z-min_vertex_z)**2<8**2)"; 
	//TCut mycutb = "((max_vertex_x - min_vertex_x)**2 + (max_vertex_y - min_vertex_y)**2 <= 4**2)&&((max_vertex_z-min_vertex_z)**2<8**2)"; 

	TCut mycuts = ""; 
	TCut mycutb = "";

   // Tell the factory how to use the training and testing events
   //
   // If no numbers of events are given, half of the events in the tree are used 
   // for training, and the other half for testing:
   //    factory->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
   // To also specify the number of testing events, use:
   //    factory->PrepareTrainingAndTestTree( mycut,
   //                                         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" );
   
   factory->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

   // ---- Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   // Cut optimisation
   if (Use["Cuts"])
      factory->BookMethod( TMVA::Types::kCuts, "Cuts",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart" );

   if (Use["CutsD"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsD",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=Decorrelate" );

   if (Use["CutsPCA"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsPCA",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=PCA" );

   if (Use["CutsGA"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsGA",
                           "H:!V:FitMethod=GA:CutRangeMin[0]=-10:CutRangeMax[0]=10:VarProp[1]=FMax:EffSel:Steps=30:Cycles=3:PopSize=400:SC_steps=10:SC_rate=5:SC_factor=0.95" );

   if (Use["CutsSA"])
      factory->BookMethod( TMVA::Types::kCuts, "CutsSA",
                           "!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   // Likelihood ("naive Bayes estimator")
   if (Use["Likelihood"])
      factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood",
                           "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );

   // Decorrelated likelihood
   if (Use["LikelihoodD"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodD",
                           "!H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate" );

   // PCA-transformed likelihood
   if (Use["LikelihoodPCA"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodPCA",
                           "!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA" ); 

   // Use a kernel density estimator to approximate the PDFs
   if (Use["LikelihoodKDE"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodKDE",
                           "!H:!V:!TransformOutput:PDFInterpol=KDE:KDEtype=Gauss:KDEiter=Adaptive:KDEFineFactor=0.3:KDEborder=None:NAvEvtPerBin=50" ); 

   // Use a variable-dependent mix of splines and kernel density estimator
   if (Use["LikelihoodMIX"])
      factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodMIX",
                           "!H:!V:!TransformOutput:PDFInterpolSig[0]=KDE:PDFInterpolBkg[0]=KDE:PDFInterpolSig[1]=KDE:PDFInterpolBkg[1]=KDE:PDFInterpolSig[2]=Spline2:PDFInterpolBkg[2]=Spline2:PDFInterpolSig[3]=Spline2:PDFInterpolBkg[3]=Spline2:KDEtype=Gauss:KDEiter=Nonadaptive:KDEborder=None:NAvEvtPerBin=50" ); 

   // Test the multi-dimensional probability density estimator
   // here are the options strings for the MinMax and RMS methods, respectively:
   //      "!H:!V:VolumeRangeMode=MinMax:DeltaFrac=0.2:KernelEstimator=Gauss:GaussSigma=0.3" );
   //      "!H:!V:VolumeRangeMode=RMS:DeltaFrac=3:KernelEstimator=Gauss:GaussSigma=0.3" );
   if (Use["PDERS"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERS",
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600" );

   if (Use["PDERSD"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERSD",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=Decorrelate" );

   if (Use["PDERSPCA"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERSPCA",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=PCA" );

   // Multi-dimensional likelihood estimator using self-adapting phase-space binning
   if (Use["PDEFoam"])
      factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoam",
                           "!H:!V:SigBgSeparate=F:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" );

   if (Use["PDEFoamBoost"])
      factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoamBoost",
                           "!H:!V:Boost_Num=30:Boost_Transform=linear:SigBgSeparate=F:MaxDepth=4:UseYesNoCell=T:DTLogic=MisClassificationError:FillFoamWithOrigWeights=F:TailCut=0:nActiveCells=500:nBin=20:Nmin=400:Kernel=None:Compress=T" );

   // K-Nearest Neighbour classifier (KNN)
   if (Use["KNN"])
      factory->BookMethod( TMVA::Types::kKNN, "KNN",
                           "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   // H-Matrix (chi2-squared) method
   if (Use["HMatrix"])
      factory->BookMethod( TMVA::Types::kHMatrix, "HMatrix", "!H:!V:VarTransform=None" );

   // Linear discriminant (same as Fisher discriminant)
   if (Use["LD"])
      factory->BookMethod( TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher discriminant (same as LD)
   if (Use["Fisher"])
      factory->BookMethod( TMVA::Types::kFisher, "Fisher", "H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher with Gauss-transformed input variables
   if (Use["FisherG"])
      factory->BookMethod( TMVA::Types::kFisher, "FisherG", "H:!V:VarTransform=Gauss" );

   // Composite classifier: ensemble (tree) of boosted Fisher classifiers
   if (Use["BoostedFisher"])
      factory->BookMethod( TMVA::Types::kFisher, "BoostedFisher", 
                           "H:!V:Boost_Num=20:Boost_Transform=log:Boost_Type=AdaBoost:Boost_AdaBoostBeta=0.2:!Boost_DetailedMonitoring" );

   // Function discrimination analysis (FDA) -- test of various fitters - the recommended one is Minuit (or GA or SA)
   if (Use["FDA_MC"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MC",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:SampleSize=100000:Sigma=0.1" );

   if (Use["FDA_GA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:PopSize=300:Cycles=3:Steps=20:Trim=True:SaveBestGen=1" );

   if (Use["FDA_SA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_SA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=SA:MaxCalls=15000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   if (Use["FDA_MT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=2:UseImprove:UseMinos:SetBatch" );

   if (Use["FDA_GAMT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GAMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:Cycles=1:PopSize=5:Steps=5:Trim" );

   if (Use["FDA_MCMT"])
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MCMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:SampleSize=20" );

   // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
   if (Use["MLP"])
      factory->BookMethod( TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator" );

   if (Use["MLPBFGS"])
      factory->BookMethod( TMVA::Types::kMLP, "MLPBFGS", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:!UseRegulator" );

   if (Use["MLPBNN"])
      factory->BookMethod( TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" ); // BFGS training with bayesian regulators

   // CF(Clermont-Ferrand)ANN
   if (Use["CFMlpANN"])
      factory->BookMethod( TMVA::Types::kCFMlpANN, "CFMlpANN", "!H:!V:NCycles=2000:HiddenLayers=N+1,N"  ); // n_cycles:#nodes:#nodes:...  

   // Tmlp(Root)ANN
   if (Use["TMlpANN"])
      factory->BookMethod( TMVA::Types::kTMlpANN, "TMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N:LearningMethod=BFGS:ValidationFraction=0.3"  ); // n_cycles:#nodes:#nodes:...

   // Support Vector Machine
   if (Use["SVM"])
      factory->BookMethod( TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm" );

   // Boosted Decision Trees
   if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

   if (Use["BDT"])  // Adaptive Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTB"]) // Bagging
      factory->BookMethod( TMVA::Types::kBDT, "BDTB",
                           "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod( TMVA::Types::kBDT, "BDTD",
                           "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );

   if (Use["BDTF"])  // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod( TMVA::Types::kBDT, "BDTMitFisher",
                           "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=-1" );

   // RuleFit -- TMVA implementation of Friedman's method
   if (Use["RuleFit"])
      factory->BookMethod( TMVA::Types::kRuleFit, "RuleFit",
                           "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02" );

   // For an example of the category classifier usage, see: TMVAClassificationCategory

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can optimize the setting (configuration) of the MVAs using the set of training events

   // ---- STILL EXPERIMENTAL and only implemented for BDT's ! 
   // factory->OptimizeAllMethods("SigEffAt001","Scan");
   // factory->OptimizeAllMethods("ROCIntegral","FitGA");

   // --------------------------------------------------------------------------------------------------

   // ---- Now you can tell the factory to train, test, and evaluate the MVAs

   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;

   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()) TMVAGui( outfileDir + outfileName );
}
