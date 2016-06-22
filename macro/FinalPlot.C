void FinalPlot(){

	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");

    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);
	
	gStyle->SetTitleX(0.14);
	gStyle->SetTitleY(0.93);

	DrawAlphaTrackLength();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf(");
	//
	DrawCrossingElectronEnergy();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
	//	
	DrawSingleElectronEnergy();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
	//
	DrawTotalElectronGammaEnergy();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawTwoElectronEnergy();
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
	//
	DrawTwoElectronEnergy("MM");
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawTwoElectronEnergy("RHC_L");
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawTwoElectronEnergy("RHC_E");
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawTwoElectronEnergy("M1");
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawTwoElectronEnergyZoom();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
	//
	//DrawBDT("MM");
	//
	//(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	//DrawBDT("RHC_L");
	//
	//(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	//DrawBDT("RHC_E");
	//
	//(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	//DrawBDT("M1");
	//
	//(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
	//
	DrawFoilRegions();
    //
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf");
    //
	DrawComp();
	//
	(TPad*)gROOT->GetSelectedPad()->Print("FinalPlots.pdf)");
	//
	(TPad*)gROOT->GetSelectedPad()->Print("Bb2nuResultComparison.pdf");
	
	
}

void DrawFoilRegions(){
	
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root");
		
	TDirectory * d = (TDirectory *) f->Get("Data");
		
	TH1D * h = (TH1D*) d->Get( "Data_h_vtx_z_vs_sect_all" );
	
    h->SetStats(kFALSE) ;
	
	h->GetYaxis()->CenterTitle(kTRUE) ;
	h->GetXaxis()->CenterTitle(kTRUE) ;
	h->GetZaxis()->CenterTitle(kTRUE) ;
	
	h->GetYaxis()->SetTitleOffset(1.4);
	h->GetXaxis()->SetTitleOffset(1.4);
	h->GetZaxis()->SetTitleOffset(2.0);
	
	h->GetZaxis()->SetTitle("No.Events");
	
	h->GetZaxis()->SetRangeUser(0,250.);
	h->GetXaxis()->SetRangeUser(18.08,19.0);

	h->GetXaxis()->SetNdivisions(105) ;	
	h->GetYaxis()->SetNdivisions(105) ;
	h->GetZaxis()->SetNdivisions(105) ;	
		
	TCanvas * Canvas = new TCanvas("FoilRegion", "FoilRegion", 500, 500);

	h->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");

	gPad->SetGridx(kFALSE);
	gPad->SetGridy(kFALSE);

    gPad->SetTickx() ;
    gPad->SetTicky() ;

	gPad->SetTopMargin(0.15);
	gPad->SetBottomMargin(0.15);
	gPad->SetRightMargin(0.20);

	h->Draw("colz");
	
	Canvas->Update();
	
};

void DrawAlphaTrackLength () {

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronOneAlphaHistos", "OneElectronOneAlphaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronOneAlphaHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}

    TH1D * Data = (TH1D*) hcoll->Find( "Data_h_alphaLength" );

	Double_t Cd116_Bi214_P1_IN_IN_weight   = 4.99306 ;   
	Double_t Mylar_Bi214_P1_IN_IN_weight   = 31.2566 ;   
	Double_t SWire_Bi214_P1_IN_IN_weight   = 563.181 ;   
	Double_t SFoil_Bi214_P1_IN_IN_weight   = 130.121 ;   
	Double_t Cd116_Bi214_P1_OUT_OUT_weight = 6.89752 ;   
	Double_t Mylar_Bi214_P1_OUT_OUT_weight = 44.3406 ;   
	Double_t SWire_Bi214_P1_OUT_OUT_weight = 580.751 ;   
	Double_t SFoil_Bi214_P1_OUT_OUT_weight = 266.749 ;   
	Double_t Cd116_Bi214_P1_IN_OUT_weight  = 4.68499 ;   
	Double_t Mylar_Bi214_P1_IN_OUT_weight  = 22.4139 ;   
	Double_t SWire_Bi214_P1_IN_OUT_weight  = 272.44  ;  
	Double_t SFoil_Bi214_P1_IN_OUT_weight  = 130.88  ;  
	Double_t Cd116_Bi214_P1_OUT_IN_weight  = 5.43017 ;   
	Double_t Mylar_Bi214_P1_OUT_IN_weight  = 26.823  ;  
	Double_t SWire_Bi214_P1_OUT_IN_weight  = 348.619 ;   
	Double_t SFoil_Bi214_P1_OUT_IN_weight  = 103.776 ;   
	Double_t Cd116_Bi214_P2_IN_IN_weight   = 27.5512 ;   
	Double_t Mylar_Bi214_P2_IN_IN_weight   = 176.294 ;   
	Double_t SWire_Bi214_P2_IN_IN_weight   = 370.251 ;   
	Double_t SFoil_Bi214_P2_IN_IN_weight   = 85.5463 ;   
	Double_t Cd116_Bi214_P2_OUT_OUT_weight = 41.6527 ;   
	Double_t Mylar_Bi214_P2_OUT_OUT_weight = 263.866 ;   
	Double_t SWire_Bi214_P2_OUT_OUT_weight = 598.877 ;   
	Double_t SFoil_Bi214_P2_OUT_OUT_weight = 115.098 ;   
	Double_t Cd116_Bi214_P2_IN_OUT_weight  = 26.0825 ;   
	Double_t Mylar_Bi214_P2_IN_OUT_weight  = 123.094 ;   
	Double_t SWire_Bi214_P2_IN_OUT_weight  = 252.426 ;   
	Double_t SFoil_Bi214_P2_IN_OUT_weight  = 52.4047 ;   
	Double_t Cd116_Bi214_P2_OUT_IN_weight  = 33.6313 ;   
	Double_t Mylar_Bi214_P2_OUT_IN_weight  = 159.959 ;   
	Double_t SWire_Bi214_P2_OUT_IN_weight  = 270.566 ;   
	Double_t SFoil_Bi214_P2_OUT_IN_weight  = 76.7008 ;   

	TH1D * Cd116_Bi214_P1_IN_IN   = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aIn"   );  Cd116_Bi214_P1_IN_IN   -> Scale( Cd116_Bi214_P1_IN_IN_weight   / Cd116_Bi214_P1_IN_IN->Integral() );
	TH1D * Mylar_Bi214_P1_IN_IN   = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aIn"   );  Mylar_Bi214_P1_IN_IN   -> Scale( Mylar_Bi214_P1_IN_IN_weight   / Mylar_Bi214_P1_IN_IN->Integral() );
    TH1D * SWire_Bi214_P1_IN_IN   = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aIn"   );  SWire_Bi214_P1_IN_IN   -> Scale( SWire_Bi214_P1_IN_IN_weight   / SWire_Bi214_P1_IN_IN->Integral() );
    TH1D * SFoil_Bi214_P1_IN_IN   = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aIn"   );  SFoil_Bi214_P1_IN_IN   -> Scale( SFoil_Bi214_P1_IN_IN_weight   / SFoil_Bi214_P1_IN_IN->Integral() );
    TH1D * Cd116_Bi214_P1_OUT_OUT = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aOut" );  Cd116_Bi214_P1_OUT_OUT -> Scale( Cd116_Bi214_P1_OUT_OUT_weight / Cd116_Bi214_P1_OUT_OUT->Integral() );
    TH1D * Mylar_Bi214_P1_OUT_OUT = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aOut" );  Mylar_Bi214_P1_OUT_OUT -> Scale( Mylar_Bi214_P1_OUT_OUT_weight / Mylar_Bi214_P1_OUT_OUT->Integral() );
    TH1D * SWire_Bi214_P1_OUT_OUT = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aOut" );  SWire_Bi214_P1_OUT_OUT -> Scale( SWire_Bi214_P1_OUT_OUT_weight / SWire_Bi214_P1_OUT_OUT->Integral() );
    TH1D * SFoil_Bi214_P1_OUT_OUT = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aOut" );  SFoil_Bi214_P1_OUT_OUT -> Scale( SFoil_Bi214_P1_OUT_OUT_weight / SFoil_Bi214_P1_OUT_OUT->Integral() );
    TH1D * Cd116_Bi214_P1_IN_OUT  = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eIn_aOut"  );  Cd116_Bi214_P1_IN_OUT  -> Scale( Cd116_Bi214_P1_IN_OUT_weight  / Cd116_Bi214_P1_IN_OUT->Integral() );
    TH1D * Mylar_Bi214_P1_IN_OUT  = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eIn_aOut"  );  Mylar_Bi214_P1_IN_OUT  -> Scale( Mylar_Bi214_P1_IN_OUT_weight  / Mylar_Bi214_P1_IN_OUT->Integral() );
    TH1D * SWire_Bi214_P1_IN_OUT  = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eIn_aOut"  );  SWire_Bi214_P1_IN_OUT  -> Scale( SWire_Bi214_P1_IN_OUT_weight  / SWire_Bi214_P1_IN_OUT->Integral() );
    TH1D * SFoil_Bi214_P1_IN_OUT  = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eIn_aOut"  );  SFoil_Bi214_P1_IN_OUT  -> Scale( SFoil_Bi214_P1_IN_OUT_weight  / SFoil_Bi214_P1_IN_OUT->Integral() );
    TH1D * Cd116_Bi214_P1_OUT_IN  = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P1_eOut_aIn"  );  Cd116_Bi214_P1_OUT_IN  -> Scale( Cd116_Bi214_P1_OUT_IN_weight  / Cd116_Bi214_P1_OUT_IN->Integral() );
    TH1D * Mylar_Bi214_P1_OUT_IN  = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P1_eOut_aIn"  );  Mylar_Bi214_P1_OUT_IN  -> Scale( Mylar_Bi214_P1_OUT_IN_weight  / Mylar_Bi214_P1_OUT_IN->Integral() );
    TH1D * SWire_Bi214_P1_OUT_IN  = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P1_eOut_aIn"  );  SWire_Bi214_P1_OUT_IN  -> Scale( SWire_Bi214_P1_OUT_IN_weight  / SWire_Bi214_P1_OUT_IN->Integral() );
    TH1D * SFoil_Bi214_P1_OUT_IN  = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P1_eOut_aIn"  );  SFoil_Bi214_P1_OUT_IN  -> Scale( SFoil_Bi214_P1_OUT_IN_weight  / SFoil_Bi214_P1_OUT_IN->Integral() );
    TH1D * Cd116_Bi214_P2_IN_IN   = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aIn"   );  Cd116_Bi214_P2_IN_IN   -> Scale( Cd116_Bi214_P2_IN_IN_weight   / Cd116_Bi214_P2_IN_IN->Integral() );
    TH1D * Mylar_Bi214_P2_IN_IN   = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aIn"   );  Mylar_Bi214_P2_IN_IN   -> Scale( Mylar_Bi214_P2_IN_IN_weight   / Mylar_Bi214_P2_IN_IN->Integral() );
    TH1D * SWire_Bi214_P2_IN_IN   = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aIn"   );  SWire_Bi214_P2_IN_IN   -> Scale( SWire_Bi214_P2_IN_IN_weight   / SWire_Bi214_P2_IN_IN->Integral() );
    TH1D * SFoil_Bi214_P2_IN_IN   = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aIn"   );  SFoil_Bi214_P2_IN_IN   -> Scale( SFoil_Bi214_P2_IN_IN_weight   / SFoil_Bi214_P2_IN_IN->Integral() );
    TH1D * Cd116_Bi214_P2_OUT_OUT = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aOut" );  Cd116_Bi214_P2_OUT_OUT -> Scale( Cd116_Bi214_P2_OUT_OUT_weight / Cd116_Bi214_P2_OUT_OUT->Integral() );
    TH1D * Mylar_Bi214_P2_OUT_OUT = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aOut" );  Mylar_Bi214_P2_OUT_OUT -> Scale( Mylar_Bi214_P2_OUT_OUT_weight / Mylar_Bi214_P2_OUT_OUT->Integral() );
    TH1D * SWire_Bi214_P2_OUT_OUT = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aOut" );  SWire_Bi214_P2_OUT_OUT -> Scale( SWire_Bi214_P2_OUT_OUT_weight / SWire_Bi214_P2_OUT_OUT->Integral() );
    TH1D * SFoil_Bi214_P2_OUT_OUT = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aOut" );  SFoil_Bi214_P2_OUT_OUT -> Scale( SFoil_Bi214_P2_OUT_OUT_weight / SFoil_Bi214_P2_OUT_OUT->Integral() );
    TH1D * Cd116_Bi214_P2_IN_OUT  = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eIn_aOut"  );  Cd116_Bi214_P2_IN_OUT  -> Scale( Cd116_Bi214_P2_IN_OUT_weight  / Cd116_Bi214_P2_IN_OUT->Integral() );
    TH1D * Mylar_Bi214_P2_IN_OUT  = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eIn_aOut"  );  Mylar_Bi214_P2_IN_OUT  -> Scale( Mylar_Bi214_P2_IN_OUT_weight  / Mylar_Bi214_P2_IN_OUT->Integral() );
    TH1D * SWire_Bi214_P2_IN_OUT  = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eIn_aOut"  );  SWire_Bi214_P2_IN_OUT  -> Scale( SWire_Bi214_P2_IN_OUT_weight  / SWire_Bi214_P2_IN_OUT->Integral() );
    TH1D * SFoil_Bi214_P2_IN_OUT  = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eIn_aOut"  );  SFoil_Bi214_P2_IN_OUT  -> Scale( SFoil_Bi214_P2_IN_OUT_weight  / SFoil_Bi214_P2_IN_OUT->Integral() );
    TH1D * Cd116_Bi214_P2_OUT_IN  = ( TH1D* ) hcoll->Find( "Cd116_Bi214_h_alphaLength_P2_eOut_aIn"  );  Cd116_Bi214_P2_OUT_IN  -> Scale( Cd116_Bi214_P2_OUT_IN_weight  / Cd116_Bi214_P2_OUT_IN->Integral() );
    TH1D * Mylar_Bi214_P2_OUT_IN  = ( TH1D* ) hcoll->Find( "Mylar_Bi214_h_alphaLength_P2_eOut_aIn"  );  Mylar_Bi214_P2_OUT_IN  -> Scale( Mylar_Bi214_P2_OUT_IN_weight  / Mylar_Bi214_P2_OUT_IN->Integral() );
    TH1D * SWire_Bi214_P2_OUT_IN  = ( TH1D* ) hcoll->Find( "SWire_Bi214_h_alphaLength_P2_eOut_aIn"  );  SWire_Bi214_P2_OUT_IN  -> Scale( SWire_Bi214_P2_OUT_IN_weight  / SWire_Bi214_P2_OUT_IN->Integral() );
    TH1D * SFoil_Bi214_P2_OUT_IN  = ( TH1D* ) hcoll->Find( "SFoil_Bi214_h_alphaLength_P2_eOut_aIn"  );  SFoil_Bi214_P2_OUT_IN  -> Scale( SFoil_Bi214_P2_OUT_IN_weight  / SFoil_Bi214_P2_OUT_IN->Integral() );
	
	
	TH1D * Cd116_Bi214 = Cd116_Bi214_P1_IN_IN->Clone("Cd116_Bi214");
	Cd116_Bi214->Add(Cd116_Bi214_P1_OUT_OUT);
	Cd116_Bi214->Add(Cd116_Bi214_P1_IN_OUT);
	Cd116_Bi214->Add(Cd116_Bi214_P1_OUT_IN);
	Cd116_Bi214->Add(Cd116_Bi214_P2_IN_IN);
	Cd116_Bi214->Add(Cd116_Bi214_P2_OUT_OUT);
	Cd116_Bi214->Add(Cd116_Bi214_P2_IN_OUT);
	Cd116_Bi214->Add(Cd116_Bi214_P2_OUT_IN);
		
	TH1D * Mylar_Bi214 = Mylar_Bi214_P1_IN_IN->Clone("Mylar_Bi214");	
	Mylar_Bi214->Add(Mylar_Bi214_P1_OUT_OUT);
	Mylar_Bi214->Add(Mylar_Bi214_P1_IN_OUT) ;
	Mylar_Bi214->Add(Mylar_Bi214_P1_OUT_IN) ;
	Mylar_Bi214->Add(Mylar_Bi214_P2_IN_IN)  ;
	Mylar_Bi214->Add(Mylar_Bi214_P2_OUT_OUT);
	Mylar_Bi214->Add(Mylar_Bi214_P2_IN_OUT) ;
	Mylar_Bi214->Add(Mylar_Bi214_P2_OUT_IN) ;
	
	TH1D * SFoil_Bi214 = SFoil_Bi214_P1_IN_IN->Clone("SFoil_Bi214");	
	SFoil_Bi214->Add(SFoil_Bi214_P1_OUT_OUT);
	SFoil_Bi214->Add(SFoil_Bi214_P1_IN_OUT);
	SFoil_Bi214->Add(SFoil_Bi214_P1_OUT_IN);
	SFoil_Bi214->Add(SFoil_Bi214_P2_IN_IN);
	SFoil_Bi214->Add(SFoil_Bi214_P2_OUT_OUT);
	SFoil_Bi214->Add(SFoil_Bi214_P2_IN_OUT);
	SFoil_Bi214->Add(SFoil_Bi214_P2_OUT_IN);

	TH1D * SWire_Bi214 = SWire_Bi214_P1_IN_IN->Clone("SWire_Bi214");	
	SWire_Bi214->Add(SWire_Bi214_P1_OUT_OUT);
	SWire_Bi214->Add(SWire_Bi214_P1_IN_OUT);
	SWire_Bi214->Add(SWire_Bi214_P1_OUT_IN);
	SWire_Bi214->Add(SWire_Bi214_P2_IN_IN);
	SWire_Bi214->Add(SWire_Bi214_P2_OUT_OUT);
	SWire_Bi214->Add(SWire_Bi214_P2_IN_OUT);
	SWire_Bi214->Add(SWire_Bi214_P2_OUT_IN);

	
	Cd116_Bi214->SetFillColor( kOrange + 10 );
	Mylar_Bi214->SetFillColor( kGreen  +  1 );
	SFoil_Bi214->SetFillColor( kViolet +  0 );
	SWire_Bi214->SetFillColor( kAzure  +  1 );
	

	THStack * Stack = new THStack("stack","stack");
	Stack->Add( Cd116_Bi214 ); 
	Stack->Add( Mylar_Bi214 ); 
	Stack->Add( SFoil_Bi214 ); 
	Stack->Add( SWire_Bi214 ); 

	TH1D * Sum = Cd116_Bi214->Clone("Sum");
	Sum->Add( Mylar_Bi214 ); 
	Sum->Add( SFoil_Bi214 ); 
	Sum->Add( SWire_Bi214 ); 
	
	TCanvas * Canvas = new TCanvas("AlphaTrackLength", "AlphaTrackLength", 500, 500);
	
    Bool_t _LogScale    = kFALSE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;	
	
    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.017);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("#alpha track length (cm)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
    //Data->GetYaxis().SetRangeUser(1e-1,5e+3) ;
        
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.14) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(0.25,1.75) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-8,8) ;
            
    TLegend * Leg = new TLegend(0.73,0.8,0.92,0.52);

    Leg->SetNColumns(1);
    Leg->SetLineWidth(0);

    Leg->AddEntry( Cd116_Bi214 , "Foil bulk"    , "F"  ); 
    Leg->AddEntry( Mylar_Bi214 , "Mylar bulk"   , "F"  ); 
    Leg->AddEntry( SFoil_Bi214 , "Foil surface" , "F"  ); 
    Leg->AddEntry( SWire_Bi214 , "Wire surface" , "F"  ); 
    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" );  

   
    pad1->cd() ;    
    Data->Draw(""); 
    Stack->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();

    pad2->cd() ;
    Ratio->Draw("P0"); 
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
	Ratio->Draw("P0same"); 

    pad3->cd(); 
    Res->Draw("P0"); 
	pad3->Update();
	TLine * LineRes = new TLine(pad3->GetUxmin(),0,pad3->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same"); 

    pad1->cd() ;
    Leg->Draw();
	
	Canvas->cd();
	Canvas->Update();

};

