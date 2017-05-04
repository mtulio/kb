 
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

void main () {
  char vet[10], aux;
  int i;

  vet[0] ='b';
  vet[1] ='r';
  vet[2] ='a';
  vet[3] ='s';
  vet[4] ='i';
  vet[5] ='l';
  vet[6] ='e';
  vet[7] ='i';
  vet[8] ='r';
  vet[9] ='o';
  cout << "vetor original\n";
  for ( i=0 ; i<= 9 ;  i++) {
    cout << vet[i];
  }
  for ( i=0 ; i<= 4 ;  i++) {
    aux = vet[i];
    vet[i] = vet[9-i];
    vet[9-i] = aux;
  }
  cout << "\n\nvetor invertido\n";
  for ( i=0 ; i<= 9 ;  i++) {
    cout << vet[i];
  }  
  getchar();
  getchar();
}

 
