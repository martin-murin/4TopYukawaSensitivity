#include<GeneralPlot.h>
#include<LocalTools.h>
#include<ObservablesTruthJetMatch.h>

// ### Observable ObsJet_TMatchPerf_NumberOfTopsFullTMatch ######################################################

ObsJet_TMatchPerf_NumberOfTopsFullTMatch::ObsJet_TMatchPerf_NumberOfTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_NumberOfTopsFullTMatch::SetPlotConf(){
    pltparams.name                   = "numberofTopsFullTMatch";
    pltparams.title                  = "Number of fully truth-matched tops";
    pltparams.nbins                  = 5;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 4.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_NumberOfTopsFullTMatch::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getNumberTopsFullTMatch();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch ######################################################

ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch::ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch::SetPlotConf(){
    pltparams.name                   = "numberofHadTopsFullTMatch";
    pltparams.title                  = "Number of fully truth-matched hadronic tops";
    pltparams.nbins                  = 3;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 2.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getNumberHadTopsFullTMatch();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch ######################################################

ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch::ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch::SetPlotConf(){
    pltparams.name                   = "numberofLepTopsFullTMatch";
    pltparams.title                  = "Number of fully truth-matched leptonic tops";
    pltparams.nbins                  = 3;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 2.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getNumberLepTopsFullTMatch();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_NumberOfBJets ######################################################

ObsJet_TMatchPerf_NumberOfBJets::ObsJet_TMatchPerf_NumberOfBJets(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_NumberOfBJets::SetPlotConf(){
    pltparams.name                   = "numberofBjets";
    pltparams.title                  = "Number of b quark jets per event";
    pltparams.nbins                  = 5;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 4.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_NumberOfBJets::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getNumberBjets();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_NumberOfLeptons ######################################################

ObsJet_TMatchPerf_NumberOfLeptons::ObsJet_TMatchPerf_NumberOfLeptons(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_NumberOfLeptons::SetPlotConf(){
    pltparams.name                   = "numberofLeptons";
    pltparams.title                  = "Number of leptons per event";
    pltparams.nbins                  = 5;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 4.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_NumberOfLeptons::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getNumberLep();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_FourTopChannel ######################################################

ObsJet_TMatchPerf_FourTopChannel::ObsJet_TMatchPerf_FourTopChannel(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_FourTopChannel::SetPlotConf(){
    pltparams.name                   = "fourTopChannel";
    pltparams.title                  = "4 Top Channel";
    pltparams.nbins                  = 6;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 5.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_FourTopChannel::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    fillObservable = event->getChannel();
    histos.at(idxChain)->Fill(fillObservable);
}

// ### Observable ObsJet_TMatchPerf_TopCategory ######################################################

ObsJet_TMatchPerf_TopCategory::ObsJet_TMatchPerf_TopCategory(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TopCategory::SetPlotConf(){
    pltparams.name                   = "topCategory";
    pltparams.title                  = "Top Category";
    pltparams.nbins                  = 7;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 6.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TopCategory::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        categories[index] = t->getTopCategory();   
        histos.at(idxChain)->Fill(t->getTopCategory());
    }
}

// ### Observable ObsJet_TMatchPerf_WCategory ######################################################

ObsJet_TMatchPerf_WCategory::ObsJet_TMatchPerf_WCategory(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_WCategory::SetPlotConf(){
    pltparams.name                   = "wCategory";
    pltparams.title                  = "W Category";
    pltparams.nbins                  = 5;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 4.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_WCategory::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        categories[index] = t->getWCategory();   
        histos.at(idxChain)->Fill(t->getWCategory());
    }
}

// ### Observable ObsJet_TMatchPerf_DeltaRBJet ######################################################

ObsJet_TMatchPerf_DeltaRBJet::ObsJet_TMatchPerf_DeltaRBJet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_DeltaRBJet::SetPlotConf(){
    pltparams.name                   = "dRBJet";
    pltparams.title                  = "dR between truth b-quark and matched b-jet";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 0.4;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_DeltaRBJet::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasBjet()){
            histos.at(idxChain)->Fill(deltaRJetParticle(t->jetB, t->daughterB));
        }
    }
}

// ### Observable ObsJet_TMatchPerf_DeltaRQJet ######################################################

ObsJet_TMatchPerf_DeltaRQJet::ObsJet_TMatchPerf_DeltaRQJet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_DeltaRQJet::SetPlotConf(){
    pltparams.name                   = "dRQJet";
    pltparams.title                  = "dR between truth light quark and matched b-jet";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 0.4;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_DeltaRQJet::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasQ1jet()){
            histos.at(idxChain)->Fill(deltaRJetParticle(t->jetLQ1, t->daughterLightQ1));
        }
        if(t->hasQ2jet()){
            histos.at(idxChain)->Fill(deltaRJetParticle(t->jetLQ2, t->daughterLightQ2));
        }
    }
}

// ### Observable ObsJet_TMatchPerf_DeltaRQjetQjet ######################################################

ObsJet_TMatchPerf_DeltaRQjetQjet::ObsJet_TMatchPerf_DeltaRQjetQjet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_DeltaRQjetQjet::SetPlotConf(){
    pltparams.name                   = "dRqjetqjet";
    pltparams.title                  = "dR between two light quark jets from W decay";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 4.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_DeltaRQjetQjet::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->wcategory == WHadTMatchCategory::separateQQ){
            float dRqjetqjet = deltaR(t->jetLQ1->Eta, t->jetLQ1->Phi, t->jetLQ2->Eta, t->jetLQ2->Phi);
            histos.at(idxChain)->Fill(dRqjetqjet);
        }
    }
}
                                                                                                            
// ### Observable ObsJet_TMatchPerf_QjetPT ######################################################

ObsJet_TMatchPerf_QjetPT::ObsJet_TMatchPerf_QjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_QjetPT::SetPlotConf(){
    pltparams.name                   = "QjetPT";
    pltparams.title                  = "p_{T} of light quark jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 800.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_QjetPT::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasQ1jet()){
            histos.at(idxChain)->Fill(t->jetLQ1->PT);
        }
        if(t->hasQ2jet()){
            histos.at(idxChain)->Fill(t->jetLQ2->PT);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_QjetM ######################################################

ObsJet_TMatchPerf_QjetM::ObsJet_TMatchPerf_QjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_QjetM::SetPlotConf(){
    pltparams.name                   = "QjetM";
    pltparams.title                  = "mass of light quark jets";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 100.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_QjetM::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasQ1jet()){
            histos.at(idxChain)->Fill(t->jetLQ1->Mass);
        }
        if(t->hasQ2jet()){
            histos.at(idxChain)->Fill(t->jetLQ2->Mass);
        }
    }
}
                                                                                                            
// ### Observable ObsJet_TMatchPerf_QjetEta ######################################################

ObsJet_TMatchPerf_QjetEta::ObsJet_TMatchPerf_QjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_QjetEta::SetPlotConf(){
    pltparams.name                   = "QjetEta";
    pltparams.title                  = "#eta of light quark jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = -4.;
    pltparams.x_max                  = 4.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_QjetEta::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasQ1jet()){
            histos.at(idxChain)->Fill(t->jetLQ1->Eta);
        }
        if(t->hasQ2jet()){
            histos.at(idxChain)->Fill(t->jetLQ2->Eta);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_BjetPT ######################################################

ObsJet_TMatchPerf_BjetPT::ObsJet_TMatchPerf_BjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_BjetPT::SetPlotConf(){
    pltparams.name                   = "BjetPT";
    pltparams.title                  = "p_{T} of b quark jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 800.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_BjetPT::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasBjet()){
            histos.at(idxChain)->Fill(t->jetB->PT);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_BjetM ######################################################

ObsJet_TMatchPerf_BjetM::ObsJet_TMatchPerf_BjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_BjetM::SetPlotConf(){
    pltparams.name                   = "BjetM";
    pltparams.title                  = "mass of b quark jets";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 100.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_BjetM::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasBjet()){
            histos.at(idxChain)->Fill(t->jetB->Mass);
        }
    }
}
                                                                                                            
// ### Observable ObsJet_TMatchPerf_BjetEta ######################################################

ObsJet_TMatchPerf_BjetEta::ObsJet_TMatchPerf_BjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_BjetEta::SetPlotConf(){
    pltparams.name                   = "BjetEta";
    pltparams.title                  = "#eta of b quark jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = -4.;
    pltparams.x_max                  = 4.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_BjetEta::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        if(t->hasBjet()){
            histos.at(idxChain)->Fill(t->jetB->Eta);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_WjetPT ######################################################

ObsJet_TMatchPerf_WjetPT::ObsJet_TMatchPerf_WjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_WjetPT::SetPlotConf(){
    pltparams.name                   = "WjetPT";
    pltparams.title                  = "p_{T} of W boson jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 800.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_WjetPT::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoWbosonLorentzVector = t->reconstructWLorentzVector();
        if(recoWbosonLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoWbosonLorentzVector.Pt());
        }
    }
}

// ### Observable ObsJet_TMatchPerf_WjetM ######################################################

ObsJet_TMatchPerf_WjetM::ObsJet_TMatchPerf_WjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_WjetM::SetPlotConf(){
    pltparams.name                   = "WjetM";
    pltparams.title                  = "mass of W boson jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 200.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_WjetM::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoWbosonLorentzVector = t->reconstructWLorentzVector();
        if(recoWbosonLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoWbosonLorentzVector.M());
        }
    }
}
                                                                                                            
