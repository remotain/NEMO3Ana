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
			_PhaseType = phase;
			_ComponentMap = new TMap(50);
			
			_MarkerStyle = 20;
			_MarkerColor = kBlack;
			_MarkerSize  = 0.5;

			Info("Observable()","New Observable %s ", GetName());
				
				};

	~Observable() { };
	
	void SetMarkerStyle( Style_t style) { _MarkerStyle = style; };
	void SetMarkerColor( Color_t color) {_MarkerColor = color; };
	void SetMarkerSize( Size_t size) {_MarkerSize = size; };
	
	Style_t GetMarkerStyle() { return _MarkerStyle; };
	Color_t GetMarkerColor() { return _MarkerColor; };
	Size_t  GetMarkerSize()  { return _MarkerSize;  };
	
	PhaseType_t GetPhase(){ return _PhaseType; };
	TH1  * GetData(){ return _Data; };
	TMap * GetComponentMap() { return _ComponentMap; };
	
	double GetComponentNorm      (Component * c);
	double GetComponentNumEvent  (Component * c);
	
	//TH1 *  GetComponentNormHisto (Component * c) { 
	//	TH1D * _tmp = (TH1D *) _ComponentMap->GetValue(c)->Clone( TString::Format("norm_%s", _ComponentMap->GetValue(c)0>GetName())) ; 
	//	_tmp->Scale(GetComponentNorm(c)); 
	//	return _tmp; 
	//};
		
	void AddComponent( Component * c, TH1 * h) { 
		Info("AddComponent()", "%s , %s", c->GetName(), h->GetName());
		_ComponentMap->Add(c, h); 
	};
	
	virtual void Draw(Option_t* option = "");
	
private:

	TH1 * _Data;
	PhaseType_t _PhaseType;
	TMap * _ComponentMap;

	Style_t _MarkerStyle;
	Color_t _MarkerColor;
	Size_t  _MarkerSize;
	
ClassDef(Observable, 1);

};

#endif