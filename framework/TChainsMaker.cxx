#include<LocalTools.h>
#include<TChainsMaker.h>
void create_chain_kt_0_alpha_0(TChain &chain_kt_0_alpha_0, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGLO_Higgs:
            // // Higgs only 4 top process - no decay

            // // TODO Higgs only 4 top process - with decay
            break;

        case SampleSet::MGLO_Inclusive:
            // // control 4 top process QCD+EW+Higgs - no decay
            
            // // control 4 top process QCD+EW+Higgs - with decay
            break;

        case SampleSet::ValidationSet:
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_1.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_2.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_3.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_4.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_5.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_6.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_7.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_8.lhe.root");
            chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_9.lhe.root");

            //chain_kt_0_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_0_alpha_0/validation_kt_0_alpha_0_10.lhe.root");
            break;

        case SampleSet::Debug:
            break;

    }

}

void create_chain_kt_1_alpha_0(TChain &chain_kt_1_alpha_0, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGPY8Delphes4TopsInclusive:
            // Inclusive 4 tops - with decay, parton shower, truth jets
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraphPythia8Delphes/prod221025_probe_CPeven_v1_decayed_1_tag_4_delphes_events.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/showered/prod220222_Incl_1M_CPeven/prod220222_Inclusive_1M_kt1_a0_delphes_1.root");
            std::cout << "Adding file";
            break;

        case SampleSet::MGLO_Higgs:
            // Higgs only 4 top process - with decay
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_9_decayed_1_unweighted_events.lhe.root");
            break;

        case SampleSet::MGLO_Inclusive:
            // control 4 top process QCD+EW+Higgs - with decay
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_9_decayed_1_unweighted_events.lhe.root");
            break;

        case SampleSet::ValidationSet:
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_1.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_2.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_3.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_4.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_5.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_6.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_7.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_8.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_9.lhe.root");

            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1000.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1001.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1002.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1003.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1004.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1005.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1006.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1007.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1008.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1009.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/physics_kt_1_alpha_0_1010.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_10.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_11.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_12.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_13.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_14.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_15.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_17.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_18.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_19.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_1.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_20.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_21.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_22.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_23.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_24.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_25.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_26.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_27.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_28.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_29.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_2.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_30.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_31.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_32.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_33.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_35.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_36.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_37.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_38.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_39.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_3.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_41.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_42.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_43.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_44.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_46.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_47.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_48.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_49.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_4.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_50.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_51.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_52.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_53.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_54.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_55.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_56.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_59.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_5.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_60.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_61.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_62.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_63.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_64.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_65.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_66.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_67.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_68.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_69.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_6.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_70.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_73.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_74.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_75.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_76.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_77.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_78.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_79.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_7.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_80.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_81.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_83.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_84.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_85.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_86.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_88.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_89.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_8.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_90.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_91.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_92.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_93.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_94.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_95.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_96.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_97.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_98.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_99.lhe.root");
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_0/validation_kt_1_alpha_0_9.lhe.root");
            break;

        case SampleSet::Debug:
            //chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a0_0_decayed_1_unweighted_events.lhe.root");
            break;
    }

}

void create_chain_kt_2_alpha_0(TChain &chain_kt_2_alpha_0, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGLO_Higgs:
            // Higgs only 4 top process - with decay
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_9_decayed_1_unweighted_events.lhe.root");

            break;

        case SampleSet::MGLO_Inclusive:
            // control 4 top process QCD+EW+Higgs - with decay
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_9_decayed_1_unweighted_events.lhe.root");
            break;

        case SampleSet::ValidationSet:
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_1.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_2.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_3.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_4.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_5.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_6.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_7.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_8.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_9.lhe.root");

            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1000.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1001.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1002.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1003.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1004.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1005.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1006.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1007.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1008.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1009.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/physics_kt_2_alpha_0_1010.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_100.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_10.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_12.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_17.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_1.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_22.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_24.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_25.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_26.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_28.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_2.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_31.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_33.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_35.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_36.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_37.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_38.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_39.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_3.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_41.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_43.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_44.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_45.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_48.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_49.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_4.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_50.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_51.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_53.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_54.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_55.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_56.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_57.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_59.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_5.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_60.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_61.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_62.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_63.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_64.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_65.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_66.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_67.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_68.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_6.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_70.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_72.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_74.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_76.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_77.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_7.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_80.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_83.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_88.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_89.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_8.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_91.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_96.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_97.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_98.lhe.root");
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_2_alpha_0/validation_kt_2_alpha_0_9.lhe.root");
            break;

        case SampleSet::Debug:
            //chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt2_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_2_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt2_a0_0_decayed_1_unweighted_events.lhe.root");
            break;
    }

}

