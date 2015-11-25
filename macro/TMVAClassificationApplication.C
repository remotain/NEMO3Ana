/**********************************************************************************

 * Package   : TMVA                                                               *
 * Exectuable: TMVAClassificationApplication                                      *
 *                                                                                *
 * This macro provides a simple example on how to use the trained classifiers     *
 * within an analysis module                                                      *
 **********************************************************************************/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#if not defined(__CINT__) || defined(__MAKECINT__)
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"
#endif

using namespace TMVA;

void TMVAClassificationApplication( TString myMethodList = "", TString myModel = "") 
{   
#ifdef __CINT__
   gROOT->ProcessLine( ".O0" ); // turn off optimization in CINT
#endif
   
	// Input/Output file path
   //TString fdir = "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/";
   //TString fdir = "/sps/nemo/scratch/remoto/nemo3/plot/plot_FINAL_TECHNOTE_20150921/";
   TString fdir = "/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/";

	// Weights file path
   //TString wdir    = "/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/weights/";	
   TString wdir    = "/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/weights/";	

   //---------------------------------------------------------------

   // This loads the library
   TMVA::Tools::Instance();

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
   // 
   // --- Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"]         = 0;
   // ---------------------------------------------------------------
   Use["Plugin"]          = 0;
   Use["Category"]        = 0;
   Use["SVM_Gauss"]       = 0;
   Use["SVM_Poly"]        = 0;
   Use["SVM_Lin"]         = 0;

   // Default model
   std::map<std::string,int> Model;

   // --- Cut optimisation
   Model[ "MM"  ]  = 0; // Mass mechanism
   Model[ "RHC" ]  = 0; // Right Handed Current
   Model[ "M1"  ]  = 0; // Majoron
   Model[ "M2"  ]  = 0; // Majoron
   Model[ "M3"  ]  = 0; // Majoron
   Model[ "M7"  ]  = 0; // Majoron


   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   // Select methods (don't look at this code - not of interest)
   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod 
                      << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
               std::cout << it->first << " ";
            }
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

   // --- Create the Reader object

   TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );    

   // Create a set of variables and declare them to the reader
   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
	Float_t min_el_en;
	Float_t max_el_en;
	Float_t el_en_asym;
	Float_t el_en_sum;
	Float_t cos_theta;
	Float_t prob_int;
	Float_t min_el_track_len;
	Float_t max_el_track_len;
	Float_t min_el_curv;
	Float_t max_el_curv;
	Float_t max_vertex_s;
	Float_t max_vertex_z;
	Float_t min_vertex_s;
	Float_t min_vertex_z;

   reader->AddVariable( "min_el_en"                                                 , &min_el_en        );
   reader->AddVariable( "max_el_en"                                                 , &max_el_en        );
   reader->AddVariable( "el_en_asym := (max_el_en-min_el_en)/(min_el_en+max_el_en)" , &el_en_asym       );
   reader->AddVariable( "el_en_sum := min_el_en+max_el_en"                          , &el_en_sum        );
   reader->AddVariable( "cos_theta"                                                 , &cos_theta        );
   reader->AddVariable( "prob_int"                                                  , &prob_int         );
   reader->AddVariable( "min_el_track_len"                                          , &min_el_track_len );
   reader->AddVariable( "max_el_track_len"                                          , &max_el_track_len );
   reader->AddVariable( "min_el_curv := min_el_track_r*min_el_sign"                 , &min_el_curv      );
   reader->AddVariable( "max_el_curv := max_el_track_r*max_el_sign"                 , &max_el_curv      );
   reader->AddVariable( "max_vertex_s"                                              , &max_vertex_s     );
   reader->AddVariable( "max_vertex_z"                                              , &max_vertex_z     );
   reader->AddVariable( "min_vertex_s"                                              , &min_vertex_s     );
   reader->AddVariable( "min_vertex_z"                                              , &min_vertex_z     );
   
   //// Spectator variables declared in the training have to be added to the reader, too
   //Float_t spec1,spec2;
   //reader->AddSpectator( "spec1 := var1*2",   &spec1 );
   //reader->AddSpectator( "spec2 := var1*3",   &spec2 );
   //
   //Float_t Category_cat1, Category_cat2, Category_cat3;
   //if (Use["Category"]){
   //   // Add artificial spectators for distinguishing categories
   //   reader->AddSpectator( "Category_cat1 := var3<=0",             &Category_cat1 );
   //   reader->AddSpectator( "Category_cat2 := (var3>0)&&(var4<0)",  &Category_cat2 );
   //   reader->AddSpectator( "Category_cat3 := (var3>0)&&(var4>=0)", &Category_cat3 );
   //}

   TString fname = "TwoElectronIntTree_NO_CHARGE_NO_VERTEX_CUT.root";	
   TFile *input = TFile::Open( fdir + fname , "READ");
   
   if (!input) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }
   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;

   // Recreate the otput file (delete existing file)
   //TFile *target  = new TFile( fdir + "TMVApp.root","RECREATE" );
   //target.Close();

   // List of three to consider
   std::vector<std::string> samples;
   samples.push_back("Data");                   // 1
   samples.push_back("Cd116_Tl208");
   samples.push_back("Cd116_Ac228");
   samples.push_back("Cd116_Bi212");
   samples.push_back("Cd116_Bi214");
   samples.push_back("Cd116_Pb214_VT");
   samples.push_back("Mylar_Bi214");
   samples.push_back("Mylar_Pb214");
   samples.push_back("Cd116_K40");
   samples.push_back("Cd116_Pa234m");
   samples.push_back("SFoil_Bi210");
   samples.push_back("SWire_Bi210");
   samples.push_back("SScin_Bi210");
   samples.push_back("SScin_Bi214");
   samples.push_back("SWire_Tl208");
   samples.push_back("SWire_Bi214");
   samples.push_back("SFoil_Bi214");
   samples.push_back("SWire_Pb214");
   samples.push_back("SFoil_Pb214");
   samples.push_back("FeShield_Bi214");
   samples.push_back("FeShield_Tl208");
   samples.push_back("FeShield_Ac228");
   samples.push_back("CuTower_Co60");
   samples.push_back("Air_Bi214");
   samples.push_back("PMT_Bi214");
   samples.push_back("PMT_Tl208");
   samples.push_back("PMT_Ac228");
   samples.push_back("PMT_K40");
   samples.push_back("ScintInn_K40");
   samples.push_back("ScintOut_K40");
   samples.push_back("ScintPet_K40");
   samples.push_back("MuMetal_Pa234m");
   samples.push_back("Cd116_2b2n_m14");
   
   
   if ( Model[ "MM"  ] ) samples.push_back( "Cd116_2b0n_m1"  ) ; // 34
   if ( Model[ "RHC" ] ) samples.push_back( "Cd116_2b0n_m2"  ) ; // 34
   if ( Model[ "M1"  ] ) samples.push_back( "Cd116_2b0n_m5"  ) ; // 34
   if ( Model[ "M2"  ] ) samples.push_back( "Cd116_2b0n_m15" ) ; // 34
   if ( Model[ "M3"  ] ) samples.push_back( "Cd116_2b0n_m6"  ) ; // 34
   if ( Model[ "M7"  ] ) samples.push_back( "Cd116_2b0n_m7"  ) ; // 34


   // --- Book the MVA methods
	TString prefix;
	prefix.Form("TMVAClassification_%s", myModel.Data());

   // Book method(s)
   for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) {
      if (it->second) {
         TString methodName = TString(it->first) + TString(" method");
         TString weightfile = wdir + prefix + TString("_") + TString(it->first) + TString(".weights.xml");
         reader->BookMVA( methodName, weightfile ); 
      }
   }
   
   for(std::vector<std::string>::iterator spit = samples.begin(); spit !=samples.end(); spit++) { 

   	   // Book output histograms
	   UInt_t nbin = 100;
	   TH1F   *histLk(0), *histLkD(0), *histLkPCA(0), *histLkKDE(0), *histLkMIX(0), *histPD(0), *histPDD(0);
	   TH1F   *histPDPCA(0), *histPDEFoam(0), *histPDEFoamErr(0), *histPDEFoamSig(0), *histKNN(0), *histHm(0);
	   TH1F   *histFi(0), *histFiG(0), *histFiB(0), *histLD(0), *histNn(0),*histNnbfgs(0),*histNnbnn(0);
	   TH1F   *histNnC(0), *histNnT(0), *histBdt(0), *histBdtG(0), *histBdtD(0), *histRf(0), *histSVMG(0);
	   TH1F   *histSVMP(0), *histSVML(0), *histFDAMT(0), *histFDAGA(0), *histCat(0), *histPBdt(0);
	   
	   if (Use["Likelihood"])    histLk      = new TH1F( TString(*spit) + "_" + "MVA_Likelihood"    ,  TString(*spit) + "_" + "MVA_Likelihood"    , nbin, -1, 1 );
	   if (Use["LikelihoodD"])   histLkD     = new TH1F( TString(*spit) + "_" + "MVA_LikelihoodD"   ,  TString(*spit) + "_" + "MVA_LikelihoodD"   , nbin, -1, 0.9999 );
	   if (Use["LikelihoodPCA"]) histLkPCA   = new TH1F( TString(*spit) + "_" + "MVA_LikelihoodPCA" ,  TString(*spit) + "_" + "MVA_LikelihoodPCA" , nbin, -1, 1 );
	   if (Use["LikelihoodKDE"]) histLkKDE   = new TH1F( TString(*spit) + "_" + "MVA_LikelihoodKDE" ,  TString(*spit) + "_" + "MVA_LikelihoodKDE" , nbin, -0.00001, 0.99999 );
	   if (Use["LikelihoodMIX"]) histLkMIX   = new TH1F( TString(*spit) + "_" + "MVA_LikelihoodMIX" ,  TString(*spit) + "_" + "MVA_LikelihoodMIX" , nbin,  0, 1 );
	   if (Use["PDERS"])         histPD      = new TH1F( TString(*spit) + "_" + "MVA_PDERS"         ,  TString(*spit) + "_" + "MVA_PDERS"         , nbin,  0, 1 );
	   if (Use["PDERSD"])        histPDD     = new TH1F( TString(*spit) + "_" + "MVA_PDERSD"        ,  TString(*spit) + "_" + "MVA_PDERSD"        , nbin,  0, 1 );
	   if (Use["PDERSPCA"])      histPDPCA   = new TH1F( TString(*spit) + "_" + "MVA_PDERSPCA"      ,  TString(*spit) + "_" + "MVA_PDERSPCA"      , nbin,  0, 1 );
	   if (Use["KNN"])           histKNN     = new TH1F( TString(*spit) + "_" + "MVA_KNN"           ,  TString(*spit) + "_" + "MVA_KNN"           , nbin,  0, 1 );
	   if (Use["HMatrix"])       histHm      = new TH1F( TString(*spit) + "_" + "MVA_HMatrix"       ,  TString(*spit) + "_" + "MVA_HMatrix"       , nbin, -0.95, 1.55 );
	   if (Use["Fisher"])        histFi      = new TH1F( TString(*spit) + "_" + "MVA_Fisher"        ,  TString(*spit) + "_" + "MVA_Fisher"        , nbin, -4, 4 );
	   if (Use["FisherG"])       histFiG     = new TH1F( TString(*spit) + "_" + "MVA_FisherG"       ,  TString(*spit) + "_" + "MVA_FisherG"       , nbin, -1, 1 );
	   if (Use["BoostedFisher"]) histFiB     = new TH1F( TString(*spit) + "_" + "MVA_BoostedFisher" ,  TString(*spit) + "_" + "MVA_BoostedFisher" , nbin, -2, 2 );
	   if (Use["LD"])            histLD      = new TH1F( TString(*spit) + "_" + "MVA_LD"            ,  TString(*spit) + "_" + "MVA_LD"            , nbin, -2, 2 );
	   if (Use["MLP"])           histNn      = new TH1F( TString(*spit) + "_" + "MVA_MLP"           ,  TString(*spit) + "_" + "MVA_MLP"           , nbin, -1.25, 1.5 );
	   if (Use["MLPBFGS"])       histNnbfgs  = new TH1F( TString(*spit) + "_" + "MVA_MLPBFGS"       ,  TString(*spit) + "_" + "MVA_MLPBFGS"       , nbin, -1.25, 1.5 );
	   if (Use["MLPBNN"])        histNnbnn   = new TH1F( TString(*spit) + "_" + "MVA_MLPBNN"        ,  TString(*spit) + "_" + "MVA_MLPBNN"        , nbin, -1.25, 1.5 );
	   if (Use["CFMlpANN"])      histNnC     = new TH1F( TString(*spit) + "_" + "MVA_CFMlpANN"      ,  TString(*spit) + "_" + "MVA_CFMlpANN"      , nbin,  0, 1 );
	   if (Use["TMlpANN"])       histNnT     = new TH1F( TString(*spit) + "_" + "MVA_TMlpANN"       ,  TString(*spit) + "_" + "MVA_TMlpANN"       , nbin, -1.3, 1.3 );
	   if (Use["BDT"])           histBdt     = new TH1F( TString(*spit) + "_" + "MVA_BDT"           ,  TString(*spit) + "_" + "MVA_BDT"           , nbin, -0.8, 0.8 );
	   if (Use["BDTD"])          histBdtD    = new TH1F( TString(*spit) + "_" + "MVA_BDTD"          ,  TString(*spit) + "_" + "MVA_BDTD"          , nbin, -0.8, 0.8 );
	   if (Use["BDTG"])          histBdtG    = new TH1F( TString(*spit) + "_" + "MVA_BDTG"          ,  TString(*spit) + "_" + "MVA_BDTG"          , nbin, -1.0, 1.0 );
	   if (Use["RuleFit"])       histRf      = new TH1F( TString(*spit) + "_" + "MVA_RuleFit"       ,  TString(*spit) + "_" + "MVA_RuleFit"       , nbin, -2.0, 2.0 );
	   if (Use["SVM_Gauss"])     histSVMG    = new TH1F( TString(*spit) + "_" + "MVA_SVM_Gauss"     ,  TString(*spit) + "_" + "MVA_SVM_Gauss"     , nbin,  0.0, 1.0 );
	   if (Use["SVM_Poly"])      histSVMP    = new TH1F( TString(*spit) + "_" + "MVA_SVM_Poly"      ,  TString(*spit) + "_" + "MVA_SVM_Poly"      , nbin,  0.0, 1.0 );
	   if (Use["SVM_Lin"])       histSVML    = new TH1F( TString(*spit) + "_" + "MVA_SVM_Lin"       ,  TString(*spit) + "_" + "MVA_SVM_Lin"       , nbin,  0.0, 1.0 );
	   if (Use["FDA_MT"])        histFDAMT   = new TH1F( TString(*spit) + "_" + "MVA_FDA_MT"        ,  TString(*spit) + "_" + "MVA_FDA_MT"        , nbin, -2.0, 3.0 );
	   if (Use["FDA_GA"])        histFDAGA   = new TH1F( TString(*spit) + "_" + "MVA_FDA_GA"        ,  TString(*spit) + "_" + "MVA_FDA_GA"        , nbin, -2.0, 3.0 );
	   if (Use["Category"])      histCat     = new TH1F( TString(*spit) + "_" + "MVA_Category"      ,  TString(*spit) + "_" + "MVA_Category"      , nbin, -2., 2. );
	   if (Use["Plugin"])        histPBdt    = new TH1F( TString(*spit) + "_" + "MVA_PBDT"          ,  TString(*spit) + "_" + "MVA_BDT"           , nbin, -0.8, 0.8 );

  	    // PDEFoam also returns per-event error, fill in histogram, and also fill significance
  	   if (Use["PDEFoam"]) {
		   histPDEFoam    = new TH1F( TString(*spit) + "_" + "MVA_PDEFoam"    , TString(*spit) + "_" + "MVA_PDEFoam"              ,nbin,  0, 1 );
  	       histPDEFoamErr = new TH1F( TString(*spit) + "_" + "MVA_PDEFoamErr" , TString(*spit) + "_" + "MVA_PDEFoam error"        ,nbin,  0, 1 );
  	       histPDEFoamSig = new TH1F( TString(*spit) + "_" + "MVA_PDEFoamSig" , TString(*spit) + "_" + "MVA_PDEFoam significance" ,nbin,  0, 10 );
  	   }

  	   // Book example histogram for probability (the other methods are done similarly)
  	   TH1F *probHistFi(0), *rarityHistFi(0);
  	   if (Use["Fisher"]) {
		   probHistFi   = new TH1F( TString(*spit) + "_" + "MVA_Fisher_Proba"  , TString(*spit) + "_" + "MVA_Fisher_Proba"  , nbin, 0, 1 );
  	       rarityHistFi = new TH1F( TString(*spit) + "_" + "MVA_Fisher_Rarity" , TString(*spit) + "_" + "MVA_Fisher_Rarity" , nbin, 0, 1 );
  	   } 

       // Prepare input tree (this must be replaced by your data source)
       // in this example, there is a toy tree with signal and one with background events
       // we'll later on use only the "signal" events for the test in this example.
       //   
	   // --- Event loop
	   // Prepare the event tree
	   // - here the variable names have to corresponds to your tree
	   // - you can use the same variables as above which is slightly faster,
	   //   but of course you can use different ones and copy the values inside the event loop
	   //
   	   std::cout << "--- Select " << TString(*spit) << " sample" << std::endl;
   	   TTree* theTree = (TTree*)input->Get(TString(*spit) + "_tree");

		Double_t b_min_el_en, b_max_el_en;
		Double_t b_cos_theta, b_prob_int;
		Double_t b_min_el_track_len, b_max_el_track_len;
		Double_t b_min_el_track_r, b_max_el_track_r;
		Double_t b_min_el_sign, b_max_el_sign;
		Double_t b_max_vertex_s, b_max_vertex_z, b_min_vertex_s, b_min_vertex_z;

   
   	   theTree->SetBranchAddress( "min_el_en"        , &b_min_el_en        );
   	   theTree->SetBranchAddress( "max_el_en"        , &b_max_el_en        );
   	   theTree->SetBranchAddress( "cos_theta"        , &b_cos_theta        );
   	   theTree->SetBranchAddress( "prob_int"         , &b_prob_int         );
   	   theTree->SetBranchAddress( "min_el_track_len" , &b_min_el_track_len );
   	   theTree->SetBranchAddress( "max_el_track_len" , &b_max_el_track_len );
   	   theTree->SetBranchAddress( "min_el_track_r"   , &b_min_el_track_r   );
   	   theTree->SetBranchAddress( "max_el_track_r"   , &b_max_el_track_r   );
   	   theTree->SetBranchAddress( "min_el_sign"      , &b_min_el_sign      );
   	   theTree->SetBranchAddress( "max_el_sign"      , &b_max_el_sign      );
   	   theTree->SetBranchAddress( "min_el_sign"      , &b_min_el_sign      );
   	   theTree->SetBranchAddress( "max_el_sign"      , &b_max_el_sign      );
   	   theTree->SetBranchAddress( "max_vertex_s"     , &b_max_vertex_s     );
   	   theTree->SetBranchAddress( "max_vertex_z"     , &b_max_vertex_z     );
   	   theTree->SetBranchAddress( "min_vertex_s"     , &b_min_vertex_s     );
   	   theTree->SetBranchAddress( "min_vertex_z"     , &b_min_vertex_z     );

                                                 
       // Efficiency calculator for cut method
       Int_t    nSelCutsGA = 0;
       Double_t effS       = 0.7;

       std::vector<Float_t> vecVar(4); // vector for EvaluateMVA tests

       std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;
       TStopwatch sw;
       sw.Start();
       for (Long64_t ievt=0; ievt<theTree->GetEntries();ievt++) {
       //for (Long64_t ievt=0; ievt<1000;ievt++) {
       
          if (ievt%1000 == 0) std::cout << "--- ... Processing event: " << ievt << std::endl;
       
          theTree->GetEntry(ievt);
       
       		min_el_en        = b_min_el_en;       
       		max_el_en        = b_max_el_en;       
       		cos_theta        = b_cos_theta;       
       		prob_int         = b_prob_int;        
       		min_el_track_len = b_min_el_track_len;
       		max_el_track_len = b_max_el_track_len;
       		min_el_track_r   = b_min_el_track_r;
       		max_el_track_r   = b_max_el_track_r;
       		min_el_sign      = b_min_el_sign;
       		max_el_sign      = b_max_el_sign;
       
       		el_en_asym = (max_el_en-min_el_en)/(min_el_en+max_el_en);
       		el_en_sum = min_el_en+max_el_en;                        
       	 	
			min_el_curv = min_el_sign * min_el_track_r;
			max_el_curv = max_el_sign * max_el_track_r;
	   
			max_vertex_s = b_max_vertex_s; 
			max_vertex_z = b_max_vertex_z; 
			min_vertex_s = b_min_vertex_s; 
			min_vertex_z = b_min_vertex_z;
	   
          // --- Return the MVA outputs and fill into histograms
       
          if (Use["CutsGA"]) {
             // Cuts is a special case: give the desired signal efficienciy
             Bool_t passed = reader->EvaluateMVA( "CutsGA method", effS );
             if (passed) nSelCutsGA++;
          }
       
          if (Use["Likelihood"   ])   histLk     ->Fill( reader->EvaluateMVA( "Likelihood method"    ) );
          if (Use["LikelihoodD"  ])   histLkD    ->Fill( reader->EvaluateMVA( "LikelihoodD method"   ) );
          if (Use["LikelihoodPCA"])   histLkPCA  ->Fill( reader->EvaluateMVA( "LikelihoodPCA method" ) );
          if (Use["LikelihoodKDE"])   histLkKDE  ->Fill( reader->EvaluateMVA( "LikelihoodKDE method" ) );
          if (Use["LikelihoodMIX"])   histLkMIX  ->Fill( reader->EvaluateMVA( "LikelihoodMIX method" ) );
          if (Use["PDERS"        ])   histPD     ->Fill( reader->EvaluateMVA( "PDERS method"         ) );
          if (Use["PDERSD"       ])   histPDD    ->Fill( reader->EvaluateMVA( "PDERSD method"        ) );
          if (Use["PDERSPCA"     ])   histPDPCA  ->Fill( reader->EvaluateMVA( "PDERSPCA method"      ) );
          if (Use["KNN"          ])   histKNN    ->Fill( reader->EvaluateMVA( "KNN method"           ) );
          if (Use["HMatrix"      ])   histHm     ->Fill( reader->EvaluateMVA( "HMatrix method"       ) );
          if (Use["Fisher"       ])   histFi     ->Fill( reader->EvaluateMVA( "Fisher method"        ) );
          if (Use["FisherG"      ])   histFiG    ->Fill( reader->EvaluateMVA( "FisherG method"       ) );
          if (Use["BoostedFisher"])   histFiB    ->Fill( reader->EvaluateMVA( "BoostedFisher method" ) );
          if (Use["LD"           ])   histLD     ->Fill( reader->EvaluateMVA( "LD method"            ) );
          if (Use["MLP"          ])   histNn     ->Fill( reader->EvaluateMVA( "MLP method"           ) );
          if (Use["MLPBFGS"      ])   histNnbfgs ->Fill( reader->EvaluateMVA( "MLPBFGS method"       ) );
          if (Use["MLPBNN"       ])   histNnbnn  ->Fill( reader->EvaluateMVA( "MLPBNN method"        ) );
          if (Use["CFMlpANN"     ])   histNnC    ->Fill( reader->EvaluateMVA( "CFMlpANN method"      ) );
          if (Use["TMlpANN"      ])   histNnT    ->Fill( reader->EvaluateMVA( "TMlpANN method"       ) );
          if (Use["BDT"          ])   histBdt    ->Fill( reader->EvaluateMVA( "BDT method"           ) );
          if (Use["BDTD"         ])   histBdtD   ->Fill( reader->EvaluateMVA( "BDTD method"          ) );
          if (Use["BDTG"         ])   histBdtG   ->Fill( reader->EvaluateMVA( "BDTG method"          ) );
          if (Use["RuleFit"      ])   histRf     ->Fill( reader->EvaluateMVA( "RuleFit method"       ) );
          if (Use["SVM_Gauss"    ])   histSVMG   ->Fill( reader->EvaluateMVA( "SVM_Gauss method"     ) );
          if (Use["SVM_Poly"     ])   histSVMP   ->Fill( reader->EvaluateMVA( "SVM_Poly method"      ) );
          if (Use["SVM_Lin"      ])   histSVML   ->Fill( reader->EvaluateMVA( "SVM_Lin method"       ) );
          if (Use["FDA_MT"       ])   histFDAMT  ->Fill( reader->EvaluateMVA( "FDA_MT method"        ) );
          if (Use["FDA_GA"       ])   histFDAGA  ->Fill( reader->EvaluateMVA( "FDA_GA method"        ) );
          if (Use["Category"     ])   histCat    ->Fill( reader->EvaluateMVA( "Category method"      ) );
          if (Use["Plugin"       ])   histPBdt   ->Fill( reader->EvaluateMVA( "P_BDT method"         ) );
       
          // Retrieve also per-event error
          if (Use["PDEFoam"]) {
             Double_t val = reader->EvaluateMVA( "PDEFoam method" );
             Double_t err = reader->GetMVAError();
             histPDEFoam   ->Fill( val );
             histPDEFoamErr->Fill( err );         
             if (err>1.e-50) histPDEFoamSig->Fill( val/err );
          }         
       
          // Retrieve probability instead of MVA output
          if (Use["Fisher"])   {
             probHistFi  ->Fill( reader->GetProba ( "Fisher method" ) );
             rarityHistFi->Fill( reader->GetRarity( "Fisher method" ) );
          }
       }

       // Get elapsed time
       sw.Stop();
       std::cout << "--- End of event loop: "; sw.Print();

       // Get efficiency for cuts classifier
       if (Use["CutsGA"]) std::cout << "--- Efficiency for CutsGA method: " << double(nSelCutsGA)/theTree->GetEntries()
                                    << " (for a required signal efficiency of " << effS << ")" << std::endl;
       
       if (Use["CutsGA"]) {
		   
		   // test: retrieve cuts for particular signal efficiency
		   // CINT ignores dynamic_casts so we have to use a cuts-secific Reader function to acces the pointer  
           TMVA::MethodCuts* mcuts = reader->FindCutsMVA( "CutsGA method" ) ;
       
           if (mcuts) {      
              std::vector<Double_t> cutsMin;
              std::vector<Double_t> cutsMax;
              mcuts->GetCuts( 0.7, cutsMin, cutsMax );
              std::cout << "--- -------------------------------------------------------------" << std::endl;
              std::cout << "--- Retrieve cut values for signal efficiency of 0.7 from Reader" << std::endl;
              for (UInt_t ivar=0; ivar<cutsMin.size(); ivar++) {
                 std::cout << "... Cut: " 
                           << cutsMin[ivar] 
                           << " < \"" 
                           << mcuts->GetInputVar(ivar)
                           << "\" <= " 
                           << cutsMax[ivar] << std::endl;
              }
              std::cout << "--- -------------------------------------------------------------" << std::endl;
           }
	   }

       // --- Write histograms
       
       TFile *target  = new TFile( fdir + "TMVApp/" + "TMVApp_" + myModel + ".root","UPDATE" );
	   
       if (Use["Likelihood"   ])   histLk     ->Write( TString(*spit) + "_" + "MVA_Likelihood"    );
       if (Use["LikelihoodD"  ])   histLkD    ->Write( TString(*spit) + "_" + "MVA_LikelihoodD"   );
       if (Use["LikelihoodPCA"])   histLkPCA  ->Write( TString(*spit) + "_" + "MVA_LikelihoodPCA" );
       if (Use["LikelihoodKDE"])   histLkKDE  ->Write( TString(*spit) + "_" + "MVA_LikelihoodKDE" );
       if (Use["LikelihoodMIX"])   histLkMIX  ->Write( TString(*spit) + "_" + "MVA_LikelihoodMIX" );
       if (Use["PDERS"        ])   histPD     ->Write( TString(*spit) + "_" + "MVA_PDERS"         );
       if (Use["PDERSD"       ])   histPDD    ->Write( TString(*spit) + "_" + "MVA_PDERSD"        );
       if (Use["PDERSPCA"     ])   histPDPCA  ->Write( TString(*spit) + "_" + "MVA_PDERSPCA"      );
       if (Use["KNN"          ])   histKNN    ->Write( TString(*spit) + "_" + "MVA_KNN"           );
       if (Use["HMatrix"      ])   histHm     ->Write( TString(*spit) + "_" + "MVA_HMatrix"       );
       if (Use["Fisher"       ])   histFi     ->Write( TString(*spit) + "_" + "MVA_Fisher"        );
       if (Use["FisherG"      ])   histFiG    ->Write( TString(*spit) + "_" + "MVA_FisherG"       );
       if (Use["BoostedFisher"])   histFiB    ->Write( TString(*spit) + "_" + "MVA_BoostedFisher" );
       if (Use["LD"           ])   histLD     ->Write( TString(*spit) + "_" + "MVA_LD"            );
       if (Use["MLP"          ])   histNn     ->Write( TString(*spit) + "_" + "MVA_MLP"           );
       if (Use["MLPBFGS"      ])   histNnbfgs ->Write( TString(*spit) + "_" + "MVA_MLPBFGS"       );
       if (Use["MLPBNN"       ])   histNnbnn  ->Write( TString(*spit) + "_" + "MVA_MLPBNN"        );
       if (Use["CFMlpANN"     ])   histNnC    ->Write( TString(*spit) + "_" + "MVA_CFMlpANN"      );
       if (Use["TMlpANN"      ])   histNnT    ->Write( TString(*spit) + "_" + "MVA_TMlpANN"       );
       if (Use["BDT"          ])   histBdt    ->Write( TString(*spit) + "_" + "MVA_BDT"           );
       if (Use["BDTD"         ])   histBdtD   ->Write( TString(*spit) + "_" + "MVA_BDTD"          );
       if (Use["BDTG"         ])   histBdtG   ->Write( TString(*spit) + "_" + "MVA_BDTG"          ); 
       if (Use["RuleFit"      ])   histRf     ->Write( TString(*spit) + "_" + "MVA_RuleFit"       );
       if (Use["SVM_Gauss"    ])   histSVMG   ->Write( TString(*spit) + "_" + "MVA_SVM_Gauss"     );
       if (Use["SVM_Poly"     ])   histSVMP   ->Write( TString(*spit) + "_" + "MVA_SVM_Poly"      );
       if (Use["SVM_Lin"      ])   histSVML   ->Write( TString(*spit) + "_" + "MVA_SVM_Lin"       );
       if (Use["FDA_MT"       ])   histFDAMT  ->Write( TString(*spit) + "_" + "MVA_FDA_MT"        );
       if (Use["FDA_GA"       ])   histFDAGA  ->Write( TString(*spit) + "_" + "MVA_FDA_GA"        );
       if (Use["Category"     ])   histCat    ->Write( TString(*spit) + "_" + "MVA_Category"      );
       if (Use["Plugin"       ])   histPBdt   ->Write( TString(*spit) + "_" + "MVA_PBDT"          );

       // Write also error and significance histos
       if (Use["PDEFoam"]) { histPDEFoam->Write(); histPDEFoamErr->Write(); histPDEFoamSig->Write(); }
       
       // Write also probability hists
       if (Use["Fisher"]) { if (probHistFi != 0) probHistFi->Write(); if (rarityHistFi != 0) rarityHistFi->Write(); }
       target->Close();
       
       std::cout << "--- Created root file: \"TMVApp_"<< myModel << ".root\" containing the MVA output histograms" << std::endl;
       
       if (Use["Likelihood"])    delete histLk     ;
       if (Use["LikelihoodD"])   delete histLkD    ;
       if (Use["LikelihoodPCA"]) delete histLkPCA  ;
       if (Use["LikelihoodKDE"]) delete histLkKDE  ;
       if (Use["LikelihoodMIX"]) delete histLkMIX  ;
       if (Use["PDERS"])         delete histPD     ;
       if (Use["PDERSD"])        delete histPDD    ;
       if (Use["PDERSPCA"])      delete histPDPCA  ;
       if (Use["KNN"])           delete histKNN    ;
       if (Use["HMatrix"])       delete histHm     ;
       if (Use["Fisher"])        delete histFi     ;
       if (Use["FisherG"])       delete histFiG    ;
       if (Use["BoostedFisher"]) delete histFiB    ;
       if (Use["LD"])            delete histLD     ;
       if (Use["MLP"])           delete histNn     ;
       if (Use["MLPBFGS"])       delete histNnbfgs ;
       if (Use["MLPBNN"])        delete histNnbnn  ;
       if (Use["CFMlpANN"])      delete histNnC    ;
       if (Use["TMlpANN"])       delete histNnT    ;
       if (Use["BDT"])           delete histBdt    ;
       if (Use["BDTD"])          delete histBdtD   ;
       if (Use["BDTG"])          delete histBdtG   ;
       if (Use["RuleFit"])       delete histRf     ;
       if (Use["SVM_Gauss"])     delete histSVMG   ;
       if (Use["SVM_Poly"])      delete histSVMP   ;
       if (Use["SVM_Lin"])       delete histSVML   ;
       if (Use["FDA_MT"])        delete histFDAMT  ;
       if (Use["FDA_GA"])        delete histFDAGA  ;
       if (Use["Category"])      delete histCat    ;
       if (Use["Plugin"])        delete histPBdt   ;

	   delete theTree;
	   target->Close();
	   
   }

   delete reader;
    
   std::cout << "==> TMVAClassificationApplication is done!" << endl << std::endl;
} 
