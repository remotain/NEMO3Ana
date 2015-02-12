
#include "THashList.h"
#include "DataSet.h"
#include "Observable.h"
#include "Component.h"
#include "Parameter.h"

namespace DataManagement {

	void SetTotalRunTime            (double val); double GetTotalRunTime            ();
	void SetTotalAcceptedRunTime    (double val); double GetTotalAcceptedRunTime    ();
	void SetTotalDeadTime           (double val); double GetTotalDeadTime           ();
	void SetTotalAcceptedDeadTime   (double val); double GetTotalAcceptedDeadTime   ();
	void SetTotalAcceptedRunTimeP1  (double val); double GetTotalAcceptedRunTimeP1  ();
	void SetTotalAcceptedDeadTimeP1 (double val); double GetTotalAcceptedDeadTimeP1 ();
	void SetTotalAcceptedRunTimeP2  (double val); double GetTotalAcceptedRunTimeP2  ();
	void SetTotalAcceptedDeadTimeP2 (double val); double GetTotalAcceptedDeadTimeP2 ();

	double GetLiveTime(PhaseType_t);
	double GetTotalLiveTime();
		
	void SetFoilMass       (double val, double valerr); 	
	void SetIsotopeMass    (double val, double valerr); 
	void SetIsotopeAtomicWeight (double val);
	
	double GetFoilMass();	
	double GetIsotopeMass();
	double GetIsotopeMassError();
	double GetIsotopeAtomicWeight();	
	double GetNormBB();
			
	void AddDataSet( DataSet * tmp);
	DataSet * FindDataSet(const char * name);
	THashList * GetDataSetCollection();
	
	void AddObservable( Observable * tmp);
	Observable * FindObservable(const char * name);
	THashList * GetObservableCollection();
	
	void AddParameter( Parameter * tmp);
	Parameter * FindParameter(const char * name);
	THashList * GetParameterCollection();
	
	void AddComponent( Component * tmp);
	Component * FindComponent(const char * name);
	THashList * GetParameterCollection();

};