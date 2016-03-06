#!/bin/bash

# Check information of Nameserver and domain
## Script under development.
#
# Created by: Marco Tulio R Braga
# Date: 04/02/16
#


## Arguments
# $0 NAMESERVER DOMAIN
if [ $# -ne 2 ];then
  echo "# Missing parameters. Please inform the nameserver and domain. Ex."
  echo "> $0 NAMESERVER DOMAIN"
  echo "> $0 8.8.8.8 ict-eng.net"
  echo "> $0 8.8.8.8 mtulio.eng.br"
  exit 1;
fi

NAMESERVER="$1"
DOMAIN="$2"

BUFFER="aa "
FILE_TMP="$(mktemp)"
FILE_LOG="$(basename -s .sh $0).log"

#if [ -f "$FILE_LOG" ]; then
#  echo -n "# Log file already exists, do you want to keep it? [y/N]: "
#  read RESP
#  if [ "$RESP" == "N" ]; then echo > $FILE_LOG ; fi
#fi

##>
echo "##################################################" |tee -a $FILE_LOG
echo "###> Starting test at $(date +%H:%M:%S-%Y.%m.%d)" |tee -a $FILE_LOG
echo "# NAME SERVER = [$NAMESERVER]" |tee -a $FILE_LOG
echo "# DOMAIN      = [$DOMAIN]" |tee -a $FILE_LOG
echo " " |tee -a $FILE_LOG
##########################################
# Tests available
## Query TIME
## VERSION
## Recursion
## TCP queries (+tcp)
## AXFR / IXFR
## SOA (SERIAL)
## NS
## MX
## A

###>

# Query TIME
function test_server_QTIME() {
  echo -ne "# Running server test - Query Time\t: " |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} version.bind chaos txt +stats +nocomments +noquestion  |awk -F'Query time: ' '{print$2}' |grep -v -e ^$ -e $';')"
  echo "[$RET_MSG]"
}
test_server_QTIME;


## VERSION
function test_server_VERSION() {

  echo -ne "# Running server test - Bind version\t: " |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} version.bind chaos txt +noquestion +noauthority +noadditional +nostats > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(grep "HEADER" ${FILE_TMP} |awk -F', ' '{print$2}' |awk '{print$2}')
  QUERY_ANSWER=$(grep -v -e ^$ -e ^';' ${FILE_TMP} |awk -F'TXT	' '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"
  #echo "QUERY_ANSWER=[$QUERY_ANSWER]"
  if [ "${QUERY_STATUS}" == "NOERROR" ]; then   echo "WARN [Version is $QUERY_ANSWER . Disable or mask this information]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "SRVFAIL" ]; then echo "[NOT AVAILABLE]"  |tee -a $FILE_LOG;
  else echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi

}
test_server_VERSION;

## RECURSION
function test_server_RECURSION() {

  echo -ne "# Running server test - Recursion\t: " |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} google.com A +noquestion +noauthority +noadditional +nostats > ${FILE_TMP})"
  QUERY_STATUS=$(grep "HEADER" ${FILE_TMP} |awk -F', ' '{print$2}' |awk '{print$2}')

  
  if [ "${QUERY_STATUS}" == "NOERROR" ]; then   echo "WARNING [RECURSION enabled] "  |tee -a $FILE_LOG
  elif [ "${QUERY_STATUS}" == "REFUSED" ]; then echo "OK [NOT AVAILABLE]"  |tee -a $FILE_LOG
  else echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_server_RECURSION;

## VERSION
function test_server_USETCP() {

  echo -ne "# Running server test - Is using TCP\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} version.bind chaos txt +noquestion +noauthority +noadditional +nostats +tcp > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(grep "HEADER" ${FILE_TMP} |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"

  if [ "${QUERY_STATUS}" == "NOERROR" ]; then   echo "OK [TCP queries is enabled]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "SERVFAIL" ]; then echo "FAIL [NOT AVAILABLE - Queries higher than 512B use TCP port 53]"  |tee -a $FILE_LOG;
  else echo "WARN [NO INFORMATION of TCP]"  |tee -a $FILE_LOG;
  fi

}
test_server_USETCP;


