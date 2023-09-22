setupATLAS --quiet
lsetup "root 6.22.00-python3-x86_64-centos7-gcc8-opt"
#lsetup "root 6.22.00-x86_64-centos7-gcc8-opt"
#lsetup "root 6.20.06-x86_64-centos7-gcc8-opt"

lsetup python

#export LD_LIBRARY_PATH=/afs/cern.ch/work/m/mmurin/public/ExRootAnalysis:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/ExRootAnalysis:$LD_LIBRARY_PATH
#export LD_LIBRARY_PATH=/afs/cern.ch/work/m/mmurin/private/4top/4top_CP_truth_studies/ExRootAnalysis:$LD_LIBRARY_PATH

#export LD_LIBRARY_PATH=/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/Delphes:$LD_LIBRARY_PATH

export ROOT_INCLUDE_PATH=/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/Delphes:$ROOT_INCLUDE_PATH
export ROOT_INCLUDE_PATH=/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/ExRootAnalysis:$ROOT_INCLUDE_PATH
export ROOT_INCLUDE_PATH=/afs/cern.ch/work/m/mmurin/private/MG5_aMC_v3_4_1/MG5_aMC_v3_4_1/Delphes/external:$ROOT_INCLUDE_PATH
