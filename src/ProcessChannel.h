#include "TString.h"
#include "TObject.h"
#include "THashList.h"

#include "DataSet.h"

namespace ProcessChannel {
	
	void SetInputFilePath      (TString & s);
	void SetInputFileName      (TString & s);
	void SetInputDirName       (TString & s);
	void SetInputTreeName      (TString & s);
	void SetOutputFilePath     (TString & s);
	void SetOutputFileName     (TString & s);
	void SetOutputTreeFileName (TString & s);
		
	TString GetInputFilePath  ();
	TString GetInputFileName  ();
	TString GetInputDirName   ();
	TString GetInputTreeName  ();
	TString GetOutputFilePath ();
	TString GetOutputFileName ();
	
	void SetFirstRunNumber ( int run    );
	void SetLastRunNumber  ( int run    );
	bool CheckRunNumber    ( int run    );
	bool CheckRunStatus    ( int status );	
		
	enum ChannelType_t {
		kOneElectron                   , 
		kTwoElectronInternal           ,
		kTwoElectronExternal           ,
		kOneElectronOneGammaInternal   ,
		kOneElectronOneGammaExternal   ,
		kOneElectronTwoGammaInternal   ,
		kOneElectronThreeGammaInternal ,
		kOneElectronOneAlpha
	};
	
	void SetChannelToProcess(ChannelType_t c);
	TString GetChannelToProcess( );	
	
	double getSectorNumber( double x, double y);	
	
	bool IsHotSpot  (double z, double s);
	bool IsHotSpot  (double z, double s);
	bool IsWarmSpot (double z, double s);
	bool IsColdSpot (double z, double s);
	
	bool Run( Long64_t n_max = -1 );
	
	// Process channel
	bool ProcessOneElectron                   ( DataSet *d );
	bool ProcessTwoElectronInternal           ( DataSet *d );
	bool ProcessTwoElectronExternal           ( DataSet *d );
	bool ProcessOneElectronOneGammaInternal   ( DataSet *d );		
	bool ProcessOneElectronOneGammaExternal   ( DataSet *d );		
	bool ProcessOneElectronTwoGammaInternal   ( DataSet *d );
	bool ProcessOneElectronThreeGammaInternal ( DataSet *d );				
	bool ProcessOneElectronOneAlpha           ( DataSet *d );
	
}
