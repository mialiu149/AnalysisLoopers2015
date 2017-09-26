//  .
// ..: P. Chang, philip@physics.ucsd.edu

// N.B.: I kept a very compact style in listing the functions in order to easily move around with {,} in vim.
//       Therefore, if one wants to add new feature please make the function extremely short as possible.
//       If the function is too long, maybe it doesn't belong here!

#ifndef tasutil_h
#define tasutil_h

// C/C++
#include <algorithm>
#include <map>
#include <vector>
#include <stdarg.h>
#include <functional>
#include <cmath>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TChainElement.h"
#include "TTreeCache.h"
#include "TStopwatch.h"
#include "TSystem.h"
#include "TLorentzVector.h"
#include "Math/LorentzVector.h"

#ifdef INCLUDE_CORE
// CORE tools
#include "CORE/CMS3.h"
#include "CORE/Base.h"
#include "CORE/TriggerSelections.h"
#include "CORE/ElectronSelections.h"
#include "CORE/MuonSelections.h"
#include "CORE/JetSelections.h"
#include "CORE/MetSelections.h"
#include "CORE/IsolationTools.h"
#include "CORE/Tools/goodrun.h"
#include "CORE/Tools/JetCorrector.h"
#include "CORE/Tools/jetcorr/FactorizedJetCorrector.h"
#include "CORE/Tools/jetcorr/JetCorrectionUncertainty.h"
using namespace tas;
#endif

///////////////////////////////////////////////////////////////////////////////////////////////
// LorentzVector typedef that we use very often
///////////////////////////////////////////////////////////////////////////////////////////////
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LV;
typedef std::vector<LV> LVs;
typedef std::vector<bool> bools;
typedef std::vector<int> ints;
typedef std::vector<float> floats;
typedef std::vector<double> doubles;

namespace TasUtil
{

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Printing functions
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // No namespace given in order to minimize typing
    // (e.g. TasUtil::print v. TasUtil::NAMESPACE::print)
    void print   (TString msg="", const char* fname="", int flush_before=0, int flush_after=0);
    void error   (TString msg, const char* fname="", int is_error=1);
    void warning (TString msg, const char* fname="");
    void announce(TString msg="", int quiet=0);
    void start   (int quiet=0, int sleep_time=0);
    void end     (int quiet=0);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Auto histogram maker
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // The concept is to keep the histogram at precision of 0.001.
    // So far in my experience of HEP, I never had to deal with precision more than 1/1000th
    // This means that if I keep every histogram at the precision of Range / N bin = 0.001,
    // I can always reproduce any other bin size histogram offline.
    // So, all I have to do is start with some small number of histograms binned in 0.001,
    // And slowly expand as the numbers come in.
    // For small range histograms (ip, or isolation), we can still create at 1/1000-th precision.
    // Then when the values that come in hits 50 or 100 (configurable), we blow it up.
    class AutoHist
    {

        public:
        int resolution;
        std::map<TString, TH1*> histdb;

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // Functions
        //////////////////////////////////////////////////////////////////////////////////////////////////

        AutoHist();
        ~AutoHist();
        // user interface
        void fill(double xval, TString name, double wgt=1);
        void fill(double xval, TString name, double wgt, int nbin, double xmin, double xmax);
        void fill(double xval, double yval, TString name, double wgt, int, double, double, int, double, double);
        void fill(double xval, TString name, double wgt, int nbin, double*);
        void fill(double xval, double yval, TString name, double wgt, int, double*, int, double*);
        void save(TString ofilename);
        // under the hood (but not private...)
        void fill(double xval, TH1*& h, double wgt=1, bool norebinning=false);
        TH1* hadd(TH1*, TH1*);
        TH1* get(TString);
        static int getRes(double range);
        static int getRes(TH1* h);
        static void transfer(TH1*, TH1*);
        static TH1* crop(TH1*, int, double, double);
        static TH1* createHist(double xval, TString name, double wgt=1, bool alreadyneg=false, int forceres=-1);
        static TH1* createFixedBinHist(double, TString, double, int, double, double);
        static TH1* createFixedBinHist(double, TString, double, int, double*);
        static TH1* createFixedBinHist(double, double, TString, double, int, double, double, int, double, double);
        static TH1* createFixedBinHist(double, double, TString, double, int, double*, int, double*);

    };

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Particle class
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // This class holds every information about a "particle".
    // The class has a generic data structure using std::map<TString, 'data'>.
    // User can use it for whatever reason.
    class Particle
    {

