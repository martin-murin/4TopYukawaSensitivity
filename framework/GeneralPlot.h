#ifndef GENERALPLOT_H
#define GENERALPLOT_H

#include<string>
#include<vector>

#include<LocalTools.h>
#include<TruthEvent4Top.h>

typedef struct PlotParams{
    const char*     name;
    const char*     title;
    Int_t           nbins;
    Double_t        x_min;
    Double_t        x_max;
    //Double_t        main_y_min;
    //Double_t        main_y_max;
    Double_t        ratio_y_min;
    Double_t        ratio_y_max;
    const char*     label_main_y_axis;
    const char*     label_ratio_y_axis;
    bool            invert_legend;
} PlotParams;

class GeneralPlot{
    private:
        TCanvas* canvas_general;
        TPad* pad1_general;
        TPad* pad2_general;

        std::vector<std::string> couplingSuffixes;
        std::string saveDir;
        std::string baseName;
        std::string fileExt;

        std::shared_ptr<TH1F> CreateHistogram(const string& name, const string& title, int Nbins, double xmin, double xmax, const string& couplingSuffix);
    public:
        PlotParams pltparams;
        std::vector<std::shared_ptr<TH1F>>      histos;
        Double_t                                fillObservable;

        SampleSet       sampleSet;
        YukawaSet       yukawaSet;

        GeneralPlot(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        virtual ~GeneralPlot();
        void Initialize();
        void PlotAndSave();
        virtual void SetPlotConf() = 0;
        virtual void ComputeFillObservable(TClonesArray* branchParticle, int idxChain){};
        virtual void ComputeFillObservable(TruthEvent4Top* event, int idxChain){};
        
};

#endif
