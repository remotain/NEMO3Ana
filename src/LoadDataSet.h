#include "TSystem.h"

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

void LoadDataSet(){

	gSystem->Load("build/lib/libNEMO3Ana.dylib");

	//if ( DataSetCollection == 0 ) DataSetCollection = new TObjArray();
	//DataSetCollection->SetOwner(kTRUE);

	DataSet::GetCollection() -> Add ( new DataSet ( "Data" , 0, 0, 0 ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Air_Bi214"         ,  70999881900     ,   42850760*Phase1Fraction ,   42850760*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Air_Pb214"         ,  19999260700     ,     270396*Phase1Fraction ,     270396*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Air_Tl208"         ,    999998800     ,    1714450*Phase1Fraction ,    1714450*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_l1_m8"  ,      5000000 	,    4760818*Phase1Fraction ,    4760818*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_l2_m1"  ,      4999900 	,    4723043*Phase1Fraction ,    4723043*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m1"     ,      5000000 	,    4812151*Phase1Fraction ,    4812151*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m15"    ,      5000000 	,    4441481*Phase1Fraction ,    4441481*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m2"     ,      4999900 	,    4692066*Phase1Fraction ,    4692066*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m5"     ,      5000100 	,    4613385*Phase1Fraction ,    4613385*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m6"     ,      4999900 	,    4224320*Phase1Fraction ,    4224320*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b0n_m7"     ,      5000000 	,    3150923*Phase1Fraction ,    3150923*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_139_m4" ,      2000000 	,    1487483*Phase1Fraction ,    1487483*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_l1_m9"  ,     10000000 	,    7283035*Phase1Fraction ,    7283035*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_l2_m14" ,     10000000 	,    4009792*Phase1Fraction ,    4009792*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_l2_m4"  ,     10000000 	,    3987897*Phase1Fraction ,    3987897*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_m14"    ,     20000000 	,   14826053*Phase1Fraction ,   14826053*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_2b2n_m4"     ,     19999900 	,   14850582*Phase1Fraction ,   14850582*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Ac228"       ,      5000000     ,    2318376*Phase1Fraction ,    2318376*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Bi212"       ,      5000000     ,    2071656*Phase1Fraction ,    2071656*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Bi214"       ,    100000000     ,   61433684*Phase1Fraction ,   61433684*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Cd113"       ,     29999700     ,     487210*Phase1Fraction ,     487210*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Cd113m"      ,     37999700     ,    3514860*Phase1Fraction ,    3514860*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Cs137"       ,      4999900     ,     411326*Phase1Fraction ,     411326*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_K40"         ,     50000000     ,   25655770*Phase1Fraction ,   25655770*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Pa234m"      ,     50000000     ,   31590048*Phase1Fraction ,   31590048*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Pb211"       ,      5000000     ,    2215140*Phase1Fraction ,    2215140*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Sr90"        ,     10000000     ,    1051881*Phase1Fraction ,    1051881*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Tl207"       ,      5000000     ,    2435171*Phase1Fraction ,    2435171*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Tl208"       ,     49988700     ,   34996966*Phase1Fraction ,   34996966*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_Y90"         ,     20000000     ,   13955404*Phase1Fraction ,   13955404*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "Cd116_pb214_VT"    ,     20000000     ,    4300821*Phase1Fraction ,    4300821*Phase2Fraction ) );               
	DataSet::GetCollection() -> Add ( new DataSet ( "CuPetals_Co60"     ,   3199953200     ,    2734718*Phase1Fraction ,    2734718*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "CuTower_Co60"      ,   7999983400     ,    9585817*Phase1Fraction ,    9585817*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "FeShield_Ac228"    , 259991150700     ,    3820592*Phase1Fraction ,    3820592*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "FeShield_Bi214"    , 3.9999433937e+12 ,  141497952*Phase1Fraction ,  141497952*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "FeShield_Tl208"    , 199999206400     ,   25062875*Phase1Fraction ,   25062875*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "MuMetal_Co60"      ,  23999660700     ,   42411984*Phase1Fraction ,   42411984*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "MuMetal_g1000"     ,  29999948100     ,   17273818*Phase1Fraction ,   17273818*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Mylar_Bi214"       ,    100000000     ,   63403711*Phase1Fraction ,   63403711*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "Mylar_Pb214"       ,    100000000     ,   27386210*Phase1Fraction ,   27386210*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "PMT_Ac228"         ,  57999873800     ,   26801660*Phase1Fraction ,   26801660*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "PMT_Bi214"         ,  2.399997467e+11 ,  227169376*Phase1Fraction ,  227169376*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "PMT_K40"           ,  3.199987293e+11 ,   39907150*Phase1Fraction ,   39907150*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "PMT_Tl208"         ,  67899380000     ,  186088503*Phase1Fraction ,  186088503*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SFoil_Bi210"       ,     99999300     ,   28330295*Phase1Fraction ,   28330295*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SFoil_Bi214"       ,    109500000     ,   69882503*Phase1Fraction ,   69882503*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SFoil_Pb214"       ,     99999600     ,   28945664*Phase1Fraction ,   28945664*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SScin_Bi210"       ,   2949994000     ,  148901839*Phase1Fraction ,  148901839*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SScin_Bi214"       ,    799996700     ,  107254794*Phase1Fraction ,  107254794*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SScin_Pa234m"      ,    299999000     ,   32742278*Phase1Fraction ,   32742278*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SScin_Pb214"       ,    999998700     ,   81148592*Phase1Fraction ,   81148592*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SWire_Bi210"       ,   7997979000     , 1819217999*Phase1Fraction , 1819217999*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SWire_Bi214"       ,   1449494000     ,  779772777*Phase1Fraction ,  779772777*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SWire_Pb214"       ,   1599997000     ,  422820201*Phase1Fraction ,  422820201*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SWire_Tl208"       ,     99999600     ,   62220508*Phase1Fraction ,   62220508*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "ScintInn_K40"      ,   5999922000     ,   23297942*Phase1Fraction ,   23297942*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "ScintOut_K40"      ,   9999860700     ,   35834873*Phase1Fraction ,   35834873*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "ScintPet_K40"      ,   1999997400     ,   15571268*Phase1Fraction ,   15571268*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SteelFrame_Ac228"  ,   7399869300     ,    8386894*Phase1Fraction ,    8386894*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SteelFrame_Bi214"  ,  14999862300     ,   32697117*Phase1Fraction ,   32697117*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SteelFrame_Co60"   ,   7999944800     ,   29122389*Phase1Fraction ,   29122389*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SteelFrame_K40"    ,  59999460900     ,   22205606*Phase1Fraction ,   22205606*Phase2Fraction ) );
	DataSet::GetCollection() -> Add ( new DataSet ( "SteelFrame_Tl208"  ,   2999970300     ,   15164507*Phase1Fraction ,   15164507*Phase2Fraction ) );

};
