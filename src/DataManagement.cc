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
	
	double GetLiveTime(PhaseType_t p) { 
		switch(p) {
			case kAll      : return _TotalAcceptedRunTime   - _TotalAcceptedDeadTime;
			case kPhaseOne : return _TotalAcceptedRunTimeP1 - _TotalAcceptedDeadTimeP1;
			case kPhaseTwo : return _TotalAcceptedRunTimeP2 - _TotalAcceptedDeadTimeP2; 
		}
	};

	double GetTotalLiveTime(){
		return _TotalAcceptedRunTime - _TotalAcceptedDeadTime;
	}

	double _FoilMass            = 0.0;
	double _FoilMassError       = 0.0;
	double _IsotopeEnrichement  = 0.0;
	double _IsotopeMass         = 0.0;
	double _IsotopeMassError    = 0.0;
	double _IsotopeAtomicWeight = 0.0;
	double _AvogadroNumber      = 6.0221413e+23;
	
	void SetFoilMass (double val, double valerr) { _FoilMass = val; _FoilMassError = valerr; }; 
	void SetIsotopeMass (double val, double valerr) { _IsotopeMass = val; _IsotopeMassError = valerr; }; 
	void SetIsotopeAtomicWeight (double val) { _IsotopeAtomicWeight = val; };
	
	double GetFoilMass            () { return _FoilMass            ; };	
	double GetIsotopeMass         () { return _IsotopeMass         ; };
	double GetIsotopeMassError    () { return _IsotopeMassError    ; };
	double GetIsotopeAtomicWeight () { return _IsotopeAtomicWeight ; };	
	double GetNormBB              () { return (_AvogadroNumber*_IsotopeMass*TMath::Log(2)*1000)/(3.15569e7*_IsotopeAtomicWeight); };

	// Data Set collection
	THashList * _DataSetCollection = new THashList();
	void AddDataSet( DataSet * tmp){ _DataSetCollection->Add(tmp); };
	DataSet * FindDataSet(const char * name) { return (DataSet *) _DataSetCollection->FindObject(name); };
    THashList * GetDataSetCollection() { return _DataSetCollection; };

	// Observable collection
	THashList * _ObservableCollection = new THashList();
	void AddObservable( Observable * tmp){ _ObservableCollection->Add(tmp); };
	Observable * FindObservable(const char * name) { return (Observable *) _ObservableCollection->FindObject(name); };
    THashList * GetObservableCollection() { return _ObservableCollection; };

	// Component collection
	THashList * _ComponentCollection = new THashList();
	void AddComponent( Component * tmp){ _ComponentCollection->Add(tmp); };
	Component * FindComponent(const char * name) { return (Component *) _ComponentCollection->FindObject(name); };
    THashList * GetComponentCollection() { return _ComponentCollection; };

	// Parameter collection
	THashList * _ParameterCollection = new THashList();
	void AddParameter( Parameter * tmp){ _ParameterCollection->Add(tmp); };
	Parameter * FindParameter(const char * name) { return (Parameter *) _ParameterCollection->FindObject(name); };
    THashList * GetParameterCollection() { return _ParameterCollection; };

	// Component collection
	THashList * _GroupCollection = new THashList();
	void AddGroup( Group * tmp){ _GroupCollection->Add(tmp); };
	Group * FindGroup(const char * name) { return (Group *) _GroupCollection->FindObject(name); };
    THashList * GetGroupCollection() { return _GroupCollection; };


}