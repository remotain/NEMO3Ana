#!/bin/bash
#$ -l ct=20:00:00
#$ -l vmem=2048M
#$ -l os=sl6
#$ -P P_nemo
#$ -l sps=1
#$ -N ProcessCL
#$ -V
#$ -j y
#$ -o /sps/nemo/scratch/remoto/nemo3/plot/
#$ -t 1-3

source /afs/in2p3.fr/throng/nemo/users/remoto/setup.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_DEF.root    ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_DEF_m1s.root     ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_DEF_p1s.root     ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi

if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_DEF.root    ${PATH_OUT}/CollieIO_BDT_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_DEF_m1s.root     ${PATH_OUT}/CollieIO_BDT_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_DEF_p1s.root     ${PATH_OUT}/CollieIO_BDT_MM_DEF.root     ; fi