void DrawCrossingElectronEnergy () {
	
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSampleBkg.C+");
	
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/TwoElectronExtHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	
	TH1D * Data = (TH1D*) hcoll->Find( "Data_h_tot_e_energy_P1" );
	Data->Add( hcoll->Find( "Data_h_tot_e_energy_P2" ));
	
    Double_t Cd116_Bi214_weight    =  0.0183795;
    Double_t Cd116_Pb214_weight    = 0.00145869;
    Double_t Mylar_Bi214_weight    =  0.0741864;
 //   Double_t Mylar_Pb214_weight    =          0;
    Double_t SWire_Bi214_weight    =    915.745;
    Double_t SWire_Pb214_weight    =    12.6295;
    Double_t SFoil_Bi214_weight    =   0.179074;
 //   Double_t SFoil_Pb214_weight    =          0;
    Double_t SScin_Bi214_weight    =    1344.27;
    Double_t SScin_Pb214_weight    =     13.789;
    Double_t PMT_Tl208_weight      =      21927;
    Double_t PMT_Ac228_weight      =    1662.52;
    Double_t FeShield_Tl208_weight =    832.019;
    Double_t FeShield_Ac228_weight =    49.3192;
    Double_t Air_Tl208_weight      =    472.979;
    Double_t CuTower_Co60_weight   =    2331.63;
    Double_t SScin_Bi210_weight    =    2107.29;
    Double_t MuMetal_Pa234m_weight =    134.964;
    Double_t Air_Bi214_weight      =    3933.27;
 //   Double_t Air_Pb214_P1_weight   =          0;
    Double_t PMT_Bi214_weight      =    21694.2;
    Double_t FeShield_Bi214_weight =    19984.4;
    Double_t ScintPet_K40_weight   =    1264.31;
    Double_t ScintOut_K40_weight   =    2016.97;
    Double_t ScintInn_K40_weight   =    3550.68;
    Double_t PMT_K40_weight        =    12472.1;
	
	TH1F * Cd116_Bi214    = (TH1F*) hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P1"    )->Clone( "Cd116_Bi214"    ) ; Cd116_Bi214    -> Add( (TH1F*) hcoll->Find( "Cd116_Bi214_h_tot_e_energy_P2"    )); Cd116_Bi214    -> Scale( Cd116_Bi214_weight    / Cd116_Bi214    -> Integral() );
	TH1F * Cd116_Pb214    = (TH1F*) hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P1" )->Clone( "Cd116_Pb214"    ) ; Cd116_Pb214    -> Add( (TH1F*) hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy_P2" )); Cd116_Pb214    -> Scale( Cd116_Pb214_weight    / Cd116_Pb214    -> Integral() );
	TH1F * Mylar_Bi214    = (TH1F*) hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P1"    )->Clone( "Mylar_Bi214"    ) ; Mylar_Bi214    -> Add( (TH1F*) hcoll->Find( "Mylar_Bi214_h_tot_e_energy_P2"    )); Mylar_Bi214    -> Scale( Mylar_Bi214_weight    / Mylar_Bi214    -> Integral() );
//	TH1F * Mylar_Pb214    = (TH1F*) hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P1"    )->Clone( "Mylar_Pb214"    ) ; Mylar_Pb214    -> Add( (TH1F*) hcoll->Find( "Mylar_Pb214_h_tot_e_energy_P2"    )); Mylar_Pb214    -> Scale( Mylar_Pb214_weight    / Mylar_Pb214    -> Integral() );
	TH1F * SWire_Bi214    = (TH1F*) hcoll->Find( "SWire_Bi214_h_tot_e_energy_P1"    )->Clone( "SWire_Bi214"    ) ; SWire_Bi214    -> Add( (TH1F*) hcoll->Find( "SWire_Bi214_h_tot_e_energy_P2"    )); SWire_Bi214    -> Scale( SWire_Bi214_weight    / SWire_Bi214    -> Integral() );
	TH1F * SWire_Pb214    = (TH1F*) hcoll->Find( "SWire_Pb214_h_tot_e_energy_P1"    )->Clone( "SWire_Pb214"    ) ; SWire_Pb214    -> Add( (TH1F*) hcoll->Find( "SWire_Pb214_h_tot_e_energy_P2"    )); SWire_Pb214    -> Scale( SWire_Pb214_weight    / SWire_Pb214    -> Integral() );
	TH1F * SFoil_Bi214    = (TH1F*) hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P1"    )->Clone( "SFoil_Bi214"    ) ; SFoil_Bi214    -> Add( (TH1F*) hcoll->Find( "SFoil_Bi214_h_tot_e_energy_P2"    )); SFoil_Bi214    -> Scale( SFoil_Bi214_weight    / SFoil_Bi214    -> Integral() );
//	TH1F * SFoil_Pb214    = (TH1F*) hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P1"    )->Clone( "SFoil_Pb214"    ) ; SFoil_Pb214    -> Add( (TH1F*) hcoll->Find( "SFoil_Pb214_h_tot_e_energy_P2"    )); SFoil_Pb214    -> Scale( SFoil_Pb214_weight    / SFoil_Pb214    -> Integral() );
	TH1F * SScin_Bi214    = (TH1F*) hcoll->Find( "SScin_Bi214_h_tot_e_energy_P1"    )->Clone( "SScin_Bi214"    ) ; SScin_Bi214    -> Add( (TH1F*) hcoll->Find( "SScin_Bi214_h_tot_e_energy_P2"    )); SScin_Bi214    -> Scale( SScin_Bi214_weight    / SScin_Bi214    -> Integral() ); 
	TH1F * SScin_Pb214    = (TH1F*) hcoll->Find( "SScin_Pb214_h_tot_e_energy_P1"    )->Clone( "SScin_Pb214"    ) ; SScin_Pb214    -> Add( (TH1F*) hcoll->Find( "SScin_Pb214_h_tot_e_energy_P2"    )); SScin_Pb214    -> Scale( SScin_Pb214_weight    / SScin_Pb214    -> Integral() ); 
	TH1F * PMT_Tl208      = (TH1F*) hcoll->Find( "PMT_Tl208_h_tot_e_energy_P1"      )->Clone( "PMT_Tl208"      ) ; PMT_Tl208      -> Add( (TH1F*) hcoll->Find( "PMT_Tl208_h_tot_e_energy_P2"      )); PMT_Tl208      -> Scale( PMT_Tl208_weight      / PMT_Tl208      -> Integral() ); 
	TH1F * PMT_Ac228      = (TH1F*) hcoll->Find( "PMT_Ac228_h_tot_e_energy_P1"      )->Clone( "PMT_Ac228"      ) ; PMT_Ac228      -> Add( (TH1F*) hcoll->Find( "PMT_Ac228_h_tot_e_energy_P2"      )); PMT_Ac228      -> Scale( PMT_Ac228_weight      / PMT_Ac228      -> Integral() ); 
	TH1F * FeShield_Tl208 = (TH1F*) hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P1" )->Clone( "FeShield_Tl208" ) ; FeShield_Tl208 -> Add( (TH1F*) hcoll->Find( "FeShield_Tl208_h_tot_e_energy_P2" )); FeShield_Tl208 -> Scale( FeShield_Tl208_weight / FeShield_Tl208 -> Integral() ); 
	TH1F * FeShield_Ac228 = (TH1F*) hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P1" )->Clone( "FeShield_Ac228" ) ; FeShield_Ac228 -> Add( (TH1F*) hcoll->Find( "FeShield_Ac228_h_tot_e_energy_P2" )); FeShield_Ac228 -> Scale( FeShield_Ac228_weight / FeShield_Ac228 -> Integral() ); 
	TH1F * Air_Tl208      = (TH1F*) hcoll->Find( "Air_Tl208_h_tot_e_energy_P1"      )->Clone( "Air_Tl208"      ) ;                                                                                          Air_Tl208      -> Scale( Air_Tl208_weight      / Air_Tl208      -> Integral() ); 
	TH1F * CuTower_Co60   = (TH1F*) hcoll->Find( "CuTower_Co60_h_tot_e_energy_P1"   )->Clone( "CuTower_Co60"   ) ; CuTower_Co60   -> Add( (TH1F*) hcoll->Find( "CuTower_Co60_h_tot_e_energy_P2"   )); CuTower_Co60   -> Scale( CuTower_Co60_weight   / CuTower_Co60   -> Integral() ); 
	TH1F * SScin_Bi210    = (TH1F*) hcoll->Find( "SScin_Bi210_h_tot_e_energy_P1"    )->Clone( "SScin_Bi210"    ) ; SScin_Bi210    -> Add( (TH1F*) hcoll->Find( "SScin_Bi210_h_tot_e_energy_P2"    )); SScin_Bi210    -> Scale( SScin_Bi210_weight    / SScin_Bi210    -> Integral() ); 
	TH1F * MuMetal_Pa234m = (TH1F*) hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P1" )->Clone( "MuMetal_Pa234m" ) ; MuMetal_Pa234m -> Add( (TH1F*) hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy_P2" )); MuMetal_Pa234m -> Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m -> Integral() ); 
	TH1F * Air_Bi214      = (TH1F*) hcoll->Find( "Air_Bi214_h_tot_e_energy_P1"      )->Clone( "Air_Bi214"      ) ;                                                                                          Air_Bi214      -> Scale( Air_Bi214_weight      / Air_Bi214      -> Integral() ); 
//	TH1F * Air_Pb214      = (TH1F*) hcoll->Find( "Air_Pb214_h_tot_e_energy_P1"      )->Clone( "Air_Pb214"      ) ;                                                                                          Air_Pb214      -> Scale( Air_Pb214_weight      / Air_Pb214      -> Integral() ); 
	TH1F * PMT_Bi214      = (TH1F*) hcoll->Find( "PMT_Bi214_h_tot_e_energy_P1"      )->Clone( "PMT_Bi214"      ) ; PMT_Bi214      -> Add( (TH1F*) hcoll->Find( "PMT_Bi214_h_tot_e_energy_P2"      )); PMT_Bi214      -> Scale( PMT_Bi214_weight      / PMT_Bi214      -> Integral() ); 
	TH1F * FeShield_Bi214 = (TH1F*) hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P1" )->Clone( "FeShield_Bi214" ) ; FeShield_Bi214 -> Add( (TH1F*) hcoll->Find( "FeShield_Bi214_h_tot_e_energy_P2" )); FeShield_Bi214 -> Scale( FeShield_Bi214_weight / FeShield_Bi214 -> Integral() ); 
	TH1F * ScintPet_K40   = (TH1F*) hcoll->Find( "ScintPet_K40_h_tot_e_energy_P1"   )->Clone( "ScintPet_K40"   ) ; ScintPet_K40   -> Add( (TH1F*) hcoll->Find( "ScintPet_K40_h_tot_e_energy_P2"   )); ScintPet_K40   -> Scale( ScintPet_K40_weight   / ScintPet_K40   -> Integral() ); 
	TH1F * ScintOut_K40   = (TH1F*) hcoll->Find( "ScintOut_K40_h_tot_e_energy_P1"   )->Clone( "ScintOut_K40"   ) ; ScintOut_K40   -> Add( (TH1F*) hcoll->Find( "ScintOut_K40_h_tot_e_energy_P2"   )); ScintOut_K40   -> Scale( ScintOut_K40_weight   / ScintOut_K40   -> Integral() ); 
	TH1F * ScintInn_K40   = (TH1F*) hcoll->Find( "ScintInn_K40_h_tot_e_energy_P1"   )->Clone( "ScintInn_K40"   ) ; ScintInn_K40   -> Add( (TH1F*) hcoll->Find( "ScintInn_K40_h_tot_e_energy_P2"   )); ScintInn_K40   -> Scale( ScintInn_K40_weight   / ScintInn_K40   -> Integral() ); 
	TH1F * PMT_K40        = (TH1F*) hcoll->Find( "PMT_K40_h_tot_e_energy_P1"        )->Clone( "PMT_K40"        ) ; PMT_K40        -> Add( (TH1F*) hcoll->Find( "PMT_K40_h_tot_e_energy_P2"        )); PMT_K40        -> Scale( PMT_K40_weight        / PMT_K40        -> Integral() ); 

	TH1D * Bi214Int = Cd116_Bi214 ->Clone("Bi214Int");
	Bi214Int->Add(Cd116_Pb214);
	Bi214Int->Add(Mylar_Bi214);
//	Bi214Int->Add(Mylar_Pb214);	
	
	TH1D * Radon = Cd116_Bi214 ->Clone("Radon");
	Radon->Add(SFoil_Bi214);
//	Radon->Add("SFoil_Pb214");
	Radon->Add(SWire_Bi214);
	Radon->Add(SWire_Pb214);
	
	TH1D * Bi214Scint = SScin_Bi214->Clone("Bi214Scint");
	Bi214Scint->Add(SScin_Pb214);

