//-----------------------------------------------------------------------------------------------
//
// #Name: AnalysisUtils.cxx
// #Description: The source file for the AnalysisUtils namespace.
//
// #Updated: 6/20/2011
//
//-----------------------------------------------------------------------------------------------
#include "AnalysisUtils.h"

// STL include(s)
#include <iostream>

// Root include(s)
#include "TVector3.h"
#include "TRotation.h"
#include "TLorentzRotation.h"
#include <math.h>
// class include(s)

namespace AnalysisUtils {
float Zbi(float sig, float bg, float bgrelunc=0.3){
     double bgunc = bgrelunc*bg;
     double tau = bg/pow(bgunc,2);//bgunc is absolute
     double n_on = sig+bg;//total yield in SR = sig + bg
     double n_off = tau*bg;
     double P_Bi = TMath::BetaIncomplete(1./(1.+tau),n_on,n_off+1);
     double Z_Bi = sqrt(2.)*TMath::ErfInverse(1.-2.*P_Bi);
     return Z_Bi;
}
    
    //------dR functions-----//

    float aquad(float a, float b) 
    {
        return sqrt( a*a + b*b );
    }
    // overloaded dR functions
    //-----coordinate transformation functions-----//

    void cmTransformation(std::vector<TLorentzVector*>::iterator fourvector, std::vector<TLorentzVector*>::iterator end4Vec, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TLorentzRotation L;
        TVector3 xAxis(1,0,0);
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation.

        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        L.Boost(0, 0, beta);      // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                     // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        
        //Loop over the vector containing the 4vectors
        for( /*initialized in the function*/ ; fourvector != end4Vec; ++fourvector) { 
            // (L*R*fourvector)
            (*fourvector)->Transform(R);     // apply the rotation.
            (*fourvector)->Transform(L);     // apply the boost 
        }
        return;    
    }

    void cmTransformation(TLorentzVector &particle, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TLorentzRotation L;
        TVector3 xAxis(1,0,0);
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation.

        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        L.Boost(0, 0, beta);      // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                     // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        // (L*R*particle)
        particle.Transform(R);  // apply the rotation
        particle.Transform(L);  // apply the boost
        return;    
    }

    void cmRotation(TLorentzVector &particle, TLorentzVector &boost4Vector) {
        //------calculate the rotation matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // note: The TRotation class describes so called active rotations, i.e. rotations of objects inside a static system of coordinates.
        //       In the case you want to rotate the frame and want to know the coordiantes of objects in the rotated coordinate system then
        //       you should apply the inverse rotation to the objects.
        //----------------------------------------------------------------------------------------------------------------------------------

        // variable initialization
        TRotation R;
        TVector3 xAxis(1,0,0);
        //Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        TVector3 boostVector = boost4Vector.Vect(); // the z-axis is in the direction of the vector component of the boost (p = gmv).

        // calculate the axes of the new coordinate system
        
        TVector3 newZ = boostVector.Unit();                // z-axis points along the direction of motion of the cm particle
        TVector3 newY = (boostVector.Cross(xAxis)).Unit(); // y-axis perpendicular to the z-axis (now we have a plane)
        TVector3 newX = (newY.Cross(newZ)).Unit();  // x-axis is perpendicular to the plane defined above (newY and newZ already unit vectors).
        
        // calculate the rotation matrix
        //
        //-----------------------------------------------------------------------------------------------------------------------------------
        // TRotation::RotateAxes()
        // note: Suppose there is a 3D object and its local axes a(1,0,0), b(0,1,0), c(0,0,1) originally coincide with the global axes.
        //       If it is known the position of local axes a'(ax',ay',az'), b'(bx',by',bz'), c'(cx',cy',cz') after the rotation then matrix
        //       which describes the rotation looks as follows:
        //       R = [ax' bx' cx']
        //           |ay' by' cy'|
        //           [az' bz' cz']
        //----------------------------------------------------------------------------------------------------------------------------------

        R.RotateAxes(newX, newY, newZ);
        R.Invert();                     // as mentioned above, we need the inverse rotation. 
        
        //------apply the transformation to the cm frame-------//
        // (R*particle)
        particle.Transform(R);  // apply the rotation

        return;
    }

