
#include "TROOT.h"
#include "TIterator.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TVector3.h"
#include "TMath.h"

#include <iostream>
#include <string>

#include "DataManagement.h"
#include "ProcessChannel.h"
#include "HistoCollection.h"

namespace ProcessChannel {

	TString _InputFilePath  = "";
	TString _InputFileName  = "";
	TString _InputDirName   = "";
	TString _InputTreeName  = "";
	TString _OutputFilePath = "";
	TString _OutputFileName = "";
	
	void SetInputFilePath (TString & s) { _InputFilePath  = s; };
	void SetInputFileName (TString & s) { _InputFileName  = s; };
	void SetInputDirName  (TString & s) { _InputDirName   = s; };
	void SetInputTreeName (TString & s) { _InputTreeName  = s; };
	void SetOutputFilePath(TString & s) { _OutputFilePath = s; };
	void SetOutputFileName(TString & s) { _OutputFileName = s; };
			
	TString GetInputFilePath () { return _InputFilePath;  };
	TString GetInputFileName () { return _InputFileName;  };
	TString GetInputDirName  () { return _InputDirName;   };
	TString GetInputTreeName () { return _InputTreeName;  };
	TString GetOutputFilePath() { return _OutputFilePath; };
	TString GetOutputFileName() { return _OutputFileName; };

	// Set/Get channel to process
	ChannelType_t _ChannelToProcess;
	void SetChannelToProcess( ChannelType_t c){ _ChannelToProcess = c; };
	TString GetChannelToProcess(){
		
		switch(_ChannelToProcess) {
			case kOneElectron                   : return "kOneElectron∂";
			case kTwoElectronInternal           : return "kTwoElectronInternal";
		    case kTwoElectronExternal           : return "kTwoElectronExternal";
		    case kOneElectronOneGammaInternal   : return "kOneElectronOneGammaInternal";
		    case kOneElectronOneGammaExternal   : return "kOneElectronOneGammaExternal";
			case kOneElectronTwoGammaInternal   : return "kOneElectronTwoGammaInternal";
			case kOneElectronThreeGammaInternal : return "kOneElectronThreeGammaInternal";
			case kOneElectronOneAlpha           : return "kOneElectronOneAlpha";
		};
	
		return "kUndefined";
		
	};

	//////////////////////////////////////////////////////////////////////////////
	//
	// Define first/last run to process
	//		
	//////////////////////////////////////////////////////////////////////////////
	int _RunFirst = -1; int _RunLast  = -1;
	void SetFirstRunNumber( int run ) { _RunFirst = run; };
	void SetLastRunNumber( int run ) { _RunLast = run; };