//	Bi214Air->Add(Air_Pb214);
	
	TH1D * Tl208FeShield = FeShield_Tl208->Clone("Tl208FeShield");
	Tl208FeShield->Add(FeShield_Ac228);
	
	TH1D * Tl208PMT = PMT_Tl208->Clone("Tl208PMT");
	Tl208PMT->Add(PMT_Ac228);	

	TH1D * K40Scint = ScintPet_K40->Clone("K40Scint");
	K40Scint->Add(ScintOut_K40);
	K40Scint->Add(ScintInn_K40);

	TH1D * Bi214Air      = Air_Bi214      -> Clone( "Bi214Air"      );	
	TH1D * Pa234mMuMetal = MuMetal_Pa234m -> Clone( "Pa234mMuMetal" );
	TH1D * Bi210Scint    = SScin_Bi210    -> Clone( "Bi210Scint"    );
	TH1D * Co60          = CuTower_Co60   -> Clone( "Co60"          );
	TH1D * Tl208Air	     = Air_Tl208      -> Clone( "Tl208Air"	    );
	TH1D * Bi214FeShield = FeShield_Bi214 -> Clone( "Bi214FeShield" );	
	TH1D * Bi214PMT	     = PMT_Bi214      -> Clone( "Bi214PMT"	    );
	TH1D * K40PMT	     = PMT_K40        -> Clone( "K40PMT"	    );
	
		
	Radon          -> SetFillColor( kAzure  +  1 );
	Pa234mMuMetal  -> SetFillColor( kViolet +  2 );
	Bi210Scint     -> SetFillColor( kViolet +  0 );
	Co60           -> SetFillColor( kViolet +  1 );
	Tl208Air       -> SetFillColor( kGreen  +  4 );
	Tl208FeShield  -> SetFillColor( kGreen  +  2 );
	Tl208PMT       -> SetFillColor( kGreen  +  1 );
	Bi214Air       -> SetFillColor( kAzure  +  9 );
	Bi214Int       -> SetFillColor( kAzure  + 11 );
	Bi214Scint     -> SetFillColor( kAzure  +  7 );
	Bi214FeShield  -> SetFillColor( kAzure  +  5 );
	Bi214PMT       -> SetFillColor( kAzure  +  6 );
	K40Scint       -> SetFillColor( kOrange +  8 );
	K40PMT         -> SetFillColor( kOrange + 10 );

	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Radon          );
	Stack->Add(Pa234mMuMetal  );
	Stack->Add(Bi210Scint     );
	Stack->Add(Co60           );
	Stack->Add(Tl208Air       );
	Stack->Add(Tl208FeShield  );
	Stack->Add(Tl208PMT       );
	Stack->Add(Bi214Air       );
	Stack->Add(Bi214Int       );
	Stack->Add(Bi214Scint     );
	Stack->Add(Bi214FeShield  );
	Stack->Add(Bi214PMT       );
	Stack->Add(K40Scint       );
	Stack->Add(K40PMT         );

	
	TH1D * Sum = Radon->Clone( "Sum" );
	Sum->Add(Pa234mMuMetal  );
	Sum->Add(Bi210Scint     );
	Sum->Add(Co60           );
	Sum->Add(Tl208Air       );
	Sum->Add(Tl208FeShield  );
	Sum->Add(Tl208PMT       );
	Sum->Add(Bi214Air       );
	Sum->Add(Bi214Int       );
	Sum->Add(Bi214Scint     );
	Sum->Add(Bi214FeShield  );
	Sum->Add(Bi214PMT       );
	Sum->Add(K40Scint       );
	Sum->Add(K40PMT         );
	
	TCanvas * Canvas = new TCanvas("CrossingElectronEnergy", "CrossingElectronEnergy", 500, 500);
	
    Bool_t _LogScale    = kFALSE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);

	
	
    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.01);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("E_{e} (MeV)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
    //Data->GetYaxis().SetRangeUser(1e-1,5e+3) ;
		
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.1) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(0.25,1.75) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-8,8) ;
            
    TLegend * Leg = new TLegend(0.50,0.8,0.92,0.20)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( Bi214Int      , "^{214}Bi Internal"  , "F" );
	Leg->AddEntry( Radon         , "Radon"              , "F" );
	Leg->AddEntry( Bi214Scint    , "^{214}Bi Scint"     , "F" );
	Leg->AddEntry( Bi214Air      , "^{214}Bi Air"       , "F" );
	Leg->AddEntry( Tl208FeShield , "^{208}Tl Fe Shield" , "F" );
	Leg->AddEntry( Tl208PMT      , "^{208}Tl PMT"       , "F" );
	Leg->AddEntry( K40Scint	     , "^{40}K Scint"       , "F" );
	Leg->AddEntry( K40PMT        , "^{40}K PMT"         , "F" );
	Leg->AddEntry( Pa234mMuMetal , "^{234m}Pa Mu Metal" , "F" );
	Leg->AddEntry( Bi210Scint    , "^{210}Bi Scint"     , "F" );
	Leg->AddEntry( Co60          , "^{60}Co"            , "F" );
	Leg->AddEntry( Tl208Air	     , "^{208}Tl Air"       , "F" );
	Leg->AddEntry( Bi214FeShield , "^{214}Tl Fe Shield" , "F" );
	Leg->AddEntry( Bi214PMT	     , "^{214}Bi PMT"       , "F" );

    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(0.5,10.0) ;    
	Ratio-> GetXaxis()->SetRangeUser(0.5,10.0) ;        
    Res  -> GetXaxis()->SetRangeUser(0.5,10.0) ;    

    pad1->cd() ;    
    Data->Draw(""); 
    Stack->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();
	
    pad2->cd() ;
    Ratio->Draw("P0"); 
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
	Ratio->Draw("P0same"); 

    pad3->cd(); 
    Res->Draw("P0"); 
	pad3->Update();
	TLine * LineRes = new TLine(pad2->GetUxmin(),0,pad2->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same"); 

    pad1->cd() ;
    Leg->Draw(); 
	
	Canvas->cd();
	Canvas->Update();
	
};	

void DrawSingleElectronEnergy () {
	
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample_OLD.C+");
	
	HistoCollection * hcoll= new HistoCollection("OneElectronHistos", "OneElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	
	TH1D * Data = (TH1D*) hcoll->Find( "Data_h_electronEnergy" );
	
	Double_t Cd116_Tl208_weight       = 187.223 ;
	Double_t Cd116_Ac228_weight       = 797.586 ;
	Double_t Cd116_Bi212_weight       = 1763.73 ;
	Double_t Cd116_Bi214_weight       = 1685.6  ;
	Double_t Cd116_Pb214_weight       = 93.9783 ;
	Double_t Mylar_Bi214_weight       = 953.484 ;
	Double_t Mylar_Pb214_weight       = 81.9187 ;
	Double_t SWire_Tl208_P1_weight    = 18.9865 ;
	Double_t SWire_Tl208_P2_weight    = 96.1741 ;
	Double_t SWire_Bi214_P1_weight    = 3665.58 ;
	Double_t SFoil_Bi214_P1_weight    = 540.298 ;
	Double_t SWire_Pb214_P1_weight    = 488.08  ;
	Double_t SFoil_Pb214_P1_weight    = 53.4516 ;
	Double_t SWire_Bi214_P2_weight    = 2964.42 ;
	Double_t SFoil_Bi214_P2_weight    = 260.012 ;
	Double_t SWire_Pb214_P2_weight    = 378.78  ;
	Double_t SFoil_Pb214_P2_weight    = 26.6665 ;
	Double_t FeShield_Bi214_weight    = 36562.6 ;
	Double_t FeShield_Tl208_weight    = 551.927 ;
	Double_t FeShield_Ac228_weight    = 175.834 ;
	Double_t PMT_K40_weight           = 13658.5 ;
	Double_t ScintInn_K40_weight      = 842.049 ;
	Double_t ScintOut_K40_weight      = 133.909 ;
	Double_t ScintPet_K40_weight      = 1975.38 ;
	Double_t PMT_Bi214_weight         = 20525.8 ;
	Double_t Air_Bi214_P1_weight      = 4042.14 ;
	Double_t Air_Pb214_P1_weight      = 15.1639 ;
	Double_t Air_Tl208_P1_weight      = 377.002 ;
	Double_t PMT_Tl208_weight         = 6890.06 ;
	Double_t PMT_Ac228_weight         = 4310.98 ;
	Double_t CuTower_Co60_weight      = 3014.71 ;
	Double_t Cd116_K40_cold_weight    = 30367.5 ;
	Double_t Cd116_Pa234m_cold_weight = 9193.24 ;
	Double_t SFoil_Bi210_cold_weight  = 74133.4 ;
	Double_t Cd116_K40_warm_weight    = 83986   ;
	Double_t Cd116_Pa234m_warm_weight = 26396.2 ;
	Double_t SFoil_Bi210_warm_weight  = 323019  ;
	Double_t SScin_Bi210_weight       = 4466.26 ;
	Double_t SScin_Bi214_weight       = 152.446 ;
	Double_t SScin_Pb214_weight       = 20.6376 ;
	Double_t MuMetal_Pa234m_weight    = 1104.01 ;
	Double_t SWire_Bi210_P1_weight    = 5256.47 ;
	Double_t SWire_Bi210_P2_weight    = 25863.3 ;
	Double_t Cd116_2b2n_m14_weight    = 16192.5 ;

		
	TH1D * Cd116_Tl208        = (TH1D*) hcoll->Find( "Cd116_Tl208_h_electronEnergy"    ); Cd116_Tl208       -> Scale(Cd116_Tl208_weight       / Cd116_Tl208       -> Integral()   );
    TH1D * Cd116_Ac228        = (TH1D*) hcoll->Find( "Cd116_Ac228_h_electronEnergy"    ); Cd116_Ac228       -> Scale(Cd116_Ac228_weight       / Cd116_Ac228       -> Integral()   );
    TH1D * Cd116_Bi212        = (TH1D*) hcoll->Find( "Cd116_Bi212_h_electronEnergy"    ); Cd116_Bi212       -> Scale(Cd116_Bi212_weight       / Cd116_Bi212       -> Integral()   );
    TH1D * Cd116_Bi214	      = (TH1D*) hcoll->Find( "Cd116_Bi214_h_electronEnergy"	   ); Cd116_Bi214       -> Scale(Cd116_Bi214_weight       / Cd116_Bi214       -> Integral()   );
    TH1D * Cd116_Pb214	      = (TH1D*) hcoll->Find( "Cd116_Pb214_VT_h_electronEnergy" ); Cd116_Pb214       -> Scale(Cd116_Pb214_weight       / Cd116_Pb214       -> Integral()   );
	TH1D * Mylar_Bi214        = (TH1D*) hcoll->Find( "Mylar_Bi214_h_electronEnergy"    ); Mylar_Bi214       -> Scale(Mylar_Bi214_weight       / Mylar_Bi214       -> Integral()   );
	TH1D * Mylar_Pb214        = (TH1D*) hcoll->Find( "Mylar_Pb214_h_electronEnergy"    ); Mylar_Pb214       -> Scale(Mylar_Pb214_weight       / Mylar_Pb214       -> Integral()   );
	TH1D * SWire_Tl208_P1     = (TH1D*) hcoll->Find( "SWire_Tl208_h_e_energy_P1"       ); SWire_Tl208_P1    -> Scale(SWire_Tl208_P1_weight    / SWire_Tl208_P1    -> Integral()   );
	TH1D * SWire_Tl208_P2     = (TH1D*) hcoll->Find( "SWire_Tl208_h_e_energy_P2"       ); SWire_Tl208_P2    -> Scale(SWire_Tl208_P2_weight    / SWire_Tl208_P2    -> Integral()   );
	TH1D * SWire_Bi214_P1     = (TH1D*) hcoll->Find( "SWire_Bi214_h_e_energy_P1"       ); SWire_Bi214_P1    -> Scale(SWire_Bi214_P1_weight    / SWire_Bi214_P1    -> Integral()   );
	TH1D * SFoil_Bi214_P1     = (TH1D*) hcoll->Find( "SFoil_Bi214_h_e_energy_P1"       ); SFoil_Bi214_P1    -> Scale(SFoil_Bi214_P1_weight    / SFoil_Bi214_P1    -> Integral()   );
	TH1D * SWire_Pb214_P1     = (TH1D*) hcoll->Find( "SWire_Pb214_h_e_energy_P1"       ); SWire_Pb214_P1    -> Scale(SWire_Pb214_P1_weight    / SWire_Pb214_P1    -> Integral()   );
	TH1D * SFoil_Pb214_P1     = (TH1D*) hcoll->Find( "SFoil_Pb214_h_e_energy_P1"       ); SFoil_Pb214_P1    -> Scale(SFoil_Pb214_P1_weight    / SFoil_Pb214_P1    -> Integral()   );
	TH1D * SWire_Bi214_P2     = (TH1D*) hcoll->Find( "SWire_Bi214_h_e_energy_P2"       ); SWire_Bi214_P2    -> Scale(SWire_Bi214_P2_weight    / SWire_Bi214_P2    -> Integral()   );
	TH1D * SFoil_Bi214_P2     = (TH1D*) hcoll->Find( "SFoil_Bi214_h_e_energy_P2"       ); SFoil_Bi214_P2    -> Scale(SFoil_Bi214_P2_weight    / SFoil_Bi214_P2    -> Integral()   );
	TH1D * SWire_Pb214_P2     = (TH1D*) hcoll->Find( "SWire_Pb214_h_e_energy_P2"       ); SWire_Pb214_P2    -> Scale(SWire_Pb214_P2_weight    / SWire_Pb214_P2    -> Integral()   );
	TH1D * SFoil_Pb214_P2     = (TH1D*) hcoll->Find( "SFoil_Pb214_h_e_energy_P2"       ); SFoil_Pb214_P2    -> Scale(SFoil_Pb214_P2_weight    / SFoil_Pb214_P2    -> Integral()   );
	TH1D * FeShield_Bi214     = (TH1D*) hcoll->Find( "FeShield_Bi214_h_electronEnergy" ); FeShield_Bi214    -> Scale(FeShield_Bi214_weight    / FeShield_Bi214    -> Integral()   );
    TH1D * FeShield_Tl208     = (TH1D*) hcoll->Find( "FeShield_Tl208_h_electronEnergy" ); FeShield_Tl208    -> Scale(FeShield_Tl208_weight    / FeShield_Tl208    -> Integral()   );
    TH1D * FeShield_Ac228     = (TH1D*) hcoll->Find( "FeShield_Ac228_h_electronEnergy" ); FeShield_Ac228    -> Scale(FeShield_Ac228_weight    / FeShield_Ac228    -> Integral()   );
	TH1D * PMT_K40   	      = (TH1D*) hcoll->Find( "PMT_K40_h_electronEnergy"        ); PMT_K40           -> Scale(PMT_K40_weight           / PMT_K40           -> Integral()   );
	TH1D * ScintInn_K40       = (TH1D*) hcoll->Find( "ScintOut_K40_h_electronEnergy"   ); ScintInn_K40      -> Scale(ScintInn_K40_weight      / ScintInn_K40      -> Integral()   );
	TH1D * ScintOut_K40       = (TH1D*) hcoll->Find( "ScintPet_K40_h_electronEnergy"   ); ScintOut_K40      -> Scale(ScintOut_K40_weight      / ScintOut_K40      -> Integral()   );
	TH1D * ScintPet_K40       = (TH1D*) hcoll->Find( "ScintInn_K40_h_electronEnergy"   ); ScintPet_K40      -> Scale(ScintPet_K40_weight      / ScintPet_K40      -> Integral()   );
	TH1D * PMT_Bi214   	      = (TH1D*) hcoll->Find( "PMT_Bi214_h_electronEnergy"      ); PMT_Bi214         -> Scale(PMT_Bi214_weight         / PMT_Bi214         -> Integral()   );
    TH1D * Air_Bi214_P1       = (TH1D*) hcoll->Find( "Air_Bi214_h_e_energy_P1"         ); Air_Bi214_P1      -> Scale(Air_Bi214_P1_weight      / Air_Bi214_P1      -> Integral()   );
    TH1D * Air_Pb214_P1       = (TH1D*) hcoll->Find( "Air_Pb214_h_e_energy_P1"         ); Air_Pb214_P1      -> Scale(Air_Pb214_P1_weight      / Air_Pb214_P1      -> Integral()   );
    TH1D * Air_Tl208_P1       = (TH1D*) hcoll->Find( "Air_Tl208_h_e_energy_P1"         ); Air_Tl208_P1      -> Scale(Air_Tl208_P1_weight      / Air_Tl208_P1      -> Integral()   );
    TH1D * PMT_Tl208          = (TH1D*) hcoll->Find( "PMT_Tl208_h_electronEnergy"      ); PMT_Tl208         -> Scale(PMT_Tl208_weight         / PMT_Tl208         -> Integral()   );
    TH1D * PMT_Ac228          = (TH1D*) hcoll->Find( "PMT_Ac228_h_electronEnergy"      ); PMT_Ac228         -> Scale(PMT_Ac228_weight         / PMT_Ac228         -> Integral()   );
    TH1D * CuTower_Co60       = (TH1D*) hcoll->Find( "CuTower_Co60_h_electronEnergy"   ); CuTower_Co60      -> Scale(CuTower_Co60_weight      / CuTower_Co60      -> Integral()   );
	TH1D * Cd116_K40_cold     = (TH1D*) hcoll->Find( "Cd116_K40_h_e_energy_P1_cold"    ); Cd116_K40_cold    -> Scale(Cd116_K40_cold_weight    / Cd116_K40_cold    -> Integral()   );
	TH1D * Cd116_Pa234m_cold  = (TH1D*) hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_cold" ); Cd116_Pa234m_cold -> Scale(Cd116_Pa234m_cold_weight / Cd116_Pa234m_cold -> Integral()   );
	TH1D * SFoil_Bi210_cold   = (TH1D*) hcoll->Find( "SFoil_Bi210_h_e_energy_P1_cold"  ); SFoil_Bi210_cold  -> Scale(SFoil_Bi210_cold_weight  / SFoil_Bi210_cold  -> Integral()   );
	TH1D * Cd116_K40_warm     = (TH1D*) hcoll->Find( "Cd116_K40_h_e_energy_P1_warm"    ); Cd116_K40_warm    -> Scale(Cd116_K40_warm_weight    / Cd116_K40_warm    -> Integral()   );
	TH1D * Cd116_Pa234m_warm  = (TH1D*) hcoll->Find( "Cd116_Pa234m_h_e_energy_P1_warm" ); Cd116_Pa234m_warm -> Scale(Cd116_Pa234m_warm_weight / Cd116_Pa234m_warm -> Integral()   );
	TH1D * SFoil_Bi210_warm   = (TH1D*) hcoll->Find( "SFoil_Bi210_h_e_energy_P1_warm"  ); SFoil_Bi210_warm  -> Scale(SFoil_Bi210_warm_weight  / SFoil_Bi210_warm  -> Integral()   );
    TH1D * SScin_Bi210        = (TH1D*) hcoll->Find( "SScin_Bi210_h_electronEnergy"    ); SScin_Bi210       -> Scale(SScin_Bi210_weight       / SScin_Bi210       -> Integral()   );
	TH1D * SScin_Bi214        = (TH1D*) hcoll->Find( "SScin_Bi214_h_electronEnergy"    ); SScin_Bi214       -> Scale(SScin_Bi214_weight       / SScin_Bi214       -> Integral()   );
	TH1D * SScin_Pb214        = (TH1D*) hcoll->Find( "SScin_Pb214_h_electronEnergy"    ); SScin_Pb214       -> Scale(SScin_Pb214_weight       / SScin_Pb214       -> Integral()   );
	TH1D * MuMetal_Pa234m     = (TH1D*) hcoll->Find( "MuMetal_Pa234m_h_electronEnergy" ); MuMetal_Pa234m    -> Scale(MuMetal_Pa234m_weight    / MuMetal_Pa234m    -> Integral()   );
	TH1D * SWire_Bi210_P1     = (TH1D*) hcoll->Find( "SWire_Bi210_h_e_energy_P1"       ); SWire_Bi210_P1    -> Scale(SWire_Bi210_P1_weight    / SWire_Bi210_P1    -> Integral()   );
	TH1D * SWire_Bi210_P2     = (TH1D*) hcoll->Find( "SWire_Bi210_h_e_energy_P2"       ); SWire_Bi210_P2    -> Scale(SWire_Bi210_P2_weight    / SWire_Bi210_P2    -> Integral()   );
	TH1D * BB                 = (TH1D*) hcoll->Find( "Cd116_2b2n_m4_h_electronEnergy"  ); BB                -> Scale(Cd116_2b2n_m14_weight    / BB                -> Integral()   );

	
	TH1D * Tl208 = SWire_Tl208_P1->Clone("Tl_208");
	Tl208->Add( SWire_Tl208_P2 );
	Tl208->Add( Cd116_Tl208   );
	Tl208->Add( Cd116_Ac228   );
	Tl208->Add( Cd116_Bi212   );

	TH1D * Bi214 = Cd116_Bi214->Clone("Bi214");
	Bi214->Add(Cd116_Pb214);
	Bi214->Add(Mylar_Bi214);
	Bi214->Add(Mylar_Pb214);

	TH1D * Radon = SWire_Bi214_P1->Clone("Radon");
	Radon->Add(SWire_Pb214_P1);
	Radon->Add(SFoil_Bi214_P1);
	Radon->Add(SFoil_Pb214_P1);
	Radon->Add(SWire_Bi214_P2);
	Radon->Add(SWire_Pb214_P2);
	Radon->Add(SFoil_Bi214_P2);
	Radon->Add(SFoil_Pb214_P2);

	TH1D * Externals = FeShield_Bi214->Clone("Externals");
	Externals->Add(FeShield_Tl208 );
	Externals->Add(FeShield_Ac228 );
	Externals->Add(CuTower_Co60   );
	Externals->Add(Air_Bi214_P1   );
	Externals->Add(Air_Pb214_P1   );
	Externals->Add(Air_Tl208_P1   );
	Externals->Add(PMT_Bi214      );
	Externals->Add(PMT_Tl208      );
	Externals->Add(PMT_Ac228      );
	Externals->Add(PMT_K40        );
	Externals->Add(ScintInn_K40   );
	Externals->Add(ScintOut_K40   );
	Externals->Add(ScintPet_K40   );
	Externals->Add(SScin_Bi210    );
	Externals->Add(SScin_Bi214    );
	Externals->Add(SScin_Pb214    );
	Externals->Add(MuMetal_Pa234m );
	
	TH1D * Pa234m = Cd116_Pa234m_cold->Clone("Pa234m");
	Pa234m -> Add(Cd116_Pa234m_warm);
	
	TH1D * K40 = Cd116_K40_cold->Clone("K40");
	K40->Add(Cd116_K40_warm);
	
	TH1D * Bi210 = SFoil_Bi210_cold->Clone("Bi210");
	Bi210->Add(SFoil_Bi210_warm);
	Bi210->Add(SWire_Bi210_P1);
	Bi210->Add(SWire_Bi210_P2);
		
	Tl208     -> SetFillColor( kOrange + 10 );
	Bi214     -> SetFillColor( kGreen  +  0 );
	Radon     -> SetFillColor( kAzure  +  1 );
	Externals -> SetFillColor( kOrange +  0 );
	BB        -> SetFillColor( kViolet + 10 );
	Pa234m    -> SetFillColor( kViolet +  1 );
	K40       -> SetFillColor( kViolet +  2 );
	Bi210     -> SetFillColor( kGreen  +  2 );
	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Tl208    );
	Stack->Add(Bi214    );
	Stack->Add(Radon    );
	Stack->Add(BB       );
	Stack->Add(Pa234m   );
	Stack->Add(Externals);
	Stack->Add(K40      );
	Stack->Add(Bi210    );
	
	TH1D * Sum = Tl208->Clone( "Sum" );
	Sum->Add(Bi214    );
	Sum->Add(Radon    );
	Sum->Add(Externals);
	Sum->Add(BB       );
	Sum->Add(Pa234m   );
	Sum->Add(K40      );
	Sum->Add(Bi210    );
	
	TCanvas * Canvas = new TCanvas("SingleElectronEnergy", "SingleElectronEnergy", 500, 500);
	
    Bool_t _LogScale    = kTRUE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);

	
	
    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.01);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("E_{e} (MeV)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
    //Data->GetYaxis().SetRangeUser(1e-1,5e+3) ;
		
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.1) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(0.25,1.75) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-8,8) ;
            
    TLegend * Leg = new TLegend(0.59,0.8,0.92,0.52)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( Bi210       , "^{210}Bi"       , "F"  );
	Leg->AddEntry( K40         , "^{40}K"         , "F"  );
	Leg->AddEntry( Externals   , "External"       , "F"  );	
	Leg->AddEntry( Pa234m      , "^{234m}Pa"      , "F"  );
	Leg->AddEntry( BB          , "2#nu#beta#beta" , "F"  );	
	Leg->AddEntry( Radon       , "Radon"          , "F"  );
	Leg->AddEntry( Bi214       , "^{214}Bi"       , "F"  );
	Leg->AddEntry( Tl208       , "^{208}Tl"       , "F"  );
    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(0.5,3.5) ;    
	Ratio-> GetXaxis()->SetRangeUser(0.5,3.5) ;        
    Res  -> GetXaxis()->SetRangeUser(0.5,3.5) ;    

    pad1->cd() ;    
    Data->Draw(""); 
    Stack->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();
	
    pad2->cd() ;
    Ratio->Draw("P0"); 
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
	Ratio->Draw("P0same"); 

    pad3->cd(); 
    Res->Draw("P0"); 
	pad3->Update();
	TLine * LineRes = new TLine(pad2->GetUxmin(),0,pad2->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same"); 

    pad1->cd() ;
    Leg->Draw(); 
	
	Canvas->cd();
	Canvas->Update();
	
};	