    void cmBoost(TLorentzVector &particle, TLorentzVector &boost4Vector) { 
        //------calculate the Lorentz Transformation Matrix------//
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation:
        // note: The matrix described by this object is the following:
        //       Lambda = [xx xy xz xt]
        //                |yx yy yz yt|
        //                |zx zy zz zt|
        //                [tx ty tz tt].
        //       Recall that Root uses the weird convention for four vectors: a = (ax, ay, az, at).
        //----------------------------------------------------------------------------------------------------------------------------------
        //
        //----------------------------------------------------------------------------------------------------------------------------------
        // TLorentzRotation::boost():
        // note: the matrix that results from an arbitrary boost b = (bx, by, bz) is as follows:
        //       Boost  = [1+g'bx^2     g'bxby      g'bxbz      gbx]
        //                |g'bybz       1+g'by^2    g'bybz      gby|
        //                |g'bzbx       g'bzby      1+g'bz^2    gbz|
        //                [gbx          gby         gbz         g  ].
        //      where g' = (g-1)/b^2.
        //
        //       We need the inverse matrix, which for an arbitrary Lorentz Transformation is given by the following:
        //       Lambda^-1 = [xx  xy  xz -tx]
        //                   |yx  yy  yz -ty|
        //                   |zx  zy  zz -tz|
        //                   [-xt -yt -zt tt].
        //-----------------------------------------------------------------------------------------------------------------------------------

        TLorentzRotation L;
        Double_t beta = boost4Vector.Beta();        // get the magnitude of beta from our boosting 4vector
        L.Boost(0, 0, beta);                        // since we have already performed the rotation, we only need to boost along the desired direction
        L.Invert();                                 // as mentioned above, we need the inverse rotation.

        //------apply the transformation to the cm frame-------//
        // (L*particle)
        particle.Transform(L);  // apply the boost
    
        return; 
    }
    int LeadingPtParticle(std::vector<TLorentzVector> particles)
{
  std::vector<int> indices;
  std::vector<float> selectedpts;
  indices.push_back(-1);
  selectedpts.push_back(-1);
  for(unsigned int i =0;i<particles.size();i++)
{
   if(particles.at(i).Pt()>selectedpts.back()) 
  {
   indices.push_back(i);
   selectedpts.push_back(particles.at(i).Pt());
  }
}
   int leading = indices.back();
   return leading;
}
   float MtMass(std::vector<TLorentzVector> objects,unsigned int size)
{
float Mt2_x = 0;
float Mt2_y = 0;
float Mt2_Et = 0;
if(size>objects.size()) std::cout<<"WARNING::"<<"need more input particles for calculation!!"<<std::endl;
for(unsigned int i  = 0;i<size;i++){
TLorentzVector tmp = objects.at(i);
float px = tmp.Px();
float py = tmp.Py();
float Et = sqrt(px*px+py*py);
Mt2_x = Mt2_x + px;
Mt2_y = Mt2_y + py;
Mt2_Et = Mt2_Et + Et;
}
float Mt = sqrt(Mt2_Et*Mt2_Et-Mt2_x*Mt2_x-Mt2_y*Mt2_y);
return Mt;
}

void SortParticlesPt(std::vector<int>& particleindex ,std::vector<TLorentzVector>& particles)
{
std::vector<TLorentzVector> newparticles;
std::vector<int> oldindex;

while(particles.size()>0)
{
int leading=LeadingPtParticle(particles);
newparticles.push_back(particles.at(leading));
oldindex.push_back(particleindex.at(leading));

particles.erase(particles.begin()+leading);
particleindex.erase(particleindex.begin()+leading);
}

for(unsigned int i=0;i<newparticles.size();i++)
{
particles.push_back(newparticles.at(i));
particleindex.push_back(oldindex.at(i));
}
return;
}

bool DrPassed(std::vector<TLorentzVector> SelectedLep, TLorentzVector tmp, float dRcut){
	for(unsigned int i = 0; i <SelectedLep.size(); i++){
		float dr1 = SelectedLep[i].DeltaR(tmp);
		if(dr1 <= dRcut) return false;
	}
return true;
}

}
