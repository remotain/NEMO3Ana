#ifndef DataSet_h
#define DataSet_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "TNamed.h"
#include "TString.h"
#include "THashList.h"

class DataSet : public TNamed {

public:

	DataSet(
		const TString &name,
		unsigned long GeneratedEvents,
		unsigned long AcceptedEventsPhase1,
		unsigned long AcceptedEventsPhase2
		) : TNamed(name, name) {
			
			_GeneratedEvents      = GeneratedEvents      ;
			_AcceptedEventsPhase1 = AcceptedEventsPhase1 ;
			_AcceptedEventsPhase2 = AcceptedEventsPhase2 ;
			
			Info("DataSet()","New data set %s (%lu,%lu,%lu)", GetName(), _GeneratedEvents, _AcceptedEventsPhase1, _AcceptedEventsPhase2);
				
				} ;

	~DataSet() { };
	
private:

	unsigned long _GeneratedEvents;
   	unsigned long _AcceptedEventsPhase1;
   	unsigned long _AcceptedEventsPhase2;

ClassDef(DataSet, 1);

};

#endif