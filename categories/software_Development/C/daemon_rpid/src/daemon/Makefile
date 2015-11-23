# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: MTulio LIBS (../lib)

CFLAGS := -I.
CFLAGS += -I../include
CFLAGS += -I../lib
CFLAGS += -lpthread

OBJECTS := ../lib/mtd_lib_file.o
OBJECTS += ../lib/mtd_lib_daemon.o
OBJECTS += ../lib/mtd_lib_strings.o

SRC=$(wildcard *.c)
PROG_NAME_FILE := ../.prog_name.txt
PROG_NAME := $(shell cat ${PROG_NAME_FILE})
#ifreq ($(PROG_NAME), )
#PROG_NAME=rpid

########### Building Program (NEW)
all: clean build
#	echo "$(PROG_NAME)"

#$(PROG_NAME): $(SRC)
#rpid: $(SRC)
build: $(SRC)
	gcc -o $(PROG_NAME) $^ $(CFLAGS) $(LIBS) ${OBJECTS}

clean: 
	rm -f *.o 
	#rm -f rpid
	#make clean ../include
	#make clean ../lib
	
