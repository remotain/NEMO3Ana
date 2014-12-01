#ifndef Observable_h
#define Observable_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "TMap.h"
#include "THashList.h"
#include "TH1.h"

#include "Component.h"

enum PhaseType_t {
	kAll,
	kPhaseOne, 
	kPhaseTwo
};

class Observable : public TNamed {

public:

	Observable(
		const char * name,
		const char * title,
		PhaseType_t phase,
		TH1 * data
		) : TNamed(name, title) {
			
			_Data = data;
			//_PhaseType = phase;
			_ComponentMap = new TMap(50);
			
			Info("Observable()","New Observable %s ", GetName());
				
				};

	~Observable() { };
	
	PhaseType_t GetPhase(){ return _PhaseType; };
	TH1  * GetData(){ return _Data; };
	TMap * GetComponentMap() { return _ComponentMap; };
	
	void AddComponent( Component * c, TH1 * h) { 
		_ComponentMap->Add(c, h); 
		
		Info("AddComponent()", "%s , %s", c->GetName(), h->GetName());
	};
	
private:

	TH1 * _Data;
	PhaseType_t _PhaseType;
	TMap * _ComponentMap;

ClassDef(Observable, 1);

};

#endif