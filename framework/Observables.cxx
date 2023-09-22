#include<GeneralPlot.h>
#include<LocalTools.h>
#include<Observables.h>
#include<Cuts.h>

// ### Observable m_tttt ######################################################

Obs_m_tttt::Obs_m_tttt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_tttt::SetPlotConf(){
    pltparams.name                   = "m_tttt";
    pltparams.title                  = "m_{t#bar{t}t#bar{t}} [GeV]";
    pltparams.nbins                  = 23;
    pltparams.x_min                  = 600.0;
    pltparams.x_max                  = 5200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}
/*
void Obs_m_tttt::ComputeFillObservable(TruthEvent4Top* event, int idxChain) {
    std::vector<GenTopParticle> topQuarks = event->topQuarks;
    for (const GenTopParticle& topParticle : topQuarks) {
        GenParticle top = topParticle.top;
        if (abs(top.PID) == 6) {
            event_observable.push_back(top.E);
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}
*/

void Obs_m_tttt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    TLorentzVector totalFourMomentum(0, 0, 0, 0);
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            TLorentzVector particleFourMomentum(particle->Px, particle->Py, particle->Pz, particle->E);
            totalFourMomentum += particleFourMomentum;
        }
    }
    fillObservable = totalFourMomentum.M();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable m_tttt_boosted ######################################################

Obs_m_tttt_boosted::Obs_m_tttt_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_tttt_boosted::SetPlotConf(){
    pltparams.name                   = "m_tttt_boosted";
    pltparams.title                  = "m_{t#bar{t}t#bar{t}} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 5200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_m_tttt_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            LorentzVectorPxPyPzE4D top_PxPyPzE4D_lab(particle->Px, particle->Py, particle->Pz, particle->E);
            LorentzVectorPxPyPzE4D top_PxPyPzE4D_4TopCoM = lorentzBoostTo4TopCoM(top_PxPyPzE4D_lab);
            event_observable.push_back(top_PxPyPzE4D_4TopCoM.E());
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0.);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable m_tt ######################################################

Obs_m_tt::Obs_m_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_tt::SetPlotConf(){
    pltparams.name                   = "m_tt";
    pltparams.title                  = "m_{tt} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 2200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_m_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    TLorentzVector totalFourMomentum(0, 0, 0, 0);
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == 6) {
            TLorentzVector particleFourMomentum(particle->Px, particle->Py, particle->Pz, particle->E);
            totalFourMomentum += particleFourMomentum;
        }
    }
    fillObservable = totalFourMomentum.M();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable m_tbartbar ######################################################

Obs_m_tbartbar::Obs_m_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_tbartbar::SetPlotConf(){
    pltparams.name                   = "m_tbartbar";
    pltparams.title                  = "m_{#bar{t}#bar{t}} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 2200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_m_tbartbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    TLorentzVector totalFourMomentum(0, 0, 0, 0);
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == -6) {
            TLorentzVector particleFourMomentum(particle->Px, particle->Py, particle->Pz, particle->E);
            totalFourMomentum += particleFourMomentum;
        }
    }
    fillObservable = totalFourMomentum.M();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable mht_mhtbar ######################################################

Obs_mht_mhtbar::Obs_mht_mhtbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_mht_mhtbar::SetPlotConf(){
    pltparams.name                   = "mht_mhtbar";
    pltparams.title                  = "m_{Ht}/m_{H#bar{t}}";
    pltparams.nbins                  = 10;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 2.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_mht_mhtbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // find the other top or antitop particle in the 4 top event
    // than the ones in iteration which are assumed to be from the Higgs decay
    auto findParticle = [&](int id, LorentzVectorPxPyPzE4D skip){
        LorentzVectorPxPyPzE4D otherParticle;
        for(auto particle_i : *branchParticle){
            TRootLHEFParticle *temp = (TRootLHEFParticle*)particle_i;
            LorentzVectorPxPyPzE4D temp4vec(temp->Px, temp->Py, temp->Pz, temp->E);
            if(temp->PID == id && temp4vec != skip){
                otherParticle = temp4vec;
                break;
            }
        }
        return otherParticle;
    };

    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    // define tops from Higgs decay and the other tops [candidates in this iteration]
                    LorentzVectorPxPyPzE4D top1FromHiggs(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2FromHiggs(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D otherTop1 = findParticle(6, top1FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop2 = findParticle(-6, top2FromHiggs);

                    event_observable.push_back(((top1FromHiggs+top2FromHiggs).E()+otherTop1.E())/((top1FromHiggs+top2FromHiggs).E()+otherTop2.E()));
                }
            }
        }
    }

    //histos.at(idxChain)->Fill(*std::min_element(event_observable.begin(), event_observable.end()));
    //histos.at(idxChain)->Fill(*std::min_element(event_observable.begin(), event_observable.end()));
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();

    /*
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == 6) {
            event_observable.push_back(particle->E);
        }
    }
    histos.at(idxChain)->Fill(std::accumulate(event_observable.begin(), event_observable.end(), 0));
    event_observable.clear();
    */
}

// ### Observable eta_tt ######################################################

Obs_eta_tt::Obs_eta_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_tt::SetPlotConf(){
    pltparams.name                   = "eta_tt";
    pltparams.title                  = "#eta_{tt}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    TLorentzVector totalFourMomentum(0, 0, 0, 0);
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == 6) {
            TLorentzVector particleFourMomentum(particle->Px, particle->Py, particle->Pz, particle->E);
            totalFourMomentum += particleFourMomentum;
        }
    }
    fillObservable = totalFourMomentum.Eta();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable eta_tbartbar ######################################################

Obs_eta_tbartbar::Obs_eta_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_tbartbar::SetPlotConf(){
    pltparams.name                   = "eta_tbartbar";
    pltparams.title                  = "#eta_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = -5;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_tbartbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    TLorentzVector totalFourMomentum(0, 0, 0, 0);
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == -6) {
            TLorentzVector particleFourMomentum(particle->Px, particle->Py, particle->Pz, particle->E);
            totalFourMomentum += particleFourMomentum;
        }
    }
    fillObservable = totalFourMomentum.Eta();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_tt ######################################################

