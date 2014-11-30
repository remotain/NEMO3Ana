{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectron);
	
	// Load one sample only for test
	DataManagement::AddDataSet ( new DataSet ( "Data" , 0, 0, 0 ) );

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
