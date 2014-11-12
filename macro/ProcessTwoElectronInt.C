{
		
	gSystem->Load("build/lib/libNEMO3Ana.dylib");
	gROOT->ProcessLine(".x macro/LoadAllDataSample.C+");
	
	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kTwoElectronInternal);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/Users/alberto/Software/SuperNEMO/work/nemo3/");
	ProcessChannel::SetInputFileName ("TwoElectronNtuplizerExe_Int_output.root");
	ProcessChannel::SetInputDirName  ("TwoElectronNtuplizer");
	ProcessChannel::SetInputTreeName ("TwoElectronNtuplizer");	
	ProcessChannel::SetOutputFilePath("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/");
	ProcessChannel::SetOutputFileName("TwoElectronIntHistos.root");
		
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}