#!/bin/bash
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
PROJECTDIR="/afs/cern.ch/work/m/mmurin/private/4TopYukawaSensitivity"
cd $PROJECTDIR
#source setup_each_time.sh
source /afs/cern.ch/user/m/mmurin/py3xgboost/bin/activate
echo "python xgboost/classifierXGBoost.py --ptcut $1 --nestim $2 --depth $3 --rate $4 --cols $5 --alp $6 --gam $7 --lam $8"
python xgboost/classifierXGBoost.py --ptcut $1 --nestim $2 --depth $3 --rate $4 --cols $5 --alp $6 --gam $7 --lam $8
#python classifierXGBoost.py --ptcut 200
#python classifierXGBoost.py --ptcut 350
#python classifierXGBoost.py --ptcut 500