void DrawTotalElectronGammaEnergy(){
	
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample_OLD.C+");
	
	// Load OneElectronTwoGammaHistos in HistoCollection
	HistoCollection * hcoll= new HistoCollection("OneElectronTwoGammaHistos", "OneElectronTwoGammaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronTwoGammaInt.root");
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	    
	TH1D * Data = (TH1D*) hcoll->Find( "Data_h_tot_energy_P1" );	
	Data->Add((TH1D*) hcoll->Find( "Data_h_tot_energy_P2" ));	

	Double_t Cd116_Tl208_P1_weight    =    17.1463; 
	Double_t Cd116_Ac228_P1_weight    =    2.79616; 
	Double_t Cd116_Bi212_P1_weight    =   0.318482; 
	Double_t Cd116_Bi214_P1_weight    =    25.5284; 
	Double_t Cd116_Pb214_P1_weight    = 0.00154435; 
	Double_t Mylar_Bi214_P1_weight    =    15.7774; 
	Double_t SWire_Tl208_P1_weight    =    8.86357; 
	Double_t SWire_Bi214_P1_weight    =    484.262; 
	Double_t SFoil_Bi214_P1_weight    =    62.9056; 
	Double_t FeShield_Bi214_P1_weight =     40.791; 
	Double_t FeShield_Tl208_P1_weight =   0.824869; 
	Double_t CuTower_Co60_P1_weight   =    3.44972; 
	Double_t Air_Bi214_P1_weight      =    28.0074; 
	Double_t Air_Tl208_P1_weight      =    6.58782; 
	Double_t PMT_Bi214_P1_weight      =    41.5511; 
	Double_t PMT_Tl208_P1_weight      =    17.7324; 
	Double_t PMT_Ac228_P1_weight      =      1.805; 
	Double_t PMT_K40_P1_weight        =    6.73046; 
	Double_t ScintInn_K40_P1_weight   =   0.168009; 
	Double_t ScintOut_K40_P1_weight   =   0.403221; 
	Double_t SScin_Bi214_P1_weight    =  0.0505728; 
	Double_t MuMetal_Pa234m_P1_weight =   0.326495; 
				
	Double_t Cd116_Tl208_P2_weight    = 109.27     ;           
	Double_t Cd116_Ac228_P2_weight    = 18.31      ;          
	Double_t Cd116_Bi212_P2_weight    = 1.84072    ;            
	Double_t Cd116_Bi214_P2_weight    = 162.476    ;            
	Double_t Mylar_Bi214_P2_weight    = 99.8945    ;            
	Double_t SWire_Tl208_P2_weight    = 47.1879    ;            
	Double_t SWire_Bi214_P2_weight    = 404.839    ;            
	Double_t SFoil_Bi214_P2_weight    = 31.5273    ;            
	Double_t SWire_Pb214_P2_weight    = 0.0285503  ;              
	Double_t SFoil_Pb214_P2_weight    = 0.00201992 ;               
	Double_t FeShield_Bi214_P2_weight = 246.951    ;            
	Double_t FeShield_Tl208_P2_weight = 5.52662    ;            
	Double_t FeShield_Ac228_P2_weight = 0.617937   ;             
	Double_t CuTower_Co60_P2_weight   = 17.2486    ;            
	Double_t PMT_Bi214_P2_weight      = 253.568    ;            
	Double_t PMT_Tl208_P2_weight      = 97.3063    ;            
	Double_t PMT_Ac228_P2_weight      = 10.83      ;          
	Double_t PMT_K40_P2_weight        = 59.9011    ;            
	Double_t ScintInn_K40_P2_weight   = 1.00805    ;            
	Double_t ScintOut_K40_P2_weight   = 2.72174    ;            
	Double_t ScintPet_K40_P2_weight   = 2.01608    ;            
	Double_t SScin_Bi214_P2_weight    = 1.87119    ;            
	Double_t MuMetal_Pa234m_P2_weight = 0.652989   ;             
			
	TH1D * Cd116_Tl208_P1    = (TH1D*) hcoll->Find( "Cd116_Tl208_h_tot_energy_P1"     );  Cd116_Tl208_P1    -> Scale( Cd116_Tl208_P1_weight    /  Cd116_Tl208_P1    -> Integral() ); 
    TH1D * Cd116_Ac228_P1    = (TH1D*) hcoll->Find( "Cd116_Ac228_h_tot_energy_P1"     );  Cd116_Ac228_P1    -> Scale( Cd116_Ac228_P1_weight    /  Cd116_Ac228_P1    -> Integral() ); 
	TH1D * Cd116_Bi212_P1    = (TH1D*) hcoll->Find( "Cd116_Bi212_h_tot_energy_P1"     );  Cd116_Bi212_P1    -> Scale( Cd116_Bi212_P1_weight    /  Cd116_Bi212_P1    -> Integral() ); 
	TH1D * Cd116_Bi214_P1    = (TH1D*) hcoll->Find( "Cd116_Bi214_h_tot_energy_P1"	  );  Cd116_Bi214_P1    -> Scale( Cd116_Bi214_P1_weight    /  Cd116_Bi214_P1    -> Integral() ); 
    TH1D * Cd116_Pb214_P1    = (TH1D*) hcoll->Find( "Cd116_Pb214_VT_h_tot_energy_P1"  );  Cd116_Pb214_P1    -> Scale( Cd116_Pb214_P1_weight    /  Cd116_Pb214_P1    -> Integral() ); 
	TH1D * Mylar_Bi214_P1    = (TH1D*) hcoll->Find( "Mylar_Bi214_h_tot_energy_P1"     );  Mylar_Bi214_P1    -> Scale( Mylar_Bi214_P1_weight    /  Mylar_Bi214_P1    -> Integral() ); 
	TH1D * SWire_Tl208_P1    = (TH1D*) hcoll->Find( "SWire_Tl208_h_tot_energy_P1"     );  SWire_Tl208_P1    -> Scale( SWire_Tl208_P1_weight    /  SWire_Tl208_P1    -> Integral() ); 	
	TH1D * SWire_Bi214_P1    = (TH1D*) hcoll->Find( "SWire_Bi214_h_tot_energy_P1"     );  SWire_Bi214_P1    -> Scale( SWire_Bi214_P1_weight    /  SWire_Bi214_P1    -> Integral() ); 	
	TH1D * SFoil_Bi214_P1    = (TH1D*) hcoll->Find( "SFoil_Bi214_h_tot_energy_P1"     );  SFoil_Bi214_P1    -> Scale( SFoil_Bi214_P1_weight    /  SFoil_Bi214_P1    -> Integral() ); 
	TH1D * FeShield_Bi214_P1 = (TH1D*) hcoll->Find( "FeShield_Bi214_h_tot_energy_P1"  );  FeShield_Bi214_P1 -> Scale( FeShield_Bi214_P1_weight /  FeShield_Bi214_P1 -> Integral() );          
	TH1D * FeShield_Tl208_P1 = (TH1D*) hcoll->Find( "FeShield_Tl208_h_tot_energy_P1"  );  FeShield_Tl208_P1 -> Scale( FeShield_Tl208_P1_weight /  FeShield_Tl208_P1 -> Integral() );          
	TH1D * CuTower_Co60_P1   = (TH1D*) hcoll->Find( "CuTower_Co60_h_tot_energy_P1"    );  CuTower_Co60_P1   -> Scale( CuTower_Co60_P1_weight   /  CuTower_Co60_P1   -> Integral() );          
	TH1D * Air_Bi214_P1      = (TH1D*) hcoll->Find( "Air_Bi214_h_tot_energy_P1"       );  Air_Bi214_P1      -> Scale( Air_Bi214_P1_weight      /  Air_Bi214_P1      -> Integral() );       
	TH1D * Air_Tl208_P1      = (TH1D*) hcoll->Find( "Air_Tl208_h_tot_energy_P1"       );  Air_Tl208_P1      -> Scale( Air_Tl208_P1_weight      /  Air_Tl208_P1      -> Integral() );       
	TH1D * PMT_Bi214_P1      = (TH1D*) hcoll->Find( "PMT_Bi214_h_tot_energy_P1"       );  PMT_Bi214_P1      -> Scale( PMT_Bi214_P1_weight      /  PMT_Bi214_P1      -> Integral() );          
	TH1D * PMT_Tl208_P1      = (TH1D*) hcoll->Find( "PMT_Tl208_h_tot_energy_P1"       );  PMT_Tl208_P1      -> Scale( PMT_Tl208_P1_weight      /  PMT_Tl208_P1      -> Integral() );          
	TH1D * PMT_Ac228_P1      = (TH1D*) hcoll->Find( "PMT_Ac228_h_tot_energy_P1"       );  PMT_Ac228_P1      -> Scale( PMT_Ac228_P1_weight      /  PMT_Ac228_P1      -> Integral() );          
	TH1D * PMT_K40_P1        = (TH1D*) hcoll->Find( "PMT_K40_h_tot_energy_P1"         );  PMT_K40_P1        -> Scale( PMT_K40_P1_weight        /  PMT_K40_P1        -> Integral() );          
	TH1D * ScintInn_K40_P1   = (TH1D*) hcoll->Find( "ScintInn_K40_h_tot_energy_P1"    );  ScintInn_K40_P1   -> Scale( ScintInn_K40_P1_weight   /  ScintInn_K40_P1   -> Integral() );          
	TH1D * ScintOut_K40_P1   = (TH1D*) hcoll->Find( "ScintOut_K40_h_tot_energy_P1"    );  ScintOut_K40_P1   -> Scale( ScintOut_K40_P1_weight   /  ScintOut_K40_P1   -> Integral() );          
	TH1D * SScin_Bi214_P1    = (TH1D*) hcoll->Find( "SScin_Bi214_h_tot_energy_P1"     );  SScin_Bi214_P1    -> Scale( SScin_Bi214_P1_weight    /  SScin_Bi214_P1    -> Integral() );          
	TH1D * MuMetal_Pa234m_P1 = (TH1D*) hcoll->Find( "MuMetal_Pa234m_h_tot_energy_P1"  );  MuMetal_Pa234m_P1 -> Scale( MuMetal_Pa234m_P1_weight /  MuMetal_Pa234m_P1 -> Integral() );          			

	TH1D * Cd116_Tl208_P2    = (TH1D*) hcoll->Find( "Cd116_Tl208_h_tot_energy_P2"     );  Cd116_Tl208_P2    -> Scale( Cd116_Tl208_P2_weight    /  Cd116_Tl208_P2    -> Integral() ); 
    TH1D * Cd116_Ac228_P2    = (TH1D*) hcoll->Find( "Cd116_Ac228_h_tot_energy_P2"     );  Cd116_Ac228_P2    -> Scale( Cd116_Ac228_P2_weight    /  Cd116_Ac228_P2    -> Integral() ); 
	TH1D * Cd116_Bi212_P2    = (TH1D*) hcoll->Find( "Cd116_Bi212_h_tot_energy_P2"     );  Cd116_Bi212_P2    -> Scale( Cd116_Bi212_P2_weight    /  Cd116_Bi212_P2    -> Integral() ); 
	TH1D * Cd116_Bi214_P2    = (TH1D*) hcoll->Find( "Cd116_Bi214_h_tot_energy_P2"	  );  Cd116_Bi214_P2    -> Scale( Cd116_Bi214_P2_weight    /  Cd116_Bi214_P2    -> Integral() ); 
	TH1D * Mylar_Bi214_P2    = (TH1D*) hcoll->Find( "Mylar_Bi214_h_tot_energy_P2"     );  Mylar_Bi214_P2    -> Scale( Mylar_Bi214_P2_weight    /  Mylar_Bi214_P2    -> Integral() ); 
	TH1D * SWire_Tl208_P2    = (TH1D*) hcoll->Find( "SWire_Tl208_h_tot_energy_P2"     );  SWire_Tl208_P2    -> Scale( SWire_Tl208_P2_weight    /  SWire_Tl208_P2    -> Integral() ); 	
	TH1D * SWire_Bi214_P2    = (TH1D*) hcoll->Find( "SWire_Bi214_h_tot_energy_P2"     );  SWire_Bi214_P2    -> Scale( SWire_Bi214_P2_weight    /  SWire_Bi214_P2    -> Integral() ); 	
	TH1D * SFoil_Bi214_P2    = (TH1D*) hcoll->Find( "SFoil_Bi214_h_tot_energy_P2"     );  SFoil_Bi214_P2    -> Scale( SFoil_Bi214_P2_weight    /  SFoil_Bi214_P2    -> Integral() ); 
	TH1D * SWire_Pb214_P2    = (TH1D*) hcoll->Find( "SWire_Pb214_h_tot_energy_P2"     );  SWire_Pb214_P2    -> Scale( SWire_Pb214_P2_weight    /  SWire_Pb214_P2    -> Integral() ); 	
	TH1D * SFoil_Pb214_P2    = (TH1D*) hcoll->Find( "SFoil_Pb214_h_tot_energy_P2"     );  SFoil_Pb214_P2    -> Scale( SFoil_Pb214_P2_weight    /  SFoil_Pb214_P2    -> Integral() ); 
	TH1D * FeShield_Bi214_P2 = (TH1D*) hcoll->Find( "FeShield_Bi214_h_tot_energy_P2"  );  FeShield_Bi214_P2 -> Scale( FeShield_Bi214_P2_weight /  FeShield_Bi214_P2 -> Integral() );          
	TH1D * FeShield_Tl208_P2 = (TH1D*) hcoll->Find( "FeShield_Tl208_h_tot_energy_P2"  );  FeShield_Tl208_P2 -> Scale( FeShield_Tl208_P2_weight /  FeShield_Tl208_P2 -> Integral() );          
	TH1D * FeShield_Ac228_P2 = (TH1D*) hcoll->Find( "FeShield_Ac228_h_tot_energy_P2"  );  FeShield_Ac228_P2 -> Scale( FeShield_Ac228_P2_weight /  FeShield_Ac228_P2 -> Integral() );          
	TH1D * CuTower_Co60_P2   = (TH1D*) hcoll->Find( "CuTower_Co60_h_tot_energy_P2"    );  CuTower_Co60_P2   -> Scale( CuTower_Co60_P2_weight   /  CuTower_Co60_P2   -> Integral() );          
	TH1D * PMT_Bi214_P2      = (TH1D*) hcoll->Find( "PMT_Bi214_h_tot_energy_P2"       );  PMT_Bi214_P2      -> Scale( PMT_Bi214_P2_weight      /  PMT_Bi214_P2      -> Integral() );          
	TH1D * PMT_Tl208_P2      = (TH1D*) hcoll->Find( "PMT_Tl208_h_tot_energy_P2"       );  PMT_Tl208_P2      -> Scale( PMT_Tl208_P2_weight      /  PMT_Tl208_P2      -> Integral() );          
	TH1D * PMT_Ac228_P2      = (TH1D*) hcoll->Find( "PMT_Ac228_h_tot_energy_P2"       );  PMT_Ac228_P2      -> Scale( PMT_Ac228_P2_weight      /  PMT_Ac228_P2      -> Integral() );          
	TH1D * PMT_K40_P2        = (TH1D*) hcoll->Find( "PMT_K40_h_tot_energy_P2"         );  PMT_K40_P2        -> Scale( PMT_K40_P2_weight        /  PMT_K40_P2        -> Integral() );          
	TH1D * ScintOut_K40_P2   = (TH1D*) hcoll->Find( "ScintOut_K40_h_tot_energy_P2"    );  ScintOut_K40_P2   -> Scale( ScintOut_K40_P2_weight   /  ScintOut_K40_P2   -> Integral() );          
	TH1D * SScin_Bi214_P2    = (TH1D*) hcoll->Find( "SScin_Bi214_h_tot_energy_P2"     );  SScin_Bi214_P2    -> Scale( SScin_Bi214_P2_weight    /  SScin_Bi214_P2    -> Integral() );          
	TH1D * MuMetal_Pa234m_P2 = (TH1D*) hcoll->Find( "MuMetal_Pa234m_h_tot_energy_P2"  );  MuMetal_Pa234m_P2 -> Scale( MuMetal_Pa234m_P2_weight /  MuMetal_Pa234m_P2 -> Integral() );          			


	TH1D * Tl208 = SWire_Tl208_P1->Clone("Tl208");
	Tl208->Add( Cd116_Tl208_P1    );
	Tl208->Add( Cd116_Ac228_P1    );
	Tl208->Add( Cd116_Bi212_P1    );
	Tl208->Add( SWire_Tl208_P2    );
	Tl208->Add( Cd116_Tl208_P2    );
	Tl208->Add( Cd116_Ac228_P2    );
	Tl208->Add( Cd116_Bi212_P2    );

	TH1D * Bi214 = Cd116_Bi214_P1->Clone("Bi214");
	Bi214->Add(Cd116_Pb214_P1);
	Bi214->Add(Mylar_Bi214_P1);
	Bi214->Add(Cd116_Bi214_P2);
	Bi214->Add(Mylar_Bi214_P2);

	TH1D * Radon = SWire_Bi214_P1->Clone("Radon");
	Radon->Add( SWire_Bi214_P2 );
	Radon->Add( SFoil_Bi214_P1 );
	Radon->Add( SFoil_Bi214_P2 );
	Radon->Add( SFoil_Pb214_P2 );

	TH1D * Externals = FeShield_Bi214_P1->Clone("Externals");
	Externals->Add( FeShield_Tl208_P1 );
	Externals->Add( CuTower_Co60_P1   );
	Externals->Add( Air_Bi214_P1   );
	Externals->Add( Air_Tl208_P1   );
	Externals->Add( PMT_Bi214_P1      );
	Externals->Add( PMT_Tl208_P1      );
	Externals->Add( PMT_Ac228_P1      );
	Externals->Add( PMT_K40_P1        );
	Externals->Add( ScintInn_K40_P1   );
	Externals->Add( ScintOut_K40_P1   );
	Externals->Add( SScin_Bi214_P1    );
	Externals->Add( MuMetal_Pa234m_P1 );
	Externals->Add( FeShield_Bi214_P2 );
	Externals->Add( FeShield_Tl208_P2 );
	Externals->Add( FeShield_Ac228_P2 );
	Externals->Add( CuTower_Co60_P2   );
	Externals->Add( PMT_Bi214_P2      );
	Externals->Add( PMT_Tl208_P2      );
	Externals->Add( PMT_Ac228_P2      );
	Externals->Add( PMT_K40_P2        );
	Externals->Add( ScintOut_K40_P2   );
	Externals->Add( SScin_Bi214_P2    );
	Externals->Add( MuMetal_Pa234m_P2 );

	
	Tl208     -> SetFillColor( kOrange + 10 );
	Bi214     -> SetFillColor( kGreen  +  0 );
	Radon     -> SetFillColor( kAzure  +  1 );
	Externals -> SetFillColor( kOrange +  0 );
	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Tl208    );
	Stack->Add(Bi214    );
	Stack->Add(Radon    );
	Stack->Add(Externals);
	
	TH1D * Sum = Bi214->Clone("Sum");
	Sum->Add(Tl208    );
	Sum->Add(Radon    );
	Sum->Add(Externals);
	
	TCanvas * Canvas = new TCanvas("TotalElectronGammaEnergy", "TotalElectronGammaEnergy", 500, 500);
	
    Bool_t _LogScale    = kTRUE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);
	
    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.01);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("E_{e} + E_{#gamma,1} + E_{#gamma,2} (MeV)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
    //Data->GetYaxis().SetRangeUser(1e-1,5e+3) ;
		
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.1) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(-0.75,4.75) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-8,8) ;
            
    TLegend * Leg = new TLegend(0.59,0.8,0.92,0.64)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( Externals   , "External"       , "F"  );	
	Leg->AddEntry( Radon       , "Radon"          , "F"  );
	Leg->AddEntry( Bi214       , "^{214}Bi"       , "F"  );
	Leg->AddEntry( Tl208       , "^{208}Tl"       , "F"  );
    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(0.0,5.0) ;    
	Ratio-> GetXaxis()->SetRangeUser(0.0,5.0) ;        
    Res  -> GetXaxis()->SetRangeUser(0.0,5.0) ;    

    pad1->cd() ;    
    Data->Draw(""); 
    Stack->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();
	
    pad2->cd() ;
    Ratio->Draw("P0"); 
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
	Ratio->Draw("P0same"); 


    pad3->cd(); 
    Res->Draw("P0"); 
	pad3->Update();
	TLine * LineRes = new TLine(pad2->GetUxmin(),0,pad2->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same"); 

    pad1->cd() ;
    Leg->Draw(); 
	
	Canvas->cd();
	Canvas->Update();
	
	
};

