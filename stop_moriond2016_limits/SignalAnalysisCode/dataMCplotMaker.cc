#include "dataMCplotMaker.h"

//Comparison to put smallest histogram on bottom of stack
bool Integral(PlotInfo plot1, PlotInfo plot2){
  return plot1.Plot->Integral(0,plot1.Plot->GetNbinsX()) < plot2.Plot->Integral(0,plot2.Plot->GetNbinsX());
}

//Comparison between pair in order to make sort on index 
bool pairCompare(const std::pair<float, int> & a, const std::pair<float, int> & b) {
  return a.first > b.first;
}

//Needed for freaking vertical lines
void DrawVerticalLine(Double_t x){
  TLine l;
  l.SetLineStyle(2);
  l.SetLineWidth(2);
  l.SetLineColor(kGray+2);
  Double_t lm = gPad->GetLeftMargin();
  Double_t rm = 1.-gPad->GetRightMargin();
  Double_t tm = 1.-gPad->GetTopMargin();
  Double_t bm = gPad->GetBottomMargin();
  Double_t xndc = (rm-lm)*((x-gPad->GetUxmin())/(gPad->GetUxmax()-gPad->GetUxmin()))+lm;
  l.DrawLineNDC(xndc,bm,xndc,tm);
}

//Function to determine maximum of each histogram, including error bars.  Side = 1 left, 2 right, 3 both, 4 = overflow
TH1F *null = new TH1F("", "", 1,0,1);
float AdjustedMaximum(int side, std::vector <std::pair<TH1F*, TH1F*> > Plots_in, TH1F* data = null, std::vector <TH1F*> Signals = std::vector<TH1F*>()){
  std::vector <TH1F*> Plots;
  std::vector <TH1F*> Plots_syst;
  for (unsigned int i = 0; i < Plots_in.size(); i++) Plots.push_back(Plots_in[i].first); 
  for (unsigned int i = 0; i < Plots_in.size(); i++) Plots_syst.push_back(Plots_in[i].second); 
  int lowerBound = 1;
  if (side == 2) lowerBound = 0.5*Plots[0]->GetNbinsX()+1;
  int upperBound = Plots[0]->GetNbinsX();
  if (side == 1) upperBound = 0.5*Plots[0]->GetNbinsX()+1;
  if (side == 2) upperBound--;
  if (side == 4) lowerBound = Plots[0]->GetNbinsX(); 
  if (side == 4) upperBound = Plots[0]->GetNbinsX()+1; 
  int nbins = Plots[0]->GetNbinsX(); 
  if (nbins < 6){
    lowerBound = 1;
    upperBound = nbins;
  }
  std::vector <float> heights;
  for (int i = lowerBound; i < upperBound; i++){
    float temp = 0;
    for (unsigned int j = 0; j < Plots.size(); j++) temp += Plots[j]->GetBinContent(i)+Plots_syst[j]->GetBinError(i);
    heights.push_back(temp);
  }
  if (Signals.size() > 0 && Signals[0]->GetEntries() > 0){
    for (int i = 1; i < Signals[0]->GetNbinsX(); i++){
      float temp = 0;
      for (unsigned int j = 0; j < Signals.size(); j++){
        temp += Signals[j]->GetBinContent(i);
      }
      heights.push_back(temp);
    }
  }
  std::sort( heights.begin(), heights.end() );
  float bkgd_height = heights[heights.size()-1];
  heights.clear();
  for (int i = lowerBound; i < upperBound; i++){
    heights.push_back(data->GetBinContent(i)+data->GetBinError(i));
  }
  std::sort( heights.begin(), heights.end() );
  float data_height = heights[heights.size()-1];
  return std::max(data_height, bkgd_height);
}

