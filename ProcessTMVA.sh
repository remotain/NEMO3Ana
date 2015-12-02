#!/bin/bash
#$ -l ct=20:00:00
#$ -l vmem=2048M
#$ -l os=sl6
#$ -P P_nemo
#$ -l sps=1
#$ -N ProcessTMVA
#$ -V
#$ -j y
#$ -o /sps/nemo/scratch/remoto/nemo3/plot/
#$ -t 1-10

source /usr/local/root/v5.34.18/bin/thisroot.sh 

#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"MM\" ,${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"RHC_L\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"RHC_E\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M1\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M2\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M3\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"
#root -b -q /afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/macro/TMVAClassificationApplication.C"(\"\",\"M7\",${SGE_TASK_ID} , ${SGE_TASK_LAST})"