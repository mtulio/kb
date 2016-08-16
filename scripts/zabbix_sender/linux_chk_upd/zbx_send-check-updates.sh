#!/bin/bash

# Script to check packages on Linux System
#> Debian-based will return:
### 
#> Enterprise Linux will return:
### 

### Make sure yum-plugin-security package is installed ###
### Make sure zabbix-sender package is installed ###

### Set Variables ###
ZBX_DATA=/tmp/zabbix-sender.data
ZABBIX_SERVER=$(egrep ^ServerActive /etc/zabbix/zabbix_agentd.conf | cut -d = -f 2)
ZABBIX_HOST=$HOSTNAME

#=====================
FC_OS_CHECK() {
  if [ -f /etc/redhat-release ]; then # TODO: homolog

    STR="$(cat /etc/redhat-release |awk '{print$1}')"
    STR="$(echo $STR | tr '[:upper:]' '[:lower:]')"

    if [ "$STR" == "centos" ]; then   OS_DISTRO="centos"
    elif [ "$STR" == "fedora" ]; then OS_DISTRO="fedora"
    else OS_DISTRO="redhat";
    fi
    OS_RELEASE="$(cat /etc/redhat-release |awk -F'release ' '{print$2}' |awk -F'(' '{print$1}')"
    OS_RELEASE="${OS_RELEASE:0:1}"
    OS_FAMILY="redhat"

  elif [ -f /etc/debian_version ]; then

    STR=$(cat /etc/debian_version |awk '{print$1}')
    R='^[0-9]+$'
    if [[ ${STR:0:1} =~ $R ]]; then # Debian starts with number
      OS_DISTRO="debian"
      OS_RELEASE=${STR:0:1}
    else
      OS_DISTRO="ubuntu"
      OS_RELEASE="$(lsb_release -rs)"
    fi
    OS_FAMILY="debian"

  else
    OS_DISTRO="ubuntu"
    OS_RELEASE="$(lsb_release -rs)"
    OS_FAMILY="debian"
  fi

}
#FC_OS_CHECK;


FC_DATA_COLLECT(){


  case $OS_DISTRO in
    'debian'|'ubuntu')
      case $OS_RELEASE in
        '8') OS_CODENAME=jessie;;
        '7') OS_CODENAME=wheezy;;
        '6') OS_CODENAME=squeeze;;
        *)   OS_CODENOME="$(lsb_release -cs)";;
      esac

      CRITICAL=$(apt-get -s dist-upgrade 2>/dev/null  | grep "^Inst"  |grep -i security |wc -l)
      IMPORTANT=$(apt-get -s dist-upgrade 2>/dev/null | grep "^Inst"  |grep -vi security |wc -l)
      MODERATE=0
      LOW=0
      SELINUX=0
      
    ;;
    'redhat'|'centos'|'fedora')
      if [ "$OS_RELEASE" == "6" ]; then

        TMP_MODERATE=$(yum updateinfo list --sec-severity=Moderate 2>/dev/null   | grep Moderate | wc -l)
        TMP_IMPORTANT=$(yum updateinfo list --sec-severity=Important 2>/dev/null | grep Important | wc -l)
        TMP_LOW=$(yum updateinfo list --sec-severity=Low 2>/dev/null             | grep Low | wc -l)
        TMP_CRITICAL=$(yum updateinfo list --sec-severity=Critical 2>/dev/null   | grep Critical | wc -l)

        MODERATE=$((TMP_MODERATE - 1))
        IMPORTANT=$((TMP_IMPORTANT - 1))
        LOW=$((TMP_LOW - 1))
        CRITICAL=$((TMP_CRITICAL - 1))

      elif [ "$OS_RELEASE" == "7" ] || [ "$OS_DISTRO" == "fedora" ]; then
        
        MODERATE=$(yum updateinfo list --sec-severity=Moderate 2>/dev/null   | grep Moderate | wc -l)
        IMPORTANT=$(yum updateinfo list --sec-severity=Important 2>/dev/null | grep Important | wc -l)
        LOW=$(yum updateinfo list --sec-severity=Low 2>/dev/null             | grep Low | wc -l)
        CRITICAL=$(yum updateinfo list --sec-severity=Critical 2>/dev/null   | grep Critical | wc -l)

      else 

        echo "# ${FUNCNAME[0]} > Distro [$OS_FAMILY / $OS_DISTRO - $OS_RELEASE] not available for this script. [1]";
        exit 1;

      fi

      ### Check if SELinux is active ###
      if [[ "$(getenforce)" == "Enforcing" ]]; then SELINUX=1
      else SELINUX=0; fi

    ;;
    *)
        echo "# ${FUNCNAME[0]} > Distro [$OS_FAMILY / $OS_DISTRO - $OS_RELEASE] not available for this script. [2]";
        exit 1;
    ;;
  esac

  RELEASE="${OS_DISTRO}_${OS_RELEASE}"

  # Save data to file
  ### Add data to file on format <HOST> <KEY> <VALUE>. See zabbix_sender -h ###
  echo -n > $ZBX_DATA
  echo "$HOSTNAME repo.moderate $MODERATE" >> $ZBX_DATA
  echo "$HOSTNAME repo.important $IMPORTANT" >> $ZBX_DATA
  echo "$HOSTNAME repo.low $LOW" >> $ZBX_DATA
  echo "$HOSTNAME repo.critical $CRITICAL" >> $ZBX_DATA
  echo "$HOSTNAME repo.release $RELEASE" >> $ZBX_DATA
  #echo "$HOSTNAME repo.selinux $SELINUX" >> $ZBX_DATA

}

# =====================================================================

FC_ZBX_SENDER_PKG() {
    
  ### Check if Zabbix-Sender is Installed ###
  INST_FAILED=0
  case $OS_DISTRO in
    'debian'|'ubuntu') if ! dpkg -l |grep -qw zabbix-sender >/dev/null 2>&1; then INST_FAILED=1; fi;;
    'redhat'|'centos'|'fedora') if ! rpm -qa | grep -w zabbix-sender >/dev/null 2>&1; then INST_FAILED=1; fi;;
    *) INST_FAILED=1 ;;
  esac


  if [ $INST_FAILED -eq 1 ]; then
    echo "Zabbix-Sender NOT installed"
    exit 1;
  fi

}

# Send data to zabbix
FC_ZABBIX_SEND() {

  FC_OS_CHECK;
  FC_ZBX_SENDER_PKG;
  FC_DATA_COLLECT

  $(which zabbix_sender) -z $ZABBIX_SERVER -i $ZBX_DATA &>/dev/null 2>&1
}
FC_ZABBIX_SEND