void DrawTwoElectronEnergy(char * model = ""){
	
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	HistoCollection * hcoll= new HistoCollection("TwoElectronHistos", "TwoElectronHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/TwoElectronIntHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	
	TH1D * Data = (TH1D*) hcoll->Find( "Data_h_tot_e_energy" );
	
    Double_t Cd116_Tl208_weight     = 5.93241           ;
    Double_t Cd116_Ac228_weight     = 6.92004           ;
    Double_t Cd116_Bi212_weight     = 2.74493           ;
    Double_t Cd116_Bi214_weight     = 18.2853           ;
    Double_t Cd116_Pb214_weight     = 0.186478          ;
    Double_t Mylar_Bi214_weight     = 11.1896           ;
    Double_t Mylar_Pb214_weight     = 0.493241          ;
    Double_t Cd116_K40_weight       = 25.9835+9.02952   ;
    Double_t Cd116_Pa234m_weight    = 27.7433+72.4378   ;
    Double_t SFoil_Bi210_weight     = 23.243            ;
    Double_t SWire_Bi210_weight     = 0.136147+0.624186 ;
    Double_t SScin_Bi210_weight     = 1.756             ;
    Double_t SScin_Bi214_weight     = 0.050538          ;
    Double_t SWire_Tl208_weight     = 0.217623+1.07644  ;
    Double_t SWire_Bi214_weight     = 21.4626+17.9578   ;
    Double_t SFoil_Bi214_weight     = 5.77558+2.73528   ;
    Double_t SWire_Pb214_weight     = 0.457546+0.648406 ;
    Double_t SFoil_Pb214_weight     = 0.215627+0.188876 ;
    Double_t FeShield_Bi214_weight  = 49.1846           ;
    Double_t FeShield_Tl208_weight  = 1.19312           ;
    Double_t FeShield_Ac228_weight  = 0.17612           ;
    Double_t CuTower_Co60_weight    = 3.77603           ;
    Double_t Air_Bi214_P1_weight    = 4.19271           ;
    Double_t PMT_Bi214_weight       = 30.7385           ;
    Double_t PMT_Tl208_weight       = 23.2701           ;
    Double_t PMT_Ac228_weight       = 3.60944           ;
    Double_t PMT_K40_weight         = 16.7905           ;
    Double_t ScintInn_K40_weight    = 0.335557          ;
    Double_t ScintOut_K40_weight    = 0.604003          ;
    Double_t ScintPet_K40_weight    = 1.00666           ;
    Double_t MuMetal_Pa234m_weight  = 0.66462           ;

	// weights obtained with limit setting on Etot
    Double_t BB_weight              = 5022.22           ;	
    Double_t MM_weight              = 78.5  * 0.09208   ;
    Double_t RHC_E_weight           = 87.0  * 0.04758   ;
    Double_t RHC_L_weight           = 156.0 * 0.07510   ;        
    Double_t M1_weight              = 900.7 * 0.06308   ;

	
	TH1D * Cd116_Tl208    = (TH1D*) hcoll->Find( "Cd116_Tl208_h_tot_e_energy"     ); Cd116_Tl208    -> Scale( Cd116_Tl208_weight    / Cd116_Tl208    ->Integral() );
	TH1D * Cd116_Ac228    = (TH1D*) hcoll->Find( "Cd116_Ac228_h_tot_e_energy"     ); Cd116_Ac228    -> Scale( Cd116_Ac228_weight    / Cd116_Ac228    ->Integral() );
	TH1D * Cd116_Bi212    = (TH1D*) hcoll->Find( "Cd116_Bi212_h_tot_e_energy"     ); Cd116_Bi212    -> Scale( Cd116_Bi212_weight    / Cd116_Bi212    ->Integral() );
	TH1D * Cd116_Bi214    = (TH1D*) hcoll->Find( "Cd116_Bi214_h_tot_e_energy"     ); Cd116_Bi214    -> Scale( Cd116_Bi214_weight    / Cd116_Bi214    ->Integral() );
	TH1D * Cd116_Pb214    = (TH1D*) hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy"  ); Cd116_Pb214    -> Scale( Cd116_Pb214_weight    / Cd116_Pb214    ->Integral() );
	TH1D * Mylar_Bi214    = (TH1D*) hcoll->Find( "Mylar_Bi214_h_tot_e_energy"     ); Mylar_Bi214    -> Scale( Mylar_Bi214_weight    / Mylar_Bi214    ->Integral() );
	TH1D * Mylar_Pb214    = (TH1D*) hcoll->Find( "Mylar_Pb214_h_tot_e_energy"     ); Mylar_Pb214    -> Scale( Mylar_Pb214_weight    / Mylar_Pb214    ->Integral() );
	TH1D * Cd116_K40      = (TH1D*) hcoll->Find( "Cd116_K40_h_tot_e_energy"       ); Cd116_K40      -> Scale( Cd116_K40_weight      / Cd116_K40      ->Integral() );
	TH1D * Cd116_Pa234m   = (TH1D*) hcoll->Find( "Cd116_Pa234m_h_tot_e_energy"    ); Cd116_Pa234m   -> Scale( Cd116_Pa234m_weight   / Cd116_Pa234m   ->Integral() );
	TH1D * SFoil_Bi210    = (TH1D*) hcoll->Find( "SFoil_Bi210_h_tot_e_energy"     ); SFoil_Bi210    -> Scale( SFoil_Bi210_weight    / SFoil_Bi210    ->Integral() );
	TH1D * SWire_Bi210    = (TH1D*) hcoll->Find( "SWire_Bi210_h_tot_e_energy"     ); SWire_Bi210    -> Scale( SWire_Bi210_weight    / SWire_Bi210    ->Integral() );
	TH1D * SScin_Bi210    = (TH1D*) hcoll->Find( "SScin_Bi210_h_tot_e_energy"     ); SScin_Bi210    -> Scale( SScin_Bi210_weight    / SScin_Bi210    ->Integral() );
	TH1D * SScin_Bi214    = (TH1D*) hcoll->Find( "SScin_Bi214_h_tot_e_energy"     ); SScin_Bi214    -> Scale( SScin_Bi214_weight    / SScin_Bi214    ->Integral() );
	TH1D * SWire_Tl208    = (TH1D*) hcoll->Find( "SWire_Tl208_h_tot_e_energy"     ); SWire_Tl208    -> Scale( SWire_Tl208_weight    / SWire_Tl208    ->Integral() );
	TH1D * SWire_Bi214    = (TH1D*) hcoll->Find( "SWire_Bi214_h_tot_e_energy"     ); SWire_Bi214    -> Scale( SWire_Bi214_weight    / SWire_Bi214    ->Integral() );
	TH1D * SFoil_Bi214    = (TH1D*) hcoll->Find( "SFoil_Bi214_h_tot_e_energy"     ); SFoil_Bi214    -> Scale( SFoil_Bi214_weight    / SFoil_Bi214    ->Integral() );
	TH1D * SWire_Pb214    = (TH1D*) hcoll->Find( "SWire_Pb214_h_tot_e_energy"     ); SWire_Pb214    -> Scale( SWire_Pb214_weight    / SWire_Pb214    ->Integral() );
	TH1D * SFoil_Pb214    = (TH1D*) hcoll->Find( "SFoil_Pb214_h_tot_e_energy"     ); SFoil_Pb214    -> Scale( SFoil_Pb214_weight    / SFoil_Pb214    ->Integral() );
	TH1D * FeShield_Bi214 = (TH1D*) hcoll->Find( "FeShield_Bi214_h_tot_e_energy"  ); FeShield_Bi214 -> Scale( FeShield_Bi214_weight / FeShield_Bi214 ->Integral() );
	TH1D * FeShield_Tl208 = (TH1D*) hcoll->Find( "FeShield_Tl208_h_tot_e_energy"  ); FeShield_Tl208 -> Scale( FeShield_Tl208_weight / FeShield_Tl208 ->Integral() );
	TH1D * FeShield_Ac228 = (TH1D*) hcoll->Find( "FeShield_Ac228_h_tot_e_energy"  ); FeShield_Ac228 -> Scale( FeShield_Ac228_weight / FeShield_Ac228 ->Integral() );
	TH1D * CuTower_Co60   = (TH1D*) hcoll->Find( "CuTower_Co60_h_tot_e_energy"    ); CuTower_Co60   -> Scale( CuTower_Co60_weight   / CuTower_Co60   ->Integral() );
	TH1D * Air_Bi214_P1   = (TH1D*) hcoll->Find( "Air_Bi214_h_tot_e_energy"       ); Air_Bi214_P1   -> Scale( Air_Bi214_P1_weight   / Air_Bi214_P1   ->Integral() );
	TH1D * PMT_Bi214      = (TH1D*) hcoll->Find( "PMT_Bi214_h_tot_e_energy"       ); PMT_Bi214      -> Scale( PMT_Bi214_weight      / PMT_Bi214      ->Integral() );
	TH1D * PMT_Tl208      = (TH1D*) hcoll->Find( "PMT_Tl208_h_tot_e_energy"       ); PMT_Tl208      -> Scale( PMT_Tl208_weight      / PMT_Tl208      ->Integral() );
	TH1D * PMT_Ac228      = (TH1D*) hcoll->Find( "PMT_Ac228_h_tot_e_energy"       ); PMT_Ac228      -> Scale( PMT_Ac228_weight      / PMT_Ac228      ->Integral() );
	TH1D * PMT_K40        = (TH1D*) hcoll->Find( "PMT_K40_h_tot_e_energy"         ); PMT_K40        -> Scale( PMT_K40_weight        / PMT_K40        ->Integral() );
	TH1D * ScintInn_K40   = (TH1D*) hcoll->Find( "ScintInn_K40_h_tot_e_energy"    ); ScintInn_K40   -> Scale( ScintInn_K40_weight   / ScintInn_K40   ->Integral() );
	TH1D * ScintOut_K40   = (TH1D*) hcoll->Find( "ScintOut_K40_h_tot_e_energy"    ); ScintOut_K40   -> Scale( ScintOut_K40_weight   / ScintOut_K40   ->Integral() );
	TH1D * ScintPet_K40   = (TH1D*) hcoll->Find( "ScintPet_K40_h_tot_e_energy"    ); ScintPet_K40   -> Scale( ScintPet_K40_weight   / ScintPet_K40   ->Integral() );
	TH1D * MuMetal_Pa234m = (TH1D*) hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy"  ); MuMetal_Pa234m -> Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m ->Integral() );
	TH1D * BB             = (TH1D*) hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy"  ); BB             -> Scale( BB_weight             / BB             ->Integral() );	

	if(model == "MM"    ) { TH1D * MM             = (TH1D*) hcoll->Find( "Cd116_2b0n_m1_h_tot_e_energy"   ); MM             -> Scale( MM_weight             / MM             ->Integral() );} 
	if(model == "RHC_E" ) { TH1D * RHC_E          = (TH1D*) hcoll->Find( "Cd116_2b0n_m18_h_tot_e_energy"  ); RHC_E          -> Scale( RHC_E_weight          / RHC_E          ->Integral() );} 
	if(model == "RHC_L" ) { TH1D * RHC_L          = (TH1D*) hcoll->Find( "Cd116_2b0n_m2_h_tot_e_energy"   ); RHC_L          -> Scale( RHC_L_weight          / RHC_L          ->Integral() );} 
	if(model == "M1"    ) { TH1D * M1             = (TH1D*) hcoll->Find( "Cd116_2b0n_m5_h_tot_e_energy"   ); M1             -> Scale( M1_weight             / M1             ->Integral() );} 


    TH1D * Tl208 = SWire_Tl208->Clone("Tl208");
    Tl208->Add( Cd116_Tl208 );
    Tl208->Add( Cd116_Ac228 );
    Tl208->Add( Cd116_Bi212 );
    
    TH1D * Bi214 = Mylar_Bi214->Clone("Bi214") ;
    Bi214->Add( Mylar_Pb214 );
    Bi214->Add( Cd116_Bi214 );
    Bi214->Add( Cd116_Pb214 );
    
    TH1D * K40 = Cd116_K40->Clone("K40") ;
    
    TH1D * Pa234m = Cd116_Pa234m->Clone("Pa234m");
    
    TH1D * Bi210 = SFoil_Bi210->Clone("Bi210"); 
    Bi210->Add( SWire_Bi210   );
    
    TH1D * Radon = SWire_Bi214->Clone("Radon") ;
    Radon->Add( SWire_Pb214 );
    Radon->Add( SFoil_Bi214 );
    Radon->Add( SFoil_Pb214 );
    	
    TH1D * Externals = FeShield_Bi214->Clone("Externals");
    Externals->Add( FeShield_Tl208 );
    Externals->Add( FeShield_Ac228 );
    Externals->Add( CuTower_Co60   );
    Externals->Add( Air_Bi214_P1   );
    Externals->Add( PMT_Bi214      );
    Externals->Add( PMT_Tl208      );
    Externals->Add( PMT_Ac228      );
    Externals->Add( PMT_K40        );
    Externals->Add( ScintInn_K40   );
    Externals->Add( ScintOut_K40   );
    Externals->Add( ScintPet_K40   );
    Externals->Add( SScin_Bi210    );
    Externals->Add( SScin_Bi214    );
    Externals->Add( MuMetal_Pa234m );

	Tl208     -> SetFillColor( kOrange + 10 );
	Bi214     -> SetFillColor( kGreen  +  0 );
	Radon     -> SetFillColor( kAzure  +  1 );
	Externals -> SetFillColor( kOrange +  0 );
	BB        -> SetFillColor( kViolet + 10 );
	Pa234m    -> SetFillColor( kViolet +  1 );
	K40       -> SetFillColor( kViolet +  2 );
	Bi210     -> SetFillColor( kGreen  +  2 );
	
	if( model == "MM"    ) {
		MM    -> SetLineColor(46);
		MM    -> SetLineStyle(1); 
		MM    -> SetLineWidth(3); 
	}
	
	if( model == "RHC_E" ) {
		RHC_E -> SetLineColor(38);
		RHC_E -> SetLineStyle(3); 
		RHC_E -> SetLineWidth(3); 
	}
	
	if ( model == "RHC_L" ) {
	 	RHC_L -> SetLineColor(38);
	 	RHC_L -> SetLineStyle(2); 
	 	RHC_L -> SetLineWidth(3); 
	}

	if( model == "M1" ){
		M1    -> SetLineColor(30);
		M1    -> SetLineStyle(1); 
		M1    -> SetLineWidth(3); 		
	}
	
	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Tl208    );
	Stack->Add(Bi214    );
	Stack->Add(K40      );
	Stack->Add(Pa234m   );
	Stack->Add(Bi210    );
	Stack->Add(Radon    );
	Stack->Add(Externals);
	Stack->Add(BB       );
	
	THStack * Stack_S = Stack->Clone("Stack_S");

	if ( model == "MM"    ) Stack_S->Add(MM);
	if ( model == "RHC_L" ) Stack_S->Add(RHC_L);
	if ( model == "RHC_E" ) Stack_S->Add(RHC_E);
	if ( model == "M1"     ) Stack_S->Add(M1);
	
		
	TH1D * Sum = Tl208->Clone( "Sum" );
	Sum->Add(Bi214    );
	Sum->Add(Radon    );
	Sum->Add(Externals);
	Sum->Add(BB       );
	Sum->Add(Pa234m   );
	Sum->Add(K40      );
	Sum->Add(Bi210    );
	
	TCanvas * Canvas = new TCanvas("TwoElectronEnergy", "TwoElectronEnergy", 500, 500);
	
    Bool_t _LogScale    = kTRUE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);

    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.01);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("E_{Tot} (MeV)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
		
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.1) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(0.25,1.75) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    	
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-3.5,3.5) ;
            
    TLegend * Leg = new TLegend(0.59,0.8,0.92,0.52)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( BB          , "2#nu#beta#beta" , "F"  );	
	Leg->AddEntry( Externals   , "External"       , "F"  );	
	Leg->AddEntry( Radon       , "Radon"          , "F"  );
	Leg->AddEntry( Bi210       , "^{210}Bi"       , "F"  );	
	Leg->AddEntry( Pa234m      , "^{234m}Pa"      , "F"  );			
	Leg->AddEntry( K40     	   , "^{40}K"         , "F"  );
	Leg->AddEntry( Bi214       , "^{214}Bi"       , "F"  );
	Leg->AddEntry( Tl208       , "^{208}Tl"       , "F"  );

    if ( model == "MM"    ) Leg->AddEntry( MM    , "#LT m_{#beta#beta} #GT" , "L"  );
	if ( model == "RHC_E" ) Leg->AddEntry( RHC_E , "#LT #eta #GT"           , "L"  );
	if ( model == "RHC_L" ) Leg->AddEntry( RHC_L , "#LT #lambda #GT"        , "L"  );
	if ( model == "M1"    ) Leg->AddEntry( M1    , "#chi^{0}_{n=1}"         , "L"  );

    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(0.6,3.5) ;    
	Ratio-> GetXaxis()->SetRangeUser(0.6,3.5) ;        
    Res  -> GetXaxis()->SetRangeUser(0.6,3.5) ;    

    pad1->cd() ;    
    Data->Draw(""); 
    Stack_S->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();
	
    pad2->cd() ;
    Ratio->Draw("P0"); 
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
	Ratio->Draw("P0same"); 

    pad3->cd(); 
    Res->Draw("P0"); 
	pad3->Update();
	TLine * LineRes = new TLine(pad3->GetUxmin(),0,pad3->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same"); 

    pad1->cd() ;
    Leg->Draw(); 

	Canvas->cd();
	Canvas->Update();

	
};

