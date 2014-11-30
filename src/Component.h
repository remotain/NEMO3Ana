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
		double norm
		
		) : TNamed(name, title) {
			
			_DataSetName   = dataset_name;
			_ParameterName = parameter_name;
			_Norm          = norm;
			
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSetName.Data(), _ParameterName.Data(), _Norm);
				
				};

	~Component() { };
	
	double GetNorm(){ return _Norm; };
	
private:

	TString _DataSetName;
	TString _ParameterName;
	double  _Norm;

ClassDef(Component, 1);

};

#endif