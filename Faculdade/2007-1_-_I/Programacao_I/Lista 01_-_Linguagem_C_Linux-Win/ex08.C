#include <stdio.h>
#include <cmath>
main () {
     float ax,ay,bx,by,D;
     printf ("\n** CALCULO DE UMA DISTANCIA ENTRE DOIS PONTOS ** \n");
     printf ("\nQual o x do ponto A? ");
     scanf ("%f",&ax);
     printf ("Qual o y do ponto A? ");
     scanf ("%f",&ay);
     printf ("Qual o x do ponto B? ");
     scanf ("%f",&bx);
     printf ("Qual o y do ponto B? ");
     scanf ("%f",&by);
     D = sqrt( (bx-ax)*(bx-ax)+(by-ay)*(by-ay) );
     printf ("\nA distancia entre os pontos A e B e: %f.\n",D);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
