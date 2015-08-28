#!/bin/bash

#
# get_System_Information.sh - Get TCP and Sockets information from your Linux System, and
#       then, if you set option -s, you can save the current data to a file
#        See FILE_STDOUT to change filename.
#	You'll get more if:
#	-> use watch to see in real time and constantly update
#	-> schedule, with -s option, in crontab to see logs later (Needs to finish, standarize, the log output)
#
# References:
# 	- See TCP states machine: http://www.tcpipguide.com/free/t_TCPOperationalOverviewandtheTCPFiniteStateMachineF-2.htm
#
# Author: Marco Tulio R Braga
# Created at 25, Aug 2015
# Changed at 27, Aug 2015
#

#######################################
# Globals & Parameter validation

LAST_DATA_CONFIG_FILE="$(basename --suffix='.sh' $0 |awk -F'get_' '{print$2}')-latest.cfg"

DATE_NOW="$(date +%Y-%m-%d_%H:%M:%S)"
FILE_TMP="$(mktemp)"
FILE_STDOUT="data_tcp.csv"

LAST_GET="${DATE_NOW}"

## Available TCP_IP States - See reference
# Some of these will be used.
AVAILABLE_STATES="established
syn-sent
syn-recv
fin-wait-1
fin-wait-2
time-wait
closed
close-wait
last-ack
listen
closing
all
connected
synchronized
bucket.
big"

COUNT=0;


#######################################
# Get TCP connections and CSV it to CSV file
# Globals:
#    FILE_TMP
#    FILE_STDOUT
# Arguments:
#    None
# Returns:
#    FILE_STDOUT
#######################################

