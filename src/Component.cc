#include "Component.h"
#include "DataManagement.h"

ClassImp(Component);

double Component::GetNorm() { 
	if (GetParameter() == 0) {
		return _Adjustment * DataManagement::GetTotalLiveTime() / GetDataSet()->GetGeneratedEvents(); 
	} else {
		return _Adjustment * GetParameter()->GetValInit() * DataManagement::GetTotalLiveTime() / GetDataSet()->GetGeneratedEvents();
	}
};

double Component::GetNormErr() { 
	if (GetParameter() == 0) {
		return GetNorm() * _AdjustmentErr / _Adjustment ;
	} else { 
		return GetNorm() * TMath::Sqrt( TMath::Power(GetParameter()->GetValError() / GetParameter()->GetValInit(),2) + TMath::Power(_AdjustmentErr / _Adjustment,2) ) ;
	}
};	