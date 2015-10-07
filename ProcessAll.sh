#!/bin/bash
#$ -l ct=10:00:00
#$ -l vmem=2048M
#$ -l os=sl6
#$ -P P_nemo
#$ -l sps=1
#$ -N ProcessAllChannel
#$ -V
#$ -j y
#$ -o /sps/nemo/scratch/remoto/nemo3/plot/
#
################################################################################
# Submit channel selection jobs
################################################################################
#
#source /afs/in2p3.fr/throng/nemo/users/remoto/setup.sh 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectron.C+ 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectronOneGammaExt.C+ 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectronOneGammaInt.C+ 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectronTwoGammaInt.C+
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectronThreeGammaInt.C+
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessTwoElectronExt.C+ 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessTwoElectronInt.C+ 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/ProcessOneElectronOneAlpha.C+ 
#
################################################################################
# Submit TMVA jobs
################################################################################
#
source /usr/local/root/v5.34.18/bin/thisroot.sh 
root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassification.C+
