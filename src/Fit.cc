
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
								
				// Get the corresponding parameter by name from DataManagement::ParameterCollection()
				Parameter * param = (Parameter *) DataManagement::GetParameterCollection()->FindObject(comp->GetParameterName());
				
				// Compute normalisation
				double norm = comp->GetNorm() * x[param->GetOrder()] * DataManagement::GetLiveTime(obs->GetPhase()) / DataManagement::FindDataSet(comp->GetDataSetName())->GetGeneratedEvents(); 
				
				// Add histogram to the sum
				h_mc->Add(h_comp, norm);
			
			}
				
			// Loop over the data histogram bin
			for (unsigned int i = 1; i <= h_data->GetNbinsX(); i++){

				// Compute the likelihood
				l_likelihood += h_data->GetBinContent(i) * TMath::Log(h_mc->GetBinContent(i)) - h_mc->GetBinContent(i);
				
			}
		
		}
		
		// Return -log(L)
		return -l_likelihood;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////
	//
	// Run the fitter
	//		
	//////////////////////////////////////////////////////////////////////////////	
	void Run(){
		
		ROOT::Math::Minimizer* min = ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad");
		
		// set tolerance , etc...
		min->SetMaxFunctionCalls(1000000);
		min->SetTolerance(0.001);
		min->SetPrintLevel(1);

		// create funciton wrapper for minmizer
		ROOT::Math::Functor f(&Fcn, DataManagement::GetParameterCollection()->GetEntries() ); 
 
		min->SetFunction(f);
 
		// Set the free variables to be minimized!
		TIter next( DataManagement::GetParameterCollection() );
		while ( Parameter * param = (Parameter *) next() ){
			
			min->SetLimitedVariable(
				param->GetOrder(), 
			    param->GetName(), 
			    param->GetValInit(), 
			    param->GetValStep(), 
			    param->GetValMin(), 
			    param->GetValMax()
		    );

		} 
		
		// do the minimization
		min->Minimize(); 
 
		//const double *xs = min->X();
		//std::cout << "Minimum: f(" << xs[0] << "," << xs[1] << "): " 
		//          << min->MinValue()  << std::endl;
        //
		//// expected minimum is 0
		//if ( min->MinValue()  < 1.E-4  && f(xs) < 1.E-4) 
		//   std::cout << "Minimizer " << minName << " - " << algoName 
		//             << "   converged to the right minimum" << std::endl;
		//else {
		//   std::cout << "Minimizer " << minName << " - " << algoName 
		//             << "   failed to converge !!!" << std::endl;
		//   Error("NumericalMinimization","fail to converge");
		//}
		
	}


}