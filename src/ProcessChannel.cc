
#include "TROOT.h"
#include "TIterator.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TVector3.h"

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

	// Set channel to process
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
		histo_collection->Add( new TH2D ( TString::Format("%s_h_vertex"                , d->GetName()) , "; Sector ; Z_{vertex} / cm ; ", 500, 18, 19 , 520, -130, 130        ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_vertexSector"          , d->GetName()) , "; Sector Number; No.Events", 200, 0, 20                            ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexZ"           , d->GetName()) , "; True - Z_{vertex} / cm ; No.Events / cm", 260, -130, 130         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueVertexSector"      , d->GetName()) , "; True - Sector Number; No.Events", 200, 0, 20                     ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sectorId"              , d->GetName()) , "; Sector; No.Events",  21, -0.5, 20.5                              ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_sourceId"              , d->GetName()) , "; Source; No.Events",   4, -1.5, 2.5                               ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSectorId"          , d->GetName()) , "; True Sector; No.Events",  21, -0.5, 20.5                         ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_trueSourceId"          , d->GetName()) , "; True Source; No.Events",   4, -1.5, 2.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_nGammas"               , d->GetName()) , "; No. #gammas; No.Events", 15, -0.5, 14.5                          ) );
		histo_collection->Add( new TH1D ( TString::Format("%s_h_totGammaEnergy"        , d->GetName()) , "; #Sigma E_{#gamma}^{high} / MeV; No.Events / 0.05 MeV", 50, 0, 2.5) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_totGammaLowEnergy"     , d->GetName()) , "; #Sigma E_{#gamma}^{low} / MeV; No.Events / 0.02 MeV", 50, 0, 1   ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nFarNAPromptHits"      , d->GetName()) , "; N. far prompt hits; No.Events", 21, -0.5, 20.5                   ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nCloseNAPromptHits"    , d->GetName()) , "; N. close prompt hits; No.Events", 21, -0.5, 20.5                 ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nFarDelayedHits"       , d->GetName()) , "; N. far delayed hits; No.Events", 21, -0.5, 20.5                  ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nCloseDelayedHits"     , d->GetName()) , "; N. close delayed hits; No.Events", 21, -0.5, 20.5                ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nFarDelayedClusters"   , d->GetName()) , "; N. far delayed clusters; No.Events", 21, -0.5, 20.5              ) );
		//histo_collection->Add( new TH1D ( TString::Format("%s_h_nCloseDelayedCslusters", d->GetName()) , "; N. close delayed clusters; No.Events", 21, -0.5, 20.5            ) );
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
		    double weight = 1;    
		    if (strcmp(d->GetName(), "SWire_Bi214")  or 
				strcmp(d->GetName(), "Swire_Pb214") )  weight = radonWeight;
		    if (strcmp(d->GetName(), "SFoil_Bi214")  or
		        strcmp(d->GetName(), "SFoil_Pb214") )  weight = sfoilRadonWeight;
		    if (strcmp(d->GetName(), "SWire_Bi210") )  weight = bi210Weight;
		
			// Fill histogram
			histo_collection->Find( TString::Format("%s_h_run"              , d->GetName()) ) -> Fill(run, weight);
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
	
		// Delete explicit histogram declaration
		delete hAnaCutFlow; delete hRecoCutFlow;
		
		// Delete the remaining crap
		histo_collection->Delete();	
		f0->Close() ; f1->Close() ; 
		_InputFile->Close(); _OutputFile->Close();
	
		return kTRUE;
	
		
	}
	
	//////////////////////////////////////////////////////////////////////////////		
	//
	// Process two electrons internal channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: TODO
	//
	//////////////////////////////////////////////////////////////////////////////		
	bool ProcessTwoElectronInternal( DataSet *d ){
		return kTRUE;
	}
	
	//////////////////////////////////////////////////////////////////////////////			
	//
	// Process two electrons external channel: 
	// Apply cut and make plot over data set 'd'
	// 
	// STATUS: TODO
	//
	//////////////////////////////////////////////////////////////////////////////
	bool ProcessTwoElectronExternal( DataSet *d ){
				
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