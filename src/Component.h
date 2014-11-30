#ifndef Component_h
#define Component_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"

class Component : public TNamed {

public:

	Component(
		const TString &name,
		const TString &title,
		const TString &dataset_name,
		const TString &parameter_name,
		double normalisation
		
		) : TNamed(name, title) {
			
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSetName, _ParameterName, _Normalisation);
				
				};

	~Component() { };
	
	double GetNormalisation(){ return _Normalisation; };
	
private:

	TString _DataSetName;
	TString _ParameterName;
	double  _Normalisation;

ClassDef(Component, 1);

};

#endif