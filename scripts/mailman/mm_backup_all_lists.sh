#!/bin/bash
#!/bin/bash
#
# mm_backup_all_lists.sh - Mailman Backup Script
#	Schedule cicle: Daily (crontab)
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: 24 Jun 2014
# modified: 12 Aug 2015
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
#readonly DIR_CUR_SCRIPT=$(echo $0 |awk -F"/$(basename $0)" '{print$1}'); 	#Config script might to be in the same dir that current script
readonly DIR_CUR_SCRIPT=$(dirname $0); 	#Config script might to be in the same dir that current script

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
readonly DATE_BKP="$(date +%Y-%m-%d)"
#readonly PATH_FILE_CSV="${}"
FILE_TMP="$(mktemp)"
FILE_CSV_TMP="${FILE_TMP}-csv"

# Mailman
PATH_MM_BKP_DIR="/var/backups/mailman/`date +%F`"
[ -d ${PATH_MM_BKP_DIR} ] || mkdir -p ${PATH_MM_BKP_DIR} 

# Mailman Paths
BIN_MM_CFG="`which config_list`"
BIN_MM_LISTS="`which list_lists`"
BIN_MM_LIST_ADM="`which list_admins`"
BIN_MM_LIST_MEM="`which list_members`"

if [ ! -x ${BIN_MM_CFG} ] ||
	[ ! -x ${BIN_MM_LISTS} ] ||
	[ ! -x ${BIN_MM_LIST_ADM} ] ||
	[ ! -x ${BIN_MM_LIST_MEM} ]
then
  echo "#% ERROR - Mailman binary(ies) not found. Exiting."
  exit 4;
fi

