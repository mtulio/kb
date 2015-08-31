#!/bin/bash

#
# test_cmd_cli.sh - Automatize tests in an telnet client using Expect scripts
#	This example test an connection to Quagga CLI and test following functions:
#		# Create N Virtual interface(s) - SVI and assigned IP address to it
#		# Add and removi IP address (check software integrity)
# Of course that it's notes that can me and I would like to help you.
# This script was done to test an system running Quagga with support to virtual interfaces.
# I known that this script need to be improve, you could collaborate to do it! :) 
#
# Created by: Marco Tulio R Braga [http://github.com/mtulio]
# Created at : Feb, 2014
# Last update: Aug, 2015
#

echo
echo "#######################################"
echo "# Expect automation - Sample test in Quagga CLI"
echo "#######################################"
echo

#########################
# Error check		#
#########################

func_error_args(){
	echo -e "\t** Incorrect args. **"
	echo " Try: $0 (svi|changeip) IP_TELNET_CLIENT [N_Loops] [SVI]"
	echo -e "\t > svi......: Run test SVI - create and remove an SVI."
	echo -e "\t > changeip.: Run test ChangeIp - Add and change ip address "
	echo "			of SVI. Start at IP 10 and increasing up of "
	echo "			class B(subnet 24 of network 192.168.SVI.X)."
	echo -e "\t > noip.....: Run test NoIp - Add and remove ip address "
	echo "			of SVI. Start at IP 10 and increasing up of "
	echo "			class B(subnet 24 of network 192.168.SVI.X)."
	echo -e "\t > IP_TELNET: Telnet IP address of target host."
	echo -e "\t > N_loops..: Repeat N times."
	echo -e "\t > VLANID...: VLANID to configure SVI and network in subnet 24."
	echo
}

# Check args
if [ $# -lt 2 ]; then
	func_error_args;
	exit;
fi

# Expect is installed?
EXPECT_BIN="`which expect`"
if [ -z ${EXPECT_BIN} ]; then 
	echo "Expect not found... please install and try again."
	exit
fi

# Host is reachable?
ping -c1 $2 &>/dev/null
if [ $? -ne 0 ]; then
	echo -e "\t ** Error... Host $2 is unreachable by icmp request... **"
	echo ""
	exit
fi

#########################
# Global		#
#########################

# Global
# $0 (svi) IP_TELNET_CLIENT N_loops
NARGS=$#		# Number of arguments in binary
TEST_ID=$1		# Pre-configured test ID
TELNET_CLI=$2		# IP of telnet target
ARG3=$3			# optional
ARG4=$4			# optional
FILE_PREFIX="expectScript"

# Tests available - creating expect file
case $TEST_ID in
	"svi")
		FILE_PREFIX="${FILE_PREFIX}_svi"
		;;
	"changeip")
		FILE_PREFIX="${FILE_PREFIX}_changeIp"
		;;
	"noip")
		FILE_PREFIX="${FILE_PREFIX}_noIp"
		;;
	*)
		func_error_args;
		exit;
	;;
esac

FILE_LOG="${FILE_PREFIX}.log"
FILE_EXPECT="${FILE_PREFIX}.expect"

#########################
# EXPECT COMMANDS 	#
#########################
## Commands to login at $TELNET_CLI arg

CMD_CONN="#!/usr/bin/expect -f
spawn telnet -l root $TELNET_CLI
send \"root\\r\"
expect \"login:\"
send \"root\\r\"
expect \"Password:\""

