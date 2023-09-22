#ifndef GENTOPPARTICLE
#define GENTOPPARTICLE

#include<TROOT.h>
#include "classes/DelphesClasses.h"
#include<LocalTools.h>

enum class TopTMatchCategory {full, bq, b, qq, q, l, none};
enum class WHadTMatchCategory {containedQQ, separateQQ, onlyQ, none, leptonic};

class GenTopParticle{
    public:
        GenTopParticle(GenParticle* p);
        ~GenTopParticle();
        int index;

        GenParticle top;
        GenParticle* daughterW;
        GenParticle* daughterB;
        GenParticle* daughterLepton;
        GenParticle* daughterLightQ1;
        GenParticle* daughterLightQ2;

        Jet* jetW;
        Jet* jetB;
        Jet* jetLQ1;
        Jet* jetLQ2;

        TopTMatchCategory topcategory;
        WHadTMatchCategory wcategory;

        bool isLeptonic();
        bool isFullyTMatch();
        bool isFullyTMatchHad();
        bool isFullyTMatchLep();
        bool hasWjet();
        bool hasBjet();
        bool hasQ1jet();
        bool hasQ2jet();
        int nQQjets();
        void calcCategories();
        int getTopCategory();
        int getWCategory();
        LorentzVectorPtEtaPhiM4D reconstructWLorentzVector();
        LorentzVectorPtEtaPhiM4D reconstructTopLorentzVector();
};

#endif
