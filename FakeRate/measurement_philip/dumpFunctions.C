{

  for (int isMC=0;isMC<2;isMC++) {

    for (int doMu=0;doMu<2;doMu++) {

//      TString suffix = Form("_v%i",isMC);
      //TString suffix = "_20170911";
      TString suffix = isMC ? "_qcd":"";
      TString lep = doMu ? "muon" : "electron";
      TString l = doMu ? "muon" : "elec";
      TString ll = doMu ? "mu" : "el";

      //muon_fakerate_conecorrpt_v_eta_qcd
      //TFile* fmc = TFile::Open("rate_histos_qcd_"+ll+suffix+".root");
      TFile* fmc = TFile::Open("fakerate_pt_v_eta.root");

      //TH2D* mc = (TH2D*) fmc->Get("rate_histo_"+l);
      TH2D* mc = (TH2D*) fmc->Get(l+"_fakerate_conecorrpt_v_eta"+suffix);

      cout << "float "+lep+"FakeRate"+suffix+"_WWW"+"(float pt, float eta) {" << endl;
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

      cout << "float "+lep+"FakeRateError"+suffix+"_WWW"+"(float pt, float eta) {" << endl;
      for (int xbin=1;xbin<=mc->GetNbinsX();xbin++) {
	for (int ybin=1;ybin<=mc->GetNbinsY();ybin++) {
	  if (xbin!=mc->GetNbinsX()) { 
	    cout << "   if (pt>=" << mc->GetXaxis()->GetBinLowEdge(xbin) << " && pt<" << mc->GetXaxis()->GetBinUpEdge(xbin) 
		 << " && fabs(eta)>=" << mc->GetYaxis()->GetBinLowEdge(ybin) << " && fabs(eta)<" << mc->GetYaxis()->GetBinUpEdge(ybin) << " ) return " 
		 <<  mc->GetBinError(xbin,ybin) << ";" << endl;
	  } else {
	    cout << "   if (pt>=" << mc->GetXaxis()->GetBinLowEdge(xbin)
		 << " && fabs(eta)>=" << mc->GetYaxis()->GetBinLowEdge(ybin) << " && fabs(eta)<" << mc->GetYaxis()->GetBinUpEdge(ybin) << " ) return " 
		 <<  mc->GetBinError(xbin,ybin) << ";" << endl;      
	  }
	}
      }
      cout << "   return 0.;" << endl;
      cout << "}" << endl;

      fmc->Close();

    }
  }
cout<<"add functions in header file: ../../commonUtils/fake_rates_www_v1.h"<<endl;
}

