# 4TopYukawaSensitivity
The 4TopYukawaSensitivity is a software framework designed for sensitivity studies of the four top quark production (tttt) to the top-Higgs Yukawa coupling.

# Introduction
This software was designed by the author, a PhD student, as a part of his particle physics research project.

## Physics context
Understanding the interaction between the Higgs boson and the top quark is of profound importance in particle physics research. The top quark is the heaviest known elementary particle and its coupling to the Higgs boson (referred to as top-Yukawa coupling) is particularly strong. This makes the top quark a sensitive probe of the Higgs mechanism and the properties of the Higgs boson. At high-energy particle collisions, such as the proton-proton collisitions at the Large Hadron Collider (LHC) at CERN, top quarks may be produced in many different processes. One of rarest and most spectacular of these is the tttt production, whose cross section is more than 10000 times lower than that of the top-antitop pair production. The tttt production may be mediated by the Higgs boson in addition to quantum chromodynamics (QCD) and electroweak (EW) mediation. The presence of two Htt vertices in the tttt production provides an enhanced sensitivity to the properties of the top-Yukawa coupling, namely the magnitude and the mixing angle between the CP-even and CP-odd states. These properties are parameterised using an effective field theory extension to the Standard Model Lagrangian.

In this project, the effect of varying the top-Yukawa coupling on the kinematic observables of the tttt events is studied at the parton level. The distributions of a number of kinematic observables are calculated from the four-momenta of the outgoing top quarks. They are compared for samples of events with coupling strengths enhanced by factors of 2 and 5, and for CP-mixing angles with the values of 0&deg; (CP-even), 45&deg; (CP-mixed) and 90&deg; (CP-odd).

Experimental limitations are also considered. Final state hadrons (b quarks and light quarks) and leptons (electrons and muons) are associated with top quarks based on parton history. They are then matched to particle jets. This method allows to estimate the fraction of the top quarks, whose decay products may be reconstructed by the detector given its acceptance range.

## About the framework
This framework is a ROOT macro. It runs in two different modes, either using non-decayed top quarks from MadGraph, or decayed and parton-showered top quarks with reconstructed particle jets from MadGraph+MadSpin+Pythia+Delphes. As the input, it uses simulated samples of tttt production in LHE format. The paths to the data files are defined in *TChainsMaker*. The main script is the *MacroMain.C*. The parton-level kinematic observables are defined in *Observables*, which are derived from a base class defined in *GeneralPlot*. This design streamlines the calculation and plotting. Variables defined for particle jets are defined in *ObservablesTruthJetMatch*. These are based on the tttt event object, which stores the information about the four top quarks and their particle-jet-matching categories, as implemented in *TruthEvent4Top*. Each top quark is an object of *GenTopParticle* class, which stores the information about its decay products. These are calculated for each of the four top quarks in each event using the parton history.

# Features
The capability of this framework include:
- producing plots for kinematic observables in tttt events based on parton-level four-momenta
- producing plots for variables related to particle-jet-matching performance
- the sets of kinematic observables and particle-jet-matching variables are easily extensible
- for large input samples, the framework can be executed on Condor high performance cluster
- the distributions of the observables are stored as histograms in an output file for further plotting and as in input to the MVA analysis
- training a boosted decision tree binary classifier (XGBoost) to distinuish between CP-even and CP-odd top-Yukawa coupling
- hyperparameter optimisation of the BDT classifier using a grid scan
- the BDT training jobs may be submitted to Condor high performance cluster and utilise GPUs

# Setup
## Prerequisites
This framework was designed to run on LXPLUS (Linux Public Login User Service at CERN). In principle, it should work elsewhere if the dependency requirements below are met (except the submission to Condor).

## Dependencies
- ROOT 6.22 (or higher)
- ExRootAnalysis 1.1.5
- Delphes (if Delphes classes GenParticle and GenJet are used)
- Python 3.9 and the following packages:
    - awkward 1.8.0
    - matplotlib 3.5.2
    - numpy 1.23.0
    - scikit-learn 1.1.1
    - scipy 1.8.1
    - seaborn 0.12.2
    - sklearn 0.0
    - six 1.16.0
    - uproot 4.3.3
    - xgboost 1.6.1

## Installation
1. Download this repository
```
git clone -b master https://github.com/martin-murin/4TopYukawaSensitivity.git
```
2. Edit paths for relevant dependencies in `setup_each_time.sh`
3. Edit `PROJECTDIR` in `run_macro.sh`
4. Edit the path to the Delphes library in `framework/run_macro.C`
5. Edit paths to input files in `framework/TChainsMaker.cxx`
6. Optionally edit `productionName` (the name of the output directory) in `framework/MacroMain.C`
7. For setting up the XGBoost script, edit paths for `PROJECTDIR` and python environment in `xgboost/classifierXGBoost.sh` and `workspace` to use in `xgboost/classifierXGBoost.py` 

## Run
### Run framework locally
Run the framework with `./run_macro.sh` which sets up the environment and launches the ROOT macro `framework/MacroMain.C`
    - Options for sample set are listed in `framework/LocalTools.h`. The paths to the different sample sets are defined in `framework/TChainsMaker.cxx`
    - Options for Yukawa set are `alpha` and `kappa` for sample sets with varying CP-mixing angle or varying coupling strength, respectively

### Submit to Condor
Submit the job to Condor simply as `condor_submit run_macro.sub` (on LXPLUS only)

### Run XGBoost classifier locally
Run XGBoost classifier either by
    - directly running the python script `python xgboost/classifierXGBoost.py --ptcut <ptcut> --nestim <nestim> --depth <depth> --rate <rate> --cols <cols> --alp <alp> --gam <gam> --lam <lam>`
    - using the shell script `source xgboost/classifierXGBoost.sh <ptcut> <nestim> <depth> <rate> <cols> <alp> <gam> <lam>`

### Submit XGBoost jobs to Condor
Use `./submit_xgboost.sh` to submit jobs to Condor. This allows submission of mutliple jobs in parallel, one for each set of hyperparameters.

# Credit
Primary developer and contact: Martin Murin (martin.murin@cern.ch) 
