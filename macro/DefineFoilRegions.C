{ 
	gSystem->Load("/Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/build/lib/libNEMO3Ana.dylib");
	gROOT->ProcessLine(".x /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/PlotStyle.C+");
		
	TFile * f = new TFile("/Users/alberto/Software/SuperNEMO/work/nemo3/plot/plot_20150622/OneElectronHistos.root");
	
	TDirectory * d = (TDirectory *) f->Get("Data");
	
	TH1D * h_map   = (TH1D*) d->Get( "Data_h_vtx_z_vs_sect_all" );	
	TH1D * h_map_h = (TH1D*) d->Get( "Data_h_vtx_z_vs_sect_hot" );	
	TH1D * h_map_m = (TH1D*) d->Get( "Data_h_vtx_z_vs_sect_warm" );	
	TH1D * h_map_l = (TH1D*) d->Get( "Data_h_vtx_z_vs_sect_cold" );	

	TH1D * h   = new TH1D ("h"   , "Entire foil; N evt. / bin; " , 500, 0, 500);
	TH1D * h_h = new TH1D ("h_h" , "High activity region; N evt. / bin; " , 500, 0, 500);
	TH1D * h_m = new TH1D ("h_m" , "Medium activity region; N evt. / bin; " , 500, 0, 500);	
	TH1D * h_l = new TH1D ("h_l" , "Low activity region; N evt. / bin; " , 500, 0, 500);
	
	h  ->SetLineWidth(1);
	h_h->SetLineWidth(1);
	h_m->SetLineWidth(1);
	h_l->SetLineWidth(1);
	
	//h_h->SetFillColor(kRed);
	//h_m->SetFillColor(kGreen);
	//h_l->SetFillColor(kBlue);

	h_h->SetMarkerColor(kRed);
	h_m->SetMarkerColor(kGreen);
	h_l->SetMarkerColor(kBlue);
	
	h_h->SetLineColor(kRed);
	h_m->SetLineColor(kGreen);
	h_l->SetLineColor(kBlue);

	h->GetXaxis()->CenterTitle(kTRUE) ;
	h->GetXaxis()->SetTitleOffset(1.4);	
	
	for (int i = 0 ; i < h_map->GetNbinsX() ; i++ ){
		
		if( h_map->GetXaxis()->GetBinLowEdge(i) < 18.08 ) continue;
		
		for (int j = 0 ; j < h_map->GetNbinsY() ; j++ ){
					
			if( h_map->GetBinContent(i,j) != 0 ) h->Fill( h_map->GetBinContent(i,j) );
			
			if( h_map_h->GetBinContent(i,j) != 0 ) h_h->Fill(h_map->GetBinContent(i,j));
			if( h_map_m->GetBinContent(i,j) != 0 ) h_m->Fill(h_map->GetBinContent(i,j));
			if( h_map_l->GetBinContent(i,j) != 0 ) h_l->Fill(h_map->GetBinContent(i,j));

		}

	}
			
	TCanvas * c1 = new TCanvas();

	gPad->SetGridx(kFALSE);
	gPad->SetGridy(kFALSE);

    gPad->SetTickx() ;
    gPad->SetTicky() ;

    h->SetStats(kFALSE) ;
	
	h->Draw();
	h_h->Draw("SAME");
	h_l->Draw("SAME");
	h_m->Draw("SAME");
	
	c1->BuildLegend(0.5,0.8,0.8,0.5);

}