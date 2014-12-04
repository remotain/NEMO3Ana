
#include <iostream>

#include "DataManagement.h"
#include "Parameter.h"
#include "Observable.h"
#include "Component.h"

#include "TMath.h"
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "Fit.h"

namespace Fit{

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit function
	//		
	//////////////////////////////////////////////////////////////////////////////
	double Fcn(const double *x){
		
		double l_likelihood = 0.;
		
		TIter next( DataManagement::GetObservableCollection() );
		while ( Observable * obs = (Observable *) next() ){
		
			// Get the data histogram
			TH1D * h_data = (TH1D*) obs->GetData();
			
			// Define sum of all mc components
			TH1D * h_mc = (TH1D*) h_data->Clone("h_mc");
			h_mc->Reset();
			
			// Loop Over Component collection
			TMapIter next( obs->GetComponentMap() );
			while ( Component * comp = (Component *) next() ){
				
				// Get the histogram
				TH1D * h_comp = (TH1D*) obs->GetComponentMap()->GetValue(comp);
				
				// Compute normalisation
				double norm = comp->GetNorm() * x[comp->GetParameter()->GetOrder()] * DataManagement::GetLiveTime( kAll ) / comp->GetDataSet()->GetGeneratedEvents();
					
				// Add histogram to the sum
				h_mc->Add(h_comp, norm);

			}
					
			// Loop over the data histogram bin
			for (unsigned int i = 1; i <= h_data->GetNbinsX(); i++){
				
				// Compute the likelihood
				if( h_mc->GetBinContent(i) == 0 ) {
					l_likelihood += - h_mc->GetBinContent(i);
				} else {
					l_likelihood += h_data->GetBinContent(i) * TMath::Log(h_mc->GetBinContent(i)) - h_mc->GetBinContent(i);
				}
				
			}
			
			h_mc->Delete();
		
		}
		
		// Return -log(L)
		return -l_likelihood;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////
	//
	// Run the fitter
	//		
	//////////////////////////////////////////////////////////////////////////////	
	void Run(const char * minimizerType, const char * algoType){
		
		ROOT::Math::Minimizer* min = ROOT::Math::Factory::CreateMinimizer(minimizerType, algoType);
		
		// set tolerance , etc...
		min->SetMaxFunctionCalls(1000000);
		min->SetTolerance(0.001);
		min->SetPrintLevel(2);

		// create funciton wrapper for minmizer
		ROOT::Math::Functor f(&Fcn, DataManagement::GetParameterCollection()->GetEntries() ); 
 
		min->SetFunction(f);
 
		// Set the free variables to be minimized!
		TIter next2( DataManagement::GetParameterCollection() );
		while ( Parameter * param = (Parameter *) next2() ){
			
			if( param->IsLimited() ) {
			
				min->SetLimitedVariable(
					param->GetOrder(), 
				    param->GetName(), 
				    param->GetValInit(), 
				    param->GetValStep(), 
				    param->GetValMin(), 
				    param->GetValMax()
						);
					
			}  else if ( param->IsFixed() ) {
				
				min->SetFixedVariable(
					param->GetOrder(), 
				    param->GetName(),
				    param->GetValInit()
						);

			} else {
				
				min->SetVariable(
					param->GetOrder(), 
				    param->GetName(),
				    param->GetValInit(), 
				    param->GetValStep()
						);
					
			}
			 
		}
		
		// do the minimization
		min->Minimize(); 
		
		const double *xs = min->X();
		const double *es = min->Errors();
		
		// Get the  variables after the fit!
		TIter next( DataManagement::GetParameterCollection() );
		while ( Parameter * param = (Parameter *) next() ){
			
			param->SetValInit(xs[param->GetOrder()]);

		}
		
		
	}


}