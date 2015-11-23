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

INC_FILE=include/config.h
PROG_NAME=`cat $(INC_FILE) |awk '{print$2" "$3}' |egrep ^PROG_NAME |awk '{print$2}'`

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
	rm -f $(PROG_NAME)
	cd lib/; make clean
	cd daemon/; make clean
