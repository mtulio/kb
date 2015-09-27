# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: None

CFLAGS += -I.
CFLAGS += -lpthread

OBJECTS := mtuliod_server.o
OBJECTS += mtd_server_cmd.o
OBJECTS += mtd_server_cmd_run.o

all: mtd_server_cmd_run mtd_server_cmd mtuliod_server mtuliod
#all: build_lib_strings 

########### Building Objects
mtd_server_cmd_run: mtd_server_cmd_run.c
	gcc -w ${CFLAGS} -c mtd_server_cmd_run.c -o mtd_server_cmd_run.o

mtd_server_cmd: mtd_server_cmd.c
	gcc -w ${CFLAGS} -c mtd_server_cmd.c -o mtd_server_cmd.o
	
mtuliod_server: mtuliod_server.c
	gcc -w ${CFLAGS}  -c mtuliod_server.c -o mtuliod_server.o




# Main Daemon
mtuliod:
	#gcc ${CFLAGS} -w mtdLib_test.c -o mtdLib_test ${OBJECTS}
	gcc ${CFLAGS} -w -o mtuliod ${OBJECTS}

clean: 
	rm -f *.o
	rm -f mtuliod
