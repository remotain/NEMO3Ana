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

#include "DataSet.h"
#include "Parameter.h"

class Component : public TNamed {

public:

	Component(
		const TString &name,
		const TString &title,
		DataSet * data_set,
		Parameter * param,
		double norm
					
		) : TNamed(name, title) {
			
			_DataSet       = data_set;
			_Parameter     = param;
			_Norm          = norm;
			_FillColor     = kWhite;
			_LineColor     = kBlack;
				
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSet->GetName(), _Parameter->GetName(), _Norm);
				
				};

	~Component() { };
	
	void SetFillColor( Color_t color) { _FillColor = color; };
	void SetLineColor( Color_t color) { _LineColor = color; };
		
	Color_t GetFillColor() { return _FillColor; };
	Color_t GetLineColor() { return _LineColor; };
			
	DataSet * GetDataSet(){ return _DataSet; };
	Parameter * GetParameter(){ return _Parameter; };

	double GetNorm (){ return _Norm; };
	
private:

	Parameter * _Parameter;
	DataSet   * _DataSet;
	TString     _ParameterName;
	double      _Norm;
	Color_t     _FillColor;
	Color_t     _LineColor;

ClassDef(Component, 1);

};

#endif