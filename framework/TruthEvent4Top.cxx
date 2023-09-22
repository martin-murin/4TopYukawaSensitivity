#include "TruthEvent4Top.h"

void printFullParticle(GenParticle* p){
    if(p != NULL){
        std::cout << std::fixed << std::setprecision(3) <<
            "### Particle PID = " << p->PID <<
            "\t Particle pT = " << p->PT <<
            "\t Eta = " << p->Eta <<
            "\t Phi = " << p->Phi <<
            "\t status: " << p->Status <<
            "\t mother1: " << p->M1 <<
            "\t mother2: " << p->M2 <<
            "\t daughter1: " << p->D1 <<
            "\t daughter2: " << p->D2 << " ;\n";
    }
}

void printFullJet(Jet* j){
    if(j != NULL){
        std::cout << std::fixed << std::setprecision(3) <<
        "### Jet PT = " << j->PT <<
        "\t Eta = " << j->Eta <<
        "\t Phi = " << j->Phi <<
        "\tMass = " << j->Mass << "\n";
    }
    else{
        std::cout << "Null Jet pointer passed to this function!\n";
    }
}

TruthEvent4Top::TruthEvent4Top(TClonesArray* branchParticle, TClonesArray* branchGenJet){
    topQuarks = {};
    eventBranchParticle = branchParticle;
    eventBranchGenJet = branchGenJet;
    int indexT = 0;
    for(auto iterator : *branchParticle){
        GenParticle *particle = (GenParticle*)iterator;
        if(abs(particle->PID) == 6 && particle->Status == 22){
            topQuarks.emplace_back(particle);
            topQuarks.back().index = indexT;
            indexT++;
        }
    }
    calcTopHistoryFromEvent();
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        matchTopDecayParticlesWithJets(&(*t));
        t->calcCategories(); 
    }
    calcChannel();

    bool verbose = false;
    if(verbose){
        std::cout << "Check history and matching in this event\n";
        for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
            printFullParticle(&t->top);
            std::cout << "\n";
            printFullParticle(t->daughterB);
            printFullJet(t->jetB);
            std::cout << "\n";
            printFullParticle(t->daughterW);
            printFullJet(t->jetW);
            std::cout << "\n";
            if(t->daughterLepton != NULL){
                printFullParticle(t->daughterLepton);
                std::cout << "\n";
            }
            if(t->daughterLightQ1 != NULL){
                printFullParticle(t->daughterLightQ1);
                printFullJet(t->jetLQ1);
                std::cout << "\n";
            }
            if(t->daughterLightQ2 != NULL){
                printFullParticle(t->daughterLightQ2);
                printFullJet(t->jetLQ2);
                std::cout << "\n";
            }
        }
    }
}

TruthEvent4Top::~TruthEvent4Top(){}

void TruthEvent4Top::calcTopHistoryFromEvent(){
    int indexW = 0;
    int indexB = 0;
    for(auto iterator : *eventBranchParticle){
        GenParticle* particle = (GenParticle*)iterator;
        if(abs(particle->PID) == 5 && particle->Status == 23){
            topQuarks.at(indexB).daughterB = particle;
            indexB++;
        }
        if(abs(particle->PID) == 24 && particle->Status == 22){
            topQuarks.at(indexW).daughterW = particle;
            indexW++;
        }
        if(abs(particle->PID) < 5 && particle->Status == 23){
            findTopOfQuarkLepton(particle);
        }
        if((abs(particle->PID) >= 11 && abs(particle->PID) <= 17) && particle->Status == 23){
            findTopOfQuarkLepton(particle);
        }
    }
}

GenParticle* TruthEvent4Top::findMotherParton(GenParticle* parton){
    for (auto iterator : *eventBranchParticle){
        GenParticle* particle = static_cast<GenParticle*>(iterator);
        if(particle->D1 == parton->M1 || particle->D2 == parton->M1){
            return particle;
        }
    }
    return parton;
}

