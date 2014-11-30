
#include "THashList.h"
#include "DataSet.h"
#include "Observable.h"
#include "Component.h"
#include "Parameter.h"

namespace DataManagement {

	void AddDataSet( DataSet * tmp);
	THashList * GetDataSetCollection();
	
	void AddObservable( Observable * tmp);
	THashList * GetObservableCollection();
	
	void AddParameter( Parameter * tmp);
	THashList * GetParameterCollection();
	
	void AddComponent( Component * tmp);
	THashList * GetComponentCollection();
	
};