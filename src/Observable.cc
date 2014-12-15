#include "Observable.h"

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
	leg->SetNColumns(2);
	
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

		stack->Add(tmp);
		hsum->Add(tmp);
		
		double err = 0.;		
		tot_evt_mc += GetComponentNumEvent(comp,err);
		tot_evt_mc_err += err*err;
		
		leg->AddEntry(h_comp, TString::Format("%s (%0.f #pm %0.f evt.)", comp->GetTitle(), GetComponentNumEvent(comp,err), err ), "F");
	
	}
	
	tot_evt_mc_err = TMath::Sqrt(tot_evt_mc_err);
	
	_Data->Chi2TestX(hsum, _chi2, _ndf, _igood, "UW,P,CHI2/NDF") ;

	leg->AddEntry((TObject*) 0, TString::Format("Total MC (%0.f #pm %0.f evt.)", tot_evt_mc, tot_evt_mc_err), "");
	leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof (%.3f/%d)", _chi2, _ndf), "");

	TCanvas * canvas = new TCanvas(GetName(), GetTitle(), 500, 500);

	// Upper plot will be in pad1                                               
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined                
	pad1->SetLogy( _LogScale );
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.45) ;
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
    pad2->SetTopMargin(0);
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