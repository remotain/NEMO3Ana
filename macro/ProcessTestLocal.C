{
		
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectron);
	
	// Load one sample only for test
	DataManagement::AddDataSet ( new DataSet ( "Data" , 0, 0, 0 ) );

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/Users/alberto/Software/SuperNEMO/work/nemo3/");
	ProcessChannel::SetInputFileName ("TwoElectronNtuplizerExe_Int_output.root");
	ProcessChannel::SetInputDirName  ("TwoElectronNtuplizer");
	ProcessChannel::SetInputTreeName ("TwoElectronNtuplizer");	
	ProcessChannel::SetOutputFilePath("/Users/alberto/Software/SuperNEMO/work/nemo3/plot_test/");
	ProcessChannel::SetOutputFileName("TwoElectronIntHistos.root");
	
	//ProcessChannel::SetFirstRunNumber(0);
	//ProcessChannel::SetLastRunNumber(5000);
	
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run(2000000);
	benchmark->Show("Run");
	
}
