#!/bin/bash
#
# generate_ramdom_password.sh - Generate ramdom passwords
#
# author: Marco Tulio R Braga (https://github.com/mtulio)
# created: Aug 18, 2015
# modified: Aug 18, 2015
#
#######################################

#######################################
# Globals & Parameter validation

LENGHT_DEFAULT="8"


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
  echo " Usage          : $0 [simple|medium|complex|default|all] [lenght] ]"
  echo " '-> simple	: Generate simple password"
  echo " '-> medium	: Generate a medium password"
  echo " '-> complex	: Generate a complex password"
  echo " '-> medium	: Generate a default (medium) password"
  echo " '-> all	: Generate all level of password"
  echo " '-> lenght	: Lenght of password. Minimal is 6. Default is ${LENGHT_DEFAULT}"

  exit 2;
} 2>/dev/null

if [ $# -gt 1 ]; then
  if [ $2 -lt 6 ]; then
    echo " #% ERROR - Password must be equal or greater than 6";
    usage;
  fi
fi

#######################################
# Create ramdom passwords
# Globals:
#    Lenght
# Arguments:
#    None
# Returns:
#    None
#######################################
gen_passwd_simple() {
  PASSWORD="$(cat /dev/urandom| tr -dc 'a-zA-Z0-9' | fold -w ${1} | head -n 1)"
  echo " # Level: [SIMPLE] , Lenght: [${1}] , Password: ${PASSWORD}"
}


gen_passwd_medium() {
  PASSWORD="$(</dev/urandom tr -dc '12345!@#$%qwertQWERTasdfgASDFGzxcvbZXCVB' | head -c${1} ; echo )"
  echo " # Level: [MEDIUM] , Lenght: [${1}] , Password: ${PASSWORD}"
}


gen_passwd_complex() {

  PASSWORD="$(cat /dev/urandom | tr -dc 'a-zA-Z0-9-_!@#$%^&*()_+{}|:<>?=' |fold -w ${1} | head -n 1)"
  echo " # Level: [COMPLEX] , Lenght: [${1}] , Password: ${PASSWORD}"
  
}


gen_passwd_default() {

  gen_passwd_medium $1;

}


gen_passwd_all() {

  gen_passwd_simple $1;
  gen_passwd_medium ${1};
  gen_passwd_complex ${1};

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

  GET_OPTS=$(getopt -o hsmcad: --long help,simple,medium,complex,all,default -n "$0" -- "$@")
  if [ $? != 0 ] ; then usage; exit 2 ; fi
  eval set -- "${GET_OPTS}"

  while true
  do
    case "$1" in
      -h|--help) usage; shift;;
      -s|--simple)  LENGHT="${3:-${LENGHT_DEFAULT}}"; gen_passwd_simple ${LENGHT} ; shift 2;;
      -m|--medium)  LENGHT="${3:-${LENGHT_DEFAULT}}"; gen_passwd_medium ${LENGHT} ; shift 2;;
      -c|--complex) LENGHT="${3:-${LENGHT_DEFAULT}}"; gen_passwd_complex ${LENGHT} ; shift 2;;
      -d|--default) LENGHT="${3:-${LENGHT_DEFAULT}}"; gen_passwd_default ${LENGHT} ; shift 2;;
      -a|--all) LENGHT="${3:-${LENGHT_DEFAULT}}"; gen_passwd_all ${LENGHT}; shift 2;;
      -- ) shift 2; break;;
      * ) break;;
    esac
  done

}
main $@

exit 0