#########################
# TEST FUNCIONS 	#
#########################
# Create SVI Test
func_test_svi_add_rem() {


	if [ $NARGS -le 3 ]; then
		func_error_args;
		echo " ** Error test - svi: Number of loops/tests not found. **"
		exit
	else
		NUMBER_OF_TESTS=$ARG3
		if [ $NARGS -ne 4 ]; then
			func_error_args;
			echo " ** Error test - svi: VLAN ID not found. **"
			exit
		else
			VLANID=$ARG4
		fi
	fi

	# Check max VLANID is greater than 8 bits -1 - this number is used to create an subnet
	if [ $VLANID -ge 4099 ];then
		func_error_args;
		echo " ** Error test - svi: Invalid VLANID ${VLANID}. **"
		exit
	elif [ $VLANID -ge 255 ];then 
		if [ $VLANID -ge 2550 ];then 
			IP_SUBNET="192.168.$(expr ${VLANID} / 100 )"
		else
			IP_SUBNET="192.168.$(expr ${VLANID} / 10 )"
		fi
	else
		IP_SUBNET="192.168.${VLANID}"
		# IP address 192.168.VLANID.10
		IP_ADDR="${IP_SUBNET}.10/24"
	fi

	echo "Creating expect config file..."
	echo " > Number of tests: $NUMBER_OF_TESTS"	
	echo " > VLAN ID: $VLANID"
	echo " > Subnet : $IP_SUBNET"
	echo " > IP Address: $IP_ADDR"


	# SVI Tests expect commands
	CMD_SVI_CFG="send \"interface gpon0.${VLANID}\\r\"
send \"ip address ${IP_ADDR}\\r\"
send \"shutdown\\r\"
send \"exit\\r\"
send \"no interface gpon0.${VLANID}\\r\"
send \"show running-config\r\"
expect \"QUAGGA(config)#\""

	echo "Running SVI test... please wait when the program is running."
	echo "The result will be show automatically."

	#######################
	# Creating expect command file
	echo "$CMD_CONN
send \"enable\r\"
send \"configure terminal\\r\"
send \"show running-config\r\"" > $FILE_EXPECT

	i=0
	while [ $i -lt $NUMBER_OF_TESTS ]; do
		echo "$CMD_SVI_CFG" >> $FILE_EXPECT

		# Waiting one second to next test
		echo "sleep 1\\r" >> $FILE_EXPECT
		(( i++ ))
	done

	echo "expect eof" >> $FILE_EXPECT
}

#########################
# Add and change IP address N times
func_test_change_ip() {

	if [ $NARGS -le 3 ]; then
		func_error_args;
		echo " ** Error test - changeip: Number of loops/tests not found. **"
		exit
	else
		NUMBER_OF_TESTS=$ARG3
		if [ $NARGS -ne 4 ]; then
			func_error_args;
			echo " ** Error test - changeip: VLAN ID not found. **"
			exit
		else
			VLANID=$ARG4
		fi
	fi

	# Check max VLANID is greater than 8 bits -1 - this number is used to create an subnet
	if [ $VLANID -ge 4099 ];then
		func_error_args;
		echo " ** Error test - changeip: Invalid VLANID ${VLANID}. **"
		exit
	elif [ $VLANID -ge 255 ];then 
		if [ $VLANID -ge 2550 ];then 
			IP_SUBNET="192.168.$(expr ${VLANID} / 100 )"
		else
			IP_SUBNET="192.168.$(expr ${VLANID} / 10 )"
		fi
	else
		IP_SUBNET="192.168.${VLANID}"
	fi

	echo "Creating expect config file..."
	echo " > Number of tests: $NUMBER_OF_TESTS"	
	echo " > VLAN ID: $VLANID"
	echo " > Subnet : $IP_SUBNET"

	#######################
	# Creating expect command file
	echo "$CMD_CONN
send \"enable\r\"
send \"show running-config\r\"" > $FILE_EXPECT

	i=0
	while [ $i -lt $NUMBER_OF_TESTS ]; do
		# Start at IP address 192.168.VLANID.10+i
		IP_ADDR="${IP_SUBNET}.$(expr 10 + ${i} )/24"
	

		echo " > IP Address: $IP_ADDR"

		echo "send \"configure terminal\\r\"
send \"interface gpon0.$VLANID\\r\"
send \"ip address ${IP_ADDR}\\r\"
send \"end\\r\"
send \"show running-config\r\"
send \"start\r\"
send \"ip addr show gpon0.$VLANID\r\"
send \"exit\r\"
send \"ping ${IP_SUBNET}.1\r\"
sleep 4\\r
send \\003
expect \"QUAGGA#\"" >> $FILE_EXPECT

		# Waiting one second to next test
		echo "sleep 1\\r" >> $FILE_EXPECT
		(( i++ ))
	done

	echo "expect eof" >> $FILE_EXPECT

}

