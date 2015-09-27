# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: None

CFLAGS += -I.
CFLAGS += -lpthread

OBJECTS := mtuliod_server.o

all: mtuliod_server mtuliod
#all: build_lib_strings 

########### Building Objects
mtuliod_server: mtuliod_server.c
	gcc ${CFLAGS} -c mtuliod_server.c -o mtuliod_server.o


# Main Daemon
mtuliod:
	#gcc ${CFLAGS} -w mtdLib_test.c -o mtdLib_test ${OBJECTS}
	gcc ${CFLAGS} -w -o mtuliod ${OBJECTS}

clean: 
	rm -f *.o
	rm -f mtuliod