//Set style -- this is completely ripped off from TDRStyle.cc
void SetTDRStyle(){

  tdrStyleAG = new TStyle("tdrStyleAGAG","Style for P-TDR");

  // For the canvas:
  tdrStyleAG->SetCanvasBorderMode(0);
  tdrStyleAG->SetCanvasColor(kWhite);
  tdrStyleAG->SetCanvasDefH(550); //Height of canvas
  tdrStyleAG->SetCanvasDefW(600); //Width of canvas
  tdrStyleAG->SetCanvasDefX(0);   //Position on screen
  tdrStyleAG->SetCanvasDefY(0);

  // For the Pad:
  tdrStyleAG->SetPadBorderMode(0);
  tdrStyleAG->SetPadColor(kWhite);
  tdrStyleAG->SetPadGridX(false);
  tdrStyleAG->SetPadGridY(false);
  tdrStyleAG->SetGridColor(0);
  tdrStyleAG->SetGridStyle(3);
  tdrStyleAG->SetGridWidth(1);

  // For the frame:
  tdrStyleAG->SetFrameBorderMode(0);
  tdrStyleAG->SetFrameBorderSize(1);
  tdrStyleAG->SetFrameFillColor(0);
  tdrStyleAG->SetFrameFillStyle(0);
  tdrStyleAG->SetFrameLineColor(1);
  tdrStyleAG->SetFrameLineStyle(1);
  tdrStyleAG->SetFrameLineWidth(1);

  //For the histo:
  tdrStyleAG->SetHistLineColor(kBlack);
  tdrStyleAG->SetHistLineWidth(2);
  tdrStyleAG->SetEndErrorSize(2);
  tdrStyleAG->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyleAG->SetOptFit(1);
  tdrStyleAG->SetFitFormat("5.4g");
  tdrStyleAG->SetFuncColor(2);
  tdrStyleAG->SetFuncStyle(1);
  tdrStyleAG->SetFuncWidth(1);

  //For the date:
  tdrStyleAG->SetOptDate(0);

  //For the statistics box:
  tdrStyleAG->SetOptFile(0);
  tdrStyleAG->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyleAG->SetOptFit(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyleAG->SetStatColor(kWhite);
  tdrStyleAG->SetStatFont(42);
  tdrStyleAG->SetStatFontSize(0.025);
  tdrStyleAG->SetStatTextColor(1);
  tdrStyleAG->SetStatFormat("6.4g");
  tdrStyleAG->SetStatBorderSize(1);
  tdrStyleAG->SetStatH(0.1);
  tdrStyleAG->SetStatW(0.15);

  //Margins:
  tdrStyleAG->SetPadTopMargin(0.10);
  tdrStyleAG->SetPadBottomMargin(0.15);
  tdrStyleAG->SetPadLeftMargin(0.15);
  tdrStyleAG->SetPadRightMargin(0.04);

  //For the Global title:
  tdrStyleAG->SetOptTitle(1);
  tdrStyleAG->SetTitleFont(42);
  tdrStyleAG->SetTitleColor(1);
  tdrStyleAG->SetTitleTextColor(1);
  tdrStyleAG->SetTitleFillColor(10);
  tdrStyleAG->SetTitleFontSize(0.05);
  tdrStyleAG->SetTitleX(0.5); // Set the position of the title box
  tdrStyleAG->SetTitleY(0.985); // Set the position of the title box
  tdrStyleAG->SetTitleAlign(23);
  tdrStyleAG->SetTitleStyle(0);
  tdrStyleAG->SetTitleBorderSize(0);
  tdrStyleAG->SetTitleFillColor(0);

  //For the axis titles:
  tdrStyleAG->SetTitleColor(1, "XYZ");
  tdrStyleAG->SetTitleFont(42, "XYZ");
  tdrStyleAG->SetTitleSize(0.035, "XYZ");
  tdrStyleAG->SetTitleOffset(1.20, "X");
  tdrStyleAG->SetTitleOffset(1.10, "Y"); 

  //For the axis labels:
  tdrStyleAG->SetLabelColor(1, "XYZ");
  tdrStyleAG->SetLabelFont(42, "XYZ");
  tdrStyleAG->SetLabelOffset(0.007, "XYZ");
  tdrStyleAG->SetLabelSize(0.035, "XYZ");

  //For the axis:
  tdrStyleAG->SetAxisColor(1, "XYZ");
  tdrStyleAG->SetStripDecimals(kTRUE);
  tdrStyleAG->SetTickLength(0.03, "XYZ");
  tdrStyleAG->SetNdivisions(510, "XYZ");
  tdrStyleAG->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyleAG->SetPadTickY(1);

  //Change for log plots:
  tdrStyleAG->SetOptLogx(0);
  tdrStyleAG->SetOptLogy(0);
  tdrStyleAG->SetOptLogz(0);

  //Postscript options:
  tdrStyleAG->SetPaperSize(20.,20.);
  tdrStyleAG->cd();
}

void singlePlotMaker(TH1F* h1, std::string title, std::string options_string) {
    if(h1->GetEntries() < 1) {
        std::cout << "Plot with title " << title << " is empty. Not drawing." << std::endl; return;
    }
    TH1F* null = new TH1F("","",1,0,1);
    std::vector <TH1F*> Backgrounds;
    std::vector <std::string> Titles;
    Backgrounds.push_back(h1);
    Titles.push_back(title);
    dataMCplotMaker(null, Backgrounds, Titles, title, "", options_string);
}

void dataMCplotMaker(TH1F* Data_in, std::vector <std::pair <TH1F*, TH1F*> > Backgrounds_pair_in, std::vector <std::string> Titles, std::string titleIn, std::string title2In, std::string options_string, std::vector <TH1F*> Signals_in, std::vector <std::string> SignalTitles, std::vector <Color_t> color_input){

  //Copy inputs
  TH1F* Data = new TH1F(*Data_in); 
  std::vector <TH1F*> Backgrounds; 
  std::vector <TH1F*> Background_systs; 
  std::vector <TH1F*> Signals; 
  std::vector <std::pair<TH1F*, TH1F*> > Backgrounds_pair; 
  for (unsigned int i = 0; i < Backgrounds_pair_in.size(); i++){
    TH1F* blah  = new TH1F(*Backgrounds_pair_in[i].first); 
    Backgrounds.push_back(blah);  
    TH1F* blah2 = 0; 
    TH1F* blah3 = 0; 
    if (Backgrounds_pair_in[i].second->GetEntries() > 0){
      blah2 = new TH1F(*Backgrounds_pair_in[i].second); 
      Background_systs.push_back(blah2); 
    }
    else blah3 = new TH1F(*Backgrounds_pair_in[i].second);
    std::pair<TH1F*, TH1F*> blah4 = std::make_pair(blah, Backgrounds_pair_in[i].second->GetEntries() > 0 ? blah2 : blah3); 
    Backgrounds_pair.push_back(blah4); 
  }
  for (unsigned int i = 0; i < Signals_in.size(); i++){
    TH1F* blah = new TH1F(*Signals_in[i]); 
    Signals.push_back(blah);  
  }

  //Convert titles to fucking char*s 
  char* title = (char *)alloca(titleIn.size() + 1);
  memcpy(title, titleIn.c_str(), titleIn.size() + 1);

  char* title2 = (char *)alloca(title2In.size() + 1);
  memcpy(title2, title2In.c_str(), title2In.size() + 1);

  bool noData = false;
  if (Data->GetEntries() == 0) noData = true;

  bool use_signals = true;
  if (Signals.size() == 0) use_signals = false;
  if (Signals.size() == 1 && Signals[0]->GetEntries() == 0) use_signals = false;

  //Turn "options" string into vector of strings, one parm each
  std::vector <std::string> Options = GetParms(options_string);  

  //Default values of all user-adjustable parameters
  bool linear = 0;
  bool nostack = 0;
  bool noFill = 0;
  bool normalize = 0;
  bool doOverflow = 1;
  bool doCounts = 0;
  bool showXaxisUnit = 1;
  bool noType = false;
  bool colorTitle = false;
  std::string xAxisLabel = "M_{T}";
  std::string energy = "13";
  std::string lumi = "10.0";
  std::string yAxisLabel = "Entries";
  std::string yAxisUnit = "";
  std::string yAxisOverride = "";
  std::string xAxisUnit = "GeV";
  std::string xAxisOverride = "";
  std::string xAxisBinLabels = "";
  std::string dataName = "data";
  std::string topYaxisTitle = "data/MC";
  std::string overrideHeader = "";
  std::string type = "CMS Preliminary "; // unused?
  std::string outputName = "data_MC_plot";
  bool preserveBackgroundOrder = 0;
  bool preserveSignalOrder = 0;
  bool showDivisionLabel = 1;
  bool xAxisVerticalBinLabels = 0;
  float setMaximum = -1;
  float setMinimum = -1;
  float legendUp = 0;
  float legendRight = 0;
  float legendTextSize = 0.035;
  std::vector <float> vLines;
  std::vector <float> hLines;
  bool doHalf = 0;
  Int_t nDivisions = -1;
  bool noLegend = false;
  bool png = false;
  bool dots = false;
  bool showPercentage = false;
  bool percentageInBox = false;
  bool errHistAtBottom = false;
  std::vector<int> percent;
  std::string datacolor = "";
  std::string ratiocolor = "";
  bool noOutput = false;
  bool noErrBars = false;
  bool noBlackLines = false;
  bool histoErrors = false;
  bool legendBox = false;
  bool xAxisOverrideGiven = false;  
  std::string lumiUnit = "fb"; 
  bool sigError = false;
  bool blackSignals = false;
  bool outOfFrame = false;
  bool markerStyle2 = false;
  float legendWider_ = 0;
  float legendTaller_ = 0;
  bool largeLabels = false;
  float yTitleOffset_ = 0;
  bool compareMultiple = 0; 
  bool noLumi = 0; 
  int ratio = -1; 
  bool ratioOnly = 0; 
  bool ratioLine = 0; 
  int bkgd_width = 1; 

  //Loop over options and change default settings to user-defined settings
  for (unsigned int i = 0; i < Options.size(); i++){
    if (Options[i].find("isLinear") < Options[i].length()) linear = 1; 
    else if (Options[i].find("preserveBackgroundOrder") < Options[i].length()) preserveBackgroundOrder = 1; 
    else if (Options[i].find("noBlackLines") < Options[i].length()) noBlackLines = 1; 
    else if (Options[i].find("noStack") < Options[i].length()) nostack = 1; 
    else if (Options[i].find("lumiUnit") < Options[i].length()) lumiUnit = getString(Options[i], "lumiUnit"); 
    else if (Options[i].find("noFill") < Options[i].length()) noFill = 1;
    else if (Options[i].find("normalize") < Options[i].length()) normalize = 1; 
    else if (Options[i].find("preserveSignalOrder") < Options[i].length()) preserveSignalOrder = 1; 
    else if (Options[i].find("legendBox") < Options[i].length()) legendBox = 1; 
    else if (Options[i].find("outputName") < Options[i].length()) outputName = getString(Options[i], "outputName");
    else if (Options[i].find("png") < Options[i].length()) png = true;
    else if (Options[i].find("noDivisionLabel") < Options[i].length()) showDivisionLabel = 0; 
    else if (Options[i].find("noLegend") < Options[i].length()) noLegend = 1; 
    else if (Options[i].find("noOverflow") < Options[i].length()) doOverflow = 0; 
    else if (Options[i].find("doCounts") < Options[i].length()) doCounts = 1; 
    else if (Options[i].find("noType") < Options[i].length()) noType = 1; 
    else if (Options[i].find("colorTitle") < Options[i].length()) colorTitle = 1; 
    else if (Options[i].find("noXaxisUnit") < Options[i].length()) showXaxisUnit = 0; 
    else if (Options[i].find("divHalf") < Options[i].length()) doHalf = 1; 
    else if (Options[i].find("energy") < Options[i].length()) energy = getString(Options[i], "energy");
    else if (Options[i].find("lumi") < Options[i].length()) lumi = getString(Options[i], "lumi");
    else if (Options[i].find("yAxisLabel") < Options[i].length()) yAxisLabel = getString(Options[i], "yAxisLabel");
    else if (Options[i].find("yAxisUnit") < Options[i].length()) yAxisUnit = getString(Options[i], "yAxisUnit");
    else if (Options[i].find("yAxisOverride") < Options[i].length()) yAxisOverride = getString(Options[i], "yAxisOverride");
    else if (Options[i].find("xAxisLabel") < Options[i].length()) xAxisLabel = getString(Options[i], "xAxisLabel");
    else if (Options[i].find("xAxisUnit") < Options[i].length()) xAxisUnit = getString(Options[i], "xAxisUnit");
    else if (Options[i].find("xAxisOverride") < Options[i].length()){ xAxisOverride = getString(Options[i], "xAxisOverride"); xAxisOverrideGiven = true; }
    else if (Options[i].find("xAxisBinLabels") < Options[i].length()) xAxisBinLabels = getString(Options[i], "xAxisBinLabels");
    else if (Options[i].find("xAxisVerticalBinLabels") < Options[i].length()) xAxisVerticalBinLabels = 1; 
    else if (Options[i].find("dataName") < Options[i].length()) dataName = getString(Options[i], "dataName");
    else if (Options[i].find("dataColor") < Options[i].length()) datacolor = getString(Options[i], "dataColor");
    else if (Options[i].find("ratioColor") < Options[i].length()) ratiocolor = getString(Options[i], "ratioColor");
    else if (Options[i].find("topYaxisTitle") < Options[i].length()) topYaxisTitle = getString(Options[i], "topYaxisTitle");
    else if (Options[i].find("type") < Options[i].length()) type = getString(Options[i], "type");
    else if (Options[i].find("overrideHeader") < Options[i].length()) overrideHeader = getString(Options[i], "overrideHeader");
    else if (Options[i].find("vLine") < Options[i].length()) vLines.push_back(atof( getString(Options[i], "vLine").c_str() ));
    else if (Options[i].find("hLine") < Options[i].length()) hLines.push_back(atof( getString(Options[i], "hLine").c_str() ));
    else if (Options[i].find("setMaximum") < Options[i].length()) setMaximum = atof( getString(Options[i], "setMaximum").c_str() );
    else if (Options[i].find("legendUp") < Options[i].length()) legendUp = atof( getString(Options[i], "legendUp").c_str() );
    else if (Options[i].find("legendRight") < Options[i].length()) legendRight = atof( getString(Options[i], "legendRight").c_str() );
    else if (Options[i].find("legendTextSize") < Options[i].length()) legendTextSize = atof( getString(Options[i], "legendTextSize").c_str() );
    else if (Options[i].find("setMinimum") < Options[i].length()) setMinimum = atof( getString(Options[i], "setMinimum").c_str() );
    else if (Options[i].find("nDivisions") < Options[i].length()) nDivisions = atoi( getString(Options[i], "nDivisions").c_str() );
    else if (Options[i].find("drawDots") < Options[i].length()) dots = true; 
    else if (Options[i].find("showPercentage") < Options[i].length()) showPercentage = true; 
    else if (Options[i].find("percentageInBox") < Options[i].length()) percentageInBox = true; 
    else if (Options[i].find("errHistAtBottom") < Options[i].length()) errHistAtBottom = true; 
    else if (Options[i].find("noOutput") < Options[i].length()) noOutput = true; 
    else if (Options[i].find("noErrBars") < Options[i].length()) noErrBars = true; 
    else if (Options[i].find("histoErrors") < Options[i].length()) histoErrors = true; 
    else if (Options[i].find("sigError") < Options[i].length()) sigError = true; 
    else if (Options[i].find("blackSignals") < Options[i].length()) blackSignals = true; 
    else if (Options[i].find("outOfFrame") < Options[i].length()) outOfFrame = true; 
    else if (Options[i].find("markerStyle2") < Options[i].length()) markerStyle2 = true; 
    else if (Options[i].find("largeLabels") < Options[i].length()) largeLabels = true; 
    else if (Options[i].find("legendWider") < Options[i].length())  legendWider_ = atof( getString(Options[i], "legendWider").c_str() );
    else if (Options[i].find("legendTaller") < Options[i].length()) legendTaller_ = atof( getString(Options[i], "legendTaller").c_str() ); 
    else if (Options[i].find("yTitleOffset") < Options[i].length()) yTitleOffset_ = atof( getString(Options[i], "yTitleOffset").c_str() ); 
    else if (Options[i].find("compareMultiple") < Options[i].length()) compareMultiple = true;
    else if (Options[i].find("ratioOnly") < Options[i].length()) ratioOnly = true;
    else if (Options[i].find("ratioLine") < Options[i].length()) ratioLine = true;
    else if (Options[i].find("ratio") < Options[i].length()) ratio = atoi( getString(Options[i], "ratio").c_str() );
    else if (Options[i].find("noLumi") < Options[i].length()) noLumi = true;
    else if (Options[i].find("bkgd_width") < Options[i].length()) bkgd_width = atoi( getString(Options[i], "bkgd_width").c_str() ); 
    else std::cout << "Warning: Option not recognized!  Option: " << Options[i] << std::endl;
  }

  //Print warnings
  if (normalize && !nostack) std::cout << "Warning! You set option to normalize, but not option --noStack.  This won't do much!" << std::endl;
  if (ratioLine && !noErrBars) std::cout << "Warning!  ratioLine won't do much without noErrBars!" << std::endl;

  //Try to guess if we should turn off division label
  if (xAxisUnit == "" || xAxisUnit.find("SR") < xAxisUnit.length() || !showXaxisUnit) showDivisionLabel = 0;

  //Decode data color
  Color_t dataColor = kBlack;
  Color_t ratioColor = kBlack;
  if (datacolor != ""){
    std::transform(datacolor.begin(), datacolor.end(), datacolor.begin(), ::tolower); 
    if (datacolor == "kred"     || datacolor == "red") dataColor = kRed;
    if (datacolor == "kblue"    || datacolor == "blue") dataColor = kBlue;
    if (datacolor == "kgreen"   || datacolor == "green") dataColor = kGreen;
    if (datacolor == "korange"  || datacolor == "orange") dataColor = kOrange;
    if (datacolor == "kcyan"    || datacolor == "cyan") dataColor = kCyan;
    if (datacolor == "kmagenta" || datacolor == "magenta") dataColor = kMagenta;
  }
  if (ratiocolor != ""){
    std::transform(ratiocolor.begin(), ratiocolor.end(), ratiocolor.begin(), ::tolower); 
    if (ratiocolor == "kred"     || ratiocolor == "red") ratioColor = kRed;
    if (ratiocolor == "kblue"    || ratiocolor == "blue") ratioColor = kBlue;
    if (ratiocolor == "kgreen"   || ratiocolor == "green") ratioColor = kGreen;
    if (ratiocolor == "korange"  || ratiocolor == "orange") ratioColor = kOrange;
    if (ratiocolor == "kcyan"    || ratiocolor == "cyan") ratioColor = kCyan;
    if (ratiocolor == "kmagenta" || ratiocolor == "magenta") ratioColor = kMagenta;
  }

  //Set Style
  SetTDRStyle();
  gStyle->SetOptStat(0);
  if (noData) gStyle->SetPadBottomMargin(.12);
  if (noData) gStyle->SetPadLeftMargin(.12);
  if (noData) gStyle->SetPadTopMargin(.07);

  //Make sure there is at least one background and enough titles
  if (Backgrounds.size() < 1){ 
    std::cout << "Error: Running with no backgrounds!" << std::endl;
    return;
  }
  if (Titles.size() != Backgrounds.size()) std::cout << "Warning! Wrong number of titles for your backgrounds!" << std::endl;
  while (Titles.size() < Backgrounds.size()){
    char* blank = new char[strlen("")+2];
    std::strcpy(blank, "");
    Titles.push_back(blank);
  }
  if (use_signals && SignalTitles.size() != Signals.size()) std::cout << "Warning! Wrong number of titles for your signals!" << std::endl;
  while (SignalTitles.size() < Signals.size()){
    char* blank = new char[strlen("")+2];
    std::strcpy(blank, "");
    SignalTitles.push_back(blank);
  }

  //Format Titles
  for (unsigned int i = 0; i < Titles.size(); i++){
    std::string title_temp = Titles[i];
    if (title_temp == "ttsl" || title_temp == "1ltop" || title_temp == "1lep" || title_temp == "singlelep" || title_temp == "singlelepton"){
       char* temp = new char[strlen("1 #font[12]{l} top")+2];
       std::strcpy(temp, "1 #font[12]{l} top");
       Titles[i] = temp;
    }
    if (title_temp == "ttdl" || title_temp == "2lep" || title_temp == "dilep" || title_temp == "dilepton"){
       char* temp = new char[strlen("t#bar{t}#rightarrow #font[12]{ll}")+2];
       std::strcpy(temp, "t#bar{t}#rightarrow #font[12]{ll}");
       Titles[i] = temp;
    }
    if (title_temp == "wjets"){
       char* temp = new char[strlen("W+jets")+2];
       std::strcpy(temp, "W+jets");
       Titles[i] = temp;
    }
  }

  //Do Overflow
  if (doOverflow == 1){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->SetBinContent(Backgrounds[i]->GetNbinsX(), Backgrounds[i]->GetBinContent(Backgrounds[i]->GetNbinsX())+Backgrounds[i]->GetBinContent(Backgrounds[i]->GetNbinsX()+1) );
    }
    for (unsigned int i = 0; i < Background_systs.size(); i++){
      Background_systs[i]->SetBinContent(Background_systs[i]->GetNbinsX(), Background_systs[i]->GetBinContent(Background_systs[i]->GetNbinsX())+Background_systs[i]->GetBinContent(Background_systs[i]->GetNbinsX()+1) );
    }
    for (unsigned int i = 0; i < Signals.size(); i++){
      Signals[i]->SetBinContent(Signals[i]->GetNbinsX(), Signals[i]->GetBinContent(Signals[i]->GetNbinsX())+Signals[i]->GetBinContent(Signals[i]->GetNbinsX()+1) );
    }
    if (!noData) Data->SetBinContent(Data->GetNbinsX(), Data->GetBinContent(Data->GetNbinsX())+Data->GetBinContent(Data->GetNbinsX()+1) );
  }

  //Do Underflow
  if (doOverflow == 1){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->SetBinContent(1, Backgrounds[i]->GetBinContent(1)+Backgrounds[i]->GetBinContent(0) );
    }
    for (unsigned int i = 0; i < Background_systs.size(); i++){
      Background_systs[i]->SetBinContent(1, Background_systs[i]->GetBinContent(1)+Background_systs[i]->GetBinContent(0) );
    }
    for (unsigned int i = 0; i < Signals.size(); i++){
      Signals[i]->SetBinContent(1, Signals[i]->GetBinContent(1)+Signals[i]->GetBinContent(0) );
    }
    if (!noData) Data->SetBinContent(1, Data->GetBinContent(1)+Data->GetBinContent(0) );
  }

  std::vector <Color_t> Colors;
  std::vector <Color_t> Colors2;

  //Set colors for histograms
  //(a) Use colors assigned
  if (color_input.size() != 0){
    for (unsigned int i = 0; i < color_input.size(); i++){
      Colors.push_back(color_input[i]);
    }
  }
  //(b) If compareMultiple, then need to light + dark colors
  if (compareMultiple){
    Colors.push_back(kGray);     Colors2.push_back(kBlack); 
    Colors.push_back(kCyan);     Colors2.push_back(kBlue); 
    Colors.push_back(kGreen);    Colors2.push_back(kGreen+3); 
    Colors.push_back(kRed-7);    Colors2.push_back(kRed); 
    Colors.push_back(kMagenta);  Colors2.push_back(kViolet+3); 
    Colors.push_back(kOrange+1); Colors2.push_back(kOrange+3); 
  }
  //(c) If only 2 backgrounds, use this green + "Azure"
  if (color_input.size() == 0 && Backgrounds.size() == 2){
    if(Colors.size() > 0) Colors[0] = kAzure+7; else Colors.push_back(kAzure+7);
    if(Colors.size() > 1) Colors[1] = kGreen+3; else Colors.push_back(kGreen+3);
  }
  //(d) Otherwise, default scheme for no signals
  if (color_input.size() == 0 && use_signals == 0){ 
    Colors.push_back(kGreen+3);   
    if (!nostack) Colors.push_back(kBlue-10);   
    Colors.push_back(kOrange+10);
    if (!nostack) Colors.push_back(kYellow-4); 
    if (!nostack) Colors.push_back(kCyan-4);
    Colors.push_back(kViolet+4);
    Colors.push_back(kRed);
    Colors.push_back(kBlack);
  }
  //(e) Otherwise, default scheme for signals
  if (color_input.size() == 0 && use_signals == 1){ 
    Colors.push_back(kGreen-3);
    Colors.push_back(kBlue-2);
    Colors.push_back(kCyan);
    Colors.push_back(kOrange-4);
    Colors.push_back(kMagenta-8);
    Colors.push_back(kRed);
    Colors.push_back(kGreen+3);
    Colors.push_back(kYellow-7);
  }

  //Black Signals
  if (blackSignals){
    for (unsigned int i = Backgrounds.size(); i < Colors.size(); i++) Colors[i] = kBlack; 
  }

  std::vector <int> Backgrounds_number; 

  //Sort Backgrounds, with Titles and Colors
  if (preserveBackgroundOrder == 0){
    std::vector<PlotInfo> myPlotInfo;
 
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      PlotInfo temp;
      temp.Plot = Backgrounds[i];
      temp.Title = Titles[i];
      temp.Number = i; 
      if (Signals.size() >= i+1)     temp.Signal      = Signals[i];
      if (Colors2.size() >= i+1) temp.SignalColor = Colors2[i];
      if (SignalTitles.size() >= i+1) temp.SignalTitle = SignalTitles[i];
      if (color_input.size() > 0){
        temp.Color = color_input[i];
      }
      else{
        temp.Color = Colors[i];
      }
      myPlotInfo.push_back(temp);
    }

    std::sort(myPlotInfo.begin(), myPlotInfo.end(), Integral);
    Backgrounds.clear();
    Titles.clear();

    for (unsigned int i = 0; i < myPlotInfo.size(); i++){
      Backgrounds.push_back(myPlotInfo[i].Plot);
      Backgrounds_number.push_back(myPlotInfo[i].Number); 
      Titles.push_back(myPlotInfo[i].Title);
      Colors[i] = myPlotInfo[i].Color;
      if (compareMultiple) Signals[i] = myPlotInfo[i].Signal;
      if (compareMultiple) Colors2[i] = myPlotInfo[i].SignalColor;
      if (compareMultiple) SignalTitles[i] = myPlotInfo[i].SignalTitle;
    }
  }

  //Sort Signals, with Titles and Colors
  if (!preserveSignalOrder && !compareMultiple){
    std::vector<PlotInfo> myPlotInfo;
 
    for (unsigned int i = 0; i < Signals.size(); i++){
      PlotInfo temp;
      temp.Plot = Signals[i];
      temp.Title = SignalTitles[i];
      if (color_input.size() > 0){
        temp.Color = color_input[i+Backgrounds.size()];
      }
      else{
        temp.Color = Colors[i+Backgrounds.size()];
      }
      myPlotInfo.push_back(temp);
    }

    std::sort(myPlotInfo.begin(), myPlotInfo.end(), Integral);
    Signals.clear();
    SignalTitles.clear();

    for (unsigned int i = 0; i < myPlotInfo.size(); i++){
      Signals.push_back(myPlotInfo[i].Plot);
      SignalTitles.push_back(myPlotInfo[i].Title);
      if (color_input.size() > 0) Colors.push_back(myPlotInfo[i].Color);
      else Colors[Backgrounds.size()+i] = myPlotInfo[i].Color;  
    }
  }

  //Draw histogram with two pads
  TCanvas c0("c0", "c0");
  TPad* finPad[2];
  if (noData == false || compareMultiple){
    c0.SetCanvasSize(600, 700);
    if (errHistAtBottom == false){
      finPad[0] = new TPad("1", "1", 0.0, 0.0, 1.0, 0.84);
      finPad[1] = new TPad("2", "2", 0.0, 0.83, 1.0, 1.0);
    }
    else{
      finPad[0] = new TPad("1", "1", 0.0, 0.16, 1.0, 1.0);
      finPad[1] = new TPad("2", "2", 0.0, 0.0, 1.0, 0.17);
    }
    if (!linear) finPad[0]->SetLogy();
    finPad[0]->SetTopMargin(0.05);
    finPad[0]->SetLeftMargin(0.12);
    finPad[0]->SetBottomMargin(0.11);
    finPad[1]->SetLeftMargin(0.12);
    finPad[1]->Draw();
    finPad[0]->Draw();
    finPad[0]->cd();
  }
  if (noData == true && !compareMultiple){
    c0.SetCanvasSize(600, 550);
    finPad[0] = new TPad();
    finPad[1] = new TPad();
    if (!linear) c0.SetLogy();
  }

  //--------First pad: histogram------------

  //Stack of backgrounds
  THStack *stack = new THStack("stack", ""); 
  Data->SetMarkerStyle(20);
  Data->UseCurrentStyle();
  if(!compareMultiple && noFill == 0 && Signals.size() >= 5 && !nostack){
    std::vector <int> Style;
    Style.push_back(3003);
    Style.push_back(3004);
    Style.push_back(3005);
    Style.push_back(3006);
    Style.push_back(3007);
    Style.push_back(3013);
    Style.push_back(3001);
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->UseCurrentStyle();
      Backgrounds[i]->SetFillColor(kGray);
      Backgrounds[i]->SetLineColor(kGray);
      Backgrounds[i]->SetFillStyle(Style[i]);
      stack->Add(Backgrounds[i]);
    }
  } 
  if(noFill == 0 && (Signals.size() < 5 || nostack || compareMultiple)){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->UseCurrentStyle();
      if (!nostack) Backgrounds[i]->SetFillColor(Colors[i]);
      Backgrounds[i]->SetMarkerColor(Colors[i]);
      if (noBlackLines || nostack) Backgrounds[i]->SetLineColor(Colors[i]);
      else Backgrounds[i]->SetLineColor(kBlack);
      Backgrounds[i]->SetLineWidth(Backgrounds[i]->GetLineWidth()/1.5);
      if (nostack && normalize) Backgrounds[i]->Scale(1.0/Backgrounds[i]->Integral());
      stack->Add(Backgrounds[i]);
    }
  } 
  else if(noFill == 1){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->UseCurrentStyle();
      Backgrounds[i]->SetFillColor(kWhite);
      Backgrounds[i]->SetLineColor(Colors[i]);
      Backgrounds[i]->SetMarkerColor(Colors[i]);
      if (nostack && normalize) Backgrounds[i]->Scale(1.0/Backgrounds[i]->Integral());
      stack->Add(Backgrounds[i]);
    }
  }
  else {
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->SetMarkerColor(Colors[i]);
    }
  }

  //Try this
  if (!dots && !nostack) Backgrounds[0]->SetMarkerColor(0); 
  if (dots){ Backgrounds[0]->SetMarkerColor(kBlue); Backgrounds[0]->SetLineColor(kBlue); }
  if (dots && Backgrounds.size() > 1){ Backgrounds[1]->SetMarkerColor(kRed); Backgrounds[1]->SetLineColor(kRed); }
  if (dots && Backgrounds.size() > 2){ Backgrounds[2]->SetMarkerColor(kGreen+3); Backgrounds[2]->SetLineColor(kGreen+3); }
  if (dots && Backgrounds.size() > 3){ Backgrounds[3]->SetMarkerColor(kOrange+7); Backgrounds[3]->SetLineColor(kOrange+7); }

  //Minimum and maximum
  float leftMax = AdjustedMaximum(1, Backgrounds_pair, Data, Signals);
  float rightMax = AdjustedMaximum(2, Backgrounds_pair, Data, Signals);
  float myMin = 0.1;
  if (setMinimum != -1) myMin = setMinimum;
  if (setMinimum == -1 && !linear && Backgrounds[0]->GetMinimum() > 0) myMin = std::min(0.1, 0.9*Backgrounds[0]->GetMinimum());
  else if (setMinimum == -1 && !linear && stack->GetMinimum() > 0) myMin = std::min(0.1, 0.5*stack->GetMinimum());
  else if (setMinimum == -1 && !linear) myMin = 0.1;
  if (setMinimum == -1 && linear) myMin = 0; 
  if (!nostack) stack->Draw("hist");
  if (nostack) stack->Draw("nostack");
  float myMax = stack->GetMaximum();
  if (setMaximum != -1) myMax = setMaximum; 
  else if (setMaximum == -1 && !linear){
    myMax = pow(AdjustedMaximum(3, Backgrounds_pair, Data, Signals), 1.0/0.69)*pow(myMin, (0.69-1)/0.69); 
    if (leftMax > 5*rightMax) myMax = pow(AdjustedMaximum(3, Backgrounds_pair, Data, Signals), 1.0/0.74)*pow(myMin, (0.74-1)/0.74);
    if (rightMax > leftMax)   myMax = myMax*10; 
  }
  else if (setMaximum == -1 && linear && noLegend)  myMax = (AdjustedMaximum(3, Backgrounds_pair, Data, Signals))*(1.2) - (stack->GetMinimum())*(1.0/3.0);
  else if (setMaximum == -1 && linear){
    myMax = (AdjustedMaximum(3, Backgrounds_pair, Data, Signals))*1.46 - (stack->GetMinimum())*(1.0/3.0);  
    if (rightMax < 0.7*leftMax){
      myMax = myMax*0.88;
      if (strcmp(title2, "") == 0) myMax = myMax*0.94; 
    }
    else if (rightMax > leftMax){ 
      if (Backgrounds.size() + Signals.size() >= 4) myMax = myMax*1.2;
    }
  }
  else if (!linear) myMax = myMax*20.0;
  else myMax = myMax*2;

  stack->SetMinimum(myMin);
  stack->SetMaximum(myMax);

  //If linear and large numbers, need extra space
  if (linear && myMax > 1000) finPad[0]->SetLeftMargin(0.15);
  if (linear && myMax > 1000) finPad[1]->SetLeftMargin(0.15);

  //Y-axis titles
  float bin_width = Backgrounds[0]->GetXaxis()->GetBinWidth(1);
  if (yAxisOverride != "" && yAxisOverride[0] != '\0') stack->GetYaxis()->SetTitle(Form("%s", yAxisOverride.c_str()));
  else if (yAxisOverride[0] == '\0' && showDivisionLabel && yAxisUnit[0] != '\0') stack->GetYaxis()->SetTitle(Form("%s [%s] / %.0f %s  ", yAxisLabel.c_str(), yAxisUnit.c_str(), bin_width, xAxisUnit.c_str()));
  else if (yAxisOverride[0] == '\0' && showDivisionLabel && yAxisUnit[0] == '\0' && bin_width >= 2) stack->GetYaxis()->SetTitle(Form("%s / %.0f %s  ", yAxisLabel.c_str(), bin_width, xAxisUnit.c_str())); 
  else if (yAxisOverride[0] == '\0' && showDivisionLabel && yAxisUnit[0] == '\0' && bin_width < 2) stack->GetYaxis()->SetTitle(Form("%s / %.2f %s  ", yAxisLabel.c_str(), bin_width, xAxisUnit.c_str())); 
  else if (yAxisOverride[0] == '\0' && !showDivisionLabel && yAxisUnit[0] != '\0')stack->GetYaxis()->SetTitle(Form("%s [%s]  ", yAxisLabel.c_str(), yAxisUnit.c_str())); 
  else if (yAxisOverride[0] == '\0' && !showDivisionLabel && yAxisUnit[0] == '\0')stack->GetYaxis()->SetTitle(Form("%s  ", yAxisLabel.c_str()));
  else std::cout << "nothing" << std::endl;

  //X-axis titles
  if (xAxisLabel == "HT" || xAxisLabel == "ht" || xAxisLabel == "Ht") xAxisLabel = "H_{T}"; 
  if (xAxisLabel == "MT" || xAxisLabel == "mt" || xAxisLabel == "Mt") xAxisLabel = "M_{T}"; 
  if (xAxisOverride[0] == '\0' && showXaxisUnit == 0) stack->GetXaxis()->SetTitle(Form("%s", xAxisLabel.c_str()));
  if (xAxisOverride[0] == '\0' && showXaxisUnit == 1) stack->GetXaxis()->SetTitle(Form("%s [%s]", xAxisLabel.c_str(), xAxisUnit.c_str()));
  if (xAxisOverride[0] != '\0' || xAxisOverrideGiven) stack->GetXaxis()->SetTitle(Form("%s", xAxisOverride.c_str()));
  if (!noData) stack->GetYaxis()->SetTitleOffset(1.5);
  if (noData && !linear) stack->GetYaxis()->SetTitleOffset(1.4+yTitleOffset_);
  if (noData &&  linear) stack->GetYaxis()->SetTitleOffset(1.6+yTitleOffset_);
  if (linear && myMax > 1000) stack->GetYaxis()->SetTitleOffset(0.5+stack->GetYaxis()->GetTitleOffset()); 

  //Title size
  if (largeLabels){
    stack->GetYaxis()->SetTitleSize(0.05);
    stack->GetXaxis()->SetTitleSize(0.05);
    stack->GetYaxis()->SetLabelSize(0.045);
    stack->GetXaxis()->SetLabelSize(0.045);
    stack->GetXaxis()->SetTitleOffset(stack->GetXaxis()->GetTitleOffset()-0.2); 
    stack->GetYaxis()->SetTitleOffset(stack->GetYaxis()->GetTitleOffset()-0.2); 
  }

  //X-axis string bin labels
  TString ts = ""+xAxisBinLabels;
  TObjArray *tx = ts.Tokenize(",");
  if (xAxisBinLabels[0] != '\0') {
      for (Int_t i = 0; i < tx->GetEntries(); i++) {
          stack->GetXaxis()->SetBinLabel(i+1, ((TObjString *)(tx->At(i)))->String());
      }
      if(xAxisVerticalBinLabels) stack->GetXaxis()->LabelsOption("v");
      else stack->GetXaxis()->LabelsOption("u");
  }

  //Show Percentage
  if(showPercentage || percentageInBox){
    std::vector<double> each;
    float total = 0;
    for(unsigned int i=0; i<Backgrounds.size(); i++){
      each.push_back(Backgrounds[i]->Integral());
      total += each.back();
    }
    for(unsigned int i=0; i<Backgrounds.size(); i++){
      each[i] = each[i]/total*100;
      percent.push_back((int) each[i]);
    }
    // Get the rounded percentage add up to 100
    int ptotal = 0;
    for(unsigned int i=0; i<percent.size(); i++)  ptotal += percent[i];
    if (ptotal > 0){ //need this in case the plots are empty!
      std::vector< std::pair<float,int> > roundings;
      for(unsigned int i=0; i< percent.size(); i++) roundings.push_back(std::make_pair((each[i]-percent[i]),i));
      std::sort(roundings.begin(), roundings.end(), pairCompare);
      for(int i=0; i< (100-ptotal); i++) percent[roundings[i].second] += 1;
    }
  }

  //if (Background_systs.size() == 0) gStyle->SetErrorX(0.001); //why the fuck is this even here?

  //Stupid dots thing
  if (dots && myMin == 0){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      for (int j = 1; j <= Backgrounds[i]->GetNbinsX(); j++){
        if (Backgrounds[i]->GetBinContent(j) == 0){
          Backgrounds[i]->SetBinContent(j, 0.0000001); 
          cout << "Warning! One of your 'dots' is 0 and won't show up.  Setting it to 0.0000001" << endl;  
        }
      }
    }
  }

  //Try this
  if (!dots && !nostack) Backgrounds[0]->SetMarkerColor(0); 
  if (dots){ Backgrounds[0]->SetMarkerColor(kBlue); Backgrounds[0]->SetLineColor(kBlue); }
  if (dots && Backgrounds.size() > 1){ Backgrounds[1]->SetMarkerColor(kRed); Backgrounds[1]->SetLineColor(kRed); }
  if (dots && Backgrounds.size() > 2){ Backgrounds[2]->SetMarkerColor(kGreen+3); Backgrounds[2]->SetLineColor(kGreen+3); }
  if (dots && Backgrounds.size() > 3){ Backgrounds[3]->SetMarkerColor(kOrange+7); Backgrounds[3]->SetLineColor(kOrange+7); }
  if (dots && Backgrounds.size() > 4){ Backgrounds[4]->SetMarkerColor(kMagenta+2); Backgrounds[4]->SetLineColor(kMagenta+2); }
  if (dots && Backgrounds.size() > 5){ Backgrounds[5]->SetMarkerColor(kYellow-4); Backgrounds[5]->SetLineColor(kYellow-4); }

  if (bkgd_width > 1){
    for (unsigned int i = 0; i < Backgrounds.size(); i++){
      Backgrounds[i]->SetLineWidth(bkgd_width); 
    }
  }

  //Draw
  if (!nostack && !dots && histoErrors) stack->Draw("histe");
  else if (!nostack && !dots && !histoErrors) stack->Draw("hist");
  else if (dots) stack->Draw("PEnostack"); 
  else if (nostack) stack->Draw("histnostack");
  THStack *stack2 = new THStack("stack2", "stack2"); 
  Data->SetMarkerColor(dataColor);
  Data->SetLineColor(dataColor);
  if (!ratioOnly) stack2->Add(Data);
  if(noErrBars) stack2->Draw("PSAME");
  else stack2->Draw("PSAMEE");
  std::vector<int> markerStyle;
  markerStyle.push_back(20);
  markerStyle.push_back(21);
  markerStyle.push_back(22);
  markerStyle.push_back(23);
  markerStyle.push_back(29);
  markerStyle.push_back(33);
  markerStyle.push_back(34);
  std::vector <int> markerStyle2_;
  markerStyle2_.push_back(24);
  markerStyle2_.push_back(20);
  markerStyle2_.push_back(25);
  markerStyle2_.push_back(21);
  markerStyle2_.push_back(26);
  markerStyle2_.push_back(22);
  markerStyle2_.push_back(23);
  THStack signalsAG;
  for (unsigned int i = 0; i < Signals.size(); i++){
    if (!compareMultiple && !sigError) Signals[i]->Draw("SAMEHISTP");
    if (!compareMultiple &&  sigError) Signals[i]->Draw("SAMEPE");
    if (compareMultiple) Signals[i]->SetMarkerColor(Colors2[i]); 
    if (compareMultiple) signalsAG.Add(Signals[i]); 
    else if (Colors.size() >= i + Backgrounds.size() + 1) Signals[i]->SetMarkerColor(Colors[i + Backgrounds.size()]);
    Signals[i]->SetLineColor(kBlack);
    Signals[i]->SetLineWidth(3);
    if (!markerStyle2) Signals[i]->SetMarkerStyle(markerStyle[i%7]);
    if ( markerStyle2) Signals[i]->SetMarkerStyle(markerStyle2_[i%7]);
  }
  if (compareMultiple) signalsAG.Draw("SAMEHISTP");

  //Draw syst errors
  TH1F *background_syst = 0;
  if (Background_systs.size() > 0){
    background_syst = new TH1F(*Background_systs[0]); 
    background_syst->SetFillColor(kGray+3); 
    background_syst->SetFillStyle(3003); 
  }
  for (unsigned int iSyst = 0; iSyst < Background_systs.size(); iSyst++){
    if (iSyst == 0) continue;
    background_syst->Sumw2(); 
    background_syst->Add(Background_systs[iSyst]); 
  }
  if (background_syst != 0) background_syst->Draw("E2 SAME");

  //Legend
  TLegend *leg;
  if ((Backgrounds.size()+Signals.size() == 1 || Backgrounds.size()+Signals.size() == 2) && (noData || ratioOnly) && !compareMultiple) leg = new TLegend(0.7+legendRight,0.79+legendUp,0.92+legendRight+legendWider_,0.87+legendUp+legendTaller_); 
  else if ((Backgrounds.size()+Signals.size() == 1 || Backgrounds.size()+Signals.size() == 2) && !noData && !ratioOnly) leg = new TLegend(0.7+legendRight,0.69+legendUp,0.92+legendRight+legendWider_,0.77+legendUp+legendTaller_); 
  else leg = new TLegend(0.7+legendRight,0.59+legendUp,0.92+legendRight+legendWider_,0.87+legendUp+legendTaller_);
  leg->SetTextSize(legendTextSize);
  leg->SetTextFont(42);
  if (!noData && !ratioOnly ) leg->AddEntry(Data, dataName.c_str(), "lep");
  if (showPercentage) for (int i = Titles.size()-1; i > -1; i--) Titles[i] =  Form("%s [%i%%]", Titles[i].c_str(), percent[i]);
  if (!dots && !nostack) for (int i = Titles.size()-1; i > -1; i--) leg->AddEntry(Backgrounds[i], Titles[i].c_str(), "f");
  if (dots || nostack) for (int i = Titles.size()-1; i > -1; i--) leg->AddEntry(Backgrounds[i], Titles[i].c_str(), "LPE");
  if (use_signals && !compareMultiple) for (int i = SignalTitles.size()-1; i > -1; i--) leg->AddEntry(Signals[i], SignalTitles[i].c_str(), "P");
  leg->SetFillStyle(0);
  if ( legendBox) leg->SetBorderSize(1);
  if (!legendBox) leg->SetBorderSize(0);
  if (!noLegend) leg->Draw();

  if (percentageInBox){
    TLatex *pctTex = new TLatex();
    leg->SetMargin(leg->GetMargin()*1.25);
    float legHeight=abs(leg->GetY1()-leg->GetY2());
    float entryHeight=legHeight/leg->GetNRows();
    float legWidth=abs(leg->GetX2()-leg->GetX1());
    float halfFillWidth = legWidth*leg->GetMargin()/2;
    int nRows = leg->GetNRows();

    float yRowOffset = 0.65 - nRows*0.05; // painstakingly-determined empirical formula
    float xPctFudge = 0.01, yPctFudge = 0.01;
    if(Titles.size() < 5) yPctFudge = 0.005; // damn, this works nicely

    for (unsigned int iEntry = 0; iEntry < Titles.size(); iEntry++)  {
      float xPctNDC = xPctFudge+leg->GetX1()+halfFillWidth*0.8;
      float yPctNDC = yPctFudge+leg->GetY1()+(iEntry+yRowOffset)*entryHeight;
      pctTex->SetTextSize(0.022);
      pctTex->SetTextAlign(22);
      pctTex->SetTextFont(42);

      float colR, colG, colB;
      gROOT->GetColor(Colors[iEntry])->GetRGB(colR,colG,colB);
      float darkness = 1.0 - ( 0.299 * colR + 0.587 * colG + 0.114 * colB);
      if(darkness < 0.5) pctTex->SetTextColor(kBlack);
      else pctTex->SetTextColor(kWhite);
      
      pctTex->DrawLatexNDC(xPctNDC,yPctNDC,Form("%i#scale[0.5]{#lower[-0.3]{%%}}",percent[iEntry]));
    }
  }

  //Get number of entries for data, MC
  float nEventsMC = 0.0;
  int nEventsData = Data->Integral(0,Data->GetNbinsX()+doOverflow);
  for (unsigned int i = 0; i < Backgrounds.size(); i++){
      nEventsMC += Backgrounds[i]->Integral(0,Backgrounds[i]->GetNbinsX()+doOverflow);
  }

  //Draw title & subtitle on plot 
  TLatex *tex = new TLatex();
  tex->SetNDC();
  tex->SetTextSize(0.035);
  float title_y_coord = 0.88;
  if (noData) title_y_coord = 0.78; 
  if (outOfFrame) title_y_coord += 0.09;
  if (colorTitle) title = Form("#color[4]{%s}",title);
  tex->DrawLatex(0.16,title_y_coord,title);
  tex->DrawLatex(0.16,title_y_coord-0.05,title2);
  float yCounts = (strcmp(title2, "") == 0) ? title_y_coord-0.05 : title_y_coord-0.10; 
  if (!noData && doCounts) tex->DrawLatex(0.16,yCounts,Form("%i (Data), %0.1f (MC)",nEventsData,nEventsMC)); 
  if ( noData && doCounts) tex->DrawLatex(0.16,yCounts,Form("%0.1f (MC)",nEventsMC)); 

  //Draw vertical lines
  c0.Update();
  for (unsigned int i = 0; i < vLines.size(); i++) DrawVerticalLine(vLines[i]); 

  //Draw Horizontal lines
  for (unsigned int i = 0; i < hLines.size(); i++){
    TLine linecut;
    c0.Update();
    linecut.SetLineStyle(2);
    linecut.SetLineWidth(2);
    linecut.SetLineColor(kGray+2);
    linecut.DrawLine(Backgrounds.size() > 0 ? Backgrounds[0]->GetXaxis()->GetXmin() : Signals[0]->GetXaxis()->GetXmin(), hLines[i], Backgrounds.size() > 0 ? Backgrounds[0]->GetXaxis()->GetXmax() : Signals[0]->GetXaxis()->GetXmax(), hLines[i]);
  }

  //Draw header
  float type_y = .95;
  if (!noData || compareMultiple) type_y = .96;
  tex->SetTextSize(0.028);
  if (overrideHeader[0] == '\0'){
    tex->SetTextAlign(31);
    if (!noLumi) tex->DrawLatex(0.96,type_y,Form("%.2f %s^{-1} (%s TeV)", stof(lumi), lumiUnit.c_str(), energy.c_str()));
    if ( noLumi) tex->DrawLatex(0.96,type_y,Form("           (%s TeV)", energy.c_str()));
    tex->SetTextAlign(11);
  }
  tex->SetTextSize(0.035);
  if (!noType) {
    if (noData && overrideHeader[0] == '\0'){
      float ycoord = outOfFrame ? .00 : .08;
      tex->DrawLatex(0.16,type_y-ycoord, "CMS");              
      ycoord = outOfFrame ? .00 : .11;
      float xcoord = outOfFrame ? .24 : .16;
      tex->DrawLatex(xcoord,type_y-ycoord, "#font[52]{Preliminary}");
    }
    if (!noData && overrideHeader[0] == '\0'){ 
      float ycoord = outOfFrame ? .00 : .08;
      float xcoord = outOfFrame ? .16 : .83;
      tex->DrawLatex(xcoord,type_y-ycoord, "CMS");              
      ycoord = outOfFrame ? .00 : .13;
      xcoord = outOfFrame ? .24 : .73;
      tex->DrawLatex(xcoord,type_y-ycoord, "#font[52]{Preliminary}");
    }
  }
  if (overrideHeader[0] != '\0') tex->DrawLatex(0.17,type_y,Form("%s", overrideHeader.c_str()));
  if (!noData && stack->GetMaximum() > 80000 && linear) finPad[0]->SetPad(0.0, 0.0, 1.0, 0.84);

  //Set number of divisions on x-axis
  if (doHalf){
    Int_t sign = (stack->GetXaxis()->GetNdivisions() > 0) ? 1 : -1;
    Int_t orig = abs(stack->GetXaxis()->GetNdivisions());
    Int_t orig_high =orig-orig%100;
    Int_t orig_low = orig%100;
    Int_t new_ndiv = (orig_low%2==1) ? orig_high+orig_low/2 : orig_high + (orig_low-1)/2;
    stack->GetXaxis()->SetNdivisions(new_ndiv, (sign>0) ? kTRUE : kFALSE);
  }
  if (nDivisions != -1 && nDivisions > 0) stack->GetXaxis()->SetNdivisions(nDivisions, kTRUE);
  if (nDivisions != -1 && nDivisions < 0) stack->GetXaxis()->SetNdivisions(nDivisions, kFALSE);

  //-----------Second pad: data/MC yields---------------
  if (!noData || compareMultiple){
    if (compareMultiple) Data = (TH1F*)Signals[0]->Clone();
    if (compareMultiple && Signals.size() > 1) for (unsigned int i = 1; i < Signals.size(); i++) Data->Add(Signals[i]); 
    finPad[1]->cd();
    TH1F* err_hist = 0;
    if (compareMultiple) err_hist = (TH1F*)Signals[0]->Clone(); 
    if (!compareMultiple) err_hist = (TH1F*)Backgrounds[0]->Clone(); 
    err_hist->SetTitle("");
    err_hist->Draw();
    err_hist->SetLineColor(ratioColor);
    if (!ratioLine) err_hist->SetMarkerColor(ratioColor);
    err_hist->GetYaxis()->SetTitle("Data/MC");
    err_hist->GetYaxis()->SetTitleSize(0.08);
    err_hist->GetYaxis()->SetTitleOffset(1.8);
    TH1F* background_syst_ratio = 0; 
    if (Background_systs.size() > 0) background_syst_ratio = (TH1F*)background_syst->Clone();
    for (int ib = 1; ib < err_hist->GetNbinsX()+1; ib++){
      float MC_value = 0;
      float MC_error_2 = 0;
      for (unsigned int i = 0; i < Backgrounds.size(); i++){
        if (ratio >= 0 && ratio != Backgrounds_number[i]) continue; 
        MC_value += Backgrounds[i]->GetBinContent(ib);
        MC_error_2 += pow(Backgrounds[i]->GetBinError(ib), 2);
      }
      float data_value = Data->GetBinContent(ib);
      float value = (MC_value > 0 ? data_value/MC_value : 1000);
      if (data_value != 0 || MC_value != 0) err_hist->SetBinContent(ib, value);
      float MC_err = sqrt(MC_error_2);
      float data_err = Data->GetBinError(ib);
      if(!noErrBars) err_hist->SetBinError(ib, (data_value == 0 || MC_value == 0) ? 0.001 : (value * sqrt( pow(MC_err/MC_value, 2) + pow(data_err/data_value, 2)) ) );
      if (Background_systs.size() > 0 && background_syst->GetBinContent(ib) > 0) background_syst_ratio->SetBinError(ib, background_syst->GetBinError(ib)/background_syst->GetBinContent(ib)); 
      else if (Background_systs.size() > 0) background_syst_ratio->SetBinError(ib, 0); 
      if (Background_systs.size() > 0) background_syst_ratio->SetBinContent(ib, 1); 
    }
    if (!ratioLine) err_hist->SetMarkerStyle(20);
    if(noErrBars && ratioLine) err_hist->Draw("HIST");
    else if(noErrBars) err_hist->Draw("P");
    else err_hist->Draw("PE");
    TText *blah = new TText();
    blah->SetTextFont(42);
    blah->SetTextSize(0.17);
    blah->SetTextAngle(90);
    blah->DrawTextNDC(0.045,0.15,topYaxisTitle.c_str());
    TLine line;
    line.SetLineColor(kGray+2);
    line.SetLineWidth(2);
    int maxbin = err_hist->GetXaxis()->GetNbins();
    line.DrawLine(err_hist->GetXaxis()->GetBinLowEdge(1),1,err_hist->GetXaxis()->GetBinUpEdge(maxbin),1);
    if(noErrBars && ratioLine) err_hist->Draw("HIST SAME");
    else if(noErrBars) err_hist->Draw("pSAME");
    else err_hist->Draw("pESAME"); 
    err_hist->GetXaxis()->SetLabelSize(0);
    err_hist->GetYaxis()->SetLabelSize(0.2);
    err_hist->GetYaxis()->SetRangeUser(0., 2.);
    err_hist->GetYaxis()->SetNdivisions(505);
    if (Background_systs.size() > 0) background_syst_ratio->Draw("E2 SAME"); 
  }
  //--------------------------------

  //Print plot as pdf 
  if (!noOutput){
    if (outputName.find(".") < outputName.length()) c0.Print(outputName.c_str());
    else if (png) c0.Print(Form("%s.png", outputName.c_str()));
    else c0.Print(Form("%s.pdf", outputName.c_str()));
  }

  //Clean up
  for (unsigned int i = 0; i < Signals.size(); i++) delete Signals[i];
  for (unsigned int i = 0; i < Backgrounds_pair.size(); i++){
    if (Backgrounds_pair[i].first  != 0) delete Backgrounds_pair[i].first;
    if (Backgrounds_pair[i].second != 0) delete Backgrounds_pair[i].second;
  }

}

