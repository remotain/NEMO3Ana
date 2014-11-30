#include "DataManagement.h"

namespace DataManagement{


    double _TotalRunTime            = 0.;  
    double _TotalAcceptedRunTime    = 0.;  
    double _TotalDeadTime           = 0.;  
    double _TotalAcceptedDeadTime   = 0.;  
    double _TotalAcceptedRunTimeP1  = 0.;  
    double _TotalAcceptedDeadTimeP1 = 0.;  
    double _TotalAcceptedRunTimeP2  = 0.;  
    double _TotalAcceptedDeadTimeP2 = 0.;  

	void SetTotalRunTime            (double val) { _TotalRunTime            = val; }; 
	void SetTotalAcceptedRunTime    (double val) { _TotalAcceptedRunTime    = val; }; 
	void SetTotalDeadTime           (double val) { _TotalDeadTime           = val; }; 
	void SetTotalAcceptedDeadTime   (double val) { _TotalAcceptedDeadTime   = val; }; 
	void SetTotalAcceptedRunTimeP1  (double val) { _TotalAcceptedRunTimeP1  = val; }; 
	void SetTotalAcceptedDeadTimeP1 (double val) { _TotalAcceptedDeadTimeP1 = val; }; 
	void SetTotalAcceptedRunTimeP2  (double val) { _TotalAcceptedRunTimeP2  = val; }; 
	void SetTotalAcceptedDeadTimeP2 (double val) { _TotalAcceptedDeadTimeP2 = val; }; 

    double GetTotalRunTime            () { return _TotalRunTime            ;};
    double GetTotalAcceptedRunTime    () { return _TotalAcceptedRunTime    ;};
    double GetTotalDeadTime           () { return _TotalDeadTime           ;};
    double GetTotalAcceptedDeadTime   () { return _TotalAcceptedDeadTime   ;};
    double GetTotalAcceptedRunTimeP1  () { return _TotalAcceptedRunTimeP1  ;};
    double GetTotalAcceptedDeadTimeP1 () { return _TotalAcceptedDeadTimeP1 ;};
    double GetTotalAcceptedRunTimeP2  () { return _TotalAcceptedRunTimeP2  ;};
    double GetTotalAcceptedDeadTimeP2 () { return _TotalAcceptedDeadTimeP2 ;};
	
	double GetTotalLiveRunTimeP1() { return _TotalAcceptedRunTimeP1 - _TotalAcceptedDeadTimeP1; };
	double GetTotalLiveRunTimeP2() { return _TotalAcceptedRunTimeP2 - _TotalAcceptedDeadTimeP2; };

	// Data Set collection
	THashList * _DataSetCollection = new THashList();
	void AddDataSet( DataSet * tmp){ _DataSetCollection->Add(tmp); };
    THashList * GetDataSetCollection() { return _DataSetCollection; };

	// Observable collection
	THashList * _ObservableCollection = new THashList();
	void AddObservable( Observable * tmp){ _ObservableCollection->Add(tmp); };
    THashList * GetObservableCollection() { return _ObservableCollection; };

	// Component collection
	THashList * _ComponentCollection = new THashList();
	void AddComponent( Component * tmp){ _ComponentCollection->Add(tmp); };
    THashList * GetComponentCollection() { return _ComponentCollection; };

	// Parameter collection
	THashList * _ParameterCollection = new THashList();
	void AddParameter( Parameter * tmp){ _ParameterCollection->Add(tmp); };
    THashList * GetParameterCollection() { return _ParameterCollection; };

}