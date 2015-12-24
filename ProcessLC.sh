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
#$ -t 1-18

source /afs/in2p3.fr/throng/nemo/users/remoto/setup.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_DEF.root              ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_DEF_m1s.root      ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_DEF_p1s.root      ${PATH_OUT}/CollieIO_En_MM_DEF.root     ; fi

if [ "${SGE_TASK_ID}" -eq "4" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_DEF.root             ${PATH_OUT}/CollieIO_BDT_MM_DEF.root    ; fi
if [ "${SGE_TASK_ID}" -eq "5" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_DEF_m1s.root     ${PATH_OUT}/CollieIO_BDT_MM_DEF.root    ; fi
if [ "${SGE_TASK_ID}" -eq "6" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_DEF_p1s.root     ${PATH_OUT}/CollieIO_BDT_MM_DEF.root    ; fi

if [ "${SGE_TASK_ID}" -eq "7" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_DEF.root           ${PATH_OUT}/CollieIO_En_RHC_L_DEF.root  ; fi
if [ "${SGE_TASK_ID}" -eq "8" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_DEF_m1s.root   ${PATH_OUT}/CollieIO_En_RHC_L_DEF.root  ; fi
if [ "${SGE_TASK_ID}" -eq "9" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_RHC_L_p1s.root    ${PATH_OUT}/CollieIO_En_RHC_L_DEF.root  ; fi

if [ "${SGE_TASK_ID}" -eq "10" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_RHC_L_DEF.root          ${PATH_OUT}/CollieIO_BDT_RHC_L_DEF.root ; fi
if [ "${SGE_TASK_ID}" -eq "11" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_RHC_L_DEF_m1s.root  ${PATH_OUT}/CollieIO_BDT_RHC_L_DEF.root ; fi
if [ "${SGE_TASK_ID}" -eq "12" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_RHC_L_DEF_p1s.root  ${PATH_OUT}/CollieIO_BDT_RHC_L_DEF.root ; fi

if [ "${SGE_TASK_ID}" -eq "13" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_DEF.root          ${PATH_OUT}/CollieIO_En_RHC_E_DEF.root  ; fi
if [ "${SGE_TASK_ID}" -eq "14" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_RHC_E_m1s.root   ${PATH_OUT}/CollieIO_En_RHC_E_DEF.root  ; fi
if [ "${SGE_TASK_ID}" -eq "15" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_RHC_E_p1s.root   ${PATH_OUT}/CollieIO_En_RHC_E_DEF.root  ; fi

if [ "${SGE_TASK_ID}" -eq "16" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_RHC_E_DEF.root         ${PATH_OUT}/CollieIO_BDT_RHC_E_DEF.root ; fi
if [ "${SGE_TASK_ID}" -eq "17" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_RHC_E_DEF_m1s.root ${PATH_OUT}/CollieIO_BDT_RHC_E_DEF.root ; fi
if [ "${SGE_TASK_ID}" -eq "18" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_RHC_E_DEF_p1s.root ${PATH_OUT}/CollieIO_BDT_RHC_E_DEF.root ; fi

