// --- T2K style ---

TStyle* SetSpecialStyle(Int_t WhichStyle = 1, TString styleName = "specialStyle") {
  TStyle *specialStyle= new TStyle(styleName, "approved plots style");
  
  // -- WhichStyle --
  // 1 = presentation large fonts
  // 2 = presentation small fonts
  // 3 = publication/paper

  Int_t FontStyle = 22;
  Float_t FontSizeLabel = 0.035;
  Float_t FontSizeTitle = 0.05;
  Float_t YOffsetTitle = 1.3;
 
  switch(WhichStyle) {
  case 1:
    FontStyle = 42;
    FontSizeLabel = 0.05;
    FontSizeTitle = 0.065;
    YOffsetTitle = 1.19;
    break;
  case 2:
    FontStyle = 42;
    FontSizeLabel = 0.035;
    FontSizeTitle = 0.05;
    YOffsetTitle = 1.6;
    break;
  case 3:
    FontStyle = 132;
    FontSizeLabel = 0.035;
    FontSizeTitle = 0.05;
    YOffsetTitle = 1.6;
    break;
  }

  // use plain black on white colors
  specialStyle->SetFrameBorderMode(0);
  specialStyle->SetCanvasBorderMode(0);
  specialStyle->SetPadBorderMode(0);
  specialStyle->SetCanvasBorderSize(0);
  specialStyle->SetFrameBorderSize(0);
  specialStyle->SetDrawBorder(0);
  specialStyle->SetTitleBorderSize(0);

  specialStyle->SetPadColor(0);
  specialStyle->SetCanvasColor(0);
  specialStyle->SetStatColor(0);
  specialStyle->SetFillColor(0);

  specialStyle->SetEndErrorSize(4);
  specialStyle->SetStripDecimals(kFALSE);

  specialStyle->SetLegendBorderSize(0);
  specialStyle->SetLegendFont(FontStyle);

  // set the paper & margin sizes
  specialStyle->SetPaperSize(20, 26);
  specialStyle->SetPadTopMargin(0.03);
  specialStyle->SetPadBottomMargin(0.13);
  specialStyle->SetPadRightMargin(0.03); // 0.075 -> 0.13 for colz option
  specialStyle->SetPadLeftMargin(0.13);//to include both large/small font options
  
  // Fonts, sizes, offsets
  specialStyle->SetTextFont(FontStyle);
  specialStyle->SetTextSize(0.08);

  specialStyle->SetLabelFont(FontStyle, "x");
  specialStyle->SetLabelFont(FontStyle, "y");
  specialStyle->SetLabelFont(FontStyle, "z");
  specialStyle->SetLabelFont(FontStyle, "t");
  specialStyle->SetLabelSize(FontSizeLabel, "x");
  specialStyle->SetLabelSize(FontSizeLabel, "y");
  specialStyle->SetLabelSize(FontSizeLabel, "z");
  specialStyle->SetLabelOffset(0.015, "x");
  specialStyle->SetLabelOffset(0.015, "y");
  specialStyle->SetLabelOffset(0.015, "z");

  specialStyle->SetTitleFont(FontStyle, "x");
  specialStyle->SetTitleFont(FontStyle, "y");
  specialStyle->SetTitleFont(FontStyle, "z");
  specialStyle->SetTitleFont(FontStyle, "t");
  specialStyle->SetTitleSize(FontSizeTitle, "y");
  specialStyle->SetTitleSize(FontSizeTitle, "x");
  specialStyle->SetTitleSize(FontSizeTitle, "z");
  specialStyle->SetTitleOffset(1.14, "x");
  specialStyle->SetTitleOffset(YOffsetTitle, "y");
  specialStyle->SetTitleOffset(1.2, "z");

  specialStyle->SetTitleStyle(0);
  specialStyle->SetTitleFontSize(0.06);//0.08
  specialStyle->SetTitleFont(FontStyle, "pad");
  specialStyle->SetTitleBorderSize(0);
  specialStyle->SetTitleX(0.1f);
  specialStyle->SetTitleW(0.8f);

  // use bold lines and markers
  specialStyle->SetMarkerStyle(20);
  specialStyle->SetHistLineWidth( Width_t(2.5) );
  specialStyle->SetLineStyleString(2, "[12 12]"); // postscript dashes
  
  // get rid of X error bars and y error bar caps
  specialStyle->SetErrorX(0.001);
  
  // do not display any of the standard histogram decorations
  specialStyle->SetOptTitle(0);
  specialStyle->SetOptStat(0);
  specialStyle->SetOptFit(0);
  
  // put tick marks on top and RHS of plots
  specialStyle->SetPadTickX(1);
  specialStyle->SetPadTickY(1);
  
  // -- color --
  // functions blue
  specialStyle->SetFuncColor(600-4);

  specialStyle->SetFillColor(1); // make color fillings (not white)
  // - color setup for 2D -
  // - "cold"/ blue-ish -
  Double_t red[]   = { 0.00, 0.00, 0.00 };
  Double_t green[] = { 1.00, 0.00, 0.00 };
  Double_t blue[]  = { 1.00, 1.00, 0.25 };
  // - "warm" red-ish colors -
  //  Double_t red[]   = {1.00, 1.00, 0.25 };
  //  Double_t green[] = {1.00, 0.00, 0.00 };
  //  Double_t blue[]  = {0.00, 0.00, 0.00 };

  Double_t stops[] = { 0.25, 0.75, 1.00 };
  const Int_t NRGBs = 3;
  const Int_t NCont = 500;

  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  specialStyle->SetNumberContours(NCont);

  // - Rainbow -
  //  specialStyle->SetPalette(1);  // use the rainbow color set

  // -- axis --
  specialStyle->SetStripDecimals(kFALSE); // don't do 1.0 -> 1
  //  TGaxis::SetMaxDigits(3); // doesn't have an effect 
  // no supressed zeroes!
  specialStyle->SetHistMinimumZero(kTRUE);


 return(specialStyle);
}


void CenterHistoTitles(TH1 *thisHisto){
  thisHisto->GetXaxis()->CenterTitle();
  thisHisto->GetYaxis()->CenterTitle();
  thisHisto->GetZaxis()->CenterTitle();
}


int AddGridLinesToPad(TPad *thisPad) {
  thisPad->SetGridx();
  thisPad->SetGridy();
  return(0);
}
