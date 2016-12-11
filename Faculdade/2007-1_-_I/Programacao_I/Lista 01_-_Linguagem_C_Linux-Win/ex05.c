#include <stdio.h>
main () {
     int A,B,C,D;
     printf ("\n** CALCULAR UMA EQUACAO QUADRATICA ** \n");
     printf ("\nQual o valor de A? ");
     scanf ("%i",&A);
     printf ("Qual o valor de B? ");
     scanf ("%i",&B);
     printf ("Qual o valor de C? ");
     scanf ("%i",&C);
     D = B * B - 4 * A * C;
     printf ("\nO valor de Delta e: %i.\n",D);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
