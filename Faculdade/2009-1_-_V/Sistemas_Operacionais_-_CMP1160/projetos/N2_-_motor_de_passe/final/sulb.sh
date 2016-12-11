#!/bin/sh

MODULE_NAME="sulb"
SULB_MAJOR=0
SULB_MINOR=0
SULB_MODE=666
SULB_OWNER=root
SULB_GROUP=root

if [ $# -eq 1 ]; then

	if [ $1 == "load" ]; then
		echo "Loading module $MODULE_NAME.ko..."
		/sbin/insmod $MODULE_NAME.ko
		
		SULB_MAJOR=$(awk '$2 == "sulb" { print $1 }' /proc/devices)

		echo "Deleting old device..."
		/bin/rm -f /dev/sulb
		
		echo "Creating new device (major: $SULB_MAJOR, minor: $SULB_MINOR, mode: $SULB_MODE)..."
		/bin/mknod --mode=$SULB_MODE /dev/$MODULE_NAME c $SULB_MAJOR $SULB_MINOR
		
		/bin/chown $SULB_OWNER:$SULB_GROUP /dev/sulb

	elif [ $1 == "unload" ]; then
		echo "Unloading module $MODULE_NAME..."
		/sbin/rmmod $MODULE_NAME

		echo "Deleting old device..."
		/bin/rm -f /dev/sulb
	
	elif [ $1 == "mkdev" ]; then
		SULB_MAJOR=$(awk '$2 == "sulb" { print $1 }' /proc/devices)

		echo "Deleting old device..."
		/bin/rm -f /dev/sulb
		
		echo "Creating new device (major: $SULB_MAJOR, minor: $SULB_MINOR, mode: $SULB_MODE)..."
		/bin/mknod --mode=$SULB_MODE /dev/$MODULE_NAME c $SULB_MAJOR $SULB_MINOR
		
		/bin/chown $SULB_OWNER:$SULB_GROUP /dev/sulb
					
	elif [ $1 == "clean" ]; then
		echo "Loading module $MODULE_NAME.ko..."
	
		echo "Deleting old device..."
		/bin/rm -f /dev/sulb
	fi
	
else
	echo "$0 <load|unload|mkdev|clean>"
fi