void DrawTwoElectronEnergyZoom(){
	
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	HistoCollection * hcoll= new HistoCollection("TwoElectronHistosZoom", "TwoElectronHistosZoom");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/TwoElectronIntHistos.root");
	
	TDirectory * fdir = 0;
	TIter next(DataManagement::GetDataSetCollection()); DataSet * ds;	
	while( ds = (DataSet*) next() ){
		fdir = (TDirectory *) f->Get(ds->GetName()); fdir->cd();
		hcoll->Load(fdir);
	}
	
	TH1D * Data = (TH1D*) hcoll->Find( "Data_h_tot_e_energy" );
	
    Double_t Cd116_Tl208_weight     = 5.93241           ;
    Double_t Cd116_Ac228_weight     = 6.92004           ;
    Double_t Cd116_Bi212_weight     = 2.74493           ;
    Double_t Cd116_Bi214_weight     = 18.2853           ;
    Double_t Cd116_Pb214_weight     = 0.186478          ;
    Double_t Mylar_Bi214_weight     = 11.1896           ;
    Double_t Mylar_Pb214_weight     = 0.493241          ;
    Double_t Cd116_K40_weight       = 25.9835+9.02952   ;
    Double_t Cd116_Pa234m_weight    = 27.7433+72.4378   ;
    Double_t SFoil_Bi210_weight     = 23.243            ;
    Double_t SWire_Bi210_weight     = 0.136147+0.624186 ;
    Double_t SScin_Bi210_weight     = 1.756             ;
    Double_t SScin_Bi214_weight     = 0.050538          ;
    Double_t SWire_Tl208_weight     = 0.217623+1.07644  ;
    Double_t SWire_Bi214_weight     = 21.4626+17.9578   ;
    Double_t SFoil_Bi214_weight     = 5.77558+2.73528   ;
    Double_t SWire_Pb214_weight     = 0.457546+0.648406 ;
    Double_t SFoil_Pb214_weight     = 0.215627+0.188876 ;
    Double_t FeShield_Bi214_weight  = 49.1846           ;
    Double_t FeShield_Tl208_weight  = 1.19312           ;
    Double_t FeShield_Ac228_weight  = 0.17612           ;
    Double_t CuTower_Co60_weight    = 3.77603           ;
    Double_t Air_Bi214_P1_weight    = 4.19271           ;
    Double_t PMT_Bi214_weight       = 30.7385           ;
    Double_t PMT_Tl208_weight       = 23.2701           ;
    Double_t PMT_Ac228_weight       = 3.60944           ;
    Double_t PMT_K40_weight         = 16.7905           ;
    Double_t ScintInn_K40_weight    = 0.335557          ;
    Double_t ScintOut_K40_weight    = 0.604003          ;
    Double_t ScintPet_K40_weight    = 1.00666           ;
    Double_t MuMetal_Pa234m_weight  = 0.66462           ;

    Double_t BB_weight              = 5022.22           ;	
    //Double_t MM_weight              = 71.2  * 0.09208   ;
	Double_t MM_weight              = 74.7  * 0.09208   ;
    Double_t RHC_E_weight           = 56.8  * 0.07510   ;
    Double_t RHC_L_weight           = 130.7 * 0.04758   ;     
    Double_t M1_weight              = 878.2 * 0.06308   ;
	
	TH1D * Cd116_Tl208    = (TH1D*) hcoll->Find( "Cd116_Tl208_h_tot_e_energy"     ); Cd116_Tl208    -> Scale( Cd116_Tl208_weight    / Cd116_Tl208    ->Integral() );
	TH1D * Cd116_Ac228    = (TH1D*) hcoll->Find( "Cd116_Ac228_h_tot_e_energy"     ); Cd116_Ac228    -> Scale( Cd116_Ac228_weight    / Cd116_Ac228    ->Integral() );
	TH1D * Cd116_Bi212    = (TH1D*) hcoll->Find( "Cd116_Bi212_h_tot_e_energy"     ); Cd116_Bi212    -> Scale( Cd116_Bi212_weight    / Cd116_Bi212    ->Integral() );
	TH1D * Cd116_Bi214    = (TH1D*) hcoll->Find( "Cd116_Bi214_h_tot_e_energy"     ); Cd116_Bi214    -> Scale( Cd116_Bi214_weight    / Cd116_Bi214    ->Integral() );
	TH1D * Cd116_Pb214    = (TH1D*) hcoll->Find( "Cd116_Pb214_VT_h_tot_e_energy"  ); Cd116_Pb214    -> Scale( Cd116_Pb214_weight    / Cd116_Pb214    ->Integral() );
	TH1D * Mylar_Bi214    = (TH1D*) hcoll->Find( "Mylar_Bi214_h_tot_e_energy"     ); Mylar_Bi214    -> Scale( Mylar_Bi214_weight    / Mylar_Bi214    ->Integral() );
	TH1D * Mylar_Pb214    = (TH1D*) hcoll->Find( "Mylar_Pb214_h_tot_e_energy"     ); Mylar_Pb214    -> Scale( Mylar_Pb214_weight    / Mylar_Pb214    ->Integral() );
	TH1D * Cd116_K40      = (TH1D*) hcoll->Find( "Cd116_K40_h_tot_e_energy"       ); Cd116_K40      -> Scale( Cd116_K40_weight      / Cd116_K40      ->Integral() );
	TH1D * Cd116_Pa234m   = (TH1D*) hcoll->Find( "Cd116_Pa234m_h_tot_e_energy"    ); Cd116_Pa234m   -> Scale( Cd116_Pa234m_weight   / Cd116_Pa234m   ->Integral() );
	TH1D * SFoil_Bi210    = (TH1D*) hcoll->Find( "SFoil_Bi210_h_tot_e_energy"     ); SFoil_Bi210    -> Scale( SFoil_Bi210_weight    / SFoil_Bi210    ->Integral() );
	TH1D * SWire_Bi210    = (TH1D*) hcoll->Find( "SWire_Bi210_h_tot_e_energy"     ); SWire_Bi210    -> Scale( SWire_Bi210_weight    / SWire_Bi210    ->Integral() );
	TH1D * SScin_Bi210    = (TH1D*) hcoll->Find( "SScin_Bi210_h_tot_e_energy"     ); SScin_Bi210    -> Scale( SScin_Bi210_weight    / SScin_Bi210    ->Integral() );
	TH1D * SScin_Bi214    = (TH1D*) hcoll->Find( "SScin_Bi214_h_tot_e_energy"     ); SScin_Bi214    -> Scale( SScin_Bi214_weight    / SScin_Bi214    ->Integral() );
	TH1D * SWire_Tl208    = (TH1D*) hcoll->Find( "SWire_Tl208_h_tot_e_energy"     ); SWire_Tl208    -> Scale( SWire_Tl208_weight    / SWire_Tl208    ->Integral() );
	TH1D * SWire_Bi214    = (TH1D*) hcoll->Find( "SWire_Bi214_h_tot_e_energy"     ); SWire_Bi214    -> Scale( SWire_Bi214_weight    / SWire_Bi214    ->Integral() );
	TH1D * SFoil_Bi214    = (TH1D*) hcoll->Find( "SFoil_Bi214_h_tot_e_energy"     ); SFoil_Bi214    -> Scale( SFoil_Bi214_weight    / SFoil_Bi214    ->Integral() );
	TH1D * SWire_Pb214    = (TH1D*) hcoll->Find( "SWire_Pb214_h_tot_e_energy"     ); SWire_Pb214    -> Scale( SWire_Pb214_weight    / SWire_Pb214    ->Integral() );
	TH1D * SFoil_Pb214    = (TH1D*) hcoll->Find( "SFoil_Pb214_h_tot_e_energy"     ); SFoil_Pb214    -> Scale( SFoil_Pb214_weight    / SFoil_Pb214    ->Integral() );
	TH1D * FeShield_Bi214 = (TH1D*) hcoll->Find( "FeShield_Bi214_h_tot_e_energy"  ); FeShield_Bi214 -> Scale( FeShield_Bi214_weight / FeShield_Bi214 ->Integral() );
	TH1D * FeShield_Tl208 = (TH1D*) hcoll->Find( "FeShield_Tl208_h_tot_e_energy"  ); FeShield_Tl208 -> Scale( FeShield_Tl208_weight / FeShield_Tl208 ->Integral() );
	TH1D * FeShield_Ac228 = (TH1D*) hcoll->Find( "FeShield_Ac228_h_tot_e_energy"  ); FeShield_Ac228 -> Scale( FeShield_Ac228_weight / FeShield_Ac228 ->Integral() );
	TH1D * CuTower_Co60   = (TH1D*) hcoll->Find( "CuTower_Co60_h_tot_e_energy"    ); CuTower_Co60   -> Scale( CuTower_Co60_weight   / CuTower_Co60   ->Integral() );
	TH1D * Air_Bi214_P1   = (TH1D*) hcoll->Find( "Air_Bi214_h_tot_e_energy"       ); Air_Bi214_P1   -> Scale( Air_Bi214_P1_weight   / Air_Bi214_P1   ->Integral() );
	TH1D * PMT_Bi214      = (TH1D*) hcoll->Find( "PMT_Bi214_h_tot_e_energy"       ); PMT_Bi214      -> Scale( PMT_Bi214_weight      / PMT_Bi214      ->Integral() );
	TH1D * PMT_Tl208      = (TH1D*) hcoll->Find( "PMT_Tl208_h_tot_e_energy"       ); PMT_Tl208      -> Scale( PMT_Tl208_weight      / PMT_Tl208      ->Integral() );
	TH1D * PMT_Ac228      = (TH1D*) hcoll->Find( "PMT_Ac228_h_tot_e_energy"       ); PMT_Ac228      -> Scale( PMT_Ac228_weight      / PMT_Ac228      ->Integral() );
	TH1D * PMT_K40        = (TH1D*) hcoll->Find( "PMT_K40_h_tot_e_energy"         ); PMT_K40        -> Scale( PMT_K40_weight        / PMT_K40        ->Integral() );
	TH1D * ScintInn_K40   = (TH1D*) hcoll->Find( "ScintInn_K40_h_tot_e_energy"    ); ScintInn_K40   -> Scale( ScintInn_K40_weight   / ScintInn_K40   ->Integral() );
	TH1D * ScintOut_K40   = (TH1D*) hcoll->Find( "ScintOut_K40_h_tot_e_energy"    ); ScintOut_K40   -> Scale( ScintOut_K40_weight   / ScintOut_K40   ->Integral() );
	TH1D * ScintPet_K40   = (TH1D*) hcoll->Find( "ScintPet_K40_h_tot_e_energy"    ); ScintPet_K40   -> Scale( ScintPet_K40_weight   / ScintPet_K40   ->Integral() );
	TH1D * MuMetal_Pa234m = (TH1D*) hcoll->Find( "MuMetal_Pa234m_h_tot_e_energy"  ); MuMetal_Pa234m -> Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m ->Integral() );
	TH1D * BB             = (TH1D*) hcoll->Find( "Cd116_2b2n_m14_h_tot_e_energy"  ); BB             -> Scale( BB_weight             / BB             ->Integral() );
	TH1D * MM             = (TH1D*) hcoll->Find( "Cd116_2b0n_m1_h_tot_e_energy"    ); MM             -> Scale( MM_weight             / MM             ->Integral() );
    TH1D * RHC_E          = (TH1D*) hcoll->Find( "Cd116_2b0n_m18_h_tot_e_energy"  ); RHC_E          -> Scale( RHC_E_weight          / RHC_E          ->Integral() );
    TH1D * RHC_L          = (TH1D*) hcoll->Find( "Cd116_2b0n_m2_h_tot_e_energy"   ); RHC_L          -> Scale( RHC_L_weight          / RHC_L          ->Integral() );
    TH1D * M1             = (TH1D*) hcoll->Find( "Cd116_2b0n_m5_h_tot_e_energy"   ); M1             -> Scale( M1_weight             / M1             ->Integral() );

    TH1D * Tl208 = SWire_Tl208->Clone("Tl208");
    Tl208->Add( Cd116_Tl208 );
    Tl208->Add( Cd116_Ac228 );
    Tl208->Add( Cd116_Bi212 );
    
    TH1D * Bi214 = Mylar_Bi214->Clone("Bi214") ;
    Bi214->Add( Mylar_Pb214 );
    Bi214->Add( Cd116_Bi214 );
    Bi214->Add( Cd116_Pb214 );
    
    TH1D * K40 = Cd116_K40->Clone("K40") ;
    
    TH1D * Pa234m = Cd116_Pa234m->Clone("Pa234m");
    
    TH1D * Bi210 = SFoil_Bi210->Clone("Bi210"); 
    Bi210->Add( SWire_Bi210   );
    
    TH1D * Radon = SWire_Bi214->Clone("Radon") ;
    Radon->Add( SWire_Pb214 );
    Radon->Add( SFoil_Bi214 );
    Radon->Add( SFoil_Pb214 );
    	
    TH1D * Externals = FeShield_Bi214->Clone("Externals");
    Externals->Add( FeShield_Tl208 );
    Externals->Add( FeShield_Ac228 );
    Externals->Add( CuTower_Co60   );
    Externals->Add( Air_Bi214_P1   );
    Externals->Add( PMT_Bi214      );
    Externals->Add( PMT_Tl208      );
    Externals->Add( PMT_Ac228      );
    Externals->Add( PMT_K40        );
    Externals->Add( ScintInn_K40   );
    Externals->Add( ScintOut_K40   );
    Externals->Add( ScintPet_K40   );
    Externals->Add( SScin_Bi210    );
    Externals->Add( SScin_Bi214    );
    Externals->Add( MuMetal_Pa234m );

	Tl208     -> SetFillColor( kOrange + 10 );
	Bi214     -> SetFillColor( kGreen  +  0 );
	Radon     -> SetFillColor( kAzure  +  1 );
	Externals -> SetFillColor( kOrange +  0 );
	BB        -> SetFillColor( kViolet + 10 );
	Pa234m    -> SetFillColor( kViolet +  1 );
	K40       -> SetFillColor( kViolet +  2 );
	Bi210     -> SetFillColor( kGreen  +  2 );
	
    MM    -> SetLineColor(46);
    RHC_L -> SetLineColor(38);
    RHC_E -> SetLineColor(38);
    M1    -> SetLineColor(30);

    MM    -> SetLineStyle(1); 
    RHC_L -> SetLineStyle(2); 
    RHC_E -> SetLineStyle(3); 
    M1    -> SetLineStyle(1); 


    MM    -> SetLineWidth(3); 
    RHC_L -> SetLineWidth(3); 
    RHC_E -> SetLineWidth(3); 
    M1    -> SetLineWidth(3); 
	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Tl208    );
	Stack->Add(Bi214    );
	Stack->Add(K40      );
	Stack->Add(Pa234m   );
	Stack->Add(Bi210    );
	Stack->Add(Radon    );
	Stack->Add(Externals);
	Stack->Add(BB       );
		
	THStack * Stack_MM = Stack->Clone("Stack_MM");
	Stack_MM->Add(MM);

	THStack * Stack_RHC_L = Stack->Clone("Stack_RHC_L");
	Stack_RHC_L->Add(RHC_L);

	THStack * Stack_RHC_E = Stack->Clone("Stack_RHC_E");
	Stack_RHC_E->Add(RHC_E);

	THStack * Stack_M1 = Stack->Clone("Stack_M1");
	Stack_M1->Add(M1);

	TH1D * Sum = Tl208->Clone( "Sum" );
	Sum->Add(Bi214    );
	Sum->Add(Radon    );
	Sum->Add(Externals);
	Sum->Add(BB       );
	Sum->Add(Pa234m   );
	Sum->Add(K40      );
	Sum->Add(Bi210    );

	TCanvas * Canvas = new TCanvas("TwoElectronEnergyZoom", "TwoElectronEnergyZoom", 500, 500);
	
    Bool_t _LogScale    = kTRUE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    TPad * pad1 = new TPad("pad1", "pad1", 0., 0., 1.0, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.14)  ;
    pad1->SetBottomMargin(0.15);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("E_{Tot} (MeV)") ;
    Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
	Data->GetXaxis()->SetTitleOffset(1.4);
				           
    TLegend * Leg = new TLegend(0.59,0.8,0.92,0.42)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( BB          , "2#nu#beta#beta" , "F"  );	
	Leg->AddEntry( Externals   , "External"       , "F"  );	
	Leg->AddEntry( Radon       , "Radon"          , "F"  );
	Leg->AddEntry( Bi210       , "^{210}Bi"       , "F"  );	
	Leg->AddEntry( Pa234m      , "^{234m}Pa"      , "F"  );			
	Leg->AddEntry( K40     	   , "^{40}K"         , "F"  );
	Leg->AddEntry( Bi214       , "^{214}Bi"       , "F"  );
	Leg->AddEntry( Tl208       , "^{208}Tl"       , "F"  );
	Leg->AddEntry( MM          , "#LT m_{#beta#beta} #GT" , "L"  );
	Leg->AddEntry( RHC_E       , "#LT #eta #GT"           , "L"  );
	Leg->AddEntry( RHC_L       , "#LT #lambda #GT"        , "L"  );
	Leg->AddEntry( M1          , " #chi^{0}_{n=1}"                , "L"  );

    Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(2.01,3.5) ;    

	pad1->cd();
    Data->Draw() ;
    Stack_MM->Draw("A,SAME,HIST");
    Stack_RHC_L->Draw("A,SAME,HIST");
    Stack_RHC_E->Draw("A,SAME,HIST");
    Stack_M1->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	Data->GetYaxis()->DrawClone("") ;
    Leg->Draw(); 
	pad1->RedrawAxis();

	Canvas->cd();
	Canvas->Update();

		
};

