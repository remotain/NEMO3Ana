
#include "DataManagement.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"

#include "Fit.h"

namespace fit{

	//////////////////////////////////////////////////////////////////////////////
	//
	// Fit function
	//		
	//////////////////////////////////////////////////////////////////////////////
	double Fcn(const double *x){
		
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
		   // a IMultiGenFunction type 
		   ROOT::Math::Functor f(&Fcn, DataManagement::GetParameterCollection()->GetEntries() ); 
 
		   min->SetFunction(f);
 
		   // Set the free variables to be minimized!
		   
		   // loop over Parameter list
		   double step[2] = {0.01,0.01};
		   double variable[2] = { -1.,1.2};
		   if (randomSeed >= 0) { 
		      TRandom2 r(randomSeed);
		      variable[0] = r.Uniform(-20,20);
		      variable[1] = r.Uniform(-20,20);
		   }
		   // starting point		   
		   min->SetVariable(0,"x",variable[0], step[0]);
		   min->SetVariable(1,"y",variable[1], step[1]);
 
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