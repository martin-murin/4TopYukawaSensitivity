#ifndef TCHAINSMAKER_H
#define TCHAINSMAKER_H

#include<TROOT.h>
#include<LocalTools.h>

void create_chain_kt_0_alpha_0(TChain &chain_kt_0_alpha_0, SampleSet sampleSet);
void create_chain_kt_1_alpha_0(TChain &chain_kt_1_alpha_0, SampleSet sampleSet);
void create_chain_kt_2_alpha_0(TChain &chain_kt_2_alpha_0, SampleSet sampleSet);
void create_chain_kt_5_alpha_0(TChain &chain_kt_5_alpha_0, SampleSet sampleSet);
void create_chain_kt_1_alpha_45(TChain &chain_kt_1_alpha_45, SampleSet sampleSet);
void create_chain_kt_1_alpha_90(TChain &chain_kt_1_alpha_90, SampleSet sampleSet);
void create_chain_single(TChain &chain_single);
void create_chain_compare1(TChain &chain_single);
void create_chain_compare2(TChain &chain_single);

#endif
