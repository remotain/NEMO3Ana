#include "Observable.h"
#include "DataManagement.h"

#include "THStack.h"
#include "TString.h"
#include "TLegend.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TStyle.h"

ClassImp(Observable);

double Observable::GetComponentNorm(Component * c) { 

	double norm = c->GetNorm() * c->GetParameter()->GetValInit() * DataManagement::GetTotalAcceptedRunTime() / c->GetDataSet()->GetGeneratedEvents(); 
	return norm; 

};

double Observable::GetComponentNumEvent(Component * c) { 
	
	TH1D * htmp = (TH1D *) _ComponentMap->GetValue(c); 
	return GetComponentNorm(c) * htmp->Integral(); 

};


void Observable::Draw(Option_t* option){
	
	THStack * stack = new THStack( TString::Format("stack_%s",GetName()), GetTitle() );
	TH1D * hsum = (TH1D*) _Data->Clone(TString::Format("hadd_%s",_Data->GetName())); 
	hsum->Reset();
	
	TLegend * leg = new TLegend(0.01, 0.6, 0.99, .90);
	leg->SetNColumns(5);
	leg->SetFillColor(kWhite);
	leg->SetTextFont(43);
	leg->SetTextSize(10);
	
	double tot_evt_mc = 0.;
	leg->AddEntry(_Data, TString::Format("%s (%0.f evt.)", "Data", _Data->Integral() ), "PL");
	
	// Loop Over Component collection
	TMapIter next( _ComponentMap );
	while ( Component * comp = (Component *) next() ){
	
		TH1D * h_comp = (TH1D*) _ComponentMap->GetValue(comp);
		h_comp->SetFillColor( comp->GetFillColor() );
		h_comp->SetLineColor( comp->GetLineColor() );
		h_comp->SetLineWidth(1);
		TH1D * tmp = (TH1D*) h_comp->Clone( TString::Format("tmp_%s", h_comp->GetName() ) );
		tmp->Scale( GetComponentNorm(comp) );

		stack->Add(tmp);
		hsum->Add(tmp);
		
		tot_evt_mc += GetComponentNumEvent(comp);
		
		leg->AddEntry(h_comp, TString::Format("%s (%0.f evt.)", comp->GetTitle(), GetComponentNumEvent(comp) ), "F");
	
	}

	leg->AddEntry((TObject*) 0, TString::Format("Total MC (%0.f evt.)", tot_evt_mc ), "");

	TCanvas * canvas = new TCanvas(GetName(), GetTitle());

	// Upper plot will be in pad1                                               
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined                
	pad1->SetTickx();
	pad1->SetLogy(kTRUE);
	pad1->SetTopMargin(0.45) ;
	pad1->SetRightMargin(0.05) ;
    pad1->Draw();
	pad1->cd();
	
	gStyle->SetTitleBorderSize(0);
	_Data->SetTitleFont(43);
	_Data->SetTitleSize(18);
	_Data->SetTitle(GetTitle());
	_Data->SetLineWidth(1);
	_Data->SetMarkerColor( _MarkerColor );
	_Data->SetMarkerStyle( _MarkerStyle );	
	_Data->SetMarkerSize( _MarkerSize );
	_Data->SetStats(kFALSE);
	_Data->GetYaxis()->CenterTitle(kTRUE);
	_Data->GetYaxis()->SetLabelFont(43);
	_Data->GetYaxis()->SetLabelSize(18);
	_Data->GetYaxis()->SetTitleFont(43);
	_Data->GetYaxis()->SetTitleSize(18);
	_Data->GetYaxis()->SetTitleOffset(1.55);
	_Data->GetXaxis()->CenterTitle(kTRUE);
	_Data->GetXaxis()->SetLabelFont(43);
	_Data->GetXaxis()->SetLabelSize(18);
	_Data->GetXaxis()->SetTitleFont(43);
	_Data->GetXaxis()->SetTitleSize(18);
	_Data->GetXaxis()->SetTitleOffset(1.55);
	
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
    pad2->Draw();
    pad2->cd();
	
	TH1D * hratio = (TH1D*) _Data->Clone( TString::Format("ratio_%s", _Data->GetName()) );
	hratio->SetTitle("");
	//hratio->Add(hsum,-1);
	hratio->Divide(hsum);
	
	hratio->GetYaxis()->SetTitle("Data/MC") ; 
	hratio->GetYaxis()->CenterTitle(kTRUE);
	hratio->GetYaxis()->SetLabelFont(43);
	hratio->GetYaxis()->SetLabelSize(18);
	hratio->GetXaxis()->SetLabelFont(43);
	hratio->GetXaxis()->SetLabelSize(18);
	hratio->GetXaxis()->SetTitleFont(43);
	hratio->GetXaxis()->SetTitleSize(20);
	hratio->GetYaxis()->SetTitleFont(43);
	hratio->GetYaxis()->SetTitleSize(18);
	hratio->GetXaxis()->SetTitleOffset(4.);
	hratio->GetYaxis()->SetTitleOffset(1.55);
	hratio->GetYaxis()->SetRangeUser(0.0,2.5);
	hratio->Draw();
	
};