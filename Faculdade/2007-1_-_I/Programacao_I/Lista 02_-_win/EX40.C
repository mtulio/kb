                     /*Marco Tulio*/

#include <stdio.h>
main () {
     int n1, n2, n3;
     printf ("\n\t\t\tExercicio 40 - Lista 02\n\n");
     printf ("Digite o primeiro numero inteiro: ");
     scanf ("%i", &n1);
     printf ("Digite o segundo numero inteiro: ");
     scanf ("%i", &n2);
     printf ("Digite o terceiro numero inteiro: ");
     scanf ("%i", &n3);
     if (n1>n2 && n1>n3) {
               if (n2>n3) { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n3, n2, n1); }
               else { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n2, n3, n1); }
     }
     else{ if (n2>n3){
             if (n1>n3) { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n3, n1, n2); }
             else { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n1, n3, n2); }
          }
          else if (n1>n2) { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n2, n1, n3); }
               else { printf ("\nOs numeros informados em ordem crescente é: %i, %i, %i.",n1, n2, n3); }
     }
     
     
     getchar();
     getchar();

}
