#/bin/bash

echo "Removendo executaveis existentes"
rm -rvf executavel
rm -rvf compilador
#rm -rvf fonte6.por.c
rm -rvf exemplo01-1.por.c


echo "Compilando o compilador..."
g++ principal.cpp -o compilador

echo "Executando o compilador para arquivo .por..."
./compilador

echo "Compilando o fonte .c ..."
gcc exemplo01-1.por.c -o executavel -w

echo "Executando o cod fonte gerado..."
./executavel