// ### Observable ObsJet_TMatchPerf_WjetEta ######################################################

ObsJet_TMatchPerf_WjetEta::ObsJet_TMatchPerf_WjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_WjetEta::SetPlotConf(){
    pltparams.name                   = "WjetEta";
    pltparams.title                  = "#eta of W boson jets";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = -4.;
    pltparams.x_max                  = 4.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_WjetEta::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoWbosonLorentzVector = t->reconstructWLorentzVector();
        if(recoWbosonLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoWbosonLorentzVector.Eta());
        }
    }
}

// ### Observable ObsJet_TMatchPerf_TMatchTopPT ######################################################

ObsJet_TMatchPerf_TMatchTopPT::ObsJet_TMatchPerf_TMatchTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TMatchTopPT::SetPlotConf(){
    pltparams.name                   = "TMatchTopPT";
    pltparams.title                  = "p_{T} of truth-matched Top";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 800.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TMatchTopPT::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoTopLorentzVector = t->reconstructTopLorentzVector();
        if(recoTopLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoTopLorentzVector.Pt());
        }
    }
}

// ### Observable ObsJet_TMatchPerf_TMatchTopM ######################################################

ObsJet_TMatchPerf_TMatchTopM::ObsJet_TMatchPerf_TMatchTopM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TMatchTopM::SetPlotConf(){
    pltparams.name                   = "TMatchTopM";
    pltparams.title                  = "mass of truth-matched Top";
    pltparams.nbins                  = 60;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 300.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TMatchTopM::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoTopLorentzVector = t->reconstructTopLorentzVector();
        if(recoTopLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoTopLorentzVector.M());
        }
    }
}
                                                                                                            
