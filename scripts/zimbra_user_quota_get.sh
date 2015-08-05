#!/bin/bash
#
# zimbra_user_quota_get - Get quota users - All or eacho domain 
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
# Reading config file

# IMPORTANT: See configuration file: config_scripts.cfg
source config_scripts.cfg || (echo "#% ERROR1 - Config scripts not found."; exit 2)
SCRIPT_CONFIG=${SCRIPT_CONFIG:=x}; 
#echo "${SCRIPT_CONFIG}"
#[ "${SCRIPT_CONFIG}" == "x" ] || (echo "#% ERROR - Config scripts not found."; exit 2);

# Import external log functions
SCRIPT_FC_LOG=${SCRIPT_FC_LOG:-config_logger}
if [ ! -x $SCRIPT_FC_LOG ] ; then echo "#% ERROR - Logger script was not found [${SCRIPT_CONFIG}]."; exit 3; fi
#echo "SCRIPT_FC_LOG=[${SCRIPT_FC_LOG}]"
source ${SCRIPT_FC_LOG} || (echo "#% ERROR - unable to start logger functions. 'config_logger' file exist?."; exit 5);
logger_init $0;

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

  logUpdPrefix; echo "${MSG_PFIX} #> Creating CSV file [${FILE_QUOTA} ($(wc -l ${FILE_QUOTA_TMP} |cut -d' ' -f1))] with header: 'mail;quote;usage' " |tee -a ${FILE_LOG}

  echo "mail;quote;usage" > ${FILE_QUOTA} 2>/dev/null
  sed 's/ /;/g' ${FILE_QUOTA_TMP} >> ${FILE_QUOTA} 2>/dev/null

  if [ -f ${FILE_QUOTA} ]; then
    logUpdPrefix; 
    local FILE_NEW="${PATH_CSV:=$PWD}/$(basename $0 |awk -F'.sh' '{print$1}')-${LOG_DATE_NOW}.csv";
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
# TODO(mtulio) : everything bellow :)

# Get quota from domain
quota_domain_dump()
{
	# Check domain
	if [ -z "$(echo $DOMAIN |grep incra.gov.br)" ]
	then
		fc_update_log_prefix
		echo "$PREFIX_LOG #> Invalid domain [$DOMAIN]"
		echo "$PREFIX_LOG #> Have you type [SUBDOMAIN]incra.gov.br ?"
		exit 1
	fi

	fc_update_log_prefix; echo "$PREFIX_LOG #> Getting users from Zimbra DB" |tee -a $FILE_LOG
	fc_dump_users_quota;

	fc_update_log_prefix; echo "$PREFIX_LOG #> Filtering per domain '$DOMAIN'" |tee -a $FILE_LOG
	
	echo "Usuario;Cota_Atual;Cota_utilizada" >  $FILE_TMP_ZCSQUOTA
	cat ${FILE_QUOTA} |grep "${DOMAIN}" >> $FILE_TMP_ZCSQUOTA
	
	mv $FILE_TMP_ZCSQUOTA $FILE_QUOTA >/dev/null 2>&1

	fc_update_log_prefix; echo "$PREFIX_LOG #> Executado com sucesso. Arquivo CSV salvo em: $FILE_QUOTA [$(wc -l $FILE_QUOTA |cut -d' ' -f1)]" |tee -a $FILE_LOG
}

quota_user()
{
	# Check user name and domain
	if [ -z ${USERNAME} ] || [ -z "$(echo $USERNAME |awk -F'@' '{print$2}' |grep incra.gov.br)" ]
	then
		fc_update_log_prefix
		echo "$PREFIX_LOG #> Username or domain invalid. USERNAME['$USERNAME']"
		echo "$PREFIX_LOG #> Have you type username@[sr.]incra.gov.br ?"
		exit 1
	fi

	# Trying to find account in server sbsb1003
	unset ACCOUNT_LINE
	ACCOUNT_LINE="`/opt/zimbra/bin/zmprov gqu sbsb1003.incra.gov.br |grep ^${USERNAME}`"
	if [ -z "${ACCOUNT_LINE}" ]
	then
		#fc_update_log_prefix
		echo "${PREFIX_LOG}#> Account not found in server 'sbsb1003', trying server 'sbsb1004'" |tee -a $FILE_LOG
		# Trying in another server
		unset ACCOUNT_LINE
		ACCOUNT_LINE="`/opt/zimbra/bin/zmprov gqu sbsb1004.incra.gov.br |grep ^${USERNAME}`"
		if [ -z "${ACCOUNT_LINE}" ]
		then
			fc_update_log_prefix
			echo "${PREFIX_LOG}#> Account not found in servers 'sbsb1003' nor 'sbsb1004'" |tee -a $FILE_LOG
			echo "${PREFIX_LOG}#> No such account '${USERNAME}' on Zimbra."
			exit 1
		fi
	fi
	
	> $FILE_QUOTA

	echo "$ACCOUNT_LINE" > $FILE_TMP_ZCSQUOTA

	echo "Usuario;Cota_Atual;Cota_utilizada" >  $FILE_QUOTA
	COUNT=0
	while read LINE
	do
		USERNAME="`echo $LINE |awk '{print$1}'`"
		QUOTA="`echo $LINE |awk '{print$2}'`"
		USAGE="`echo $LINE |awk '{print$3}'`"

		echo "$USERNAME;$QUOTA;$USAGE" >> $FILE_QUOTA

		let "COUNT++"
		echo -ne "\r#> Criando arquivo CSV [$FILE_QUOTA] com as contas do domínio $DOMAIN...$COUNT" |tee -a $FILE_LOG
	done  < $FILE_TMP_ZCSQUOTA
	
	# stdout
	cat $FILE_QUOTA
	
	fc_update_log_prefix; echo "$PREFIX_LOG #> Executado com sucesso. Arquivo CSV salvo em: $FILE_QUOTA" |tee -a $FILE_LOG

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