        public:
        enum VarType
        {
            kINT = 0,
            kFLT = 1,
            kTLV = 2,
            kSTR = 3,
            kNON = -1
        };

        typedef std::vector<TString> vecStr;
        typedef std::map<TString, VarType> mapTyp;
        typedef std::map<TString, float> mapFlt;
        typedef std::map<TString, int> mapInt;
        typedef std::map<TString, TLorentzVector> mapTLV;
        typedef std::map<TString, TString> mapStr;

        private:

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // Members
        //////////////////////////////////////////////////////////////////////////////////////////////////

        // Vector to hold the types
        vecStr var_Nam;
        mapStr var_Ttl;
        mapTyp var_Typ;
        mapFlt var_Flt;
        mapInt var_Int;
        mapTLV var_TLV;
        mapStr var_Str;

        public:

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // Functions
        //////////////////////////////////////////////////////////////////////////////////////////////////

        Particle();
        ~Particle();

        bool varExists(TString name);
        void createFltVar(TString name, TString title="");
        void createIntVar(TString name, TString title="");
        void createTLVVar(TString name, TString title="");
        void createStrVar(TString name, TString title="");

        static void printError             (TString name, TString msg, TString action, VarType type=kNON);
        static void printAlreadyExistsError(TString name, TString action, VarType type=kNON);
        static void printOutOfRangeError   (TString name, TString action, VarType type=kNON);

        void setFltVar(TString name, float          var);
        void setIntVar(TString name, int            var);
        void setStrVar(TString name, TString        var);
        void setTLVVar(TString name, TLorentzVector var);

        const float&          getFltVar(TString name) const;
        const int&            getIntVar(TString name) const;
        const TLorentzVector& getTLVVar(TString name) const;
        const TString&        getStrVar(TString name) const;

        VarType getType(TString name);

