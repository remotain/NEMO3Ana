#include "Observable.h"

#include <iostream>

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
	TH1D * hsum = (TH1D*) _Data->Clone(TString::Format("hadd_%s",_Data->GetName())); 
	hsum->Reset();
	
	TLegend * leg = new TLegend(0.05, 0.6, 0.95, .90);
	
	if(_ComponentList->GetEntries() < 8 )
		leg->SetNColumns(2);
	else 
		leg->SetNColumns(3);
	
	double tot_evt_mc ,tot_evt_mc_err = 0.;
	leg->AddEntry(_Data, TString::Format("%s (%0.f evt.)", "Data", _Data->Integral() ), "PL");
	
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
		hsum->Add(tmp);
				
		double err = 0.;
		
		if ( GetComponentNumEvent(comp,err) != 0 ){	
			tot_evt_mc += GetComponentNumEvent(comp,err);
			tot_evt_mc_err += err*err;
		}
				
		leg->AddEntry(h_comp, TString::Format("%s (%.1f #pm %.1f evt.)", comp->GetTitle(), GetComponentNumEvent(comp,err), err ), "F");
	
	}
	
	tot_evt_mc_err = TMath::Sqrt(tot_evt_mc_err);
	

	leg->AddEntry((TObject*) 0, TString::Format("Total MC (%0.f #pm %0.f evt.)", tot_evt_mc, tot_evt_mc_err), "");

	// Original ROOT chi2 calculation
	_chi2 = 0; _ndf = 0;
	_Data->Chi2TestX(hsum, _chi2, _ndf, _igood, "UU") ;
	leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof (%.1f/%d)", _chi2, _ndf), "");

	// My own chi2 calculation
	//Chi2Test(_Data, hsum, _chi2, _ndf);
	//leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof (%.1f/%d)", _chi2, _ndf), "");

	TCanvas * canvas = new TCanvas(GetName(), GetTitle(), 500, 500);

	// Upper plot will be in pad1                                               
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
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
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0.1);
    pad2->SetBottomMargin(0.4);
	pad2->SetRightMargin(0.05) ;
	pad2->SetTickx();
	pad2->SetTicky();
    pad2->Draw();
    pad2->cd();
	
	TH1D * hratio = (TH1D*) _Data->Clone( TString::Format("ratio_%s", _Data->GetName()) );
	hratio->SetTitle("");
	hratio->Divide(hsum);
		
	hratio->GetYaxis()->SetTitle("Data/MC") ; 
	hratio->GetYaxis()->CenterTitle(kTRUE);
	hratio->GetYaxis()->SetRangeUser(0.0,2.5);
	hratio->Draw();
	
};

void Observable::DrawDetails(Option_t* option){
	
	TH1D * hnorm = new TH1D("hnorm", "; ;Adjustement", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	TH1D * heff  = new TH1D("heff" , "; ;Efficiency", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	TH1D * hevt  = new TH1D("hevt" , "; ;Num. of evts", _ComponentList->GetEntries(), 0, _ComponentList->GetEntries() );
	
	hnorm -> SetMarkerStyle(20); hnorm -> SetMarkerSize(0.8);
	heff  -> SetMarkerStyle(20); heff  -> SetMarkerSize(0.8);
	hevt  -> SetMarkerStyle(20); hevt  -> SetMarkerSize(0.8);
	
	hnorm -> SetStats(kFALSE);
	heff  -> SetStats(kFALSE);
	hevt  -> SetStats(kFALSE);
			
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
		
		hnorm -> SetBinContent(counter+1, comp->GetNorm());
		heff  -> SetBinContent(counter+1, eff);
		hevt  -> SetBinContent(counter+1, numevt);
			
		hnorm -> SetBinError(counter+1,	comp->GetNormErr());
		heff  -> SetBinError(counter+1,	eff_e);
		hevt  -> SetBinError(counter+1,	err);
		
		// Print info	
		//std::cout << comp->GetName() 
		//		<< " " << comp->GetNorm() << " +/- " << comp->GetNormErr() 
		//		<< " " << h_comp->GetEntries() / comp->GetDataSet()->GetGeneratedEvents() 
		//		<< " " << numevt << " +/- " << err << std::endl;
	
		counter++;
				
	}
	
	TCanvas * canvas = new TCanvas(TString::Format("%s_fit_details", GetName()), TString::Format("%s Fit Details", GetTitle()), 500, 500);

	// Upper plot will be in pad1                                               
	canvas->cd();	
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.75, 1, 0.999);
	pad1->SetLogy(kTRUE);
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.1) ;
	pad1->SetBottomMargin(0.01) ;
	pad1->SetRightMargin(0.05) ;
	pad1->Draw();
	pad1->cd();
	heff->Draw();
	
	canvas->cd();
	TPad *pad2 = new TPad("pad2", "pad2", 0, 0.5, 1, 0.75);
	pad2->SetLogy(kTRUE);
    pad2->SetTopMargin(0.01);
    pad2->SetBottomMargin(0.01);
	pad2->SetRightMargin(0.05) ;
	pad2->SetTickx();
	pad2->SetTicky();
	pad2->Draw();
	pad2->cd();
	hnorm->Draw();
		
	canvas->cd();
	TPad *pad3 = new TPad("pad3", "pad3", 0, 0.05, 1, 0.5);
	pad3->SetLogy(kTRUE);
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