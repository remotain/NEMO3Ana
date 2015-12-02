#!/bin/bash
#$ -l ct=10:00:00
#$ -l vmem=2048M
#$ -l os=sl6
#$ -P P_nemo
#$ -l sps=1
#$ -N ProcessCL
#$ -V
#$ -j y
#$ -o /sps/nemo/scratch/remoto/nemo3/plot/

source /usr/local/root/v5.34.18/bin/thisroot.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_MM.root    ${PATH_OUT}/CollieIO_En_MM.root 
./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_RHC_L.root ${PATH_OUT}/CollieIO_En_RHC_L.root 
./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_RHC_E.root ${PATH_OUT}/CollieIO_En_RHC_E.root 

./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_MM.root    ${PATH_OUT}/CollieIO_BDT_MM.root 
./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_RHC_L.root ${PATH_OUT}/CollieIO_BDT_RHC_L.root 
./${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_RHC_E.root ${PATH_OUT}/CollieIO_BDT_RHC_E.root 
