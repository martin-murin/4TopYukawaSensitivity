#include<LocalTools.h>

#include<TROOT.h>
#include<vector>
#include<algorithm>

std::string sampleSetToStr(SampleSet s){
    switch (s) {
        case SampleSet::MGLO_Higgs:                 return "MGLO_Higgs";
        case SampleSet::MGLO_Inclusive:             return "MGLO_Inclusive";
        case SampleSet::MGPY8Delphes4TopsInclusive: return "MGPY8Delphes4TopsInclusive";
        case SampleSet::ValidationSet:              return "ValidationSet";
        case SampleSet::Debug:                      return "Debug";
    }
    return "Warning: Unknown sample set!";
}

std::string yukawaSetToStr(YukawaSet s){
    switch (s) {
        case YukawaSet::kappa:  return "kappa";
        case YukawaSet::alpha:  return "alpha";
    }
    return "Warning: Unknown Yukawa set!";
}

std::string translateCouplingSuffix(const std::string& couplingSuffix) {
    std::unordered_map<std::string, std::string> translations = {
        {"kt_1_alpha_0", "SM Higgs (#alpha=0)"},
        //{"kt_1_alpha_0", "SM top-Yukawa coupling"},
        {"kt_1_alpha_45", "Mixed Higgs (#alpha=#pi/4)"},
        {"kt_1_alpha_90", "CP-odd Higgs (#alpha=#pi/2)"},
        {"kt_2_alpha_0", "Enchanced #kappa_{Ht#bar{t}} = 2 #times #kappa_{Ht#bar{t}}^{SM}"},
        {"kt_5_alpha_0", "Enchanced #kappa_{Ht#bar{t}} = 5 #times #kappa_{Ht#bar{t}}^{SM}"}
    };

    auto it = translations.find(couplingSuffix);
    if (it != translations.end()) {
        std::cout << "Text coupling suffix" << it->second << "\n";
        return it->second;
    } else {
        return "Invalid coupling suffix";
    }
}

void printFull(GenParticle* p){
    std::cout << std::fixed << std::setprecision(3) << "### Particle PID = " << p->PID << "\t Particle pT = " << p->PT << "\t Eta = " << p->Eta << "\t Phi = " << p->Phi << "\t status: " << p->Status << "\t mother1: " << p->M1 << "\t mother2: " << p->M2 << "\t daughter1: " << p->D1 << "\t daughter2: " << p->D2 << " ;\n";
}

template<typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

std::vector<double> crossZ(std::vector<double> v){
    std::vector<double> v_cross_z = {v.at(1), -v.at(0), 0};
    return v_cross_z;
}

double dotProductND(std::vector<double> w1, std::vector<double> w2){
    assert(w1.size()==w2.size());
    return std::inner_product(w1.begin(), w1.end(), w2.begin(), 0.0);
}

std::vector<double> crossProduct3D(vector<double> w1, vector<double> w2){
    assert(w1.size() == 3 && w2.size() == 3);
    vector<double> w1xw2{w1.at(1)*w2.at(2)-w1.at(2)*w2.at(1), w1.at(2)*w2.at(0)-w1.at(0)*w2.at(2), w1.at(0)*w2.at(1)-w1.at(1)*w2.at(0)};
    return w1xw2;
}

double squareNormND(std::vector<double> w){
    return sqrt(std::accumulate(
                    w.begin(),
                    w.end(),
                    0.0,
                    [](double sq_sum, double elem){
                        return sq_sum+pow(elem,2);
    }));
}

std::vector<double>& normalize(vector<double>& vec){
    double vecNorm = squareNormND(vec);
    std::transform(vec.begin(), vec.end(), vec.begin(), [vecNorm](double& e){return e/vecNorm;});
    return vec;
}

double b2operator(vector<double> w1, vector<double> w2){
    return dotProductND(crossZ(w1),crossZ(w2))/(squareNormND(w1)*squareNormND(w2));
}

double b4operator(vector<double> w1, vector<double> w2){
    std::vector<double> unitZ = {0,0,1};
    return dotProductND(w1,unitZ)*dotProductND(w2,unitZ)/(squareNormND(w1)*squareNormND(w2));
}

double b2operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){
    std::vector<double> w1 = {p1.Px(), p1.Py(), p1.Pz()};
    std::vector<double> w2 = {p2.Px(), p2.Py(), p2.Pz()};
    return dotProductND(crossZ(w1),crossZ(w2))/(squareNormND(w1)*squareNormND(w2));
}

double b4operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){
    std::vector<double> w1 = {p1.Px(), p1.Py(), p1.Pz()};
    std::vector<double> w2 = {p2.Px(), p2.Py(), p2.Pz()};
    std::vector<double> unitZ = {0,0,1};
    return dotProductND(w1,unitZ)*dotProductND(w2,unitZ)/(squareNormND(w1)*squareNormND(w2));
}

double a1operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){
    std::vector<double> w1 = {p1.Px(), p1.Py(), p1.Pz()};
    std::vector<double> w2 = {p2.Px(), p2.Py(), p2.Pz()};
    std::vector<double> unitZ = {0,0,1};
    return dotProductND(crossZ(w1),crossZ(w2))/abs(dotProductND(crossZ(w1),crossZ(w2)));
}

double b1operator(LorentzVectorPxPyPzE4D p1, LorentzVectorPxPyPzE4D p2){
    std::vector<double> w1 = {p1.Px(), p1.Py(), p1.Pz()};
    std::vector<double> w2 = {p2.Px(), p2.Py(), p2.Pz()};
    std::vector<double> unitZ = {0,0,1};
    return dotProductND(crossZ(w1),crossZ(w2))/(p1.Pt()*p2.Pt());
}