Obs_phi_tt::Obs_phi_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_tt::SetPlotConf(){
    pltparams.name                   = "phi_tt";
    pltparams.title                  = "#Delta #phi_{tt}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == 6) {
            event_observable.push_back(particle->Phi);
        }
    }
    fillObservable = abs(deltaPhi(event_observable.front(), event_observable.back()));
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_tbartbar ######################################################

Obs_phi_tbartbar::Obs_phi_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_tbartbar::SetPlotConf(){
    pltparams.name                   = "phi_tbartbar";
    pltparams.title                  = "#Delta #phi_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_tbartbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == -6) {
            event_observable.push_back(particle->Phi);
        }
    }
    fillObservable = abs(deltaPhi(event_observable.front(), event_observable.back()));
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_ttbar ######################################################

Obs_phi_ttbar::Obs_phi_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_ttbar::SetPlotConf(){
    pltparams.name                   = "phi_ttbar";
    pltparams.title                  = "#Delta #phi_{t#bar{t}}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_ttbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(deltaPhi(particle1->Phi, particle2->Phi)));
                }
            }
        }
    }
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable phi_ttbar_min ######################################################

Obs_phi_ttbar_min::Obs_phi_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_ttbar_min::SetPlotConf(){
    pltparams.name                   = "phi_ttbar_min";
    pltparams.title                  = "#Delta #phi_{t#bar{t}}^{min}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_ttbar_min::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(deltaPhi(particle1->Phi, particle2->Phi)));
                }
            }
        }
    }
    fillObservable=*std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_ttbar_max ######################################################

Obs_phi_ttbar_max::Obs_phi_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_ttbar_max::SetPlotConf(){
    pltparams.name                   = "phi_ttbar_max";
    pltparams.title                  = "#Delta #phi_{t#bar{t}}^{max}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 1.6;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = true;
}

void Obs_phi_ttbar_max::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(deltaPhi(particle1->Phi, particle2->Phi)));
                }
            }
        }
    }
    fillObservable=*std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_ttbar_avg ######################################################

Obs_phi_ttbar_avg::Obs_phi_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_ttbar_avg::SetPlotConf(){
    pltparams.name                   = "phi_ttbar_avg";
    pltparams.title                  = "#Delta #phi_{t#bar{t}}^{avg}";
    pltparams.nbins                  = 16;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 1.6;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_ttbar_avg::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(deltaPhi(particle1->Phi, particle2->Phi)));
                }
            }
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0.)/((double)event_observable.size());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable phi_HiggsTTInOtherTTFrame ######################################################