GET_CONNECTIONS() {
  
  # Get TCP connections
  LANG=en netstat -nat |grep -ve ^[A,P] |awk '{print$6}'|sort |uniq -c |awk '{print$2";"$1}' |sort |tr '[:upper:]' '[:lower:]' > ${FILE_TMP}
  #cat ${FILE_TMP}

  # Count it and save in envs
  while read LINE
  do

    NAME="$(echo $LINE |awk -F';' '{print$1}')"
    VALUE="$(echo $LINE |awk -F';' '{print$2}')"

    if [ "${NAME}" == "established" ]; then FIELD01=$VALUE 
    elif [ "${NAME}" == "syn-sent" ]; then FIELD02=$VALUE 
    elif [ "${NAME}" == "syn-recv" ]; then FIELD03=$VALUE 
    elif [ "${NAME}" == "fin-wait-1" ]; then FIELD04=$VALUE 
    elif [ "${NAME}" == "fin-wait-2" ]; then FIELD05=$VALUE 
    elif [ "${NAME}" == "time-wait" ]; then FIELD06=$VALUE 
    elif [ "${NAME}" == "closed" ]; then FIELD07=$VALUE 
    elif [ "${NAME}" == "close-wait" ]; then FIELD08=$VALUE 
    elif [ "${NAME}" == "last-ack" ]; then FIELD09=$VALUE 
    elif [ "${NAME}" == "listen" ]; then FIELD10=$VALUE 
    elif [ "${NAME}" == "closing" ]; then FIELD11=$VALUE 
    fi

    COUNT=$(expr $COUNT + $VALUE)
  done < ${FILE_TMP}

  # Get socks TCP
  SS_PROC_ALL="$(LANG=en ss -p |wc -l |awk '{print$1}')"
  SS_SOCK_SYS_ALL="$(LANG=en ss -s |grep Total: |awk '{print$2}')"
  SS_SOCK_KERN_ALL="$(LANG=en ss -s |grep Total: |awk -F")" '{print$1}' |awk '{print$4}')"
  SS_SOCK_TCP_ALL="$(LANG=en ss -s |grep ^TCP: |awk '{print$2}')"
  SS_SOCK_TT_RAW="$(LANG=en ss -s |grep ^RAW |awk '{print$2}')"
  SS_SOCK_TT_TCP="$(LANG=en ss -s |grep -ve ^TCP: |grep ^TCP |awk '{print$2}')"
  SS_SOCK_TT_UDP="$(LANG=en ss -s |grep ^UDP |awk '{print$2}')"
  SS_SOCK_TT_INET="$(LANG=en ss -s |grep ^INET |awk '{print$2}')"
  SS_SOCK_TT_FRAG="$(LANG=en ss -s |grep ^FRAG |awk '{print$2}')"

  # Zero blank/empty fields
  if [ "${FIELD01}x" == "x" ]; then FIELD01=0; fi
  if [ "${FIELD02}x" == "x" ]; then FIELD02=0; fi
  if [ "${FIELD03}x" == "x" ]; then FIELD03=0; fi
  if [ "${FIELD04}x" == "x" ]; then FIELD04=0; fi
  if [ "${FIELD05}x" == "x" ]; then FIELD05=0; fi
  if [ "${FIELD06}x" == "x" ]; then FIELD06=0; fi
  if [ "${FIELD07}x" == "x" ]; then FIELD07=0; fi
  if [ "${FIELD08}x" == "x" ]; then FIELD08=0; fi
  if [ "${FIELD09}x" == "x" ]; then FIELD09=0; fi
  if [ "${FIELD10}x" == "x" ]; then FIELD10=0; fi
  if [ "${FIELD11}x" == "x" ]; then FIELD11=0; fi

  #echo "FIELD01=[$FIELD01] FIELD02=[$FIELD02] FIELD03=[$FIELD03] FIELD04=[$FIELD04] FIELD05=[$FIELD05] FIELD06=[$FIELD06] FIELD07=[$FIELD07] FIELD08=[$FIELD08] FIELD09=[$FIELD09] FIELD10=[$FIELD10] FIELD11=[$FIELD11]"

  # Saving data to file FILE_STDOUT
  #DATE_NOW;established;syn-sent;syn-recv;fin-wait-1;fin-wait-2;time-wait;closed;close-wait;last-ack;listen;closing
  ARRAY="${DATE_NOW};NT_ALL[${COUNT}];NT_ESTABLISHED[${FIELD01}];N_SYN-S[${FIELD02}];N_SYN-R[${FIELD03}];N_FIN-W1[${FIELD04}];N_FIN-W2[${FIELD05}];N_TIME-W[${FIELD06}];N_CLOSED[${FIELD07}];N_CLOSE-W[${FIELD08}];N_LAST-ACK[${FIELD09}];N_LISTEN[${FIELD10}];N_CLOSING[${FIELD11}];S_ProcAll[${SS_PROC_ALL}];S_SockSys[${SS_SOCK_SYS_ALL}];S_SockKern[${SS_SOCK_KERN_ALL}];S_SockTcpAll[${SS_SOCK_TCP_ALL}];S_SockRaw[${SS_SOCK_TT_RAW}];S_SockTcp[${SS_SOCK_TT_TCP}];S_SockUdp[${SS_SOCK_TT_UDP}];S_SockInet[${SS_SOCK_TT_INET}];S_SockFrag[${SS_SOCK_TT_FRAG}]"

  # Show betther using watch:
  echo -e "\t\t\t .:: GET TCP and Sockets Information ::."

  if [ "$(whoami)" != "root" ]; then
    echo -e " "
    echo "#% WARN: if you run by root, you'll get more details	"
  fi

  echo -e " "
  echo -e "\t\t\t\tTCP Connections"
  echo -e "DATE\t\tCount:\tEstbli\tSYN-Snt\tSYN-Rcv\tFIN-W1\tFIN-W2\tTime-W\tClosed\tClose-W\tL-ACK\tLISTEN\tCLOSING"
  echo -e "$(echo ${DATE_NOW}|awk -F'_' '{print$2}')\t${COUNT}\t${FIELD01}\t${FIELD02}\t${FIELD03}\t${FIELD04}\t${FIELD05}\t${FIELD06}\t${FIELD07}\t${FIELD08}\t${FIELD09}\t${FIELD10}\t${FIELD11}"
  echo " "
  echo -e "\t\t\t\t Sockets Information"
  echo -e "\t\tProcAll\tSystem\tKernel\tTcp_All\tRAW\tTCP\tUDP\tINET\tFRAG"
  echo -e "\t\t${SS_PROC_ALL}\t${SS_SOCK_SYS_ALL}\t${SS_SOCK_KERN_ALL}\t${SS_SOCK_TCP_ALL}\t${SS_SOCK_TT_RAW}\t${SS_SOCK_TT_TCP}\t${SS_SOCK_TT_UDP}\t${SS_SOCK_TT_INET}\t${SS_SOCK_TT_FRAG}"
  echo -e " "
  


  if [ "${FLAG_SAVE}x" != "x" ]; then

    #echo "${ARRAY}" |tee -a ${FILE_STDOUT}
    echo "${ARRAY}" >> ${FILE_STDOUT}
  
    if [ -f ${FILE_STDOUT} ]; then
      echo "#> All data have been saved at CSV file in [${FILE_STDOUT} ($(ls -ls data_tcp.csv |awk '{print$1}'))]"
    #else
    #  echo "#% ERROR - Creating CSV file in [${FILE_STDOUT}]"
    fi

  cat <<EOF > ${LAST_DATA_CONFIG_FILE}

# ${LAST_DATA_CONFIG_FILE} - Config file for data collected from netstat and ss

LAST_GET_DATE="${DATE_NOW}"
FIELDS="DATE_NOW;established;syn-sent;syn-recv;fin-wait-1;fin-wait-2;time-wait;closed;close-wait;last-ack;listen;closing"
LAST_GET_DATA="${ARRAY}"

EOF

    if [ -f ${LAST_DATA_CONFIG_FILE} ]; then
      echo "#> Latest config file was created at [${LAST_DATA_CONFIG_FILE}]"
    #else
    #  echo "#% ERROR - Latest config file was created in [${FILE_STDOUT}]"
    fi
  fi
  
  echo -e " "
  echo -e "###################################"
  echo -e "NOTE: is better using to automatically update, such as: $ watch -n1 $0 "
  echo -e " -> Created by Marco Túlio. Enjoy it :) "
  echo -e " "
}


#######################################
# Clean up temp files
# Globals:
#    None
# Arguments:
#    None
# Returns:
#   None
#######################################
cleanup() {
  rm -f ${FILE_TMP} >/dev/null 2>&1
}


script_finish() {
  cleanup;
  exit 99;
}


#######################################
# Main script 
# Globals:
#    FILE_TMP
#    FILE_STDOUT
# Arguments:
#    None
# Returns:
#    FILE_STDOUT
#######################################
main() {

  case $1 in 
    "-s"|"--save") FLAG_SAVE=1;
  esac;

  GET_CONNECTIONS;
  
  cleanup;
}
main $@;

exit 0;