#########################
# Add, removing and checking IP address from interface SVI
func_test_no_ip() {

	if [ $NARGS -le 3 ]; then
		func_error_args;
		echo " ** Error test - noip: Number of loops/tests not found. **"
		exit
	else
		NUMBER_OF_TESTS=$ARG3
		if [ $NARGS -ne 4 ]; then
			func_error_args;
			echo " ** Error test - noip: VLAN ID not found. **"
			exit
		else
			VLANID=$ARG4
		fi
	fi

	# Check max VLANID is greater than 8 bits -1 - this number is used to create an subnet
	if [ $VLANID -ge 4099 ];then
		func_error_args;
		echo " ** Error test - noip: Invalid VLANID ${VLANID}. **"
		exit
	elif [ $VLANID -ge 255 ];then 
		if [ $VLANID -ge 2550 ];then 
			IP_SUBNET="192.168.$(expr ${VLANID} / 100 )"
		else
			IP_SUBNET="192.168.$(expr ${VLANID} / 10 )"
		fi
	else
		IP_SUBNET="192.168.${VLANID}"
	fi

	echo "Creating expect config file..."
	echo " > Number of tests: $NUMBER_OF_TESTS"	
	echo " > VLAN ID: $VLANID"
	echo " > Subnet : $IP_SUBNET"

	#######################
	# Creating expect command file
	echo "$CMD_CONN
send \"enable\r\"
send \"show running-config\r\"" > $FILE_EXPECT

	i=0
	while [ $i -lt $NUMBER_OF_TESTS ]; do
		# Start at IP address 192.168.VLANID.10+i
		IP_ADDR="${IP_SUBNET}.$(expr 10 + ${i} )/24"
	

		echo " > IP Address: $IP_ADDR"

		# Develop mode
		echo "send \"configure terminal\\r\"
send \"interface gpon0.$VLANID\\r\"
send \"ip address ${IP_ADDR}\\r\"
send \"end\\r\"
send \"show running-config\r\"
send \"start\r\"
send \"ip addr show gpon0.$VLANID\r\"
send \"exit\r\"
sleep 1\\r
send \"configure terminal\\r\"
send \"interface gpon0.$VLANID\\r\"
send \"no ip address ${IP_ADDR}\\r\"
send \"end\\r\"
send \"show running-config\r\"
send \"start\r\"
send \"ip addr show gpon0.$VLANID\r\"
send \"exit\r\"
expect \"QUAGGA#\"" >> $FILE_EXPECT
		
		# Waiting one second to next test		
		echo "sleep 1\\r" >> $FILE_EXPECT
		(( i++ ))
	done

	echo "expect eof" >> $FILE_EXPECT

}

#########################
# EXPECT FUNCTIONS 	#
#########################

# Run expect according 'expect command file: $FILE_EXPECT'
func_run_expect() {
	${EXPECT_BIN} -f $FILE_EXPECT &>$FILE_LOG
	cat $FILE_LOG
}

#########################
# CREATE AND RUN TESTS	#
#########################

# Create and run SVI Test
func_do_test_svi_add_rem() {
	func_test_svi_add_rem;
	func_run_expect;
}

# Create and run 'Change IP' Test
func_do_test_change_ip() {
	func_test_change_ip;

	echo "Running 'Change IP' test... please wait when the program is running."
	echo "The result will be show automatically."	
	func_run_expect;
}

# Create and run 'No IP' test
func_do_test_no_ip() {
	func_test_no_ip;

	echo "Running 'No IP' test... please wait when the program is running."
	echo "The result will be show automatically."	
	func_run_expect;
}

#########################
# MAIN	#
#########################
# MAIN
# Run test

case $TEST_ID in
	"svi") # interface gpon0.X; ip address A.B.C.D/M; shutdown; no inte gpon0.X
		func_do_test_svi_add_rem;
		;;
	"changeip") # interface gpon0.X; ip address A.B.C.D/M; show running; interface gpon0.X; ip address A.B.C.E/M; ...
		func_do_test_change_ip;
		;;
	"noip") # interface gpon0.X; ip address A.B.C.D/M; show ip; 
		func_do_test_no_ip;
		;;
	*)
		func_error_args;
		exit;
		;;
esac

echo 
echo "#######################################"
echo "The log file was created...........: ${FILE_LOG}"
echo "The expect config file was created.: ${FILE_EXPECT}"
echo 

