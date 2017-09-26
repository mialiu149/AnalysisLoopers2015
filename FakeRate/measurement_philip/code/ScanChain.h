// ROOT
#include "Math/VectorUtil.h"

// SNT
#define INCLUDE_CORE
#include "tasutil.cc"
#include "LeptonTree.cc"
#include "pu_weights.h"
#include "../CORE/Tools/dorky/dorky.cc"

using namespace std;
using namespace LeptonTreeNameSpace;

struct Lepton
{
    int evt_event;
    int evt_lumiBlock;
    int evt_run;
    int nvtx;
    float instantLumi;
    LV p4;
    int id;
    int nFOs_VVV;
    int njets40;
    int njets40_up;
    int njets40_dn;
    int prescale;
    bool pass_trig;
    float weight;
    float iso;
    std::vector<float> wgt_syst;
    float evt_met;
    float evt_metPhi;
    float evt_met_up;
    float evt_metPhi_up;
    float evt_met_dn;
    float evt_metPhi_dn;
    float evt_mt;
    float evt_mt_up;
    float evt_mt_dn;
    bool passId;
    bool passFO;
    float coneptcorr;
    bool pass_e8i;
    bool pass_m8i;
    bool pass_e17i;
    bool pass_m17i;
    int motherID;
    bool isEWK;
    bool isData;
    bool isDoubleMuon;

    void print()
    {
        std::cout << "evt_event;  " << evt_event  << std::endl;
        std::cout << "p4.pt();    " << p4.pt()    << std::endl;
        std::cout << "p4.eta();   " << p4.eta()   << std::endl;
        std::cout << "id;         " << id         << std::endl;
        std::cout << "nFOs_VVV;   " << nFOs_VVV   << std::endl;
        std::cout << "njets40;    " << njets40    << std::endl;
        std::cout << "prescale;   " << prescale   << std::endl;
        std::cout << "pass_trig;  " << pass_trig  << std::endl;
        std::cout << "weight;     " << weight     << std::endl;
        std::cout << "evt_met;    " << evt_met    << std::endl;
        std::cout << "evt_metPhi; " << evt_metPhi << std::endl;
        std::cout << "evt_mt;     " << evt_mt     << std::endl;
        std::cout << "passId;     " << passId     << std::endl;
        std::cout << "passFO;     " << passFO     << std::endl;
        std::cout << "coneptcorr; " << coneptcorr << std::endl;
    }
};

float computePtRel( LorentzVector lepp4, LorentzVector jetp4, bool subtractLep );
double calculateMt( const LorentzVector p4, double met, double met_phi );
float getPt( float pt, bool extrPtRel = false );
float getEta( float eta, float ht, bool extrPtRel = false );
bool passIsolatedFO( int id, float eta, float disc, float pt );
float mvacut( float A, float B, float C, float pt_ );
void fill( TasUtil::AutoHist& hists, TString suffix, float& evt_mt, float& evt_met, float& weight);
void fillFakeRateHistograms( TasUtil::AutoHist& hists, TString label, float& evt_met, float& evt_mt, float& weight );
void fillEventLevelHistograms( std::vector<Lepton>& leptons, TasUtil::AutoHist& hists );
void fillEventLevelHistogramsSyst( std::vector<Lepton> leptons, TasUtil::AutoHist& hists, int njets, float evt_met, float evt_metPhi, float evt_mt, int iwgt, TString);

double nvtxRewgtMu( Lepton& );
double nvtxRewgtEl( Lepton& );
double nvtxRewgt( int nvtx );
