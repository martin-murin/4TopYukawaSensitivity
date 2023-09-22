#ifndef OBSERVABLESTRUTHJETMATCH_H
#define OBSERVABLESTRUTHJETMATCH_H

#include<GeneralPlot.h>
#include<LocalTools.h>
#include<TruthEvent4Top.h>

class ObsJet_TMatchPerf_NumberOfTopsFullTMatch : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_NumberOfTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_NumberOfHadTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_NumberOfLepTopsFullTMatch(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_NumberOfBJets : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_NumberOfBJets(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_NumberOfLeptons : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_NumberOfLeptons(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_FourTopChannel : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_FourTopChannel(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_TopCategory : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TopCategory(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

class ObsJet_TMatchPerf_WCategory : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_WCategory(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

class ObsJet_TMatchPerf_DeltaRBJet : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_DeltaRBJet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_DeltaRQJet : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_DeltaRQJet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_DeltaRQjetQjet : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_DeltaRQjetQjet(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_QjetPT : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_QjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_QjetM : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_QjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_QjetEta : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_QjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_BjetPT : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_BjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_BjetM : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_BjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_BjetEta : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_BjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_WjetPT : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_WjetPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_WjetM : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_WjetM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_WjetEta : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_WjetEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_TMatchTopPT : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TMatchTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_TMatchTopM : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TMatchTopM(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};

class ObsJet_TMatchPerf_TMatchTopEta : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TMatchTopEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
};
// ### Observable m_tttt ######################################################

class ObsJet_m_tttt : public GeneralPlot {
    public:
        ObsJet_m_tttt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TruthEvent4Top* event, int idxChain); 
};

class ObsJet_TMatchPerf_TopCategory_pt0_200 : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TopCategory_pt0_200(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

class ObsJet_TMatchPerf_TopCategory_pt200_350 : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TopCategory_pt200_350(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

class ObsJet_TMatchPerf_TopCategory_pt350_500 : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TopCategory_pt350_500(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

class ObsJet_TMatchPerf_TopCategory_pt500 : public GeneralPlot {
        public:
                ObsJet_TMatchPerf_TopCategory_pt500(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
                void SetPlotConf();
                void ComputeFillObservable(TruthEvent4Top* event, int idxChain);
                Int_t categories[4];
};

#endif
