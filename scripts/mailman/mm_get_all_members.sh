#!/bin/bash
#!/bin/bash
#
# mm_get_all_members.sh - Get all Mailman members (from all lists) 
#	and create a CSV file with members with theirs lists.
#	Schedule cicle: Daily (crontab)
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: 14 Aug 2015
# modified: 14 Aug 2015
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
  echo " Usage          : $0 --[debug|help]"
  echo " '-> --debug    : Enable debug - status of each member"
  echo " '-> --help     : Show this help"
  exit 2;
} 2>/dev/null

#######################################
# Globals & Parameter validation
# IMPORTANT: See configuration file: config_scripts.cfg
readonly SCRIPT_CONFIG="../config_scripts.cfg"
readonly SCRIPT_LOGGER="../config_logger"

#Config script might to be in the same dir that current script
readonly DIR_CUR_SCRIPT=$(echo $0 |awk -F"/$(basename $0)" '{print$1}'); 	#Config script might to be in the same dir that current script

if [ ! -x ${DIR_CUR_SCRIPT}/${SCRIPT_CONFIG} ]; then echo "#% ERROR - Config file was not found [${DIR_CUR_SCRIPT}/${SCRIPT_CONFIG}]."; exit 3; fi
source ${DIR_CUR_SCRIPT}/${SCRIPT_CONFIG} || (echo "#% ERROR - Config scripts not found."; exit 2)

# Import external log functions
SCRIPT_FC_LOG=${SCRIPT_FC_LOG:-${DIR_CUR_SCRIPT}/${SCRIPT_LOGGER}}

if [ ! -x $SCRIPT_FC_LOG ] ; then echo "#% ERROR - Logger script was not found [${SCRIPT_CONFIG}]."; exit 3; fi
source ${SCRIPT_FC_LOG} || (echo "#% ERROR - unable to start logger functions. 'config_logger' file exist?."; exit 5);

logger_init $0;
test "${FILE_LOG}"x == "x" && (echo "#% ERROR - unable to determine logger file [${FILE_LOG}]. Check 'logger_setLogFile()' in  'config_logger'."; exit 5);

# Check hostname is an LDAP Server
if [ "$HOSTNAME" != "${SERVER_MM1}" ] && [ "$HOSTNAME" != "${SERVER_MM2}" ]; then
  echo "#% Script allowed to run only in Mailman server.."
  exit 4;
fi 


## Globals and validations
readonly DATE_CHG="$(date +%Y-%m-%d)"
FILE_TMP="$(mktemp)"
FILE_CSV_TMP="${FILE_TMP}-csv"

# Mailman
#readonly PATH_MM_BKP_DIR="/var/backups/mailman/`date +%F`"
readonly PATH_MM_BKP_DIR="/var/backups/mailman/2015-08-13"
if [ ! -d ${PATH_MM_BKP_DIR} ]; then
  echo "#% ERROR - unable to find backup directory [${PATH_MM_BKP_DIR}]. This script could be run only with Mailman Backup script."; 
  exit 5;
fi

#######################################
# Get membership from lists
# Globals:
#    None
# Arguments:
#    None
# Returns:
#    CSV file with members and its lits
#######################################
mm_get_members_lists() {
  
  logUpdPrefix; echo "${MSG_PFIX} <> Starting function to search members and their lists. LOG=[${FILE_LOG}]" |tee -a ${FILE_LOG}

  # Get all members
  cat ${PATH_MM_BKP_DIR}/*.members |sort -u > ${FILE_TMP} 2>/dev/null
  logUpdPrefix; echo "${MSG_PFIX} #> It was found [$(cat ${FILE_TMP} |wc -l)] e-mails in all lists." |tee -a ${FILE_LOG}

  COUNT=0
  echo "DATE_CHG;MAIL;MEMBER_OF_LISTS" > ${FILE_CSV_TMP}

  for MEMBER_NAME in $(cat ${FILE_TMP})
  do

    logUpdPrefix; echo -n "${MSG_PFIX} #> Checking lists that email [${MEMBER_NAME}] have been ingressed..." |tee -a ${FILE_LOG}

    grep -rw ${MEMBER_NAME} ${PATH_MM_BKP_DIR}/*.members > ${FILE_TMP}.lists 2>/dev/null

    unset LIST_NAME_VEC
    COUNTL=0
    for LIST_FIND in $(cat ${FILE_TMP}.lists)
    do
      LIST_PATH="$(echo ${LIST_FIND} |awk -F':' '{print$1}')"
        LIST_NAME="$(basename ${LIST_PATH} |awk -F'.members' '{print$1}')"
      if [ "$COUNTL" == "0" ]; then
        LIST_NAME_VEC="${LIST_NAME}"
      else
        LIST_NAME_VEC="${LIST_NAME_VEC}:${LIST_NAME}"
      fi
      let "COUNTL++"
    done

    echo " Ingressed in [${COUNTL}] lists" |tee -a ${FILE_LOG}


    let "COUNT++"
    echo "${DATE_CHG};${MEMBER_NAME};${LIST_NAME_VEC}" >> ${FILE_CSV_TMP}

    # Testing:
    if [ $COUNT -eq 100 ];then echo "${FILE_CSV_TMP}"; break; fi
  done

  logUpdPrefix; 
  echo "${MSG_PFIX} #> Found [${COUNT}] members and its lists." |tee -a ${FILE_LOG}
  echo "${MSG_PFIX} #> Saving temp CSV file  ${FILE_CSV_TMP} [$(wc -l ${FILE_CSV_TMP} |cut -d ' ' -f1)]." |tee -a ${FILE_LOG}

  if [ -f ${FILE_CSV_TMP} ]; then
    #local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-$(date +%Y-%m-%d).csv";
    local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-latest.csv";

    mv ${FILE_CSV_TMP} ${FILE_NEW} >/dev/null 2>/dev/null
    logUpdPrefix;
    if [ -f ${FILE_NEW} ];then echo "${MSG_PFIX} #> SUCCESS. CSV file saved at ${FILE_NEW} [$(wc -l ${FILE_NEW} |cut -d ' ' -f1)]" |tee -a ${FILE_LOG}
    else echo "${MSG_PFIX} #% ERROR - Moving CSV file ${FILE_CSV_TMP} to ${FILE_NEW} " |tee -a ${FILE_LOG} ; fi
  else
    logUpdPrefix; echo "${MSG_PFIX} #% ERROR[${FUNCNAME[0]}] - CSV file not found" |tee -a ${FILE_LOG}
  fi
}


#######################################
# Clean up temporary files
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
# Main script function - options treatment
# Globals:
#   None
# Arguments:
#   None
# Returns:
#   None
#######################################
main() {

  case $1 in
    "--debug") EN_DEBUG=1;;
  esac

  mm_get_members_lists;

  cleanup;
}
main $@;

