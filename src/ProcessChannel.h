#include "TString.h"
#include "TObject.h"
#include "THashList.h"

#include "DataSet.h"

namespace ProcessChannel {
	
	void SetInputFilePath  (TString & s);
	void SetInputFileName  (TString & s);
	void SetInputDirName   (TString & s);
	void SetInputTreeName  (TString & s);
	void SetOutputFilePath (TString & s);
	void SetOutputFileName (TString & s);
	
	TString GetInputFilePath  ();
	TString GetInputFileName  ();
	TString GetInputDirName   ();
	TString GetInputTreeName  ();
	TString GetOutputFilePath ();
	TString GetOutputFileName ();
	
	enum ChannelType_t {
		kOneElectron                 , 
		kTwoElectronInternal         ,
		kTwoElectronExternal         ,
		kOneElectronOneGammaInternal ,
		kOneElectronOneGammaExternal ,
		kOneElectronTwoGammaInternal ,
		kOneElectronOneAlpha         ,
	};
	
	void SetChannelToProcess(ChannelType_t c);
	TString GetChannelToProcess( );	
		
	void AddDataSet( DataSet * d);
	THashList * GetDataSetCollection();
	
	bool Run();
	
	// Process channel
	bool ProcessOneElectron                 ( DataSet *d );
	bool ProcessTwoElectronInternal         ( DataSet *d );
	bool ProcessTwoElectronExternal         ( DataSet *d );
	bool ProcessOneElectronOneGammaInternal ( DataSet *d );		
	bool ProcessOneElectronOneGammaExternal ( DataSet *d );		
	bool ProcessOneElectronTwoGammaInternal ( DataSet *d );		
	bool ProcessOneElectronOneAlpha         ( DataSet *d );
	
}
