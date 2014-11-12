{
		
	gSystem->Load("build/lib/libNEMO3Ana.dylib");
	gROOT->ProcessLine(".x macro/LoadAllDataSample.C+");

	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectron);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/Users/alberto/Software/SuperNEMO/work/nemo3/");
	ProcessChannel::SetInputFileName ("SingleElectronAnalysis_output.root");
	ProcessChannel::SetInputDirName  ("SingleElectronSearch");
	ProcessChannel::SetInputTreeName ("SingleElectronSearch");	
	ProcessChannel::SetOutputFilePath("/Users/alberto/Software/SuperNEMO/work/nemo3/plot_test/");
	ProcessChannel::SetOutputFileName("OneElectronHistos.root");
	
	
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}