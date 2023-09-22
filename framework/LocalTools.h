#ifndef LOCALTOOLS_H
#define LOCALTOOLS_H

#include<TROOT.h>
#include<vector>

using std::vector;

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double>> LorentzVectorPxPyPzE4D;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double>> LorentzVectorPtEtaPhiM4D;
template<class T> T& unmove(T&& t) { return t; } 

enum class SampleSet{MGLO_Higgs, MGLO_Inclusive, MGPY8Delphes4TopsInclusive, ValidationSet, Debug};
enum class YukawaSet{kappa, alpha};
std::string sampleSetToStr(SampleSet s);
std::string yukawaSetToStr(SampleSet s);
std::map<std::string, SampleSet> samplemap = {
    {"higgs", SampleSet::MGLO_Higgs},
    {"control", SampleSet::MGLO_Inclusive},
    {"truthjets", SampleSet::MGPY8Delphes4TopsInclusive},
    {"validation", SampleSet::ValidationSet},
    {"debug", SampleSet::Debug}};
std::map<std::string, YukawaSet> yukawamap = {
    {"alpha", YukawaSet::alpha},
    {"kappa", YukawaSet::kappa}};
std::string translateCouplingSuffix(const std::string& couplingSuffix);

template<typename T> int sgn(T val);
vector<double> crossZ(vector<double> v);
double dotProductND(vector<double> w1, vector<double> w2);
vector<double> crossProduct3D(vector<double> w1, vector<double> w2);
double squareNormND(vector<double> w);
double b2operator(vector<double> w1, vector<double> w2);
double b4operator(vector<double> w1, vector<double> w2);
double a1operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2);
double b1operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2);
double b2operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2);
double b4operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2);
double deltaPhi(double phi1, double phi2);
double deltaR(double eta1, double phi1, double eta2, double phi2);
double deltaR(LorentzVectorPxPyPzE4D lorentzVec1, LorentzVectorPxPyPzE4D lorentzVec2);
vector<double>& normalize(vector<double>& v);

vector<double> lorentz4DToCartesian3D(LorentzVectorPxPyPzE4D const& v);
void printLorentz4D(LorentzVectorPxPyPzE4D const& P);
template<typename T> void printVector(const vector<T>& t);
template<typename... Ts> LorentzVectorPxPyPzE4D sumLorentz4D(Ts... ps);
LorentzVectorPxPyPzE4D sumLorentz4D(vector<LorentzVectorPxPyPzE4D> ps);

double cosPhiC(vector<double> const& np1, vector<double> const& np2, vector<double> const& nt1, vector<double> const& nt2);

#endif
