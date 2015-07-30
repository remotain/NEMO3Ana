{
	gSystem->Load("/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/lib/libNEMO3Ana.so");

	// Run time STANDARD RUN
	DataManagement::SetTotalRunTime            (    167629292);
	DataManagement::SetTotalAcceptedRunTime    (    167629292);
	DataManagement::SetTotalDeadTime           (1868832.32295);
	DataManagement::SetTotalAcceptedDeadTime   (1868832.32295); 
	DataManagement::SetTotalAcceptedRunTimeP1  (     33859178); 
	DataManagement::SetTotalAcceptedDeadTimeP1 ( 457955.57403);
	DataManagement::SetTotalAcceptedRunTimeP2  (    133770114);
	DataManagement::SetTotalAcceptedDeadTimeP2 (1410876.74892);

	// Run time GOOD RUN
	//DataManagement::SetTotalRunTime            (    149287469.000);
	//DataManagement::SetTotalAcceptedRunTime    (    149287469.000);
	//DataManagement::SetTotalDeadTime           (      1673710.109);
	//DataManagement::SetTotalAcceptedDeadTime   (      1673710.109);
	//DataManagement::SetTotalAcceptedRunTimeP1  (     29308968.000); 
	//DataManagement::SetTotalAcceptedDeadTimeP1 (       397833.032);
	//DataManagement::SetTotalAcceptedRunTimeP2  (    119978501.000);
	//DataManagement::SetTotalAcceptedDeadTimeP2 (      1275877.077);
	
	double Data_AccptRunTimeP1 = DataManagement::GetTotalAcceptedRunTimeP1() - DataManagement::GetTotalAcceptedDeadTimeP1();
	double Data_AccptRunTimeP2 = DataManagement::GetTotalAcceptedRunTimeP2() - DataManagement::GetTotalAcceptedDeadTimeP2();
	
	double Phase1Fraction = Data_AccptRunTimeP1/DataManagement::GetTotalAcceptedRunTime();
	double Phase2Fraction = Data_AccptRunTimeP2/DataManagement::GetTotalAcceptedRunTime();
	
	// Isotope mass and normalisation
	DataManagement::SetIsotopeMass(410.4 /* g */, 1.0 /* g */ );
	DataManagement::SetIsotopeAtomicWeight(115.904756 /* g/mol */ );

	DataManagement::AddDataSet ( new DataSet ( "Data", 0, 0, 0));
	DataManagement::AddDataSet ( new DataSet ( "Air_Bi214"   , 70999881900.0 ,  42850760.0*Phase1Fraction ,  42850760.0*Phase2Fraction ));
	DataManagement::AddDataSet ( new DataSet ( "Cd116_Bi214" ,   100000000.0 ,  61433684.0*Phase1Fraction ,  61433684.0*Phase2Fraction ));
	DataManagement::AddDataSet ( new DataSet ( "Mylar_Bi214" ,   100000000.0 ,  63403711.0*Phase1Fraction ,  63403711.0*Phase2Fraction ));
	DataManagement::AddDataSet ( new DataSet ( "SFoil_Bi214" ,   109500000.0 ,  69882503.0*Phase1Fraction ,  69882503.0*Phase2Fraction ));
	DataManagement::AddDataSet ( new DataSet ( "SScin_Bi214" ,   799996700.0 , 107254794.0*Phase1Fraction , 107254794.0*Phase2Fraction ));
	DataManagement::AddDataSet ( new DataSet ( "SWire_Bi214" ,  1449494000.0 , 779772777.0*Phase1Fraction , 779772777.0*Phase2Fraction ));
  
}
