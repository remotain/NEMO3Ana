#ifndef Parameter_h
#define Parameter_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"

class Parameter : public TNamed {

public:

	Parameter(
		const TString &name,
		const TString &title,
		double val_init,
		double val_max,
		double val_min,
		double val_step,
		
		) : TNamed(name, name) {
			
			_ValInit = val_init;   
			_ValMax  = val_max;  
			_ValMin  = val_min;  
			_ValStep = val_step;   
			
			Info("Parameter()","New parameter %s (%d,%d,%d,%d)", GetName(), _ValInit, _ValMax, _ValMin, _ValStep);
				
				} ;

	double GetValInit () { return _ValInit; };
	double GetValMax  () { return _ValMax;  };
	double GetValMin  () { return _ValMin;  };
	double GetValStep () { return _ValStep; };
		
	~Parameter() { };
	
private:

	double _ValInit,
	double _ValMax,
	double _ValMin,
	double _ValStep,

ClassDef(Parameter, 1);

};

#endif