	bool CheckRunNumber( int run ) {
		
		if ( run >= _RunFirst && run <= _RunLast )     return kTRUE;
		else if ( _RunFirst == -1 && run <= _RunLast ) return kTRUE;
		else if ( _RunLast == -1 && run >= _RunFirst ) return kTRUE; 
		else if ( _RunFirst == -1 && _RunLast == -1)   return kTRUE;
		else                                           return kFALSE;
		
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Excluded spot definition
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool IsExcludedSpot  (double z, double s){
		
		if ( s < 18.08 ) return true;
		
		return false;
		
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Hot spot definition
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool IsHotSpot  (double z, double s){
		
		if( IsExcludedSpot(z,s) )  	                                    return false;
		
		// Benton's definition (Created on 18/05/2015)
		else if( z>=  108.00 and z <=  120.00 and s >= 18.70 and s <= 18.35) return true;
		else if( z>=  109.00 and z <=  120.00 and s >= 18.59 and s <= 18.75) return true;
		else if( z>=  110.00 and z <=  120.00 and s >= 18.86 and s <= 19.00) return true;
		else if( z>=   74.61 and z <=   93.30 and s >= 18.19 and s <= 18.35) return true;
		else if( z>=   68.50 and z <=   73.75 and s >= 18.58 and s <= 18.61) return true;
		else if( z>=    1.17 and z <=   36.80 and s >= 18.08 and s <= 18.21) return true;
		else if( z>=   14.21 and z <=   35.90 and s >= 18.60 and s <= 18.76) return true;
		else if( z>=  -37.01 and z <=   -0.56 and s >= 18.19 and s <= 18.35) return true;	
		else if( z>=  -58.00 and z <=  -52.00 and s >= 18.12 and s <= 18.16) return true;	
		else if( z>=  -94.42 and z <=  -64.00 and s >= 18.07 and s <= 18.21) return true;	
		else if( z>= -120.00 and z <= -112.00 and s >= 18.07 and s <= 18.35) return true;	
		else if( z>= -120.00 and z <= -107.00 and s >= 18.72 and s <= 18.88) return true;	
		
		// My original definition (Commented on 18/05/2015)                                                                
	    //else if ( z > +110.0 and s > 18.08 and s < 18.32 )               return true;
		//else if ( z > +114.0 and s > 18.61 and s < 18.75 )               return true;
	    //else if ( z > +112.0 and s > 18.86 and s < 19.00 )               return true;		
		//else if ( z >  +76.0 and z < +92.0 and s > 18.21 and s < 18.35 ) return true;
	    //else if ( z >  +70.0 and z < +73.0 and s > 18.59 and s < 18.61 ) return true;
	    //else if ( z >    0.0 and z < +35.0 and s > 18.08 and s < 18.23 ) return true;
	    //else if ( z >  +16.0 and z < +34.0 and s > 18.61 and s < 18.75 ) return true;
	    //else if ( z <   -3.0 and z > -32.0 and s > 18.20 and s < 18.35 ) return true;
	    //else if ( z <  -52.0 and z > -58.0 and s > 18.12 and s < 18.16 ) return true;
	    //else if ( z <  -64.0 and z > -94.0 and s > 18.08 and s < 18.20 ) return true;    
		//else if ( z < -112.0 and s > 18.14 and s < 18.35)                return true;
	    //else if ( z < -110.0 and s > 18.74 and s < 18.88)                return true;
		
		return false;
		
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Warm spot definition
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool IsWarmSpot (double z, double s){
		
		if ( IsExcludedSpot(z,s) or IsHotSpot(z,s) )      return false;
		
		// Benton's definition (Created on 18/05/2015)
		else if ( z >= -120.00 and z <=  50.00 and s >= 18.87 and s <= 19.00 ) return true;
		else if ( z >= -120.00 and z <=  15.00 and s >= 18.48 and s <= 18.72 ) return true;
		else if ( z >=   15.00 and z <= 120.00 and s >= 18.48 and s <= 18.58 ) return true;
		else if ( z >=   15.00 and z <=  68.00 and s >= 18.58 and s <= 18.60 ) return true;
		else if ( z >=   73.74 and z <= 108.00 and s >= 18.58 and s <= 18.60 ) return true;

		// My original definition (Commented on 18/05/2015)                             	
		//else if ( s < 18.48 )                             return true;
		//else if ( z >  +34. and s > 18.60 and s < 18.75 ) return true;
		//else if ( s > 18.75 and s < 18.88 )               return true;
		//else if ( z >  +50. and s > 18.88 )               return true;
		
		return false;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////
	//
	// Cold spot definition
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool IsColdSpot (double z, double s){
		
		if( IsExcludedSpot(z,s) or IsHotSpot(z,s) or IsWarmSpot(z,s) ) return false;
		
		return true;
		
	}

	// Number of events in the loop. -1 : all events.
	Long64_t _n_max = -1;

	//////////////////////////////////////////////////////////////////////////////
	//
	// Run over all data set found in DataManagement::GetDataSetCollection()
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool Run( Long64_t n_max){

		TIter next(DataManagement::GetDataSetCollection());
		DataSet * d;

		_n_max = n_max;

		while( (d = (DataSet *) next()) ) {
				
			std::cout << std::endl << "Data set: " << d->GetName()<< std::endl;

			bool status = kFALSE;

			// Process the required channel
			switch(_ChannelToProcess) { 
				case kOneElectron                   : status = ProcessOneElectron(d)                   ; break;
				case kTwoElectronInternal           : status = ProcessTwoElectronInternal(d)           ; break;
				case kTwoElectronExternal           : status = ProcessTwoElectronExternal(d)           ; break;
				case kOneElectronOneGammaInternal   : status = ProcessOneElectronOneGammaInternal(d)   ; break;
				case kOneElectronOneGammaExternal   : status = ProcessOneElectronOneGammaExternal(d)   ; break;
				case kOneElectronTwoGammaInternal   : status = ProcessOneElectronTwoGammaInternal(d)   ; break;
				case kOneElectronThreeGammaInternal : status = ProcessOneElectronThreeGammaInternal(d) ; break;
				case kOneElectronOneAlpha           : status = ProcessOneElectronOneAlpha(d)           ; break;			
			
				default : status = kFALSE; break;
			}
			
			// Check the status of the process
			if( !status ) return kFALSE;

		}

		return kTRUE;
		
	}

	//////////////////////////////////////////////////////////////////////////////
	//
	// Process One electron channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 10/11/214
	//	
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectron( DataSet *d ){
	
		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
		cutNames->push_back("Cd-116 sector (18) ");
	    cutNames->push_back("Energy of the electron > 300 keV ");
	    cutNames->push_back("Negative track sign");
		cutNames->push_back("Not an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		histo_collection->Add( hAnaCutFlow );
		
		// Make all other histos
		histo_collection->Add( new TH1D ( TString::Format("%s_h_run"                   , d->GetName()) , "; Run; No.Events",    200, 1000, 9500                              ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_electronEnergy"        , d->GetName()) , "; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trackLength"           , d->GetName()) , "; Track Length / cm; No.Events / cm", 200, 0, 200                  ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trackSign"             , d->GetName()) , "; Sign of Track Curvature; No.Events", 10, -2, 2                   ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_electronIobt"          , d->GetName()) , "; IOBT; No.Events", 5, -0.5, 4.5                                   ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexZ"           , d->GetName()) , "; True - Z_{vertex} / cm ; No.Events / cm", 260, -130, 130         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexSector"      , d->GetName()) , "; True - Sector Number; No.Events", 200, 0, 20                     ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sectorId"              , d->GetName()) , "; Sector; No.Events",  21, -0.5, 20.5                              ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sourceId"              , d->GetName()) , "; Source; No.Events",   4, -1.5, 2.5                               ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSectorId"          , d->GetName()) , "; True Sector; No.Events",  21, -0.5, 20.5                         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSourceId"          , d->GetName()) , "; True Source; No.Events",   4, -1.5, 2.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_nGammas"               , d->GetName()) , "; No. #gammas; No.Events", 15, -0.5, 14.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_totGammaEnergy"        , d->GetName()) , "; #Sigma E_{#gamma}^{high} / MeV; No.Events / 0.05 MeV", 50, 0, 2.5) );
		
		histo_collection->Add( new TH2D ( TString::Format("%s_h_vtx_z_vs_sect"         , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );
		histo_collection->Add( new TH2D ( TString::Format("%s_h_vtx_z_vs_sect_warm"    , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );		
		histo_collection->Add( new TH2D ( TString::Format("%s_h_vtx_z_vs_sect_cold"    , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );		

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ"               , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_warm"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_cold"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector"          , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_warm"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_cold"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P1"               , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P1_warm"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P1_cold"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2"               , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2_warm"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2_cold"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P1"          , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P1_warm"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P1_cold"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2"               , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2_warm"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ_P2_cold"          , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P2"          , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P2_warm"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector_P2_cold"     , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P1"           , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P1_warm"      , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P1_cold"      , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );

		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P2"           , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );		
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P2_warm"      , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P2_cold"      , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 35, 0, 3.5                  ) );

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);
	
		// Declaration of leaf types
		Int_t           run                  ; tree->SetBranchAddress("run"                  , &run                  );
		Int_t           event                ; tree->SetBranchAddress("event"                , &event                );
		Int_t           runType              ; tree->SetBranchAddress("runType"              , &runType              );
	  	Int_t           timeStampSec         ; tree->SetBranchAddress("timeStampSec"         , &timeStampSec         );
	    Int_t           timeStampNanoS       ; tree->SetBranchAddress("timeStampNanoS"       , &timeStampNanoS       );
	    Double_t        eventTime            ; tree->SetBranchAddress("eventTime"            , &eventTime            );
	    Double_t        radonWeight          ; tree->SetBranchAddress("radonWeight"          , &radonWeight          );
	    Double_t        bi210Weight          ; tree->SetBranchAddress("bi210Weight"          , &bi210Weight          );
	    Double_t        sfoilRadonWeight     ; tree->SetBranchAddress("sfoilRadonWeight"     , &sfoilRadonWeight     );
	    Int_t           foilSide             ; tree->SetBranchAddress("foilSide"             , &foilSide             );
	    Int_t           sectorId             ; tree->SetBranchAddress("sectorId"             , &sectorId             );
	    Int_t           sourceId             ; tree->SetBranchAddress("sourceId"             , &sourceId             );
	    Int_t           isInHotSpot          ; tree->SetBranchAddress("isInHotSpot"          , &isInHotSpot          );
	    Double_t        vertexSector         ; tree->SetBranchAddress("vertexSector"         , &vertexSector         );
	    Double_t        trueVertexSector     ; tree->SetBranchAddress("trueVertexSector"     , &trueVertexSector     );
	    Int_t           trueVertexLayer      ; tree->SetBranchAddress("trueVertexLayer"      , &trueVertexLayer      );
	    Int_t           trueSectorId         ; tree->SetBranchAddress("trueSectorId"         , &trueSectorId         );
	    Int_t           trueSourceId         ; tree->SetBranchAddress("trueSourceId"         , &trueSourceId         );
	    Double_t        el_energy            ; tree->SetBranchAddress("el_energy"            , &el_energy            );
	    Int_t           el_side              ; tree->SetBranchAddress("el_side"              , &el_side              );
	    Double_t        el_dEnergy           ; tree->SetBranchAddress("el_dEnergy"           , &el_dEnergy           );
	    Double_t        el_beta              ; tree->SetBranchAddress("el_beta"              , &el_beta              );
	    Double_t        el_dBeta             ; tree->SetBranchAddress("el_dBeta"             , &el_dBeta             );
	    Double_t        el_pathLength        ; tree->SetBranchAddress("el_pathLength"        , &el_pathLength        );
	    Double_t        el_energyLoss        ; tree->SetBranchAddress("el_energyLoss"        , &el_energyLoss        );
	    Double_t        el_measTime          ; tree->SetBranchAddress("el_measTime"          , &el_measTime          );
	    Double_t        el_dMeasTime         ; tree->SetBranchAddress("el_dMeasTime"         , &el_dMeasTime         );
	    Double_t        el_thTof             ; tree->SetBranchAddress("el_thTof"             , &el_thTof             );
	    Double_t        el_dThTof            ; tree->SetBranchAddress("el_dThTof"            , &el_dThTof            );
	    Int_t           el_caloiobt          ; tree->SetBranchAddress("el_caloiobt"          , &el_caloiobt          );
	    Int_t           el_calofcll          ; tree->SetBranchAddress("el_calofcll"          , &el_calofcll          );
	    Int_t           el_caloHsFlag        ; tree->SetBranchAddress("el_caloHsFlag"        , &el_caloHsFlag        );
	    Double_t        el_trkSign           ; tree->SetBranchAddress("el_trkSign"           , &el_trkSign           );
	    Long64_t        el_tdc_count         ; tree->SetBranchAddress("el_tdc_count"         , &el_tdc_count         );
	    Double_t        el_vtx_x_            ; tree->SetBranchAddress("el_vtx_x_"            , &el_vtx_x_            );
	    Double_t        el_vtx_y_            ; tree->SetBranchAddress("el_vtx_y_"            , &el_vtx_y_            );
	    Double_t        el_vtx_z_            ; tree->SetBranchAddress("el_vtx_z_"            , &el_vtx_z_            );
	    Double_t        el_ip_x_             ; tree->SetBranchAddress("el_ip_x_"             , &el_ip_x_             );
	    Double_t        el_ip_y_             ; tree->SetBranchAddress("el_ip_y_"             , &el_ip_y_             );
	    Double_t        el_ip_z_             ; tree->SetBranchAddress("el_ip_z_"             , &el_ip_z_             );
	    Double_t        el_min_xy_dist_      ; tree->SetBranchAddress("el_min_xy_dist_"      , &el_min_xy_dist_      );
	    Double_t        el_min_z_dist_       ; tree->SetBranchAddress("el_min_z_dist_"       , &el_min_z_dist_       );
	    Int_t           nClusters_           ; tree->SetBranchAddress("nClusters_"           , &nClusters_           );
	    Int_t           nLowEnergyClusters_  ; tree->SetBranchAddress("nLowEnergyClusters_"  , &nLowEnergyClusters_  );
	    Double_t        totUnderlyingEnergy_ ; tree->SetBranchAddress("totUnderlyingEnergy_" , &totUnderlyingEnergy_ );
	
	    TVector3 *eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex"    , &eVertex    );
	    TVector3 *trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex" , &trueVertex );
	
	    // Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

	    Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
		      std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;

			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
		    if ( !CheckRunNumber(run) ) continue;
			if ( sectorId != 18 || IsExcludedSpot(el_vtx_z_, vertexSector) ) continue; hAnaCutFlow -> Fill(currentcut++); // Cd foil only
			if ( el_trkSign > 0)  						  continue; hAnaCutFlow -> Fill(currentcut++); // Negative track only
			if ( el_energy < 0.3) 						  continue; hAnaCutFlow -> Fill(currentcut++); // E > 300 keV only
			if ( IsHotSpot(eVertex->z(), vertexSector) )  continue; hAnaCutFlow -> Fill(currentcut++);
			// 3. no hotspot
		
			// Apply radon map
		    double weight = 1;    
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }
		
			// Fill histogram
		    histo_collection->Find( TString::Format("%s_h_run"              , d->GetName()) ) -> Fill(run                   , weight);
		    histo_collection->Find( TString::Format("%s_h_electronEnergy"   , d->GetName()) ) -> Fill(el_energy             , weight);
			histo_collection->Find( TString::Format("%s_h_trackLength"      , d->GetName()) ) -> Fill(el_pathLength         , weight);
			histo_collection->Find( TString::Format("%s_h_trackSign"        , d->GetName()) ) -> Fill(el_trkSign            , weight);
			histo_collection->Find( TString::Format("%s_h_electronIobt"     , d->GetName()) ) -> Fill(el_caloiobt           , weight);
			histo_collection->Find( TString::Format("%s_h_trueVertexZ"      , d->GetName()) ) -> Fill(trueVertex->Z()       , weight);
			histo_collection->Find( TString::Format("%s_h_trueVertexSector" , d->GetName()) ) -> Fill(trueVertexSector      , weight);
			histo_collection->Find( TString::Format("%s_h_sectorId"         , d->GetName()) ) -> Fill(sectorId              , weight);
			histo_collection->Find( TString::Format("%s_h_sourceId"         , d->GetName()) ) -> Fill(sourceId              , weight);
			histo_collection->Find( TString::Format("%s_h_trueSectorId"     , d->GetName()) ) -> Fill(trueSectorId          , weight);
			histo_collection->Find( TString::Format("%s_h_trueSourceId"     , d->GetName()) ) -> Fill(trueSourceId          , weight);
			histo_collection->Find( TString::Format("%s_h_nGammas"          , d->GetName()) ) -> Fill(nClusters_            , weight);
			histo_collection->Find( TString::Format("%s_h_totGammaEnergy"   , d->GetName()) ) -> Fill(totUnderlyingEnergy_  , weight);
		  
			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
		  
			//if( !IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			//else if( IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			
			histo_collection->Find( TString::Format("%s_h_vertexZ"          , d->GetName()) ) -> Fill(el_vtx_z_             , weight);
			histo_collection->Find( TString::Format("%s_h_vertexSector"     , d->GetName()) ) -> Fill(vertexSector          , weight);
			
			
			if( IsWarmSpot(el_vtx_z_, vertexSector) ) {
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
				histo_collection->Find( TString::Format("%s_h_vertexZ_warm"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
				histo_collection->Find( TString::Format("%s_h_vertexSector_warm"  , d->GetName()) ) -> Fill(vertexSector, weight);
			} else if( IsColdSpot(el_vtx_z_, vertexSector) ) {
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
				histo_collection->Find( TString::Format("%s_h_vertexZ_cold"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
				histo_collection->Find( TString::Format("%s_h_vertexSector_cold"  , d->GetName()) ) -> Fill(vertexSector, weight);
		  	}
		  
			// Phase 1 & 2
		    if (run < 3396) {
				
				histo_collection->Find(TString::Format("%s_h_e_energy_P1", d->GetName())) -> Fill(el_energy , weight);			 
				histo_collection->Find( TString::Format("%s_h_vertexZ_P1"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
				histo_collection->Find( TString::Format("%s_h_vertexSector_P1"  , d->GetName()) ) -> Fill(vertexSector, weight);
				
				if( IsWarmSpot(el_vtx_z_, vertexSector) ) {
			 		histo_collection->Find(TString::Format("%s_h_e_energy_P1_warm" , d->GetName())) -> Fill(el_energy , weight);
					histo_collection->Find( TString::Format("%s_h_vertexZ_P1_warm"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
					histo_collection->Find( TString::Format("%s_h_vertexSector_P1_warm"  , d->GetName()) ) -> Fill(vertexSector, weight);
				} else if( IsColdSpot(el_vtx_z_, vertexSector) ) {
			 		histo_collection->Find(TString::Format("%s_h_e_energy_P1_cold" , d->GetName())) -> Fill(el_energy , weight);
					histo_collection->Find( TString::Format("%s_h_vertexZ_P1_cold"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
					histo_collection->Find( TString::Format("%s_h_vertexSector_P1_cold"  , d->GetName()) ) -> Fill(vertexSector, weight);
				}
				
			} else {
			
				histo_collection->Find(TString::Format("%s_h_e_energy_P2", d->GetName())) -> Fill(el_energy , weight);
				histo_collection->Find( TString::Format("%s_h_vertexZ_P2"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
				histo_collection->Find( TString::Format("%s_h_vertexSector_P2"  , d->GetName()) ) -> Fill(vertexSector, weight);

				if( IsWarmSpot(el_vtx_z_, vertexSector) ) {
			 		histo_collection->Find(TString::Format("%s_h_e_energy_P2_warm" , d->GetName())) -> Fill(el_energy , weight);
					histo_collection->Find( TString::Format("%s_h_vertexZ_P2_warm"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
					histo_collection->Find( TString::Format("%s_h_vertexSector_P2_warm"  , d->GetName()) ) -> Fill(vertexSector, weight);
				} else if( IsColdSpot(el_vtx_z_, vertexSector) ) {
			 		histo_collection->Find(TString::Format("%s_h_e_energy_P2_cold" , d->GetName())) -> Fill(el_energy , weight);
					histo_collection->Find( TString::Format("%s_h_vertexZ_P2_cold"       , d->GetName()) ) -> Fill(el_vtx_z_   , weight);
					histo_collection->Find( TString::Format("%s_h_vertexSector_P2_cold"  , d->GetName()) ) -> Fill(vertexSector, weight);
				}
			
		    }
			
		}
		
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
		
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;
	
		
	}
	
	//////////////////////////////////////////////////////////////////////////////		
	//
	// Process two electrons internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 11/11/2014
	//
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessTwoElectronInternal( DataSet *d ){
		
		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
		cutNames->push_back("Cd-116 sector (18) ");
		cutNames->push_back("Negative track sign");
	    cutNames->push_back("Energy of the electron > 500 keV ");
		cutNames->push_back("Sum track length > 80 cm ");
		cutNames->push_back("Internal probability > 0.04");
		cutNames->push_back("External probability < 0.01");
		cutNames->push_back("No unassociated hits opposite to the electrons");
	    cutNames->push_back("No electron hits petal near the foil");
		cutNames->push_back("|dz_vtx| < 4 cm and radial distance < 2");
		cutNames->push_back("Not an hot spot");
		
	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos
		histo_collection->Add( new TH1D( TString::Format("%s_h_run"                    , d->GetName()) , "; Run; No.Events",    200, 1000, 9500                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_sectorId"               , d->GetName()) , "; Sector; No.Events",  21, -0.5, 20.5                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_sourceId"               , d->GetName()) , "; Source; No.Events",   4, -1.5, 2.5                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_min"          , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_max"          , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_min"         , d->GetName()) , "; Min dE_{e} / MeV; No.Events / 0.01 MeV", 50, 0, 0.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_max"         , d->GetName()) , "; Max dE_{e} / MeV; No.Events / 0.01 MeV", 50, 0, 0.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_min"            , d->GetName()) , "; Min - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_max"            , d->GetName()) , "; Max - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_min"           , d->GetName()) , "; Min - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_max"           , d->GetName()) , "; Max - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_min"       , d->GetName()) , "; Min - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_max"       , d->GetName()) , "; Max - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_min"          , d->GetName()) , "; Min - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_max"          , d->GetName()) , "; Max - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_0"            , d->GetName()) , "; First el. - E / MeV; No.Events / 0.1 MeV", 35, 0, 3.5             ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_1"            , d->GetName()) , "; Last el. - E / MeV; No.Events / 0.1 MeV", 35, 0, 3.5              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_0"           , d->GetName()) , "; First el. - dE / MeV; No.Events / 0.01 MeV", 50, 0, 0.5           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_1"           , d->GetName()) , "; Last el. - dE / MeV; No.Events / 0.01 MeV", 50, 0, 0.5            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_0"              , d->GetName()) , "; First el. - #beta_{e}; No.Events / 0.01",100, 0.6, 1.6            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_1"              , d->GetName()) , "; Last el. - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_0"             , d->GetName()) , "; First el. - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_1"             , d->GetName()) , "; Last el. - d#beta_{e}; No.Events / 0.002",  100, 0, 0.2           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_pathLength_0"        , d->GetName()) , "; First el. - Track Length / cm; No.Events / cm", 200, 0, 200       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_pathLength_1"        , d->GetName()) , "; Last el. - Track Length / cm; No.Events / cm", 200, 0, 200        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energyLoss_0"        , d->GetName()) , "; First el. - Energy Loss / MeV; No.Events / 5 keV", 60, 0, 0.3     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energyLoss_1"        , d->GetName()) , "; Last el. - Energy Loss / MeV; No.Events / 5 keV", 60, 0, 0.3      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_measTime_0"          , d->GetName()) , "; First el. - T_{meas} / ns; No.Events / 1 ns", 130, -220, -90      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_measTime_1"          , d->GetName()) , "; Last el. - T_{meas} / ns; No.Events / 1 ns",  130, -220, -90      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_0"         , d->GetName()) , "; First el. - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_1"         , d->GetName()) , "; Last el. - dT_{meas} / ns; No.Events / 0.04 ns",  50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_thTof_0"             , d->GetName()) , "; First el. - T_{theo} / ns; No.Events / 1 ns", 50, 0, 50           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_thTof_1"             , d->GetName()) , "; Last el. - T_{theo} / ns; No.Events / 1 ns",  50, 0, 50           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_0"            , d->GetName()) , "; First el. - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_1"            , d->GetName()) , "; Last el. - dT_{theo} / ns; No.Events / 0.04 ns",  50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_caloiobt0"           , d->GetName()) , "; First el. - IOBT; No.Events", 5, -0.5, 4.5                        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_caloiobt1"           , d->GetName()) , "; Last el. - IOBT; No.Events", 5, -0.5, 4.5                         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_trkSign0"            , d->GetName()) , "; First el. - Sign of Track Curvature; No.Events", 10, -2, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_trkSign1"            , d->GetName()) , "; Last el. - Sign of Track Curvature; No.Events", 10, -2, 2         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nTracks"                , d->GetName()) , "; N. Tracks; No.Events" , 15, -0.5, 14.5                            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCaloHits"              , d->GetName()) , "; N. Calo Hits; No.Events" , 15, -0.5, 14.5                         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nRawCaloHits"           , d->GetName()) , "; N. Raw Calo Hits; No.Events" , 15, -0.5, 14.5                     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexZ"                , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                 ) );
		histo_collection->Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"          , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexSector"           , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_trueVertexZ"            , d->GetName()) , "; True - Z_{vertex} / cm ; No.Events / cm", 260, -130, 130          ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_trueVertexSector"       , d->GetName()) , "; True - Sector Number; No.Events", 200, 0, 20                      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta"               , d->GetName()) , "; Cos(#Theta); No.Events", 100, -1, 1                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probInt"                , d->GetName()) , "; Internal Prob.; No.Events", 100, 0, 1.1                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probExt_1_to_0"         , d->GetName()) , "; Last to First - External Prob.; No.Events", 100, 0, 0.1           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probExt_0_to_1"         , d->GetName()) , "; First to Last - External Prob.; No.Events", 100, 0, 1.1           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chisqInt"               , d->GetName()) , "; Internal #Chi^{2}; No.Events", 100, 0, 8000                       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chiSqExt_0_to_1"        , d->GetName()) , "; First to Last - #Chi^{2}; No.Events", 100, 0, 5000                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chiSqExt_1_to_0"        , d->GetName()) , "; Last to First - #Chi^{2}; No.Events", 100, 0, 10000               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nGammas"                , d->GetName()) , "; No. #gammas; No.Events", 15, -0.5, 14.5                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nLowEnergyGammas"       , d->GetName()) , "; No. Low E #gamma; No.Events", 15, -0.5, 14.5                      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nHighEnergyGammas"      , d->GetName()) , "; No. High E #gamma; No.Events", 15, -0.5, 14.5                     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_totELowEnergyGammas"    , d->GetName()) , "; #Sigma E_{#gamma}^{low} / MeV; No.Events / 0.02 MeV", 50, 0, 1    ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_totEHighEnergyGammas"   , d->GetName()) , "; #Sigma E_{#gamma}^{high} / MeV; No.Events / 0.05 MeV", 50, 0, 2.5 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nClusters"              , d->GetName()) , "; No. #gamma clusters; No.Events", 15, -0.5, 14.5                   ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarNAPromptHits"       , d->GetName()) , "; N. far prompt hits; No.Events", 21, -0.5, 20.5                    ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseNAPromptHits"     , d->GetName()) , "; N. close prompt hits; No.Events", 21, -0.5, 20.5                  ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarDelayedHits"        , d->GetName()) , "; N. far delayed hits; No.Events", 21, -0.5, 20.5                   ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseDelayedHits"      , d->GetName()) , "; N. close delayed hits; No.Events", 21, -0.5, 20.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarDelayedClusters"    , d->GetName()) , "; N. far delayed clusters; No.Events", 21, -0.5, 20.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseDelayedCslusters" , d->GetName()) , "; N. close delayed clusters; No.Events", 21, -0.5, 20.5             ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P1"        , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P1"        , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P1"            , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1"        , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P1_cold"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P1_cold"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P1_cold"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_cold"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P1_warm"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P1_warm"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P1_warm"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_warm"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P1_hot"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P1_hot"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P1_hot"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_hot"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );


		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P2"        , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P2"        , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P2"            , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2"        , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P2_cold"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P2_cold"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P2_cold"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_cold"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P2_warm"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P2_warm"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P2_warm"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_warm"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_min_e_energy_P2_hot"   , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_max_e_energy_P2_hot"   , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta_P2_hot"       , d->GetName()) , "; Cos(#Theta); No.Events", 25, -1, 1                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_hot"   , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );

		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_SS_In"  , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_SS_In"  , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_SS_Out" , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_SS_Out" , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1_OS"     , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2_OS"     , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dx"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dy"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dz"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_x"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_y"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_z"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -130, 130                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_x"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_y"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_z"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -130, 130                              ) );

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t     run                         ; tree->SetBranchAddress("run"                         , &run                         );
	    Int_t     event                       ; tree->SetBranchAddress("event"                       , &event                       );
	    Int_t     runType                     ; tree->SetBranchAddress("runType"                     , &runType                     );
	    Double_t  eventTime                   ; tree->SetBranchAddress("eventTime"                   , &eventTime                   );
	    Int_t     timeStampSec                ; tree->SetBranchAddress("timeStampSec"                , &timeStampSec                );
	    Int_t     timeStampNanoS              ; tree->SetBranchAddress("timeStampNanoS"              , &timeStampNanoS              );
	    Double_t  radonWeight                 ; tree->SetBranchAddress("radonWeight"                 , &radonWeight                 );
	    Double_t  bi210Weight                 ; tree->SetBranchAddress("bi210Weight"                 , &bi210Weight                 );
	    Double_t  sfoilRadonWeight            ; tree->SetBranchAddress("sfoilRadonWeight"            , &sfoilRadonWeight            );
	    Double_t  cosThetaWeight              ; tree->SetBranchAddress("cosThetaWeight"              , &cosThetaWeight              );
	    Int_t     foilSide                    ; tree->SetBranchAddress("foilSide"                    , &foilSide                    );
	    Int_t     sectorId                    ; tree->SetBranchAddress("sectorId"                    , &sectorId                    );
	    Int_t     sourceId                    ; tree->SetBranchAddress("sourceId"                    , &sourceId                    );
	    Int_t     isInHotSpot                 ; tree->SetBranchAddress("isInHotSpot"                 , &isInHotSpot                 );
	    Double_t  vertexSector                ; tree->SetBranchAddress("vertexSector"                , &vertexSector                );
	    Int_t     nTracks                     ; tree->SetBranchAddress("nTracks"                     , &nTracks                     );
	    Int_t     nCaloHits                   ; tree->SetBranchAddress("nCaloHits"                   , &nCaloHits                   );
	    Int_t     nRawCaloHits                ; tree->SetBranchAddress("nRawCaloHits"                , &nRawCaloHits                );
	    Int_t     nAlphas                     ; tree->SetBranchAddress("nAlphas_"                    , &nAlphas                     );
	    Int_t     nFarNAPromptHits            ; tree->SetBranchAddress("nFarNAPromptHits"            , &nFarNAPromptHits            );
	    Int_t     nCloseNAPromptHits          ; tree->SetBranchAddress("nCloseNAPromptHits"          , &nCloseNAPromptHits          );
	    Int_t     nFarDelayedHits             ; tree->SetBranchAddress("nFarDelayedHits"             , &nFarDelayedHits             );
	    Int_t     nCloseDelayedHits           ; tree->SetBranchAddress("nCloseDelayedHits"           , &nCloseDelayedHits           );
	    Int_t     nFarDelayedClusters         ; tree->SetBranchAddress("nFarDelayedClusters"         , &nFarDelayedClusters         );
	    Int_t     nCloseDelayedCslusters      ; tree->SetBranchAddress("nCloseDelayedCslusters"      , &nCloseDelayedCslusters      );
	    Int_t     nFarNAPromptHits_Opposite   ; tree->SetBranchAddress("nFarNAPromptHits_Opposite"   , &nFarNAPromptHits_Opposite   );
	    Int_t     nCloseNAPromptHits_Opposite ; tree->SetBranchAddress("nCloseNAPromptHits_Opposite" , &nCloseNAPromptHits_Opposite );
	    Int_t     nDelayedHits                ; tree->SetBranchAddress("nDelayedHits"                , &nDelayedHits                );
	    Double_t  cosTheta                    ; tree->SetBranchAddress("cosTheta"                    , &cosTheta                    );
	    Double_t  probInt                     ; tree->SetBranchAddress("probInt"                     , &probInt                     );
	    Double_t  probExt_1_to_0              ; tree->SetBranchAddress("probExt_1_to_0"              , &probExt_1_to_0              );
	    Double_t  probExt_0_to_1              ; tree->SetBranchAddress("probExt_0_to_1"              , &probExt_0_to_1              );
	    Double_t  chisqInt                    ; tree->SetBranchAddress("chisqInt"                    , &chisqInt                    );
	    Double_t  chiSqExt_0_to_1             ; tree->SetBranchAddress("chiSqExt_0_to_1"             , &chiSqExt_0_to_1             );
	    Double_t  chiSqExt_1_to_0             ; tree->SetBranchAddress("chiSqExt_1_to_0"             , &chiSqExt_1_to_0             );
	    Bool_t    elOnSameSide                ; tree->SetBranchAddress("elOnSameSide"                , &elOnSameSide                );
	    Int_t     nElectrons                  ; tree->SetBranchAddress("nElectrons"                  , &nElectrons                  );
	    Double_t  el_energy_[2]               ; tree->SetBranchAddress("el_energy_"                  , el_energy_                   );
	    Double_t  el_dEnergy_[2]              ; tree->SetBranchAddress("el_dEnergy_"                 , el_dEnergy_                  );
	    Double_t  el_beta_[2]                 ; tree->SetBranchAddress("el_beta_"                    , el_beta_                     );
	    Double_t  el_dBeta_[2]                ; tree->SetBranchAddress("el_dBeta_"                   , el_dBeta_                    );
	    Double_t  el_pathLength_[2]           ; tree->SetBranchAddress("el_pathLength_"              , el_pathLength_               );
	    Double_t  el_energyLoss_[2]           ; tree->SetBranchAddress("el_energyLoss_"              , el_energyLoss_               );
	    Double_t  el_measTime_[2]             ; tree->SetBranchAddress("el_measTime_"                , el_measTime_                 );
	    Double_t  el_dMeasTime_[2]            ; tree->SetBranchAddress("el_dMeasTime_"               , el_dMeasTime_                );
	    Double_t  el_thTof_[2]                ; tree->SetBranchAddress("el_thTof_"                   , el_thTof_                    );
	    Double_t  el_dThTof_[2]               ; tree->SetBranchAddress("el_dThTof_"                  , el_dThTof_                   );
	    Int_t     el_side_[2]                 ; tree->SetBranchAddress("el_side_"                    , el_side_                     );
	    Int_t     el_caloiobt[2]              ; tree->SetBranchAddress("el_caloiobt"                 , el_caloiobt                  );
	    Int_t     el_calofcll[2]              ; tree->SetBranchAddress("el_calofcll"                 , el_calofcll                  );
	    Int_t     el_caloHsFlag[2]            ; tree->SetBranchAddress("el_caloHsFlag_"              , el_caloHsFlag                );
	    Double_t  el_trkSign[2]               ; tree->SetBranchAddress("el_trkSign"                  , el_trkSign                   );
	    Double_t  el_min_xy_dist[2]           ; tree->SetBranchAddress("el_min_xy_dist_"             , el_min_xy_dist               );
	    Double_t  el_min_z_dist[2]            ; tree->SetBranchAddress("el_min_z_dist_"              , el_min_z_dist                );
	    Double_t  el_vtx_x_[2]                ; tree->SetBranchAddress("el_vtx_x_"                   , el_vtx_x_                    );
	    Double_t  el_vtx_y_[2]                ; tree->SetBranchAddress("el_vtx_y_"                   , el_vtx_y_                    );
	    Double_t  el_vtx_z_[2]                ; tree->SetBranchAddress("el_vtx_z_"                   , el_vtx_z_                    );
	    Double_t  el_ip_x_[2]                 ; tree->SetBranchAddress("el_ip_x_"                    , el_ip_x_                     );
	    Double_t  el_ip_y_[2]                 ; tree->SetBranchAddress("el_ip_y_"                    , el_ip_y_                     );
	    Double_t  el_ip_z_[2]                 ; tree->SetBranchAddress("el_ip_z_"                    , el_ip_z_                     );
	    Int_t     el_n_neighbours_[2]         ; tree->SetBranchAddress("el_n_neighbours_"            , el_n_neighbours_             );
	    Int_t     nGammas                     ; tree->SetBranchAddress("nGammas"                     , &nGammas                     );
	    Int_t     nLowEnergyGammas            ; tree->SetBranchAddress("nLowEnergyGammas"            , &nLowEnergyGammas            );
	    Int_t     nHighEnergyGammas           ; tree->SetBranchAddress("nHighEnergyGammas"           , &nHighEnergyGammas           );
	    Double_t  totELowEnergyGammas         ; tree->SetBranchAddress("totELowEnergyGammas"         , &totELowEnergyGammas         );
	    Double_t  totEHighEnergyGammas        ; tree->SetBranchAddress("totEHighEnergyGammas"        , &totEHighEnergyGammas        );
	    Int_t     nClusters                   ; tree->SetBranchAddress("nClusters_"                  , &nClusters                   );

	    TVector3* eVertex = new TVector3(0,0,0);    tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0); tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
		      		      std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
			
			
			double el_vtx_z_mean_ = (el_vtx_z_[0]+el_vtx_z_[1])/2;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
		    if ( !CheckRunNumber(run) ) continue;
			if (sectorId != 18 || IsExcludedSpot(el_vtx_z_mean_, vertexSector)) continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_trkSign[0] >=0 or el_trkSign[1] >=0 )					  continue; hAnaCutFlow -> Fill(currentcut++);
			if (el_energy_[0] < 0.5 or el_energy_[1] < 0.5)        			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_pathLength_[0] + el_pathLength_[1] < 80)        			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probInt < 0.04)                                    			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probExt_0_to_1 > 0.01 or probExt_1_to_0 > 0.01)    			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (elOnSameSide and nCloseNAPromptHits_Opposite != 0) 			  continue; hAnaCutFlow -> Fill(currentcut++);
			
		    if ((el_caloiobt[0] > 1 and (el_calofcll[0] == 1 or el_calofcll[0] == 2)) or 
		        (el_caloiobt[1] > 1 and (el_calofcll[1] == 1 or el_calofcll[1] == 2))) continue; hAnaCutFlow->Fill(currentcut++);

			// Set min and max variables
		    double el_energy_min   , el_energy_max   ;
		    double el_dEnergy_min  , el_dEnergy_max  ; 
		    double el_beta_min     , el_beta_max     ;
		    double el_dBeta_min    , el_dBeta_max    ;
		    double el_dMeasTime_min, el_dMeasTime_max;
		    double el_dThTof_min   , el_dThTof_max   ;

		    TVector3 el_vtx_min, el_vtx_max, el_ip_min, el_ip_max;
		    if (el_energy_[0] < el_energy_[1]) {
		      el_energy_min    = el_energy_[0]   ; el_energy_max    = el_energy_[1]   ;
		      el_dEnergy_min   = el_dEnergy_[0]  ; el_dEnergy_max   = el_dEnergy_[1]  ;
		      el_beta_min      = el_beta_[0]     ; el_beta_max      = el_beta_[1]     ;
		      el_dBeta_min     = el_dBeta_[0]    ; el_dBeta_max     = el_dBeta_[1]    ;
		      el_dMeasTime_min = el_dMeasTime_[0]; el_dMeasTime_max = el_dMeasTime_[1];
		      el_dThTof_min    = el_dThTof_[0]   ; el_dThTof_max    = el_dThTof_[1]   ;      
		      el_vtx_min.SetXYZ(el_vtx_x_[0], el_vtx_y_[0], el_vtx_z_[0]);
		      el_vtx_max.SetXYZ(el_vtx_x_[1], el_vtx_y_[1], el_vtx_z_[1]);
		      el_ip_min .SetXYZ(el_ip_x_[0] , el_ip_y_[0] , el_ip_z_[0] ); 
		      el_ip_max .SetXYZ(el_ip_x_[1] , el_ip_y_[1] , el_ip_z_[1] );
		    } else {
		      el_energy_min    = el_energy_[1]   ; el_energy_max    = el_energy_[0]   ;
		      el_dEnergy_min   = el_dEnergy_[1]  ; el_dEnergy_max   = el_dEnergy_[0]  ;
		      el_beta_min      = el_beta_[1]     ; el_beta_max      = el_beta_[0]     ;
		      el_dBeta_min     = el_dBeta_[1]    ; el_dBeta_max     = el_dBeta_[0]    ;
		      el_dMeasTime_min = el_dMeasTime_[1]; el_dMeasTime_max = el_dMeasTime_[0];
		      el_dThTof_min    = el_dThTof_[1]   ; el_dThTof_max    = el_dThTof_[0]   ;      
		      el_vtx_min.SetXYZ(el_vtx_x_[1], el_vtx_y_[1], el_vtx_z_[1]);
		      el_vtx_max.SetXYZ(el_vtx_x_[0], el_vtx_y_[0], el_vtx_z_[0]);
		      el_ip_min .SetXYZ(el_ip_x_[1] , el_ip_y_[1] , el_ip_z_[1] );
		      el_ip_max .SetXYZ(el_ip_x_[0] , el_ip_y_[0] , el_ip_z_[0] ); 
		    }

			// Last cut on vertex position on foil
		    TVector3 delta_v = el_vtx_min - el_vtx_max;
		    if (TMath::Abs(delta_v.z()) > 4 or delta_v.Perp() > 2) continue; hAnaCutFlow -> Fill(currentcut++);

			if ( IsHotSpot(eVertex->z(), vertexSector) ) continue; hAnaCutFlow -> Fill(currentcut++);

			// Apply radon map
		    double weight = 1;    
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }
		
			// Fill histogram
		    histo_collection->Find(TString::Format("%s_h_run"                    , d->GetName()) ) -> Fill(run                    , weight);
		    histo_collection->Find(TString::Format("%s_h_sectorId"               , d->GetName()) ) -> Fill(sectorId               , weight);
		    histo_collection->Find(TString::Format("%s_h_sourceId"               , d->GetName()) ) -> Fill(sourceId               , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_min"          , d->GetName()) ) -> Fill(el_energy_min          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_max"          , d->GetName()) ) -> Fill(el_energy_max          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_min"         , d->GetName()) ) -> Fill(el_dEnergy_min         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_max"         , d->GetName()) ) -> Fill(el_dEnergy_max         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_min"            , d->GetName()) ) -> Fill(el_beta_min            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_max"            , d->GetName()) ) -> Fill(el_beta_max            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_min"           , d->GetName()) ) -> Fill(el_dBeta_min           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_max"           , d->GetName()) ) -> Fill(el_dBeta_max           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_min"       , d->GetName()) ) -> Fill(el_dMeasTime_min       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_max"       , d->GetName()) ) -> Fill(el_dMeasTime_max       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_min"          , d->GetName()) ) -> Fill(el_dThTof_min          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_max"          , d->GetName()) ) -> Fill(el_dThTof_max          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_0"            , d->GetName()) ) -> Fill(el_energy_[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_1"            , d->GetName()) ) -> Fill(el_energy_[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_0"           , d->GetName()) ) -> Fill(el_dEnergy_[0]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_1"           , d->GetName()) ) -> Fill(el_dEnergy_[1]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_0"              , d->GetName()) ) -> Fill(el_beta_[0]            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_1"              , d->GetName()) ) -> Fill(el_beta_[1]            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_0"             , d->GetName()) ) -> Fill(el_dBeta_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_1"             , d->GetName()) ) -> Fill(el_dBeta_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_pathLength_0"        , d->GetName()) ) -> Fill(el_pathLength_[0]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_pathLength_1"        , d->GetName()) ) -> Fill(el_pathLength_[1]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energyLoss_0"        , d->GetName()) ) -> Fill(el_energyLoss_[0]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energyLoss_1"        , d->GetName()) ) -> Fill(el_energyLoss_[1]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_measTime_0"          , d->GetName()) ) -> Fill(el_measTime_[0]        , weight);
		    histo_collection->Find(TString::Format("%s_h_el_measTime_1"          , d->GetName()) ) -> Fill(el_measTime_[1]        , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_0"         , d->GetName()) ) -> Fill(el_dMeasTime_[0]       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_1"         , d->GetName()) ) -> Fill(el_dMeasTime_[1]       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_thTof_0"             , d->GetName()) ) -> Fill(el_thTof_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_thTof_1"             , d->GetName()) ) -> Fill(el_thTof_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_0"            , d->GetName()) ) -> Fill(el_dThTof_[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_1"            , d->GetName()) ) -> Fill(el_dThTof_[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_caloiobt0"           , d->GetName()) ) -> Fill(el_caloiobt[0]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_caloiobt1"           , d->GetName()) ) -> Fill(el_caloiobt[1]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_trkSign0"            , d->GetName()) ) -> Fill(el_trkSign[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_trkSign1"            , d->GetName()) ) -> Fill(el_trkSign[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_nTracks"                , d->GetName()) ) -> Fill(nTracks                , weight);
		    histo_collection->Find(TString::Format("%s_h_nCaloHits"              , d->GetName()) ) -> Fill(nCaloHits              , weight);
		    histo_collection->Find(TString::Format("%s_h_nRawCaloHits"           , d->GetName()) ) -> Fill(nRawCaloHits           , weight);
		    histo_collection->Find(TString::Format("%s_h_vertexZ"                , d->GetName()) ) -> Fill(eVertex->z()           , weight);
		    histo_collection->Find(TString::Format("%s_h_vertexSector"           , d->GetName()) ) -> Fill(vertexSector           , weight);
		    histo_collection->Find(TString::Format("%s_h_trueVertexZ"            , d->GetName()) ) -> Fill(trueVertex->z()        , weight);
		    histo_collection->Find(TString::Format("%s_h_cosTheta"               , d->GetName()) ) -> Fill(cosTheta               , weight);
		    histo_collection->Find(TString::Format("%s_h_probInt"                , d->GetName()) ) -> Fill(probInt                , weight);
		    histo_collection->Find(TString::Format("%s_h_probExt_1_to_0"         , d->GetName()) ) -> Fill(probExt_1_to_0         , weight);
		    histo_collection->Find(TString::Format("%s_h_probExt_0_to_1"         , d->GetName()) ) -> Fill(probExt_0_to_1         , weight);
		    histo_collection->Find(TString::Format("%s_h_chisqInt"               , d->GetName()) ) -> Fill(chisqInt               , weight);
		    histo_collection->Find(TString::Format("%s_h_chiSqExt_0_to_1"        , d->GetName()) ) -> Fill(chiSqExt_0_to_1        , weight);
		    histo_collection->Find(TString::Format("%s_h_chiSqExt_1_to_0"        , d->GetName()) ) -> Fill(chiSqExt_1_to_0        , weight);
		    histo_collection->Find(TString::Format("%s_h_nGammas"                , d->GetName()) ) -> Fill(nGammas                , weight);
		    histo_collection->Find(TString::Format("%s_h_nLowEnergyGammas"       , d->GetName()) ) -> Fill(nLowEnergyGammas       , weight);
		    histo_collection->Find(TString::Format("%s_h_nHighEnergyGammas"      , d->GetName()) ) -> Fill(nHighEnergyGammas      , weight);
		    histo_collection->Find(TString::Format("%s_h_totELowEnergyGammas"    , d->GetName()) ) -> Fill(totELowEnergyGammas    , weight);
		    histo_collection->Find(TString::Format("%s_h_totEHighEnergyGammas"   , d->GetName()) ) -> Fill(totEHighEnergyGammas   , weight);
		    histo_collection->Find(TString::Format("%s_h_nClusters"              , d->GetName()) ) -> Fill(nClusters              , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseNAPromptHits"     , d->GetName()) ) -> Fill(nCloseNAPromptHits     , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarNAPromptHits"       , d->GetName()) ) -> Fill(nFarNAPromptHits       , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarDelayedHits"        , d->GetName()) ) -> Fill(nFarDelayedHits        , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseDelayedHits"      , d->GetName()) ) -> Fill(nCloseDelayedHits      , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarDelayedClusters"    , d->GetName()) ) -> Fill(nFarDelayedClusters    , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseDelayedCslusters" , d->GetName()) ) -> Fill(nCloseDelayedCslusters , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dx"                 , d->GetName()) ) -> Fill(delta_v.x()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dy"                 , d->GetName()) ) -> Fill(delta_v.y()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dz"                 , d->GetName()) ) -> Fill(delta_v.z()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_x"             , d->GetName()) ) -> Fill(el_vtx_x_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_y"             , d->GetName()) ) -> Fill(el_vtx_y_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_z"             , d->GetName()) ) -> Fill(el_vtx_z_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_x"             , d->GetName()) ) -> Fill(el_vtx_x_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_y"             , d->GetName()) ) -> Fill(el_vtx_y_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_z"             , d->GetName()) ) -> Fill(el_vtx_z_[1]           , weight);
			 

			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, eVertex->z()); 
			 
		    double tot_e = el_energy_[0] + el_energy_[1];
			
		    if (run < 3396) {

		      	
				histo_collection->Find(TString::Format("%s_h_min_e_energy_P1" , d->GetName()) ) -> Fill(el_energy_min , weight);
				histo_collection->Find(TString::Format("%s_h_max_e_energy_P1" , d->GetName()) ) -> Fill(el_energy_max , weight);
				histo_collection->Find(TString::Format("%s_h_cosTheta_P1"     , d->GetName()) ) -> Fill(cosTheta      , weight);
		        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1" , d->GetName()) ) -> Fill(tot_e         , weight);

				if( IsHotSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P1_hot" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P1_hot" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P1_hot"    , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_hot" , d->GetName()) ) -> Fill(tot_e         , weight);
				} else if( IsWarmSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P1_warm" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P1_warm" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P1_warm"     , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_warm" , d->GetName()) ) -> Fill(tot_e         , weight);
				} else if( IsColdSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P1_cold" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P1_cold" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P1_cold"     , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_cold" , d->GetName()) ) -> Fill(tot_e         , weight);
				}

		        if (el_side_[0] == el_side_[1]) {
					if (el_side_[0] == 0) {
						histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_SS_In", d->GetName()) ) -> Fill(tot_e , weight);
		          	} else {
						histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_SS_Out", d->GetName()) ) -> Fill(tot_e , weight);
		          	}
		        } else {
					histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_OS", d->GetName()) ) -> Fill(tot_e , weight);
		        }

		    } else {
				
				histo_collection->Find(TString::Format("%s_h_min_e_energy_P2" , d->GetName()) ) -> Fill(el_energy_min , weight);
				histo_collection->Find(TString::Format("%s_h_max_e_energy_P2" , d->GetName()) ) -> Fill(el_energy_max , weight);
				histo_collection->Find(TString::Format("%s_h_cosTheta_P2"     , d->GetName()) ) -> Fill(cosTheta      , weight);
		        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2" , d->GetName()) ) -> Fill(tot_e         , weight);

				if( IsHotSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P2_hot" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P2_hot" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P2_hot"    , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_hot" , d->GetName()) ) -> Fill(tot_e         , weight);
				} else if( IsWarmSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P2_warm" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P2_warm" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P2_warm"     , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_warm" , d->GetName()) ) -> Fill(tot_e         , weight);
				} else if( IsColdSpot(el_vtx_z_mean_, vertexSector) ) {
					histo_collection->Find(TString::Format("%s_h_min_e_energy_P2_cold" , d->GetName()) ) -> Fill(el_energy_min , weight);
					histo_collection->Find(TString::Format("%s_h_max_e_energy_P2_cold" , d->GetName()) ) -> Fill(el_energy_max , weight);
					histo_collection->Find(TString::Format("%s_h_cosTheta_P2_cold"     , d->GetName()) ) -> Fill(cosTheta      , weight);
			        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_cold" , d->GetName()) ) -> Fill(tot_e         , weight);
				}
				

		        if (el_side_[0] == el_side_[1]) {
		          if (el_side_[0] == 0) {
		            histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_SS_In", d->GetName()) ) -> Fill(tot_e , weight);
		          } else {
		            histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_SS_Out", d->GetName()) ) -> Fill(tot_e , weight);
		          }
		        } else {
					histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_OS", d->GetName()) ) -> Fill(tot_e , weight);
		        }
		      
		    }

		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
	
		// Delete the remaining crap
		histo_collection->Delete();	
		tree->Delete();
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;

	}
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process two electrons external channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 11/11/2014
	//
	//////////////////////////////////////////////////////////////////////////////
	bool ProcessTwoElectronExternal( DataSet *d ){
		
		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
		cutNames->push_back("Cd-116 sector (18) ");
	    cutNames->push_back("Track with opposite curvature");
	    cutNames->push_back("Energy one electron > 300 keV");
		cutNames->push_back("Internal probability < 0.01");
		cutNames->push_back("External probability > 0.04");
		cutNames->push_back("|dz_vtx| < 8 cm and radial distance < 4");
		cutNames->push_back("Not an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos
		histo_collection->Add( new TH1D( TString::Format("%s_h_run"                    , d->GetName()) , "; Run; No.Events",    200, 1000, 9500                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_sectorId"               , d->GetName()) , "; Sector; No.Events",  21, -0.5, 20.5                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_sourceId"               , d->GetName()) , "; Source; No.Events",   4, -1.5, 2.5                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_min"          , d->GetName()) , "; Min E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_max"          , d->GetName()) , "; Max E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_min"         , d->GetName()) , "; Min dE_{e} / MeV; No.Events / 0.01 MeV", 50, 0, 0.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_max"         , d->GetName()) , "; Max dE_{e} / MeV; No.Events / 0.01 MeV", 50, 0, 0.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_min"            , d->GetName()) , "; Min - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_max"            , d->GetName()) , "; Max - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_min"           , d->GetName()) , "; Min - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_max"           , d->GetName()) , "; Max - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_min"       , d->GetName()) , "; Min - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_max"       , d->GetName()) , "; Max - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_min"          , d->GetName()) , "; Min - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_max"          , d->GetName()) , "; Max - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_0"            , d->GetName()) , "; First el. - E / MeV; No.Events / 0.1 MeV", 35, 0, 3.5             ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energy_1"            , d->GetName()) , "; Last el. - E / MeV; No.Events / 0.1 MeV", 35, 0, 3.5              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_0"           , d->GetName()) , "; First el. - dE / MeV; No.Events / 0.01 MeV", 50, 0, 0.5           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dEnergy_1"           , d->GetName()) , "; Last el. - dE / MeV; No.Events / 0.01 MeV", 50, 0, 0.5            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_0"              , d->GetName()) , "; First el. - #beta_{e}; No.Events / 0.01",100, 0.6, 1.6            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_beta_1"              , d->GetName()) , "; Last el. - #beta_{e}; No.Events / 0.01", 100, 0.6, 1.6            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_0"             , d->GetName()) , "; First el. - d#beta_{e}; No.Events / 0.002", 100, 0, 0.2           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dBeta_1"             , d->GetName()) , "; Last el. - d#beta_{e}; No.Events / 0.002",  100, 0, 0.2           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_pathLength_0"        , d->GetName()) , "; First el. - Track Length / cm; No.Events / cm", 200, 0, 200       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_pathLength_1"        , d->GetName()) , "; Last el. - Track Length / cm; No.Events / cm", 200, 0, 200        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energyLoss_0"        , d->GetName()) , "; First el. - Energy Loss / MeV; No.Events / 5 keV", 60, 0, 0.3     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_energyLoss_1"        , d->GetName()) , "; Last el. - Energy Loss / MeV; No.Events / 5 keV", 60, 0, 0.3      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_measTime_0"          , d->GetName()) , "; First el. - T_{meas} / ns; No.Events / 1 ns", 130, -220, -90      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_measTime_1"          , d->GetName()) , "; Last el. - T_{meas} / ns; No.Events / 1 ns",  130, -220, -90      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_0"         , d->GetName()) , "; First el. - dT_{meas} / ns; No.Events / 0.04 ns", 50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dMeasTime_1"         , d->GetName()) , "; Last el. - dT_{meas} / ns; No.Events / 0.04 ns",  50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_thTof_0"             , d->GetName()) , "; First el. - T_{theo} / ns; No.Events / 1 ns", 50, 0, 50           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_thTof_1"             , d->GetName()) , "; Last el. - T_{theo} / ns; No.Events / 1 ns",  50, 0, 50           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_0"            , d->GetName()) , "; First el. - dT_{theo} / ns; No.Events / 0.04 ns", 50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_dThTof_1"            , d->GetName()) , "; Last el. - dT_{theo} / ns; No.Events / 0.04 ns",  50, 0, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_caloiobt0"           , d->GetName()) , "; First el. - IOBT; No.Events", 5, -0.5, 4.5                        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_caloiobt1"           , d->GetName()) , "; Last el. - IOBT; No.Events", 5, -0.5, 4.5                         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_trkSign0"            , d->GetName()) , "; First el. - Sign of Track Curvature; No.Events", 10, -2, 2        ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_el_trkSign1"            , d->GetName()) , "; Last el. - Sign of Track Curvature; No.Events", 10, -2, 2         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nTracks"                , d->GetName()) , "; N. Tracks; No.Events" , 15, -0.5, 14.5                            ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCaloHits"              , d->GetName()) , "; N. Calo Hits; No.Events" , 15, -0.5, 14.5                         ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nRawCaloHits"           , d->GetName()) , "; N. Raw Calo Hits; No.Events" , 15, -0.5, 14.5                     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexZ"                , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                 ) );
		histo_collection->Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"          , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexSector"           , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_trueVertexZ"            , d->GetName()) , "; True - Z_{vertex} / cm ; No.Events / cm", 260, -130, 130          ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_trueVertexSector"       , d->GetName()) , "; True - Sector Number; No.Events", 200, 0, 20                      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_cosTheta"               , d->GetName()) , "; Cos(#Theta); No.Events", 100, -1, 1                               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probInt"                , d->GetName()) , "; Internal Prob.; No.Events", 100, 0, 1.1                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probExt_1_to_0"         , d->GetName()) , "; Last to First - External Prob.; No.Events", 100, 0, 0.1           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_probExt_0_to_1"         , d->GetName()) , "; First to Last - External Prob.; No.Events", 100, 0, 1.1           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chisqInt"               , d->GetName()) , "; Internal #Chi^{2}; No.Events", 100, 0, 8000                       ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chiSqExt_0_to_1"        , d->GetName()) , "; First to Last - #Chi^{2}; No.Events", 100, 0, 5000                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_chiSqExt_1_to_0"        , d->GetName()) , "; Last to First - #Chi^{2}; No.Events", 100, 0, 10000               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nGammas"                , d->GetName()) , "; No. #gammas; No.Events", 15, -0.5, 14.5                           ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nLowEnergyGammas"       , d->GetName()) , "; No. Low E #gamma; No.Events", 15, -0.5, 14.5                      ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nHighEnergyGammas"      , d->GetName()) , "; No. High E #gamma; No.Events", 15, -0.5, 14.5                     ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_totELowEnergyGammas"    , d->GetName()) , "; #Sigma E_{#gamma}^{low} / MeV; No.Events / 0.02 MeV", 50, 0, 1    ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_totEHighEnergyGammas"   , d->GetName()) , "; #Sigma E_{#gamma}^{high} / MeV; No.Events / 0.05 MeV", 50, 0, 2.5 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nClusters"              , d->GetName()) , "; No. #gamma clusters; No.Events", 15, -0.5, 14.5                   ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarNAPromptHits"       , d->GetName()) , "; N. far prompt hits; No.Events", 21, -0.5, 20.5                    ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseNAPromptHits"     , d->GetName()) , "; N. close prompt hits; No.Events", 21, -0.5, 20.5                  ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarDelayedHits"        , d->GetName()) , "; N. far delayed hits; No.Events", 21, -0.5, 20.5                   ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseDelayedHits"      , d->GetName()) , "; N. close delayed hits; No.Events", 21, -0.5, 20.5                 ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nFarDelayedClusters"    , d->GetName()) , "; N. far delayed clusters; No.Events", 21, -0.5, 20.5               ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_nCloseDelayedCslusters" , d->GetName()) , "; N. close delayed clusters; No.Events", 21, -0.5, 20.5             ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P1"        , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_tot_e_energy_P2"        , d->GetName()) , "; #Sigma E_{e} / MeV; No.Events / 0.1 MeV", 46, 0, 4.6              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dx"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dy"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_dz"                 , d->GetName()) , "; cm; No.Events / 1mm", 300, -15, 15                                ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_x"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_y"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_0_z"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -130, 130                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_x"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_y"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -170, 170                              ) );
		histo_collection->Add( new TH1D( TString::Format("%s_h_vtx_el_1_z"             , d->GetName()) , "; cm; No.Events / 1mm", 300, -130, 130                              ) );

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t     run                         ; tree->SetBranchAddress("run"                         , &run                         );
	    Int_t     event                       ; tree->SetBranchAddress("event"                       , &event                       );
	    Int_t     runType                     ; tree->SetBranchAddress("runType"                     , &runType                     );
		Double_t  eventTime                   ; tree->SetBranchAddress("eventTime"                   , &eventTime                   );
	    Int_t     timeStampSec                ; tree->SetBranchAddress("timeStampSec"                , &timeStampSec                );
	    Int_t     timeStampNanoS              ; tree->SetBranchAddress("timeStampNanoS"              , &timeStampNanoS              );
	    Double_t  radonWeight                 ; tree->SetBranchAddress("radonWeight"                 , &radonWeight                 );
	    Double_t  bi210Weight                 ; tree->SetBranchAddress("bi210Weight"                 , &bi210Weight                 );
	    Double_t  sfoilRadonWeight            ; tree->SetBranchAddress("sfoilRadonWeight"            , &sfoilRadonWeight            );
	    Double_t  cosThetaWeight              ; tree->SetBranchAddress("cosThetaWeight"              , &cosThetaWeight              );
	    Int_t     foilSide                    ; tree->SetBranchAddress("foilSide"                    , &foilSide                    );
	    Int_t     sectorId                    ; tree->SetBranchAddress("sectorId"                    , &sectorId                    );
	    Int_t     sourceId                    ; tree->SetBranchAddress("sourceId"                    , &sourceId                    );
	    Int_t     isInHotSpot                 ; tree->SetBranchAddress("isInHotSpot"                 , &isInHotSpot                 );
	    Double_t  vertexSector                ; tree->SetBranchAddress("vertexSector"                , &vertexSector                );
	    Int_t     nTracks                     ; tree->SetBranchAddress("nTracks"                     , &nTracks                     );
	    Int_t     nCaloHits                   ; tree->SetBranchAddress("nCaloHits"                   , &nCaloHits                   );
	    Int_t     nRawCaloHits                ; tree->SetBranchAddress("nRawCaloHits"                , &nRawCaloHits                );
	    Int_t     nAlphas                     ; tree->SetBranchAddress("nAlphas_"                    , &nAlphas                     );
	    Int_t     nFarNAPromptHits            ; tree->SetBranchAddress("nFarNAPromptHits"            , &nFarNAPromptHits            );
	    Int_t     nCloseNAPromptHits          ; tree->SetBranchAddress("nCloseNAPromptHits"          , &nCloseNAPromptHits          );
	    Int_t     nFarDelayedHits             ; tree->SetBranchAddress("nFarDelayedHits"             , &nFarDelayedHits             );
	    Int_t     nCloseDelayedHits           ; tree->SetBranchAddress("nCloseDelayedHits"           , &nCloseDelayedHits           );
	    Int_t     nFarDelayedClusters         ; tree->SetBranchAddress("nFarDelayedClusters"         , &nFarDelayedClusters         );
	    Int_t     nCloseDelayedCslusters      ; tree->SetBranchAddress("nCloseDelayedCslusters"      , &nCloseDelayedCslusters      );
	    Int_t     nFarNAPromptHits_Opposite   ; tree->SetBranchAddress("nFarNAPromptHits_Opposite"   , &nFarNAPromptHits_Opposite   );
	    Int_t     nCloseNAPromptHits_Opposite ; tree->SetBranchAddress("nCloseNAPromptHits_Opposite" , &nCloseNAPromptHits_Opposite );
	    Int_t     nDelayedHits                ; tree->SetBranchAddress("nDelayedHits"                , &nDelayedHits                );
	    Double_t  cosTheta                    ; tree->SetBranchAddress("cosTheta"                    , &cosTheta                    );
	    Double_t  probInt                     ; tree->SetBranchAddress("probInt"                     , &probInt                     );
	    Double_t  probExt_1_to_0              ; tree->SetBranchAddress("probExt_1_to_0"              , &probExt_1_to_0              );
	    Double_t  probExt_0_to_1              ; tree->SetBranchAddress("probExt_0_to_1"              , &probExt_0_to_1              );
	    Double_t  chisqInt                    ; tree->SetBranchAddress("chisqInt"                    , &chisqInt                    );
	    Double_t  chiSqExt_0_to_1             ; tree->SetBranchAddress("chiSqExt_0_to_1"             , &chiSqExt_0_to_1             );
	    Double_t  chiSqExt_1_to_0             ; tree->SetBranchAddress("chiSqExt_1_to_0"             , &chiSqExt_1_to_0             );
	    Bool_t    elOnSameSide                ; tree->SetBranchAddress("elOnSameSide"                , &elOnSameSide                );
	    Int_t     nElectrons                  ; tree->SetBranchAddress("nElectrons"                  , &nElectrons                  );
	    Double_t  el_energy_[2]               ; tree->SetBranchAddress("el_energy_"                  , el_energy_                   );
	    Double_t  el_dEnergy_[2]              ; tree->SetBranchAddress("el_dEnergy_"                 , el_dEnergy_                  );
	    Double_t  el_beta_[2]                 ; tree->SetBranchAddress("el_beta_"                    , el_beta_                     );
	    Double_t  el_dBeta_[2]                ; tree->SetBranchAddress("el_dBeta_"                   , el_dBeta_                    );
	    Double_t  el_pathLength_[2]           ; tree->SetBranchAddress("el_pathLength_"              , el_pathLength_               );
	    Double_t  el_energyLoss_[2]           ; tree->SetBranchAddress("el_energyLoss_"              , el_energyLoss_               );
	    Double_t  el_measTime_[2]             ; tree->SetBranchAddress("el_measTime_"                , el_measTime_                 );
	    Double_t  el_dMeasTime_[2]            ; tree->SetBranchAddress("el_dMeasTime_"               , el_dMeasTime_                );
	    Double_t  el_thTof_[2]                ; tree->SetBranchAddress("el_thTof_"                   , el_thTof_                    );
	    Double_t  el_dThTof_[2]               ; tree->SetBranchAddress("el_dThTof_"                  , el_dThTof_                   );
	    Int_t     el_side_[2]                 ; tree->SetBranchAddress("el_side_"                    , el_side_                     );
	    Int_t     el_caloiobt[2]              ; tree->SetBranchAddress("el_caloiobt"                 , el_caloiobt                  );
	    Int_t     el_calofcll[2]              ; tree->SetBranchAddress("el_calofcll"                 , el_calofcll                  );
	    Int_t     el_caloHsFlag[2]            ; tree->SetBranchAddress("el_caloHsFlag_"              , el_caloHsFlag                );
	    Double_t  el_trkSign[2]               ; tree->SetBranchAddress("el_trkSign"                  , el_trkSign                   );
	    Double_t  el_min_xy_dist[2]           ; tree->SetBranchAddress("el_min_xy_dist_"             , el_min_xy_dist               );
	    Double_t  el_min_z_dist[2]            ; tree->SetBranchAddress("el_min_z_dist_"              , el_min_z_dist                );
	    Double_t  el_vtx_x_[2]                ; tree->SetBranchAddress("el_vtx_x_"                   , el_vtx_x_                    );
	    Double_t  el_vtx_y_[2]                ; tree->SetBranchAddress("el_vtx_y_"                   , el_vtx_y_                    );
	    Double_t  el_vtx_z_[2]                ; tree->SetBranchAddress("el_vtx_z_"                   , el_vtx_z_                    );
	    Double_t  el_ip_x_[2]                 ; tree->SetBranchAddress("el_ip_x_"                    , el_ip_x_                     );
	    Double_t  el_ip_y_[2]                 ; tree->SetBranchAddress("el_ip_y_"                    , el_ip_y_                     );
	    Double_t  el_ip_z_[2]                 ; tree->SetBranchAddress("el_ip_z_"                    , el_ip_z_                     );
	    Int_t     nGammas                     ; tree->SetBranchAddress("nGammas"                     , &nGammas                     );
	    Int_t     nLowEnergyGammas            ; tree->SetBranchAddress("nLowEnergyGammas"            , &nLowEnergyGammas            );
	    Int_t     nHighEnergyGammas           ; tree->SetBranchAddress("nHighEnergyGammas"           , &nHighEnergyGammas           );
	    Double_t  totELowEnergyGammas         ; tree->SetBranchAddress("totELowEnergyGammas"         , &totELowEnergyGammas         );
	    Double_t  totEHighEnergyGammas        ; tree->SetBranchAddress("totEHighEnergyGammas"        , &totEHighEnergyGammas        );
	    Int_t     nClusters                   ; tree->SetBranchAddress("nClusters_"                  , &nClusters                   );

	    TVector3* eVertex = new TVector3(0,0,0);    tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0); tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
			if ( !CheckRunNumber(run) ) continue;
		    if (sectorId != 18 || IsExcludedSpot(eVertex->z(), vertexSector)) continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_trkSign[0] == el_trkSign[1] )							  continue; hAnaCutFlow -> Fill(currentcut++);
			if (el_energy_[0] < 0.3 and el_energy_[1] < 0.3)     			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probInt > 0.01)                                  			  continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probExt_0_to_1 < 0.04 and probExt_1_to_0 < 0.04) 			  continue; hAnaCutFlow -> Fill(currentcut++);
			if ( IsHotSpot(eVertex->z(), vertexSector) ) 	     			  continue; hAnaCutFlow -> Fill(currentcut++);
			
			// Set min and max variables
		    double el_energy_min   , el_energy_max   ;
		    double el_dEnergy_min  , el_dEnergy_max  ; 
		    double el_beta_min     , el_beta_max     ;
		    double el_dBeta_min    , el_dBeta_max    ;
		    double el_dMeasTime_min, el_dMeasTime_max;
		    double el_dThTof_min   , el_dThTof_max   ;

		    TVector3 el_vtx_min, el_vtx_max, el_ip_min, el_ip_max;
		    if (el_energy_[0] < el_energy_[1]) {
		      el_energy_min    = el_energy_[0]   ; el_energy_max    = el_energy_[1]   ;
		      el_dEnergy_min   = el_dEnergy_[0]  ; el_dEnergy_max   = el_dEnergy_[1]  ;
		      el_beta_min      = el_beta_[0]     ; el_beta_max      = el_beta_[1]     ;
		      el_dBeta_min     = el_dBeta_[0]    ; el_dBeta_max     = el_dBeta_[1]    ;
		      el_dMeasTime_min = el_dMeasTime_[0]; el_dMeasTime_max = el_dMeasTime_[1];
		      el_dThTof_min    = el_dThTof_[0]   ; el_dThTof_max    = el_dThTof_[1]   ;      
		      el_vtx_min.SetXYZ(el_vtx_x_[0], el_vtx_y_[0], el_vtx_z_[0]);
		      el_vtx_max.SetXYZ(el_vtx_x_[1], el_vtx_y_[1], el_vtx_z_[1]);
		      el_ip_min .SetXYZ(el_ip_x_[0] , el_ip_y_[0] , el_ip_z_[0] ); 
		      el_ip_max .SetXYZ(el_ip_x_[1] , el_ip_y_[1] , el_ip_z_[1] );
		    } else {
		      el_energy_min    = el_energy_[1]   ; el_energy_max    = el_energy_[0]   ;
		      el_dEnergy_min   = el_dEnergy_[1]  ; el_dEnergy_max   = el_dEnergy_[0]  ;
		      el_beta_min      = el_beta_[1]     ; el_beta_max      = el_beta_[0]     ;
		      el_dBeta_min     = el_dBeta_[1]    ; el_dBeta_max     = el_dBeta_[0]    ;
		      el_dMeasTime_min = el_dMeasTime_[1]; el_dMeasTime_max = el_dMeasTime_[0];
		      el_dThTof_min    = el_dThTof_[1]   ; el_dThTof_max    = el_dThTof_[0]   ;      
		      el_vtx_min.SetXYZ(el_vtx_x_[1], el_vtx_y_[1], el_vtx_z_[1]);
		      el_vtx_max.SetXYZ(el_vtx_x_[0], el_vtx_y_[0], el_vtx_z_[0]);
		      el_ip_min .SetXYZ(el_ip_x_[1] , el_ip_y_[1] , el_ip_z_[1] );
		      el_ip_max .SetXYZ(el_ip_x_[0] , el_ip_y_[0] , el_ip_z_[0] ); 
		    }

			// Last cut on vertex position on foil
		    TVector3 delta_v = el_vtx_min - el_vtx_max;
		    if (TMath::Abs(delta_v.z()) > 8 or delta_v.Perp() > 4) continue; hAnaCutFlow -> Fill(currentcut++);

			// Apply radon map
		    double weight = 1;    
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }
			
			// Fill histogram
		    histo_collection->Find(TString::Format("%s_h_run"                    , d->GetName()) ) -> Fill(run                    , weight);
		    histo_collection->Find(TString::Format("%s_h_sectorId"               , d->GetName()) ) -> Fill(sectorId               , weight);
		    histo_collection->Find(TString::Format("%s_h_sourceId"               , d->GetName()) ) -> Fill(sourceId               , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_min"          , d->GetName()) ) -> Fill(el_energy_min          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_max"          , d->GetName()) ) -> Fill(el_energy_max          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_min"         , d->GetName()) ) -> Fill(el_dEnergy_min         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_max"         , d->GetName()) ) -> Fill(el_dEnergy_max         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_min"            , d->GetName()) ) -> Fill(el_beta_min            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_max"            , d->GetName()) ) -> Fill(el_beta_max            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_min"           , d->GetName()) ) -> Fill(el_dBeta_min           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_max"           , d->GetName()) ) -> Fill(el_dBeta_max           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_min"       , d->GetName()) ) -> Fill(el_dMeasTime_min       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_max"       , d->GetName()) ) -> Fill(el_dMeasTime_max       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_min"          , d->GetName()) ) -> Fill(el_dThTof_min          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_max"          , d->GetName()) ) -> Fill(el_dThTof_max          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_0"            , d->GetName()) ) -> Fill(el_energy_[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energy_1"            , d->GetName()) ) -> Fill(el_energy_[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_0"           , d->GetName()) ) -> Fill(el_dEnergy_[0]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dEnergy_1"           , d->GetName()) ) -> Fill(el_dEnergy_[1]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_0"              , d->GetName()) ) -> Fill(el_beta_[0]            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_beta_1"              , d->GetName()) ) -> Fill(el_beta_[1]            , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_0"             , d->GetName()) ) -> Fill(el_dBeta_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dBeta_1"             , d->GetName()) ) -> Fill(el_dBeta_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_pathLength_0"        , d->GetName()) ) -> Fill(el_pathLength_[0]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_pathLength_1"        , d->GetName()) ) -> Fill(el_pathLength_[1]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energyLoss_0"        , d->GetName()) ) -> Fill(el_energyLoss_[0]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_energyLoss_1"        , d->GetName()) ) -> Fill(el_energyLoss_[1]      , weight);
		    histo_collection->Find(TString::Format("%s_h_el_measTime_0"          , d->GetName()) ) -> Fill(el_measTime_[0]        , weight);
		    histo_collection->Find(TString::Format("%s_h_el_measTime_1"          , d->GetName()) ) -> Fill(el_measTime_[1]        , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_0"         , d->GetName()) ) -> Fill(el_dMeasTime_[0]       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dMeasTime_1"         , d->GetName()) ) -> Fill(el_dMeasTime_[1]       , weight);
		    histo_collection->Find(TString::Format("%s_h_el_thTof_0"             , d->GetName()) ) -> Fill(el_thTof_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_thTof_1"             , d->GetName()) ) -> Fill(el_thTof_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_0"            , d->GetName()) ) -> Fill(el_dThTof_[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_dThTof_1"            , d->GetName()) ) -> Fill(el_dThTof_[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_caloiobt0"           , d->GetName()) ) -> Fill(el_caloiobt[0]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_caloiobt1"           , d->GetName()) ) -> Fill(el_caloiobt[1]         , weight);
		    histo_collection->Find(TString::Format("%s_h_el_trkSign0"            , d->GetName()) ) -> Fill(el_trkSign[0]          , weight);
		    histo_collection->Find(TString::Format("%s_h_el_trkSign1"            , d->GetName()) ) -> Fill(el_trkSign[1]          , weight);
		    histo_collection->Find(TString::Format("%s_h_nTracks"                , d->GetName()) ) -> Fill(nTracks                , weight);
		    histo_collection->Find(TString::Format("%s_h_nCaloHits"              , d->GetName()) ) -> Fill(nCaloHits              , weight);
		    histo_collection->Find(TString::Format("%s_h_nRawCaloHits"           , d->GetName()) ) -> Fill(nRawCaloHits           , weight);
		    histo_collection->Find(TString::Format("%s_h_vertexZ"                , d->GetName()) ) -> Fill(eVertex->z()           , weight);
		    histo_collection->Find(TString::Format("%s_h_vertexSector"           , d->GetName()) ) -> Fill(vertexSector           , weight);
		    histo_collection->Find(TString::Format("%s_h_trueVertexZ"            , d->GetName()) ) -> Fill(trueVertex->z()        , weight);
		    histo_collection->Find(TString::Format("%s_h_cosTheta"               , d->GetName()) ) -> Fill(cosTheta               , weight);
		    histo_collection->Find(TString::Format("%s_h_probInt"                , d->GetName()) ) -> Fill(probInt                , weight);
		    histo_collection->Find(TString::Format("%s_h_probExt_1_to_0"         , d->GetName()) ) -> Fill(probExt_1_to_0         , weight);
		    histo_collection->Find(TString::Format("%s_h_probExt_0_to_1"         , d->GetName()) ) -> Fill(probExt_0_to_1         , weight);
		    histo_collection->Find(TString::Format("%s_h_chisqInt"               , d->GetName()) ) -> Fill(chisqInt               , weight);
		    histo_collection->Find(TString::Format("%s_h_chiSqExt_0_to_1"        , d->GetName()) ) -> Fill(chiSqExt_0_to_1        , weight);
		    histo_collection->Find(TString::Format("%s_h_chiSqExt_1_to_0"        , d->GetName()) ) -> Fill(chiSqExt_1_to_0        , weight);
		    histo_collection->Find(TString::Format("%s_h_nGammas"                , d->GetName()) ) -> Fill(nGammas                , weight);
		    histo_collection->Find(TString::Format("%s_h_nLowEnergyGammas"       , d->GetName()) ) -> Fill(nLowEnergyGammas       , weight);
		    histo_collection->Find(TString::Format("%s_h_nHighEnergyGammas"      , d->GetName()) ) -> Fill(nHighEnergyGammas      , weight);
		    histo_collection->Find(TString::Format("%s_h_totELowEnergyGammas"    , d->GetName()) ) -> Fill(totELowEnergyGammas    , weight);
		    histo_collection->Find(TString::Format("%s_h_totEHighEnergyGammas"   , d->GetName()) ) -> Fill(totEHighEnergyGammas   , weight);
		    histo_collection->Find(TString::Format("%s_h_nClusters"              , d->GetName()) ) -> Fill(nClusters              , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseNAPromptHits"     , d->GetName()) ) -> Fill(nCloseNAPromptHits     , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarNAPromptHits"       , d->GetName()) ) -> Fill(nFarNAPromptHits       , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarDelayedHits"        , d->GetName()) ) -> Fill(nFarDelayedHits        , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseDelayedHits"      , d->GetName()) ) -> Fill(nCloseDelayedHits      , weight);
		    histo_collection->Find(TString::Format("%s_h_nFarDelayedClusters"    , d->GetName()) ) -> Fill(nFarDelayedClusters    , weight);
		    histo_collection->Find(TString::Format("%s_h_nCloseDelayedCslusters" , d->GetName()) ) -> Fill(nCloseDelayedCslusters , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dx"                 , d->GetName()) ) -> Fill(delta_v.x()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dy"                 , d->GetName()) ) -> Fill(delta_v.y()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_dz"                 , d->GetName()) ) -> Fill(delta_v.z()            , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_x"             , d->GetName()) ) -> Fill(el_vtx_x_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_y"             , d->GetName()) ) -> Fill(el_vtx_y_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_0_z"             , d->GetName()) ) -> Fill(el_vtx_z_[0]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_x"             , d->GetName()) ) -> Fill(el_vtx_x_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_y"             , d->GetName()) ) -> Fill(el_vtx_y_[1]           , weight);
		    histo_collection->Find(TString::Format("%s_h_vtx_el_1_z"             , d->GetName()) ) -> Fill(el_vtx_z_[1]           , weight);
			
			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, eVertex->z()); 
			 
		    double tot_e = el_energy_[0] + el_energy_[1];
			
		    if (run < 3396) {
				//if( ! IsHotSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1", d->GetName()) ) -> Fill(tot_e , weight);
			}
		    else {
				//if( ! IsHotSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2", d->GetName()) ) -> Fill(tot_e , weight);		      
		    }

		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;

	}
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process one electron one gamma internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 13/11/2014
	//	
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneGammaInternal( DataSet *d ){
		
		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
		cutNames->push_back("Cd-116 sector (18) ");
		cutNames->push_back("Negative track sign ");
	    cutNames->push_back("One gamma cluster with energy > 200 keV ");
	    cutNames->push_back("Energy one electron > 300 keV ");
		cutNames->push_back("Electrons hit isolated block");
		cutNames->push_back("Internal probability > 0.04");
		cutNames->push_back("Max External probability (e->g ; g->e) < 0.01");
		cutNames->push_back("Not an hot spot");
		
	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_run"             , d->GetName()) , "; Run; No. Events"  , 200, 1000, 9500							        ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_eventTime"       , d->GetName()) , "; Time since 15^{th} Feb 2013 / s; No.Events", 200, 0, 250e6/86400		) );					
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sectorId"        , d->GetName()) , "; Sector; No. Events",  21, -0.5, 20.5							        ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sourceId"        , d->GetName()) , "; Source; No. Events",   4, -1.5, 2.5							        ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy"  , d->GetName()) , "; E_{e} / MeV; No.Events / 0.05 MeV", 100, 0, 5						) );	                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackLength"     , d->GetName()) , "; Track Length / cm; No.Events / cm", 200, 0, 200						) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_trackSign"       , d->GetName()) , "; Sign; No.Events", 5, -2.5, 2.5                                          ) );	                   	                   
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexZ"         , d->GetName()) , "; Z / cm ; No.Events / 0.5 cm", 260, -130, 130							) );                     
		histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexSector"    , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19                               ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_gammaEnergy"     , d->GetName()) , "; E_{#gamma} / MeV; No.Events / 0.1 MeV", 50, 0, 5						) );	                  
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_cosTheta"        , d->GetName()) , "; Cos(#Theta) e - #gamma_{min}; No.Events", 12, -1, 1					) );		               
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_probInt"         , d->GetName()) , "; Int. Prob. e - #gamma_{min}; No.Events",  12, 0, 1					) );		                
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_probExt"         , d->GetName()) , "; Ext. Prob. e - #gamma_{min}; No.Events",  12, 0, 1					) );		                
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_gammaLowEnergy"  , d->GetName()) , "; E_{#gamma} / MeV; No.Events / 0.02 MeV", 25, 0, 0.5					) );		               
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_nLowEnergyGamma" , d->GetName()) , "; N_{#gamma} low E; No.Events", 20, -0.5, 19.5							) );                     
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_layer_vs_side"   , d->GetName()) , "Layer vs Side; Side; Layer", 4, -1.5, 2.5, 10, -0.5, 9.5				) );			            

	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"      , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
						
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1"      , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV", 60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P1"       , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"              ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_g_energy_P1"       , d->GetName()) , "; E_{#gamma}; No. Events / 0.1 MeV"         ,  60, 0, 6  ) );


		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_hot"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );	

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2"      , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV", 60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P2"       , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"             ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_g_energy_P2"       , d->GetName()) , "; E_{#gamma}; No. Events / 0.1 MeV"        ,  60, 0, 6  ) );
		
		
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_hot"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6           ) );	

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t           run                      ; tree->SetBranchAddress("run"                   , &run                   );
	    Int_t           event                    ; tree->SetBranchAddress("event"                 , &event                 );
	    Int_t           timeStampSec             ; tree->SetBranchAddress("timeStampSec"          , &timeStampSec          );
	    Int_t           timeStampNanoS           ; tree->SetBranchAddress("timeStampNanoS"        , &timeStampNanoS        );
	    Double_t        eventTime                ; tree->SetBranchAddress("eventTime"             , &eventTime             );
	    Double_t        radonWeight              ; tree->SetBranchAddress("radonWeight"           , &radonWeight           );
	    Double_t        bi210Weight              ; tree->SetBranchAddress("bi210Weight"           , &bi210Weight           );
	    Double_t        sfoilRadonWeight         ; tree->SetBranchAddress("sfoilRadonWeight"      , &sfoilRadonWeight      );
	    Int_t           foilSide                 ; tree->SetBranchAddress("foilSide"              , &foilSide              );
	    Int_t           sectorId                 ; tree->SetBranchAddress("sectorId"              , &sectorId              );
	    Int_t           sourceId                 ; tree->SetBranchAddress("sourceId"              , &sourceId              );
	    Int_t           isInHotSpot              ; tree->SetBranchAddress("isInHotSpot"           , &isInHotSpot           );
	    Double_t        vertexSector             ; tree->SetBranchAddress("vertexSector"          , &vertexSector          );
	    Int_t           nCaloHits                ; tree->SetBranchAddress("nCaloHits"             , &nCaloHits             );
	    Int_t           nRawCaloHits             ; tree->SetBranchAddress("nRawCaloHits"          , &nRawCaloHits          );
	    Double_t        el_energy_               ; tree->SetBranchAddress("el_energy_"            , &el_energy_            );
	    Int_t           el_side_                 ; tree->SetBranchAddress("el_side_"              , &el_side_              );
	    Double_t        el_dEnergy_              ; tree->SetBranchAddress("el_dEnergy_"           , &el_dEnergy_           );
	    Double_t        el_beta_                 ; tree->SetBranchAddress("el_beta_"              , &el_beta_              );
	    Double_t        el_dBeta_                ; tree->SetBranchAddress("el_dBeta_"             , &el_dBeta_             );
	    Double_t        el_pathLength_           ; tree->SetBranchAddress("el_pathLength_"        , &el_pathLength_        );
	    Double_t        el_energyLoss_           ; tree->SetBranchAddress("el_energyLoss_"        , &el_energyLoss_        );
	    Double_t        el_measTime_             ; tree->SetBranchAddress("el_measTime_"          , &el_measTime_          );
	    Double_t        el_dMeasTime_            ; tree->SetBranchAddress("el_dMeasTime_"         , &el_dMeasTime_         );
	    Double_t        el_thTof_                ; tree->SetBranchAddress("el_thTof_"             , &el_thTof_             );
	    Double_t        el_dThTof_               ; tree->SetBranchAddress("el_dThTof_"            , &el_dThTof_            );
	    Int_t           el_caloiobt              ; tree->SetBranchAddress("el_caloiobt"           , &el_caloiobt           );
	    Int_t           el_calofcll              ; tree->SetBranchAddress("el_calofcll"           , &el_calofcll           );
	    Int_t           el_caloHsFlag_           ; tree->SetBranchAddress("el_caloHsFlag_"        , &el_caloHsFlag_        );
	    Double_t        el_trkSign               ; tree->SetBranchAddress("el_trkSign"            , &el_trkSign            );
	    Double_t        el_tdc_count             ; tree->SetBranchAddress("el_tdc_count"          , &el_tdc_count          );
	    Double_t        el_min_xy_dist_          ; tree->SetBranchAddress("el_min_xy_dist_"       , &el_min_xy_dist_       );
	    Double_t        el_min_z_dist_           ; tree->SetBranchAddress("el_min_z_dist_"        , &el_min_z_dist_        );
	    Double_t        el_vtx_x_                ; tree->SetBranchAddress("el_vtx_x_"             , &el_vtx_x_             );
	    Double_t        el_vtx_y_                ; tree->SetBranchAddress("el_vtx_y_"             , &el_vtx_y_             );
	    Double_t        el_vtx_z_                ; tree->SetBranchAddress("el_vtx_z_"             , &el_vtx_z_             );
	    Double_t        el_ip_x_                 ; tree->SetBranchAddress("el_ip_x_"              , &el_ip_x_              );
	    Double_t        el_ip_y_                 ; tree->SetBranchAddress("el_ip_y_"              , &el_ip_y_              );
	    Double_t        el_ip_z_                 ; tree->SetBranchAddress("el_ip_z_"              , &el_ip_z_              );
	    Int_t           el_first_hit_layer_      ; tree->SetBranchAddress("el_first_hit_layer_"   , &el_first_hit_layer_   );
	    Int_t           el_secnd_hit_layer_      ; tree->SetBranchAddress("el_secnd_hit_layer_"   , &el_secnd_hit_layer_   );
	    Int_t           el_last_hit_layer_       ; tree->SetBranchAddress("el_last_hit_layer_"    , &el_last_hit_layer_    );
	    Int_t           el_nxt_last_hit_layer_   ; tree->SetBranchAddress("el_nxt_last_hit_layer_", &el_nxt_last_hit_layer_);
	    Int_t           el_n_neighbours_         ; tree->SetBranchAddress("el_n_neighbours_"      , &el_n_neighbours_      );
	    Double_t        trueVertexSector         ; tree->SetBranchAddress("trueVertexSector"      , &trueVertexSector      );
	    Int_t           trueVertexLayer          ; tree->SetBranchAddress("trueVertexLayer"       , &trueVertexLayer       );
	    Double_t        trueSectorId             ; tree->SetBranchAddress("trueSectorId"          , &trueSectorId          );
	    Double_t        trueSourceId             ; tree->SetBranchAddress("trueSourceId"          , &trueSourceId          );
	    Int_t           nLowEnergyClusters       ; tree->SetBranchAddress("nLowEnergyClusters"    , &nLowEnergyClusters    );
	    Double_t        totELowEnergyClusters    ; tree->SetBranchAddress("totELowEnergyClusters" , &totELowEnergyClusters );
		Int_t           nNAPromptHits_           ; tree->SetBranchAddress("nNAPromptHits_"        , &nNAPromptHits_        );
		Int_t           nNADelayedHits_          ; tree->SetBranchAddress("nNADelayedHits_"       , &nNADelayedHits_       );
		Int_t           nNANoiseHits_            ; tree->SetBranchAddress("nNANoiseHits_"         , &nNANoiseHits_         );				
		Int_t           nNAPromptHits_near_      ; tree->SetBranchAddress("nNAPromptHits_near_"   , &nNAPromptHits_near_   );
		Int_t           nNADelayedHits_near_     ; tree->SetBranchAddress("nNADelayedHits_near_"  , &nNADelayedHits_near_  );
		Int_t           nNANoiseHits_near_       ; tree->SetBranchAddress("nNANoiseHits_near_"    , &nNANoiseHits_near_    );				
	    Int_t           nClusters_               ; tree->SetBranchAddress("nClusters_"            , &nClusters_            );
	    Int_t           nHighEnergyClusters_     ; tree->SetBranchAddress("nHighEnergyClusters_"  , &nHighEnergyClusters_  );
	    Int_t           gmc_nGammas_[37]         ; tree->SetBranchAddress("gmc_nGammas_"          , gmc_nGammas_           );
	    Double_t        gmc_energy_[37]          ; tree->SetBranchAddress("gmc_energy_"           , gmc_energy_            );
	    Double_t        gmc_dEnergy_[37]         ; tree->SetBranchAddress("gmc_dEnergy_"          , gmc_dEnergy_           );
	    Double_t        gmc_timeSpan_[37]        ; tree->SetBranchAddress("gmc_timeSpan_"         , gmc_timeSpan_          );
	    Double_t        gmc_clusterProb_[37]     ; tree->SetBranchAddress("gmc_clusterProb_"      , gmc_clusterProb_       );
	    Double_t        gmc_measTime_[37]        ; tree->SetBranchAddress("gmc_measTime_"         , gmc_measTime_          );
	    Double_t        gmc_dMeasTime_[37]       ; tree->SetBranchAddress("gmc_dMeasTime_"        , gmc_dMeasTime_         );
	    Double_t        gmc_hitPosition_x_[37]   ; tree->SetBranchAddress("gmc_hitPosition_x_"    , gmc_hitPosition_x_     );
	    Double_t        gmc_hitPosition_y_[37]   ; tree->SetBranchAddress("gmc_hitPosition_y_"    , gmc_hitPosition_y_     );
	    Double_t        gmc_hitPosition_z_[37]   ; tree->SetBranchAddress("gmc_hitPosition_z_"    , gmc_hitPosition_z_     );
	    Double_t        gmc_scintToPMTTime_[37]  ; tree->SetBranchAddress("gmc_scintToPMTTime_"   , gmc_scintToPMTTime_    );
	    Double_t        gmc_dPathLength_[37]     ; tree->SetBranchAddress("gmc_dPathLength_"      , gmc_dPathLength_       );
	    Int_t           gmc_iobt_[37]            ; tree->SetBranchAddress("gmc_iobt_"             , gmc_iobt_              );
	    Int_t           gmc_fcll_[37]            ; tree->SetBranchAddress("gmc_fcll_"             , gmc_fcll_              );
	    Int_t           gmc_clusterId_[37]       ; tree->SetBranchAddress("gmc_clusterId_"        , gmc_clusterId_         );
	    Bool_t          gmc_goodPMTStatuses_[37] ; tree->SetBranchAddress("gmc_goodPMTStatuses_"  , gmc_goodPMTStatuses_   );
	    Bool_t          gmc_goodLDFlags_[37]     ; tree->SetBranchAddress("gmc_goodLDFlags_"      , gmc_goodLDFlags_       );
	    Bool_t          gmc_hasLDCorrs_[37]      ; tree->SetBranchAddress("gmc_hasLDCorrs_"       , gmc_hasLDCorrs_        );
	    Bool_t          gmc_hasLDCorrErrs_[37]   ; tree->SetBranchAddress("gmc_hasLDCorrErrs_"    , gmc_hasLDCorrErrs_     );
	    Bool_t          gmc_goodHSFlags_[37]     ; tree->SetBranchAddress("gmc_goodHSFlags_"      , gmc_goodHSFlags_       );
	    Int_t           gmc_numNeighbours_[37]   ; tree->SetBranchAddress("gmc_numNeighbours_"    , gmc_numNeighbours_     );
		Int_t           gmc_nNAPromptHits_[37]   ; tree->SetBranchAddress("gmc_nNAPromptHits_"    , gmc_nNAPromptHits_     );
		Int_t           gmc_nNADelayedHits_[37]  ; tree->SetBranchAddress("gmc_nNADelayedHits_"   , gmc_nNADelayedHits_    );
		Int_t           gmc_nNANoiseHits_[37]    ; tree->SetBranchAddress("gmc_nNANoiseHits_"     , gmc_nNANoiseHits_      );
	    Double_t        gmc_first_g_time_[37]    ; tree->SetBranchAddress("gmc_first_g_time_"     , gmc_first_g_time_      );
	    Double_t        gmc_first_g_d_time_[37]  ; tree->SetBranchAddress("gmc_first_g_d_time_"   , gmc_first_g_d_time_    );
	    Double_t        gmc_first_g_x_[37]       ; tree->SetBranchAddress("gmc_first_g_x_"        , gmc_first_g_x_         );
	    Double_t        gmc_first_g_y_[37]       ; tree->SetBranchAddress("gmc_first_g_y_"        , gmc_first_g_y_         );
	    Double_t        gmc_first_g_z_[37]       ; tree->SetBranchAddress("gmc_first_g_z_"        , gmc_first_g_z_         );
	    Double_t        gmc_g_th_time_[37]       ; tree->SetBranchAddress("gmc_g_th_time_"        , gmc_g_th_time_         );
	    Double_t        gmc_g_d_th_time_[37]     ; tree->SetBranchAddress("gmc_g_d_th_time_"      , gmc_g_d_th_time_       );
	    Double_t        gmc_int_c_sq_[37]        ; tree->SetBranchAddress("gmc_int_c_sq_"         , gmc_int_c_sq_          );
	    Double_t        gmc_int_prob_[37]        ; tree->SetBranchAddress("gmc_int_prob_"         , gmc_int_prob_          );
	    Double_t        gmc_ext_c_sq_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_g_to_e_"  , gmc_ext_c_sq_g_to_e_   );
	    Double_t        gmc_ext_prob_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_prob_g_to_e_"  , gmc_ext_prob_g_to_e_   );
	    Double_t        gmc_ext_c_sq_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_e_to_g_"  , gmc_ext_c_sq_e_to_g_   );
	    Double_t        gmc_ext_prob_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_prob_e_to_g_"  , gmc_ext_prob_e_to_g_   );
	    Double_t        cosTheta_[37]            ; tree->SetBranchAddress("cosTheta_"             , cosTheta_              );

	    TVector3* eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

	        double ext_prob = 
	          (gmc_ext_prob_g_to_e_[0] > gmc_ext_prob_e_to_g_[0]) ?
	          gmc_ext_prob_g_to_e_[0] : gmc_ext_prob_e_to_g_[0];

			// Implement selection
			if ( !CheckRunNumber(run) ) continue;
		    if ( sectorId != 18 or IsExcludedSpot(el_vtx_z_, vertexSector)) continue; hAnaCutFlow -> Fill(currentcut++);
			if ( el_trkSign >= 0 )											continue; hAnaCutFlow -> Fill(currentcut++);
			if ( nHighEnergyClusters_ != 1 or gmc_energy_[0] < 0.2)			continue; hAnaCutFlow -> Fill(currentcut++);
		    if ( el_energy_ < 0.3 )                   						continue; hAnaCutFlow -> Fill(currentcut++);
			if ( el_n_neighbours_ != 0 ) 									continue; hAnaCutFlow -> Fill(currentcut++);
			//if ( !(nNAPromptHits_ <=2 and nNADelayedHits_ <=2 and
			//	 nNAPromptHits_near_ == 0 and nNADelayedHits_near_ == 0 and
			//	 gmc_nNAPromptHits_[0] == 0 and gmc_nNADelayedHits_[0] == 0) ) continue; hAnaCutFlow -> Fill(currentcut++);
		    if ( gmc_int_prob_[0] < 0.04 )            						continue; hAnaCutFlow -> Fill(currentcut++);
		    if ( ext_prob > 0.01 ) 			          						continue; hAnaCutFlow -> Fill(currentcut++);
			if ( IsHotSpot(el_vtx_z_, vertexSector) ) 						continue; hAnaCutFlow -> Fill(currentcut++);
			// Apply radon map
		    double weight = 1; 
			std::string name (d->GetName());   
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }
		
			// Fill histogram
	        histo_collection -> Find( TString::Format("%s_h_run"             , d->GetName()) ) -> Fill(run                       , weight);  
	        histo_collection -> Find( TString::Format("%s_h_eventTime"       , d->GetName()) ) -> Fill(eventTime/86400.0         , weight);  
	        histo_collection -> Find( TString::Format("%s_h_sectorId"        , d->GetName()) ) -> Fill(sectorId                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_sourceId"        , d->GetName()) ) -> Fill(sourceId                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_electronEnergy"  , d->GetName()) ) -> Fill(el_energy_                , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackLength"     , d->GetName()) ) -> Fill(el_pathLength_            , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackSign"       , d->GetName()) ) -> Fill(el_trkSign                , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexZ"         , d->GetName()) ) -> Fill(eVertex->z()              , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexSector"    , d->GetName()) ) -> Fill(vertexSector              , weight);
	        histo_collection -> Find( TString::Format("%s_h_gammaEnergy"     , d->GetName()) ) -> Fill(gmc_energy_[0]            , weight);
	        histo_collection -> Find( TString::Format("%s_h_cosTheta"        , d->GetName()) ) -> Fill(cosTheta_[0]              , weight);
	        histo_collection -> Find( TString::Format("%s_h_probInt"         , d->GetName()) ) -> Fill(gmc_int_prob_[0]          , weight);
	        histo_collection -> Find( TString::Format("%s_h_probExt"         , d->GetName()) ) -> Fill(ext_prob                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_gammaLowEnergy"  , d->GetName()) ) -> Fill(totELowEnergyClusters     , weight);          
	        histo_collection -> Find( TString::Format("%s_h_nLowEnergyGamma" , d->GetName()) ) -> Fill(nLowEnergyClusters        , weight);
			
	        histo_collection -> Find( TString::Format("%s_h_layer_vs_side"   , d->GetName()) ) -> Fill(foilSide, trueVertexLayer);

			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);

			//if( IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			if( IsWarmSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			else if( IsColdSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);


		    if (run < 3396) {
					
				histo_collection->Find(TString::Format("%s_h_tot_energy_P1" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				histo_collection->Find(TString::Format("%s_h_e_energy_P1"   , d->GetName()) ) -> Fill(el_energy_, weight);
				histo_collection->Find(TString::Format("%s_h_g_energy_P1"   , d->GetName()) ) -> Fill(gmc_energy_[0], weight);
				
				//else if( IsHotSpot(el_vtx_z_, vertexSector) )
				//	histo_collection->Find(TString::Format("%s_h_tot_energy_P1_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				if( IsWarmSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_tot_energy_P1_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				else if( IsColdSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_tot_energy_P1_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

			} else{ 
				
				histo_collection->Find(TString::Format("%s_h_tot_energy_P2"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				histo_collection->Find(TString::Format("%s_h_e_energy_P2"   , d->GetName()) ) -> Fill(el_energy_, weight);
				histo_collection->Find(TString::Format("%s_h_g_energy_P2"   , d->GetName()) ) -> Fill(gmc_energy_[0], weight);
				
				//else if( IsHotSpot(el_vtx_z_, vertexSector) )
				//	histo_collection->Find(TString::Format("%s_h_tot_energy_P2_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				if( IsWarmSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_tot_energy_P2_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				else if( IsColdSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_tot_energy_P2_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

			}

		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;
	}		
		
	//////////////////////////////////////////////////////////////////////////////				
	//
	// Process one electron two gamma internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 14/11/2014
	//		
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronTwoGammaInternal( DataSet *d ){

		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
	    cutNames->push_back("Cd-116 sector (18) ");
		cutNames->push_back("Negative track sign ");
	    cutNames->push_back("Two gamma cluster with energy > 200 keV ");
	    cutNames->push_back("Energy of the electron > 300 keV ");
		cutNames->push_back("The electron hit isolated block");
	    cutNames->push_back("Internal Probability > 0.04");
	    cutNames->push_back("External Probability < 0.01");
	    //cutNames->push_back("E_e > 4.0 MeV - 1.5 * Sum E_gamma");
		cutNames->push_back("Not an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_run"                   , d->GetName()) , "; Run; No. Events"  , 200, 1000, 9500							         ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_eventTime"             , d->GetName()) , "; Time since 15^{th} Feb 2013 / s; No.Events", 200, 0, 250e6/86400		 ) );					
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sectorId"              , d->GetName()) , "; Sector; No. Events",  21, -0.5, 20.5							         ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sourceId"              , d->GetName()) , "; Source; No. Events",   4, -1.5, 2.5							         ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy"        , d->GetName()) , "; E_{e} / MeV; No.Events / 0.05 MeV", 100, 0, 5						     ) );	                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackLength"           , d->GetName()) , "; Track Length / cm; No.Events / cm", 200, 0, 200						 ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_trackSign"             , d->GetName()) , "; Sign; No.Events", 5, -2.5, 2.5                                          ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexZ"               , d->GetName()) , "; Z / cm ; No.Events / 0.5 cm", 260, -130, 130							 ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexSector"          , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19							         ) );                        
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minGammaEnergy"        , d->GetName()) , "; Min E(#gamma) / MeV; No.Events/0.1 MeV", 50, 0, 5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxGammaEnergy"        , d->GetName()) , "; Max E(#gamma) / MeV; No.Events/0.1 MeV", 50, 0, 5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_cosTheta"         , d->GetName()) , "; Cos(#Theta) e - #gamma_{min}; No.Events", 12, -1, 1                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_probInt"          , d->GetName()) , "; Int. Prob. e - #gamma_{min}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_probExt"          , d->GetName()) , "; Ext. Prob. e - #gamma_{min}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_cosTheta"         , d->GetName()) , "; Cos(#Theta) e - #gamma_{max} ;No.Events", 12, -1, 1                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_probInt"          , d->GetName()) , "; Int. Prob. e - #gamma_{max}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_probExt"          , d->GetName()) , "; Ext. Prob. e - #gamma_{max}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_energy_corr"           , d->GetName()) , "; Min E_#gamma + Max E_#gamma / MeV - E_e / Mev",  40, 0, 4, 20, 0, 2     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_energy_score_fun"      , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_energy_score_vs_tot"   , d->GetName()) , "; Score function; No. Events",  50, 0, 5, 50, -5, 5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_energy_before"         , d->GetName()) , "Before Cut on Correlation; Tot Energy / MeV; No.Events / 0.1",  50, 0, 50 ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_energy_after"          , d->GetName()) , "After Cut on Correlation; Tot Energy / MeV; No.Events / 0.1",  50, 0, 5   ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_layer_vs_side"         , d->GetName()) , "Layer vs Side; Side; Layer", 4, -1.5, 2.5, 10, -0.5, 9.5				     ) );
		
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"         , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130       	 ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_hot"     , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_warm"    , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_cold"    , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
		
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P1" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1"       , d->GetName()) , "; E_{#gamma,Low} + E_{#gamma,High}+ E_{e}; No. Events / 0.1 MeV",  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P1"         , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"           ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_glow_energy_P1"      , d->GetName()) , "; E_{#gamma,Low}; No. Events / 0.1 MeV"  ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_ghigh_energy_P1"     , d->GetName()) , "; E_{#gamma,High}; No. Events / 0.1 MeV" ,  60, 0, 6  ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P1_hot"  , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P1_warm" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P1_cold" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P2" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2"       , d->GetName()) , "; E_{#gamma,Low} + E_{#gamma,High}+ E_{e}; No. Events / 0.1 MeV",  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P2"         , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"           ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_glow_energy_P2"      , d->GetName()) , "; E_{#gamma,Low}; No. Events / 0.1 MeV"  ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_ghigh_energy_P2"     , d->GetName()) , "; E_{#gamma,High}; No. Events / 0.1 MeV" ,  60, 0, 6  ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P2_hot"  , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P2_warm" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_energy_score_fun_P2_cold" , d->GetName()) , "; Score function; No. Events",  50, -5, 5                                 ) );

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t           run                      ; tree->SetBranchAddress("run"                   , &run                   );
	    Int_t           event                    ; tree->SetBranchAddress("event"                 , &event                 );
	    Int_t           timeStampSec             ; tree->SetBranchAddress("timeStampSec"          , &timeStampSec          );
	    Int_t           timeStampNanoS           ; tree->SetBranchAddress("timeStampNanoS"        , &timeStampNanoS        );
	    Double_t        eventTime                ; tree->SetBranchAddress("eventTime"             , &eventTime             );
	    Double_t        radonWeight              ; tree->SetBranchAddress("radonWeight"           , &radonWeight           );
	    Double_t        bi210Weight              ; tree->SetBranchAddress("bi210Weight"           , &bi210Weight           );
	    Double_t        sfoilRadonWeight         ; tree->SetBranchAddress("sfoilRadonWeight"      , &sfoilRadonWeight      );
	    Int_t           foilSide                 ; tree->SetBranchAddress("foilSide"              , &foilSide              );
	    Int_t           sectorId                 ; tree->SetBranchAddress("sectorId"              , &sectorId              );
	    Int_t           sourceId                 ; tree->SetBranchAddress("sourceId"              , &sourceId              );
	    Int_t           isInHotSpot              ; tree->SetBranchAddress("isInHotSpot"           , &isInHotSpot           );
	    Double_t        vertexSector             ; tree->SetBranchAddress("vertexSector"          , &vertexSector          );
	    Int_t           nCaloHits                ; tree->SetBranchAddress("nCaloHits"             , &nCaloHits             );
	    Int_t           nRawCaloHits             ; tree->SetBranchAddress("nRawCaloHits"          , &nRawCaloHits          );
	    Double_t        el_energy_               ; tree->SetBranchAddress("el_energy_"            , &el_energy_            );
	    Int_t           el_side_                 ; tree->SetBranchAddress("el_side_"              , &el_side_              );
	    Double_t        el_dEnergy_              ; tree->SetBranchAddress("el_dEnergy_"           , &el_dEnergy_           );
	    Double_t        el_beta_                 ; tree->SetBranchAddress("el_beta_"              , &el_beta_              );
	    Double_t        el_dBeta_                ; tree->SetBranchAddress("el_dBeta_"             , &el_dBeta_             );
	    Double_t        el_pathLength_           ; tree->SetBranchAddress("el_pathLength_"        , &el_pathLength_        );
	    Double_t        el_energyLoss_           ; tree->SetBranchAddress("el_energyLoss_"        , &el_energyLoss_        );
	    Double_t        el_measTime_             ; tree->SetBranchAddress("el_measTime_"          , &el_measTime_          );
	    Double_t        el_dMeasTime_            ; tree->SetBranchAddress("el_dMeasTime_"         , &el_dMeasTime_         );
	    Double_t        el_thTof_                ; tree->SetBranchAddress("el_thTof_"             , &el_thTof_             );
	    Double_t        el_dThTof_               ; tree->SetBranchAddress("el_dThTof_"            , &el_dThTof_            );
	    Int_t           el_caloiobt              ; tree->SetBranchAddress("el_caloiobt"           , &el_caloiobt           );
	    Int_t           el_calofcll              ; tree->SetBranchAddress("el_calofcll"           , &el_calofcll           );
	    Int_t           el_caloHsFlag_           ; tree->SetBranchAddress("el_caloHsFlag_"        , &el_caloHsFlag_        );
	    Double_t        el_trkSign               ; tree->SetBranchAddress("el_trkSign"            , &el_trkSign            );
	    Double_t        el_tdc_count             ; tree->SetBranchAddress("el_tdc_count"          , &el_tdc_count          );
	    Double_t        el_min_xy_dist_          ; tree->SetBranchAddress("el_min_xy_dist_"       , &el_min_xy_dist_       );
	    Double_t        el_min_z_dist_           ; tree->SetBranchAddress("el_min_z_dist_"        , &el_min_z_dist_        );
	    Double_t        el_vtx_x_                ; tree->SetBranchAddress("el_vtx_x_"             , &el_vtx_x_             );
	    Double_t        el_vtx_y_                ; tree->SetBranchAddress("el_vtx_y_"             , &el_vtx_y_             );
	    Double_t        el_vtx_z_                ; tree->SetBranchAddress("el_vtx_z_"             , &el_vtx_z_             );
	    Double_t        el_ip_x_                 ; tree->SetBranchAddress("el_ip_x_"              , &el_ip_x_              );
	    Double_t        el_ip_y_                 ; tree->SetBranchAddress("el_ip_y_"              , &el_ip_y_              );
	    Double_t        el_ip_z_                 ; tree->SetBranchAddress("el_ip_z_"              , &el_ip_z_              );
	    Int_t           el_first_hit_layer_      ; tree->SetBranchAddress("el_first_hit_layer_"   , &el_first_hit_layer_   );
	    Int_t           el_secnd_hit_layer_      ; tree->SetBranchAddress("el_secnd_hit_layer_"   , &el_secnd_hit_layer_   );
	    Int_t           el_last_hit_layer_       ; tree->SetBranchAddress("el_last_hit_layer_"    , &el_last_hit_layer_    );
	    Int_t           el_nxt_last_hit_layer_   ; tree->SetBranchAddress("el_nxt_last_hit_layer_", &el_nxt_last_hit_layer_);
	    Int_t           el_n_neighbours_         ; tree->SetBranchAddress("el_n_neighbours_"      , &el_n_neighbours_      );
	    Double_t        trueVertexSector         ; tree->SetBranchAddress("trueVertexSector"      , &trueVertexSector      );
	    Int_t           trueVertexLayer          ; tree->SetBranchAddress("trueVertexLayer"       , &trueVertexLayer       );
	    Double_t        trueSectorId             ; tree->SetBranchAddress("trueSectorId"          , &trueSectorId          );
	    Double_t        trueSourceId             ; tree->SetBranchAddress("trueSourceId"          , &trueSourceId          );
	    Int_t           nLowEnergyClusters       ; tree->SetBranchAddress("nLowEnergyClusters"    , &nLowEnergyClusters    );
	    Double_t        totELowEnergyClusters    ; tree->SetBranchAddress("totELowEnergyClusters" , &totELowEnergyClusters );
		Int_t           nNAPromptHits_           ; tree->SetBranchAddress("nNAPromptHits_"        , &nNAPromptHits_        );
		Int_t           nNADelayedHits_          ; tree->SetBranchAddress("nNADelayedHits_"       , &nNADelayedHits_       );
		Int_t           nNANoiseHits_            ; tree->SetBranchAddress("nNANoiseHits_"         , &nNANoiseHits_         );				
		Int_t           nNAPromptHits_near_      ; tree->SetBranchAddress("nNAPromptHits_near_"   , &nNAPromptHits_near_   );
		Int_t           nNADelayedHits_near_     ; tree->SetBranchAddress("nNADelayedHits_near_"  , &nNADelayedHits_near_  );
		Int_t           nNANoiseHits_near_       ; tree->SetBranchAddress("nNANoiseHits_near_"    , &nNANoiseHits_near_    );				
	    Int_t           nClusters_               ; tree->SetBranchAddress("nClusters_"            , &nClusters_            );
	    Int_t           nHighEnergyClusters_     ; tree->SetBranchAddress("nHighEnergyClusters_"  , &nHighEnergyClusters_  );
	    Int_t           gmc_nGammas_[37]         ; tree->SetBranchAddress("gmc_nGammas_"          , gmc_nGammas_           );
	    Double_t        gmc_energy_[37]          ; tree->SetBranchAddress("gmc_energy_"           , gmc_energy_            );
	    Double_t        gmc_dEnergy_[37]         ; tree->SetBranchAddress("gmc_dEnergy_"          , gmc_dEnergy_           );
	    Double_t        gmc_timeSpan_[37]        ; tree->SetBranchAddress("gmc_timeSpan_"         , gmc_timeSpan_          );
	    Double_t        gmc_clusterProb_[37]     ; tree->SetBranchAddress("gmc_clusterProb_"      , gmc_clusterProb_       );
	    Double_t        gmc_measTime_[37]        ; tree->SetBranchAddress("gmc_measTime_"         , gmc_measTime_          );
	    Double_t        gmc_dMeasTime_[37]       ; tree->SetBranchAddress("gmc_dMeasTime_"        , gmc_dMeasTime_         );
	    Double_t        gmc_hitPosition_x_[37]   ; tree->SetBranchAddress("gmc_hitPosition_x_"    , gmc_hitPosition_x_     );
	    Double_t        gmc_hitPosition_y_[37]   ; tree->SetBranchAddress("gmc_hitPosition_y_"    , gmc_hitPosition_y_     );
	    Double_t        gmc_hitPosition_z_[37]   ; tree->SetBranchAddress("gmc_hitPosition_z_"    , gmc_hitPosition_z_     );
	    Double_t        gmc_scintToPMTTime_[37]  ; tree->SetBranchAddress("gmc_scintToPMTTime_"   , gmc_scintToPMTTime_    );
	    Double_t        gmc_dPathLength_[37]     ; tree->SetBranchAddress("gmc_dPathLength_"      , gmc_dPathLength_       );
	    Int_t           gmc_iobt_[37]            ; tree->SetBranchAddress("gmc_iobt_"             , gmc_iobt_              );
	    Int_t           gmc_fcll_[37]            ; tree->SetBranchAddress("gmc_fcll_"             , gmc_fcll_              );
	    Int_t           gmc_clusterId_[37]       ; tree->SetBranchAddress("gmc_clusterId_"        , gmc_clusterId_         );
	    Bool_t          gmc_goodPMTStatuses_[37] ; tree->SetBranchAddress("gmc_goodPMTStatuses_"  , gmc_goodPMTStatuses_   );
	    Bool_t          gmc_goodLDFlags_[37]     ; tree->SetBranchAddress("gmc_goodLDFlags_"      , gmc_goodLDFlags_       );
	    Bool_t          gmc_hasLDCorrs_[37]      ; tree->SetBranchAddress("gmc_hasLDCorrs_"       , gmc_hasLDCorrs_        );
	    Bool_t          gmc_hasLDCorrErrs_[37]   ; tree->SetBranchAddress("gmc_hasLDCorrErrs_"    , gmc_hasLDCorrErrs_     );
	    Bool_t          gmc_goodHSFlags_[37]     ; tree->SetBranchAddress("gmc_goodHSFlags_"      , gmc_goodHSFlags_       );
	    Int_t           gmc_numNeighbours_[37]   ; tree->SetBranchAddress("gmc_numNeighbours_"    , gmc_numNeighbours_     );
		Int_t           gmc_nNAPromptHits_[37]   ; tree->SetBranchAddress("gmc_nNAPromptHits_"    , gmc_nNAPromptHits_     );
		Int_t           gmc_nNADelayedHits_[37]  ; tree->SetBranchAddress("gmc_nNADelayedHits_"   , gmc_nNADelayedHits_    );
		Int_t           gmc_nNANoiseHits_[37]    ; tree->SetBranchAddress("gmc_nNANoiseHits_"     , gmc_nNANoiseHits_      );
	    Double_t        gmc_first_g_time_[37]    ; tree->SetBranchAddress("gmc_first_g_time_"     , gmc_first_g_time_      );
	    Double_t        gmc_first_g_d_time_[37]  ; tree->SetBranchAddress("gmc_first_g_d_time_"   , gmc_first_g_d_time_    );
	    Double_t        gmc_first_g_x_[37]       ; tree->SetBranchAddress("gmc_first_g_x_"        , gmc_first_g_x_         );
	    Double_t        gmc_first_g_y_[37]       ; tree->SetBranchAddress("gmc_first_g_y_"        , gmc_first_g_y_         );
	    Double_t        gmc_first_g_z_[37]       ; tree->SetBranchAddress("gmc_first_g_z_"        , gmc_first_g_z_         );
	    Double_t        gmc_g_th_time_[37]       ; tree->SetBranchAddress("gmc_g_th_time_"        , gmc_g_th_time_         );
	    Double_t        gmc_g_d_th_time_[37]     ; tree->SetBranchAddress("gmc_g_d_th_time_"      , gmc_g_d_th_time_       );
	    Double_t        gmc_int_c_sq_[37]        ; tree->SetBranchAddress("gmc_int_c_sq_"         , gmc_int_c_sq_          );
	    Double_t        gmc_int_prob_[37]        ; tree->SetBranchAddress("gmc_int_prob_"         , gmc_int_prob_          );
	    Double_t        gmc_ext_c_sq_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_g_to_e_"  , gmc_ext_c_sq_g_to_e_   );
	    Double_t        gmc_ext_prob_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_prob_g_to_e_"  , gmc_ext_prob_g_to_e_   );
	    Double_t        gmc_ext_c_sq_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_e_to_g_"  , gmc_ext_c_sq_e_to_g_   );
	    Double_t        gmc_ext_prob_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_prob_e_to_g_"  , gmc_ext_prob_e_to_g_   );
	    Double_t        cosTheta_[37]            ; tree->SetBranchAddress("cosTheta_"             , cosTheta_              );
		
	    TVector3* eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);
			if ( !CheckRunNumber(run) ) continue;
	        if ( sectorId != 18 or IsExcludedSpot(el_vtx_z_, vertexSector)) continue; hAnaCutFlow->Fill(currentcut++);
			if ( el_trkSign >=0 ) 											continue; hAnaCutFlow->Fill(currentcut++);
	        if ( nHighEnergyClusters_ != 2 or
				 gmc_energy_[0] < 0.2 or gmc_energy_[1] < 0.2 )             continue; hAnaCutFlow->Fill(currentcut++);
	        if ( isInHotSpot)                                            	continue; hAnaCutFlow->Fill(currentcut++);
	        if ( el_energy_   < 0.3)                                     	continue; hAnaCutFlow->Fill(currentcut++);
			if ( el_n_neighbours_ != 0 ) 									continue; hAnaCutFlow->Fill(currentcut++);
			//if ( !(nNAPromptHits_ <=2 and nNADelayedHits_ <=2 and
			//	 nNAPromptHits_near_ == 0 and nNADelayedHits_near_ == 0 and
			//	 gmc_nNAPromptHits_[0] == 0 and gmc_nNADelayedHits_[0] == 0 and
			//     gmc_nNAPromptHits_[1] == 0 and gmc_nNADelayedHits_[1] == 0)) continue; hAnaCutFlow -> Fill(currentcut++);
			if ( !(gmc_int_prob_[0] > 0.04 and gmc_int_prob_[1] > 0.04)) 	continue; hAnaCutFlow->Fill(currentcut++);
	        if (
	          !((gmc_ext_prob_g_to_e_[0] < 0.01 and gmc_ext_prob_e_to_g_[0] < 0.01) and 
	            (gmc_ext_prob_g_to_e_[1] < 0.01 and gmc_ext_prob_e_to_g_[1] < 0.01)
	            )
	          )                                                          continue; hAnaCutFlow->Fill(currentcut++);
      	  	//if ( score_function < 0)                                     continue; hAnaCutFlow->Fill(currentcut++);
			if( IsHotSpot(el_vtx_z_, vertexSector) )					continue; hAnaCutFlow->Fill(currentcut++);
			
	        // Identify high and low energy gamma and calculate the score function
	        int high_id, low_id;
	        if (gmc_energy_[0] > gmc_energy_[1]) {
	          high_id = 0; low_id = 1;
	        } else {
	          high_id = 1; low_id = 0;
	        }

	        double ext_prob[2];
	        for (int i = 0; i < 2; ++i) {
	          ext_prob[i] = (gmc_ext_prob_g_to_e_[i] > gmc_ext_prob_e_to_g_[i]) ?
	                         gmc_ext_prob_g_to_e_[i] : gmc_ext_prob_e_to_g_[i];
	        }

	        double score_function = el_energy_ + 1.5 * (gmc_energy_[0] + gmc_energy_[1]) - 4;
	        double total_energy   = el_energy_ + gmc_energy_[0] + gmc_energy_[1];

			// Apply radon map
		    double weight = 1;
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }

	        histo_collection -> Find( TString::Format("%s_h_run"                 , d->GetName()) ) -> Fill(run                                       , weight);
	        histo_collection -> Find( TString::Format("%s_h_eventTime"           , d->GetName()) ) -> Fill(eventTime/86400.0                         , weight);  
	        histo_collection -> Find( TString::Format("%s_h_sectorId"            , d->GetName()) ) -> Fill(sectorId                                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_sourceId"            , d->GetName()) ) -> Fill(sourceId                                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_electronEnergy"      , d->GetName()) ) -> Fill(el_energy_                                , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackLength"         , d->GetName()) ) -> Fill(el_pathLength_                            , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackSign"           , d->GetName()) ) -> Fill(el_trkSign                                , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexZ"             , d->GetName()) ) -> Fill(eVertex->z()                              , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexSector"        , d->GetName()) ) -> Fill(vertexSector                              , weight);
	        histo_collection -> Find( TString::Format("%s_h_minGammaEnergy"      , d->GetName()) ) -> Fill(gmc_energy_[low_id]                       , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxGammaEnergy"      , d->GetName()) ) -> Fill(gmc_energy_[high_id]                      , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_cosTheta"       , d->GetName()) ) -> Fill(cosTheta_[low_id]                         , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_probInt"        , d->GetName()) ) -> Fill(gmc_int_prob_[low_id]                     , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_probExt"        , d->GetName()) ) -> Fill(ext_prob[low_id]                          , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_cosTheta"       , d->GetName()) ) -> Fill(cosTheta_[high_id]                        , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_probInt"        , d->GetName()) ) -> Fill(gmc_int_prob_[high_id]                    , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_probExt"        , d->GetName()) ) -> Fill(ext_prob[high_id]                         , weight);
	        histo_collection -> Find( TString::Format("%s_h_energy_score_fun"    , d->GetName()) ) -> Fill(score_function                            , weight);
	        histo_collection -> Find( TString::Format("%s_h_energy_before"       , d->GetName()) ) -> Fill(total_energy                              , weight);

			histo_collection -> Find( TString::Format("%s_h_energy_corr"         , d->GetName()) ) -> Fill(gmc_energy_[0]+gmc_energy_[1] , el_energy_      );	        
	        histo_collection -> Find( TString::Format("%s_h_energy_score_vs_tot" , d->GetName()) ) -> Fill(total_energy                  , score_function  );
			histo_collection -> Find( TString::Format("%s_h_layer_vs_side"       , d->GetName()) ) -> Fill(foilSide                      , trueVertexLayer );
 
			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);

			//if( IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			if( IsWarmSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			else if( IsColdSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
 		   
 
 		    if (run < 3396) {

				histo_collection -> Find( TString::Format("%s_h_energy_score_fun_P1" , d->GetName()) ) -> Fill(score_function);
				histo_collection -> Find( TString::Format("%s_h_tot_energy_P1"       , d->GetName()) ) -> Fill(total_energy);
				histo_collection -> Find( TString::Format("%s_h_e_energy_P1"         , d->GetName()) ) -> Fill(el_energy_);
				histo_collection -> Find( TString::Format("%s_h_glow_energy_P1"      , d->GetName()) ) -> Fill(gmc_energy_[low_id]);
				histo_collection -> Find( TString::Format("%s_h_ghigh_energy_P1"     , d->GetName()) ) -> Fill(gmc_energy_[high_id]);				
								
				//if( IsHotSpot(el_vtx_z_, vertexSector) )
				//	histo_collection->Find(TString::Format("%s_h_energy_score_fun_P1_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				if( IsWarmSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_energy_score_fun_P1_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				else if( IsColdSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_energy_score_fun_P1_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);


			} else {

				histo_collection -> Find( TString::Format("%s_h_energy_score_fun_P2"  , d->GetName()) ) -> Fill( score_function);
				histo_collection -> Find( TString::Format("%s_h_tot_energy_P2"       , d->GetName()) ) -> Fill(total_energy);
				histo_collection -> Find( TString::Format("%s_h_e_energy_P2"         , d->GetName()) ) -> Fill(el_energy_);
				histo_collection -> Find( TString::Format("%s_h_glow_energy_P2"      , d->GetName()) ) -> Fill(gmc_energy_[low_id]);
				histo_collection -> Find( TString::Format("%s_h_ghigh_energy_P2"     , d->GetName()) ) -> Fill(gmc_energy_[high_id]);				

				//if( IsHotSpot(el_vtx_z_, vertexSector) )
				//	histo_collection->Find(TString::Format("%s_h_energy_score_fun_P2_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				if( IsWarmSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_energy_score_fun_P2_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				else if( IsColdSpot(el_vtx_z_, vertexSector) )
					histo_collection->Find(TString::Format("%s_h_energy_score_fun_P2_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

			}
			
		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;

	}		

	//////////////////////////////////////////////////////////////////////////////				
	//
	// Process one electron three gamma internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 29/01/2015
	//		
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronThreeGammaInternal( DataSet *d ){

		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
	    cutNames->push_back("Cd-116 sector (18) ");
		cutNames->push_back("Negative track sign ");
	    cutNames->push_back("Three gamma cluster with energy > 200 keV");
	    //cutNames->push_back("Energy of the gamma > 200 keV ");
	    cutNames->push_back("Energy of the electron > 300 keV ");
		cutNames->push_back("The electron hit isolated block");
	    cutNames->push_back("Internal Probability > 0.04");
	    cutNames->push_back("External Probability < 0.01");
	    //cutNames->push_back("E_e > 4.0 MeV - 1.5 * Sum E_gamma");
		cutNames->push_back("Not an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_run"                   , d->GetName()) , "; Run; No. Events"  , 200, 1000, 9500							         ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_eventTime"             , d->GetName()) , "; Time since 15^{th} Feb 2013 / s; No.Events", 200, 0, 250e6/86400		 ) );					
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sectorId"              , d->GetName()) , "; Sector; No. Events",  21, -0.5, 20.5							         ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sourceId"              , d->GetName()) , "; Source; No. Events",   4, -1.5, 2.5							         ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy"        , d->GetName()) , "; E_{e} / MeV; No.Events / 0.05 MeV", 100, 0, 5						     ) );	                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackLength"           , d->GetName()) , "; Track Length / cm; No.Events / cm", 200, 0, 200						 ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_trackSign"             , d->GetName()) , "; Sign; No.Events", 5, -2.5, 2.5                                          ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexZ"               , d->GetName()) , "; Z / cm ; No.Events / 0.5 cm", 260, -130, 130							 ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexSector"          , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19							         ) );                        
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minGammaEnergy"        , d->GetName()) , "; Min E(#gamma) / MeV; No.Events/0.1 MeV", 50, 0, 5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxGammaEnergy"        , d->GetName()) , "; Max E(#gamma) / MeV; No.Events/0.1 MeV", 50, 0, 5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_cosTheta"         , d->GetName()) , "; Cos(#Theta) e - #gamma_{min}; No.Events", 12, -1, 1                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_probInt"          , d->GetName()) , "; Int. Prob. e - #gamma_{min}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_minE_probExt"          , d->GetName()) , "; Ext. Prob. e - #gamma_{min}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_cosTheta"         , d->GetName()) , "; Cos(#Theta) e - #gamma_{max} ;No.Events", 12, -1, 1                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_probInt"          , d->GetName()) , "; Int. Prob. e - #gamma_{max}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_maxE_probExt"          , d->GetName()) , "; Ext. Prob. e - #gamma_{max}; No.Events",  12, 0, 1                      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_energy_corr"           , d->GetName()) , "; Min E_#gamma + Max E_#gamma / MeV - E_e / Mev",  40, 0, 4, 20, 0, 2     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_energy_before"         , d->GetName()) , "Before Cut on Correlation; Tot Energy / MeV; No.Events / 0.1",  50, 0, 50 ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_energy_after"          , d->GetName()) , "After Cut on Correlation; Tot Energy / MeV; No.Events / 0.1",  50, 0, 5   ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_layer_vs_side"         , d->GetName()) , "Layer vs Side; Side; Layer", 4, -1.5, 2.5, 10, -0.5, 9.5				     ) );
		
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"         , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130       	 ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_hot"     , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_warm"    , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_cold"    , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130            ) );
		
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy"          , d->GetName()) , "; E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy"            , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"           ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1"       , d->GetName()) , "; E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P1"         , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"           ,  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2"       , d->GetName()) , "; E_{#gamma,1} + E_{#gamma,2} + E_{#gamma,3} + E_{e}; No. Events / 0.1 MeV",  60, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P2"         , d->GetName()) , "; E_{e}; No. Events / 0.1 MeV"           ,  60, 0, 6  ) );


		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t           run                      ; tree->SetBranchAddress("run"                   , &run                   );
	    Int_t           event                    ; tree->SetBranchAddress("event"                 , &event                 );
	    Int_t           timeStampSec             ; tree->SetBranchAddress("timeStampSec"          , &timeStampSec          );
	    Int_t           timeStampNanoS           ; tree->SetBranchAddress("timeStampNanoS"        , &timeStampNanoS        );
	    Double_t        eventTime                ; tree->SetBranchAddress("eventTime"             , &eventTime             );
	    Double_t        radonWeight              ; tree->SetBranchAddress("radonWeight"           , &radonWeight           );
	    Double_t        bi210Weight              ; tree->SetBranchAddress("bi210Weight"           , &bi210Weight           );
	    Double_t        sfoilRadonWeight         ; tree->SetBranchAddress("sfoilRadonWeight"      , &sfoilRadonWeight      );
	    Int_t           foilSide                 ; tree->SetBranchAddress("foilSide"              , &foilSide              );
	    Int_t           sectorId                 ; tree->SetBranchAddress("sectorId"              , &sectorId              );
	    Int_t           sourceId                 ; tree->SetBranchAddress("sourceId"              , &sourceId              );
	    Int_t           isInHotSpot              ; tree->SetBranchAddress("isInHotSpot"           , &isInHotSpot           );
	    Double_t        vertexSector             ; tree->SetBranchAddress("vertexSector"          , &vertexSector          );
	    Int_t           nCaloHits                ; tree->SetBranchAddress("nCaloHits"             , &nCaloHits             );
	    Int_t           nRawCaloHits             ; tree->SetBranchAddress("nRawCaloHits"          , &nRawCaloHits          );
	    Double_t        el_energy_               ; tree->SetBranchAddress("el_energy_"            , &el_energy_            );
	    Int_t           el_side_                 ; tree->SetBranchAddress("el_side_"              , &el_side_              );
	    Double_t        el_dEnergy_              ; tree->SetBranchAddress("el_dEnergy_"           , &el_dEnergy_           );
	    Double_t        el_beta_                 ; tree->SetBranchAddress("el_beta_"              , &el_beta_              );
	    Double_t        el_dBeta_                ; tree->SetBranchAddress("el_dBeta_"             , &el_dBeta_             );
	    Double_t        el_pathLength_           ; tree->SetBranchAddress("el_pathLength_"        , &el_pathLength_        );
	    Double_t        el_energyLoss_           ; tree->SetBranchAddress("el_energyLoss_"        , &el_energyLoss_        );
	    Double_t        el_measTime_             ; tree->SetBranchAddress("el_measTime_"          , &el_measTime_          );
	    Double_t        el_dMeasTime_            ; tree->SetBranchAddress("el_dMeasTime_"         , &el_dMeasTime_         );
	    Double_t        el_thTof_                ; tree->SetBranchAddress("el_thTof_"             , &el_thTof_             );
	    Double_t        el_dThTof_               ; tree->SetBranchAddress("el_dThTof_"            , &el_dThTof_            );
	    Int_t           el_caloiobt              ; tree->SetBranchAddress("el_caloiobt"           , &el_caloiobt           );
	    Int_t           el_calofcll              ; tree->SetBranchAddress("el_calofcll"           , &el_calofcll           );
	    Int_t           el_caloHsFlag_           ; tree->SetBranchAddress("el_caloHsFlag_"        , &el_caloHsFlag_        );
	    Double_t        el_trkSign               ; tree->SetBranchAddress("el_trkSign"            , &el_trkSign            );
	    Double_t        el_tdc_count             ; tree->SetBranchAddress("el_tdc_count"          , &el_tdc_count          );
	    Double_t        el_min_xy_dist_          ; tree->SetBranchAddress("el_min_xy_dist_"       , &el_min_xy_dist_       );
	    Double_t        el_min_z_dist_           ; tree->SetBranchAddress("el_min_z_dist_"        , &el_min_z_dist_        );
	    Double_t        el_vtx_x_                ; tree->SetBranchAddress("el_vtx_x_"             , &el_vtx_x_             );
	    Double_t        el_vtx_y_                ; tree->SetBranchAddress("el_vtx_y_"             , &el_vtx_y_             );
	    Double_t        el_vtx_z_                ; tree->SetBranchAddress("el_vtx_z_"             , &el_vtx_z_             );
	    Double_t        el_ip_x_                 ; tree->SetBranchAddress("el_ip_x_"              , &el_ip_x_              );
	    Double_t        el_ip_y_                 ; tree->SetBranchAddress("el_ip_y_"              , &el_ip_y_              );
	    Double_t        el_ip_z_                 ; tree->SetBranchAddress("el_ip_z_"              , &el_ip_z_              );
	    Int_t           el_first_hit_layer_      ; tree->SetBranchAddress("el_first_hit_layer_"   , &el_first_hit_layer_   );
	    Int_t           el_secnd_hit_layer_      ; tree->SetBranchAddress("el_secnd_hit_layer_"   , &el_secnd_hit_layer_   );
	    Int_t           el_last_hit_layer_       ; tree->SetBranchAddress("el_last_hit_layer_"    , &el_last_hit_layer_    );
	    Int_t           el_nxt_last_hit_layer_   ; tree->SetBranchAddress("el_nxt_last_hit_layer_", &el_nxt_last_hit_layer_);
	    Int_t           el_n_neighbours_         ; tree->SetBranchAddress("el_n_neighbours_"      , &el_n_neighbours_      );
	    Double_t        trueVertexSector         ; tree->SetBranchAddress("trueVertexSector"      , &trueVertexSector      );
	    Int_t           trueVertexLayer          ; tree->SetBranchAddress("trueVertexLayer"       , &trueVertexLayer       );
	    Double_t        trueSectorId             ; tree->SetBranchAddress("trueSectorId"          , &trueSectorId          );
	    Double_t        trueSourceId             ; tree->SetBranchAddress("trueSourceId"          , &trueSourceId          );
	    Int_t           nLowEnergyClusters       ; tree->SetBranchAddress("nLowEnergyClusters"    , &nLowEnergyClusters    );
	    Double_t        totELowEnergyClusters    ; tree->SetBranchAddress("totELowEnergyClusters" , &totELowEnergyClusters );
		Int_t           nNAPromptHits_           ; tree->SetBranchAddress("nNAPromptHits_"        , &nNAPromptHits_        );
		Int_t           nNADelayedHits_          ; tree->SetBranchAddress("nNADelayedHits_"       , &nNADelayedHits_       );
		Int_t           nNANoiseHits_            ; tree->SetBranchAddress("nNANoiseHits_"         , &nNANoiseHits_         );				
		Int_t           nNAPromptHits_near_      ; tree->SetBranchAddress("nNAPromptHits_near_"   , &nNAPromptHits_near_   );
		Int_t           nNADelayedHits_near_     ; tree->SetBranchAddress("nNADelayedHits_near_"  , &nNADelayedHits_near_  );
		Int_t           nNANoiseHits_near_       ; tree->SetBranchAddress("nNANoiseHits_near_"    , &nNANoiseHits_near_    );				
	    Int_t           nClusters_               ; tree->SetBranchAddress("nClusters_"            , &nClusters_            );
	    Int_t           nHighEnergyClusters_     ; tree->SetBranchAddress("nHighEnergyClusters_"  , &nHighEnergyClusters_  );
	    Int_t           gmc_nGammas_[37]         ; tree->SetBranchAddress("gmc_nGammas_"          , gmc_nGammas_           );
	    Double_t        gmc_energy_[37]          ; tree->SetBranchAddress("gmc_energy_"           , gmc_energy_            );
	    Double_t        gmc_dEnergy_[37]         ; tree->SetBranchAddress("gmc_dEnergy_"          , gmc_dEnergy_           );
	    Double_t        gmc_timeSpan_[37]        ; tree->SetBranchAddress("gmc_timeSpan_"         , gmc_timeSpan_          );
	    Double_t        gmc_clusterProb_[37]     ; tree->SetBranchAddress("gmc_clusterProb_"      , gmc_clusterProb_       );
	    Double_t        gmc_measTime_[37]        ; tree->SetBranchAddress("gmc_measTime_"         , gmc_measTime_          );
	    Double_t        gmc_dMeasTime_[37]       ; tree->SetBranchAddress("gmc_dMeasTime_"        , gmc_dMeasTime_         );
	    Double_t        gmc_hitPosition_x_[37]   ; tree->SetBranchAddress("gmc_hitPosition_x_"    , gmc_hitPosition_x_     );
	    Double_t        gmc_hitPosition_y_[37]   ; tree->SetBranchAddress("gmc_hitPosition_y_"    , gmc_hitPosition_y_     );
	    Double_t        gmc_hitPosition_z_[37]   ; tree->SetBranchAddress("gmc_hitPosition_z_"    , gmc_hitPosition_z_     );
	    Double_t        gmc_scintToPMTTime_[37]  ; tree->SetBranchAddress("gmc_scintToPMTTime_"   , gmc_scintToPMTTime_    );
	    Double_t        gmc_dPathLength_[37]     ; tree->SetBranchAddress("gmc_dPathLength_"      , gmc_dPathLength_       );
	    Int_t           gmc_iobt_[37]            ; tree->SetBranchAddress("gmc_iobt_"             , gmc_iobt_              );
	    Int_t           gmc_fcll_[37]            ; tree->SetBranchAddress("gmc_fcll_"             , gmc_fcll_              );
	    Int_t           gmc_clusterId_[37]       ; tree->SetBranchAddress("gmc_clusterId_"        , gmc_clusterId_         );
	    Bool_t          gmc_goodPMTStatuses_[37] ; tree->SetBranchAddress("gmc_goodPMTStatuses_"  , gmc_goodPMTStatuses_   );
	    Bool_t          gmc_goodLDFlags_[37]     ; tree->SetBranchAddress("gmc_goodLDFlags_"      , gmc_goodLDFlags_       );
	    Bool_t          gmc_hasLDCorrs_[37]      ; tree->SetBranchAddress("gmc_hasLDCorrs_"       , gmc_hasLDCorrs_        );
	    Bool_t          gmc_hasLDCorrErrs_[37]   ; tree->SetBranchAddress("gmc_hasLDCorrErrs_"    , gmc_hasLDCorrErrs_     );
	    Bool_t          gmc_goodHSFlags_[37]     ; tree->SetBranchAddress("gmc_goodHSFlags_"      , gmc_goodHSFlags_       );
	    Int_t           gmc_numNeighbours_[37]   ; tree->SetBranchAddress("gmc_numNeighbours_"    , gmc_numNeighbours_     );
		Int_t           gmc_nNAPromptHits_[37]   ; tree->SetBranchAddress("gmc_nNAPromptHits_"    , gmc_nNAPromptHits_     );
		Int_t           gmc_nNADelayedHits_[37]  ; tree->SetBranchAddress("gmc_nNADelayedHits_"   , gmc_nNADelayedHits_    );
		Int_t           gmc_nNANoiseHits_[37]    ; tree->SetBranchAddress("gmc_nNANoiseHits_"     , gmc_nNANoiseHits_      );
	    Double_t        gmc_first_g_time_[37]    ; tree->SetBranchAddress("gmc_first_g_time_"     , gmc_first_g_time_      );
	    Double_t        gmc_first_g_d_time_[37]  ; tree->SetBranchAddress("gmc_first_g_d_time_"   , gmc_first_g_d_time_    );
	    Double_t        gmc_first_g_x_[37]       ; tree->SetBranchAddress("gmc_first_g_x_"        , gmc_first_g_x_         );
	    Double_t        gmc_first_g_y_[37]       ; tree->SetBranchAddress("gmc_first_g_y_"        , gmc_first_g_y_         );
	    Double_t        gmc_first_g_z_[37]       ; tree->SetBranchAddress("gmc_first_g_z_"        , gmc_first_g_z_         );
	    Double_t        gmc_g_th_time_[37]       ; tree->SetBranchAddress("gmc_g_th_time_"        , gmc_g_th_time_         );
	    Double_t        gmc_g_d_th_time_[37]     ; tree->SetBranchAddress("gmc_g_d_th_time_"      , gmc_g_d_th_time_       );
	    Double_t        gmc_int_c_sq_[37]        ; tree->SetBranchAddress("gmc_int_c_sq_"         , gmc_int_c_sq_          );
	    Double_t        gmc_int_prob_[37]        ; tree->SetBranchAddress("gmc_int_prob_"         , gmc_int_prob_          );
	    Double_t        gmc_ext_c_sq_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_g_to_e_"  , gmc_ext_c_sq_g_to_e_   );
	    Double_t        gmc_ext_prob_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_prob_g_to_e_"  , gmc_ext_prob_g_to_e_   );
	    Double_t        gmc_ext_c_sq_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_e_to_g_"  , gmc_ext_c_sq_e_to_g_   );
	    Double_t        gmc_ext_prob_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_prob_e_to_g_"  , gmc_ext_prob_e_to_g_   );
	    Double_t        cosTheta_[37]            ; tree->SetBranchAddress("cosTheta_"             , cosTheta_              );
		
	    TVector3* eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);
			if ( !CheckRunNumber(run) ) continue;
	        if ( sectorId != 18 || IsExcludedSpot(el_vtx_z_, vertexSector)) continue; hAnaCutFlow->Fill(currentcut++);
			if ( el_trkSign >=0 ) 											continue; hAnaCutFlow->Fill(currentcut++);
	        if ( nHighEnergyClusters_ != 3  or gmc_energy_[0] < 0.2 or 
				gmc_energy_[1] < 0.2  or gmc_energy_[2] < 0.2)              continue; hAnaCutFlow->Fill(currentcut++);
	        if ( isInHotSpot)                                            	continue; hAnaCutFlow->Fill(currentcut++);
	        if ( el_energy_   < 0.3)                                     	continue; hAnaCutFlow->Fill(currentcut++);
			if ( el_n_neighbours_ != 0 ) 									continue; hAnaCutFlow -> Fill(currentcut++);
			//if ( !(nNAPromptHits_ <=2 and nNADelayedHits_ <=2 and
			//	 nNAPromptHits_near_ == 0 and nNADelayedHits_near_ == 0 and
			//	 gmc_nNAPromptHits_[0] == 0 and gmc_nNADelayedHits_[0] == 0 and
			//     gmc_nNAPromptHits_[1] == 0 and gmc_nNADelayedHits_[1] == 0 and
			//	 gmc_nNAPromptHits_[2] == 0 and gmc_nNADelayedHits_[2] == 0) ) continue; hAnaCutFlow -> Fill(currentcut++);
	        if ( !(gmc_int_prob_[0] > 0.04 and gmc_int_prob_[1] > 0.04)) 	continue; hAnaCutFlow->Fill(currentcut++);
	        if (
	          !((gmc_ext_prob_g_to_e_[0] < 0.01 and gmc_ext_prob_e_to_g_[0] < 0.01) and 
	            (gmc_ext_prob_g_to_e_[1] < 0.01 and gmc_ext_prob_e_to_g_[1] < 0.01) and
				(gmc_ext_prob_g_to_e_[2] < 0.01 and gmc_ext_prob_e_to_g_[2] < 0.01)
	            )
	          )                                                          continue; hAnaCutFlow->Fill(currentcut++);
      	  	//if ( score_function < 0)                                   continue; hAnaCutFlow->Fill(currentcut++);
			if( IsHotSpot(el_vtx_z_, vertexSector) )					 continue; hAnaCutFlow->Fill(currentcut++);
			
	        double ext_prob[3];
	        for (int i = 0; i < 3; ++i) {
	          ext_prob[i] = (gmc_ext_prob_g_to_e_[i] > gmc_ext_prob_e_to_g_[i]) ?
	                         gmc_ext_prob_g_to_e_[i] : gmc_ext_prob_e_to_g_[i];
	        }

	        // Identify high and low energy gamma and calculate the score function
	        int high_id, low_id;
			
	        if (gmc_energy_[0] > gmc_energy_[1]) {
	          high_id = 0; low_id = 1;
	        } else {
	          high_id = 1; low_id = 0;
	        } if (gmc_energy_[2] > gmc_energy_[high_id]) {
	        	high_id = 2;
	        } else if (gmc_energy_[2] < gmc_energy_[low_id]) { 
				low_id = 2;
			}

	        //double score_function = el_energy_ + 1.5 * (gmc_energy_[0] + gmc_energy_[1]) - 4;
	        double total_energy   = el_energy_ + gmc_energy_[0] + gmc_energy_[1] + gmc_energy_[2];

			// Apply radon map
		    double weight = 1;
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }

	        histo_collection -> Find( TString::Format("%s_h_run"                 , d->GetName()) ) -> Fill(run                                       , weight);
	        histo_collection -> Find( TString::Format("%s_h_eventTime"           , d->GetName()) ) -> Fill(eventTime/86400.0                         , weight);  
	        histo_collection -> Find( TString::Format("%s_h_sectorId"            , d->GetName()) ) -> Fill(sectorId                                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_sourceId"            , d->GetName()) ) -> Fill(sourceId                                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_electronEnergy"      , d->GetName()) ) -> Fill(el_energy_                                , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackLength"         , d->GetName()) ) -> Fill(el_pathLength_                            , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackSign"           , d->GetName()) ) -> Fill(el_trkSign                                , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexZ"             , d->GetName()) ) -> Fill(eVertex->z()                              , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexSector"        , d->GetName()) ) -> Fill(vertexSector                              , weight);
	        histo_collection -> Find( TString::Format("%s_h_minGammaEnergy"      , d->GetName()) ) -> Fill(gmc_energy_[low_id]                       , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxGammaEnergy"      , d->GetName()) ) -> Fill(gmc_energy_[high_id]                      , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_cosTheta"       , d->GetName()) ) -> Fill(cosTheta_[low_id]                         , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_probInt"        , d->GetName()) ) -> Fill(gmc_int_prob_[low_id]                     , weight);
	        histo_collection -> Find( TString::Format("%s_h_minE_probExt"        , d->GetName()) ) -> Fill(ext_prob[low_id]                          , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_cosTheta"       , d->GetName()) ) -> Fill(cosTheta_[high_id]                        , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_probInt"        , d->GetName()) ) -> Fill(gmc_int_prob_[high_id]                    , weight);
	        histo_collection -> Find( TString::Format("%s_h_maxE_probExt"        , d->GetName()) ) -> Fill(ext_prob[high_id]                         , weight);
	        histo_collection -> Find( TString::Format("%s_h_energy_before"       , d->GetName()) ) -> Fill(total_energy                              , weight);

			histo_collection -> Find( TString::Format("%s_h_energy_corr"         , d->GetName()) ) -> Fill(gmc_energy_[0]+gmc_energy_[1]+gmc_energy_[3] , el_energy_ );	        
			histo_collection -> Find( TString::Format("%s_h_layer_vs_side"       , d->GetName()) ) -> Fill(foilSide                      , trueVertexLayer );
 
			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);

			//if( IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			if( IsWarmSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			else if( IsColdSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
 		   
			// P1 & P2 together
			histo_collection -> Find( TString::Format("%s_h_tot_energy"       , d->GetName()) ) -> Fill(total_energy);
			histo_collection -> Find( TString::Format("%s_h_e_energy"         , d->GetName()) ) -> Fill(el_energy_);
			
			 if (run < 3396) {
	 			histo_collection -> Find( TString::Format("%s_h_tot_energy_P1"       , d->GetName()) ) -> Fill(total_energy);
	 			histo_collection -> Find( TString::Format("%s_h_e_energy_P1"         , d->GetName()) ) -> Fill(el_energy_); 
			 } else {
	 			histo_collection -> Find( TString::Format("%s_h_tot_energy_P2"       , d->GetName()) ) -> Fill(total_energy);
	 			histo_collection -> Find( TString::Format("%s_h_e_energy_P2"         , d->GetName()) ) -> Fill(el_energy_);
			 	
			 }
			
		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;

	}		

	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process one electron one gamma external channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 13/11/2014
	//	
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneGammaExternal( DataSet *d ){
		
		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
		cutNames->push_back("Cd-116 sector (18) ");
		cutNames->push_back("Negative track sign ");
	    cutNames->push_back("One gamma cluster with energy > 150 keV ");
	    cutNames->push_back("Energy one electron > 300 keV ");
	    cutNames->push_back("External Probability > 0.04");
	    cutNames->push_back("Internal Probability < 0.01");
	    cutNames->push_back("Not an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_run"             , d->GetName()) , "; Run; No. Events"  , 200, 1000, 9500							        ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_eventTime"       , d->GetName()) , "; Time since 15^{th} Feb 2013 / s; No.Events", 200, 0, 250e6/86400		) );					
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sectorId"        , d->GetName()) , "; Sector; No. Events",  21, -0.5, 20.5							        ) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sourceId"        , d->GetName()) , "; Source; No. Events",   4, -1.5, 2.5							        ) );                      
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy"  , d->GetName()) , "; E_{e} / MeV; No.Events / 0.05 MeV", 100, 0, 5						) );	                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackLength"     , d->GetName()) , "; Track Length / cm; No.Events / cm", 200, 0, 200						) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_trackSign"       , d->GetName()) , "; Sign; No.Events", 5, -2.5, 2.5                                          ) );	                   
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexZ"         , d->GetName()) , "; Z / cm ; No.Events / 0.5 cm", 260, -130, 130							) );                     
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexSector"    , d->GetName()) , "; Sector Number; No.Events", 100, 18, 19							    ) );                        
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_gammaEnergy"     , d->GetName()) , "; E_{#gamma} / MeV; No.Events / 0.1 MeV", 50, 0, 5						) );	                  
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_cosTheta"        , d->GetName()) , "; Cos(#Theta) e - #gamma_{min}; No.Events", 12, -1, 1					) );		               
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_probInt"         , d->GetName()) , "; Int. Prob. e - #gamma_{min}; No.Events",  12, 0, 1					) );		                
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_probExt"         , d->GetName()) , "; Ext. Prob. e - #gamma_{min}; No.Events",  12, 0, 1					) );		                
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_gammaLowEnergy"  , d->GetName()) , "; E_{#gamma} / MeV; No.Events / 0.02 MeV", 25, 0, 0.5					) );		               
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_nLowEnergyGamma" , d->GetName()) , "; N_{#gamma} low E; No.Events", 20, -0.5, 19.5							) );                     
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_layer_vs_side"   , d->GetName()) , "Layer vs Side; Side; Layer", 4, -1.5, 2.5, 10, -0.5, 9.5				) );			            

	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"      , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130      ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1"     , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P1"       , d->GetName()) , "; E_{e}; No. Events / 0.05 MeV"             ,  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_g_energy_P1"       , d->GetName()) , "; E_{#gamma}; No. Events / 0.05 MeV"        ,  120, 0, 6  ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_In"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Out" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Pet" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6  ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_In_hot"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Out_hot" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Pet_hot" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_In_warm"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Out_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Pet_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_In_cold"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Out_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P1_Pet_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2"     , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_e_energy_P2"       , d->GetName()) , "; E_{e}; No. Events / 0.05 MeV"             ,  120, 0, 6  ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_g_energy_P2"       , d->GetName()) , "; E_{#gamma}; No. Events / 0.05 MeV"        ,  120, 0, 6  ) );
		
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_In"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Out" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Pet" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_In_hot"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Out_hot" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Pet_hot" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_In_warm"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Out_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Pet_warm" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_In_cold"  , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Out_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );
		histo_collection -> Add( new TH1D ( TString::Format("%s_h_tot_energy_P2_Pet_cold" , d->GetName()) , "; E_{#gamma} + E_{e}; No. Events / 0.05 MeV",  120, 0, 6            ) );

		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t           run                      ; tree->SetBranchAddress("run"                   , &run                   );
	    Int_t           event                    ; tree->SetBranchAddress("event"                 , &event                 );
	    Int_t           timeStampSec             ; tree->SetBranchAddress("timeStampSec"          , &timeStampSec          );
	    Int_t           timeStampNanoS           ; tree->SetBranchAddress("timeStampNanoS"        , &timeStampNanoS        );
	    Double_t        eventTime                ; tree->SetBranchAddress("eventTime"             , &eventTime             );
	    Double_t        radonWeight              ; tree->SetBranchAddress("radonWeight"           , &radonWeight           );
	    Double_t        bi210Weight              ; tree->SetBranchAddress("bi210Weight"           , &bi210Weight           );
	    Double_t        sfoilRadonWeight         ; tree->SetBranchAddress("sfoilRadonWeight"      , &sfoilRadonWeight      );
	    Int_t           foilSide                 ; tree->SetBranchAddress("foilSide"              , &foilSide              );
	    Int_t           sectorId                 ; tree->SetBranchAddress("sectorId"              , &sectorId              );
	    Int_t           sourceId                 ; tree->SetBranchAddress("sourceId"              , &sourceId              );
	    Int_t           isInHotSpot              ; tree->SetBranchAddress("isInHotSpot"           , &isInHotSpot           );
	    Double_t        vertexSector             ; tree->SetBranchAddress("vertexSector"          , &vertexSector          );
	    Int_t           nCaloHits                ; tree->SetBranchAddress("nCaloHits"             , &nCaloHits             );
	    Int_t           nRawCaloHits             ; tree->SetBranchAddress("nRawCaloHits"          , &nRawCaloHits          );
	    Double_t        el_energy_               ; tree->SetBranchAddress("el_energy_"            , &el_energy_            );
	    Int_t           el_side_                 ; tree->SetBranchAddress("el_side_"              , &el_side_              );
	    Double_t        el_dEnergy_              ; tree->SetBranchAddress("el_dEnergy_"           , &el_dEnergy_           );
	    Double_t        el_beta_                 ; tree->SetBranchAddress("el_beta_"              , &el_beta_              );
	    Double_t        el_dBeta_                ; tree->SetBranchAddress("el_dBeta_"             , &el_dBeta_             );
	    Double_t        el_pathLength_           ; tree->SetBranchAddress("el_pathLength_"        , &el_pathLength_        );
	    Double_t        el_energyLoss_           ; tree->SetBranchAddress("el_energyLoss_"        , &el_energyLoss_        );
	    Double_t        el_measTime_             ; tree->SetBranchAddress("el_measTime_"          , &el_measTime_          );
	    Double_t        el_dMeasTime_            ; tree->SetBranchAddress("el_dMeasTime_"         , &el_dMeasTime_         );
	    Double_t        el_thTof_                ; tree->SetBranchAddress("el_thTof_"             , &el_thTof_             );
	    Double_t        el_dThTof_               ; tree->SetBranchAddress("el_dThTof_"            , &el_dThTof_            );
	    Int_t           el_caloiobt              ; tree->SetBranchAddress("el_caloiobt"           , &el_caloiobt           );
	    Int_t           el_calofcll              ; tree->SetBranchAddress("el_calofcll"           , &el_calofcll           );
	    Int_t           el_caloHsFlag_           ; tree->SetBranchAddress("el_caloHsFlag_"        , &el_caloHsFlag_        );
	    Double_t        el_trkSign               ; tree->SetBranchAddress("el_trkSign"            , &el_trkSign            );
	    Double_t        el_tdc_count             ; tree->SetBranchAddress("el_tdc_count"          , &el_tdc_count          );
	    Double_t        el_min_xy_dist_          ; tree->SetBranchAddress("el_min_xy_dist_"       , &el_min_xy_dist_       );
	    Double_t        el_min_z_dist_           ; tree->SetBranchAddress("el_min_z_dist_"        , &el_min_z_dist_        );
	    Double_t        el_vtx_x_                ; tree->SetBranchAddress("el_vtx_x_"             , &el_vtx_x_             );
	    Double_t        el_vtx_y_                ; tree->SetBranchAddress("el_vtx_y_"             , &el_vtx_y_             );
	    Double_t        el_vtx_z_                ; tree->SetBranchAddress("el_vtx_z_"             , &el_vtx_z_             );
	    Double_t        el_ip_x_                 ; tree->SetBranchAddress("el_ip_x_"              , &el_ip_x_              );
	    Double_t        el_ip_y_                 ; tree->SetBranchAddress("el_ip_y_"              , &el_ip_y_              );
	    Double_t        el_ip_z_                 ; tree->SetBranchAddress("el_ip_z_"              , &el_ip_z_              );
		Double_t        trueVertexSector         ; tree->SetBranchAddress("trueVertexSector"      , &trueVertexSector      );
	    Int_t           trueVertexLayer          ; tree->SetBranchAddress("trueVertexLayer"       , &trueVertexLayer       );
	    Double_t        trueSectorId             ; tree->SetBranchAddress("trueSectorId"          , &trueSectorId          );
	    Double_t        trueSourceId             ; tree->SetBranchAddress("trueSourceId"          , &trueSourceId          );
	    Int_t           nLowEnergyClusters       ; tree->SetBranchAddress("nLowEnergyClusters"    , &nLowEnergyClusters    );
	    Double_t        totELowEnergyClusters    ; tree->SetBranchAddress("totELowEnergyClusters" , &totELowEnergyClusters );
	    Int_t           nClusters_               ; tree->SetBranchAddress("nClusters_"            , &nClusters_            );
	    Int_t           nHighEnergyClusters_     ; tree->SetBranchAddress("nHighEnergyClusters_"  , &nHighEnergyClusters_  );
	    Int_t           gmc_nGammas_[37]         ; tree->SetBranchAddress("gmc_nGammas_"          , gmc_nGammas_           );
	    Double_t        gmc_energy_[37]          ; tree->SetBranchAddress("gmc_energy_"           , gmc_energy_            );
	    Double_t        gmc_dEnergy_[37]         ; tree->SetBranchAddress("gmc_dEnergy_"          , gmc_dEnergy_           );
	    Double_t        gmc_timeSpan_[37]        ; tree->SetBranchAddress("gmc_timeSpan_"         , gmc_timeSpan_          );
	    Double_t        gmc_clusterProb_[37]     ; tree->SetBranchAddress("gmc_clusterProb_"      , gmc_clusterProb_       );
	    Double_t        gmc_measTime_[37]        ; tree->SetBranchAddress("gmc_measTime_"         , gmc_measTime_          );
	    Double_t        gmc_dMeasTime_[37]       ; tree->SetBranchAddress("gmc_dMeasTime_"        , gmc_dMeasTime_         );
	    Double_t        gmc_hitPosition_x_[37]   ; tree->SetBranchAddress("gmc_hitPosition_x_"    , gmc_hitPosition_x_     );
	    Double_t        gmc_hitPosition_y_[37]   ; tree->SetBranchAddress("gmc_hitPosition_y_"    , gmc_hitPosition_y_     );
	    Double_t        gmc_hitPosition_z_[37]   ; tree->SetBranchAddress("gmc_hitPosition_z_"    , gmc_hitPosition_z_     );
	    Double_t        gmc_scintToPMTTime_[37]  ; tree->SetBranchAddress("gmc_scintToPMTTime_"   , gmc_scintToPMTTime_    );
	    Double_t        gmc_dPathLength_[37]     ; tree->SetBranchAddress("gmc_dPathLength_"      , gmc_dPathLength_       );
	    Int_t           gmc_iobt_[37]            ; tree->SetBranchAddress("gmc_iobt_"             , gmc_iobt_              );
	    Int_t           gmc_fcll_[37]            ; tree->SetBranchAddress("gmc_fcll_"             , gmc_fcll_              );
	    Int_t           gmc_clusterId_[37]       ; tree->SetBranchAddress("gmc_clusterId_"        , gmc_clusterId_         );
	    Bool_t          gmc_goodPMTStatuses_[37] ; tree->SetBranchAddress("gmc_goodPMTStatuses_"  , gmc_goodPMTStatuses_   );
	    Bool_t          gmc_goodLDFlags_[37]     ; tree->SetBranchAddress("gmc_goodLDFlags_"      , gmc_goodLDFlags_       );
	    Bool_t          gmc_hasLDCorrs_[37]      ; tree->SetBranchAddress("gmc_hasLDCorrs_"       , gmc_hasLDCorrs_        );
	    Bool_t          gmc_hasLDCorrErrs_[37]   ; tree->SetBranchAddress("gmc_hasLDCorrErrs_"    , gmc_hasLDCorrErrs_     );
	    Bool_t          gmc_goodHSFlags_[37]     ; tree->SetBranchAddress("gmc_goodHSFlags_"      , gmc_goodHSFlags_       );
	    Int_t           gmc_numNeighbours_[37]   ; tree->SetBranchAddress("gmc_numNeighbours_"    , gmc_numNeighbours_     );
	    Double_t        gmc_first_g_time_[37]    ; tree->SetBranchAddress("gmc_first_g_time_"     , gmc_first_g_time_      );
	    Double_t        gmc_first_g_d_time_[37]  ; tree->SetBranchAddress("gmc_first_g_d_time_"   , gmc_first_g_d_time_    );
	    Double_t        gmc_first_g_x_[37]       ; tree->SetBranchAddress("gmc_first_g_x_"        , gmc_first_g_x_         );
	    Double_t        gmc_first_g_y_[37]       ; tree->SetBranchAddress("gmc_first_g_y_"        , gmc_first_g_y_         );
	    Double_t        gmc_first_g_z_[37]       ; tree->SetBranchAddress("gmc_first_g_z_"        , gmc_first_g_z_         );
	    Double_t        gmc_g_th_time_[37]       ; tree->SetBranchAddress("gmc_g_th_time_"        , gmc_g_th_time_         );
	    Double_t        gmc_g_d_th_time_[37]     ; tree->SetBranchAddress("gmc_g_d_th_time_"      , gmc_g_d_th_time_       );
	    Double_t        gmc_int_c_sq_[37]        ; tree->SetBranchAddress("gmc_int_c_sq_"         , gmc_int_c_sq_          );
	    Double_t        gmc_int_prob_[37]        ; tree->SetBranchAddress("gmc_int_prob_"         , gmc_int_prob_          );
	    Double_t        gmc_ext_c_sq_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_g_to_e_"  , gmc_ext_c_sq_g_to_e_   );
	    Double_t        gmc_ext_prob_g_to_e_[37] ; tree->SetBranchAddress("gmc_ext_prob_g_to_e_"  , gmc_ext_prob_g_to_e_   );
	    Double_t        gmc_ext_c_sq_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_c_sq_e_to_g_"  , gmc_ext_c_sq_e_to_g_   );
	    Double_t        gmc_ext_prob_e_to_g_[37] ; tree->SetBranchAddress("gmc_ext_prob_e_to_g_"  , gmc_ext_prob_e_to_g_   );
	    Double_t        cosTheta_[37]            ; tree->SetBranchAddress("cosTheta_"             , cosTheta_              );

	    TVector3* eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex", &eVertex);
	    TVector3* trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex", &trueVertex);
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

	        double ext_prob = 
	          (gmc_ext_prob_g_to_e_[0] < gmc_ext_prob_e_to_g_[0]) ?
	           gmc_ext_prob_g_to_e_[0] : gmc_ext_prob_e_to_g_[0];

			// Implement selection
			if ( !CheckRunNumber(run) ) continue;
		    if ( sectorId != 18 || IsExcludedSpot(el_vtx_z_, vertexSector)) continue; hAnaCutFlow -> Fill(currentcut++);
			if ( el_trkSign >=0 ) 											continue; hAnaCutFlow->Fill(currentcut++);
			if ( nHighEnergyClusters_ != 1 ) 	      						continue; hAnaCutFlow -> Fill(currentcut++);
		    if ( el_energy_ < 0.3 )          	      						continue; hAnaCutFlow -> Fill(currentcut++);
		    if ( gmc_int_prob_[0] > 0.01 )   	      						continue; hAnaCutFlow -> Fill(currentcut++);
			if ( gmc_ext_prob_g_to_e_[0] < 0.04 )     						continue; hAnaCutFlow -> Fill(currentcut++);
			if ( IsHotSpot(el_vtx_z_, vertexSector) ) 						continue; hAnaCutFlow -> Fill(currentcut++);
			
			// Apply radon map
		    double weight = 1;
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;

	        // Take into account half-lives for Bi210 and Co60 
	        if(std::string::npos != name.find("Bi210")){
	        	weight *= exp(-(log(2)/(22.3*365.25*86400.0))*eventTime);
	        }
	        if(std::string::npos != name.find("Co60")){
	        	weight *= exp(-(log(2)/(1925.2*86400.0))*eventTime);
	        }
		
			// Fill histogram
	        histo_collection -> Find( TString::Format("%s_h_run"             , d->GetName()) ) -> Fill(run                       , weight);  
	        histo_collection -> Find( TString::Format("%s_h_eventTime"       , d->GetName()) ) -> Fill(eventTime/86400.0         , weight);  
	        histo_collection -> Find( TString::Format("%s_h_sectorId"        , d->GetName()) ) -> Fill(sectorId                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_sourceId"        , d->GetName()) ) -> Fill(sourceId                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_electronEnergy"  , d->GetName()) ) -> Fill(el_energy_                , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackLength"     , d->GetName()) ) -> Fill(el_pathLength_            , weight);
	        histo_collection -> Find( TString::Format("%s_h_trackSign"       , d->GetName()) ) -> Fill(el_trkSign                , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexZ"         , d->GetName()) ) -> Fill(eVertex->z()              , weight);
	        histo_collection -> Find( TString::Format("%s_h_vertexSector"    , d->GetName()) ) -> Fill(vertexSector              , weight);
	        histo_collection -> Find( TString::Format("%s_h_gammaEnergy"     , d->GetName()) ) -> Fill(gmc_energy_[0]            , weight);
	        histo_collection -> Find( TString::Format("%s_h_cosTheta"        , d->GetName()) ) -> Fill(cosTheta_[0]              , weight);
	        histo_collection -> Find( TString::Format("%s_h_probInt"         , d->GetName()) ) -> Fill(gmc_int_prob_[0]          , weight);
	        histo_collection -> Find( TString::Format("%s_h_probExt"         , d->GetName()) ) -> Fill(ext_prob                  , weight);
	        histo_collection -> Find( TString::Format("%s_h_gammaLowEnergy"  , d->GetName()) ) -> Fill(totELowEnergyClusters     , weight);          
	        histo_collection -> Find( TString::Format("%s_h_nLowEnergyGamma" , d->GetName()) ) -> Fill(nLowEnergyClusters        , weight);
			
	        histo_collection -> Find( TString::Format("%s_h_layer_vs_side"   , d->GetName()) ) -> Fill(foilSide, trueVertexLayer);

			histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect"    , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);

			//if( IsHotSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_hot"  , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			//else if( IsWarmSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_warm" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			//else if( IsColdSpot(el_vtx_z_, vertexSector) )
			//	histo_collection->Find( TString::Format("%s_h_vtx_z_vs_sect_cold" , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);

			//string wall[4]   = {"In","Out","Pet","Pet"};

		    if (run < 3396) {
				
				histo_collection->Find(TString::Format("%s_h_tot_energy_P1" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				histo_collection->Find(TString::Format("%s_h_e_energy_P1"   , d->GetName()) ) -> Fill(el_energy_                 , weight);
				histo_collection->Find(TString::Format("%s_h_g_energy_P1"   , d->GetName()) ) -> Fill(gmc_energy_[0]             , weight);
				
				if( gmc_iobt_[0] == 0 ) {
					
					histo_collection->Find(TString::Format("%s_h_tot_energy_P1_In"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					
					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P1_In_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_In_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_In_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					
				} else if( gmc_iobt_[0] == 1 ) {

					histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Out"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Out_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Out_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Out_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);


				} else if( gmc_iobt_[0] == 2 or gmc_iobt_[0] == 3 ) {

					histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Pet"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Pet_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Pet_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P1_Pet_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

				}
			}

		    else {
				
				//if( ! IsHotSpot(el_vtx_z_, vertexSector) )
				histo_collection->Find(TString::Format("%s_h_tot_energy_P2" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
				histo_collection->Find(TString::Format("%s_h_e_energy_P2"   , d->GetName()) ) -> Fill(el_energy_                 , weight);
				histo_collection->Find(TString::Format("%s_h_g_energy_P2"   , d->GetName()) ) -> Fill(gmc_energy_[0]             , weight);

				if( gmc_iobt_[0] == 0 ) {

					histo_collection->Find(TString::Format("%s_h_tot_energy_P2_In"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P2_In_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_In_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_In_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

				} else if( gmc_iobt_[0] == 1 ) {
					
					histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Out"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Out_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Out_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Out_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);

				} else if( gmc_iobt_[0] == 2 or gmc_iobt_[0] == 3 ) {
					
					histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Pet"  , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);			

					//if( IsHotSpot(el_vtx_z_, vertexSector) )
					//	histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Pet_hot" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					if( IsWarmSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Pet_warm" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					else if( IsColdSpot(el_vtx_z_, vertexSector) )
						histo_collection->Find(TString::Format("%s_h_tot_energy_P2_Pet_cold" , d->GetName()) ) -> Fill(el_energy_ + gmc_energy_[0], weight);
					
				}
			}
		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;


	}	
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process one electron one alpha channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: DONE 14/11/2014
	//		
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneAlpha( DataSet *d ){

		TString tmp_name = _InputFilePath + d->GetName() + "/" + _InputFileName;
		TFile * _InputFile = new TFile(tmp_name,"READ");
	
		if(_InputFile->IsZombie()) return kFALSE;

		_InputFile->Print();
	
		// Define histograms
		HistoCollection * histo_collection = new HistoCollection(d->GetName(), "");
		histo_collection->GetCollection()->SetOwner(kTRUE);
		TH1D::SetDefaultSumw2(kTRUE);

		// Retry Reco cut flow histogram
		TDirectoryFile * f0 = (TDirectoryFile*) _InputFile->Get("CutFlowManager");
	    TH1F* hRecoCutFlow = (TH1F*)f0->FindObjectAny("CutFlowManager_hCutFlow_")->Clone(TString::Format("%s_h_RecoCutFlow", d->GetName()));
		histo_collection->Add( hRecoCutFlow );

		// Make Ana cut flow histogram
	    std::vector<std::string>* cutNames = new std::vector<std::string>();
	    cutNames->push_back("All events ");
	    cutNames->push_back("Cd-116 sector (18) ");
	    cutNames->push_back("Negative electron track sign");
	    cutNames->push_back("Energy of the electron > 300 keV ");
	    cutNames->push_back("Length of alpha track < $40\\,\\rm{cm}$ ");
	    cutNames->push_back("At least 2 delayed hits in the Alpha cluster");
		cutNames->push_back("Is an hot spot");

	    unsigned int nCuts = cutNames->size();
	    TH1D* hAnaCutFlow  = new TH1D( TString::Format("%s_h_AnaCutFlow", d->GetName() ),"Analysis cut flow", nCuts+1, -0.5, nCuts+0.5);
	    for (unsigned int i = 0; i < cutNames->size(); i++){
	      hAnaCutFlow->GetXaxis()->SetBinLabel(i+1,cutNames->at(i).c_str());
	    }
		
		histo_collection->Add( hAnaCutFlow );

		// Make all other histos		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_run"                   , d->GetName() ) , "Run Number; Run; "  , 200, 1000, 9500                                                   ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sectorId"              , d->GetName() ) , "Sector Id; Sector; ",  21, -0.5, 20.5                                                   ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_sourceId"              , d->GetName() ) , "Source Id; Source; ",   4, -1.5, 2.5                                                    ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy"        , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electroniobt"          , d->GetName() ) , "Address of block hit by electron; IOBT; No.Events", 5, -0.5, 4.5                        ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackLength"           , d->GetName() ) , "Track Length; Track Length / cm; No.Events / cm", 200, 0, 200                           ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_trackSign"             , d->GetName() ) , "Track Sign; Sign of Track Curvature / cm; No.Events / cm", 10, -2, 2                    ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexZ"               , d->GetName() ) , "Z of electron interzection; Z / cm ; No.Events / cm", 260, -130, 130                    ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_vertexSector"          , d->GetName() ) , "Sector number of electron interzection; Sector Number; No.Events", 100, 18, 19          ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_vtx_z_vs_sect"         , d->GetName() ) , "; Sector Number; Z_{vertex} / cm", 500, 18, 19, 520, -130, 130                          ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_nGammas"               , d->GetName() ) , "Number of non associated #gamma; No. Gammas; No.Events", 15, -0.5, 14.5                 ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_gammaLowEnergy"        , d->GetName() ) , "Total energy of not associated #gamma; E / MeV; No.Events/0.1 MeV", 35, 0, 3.5          ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaNHits"            , d->GetName() ) , "Number of delayed hits in #alpha; N.Hits / MeV; No.Events", 15, -0.5, 14.5              ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime"             , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                   ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaMaxTimeDiff"      , d->GetName() ) , "Maximum time difference; Max Time Diff / #mus;  No.Events / 0.1 #mus", 25, 0, 2.5       ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength"           , d->GetName() ) , "Length of the #alpha track; Alpha length / cm; No.Events / cm", 55, 0, 55               ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaVertexZ"          , d->GetName() ) , "Z of alpha intersection; Z / cm; No.Events / cm", 260, -130, 130                        ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaVertexSector"     , d->GetName() ) , "Sector number of alpha intersection; Sector Number; No.Events", 200, 0, 20              ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaVertexDist"       , d->GetName() ) , "Distance between electron and alpha vtx; Distance / cm; No.Events / 0.1 cm", 100, 0, 10 ) );
	    histo_collection -> Add( new TH2D( TString::Format("%s_h_layer_vs_side"         , d->GetName() ) , "Layer vs Side; Side; Layer", 4, -1.5, 2.5, 10, -0.5, 9.5                                ) );

		// P1 plots

	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P1"                , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P1"           , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P1"              , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P1_eIn_aIn"        , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P1_eIn_aIn"   , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P1_eIn_aIn"      , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P1_eOut_aOut"      , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P1_eOut_aOut" , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P1_eOut_aOut"    , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P1_eIn_aOut"       , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P1_eIn_aOut"  , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P1_eIn_aOut"     , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P1_eOut_aIn"       , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P1_eOut_aIn"  , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P1_eOut_aIn"     , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );

		// P2 plots

	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P2"                , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P2"           , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P2"              , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );		
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P2_eIn_aIn"        , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P2_eIn_aIn"   , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P2_eIn_aIn"      , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P2_eOut_aOut"      , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P2_eOut_aOut" , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P2_eOut_aOut"    , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P2_eIn_aOut"       , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P2_eIn_aOut"  , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P2_eIn_aOut"     , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaTime_P2_eOut_aIn"       , d->GetName() ) , "Time of delayed #alpha; Time / #mus; No.Events / 20 #mus", 40, 0, 800                ) );
	    histo_collection -> Add( new TH1D( TString::Format("%s_h_electronEnergy_P2_eOut_aIn"  , d->GetName() ) , "Energy of Electron; E_{e} / MeV; No.Events / 0.1 MeV", 35, 0, 3.5                    ) );
		histo_collection -> Add( new TH1D( TString::Format("%s_h_alphaLength_P2_eOut_aIn"     , d->GetName() ) , "; #alpha length / cm; No.Events / cm", 55, 0, 55                                     ) );



		// Get TTree
		TDirectoryFile * f1 = (TDirectoryFile*) _InputFile->Get(_InputDirName);	
		TTree * tree = (TTree *) f1->Get(_InputTreeName);

		// Declaration of leaf types
	    Int_t           run                      ; tree->SetBranchAddress("run"                       , &run                      );
	    Int_t           event                    ; tree->SetBranchAddress("event"                     , &event                    );
	    Int_t           runType                  ; tree->SetBranchAddress("runType"                   , &runType                  );
	    Int_t           timeStampSec             ; tree->SetBranchAddress("timeStampSec"              , &timeStampSec             );
	    Int_t           timeStampNanoS           ; tree->SetBranchAddress("timeStampNanoS"            , &timeStampNanoS           );
	    Double_t        radonWeight              ; tree->SetBranchAddress("radonWeight"               , &radonWeight              );
	    Double_t        bi210Weight              ; tree->SetBranchAddress("bi210Weight"               , &bi210Weight              );
	    Double_t        sfoilRadonWeight         ; tree->SetBranchAddress("sfoilRadonWeight"          , &sfoilRadonWeight         );
	    Int_t           foilSide                 ; tree->SetBranchAddress("foilSide"                  , &foilSide                 );
	    Int_t           sectorId                 ; tree->SetBranchAddress("sectorId"                  , &sectorId                 );
	    Int_t           sourceId                 ; tree->SetBranchAddress("sourceId"                  , &sourceId                 );
	    Int_t           isInHotSpot              ; tree->SetBranchAddress("isInHotSpot"               , &isInHotSpot              );
	    Double_t        vertexSector             ; tree->SetBranchAddress("vertexSector"              , &vertexSector             );
	    Double_t        el_energy                ; tree->SetBranchAddress("el_energy"                 , &el_energy                );
	    Int_t           el_side                  ; tree->SetBranchAddress("el_side"                   , &el_side                  );
	    Double_t        el_dEnergy               ; tree->SetBranchAddress("el_dEnergy"                , &el_dEnergy               );
	    Double_t        el_beta                  ; tree->SetBranchAddress("el_beta"                   , &el_beta                  );
	    Double_t        el_dBeta                 ; tree->SetBranchAddress("el_dBeta"                  , &el_dBeta                 );
	    Double_t        el_pathLength            ; tree->SetBranchAddress("el_pathLength"             , &el_pathLength            );
	    Double_t        el_energyLoss            ; tree->SetBranchAddress("el_energyLoss"             , &el_energyLoss            );
	    Double_t        el_measTime              ; tree->SetBranchAddress("el_measTime"               , &el_measTime              );
	    Double_t        el_dMeasTime             ; tree->SetBranchAddress("el_dMeasTime"              , &el_dMeasTime             );
	    Double_t        el_thTof                 ; tree->SetBranchAddress("el_thTof"                  , &el_thTof                 );
	    Double_t        el_dThTof                ; tree->SetBranchAddress("el_dThTof"                 , &el_dThTof                );
	    Int_t           el_caloiobt              ; tree->SetBranchAddress("el_caloiobt"               , &el_caloiobt              );
	    Int_t           el_calofcll              ; tree->SetBranchAddress("el_calofcll"               , &el_calofcll              );
	    Int_t           el_caloHsFlag            ; tree->SetBranchAddress("el_caloHsFlag"             , &el_caloHsFlag            );
	    Double_t        el_trkSign               ; tree->SetBranchAddress("el_trkSign"                , &el_trkSign               );
	    Long64_t        el_tdc_count             ; tree->SetBranchAddress("el_tdc_count"              , &el_tdc_count             );
	    Double_t        trueVertexSector         ; tree->SetBranchAddress("trueVertexSector"          , &trueVertexSector         );
	    Int_t           trueVertexLayer          ; tree->SetBranchAddress("trueVertexLayer"           , &trueVertexLayer          );
	    Double_t        trueSectorId             ; tree->SetBranchAddress("trueSectorId"              , &trueSectorId             );
	    Double_t        trueSourceId             ; tree->SetBranchAddress("trueSourceId"              , &trueSourceId             );
	    Int_t           nGammas                  ; tree->SetBranchAddress("nGammas"                   , &nGammas                  );
	    Int_t           nLowEnergyGammas         ; tree->SetBranchAddress("nLowEnergyGammas"          , &nLowEnergyGammas         );
	    Int_t           nHighEnergyGammas        ; tree->SetBranchAddress("nHighEnergyGammas"         , &nHighEnergyGammas        );
	    Double_t        totELowEnergyGammas      ; tree->SetBranchAddress("totELowEnergyGammas"       , &totELowEnergyGammas      );
	    Double_t        totEHighEnergyGammas     ; tree->SetBranchAddress("totEHighEnergyGammas"      , &totEHighEnergyGammas     );
	    Int_t           gm_pmtNumber_[50]        ; tree->SetBranchAddress("gm_pmtNumber_"             , gm_pmtNumber_             );
	    Int_t           gm_sectorNumber_[50]     ; tree->SetBranchAddress("gm_sectorNumber_"          , gm_sectorNumber_          );
	    Int_t           gm_iobt_[50]             ; tree->SetBranchAddress("gm_iobt_"                  , gm_iobt_                  );
	    Int_t           gm_fcll_[50]             ; tree->SetBranchAddress("gm_fcll_"                  , gm_fcll_                  );
	    Int_t           gm_blockNumber_[50]      ; tree->SetBranchAddress("gm_blockNumber_"           , gm_blockNumber_           );
	    Int_t           gm_ldFlag_[50]           ; tree->SetBranchAddress("gm_ldFlag_"                , gm_ldFlag_                );
	    Double_t        gm_ldCorr_[50]           ; tree->SetBranchAddress("gm_ldCorr_"                , gm_ldCorr_                );
	    Double_t        gm_ldCorrErr_[50]        ; tree->SetBranchAddress("gm_ldCorrErr_"             , gm_ldCorrErr_             );
	    Int_t           gm_hsFlag_[50]           ; tree->SetBranchAddress("gm_hsFlag_"                , gm_hsFlag_                );
	    Double_t        gm_energy_[50]           ; tree->SetBranchAddress("gm_energy_"                , gm_energy_                );
	    Double_t        gm_dEnergy_[50]          ; tree->SetBranchAddress("gm_dEnergy_"               , gm_dEnergy_               );
	    Double_t        gm_measTime_[50]         ; tree->SetBranchAddress("gm_measTime_"              , gm_measTime_              );
	    Double_t        gm_dMeasTime_[50]        ; tree->SetBranchAddress("gm_dMeasTime_"             , gm_dMeasTime_             );
	    Double_t        gm_dPathLength_[50]      ; tree->SetBranchAddress("gm_dPathLength_"           , gm_dPathLength_           );
	    Double_t        gm_thickness_[50]        ; tree->SetBranchAddress("gm_thickness_"             , gm_thickness_             );
	    Double_t        gm_blockWidth_[50]       ; tree->SetBranchAddress("gm_blockWidth_"            , gm_blockWidth_            );
	    Double_t        gm_blockHeight_[50]      ; tree->SetBranchAddress("gm_blockHeight_"           , gm_blockHeight_           );
	    Double_t        gm_scintToPMTTime_[50]   ; tree->SetBranchAddress("gm_scintToPMTTime_"        , gm_scintToPMTTime_        );
	    Int_t           alphaNHits               ; tree->SetBranchAddress("alphaNHits"                , &alphaNHits               );
	    Double_t        alphaTime                ; tree->SetBranchAddress("alphaTime"                 , &alphaTime                );
	    Double_t        alphaMaxTimeDiff         ; tree->SetBranchAddress("alphaMaxTimeDiff"          , &alphaMaxTimeDiff         );
	    Double_t        alphaLength              ; tree->SetBranchAddress("alphaLength"               , &alphaLength              );
	    Double_t        alphaClosestHitDistFoil  ; tree->SetBranchAddress("alphaClosestHitDistFoil"   , &alphaClosestHitDistFoil  );
	    Double_t        alphaClosestHitDistWire  ; tree->SetBranchAddress("alphaClosestHitDistWire"   , &alphaClosestHitDistWire  );
	    Double_t        alphaFurthestHitDistFoil ; tree->SetBranchAddress("alphaFurthestHitDistFoil"  , &alphaFurthestHitDistFoil );
	    Int_t           alphaSide                ; tree->SetBranchAddress("alphaSide"                 , &alphaSide                );
	    Bool_t          alphaNearWire_           ; tree->SetBranchAddress("alphaNearWire_"            , &alphaNearWire_           );
	    Double_t        alphaVertexZ             ; tree->SetBranchAddress("alphaVertexZ"              , &alphaVertexZ             );
	    Double_t        alphaVertexSector        ; tree->SetBranchAddress("alphaVertexSector"         , &alphaVertexSector        );
	    Double_t        alphaVertexDist          ; tree->SetBranchAddress("alphaVertexDist"           , &alphaVertexDist          );


	    TVector3* eVertex    = new TVector3(0,0,0) ; tree->SetBranchAddress("eVertex"    , &eVertex    );
	    TVector3* trueVertex = new TVector3(0,0,0) ; tree->SetBranchAddress("trueVertex" , &trueVertex );
	    TVector3* el_ip      = new TVector3(0,0,0) ; tree->SetBranchAddress("el_ip"      , &el_ip      );
		
		// Loop
		Long64_t nentries = tree->GetEntriesFast();
		if ( _n_max != -1) nentries = _n_max;

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
			int frac = (int)round(100*iEvt/nentries);
		    if ( iEvt % (int)round(1+(0.1*nentries)) == 0) {
				std::cout << "Process: " << frac << "% (" << iEvt << "/" << nentries << ")" << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);
			if ( !CheckRunNumber(run) ) continue;
	        if(sectorId != 18 || IsExcludedSpot(eVertex->z(), vertexSector)) continue; hAnaCutFlow->Fill(currentcut++);
	        if(el_trkSign >= 0 ) 											 continue; hAnaCutFlow->Fill(currentcut++);
			if(el_energy   < 0.3)                       					 continue; hAnaCutFlow->Fill(currentcut++);
	        if(alphaLength > 40)                        					 continue; hAnaCutFlow->Fill(currentcut++);
	        if(alphaNHits  < 2)                         					 continue; hAnaCutFlow->Fill(currentcut++);
			if( IsHotSpot(eVertex->z(), vertexSector) ) 					 continue; hAnaCutFlow->Fill(currentcut++);
	
			// Apply radon map
		    double weight = 1;
			std::string name (d->GetName());
		    if (std::string::npos != name.find("SWire_Bi214") or 
				std::string::npos != name.find("SWire_Pb214") )  weight = radonWeight;
		    if (std::string::npos != name.find("SFoil_Bi214")  or
		        std::string::npos != name.find("SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (std::string::npos != name.find("SWire_Bi210") )  weight = bi210Weight;
			
	        histo_collection -> Find( TString::Format("%s_h_run"               , d->GetName()) ) -> Fill(run                        , weight );    
	        histo_collection -> Find( TString::Format("%s_h_sectorId"          , d->GetName()) ) -> Fill(sectorId                   , weight );
	        histo_collection -> Find( TString::Format("%s_h_sourceId"          , d->GetName()) ) -> Fill(sourceId                   , weight );
	        histo_collection -> Find( TString::Format("%s_h_electronEnergy"    , d->GetName()) ) -> Fill(el_energy                  , weight );
	        histo_collection -> Find( TString::Format("%s_h_electroniobt"      , d->GetName()) ) -> Fill(el_caloiobt                , weight );
	        histo_collection -> Find( TString::Format("%s_h_trackLength"       , d->GetName()) ) -> Fill(el_pathLength              , weight );
	        histo_collection -> Find( TString::Format("%s_h_trackSign"         , d->GetName()) ) -> Fill(el_trkSign                 , weight );
	        histo_collection -> Find( TString::Format("%s_h_vertexZ"           , d->GetName()) ) -> Fill(eVertex->z()               , weight );
	        histo_collection -> Find( TString::Format("%s_h_vertexSector"      , d->GetName()) ) -> Fill(vertexSector               , weight );
	        histo_collection -> Find( TString::Format("%s_h_nGammas"           , d->GetName()) ) -> Fill(nGammas                    , weight );
	        histo_collection -> Find( TString::Format("%s_h_gammaLowEnergy"    , d->GetName()) ) -> Fill(totELowEnergyGammas        , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaNHits"        , d->GetName()) ) -> Fill(alphaNHits                 , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaTime"         , d->GetName()) ) -> Fill(alphaTime/1000             , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaMaxTimeDiff"  , d->GetName()) ) -> Fill(alphaMaxTimeDiff/1000      , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaLength"       , d->GetName()) ) -> Fill(alphaLength                , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaVertexZ"      , d->GetName()) ) -> Fill(alphaVertexZ               , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaVertexSector" , d->GetName()) ) -> Fill(alphaVertexSector          , weight );
	        histo_collection -> Find( TString::Format("%s_h_alphaVertexDist"   , d->GetName()) ) -> Fill(alphaVertexDist            , weight );
			
			histo_collection -> Find( TString::Format("%s_h_vtx_z_vs_sect"     , d->GetName()) ) -> Fill(vertexSector , eVertex->z()    );
	        histo_collection -> Find( TString::Format("%s_h_layer_vs_side"     , d->GetName()) ) -> Fill(foilSide     , trueVertexLayer );
 
	        // string e_a_side_t[4] = {"e In - #alpha In", "e In - #alpha Out", 
	        //                         "e Out - #alpha In", "e Out - #alpha Out"};
	        //int side_id = el_side*2 + alphaSide;
 
 		    if (run < 3396) {


				histo_collection -> Find( TString::Format("%s_h_alphaTime_P1"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
				histo_collection -> Find( TString::Format("%s_h_electronEnergy_P1" , d->GetName()) )->Fill(el_energy      , weight);
				histo_collection -> Find( TString::Format("%s_h_alphaLength_P1"    , d->GetName()) )->Fill(alphaLength    , weight);
				
				if ( el_side == 0 and alphaSide == 0) {
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P1_eIn_aIn"    , d->GetName()) )->Fill(alphaLength    , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaTime_P1_eIn_aIn"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P1_eIn_aIn" , d->GetName()) )->Fill(el_energy      , weight);

				} else if( el_side == 1 and alphaSide == 1) {
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P1_eOut_aOut"    , d->GetName()) )->Fill(alphaLength    , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaTime_P1_eOut_aOut"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P1_eOut_aOut" , d->GetName()) )->Fill(el_energy      , weight);

				} else if( el_side == 0 and alphaSide == 1) {
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P1_eIn_aOut"    , d->GetName()) )->Fill(alphaLength    , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaTime_P1_eIn_aOut"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P1_eIn_aOut" , d->GetName()) )->Fill(el_energy      , weight);

				} else if( el_side == 1 and alphaSide == 0) {
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P1_eOut_aIn"    , d->GetName()) )->Fill(alphaLength    , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaTime_P1_eOut_aIn"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P1_eOut_aIn" , d->GetName()) )->Fill(el_energy      , weight);

				}
				
			} else {

				histo_collection -> Find( TString::Format("%s_h_alphaTime_P2"      , d->GetName()) )->Fill(alphaTime/1000 , weight);
				histo_collection -> Find( TString::Format("%s_h_electronEnergy_P2" , d->GetName()) )->Fill(el_energy , weight);
				histo_collection -> Find( TString::Format("%s_h_alphaLength_P2"    , d->GetName()) )->Fill(alphaLength , weight);

				if ( el_side == 0 and alphaSide == 0) {
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eIn_aIn"    , d->GetName()) )->Fill(alphaLength , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P2_eIn_aIn" , d->GetName()) )->Fill(el_energy   , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eIn_aIn"    , d->GetName()) )->Fill(alphaLength , weight);

				} else if( el_side == 1 and alphaSide == 1) {                             
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eOut_aOut"    , d->GetName()) )->Fill(alphaLength , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P2_eOut_aOut" , d->GetName()) )->Fill(el_energy   , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eOut_aOut"    , d->GetName()) )->Fill(alphaLength , weight);

				} else if( el_side == 0 and alphaSide == 1) {                             
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eIn_aOut"    , d->GetName()) )->Fill(alphaLength , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P2_eIn_aOut" , d->GetName()) )->Fill(el_energy   , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eIn_aOut"    , d->GetName()) )->Fill(alphaLength , weight);

				} else if( el_side == 1 and alphaSide == 0) {                             
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eOut_aIn"    , d->GetName()) )->Fill(alphaLength , weight);
					histo_collection -> Find( TString::Format("%s_h_electronEnergy_P2_eOut_aIn" , d->GetName()) )->Fill(el_energy   , weight);
					histo_collection -> Find( TString::Format("%s_h_alphaLength_P2_eOut_aIn"    , d->GetName()) )->Fill(alphaLength , weight);

				}

			}
			
		}

		std::cout << "before output file" << std::endl;
		TFile * _OutputFile = new TFile(_OutputFilePath + _OutputFileName, "UPDATE");
		_OutputFile->Print();
		histo_collection->Write();
		
		//histo_collection->SaveAs("test.pdf");
			
		// Delete the remaining crap
		histo_collection->Delete();
		tree->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;
	}

}