Obs_phi_HiggsTTInOtherTTFrame::Obs_phi_HiggsTTInOtherTTFrame(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_HiggsTTInOtherTTFrame::SetPlotConf(){
    pltparams.name                   = "phi_HiggsTTInOtherTTFrame";
    pltparams.title                  = "#Delta #phi^{t#bar{t}frame}_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -3;
    pltparams.x_max                  = 3;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_HiggsTTInOtherTTFrame::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){

    // find the other top or antitop particle in the 4 top event
    // than the ones in iteration which are assumed to be from the Higgs decay
    auto findParticle = [&](int id, LorentzVectorPxPyPzE4D skip){
        LorentzVectorPxPyPzE4D otherParticle;
        for(auto particle_i : *branchParticle){
            TRootLHEFParticle *temp = (TRootLHEFParticle*)particle_i;
            LorentzVectorPxPyPzE4D temp4vec(temp->Px, temp->Py, temp->Pz, temp->E);
            if(temp->PID == id && temp4vec != skip){
                otherParticle = temp4vec;
                break;
            }
        }
        return otherParticle;
    };
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    // define tops from Higgs decay and the other tops [candidates in this iteration]
                    LorentzVectorPxPyPzE4D top1FromHiggs(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2FromHiggs(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D otherTop1 = findParticle(6, top1FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop2 = findParticle(-6, top2FromHiggs);
                    LorentzVectorPxPyPzE4D otherTTFramePxPyPzE4D = sumLorentz4D(otherTop1, otherTop2);

                    // boost ttbar from higs decay to the other ttbar frame
                    ROOT::Math::Boost boostToOtherTTFrame(otherTTFramePxPyPzE4D.BoostToCM());
                    LorentzVectorPxPyPzE4D top1FromHiggs_OtherTTFrame = boostToOtherTTFrame(top1FromHiggs);
                    LorentzVectorPxPyPzE4D top2FromHiggs_OtherTTFrame = boostToOtherTTFrame(top2FromHiggs);
                    // compute event observable
                    event_observable.push_back(abs(deltaPhi(top1FromHiggs_OtherTTFrame.Phi(), top2FromHiggs_OtherTTFrame.Phi())));

                }
            }
        }
    }

    //histos.at(idxChain)->Fill(*std::min_element(event_observable.begin(), event_observable.end()));
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable phi_HiggsTTInOtherTTFrameVectorial ######################################################

Obs_phi_HiggsTTInOtherTTFrameVectorial::Obs_phi_HiggsTTInOtherTTFrameVectorial(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_phi_HiggsTTInOtherTTFrameVectorial::SetPlotConf(){
    pltparams.name                   = "phi_HiggsTTInOtherTTFrameVectorial";
    pltparams.title                  = "#Delta #phi^{t#bar{t}frame}_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -3;
    pltparams.x_max                  = 3;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_phi_HiggsTTInOtherTTFrameVectorial::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){

    // find the other top or antitop particle in the 4 top event
    // than the ones in iteration which are assumed to be from the Higgs decay
    auto findParticle = [&](int id, LorentzVectorPxPyPzE4D skip){
        LorentzVectorPxPyPzE4D otherParticle;
        for(auto particle_i : *branchParticle){
            TRootLHEFParticle *temp = (TRootLHEFParticle*)particle_i;
            LorentzVectorPxPyPzE4D temp4vec(temp->Px, temp->Py, temp->Pz, temp->E);
            if(temp->PID == id && temp4vec != skip){
                otherParticle = temp4vec;
                break;
            }
        }
        return otherParticle;
    };
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    // define tops from Higgs decay and the other tops [candidates in this iteration]
                    LorentzVectorPxPyPzE4D top1FromHiggs(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2FromHiggs(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D otherTop1 = findParticle(6, top1FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop2 = findParticle(-6, top2FromHiggs);
                    LorentzVectorPxPyPzE4D otherTTFramePxPyPzE4D = sumLorentz4D(otherTop1, otherTop2);

                    // boost ttbar from higs decay to the other ttbar frame
                    ROOT::Math::Boost boostToOtherTTFrame(otherTTFramePxPyPzE4D.BoostToCM());
                    LorentzVectorPxPyPzE4D top1FromHiggs_OtherTTFrame = boostToOtherTTFrame(top1FromHiggs);
                    LorentzVectorPxPyPzE4D top2FromHiggs_OtherTTFrame = boostToOtherTTFrame(top2FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop1_OtherTTFrame = boostToOtherTTFrame(otherTop1);
                    LorentzVectorPxPyPzE4D otherTop2_OtherTTFrame = boostToOtherTTFrame(otherTop2);

                    // compute event observable
                    event_observable.push_back(
                            sgn(dotProductND(
                                normalize(unmove(lorentz4DToCartesian3D(otherTop1_OtherTTFrame))),
                                crossProduct3D(
                                    normalize(unmove(lorentz4DToCartesian3D(top1FromHiggs_OtherTTFrame))),
                                    normalize(unmove(lorentz4DToCartesian3D(top2FromHiggs_OtherTTFrame))))))
                            *TMath::ACos(
                                dotProductND(
                                    crossProduct3D(
                                        lorentz4DToCartesian3D(otherTop1_OtherTTFrame),
                                        lorentz4DToCartesian3D(top1FromHiggs_OtherTTFrame)),
                                    crossProduct3D(
                                        lorentz4DToCartesian3D(otherTop1_OtherTTFrame),
                                        lorentz4DToCartesian3D(top2FromHiggs_OtherTTFrame)))
                                /squareNormND(
                                        crossProduct3D(
                                            lorentz4DToCartesian3D(otherTop1_OtherTTFrame),
                                            lorentz4DToCartesian3D(top2FromHiggs_OtherTTFrame)))
                                /squareNormND(
                                        crossProduct3D(
                                            lorentz4DToCartesian3D(otherTop1_OtherTTFrame),
                                            lorentz4DToCartesian3D(top1FromHiggs_OtherTTFrame)))
                            )
                    );

                }
            }
        }
    }

    //histos.at(idxChain)->Fill(*std::min_element(event_observable.begin(), event_observable.end()));
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable dy_tt ######################################################

Obs_dy_tt::Obs_dy_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_tt::SetPlotConf(){
    pltparams.name                   = "dy_tt";
    pltparams.title                  = "#Delta y_{tt}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == 6) {
            event_observable.push_back(particle->Rapidity);
        }
    }
    fillObservable = abs(event_observable.front() - event_observable.back());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dy_tbartbar ######################################################

Obs_dy_tbartbar::Obs_dy_tbartbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_tbartbar::SetPlotConf(){
    pltparams.name                   = "dy_tbartbar";
    pltparams.title                  = "#Delta y_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_tbartbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(particle->PID == -6) {
            event_observable.push_back(particle->Rapidity);
        }
    }
    fillObservable = abs(event_observable.front() - event_observable.back());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dy_ttbar_all ######################################################

Obs_dy_ttbar_all::Obs_dy_ttbar_all(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_ttbar_all::SetPlotConf(){
    pltparams.name                   = "dy_ttbar_all";
    pltparams.title                  = "#Delta y_{t#bar{t}}^{all}";
    pltparams.nbins                  = 24;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 6;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_ttbar_all::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(particle1->Rapidity - particle2->Rapidity));
                }
            }
        }
    }
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable dy_ttbar_min ######################################################

Obs_dy_ttbar_min::Obs_dy_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_ttbar_min::SetPlotConf(){
    pltparams.name                   = "dy_ttbar_min";
    pltparams.title                  = "#Delta y_{t#bar{t}}^{min}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_ttbar_min::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(particle1->Rapidity - particle2->Rapidity));
                }
            }
        }
    }
    fillObservable = *std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dy_ttbar_max ######################################################

Obs_dy_ttbar_max::Obs_dy_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_ttbar_max::SetPlotConf(){
    pltparams.name                   = "dy_ttbar_max";
    pltparams.title                  = "#Delta y_{t#bar{t}}^{max}";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_ttbar_max::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(particle1->Rapidity - particle2->Rapidity));
                }
            }
        }
    }
    fillObservable = *std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dy_ttbar_avg ######################################################

Obs_dy_ttbar_avg::Obs_dy_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dy_ttbar_avg::SetPlotConf(){
    pltparams.name                   = "dy_ttbar_avg";
    pltparams.title                  = "#Delta y_{t#bar{t}}^{avg}";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 2.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 10000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dy_ttbar_avg::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(abs(particle1->Rapidity - particle2->Rapidity));
                }
            }
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0.)/((double)(event_observable.size()));
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b2_tt ######################################################

