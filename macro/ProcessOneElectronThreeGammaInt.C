{

	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	gROOT->ProcessLine(".x /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/LoadAllDataSample.C+");
	
	// Set Channel to process
	ProcessChannel::SetChannelToProcess(ProcessChannel::kOneElectronTwoGammaInternal);

	// Set basic path	
	ProcessChannel::SetInputFilePath ("/sps/nemo/scratch/remoto/nemo3/data/ElectronGamma/");
	ProcessChannel::SetInputFileName ("ElectronGammaAnalysis_output.root");
	ProcessChannel::SetInputDirName  ("ElectronGammaSearch");
	ProcessChannel::SetInputTreeName ("ElectronGammaSearch");	
	ProcessChannel::SetOutputFilePath("/sps/nemo/scratch/remoto/nemo3/plot/");
	ProcessChannel::SetOutputFileName("OneElectronThreeGammaInt.root");
		
	// Run
	TBenchmark * benchmark = new TBenchmark();
	benchmark->Start("Run");
	ProcessChannel::Run();
	benchmark->Show("Run");
	
}