//Overload function for case of no stat errors
void dataMCplotMaker(TH1F* Data_in, std::vector <TH1F*> Backgrounds_in, std::vector <std::string> Titles, std::string titleIn, std::string title2In, std::string options_string, std::vector <TH1F*> Signals_in, std::vector <std::string> SignalTitles, std::vector <Color_t> color_input){

  //Make a null pair for each 
  std::vector< std::pair<TH1F*, TH1F*> > Backgrounds_pair_in;
  for (unsigned int i = 0; i < Backgrounds_in.size(); i++){
    TH1F* null_hist = new TH1F(Form("dummy_bkgd_syst_%i", i), Form("dummy_bkgd_syst_%i", i), 1, 0, 1); 
    std::pair<TH1F*, TH1F*> temp = std::make_pair( Backgrounds_in[i], null_hist ); 
    Backgrounds_pair_in.push_back(temp); 
  }

  dataMCplotMaker(Data_in, Backgrounds_pair_in, Titles, titleIn, title2In, options_string, Signals_in, SignalTitles, color_input); 

  for (unsigned int i = 0; i < Backgrounds_in.size(); i++){
    delete Backgrounds_pair_in[i].second;
  }

}

void dataMCplotMaker(TH1F* Data_in, std::vector <std::pair <TH1F*, float> > Backgrounds_in, std::vector <std::string> Titles, std::string titleIn, std::string title2In, std::string options_string, std::vector <TH1F*> Signals_in, std::vector <std::string> SignalTitles, std::vector <Color_t> color_input){

  std::vector< std::pair<TH1F*, TH1F*> > Backgrounds_pair_in;
  for (unsigned int i = 0; i < Backgrounds_in.size(); i++){
    TH1F* temp_hist = new TH1F(*Backgrounds_in[i].first); 
    for (int j = 0; j < Backgrounds_in[i].first->GetNbinsX(); j++) temp_hist->SetBinError(j, Backgrounds_in[i].first->GetBinContent(j)*Backgrounds_in[i].second);
    std::pair <TH1F*, TH1F*> temp = std::make_pair( Backgrounds_in[i].first, temp_hist ); 
    Backgrounds_pair_in.push_back(temp); 
  }

  dataMCplotMaker(Data_in, Backgrounds_pair_in, Titles, titleIn, title2In, options_string, Signals_in, SignalTitles, color_input); 

}
