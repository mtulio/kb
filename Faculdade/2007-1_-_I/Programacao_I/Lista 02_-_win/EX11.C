                /*Marco Tulio*/
//Obs: não imprimi o Triangulo Escaleno


#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 11 - Lista 02\n\n");
     float a, b, c;
     printf ("Digite o Lado A: ");
     scanf ("%f", &a);
     printf ("Digite o Lado B: ");
     scanf ("%f", &b);
     printf ("Digite o Lado C: ");
     scanf ("%f", &c);
     if ( (a<b+c) || (b<a+c) || (c<a+b) ) {
          if ( a==b && a==c && b==c ){
               printf ("\nOs lados %.2f, %.2f e %.2f formam um Triangulo Equilatero!\n\n",a,b,c);
          }
          if ( a==b && a!=c || a==c && a!=b){
                   printf(" Forma um triangulo isoceles.\n");
          }

          if ( (a!=b) && (a!=c) && (b!=c) ) {
               printf ("\nOs lados %.2f, %.2f e %.2f formam um Triangulo Escaleno!\n\n",a,b,c);
          }
     }
     if ((a>b+c) || (b>a+c) || (c>a+b)) { 
          printf ("\nOs valores informados não formam um Triangulo!\n");
     }
     
      fflush(stdin); //limpa buffet do teclado - Windows
      //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}
