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
#$ -t 1-57

source /afs/in2p3.fr/throng/nemo/users/remoto/setup.sh

PATH_EXE=/afs/in2p3.fr/throng/nemo/users/remoto/work/NEMO3Ana/build/bin
PATH_OUT=/sps/nemo/scratch/remoto/nemo3/plot/plot_UPDATE_TECHNOTE_20151118/Collie

# E cut DEFAULT
if [ "${SGE_TASK_ID}" -eq "1" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_000.root    ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "2" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_000.root ${PATH_OUT}/CollieIO_En_RHC_L_000.root  ; fi
if [ "${SGE_TASK_ID}" -eq "3" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_000.root ${PATH_OUT}/CollieIO_En_RHC_E_000.root  ; fi

if [ "${SGE_TASK_ID}" -eq "4" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_000_m1s.root     ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "5" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_000_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_000.root  ; fi
if [ "${SGE_TASK_ID}" -eq "6" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_E_000_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_000.root  ; fi

if [ "${SGE_TASK_ID}" -eq "7" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_000_p1s.root     ${PATH_OUT}/CollieIO_En_MM_000.root     ; fi
if [ "${SGE_TASK_ID}" -eq "8" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_L_000_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_000.root  ; fi
if [ "${SGE_TASK_ID}" -eq "9" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_E_000_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_000.root  ; fi

# E cut 1 MeV
if [ "${SGE_TASK_ID}" -eq "10" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_100.root     ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "11" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_100.root  ${PATH_OUT}/CollieIO_En_RHC_L_100.root  ; fi
if [ "${SGE_TASK_ID}" -eq "12" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_100.root  ${PATH_OUT}/CollieIO_En_RHC_E_100.root  ; fi

if [ "${SGE_TASK_ID}" -eq "13" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_100_p1s.root     ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "14" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_L_100_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_100.root  ; fi
if [ "${SGE_TASK_ID}" -eq "15" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_E_100_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_100.root  ; fi

if [ "${SGE_TASK_ID}" -eq "16" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_100_p1s.root     ${PATH_OUT}/CollieIO_En_MM_100.root     ; fi
if [ "${SGE_TASK_ID}" -eq "17" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_100_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_100.root  ; fi
if [ "${SGE_TASK_ID}" -eq "18" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_E_100_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_100.root  ; fi

# E cut 1.5 MeV
if [ "${SGE_TASK_ID}" -eq "19" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_150.root     ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "20" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_150.root  ${PATH_OUT}/CollieIO_En_RHC_L_150.root  ; fi
if [ "${SGE_TASK_ID}" -eq "21" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_150.root  ${PATH_OUT}/CollieIO_En_RHC_E_150.root  ; fi

if [ "${SGE_TASK_ID}" -eq "22" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_150_p1s.root     ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "23" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_L_150_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_150.root  ; fi
if [ "${SGE_TASK_ID}" -eq "24" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_E_150_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_150.root  ; fi

if [ "${SGE_TASK_ID}" -eq "25" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_150_m1s.root     ${PATH_OUT}/CollieIO_En_MM_150.root     ; fi
if [ "${SGE_TASK_ID}" -eq "26" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_150_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_150.root  ; fi
if [ "${SGE_TASK_ID}" -eq "27" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_E_150_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_150.root  ; fi

# E cut 2.0 MeV
if [ "${SGE_TASK_ID}" -eq "28" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_200.root     ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "29" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_200.root  ${PATH_OUT}/CollieIO_En_RHC_L_200.root  ; fi
if [ "${SGE_TASK_ID}" -eq "30" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_200.root  ${PATH_OUT}/CollieIO_En_RHC_E_200.root  ; fi

if [ "${SGE_TASK_ID}" -eq "31" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_200_p1s.root     ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "32" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_L_200_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_200.root  ; fi
if [ "${SGE_TASK_ID}" -eq "33" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_E_200_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_200.root  ; fi

if [ "${SGE_TASK_ID}" -eq "34" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_200_m1s.root     ${PATH_OUT}/CollieIO_En_MM_200.root     ; fi
if [ "${SGE_TASK_ID}" -eq "35" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_200_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_200.root  ; fi
if [ "${SGE_TASK_ID}" -eq "36" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_E_200_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_200.root  ; fi

# E cut 2.5 MeV
if [ "${SGE_TASK_ID}" -eq "37" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_MM_250.root     ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi
if [ "${SGE_TASK_ID}" -eq "38" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_L_250.root  ${PATH_OUT}/CollieIO_En_RHC_L_250.root  ; fi
if [ "${SGE_TASK_ID}" -eq "39" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_En_RHC_E_250.root  ${PATH_OUT}/CollieIO_En_RHC_E_250.root  ; fi

if [ "${SGE_TASK_ID}" -eq "40" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_MM_250_p1s.root     ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi
if [ "${SGE_TASK_ID}" -eq "41" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_L_250_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_250.root  ; fi
if [ "${SGE_TASK_ID}" -eq "42" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_En_RHC_E_250_p1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_250.root  ; fi

if [ "${SGE_TASK_ID}" -eq "43" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_MM_250_m1s.root     ${PATH_OUT}/CollieIO_En_MM_250.root     ; fi
if [ "${SGE_TASK_ID}" -eq "44" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_L_250_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_L_250.root  ; fi
if [ "${SGE_TASK_ID}" -eq "45" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_En_RHC_E_250_m1s.root  ${PATH_OUT}/CollieIO_En_RHC_E_250.root  ; fi

# BDT
if [ "${SGE_TASK_ID}" -eq "46" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_MM.root    ${PATH_OUT}/CollieIO_BDT_MM.root    ; fi
if [ "${SGE_TASK_ID}" -eq "47" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_RHC_L.root ${PATH_OUT}/CollieIO_BDT_RHC_L.root ; fi 
if [ "${SGE_TASK_ID}" -eq "48" ]; then ${PATH_EXE}/collieLC ${PATH_OUT}/CollieLC_BDT_RHC_E.root ${PATH_OUT}/CollieIO_BDT_RHC_E.root ; fi 

if [ "${SGE_TASK_ID}" -eq "49" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_MM_m1s.root    ${PATH_OUT}/CollieIO_BDT_MM.root    ; fi
if [ "${SGE_TASK_ID}" -eq "40" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_RHC_L_m1s.root ${PATH_OUT}/CollieIO_BDT_RHC_L.root ; fi 
if [ "${SGE_TASK_ID}" -eq "51" ]; then ${PATH_EXE}/collieLC_m1s ${PATH_OUT}/CollieLC_BDT_RHC_E_m1s.root ${PATH_OUT}/CollieIO_BDT_RHC_E.root ; fi 

if [ "${SGE_TASK_ID}" -eq "52" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_MM_p1s.root    ${PATH_OUT}/CollieIO_BDT_MM.root    ; fi
if [ "${SGE_TASK_ID}" -eq "53" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_RHC_L_p1s.root ${PATH_OUT}/CollieIO_BDT_RHC_L.root ; fi 
if [ "${SGE_TASK_ID}" -eq "54" ]; then ${PATH_EXE}/collieLC_p1s ${PATH_OUT}/CollieLC_BDT_RHC_E_p1s.root ${PATH_OUT}/CollieIO_BDT_RHC_E.root ; fi 