void DrawBDT( char * model = "MM"){
	
    TFile * f = new TFile( TString::Format("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/TMVApp/TMVApp_%s.root", model ) , "READ" );

	
	TH1D * Data = (TH1D*) f->Get( "Data_MVA_BDT" );
 	Data->Sumw2(); //Data->Rebin(2);
	
	Double_t Cd116_Tl208_weight     = 5.93241           ;
	Double_t Cd116_Ac228_weight     = 6.92004           ;
	Double_t Cd116_Bi212_weight     = 2.74493           ;
	Double_t Cd116_Bi214_weight     = 18.2853           ;
	Double_t Cd116_Pb214_weight     = 0.186478          ;
	Double_t Mylar_Bi214_weight     = 11.1896           ;
	Double_t Mylar_Pb214_weight     = 0.493241          ;
	Double_t Cd116_K40_weight       = 25.9835+9.02952   ;
	Double_t Cd116_Pa234m_weight    = 27.7433+72.4378   ;
	Double_t SFoil_Bi210_weight     = 23.243            ;
	Double_t SWire_Bi210_weight     = 0.136147+0.624186 ;
	Double_t SScin_Bi210_weight     = 1.756             ;
	Double_t SScin_Bi214_weight     = 0.050538          ;
	Double_t SWire_Tl208_weight     = 0.217623+1.07644  ;
	Double_t SWire_Bi214_weight     = 21.4626+17.9578   ;
	Double_t SFoil_Bi214_weight     = 5.77558+2.73528   ;
	Double_t SWire_Pb214_weight     = 0.457546+0.648406 ;
	Double_t SFoil_Pb214_weight     = 0.215627+0.188876 ;
	Double_t FeShield_Bi214_weight  = 49.1846           ;
	Double_t FeShield_Tl208_weight  = 1.19312           ;
	Double_t FeShield_Ac228_weight  = 0.17612           ;
	Double_t CuTower_Co60_weight    = 3.77603           ;
	Double_t Air_Bi214_P1_weight    = 4.19271           ;
	Double_t PMT_Bi214_weight       = 30.7385           ;
	Double_t PMT_Tl208_weight       = 23.2701           ;
	Double_t PMT_Ac228_weight       = 3.60944           ;
	Double_t PMT_K40_weight         = 16.7905           ;
	Double_t ScintInn_K40_weight    = 0.335557          ;
	Double_t ScintOut_K40_weight    = 0.604003          ;
	Double_t ScintPet_K40_weight    = 1.00666           ;
	Double_t MuMetal_Pa234m_weight  = 0.66462           ;
	
	Double_t BB_weight              = 5022.22           ;	
	//Double_t MM_weight              = 71.2  * 0.09208   ;
	Double_t MM_weight              = 74.7  * 0.09208   ;
	Double_t RHC_E_weight           = 56.8  * 0.07510   ;
	Double_t RHC_L_weight           = 130.7 * 0.04758   ;     
	Double_t M1_weight              = 878.2 * 0.06308   ;
	
	TH1D * Cd116_Tl208    = (TH1D*) f->Get( "Cd116_Tl208_MVA_BDT"           ); Cd116_Tl208    -> Scale( Cd116_Tl208_weight    / Cd116_Tl208    ->Integral() ); 
	TH1D * Cd116_Ac228    = (TH1D*) f->Get( "Cd116_Ac228_MVA_BDT"           ); Cd116_Ac228    -> Scale( Cd116_Ac228_weight    / Cd116_Ac228    ->Integral() ); 
	TH1D * Cd116_Bi212    = (TH1D*) f->Get( "Cd116_Bi212_MVA_BDT"           ); Cd116_Bi212    -> Scale( Cd116_Bi212_weight    / Cd116_Bi212    ->Integral() ); 
	TH1D * Cd116_Bi214    = (TH1D*) f->Get( "Cd116_Bi214_MVA_BDT"           ); Cd116_Bi214    -> Scale( Cd116_Bi214_weight    / Cd116_Bi214    ->Integral() ); 
	TH1D * Cd116_Pb214    = (TH1D*) f->Get( "Cd116_Pb214_VT_MVA_BDT"        ); Cd116_Pb214    -> Scale( Cd116_Pb214_weight    / Cd116_Pb214    ->Integral() ); 
	TH1D * Mylar_Bi214    = (TH1D*) f->Get( "Mylar_Bi214_MVA_BDT"           ); Mylar_Bi214    -> Scale( Mylar_Bi214_weight    / Mylar_Bi214    ->Integral() ); 
	TH1D * Mylar_Pb214    = (TH1D*) f->Get( "Mylar_Pb214_MVA_BDT"           ); Mylar_Pb214    -> Scale( Mylar_Pb214_weight    / Mylar_Pb214    ->Integral() ); 
	TH1D * Cd116_K40      = (TH1D*) f->Get( "Cd116_K40_MVA_BDT"             ); Cd116_K40      -> Scale( Cd116_K40_weight      / Cd116_K40      ->Integral() ); 
	TH1D * Cd116_Pa234m   = (TH1D*) f->Get( "Cd116_Pa234m_MVA_BDT"          ); Cd116_Pa234m   -> Scale( Cd116_Pa234m_weight   / Cd116_Pa234m   ->Integral() ); 
	TH1D * SFoil_Bi210    = (TH1D*) f->Get( "SFoil_Bi210_MVA_BDT"           ); SFoil_Bi210    -> Scale( SFoil_Bi210_weight    / SFoil_Bi210    ->Integral() ); 
	TH1D * SWire_Bi210    = (TH1D*) f->Get( "SWire_Bi210_MVA_BDT"           ); SWire_Bi210    -> Scale( SWire_Bi210_weight    / SWire_Bi210    ->Integral() ); 
	TH1D * SScin_Bi210    = (TH1D*) f->Get( "SScin_Bi210_MVA_BDT"           ); SScin_Bi210    -> Scale( SScin_Bi210_weight    / SScin_Bi210    ->Integral() ); 
	TH1D * SScin_Bi214    = (TH1D*) f->Get( "SScin_Bi214_MVA_BDT"           ); SScin_Bi214    -> Scale( SScin_Bi214_weight    / SScin_Bi214    ->Integral() ); 
	TH1D * SWire_Tl208    = (TH1D*) f->Get( "SWire_Tl208_MVA_BDT"           ); SWire_Tl208    -> Scale( SWire_Tl208_weight    / SWire_Tl208    ->Integral() ); 
	TH1D * SWire_Bi214    = (TH1D*) f->Get( "SWire_Bi214_MVA_BDT"           ); SWire_Bi214    -> Scale( SWire_Bi214_weight    / SWire_Bi214    ->Integral() ); 
	TH1D * SFoil_Bi214    = (TH1D*) f->Get( "SFoil_Bi214_MVA_BDT"           ); SFoil_Bi214    -> Scale( SFoil_Bi214_weight    / SFoil_Bi214    ->Integral() ); 
	TH1D * SWire_Pb214    = (TH1D*) f->Get( "SWire_Pb214_MVA_BDT"           ); SWire_Pb214    -> Scale( SWire_Pb214_weight    / SWire_Pb214    ->Integral() ); 
	TH1D * SFoil_Pb214    = (TH1D*) f->Get( "SFoil_Pb214_MVA_BDT"           ); SFoil_Pb214    -> Scale( SFoil_Pb214_weight    / SFoil_Pb214    ->Integral() ); 
	TH1D * FeShield_Bi214 = (TH1D*) f->Get( "FeShield_Bi214_MVA_BDT"        ); FeShield_Bi214 -> Scale( FeShield_Bi214_weight / FeShield_Bi214 ->Integral() ); 
	TH1D * FeShield_Tl208 = (TH1D*) f->Get( "FeShield_Tl208_MVA_BDT"        ); FeShield_Tl208 -> Scale( FeShield_Tl208_weight / FeShield_Tl208 ->Integral() ); 
	TH1D * FeShield_Ac228 = (TH1D*) f->Get( "FeShield_Ac228_MVA_BDT"        ); FeShield_Ac228 -> Scale( FeShield_Ac228_weight / FeShield_Ac228 ->Integral() ); 
	TH1D * CuTower_Co60   = (TH1D*) f->Get( "CuTower_Co60_MVA_BDT"          ); CuTower_Co60   -> Scale( CuTower_Co60_weight   / CuTower_Co60   ->Integral() ); 
	TH1D * Air_Bi214_P1   = (TH1D*) f->Get( "Air_Bi214_MVA_BDT"             ); Air_Bi214_P1   -> Scale( Air_Bi214_P1_weight   / Air_Bi214_P1   ->Integral() ); 
	TH1D * PMT_Bi214      = (TH1D*) f->Get( "PMT_Bi214_MVA_BDT"             ); PMT_Bi214      -> Scale( PMT_Bi214_weight      / PMT_Bi214      ->Integral() ); 
	TH1D * PMT_Tl208      = (TH1D*) f->Get( "PMT_Tl208_MVA_BDT"             ); PMT_Tl208      -> Scale( PMT_Tl208_weight      / PMT_Tl208      ->Integral() ); 
	TH1D * PMT_Ac228      = (TH1D*) f->Get( "PMT_Ac228_MVA_BDT"             ); PMT_Ac228      -> Scale( PMT_Ac228_weight      / PMT_Ac228      ->Integral() ); 
	TH1D * PMT_K40        = (TH1D*) f->Get( "PMT_K40_MVA_BDT"               ); PMT_K40        -> Scale( PMT_K40_weight        / PMT_K40        ->Integral() ); 
	TH1D * ScintInn_K40   = (TH1D*) f->Get( "ScintInn_K40_MVA_BDT"          ); ScintInn_K40   -> Scale( ScintInn_K40_weight   / ScintInn_K40   ->Integral() ); 
	TH1D * ScintOut_K40   = (TH1D*) f->Get( "ScintOut_K40_MVA_BDT"          ); ScintOut_K40   -> Scale( ScintOut_K40_weight   / ScintOut_K40   ->Integral() ); 
	TH1D * ScintPet_K40   = (TH1D*) f->Get( "ScintPet_K40_MVA_BDT"          ); ScintPet_K40   -> Scale( ScintPet_K40_weight   / ScintPet_K40   ->Integral() ); 
	TH1D * MuMetal_Pa234m = (TH1D*) f->Get( "MuMetal_Pa234m_MVA_BDT"        ); MuMetal_Pa234m -> Scale( MuMetal_Pa234m_weight / MuMetal_Pa234m ->Integral() ); 
	TH1D * BB             = (TH1D*) f->Get( "Cd116_2b2n_m14_MVA_BDT"        ); BB             -> Scale( BB_weight             / BB             ->Integral() ); 

	if(model == "MM" )    { TH1D * MM             = (TH1D*) f->Get( "Cd116_2b0n_m1_MVA_BDT"         ); MM             -> Scale( MM_weight             / MM             ->Integral() );} 
	if(model == "RHC_E" ) { TH1D * RHC_E          = (TH1D*) f->Get( "Cd116_2b0n_m18_MVA_BDT"        ); RHC_E          -> Scale( RHC_E_weight          / RHC_E          ->Integral() );} 
	if(model == "RHC_L" ) { TH1D * RHC_L          = (TH1D*) f->Get( "Cd116_2b0n_m2_MVA_BDT"         ); RHC_L          -> Scale( RHC_L_weight          / RHC_L          ->Integral() );} 
	if(model == "M1"    ) { TH1D * M1             = (TH1D*) f->Get( "Cd116_2b0n_m5_MVA_BDT"         ); M1             -> Scale( M1_weight             / M1             ->Integral() );} 
	
	TH1D * Tl208 = SWire_Tl208->Clone("Tl208");
	Tl208->Add( Cd116_Tl208 );
	Tl208->Add( Cd116_Ac228 );
	Tl208->Add( Cd116_Bi212 );
	
	TH1D * Bi214 = Mylar_Bi214->Clone("Bi214") ;
	Bi214->Add( Mylar_Pb214 );
	Bi214->Add( Cd116_Bi214 );
	Bi214->Add( Cd116_Pb214 );
	
	TH1D * K40 = Cd116_K40->Clone("K40") ;
	
	TH1D * Pa234m = Cd116_Pa234m->Clone("Pa234m");
	
	TH1D * Bi210 = SFoil_Bi210->Clone("Bi210"); 
	Bi210->Add( SWire_Bi210   );
	
	TH1D * Radon = SWire_Bi214->Clone("Radon") ;
	Radon->Add( SWire_Pb214 );
	Radon->Add( SFoil_Bi214 );
	Radon->Add( SFoil_Pb214 );
	
	TH1D * Externals = FeShield_Bi214->Clone("Externals");
	Externals->Add( FeShield_Tl208 );
	Externals->Add( FeShield_Ac228 );
	Externals->Add( CuTower_Co60   );
	Externals->Add( Air_Bi214_P1   );
	Externals->Add( PMT_Bi214      );
	Externals->Add( PMT_Tl208      );
	Externals->Add( PMT_Ac228      );
	Externals->Add( PMT_K40        );
	Externals->Add( ScintInn_K40   );
	Externals->Add( ScintOut_K40   );
	Externals->Add( ScintPet_K40   );
	Externals->Add( SScin_Bi210    );
	Externals->Add( SScin_Bi214    );
	Externals->Add( MuMetal_Pa234m );
	
    Tl208     -> Rebin(2);
    Bi214     -> Rebin(2);
    Radon     -> Rebin(2);
    Externals -> Rebin(2);
    K40       -> Rebin(2);
    Pa234m    -> Rebin(2);
    Bi210     -> Rebin(2);
    BB        -> Rebin(2);    
    Data      -> Rebin(2);	
	
	if( model == "MM"    ) { MM    -> Rebin(2); }
	if( model == "RHC_E" ) { RHC_E -> Rebin(2); }
	if( model == "RHC_L" ) { RHC_L -> Rebin(2); }
	if( model == "M1"    ) { M1    -> Rebin(2); }
		
	Tl208     -> SetFillColor( kOrange + 10 );
	Bi214     -> SetFillColor( kGreen  +  0 );
	Radon     -> SetFillColor( kAzure  +  1 );
	Externals -> SetFillColor( kOrange +  0 );
	BB        -> SetFillColor( kViolet + 10 );
	Pa234m    -> SetFillColor( kViolet +  1 );
	K40       -> SetFillColor( kViolet +  2 );
	Bi210     -> SetFillColor( kGreen  +  2 );
	
	if( model == "MM"    ) {
		MM    -> SetLineColor(46);
		MM    -> SetLineStyle(1); 
		MM    -> SetLineWidth(3); 
	}
	
	if( model == "RHC_E" ) {
		RHC_E -> SetLineColor(38);
		RHC_E -> SetLineStyle(3); 
		RHC_E -> SetLineWidth(3); 
	}
	
	if ( model == "RHC_L" ) {
	 	RHC_L -> SetLineColor(38);
	 	RHC_L -> SetLineStyle(2); 
	 	RHC_L -> SetLineWidth(3); 
	}

	if( model == "M1" ){
		M1    -> SetLineColor(30);
		M1    -> SetLineStyle(1); 
		M1    -> SetLineWidth(3); 		
	}
	
	THStack * Stack = new THStack("stack","stack");
	Stack->Add(Tl208    );
	Stack->Add(Bi214    );
	Stack->Add(K40      );
	Stack->Add(Pa234m   );
	Stack->Add(Bi210    );
	Stack->Add(Radon    );
	Stack->Add(Externals);
	Stack->Add(BB       );
	
	THStack * Stack_S = Stack->Clone("Stack_S");

	if ( model == "MM"    ) Stack_S->Add(MM);
	if ( model == "RHC_L" ) Stack_S->Add(RHC_L);
	if ( model == "RHC_E" ) Stack_S->Add(RHC_E);
	if ( model == "M1"     ) Stack_S->Add(M1);
	
	TH1D * Sum = Tl208->Clone( "Sum" );
	Sum->Add(Bi214    );
	Sum->Add(Radon    );
	Sum->Add(Externals);
	Sum->Add(BB       );
	Sum->Add(Pa234m   );
	Sum->Add(K40      );
	Sum->Add(Bi210    );	
	
	TCanvas * Canvas = new TCanvas("TwoElectronEnergy", "TwoElectronEnergy", 500, 500);
	
    Bool_t _LogScale    = kTRUE  ;
    Bool_t _Grid        = kFALSE ;
    Style_t _MarkerStyle = 20     ;
    Size_t _MarkerSize  = 0.8    ;
    Color_t _MarkerColor = kBlack ;
	
    gStyle->SetTitleBorderSize(0);
    gStyle->SetLegendBorderSize(0);

    TPad * pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
    pad1->SetGrid(_Grid, _Grid);
    pad1->SetLogy( _LogScale ) ;
    pad1->SetTickx() ;
    pad1->SetTicky() ;
    pad1->SetTopMargin(0.15)  ;
    pad1->SetBottomMargin(0.01);  
    pad1->SetRightMargin(0.05)  ;
    pad1->Draw() ;
    pad1->cd() ;
        
    Data->SetTitle("NEMO-3 ^{116}Cd - 0.410 g, 5.26 y");
    Data->SetLineWidth(2) ;
    Data->SetMarkerColor( _MarkerColor ) ;
    Data->SetMarkerStyle( _MarkerStyle ) ;	
    Data->SetMarkerSize( _MarkerSize ) ;
    Data->SetStats(kFALSE) ;
    Data->GetXaxis()->SetTitle("BDT Score") ;
	Data->GetYaxis()->SetTitle("No.Events") ;
    Data->GetYaxis()->CenterTitle(kTRUE) ;
    Data->GetXaxis()->CenterTitle(kTRUE) ;
		
    Canvas->cd() ;	
    TPad * pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40) ;
    pad2->SetGrid(_Grid, _Grid);
    pad2->SetTopMargin(0.1) ;
    pad2->SetBottomMargin(0.01) ;
    pad2->SetRightMargin(0.05)  ;
    pad2->SetTickx() ;
    pad2->SetTicky() ;
    pad2->Draw() ;
    pad2->cd() ;
    
    TH1F * Ratio = Data->Clone( "Ratio" );
    Ratio->SetTitle("") ;
    Ratio->Divide(Sum) ;

    Ratio->GetYaxis()->SetNdivisions(105) ;  
	Ratio->GetXaxis()->SetTickLength(0.15);
    Ratio->GetYaxis()->SetTitle("Data/MC") ;  
    Ratio->GetYaxis()->CenterTitle(kTRUE) ;
    Ratio->GetYaxis()->SetRangeUser(-0.25,2.5) ;
    
    Canvas->cd() 	;
    TPad * pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25) ;
    pad3->SetGrid(_Grid, _Grid);
    pad3->SetTopMargin(0.1) ;
    pad3->SetBottomMargin(0.4) ;
    pad3->SetRightMargin(0.05);  
    pad3->SetTickx() ;
    pad3->SetTicky(); 
    pad3->Draw(); 
    
    TH1F * Res = Data->Clone( "Residual (#sigma)" ); 
    Res->SetTitle("") ;
    Res->Add(Sum, -1); 
    
    for ( int i = 1 ; i < Ratio->GetNbinsX()+1; i++){
    	
    	if (Ratio->GetBinError(i) == 0) continue; 
    	
    	Res->SetBinContent(i, Res->GetBinContent(i) / TMath::Sqrt( Sum->GetBinContent(i) ) );
    	Res->SetBinError(i, 1. );
		
    }
	
    Res->GetYaxis()->SetNdivisions(105)   ;
	Res->GetXaxis()->SetTickLength(0.10);
    Res->GetYaxis()->SetTitle("Residual (#sigma)") ;  
    Res->GetYaxis()->CenterTitle(kTRUE) ;
    Res->GetYaxis()->SetRangeUser(-3.5,3.5) ;
    	        
    TLegend * Leg = new TLegend(0.59,0.8,0.92,0.52)   ;      

    Leg->SetNColumns(2);
    Leg->SetLineWidth(0);

	Leg->AddEntry( BB          , "2#nu#beta#beta" , "F"  );	
	Leg->AddEntry( Externals   , "External"       , "F"  );	
	Leg->AddEntry( Radon       , "Radon"          , "F"  );
	Leg->AddEntry( Bi210       , "^{210}Bi"       , "F"  );	
	Leg->AddEntry( Pa234m      , "^{234m}Pa"      , "F"  );			
	Leg->AddEntry( K40     	   , "^{40}K"         , "F"  );
	Leg->AddEntry( Bi214       , "^{214}Bi"       , "F"  );
	Leg->AddEntry( Tl208       , "^{208}Tl"       , "F"  );
	
    if ( model == "MM"    ) Leg->AddEntry( MM    , "#LT m_{#beta#beta} #GT" , "L"  );
	if ( model == "RHC_E" ) Leg->AddEntry( RHC_E , "#LT #eta #GT"           , "L"  );
	if ( model == "RHC_L" ) Leg->AddEntry( RHC_L , "#LT #lambda #GT"        , "L"  );
	if ( model == "M1"    ) Leg->AddEntry( M1    , "#chi^{0}_{n=1}"         , "L"  );
	
	
	Leg->AddEntry( Data        , TString::Format("Data (%0.f)", Data->GetEntries()), "PL" ); 

    Data -> GetXaxis()->SetRangeUser(-0.4,0.4) ;    
	Ratio-> GetXaxis()->SetRangeUser(-0.4,0.4) ;        
    Res  -> GetXaxis()->SetRangeUser(-0.4,0.4) ;    

	if ( model == "M1"    ) {
    	Data -> GetXaxis()->SetRangeUser(-0.4,0.8 ) ;    
		Ratio-> GetXaxis()->SetRangeUser(-0.4,0.8 ) ;        
    	Res  -> GetXaxis()->SetRangeUser(-0.4,0.8 ) ;    
	}
	
    pad1->cd() ;    
    Data->Draw(""); 
    Stack_S->Draw("A,SAME,HIST");
    Data->Draw("SAME") ;
	pad1->RedrawAxis();
	
    pad2->cd() ;
    Ratio->Draw("P0");
	pad2->Update();
	TLine * LineRatio = new TLine(pad2->GetUxmin(),1,pad2->GetUxmax(),1);
	LineRatio->Draw("same");
    Ratio->Draw("P0same");
	
    pad3->cd(); 
    Res->Draw("P0");
	pad3->Update();
	TLine * LineRes = new TLine(pad3->GetUxmin(),0,pad3->GetUxmax(),0);
	LineRes->Draw("same");
	Res->Draw("P0same");

    pad1->cd() ;
    Leg->Draw(); 

	Canvas->cd();
	Canvas->Update();


};

