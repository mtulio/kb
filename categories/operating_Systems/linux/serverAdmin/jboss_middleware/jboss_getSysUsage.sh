#!/bin/bash
#
# jboss_getSysUsage.sh - Get system usage and infos from Jboss Daemon
#	INCOMPLETE - Needs to test and generalize script
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: 15 Aug 2015
# modified: 15 Aug 2015
#
#######################################


# Obtendo date
DATE_NOW="$(date +%Y%m%d-%H:%m:%d)"

# Obtendo uptime
UPTIME="$(uptime |awk -F'up' '{print$2}' |awk -F',' '{print$1}')"

# Obtendo proc N
PROC_TOTAL="$(ps aux |wc -l)"

# Obtendo sockets abertos
FD_OPEN="$(cat /proc/sys/fs/file-nr |awk '{print$1}')"
FD_TOTAL="$(cat /proc/sys/fs/file-nr |awk '{print$3}')"

# Obtendo free memory
MEM_TT="$(cat /proc/meminfo |grep MemTotal |awk '{print$2}')"
MEM_FR="$(cat /proc/meminfo |grep MemFree |awk '{print$2}')"
MEM_AV="$(cat /proc/meminfo |grep MemAvailable |awk '{print$2}')"


# Obtendo sockets abertos por PID JBOSS
PID_JBOSS_NAME="sleep"
PID_JBOSS_CTPS="$(ps aux |grep $PID_JBOSS_NAME |grep CTPS)"

PID_JBOSS_LIST="$(ps aux |grep $PID_JBOSS_NAME)"


# Print log
echo "$DATE_NOW;UPTIME=$UPTIME;PROC_TOTAL=$PROC_TOTAL;PROC_TOTAL=$PROC_TOTAL;FD_OPEN=$FD_OPEN ,FD_TOTAL=$FD_TOTAL;MEM_TT_Kb=$MEM_TT,MEM_FR_Kb=$MEM_FR,MEM_AV_Kb=$MEM_AV"

