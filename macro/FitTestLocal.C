{
	
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	// Load all histograms from OneElectron channel
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20141115/OneElectronHistos.root")
	HistoCollection * h = new HistoCollection("All", "All");	
	TIter next(_ObservableCollection); TH1D * obs;
	while( (d = (DataSet *) next(ProcessChannell::GetDataSetCollection())) ) {
		TDirectory * f0 = (TDirectory *) f->Get(d->GetName()); f0->cd();
		h->Load(f0);
	}

	// Add the list of observables to fit
	Fit::GetObservableCollection()->Add( h->Find("Data_h_e_energy_P1") );
	
	// Define the list of parameters to consider in the fit
	Fit::GetParameterCollection()->Add( new Parameter() );
	
	// Define the list of components to consider in the fit
	Fit::GetComponentCollection()->Add( new Component() );
	 	
	// Run the fit
	Fit::Run();	
		
}	