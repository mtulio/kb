#!/bin/bash

#
# vm_manage.sh - Script to control vagrant. (store vagrant boxes in different directory)
# author: Marco Túlio R Braga
#

usage() {
  echo "#% ERROR -  Usage: $0 [start|up|stop|halt|suspend|list|status|global-status|export] VM_NAME"
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
  export VAGRANT_HOME="${VAGRANT_HOME}"
}

# Start a VM
START_ALL() {
  EXPORT;
  ${VAGRANT_CMD} up --provider="virtualbox"
}
START() {
  EXPORT;
  echo "# Using VAGRANT_HOME=[${VAGRANT_HOME}]"
  if [ "${VM_NAME}x" == "x" ]; then
    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
    exit 99;
  else
    ${VAGRANT_CMD} up ${VM_NAME} --provider="virtualbox"
  fi
}


STOP() {
  EXPORT;
  if [ "${VM_NAME}x" == "x" ]; then
    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
    exit 99;
  else
    ${VAGRANT_CMD} halt ${VM_NAME}
  fi
}
STOP_ALL() {
  ${VAGRANT_CMD} halt
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


#INIT() {
#  EXPORT;
#  if [ "${VM_NAME}x" == "x" ]; then
#    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
#    exit 99;
#  else
#    ${VAGRANT_CMD} init ${VM_NAME}
#  fi
#}


# List VMS
STATUS() {
  ${VAGRANT_CMD} status
}
GLOBAL_STATUS() {
  ${VAGRANT_CMD} global-status
}


SSH() {
  EXPORT;
  if [ "${VM_NAME}x" == "x" ]; then
    echo "#% ERROR - VM [${VM_NAME}] not found. See available machine with 'status' option"
    exit 99;
  else
    ${VAGRANT_CMD} ssh ${VM_NAME}
  fi
}

###############
# Main function
main() {
  case $VM_CMD in
    "start"|"up") START $VM_NAME;;
    "start-all") START_ALL;;
    "stop"|"halt") STOP $VM_NAME;;
    "stop-all"|"halt-all") STOP_ALL;;
    "suspend") SUSPEND $VM_NAME;;
    "suspend-all") SUSṔEND_ALL;;
#    "init") INIT $VM_NAME;;
    "export") EXPORT;;
    "global-status") GLOBAL_STATUS;;
    "status"|"list") STATUS;;
    "ssh"|"conect") SSH $VM_NAME;;
    *) usage ;;
  esac
}
main $@;