// ### Observable ObsJet_TMatchPerf_TMatchTopEta ######################################################

ObsJet_TMatchPerf_TMatchTopEta::ObsJet_TMatchPerf_TMatchTopEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TMatchTopEta::SetPlotConf(){
    pltparams.name                   = "TMatchTopEta";
    pltparams.title                  = "#eta of truth-matched Top";
    pltparams.nbins                  = 40;
    pltparams.x_min                  = -4.;
    pltparams.x_max                  = 4.;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TMatchTopEta::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        LorentzVectorPtEtaPhiM4D recoTopLorentzVector = t->reconstructTopLorentzVector();
        if(recoTopLorentzVector.Pt() != 0){
            histos.at(idxChain)->Fill(recoTopLorentzVector.Eta());
        }
    }
}


// ### Observable m_tttt ######################################################

ObsJet_m_tttt::ObsJet_m_tttt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_m_tttt::SetPlotConf(){
    pltparams.name                   = "truth_m_tttt";
    pltparams.title                  = "m_{t#bar{t}t#bar{t}} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 5200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Events / 100 GeV";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
}

void ObsJet_m_tttt::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    std::for_each(event->topQuarks.begin(), event->topQuarks.end(), [&](GenTopParticle t){event_observable.push_back(t.top.E);});
    fillObservable = accumulate(event_observable.begin(), event_observable.end(), 0);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable ObsJet_TMatchPerf_TopCategory_pt0_200 ######################################################

