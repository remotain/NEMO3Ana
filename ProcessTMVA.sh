#!/bin/bash
#$ -l ct=50:00:00
#$ -l vmem=2048M
#$ -l os=sl6
#$ -P P_nemo
#$ -l sps=1
#$ -N ProcessTMVA
#$ -V
#$ -j y
#$ -o /sps/nemo/scratch/remoto/nemo3/plot/
#
# TO BE SUBMITTED AS
# qsub -t 1-34 ProcessTMVA.sh
#source /usr/local/root/v5.34.18/bin/thisroot.sh 
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\", ${SGE_TASK_ID})"

#root -b -q macro/TMVAClassification.C"(\"\", \"MM\"  )"
#root -b -q macro/TMVAClassification.C"(\"\", \"RHC\" )"
#root -b -q macro/TMVAClassification.C"(\"\", \"M1\"  )"
#root -b -q macro/TMVAClassification.C"(\"\", \"M2\"  )"
#root -b -q macro/TMVAClassification.C"(\"\", \"M3\"  )"
#root -b -q macro/TMVAClassification.C"(\"\", \"M7\"  )"


#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"MM\" )"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"RHC\")"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M1\" )"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M2\" )"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M3\" )"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M7\" )"