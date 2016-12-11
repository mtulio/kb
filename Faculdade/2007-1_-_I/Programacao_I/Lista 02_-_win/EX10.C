/*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 10 - Lista 02\n\n");
     float a, b, c;
     printf ("Digite o Lado A: ");
     scanf ("%f", &a);
     printf ("Digite o Lado B: ");
     scanf ("%f", &b);
     printf ("Digite o Lado C: ");
     scanf ("%f", &c);
     if ( a<b+c || b<a+c || c<a+b ) {
          printf ("\nOs lados informados formam um Triangulo!!\n\n");
     }
     else printf ("\nOs lados informado não formam um Triangulo!!!\n\n");
     getchar();
     getchar();
}