void TruthEvent4Top::findTopOfQuarkLepton(GenParticle* parton){
    GenParticle* motherW = findMotherParton(parton);
    GenParticle* grandmotherW = findMotherParton(motherW);
    if(abs(motherW->PID) == 24){
        while(abs(grandmotherW->PID) != 6){
            motherW = findMotherParton(motherW);
            grandmotherW = findMotherParton(motherW);
        }
    }
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(motherW->E == t->daughterW->E){
            if(abs(parton->PID) == 11 || abs(parton->PID) == 13){
            //if(abs(parton->PID) == 11 || abs(parton->PID) == 13 || abs(parton->PID) == 15 ){
                // Cut on matched lepton pT
                if(parton->PT > 10.){
                    t->daughterLepton = parton;
                }
            }
            else if(t->daughterLightQ1 == NULL){
                t->daughterLightQ1 = parton;
            }
            else if(t->daughterLightQ2 == NULL){
                t->daughterLightQ2 = parton;
            }
        }
    }
}

Jet* TruthEvent4Top::findMatchingJet(GenParticle* p, float dRCut, float jetEtaCut){
    Jet* matchedJet = NULL;
    if(p != NULL){
        float currentMinDR=999.;
        for(auto iterator: *eventBranchGenJet){
            Jet* j = static_cast<Jet*>(iterator);
            float dR = deltaR(j->Eta, j->Phi, p->Eta, p->Phi);
            if(dR < currentMinDR && dR < dRCut && abs(j->Eta) < jetEtaCut){
                matchedJet = j;
                currentMinDR = dR;
            }
        }
    }
    return matchedJet;
}

void TruthEvent4Top::matchTopDecayParticlesWithJets(GenTopParticle* top){
    float dRCut = 0.4;
    float jetEtaCut = 4.0;
    top->jetW = NULL; //findMatchingJet(top->daughterW, dRCut, jetEtaCut);
    top->jetB = findMatchingJet(top->daughterB, dRCut, jetEtaCut);
    top->jetLQ1 = findMatchingJet(top->daughterLightQ1, dRCut, jetEtaCut);
    top->jetLQ2 = findMatchingJet(top->daughterLightQ2, dRCut, jetEtaCut);
}

int TruthEvent4Top::getNumberLep(){
    int numberOfLeptons = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->isLeptonic()){
            numberOfLeptons++;
        }
    }
    return numberOfLeptons;
}

void TruthEvent4Top::calcChannel(){
    if(getNumberLep() == 0){
        channel = Channel::Had;
    }
    else if(getNumberLep() == 1){
        channel = Channel::SingleLep;
    }
    else if(getNumberLep() == 2){
        int charge = 1;
        std::for_each(topQuarks.begin(), topQuarks.end(), [&charge](GenTopParticle t){
                if(t.daughterLepton != NULL){
                    charge *= t.daughterLepton->PID;
                }
            }
        );
        if(charge > 0){
            channel = Channel::DiLepSS;
        }
        else{
            channel = Channel::DiLepOS;
        }
    }
    else if(getNumberLep() == 3){
        channel = Channel::ThreeLep;
    }
    else if(getNumberLep() == 4){
        channel = Channel::AllLep;
    }
}

int TruthEvent4Top::getNumberBjets(){
    int numberOfBjets = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->hasBjet()){
            numberOfBjets++;
        }
    }
    return numberOfBjets;
}

int TruthEvent4Top::getNumberNullB(){
    int numberNullB = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->daughterB == NULL){
            numberNullB++;
        }
    }
    return numberNullB;
}

int TruthEvent4Top::getChannel(){
    return (int)channel;
}

int TruthEvent4Top::getNumberTopsFullTMatch(){
    int numberTopsFullReco = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->isFullyTMatch()){
            numberTopsFullReco++;
        }
    }
    return numberTopsFullReco;
}

int TruthEvent4Top::getNumberHadTopsFullTMatch(){
    int numberHadTopsFullReco = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->isFullyTMatchHad()){
            numberHadTopsFullReco++;
        }
    }
    return numberHadTopsFullReco;
}

int TruthEvent4Top::getNumberLepTopsFullTMatch(){
    int numberLepTopsFullReco = 0;
    for(auto t = std::begin(topQuarks); t != std::end(topQuarks); ++t){
        if(t->isFullyTMatchLep()){
            numberLepTopsFullReco++;
        }
    }
    return numberLepTopsFullReco;
}
