#include <iostream>
#include <map>
#include <string>

void DrawBDTScore( TString myModel = "" ){
		
	//gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");

	//gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/LoadAllDataSample.C+");

	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");
	
    // Default model to be trained + tested
    std::map<std::string,int> Model;

    // --- Cut optimisation
    Model[ "MM"    ]  = 0; // Mass mechanism
    Model[ "RHC_L" ]  = 0; // Right Handed Current
    Model[ "RHC_E" ]  = 0; // Right Handed Current	
    Model[ "M1"    ]  = 0; // Majoron
    Model[ "M2"    ]  = 0; // Majoron
    Model[ "M3"    ]  = 0; // Majoron
    Model[ "M7"    ]  = 0; // Majoron
	
    if(myModel != "") {
  	
 		std::string regModel(myModel);
		
 		if( Model.find(regModel) == Model.end() ){
 			std::cout << "Model \"" << myModel << "\" not known in under this name. Choose among the following:" << std::endl;
 			for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
 			std::cout << std::endl;
 			return;
 		}
	   
 		Model[regModel] = 1;
	
    } else {
   	
 	   std::cout << "No signal model as been specified. You must choose one among the following:" << std::endl;
        for (std::map<std::string,int>::iterator it = Model.begin(); it != Model.end(); it++) std::cout << it->first << " ";
        std::cout << std::endl;
        return;
    }

    // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
    TString fn;
	fn.Form( "TMVApp_%s.root", myModel.Data() );
	TString fd( "/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/TMVApp/" );
	TFile * f = TFile::Open( fd + fn , "READ" );
	f->Print();
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Data distribution
	//
	//////////////////////////////////////////////////////////////////////////////	
	TH1F *       Data        = f->Get( "Data_MVA_BDT"           );              Data->Sumw2();	

	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Arbitrary normalisation
	//
	//////////////////////////////////////////////////////////////////////////////		
    TH1F* Signal = 0;
	
	if ( Model[ "MM"    ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m1_MVA_BDT"   ) ; 
    if ( Model[ "RHC_L" ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m2_MVA_BDT"   ) ; 
    if ( Model[ "RHC_E" ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m18_MVA_BDT"  ) ; 	
    if ( Model[ "M1"    ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m5_MVA_BDT"   ) ; 
    if ( Model[ "M2"    ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m15_MVA_BDT"  ) ; 
    if ( Model[ "M3"    ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m6_MVA_BDT"   ) ; 
    if ( Model[ "M7"    ] ) Signal = (TH1F*) f->Get( "Cd116_2b0n_m7_MVA_BDT"   ) ; 
	
	Signal->Scale( ( 100 ) / Signal ->Integral() );
	
	
	//////////////////////////////////////////////////////////////////////////////
	//	
	// Background distribution (renormalise histogram wrt best fit)
	//
	//////////////////////////////////////////////////////////////////////////////	
    TH1F *  Cd116_Tl208      = f->Get("Cd116_Tl208_MVA_BDT"    ) ; if( Cd116_Tl208    ) { Cd116_Tl208    -> Scale( (5.93241           ) / Cd116_Tl208     ->Integral() ) ; };
    TH1F *  Cd116_Ac228      = f->Get("Cd116_Ac228_MVA_BDT"    ) ; if( Cd116_Ac228    ) { Cd116_Ac228    -> Scale( (6.92004           ) / Cd116_Ac228     ->Integral() ) ; };
    TH1F *  Cd116_Bi212      = f->Get("Cd116_Bi212_MVA_BDT"    ) ; if( Cd116_Bi212    ) { Cd116_Bi212    -> Scale( (2.74493           ) / Cd116_Bi212     ->Integral() ) ; };
    TH1F *  Cd116_Bi214      = f->Get("Cd116_Bi214_MVA_BDT"    ) ; if( Cd116_Bi214    ) { Cd116_Bi214    -> Scale( (18.2853           ) / Cd116_Bi214     ->Integral() ) ; };
    TH1F *  Cd116_Pb214      = f->Get("Cd116_Pb214_VT_MVA_BDT" ) ; if( Cd116_Pb214    ) { Cd116_Pb214    -> Scale( (0.186478          ) / Cd116_Pb214     ->Integral() ) ; };
    TH1F *  Mylar_Bi214      = f->Get("Mylar_Bi214_MVA_BDT"    ) ; if( Mylar_Bi214    ) { Mylar_Bi214    -> Scale( (11.1896           ) / Mylar_Bi214     ->Integral() ) ; };
    TH1F *  Mylar_Pb214      = f->Get("Mylar_Pb214_MVA_BDT"    ) ; if( Mylar_Pb214    ) { Mylar_Pb214    -> Scale( (0.493241          ) / Mylar_Pb214     ->Integral() ) ; };
    TH1F *  Cd116_K40        = f->Get("Cd116_K40_MVA_BDT"      ) ; if( Cd116_K40      ) { Cd116_K40      -> Scale( (25.9835+9.02952   ) / Cd116_K40       ->Integral() ) ; };
    TH1F *  Cd116_Pa234m     = f->Get("Cd116_Pa234m_MVA_BDT"   ) ; if( Cd116_Pa234m   ) { Cd116_Pa234m   -> Scale( (27.7433+72.4378   ) / Cd116_Pa234m    ->Integral() ) ; };
    TH1F *  SFoil_Bi210      = f->Get("SFoil_Bi210_MVA_BDT"    ) ; if( SFoil_Bi210    ) { SFoil_Bi210    -> Scale( (23.243            ) / SFoil_Bi210     ->Integral() ) ; };
    TH1F *  SWire_Bi210      = f->Get("SWire_Bi210_MVA_BDT"    ) ; if( SWire_Bi210    ) { SWire_Bi210    -> Scale( (0.136147+0.624186 ) / SWire_Bi210     ->Integral() ) ; };
    TH1F *  SScin_Bi210      = f->Get("SScin_Bi210_MVA_BDT"    ) ; if( SScin_Bi210    ) { SScin_Bi210    -> Scale( (1.756             ) / SScin_Bi210     ->Integral() ) ; };
    TH1F *  SScin_Bi214      = f->Get("SScin_Bi214_MVA_BDT"    ) ; if( SScin_Bi214    ) { SScin_Bi214    -> Scale( (0.050538          ) / SScin_Bi214     ->Integral() ) ; };
    TH1F *  SScin_Pb214      = f->Get("SScin_Pb214_MVA_BDT"    ) ; if( SScin_Pb214    ) { SScin_Pb214    -> Scale( (0.                ) / SScin_Pb214     ->Integral() ) ; };
    TH1F *  SWire_Tl208      = f->Get("SWire_Tl208_MVA_BDT"    ) ; if( SWire_Tl208    ) { SWire_Tl208    -> Scale( (0.217623+1.07644  ) / SWire_Tl208     ->Integral() ) ; };
    TH1F *  SWire_Bi214_P1   = f->Get("SWire_Bi214_MVA_BDT"    ) ; if( SWire_Bi214_P1 ) { SWire_Bi214_P1 -> Scale( (21.4626+17.9578   ) / SWire_Bi214_P1  ->Integral() ) ; };
    TH1F *  SFoil_Bi214      = f->Get("SFoil_Bi214_MVA_BDT"    ) ; if( SFoil_Bi214    ) { SFoil_Bi214    -> Scale( (5.77558+2.73528   ) / SFoil_Bi214     ->Integral() ) ; };
    TH1F *  SWire_Pb214      = f->Get("SWire_Pb214_MVA_BDT"    ) ; if( SWire_Pb214    ) { SWire_Pb214    -> Scale( (0.457546+0.648406 ) / SWire_Pb214     ->Integral() ) ; };
    TH1F *  SFoil_Pb214      = f->Get("SFoil_Pb214_MVA_BDT"    ) ; if( SFoil_Pb214    ) { SFoil_Pb214    -> Scale( (0.215627+0.188876 ) / SFoil_Pb214     ->Integral() ) ; };
    TH1F *  FeShield_Bi214   = f->Get("FeShield_Bi214_MVA_BDT" ) ; if( FeShield_Bi214 ) { FeShield_Bi214 -> Scale( (49.1846           ) / FeShield_Bi214  ->Integral() ) ; };
    TH1F *  FeShield_Tl208   = f->Get("FeShield_Tl208_MVA_BDT" ) ; if( FeShield_Tl208 ) { FeShield_Tl208 -> Scale( (1.19312           ) / FeShield_Tl208  ->Integral() ) ; };
    TH1F *  FeShield_Ac228   = f->Get("FeShield_Ac228_MVA_BDT" ) ; if( FeShield_Ac228 ) { FeShield_Ac228 -> Scale( (0.17612           ) / FeShield_Ac228  ->Integral() ) ; };
    TH1F *  CuTower_Co60     = f->Get("CuTower_Co60_MVA_BDT"   ) ; if( CuTower_Co60   ) { CuTower_Co60   -> Scale( (3.77603           ) / CuTower_Co60    ->Integral() ) ; };
    TH1F *  Air_Bi214_P1     = f->Get("Air_Bi214_MVA_BDT"      ) ; if( Air_Bi214_P1   ) { Air_Bi214_P1   -> Scale( (4.19271           ) / Air_Bi214_P1    ->Integral() ) ; };
    TH1F *  Air_Tl208_P1     = f->Get("Air_Tl208_MVA_BDT"      ) ; if( Air_Tl208_P1   ) { Air_Tl208_P1   -> Scale( (0.                ) / Air_Tl208_P1    ->Integral() ) ; };
    TH1F *  PMT_Bi214        = f->Get("PMT_Bi214_MVA_BDT"      ) ; if( PMT_Bi214      ) { PMT_Bi214      -> Scale( (30.7385           ) / PMT_Bi214       ->Integral() ) ; };
    TH1F *  PMT_Tl208        = f->Get("PMT_Tl208_MVA_BDT"      ) ; if( PMT_Tl208      ) { PMT_Tl208      -> Scale( (23.2701           ) / PMT_Tl208       ->Integral() ) ; };
    TH1F *  PMT_Ac228        = f->Get("PMT_Ac228_MVA_BDT"      ) ; if( PMT_Ac228      ) { PMT_Ac228      -> Scale( (3.60944           ) / PMT_Ac228       ->Integral() ) ; };
    TH1F *  PMT_K40          = f->Get("PMT_K40_MVA_BDT"        ) ; if( PMT_K40        ) { PMT_K40        -> Scale( (16.7905           ) / PMT_K40         ->Integral() ) ; };
    TH1F *  ScintInn_K40     = f->Get("ScintInn_K40_MVA_BDT"   ) ; if( ScintInn_K40   ) { ScintInn_K40   -> Scale( (0.335557          ) / ScintInn_K40    ->Integral() ) ; };
    TH1F *  ScintOut_K40     = f->Get("ScintOut_K40_MVA_BDT"   ) ; if( ScintOut_K40   ) { ScintOut_K40   -> Scale( (0.604003          ) / ScintOut_K40    ->Integral() ) ; };
    TH1F *  ScintPet_K40     = f->Get("ScintPet_K40_MVA_BDT"   ) ; if( ScintPet_K40   ) { ScintPet_K40   -> Scale( (1.00666           ) / ScintPet_K40    ->Integral() ) ; };
    TH1F *  MuMetal_Pa234m   = f->Get("MuMetal_Pa234m_MVA_BDT" ) ; if( MuMetal_Pa234m ) { MuMetal_Pa234m -> Scale( (0.66462           ) / MuMetal_Pa234m  ->Integral() ) ; };
    TH1F *  Cd116_2b2n_m14   = f->Get("Cd116_2b2n_m14_MVA_BDT" ) ; if( Cd116_2b2n_m14 ) { Cd116_2b2n_m14 -> Scale( (5022.22           ) / Cd116_2b2n_m14  ->Integral() ) ; };

	// Set the groups
	TH1F * Tl208 = SWire_Tl208->Clone("Tl208");
	Tl208 -> Add( Cd116_Tl208    );
	Tl208 -> Add( Cd116_Ac228    );
	Tl208 -> Add( Cd116_Bi212    );
	
	TH1F * Bi214 = Mylar_Bi214->Clone("Bi214");
	Bi214 -> Add( Mylar_Pb214 );
	Bi214 -> Add( Cd116_Bi214 );
	Bi214 -> Add( Cd116_Pb214 );
	
	TH1F * K40 = Cd116_K40->Clone("K40");
	
	TH1F * Pa234m = Cd116_Pa234m->Clone("Pa234m");
	
	TH1F * Bi210 = SFoil_Bi210->Clone("Bi210");
	Bi210 -> Add( SWire_Bi210   );
	
	TH1F * Radon = SWire_Bi214_P1->Clone("Radon");
	Radon -> Add( SWire_Pb214 );
	Radon -> Add( SFoil_Bi214 );
	Radon -> Add( SFoil_Pb214 );
		
	TH1F * Externals = FeShield_Bi214->Clone("Externals");
	Externals -> Add( FeShield_Bi214 );
	Externals -> Add( FeShield_Tl208 );
	Externals -> Add( FeShield_Ac228 );
	Externals -> Add( CuTower_Co60   );
	Externals -> Add( Air_Bi214_P1   );
	Externals -> Add( Air_Tl208_P1   );	
	Externals -> Add( PMT_Bi214      );
	Externals -> Add( PMT_Tl208      );
	Externals -> Add( PMT_Ac228      );
	Externals -> Add( PMT_K40        );
	Externals -> Add( ScintInn_K40   );
	Externals -> Add( ScintOut_K40   );
	Externals -> Add( ScintPet_K40   );
	Externals -> Add( SScin_Bi210    );
	Externals -> Add( SScin_Bi214    );
	Externals -> Add( SScin_Pb214    );
	Externals -> Add( MuMetal_Pa234m );
	

	Tl208          -> SetFillColor( kOrange + 10 );
	Bi214          -> SetFillColor( kGreen  +  0 );
	Radon          -> SetFillColor( kAzure  +  1 );
	Externals      -> SetFillColor( kOrange +  0 );
	K40            -> SetFillColor( kViolet +  1 );
	Pa234m         -> SetFillColor( kViolet +  0 );	
	Bi210          -> SetFillColor( kGreen  +  2 );
	Cd116_2b2n_m14 -> SetFillColor( kViolet + 10 );
	
	Signal ->SetLineColor(kGray+3);
	Signal ->SetLineWidth(3);
	
	// Set the Stack
	THStack * Stack = new THStack("stack","stack");
	Stack->Add( Tl208          );
	Stack->Add( Bi214          );
	Stack->Add( K40            );
	Stack->Add( Pa234m         );
	Stack->Add( Bi210          );
	Stack->Add( Radon          );
	Stack->Add( Externals      );
	Stack->Add( Cd116_2b2n_m14 );
	
	TH1F * hsum = Cd116_2b2n_m14->Clone("hsum");
	hsum -> Add (Tl208    );
	hsum -> Add (Bi214    );
	hsum -> Add (Radon    );
	hsum -> Add (Externals);
	hsum -> Add (K40      );
	hsum -> Add (Pa234m   );
	hsum -> Add (Bi210    );
	
	//TCanvas * c = new TCanvas();
	//Data->Draw();       
	//Stack->Draw("same");
	
	TCanvas * canvas = new TCanvas("BDT", "BDT", 500, 500);

	Bool_t _LogScale = kTRUE;
	Style_t _MarkerStyle = 20;
	Size_t _MarkerSize  = 0.5;
	Color_t _MarkerColor = kBlack;

	// Upper plot will be in pad1                                               
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.40, 1, 1.0);
	pad1->SetLogy( _LogScale );
	pad1->SetTickx();
	pad1->SetTicky();
	pad1->SetTopMargin(0.15) ;
	pad1->SetBottomMargin(0.01) ;
	pad1->SetRightMargin(0.05) ;
    pad1->Draw();
	pad1->cd();
	
	gStyle->SetTitleBorderSize(0);
	//gStyle->SetTitleFont(43,"");
	TString title;
	title.Form( "BDT Score (%s)", myModel.Data() );
	Data->SetTitle(title);
	Data->SetLineWidth(1);
	Data->SetMarkerColor( _MarkerColor );
	Data->SetMarkerStyle( _MarkerStyle );	
	Data->SetMarkerSize( _MarkerSize );
	Data->SetStats(kFALSE);
	Data->GetXaxis()->SetTitle("BDT Score");
	Data->GetYaxis()->SetTitle("No.Events");
	Data->GetYaxis()->CenterTitle(kTRUE);
	Data->GetXaxis()->CenterTitle(kTRUE);
	Data->GetYaxis()->SetRangeUser(1e-2,5e+3);
	
	Data->Draw("");
	Stack->Draw(TString::Format("A,SAME,HIST,%s",""));
	Data->Draw("SAME");
	Signal->Draw("SAME");
	//leg->Draw();
	
	canvas->cd();	
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.25, 1, 0.40);
    pad2->SetTopMargin(0.1);
    pad2->SetBottomMargin(0.01);
	pad2->SetRightMargin(0.05) ;
	pad2->SetTickx();
	pad2->SetTicky();
    pad2->Draw();
    pad2->cd();
	
	TH1D * hratio = (TH1D*) Data->Clone( TString::Format("ratio_%s", Data->GetName()) );
	hratio->SetTitle("");
	hratio->Divide(hsum);
		
	hratio->GetYaxis()->SetNdivisions(505) ; 	
	hratio->GetYaxis()->SetTitle("Data/MC") ; 
	hratio->GetYaxis()->CenterTitle(kTRUE);
	hratio->GetYaxis()->SetRangeUser(0.,5.);
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
	
	TH1D * hres = (TH1D*) Data->Clone( TString::Format("residuals_%s", Data->GetName()) );
	hres->SetTitle("");
	hres->Add(hsum, -1);
	
	for (unsigned int i = 1; i <= hratio->GetNbinsX(); i++){
	
		if( hratio->GetBinError(i) == 0 ) continue;
		
		hres->SetBinContent(i, hres->GetBinContent(i) / TMath::Sqrt( Data->GetBinContent(i) ) );
		hres->SetBinError(i, TMath::Sqrt( TMath::Abs(hres->GetBinContent(i)) ) );
	
	
	}  
	
	hres->GetYaxis()->SetNdivisions(505) ; 
	hres->GetYaxis()->SetTitle("Residuals") ; 
	hres->GetYaxis()->CenterTitle(kTRUE);
	hres->GetYaxis()->SetRangeUser(-5.0,5.0);
	hres->Draw();
	
	Double_t _chi2 = 0; Int_t _ndf = 0; Int_t _igood = 0;
	Data->Chi2Test(hsum, "PUW") ;
	Double_t _pval = Data->Chi2TestX(hsum, _chi2, _ndf, _igood, "PUW") ;
	Double_t _ks = Data-> KolmogorovTest(hsum,"D") ;

 	TLegend * leg =  new TLegend(0.20,0.8,0.35,0.35);
	leg->AddEntry(Data,"Data","PL");
	leg->AddEntry(Signal,"0#nu#beta#beta (" + myModel + ")","L");
	leg->AddEntry( Cd116_2b2n_m14 , "2#nu#beta#beta" , "F");
	leg->AddEntry( Externals      , "Externals"      , "F");
	leg->AddEntry( Radon          , "Radon"          , "F");
	leg->AddEntry( Bi210          , "Bi210"          , "F");
	leg->AddEntry( Pa234m         , "Pa234m"         , "F");
	leg->AddEntry( K40            , "K40"            , "F");
	leg->AddEntry( Bi214          , "Bi214"          , "F");			
	leg->AddEntry( Tl208          , "Tl208"          , "F");
	
	//leg->AddEntry((TObject*) 0, TString::Format("#chi^2/dof = %.1f/%d ", _chi2, _ndf), "");
	//leg->AddEntry((TObject*) 0, TString::Format("K-S = %.3f", _ks), "");
	
	pad1->cd();
	leg->Draw();

    TString pn;
	pn.Form( "plots/BDTScore_%s.pdf", myModel.Data() );
	(TPad*)gROOT->GetSelectedPad()->Print(pn);

	DrawCutEff(Signal, hsum);
	
}

void DrawCutEff(TH1F * sig, TH1F* bkg){
	
	sig->Scale( 1000. / sig->Integral() );
	bkg->Scale( 1000. / bkg->Integral() );
		
	Double_t x[100], sig_eff[100], bkg_eff[100], sig_sig[100];
	
    std::map<double,bool> Treshold;

    Treshold[ 0.20 ] = false;
    Treshold[ 0.50 ] = false;
    Treshold[ 0.80 ] = false;		
    Treshold[ 0.90 ] = false;		
	Treshold[ 0.95 ] = false;		
	Treshold[ 0.99 ] = false;		

	std::map<double,bool>::iterator iter;
	for (iter = Treshold.begin(); iter != Treshold.end(); iter++){
		std::cout << iter->first << " " << iter->second << std::endl;
	}

				
	for(int i = 0; i < sig->GetNbinsX(); i++) {
		
		x[i] = sig->GetBinCenter(i+1);
		
		sig_eff[i] = sig->Integral(i+1, sig->GetNbinsX()) / sig->Integral(1, sig->GetNbinsX());
		bkg_eff[i] = bkg->Integral(i+1, sig->GetNbinsX()) / bkg->Integral(1, sig->GetNbinsX());
		
		if ( sig->Integral(i+1, sig->GetNbinsX()) + bkg->Integral(i+1, sig->GetNbinsX()) != 0 ) {
			sig_sig[i] = sig->Integral(i+1, sig->GetNbinsX()) / TMath::Sqrt(sig->Integral(i+1, sig->GetNbinsX()) + bkg->Integral(i+1, sig->GetNbinsX()));
		}
		
		
		
		
	}
	
	TGraph * g_sig_eff = new TGraph(sig->GetNbinsX(), x, sig_eff); g_sig_eff->SetLineWidth(3); g_sig_eff->SetLineColor(kBlue);
	TGraph * g_bkg_eff = new TGraph(sig->GetNbinsX(), x, bkg_eff); g_bkg_eff->SetLineWidth(3); g_bkg_eff->SetLineColor(kRed);
	
	TCanvas * c_eff = new TCanvas();
	g_sig_eff->Draw("AL");
	g_bkg_eff->Draw("Lsame");

	TGraph * g_sig_sig = new TGraph(sig->GetNbinsX(), x, sig_sig); g_sig_sig->SetLineWidth(3); g_sig_sig->SetLineColor(kGreen+1);
	
	TCanvas * c_sig = new TCanvas();
	g_sig_sig->Draw("AL");

	TGraph * g_eff = new TGraph(sig->GetNbinsX(), sig_eff, bkg_eff); g_eff->SetLineWidth(3); //g_eff->SetLineColor(kGreen+1);
	
	TCanvas * c_ = new TCanvas();
	g_eff->Draw("AL");
	
}
