
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
	
	double GetTotalLiveRunTimeP1();
	double GetTotalLiveRunTimeP2();
	
	void AddDataSet( DataSet * tmp);
	THashList * GetDataSetCollection();
	
	void AddObservable( Observable * tmp);
	THashList * GetObservableCollection();
	
	void AddParameter( Parameter * tmp);
	THashList * GetParameterCollection();
	
	void AddComponent( Component * tmp);
	THashList * GetParameterCollection();

};