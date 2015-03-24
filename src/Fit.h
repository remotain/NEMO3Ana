#include "Math/Minimizer.h"

namespace Fit {

	double Fcn(const double *x);
	void Run(const char * minimizerType = "Minuit", const char * algoType = "Migrad");
	
	void DoDrawContour( unsigned int nstep = 100);
	void DoDrawScan( unsigned int nstep  = 1000);
	
};