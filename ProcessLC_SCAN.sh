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
#$ -t 1-30

source /afs/in2p3.fr/throng/nemo/users/remoto/setup.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

# E
if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_000.root ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_100.root ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_150.root ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "4" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_200.root ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "5" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_250.root ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi

if [ "${SGE_TASK_ID}" -eq "6" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_000_m1s.root ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "7" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_100_m1s.root ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "8" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_150_m1s.root ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "9" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_200_m1s.root ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "10" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_250_m1s.root ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi

if [ "${SGE_TASK_ID}" -eq "11" ]; then ${PATH_EXE}/Collielc_p1s ${PATH_OUT}/CollieLC_En_MM_000_p1s.root ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "12" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_100_p1s.root ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "13" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_150_p1s.root ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "14" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_200_p1s.root ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "15" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_250_p1s.root ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi

# BDT
if [ "${SGE_TASK_ID}" -eq "16" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_-020.root ${PATH_OUT}/CollieIO_BDT_MM_-020.root     ; fi
if [ "${SGE_TASK_ID}" -eq "17" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_-010.root ${PATH_OUT}/CollieIO_BDT_MM_-010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "18" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_000.root ${PATH_OUT}/CollieIO_BDT_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "19" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_010.root ${PATH_OUT}/CollieIO_BDT_MM_010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "20" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM_020.root ${PATH_OUT}/CollieIO_BDT_MM_020.root     ; fi

if [ "${SGE_TASK_ID}" -eq "21" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_-020_m1s.root ${PATH_OUT}/CollieIO_BDT_MM_-020.root     ; fi
if [ "${SGE_TASK_ID}" -eq "22" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_-010_m1s.root ${PATH_OUT}/CollieIO_BDT_MM_-010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "23" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_000_m1s.root ${PATH_OUT}/CollieIO_BDT_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "24" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_010_m1s.root ${PATH_OUT}/CollieIO_BDT_MM_010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "25" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_020_m1s.root ${PATH_OUT}/CollieIO_BDT_MM_020.root     ; fi

if [ "${SGE_TASK_ID}" -eq "26" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_-020_p1s.root ${PATH_OUT}/CollieIO_BDT_MM_-020.root     ; fi
if [ "${SGE_TASK_ID}" -eq "27" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_-010_p1s.root ${PATH_OUT}/CollieIO_BDT_MM_-010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "28" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_000_p1s.root ${PATH_OUT}/CollieIO_BDT_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "29" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_010_p1s.root ${PATH_OUT}/CollieIO_BDT_MM_010.root     ; fi
if [ "${SGE_TASK_ID}" -eq "30" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_020_p1s.root ${PATH_OUT}/CollieIO_BDT_MM_020.root     ; fi