void DrawComp(){

	TGraphErrors * comp_stat = new TGraphErrors(5);
	TGraphAsymmErrors * comp_syst = new TGraphAsymmErrors(5);
	TGraphAsymmErrors * this_work = new TGraphAsymmErrors(1);
	
	//comp_stat->GetYaxis()->SetTitleOffset(2.);
	//comp_stat->GetXaxis()->SetTitleOffset(2.);

	TH2F * frame = new TH2F("frame", "", 4, 2, 3.6, 5, 0, 5);
	frame->SetStats(kFALSE);
		
	frame->GetXaxis()->SetTitle("^{116}Cd 2#nu#beta#beta half-life (#times 10^{19} y)");	
	frame->GetXaxis()->CenterTitle(kTRUE) ;
	frame->GetXaxis()->SetTitleOffset(1.5);
		
	frame->GetYaxis()->SetBinLabel(1, "This work" );
	frame->GetYaxis()->SetBinLabel(2, "Aurora"  );
	frame->GetYaxis()->SetBinLabel(3, "Solotvina" );	
	frame->GetYaxis()->SetBinLabel(4, "NEMO-2"    );		
	frame->GetYaxis()->SetBinLabel(5, "ELEGANT-V" );		
				
	comp_stat->SetPoint(0, 2.74, 0.5 ); 
	comp_stat->SetPoint(1, 2.62, 1.5 ); 	
	comp_stat->SetPoint(2, 2.90, 2.5 );
	comp_stat->SetPoint(3, 2.90, 3.5 );	
	comp_stat->SetPoint(4, 2.60, 4.5 );

	comp_stat->SetPointError(0, 0.04, 0.0 ); 
	comp_stat->SetPointError(1, 0.02, 0.0 ); 	
	comp_stat->SetPointError(2, 0.06, 0.0 );
	comp_stat->SetPointError(3, 0.30, 0.0 );	
	comp_stat->SetPointError(4, 0.00, 0.0 );
		
	comp_stat->SetMarkerStyle(20);
	comp_stat->SetMarkerColor(kBlack);
	comp_stat->SetMarkerSize(1.0);	
	comp_stat->SetLineWidth(3);	
	
	comp_syst->SetPoint(0, 2.74, 0.5 ); 
	comp_syst->SetPoint(1, 2.62, 1.5 ); 	
	comp_syst->SetPoint(2, 2.90, 2.5 );
	comp_syst->SetPoint(3, 2.90, 3.5 );	
	comp_syst->SetPoint(4, 2.60, 4.5 );
	
	comp_syst->SetPointError(0, TMath::Sqrt(0.04**2 + 0.18**2) , TMath::Sqrt(0.04**2 + 0.18**2) , 0.06, 0.06); 
	comp_syst->SetPointError(1, TMath::Sqrt(0.02**2 + 0.14**2) , TMath::Sqrt(0.02**2 + 0.14**2) , 0.06, 0.06);
	comp_syst->SetPointError(2, TMath::Sqrt(0.06**2 + 0.38**2) , TMath::Sqrt(0.06**2 + 0.40**2) , 0.06, 0.06);
	comp_syst->SetPointError(3, TMath::Sqrt(0.30**2 + 0.20**2) , TMath::Sqrt(0.30**2 + 0.20**2) , 0.06, 0.06);	
	comp_syst->SetPointError(4, 0.5                            , 0.9                            , 0.06, 0.06);	
		
	comp_syst->SetMarkerStyle(1);
	comp_syst->SetMarkerColor(kBlack);
	comp_syst->SetMarkerSize(0.);	
	comp_syst->SetLineWidth(3);	
	comp_syst->SetFillColor(kGreen+1);	
	
	
	this_work->SetPoint(0, 2.74, 0.5 ); 
	this_work->SetPointError(0, TMath::Sqrt(0.04**2 + 0.18**2) , TMath::Sqrt(0.04**2 + 0.18**2), 0.06, 0.06); 
	this_work->SetMarkerStyle(1);
	this_work->SetMarkerColor(kBlack);
	this_work->SetMarkerSize(0.);	
	this_work->SetLineWidth(3);	
	this_work->SetFillColor(kOrange);	

	TCanvas * Canvas = new TCanvas("Comp", "Comp", 500, 500);
	
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0, 1, 1);
	pad1->SetLogx(kFALSE);
	pad1->SetGridx(kTRUE);
	pad1->SetGridy(kFALSE);
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.01) ;
	pad1->SetBottomMargin(0.1) ;
	pad1->SetRightMargin(0.1) ;
	pad1->SetLeftMargin(0.2) ;
	pad1->Draw();
	pad1->cd();

	frame->Draw();
	comp_syst->Draw("2");
	this_work->Draw("2");
	comp_stat->Draw("P0");
		
};