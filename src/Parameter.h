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
		const char * name,
		const char * title,
		unsigned int order,
		double val_init,
		double val_step		
		) : TNamed(name, name) {
			
			_Order     = order;
			_ValInit   = val_init;   
			_ValStep   = val_step;   
			_ValMax    = 0;
			_ValMin    = 0;
			_ValError  = 0;
			_IsFixed   = false;
			_IsLimited = false;
						
			Info("Parameter()","New parameter %s (%f,%f)", GetName(), _ValInit, _ValStep);
				
				} ;

	unsigned int GetOrder   () { return _Order;   };
	
	double GetValInit  () { return _ValInit;  };
	double GetValMax   () { return _ValMax;   };
	double GetValMin   () { return _ValMin;   };
	double GetValStep  () { return _ValStep;  };
	double GetValError () { return _ValError; };
	
	void SetValInit  ( double val ) { _ValInit  = val; };
	void SetValMax   ( double val ) { _ValMax   = val; };
	void SetValMin   ( double val ) { _ValMin   = val; };
	void SetValStep  ( double val ) { _ValStep  = val; };		
	void SetValError ( double val ) { _ValError = val; };
	
	bool IsFixed () { return _IsFixed; };
	void SetFix  () { _IsFixed = true; _IsLimited = false; };

	bool IsLimited () { return _IsLimited; };
	void SetLimit(double min, double max) { _IsFixed = false; _IsLimited = true; _ValMin = min; _ValMax = max; };

	~Parameter() { };
	
private:

	unsigned int _Order;
	double _ValInit;
	double _ValMax;
	double _ValMin;
	double _ValStep;
	double _ValError;
	
	bool _IsFixed;
	bool _IsLimited;

ClassDef(Parameter, 1);

};

#endif