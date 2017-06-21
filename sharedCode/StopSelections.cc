#include "StopSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"
#include "TVector3.h"

struct sortbypt{
  bool operator () (const pair<int, LorentzVector> &v1, const pair<int,LorentzVector> &v2)
  {
        return v1.second.pt() > v2.second.pt();
  }
};

vector<pair <int, LorentzVector> > sort_pt( vector<LorentzVector> p4_, float pt_){
  vector<pair <int, LorentzVector> > sorted_;
  for(unsigned int iObj=0; iObj<p4_.size(); iObj++){
   if(p4_.at(iObj).pt()<pt_) continue;
   sorted_.push_back(make_pair(iObj,p4_.at(iObj)));
  }
  sort(sorted_.begin(),sorted_.end(),sortbypt());
  return sorted_;
}

vector< LorentzVector> getsortedp4(vector<pair <int, LorentzVector> > index_){
  vector<LorentzVector> sorted_p4;
  for(unsigned int iObj=0; iObj<index_.size(); iObj++){
   sorted_p4.push_back(index_.at(iObj).second);
  }
  return sorted_p4;
}

float getMinDphi(float metPhi, LorentzVector& vec1, LorentzVector& vec2 ) {                                                                                                    
  float dphimj1_    = getdphi(metPhi, vec1.phi() );
  float dphimj2_    = getdphi(metPhi, vec2.phi() );
  float dphimjmin_  = TMath::Min( dphimj1_ , dphimj2_ );

  return dphimjmin_;

}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}
float getMT(TLorentzVector lep,TLorentzVector met){
  return sqrt(2*met.Et()*lep.Et()*(1-cos(getdphi(lep.Phi(),met.Phi()) ) ) );
}
float getMT(LorentzVector lep,LorentzVector met){
  return sqrt(2*met.Et()*lep.Et()*(1-cos(getdphi(lep.Phi(),met.Phi()) ) ) );
}

float calculateMt(const LorentzVector p4, double met, double met_phi){
  float phi1 = p4.Phi();
  float phi2 = met_phi;
  float Et1  = p4.Et();
  float Et2  = met;

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

float getdphi( float phi1 , float phi2 ){                                                                                                                                      
  float dphi = fabs( phi1 - phi2 );
  if( dphi > TMath::Pi() ) dphi = TMath::TwoPi() - dphi;
  return dphi;
}

float DPhi_W_lep(float MET, float MET_Phi, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(MET*cos(MET_Phi),MET*sin(MET_Phi),0);
  const TVector3 w = lep+met;
  double dphi = fabs(w.DeltaPhi(lep));
  return dphi;
}


bool CompareIndexValueGreatest(const std::pair<double, int>& firstElem, const std::pair<double, int>& secondElem) {
  return firstElem.first > secondElem.first;
}
bool CompareIndexValueSmallest(const std::pair<double, int>& firstElem, const std::pair<double, int>& secondElem) {
  return firstElem.first < secondElem.first;
}

void doubleSysError(TH2D* hist){
     for(int x=1; x<=(int)hist->GetNbinsX(); x++){
      for(int y=1; y<=(int)hist->GetNbinsY(); y++){
          hist->SetBinError(x,y,hist->GetBinError(x,y)*2.0);
      }
    }
return;
}

void setcounterLabel(TH1D* hist, string* labels) {
     hist->Sumw2();
     for(int x=1; x<=(int)hist->GetNbinsX(); x++){
         hist->GetXaxis()->SetBinLabel(x,labels[x].c_str());
     }
}
void setcounterLabel3D(TH3D* hist, string* labels) {
     hist->Sumw2();
     for(int x=1; x<=(int)hist->GetNbinsZ(); x++){
         hist->GetZaxis()->SetBinLabel(x,labels[x].c_str());
     }
}
vector<float> getupdownerr( TH2D* hist, float pt, float eta, float pt_cutoff, float pt_min,float eta_cutoff ,bool pteta){
     vector<float> updownerr;
     int binX, binY;
     if(pteta) {
       pt_min =  hist->GetXaxis()->GetBinLowEdge(1)+0.01;
       pt_cutoff =  hist->GetXaxis()->GetBinLowEdge(hist->GetNbinsX()+1)-0.01;
       float eta_min =  hist->GetYaxis()->GetBinLowEdge(1)+0.01;
       eta_cutoff =  hist->GetYaxis()->GetBinLowEdge(hist->GetNbinsY()+1)-0.01;
       binX = hist->GetXaxis()->FindBin( std::max( std::min(pt_cutoff,pt),pt_min ) );
       binY = hist->GetYaxis()->FindBin( std::max( std::min(eta_cutoff,eta),eta_min ) );
     }
     else{
       pt_min =  hist->GetYaxis()->GetBinLowEdge(1)+0.01;
       pt_cutoff =  hist->GetYaxis()->GetBinLowEdge(hist->GetNbinsY()+1)-0.01;
       binX = hist->GetXaxis()->FindBin( max(min(eta_cutoff,eta),-eta_cutoff));
       binY = hist->GetYaxis()->FindBin( max(min(pt_cutoff,pt),pt_min));
    }
     float lepSF    = hist->GetBinContent( binX, binY );
     float lepSF_Up = lepSF + hist->GetBinError( binX, binY );
     float lepSF_Dn = lepSF - hist->GetBinError( binX, binY );
     updownerr.push_back(lepSF);
     updownerr.push_back(lepSF_Up);
     updownerr.push_back(lepSF_Dn);
  return updownerr;
}
//helper function for DeltaR, using two phi's and eta's
  float DeltaR(float phi1, float phi2, float eta1, float eta2){
    // From cmssw reco::deltaPhi()
    float dphi = phi1 - phi2;
    while( dphi >   TMath::Pi() ) dphi -= TMath::TwoPi();
    while( dphi <= -TMath::Pi() ) dphi += TMath::TwoPi();
    return TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(eta1-eta2,2));
  }

  //helper function for DeltaR, using two Math::LorentzVector's
  float deltaR(LorentzVector jet1, LorentzVector jet2){
    // From cmssw reco::deltaPhi()
    float dphi = jet1.Phi() - jet2.Phi();
    while( dphi >   TMath::Pi() ) dphi -= TMath::TwoPi();
    while( dphi <= -TMath::Pi() ) dphi += TMath::TwoPi();
    return TMath::Sqrt(TMath::Power(dphi,2)+TMath::Power(jet1.Eta()-jet2.Eta(),2));
  }
  
