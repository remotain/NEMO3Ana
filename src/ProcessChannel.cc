
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
			case kOneElectron                 : return "kOneElectron∂";
			case kTwoElectronInternal         : return "kTwoElectronInternal";
		    case kTwoElectronExternal         : return "kTwoElectronExternal";
		    case kOneElectronOneGammaInternal : return "kOneElectronOneGammaInternal";
		    case kOneElectronOneGammaExternal : return "kOneElectronOneGammaExternal";
			case kOneElectronTwoGammaInternal : return "kOneElectronTwoGammaInternal";
			case kOneElectronOneAlpha         : return "kOneElectronOneAlpha";
		};
	
		return "kUndefined";
		
	};

	// Data Set collection
	THashList * _DataSetCollection = new THashList();
	void AddDataSet( DataSet * d){ _DataSetCollection->Add(d); };
    THashList * GetDataSetCollection() { return _DataSetCollection; };

	//////////////////////////////////////////////////////////////////////////////
	//
	// Run over all data set found in _DataSetCollection
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool Run(){

		TIter next(_DataSetCollection);
		DataSet * d;

		while( (d = (DataSet *) next()) ) {
				
			std::cout << std::endl << "Processing: " << d->GetName()<< std::endl;

			bool status = kFALSE;

			// Process the required channel
			switch(_ChannelToProcess) { 
				case kOneElectron                 : status = ProcessOneElectron(d)                 ; break;
				case kTwoElectronInternal         : status = ProcessTwoElectronInternal(d)         ; break;
				case kTwoElectronExternal         : status = ProcessTwoElectronExternal(d)         ; break;
				case kOneElectronOneGammaInternal : status = ProcessOneElectronOneGammaInternal(d) ; break;
				case kOneElectronOneGammaExternal : status = ProcessOneElectronOneGammaExternal(d) ; break;
				case kOneElectronTwoGammaInternal : status = ProcessOneElectronTwoGammaInternal(d) ; break;
				case kOneElectronOneAlpha         : status = ProcessOneElectronOneAlpha(d)         ; break;			
			
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
	    cutNames->push_back("Energy of the electron > 200 keV ");
	    cutNames->push_back("Negative track sign");

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
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexZ"               , d->GetName()) , "; Z_{vertex} / cm ; No.Events / cm", 260, -130, 130                ) );
		histo_collection->Add( new TH2D ( TString::Format("%s_h_vertex"                , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130       ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector"          , d->GetName()) , "; Sector Number; No.Events", 200, 0, 20                            ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexZ"           , d->GetName()) , "; True - Z_{vertex} / cm ; No.Events / cm", 260, -130, 130         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexSector"      , d->GetName()) , "; True - Sector Number; No.Events", 200, 0, 20                     ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sectorId"              , d->GetName()) , "; Sector; No.Events",  21, -0.5, 20.5                              ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sourceId"              , d->GetName()) , "; Source; No.Events",   4, -1.5, 2.5                               ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSectorId"          , d->GetName()) , "; True Sector; No.Events",  21, -0.5, 20.5                         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSourceId"          , d->GetName()) , "; True Source; No.Events",   4, -1.5, 2.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_nGammas"               , d->GetName()) , "; No. #gammas; No.Events", 15, -0.5, 14.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_totGammaEnergy"        , d->GetName()) , "; #Sigma E_{#gamma}^{high} / MeV; No.Events / 0.05 MeV", 50, 0, 2.5) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P1"           , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 350, 0, 3.5                  ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_e_energy_P2"           , d->GetName()) , "; E_{e} / MeV; No.Events / 0.01 MeV", 350, 0, 3.5                  ) );

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

	    Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
		    if (iEvt % 500000 == 0) {
		      std::cout << "\t " << iEvt << "/" << nentries << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;

			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
			if (sectorId != 18)    continue; hAnaCutFlow -> Fill(currentcut++); // Cd foil only
			if (el_trkSign > 0)    continue; hAnaCutFlow -> Fill(currentcut++); // Negative track only
			if (el_energy < 0.200) continue; hAnaCutFlow -> Fill(currentcut++); // E > 2 MeV only
			// 3. no hotspot
		
			// Apply radon map
		    double weight = 1.0;    
		    if (strcmp(d->GetName(), "SWire_Bi214") == 0 or 
			strcmp(d->GetName(), "SWire_Pb214") == 0 )  weight = radonWeight;
		    if (strcmp(d->GetName(), "SFoil_Bi214") == 0  or
		        strcmp(d->GetName(), "SFoil_Pb214") == 0 )  weight = sfoilRadonWeight;
		    if (strcmp(d->GetName(), "SWire_Bi210") == 0 )  weight = bi210Weight;
		
			// Fill histogram
		    histo_collection->Find( TString::Format("%s_h_run"              , d->GetName()) ) -> Fill(run,weight);
		    histo_collection->Find( TString::Format("%s_h_electronEnergy"   , d->GetName()) ) -> Fill(el_energy, weight);
			histo_collection->Find( TString::Format("%s_h_trackLength"      , d->GetName()) ) -> Fill(el_pathLength, weight);
			histo_collection->Find( TString::Format("%s_h_trackSign"        , d->GetName()) ) -> Fill(el_trkSign, weight);
			histo_collection->Find( TString::Format("%s_h_electronIobt"     , d->GetName()) ) -> Fill(el_caloiobt, weight);
			histo_collection->Find( TString::Format("%s_h_vertex"           , d->GetName()) ) -> Fill(vertexSector, el_vtx_z_);
			histo_collection->Find( TString::Format("%s_h_vertexZ"          , d->GetName()) ) -> Fill(el_vtx_z_, weight);
			histo_collection->Find( TString::Format("%s_h_vertexSector"     , d->GetName()) ) -> Fill(vertexSector, weight);
			histo_collection->Find( TString::Format("%s_h_trueVertexZ"      , d->GetName()) ) -> Fill(trueVertex->Z(), weight);
			histo_collection->Find( TString::Format("%s_h_trueVertexSector" , d->GetName()) ) -> Fill(trueVertexSector, weight);
			histo_collection->Find( TString::Format("%s_h_sectorId"         , d->GetName()) ) -> Fill(sectorId, weight);
			histo_collection->Find( TString::Format("%s_h_sourceId"         , d->GetName()) ) -> Fill(sourceId, weight);
			histo_collection->Find( TString::Format("%s_h_trueSectorId"     , d->GetName()) ) -> Fill(trueSectorId, weight);
			histo_collection->Find( TString::Format("%s_h_trueSourceId"     , d->GetName()) ) -> Fill(trueSourceId, weight);
			histo_collection->Find( TString::Format("%s_h_nGammas"          , d->GetName()) ) -> Fill(nClusters_, weight);
			histo_collection->Find( TString::Format("%s_h_totGammaEnergy"   , d->GetName()) ) -> Fill(totUnderlyingEnergy_, weight);
		  
			// Phase 1 & 2
		    if (run < 3396) {
			 histo_collection->Find(TString::Format("%s_h_e_energy_P1", d->GetName())) -> Fill(el_energy);
		    } else {
			 histo_collection->Find(TString::Format("%s_h_e_energy_P2", d->GetName())) -> Fill(el_energy); 
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
	    cutNames->push_back("Energy of the electron > 200 keV ");
		cutNames->push_back("Sum track length > 80 cm ");
		cutNames->push_back("Internal probability > 0.04");
		cutNames->push_back("External probability < 0.01");
		cutNames->push_back("No unassociated hits opposite to the electrons");
	    cutNames->push_back("No electron hits petal near the foil");
		cutNames->push_back("|dz_vtx| < 4 cm and radial distance < 2");

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
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexSector"           , d->GetName()) , "; Sector Number; No.Events", 200, 0, 20                             ) );
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

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
		    if (iEvt % 500000 == 0) {
		      std::cout << "\t " << iEvt << "/" << nentries << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
		    if (sectorId != 18)                                    continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_energy_[0] < 0.2 or el_energy_[1] < 0.2)        continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_pathLength_[0] + el_pathLength_[1] < 80)        continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probInt < 0.04)                                    continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probExt_0_to_1 > 0.01 or probExt_1_to_0 > 0.01)    continue; hAnaCutFlow -> Fill(currentcut++);
		    if (elOnSameSide and nCloseNAPromptHits_Opposite != 0) continue; hAnaCutFlow -> Fill(currentcut++);
			
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

			// Apply radon map
		    double weight = 1;    
		    if (strcmp(d->GetName(), "SWire_Bi214")  or 
				strcmp(d->GetName(), "Swire_Pb214") )  weight = radonWeight;
		    if (strcmp(d->GetName(), "SFoil_Bi214")  or
		        strcmp(d->GetName(), "SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (strcmp(d->GetName(), "SWire_Bi210") )  weight = bi210Weight;
		
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
			 
		    double tot_e = el_energy_[0] + el_energy_[1];
			
		    if (run < 3396) {
		      
		        histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1", d->GetName()) ) -> Fill(tot_e);

		        if (el_side_[0] == el_side_[1]) {
					if (el_side_[0] == 0) {
						histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_SS_In", d->GetName()) ) -> Fill(tot_e);
		          	} else {
						histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_SS_Out", d->GetName()) ) -> Fill(tot_e);
		          	}
		        } else {
					histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1_OS", d->GetName()) ) -> Fill(tot_e);
		        }

		    } else {
				
				histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2", d->GetName()) ) -> Fill(tot_e);

		        if (el_side_[0] == el_side_[1]) {
		          if (el_side_[0] == 0) {
		            histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_SS_In", d->GetName()) ) -> Fill(tot_e);
		          } else {
		            histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_SS_Out", d->GetName()) ) -> Fill(tot_e);
		          }
		        } else {
					histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2_OS", d->GetName()) ) -> Fill(tot_e);
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
	    cutNames->push_back("Energy one electron > 200 keV ");
		cutNames->push_back("Internal probability < 0.01");
		cutNames->push_back("External probability > 0.04");
		cutNames->push_back("|dz_vtx| < 8 cm and radial distance < 4");

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
		histo_collection->Add( new TH1D( TString::Format("%s_h_vertexSector"           , d->GetName()) , "; Sector Number; No.Events", 200, 0, 20                             ) );
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

		Long64_t nbytes = 0, nb = 0;	

	    for (Long64_t iEvt = 0; iEvt < nentries; iEvt++) {
		
		    if (iEvt % 500000 == 0) {
		      std::cout << "\t " << iEvt << "/" << nentries << std::endl;
		    }
		
	       	nb = tree->GetEntry(iEvt); nbytes += nb;
				
			unsigned int currentcut = 0;
			hAnaCutFlow -> Fill(currentcut++);

			// Implement selection
		    if (sectorId != 18)                                    continue; hAnaCutFlow -> Fill(currentcut++);
		    if (el_energy_[0] < 0.2 and el_energy_[1] < 0.2)       continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probInt > 0.01)                                    continue; hAnaCutFlow -> Fill(currentcut++);
		    if (probExt_0_to_1 < 0.04 and probExt_1_to_0 < 0.04)   continue; hAnaCutFlow -> Fill(currentcut++);

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
		    if (strcmp(d->GetName(), "SWire_Bi214")  or 
				strcmp(d->GetName(), "Swire_Pb214") )  weight = radonWeight;
		    if (strcmp(d->GetName(), "SFoil_Bi214")  or
		        strcmp(d->GetName(), "SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (strcmp(d->GetName(), "SWire_Bi210") )  weight = bi210Weight;
		
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
			 
		    double tot_e = el_energy_[0] + el_energy_[1];
			
		    if (run < 3396) {
				histo_collection->Find(TString::Format("%s_h_tot_e_energy_P1", d->GetName()) ) -> Fill(tot_e);
			}
		    else {
				histo_collection->Find(TString::Format("%s_h_tot_e_energy_P2", d->GetName()) ) -> Fill(tot_e);		      
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
	// STATUS: TODO
	//	
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneGammaInternal( DataSet *d ){
		
		return kTRUE;
	}		
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process one electron one gamma external channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: TODO
	//	
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneGammaExternal( DataSet *d ){
		return kTRUE;
	}	
	
	//////////////////////////////////////////////////////////////////////////////				
	//
	// Process one electron two gamma internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: TODO
	//		
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronTwoGammaInternal( DataSet *d ){

		
		return kTRUE;
	}		
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process one electron one alpha channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: TODO
	//		
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessOneElectronOneAlpha( DataSet *d ){
		
		return kTRUE;
	}

}
