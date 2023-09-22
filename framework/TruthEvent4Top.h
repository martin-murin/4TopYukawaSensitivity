#ifndef TRUTHEVENT4TOP 
#define TRUTHEVENT4TOP 

#include"classes/DelphesClasses.h"
#include"classes/SortableObject.h"
#include "GenTopParticle.h"

enum class Channel {Had, SingleLep, DiLepOS, DiLepSS, ThreeLep, AllLep};

class TruthEvent4Top{
    private:
        GenParticle* findMotherParton(GenParticle* parton);
        void findTopOfQuarkLepton(GenParticle* parton);
        void calcTopHistoryFromEvent();
        
        Jet* findMatchingJet(GenParticle* p, float dRCut, float jetEtaCut);
        void matchTopDecayParticlesWithJets(GenTopParticle* top);
        
        Channel channel;
        void calcChannel();
    public:
        TruthEvent4Top(TClonesArray* branchParticle, TClonesArray* branchGenJet);
        virtual ~TruthEvent4Top();
        
        TClonesArray* eventBranchParticle;
        TClonesArray* eventBranchGenJet;

        //Long64_t eventNumber; 
        std::vector<GenTopParticle> topQuarks;
        
        int getNumberBjets();
        int getNumberNullB();
        int getNumberLep();
        int getChannel();
        int getNumberTopsFullTMatch();
        int getNumberHadTopsFullTMatch();
        int getNumberLepTopsFullTMatch();
};

#endif
