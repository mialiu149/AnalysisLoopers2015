#include "TH2F.h"

void makeHistInclusive( TH2F * h_exclusive, TH2F * &h_inclusive, bool inclusivenjets, bool inclusiveht );

void makeHistInclusive( TH2F * h_exclusive, TH2F * &h_inclusive, bool inclusivenjets, bool inclusiveht )
{
  h_inclusive->Scale(0.0);
  for( int xbin = 1; xbin < h_exclusive->GetNbinsX()+1; xbin++ ){
	for( int ybin = 1; ybin < h_exclusive->GetNbinsY()+1; ybin++ ){
	  if( !inclusivenjets &&
		  inclusiveht    ) h_inclusive->SetBinContent( xbin, ybin, h_exclusive->Integral( xbin, xbin, ybin, -1 ));
	  if(  inclusivenjets &&
		   inclusiveht    ) h_inclusive->SetBinContent( xbin, ybin, h_exclusive->Integral( xbin,   -1, ybin, -1 ));
	  if( !inclusivenjets &&
		  !inclusiveht    ) h_inclusive->SetBinContent( xbin, ybin, h_exclusive->Integral( xbin, xbin, ybin, ybin ));
	}
  }  
  return;
}
