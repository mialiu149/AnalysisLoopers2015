{

  for (int doIso=0;doIso<1;doIso++) {

    for (int doMu=0;doMu<2;doMu++) {

      TString suffix = (doIso ? "_IsoTrigs" : "" );

      TString lep = doMu ? "muon" : "electron";
      TString l = doMu ? "mu" : "e";
      TString ll = doMu ? "mu" : "el";

      TFile* fmc = TFile::Open("rate_histos_qcd_"+ll+suffix+".root");

      TH2D* mc = (TH2D*) fmc->Get("rate_histo_"+l);

      cout << "float "+lep+"QCDMCFakeRate"+suffix+"WWW"+"(float pt, float eta) {" << endl;
      for (int xbin=1;xbin<=mc->GetNbinsX();xbin++) {
	for (int ybin=1;ybin<=mc->GetNbinsY();ybin++) {
	  if (xbin!=mc->GetNbinsX()) { 
	    cout << "   if (pt>=" << mc->GetXaxis()->GetBinLowEdge(xbin) << " && pt<" << mc->GetXaxis()->GetBinUpEdge(xbin) 
		 << " && fabs(eta)>=" << mc->GetYaxis()->GetBinLowEdge(ybin) << " && fabs(eta)<" << mc->GetYaxis()->GetBinUpEdge(ybin) << " ) return " 
		 <<  mc->GetBinContent(xbin,ybin) << ";" << endl;
	  } else {
	    cout << "   if (pt>=" << mc->GetXaxis()->GetBinLowEdge(xbin)
		 << " && fabs(eta)>=" << mc->GetYaxis()->GetBinLowEdge(ybin) << " && fabs(eta)<" << mc->GetYaxis()->GetBinUpEdge(ybin) << " ) return " 
		 <<  mc->GetBinContent(xbin,ybin) << ";" << endl;      
	  }
	}
      }
      cout << "   return 0.;" << endl;
      cout << "}" << endl;

      fmc->Close();

    }
  }
cout<<"add functions in header file: ../../commonUtils/fake_rates_www_v0.h"<<endl;
}
