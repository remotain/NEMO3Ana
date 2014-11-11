#ifndef HistoCollection_h
#define HistoCollection_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"
#include "TH1.h"

class HistoCollection : public TNamed {

public:

	HistoCollection(const char* name, const char* title)       : TNamed(name, title) { _collection = new THashList(); };
	HistoCollection(const TString& name, const TString& title) : TNamed(name, title) { _collection = new THashList(); };

	~HistoCollection(){ };

	void Add( TH1 * h ) { _collection->Add(h); };
	TH1D * Find( const char* name ) { return (TH1D*)_collection->FindObject(name); };
	
	THashList * GetCollection(){ return _collection; };
	
	Int_t Write();
	void SaveAs(const char* filename = "", Option_t* option = "");


private:

	THashList * _collection;

ClassDef(HistoCollection,1);

};

#endif