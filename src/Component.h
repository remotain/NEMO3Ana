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
#include "TMath.h"

#include "DataSet.h"
#include "Parameter.h"

class Component : public TNamed {

public:

	Component(
		const TString &name,
		const TString &title,
		DataSet * data_set,
		Parameter * param,
		double adj    = 1.,
		double adjerr = 0.,
		bool constraint = false,
		int nSigma = 1
		) : TNamed(name, title) {
			
			_DataSet       = data_set;
			_Parameter     = param;
			_Adjustment    = adj;
			_AdjustmentErr = adjerr;
			_FillColor     = kWhite;
			_LineColor     = kBlack;
			_IsGausConstraint = constraint;
			_nSigma        = nSigma;
				
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSet->GetName(), _Parameter->GetName(), _Adjustment);
				
				};
	
	Component(
		const TString &name,
		const TString &title,
		DataSet * data_set,
		double adj    = 1.,
		double adjerr = 0.
		) : TNamed(name, title) {
	
			_DataSet       = data_set;
			_Parameter     = 0;
			_Adjustment    = adj;
			_AdjustmentErr = adjerr;
			_FillColor     = kWhite;
			_LineColor     = kBlack;
	
			Info("Component()","New component %s (%s,%s,%f)", GetName(), _DataSet->GetName(), "Null", _Adjustment);
	
				};


	~Component() { };
	
	void SetFillColor( Color_t color) { _FillColor = color; };
	void SetLineColor( Color_t color) { _LineColor = color; };
		
	Color_t GetFillColor() { return _FillColor; };
	Color_t GetLineColor() { return _LineColor; };
			
	DataSet * GetDataSet(){ return _DataSet; };
	Parameter * GetParameter(){ return _Parameter; };

	double GetAdjustment    (){ return _Adjustment; };
	double GetAdjustmentErr (){ return _AdjustmentErr; };
	
	double GetNorm();
	double GetNormErr();
	
	void SetGausConstraint( bool is) {_IsGausConstraint = is; }; 
	bool IsGausConstraint() {return _IsGausConstraint; }; 
	int  GetNSigma(){ return _nSigma; };
	
private:

	Parameter * _Parameter;
	DataSet   * _DataSet;
	TString     _ParameterName;
	double      _Adjustment;
	double      _AdjustmentErr;
	Color_t     _FillColor;
	Color_t     _LineColor;
	bool		_IsGausConstraint;
	int         _nSigma;
	
ClassDef(Component, 1);

};

#endif