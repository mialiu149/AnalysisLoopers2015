#include "TColor.h"

void setBenStyle() {
  
  cout<<"Using Ben style file"<<endl;
  TStyle *benStyle = new TStyle("benStyle","Style for Ben");
  
  //benStyle->SetStyle("Plain");
 
  //canvas
  benStyle->SetCanvasBorderMode(0);
  benStyle->SetCanvasColor(kWhite);
  
  //pad
  benStyle->SetPadColor(kWhite);
  benStyle->SetPadBorderMode(0);

  //title
  benStyle->SetTitleFillColor(10);

  //stat box
  benStyle->SetStatColor(kWhite);

  //frame
  benStyle->SetFrameFillStyle(0);
  benStyle->SetFrameBorderMode(0);

  //axes
  benStyle->SetTitleSize(0.055, "XYZ");
  //benStyle->SetTitleOffset(10, "Y");
  benStyle->SetLabelSize(0.05, "XYZ");

  //margins
  benStyle->SetPadTopMargin(0.1);
  benStyle->SetPadBottomMargin(0.13);
  benStyle->SetPadLeftMargin(0.13);
  benStyle->SetPadRightMargin(0.15);

  //palette
  //For the palette
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  benStyle->SetNumberContours(NCont);

  //text TH1
  //benStyle->SetPaintTextFormat(".1f");

  benStyle->cd();
}
