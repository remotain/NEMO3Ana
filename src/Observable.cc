#include "Observable.h"

#include <iostream>
#include <iomanip>

#include "THStack.h"
#include "TMath.h"
#include "TString.h"
#include "TLegend.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TStyle.h"

ClassImp(Observable);

double Observable::GetComponentNumEvent(Component * c, double &err) { 
	
	TH1D * htmp = (TH1D *) _ComponentMap->GetValue(c);
	
	double int_err = 0.;
	double integral = htmp->IntegralAndError(0, htmp->GetNbinsX(), int_err);
	
	double norm_err = c->GetNormErr();
	double norm = c->GetNorm();
		
	double num_evt = norm * integral; 
	err = num_evt * TMath::Sqrt((norm_err/norm)*(norm_err/norm) + (int_err/integral)*(int_err/integral));
	
	return num_evt; 

};


void Observable::Draw(Option_t* option){
	
	THStack * stack = new THStack( TString::Format("stack_%s",GetName()), GetTitle() );
	_hsum = (TH1D*) _Data->Clone(TString::Format("hadd_%s",_Data->GetName())); 
	_hsum->Reset();
	
	TLegend * leg = new TLegend(0.05, 0.6, 0.95, .90);	
	
	double tot_evt_mc =0.; double tot_evt_mc_err = 0.;

	int num_comp = 0;

	if( _GroupList && _DrawGroup){
		
		if(_GroupList->GetEntries() < 8 ) leg->SetNColumns(2);
		else leg->SetNColumns(3);
		
		
		TIter next1( _GroupList,  kIterForward);
		while ( Group * group = (Group *) next1() ){ 
		
			//Info("Draw()", "Draw group %s", group->GetName() ); 
		
			double g_tot_evt = 0.;
			double g_tot_err = 0.;
			
			TH1D * gsum = (TH1D*) _Data->Clone(TString::Format("hadd_%s", group->GetName())); 
			gsum->Reset();
			gsum->SetFillColor( group->GetFillColor() );
			gsum->SetLineColor( group->GetLineColor() );
			gsum->SetLineWidth(1);			
					
			TIter next2( group->GetComponentList(),  kIterForward);
			while ( Component * comp = (Component *) next2() ){ 
								
				TH1D * h_comp = (TH1D*) _ComponentMap->GetValue(comp->GetName());
    			
				//Info("Draw()", "Draw component %s", comp->GetName() ); 
				
				if ( !h_comp ) {
					Warning("Draw()", "Don't find component histogram for %s", comp->GetName() ); 
					continue;
    			}	
							
				TH1D * tmp = (TH1D*) h_comp->Clone( TString::Format("tmp_%s", h_comp->GetName() ) );
				tmp->Scale( comp->GetNorm() );
				//std::cout << comp->GetName() << " " << comp->GetNorm() << " " << comp->GetNormErr() << std::endl;
				
				// Renormalise the errors
				for (unsigned int i = 1; i <= tmp->GetNbinsX(); i++){
					if(h_comp->GetBinContent(i) != 0 and comp->GetNorm() != 0){
						double tmp_err = tmp->GetBinContent(i)*TMath::Sqrt( TMath::Power(h_comp->GetBinError(i)/h_comp->GetBinContent(i),2) + TMath::Power(comp->GetNormErr()/comp->GetNorm(),2) );
						tmp->SetBinError(i, tmp_err);
						//std::cout << i << " " << tmp->GetBinContent(i) << " " << tmp->GetBinError(i) << std::endl; 
					} 
				}
						
				gsum->Add(tmp);
				
				double err = 0.;
				
				if ( GetComponentNumEvent(comp,err) != 0 ){	
					tot_evt_mc += GetComponentNumEvent(comp,err);
					tot_evt_mc_err += err*err;
					
					g_tot_evt += GetComponentNumEvent(comp,err);
					g_tot_err += err*err;
					
				}
			}			
				
			stack->Add(gsum);
			_hsum->Add(gsum,1);
				
			g_tot_err = TMath::Sqrt(g_tot_err);	
							
			leg->AddEntry(gsum, TString::Format("%s (%.1f #pm %.1f evt.)", group->GetTitle(), g_tot_evt, g_tot_err ), "F");
			
		}
					
	} else {
	
		if(_ComponentList->GetEntries() < 8 ) leg->SetNColumns(2);
		else leg->SetNColumns(3);
	
		// Loop Over Component collection
		//TMapIter next( _ComponentMap,  kIterForward);
		TIter next( _ComponentList,  kIterForward);
		while ( Component * comp = (Component *) next() ){ 
		
			TH1D * h_comp = (TH1D*) _ComponentMap->GetValue(comp);
			h_comp->SetFillColor( comp->GetFillColor() );
			h_comp->SetLineColor( comp->GetLineColor() );
			h_comp->SetLineWidth(1);
			TH1D * tmp = (TH1D*) h_comp->Clone( TString::Format("tmp_%s", h_comp->GetName() ) );
			tmp->Scale( comp->GetNorm() );
			//std::cout << comp->GetName() << " " << comp->GetNorm() << " " << comp->GetNormErr() << std::endl;
				
			// Renormalise the errors
			for (unsigned int i = 1; i <= tmp->GetNbinsX(); i++){
				if(h_comp->GetBinContent(i) != 0 and comp->GetNorm() != 0){
					double tmp_err = tmp->GetBinContent(i)*TMath::Sqrt( TMath::Power(h_comp->GetBinError(i)/h_comp->GetBinContent(i),2) + TMath::Power(comp->GetNormErr()/comp->GetNorm(),2) );
					tmp->SetBinError(i, tmp_err);
					//std::cout << i << " " << tmp->GetBinContent(i) << " " << tmp->GetBinError(i) << std::endl; 
				} 
			}
				
			stack->Add(tmp);
			_hsum->Add(tmp);
			
			double err = 0.;
		
			if ( GetComponentNumEvent(comp,err) != 0 ){	
				tot_evt_mc += GetComponentNumEvent(comp,err);
				tot_evt_mc_err += err*err;
			}
			
			if( GetComponentNumEvent(comp,err) != 0. ) {		
				leg->AddEntry(h_comp, TString::Format("%s (%.1f #pm %.1f evt.)", comp->GetTitle(), GetComponentNumEvent(comp,err), err ), "F");
			}		
			
		}
	
	}
	
	tot_evt_mc_err = TMath::Sqrt(tot_evt_mc_err);
	
	leg->AddEntry(_Data, TString::Format("%s (%0.f evt.)", "Data", _Data->Integral() ), "PL");
	leg->AddEntry((TObject*) 0, TString::Format("Total MC (%0.f #pm %0.f evt.)", tot_evt_mc, tot_evt_mc_err), "");

	
	_chi2 = 0; _ndf = 0;
	_pval = _Data->Chi2TestX(_hsum, _chi2, _ndf, _igood, "UW") ;
	_ks = _Data-> KolmogorovTest(_hsum) ;
	
	//leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof (%.1f/%d)", _chi2, _ndf), "");

	// My own chi2 calculation
	//Chi2Test(_Data, _hsum, _chi2, _ndf);
	//leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof (%.1f/%d)", _chi2, _ndf), "");

	TCanvas * canvas = new TCanvas(GetName(), GetTitle(), 500, 500);

	// Upper plot will be in pad1                                               
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
	pad1->SetLogy( _LogScale );
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.45) ;
	pad1->SetBottomMargin(0.01) ;
	pad1->SetRightMargin(0.05) ;
    pad1->Draw();
	pad1->cd();
	
	gStyle->SetTitleBorderSize(0);
	//gStyle->SetTitleFont(43,"");
	_Data->SetTitle(GetTitle());
	_Data->SetLineWidth(1);
	_Data->SetMarkerColor( _MarkerColor );
	_Data->SetMarkerStyle( _MarkerStyle );	
	_Data->SetMarkerSize( _MarkerSize );
	_Data->SetStats(kFALSE);
	_Data->GetYaxis()->CenterTitle(kTRUE);
	_Data->GetXaxis()->CenterTitle(kTRUE);
	
	_Data->Draw(option);
	stack->Draw(TString::Format("A,SAME,HIST,%s",option));
	_Data->Draw("SAME");
	leg->Draw();
	
	canvas->cd();	
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40);
    pad2->SetTopMargin(0.1);
    pad2->SetBottomMargin(0.01);
	pad2->SetRightMargin(0.05) ;
	pad2->SetTickx();
	pad2->SetTicky();
    pad2->Draw();
    pad2->cd();
	
	TH1D * hratio = (TH1D*) _Data->Clone( TString::Format("ratio_%s", _Data->GetName()) );
	hratio->SetTitle("");
	hratio->Divide(_hsum);
		
	hratio->GetYaxis()->SetNdivisions(505) ; 	
	hratio->GetYaxis()->SetTitle("Data/MC") ; 
	hratio->GetYaxis()->CenterTitle(kTRUE);
	hratio->GetYaxis()->SetRangeUser(0.0,4.0);
	hratio->Draw();
	
	canvas->cd();	
    TPad *pad3 = new TPad("pad3", "pad3", 0, 0.01, 1, 0.25);
    pad3->SetTopMargin(0.1);
    pad3->SetBottomMargin(0.4);
	pad3->SetRightMargin(0.05) ;
	pad3->SetTickx();
	pad3->SetTicky();
    pad3->Draw();
    pad3->cd();
	
	TH1D * hres = (TH1D*) _Data->Clone( TString::Format("residuals_%s", _Data->GetName()) );
	hres->SetTitle("");
	hres->Add(_hsum, -1);
	
	for (unsigned int i = 1; i <= hratio->GetNbinsX(); i++){
	
		if( hratio->GetBinError(i) == 0 ) continue;
		
		hres->SetBinContent(i, hres->GetBinContent(i) / TMath::Sqrt( _Data->GetBinContent(i) ) );
		hres->SetBinError(i, TMath::Sqrt( TMath::Abs(hres->GetBinContent(i)) ) );
	
	
	}  
	
	hres->GetYaxis()->SetNdivisions(505) ; 
	hres->GetYaxis()->SetTitle("Residuals") ; 
	hres->GetYaxis()->CenterTitle(kTRUE);
	hres->GetYaxis()->SetRangeUser(-5.0,5.0);
	hres->Draw();
	
};

