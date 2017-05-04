                /*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 05 - Lista 02\n\n");
     int n, dg1, dg2, dg3, dg4, soma;
     printf ("\nDigite um numero com 4 digitos distintos: ");
     scanf ("%i", &n);
     dg1 = n/1000;
     dg2 = (n%1000)/100;
     dg3 = ((n%1000)%100)/10;
     dg4 = ((n%1000)%100)%10;
     if ( dg1>dg2 && dg1>dg3 && dg1>dg4 ) {
          soma = dg2 + dg3 + dg4;
     }
     else if( dg2>dg3 && dg2>dg4 ) {
          soma = dg1 + dg3 + dg4;
          }
          else if ( dg3>dg4 ) {
               soma = dg1 + dg2 + dg4;
               }
               else soma = dg1 + dg2 + dg3;
      printf ("\nA soma dos 3 numéros é %.0i.",soma);
 

      fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}         
