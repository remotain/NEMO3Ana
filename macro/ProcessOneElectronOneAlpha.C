{
		
	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAlphaDataSample.C+");

	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectronOneAlpha);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/sps/nemo/scratch/remoto/nemo3/data/ElectronAlpha/");
	ProcessChannel::SetInputFileName ("ElectronAlphaAnalysis_output.root");
	ProcessChannel::SetInputDirName  ("ElectronAlphaSearch");
	ProcessChannel::SetInputTreeName ("ElectronAlphaSearch");	
	ProcessChannel::SetOutputFilePath("/sps/nemo/scratch/remoto/nemo3/plot/");
	ProcessChannel::SetOutputFileName("OneElectronOneAlphaHistos.root");
	
	
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}
