#include <stdio.h>
main (){
     int a11,a12,a21,a22,D;
     printf (" \n** CALCULO de DETERMINANTE de MATRIZ 2x2 ** \n");
     printf ("\nInforme o elemento a11: ");
     scanf ("%i",&a11);
     printf ("Informe o elemento a12: ");
     scanf ("%i",&a12);
     printf ("Informe o elemento a21: ");
     scanf ("%i",&a21);
     printf ("Informe o elemento a22: ");
     scanf ("%i",&a22);
     D = a11*a22-a12*a21;
     printf ("\nO determinate e: %i.\n",D);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
