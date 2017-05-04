/*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 12 - Lista 02\n\n");
     float a,b,c;
     printf ("Digite o Lado A de um Triangulo: ");
     scanf ("%f", &a);
     printf ("Digite o Lado B de um Triangulo: ");
     scanf ("%f", &b);
     printf ("Digite o Lado C de um Triangulo: ");
     scanf ("%f", &c);
     if ( a<b+c || b<a+c || c<a+b ) {
        if ( a*a == b*b + c*c ) {
            printf ("\nOs lados A,B,C informados formam um Trinagulo RETANGULO!!!\n\n");
        }
        if ( a*a > b*b + c*c ) {
           printf ("\nOs lados A,B,C informados formam um Trinagulo OBTUSÂNGULO!!!\n\n");
        }
        if ( a*a < b*b + c*c ) {
           printf ("\nOs lados A,B,C informados formam um Trinagulo ACUTANGULO!!!\n\n");
        }
     }
     getchar();
     getchar();
}
