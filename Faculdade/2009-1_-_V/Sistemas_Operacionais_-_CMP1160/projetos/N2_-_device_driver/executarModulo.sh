#!/bin/bash
make
cp devicedriver.ko elevador.ko
insmod elevador.ko
mknod /dev/elevador c 146 0
gcc -g -w Elevador.c elevador
./elevador
echo "Fechando programa.."
echo
echo "Removendo dispositivo /dev/elevador"
rm -rf /dev/elevador
echo "Removendo modulo do elevador"
rmmod -f elevador