        void print();
        void printFltVar(TString name);
        void printIntVar(TString name);
        void printTLVVar(TString name);
        void printStrVar(TString name);

    };
    typedef std::vector<Particle> Particles;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Data extractor
    ///////////////////////////////////////////////////////////////////////////////////////////////
    Particles get(std::function<unsigned int()>, std::function<bool(int)>, std::function<Particle(int)>);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Math functions
    ///////////////////////////////////////////////////////////////////////////////////////////////
    namespace Math
    {
        // Short hand for float LorentzVector
        typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
        ///////////////////////////////////////////////////////////////////////////////////////////
        // TLorentzVector related operations
        ///////////////////////////////////////////////////////////////////////////////////////////
        // Create TLVs
        TLorentzVector TLV(LorentzVector);
        TLorentzVector TLVXYZE(float, float, float, float);
        TLorentzVector TLVPtEtaPhiM(float, float, float, float);
        TLorentzVector TLVPtEtaPhiE(float, float, float, float);
        TLorentzVector TLVMET(float, float);
        // The custom MT function, not from the TLorentzVector member function
        float MT  (TLorentzVector, TLorentzVector);
        // TLorentzVector
        float DEta(TLorentzVector a, TLorentzVector b);
        float DPhi(TLorentzVector a, TLorentzVector b);
        float DR  (TLorentzVector a, TLorentzVector b);
        float DPt (TLorentzVector a, TLorentzVector b);
        float Mass(TLorentzVector a, TLorentzVector b);
        float Pt  (TLorentzVector a, TLorentzVector b);
        float MT  (TLorentzVector p4  , float met, float met_phi);
        ///////////////////////////////////////////////////////////////////////////////////////////
        // LorentzVector related operations
        ///////////////////////////////////////////////////////////////////////////////////////////
        // Creating LorentzVector
        LorentzVector LV(TLorentzVector);
        LorentzVector LVXYZE(float, float, float, float);
        LorentzVector METLV(float, float);
        // LorentzVector
        float DEta(LorentzVector a, float         b);
        float DPhi(LorentzVector a, float         b);
        float DEta(LorentzVector a, LorentzVector b);
        float DPhi(LorentzVector a, LorentzVector b);
        float DR  (LorentzVector a, LorentzVector b);
        float DPt (LorentzVector a, LorentzVector b);
        float Mass(LorentzVector a, LorentzVector b);
        float Pt  (LorentzVector a, LorentzVector b);
        float MT  (LorentzVector a, LorentzVector b);
        float MT  (LorentzVector a, float met, float met_phi);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Looper class
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // NOTE: This class assumes accessing TTree in the SNT style which uses the following,
    // https://github.com/cmstas/Software/blob/master/makeCMS3ClassFiles/makeCMS3ClassFiles.C
    // It is assumed that the "template" class passed to this class will have
    // 1. "Init(TTree*)"
    // 2. "GetEntry(uint)"
    // 3. "progress(nevtProc'ed, total)"
    template <class TREECLASS>
    class Looper
    {
        public:
        // Members
        TChain* tchain;
        TObjArray *listOfFiles;
        TObjArrayIter* fileIter;
        TFile* tfile;
        TTree* ttree;
        unsigned int nEventsTotalInChain;
        unsigned int nEventsTotalInTree;
        int nEventsToProcess;
        unsigned int nEventsProcessed;
        unsigned int indexOfEventInTTree;
        bool fastmode;
        TREECLASS* treeclass;
        TStopwatch my_timer;
        int bar_id;
        int print_rate;
        // Functions
        Looper(TChain* chain=0, TREECLASS* treeclass=0, int nEventsToProcess=-1);
        ~Looper();
        void setTChain(TChain* c);
        void setTreeClass(TREECLASS* t);
        void printCurrentEventIndex();
        bool allEventsInTreeProcessed();
        bool allEventsInChainProcessed();
        bool nextEvent();
        TTree* getTree() { return ttree; }
        unsigned int getNEventsProcessed() { return nEventsProcessed; }
        private:
        void setFileList();
        void setNEventsToProcess();
        bool nextTree();
        bool nextEventInTree();
        void initProgressBar();
        void printProgressBar();
    };

    class TTreeX : public TTree
    {

        public:
        enum kType
        {
            kInt_t      =  1,
            kBool_t     =  2,
            kFloat_t    =  3,
            kLV         =  4,
            kVecInt_t   = 11,
            kVecBool_t  = 12,
            kVecFloat_t = 13,
            kVecLV      = 14
        };
        typedef vector<LV>::const_iterator lviter;

        private:
        std::map<TString, Int_t  > mapInt_t;
        std::map<TString, Bool_t > mapBool_t;
        std::map<TString, Float_t> mapFloat_t;
        std::map<TString, LV     > mapLV;
        std::map<TString, std::vector<Int_t  > > mapVecInt_t;
        std::map<TString, std::vector<Bool_t > > mapVecBool_t;
        std::map<TString, std::vector<Float_t> > mapVecFloat_t;
        std::map<TString, std::vector<LV     > > mapVecLV;

        public:
        TTreeX(TString treename, TString title);
        ~TTreeX();
        void* getValPtr(TString brname);
        template <class T>
        T* get(TString brname, int entry=-1);

        template <class T>
        void createBranch(TString);
        template <class T>
        void setBranch(TString, T);
        template <class T>
        void pushbackToBranch(TString, T);

