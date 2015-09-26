# MTulio EngICT
# Description: MTulio Deamon
# Dependencies: None

CFLAGS += -I.
CFLAGS += -lm

OBJECTS := mtdLib_strings.o

all: build_lib_strings build_app_testLib
#all: build_lib_strings 

########### Building Libs
build_lib_strings: mtdLib_strings.c
	gcc ${CFLAGS} -c mtdLib_strings.c -o mtdLib_strings.o


# App to test libs
build_app_testLib:
	gcc ${CFLAGS} mtdLib_test.c -o mtdLib_test ${OBJECTS}

clean: 
	rm -f *.o
	rm -f mtdLib_strings mtdLib_test