void Observable::PrintQuality(){
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << GetName() << std::endl;	
	std::cout << TString::Format("#chi^2/dof (%.1f/%d), p-value %.3f", _chi2, _ndf, _pval) << std::endl;
	std::cout << TString::Format("KS = %.3f", _ks) << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

}

void Observable::PrintDetails(){
	
	// Loop Over Component collection
	//TMapIter next( _ComponentMap,  kIterForward);
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Number of entries for \"" << GetName() << "\""<< std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	

	TIter next( _ComponentList,  kIterForward);
	while ( Component * comp = (Component *) next() ){ 
		
		double err = 0.;
		double n = 0.;
		
		if ( GetComponentNumEvent(comp,err) != 0 ) n = GetComponentNumEvent(comp,err);
		else err = 0. ;
			
		std::cout << std::setw(20) << comp->GetName() << " = " << std::setw(10) << n << " +/- " << err << std::endl;
		
	}

	std::cout << "--------------------------------------------------" << std::endl;

	if( _GroupList && _DrawGroup){

		std::cout << " "<< std::endl;
		std::cout << "--------------------------------------------------" << std::endl;	
				
		TIter next1( _GroupList,  kIterForward);
		while ( Group * group = (Group *) next1() ){ 

			double tot_err = 0.;
			double tot_n = 0.;
				
			TIter next2( group->GetComponentList(),  kIterForward);
			while ( Component * comp = (Component *) next2() ){ 

				if ( ! (TH1D*) _ComponentMap->GetValue(comp->GetName()) ) {
					//Warning("Draw()", "Don't find component histogram for %s", comp->GetName() ); 
					continue;
    			}	

				double err = 0.;
				
				if ( GetComponentNumEvent(comp,err) != 0 ) tot_n += GetComponentNumEvent(comp,err);
				else err = 0. ;
				
				tot_err += err*err;
				
			}
	
			std::cout << std::setw(20) << group->GetName() << " = " << std::setw(10) << tot_n << " +/- " << TMath::Sqrt(tot_err) << std::endl;
	
		}
		
		std::cout << "--------------------------------------------------" << std::endl;	
				
	}
	
};

