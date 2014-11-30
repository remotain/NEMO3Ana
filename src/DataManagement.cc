#include "DataManagement.h"

namespace DataManagement{

	// Data Set collection
	THashList * _DataSetCollection = new THashList();
	void AddDataSet( DataSet * d){ _DataSetCollection->Add(d); };
    THashList * GetDataSetCollection() { return _DataSetCollection; };


}