Obs_b2_tt::Obs_b2_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_tt::SetPlotConf(){
    pltparams.name                   = "b2_tt";
    pltparams.title                  = "b2_{tt}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == 6 && particle2->E != particle1->E) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b2operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}


// ### Observable b4_tt ######################################################

Obs_b4_tt::Obs_b4_tt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_tt::SetPlotConf(){
    pltparams.name                   = "b4_tt";
    pltparams.title                  = "b4_{tt}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 40000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b4_tt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == 6 && particle2->E != particle1->E) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b4operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b2_txtx ######################################################

Obs_b2_txtx::Obs_b2_txtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_txtx::SetPlotConf(){
    pltparams.name                   = "b2_txtx";
    pltparams.title                  = "b2_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_txtx::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == -6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6 && particle2->E != particle1->E) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b2operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}


// ### Observable b4_txtx ######################################################

Obs_b4_txtx::Obs_b4_txtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_txtx::SetPlotConf(){
    pltparams.name                   = "b4_txtx";
    pltparams.title                  = "b4_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 40000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b4_txtx::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == -6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6 && particle2->E != particle1->E) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b4operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b2_ttbar ######################################################

Obs_b2_ttbar::Obs_b2_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_ttbar::SetPlotConf(){
    pltparams.name                   = "b2_ttbar";
    pltparams.title                  = "b2_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_ttbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b2operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}


// ### Observable b4_ttbar ######################################################

Obs_b4_ttbar::Obs_b4_ttbar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_ttbar::SetPlotConf(){
    pltparams.name                   = "b4_ttbar";
    pltparams.title                  = "b4_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 40000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = true;
}

void Obs_b4_ttbar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    vector<double> top1_PxPyPz3D = {particle1->Px, particle1->Py, particle1->Pz};
                    vector<double> top2_PxPyPz3D = {particle2->Px, particle2->Py, particle2->Pz};
                    event_observable.push_back(b4operator(top1_PxPyPz3D, top2_PxPyPz3D));
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable b2_ttbar_boosted ######################################################

Obs_b2_ttbar_boosted::Obs_b2_ttbar_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_ttbar_boosted::SetPlotConf(){
    pltparams.name                   = "b2_ttbar_boosted";
    pltparams.title                  = "b2_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_ttbar_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());
    // Loop over particle pairs
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_4TopCoM = lorentzBoostTo4TopCoM(top1_PxPyPzE4D_lab);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_4TopCoM = lorentzBoostTo4TopCoM(top2_PxPyPzE4D_lab);

                    event_observable.push_back(b2operator(top1_PxPyPzE4D_4TopCoM, top2_PxPyPzE4D_4TopCoM));
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}


// ### Observable b4_ttbar_boosted ######################################################

Obs_b4_ttbar_boosted::Obs_b4_ttbar_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_ttbar_boosted::SetPlotConf(){
    pltparams.name                   = "b4_ttbar_boosted";
    pltparams.title                  = "b4_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 40000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b4_ttbar_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());  
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_4TopCoM = lorentzBoostTo4TopCoM(top1_PxPyPzE4D_lab);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_4TopCoM = lorentzBoostTo4TopCoM(top2_PxPyPzE4D_lab);

                    event_observable.push_back(b4operator(top1_PxPyPzE4D_4TopCoM, top2_PxPyPzE4D_4TopCoM));
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable cosPhiC ######################################################

Obs_cosPhiC::Obs_cosPhiC(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_cosPhiC::SetPlotConf(){
    pltparams.name                   = "cosPhiC";
    pltparams.title                  = "#phi_{C}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1.6;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_cosPhiC::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // find the other top or antitop particle in the 4 top event
    // than the ones in iteration which are assumed to be from the Higgs decay
    auto findParticle = [&](int id, LorentzVectorPxPyPzE4D skip){
        LorentzVectorPxPyPzE4D otherParticle;
        for(auto particle_i : *branchParticle){
            TRootLHEFParticle *temp = (TRootLHEFParticle*)particle_i;
            LorentzVectorPxPyPzE4D temp4vec(temp->Px, temp->Py, temp->Pz, temp->E);
            if(temp->PID == id && temp4vec != skip){
                otherParticle = temp4vec;
                break;
            }
        }
        return otherParticle;
    };
    // initial state protons
    TRootLHEFParticle *proton1 = (TRootLHEFParticle*)((*branchParticle)[0]);
    TRootLHEFParticle *proton2 = (TRootLHEFParticle*)((*branchParticle)[1]);
    LorentzVectorPxPyPzE4D proton1_labFrame(proton1->Px, proton1->Py, proton1->Pz, proton1->E);
    LorentzVectorPxPyPzE4D proton2_labFrame(proton2->Px, proton2->Py, proton2->Pz, proton2->E);
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    // define tops from Higgs decay and the other tops [candidates in this iteration]
                    LorentzVectorPxPyPzE4D top1FromHiggs(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2FromHiggs(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D otherTop1 = findParticle(6, top1FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop2 = findParticle(-6, top2FromHiggs);
                    LorentzVectorPxPyPzE4D higgsFramePxPyPzE4D = sumLorentz4D(top1FromHiggs, top2FromHiggs);
                    // boost pp and ttbar to the frame of the higgs candidate
                    ROOT::Math::Boost boostToHiggsFrame(higgsFramePxPyPzE4D.BoostToCM());
                    LorentzVectorPxPyPzE4D proton1_HiggsFrame = boostToHiggsFrame(proton1_labFrame);
                    LorentzVectorPxPyPzE4D proton2_HiggsFrame = boostToHiggsFrame(proton2_labFrame);
                    LorentzVectorPxPyPzE4D otherTop1_HiggsFrame = boostToHiggsFrame(otherTop1);
                    LorentzVectorPxPyPzE4D otherTop2_HiggsFrame = boostToHiggsFrame(otherTop2);
                    // compute event observable
                    event_observable.push_back(
                        TMath::ACos(
                            cosPhiC(
                                normalize(unmove(lorentz4DToCartesian3D(proton1_HiggsFrame))),
                                normalize(unmove(lorentz4DToCartesian3D(proton2_HiggsFrame))),
                                normalize(unmove(lorentz4DToCartesian3D(otherTop1_HiggsFrame))),
                                normalize(unmove(lorentz4DToCartesian3D(otherTop2_HiggsFrame)))
                            )
                        )                                    
                    );
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable HT ######################################################

Obs_HT::Obs_HT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_HT::SetPlotConf(){
    pltparams.name                   = "HT";
    pltparams.title                  = "H_{T} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 4000.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_HT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            event_observable.push_back(particle->PT);
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0.);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dR_ttbar_min ######################################################

Obs_dR_ttbar_min::Obs_dR_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dR_ttbar_min::SetPlotConf(){
    pltparams.name                   = "dR_ttbar_min";
    pltparams.title                  = "#DeltaR_{t#bar{t}}^{min}";
    pltparams.nbins                  = 14;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dR_ttbar_min::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(deltaR(particle1->Eta, particle1->Phi, particle2->Eta, particle2->Phi));
                }
            }
        }
    }
    fillObservable = *std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dR_ttbar_avg ######################################################

Obs_dR_ttbar_avg::Obs_dR_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dR_ttbar_avg::SetPlotConf(){
    pltparams.name                   = "dR_ttbar_avg";
    pltparams.title                  = "#DeltaR_{t#bar{t}}^{avg}";
    pltparams.nbins                  = 14;
    pltparams.x_min                  = 1.5;
    pltparams.x_max                  = 5.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_dR_ttbar_avg::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    event_observable.push_back(deltaR(particle1->Eta, particle1->Phi, particle2->Eta, particle2->Phi));
                }
            }
        }
    }
    fillObservable = std::accumulate(event_observable.begin(), event_observable.end(), 0.)/((double)(event_observable.size()));
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dRtt ######################################################

Obs_dRtt::Obs_dRtt(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dRtt::SetPlotConf(){
    pltparams.name                   = "dRtt";
    pltparams.title                  = "#DeltaR_{tt}";
    pltparams.nbins                  = 14;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = true;
}

void Obs_dRtt::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> tt_samesign = Selections::tt_samesign<TRootLHEFParticle>(branchParticle, 1);
    LorentzVectorPxPyPzE4D top1_PxPyPzE4D = std::get<0>(tt_samesign);
    LorentzVectorPxPyPzE4D top2_PxPyPzE4D = std::get<1>(tt_samesign);

    event_observable.push_back(deltaR(top1_PxPyPzE4D.Eta(), top1_PxPyPzE4D.Phi(), top2_PxPyPzE4D.Eta(), top2_PxPyPzE4D.Phi()));

    fillObservable = event_observable.at(0);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable dRtxtx ######################################################

Obs_dRtxtx::Obs_dRtxtx(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dRtxtx::SetPlotConf(){
    pltparams.name                   = "dRtxtx";
    pltparams.title                  = "#DeltaR_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 14;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = true;
}

void Obs_dRtxtx::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> tt_samesign = Selections::tt_samesign<TRootLHEFParticle>(branchParticle, -1);
    LorentzVectorPxPyPzE4D top1_PxPyPzE4D = std::get<0>(tt_samesign);
    LorentzVectorPxPyPzE4D top2_PxPyPzE4D = std::get<1>(tt_samesign);

    event_observable.push_back(deltaR(top1_PxPyPzE4D.Eta(), top1_PxPyPzE4D.Phi(), top2_PxPyPzE4D.Eta(), top2_PxPyPzE4D.Phi()));

    fillObservable = event_observable.at(0);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leading pT min dR ######################################################

Obs_dR_ttbar_lead_min::Obs_dR_ttbar_lead_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_dR_ttbar_lead_min::SetPlotConf(){
    pltparams.name                   = "dR_ttbar_lead_min";
    pltparams.title                  = "#DeltaR_{t#bar{t}}^{lead. min.}";
    pltparams.nbins                  = 14;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = true;
}

void Obs_dR_ttbar_lead_min::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D = std::get<1>(ttbar_leadPT_minDR);
    fillObservable = deltaR(leadingTop_PxPyPzE4D, closestTop_PxPyPzE4D);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}


// ### Observable leadingTopPT ######################################################

Obs_leadingTopPT::Obs_leadingTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingTopPT::SetPlotConf(){
    pltparams.name                   = "leadingTopPT";
    pltparams.title                  = "Leading p^{top}_{T} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1000.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingTopPT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            event_observable.push_back(particle->PT);
        }
    }
    fillObservable = *std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable diffHiLoTopPT ######################################################

Obs_diffHiLoTopPT::Obs_diffHiLoTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_diffHiLoTopPT::SetPlotConf(){
    pltparams.name                   = "diffHiLoTopPT";
    pltparams.title                  = "p_{T top}^{max} -- p_{T top}^{min} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1000.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_diffHiLoTopPT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            event_observable.push_back(particle->PT);
        }
    }
    fillObservable = *std::max_element(event_observable.begin(), event_observable.end()) - *std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leadingBeautyPT ######################################################

Obs_leadingBeautyPT::Obs_leadingBeautyPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingBeautyPT::SetPlotConf(){
    pltparams.name                   = "leadingBeautyPT";
    pltparams.title                  = "Leading p^{b}_{T} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 700.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingBeautyPT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 5) {
            event_observable.push_back(particle->PT);
        }
    }
    fillObservable = *std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leadingLeptonPT ######################################################

Obs_leadingLeptonPT::Obs_leadingLeptonPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingLeptonPT::SetPlotConf(){
    pltparams.name                   = "leadingLeptonPT";
    pltparams.title                  = "Leading p^{l}_{T} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 400.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingLeptonPT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 11 || abs(particle->PID) == 13) {
            event_observable.push_back(particle->PT);
        }
    }
    if (event_observable.size() != 0) {
        fillObservable = *std::max_element(event_observable.begin(), event_observable.end());
        histos.at(idxChain)->Fill(fillObservable);
    }
    event_observable.clear();
}

// ### Observable subleadingTopPT ######################################################

Obs_subleadingTopPT::Obs_subleadingTopPT(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_subleadingTopPT::SetPlotConf(){
    pltparams.name                   = "subleadingTopPT";
    pltparams.title                  = "subleading p^{top}_{T} [GeV]";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1000.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_subleadingTopPT::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            event_observable.push_back(particle->PT);
        }
    }
    std::sort(event_observable.begin(), event_observable.end());
    fillObservable = event_observable.at(1);
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leadingTopEta ######################################################

Obs_leadingTopEta::Obs_leadingTopEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingTopEta::SetPlotConf(){
    pltparams.name                   = "leadingTopEta";
    pltparams.title                  = "Leading #eta^{top}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingTopEta::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            event_observable.push_back(particle->Eta);
        }
    }
    fillObservable = *std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leadingBeautyEta ######################################################

