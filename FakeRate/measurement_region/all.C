{

    gROOT->ProcessLine(".L ../../commonUtils/commonUtils.h");
    gROOT->ProcessLine(".L normalizeZpeak.C");
    gROOT->ProcessLine(".L plotMTCR.C");
    gROOT->ProcessLine(".L make1DplotFR.C");
    gROOT->ProcessLine(".L plotEWKCorFR.C");

    TString tag = getTag();
  // tag = "v1.09FR_80X"; // FIXME
  // tag = "v1.13FR"; // FIXME
  tag = "v1.14FR"; // FIXME
    cout << "using tag=" << tag << endl;
    float intlumi = getLumi();
    // float intlumi = 12.9-6.26; // HALF
    cout << "intlumi=" << intlumi << "/fb" << endl;

    cout << "non isolated triggers" << endl;
    
    // float zsfEl = 0.994575;
    // float zsfMu = 0.996737;
    // float mtsfEl = 1.28453;
    // float mtsfMu = 1.1685;
    // make1DplotFR(zsfEl, zsfMu, mtsfEl, mtsfMu, true);
    // plotEWKCorFR(zsfEl, zsfMu, mtsfEl, mtsfMu, true);
    // zsfEl = 0.994537;
    // zsfMu = 0.996135;
    // mtsfEl = 1.28411;
    // mtsfMu = 1.19314;
    // make1DplotFR(zsfEl, zsfMu, mtsfEl, mtsfMu, false);
    // plotEWKCorFR(zsfEl, zsfMu, mtsfEl, mtsfMu, false);

    pair<float,float> zsfs = normalizeZpeak(intlumi, tag, false);
    float zsfEl = zsfs.first;
    float zsfMu = zsfs.second;
    cout << "ZP SF: " << zsfEl << " " << zsfMu << endl;

    pair<float,float> mtsfs = plotMTCR(zsfEl, zsfMu, false);
    float mtsfEl = mtsfs.first;
    float mtsfMu = mtsfs.second;
    cout << "MT SF: " << mtsfEl << " " << mtsfMu << endl;

    make1DplotFR(zsfEl, zsfMu, mtsfEl, mtsfMu, false);
    plotEWKCorFR(zsfEl, zsfMu, mtsfEl, mtsfMu, false);

    gROOT->ProcessLine(".x plotFR.C");
    // gROOT->ProcessLine(".x trigStudyEl.C");
    // gROOT->ProcessLine(".x trigStudyMu.C");

    cout << "isolated triggers" << endl;

    pair<float,float> zsfs_i = normalizeZpeak(intlumi, tag, true);
    zsfEl = zsfs_i.first;
    zsfMu = zsfs_i.second;
    cout << "ZP SF: " << zsfEl << " " << zsfMu << endl;

    pair<float,float> mtsfs_i = plotMTCR(zsfEl, zsfMu, true);
    mtsfEl = mtsfs_i.first;
    mtsfMu = mtsfs_i.second;
    cout << "MT SF: " << mtsfEl << " " << mtsfMu << endl;

    make1DplotFR(zsfEl, zsfMu, mtsfEl, mtsfMu, true);
    plotEWKCorFR(zsfEl, zsfMu, mtsfEl, mtsfMu, true);

}
