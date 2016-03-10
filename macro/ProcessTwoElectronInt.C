{

	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kTwoElectronInternal);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/sps/nemo/scratch/remoto/nemo3/data/TwoElectronNtuples_Int/");
	ProcessChannel::SetInputFileName ("TwoElectronNtuplizerExe_Int_output.root");
	ProcessChannel::SetInputDirName  ("TwoElectronNtuplizer");
	ProcessChannel::SetInputTreeName ("TwoElectronNtuplizer");	
	ProcessChannel::SetOutputFilePath("/sps/nemo/scratch/remoto/nemo3/plot/");
	ProcessChannel::SetOutputFileName("TwoElectronIntHistos.root");
	ProcessChannel::SetOutputTreeFileName("TwoElectronIntTree.root");	

	//ProcessChannel::SetOutputFileName("TwoElectronIntHistos_run_1872_7920.root");
	//ProcessChannel::SetFirstRunNumber(1872);
	//ProcessChannel::SetLastRunNumber(7920);
		
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}
