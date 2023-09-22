#!/bin/bash
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh
PROJECTDIR="/afs/cern.ch/work/m/mmurin/private/4TopYukawaSensitivity"
cd $PROJECTDIR
source setup_each_time.sh
cd framework
root -b -q -l 'run_macro.C("control","alpha")'
cd ..
