# MTulio EngICT
# Description: MTulio API - Daemon and Driver
# Dependencies: None

CC:= $(CROSS_COMPILE)gcc
STRIP:= $(CROSS_COMPILE)strip
LIBS   += -lpthread

CONFIG_FILE = "include/mtulio.h"

.PHONY: clean all

# Building

all: unconf config build_app build_daemon build_drv build_drv_k2u message

## Config
config:
	@echo "#ifndef MTULIO_CONFIG_H_" > $(CONFIG_FILE); \
	echo "#define MTULIO_API_CONFIG_H_" >> $(CONFIG_FILE); \
	echo ' ' >> $(CONFIG_FILE); \
	if [ ${DEBUG_ENABLE} -eq 1 ]; then \
		echo '#define DEBUG_ENABLED	1' >> $(CONFIG_FILE); \
	else \
		echo '#undef DEBUG_ENABLED' >> $(CONFIG_FILE); \
	fi; \
	echo ' ' >> $(CONFIG_FILE); \
	echo "#endif /* MTULIO_CONFIG_H_ */" >> $(CONFIG_FILE);

## Build App
app: config build_app

build_app:
	cd app/; make 
	mv app/mtulio_app .

## Build Daemon
daemon: config build_daemon

build_daemon:
	cd daemon/; make 
	mv daemon/mtuliod .

## Build Driver
## Build Driver k2u - Kernel to User

drv: config build_drv build_drv_k2u

build_drv: 
	# Building driver

build_drv_k2u:
	# Building driver - kernel2user

# Message
message:
	############################################
	#	MTulio's Driver, Daemon & App
	############################################
	# MTulio's driver, daemon and app wasr built 
	# with success.
	# Driver and Command Requeriments:
	# device: /dev/mtulio-dev
	# Major Number: 2XX
	# Run: 
	#	$ mknode /dev/mtulio-dev 22
	#	$ insmod mtulio_drv.ko
	#	$ mtuliod -d
	#	$ mtulio_app --version

# Clean config
clean: unconf
	cd driver/; make clean; cd -
	cd driver_k2u/; make clean; cd -
	rm -rf .tmp_versions/ *.ko *.cmd *.o Module.symvers
	cd app/; make clean; cd -
	cd daemon/; make clean; cd -
	rm -rf mtuliod mtulio_app mtulio_drv.ko mtulio_drv_k2u.ko 

unconf:
	@rm -rf $(CONFIG_FILE);