#######################################
# Backing up lists
# Globals:
#    None
# Arguments:
#    None
# Returns:
#    CSV file
#######################################
mm_backup_all() {
  
  logUpdPrefix; echo "${MSG_PFIX} <> Starting backup  LOG=[${FILE_LOG}]" |tee -a ${FILE_LOG}
  #logUpdPrefix; echo "${MSG_PFIX} <> Starting backup  LOG=[${FILE_LOG}]" 

  # Get all lists
  ${BIN_MM_LISTS} -b > ${FILE_TMP} 2>/dev/null
  if [ "${EN_DEBUG}" != "1" ]; then
    echo "${MSG_PFIX} #> It was found [$(cat ${FILE_TMP} |wc -l)] list to be backed up. For details see CSV temp file [${FILE_CSV_TMP}]..." |tee -a ${FILE_LOG}
  else 
    logUpdPrefix; echo "${MSG_PFIX} #> It was found [$(cat ${FILE_TMP} |wc -l)] list to be backed up." |tee -a ${FILE_LOG}
  fi  

  COUNT=0
  echo "DATE_BKP;LISTNAME;CFG_LINES;ADMIN_LINES;MEMBERS_LINES" > ${FILE_CSV_TMP}

  for LISTNAME in $(cat ${FILE_TMP})
  do

    if [ "${EN_DEBUG}" == "1" ]; then
      logUpdPrefix; echo -n "${MSG_PFIX} #> Backing up list [${LISTNAME}] - " |tee -a ${FILE_LOG}
    fi

    $BIN_MM_CFG -o ${PATH_MM_BKP_DIR}/${LISTNAME}.cfg.tmp ${LISTNAME} |tee -a ${FILE_LOG}

    grep -v ^# ${PATH_MM_BKP_DIR}/${LISTNAME}.cfg.tmp |grep -v ^$ > ${PATH_MM_BKP_DIR}/${LISTNAME}.cfg |tee -a ${FILE_LOG}
    
    rm -f ${PATH_MM_BKP_DIR}/${LISTNAME}.cfg.tmp |tee -a ${FILE_LOG}

    COUNT_CFG="$(wc -l ${PATH_MM_BKP_DIR}/${LISTNAME}.cfg|awk '{print$1}')"

    ${BIN_MM_LIST_ADM} ${LISTNAME} > ${PATH_MM_BKP_DIR}/${LISTNAME}.admins |tee -a ${FILE_LOG}
    COUNT_ADM="$(wc -l ${PATH_MM_BKP_DIR}/${LISTNAME}.admins |awk '{print$1}')"

    ${BIN_MM_LIST_MEM} ${LISTNAME} > ${PATH_MM_BKP_DIR}/${LISTNAME}.members |tee -a ${FILE_LOG}
    COUNT_MEM="$(wc -l ${PATH_MM_BKP_DIR}/${LISTNAME}.members |awk '{print$1}')"


    if [ "${EN_DEBUG}" == "1" ]; then
      echo -n " config[${COUNT_CFG}] " 
      echo -n " admins[${COUNT_ADM}] " |tee -a ${FILE_LOG}
      echo " members[${COUNT_MEM}] " |tee -a ${FILE_LOG}
    fi

    let "COUNT++"

    echo "${DATE_BKP};${LISTNAME};${COUNT_CFG};${COUNT_ADM};${COUNT_MEM}" >> ${FILE_CSV_TMP}

    # Testing limit of 100: 
    #if [ $COUNT -eq 100 ];then echo "${FILE_TMP}-csv"; break; fi
  done

  logUpdPrefix; 
  echo "${MSG_PFIX} #> It was backed up [${COUNT}] lists." |tee -a ${FILE_LOG}
  echo "${MSG_PFIX} #> Packing backup dir ${PATH_MM_BKP_DIR} to file ${PATH_MM_BKP_DIR}.tgz" |tee -a ${FILE_LOG}
  tar cfz ${PATH_MM_BKP_DIR}.tgz ${PATH_MM_BKP_DIR}/  >/dev/null 2>&1  |tee -a ${FILE_LOG}

  logUpdPrefix; 
  if [ -f ${PATH_MM_BKP_DIR}.tgz ]
  then
    # Check if backup is not empty
    tar tf ${PATH_MM_BKP_DIR}.tgz |grep "members" >/dev/null 2>&1
    if [ $? -eq 0 ]
    then
      echo "${MSG_PFIX} #> Backup success - File saved in: ${PATH_MM_BKP_DIR}.tgz" |tee -a ${FILE_LOG}
      
      #logUpdPrefix; echo "${MSG_PFIX} #> Calling external script to get Memberships from each list [$(dirname $0)/mm_get_all_members.sh]" |tee -a ${FILE_LOG}
      #$(dirname $0)/mm_get_all_members.sh 2>/dev/null
      #logUpdPrefix; echo "${MSG_PFIX} #> Script ran with success." |tee -a ${FILE_LOG}
      
      echo "${MSG_PFIX} #> Removing Backup directory." |tee -a ${FILE_LOG}
       rm -rf ${PATH_MM_BKP_DIR}/ >/dev/null 2>&1 |tee -a ${FILE_LOG}
      if [ -d ${PATH_MM_BKP_DIR} ];
      then 
        echo "${MSG_PFIX} #% ERROR - deleting backup directory ${PATH_MM_BKP_DIR}" |tee -a ${FILE_LOG} 
      fi
    else
      echo "${MSG_PFIX} #% ERROR - Backup file [${PATH_MM_BKP_DIR}.tgz] is empty " |tee -a ${FILE_LOG}
    fi
  else
    echo "${MSG_PFIX} #% ERROR - Backup file [${PATH_MM_BKP_DIR}.tgz] is not found. Directory will not be deleted." |tee -a ${FILE_LOG}
  fi


  logUpdPrefix; echo "${MSG_PFIX} #> Saving temp CSV file  ${FILE_CSV_TMP} [$(wc -l ${FILE_CSV_TMP} |cut -d ' ' -f1)]." |tee -a ${FILE_LOG}
  if [ -f ${FILE_CSV_TMP} ]; then
    local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-$(date +%Y-%m-%d).csv";

    mv ${FILE_CSV_TMP} ${FILE_NEW} >/dev/null 2>/dev/null
    logUpdPrefix;
    if [ -f ${FILE_NEW} ];then echo "${MSG_PFIX} #> SUCCESS. CSV file saved at ${FILE_NEW} [$(wc -l ${FILE_NEW} |cut -d ' ' -f1)]" |tee -a ${FILE_LOG}
    else echo "${MSG_PFIX} #% ERROR - Moving CSV file ${FILE_CSV_TMP} to ${FILE_NEW} " |tee -a ${FILE_LOG} ; fi
  else
    logUpdPrefix; echo "${MSG_PFIX} #% ERROR[${FUNCNAME[0]}] - CSV file not found" |tee -a ${FILE_LOG}
  fi

  logUpdPrefix; echo "${MSG_PFIX} #> Backed Finish." |tee -a ${FILE_LOG}
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
    "--help") usage;;
  esac

  mm_backup_all;
  cleanup;
}
main $@;

