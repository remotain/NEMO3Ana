#ifndef Component_h
#define Component_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"
#include "TH1.h"

class Component : public TNamed {

public:

	Component(
		const TString &name,
		const TString &title,
		const TString &dataset_name,
		const TString &parameter_name,
		double norm,
		TH1 * histo
					
		) : TNamed(name, title) {
			
			_DataSetName   = dataset_name;
			_ParameterName = parameter_name;
			_Norm          = norm;
			_Histo         = histo;
			
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSetName.Data(), _ParameterName.Data(), _Norm);
				
				};

	~Component() { };
	
	TString GetDataSetName(){ return _DataSetName; };
	TString GetParameterName(){ return _ParameterName; };

	double GetNorm  (){ return _Norm;  };
	TH1 *  GetHisto (){ return _Histo; };
	
private:

	TString _DataSetName;
	TString _ParameterName;
	double  _Norm;
	TH1 *   _Histo;

ClassDef(Component, 1);

};

#endif