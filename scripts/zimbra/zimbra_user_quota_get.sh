#!/bin/bash
#
# zimbra_user_quota_get - Get quota users - All or each domain, to CSV file.
# 	Output file(CSV) could be used to load in an DB
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: 30 Jun 2015
# modified: 05 Aug 2015
#
#######################################

#######################################
# Show usage script
# Globals:
#   None
# Arguments:
#   None
# Returns:
#   Help message
#######################################
usage() {
  [ "$*" ] && echo " You entered        : $0 $*"
  echo " Usage          : $0 [all | [(domain|user) (dominio|usuario)] ]"
  exit 2;
} 2>/dev/null

if [ $# -lt 2 ]
then
  if [ "$1" != "all" ]
  then 
    usage; 
  fi
fi

#######################################
# Globals & Parameter validation


# IMPORTANT: See configuration file: config_scripts.cfg
readonly SCRIPT_CONFIG="config_scripts.cfg"

readonly SCRIPT_LOGGER="config_logger"
readonly DIR_CUR_SCRIPT=$(echo $0 |awk -F"/$(basename $0)" '{print$1}'); 	#Config script might to be in the same dir that current script

source ${DIR_CUR_SCRIPT}/${SCRIPT_CONFIG} || (echo "#% ERROR1 - Config scripts not found."; exit 2)

# Import external log functions
SCRIPT_FC_LOG=${SCRIPT_FC_LOG:-${DIR_CUR_SCRIPT}/${SCRIPT_LOGGER}}

if [ ! -x $SCRIPT_FC_LOG ] ; then echo "#% ERROR - Logger script was not found [${SCRIPT_CONFIG}]."; exit 3; fi
source ${SCRIPT_FC_LOG} || (echo "#% ERROR - unable to start logger functions. 'config_logger' file exist?."; exit 5);

logger_init $0;
test "${FILE_LOG}"x == "x" && (echo "#% ERROR - unable to determine logger file [${FILE_LOG}]. Check 'logger_setLogFile()' in  'config_logger'."; exit 5);

# Check hostname is an MAILBOX
if [ "$HOSTNAME" != "${LDAP_USR_QT_MBOX1}" ] && [ "$HOSTNAME" != "${LDAP_USR_QT_MBOX2}" ]; then
  echo "#% Script allowed to run only in Zimbra Mailbox servers [${LDAP_USR_QT_SRVSV}]."
  exit 4;
fi 

# Declare Globals
readonly ARG1=$1
readonly ARG2=$2
readonly FILE_QUOTA="$(mktemp)"
readonly FILE_QUOTA_TMP="${FILE_QUOTA}.tmp"


#######################################
# Get users quota from servers
# Globals:
#    LDAP_USR_QT_SRVSV
#    BIN_ZCS_ZMPROV
#    DOMAIN_GLOBAL
#    FILE_QUOTA*
# Arguments:
#    None
# Returns:
#    CSV file with all users and quotas
#######################################
quota_dump_all2csv() {
  rm -f ${FILE_QUOTA}* >/dev/null 2>&1

  for MBOX_SERVER in ${LDAP_USR_QT_SRVSV}
  do
    logUpdPrefix; echo -n "${MSG_PFIX} #> Dumping all accounts from server ${MBOX_SERVER}..." |tee -a ${FILE_LOG}
    ${BIN_ZCS_ZMPROV} gqu ${MBOX_SERVER}.${DOMAIN_GLOBAL} >> ${FILE_QUOTA} 2>/dev/null
    if [ $? -eq 0 ]; 
    then logUpdPrefix; echo "[SUCCESS] ${DATE_RUNNING} [$(wc -l ${FILE_QUOTA} |cut -d' ' -f1)]" |tee -a ${FILE_LOG} ;
    else logUpdPrefix; echo "[FAIL] - #% ERROR[${FUNCNAME[0]}] running Zimbra Command: 'zmprov gqu ...'" |tee -a ${FILE_LOG} ; script_finish;
    fi
  done

  logUpdPrefix; echo "${MSG_PFIX} #> Sorting CSV file " |tee -a ${FILE_LOG}
  sort ${FILE_QUOTA} > ${FILE_QUOTA_TMP} 2>/dev/null

  #rm -f ${FILE_QUOTA_TMP}* >/dev/null 2>&1

  logUpdPrefix; echo "${MSG_PFIX} #> Creating CSV file [${FILE_QUOTA} ($(wc -l ${FILE_QUOTA_TMP} |cut -d' ' -f1))] with header: 'mail;quota_cfg;quota_usg' " |tee -a ${FILE_LOG}

  echo "mail;quota_cfg;quota_usg" > ${FILE_QUOTA} 2>/dev/null
  sed 's/ /;/g' ${FILE_QUOTA_TMP} >> ${FILE_QUOTA} 2>/dev/null

  if [ -f ${FILE_QUOTA} ]; then
    logUpdPrefix; 
    local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-$(date +%Y%m%d).csv";
    #echo "NEW_FILE=$FILE_NEW"
    mv ${FILE_QUOTA} ${FILE_NEW} 
    echo "${MSG_PFIX} #> SUCCESS. CSV file saved at ${FILE_NEW} [$(wc -l ${FILE_NEW} |cut -d ' ' -f1)]" |tee -a ${FILE_LOG}
  else
    logUpdPrefix; echo "${MSG_PFIX} #% ERROR[${FUNCNAME[0]}] - CSV file not found" |tee -a ${FILE_LOG}
  fi
}

quota_dump_all() {

  quota_dump_all2csv;
  if [ -f ${FILE_QUOTA} ]
  then
    logUpdPrefix; echo "${MSG_PFIX} #> SUCCESS! CSV file created at: ${FILE_QUOTA}" |tee -a ${FILE_LOG}
  fi
}

#######################################
# Get users quota from servers
# Globals:
#    LDAP_USR_QT_SRVSV
#    BIN_ZCS_ZMPROV
#    DOMAIN_GLOBAL
#    FILE_QUOTA*
# Arguments:
#    None
# Returns:
#    CSV file with all users and quotas
#######################################
quota_domain_dump()
{
	echo "# TODO(mtulio) : Dump quota users by domani"
}

quota_user()
{
	echo "# TODO(mtulio) : Dump quota for an specific user "
}


#######################################
# Clean up temp files
# Globals:
#    ARG2
# Arguments:
#    None
# Returns:
#   None
#######################################
cleanup() {
  rm -f ${FILE_QUOTA_TMP} >/dev/null 2>&1
}


script_finish() {
  cleanup;
  exit 99;
}
#######################################
# Main script function - options treatment
# Globals:
#    ARG1
#    ARG2
# Arguments:
#    $*
# Returns:
#   A user, or list, with its quote
#######################################
main() {
  case $ARG1 in 
    "domain") DOMAIN="${ARG2}" ; fc_quota_domain ;;
    "user") USERNAME="${ARG2}" ; fc_quota_user ;;
    "all") quota_dump_all ;;
    *) echo "#% Unknown optionOpcao desconhecida [$ARG1]" |tee -a ${FILE_LOG} ; usage ;;
  esac

  cleanup;
}
main $@;


exit 0;
