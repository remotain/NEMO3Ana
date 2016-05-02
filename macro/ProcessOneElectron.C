{
		
	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAllDataSample.C+");

	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectron);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/sps/nemo/scratch/remoto/nemo3/data/SingleElectron/");
	ProcessChannel::SetInputFileName ("SingleElectronAnalysis_output.root");
	ProcessChannel::SetInputDirName  ("SingleElectronSearch");
	ProcessChannel::SetInputTreeName ("SingleElectronSearch");	
	ProcessChannel::SetOutputFilePath("/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20160429/");
	ProcessChannel::SetOutputFileName("OneElectronHistos.root");

	//ProcessChannel::SetFirstRunNumber(2700);
	//ProcessChannel::SetLastRunNumber(2800);	
	
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}