Obs_leadingBeautyEta::Obs_leadingBeautyEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingBeautyEta::SetPlotConf(){
    pltparams.name                   = "leadingBeautyEta";
    pltparams.title                  = "Leading #eta^{b}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingBeautyEta::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 5) {
            event_observable.push_back(particle->Eta);
        }
    }
    fillObservable = *std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable leadingLeptonEta ######################################################

Obs_leadingLeptonEta::Obs_leadingLeptonEta(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_leadingLeptonEta::SetPlotConf(){
    pltparams.name                   = "leadingLeptonEta";
    pltparams.title                  = "Leading #eta^{lep}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_leadingLeptonEta::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 11 || abs(particle->PID) == 13) {
            event_observable.push_back(particle->Eta);
        }
    }
    if (event_observable.size() != 0) {
        fillObservable = *std::min_element(event_observable.begin(), event_observable.end());
        histos.at(idxChain)->Fill(fillObservable);
    }
    event_observable.clear();
}

// ### Observable m_ttbar_minDR ######################################################

Obs_m_ttbar_minDR::Obs_m_ttbar_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_ttbar_minDR::SetPlotConf(){
    pltparams.name                   = "m_ttbar_minDR";
    pltparams.title                  = "m_{t#bar{t}}^{#DeltaR_{min}} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 2200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_m_ttbar_minDR::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_minDR = Selections::ttbar_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D = std::get<0>(ttbar_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D = std::get<1>(ttbar_minDR);
    LorentzVectorPxPyPzE4D totalFourMomentum = leadingTop_PxPyPzE4D+closestTop_PxPyPzE4D;
    fillObservable = totalFourMomentum.M();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable m_ttbar_leadPT_minDR ######################################################

Obs_m_ttbar_leadPT_minDR::Obs_m_ttbar_leadPT_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_m_ttbar_leadPT_minDR::SetPlotConf(){
    pltparams.name                   = "m_ttbar_leadPT_minDR";
    pltparams.title                  = "m_{t#bar{t}}^{p_{T}^{lead }#DeltaR_{min}} [GeV]";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 200.0;
    pltparams.x_max                  = 2200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_m_ttbar_leadPT_minDR::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D = std::get<1>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D totalFourMomentum = leadingTop_PxPyPzE4D+closestTop_PxPyPzE4D;
    fillObservable = totalFourMomentum.M();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b2_ttbar_minDR_boosted ######################################################

Obs_b2_ttbar_minDR_boosted::Obs_b2_ttbar_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_ttbar_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "b2_ttbar_minDR_boosted";
    pltparams.title                  = "b2_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_ttbar_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(b2operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b4_ttbar_minDR_boosted ######################################################

Obs_b4_ttbar_minDR_boosted::Obs_b4_ttbar_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_ttbar_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "b4_ttbar_minDR_boosted";
    pltparams.title                  = "b4_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b4_ttbar_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(b4operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b2_ttbar_leadPT_minDR_boosted ######################################################

Obs_b2_ttbar_leadPT_minDR_boosted::Obs_b2_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b2_ttbar_leadPT_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "b2_ttbar_leadPT_minDR_boosted";
    pltparams.title                  = "b2_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b2_ttbar_leadPT_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(b2operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b4_ttbar_leadPT_minDR_boosted ######################################################

Obs_b4_ttbar_leadPT_minDR_boosted::Obs_b4_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b4_ttbar_leadPT_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "b4_ttbar_leadPT_minDR_boosted";
    pltparams.title                  = "b4_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b4_ttbar_leadPT_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(b4operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable b1_ttbar_leadPT_minDR_boosted ######################################################

Obs_b1_ttbar_leadPT_minDR_boosted::Obs_b1_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_b1_ttbar_leadPT_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "b1_ttbar_leadPT_minDR_boosted";
    pltparams.title                  = "b1_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_b1_ttbar_leadPT_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(b1operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable a1_ttbar_leadPT_minDR_boosted ######################################################

Obs_a1_ttbar_leadPT_minDR_boosted::Obs_a1_ttbar_leadPT_minDR_boosted(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_a1_ttbar_leadPT_minDR_boosted::SetPlotConf(){
    pltparams.name                   = "a1_ttbar_leadPT_minDR_boosted";
    pltparams.title                  = "a1_{t#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1;
    pltparams.x_max                  = 1;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 80000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_a1_ttbar_leadPT_minDR_boosted::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Get top quarks in this event
    vector<LorentzVectorPxPyPzE4D> eventTops_PxPyPzE4D_lab;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            eventTops_PxPyPzE4D_lab.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    ROOT::Math::Boost lorentzBoostTo4TopCoM(sumLorentz4D(eventTops_PxPyPzE4D_lab).BoostToCM());

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR = Selections::ttbar_leadPT_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_lab = std::get<0>(ttbar_leadPT_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_lab = std::get<1>(ttbar_leadPT_minDR);

    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(leadingTop_PxPyPzE4D_lab);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D_4TopCM = lorentzBoostTo4TopCoM(closestTop_PxPyPzE4D_lab);

    event_observable.push_back(a1operator(leadingTop_PxPyPzE4D_4TopCM, closestTop_PxPyPzE4D_4TopCM));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable pT_ttbar_max ######################################################

Obs_pT_ttbar_max::Obs_pT_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_pT_ttbar_max::SetPlotConf(){
    pltparams.name                   = "pT_ttbar_max";
    pltparams.title                  = "p_{T t#bar{t}}^{max} [GeV]";
    pltparams.nbins                  = 24;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_pT_ttbar_max::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    event_observable.push_back((top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Pt());
                }
            }
        }
    }
    fillObservable = *std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable pT_ttbar_minDR ######################################################

Obs_pT_ttbar_minDR::Obs_pT_ttbar_minDR(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_pT_ttbar_minDR::SetPlotConf(){
    pltparams.name                   = "pT_ttbar_minDR";
    pltparams.title                  = "p_{T t#bar{t}}^{min #DeltaR} [GeV]";
    pltparams.nbins                  = 24;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 1200.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 7000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_pT_ttbar_minDR::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_minDR = Selections::ttbar_minDR<TRootLHEFParticle>(branchParticle);
    LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D = std::get<0>(ttbar_minDR);
    LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D = std::get<1>(ttbar_minDR);
    LorentzVectorPxPyPzE4D totalFourMomentum = leadingTop_PxPyPzE4D+closestTop_PxPyPzE4D;
    fillObservable = totalFourMomentum.Pt();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable eta_ttbar_all ######################################################

Obs_eta_ttbar_all::Obs_eta_ttbar_all(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_ttbar_all::SetPlotConf(){
    pltparams.name                   = "eta_ttbar_all";
    pltparams.title                  = "#eta_{t#bar{t}}^{all}";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_ttbar_all::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    event_observable.push_back(abs((top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Eta()));
                }
            }
        }
    }
    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable eta_ttbar_min ######################################################

Obs_eta_ttbar_min::Obs_eta_ttbar_min(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_ttbar_min::SetPlotConf(){
    pltparams.name                   = "eta_ttbar_min";
    pltparams.title                  = "#eta_{t#bar{t}}^{min}";
    pltparams.nbins                  = 15;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 3;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_ttbar_min::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    event_observable.push_back(abs((top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Eta()));
                }
            }
        }
    }
    fillObservable=*std::min_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable eta_ttbar_max ######################################################

Obs_eta_ttbar_max::Obs_eta_ttbar_max(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_ttbar_max::SetPlotConf(){
    pltparams.name                   = "eta_ttbar_max";
    pltparams.title                  = "#eta_{t#bar{t}}^{max}";
    pltparams.nbins                  = 25;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 5;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_ttbar_max::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    event_observable.push_back(abs((top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Eta()));
                }
            }
        }
    }
    fillObservable=*std::max_element(event_observable.begin(), event_observable.end());
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable eta_ttbar_avg ######################################################

Obs_eta_ttbar_avg::Obs_eta_ttbar_avg(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_eta_ttbar_avg::SetPlotConf(){
    pltparams.name                   = "eta_ttbar_avg";
    pltparams.title                  = "#eta_{t#bar{t}}^{avg}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0;
    pltparams.x_max                  = 4;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 5000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_eta_ttbar_avg::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    event_observable.push_back(abs((top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Eta()));
                }
            }
        }
    }
    fillObservable=std::accumulate(event_observable.begin(), event_observable.end(), 0.)/((double)(event_observable.size()));
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable thetaStar ######################################################

Obs_thetaStar::Obs_thetaStar(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_thetaStar::SetPlotConf(){
    pltparams.name                   = "thetaStar";
    pltparams.title                  = "#theta^{*}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_thetaStar::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    // find the other top or antitop particle in the 4 top event
    // than the ones in iteration which are assumed to be from the Higgs decay
    auto findParticle = [](TClonesArray* branchParticle, int id, LorentzVectorPxPyPzE4D skip){
        LorentzVectorPxPyPzE4D otherParticle;
        for(auto particle_i : *branchParticle){
            TRootLHEFParticle *temp = (TRootLHEFParticle*)particle_i;
            LorentzVectorPxPyPzE4D temp4vec(temp->Px, temp->Py, temp->Pz, temp->E);
            if(temp->PID == id && temp4vec != skip){
                otherParticle = temp4vec;
                break;
            }
        }
        return otherParticle;
    };
    // initial state protons
    TRootLHEFParticle *proton1 = (TRootLHEFParticle*)((*branchParticle)[0]);
    TRootLHEFParticle *proton2 = (TRootLHEFParticle*)((*branchParticle)[1]);
    LorentzVectorPxPyPzE4D proton1_labFrame(proton1->Px, proton1->Py, proton1->Pz, proton1->E);
    LorentzVectorPxPyPzE4D proton2_labFrame(proton2->Px, proton2->Py, proton2->Pz, proton2->E);
    // Loop over particles
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle1 = (TRootLHEFParticle*)iterator1;
        if(particle1->PID == 6) {
            for(auto iterator2 : *branchParticle){
                TRootLHEFParticle *particle2 = (TRootLHEFParticle*)iterator2;
                if(particle2->PID == -6) {
                    // define tops from Higgs decay and the other tops [candidates in this iteration]
                    LorentzVectorPxPyPzE4D top1FromHiggs(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                    LorentzVectorPxPyPzE4D top2FromHiggs(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                    LorentzVectorPxPyPzE4D otherTop1 = findParticle(branchParticle, 6, top1FromHiggs);
                    LorentzVectorPxPyPzE4D otherTop2 = findParticle(branchParticle, -6, top2FromHiggs);
                    LorentzVectorPxPyPzE4D ttbarFramePxPyPzE4D = sumLorentz4D(otherTop1, otherTop2);

                    // boost pp and ttbar to the frame of the higgs candidate
                    ROOT::Math::Boost boostTottbarFrame(ttbarFramePxPyPzE4D.BoostToCM());
                    LorentzVectorPxPyPzE4D proton1_ttbarFrame = boostTottbarFrame(proton1_labFrame);
                    //LorentzVectorPxPyPzE4D proton2_ttbarFrame = boostTottbarFrame(proton2_labFrame);
                    LorentzVectorPxPyPzE4D otherTop1_ttbarFrame = boostTottbarFrame(otherTop1);
                    //LorentzVectorPxPyPzE4D otherTop2_ttbarFrame = boostTottbarFrame(otherTop2);

                    // compute event observable
                    event_observable.push_back(
                        TMath::ACos(
                            dotProductND(
                                normalize(unmove(lorentz4DToCartesian3D(otherTop1_ttbarFrame))),
                                normalize(unmove(lorentz4DToCartesian3D(proton1_ttbarFrame)))))
                    );
                }
            }
        }
    }

    std::for_each(
            event_observable.begin(),
            event_observable.end(),
            [=](double x){
                histos.at(idxChain)->Fill((Double_t)x);
    });
    event_observable.clear();
}

// ### Observable angleTopAntitopPlanes ######################################################

Obs_angleTopAntitopPlanes::Obs_angleTopAntitopPlanes(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_angleTopAntitopPlanes::SetPlotConf(){
    pltparams.name                   = "angleTopAntitopPlanes";
    pltparams.title                  = "#theta^{tt}_{#bar{t}#bar{t}}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = 0.0;
    pltparams.x_max                  = 3.2;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_angleTopAntitopPlanes::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    vector<LorentzVectorPxPyPzE4D> tops;
    vector<LorentzVectorPxPyPzE4D> antitops;
    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator1;
        if(particle->PID == 6) {
            tops.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        
        }
    }

    for(auto iterator1 : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator1;
        if(particle->PID == -6) {
            antitops.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }
    
    vector<double> topsplane = crossProduct3D(lorentz4DToCartesian3D(tops.front()), lorentz4DToCartesian3D(tops.back()));
    vector<double> antitopsplane = crossProduct3D(lorentz4DToCartesian3D(antitops.front()), lorentz4DToCartesian3D(antitops.back()));
    normalize(topsplane);
    normalize(antitopsplane);
    
    event_observable.push_back(TMath::ACos(dotProductND(topsplane, antitopsplane)));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable tripleProductLeadingTopPTFrame ######################################################

Obs_tripleProductLeadingTopPTFrame::Obs_tripleProductLeadingTopPTFrame(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_tripleProductLeadingTopPTFrame::SetPlotConf(){
    pltparams.name                   = "tripleProductLeadingTopPTFrame";
    pltparams.title                  = "#vec{p}^{ top}_{2} #upoint #vec{p}^{ top}_{3} #times #vec{p}^{ top}_{4}";
    pltparams.nbins                  = 15;
    pltparams.x_min                  = 0.;
    pltparams.x_max                  = 0.3;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_tripleProductLeadingTopPTFrame::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    double currentPT = 0.;
    LorentzVectorPxPyPzE4D topLeadingPT(0., 0., 0., 0.);
    vector<LorentzVectorPxPyPzE4D> topParticles_labFrame;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            if(topLeadingPT.E() == 0.){
                topLeadingPT = LorentzVectorPxPyPzE4D(particle->Px, particle->Py, particle->Pz, particle->E);
                currentPT = topLeadingPT.Pt();
                continue;
            }
            if(particle->PT > currentPT){
                topParticles_labFrame.push_back(topLeadingPT);
                //topParticles_labFrame.emplace_back(topLeadingPT.Px(), topLeadingPT.Py(), topLeadingPT.Pz(), topLeadingPT.E());
                topLeadingPT = LorentzVectorPxPyPzE4D(particle->Px, particle->Py, particle->Pz, particle->E);
                currentPT = topLeadingPT.Pt();
            }
            else{
                topParticles_labFrame.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
            }
        }
    }
    ROOT::Math::Boost boostToTopLeadingPTFrame(topLeadingPT.BoostToCM());
    vector<LorentzVectorPxPyPzE4D> topParticles_TopLeadingPTFrame;
    std::for_each(
            topParticles_labFrame.begin(),
            topParticles_labFrame.end(),
            [&](LorentzVectorPxPyPzE4D topParticle){
                LorentzVectorPxPyPzE4D temp = boostToTopLeadingPTFrame(topParticle);
                topParticles_TopLeadingPTFrame.emplace_back(temp.Px(), temp.Py(), temp.Pz(), temp.E());
            });

    event_observable.push_back(
            abs(
                dotProductND(
                    normalize(unmove(lorentz4DToCartesian3D(topParticles_TopLeadingPTFrame.at(0)))),
                    crossProduct3D(
                        normalize(unmove(lorentz4DToCartesian3D(topParticles_TopLeadingPTFrame.at(1)))),
                        normalize(unmove(lorentz4DToCartesian3D(topParticles_TopLeadingPTFrame.at(2))))))));

    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable p1Xp2Op3Xp4 ######################################################

Obs_p1Xp2Op3Xp4::Obs_p1Xp2Op3Xp4(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_p1Xp2Op3Xp4::SetPlotConf(){
    pltparams.name                   = "p1Xp2Op3Xp4";
    pltparams.title                  = "#vec{p}^{ top}_{1} #times #vec{p}^{ top}_{2} #upoint #vec{p}^{ top}_{3} #times #vec{p}^{ top}_{4}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1.0;
    pltparams.x_max                  = 1.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_p1Xp2Op3Xp4::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    vector<LorentzVectorPxPyPzE4D> topParticles;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            topParticles.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }

    std::sort(topParticles.begin(), topParticles.end(), [](LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){return (p1.Pt() > p2.Pt());});

    event_observable.push_back(
            dotProductND(
                crossProduct3D(
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(0)))),
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(1))))),
                crossProduct3D(
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(2)))),
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(3)))))));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}

