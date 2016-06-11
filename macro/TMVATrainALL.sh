#!/bin/bash

source /Users/alberto/Software/ROOT/root.git/bin/thisroot.sh

root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"MM\"    )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"RHC_L\" )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"RHC_E\" )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"M1\"    )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"M2\"    )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"M3\"    )";
root -b -q /Users/alberto/Software/SuperNEMO/work/nemo3/NEMO3Ana/macro/TMVAClassification.C"( \"BDT\" , \"M7\"    )";

