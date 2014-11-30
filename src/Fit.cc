
#include "DataManagement.h"
#include "Parameter.h"

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
		
		return 0;
		
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