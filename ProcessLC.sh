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
#$ -t 1-6

source /usr/local/root/v5.34.18/bin/thisroot.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

#${SGE_TASK_ID}

if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_MM.root     ${PATH_OUT}/CollieIO_En_MM.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_RHC_L.root  ${PATH_OUT}/CollieIO_En_RHC_L.root  ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_En_RHC_E.root  ${PATH_OUT}/CollieIO_En_RHC_E.root  ; fi
if [ "${SGE_TASK_ID}" -eq "4" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_MM.root    ${PATH_OUT}/CollieIO_BDT_MM.root    ; fi
if [ "${SGE_TASK_ID}" -eq "5" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_RHC_L.root ${PATH_OUT}/CollieIO_BDT_RHC_L.root ; fi 
if [ "${SGE_TASK_ID}" -eq "6" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieCL_BDT_RHC_E.root ${PATH_OUT}/CollieIO_BDT_RHC_E.root ; fi 
