#! /bin/bash

mk_folders () {
    echo "Cleaning condor directory"
    rm -rf condor/xgboost
    mkdir -p condor/xgboost/input
    mkdir -p condor/xgboost/output
    mkdir -p condor/xgboost/error
    mkdir -p condor/xgboost/log
}

mk_folders

MAIN=$(pwd)
PARAMSFILE='condor/xgboost/input/permutations.txt'

# Create space-points for grid scan hyperparameter optimisation
for PTCUT in 200 350
do
    for NESTIM in 500 1000
    do
        for DEPTH in 2 3
        do
            for RATE in 0.008 
            do
                for COLS in 0.5
                do
                    for ALP in 0 10 
                    do
                        for GAM in 0
                        do
                            for LAM in 1
                            do
                                echo $PTCUT $NESTIM $DEPTH $RATE $COLS $ALP $GAM $LAM >> $PARAMSFILE
                            done
                        done
                    done
                done
            done
        done
    done
done
condor_submit xgboost.sub --append "queue ptcut, nestim, depth, rate, cols, alp, gam, lam from $PARAMSFILE"
