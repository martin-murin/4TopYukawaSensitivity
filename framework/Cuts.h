#include<classes/DelphesClasses.h>
#include<LocalTools.h>

namespace Cuts {

    bool leadingTopPT(TClonesArray* branchParticle, double cutPT);
    bool ttbarPT(TClonesArray* branchParticle, double cutPT);
    bool channelSSML(TClonesArray* branchParticle);
    bool channel2L(TClonesArray* branchParticle);

}

namespace Selections {

    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> tt_samesign(TClonesArray* branchParticle, int sign);
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_minDR(TClonesArray* branchParticle);
    std::pair<LorentzVectorPxPyPzE4D, LorentzVectorPxPyPzE4D> ttbar_leadPT_minDR(TClonesArray* branchParticle);

}
