#include "StopSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"
#include "TMath.h"
//#include "CMS3.h"
//#include "ElectronSelections.h"
//#include "MuonSelections.h"
//#include "JetSelections.h"
//#include "VertexSelections.h"
//#include "IsoTrackVeto.h"
//#include "IsolationTools.h"
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

float getdphi( float phi1 , float phi2 ){                                                                                                                                      
  float dphi = fabs( phi1 - phi2 );
  if( dphi > TMath::Pi() ) dphi = TMath::TwoPi() - dphi;
  return dphi;
}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float calculateMt(const LorentzVector p4, double met, double met_phi){
  float phi1 = p4.Phi();
  float phi2 = met_phi;
  float Et1  = p4.Et();
  float Et2  = met;

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}

float DPhi_W_lep(float MET, float MET_Phi, LorentzVector p4){
  const TVector3 lep(p4.x(), p4.y(), p4.z());
  const TVector3 met(MET*cos(MET_Phi),MET*sin(MET_Phi),0);
  const TVector3 w = lep+met;
  double dphi = fabs(w.DeltaPhi(lep));
  return dphi;
}
