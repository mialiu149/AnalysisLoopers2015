#include "TFile.h"
#include "TH1F.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include "TString.h"

using namespace std;

void GetFuckingSyncTable(){

  const unsigned int processsetsize = 3;
  const unsigned int bgsetsize = 6;
  const unsigned int sigsetsize = 4;

  string bgname[bgsetsize]={"$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 2\\ell$","$\\mathrm{t}\\bar{\\mathrm{t}}\\rightarrow 1\\ell$", "single $t$","W$(\\ell\\nu)$+jets", "DY+jets", "Rare"};
  string signame[sigsetsize]={"$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (425,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (500,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (650,325)","$\\tilde{\\mathrm{t}}\\rightarrow\\mathrm{t}\\tilde{\\chi}_{1}^{0}$ (850,100)"};
  string processname[processsetsize]={"$\geq2\ell$", "$1\ell$", "Z$(\\nu\\nu)$"};
  
  string bgset[bgsetsize]={"TTbar2l","TTbar1l","SingleT","WJets","DYJets","Rare"};
  string sigset[sigsetsize]={"Stop_425_325","Stop_500_325","Stop_650_325","Stop_850_100"};
  string processset[processsetsize]={"2l","1l","Znunu"};
  
  TFile *fbg[bgsetsize];
  for(unsigned int n=0; n<bgsetsize; ++n) {
    string datasetstring = bgset[n];
    if(n==0) datasetstring = "TTbar";
    else if(n==1) continue;
    TString x = ("rootfiles/fuckingsync/Histos_"+datasetstring+".root");
    cout << x << endl;
      fbg[n] = TFile::Open(x);
      //  cout << fbg[n].IsZombie();
  }
  TFile *fsig[sigsetsize];
  for(unsigned int n=0; n<sigsetsize; ++n) {
   string datasetstring = sigset[n];
    TString x = ("rootfiles/fuckingsync/Histos_"+datasetstring+".root");
    cout << x << endl;
    fsig[n] = TFile::Open(x);
  }
  TFile *fprocess = TFile::Open("rootfiles/fuckingsync/Histos_processtype.root");
  

  vector<string> histonames;
  map<string, TH1F*> histos;

  histonames.push_back("MET_lowMT2W");
  histonames.push_back("MET_highMT2W");
  
  //CONTINUE HERE
  for(unsigned int i = 0; i<histonames.size();++i){
    for(unsigned int n=0; n<bgsetsize; ++n){
      int fileidentifier = n;
      if(n==1) fileidentifier = 0;//TTbar2l
      fbg[fileidentifier]->cd();
      string name = histonames[i]+"_"+bgset[n];
      histos[name] = (TH1F*)fbg[fileidentifier]->Get(name.c_str());
    }
    for(unsigned int n=0; n<sigsetsize; ++n){
      fsig[n]->cd();
      string name = histonames[i]+"_"+sigset[n];
      histos[name] = (TH1F*)fsig[n]->Get(name.c_str());
    }
    for(unsigned int n=0; n<processsetsize; ++n){
      fprocess->cd();
      string name = histonames[i]+"_"+processset[n];
      histos[name] = (TH1F*)fprocess->Get(name.c_str());
    }
  }
  for(map<string,TH1F*>::iterator h=histos.begin(); h!=histos.end();++h){
    for(unsigned int i = 0; i<h->second->GetNbinsX(); ++i){
      if(h->second->GetBinContent(i)<0){
	h->second->SetBinContent(i,0);
	h->second->SetBinError(i,0);
      }
    }
  }
  for(unsigned int i = 0; i<histonames.size();++i){
    for(unsigned int n=0; n<bgsetsize; ++n){
      string name = histonames[i]+"_"+bgset[n];
      string totname = histonames[i]+"_totalbg";
      if(n==0) {
	histos[totname] = (TH1F*)histos[name]->Clone(totname.c_str());
      } else {
	histos[totname]->Add(histos[name]);
      }
    }
  }
  std::ostringstream* fLogStream = new std::ostringstream();

  *fLogStream << "*********************************************************************" << endl;
  *fLogStream << "\%BEGINLATEX\%"             << endl;
  *fLogStream << "\\begin{table}"             << endl
	      << "\\begin{center}"            << endl
	      << "\\small"                    << endl;
  *fLogStream << "\\begin{tabular}{lccccc}"    << endl;	     
  *fLogStream << "\\hline"                    << endl;
  *fLogStream << " Sample & $250\\leq E_\\mathrm{T}^\\mathrm{miss} < 300$ GeV & $300\\leq E_\\mathrm{T}^\\mathrm{miss} < 350$ GeV & $350 \\leq E_\\mathrm{T}^\\mathrm{miss} < 400$ GeV & $E_\\mathrm{T}^\\mathrm{miss} \\geq 400$ GeV & \\\\" << endl;
  *fLogStream << "\\hline" << endl;
  *fLogStream << " & \\multicolumn{5}{|l|}{$M_\\mathrm{T2}^\\mathrm{W} \\leq 200$ GeV} & & & & \\\\" << endl;
  double error = 0;
  for(unsigned int n = 0; n<processsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_lowMT2W_"+processset[n] ]->Clone("h");
    *fLogStream << processname[n] << " & $" << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  }
  TH1F *hh = (TH1F*)histos["MET_lowMT2W_totalbg"]->Clone("hh");
  *fLogStream << "Total & $" << fixed << setprecision(2)
	      << hh->IntegralAndError(hh->FindBin(250.1),hh->FindBin(299.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(300.1),hh->FindBin(349.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(350.1),hh->FindBin(399.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(400.1),hh->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  for(unsigned int n = 0; n<sigsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_lowMT2W_"+sigset[n] ]->Clone("h");
    *fLogStream << signame[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  }
  *fLogStream << "\\hline" << endl;
  *fLogStream << " Sample & $250\\leq E_\\mathrm{T}^\\mathrm{miss} < 300$ GeV & $300\\leq E_\\mathrm{T}^\\mathrm{miss} < 350$ GeV & $350 \\leq E_\\mathrm{T}^\\mathrm{miss} < 400$ GeV & $400 \\leq E_\\mathrm{T}^\\mathrm{miss} < 500$ GeV & $E_\\mathrm{T}^\\mathrm{miss} \\geq 400$ GeV \\\\" << endl;
    *fLogStream << "\\hline" << endl;
  *fLogStream << " & \\multicolumn{5}{|l|}{$M_\\mathrm{T2}^\\mathrm{W} > 200$ GeV} & & & & \\\\" << endl;
  for(unsigned int n = 0; n<processsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_highMT2W_"+processset[n] ]->Clone("h");
    *fLogStream << processname[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(499.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(500.1),h->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  }
  hh = (TH1F*)histos["MET_highMT2W_totalbg"]->Clone("hh");
  *fLogStream << "Total & $" << fixed << setprecision(2)
	      << hh->IntegralAndError(hh->FindBin(250.1),hh->FindBin(299.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(300.1),hh->FindBin(349.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(350.1),hh->FindBin(399.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(400.1),hh->FindBin(499.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(500.1),hh->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  for(unsigned int n = 0; n<sigsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_highMT2W_"+sigset[n] ]->Clone("h");
    *fLogStream << signame[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(499.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(500.1),h->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  }
  *fLogStream << "\\hline\\hline" << endl
	      << "\\end{tabular}" << endl
	      << "\\end{center}"  << endl
	      << "\\end{table}"   << endl
	      << "\%ENDLATEX\%"   << endl
	      << endl;
      

  *fLogStream << "*********************************************************************" << endl;
  *fLogStream << "\%BEGINLATEX\%"             << endl;
  *fLogStream << "\\begin{table}"             << endl
	      << "\\begin{center}"            << endl
	      << "\\small"                    << endl;
  *fLogStream << "\\begin{tabular}{lccccc}"    << endl;	     
  *fLogStream << "\\hline"                    << endl;
  *fLogStream << " Sample & $250\\leq E_\\mathrm{T}^\\mathrm{miss} < 300$ GeV & $300\\leq E_\\mathrm{T}^\\mathrm{miss} < 350$ GeV & $350 \\leq E_\\mathrm{T}^\\mathrm{miss} < 400$ GeV & $E_\\mathrm{T}^\\mathrm{miss} \\geq 400$ GeV & \\\\" << endl;
  *fLogStream << "\\hline" << endl;
  *fLogStream << " & \\multicolumn{5}{|l|}{$M_\\mathrm{T2}^\\mathrm{W} \\leq 200$ GeV} & & & & \\\\" << endl;
  error = 0;
  for(unsigned int n = 0; n<bgsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_lowMT2W_"+bgset[n] ]->Clone("h");
    *fLogStream << bgname[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  }
  hh = (TH1F*)histos["MET_lowMT2W_totalbg"]->Clone("hh");
  *fLogStream << "Total & $" << fixed << setprecision(2)
	      << hh->IntegralAndError(hh->FindBin(250.1),hh->FindBin(299.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(300.1),hh->FindBin(349.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(350.1),hh->FindBin(399.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(400.1),hh->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  for(unsigned int n = 0; n<sigsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_lowMT2W_"+sigset[n] ]->Clone("h");
    *fLogStream << signame[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(749.9),error) << " \\pm " << error << "$ & "
		<< "\\\\" << endl;
  }
  *fLogStream << "\\hline" << endl;
  *fLogStream << " Sample & $250\\leq E_\\mathrm{T}^\\mathrm{miss} < 300$ GeV & $300\\leq E_\\mathrm{T}^\\mathrm{miss} < 350$ GeV & $350 \\leq E_\\mathrm{T}^\\mathrm{miss} < 400$ GeV & $400 \\leq E_\\mathrm{T}^\\mathrm{miss} < 500$ GeV & $E_\\mathrm{T}^\\mathrm{miss} \\geq 500$ GeV \\\\" << endl;
  *fLogStream << "\\hline" << endl;
  *fLogStream << " & \\multicolumn{5}{|l|}{$M_\\mathrm{T2}^\\mathrm{W} > 200$ GeV} & & & & \\\\" << endl;
  for(unsigned int n = 0; n<bgsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_highMT2W_"+bgset[n] ]->Clone("h");
    *fLogStream << bgname[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(499.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(500.1),h->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  }
  hh = (TH1F*)histos["MET_highMT2W_totalbg"]->Clone("hh");
  *fLogStream << "Total & $" << fixed << setprecision(2)
	      << hh->IntegralAndError(hh->FindBin(250.1),hh->FindBin(299.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(300.1),hh->FindBin(349.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(350.1),hh->FindBin(399.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(400.1),hh->FindBin(499.9),error) << " \\pm " << error << "$ & $"
	      << hh->IntegralAndError(hh->FindBin(500.1),hh->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  for(unsigned int n = 0; n<sigsetsize; ++n){
    TH1F *h = (TH1F*)histos["MET_highMT2W_"+sigset[n] ]->Clone("h");
    *fLogStream << signame[n] << " & $"  << fixed << setprecision(2)
		<< h->IntegralAndError(h->FindBin(250.1),h->FindBin(299.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(300.1),h->FindBin(349.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(350.1),h->FindBin(399.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(400.1),h->FindBin(499.9),error) << " \\pm " << error << "$ & $"
		<< h->IntegralAndError(h->FindBin(500.1),h->FindBin(749.9),error) << " \\pm " << error << "$ "
		<< "\\\\" << endl;
  }
  *fLogStream << "\\hline\\hline" << endl
	      << "\\end{tabular}" << endl
	      << "\\end{center}"  << endl
	      << "\\end{table}"   << endl
	      << "\%ENDLATEX\%"   << endl
	      << endl;
      
  cout << fLogStream->str();
}
