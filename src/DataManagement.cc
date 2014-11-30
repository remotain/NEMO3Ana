#include "DataManagement.h"

namespace DataManagement{

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