## AXFR
# A zone transfer can be requested by specifying a type of
# AXFR. When an incremental zone transfer (IXFR) is required, type is set to ixfr=N. The incremental zone transfer will contain the
# changes made to the zone since the serial number in the zone's SOA record was N.
#function test_domain_AXFR() {
#  echo aa
#
#}

function test_domain_AXFR() {

  echo -ne "# Running domain test - Zone transfer\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} AXFR +noquestion +noauthority +noadditional +nostats +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"

  if [ "$(grep 'Transfer failed' ${FILE_TMP} >/dev/null 2>&1; echo $?)" == "0" ]	; then   echo "OK [DENIED by configuration]"  |tee -a $FILE_LOG;
  elif [ "$(grep 'connection timed out' ${FILE_TMP} >/dev/null 2>&1; echo $?)" == "0" ]	; then   echo "OK [DENIED by network/firewall]"  |tee -a $FILE_LOG;
  elif [ "$(grep -v -e ^$ -e ^';' ${FILE_TMP} >/dev/null 2>&1)"x != "x" ]	; then   echo "FAIL [WARNING Domain transfer is enabled, you must fix it]"  |tee -a $FILE_LOG;
  else echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi

}
test_domain_AXFR;

## SOA
function test_domain_SOA() {

  echo -ne "# Running domain test - records SOA\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} SOA +noquestion +noauthority +noadditional +nostats +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  QUERY_ANSWER=$(cat ${FILE_TMP} |grep -v -e ^$ -e ^';' |awk -F'SOA	' '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"
  #echo "QUERY_ANSWER=[$QUERY_ANSWER]"
  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "WARN [Server isn't authoritative for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	echo "OK";
	echo -e "# Running domain test - records SOA\t: '-> P.SERVER \t[$(echo $QUERY_ANSWER |awk '{print$1}')]" |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> EMAIL \t[$(echo $QUERY_ANSWER |awk '{print$2}')]"    |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> SERIAL \t[$(echo $QUERY_ANSWER |awk '{print$3}')]"   |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> REFRESH \t[$(echo $QUERY_ANSWER |awk '{print$4}')]"  |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> FAIL REF \t[$(echo $QUERY_ANSWER |awk '{print$5}')]" |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> EXPIRE \t[$(echo $QUERY_ANSWER |awk '{print$6}')]"   |tee -a $FILE_LOG
	echo -e "# Running domain test - records SOA\t: '-> NEG TTL \t[$(echo $QUERY_ANSWER |awk '{print$7}')]"  |tee -a $FILE_LOG
  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_SOA;


## NS
function test_domain_NS() {

  echo -ne "# Running domain test - records NS\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} NS +noquestion +noauthority +noadditional +nostats +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"

  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "WARN [Server isn't authoritative for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	echo "OK"  |tee -a $FILE_LOG;
	RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} NS +tries=1 +noquestion +noauthority +nostats +nocomments |grep -v -e ^$ -e ^';' > ${FILE_TMP}; export RET_CODE=$?)"
	# Get all NS
	for VALUE in $(grep ^${DOMAIN} ${FILE_TMP} |awk '{print$5}')
	do
		echo -e "# Running domain test - records NS\t: '-> $VALUE [$(dig @${NAMESERVER} $VALUE A +short |tr '\n' ' ' )]"  |tee -a $FILE_LOG
	done

  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_NS;

