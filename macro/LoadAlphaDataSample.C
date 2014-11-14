{

	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");
	
	// Run time
	double Data_TotalRunTime            =     167629292;
	double Data_TotalAcceptedRunTime    =     167629292;
	double Data_TotalDeadTime           = 1868832.32295;
	double Data_TotalAcceptedDeadTime   = 1868832.32295; 
	double Data_TotalAcceptedRunTimeP1  =      33859178; 
	double Data_TotalAcceptedDeadTimeP1 =  457955.57403;
	double Data_TotalAcceptedRunTimeP2  =     133770114;
	double Data_TotalAcceptedDeadTimeP2 = 1410876.74892;
	double Data_AccptRunTimeP1 = Data_TotalAcceptedRunTimeP1 - Data_TotalAcceptedDeadTimeP1;
	double Data_AccptRunTimeP2 = Data_TotalAcceptedRunTimeP2 - Data_TotalAcceptedDeadTimeP2;

	double Phase1Fraction = Data_AccptRunTimeP1/Data_TotalAcceptedRunTime;
	double Phase2Fraction = Data_AccptRunTimeP2/Data_TotalAcceptedRunTime;
	
	const double fractionOfGoodRuns = 8.90574858703334082e-01;
	
	Air_Bi214  Cd116_Bi214  Data  Mylar_Bi214  SFoil_Bi214  SScin_Bi214  SWire_Bi214
	
    ProcessChannel::AddDataSet ( new DataSet ( "Data", 0, 0, 0));
	ProcessChannel::AddDataSet ( new DataSet ( "Air_Bi214"   , 70999881900.0*fractionOfGoodRuns ,  42850760.0*Phase1Fraction ,  42850760.0*Phase2Fraction ));
    ProcessChannel::AddDataSet ( new DataSet ( "Cd116_Bi214" ,   100000000.0*fractionOfGoodRuns ,  61433684.0*Phase1Fraction ,  61433684.0*Phase2Fraction ));
    ProcessChannel::AddDataSet ( new DataSet ( "Mylar_Bi214" ,   100000000.0*fractionOfGoodRuns ,  63403711.0*Phase1Fraction ,  63403711.0*Phase2Fraction ));
    ProcessChannel::AddDataSet ( new DataSet ( "SFoil_Bi214" ,   109500000.0*fractionOfGoodRuns ,  69882503.0*Phase1Fraction ,  69882503.0*Phase2Fraction ));
	ProcessChannel::AddDataSet ( new DataSet ( "SScin_Bi214" ,   799996700.0*fractionOfGoodRuns , 107254794.0*Phase1Fraction , 107254794.0*Phase2Fraction ));
    ProcessChannel::AddDataSet ( new DataSet ( "SWire_Bi214" ,  1449494000.0*fractionOfGoodRuns , 779772777.0*Phase1Fraction , 779772777.0*Phase2Fraction ));

}