// ### Observable p1Xp3Op2xp4 ######################################################

Obs_p1Xp3Op2Xp4::Obs_p1Xp3Op2Xp4(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx) : GeneralPlot(prodName, sampleSet, yukawaSet, sfx){
    SetPlotConf();
    Initialize();
}

void Obs_p1Xp3Op2Xp4::SetPlotConf(){
    pltparams.name                   = "p1Xp3Op2Xp4";
    pltparams.title                  = "#vec{p}^{ top}_{1} #times #vec{p}^{ top}_{3} #upoint #vec{p}^{ top}_{2} #times #vec{p}^{ top}_{4}";
    pltparams.nbins                  = 20;
    pltparams.x_min                  = -1.0;
    pltparams.x_max                  = 1.0;
    //pltparams.main_y_min             = 10.;
    //pltparams.main_y_max             = 35000.;
    pltparams.ratio_y_min            = 0.25;
    pltparams.ratio_y_max            = 2.6;
    pltparams.label_main_y_axis      = "Normalised";
    pltparams.label_ratio_y_axis     = "Ratio to kt_0";
    pltparams.invert_legend          = false;
}

void Obs_p1Xp3Op2Xp4::ComputeFillObservable(TClonesArray* branchParticle, int idxChain){
    vector<LorentzVectorPxPyPzE4D> topParticles;
    for(auto iterator : *branchParticle){
        TRootLHEFParticle *particle = (TRootLHEFParticle*)iterator;
        if(abs(particle->PID) == 6) {
            topParticles.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
        }
    }

    std::sort(topParticles.begin(), topParticles.end(), [](LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){return (p1.Pt() > p2.Pt());});

    event_observable.push_back(
            dotProductND(
                crossProduct3D(
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(0)))),
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(2))))),
                crossProduct3D(
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(1)))),
                    normalize(unmove(lorentz4DToCartesian3D(topParticles.at(3)))))));
    fillObservable = event_observable.front();
    histos.at(idxChain)->Fill(fillObservable);
    event_observable.clear();
}