## MX
function test_domain_MX() {

  echo -ne "# Running domain test - records MX\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} MX +noquestion +noauthority +noadditional +nostats +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"
  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "WARN [Server isn't authoritative for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	echo "OK";
	RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} MX +tries=1 +noquestion +noauthority +nostats +nocomments |grep -v -e ^$ -e ^';' > ${FILE_TMP}; export RET_CODE=$?)"
	# Get all MX
	for VALUE in $(grep ^${DOMAIN} ${FILE_TMP} |awk '{print$6}')
	do
		echo -e "# Running domain test - records MX\t: '-> $VALUE [$(dig @${NAMESERVER} $VALUE A +short |tr '\n' ' ')]"  |tee -a $FILE_LOG
	done
  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_MX;

## A
function test_domain_A() {

  echo -ne "# Running domain test - records A\t: "  |tee -a $FILE_LOG
  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} A +noquestion +noauthority +noadditional +nostats +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"
  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "WARN [Server isn't authoritative for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	# Get all A
	#echo "OK [$(dig @${NAMESERVER} ${DOMAIN} A +short |tr '\n' ' ')]"  |tee -a $FILE_LOG;
	echo -n "OK "  |tee -a $FILE_LOG;
	RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} A +short |tr '\n' ' ')"
	if [ "$RET_MSG"x == "x" ]; then
		echo "[No Address configured]" |tee -a $FILE_LOG
	else
		echo "[$RET_MSG]" |tee -a $FILE_LOG
	fi
  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_A;

## DSSEC KEY
function test_domain_DSEC_KEY() {

  echo -ne "# Running domain test - NSec KEY KSK\t: "  |tee -a $FILE_LOG

  if [ "$(dig +multiline ${DOMAIN} DNSKEY +short)x" == "x" ]; then
    echo "FAIL [DNSsec is not available for this domain]"  |tee -a $FILE_LOG
    return;
  fi

  RET_MSG="$(dig @${NAMESERVER} ${DOMAIN} DNSKEY +multiline +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"

  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "FAIL [DNS Sec is not configured for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	echo "OK [KSK key id is: $(dig @${NAMESERVER} ${DOMAIN} DNSKEY +multiline +tries=1 |grep KSK |awk -F'key id = ' '{print$2}')] [Server: $(grep 'SERVER:' ${FILE_TMP} |awk -F';; SERVER: ' '{print$2}')]"  |tee -a $FILE_LOG
  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_DSEC_KEY;

## DSSEC KEY_PARENT
function test_domain_DSEC_KEY_PAR() {

  echo -ne "# Running domain test - NSec PARENT KSK\t: "  |tee -a $FILE_LOG

  if [ "$(dig +multiline ${DOMAIN} DNSKEY +short)x" == "x" ]; then
    echo "FAIL [DNSsec is not available for this domain]"  |tee -a $FILE_LOG
    return;
  fi

  RET_MSG="$(dig ${DOMAIN} DS +multiline +tries=1 > ${FILE_TMP}; export RET_CODE=$?)"
  QUERY_STATUS=$(cat ${FILE_TMP} |grep "HEADER" |awk -F', ' '{print$2}' |awk '{print$2}')
  #echo "QUERY_STATUS=[$QUERY_STATUS]"

  if [ "${QUERY_STATUS}" == "REFUSED" ]; then   
	echo "FAIL [DNS Sec is not configured for this domain]"  |tee -a $FILE_LOG;
  elif [ "${QUERY_STATUS}" == "NOERROR" ]; then
	echo "OK [KSK key id is: $(dig ${DOMAIN} DS +multiline  +short |awk '{print$1}' |head -n1)] [Server: $(grep 'SERVER:' ${FILE_TMP} |awk -F';; SERVER: ' '{print$2}')]"  |tee -a $FILE_LOG
  else 
	echo "[NO INFORMATION]"  |tee -a $FILE_LOG;
  fi
}
test_domain_DSEC_KEY_PAR;

echo "###> Finish test at $(date +%H:%M:%S-%Y.%m.%d)" |tee -a $FILE_LOG
echo "##################################################" |tee -a $FILE_LOG

rm -f $FILE_TMP
