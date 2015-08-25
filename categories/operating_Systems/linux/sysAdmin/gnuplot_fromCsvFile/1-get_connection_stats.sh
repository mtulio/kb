#!/bin/bash

#
# get_connection_stats.sh - Generate CSV file from TCP connections
#       see script gplot_generateFromCsv.pg  for generate graphics from CSV files.
#
# See TCP states at:
#	- TCP State machine: http://www.tcpipguide.com/free/t_TCPOperationalOverviewandtheTCPFiniteStateMachineF-2.htm
#
# Author: Marco Tulio R Braga
# Created at 25, Aug 2015
# Changed at 25, Aug 2015
#


DATE_NOW="$(date +%Y-%m-%d_%H:%M:%S)"
LANG=en netstat -nat |grep -ve ^[A,P] |awk '{print$6}'|sort |uniq -c |awk '{print$2";"$1}' |sort |tr '[:upper:]' '[:lower:]' > /tmp/TMP_INPUT.tmp

# Not at all will be used.
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

done < /tmp/TMP_INPUT.tmp

#DATE_NOW;established;syn-sent;syn-recv;fin-wait-1;fin-wait-2;time-wait;closed;close-wait;last-ack;listen;closing
echo "$DATE_NOW;${FIELD01};${FIELD02};${FIELD03};${FIELD04};${FIELD05};${FIELD06};${FIELD07};${FIELD08};${FIELD09};${FIELD10};${FIELD11};" >> data.csv


exit 0;
