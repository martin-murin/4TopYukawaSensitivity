#ifndef OBSERVABLES_H
#define OBSERVABLES_H

#include<GeneralPlot.h>
#include<LocalTools.h>

// ### Observable m_tttt ######################################################

class Obs_m_tttt : public GeneralPlot {
    public:
        Obs_m_tttt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable m_tttt_boosted ######################################################

class Obs_m_tttt_boosted : public GeneralPlot {
    public:
        Obs_m_tttt_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable m_tt ######################################################

class Obs_m_tt : public GeneralPlot {
    public:
        Obs_m_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable m_tbartbar ######################################################

class Obs_m_tbartbar : public GeneralPlot {
    public:
        Obs_m_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable mht_mhtbar ######################################################

class Obs_mht_mhtbar : public GeneralPlot {
    public:
        Obs_mht_mhtbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_tt ######################################################

class Obs_eta_tt : public GeneralPlot {
    public:
        Obs_eta_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_tbartbar ######################################################

class Obs_eta_tbartbar : public GeneralPlot {
    public:
        Obs_eta_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_tt ######################################################

class Obs_phi_tt : public GeneralPlot {
    public:
        Obs_phi_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_tbartbar ######################################################

class Obs_phi_tbartbar : public GeneralPlot {
    public:
        Obs_phi_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_ttbar ######################################################

class Obs_phi_ttbar : public GeneralPlot {
    public:
        Obs_phi_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_ttbar_min ######################################################

class Obs_phi_ttbar_min : public GeneralPlot {
    public:
        Obs_phi_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_ttbar_max ######################################################

class Obs_phi_ttbar_max : public GeneralPlot {
    public:
        Obs_phi_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_ttbar_avg ######################################################

class Obs_phi_ttbar_avg : public GeneralPlot {
    public:
        Obs_phi_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_HiggsTTInOtherTTFrame ######################################################

class Obs_phi_HiggsTTInOtherTTFrame : public GeneralPlot {
    public:
        Obs_phi_HiggsTTInOtherTTFrame(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable phi_HiggsTTInOtherTTFrameVectorial ######################################################

class Obs_phi_HiggsTTInOtherTTFrameVectorial : public GeneralPlot {
    public:
        Obs_phi_HiggsTTInOtherTTFrameVectorial(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_tt ######################################################

class Obs_dy_tt : public GeneralPlot {
    public:
        Obs_dy_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_tbartbar ######################################################

class Obs_dy_tbartbar : public GeneralPlot {
    public:
        Obs_dy_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_ttbar_all ######################################################

class Obs_dy_ttbar_all : public GeneralPlot {
    public:
        Obs_dy_ttbar_all(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_ttbar_min ######################################################

class Obs_dy_ttbar_min : public GeneralPlot {
    public:
        Obs_dy_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_ttbar_max ######################################################

class Obs_dy_ttbar_max : public GeneralPlot {
    public:
        Obs_dy_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dy_ttbar_avg ######################################################

class Obs_dy_ttbar_avg : public GeneralPlot {
    public:
        Obs_dy_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_tt ######################################################

class Obs_b2_tt : public GeneralPlot {
    public:
        Obs_b2_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_tt ######################################################

class Obs_b4_tt : public GeneralPlot {
    public:
        Obs_b4_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_txtx ######################################################

class Obs_b2_txtx : public GeneralPlot {
    public:
        Obs_b2_txtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_txtx ######################################################

class Obs_b4_txtx : public GeneralPlot {
    public:
        Obs_b4_txtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_ttbar ######################################################

class Obs_b2_ttbar : public GeneralPlot {
    public:
        Obs_b2_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_ttbar ######################################################

class Obs_b4_ttbar : public GeneralPlot {
    public:
        Obs_b4_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_ttbar_boosted ######################################################

class Obs_b2_ttbar_boosted : public GeneralPlot {
    public:
        Obs_b2_ttbar_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_ttbar_boosted ######################################################

class Obs_b4_ttbar_boosted : public GeneralPlot {
    public:
        Obs_b4_ttbar_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable cosPhiC ######################################################

class Obs_cosPhiC : public GeneralPlot {
    public:
        Obs_cosPhiC(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable HT ######################################################

class Obs_HT : public GeneralPlot {
    public:
        Obs_HT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dR_ttbar_min ######################################################

class Obs_dR_ttbar_min : public GeneralPlot {
    public:
        Obs_dR_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dR_ttbar_avg ######################################################

class Obs_dR_ttbar_avg : public GeneralPlot {
    public:
        Obs_dR_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dRtt ######################################################

class Obs_dRtt : public GeneralPlot {
    public:
        Obs_dRtt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable dRtxtx ######################################################

class Obs_dRtxtx : public GeneralPlot {
    public:
        Obs_dRtxtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leading pT min dR ######################################################

class Obs_dR_ttbar_lead_min : public GeneralPlot {
    public:
        Obs_dR_ttbar_lead_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingTopPT ######################################################

class Obs_leadingTopPT : public GeneralPlot {
    public:
        Obs_leadingTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable diffHiLoTopPT ######################################################

class Obs_diffHiLoTopPT : public GeneralPlot {
    public:
        Obs_diffHiLoTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingBeautyPT ######################################################

class Obs_leadingBeautyPT : public GeneralPlot {
    public:
        Obs_leadingBeautyPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingLeptonPT ######################################################

class Obs_leadingLeptonPT : public GeneralPlot {
    public:
        Obs_leadingLeptonPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable subleadingTopPT ######################################################

class Obs_subleadingTopPT : public GeneralPlot {
    public:
        Obs_subleadingTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingTopEta ######################################################

class Obs_leadingTopEta : public GeneralPlot {
    public:
        Obs_leadingTopEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingBeautyEta ######################################################

class Obs_leadingBeautyEta : public GeneralPlot {
    public:
        Obs_leadingBeautyEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable leadingLeptonEta ######################################################

class Obs_leadingLeptonEta : public GeneralPlot {
    public:
        Obs_leadingLeptonEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable m_ttbar_minDR ######################################################

class Obs_m_ttbar_minDR : public GeneralPlot {
    public:
        Obs_m_ttbar_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable m_ttbar_leadPT_minDR ######################################################

class Obs_m_ttbar_leadPT_minDR : public GeneralPlot {
    public:
        Obs_m_ttbar_leadPT_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_ttbar_minDR_boosted ######################################################

class Obs_b2_ttbar_minDR_boosted : public GeneralPlot {
    public:
        Obs_b2_ttbar_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_ttbar_minDR_boosted ######################################################

class Obs_b4_ttbar_minDR_boosted : public GeneralPlot {
    public:
        Obs_b4_ttbar_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b2_ttbar_leadPT_minDR_boosted ######################################################

class Obs_b2_ttbar_leadPT_minDR_boosted : public GeneralPlot {
    public:
        Obs_b2_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b4_ttbar_leadPT_minDR_boosted ######################################################

class Obs_b4_ttbar_leadPT_minDR_boosted : public GeneralPlot {
    public:
        Obs_b4_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable b1_ttbar_leadPT_minDR_boosted ######################################################

class Obs_b1_ttbar_leadPT_minDR_boosted : public GeneralPlot {
    public:
        Obs_b1_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable a1_ttbar_leadPT_minDR_boosted ######################################################

class Obs_a1_ttbar_leadPT_minDR_boosted : public GeneralPlot {
    public:
        Obs_a1_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable pT_ttbar_max ######################################################

class Obs_pT_ttbar_max : public GeneralPlot {
    public:
        Obs_pT_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable pT_ttbar_minDR ######################################################

class Obs_pT_ttbar_minDR : public GeneralPlot {
    public:
        Obs_pT_ttbar_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_ttbar_all ######################################################

class Obs_eta_ttbar_all : public GeneralPlot {
    public:
        Obs_eta_ttbar_all(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_ttbar_min ######################################################

class Obs_eta_ttbar_min : public GeneralPlot {
    public:
        Obs_eta_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_ttbar_max ######################################################

class Obs_eta_ttbar_max : public GeneralPlot {
    public:
        Obs_eta_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable eta_ttbar_avg ######################################################

class Obs_eta_ttbar_avg : public GeneralPlot {
    public:
        Obs_eta_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable thetaStar ######################################################

class Obs_thetaStar : public GeneralPlot {
    public:
        Obs_thetaStar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable angleTopAntitopPlanes ######################################################

class Obs_angleTopAntitopPlanes : public GeneralPlot {
    public:
        Obs_angleTopAntitopPlanes(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable tripleProductLeadingTopPTFrame ######################################################

class Obs_tripleProductLeadingTopPTFrame : public GeneralPlot {
    public:
        Obs_tripleProductLeadingTopPTFrame(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable p1Xp2Op3Xp4 ######################################################

class Obs_p1Xp2Op3Xp4 : public GeneralPlot {
    public:
        Obs_p1Xp2Op3Xp4(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

// ### Observable p1Xp3Op2Xp4 ######################################################

class Obs_p1Xp3Op2Xp4 : public GeneralPlot {
    public:
        Obs_p1Xp3Op2Xp4(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx);
        std::vector<double> event_observable;
        void SetPlotConf();
        void ComputeFillObservable(TClonesArray* branchParticle, int idxChain); 
};

#endif
