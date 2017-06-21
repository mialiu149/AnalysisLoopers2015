{
    gROOT->ProcessLine(".L ../../commonUtils.h");
    gROOT->ProcessLine(".L normalizeZpeak.C");

    // TString tag = "v1.09FR_80X";
    // TString tag = "v1.10FR";
    // TString tag = "v1.11FR"; // ICHEP
    TString tag = "v1.14FR"; // Moriond
    // float intlumi = getLumi();
    // float intlumi = 36.46;
    float intlumi = 36.8;

    pair<float,float> zsfs1 = normalizeZpeak(intlumi, tag, false, true);
    cout << "ZP SF non-iso,8 e,mu: " << zsfs1.first << " " << zsfs1.second << endl;
    cout << "                    : " << 1.0/zsfs1.first << " " << 1.0/zsfs1.second << endl;

    pair<float,float> zsfs2 = normalizeZpeak(intlumi, tag, false, false);
    cout << "ZP SF non-iso,17 e,mu: " << zsfs2.first << " " << zsfs2.second << endl;
    cout << "                     : " << 1.0/zsfs2.first << " " << 1.0/zsfs2.second << endl;

    pair<float,float> zsfs3 = normalizeZpeak(intlumi, tag, true, true);
    cout << "ZP SF iso,8 e,mu: " << zsfs3.first << " " << zsfs3.second << endl;
    cout << "                : " << 1.0/zsfs3.first << " " << 1.0/zsfs3.second << endl;

    pair<float,float> zsfs4 = normalizeZpeak(intlumi, tag, true, false);
    cout << "ZP SF iso,17 e,mu: " << zsfs4.first << " " << zsfs4.second << endl;
    cout << "                 : " << 1.0/zsfs4.first << " " << 1.0/zsfs4.second << endl;
}
