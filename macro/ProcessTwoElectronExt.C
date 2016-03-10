{

	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kTwoElectronExternal);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/sps/nemo/scratch/remoto/nemo3/data/TwoElectronNtuples_Ext/");
	ProcessChannel::SetInputFileName ("TwoElectronNtuplizerExe_Ext_output.root");
	ProcessChannel::SetInputDirName  ("TwoElectronNtuplizer");
	ProcessChannel::SetInputTreeName ("TwoElectronNtuplizer");	
	ProcessChannel::SetOutputFilePath("/sps/nemo/scratch/remoto/nemo3/plot/");
	ProcessChannel::SetOutputFileName("TwoElectronExtHistos.root");
		
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}