void Observable::DrawDetails(Option_t* option){
	
	TH1D * hnorm = new TH1D("hnorm", "; ;Adjustement", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	TH1D * heff  = new TH1D("heff" , "; ;Efficiency", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	TH1D * hevt  = new TH1D("hevt" , "; ;Num. of evts", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	
	hnorm -> SetMarkerStyle(20); hnorm -> SetMarkerSize(0.80);
	heff  -> SetMarkerStyle(20); heff  -> SetMarkerSize(0.80);
	hevt  -> SetMarkerStyle(20); hevt  -> SetMarkerSize(0.80);
	
	hnorm -> SetStats(kFALSE);
	heff  -> SetStats(kFALSE);
	hevt  -> SetStats(kFALSE);
	
	hnorm ->GetYaxis()->SetTitleOffset(4.);
	heff  ->GetYaxis()->SetTitleOffset(4.);
	hevt  ->GetYaxis()->SetTitleOffset(4.);
		
	//std::cout << "Fit components" << " & " << "Efficiency" << " & " << "Activity [Bq]" << " & " << "Num. of events" << std::endl;	
			
	// Loop Over Component collection
	int counter = 0;
	//TMapIter next( _ComponentMap,  kIterForward);
	TIter next( _ComponentList,  kIterForward);
	while ( Component * comp = (Component *) next() ){ 
		
		TH1D * h_comp = (TH1D*) _ComponentMap->GetValue(comp);
		double err = 0; double numevt = GetComponentNumEvent(comp,err);
		double eff = h_comp->GetEntries() / comp->GetDataSet()->GetGeneratedEvents();
		double eff_e = sqrt(eff*(1-eff)/comp->GetDataSet()->GetGeneratedEvents());
		
		hnorm ->GetXaxis()->SetBinLabel(counter+1, comp->GetName());
		heff  ->GetXaxis()->SetBinLabel(counter+1, comp->GetName());
		hevt  ->GetXaxis()->SetBinLabel(counter+1, comp->GetName());	
		
		hevt -> GetXaxis() -> LabelsOption("v");
		
		if( comp->GetNorm() != 0 ) {
			hnorm -> SetBinContent(counter+1, comp->GetNorm()) ; 
			hnorm -> SetBinError(counter+1 , comp->GetNormErr());
		} 
		if( eff != 0 ) { 
			heff  -> SetBinContent(counter+1, eff); 
			heff  -> SetBinError(counter+1 , eff_e);
		} 
		if( numevt != 0 ) {
			hevt  -> SetBinContent(counter+1, numevt); 
			hevt  -> SetBinError(counter+1 , err);
		}
		
	//	std::cout << comp->GetName() << " & " << eff << "\\pm" << eff_e << " & " << comp->GetNorm() << "\\pm" << comp->GetNormErr() << " & " << numevt << "\\pm" << err << std::endl;
				
		counter++;
				
	}
	
	TCanvas * canvas = new TCanvas(TString::Format("%s_fit_details", GetName()), TString::Format("%s Fit Details", GetTitle()), 700, 1000);

	// Upper plot will be in pad1                                               
	canvas->cd();	
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.75, 1, 0.999);
	pad1->SetLogy(kTRUE);
	pad1->SetGridx(kFALSE);
	pad1->SetGridy(kFALSE);
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.1) ;
	pad1->SetBottomMargin(0.005) ;
	pad1->SetRightMargin(0.05) ;
	pad1->Draw();
	pad1->cd();
	heff->Draw();
	
	canvas->cd();
	TPad *pad2 = new TPad("pad2", "pad2", 0, 0.5, 1, 0.75);
	pad2->SetLogy(kTRUE);
	pad2->SetGridx(kFALSE);
	pad2->SetGridy(kFALSE);	
    pad2->SetTopMargin(0.01);
    pad2->SetBottomMargin(0.005);
	pad2->SetRightMargin(0.05) ;
	pad2->SetTickx();
	pad2->SetTicky();
	pad2->Draw();
	pad2->cd();
	hnorm->Draw();
		
	canvas->cd();
	TPad *pad3 = new TPad("pad3", "pad3", 0, 0.05, 1, 0.5);
	pad3->SetLogy(kTRUE);
	pad3->SetGridx(kFALSE);
	pad3->SetGridy(kFALSE);
    pad3->SetTopMargin(0.01);
    pad3->SetBottomMargin(0.50);
	pad3->SetRightMargin(0.05) ;
	pad3->SetTickx();
	pad3->SetTicky();
    pad3->Draw();
	pad3->cd();
	hevt->Draw();

	
};

void Observable::Chi2Test(TH1 * hData, TH1 * hModel, double & chi2, int & ndf){
	
	chi2 = 0;
	ndf = 0;
	
	// Loop over the data histogram bin
	for (unsigned int i = 1; i <= hData->GetNbinsX(); i++){
		
		// Exclude bin with low number of entries from the chi2 calculation
		if( hData->GetBinContent(i) == 0 && hModel->GetBinContent(i) == 0 ) {
			continue;
		}  else if ( hData->GetBinContent(i) > 0 && hModel->GetBinContent(i) > 0 ) {

			chi2 += TMath::Power( (hModel->GetBinContent(i) - hData->GetBinContent(i)) , 2 ) / (hData->GetBinError(i)*hData->GetBinError(i) + hModel->GetBinError(i)*hModel->GetBinError(i));
			
		} else if ( hData->GetBinContent(i) == 0 && hModel->GetBinContent(i) > 0 ) {

			chi2 += TMath::Power( (hModel->GetBinContent(i) - hData->GetBinContent(i)) , 2 ) / (hModel->GetBinError(i)*hModel->GetBinError(i));			
			
		} else if ( hData->GetBinContent(i) > 0 && hModel->GetBinContent(i) == 0) {

			chi2 += TMath::Power( (hModel->GetBinContent(i) - hData->GetBinContent(i)) , 2 ) / (hData->GetBinError(i)*hData->GetBinError(i));			
			
		}

		ndf++;
		
	}
	
	ndf = ndf - 1;
	
};