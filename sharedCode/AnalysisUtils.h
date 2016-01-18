//-----------------------------------------------------------------------------------------------
//
// #Name: AnalysisUtils.h
// #Description: This is the header file for the AnalysisUtils namespace. I am placing all the
//               functions that are not within a class, but are useful for a generic physics 
//               analysis in this namespace. The point here is to prevent name clashes in 
//               future analysis programs.
// 
// #Author: Joshua Loyal
// #Updated: 6/20/2011
// 
//-----------------------------------------------------------------------------------------------

// STL include(s)
#include "core/include/SCycleBase.h"
#include <vector>
#include <cmath>

// Root include(s)
#include "TLorentzVector.h"

// user defined classes

namespace AnalysisUtils {
  
   //------calculation functions-----//
  
   // adds two numbers in quadriture
   inline float aquad(float a, float b); 

   // finds the dR separation int eta-phi space of two particles  
   //-----transformation functions-----//
   void cmTransformation(std::vector<TLorentzVector*>::iterator fourvector, std::vector<TLorentzVector*>::iterator end4Vec, TLorentzVector &boostVector);
   void cmTransformation(TLorentzVector &particle, TLorentzVector &boostVector);
   void cmRotation(TLorentzVector &particle, TLorentzVector &boostVector);
   void cmBoost(TLorentzVector &particle, TLorentzVector &boostVector);
   int LeadingPtParticle(std::vector<TLorentzVector>);
   float MtMass(std::vector<TLorentzVector>,int);
   void SortParticlesPt(std::vector<int>&,std::vector<TLorentzVector>&);
   bool DrPassed(std::vector<TLorentzVector>,TLorentzVector,float);
}   
