#include "HistoCollection.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TKey.h"
#include <cstring>

ClassImp(HistoCollection);

TH1D * HistoCollection::Find( const char* name ) 
{ 

	TH1D * obj = (TH1D*) _collection->FindObject(name); 
	
	if ( !obj ) Error("Find()", "Histo '%s' not found in collection", name);
		
	return obj;
};

Int_t HistoCollection::Write()
{
	TDirectory * d = gFile->mkdir(GetName());
		
	// Directory already exists. Skip.
	if( d == 0 ) return 0; 

	d->cd();
	Info("Write()", "Write histo collection on file");
	return _collection->Write();
	
}
	
void HistoCollection::SaveAs(const char* filename, Option_t* option)
{
		
	if (filename && strstr(filename,".pdf")) {
		
		TIter next(_collection);
		TH1D * h;
		
		while( (h = (TH1D *) next()) ) {
			
			TCanvas c (h->GetName(), h->GetTitle());
			h->Draw();
			
			if( h == _collection->First()) c.Print( TString::Format("%s(", filename) );
			else if( h == _collection->Last()) c.Print( TString::Format("%s)", filename) );
			else c.Print(filename);
		
		}
		
		return;
	}
	
	Error("SaveAs", "cannot open file: %s", filename);	
	
}

void HistoCollection::Load(TDirectory * dir){
	
	TList * list = dir->GetListOfKeys();
	TIter next(list); TKey * k;
	
	while( ( k = (TKey*) next() ) ) {
		
		_collection->Add( (TH1 *) k->ReadObj() );
		Info("Load()","Add %s to collection", k->GetName());
		
	}
	
	
}