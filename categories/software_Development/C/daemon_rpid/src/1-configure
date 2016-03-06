#!/bin/bash

# Configure script

#######
## PRE_REQ

### HELP
function FC_USAGE() {
  echo "# Error typing arguments: $*"
  echo "Available args: "
  echo -e "\t $0 progName=NAME progVersion=VERSION"
}

if [ $# -ne 2 ];then
  FC_USAGE $@;
  exit 1;
fi

############
## FUNCTIONS

### Split value from delimiter '='
function FC_GET_ARG() {

  unset ARG_OPT;
  unset ARG_VAL;
  export ARG_OPT="$(echo $1 |awk -F'=' '{print$1}')"
  export ARG_VAL="$(echo $1 |awk -F'=' '{print$2}')"

}

##########
## GLOBALS

#% TODO: use getopts
FC_GET_ARG $1;
PROG_NAME="$ARG_VAL"

FC_GET_ARG $2;
PROG_VER="$ARG_VAL"

PROG_BUILD_DATE="$(date +%Y.%m.%d_%H:%M:%S)"

BODY_PROG_MAIN="
/* 
 * $PROG_NAME - $PROG_VER - $PROG_BUILD_DATE
 * Create automaticall by configure script.
 * 
*/

#include <daemon_main.h>

int main (int argc, char *argv[])
{
	return daemon_main(argc, argv);
}
"

BODY_PROG_INC="
/* 
 * $PROG_NAME - $PROG_VER - $PROG_BUILD_DATE
 * Create automaticall by configure script.
 * 
*/

#ifndef _CONFIG_H_
#define _CONFIG_H_

#define PROG_NAME	\"$PROG_NAME\"
#define PROG_VERSION	\"$PROG_VER\"
#define PROG_BUILD_DATE	\"$PROG_BUILD_DATE\"

#endif /* _CONFIG_H_ */
"


#######
## MAIN

FILE_PROG_MAIN="daemon/main_${PROG_NAME}.c"
FILE_PROG_INC="include/config.h"
FILE_PROG_NAME=".prog_name.txt"

echo -n "# Creating main function in $FILE_PROG_MAIN ... "
echo "$BODY_PROG_MAIN" > $FILE_PROG_MAIN 2>/dev/null
if [ -f $FILE_PROG_MAIN ];then echo "[ OK ]" 
else echo "[FAIL]"; fi

echo -n "# Creating config.h on directory $(dirname $FILE_PROG_MAIN)/ ... "
echo "$BODY_PROG_INC" > $FILE_PROG_INC 2>/dev/null
if [ -f $FILE_PROG_MAIN ];then echo "[ OK ]"
else echo "[FAIL]"; fi

echo -n "# Creating file with prog name $FILE_PROG_NAME ... "
echo "$PROG_NAME" > $FILE_PROG_NAME 2>/dev/null
if [ -f $FILE_PROG_NAME ];then echo "[ OK ]" 
else echo "[FAIL]"; fi


