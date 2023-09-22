#include<Cuts.h>
#include<LocalTools.h>
#include<classes/DelphesClasses.h>

namespace Cuts {
    
    template<typename ParticleType>
    bool leadingTopPT(TClonesArray* branchParticle, double cutPT){
        vector<double> eventCutVariable;
        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            if(abs(particle->PID) == 6 && particle->PT > cutPT){
                return true;
            }
        }
        return false;
    }

    template<typename ParticleType>
    bool ttbarPT(TClonesArray* branchParticle, double cutPT){
        double eventCutVariable;
        for(auto iterator1 : *branchParticle){
            ParticleType* particle1 = static_cast<ParticleType*>(iterator1);
            if(particle1->PID == 6) {
                for(auto iterator2 : *branchParticle){
                    ParticleType* particle2 = static_cast<ParticleType*>(iterator2);
                    if(particle2->PID == -6) {
                        LorentzVectorPxPyPzE4D top1_PxPyPzE4D_lab(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                        LorentzVectorPxPyPzE4D top2_PxPyPzE4D_lab(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                        eventCutVariable = (top1_PxPyPzE4D_lab+top2_PxPyPzE4D_lab).Pt();
                        if(eventCutVariable > cutPT){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    // is event with same-sign dilepton or multi-leppton final state
    template<typename ParticleType>
    bool channelSSML(TClonesArray* branchParticle){
        std::vector<int> leptons;
        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            if(abs(particle->PID) == 11 || abs(particle->PID) == 13){
                leptons.push_back(particle->PID);
            }
        } 
        if(leptons.size() > 2 || (leptons.size() == 2 && leptons.front()*leptons.back() > 0)){
            return true;
        }
        else{
            return false;
        }
    }

    template<typename ParticleType>
    bool channel2L(TClonesArray* branchParticle){
        std::vector<int> leptons;
        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            if(abs(particle->PID) == 11 || abs(particle->PID) == 13){
                leptons.push_back(particle->PID);
            }
        } 
        if(leptons.size() == 2){
            return true;
        }
        else{
            return false;
        }
    }
}

namespace Selections {
    template<typename ParticleType>
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> tt_samesign(TClonesArray* branchParticle, int sign){
        std::vector<LorentzVectorPxPyPzE4D> particles;
        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            if(particle->PID == sign*6){
                particles.emplace_back(particle->Px, particle->Py, particle->Pz, particle->E);
            }
        }
        std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> tt_samesign{particles.at(0), particles.at(1)};
        return tt_samesign;
    }

    template<typename ParticleType>
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_minDR(TClonesArray* branchParticle){
        double currentMinDR = 1000.;
        LorentzVectorPxPyPzE4D top1_PxPyPzE4D;
        LorentzVectorPxPyPzE4D top2_PxPyPzE4D;

        for(auto iterator1 : *branchParticle){
            ParticleType* particle1 = static_cast<ParticleType*>(iterator1);
            if(particle1->PID == 6){
                for(auto iterator2 : *branchParticle){
                    ParticleType* particle2 = static_cast<ParticleType*>(iterator2);
                    if(particle2->PID == -6){
                        if(deltaR(particle1->Eta, particle1->Phi, particle2->Eta, particle2->Phi) < currentMinDR){
                            top1_PxPyPzE4D.SetPxPyPzE(particle1->Px, particle1->Py, particle1->Pz, particle1->E);
                            top2_PxPyPzE4D.SetPxPyPzE(particle2->Px, particle2->Py, particle2->Pz, particle2->E);
                        }    
                    }
                }
            }
        }
        std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_minDR{top1_PxPyPzE4D, top2_PxPyPzE4D};
        return ttbar_minDR;
    }

    template<typename ParticleType>
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR(TClonesArray* branchParticle){
        double currentLeadingPT = 0.;
        double currentMinDR = 1000.;
        int currentPID = 0;
        LorentzVectorPxPyPzE4D leadingTop_PxPyPzE4D;
        LorentzVectorPxPyPzE4D closestTop_PxPyPzE4D;

        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            if(abs(particle->PID) == 6 && currentLeadingPT < particle->PT) {
                leadingTop_PxPyPzE4D.SetPxPyPzE(particle->Px, particle->Py, particle->Pz, particle->E);
                currentLeadingPT = particle->PT;
                currentPID = particle->PID;
            }
        }

        for(auto iterator : *branchParticle){
            ParticleType* particle = static_cast<ParticleType*>(iterator);
            double currentDeltaR = deltaR(leadingTop_PxPyPzE4D.Eta(), leadingTop_PxPyPzE4D.Phi(), particle->Eta, particle->Phi);
            if(particle->PID == -currentPID && currentDeltaR < currentMinDR) {
                closestTop_PxPyPzE4D.SetPxPyPzE(particle->Px, particle->Py, particle->Pz, particle->E);
                currentMinDR = currentDeltaR;
            }
        }
        
        std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR{leadingTop_PxPyPzE4D, closestTop_PxPyPzE4D};
        return ttbar_leadPT_minDR;
    
    } 

}