double deltaPhi(double phi1, double phi2){
    double deltaphi = phi1 - phi2;
    double pi = TMath::Pi();
    while(deltaphi >= pi) deltaphi -= 2*pi;
    while(deltaphi < -pi) deltaphi += 2*pi;
    return deltaphi;
}

double deltaR(double eta1, double phi1, double eta2, double phi2){
    double deltaeta = eta1 - eta2;
    double deltaphi = deltaPhi(phi1, phi2);
    return TMath::Sqrt(deltaeta*deltaeta + deltaphi*deltaphi);
}

double deltaR(LorentzVectorPxPyPzE4D lorentzVec1, LorentzVectorPxPyPzE4D lorentzVec2){
    return deltaR(lorentzVec1.Eta(), lorentzVec1.Phi(), lorentzVec2.Eta(), lorentzVec2.Phi());
}

std::vector<double> lorentz4DToCartesian3D(LorentzVectorPxPyPzE4D const& v){
    std::vector<double> w = {v.Px(), v.Py(), v.Pz()};
    return w;
}

void printLorentz4D(LorentzVectorPxPyPzE4D const& P){
    std::cout << P.Px() << "  " << P.Py() << "  "  << P.Pz() << "  " << P.E() << "\n";  
}

template<typename T> void printVector(const vector<T>& t){
    std::for_each(t.begin(), t.end(), [](T e){std::cout<< e <<"  ";});
    std::cout<<"\n";
}

template<typename... Ts> LorentzVectorPxPyPzE4D sumLorentz4D(Ts... ps){
    LorentzVectorPxPyPzE4D null4D(0,0,0,0);
    return(null4D+...+ps);
}

LorentzVectorPxPyPzE4D sumLorentz4D(vector<LorentzVectorPxPyPzE4D> ps){
    LorentzVectorPxPyPzE4D sum_p(0,0,0,0);
    for(const LorentzVectorPxPyPzE4D& p : ps){sum_p += p;}
    return sum_p;    
}

double cosPhiC(vector<double> const& np1, vector<double> const& np2, vector<double> const& nt1, vector<double> const& nt2){
    double cosPhiCvalue = abs(dotProductND(crossProduct3D(np1, np2), crossProduct3D(nt1, nt2)))/(squareNormND(crossProduct3D(np1, np2))*squareNormND(crossProduct3D(nt1, nt2)));
    return cosPhiCvalue;
};

// ****************************************
// Backup - lambda version of the functions
// ****************************************

/*
auto crossZ = [](vector<double> v){
    std::vector<double> v_cross_z = {v.at(1), -v.at(0), 0};
    return v_cross_z;
};
auto dotProductND = [](vector<double> w1, vector<double> w2){
    assert(w1.size()==w2.size());
    return std::inner_product(w1.begin(), w1.end(), w2.begin(), 0.0);
};
auto normalize = [](
    std::vector<double> w1,
    std::vector<double> w2,
    double (*normND)(vector<double>)){
        return normND(w1)*normND(w2);
};
auto squareNormND = [](vector<double> w){
    return sqrt(std::accumulate(
                    w.begin(),
                    w.end(),
                    0.0,
                    [](double sq_sum, double elem){
                        return sq_sum+pow(elem,2);
    }));
};

// Compute b2 // type std::function<double(std::vector<double>,std::vector<double>)> //
auto b2 = [&crossZ, &dotProductND, &normalize, &squareNormND](
        std::vector<double> v1,
        std::vector<double> v2){
            return dotProductND(crossZ(v1),crossZ(v2))/normalize(v1,v2,squareNormND);
};

// Compute b4
auto b4 = [&dotProductND, &normalize, &squareNormND](vector<double> v1,vector<double> v2){
        vector<double> unit_z = {0,0,1};
        return dotProductND(v1,unit_z)*dotProductND(v2,unit_z)/normalize(v1,v2,squareNormND);
};
// compute cosPhiC using the equation
auto printVec = [](vector<double> v){
    std::for_each(v.begin(), v.end(), [](double a){std::cout << a << " ";});
};
auto lorentzTo3D = [](LorentzVectorPxPyPzE4D vec){
    vector<double> temp{vec.Px(), vec.Py(), vec.Pz()};
    return temp;
};
auto absVec = [](vector<double> v){
    return sqrt(std::accumulate(v.begin(), v.end(), 0., [](double sum, double e){return sum+e*e;}));
};
auto normalize = [absVec](vector<double> vec){
    double vec_length = absVec(vec);
    vector<double> temp;
    std::for_each(
            vec.begin(),
            vec.end(),
            [&](double a){
                temp.push_back(a/vec_length);
                });
    return temp;
};
auto cross = [](vector<double> v1, vector<double> v2){
    assert(v1.size() == 3 && v2.size() == 3);
    vector<double> v1xv2{v1.at(1)*v2.at(2)-v1.at(2)*v2.at(1), v1.at(2)*v2.at(0)-v1.at(0)*v2.at(2), v1.at(0)*v2.at(1)-v1.at(1)*v2.at(0)};
    return v1xv2;
};
auto dot = [](vector<double> v1, vector<double> v2){
    assert(v1.size() == v2.size());
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
};

auto cosPhiC = [&](vector<double> np1, vector<double> np2, vector<double> nt1, vector<double> nt2){
    double cosPhiCvalue = abs(dot(cross(np1, np2), cross(nt1, nt2)))/(absVec(cross(np1, np2))*absVec(cross(nt1, nt2)));
    return cosPhiCvalue;
};
*/
