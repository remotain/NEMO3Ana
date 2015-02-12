{
	// Use RooFit to fit Alpha time with A * e^(\lambda * t)
	// I would actually prefer to fit directly the halflife T_{1/2}

	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	// Load OneElectronHistos in HistoCollection
	HistoCollection * hcoll = new HistoCollection("OneElectronOneAlphaHistos", "OneElectronOneAlphaHistos");

	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150127/OneElectronOneAlphaHistos.root");
	TDirectory * fdir = 0;

	fdir = (TDirectory *) f->Get("Data"); fdir->cd();
	hcoll->Load(fdir);
	

	RooRealVar Time("Time","#alpha Time Delay", 0., 700.,"#mus"); 
		
	RooDataHist Hist("Hist", "Data", Time, hcoll->Find( "Data_h_alphaTime" ) );
	
	RooRealVar Bkg      ( "Bkg"      , "B"          , 0. , 0. , 10 ) ; 
	Bkg.setConstant(kTRUE);
	
	RooRealVar Activity ( "Activity" , "A"          , 1.60 , 0. , 2 ) ; 
	RooRealVar Thalf    ( "Thalf"    , "T_{1/2}"    , 164.3 , 0. , 200. ) ;
	//Thalf.setConstant(kTRUE);
	
	//RooGenericPdf Pdf("Pdf","Bkg + Activity * exp( - log(2) * Time / Thalf )",RooArgSet(Bkg, Activity, Time, Thalf)) ;
	RooGenericPdf Pdf("Pdf","Activity * exp( - log(2) * Time / Thalf )",RooArgSet(Activity, Time, Thalf)) ;
	
	Pdf.fitTo( Hist, RooFit::Range(20,640) );
	
	RooPlot* frame = Time.frame() ;
	Hist.plotOn(frame , RooFit::Name("Hist")) ;
	Pdf.plotOn(frame  , RooFit::Name("Pdf")) ;
	
	_canvas = new TCanvas("_canvas","_canvas") ;
    
	_canvas->SetTickx();
	_canvas->SetTopMargin(0.05) ;
	_canvas->SetRightMargin(0.05) ;
	_canvas->SetLeftMargin(0.20) ;
	_canvas->SetBottomMargin(0.20);
	_canvas->SetLogy(kTRUE);
	
	frame->GetYaxis()->SetRangeUser(6,800);
	frame->GetYaxis()->CenterTitle(kTRUE);
	frame->GetYaxis()->SetLabelFont(43);
	frame->GetYaxis()->SetLabelSize(25);
	frame->GetXaxis()->SetLabelFont(43);
	frame->GetXaxis()->SetLabelSize(25);
	frame->GetXaxis()->SetTitleFont(43);
	frame->GetXaxis()->SetTitleSize(25);
	frame->GetYaxis()->SetTitleFont(43);
	frame->GetYaxis()->SetTitleSize(25);
	frame->GetXaxis()->SetTitleOffset(1.55);
	frame->GetYaxis()->SetTitleOffset(1.55);
	frame->Draw();
	
	gStyle->SetOptTitle(kFALSE);
	
	TLegend * leg = new TLegend(0.25,0.26,0.55,0.62);
	
	leg->AddEntry(frame->findObject("Hist") , "Data", "PL");
	leg->AddEntry(frame->findObject("Pdf")  , "Model", "L");
	//leg->AddEntry((TObject *) 0,TString::Format("%s = %.2f #pm%.2f ", Bkg->GetTitle(), Bkg->getVal(), Bkg->getError()), ""); 		
	leg->AddEntry((TObject *) 0,TString::Format("%s = %.2f #pm%.2f ", Activity->GetTitle(), Activity->getVal(), Activity->getError()), ""); 		
	leg->AddEntry((TObject *) 0,TString::Format("%s = %.2f #pm%.2f #mus", Thalf->GetTitle(), Thalf->getVal(), Thalf->getError()), ""); 		
	leg->AddEntry((TObject *) 0,TString::Format("#chi^{2}/dof = %.2f ", frame->chiSquare("Pdf","Hist")), "");
	leg->SetFillColor(kWhite);
	leg->SetTextFont(43);
	leg->SetTextSize(15);
	leg->Draw();
	
	
	
	
}
