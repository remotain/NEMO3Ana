#include <iostream>

#include "DataManagement.h"
#include "Parameter.h"
#include "Observable.h"
#include "Component.h"

#include "TGraph.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TString.h"
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
		
		long double l_likelihood = 0.;
		
		TIter next1( DataManagement::GetObservableCollection() );
		while ( Observable * obs = (Observable *) next1() ){
		
			// Get the data histogram
			TH1D * h_data = (TH1D*) obs->GetData();

			// Define sum of all mc components
			TH1D * h_mc = (TH1D*) h_data->Clone("h_mc");
			h_mc->Reset();
			
			// Loop Over Component collection
			TMapIter next2( obs->GetComponentMap() );
			while ( Component * comp = (Component *) next2() ){
				
				// Get the histogram
				TH1D * h_comp = (TH1D*) obs->GetComponentMap()->GetValue(comp);
				
				// Compute normalisation
				double norm = 0.0;
				if( comp->GetParameter() ){
					 norm = comp->GetAdjustment() * x[comp->GetParameter()->GetOrder()] * DataManagement::GetTotalLiveTime( ) / comp->GetDataSet()->GetGeneratedEvents();
				} else { 
					norm = comp->GetAdjustment() * DataManagement::GetTotalLiveTime( ) / comp->GetDataSet()->GetGeneratedEvents();	
				}
				// Add histogram to the sum
				h_mc->Add(h_comp, norm);

			}
					
			// Loop over the data histogram bin
			for (unsigned int i = obs->GetFitRangeLowBin(); i <= obs->GetFitRangeUpBin(); i++){
				
				// Compute the likelihood
				if( h_mc->GetBinContent(i) > 0 ) {

					l_likelihood += h_data->GetBinContent(i) * TMath::Log(h_mc->GetBinContent(i)) - h_mc->GetBinContent(i) - TMath::LnGamma(h_data->GetBinContent(i)+1);
					
				} else {
					
					l_likelihood += -TMath::LnGamma(h_data->GetBinContent(i)+1);
					
				}
							
			}
			
			// Add gaussian contraints
			TIter next3( DataManagement::GetComponentCollection() );
			while ( Component * comp = (Component *) next3() ){
				
				if( comp->IsGausConstraint() ){
					l_likelihood += TMath::Log( TMath::Gaus(x[comp->GetParameter()->GetOrder()]*comp->GetAdjustment(), comp->GetAdjustment(), comp->GetAdjustmentErr()*x[comp->GetParameter()->GetOrder()], true) );
					//l_likelihood += TMath::Log( TMath::Gaus(x[comp->GetParameter()->GetOrder()]*comp->GetAdjustment(), comp->GetAdjustment(), comp->GetNSigma()*comp->GetAdjustmentErr()*x[comp->GetParameter()->GetOrder()], true) );
				}
			}
			
			h_mc->Delete();
		
		}
		
		// Return -log(L)
		
		return -2*l_likelihood;
	
	}
	
	//////////////////////////////////////////////////////////////////////////////
	//
	// Run the fitter
	//		
	//////////////////////////////////////////////////////////////////////////////
	bool _DoDrawContour = false; unsigned int _nStepContour = 100;
	void DoDrawContour( unsigned int nstep) {_DoDrawContour = true; _nStepContour = nstep; };
	bool _DoDrawScan = false; unsigned int _nStepScan = 1000;
	void DoDrawScan( unsigned int nstep ) {_DoDrawScan = true; _nStepScan = nstep; };
	bool _DoDrawCorrelationMatrix = false;
	void DoDrawCorrelationMatrix(){ _DoDrawCorrelationMatrix = true; };
		
	void Run(const char * minimizerType, const char * algoType){
		
		ROOT::Math::Minimizer * min = ROOT::Math::Factory::CreateMinimizer(minimizerType, algoType);
		
		// set tolerance , etc...
		min->SetMaxFunctionCalls(1000000);
		min->SetTolerance(0.001);
		min->SetPrintLevel(2);

		// create funciton wrapper for minmizer
		ROOT::Math::Functor f(&Fcn, DataManagement::GetParameterCollection()->GetEntries() ); 
 
		min->SetFunction(f);
 
		// Set the free variables to be minimized!
		TIter next1( DataManagement::GetParameterCollection() );
		while ( Parameter * param = (Parameter *) next1() ){
			
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
		TIter next2( DataManagement::GetParameterCollection() );
		while ( Parameter * param = (Parameter *) next2() ){
			
			param->SetValInit(xs[param->GetOrder()]);
			param->SetValError(es[param->GetOrder()]);
		}
				
		// Likelihood Scan
		if( _DoDrawScan ) {
		
			//TCanvas * c0 = new TCanvas("likelihood_scan", "Likelihood Scan");
			//c0->Divide(2, min->NFree()/2 + min->NFree()%2 );
			TIter next4( DataManagement::GetParameterCollection() );
			while ( Parameter * param = (Parameter *) next4() ){
				
				if(param->IsFixed()) continue;
				
				TCanvas * c0 = new TCanvas(TString::Format("likelihood_scan_%s", param->GetName()), TString::Format("Likelihood Scan: %s", param->GetName()));
				
				double x[_nStepScan], y[_nStepScan];
				min->Scan(param->GetOrder(), _nStepScan, x, y, param->GetValInit()-1*param->GetValError(), param->GetValInit()+1*param->GetValError());
				
				c0->cd(param->GetOrder()+1);
				TGraph * g = new TGraph(_nStepScan-1, x, y);
				g->SetName(TString::Format("likelihood_scan_%s", param->GetName()));
				g->SetTitle(TString::Format(";%s;-2*Log(L);", param->GetName()));
				g->GetXaxis()->SetTitleOffset(3.);
				g->Draw("ACP");
				g->SetLineColor(kBlue);
				g->SetLineWidth(2);
				
			}
			
		}
		
		// Likelihood Contour
		if( _DoDrawContour ){ 
			
			TCanvas * c1 = new TCanvas("likelihood_contour", "Likelihood Contour");
			int ncontour = ceil(TMath::Factorial(min->NFree())/(TMath::Factorial(min->NFree()-2)*TMath::Factorial(2))/2);
			c1->Divide(2, ncontour);
			TIter next5( DataManagement::GetParameterCollection() );
			int counter=0;
			while ( Parameter * param1 = (Parameter *) next5() ){
				
				if(param1->IsFixed()) continue;
				
				TIter next6( DataManagement::GetParameterCollection() );
				while ( Parameter * param2 = (Parameter *) next6() ){
				
					if( param1->GetOrder() <= param2->GetOrder() )continue;
					
					double x[_nStepContour], y[_nStepContour];
					min->Contour(param1->GetOrder(), param2->GetOrder(), _nStepContour, x, y);
								
					c1->cd(counter + 1);
					TGraph * g = new TGraph(_nStepContour-1, x, y);
					g->SetName(TString::Format("likelihood_contour_%s_%s", param1->GetName(), param2->GetName()));
					g->SetTitle(TString::Format(";%s;%s;", param1->GetName(), param2->GetName()));
					g->GetXaxis()->SetTitleOffset(3.);
					g->Draw("ACP");
					g->SetLineColor(kBlue);
					g->SetLineWidth(2);
					
					TGraph * g_min = new TGraph(1);
					g_min->SetPoint(1, param1->GetValInit(), param2->GetValInit());
					g_min->Draw("Psame");
					g_min->SetMarkerColor(kRed);
					g_min->SetMarkerStyle(34);
					
					counter++;	
				
				}
			}	
		}
		
		if( _DoDrawCorrelationMatrix ){ 
			
			TCanvas * c1 = new TCanvas("CorrelationMatrix", "Correlation Matrix");
			TH2F * CorrelationMatrix = new TH2F("CorrelationMatrix", "CorrelationMatrix", min->NDim(), 0, min->NDim(), min->NDim(), 0, min->NDim());
			CorrelationMatrix->GetZaxis()->SetRangeUser(-1,1);
			CorrelationMatrix->GetXaxis()->SetTitleOffset(4.);						
			CorrelationMatrix->GetYaxis()->SetTitleOffset(4.);						
						
			for( int i = 0; i < min->NDim(); i++ ){	
				for( int j = 0; j < min->NDim(); j++ ){
					
					CorrelationMatrix->GetXaxis()->SetBinLabel(i, min->VariableName(i).c_str() );
					CorrelationMatrix->GetYaxis()->SetBinLabel(i, min->VariableName(i).c_str() );

					CorrelationMatrix->SetBinContent(i,j, min->Correlation(i,j));
			
				}
			}
			CorrelationMatrix->Draw("COLZ,TEXT");
		}
				
		// Compute the chi2
		double dof = 0;
		TIter next3( DataManagement::GetObservableCollection() );
		while ( Observable * obs = (Observable *) next3() ){
			dof += obs->GetFitRangeUpBin() - obs->GetFitRangeLowBin();
		} dof -= min->NFree();
		std::cout << "CHI^2/dof = " << min->MinValue() << "/" << dof << " = " << min->MinValue()/dof << std::endl;	

		
	}


}