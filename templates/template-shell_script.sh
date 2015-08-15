#!/bin/bash
#
# script_template.sh - TEMPLATE SCRIPT - MIGHT TO BE CHANGED
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: XX Month 2015
# modified: XX Month 2015
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
  echo " Usage          : $0 [all | daily] ]"
  echo " '-> all   : Create an CSV with all data from log  [run at once]"
  echo " '-> daily : Create an unique CSV from today's log [run at same day of ]"

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
readonly DIR_CUR_SCRIPT=$(dirname $0); 	#Config script might to be in the same dir that current script

source ${DIR_CUR_SCRIPT}/${SCRIPT_CONFIG} || (echo "#% ERROR1 - Config scripts not found."; exit 2)

# Import external log functions
SCRIPT_FC_LOG=${SCRIPT_FC_LOG:-${DIR_CUR_SCRIPT}/${SCRIPT_LOGGER}}

if [ ! -x $SCRIPT_FC_LOG ] ; then echo "#% ERROR - Logger script was not found [${SCRIPT_CONFIG}]."; exit 3; fi
source ${SCRIPT_FC_LOG} || (echo "#% ERROR - unable to start logger functions. 'config_logger' file exist?."; exit 5);

logger_init $0;
test "${FILE_LOG}"x == "x" && (echo "#% ERROR - unable to determine logger file [${FILE_LOG}]. Check 'logger_setLogFile()' in  'config_logger'."; exit 5);

# Check hostname is an LDAP Server
if [ "$HOSTNAME" != "${ZIMBRA_SERVER_LDAP1}" ] && [ "$HOSTNAME" != "${ZIMBRA_SERVER_LDAP2}" ]; then
  echo "#% Script allowed to run only in Zimbra LDAP servers [${LDAP_USR_QT_SRVSV}]."
  exit 4;
fi 

# Declare Globals
readonly FILE_TMP="$(mktemp)"

#######################################
# CHANGE IT: Function to get X, Y and Z
# Globals:
#    LDAP_USR_QT_SRVSV
#    BIN_ZCS_ZMPROV
#    DOMAIN_GLOBAL
# Arguments:
#    None
# Returns:
#    CSV file with all X and Y
#######################################
your_function_name_DO() {
  rm -f ${FILE_TMP}* >/dev/null 2>&1
  local DATE_TODAY="$(date +%Y%m%d)"

  local FILE_USRS_ACT="${FILE_TMP}-active"
  local FILE_USRS_DIS="${FILE_TMP}-closed"
  local FILE_USRS_CSVTMP="${FILE_TMP}-csv.tmp"
  local FILE_USRS_CSV="${FILE_TMP}-csv"

  logUpdPrefix; echo -n "${MSG_PFIX} #> Getting active users..." |tee -a ${FILE_LOG}
  ${BIN_ZCS_ZMPROV} sa "(&(!(zimbraAccountStatus=*closed*))(&(flag=vpn)))" >> ${FILE_USRS_ACT} 2>/dev/null
  if [ $? -eq 0 ]; 
    then 
    logUpdPrefix; echo "[SUCCESS] ${DATE_RUNNING} [$(wc -l ${FILE_USRS_ACT} |cut -d' ' -f1)]" |tee -a ${FILE_LOG} ;
  else 
    logUpdPrefix; echo "[FAIL] - #% ERROR[${FUNCNAME[0]}] running Zimbra Command: 'zmprov sa (&(!(zimbraAccountStatus=*closed*))(&(flag=vpn))) ...'" |tee -a ${FILE_LOG} ; 
    script_finish;
  fi
  
  logUpdPrefix; echo "${MSG_PFIX} #> Creating CSV file such as: 'DATE;mail;status' " |tee -a ${FILE_LOG}
  while read LINE; do echo "${DATE_TODAY};${LINE};active" >> ${FILE_USRS_CSVTMP}; done < ${FILE_USRS_ACT}
  logUpdPrefix; echo "${MSG_PFIX} #> CSV on active accounts was created at [$(wc -l ${FILE_USRS_CSVTMP} |cut -d' ' -f1)] " |tee -a ${FILE_LOG}

  logUpdPrefix; echo -n "${MSG_PFIX} #> Getting non-active users..." |tee -a ${FILE_LOG}
  ${BIN_ZCS_ZMPROV} sa "(&(&(zimbraAccountStatus=closed))(&(flag=value)))" >> ${FILE_USRS_DIS} 2>/dev/null
  if [ $? -eq 0 ]; 
    then 
    logUpdPrefix; echo "[SUCCESS] ${DATE_RUNNING} [$(wc -l ${FILE_USRS_DIS} |cut -d' ' -f1)]" |tee -a ${FILE_LOG} ;
  else 
    logUpdPrefix; echo "[FAIL] - #% ERROR[${FUNCNAME[0]}] running Zimbra Command: 'zmprov sa (&(&(zimbraAccountStatus=closed))(&(flag=value))) ...'" |tee -a ${FILE_LOG} ; 
    script_finish;
  fi
  
  logUpdPrefix; echo "${MSG_PFIX} #> Creating CSV file such as: 'DATE;mail;status' " |tee -a ${FILE_LOG}
  while read LINE; do echo "${DATE_TODAY};${LINE};closed" >> ${FILE_USRS_CSVTMP}; done < ${FILE_USRS_DIS}
  logUpdPrefix; echo "${MSG_PFIX} #> CSV on non-active accounts was created [$(wc -l ${FILE_USRS_CSVTMP} |cut -d' ' -f1)] " |tee -a ${FILE_LOG}


  logUpdPrefix; echo "${MSG_PFIX} #> Sorting CSV file " |tee -a ${FILE_LOG}
  echo "DATE;mail;status" > ${FILE_USRS_CSV}
  sort ${FILE_USRS_CSVTMP} >> ${FILE_USRS_CSV} 2>/dev/null

  
  if [ -f ${FILE_USRS_CSV} ]; then
    local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-$(date +%Y%m%d).csv";
    
    mv ${FILE_TMP}-csv ${FILE_NEW} 
    logUpdPrefix; echo "${MSG_PFIX} #> SUCCESS. CSV file saved at ${FILE_NEW} [$(wc -l ${FILE_NEW} |cut -d ' ' -f1)]" |tee -a ${FILE_LOG}
  else
    logUpdPrefix; echo "${MSG_PFIX} #% ERROR[${FUNCNAME[0]}] - CSV file not found" |tee -a ${FILE_LOG}
  fi
}

your_function_name_MENU() {

  your_function_name_DO;
  if [ -f ${FILE_X} ]
  then
    logUpdPrefix; echo "${MSG_PFIX} #> SUCCESS! CSV file created at: ${FILE_X}" |tee -a ${FILE_LOG}
  fi
}

#######################################
# CHANGE IT: Description of function
# Globals:
#    None
# Arguments:
#    None
# Returns:
#    None
#######################################
your_function_name2()
{
  echo "TODO(mtulio) : Descript here what to do (pending) in this function"
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
  rm -f ${FILE_X} >/dev/null 2>&1
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
#   What to return
#######################################
main() {
  case $ARG1 in 
    "OPT1") your_function_name_MENU $@ ;;
    *) echo "#% Unknown option [$ARG1]" |tee -a ${FILE_LOG} ; usage ;;
  esac

  cleanup;
}
main $@;


exit 0;
