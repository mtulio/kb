#!/bin/bash

#
# vm_manage.sh - Script to control vagrant. (store vagrant boxes in different directory)
# author: Marco Túlio R Braga
#

usage() {
  echo "#% ERROR -  Usage: $0 [start|up|stop|suspend|export|list|status|global-status] VM_NAME"
  exit 99;
}


# Globals

VAGRANT_CMD="$(which vagrant)"
VAGRANT_HOME="/home/workDir/MaquinasVirtuais/vagrant/vagrant.d"		# Change Me
VAGRANT_VAGRANTFILE="Vagrantfile"

if [ ! -x ${VAGRANT_CMD} ]; then
  echo "#% ERROR - Vagrant binary not found. Is vagrant installed?"
  exit 3;
fi

if [ ! -d ${VAGRANT_HOME} ]; then
  echo "#% ERROR - Vagrant Home Directory is not valid. Please, check VAGRANT_HOME environment."
  echo "	Current VAGRANT_HOME is set to ${VAGRANT_HOME}. Change it."
  exit 2;
fi

# Local envs

readonly VM_CMD="$1"
readonly VM_NAME="$2"

################
## Global functions
# Export Envs
EXPORT() {
  export VAGRANT_HOME="${PWD}/vagrant.d"
}

# Start a VM
START_ALL() {
  EXPORT;
  ${VAGRANT_CMD} up 
}
START() {
  EXPORT;
  if [ "${VM_NAME}x" == "x" ]; then
    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
    exit 99;
  else
    ${VAGRANT_CMD} up ${VM_NAME}
  fi
}

SUSPEND() {
  EXPORT;
  if [ "${VM_NAME}x" == "x" ]; then
    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
    exit 99;
  else
    ${VAGRANT_CMD} suspend ${VM_NAME}
  fi
}

SUSPEND_ALL() {
  ${VAGRANT_CMD} suspend 
}

# List VMS
STATUS() {
  ${VAGRANT_CMD} status
}
GLOBAL_STATUS() {
  ${VAGRANT_CMD} global-status
}

# Main function
main() {
  case $VM_CMD in
    "start"|"up") START $VM_NAME;;
    "start-all") START_ALL;;
    "stop"|"suspend") SUSṔEND $VM_NAME;;
    "stop-all"|"suspend-all") SUSṔEND_ALL;;
    "export") EXPORT;;
    "global-status") GLOBAL_STATUS;;
    "status"|"list") STATUS;;
    "ssh"|"conect") SSH $VM_NAME;;
    *) usage ;;
  esac
}
main $@;
