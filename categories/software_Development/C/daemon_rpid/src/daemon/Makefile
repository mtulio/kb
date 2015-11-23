# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: MTulio LIBS (../lib)

CFLAGS := -I.
CFLAGS += -I../include
CFLAGS += -I../lib
CFLAGS += -lpthread

OBJECTS += ../lib/mtd_lib_file.o
OBJECTS += ../lib/mtd_lib_daemon.o

SRC=$(wildcard *.c)
PROG_NAME_FILE=../.prog_name.txt
#PROG_NAME=`cat $(PROG_NAME_FILE)`
PROG_NAME=rpid

########### Building Program (NEW)
#all:
#	echo "$(PROG_NAME)"

#$(PROG_NAME): $(SRC)
$(PROG_NAME): $(SRC)
#rpid: $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) ${OBJECTS}

clean: 
	rm -f *.o
	#make clean ../include
	#make clean ../lib
	
