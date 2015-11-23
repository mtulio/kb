# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: None

CFLAGS := -I.
CFLAGS += -I../include
CFLAGS += -lm

OBJECTS := mtd_lib_daemon.o
OBJECTS += mtd_lib_file.o

#all: build_lib_strings build_lib_file build_lib_daemon
all: build_lib_file build_lib_daemon
#all: build_lib_strings 

########### Building Libs
#build_lib_strings: mtd_lib_strings.c
#	gcc ${CFLAGS} -c mtd_lib_strings.c -o mtd_lib_strings.o

build_lib_file: mtd_lib_file.c
	gcc ${CFLAGS} -c mtd_lib_file.c -o mtd_lib_file.o

build_lib_daemon: mtd_lib_daemon.c
	gcc ${CFLAGS} -c mtd_lib_daemon.c -o mtd_lib_daemon.o

############ App test
# App to test libs
build_app_testLib:
	gcc ${CFLAGS} -w mtd_lib_test.c -o mtd_lib_test ${OBJECTS}

clean: 
	rm -f *.o
	rm -f mtdLib_strings mtdLib_test
