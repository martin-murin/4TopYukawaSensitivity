#include "GenTopParticle.h"
/*
// to be imported from LocalTools.h
double deltaPhi(double phi1, double phi2){
    double deltaphi = phi1 - phi2;
    double pi = TMath::Pi();
    while(deltaphi >= pi) deltaphi -= 2*pi;
    while(deltaphi < -pi) deltaphi += 2*pi;
    return deltaphi;
}

// to be imported from LocalTools.h
double deltaR(double eta1, double phi1, double eta2, double phi2){
    double deltaeta = eta1 - eta2;
    double deltaphi = deltaPhi(phi1, phi2);
    return TMath::Sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
}
*/
double deltaRJetParticle(Jet* j, GenParticle* p){
    return deltaR(j->Eta, j->Phi, p->Eta, p->Phi);
}

template<typename T>
LorentzVectorPtEtaPhiM4D getLorentzFromObject(T* object){
    LorentzVectorPtEtaPhiM4D lorentzVec(object->PT, object->Eta, object->Phi, object->Mass);
    return lorentzVec;
}

GenTopParticle::GenTopParticle(GenParticle* p){
    top = *p;
    index = 0;

    daughterW = NULL;
    daughterB = NULL;
    daughterLepton = NULL;
    daughterLightQ1 = NULL;
    daughterLightQ2 = NULL;
    jetW = NULL;
    jetB = NULL;
    jetLQ1 = NULL;
    jetLQ2 = NULL;
}

GenTopParticle::~GenTopParticle(){}

bool GenTopParticle::isLeptonic(){
    if(daughterLepton != NULL){
        return true;
    }
    return false;
}

bool GenTopParticle::isFullyTMatch(){
    //if(jetB != NULL && (isLeptonic() || (jetLQ1 != NULL && jetLQ2 != NULL) || jetW != NULL)){
    if(jetB != NULL && (isLeptonic() || (jetLQ1 != NULL && jetLQ2 != NULL))){
        return true;
    }
    return false;
}

bool GenTopParticle::isFullyTMatchHad(){
    //if(jetB != NULL && ((jetLQ1 != NULL && jetLQ2 != NULL) || jetW != NULL)){
    if(jetB != NULL && ((jetLQ1 != NULL && jetLQ2 != NULL))){
        return true;
    }
    return false;
}

bool GenTopParticle::isFullyTMatchLep(){
    if(jetB != NULL && isLeptonic()){
        return true;
    }
    return false;
}

bool GenTopParticle::hasWjet(){
    if(jetW != NULL){
        return true;
    }
    return false;
}

bool GenTopParticle::hasBjet(){
    if(jetB != NULL){
        return true;
    }
    return false;
}

bool GenTopParticle::hasQ1jet(){
    if(jetLQ1 != NULL){
        return true;
    }
    return false;
}

bool GenTopParticle::hasQ2jet(){
    if(jetLQ2 != NULL){
        return true;
    }
    return false;
}

int GenTopParticle::nQQjets(){
    if(jetLQ1 != NULL && jetLQ2 != NULL){
        return 2;
    }
    else if(jetLQ1 != NULL || jetLQ2 != NULL){
        return 1;
    }
    return 0;
}

void GenTopParticle::calcCategories(){
    // determine top reconstruction category
    if(hasBjet() && (nQQjets() == 2 || isLeptonic())){
        topcategory = TopTMatchCategory::full;
    }
    else if(hasBjet() && nQQjets() == 1 && !isLeptonic()){
        topcategory = TopTMatchCategory::bq;
    }
    else if(hasBjet() && nQQjets() == 0 && !isLeptonic()){
        topcategory = TopTMatchCategory::b;
    }
    else if(!hasBjet() && nQQjets() == 2){
        topcategory = TopTMatchCategory::qq;
    }
    else if(!hasBjet() && nQQjets() == 1){
        topcategory = TopTMatchCategory::q;
    }
    else if(!hasBjet() && isLeptonic()){
        topcategory = TopTMatchCategory::l;
    }
    else{
        topcategory = TopTMatchCategory::none;
    }

    // determine W boson from top decay reconstruction category
    if(isLeptonic()){
        wcategory = WHadTMatchCategory::leptonic;
    }
    else if(nQQjets() == 2){
        if(jetLQ1->PT == jetLQ2->PT){
            wcategory = WHadTMatchCategory::containedQQ;
        }
        else{
            wcategory = WHadTMatchCategory::separateQQ;
        }
    }
    else if(nQQjets() == 1){
        wcategory = WHadTMatchCategory::onlyQ;
    }
    else{
        wcategory = WHadTMatchCategory::none;
    }
}

int GenTopParticle::getTopCategory(){
    return (int)topcategory;
}

int GenTopParticle::getWCategory(){
    return (int)wcategory;
}

LorentzVectorPtEtaPhiM4D GenTopParticle::reconstructWLorentzVector(){
    LorentzVectorPtEtaPhiM4D wbosonLorentzVector(0, 0, 0, 0);
    if(wcategory == WHadTMatchCategory::containedQQ){
        wbosonLorentzVector = getLorentzFromObject<Jet>(jetLQ1);
    }
    if(wcategory == WHadTMatchCategory::separateQQ){
        wbosonLorentzVector = getLorentzFromObject<Jet>(jetLQ1) + getLorentzFromObject<Jet>(jetLQ2);
    }
    return wbosonLorentzVector;
}

LorentzVectorPtEtaPhiM4D GenTopParticle::reconstructTopLorentzVector(){
    LorentzVectorPtEtaPhiM4D topLorentzVector(0, 0, 0, 0);
    if(topcategory == TopTMatchCategory::full){
        if(isLeptonic()){
           topLorentzVector = getLorentzFromObject<Jet>(jetB) + getLorentzFromObject<GenParticle>(daughterLepton); 
        }
        else if(wcategory == WHadTMatchCategory::containedQQ){
            topLorentzVector = getLorentzFromObject<Jet>(jetB) + getLorentzFromObject<Jet>(jetLQ1);
        }
        else if(wcategory == WHadTMatchCategory::separateQQ){
            topLorentzVector = getLorentzFromObject<Jet>(jetB) + getLorentzFromObject<Jet>(jetLQ1) + getLorentzFromObject<Jet>(jetLQ2);
        }
    }
    return topLorentzVector;
}
