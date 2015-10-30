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
#include "Group.h"

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
			_ComponentMap  = new TMap(50);
			_ComponentList = new TList();
			_GroupList     = 0;			
			
			_FitRangeLowBin = 1; // first bin
			_FitRangeUpBin  = _Data->GetNbinsX(); //last bin 
				
			_MarkerStyle = 20;
			_MarkerColor = kBlack;
			_MarkerSize  = 0.5;
			_DrawGroup   = kFALSE;
			_LogScale    = kFALSE;
			_ForceNorm   = kFALSE;

			_chi2  =  0.0 ;
			_ndf   = -1   ;
			_igood = -1   ;
	
			Info("Observable()","New Observable %s ", GetName());
				
				};

	~Observable() { };
	
	void SetMarkerStyle( Style_t style)   {  _MarkerStyle = style; };
	void SetMarkerColor( Color_t color)   { _MarkerColor  = color; };
	void SetMarkerSize( Size_t size)      { _MarkerSize   = size;  };
	void SetDrawGroup( Bool_t drawgroup ) { _DrawGroup     = drawgroup; };
	void SetLogScale( Bool_t islog )      { _LogScale     = islog; };
	
	void SetFitRangeLowEdge( Double_t low ){ _FitRangeLowBin = _Data->FindBin(low); };
	Double_t GetFitRangeLowBin() { return _FitRangeLowBin; };
	
	void SetFitRangeUpEdge( Double_t up ){ _FitRangeUpBin = _Data->FindBin(up); };
	Double_t GetFitRangeUpBin()  { return _FitRangeUpBin; };
	
	Style_t GetMarkerStyle() { return _MarkerStyle; };
	Color_t GetMarkerColor() { return _MarkerColor; };
	Size_t  GetMarkerSize()  { return _MarkerSize;  };
	Bool_t  GetDrawGroup()   { return _DrawGroup;   };
	Bool_t  GetLogScale()    { return _LogScale;    };
	
	PhaseType_t GetPhase(){ return _PhaseType; };
	TH1  * GetData(){ return _Data; };
	TMap * GetComponentMap() { return _ComponentMap; };
	
	//	double GetComponentNorm      (Component * c, double &err);
	double GetComponentNumEvent  (Component * c, double &err);
		
	void AddComponent( Component * c, TH1 * h) { 
		Info("AddComponent()", "%s , %s", c->GetName(), h->GetName());
		_ComponentMap->Add(c, h);
		_ComponentList->Add(c);
	};

	void AddGroup ( Group * g) { 
		Info("AddGroup()", "%s", g->GetName());
		
		if ( !_GroupList ) _GroupList = new TList();
		
		_GroupList->Add(g);
	};

	void AddGroupAll ( TList * l) { 
		_GroupList = l;
	};

	virtual void Draw(Option_t* option = "");
	virtual void DrawDetails(Option_t* option = "");
	virtual void PrintDetails();
	virtual void Chi2Test(TH1 * hData, TH1 * hModel, double & chi2, int & ndf);
	
	// chi2 and ks test
	double GetChi2   () { return _chi2; };
	double GetPValue () { return _pval; };
	double GetKS     () { return _ks;   };
	double GetNDF    () { return _ndf;  };
	
	void ForceNorm( bool is ){ _ForceNorm = is; };
	bool IsForceNorm(){ return _ForceNorm; };
	
private:

	TH1 * _Data;
	PhaseType_t _PhaseType;
	TMap  * _ComponentMap;
	TList * _ComponentList;
	TList * _GroupList;

	Double_t _FitRangeLowBin;
	Double_t _FitRangeUpBin;

	Style_t _MarkerStyle;
	Color_t _MarkerColor;
	Size_t  _MarkerSize;
	Bool_t  _LogScale;
	Bool_t  _DrawGroup;
	Bool_t _ForceNorm;
			
	// for chi2
	Double_t _chi2;
	Double_t _pval; // chi2 pvalue
	Double_t _ks; // Kolmogorow test
	Int_t    _ndf;
	Int_t    _igood;
	
ClassDef(Observable, 1);

};

#endif