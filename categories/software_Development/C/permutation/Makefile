# Makefile of Permutation problem
# Created by Marco Tulio

OBJECTS := list_linked.o
OBJECTS += permutation.o

all: build_list build_permutation main_permDiv8

build_list: list_linked.c
	gcc -w -c list_linked.c -o list_linked.o

build_permutation: permutation.c
	gcc -w -c permutation.c -o permutation.o

main_permDiv8:
	gcc ${CFLAGS} main_permutation_div8.c -w -o perm_div8 ${OBJECTS}

clean:
	rm -rf *.o perm_div8