        void sortVecBranchesByPt(TString, std::vector<TString>, std::vector<TString>, std::vector<TString>);
        template <class T>
        std::vector<T> sortFromRef( std::vector<T> const& in, std::vector<std::pair<size_t, lviter> > const& reference);
        struct ordering
        {
            bool operator ()(std::pair<size_t, lviter> const& a, std::pair<size_t, lviter> const& b) 
            {
                return (*(a.second)).pt() > (*(b.second)).pt();
            }
        };

        void clear();
    };

    //_________________________________________________________________________________________________
    template <> void TTreeX::setBranch<Int_t               >(TString bn, Int_t                val) { mapInt_t     [bn] = val; }
    template <> void TTreeX::setBranch<Bool_t              >(TString bn, Bool_t               val) { mapBool_t    [bn] = val; }
    template <> void TTreeX::setBranch<Float_t             >(TString bn, Float_t              val) { mapFloat_t   [bn] = val; }
    template <> void TTreeX::setBranch<LV                  >(TString bn, LV                   val) { mapLV        [bn] = val; }
    template <> void TTreeX::setBranch<std::vector<Int_t  >>(TString bn, std::vector<Int_t  > val) { mapVecInt_t  [bn] = val; }
    template <> void TTreeX::setBranch<std::vector<Bool_t >>(TString bn, std::vector<Bool_t > val) { mapVecBool_t [bn] = val; }
    template <> void TTreeX::setBranch<std::vector<Float_t>>(TString bn, std::vector<Float_t> val) { mapVecFloat_t[bn] = val; }
    template <> void TTreeX::setBranch<std::vector<LV     >>(TString bn, std::vector<LV     > val) { mapVecLV     [bn] = val; }
    template <> void TTreeX::pushbackToBranch<Int_t        >(TString bn, Int_t       val) { mapVecInt_t  [bn].push_back(val); }
    template <> void TTreeX::pushbackToBranch<Bool_t       >(TString bn, Bool_t      val) { mapVecBool_t [bn].push_back(val); }
    template <> void TTreeX::pushbackToBranch<Float_t      >(TString bn, Float_t     val) { mapVecFloat_t[bn].push_back(val); }
    template <> void TTreeX::pushbackToBranch<LV           >(TString bn, LV          val) { mapVecLV     [bn].push_back(val); }

    //_________________________________________________________________________________________________
    template <> void TTreeX::createBranch<Int_t               >(TString bn) { Branch(bn, &(mapInt_t      [bn])); }
    template <> void TTreeX::createBranch<Bool_t              >(TString bn) { Branch(bn, &(mapBool_t     [bn])); }
    template <> void TTreeX::createBranch<Float_t             >(TString bn) { Branch(bn, &(mapFloat_t    [bn])); }
    template <> void TTreeX::createBranch<LV                  >(TString bn) { Branch(bn, &(mapLV         [bn])); }
    template <> void TTreeX::createBranch<std::vector<Int_t  >>(TString bn) { Branch(bn, &(mapVecInt_t   [bn])); }
    template <> void TTreeX::createBranch<std::vector<Bool_t >>(TString bn) { Branch(bn, &(mapVecBool_t  [bn])); }
    template <> void TTreeX::createBranch<std::vector<Float_t>>(TString bn) { Branch(bn, &(mapVecFloat_t [bn])); }
    template <> void TTreeX::createBranch<std::vector<LV     >>(TString bn) { Branch(bn, &(mapVecLV      [bn])); }
    template <class T>
    std::vector<T> TTreeX::sortFromRef( std::vector<T> const& in, std::vector<std::pair<size_t, TTreeX::lviter> > const& reference)
    {
        std::vector<T> ret(in.size());

        size_t const size = in.size();
        for (size_t i = 0; i < size; ++i)
            ret[i] = in[reference[i].first];

        return ret;
    }

#ifdef INCLUDE_CORE
    class CORE2016
    {

        public:
        CORE2016();
        ~CORE2016();

        TString option;