ObsJet_TMatchPerf_TopCategory_pt0_200::ObsJet_TMatchPerf_TopCategory_pt0_200(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TopCategory_pt0_200::SetPlotConf(){
    pltparams.name                   = "topCategory_pt0_200";
    pltparams.title                  = "Top Category";
    pltparams.nbins                  = 7;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 6.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TopCategory_pt0_200::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        if(t->top.PT < 200.){
            categories[index] = t->getTopCategory();   
            histos.at(idxChain)->Fill(t->getTopCategory());
        }
        else{
            categories[index] = -1;
            histos.at(idxChain)->Fill(-1);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_TopCategory_pt200_350 ######################################################

ObsJet_TMatchPerf_TopCategory_pt200_350::ObsJet_TMatchPerf_TopCategory_pt200_350(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TopCategory_pt200_350::SetPlotConf(){
    pltparams.name                   = "topCategory_pt200_350";
    pltparams.title                  = "Top Category";
    pltparams.nbins                  = 7;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 6.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TopCategory_pt200_350::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        if(t->top.PT > 200. && t->top.PT < 350.){
            categories[index] = t->getTopCategory();   
            histos.at(idxChain)->Fill(t->getTopCategory());
        }
        else{
            categories[index] = -1;
            histos.at(idxChain)->Fill(-1);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_TopCategory_pt350_500 ######################################################

ObsJet_TMatchPerf_TopCategory_pt350_500::ObsJet_TMatchPerf_TopCategory_pt350_500(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TopCategory_pt350_500::SetPlotConf(){
    pltparams.name                   = "topCategory_pt350_500";
    pltparams.title                  = "Top Category";
    pltparams.nbins                  = 7;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 6.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TopCategory_pt350_500::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        if(t->top.PT > 350. && t->top.PT < 500.){
            categories[index] = t->getTopCategory();   
            histos.at(idxChain)->Fill(t->getTopCategory());
        }
        else{
            categories[index] = -1;
            histos.at(idxChain)->Fill(-1);
        }
    }
}

// ### Observable ObsJet_TMatchPerf_TopCategory_pt500 ######################################################

ObsJet_TMatchPerf_TopCategory_pt500::ObsJet_TMatchPerf_TopCategory_pt500(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void ObsJet_TMatchPerf_TopCategory_pt500::SetPlotConf(){
    pltparams.name                   = "topCategory_pt500";
    pltparams.title                  = "Top Category";
    pltparams.nbins                  = 7;
    pltparams.x_min                  = -0.5;
    pltparams.x_max                  = 6.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.8;
    pltparams.ratio_y_max            = 1.2;
    pltparams.label_main_y_axis      = "Events";
    pltparams.label_ratio_y_axis     = "Ratio to SM";
}

void ObsJet_TMatchPerf_TopCategory_pt500::ComputeFillObservable(TruthEvent4Top* event, int idxChain){
    for(auto t = std::begin(event->topQuarks); t != std::end(event->topQuarks); ++t){
        int index = std::distance(std::begin(event->topQuarks), t);
        if(t->top.PT > 500.){
            categories[index] = t->getTopCategory();   
            histos.at(idxChain)->Fill(t->getTopCategory());
        }
        else{
            categories[index] = -1;
            histos.at(idxChain)->Fill(-1);
        }
    }
}

