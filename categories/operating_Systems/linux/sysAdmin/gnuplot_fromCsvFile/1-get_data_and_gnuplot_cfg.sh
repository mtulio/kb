#!/bin/bash

#
# get_connection_stats.sh - Generate CSV file from TCP connections
#       see script gplot_generateFromCsv.pg for generate graphics from CSV files.
#
# References:
# 	- See TCP states machine: http://www.tcpipguide.com/free/t_TCPOperationalOverviewandtheTCPFiniteStateMachineF-2.htm
#
# Author: Marco Tulio R Braga
# Created at 25, Aug 2015
# Changed at 25, Aug 2015
#

#######################################
# Globals & Parameter validation

DATE_NOW="$(date +%Y-%m-%d_%H:%M:%S)"
FILE_TMP="$(mktemp)"
FILE_STDOUT="data_tcp.csv"
FILE_GNUPLOT_SCRIPT="gplot_generateFromCsv.pg"
FILE_GNUPLOT_STDOUT_IMAGE="data_tcp.png"
FILE_SCRIPT_RUN_GNUPLOT="2-gplot_run.sh"

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
  echo "$DATE_NOW;${COUNT};${FIELD01};${FIELD02};${FIELD03};${FIELD04};${FIELD05};${FIELD06};${FIELD07};${FIELD08};${FIELD09};${FIELD10};${FIELD11};" >> ${FILE_STDOUT}
  
  if [ -f ${FILE_STDOUT} ]; then
    echo "#> CSV file was created with TCP Connections in [${FILE_STDOUT}]"
  else
    echo "#% ERROR - Creating CSV file in [${FILE_STDOUT}]"
  fi

}


#######################################
# Create a GNUplot script
# Globals:
#    FILE_STDOUT
#    FILE_GNUPLOT_SCRIPT
# Arguments:
#    None
# Returns:
#    FILE_GNUPLOT_SCRIPT
#######################################
CREATE_GNUPLOT_SCRIPT() {
  # Generating GnuPlot script
  cat <<EOF > ${FILE_GNUPLOT_SCRIPT}
#!/usr/bin/gnuplot

# WARN: do not change this script, was generated automatically by $0

#
# gplot_generateFromCsv.pg - Generate gnuplot graph from a CSV (TCP connections),
#       see $0 to generate CSV file.
#
# Author: Marco Tulio R Braga
# Created at 25, Aug 2015
# Changed at $(LANG=us date -u)
#


reset
#set terminal png
set terminal png truecolor
set output "${FILE_GNUPLOT_STDOUT_IMAGE}"
set datafile separator ";"

set autoscale

set xdata time
set timefmt "%Y-%m-%d_%H:%M:%S"
set format x "%H:%M"
set xlabel "time"

set ylabel "total"
set yrange [0:500]

set title "TCP Connections"
set key reverse Left outside
set grid

set style data linespoints
#set style data linespoints
#set style data lines
#set style data steps

plot "${FILE_STDOUT}" using 1:1 with lines title "total", \
"" using 1:2 with lines title "established", \
"" using 1:3 with lines title "syn-sent", \
"" using 1:4 with lines title "syn-recv", \
"" using 1:5 with lines title "fin-wait-1", \
"" using 1:6 with lines title "fin-wait-2", \
"" using 1:7 with lines title "time-wait", \
"" using 1:8 title "closed", \
"" using 1:9 title "close-wait", \
"" using 1:10 title "last-ack", \
"" using 1:11 title "listen", \
"" using 1:12 title "closing"

EOF

  if [ -f ${FILE_GNUPLOT_SCRIPT} ]; then
    chmod u+x ${FILE_GNUPLOT_SCRIPT}
    echo "#> GNUplot script in [${FILE_GNUPLOT_SCRIPT}]"
  else
    echo "#% ERROR - Creating GNUplot script in [${FILE_GNUPLOT_SCRIPT}]"
  fi
}

CREATE_SCRIPT_RUN_GNUPLOT() {

  cat <<EOF > ${FILE_SCRIPT_RUN_GNUPLOT} 
#!/bin/bash

# WARN: do not change this script, was generated automatically by $0

# 2-gplot_run.sh - Run gnuplot reading data from CSV [${FILE_STDOUT}]

# Globals
GNUPLOT_PATH="$(which gnuplot)"
if [ ! -x ${GNUPLOT_PATH} ]; then
  echo "#% ERROR - GNUPlot not found in your system, is it installed?"
  exit 1;
fi

# Clean all output beforin run
rm -f ${FILE_GNUPLOT_STDOUT_IMAGE}

if [ ! -f ${FILE_STDOUT} ]; then
  echo "#% ERRO - Data file [${FILE_STDOUT}] not found. Already you ran script '${0}' to generete it?"
  exit 1;
fi

if [ ! -f ${FILE_GNUPLOT_SCRIPT} ];
then
  echo "# Gnuplot configuration [${FILE_GNUPLOT_SCRIPT}] not found."
  exit 1;
fi

# Running gnuplot
cat ${FILE_GNUPLOT_SCRIPT} |gnuplot 2>/dev/null
if [ -f ${FILE_GNUPLOT_STDOUT_IMAGE} ]; then
  echo "# Grafic generated with success. See [${FILE_GNUPLOT_STDOUT_IMAGE}]"
else
    echo "#% ERROR generating graphics - file [${FILE_GNUPLOT_STDOUT_IMAGE}] not found."
fi

exit 0;
EOF
  
  if [ -f ${FILE_SCRIPT_RUN_GNUPLOT} ]; then
    chmod u+x ${FILE_SCRIPT_RUN_GNUPLOT}
    echo "#> GNUplot load script created at [${FILE_SCRIPT_RUN_GNUPLOT}]"
    echo "#> Now, run [${FILE_SCRIPT_RUN_GNUPLOT}] to create your graphic with GNUplot"
  else
    echo "#% ERROR - Creating GNUplot load script [${FILE_SCRIPT_RUN_GNUPLOT}]"
  fi

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
#    FILE_GNUPLOT_SCRIPT
#    SCRIPT_RUN_GNUPLOT
# Arguments:
#    None
# Returns:
#    FILE_STDOUT
#    FILE_GNUPLOT_SCRIPT
#    SCRIPT_RUN_GNUPLOT
#######################################
main() {
  GET_CONNECTIONS;
  CREATE_GNUPLOT_SCRIPT;
  CREATE_SCRIPT_RUN_GNUPLOT;
  
  cleanup;
}
main;

exit 0;