        // stores current corrections for a given event
        FactorizedJetCorrector   * jet_corrector_pfL1FastJetL2L3_current;
        JetCorrectionUncertainty * jecUnc_current;

        // default corrections
        std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
        FactorizedJetCorrector   * jet_corrector_pfL1FastJetL2L3;
        JetCorrectionUncertainty * jecUnc;

        // corrections for later runs in 2016F
        std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3_postrun278802;
        FactorizedJetCorrector   * jet_corrector_pfL1FastJetL2L3_postrun278802;
        JetCorrectionUncertainty * jecUnc_postrun278802;

        // lepton ids
        std::vector<std::pair<id_level_t, TString>> lepton_ids;

        void initializeCORE(TString option);
        static int getCMS3Version();
        void setJetCorrector();
        void createEventBranches(TTreeX* ttree);
        void setEventBranches(TTreeX* ttree);
        void createPileUpBranches(TTreeX* ttree);
        void setPileUpBranches(TTreeX* ttree);
        void createMETBranches(TTreeX* ttree);
        void setMETBranches(TTreeX* ttree);
        void createLeptonBranches(TTreeX* ttree, std::vector<std::pair<id_level_t, TString>>);
        void setLeptonBranches(TTreeX* ttree);
        void setElectronBranches(TTreeX* ttree);
        void setMuonBranches(TTreeX* ttree);
        void createJetBranches(TTreeX* ttree);
        void setJetBranches(TTreeX* ttree);
    };

#endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Event Looper (Looper) class template implementation
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

// It's easier to put the implementation in the header file to avoid compilation issues.

//_________________________________________________________________________________________________
template <class TREECLASS>
TasUtil::Looper<TREECLASS>::Looper(TChain* c, TREECLASS* t, int nevtToProc) :
    tchain(0),
    listOfFiles(0),
    fileIter(0),
    tfile(0),
    ttree(0),
    nEventsTotalInChain(0),
    nEventsTotalInTree(0),
    nEventsToProcess(nevtToProc),
    nEventsProcessed(0),
    indexOfEventInTTree(0),
    fastmode(false),
    treeclass(0),
    bar_id(0),
    print_rate(432)
{
    initProgressBar();
    print("Start EventLooping");
    start();
    if (c) setTChain(c);
    if (t) setTreeClass(t);
    if (nevtToProc > 5000)
        fastmode = true;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
TasUtil::Looper<TREECLASS>::~Looper()
{
    print("Finished EventLooping");
    end();
    if (fileIter) delete fileIter;
    if (tfile) delete tfile;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::setTChain(TChain* c)
{
    if (c)
    {
        tchain = c;
        setNEventsToProcess();
        setFileList();
    }
    else
    {
        error("You provided a null TChain pointer!", __FUNCTION__);
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::setTreeClass(TREECLASS* t)
{
    if (t)
    {
        treeclass = t;
    }
    else
    {
        error("You provided a null TreeClass pointer!", __FUNCTION__);
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::printCurrentEventIndex()
{
    TasUtil::print(TString::Format("Current TFile = %s", tfile->GetName()));
    TasUtil::print(TString::Format("Current TTree = %s", ttree->GetName()));
    TasUtil::print(TString::Format("Current Entry # in TTree = %d", indexOfEventInTTree));
}

//_________________________________________________________________________________________________
template <class TREECLASS>
bool TasUtil::Looper<TREECLASS>::nextTree()
{
    if (!fileIter)
        error("fileIter not set but you are trying to access the next file", __FUNCTION__);
    // Get the TChainElement from TObjArrayIter.
    // If no more to run over, Next returns 0.
    TChainElement* chainelement = (TChainElement*) fileIter->Next();
    if (chainelement)
    {
        // If there is already a TFile opened from previous iteration, close it.
        if (tfile) tfile->Close();
        // Open up a new file
        //tfile = new TFile(chainelement->GetTitle());
        tfile = TFile::Open(chainelement->GetTitle());
        // Get the ttree
        ttree = (TTree*) tfile->Get(tchain->GetName());
        if (!ttree)
            error("TTree is null!??", __FUNCTION__);
        // Set some fast mode stuff
        if (fastmode) TTreeCache::SetLearnEntries(10);
        if (fastmode) ttree->SetCacheSize(128*1024*1024);
        // Print some info to stdout
        announce("Working on " +
                 TString(tfile->GetName()) +
                 "/TTree:" +
                 TString(ttree->GetName()));
        // Reset the nEventsTotalInTree in this tree
        nEventsTotalInTree = ttree->GetEntries();
        // Reset the event index as we got a new ttree
        indexOfEventInTTree = 0;
        // Set the ttree to the TREECLASS
        treeclass->Init(ttree);
        // Return that I got a good one
        return true;
    }
    else
    {
        // Announce that we are done with this chain
        print("Done with all trees in this chain", __FUNCTION__);
        return false;
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
bool TasUtil::Looper<TREECLASS>::allEventsInTreeProcessed()
{
    if (indexOfEventInTTree >= nEventsTotalInTree) return true;
    else return false;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
bool TasUtil::Looper<TREECLASS>::allEventsInChainProcessed()
{
    if (nEventsProcessed > (unsigned int) nEventsToProcess) return true;
    else return false;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
bool TasUtil::Looper<TREECLASS>::nextEventInTree()
{
//    treeclass->progress(nEventsProcessed, nEventsToProcess);
    // Sanity check before loading the next event.
    if (!ttree) error("current ttree not set!", __FUNCTION__);
    if (!tfile) error("current tfile not set!", __FUNCTION__);
    if (!fileIter) error("fileIter not set!", __FUNCTION__);
    // Increment the counter for this ttree
    ++indexOfEventInTTree;
    // Increment the counter for the entire tchain
    ++nEventsProcessed;
    // If all fine return true
    // Check whether I processed everything
    if (allEventsInTreeProcessed()) return false;
    if (allEventsInChainProcessed()) return false;
    // if fast mode do some extra
    if (fastmode) ttree->LoadTree(indexOfEventInTTree);
    // Set the event index in TREECLASS
    treeclass->GetEntry(indexOfEventInTTree);
    // Print progress
//    printProgressBar();
    return true;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
bool TasUtil::Looper<TREECLASS>::nextEvent()
{
    // If no tree it means this is the beginning of the loop.
    if (!ttree)
    {
        // Load the next tree if it returns true, then proceed to next event in tree.
        while (nextTree())
        {
            // If the next event in tree was successfully loaded return true, that it's good.
            if (nextEventInTree())
                return true;
            // If the first event in this tree was not good, continue to the next tree
            else
                continue;
        }
        // If looping over all trees, we fail to find first event that's good,
        // return false and call it quits.
        // At this point it will exit the loop without processing any events.
        return false;
    }
    // If tree exists, it means that we're in the middle of a loop
    else
    {
        // If next event is successfully loaded proceed.
        if (nextEventInTree())
        {
            return true;
        }
        // If next event is not loaded then check why.
        else
        {
            // If failed because it was the last event in the whole chain to process, exit the loop.
            // You're done!
            if (allEventsInChainProcessed())
            {
                return false;
            }
            // If failed because it's last in the tree then load the next tree and the event
            else if (allEventsInTreeProcessed())
            {
                // Load the next tree if it returns true, then proceed to next event in tree.
                while (nextTree())
                {
                    // If the next event in tree was successfully loaded return true, that it's good.
                    if (nextEventInTree())
                        return true;
                    // If the first event in this tree was not good, continue to the next tree
                    else
                        continue;
                }
                // If looping over all trees, we fail to find first event that's good,
                // return false and call it quits.
                // Again you're done!
                return false;
            }
            else
            {
                // Why are you even here?
                // spit error and return false to avoid warnings
                error("You should not be here! Please contact philip@physics.ucsd.edu", __FUNCTION__);
                return false;
            }
        }
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::setFileList()
{
    if (!fileIter)
    {
        listOfFiles = tchain->GetListOfFiles();
        fileIter = new TObjArrayIter(listOfFiles);
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::setNEventsToProcess()
{
    if (tchain)
    {
        nEventsTotalInChain = tchain->GetEntries();
        if (nEventsToProcess < 0)
            nEventsToProcess = nEventsTotalInChain;
    }
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::initProgressBar()
{
    /// Init progress bar
    my_timer.Start();
    bar_id = 0;
}

//_________________________________________________________________________________________________
template <class TREECLASS>
void TasUtil::Looper<TREECLASS>::printProgressBar()
{
    /// Print progress bar

    int entry = nEventsProcessed;
    int totalN = nEventsToProcess;

    if (totalN < 20)
        totalN = 20;

    // Progress bar
    if (entry > totalN)
    {
        printf("Why are you here?\n");
    }
    else if (entry == totalN)
    {
        Double_t elapsed = my_timer.RealTime();
        Double_t rate;
        if (elapsed!=0)
            rate = entry / elapsed;
        else
            rate = -999;
        const int mins_in_hour = 60;
        const int secs_to_min = 60;
        Int_t input_seconds = elapsed;
        Int_t seconds = input_seconds % secs_to_min;
        Int_t minutes = input_seconds / secs_to_min % mins_in_hour;
        Int_t hours   = input_seconds / secs_to_min / mins_in_hour;

        printf("\rTasUtil::");
        printf("+");
        printf("|====================");

        //for ( int nb = 0; nb < 20; ++nb )
        //{
        //  printf("=");
        //}

        printf("| %.1f %% (%d/%d) with  [avg. %d Hz]   Total Time: %.2d:%.2d:%.2d         \r", 100.0, entry, totalN, (int)rate, hours, minutes, seconds);
        fflush(stdout);
        printf("\n");
    }
    else if (entry%(5*((int)print_rate)) < 100)
    {

        // sanity check
        if (entry >= totalN+10) // +2 instead of +1 since, the loop might be a while loop where to check I got a bad event the index may go over 1.
        {
            TString msg = TString::Format("%d %d", entry, totalN);
            TasUtil::print(msg, __FUNCTION__);
            TasUtil::error("Total number of events processed went over max allowed! Check your loop boundary conditions!!", __FUNCTION__);
        }

        int nbars = entry/(totalN/20);
        Double_t elapsed = my_timer.RealTime();
        Double_t rate;
        if (elapsed!=0)
            rate = entry / elapsed;
        else
            rate = -999;
        Double_t percentage = entry / (totalN * 1.) * 100;
        const int mins_in_hour = 60;
        const int secs_to_min = 60;
        Int_t input_seconds = (totalN-entry)/rate;
        Int_t seconds = input_seconds % secs_to_min;
        Int_t minutes = input_seconds / secs_to_min % mins_in_hour;
        Int_t hours   = input_seconds / secs_to_min / mins_in_hour;

        print_rate = (int)(rate) + 1;

        printf("\rTasUtil:: ");
        if (bar_id%4 == 3) printf("-");
        if (bar_id%4 == 2) printf("/");
        if (bar_id%4 == 1) printf("|");
        if (bar_id%4 == 0) printf("\\");
        printf("|");
        bar_id ++;

        for (int nb = 0; nb < 20; ++nb)
        {
            if (nb < nbars) printf("=");
            else printf(".");
        }

        printf("| %.1f %% (%d/%d) with  [%d Hz]   ETA %.2d:%.2d:%.2d         ", percentage, entry+1, totalN, (int)rate, hours, minutes, seconds);
        fflush(stdout);

    }

    my_timer.Start(kFALSE);
}

//_________________________________________________________________________________________________
template <class T>
T* TasUtil::TTreeX::get(TString brname, int entry)
{
    if (entry >= 0)
        GetEntry(entry);
    return (T*) getValPtr(brname);
}

#endif
