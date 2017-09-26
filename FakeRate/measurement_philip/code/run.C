void run(TString input_path, TString output_path)
{
    TString fakeratedir = gSystem->Getenv("FAKERATEDIR");
    gSystem->Load(fakeratedir + "/code/CMS3_CORE.so");
//    gROOT->ProcessLine(".L vtx_reweight.h");
    gROOT->ProcessLine(".L "+fakeratedir+"/code/ScanChain.C++O");
    gROOT->ProcessLine("TString input_path = \""+input_path+"\";");
    gROOT->ProcessLine("TString output_path = \""+output_path+"\";");
    gROOT->ProcessLine("TString ttreename = \"t\";");
    gROOT->ProcessLine("TChain *chain = new TChain(ttreename);");
    gROOT->ProcessLine("TObjArray* files = input_path.Tokenize(\",\");");
    gROOT->ProcessLine("for (unsigned int ifile = 0; ifile < files->GetEntries(); ++ifile) { TString filepath = ((TObjString*) files->At(ifile))->GetString(); std::cout << \"Adding to TChain: file = \" << filepath << std::endl; chain->Add(filepath); }");
    gROOT->ProcessLine("ScanChain(chain,output_path);");
}
