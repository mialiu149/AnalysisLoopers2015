void draw_evt_run()
{
    TChain* ch = new TChain("t");
    ch->Add("/hadoop/cms/store/user/phchang/condor/forCommissioningv7/2016DoubleMuon_*.root");
    TCanvas* c1 = new TCanvas("", "", 0, 0, 800, 800);
    ch->Draw("evt_run");
    c1->SaveAs("evt_run.png");
}
