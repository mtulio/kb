#include <stdio.h>
main (){
     int A,B,C,D,R,S;
     printf ("\nQual o primeiro numero inteiro? ");
     scanf ("%i",&A);
     printf ("Qual o segundo numero inteiro? ");
     scanf ("%i",&B);
     printf ("Qual o terceiro numero inteiro? ");
     scanf ("%i",C);
     R = A * A + 2 * A * B + B * B;
     S = B * B + 2 * B * C + C * C;
     D = (R + S) / 2;
     printf ("\nO valor D e: %i.\n",D);
     printf ("\n\n<< Marco Tulio >>\n");
     getchar(),getchar();
}
