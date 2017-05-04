/* Universidade Catolica de Goias
 * Departamento de Computacao
 * Introducao a Ciencias da Computacao II
 * Programacao Estruturada de Computadores
 * Laboratorio 6 (a) - Exemplo de Recursividade
 */

#include <stdio.h>

int fatorial ( int n ) {
  if (n==1) {
    return(1);
  }
  else {
    return(n*fatorial(n-1));
  }
}

int main ( void ) {
  int x;
  while(x!=0) {
     printf("Entre com um numero inteiro:");
     scanf("%i",&x);
     if (x!=0)
        printf("O valor de %i!=%i\n",x,fatorial(x));
     getchar();
  }
}
