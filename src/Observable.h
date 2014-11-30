#ifndef Observable_h
#define Observable_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"
#include "TH1.h"

#include "Component.h"

class Observable : public TNamed {

public:

	Observable(
		const TString &name,
		const TString &title,
		TH1 * data
		) : TNamed(name, title) {
			
			_Data = data;
			_ComponentCollection = new THashList();
			
			Info("Observable()","New Observable %s ", GetName());
				
				};

	~Observable() { };
	
	TH1 * GetData (){ return _Data; };
	THashList * GetComponentCollection() { return _ComponentCollection; };
	
	void AddComponent( Component * c) { _ComponentCollection->Add(c); };
	void AddComponent( THashList * c) { _ComponentCollection->AddAll(c); };
	
private:

	TH1 * _Data;
	THashList * _ComponentCollection;

ClassDef(Observable, 1);

};

#endif