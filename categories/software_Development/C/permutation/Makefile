# Makefile of Permutation problem
# Created by Marco Tulio

OBJECTS := list_linked.o
OBJECTS += permutation.o

CONFIG_FILE = "config.h"

## What to build
# Build all program
all: clean build_div8 

# Build only permutation divisible by 8 program
perm_div8: build_div8
pdiv8: build_div8
main_permDiv8: build_div8
build_div8: clean config_perm_div8 build_list build_permutation main_perm_div8

# Build only Program to check k-th permutation from N
perm_k: build_k
permk: build_k
build_k: clean config_perm_k build_list build_permutation main_perm_k

## Config
config: config_perm_div8

config_perm_div8:
	@echo "#ifndef _CONFIG_H_" > $(CONFIG_FILE); \
	echo "#define _CONFIG_H_" >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#define _PERM_EN_BREAK    1	/* break point enabled */ " >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#define _PERM_DIV8    1" >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#endif /* _CONFIG_H_ */" >> $(CONFIG_FILE);
	
config_perm_k:
	@echo "#ifndef _CONFIG_H_" > $(CONFIG_FILE); \
	echo "#define _CONFIG_H_" >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#define _PERM_EN_BREAK    1	/* break point enabled */ " >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#define _PERM_K    1" >> $(CONFIG_FILE); \
	echo " " >> $(CONFIG_FILE); \
	echo "#endif /* _CONFIG_H_ */" >> $(CONFIG_FILE);

## Building libs/objects
build_list: list_linked.c
	gcc -w -c list_linked.c -o list_linked.o

build_permutation: permutation.c
	gcc -w -c permutation.c -o permutation.o


## Building progrms

main_perm_div8:
	gcc ${CFLAGS} main_perm_divby8.c -w -o permutation_divby8 ${OBJECTS}

main_perm_k: main_perm_k.c
	gcc ${CFLAGS} main_perm_k.c -w -o permutation_k ${OBJECTS}


## Clean all
clean:
	rm -rf *.o permutation_divby8 permutation_k
	rm -rf config.h
