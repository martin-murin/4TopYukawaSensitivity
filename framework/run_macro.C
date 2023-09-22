void run_macro(std::string sampleset, std::string yukawaset){
    std::string execline =
        std::string(".x MacroMain.C(\"")
        + sampleset
        + std::string("\", \"")
        + yukawaset
        + std::string("\")");
    std::cout << "Executing line " << execline << "\n";
    gSystem->Load("libExRootAnalysis.so");
    gSystem->Load("libPhysics");
    //gSystem->Load("/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/ExRootAnalysis/libExRootAnalysis.so");
    //gSystem->Load("/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/ExRootAnalysis/libPhysics");
    //gSystem->Load("/afs/cern.ch/work/m/mmurin/public/ExRootAnalysis/libExRootAnalysis.so");
    //gSystem->Load("/afs/cern.ch/work/m/mmurin/public/ExRootAnalysis/libPhysics");
    gSystem->Load("/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/Delphes/libDelphes");
    gROOT->ProcessLine(".L TChainsMaker.cxx");
    gROOT->ProcessLine(".L LocalTools.cxx");
    gROOT->ProcessLine(".L Cuts.cxx");
    gROOT->ProcessLine(".L GenTopParticle.cxx");
    gROOT->ProcessLine(".L TruthEvent4Top.cxx");
    gROOT->ProcessLine(".L GeneralPlot.cxx");
    gROOT->ProcessLine(".L Observables.cxx");
    gROOT->ProcessLine(".L ObservablesTruthJetMatch.cxx");
    gROOT->SetBatch(kTRUE);
    gROOT->ProcessLine(execline.c_str());
    gROOT->ProcessLine(".q");
}