void create_chain_kt_5_alpha_0(TChain &chain_kt_5_alpha_0, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGLO_Higgs:
            // Higgs only 4 top process - with decay
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_9_decayed_1_unweighted_events.lhe.root");
            break;

        case SampleSet::MGLO_Inclusive:
            // control 4 top process QCD+EW+Higgs - with decay
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_9_decayed_1_unweighted_events.lhe.root");
            break;
        
        case SampleSet::ValidationSet:
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_1.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_2.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_3.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_4.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_5.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_6.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_7.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_8.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_9.lhe.root");

            //chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_5_alpha_0/validation_kt_5_alpha_0_10.lhe.root");
            break;

        case SampleSet::Debug:
            //chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt5_a0_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_5_alpha_0.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt5_a0_0_decayed_1_unweighted_events.lhe.root");
            break;
    }

}

void create_chain_kt_1_alpha_45(TChain &chain_kt_1_alpha_45, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGPY8Delphes4TopsInclusive:
            // Inclusive 4 tops - with decay, parton shower, truth jets
            //chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraphPythia8Delphes/prod221025_probe_CPmix_v1_decayed_1_tag_4_delphes_events.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/showered/prod220222_Incl_1M_CPmix/prod220222_Inclusive_1M_kt1_a45_delphes_1.root");
            break;

        case SampleSet::MGLO_Higgs:
            // Higgs only 4 top process - with decay
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_9_decayed_1_unweighted_events.lhe.root");

            break;

        case SampleSet::MGLO_Inclusive:
            // control 4 top process QCD+EW+Higgs - with decay
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_9_decayed_1_unweighted_events.lhe.root");
            break;

        case SampleSet::ValidationSet:
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_1.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_2.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_3.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_4.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_5.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_6.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_7.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_8.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_9.lhe.root");
            
            //chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_45/validation_kt_1_alpha_45_10.lhe.root");
            break;

        case SampleSet::Debug:
            //chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a45_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_45.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a45_0_decayed_1_unweighted_events.lhe.root");
            break;
    }

}

void create_chain_kt_1_alpha_90(TChain &chain_kt_1_alpha_90, SampleSet sampleSet){

    switch (sampleSet){
        case SampleSet::MGPY8Delphes4TopsInclusive:
            // Inclusive 4 tops - with decay, parton shower, truth jets
            //chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraphPythia8Delphes/prod221025_probe_CPodd_v1_decayed_1_tag_4_delphes_events.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/showered/prod220222_Incl_1M_CPodd/prod220222_Inclusive_1M_kt1_a90_delphes_1.root");
            break;

        case SampleSet::MGLO_Higgs:
            // Higgs only 4 top process - with decay
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_9_decayed_1_unweighted_events.lhe.root");

            break;

        case SampleSet::MGLO_Inclusive:
            // control 4 top process QCD+EW+Higgs - with decay
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_1_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_2_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_3_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_4_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_5_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_6_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_7_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_8_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_9_decayed_1_unweighted_events.lhe.root");

            break;

        case SampleSet::ValidationSet:
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_1.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_2.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_3.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_4.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_5.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_6.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_7.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_8.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_9.lhe.root");
            
            //chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_validation_data/validation_kt_1_alpha_90/validation_kt_1_alpha_90_10.lhe.root");
            break;

        case SampleSet::Debug:
            //chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Higgs_1M_kt1_a90_0_decayed_1_unweighted_events.lhe.root");
            chain_kt_1_alpha_90.Add("/eos/user/m/mmurin/4top_CP_truth_studies_MadGraph1M/decayed/prod220222_Incl_1M_kt1_a90_0_decayed_1_unweighted_events.lhe.root");
            break;
    }

}

void create_chain_single(TChain &chain_single){
    chain_single.Add("/afs/cern.ch/work/m/mmurin/private/MadGraph5_aMCatNLO/MG5_aMC_v3_2_0/PROC_HC_NLO_X0_UFO-no_b_mass_tttt_0/Events/run_01/unweighted_events.lhe.root");
}

void create_chain_compare1(TChain &chain_single){
    chain_single.Add("/afs/cern.ch/work/m/mmurin/private/MadGraph5_aMCatNLO/MG5_aMC_v3_2_0/PROC_HC_NLO_X0_UFO-no_b_mass_tttt_1/Events/run_events80k_kt1_a0/unweighted_events.lhe.root");
}

void create_chain_compare2(TChain &chain_single){
    chain_single.Add("/afs/cern.ch/work/m/mmurin/private/MadGraph5_aMCatNLO/MG5_aMC_v3_2_0/PROC_HC_NLO_X0_UFO-no_b_mass_tttt_1/Events/run_events80k_kt1_a90/unweighted_events.lhe.root");
}

