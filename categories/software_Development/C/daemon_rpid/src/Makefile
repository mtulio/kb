# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: None

# etc/
#  '- default/
#  '- mtd/
#  '- init.d/
# src/
#  '- daemon/
#  '- include/
#  '- lib/
#  '- scripts/
# configure
# Makefile
# 

## Main Makefile

INC_FILE := include/config.h
PROG_NAME_FILE := .prog_name.txt
#PROG_NAME := $(shell cat ${PROG_NAME_FILE})

ifneq ("$(wildcard $(INC_FILE))","")
PROG_NAME := $(shell cat ${PROG_NAME_FILE})
else
#TODO: Run configure.sh
PROG_NAME := rpid
endif


# Build all
all: clean build

# Build chain
build: build_lib build_daemon

build_lib:
	cd lib/; make

build_daemon: build_lib
	cd daemon/; make
	cp daemon/$(PROG_NAME) .

# Clean chain
clean:
	#test -f $(PROG_NAME) && rm -f $(PROG_NAME)
	#test -f $(INC_FILE) && rm -f $(INC_FILE)
	#test -f .prog_name.txt && rm -f .prog_name.txt 
	cd lib/; make clean
	cd daemon/; make clean
